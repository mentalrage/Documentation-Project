*** UID:0000L1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# MainUiGraph

## IME-Layer Header Export - 2026-08-24

`NexusTK/ui/MainUiGraph.h` exposes `class Layer;` and `extern Layer *g_pIMEPaneLayer;` through semantic owner [UID:0004VG][g_pIMEPaneLayer](by-global/g_pIMEPaneLayer.md). `MainUiGraph.cpp` retains the sole zero-initialized definition at source position `60`, backed by the non-emitting `0x0069b37c` physical storage. [UID:0000JK][FpsPane](by-file/FpsPane.md) is a header consumer for its diagnostic pane's frame-parent attachment only; it does not own, rename, or duplicate the IME-layer global.

## Status-Layer Header Export - 2026-08-16

`NexusTK/ui/MainUiGraph.h` now exposes `extern Layer *g_pStatusPaneLayer;` through semantic owner [UID:0004VF][g_pStatusPaneLayer](by-global/g_pStatusPaneLayer.md). `MainUiGraph.cpp` retains the sole zero-initialized definition at source position `50`, backed by non-emitting [UID:0004VH][0x0069b378-0x0069b37c.g_pStatusPaneLayerStorage](by-memory/0x0069b378-0x0069b37c.g_pStatusPaneLayerStorage.md). [UID:0001A1][0x004ffd80-0x0050008b.HistoryViewingPaneCore](by-memory/0x004ffd80-0x0050008b.HistoryViewingPaneCore.md) is a header consumer only; it does not own or duplicate the global.

## UID0000KA Layer-Slot Consumer - 2026-08-15

`NexusTK/ui/inventory/InventoryPane.cpp` includes `../MainUiGraph.h` and consumes the existing `MainUiLayerSlots` declaration, `g_mainUiLayerSlots` extern, and `rootPaneLayerContext` member only as the `InterfaceEfx` constructor's layer argument. MainUiGraph retains the global definition and lifecycle ownership; Application/BaramApp remains a startup/shutdown consumer. No layer storage or initialization moves to UID0000KA, and scores are unchanged.

## 2026-08-14 B003 ChangePassword Dependency Incorporation

- UID0000T6 now emits guarded `MainUiGraph.h` with a Layer forward, exact three-pointer `MainUiLayerSlots`, and extern, plus `MainUiGraph.cpp` include and `{ NULL, NULL, NULL }` definition.
- ChangePasswordDialogPane uses only the overlay member. The effect/root slots, neighboring globals, and broader main-UI graph remain owned here; file score stays `90/92`.

## Status

- Confidence: very strong for graph-layer support, resources, the provisional head triplet, three independently defined Layer globals, layout selector, and map dimensions. This file no longer owns or emits the concrete MainMenuPane singleton or `InitializeMainUiGraph` method.
- Proposed module folder: `ui/`
- Proposed source file: `ui/MainUiGraph.cpp`
- Current source disposition: support-only for the graph-layer declarations and globals retained below; historical generated-output routes are provenance only.
- Evidence basis: `simroot_v2` generated output, Wave2 notes in `by-memory/-report.md`, and targeted IDA MCP checks on 2026-05-24.
- Latest evidence basis: targeted IDA MCP checks on 2026-06-07 for the initializer boundary, sole caller, root pointer, layer slots, layout selector, and map tile dimension refs, plus B011 MCP session `80de0a67` on 2026-06-26 for frame resources, common-tail helper/global names, active map-session state, and pointer-route negatives. Earlier generated-output references remain provenance only and are not the scoring basis for this refresh.

## Hypothesis

`MainUiGraph.cpp` remains a support file for shared layer slots, layout selection, and map-dimension state used by post-login UI construction. [UID:00019K][0x004f7d10-0x004f8b2a.InitializeMainUiGraph](by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md) now owns and emits the complete method through [UID:00007O][MainMenuPane](by-class/MainMenuPane.md), and [UID:0000RF][g_pMainMenuPane](by-global/g_pMainMenuPane.md) is defined in `MainMenuPane.cpp`.

Keep this out of [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md). The only executable caller is the successful-login path, but the function builds the persistent game UI and touches map, chat, status, user, input, profile, and application-ready state.

## Proposed Contents

