*** UID:00008C | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// MiniMapDialog class declaration is intentionally withheld: the DialogPane-derived
// shell, embedded renderer, child controls, and raw no-route bodies are documented,
// but the full derived-tail layout and exact private member declarations are not
// source-quality yet.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MiniMapDialog

## Status

- Confidence: strong for purpose and core IDA-confirmed methods; medium for final file split.
- Likely source file: [UID:0000LE][MiniMap](by-file/MiniMap.md), probably `map/MiniMapDialog.cpp` or a combined `map/MiniMap.cpp`.
- Current recovered file: `source-3/simroot_v2/class_MiniMapDialog.cpp`
- Main memory doc: [UID:0000XK][0x00450ca0-0x0045381b.MiniMapDialog](by-memory/0x00450ca0-0x0045381b.MiniMapDialog.md)
- Parent attachment: [UID:0000LE][MiniMap](by-file/MiniMap.md), now that the file root and this class both satisfy the corrected 85/85 gate.

## Class Purpose

`MiniMapDialog` is the in-game minimap window. It owns the `DialogPane`-derived shell, the 768x768 map view, toggle controls for map symbol categories, coordinate display controls, tooltip/hit-test behavior, timer-driven map refresh, and the embedded [UID:00008F][MiniMapRenderer](by-class/MiniMapRenderer.md) runtime object at dialog offset `+0x1cc`.

The active dialog singleton storage is [UID:00028P][0x0067a7c4-0x0067a7c8.g_pMiniMapDialog](by-memory/0x0067a7c4-0x0067a7c8.g_pMiniMapDialog.md). The constructor publishes `this`, teardown/helper paths clear the slot, and packet/UI paths use the global to close or avoid constructing a duplicate minimap dialog.

Its static labels use a local [UID:00005C][FontStyle](by-class/FontStyle.md) configured with `Configure(0x80, 6, 1, 0)`. That style object remains reusable UI control support, not minimap-owned code.

The class is minimap/map UI feature code. It calls map, renderer, downloader, timer, and shared dialog/control helpers, but those call edges should not move the class into [UID:00007Q][MapPane](by-class/MapPane.md), [UID:0000JC][FileDownloader](by-file/FileDownloader.md), or generic dialog-control modules.

## Method Families

| Area | Address evidence | Role |
| --- | --- | --- |
| Construction and teardown | `0x00450ca0`, `0x00451330`, `0x00452d20`, `0x004537bc`, `0x004537c7`, `0x004537e0` | Builds the dialog, embedded renderer, EPF controls, coordinate numeric controls, and child panes. Destructor `0x00451330` and teardown helper `0x00452d20` contain ten static calls to inherited DialogPane pointer removal before deleting and clearing saved pane fields/vector entries. The two `0x004537bc`/`0x004537c7` functions are adjustor thunks. |
| User input and actions | `0x004518b0`, `0x004519b0`, `0x00451a10` | Toggle portal/NPC display, schedule close timer, handle keyboard close, and handle mouse map-coordinate/tooltip behavior. |
| Timer and map refresh | `0x00451c90`, raw `0x004517a0` body | Handles download status, map-image request/retry, tooltip timing, and refresh/re-render once minimap data is ready. B004 2026-06-23 confirms `0x004517a0` is still not an IDA function start and has no route to its start, but raw disassembly proves a refresh/re-render body that checks the requested map id, calls `MiniMapRenderer::BuildSymbolViews`, clears/renders panes, reapplies visibility groups, invalidates the 768x768 region, and stores refresh success state. |
| Layout and symbol rendering | [UID:0000XL][0x00452260-0x0045239a.GetControlLayout_452260](by-memory/0x00452260-0x0045239a.GetControlLayout_452260.md), `0x004523d0`, `0x00452d20`, `0x00452f70` | Lays out static controls, creates image/symbol/text/rectangle panes, clears panes, and toggles symbol groups. |

## Symbol Center Update Evidence

