// Shared by tobacco's native stacks and crafting recipes. Quantities of leaves/hands are grams;
// bale quantities remain hand equivalents (0..5), preserving existing saved bales.
class geb_TobaccoStacking
{
	static bool CanMix(Edible_Base a, Edible_Base b)
	{
		if (!a || !b || a == b || a.GetIsFrozen() || b.GetIsFrozen() || a.GetQuantity() <= 0 || b.GetQuantity() <= 0)
			return false;
		FoodStageType stage = a.GetFoodStageType();
		return stage == b.GetFoodStageType() && (stage == FoodStageType.RAW || stage == FoodStageType.DRIED);
	}

	// A merge must not give older leaves a fresh decay timer or remove contamination. Cured (DRIED) tobacco is
	// matched by its stage: vanilla Edible_Base.ProcessDecay leaves dried fruit and veg at last decay stage NONE
	// (they never decay), so the timer test below never sees it.
	static void KeepFoodProperties(Edible_Base target, Edible_Base source)
	{
		if (!target || !source)
			return;
		int agents = target.GetAgents() | source.GetAgents();
		FoodStageType stage = source.GetFoodStageType();
		if (stage == FoodStageType.DRIED)
		{
			if (target.GetFoodStageType() != FoodStageType.DRIED)
				target.ChangeFoodStage(FoodStageType.DRIED);
		}
		else if (source.GetLastDecayStage() == stage)
		{
			if (target.GetLastDecayStage() != target.GetFoodStageType() || source.GetDecayTimer() < target.GetDecayTimer())
				target.TransferFoodStage(source);
		}
		target.TransferAgents(agents);
		if (target.GetFoodStageType() == FoodStageType.RAW)
			target.ResetCookingTime(); // Adding fresh tobacco must not finish curing on the old hand's timer.
	}

	static void AddLeaves(Edible_Base source, Edible_Base target)
	{
		if (!CanMix(source, target))
			return;
		float held = target.GetQuantity();
		float take = Math.Min(source.GetQuantity(), target.GetQuantityMax() - held);
		if (take <= 0)
			return;
		float health = (target.GetHealth01("", "") * held + source.GetHealth01("", "") * take) / (held + take);
		KeepFoodProperties(target, source);
		target.SetHealth01("", "", health);
		target.AddQuantity(take);
		source.AddQuantity(-take);
	}

	static bool CanBale(Edible_Base hand)
	{
		// ItemBase.SetQuantity treats <= 0.001 as zero. A smaller hand must be topped up
		// before starting a bale, or that empty bale would be deleted along with the rope.
		return hand && !hand.GetIsFrozen() && hand.GetQuantityNormalized() > 0.001 && hand.GetFoodStageType() == FoodStageType.DRIED;
	}

	static void AddToBale(Edible_Base hand, ItemBase bale)
	{
		if (!CanBale(hand) || !bale)
			return;
		float held = bale.GetQuantity();
		float take = Math.Min(hand.GetQuantityNormalized(), bale.GetQuantityMax() - held);
		if (take <= 0)
			return;
		float health = (bale.GetHealth01("", "") * held + hand.GetHealth01("", "") * take) / (held + take);
		bale.SetHealth01("", "", health);
		bale.TransferAgents(hand.GetAgents());
		bale.AddQuantity(take);
		hand.AddQuantity(-take * hand.GetQuantityMax());
	}
};

class geb_TobaccoBale : ItemBase
{
	void geb_TobaccoBale()
	{
		// The vanilla default is one decimal place; partial hands need finer synchronization.
		UpdateNetSyncVariableFloat("m_VarQuantity", GetQuantityMin(), GetQuantityMax(), 4);
	}
};
