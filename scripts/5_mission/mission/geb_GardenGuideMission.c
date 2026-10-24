// Unfolding Geb's Garden Guide runs vanilla's ActionUnfoldMap, which opens MENU_MAP. While the player holds an
// unfolded guide, that menu is geb_GardenGuideMenu (the guide as a page, the way the map screen shows the map) instead
// of the map screen; every other map, and the map shortcut key, open as before.
modded class MissionGameplay
{
	override UIScriptedMenu CreateScriptedMenu(int id)
	{
		if (id == MENU_MAP)
		{
			PlayerBase player = PlayerBase.Cast(g_Game.GetPlayer());
			if (player && player.IsMapOpen() && geb_GardenGuide.Cast(player.GetItemInHands()))
			{
				UIScriptedMenu menu = new geb_GardenGuideMenu;
				menu.SetID(id);
				return menu;
			}
		}

		return super.CreateScriptedMenu(id);
	}
};
