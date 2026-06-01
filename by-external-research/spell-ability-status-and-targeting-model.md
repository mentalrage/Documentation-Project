*** UID:0000H7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Spell, Ability, Status, And Targeting Model

Research date: 2026-05-24

Scope: online-only public research on NexusTK spell records, path ability families, status effects, targeting, aethers, and alignment-name variants. Treat this as a schema and vocabulary guide for reverse engineering, not as confirmed target-binary behavior.

Confidence: medium. The official KRU path guide is authoritative for public path themes and legacy spell names. Nexus Atlas spell pages are fan-maintained, but they expose a consistent record schema and many concrete values that are useful for string/resource searches.

## Spell Record Schema

Nexus Atlas presents spells with a repeated data model:

- Spell name and short functional description.
- Mana cost.
- Spell type.
- Aethers: time before the spell can be cast again. Nexus Atlas explicitly counts zero-second aethers.
- Duration: time the effect remains active on the caster or target.
- Target: self-only, targetable, one-tile trap, surrounding creatures, typed name, or special pattern.
- Information flags: restrictions such as "not usable in PK", "cannot be learned in Tangun", "obtain from NPC Seyn", or Vortex-boss behavior.
- Description and additional information.
- Level/stat/rank requirements.
- Item, coin, kill, or quest requirements.
- Alignment-name variants for Kwi-Sin, Ming-Ken, and Ohaeng.

Reverse-engineering implication: spell handling likely combines data-table-like spell definitions with procedural special cases. Search for field labels, alignment aliases, effect names, and NPC/quest spell names.

## Spell Type Taxonomy

Nexus Atlas classifies spell roles into these visible families:

- Enhancement: buffs or self/target improvements, including furies, Ingress, Might, armor hardening, hit/damage changes, and weapon-related boosts.
- Healing: self or target vitality restoration.
- Revealing: exposes target stats, inventory, trap information, or whereabouts.
- Roleplay: benefits outside normal hunting, such as Share Wisdom and Mentor.
- Summoning: brings an animal or player/helper to the caster.
- Transport: moves the player or bridges location to another player, such as Gateway, Return, Approach, or Summon-style movement.
- Transformation: morphs the player into an animal or other form, including Beast and alignment morphs.
- Trap: rogue trap spells and natural cave trap behavior.
- Weakening: debuffs such as Vex, Scourge, paralysis, blind, sleep, and AC-raising curses.
- Cleansing: present in detailed spell pages for poison/curse/veil/paralysis removal, even though it is not emphasized in the Nexus Atlas index summary.
- Attack: direct damage, area damage, ranged attacks, and special rank attacks.

The official KRU path guide uses different prose names for the same conceptual families: warrior Valor, rogue Riches, mage Mystery, and poet Love.

## Shared Baseline Spell Families

Common early or cross-path ideas include:

- Gateway: transport to one of the four gates.
- Soothe/Fleshspeak/Lay Hands/Recover/Heal family: vitality restoration.
- Might/Valor/Bless/Harden Armor/Sanctuary family: stat, armor, and damage mitigation effects.
- Spark/Singe/Ignite/Erupt/Ion/Impact/Explode family: ranged or area attacks.
- Approach/Summon/Return family: player or self movement.
- Mentor: novice/social role support.
- Invoke: vitality-to-mana conversion.

Different paths get different timing, target, and power curves. Some names are shared directly; others are renamed by alignment.

## Alignment Name Layer

The official path guide lists base spell names alongside Kwi-Sin, Ming-Ken, and Ohaeng name variants. Examples:

- Warrior Wolf's Fury becomes names such as Soul's Rage, Spirit of the Forest, or Augmentation.
- Rogue Judge becomes names such as Spiritual Advisor, Natural Talent, or Appraise.
- Mage Invoke becomes names such as Spirit's Power, Life Force, or Gather Magic.
- Poet Purge becomes names such as Cure Illness, Restore Health, or Remove Poison.

