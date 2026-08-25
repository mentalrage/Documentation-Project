*** UID:0000NO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# ServerSelectPane

## Status

- Confidence: very strong for feature ownership, login placement, complete singleton/pane/list inventories, exact CPP/H routes and source order, both class ABI children, corrected virtual identities, list packet/draw behavior, and broad-range policy; residual uncertainty is original private spelling and static liveness of retained raw list starts.
- Proposed module: `login/ServerSelectPane.cpp`
- Matching declaration route: generated `NexusTK/login/ServerSelectPane.h`, with UID0000S8's sole global forward/extern followed by UID0000D2's complete class declaration.
- Current recovered sources: `class_ServerSelectPane.cpp`, `class_ServerSelectMenuItemList.cpp`, and nearby recovered main-menu cleanup helper.

## File Role

`ServerSelectPane.cpp` owns the pre-login server-selection dialog. It displays the server list using `DLGSERV.EPD` or `DLGSERV.EPF`, remembers the configured server name, lets the user confirm or cancel, writes the selected server name into config/application state, and sends the server-select packet before the login flow continues.

This belongs under `login/` rather than generic dialogs because it is part of the main-menu/login sequence and is closed by `CloseMainMenuDialogSingletons_4F69A0` together with other pre-login panes.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `ServerSelectPane` | `0x00573d20-0x00574496`, singleton clear helper `0x00574750`, thunks `0x0057475b`/`0x00574766`, scalar wrapper `0x00574780-0x005747df`, ABI child [UID:0003D7][0x00624d24-0x00624dc0.ServerSelectPaneVtableData](by-memory/0x00624d24-0x00624dc0.ServerSelectPaneVtableData.md) | Modal server-selection dialog with `ServerSelectDirectory *` constructor input, layout construction, `OnControlCommand`, `UpdateActionButton`, implicit virtual destruction, singleton cleanup, and compiler-generated three-view ABI. |
| `ServerSelectMenuItemList` | raw constructor `0x005744a0`, active methods `0x00574660-0x00574747`, vtable child [UID:0003D9][0x00624dc0-0x00624e84.ServerSelectMenuItemListVtableData](by-memory/0x00624dc0-0x00624e84.ServerSelectMenuItemListVtableData.md) | List-pane row widget for selecting `ServerSelectEntry *` rows, forwarding activation to the owner pane, and drawing `Name : Description` text. |
| Selection helpers | `0x00574510-0x0057465d`, raw helpers `0x00574500`, `0x00574550`, and `0x00574570` | [UID:0000VG][ServerSelectHelpers_574510_5745b0](by-item/ServerSelectHelpers_574510_5745b0.md) applies the chosen server, sends opcode `0x57`, stores selected id/endpoint state, and updates config/application selected-server names. |
| Global singleton | [UID:0000S8][g_pServerSelectPane](by-global/g_pServerSelectPane.md) | Sole externally linked, loader-zeroed active-pane definition at emitter position `0`, with matching H `extern`; exact storage UID0002XN is false/non-emitting physical evidence. Use canonical `g_pServerSelectPane`; older aliases are historical only. |

## Evidence Notes

