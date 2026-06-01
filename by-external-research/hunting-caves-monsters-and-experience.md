*** UID:0000GY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Hunting, Caves, Monsters, And Experience

Research date: 2026-05-24

Confidence: medium. Official help is strong for modern public cave gates and group-role descriptions. Nexus Atlas pages are useful for area/monster/drop names, but many values are version-sensitive.

Scope: external public data about hunting, experience progression, cave tier gates, group roles, monster/drop vocabulary, and boss/drop etiquette.

## Experience And Level Progression

Observed:

- Official help says levels are gained by gathering experience, with monster hunting described as the quickest and most abundant source. Source: [official Leveling](https://help.nexustk.com/wiki/wiki/62/leveling).
- From level 1 to 99, the status tab's second page shows `Next Level`; the experience bar in the bottom right under Vita/Mana shows total experience earned. Source: [official Leveling](https://help.nexustk.com/wiki/wiki/62/leveling).
- After level 99, official help says characters no longer gain levels. Instead, experience can be exchanged at a Midnight Weaver for additional MGT/GRC/WIL, Vita, or Mana. Source: [official Leveling](https://help.nexustk.com/wiki/wiki/62/leveling).
- Official terminology says `Max` refers to the maximum experience a character can hold and gives the value as `2^32-1` / 4.29 billion. Source: [official Nexus Terminology](https://help.nexustk.com/wiki/wiki/70/nexus-terminology).

Reverse-engineering leads:

- Search for `Next Level`, `Midnight Weaver`, `MGT`, `GRC`, `WIL`, `Max`, and 32-bit experience formatting/limits.
- The explicit `2^32-1` note is a strong lead that experience may be stored/displayed as an unsigned 32-bit quantity somewhere in client/server protocol or UI.

## Group Hunting Roles

Observed:

- Official group-hunting guide says group hunting increases experience earned, especially later in the game, and each path has a group role. Source: [official Hunting in a Group](https://help.nexustk.com/wiki/wiki/84/hunting-in-a-group).
- Warriors are described as high swing-damage and vitality-based attackers with heavy support needs and low mobility. Source: [official Hunting in a Group](https://help.nexustk.com/wiki/wiki/84/hunting-in-a-group).
- Rogues are described as mobile damage dealers using invisibility, back/ambush bonuses, traps, and lower-drain special attacks. Source: [official Hunting in a Group](https://help.nexustk.com/wiki/wiki/84/hunting-in-a-group).
- Mages are described as support/control characters with paralyzes, blinds, armor debuffs, buffs, long-distance mana-based attacks, self mana restoration, damage reduction, and healing. Source: [official Hunting in a Group](https://help.nexustk.com/wiki/wiki/84/hunting-in-a-group).
- Poets are described as support characters with healing, mana restoration, buffs, monster debuffs, debuff removal, and Harden Body survivability. Source: [official Hunting in a Group](https://help.nexustk.com/wiki/wiki/84/hunting-in-a-group).
- The guide recommends checking cave requirements, not always choosing the highest available cave, and often selecting a cave one or two tiers lower for better kill speed. Source: [official Hunting in a Group](https://help.nexustk.com/wiki/wiki/84/hunting-in-a-group).

Reverse-engineering leads:

- Search for group UI, experience share, path roles, buff/debuff states, invisibility/ambush modifiers, and room occupancy/social-rule messages.
- The guide references Law board entry 185 for room-sharing rules. That points to board/law text surfaces rather than low-level mechanics.

## Cave Gate Models

Observed:

- Official Hunt Guide links cave charts for Kingdom, Mythic, Vortex, Ancient Training Grounds, Gogoon, and Event caves. Source: [official Hunt Guide](https://help.nexustk.com/wiki/wiki/10/hunt-guide).
- Kingdom cave chart uses a mix of level gates, stat gates, locations, and coordinates. Examples include rat caves at level 4, fox caves around level 20, haunted houses around level 36, Vale Black Skeletons at level 50, Wilderness Lobsters at 70, ogre/mantis areas in the 60-90+ range, and high-stat Arctic ogre gates. Source: [official Kingdom Cave Chart](https://help.nexustk.com/wiki/wiki/65/kingdom-cave-chart).
- Mythic cave chart is organized by animal and three cave tiers, escalating from Rabbit through Dragon and from level gates into vita/mana stat gates. Source: [official Mythic Cave Chart](https://help.nexustk.com/wiki/wiki/63/mythic-cave-chart).
- Vortex cave chart is organized by tribe and three cave tiers, using vita/mana stat gates for Assassin, Magus, Hunter, Hillmen, Anchorite, Wind, Shadow, Bandit, Dread, Grey Hand, Earth, and Water. Source: [official Vortex Cave Chart](https://help.nexustk.com/wiki/wiki/64/vortex-cave-chart).
- Ancient Training Grounds chart has cave 1 through 10 with level/stat ranges and balance options that set base stats to lower cave maxima. Source: [official Ancient Training Grounds Cave Chart](https://help.nexustk.com/wiki/wiki/158/ancient-training-grounds-cave-chart).
- Gogoon chart lists location families such as Bee, Bird, Crab, Flower, Gargoyle, Imp, Rhino, Turtle, with gates from level 50 through Ee san examples. Source: [official Gogoon Cave Chart](https://help.nexustk.com/wiki/wiki/157/gogoon-cave-chart).
- Event cave chart has split ranges from level 15 through high stat tiers and an `Infinite` top category. Source: [official Event Cave Chart](https://help.nexustk.com/wiki/wiki/41/event-cave-chart).

Reverse-engineering leads:

- Search for cave chart names, location names, and stat-gate formatting using `vita/mana` pairs.
- Cave entry checks may be server-side, but client map names, coordinates, error messages, or UI hints may still exist locally.
- Ancient Training Grounds balancing suggests special stat-normalization status effects or server-side flags that may appear in client status displays.

## Monster, Drop, And Area Vocabulary

Observed:

- Nexus Atlas Wilderness page lists common creatures and drops such as rabbits/rabbit meat, squirrels/acorn/gold acorn, rats/rat meat, deer/antlers, sheep/wool, wolves/wolf meat, boa/snake meat, and Golden Hare/amber. Source: [Nexus Atlas Wilderness](https://www.nexusatlas.com/40atlas/wilderness.php).
- Nexus Atlas map pages routinely list creature experience and item drops per area, which can seed search terms for monster names and drop item names. Source: [Nexus Atlas Wilderness](https://www.nexusatlas.com/40atlas/wilderness.php).
- Nexus Atlas item/resource pages connect monster drops to recipes and quests, e.g. White Amber from many creatures, Yellow Amber in Black Skeleton/Lobster caves, Splendid Tiger Pelt from Mythic Tigers, and key drops from mythic key bosses. Sources: [NeX-Files: Items for Skills](https://www.nexusatlas.com/nexfiles/skills.php), [NeX-Files: Rocks and Minerals](https://www.nexusatlas.com/nexfiles/rocks.php), [NeX-Files: Keys](https://www.nexusatlas.com/nexfiles/keys.php).
- Official making-money guide says ambers are a major early wealth source, while Ginko wood, Wool, Ore, Mythic Keys, boss drops, and ogre weapons have market value. Source: [official Making Money in Nexus](https://help.nexustk.com/wiki/wiki/133/making-money-in-nexus).

Reverse-engineering leads:

- Search for monster/drop strings in DAT/resource tables before assuming code ownership.
- Common economic/drop names are likely high-value packet/resource strings: `Amber`, `White amber`, `Yellow amber`, `Mythic Keys`, `Ginko wood`, `Wool`, `Ore`, `Splendid Tiger Pelt`, `Gold acorn`.

## Bosses, Drops, And Social Etiquette

Observed:

- Official making-money guide notes boss drops and Mythic Keys retain value, competition for bosses is expected, and tradition says the player who found the boss takes the drop. Source: [official Making Money in Nexus](https://help.nexustk.com/wiki/wiki/133/making-money-in-nexus).
- Nexus Atlas Vortex page describes Vortex bosses, Vortex armors, and grouped high-risk training. Source: [Nexus Atlas Vortex](https://www.nexusatlas.com/60atlas/vortex.php).
- Nexus Atlas Vortex hand items associate many item names with boss/source names and cave types. Source: [Nexus Atlas Vortex Hand Armor](https://www.nexusatlas.com/armor/vortexhand.php).

Reverse-engineering leads:

- Search for boss names, item source names, and map/tribe names together.
- Drop ownership messages may overlap item restriction strings such as owner/bonding or pickup failure text.

## Open Questions

- Open-question pass 2026-05-24: official Leveling answers the public progression surface: levels 1-99 use experience, `Next Level` is on the second status tab page, the experience bar is under Vita/Mana, and post-99 experience is exchanged at a Midnight Weaver for MGT/GRC/WIL, Vita, or Mana. Whether sharing, max-experience, and post-99 exchange are client-enforced remains local work.
- Open-question pass 2026-05-24: official Hunt Guide/cave chart pages answer the current public cave-chart families, but not the exact target-era cave gate tables embedded or displayed by the local client.
- Open-question pass 2026-05-24: boss/drop etiquette remains social/public-guide material unless local packets/resources show enforcement. Public pages do not prove local monster/drop tables.

- Which cave gate tables existed in the target client era?
- Are experience sharing, max experience, and post-99 exchange displayed client-side or only server-enforced?
- Does the client contain monster/drop tables, or are those entirely server/map/resource-side?
- Are boss/drop etiquette and law-board references purely social text, or do they map to enforced mechanics?
