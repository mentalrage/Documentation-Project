*** UID:0001W2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000CO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ScrollVolumePaneLayout

## Status

- Confidence: strong for local tail fields, object size, raw setter/predicate evidence, and direct owner; base class layout remains inherited from `Pane`/`ScrollablePane` views.
- Direct owner: [UID:0000CO][ScrollVolumePane](by-class/ScrollVolumePane.md), with source file [UID:0000NK][ScrollVolumePane](by-file/ScrollVolumePane.md)
- Primary memory evidence: [UID:0001H2][0x00564710-0x005654ec.ScrollVolumePane](by-memory/0x00564710-0x005654ec.ScrollVolumePane.md)
- Vtable evidence: [UID:0001YT][ScrollVolumePaneVtables](by-type/by-vtable/ScrollVolumePaneVtables.md)
- Size evidence: IDA decompilation of `NewOptionPane::NewOptionPane` allocates `272` bytes twice before calling the `ScrollVolumePane` constructor, confirming a `0x110` object size.

## Layout Hypothesis

`ScrollVolumePane` extends `Pane` and exposes three vtable views. The confirmed local state lives near the end of the object:

| Offset | Size | Observed field | Evidence |
| --- | --- | --- | --- |
| `+0x00` | 4 | primary vtable | Constructor writes `ScrollVolumePane` vtable. |
| `+0xa0` | 4 | secondary vtable | Constructor writes second `ScrollVolumePane` vtable. |
| `+0xa4` | 4 | tertiary vtable / timer-handler view | Constructor writes third vtable; timer calls use `this + 0xa4`. |
| `+0x44` | 16 | bounds rectangle | Setters invalidate through vtable slot using `this + 0x44`; geometry helpers read the same rectangle. |
| `+0xf8` | 2 | unresolved low state word | Constructor initializes the containing dword to `0x00010000`; [UID:00031M][0x005647c0-0x005647e7.ScrollVolumePaneSetLowStateWordRaw](by-memory/0x005647c0-0x005647e7.ScrollVolumePaneSetLowStateWordRaw.md) compares/writes this word and invalidates the bounds rect when changed. |
| `+0xfa` | 1 | initialized state byte | Constructor sets it to `1` through the packed dword store; [UID:00031N][0x005647f0-0x00564814.ScrollVolumePaneSetStateByteRaw](by-memory/0x005647f0-0x00564814.ScrollVolumePaneSetStateByteRaw.md) compares/writes this byte and invalidates the bounds rect when changed. |
| `+0xfb` | 1 | drag-position override flag | Paint, hit-test, and geometry helpers check this byte before using the stored drag offset. |
| `+0xfc` | 1 | `volumeType` | Constructor stores the argument; value-change helper passes it to option-pane callback. |
| `+0xfe` | 2 | current value | `SetValue` writes this word; `SetRange` clamps it. |
| `+0x100` | 2 | max value/range | `SetRange` writes this word; paint/geometry divide by it. |
| `+0x102` | 1 | enabled byte | Constructor initializes it to `1`; `Enable`/`Disable` mutate it. |
| `+0x103` | 1 | highlighted part | Highlight helpers read/write `0xff` sentinel and invalidate old/new part rectangles. |
| `+0x104` | 1 | active interaction part | Mouse handlers use `0xff` sentinel; raw reset helper clears it. |
| `+0x108` | 8 | mouse reference / drag-offset point | Constructor clears the point; drag-start raw helper stores the mouse-to-thumb offset through `InitPoint`-style helper `0x004b7c30`. |
| `+0x10c` | 4 | drag offset | Drag path clamps this to the track length and converts it into current value. |

## State Values

Known slider part codes:

| Code | Meaning |
| --- | --- |
| `0` | collapsed top edge/arrow region |
| `1` | track above thumb |
| `2` | thumb |
| `3` | track below thumb |
| `4` | collapsed bottom edge/arrow region |
| `0xff` | no highlighted or active part |

## Evidence Notes

