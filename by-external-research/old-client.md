*** UID:0000H4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Old NexusTK Client Era, 1998-2005

Research date: 2026-05-24

Scope: online-only report on the North American NexusTK client era from commercial launch through the KRU transition. The original todo mentioned checking local code/IDA; that is intentionally deferred because this directory is external research only.

Confidence: medium. Official pages give current packaging and current/legacy guide behavior. Nexus Atlas archives preserve period reports, often including official reposts, but are fan-maintained. NexusWiki lineage notes are useful but should be confirmed against local binaries before they drive names.

## Executive Summary

The public record for the 1998-2005 US client shows a keyboard-driven Windows MMORPG client with 2D tile graphics, local resource packs for faces/items/armor/music/maps, automatic patching, and a close relationship to Korean Baram client versions. The clearest dated technical anchor is the January 2003 Nexus 5.31/5.32 transition, which Nexus Atlas reports as a major client refresh involving new faces, new item/armor/weapon graphics, a revised sound system, a revised map/rendering system, and fixes for screenshot, refresh, and home bugs. By 2005, the US service had become KRU Interactive and fan-maintained sources say the US rights involved the BARAM 6.0 client.

The specific old-rendering-support question has a narrower answer. Public Nexus Atlas evidence says Nexus 6.5 introduced dramatically different high-resolution graphics while still giving players an option to view the game as it appeared in earlier clients. December 2005 and January 2006 patch reports then refer separately to high-resolution and low-resolution clients, proving that the compatibility path was still active around the 6.58/6.59 patch family. I did not find a public source that states when, or even whether, this old/low-resolution rendering support was later removed.

For reverse engineering, the key client-era boundaries are likely:

- Pre-commercial/beta and 1998 "gold" US service.
- Pre-5.31 old-graphics/older-map client.
- January 2003 5.31 and 5.32 patch family.
- 2004 Vortex/content/art expansion period.
- 2005 KRU transition and probable 6.0-era branch.
- October 2005 Nexus 6.5 high-resolution graphics transition with an option to view the game like earlier clients.
- December 2005/January 2006 6.58/6.59 patch family, where public notes still mention both high-resolution and low-resolution client behavior.

## Public Release And Platform Evidence

MobyGames lists Nexus: The Kingdom of the Winds as a 1998 Windows release, developed by Nexon Corporation and published by Nexon, Inc. It classifies the game as top-down, anime/manga styled, persistent, and massively multiplayer.

NexusWiki says the US release came from licensing BARAM in 1996 and retitling it for the Western audience. It says NexusTK went commercial in 1998, becoming pay-to-play, and associates that release with the in-game "Great Shift" event. Because this is a fan wiki, use it as a historical lead, not final proof.

The current KRU official download page is much later but still useful as an endpoint:

- The current downloadable client is labeled Nexus TK 7.52 and is 227 MB.
- The page says the game requires minimum resolution 1024x768.
- It provides a full installer, .NET Framework 3.5 dependencies, Visual C++ 2010 redistributable dependencies, and separate updater repair downloads.
- The page states that launching uses a NexusTK desktop icon or "NextAeon" from the Start Menu.
- Trial play reaches level 49; paid registration opens portraits/profiles, clans, longer quests, boards, subpaths, spells/items/maps, intelligent monsters, and Elixir War.

This current page should not be projected backward wholesale, but it confirms the long-lived Windows installer/updater lineage.

## Input And Interface Model

The official KRU basic guide describes a keyboard-centric client:

- Speech with apostrophe.
- Whisper with double quote.
- Look, pick up, attack, use/equip/eat/read/write, inventory, open door, hand item, status, take off.
- Combined-key actions for pick up all, shout, change magic order, drop all, group status, hand all, fast magic, fast speech, remember chat, realm-center view adjustment, clairaudience, volume, ignore, options, sense heroes, and leave kingdom.
- Status view exposes path, weapon, armor, helm, hand items, vitality, mana, hit probability, damage, armor class, and next-level experience.