- IDA MCP confirms `ServerSelectPane::ServerSelectPane` at `0x00573d20-0x00574300`, `OnControlCommand(int,int)` at `0x00574340-0x00574430`, `UpdateActionButton()` at `0x00574440-0x00574496`, singleton clear helper at `0x00574750`, adjustor thunks at `0x0057475b` and `0x00574766`, and scalar deleting wrapper at `0x00574780-0x005747df`.
- IDA MCP confirms `ServerSelectMenuItemList` active methods at `0x00574660-0x0057466a` and `0x00574670-0x00574747`.
- Historical pre-callback observation: IDA MCP did not define a function at the raw `ServerSelectMenuItemList` constructor `0x005744a0`, and the then-generated `ServerSelectPane` constructor built the list inline. Current validator-owned generated source contains the accepted out-of-line `ServerSelectMenuItemList::ServerSelectMenuItemList(ServerSelectPane *owner)` definition; the raw-start modeling caveat remains evidence about the binary, not the current generated source shape.
- IDA MCP confirms real helper functions at `0x00574510-0x0057454d` and `0x005745b0-0x0057465d`; Wave3 currently owns the first as `ChattingColorListPane::ApplySelectedColor`, which is not consistent with server-select caller and data-flow context.
- 2026-05-24 MCP recheck: `xrefs_to 0x00574510` reports only the two `ServerSelectPane::OnControlCommand` branch calls at `0x00574399` and `0x005743db`. Decompilation shows the helper copying the selected server name into the config/current-server buffer before calling `0x005745b0`, which sends the `0x57` select-server packet and records selected endpoint state.
- `xrefs_to 0x0069b4ac` supports [UID:0000S8][g_pServerSelectPane](by-global/g_pServerSelectPane.md): main-menu cleanup/startup, constructor, non-deleting destructor helper, thunk, and scalar deleting destructor all touch the same pointer.
- 2026-06-07 Batch 043 live IDA MCP reconfirmed `g_pServerSelectPane` as a clean four-byte zero-initialized slot with seven lifecycle xrefs, and the split exact memory page [UID:0002XN][0x0069b4ac-0x0069b4b0.g_pServerSelectPane](by-memory/0x0069b4ac-0x0069b4b0.g_pServerSelectPane.md) now isolates the singleton storage from neighboring create-user and transfer-server globals.
- 2026-06-12 A005 Batch267 live IDA MCP reconfirmed [UID:0000D1][ServerSelectMenuItemList](by-class/ServerSelectMenuItemList.md) and exact vtable child [UID:0003D9][0x00624dc0-0x00624e84.ServerSelectMenuItemListVtableData](by-memory/0x00624dc0-0x00624e84.ServerSelectMenuItemListVtableData.md) as login-owned children of this source file: parent constructor/list-building stores reference `0x00624dc4`, `0x00624e4c`, and `0x00624e7c` at `0x00573f0b/0x00573f11/0x00573f1b` and `0x005741c8/0x005741ce/0x005741d8`, raw constructor bytes store the same adjusted views at `0x005744d7/0x005744dd/0x005744e7`, and the target ends at the `0x00624e84` `Select Server` literal before the remaining server-select resource tail.
- 2026-06-22 B013 Rule 26 recheck adds the current source route: the main-menu caller passes `g_pConfig + 0x28db10` to `ServerSelectPane::ServerSelectPane(ServerSelectDirectory *serverDirectory)`, the pane stores the pointer at `this + 0x26c`, and the list rows store `ServerSelectEntry *` pointers whose names/descriptions/endpoint fields drive display, config, and packet behavior.

## Singleton Definition And Header Topology

[UID:0000S8][g_pServerSelectPane](by-global/g_pServerSelectPane.md) is the sole source emitter for the active pane pointer. It emits first in this module:

```cpp
class ServerSelectPane;

ServerSelectPane *g_pServerSelectPane = NULL;
```

The matching header channel emits:

```cpp
class ServerSelectPane;

extern ServerSelectPane *g_pServerSelectPane;
```

- Position `0` places the forward declaration/definition before class and method children without requiring a complete type.
- Main-menu cleanup at `0x004f69fb` and the server-list/create guard at `0x004f70a8` are external consumers, so file-local `static`, function-local storage, and class-static replacement are rejected.
- Exact physical [UID:0002XN][0x0069b4ac-0x0069b4b0.g_pServerSelectPane](by-memory/0x0069b4ac-0x0069b4b0.g_pServerSelectPane.md) remains owner-linked but false/non-emitting with blank CPP/H.
- Mixed physical aggregate UID00029W remains parentless/false/non-emitting; broad executable aggregate UID0001HR remains blank and routes through this file without duplicating the global.

## Loader-Zero Storage And Historical Correction

- Current live IDA reads `00 00 00 00` and dword/global value zero at `0x0069b4ac`.
- Target RVA `0x29b4ac` is `0x2e4ac` bytes into `.data`, beyond raw size `0xd800`. No target initializer bytes exist in the executable; loader zero-fill supplies the null state.
- Historical `0xffffffff` wording is disproved. Preserve it only as correction history, never as present source behavior.
- Current IDA presents four one-byte undefined heads beginning with `unk_69B4AC`, not a clean typed dword. Supervisor Gate 2B should normalize only the exact four-byte range, without touching create-user/transfer neighbors.

## Direct Singleton Cause And Lifetime

MSVC RTTI proves `ServerSelectPane` directly inherits empty `Singleton<ServerSelectPane>`:

- ServerSelectPane type descriptor `0x006791a4` and Singleton type descriptor `0x006791c4`.
- Singleton base descriptor `0x006502e8` has PMD `620/-1/0`, i.e. `+0x26c/-1/0`, attributes `0x40`.
- Existing `DialogPane` is `0x26c` bytes. Empty-base optimization allows the Singleton base address to overlap `m_serverDirectory` at `+0x26c`; complete allocation remains `0x270`.

The seven singleton references are main-menu cleanup/create reads, constructor publication/fallback clear, ordinary destructor clear, constructor-EH clear, and scalar deleting wrapper clear. These are source inheritance/lifetime evidence. Final source must not introduce separate manual registration/clear wrappers merely because the compiler generated those paths.

## Server Directory And State Model

Best current file-local type names:

```cpp
struct ServerSelectEntry {
    unsigned char serverId;
    wchar_t *name;
    wchar_t *description;
    wchar_t *agreementText;
    unsigned char address[4];
    unsigned short port;
};

struct ServerSelectDirectory {
    ServerSelectEntry entries[32];
    int entryCount;
    unsigned char version;
};
```

`ServerSelectPane` owns a `ServerSelectDirectory *m_serverDirectory` at `+0x26c`. The directory is exactly 0x308 bytes: 32 0x18-byte rows, `entryCount` at `+0x300`, and `version` at `+0x304`. Natural x86 alignment supplies gaps before `name` and after `port`; no source-visible reserved members are required. `ServerSelectMenuItemList` stores `ServerSelectPane *m_owner` at `+0x14c` and list rows are pointers to `ServerSelectEntry`, not inline server records.

Config/application state touched by this file:

- `g_pConfig + 0x28db10`: server-select directory block passed to the constructor.
- `g_pConfig + 0x2916d0`: selected/configured server name copied with `_wcscpy_s(..., 0x10, entry->name)`.
- `g_pConfig + 0x28d9d8`: selected server id written after opcode `0x57` packet send.
- `g_pConfig + 0x28d9dd`: endpoint-format skip/preserve flag.
- `g_pConfig + 0x291230`: exact inherited `m_serverEndpointText[64]` destination in `SendServerSelectPacket`, formatted from the prefix, four address octets, and `entry->port`; `m_musicFolderPath` is separate at `+0x29190c`.
- `g_pConfig + 0x2912b0`: first endpoint-format component.
- `g_pApplication + 0x858`: current/selected server display name initialized to `TestServer` and updated by list draw/raw apply paths.

## Source Emission Policy

UID0000S8 emits the one complete global CPP/H route at position `0`. UID0000D2 emits `#include "ServerSelectPane.h"` plus `[[CHILDREN]]` in CPP and the complete period-compatible `ServerSelectPane` declaration in H at position `10`. UID0003D7 emits only the ServerSelectPane compiler-generated ABI marker at position `20`. UID0000D1 emits complete `ServerSelectMenuItemList` authored CPP/H at position `30`, including the full source include graph, its child expansion marker, and exact Socket receiver dispatch `g_packetSender->QueueAndSendPacket(packet, 3)`. UID0003D9 emits only the list-class compiler-generated ABI marker through UID0000D1 at position `40`.

- UID0000D2 H forward-declares and friends `ServerSelectMenuItemList`, permitting the exact owner-activation thunk without a public wrapper or binary state. Its support prose classifies `SendServerSelectPacket` as a private list member, not a file-local helper, because both callers establish the list instance in ECX.
- UID0000D1 H includes `../config/Config.h` and reuses Config's sole complete `ServerSelectEntry` declaration, then declares direct `ListPane` inheritance, complete 0x150 layout, constructor, four nonvirtual methods, two virtual overrides, private packet helper, owner pointer, and size guards. The old consumer-local entry record is superseded because it would collide with the Config owner. UID0000D1 CPP includes complete `Application`, StartupWindow, PacketBuffer, Socket, Surface, and CRT wide-string declarations, and dispatches the three-byte packet through the `g_packetSender` object receiver rather than a free-function-shaped helper.
- UID0000D1 CPP contains one constructor plus seven authored methods. UID0000VG remains a detailed non-duplicating helper index, and UID0001HR remains a mixed broad evidence aggregate with blank formal channels.
- UID0003D7 and UID0003D9 never emit raw locator/vtable/RTTI dwords. Shared deleting wrappers, adjustors, vptr stores, and scalar wrappers remain compiler-generated.

