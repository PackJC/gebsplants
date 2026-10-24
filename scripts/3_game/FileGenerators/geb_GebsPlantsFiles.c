// Writes Geb's Plants' Central Economy files into $profile:Gebs/mpmissions/ on server start, next to Gebsfish's.
// Each file's second line is "<!-- Version: x -->", the mod version (constants.c). As in Gebsfish, a file is rewritten
// only when it is missing or that version differs, so admin edits survive restarts until the version changes; bump
// VERSION_GEBSPLANTS whenever this generator's output changes.
//
// Server owners copy gebsplants-types.xml into mpmissions/<mission>/gebsplants/ and register it with the block in
// gebsplants-cfgeconomycore.xml. Seed packets are farm loot like vanilla's; wild ginseng grows through the vanilla
// TrajectoryDeciduous event, so its <child> line in gebsplants-events-children.xml is merged into that event by hand.
class geb_GebsPlantsFiles
{
	protected const string DIRECTORY_PATH = "$profile:Gebs/mpmissions/";
	protected const string VERSION_PREFIX = "<!-- Version: ";
	protected const string LOG_PREFIX = "[GebsPlants] ";

	void GenerateAll()
	{
		if ( !GetGame() || !GetGame().IsServer() )
			return;

		MakeDirectory("$profile:Gebs");
		MakeDirectory(DIRECTORY_PATH);

		WriteTypes();
		WriteEventChildren();
		WriteEconomyCore();
	}

	// ------------------------------------------------------------------------------------------------------------
	// Files
	// ------------------------------------------------------------------------------------------------------------

	protected void WriteTypes()
	{
		string name = "gebsplants-types.xml";
		FileHandle file = BeginFile(name, "Register with gebsplants-cfgeconomycore.xml, or merge into db/types.xml.");
		if ( !file )
			return;

		FPrintln(file, "<types>");
		FPrintln(file, "    <!-- Seed packets: farm loot like vanilla's seed packs. Vanilla's four packs are about 30 each; these 30 share the same spots, so each is lower -->");
		WriteTypeList(file, GetSeedPackets(), 4, 14400, 2, false, "food", "Farm");
		FPrintln(file, "    <!-- Geb's Garden Guide: a field guide on vanilla's folded map, rare on the shelves of farms, villages and towns (vanilla's map is 50 in hunting and office spots) -->");
		WriteType(file, "geb_GardenGuide", 6, 14400, 3, false, "tools", "Farm,Village,Town", "shelves");
		FPrintln(file, "    <!-- Wild ginseng (grows through TrajectoryDeciduous, like the mushrooms). Lifetime 3600 rather than the mushrooms' 900: a garden harvest is the same class and drops at the player's feet -->");
		WriteTypeList(file, GetWildPlants(), 0, 3600, 0, true, "food", "");
		FPrintln(file, "    <!-- Harvests, slices, tobacco and joints (from the garden only) -->");
		WriteTypeList(file, GetCrops(), 0, 14400, 0, true, "food", "");
		FPrintln(file, "    <!-- Seeds (from packets, or cut out of a harvest) -->");
		WriteTypeList(file, GetSeeds(), 0, 14400, 0, true, "tools", "");
		FPrintln(file, "    <!-- The growing plants in a garden plot -->");
		WriteTypeList(file, GetPlants(), 0, 28800, 0, true, "tools", "");
		FPrintln(file, "</types>");

		EndFile(file, name);
	}

	// The <child> lines to add to vanilla events. A mod can't safely redefine a vanilla event from its own events
	// file, so these are merged by hand into db/events.xml.
	protected void WriteEventChildren()
	{
		string name = "gebsplants-events-children.xml";
		FileHandle file = BeginFile(name, "Merge each event's <child> lines into the <children> of the vanilla event of the same name in db/events.xml.");
		if ( !file )
			return;

		FPrintln(file, "<merge>");
		FPrintln(file, "    <!-- Wild ginseng on the forest floor of the broadleaf woods, with the mushrooms -->");
		FPrintln(file, "    <!-- An event's children share its spawns equally, so ginseng takes a share from the mushrooms already in it (vanilla Chernarus: its Lactarius, about half). To keep as many mushrooms, raise the event's <nominal> in db/events.xml -->");
		FPrintln(file, "    <event name=\"TrajectoryDeciduous\">");
		FPrintln(file, "        <children>");
		WriteChildren(file, GetDeciduousPlants(), "lootmax=\"0\" lootmin=\"0\" max=\"0\" min=\"0\"");
		FPrintln(file, "        </children>");
		FPrintln(file, "    </event>");
		FPrintln(file, "</merge>");

		EndFile(file, name);
	}

	// ------------------------------------------------------------------------------------------------------------
	// Class lists (from the mod's config; keep in step when classes are added)
	// ------------------------------------------------------------------------------------------------------------

