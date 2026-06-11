*** UID:0000CO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000NK | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ScrollVolumePane

## Status

- Confidence: strong for behavior and source ownership; medium-high for final helper names and raw function-table gaps.
- Likely source file: [UID:0000NK][ScrollVolumePane](by-file/ScrollVolumePane.md)
- Parent handling: attached to [UID:0000NK][ScrollVolumePane](by-file/ScrollVolumePane.md) at autogen position `10`; this class is `87/85` and the direct file parent is `88/85`, so the current strict parent gate is satisfied. C++ remains blank below the 95+ reconstruction gate.
- Address range: [UID:0001H2][0x00564710-0x005654ec.ScrollVolumePane](by-memory/0x00564710-0x005654ec.ScrollVolumePane.md)
- Vtables: [UID:0001YT][ScrollVolumePaneVtables](by-type/by-vtable/ScrollVolumePaneVtables.md)
- Current recovered file: `source-3/simroot_v2/ui/controls/class_ScrollVolumePane.cpp`
- Imported source file: `ScrollVolumePane.cpp`

## Class Purpose

`ScrollVolumePane` is a vertical volume slider pane used by the option UI. It tracks a current value, maximum range, enabled state, highlighted part, active interaction state, and thumb drag offset. Mouse input can page above/below the thumb, drag the thumb, commit changes, and refresh only affected part rectangles.

The class renders the slider track and two-part thumb through `SCRBUTT2.EPF` / `BUTTON.PAL`; it does not own sound playback or option packet policy.

## Method Notes

| Method or helper | Address | Role |
| --- | --- | --- |
| constructor | `0x00564710-0x005647b1` | Constructs the `Pane` base, stores volume type, initializes packed slider state, installs three vtable pointers, and clears the mouse reference point. |
| raw low-state-word setter | [UID:00031M][0x005647c0-0x005647e7.ScrollVolumePaneSetLowStateWordRaw](by-memory/0x005647c0-0x005647e7.ScrollVolumePaneSetLowStateWordRaw.md) | Function-shaped raw helper that stores word `+0xf8` and invalidates the bounds rect when changed. |
| raw state-byte setter | [UID:00031N][0x005647f0-0x00564814.ScrollVolumePaneSetStateByteRaw](by-memory/0x005647f0-0x00564814.ScrollVolumePaneSetStateByteRaw.md) | Function-shaped raw helper that stores byte `+0xfa` and invalidates the bounds rect when changed. |
| `SetRange` | `0x00564820-0x0056487b` | Clamps max range to `0..30000`, reduces current value if necessary, and invalidates bounds. |
| `SetValue` | `0x00564880-0x005648a7` | Stores the current value and invalidates bounds when changed. |
| `Enable` | `0x005648b0-0x005648ca` | Sets enabled byte and invalidates the control. |
| `Disable` | `0x005648d0-0x005648ea` | Clears enabled byte and invalidates the control. |
| raw can-adjust predicate | [UID:00031O][0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw](by-memory/0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw.md) | Function-shaped raw predicate returning enabled-and-positive-range state from `+0x102/+0x100`. |
| `OnMouseEvent` | `0x00564910-0x00564af1` | Handles mouse press, drag, release, capture, highlight, page up/down, and commit paths. |
| `IsScrollable` | `0x00564b00-0x00564b05` | Returns false; this pane is not an externally scrollable viewport. |
| `OnLoseFocus` | `0x00564b10-0x00564b43` | Commits pending slider changes and schedules refresh when focus is lost. |
| `OnPaint` | `0x00564b50-0x00564e21` | Draws track background and the two-part EPF thumb at the computed value/drag position. |
| hit-test helper | [UID:0001H3][0x00564e30-0x00565006.ScrollVolumePaneHitTestPart](by-memory/0x00564e30-0x00565006.ScrollVolumePaneHitTestPart.md) | IDA-confirmed omitted helper that finds which slider part contains a point. |
| `GetPartRect` | `0x00565010-0x0056516b` | Computes part rectangles for track above thumb, thumb, track below thumb, and collapsed edge regions. |
| raw `SetHighlightPart` helper | [UID:0002LB][0x00565170-0x005651e0.ScrollVolumePaneSetHighlightPartRaw](by-memory/0x00565170-0x005651e0.ScrollVolumePaneSetHighlightPartRaw.md) | Function-shaped raw code that invalidates old/new highlight parts; IDA currently does not model it as a function. |
| raw begin-interaction helper | [UID:0002LC][0x005651e0-0x005652a0.ScrollVolumePaneBeginInteractionRaw](by-memory/0x005651e0-0x005652a0.ScrollVolumePaneBeginInteractionRaw.md) | Function-shaped raw helper that updates highlight/drag state, calls drag commit, and starts the timer/update view; IDA currently does not model it as a function. |
| drag update/commit helper | [UID:0001H4][0x005652a0-0x00565360.ScrollVolumePaneCommitInteraction](by-memory/0x005652a0-0x00565360.ScrollVolumePaneCommitInteraction.md) | IDA-confirmed helper called from mouse and focus paths; commits active interaction state. |
| value-change notify helper | [UID:0001H5][0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange](by-memory/0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange.md) | IDA-confirmed helper that computes new value and calls the owning option-pane callback when changed. |
| raw `ResetInteractionState` helper | [UID:0002LD][0x00565490-0x005654ec.ScrollVolumePaneResetInteractionStateRaw](by-memory/0x00565490-0x005654ec.ScrollVolumePaneResetInteractionStateRaw.md) | Function-shaped raw code that clears timer/highlight state; IDA currently does not model it as a function. |