After coherent scoped refresh, generated `ServerSelectPane.cpp` must contain UID0000S8's global definition once; UID0000D2's include/children route and UID0003D7 marker; UID0000D1's seven exact dependency includes and eight authored definitions; UID0003D9's marker in position order; exactly one `g_packetSender->QueueAndSendPacket(packet, 3)` call; and no `QueueAndSendPacket(g_packetSender, packet, 3)` call. Generated `ServerSelectPane.h` must contain UID0000S8's forward/extern once, UID0000D2's complete declaration plus list friendship, exactly one Config-owned `ServerSelectEntry` definition through `Config.h`, and UID0000D1's list declaration once. UID0003D7, UID0000D2, UID0000D1, and UID0003D9 must have no empty-emitter marker. UID0002XN must remain absent. No raw ABI arrays, duplicate entry/class declarations or definitions, partial `Application` declaration, stubs, TODOs, placeholders, or missing complete-type dependency are allowed.

## UID0003D9 Ordinary Dependency Package - 2026-08-15

The accepted UID0003D9 source-quality report separates runtime behavior from declaration visibility. The list implementation already had the exact constructor, selection, packet, activation, and drawing behavior; this ordinary callback completes the owner graph instead of relying on undeclared globals or a precompiled-header assumption. Config owns `ServerSelectEntry`, `Config`, and `g_pConfig`; Application owns the complete `Application` declaration, `g_pApplication`, and `m_currentServerName[256]`; StartupWindow owns `g_useEpfAssets`; PacketBuffer owns `PacketBufferWriteUInt8`; Socket owns `Socket` and `g_packetSender`; Surface owns `RectBounds`, `SurfaceFillRectProc`, and `g_pfnFillRect`; and `<wchar.h>` owns the C wide-string API.

The generated unit must therefore remain ordinary mid-2000s C++: include owner headers, access real source-facing members, and let class declarations regenerate RTTI/vtables. Historical consumer-local `ServerSelectEntry`, forward-only `Application`, raw member-offset access, free-function packet dispatch, guessed PCH dependency, and authored ABI arrays are superseded and must not return.

## ServerSelectPane Declaration And Three-View ABI

- The complete class declaration is `ServerSelectPane : public DialogPane, public Singleton<ServerSelectPane>`, with a `ServerSelectDirectory *m_serverDirectory` member at `+0x26c`. `DialogPane` is `0x26c`, the empty Singleton base PMD is also `+0x26c`, and the complete allocation is `0x270`.
- Exact ABI child [UID:0003D7][0x00624d24-0x00624dc0.ServerSelectPaneVtableData](by-memory/0x00624d24-0x00624dc0.ServerSelectPaneVtableData.md) classifies 156 bytes and 39 cells: a 23-slot primary view, 11-slot `EventHandler` view at `+0xa0`, and two-slot `TimerHandler` view at `+0xa4`.
- The three COLs share ServerSelectPane type descriptor `0x6791a4` and CHD `0x650298`; the eight-base graph closes `DialogPane`, `Pane`, `GrafPort`, `LObject`, `EventHandler`, `TimerHandler`, and direct `Singleton<ServerSelectPane>` ancestry.
- Constructor, ordinary cleanup, and scalar deleting wrapper each write all three heads. Singleton failure cleanup and the two adjusted deleting-destructor entries are compiler lowering; source must not author them or the vptr stores.
- Primary slots `+0x48/+0x4c`, calling convention, base contract, and body behavior support `virtual void OnControlCommand(int controlIndex, int notifyCode);` and `virtual void UpdateActionButton();`. The old `OnDialogAction` and `UpdateScrollButtons` labels are preserved only as rejected historical assumptions.
- No explicit derived destructor is declared. Implicit virtual destruction through the base hierarchy recreates the observed ordinary cleanup/scalar-wrapper family without decompiler-shaped source.

## ServerSelectMenuItemList Source And Three-View ABI Closure

