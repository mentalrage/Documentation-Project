*** UID:0000H2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Map Atlas, Coordinate, Area, And Travel Catalog

Research date: 2026-05-24

Scope: public map, coordinate, cave, shop, city, travel, and area-list information from Nexus Atlas and official help, used as reverse-engineering search vocabulary for map resources, warp tables, NPC/shop entries, monster placement, and gate checks.

Confidence: medium. Nexus Atlas map pages are detailed and internally structured, but fan-maintained and version-tagged. Official help cave charts are stronger for current public cave gate and coordinate data.

## Source Families

This batch uses three kinds of map sources:

- Nexus Atlas clickable maps, especially the Version 6.0 index and city/area pages.
- Nexus Atlas map/cave listing pages, which summarize shops and caves by area.
- Official help cave charts, which provide level/stat gates and coordinates for cave entry families.

These sources should be treated as external vocabulary and structure leads. They do not prove how the target binary stores maps, warps, NPCs, or monsters.

## Nexus Atlas Map Page Schema

Nexus Atlas area pages have a repeatable shape:

- version breadcrumb, such as `6.0 | Atlas | Clickable Maps | Buya`;
- area title and prose description;
- links to older/newer map versions;
- cardinal exits such as North, South, East, West;
- `Zoom Out` or world-map link;
- `Information` block with nearest kingdom, existence/version, shop count, cave/room count;
- places of interest, caves, shops/halls, clans, guilds, inns, or other area-specific lists;
- coordinate pairs for many entries;
- monster table with creature name, experience, item drop, and sometimes rare drop;
- event/quest notes embedded in the map page.

For reverse engineering, this schema suggests distinct data concepts:

- map identity and display name;
- map version or era;
- cardinal exit/warp graph;
- clickable hotspots or coordinate doors;
- NPC/shop/hall/inn labels;
- cave entrances and gate checks;
- monster spawn tables;
- resource/drop tables;
- special scripts attached to an area.

## Coordinate Formats

Public sources use several coordinate formats:

- comma form: `(0125, 0144)`;
- slash form: `074/103`;
- official cave-chart form: `16/78`;
- zero-padded and non-zero-padded variants.

The same world vocabulary can appear with different formatting across sources. Search both slash and comma forms when hunting local strings or data. For example, Nagnang Arena appears as `074/103` in Nexus Atlas Carnage pages and Nagnang places of interest, while official help may use slash-only coordinate style.

Do not assume a coordinate string proves a local map coordinate table. Many coordinate labels may exist only in web/help text or server-generated board posts.

## 6.0 Clickable Map Areas

The Nexus Atlas 6.0 map index lists these clickable areas:

- Buya: growing city, with Tutor hall and hair salon additions.
- Forest Crossroads: Mantis Haven.
- Hamgyong Nam-do: Ogre Land, with later areas and at least one quest-gated area.
- Hausson: Pirate Island.
- Islets: quiet place, with abandoned Yu Ryang Village.
- Kugnae: updated capital city maps.
- Nagnag's Armory: armor-smith map group.
- Nagnang: forsaken land.
- Tangun: tutorial area north of Kugnae.
- Vale: wild area with PVP danger, shrines, warps, and Scribe's Mountain.
- Wilderness: resource/social region with hidden areas.
- Woodlands: poisoned hunting grounds with mine field, sheep field, and wheat gathering.

The index records "Date Added" values from 2006-2007. Those dates are Nexus Atlas publication dates, not necessarily in-game release dates.

## 6.0 Map/Cave Listing

The Nexus Atlas 6.0 listing summarizes areas by shops and caves:

- Buya: 12 shops and 6 caves, including Fox Cave, Haunted House, Library Caverns, Rabbit Cave, Rat Cave, and Sute Cave.
- Hausson: 5 shops and no listed caves.
- Kugnae: 14 shops and 6 caves, including Fox, Haunted House, Rabbit, Rat, Snake, and Spider caves.
- Nagnang: 11 shops and 2 caves, including Leviathan Area and Blight Map.
- Tangun: 1 shop and no listed caves.
- Vale: no shops and 3 caves, including Skeleton, Scribe's Mountain, and Polar Bear.
- Wilderness: 5 listed shop/subpath/resource areas and 3 caves, including Iron Labs, Lobsters, and Rat Cave.
- Woodlands: no shops and 6 caves, including Dog, Frozen Tundra, Lobsters, Rabbits, Raheem Desert, and Snakes.

This page is useful as a compact checklist of shop/cave strings before doing deeper map-page extraction.

## City Examples

### Buya

Nexus Atlas describes Buya as a royal city ruled by Princess Lashan, with exits toward The Vale, Wilderness, Islets/Forest Crossroads, and world-map access. The page lists caves, shops/halls, clans, guilds, inns, and monsters.

