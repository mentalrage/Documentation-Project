*** UID:0000HA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# User Profile Directory And Webreport Schema

Research date: 2026-05-24

Scope: public `users.nexustk.com` profile, directory, and webreport pages linked from the official NexusTK community page. This is external web research only; it does not prove how the target client stores profile data, whether a local build opens these URLs, or whether every field is visible in every era.

Confidence: high for public URL structure and observed fields on 2026-05-24. Medium for client/server ownership; the public pages are web exports or web-rendered views, not binary evidence.

## Public User-Page Root

`http://users.nexustk.com/` is titled `NexusTK User webpages`. It describes a user web page system for registered NexusTK players who have chosen to show an online page for their character.

The root page exposes:

- a GET search form with input name `name` and action `http://users.nexustk.com`;
- an `advanced search` link at `/search`, which returned HTTP 403 when fetched directly in this pass;
- alphabetic directory links under `/userfiles/a.html` through `/userfiles/z.html`;
- example links using the same query form;
- setup instructions saying a player needs to be registered, above level 10, and should press `F1` in game to follow directions for setting up and personalizing the web page;
- link syntax for external pages: `http://users.nexustk.com/?name=TheName`.

The root page also explains the negative search state. If a name has no current listing, the page says the character may not be registered, may not have asked to display a web page, or the web pages may not have updated yet. It says updates may take up to 24 hours.

## Character Query Pages

Profile lookup uses a simple query URL:

```text
http://users.nexustk.com/?name=<CharacterName>
```

Observed listed character pages use a title like:

```text
<Displayed path/title> <Name> - Nexus TK Character page
```

Observed page sections and fields can include:

- character display name;
- character title;
- nation;
- spouse;
- clan title;
- clan name;
- vital statistics: level, vita, mana, might, grace, will;
- equipment list: weapon, armor, helm, left hand, right hand;
- inventory list, including current gold and item stack counts;
- legend section with icon images and `alt` text containing full legend-mark strings;
- player portrait image, when present;
- item images under `/items/<id>_<variant>.gif`;
- legend images under `/legend/<id>_<variant>.gif`;
- `Last Updated` date.

Not every profile exposes every section. One inspected profile showed only identity, nation, spouse/clan fields, and last-updated date, while other inspected profiles included vital statistics, equipment, inventory, and long legend sections.

Reverse-engineering impact:

- Profile pages prove public web export vocabulary for stats, equipment slots, inventory, current gold, nation, spouse, clan, and legend marks.
- Legend marks on profile pages are image-backed but also expose readable text in image alt attributes. This is a strong lead for client legend icon IDs and text rendering, but not proof that the executable stores the same text.
- Item images use numeric filename patterns, which may help correlate public item art with local resources if the same naming convention exists locally.
- Profile setup through `F1` ties web-page configuration to an in-game help/profile flow, but public pages do not prove whether the game client uploads data directly or only toggles server-side publication settings.

## Alphabetic User Directories

Alphabetic directory pages such as `/userfiles/a.html` list published characters by first letter. The visible rows combine a path/title/rank-like prefix with character name.

Examples of row patterns observed:

- base path plus name;
- subpath/title plus name;
- rank or special title plus name;
- role-like labels such as Merchant, Shaman, Spy, Poet, or rank titles.

These directories are public listing surfaces, not complete population lists. The root page makes clear they contain registered characters who opted to show an online page.

## Official Community Webreport Links

The official community page links many `users.nexustk.com/webreport` pages. These are separate from direct character query pages and act like public reports for roles, paths, clans, armies, and subpaths.

### Power / Path Reports

| URL basename | Public report |
| --- | --- |
| `PowerAll.htm` | Top 1000 of Nexus |
| `PowerWarrior.htm` | Top 250 Warriors |
| `PowerRogue.htm` | Top 250 Rogues |
| `PowerMage.htm` | Top 250 Mages |
| `PowerPoet.htm` | Top 250 Poets |

Observed row schema:

```text
<rank>. <display title> <character name> (<rank/mark/status>)
```

Each entry links back to a character query page using `?name=`.

### Role Reports

| URL basename | Public report |
| --- | --- |
| `Judge.htm` | Current Judges of Nexus |
| `Tutors.htm` | Current Tutors of Nexus |

Observed row schema:

```text
<role title> <character name> (<path/title> - <rank/level>)
```

These reports are strong public evidence that Judge and Tutor are web-visible role categories. They do not prove client-side tooling.

### Clan And Army Reports

The official community page links clan reports such as `Alizarin.html`, `Bear.html`, `Covenant.html`, `Dharma.html`, `Enigma.html`, `Heavens.html`, `Kurimja.html`, `LostKingdom.html`, `Oceana.html`, `Pegasus.html`, `Phoenix.html`, `Silla.html`, `SunMoon.html`, `The_Forsaken.html`, `Tiger.html`, `SanSin.html`, and `Viper.html`. It also links `BuyaArmy.html` and `KoguryoArmy.html`.

