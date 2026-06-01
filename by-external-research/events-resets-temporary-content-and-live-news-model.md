*** UID:0000GT | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Events, Resets, Temporary Content, And Live News Model

Research date: 2026-05-24

Scope: online public information about NexusTK event caves, server reset posts, temporary event maps/items/NPCs, roleplay event reporting, event legend marks, and live news/status surfaces. This is external research only and should be treated as dated context until confirmed locally.

Confidence: medium. Official Event Cave Chart is strong for current public gate labels. Nexus Atlas front page and archives are valuable for event vocabulary and dated examples, but archive reports often mix official reposts, reporter interpretation, and temporary live content.

## Event Surface Inventory

Public sources show events through several surfaces:

- official cave charts and event cave level/stat bands;
- Dream Weaver server reset posts;
- Community, Chronicles of the Winds, Whispering Winds, Event Winners, and other board posts;
- temporary maps, rooms, portals, and NPCs;
- temporary items, talismans, disguises, recipes, and rewards;
- event legend marks and participation counters;
- hosted community games and subpath festivals;
- live front-page server status buckets such as Nation, Carnage, Event, and House.

Reverse-engineering impact: event support is likely a blend of static client resources, server-side scripts, board/news text, map data, item/spell records, and temporary state. Do not assume one event subsystem owns all of it.

## Official Event Cave Tiers

Official Event Cave Chart lists event cave bands from low-level cave entries through high-stat split bands and an `Infinite` top category.

Observed labels and gates:

| Label | Public gate |
| --- | --- |
| Cave 1 | Level 15 - Level 38 |
| Cave 1/2 Split | Level 39 - Level 40 |
| Cave 2 | Level 41 - Level 66 |
| Cave 2/3 Split | Level 67 - Level 68 |
| Cave 3 | Level 69 - Level 94 |
| Cave 3/4 Split | Level 95 - Level 98 |
| Cave 4 | Level 99 - 19,999/9,999 |
| Cave 4/5 Split | 20k/10k - 29,999/14,999 |
| Cave 5 | 30k/15k - 64,999/32,499 |
| Cave 5/6 Split | 65k/32.5k - 79,999/39,999 |
| Cave 6 | 80k/40k - 159,999/79,999 |
| Cave 6/7 Split | 170k/85k - 199,999/99,999 |
| Cave 7 | 200k/100k - 419,999/209,999 |
| Cave 7/8 Split | 420k/210k - 499,999/249,999 |
| Cave 8 | 500k/250k - 899,999/449,999 |
| Cave 8/9 Split | 900k/450k - 999,999/499,999 |
| Cave 9 | 1m/500k - 2,299,999/1,149,999 |
| Cave 9/10 Split | 1.9m/950k - 2,299,999/1,299,999 |
| Cave 10 | 2.3m/1.3m |
| Cave 10/11 Split | 3m/1.8m |
| Cave 11 | Infinite |

Reverse-engineering leads:

- Search for `Event Cave`, `Cave 1/2 Split`, `Cave 10/11 Split`, `Infinite`, and stat-band constants.
- Split labels imply event entry or cave-selection UI with boundary cases.
- Gate logic is likely server-owned, but client resources may contain labels, map names, or denial messages.

## Server Reset Board Pattern

Nexus Atlas archives often preserve Dream Weaver board posts with a structure like board title, sender, date, subject, and update notes. Reset posts can introduce or remove features, close events, move NPCs, repair maps, adjust channels, or add temporary caves.

Examples from May/August 2020:

- Dream Weaver reset notes introduced ministry and Nagnang Army chat routes after Frozen Fortress/Nabihye content ended.
- A later reset removed an old Mentor karma-reward confusion, pointed players toward a Faerie Light method, and included subpath-guide updates.
- August 2020 reset notes included clan/subpath updates, chat channel fixes, a Shaman Charm relocation, a Merchant hall entrance move, and Barbarian event-area updates.

Reverse-engineering leads:

- Search for `Dream Weaver`, `Server Reset`, `FROM: NexusTK`, `SUBJECT: Server Reset`, `reset`, and dated version/update strings.
- Reset posts are strong clues for exact feature introduction/removal windows.
- Board text may be server/web content only, but strings copied into the client can reveal update dialogs, URL links, or board templates.

## Temporary Maps And Event Area Expansion

Nexus Atlas May 2020 documents a Sonhi Hideout event area around Kugnae underground/sewer spaces. The report describes new rooms, level-banded hideout rooms, non-spawning rooms, ambush rooms, an event stockade, event NPCs, and normal death behavior.

Named examples:

- Underground Connection;
- Sewers Hollow;
- Sonhi Hideout Entrance;
- Sonhi Hideout Station;
- Sonhi Hideout Base;
- Sonhi Hideout Pit;
- Old Sewers Corridors;
- Deeper Sonhi Hideout;
- Sonhi Hideout Storage;
- Sonhi Command Post;
- Sonhi Hideout Stockade.

Reverse-engineering leads:

- Search for temporary room names and map labels, not just permanent city names.
- Event maps can reuse existing cave entrances, such as Kugnae Rat Cave, while adding new temporary branches.
- Check whether local map/resource packs retain old event maps after events close.

## Temporary Items, Disguises, Recipes, And Branching Support

The Sonhi Hideout event walkthrough is useful because it exposes several event mechanics:

- NPC dialogue to obtain a disguise and pass;
- equipment restrictions for entering a hideout;
- temporary travel items such as hideout talismans;
- boss/key drops;
- role choice between defending Koguryo or supplying Sonhi insurgents;
- Creation-system recipes for disabling explosives or making weapon crates;
- side-dependent turn-in phrases and legend marks;
- quest reset phrase to change sides;
- level-based subaccessory rewards.

High-value strings:

- `KaMing pass`
- `Sonhi helm`
- `Sonhi armor`
- `Hideout talisman`
- `Hideout key`
- `Disabled explosives`
- `Weapon crate`
- `Neutralizing reagent`
- `Difuser box`
- `Stealth Explosives`
- `Shatter bombs`
- `I changed my mind`

Reverse-engineering leads:

- Event scripts can bind together item restrictions, NPC speech, Creation recipes, boss drops, map entry gates, and legend marks.
- Temporary event items may use normal inventory/equipment flags, but server scripts determine when they are valid.
- Branching event choices are likely server-side quest state with client-visible item/legend/result text.

## Event Legend Marks

Nexus Atlas Event Legend Marks groups event marks into anniversaries, arena-based event counters, and historical hosted events. The page says event marks can represent participation, completion, kills, exploration, or arena wins.

Observed event-mark families include:

- anniversary login marks;
- Bloodlust, Carnage, Elixir War, and Fox Hunt participation/win counters;
- invasion and war events;
- Lost Mines, Pirate Invasion, Sonhi, God War, Nagnang War, Blight, Wind Temple, and rebuilding events;
- marks tied to completed tasks, entered areas, donations/materials, and event-specific rewards.

Reverse-engineering leads:

- Event legend marks may have dynamic counts, dates, item notes, or participant role text.
- Search for `Anniversary`, `Bloodlust Participation`, `Carnage Wins`, `Elixir Wars Wins`, `Fox Hunt Wins`, `Lost Mines`, `Pirate Invasion`, `Sonhi`, `God War`, `Rebuilding`.
- Arena counters overlap with Carnage/PVP systems; seasonal/event quest marks overlap with quest and legend systems.

## Seasonal And Community Festival Events

The current Nexus Atlas front page fetched on 2026-05-24 showed recent community reporting for Beltane and a SanSin Primogen transition. It also showed live server status buckets for Nation, Carnage, Event, and House.

Beltane reporting describes:

- a scheduled multi-day festival;
- opening and closing rituals;
- games hosted by subpaths;
- board/news scheduling;
- prizes/tokens/favors;
- subpath representatives and community leaders;
- screenshot submission instructions.

Reverse-engineering leads:

- Some events are almost entirely social/board driven while still using in-game spaces, items, summons, dice rolls, or host tools.
- Search terms should include festival and game names as well as system terms: `Beltane`, `Sacred Grove`, `Mystic Garden`, `Snake Attack`, `Battle on the Bridge`, `Druid Bingo`, `Midnight Lotus`, `Nature's Bounty`, `The Ten`, `Deadliest Poison`, `Kendo Royale`.
- Front-page live buckets are web signals; do not assume `Nation`, `Carnage`, `Event`, and `House` are client protocol labels without local evidence.

## Invasion And Ambush Event Pattern

Nexus Atlas May 2020 Stygian/Sonhi reporting shows another event pattern:

- roleplay warning through boards;
- named NPC and faction conflict;
- map ambushes around cities and wilderness;
- temporary portal/warp changes;
- hidden or abducted NPCs;
- attack waves and boss/cultist enemies;
- follow-up reset posts and walkthroughs.

Search leads:

- `Stygian Order`
- `HaggardWitch`
- `KaKhan`
- `KaMing`
- `Sonhi`
- `Stygian Archer`
- `Stygian Assassin`
- `Archmage`
- `Frozen Fortress`
- `Nabihye`
- `Glacial Forest`
- `Whispering Winds`
- `Chronicles of the Winds`

Reverse-engineering leads:

- Events may alter live NPC availability, portal behavior, enemy spawns, map entry, and city safety.
- These are almost certainly server-side in behavior, but client-local resources may contain sprites, maps, item names, and status strings.

## Current News And Screenshot Submission Signals

The Nexus Atlas front page includes recent headlines, server status, article text, screenshots, and contact/reporting instructions. Current screenshot instructions request full-size BMP or PNG images and mention in-game capture keys, while also asking contributors to hide names/chat and allowing editors to crop UI panels.

Reverse-engineering leads:

- News sites provide current vocabulary for social roles, but current page text is not proof of target-era behavior.
- Screenshot instructions can cross-check current/legacy screenshot key support.
- Reporter notes identify useful fields to preserve when mining archives: author, date/time, subject, board title, screenshots, location names, NPC names, and quoted command phrases.

## Likely Client/Server Ownership

Likely client-owned or client-visible:

- maps, tiles, sprites, item icons, equipment visuals, and sounds shipped for events;
- screenshot capture;
- generic board/mail/news display windows;
- inventory/equipment restriction feedback;
- Creation-system UI and item selection;
- legend/profile rendering;
- map names, room labels, and teleport/loading behavior;
- event cave entry prompts or rejection messages.

Likely server-owned:

- event start/end state;
- temporary NPC and enemy spawns;
- cave gate validation;
- event quest state and branch choices;
- reward and legend mark grants;
- temporary portal/warp behavior;
- event-specific recipes and item validity, unless proven client-local;
- live status counts and board/news content.

Shared protocol candidates:

- map transfer to event rooms;
- NPC speech and response options;
- item/equipment validation;
- Creation submit/result;
- quest/legend update;
- event cave entry request/denial;
- temporary buff/item/spell grants;
- board/news post retrieval.

## String And Data Search Leads

Search locally for:

- reset/news: `Dream Weaver`, `Server Reset`, `Chronicles of the Winds`, `Whispering Winds`, `Event Winners`, `Recent Headlines`;
- cave labels: `Event Cave`, `Cave 1/2 Split`, `Cave 9/10 Split`, `Cave 11`, `Infinite`;
- Sonhi event: `Sonhi Hideout`, `KaMing`, `KaKhan`, `HaggardWitch`, `Disabled explosives`, `Weapon crate`, `Hideout talisman`, `Hideout key`;
- Stygian event: `Stygian Order`, `Frozen Fortress`, `Nabihye`, `Glacial Forest`, `Stygian Archer`, `Stygian Assassin`, `Archmage`;
- event marks: `Anniversary`, `Bloodlust Participation`, `Carnage Wins`, `Pirate Invasion`, `Lost Mines`, `God War`, `Rebuilding`;
- festivals: `Beltane`, `Sacred Grove`, `Mystic Garden`, `Druid Bingo`, `Nature's Bounty`, `Deadliest Poison`, `Kendo Royale`;
- live buckets: `Nation`, `Carnage`, `Event`, `House`.

## Open Questions

- Open-question pass 2026-05-24: official Event Cave Chart and Nexus Atlas archives answer public event vocabulary and level-band models, but do not prove what temporary maps/items remain in local client resources.
- Open-question pass 2026-05-24: archive reset posts can identify event names, NPCs, temporary portals, recipes, disguises, and cave labels. Whether labels are local strings, server-sent text, or board/help-only terminology remains local/protocol work.
- Open-question pass 2026-05-24: the best public method for target-era filtering is to tie event names to dated archive months after the local client version is pinned.

- Are temporary event maps retained in local DAT/resource files after event closure?
- Does the target client contain event recipe data, or does the server validate Creation submissions?
- Are event cave split labels local strings, server-sent labels, or board/help-only terminology?
- How are live event status and temporary portal availability represented in protocol state?
- Which archive event names correspond to target-era resources versus later live-service additions?

## Sources

- [Official help: Event Cave Chart](https://help.nexustk.com/wiki/wiki/41/event-cave-chart)
- [Official help: Basic Keys](https://help.nexustk.com/wiki/wiki/7/basic-keys)
- [Nexus Atlas main page](https://www.nexusatlas.com/)
- [Nexus Atlas: Event legend marks](https://www.nexusatlas.com/legends/events.php)
- [Nexus Atlas March 2020 archive](https://www.nexusatlas.com/archives/mainpage-archive-3-2020.php)
- [Nexus Atlas May 2020 archive](https://www.nexusatlas.com/archives/mainpage-archive-5-2020.php)
- [Nexus Atlas August 2020 archive](https://www.nexusatlas.com/archives/mainpage-archive-8-2020.php)
- [Nexus Atlas May 2004 archive](https://www.nexusatlas.com/archives/mainpage-archive-5-2004.php)