B005 2026-06-20 reanalysis of [UID:00008G][MiniMapSymbolControlPane](by-class/MiniMapSymbolControlPane.md) resolves a previously omitted call in the `0x00452ea0` layout/update path. That path calls `MiniMapRenderer::UpdateViewOriginFromPlayer` at `0x00452ee9`, computes display-space marker centers, calls the analogous image-control position setter at `0x00452f3d`, then calls `MiniMapSymbolControlPane::SetCenterPosition` at `0x00452f4e`. This supports `SetCenterPosition(int centerX, int centerY)` as the source-facing symbol-control helper name and rejects raw map-coordinate names for that method because renderer view-origin conversion has already happened.

B007 2026-06-21 confirms this MiniMapDialog caller chain as the ownership bridge for the renderer/control aggregate: dialog code embeds the renderer at `+0x1cc`, calls the renderer update before marker placement, then updates image-control and symbol-control centers. This keeps the renderer and private controls with the MiniMap feature root while preserving `MiniMapDialog` as the caller/owner of the UI update sequence.

## DialogPane Removal Consumer Evidence

[UID:0003KI][0x0049dca0-0x0049dcf8.DialogPaneRemoveControlByPointer](by-memory/0x0049dca0-0x0049dcf8.DialogPaneRemoveControlByPointer.md) is inherited protected `DialogPane::RemoveControl(ControlPane *)`, not a MiniMap-owned helper. Fresh session `supervisor_20260712` reports five calls from destructor `0x00451330` at `0x45137c`, `0x4513bb`, `0x45141b`, `0x45147b`, and `0x4514be`, and five from teardown helper `0x00452d20` at `0x452d2e`, `0x452d6f`, `0x452dcb`, `0x452e2b`, and `0x452e70`.

The two callers pass panes from fields `+0x5d0/+0x5d4` and pointer vectors `+0x5d8..+0x5dc`, `+0x5f0..+0x5f4`, and `+0x5fc..+0x600`. Each static call is followed by the saved pointer's deleting virtual destructor with flag `1` and then a zero store to its field/vector slot; vector sites may repeat dynamically. This order proves DialogPane's List registration is non-owning and rejects destruction or caller-storage clearing inside UID0003KI. It does not move UID0003KI, generic DialogPane control storage, or its source file into MiniMap ownership.

## B004 Raw-Label And Aggregate-Owner Recheck

B004 2026-06-23 rechecked the main [UID:0000XK][0x00450ca0-0x0045381b.MiniMapDialog](by-memory/0x00450ca0-0x0045381b.MiniMapDialog.md) island with MCP session `80de0a67` and local PE route controls. The target is now `88/89` while this class page remains a class-context page with marker-only class-level C++. The MiniMap file root [UID:0000LE][MiniMap](by-file/MiniMap.md) remains the owner/emitter because the exact memory island contains class methods plus free/helper/support bytes: [UID:0000XL][0x00452260-0x0045239a.GetControlLayout_452260](by-memory/0x00452260-0x0045239a.GetControlLayout_452260.md) `GetControlLayout_452260`, [UID:0000XM][0x004536e0-0x00453732.FontStyleImplicitDestructor](by-memory/0x004536e0-0x00453732.FontStyleImplicitDestructor.md) FontStyle cleanup, shared small-wide-string helpers at `0x00453540` and `0x00453740`, raw no-route bodies, adjustor thunks, and a scalar deleting destructor.

Current raw-label decisions for class documentation:

| Raw start | Current status | Class-facing role |
| --- | --- | --- |
| `0x004517a0` | Not an IDA function start; zero MCP xrefs; PE scan found no branch/pointer route. | Raw `RefreshMiniMap(int mapId)`-style body. It checks the target map id against `this+0x26c`, builds symbol views, clears/renders symbol panes, reapplies visibility groups, invalidates the map view, and stores success/failure at `this+0x614`. |
| `0x00452ce0` | Not an IDA function start; zero MCP xrefs; PE scan found no branch/pointer route. | Raw symbol-pane append/add-control helper. It calls the shared dialog add-control helper, appends the pane pointer into the vector around `this+0x5c4`/`this+0x5c8`, and may grow capacity. The generated `EnqueueRequest` name is rejected because the body is UI-pane vector append behavior. |
| `0x00452ea0` | Not an IDA function start; zero MCP xrefs; PE scan found no branch/pointer route. | Raw player-marker center update path. It guards the active map id, calls `MiniMapRenderer::UpdateViewOriginFromPlayer` at `0x00452ee9`, computes display-space centers, calls the image-control position setter at `0x00452f3d`, calls `MiniMapSymbolControlPane::SetCenterPosition` at `0x00452f4e`, then invalidates/draws through the dialog vtable. |

