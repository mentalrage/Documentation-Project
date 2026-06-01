*** UID:0000GR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Crafting, Skills, Resources, And Creation System

Research date: 2026-05-24

Scope: online public information about NexusTK crafting families, skill ranks, tools, resource chains, food/potion/scroll item effects, and Creation-system leads. This is external research for reverse-engineering context only.

Confidence: medium. Nexus Atlas provides dense fan-maintained crafting and item references, while official help confirms keyboard entry points and general money-making/resource concepts. Treat recipe details and prices as leads until locally confirmed.

## Crafting Family Taxonomy

Nexus Atlas divides crafting into five broad types:

- Gathering;
- Refining;
- Manufacturing;
- Cooking;
- Mental.

Gathering includes Farmers, Fisherman, Miners, and Woodcutters. Refining includes Smelter, Weaver, and Gemcutter. Manufacturing includes Carpenter, Jeweler, Smith, and Tailor. Cooking includes Food Preparation and Chef. Mental skills include Alchemist and Scribe and are described as spell-caster skills.

Reverse-engineering leads:

- These family and skill names are useful as string seeds, but they may be server-side skill labels rather than client-side enum names.
- The broad taxonomy suggests the client may need generic skill-result display, item-use prompts, and inventory updates more than per-recipe logic.
- If a local Creation UI exists, inspect whether it knows recipe families or simply sends selected ingredient/item combinations to the server.

## Skill Ranks And Specialization

Nexus Atlas lists crafting ranks from low to high:

- Novice;
- Apprentice;
- Accomplished;
- Adept;
- Talented;
- Skilled;
- Expert;
- Master;
- Grand Master;
- Champion;
- Legendary.

The crafting legend page says refining paths can be advanced by everyone up to Accomplished, but higher progress requires specialization, and only one refining specialization can be selected.

Reverse-engineering leads:

- Rank names may appear in character status, legends, NPC dialogue, guide text, or crafting-result messages.
- Specialization is likely server-owned state. Client evidence may be limited to NPC text, legend marks, and skill labels.
- Search for the exact rank names near crafting skill names and "agreement" item names.

## Official Client Entry Points

Official Basic Keys documents `Shift+i` as the Creation system. The same key reference documents inventory actions for using/eating/wielding/wearing items, immediate equip, pickup, drop, hand, and exchange.

Reverse-engineering leads:

- `Shift+i` is the main client-side anchor for Creation-system UI or command dispatch.
- Inventory action handlers likely feed the Creation system by selecting, using, or combining item stacks.
- The server likely validates recipes, consumes inputs, advances skill state, and returns outputs/failure products.

## Gathering Chains

Gathering skills and visible resources from Nexus Atlas:

- Farmers use a Basic sickle and collect rice, peas, and wheat.
- Fisherman use no listed tool and collect fish.
- Miners use a Mining shovel and Mining pick and collect ore and gems.
- Woodcutters use an Axe and collect Ginko Wood and Silver Tree Branch.

The official Making Money page emphasizes Ginko wood, Wool, and Ore as commodity sources, and says mining and woodcutting improve with use, yielding more and better resources.

Reverse-engineering leads:

- Gather actions may be map/tile/NPC interactions rather than inventory-only actions.
- Tool names are useful for item-table and use-action searches.
- Improvement with use implies skill progress/state is server-side, but client may show rank text, failure text, or result messages.

## Mining, Smelting, And Smithing Chain

Nexus Atlas skills and rocks pages describe a metal/resource chain:

- Mining yields ore grades and gems.
- Ore grades include poor, medium, high, and very high quality references.
- Smelting converts ore into Metal or Fine Metal and can fail into Slag.
- Smithing uses Metal/Fine Metal and can fail into Spent Metal.
- Mining tools include Mining shovel and Mining pick.
- Smelting requires or references a Smelting Agreement.
- Gems and minerals include Amber, Amethyst, Diamond, Topaz, Quartz, Onyx, Onyx Shard, Obsidian, Limestone, Gold ore, and Silver Ore.

Reverse-engineering leads:

- Search for ore names with bracketed quality notation such as `Ore [poor]`, `Ore [med]`, `Ore [high]`, and `Ore [very high]`.
- Failure products are high-value strings: `Slag` and `Spent Metal`.
- Mining and gem outputs overlap with spell, quest, sale, and crafting requirements, so item records may be reused across several systems.

