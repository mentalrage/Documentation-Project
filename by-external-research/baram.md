*** UID:0000GK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Korean Baram / Kingdom Of The Winds Lineage And Feature Delta

Research date: 2026-05-24

Scope: online-only research on the Korean parent game usually romanized as Baram-ui Nara / The Kingdom of the Winds, with emphasis on facts that may explain why NexusTK client assets, strings, or systems diverge from the current North American service. This is not binary-confirmed evidence.

Confidence: mixed. High confidence for Guinness, Nexon, and current Nexon Korea guide/update-history claims. Medium confidence for NexusWiki lineage notes and fan/community interpretations.

## Executive Summary

The North American NexusTK service is a localization/branch of Nexon's Korean Baram / The Kingdom of the Winds line. Public sources consistently describe the Korean game as launched in Korea on April 5, 1996, inspired by Korean mythology and Kim Jin's graphic novels, and as a long-running graphical MMORPG. The Korean service is still active under Nexon Korea and has accumulated many systems absent from, or only weakly reflected in, the public US NexusTK documentation.

For reverse engineering, treat Korean Baram as the upstream design family, not as a direct match to the target client. Names, map art, class structure, UI affordances, and protocol assumptions can share ancestry, but the Korean service has decades of updates that may not exist in the old or current US client.

## Historical Anchors

- Guinness World Records identifies "Nexus: The Kingdom of the Winds" as the longest running MMORPG record holder as of October 31, 2022, and states that it first launched in Korea on April 5, 1996. It also notes Korean mythology, Kim Jin's graphic novels, ancient-Korea-inspired zones, and community roles such as judge or teacher.
- Nexon's 2022 press release for The Kingdom of the Winds: Yeon says the PC game launched in April 1996 as Nexon's first PC game and was recognized as the world's first graphic MMORPG. It also states that the 2011 Guinness listing was for "longest-running commercial graphical MMORPG."
- A 2013 Korean press report on the Nexon Computer Museum says the museum planned to restore the initial version of Baram. It describes the 1996 service, 18 million cumulative members, 130,000 peak concurrent users, and the point that the live service had changed from the early version through new systems and content.
- A 2026 Korean press report says Baram reached its 30th anniversary, that the first day of service began with one user, that 2005 peak concurrency reached 130,000, and that 2021 cumulative registered users surpassed 26 million.
- NexusWiki says BARAM was licensed for US release in 1996 and retitled Nexus: The Kingdom of the Winds for the Western audience. It says NexusTK went commercial in 1998 and that the 2005 KRU transition included US rights to the BARAM 6.0 client. Treat this as fan-maintained but highly relevant.

## Current Korean Service Surface

The Korean official site is a modern live-service portal, not a simple legacy client page. Current visible navigation includes news, events, Baram patch notes, official guide, rankings, cash shop, community boards, clan/guild areas, support, probability item disclosures, Nexon Open API, and social links.

Current home page evidence from May 2026 shows:

- Active 30th anniversary merchandising/event promotion.
- Direct "download" and "patch" buttons.
- Current notices and weekly update posts.
- Cash shop items and membership-style products.
- Community and Q&A surfaces.
- Official "Baram library" guide pages.

The current Korean service therefore looks much closer to a modern MMO platform wrapper than the current NexusTK US website, which primarily exposes installer, account, guide, and news surfaces.

## Korean Old-Graphics / Compatibility Mode

The Korean service has an official old-graphics mode, but the public evidence places it in a modern Baram update rather than in the 1998-2005 US NexusTK client lineage.

The key launch point is the July 23, 2020 "Back to the Baram" update. Nexon's official promotion page says the update added an old-version graphics mode, wide-resolution support, new servers, free conversion of several functional cash items, and related events. The same page says that when old-version graphics mode is selected, NPCs, monsters, backgrounds, and similar objects that have past graphics are displayed with old-version designs. It also says players using different graphics options can play together on the same server, and that existing servers can use the old-graphics mode.

An official July 23, 2020 update notice gives the in-client access path:

- Open the bottom menu button or press `Alt+X`.
- Click the settings icon at the bottom of the menu.
- Alternatively, press `F10` directly.
- In settings, open Options > Screen and select the desired graphics mode.

The current official environment-settings guide still documents graphics-mode selection as part of the settings surface. Its screen section lists four graphics modes:

| Translated mode | Meaning |
| --- | --- |
| Old-version normal | Old graphics in the normal viewport/resolution family. |
| Old-version wide | Old graphics in the wide viewport/resolution family. |
| New-version normal | Modern graphics in the normal viewport/resolution family. |
| New-version wide | Modern graphics in the wide viewport/resolution family. |

The official 2020 pages and current guide imply this behavior:

