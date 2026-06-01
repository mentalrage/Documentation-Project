*** UID:0000GJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Archive, News, Reset, And Event Mining Methodology

Research date: 2026-05-24

Scope: how to mine Nexus Atlas current news and archive pages for client/server feature leads, while preserving date context and separating fan reporting from reposted official or board text.

Confidence: medium. Nexus Atlas archives are extensive and often quote or summarize in-game board posts, but they remain fan-maintained pages. Use them as dated leads until corroborated by official pages, live boards, local resources, packets, or binary strings.

## Archive Topology

Nexus Atlas has two archive indexes:

- `archives/index.php`: current monthly archive index. In this pass it listed April 2026 back through January 2008.
- `archives/archivednews.php`: older/manual archive index. In this pass it listed February 2010 back through April 2002.

The two indexes overlap for 2008-2010. The site explains that its old Coranto news software had a bug that purged links older than two years, so older pages were manually indexed.

Archive URL pattern:

- `https://www.nexusatlas.com/archives/mainpage-archive-M-YYYY.php`
- example: `mainpage-archive-4-2026.php`
- example: `mainpage-archive-3-2020.php`

Use month/year URLs directly when building a crawl list.

## Current Front Page Signal

The current Nexus Atlas front page is useful because it exposes live vocabulary and site structure:

- server status with `OK`;
- total users online;
- visible server buckets such as Nation, Carnage, Event, and House;
- recent headlines;
- current long-form news posts;
- contributor/reporting instructions;
- screenshot submission notes.

On May 24, 2026, the front page showed 131 total users online with separate counts for Nation, Carnage, Event, and House. Treat those as live web status labels, not necessarily target-client-era strings.

The front page also asks players to submit screenshots in `.bmp` or `.png` format and mentions in-game screenshot keys. This is a useful cross-check against official Basic Keys and old-client screenshot behavior.

## Article Record Pattern

Nexus Atlas news/archive entries usually carry:

- month archive title;
- day/date heading;
- headline;
- `Posted by` reporter and time;
- screenshots/images;
- body text;
- in-game date such as Hyul/Moon/Sun in some entries;
- pasted in-game board blocks with fields like `BOARD TITLE`, `FROM`, `DATE`, and `SUBJECT`;
- event walkthrough steps;
- item lists, coordinates, NPC names, and player names;
- credits to players who provided discoveries.

For extraction, preserve at least:

- Gregorian date;
- archive URL;
- headline;
- reporter/source type;
- whether the text is reporter observation, official site repost, Dream Weaver post, Community board post, or live board post;
- client/server feature leads;
- exact terms to search later.

## High-Value News Categories

Archive pages are especially useful for:

- client patches and version announcements;
- server reset notes;
- Dream Weaver posts;
- Community board reposts;
- new maps and temporary event maps;
- seasonal event walkthroughs;
- NPC keyword and item hand-in sequences;
- new spells, temporary spells, aethers, or spell-effect items;
- Carnage/PVP rule changes;
- Kruna/item-shop releases;
- role changes such as primogens, elders, tutors, judges, and hosts;
- screenshot/UI reports;
- account/support/domain transitions.

Low-value or context-only categories:

- long roleplay speeches without mechanics;
- player interviews with no system details;
- social ceremony summaries unless they include map, item, title, board, or legend vocabulary;
- site/header/theme changes unrelated to the game client.

## Date And Version Discipline

Every extracted fact should keep its date. Many archive pages describe temporary events or later-client behavior.

Use this rule:

- Official current help page: likely current public behavior, but may be old help text.
- Official archived/reposted board text: strong dated lead for that date.
- Nexus Atlas reporter observation: medium dated lead.
- Player comment/walkthrough in archive: lower confidence but often useful for NPC keywords and item names.
- Current front page: current vocabulary only, not historical proof.

Do not merge 2002, 2006, 2010, 2020, and 2026 behavior into one timeless model.

## Example: Easter Event Scripting

The April 2026 archive reports a yearly Easter return:

- colored eggs spawn on the floor around kingdoms;
- opening eggs can give coins, pirate coins, random items, stats, or rare items;
- rare examples include Zibong blade and Book of Song;
- special eggs cast temporary effects such as Desperate attack, Whirlwind, Harden body, or invoke-like behavior;
- NPC Tokki appears outside Buya or Kugnae Palace;
- Tokki asks for help three times;
- players collect 1, then 20, then 50 Mysterious Eggs;
- reward includes a legend mark and path-dependent temporary spells;
- Warrior/Rogue/Mage get Easter Revival, while Poets get Easter Orb of Sul Slash.

Reverse-engineering leads:

- floor-spawn item logic;
- item-open/use effect dispatch;
- temporary event spell grant/removal;
- path-dependent reward branching;
- NPC keyword/quest-state chain;
- event legend mark strings;
- max stack/hold count for temporary event items.

## Example: Balanced Caves And Event Under 99

The March 2020 archive includes a Community-board repost from GM Wony with balanced cave information:

- level/stat bands map to Cave 1 through Cave 10;
- lower and lowest split paths apply exp/drop penalties;
- high bands include values such as 640k/320k, 2m/1m, and 5m/2.5m.

The same month includes event-under-99 notes:

- Frozen Fortress and Fortress room names;
- Stygian archmage;
- Black amber, Mystic potion, and rare artifact drops;
- Imp seal used on a gate;
- legend mark and karma reward;
- adjusted ghost difficulty and level-block change.

This is useful for event cave gate logic, split-selection UI, temporary maps, drop tables, and GM-posted balance constants.

## Example: New Communication Channels

The April 2020 archive preserves a Community-board post about communication channels:

- `/tutors` for help from tutors;
- `/novice` for lower-level/new-player assistance;
- `/justice` for immediate judge/archon justice issues;
- `/report` for bugs or situations needing archons/GMs;
- non-urgent issues should use boards or mail.

This extends the official Verbal Commands page, which currently lists `/report`, `/novice`, `/n`, and `/tutor` but not every 2020 channel form. Treat this as evidence of channel evolution and search for both singular and plural variants.

## Example: Community Rituals And Seasonal Events

The February 2026 archive includes a Lunar New Year ritual around the Tao te Ching, zodiac animals, elements, symbolic objects, performance, and player participation. The May 2026 front page covers Beltane and a SanSin primogen change.

These entries may not contain client code behavior, but they are strong for:

- map/venue names;
- role titles;
- seasonal vocabulary;
- temporary floor art/object usage;
- social rank/status names;
- potential event legend marks or board posts.

Use them as low-risk vocabulary seeds, not mechanics proof.

## Crawl And Extraction Workflow

Recommended workflow for future agents:

1. Build a month list from both archive indexes.
2. Fetch pages with a browser-like user agent.
3. Strip scripts/styles/tags, but keep dates and headings.
4. Search each page for feature terms:
   - `BOARD TITLE`
   - `Dream Weaver`
   - `Community`
   - `Server Reset`
   - `client patch`
   - `Nexus 5`
   - `Nexus 6`
   - `Kruna`
   - `Item Shop`
   - `Carnage`
   - `map`
   - `quest`
   - `legend`
   - `spell`
   - `aether`
   - `coordinate`
   - `bug`
   - `patch`
5. Extract only dated, concrete facts into topic docs.
6. Put chronological client/version anchors into `full-update-history.md`.
7. Record uncertain or fan-only interpretations as hypotheses.

Keep event walkthroughs as summaries, not large copied passages.

## Suggested Extraction Fields

Use a structured note per finding:

- `date`: Gregorian date from archive.
- `source_url`: full archive URL.
- `source_kind`: Nexus Atlas report, official repost, Dream Weaver board, Community board, live board, official help.
- `headline_or_subject`: exact headline/subject.
- `systems`: client patch, map, event, item, spell, board, account, PVP, social role, etc.
- `facts`: concise summary.
- `search_terms`: strings to search in local data.
- `confidence`: high/medium/low.
- `follow_up`: local verification target.

This will keep the archive corpus from becoming a loose pile of anecdotes.

## Reverse-Engineering Leads

Search local resources and strings for archive-derived patterns:

- board markers: `BOARD TITLE`, `FROM`, `DATE`, `SUBJECT`, `Dream Weaver`, `Community`, `Chronicles of the Winds`;
- reset/patch markers: `Server Reset`, `client patch`, `auto-patch`, `Version`, `Nexus 5.31`, `Nexus 6.59`, `Nexus 6.90`;
- event names: `Easter`, `Tokki`, `Mysterious Egg`, `Frozen Fortress`, `Imp seal`, `Stygian archmage`, `Beltane`, `Lunar New Year`;
- communication channels: `/tutors`, `/justice`, `/novice`, `/report`, `/tutor`;
- live server buckets: `Nation`, `Carnage`, `Event`, `House`;
- media/UI terms: `.bmp`, `.png`, screenshot, chat windows, statistics, items, spells.

## Sources

- [Nexus Atlas current front page](https://www.nexusatlas.com/)
- [Nexus Atlas archive index](https://www.nexusatlas.com/archives/index.php)
- [Nexus Atlas older archived-news index](https://www.nexusatlas.com/archives/archivednews.php)
- [Nexus Atlas February 2026 archive](https://www.nexusatlas.com/archives/mainpage-archive-2-2026.php)
- [Nexus Atlas April 2026 archive](https://www.nexusatlas.com/archives/mainpage-archive-4-2026.php)
- [Nexus Atlas March 2020 archive](https://www.nexusatlas.com/archives/mainpage-archive-3-2020.php)
- [Nexus Atlas April 2020 archive](https://www.nexusatlas.com/archives/mainpage-archive-4-2020.php)
- [Nexus Atlas February 2010 archive](https://www.nexusatlas.com/archives/mainpage-archive-2-2010.php)
- [Nexus Atlas January 2006 archive](https://www.nexusatlas.com/archives/mainpage-archive-1-2006.php)
- [Nexus Atlas November 2006 archive](https://www.nexusatlas.com/archives/mainpage-archive-11-2006.php)

## Open Questions

- Open-question pass 2026-05-24: local mirroring is practical only if the mirror is stored under `by-external-research` and remains source material, but a full mirror is likely noisy. Prefer targeted URL lists and extracted notes over bulk HTML unless a future task explicitly needs corpus search.
- Open-question pass 2026-05-24: highest-value archive months for target matching now have stronger anchors: January 2003 for 5.31/5.32, late 2005 through January 2006 for 6.5/6.59 high/low-resolution transition, April 2011 for 6.90, and current official pages for 7.52.
- Open-question pass 2026-05-24: Dream Weaver/Community board repost fidelity remains unresolved. Archives visibly mix official-style reposts, fan reports, and summaries; each entry should be classified individually.
- Open-question pass 2026-05-24: temporary-event retention cannot be answered from web archives alone. Public archives identify event names/maps/items, while local resource inspection must determine whether assets persisted after events.

- Is there a practical way to mirror the full archive corpus locally without touching output directories outside `by-external-research`?
- Which archive months are most likely to match the target binary's client version?
- Do current Nexus Atlas server-status labels map to server names/protocol fields, or are they purely site-side?
- Are Dream Weaver/Community board reposts exact copies, edited summaries, or a mix?
- How much temporary-event content remains in local client resources after events expire?
