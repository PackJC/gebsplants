// The high's screen effect each frame, on the smoker's own client. See scripts/4_world/entities/geb_joint.c.
modded class MissionGameplay
{
	override void OnUpdate(float timeslice)
	{
		super.OnUpdate(timeslice);
		geb_HighClient.Update(timeslice);
	}

	// leaving the server: the effect ends here, so it can't follow the player into the menus
	override void OnMissionFinish()
	{
		geb_HighClient.Stop();
		super.OnMissionFinish();
	}
};
