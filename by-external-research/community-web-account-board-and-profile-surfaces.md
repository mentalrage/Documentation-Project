*** UID:0000GQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Community Web, Account, Board, And Profile Surfaces

Research date: 2026-05-24

Scope: public web and in-game-adjacent community infrastructure around NexusTK: account registration, user/profile pages, boards, mail/messenger delivery, fan/community link directories, item-shop flow, and current board mirrors.

Confidence: medium. Official KRU pages are strong for current public account/download/community links and client key bindings. Nexus Atlas archives are historical fan reports, useful as dated evidence and search leads but not binary proof.

## Surface Inventory

NexusTK's public ecosystem is not just the game executable. Public sources point to several related surfaces:

- `www.nexustk.com`: official entry, downloads, guide, community links, screenshots, item-shop/news entry points.
- `secure.kru.com`: official account manager/payment surface referenced by the download page and by 2005 migration news.
- `support.kru.com`: official support surface referenced by current download support and the 2005 KRU migration.
- `users.nexustk.com`: user/profile/community list host linked by the official community page.
- `inns.nexustk.com`: "in-room pages" link from the official community page; current public host for plot lookup, pointer maps, and room design catalogs.
- `boards.nexustk.com`: public board mirror. The Carnage schedule board is currently available over HTTP as static HTML.
- in-game boards and mail: official help and board mirrors imply direct in-client board/mail UI with web mirrors for at least some boards.
- Messenger/parcel delivery: Nexus Atlas archive reports Kruna item delivery through Messenger parcels.

Reverse-engineering impact: do not assume all visible "game" functions are pure client/server gameplay. Some flows are browser, web account manager, in-game board records, or server-delivered parcels displayed by the client.

## Account And Registration Gates

The official download page says new players create a character from the opening screen after installing the client, can play to level 49, and need a paying account to continue using that trial character. It says character name and password remain the same after registration.

The same official page lists registration gates:

- custom portrait/profile;
- clan participation;
- longer quests;
- access to all bulletin boards;
- subpaths;
- more spells, items, and maps;
- intelligent monsters;
- Elixir War.

These gates overlap with many client UI and server-permission surfaces: portrait/profile editor, board access checks, clan/subpath chat and windows, map entry failures, spell availability, item use, and event entry.

## KRU Domain Migration And Account Manager

The May 2, 2005 Nexus Atlas archive reports the KRU transition from older Nexon/KRU game domains to `kru.com`. The archive says KRU consolidated Support and Account Manager under the company website and exposed direct links for support and secure account management. It also notes an inactive account/character purge and urges re-registration before the purge.

Use this as a dated lead for string searches around:

- `Nexon.net`
- `krugames.com`
- `kru.com`
- `support.kru.com`
- `secure.kru.com`
- `Account Manager`
- `Support`
- `PURGE`
- registration/renewal and account reactivation wording.

If the target client is from the 2004-2006 window, account/support URLs may differ from modern official pages.

## Community Directory Model

The official community page is a directory of both official and fan/community surfaces. It exposes:

- "In-room pages";
- boards;
- user list;
- user profile;
- clans: Alizarin, Bear, Covenant, Destiny, Dharma, Enigma, Heavens, K'urimja, Lost Kingdom, Oceana, Pegasus, Phoenix, Silla, Sun Moon, The Forsaken, Tiger, SanSin;
- armies: Buya Army and Koguryo Army;
- Judges and Tutors;
- all players and base path lists for Warriors, Rogues, Mages, Poets;
- subpath group links: Barbarian, Do, Chongun, Spy, Ranger, Merchant, Diviner, Geomancer, Shaman, Druid, Monk, Muse;
- fan/reference links including NexusWiki, Nexus Biographies, Stat Addict, Chung Ryong's Dojang, Nexus Atlas, and Nexus Forums.

This directory is useful because it gives canonical public names for social categories likely to appear in board categories, profile pages, legend filters, clan halls, path ranks, chat routes, and role privilege checks.

## User Pages And Profile Pages

The September 19, 2003 Nexus Atlas archive reports that "user pages" returned and points players to a NexusTK list URL while the community links page was not yet updated. This is dated evidence that profile/list pages were an important web surface during the old client era, not just a modern leftover.

