** TARGET-REPORT-UID:0000FN **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B001-goal2-userlistdialogpane-class-source-quality-0000FN-20260618

## Finalized Report / Current Recommendation

Primary target [UID:0000FN][UserListDialogPane](../../../../../by-class/UserListDialogPane.md) should remain a class-level emitting document owned by [UID:0000OZ][UserListDialogPane](../../../../../by-file/UserListDialogPane.md). The direct source family remains `NexusTK/social/UserListDialogPane.cpp`; no split away to `UserPane`, `MapPane`, `LivingObjectPane`, `UserStatusPane`, or generic control infrastructure is justified. The class page should receive a first-draft class declaration and helper type declarations, while method bodies should remain owned by the executable memory aggregate [UID:0001KI][0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane](../../../../../by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md) or exact method children if the supervisor later splits them.

Recommended metadata:

| UID | Current | Recommended | Rationale |
| --- | --- | --- | --- |
| `0000FN` `UserListDialogPane` | `85/85`, `RECONSTRUCTABLE:TRUE`, owner/emitter `0000OZ`, blank C++ | `88/88`, keep owner/emitter `0000OZ`, populate class-level C++ | Fixed row layout, packet fields, singleton/source route, helper names, local class ownership, non-modeled chunk taxonomy, and class declaration readiness are now defensible. |
| `0000OZ` `by-file/UserListDialogPane.md` | `86/85` | `88/88` | File ownership is strengthened by validated social user-list class cluster, resource strings, singleton globals, packet route, and local helper taxonomy. |
| `0001KI` executable aggregate | Header `85/86`; coverage row stale at `82%` | `87/88`, keep owner/emitter `0000OZ`, keep aggregate formal C++ blank | Behavior is now materially better resolved, but it is still a broad interleaved executable island containing `UserListDialogPane`, `PartySearchEditPane`, `UserListPane`, reusable checkbox-control thunks, comparators, table data, and local no-route helper code. Class/method declarations can emit elsewhere; the broad aggregate should not be the formal C++ container. |
| `0000FO` `UserListPane` | `85/87` | keep score unless supervisor wants a support-only bump to `86/88` | Row layout and source-text state are now clearer for `UserListPane`, but this report is not a full class-C++ pass for that target. Add support notes only. |
| `0000A7` `PartySearchEditPane` | `85/89` | keep score | Its `"Put me on the hunters list"` action is key evidence for the user-list row flag, but no ownership or score repair is needed. |
| `0002A7` memory flag at `0x0069bed0` | `86/88`, name says `ShowHiddenFlag` | rename/reclassify to `UserListDialogHuntersListOnlyFlag`, `88/90` | Existing "show hidden" semantics are contradicted by filtering evidence. The byte makes the dialog show only rows whose per-record hunters-list/party-search flag is set. |
| `0002ZX` global flag page | `86/88`, name says `g_bShowHiddenUsers` | rename/reclassify to `g_bShowHuntersListOnly`, `88/90` | Use a descriptive inferred name rather than the stale hidden-users name. This is a module-scope `bool`-like flag in `UserListDialogPane.cpp`. |

The primary remaining low-confidence item is source-original naming. The binary supports high-probability descriptive names for the record fields and helpers, but does not prove original identifiers. That uncertainty should not block class-level first-draft C++; use descriptive names and mark them inferred.

## Evidence Checked

Documents inspected:

- [UID:0000FN][by-class/UserListDialogPane.md](../../../../../by-class/UserListDialogPane.md)
- [UID:0000OZ][by-file/UserListDialogPane.md](../../../../../by-file/UserListDialogPane.md)
- [UID:0001KI][by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md](../../../../../by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md)
- [UID:0000FO][by-class/UserListPane.md](../../../../../by-class/UserListPane.md)
- [UID:0000A7][by-class/PartySearchEditPane.md](../../../../../by-class/PartySearchEditPane.md)
- [UID:00026U][by-memory/0x0062e8fc-0x0062eccc.UserListReadOnlyData.md](../../../../../by-memory/0x0062e8fc-0x0062eccc.UserListReadOnlyData.md)
- [UID:0003E6][UserListDialogPane vtable lead-in data](../../../../../by-memory/0x0062e8fc-0x0062e998.UserListDialogPaneVtableData.md)
- [UID:0003E7][PartySearchEditPane vtable data](../../../../../by-memory/0x0062ea3c-0x0062eadc.PartySearchEditPaneVtableData.md)
- [UID:0003E8][UserListPane vtable data](../../../../../by-memory/0x0062eadc-0x0062eb9c.UserListPaneVtableData.md)
- [UID:0003E9][UserList resource strings](../../../../../by-memory/0x0062eb9c-0x0062eccc.UserListResourceStrings.md)
- [UID:00029Y][MessageStatusAndMenuPaneGlobals](../../../../../by-memory/0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals.md)
- [UID:0002A7][0x0069bed0-0x0069bed4.UserListDialogShowHiddenFlag](../../../../../by-memory/0x0069bed0-0x0069bed4.UserListDialogShowHiddenFlag.md)
- [UID:0002ZX][g_bShowHiddenUsers](../../../../../by-global/g_bShowHiddenUsers.md)
- [UID:0003EI][g_pUserListDialogPane](../../../../../by-global/g_pUserListDialogPane.md)
- [UID:0003VB][UserPaneHandleServerMessage](../../../../../by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md)
- [UID:0003US][LivingObjectPaneHandleUserListPacket](../../../../../by-memory/0x005abb20-0x005abc6f.LivingObjectPaneHandleUserListPacket.md)
- Executed B001 report `research/executed/0003VB-0003US-UserPaneUserListDispatchSourceShape-source-quality.md`.
- Current coverage rows in `by-class/-coverage-report.md`, `by-file/-coverage-report.md`, `by-memory/-coverage-report.md`, and `by-global/-coverage-report.md`.

Raw binary evidence checked from `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`:

- VA disassembly for `0x0059bc90-0x0059f25b`, including constructor, sort helpers, refresh, packet handler, command handler, local helpers, `PartySearchEditPane`, `UserListPane`, comparators, and destructors.
- Raw string decoding for `0x0062eb9c-0x0062eccc`.
- Server packet name table at base `0x00625008` with stride `0x7e`: index `0x36` resolves to `kServerUserList` at `0x00626a9c`.
- Direct/absolute references to switch tables and comparator/helper starts.
- Constructor caller contexts at `0x005087f4`, `0x00513c6c`, `0x005a7ccb`, and retained duplicate route `0x005abc54` already documented by the accepted [UID:0003VB]/[UID:0003US] report.

IDA MCP status:

- The local IDA MCP endpoint `http://127.0.0.1:13337/mcp` was not reachable during this continuation (`Unable to connect to the remote server`). This report therefore uses existing IDA-backed docs, accepted B001 reports, and current raw PE/Capstone inspection as the IDA-equivalent evidence source. Any statement below that says "no direct route found" means no direct rel32 or absolute VA route was found in the raw binary scan and no existing doc supplied a stronger live xref.

## IDA MCP Facts / Raw PE Facts

### Constructor and object layout

- `0x0059bc90` constructs a `UserListDialogPane` object of size `0x28c` and publishes `this` into `0x0069b4e0` (`g_pUserListDialogPane`) at `0x0059bce4`, with fallback/null clear at `0x0059bceb`.
- The vtable lead-in at `0x0062e960` is stored at `this+0xa0` at `0x0059bd16`. The exact read-only-data child [UID:0003E6] is correctly owned by [UID:0000FN].
- The constructor consumes a server payload whose first user-list fields are:
  - `payload[0]`: server opcode / message selector, validated by opcode `0x36` dispatch and `kServerUserList`.
  - `payload+1`: big-endian word, best named `serverTotalUserCount` or `totalUserCount`. It is read before the entry loop and later used to compute displayed/hidden-filtered totals.
  - `payload+3`: big-endian word, best named `userListEntryCount`. It bounds the `0x414` row-record parse loop.
  - `payload+5`: sort/view mode byte. It seeds the dialog sort-mode radio/control state; current evidence supports `initialSortMode` or `userListModeByte`, not a stronger protocol name.
  - `payload+6`: first encoded user-list record.
- The constructor allocates five repeated `UserListPane` children of size `0x49c` through `0x0059e710`, passing row size `0x414`, visible count `0x64`, and a bucket/list kind value `5`. The five pointers are stored at `this+0x274`, `this+0x278`, `this+0x27c`, `this+0x280`, and `this+0x284`.
- The constructor allocates the master record list at `this+0x288` with element size `0x414` and capacity `0x64`.
- Object state fields supported by raw writes/reads:
  - `this+0x26c`: selected category/career id used by `RefreshCategoryView`.
  - `this+0x26e`: category page/cycle index, clamped from `0` to `5`.
  - `this+0x270`: selected local-player career variant/special-filter byte widened into a word-sized field.
  - `this+0x274..0x284`: five `UserListPane *` bucket panes. Nonzero bucket values index `this+0x270 + bucket*4`, so bucket `1` maps to `this+0x274`, bucket `2` to `this+0x278`, bucket `3` to `this+0x27c`, bucket `4` to `this+0x280`, and bucket `0` falls through to `this+0x284`.
  - `this+0x288`: master list/container of `0x414`-byte user records.

### `0x414` user-list record layout

Best supported packed record layout:

| Offset | Size | Recommended name | Evidence |
| --- | ---: | --- | --- |
| `+0x000` | 1 | `careerId` / `categoryId` | High nibble of encoded byte 0; compared against selected category/career in constructor and refresh. |
| `+0x001` | 1 | `bucketIndex` / `statusBucket` | Low bits of encoded byte 0; selects one of five `UserListPane` bucket panes. |
| `+0x002` | 1 | `reserved2` / unresolved parsed flag | Constructor zeroes it. No stronger read evidence found in current target. Do not name it `hiddenFlag` without new evidence. |
| `+0x003` | 1 | `badgeIconId` / `secondaryIconId` | Low bits of encoded byte 1; `UserListPane` drawing uses values `1..4` to choose a 16-icon badge. |
| `+0x004` | 1 | `displayColor` / `rowColor` | Encoded packet byte 3; draw path uses it for row background/foreground behavior. The local player match path overwrites it with `0x80`. |
| `+0x005..+0x007` | 3 | padding/reserved | No stable semantic reads found. |
| `+0x008` | 4 | `arrivalSortKey` / `sequenceSortKey` | Set to `100000 - ordinal`; status comparator uses it as tie-breaker. |
| `+0x00c` | 1 | `statusIconId` / `rankIconId` | High nibble of encoded byte 1; draw path renders star/status icon for values `1..4`; comparator prioritizes this byte. |
| `+0x00d` | 1 | padding/reserved | Alignment before wide name. |
| `+0x00e` | `0x200` | `name[256]` UTF-16 | Length-prefixed MBCS name is converted into this buffer; list matching and double-click/source requests compare this field. |
| `+0x20e` | 1 | `huntersListFlag` / `partySearchListed` | Encoded from low bits of packet byte 2; filter flag at `0x0069bed0` skips rows where this byte is zero; `PartySearchEditPane` label says `"Put me on the hunters list"`; opcode `0x83` updates this field for the local player; double-click only requests source text when this byte is nonzero. |
| `+0x20f` | 1 | `hasSourceText` | Cleared after name conversion; opcode `0x84` sets it and stores source text; double-click checks it before posting cached source text. |
| `+0x210` | `0x200` | `sourceText[256]` UTF-16 | Opcode `0x84` copies a converted source string here; `AddUserListSourceMessage` formats this text with the row name. |
| `+0x410` | 1 | `careerVariant` / `specialFilterValue` | High nibble of encoded byte 2; selected-category case `10` compares it against `this+0x270`. |
| `+0x411..+0x413` | 3 | padding/reserved | No stable semantic reads found. |

Rejected record alternatives:

- `+0x20e` as `hidden` or `showHidden`: rejected. When the global byte is `1`, constructor/refresh skip records where `+0x20e == 0`; that is a "show only rows with this flag" filter, not hidden-user display. `PartySearchEditPane` supplies the UI string `"Put me on the hunters list"` and its action updates `g_pPlayerData+0x3cb1`, which is also written by packet opcode `0x83` and mirrored into row `+0x20e`.
- `+0x20f` as another flag unrelated to source text: rejected. It is set only with source-string population and gates cached source-message posting.
- `+0x00e` as ANSI: rejected. The parse path converts MBCS to UTF-16 and subsequent compares/draws use wide-string helpers.
- `+0x210` as target name: rejected. `%s > %s` formatting receives `row+0x00e` as name and `row+0x210` as source text.

### Sort and comparator names

Existing names appear swapped:

- `0x0059e950` compares `row+0x0c` first and `row+0x08` as a tie-breaker. Recommended name: `CompareUserListRecordsByStatus` or `CompareUserListRecordsByRank`.
- `0x0059e990` compares wide strings at `row+0x0e`. Recommended name: `CompareUserListRecordsByName`.
- `0x0059d1f0` pushes comparator `0x0059e950`; recommended method name: `SortListsByStatus`.
- `0x0059d250` pushes comparator `0x0059e990`; recommended method name: `SortListsByName`.
- `RefreshCategoryView` uses the control state from command/control id `3`: state `0` sorts with `0x0059e950`, state `1` sorts with `0x0059e990`. The UI labels are not proven, so state names should remain `kSortByStatus`/`kSortByName` unless strings are later found.
- `0x0059e9b0` and `0x0059e9d0` are small wrappers that sort a `UserListPane` internal list at `this+0x130` with `0x0059e950` and `0x0059e990` respectively. No direct rel32/absolute route to the wrapper starts was found in the raw scan; document as retained/no-route local wrappers, not public methods.

### Packet handler names and fields

`UserListDialogPane::HandleUserListPacket` at `0x0059d620` handles two relevant packet opcodes:

- Opcode `0x83`: local hunters-list/party-search listed flag synchronization.
  - Reads `payload[1]` as a byte flag.
  - Writes the flag to `g_pPlayerData + 0x3cb1`.
  - Updates the command/control id `20` child state through the dialog control tree.
  - Searches master rows by local player name and writes the matching row's `+0x20e` to the flag.
  - Calls `RefreshCategoryView` so the current filter/bucket display reflects the changed flag.
  - Recommended local handler name if split later: `HandleHuntersListFlagPacket` or `HandlePartySearchListedFlagPacket`.
- Opcode `0x84`: source-text response/update.
  - Reads a length-prefixed target name beginning at `payload+1`.
  - Reads the source-text length immediately after the target-name bytes.
  - Converts both fields to bounded UTF-16 buffers.
  - Finds the matching master row by `row+0x0e`.
  - Sets `row+0x20f = 1` and copies source text into `row+0x210`.
  - Calls `0x0059e9f0` to synchronize the source text into the corresponding visible bucket/list duplicate.
  - Calls `0x0059de60` to post the formatted message.
  - Recommended local handler name if split later: `HandleUserListSourceTextPacket`.

`UserListPane` double-click behavior validates the same interpretation:

- It ignores rows with `row+0x20e == 0`.
- If `row+0x20f == 1`, it calls `AddUserListSourceMessage` with the cached row.
- Otherwise it sends outbound opcode `0x85` plus the selected row name, best named `RequestUserListSourceText`.

### Local helpers and non-modeled aggregate chunks

- `0x0059d198-0x0059d1e0`: contains padding followed by a real non-deleting destructor/EH cleanup helper at `0x0059d1a0`. It resets `this`, `this+0xa0`, and `this+0xa4` vtable slots, deletes `this+0x288` when non-null, calls the dialog base destructor, clears `g_pUserListDialogPane`, and returns. No direct route to `0x0059d1a0` was found; best source shape is compiler destructor body / constructor-unwind cleanup, not a public helper.
- `0x0059d5fe-0x0059d620`: not unknown source code. It is alignment plus the `RefreshCategoryView` switch table at `0x0059d600`, with dword case targets `0x0059d31c`, `0x0059d32b`, `0x0059d333`, `0x0059d33a`, `0x0059d341`, and `0x0059d348`, followed by `int3` padding. There is an absolute dword reference from the refresh logic to `0x0059d600`.
- `0x0059dbe3-0x0059de60`: contains `OnControlCommand` switch-table data beginning at `0x0059dbe4`, selector bytes, `int3` padding, and then a real but no-route helper at `0x0059dc20`.
- `0x0059dc20-0x0059de4a`: real code-shaped helper, but no direct rel32/absolute route to the start was found. It reads local player name/status data from `g_pPlayerData`, mirrors the hunter-list flag/source text into the local player's row, builds outbound opcode `0x84`, and sends through the packet sender global. Best descriptive name: `SubmitPartySearchSettingsFromDialog` or `SendUserListPartySearchSettings`. Because it lacks a live route in current evidence, do not emit it as a public class method yet; keep it as retained/no-route local helper evidence under [UID:0001KI].
- `0x0059de60-0x0059decf`: direct helper reached from `0x0059d7c2` and `0x0059eeb0`. It checks the chat/system output sink at `0x0067adcc`, formats `"%s > %s"` using `row+0x0e` and `row+0x210`, and calls the message output helper with style arguments including `0x8f` and `0x80`. Recommended source-facing name: `AddUserListSourceMessage` or `PostUserListSourceMessage`; use `static void __cdecl AddUserListSourceMessage(const UserListRecord *record);`.
- `0x0059e9a6-0x0059e9f0`: contains small list-sort wrappers at `0x0059e9b0` and `0x0059e9d0`; no direct route to wrapper starts was found. The comparator addresses themselves are referenced from constructor/refresh/sort paths.
- `0x0059e9f0-0x0059ea8f`: direct helper reached only from `0x0059d7b0`. It searches a bucket/list pane by row name and copies `hasSourceText` plus `sourceText` from the master row into the visible duplicate. Recommended source-facing name: `SyncUserListSourceTextIntoBucket`.

### Resource strings and read-only data

