*** UID:0000AW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000MT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ProgressBarControlPane

## Status

- Confidence: strong for constructor and draw virtual, medium for private helper names.
- Likely source file: [UID:0000MT][ProgressBarControlPane](by-file/ProgressBarControlPane.md)
- Current recovered file: `source-3/simroot_v2/class_ProgressBarControlPane.cpp`
- Vtables: [UID:0001YH][ProgressBarControlPaneVtables](by-type/by-vtable/ProgressBarControlPaneVtables.md) at `0x00617b34`, `0x00617b9c`, and `0x00617bcc`

## Class Purpose

`ProgressBarControlPane` is a `ControlPane`-derived progress indicator. It stores a lower bound, current value, and upper bound, clamps public range input to `0..30000`, invalidates the pane when state changes, and paints a horizontal filled/empty bar with a frame.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| projected range-start setter | [UID:000115][0x00494a90-0x00494ae7.ProgressBarControlPaneRangeStartSetter](by-memory/0x00494a90-0x00494ae7.ProgressBarControlPaneRangeStartSetter.md) | Clamps the incoming value, writes field `0xf8`, raises current field `0xfa` if needed, and invalidates. IDA does not currently model this as a function. |
| projected range-end setter | [UID:000117][0x00494af0-0x00494b4b.ProgressBarControlPaneRangeEndSetter](by-memory/0x00494af0-0x00494b4b.ProgressBarControlPaneRangeEndSetter.md) | Clamps the incoming value, writes field `0xfc`, lowers current field `0xfa` if needed, and invalidates. IDA does not currently model this as a function. |
| `ProgressBarControlPane` | [UID:000119][0x00494c80-0x00494daa.ProgressBarControlPaneConstructor](by-memory/0x00494c80-0x00494daa.ProgressBarControlPaneConstructor.md) | Constructs the control with type `22`, installs progress-bar vtables, clamps initial range fields, and resets current value to `0`. |
| projected current-value adder | [UID:00011A][0x00494db0-0x00494dde.ProgressBarControlPaneCurrentValueAdder](by-memory/0x00494db0-0x00494dde.ProgressBarControlPaneCurrentValueAdder.md) | Adds a 16-bit delta into current field `0xfa` and invalidates if changed. IDA does not currently model this as a function. |
| `DrawProgressBar` | [UID:00011C][0x00494de0-0x00494eb0.ProgressBarControlPaneDrawProgressBar](by-memory/0x00494de0-0x00494eb0.ProgressBarControlPaneDrawProgressBar.md) | Computes the filled width from current/range fields and draws filled, empty, and frame regions. |

## Evidence Notes

- `source-3/simroot_v2/class_ProgressBarControlPane.cpp` emits the constructor and draw virtual.
- IDA confirms `0x00494c80` has one direct caller, `PatchPane::PatchPane` at `0x005472d7`.
- IDA confirms the draw routine is a vtable target at `0x00617b78`.
- 2026-05-26 IDA MCP vtable pass confirms primary/secondary/tertiary vtables at `0x00617b34`, `0x00617b9c`, and `0x00617bcc`, installed by constructor stores at `0x00494cc5`, `0x00494ccb`, and `0x00494cd5`.
- The three projected helpers touch the same field triplet (`0xf8`, `0xfa`, `0xfc`) and use the same vtable `+0x20` invalidation pattern as the constructor.
- Current generated metadata records a stored constructor-name control-character issue; treat the active emitted source name as cleaned, but keep the data issue tracked.
- 2026-05-26 recheck: IDA MCP still reports `0x00494a90`, `0x00494af0`, and `0x00494db0` as `Not a function`, with no direct xrefs. Keep them as projected private helper bytes under this class, not ignored/runtime code.
- 2026-06-01 byte recheck confirms the two range-setter helper bodies end at `0x00494ae7` and `0x00494b4b`, with only `0xcc` alignment between/after them.

## Cross-References

- [UID:0000MT][ProgressBarControlPane](by-file/ProgressBarControlPane.md)
- [UID:0001YH][ProgressBarControlPaneVtables](by-type/by-vtable/ProgressBarControlPaneVtables.md)
- [UID:000116][0x00494a90-0x00494b4b.ProgressBarRangeSetters](by-memory/0x00494a90-0x00494b4b.ProgressBarRangeSetters.md)
- [UID:000119][0x00494c80-0x00494daa.ProgressBarControlPaneConstructor](by-memory/0x00494c80-0x00494daa.ProgressBarControlPaneConstructor.md)
- [UID:00011A][0x00494db0-0x00494dde.ProgressBarControlPaneCurrentValueAdder](by-memory/0x00494db0-0x00494dde.ProgressBarControlPaneCurrentValueAdder.md)
- [UID:00011C][0x00494de0-0x00494eb0.ProgressBarControlPaneDrawProgressBar](by-memory/0x00494de0-0x00494eb0.ProgressBarControlPaneDrawProgressBar.md)
- [UID:000038][ControlPane](by-class/ControlPane.md)
- [UID:0000A9][PatchPane](by-class/PatchPane.md)

## Changes

- 2026-05-30: Changed completion/confidence from `0/0` to `82/78`.
  - Before: The page was unevaluated despite documenting constructor, draw behavior, range fields, vtables, and helper caveats.
  - After: Scored as high completion with medium-high confidence because several helper byte ranges remain projected private helpers rather than IDA-modeled functions.
  - Evidence: Existing method notes, field descriptions, IDA MCP vtable pass, and function-boundary caveats document the class behavior and remaining uncertainty.
- 2026-06-01: Marked the class reconstructable and attached it to the `ProgressBarControlPane` source-file page.
  - Before: validator autogen metadata was blank.
  - After: `RECONSTRUCTABLE:TRUE`, parent UID `0000MT`, and position `10`; no C++ code is emitted.
  - Evidence: constructor, draw virtual, vtables, and projected helper bytes are all documented as NexusTK-owned progress-bar control code, but final-source code still requires higher confidence and completion.
