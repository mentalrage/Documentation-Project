*** UID:0000GS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Economy, Banking, Trading, Kruna, And Market Model

Research date: 2026-05-24

Scope: online public information about NexusTK money flow, NPC shop grammar, bank/deposit commands, player trade behavior, Kruna/item-shop delivery, and market-adjacent UI leads. This is external context only; confirm locally before treating any behavior as target-client fact.

Confidence: medium. Official help pages are strong for documented commands and broad player guidance. Nexus Atlas archives are dated fan reports and are most useful as historical search leads for client strings and feature boundaries.

## Economy Surface Inventory

NexusTK's public economy has several distinct surfaces:

- coins carried by the character;
- banked coins and banked items;
- NPC buying, selling, and repair commands;
- direct item hand/drop/exchange actions;
- player-to-player service markets, including leeching and profile art;
- resource gathering and commodity markets;
- boss drops, keys, and quest-demand items;
- community event prizes;
- web-based Kruna purchases and in-game Messenger parcel delivery.

Reverse-engineering impact: do not model "money" as a single client feature. The client may only expose commands, item actions, inventory state, parcel dialogs, and shop/bank windows while the server owns balances, market validity, bank contents, shop inventory, and item-transfer restrictions.

## Official Bank And Deposit Grammar

The official Verbal Commands page documents bank-style commands based on spoken phrases rather than slash-only UI. It includes deposit actions for items, all of an item, a specific quantity of an item, and coins. It also documents query commands for deposited lists, coin amounts, and item amounts.

High-value command strings:

- `I will deposit`
- `I will deposit all`
- `I will deposit #`
- `I will deposit # coins`
- `What have I deposited?`
- `How many Coins do I have deposited?`
- `How many ITEM do I have deposited?`

Reverse-engineering leads:

- These phrases are likely sent as normal chat/NPC speech or as a specialized NPC interaction packet with command text.
- Bank item and coin storage should be treated as server-side state. The client-facing work is likely prompt display, typed command routing, inventory update, and bank-list display.
- Search local strings for both exact phrases and nearby variants without punctuation or with case differences.

## NPC Shop, Repair, And Travel Commands

Official Verbal Commands also documents NPC shop and service grammar:

- `What do you buy?`
- `What do you sell?`
- `What do you buy NAME?`
- `Buy NAME`
- `Buy # NAME`
- `Buy all NAME`
- `Sell NAME`
- `Sell # NAME`
- `Sell all NAME`
- `Repair`
- `Repair all`
- `Quest`
- `Abandon`
- `Cleanse`
- `Dismiss`

The same page lists travel commands such as `Kugnae`, `Buya`, `Nagnang`, and `Tangun`.

Reverse-engineering leads:

- Shop and repair flows may reuse speech parsing rather than dedicated GUI controls.
- Repair all/single-item behavior should be compared with item flags such as unrepairable, item-shop item, bonded, and special-event restrictions.
- Travel words are useful string seeds for NPC teleport/travel prompts and map transition handling.

## Inventory, Exchange, And Physical Item Actions

Official Basic Keys documents item action keys for inventory and world interactions:

- inventory expand/collapse;
- eat/use/wield/wear/take off;
- immediate equip;
- pick up one item, pick up all items, and pick up surrounding items;
- drop one item or all items;
- hand one item or all items;
- exchange toggle.

Reverse-engineering leads:

- The economy touches ordinary inventory handlers. Item movement verbs should be cross-checked against item restriction messages and Kruna item flags.
- `Exchange` is a likely UI state or mode rather than a one-shot item command.
- The client likely handles local selection, targeting, and action packet construction, while the server validates ownership, trade eligibility, and quantity.

## Official Money-Making Guidance

The official Making Money page describes several player-facing wealth sources:

- ambers are recommended for new players, with Mythic Rabbit and Tangun haunted house given as examples;
- commodities include Ginko wood, Wool, and Ore;
- woodcutting and mining skills improve over time, yielding more and better resources;
- dropped loot values fluctuate with supply and demand;
- Mythic Keys and boss drops remain useful because quests require them;
- boss competition is expected, but a community convention gives the drop to the player who found the boss;
- community events often award cash prizes;
- market flipping is possible but risky unless the player understands item price ranges;
- services can be sold, including leeching and profile art.

