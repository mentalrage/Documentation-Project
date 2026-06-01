*** UID:0000GO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Client Install, Interface, And Commands

Confidence: medium for public/current client packaging, strong for official documented commands, open for target-binary applicability.

Scope: public official documentation and fan archive notes that describe the NexusTK client surface: installer dependencies, free/registered feature gates, input commands, verbal commands, and UI behaviors that are useful for binary string and handler searches.

## Official Client Packaging

Observed:

- The official download page currently offers `Nexus TK 7.52 (227MB)` as a single-file KRU download and says Nexus requires at least `1024x768` resolution. Source: [official download page](https://www.nexustk.com/download_2.html).
- The same page points users to `.Net Framework 3.5` for .NET Framework errors and `Visual C++ 2010 Redist. Package` for `MSVCR100.dll` errors. Source: [official download page](https://www.nexustk.com/download_2.html).
- The official page includes updater repair paths: an installer for any previous version to current version and a zip replacement for `NexusUpdater.exe`. Source: [official download page](https://www.nexustk.com/download_2.html).
- Free play is allowed up to level 49. Registration unlocks broader access, including portrait/profile customization, clans, longer quests, boards, subpaths, more spells/items/maps, harder monsters, and Elixir War. Sources: [official main page](https://www.nexustk.com/main.html), [official download page](https://www.nexustk.com/download_2.html).
- The official FaceMaker page describes a separate portrait-maker utility that saves the portrait to the correct client location and format for registered characters. Source: [official downloads and FaceMaker page](https://www.nexustk.com/download_3.html).

Reverse-engineering leads:

- Search local code/resources for installer-era dependency assumptions such as `MSVCR100`, `.NET`, `NexusUpdater.exe`, `NextAeon`, `FaceMaker`, portrait path strings, updater messages, and 1024x768 display checks.
- Account feature gates may appear as UI flags around boards, clan/subpath access, maps, spells, portraits, and event enrollment.

## Keyboard And UI Commands

Observed from official help:

- Function keys cover help, subpath chat, friends, realm centering, whisper/shout hearing, music, sound, ignore list, options, hotkeys, fast move, click-to-move, dress-up/item-shop, damage numbers, and old Tab/V swap. Source: [official Basic Keys](https://help.nexustk.com/wiki/wiki/7/basic-keys).
- Communication keys include talk, whisper, clan whisper, subpath chat, shout, emotions, bulletin boards, group, group status, group view, clan whisper toggle, mail, and target-to-talk. Source: [official Basic Keys](https://help.nexustk.com/wiki/wiki/7/basic-keys).
- Character and item actions include status cycling, inventory expand/collapse, spell list expand/collapse, item order, spell order, eat, use, wield, wear, take off, immediate equip, pick up, pick up all, pick up surrounding drops, hand, hand all, drop, drop all, and exchange toggle. Source: [official Basic Keys](https://help.nexustk.com/wiki/wiki/7/basic-keys).
- Combat and misc actions include attack, throw, target next/previous, cast spell, leave kingdom, ride, open, mini-map, guide tab, creation system, post, screenshots, reload screen, right-click look, pan screen, and helpful commands. Source: [official Basic Keys](https://help.nexustk.com/wiki/wiki/7/basic-keys).
- The older official guide uses the same basic UI categories: socializing, emotions, adventuring, character status, and commands. It also describes status fields such as path, equipped gear, vitality, mana, hit, damage, AC, and next-level experience. Source: [official basic/interface guide](https://www.nexustk.com/guid_01.html).

Reverse-engineering leads:

- Key handling should have dense dispatch for single-key ASCII commands plus function keys, shifted variants, Ctrl variants, Tab, Scroll Lock, and arrow panning.
- Status UI likely formats path/equipment plus numeric fields for vitality, mana, hit, damage, AC, and next-level experience.
- Screenshot handlers should support PNG and BMP paths, with legacy or alternate bindings for Scroll Lock, Shift+Scroll Lock, and Ctrl+Shift+3.

## Verbal And NPC Command Grammar

Observed from official help:

- Banking commands include deposit-all, deposit-one, deposit-number, coin deposit, deposited item list, deposited coin count, and deposited item count. Source: [official Verbal Commands](https://help.nexustk.com/wiki/wiki/40/verbal-commands).
- NPC interaction includes buy/sell listings, asking an NPC name, repair all, repair item, minor quest request, PC subpath leave, NPC path leave, and elder-only dismissal. Source: [official Verbal Commands](https://help.nexustk.com/wiki/wiki/40/verbal-commands).
- NPC trading has quantity-specific buy and sell commands. Source: [official Verbal Commands](https://help.nexustk.com/wiki/wiki/40/verbal-commands).
- Travel commands include destination words for Kugnae, Buya, Nagnang, and Tangun. Source: [official Verbal Commands](https://help.nexustk.com/wiki/wiki/40/verbal-commands).
- Slash/say commands include clan, group, subpath, individual whisper aliases, report to archons, novice chat aliases, range dice, and shout. Source: [official Verbal Commands](https://help.nexustk.com/wiki/wiki/40/verbal-commands).

Reverse-engineering leads:

- Search for literal command words and phrases such as `What do you buy?`, `What do you sell?`, `Repair all`, `Quest`, `Abandon`, `Cleanse`, `Dismiss`, `/report`, `/novice`, `/roll`, `/r#-#`, `/sp`, `/clan`, and destination names.
- The command grammar suggests separate layers for client-side chat channel routing, server-directed NPC speech, local macro expansion, and displayed feedback in status/text windows.
- Dice commands should have output and range parsing logic. The January 2007 Nexus Atlas archive confirms `/roll` became socially significant enough to need law changes. Source: [January 2007 archive](https://www.nexusatlas.com/archives/mainpage-archive-1-2007.php).

## Historical Client Notes From Archives

Observed:

- A January 2006 Nexus Atlas report of `Nexus 6.59` says that patch notes included high-resolution emotions/actions, low-resolution `Control-w` crash fix, text color dialog fixes, updated death graphic, map tile fixes, and carnage host participant-count visibility. Source: [January 2006 archive](https://www.nexusatlas.com/archives/mainpage-archive-1-2006.php).
- An April 2011 Nexus Atlas report of `Nexus 6.90` says the client auto-patched, inventory size expanded from 26 to 27, item-shop expansion could raise inventory to 52, and item durability notices moved to the text box. Source: [April 2011 archive](https://www.nexusatlas.com/archives/mainpage-archive-4-2011.php).

Reverse-engineering leads:

- Look for legacy high-resolution/low-resolution branches, `Control-w` or close-window behavior, text color dialog code, death sprite/resource names, inventory capacity constants, item-shop capacity checks, durability threshold messages, and carnage host observer UI.

## Open-Question Resolution Notes 2026-05-24

- Current public client endpoint: resolved for the live website as `Nexus TK 7.52 (227MB)` with `1024x768` minimum resolution, but this does not identify the reconstructed target binary.
- Public era anchors: the 2003 official reference page describes a 50.5 MB client with Win95/98/2000/ME/XP and DirectX 7/8 requirements; Nexus Atlas provides 6.5/6.59 and 6.90 anchors. These are comparison points for local version matching.
- Key bindings: narrowed. Current Basic Keys exposes fixed keys, `F10` Options, `F11` Hotkey setting, F1 behavior controlled through Options, Tab/V swap, and click-to-move toggles. Therefore the current client is partly option/hotkey driven from the user's perspective. Exact hard-coded/data-driven split remains local work.
- Verbal commands: narrowed. Official Verbal Commands frames bank/shop/travel/chat commands as typed/sayable text and says many can be placed in Say macros. That supports text-command searches, but does not prove whether the client sends raw speech or structured command packets.
- FaceMaker: narrowed. The public workflow is a separate utility that saves a registered character's portrait to the correct location and format. The exact path/format is not public in the page and remains local inspection.

## Open Questions

- Which public client era matches the reconstructed target binary?
- Are key bindings hard-coded, data-driven, or partly server-configured?
- Does the client parse verbal commands locally before sending, or does it mostly pass speech text to the server?
- Where are FaceMaker portrait paths and custom portrait formats represented in the client?