## Excluded Tail

IDA/cache identify the immediately following `0x005654ec` and `0x005654f7` adjustor thunks and `0x00565510` deleting destructor as `ScrollablePane` destructor glue. Do not use those rows as evidence that `ScrollVolumePane.cpp` owns a destructor implementation unless later IDA/vtable work proves otherwise.

2026-05-26 IDA MCP recheck confirms both adjustor thunks still have data refs from vtable slots (`0x00623e58` and `0x00623e88`) and jump to `0x00565510`; `0x00565510` still has no ordinary callers and decompiles as the `ScrollablePane` scalar deleting destructor.

## Layout Notes

See [UID:0001W2][ScrollVolumePaneLayout](by-type/by-struct/ScrollVolumePaneLayout.md). The most important local fields are:

- `+0xfc`: volume type, set by constructor argument.
- `+0xfe`: current slider value.
- `+0x100`: max slider value/range.
- `+0x102`: enabled byte.
- `+0x103`: highlighted slider part.
- `+0x104`: active interaction part.
- `+0x108`: mouse reference point / drag state.
- `+0x10c`: drag offset used while dragging the thumb.

## Evidence Notes

- IDA `lookup_funcs` confirms all primary methods except raw/projected `0x00565170`, `0x005651e0`, and `0x00565490`.
- 2026-05-31 IDA raw-disassembly pass split those three raw/projected helper spans into exact `by-memory` pages and confirmed their field effects on highlight, active part, drag offset, timer/update view, and reset state.
- IDA `callers` confirms constructor use from `NewOptionPane::NewOptionPane`, range/value setters from `NewOptionPane::ApplyVolumeSettings`, and enable/disable from `NewOptionPane::UpdateSliderVisibility`.
- 2026-05-25 IDA MCP checks confirm the omitted helpers at `0x00564e30`, `0x005652a0`, and `0x00565360` are still absent from active generated source but form the internal mouse/focus interaction commit chain.
- 2026-05-26 IDA MCP recheck reconfirms the same helper chain: hit-test callers at `0x005649f1` and `0x0056530f`, commit callers at `0x00564a83` and `0x00564b28`, and notify callers at `0x005652fb` and `0x00565324`.
- 2026-05-26 IDA MCP confirms the three `ScrollVolumePane` vtable bases at `0x006240b4`, `0x00624100`, and `0x00624130`, including paint, mouse, false-return, and focus/commit slots, despite current Wave3 metadata reporting `vtable_count: 0`.
- The current active output emits the helper rows at `0x00564e30`, `0x005652a0`, and `0x00565360`, but all three are still surfaced with stale `TextEditPane::*` signatures even though the source map and IDA evidence attach them to `ScrollVolumePane`. It also includes raw projected starts, so use the memory page before migrating the class.
- 2026-06-03 restarted IDA MCP recheck reconfirmed raw helper starts `0x00565170`, `0x005651e0`, and `0x00565490` as non-modeled function-table gaps with no xrefs or raw pointer hits. It also reconfirmed the modeled neighbor helpers at `0x00565010`, `0x005652a0`, and `0x00565360`, the `0x005654ec`/`0x005654f7` neighboring `ScrollablePane` thunks, and the raw helper calls into `GetPartRect`, commit, timer start/stop, and invalidation slots.
- 2026-06-08 A008 IDA MCP recheck confirmed the modeled method starts/sizes, constructor stores to `+0xfc/+0xfe/+0x100/+0x102/+0x103/+0x104/+0x108`, vtable installs at `0x00564761`/`0x00564767`/`0x00564771`, constructor/setter callers from `NewOptionPane`, internal helper callers, and the neighboring `ScrollablePane` thunk boundary.
- The same pass split three previously undocumented raw helpers at `0x005647c0`, `0x005647f0`, and `0x005648f0`; all three are source-looking ScrollVolumePane methods with no direct xrefs and unresolved final names.

## Cross-References