- UID0000D1 is a direct `ListPane` subclass, not `SimpleListPane`. Its eight-base RTTI chain is self, ListPane, ScrollablePane, Pane, GrafPort, LObject, EventHandler, and TimerHandler; inherited handler views are at `+0xa0/+0xa4`.
- Natural layout is the `0x14c` ListPane base plus `ServerSelectPane *m_owner` at `+0x14c`, total `0x150`. Rows are `ServerSelectEntry *` pointers; each 0x18-byte entry contains id, name/description/agreement wide-string pointers, four address bytes, and unsigned-short port.
- Exact authored source inventory is constructor `[0x5744a0,0x5744f8)`, `AddServerEntry` `[0x574500,0x57450e)`, `ApplySelectedServer` `[0x574510,0x57454e)`, `SelectServerEntryIndex` `[0x574550,0x574561)`, `ApplyServerEntry` `[0x574570,0x5745ac)`, private member `SendServerSelectPacket` `[0x5745b0,0x57465e)`, `OnItemActivated` `[0x574660,0x57466b)`, and `DrawListEntry` `[0x574670,0x574748)`.
- The packet helper has two callers and member-this ABI. It emits bytes `0x57,0,id`, dispatches exactly three bytes from a 16-byte local frame through `g_packetSender->QueueAndSendPacket(packet, 3)`, stores selected id, and conditionally formats the six-component endpoint with the four address bytes and signed interpretation of the 16-bit port. The rejected `QueueAndSendPacket(g_packetSender, packet, 3)` spelling would incorrectly model the Socket receiver as a free-function argument.
- Draw behavior uses colors `0x25/0x80`, selected fill, application current-name update, right-edge subtraction by 10 in EPF mode, and a 1024-wide-character `Name : Description` buffer.
- Raw constructor/add/select/apply starts have no modeled function, inbound start xref, rel32 route, or encoded VA/RVA pointer route. Their coherent complete bodies remain authored source through UID0000D1; the negative route proof remains a confidence cap.
- Exact ABI child UID0003D9 covers `[0x624dc0,0x624e84)`, 196 bytes/49 cells, with 33/11/2 slots, three COLs, one eight-base hierarchy, table-store triads, and exact successor `Select Server` boundary. Shared wrapper `0x47e9d0` and adjustors `0x47e881/0x47e88c` are compiler-generated.
- Historical blank list source, static/file-local packet helper, free-function-shaped Socket dispatch, `GetSelectedEntry`, `DrawListItem`, top-edge mutation, and separate helper-emission assumptions are superseded by the accepted exact class source. They remain correction history, not current generated criteria.

## Dated Generated Baseline And Dynamic Authority

- Before the UID0003D9 callback, validator command `000000024083`, refreshed `2026-08-15T06:37:34-04:00`, produced CPP SHA256 `7D4C47053809E326964E61F830FB93665D20DA478F0F0327677CF1577F06DAD4` (1369 bytes, 26 lines) and H SHA256 `9ADFCD73337938A2D52E385E6A3008D87D3FE04FF8D3AEE2E6411910C82F87C7` (1012 bytes, 32 lines). That dated snapshot showed UID0003D9/UID0000D1 empty and is historical evidence only.
- The complete dated UID0003D9 callback/dependency history is preserved below. Every row is a historical observation subordinate to a fresh coherent validator refresh and physical generated reread; no row is permanent generated authority.