These raw bodies are source-shaped and documented as class-context behavior, but they are not source-emitting child methods under the accepted implementation. The no-code decision is target-specific: no function object, no start xrefs, no PE direct branch/pointer route, no caller-owned signature, and the parent memory page is a mixed aggregate rather than a single class implementation body.

## B010 Declaration-Shell Audit

Current evidence supports a class-index marker with `[[CHILDREN]]`, not a `class MiniMapDialog { ... }` declaration shell. The primary/secondary/tertiary vtables at `0x006104f4`, `0x00610554`, and `0x00610584` have constructor/destructor store evidence, and the class is DialogPane-derived, but the full inherited and derived-tail declaration is not settled. Constructor `0x00450ca0`, destructor `0x00451330`, scalar cleanup helper `0x004537e0`, adjustor thunks, and raw no-route bodies inside [UID:0000XK][0x00450ca0-0x0045381b.MiniMapDialog](by-memory/0x00450ca0-0x0045381b.MiniMapDialog.md) are documented at range level.

Known class-context inventory includes construction/teardown, input/action/timer/layout/render families, the embedded renderer at object offset `+0x1cc`, [UID:0000XL][0x00452260-0x0045239a.GetControlLayout_452260](by-memory/0x00452260-0x0045239a.GetControlLayout_452260.md), and raw refresh/append/center-update bodies. A declaration shell is excluded in this callback because the large derived tail, raw no-function/no-route bodies, embedded renderer/control fields, and exact private child-control member declarations are not source-quality. [UID:0000XK][0x00450ca0-0x0045381b.MiniMapDialog](by-memory/0x00450ca0-0x0045381b.MiniMapDialog.md) and exact children document behavior; this class page emits only the formal marker.

## Boundary Caveats

- Current MCP session `80de0a67` does not define functions at generated/raw starts `0x004517a0`, `0x00452ce0`, or `0x00452ea0`, and PE route controls found no direct branch or pointer route to those starts. Treat them as documented raw no-route bodies inside [UID:0000XK][0x00450ca0-0x0045381b.MiniMapDialog](by-memory/0x00450ca0-0x0045381b.MiniMapDialog.md), not class-level first-draft C++ entries.
- Historical generated `class_MiniMapDialog.cpp` placement included broad helper methods at `0x0049db60`, `0x0049dc10`, `0x0049dca0`, `0x0049dd80`, and `0x0049ddd0`. Current UID0003KI evidence confirms `0x0049dca0` is a shared DialogPane method even though all ten direct consumers are MiniMap teardown paths; receiver state and the accepted DialogPane overload family control ownership.
- The generated file includes some field names that imply local ownership of downloader-like state. IDA constructor evidence confirms construction of [UID:00008F][MiniMapRenderer](by-class/MiniMapRenderer.md) at `0x00453f50`; [UID:00008D][MiniMapDownloader](by-class/MiniMapDownloader.md) remains its own singleton/worker class.

## Cross-References

- [UID:0000LE][MiniMap](by-file/MiniMap.md)
- [UID:00008F][MiniMapRenderer](by-class/MiniMapRenderer.md)
- [UID:00008E][MiniMapImageControlPane](by-class/MiniMapImageControlPane.md)
- [UID:00008G][MiniMapSymbolControlPane](by-class/MiniMapSymbolControlPane.md)
- [UID:00009M][NumericStringControlPane](by-class/NumericStringControlPane.md)
- [UID:0000BT][RectangleControlPane](by-class/RectangleControlPane.md)
- [UID:00005C][FontStyle](by-class/FontStyle.md)
- [UID:00008D][MiniMapDownloader](by-class/MiniMapDownloader.md)
- [UID:00008H][MiniMapVersionManager](by-class/MiniMapVersionManager.md)
- [UID:0000XK][0x00450ca0-0x0045381b.MiniMapDialog](by-memory/0x00450ca0-0x0045381b.MiniMapDialog.md)
- [UID:0000SY][GetControlLayout_452260](by-global/GetControlLayout_452260.md)
- [UID:0000XO][0x00453df0-0x004563b5.MiniMapRendererAndControls](by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md)