- [UID:0000NK][ScrollVolumePane](by-file/ScrollVolumePane.md)
- [UID:0001H2][0x00564710-0x005654ec.ScrollVolumePane](by-memory/0x00564710-0x005654ec.ScrollVolumePane.md)
- [UID:00031M][0x005647c0-0x005647e7.ScrollVolumePaneSetLowStateWordRaw](by-memory/0x005647c0-0x005647e7.ScrollVolumePaneSetLowStateWordRaw.md)
- [UID:00031N][0x005647f0-0x00564814.ScrollVolumePaneSetStateByteRaw](by-memory/0x005647f0-0x00564814.ScrollVolumePaneSetStateByteRaw.md)
- [UID:00031O][0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw](by-memory/0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw.md)
- [UID:0001H3][0x00564e30-0x00565006.ScrollVolumePaneHitTestPart](by-memory/0x00564e30-0x00565006.ScrollVolumePaneHitTestPart.md)
- [UID:0002LB][0x00565170-0x005651e0.ScrollVolumePaneSetHighlightPartRaw](by-memory/0x00565170-0x005651e0.ScrollVolumePaneSetHighlightPartRaw.md)
- [UID:0002LC][0x005651e0-0x005652a0.ScrollVolumePaneBeginInteractionRaw](by-memory/0x005651e0-0x005652a0.ScrollVolumePaneBeginInteractionRaw.md)
- [UID:0001H4][0x005652a0-0x00565360.ScrollVolumePaneCommitInteraction](by-memory/0x005652a0-0x00565360.ScrollVolumePaneCommitInteraction.md)
- [UID:0001H5][0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange](by-memory/0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange.md)
- [UID:0002LD][0x00565490-0x005654ec.ScrollVolumePaneResetInteractionStateRaw](by-memory/0x00565490-0x005654ec.ScrollVolumePaneResetInteractionStateRaw.md)
- [UID:0001W2][ScrollVolumePaneLayout](by-type/by-struct/ScrollVolumePaneLayout.md)
- [UID:0001YT][ScrollVolumePaneVtables](by-type/by-vtable/ScrollVolumePaneVtables.md)
- [UID:0000M7][OptionPane](by-file/OptionPane.md)
- [UID:000097][NewOptionPane](by-class/NewOptionPane.md)
- [UID:0000A2][Pane](by-class/Pane.md)

## Changes

- 2026-05-30: Changed completion/confidence from `0/0` to `86/80`.
  - Before: The page was unevaluated despite extensive method, layout, vtable, caller, omitted-helper, and excluded-tail documentation.
  - After: Scored as high completion with strong-but-not-perfect confidence because behavior/source ownership are strong while several raw projected helper starts remain unmodeled by IDA.
  - Evidence: Existing method notes, excluded-tail section, layout notes, IDA caller/evidence notes, and exact by-memory/type cross-references support the score.
- 2026-05-30: Corrected the current recovered source path and active-output caveat.
  - Before: The page referenced the old flat `source-3/simroot_v2/class_ScrollVolumePane.cpp` path and described helper rows as omitted from active output.
  - After: The page points to `source-3/simroot_v2/ui/controls/class_ScrollVolumePane.cpp` and records that the helpers are emitted but still affected by stale `TextEditPane` signatures in generated code.
  - Evidence: Current `simroot_v2` file list, `class_ScrollVolumePane.cpp.source_map.json`, and `class_ScrollVolumePane.meta_wave3` report emitted path `ui\controls\class_ScrollVolumePane.cpp` and active methods `0x00564e30`, `0x005652a0`, and `0x00565360`.
- 2026-05-31: Marked the class reconstructable and replaced inline raw helper rows with exact UID-linked memory pages.
  - Before: The page listed `0x00565170`, `0x005651e0`, and `0x00565490` as inline projected raw spans only.
  - After: Those spans are first-class `by-memory` pages and the class page links to them without adding parent attachments or final C++.
  - Evidence: IDA MCP raw disassembly confirms the three helper-shaped ranges and their state effects, but confidence remains below the 95+ code/parent gate.
- 2026-06-03 parent attachment update:
  - Before: `AUTOGEN_PARENT_UID` was blank and confidence stayed at `80` despite the file parent already having a valid `NexusTK/ui/controls/` path.
  - Changed to: confidence `82`, `AUTOGEN_PARENT_UID:0000NK`, and position `10`; reconstruction C++ remains blank.
  - Evidence: the restarted IDA MCP recheck reconfirmed the raw helper gaps, modeled helper chain, and neighboring `ScrollablePane` thunk boundary, while [UID:0000NK][ScrollVolumePane](by-file/ScrollVolumePane.md) is already a validated controls source root.
- 2026-06-08 A008 Batch 137 strict-gate and child-split update:
  - Before: score was `86/82`, and the method inventory skipped three raw helper bodies near the constructor/setter cluster.
  - Changed to: score `87/85`; parent remains [UID:0000NK][ScrollVolumePane](by-file/ScrollVolumePane.md) at position `10`.
  - Evidence: live IDA MCP rechecked modeled boundaries, constructor field/vtable stores, constructor/setter/helper callers, vtable xrefs, neighboring destructor-thunk ownership, and the newly split raw helpers [UID:00031M][0x005647c0-0x005647e7.ScrollVolumePaneSetLowStateWordRaw](by-memory/0x005647c0-0x005647e7.ScrollVolumePaneSetLowStateWordRaw.md), [UID:00031N][0x005647f0-0x00564814.ScrollVolumePaneSetStateByteRaw](by-memory/0x005647f0-0x00564814.ScrollVolumePaneSetStateByteRaw.md), and [UID:00031O][0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw](by-memory/0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw.md). The parent file is now also `88/85`, satisfying the strict parent gate.
