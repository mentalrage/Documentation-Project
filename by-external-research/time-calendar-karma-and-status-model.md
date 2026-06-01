*** UID:0000H9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Time, Calendar, Karma, And Status Model

Research date: 2026-05-24

Confidence: medium. Official help provides clear public descriptions, but implementation split between client and server is unknown.

Scope: external public descriptions of in-game time, status/profile pages, karma labels, alignment selection, and experience/status fields that can help identify UI strings and data models.

## In-Game Time

Observed:

- Official help says Nexus time moves eight times faster than real life. Source: [official Time Conversion](https://help.nexustk.com/wiki/wiki/71/time-conversion).
- Official help warns that a pop-up saying to wait `one day` often means one in-game day, not 24 real hours. Source: [official Time Conversion](https://help.nexustk.com/wiki/wiki/71/time-conversion).
- Official conversion examples include one Nexus minute as 7.5 real seconds, one Nexus hour as 7.5 real minutes, one day as 3 real hours, one totem time as 45 real minutes, one week as 21 real hours, and one year/Hyul as 33 days, 16 hours, 48 minutes. Source: [official Time Conversion](https://help.nexustk.com/wiki/wiki/71/time-conversion).
- Official terminology says Yuri/Hyul are used as year terms and says eight Yuris/Hyuls equal one real-world year. Source: [official Nexus Terminology](https://help.nexustk.com/wiki/wiki/70/nexus-terminology).

Reverse-engineering leads:

- Search for `Hyul`, `Yuri`, `totem time`, and timer conversion constants.
- Quest wait logic is likely server-side, but client pop-up text, countdowns, and calendar display may reveal time scaling.

## Status, Profile, And Legend Navigation

Observed:

- Official basic/interface guide says status shows path or Peasant, weapon, armor, helm, hand objects, and detailed stats after paging. It describes vitality, mana, hit probability, damage, AC, and next-level experience. Source: [official basic/interface guide](https://www.nexustk.com/guid_01.html).
- Official Basic Keys says `s` cycles status, `i` expands/collapses inventory, and `+` expands/collapses the spell list. Source: [official Basic Keys](https://help.nexustk.com/wiki/wiki/7/basic-keys).
- Nexus Atlas legend page says legends can be checked by pressing `S` and paging through the status screen, or by clicking another person and paging twice. Source: [Nexus Atlas Legend Marks](https://www.nexusatlas.com/legends/index.php).
- Official Leveling says `Next Level` appears under the second status tab page and the experience bar is in the bottom right under Vita/Mana. Source: [official Leveling](https://help.nexustk.com/wiki/wiki/62/leveling).

Reverse-engineering leads:

- Search for status page labels and next-page navigation.
- A likely UI structure includes multiple character-status pages: equipment/basic stats, level/experience, legends, and possibly profile/portrait.

## Core Numeric Fields

Observed:

- Public documentation names the core display stats as vitality/vita, mana, hit, damage/dam, AC, might, will, grace, protection, healing, and wisdom across status and item database pages. Sources: [official basic/interface guide](https://www.nexustk.com/guid_01.html), [Nexus Atlas Weapons](https://www.nexusatlas.com/weapons/), [Nexus Atlas Hand Items](https://www.nexusatlas.com/armor/handitems.php).
- Official terminology explains AC: positive AC increases damage taken, while negative AC decreases damage taken. Source: [official Nexus Terminology](https://help.nexustk.com/wiki/wiki/70/nexus-terminology).
- Official group-hunting guide describes vitality-based attacks for warriors and mana-based attacks for mages. Source: [official Hunting in a Group](https://help.nexustk.com/wiki/wiki/84/hunting-in-a-group).

Reverse-engineering leads:

- Search for short labels (`Vita`, `Mana`, `AC`, `Hit`, `Dam`, `Might`, `Will`, `Grace`) and longer explanatory text.
- Negative AC behavior should be respected in any reconstructed combat/stat UI documentation, even if the combat calculation is server-side.

## Karma

Observed:

- Official Karma Chart describes levels and approximate point ranges for Snake, Rat, Cat, Squirrel, Rabbit, Jindo Dog, Monkey, Ox, Bear, Tiger, Dragon, Spirit, Angel's Tear, and Angel/Shunnyo. Source: [official Karma Chart](https://help.nexustk.com/wiki/wiki/139/karma-chart).
- Nexus Atlas NeX-Files index lists Karma Information as a useful chart/information area and frames karma as a topic with acquisition/loss questions and a graphical chart. Source: [Nexus Atlas NeX-Files](https://www.nexusatlas.com/nexfiles/index.php).

Reverse-engineering leads:

- Search for karma-rank labels and descriptions.
- Karma may be displayed as named tiers rather than a raw numeric value, and some pages imply multiple points per tier.

## Alignment

Observed:

- Official help lists three alignments: Ming-Ken, Ohaeng, and Kwi-Sin. Source: [official Alignments](https://help.nexustk.com/wiki/wiki/36/alignments).
- Official help says alignments alter the look of abilities and slightly reduce some select spell aethers, such as Desperate Attack for rogues. Source: [official Alignments](https://help.nexustk.com/wiki/wiki/36/alignments).
- Official help says alignment choice becomes available at level 45 via hidden shrines and an Alignment Master, then the character returns to their path guild to inform them. It lists shrine coordinates for Ming-Ken in Islets, Ohaeng in Wilderness, and Kwi-Sin in Arctic Village. Source: [official Alignments](https://help.nexustk.com/wiki/wiki/36/alignments).

Reverse-engineering leads:

- Search for alignment names, `Alignment Master`, shrine coordinates, `Desperate Attack`, aether labels, and spell visual variant resources.
- Alignment may affect display names, visual effects, aether/cooldown values, or all three.

## Open-Question Resolution Notes 2026-05-24

- Time conversion is publicly answered at the behavior level: Nexus time runs eight times faster than real time, and a Nexus day is three real hours. Whether the target client computes this locally or displays server-fed calendar/time remains local.
- Status display is narrowed: official Leveling says `Next Level` appears under the second status tab page and the experience bar is under Vita/Mana. Basic Keys says `s` cycles status. The hard-coded-layout versus server-supplied-panel question remains local.
- Leveling is publicly answered: levels 1-99 use experience; after 99, experience is exchanged at a Midnight Weaver for MGT/GRC/WIL, Vita, or Mana. That supplies UI/search vocabulary but not storage ownership.
- Karma/alignment public sources provide labels and behavior descriptions, but not whether the local target stores enums, display labels, or server-fed legend/status strings.
- Aether/cooldown public sources mention alignment reducing select spell aethers, but public pages do not prove whether cooldown values are client-visible or server-authoritative in the target.

## Open Questions

- Does the target binary compute or merely display Nexus calendar/time conversion?
- Are status pages built from hard-coded layout or server-supplied panel records?
- Are karma and alignment stored as enums, text labels, or server-fed legend/status values?
- Are spell aethers/cooldowns available client-side for display or only server-enforced?
