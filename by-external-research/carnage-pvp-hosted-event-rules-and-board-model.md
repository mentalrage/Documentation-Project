*** UID:0000GM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Carnage, PVP, Hosted Event Rules, And Board Model

Research date: 2026-05-24

Scope: public information about NexusTK PK/PVP areas, Carnage event types, host privileges, team/color mechanics, board schedules, event gates, rewards, prohibited actions, and client/UI leads.

Confidence: medium. Official help is authoritative for broad current concepts, event categories, level bands, and board location. Nexus Atlas and live Carnage board posts add operational detail, but some rules changed over time and may not match the target client era.

## PK/PVP Baseline

Official help defines PK/PVP as player-killing/player-versus-player combat in special areas. It names events, carnages, and casual interactions such as sire pit as contexts where this combat happens.

This implies a map/zone flag model rather than global PVP. The client may need to display or react to:

- special arena maps;
- PVP-enabled attack targeting;
- team/friendly-fire restrictions;
- ghost/death state in arenas;
- event entry doors/NPCs;
- host instructions through broadcast channels.

Do not assume the client enforces PVP legality. Many rules look social/server-authoritative, but local UI can still expose team indicators, spell filters, event prompts, and entry denial messages.

## Official Carnage Help

Official help describes Carnages as paid-entry PK events with entry restrictions by event type. It names Bloodlusts, Riches, Crusades, Elixir wars, and Fox hunts.

The same official page says Carnages are hosted by players with special privileges, called Carnage Hosts. Events are scheduled two weeks in advance by the Head Carnage Host. The schedule is available on a carnage board at `(126, 081)` in Buya and online at `http://boards.nexustk.com/Carnage/index.html`.

Client/server leads:

- paid entry prompt and coin deduction;
- event category and level/stat/rank gates;
- host capability flags;
- schedule board category;
- time display and date parsing for board posts;
- online board mirror generation.

## Event Types And Teams

Nexus Atlas describes Carnage as an arena fighting game organized by Carnage Staff. It says teams use the colors ash, fire, river, and snow, corresponding to black, red, blue, and white variants. It names Bloodlust, Carnage of Riches, Crusades, Elixir Wars, Fox Hunt, and Ultimate Gauntlet.

Current board posts and Nexus Atlas pages show several event patterns:

- Riches: team deathmatch with prizes and experience.
- Bloodlust: team deathmatch, usually no item prize, victory legend mark.
- Crusades: team PVP with enforced balancing and no subaccessories.
- Elixir War: two-team capture-the-flag-like potion/trophy game.
- Fox Hunt: mount/fox capture game with tokens and themed variants.
- FAV/rotating hosted sets: current schedule uses shorthand such as `EW`, `RC`, `BL`, and `FH`.

Search strings should include both formal and abbreviated names.

## Level, Stat, Rank, And Registration Gates

Official Carnage Levels lists event bands and entry fees:

- Riches: Glory, Legends, Ancients, Avatars, Celestials, Paramount, Mayhem.
- Bloodlust: Massacre, Chaos, Slaughter, Insanity, Crusades.
- Elixir Wars: Elixir War.
- Fox Hunts: Fox Hunt.
- Tangun Academy Carnages: Academy Adventure, Academy Heroes, Academy Conquest, Academy Elixir.

Official notes say Riches has win/prize limits, Bloodlusts and Elixirs allow unlimited wins, Academy Carnages do not require registration, and Crusades requires no sub-accessories, three inventory slots, and stat reduction.

The live Carnage Guide board post from August 16 says modern Riches now accepts broader level ranges but applies balancers:

- Ancients: level 6 to 99 unmarked, balanced to 50k/25k.
- Avatars: level 6 to Il mark or lower, balanced to 160k/80k.
- Celestial: level 6 to Sam mark or lower, balanced to 640k/320k.
- Paramount: level 6 with all marks/stats, balanced to 1.28m/640k.
- Mayhem: level 6 with all marks/stats, uncapped.
- Crusade: 51+, balanced to 640k/320k.
- Elixir War: 51+ and registered.
- Fox Hunt: 11+.

