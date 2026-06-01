*** UID:0000H5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Quest, Dialog, Kill Track, And Progression Script Model

Research date: 2026-05-24

Scope: online-only public research on NexusTK quest structure, NPC dialog keywords, daily/repeatable quest flow, kill tracking, rank quests, alliance quests, and quest-to-legend/item rewards. This is a guide to likely server/client vocabulary and state, not a local binary finding.

Confidence: medium. Official help is strong for public commands and minor-quest location data. Nexus Atlas is fan-maintained but highly detailed and internally consistent for quest pages, legend marks, and alliance mechanics.

## Quest Page Schema

Nexus Atlas quest pages follow a common structure:

- Quest title and category.
- Level required.
- Prerequisite.
- Karma needed.
- How to begin.
- Steps.
- Items lost to sacrifice.
- Stats/karma lost to sacrifice.
- Rewards.
- Legend mark or item gained.

This schema is useful because it mirrors what the game itself must track: eligibility, dialog triggers, inventory checks, creature kills, consumed items, stat/experience costs, reward flags, and legend marks.

## NPC Dialog Keywords

Official help documents public NPC command phrases such as:

- `Quest`: request a minor quest from an NPC.
- `Abandon`: leave a PC subpath.
- `Cleanse`: leave an NPC path.
- `Dismiss`: elder-only PC subpath dismissal.
- Shop and repair phrases such as `What do you buy?`, `What do you sell?`, `Repair all`, and `Repair my item`.
- Banking phrases such as `I will deposit item`, `What have I deposited?`, and quantity forms.
- Travel destination words such as `Kugnae`, `Buya`, `Nagnang`, and `Tangun`.

Nexus Atlas quest pages add more quest-specific keywords:

- Minor quests begin by saying `Quest` to a guildmaster or clan NPC and complete by saying `Complete`.
- Il San rank begins through Bon-Hwa and an `Il San` option.
- Sa san Seyn spell flow uses `Hello`, `Sa san`, `Metal`, `Baekho`, `Hot coal`, `Ju jak`, `Moon wine`, `Hyun moo`, `Golden rabbit`, `Chung ryong`, and `Four guardians`.
- Armor quests use keywords such as `Star`, `Moon`, `Sun`, and `Wind`.

Reverse-engineering implication: NPC dialog handling is likely a command parser with both global verbs and per-NPC/per-quest keyword tables. Some phrases are full sentences, some are single words, and some include item names.

## Minor Quest Model

Official help lists many minor-quest targets with location and cave names. Nexus Atlas explains the flow:

- Minimum level is 5.
- Start by saying `Quest` to a guildmaster or clan NPC.
- The NPC assigns a creature to kill.
- The character receives a temporary legend mark describing the target.
- The player must kill the specified monster and return without invalidating the state.
- The quest can be completed while grouped.
- Mythic creature assignments can accept anything within that Mythic cave family.
- If the assigned target is impractical, saying `Quest` again can remove the quest, with a 48-hour wait before a new one.
- Completion uses `Complete`.
- Rewards include an accumulating minor-quest legend mark and experience; high-rank rewards scale with stats according to Nexus Atlas examples.

Implementation leads:

- Daily or 24-hour eligibility timer.
- Quest-abandon timer distinct from normal repeat timer.
- Assigned creature id or creature-family id.
- Temporary legend/status mark text.
- "Last kill" or quest kill-credit state.
- Group kill-credit sharing.
- Experience reward formula that depends on level and later stats.

## Minor Quest Location Vocabulary

The official minor-quest location page is a compact monster/location/cave vocabulary source. It includes targets across Tangun, Buya, Kugnae, Wilderness, Woodlands, Arctic, Vale, Hamgyong nam-do, Nagnang, Islets, Hausson, Kinung, Forest Crossroads, Southern Koguryo, and Forest of Elders.

Representative target/cave pairs:

- Big bat: Buya Rat Cave.
- Big rat: Kugnae/Wilderness Rat Cave.
- Black rabbit and Shadow crow: Nagnang/Woodlands.
- Arctic deer, Avalanche ogre, Hail ogre, Tempest ogre: Arctic Ogres.
- Cave ogre, Lost spirit, Hill Ogre, Marsh ogre: Hamgyong nam-do cave families.
- Giant spider, trapdoor spider, giant scorpion, pale scorpion: Kugnae Spider Cave.
- Green squirrel: Nagnang Leviathan.
- Iron tiger and Gim-yi: Wilderness Iron Labs.
- Seki and Yachi: Buya Sute's Cave.
- Spring butterfly: Kinung or Forest of Elders.

For local searching, these names help distinguish creature-name tables from map/cave names and quest-target strings.

## Rank Progression Quests

Nexus Atlas describes Il San, Ee San, Sam San, and Sa San as 99+ rank quests. The Il San page illustrates the model:

- Level required: 99.
- Prerequisite: 160,000 vitality or 80,000 mana.
- Begin by reaching Bon-Hwa near the Forever Tree.
- The player selects `Il San`.
- Trials include knowledge, strength, and wealth.
- Trial of Knowledge sacrifices 1.2 billion experience.
- Trial of Strength requires killing a Spirit Rat.
- Trial of Wealth sacrifices coins and well-crafted white ambers.
- Completion grants a legend mark, one dot on the Ctrl-W heroes list, higher visible ordering, stat boosts through Bon-Hwa Immortality, stronger weapon enchantment naming, and subpath item forging where applicable.

This model implies rank state affects visible social UI, spell eligibility, item forging, enchantment labels, and stat caps or temporary boosts.

## Armor And Prerequisite Quest Chain

The Nexus Atlas quest index and legend-mark pages show a level-gated armor chain:

- `Blessed by the Stars`: prerequisite for Star armor and a legend mark.
- Star armor: say `Star` to guildmaster at level 66.
- Moon armor: say `Moon` to guildmaster at level 76.
- Sun armor: say `Sun` to guildmaster at level 86.
- Wind armor: say `Wind` to Mountain Scribe at level 96.

The quest legend page also links Defender marks, Orb quest marks, Nagnang quest marks, lesser alliances, greater alliances, and mark/rank quests. This gives a strong taxonomy for checking legend-mark categories and quest flags.

## Alliance Quest And Kill Track Model

Nexus Atlas Alliance Tips gives unusually implementation-like detail about the Nexus Kill Track system:

- Kill credit can be gained while grouped, and everyone in the group receives credit.
- Starting a Lesser or Greater Alliance resets Kill Track to zero.
- Kill Track records creature type and number killed.
- Character information, including Kill Track, is saved in the game database on logoff.
- Only the last eight creature types are saved.
- Each creature type can record up to 255 kills according to the fan explanation.
- Killing a new type pushes older types down the list; a ninth type can be lost on save.
- Lesser Alliances reserve two saved slots for two boss types.
- Multiple Lesser Alliances can be started after the reset, but doing several leaves fewer "free" creature-type slots.
- Greater Alliances involve six boss types, leaving two mistake slots.
- Greater Alliance NPCs check boss types and item inventory before taking items and rewarding.

This is one of the most valuable external leads for server data structures. Even if exact implementation differs, the public behavior strongly implies an ordered recent-kill array per character, per-creature counters, group kill-credit propagation, quest reset behavior, and save-time truncation.

## Sa San Seyn Quest As Script Example

The Seyn quest is a high-rank scripted example:

- Entry condition: Sa san stats.
- Start NPC: Seyn in the center of Vortex.
- Dialog sequence begins with `Hello`.
- Four guardian shrines are visited at named Wilderness coordinates.
- Each guardian step uses a keyword, an item-gathering substep, then a guardian keyword that consumes a bundle and grants an essence.
- One step requires slaying a Golden rabbit in Mythic Rabbit 3 before saying `Golden rabbit`.
- Final return to Seyn with `Four guardians` consumes collected essences and teaches a spell.

This script combines rank checks, NPC location checks, shrine coordinates, repeated keyword states, item bundle validation, kill validation, essence flags, and spell reward assignment.

## Quest Rewards And Legend Marks

Nexus Atlas quest legend marks show several reward/flag categories:

- General quest marks such as Dog Linguist, Ice Beast, Sute, Totem Mastery, and Minor Quests.
- Armor quest marks and intermediate armor-chain marks.
- Defender marks tied to kingdom army and special dyes.
- Geomancer orb marks by element: earth, fire, metal, water, wood.
- Nagnang path and Leviathan marks.
- Lesser alliance marks for each Mythic animal family, with favor-item rewards.
- Greater alliance and rank marks.

The key point for local analysis is that legend marks are not just achievements. They can be prerequisites, visible profile text, item rewards, role credentials, quest state, and unlock flags.

## Client/Server Split Considerations

Most quest logic is probably server-authoritative, but external sources still imply client-facing pieces:

- NPC dialog text and command entry.
- Status/profile/legend display.
- Quest-related message strings.
- Item names and icons in requirement/reward UI.
- Creature and cave names shown in messages.
- Heroes-list dots and rank ordering.
- Spell names after quest completion.
- Map/coordinate display where quest steps use locations.

Do not assume the client contains full quest scripts. It may only display strings and send typed speech, movement, item, and attack events to the server.

## Reverse-Engineering Leads

Search terms:

- Global NPC commands: Quest, Complete, Abandon, Cleanse, Dismiss, Repair all, What do you buy, What do you sell, I will deposit.
- Rank terms: Il San, Ee San, Sam San, Sa San, Bon-Hwa, Forever tree, Trial of Knowledge, Trial of Strength, Trial of Wealth.
- Armor terms: Blessed by the Stars, Star, Moon, Sun, Wind, Mountain Scribe.
- Kill Track terms: Alliance, Lesser Alliance, Greater Alliance, Avenger, Spirit, Mythic, favor.
- Seyn terms: Seyn, Vortex, Four guardians, Baekho essence, Ju jak, Hyun moo, Chung ryong, Golden rabbit.
- Legend categories: Quests, Armor Quests, Defender, Orb Quest Marks, Nagnang Quests, Lesser Alliances, Greater Alliances.

Potential structures:

- Quest flag table or legend-mark table.
- Recent kill-type array with up to eight saved entries.
- Kill counter per creature type, possibly byte-sized or capped at 255.
- NPC speech command parser.
- Item bundle validation and consumption routine.
- Reward application routine for items, experience, karma, stats, marks, spells, and social UI state.
- Group kill-credit propagation.

## Sources

- [Official NexusTK verbal commands](https://help.nexustk.com/wiki/wiki/40/verbal-commands)
- [Official NexusTK minor quest locations](https://help.nexustk.com/wiki/wiki/61/minor-quest-locations)
- [Nexus Atlas quests index](https://www.nexusatlas.com/quests/index.php)
- [Nexus Atlas minor quest](https://www.nexusatlas.com/quests/minorquest.php)
- [Nexus Atlas Il San quest](https://www.nexusatlas.com/quests/ilsan.php)
- [Nexus Atlas alliance tips](https://www.nexusatlas.com/quests/alliancetips.php)
- [Nexus Atlas Sa san Seyn Spell quest](https://www.nexusatlas.com/quests/seynspell.php)
- [Nexus Atlas quest legend marks](https://nexusatlas.com/legends/quests.php)

## Open Questions

- Open-question pass 2026-05-24: official Verbal Commands confirms `Quest` as a public NPC command for requesting a minor quest. That is a strong string/dialog lead but not proof of client-side quest scripting.
- Open-question pass 2026-05-24: official Leveling confirms status/progression UI vocabulary around `Next Level`, Vita/Mana, level 99, and Midnight Weaver post-99 exchange. This helps rank/progression quest interpretation but not local quest-state storage.
- Open-question pass 2026-05-24: Kill Track remains mostly server/social from public sources reviewed here. No public source in this pass proved that recent-kill arrays or last-killed creature state are serialized to the client.
- Open-question pass 2026-05-24: global NPC command parsing remains local/protocol work. Public pages document the user grammar, not the packet form.

- Whether Kill Track exists in the target server only or has any client-visible state.
- Whether quest state is represented in local client memory beyond received text and legend/status display.
- Whether "last killed creature" or recent-kill arrays are ever serialized to the client.
- Whether the target binary contains hardcoded global NPC commands or sends all speech as opaque chat to the server.
