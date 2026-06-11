*** UID:0002ZI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000O3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# StaffsDialogEpfResourcePointer

## Status

- Address: `0x0066db44`
- Exact storage: `by-memory/0x0066db44-0x0066db48.StaffsDialogEpfResourcePointer.md`.
- Current IDA name: `off_66DB44`.
- Target: UTF-16 `STAFF.EPF` at `0x0061e484` (`aStaffEpf`).
- Kind: source-declared pointer to a staff-dialog resource-name literal.
- Proposed source owner: [UID:0000O3][StaffsDialogPane](by-file/StaffsDialogPane.md).
- Rebuild handling: source-declared pointer or equivalent address-taken resource constant.

## Role

The StaffsDialogPane constructor uses this pointer for `STAFF.EPF` frame lookup, background image setup, display/resource registration, and frame-relative positioning.

## Evidence

- 2026-06-07 A007 IDA MCP reads `0x0066db44` as `0x0061e484`.
- The target bytes decode as UTF-16 `STAFF.EPF`.
- `xrefs_to 0x0066db44` reports five constructor refs inside `0x004ffaa0-0x004ffd1d`: `0x004ffb42`, `0x004ffb72`, `0x004ffb91`, `0x004ffba6`, and `0x004ffcb1`.
- The target literal is referenced only by this pointer slot; executable consumers use the `.data` pointer, not the read-only literal directly.

## Source Ownership

Keep this with StaffsDialogPane resource setup. The exact by-memory child can attach here because this page is a direct semantic parent at `85/85+`; broader file/class pages remain useful source context but do not need to be over-scored just to parent this pointer.

## Assignment Gate

- `AUTOGEN_PARENT_UID` is set to [UID:0000O3][StaffsDialogPane](by-file/StaffsDialogPane.md).
- This by-global parent is `87/92`, and the direct source-file parent is now `85/86`, so both sides clear the corrected `85/85` assignment gate.
- 2026-06-07 A010 Batch077 live IDA refresh reconfirmed `0x0066db44 -> 0x0061e484`, UTF-16 `STAFF.EPF`, one literal xref from the pointer slot, and five pointer xrefs in the StaffsDialogPane constructor.

## Cross-References

- [UID:0000O3][StaffsDialogPane](by-file/StaffsDialogPane.md)
- [UID:0000DY][StaffsDialogPane](by-class/StaffsDialogPane.md)
- [UID:00019Z][0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore](by-memory/0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore.md)
- [UID:0001RM][staff-dialog-resources](by-resource/staff-dialog-resources.md)

## Changes

- 2026-06-07 A010 Batch077: Set `AUTOGEN_PARENT_UID:0000O3` after refreshing [UID:0000O3][StaffsDialogPane](by-file/StaffsDialogPane.md) to `85/86`. This repairs generated coverage for memory child [UID:00027M][0x0066db44-0x0066db48.StaffsDialogEpfResourcePointer](by-memory/0x0066db44-0x0066db48.StaffsDialogEpfResourcePointer.md) without changing this page's `87/92` score.
- 2026-06-07 A007 Batch 052: Created exact by-global parent for the split StaffsDialogPane `STAFF.EPF` pointer after live IDA confirmed pointer value, target string, constructor xrefs, and separation from the adjacent MapPane `CMAP` pointer.
