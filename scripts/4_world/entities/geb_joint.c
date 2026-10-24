// Joints: a lit joint (geb_JointLit; rolled and lit by the recipes in geb_cutOutSeeds.c) smoked a puff at a time,
// and the high it brings: the world rolling slowly round the colours of the rainbow (PPERequester_GebHigh in
// scripts/3_game/high/geb_High.c). The server keeps each smoker's high (when it ends, how many puffs went into it) and
// sends it to their client, which counts it down and drives the screen effect. A high does not outlast a logout.

const float GEB_PUFF_SECONDS = 2.5;		// one draw on the joint
const float GEB_HIGH_PER_PUFF = 150;	// seconds of high each puff adds (a whole joint of six puffs: 15 minutes)
const float GEB_HIGH_MAX = 1500;		// the most it adds up to (25 minutes)
const float GEB_HIGH_FADE = 60;			// it fades out over its last minute
const float GEB_HIGH_COUGH = 0.25;		// the chance a puff makes you cough

class geb_Joint : Inventory_Base {};

class geb_JointLit : Inventory_Base
{
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionSmokeJoint);
	}
};

class ActionSmokeJointCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousRepeat(GEB_PUFF_SECONDS);
	}
};

// Hold the button to draw on the joint, puff after puff, with vanilla's eating animation; the last puff finishes it
class ActionSmokeJoint : ActionContinuousBase
{
	void ActionSmokeJoint()
	{
		m_CallbackClass = ActionSmokeJointCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_EAT;
		m_CommandUIDProne = DayZPlayerConstants.CMD_ACTIONFB_EAT;
		m_Text = "#STR_geb_Smoke";
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINotRuinedAndEmpty();
		m_ConditionTarget = new CCTSelf();
	}

	override bool HasProneException()
	{
		return true;
	}

	override bool HasTarget()
	{
		return false;
	}

	// not through a mask, as with eating
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		return player.CanEatAndDrink();
	}

	// each puff (CAContinuousRepeat: every GEB_PUFF_SECONDS while the button is held)
	override void OnFinishProgressServer(ActionData action_data)
	{
		ItemBase joint = action_data.m_MainItem;
		PlayerBase player = action_data.m_Player;
		if (!joint || !player)
			return;

		player.GebPuff();
		joint.AddQuantity(-1);
	}
};

modded class ActionConstructor
{
	override void RegisterActions(TTypenameArray actions)
	{
		super.RegisterActions(actions);
		actions.Insert(ActionSmokeJoint);
	}
};

modded class PlayerBase
{
	protected float m_GebHighEnd;			// server: when the high ends (seconds of mission time)
	protected int m_GebHighPuffs;			// server: the puffs that went into it

	// server: one puff on a lit joint. Each adds to how long the high lasts, and the first few to how strong it is.
	void GebPuff()
	{
		float now = g_Game.GetTime() * 0.001;
		float left = m_GebHighEnd - now;
		if (left <= 0)
		{
			left = 0;
			m_GebHighPuffs = 0;
		}

		left = Math.Min(GEB_HIGH_MAX, left + GEB_HIGH_PER_PUFF);
		m_GebHighEnd = now + left;
		m_GebHighPuffs++;

		if (Math.RandomFloat01() < GEB_HIGH_COUGH && GetSymptomManager())
			GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_COUGH);

		float strength = Math.Min(1, 0.4 + 0.2 * (m_GebHighPuffs - 1));
		GebSendHigh(left, strength);
	}

	// server: tell this player's client about their high (offline the client is right here)
	protected void GebSendHigh(float left, float strength)
	{
		if (!g_Game.IsMultiplayer())
		{
			geb_HighClient.Set(left, strength);
			return;
		}

		PlayerIdentity identity = GetIdentity();
		if (!identity)
			return;

		Param2<float, float> data = new Param2<float, float>(left, strength);
		g_Game.RPCSingleParam(this, GEB_RPC_HIGH, data, true, identity);
	}

	override void EEKilled(Object killer)
	{
		if (g_Game.IsServer())
		{
			m_GebHighEnd = 0;
			m_GebHighPuffs = 0;
		}

		super.EEKilled(killer);
	}

	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);

		if (rpc_type != GEB_RPC_HIGH || g_Game.IsDedicatedServer())
			return;

		Param2<float, float> data = new Param2<float, float>(0, 0);
		if (ctx.Read(data))
			geb_HighClient.Set(data.param1, data.param2);
	}
};

// The smoker's client: counts the high down between the server's messages, eases what is shown toward it (it comes on
// over a quarter of a minute and fades out over the last one) and drives the screen effect. Nothing shows while
// unconscious (the time still passes); dying or leaving the game stops it at once.
class geb_HighClient
{
	protected static float s_Left;			// seconds of high still to come
	protected static float s_Strength;		// how strong it is (0..1)
	protected static float s_Shown;			// how much of it shows now
	protected static PPERequester_GebHigh s_Requester;

	static void Set(float left, float strength)
	{
		s_Left = left;
		s_Strength = strength;
	}

	static void Update(float delta)
	{
		PlayerBase player = PlayerBase.Cast(g_Game.GetPlayer());
		if (!player || !player.IsAlive())
		{
			Stop();
			return;
		}

		float target = 0;
		if (s_Left > 0)
		{
			s_Left = Math.Max(0, s_Left - delta);
			if (!player.IsUnconscious())
				target = s_Strength * Math.Clamp(s_Left / GEB_HIGH_FADE, 0, 1);
		}

		float rate = delta / 15;
		s_Shown = s_Shown + Math.Clamp(target - s_Shown, -rate, rate);
		if (s_Shown <= 0.001)
		{
			s_Shown = 0;
			if (s_Requester && s_Requester.IsRequesterRunning())
				s_Requester.Stop();
			return;
		}

		if (!s_Requester)
			Class.CastTo(s_Requester, PPERequesterBank.GetRequester(PPERequester_GebHigh));
		if (!s_Requester)
			return;

		if (!s_Requester.IsRequesterRunning())
			s_Requester.Start();
		s_Requester.SetHigh(s_Shown, delta);
	}

	static void Stop()
	{
		s_Left = 0;
		s_Strength = 0;
		s_Shown = 0;
		if (s_Requester && s_Requester.IsRequesterRunning())
			s_Requester.Stop();
	}
};