## Wool, Weaving, Tailoring, And Cloth Chain

Nexus Atlas skills pages describe cloth-related resources:

- Wool is a common gathered/drop resource.
- Weaving uses Weaving Tools and Fine Weaving Tools.
- Outputs include Cloth and Fine Cloth.
- Tailoring is the manufacturing skill associated with cloth resources.

Reverse-engineering leads:

- Search for `Wool`, `Cloth`, `Fine Cloth`, `Weaving Tools`, and `Fine Weaving Tools`.
- If recipes are local, expect cloth inputs to appear near tailoring output items; if server-owned, local evidence may only be inventory names and result messages.
- Official money guidance mentions Wool as a commodity, so it may appear in both crafting and market-oriented help text.

## Woodcutting, Carpentry, And Quiver Chain

Nexus Atlas skills pages describe wood-related resources:

- Woodcutting uses an Axe.
- Main resources include Ginko Wood and Silver Tree Branch.
- Carpentry uses wood resources for manufactured outputs.
- Quiver components appear as closed seasonal/elemental quiver item names.
- Wood Scraps are listed as a wood-skill failure or byproduct.

Reverse-engineering leads:

- Search for `Ginko Wood`, `Silver Tree Branch`, `Wood Scraps`, `Axe`, and quiver family names.
- Quiver items may connect crafting to ammunition/arrows and equipment display.
- Wood Scraps are a strong failure-output string.

## Gemcutting And Amber Chain

Nexus Atlas skills and rocks pages identify amber and gemcutting chains:

- ambers include Amber, Dark amber, Flame amber, White amber, Yellow amber, and other special amber forms;
- gemcutting outputs include crafted, tarnished, and well-crafted amber variants;
- Well Crafted White Amber is called out as an Il San Quest requirement on Nexus Atlas;
- the official Making Money page identifies ambers as an important new-player money source.

Reverse-engineering leads:

- Amber names are likely dense item-table hits and may appear in spell/quest requirements.
- `Well Crafted White Amber` is a good cross-system search term because it ties crafting output to rank progression.
- Case, spacing, and punctuation may vary between item tables and quest text.

## Food Preparation, Chef, And Health Restoration

Nexus Atlas food references list food items with vitality restoration amounts and obtain methods. Examples include meats, fish, fruit, acorns, ginseng, mountain ginseng, cooked fish, broiled meat, roast chicken, and prepared foods. Food Preparation also produces flour from grain resources, and cooking paths connect to Chef.

The food page also includes special cases such as prepared/cooked items that restore different vitality amounts depending on spouse proximity. Potions and food overlap because health-restoration items include red, blue, yellow, and violet potions.

Reverse-engineering leads:

- Food items can be normal inventory consumables, skill outputs, monster drops, NPC shop goods, and quest resources.
- Search for `Food Preparation`, `Chef`, `Flour`, `Noodles`, `Ginseng`, `Mountain ginseng`, `Cooked fish`, `Broiled meat`, and `Roast chicken`.
- Conditional restoration behavior is likely server-side, but the item-use result text may be client-visible.

## Alchemy, Scribe, Potions, And Scrolls

Nexus Atlas skills and potion/scroll pages describe mental-skill outputs and consumables:

- alchemy connects to potions, powders, poisons, and amber-derived ingredients;
- scribe resources include Ink, Moon Paper, White Paper, scrolls, and amber ingredients;
- potion effects include sanctuary, strength, harden armor/body, purge/poison removal, vitality restoration, regeneration, and Sage toggle behavior;
- scroll effects include return-to-inn, clan-hall travel, defensive protection, immortality, invocation, and curse protection.

Reverse-engineering leads:

- Potions and scrolls are good probes for item-use effect IDs because they map to visible status/spell effects.
- Search for `Ink`, `Moon Paper`, `White Paper`, `Scroll of Defense`, `Scroll of Immortality`, `Scroll of Invocation`, `Scroll of Protection`, `Yellow scroll`, `Kindred talisman`, `White potion`, and potion color names.
- The client may know display names and icons while the server applies actual status changes.

## Creation-System Combination Leads

