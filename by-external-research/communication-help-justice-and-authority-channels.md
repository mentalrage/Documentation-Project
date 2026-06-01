*** UID:0000GP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Communication, Help, Justice, And Authority Channels

Research date: 2026-05-24

Scope: online public information about NexusTK chat routes, help channels, justice/report escalation, authority roles, mail/boards, and role-specific communication surfaces. This is external research only; use it as search vocabulary and behavior context until confirmed locally.

Confidence: medium. Official help pages are strong for documented key bindings and command aliases. Nexus Atlas archives are dated fan reports and are most useful for channel evolution and live-service routing changes.

## Communication Surface Inventory

Public sources describe communication as a mix of keyboard actions, slash/say commands, boards, mail, and role-gated channels:

- ordinary talk and target-to-talk;
- whisper aliases;
- shout/sage-like broadcast listening;
- clan, group, and subpath chat;
- novice and tutor help channels;
- justice and report escalation channels;
- bulletin boards and web board mirrors;
- mail/NMail;
- Messenger parcels;
- public profile/user pages and role lists.

Reverse-engineering impact: the client likely has several channel identifiers, toggle states, and message panes. Some newer routes may be server-side additions that reused generic chat transport rather than requiring a large client UI change.

## Official Key Binding Model

Official Basic Keys documents communication-specific keys and toggles:

- `F2` and `Shift+F2`: subpath chat on/off;
- `F3` and `Shift+F3`: friends list;
- `F5` and `Shift+F5`: hear whisper/listen to whisper;
- `F6` and `Shift+F6`: hear shouts/listen to shout;
- `F9`: ignore list;
- `'`: talk;
- `"`: whisper;
- `" !`: whisper clan chat;
- `" @`: whisper subpath chat;
- `!`: shout;
- `:`: emote;
- `b`: bulletin boards;
- `g`: group with another;
- `Shift+g`: group on/off;
- `f`: view group;
- `Shift+f`: clan whisper on/off;
- `Shift+m`: mail;
- `v`: select target to talk;
- `p`: post.

Reverse-engineering leads:

- The repeated on/off wording suggests persistent local toggles for receiving or routing channels.
- Friends, ignore, group, board, mail, and post are likely separate windows or modal flows.
- Clan and subpath whisper shortcuts indicate privileged routes that may depend on server-side membership state.

## Official Slash And Say Commands

Official Verbal Commands documents chat and utility commands:

- `/s` and `!` for shout;
- `/c`, `/clan`, and `/g` for clan chat;
- `/t !!` for group chat;
- `/sp` for subpath chat;
- `/t name`, `/tell name`, `/whisper name`, and `/w name` for direct whisper;
- `/report` to online archons;
- `/novice`, `/n`, and `/tutor` for novice chat;
- `/r` and `/r#-#` for random rolls.

Reverse-engineering leads:

- Slash command aliases should map to a smaller number of internal channel IDs.
- `/g` is documented as clan chat while `g` as a key groups with another player; local code may distinguish typed command parsing from key handling.
- Dice commands may generate server-visible chat output rather than local-only random text.
- `/report` is officially documented as an archon route; later archive evidence distinguishes it from justice routing.

## 2020 Help, Justice, And Report Channel Evolution

Nexus Atlas April 2020 and August 2020 archive pages preserve reports of new or repaired help channels. The 2020 channel set includes:

- `/tutors`: direct help from tutors for path, spell, or quest questions;
- `/novice`: lower-level/new-player help, monitored by tutors;
- `/justice`: immediate judge or archon attention for active justice issues;
- `/report`: urgent bugs or gameplay-hindering situations needing Archons or GMs.

The August 2020 archive also mentions a chat-channel fix affecting Tutors, Ministry, Justice, and other channels.

Reverse-engineering leads:

- Search for both singular and plural variants: `/tutor`, `/tutors`, `/novice`, `/n`, `/justice`, and `/report`.
- Treat `/justice` and `/tutors` as possible later server-side additions if absent from older official command lists.
- `Ministry` in the August 2020 archive suggests government or kingdom-role channels beyond the baseline official command page.
- Channel purpose may be enforced socially, by role routing, by rate limits, or by server-side permission checks.

