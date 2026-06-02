*** UID:0000L1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# MainUiGraph

## Status

- Confidence: strong for `InitializeMainUiGraph` boundary and runtime role; medium for final original source filename.
- Proposed module folder: `ui/`
- Proposed source file: `ui/MainUiGraph.cpp`
- Current generated source: `simroot_v2/recovered/InitializeMainUiGraph_004F7D10.cpp`
- Evidence basis: `simroot_v2` generated output, Wave2 notes in `by-memory/-report.md`, and targeted IDA MCP checks on 2026-05-24.

## Hypothesis

`MainUiGraph.cpp` should own the post-login in-game UI bootstrap centered on `InitializeMainUiGraph`. This is the handoff point after successful login: it receives the main UI graph object or bootstrap owner, builds the in-game pane tree for the newer and older layouts, loads profile/UI state, touches the [UID:0000HR][BlackHole](by-file/BlackHole.md) deferred-deletion queue, retargets input, and marks the application as ready for the live game UI.

Keep this out of [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md). The only executable caller is the successful-login path, but the function builds the persistent game UI and touches map, chat, status, user, input, profile, and application-ready state.

## Proposed Contents

| Entity | Current range/global | Current evidence | Role |
| --- | --- | --- | --- |
| [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md) | `0x004f7d10-0x004f8b2a` | `recovered/InitializeMainUiGraph_004F7D10.cpp` | Builds the post-login main UI pane tree and finalizes ready/input/profile state. |
| [UID:0000RF][g_pMainUiGraph](by-global/g_pMainUiGraph.md) | `dword_67ABA4` / `0x0067aba4` | caller loads this global into `ecx` before `0x004f7d10` | Global root object used by login dialogs and in-game UI graph attachment. |
| [UID:0000T6][MainUiLayerSlots](by-global/MainUiLayerSlots.md) | `dword_69B364`, `dword_69B368`, `dword_69B36C`, `dword_69B374`, `dword_69B378`, `dword_69B37C` | startup at `0x004f5fb0`, UI setup at `0x004f7d10`, shutdown at `0x004f6490` | Shared layer/context pointers passed through pane setup. `dword_69B364` is the backing storage for stale generated alias `g_pScreenEffecterList`. |
| layout selector | [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / `byte_66DA97` | IDA data refs in `0x004f7d10` | Selects newer EPF/current layout versus older/legacy layout. |
| map tile dimensions | [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md) / `word_66DA9C`, `word_66DAA0` | IDA data refs in `0x004f7d10` | `48x48` map tile pixel span used to build current and legacy playfield bounds before `MapPane` construction. |
| frame resource pointers | `off_61E100`, `off_61E114` | passed into `BackPane::BackPane` | Different root frame resources for the two layout branches; filenames still need decoding. |

## Layout Branches

The newer layout branch constructs [UID:0000HO][BackPane](by-file/BackPane.md) as the root backdrop, [UID:0000L3][MapPane](by-file/MapPane.md) as the playfield, then chat background/display/resize panes, general-purpose panels, [UID:0000L2][MapNamePane](by-file/MapNamePane.md), [UID:00008B][MiniMapButtonPane](by-class/MiniMapButtonPane.md), [UID:0000OF][TabPane](by-file/TabPane.md), [UID:0000JX][HourPane](by-file/HourPane.md), chat variety/handle panes, [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md), [UID:0000NX][SoundStatusPane](by-file/SoundStatusPane.md), and [UID:0000P1][UserPane](by-file/UserPane.md).

The older layout branch constructs [UID:0000HO][BackPane](by-file/BackPane.md), [UID:0000L3][MapPane](by-file/MapPane.md), [UID:0000L2][MapNamePane](by-file/MapNamePane.md), [UID:0000JZ][IconsPane](by-file/IconsPane.md), [UID:0000JX][HourPane](by-file/HourPane.md), [UID:0000IF][ConnStatusPane](by-file/ConnStatusPane.md), [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md), [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md) through `OldUserStatusPane`, [UID:0000NX][SoundStatusPane](by-file/SoundStatusPane.md), and [UID:0000P1][UserPane](by-file/UserPane.md). It also creates the legacy [UID:00006O][InterfaceEfxMgr](by-class/InterfaceEfxMgr.md) after common registration.

The common tail calls [UID:0000MS][ProfileStorage](by-file/ProfileStorage.md) through `LoadUserProfileData`, refreshes screen/root-side state, calls the [UID:0000HR][BlackHole](by-file/BlackHole.md) pane/object deferred-deletion helper at `0x004f8a9a`, calls ready hooks, retargets input through [UID:0000K6][InputMan](by-file/InputMan.md), arms a `3000` ms delayed path, and sets the application main-UI-ready flag. The exact lifetime meaning of the `BlackHole` call needs a focused owner review before naming the `this` object as a permanent graph root.

## Boundary Notes

- IDA `lookup_funcs` confirms `sub_4F7D10` size `0xe1b`, ending at `0x004f8b2a`; `0x004f8b30` starts `EnsureLoginDialogPane_4F8B30`.
- IDA `callers` and `xrefs_to` confirm the sole executable caller at `0x004fac9b` inside `LoginDialogPane::OnServerMessage`.
- The caller executes `mov ecx, dword_67ABA4` before the call, matching the `g_pMainUiGraph` root-object interpretation.
- The recovered `CreatePane`, `InitializePane`, `CallOptionalReadyHook`, and `NotifyLoginNameIfNeeded` helpers are generated source conveniences over repeated allocation, virtual slot, and conversion sequences. Do not promote them to original standalone functions without separate IDA evidence.
- `MainUiGraph` has enough structure evidence for the login-name cache consumed by status panes and user-name helpers, but its full class/struct layout is still provisional.

## Source Placement

Use `ui/MainUiGraph.cpp` as the current source-layout hypothesis. `app/Application.cpp` should keep process/application lifecycle logic, and `login/LoginDialogPane.cpp` should keep login-result handling. `MainUiGraph.cpp` is the bridge that constructs the live game UI once authentication succeeds.

## Cross-References

- [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md)
- [UID:00019K][0x004f7d10-0x004f8b2a.InitializeMainUiGraph](by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md)
- [UID:0000RF][g_pMainUiGraph](by-global/g_pMainUiGraph.md)
- [UID:0000T6][MainUiLayerSlots](by-global/MainUiLayerSlots.md)
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md)
- [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md)
- [UID:0000HR][BlackHole](by-file/BlackHole.md)
- [UID:00019I][0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs](by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md)
- [UID:0000K9][InterfaceEfx](by-file/InterfaceEfx.md)
- [UID:0001QQ][client_s5-ui-and-gameworld-rendering](by-meta/client_s5-ui-and-gameworld-rendering.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:80`.
  - Summary/evidence: post-login UI bootstrap role, global/layer state, layout branches, common tail, sole caller, source placement, and key cross-references are documented; confidence is capped by provisional graph/root layout and generated helper naming.
- 2026-06-02: Assigned validator reconstruction path.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank while the page already named `ui/MainUiGraph.cpp` as the working source placement.
  - After: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/"`.
  - Evidence: this page documents `MainUiGraph.cpp` as the live-game UI bootstrap, and [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) already tracks the UI subsystem layout.
