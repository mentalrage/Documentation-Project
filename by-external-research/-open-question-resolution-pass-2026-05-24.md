*** UID:0000GH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Open-Question Resolution Pass, 2026-05-24

Scope: first pass over existing `by-external-research` documents to answer or narrow open questions using public online sources. This is still external research only; questions about the local target executable, DAT contents, packet fields, or exact client/server ownership require local binary/resource inspection.

Confidence: medium. Official KRU/NexusTK help and download pages are strong for current public behavior. Nexus Atlas archives are useful dated evidence, especially when they quote reset/client patch notes, but remain fan-maintained unless the archive explicitly identifies official reposts.

## Public Answers And Narrowed Questions

### Current public client endpoint

The current official download page exposes `Nexus TK 7.52 (227MB)`, a minimum resolution of `1024x768`, updater repair downloads, `.NET Framework 3.5` guidance, `MSVCR100.dll` / Visual C++ 2010 redistributable guidance, and launch text naming the `NexusTK` desktop icon and `NextAeon` Start Menu entry.

This answers the current public-client endpoint, but it does not identify the local target binary. Public sources give dated anchors for comparison: the 2003 official reference page describes a 50.5 MB client with Win95/98/2000/ME/XP and DirectX 7/8 requirements; Nexus Atlas reports Nexus 6.5/6.59 in 2005-2006 and Nexus 6.90 in April 2011.

### Key binding and option model

Official Basic Keys prove that the current client has a large fixed keyboard surface, but also that some behavior is option/hotkey driven:

- `F10` opens Options.
- `F11` opens Hotkey setting.
- the guide homepage says old/new `F1` behavior is controlled from the Options tab.
- `Shift+F11` toggles Tab/V swap, with old Tab behavior when off.
- `Shift+F12` toggles click-to-move.

This narrows key-binding questions: the current public client is not purely hard-coded from the user's perspective. The exact target binary still needs local inspection to decide which keys are fixed dispatch, configurable hotkeys, or server-provided labels.

### Verbal commands and NPC/shop/bank grammar

Official Verbal Commands treats banking, shop, repair, quest, travel, clan, group, subpath, whisper, report, novice, roll, and shout commands as typed/sayable text. It explicitly says many say commands can be put into Say macros if the text is short enough.

This strongly supports a text-command user model and explains why many shop/bank/subpath commands should be searched as literal strings. It does not prove whether the client sends raw speech text, a structured command packet, or both. That split remains local/protocol work.

### Slash command channel surface

Current official Verbal Commands includes `/report`, `/novice`, `/n`, and `/tutor`, but not `/justice` or `/tutors`. Nexus Atlas 2020 archive research documents `/tutors`, `/justice`, `/novice`, and `/report` as distinct help/report routes in that period.

This narrows the channel-timeline question: `/justice` and plural `/tutors` appear to be later public-service routing additions than the current official command baseline page captures, or at least documented through archive reports rather than that page. Their presence in the target build still needs local string/protocol evidence.

### Screenshot behavior by era

Current official Basic Keys says:

- Scroll Lock captures PNG.
- Shift+Scroll Lock captures BMP.
- Ctrl+Shift+3 captures BMP.

Nexus Atlas January 2006 archive evidence described older screenshot behavior around JPG/BMP output. Therefore screenshot format behavior is era-specific. Do not assume modern PNG output when documenting a 5.x/6.x target client, and do not assume 2006 JPG/BMP behavior for current 7.52.

### FaceMaker and portrait handling

The official FaceMaker page says FaceMaker is a separate portrait-maker utility for registered characters, asks the user to select/crop an image, presents a list of characters used on the computer, and saves the portrait to the correct location and format. It does not publicly reveal the exact path or file format.

This answers the public workflow and confirms a local character-aware file placement step. It does not answer the binary-format or path question.

### Registration gates

The current official download page says a trial character can play to level 49, and registration unlocks custom portrait/profile, clans, longer quests, all bulletin boards, subpaths, more spells/items/maps, intelligent monsters, and Elixir War.

