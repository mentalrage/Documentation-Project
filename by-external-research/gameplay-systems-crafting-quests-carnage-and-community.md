*** UID:0000GV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Gameplay Systems, Crafting, Quests, Carnage, And Community

Confidence: medium. Official help is strong for documented commands and carnage level bands. Nexus Atlas is strong for vocabulary and coverage, but fan-maintained and version-sensitive.

Scope: public descriptions of major systems that can explain client UI surfaces, string tables, status displays, resource names, event flows, and packet categories.

## Quest And Legend-Mark Structure

Observed:

- Nexus Atlas quest index divides content into legend-mark quests, 99+ quests and ranks, Hamgyong quests, Mythic Alliances, armor quests, Nagnang quests, item quests, other adventures, seasonal quests, extinct quests, and tutor quests. Source: [Nexus Atlas quests index](https://www.nexusatlas.com/quests/index.php).
- Nexus Atlas legend-mark pages show quests, armor quests, defender marks, Nagnang quests, alliances, ranks, alignment, events, crimes, Nexus roles/jobs, skills, subpaths, and other categories as durable achievement/identity records. Source: [Nexus Atlas quest legend marks](https://nexusatlas.com/legends/quests.php).
- Official verbal commands include `Quest` for requesting a minor quest from an NPC. Source: [official Verbal Commands](https://help.nexustk.com/wiki/wiki/40/verbal-commands).

Reverse-engineering leads:

- Search for `Legend`, `Quest`, `Minor Quest`, `Alliance`, `Blessed by the Stars`, `Star Armor`, `Moon Armor`, `Sun Armor`, `Wind Armor`, `Totem Mastery`, and rank quest names.
- Legend marks may appear in profile/status UI, persistent character data, or server-fed text. Do not assume all legend data is client-local.

## Crafting And Skill Families

Observed from Nexus Atlas:

- Crafting is grouped into five categories: Gathering, Refining, Manufacturing, Cooking, and Mental. Source: [Nexus Atlas crafting legend marks](https://www.nexusatlas.com/legends/crafting.php).
- Gathering includes farming, fishing, mining, and woodcutting. Farming uses a Basic sickle; mining uses shovel/pick; woodcutting uses an axe. Source: [Nexus Atlas crafting legend marks](https://www.nexusatlas.com/legends/crafting.php).
- Refining includes smelting, weaving, and gemcutting. Atlas notes all paths can do these to Accomplished, but a character must specialize for further advancement and can specialize in only one. Source: [Nexus Atlas crafting legend marks](https://www.nexusatlas.com/legends/crafting.php).
- Manufacturing includes carpentry, jewelering, smithing, and tailoring, with only one manufacturing choice. Source: [Nexus Atlas crafting legend marks](https://www.nexusatlas.com/legends/crafting.php).
- Cooking includes food preparation and chef; mental skills include alchemist and scribe for spell casters. Source: [Nexus Atlas crafting legend marks](https://www.nexusatlas.com/legends/crafting.php).
- Skill ranks span Novice through Legendary in the Atlas tables. Source: [Nexus Atlas crafting legend marks](https://www.nexusatlas.com/legends/crafting.php).

Reverse-engineering leads:

- Search for skill names, rank names, crafting tool names, and resource outputs such as `Metal`, `Fine metal`, `Cloth`, `Fine cloth`, `Flour`, `Potions`, and `Scrolls`.
- The `Creation system` key binding in official help may be the client entry point for some combine/crafting UI. Source: [official Basic Keys](https://help.nexustk.com/wiki/wiki/7/basic-keys).

## Carnage, PVP, And Events

Observed:

- Nexus Atlas describes Carnages as arena games with teams named ash, fire, river, and snow. Different carnage types have different objectives, arenas, rules, prizes, and legend marks. Source: [Nexus Atlas carnage section](https://www.nexusatlas.com/carnage/index.php).
- Nexus Atlas names Carnage categories including Bloodlust, Carnage of Riches, Crusades, Elixir Wars, Fox Hunt, and Ultimate Gauntlet. Source: [Nexus Atlas carnage section](https://www.nexusatlas.com/carnage/index.php).
- Official help lists carnage level/stat bands and entry fees for Riches, Bloodlusts, Elixir Wars, Fox Hunts, and Tangun Academy carnages. It also notes Riches daily win/prize limits and unlimited Bloodlust/Elixir wins. Source: [official Carnage Levels](https://help.nexustk.com/wiki/wiki/39/carnage-levels).
- A January 2006 archive patch note says carnage hosts gained the ability to periodically view how many participants from each team remained alive. Source: [January 2006 archive](https://www.nexusatlas.com/archives/mainpage-archive-1-2006.php).

Reverse-engineering leads:

- Search for team color names, carnage category names, `Carnage Staff`, `Bloodlust`, `Riches`, `Elixir`, `Fox Hunt`, `Crusade`, `Ultimate Gauntlet`, `Academy`, and participant-count UI strings.
- Carnage support may include separate map instances, scoreboard windows, team-color overlays, observer/host privileges, and event registration restrictions.

## Community Organizations And Social Roles

Observed:

- Official community links page lists clans, armies, judges, tutors, all players, base paths, and subpaths. It also links Nexus Atlas as a fan/community information site. Source: [official community page](https://www.nexustk.com/community.html).
- Nexus Atlas says the game has social organizations and in-game job positions including clans, tribes, armies, ministries, judges, tutors, and PVP game hosts. Source: [Nexus Atlas: What is Nexus?](https://www.nexusatlas.com/what.php).
- Nexus Atlas PC subpaths are player-run and include application/training processes, scrolls, guides, elders, and roleplay expectations. Source: [Nexus Atlas subpaths](https://www.nexusatlas.com/subpaths/index.php).
- Current Nexus Atlas front page includes live server-status style categories such as total users, Nation, Carnage, Event, and House, showing the fan site tracks active population grouping. Source: [Nexus Atlas main page](https://www.nexusatlas.com/).

Reverse-engineering leads:

- Search for org/channel labels: `Clan`, `Army`, `Ministry`, `Judge`, `Tutor`, `Primogen`, `Elder`, `Guide`, `House`, `Nation`, `Event`, `Carnage`.
- Official key bindings and verbal commands imply chat routing for clan, group, subpath, novice, whispers, archon report, shout, and boards/mail. Sources: [official Basic Keys](https://help.nexustk.com/wiki/wiki/7/basic-keys), [official Verbal Commands](https://help.nexustk.com/wiki/wiki/40/verbal-commands).

## Economy, Banking, And Item Shop

Observed:

- Official verbal commands document bank deposit and count queries, NPC buy/sell flows, repair, and item hand/drop/exchange actions. Source: [official Verbal Commands](https://help.nexustk.com/wiki/wiki/40/verbal-commands).
- The official site links to a secure KRU item shop/account flow. Source: [official main page](https://www.nexustk.com/main.html).
- Nexus Atlas archive reports that the Kruna item shop opened on the NexusTK webpage on November 6, 2006. The same report says purchases were delivered through Messenger/parcel after a short wait, and item-shop items could not be transferred, dropped, or exchanged, but could be deposited and repaired. Source: [November 2006 archive](https://www.nexusatlas.com/archives/mainpage-archive-11-2006.php).
- April 2011 archive notes item-shop inventory expansion up to 52 slots after the default inventory increased to 27. Source: [April 2011 archive](https://www.nexusatlas.com/archives/mainpage-archive-4-2011.php).

Reverse-engineering leads:

- Search for `Kruna`, `Item Shop`, `Messenger`, `parcel`, `Recharge Kruna`, `deposit`, `repair`, transfer restrictions, and inventory-capacity constants.
- Economy logic may be server-authoritative, but UI text, item flags, and inventory capacity display are likely represented client-side.

## Open Questions

- Open-question pass 2026-05-24: public sources confirm user-facing generic controls for Creation (`Shift+i`), boards (`b`), post (`p`), mail (`Shift+m`), inventory, spell list, exchange, and verbal/NPC commands. They do not prove whether each system uses custom screens or generic list/choice dialogs internally.
- Open-question pass 2026-05-24: item-shop purchase/recharge is publicly web/account side in the November 2006 archive, while delivery appears in-game through Messenger parcels. That narrows item-shop/account flow to a web/server plus client-parcel split.
- Open-question pass 2026-05-24: current official community pages provide organization names and categories, but local enum/server-fed representation remains unresolved.

- Which system text is hard-coded in the client versus transmitted by the server?
- Are crafting and quest UIs generic list/choice dialogs or custom per-system screens?
- How much of the item-shop and account flow exists in the game client versus browser/web pages?
- Are community organizations represented as client-side enum labels, server-fed records, or both?
