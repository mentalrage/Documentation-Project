*** UID:0000CH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000NH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ScrolledPictureControlPane

## Status

- Confidence: strong for behavior, exact method boundaries, vtable refs, callee set, and source-file ownership; medium for final field names and construction path.
- Likely source file: [UID:0000NH][ScrolledPictureControlPane](by-file/ScrolledPictureControlPane.md)
- Main address ranges: `0x004ff7d0-0x004ffa9f`, `0x00502550-0x00502566`, and `0x00502ab0-0x00502b58`

## Class Purpose

`ScrolledPictureControlPane` is a `ControlPane` type `8` image widget that loads an EPF frame, stores palette/frame draw state, and scrolls the image through the control using timer ticks.

## Method Families

| Range | Function | Role |
| --- | --- | --- |
| `0x004ff7d0-0x004ff95e` | constructor | Initialize `ControlPane`, load frame metadata and draw record, load or select a palette, compute initial destination rectangle, and start a timer. |
| `0x004ff970-0x004ff9d7` | destructor | Destroy the owned image block and tear down pane/control state. |
| `0x004ff9e0-0x004ffa4b` | `OnTimerEvent` | Offset the image rectangle by scroll step/direction, refresh the owner/control region, and schedule the next tick. |
| `0x004ffa60-0x004ffa9f` | `OnPaintFrame` | Fill/prepare the control region and blit the current image frame. |
| `0x00502550-0x00502566` | adjustor thunks | Secondary/tertiary vtable glue to `0x00502ab0`. |
| `0x00502ab0-0x00502b58` | scalar deleting destructor | Deleting-destructor wrapper around image cleanup and base teardown. |

## Evidence Notes

- 2026-06-04 live IDA MCP on `NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515` confirms `sub_4FF7D0` as `0x004ff7d0-0x004ff95e`, `sub_4FF970` as `0x004ff970-0x004ff9d7`, `sub_4FF9E0` as `0x004ff9e0-0x004ffa4b`, `sub_4FFA60` as `0x004ffa60-0x004ffa9f`, the two `0xb` adjustor thunks at `0x00502550` and `0x0050255b`, and `sub_502AB0` as `0x00502ab0-0x00502b58`.
- Live refs show no direct code/data refs to the constructor or non-deleting destructor starts; timer and paint are vtable-reached at `0x0061d92c` and `0x0061d8d4`, and the scalar deleting destructor has vtable ref `0x0061d890` plus thunk code refs from `0x00502556` and `0x00502561`.
- The constructor calls [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md) helpers `0x004d0f50` and `0x004d1600`, palette helpers `0x00543d70`/`0x00543d40`, rectangle setup `0x004b7c50`, and timer scheduling `0x005975e0`, confirming an EPF/palette picture control rather than text-edit or DAT text rendering.
- `OnTimerEvent` switches on direction `0..3`, offsets the destination rectangle by the scroll step, invalidates/refreshes through the owner/control subobject, and schedules another timer tick.
- `OnPaintFrame` calls the pane fill/prepare helper and render callbacks through `dword_69B3FC` and `dword_69B3E8`, matching frame blitting with palette state.
- Live boundary bytes confirm constructor switch-table support starts after the constructor at `0x004ff95e`, timer switch-table support starts after `0x004ffa4b`, and the paint method's final `retn` is at `0x004ffa9e` with padding at `0x004ffa9f`.

## Data Caveats

- Prior owner labels include fitting-room and head-selection types. Treat those as data pollution until factory/config construction is found.
- The timer method is reached through an owner/subobject adjustment. Field offsets should be rechecked before any structure layout migration.
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

- 2026-06-05: Changed `RECONSTRUCTABLE` from blank to `TRUE` and assigned parent `0000NH`.
  - Before: The EPF picture scroller remained unclassified in autogen coverage even though the class and parent file both met the 80/80 attach gate.
  - After: The class contributes to `ScrolledPictureControlPane.cpp` as a reconstructable child without emitting final C++ yet.
  - Evidence: Live IDA MCP lookup confirms constructor/destructor/timer/paint starts at `0x004ff7d0`, `0x004ff970`, `0x004ff9e0`, `0x004ffa60`, adjustor thunks at `0x00502550` and `0x0050255b`, and scalar deleting destructor `0x00502ab0`; parent [UID:0000NH][ScrolledPictureControlPane](by-file/ScrolledPictureControlPane.md) records the same EPF/palette control ownership.

- 2026-05-30: Changed completion/confidence from `0/0` to `76/76`.
  - Before: The page was unevaluated despite documenting image scrolling behavior, constructor/destructor/timer/paint ranges, destructor thunks, and generated-owner pollution.
  - After: Scored as moderate-high completion and confidence because behavior is strong, while field names and final caller/feature owner remain unresolved.
  - Evidence: Existing method-family table, IDA evidence notes, data caveats, and image/control cross-references support the score.
- 2026-06-04: Changed completion/confidence from `76/76` to `84/88`.
  - Before: The page had a useful function map but stale generated-source wording, final-byte-style method ends, and limited caller/vtable/callee evidence.
  - After: Scored higher because live IDA confirms exact half-open method extents, vtable refs, thunk targets, callee set, switch-table boundaries, scalar deleting destructor behavior, and source-file ownership through the refreshed core memory page.
  - Remaining uncertainty: final C++ stays blank because field names, construction/factory path, and base teardown naming are not proven to the 95/95 reconstruction bar.