The current official community page still links a user list and user profile host under `users.nexustk.com`. Follow-up research found that the host is a public user web page system with a root search form, alphabetic directories, query URLs using `?name=CharacterName`, and `webreport` pages for public path rankings, clans, armies, judges, tutors, and subpaths.

The root page says it lists registered NexusTK players who chose to show an online page. It also says a player needs to be registered, above level 10, and should press `F1` in game for setup directions. This ties public user pages to an in-game help/profile setup flow, but does not prove the client uploads profile data directly.

Reverse-engineering leads:

- profile/portrait customization strings;
- legend page or character status export strings;
- list filters by path, clan, subpath, judge/tutor role;
- web URL launch behavior in client menu/buttons;
- "listed on the Nexus webpage" checks mentioned in archive tutor applications.
- See [UID:0000HA][user-profile-directory-and-webreport-schema](by-external-research/user-profile-directory-and-webreport-schema.md) for current public URL patterns and observed profile/report fields.

## In-Room Pages And House Website

The official community page links `In-room pages` to `http://inns.nexustk.com`. Follow-up research confirmed this host currently exposes the public house/inn catalog:

- root landing page titled `Nexus Inn Room Plot List`;
- nine town plot lists under `/plots/<Town>.html`;
- 2,999 current public plot rows with plot number, size, location, and coordinate pointer links;
- graphical world/kingdom image maps under `/plots/World.html`, `/plots/Buya.html`, `/plots/Kugnae.html`, and `/plots/Nagnang.html`;
- pointer endpoint `/plots/Pointer.pl?map=<Town>&x=<X>&y=<Y>&size=<Size>&plot=<PlotId>`;
- room design catalog pages under `/rooms/`;
- 37 current room design codes with names, designers, thumbnails, and full-size image pages.

This is a web-adjacent gameplay surface: it helps players identify plot numbers and design codes for in-game inn/merchant/assistant flows, but the public pages do not show account login, owner/rent/guest state, private storage, current occupants, or packet/API details. See [UID:0000GZ][in-room-pages-and-inns-web-schema](by-external-research/in-room-pages-and-inns-web-schema.md) for the full schema.

Nexus Atlas archives anchor this surface in the older-client era. The July 2003 archive reposts a Dream Weaver `New House Designs` note that names Releen, Dok-Sin, Filnoos, and Altree and points to `http://inns.nexustk.com` as the house website. The July 2004 archive uses the `Pointer.pl` endpoint as a public event direction URL for a North Masan map with an arrow.

## Boards And Board Mirrors

Official help says the `b` key opens bulletin boards, and the official Carnages help page says the Carnage schedule can be viewed either on a carnage board at `(126, 081)` in Buya or online at `http://boards.nexustk.com/Carnage/index.html`.

The live Carnage board mirror is plain HTML:

- it uses a `META Refresh` interval of 600 seconds;
- it has table rows with post number, date, author, and subject;
- linked post filenames include author/date/number fields such as `Drywater 05100054.html`;
- posts have headers like `Board`, `Author`, `Subject`, and `Date`;
- the schedule board was last updated on May 10, 2026 according to its generated timestamp.

Current visible post subjects include:

- Carnage Schedule;
- List of Champions;
- Fox Hunt of Champions;
- Elixir of Champions;
- Carnage of Champions;
- Bans 2025;
- Carnage Law;
- Carnage Application;
- Team Dye Indicator;
- Carnage Guide;
- Balancers for Riches;
- Prohibited Items;
- Win Timer Improvement;
- Carnage Rules.

Implication: board content is both gameplay-critical and web-exposed. Some in-game boards may be server-generated HTML mirrors with minimal client logic beyond board list, post list, and post display.

Follow-up board-root research found that `http://boards.nexustk.com/index.html` currently lists 24 public board mirrors, not just Carnage. The root says the pages expose some boards available in the game and are updated every 15 minutes. Categories include Community, buy/sell market boards, Hunting, Community Events, Dream Weaver, Dreams, Whispering Winds, Law, Guide, Welcome, story/poetry/tales boards, Kingdom Tribune, Chronicles of the Winds, Drifting Winds, Inquiring Minds, Fox Hunt, Carnage, and the four base path boards. See [UID:0000GL][board-mirror-catalog-and-schema](by-external-research/board-mirror-catalog-and-schema.md) for the full catalog and schema.