- It is a client-side presentation choice on the live service, not a separate classic ruleset.
- It can be used on existing servers.
- Players in old/new graphics modes can coexist on the same server.
- The server can keep the same world state and object identity while clients choose different art for the same things.
- It is bounded by asset availability: official wording repeatedly limits old rendering to NPCs, monsters, backgrounds, and similar objects that actually have historical graphics.
- It supports both old/new art selection and normal/wide presentation choices. The launch promotion calls out four total resolution/graphics combinations.
- It is configured from the normal settings UI, alongside other modern options such as window/fullscreen mode, visual effects, sound, controls, tile-data optimization, and shortcut settings.

What it can do:

- Display restored old-style artwork for supported NPCs, monsters, backgrounds, and other categories where Baram has an older asset variant.
- Let nostalgic players use older-looking art while remaining on modern Korean Baram servers.
- Let old-mode and new-mode users play together without server separation.
- Combine old art with the wide client viewport where supported.
- Leave gameplay systems, account state, trading, events, classes, promotion tiers, and live-service content available because this is not presented as a legacy server.

What it cannot be assumed to do:

- It is not evidence that the Korean service restored the complete 1998-2005 client renderer, protocol, UI, map files, gameplay balance, class systems, or server rules.
- It is not evidence that every object has an old graphic. The official pages explicitly scope the feature to objects with past graphics.
- It is not evidence that US NexusTK inherited the same 2020 feature.
- It is not evidence that the old graphics are exactly the same as the US 1998-2005 asset set. Korean Baram and US NexusTK shared ancestry but diverged for decades.
- It does not by itself imply old bugs, old screenshot behavior, old input behavior, old map dimensions, old pathing, or old animation timing.

Known limitations from public user reports:

- A Korean BaramKin user asked shortly after the 2020 update when unrestored old-version graphics would be restored, listing missing old-style spell visuals, bat graphics, item sparkle effects, and old Infinite Arena clothing/color appearances. This is not official confirmation, but it is useful negative evidence: at least some players saw the 2020 restoration as incomplete.
- The official July 2020 update details also said old-graphics support for some website/profile and cash-shop preview surfaces would be provided later. That means the launch state was not fully consistent across every presentation surface.

Reverse-engineering implications:

- If a modern Korean Baram client is inspected, expect a graphics-mode setting, old/new asset selection tables, and fallback behavior when old artwork is absent.
- Mixed-mode same-server play strongly suggests that object IDs, character state, NPC identity, and map identity are not forked by the old-graphics mode. The fork is likely in resource lookup and rendering selection.
- The mode is valuable as proof that Baram-family clients can carry dual art paths for the same live object model.
- It should not be used to rename 1998-2005 US NexusTK code unless local strings, resources, or control flow confirm the same mechanism.

## Current Feature Categories From Official Korean Guide

The official Korean guide index is valuable because it names whole systems in one place. It includes the following broad areas:

- Beginner systems: update history, new-player support rewards, vouchers/tickets, item binding/sealing, level conquest boxes, returning-player products, storage/container usage.
- Classes, magic, and equipment: class/magic basics, 1st through 9th promotion paths, and 11 class introductions.
- Combat and growth: combat prep, growth prep, combat efficiency, rest experience, consumable/medicine efficiency, events, family guardian temple, hunting fatigue, recommended hunting grounds by level.
- Item acquisition: golden bowl, costume synthesis, mining, pumpkins.
- Ability/item enhancement: status effects, major stats, item dismantling/enhancement, production enhancement, item engraving, bonus potential abilities, post-700 stat changes, internal-power enhancement, soul enhancement, divine-power opening, body enhancement.
- PVE content: Hero's Path, celestial ranking records, multiple named challenge modes and raids including Hwangsanbeol, Susanoo, Akgwimun, Ansi Castle, Samcheondaecheon world, and recent "Gwaeryeok Nansin" category.
- PVP content: battlefield, northern victor/king, endless war.
- Non-combat content: play rooms, exploration journal, archaeology, achievements, production, housing, Baram chronicle, seasonal village, dye/tanning, costume rental, fantasy island treasure, hero memory, storage systems, costume room, monster journal.
- Summon/pet-like systems: "hwan-su" UI, raising, activation, transcendence/awakening, equipment.
- Clan/family systems: family, family duel, clan UI, clan activities/benefits, clan gifts, upper clan base/fishing.
- Trade/cash/community: one-to-one trade, item exchange, cash shop, friends, groups, group finder, chat, Baram plaza.

This catalog is the clearest public sign that Korean Baram has moved far beyond the US NexusTK feature set described by KRU and Nexus Atlas.

## Current Korean Progression Scale

The Korean guide's recommended hunting-ground page starts by saying characters under level 600 should follow Hero's Path. Its visible high-level table then ranges from level 600 through level 940, with recommended combat power and group sizes of 1-3 for many hunting grounds.