Nexus Atlas repeats this pattern in detailed spell records. This implies a logical spell identity can have multiple display names depending on alignment. For binary work, do not assume a name string is unique to one spell implementation; group by effect family, path, level/rank, and alignment.

## Path-Specific Ability Themes

### Warrior

Warrior spells emphasize melee damage, hit/attack enhancement, positional attacks, detection, weapon empowerment, and self/target healing. Nexus Atlas examples include:

- Taunt as a 1-damage pulling spell.
- Wolf's Fury and Tiger's Fury as weapon damage multipliers.
- Bless increasing hit chance.
- Backstab and Flank enabling attacks behind or to the sides.
- Watchful Eye detecting ambushes.
- Later rank abilities such as Rampage and Scream include area or stun behavior.

### Rogue

Rogue spells emphasize transformation, traps, stealth, mobility, revealing, item manipulation, and special attacks.

Examples from Nexus Atlas:

- Feral/Rodent/Gangrel/Beast morph into animals.
- Judge reveals level and basic stats if level conditions are satisfied.
- Invisible changes visibility and attack damage behavior.
- Approach and Ambush alter position.
- Bladestorm is a trap that can force an Assault-like attack and has separate player/creature behavior.
- Chance uses dropped coins during a timed window, demonstrating spell effects tied to item/ground state.

### Mage

Mage spells emphasize attack, area damage, control, curses, poison, paralysis, sleep, confusion, armor/status changes, transport, and some healing/cleansing.

Examples:

- Pestilence gives +5 AC to the target; Nexus Atlas notes positive AC is worse.
- Static immobilizes targets and cannot be cast on players.
- Spark/Singe/Ignite and later high-rank attacks provide ranged damage.
- Vex, Blind, Paralyze, Confuse, Sleep, Doze, Tempest, and Hellfire define a broad control/damage toolkit.

### Poet

Poet spells emphasize healing, cleansing, protection, status removal, animal friendship, revival-like high-end effects, and group support.

Examples:

- Purge removes poison.
- Harden Armor improves AC.
- Remove Curse, Remove Veil, Cure Paralysis, Atone, Remedy, Fortify, Inspiration, Revitalize, and related alignment variants show how many poet effects are status-repair or support oriented.
- Invoke exists for poet mana management, with Nexus Atlas noting a 36-second aether and vitality-to-mana conversion behavior.

## Aethers, Duration, And Strongest-Spell Rules

Nexus Atlas warns that players should usually use only the strongest version of a spell in a family, especially furies and Ingress-type spells. The rule of thumb given is that the higher-level spell is stronger, and the last cast in a related enhancement family can determine the active effect.

Reverse-engineering implications:

- Some buffs may overwrite by effect family rather than stack by spell name.
- Spell definitions may include a "family" or effect category not visible in the display name.
- Aethers are separate from duration: a spell can have a long duration and zero aether, or a short duration and nonzero aether.
- Some special effects drain resources over time after casting, such as rogue Chance or trap behavior.

## Targeting And Spatial Rules

Public sources show multiple target modes:

- Self only: most morphs, many buffs, self heals, and Invoke.
- Targetable: attack, heal, reveal, curse, and cleansing spells.
- Typed name: Approach and similar player-location actions.
- Facing target: Ambush and attack-adjacent behavior.
- One-tile trap: rogue traps.
- Surrounding creatures: Scream and some area effects.
- Pattern-based attacks: some Sa san and Vortex/Seyn abilities use pattern graphics or multi-target shapes.

The official KRU guide reinforces adjacency/facing rules for ordinary attack and look actions. Spell targeting probably sits on top of the same map/tile/facing model.

## Traps And Cave Hazards

Nexus Atlas states that trap spells can occur naturally in some caves, that rogue player traps cannot affect players outside PK areas, and that traps stack. Rogue pages describe traps with special duration, mana drain, hidden visibility rules, and different player-versus-creature effects.

