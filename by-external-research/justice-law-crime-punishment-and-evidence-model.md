*** UID:0000H1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Justice, Law, Crime, Punishment, And Evidence Model

Research date: 2026-05-24

Scope: online public information about NexusTK justice roles, crime/branding marks, jail/punishment vocabulary, evidence capture, report/justice channels, PK/PVP boundaries, and Carnage-law overlap. This is external research only; confirm against local client/binary evidence before treating any behavior as target fact.

Confidence: medium. Official help is strong for role definitions and PK/PVP scope. Nexus Atlas crime pages, archives, and Carnage board mirrors are fan/historical surfaces but preserve useful dated vocabulary and workflow evidence.

## Justice Surface Inventory

Public sources point to several justice-related surfaces:

- judges and archons as authority roles;
- `/justice` and `/report` escalation channels;
- in-game law and justice boards;
- crime legend marks and brandings;
- jail-term and last-justice metadata;
- evidence screenshots;
- PK/PVP area boundaries;
- Carnage rules, host authority, and event-specific punishment.

Reverse-engineering impact: justice is not one subsystem. It likely crosses chat routing, board/mail UI, legend/profile rendering, screenshots, map/arena flags, item/spell restrictions, role privileges, and server-side punishment state.

## Authority Roles

Official Nexus Terminology defines:

- Archons as special overseer characters with powers such as wall walking, fast movement, monster spawning, and map attribute adjustment;
- Judges as trained player arbiters of NexusTK law who can judge and punish violations;
- Gods as developer-controlled community-interaction characters or roleplay totem spirits.

Nexus Atlas job marks also include Judge and the related `Justice Matter` mark, which records the last judge associated with a justice case.

Reverse-engineering leads:

- Search for `Archon`, `Judge`, `Justice Matter`, `God`, `Immortal`, `GM`, `court`, `law`, and `punish`.
- Role powers are likely server-authoritative, but the client may expose special windows, movement/visibility modes, map tools, board permissions, or privileged command labels.
- Justice metadata may appear in profile/legend display rather than a separate justice UI.

## Crime Marks And Brandings

Nexus Atlas crime legend marks describe punishments as public brandings. The page says brandings can affect acceptance into clans, subpaths, and high positions, and points players to the in-game law board for more information.

Crime/status categories listed there include:

- Last Justice Matter;
- Jail Terms;
- Attempted Murder;
- Harassment;
- Inappropriate Posting;
- Minor Infractions;
- Murder;
- Profanity;
- Scamming;
- Serious Crimes;
- Theft;
- Autohunting;
- Sage Abuse;
- Sexual Harassment.

Reverse-engineering leads:

- Search for all mark names exactly, plus `branding`, `brand`, `jail`, `sentence`, `law board`, and `Last Justice Matter`.
- Some marks are described as historical or replaced by broader serious-crime brandings. Treat fan descriptions as era-sensitive.
- Crime marks probably render in the same legend/profile system as quest, subpath, job, event, and skill marks.

## Jail, Bans, And Position Eligibility

Nexus Atlas crime marks describe jail terms as sentence counts and say repeated jailings can escalate to kingdom bans or game bans. The same page says even one branding can affect social acceptance into groups or positions.

Reverse-engineering leads:

- Search for `Jail`, `jailing`, `sentence`, `term`, `banished`, `banned from`, `kingdom`, `Koguryo`, `Buya`, `Nagnang`, and `high positions`.
- Jail and ban enforcement is likely server-side, but map names, denial messages, profile marks, and legal board content may be client-visible.
- Eligibility effects may be social policy rather than hardcoded checks except where a specific group/server process refuses entry.

## Evidence And Screenshot Capture

Nexus Atlas January 2003 archive posts describe justice evidence rules around screenshots. They report that justice screenshots needed to be taken with the client-supported Scroll Lock capture path, not external screen capture. The same archive discusses old BMP capture behavior and 5.31/5.32-era screenshot format changes.

Official Basic Keys currently document screenshot controls:

- Scroll Lock: screen capture in PNG format;
- Shift+Scroll Lock: BMP capture;
- Ctrl+Shift+3: BMP capture.

Reverse-engineering leads:

- Screenshot behavior is justice-relevant, not just graphics utility code.
- Search for `Scroll Lock`, `Screen capture`, `Screenshots`, `.png`, `.bmp`, `.jpg`, `BMP`, `JPG`, and output-folder strings.
- Old-client variants may have format changes across versions; do not assume current PNG/BMP documentation matches every target build.
- Evidence workflows may explain why screenshot code retained compatibility options.

## Justice, Report, And Board Routing

Nexus Atlas April 2020 archive reports channel routing with distinct purposes:

- `/justice`: immediate judge or archon attention for active justice issues;
- `/report`: urgent bugs or gameplay blockers for Archons or GMs, not justice matters;
- justice board: non-immediate justice issues;
- mail: non-urgent contact with Immortals or role holders.

Official Verbal Commands lists `/report` as a route to online archons but does not list every later channel variant. This suggests command/channel vocabulary evolved over time.

Reverse-engineering leads:

- Search for `/justice`, `/report`, `justice board`, `report channel`, `Archons`, `GMs`, `Immortals`, and `Halon`.
- If `/justice` is absent locally, it may have been added server-side after the target build or implemented as generic slash-command forwarding.
- Board names can matter as much as command aliases because non-urgent law issues route through boards.

## PK/PVP Boundaries

Official PK/PVP help defines player killing/player-versus-player combat as occurring in special areas for events, carnages, or casual interactions such as sire pit.

Nexus Atlas crime marks distinguish murder/attempted murder in non-PK areas from allowed PVP spaces. Nexus Atlas Carnage rules reinforce that arena activity still obeys Nexus law and Carnage-specific host rules.

Reverse-engineering leads:

- Search for `PK`, `PVP`, `sire pit`, `arena`, `Carnage`, `non-pk`, `murder`, `attempted murder`, and map flags.
- Legal/illegal player damage may be determined by map/area flags, event state, or server-side combat rules.
- The client may only display map state, arena entry prompts, or combat-result messages while the server enforces legality.

## Carnage Law And Event-Specific Punishment

Nexus Atlas Carnage rules describe event rules such as obeying hosts, keeping sage enabled for host instructions, not attacking hosts, avoiding prohibited spells/items, avoiding bug abuse, and following Nexus law inside arenas.

A live Carnage Law board mirror says entering multiple characters controlled by the same player/account into one carnage is forbidden and punishable with serious-crime jailing for all involved characters.

Reverse-engineering leads:

- Carnage law overlaps general justice, but likely uses event-host tools and board procedures.
- Search for `Carnage Law`, `Serious crimes`, `multiple characters`, `same account`, `Host`, `sage`, `F6`, `banned from Carnage`, and `Law #55`.
- Event-specific punishment may be enforced through board records, host authority, server-side role tools, and ordinary crime marks.

## Anti-Automation And Macro Vocabulary

Nexus Atlas crime marks mention autohunting, auto-skills, and auto-crafting as serious or historical crime vocabulary. The page describes these in player-policy terms, not as proof of client detection.

Reverse-engineering leads:

- Search for `Autohunting`, `Auto Skills`, `auto-crafting`, `macro`, `space bar`, `AFK`, and `not participating`.
- Treat this as policy vocabulary first. Client-side enforcement may not exist beyond normal input handling, idle state, or server messages.
- If local anti-automation strings exist, compare them carefully against server policy messages and event-law wording.

## Likely Client/Server Ownership

Likely client-owned or client-visible:

- screenshot key handling and output format/path;
- chat command entry for report/justice routes;
- board/mail windows for law, justice, and reports;
- profile/legend rendering of crime marks and justice metadata;
- arena/event UI prompts and host instructions;
- map/area labels such as jail, arena, sire pit, or carnage halls;
- local display of server punishment/error messages.

Likely server-owned:

- judge/archon/GM privileges;
- jail, ban, and punishment state;
- crime mark grants/removals;
- map flags controlling PK/PVP legality;
- report/justice routing to online authorities;
- board contents and permissions;
- Carnage host authority and event bans.

Shared protocol candidates:

- send report/justice chat;
- board list/read/post operations;
- mail/report delivery;
- legend mark updates;
- teleport/jail movement;
- PVP permission/combat result state;
- host/event rule enforcement messages;
- screenshot capture remains local, but evidence submission is social/web/mail/board side.

## String And Data Search Leads

Search locally for:

- justice roles: `Judge`, `Archon`, `GM`, `Immortal`, `God`, `Justice Matter`, `Last Justice Matter`;
- crime marks: `Attempted Murder`, `Harassment`, `Inappropriate Posting`, `Minor Infractions`, `Murder`, `Profanity`, `Scamming`, `Serious Crimes`, `Theft`, `Autohunting`, `Sage Abuse`, `Sexual Harassment`;
- punishment: `Jail`, `Jail Terms`, `sentence`, `branding`, `brandings`, `ban`, `banned`, `law board`, `court`;
- channels: `/justice`, `/report`, `justice board`, `report channel`, `online archons`;
- evidence: `Scroll Lock`, `Screen capture`, `Screenshots`, `.bmp`, `.png`, `.jpg`, `BMP`, `JPG`;
- PVP/carnage: `PK`, `PVP`, `sire pit`, `Carnage Law`, `Law #55`, `Host`, `sage`, `F6`, `same account`, `multiple characters`.

## Open Questions

- Open-question pass 2026-05-24: `/justice` timeline is narrowed. Current official Verbal Commands documents `/report`, `/novice`, `/n`, and `/tutor`; Nexus Atlas 2020 archive research documents `/justice` and `/tutors`. Treat `/justice` as later or separately documented routing unless target strings prove it.
- Open-question pass 2026-05-24: screenshot evidence is era-specific. Current official Basic Keys says Scroll Lock makes PNG and Shift+Scroll Lock / Ctrl+Shift+3 make BMP, while 2006 archive material described older JPG/BMP behavior. A target-era screenshot format needs local/version confirmation.
- Open-question pass 2026-05-24: public sources support law/crime as server/social/board-driven with client-visible marks, reports, screenshots, and board/profile display. They do not prove local enforcement of PK/PVP map flags, jail/ban, or crime marks.

- Are justice/crime marks locally formatted from structured records or displayed as server-sent legend text?
- Does the target client know `/justice`, or only `/report` and generic slash-command forwarding?
- Are PK/PVP map flags visible in local map data, or only enforced by the server?
- Does the screenshot system include anti-tamper metadata, or did judges rely on file format/visual inspection outside the client?
- Are jail/ban/court messages hardcoded locally or sent dynamically by staff/server tools?

## Sources

- [Official help: Nexus Terminology](https://help.nexustk.com/wiki/wiki/70/nexus-terminology)
- [Official help: Verbal Commands](https://help.nexustk.com/wiki/wiki/40/verbal-commands)
- [Official help: Basic Keys](https://help.nexustk.com/wiki/wiki/7/basic-keys)
- [Official help: PK/PVP Guide](https://help.nexustk.com/wiki/wiki/12/pkpvp-guide)
- [Nexus Atlas: Crime legend marks](https://www.nexusatlas.com/legends/crimes.php)
- [Nexus Atlas: Job legend marks](https://www.nexusatlas.com/legends/jobs.php)
- [Nexus Atlas January 2003 archive](https://www.nexusatlas.com/archives/mainpage-archive-1-2003.php)
- [Nexus Atlas April 2020 archive](https://www.nexusatlas.com/archives/mainpage-archive-4-2020.php)
- [Nexus Atlas Carnage Rules](https://www.nexusatlas.com/carnage/rules.php)
- [Live Carnage Law post](http://boards.nexustk.com/Carnage/Horus%2011090024.html)