For old-client analysis, expect command dispatch and UI state to be tightly tied to keyboard events, modal lists, inventory letters, and direct tile adjacency checks.

## January 2003 Nexus 5.31 Client Refresh

Nexus Atlas January 2003 archive gives the strongest old-client technical evidence found so far.

On January 22, 2003, Nexus Atlas reposted official news saying a new client was coming after months of waiting. Reported features:

- Four new faces for character variation.
- New weapon, armor, and item images for future quests/events.
- A totally new sound system with improved music and new options.
- A revised map system intended to render faster/smoother and improve map functionality.
- Fixes for known "screenshot", "refresh", and "home" bugs.
- Advance download before the patch.

Another January 2003 archive entry says Yin provided an early Nexus 5.31 download:

- Full client size: 50.5 MB.
- Automatic patching was being checked.
- Patch size for all changes was around 82 MB, so full download was preferred.

On the apparent 5.31 launch day, fan observations include:

- New Ranger hero icon.
- New map/stable UI.
- New music and CD player.
- New faces.
- Faster walking.
- Pressing "m" to see if new mail exists.
- Seeing a player's totem when clicking them.

The same archive records compatibility and bug fallout:

- 5.31 caused login/map-load crashes for at least some users.
- Screenshots became JPG in one report, irritating players who wanted lossless pixel captures.
- Some spell/equipment lists showed on one line.
- Some hair-color/emotion, who-list, and legend graphics were wrong.
- Music stopped after a while.
- Exiting to the login screen could show a loading image.
- The house server came back, but "New interior" was disabled because it caused crashes.

Shortly afterward, Nexus 5.32 is described as a small patch over 5.31. Listed fixes:

- DirectX 7 requirement for NT users.
- Lists such as spells/items showing on one line.
- Bad legend icon graphics.
- Bad who-list icon graphics.
- Hair dye with emotions.
- Main-map login crashes.

## Screenshot And Evidence Capture Behavior

Screenshots matter because the client had in-game legal/justice uses. Nexus Atlas January 2003 records:

- Justice screenshots had to be taken through the client-supported Scroll Lock method, not external capture.
- A period note says accurate BMP screenshots could be taken by holding Shift, Ctrl, or Alt with Scroll Lock. The wording was uncertain in the fan post, but Shift+Scroll Lock appears repeatedly in later Nexus Atlas data-gathering requests.
- 5.31 reportedly saved screenshots as JPG, creating pixel-quality concerns.

Reverse-engineering implications:

- There may be client code paths for BMP/JPG capture, filename generation, and special modifier handling.
- Screenshot code may interact with cursor rendering and the graphics backbuffer.
- Some versions may have changed screenshot output format.

## Server Stability And Patch Pressure

The January 12, 2003 Nexus Atlas archive says Nexus had experienced "worst server latency since Beta", with slowing, crashes, and difficulty remaining logged in. This is not client proof, but it places the 5.31 rollout in a period of operational pressure.

The September 2003 archive contains an official-style explanation from Delphi after an exploit incident:

- A new feature updated the server code.
- A security check stopped working correctly.
- Players began using resurrect ability in rooms without resurrect NPCs.
- A small group exploited the hole for gold/stats and disruption.
- The issue was said to be fixed and monitored.

This is server-side, but it suggests that client-era feature additions were not purely cosmetic. They affected server checks, abilities, rooms, item/stat integrity, and abuse handling.

## 2004 Vortex And Asset Expansion Context

The July 2004 Nexus Atlas archive preserves an official post by Eldridge around the sixth commercial anniversary:

- It references nearly eight years since the US beta version and 10 years since the original Nexus began in Korea.
- It says recent work had negotiated access to previously unused graphics for Nexus and that these had been slowly added.
- The Vortex / "Mythic 2" area was announced as a new high-level hunting area where Mythic 1 stopped.
- Vortex added 12 caves in three levels, like the original Mythic Nexus.
- The new caves had over 100 new items with new graphics.
- Boss AI used a brand-new system and was intended to be more challenging.

