*** UID:0000CH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ScrolledPictureControlPane

## Status

- Confidence: strong for behavior, medium for field names and caller ownership.
- Likely source file: [UID:0000NH][ScrolledPictureControlPane](by-file/ScrolledPictureControlPane.md)
- Main address ranges: `0x004ff7d0-0x004ffa9e` and `0x00502ab0-0x00502b58`
- Current recovered file: `source-3/simroot_v2/class_ScrolledPictureControlPane.cpp`

## Class Purpose

`ScrolledPictureControlPane` is a `ControlPane` type `8` image widget that loads an EPF frame, stores palette/frame draw state, and scrolls the image through the control using timer ticks.

## Method Families

| Range | Function | Role |
| --- | --- | --- |
| `0x004ff7d0-0x004ff95d` | constructor | Initialize `ControlPane`, load frame metadata and draw record, load or select a palette, compute initial destination rectangle, and start a timer. |
| `0x004ff970-0x004ff9d7` | destructor | Destroy the owned image block and tear down pane/control state. |
| `0x004ff9e0-0x004ffa4b` | `OnTimerEvent` | Offset the image rectangle by scroll step/direction, refresh the owner/control region, and schedule the next tick. |
| `0x004ffa60-0x004ffa9e` | `OnPaintFrame` | Fill/prepare the control region and blit the current image frame. |
| `0x00502550-0x00502566` | adjustor thunks | Secondary/tertiary vtable glue to `0x00502ab0`. |
| `0x00502ab0-0x00502b58` | scalar deleting destructor | Deleting-destructor wrapper around image cleanup and base teardown. |

## Evidence Notes

- IDA MCP confirms the constructor, destructor, timer, paint, thunk, and scalar deleting destructor starts.
- The constructor uses [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md) helpers rather than text-edit or DAT text rendering.
- `OnTimerEvent` scrolls in four directions and schedules another timer, matching an animated picture control rather than a one-shot image pane.
- Current IDA caller checks did not find a direct constructor caller, so final feature owner is unresolved.

## Data Caveats

- Generated owner names in the current source include fitting-room and head-selection types. Treat those as data pollution until factory/config construction is found.
- The generated timer method is written through an owner/subobject adjustment. Field offsets should be rechecked before any structure layout migration.
- 2026-05-25 IDA recheck still finds no direct constructor callers for `0x004ff7d0`; `0x00502ab0` is only directly reached by the two thunk starts at `0x00502550` and `0x0050255b`. The generated fitting-room/head-selection labels remain unsafe because IDA decompilation shows generic frame-table, palette, timer, and render-callback behavior.

## Cross-References

- [UID:0000NH][ScrolledPictureControlPane](by-file/ScrolledPictureControlPane.md)
- [UID:00019Y][0x004ff7d0-0x004ffa9e.ScrolledPictureControlPaneCore](by-memory/0x004ff7d0-0x004ffa9e.ScrolledPictureControlPaneCore.md)
- [UID:0001AD][0x00502550-0x00502566.ScrolledPictureControlPaneDestructorThunks](by-memory/0x00502550-0x00502566.ScrolledPictureControlPaneDestructorThunks.md)
- [UID:0001AI][0x00502ab0-0x00502b58.ScrolledPictureControlPaneScalarDeletingDestructor](by-memory/0x00502ab0-0x00502b58.ScrolledPictureControlPaneScalarDeletingDestructor.md)
- [UID:0000CI][ScrolledTextControlPane](by-class/ScrolledTextControlPane.md)
- [UID:0000IG][ControlPane](by-file/ControlPane.md)
- [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)

## Changes

- 2026-05-30: Changed completion/confidence from `0/0` to `76/76`.
  - Before: The page was unevaluated despite documenting image scrolling behavior, constructor/destructor/timer/paint ranges, destructor thunks, and generated-owner pollution.
  - After: Scored as moderate-high completion and confidence because behavior is strong, while field names and final caller/feature owner remain unresolved.
  - Evidence: Existing method-family table, IDA evidence notes, data caveats, and image/control cross-references support the score.