Decoded resource/string tail:

- `0x0062eb9c`: `Users Dialog Pane`
- `0x0062ebc0`: `USERLIST.PAL`
- `0x0062ebdc`: `USERLIST.EPF`
- `0x0062ebf8`: `USERLIST.PAD`
- `0x0062ec14`: `USERLIST.EPD`
- `0x0062ec30`: `%s > %s`
- `0x0062ec40`: `Put me on the hunters list`
- `0x0062ec78`: `STAR.EPF`
- `0x0062ec8c`: `ICON.EPF`
- `0x0062eca0`: `STAR.EPD`
- `0x0062ecb4`: `ICON.EPD`

The string `"Put me on the hunters list"` is decisive support that the row flag at `+0x20e` and global filter byte at `0x0069bed0` are hunters-list/party-search UI state, not hidden-user visibility.

### Packet route and opcode support

- [UID:0003VB] already accepted that opcode `0x36` is a live `UserPane` inline user-list case, while [UID:0003US] is a retained duplicate/no-live-route helper.
- The `MapPane` dispatcher route at `0x005087c2-0x005087f4` lazily creates `UserListDialogPane` if `g_pUserListDialogPane` is null, allocates `0x28c`, and calls `0x0059bc90`.
- Raw server packet-name table index `0x36` is `kServerUserList` at `0x00626a9c`; the current [UID:0001SO][MapServerPacketOpcode](../../../../../by-type/by-enum/MapServerPacketOpcode.md) row saying "transfer/server dialog path" is stale for this opcode and should be replaced.

## Heuristic / Inference Reanalysis And Validation

### Fixed record fields

Validation: the `0x414` record size is not merely a generated-code guess. It is passed into the list constructor/allocation paths, used for master list capacity, and matches all observed field offsets through `+0x413`. The record contains two 256-wide-character buffers, one at `+0x0e` and one at `+0x210`, with one-byte flags before the second buffer and a one-byte variant selector at `+0x410`.

Best inference: name the type `UserListRecord` or `UserListEntryRecord`. `UserListRecord` is shorter and fits both master and bucket/list duplicate storage.

Rejected alternatives:

- `UserInfoRecord`: too broad and conflicts with nearby `UserInfoDialogPane`.
- `HiddenUserRecord`: contradicted by hunters-list evidence.
- `PartySearchRecord`: too narrow; the same record also carries career/category/status/icon/name/sort data for the whole user list.

Impact: this resolves the fixed-record field blocker for [UID:0000FN] and materially improves [UID:0000FO]. It supports class-level declarations but not full method bodies on the class page.

### Packet fields

Validation: constructor payload fields from `payload+1`, `payload+3`, `payload+5`, and `payload+6` are supported by the parse loop and accepted opcode route. Opcode `0x83` and `0x84` semantics are supported by writes to `g_pPlayerData+0x3cb1`, row `+0x20e`, row `+0x20f`, row `+0x210`, and the outbound/cached source-message paths.

Best inference:

- Constructor signature: `UserListDialogPane(const unsigned char *packet)` or `UserListDialogPane(const ServerPacket *packet)` if the project's packet wrapper type is already available. Use byte pointer in the first draft to avoid inventing a wrapper.
- Packet `0x83`: `HandleHuntersListFlagPacket`.
- Packet `0x84`: `HandleUserListSourceTextPacket`.
- Outbound `0x85`: `RequestUserListSourceText`.

Rejected alternatives:

- Naming `payload+5` as final `sortMode`: partially supported, but the byte may include view mode. Use `initialSortMode`/`userListModeByte` until control labels are found.
- Naming `payload+1` as `visibleCount`: likely wrong because filtering subtracts hidden/skipped rows from it; use `serverTotalUserCount`.

Impact: clears the packet-field blocker with one remaining caveat on original protocol naming.

### `g_bShowHiddenUsers` reanalysis

Validation: both constructor and `RefreshCategoryView` test the global byte at `0x0069bed0`; when it equals `1`, they skip records whose row `+0x20e` is zero. The records that remain are exactly those marked by the hunters-list/party-search flag. `PartySearchEditPane`'s UI string and packet opcode `0x83` both point to hunter-list membership.

Best inference: rename the global to `g_bShowHuntersListOnly` or `g_bUserListHuntersOnly`. I recommend `g_bShowHuntersListOnly` because the observed behavior is display filtering, not record ownership. Rename the exact memory page to `UserListDialogHuntersListOnlyFlag`.

Rejected alternatives:

- Keep `g_bShowHiddenUsers`: contradicted by the skip condition and UI string.
- Name it `g_bHideNonHunters`: semantically accurate but less source-like and not directly phrased as UI state.
- Name it `g_bPartySearchOnly`: plausible but weaker than the literal string `"hunters list"`.

Impact: requires supervisor-owned support/coverage text changes for [UID:0002A7] and [UID:0002ZX]. This is the strongest correction in the assignment.

### Helper names

Validation: `0x0059de60` has direct callers and formats the `"%s > %s"` source message; `0x0059e9f0` has a direct caller from opcode `0x84` and synchronizes bucket duplicate records; comparator bodies define their names from field reads rather than generated labels.

Best inference:

- `0x0059de60`: `AddUserListSourceMessage` or `PostUserListSourceMessage`; use `AddUserListSourceMessage` to preserve current doc continuity while removing the address suffix.
- `0x0059e9f0`: `SyncUserListSourceTextIntoBucket`.
- `0x0059e950`: `CompareUserListRecordsByStatus`.
- `0x0059e990`: `CompareUserListRecordsByName`.
- `0x0059d1f0`: `SortListsByStatus`.
- `0x0059d250`: `SortListsByName`.

Rejected alternatives:

- Preserve `SortListsByName` at `0x0059d1f0`: contradicted by the comparator address and comparator body.
- Preserve `SortListsByStatus` at `0x0059d250`: contradicted by the wide-string comparator.
- Name `0x0059de60` as a generic chat helper: rejected because it is user-list-specific, uses the user-list source format, and is only called from this island in current evidence.

