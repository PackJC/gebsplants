<h1 align="center">
  <br>
  <img src=".github/logo.png" alt="Geb's Plants" width="500"/>
  <br>
  <a href="https://discord.gg/G8uSGZ8yyf" style="width:250"><img src="https://i.imgur.com/4IyA522.png" alt="Join Our Discord" width="250" style="margin-left:9%"/></a><img src="https://i.imgur.com/3rhti8A.gif" alt="Like & Favorite" width="500" style="margin-left:-10%"/>
  <br>
</h1>

<h3 align="center">Garden Crops and Wild Plants for DayZ</h3>

<p align="center">
  <img alt="Mod Version" src="https://img.shields.io/badge/Mod-v2.0.0-blue?style=for-the-badge">
  <img alt="DayZ Version" src="https://img.shields.io/badge/DayZ-v1.30-teal?style=for-the-badge">
  <a href="https://packjc.github.io/gebsplants/"><img alt="Website" src="https://img.shields.io/badge/Website-Garden%20Guide-1f8a4c?style=for-the-badge"></a>
</p>

<p align="center">
  <a href="https://packjc.github.io/gebsplants/">Website</a> •
  <a href="#key-features">Key Features</a> •
  <a href="#installation">Installation</a> •
  <a href="#main-classnames">Classnames</a> •
  <a href="#credits">Credits</a> •
  <a href="#license">License & Terms</a> •
  <a href='CHANGELOG.md'>Change Log</a>
</p>

## Information

Geb's Plants adds 30 garden crops to DayZ, and one of them, ginseng, also grows wild on the forest floor.
Every crop grows from its own seed packet through five stages in a garden plot. Most harvests can be eaten raw, baked, boiled or dried; tobacco is cured in the smoke and baled instead, the opium poppy gives its seed pods, coca its leaves, and cannabis its buds, which you roll into joints and smoke.

## Requirements

* DayZ 1.30. No other mods are needed: load Geb's Plants on both the server and every client.

## Key Features

* **Gardening**: 30 crops to grow in a garden plot (corn, okra, green beans, onions, garlic, yellow squash, watermelon, cantaloupe, carrots, cucumbers, barley, tobacco, cabbage, collards, sweet potatoes, beets, radishes, turnips, peas, pole beans, peanuts, strawberries, hops, sorghum, sunflowers, leeks, ginseng, opium poppies, coca and cannabis), each from its own seed packet through five growth stages to a harvest you can eat raw, bake, boil or dry (tobacco is cured instead; the opium poppy gives its seed pods, coca its leaves and cannabis its buds).
* **Seed saving**: cut, thresh or shell fresh seeds back out of a raw crop with a blade (garlic splits into cloves and sweet potatoes into seed pieces; some crops come from packets only). Watermelons and cantaloupes are cut into slices with a blade, like vanilla's pumpkin, and a sweet potato is peeled with a blade before it's eaten or cooked, like vanilla's potato.
* **Cannabis**: roll a gram of bud in a sheet of paper into a joint, light it with a lighter or a box of matches, and hold left click to smoke it: six puffs to a joint, and now and then a cough. Every puff tints the world round the colours of the rainbow for a while longer, about 15 minutes for a whole joint and up to 25, stronger over the first few puffs. Only the smoker sees it; a mask gets in the way, as with eating, and dying ends it.
* **Tobacco**: combine partial leaf bunches, tie leaves into hands, and keep adding matching leaves or hands until each hand holds 300 g. Cure them in the smoke of a stone oven, a closed barrel stove or an indoor fireplace, and start a bale with rope. Add cured hands, including partial ones, until it holds five full hands; any excess stays in the source hand. Green and cured tobacco stay separate.
* **Geb's Garden Guide**: a field guide to all 30 crops, printed on a folded map with its own cover: when each one ripens, what one plant gives and how to grow them. Found on the shelves of farms, villages and towns.
* **Wild plants**: wild American ginseng ("sang") grows on the forest floor near players, like vanilla's mushrooms, in shady hardwood coves. Chew the root, boil it into a tea or dry it to keep, or grow it from seed in a garden plot.
* **Server-controlled by design**: seed packets are ordinary loot and wild plants join the vanilla forest-floor events. Add only what you want.
* **Ready-made economy files**: on start the server writes the types for every crop, seed, packet and plant, and the ginseng event line, to `$profile:Gebs/mpmissions/`, like Gebsfish, and rewrites them only when the mod's version changes: each file carries the version in a stamp, so your edits stay put until then.
* Supported languages:
  - English
  - Czech
  - German
  - Russian
  - Polish
  - Hungarian
  - Italian
  - Spanish
  - French
  - Chinese (Traditional and Simplified)
  - Japanese
  - Portuguese
  > **Note**
  > Although supported languages are listed above, we cannot verify complete accuracy. If you are a native speaker and notice anything wrong, please reach out to us in the Discord via a ticket to assist us in getting proper translations.

