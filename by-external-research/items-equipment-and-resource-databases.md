*** UID:0000H0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Items, Equipment, And Resource Databases

Research date: 2026-05-24

Confidence: medium. Nexus Atlas item/equipment pages are fan-maintained and price data is explicitly not authoritative, but their field vocabulary is very useful for client UI, string, and resource searches.

Scope: external item/equipment/resource information from Nexus Atlas and official help, emphasizing data fields and user-facing messages that may map to local client UI, item tooltips, resource records, and inventory/equipment handlers.

## Nexus Atlas Item Database Surface

Observed:

- Nexus Atlas has a general Items section with categories including arrows, bombs, crafts, drops, events, keys, mana, potions, quests, rocks, scrolls, shops, spells, vita, Woodlands items, extinct, and other. Source: [Nexus Atlas Items](https://www.nexusatlas.com/items/).
- Nexus Atlas has a Weapons section organized by type: axes, bows, carnage prizes, clubs, enchanted weapons, extinct weapons, fans, spears/staves, swords/knives, toys, Vortex, whips, plus event weapon groups. Source: [Nexus Atlas Weapons](https://www.nexusatlas.com/weapons/).
- Nexus Atlas has armor/equipment sections for hand items, event hand items, Vortex hand items, mage/poet/rogue/warrior/peasant gear, wisdom clothes, helms, shields, coats, subaccessories, and extinct items. Sources: [Nexus Atlas Hand Items](https://www.nexusatlas.com/armor/handitems.php), [Nexus Atlas Vortex Hand Armor](https://www.nexusatlas.com/armor/vortexhand.php).
- Nexus Atlas warning: Merchant-supplied prices are estimates and not final authority. Source: [Nexus Atlas Weapons](https://www.nexusatlas.com/weapons/).

Reverse-engineering leads:

- External database categories are good string seeds for inventory filters, item database table names, or resource grouping comments, but not proof of original client-side data organization.
- If local code has item tooltip or item-inspection formatting, fields below should appear together or in nearby formatting functions.

## Equipment Field Vocabulary

Observed from Nexus Atlas weapons/armor pages:

- Weapon records include name, durability, short/long damage, AC, hit, damage bonus, vita, mana, might, will, grace, protection, healing, path/class/level requirements, might-to-wield, special info, obtain method, spell casts, market price, and NPC sale price. Source: [Nexus Atlas Weapons](https://www.nexusatlas.com/weapons/).
- Armor and hand-item records use a similar stat block: durability, AC, hit, dam, vita, mana, might, will, grace, protection, healing, wisdom, gender/path/level requirement, merchant suggested price, obtain method, special info, detailed info, NPC sells, and NPC buys. Sources: [Nexus Atlas Hand Items](https://www.nexusatlas.com/armor/handitems.php), [Nexus Atlas Vortex Hand Armor](https://www.nexusatlas.com/armor/vortexhand.php).
- Nexus Atlas specifically notes separate ground and hand graphics for weapons, useful for recognizing an item on the floor versus equipped on a character. Source: [Nexus Atlas Weapons](https://www.nexusatlas.com/weapons/).
- Special info can describe constraints such as bonded, break on death, unrepairable, or arena-only behavior. Source: [Nexus Atlas Weapons](https://www.nexusatlas.com/weapons/).

High-value field strings:

- `Durability`
- `Damage`
- `AC`
- `Hit`
- `Dam`
- `Vita`
- `Mana`
- `Might`
- `Will`
- `Grace`
- `Protection`
- `Healing`
- `Wisdom`
- `Special Info`
- `How to Obtain`
- `Casts`
- `NPC Sells`
- `NPC Buys`
- `Market Price`
- `Might to Wield`

Reverse-engineering leads:

- Search for stat labels and item-use restrictions in client strings.
- The weapon data model appears to distinguish short/long damage (`S` and `L`) and carried/equipped graphics. This may map to item metadata, sprite IDs, and character equipment overlay resources.
- `Wisdom` appears in Nexus Atlas item stats and event item notes, but one archive report explicitly says players did not know what wisdom did at that time. Treat it as a displayed stat field, not confirmed behavior.

## Item Restriction And Status Messages

Observed from Nexus Atlas Weapons:

- Example failure/status messages include unregistered pickup restriction, bonded owner restriction, path restriction, insufficient might, and insufficient level. Source: [Nexus Atlas Weapons](https://www.nexusatlas.com/weapons/).

Search leads:

- `You are afraid to pick up such a powerful item`
- `There is an owner for that`
- `Your Path has forbidden itself from this vulgar implement`
- `You can't lift it above your waist much less wield it`
- `You need more experience`

Reverse-engineering leads:

- These are strong candidates for client-visible server messages. If present locally, they may sit near item pickup/equip failure formatting.
- Item restrictions to inspect locally: registration, owner/bonding, path, level, might, arena-only, transfer/drop/exchange/deposit/repair flags.

## Vortex And Rank-Scaled Equipment

Observed:

- Nexus Atlas Vortex body armor and Vortex hand-armor pages present rank-tiered item families. Vortex hand items use prefixes such as `New`, `Worn`, `Old`, `Ancient`, and `Antique`, with rank requirements from level 99 through Il san, Ee san, and Sam san examples. Source: [Nexus Atlas Vortex Hand Armor](https://www.nexusatlas.com/armor/vortexhand.php).
- Vortex hand items list boss/source names and cave/tribe context such as Hunter, Water, Wind, Hillman, Dread, Magus, Shadow, and other Vortex cave groups. Source: [Nexus Atlas Vortex Hand Armor](https://www.nexusatlas.com/armor/vortexhand.php).
- Vortex body armor records include path/gender body-armor families with rank gates and majority-group rank notes. Source: [Nexus Atlas Vortex Body Armor](https://nexusatlas.com/armor/vortexarmor.php).

Reverse-engineering leads:

- Search for Vortex item prefixes and cave/source names alongside stat labels.
- Rank-scaling item families may explain repeated resource/stat records with systematic prefix changes.
- If client has item compare/tooltip code, Vortex pages provide dense examples of all stat fields being populated.

## Resource, Skill, Potion, Food, And Key Items

Observed:

- Nexus Atlas NeX-Files skills page groups skill-related items into metal, cloth, wood, gem, scribe, alchemy, and food skills. Source: [NeX-Files: Items for Skills](https://www.nexusatlas.com/nexfiles/skills.php).
- Metal-skill examples include ore grades, metal/fine metal, mining shovel, mining pick, slag, gold/silver ore, ambers, and gems. Source: [NeX-Files: Items for Skills](https://www.nexusatlas.com/nexfiles/skills.php).
- Cloth examples include wool, cloth, fine cloth, weaving tools, and fine weaving tools. Wood examples include axe, ginko wood, silver tree branch, quiver components, and wood scraps. Source: [NeX-Files: Items for Skills](https://www.nexusatlas.com/nexfiles/skills.php).
- Scribe/alchemy examples include white paper, moon paper, ink, scrolls, potions, powdered ambers, poison for darts, and potion ingredients. Source: [NeX-Files: Items for Skills](https://www.nexusatlas.com/nexfiles/skills.php).
- Mana restoration items have fields for mana given, vita taken, uses per object, and source. Source: [NeX-Files: Mana Restoration](https://www.nexusatlas.com/nexfiles/mana.php).
- Potions/scrolls list use effects such as sanctuary, poison removal, healing, regeneration, return-to-inn, harden body, invoke, curse protection, and clan-hall travel. Source: [NeX-Files: Potions and Scrolls](https://www.nexusatlas.com/nexfiles/potions.php).
- Keys include totem keys, trigram keys, and miscellaneous keys. Totem keys change personal totems, support NPC subpath selection, and participate in lesser alliances. A complete trigram key set can be combined through the Creation system into a `Trigram Set`. Source: [NeX-Files: Keys](https://www.nexusatlas.com/nexfiles/keys.php).
- Food/vita-restoration entries include vitality restored and source. Common examples include acorns, antlers, potions, meat, fish, ginseng, and cooked/prepared foods. Source: [NeX-Files: Health Restoration](https://www.nexusatlas.com/nexfiles/food.php).
- Rocks/minerals include amber variants, ore grades, gems, slag, onyx shard, and spell/crafting/sale uses. Source: [NeX-Files: Rocks and Minerals](https://www.nexusatlas.com/nexfiles/rocks.php).

Reverse-engineering leads:

- Search inventory/use handlers for `uses per object`, vita/mana tradeoff, and item-use effects.
- Search Creation system logic for `Trigram Set`, quiver components, scribe recipes, and skill failure outputs such as `Slag`, `Spent Metal`, and `Wood Scraps`.
- Search item-name resources for ore grades with bracket notation: `Ore [poor]`, `Ore [med]`, `Ore [high]`, `Ore [very high]`.

## Official Client/Inventory Linkage

Observed:

- Official Basic Keys include inventory expand/collapse, spell list expand/collapse, eat/use/wield/wear/take-off, immediate equip, pickup, pickup all, surrounding pickup, hand, hand all, drop, drop all, and exchange. Source: [official Basic Keys](https://help.nexustk.com/wiki/wiki/7/basic-keys).
- Official download page says registration unlocks access to more spells, items, maps, boards, clans, subpaths, and profile/portrait customization. Source: [official download page](https://www.nexustk.com/download_2.html).
- Nexus Atlas archives say Kruna item-shop items could be deposited and repaired but not transferred, dropped, or exchanged. Source: [November 2006 archive](https://www.nexusatlas.com/archives/mainpage-archive-11-2006.php).

Reverse-engineering leads:

- Inventory UI should support both item action verbs and item restrictions.
- If the target binary is post-item-shop, search for item flags around transfer/drop/exchange/deposit/repair.

## Open Questions

- Open-question pass 2026-05-24: official Basic Keys confirms client-visible item action surfaces for inventory, eat/use/wield/wear/take off, immediate equip, pick up, drop, hand, and exchange. That answers user-facing controls, not local item metadata ownership.
- Open-question pass 2026-05-24: Nexus Atlas item/equipment/resource pages remain useful for names and presentation fields, but public pages do not prove that DAT files store stats or restriction text.
- Open-question pass 2026-05-24: item-shop archive reports define restrictions such as cannot transfer/drop/exchange and can deposit/repair. The public sources do not say whether those messages are client-local or server-sent.

- How much item metadata is client-local versus transmitted by the server?
- Do DAT resources store item stat records, only sprites, or both?
- Are ground/equipped graphics linked by item ID, naming convention, or a separate resource table?
- Are item restriction messages stored client-side in the target binary or sent from the server?