Potential local evidence:

- Trap spell names: Dart trap, Flash Trap, Bladestorm, Sleep trap.
- Tile/object lifecycle fields for trap creation, owner, stack count, duration, and triggered effect.
- PK-area checks separate from creature checks.
- Spell visibility checks such as Spot Trap.

## Sa San And Seyn Spell Path

Nexus Atlas describes a special Sa san spell quest in Vortex:

- Every Sa san player can learn one spell from Seyn.
- Other Sa san spells are learned in Sa san Haven in Arctic Village.
- Seyn requires dialog keywords at Vortex and four guardian shrine sequences in Wilderness.
- The Baekho, Ju jak, Hyun moo, and Chung ryong steps require shrine keywords, item bundles, favor items, keys, and essences.
- Final completion returns to Seyn with the "Four guardians" keyword.

This is important because high-rank spells are not just table unlocks. They can be quest-gated through dialog, inventory checks, kills, coordinates, and rank/stat checks.

## Reverse-Engineering Leads

Search terms:

- Field labels: Mana Cost, Spell Type, Aethers, Duration, Target, Information, Additional Information.
- Type names: Enhancement, Healing, Revealing, Roleplay, Summoning, Transport, Transformation, Trap, Weakening, Cleansing, Attack.
- Spell-effect families: Gateway, Soothe, Invoke, Fleshspeak, Approach, Summon, Return, Mentor, Vex, Scourge, Paralyze, Sleep, Blind, Spot Trap, Set Trap.
- Alignment names: Kwi-Sin, Ming-Ken, Ohaeng, Spiritsong, Helping Hand, Heal Others, Life Force, Gather Magic.
- High-rank/Seyn terms: Seyn, Sa san, Four guardians, Baekho, Ju jak, Hyun moo, Chung ryong, Vortex, Sa san Haven.

Potential structures:

- Spell definition table keyed by spell id.
- Display-name table keyed by base path and alignment.
- Effect handler dispatch table.
- Aether/cooldown state per character/spell or spell family.
- Buff/debuff slot table keyed by effect family.
- Target-mode validation for map coordinates, typed names, facing tile, and PK area.
- Reagent/item requirement handling shared with quests.

## Sources

- [Official NexusTK paths/spells guide](https://www.nexustk.com/guid_03.html)
- [Nexus Atlas spells index](https://www.nexusatlas.com/spells/index.php)
- [Nexus Atlas mage spells](https://www.nexusatlas.com/spells/mage.php)
- [Nexus Atlas poet spells](https://www.nexusatlas.com/spells/poet.php)
- [Nexus Atlas rogue spells](https://www.nexusatlas.com/spells/rogue.php)
- [Nexus Atlas warrior spells](https://www.nexusatlas.com/spells/warrior.php)
- [Nexus Atlas Sa san Seyn Spell quest](https://www.nexusatlas.com/quests/seynspell.php)
- [Official NexusTK basic/interface guide](https://www.nexustk.com/guid_01.html)

## Open Questions

- Open-question pass 2026-05-24: official Alignments confirms that alignment can alter the look of abilities and slightly reduce selected spell aethers. This supports searching for alignment-specific visuals/names and aether display paths.
- Open-question pass 2026-05-24: official Basic Keys confirms the current client has spell list expand/collapse, change spell order, and cast-spell key flows. That proves a client-visible spell list/control surface, but not local spell-definition ownership.
- Open-question pass 2026-05-24: public pages do not prove whether target spell names, alignment aliases, aether timers, or trap effects are executable strings, DAT/resource strings, or server-fed display data.

- Whether the target client stores spell definitions locally or receives most spell behavior from the server.
- Whether alignment spell names are client-side display aliases or server-provided strings.
- Whether aether timing is purely server-authoritative or mirrored in local UI state.
- Which trap behaviors are client-rendered versus invisible/server-only state.
