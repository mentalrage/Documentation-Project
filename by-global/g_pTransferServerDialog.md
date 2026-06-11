*** UID:0000SL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000OW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pTransferServerDialog

## Status

- Confidence: strong for address, lifecycle, overlay role, and exact storage slot.
- Address: `0x0069b4b0`
- Current IDA name: `dword_69B4B0`
- Proposed owner file: [UID:0000OW][TransferServerDialogPane](by-file/TransferServerDialogPane.md)
- Exact storage evidence: [UID:00029W][0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots](by-memory/0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots.md) records `0x0069b4b0` as the initialized `0xffffffff` transfer-overlay singleton slot with 20 direct xrefs.

## Symbol Role

`g_pTransferServerDialog` tracks the active animated transfer-server overlay. The constructor stores the active pane pointer, helper/destructor paths clear it, and login/map/session code reads or clears it when showing, resetting, or dismissing the `TRANSSVR` transfer overlay.

Treat the adjacent main-menu singleton run as physical storage adjacency, not one source-level aggregate. The declaration belongs with `TransferServerDialogPane.cpp`; neighboring slots are owned by create-user and server-select dialog modules.

## IDA MCP Evidence

Checked on 2026-05-24:

- `xrefs_to 0x0069b4b0` reports constructor stores at `0x00598f21` and `0x00598f28`.
- Non-deleting destructor helper `0x00599220` clears the global at `0x0059923a`.
- Helper `0x005993b0` clears the global directly, and scalar deleting destructor `0x005993e0` clears it at `0x00599400`.
- External users include main-menu/login flow around `0x004f7460`, `0x004f7497`, `0x004f8f55`; map/session transfer paths around `0x00506f81`, `0x00507d38`, `0x00507d9b`, `0x0050ff3d`, `0x0050ffa0`, `0x00510271`, and `0x005102d4`; and living-object/session packet handlers at `0x005a5c23` and `0x005aacfb`/`0x005aad0a`/`0x005aae6e`/`0x005aae7d`.
- IDA MCP `py_eval` rechecked `0x0069b4b0` on 2026-05-31 and confirmed IDA name `dword_69B4B0`, initial dword `0xffffffff`, and 20 data xrefs matching the constructor, teardown, clear helper, scalar deleting destructor, and broad login/map/session users listed above.
- [UID:0001KD][0x00598ed0-0x0059943f.TransferServerDialogPane](by-memory/0x00598ed0-0x0059943f.TransferServerDialogPane.md) records the complete transfer-overlay executable range: constructor, non-deleting destructor helper, reset/repaint helper, timer handler, paint handler, singleton clear helper, adjustor thunks, and scalar deleting destructor.
- [UID:00026R][0x0062e480-0x0062e57c.TransferServerReadOnlyData](by-memory/0x0062e480-0x0062e57c.TransferServerReadOnlyData.md) ties the class vtables and `TRANSSVR.EPF`/`.EPD`/`.PAL`/`.PAD` resource strings to the same overlay module.
- [UID:0002Q6][0x004f8f10-0x004f8f95.OpenTransferServerDialog](by-memory/0x004f8f10-0x004f8f95.OpenTransferServerDialog.md) documents the retained main-menu launcher guard that checks this singleton before allocating `0x100` bytes and constructing `TransferServerDialogPane`.
- IDA MCP `py_eval` on 2026-06-07 reconfirmed `0x0069b4b0-0x0069b4b4` as the exact four-byte storage item, bytes `ff ff ff ff`, initial dword `0xffffffff`, and all 20 direct xrefs. The exact split memory page is [UID:0002XO][0x0069b4b0-0x0069b4b4.g_pTransferServerDialog](by-memory/0x0069b4b0-0x0069b4b4.g_pTransferServerDialog.md).

## Ownership Notes

- Keep this global with `ui/dialogs/TransferServerDialogPane.cpp`.
- The broad xref set means the overlay is triggered by several subsystems, but the storage and teardown behavior remain part of the transfer-overlay source module.

## Cross-References

- [UID:0000OW][TransferServerDialogPane](by-file/TransferServerDialogPane.md)
- [UID:0000F7][TransferServerDialogPane](by-class/TransferServerDialogPane.md)
- [UID:0001KD][0x00598ed0-0x0059943f.TransferServerDialogPane](by-memory/0x00598ed0-0x0059943f.TransferServerDialogPane.md)
- [UID:00029W][0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots](by-memory/0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots.md)
- [UID:00026R][0x0062e480-0x0062e57c.TransferServerReadOnlyData](by-memory/0x0062e480-0x0062e57c.TransferServerReadOnlyData.md)
- [UID:0002Q6][0x004f8f10-0x004f8f95.OpenTransferServerDialog](by-memory/0x004f8f10-0x004f8f95.OpenTransferServerDialog.md)
- [UID:0000VJ][TransferServerDialogPaneThunks_599220_5993e0](by-item/TransferServerDialogPaneThunks_599220_5993e0.md)

## Changes

- 2026-05-31: Updated reconstruction metadata and scores from live IDA evidence.
  - Before: completion/confidence were `0/0`, reconstructable state was blank, and no parent file UID was assigned.
  - After: `COMPLETION:76`, `CONFIDENCE:84`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000OW` for [UID:0000OW][TransferServerDialogPane](by-file/TransferServerDialogPane.md). `RECONSTRUCTION_CPP CODE` remains blank because the page is below the 95+ final-source threshold.
  - Evidence: IDA MCP rechecked `0x0069b4b0` as a 4-byte singleton pointer with 20 data xrefs across overlay construction, cleanup/destructor/clear helpers, and main-menu/login/map/session/living-object users.
- 2026-06-06: Raised `COMPLETION` from `76` to `84` and `CONFIDENCE` from `84` to `88`.
  - Added exact storage-slot evidence, executable-range support, transfer-server read-only resource/vtable evidence, retained launcher evidence, and a caveat for the surrounding main-menu singleton run.
  - Evidence: existing IDA-backed docs now account for the singleton slot in [UID:00029W][0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots](by-memory/0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots.md), overlay methods in [UID:0001KD][0x00598ed0-0x0059943f.TransferServerDialogPane](by-memory/0x00598ed0-0x0059943f.TransferServerDialogPane.md), vtables/resources in [UID:00026R][0x0062e480-0x0062e57c.TransferServerReadOnlyData](by-memory/0x0062e480-0x0062e57c.TransferServerReadOnlyData.md), and launch gating in [UID:0002Q6][0x004f8f10-0x004f8f95.OpenTransferServerDialog](by-memory/0x004f8f10-0x004f8f95.OpenTransferServerDialog.md). Final C++ remains blank because field names, timer subobject names, and destructor/thunk representation are still below the 95/95 threshold.
- 2026-06-07 Batch 043 split-parent refresh:
  - Before: `84/88`, below the corrected `85/85` completion gate for assigning an exact storage child.
  - After: `86/88`.
  - Evidence: live IDA MCP reconfirmed exact slot bytes/item bounds and all 20 constructor, teardown, launcher, map, session, and living-object xrefs. The exact memory split now carries the direct storage child while this page remains the canonical global owner.
