*** UID:0000NF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/core/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ScrollBar

## Status

- Confidence: strong for `ScrollPane`, `ScrollWidget`, and `ScrollablePane`; medium-high for keeping `CScrollBarBackPane` in the same original file.
- Proposed module: `ui/core/ScrollBar.cpp`
- Current recovered sources: `source-3/simroot_v2/class_ScrollPane.cpp`, `class_ScrollWidget.cpp`, `class_ScrollablePane.cpp`, and `class_CScrollBarBackPane.cpp`
- Main address clusters: `0x0055c200-0x0055de98`, `0x0055e660-0x0055f242`, `0x005654ec-0x00565608`, `0x0053fea0-0x0053ff8d`, and `0x00542680-0x005426d5`

## File Role

This module owns generic pane-level scrollbar infrastructure. `ScrollPane` is the visible scrollbar pane, `ScrollWidget` is a small target/enable state helper embedded by scroll users, and `ScrollablePane` wraps a content pane with optional horizontal and vertical `ScrollPane` children.

`CScrollBarBackPane` appears to be an older or specialized scrollbar backplate pane. It is generic enough to keep near scrollbar infrastructure for now, but its lower address and fixed line-pattern drawing make this a medium-confidence placement.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `ScrollPane` | `0x0055c200-0x0055de98` in separate method clusters | Visible scrollbar pane, EPF/classic scrollbar drawing, hit part rectangle calculation, timer repeat callback. |
| `ScrollWidget` | `0x0055c310-0x0055c3da` | Small clamped scroll target/enabled-state helper with notify callback. |
| `ScrollablePane` | `0x0055e660-0x0055f242`, `0x005654ec-0x00565608` | Pane that owns horizontal/vertical `ScrollPane` children, destructor adjustor glue, and default virtuals. |
| `CScrollBarBackPane` | `0x0053fea0-0x0053ff8d`, `0x00542680-0x005426d5` | Fixed scrollbar background/backplate pane, cleanup helper, draw vtable method, adjustor thunks, and scalar teardown. |
| Scrollbar size tables | globals in `class_ScrollablePane.cpp` | High/low resolution horizontal and vertical scrollbar thickness tables. |

## Ownership Decision

Keep this separate from [UID:0000MC][Pane](by-file/Pane.md). `Pane` owns base visibility, layers, events, and dirty regions; this module owns scrollbar-specific geometry, drawing, and scroll child layout.

Keep [UID:0000NE][ScrollableControlPane](by-file/ScrollableControlPane.md) as a neighboring controls module rather than folding it into `ScrollBar.cpp`. It derives from [UID:0000IG][ControlPane](by-file/ControlPane.md), has control type `0x12`, and has broad dialog-level constructor fan-in.

Do not fold `TextEditPane` into this file. `TextEditPane` contains many scrollbar tracking variants, but it is a large rich text editor class. Its scroll methods consume `ScrollPane::GetScrollPartRect` rather than proving the entire editor belongs in scrollbar core.

## Evidence Notes

- `ScrollablePane::ScrollablePane` constructs two `ScrollPane` children: `new ScrollPane(1)` for horizontal and `new ScrollPane(0)` for vertical.
- IDA MCP reports six direct `ScrollablePane` constructor callers: `ChattingPane`, `FolderTreePane`, `ListPane`, `SystemMessagePane`, `OldSystemMessagePane`, and `TextEditPane`.
- `ScrollPane::OnDraw` renders classic `SCRL001.EPD`/`SCRL001.PAD` assets and newer EPF assets such as `SLIDEBG.EPF`, `SCRBUTT.EPF`, `SLIDEBG.PAL`, and `BUTTON.PAL`.
- `ScrollPane::GetScrollPartRect` has 15 direct call references, including calls from `ScrollPane::OnDraw` and nearby `TextEditPane` scrollbar handlers.
- `ScrollWidget` metadata says the recovered subset proves a notify callback at `+0x20`, position/target state, and an enabled flag; the class sits in the same address neighborhood as `ScrollPane`.
- 2026-06-03 IDA MCP recheck corrects the local input-core method ends to half-open ranges, exposes raw setter-shaped bodies at `0x0055c2b0`, `0x0055c2e0`, and `0x0055c370`, and confirms `ScrollWidget` callers from `ScrollablePane` synchronization and `ChattingHandlePane` enable/disable paths.
- `CScrollBarBackPane` has two excluded adjustor thunk methods at `0x0054259f` and `0x005425aa`, now documented inside [UID:00023J][0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland](by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md).
- 2026-06-01 IDA MCP recheck: `CScrollBarBackPane` core contains constructor bytes at `0x0053fea0-0x0053fed2`, internal `0xcc` alignment at `0x0053fed2-0x0053fee0`, cleanup helper `sub_53FEE0` at `0x0053fee0-0x0053feff`, and draw method `sub_53FF00` at `0x0053ff00-0x0053ff8d`.
- 2026-06-01 IDA MCP recheck: `sub_53FF00` is referenced from vtable/data slot `0x00621060`; scalar deleting destructor `sub_542680` is referenced from `0x0062101c` and from adjustor jumps at `0x005425a5`/`0x005425b0`; adjustor thunks are referenced from secondary table slots `0x00621068` and `0x00621098`.
- 2026-06-01 IDA MCP recheck: `0x0062101c` is the primary `CScrollBarBackPane` vtable base, referenced by constructor write `0x0053feb1`, cleanup helper write `0x0053fee0`, NewOptionPane-adjacent code at `0x005400fc`/`0x00540147`, and destructor write `0x00542686`.
- `ScrollCollectionPane` and `ScrollNewGroupPane` share the same pane-derived themed-scrollbar layout pattern and EPF-backed input/paint helpers, but current evidence keeps them as sibling themed scrollbar classes rather than merging them into the older `ScrollPane` core.
- 2026-05-28 IDA MCP boundary review corrected `ScrollPane::OnScrollTimer` to end at `0x0055c643`, `ScrollPane::OnDraw` to end at `0x0055d957`, and `ScrollablePane` destructor/defaults to cover `0x005654ec-0x00565608`.