## Changes

- 2026-07-12 B003 UID0003KI support implementation:
  - Kept `86/89`, MiniMap file owner/emitter UID0000LE, reconstructable state, marker-only class C++, and all broader B004/B005/B007/B010 class/split decisions.
  - Added all ten UID0003KI teardown call sites, exact field/vector sources, remove/destruct/clear ordering, non-owning lifetime proof, and explicit DialogPane ownership exclusion.

- 2026-06-30 B010 empty-emitter implementation callback:
  - Raised `85/88` to `86/89`, inserted the accepted formal class-index marker with `[[CHILDREN]]`, and added the declaration-shell audit covering vtables, constructor/destructor routes, raw no-route bodies, embedded renderer offset `+0x1cc`, and class-layout blockers.
- 2026-06-23 B004 MiniMapDialog source-quality implementation:
  - Score unchanged at `85/88`.
  - Added the current [UID:0000XK][0x00450ca0-0x0045381b.MiniMapDialog](by-memory/0x00450ca0-0x0045381b.MiniMapDialog.md) `88/89` raw-label and no-code decisions from MCP session `80de0a67`: `0x004517a0` as raw refresh/re-render, `0x00452ce0` as raw symbol-pane append/add-control with generated `EnqueueRequest` rejected, and `0x00452ea0` as raw player-marker center update. Clarified that `MiniMapDialog` is the primary class context, while [UID:0000LE][MiniMap](by-file/MiniMap.md) remains the file-root owner/emitter because the exact memory island also contains free/shared/helper and compiler-support bytes.
- 2026-06-21 B007 MiniMapRendererAndControls Rule 26 sync:
  - Score unchanged at `85/88`.
  - Added the caller-chain ownership bridge from MiniMapDialog into the renderer/control aggregate, confirming that `UpdateViewOriginFromPlayer` and `SetCenterPosition` belong to the MiniMap feature family without moving shared controls or raw helper bodies into the dialog class.
- 2026-06-20 B005 MiniMapSymbolControlPane support sync:
  - Score unchanged at `85/88`.
  - Added the `0x00452ea0` caller chain showing `MiniMapRenderer::UpdateViewOriginFromPlayer` at `0x00452ee9`, image-control position update at `0x00452f3d`, and `MiniMapSymbolControlPane::SetCenterPosition` at `0x00452f4e`. This keeps symbol-center ownership in the MiniMap feature while documenting why the helper takes display-space centers rather than raw map coordinates.
- 2026-06-07 A010 Batch032 parent-gate update:
  - Before: `80/84`, `AUTOGEN_PARENT_UID` blank because the MiniMap file root and class page did not clear the corrected assignment gate.
  - After: `85/88`, `AUTOGEN_PARENT_UID:0000LE`; added explicit singleton-storage ownership evidence from live IDA xrefs for `g_pMiniMapDialog`. Final class C++ remains blank because method names, projected generated labels, and source split are still below the final-source gate.
- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` after live IDA MCP on `NexusTK.exe` confirmed the minimap dialog constructor/destructor, input/timer/layout, adjustor, and cleanup starts at `0x00450ca0`, `0x00451330`, `0x004537bc`, `0x004537c7`, `0x004537e0`, `0x004518b0`, `0x004519b0`, `0x00451a10`, `0x00451c90`, `0x00452260`, `0x004523d0`, `0x00452d20`, and `0x00452f70`. At that time `AUTOGEN_PARENT_UID` stayed blank because likely parent [UID:0000LE][MiniMap](by-file/MiniMap.md) was below the 80 completion attachment gate.
- 2026-05-30: Grading changed from `0/0` to `80/84`.
  - Before: page had a useful class summary and method-family inventory but remained unevaluated by the completion/confidence header.
  - After: score reflects documented class purpose, owner module, major method families, embedded renderer relationship, shared-control dependencies, and explicit boundary caveats for projected generated labels.
  - Evidence: linked memory page [UID:0000XK][0x00450ca0-0x0045381b.MiniMapDialog](by-memory/0x00450ca0-0x0045381b.MiniMapDialog.md) records IDA-confirmed function starts, constructor callers, seven layout-helper calls, direct renderer construction, numeric/rectangle control constructor calls, and broad-helper exclusions.