High-value strings and locations include:

- caves: Buya Fox Cave, Haunted House, Library Caverns, Rabbit Cave, Rat Cave, Sute's Cave;
- shops/halls: Bagai Shop, Blossom Seams, Budol Goh, Buya Library, Buya Salon, Dok Smith, Ogi Butcher, Paryu Message, Peach Chapel, Pitch Shop;
- clans: Dharma, Elendhirin, Heavens, Lost Kingdom, Phoenix, Sansin;
- guilds: Buya Mage Guild, Poet Guild, Rogue Guild, Warrior Guild;
- inns: Pepper Tavern, Spring Tavern, Yunsil Tavern.

### Kugnae / Koguryo

Nexus Atlas describes Kugnae as the capital city of Koguryo and says it has existed since beta. Its exits include Wilderness, Dae Shore, and Nagnang. The page lists many places and coordinates, including Jail, Koguryo Gathering, Kugnae Palace, marketplace, tower arena, path guilds, clan halls, and subpath areas.

High-value strings include:

- `Alt Kugnae`;
- `Jail`;
- `Koguryo Gathering`;
- `Kugnae Palace`;
- `Tower Arena`;
- `Red Cap Messenger`;
- `Diviners' Subpath Area`;
- `Merchant's Subpath Area`;
- `Tutor Ironheart`.

### Nagnang

Nexus Atlas describes Nagnang as a rural kingdom under Prince Kija with Blight as a lurking rival force. It gives exits to Southern Koguryo, Vortex, and Woodlands. The page lists places of interest, caves, shops, guilds, and clan gardens.

High-value strings include:

- `Dark Forest`;
- `East Gate`;
- `Gauntlet`;
- `Grove of Shadows`;
- `Kija's Grove`;
- `Leviathan`;
- `Midnight Weaver`;
- `Mountain Shaman`;
- `Nagnang Arena`;
- `Nagnang Palace`;
- `Oblivion`;
- `Woodlands Entrance`;
- `Tavern of Fire`, `Tavern of Metal`, `Tavern of Water`, `Tavern of Wind`, `Tavern of Wood`;
- clan gardens for Alizarin, Forsaken, K'urimja, Pegasus, Silla, and Viper.

## Wilderness And Resource Model

The 4.0 Wilderness page describes a resource-heavy region:

- many resources and player homes;
- five subpaths, four with public areas;
- sheep fields for wool;
- ore mining from the surface;
- four dense groves for woodcutting;
- north exit to Buya and south exit to Kugnae;
- monsters including rabbit, squirrel, rat, deer, sheep, black buck, horse, wolf, blood wolf, boa, and golden hare;
- drops including rabbit meat, acorn, gold acorn, rat meat, antler, wool, wolf meat, snake meat, and amber.

This page is useful for resource-gathering and low-level monster/drop strings. If local assets include map names but not script logic, these names can still identify map resource packs.

## Vortex Special Area

The 6.0 Vortex page is unusually dense. It describes:

- Nagnang as nearest kingdom;
- existence date July 2004;
- 12 rooms;
- Chizao/Vortex lore;
- boss drops for Vortex Armors;
- Seyn in the center after Sa san introduction;
- a 20-step Sa san Seyn spell flow using shrine keywords and item requirements;
- monsters and drops.

The same source says only the first three creatures listed for each cave appear in the first room, while other creatures can appear in all other rooms. That suggests room-indexed spawn variations.

Important strings:

- `Vortex`;
- `Seyn`;
- `Chizao`;
- `Captain's Tent`;
- `Baekho`, `Ju jak`, `Hyun moo`, `Chung ryong`;
- `Baekho essence`;
- `Four guardians`;
- `Vortex Armors`;
- `Sa san`;
- `Metal`, `Hot coal`, `Moon wine`, `Golden rabbit`.

## Official Cave Chart Model

Official help cave charts give current entry gates in a more mechanical form:

- Kingdom Cave Chart: cave name, level/stat gate, location, coordinates.
- Mythic Cave Chart: animal-themed caves with Cave 1/2/3 gates.
- Vortex Cave Chart: tribe names with Cave 1/2/3 vita/mana gates.
- Event Cave Chart: Cave 1 through Cave 11 plus split bands, from level-gated entries to very high stat bands and Infinite.

Official chart examples:

- Kingdom caves include Buya Rat Cave, Kugnae Rat Cave, Wilderness Rat, Buya Rabbit, Kugnae Rabbit Cave, Woodlands Snake, Green Squirrels, Iron Labyrinth, Sute Cave, Vale Black Skeletons, and Arctic Ogres.
- Mythic animals include Rabbit, Monkey, Dog, Rooster, Rat, Horse, Ox, Pig, Snake, Sheep, Tiger, and Dragon.
- Vortex tribes include Assassin, Magus, Hunter, Hillmen, Anchorite, Wind, Shadow, Bandit, Dread, Grey Hand, Earth, and Water.
- Event Cave Chart uses cave and split labels such as `Cave 4/5 Split`, `Cave 9/10 Split`, and `Infinite`.

These sources are strong leads for stat-gate constants and denial messages.

## Travel And Warp Vocabulary

Official verbal commands document travel keywords to NPCs:

- `Kugnae`;
- `Buya`;
- `Nagnang`;
- `Tangun`.

Map pages document physical exits and world-map graph links. A robust reverse-engineering search should treat "travel" as a combination of:

- spoken NPC destinations;
- exit warps on map edges;
- clickable map hotspots;
- ring/summon spell destinations;
- event/quest teleports;
- board/help coordinates.

## Reverse-Engineering Leads

Search locally for:

- area names: `Buya`, `Kugnae`, `Koguryo`, `Nagnang`, `Tangun`, `Vale`, `Wilderness`, `Woodlands`, `Vortex`, `Hausson`, `Islets`, `Hamgyong`, `Forest Crossroads`;
- map graph terms: `North`, `South`, `East`, `West`, `Zoom Out`, `World Map`, `Nearest Kingdom`;
- place names: `Nagnang Arena`, `Kugnae Palace`, `Jail`, `Tower Arena`, `Scribe's Mountain`, `Iron Labyrinth`, `Leviathan`, `Blight Map`;
- shop words: `Smith`, `Butcher`, `Seams`, `Salon`, `Tavern`, `Message`, `Chapel`, `Library`, `Weaver`, `Goh`;
- gate words: `Level`, `Cave`, `Split`, `Infinite`, `Vortex`, `Mythic`, `Kingdom`;
- coordinate delimiters: `/`, `,`, zero-padded coordinate strings around known public examples.

Potential local data structures:

- map metadata table;
- map ID to display-name table;
- warp-edge/click hotspot table;
- NPC/shop spawn table;
- cave gate/stat table;
- monster spawn and drop tables;
- area resource pack names;
- server-fed map labels with client-side rendering only.

## Sources

- [Nexus Atlas 6.0 clickable map index](https://www.nexusatlas.com/60atlas/index.php)
- [Nexus Atlas 6.0 map/cave listing](https://www.nexusatlas.com/60atlas/list.php)
- [Nexus Atlas 4.0 Wilderness map](https://www.nexusatlas.com/40atlas/wilderness.php)
- [Nexus Atlas 6.0 Vortex map](https://www.nexusatlas.com/60atlas/vortex.php)
- [Nexus Atlas 6.0 Buya map](https://www.nexusatlas.com/60atlas/buya.php)
- [Nexus Atlas 6.0 Kugnae/Koguryo map](https://www.nexusatlas.com/60atlas/kugnae.php)
- [Nexus Atlas 6.0 Nagnang map](https://www.nexusatlas.com/60atlas/nagnang.php)
- [Official NexusTK Kingdom Cave Chart](https://help.nexustk.com/wiki/wiki/65/kingdom-cave-chart)
- [Official NexusTK Mythic Cave Chart](https://help.nexustk.com/wiki/wiki/63/mythic-cave-chart)
- [Official NexusTK Vortex Cave Chart](https://help.nexustk.com/wiki/wiki/64/vortex-cave-chart)
- [Official NexusTK Event Cave Chart](https://help.nexustk.com/wiki/wiki/41/event-cave-chart)
- [Official NexusTK Verbal Commands](https://help.nexustk.com/wiki/wiki/40/verbal-commands)

## Open Questions

- Open-question pass 2026-05-24: current official Kingdoms Governments names the livable kingdom set and surrounding lands, while Nexus Atlas 6.0 maps provide public map/NPC/shop/cave metadata. These answer public vocabulary, not local resource ownership.
- Open-question pass 2026-05-24: official Verbal Commands confirms travel words for Kugnae, Buya, Nagnang, and Tangun. That gives NPC/travel string leads but not packet/map-transition structure.
- Open-question pass 2026-05-24: map names, coordinate labels, spawn/drop tables, and event-map retention remain local resource/protocol questions. Public map pages can guide searches but cannot prove what the client stores.

- Are map names embedded in client resource files, server packets, or both?
- Does the target client contain coordinate labels or only render coordinates supplied by the server/UI?
- Are spawn/drop tables present locally for offline display, or are all monster/drop facts server-side?
- Which Nexus Atlas version family best matches the target binary's map resources?
- Are event maps retained in local data after events end?
