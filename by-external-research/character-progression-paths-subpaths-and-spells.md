*** UID:0000GN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Character Progression, Paths, Subpaths, And Spells

Confidence: strong for public path/subpath names, medium for spell role grouping, open for target-binary match.

Scope: external public descriptions of character path progression, subpath organization, high-level ranks, and spell naming families. This is not binary evidence; use it to seed local symbol/string/resource searches.

## Base Path Model

Observed:

- Official help identifies four base paths: Warrior, Rogue, Mage, and Poet. Source: [official Paths](https://help.nexustk.com/wiki/wiki/35/paths).
- The official path page says "Quickening" occurs at level 5, after which guild halls accept a character into one of the base paths. Source: [official Paths](https://help.nexustk.com/wiki/wiki/35/paths).
- The official path page says that at level 50 a hero may choose a subpath or alignment. Source: [official Paths](https://help.nexustk.com/wiki/wiki/35/paths).
- Nexus Atlas describes NexusTK as having four main hero classes and sixteen sub-classes/subpaths. Source: [Nexus Atlas: What is Nexus?](https://www.nexusatlas.com/what.php).

Reverse-engineering leads:

- Search for path strings and guild hall dialogue around `Warrior`, `Rogue`, `Mage`, `Poet`, `Quickening`, and level gates `5`, `50`, and `99`.
- The client likely has UI fields and resource filtering keyed by base path, with spell/item/equipment constraints.

## PC And NPC Subpaths

Observed:

- Nexus Atlas says each base path has three PC subpaths and one NPC subpath. PC subpaths are player-run and use application/training processes; Nexus Atlas records level 50 as the PC subpath application gate. Source: [Nexus Atlas: Subpaths](https://www.nexusatlas.com/subpaths/index.php).
- Nexus Atlas says NPC subpaths are not player-run, are ruled by Totem Gods, require level 99, and are joined at Baek's Shop in Kugnae. Source: [Nexus Atlas: Subpaths](https://www.nexusatlas.com/subpaths/index.php).
- Official help lists the same subpath families. Source: [official Subpaths](https://help.nexustk.com/wiki/wiki/17/subpaths).

Subpath map:

| Base path | PC subpaths | NPC/Totem subpath |
| --- | --- | --- |
| Warrior | Barbarian, Chongun, Do | Chung Ryong |
| Rogue | Merchant, Ranger, Spy | Baekho |
| Mage | Diviner, Geomancer, Shaman | Ju Jak |
| Poet | Druid, Monk, Muse | Hyun Moo |

Nexus Atlas short descriptors:

- Barbarian: wilderness origin, unity/family, outdoor survival.
- Chongun: Koguryo origin, protector/defender code.
- Do: Buya origin, martial weapon mastery.
- Merchant: Kugnae origin, trade, economy, treasure hunting, wealth.
- Ranger: wilderness origin, nature protection and skill enhancement.
- Spy: Koguryo origin, disguise, investigation, subterfuge.
- Diviner: Koguryo origin, past/present/future interpretation and taoist beliefs.
- Geomancer: wilderness origin, earth/natural energy, balance, taoism.
- Shaman: Nagnang origin, spirit speaker and old magic.
- Druid: wilderness origin, nature and natural cycles.
- Monk: Koguryo origin, deity and Buddhist framing.
- Muse: Buya origin, music, art, storytelling, poetry.

Source: [Nexus Atlas: Subpaths](https://www.nexusatlas.com/subpaths/index.php).

Reverse-engineering leads:

- Search subpath names, totem names, `Baek's Shop`, `Subpath Elder`, guide/elder titles, path scroll names, subpath chat, brandings, and path-only item restrictions.
- Community organization data may be a mix of client display strings and server data. Confirm before assigning ownership to client code.

## Spell Role Families

Observed:

- The official paths/spells guide lists large spell families for base paths and alignments. Source: [official paths/spells guide](https://www.nexustk.com/guid_03.html).
- Common cross-path utility concepts include gateway/return travel, approach/summon movement, mentor, healing/soothing, buffs, status cures, and transformation or animal interactions. Source: [official paths/spells guide](https://www.nexustk.com/guid_03.html).
- Warrior spell names emphasize direct attacks, rage/fury, weapon infusion, back/flank attacks, detection, and self-healing.
- Rogue spell names emphasize stealth, disguises, traps, judging/appraising, poison/drain, ranged pickup, ambush, summoning, and mobility.
- Mage spell names emphasize elemental damage, area attacks, paralysis/sleep/blind/confusion, curses, poison, shields, and vitality/mana conversion.
- Poet spell names emphasize healing, armor/defense, cures, resurrection, mana/vitality support, taming/friends, barriers, and group support.

Reverse-engineering leads:

- Search exact spell names when naming tables or resource IDs. Useful common names include `Gateway`, `Return`, `Approach`, `Summon`, `Mentor`, `Soothe`, `Vigor`, `Invisible`, `Set trap`, `Paralyze`, `Sleep`, `Resurrect`, and `Water of life`.
- Alignment variants such as Kwi-Sin, Ming-Ken, and Ohaeng appear to provide flavor-renamed spell sets with similar roles. This may explain parallel string tables or repeated spell metadata rows.

## High-Level Rank And Quest Gates

Observed:

- Nexus Atlas quest index separates 99+ quests and ranks such as Enchant, Il San, Ee San, Sam San, Sa San, and related Seyn spell quests. Source: [Nexus Atlas: Quests index](https://www.nexusatlas.com/quests/index.php).
- Nexus Atlas Vortex notes place Seyn in the Vortex after the introduction of Sa san and describe spoken NPC/item gates involving Baekho, Ju Jak, Hyun Moo, Chung Ryong, and `Four guardians`. Source: [Nexus Atlas: Vortex](https://www.nexusatlas.com/60atlas/vortex.php).
- Official carnage level ranges use rank labels such as Enchanted, Il san, Sam san, Sa san, Oh san, and Ee san in stat-band context. Source: [official Carnage Levels](https://help.nexustk.com/wiki/wiki/39/carnage-levels).

Reverse-engineering leads:

- Search for rank strings: `Il san`, `Ee san`, `Sam san`, `Sa san`, `Oh san`, `Enchant`, `Seyn`, `Four guardians`, and totem essence names.
- High-level gates likely cross item inventory, legend marks, stats, and spoken command state.

## Open Questions

- Open-question pass 2026-05-24: current official help confirms base paths, current subpath lists, alignment names, level 45 alignment availability, level 50 subpath choice framing, level 1-99 experience, and post-99 Midnight Weaver exchange. Target-era subpath/spell coverage remains local/version work.
- Open-question pass 2026-05-24: official Alignments says alignment alters ability appearance and slightly reduces selected aethers. This narrows alignment variants to display/effect/aether leads but does not prove local spell ID layout.
- Open-question pass 2026-05-24: public pages document spell/progression behavior and vocabulary, but not whether spell names/gates are executable resources or server-fed text in the target.

- Which spell names are client resources versus server-driven text?
- Does the target binary include all modern subpath/totem strings or only those present at its release time?
- Are alignment variants represented as separate spell IDs or localized display aliases over shared behavior?
- Are level/rank gates checked only server-side, or mirrored in client UI filtering?