Reverse-engineering leads:

- `Leech`, `Mythic Key`, `boss drop`, `Ginko wood`, `Wool`, `Ore`, and amber names are useful strings for market, item, and community help text.
- The official page implies there is no global auction house in the core guidance; player markets may be mostly social/chat/board driven unless a later target client adds other systems.
- Skill improvement affects resource yield, so crafting/gathering state probably lives server-side and only results are displayed client-side.

## Commodity And Resource Market Seeds

Nexus Atlas item/resource pages give concrete commodity names and common sell/use hints:

- mining resources include ore grades, metal, fine metal, slag, gold ore, silver ore, ambers, and gems;
- mining tools include Mining shovel and Mining pick;
- cloth resources include Wool, Cloth, Fine Cloth, Weaving Tools, and Fine Weaving Tools;
- wood resources include Axe, Ginko Wood, Silver Tree Branch, quiver components, and Wood Scraps;
- gem skill outputs include crafted, tarnished, and well-crafted amber variants;
- scribe and alchemy resources include Ink, Moon Paper, White Paper, scrolls, potions, powdered ambers, and potion ingredients;
- rocks/minerals include Amber, Amethyst, Diamond, Topaz, Quartz, Onyx, Onyx Shard, Obsidian, Limestone, ore grades, and special amber variants.

Reverse-engineering leads:

- Commodity names are useful for item-table searches and for validating whether a client build carries item-name resources.
- Failure products such as `Slag`, `Spent Metal`, and `Wood Scraps` are good search seeds for crafting-result messaging.
- Ring-shop and NPC buy/sell data from fan pages should be treated as market hints, not authoritative target values.

## Kruna And Web Item-Shop Flow

The November 2006 Nexus Atlas archive reports the Item Shop opening on the NexusTK website. The described flow is mostly web/account side:

- log in with PatronID and password;
- buy a Kruna coupon through a coupon-shop flow;
- receive the coupon by email;
- recharge Kruna on a Kruna account page;
- choose an item and quantity on item pages;
- choose a character or gift recipient;
- wait, then relog or change servers;
- accept the item in Messenger as a parcel.

The same archive report says KRU item-shop items were non-bonded but could not be transferred, dropped, or exchanged. It says they could be deposited and repaired. A later November 2006 archive item mentions a new `Item Shop Announcements` board. The February 2010 archive reports free Kruna grants for registered accounts and new item-shop cosmetic items.

Reverse-engineering leads:

- Web purchasing, Kruna balance, and coupon redemption probably do not belong to the game executable except as URL/help/news strings, if present.
- The game client should still expose parcel acceptance, Messenger UI, item-shop item flags, repair/deposit eligibility, and failure messages for transfer/drop/exchange.
- Search for `Kruna`, `PatronID`, `Coupon Shop`, `Item Shop`, `Item Shop Announcements`, `parcel`, `Messenger`, `gift`, `recharge`, and `KRU`.

## Player Market And Social Economy

Official guidance and Nexus Atlas terminology describe a social economy:

- `Leech` means paying another player to help gain experience;
- player-run profile art is a service market;
- event prizes and hosted community games inject coins or valuable items;
- bosses and Mythic Keys create contested supply;
- market flipping is player knowledge driven;
- Merchant subpath services and marks include trading, treasure hunting, preferred client, economist, and other commerce-adjacent roles.

Reverse-engineering leads:

- Much of this may be emergent social behavior rather than hardcoded client behavior.
- Client evidence is more likely in chat channels, board posts, exchange UI, legend marks, mail, and item-transfer restrictions than in a centralized market subsystem.
- If an auction-house or offline-market feature appears locally, compare it against the February 2010 Nexus Atlas "Dreams" archive entry because that archive listed it as a desired feature, not necessarily an implemented one.

## Likely Client/Server Ownership

Likely client-owned or client-visible:

- key bindings for inventory, hand/drop/pickup/exchange, mail, boards, and Messenger;
- typed command entry and chat/NPC speech routing;
- shop/bank prompt display;
- item movement UI and failure messages;
- item tooltip/stat display;
- parcel acceptance windows;
- local links or announcements for item-shop/news pages.

Likely server-owned:

- coin balances and bank contents;
- NPC shop inventory and prices;
- repair cost and eligibility;
- item ownership, bonding, and restriction validation;
- resource drop rates and skill yield;
- Kruna balance, coupon redemption, item delivery queue;
- event prize grants and player-service enforcement, if any.

Shared protocol candidates:

- buy/sell/deposit/repair requests;
- inventory stack/quantity updates;
- bank-list and bank-balance responses;
- exchange/trade requests and accept/cancel states;
- parcel accept/reject;
- item restriction result codes or text messages.

## String And Data Search Leads

Search locally for:

- bank grammar: `I will deposit`, `What have I deposited`, `How many Coins`, `deposited`;
- shop grammar: `What do you buy`, `What do you sell`, `Buy all`, `Sell all`, `Repair all`;
- item movement: `Exchange`, `Hand`, `Drop`, `Pick up`, `parcel`, `Messenger`;
- item-shop terms: `Kruna`, `PatronID`, `Coupon`, `Item Shop`, `KRU`, `gift`, `recharge`;
- commodities: `Amber`, `Ginko Wood`, `Wool`, `Ore`, `Mythic Key`, `Slag`, `Spent Metal`, `Wood Scraps`;
- social market terms: `Leech`, `profile art`, `Treasure Hunter`, `Preferred Client`, `Economist`, `Trading`;
- restriction phrases from item pages and archives: `cannot be transferred`, `cannot be dropped`, `cannot be exchanged`, `can be deposited`, `can be repaired`.

## Open-Question Resolution Notes 2026-05-24

- Bank/shop commands are publicly documented as verbal/NPC phrases and the official command page says say commands can be used in macros. This supports a text-command user model, but not a raw-text versus structured-packet conclusion.
- Kruna/item-shop public flow is web/account heavy in the November 2006 archive, with in-game Messenger parcel delivery. Public evidence therefore favors web/server ownership for purchase/recharge and client-visible ownership for parcel acceptance and item restriction display.
- NPC buy/sell prices remain unresolved from public official pages reviewed here. Nexus Atlas item/shop pages can provide fan price/value hints, but those are not proof of local client price tables.
- Exchange is confirmed as a current key/UI toggle by official Basic Keys (`Shift+e`), but public sources do not prove whether it is a dedicated protocol/modal state or a generic action route.
- Item restriction display remains a client/server split question. Public archives name restrictions for item-shop items, but not where rejection text is stored.

## Open Questions

- Are bank/shop commands sent as raw text or as structured command packets?
- Does the target client contain item-shop/Kruna strings, or were those entirely web/server side for the relevant build?
- Are NPC buy/sell prices present locally, or only item display labels and server responses?
- Does exchange use a dedicated modal/protocol state or a general target/action packet?
- Which item restrictions are displayed by client-local strings versus server-sent messages?

## Sources

- [Official help: Making Money in Nexus](https://help.nexustk.com/wiki/wiki/133/making-money-in-nexus)
- [Official help: Verbal Commands](https://help.nexustk.com/wiki/wiki/40/verbal-commands)
- [Official help: Basic Keys](https://help.nexustk.com/wiki/wiki/7/basic-keys)
- [Official help: Nexus Terminology](https://help.nexustk.com/wiki/wiki/70/nexus-terminology)
- [Official help: Subpath Quests & Services](https://help.nexustk.com/wiki/wiki/87/subpath-quests-services)
- [Nexus Atlas: Items for Skills](https://www.nexusatlas.com/nexfiles/skills.php)
- [Nexus Atlas: Rocks and Minerals](https://www.nexusatlas.com/nexfiles/rocks.php)
- [Nexus Atlas: Potions and Scrolls](https://www.nexusatlas.com/nexfiles/potions.php)
- [Nexus Atlas: Health Restoration](https://www.nexusatlas.com/nexfiles/food.php)
- [Nexus Atlas: Crafting legend marks](https://www.nexusatlas.com/legends/crafting.php)
- [Nexus Atlas: Subpath legend marks](https://www.nexusatlas.com/legends/subpaths.php)
- [Nexus Atlas November 2006 archive](https://www.nexusatlas.com/archives/mainpage-archive-11-2006.php)
- [Nexus Atlas February 2010 archive](https://www.nexusatlas.com/archives/mainpage-archive-2-2010.php)