## Installation

1. Subscribe to Geb's Plants on the [Steam Workshop](https://steamcommunity.com/sharedfiles/filedetails/?id=3823623344).
2. Install the published `@gebsplants` folder beside the DayZ server executable.
3. Copy the included `.bikey` into the server's `keys` folder.
4. Add `-mod=@gebsplants` to the server launch parameters. Every connecting player must load the same Workshop mod.
5. Start the server once. The mod writes `gebsplants-types.xml`, `gebsplants-events-children.xml` and `gebsplants-cfgeconomycore.xml` to `$profile:Gebs/mpmissions/`. Copy `gebsplants-types.xml` into `mpmissions/<your mission>/gebsplants/` and register it with the block from `gebsplants-cfgeconomycore.xml` in your `cfgeconomycore.xml` (the seed packets then spawn as farm loot), and merge the ginseng `<child>` line into the vanilla `TrajectoryDeciduous` event in `db/events.xml`. Ginseng then shares that event's spawns with its mushrooms, so raise the event's `<nominal>` if you want to keep as many mushrooms. The files are only rewritten when the mod's version changes or a file is missing.

The [server-owner guide](https://packjc.github.io/gebsplants/#setup) walks through every step, with copy-ready XML.

## Main Classnames

| Category | Classnames |
| --- | --- |
| Garden crops | `geb_Barley`, `geb_Beets`, `geb_Cabbage`, `geb_CannabisBud`, `geb_Joint`, `geb_JointLit`, `geb_Cantaloupe`, `geb_CantaloupeSlice`, `geb_Carrot`, `geb_CocaLeaves`, `geb_Collards`, `geb_Cucumber`, `geb_Corn`, `geb_Garlic`, `geb_GreenBeans`, `geb_TobaccoLeaves`, `geb_TobaccoHand`, `geb_HopCones`, `geb_Leek`, `geb_Okra`, `geb_Onion`, `geb_PeaPods`, `geb_Peanuts`, `geb_PoleBeans`, `geb_PoppyPod`, `geb_Radishes`, `geb_Sorghum`, `geb_Strawberries`, `geb_SunflowerHead`, `geb_SweetPotato`, `geb_SweetPotatoPeeled`, `geb_TobaccoBale`, `geb_Turnip`, `geb_Watermelon`, `geb_WatermelonSlice`, `geb_YellowSquash` |
| Seed packets | `geb_BarleySeedsPack`, `geb_BeetSeedsPack`, `geb_CabbageSeedsPack`, `geb_CannabisSeedsPack`, `geb_CantaloupeSeedsPack`, `geb_CarrotSeedsPack`, `geb_CocaSeedsPack`, `geb_CollardSeedsPack`, `geb_CucumberSeedsPack`, `geb_GinsengSeedsPack`, `geb_PoleBeanSeedsPack`, `geb_GreenBeanSeedsPack`, `geb_HopRhizomesPack`, `geb_LeekSeedsPack`, `geb_OkraSeedsPack`, `geb_OnionSeedsPack`, `geb_PeaSeedsPack`, `geb_PeanutSeedsPack`, `geb_PoppySeedsPack`, `geb_RadishSeedsPack`, `geb_GarlicClovesPack`, `geb_SorghumSeedsPack`, `geb_StrawberrySeedsPack`, `geb_SunflowerSeedsPack`, `geb_CornSeedsPack`, `geb_SweetPotatoSeedPiecesPack`, `geb_TobaccoSeedsPack`, `geb_TurnipSeedsPack`, `geb_WatermelonSeedsPack`, `geb_YellowSquashSeedsPack` |
| Seeds | `geb_BarleySeeds`, `geb_GreenBeanSeeds`, `geb_BeetSeeds`, `geb_CabbageSeeds`, `geb_CannabisSeeds`, `geb_CantaloupeSeeds`, `geb_CarrotSeeds`, `geb_CocaSeeds`, `geb_CollardSeeds`, `geb_CornSeeds`, `geb_CucumberSeeds`, `geb_PeaSeeds`, `geb_GarlicCloves`, `geb_GinsengSeeds`, `geb_HopRhizomes`, `geb_LeekSeeds`, `geb_OkraSeeds`, `geb_OnionSeeds`, `geb_PoleBeanSeeds`, `geb_PoppySeeds`, `geb_RadishSeeds`, `geb_PeanutSeeds`, `geb_SorghumSeeds`, `geb_YellowSquashSeeds`, `geb_StrawberrySeeds`, `geb_SunflowerSeeds`, `geb_SweetPotatoSeedPieces`, `geb_TobaccoSeeds`, `geb_TurnipSeeds`, `geb_WatermelonSeeds` |
| Plants | `geb_Plant_Barley`, `geb_Plant_Beets`, `geb_Plant_GreenBeans`, `geb_Plant_Cabbage`, `geb_Plant_Cannabis`, `geb_Plant_Cantaloupe`, `geb_Plant_Carrot`, `geb_Plant_Coca`, `geb_Plant_Collards`, `geb_Plant_Corn`, `geb_Plant_Cucumber`, `geb_Plant_Garlic`, `geb_Plant_Ginseng`, `geb_Plant_Hops`, `geb_Plant_Leek`, `geb_Plant_Okra`, `geb_Plant_Onion`, `geb_Plant_Peas`, `geb_Plant_Peanuts`, `geb_Plant_PoleBeans`, `geb_Plant_Poppy`, `geb_Plant_Radish`, `geb_Plant_Sorghum`, `geb_Plant_Strawberries`, `geb_Plant_Sunflower`, `geb_Plant_SweetPotato`, `geb_Plant_Tobacco`, `geb_Plant_Turnip`, `geb_Plant_Watermelon`, `geb_Plant_YellowSquash` |
| Wild plants | `geb_Ginseng` |
| Garden guide | `geb_GardenGuide` |

The complete searchable list of 128 public config classes is on the [project website](https://packjc.github.io/gebsplants/#classnames).

## The Geb's family

Every mod by Geb stands on its own, so a server can run the ones it wants:

* [Gebsfish](https://github.com/PackJC/gebsfish) ([wiki](https://packjc.github.io/gebsfish/)): the fishing overhaul, with 94 catchable species, rods, lures, coolers, the jon boat and more
* [Geb's Animals](https://github.com/PackJC/gebsanimals) ([website](https://packjc.github.io/gebsanimals/)): 15 wildlife species
* [Geb's Plants](https://github.com/PackJC/gebsplants) ([website](https://packjc.github.io/gebsplants/)) (this mod): 30 garden crops including wild ginseng
* [Geb's Mushrooms](https://github.com/PackJC/gebsmushrooms) ([website](https://packjc.github.io/gebsmushrooms/)): 69 edible, poisonous and psychedelic fungi
* [Alien Invasion](https://github.com/PackJC/alieninvasion) ([website](https://packjc.github.io/alieninvasion/)): UFO crash sites, Little Green Men and the Montauk plasma rifle
* [Thanksgiving](https://steamcommunity.com/sharedfiles/filedetails/?id=2886269800) (Workshop): Pilgrim clothes, turkeys and a flintlock musket for the holiday
* [Great Smoky Mountains](https://github.com/PackJC/greatsmokymountains) ([Workshop](https://steamcommunity.com/sharedfiles/filedetails/?id=2812533524)): a 20 x 20 km map of the Smokies at real scale

Geb's Animals, Plants and Mushrooms grew out of one mod, **Geb's Flora & Fauna**, and keep its classnames. The released Flora & Fauna had the animals and four mushrooms but no plants, so Geb's Plants only adds new items. A server that ran it should load Geb's Animals and Geb's Mushrooms to keep every item players already have, because leaving one of those out deletes its items from the server's storage at the next restart.

## Credits

- Geb, creator and author
- The DayZ community for reporting bugs and inspiration throughout the life of the mod
- [CADNav](https://www.cadnav.com/) for the opium poppy pod model, improved and rebuilt for the mod
- The crops' textures are built from free photos on Wikimedia Commons (cut out, recoloured and recombined). All are public domain or CC0 except these seven, used under [CC BY 2.0](https://creativecommons.org/licenses/by/2.0/): [Corn on the cob](https://commons.wikimedia.org/wiki/File:Corn_on_the_cob.jpg) by darwin Bell, [Ears of corn](https://commons.wikimedia.org/wiki/File:Ears_of_corn_(3934435595).jpg) by normanack, [Sorghum bicolor flowerhead](https://commons.wikimedia.org/wiki/File:Sorghum_bicolor_flowerhead1_NWS_-_Flickr_-_Macleay_Grass_Man.jpg) by Harry Rose, [Leaves, Wild strawberry](https://commons.wikimedia.org/wiki/File:Leaves,_Wild_strawberry_-_Flickr_-_nekonomania.jpg) by Yoko Nekonomania, [Papaver somniferum leaf1](https://commons.wikimedia.org/wiki/File:Papaver_somniferum_leaf1_(15289790551).jpg) and [Papaver somniferum flower4](https://commons.wikimedia.org/wiki/File:Papaver_somniferum_flower4_(15106250090).jpg) by Harry Rose, and [Poppy seed heads](https://commons.wikimedia.org/wiki/File:Poppy_seed_heads_(4824568284).jpg) by Tony Hisgett; and, under [CC BY 4.0](https://creativecommons.org/licenses/by/4.0/), [Coca (Erythroxylum coca) en Meta (Colombia) 1](https://commons.wikimedia.org/wiki/File:Coca_(Erythroxylum_coca)_en_Meta_(Colombia)_1.jpg) by Danna Guevara (the coca bush and its leaves)


## Support

If you like this project and think it has improved your server in any way, consider contributing! We are always looking for help with ideas, new models, and any monetary support that can help improve the mod. Open a ticket in the [Discord](https://discord.gg/G8uSGZ8yyf) to discuss how you can contribute, or report a bug on [GitHub](https://github.com/PackJC/gebsplants/issues).


## License

[Attribution-NonCommercial-NoDerivatives 4.0 International](https://github.com/PackJC/gebsplants/blob/master/LICENSE)

## Usage & Terms
This item is NOT authorized (strictly forbidden) for any of these conditions:
- posting on Steam, except under the Steam account Cole.
- hosting on any download server other than Geb's Plants current workshop download.
- hosting on any launcher for distribution other than Geb's Plants current workshop download.
- to be packaged in any form other than Geb's Plants current workshop download.
- to create derivative works.

## PERMISSION IS NOT GRANTED FOR THIS MOD TO BE INCLUDED IN A "SERVER PACK" or "MOD PACK" DO NOT EVEN ASK TO REPACK. NO. NOT ALLOWED.
Use a Collection if you want to include this mod on your server for your users.

## Monetization
You are hereby given monetization approval under the conditions that you follow the DayZ Server Monetization agreement and have obtained permission from Bohemia. Read more here https://www.bohemia.net/monetization

## Donations
We accept donations at https://www.paypal.com/paypalme/packjc every dollar counts and we greatly appreciate any contributions!

### Copyright © Smoky Mountain Software 2022-2026
