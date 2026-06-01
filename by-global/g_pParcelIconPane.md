*** UID:0000RX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pParcelIconPane

## Status

- Address: `0x0069b4d0`
- IDA name: `dword_69B4D0`
- Likely type: `ParcelIconPane*`
- Likely owner file: [UID:0000MF][ParcelPane](by-file/ParcelPane.md)
- Confidence: strong

## Purpose

`g_pParcelIconPane` stores the active outer parcel notification icon pane. It is distinct from [UID:0000RY][g_pParcelPane](by-global/g_pParcelPane.md), which points at the embedded child pane that renders the two parcel/letter slots.

## Evidence

- 2026-05-25 IDA MCP xrefs to `0x0069b4d0` include a read in `sub_5047F0` at `0x005048d5`, writes in `ParcelIconPane` constructor `0x00545e40`, clears in non-deleting destructor `0x00546070`, clear helper `0x00546e70`, and scalar deleting destructor `0x00546f40`.
- `ParcelIconPane` destructor paths dismiss the associated child pane before clearing this singleton, matching ownership of the outer icon object rather than the child [UID:0000A6][ParcelPane](by-class/ParcelPane.md).

## 2026-05-30 Review Notes

- IDA MCP `py_eval` on 2026-05-30 confirms `0x0069b4d0` is `dword_69B4D0`, size `4`, in `.data`, with 6 data xrefs.
- Live IDA xrefs confirm the shutdown/main-UI reader at `0x005048d5` in `sub_5047F0`, constructor writes at `0x00545e91` and `0x00545e98` in `sub_545E40`, destructor clear at `0x005460c9` in `sub_546070`, singleton clear at `0x00546e70` in `sub_546E70`, and scalar deleting destructor clear at `0x00546fa0` in `sub_546F40`.
- This slot is distinct from `0x0069b4d4`, which live IDA names `dword_69B4D4` and existing docs identify as [UID:0000SB][g_pSoundStatusPane](by-global/g_pSoundStatusPane.md), not `g_pParcelPane`.
- Completion remains below full because the shutdown/main-UI reader at `0x005048d5` still needs a precise source-level owner/name.

## Ownership Decision

Declare this with the parcel notification module. Keep it separate from `g_pParcelPane` so source migration preserves the two-object lifetime model.

## Cross-References

- [UID:0000MF][ParcelPane](by-file/ParcelPane.md)
- [UID:0000A5][ParcelIconPane](by-class/ParcelIconPane.md)
- [UID:0001EG][0x00545e40-0x0054606a.ParcelIconPaneConstructor](by-memory/0x00545e40-0x0054606a.ParcelIconPaneConstructor.md)
- [UID:0001EO][0x00546f40-0x00546ff9.ParcelIconPaneScalarDeletingDestructor](by-memory/0x00546f40-0x00546ff9.ParcelIconPaneScalarDeletingDestructor.md)
- [UID:0001EH][0x00545e40-0x005470ac.ParcelNotificationPanes](by-memory/0x00545e40-0x005470ac.ParcelNotificationPanes.md)
- [UID:0000RY][g_pParcelPane](by-global/g_pParcelPane.md)

## Changes

- Before: completion/confidence were ungraded at `0/0`, and Evidence included generated-data placement.
- Changed to: completion `78`, confidence `86`; generated-data placement was removed from Evidence.
- Summary/evidence: live IDA MCP on 2026-05-30 verified exact storage, size, segment, 6 xrefs, constructor/destructor/clear-helper writes, and the main-UI reader. Completion remains below full until the main-UI reader source-level owner is named.
