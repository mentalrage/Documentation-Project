*** UID:0000UV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000L1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# InitializeMainUiGraph 0x004F7D10

## Status

- Confidence: strong for boundary, caller, and high-level behavior.
- Current address range: IDA half-open `0x004f7d10-0x004f8b2b` (`0x004f8b2a` last covered byte)
- Proposed owner file: [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md)
- Autogen parent: [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md)

## Summary

`InitializeMainUiGraph` is the global post-login bootstrap for the live in-game UI. It builds either the newer EPF/high-resolution layout or the older legacy layout, attaches child panes under the root [UID:0000HO][BackPane](by-file/BackPane.md), initializes user/status/chat/map surfaces, loads profile data, calls the [UID:0000HR][BlackHole](by-file/BlackHole.md) deferred-deletion helper, retargets input, starts a delayed timer path, and marks the application state as ready.

The function is not a `LoginDialogPane` method. Login success is only the trigger.

## Confirmed Caller

IDA MCP confirms one executable caller:

| Call site | Caller | Notes |
| --- | --- | --- |
| `0x004fac9b` | [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md) / `LoginDialogPane::OnServerMessage` | Success path closes/slides the login dialog, loads `dword_67ABA4` into `ecx`, calls `InitializeMainUiGraph`, then persists the remembered account text. |

IDA MCP recheck on 2026-06-04 confirms `sub_4F7D10` starts at `0x004f7d10`, ends half-open at `0x004f8b2b`, has the same single caller at `0x004fac9b` inside `sub_4FAB10`, and has 282 direct code-reference sites to 183 unique out-of-body targets. This supports the current broad UI-graph bootstrap interpretation but is still below the final C++ gate because many callees and global state names remain unresolved or only partially named.

## Newer Layout Construction