Examples from the table:

- Level 600: Bongnae Mountain Depths, recommended combat power 15,000.
- Level 700: Danseok Cave, recommended combat power 20,000.
- Level 800: Ganges River - Vishnu Ruins, recommended combat power 46,000.
- Level 900: Seorabeol residential district, recommended combat power 96,000.
- Level 940: Silla Palace secret room, recommended combat power 108,000.

This is a major delta from US NexusTK public guides, where level 99 and post-99 stat/experience exchange remain central vocabulary. Korean Baram's modern data model likely contains level, promotion tier, combat power, region unlocks, daily fatigue counters, and equipment-enhancement statistics that should not be assumed present in the US target.

## Current Korean Automation And Convenience Systems

The official Korean auto-hunting guide states that auto-hunting and automatic item use exist as convenience systems. The visible requirements and limits include:

- Auto-hunting is available to characters with 6th promotion and level 600+.
- It is launched from a lower menu auto-hunting button.
- It is restricted to one character at a time across same account/identity/IP/PC.
- It is limited to four hours per Nexon ID per day, resetting at midnight.
- It consumes the same hunting-area fatigue as manual hunting.
- It cannot be used while grouped.
- Direct player input can still occur while auto-hunting is running.
- Equipment durability reaching zero stops auto-hunting.

This is a strong example of a Korean-only or Korean-modern feature family. It implies modern client state for automation mode, daily counters, fatigue tracking, durability checks, and UI menu buttons. Do not project this into NexusTK unless local evidence exists.

## Current Korean Economy And Trade

The official Korean item-exchange guide says Baram has an item exchange accessible from the lower-right game menu through Menu (Alt+X) > Exchange. It also says keyboard shortcuts can be configured under settings (F10), that buying/selling requires a safe Nexon OTP security grade, and that the exchange has normal and integrated/cross-server exchange modes.

Delta against US NexusTK:

- US public documentation emphasizes direct trade, shops, item shop/Kruna, and player economy practices.
- Korean Baram has a documented exchange UI, integrated exchange, security-gated buying/selling, item search, category search, and auto-complete search vocabulary.
- If the US target contains exchange-like UI strings, they may be inherited from later upstream Baram or from unrelated local additions; confirm before naming.

## Current Korean Update History As A Feature Map

The official Korean update-history guide provides a compact year-by-year feature list from 2002 onward. This is especially useful as a system vocabulary index:

- 2002: Jumong server, China continent, Nakrang server, 4th promotion and Dosaksan.
- 2003: memorial item, Fantasy Island, Bonghwang service, graphics renewal and Baekdu Mountain.
- 2004: minimap, Jumong escort battle, traditional wedding, siege-war renewal.
- 2005: new Archer class, pricing model revision / flat-fee abolition, housing and production.
- 2006: Gwimundong, 10th anniversary, hwan-su.
- 2007: rest experience, character deletion system, Baram chronicle part 1.
- 2008: hell update, duel and hall of fame.
- 2009: 5th promotion, technical training, new dungeons.
- 2010: Hero Battle, Baekje, Guinness listing, new server and battlefield.
- 2011: Nexon ID login, Cheonin class, divine-beast transformation.
- 2012-2014: service center, hero characters, world map overhaul, Chinese fortress, Baekje prosperity, invasion war, behavior combinations, item engraving renewal, server integration, Baram 1996 restoration, growth clan hunting grounds, divine-beast transformation renewal, Geumcheon region.
- 2015-2018: many dungeons, 6th and 7th promotions, housing medicine manufacture, damage meter, quest navigation, item comparison, quickslots, custom hotkeys, item breakdown/enhancement, marker system, production renewal, max-level expansions, combat power, smart targeting, raids, growth engraving, new classes including Madosa, Youngsulsa, Chasa.
- 2019-2024: repeated UX, UI, combat-power, raid, exchange, family, auto-hunt, class remaster, enhancement, pet/summon, equipment, and content-structure updates.

For reverse engineering, this list is less about exact parity and more about search vocabulary. Korean-origin strings for "quickslot", "custom shortcut", "minimap", "item comparison", "marker", "smart targeting", "combat power", "exchange", "auto hunt", "family", and "fatigue" are plausible in later Baram-family code, but are not expected in a 1998-2005 US client unless backported.

## Korean Version Versus US NexusTK

Known divergence categories:

- Business model: Korean history includes flat-fee abolition in 2005 and modern cash shop/membership products; US NexusTK remains framed as free to level 49 with paid account continuation on official KRU pages.
- Class count: Korean current guide advertises 11 classes and 1-9 promotion coverage. US public guides are centered on four base paths and PC/NPC subpaths.
- Progression: Korean current guide references level 600+ and level 900+ hunting areas, combat power, fatigue, and Hero's Path. US public docs center level 99, marks, karma, subpaths, clans, and post-99 vitality/mana exchange.
- UI: Korean current guide documents configurable shortcuts, exchange UI, group finder, modern guide/help surfaces, quickslots, and menu buttons. US official guide is keyboard-heavy and legacy in style.
- Content geography: Korean update history includes China, Baekje, India, Silla, Baekdu, hell, and many raid/challenge regions. US NexusTK geography is narrower and documented through Koguryo, Buya, Nagnang, Wilderness, Mythic, Vortex, and related areas.
- Automation: Korean current auto-hunting has explicit daily limits and fatigue behavior. This is not part of the US official NexusTK guides reviewed.

## Implications For Local Analysis

Useful search and classification leads:

- Upstream/client-version terms: Baram, BARAM, Kingdom of the Winds, 6.0 client, Nexus 5.31, Nexus 5.32, NexusTK 7.52.
- Korean-modern concepts that might appear only in newer assets: auto hunt, item exchange, integrated exchange, combat power, fatigue, quickslot, custom hotkey, marker, smart targeting, family, hwan-su, engraving, item potential, body/soul/internal-power enhancement.
- Shared old-family concepts likely to overlap: tile maps, top-down/isometric-ish 2D presentation, map/stable UI, legend marks/icons, who list, friend/group/chat, item/equipment lists, spell lists, faces, portraits, music/sound system, screenshot capture.
- Do not rename US classes or systems directly from Korean modern pages unless the local binary or US public docs confirm the term.

## Sources

- [Guinness World Records: Longest running MMORPG](https://www.guinnessworldrecords.com/world-records/88203-longest-running-massive-multiplayer-online-role-playing-game-mmorpg)
- [Nexon 2022 release for The Kingdom of the Winds: Yeon](https://pdf.irpocket.com/C3659/BbNL/qjAh/EW1b.pdf)
- [Khan 2013 report on Nexon Computer Museum restoring the early Baram version](https://www.khan.co.kr/article/201307081400261)
- [Khan 2026 report on 30th anniversary](https://www.khan.co.kr/en/article/202604061610047)
- [Official Korean Baram home page](https://baram.nexon.com/)
- [Official Korean Baram Back to the Baram 2020 intro](https://baram.nexon.com/E200723/Intro)
- [Official Korean Baram July 23 2020 old-graphics update notice](https://baram.nexon.com/Notice/List/1/130978)
- [Official Korean Baram July 23 2020 update details / old-graphics FAQ](https://baram.nexon.com/Notice/List/64/130974)
- [Official Korean Baram guide index](https://baram.nexon.com/GameGuide/Index)
- [Official Korean Baram environment settings guide](https://baram.nexon.com/GameGuide/View/25)
- [Official Korean Baram update history](https://baram.nexon.com/GameGuide/View/3)
- [Official Korean Baram auto-hunting guide](https://baram.nexon.com/GameGuide/View/97)
- [Official Korean Baram recommended hunting grounds](https://baram.nexon.com/GameGuide/View/171)
- [Official Korean Baram item exchange guide](https://baram.nexon.com/GameGuide/View/70)
- [Korean BaramKin old-graphics restoration Q&A](https://baram.nexon.com/BaramKin/View/8961?aSeq=21425)
- [NexusWiki: KRU Interactive](https://nexuswiki.com/wiki/KRU_Interactive)
- [NexusWiki: BARAM](https://www.nexuswiki.com/wiki/BARAM)

## Open Questions

- Open-question pass 2026-05-24: the Korean old-graphics mode is publicly answered at the feature level: launched July 23, 2020, still documented in current Korean settings, and scoped to old graphics where old assets exist. Full asset coverage remains unresolved; a Korean BaramKin report shortly after launch listed missing old graphics/effects.
- Open-question pass 2026-05-24: all questions about inspected local US client builds, local version strings, and BARAM 6.0 executable/resource boundaries are local binary/resource questions, not answerable from Korean public pages alone.
- Open-question pass 2026-05-24: do not merge Korean Baram 2020 old/new graphics mode with NexusTK 6.5 high/low-resolution support unless local strings or resource paths prove a shared mechanism.

- Whether any inspected local client build includes Korean Baram-origin strings, asset container names, or version numbers.
- Whether the target binary is closer to pre-5.31, 5.31/5.32, 6.0, or another US-specific branch.
- Whether KRU's "BARAM 6.0 client" reference maps to a concrete executable/resource format boundary visible in local artifacts.
- Whether Korean old-graphics mode has since achieved full old-asset coverage, or still falls back for spells, items, monsters, and preview surfaces when no old asset exists.
- Whether any local US client branch contains an old/new graphics-mode flag similar to Korean Baram 2020, or only the earlier NexusTK 6.5 high/low-resolution transition path.
