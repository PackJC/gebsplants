class CfgPatches
{
	class gebsplants
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Scripts",
			"DZ_Gear_Cultivation",
			"DZ_Gear_Food"
		};
	};
};
class CfgMods
{
	class gebsplants
	{
		dir="gebsplants";
		picture="gebsplants\data\logo.paa";			// picture in expanded description
		logoSmall="gebsplants\data\logo.paa";			// icon next to mod name when description is not expanded
		logo="gebsplants\data\logo.paa";				// logo below game menu
		logoOver="gebsplants\data\logo_hover.paa";	// logo hovered (CfgMods reads logoOver, as mod.cpp does)
		overview="Geb's Plants: 30 garden crops including wild ginseng for DayZ";	// keep in step with mod.cpp's overview
		action="";
		name="Geb's Plants";
		// Without this the engine looks for gebsplants/Anims/cfg/skeletons.anim.xml
		// and logs "ANIMATION (E): Can't load ..." on every start; point it at vanilla's.
		skeletonDefinitions="DZ/anims/cfg/skeletons.anim.xml";
		credits="Geb";
		author="Geb";
		authorID="0";
		version="2.0.0";
		extra=0;
		type="mod";
		dependencies[]=
		{
			"Game",
			"World",
			"Mission"
		};
		class defs
		{
			class gameScriptModule
			{
				value="";
				files[]=
				{
					"gebsplants/scripts/3_game"
				};
			};
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"gebsplants/scripts/4_world"
				};
			};
			class missionScriptModule
			{
				value="";
				files[]=
				{
					"gebsplants/scripts/5_mission"
				};
			};
		};
	};
};