This is an example of rule drift. Preserve both official help and current board evidence with dates.

## Live Board Mirror

The live Carnage board index is static HTML with rows for post number, date, author, and subject. The current schedule post is `Drywater 05100054.html`, dated `5/10`, and the board timestamp resolves to May 10, 2026 local time.

Visible current board topics include:

- Carnage Schedule;
- Carnage Guide;
- Carnage Rules I and II;
- Carnage Law;
- Carnage Application;
- Team Dye Indicator;
- Balancers for Riches;
- Prohibited Items;
- Win Timer Improvement;
- Bans 2025;
- champion lists and special tournaments.

The current schedule post contains timed entries for Foxhunt, Elixir, Riches, Bloodlust/Crusade, and FAV events. It also marks Carnage Holidays.

Reverse-engineering value: this shows current board post field schema, date format, and content vocabulary that may match in-game board UI strings.

## Host Authority And Event Law

Nexus Atlas Carnage Rules and live board rules both emphasize host authority:

- participants must obey host instructions;
- hosts can remove, kill, or ban participants in rule cases;
- players must keep the relevant broadcast channel enabled for instructions;
- attacking hosts or casting spells on them is prohibited;
- all Nexus laws still apply inside arenas;
- bug abuse, disruption, false-start shouts, and multiple-character entry are prohibited.

The live `Carnage Law` board post says submitting multiple characters by the same player/account into one carnage is forbidden and punishable as serious-crime jailing for all involved characters.

This points to at least three authority layers:

- event host controls: start/stop, doors, teams, dye, prizes, removals;
- normal law/judge/archon system: jailing, bans, serious crime marks;
- automated server checks: inventory slots, subaccessory removal, registration, win timers, event entry status.

## Team Dye And Visual Identification

Older Nexus Atlas pages describe team colors as ash, fire, river, and snow. Live board post `New: Team Dye Indicator` says players can see a colored box below a character name during Carnage to indicate assigned team, toggleable in the Options tab. It also says wearing clothing that properly displays dye remains required.

This is a high-value UI lead:

- team indicator rendering near nameplates;
- event-only overlay;
- Options tab toggle;
- clothing/dye visual state;
- team-color packet or local state field.

Look for strings around `Team Dye Indicator`, `dye`, `ash`, `fire`, `river`, `snow`, `red`, `blue`, and options-page toggles.

## Balancers, Subaccessories, And Inventory Slots

Official Carnage Levels and live board posts agree that some events require players to remove sub-accessories and have inventory capacity. The live `Balancers for Riches` post says Riches events issue balancers on entry and requires both subaccessories removed plus at least three empty inventory slots. It lists capped vita/mana levels per league.

Nexus Atlas Bloodlust and Crusades pages also describe balancers as subaccessories that increase or decrease stats to even the playing field, and say remaining balancers can be removed by town arena dye NPCs.

Reverse-engineering leads:

- equipment slot checks for subaccessories;
- empty inventory slot counting;
- temporary item/equipment issuance;
- stat cap display or server-applied adjustment;
- cleanup path through dye NPC;
- entry denial messages for insufficient slots/equipped subaccessories.

## Prohibited Spells And Items

Nexus Atlas rules and live board rules list prohibited or conditional effects:

- summoned pets/creatures;
- resurrection;
- mana-stealing effects such as Inspiration;
- morph/color-changing effects;
- pop-up-causing effects such as Mentor, Propose, Gamble, or karma reading;
- cloning invisible or enemy-team players;
- some ranger traps in lower events;
- Push in circle matches;
- sleep arrows and Onyon;
- dye arrows or similar effects;
- rank/stat-tier items in lower Riches leagues;
- black potions and stat-bonus mantle/footwear items in later live rules.

This list is useful for effect-category searches rather than exact names only. Event legality may be enforced server-side, but the client may display denial reasons or unavailable action feedback.

## Round Control And Arena Geometry

