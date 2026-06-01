*** UID:0000H8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Subpath Services, Legend Marks, And Roleplay Model

Research date: 2026-05-24

Scope: online public information about NexusTK base-path gates, PC/NPC subpath structure, subpath authority roles, services, legend marks, brandings, and roleplay-facing data. This document is external research only and should be used as vocabulary and behavior context until confirmed locally.

Confidence: medium. Official help confirms path/subpath lists and service names. Nexus Atlas provides richer fan-maintained social and legend-mark context, but exact availability and wording can vary by era.

## Base Path And Subpath Gates

Official Paths help says the base path choice occurs after the Quickening at level 5. The four base paths are Warrior, Rogue, Mage, and Poet. The same page says level 50 opens the choice to join a subpath or embrace an alignment.

Official Subpaths help lists the same four base-path families:

| Base path | PC subpaths | Totem/NPC subpath |
| --- | --- | --- |
| Warrior | Barbarian, Chongun, Do | Chung Ryong |
| Rogue | Merchant, Ranger, Spy | Baekho |
| Mage | Diviner, Geomancer, Shaman | Ju Jak |
| Poet | Druid, Monk, Muse | Hyun Moo |

Nexus Atlas adds that each base path has three PC subpaths and one NPC subpath. It records level 50 as the PC-subpath application gate and level 99 as the NPC-subpath join gate.

Reverse-engineering leads:

- Search for `Quickening`, `Warrior`, `Rogue`, `Mage`, `Poet`, `subpath`, `alignment`, `level 50`, and `level 99`.
- Path/subpath gates may be server-side, but client UI can still display denial messages, path lists, and status fields.
- NPC path names have spacing/case variants: `Ju Jak`, `Jujak`, `Hyun Moo`, `Hyunmoo`, `Chung Ryong`, `Chungryong`.

## PC Versus NPC Subpath Model

Nexus Atlas distinguishes:

- PC subpaths: player-run, application and training based, roleplay-oriented, and tied to elders/guides and path scrolls;
- NPC subpaths: not player-run, ruled by Totem Gods, joined at Baek's Shop in Kugnae, and aimed at players who do not want player-run subpath roleplay.

Reverse-engineering leads:

- `Baek's Shop` is a high-value NPC/location string for NPC subpath joining.
- PC subpath joins probably involve social approval plus server-side membership changes rather than a purely client-local quest.
- NPC subpath joining may be more quest/NPC-dialog driven and may have explicit item/karma/totem key dependencies in related quest pages.

## Subpath Authority Roles

Official terminology defines Elders as subpath leaders. Nexus Atlas job marks include `Elder of Subpath`, `Founder of Subpath`, `Guide of Subpath`, and a retired/old elder mark. Official Verbal Commands documents `Dismiss` as an Elder-only command for removing a PC subpath member.

Reverse-engineering leads:

- Search for `Elder`, `Guide`, `Founder`, `Dismiss`, `Subpath Elder`, `Guide of Subpath`, and subpath-specific title strings.
- Role authority may be server-owned, but the client may expose command text, subpath member lists, board permissions, subpath chat routing, and legend marks.
- `Dismiss` should be inspected alongside membership removal, privilege failure messages, and role-only NPC interactions.

## Subpath Communication And Membership UI

Official Basic Keys and Verbal Commands show several subpath-specific communication routes:

- `F2` and `Shift+F2`: subpath chat on/off;
- `" @`: whisper subpath chat;
- `/sp`: talk to subpath;
- `Abandon`: leave PC subpath;
- `Cleanse`: leave NPC path.

Reverse-engineering leads:

- Subpath membership likely affects chat-route permission, status/profile display, and spell/item eligibility.
- `Abandon` and `Cleanse` are important command strings because they separate PC-subpath exit from NPC-path exit.
- Search for `Subpath chat`, `/sp`, `Abandon`, `Cleanse`, `whisper subpath`, and `Totem`.

## Official Subpath Services

Official Subpath Quests & Services lists public services and quest categories by subpath. The page notes that its information came from Subpaths Board material supplied by elders/guides.

Service clusters:

- Barbarians: Blood Oath, Survival Challenges, Wilderness Training.
- Chonguns: Pardon Tribunal, honor demonstrations, noble titles, Art of War College.
- Diviners: marriage purification, Tao serenity, I-Ching, Threads of Fate, Tarot Cards, unpopular-opinion and smallness services, Divine Order study/training/oaths.
- Do: Master Bladecrafter, Weapon Master, Art of Peace.
- Druids: elemental alignment, Herbalism, Animal Devotion, Heart Sing.
- Geomancers: Elementalist's Mark and Ba-Gua.
- Merchants: D Quest, True Wealth, Lucky, Philanthropist, Economist, Three Duties, Preferred Client, Treasure Hunter, Trading.
- Monks: Vow/Oath Renewal, Forgiveness, Eightfold Path, Inner Peace, Family Mark, Inzen, Past Lives.
- Musei: Sweet Revenge, Instrument Quests, Community Theatre, Muse College.
- Rangers: Taming, Scouting, Arrow-cresting.
- Shamans: Weddings, Kindred Spirits, Totem Spirit Revelation, Ceremonial Fire, Ritual Stones, Spirit Drum, Medicine Wheel, Alignment Devotion, Mudang Acolyte.
- Spies: Employment Opportunities.

Reverse-engineering leads:

- Service names are excellent string seeds for boards, NPC dialogue, legend marks, and item/quest requirements.
- Some services imply direct mechanical effects, such as karma restoration, marriage/vow marks, item crafting, title assignment, or alignment/totem changes.
- Other services may be pure roleplay events with only board text or legend marks as client-visible output.

## Nexus Atlas Subpath Identity Themes

Nexus Atlas gives a compact theme/origin profile for each PC subpath:

- Barbarian: Warrior, Wilderness, unity/family/outdoor survival.
- Chongun: Warrior, Koguryo, protector and honor code.
- Do: Warrior, Buya, weapon mastery and personal ability.
- Merchant: Rogue, Kugnae, trade/economy/crafting/treasure hunting/wealth.
- Ranger: Rogue, Wilderness, nature protection and skill enhancement.
- Spy: Rogue, Koguryo, disguise, investigation, subterfuge.
- Diviner: Mage, Koguryo, past/present/future interpretation and Taoist beliefs.
- Geomancer: Mage, Wilderness, earth/natural energy and balance.
- Shaman: Mage, Nagnang, spirit communication and older magic.
- Druid: Poet, Wilderness, nature and natural cycles.
- Monk: Poet, Koguryo, peace, good/evil, deity devotion, Buddhist framing.
- Muse: Poet, Buya, music, art, storytelling, poetry.

Reverse-engineering leads:

- Origin cities/regions can appear in public profile pages, subpath halls, map names, and board categories.
- Theme words are useful for interpreting otherwise ambiguous quest or legend-mark text.
- Player-run roleplay identity can produce many strings that are not core combat mechanics.

## Legend Mark Categories

Nexus Atlas subpath legend marks are organized by subpath and include several recurring categories:

- membership or internal achievement marks;
- guide/elder service-provider marks;
- recipient marks for services such as weddings, readings, forgiveness, vows, or blood oaths;
- friendship or honorary marks;
- enemy/red branding marks;
- ranked skill or challenge marks;
- path-specific game/event marks;
- extinct or historical marks, such as Shadow-related marks.

Examples by theme:

- Barbarian: blood oath, enemy, heart/friendship.
- Chongun: Art of War, honor/dishonor, wedding marks.
- Diviner: Tai-Chi, Fortune, I-Ching, Tao/Yin/Yang/Yin-Yang, marriage purification.
- Do: Exalted, Masai Tournament, Weapon Master.
- Druid: Air/Earth/Fire/Water alignment, Defiler, Protector.
- Geomancer: Balance, Ba-Gua relationship/fame/items/love readings.
- Merchant: collector/trader/treasure/economist-style marks, Trustworthy Trader, Dishonorable Trader, Market Disruptor.
- Monk: Forgiven, Inner Peace, Enlightenment, vows, blood oath renewal.
- Muse: Muse blessings, Discordant Note, Graced.
- Shaman: Ascension, Cursed, Kindred, Medicine Wheel, Totem Spirit, Touched by Spirits, wedding/cursing marks.
- Spy: aid, exploitation, membership.
- Ranger: archery/camouflage/foraging/cartographing/security/tracking/trapping ranks, scouting, respect-nature marks.

Reverse-engineering leads:

- Legend marks may have exact text, icon IDs, date/person fields, and count fields.
- Red/enemy brandings are worth tracking because they may interact with NPC denial, social permissions, or display color.
- Search for `Enemy of`, `Dishonorable`, `Defiler`, `Discordant Note`, `Market Disruptor`, `Cursed`, `Totem Spirit`, `Weapon Master`, `I-Ching`, `Ba-Gua`, and `Blood Oath`.

## Roleplay Events Versus Mechanics

Subpath sources mix several layers:

- formal membership data;
- subpath chat and authority commands;
- path-specific spells/items or services;
- public legend/profile marks;
- boards and applications;
- purely social roleplay events.

Reverse-engineering leads:

- Avoid assuming every service name has a dedicated client subsystem.
- Strong client candidates are chat channels, command strings, profile/legend display, board/mail UI, spell/item restrictions, and NPC dialogue.
- Strong server candidates are membership state, authority checks, quest/legend grants, spell permissions, and event reward grants.

## Likely Client/Server Ownership

Likely client-owned or client-visible:

- path/subpath labels and status/profile fields;
- subpath chat toggles and route aliases;
- boards, mail, applications, and post text windows;
- legend mark rendering and icons;
- NPC dialogue prompts and denial/result messages;
- item/spell restriction labels tied to path/subpath.

Likely server-owned:

- membership and role assignment;
- elder/guide privileges;
- join/leave/dismiss validation;
- subpath service completion and legend grant;
- PC-subpath application status;
- NPC subpath/totem path quest state;
- red-branding effects and permissions, if any.

Shared protocol candidates:

- set or clear subpath membership;
- send subpath chat;
- leave PC subpath or NPC path;
- elder/guide command request;
- legend mark add/remove/update;
- board/mail operations for subpath groups;
- spell/item eligibility checks.

## String And Data Search Leads

Search locally for:

- path/subpath map: `Barbarian`, `Chongun`, `Do`, `Merchant`, `Ranger`, `Spy`, `Diviner`, `Geomancer`, `Shaman`, `Druid`, `Monk`, `Muse`, `Chung Ryong`, `Baekho`, `Ju Jak`, `Hyun Moo`;
- authority: `Elder`, `Guide`, `Founder`, `Dismiss`, `Abandon`, `Cleanse`, `Subpath Elder`;
- communication: `/sp`, `Subpath chat`, `whisper subpath`, `F2`;
- services: `Blood Oath`, `Survival Challenges`, `Pardon Tribunal`, `I-Ching`, `Tarot`, `Ba-Gua`, `Weapon Master`, `Herbalism`, `Three Duties`, `Preferred Client`, `Eightfold Path`, `Community Theatre`, `Arrow-cresting`, `Medicine Wheel`, `Employment Opportunities`;
- marks/brandings: `Enemy of`, `Dishonorable Trader`, `Market Disruptor`, `Defiler of Nature`, `Discordant Note`, `Cursed`, `Touched by Spirits`, `Trustworthy Trader`;
- locations and gates: `Baek's Shop`, `Totem Gods`, `Quickening`, `level 50`, `level 99`, `alignment`.

## Open-Question Resolution Notes 2026-05-24

- Service-name provenance is answered publicly: the official Subpath Quests & Services page says all information was taken directly from Subpaths Board and provided by each subpath's Elder/Guide. Therefore service names should be treated first as board/community strings until local resources prove client embedding.
- `Dismiss` is documented as an Elder-only verbal/NPC command by official Verbal Commands. Public docs do not prove whether it becomes a dedicated packet or remains raw/structured NPC speech.
- PC/NPC subpath separation is public at the design level: official/help and Nexus Atlas sources distinguish PC subpaths from NPC/totem paths, and `Abandon` versus `Cleanse` reinforces separate leave commands. Internal status-field representation remains local.
- Enemy/red brandings are public legend-mark concepts. Public sources do not prove any local UI effect beyond display unless local code/resources show color, permission, or denial behavior.
- Legend marks are visible through status/profile pages, but public sources do not reveal whether the target stores rich local records or receives server text.

## Open Questions

- Does the target client contain subpath service names, or are they only in board/NPC/server text?
- Are legend marks stored/rendered as rich client records or as server-sent text blocks?
- Does `Dismiss` have a dedicated packet/command path, or is it raw NPC speech interpreted by the server?
- Are PC and NPC subpaths represented by the same status field internally?
- Do red/enemy brandings affect any local UI state or only server-side permission checks?

## Sources

- [Official help: Paths](https://help.nexustk.com/wiki/wiki/35/paths)
- [Official help: Subpaths](https://help.nexustk.com/wiki/wiki/17/subpaths)
- [Official help: Subpath Quests & Services](https://help.nexustk.com/wiki/wiki/87/subpath-quests-services)
- [Official help: Basic Keys](https://help.nexustk.com/wiki/wiki/7/basic-keys)
- [Official help: Verbal Commands](https://help.nexustk.com/wiki/wiki/40/verbal-commands)
- [Official help: Nexus Terminology](https://help.nexustk.com/wiki/wiki/70/nexus-terminology)
- [Nexus Atlas: Subpaths](https://www.nexusatlas.com/subpaths/index.php)
- [Nexus Atlas: Subpath legend marks](https://www.nexusatlas.com/legends/subpaths.php)
- [Nexus Atlas: Job legend marks](https://www.nexusatlas.com/legends/jobs.php)
- [Nexus Atlas: What is Nexus?](https://www.nexusatlas.com/what.php)