## Authority Roles And Routing Targets

Official Nexus Terminology defines several authority terms:

- Archons are special overseer characters with powers such as wall walking, fast movement, spawning monsters, and map-attribute adjustment.
- Judges are selected and trained players who arbitrate NexusTK law and can punish violations.
- Elders lead subpaths.
- Gods can refer to developer-controlled community-interaction characters or to totem spirits in roleplay.

Nexus Atlas job legend marks list community roles including Carnage Assistant, Carnage Host, Elder of Subpath, Founder of Subpath, Fox Hunt Host, Guide of Subpath, Judge, Primogen, and Tutor. Related marks include Being Mentored By, Justice Matter, and Tutored Students.

Reverse-engineering leads:

- Role names are useful string seeds for profile/legend/status windows and board permissions.
- Some role power may only exist on the server, but client UI may expose host tools, board tools, special movement, map attribute controls, or debug-like interfaces for Archons/GMs.
- `Justice Matter`, `Being Mentored By`, and `Tutored Students` suggest user-visible metadata that can appear in legend/profile rendering.

## Boards, Mail, And Profile-Linked Communication

Official Basic Keys document bulletin boards, post, and mail entry points. The official community page links public roles and groups such as clans, armies, judges, tutors, path lists, subpaths, user list, user profile, boards, and in-room pages.

Nexus Atlas archives and board mirrors show that some in-game boards have web-readable copies or official reposts. The public board root at `boards.nexustk.com` currently lists 24 public board mirrors, including Community, market, Hunting, Community Events, Dream Weaver, Law, Guide, Chronicles, Carnage, and path boards. The mirror schema uses static HTML rows with post number, date, author, and subject fields. Archive reports also use `NMail` as a player term for in-game mail.

Reverse-engineering leads:

- Boards likely have at least list, read, post, and maybe reply/delete/manage flows.
- Role authority can affect board write permissions and public directory/profile pages.
- Mail and Messenger parcels should be separated: mail is player communication, Messenger parcels can deliver items from web/item-shop flows.
- Search for `Board`, `Author`, `Subject`, `Date`, `Post`, `NMail`, `mail`, `Messenger`, `parcel`, `User profile`, and `User list`.
- See [UID:0000GL][board-mirror-catalog-and-schema](by-external-research/board-mirror-catalog-and-schema.md) for public board directories and mirror fields.

## Sage, Shout, And Broadcast Listening

Official keys expose shout send/listen behavior through `!`, `F6`, and `Shift+F6`. Nexus Atlas terminology uses `sage/shouts` in the Merchant treasure-hunt term `TH/[TH]`. Carnage rules from earlier research also mention hosts giving instructions through sage and tell players to enable it with `F6`.

Reverse-engineering leads:

- Treat `sage`, `shout`, and `listen to shout` as overlapping search terms.
- Host/event broadcasts may reuse shout infrastructure or a privileged broadcast channel.
- Search for `Sage`, `Shout`, `Hear shouts`, `Listen to Shout`, `TH`, `Treasure hunt`, and event-host role labels.

## Help Channel Purpose Boundaries

External sources imply distinct routing purposes:

- novice/tutor channels: path, spell, quest, hunting, and new-player support;
- justice channel: immediate law/harassment/scam/PVP/legal incidents;
- report channel: urgent bugs or gameplay blockers for Archons/GMs;
- boards: non-urgent reports, applications, schedules, laws, community postings;
- mail: non-urgent private contact with players, role holders, or Immortals.

Reverse-engineering leads:

- If channel identifiers are visible locally, names may appear in command parsing, help text, error messages, and server-response formatting.
- If channel identifiers are server-sent, the client may still contain generic channel-rendering logic with color/style selectors.
- Look for denial messages such as not authorized, no online recipients, level restricted, muted, ignored, or channel disabled.

## Likely Client/Server Ownership

Likely client-owned or client-visible:

- key bindings and hotkey labels;
- local chat input parser for slash aliases, if not server-parsed;
- channel toggle state for whisper, shout, clan, subpath, and group;
- chat pane rendering, colors, prefixes, and scrollback;
- friends and ignore list windows;
- board/mail/post windows;
- group view and target-to-talk selection;
- profile/legend display of role marks.

