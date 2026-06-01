*** UID:0000NK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ScrollVolumePane

## Status

- Confidence: strong for class/source-family identity; medium-high for final `ui/controls` folder placement.
- Proposed module: `ui/controls/ScrollVolumePane.cpp`
- Proposed header: `ui/controls/ScrollVolumePane.h`
- Current recovered source: `source-3/simroot_v2/ui/controls/class_ScrollVolumePane.cpp`
- Main class: [UID:0000CO][ScrollVolumePane](by-class/ScrollVolumePane.md)
- Main address doc: [UID:0001H2][0x00564710-0x005654ec.ScrollVolumePane](by-memory/0x00564710-0x005654ec.ScrollVolumePane.md)
- Evidence basis: `simroot_v2`, cached prewave metadata, read-only Wave2 recovered methods, Wave2 report entries, and IDA MCP checks through 2026-05-26.

## File Role

`ScrollVolumePane.cpp` owns the vertical slider used by option-panel sound and music volume controls. It is a `Pane`-derived control with three vtable views, packed value/range/enabled/highlight/drag state, mouse capture/drag handling, and EPF-backed thumb rendering from `SCRBUTT2.EPF` with `BUTTON.PAL`.

Keep this separate from [UID:0000M7][OptionPane](by-file/OptionPane.md). `NewOptionPane` constructs and configures the sliders, but this source owns reusable slider behavior and drawing.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| [UID:0000CO][ScrollVolumePane](by-class/ScrollVolumePane.md) | `0x00564710-0x005654ec` | Volume slider pane constructor, value/range API, mouse handling, drawing, and helper methods. |
| [UID:0001H3][0x00564e30-0x00565006.ScrollVolumePaneHitTestPart](by-memory/0x00564e30-0x00565006.ScrollVolumePaneHitTestPart.md) | `0x00564e30-0x00565006` | Omitted helper that maps a point to slider part id `0..4` or `-1`. |
| [UID:0002LB][0x00565170-0x005651e0.ScrollVolumePaneSetHighlightPartRaw](by-memory/0x00565170-0x005651e0.ScrollVolumePaneSetHighlightPartRaw.md) | `0x00565170-0x005651e0` | Raw helper that invalidates old/new highlighted slider parts and stores highlight state. |
| [UID:0002LC][0x005651e0-0x005652a0.ScrollVolumePaneBeginInteractionRaw](by-memory/0x005651e0-0x005652a0.ScrollVolumePaneBeginInteractionRaw.md) | `0x005651e0-0x005652a0` | Raw helper that initializes drag/highlight state, calls commit, and starts timer/update handling. |
| [UID:0001H4][0x005652a0-0x00565360.ScrollVolumePaneCommitInteraction](by-memory/0x005652a0-0x00565360.ScrollVolumePaneCommitInteraction.md) | `0x005652a0-0x00565360` | Omitted helper that commits mouse/focus interactions and clears highlight state. |
| [UID:0001H5][0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange](by-memory/0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange.md) | `0x00565360-0x00565488` | Omitted helper that computes changed slider values and calls the option-pane callback. |
| [UID:0002LD][0x00565490-0x005654ec.ScrollVolumePaneResetInteractionStateRaw](by-memory/0x00565490-0x005654ec.ScrollVolumePaneResetInteractionStateRaw.md) | `0x00565490-0x005654ec` | Raw helper that stops timer/update handling and clears active/highlight state before `ScrollablePane` destructor thunks. |
| [UID:0001W2][ScrollVolumePaneLayout](by-type/by-struct/ScrollVolumePaneLayout.md) | offsets `+0xfc` through `+0x10c` | Packed volume type, current/range values, enabled/highlight/interaction/drag fields. |
| [UID:0001YT][ScrollVolumePaneVtables](by-type/by-vtable/ScrollVolumePaneVtables.md) | `0x006240b4`, `0x00624100`, `0x00624130` | Three-view pane vtable cluster for paint, mouse, false-return, and focus/commit slots. |
| `g_pEPFLibrary` / [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) dependency | global data dependency | Loads `SCRBUTT2.EPF`/`BUTTON.PAL` for thumb frames; generated `g_pEPFLibrary` should be treated as an unresolved alias lead until reconciled with the reviewed EPF registry singleton. |

