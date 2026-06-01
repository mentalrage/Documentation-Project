*** UID:0000GZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# In-Room Pages And Inns Web Schema

Research date: 2026-05-24

Scope: public online research into the official `inns.nexustk.com` in-room/house web surface linked from the official NexusTK community page. This document records URL patterns, plot catalog structure, design-code structure, limits of the public data, and reverse-engineering leads.

Confidence: high for the current public HTTP schema observed on 2026-05-24. Medium for historical interpretation from Nexus Atlas archives. Low for any client/server ownership inference until the local binary, resources, and protocol are inspected.

## Summary

The official community page links `http://inns.nexustk.com` as `In-room pages`. The host currently responds over HTTP and exposes a static/CGI-style house web surface:

- root plot/design landing page: `http://inns.nexustk.com/`;
- plot-list pages under `/plots/<Town>.html`;
- graphical image-map pages under `/plots/World.html`, `/plots/Buya.html`, `/plots/Kugnae.html`, and `/plots/Nagnang.html`;
- a Perl pointer endpoint under `/plots/Pointer.pl`;
- room design pages under `/rooms/`;
- full room images under `/rooms/html/<code>.html` and `/rooms/images/<code>.jpg`;
- designer biography pages for Releen, Dok-Sin, Filnoos, and Altree.

The surface is a public catalog, not a visible account-management API. It can help a player find a plot number, locate a plot on a village map, preview the base interior size image, choose an interior design code, and read designer flavor text. It does not publicly expose rent ledgers, owners, current occupants, guest lists, private decorations, item permissions, storage, or live room state.

## Root Landing Page

`http://inns.nexustk.com/` and `/index.html` currently return the same page with title `Nexus Inn Room Plot List`.

The root page presents two workflows:

- find a plot in one of the villages;
- change the interior of an already rented house.

The plot text says the area helps find an available plot number in Nexus villages. After a player has a plot number, the page says the player can request to rent that house from the merchant controlling that town. The public HTML does not include owner names or a separate live availability field; the only visible plot data is plot number, size, town/location text, and coordinates.

The interior text says interiors depend on land size. A player can choose only a design of the same size as the rented plot, except that later room landing pages allow larger houses to use smaller designs too. The page tells players to take down the design code and tell an inn assistant; the assistant sets it up and notifies the player when ready.

HTTP/transport note: HTTP worked in this pass. An HTTPS probe to `https://inns.nexustk.com/` failed during TLS/send setup, so treat the live public surface as HTTP unless later testing proves otherwise.

## Kingdom And Town Navigation

The root page lists three kingdom columns:

| Kingdom column | Town links |
| --- | --- |
| Koguryo | Kangnung, Masan, Onyang |
| Buya | Tok-Do, Naju, Kimchon |
| Nagnang | Chunchon, Kunsan, Kyongju |

The graphical path is image-map based:

- `/plots/World.html` uses `World.jpg` and links to `Buya.html`, `Kugnae.html`, and `Nagnang.html`.
- `/plots/Buya.html` links to `Tok-Do.html`, `Naju.html`, and `Kimchon.html`.
- `/plots/Kugnae.html` links to `Kangnung.html`, `Masan.html`, and `Onyang.html`.
- `/plots/Nagnang.html` links to `Chunchon.html`, `Kunsan.html`, and `Kyongju.html`.

The graphical pages are old-style HTML image maps with `area` coordinates and a 3600-second meta refresh.

## Plot List Schema

Each town page has title `Nexus Inn Room Plot List for <Town>` and a table with these visible columns:

- `Plot #`;
- `Size`;
- `Location`.

Each row repeats the same pointer URL on all three cells. Example row shape:

`/plots/Pointer.pl?map=Masan&x=96&y=86&size=Small&plot=050003`

Fields:

- `map`: town name used by the pointer endpoint;
- `x`: in-game map coordinate;
- `y`: in-game map coordinate;
- `size`: `Small`, `Medium`, or `Large`;
- `plot`: six-digit plot identifier.

