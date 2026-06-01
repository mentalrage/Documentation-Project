*** UID:0000NH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ScrolledPictureControlPane

## Status

- Confidence: strong for core behavior, medium for field names and owner-offset details.
- Proposed module: `ui/controls/ScrolledPictureControlPane.cpp`
- Proposed header: `ui/controls/ScrolledPictureControlPane.h`
- Current recovered source: `source-3/simroot_v2/class_ScrolledPictureControlPane.cpp`
- Main address clusters: `0x004ff7d0-0x004ffa9e`, `0x00502550-0x00502566`, and `0x00502ab0-0x00502b58`

## File Role

This module owns an auto-scrolling picture control. It is a `ControlPane` type `8` widget that loads an EPF frame resource, optionally loads a palette, computes an off-screen starting rectangle based on scroll direction, starts a timer, offsets the picture rectangle on each tick, invalidates/repaints the control, and blits the frame through shared render callbacks.

It is the picture-resource sibling of [UID:0000NI][ScrolledTextControlPane](by-file/ScrolledTextControlPane.md). The text control pre-renders DAT text through `TextEditPane`; this class directly loads and scrolls an EPF frame/image resource.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| [UID:00019Y][0x004ff7d0-0x004ffa9e.ScrolledPictureControlPaneCore](by-memory/0x004ff7d0-0x004ffa9e.ScrolledPictureControlPaneCore.md) | `0x004ff7d0-0x004ffa9e` | EPF picture-scroller constructor, non-deleting destructor, timer callback, paint callback, and internal switch tables. |
| [UID:0001AD][0x00502550-0x00502566.ScrolledPictureControlPaneDestructorThunks](by-memory/0x00502550-0x00502566.ScrolledPictureControlPaneDestructorThunks.md) | `0x00502550-0x00502566` | Compiler-generated secondary/tertiary destructor adjustor thunks. |
| [UID:0001AI][0x00502ab0-0x00502b58.ScrolledPictureControlPaneScalarDeletingDestructor](by-memory/0x00502ab0-0x00502b58.ScrolledPictureControlPaneScalarDeletingDestructor.md) | `0x00502ab0-0x00502b58` | Scalar deleting destructor companion for the same class. |

## Function Map

| Range | Function | Notes |
| --- | --- | --- |
| `0x004ff7d0-0x004ff95d` | `ScrolledPictureControlPane::ScrolledPictureControlPane` | Calls `ControlPane` type `8`, initializes an embedded tile/image context, loads EPF frame data, selects a palette, computes the initial destination rectangle, and starts a timer. |
| `0x004ff970-0x004ff9d7` | `ScrolledPictureControlPane::~ScrolledPictureControlPane` | Destroys the owned image block and chains to base pane teardown. |
| `0x004ff9e0-0x004ffa4b` | `ScrolledPictureControlPane::OnTimerEvent` | Moves the destination rectangle in direction `0..3`, refreshes/invalidates the owner view, and schedules the next timer. |
| `0x004ffa60-0x004ffa9e` | `ScrolledPictureControlPane::OnPaintFrame` | Invalidates/fills the control region and blits the current frame with palette state. |
| `0x00502550-0x00502566` | disabled adjustor thunks | IDA-confirmed secondary/tertiary vtable thunks; see [UID:0001AD][0x00502550-0x00502566.ScrolledPictureControlPaneDestructorThunks](by-memory/0x00502550-0x00502566.ScrolledPictureControlPaneDestructorThunks.md). |
| `0x00502ab0-0x00502b58` | scalar deleting destructor | Deleting-destructor wrapper around owned-image cleanup and base teardown; see [UID:0001AI][0x00502ab0-0x00502b58.ScrolledPictureControlPaneScalarDeletingDestructor](by-memory/0x00502ab0-0x00502b58.ScrolledPictureControlPaneScalarDeletingDestructor.md). |

## Ownership Decision

Keep this as a reusable UI control under `ui/controls`. It shares the scrolled-control pattern with [UID:0000NI][ScrolledTextControlPane](by-file/ScrolledTextControlPane.md), but its asset pipeline is EPF/palette/frame-table based and should not be merged into text editing or DAT text display code.

Do not attach it to fitting-room or head-selection dialogs based on generated type names alone. Current generated source contains `HeadSelectDialog`, `FittingRoomDialog`, `FittingRoomListPane`, and `TextButtonExControlPane` names in helper paths; IDA evidence shows a generic control/timer/image-scroll body.

## Evidence Notes