Impact: class C++ should use the corrected sort method names. Existing docs should be revised to avoid propagating swapped names.

### Non-modeled chunks

Validation: raw byte inspection divides the suspicious gaps into compiler/runtime artifacts, switch tables, direct local helpers, and no-route retained helpers. No arbitrary "unknown chunk" remains in the primary class evidence.

Best inference:

- Do not split `0x0059d198-0x0059d1e0` as an ordinary user-authored public helper; document it as destructor/unwind cleanup.
- Do not split `0x0059d5fe-0x0059d620` as code; it is `RefreshCategoryView` jump-table data plus padding.
- Do not split `0x0059dbe3-0x0059dc20` as code; it is `OnControlCommand` switch-table data plus padding.
- Keep `0x0059dc20` documented as a retained/no-route local send helper until a route is found.
- Keep `0x0059e9b0`/`0x0059e9d0` documented as retained/no-route local sort wrappers.

Rejected alternatives:

- Creating new emitting child pages for every raw helper start now: rejected because most are compiler tables/wrappers or lack a live route. The executable aggregate can document them without premature child pages.
- Folding checkbox-control thunks into `UserListDialogPane`: rejected by exact reusable `CheckBoxTextControlPane` ownership.

Impact: supports raising [UID:0001KI] coverage/score without turning the aggregate into a formal C++ method body.

### Source placement and ownership

Validation: constructor, local classes, singleton globals, resource strings, and row helpers all cluster under `UserListDialogPane.cpp`. `UserPane`, `MapPane`, and `LivingObjectPane` are packet dispatch callers or retained duplicates; they do not own the dialog class. `PartySearchEditPane` and `UserListPane` are local classes in the same source file rather than separate source files based on current coverage ownership and resource adjacency.

Best inference: keep [UID:0000FN], [UID:0000FO], [UID:0000A7], [UID:0001KI], [UID:0002ZX], [UID:0003EI], and user-list read-only data under [UID:0000OZ] unless future source-tree evidence proves a narrower file split.

Rejected alternatives:

- `UserPane` ownership: rejected; it dispatches opcode `0x36` and constructs/updates the dialog, but the class body, strings, globals, and local helpers live in the user-list island.
- `LivingObjectPane` ownership: rejected; [UID:0003US] is an accepted retained duplicate/no-live-route helper.
- `UserStatusPane`/`g_pOldUserStatusPane` ownership: rejected; neighboring global storage is unrelated singleton state.
- Generic list/control infrastructure ownership: rejected for user-list-specific record parse, source-message protocol, resource strings, and `UserListPane` vtable.

Impact: no owner/emitter change for [UID:0000FN]; support docs need naming and score updates, not a split.

### Final C++ readiness

Validation: [UID:0000FN] is a class page, not the executable method-body aggregate. The class declaration can express the validated record type, member fields, constructor/destructor, sort/refresh/packet/control methods, and local static helpers without pretending to fully decompile every body.

Best inference: populate [UID:0000FN] formal C++ with class-level declarations and the packed `UserListRecord` helper type. Do not populate [UID:0001KI] aggregate formal C++ from this report, because it remains a mixed island with multiple classes, switch tables, exact reusable child controls, and no-route local helper bodies. If formal method bodies are desired, create exact method children or apply a separate method-body pass.

Rejected alternatives:

- Keep [UID:0000FN] C++ blank: no longer justified after row layout and class shape are resolved.
- Put all method bodies in [UID:0000FN]: rejected by current documentation structure. Class pages should not absorb executable aggregate bodies unless that is the established local convention for this project.

Impact: primary target can clear the code-entry gate after metadata update.

## Ranked Ownership Analysis

1. [UID:0000OZ][`UserListDialogPane.cpp`](../../../../../by-file/UserListDialogPane.md) is the correct source owner. It owns the class, local list pane, party-search pane, singleton pointer, hunters-list-only filter byte, user-list resources, record parser, source-message helper, and source-text request/update logic.
2. [UID:0000FN][`UserListDialogPane`](../../../../../by-class/UserListDialogPane.md) is the correct direct class owner for the dialog declaration and high-level class member documentation. It should not become a split/index page.
3. [UID:0000FO][`UserListPane`](../../../../../by-class/UserListPane.md) owns repeated row-widget drawing, selection, double-click, and source-request behavior. It should receive row-layout support notes but does not displace the dialog class.
4. [UID:0000A7][`PartySearchEditPane`](../../../../../by-class/PartySearchEditPane.md) owns the hunter-list text-entry subdialog and provides strong semantic evidence for row `+0x20e`; it remains a local class under the same file.
5. `MapPane` and [UID:0003VB][`UserPaneHandleServerMessage`](../../../../../by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md) are dispatch/constructor callers only. They should retain caller notes and opcode rows but should not own user-list class declarations.
6. [UID:0003US][`LivingObjectPaneHandleUserListPacket`](../../../../../by-memory/0x005abb20-0x005abc6f.LivingObjectPaneHandleUserListPacket.md) remains a retained duplicate/no-live-route helper for opcode `0x36`; it should not receive dialog source ownership.
7. `CheckBoxTextControlPane`/specialized button infrastructure owns exact reusable checkbox-control vtable/data chunks only. It does not own user-list row storage, packet parsing, or dialog state.
8. `UserStatusPane`, `g_pOldUserStatusPane`, and message/menu globals are neighboring support state only. No current evidence routes the user-list class to those owners.

## Open Questions Resolved Or Remaining

Resolved:

- Fixed `1044`/`0x414` user-record layout: resolved with field names above.
- Packet fields: resolved to constructor total/count/mode/records, opcode `0x83` hunter-list flag update, opcode `0x84` source-text update, and opcode `0x85` source-text request.
- `AddUserListSourceMessage_59DE60`: resolved to `AddUserListSourceMessage` / `PostUserListSourceMessage`, a static/free local helper taking a `UserListRecord const *`.
- Sort helper names: current docs should swap the `0x0059d1f0`/`0x0059d250` source-facing names to status/name respectively.
- `g_bShowHiddenUsers`: resolved as stale/wrong; use `g_bShowHuntersListOnly` or `g_bUserListHuntersOnly`.
- Non-modeled chunks: resolved into destructor cleanup, switch tables, retained/no-route send helper, retained/no-route sort wrappers, and direct source-text sync helper.
- Ownership/source placement: remains `NexusTK/social/UserListDialogPane.cpp`, with local class pages for `UserListDialogPane`, `UserListPane`, and `PartySearchEditPane`.
- Class C++ readiness: primary class page should be populated with declarations.

