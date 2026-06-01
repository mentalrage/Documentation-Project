*** UID:0000HB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# World, Map, Location, And Resource Model

Confidence: medium. Nexus Atlas is extensive and specific, but map pages mix game versions and fan-maintained data. Use as external context and string/search seeds.

Scope: public map/location/resource information that helps identify likely map systems, coordinate handling, shops/caves, resources, NPC destinations, and event/high-level areas.

## Coordinate Model

Observed:

- Official help says the lower-right numbers change as the character moves, representing position in the current area. Moving east/right increases the first number; moving south/down increases the second. Source: [official Finding Places](https://help.nexustk.com/wiki/wiki/136/finding-places).
- Nexus Atlas map and quest pages frequently use coordinate pairs for shops, NPCs, quest objects, and exits. Examples include Kugnae shops on the Kugnae map and seasonal archive walkthrough locations. Sources: [Nexus Atlas Kugnae map](https://www.nexusatlas.com/50atlas/kugnae.php), [March 2016 archive](https://www.nexusatlas.com/archives/mainpage-archive-3-2016.php).

Reverse-engineering leads:

- Search UI code for lower-right coordinate formatting and map-local x/y fields.
- Movement code should align with east increasing x and south increasing y.
- Map transition and NPC lookup data may use coordinate pairs with 0-padded display formatting.

## Map Versioning And Area Indexes

Observed:

- Nexus Atlas maintains versioned map sections. The 6.0 index says KRU announced a major new version in November 2005, that a brief beta preceded 6.3, and that version 6.5 was running by the later map project period. Source: [Nexus Atlas 6.0 maps index](https://www.nexusatlas.com/60atlas/index.php).
- The 6.0 map index lists major clickable-map areas: Buya, Forest Crossroads, Hamgyong Nam-do, Hausson, Islets, Kugnae, Nagnang's Armory, Nagnang, Tangun, Vale, Wilderness, and Woodlands. Source: [Nexus Atlas 6.0 maps index](https://www.nexusatlas.com/60atlas/index.php).
- Nexus Atlas says Wilderness first showed all areas and some secret areas in the 6.0 map set and emphasizes that Wilderness was not only for wood, wool, or ore. Source: [Nexus Atlas 6.0 maps index](https://www.nexusatlas.com/60atlas/index.php).
- A May 2006 archive entry says the Woodlands map release concluded a map project that began the week Vortex was released in June 2003, with 100 percent of the kingdoms mapped for Nexus Atlas use at that point. Source: [May 2006 archive](https://www.nexusatlas.com/archives/mainpage-archive-5-2006.php).

Reverse-engineering leads:

- Search for area names and version-era terms: `Kugnae`, `Buya`, `Nagnang`, `Tangun`, `Wilderness`, `Woodlands`, `Vortex`, `Hamgyong`, `Hausson`, `Islets`, `Vale`, `Dae Shore`, `Sanhae`, `Arctic`.
- Versioned map assets may reveal why old and new graphics/resource sets coexist in the client.

## Area Graph, Shops, And Caves

Observed:

- Nexus Atlas pages expose map adjacency using north/south/east/west links and return/zoom-out links. Example: Vortex returns to Nagnang and has only a north link back to Nagnang. Source: [Nexus Atlas Vortex](https://www.nexusatlas.com/60atlas/vortex.php).
- The 6.0 map/cave listing summarizes shops and caves by area. Examples: Buya has shops such as Bagai Shop, Library, Chi Seams, Buya Salon, and Dok Smith; Kugnae has shops including Baek Shop, Kugnae Library, Merchants' Subpath Area, Sunset Weaver, and Suni Butcher; Nagnang has taverns of elements plus butcher, salon, tailors, weavers, and message shop. Source: [Nexus Atlas 6.0 map/cave listing](https://www.nexusatlas.com/60atlas/list.php).
- The same listing shows cave groupings such as Kugnae Fox/Haunted House/Rabbit/Rat/Snake/Spider caves, Buya Fox/Haunted House/Library/Rabbit/Rat/Sute caves, Wilderness Iron Labs/Lobsters/Rat Cave, and Woodlands Dog/Frozen Tundra/Lobsters/Rabbits/Raheem Desert/Snakes. Source: [Nexus Atlas 6.0 map/cave listing](https://www.nexusatlas.com/60atlas/list.php).

Reverse-engineering leads:

- Map data may be organized as area IDs, exits, shop/NPC room IDs, cave/dungeon entries, and return destinations.
- Shop names and NPC names are useful string anchors for resource or packet handlers.

## Resource And Creature Context

Observed:

- Nexus Atlas Wilderness page describes Wilderness as a resource-heavy area with sheep for wool, ore on the surface, dense tree groves for woodcutting, and five subpaths with homes there. Source: [Nexus Atlas Wilderness](https://www.nexusatlas.com/40atlas/wilderness.php).
- The Wilderness page lists common creatures and drops such as rabbit/rabbit meat, squirrel/acorn/gold acorn, rat/rat meat, deer/antler, sheep/wool, wolf/wolf meat, boa/snake meat, and Golden Hare/amber. Source: [Nexus Atlas Wilderness](https://www.nexusatlas.com/40atlas/wilderness.php).
- Crafting documentation depends on resource flows: farming, fishing, mining, woodcutting, smelting, weaving, gemcutting, carpentry, jewelering, smithing, tailoring, food preparation, chef, alchemy, and scribing. Source: [Nexus Atlas crafting legend marks](https://www.nexusatlas.com/legends/crafting.php).

Reverse-engineering leads:

- Search for resource item strings: `Wool`, `Ore`, `Ginko wood`, `Silver tree branch`, `Metal`, `Fine metal`, `Cloth`, `Fine cloth`, `Amber`, `Rabbit meat`, `Acorn`, `Gold acorn`.
- Gathering/refining/manufacturing may use shared progress and skill-rank UI, but the actual collection rules may be server-side.

## High-Level And Event Area Example: Vortex

Observed:

- Nexus Atlas describes Vortex as a high-risk training area associated with Nagnang, twelve rooms, Vortex bosses, Vortex armors, and the Sa san/Seyn spell quest path. Source: [Nexus Atlas Vortex](https://www.nexusatlas.com/60atlas/vortex.php).
- The Vortex page records a long spoken-command and item-gate sequence across Baekho, Ju Jak, Hyun Moo, Chung Ryong, and Seyn. Source: [Nexus Atlas Vortex](https://www.nexusatlas.com/60atlas/vortex.php).

Reverse-engineering leads:

- Search for `Vortex`, `Seyn`, `Chizao`, `Captain's Tent`, `Baekho essence`, `Ju jak`, `Hyun moo`, `Chung ryong`, `Four guardians`, and Vortex armor names.
- The client may only display these strings and receive server state; still useful for resource and UI lookup.

## Open Questions

- Open-question pass 2026-05-24: current official Kingdoms Governments answers public geography names for current help-era documentation: Koguryo, Buya, Nagnang, Wilderness, and surrounding lands such as Gogoon Island, Han Empire, Ilbon Empire, Jinhan Chiefdom, Kaya, Kinung, Mongolic Empire, Paekjae, Shilla, Sonhi, and Tangun.
- Open-question pass 2026-05-24: official Verbal Commands confirms travel words for Kugnae, Buya, Nagnang, and Tangun. This is public NPC/travel vocabulary, not proof of local map asset storage.
- Open-question pass 2026-05-24: map packaging and event-map retention remain local DAT/resource questions. Public Nexus Atlas pages are map metadata leads, not resource-container proof.

- Are map assets bundled as DAT entries, loose files, or generated tile sheets in the target client?
- Does the client contain shop/cave/NPC names locally, or are these mostly server-fed labels?
- Which map version corresponds to the target binary's graphics and map IDs?
- Are event maps retained in current DATs after an event ends, or patched in/out?
