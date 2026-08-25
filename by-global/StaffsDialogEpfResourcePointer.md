*** UID:0002ZI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000O3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000O3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static const wchar_t *kStaffsDialogEpfName = L"STAFF.EPF";

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# StaffsDialogEpfResourcePointer

## Status

- Address: `0x0066db44`
- Exact storage: `by-memory/0x0066db44-0x0066db48.StaffsDialogEpfResourcePointer.md`.
- Current IDA name: `off_66DB44`.
- Target: UTF-16 `STAFF.EPF` at `0x0061e484` (`aStaffEpf`).
- Kind: source-declared pointer to a staff-dialog resource-name literal.
- Current source owner/emitter: [UID:0000O3][StaffsDialogPane](by-file/StaffsDialogPane.md), position `5`.
- Rebuild handling: one file-local pointer-to-const-wide-character definition, emitted once before the class/method source.

## Role

The StaffsDialogPane constructor uses this pointer for `STAFF.EPF` frame lookup, background image setup, display/resource registration, and frame-relative positioning. [UID:00019Z][0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore](by-memory/0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore.md) now emits formal constructor C++ using the source-facing resource-name constant `kStaffsDialogEpfName`; this page keeps the exact pointer/declaration audit separate from the method body.

## Evidence

- 2026-06-07 A007 IDA MCP reads `0x0066db44` as `0x0061e484`.
- The target bytes decode as UTF-16 `STAFF.EPF`.
- `xrefs_to 0x0066db44` reports five constructor refs inside `0x004ffaa0-0x004ffd1d`: `0x004ffb42`, `0x004ffb72`, `0x004ffb91`, `0x004ffba6`, and `0x004ffcb1`.
- The target literal is referenced only by this pointer slot; executable consumers use the `.data` pointer, not the read-only literal directly.
- UID00019Z B014 implementation also records the related `STAFFS2`/`STAFFS` event-bit branch in the constructor; the text-resource branch and this `STAFF.EPF` pointer are StaffsDialogPane source behavior, while missing resource payload provenance remains on [UID:0001RM][staff-dialog-resources](by-resource/staff-dialog-resources.md).

## Source Ownership

Keep this with StaffsDialogPane resource setup. The exact by-memory child can attach here because this page is a direct semantic parent at `85/85+`; broader file/class pages remain useful source context but do not need to be over-scored just to parent this pointer.

## Assignment Gate

- Current canonical owner/emitter is [UID:0000O3][StaffsDialogPane](by-file/StaffsDialogPane.md).
- This by-global definition is current `92/94`, and the direct source-file owner is current `92/93`; both exceed the assignment gate and emit in accepted source order at position `5`.
- 2026-06-07 A010 Batch077 live IDA refresh reconfirmed `0x0066db44 -> 0x0061e484`, UTF-16 `STAFF.EPF`, one literal xref from the pointer slot, and five pointer xrefs in the StaffsDialogPane constructor.

## Cross-References

- [UID:0000O3][StaffsDialogPane](by-file/StaffsDialogPane.md)
- [UID:0000DY][StaffsDialogPane](by-class/StaffsDialogPane.md)
- [UID:00019Z][0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore](by-memory/0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore.md)
- [UID:0001RM][staff-dialog-resources](by-resource/staff-dialog-resources.md)

## Changes

- 2026-07-21 B001 UID0001PT callback: raised `87/92` to `92/94`, set source position `5`, and inserted the exact one-definition source `static const wchar_t *kStaffsDialogEpfName = L"STAFF.EPF";`. The physical `.data` slot `0x0066db44` contains `0x0061e484`; the target UTF-16 literal has one pointer-slot xref, and all five executable consumers (`0x004ffb42`, `0x004ffb72`, `0x004ffb91`, `0x004ffba6`, `0x004ffcb1`) are in the Staffs constructor. This closes type, linkage, initializer, source order, and one-definition blockers while leaving the physical page non-emitting.
- Historical/superseded state: this page previously left declaration/linkage C++ blank and described the source form as merely proposed. Exact pointer storage and exclusive constructor use now support the accepted file-local definition; no array definition, shared resource table, or second emitted backing global is required.

- 2026-06-07 A010 Batch077: Set `AUTOGEN_PARENT_UID:0000O3` after refreshing [UID:0000O3][StaffsDialogPane](by-file/StaffsDialogPane.md) to `85/86`. This repairs generated coverage for memory child [UID:00027M][0x0066db44-0x0066db48.StaffsDialogEpfResourcePointer](by-memory/0x0066db44-0x0066db48.StaffsDialogEpfResourcePointer.md) without changing this page's `87/92` score.
- 2026-06-07 A007 Batch 052: Created exact by-global parent for the split StaffsDialogPane `STAFF.EPF` pointer after live IDA confirmed pointer value, target string, constructor xrefs, and separation from the adjacent MapPane `CMAP` pointer.
- 2026-07-03 B014 UID00019Z implementation sync: noted that the accepted constructor C++ now uses `kStaffsDialogEpfName` and the `STAFFS2`/`STAFFS` branch through [UID:00019Z][0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore](by-memory/0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore.md); pointer storage declaration C++ remains blank on this support page.