Rules describe event-start and arena-control concepts:

- players wait behind lines marked by yellow scrolls;
- attacking before the host starts the round is illegal;
- setting traps before the start is illegal, while traps can be legal during the round;
- moving/tampering with yellow scrolls is prohibited;
- hosts can call circle matches;
- circle matches use an enclosed roughly 8x8 area;
- stepping out disqualifies a player;
- rogues using ambush or players using jump/leap must be able to return immediately;
- circle matches have a 10-minute maximum in live board rules;
- tied rounds may award both teams points or trigger redo rounds.

The client may only render maps and items, but the vocabulary suggests event scripts for markers, doors, timed rounds, round state, and host chat.

## Riches And Bloodlust

Nexus Atlas describes both Riches and Bloodlust as team PVP where the objective is to kill everyone on the opposing team. Hosts pick teams with help from auto-dye. Matches normally use best-of-three rounds.

Key differences:

- Riches gives prizes and experience, and historically had one prize/win mark limit per 24 hours.
- Bloodlust generally gives only a victory legend mark and no item prize.
- Riches pages map leagues to doors, entry fees, prize tables, and experience amounts.
- Bloodlust pages name Buya Arena and include Crusade balancing notes.

Client leads:

- door selection by league;
- prize-selection UI;
- victory mark and experience result messages;
- win timer messages;
- auto-dye/team assignment state.

## Elixir War

Nexus Atlas describes Elixir War as a two-team capture game with red in the northwest and blue in the southeast. Each team retrieves a potion from the opposing base, brings it to a center NPC/trophy interaction, and hands an acorn to receive the trophy. The system then announces the trophy holder. Matches are best-of-three or best-of-five.

The page also says:

- arrows can hit opposing players and change their color;
- a hit player is dead if they move;
- being hit by one's own team can restore team color;
- arrows are limited;
- players need at least one acorn and can buy acorns from the NPC;
- the arena is Nagnang Arena with map coordinates.

Client/server leads:

- team base/potion object state;
- trophy possession broadcast;
- color-change/death-on-move rule;
- arrow count and projectile hit effects;
- NPC acorn purchase and hand-in;
- best-of-N score state.

## Fox Hunt

Nexus Atlas describes Fox Hunt as a team game in the Royal Stables/Fox Hunt Stables. Players ride horses, captains summon foxes, and teams try to capture the opposing team's fox or captain. Capture can be caused by surrounding/blocking the fox or separating it from the captain, and the system announces capture. Matches can be best-of-three, best-of-five, or best-of-seven. Prizes can include Riches-type prizes or tokens used for mounts.

The page also lists theme variants such as Hectic Horses, Luminous Leaders, Recurring Eclipse, Equestrian Equality, Magnificent Mounts, The Great Horse Strike, and Conquering Quantity.

Client leads:

- mounted-player requirements;
- mount disqualification or entry messages;
- summoned follower AI and capture detection;
- darkness/light level changes;
- system capture announcements;
- token/prize exchange.

## Archive Patch Leads

The January 2006 Nexus Atlas archive says a `Nexus 6.59` patch allowed carnage hosts to periodically view how many participants from each team remained alive. The May 2005 archive says players could bring their own bows into Elixir War after a reset. The November 2006 archive reports a Head Carnage Host selection on the community board.

These dated reports point to host-only UI and event-rule changes:

- alive-count host command/window;
- Elixir War bow allowance;
- community board announcements for staffing;
- staff privilege transitions.

## Reverse-Engineering Leads

Search locally for:

- event names: `Carnage`, `Riches`, `Bloodlust`, `Crusade`, `Elixir`, `Fox Hunt`, `Ultimate Gauntlet`, `FAV`;
- teams/colors: `ash`, `fire`, `river`, `snow`, `red`, `blue`, `dye`, `Team Dye Indicator`;
- roles: `Carnage Host`, `Head Host`, `Carnage Staff`, `Archon`, `Host`;
- rules: `balancer`, `subaccessory`, `yellow scroll`, `circle`, `last man standing`, `win timer`, `prohibited`, `banishment`;
- objects: `trophy`, `potion`, `acorn`, `fox`, `horse`, `mount`, `token`, `Dye potions`;
- boards: `Carnage Schedule`, `Carnage Guide`, `Carnage Rules`, `Carnage Law`.