Nexus Atlas key references note that a complete trigram key set can be combined through the Creation system into a `Trigram Set`. Nexus Atlas skills pages also list crafted components, failure outputs, and recipe-adjacent item families.

Creation-system search seeds:

- `Creation`
- `Trigram Set`
- `Basic sickle`
- `Mining shovel`
- `Mining pick`
- `Smelting Agreement`
- `Weaving Tools`
- `Fine Weaving Tools`
- `Wood Scraps`
- `Spent Metal`
- `Slag`
- `Fine Metal`
- `Fine Cloth`

Reverse-engineering leads:

- If the target client contains recipe data, expect item combinations, output names, and possibly quantity requirements near Creation UI handlers.
- If recipes are server-owned, local code may only open a Creation window and send selected item IDs/slots.
- Failure outputs can help distinguish local recipe tables from generic server-result handling.

## Legend Marks And Social Proof

Nexus Atlas crafting legend marks show that crafting progress is publicly visible through legend/profile marks. Crafting ranks and subpath services also intersect with social identity: Merchants have trade/economist/treasure-hunter marks, and subpaths provide services or quests that may consume crafted goods.

Reverse-engineering leads:

- Crafting can surface in character legend UI even if actual recipes are server-owned.
- Search legend/profile formatting code for rank strings and crafting skill names.
- Public marks may use phrasing different from internal skill names.

## Likely Client/Server Ownership

Likely client-owned or client-visible:

- `Shift+i` Creation-system entry;
- inventory item selection and use/eat/equip actions;
- crafting skill/rank labels in status or legends;
- item names, icons, and possibly tooltips;
- result/failure messages and consumed/created item updates;
- visible potion/scroll status text or spell-effect icons.

Likely server-owned:

- skill experience and rank advancement;
- resource yield rates;
- recipe validation;
- ingredient consumption and output grant;
- failure probability and failure products;
- vitality/mana restoration and status-effect application;
- specialization locks.

Shared protocol candidates:

- open Creation UI;
- submit item/slot combination;
- skill action request from map/tile/NPC interaction;
- inventory delta response;
- skill-rank/status update;
- consumable item-use response;
- error/failure message response.

## Open Questions

- Open-question pass 2026-05-24: official Basic Keys confirms a client-visible Creation-system entry point through `Shift+i`. That answers the public UI hook, but not whether recipes or ingredient validation are local.
- Open-question pass 2026-05-24: official and Nexus Atlas sources provide skill/resource/rank vocabulary, but public pages do not reveal whether rank names are executable strings, resource strings, or server-sent labels in the target.
- Open-question pass 2026-05-24: potion/scroll names and effects are public item/spell vocabulary. Whether item use invokes spell-effect code or a separate item-effect path remains local.

- Does the target client contain local recipe data, or only a generic Creation UI?
- Are skill rank names stored in the executable, resource files, or sent by the server?
- Are potion/scroll effect names implemented as item-use effects, spell effects, or both?
- How are stack quantities and ingredient slots represented in Creation-system packets?
- Are gathered resource nodes represented in map data, object data, or entirely server-side interactions?

## Sources

- [Official help: Basic Keys](https://help.nexustk.com/wiki/wiki/7/basic-keys)
- [Official help: Making Money in Nexus](https://help.nexustk.com/wiki/wiki/133/making-money-in-nexus)
- [Nexus Atlas: Crafting legend marks](https://www.nexusatlas.com/legends/crafting.php)
- [Nexus Atlas: Items for Skills](https://www.nexusatlas.com/nexfiles/skills.php)
- [Nexus Atlas: Rocks and Minerals](https://www.nexusatlas.com/nexfiles/rocks.php)
- [Nexus Atlas: Health Restoration](https://www.nexusatlas.com/nexfiles/food.php)
- [Nexus Atlas: Potions and Scrolls](https://www.nexusatlas.com/nexfiles/potions.php)
- [Nexus Atlas: Keys](https://www.nexusatlas.com/nexfiles/keys.php)
- [Nexus Atlas: What is Nexus?](https://www.nexusatlas.com/what.php)
- [Nexus Atlas: Subpaths](https://www.nexusatlas.com/subpaths/index.php)
- [Nexus Atlas: Subpath legend marks](https://www.nexusatlas.com/legends/subpaths.php)