This answers the public feature-gate list. It does not prove whether each gate is client-visible before server rejection, server-only, or both.

### Boards, mail, and web mirrors

Official Basic Keys exposes `b` for bulletin boards, `p` for post, and `Shift+m` for mail. The official Carnages help page and live board mirror prove at least the Carnage board has a web-readable mirror. This pass did not find a public index proving which other in-game boards have live mirrors.

Treat "which boards are mirrored" as partially answered: Carnage is confirmed; other board mirrors need targeted URL discovery or current site enumeration.

### Subpath-service provenance

Official Subpath Quests & Services says its service data was taken directly from Subpaths Board material and provided by the Elder/Guide of each subpath. That answers a major provenance question: many service names are board/social/community terms before they are proven game-client strings.

This does not prove whether individual service names appear in the local client, in server dialogue, in board text only, or in legend/profile output.

### Current clan and subpath lists

Official Clans of the Kingdoms gives a current documented clan list by kingdom. Official Subpaths gives the current documented PC/NPC subpath list by base path. These are good current-name sources.

They do not answer target-era membership. Exact clan/subpath availability for a 1998-2005 or 6.x target must be tied to archives and local strings.

### Time, leveling, and status display

Official Time Conversion says Nexus time runs eight times faster than real time and gives conversion examples. Official Leveling says levels 1-99 use experience, `Next Level` appears under the second status tab page, experience is displayed in the bottom-right bar under Vita/Mana, and post-99 experience is exchanged at a Midnight Weaver for MGT/GRC/WIL, Vita, or Mana.

This answers public behavior and UI vocabulary. It does not prove whether the client computes time locally or receives time/status panels from the server.

### Inventory and durability public patch anchor

Nexus Atlas April 2011 reports Nexus 6.90 auto-patch changes: default inventory size expanded from 26 to 27, item-shop inventory expansion could reach 52, and durability notices moved to the text box at 50%, 25%, 10%, 5%, and 1%.

This gives dated constants and message-routing leads. It does not prove the local target has those constants unless the target is 6.90-era or later.

### Old/high-low graphics compatibility

Nexus Atlas 6.5/6.59 evidence shows NexusTK had high-resolution and low-resolution/earlier-client-view support around 2005-2006. Korean Baram separately added an official old-graphics mode on July 23, 2020. These are distinct compatibility stories and should not be merged without local evidence.

No public removal notice for NexusTK low-resolution/earlier-client-view support was found in this pass.

### In-room pages and house website

The official community page links `In-room pages` to `http://inns.nexustk.com`. Direct research of that host answers the public web-schema side of the housing questions:

- root page title is `Nexus Inn Room Plot List`;
- nine town pages under `/plots/<Town>.html` expose plot number, size, location, and coordinate pointer links;
- current public catalog has 2,999 plot rows: 1,481 small, 950 medium, and 568 large;
- pointer URLs use `/plots/Pointer.pl?map=<Town>&x=<X>&y=<Y>&size=<Size>&plot=<PlotId>`;
- current design catalog has 37 design codes: 14 small, 12 medium, and 11 large;
- medium houses can use small or medium interiors, while large houses can use small, medium, or large interiors;
- current designer names are Releen, Dok-Sin, Filnoos, and Altree.

Nexus Atlas July 2003 anchors `inns.nexustk.com` as the house website for new designs, and July 2004 shows the `Pointer.pl` endpoint used as a public house direction URL.

This resolves the public surface inventory, but not the local ownership questions. The public site does not expose owners, rent expiry, guests, current occupants, storage, private custom state, item/spell rules, or packet fields. Whether the target client opens the site or shares only in-game house vocabulary remains local binary/protocol work.

## Questions Still Local-Only

The following open-question classes were not answerable from public web sources and should be routed to local binary/resource/protocol work:

- which exact public client era matches the local target binary;
- whether strings are compiled into the executable, loaded from resources/DATs, or server-fed;
- whether spells, item records, monster/drop tables, cave gates, recipe data, map names, and event content are client-local or server-owned;
- whether key/slash/verbal commands are parsed locally, sent as raw text, or converted to structured packets;
- whether board/mail/profile/parcel flows share UI windows or protocol states;
- whether legend marks are structured client records or server-sent text blocks;
- whether map collision/tile blocking is local, server-side, or mixed;
- whether temporary event maps/resources remain in local DATs after event closure;
- whether role-specific Archon/Judge/Carnage-host tooling exists in the target client;
- whether high/low-resolution or old/new graphics support remains dormant in current NexusTK 7.52.

## Documents Updated By This Pass

- `archive-news-reset-event-mining-methodology.md`
- `baram.md`
- `carnage-pvp-hosted-event-rules-and-board-model.md`
- `character-progression-paths-subpaths-and-spells.md`
- `client-install-interface-and-commands.md`
- `communication-help-justice-and-authority-channels.md`
- `community-web-account-board-and-profile-surfaces.md`
- `crafting-skills-resources-and-creation-system.md`
- `economy-banking-trading-kruna-and-market-model.md`
- `events-resets-temporary-content-and-live-news-model.md`
- `full-update-history.md`
- `gameplay-systems-crafting-quests-carnage-and-community.md`
- `graphics-rendering-patches-and-asset-evolution.md`
- `housing-rooms-inns-and-private-space-model.md`
- `in-room-pages-and-inns-web-schema.md`
- `hunting-caves-monsters-and-experience.md`
- `items-equipment-and-resource-databases.md`
- `justice-law-crime-punishment-and-evidence-model.md`
- `map-atlas-coordinate-area-and-travel-catalog.md`
- `news-archive-timeline-and-client-change-notes.md`
- `old-client.md`
- `quest-dialog-killtrack-and-progression-scripts.md`
- `social-governance-law-and-legend-systems.md`
- `spell-ability-status-and-targeting-model.md`
- `subpath-services-legend-marks-and-roleplay-model.md`
- `time-calendar-karma-and-status-model.md`
- `world-map-location-and-resource-model.md`

## Sources

- [Official NexusTK download page](https://www.nexustk.com/download_2.html)
- [Official NexusTK FaceMaker page](https://www.nexustk.com/download_3.html)
- [Official 2003 NexusTK reference/download page](https://www.nexustk.com/2003/ref/5/index5.html)
- [Official help wiki homepage](https://help.nexustk.com/)
- [Official help: Basic Keys](https://help.nexustk.com/wiki/wiki/7/basic-keys)
- [Official help: Verbal Commands](https://help.nexustk.com/wiki/wiki/40/verbal-commands)
- [Official help: Leveling](https://help.nexustk.com/wiki/wiki/62/leveling)
- [Official help: Time Conversion](https://help.nexustk.com/wiki/wiki/71/time-conversion)
- [Official help: Clans of the Kingdoms](https://help.nexustk.com/wiki/wiki/16/clans-of-the-kingdoms)
- [Official help: Subpaths](https://help.nexustk.com/wiki/wiki/17/subpaths)
- [Official help: Subpath Quests & Services](https://help.nexustk.com/wiki/wiki/87/subpath-quests-services)
- [Official NexusTK community page](https://www.nexustk.com/community.html)
- [NexusTK in-room page root](http://inns.nexustk.com/)
- [NexusTK Masan plot list](http://inns.nexustk.com/plots/Masan.html)
- [NexusTK small room designs](http://inns.nexustk.com/rooms/SmallB.html)
- [NexusTK medium room designs](http://inns.nexustk.com/rooms/MediumB.html)
- [NexusTK large room designs](http://inns.nexustk.com/rooms/LargeB.html)
- [NexusTK Masan pointer example](http://inns.nexustk.com/plots/Pointer.pl?map=Masan&x=59&y=132&size=Large&plot=050733)
- [Nexus Atlas July 2003 archive](https://www.nexusatlas.com/archives/mainpage-archive-7-2003.php)
- [Nexus Atlas July 2004 archive](https://www.nexusatlas.com/archives/mainpage-archive-7-2004.php)
- [Nexus Atlas April 2011 archive](https://www.nexusatlas.com/archives/mainpage-archive-4-2011.php)