## Cross-References

- [UID:0000CM][ScrollPane](by-class/ScrollPane.md)
- [UID:0000CP][ScrollWidget](by-class/ScrollWidget.md)
- [UID:0000CF][ScrollablePane](by-class/ScrollablePane.md)
- [UID:00003D][CScrollBarBackPane](by-class/CScrollBarBackPane.md)
- [UID:0001GH][0x0055c200-0x0055c643.ScrollPaneInputCore](by-memory/0x0055c200-0x0055c643.ScrollPaneInputCore.md)
- [UID:0001GI][0x0055c650-0x0055d957.ScrollPaneOnDraw](by-memory/0x0055c650-0x0055d957.ScrollPaneOnDraw.md)
- [UID:0001GK][0x0055d9e0-0x0055de98.ScrollPaneGetScrollPartRect](by-memory/0x0055d9e0-0x0055de98.ScrollPaneGetScrollPartRect.md)
- [UID:0001GL][0x0055e660-0x0055f242.ScrollablePaneCore](by-memory/0x0055e660-0x0055f242.ScrollablePaneCore.md)
- [UID:0001H6][0x005654ec-0x00565608.ScrollablePaneVirtualDefaults](by-memory/0x005654ec-0x00565608.ScrollablePaneVirtualDefaults.md)
- [UID:0001DV][0x0053fea0-0x0053ff8d.CScrollBarBackPaneCore](by-memory/0x0053fea0-0x0053ff8d.CScrollBarBackPaneCore.md)
- [UID:0001E3][0x00542680-0x005426d5.CScrollBarBackPaneDestructor](by-memory/0x00542680-0x005426d5.CScrollBarBackPaneDestructor.md)
- [UID:00023J][0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland](by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md)
- [UID:0000NE][ScrollableControlPane](by-file/ScrollableControlPane.md)
- [UID:0000NG][ScrollCollectionPane](by-file/ScrollCollectionPane.md)
- [UID:0001VZ][ScrollCollectionPaneLayout](by-type/by-struct/ScrollCollectionPaneLayout.md)
- [UID:0000CL][ScrollNewGroupPane](by-class/ScrollNewGroupPane.md)

## Changes

- 2026-05-28: Changed `CScrollBarBackPane` core end from `0x0053ff8c` to `0x0053ff8d`.
  - Before: the file candidate stopped before the final `ret` byte of the draw helper.
  - After: the file candidate includes the full `DrawScrollBarBackPattern` helper.
  - Evidence: IDA MCP reports `sub_53FF00` as `0x0053ff00-0x0053ff8d`; bytes after that end are padding before `NewOptionPane`.
- 2026-05-28: Changed `CScrollBarBackPane` destructor end from `0x005426d4` to `0x005426d5`.
  - Before: the file candidate omitted the final byte of the scalar deleting destructor wrapper.
  - After: the file candidate includes the full wrapper and points excluded adjustor thunks to the shared thunk island.
  - Evidence: IDA MCP reports `sub_542680` as `0x00542680-0x005426d5`; related adjustor thunks live in [UID:00023J][0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland](by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md).
- 2026-05-28: Corrected ScrollPane/ScrollablePane boundary endpoints.
  - Before: `ScrollPaneInputCore`, `ScrollPaneOnDraw`, and `ScrollablePaneVirtualDefaults` used `0x0055c642`, `0x0055d956`, and `0x00565510-0x00565607`.
  - After: the file doc uses corrected owner ranges `0x0055c200-0x0055c643`, `0x0055c650-0x0055d957`, and `0x005654ec-0x00565608`.
  - Evidence: IDA MCP reports the final bytes of `OnScrollTimer`, `OnDraw`, and `IsScrollable`, plus two `ScrollablePane` destructor adjustor thunks at `0x005654ec` and `0x005654f7`.
- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `86` and confidence to `80`.
  - Evidence: document covers scrollbar class family contents, ownership decisions, IDA evidence, boundary corrections, sibling-class exclusions, and cross-references; confidence remains capped by whether `CScrollBarBackPane` was originally in the same source file.
- 2026-06-01: Changed `PROPOSED_RECONSTRUCTION_PATH` from blank to `NexusTK/ui/core/`, raised completion/confidence from `86/80` to `88/82`, and added current `CScrollBarBackPane` IDA evidence.
  - Before: the page had a proposed module but no validator path, and the CScrollBarBackPane child evidence missed the local cleanup helper.
  - After: the source path is explicit and child pages can attach to this file; final source remains deferred because helper names and `CScrollBarBackPane` file placement are not final-audit quality.
- 2026-06-03: Attached core scroll class pages and corrected ScrollWidget local ranges.
  - Before: `ScrollPane`, `ScrollWidget`, and `ScrollablePane` class pages were listed here but unassigned in autogen metadata, and `ScrollWidget` method ranges omitted return bytes.
  - After: attached [UID:0000CM][ScrollPane](by-class/ScrollPane.md), [UID:0000CP][ScrollWidget](by-class/ScrollWidget.md), and [UID:0000CF][ScrollablePane](by-class/ScrollablePane.md) to this file; C++ remains blank for all.
  - Evidence: IDA MCP `py_eval` on 2026-06-03 confirms the input-core function boundaries, raw setter bodies, `ScrollablePane` callers, `ChattingHandlePane` enable/disable callers, and notification callback pattern.