Remaining but bounded:

- Original source identifiers for `serverTotalUserCount`, `initialSortMode`, `careerVariant`, `statusIconId`, and `bucketIndex` are not proven. Current names are descriptive and source-facing enough for draft C++ but should be marked inferred.
- `row+0x002` and reserved padding bytes still lack meaningful semantic reads. They should remain reserved/unresolved and should not affect score because the main behavior does not depend on them.
- `0x0059dc20` may be a local helper reachable indirectly by an unmodeled UI/control route, but no direct rel32/absolute route was found. Keep it documented as retained/no-route local send helper until a route is found.

## First-Draft C++ Recommendation

Populate [UID:0000FN] formal C++ with a class-level declaration, not method bodies. The following is source-style mid-2000s C++ and intentionally uses descriptive inferred names where original identifiers are not proven.

```cpp
class DialogPane;
class UserListPane;
class PartySearchEditPane;
class PacketEventContext;
class KeyEvent;
class ControlPane;

#pragma pack(push, 1)
struct UserListRecord
{
    unsigned char careerId;          // +0x000, encoded byte 0 high nibble
    unsigned char bucketIndex;       // +0x001, encoded byte 0 low bits
    unsigned char reserved2;         // +0x002, written as zero by the parser
    unsigned char badgeIconId;       // +0x003, encoded byte 1 low bits
    unsigned char displayColor;      // +0x004, encoded packet byte 3
    unsigned char reserved5[3];      // +0x005
    long arrivalSortKey;             // +0x008, 100000 - packet ordinal
    unsigned char statusIconId;      // +0x00c, encoded byte 1 high nibble
    unsigned char reservedD;         // +0x00d
    wchar_t name[256];               // +0x00e
    unsigned char huntersListFlag;   // +0x20e, "hunters list" / party-search listed
    unsigned char hasSourceText;     // +0x20f
    wchar_t sourceText[256];         // +0x210
    unsigned char careerVariant;     // +0x410, encoded byte 2 high nibble
    unsigned char reserved411[3];    // +0x411
};
#pragma pack(pop)

class UserListDialogPane : public DialogPane
{
public:
    explicit UserListDialogPane(const unsigned char *packet);
    virtual ~UserListDialogPane();

    void SortListsByStatus();
    void SortListsByName();
    void RefreshCategoryView(int step);
    bool HandleUserListPacket(PacketEventContext *event);
    virtual bool OnKeyEvent(KeyEvent *event);
    virtual void OnControlCommand(unsigned int commandId);

private:
    void AddRecordToCurrentBucket(UserListRecord *record);
    void RebuildCategoryBuckets();
    void UpdateCountLabels();

    static int __cdecl CompareUserListRecordsByStatus(const void *left, const void *right);
    static int __cdecl CompareUserListRecordsByName(const void *left, const void *right);
    static void __cdecl AddUserListSourceMessage(const UserListRecord *record);
    static void __cdecl SyncUserListSourceTextIntoBucket(UserListPane *pane,
                                                         const UserListRecord *record);

private:
    // Observed object offsets; inherited DialogPane storage occupies the preceding bytes.
    short m_selectedCategoryId;       // +0x26c
    short m_categoryPage;             // +0x26e
    short m_selectedCareerVariant;    // +0x270
    short m_reserved272;              // +0x272
    UserListPane *m_bucketPanes[5];   // +0x274..+0x287
    void *m_allUsers;                 // +0x288, list of UserListRecord, element size 0x414
};
```

Recommended companion declarations for [UID:0000OZ] or a file-level support section, not necessarily [UID:0000FN] formal C++:

```cpp
extern UserListDialogPane *g_pUserListDialogPane;
extern bool g_bShowHuntersListOnly;
```

Do not populate formal C++ for [UID:0001KI] from this report. Target-specific no-code proof for [UID:0001KI]: it is an executable aggregate spanning multiple classes and compiler artifacts: `UserListDialogPane`, `PartySearchEditPane`, `UserListPane`, checkbox-control interleaves, switch tables, comparator functions, direct helpers, no-route retained helpers, scalar-deleting destructor families, and resource/data adjacency. A single aggregate C++ body would either duplicate class-page declarations or collapse multiple source entities into one invalid source unit. Formal method bodies should be introduced through exact method children or a separate focused method-body report.

## Exact Supervisor Changes Required

Apply these changes in the shared docs; this B001 report does not edit them.

### [UID:0000FN] `by-class/UserListDialogPane.md`

Header:

- Change `COMPLETION` from `85` to `88`.
- Change `CONFIDENCE` from `85` to `88`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `CANONICAL_OWNER:0000OZ`.
- Keep `EMITTER_UIDS:0000OZ`.
- Populate formal C++ with the class declaration in `## First-Draft C++ Recommendation`.

Add/replace a source-quality note near the current open-question section:

```markdown
2026-06-18 B001 source-quality pass: resolved the fixed user-list row layout as packed `UserListRecord` size `0x414`, with `careerId` at `+0x00`, `bucketIndex` at `+0x01`, `badgeIconId` at `+0x03`, `displayColor` at `+0x04`, `arrivalSortKey` at `+0x08`, `statusIconId` at `+0x0c`, UTF-16 `name[256]` at `+0x0e`, hunters-list/party-search listed flag at `+0x20e`, source-text-valid flag at `+0x20f`, UTF-16 `sourceText[256]` at `+0x210`, and `careerVariant` at `+0x410`. Constructor packet fields are `payload+1` total user count, `payload+3` entry count, `payload+5` initial sort/view mode, and `payload+6` encoded records. Packet opcode `0x83` updates the local hunters-list flag; opcode `0x84` updates source text; UserListPane double-click sends opcode `0x85` to request missing source text. Existing `SortListsByName`/`SortListsByStatus` labels were swapped by generated output: `0x0059d1f0` sorts by status/rank comparator `0x0059e950`, while `0x0059d250` sorts by wide name comparator `0x0059e990`. The old `g_bShowHiddenUsers` name is stale; the byte at `0x0069bed0` is a hunters-list-only filter because enabled refresh/constructor paths skip rows whose `+0x20e` flag is zero and `PartySearchEditPane` uses the literal "Put me on the hunters list".
```