| Validator command | Refreshed at | Generated CPP snapshot | Generated H snapshot | Historical disposition |
| --- | --- | --- | --- | --- |
| `000000024212` | `2026-08-15T07:55:26-04:00` | SHA256 `CEB6CCD67B29CCA4C07CE5CA3C43B2100BC0CF65D184713EC3B16EC858AA116F`, 4034 bytes/116 lines | SHA256 `7F7A36B7EAA9BC3A224011AEC4C56F505C2FF5B7D226ADA008CBFBC42E8597FF`, 2274 bytes/77 lines | Initial ordinary callback-time population; dated provenance only. |
| `000000024301` | `2026-08-15T18:26:55-04:00` | SHA256 `2472A57D5EEA458A0825C88CACA9CBFD1C9CBBCCF0C77829C507CBB27E8E97B8`, 4034 bytes/116 lines | SHA256 `5AE48F05D8BA7F7338A5B602E2E6543540FE619DB1436AEBD65CB5102BE792F5`, 2274 bytes/77 lines | Prior accepted snapshot; dated provenance only. |
| `000000024426` | `2026-08-15T19:25:29-04:00` | SHA256 `3C4C798C5BB00D659A4FE624C7D9FC24EE2EC47247B780DD3FB9798A6807D778`, 4034 bytes/116 lines | SHA256 `009687B69C6C0837661F3CB8B9B91A40F0F656E93029FF8840D5F0D03DE7C16F`, 2274 bytes/77 lines | Prior supervisor-observed snapshot; dated provenance only. |
| `000000024441` | `2026-08-15T20:29:30-04:00` | SHA256 `EE6398AAE4501BAE04440F2CD012BD621C59D4CDEA800B23D1BA9287B4B68993`, 4034 bytes/116 lines | SHA256 `B86314644B73FB96EB590EC4DEC857696D56B6A476B8C6DE3D371DF16D418B26`, 2274 bytes/77 lines | Prior supervisor-observed snapshot; dated provenance only. |
| `000000024477` | `2026-08-15T22:21:16-04:00` | SHA256 `31EF87D5419A332ED532AEC134FEA0AC4FCEC439348A1DE795C66F08F27138B1`, 4034 bytes/116 lines | SHA256 `549CFF371B326CEE021E1DB5EFFC7C2735A4E48E2FE9A0B2CC65192A1165B9EE`, 2274 bytes/77 lines | Corrected receiver/helper/topology callback snapshot; dated provenance only. |
| `000000024590` | `2026-08-16T00:08:44-04:00` | SHA256 `08FA62766C8A72F4F0CDF84E322A243CA7264741D958CEEE6CC5AB4F65F0EFC7`, 4220 bytes/124 lines | SHA256 `F5AECA831516D63B462FAFEF1857E02196041A130A8E8EC2A3425E768A5D5306`, 2099 bytes/68 lines | Complete dependency-callback snapshot with Config-owned entry type and complete Application/MSGHandler/include closure; dated provenance only. |

- Generated authority is validator-owned and must be established dynamically from a coherent waited refresh plus physical CPP/H reread. Command IDs and hashes are dated snapshots rather than permanent authority, and generated files are never edited directly.

## Ownership Notes

- Keep the server-select pane near `MainMenuPane` and login/account dialogs. It is not part of in-game popup/menu infrastructure.
- The list pane should migrate with `ServerSelectPane`, not as a generic list control.
- Treat `0x005744a0`, `0x00574500`, `0x00574550`, and `0x00574570` as raw source-shaped helpers with no direct start route yet. Use canonical `g_pServerSelectPane` for the singleton; the old alias split is resolved as stale documentation wording, not a separate source variable.
- Do not place the singleton definition in MainMenuPane, Application, a generic dialog module, UID00029W, or UID0001HR. Those are consumers, broad containers, or mixed physical indexes.
- Do not emit `unk_69B4AC`/`dword_69B4AC`, `0xffffffff`, duplicate globals, covered-by placeholder code, smart pointers, or decompiler-shaped registration helpers.

## Score Rationale

- Completion `91`: the file page covers class/list/helper/global contents, exact global and both class CPP/H text/order, external linkage, loader-zero storage, Singleton RTTI/EBO/lifecycle, complete ServerSelectPane and ServerSelectMenuItemList three-view ABI families, corrected virtual identities, compiler/source splits, directory/entry/packet/draw behavior, generated acceptance criteria, independent evidence pages, and rejected owner/source alternatives.
- Confidence `94`: live IDA, PE mapping, all 39 ServerSelectPane ABI cells, all 49 ServerSelectMenuItemList ABI cells, RTTI/COL/PMD records, lifecycle and constructor stores, exact class/helper ranges/hashes, and login source-tree context agree. Remaining limits are original private spelling and raw list-start reachability, not source placement, declaration completeness, or emitter ownership.

## Cross-References

- [UID:0000D2][ServerSelectPane](by-class/ServerSelectPane.md)
- [UID:0000D1][ServerSelectMenuItemList](by-class/ServerSelectMenuItemList.md)
- [UID:0001HR][0x00573d20-0x005747df.ServerSelectPane](by-memory/0x00573d20-0x005747df.ServerSelectPane.md)
- [UID:0000VG][ServerSelectHelpers_574510_5745b0](by-item/ServerSelectHelpers_574510_5745b0.md)
- [UID:0000S8][g_pServerSelectPane](by-global/g_pServerSelectPane.md)
- [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)
- [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md)

## Changes