The location cell combines a subarea label and coordinate pair, for example `North Masan 96,86`.

The HTML uses alternating background colors and no JSON or visible form submission. The rows should be treated as generated static catalog data or static exports, not as proof that the client receives the same table.

## Current Plot Counts

The following counts were extracted by fetching each town page and de-duplicating pointer URLs, because each visible row repeats the pointer URL three times.

| Kingdom | Town | Total plots | Small | Medium | Large | First plot | Last plot |
| --- | --- | ---: | ---: | ---: | ---: | --- | --- |
| Koguryo | Kangnung | 463 | 230 | 160 | 73 | 052002 | 052795 |
| Koguryo | Masan | 461 | 213 | 152 | 96 | 050003 | 050818 |
| Koguryo | Onyang | 452 | 220 | 150 | 82 | 051001 | 051812 |
| Buya | Tok-Do | 398 | 189 | 134 | 75 | 053004 | 053802 |
| Buya | Naju | 398 | 203 | 123 | 72 | 055004 | 055799 |
| Buya | Kimchon | 404 | 209 | 113 | 82 | 054004 | 054808 |
| Nagnang | Chunchon | 143 | 83 | 30 | 30 | 057007 | 057755 |
| Nagnang | Kunsan | 141 | 69 | 43 | 29 | 058006 | 058754 |
| Nagnang | Kyongju | 139 | 65 | 45 | 29 | 056006 | 056753 |

Totals:

- 2,999 public plot entries;
- 1,481 small;
- 950 medium;
- 568 large.

Observed plot-ID prefixes align by town in this catalog:

- `050xxx`: Masan;
- `051xxx`: Onyang;
- `052xxx`: Kangnung;
- `053xxx`: Tok-Do;
- `054xxx`: Kimchon;
- `055xxx`: Naju;
- `056xxx`: Kyongju;
- `057xxx`: Chunchon;
- `058xxx`: Kunsan.

The plot identifiers are not contiguous. Do not infer missing IDs are deleted plots without local/server confirmation.

## Pointer Endpoint

The endpoint form is:

`http://inns.nexustk.com/plots/Pointer.pl?map=<Town>&x=<X>&y=<Y>&size=<Size>&plot=<PlotId>`

When `size` and `plot` are present, the page title is `<Town> - plot <PlotId>`. The page shows:

- village map image;
- absolute-positioned red arrow image;
- text stating that the arrow shows the gate to the plot;
- the plot number in a small absolute-positioned label;
- a generic inside-house image based on town/kingdom and size;
- `Back` link using `javascript:history.back()`.

Example observed URL:

`http://inns.nexustk.com/plots/Pointer.pl?map=Masan&x=59&y=132&size=Large&plot=050733`

When only `map`, `x`, and `y` are supplied, the endpoint still returns a map/arrow page but uses a generic title such as `Masan` and text saying the arrow shows the gate to the house. Nexus Atlas used this shorter pointer form in July 2004 as a public "House Direction URL" for a North Masan event location.

The pointer page uses image files such as:

- `../images/KVill.jpg` and `../images/KVillLarge.jpg`;
- `../images/NVill.jpg` and `../images/NVillSmall.jpg`;
- `../images/TokDo.jpg` and `../images/TokDoSmall.jpg`;
- `../images/point.gif`.

Interpretation: the web endpoint maps game coordinates to an HTML/CSS arrow position over large map images. This is useful for coordinate/resource vocabulary, but it does not prove that the game client computes these web arrow positions.

## Room Design Navigation

Room design landing pages:

- `/rooms/Small.html`: lists small interiors directly.
- `/rooms/Medium.html`: lets the user choose small or medium interiors.
- `/rooms/Large.html`: lets the user choose small, medium, or large interiors.
- `/rooms/SmallB.html`, `/rooms/MediumB.html`, `/rooms/LargeB.html`: actual catalog pages.

Observed compatibility rule:

- a small plot can use small interiors;
- a medium plot can use small or medium interiors;
- a large plot can use small, medium, or large interiors.

Each catalog entry contains:

- four-digit room code;
- room name;
- designer;
- 200x200 thumbnail image `/rooms/images/<code>A.jpg`;
- full-size page `/rooms/html/<code>.html`;
- full-size image `/rooms/images/<code>.jpg`;
- descriptive flavor text.

The full-size HTML pages are simple wrappers around a single image and use titles such as `Nexus Inn Room - Code: 0101`.

## Interior Design Codes

Current visible design codes:

| Size group | Code | Name | Designer |
| --- | --- | --- | --- |
| Small | 0101 | Lavender Dream | Releen |
| Small | 0102 | Sky Dreams | Filnoos |
| Small | 0103 | Stone Sentinels | Dok-Sin |
| Small | 0104 | Love's Nest | Filnoos |
| Small | 0105 | Grange | Altree |
| Small | 0106 | Essence | Releen |
| Small | 0107 | Marble Sky | Dok-Sin |
| Small | 0108 | Serenity | Filnoos |
| Small | 0109 | Woven Reeds | Altree |
| Small | 0110 | Flamboyance | Releen |
| Small | 0111 | Autumn Dream | Altree |
| Small | 0112 | Rainbow Delight | Filnoos |
| Small | 0113 | Stoney Terrace | Dok-Sin |
| Small | 0114 | Traditionality | Releen |
| Medium | 0201 | Miners Delight | Dok-Sin |
| Medium | 0202 | Muddy Banks | Altree |
| Medium | 0203 | Geometry | Dok-Sin |
| Medium | 0204 | Amazing Nature | Altree |
| Medium | 0205 | Chiseled Beauty | Dok-Sin |
| Medium | 0206 | Party Room | Releen |
| Medium | 0207 | Royal Suite | Filnoos |
| Medium | 0208 | Floral Fields | Altree |
| Medium | 0209 | Filnoos' Finest | Filnoos |
| Medium | 0210 | Love's Sanctuary | Releen |
| Medium | 0211 | Restful Grove | Altree |
| Medium | 0212 | The Cavern | Dok-Sin |
| Large | 0301 | Tribal Gathering | Altree |
| Large | 0302 | Scholars Den | Dok-Sin |
| Large | 0303 | Island Paradise | Altree |
| Large | 0304 | Forested Falls | Altree |
| Large | 0305 | Ball Room | Filnoos |
| Large | 0306 | Royal Function | Releen |
| Large | 0307 | Grand Hall | Dok-Sin |
| Large | 0308 | Frabricity | Filnoos |
| Large | 0309 | Life Engraved | Dok-Sin |
| Large | 0310 | Scholars hideaway | Releen |
| Large | 0311 | Waterfall dreams | Altree |

Notes:

- The live HTML has spelling variants such as `Desinger`, `Frabricity`, `Scholars hideaway`, and `Waterfall dreams`. Preserve those spellings as source vocabulary when searching local strings.
- Current catalog total is 37 design codes: 14 small, 12 medium, and 11 large.

## Designer Pages

The designer biography pages are:

- `/rooms/Releen.html`;
- `/rooms/Dok-Sin.html`;
- `/rooms/Filnoos.html`;
- `/rooms/Altree.html`.

Their text frames the designers by style:

- Releen: traditional, colorful, broad design inspiration;
- Dok-Sin: stone/cave/statue-focused designer tied to Nagnang caves;
- Filnoos: luxury/flamboyant/fabric/royalty themes;
- Altree: nature-focused, garden/outdoor style.

These names appear in a July 2003 Nexus Atlas archive repost about new house designs and are also live in the current room pages.

## Historical Anchors

Nexus Atlas July 2003 archive:

- preserves a Dream Weaver repost about `New House Designs`;
- names designers Releen, Dok-Sin, Filnoos, and Altree;
- says there were 12 more designs, 4 for each house size;
- directs players to the house website `http://inns.nexustk.com`.

Nexus Atlas July 2004 archive:

- uses `http://inns.nexustk.com/plots/Pointer.pl?map=Masan&&x=59&y=132` as a public `House Direction URL`;
- labels it as a North Masan map with arrow for an event location.

