*** UID:0000GL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Board Mirror Catalog And Static HTML Schema

Research date: 2026-05-24

Scope: public `boards.nexustk.com` mirror pages and their relationship to in-game boards. This is external web research only; it does not prove how the target client stores board data or whether a local build can open these URLs.

Confidence: high for the public board-mirror URL list and HTML schema observed on 2026-05-24. Medium for interpreting relationship to in-game boards; official help confirms some board entry points, but the mirror/export pipeline itself is not publicly documented in protocol detail.

## Public Board Root

`http://boards.nexustk.com/index.html` is a live board-root page titled `Nexus TK boards`. It says the site exposes some boards available in the game and that the pages are updated every 15 minutes.

The root page is important because it answers a previous open question: Carnage is not the only public board mirror. The root currently links 24 board categories.

## Board Mirror Inventory

Counts below are from public HTML fetched on 2026-05-24. `Pages` means discovered `index*.html` pages for that board. `Rows` means counted post rows across those pages. Row counts should be treated as web-snapshot counts, not as authoritative in-game record counts.

| Directory | Public label | Pages | Rows | Last-updated signal |
| --- | --- | ---: | ---: | --- |
| `Community` | Community | 31 | 1576 | 2026-05-23 04:40:01 PDT |
| `MarketB` | Market (Buy) | 2 | 87 | 2026-05-23 19:55:01 PDT |
| `MarketS` | Market (Sell) | 3 | 119 | 2026-05-23 20:10:01 PDT |
| `Hunting` | Hunting | 4 | 159 | 2026-05-18 20:05:01 PDT |
| `ComEvents` | Community Events | 12 | 582 | 2026-05-23 20:25:02 PDT |
| `DreamWeaver` | Dream Weaver | 22 | 1107 | 2026-04-03 09:10:01 PDT |
| `Dreams` | Dreams | 24 | 1183 | 2026-05-16 21:20:01 PDT |
| `WhisperingWinds` | Whispering winds | 3 | 151 | 2023-07-27 19:45:01 PDT |
| `Law` | Law | 2 | 58 | 2022-11-08 00:30:02 PST |
| `Guide` | Guide | 2 | 72 | 2025-09-06 10:50:01 PDT |
| `Welcome` | Welcome to the Nexus | 1 | 17 | 2020-02-14 06:35:01 PST |
| `Story` | Story Contest | 29 | 1453 | 2023-03-18 18:35:01 PDT |
| `Tales` | Tales of the People | 11 | 528 | 2023-03-04 19:10:02 PST |
| `Poetry` | Poetry | 20 | 971 | 2024-04-06 10:05:01 PDT |
| `NewsKingdom` | Kingdom Tribune | 5 | 254 | 2018-11-29 08:25:04 PST |
| `Chronicles` | Chronicles of the Winds | 30 | 1485 | 2026-05-23 06:40:01 PDT |
| `DriftingWinds` | Drifting Winds | 2 | 54 | 2018-11-29 08:25:05 PST |
| `InquiringMinds` | Inquiring Minds | 3 | 152 | 2026-04-16 06:10:01 PDT |
| `FoxHunt` | Fox hunt league | 1 | 2 | 2018-11-29 08:25:05 PST |
| `Carnage` | Carnage Schedule | 1 | 31 | 2026-05-10 14:10:01 PDT |
| `Warriors` | Warriors | 2 | 78 | 2025-02-14 11:30:01 PST |
| `Rogues` | Rogues | 2 | 72 | 2022-06-03 12:15:01 PDT |
| `Mages` | Mages | 3 | 119 | 2021-09-12 16:10:01 PDT |
| `Poets` | Poets | 2 | 79 | 2024-03-27 09:45:01 PDT |

## Static Index Schema

Observed board index pages share the same broad HTML structure:

- `<title>` uses `Nexus <Board> board`, except the root uses `Nexus TK boards`.
- A `<META HTTP-EQUIV="Refresh" CONTENT="600">` tag refreshes board pages every 600 seconds.
- A `<META HTTP-EQUIV="Expires" CONTENT="0">` tag disables stale browser caching.
- CSS is loaded from `/images/boards.css`.
- The board name is displayed in a centered underlined heading.
- The post list is a table with four user-visible columns: post number, date, author, and subject.
- Each row repeats the same post URL in all four cells, which is why raw link counts are roughly four times row counts.
- Most boards paginate through `index1.html`, `index2.html`, and so on, with `Next >` and `^ Up ^` form buttons.
- The last-updated footer is not plain text. It is rendered by JavaScript from a Unix epoch expression: `new Date(<epoch> * 1000)`.

The static schema is a strong lead for in-game board fields:

- board/category name;
- numeric post id;
- short date shown as month/day;
- author display name, sometimes including role title;
- subject;
- body HTML/text;
- update/export timestamp outside the in-game post record.

## Post Page Schema

Observed post pages use a simple header/body form:

- HTML title format: `<post id> - <author> - "<subject>"`.
- Header fields: `Board`, `Author`, `Subject`, and `Date`.
- Body content follows the header and can contain line breaks, simple HTML, links, formulas, guide text, or roleplay text.
- Date display is month/day only in the visible header, while filenames commonly include author plus numeric date/id data.

Examples inspected:

- `Mages/Ataraxic 08160223.html`: Mage tutor guide post for Sa san trials.
- `Warriors/Astrael 01080116.html`: warrior weapon comparison.
- `Poets/Arkanis 12030153.html`: poet guide post discussing spell targeting.
- `Community/Astrael05231907.html`: community post about weapon AC.

These examples show that board content can preserve mechanic-heavy player/tutor knowledge: spell targeting, weapon comparisons, AC/protection, gathering charts, spell damage, rank trials, and roleplay/service information. Treat such posts as player/tutor reports unless corroborated by official help, Nexus Atlas reference pages, local resources, or binary behavior.

## Relationship To In-Game Boards

Official help confirms that the client has board entry points:

- `b` opens bulletin boards.
- `p` posts.
- the current official download page says registered accounts unlock access to all bulletin boards.
- official Carnages help says the Carnage schedule can be viewed on an in-game Carnage board at Buya `(126, 081)` or online at the Carnage mirror.

The board root also says the web pages expose some boards available in the game. Therefore the public mirror is likely an export of in-game board content or a closely related board backend. Public sources do not reveal:

- whether the web mirror is generated directly from the same database as in-game boards;
- whether all in-game boards are mirrored;
- whether private, role-only, clan, subpath, or staff boards are omitted;
- whether the client ever launches mirror URLs;
- whether the target-era client uses the same board categories as the current mirror.

## Reverse-Engineering Leads

Search locally for:

- board directories/labels: `Community`, `MarketB`, `MarketS`, `Hunting`, `ComEvents`, `DreamWeaver`, `Dreams`, `WhisperingWinds`, `Law`, `Guide`, `Welcome`, `Story`, `Tales`, `Poetry`, `NewsKingdom`, `Chronicles`, `DriftingWinds`, `InquiringMinds`, `FoxHunt`, `Carnage`, `Warriors`, `Rogues`, `Mages`, `Poets`;
- user-visible labels: `Market (Buy)`, `Market (Sell)`, `Community Events`, `Dream Weaver`, `Whispering winds`, `Welcome to the Nexus`, `Story Contest`, `Tales of the People`, `Kingdom Tribune`, `Chronicles of the Winds`, `Drifting Winds`, `Inquiring Minds`, `Fox hunt league`, `Carnage Schedule`;
- board fields: `Board`, `Author`, `Subject`, `Date`, `Post`, `Next`, `Up`;
- web/export strings: `boards.nexustk.com`, `boards.css`, `Refresh`, `Expires`;
- client controls: `b`, `p`, board list/read/post packet handlers, reply/delete/moderation commands, author/title/date formatting, role-gated write checks.

If local board handlers exist, compare the field order against the public mirror's four-column index and four-field post header before assuming a custom schema.

## Open Questions

- Which of the 24 public mirrors correspond one-to-one to in-game board categories in the target build?
- Are in-game boards and web mirrors generated from the same backend data, or is the web mirror a periodic export?
- Are private clan/subpath/role/staff boards intentionally absent from the public root?
- Does the client store board category names locally, receive them from the server, or use both?
- Does the target client include URL-launching or browser integration for board mirrors?
- Do old target-era boards use the same static HTML schema, or did this mirror format change after 2005?

## Sources

- [Public NexusTK board root](http://boards.nexustk.com/index.html)
- [Community board mirror](http://boards.nexustk.com/Community/index.html)
- [Market buy board mirror](http://boards.nexustk.com/MarketB/index.html)
- [Market sell board mirror](http://boards.nexustk.com/MarketS/index.html)
- [Hunting board mirror](http://boards.nexustk.com/Hunting/index.html)
- [Community Events board mirror](http://boards.nexustk.com/ComEvents/index.html)
- [Dream Weaver board mirror](http://boards.nexustk.com/DreamWeaver/index.html)
- [Dreams board mirror](http://boards.nexustk.com/Dreams/index.html)
- [Law board mirror](http://boards.nexustk.com/Law/index.html)
- [Guide board mirror](http://boards.nexustk.com/Guide/index.html)
- [Chronicles of the Winds board mirror](http://boards.nexustk.com/Chronicles/index.html)
- [Carnage board mirror](http://boards.nexustk.com/Carnage/index.html)
- [Warriors board mirror](http://boards.nexustk.com/Warriors/index.html)
- [Rogues board mirror](http://boards.nexustk.com/Rogues/index.html)
- [Mages board mirror](http://boards.nexustk.com/Mages/index.html)
- [Poets board mirror](http://boards.nexustk.com/Poets/index.html)
- [Official help: Basic Keys](https://help.nexustk.com/wiki/wiki/7/basic-keys)
- [Official help: Carnages](https://help.nexustk.com/wiki/wiki/38/carnages)
- [Official NexusTK download page](https://www.nexustk.com/download_2.html)