### [UID:0000OZ] `by-file/UserListDialogPane.md`

Header:

- Change `COMPLETION` from `86` to `88`.
- Change `CONFIDENCE` from `85` to `88`.

Replace the stale global/support wording that says `g_bShowHiddenUsers` or "show hidden users" with:

```markdown
- `g_bShowHuntersListOnly` (inferred source-facing name for `0x0069bed0`, currently documented by [UID:0002A7]): module-scope boolean-like filter used by `UserListDialogPane` construction and refresh. When set, the dialog includes only records whose `UserListRecord::huntersListFlag` at `+0x20e` is nonzero. The previous `g_bShowHiddenUsers` name is stale; no current evidence shows a hidden-user visibility flag.
```

Add helper-name replacement text:

```markdown
- `AddUserListSourceMessage` (`0x0059de60`): static/free local helper that formats `"%s > %s"` with `UserListRecord::name` and `UserListRecord::sourceText`, then posts the result to the message output sink.
- `SyncUserListSourceTextIntoBucket` (`0x0059e9f0`): local helper called by opcode `0x84` handling to copy `hasSourceText/sourceText` from the master record to the visible bucket duplicate with the same UTF-16 name.
- `CompareUserListRecordsByStatus` (`0x0059e950`) and `CompareUserListRecordsByName` (`0x0059e990`) are comparator helpers. `0x0059d1f0` should be named `SortListsByStatus`; `0x0059d250` should be named `SortListsByName`.
```

### [UID:0001KI] `by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md`

Header:

- Change `COMPLETION` from `85` to `87`.
- Change `CONFIDENCE` from `86` to `88`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `CANONICAL_OWNER:0000OZ`.
- Keep `EMITTER_UIDS:0000OZ`.
- Keep aggregate formal C++ blank with the no-code proof above.

Add/replace non-modeled chunk note:

```markdown
2026-06-18 B001 non-modeled chunk reanalysis: `0x0059d198-0x0059d1e0` is padding plus a non-deleting destructor / constructor-unwind cleanup helper at `0x0059d1a0`; `0x0059d5fe-0x0059d620` is `RefreshCategoryView` switch-table data at `0x0059d600` plus padding; `0x0059dbe3-0x0059dc20` is `OnControlCommand` switch-table data plus padding; `0x0059dc20-0x0059de4a` is real no-route local send helper code that mirrors local-player hunters-list/source text state and builds outbound opcode `0x84`; `0x0059e9b0`/`0x0059e9d0` are no-route local sort wrappers around comparators `0x0059e950`/`0x0059e990`; and `0x0059e9f0` is the directly called source-text bucket synchronization helper.
```

### [UID:0000FO] `by-class/UserListPane.md`

Add support note; no required score change:

```markdown
2026-06-18 B001 support update from [UID:0000FN]: `UserListPane` rows are packed `UserListRecord` entries of size `0x414`. Drawing uses `huntersListFlag` at `+0x20e` for the hunters-list marker, `statusIconId` at `+0x0c` for the star/status icon, `badgeIconId` at `+0x03` plus `bucketIndex` at `+0x01` for the secondary badge, `displayColor` at `+0x04`, UTF-16 `name[256]` at `+0x0e`, `hasSourceText` at `+0x20f`, and UTF-16 `sourceText[256]` at `+0x210`. Double-click posts cached source text through `AddUserListSourceMessage` when `hasSourceText` is set, otherwise sends outbound opcode `0x85` with the selected name to request the source text.
```

### [UID:0000A7] `by-class/PartySearchEditPane.md`

Add support note; no required score change:

```markdown
2026-06-18 B001 support update from [UID:0000FN]: the literal `Put me on the hunters list` and opcode `0x84` submit path establish that `UserListRecord +0x20e` and `g_pPlayerData+0x3cb1` are hunters-list/party-search listed state. This contradicts the old `g_bShowHiddenUsers` interpretation for the dialog filter byte at `0x0069bed0`.
```

### [UID:0002A7] `by-memory/0x0069bed0-0x0069bed4.UserListDialogShowHiddenFlag.md`

Recommended rename:

- Rename file/title to `by-memory/0x0069bed0-0x0069bed4.UserListDialogHuntersListOnlyFlag.md`.
- Keep UID `0002A7`.
- Change `COMPLETION` from `86` to `88`.
- Change `CONFIDENCE` from `88` to `90`.
- Keep `CANONICAL_OWNER:0002ZX`.
- Keep `EMITTER_UIDS:0002ZX`.

Replacement summary text:

```markdown
The byte at `0x0069bed0` is the `UserListDialogPane` hunters-list-only filter flag, best source-facing name `g_bShowHuntersListOnly` / `g_bUserListHuntersOnly`. Constructor and refresh paths test the byte; when it is `1`, they skip records whose `UserListRecord::huntersListFlag` at `+0x20e` is zero. `PartySearchEditPane`'s `"Put me on the hunters list"` literal, packet opcode `0x83`, and local-player state at `g_pPlayerData+0x3cb1` establish the flag as hunters-list/party-search filtering. The old `ShowHiddenFlag`/`g_bShowHiddenUsers` name is stale and contradicted by current evidence. The exact storage remains a four-byte slot with only the first byte semantically proven.
```

### [UID:0002ZX] `by-global/g_bShowHiddenUsers.md`

Recommended rename:

- Rename page/title to `by-global/g_bShowHuntersListOnly.md`.
- Keep UID `0002ZX`.
- Change `COMPLETION` from `86` to `88`.
- Change `CONFIDENCE` from `88` to `90`.
- Keep owner/emitter `0000OZ`.

