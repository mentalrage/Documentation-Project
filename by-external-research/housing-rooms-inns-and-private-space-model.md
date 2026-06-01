*** UID:0000GX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Housing, Rooms, Inns, And Private Space Model

Research date: 2026-05-24

Scope: online public information about NexusTK houses, inns, in-room web pages, house-server status, custom room/interior behavior, rent/guest flows, and private-space rule clues. This is external research only and should be confirmed locally before being treated as target-client fact.

Confidence: medium-low. Housing information is scattered across current web links, Nexus Atlas server-status pages, and old archive reports. The archive reports are valuable dated leads but may describe server-side behavior, era-specific bugs, or systems later rewritten.

## Housing Surface Inventory

Public sources point to several related surfaces:

- a current official community-page link for `In-room pages`;
- an `inns.nexustk.com` web host linked from the official community page;
- a separate `House server` bucket on Nexus Atlas server status;
- old `house server` and `inn system` archive reports;
- rent and guest management through innkeepers;
- custom house design/interior requests;
- house-specific item/spell toggles;
- return-home behavior exposed through F1 in an old archive report;
- map/atlas listings for inns, halls, rooms, and private group spaces.

Reverse-engineering impact: housing is likely not just map data. It may involve separate server routing, per-house state, ownership/rent records, guest permissions, configurable interiors, item/spell rules, and web-facing room/profile pages.

## Official Community Web Surface

The official NexusTK community page links `In-room pages` alongside boards, user list, and user profile. Earlier research identified the in-room pages host as `inns.nexustk.com`.

Follow-up research on 2026-05-24 confirmed that `http://inns.nexustk.com/` is a live HTTP house/inn catalog, not just a dead community link. The public host exposes plot lists, town/kingdom image maps, a `Pointer.pl` endpoint that places a red arrow over map images, and a 37-code interior design catalog. See [UID:0000GZ][in-room-pages-and-inns-web-schema](by-external-research/in-room-pages-and-inns-web-schema.md) for the observed URL grammar and current counts.

Reverse-engineering leads:

- Search for `inns.nexustk.com`, `In-room pages`, `room pages`, `User profile`, and `Community`.
- Web room pages may be generated from server data rather than the game executable, but URL strings or menu actions may exist locally.
- This surface should be separated from in-client houses/inns unless local evidence links them.

## In-Room Web Catalog Details

The current in-room host answers several previously open public questions:

- root pages `/` and `/index.html` are titled `Nexus Inn Room Plot List`;
- plot-list pages are under `/plots/<Town>.html`;
- town plot rows expose `Plot #`, `Size`, and `Location`;
- row links use `/plots/Pointer.pl?map=<Town>&x=<X>&y=<Y>&size=<Small|Medium|Large>&plot=<PlotId>`;
- the current catalog has 2,999 plot entries across nine towns;
- current design pages expose 37 design codes: 14 small, 12 medium, and 11 large;
- medium houses can use small or medium designs; large houses can use small, medium, or large designs;
- design entries include code, room name, designer, thumbnail, full-size image page, and descriptive text;
- public designer names are Releen, Dok-Sin, Filnoos, and Altree.

What the web catalog does not answer:

- whether a listed plot is currently rented or actually available;
- owner, guest, rent-expiry, occupant, storage, or private item state;
- whether web catalog records are generated from the same live records used by in-game houses;
- whether the target client opens this site or only shares vocabulary with in-game innkeepers.

Useful search terms added by the catalog:

- URL/path terms: `/plots/Pointer.pl`, `/rooms/SmallB.html`, `/rooms/MediumB.html`, `/rooms/LargeB.html`;
- plot ID prefixes: `050`, `051`, `052`, `053`, `054`, `055`, `056`, `057`, `058`;
- design code ranges: `0101`-`0114`, `0201`-`0212`, `0301`-`0311`;
- room names: `Lavender Dream`, `Love's Nest`, `Party Room`, `Grand Hall`, `Waterfall dreams`;
- asset-style names: `KVill`, `NVill`, `TokDo`, `point.gif`.

## Separate House Server Signal

The Nexus Atlas server-status page currently lists five public server buckets: Login, Nation, Carnage, Event, and House. A 2026-05-24 fetch showed a `House server` with its own uptime and user count.