Client relevance:

- The old client needed to display newly-added item graphics and map/tile content.
- If the target resource set has Vortex-era assets, it may postdate or align with the 2004 content push.
- "Unused graphics" may explain assets that seem inherited from Korean Baram or from a shared art pool.

## 2005 KRU Transition

Nexus Atlas March 2005 reports the KRU Interactive spin-off. It quotes a newsletter saying Nexon, Inc. became KRU Interactive, Inc., spun off from Nexon Corporation, and continued NexusTK, Dark Ages, and Shattered Galaxy service. It also says KRU had business rights and more flexibility/autonomy.

The March 31, 2005 archive says the Nexon name remained in use during the transition and that some areas, including support/account manager domains and in-game names/login page, would change gradually, with in-game/login text likely needing a patch.

The May 2, 2005 archive says KRU moved account/support systems to the kru.com domain, leaving Nexon.net behind. It also notes direct support/account URLs and a character/account purge for inactive accounts.

NexusWiki adds the important but fan-maintained claim that in February 2005 NEXON INC. purchased US rights to the BARAM 6.0 client and split from Nexon as KRU Interactive.

Client relevance:

- Around 2005, expect changed branding strings, account/support URLs, and possibly login-page/domain behavior.
- A 6.0-era client boundary is plausible but needs local confirmation.
- Transition-era resource sets might contain both Nexon and KRU names.

## Post-2005 High/Low-Resolution Client Evidence

Nexus Atlas has a dedicated report for Nexus Version 6.5. It describes 6.5 as the largest client change since version 4.0 began and says that although high-resolution graphics were dramatically different, players would have the option to view the game as it appeared in earlier clients. This is the strongest public NexusTK evidence found for an old-graphics or compatibility display mode.

Important boundaries:

- NexusWiki identifies version 6.5 as the current client in use as of a page last edited November 29, 2005, and says it was released by KRU Interactive on October 12, 2005.
- Nexus Atlas December 30, 2005 patch notes, reposted from Nexustk.com, say text color in the high-resolution client became customizable.
- The same December 2005 notes say some armors were updated to high-resolution graphics and show examples described as old on the left and updated on the right.
- The same notes say a bug causing bodies in the low resolution client to show up black was fixed.
- Nexus Atlas January 2006 archive repeats or expands the 6.58/6.59-era patch context, including high-resolution client text color, missing bow animations, armor graphics updated to high-resolution graphics, low-resolution-client black-body fixes, and lighting/effects fixes.
- Another January 2006 patch note says `Control-W` in the low-resolution client no longer caused a crash, and that the dead graphic was updated in the high-resolution client.

What the NexusTK 6.5-era compatibility path appears able to do:

- Preserve an older visual presentation while the newer high-resolution art set was being introduced.
- Let players choose a view closer to earlier clients, according to the 6.5 report.
- Maintain separate high-resolution and low-resolution client behavior, at least enough that patch notes could name bugs in each path independently.
- Render character bodies, armor graphics, dead graphics, bow animations, lighting, effects, and text-color UI through code paths that were not fully identical between high and low resolution.
- Continue receiving fixes after the initial 6.5 launch, because the December 2005 and January 2006 notes still describe low-resolution-client and high-resolution-client bugs.

What this does not prove:

- It does not prove the compatibility path was a complete byte-for-byte old client renderer.
- It does not prove old maps, old protocol, old server behavior, old bugs, or old gameplay balance were preserved.
- It does not identify whether the old view used separate art packs, downscaled art, alternate resource lookup, alternate tile sets, or an independent renderer.
- It does not give a removal date.
- It does not prove that current NexusTK 7.52 still exposes the old/low-resolution mode. The current official download page only states a 1024x768 minimum resolution and does not advertise a high/low or old/new graphics toggle.

