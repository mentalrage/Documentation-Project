*** UID:0000SL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000OW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pTransferServerDialog

## Status

- Confidence: strong for address and role.
- Address: `0x0069b4b0`
- Current IDA name: `dword_69B4B0`
- Proposed owner file: [UID:0000OW][TransferServerDialogPane](by-file/TransferServerDialogPane.md)

## Symbol Role

`g_pTransferServerDialog` tracks the active animated transfer-server overlay. The constructor stores the active pane pointer, helper/destructor paths clear it, and login/map/session code reads or clears it when showing, resetting, or dismissing the `TRANSSVR` transfer overlay.

## IDA MCP Evidence

Checked on 2026-05-24:

- `xrefs_to 0x0069b4b0` reports constructor stores at `0x00598f21` and `0x00598f28`.
- Non-deleting destructor helper `0x00599220` clears the global at `0x0059923a`.
- Helper `0x005993b0` clears the global directly, and scalar deleting destructor `0x005993e0` clears it at `0x00599400`.
- External users include main-menu/login flow around `0x004f7460`, `0x004f7497`, `0x004f8f55`; map/session transfer paths around `0x00506f81`, `0x00507d38`, `0x00507d9b`, `0x0050ff3d`, `0x0050ffa0`, `0x00510271`, and `0x005102d4`; and living-object/session packet handlers at `0x005a5c23` and `0x005aacfb`/`0x005aad0a`/`0x005aae6e`/`0x005aae7d`.
- IDA MCP `py_eval` rechecked `0x0069b4b0` on 2026-05-31 and confirmed IDA name `dword_69B4B0`, initial dword `0xffffffff`, and 20 data xrefs matching the constructor, teardown, clear helper, scalar deleting destructor, and broad login/map/session users listed above.

## Ownership Notes

- Keep this global with `ui/dialogs/TransferServerDialogPane.cpp`.
- The broad xref set means the overlay is triggered by several subsystems, but the storage and teardown behavior remain part of the transfer-overlay source module.

## Cross-References

- [UID:0000OW][TransferServerDialogPane](by-file/TransferServerDialogPane.md)
- [UID:0000F7][TransferServerDialogPane](by-class/TransferServerDialogPane.md)
- [UID:0001KD][0x00598ed0-0x0059943f.TransferServerDialogPane](by-memory/0x00598ed0-0x0059943f.TransferServerDialogPane.md)
- [UID:0000VJ][TransferServerDialogPaneThunks_599220_5993e0](by-item/TransferServerDialogPaneThunks_599220_5993e0.md)

## Changes

- 2026-05-31: Updated reconstruction metadata and scores from live IDA evidence.
  - Before: completion/confidence were `0/0`, reconstructable state was blank, and no parent file UID was assigned.
  - After: `COMPLETION:76`, `CONFIDENCE:84`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000OW` for [UID:0000OW][TransferServerDialogPane](by-file/TransferServerDialogPane.md). `RECONSTRUCTION_CPP CODE` remains blank because the page is below the 95+ final-source threshold.
  - Evidence: IDA MCP rechecked `0x0069b4b0` as a 4-byte singleton pointer with 20 data xrefs across overlay construction, cleanup/destructor/clear helpers, and main-menu/login/map/session/living-object users.