Likely server-owned:

- membership checks for clan/subpath/group/government channels;
- routing to tutors, judges, archons, GMs, and ministries;
- mute/ignore enforcement beyond local display;
- board content and permissions;
- mail delivery and storage;
- role assignments and legend marks;
- Archon/God/Judge powers.

Shared protocol candidates:

- send chat message with channel ID and recipient;
- channel toggle or subscription state;
- friends/ignore list update;
- board list/read/post operations;
- mail list/read/send/delete operations;
- role-channel broadcast;
- justice/report escalation packet or special chat route;
- server-sent channel error/status message.

## String And Data Search Leads

Search locally for:

- commands: `/s`, `/c`, `/clan`, `/g`, `/t !!`, `/sp`, `/tell`, `/whisper`, `/w`, `/report`, `/novice`, `/n`, `/tutor`, `/tutors`, `/justice`, `/r#-#`;
- channel labels: `Clan`, `Subpath`, `Group`, `Whisper`, `Shout`, `Sage`, `Novice`, `Tutor`, `Tutors`, `Justice`, `Report`, `Ministry`;
- role labels: `Archon`, `GM`, `Immortal`, `Judge`, `Tutor`, `Primogen`, `Elder`, `Guide`, `Carnage Host`, `Fox Hunt Host`;
- board/mail labels: `Board`, `Post`, `Author`, `Subject`, `Date`, `NMail`, `Mail`, `Messenger`, `parcel`;
- denial/status text: `ignore`, `ignored`, `muted`, `not authorized`, `not online`, `no tutors`, `no archons`, `no judges`, `channel`.

## Open-Question Resolution Notes 2026-05-24

- Current official slash commands: `/report`, `/novice`, `/n`, and `/tutor` are documented by official Verbal Commands. `/justice` and plural `/tutors` are not on that current official command page, but Nexus Atlas 2020 reports document them as active help/report routes.
- This narrows `/justice` and `/tutors`: treat them as later or separately documented service-routing aliases unless local target strings prove otherwise.
- Friends/ignore: current Basic Keys confirms UI entry points through `F3` friends list and `F9` ignore list, but public sources do not show whether the lists are local files, server state, or synchronized.
- Sage/shout: official keys expose shout send/listen behavior through `!`, `F6`, and `Shift+F6`; Carnage/social sources use `sage` as an event-host broadcast term. Public sources do not prove whether `sage` is the same internal channel as shout.
- Role tools: public terminology names Archon powers, Judges, Elders, and Gods, but does not document client-only tool windows. Keep this as a local UI/protocol question.

## Open Questions

- Which slash commands are parsed by the client versus sent raw to the server?
- Are `/justice` and `/tutors` present in the target build, or introduced later as server-side command aliases?
- Does `sage` share the same internal channel as shout, or is it a privileged broadcast route?
- Are friends and ignore lists stored locally, server-side, or both?
- Does the client contain role-specific tool windows for Archons/Judges/Carnage hosts, or only generic command surfaces?

## Sources

- [Official help: Basic Keys](https://help.nexustk.com/wiki/wiki/7/basic-keys)
- [Official help: Verbal Commands](https://help.nexustk.com/wiki/wiki/40/verbal-commands)
- [Official help: Nexus Terminology](https://help.nexustk.com/wiki/wiki/70/nexus-terminology)
- [Official help: Subpath Quests & Services](https://help.nexustk.com/wiki/wiki/87/subpath-quests-services)
- [Official NexusTK community page](https://www.nexustk.com/community.html)
- [Nexus Atlas: Job legend marks](https://www.nexusatlas.com/legends/jobs.php)
- [Nexus Atlas: Subpath legend marks](https://www.nexusatlas.com/legends/subpaths.php)
- [Nexus Atlas April 2020 archive](https://www.nexusatlas.com/archives/mainpage-archive-4-2020.php)
- [Nexus Atlas August 2020 archive](https://www.nexusatlas.com/archives/mainpage-archive-8-2020.php)