The safest timeline from public sources is:

| Date | Evidence | Interpretation |
| --- | --- | --- |
| January 2003 | Nexus 5.31/5.32 client refresh with revised map/rendering system and new assets. | A major pre-high-resolution client modernization. |
| October 12, 2005 | NexusWiki page says 6.5 was released by KRU Interactive. | Fan-maintained but useful date for the 6.5 boundary. |
| Late 2005 | Nexus Atlas 6.5 report says high-resolution graphics changed dramatically while an earlier-client view option existed. | Compatibility/old-view support existed at the 6.5 transition. |
| December 30, 2005 | Official repost mentions high-resolution client text color and low-resolution-client black-body bug fix. | High and low resolution paths were both still live. |
| January 2006 | Nexus Atlas archive includes 6.58/6.59 fixes for low-resolution-client crash/black body and high-resolution-client dead graphic/text color. | Last positive public evidence found in this pass for named high/low-resolution client support. |
| Current official page, checked 2026-05-24 | Nexus TK 7.52 download requires minimum 1024x768; no public old/high/low toggle is documented there. | Modern public docs do not expose a compatibility toggle, but absence is not removal proof. |

## Relationship To Korean Baram Old-Graphics Mode

Korean Baram's official old-graphics mode is a later and separate data point. Nexon Korea launched that mode on July 23, 2020 as part of a "Back to the Baram" update, and current Korean guide pages still document old/new normal/wide graphics-mode settings.

Comparison:

- NexusTK 6.5 evidence is from 2005-2006 and appears tied to a high-resolution art transition in the US service.
- Korean Baram 2020 evidence is from the modern Korean service and is explicitly a live-service old/new graphics selector with normal/wide variants.
- Both show Baram-family clients carrying more than one visual presentation for the same game world.
- They should not be assumed to be the same implementation. The Korean 2020 mode may use modern asset-selection logic and restored old art, while NexusTK 6.5 may involve older high/low renderer or resource-pack compatibility.
- For local reverse engineering, treat them as two leads: a US 6.5 high/low rendering branch and a later Korean old/new asset-selection branch.

## Removal Or Current-Support Status

I did not find a public removal notice for NexusTK old-client rendering support.

The strongest confirmed statements are positive evidence of existence:

- Nexus Atlas 6.5 report: players had an option to view the game as it appeared in earlier clients.
- December 2005 official repost: both high-resolution and low-resolution client behavior are named.
- January 2006 archive: both high-resolution and low-resolution client behavior are still named in patch fixes.

The strongest current negative evidence is only indirect:

- The current official KRU download page offers Nexus TK 7.52, says the minimum resolution is 1024x768, and does not describe an old-view, low-resolution, or high/low graphics toggle.
- Current public-facing KRU pages reviewed in this pass focus on installer, updater, dependencies, account/trial limits, and basic guide content rather than graphics-mode selection.

Conclusion: public sources found so far support "old/low-resolution rendering compatibility existed in NexusTK 6.5/6.59" and "no explicit public removal date found." A removal date should not be asserted without either an archived official patch note, an installer/manual that removes the setting, or local binary/resource evidence showing the branch absent.

## Era-Specific Reverse-Engineering Leads

Likely old-client modules or behaviors to look for:

- Version strings: Nexus 5.31, Nexus 5.32, Nexus 6.0, Nexus 6.5, Nexus 6.58, Nexus 6.59, NexusTK 7.52, BARAM 6.0.
- Graphics/resource formats: face images, weapon/armor/item images, legend icons, who-list icons, map tiles, stable/map UI, house interior assets, high-resolution graphics, low-resolution graphics, old-view resource selection.
- Audio: old/new music system, CD player UI, volume control, repeated music bug.
- Input: keyboard command table, fast magic, fast speech, modal inventory/spell list letters.
- Map/render: revised map system, refresh behavior, home bug, map-load crashes, realm-center view adjustment, high/low-resolution mode flag, graphics-mode persistence, renderer fallback when high-resolution assets are missing.
- Screenshot capture: Scroll Lock handling, modifier keys, BMP/JPG output.
- Account/network: login page, Nexon/KRU domain strings, updater endpoints, support/account URLs, trial/registration state.
- UI/settings vocabulary: high-resolution client, low-resolution client, old graphics, graphics option, text color, effects, lighting, auto-walk, `Control-W`, `Shift+F12`.
- Server-message vocabulary: Dream Weaver posts, board text, purge notices, reset/update notices, group/whisper/sage/chat.

## Sources

- [MobyGames: Nexus: The Kingdom of the Winds](https://www.mobygames.com/game/57177/nexus-the-kingdom-of-the-winds/)
- [Official NexusTK download page](https://www.nexustk.com/download_2.html)
- [Official NexusTK FaceMaker/download page](https://www.nexustk.com/download_3.html)
- [Official NexusTK basic guide](https://www.nexustk.com/guid_01.html)
- [Nexus Atlas January 2003 archive](https://www.nexusatlas.com/archives/mainpage-archive-1-2003.php)
- [Nexus Atlas September 2003 archive](https://www.nexusatlas.com/archives/mainpage-archive-9-2003.php)
- [Nexus Atlas July 2004 archive](https://www.nexusatlas.com/archives/mainpage-archive-7-2004.php)
- [Nexus Atlas March 2005 archive](https://www.nexusatlas.com/archives/mainpage-archive-3-2005.php)
- [Nexus Atlas May 2005 archive](https://www.nexusatlas.com/archives/mainpage-archive-5-2005.php)
- [Nexus Atlas Version 6.5 report](https://www.nexusatlas.com/reports/alpha.php)
- [Nexus Atlas December 2005 archive](https://www.nexusatlas.com/archives/mainpage-archive-12-2005.php)
- [Nexus Atlas January 2006 archive](https://www.nexusatlas.com/archives/mainpage-archive-1-2006.php)
- [Nexus Atlas September 2006 archive](https://www.nexusatlas.com/archives/mainpage-archive-9-2006.php)
- [NexusWiki: KRU Interactive](https://nexuswiki.com/wiki/KRU_Interactive)
- [NexusWiki: Nexus client](https://www.nexuswiki.com/wiki/Nexus_client)
- [Official Korean Baram Back to the Baram 2020 intro](https://baram.nexon.com/E200723/Intro)
- [Official Korean Baram environment settings guide](https://baram.nexon.com/GameGuide/View/25)

## Open Questions

- Open-question pass 2026-05-24: this document now answers the public old-rendering-support question as far as web sources allow: NexusTK 6.5/6.59 had high/low-resolution or earlier-client-view support, and no public removal notice was found.
- Open-question pass 2026-05-24: all exact local questions here remain binary/resource inspection targets: version string, screenshot path/format, KRU/Nexon branding strings, BARAM 6.0 boundary, and dormant compatibility branches.
- Open-question pass 2026-05-24: current public endpoint is Nexus TK 7.52 with 1024x768 minimum resolution, but the current download page does not prove whether low-resolution support was removed from code/resources.

- Which exact local executable/resource set is being studied, and whether it exposes a client version string.
- Whether the local client supports the 5.31 screenshot JPG behavior or the older BMP path only.
- Whether the local target contains KRU branding, Nexon branding, or both.
- Whether "BARAM 6.0 client" maps to a visible protocol, resource, or executable-format change.
- When, if ever, KRU removed the low-resolution / earlier-client-view option after the 6.5/6.59 era.
- Whether the low-resolution path is a renderer branch, an asset-pack branch, a viewport setting, or a combination.
- Whether current NexusTK 7.52 still contains dormant compatibility strings or resource lookup paths even if the public download page no longer documents the option.
