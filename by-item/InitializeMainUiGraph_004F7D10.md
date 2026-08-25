*** UID:0000UV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00019K | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# InitializeMainUiGraph 0x004F7D10

## Status

- Confidence: very strong for boundary, caller, branch split, resources, source-facing tail names, and behavior. This item is a non-emitting alias/index because exact UID00019K now owns and emits the complete method.
- Current address range: IDA half-open `0x004f7d10-0x004f8b2b` (`0x004f8b2a` last covered byte)
- Canonical owner: [UID:00019K][0x004f7d10-0x004f8b2a.InitializeMainUiGraph](by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md)
- Source owner/emitter: [UID:00007O][MainMenuPane](by-class/MainMenuPane.md) through exact UID00019K; this alias emits nothing.
- Source-facing documentation name: `InitializeMainUiGraph` remains accepted.
- Current IDB label state: live MCP session/database `80de0a67` reports `lookup_funcs 0x004f7d10 -> sub_4F7D10`, `lookup_funcs InitializeMainUiGraph -> Not found`, and zero current function/name entity-query hits for `InitializeMainUiGraph`. The 2026-06-16 saved-label note below is historical rename context, not active-session label proof.

## Summary

`InitializeMainUiGraph` indexes the exact source-authored `MainMenuPane::InitializeMainUiGraph()` method. UID00019K contains the complete two-layout implementation; this page retains searchable caller, branch, resource, and historical evidence without duplicating source.

The function is not a `LoginDialogPane` method. Login success is only the trigger.

## Confirmed Caller

IDA MCP confirms one executable caller:

| Call site | Caller | Notes |
| --- | --- | --- |
| `0x004fac9b` | [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md) / `LoginDialogPane::OnServerMessage` | Success path closes/slides the login dialog, loads `dword_67ABA4` into `ecx`, calls `InitializeMainUiGraph`, then persists the remembered account text. |

IDA MCP recheck confirms `sub_4F7D10` starts at `0x004f7d10`, ends half-open at `0x004f8b2b`, has the single caller at `0x004fac9b`, and has 282 direct code-reference sites to 183 unique out-of-body targets. UID0002AF reanalysis resolved the source operation and all 39 direct callees; the broad fan-out is no longer a code blocker.

Live IDA MCP reconfirmed the one-caller relationship and caller-side [UID:0000RF][g_pMainMenuPane](by-global/g_pMainMenuPane.md) receiver load through `dword_67ABA4` at `0x004fac95`.

## Newer Layout Construction

