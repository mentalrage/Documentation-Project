*** UID:0000IT | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/core/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# DialogPane

## Status

- Confidence: strong for source module and class responsibility, medium for generated active-source quality.
- Proposed module: `ui/core/DialogPane.cpp`
- Current recovered source: `source-3/simroot_v2/class_DialogPane.cpp`
- Main method cluster: `0x0049d8a0-0x0049fead`, with input override methods in `0x0046ad80-0x0046e9f4`
- Type docs: [UID:0001U4][DialogPaneLayout](by-type/by-struct/DialogPaneLayout.md), [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md)

## File Role

`DialogPane` is the base class for modal and modeless dialogs. It extends `Pane`, stores a title, dialog config ID, dialog mode/capture state, focused/hover/selected control IDs, control manager pointer, tile context, and background state. It owns common dialog creation/show/hide/destroy behavior and config-backed dialog positioning.

Many feature dialogs should remain separate feature files, but their common lifetime, control tracking, and layout behavior belong here.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `DialogPane` | `0x0049d8a0-0x0049fead` | Base dialog constructor, create/show/hide/destroy, control focus/selection, config-backed positioning. |
| vtable family | `0x00618a64`, `0x00618ac4`, `0x00618af4` | Primary dialog view plus secondary/tertiary handler views at object offsets `+0xa0` and `+0xa4`. |
| adjustor thunk helpers | `0x0048c27b`, `0x0048c286` | Compiler-generated secondary/tertiary destructor thunks; reused by derived dialog vtables. |
| [UID:00012U][0x0049eac0-0x0049f07e.DialogPaneSlideAnimation](by-memory/0x0049eac0-0x0049f07e.DialogPaneSlideAnimation.md) | `0x0049eac0-0x0049f07e` | Shared dialog slide/open/close/shrink/expand animation helpers currently polluted into feature owners. |
| input/window reposition overrides | `0x0046ad80`, `0x0046e930`; [UID:00020Y][0x0046d330-0x0046d475.WebBoardDialogVirtualCompanions](by-memory/0x0046d330-0x0046d475.WebBoardDialogVirtualCompanions.md) covers derived `0x0046d3b0`, and [UID:00020Z][0x0046d4b0-0x0046d57b.WebBoardDialogInputAndRequestHelpers](by-memory/0x0046d4b0-0x0046d57b.WebBoardDialogInputAndRequestHelpers.md) covers derived `0x0046d4b0` | Browser/embedded-window keyboard and reposition handlers currently owned by DialogPane or derived-dialog override evidence. |

## Evidence Notes

- IDA MCP reports 84 direct constructor call sites, matching a common dialog base.
- IDA MCP `list_globals` confirms three `DialogPane` vtable bases at `0x00618a64`, `0x00618ac4`, and `0x00618af4`; `disasm` confirms `0x0048c27b` and `0x0048c286` as 11-byte destructor adjustor thunks.
- IDA layout review on 2026-05-26 confirms inherited dialog fields at `+0x0f8`, `+0x1f8`, `+0x1fc`, `+0x200`, `+0x204`, mouse/control state from `+0x208` through `+0x238`, `+0x23c`, and the custom background/tile state through `+0x268`.
- IDA MCP on 2026-05-25 reports 47 direct callers to `0x0049eac0` and 69 direct callers to `0x0049eb90`, confirming the slide helpers are shared dialog infrastructure rather than ranking/clan feature methods.
- IDA MCP on 2026-06-02 confirms the base constructor at `0x0049d8a0` increments [UID:0001PH][0x0069b380-0x0069b381.g_activeDialogCount](by-memory/0x0069b380-0x0069b381.g_activeDialogCount.md), and the destructor at `0x0049d9f0` decrements it. Other UI/input paths only compare the byte, so the storage owner belongs with common dialog lifetime state.
- Generated source shows many feature dialogs calling `DialogPane::DialogPane`.
- Wave3 metadata has useful high-level structure notes, but the active generated file has low automated quality because cross-file class references were not resolved during grading. That issue is logged in [Wave3 noticed problems](../wave3_noticed_problems.md).

## Cross-References

- [UID:00003T][DialogPane](by-class/DialogPane.md)
- [UID:00012R][0x0049d8a0-0x0049feae.DialogPane](by-memory/0x0049d8a0-0x0049feae.DialogPane.md)
- [UID:0001U4][DialogPaneLayout](by-type/by-struct/DialogPaneLayout.md)
- [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md)
- [UID:00010U][0x0048c27b-0x0048c290.DialogPaneAdjustorThunks](by-memory/0x0048c27b-0x0048c290.DialogPaneAdjustorThunks.md)
- [UID:00012U][0x0049eac0-0x0049f07e.DialogPaneSlideAnimation](by-memory/0x0049eac0-0x0049f07e.DialogPaneSlideAnimation.md)
- [UID:0000MC][Pane](by-file/Pane.md)
- [UID:00000W][BlackHole](by-class/BlackHole.md)
- [UID:0000A3][PaneChildRegistry](by-class/PaneChildRegistry.md)
- [UID:0000KL][Layer](by-file/Layer.md)

## Changes

- 2026-05-27: The input/window reposition override row previously listed `0x0046d3b0` as part of the unresolved DialogPane-derived override group. Changed it to link to the `WebBoardDialog` virtual-companion memory page because IDA vtable slot `0x00613654` points to `0x0046d3b0` in the `WebBoardDialog` vtable family, and the body repositions the embedded browser child window.
- 2026-05-27: The input/window reposition override row also previously kept `0x0046d4b0` in the unresolved DialogPane-derived override group. Changed it to link to the `WebBoardDialog` input/request helper page because IDA vtable slot `0x00613658` points to `0x0046d4b0` in the same `WebBoardDialog` vtable family.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:78`.
  - Summary/evidence: base dialog role, proposed contents, vtable/layout anchors, broad constructor fan-in, slide animation ownership, derived override corrections, and generated-output quality caveat are documented; confidence is capped by active-source quality and remaining derived override review.
- 2026-05-31 projected reconstruction path:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank.
  - Changed to: `NexusTK/ui/core/`.
  - Summary/evidence: `by-project-structure/proposed-source-tree.md` places `DialogPane.cpp` under `ui/core`, and the 2026-05-31 IDA MCP recheck confirms this is common dialog infrastructure rather than a feature-dialog source.
- 2026-06-02 active-dialog counter ownership:
  - Changed confidence from `78` to `80`.
  - Evidence: IDA MCP shows `DialogPane` construction increments the global active-dialog byte and destruction decrements it; all other reviewed refs are consumers that gate immediate UI/input commands.