- `NewOptionPane::NewOptionPane` (`0x0053ff90`) allocates `272` bytes twice and calls `0x00564710(v10, 1)` at `0x00540097` and `0x00564710(v12, 0)` at `0x005400c6`, confirming the object size and the two option sliders.
- Constructor decompilation writes `+0xfc`, clears the current/range dword at `+0xfe`, initializes `+0xf8` to `0x00010000`, writes `+0x102/+0x103` through a packed word, writes `+0x104 = 0xff`, clears the point at `+0x108`, and installs vtable bases at `+0`, `+0xa0`, and `+0xa4`.
- 2026-06-08 A008 IDA MCP disassembly split three additional raw helper spans: [UID:00031M][0x005647c0-0x005647e7.ScrollVolumePaneSetLowStateWordRaw](by-memory/0x005647c0-0x005647e7.ScrollVolumePaneSetLowStateWordRaw.md) writes word `+0xf8`, [UID:00031N][0x005647f0-0x00564814.ScrollVolumePaneSetStateByteRaw](by-memory/0x005647f0-0x00564814.ScrollVolumePaneSetStateByteRaw.md) writes byte `+0xfa`, and [UID:00031O][0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw](by-memory/0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw.md) tests enabled byte `+0x102` plus positive range word `+0x100`.
- `SetRange` uses `this[127]` and `this[128]`, matching words at `+0xfe` and `+0x100`.
- `Enable` and `Disable` read/write byte `+0x102`.
- Paint, `GetPartRect`, hit-test, and value-change helpers use `+0xfb`, `+0xfe`, `+0x100`, `+0x102`, `+0x103`, `+0x104`, and the `+0x108/+0x10c` point/offset fields with the fixed 38-pixel thumb height and `SCRBUTT2.EPF`.
- Raw helper pages now cover `0x00565170`, `0x005651e0`, and `0x00565490`, confirming highlight, active-part, drag-offset, and reset-state use independently of generated Wave3 method names.
- IDA xrefs confirm vtable bases `0x006240b4`, `0x00624100`, and `0x00624130` installed by the constructor.

## Assignment Gate

Assigned to direct owner [UID:0000CO][ScrollVolumePane](by-class/ScrollVolumePane.md). The layout is now `85/86`, the class parent is `87/85`, and the file parent [UID:0000NK][ScrollVolumePane](by-file/ScrollVolumePane.md) is `88/85`, so the strict child/direct-parent gate is satisfied. Reconstruction C++ remains blank because this is a layout evidence page and several field/source names are still below final-audit quality.

## Cross-References

- [UID:0000NK][ScrollVolumePane](by-file/ScrollVolumePane.md)
- [UID:0000CO][ScrollVolumePane](by-class/ScrollVolumePane.md)
- [UID:0001H2][0x00564710-0x005654ec.ScrollVolumePane](by-memory/0x00564710-0x005654ec.ScrollVolumePane.md)
- [UID:0001YT][ScrollVolumePaneVtables](by-type/by-vtable/ScrollVolumePaneVtables.md)
- [UID:00031M][0x005647c0-0x005647e7.ScrollVolumePaneSetLowStateWordRaw](by-memory/0x005647c0-0x005647e7.ScrollVolumePaneSetLowStateWordRaw.md)
- [UID:00031N][0x005647f0-0x00564814.ScrollVolumePaneSetStateByteRaw](by-memory/0x005647f0-0x00564814.ScrollVolumePaneSetStateByteRaw.md)
- [UID:00031O][0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw](by-memory/0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw.md)
- [UID:0000M7][OptionPane](by-file/OptionPane.md)

## Changes

- 2026-05-31: Changed completion/confidence from `0/0` to `78/84` and marked the layout reconstructable.
  - Before: The page used metadata size evidence and treated the packed `+0xf8` dword as a single field.
  - After: The page records IDA allocation evidence for the `0x110` object size, splits the packed `+0xf8..+0xfb` state, and ties the tail fields to constructor, setter, paint, hit-test, raw helper, and callback decompilation evidence.
  - Evidence: IDA MCP checks of `NewOptionPane::NewOptionPane`, `ScrollVolumePane` constructor/setters/paint/hit-test/commit/value-change helpers, raw helper disassembly at `0x00565170`, `0x005651e0`, `0x00565490`, and vtable xrefs.
- 2026-06-08 A008 Batch 137 strict-gate and raw-field update:
  - Before: score was `78/84`, and the layout page did not link the raw helpers that write `+0xf8`, `+0xfa`, or test enabled/range state.
  - Changed to: score `85/86` and `AUTOGEN_PARENT_UID:0000CO`.
  - Evidence: live IDA MCP rechecked constructor allocation/field stores, vtable install xrefs, caller edges from `NewOptionPane`, internal helper callers, and the newly split raw helpers [UID:00031M][0x005647c0-0x005647e7.ScrollVolumePaneSetLowStateWordRaw](by-memory/0x005647c0-0x005647e7.ScrollVolumePaneSetLowStateWordRaw.md), [UID:00031N][0x005647f0-0x00564814.ScrollVolumePaneSetStateByteRaw](by-memory/0x005647f0-0x00564814.ScrollVolumePaneSetStateByteRaw.md), and [UID:00031O][0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw](by-memory/0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw.md). [UID:0000CO][ScrollVolumePane](by-class/ScrollVolumePane.md) and [UID:0000NK][ScrollVolumePane](by-file/ScrollVolumePane.md) now also meet the strict `85/85` parent gate.
