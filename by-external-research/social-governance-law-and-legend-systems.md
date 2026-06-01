*** UID:0000H6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Social Governance, Law, And Legend Systems

Research date: 2026-05-24

Confidence: medium. Official help and Nexus Atlas agree on many social-role names, but authority/status mechanics may be server-side. Use these as vocabulary and UI leads.

Scope: public documentation about kingdoms, clans, roles/jobs, law/crimes, legend marks, subpath services, and community governance.

## Kingdoms And Political Geography

Observed:

- Official help says there are three livable kingdoms citizens can choose to live in, plus the neutral Wilderness. Source: [official Kingdoms Governments](https://help.nexustk.com/wiki/wiki/18/kingdoms-governments).
- Official help names the livable kingdoms as Koguryo, Buya, and Nagnang. Source: [official Kingdoms Governments](https://help.nexustk.com/wiki/wiki/18/kingdoms-governments).
- Official help also lists surrounding lands/polities such as Gogoon Island, Han Empire, Ilbon Empire, Jinhan Chiefdom, Kaya Kingdom, Kinung Town, Mongolic Empire, Paekjae Kingdom, Shilla Kingdom, Sonhi Tribes, and Tangun Town. Source: [official Kingdoms Governments](https://help.nexustk.com/wiki/wiki/18/kingdoms-governments).
- Nexus Atlas describes central story conflicts among Koguryo, Buya, and Nagnang under King M'hul, Queen Lasahn, and King ChaeRi. Source: [Nexus Atlas: What is Nexus?](https://www.nexusatlas.com/what.php).

Reverse-engineering leads:

- Search kingdom names and ruler names in resource strings, map labels, profile/status fields, guild halls, and board categories.
- `Nation`, `House`, `Event`, and `Carnage` categories appear on the Nexus Atlas front page's live server-status panel and may correspond to server-list/grouping terminology. Source: [Nexus Atlas main page](https://www.nexusatlas.com/).

## Clans, Subpaths, And Public Roles

Observed:

- Official help lists clans by kingdom. Koguryo clans include Bear, Destiny, Enigma, Oceana, Sun Moon Sect, and Tiger. Buya clans include Dharma, Heavens, Lost Kingdom, Phoenix, and SanSin. Nagnang clans include Alizarin, Covenant, K'urimja, Pegasus, Silla, The Forsaken, and Viper. Source: [official Clans of the Kingdoms](https://help.nexustk.com/wiki/wiki/16/clans-of-the-kingdoms).
- Official community page also links clans, armies, judges, tutors, players, base paths, and subpaths. Source: [official community page](https://www.nexustk.com/community.html).
- Nexus Atlas job legend marks include Carnage Assistant, Carnage Host, Elder of Subpath, Founder of Subpath, Fox Hunt Host, Guide of Subpath, Judge, Primogen, Tutor, Being Mentored By, Justice Matter, and Tutored Students. Source: [Nexus Atlas Jobs](https://www.nexusatlas.com/legends/jobs.php).
- Official terminology defines Archons as special characters used to oversee/run NexusTK, with powers such as walking through walls, fast movement, spawning monsters, and changing map attributes. Source: [official Nexus Terminology](https://help.nexustk.com/wiki/wiki/70/nexus-terminology).
- Official terminology defines Judges as trained arbiters of NexusTK law, Elder as subpath leaders, and Gods as developer-controlled community interaction characters or totem spirits in roleplay. Source: [official Nexus Terminology](https://help.nexustk.com/wiki/wiki/70/nexus-terminology).

Reverse-engineering leads:

- Search social role labels: `Archon`, `Judge`, `God`, `Primogen`, `Elder`, `Guide`, `Tutor`, `Carnage Host`, `Fox Hunt Host`, `Minister`, `General`, `Chancellor`.
- Role privileges may appear only as server-sent capability flags, but client UI could expose host tools, board management, wall-walk/debug-like behavior, or special map/object commands for Archons/Gods.

## Subpath Services And Roleplay Markers

Observed:

- Official help lists many subpath services/quests by path, including Barbarian Blood Oath, Survival Challenges, Wilderness Training, Chongun tribunals/nobility/war college, Diviner readings, Do bladecraft/weapon/peace work, Druid elements/herbalism/animal devotion, Geomancer elemental/Ba-Gua content, Merchant economics/trading/treasure hunting, Monk vows/forgiveness/eightfold/past lives, Muse revenge/instruments/theatre/college, Ranger taming/scouting/arrow cresting, Shaman weddings/totem/rituals/medicine wheel/alignment, and Spy employment. Source: [official Subpath Quests & Services](https://help.nexustk.com/wiki/wiki/87/subpath-quests-services).
- The same page notes its information came directly from Subpaths Board and elders/guides. Source: [official Subpath Quests & Services](https://help.nexustk.com/wiki/wiki/87/subpath-quests-services).
- Nexus Atlas subpath legend marks include path-specific friend/enemy/training/quest marks and notes that red marks can make a character an enemy of a subpath. Source: [Nexus Atlas Subpath Legend Marks](https://www.nexusatlas.com/legends/subpaths.php).

Reverse-engineering leads:

- Search for subpath service names as board text, legend-mark strings, quest markers, and NPC prompts.
- Because many services are roleplay/community driven, expect some content to live as board text or server-side records rather than client logic.

## Legend Marks And Status/Profile UI

Observed:

- Nexus Atlas describes legend marks as records obtained from quests, events, crafting skills, and more; some are good and some are bad. Source: [Nexus Atlas Legend Marks](https://www.nexusatlas.com/legends/index.php).
- Nexus Atlas says a player can check their own or another player's legends by pressing `S` and moving through status pages, or clicking a person and moving through pages. Source: [Nexus Atlas Legend Marks](https://www.nexusatlas.com/legends/index.php).
- Legend categories include alignment, crimes, events, jobs, quests, skills, subpaths, and other. Source: [Nexus Atlas Legend Marks](https://www.nexusatlas.com/legends/index.php).
- Event legend marks include anniversaries, arena-based participation/wins, and many historical hosted events. Source: [Nexus Atlas Event Legend Marks](https://www.nexusatlas.com/legends/events.php).
- Job marks track roles and role-related relationships such as mentoring, justice matters, and tutored-student counts. Source: [Nexus Atlas Jobs](https://www.nexusatlas.com/legends/jobs.php).

Reverse-engineering leads:

- Search for status/profile page navigation and labels around `Legend`, `Mark`, `Justice Matter`, `Being Mentored By`, `Tutored Students`, and category names.
- Legend marks likely share UI with status pages; official Basic Keys says `s` cycles status and Nexus Atlas describes arrow paging. Source: [official Basic Keys](https://help.nexustk.com/wiki/wiki/7/basic-keys).

## Crime, Punishment, And Law

Observed:

- Nexus Atlas crime legend marks are commonly called brandings and can affect acceptance into subpaths, clans, or high positions. Source: [Nexus Atlas Crime Marks](https://www.nexusatlas.com/legends/crimes.php).
- Nexus Atlas says multiple jailings can get a character banned from kingdoms or the game, and points to the in-game law board for more information. Source: [Nexus Atlas Crime Marks](https://www.nexusatlas.com/legends/crimes.php).
- Crime categories listed include attempted murder, harassment, inappropriate posting, minor infractions, murder, profanity, scamming, serious crimes, theft, autohunting, sage abuse, and related justice matter/jail-term markers. Source: [Nexus Atlas Crime Marks](https://www.nexusatlas.com/legends/crimes.php).
- Official terminology defines Judges as players selected/trained to try, judge, and punish law violations. Source: [official Nexus Terminology](https://help.nexustk.com/wiki/wiki/70/nexus-terminology).

Reverse-engineering leads:

- Search for `Jail`, `Justice`, `Law`, `Judge`, `branding`, `ignore`, `Autohunting`, `Sage Abuse`, `Minor Infractions`, and board/law text.
- Autohunting and macro-related language is a lead for anti-cheat or behavior-detection strings, but the fan page is not evidence of client-side enforcement.

## PVP And Controlled Combat

Observed:

- Official PK/PVP guide defines PK/PVP as player-killing/player-versus-player combat in special areas for events, carnages, or casual interactions such as sire pit. Source: [official PK/PVP Guide](https://help.nexustk.com/wiki/wiki/12/pkpvp-guide).
- Nexus Atlas carnage and event legend pages track arena participation and wins. Sources: [Nexus Atlas Carnage](https://www.nexusatlas.com/carnage/index.php), [Nexus Atlas Event Legend Marks](https://www.nexusatlas.com/legends/events.php).

Reverse-engineering leads:

- Search for PK/PVP area flags, arena maps, carnage key/host controls, sire pit references, and team-color status.

## Open-Question Resolution Notes 2026-05-24

- Current clan/subpath lists are publicly answered for the current official help era by Clans of the Kingdoms and Subpaths pages. They are not automatically target-era lists.
- Subpath services are confirmed as board/community-derived public material: the official Subpath Quests & Services page says its information came directly from Subpaths Board and elders/guides.
- Public sources define roles and some powers, but not client tooling. Archon wall-walk/fast-move/spawn/map-attribute powers are official terminology, but the client UI/tooling boundary remains local work.
- Legend marks are publicly visible through status/profile behavior and Nexus Atlas categories, but their local representation as structured records versus server-fed text remains unresolved.
- Law/crime enforcement appears server/social from public material; no public source reviewed here proves local client enforcement beyond display, reporting, screenshots, or board/profile rendering.

## Open Questions

- Which social roles have explicit client-side UI/tooling in the target binary?
- Are legend marks encoded as structured records in the client or purely server-fed display text?
- Does the client have any local enforcement around law/crime/role privilege, or only displays server decisions?
- Which clan/subpath lists are era-specific for the target client?