	// Seed packets
	protected TStringArray GetSeedPackets()
	{
		TStringArray names = {
			"geb_BarleySeedsPack", "geb_BeetSeedsPack", "geb_CabbageSeedsPack", "geb_CannabisSeedsPack",
			"geb_CantaloupeSeedsPack", "geb_CarrotSeedsPack", "geb_CocaSeedsPack", "geb_CollardSeedsPack",
			"geb_CucumberSeedsPack", "geb_GinsengSeedsPack", "geb_PoleBeanSeedsPack", "geb_GreenBeanSeedsPack",
			"geb_HopRhizomesPack", "geb_LeekSeedsPack", "geb_OkraSeedsPack", "geb_OnionSeedsPack",
			"geb_PeaSeedsPack", "geb_PeanutSeedsPack", "geb_PoppySeedsPack", "geb_RadishSeedsPack",
			"geb_GarlicClovesPack", "geb_SorghumSeedsPack", "geb_StrawberrySeedsPack", "geb_SunflowerSeedsPack",
			"geb_CornSeedsPack", "geb_SweetPotatoSeedPiecesPack", "geb_TobaccoSeedsPack", "geb_TurnipSeedsPack",
			"geb_WatermelonSeedsPack", "geb_YellowSquashSeedsPack"
		};
		return names;
	}

	// Wild plants
	protected TStringArray GetWildPlants()
	{
		TStringArray names = {
			"geb_Ginseng"
		};
		return names;
	}

	// Harvests, slices, the peeled sweet potato, tobacco and joints
	protected TStringArray GetCrops()
	{
		TStringArray names = {
			"geb_Barley", "geb_Beets", "geb_Cabbage", "geb_CannabisBud",
			"geb_Joint", "geb_JointLit", "geb_Cantaloupe", "geb_CantaloupeSlice",
			"geb_Carrot", "geb_CocaLeaves", "geb_Collards", "geb_Cucumber",
			"geb_Corn", "geb_Garlic", "geb_GreenBeans", "geb_TobaccoLeaves",
			"geb_TobaccoHand", "geb_HopCones", "geb_Leek", "geb_Okra",
			"geb_Onion", "geb_PeaPods", "geb_Peanuts", "geb_PoleBeans",
			"geb_PoppyPod", "geb_Radishes", "geb_Sorghum", "geb_Strawberries",
			"geb_SunflowerHead", "geb_SweetPotato", "geb_SweetPotatoPeeled", "geb_TobaccoBale",
			"geb_Turnip", "geb_Watermelon", "geb_WatermelonSlice", "geb_YellowSquash"
		};
		return names;
	}

	// Seeds
	protected TStringArray GetSeeds()
	{
		TStringArray names = {
			"geb_BarleySeeds", "geb_GreenBeanSeeds", "geb_BeetSeeds", "geb_CabbageSeeds",
			"geb_CannabisSeeds", "geb_CantaloupeSeeds", "geb_CarrotSeeds", "geb_CocaSeeds",
			"geb_CollardSeeds", "geb_CornSeeds", "geb_CucumberSeeds", "geb_PeaSeeds",
			"geb_GarlicCloves", "geb_GinsengSeeds", "geb_HopRhizomes", "geb_LeekSeeds",
			"geb_OkraSeeds", "geb_OnionSeeds", "geb_PoleBeanSeeds", "geb_PoppySeeds",
			"geb_RadishSeeds", "geb_PeanutSeeds", "geb_SorghumSeeds", "geb_YellowSquashSeeds",
			"geb_StrawberrySeeds", "geb_SunflowerSeeds", "geb_SweetPotatoSeedPieces", "geb_TobaccoSeeds",
			"geb_TurnipSeeds", "geb_WatermelonSeeds"
		};
		return names;
	}

	// Garden plants
	protected TStringArray GetPlants()
	{
		TStringArray names = {
			"geb_Plant_Barley", "geb_Plant_Beets", "geb_Plant_GreenBeans", "geb_Plant_Cabbage",
			"geb_Plant_Cannabis", "geb_Plant_Cantaloupe", "geb_Plant_Carrot", "geb_Plant_Coca",
			"geb_Plant_Collards", "geb_Plant_Corn", "geb_Plant_Cucumber", "geb_Plant_Garlic",
			"geb_Plant_Ginseng", "geb_Plant_Hops", "geb_Plant_Leek", "geb_Plant_Okra",
			"geb_Plant_Onion", "geb_Plant_Peas", "geb_Plant_Peanuts", "geb_Plant_PoleBeans",
			"geb_Plant_Poppy", "geb_Plant_Radish", "geb_Plant_Sorghum", "geb_Plant_Strawberries",
			"geb_Plant_Sunflower", "geb_Plant_SweetPotato", "geb_Plant_Tobacco", "geb_Plant_Turnip",
			"geb_Plant_Watermelon", "geb_Plant_YellowSquash"
		};
		return names;
	}