- IDA MCP confirms `0x004ff7d0`, `0x004ff970`, `0x004ff9e0`, and `0x004ffa60` as real functions and vtable targets.
- The constructor calls shared image-frame helpers [UID:0000UY][LoadImageFrameTable_004D0F50](by-item/LoadImageFrameTable_004D0F50.md) and [UID:0000UX][LoadFrameDrawRecord_004D1600](by-item/LoadFrameDrawRecord_004D1600.md), then uses [UID:0000MA][Palette](by-file/Palette.md) state.
- No direct constructor caller was found in the current IDA pass. Treat construction as config/factory-driven or unresolved until caller evidence is found.
- The scalar deleting destructor lives in a later control destructor island near other UI vtable wrappers, so it is documented here without expanding the core memory file across unrelated neighbors.
- 2026-05-25 recheck: current `class_ScrolledPictureControlPane.cpp` still contains generated `HeadSelectDialog`, `FittingRoomDialog`, `FittingRoomListPane`, and `TextButtonExControlPane` labels, while IDA still reports no direct callers for `0x004ff7d0`. IDA decompilation shows generic control behavior: `ControlPane` type `8`, frame table load through `0x004d0f50`/`0x004d1600`, palette lookup through `dword_67a7e0`, timer scheduling through `sub_5975e0`, and render callbacks through `dword_69b3fc`/`dword_69b3e8`.
- 2026-06-01 IDA MCP recheck records exact core function sizes and vtable evidence: constructor `0x18e`, destructor `0x67`, timer callback `0x6b`, paint callback `0x3f`; timer method vtable data at `0x0061d92c`; paint method vtable data at `0x0061d8d4`; constructor/destructor/scalar-deleting paths write/reference the `ScrolledPictureControlPane` vtable family at `0x0061d890`.
- The refreshed core memory page records the object-offset state map: timer interval `+0x108`, scroll step `+0x10c`, direction `+0x110`, frame block `+0x114`, frame draw record `+0x118..+0x13f`, palette/render state `+0x140`, and destination rectangle `+0x144..+0x153`.

## Current Caveats

- Field names for scroll interval, step, direction, image context, and destination rectangle are provisional. The generated `OnTimerEvent` body is especially affected by subobject/owner-offset adjustment.
- Direct construction path is still unresolved; do not infer final feature ownership from the generated fitting-room/head-selection type names.
- Destructor-generated base names are polluted and should be normalized to neutral pane/control teardown before source migration.

## Cross-References

- [UID:0000CH][ScrolledPictureControlPane](by-class/ScrolledPictureControlPane.md)
- [UID:00019Y][0x004ff7d0-0x004ffa9e.ScrolledPictureControlPaneCore](by-memory/0x004ff7d0-0x004ffa9e.ScrolledPictureControlPaneCore.md)
- [UID:0001AD][0x00502550-0x00502566.ScrolledPictureControlPaneDestructorThunks](by-memory/0x00502550-0x00502566.ScrolledPictureControlPaneDestructorThunks.md)
- [UID:0001AI][0x00502ab0-0x00502b58.ScrolledPictureControlPaneScalarDeletingDestructor](by-memory/0x00502ab0-0x00502b58.ScrolledPictureControlPaneScalarDeletingDestructor.md)
- [UID:0000NI][ScrolledTextControlPane](by-file/ScrolledTextControlPane.md)
- [UID:0000IG][ControlPane](by-file/ControlPane.md)
- [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md)
- [UID:0000UY][LoadImageFrameTable_004D0F50](by-item/LoadImageFrameTable_004D0F50.md)
- [UID:0000UX][LoadFrameDrawRecord_004D1600](by-item/LoadFrameDrawRecord_004D1600.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)
- [UID:0000MA][Palette](by-file/Palette.md)

## Changes

- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `84` and confidence to `78`.
  - Evidence: document covers control role, function map, ownership decision, IDA evidence, generated-name pollution, unresolved construction path, caveats, and cross-references; confidence is capped by provisional field names and owner-offset details.
- 2026-06-01: Raised documentation score to `88/84` and set the projected source folder to `NexusTK/ui/controls/`.
  - Before: source placement was described in prose but the validator-managed projected path was blank, and the file confidence stayed below the parent-link threshold for attached memory ranges.
  - After: the page has a concrete projected folder, exact child rows, refreshed IDA function-size/vtable evidence, and a linked object-offset state map in the core memory page.
  - Evidence: 2026-06-01 IDA MCP `lookup_funcs`, `xrefs_to`, `callees`, `decompile`, `disasm`, and byte checks recorded in [UID:00019Y][0x004ff7d0-0x004ffa9e.ScrolledPictureControlPaneCore](by-memory/0x004ff7d0-0x004ffa9e.ScrolledPictureControlPaneCore.md).
