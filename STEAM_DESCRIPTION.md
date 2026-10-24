[img]https://i.imgur.com/3rhti8A.gif[/img]
[url=https://discord.gg/G8uSGZ8yyf][img]https://i.imgur.com/4IyA522.png[/img][/url]

[h1]Mod Information[/h1]
Geb's Plants brings gardening and foraging to DayZ. It adds [b]30 garden crops[/b], each grown from its own Geb's Garden seed packet, and one of them, [b]ginseng[/b], also grows wild on the forest floor. Most harvests can be eaten raw, baked, boiled or dried; tobacco is cured in the smoke and baled, and cannabis buds are rolled into joints and smoked.

It's meant to add immersion, not to make survival easier: crops take real time to grow, and seed packets are ordinary loot.

[b]Website (every crop and the setup guide):[/b] [url=https://packjc.github.io/gebsplants/]packjc.github.io/gebsplants[/url]

[h1]Requirements[/h1]
[list]
[*] DayZ 1.30.
[*] No other mods. Load it on both the server and every client.
[/list]

[h1]Features[/h1]
[list]
[*] [b]30 garden crops:[/b] corn, okra, green beans, onions, garlic, yellow squash, watermelon, cantaloupe, carrots, cucumbers, barley, tobacco, cabbage, collards, sweet potatoes, beets, radishes, turnips, peas, pole beans, peanuts, strawberries, hops, sorghum, sunflowers, leeks, ginseng, opium poppies, coca and cannabis.
[*] [b]Real growing:[/b] sow the seeds from a packet in a tilled garden plot, water them, and watch five growth stages. Harvest when ripe, before it dries out or spoils.
[*] [b]Seed saving:[/b] cut, thresh or shell fresh seeds out of a raw harvest with a blade. Garlic splits into cloves and sweet potatoes into seed pieces; some crops come from packets only.
[*] [b]Melons and sweet potatoes:[/b] cut a watermelon or cantaloupe into slices with a blade, like vanilla's pumpkin, and peel a sweet potato before eating or cooking it, like vanilla's potato.
[*] [b]Cannabis:[/b] roll a gram of bud in a sheet of paper into a joint, light it with a lighter or matches, and hold left click to smoke it. Every puff tints the world round the colours of the rainbow for a while longer: about 15 minutes for a whole joint, up to 25. Only the smoker sees it.
[*] [b]Tobacco:[/b] tie the leaves into hands of up to 300 g and cure them in the smoke of a stone oven, a closed barrel stove or an indoor fireplace, then bale five cured hands with rope.
[*] [b]Geb's Garden Guide:[/b] a field guide to all 30 crops, printed on a folded map: when each one ripens, what one plant gives and how to grow them. Found on the shelves of farms, villages and towns.
[*] [b]Wild ginseng ("sang"):[/b] dig it in shady hardwood woods; chew, brew or dry the root, and grow more from its berries.
[*] [b]Server-controlled:[/b] nothing replaces vanilla. Seed packets are loot, ginseng joins the vanilla forest-floor event, and the server writes ready-made economy files, like Gebsfish.
[/list]

[h1]Server Setup[/h1]
Start the server once and the mod writes [b]gebsplants-types.xml[/b], [b]gebsplants-events-children.xml[/b] and [b]gebsplants-cfgeconomycore.xml[/b] to $profile:Gebs/mpmissions/. They're only rewritten when the mod's version changes, so your edits stay put.
[list]
[*] Copy gebsplants-types.xml into mpmissions/<your mission>/gebsplants/ and paste the block from gebsplants-cfgeconomycore.xml into your cfgeconomycore.xml. The seed packets then spawn as farm loot.
[*] For wild ginseng, merge the <child> line from gebsplants-events-children.xml into the vanilla [b]TrajectoryDeciduous[/b] event in db/events.xml.
[/list]
The website has the full guide.

[h1]Classnames[/h1]
All 128 public classnames are on the website, with one-click copy: [url=https://packjc.github.io/gebsplants/#classnames]packjc.github.io/gebsplants/#classnames[/url]

[h1]Coming from Geb's Flora & Fauna[/h1]
Geb's Animals, Plants and Mushrooms grew out of Geb's Flora & Fauna and keep its classnames. Geb's Plants only adds new items; if your server ran Flora & Fauna, also load Geb's Animals and Geb's Mushrooms, or their items are deleted at the next restart.

[h1]Supported Languages[/h1]
English, Czech, German, Russian, Polish, Hungarian, Italian, Spanish, French, Chinese (Traditional), Chinese (Simplified), Japanese, Portuguese.

If you're a native speaker and spot a bad translation, please tell us in the Discord.

[h1]The Geb's Family[/h1]
Every mod by Geb stands on its own, so a server can run the ones it wants:
[list]
[*] [url=https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117]Gebsfish[/url]: the fishing overhaul, with 94 catchable species, rods, lures, coolers, the jon boat and more
[*] [url=https://steamcommunity.com/sharedfiles/filedetails/?id=2764114664]Geb's Animals[/url]: 15 wildlife species
[*] [b]Geb's Plants[/b] (this mod): 30 garden crops including wild ginseng
[*] [url=https://packjc.github.io/gebsmushrooms/]Geb's Mushrooms[/url]: 69 edible, poisonous and psychedelic fungi
[*] [url=https://steamcommunity.com/sharedfiles/filedetails/?id=2840597308]Alien Invasion[/url]: UFO crash sites, Little Green Men and the Montauk plasma rifle
[*] [url=https://steamcommunity.com/sharedfiles/filedetails/?id=2886269800]Thanksgiving[/url]: Pilgrim clothes, turkeys and a flintlock musket for the holiday
[*] [url=https://steamcommunity.com/sharedfiles/filedetails/?id=2812533524]Great Smoky Mountains[/url]: a 20 x 20 km map of the Smokies at real scale
[/list]

[h1]Contributors & Credits[/h1]
[list]
[*] Geb, creator and author
[*] The DayZ Modding Community <3
[*] [url=https://www.cadnav.com/]CADNav[/url] for the opium poppy pod model, improved and rebuilt for the mod
[*] The crops' textures are built from free photos on Wikimedia Commons. All are public domain or CC0 except these seven, used under [url=https://creativecommons.org/licenses/by/2.0/]CC BY 2.0[/url]: [url=https://commons.wikimedia.org/wiki/File:Corn_on_the_cob.jpg]Corn on the cob[/url] by darwin Bell, [url=https://commons.wikimedia.org/wiki/File:Ears_of_corn_(3934435595).jpg]Ears of corn[/url] by normanack, [url=https://commons.wikimedia.org/wiki/File:Sorghum_bicolor_flowerhead1_NWS_-_Flickr_-_Macleay_Grass_Man.jpg]Sorghum bicolor flowerhead[/url] by Harry Rose, [url=https://commons.wikimedia.org/wiki/File:Leaves,_Wild_strawberry_-_Flickr_-_nekonomania.jpg]Leaves, Wild strawberry[/url] by Yoko Nekonomania, [url=https://commons.wikimedia.org/wiki/File:Papaver_somniferum_leaf1_(15289790551).jpg]Papaver somniferum leaf1[/url] and [url=https://commons.wikimedia.org/wiki/File:Papaver_somniferum_flower4_(15106250090).jpg]Papaver somniferum flower4[/url] by Harry Rose, and [url=https://commons.wikimedia.org/wiki/File:Poppy_seed_heads_(4824568284).jpg]Poppy seed heads[/url] by Tony Hisgett; and, under [url=https://creativecommons.org/licenses/by/4.0/]CC BY 4.0[/url], [url=https://commons.wikimedia.org/wiki/File:Coca_(Erythroxylum_coca)_en_Meta_(Colombia)_1.jpg]Coca (Erythroxylum coca) en Meta (Colombia) 1[/url] by Danna Guevara
[/list]

[h1]Usage & Terms[/h1]
This item is NOT authorized (strictly forbidden) for any of these conditions:
[list]
[*] posting on Steam, except under the Steam account Cole.
[*] hosting on any download server other than Geb's Plants current workshop download.
[*] hosting on any launcher for distribution other than Geb's Plants current workshop download.
[*] to be packaged in any form other than Geb's Plants current workshop download.
[*] to create derivative works.
[/list]

[h1]PERMISSION IS NOT GRANTED FOR THIS MOD TO BE INCLUDED IN A "SERVER PACK" or "MOD PACK" DO NOT EVEN ASK TO REPACK. NO. NOT ALLOWED.[/h1]
Use a Collection if you want to include this mod on your server for your users.

[h1]Monetization[/h1]
You are hereby given monetization approval under the conditions that you follow the DayZ Server Monetization agreement and have obtained permission from Bohemia. Read more here https://www.bohemia.net/monetization

[h1]Donations[/h1]
We accept donations at https://www.paypal.com/paypalme/packjc. Every dollar counts and we greatly appreciate any contributions!

Copyright © Smoky Mountain Software 2022-2026
