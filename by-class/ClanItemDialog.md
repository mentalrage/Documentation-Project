*** UID:00002F | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000I9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ClanItemDialog

## Status

- Confidence: strong for exact validated child methods, destructor links, vtable-family identity, and ClanBank source placement; medium for raw constructor reachability and final source-level base/member names.
- Likely source file: [UID:0000I9][ClanBank](by-file/ClanBank.md)
- Reconstruction parent: [UID:0000I9][ClanBank](by-file/ClanBank.md)

## Score Rationale

- Completion `82`: raised from `74` after the 2026-06-05 live IDA pass reconfirmed the raw constructor bytes, exact destructor-tail and confirm-callback function sizes, scalar deleting destructor range, vtable data refs, destructor adjustor thunks, and control/text validation behavior. It remains below final-source range because constructor reachability, exact member/control names, and base destructor source spelling are still open.
- Confidence `88`: strong for class identity, byte boundaries, ClanItemDialog vtable stores, child ownership, and [UID:0000I9][ClanBank](by-file/ClanBank.md) placement. It stays below `95` because the constructor start is still not an IDA function and the final C++ layout is not ready.

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
- 2026-06-05 live IDA MCP used `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, SHA256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
- `lookup_funcs` still reports no function at `0x0048a0c0`, while `0x0048a100` is size `0x1f`, `0x0048a120` is size `0x9e`, and `0x0048c470` is size `0x55`.
- Bounded raw disassembly reconfirms the constructor-shaped bytes at `0x0048a0c0-0x0048a0fb`: call `0x0049d8a0` / [UID:00012R][0x0049d8a0-0x0049feae.DialogPane](by-memory/0x0049d8a0-0x0049feae.DialogPane.md) with the blank wide-title pointer at `0x0060db20`, mode args `-1` and `1`, then store vtables `0x00615fdc`, `0x00616040`, and `0x00616070`, return with `retn 4`, and stop before `0xcc` padding.
- `xrefs_to` shows no inbound xrefs to raw start `0x0048a0c0`; vtable data refs tie the same three `ClanItemDialog` vtables to the raw constructor, the destructor tail at `0x0048a100`, sibling reset helpers at `0x0048a690` and `0x0048acf0`, and scalar deleting destructor `0x0048c470`.
- `xrefs_to(0x0048a120)` reports vtable data refs at `0x00616028`, `0x006160c8`, and `0x00616168`. `callees(0x0048a120)` reports [UID:0002OA][0x00498c10-0x00498c1f.TextEditControlPaneReadTextForwarder](by-memory/0x00498c10-0x00498c1f.TextEditControlPaneReadTextForwarder.md) and `@__security_check_cookie@4`.
- Destructor adjustor thunks at `0x0048c2d3` and `0x0048c2de` subtract `0xa0` and `0xa4`, then jump to `0x0048c470`; the scalar deleting destructor resets the same three vtables, calls base cleanup, and conditionally frees the block.

## Cross-References

- [UID:0000I9][ClanBank](by-file/ClanBank.md)
- [UID:00012R][0x0049d8a0-0x0049feae.DialogPane](by-memory/0x0049d8a0-0x0049feae.DialogPane.md)
- [UID:00021X][0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor](by-memory/0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor.md)
- [UID:00010N][0x0048a100-0x0048a1be.ClanItemDialogCore](by-memory/0x0048a100-0x0048a1be.ClanItemDialogCore.md)
- [UID:0002OC][0x0048a100-0x0048a11f.ClanItemDialogVtableResetDestructorTail](by-memory/0x0048a100-0x0048a11f.ClanItemDialogVtableResetDestructorTail.md)
- [UID:0002OB][0x0048a120-0x0048a1be.ClanItemDialogConfirmValidation](by-memory/0x0048a120-0x0048a1be.ClanItemDialogConfirmValidation.md)
- [UID:0002OA][0x00498c10-0x00498c1f.TextEditControlPaneReadTextForwarder](by-memory/0x00498c10-0x00498c1f.TextEditControlPaneReadTextForwarder.md)
- [UID:00010T][0x0048c260-0x0048c63f.ClanDestructorBand](by-memory/0x0048c260-0x0048c63f.ClanDestructorBand.md)
- [UID:0001X9][ClanDialogVtableFamily](by-type/by-vtable/ClanDialogVtableFamily.md)
- [UID:000029][ClanDepItemDialog](by-class/ClanDepItemDialog.md)
- [UID:00002N][ClanWidItemDialog](by-class/ClanWidItemDialog.md)

## Changes

- 2026-05-27: Changed constructor documentation from an unbounded projected `0x0048a0c0-0x0048a0fa` range to bounded raw constructor [UID:00021X][0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor](by-memory/0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor.md). Evidence: IDA MCP reports no function at `0x0048a0c0`, but the bytes form a complete constructor-shaped body ending at `0x0048a0fb`, followed by `0xcc` alignment before `0x0048a100`.
- What existed before: the page documented shared clan item-dialog validation behavior and raw constructor bounding, but metadata was still `0/0`.
- What it was changed to: scores were set to `70/78`.
- Summary and evidence: `OnConfirm`, vtable reset, destructor, and raw constructor shape are documented; constructor reachability and final base/dialog field layout remain unresolved.
- 2026-05-31: Split the core method references into exact child pages and updated metadata.
  - What existed before: `0x0048a100` and `0x0048a120` were raw address notes under the aggregate core page, and reconstructable metadata was blank.
  - Changed to: linked exact child pages, marked `RECONSTRUCTABLE:TRUE`, and set scores to `74/84`.
  - Summary and evidence: IDA MCP verified the vtable-reset helper size, confirm-callback size, vtable references, text-control forwarder callee, and padding around the child ranges.
- 2026-06-05: Raised from `74/84` to `82/88` and attached to [UID:0000I9][ClanBank](by-file/ClanBank.md).
  - What existed before: the class page had exact child links, but the class itself was below the parent-attachment threshold and still listed stale source-lead provenance.
  - Changed to: added score rationale, live IDA executable identity, raw constructor byte evidence, destructor-tail and confirm-callback verification, destructor thunk/scalar-destructor evidence, vtable-family refs, and source-parent routing.
  - Summary and evidence: live IDA MCP on 2026-06-05 reconfirmed exact function sizes, no-function/no-xref status for `0x0048a0c0`, vtable data refs, control ids, text-control callee, and destructor thunk flow. C++ remains blank under the final-source gate.