| Entity | Current range/global | Current evidence | Role |
| --- | --- | --- | --- |
| [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md) | IDA half-open `0x004f7d10-0x004f8b2b` (`0x004f8b2a` last byte) | non-emitting alias/index for UID00019K | Cross-reference only; no body or ownership here. |
| [UID:0000RF][g_pMainMenuPane](by-global/g_pMainMenuPane.md) | `dword_67ABA4` / `0x0067aba4` | caller loads this concrete singleton into `ecx` before `0x004f7d10` | `MainMenuPane *` definition owned/emitted by MainMenuPane.cpp, not this file. |
| [UID:0000T6][MainUiLayerSlots](by-global/MainUiLayerSlots.md) | provisional `effectPaneLayerContext`, `rootPaneLayerContext`, `overlayPaneLayerContext` at `0x0069b364/368/36c` | startup at `0x004f5fb0`, UI setup at `0x004f7d10`, shutdown at `0x004f6490` | Retained head-triplet support only; its final declaration shape remains open. |
| [UID:0004VE][g_pLayoutPaneLayer](by-global/g_pLayoutPaneLayer.md) | independent `Layer *` at `0x0069b374`, source position 40 | 13 refs across lifecycle, Browser, alert, and dialog layout | Sole zero-initialized definition in `MainUiGraph.cpp`; shared-header `extern` declaration is separate. |
| [UID:0004VF][g_pStatusPaneLayer](by-global/g_pStatusPaneLayer.md) | independent `Layer *` at `0x0069b378`, source position 50 | 14 refs across lifecycle, Help, History, dim/fade, Timer, and InputBlocker | Sole zero-initialized definition in `MainUiGraph.cpp`; physical backing is non-emitting. |
| [UID:0004VG][g_pIMEPaneLayer](by-global/g_pIMEPaneLayer.md) | independent `Layer *` at `0x0069b37c`, source position 60 | 11 refs across lifecycle, three IME constructors, root inline equivalents, and incidental FPS use | Sole zero-initialized definition in `MainUiGraph.cpp`; FpsPane does not own or rename it. |
| layout selector | [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97` | IDA data refs in `0x004f7d10` | Selects newer EPF/current layout versus older/legacy layout. |
| map tile dimensions | [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md) / `word_66DA9C`, `word_66DAA0` | IDA data refs in `0x004f7d10` | `48x48` map tile pixel span used to build current and legacy playfield bounds before `MapPane` construction. |
| frame resource strings | `FRAME.EPF` at `0x0061e100`, `FRAME.EPD` at `0x0061e114` | passed into `BackPane::BackPane`; xrefs `0x004f7d76` and `0x004f856c`; [UID:0001R7][backpane-background-resources](by-resource/backpane-background-resources.md) | Different root frame resources for the two layout branches. |

## Layout Branches

The newer layout branch constructs [UID:0000HO][BackPane](by-file/BackPane.md) as the root backdrop, [UID:0000L3][MapPane](by-file/MapPane.md) as the playfield, then chat background/display/resize panes, general-purpose panels, [UID:0000L2][MapNamePane](by-file/MapNamePane.md), [UID:00008B][MiniMapButtonPane](by-class/MiniMapButtonPane.md), [UID:0000OF][TabPane](by-file/TabPane.md), [UID:0000JX][HourPane](by-file/HourPane.md), chat variety/handle panes, [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md), [UID:0000NX][SoundStatusPane](by-file/SoundStatusPane.md), and [UID:0000P1][UserPane](by-file/UserPane.md).

The older layout branch constructs [UID:0000HO][BackPane](by-file/BackPane.md), [UID:0000L3][MapPane](by-file/MapPane.md), [UID:0000L2][MapNamePane](by-file/MapNamePane.md), [UID:0000JZ][IconsPane](by-file/IconsPane.md), [UID:0000JX][HourPane](by-file/HourPane.md), [UID:0000IF][ConnStatusPane](by-file/ConnStatusPane.md), [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md), [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md) through `OldUserStatusPane`, [UID:0000NX][SoundStatusPane](by-file/SoundStatusPane.md), and [UID:0000P1][UserPane](by-file/UserPane.md). It also creates the legacy [UID:00006O][InterfaceEfxMgr](by-class/InterfaceEfxMgr.md) after common registration.

The common tail calls [UID:0000MS][ProfileStorage](by-file/ProfileStorage.md) through `LoadUserProfileData`, calls [UID:00039S][0x00557820-0x00557838.ScreenPanePresentationModeFlagSetters](by-memory/0x00557820-0x00557838.ScreenPanePresentationModeFlagSetters.md) through [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md), calls the [UID:0000HR][BlackHole](by-file/BlackHole.md) pane/object deferred-deletion helper at `0x004f8a9a` through [UID:0000Q8][g_pApplicationCleanupQueue](by-global/g_pApplicationCleanupQueue.md), calls the optional [UID:00029D][0x0069ae08-0x0069ae0c.g_pScreenDimmer](by-memory/0x0069ae08-0x0069ae0c.g_pScreenDimmer.md) hook, retargets input through [UID:0000K6][InputMan](by-file/InputMan.md), calls [UID:0003ZI][0x0057b370-0x0057b3ec.SoundManagerRestartMusic](by-memory/0x0057b370-0x0057b3ec.SoundManagerRestartMusic.md) with a `3000` ms delay, and sets [UID:000294][0x0067ab1c-0x0067ab20.g_pApplication](by-memory/0x0067ab1c-0x0067ab20.g_pApplication.md) byte `+0x840` to `1`, best documented as `g_pApplication->m_inMapSession = true` / active map-session state. [UID:0002QH][0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown](by-memory/0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown.md) is the teardown counterpart that clears the byte.

## Boundary Notes

- IDA `lookup_funcs` confirms `sub_4F7D10` size `0xe1b`, IDA half-open range `0x004f7d10-0x004f8b2b`, and last covered byte `0x004f8b2a`; `0x004f8b30` starts `EnsureLoginDialogPane_4F8B30` after five `0xcc` padding bytes at `0x004f8b2b-0x004f8b30`.
- IDA `callers` and `xrefs_to` confirm the sole executable caller at `0x004fac9b` inside `LoginDialogPane::OnServerMessage`.
- The caller executes `mov ecx, dword_67ABA4` before the call, matching the concrete [UID:0000RF][g_pMainMenuPane](by-global/g_pMainMenuPane.md) receiver.
- A004 live IDA MCP on 2026-06-07 reconfirmed `0x004f7d10` size `0xe1b`, successor `0x004f8b30` size `0x5d`, and sole call at `0x004fac9b` inside `sub_4FAB10`.
- Live evidence counts [UID:0000RF][g_pMainMenuPane](by-global/g_pMainMenuPane.md) at 31 refs across 26 functions, [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) at 366 refs across 248 functions, and [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md) at 89 refs across 51 functions; these are dependency references, not ownership of the class method.
- The recovered `CreatePane`, `InitializePane`, `CallOptionalReadyHook`, and `NotifyLoginNameIfNeeded` helpers are generated source conveniences over repeated allocation, virtual slot, and conversion sequences. Do not promote them to original standalone functions without separate IDA evidence.
- The earlier provisional `MainUiGraph` object/login-name-cache interpretation is superseded; `m_serverName[128]` is a `MainMenuPane` member used by the emitted method.
- Pointer-route negatives preserve the sole direct login-success call through `g_pMainMenuPane`; no table-driven dispatch route exists.

## Historical 2026-06-26 B011 Source-Quality Update

- Evidence-time state: UID00019K and UID0000UV were then `90/91` and routed here. Current state is UID00019K `93/94` under MainMenuPane and UID0000UV `91/93` as its non-emitting alias.
- The frame resource names are resolved as `FRAME.EPF` and `FRAME.EPD`; the older "filenames still need decoding" caveat was superseded by string bytes, xrefs, and [UID:0001R7][backpane-background-resources](by-resource/backpane-background-resources.md).
- The active-session tail is now source-facing: `g_pScreenPane->EnablePresentationMode()`, `g_pApplicationCleanupQueue` through the BlackHole deferred-deletion helper, optional `g_pScreenDimmer`, InputMan retargeting, `SoundManager::RestartMusic(3000)`, and `g_pApplication->m_inMapSession = true`.
- The [UID:0000T6][MainUiLayerSlots](by-global/MainUiLayerSlots.md) names are the accepted documentation names for this file's layer/context slots, while final declaration shape remains open.
- Superseded conclusion: this file does not emit the initializer because MainMenuPane owns it, not because its body is unresolved. UID00019K now contains the complete human-written method.

## Source Placement

Use `ui/MainUiGraph.cpp` for shared graph/layer support and the sole zero-initialized definitions of `g_pLayoutPaneLayer`, `g_pStatusPaneLayer`, and `g_pIMEPaneLayer`, in source positions 40/50/60 after retained head support. Shared header `extern` declarations are separate and must not duplicate definitions. `login/MainMenuPane.cpp` defines `g_pMainMenuPane` and emits `MainMenuPane::InitializeMainUiGraph`; `login/LoginDialogPane.cpp` keeps login-result handling, and `app/Application.cpp` keeps lifecycle logic.

## Cross-References

- [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md)
- [UID:00019K][0x004f7d10-0x004f8b2a.InitializeMainUiGraph](by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md)
- [UID:0000RF][g_pMainMenuPane](by-global/g_pMainMenuPane.md)
- [UID:00007O][MainMenuPane](by-class/MainMenuPane.md)
- [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)
- [UID:0000T6][MainUiLayerSlots](by-global/MainUiLayerSlots.md)
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md)
- [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md)
- [UID:0000HR][BlackHole](by-file/BlackHole.md)
- [UID:00019I][0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs](by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md)
- [UID:0000K9][InterfaceEfx](by-file/InterfaceEfx.md)
- [UID:0001QQ][client_s5-ui-and-gameworld-rendering](by-meta/client_s5-ui-and-gameworld-rendering.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-07-21 B005 UID00029O source-quality callback:
  - Raised `88/88` to `90/92` for the three independently resolved Layer-pointer definitions while preserving the separate head declaration cap.
  - Added exact positions 40/50/60, physical backing UIDs, 13/14/11 reference families, startup/register and shutdown/detach/delete/clear lifecycle, header/source one-definition policy, Browser/Fps alias rejection, target split, and loader-zero evidence.
  - UID0002AF, UID0000RF, UID00019K, and UID0000UV remain routed to MainMenuPane; no initializer body or unrelated source inventory moved here.

- 2026-07-14 B002 UID0002AF callback: de-owned UID0002AF, UID0000RF, UID00019K, and UID0000UV; synchronized the concrete `g_pMainMenuPane` receiver, MainMenuPane source route, complete method/alias dispositions, and old-name history. Scores remain `88/88`; graph-layer support detail stays intact.

- 2026-06-26 B011 source-quality sync:
  - Before: `86/86`, with correct owner/source placement but stale frame-resource decoding, `main-UI-ready` tail wording, and raw layer/global/helper aliases.
  - Changed to: `88/88`, with half-open range wording, `FRAME.EPF` / `FRAME.EPD`, source-facing layer/context names, `g_pApplication->m_inMapSession = true`, `g_pScreenPane`, `g_pScreenDimmer`, `g_pApplicationCleanupQueue`, `ScreenPane::EnablePresentationMode`, `SoundManager::RestartMusic(3000)`, and the accepted formal no-code/source-shape cap for the broad initializer.
  - Evidence: B011 report `00019K-InitializeMainUiGraph-source-quality.md`, MCP session `80de0a67`, and the current by-memory/by-item pages for [UID:00019K][0x004f7d10-0x004f8b2a.InitializeMainUiGraph](by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md) and [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md).
- 2026-06-07 A008 alias cleanup:
  - Before: the layout selector row linked [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) but still used a bare `byte_66DA97` alias.
  - Changed to: preserved `byte_66DA97` only as the historical IDA alias for the canonical global.
  - Evidence: the documented `0x004f7d10` data refs still select newer EPF/current layout versus older/legacy layout.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:80`.
  - Summary/evidence: post-login UI bootstrap role, global/layer state, layout branches, common tail, sole caller, source placement, and key cross-references are documented; confidence is capped by provisional graph/root layout and generated helper naming.
- 2026-06-02: Assigned validator reconstruction path.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank while the page already named `ui/MainUiGraph.cpp` as the working source placement.
  - After: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/"`.
  - Evidence: this page documents `MainUiGraph.cpp` as the live-game UI bootstrap, and [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) already tracks the UI subsystem layout.
- 2026-06-07 A004 Batch 036 parent-gate refresh:
  - Before: `COMPLETION:84`, `CONFIDENCE:80`.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:86`.
  - Historical summary/evidence: live IDA MCP reconfirmed the boundary, caller, layer slots, layout selector, and map dimensions. The then-used `g_pMainUiGraph` alias and blank-body conclusion are superseded by [UID:0000RF][g_pMainMenuPane](by-global/g_pMainMenuPane.md) and the complete UID00019K method.