Replacement summary text:

```markdown
`g_bShowHuntersListOnly` is the inferred source-facing module-scope boolean for [UID:0002A7] `0x0069bed0`. It belongs to `UserListDialogPane.cpp` and filters the visible user-list rows to entries whose packed `UserListRecord::huntersListFlag` at `+0x20e` is nonzero. The earlier `g_bShowHiddenUsers` name should not be used as final source naming; no current branch or UI string supports hidden-user semantics.
```

### [UID:0001SO] `by-type/by-enum/MapServerPacketOpcode.md`

Replace opcode `0x36` row:

```markdown
| 0x36 | user-list dialog packet | Server label table entry is `kServerUserList` at `0x00626a9c`; `MapPane` and `UserPane` dispatch paths lazily create `UserListDialogPane` with the packet payload when `g_pUserListDialogPane` is null. |
```

## Coverage Report Replacement Text

Do not edit coverage files directly in this B001 pass. These are supervisor-owned replacements.

### `by-class/-coverage-report.md`

Replace [UID:0000FN] row:

```markdown
- [UID:0000FN][UserListDialogPane](by-class/UserListDialogPane.md) : reconstructable : 88% : strong : Social user-list dialog class with file-parent attachment, exact vtable lead-in child [UID:0003E6][0x0062e8fc-0x0062e998.UserListDialogPaneVtableData](by-memory/0x0062e8fc-0x0062e998.UserListDialogPaneVtableData.md), packed `0x414` `UserListRecord` layout, constructor packet fields, opcode `0x83` hunters-list flag update, opcode `0x84` source-text update, corrected status/name sort helper names, singleton/filter globals, local UserListPane/PartySearch ownership, and class-level first-draft C++ declaration ready.
```

Optional support-only replacement for [UID:0000FO] if supervisor wants the row-layout evidence reflected:

```markdown
- [UID:0000FO][UserListPane](by-class/UserListPane.md) : reconstructable : 85% : strong : Repeated user-list widget with exact vtable child [UID:0003E8][0x0062eadc-0x0062eb9c.UserListPaneVtableData](by-memory/0x0062eadc-0x0062eb9c.UserListPaneVtableData.md); constructor/destructor, draw, selection, direct-message, double-click behavior, `0x414` `UserListRecord` row layout, hunters-list marker, cached source-text state, and local dialog ownership documented.
```

### `by-file/-coverage-report.md`

Replace [UID:0000OZ] row:

```markdown
- [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md) : reconstructable : 88% : strong : Social user-list source family with `UserListDialogPane`, `UserListPane`, and `PartySearchEditPane` local classes; `g_pUserListDialogPane` singleton; corrected `g_bShowHuntersListOnly` filter state; packed `0x414` record layout; source-message, source-text sync, comparator, sort, and packet helper names; IDA/raw-backed executable and read-only data evidence; checkbox-control split caveat retained.
```

### `by-memory/-coverage-report.md`

Replace [UID:0001KI] row:

```markdown
    - [UID:0001KI][0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane](by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md) 0x0059bc90-0x0059f25b | class | UserListDialogPaneAndUserListPane : reconstructable : 87% : strong : Social user-list executable aggregate with `UserListDialogPane`, `UserListPane`, `PartySearchEditPane`, packed `0x414` user records, constructor packet parser, opcode `0x83` hunters-list flag handling, opcode `0x84` source-text handling, opcode `0x85` source-text request support, corrected status/name comparators, source-message helper, source-text bucket sync helper, destructor cleanup, switch-table/padding taxonomy, retained no-route send/sort helpers, checkbox-control interleaves, read-only data caveats, and broad-aggregate no-code proof documented.
```

Replace [UID:0002A7] row after supervisor rename or keep link filename unchanged if renaming is deferred:

```markdown
    - [UID:0002A7][0x0069bed0-0x0069bed4.UserListDialogHuntersListOnlyFlag](by-memory/0x0069bed0-0x0069bed4.UserListDialogHuntersListOnlyFlag.md) 0x0069bed0-0x0069bed4 | global-data flag | UserListDialogHuntersListOnlyFlag : reconstructable : 88% : very-strong : UserListDialogPane hunters-list-only filter byte assigned to [UID:0002ZX][g_bShowHuntersListOnly](by-global/g_bShowHuntersListOnly.md); constructor and refresh paths include only rows whose `UserListRecord::huntersListFlag` at `+0x20e` is nonzero when the byte is set, and `PartySearchEditPane`/opcode `0x83` evidence ties that row flag to the `"Put me on the hunters list"` UI state. Older show-hidden-users wording is stale; trailing bytes remain retained in the exact four-byte slot.
```

No replacement needed for [UID:0002WD]; the singleton row is already accurate.

### `by-global/-coverage-report.md`

Replace [UID:0002ZX] row after supervisor rename or keep link filename unchanged if renaming is deferred:

```markdown
- [UID:0002ZX][g_bShowHuntersListOnly](by-global/g_bShowHuntersListOnly.md) : reconstructable : 88% : very-strong : UserListDialogPane module-scope hunters-list-only filter backed by [UID:0002A7][0x0069bed0-0x0069bed4.UserListDialogHuntersListOnlyFlag](by-memory/0x0069bed0-0x0069bed4.UserListDialogHuntersListOnlyFlag.md); constructor and refresh paths skip rows whose `UserListRecord::huntersListFlag` at `+0x20e` is zero when this byte is set, with `PartySearchEditPane` and opcode `0x83` confirming hunters-list/party-search semantics. The previous `g_bShowHiddenUsers` name is stale.
```

No replacement needed for [UID:0003EI]; the `g_pUserListDialogPane` singleton row is accurate.

## Changed Files

- Created this report only: `source-3/project-documentation/tools/leaser/Agents/Agent-B001/research/0000FN-UserListDialogPane-class-source-quality.md`.

No by-* docs, generated reports/source, IDA DB, or `by-memory/-coverage-report.md` were edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0000FN-UserListDialogPane-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:17","uid":"0000FN"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