Interpretation: the in-room/house website and pointer endpoint are old-era surfaces, not modern-only leftovers. The current 37-code design catalog is cumulative or later than the July 2003 "12 more designs" anchor, so do not assume every current design existed in the first house-design rollout.

## What The Public Site Can And Cannot Answer

Publicly answered:

- official community navigation host for in-room pages;
- current town/kingdom plot catalog;
- plot-number, size, town, subarea, and coordinate schema;
- pointer URL grammar;
- map/arrow web display behavior;
- current interior design-code catalog;
- size compatibility for selecting designs;
- design image URL pattern and designer names;
- historical existence by July 2003/July 2004 archives.

Not publicly answered:

- whether each public plot row is currently unrented, rentable, or merely listed;
- plot owner, rent expiry, guest list, mailbox/invitation state, or current occupants;
- whether a player has chosen a custom design;
- whether private room item/spell rules are represented in the public site;
- whether web data comes from the same server records used in-game;
- whether the client opens this site directly or players navigate through a browser;
- whether the local target binary contains any `inns.nexustk.com` URL strings;
- packet formats for rent, guest, interior, House server transfer, or return-home behavior.

## Reverse-Engineering Leads

Search local strings and resources for:

- domains and paths: `inns.nexustk.com`, `/plots/Pointer.pl`, `/rooms/Small`, `/rooms/Medium`, `/rooms/Large`;
- house web labels: `In-room pages`, `Nexus Inn Room Plot List`, `Nexus Inn Room Design List`;
- rent/assistant terms: `plot`, `rent`, `merchant controlling that town`, `inn assistant`, `notify you when it is ready`;
- plot sizes: `Small`, `Medium`, `Large`;
- town names and plot-ID prefixes: `050`, `051`, `052`, `053`, `054`, `055`, `056`, `057`, `058`;
- design codes and names: `0101`, `0201`, `0301`, `Lavender Dream`, `Party Room`, `Grand Hall`;
- designer names: `Releen`, `Dok-Sin`, `Filnoos`, `Altree`;
- image/resource names if web assets were ever bundled or mirrored: `KVill`, `NVill`, `TokDo`, `point.gif`.

Likely ownership split:

- web/server: public plot catalog generation, design catalog, pointer map generation;
- server/game: rent status, owner state, guest permissions, interior-change approval, House server routing, item/spell restrictions;
- client-visible: map transfer, house entry/exit, messages from innkeeper/assistant, design request/status text, room/interior rendering.

Open local checks:

- whether `plot` IDs appear in packets, resources, map scripts, or server messages;
- whether `Small`/`Medium`/`Large` interior selection is represented as numeric enum values;
- whether current public design codes match any local map/resource IDs;
- whether old clients include `inns.nexustk.com` or only in-game innkeeper text;
- whether map coordinates in pointer URLs match local tile coordinates exactly.

## Sources

- [Official NexusTK community page](https://www.nexustk.com/community.html)
- [NexusTK in-room page root](http://inns.nexustk.com/)
- [NexusTK in-room world map](http://inns.nexustk.com/plots/World.html)
- [NexusTK Masan plot list](http://inns.nexustk.com/plots/Masan.html)
- [NexusTK Masan pointer example](http://inns.nexustk.com/plots/Pointer.pl?map=Masan&x=59&y=132&size=Large&plot=050733)
- [NexusTK small room designs](http://inns.nexustk.com/rooms/SmallB.html)
- [NexusTK medium room designs](http://inns.nexustk.com/rooms/MediumB.html)
- [NexusTK large room designs](http://inns.nexustk.com/rooms/LargeB.html)
- [NexusTK room code 0101 example](http://inns.nexustk.com/rooms/html/0101.html)
- [Nexus Atlas July 2003 archive](https://www.nexusatlas.com/archives/mainpage-archive-7-2003.php)
- [Nexus Atlas July 2004 archive](https://www.nexusatlas.com/archives/mainpage-archive-7-2004.php)
