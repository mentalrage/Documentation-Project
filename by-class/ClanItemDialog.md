*** UID:00002F | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ClanItemDialog

## Status

- Confidence: strong for exact validated child methods and destructor links; medium for raw constructor reachability and final source-level base/member names.
- Likely source file: [UID:0000I9][ClanBank](by-file/ClanBank.md)
- Current recovered file: `source-3/simroot_v2/class_ClanItemDialog.cpp`

## Class Purpose

`ClanItemDialog` is the shared item-selection dialog base used by clan item deposit/withdraw flows. Its confirmed behavior validates that an item row is selected and that the quantity/text control is non-empty before enabling the confirm action.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| raw constructor | [UID:00021X][0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor](by-memory/0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor.md) | Constructor-shaped bytes that call the base setup path and install `ClanItemDialog` vtables; IDA reports no function at `0x0048a0c0`. |
| vtable-reset helper | [UID:0002OC][0x0048a100-0x0048a11f.ClanItemDialogVtableResetDestructorTail](by-memory/0x0048a100-0x0048a11f.ClanItemDialogVtableResetDestructorTail.md) | Real IDA function; resets `ClanItemDialog` vtables and jumps into base cleanup. |
| `OnConfirm` | [UID:0002OB][0x0048a120-0x0048a1be.ClanItemDialogConfirmValidation](by-memory/0x0048a120-0x0048a1be.ClanItemDialogConfirmValidation.md) | Reads controls `1`, `5`, and `6`; enables confirm only when a selection exists and text-control content is non-empty. |
| destructor/thunks | `0x0048c2d3`, `0x0048c2de`, `0x0048c470-0x0048c4c4` | Vtable thunks and scalar deleting destructor through `TransferReplyAlert`. |

## Evidence Notes

- IDA confirms `0x0048a100`, `0x0048a120`, and `0x0048c470`.
- IDA rejects `0x0048a0c0` as a function start, but 2026-05-27 byte-level audit bounded [UID:00021X][0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor](by-memory/0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor.md) as a constructor-shaped body that stores `ClanItemDialog` vtables at `0x0048a0d8`, `0x0048a0e0`, and `0x0048a0ea`.
- 2026-05-31 IDA MCP recheck split the core methods into exact pages: [UID:0002OC][0x0048a100-0x0048a11f.ClanItemDialogVtableResetDestructorTail](by-memory/0x0048a100-0x0048a11f.ClanItemDialogVtableResetDestructorTail.md) and [UID:0002OB][0x0048a120-0x0048a1be.ClanItemDialogConfirmValidation](by-memory/0x0048a120-0x0048a1be.ClanItemDialogConfirmValidation.md). The confirm method calls [UID:0002OA][0x00498c10-0x00498c1f.TextEditControlPaneReadTextForwarder](by-memory/0x00498c10-0x00498c1f.TextEditControlPaneReadTextForwarder.md), proving the quantity/text read is through reusable text-control code.

## Cross-References

- [UID:0000I9][ClanBank](by-file/ClanBank.md)
- [UID:00021X][0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor](by-memory/0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor.md)
- [UID:00010N][0x0048a100-0x0048a1be.ClanItemDialogCore](by-memory/0x0048a100-0x0048a1be.ClanItemDialogCore.md)
- [UID:0002OC][0x0048a100-0x0048a11f.ClanItemDialogVtableResetDestructorTail](by-memory/0x0048a100-0x0048a11f.ClanItemDialogVtableResetDestructorTail.md)
- [UID:0002OB][0x0048a120-0x0048a1be.ClanItemDialogConfirmValidation](by-memory/0x0048a120-0x0048a1be.ClanItemDialogConfirmValidation.md)
- [UID:00010T][0x0048c260-0x0048c63f.ClanDestructorBand](by-memory/0x0048c260-0x0048c63f.ClanDestructorBand.md)
- [UID:000029][ClanDepItemDialog](by-class/ClanDepItemDialog.md)
- [UID:00002N][ClanWidItemDialog](by-class/ClanWidItemDialog.md)

## Changes

- 2026-05-27: Changed constructor documentation from unbounded Wave3 projected `0x0048a0c0-0x0048a0fa` to bounded raw constructor [UID:00021X][0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor](by-memory/0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor.md). Evidence: IDA MCP reports no function at `0x0048a0c0`, but the bytes form a complete constructor-shaped body ending at `0x0048a0fb`, followed by `0xcc` alignment before `sub_48A100`.
- What existed before: the page documented shared clan item-dialog validation behavior and raw constructor bounding, but metadata was still `0/0`.
- What it was changed to: scores were set to `70/78`.
- Summary and evidence: `OnConfirm`, vtable reset, destructor, and raw constructor shape are documented; constructor reachability and final base/dialog field layout remain unresolved.
- 2026-05-31: Split the core method references into exact child pages and updated metadata.
  - What existed before: `0x0048a100` and `0x0048a120` were raw address notes under the aggregate core page, and reconstructable metadata was blank.
  - Changed to: linked exact child pages, marked `RECONSTRUCTABLE:TRUE`, and set scores to `74/84`.
  - Summary and evidence: IDA MCP verified the vtable-reset helper size, confirm-callback size, vtable references, text-control forwarder callee, and padding around the child ranges.
