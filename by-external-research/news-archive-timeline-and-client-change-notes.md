*** UID:0000H3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# News Archive Timeline And Client Change Notes

Confidence: medium. Nexus Atlas archives are fan-maintained and often repost or paraphrase official notes. Treat this as a guide to historical vocabulary and likely client/server features, not as binary proof.

Scope: selected high-value archive findings from Nexus Atlas news and official pages. This is not a complete history. The goal is to capture external clues relevant to client reverse engineering.

## Archive Mechanics

Observed:

- Nexus Atlas has a dedicated archive index for manually indexed past news pages. The archive index explains that older news links were manually preserved because the old news software purged links to articles more than two years old. Source: [Nexus Atlas archive index](https://www.nexusatlas.com/archives/index.php).
- The current Nexus Atlas main page still has live server-style status and recent headlines, so it remains useful for current terminology and community categories. Source: [Nexus Atlas main page](https://www.nexusatlas.com/).

Implication: the archives are unusually valuable because they preserve event, patch, map, and community vocabulary across many years, including material no longer present on official pages.

## Selected Timeline

### 2004-02: Nagnang and item stat changes

Nexus Atlas reported new tiles south of west gate Nagnang and a polearm armor-class change. Source: [February 2004 archive](https://www.nexusatlas.com/archives/mainpage-archive-2-2004.php).

RE value: search for Nagnang map expansion data, polearm item records, and item AC modifiers if the target binary predates or overlaps this era.

### 2005-04: Large 5.x map release

Nexus Atlas reported a major 5.x map-section release for Buya-server areas including Buya, Islets, Sanhae, and Arctic lands. Source: [April 2005 archive](https://www.nexusatlas.com/archives/mainpage-archive-4-2005.php).

RE value: map resources and atlas naming may distinguish 5.x versus 6.x graphics/data.

### 2006-01: Official site redesign and Nexus 6.59 auto-patch

Nexus Atlas reported a new official Nexus website design in January 2006, described as updated to match new client graphics. The same month includes a `Nexus 6.59` auto-patch report. Source: [January 2006 archive](https://www.nexusatlas.com/archives/mainpage-archive-1-2006.php).

The 6.59 report is especially useful. It mentions high-resolution emotions/actions, multiple equipment sprite fixes, a low-resolution `Control-w` crash fix, walk-blocking fixes, text color dialog buttons, clan bank visibility, updated death graphic, map tile fixes, carnage host alive-count display, and updated ring/subpath item looks.

RE value:

- high-resolution and low-resolution rendering branches;
- action/emotion animation resources;
- equipment paper-doll composition and directional sprite bugs;
- text color dialog code;
- clan bank UI;
- carnage host UI;
- death sprite/resource update;
- map tile collision/walkability changes.

### 2006-05: Reset changes and map project completion

Nexus Atlas reported May 2006 reset changes including a Book of Song graphic update, event item deposit/repair cost changes, clan room/merchant changes, and a Shaman item. A May 28 entry says the Woodlands map release completed a map project that started with the Vortex release week in June 2003. Source: [May 2006 archive](https://www.nexusatlas.com/archives/mainpage-archive-5-2006.php).

RE value:

- music/book item graphics;
- deposit/repair pricing UI;
- event-item durability/repair behavior;
- clan/subpath merchant additions;
- map coverage milestones for Vortex/Woodlands.

### 2006-11: Kruna item shop launch

Nexus Atlas reported the Kruna item shop opening on the NexusTK webpage on November 6, 2006. The report describes account login, Kruna recharge through coupon flow, item purchase, delivery through Messenger/parcel, and item-shop transfer restrictions. Source: [November 2006 archive](https://www.nexusatlas.com/archives/mainpage-archive-11-2006.php).

RE value:

- `Kruna`, `Item Shop`, `Messenger`, `parcel`, `Coupon Shop`, and transfer-restriction strings;
- web/account integration boundaries;
- item flags for bonded/non-transferable/drop/exchange behavior;
- deposit/repair allowances for cash-shop items.

### 2007-01: ZoomTK, `/roll`, and gambling law

Nexus Atlas reported ZoomTK map work in January 2007 and a new gamble law after introduction of `/roll`. Source: [January 2007 archive](https://www.nexusatlas.com/archives/mainpage-archive-1-2007.php).

RE value:

- `/roll` and `/random` command parsing;
- visible dice output;
- chat spam/hearing filters;
- map zoom/full-size map concepts are external-site features, but the archive references coordinates and map freshness that help date external map data.

### 2011-04: Nexus 6.90

Nexus Atlas reported `Nexus 6.90` in April 2011. The report says the client auto-patched; Windows Vista/7 users should run as administrator; default inventory size increased from 26 to 27; item-shop expansion could reach 52 slots; durability notices moved to the text box; Easter and Earth Day events appeared; and Spy/army coat items had minor updates. Source: [April 2011 archive](https://www.nexusatlas.com/archives/mainpage-archive-4-2011.php).

RE value:

- updater elevation/admin handling;
- inventory capacity constants and item-shop capacity overrides;
- durability threshold warning routing from status window to text box;
- event item/map injection;
- path/subpath/army clothing resource updates.

### 2015-2020: Seasonal event reuse and quest scripting

Nexus Atlas archives from 2015, 2016, and 2020 show recurring seasonal event walkthroughs such as Easter eggs and St. Patrick's Day/Green Ale steps, with NPC speech triggers, map selection, coordinate references, item collection, and temporary rewards. Sources: [April 2015 archive](https://www.nexusatlas.com/archives/mainpage-archive-4-2015.php), [March 2016 archive](https://www.nexusatlas.com/archives/mainpage-archive-3-2016.php), [April 2020 archive](https://www.nexusatlas.com/archives/mainpage-archive-4-2020.php).

RE value:

- repeated seasonal event strings and temporary item names;
- event NPC dialogue triggers;
- map selection UI;
- quest state and inventory checks;
- temporary morph/spell/item effects.

### 2026: Active community/news cadence

Nexus Atlas current front page in May 2026 shows recent headlines, live server categories, and active community leadership/event reporting. Source: [Nexus Atlas main page](https://www.nexusatlas.com/).

RE value: current data confirms modern terms still include Nation, Carnage, Event, House, primogen/clan leadership, and festival/community-event language. Do not assume these all existed in the target binary era.

## Cross-Cutting Reverse-Engineering Search Terms

- Client/version: `Nexus 6.59`, `Nexus 6.90`, `auto-patch`, `NexusUpdater.exe`, `high-resolution`, `low-resolution`.
- UI/input: `Control-w`, `text color`, `damage numbers`, `durability`, `inventory`, `Messenger`, `parcel`.
- Systems: `clan bank`, `Carnage`, `Bloodlust`, `Elixir`, `Kruna`, `Item Shop`, `/roll`, `/random`.
- Map/event: `Vortex`, `Woodlands`, `ZoomTK`, `Tree of Reflections`, `Bonghwang`, `Green Ale`, `Easter eggs`.
- Social: `Primogen`, `Elder`, `Guide`, `Ministry`, `Army`, `Tutor`, `Judge`.

## Open Questions

- Open-question pass 2026-05-24: public version anchors now include the 2003 official 50.5 MB client reference, Nexus 6.5/6.59 high/low-resolution transition, Nexus 6.90 in April 2011, and current Nexus TK 7.52. Matching the local binary remains a local metadata/string/resource task.
- Open-question pass 2026-05-24: the April 2011 Nexus Atlas archive answers a specific inventory/durability point for Nexus 6.90: default inventory increased from 26 to 27, item-shop expansion could reach 52, and durability warnings moved to the text box at 50%, 25%, 10%, 5%, and 1%.
- Open-question pass 2026-05-24: public archives can identify candidate patch changes, but correspondence to local code/resources requires local diffing or string/resource inspection.

- Is the target binary closer to 5.x, 6.x, or later public clients?
- Which archive-reported patch changes correspond to local resource or code deltas visible in this repository?
- Are inventory-size and durability-warning constants visible in client code, or server-driven?
- Does local resource data preserve event maps/items after events ended?