Reverse-engineering leads:

- Search for `House server`, `Login server`, `Nation server`, `Carnage server`, and `Event server`.
- The status page is a web surface, but it suggests house/private-space traffic may be separated from normal Nation maps.
- If local client code contains server-selection or transfer logic, House may appear as a server type, map category, or connection target.

## 2003 House/Inn System Rewrite

The August 2003 Nexus Atlas archive preserves a Dream Weaver reset report about a new house system. The report says the inn system was being rewritten from the ground up and that the new system was intended to smooth out house-management flows, especially delays around offline letters and new house design requests.

Observed behaviors from the same archive month:

- offline house invitations no longer arrived as one of the old letters;
- players saw a status-box message on login for house invitations;
- the innkeeper flow used the word `Guest`;
- rent renewal was updated to select a number of months rather than repeated guessing/clicking;
- a bug could prevent a player from living in their house;
- an innkeeper rent-charge bug was reported;
- house-server F1 return-home behavior could teleport a trapped player back to the normal wake-up location;
- a house option could toggle potions and scrolls, including yellow scrolls.

Reverse-engineering leads:

- Search for `Guest`, `rent`, `renew rent`, `Inn keeper`, `Return home`, `New house design`, `house design`, `live in your house`, and `potions and scrolls`.
- Offline guest invitations imply server-side mailbox/status messaging that may share code with mail or Messenger indicators.
- House-specific item/spell toggles imply per-map or per-house rule flags.

## January 2003 House Server And Interior Bugs

The January 2003 Nexus Atlas archive reports 5.31/5.32-era client/server issues. It says the house server returned but the `New interior` option was disabled for a period because it caused crashes. The same archive mentions custom room design issues while discussing sound and client patch problems.

Reverse-engineering leads:

- Search for `New interior`, `custom room`, `custom room designs`, `house server`, `interior`, and crash/loading strings.
- Housing/interior features may touch client resource loading, map tiles, object placement, and server transfer.
- If the target build is near the 5.31/5.32 era, house/interior code may be fragile and mixed with map/render changes.

## Inns, Wake-Up Locations, And Return Home

Archive reports connect houses to innkeeper flows, rent, guests, and wake-up/return-home behavior. Nexus Atlas map pages also list inns and taverns as ordinary map features in cities such as Buya, Kugnae, and Nagnang.

Reverse-engineering leads:

- Inns are both public map locations and house-management interfaces.
- Search for `Inn`, `Innkeeper`, `wake up`, `Return home`, `home`, `rent`, `guest`, `Pepper Tavern`, `Spring Tavern`, `Yunsil Tavern`, and city inn/tavern names.
- Return-home behavior may be a server-side teleport command exposed through a help/F1 action.

## House Rules And Item/Spell Restrictions

The August 2003 archive's house-setting note says potions and scrolls could be enabled or disabled in houses. The report specifically mentions yellow scrolls as part of this option.

Potential rule categories:

- potion use;
- scroll use;
- yellow scroll return behavior;
- return-home escape;
- guest/occupant permissions;
- rent/ownership active state;
- custom design pending state.

Reverse-engineering leads:

- Search item-use logic for map/house restrictions, especially scroll and potion denial messages.
- House-rule checks may be map flags, server validation, or both.
- Yellow scroll behavior overlaps travel/return-to-inn behavior documented in item references.

## Private, Clan, And Group Spaces

Housing should be distinguished from other private/semi-private spaces:

- personal houses/inn rooms;
- clan halls and clan rooms;
- subpath halls;
- ministry/army offices;
- Carnage/event halls;
- inns and taverns;
- current web `In-room pages`.

Reverse-engineering leads:

- Use map/area labels to avoid conflating personal house maps with clan hall maps.
- Search for `Clan hall`, `Clan room`, `Subpath Area`, `Gathering`, `Tavern`, `Hall`, `Room`, and `House`.
- Permissions may share generic room-entry checks but differ in ownership and role state.

## Likely Client/Server Ownership

Likely client-owned or client-visible:

- map/interior rendering and local resource loading;
- door/open interactions and room transitions;
- UI/help entry for return-home behavior, if present;
- status-box invitation or rent messages;
- innkeeper NPC dialogue text;
- item-use denial messages for house rules;
- URL/menu links to in-room pages, if any.

Likely server-owned:

- house ownership and rent state;
- guest/occupant lists;
- house design/interior approval and storage;
- map instance allocation;
- House server routing and population;
- item/spell permissions in private rooms;
- return-home teleport destination;
- offline invitation handling.

Shared protocol candidates:

- transfer to/from House server;
- enter house/room request;
- rent renewal request;
- guest add/remove/invitation notification;
- house design request/status;
- return-home action;
- item/spell use denial based on house flags;
- room/map object state updates.

## String And Data Search Leads

Search locally for:

- web/domain terms: `inns.nexustk.com`, `In-room pages`, `room pages`;
- server terms: `House server`, `Login server`, `Nation server`, `Event server`;
- house terms: `house`, `House`, `New interior`, `custom room`, `custom room design`, `house design`;
- inn/rent terms: `Inn`, `Innkeeper`, `Guest`, `rent`, `renew rent`, `live in your house`;
- home behavior: `Return home`, `wake up`, `home`, `trapped`;
- item rules: `potions and scrolls`, `yellow scroll`, `scrolls`, `potions`;
- private spaces: `clan hall`, `clan room`, `subpath area`, `tavern`, `hall`, `room`.

## Open Questions

- Open-question pass 2026-05-24: public sources confirm in-room web pages as an official community surface and House/server status vocabulary as public web context, but do not prove client-side House server routing beyond normal map/server transfer handling.
- Open-question pass 2026-05-24: the current in-room web catalog answers the public URL/schema side: 2,999 visible plot rows, nine towns, `Pointer.pl` URL grammar, and 37 public interior design codes. It does not expose owners, rent state, guests, storage, custom per-player decorations, or packet formats.
- Open-question pass 2026-05-24: house/inn interiors, item restrictions, guest/rent behavior, and in-room page generation remain local/server-web split questions. Public pages are vocabulary and timeline leads, not resource-layout proof.
- Open-question pass 2026-05-24: exact house/inn-system era must be pinned after the local client version is known; archives can then be filtered to the matching period.

- Does the target client contain House server routing logic or only generic map-transfer handling?
- Are custom interiors stored as map resources, server object layouts, or both?
- Does the client enforce any house item/spell restrictions locally, or only display server denials?
- Are web in-room pages generated from the same data as in-game houses?
- Which era of house/inn-system behavior matches the target binary?

## Sources

- [Official NexusTK community page](https://www.nexustk.com/community.html)
- [NexusTK in-room page root](http://inns.nexustk.com/)
- [NexusTK Masan plot list](http://inns.nexustk.com/plots/Masan.html)
- [NexusTK small room designs](http://inns.nexustk.com/rooms/SmallB.html)
- [NexusTK medium room designs](http://inns.nexustk.com/rooms/MediumB.html)
- [NexusTK large room designs](http://inns.nexustk.com/rooms/LargeB.html)
- [NexusTK Masan pointer example](http://inns.nexustk.com/plots/Pointer.pl?map=Masan&x=59&y=132&size=Large&plot=050733)
- [Nexus Atlas server status](https://www.nexusatlas.com/serverstatus.php)
- [Nexus Atlas main page](https://www.nexusatlas.com/)
- [Nexus Atlas January 2003 archive](https://www.nexusatlas.com/archives/mainpage-archive-1-2003.php)
- [Nexus Atlas July 2003 archive](https://www.nexusatlas.com/archives/mainpage-archive-7-2003.php)
- [Nexus Atlas July 2004 archive](https://www.nexusatlas.com/archives/mainpage-archive-7-2004.php)
- [Nexus Atlas August 2003 archive](https://www.nexusatlas.com/archives/mainpage-archive-8-2003.php)
- [Nexus Atlas 6.0 map/cave listing](https://www.nexusatlas.com/60atlas/list.php)
- [Nexus Atlas 6.0 Buya map](https://www.nexusatlas.com/60atlas/buya.php)
- [Nexus Atlas 6.0 Kugnae map](https://www.nexusatlas.com/60atlas/kugnae.php)
