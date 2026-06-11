*** UID:0000CS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SelectionState

## Status

- Disposition: ignored as a standalone class record; fold behavior into [UID:00007A][ListPane](by-class/ListPane.md).
- Confidence: strong that `0x004f3e20` is a `ListPane` selection helper; no current evidence supports `SelectionState` as an original independent class.
- Likely source file: [UID:0000KT][ListPane](by-file/ListPane.md)
- Address range: [UID:000194][0x004f3a50-0x004f4a77.ListPane](by-memory/0x004f3a50-0x004f4a77.ListPane.md)
- Current recovered file: `source-3/simroot_v2/class_SelectionState.cpp`

## Ownership Decision

`SelectionState` currently appears to be a generated alias over `ListPane` selection state, not an independent original class. Its only active method, `0x004f3e20`, reads the same `ListPane` layout used by neighboring helpers:

- `+0x134`: selected index;
- `+0x138`: selection flag list;
- `+0x13c`: multi-select/selection-mode byte.

The behavior is better named `ListPane::GetSelectionCount` and should be folded into [UID:00007A][ListPane](by-class/ListPane.md) unless later struct/vtable evidence proves a real separate helper class.

## Evidence Notes

- IDA MCP decompilation of `0x004f3e20` counts nonzero bytes in the `+0x138` selection flag list when byte `+0x13c` is set, otherwise it returns whether selected index `+0x134` is nonnegative.
- IDA caller fanout includes board, exchange, item-menu, spell-menu, server-select, phone-book, and other list users, matching a shared list selection helper.
- `source-3/simroot_v2/class_SelectionState.cpp` has no constructor, destructor, or independent field layout evidence.
- 2026-05-26 IDA `py_eval` recheck confirms `0x004f3e20-0x004f3e74` as a real helper with 14 xrefs, confirms neighboring `ListPane` selection helpers at `0x004f3dd0`, `0x004f3e80`, and `0x004f3f00`, and finds no IDA names containing `SelectionState`.
- The same IDA name pass shows `ListPane` vtables and RTTI (`??_7ListPane...`, `??_R4ListPane...`, `??_R0?AVListPane...`) plus many derived list-pane RTTI records, supporting `ListPane` ownership for this helper.

## Cross-References

- [UID:00007A][ListPane](by-class/ListPane.md)
- [UID:0000KT][ListPane](by-file/ListPane.md)
- [UID:000194][0x004f3a50-0x004f4a77.ListPane](by-memory/0x004f3a50-0x004f4a77.ListPane.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- 2026-06-05: Changed `RECONSTRUCTABLE` from blank to `FALSE` and left `AUTOGEN_PARENT_UID` blank.
  - Before: The generated `SelectionState` alias still appeared unclassified in autogen coverage.
  - After: The standalone class record is classified as not reconstructable; the source behavior belongs to `ListPane`, not a separate original class.
  - Evidence: Live IDA MCP lookup confirms the only active helper at `0x004f3e20`; existing ownership notes document it as `ListPane` selection-count behavior with no constructor, destructor, vtable, or independent layout evidence.

- 2026-05-30: Changed completion/confidence from `0/0` to `-1/-1`.
  - Before: The page was still appearing in generated low-score stats even though its status and coverage row already mark it ignored as a standalone class.
  - After: Excluded it from scoring so the queue focuses on reconstructable documents.
  - Evidence: Existing ownership decision, by-class ignored ledger, and `by-class/-coverage-report.md` identify this as a generated alias for `ListPane::GetSelectionCount`, not an independent original class.