Observed row schema on a clan page:

```text
<clan role/title>: <character name> (<path/title> - <rank/level>) "<public note/title>"
```

Some role/title fields include permission hints such as full banking or item banking. This is valuable public vocabulary for clan authority and bank permission strings, but the public page does not prove how permissions are represented in the client.

### Subpath Reports

The official community page links current subpath reports:

- `Barbarian.htm`
- `Do.htm`
- `Chongun.htm`
- `Spy.htm`
- `Ranger.htm`
- `Merchant.htm`
- `Diviner.htm`
- `Geomancer.htm`
- `Shaman.htm`
- `Druid.htm`
- `Monk.htm`
- `Muse.htm`

Observed row schema on a subpath page:

```text
<subpath role/title>: <character name> (<path/title> - <rank/level>)
```

High-value role strings include `Elder` and `Guide`. These reports provide public confirmation that role membership and role title are web-visible, but they do not prove whether the target client stores these lists locally.

## Update Signals

Observed profile pages have a plain `Last Updated :` date, such as a month-day-year value.

Observed webreport pages use a JavaScript last-updated timestamp:

```text
new Date(<epoch> * 1000)
```

For example, on 2026-05-24 this pass observed `PowerAll.htm` and a clan report with update epochs resolving to early May 24, 2026 Pacific time. Treat these as web-export timestamps, not in-game event times.

## Client/Server/Web Ownership Leads

Likely web/server-owned:

- public publication opt-in;
- generated profile pages;
- generated path/clan/role/subpath reports;
- profile search and alphabet directory;
- current webreport update timestamps;
- public filtering by path, clan, role, army, and subpath.

Likely client-visible or client-related:

- `F1` help/profile setup flow;
- profile/portrait customization gate for registered accounts;
- status fields that overlap with profile fields;
- legend/status page rendering that overlaps with web profile legend text;
- equipment/inventory/item names and icon IDs;
- spouse/nation/clan/subpath/title fields.

Unknown:

- whether the game client uploads portrait/profile text directly;
- whether profile publication is toggled in client UI, web account UI, or both;
- whether item/legend icon numeric IDs match local DAT/resource IDs;
- whether inventory and current gold are exported live, periodically, or from a cached server snapshot;
- whether the target-era client has the same profile/export fields.

## Reverse-Engineering Leads

Search locally for:

- hosts and paths: `users.nexustk.com`, `/userfiles/`, `/webreport/`, `?name=`, `PowerAll`, `PowerWarrior`, `PowerRogue`, `PowerMage`, `PowerPoet`;
- profile fields: `Character name`, `Character title`, `Character Nation`, `Spouse`, `Clan title`, `Clan name`, `Vital statistics`, `Equipment list`, `Inventory list`, `Current gold`, `Legend`, `Last Updated`;
- stat labels: `Level`, `Vita`, `Mana`, `Might`, `Grace`, `Will`;
- item/legend image paths: `/items/`, `/legend/`, `.gif`, `.png`;
- setup vocabulary: `user web page`, `web listing`, `registered member`, `above level 10`, `F1`, `profile`, `portrait`;
- report labels: `Top 1000 of Nexus`, `Top 250 Warriors`, `Current Judges`, `Current Tutors`, `Elder`, `Guide`, `Primogen`, `Council`, `Full banking`, `Item banking`.

## Open Questions

- Does the target client contain profile setup UI or only link/help text for the web page system?
- Are public profile pages generated from the same data structures as in-game status/legend pages?
- Do `/items/<id>_<variant>.gif` and `/legend/<id>_<variant>.gif` map directly to local DAT/resource IDs?
- Are inventory and current gold exports controlled by player privacy options, registration state, or fixed server export rules?
- Did the 1998-2005 client-era user pages expose the same fields and query scheme, or did this web system change after the KRU transition?

## Sources

- [Official NexusTK community page](https://www.nexustk.com/community.html)
- [NexusTK user page root](http://users.nexustk.com/)
- [NexusTK user directory A](http://users.nexustk.com/userfiles/a.html)
- [NexusTK profile query example](http://users.nexustk.com/?name=Aemon)
- [NexusTK Top 1000 webreport](http://users.nexustk.com/webreport/PowerAll.htm)
- [NexusTK Warriors webreport](http://users.nexustk.com/webreport/PowerWarrior.htm)
- [NexusTK Judges webreport](http://users.nexustk.com/webreport/Judge.htm)
- [NexusTK Tutors webreport](http://users.nexustk.com/webreport/Tutors.htm)
- [NexusTK Alizarin clan webreport](http://users.nexustk.com/webreport/Alizarin.html)
- [NexusTK Barbarian subpath webreport](http://users.nexustk.com/webreport/Barbarian.htm)
- [Official NexusTK download page](https://www.nexustk.com/download_2.html)
- [Official NexusTK FaceMaker page](https://www.nexustk.com/download_3.html)