When [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / `byte_66DA97 == 1`, the function builds the newer in-game layout:

| Created entity | Construction/setup site | Notes |
| --- | --- | --- |
| [UID:0000HO][BackPane](by-file/BackPane.md) | `0x004f7d7d` | Root backdrop, using `FRAME.EPF` at `0x0061e100`. |
| [UID:0000L3][MapPane](by-file/MapPane.md) / playfield pane | `0x004f7dfa` | Playfield under the root pane with 17 by 15 map dimensions and [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md) passed through the current `GameServerConfig::InitializeMapPane` attribution. |
| [UID:0000I5][Chatting](by-file/Chatting.md) background/display/resize panes | `0x004f7e89`, `0x004f7efd`, `0x004f7f71` | New chat area, including persisted height update through `0x004f7fd5`. |
| general-purpose panels and frame helpers | `0x004f7ff7`, `0x004f8020`, `0x004f802c` | Allocates panel helpers and calls `BuildAboveFrameBorder`. |
| [UID:00007P][MapNamePane](by-class/MapNamePane.md) | `0x004f8051` | Top-center map name label. |
| [UID:00008B][MiniMapButtonPane](by-class/MiniMapButtonPane.md) | `0x004f80c2` | Newer layout mini-map button. |
| [UID:0000OF][TabPane](by-file/TabPane.md) | `0x004f812d` | Newer layout tab/action strip. |
| [UID:0000JX][HourPane](by-file/HourPane.md) | `0x004f81a0` | Newer layout clock/hour pane. |
| chat variety/handle panes | `0x004f8217`, `0x004f8288` | Chat mode/handle controls. |
| [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md) and `UserStatusPane2` | `0x004f837a`, `0x004f83ea` | Newer status summary and compact meter pane. |
| [UID:0000NX][SoundStatusPane](by-file/SoundStatusPane.md) | constructor call `0x004f8460` | Newer layout immediately precedes the call with `operator new(0x108)`, then calls `SoundStatusPane::SoundStatusPane`. |
| [UID:0000P1][UserPane](by-file/UserPane.md) | `0x004f84ca`, `0x004f84e2` | Avatar/user pane allocation/setup under playfield. |

This branch also calls the user-name helper at `0x005a2d80`, a ready hook through [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) / historical `dword_67A748`, and a multibyte user-name notification through `WideCharToMultiByte` and `0x00575c30`.

## Older Layout Construction

When [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / `byte_66DA97 != 1`, the function builds the older layout:

The accepted ConnStatusPane allocation is exact: `push 0x128` at `0x004f87cc`, followed by the sole call to [UID:000113][0x00494520-0x004949df.ConnStatusPane](by-memory/0x00494520-0x004949df.ConnStatusPane.md) at `0x004f87ec`. No other executable caller targets `0x00494520`; this item owns only the allocation/call site, while ConnStatusPane owns the class and constructor source.

| Created entity | Construction/setup site | Notes |
| --- | --- | --- |
| [UID:0000HO][BackPane](by-file/BackPane.md) | `0x004f8573` | Root backdrop, using `FRAME.EPD` at `0x0061e114`. |
| [UID:0000L3][MapPane](by-file/MapPane.md) / playfield pane | `0x004f85ef` | Legacy playfield bounds with small positive offsets and the same [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md), through the current `GameServerConfig::InitializeMapPane` attribution. |
| frame helpers | `0x004f8670` | Calls `BuildAboveFrameBorder`. |
| [UID:00007P][MapNamePane](by-class/MapNamePane.md) | `0x004f8695` | Legacy map name position. |
| [UID:0000JZ][IconsPane](by-file/IconsPane.md) | `0x004f8706` | Legacy icon strip. |
| [UID:0000JX][HourPane](by-file/HourPane.md) | `0x004f877c` | Legacy clock/hour pane. |
| [UID:0000IF][ConnStatusPane](by-file/ConnStatusPane.md) | allocation `0x004f87cc`; call `0x004f87ec` | Pushes exact size `0x128` and performs the sole call to constructor `0x00494520`; construction belongs to ConnStatusPane, while this page remains a non-emitting caller index. |
| [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md) / `OldSystemMessagePane` | `0x004f8861` | Legacy system-message display. |
| [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md) / `OldUserStatusPane` | `0x004f8951` | Legacy user status panel. |
| [UID:0000NX][SoundStatusPane](by-file/SoundStatusPane.md) | constructor call `0x004f89c7` | Legacy layout independently precedes the call with `operator new(0x108)`, then calls the same `SoundStatusPane::SoundStatusPane`. |
| [UID:0000P1][UserPane](by-file/UserPane.md) | `0x004f8a31`, `0x004f8a49` | Avatar/user pane allocation/setup under playfield. |
| [UID:00006O][InterfaceEfxMgr](by-class/InterfaceEfxMgr.md) | `0x004f8abd` | Created only after the common tail condition confirms old layout. |

## Common Tail

After either branch, the function:

- calls [UID:0000MS][ProfileStorage](by-file/ProfileStorage.md) through `LoadUserProfileData` at `0x004f8a83`;
- refreshes the shared screen/root object through [UID:00039S][0x00557820-0x00557838.ScreenPanePresentationModeFlagSetters](by-memory/0x00557820-0x00557838.ScreenPanePresentationModeFlagSetters.md) after loading [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md);
- calls [UID:0000HR][BlackHole](by-file/BlackHole.md) helper `0x00469180` at `0x004f8a9a` through [UID:0000Q8][g_pApplicationCleanupQueue](by-global/g_pApplicationCleanupQueue.md) / historical `dword_67A74C`; current evidence says this is a pane/object deferred-deletion queue path, not child registration;
- calls an optional ready/presentation hook through [UID:00029D][0x0069ae08-0x0069ae0c.g_pScreenDimmer](by-memory/0x0069ae08-0x0069ae0c.g_pScreenDimmer.md);
- calls [UID:0000K6][InputMan](by-file/InputMan.md) `TrackInputTarget(0, false)` at `0x004f8aee`;
- arms [UID:0003ZI][0x0057b370-0x0057b3ec.SoundManagerRestartMusic](by-memory/0x0057b370-0x0057b3ec.SoundManagerRestartMusic.md) with a `3000` ms delay at `0x004f8afe`;
- writes [UID:000294][0x0067ab1c-0x0067ab20.g_pApplication](by-memory/0x0067ab1c-0x0067ab20.g_pApplication.md) byte `+0x840` to `1`, best documented as `g_pApplication->m_inMapSession = true` / active map-session state. [UID:0002QH][0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown](by-memory/0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown.md) proves the matching exit-to-menu clear.

## Live IDA Evidence

Checked on 2026-06-04:

- `lookup_funcs` reports `sub_4F7D10` at `0x004f7d10`, size `0xe1b`; the function ends half-open at `0x004f8b2b`, and the next function starts at `0x004f8b30` after five `0xcc` padding bytes.
- `xrefs_to 0x004f7d10` reports one executable caller: `0x004fac9b` inside `sub_4FAB10`.
- Caller context shows `mov ecx, dword_67ABA4` at `0x004fac95` immediately before `call sub_4F7D10`, matching the [UID:0000RF][g_pMainMenuPane](by-global/g_pMainMenuPane.md) receiver handoff.
- Direct code-reference enumeration reports 282 direct code-ref sites to 183 unique out-of-body targets.
- Key live target sites include BackPane construction at `0x004f7d7d` and `0x004f8573`, MapPane setup at `0x004f7dfa` and `0x004f85ef`, frame-border construction at `0x004f802c` and `0x004f8670`, and SoundStatusPane construction at `0x004f8460` and `0x004f89c7`. Both SoundStatusPane branches have their own immediately preceding `operator new(0x108)` sequence, proving the complete `0x108` layout in both UI variants. UserPane setup follows at `0x004f84e2` and `0x004f8a49`; later sites include profile load at `0x004f8a83`, deferred-deletion queue touch at `0x004f8a9a`, input retarget at `0x004f8aee`, and old-layout InterfaceEfxMgr construction at `0x004f8ad8`.
- Data refs from the body include `byte_66DA97` at `0x004f7d40` and `0x004f8aaf`, `word_66DAA0` at `0x004f7e11` and `0x004f8606`, `word_66DA9C` at `0x004f7e18` and `0x004f860d`, `dword_69B364` at 12 pane-setup push sites, `dword_69B368` at 10 pane-setup push sites, [UID:0000Q8][g_pApplicationCleanupQueue](by-global/g_pApplicationCleanupQueue.md) / historical `dword_67A74C` at `0x004f8a93`, `dword_69AE08` at `0x004f8a9f`, `dword_67AB44` at `0x004f8ae4`, and `dword_67AB1C` at `0x004f8b03`.

Checked again on 2026-06-14 under live IDA MCP session `b001_0002bd`:

- `lookup_funcs` reconfirmed `sub_4F7D10` size `0xe1b` / 3611 bytes and successor `sub_4F8B30` size `0x5d` / 93 bytes (Verified with `int_convert.py`). No function exists at the half-open end `0x004f8b2b`.
- `get_bytes` around `0x004f7d10` shows `0xcc` padding before the function prologue; bytes around `0x004f8b20` show the return tail, five `0xcc` bytes, and then the successor `0x004f8b30` prologue.
- `xrefs_to 0x004f7d10` reports only `0x004fac9b`; `xrefs_to 0x0067aba4` reports the caller load at `0x004fac95`, matching the [UID:0000RF][g_pMainMenuPane](by-global/g_pMainMenuPane.md) receiver handoff.
- Layer/context xref checks reconfirmed dense in-body references to `dword_69B364` at sites including `0x004f7e4f`, `0x004f7ec3`, `0x004f7f37`, `0x004f7fae`, `0x004f8088`, `0x004f80f3`, `0x004f81dd`, `0x004f824e`, `0x004f82c2`, `0x004f8339`, `0x004f8656`, and `0x004f86cc`; and to `dword_69B368` at sites including `0x004f7dbb`, `0x004f8167`, `0x004f83b1`, `0x004f8427`, `0x004f85b0`, `0x004f8743`, `0x004f87b3`, `0x004f889e`, `0x004f8911`, and `0x004f898e`.
- Decompiler review reconfirmed the `byte_66DA97 == 1` newer-layout branch, the old-layout branch, and the common tail that loads profile data, refreshes the shared screen/root object, touches the BlackHole/deferred-deletion queue, retargets input, arms a decimal `3000` ms delayed path, and marks the application state ready.
- The resolved callee inventory includes BackPane, MapPane, Chatting family, frame/border, MapNamePane, MiniMapButton, TabPane, HourPane, UserStatus/UserPane/SoundStatus/Icons/SystemMessage/InterfaceEfxMgr, `WideCharToMultiByte`, profile loading, presentation/deferred deletion, InputMan, and music restart paths. UID00019K records their exact source order and compiler/EH distinctions.

Checked again on 2026-06-16 under live IDA MCP session `b001_0001KM_20260616`:

- `lookup_funcs` still reported `sub_4F7D10` size `0xe1b` before the IDA update, and `analyze_function 0x004f7d10` reconfirmed one caller, `0x004fac9b` inside `sub_4FAB10`.
- The decompiler still shows the `byte_66DA97 == 1` newer-layout branch, the older branch, and the same common tail through profile load, shared root refresh, BlackHole/deferred deletion, input retarget, delayed timer/helper calls, and application-ready state.
- The callee list now includes several previously saved labels, including `MapPaneInitialize`, `ChattingBackPane_Constructor`, `LoadUserProfileData`, `HourPaneConstructor`, `GeneralPurposePanel2Constructor`, `UserStatusPane_Constructor`, and `IconsPaneConstructor`, but also keeps unresolved `sub_*` helpers such as `sub_57B370`, `sub_480AD0`, `sub_588E30`, `sub_5BAB00`, `sub_557820`, and `sub_5BC610`.
- Dry-run rename accepted `sub_4F7D10 -> InitializeMainUiGraph`; C001 applied the function label, saved `NexusTK.exe.i64`, and post-save `lookup_funcs` verified the label at `0x004f7d10` at that time. This is historical rename context; the 2026-06-26 B011 recheck below supersedes any unqualified claim that the active IDB session still exposes that label.

## Historical 2026-06-26 B011 Source-Quality Implementation

- B011 report `00019K-InitializeMainUiGraph-source-quality.md` used live MCP session `80de0a67` and rechecked the current IDB with `lookup_funcs`, `xrefs_to`, `analyze_function`, `get_bytes`, `find_bytes`, `disasm`, and `int_convert.py`.
- Current IDB label-state correction: live MCP session/database `80de0a67` reports `lookup_funcs 0x004f7d10 -> sub_4F7D10`, `lookup_funcs InitializeMainUiGraph -> Not found`, and zero current function/name entity-query hits for `InitializeMainUiGraph`. The item keeps `InitializeMainUiGraph` as the source-facing documentation name because behavior, sole caller, graph-pointer handoff, and owner route still support it, but the active MCP/IDB session does not currently prove the saved IDA label.
- Boundary evidence is unchanged and now expressed consistently: the modeled function is IDA half-open `0x004f7d10-0x004f8b2b`, the last covered byte is `0x004f8b2a`, `0x004f8b2b` is not a function, and the successor at `0x004f8b30` is separated by five `0xcc` padding bytes.
- Historical conclusion: caller evidence was exact, but the then-current `g_pMainUiGraph`/MainUiGraph ownership route is superseded. The receiver is `g_pMainMenuPane`, and UID00019K is owned/emitted by MainMenuPane.
- Previously open raw-name blockers were chased and resolved where evidence allowed: `off_61E100` / `off_61E114` are `FRAME.EPF` / `FRAME.EPD`; `sub_480AD0` is [UID:0002F8][0x00480ad0-0x00480ba3.ChattingModifyHeightPaneSetLineCount](by-memory/0x00480ad0-0x00480ba3.ChattingModifyHeightPaneSetLineCount.md); `sub_557820` is [UID:00039S][0x00557820-0x00557838.ScreenPanePresentationModeFlagSetters](by-memory/0x00557820-0x00557838.ScreenPanePresentationModeFlagSetters.md); `sub_57B370` is [UID:0003ZI][0x0057b370-0x0057b3ec.SoundManagerRestartMusic](by-memory/0x0057b370-0x0057b3ec.SoundManagerRestartMusic.md); `dword_67A7CC` is [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md); `dword_67A74C` is [UID:0000Q8][g_pApplicationCleanupQueue](by-global/g_pApplicationCleanupQueue.md); `unk_69AE08` is [UID:00029D][0x0069ae08-0x0069ae0c.g_pScreenDimmer](by-memory/0x0069ae08-0x0069ae0c.g_pScreenDimmer.md); and `word_66DA9C` / `word_66DAA0` are [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md) / `g_mapTilePixelHeight`.
- The `dword_67AB1C + 0x840` tail byte is no longer a vague application-ready flag in this item. [UID:000294][0x0067ab1c-0x0067ab20.g_pApplication](by-memory/0x0067ab1c-0x0067ab20.g_pApplication.md) establishes the object as `g_pApplication`, and [UID:0002QH][0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown](by-memory/0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown.md) proves the matching teardown clear, so the best current source-facing wording is `g_pApplication->m_inMapSession = true` / active map-session state.
- [UID:0000T6][MainUiLayerSlots](by-global/MainUiLayerSlots.md) provides the current source-facing layer/context names for the `dword_69B36x` slots (`effectPaneLayerContext`, `rootPaneLayerContext`, `overlayPaneLayerContext`, `layoutPaneLayerContext`, `statusPaneLayerContext`, and `fpsOverlayLayerContext`). Their exact declaration shape remains an open source-layout question, but they should replace raw `dword_69B36x` names in this item when describing pane setup.
- Negative route evidence was preserved: current MCP `find_bytes` found no absolute little-endian pointer hits for the target start, last covered byte, half-open end, or successor. The route remains the sole direct login-success call.
- Superseded no-code conclusion: this is a 3,611-byte initializer with two layout branches, a shared tail, 39 direct callees, 139 basic blocks, and SEH cleanup records. UID0002AF resolved those source-shape blockers and installed the complete body in UID00019K; this alias stays blank only to prevent duplicate emission.

## Score Rationale

| Field | Score | Rationale |
| --- | --- | --- |
| Completion | `91` | The alias records exact range, caller, branch construction, common tail, resources, globals, historical label state, and its definitive covered-by relationship to the complete UID00019K source. |
| Confidence | `93` | Binary and source-shape evidence agree that this item is an index for the exact MainMenuPane method. Blank code is deliberate duplicate prevention, not unresolved reconstruction. |

## Data And Naming Caveats

- Helper names such as `CreatePane`, `InitializePane`, `CallOptionalReadyHook`, and `NotifyLoginNameIfNeeded` are local analysis labels over repeated allocation, virtual-slot, and conversion patterns. Do not promote them to original standalone functions without separate IDA evidence.
- `off_61E100` and `off_61E114` are resolved frame-resource string inputs, `FRAME.EPF` and `FRAME.EPD`, documented through [UID:0001R7][backpane-background-resources](by-resource/backpane-background-resources.md).
- The layer/context globals `dword_69B364`, `dword_69B368`, `dword_69B36C`, `dword_69B374`, `dword_69B378`, and `dword_69B37C` are tracked in [UID:0000T6][MainUiLayerSlots](by-global/MainUiLayerSlots.md) with source-facing names. `dword_69B364` has a stale alias at [UID:0000S6][g_pScreenEffecterList](by-global/g_pScreenEffecterList.md), but this item should use the MainUiLayerSlots names while preserving final declaration-shape caveats.
- `word_66DA9C` and `word_66DAA0` are now documented as [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md), not anonymous MainUiGraph locals.
- Historical source-quality investigation: C001/B011 had not yet resolved the method's class route and complete source shape. UID0002AF supersedes those blockers with the emitted UID00019K body.
- Current blank-block proof: this page and UID00019K identify the same exact range/operation. Emitting here would duplicate the class method; `RECONSTRUCTABLE:FALSE`, blank emitter/position/C++, and canonical owner UID00019K are therefore required.

## Cross-References

- [UID:00007O][MainMenuPane](by-class/MainMenuPane.md)
- [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)
- [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md) (support/non-owner)
- [UID:00019K][0x004f7d10-0x004f8b2a.InitializeMainUiGraph](by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md)
- [UID:0000RF][g_pMainMenuPane](by-global/g_pMainMenuPane.md)
- [UID:0000T6][MainUiLayerSlots](by-global/MainUiLayerSlots.md)
- [UID:0000Q8][g_pApplicationCleanupQueue](by-global/g_pApplicationCleanupQueue.md)
- [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md)
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md)
- [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md)
- [UID:0000HR][BlackHole](by-file/BlackHole.md)
- [UID:00019I][0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs](by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md)

## 2026-07-14 HourPane Constructor Routes

- The new-layout route allocates exactly `0xfc` bytes, calls [UID:0004NJ][0x004cee60-0x004ceeaf.HourPaneConstructor](by-memory/0x004cee60-0x004ceeaf.HourPaneConstructor.md) at instruction `0x004f81a0`, applies bounds `(830, 736, 885, 751)`, and attaches the result under the new-layout root/layer.
- The legacy route independently allocates `0xfc`, calls the same constructor at instruction `0x004f877c`, applies bounds `(14, 375, 43, 387)`, and attaches the result under the legacy root/layer.
- This item remains an initializer/caller inventory. It does not own HourPane methods, singleton/frame data, resource literals, or compiler ABI bodies.
- Existing `90/91` metadata, owner/emitter route, blank formal block, broad pane graph inventory, and all unrelated evidence remain unchanged.

## Changes

- 2026-08-22 B003 UID0000IF accepted support callback: preserved `91/93`, owner UID00019K, non-emitting metadata, and all unrelated UI-graph evidence; added exact `push 0x128` at `0x004f87cc`, constructor call `0x004f87ec`, and sole-caller/source-ownership proof.

- 2026-07-14 B002 UID0002AF callback: converted UID0000UV to a `91/93` non-emitting alias/index covered by UID00019K; set owner UID00019K, `RECONSTRUCTABLE:FALSE`, blank emitter/position/formal C++; synchronized the `g_pMainMenuPane` receiver and historicalized the superseded MainUiGraph/no-code route.

- 2026-06-26 B011 current-IDB-label addendum: qualified stale current-label wording from the 2026-06-16 rename. The item keeps `InitializeMainUiGraph` as the source-facing documentation name, but live MCP session/database `80de0a67` currently reports `lookup_funcs 0x004f7d10 -> sub_4F7D10`, `lookup_funcs InitializeMainUiGraph -> Not found`, and zero current function/name entity-query hits for `InitializeMainUiGraph`. Metadata, owner/emitter route, range/caller facts, and formal C++ remain unchanged.

- 2026-06-26 B011 source-quality implementation: raised `87/89` to `90/91`, synchronized [UID:00019K][0x004f7d10-0x004f8b2a.InitializeMainUiGraph](by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md), replaced stale raw resource/global/helper caveats with `FRAME.EPF`, `FRAME.EPD`, `g_pApplication->m_inMapSession = true`, `g_pScreenPane`, `g_pScreenDimmer`, `g_pApplicationCleanupQueue`, `ScreenPane::EnablePresentationMode`, `SoundManager::RestartMusic(3000)`, `ChattingModifyHeightPane::SetLineCount`, and [UID:0000T6][MainUiLayerSlots](by-global/MainUiLayerSlots.md) layer/context names. Preserved exact range/caller/negative evidence and kept C++ blank under the accepted no-code proof.

- 2026-06-07: Replaced the raw `dword_67A74C` cleanup-queue reference with canonical [UID:0000Q8][g_pApplicationCleanupQueue](by-global/g_pApplicationCleanupQueue.md) wording.
  - Before: the common-tail/data-ref evidence described the BlackHole deferred-deletion path through the historical generated global only.
  - After: the page links the resolved application cleanup queue while retaining the historical label and exact data-reference site.
  - Evidence: the generated resolved-name report maps `dword_67A74C` to `g_pApplicationCleanupQueue`, and this page's existing live IDA evidence places the deferred-deletion queue touch at `0x004f8a9a` with the data ref at `0x004f8a93`.

- 2026-06-07: Replaced the raw `dword_67A748` ready-hook reference with canonical [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) wording.
  - Before: the newer-layout branch described the hook target only by the historical generated global name.
  - After: the page links the resolved collection-data global while retaining the historical label for traceability.
  - Evidence: the generated resolved-name report maps `dword_67A748` to `g_pCollectionData`, and the existing live IDA notes keep the hook in the newer-layout post-login UI bootstrap path.

- 2026-05-31: Grading and reconstruction status changed from unevaluated/blank to `70/85` and `RECONSTRUCTABLE:TRUE`.
  - Before: the page body documented the main UI bootstrap, but the validator metadata still showed `0/0` and no reconstruction status.
  - After: the metadata now reflects the researched bootstrap function. Parent UID and C++ remain blank because the fan-out contains many not-yet-final callees and global names, and the source-level body is not ready under the current code-entry gate.
  - Evidence: IDA MCP confirms the function boundary, the sole login-success caller, and the large pane/helper call fan-out matching the documented new/old layout construction tables.
- 2026-06-04: Raised completion/confidence from `70/85` to `78/86` and attached [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md) as the autogen parent.
  - Before: the page had the high-level layout tables but no parent metadata and still carried stale provenance wording.
  - Historical after-state: the page recorded boundary, single caller, the then-current `g_pMainUiGraph` alias, MainUiGraph parent, and blank C++. The alias, parent, and blocker are superseded above.
  - Evidence: live IDA MCP `lookup_funcs`, `xrefs_to`, and `py_eval` on 2026-06-04.
- 2026-06-14: Raised completion/confidence from `78/86` to `86/88`.
  - Before: the item had strong 2026-06-04 evidence but no current IDA refresh, no explicit score rationale, and stale final-code-gate wording.
  - Historical after-state: the page recorded byte boundaries, caller/global xrefs, layer refs, branch/tail shape, and a blank body. UID00019K now emits the complete body.
  - Evidence: live IDA MCP `lookup_funcs`, `xrefs_to`, `callees`, `get_bytes`, and `decompile` on 2026-06-14.

- 2026-06-16 C001 safe IDA refresh: Raised completion/confidence from `86/88` to `87/89`.
  - Before: the page had strong current evidence but IDA still named the entry `sub_4F7D10`.
  - Historical after-state: IDA reconfirmed the caller/branches/tail and C001 saved the label at that time; UID0002AF later resolved the source shape and this alias remains blank only to prevent duplicate emission.
  - Evidence: IDA MCP `lookup_funcs`, `analyze_function`, `rename` dry-run/apply, `idb_save`, and post-save `lookup_funcs` on 2026-06-16.
- 2026-07-14 B005 HourPane support synchronization: linked real constructor UID0004NJ and added exact branch-local allocations, calls, bounds, and attachment context without changing this item's scores, formal block, or broad initializer disposition.