Separate candidate responsibilities:

- client: visual team indicator, options toggle, nameplate overlay, board reading, map/door interaction UI, chat display, item/spell list and possible local filtering;
- server: event scheduling, entry gates, balance stat application, team assignment, round start/stop, prizes, win timers, rule enforcement, jailing/bans;
- host tools: participant counts, team picking, auto-dye, door control, announcements, removals.

## Sources

- [Official NexusTK PK/PVP Guide](https://help.nexustk.com/wiki/wiki/12/pkpvp-guide)
- [Official NexusTK Carnages help](https://help.nexustk.com/wiki/wiki/38/carnages)
- [Official NexusTK Carnage Levels](https://help.nexustk.com/wiki/wiki/39/carnage-levels)
- [Live Carnage board index](http://boards.nexustk.com/Carnage/index.html)
- [Live Carnage schedule post](http://boards.nexustk.com/Carnage/Drywater%2005100054.html)
- [Live Carnage Guide post](http://boards.nexustk.com/Carnage/Drywater%2008160019.html)
- [Live Team Dye Indicator post](http://boards.nexustk.com/Carnage/Drywater%2010050020.html)
- [Live Riches Balancers post](http://boards.nexustk.com/Carnage/Drywater%2008160018.html)
- [Live Carnage Law post](http://boards.nexustk.com/Carnage/Horus%2011090024.html)
- [Live Carnage Rules I post](http://boards.nexustk.com/Carnage/Drywater%2012100016.html)
- [Live Carnage Rules II post](http://boards.nexustk.com/Carnage/Drywater%2012100015.html)
- [Nexus Atlas Carnage section](https://www.nexusatlas.com/carnage/index.php)
- [Nexus Atlas Carnage Rules](https://www.nexusatlas.com/carnage/rules.php)
- [Nexus Atlas Carnage of Riches](https://www.nexusatlas.com/carnage/riches.php)
- [Nexus Atlas Bloodlust](https://www.nexusatlas.com/carnage/bloodlust.php)
- [Nexus Atlas Elixir Wars](https://www.nexusatlas.com/carnage/elixir.php)
- [Nexus Atlas Crusades](https://www.nexusatlas.com/carnage/crusades.php)
- [Nexus Atlas Fox Hunt](https://www.nexusatlas.com/carnage/foxhunt.php)
- [Nexus Atlas January 2006 archive](https://www.nexusatlas.com/archives/mainpage-archive-1-2006.php)
- [Nexus Atlas May 2005 archive](https://www.nexusatlas.com/archives/mainpage-archive-5-2005.php)
- [Nexus Atlas November 2006 archive](https://www.nexusatlas.com/archives/mainpage-archive-11-2006.php)

## Open Questions

- Open-question pass 2026-05-24: official PK/PVP help answers the public combat boundary: PK/PVP is held in special areas for events, carnages, or casual interactions such as sire pit. Exact map flags and enforcement remain local/server questions.
- Open-question pass 2026-05-24: the live Carnage board confirms public posts for Team Dye Indicator, balancers, prohibited items, carnage laws, applications, schedules, and rules. That confirms board/public rule vocabulary, not target-client implementation.
- Open-question pass 2026-05-24: board mirror schema is confirmed for Carnage as static HTML with post number/date/author/subject. Whether mirrors share the same source data as in-game boards remains unresolved.

- Which Carnage rules are encoded in server scripts versus only posted/socially enforced?
- Does the target client include the modern team dye indicator, or is that a later patch feature?
- Are board mirrors generated from the same data as in-game boards, and do all boards share the same post schema?
- What packet/state fields represent team, dye, host privilege, round state, and event registration?
- Are balancers real temporary items, hidden stat modifiers, or both?