## Evidence Notes

- Current Wave3 metadata imports the class from `ScrollVolumePane.cpp` and describes a 272-byte struct extending `Pane`.
- IDA confirms real function starts for constructor and primary methods at `0x00564710`, `0x00564820`, `0x00564880`, `0x005648b0`, `0x005648d0`, `0x00564910`, `0x00564b00`, `0x00564b10`, `0x00564b50`, `0x00564e30`, `0x00565010`, `0x005652a0`, and `0x00565360`.
- 2026-05-25 IDA MCP checks confirm the omitted helpers at `0x00564e30`, `0x005652a0`, and `0x00565360` are an internal slider interaction chain; the final helper calls [UID:0000M7][OptionPane](by-file/OptionPane.md) callback `0x00540490` only after a value change.
- 2026-05-26 IDA MCP recheck leaves the boundary unchanged: `0x00565170`, `0x005651e0`, and `0x00565490` still report `Not a function` with no xrefs, while `0x005654ec` and `0x005654f7` are vtable-referenced adjustor thunks that jump to `ScrollablePane::ScalarDeletingDestructor` at `0x00565510`.
- 2026-05-31 IDA MCP raw-disassembly pass split `0x00565170`, `0x005651e0`, and `0x00565490` into exact memory pages so the file-level contents no longer rely on inline projected rows.
- IDA confirms vtable bases `0x006240b4`, `0x00624100`, and `0x00624130`; current Wave3 metadata has `vtable_count: 0`, so vtable inventory must be maintained manually until the data is fixed.
- Constructor callers are two allocations from [UID:0000M7][OptionPane](by-file/OptionPane.md) constructor at `0x00540097` and `0x005400c6`, corresponding to music and sound sliders.
- `SetRange`, `SetValue`, `Enable`, and `Disable` are called by `NewOptionPane` helpers at `0x005403b0` and `0x00541a90`.
- Wave2 recovered `ScrollVolumePane::SetRange`, `SetValue`, `Enable`, and `Disable` match the active generated methods and were restored to close previous missing refs.

## Generated Output Caveats

- Active `class_ScrollVolumePane.cpp` now emits helper bodies at `0x00564e30`, `0x005652a0`, and `0x00565360`, but the generated C++ still uses stale `TextEditPane::*` signatures for those helper bodies while the source map keeps them in the `ScrollVolumePane` file/method partition.
- Active output includes `SetHighlightPart` at `0x00565170` and `ResetInteractionState` at `0x00565490`; both are function-shaped raw code in IDA disassembly, but IDA `lookup_funcs` reports `Not a function` and `xrefs_to` reports no xrefs. Keep them as raw/projected helpers until the function table is corrected.
- The adjacent `0x005654ec`, `0x005654f7`, and `0x00565510` destructor tail is currently [UID:0001H6][0x005654ec-0x00565608.ScrollablePaneVirtualDefaults](by-memory/0x005654ec-0x00565608.ScrollablePaneVirtualDefaults.md) glue, not `ScrollVolumePane` ownership evidence. The canonical memory page now starts at `0x005654ec` so those thunks are covered by `ScrollablePane`, not this file.
- `class_ScrollVolumePane.cpp.source_map.json` still reports generated `g_pEPFLibrary` as unresolved global-data provenance with no memory range. Use [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) as the reviewed canonical global, or run a dedicated alias/global pass before treating the local comment as a distinct ownership record.

## Changes

- 2026-05-28: Clarified that `0x005654ec` and `0x005654f7` are now included in the `ScrollablePaneVirtualDefaults` page.
  - Before: this file pointed to a `0x00565510-0x00565607` page that described the thunks only in prose.
  - After: the `ScrollablePane` page range itself covers `0x005654ec-0x00565608`; `ScrollVolumePane` still ends at `0x005654ec`.
  - Evidence: IDA MCP reports the two thunks subtracting `0xa0`/`0xa4` and jumping to `0x00565510`.
- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `88` and confidence to `80`.
  - Evidence: document includes role, proposed contents, omitted helper chain, layout/vtable refs, IDA evidence, generated-output caveats, boundary correction, source-structure decision, and cross-references; confidence remains capped by final folder and raw/projected helper modeling.