## In-Game Communication Keys

Official Basic Keys documents these communication-adjacent controls:

- `b`: bulletin boards;
- `Shift+m`: mail;
- `p`: post;
- `F3`: friends list;
- `F5`: hear whisper toggle;
- `F6`: hear shouts toggle;
- `F9`: ignore list;
- talk, whisper, clan whisper, subpath whisper, shout, emotion, group, group view, and target-to-talk keys.

Official Verbal Commands document chat routes:

- `/s` and `!` for shout;
- `/c`, `/clan`, and `/g` for clan;
- `/t !!` for group;
- `/sp` for subpath;
- `/t`, `/tell`, `/whisper`, and `/w` for direct whisper;
- `/report` to online archons;
- `/novice`, `/n`, and `/tutor` for novice chat;
- `/r` and `/r#-#` for dice.

Because Carnage rules say hosts give instructions through "sage" and tell players to enable it with `F6`, treat "sage" as a broadcast/listening mode that may share implementation with shout/hear-shout controls or use the same toggle.

## Mail, NMail, Messenger, And Parcels

Archives and official help distinguish several message/delivery concepts:

- `Shift+m` opens mail.
- Player reports and applications use `NMail` as a social term for mail.
- The November 2006 Kruna report says purchased items are accepted through Messenger as parcels.
- Several archive posts say players should send applications by mail to named characters or role accounts.

Client leads:

- mailbox list and read/reply/delete windows;
- post/board composition UI;
- messenger/parcel acceptance dialog;
- server message for "new mail" or mail indicator;
- character-name validation for mail recipients;
- item parcel restrictions and delivery delay messaging.

## Kruna And Item Shop Integration

The November 6, 2006 Nexus Atlas archive reports the Item Shop opening on the NexusTK webpage. The described flow is web-heavy:

- log in with PatronID and password;
- buy a Kruna coupon through a coupon-shop flow;
- recharge Kruna on a Kruna account page using a coupon mailed by email;
- select items from item pages;
- choose a character or gift recipient;
- wait, then relog or change servers;
- accept the parcel in Messenger.

The same report says KRU item-shop items are non-bonded but cannot be transferred, dropped, or exchanged, while they can be deposited and repaired. A later November 2006 archive post mentions an `Item Shop Announcements` board on the bulletin system. The February 2010 archive reports free Kruna for registered accounts and item-shop additions.

This is a strong lead for a split integration:

- purchasing is web/account side;
- balance, ownership, delivery, and item restrictions are server-side;
- client displays parcel acceptance, item flags, repair/deposit behavior, and possibly item-shop/dress-up windows.

## Live-Service Wishlist And UI Roadmap Leads

The February 2010 Nexus Atlas archive preserves a "Dreams" list that mentions:

- item-shop layout improvements;
- grouping same items with different colors in one slot;
- increasing visible Kruna item options;
- vita/mana bars for group members;
- an offline auction house idea;
- stretchable Group, Items, and Spells tabs;
- friends-list login notifications;
- pet speed;
- canceling Sam san repair to avoid aethers;
- ring destinations for Ancient Training Grounds and Woodlands caves.

These are not proof of implemented behavior at that date unless separately documented, but they are useful feature leads. Some later clients may contain these UI features or partial strings even if the target binary predates them.

## Reverse-Engineering Leads

Search locally for:

- domains and URLs: `nexustk.com`, `users.nexustk.com`, `inns.nexustk.com`, `boards.nexustk.com`, `secure.kru.com`, `support.kru.com`, `kru.com`, `Nexon.net`;
- account words: `PatronID`, `Account Manager`, `register`, `renewal`, `coupon`, `Kruna`, `Item Shop`, `parcel`, `Messenger`;
- board words: `Board`, `Author`, `Subject`, `Date`, `Post`, `Carnage Schedule`, `Dream Weaver`, `Chronicles of the Winds`, `Law board`;
- profile words: `User profile`, `User list`, `portrait`, `profile`, `legend listed`;
- communication words: `NMail`, `mail`, `whisper`, `sage`, `shout`, `novice`, `tutor`, `report`, `ignore`.

Separate likely ownership:

- client: key bindings, board/mail windows, post editor, friends list, ignore list, chat routing, parcel acceptance display, profile/portrait upload UI if any;
- server/web: board contents, account/payment state, Kruna purchase, profile list generation, delivery queue, role authorization;
- shared protocol: board list/post operations, mail operations, parcel accept/reject, item restriction flags, chat-channel identifiers.

## Open-Question Resolution Notes 2026-05-24

- Registration gates are publicly answered by the official download page: registered accounts unlock portrait/profile customization, clans, longer quests, all bulletin boards, subpaths, more spells/items/maps, intelligent monsters, and Elixir War. Whether each gate is locally visible or server-only remains binary/protocol work.
- Portrait/profile workflow is narrowed by the official FaceMaker page and public user-page root. FaceMaker is a separate utility for registered characters and the user-page root says profile setup uses in-game `F1` help for registered characters above level 10. Exact local file format/path and upload/publication mechanism remain local or server-web questions.
- Board mirrors are now substantially answered for public web mirrors: `boards.nexustk.com/index.html` lists 24 public board categories. This still does not prove that every in-game board is mirrored or that private/role/clan/subpath boards are exposed.
- Board/mail entry points are public: Basic Keys documents `b` for boards, `p` for post, and `Shift+m` for mail. That does not prove whether Messenger parcel acceptance reuses mail UI or has a separate packet/window.
- URL-launching remains local: public pages prove web hosts exist, but not that the game client opens those URLs directly.
- In-room pages are now publicly mapped at the schema level: `inns.nexustk.com` exposes plot lists, pointer maps, and room design codes. The remaining questions are whether the client launches those URLs, whether plot/design IDs appear in local resources or packets, and whether the public catalog is generated from the same records as live in-game house state.

## Sources

- [Official NexusTK community page](https://www.nexustk.com/community.html)
- [Official NexusTK download/account gate page](https://www.nexustk.com/download_2.html)
- [Official NexusTK main page](https://www.nexustk.com/main.html)
- [Official NexusTK Basic Keys](https://help.nexustk.com/wiki/wiki/7/basic-keys)
- [Official NexusTK Verbal Commands](https://help.nexustk.com/wiki/wiki/40/verbal-commands)
- [Official NexusTK Carnages help](https://help.nexustk.com/wiki/wiki/38/carnages)
- [Live Carnage board index](http://boards.nexustk.com/Carnage/index.html)
- [Public NexusTK board root](http://boards.nexustk.com/index.html)
- [NexusTK user page root](http://users.nexustk.com/)
- [NexusTK Top 1000 webreport](http://users.nexustk.com/webreport/PowerAll.htm)
- [NexusTK profile query example](http://users.nexustk.com/?name=Aemon)
- [NexusTK in-room page root](http://inns.nexustk.com/)
- [NexusTK Masan plot list](http://inns.nexustk.com/plots/Masan.html)
- [NexusTK small room designs](http://inns.nexustk.com/rooms/SmallB.html)
- [NexusTK medium room designs](http://inns.nexustk.com/rooms/MediumB.html)
- [NexusTK large room designs](http://inns.nexustk.com/rooms/LargeB.html)
- [NexusTK Masan pointer example](http://inns.nexustk.com/plots/Pointer.pl?map=Masan&x=59&y=132&size=Large&plot=050733)
- [Nexus Atlas July 2003 archive](https://www.nexusatlas.com/archives/mainpage-archive-7-2003.php)
- [Nexus Atlas July 2004 archive](https://www.nexusatlas.com/archives/mainpage-archive-7-2004.php)
- [Nexus Atlas September 2003 archive](https://www.nexusatlas.com/archives/mainpage-archive-9-2003.php)
- [Nexus Atlas May 2005 archive](https://www.nexusatlas.com/archives/mainpage-archive-5-2005.php)
- [Nexus Atlas November 2006 archive](https://www.nexusatlas.com/archives/mainpage-archive-11-2006.php)
- [Nexus Atlas February 2010 archive](https://www.nexusatlas.com/archives/mainpage-archive-2-2010.php)

## Open Questions

- Which board categories have live web mirrors besides Carnage?
- Do profile/portrait pages use static server exports or live account/profile APIs?
- Does the client contain URL-launching code for community/profile/account pages, or are these purely website navigation?
- Is Messenger parcel acceptance the same UI path as player mail, or a separate packet/window?
- Which registration gates are locally visible in the client versus enforced only by server rejection messages?