When [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / `byte_66DA97 == 1`, the function builds the newer in-game layout:

| Created entity | Construction/setup site | Notes |
| --- | --- | --- |
| [UID:0000HO][BackPane](by-file/BackPane.md) | `0x004f7d7d` | Root backdrop, using frame pointer `off_61E100`. |
| [UID:0000L3][MapPane](by-file/MapPane.md) / playfield pane | `0x004f7dfa` | Playfield under the root pane with 17 by 15 map dimensions and [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md) passed through the current `GameServerConfig::InitializeMapPane` attribution. |
| [UID:0000I5][Chatting](by-file/Chatting.md) background/display/resize panes | `0x004f7e89`, `0x004f7efd`, `0x004f7f71` | New chat area, including persisted height update through `0x004f7fd5`. |
| general-purpose panels and frame helpers | `0x004f7ff7`, `0x004f8020`, `0x004f802c` | Allocates panel helpers and calls `BuildAboveFrameBorder`. |
| [UID:00007P][MapNamePane](by-class/MapNamePane.md) | `0x004f8051` | Top-center map name label. |
| [UID:00008B][MiniMapButtonPane](by-class/MiniMapButtonPane.md) | `0x004f80c2` | Newer layout mini-map button. |
| [UID:0000OF][TabPane](by-file/TabPane.md) | `0x004f812d` | Newer layout tab/action strip. |
| [UID:0000JX][HourPane](by-file/HourPane.md) | `0x004f81a0` | Newer layout clock/hour pane. |
| chat variety/handle panes | `0x004f8217`, `0x004f8288` | Chat mode/handle controls. |
| [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md) and `UserStatusPane2` | `0x004f837a`, `0x004f83ea` | Newer status summary and compact meter pane. |
| [UID:0000NX][SoundStatusPane](by-file/SoundStatusPane.md) | `0x004f8460` | Newer layout sound/music HUD status. |
| [UID:0000P1][UserPane](by-file/UserPane.md) | `0x004f84ca`, `0x004f84e2` | Avatar/user pane allocation/setup under playfield. |

This branch also calls the user-name helper at `0x005a2d80`, a ready hook through `dword_67A748`, and a multibyte user-name notification through `WideCharToMultiByte` and `0x00575c30`.

## Older Layout Construction

When [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / `byte_66DA97 != 1`, the function builds the older layout:

| Created entity | Construction/setup site | Notes |
| --- | --- | --- |
| [UID:0000HO][BackPane](by-file/BackPane.md) | `0x004f8573` | Root backdrop, using frame pointer `off_61E114`. |
| [UID:0000L3][MapPane](by-file/MapPane.md) / playfield pane | `0x004f85ef` | Legacy playfield bounds with small positive offsets and the same [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md), through the current `GameServerConfig::InitializeMapPane` attribution. |
| frame helpers | `0x004f8670` | Calls `BuildAboveFrameBorder`. |
| [UID:00007P][MapNamePane](by-class/MapNamePane.md) | `0x004f8695` | Legacy map name position. |
| [UID:0000JZ][IconsPane](by-file/IconsPane.md) | `0x004f8706` | Legacy icon strip. |
| [UID:0000JX][HourPane](by-file/HourPane.md) | `0x004f877c` | Legacy clock/hour pane. |
| [UID:0000IF][ConnStatusPane](by-file/ConnStatusPane.md) | `0x004f87ec` | Legacy connection status pane. |
| [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md) / `OldSystemMessagePane` | `0x004f8861` | Legacy system-message display. |
| [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md) / `OldUserStatusPane` | `0x004f8951` | Legacy user status panel. |
| [UID:0000NX][SoundStatusPane](by-file/SoundStatusPane.md) | `0x004f89c7` | Legacy sound/music HUD status. |
| [UID:0000P1][UserPane](by-file/UserPane.md) | `0x004f8a31`, `0x004f8a49` | Avatar/user pane allocation/setup under playfield. |
| [UID:00006O][InterfaceEfxMgr](by-class/InterfaceEfxMgr.md) | `0x004f8abd` | Created only after the common tail condition confirms old layout. |

## Common Tail

After either branch, the function:

- calls [UID:0000MS][ProfileStorage](by-file/ProfileStorage.md) through `LoadUserProfileData` at `0x004f8a83`;
- refreshes the shared screen/root object through `0x00557820`;
- calls [UID:0000HR][BlackHole](by-file/BlackHole.md) helper `0x00469180` at `0x004f8a9a`; current evidence says this is a pane/object deferred-deletion queue path, not child registration;
- calls an optional ready hook through `dword_69AE08`;
- calls [UID:0000K6][InputMan](by-file/InputMan.md) `TrackInputTarget(0, false)` at `0x004f8aee`;
- arms a `3000` ms delayed path at `0x004f8afe`;
- writes the application main-UI-ready flag through `dword_67AB1C`.

## Live IDA Evidence

Checked on 2026-06-04:

- `lookup_funcs` reports `sub_4F7D10` at `0x004f7d10`, size `0xe1b`; the function ends half-open at `0x004f8b2b`, and the next function starts at `0x004f8b30` after five `0xcc` padding bytes.
- `xrefs_to 0x004f7d10` reports one executable caller: `0x004fac9b` inside `sub_4FAB10`.
- Caller context shows `mov ecx, dword_67ABA4` at `0x004fac95` immediately before `call sub_4F7D10`, matching the [UID:0000RF][g_pMainUiGraph](by-global/g_pMainUiGraph.md) handoff.
- Direct code-reference enumeration reports 282 direct code-ref sites to 183 unique out-of-body targets.
- Key live target sites include BackPane construction at `0x004f7d7d` and `0x004f8573`, MapPane setup at `0x004f7dfa` and `0x004f85ef`, frame-border construction at `0x004f802c` and `0x004f8670`, SoundStatusPane construction at `0x004f8460` and `0x004f89c7`, UserPane setup at `0x004f84e2` and `0x004f8a49`, profile load at `0x004f8a83`, deferred-deletion queue touch at `0x004f8a9a`, input retarget at `0x004f8aee`, and old-layout InterfaceEfxMgr construction at `0x004f8ad8`.
- Data refs from the body include `byte_66DA97` at `0x004f7d40` and `0x004f8aaf`, `word_66DAA0` at `0x004f7e11` and `0x004f8606`, `word_66DA9C` at `0x004f7e18` and `0x004f860d`, `dword_69B364` at 12 pane-setup push sites, `dword_69B368` at 10 pane-setup push sites, `dword_67A74C` at `0x004f8a93`, `dword_69AE08` at `0x004f8a9f`, `dword_67AB44` at `0x004f8ae4`, and `dword_67AB1C` at `0x004f8b03`.

## Data And Naming Caveats

- Helper names such as `CreatePane`, `InitializePane`, `CallOptionalReadyHook`, and `NotifyLoginNameIfNeeded` are local analysis labels over repeated allocation, virtual-slot, and conversion patterns. Do not promote them to original standalone functions without separate IDA evidence.
- `off_61E100` and `off_61E114` are confirmed frame-resource pointer inputs to `BackPane`, but their filenames are not decoded here.
- The layer/context globals `dword_69B364`, `dword_69B368`, `dword_69B36C`, `dword_69B374`, `dword_69B378`, and `dword_69B37C` are tracked in [UID:0000T6][MainUiLayerSlots](by-global/MainUiLayerSlots.md). `dword_69B364` has a stale alias at [UID:0000S6][g_pScreenEffecterList](by-global/g_pScreenEffecterList.md).
- `word_66DA9C` and `word_66DAA0` are now documented as [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md), not anonymous MainUiGraph locals.

## Cross-References

- [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md)
- [UID:00019K][0x004f7d10-0x004f8b2a.InitializeMainUiGraph](by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md)
- [UID:0000RF][g_pMainUiGraph](by-global/g_pMainUiGraph.md)
- [UID:0000T6][MainUiLayerSlots](by-global/MainUiLayerSlots.md)
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md)
- [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md)
- [UID:0000HR][BlackHole](by-file/BlackHole.md)
- [UID:00019I][0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs](by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md)

## Changes

- 2026-05-31: Grading and reconstruction status changed from unevaluated/blank to `70/85` and `RECONSTRUCTABLE:TRUE`.
  - Before: the page body documented the main UI bootstrap, but the validator metadata still showed `0/0` and no reconstruction status.
  - After: the metadata now reflects the researched bootstrap function. Parent UID and C++ remain blank because the fan-out contains many not-yet-final callees and global names, and the source-level body is not ready for the `95+` final-code gate.
  - Evidence: IDA MCP confirms the function boundary, the sole login-success caller, and the large pane/helper call fan-out matching the documented new/old layout construction tables.
- 2026-06-04: Raised completion/confidence from `70/85` to `78/86` and attached [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md) as the autogen parent.
  - Before: the page had the high-level layout tables but no parent metadata and still carried stale provenance wording.
  - After: the page records current live IDA boundary, padding, single caller, caller handoff through `g_pMainUiGraph`, direct-code-ref counts, key constructor/helper call sites, data-ref inventory, and MainUiGraph parent attachment. C++ remains blank because the function's 183 direct targets and unresolved graph/global names keep it below the `95/95` final-code gate.
  - Evidence: live IDA MCP `lookup_funcs`, `xrefs_to`, and `py_eval` on 2026-06-04.