- 2026-05-30: Corrected the current recovered source path and generated-output caveat.
  - Before: The page referenced the old flat `source-3/simroot_v2/class_ScrollVolumePane.cpp` path and said the active output omitted the three helper bodies.
  - After: The page points to `source-3/simroot_v2/ui/controls/class_ScrollVolumePane.cpp` and records the current issue more precisely: the helper bodies are emitted, but some generated signatures remain polluted by `TextEditPane` ownership/name data.
  - Evidence: Current `simroot_v2` file list, `class_ScrollVolumePane.cpp.source_map.json`, and `class_ScrollVolumePane.meta_wave3` report emitted path `ui\controls\class_ScrollVolumePane.cpp`, active methods `0x00564e30`, `0x005652a0`, and `0x00565360`, and `TextEditPane::*` signatures in the generated source body.
- 2026-05-31: Set `PROPOSED_RECONSTRUCTION_PATH` to `NexusTK/ui/controls/` and added the split raw helper memory pages to proposed contents.
  - Before: The validator-managed projected path was blank and raw helper spans were only described in caveats.
  - After: The file stages as `auto-generated/NexusTK/ui/controls/ScrollVolumePane.cpp`, matching the proposed source tree, and contents link the exact raw helper pages by UID.
  - Evidence: `by-project-structure/proposed-source-tree.md` already places `ScrollVolumePane.cpp` under controls; IDA MCP confirms the raw helper boundaries and the class remains a reusable UI control consumed by `OptionPane`.
- `GetPartRect` has broad helper use inside this source and possibly text-edit/scroll helpers; do not move it to [UID:0000ON][TextEditPane](by-file/TextEditPane.md) solely from generated notes.

## Source-Structure Decision

Use a separate `ui/controls/ScrollVolumePane.cpp` module. It is more specific than [UID:0000NF][ScrollBar](by-file/ScrollBar.md) and [UID:0000NE][ScrollableControlPane](by-file/ScrollableControlPane.md), but still a reusable control. [UID:0000M7][OptionPane](by-file/OptionPane.md) consumes it to implement audio settings and should not absorb its class methods.

## Cross-References

- [UID:0000CO][ScrollVolumePane](by-class/ScrollVolumePane.md)
- [UID:0001H2][0x00564710-0x005654ec.ScrollVolumePane](by-memory/0x00564710-0x005654ec.ScrollVolumePane.md)
- [UID:0001H3][0x00564e30-0x00565006.ScrollVolumePaneHitTestPart](by-memory/0x00564e30-0x00565006.ScrollVolumePaneHitTestPart.md)
- [UID:0002LB][0x00565170-0x005651e0.ScrollVolumePaneSetHighlightPartRaw](by-memory/0x00565170-0x005651e0.ScrollVolumePaneSetHighlightPartRaw.md)
- [UID:0002LC][0x005651e0-0x005652a0.ScrollVolumePaneBeginInteractionRaw](by-memory/0x005651e0-0x005652a0.ScrollVolumePaneBeginInteractionRaw.md)
- [UID:0001H4][0x005652a0-0x00565360.ScrollVolumePaneCommitInteraction](by-memory/0x005652a0-0x00565360.ScrollVolumePaneCommitInteraction.md)
- [UID:0001H5][0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange](by-memory/0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange.md)
- [UID:0002LD][0x00565490-0x005654ec.ScrollVolumePaneResetInteractionStateRaw](by-memory/0x00565490-0x005654ec.ScrollVolumePaneResetInteractionStateRaw.md)
- [UID:0001W2][ScrollVolumePaneLayout](by-type/by-struct/ScrollVolumePaneLayout.md)
- [UID:0001YT][ScrollVolumePaneVtables](by-type/by-vtable/ScrollVolumePaneVtables.md)
- [UID:0000M7][OptionPane](by-file/OptionPane.md)
- [UID:0001DW][0x0053ff90-0x00541b2b.NewOptionPane](by-memory/0x0053ff90-0x00541b2b.NewOptionPane.md)
- [UID:0000NF][ScrollBar](by-file/ScrollBar.md)
- [UID:0000NE][ScrollableControlPane](by-file/ScrollableControlPane.md)
- [UID:0001QV][client_ui_core](by-meta/client_ui_core.md)