	// Into TrajectoryDeciduous
	protected TStringArray GetDeciduousPlants()
	{
		TStringArray names = {
			"geb_Ginseng"
		};
		return names;
	}

	// ------------------------------------------------------------------------------------------------------------
	// Helpers
	// ------------------------------------------------------------------------------------------------------------

	// Opens fileName for writing with the XML/version header. Returns an empty handle when the file is already
	// at the current version (nothing to do) or can't be created.
	protected FileHandle BeginFile(string fileName, string usage)
	{
		FileHandle file;
		string path = DIRECTORY_PATH + fileName;
		if ( IsCurrentVersion(path) )
			return file;

		file = OpenFile(path, FileMode.WRITE);
		if ( !file )
		{
			Print(LOG_PREFIX + "Could not create " + path);
			return file;
		}

		FPrintln(file, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>");
		FPrintln(file, VERSION_PREFIX + FileStamp() + " -->");
		FPrintln(file, "<!-- Geb's Plants: " + usage + " -->");
		return file;
	}

	protected void EndFile(FileHandle file, string fileName)
	{
		CloseFile(file);
		Print(LOG_PREFIX + fileName + " generated in " + DIRECTORY_PATH);
	}

	protected bool IsCurrentVersion(string path)
	{
		if ( !FileExist(path) )
			return false;

		FileHandle file = OpenFile(path, FileMode.READ);
		if ( !file )
			return false;

		string line;
		string found = "";
		for (int i = 0; i < 5 && FGets(file, line) > 0; i++)
		{
			int start = line.IndexOf(VERSION_PREFIX);
			if ( start == -1 )
				continue;

			string tail = line.Substring(start + VERSION_PREFIX.Length(), line.Length() - start - VERSION_PREFIX.Length());
			int end = tail.IndexOf("-->");
			if ( end != -1 )
				found = tail.Substring(0, end).Trim();
			break;
		}

		CloseFile(file);
		return found == FileStamp();
	}

	// "2.0.0": the mod version
	protected string FileStamp()
	{
		return VERSION_GEBSPLANTS;
	}

	// One <type> per class in the list, all with the same numbers.
	protected void WriteTypeList(FileHandle file, TStringArray classes, int nominal, int lifetime, int min, bool crafted, string category, string usage)
	{
		foreach (string typeName : classes)
			WriteType(file, typeName, nominal, lifetime, min, crafted, category, usage);
	}

	// usage: one usage flag or several separated by commas; placeTag: an optional <tag> (shelves, floor, ground).
	protected void WriteType(FileHandle file, string typeName, int nominal, int lifetime, int min, bool crafted, string category, string usage, string placeTag = "")
	{
		string craftedFlag = "0";
		if ( crafted )
			craftedFlag = "1";

		FPrintln(file, "    <type name=\"" + typeName + "\">");
		FPrintln(file, "        <nominal>" + nominal.ToString() + "</nominal>");
		FPrintln(file, "        <lifetime>" + lifetime.ToString() + "</lifetime>");
		FPrintln(file, "        <restock>0</restock>");
		FPrintln(file, "        <min>" + min.ToString() + "</min>");
		FPrintln(file, "        <quantmin>-1</quantmin>");
		FPrintln(file, "        <quantmax>-1</quantmax>");
		FPrintln(file, "        <cost>100</cost>");
		FPrintln(file, "        <flags count_in_cargo=\"0\" count_in_hoarder=\"0\" count_in_map=\"1\" count_in_player=\"0\" crafted=\"" + craftedFlag + "\" deloot=\"0\"/>");
		if ( category != "" )
			FPrintln(file, "        <category name=\"" + category + "\"/>");
		if ( placeTag != "" )
			FPrintln(file, "        <tag name=\"" + placeTag + "\"/>");
		if ( usage != "" )
		{
			TStringArray usages = new TStringArray;
			usage.Split(",", usages);
			foreach (string usageName : usages)
				FPrintln(file, "        <usage name=\"" + usageName + "\"/>");
		}
		FPrintln(file, "    </type>");
	}

	// <child> lines for one vanilla event: every class in the list with the same attributes.
	protected void WriteChildren(FileHandle file, TStringArray classes, string attributes)
	{
		foreach (string childType : classes)
			FPrintln(file, "            <child " + attributes + " type=\"" + childType + "\"/>");
	}

	protected void WriteEconomyCore()
	{
		string name = "gebsplants-cfgeconomycore.xml";
		FileHandle file = BeginFile(name, "Copy gebsplants-types.xml into mpmissions/<your mission>/gebsplants/ and paste the <ce> block inside <economycore> in cfgeconomycore.xml.");
		if ( !file )
			return;

		FPrintln(file, "<economycore>");
		FPrintln(file, "    <ce folder=\"gebsplants\">");
		FPrintln(file, "        <file name=\"gebsplants-types.xml\" type=\"types\" />");
		FPrintln(file, "    </ce>");
		FPrintln(file, "</economycore>");

		EndFile(file, name);
	}
}