- 2026-08-15 B010 UID0003D9 accepted implementation callback:
  - File score/path `91/94`, `NexusTK/login/` source root, and by-file ownership remain unchanged.
  - Added complete UID0000D1 CPP/H at position 30, UID0003D9 marker at position 40, UID0000D2 friendship support, all list authored ranges/behavior, exact 49-cell ABI cause, raw-start/compiler disposition, source order, and current generated acceptance criteria.
  - Preserved command `000000024083` hashes as a dated pre-callback snapshot while making waited validator output the dynamic generated authority.

- 2026-08-10 B010 UID0002PA accepted implementation callback:
  - File score/path, source inventory, ownership, singleton route, and blank by-file formal policy remain unchanged.
  - Removed active `reserved0c`/`portOrEndpointSuffix` and explicit-padding placeholders. The complete dependency model now uses owned `agreementText`, unsigned-short `port`, directory `version`, and natural alignment.
  - Historical reserved arrays, signed port/suffix, missing agreement/version, and endpoint/music conflict assumptions remain preserved in dated history as superseded source models.

- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `84` and confidence to `80`.
  - Evidence: document covers login feature role, proposed contents, IDA method boundaries, helper/data-boundary caveats, singleton alias evidence, ownership notes, and cross-references; confidence remains limited by projected list constructor and helper ownership cleanup.
- 2026-06-01: Added projected path `NexusTK/login/`.
  - Before: the page text proposed `login/ServerSelectPane.cpp`, but validator metadata had no projected path.
  - After: `PROPOSED_RECONSTRUCTION_PATH` is `NexusTK/login/`.
  - Evidence: source-tree docs already place `ServerSelectPane.cpp` under `login/`, and live IDA MCP reconfirmed the constructor caller, main-menu singleton xrefs, dialog resources, and selected-server helpers as pre-login/login code.
- 2026-06-07 Batch 043 parent-gate refresh:
  - Before: `84/80`; helper-boundary and alias caveats kept the file below the stricter parent gate.
  - After: `85/86`.
  - Evidence: the exact singleton storage is now split and live-reconfirmed, while the existing method, list-pane, helper, resource, and login/startup evidence supports `NexusTK/login/ServerSelectPane.cpp` as the source owner. Remaining helper cleanup still blocks final C++, not parent routing.
- 2026-06-12 A005 Batch267 list-vtable parent repair:
  - Before: `85/86`; the file page owned `ServerSelectMenuItemList` but did not carry the exact [UID:0003D9][0x00624dc0-0x00624e84.ServerSelectMenuItemListVtableData](by-memory/0x00624dc0-0x00624e84.ServerSelectMenuItemListVtableData.md) routing evidence needed by the class parent.
  - After: `86/87`, retaining `NexusTK/login/`.
  - Evidence: live IDA reconfirmed the list-class vtable child, all three parent constructor/list-building/raw-constructor vtable stores, selected-row virtual slots, the `Select Server` string boundary, and direct class/file ownership under the login server-select module.
- 2026-06-22 B013 Rule 26 support sync:
  - Score unchanged at `86/87`.
  - Incorporated `ServerSelectDirectory`/`ServerSelectEntry` layout, constructor argument route, canonical `g_pServerSelectPane` wording, selected config/application state fields, opcode `0x57` packet ownership, raw-helper no-route policy, and the file/child-level source-emission policy for future C++.
- 2026-07-26 B005 UID0002XN implementation callback:
  - Raised `86/87` to `89/91`, preserved `NexusTK/login/`, and added UID0000S8's sole position-0 global CPP/H route.
  - Incorporated loader-zero PE proof, direct `Singleton<ServerSelectPane>` RTTI/PMD/EBO cause, complete seven-reference lifecycle, physical UID0002XN false/non-emitting route, exact generated CPP/H expectations, remaining independent emitter caveats, rejected alternatives, and score rationale without pruning B013 directory/list/helper/packet evidence.

## 2026-07-15 UID0003UP Server-Endpoint Synchronization

- File score, path, source inventory, blank by-file formal policy, ownership, and complete server-selection detail remain unchanged.
- ServerSelect source consumes inherited Config `m_serverEndpointText[64]` at `+0x291230`, retaining exact prefix/address/port formatting. ANSI login address/startup fields and `m_musicFolderPath` at `+0x29190c` remain separate source concepts.
- Historical MP3-at-endpoint wording is superseded. No generated/manual file or additional C++ destination is created.
