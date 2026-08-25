*** UID:0000SL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
TransferServerDialogPane *g_pTransferServerDialog = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pTransferServerDialog

## UID00037R Ctrl+R Suppression Guard - 2026-08-24

- [UID:00037R][0x00506d20-0x00507150.MapPaneResizeCommandInputCore](by-memory/0x00506d20-0x00507150.MapPaneResizeCommandInputCore.md) reads this pointer at `0x00506f81` after matching translated key `r` with exact Control.
- A nonnull active transfer dialog suppresses the complete map-refresh initiation: no MapRefreshDimmer construction, opcode `0x38` send, refresh-flag writes, or ObjectList mark/prune calls occur. The key event is still consumed. A null pointer permits the full refresh sequence.
- This is a read-only MapPane consumer. The global definition, zero initialization, publication, teardown, and TransferServerDialogPane.cpp ownership remain unchanged.

## Status

- Confidence: very strong for address, zero initialization, exact pointer type/name, source module, constructor/destructor/EH lifecycle, 20 direct xrefs, and storage split.
- Address: `0x0069b4b0`
- Current IDA name: `dword_69B4B0`
- Proposed owner file: [UID:0000OW][TransferServerDialogPane](by-file/TransferServerDialogPane.md)
- Exact storage evidence: [UID:00029W][0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots](by-memory/0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots.md) records `0x0069b4b0` as the initialized `0x00000000` transfer-overlay singleton slot with 20 direct xrefs.

## Symbol Role

`g_pTransferServerDialog` tracks the active animated transfer-server overlay. The constructor stores the active pane pointer, helper/destructor paths clear it, and login/map/session code reads or clears it when showing, resetting, or dismissing the `TRANSSVR` transfer overlay.

Treat the adjacent main-menu singleton run as physical storage adjacency, not one source-level aggregate. The declaration belongs with `TransferServerDialogPane.cpp`; neighboring slots are owned by create-user and server-select dialog modules.

## Accepted Source Definition

`TransferServerDialogPane *g_pTransferServerDialog = 0;` is the exact source global. It emits through file UID0000OW after the class's exact source children. The zero initializer matches bytes at [UID:0002XO][0x0069b4b0-0x0069b4b4.g_pTransferServerDialog](by-memory/0x0069b4b0-0x0069b4b4.g_pTransferServerDialog.md); no `0xffffffff`, function-local static, reference, smart pointer, aggregate field, or explicit registration wrapper is supported.

Constructor UID0004MV publishes `this`; ordinary destructor UID0004MW clears it; compiler unwind UID0004N0 clears exceptional partial construction; scalar wrapper UID0004N2 includes the ordinary destruction side effect. Launcher guards and login/map/session/packet consumers account for the remaining reads and clears. The global is source-authored even though its backing bytes are generated `.data` storage.

## IDA MCP Evidence

Checked on 2026-05-24:

- `xrefs_to 0x0069b4b0` reports constructor stores at `0x00598f21` and `0x00598f28`.
- Non-deleting destructor helper `0x00599220` clears the global at `0x0059923a`.
- Helper `0x005993b0` clears the global directly, and scalar deleting destructor `0x005993e0` clears it at `0x00599400`.
- External users include main-menu/login flow around `0x004f7460`, `0x004f7497`, `0x004f8f55`; map/session transfer paths around `0x00506f81`, `0x00507d38`, `0x00507d9b`, `0x0050ff3d`, `0x0050ffa0`, `0x00510271`, and `0x005102d4`; and living-object/session packet handlers at `0x005a5c23` and `0x005aacfb`/`0x005aad0a`/`0x005aae6e`/`0x005aae7d`.
- IDA MCP `get_bytes` rechecked `0x0069b4b0` on 2026-06-12 C001 and confirmed bytes `00 00 00 00` and initial dword `0x00000000`; `xrefs_to` confirmed 20 data refs matching the constructor, teardown, clear helper, scalar deleting destructor, and broad login/map/session users listed above.
- [UID:0001KD][0x00598ed0-0x0059943f.TransferServerDialogPane](by-memory/0x00598ed0-0x0059943f.TransferServerDialogPane.md) records the complete transfer-overlay executable range: constructor, non-deleting destructor helper, reset/repaint helper, timer handler, paint handler, singleton clear helper, adjustor thunks, and scalar deleting destructor.
- [UID:00026R][0x0062e47c-0x0062e578.TransferServerReadOnlyData](by-memory/0x0062e47c-0x0062e578.TransferServerReadOnlyData.md) ties the class vtables and `TRANSSVR.EPF`/`.EPD`/`.PAL`/`.PAD` resource strings to the same overlay module.
- [UID:0002Q6][0x004f8f10-0x004f8f95.OpenTransferServerDialog](by-memory/0x004f8f10-0x004f8f95.OpenTransferServerDialog.md) documents the retained main-menu launcher guard that checks this singleton before allocating `0x100` bytes and constructing `TransferServerDialogPane`.
- IDA MCP `get_bytes` on 2026-06-12 C001 reconfirmed `0x0069b4b0-0x0069b4b4` as the exact four-byte storage item, bytes `00 00 00 00`, initial dword `0x00000000`, and all 20 direct xrefs. The exact split memory page is [UID:0002XO][0x0069b4b0-0x0069b4b4.g_pTransferServerDialog](by-memory/0x0069b4b0-0x0069b4b4.g_pTransferServerDialog.md).

## Ownership Notes

- Keep this global with `ui/dialogs/TransferServerDialogPane.cpp`.
- The broad xref set means the overlay is triggered by several subsystems, but the storage and teardown behavior remain part of the transfer-overlay source module.

## Cross-References

- [UID:0000OW][TransferServerDialogPane](by-file/TransferServerDialogPane.md)
- [UID:0000F7][TransferServerDialogPane](by-class/TransferServerDialogPane.md)
- [UID:0001KD][0x00598ed0-0x0059943f.TransferServerDialogPane](by-memory/0x00598ed0-0x0059943f.TransferServerDialogPane.md)
- [UID:00029W][0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots](by-memory/0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots.md)
- [UID:00026R][0x0062e47c-0x0062e578.TransferServerReadOnlyData](by-memory/0x0062e47c-0x0062e578.TransferServerReadOnlyData.md)
- [UID:0002Q6][0x004f8f10-0x004f8f95.OpenTransferServerDialog](by-memory/0x004f8f10-0x004f8f95.OpenTransferServerDialog.md)
- [UID:0000VJ][TransferServerDialogPaneThunks_599220_5993e0](by-item/TransferServerDialogPaneThunks_599220_5993e0.md)

## Changes

- 2026-08-24 B006 UID00037R callback: resolved xref `0x00506f81` as the exact Ctrl+R refresh-suppression guard while preserving storage, lifecycle, and source ownership.
- 2026-05-31: Updated reconstruction metadata and scores from live IDA evidence.
  - Before: completion/confidence were `0/0`, reconstructable state was blank, and no parent file UID was assigned.
  - After: `COMPLETION:76`, `CONFIDENCE:84`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000OW` for [UID:0000OW][TransferServerDialogPane](by-file/TransferServerDialogPane.md). `RECONSTRUCTION_CPP CODE` remains blank because the page is below the 95+ final-source threshold.
  - Evidence: IDA MCP rechecked `0x0069b4b0` as a 4-byte singleton pointer with 20 data xrefs across overlay construction, cleanup/destructor/clear helpers, and main-menu/login/map/session/living-object users.
- 2026-06-06: Raised `COMPLETION` from `76` to `84` and `CONFIDENCE` from `84` to `88`.
  - Added exact storage-slot evidence, executable-range support, transfer-server read-only resource/vtable evidence, retained launcher evidence, and a caveat for the surrounding main-menu singleton run.
  - Evidence: existing IDA-backed docs now account for the singleton slot in [UID:00029W][0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots](by-memory/0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots.md), overlay methods in [UID:0001KD][0x00598ed0-0x0059943f.TransferServerDialogPane](by-memory/0x00598ed0-0x0059943f.TransferServerDialogPane.md), vtables/resources in [UID:00026R][0x0062e47c-0x0062e578.TransferServerReadOnlyData](by-memory/0x0062e47c-0x0062e578.TransferServerReadOnlyData.md), and launch gating in [UID:0002Q6][0x004f8f10-0x004f8f95.OpenTransferServerDialog](by-memory/0x004f8f10-0x004f8f95.OpenTransferServerDialog.md). Final C++ remains blank because field names, timer subobject names, and destructor/thunk representation are still below the 95/95 threshold.
- 2026-06-07 Batch 043 split-parent refresh:
  - Before: `84/88`, below the corrected `85/85` completion gate for assigning an exact storage child.
  - After: `86/88`.
  - Evidence: live IDA MCP reconfirmed exact slot bytes/item bounds and all 20 constructor, teardown, launcher, map, session, and living-object xrefs. The exact memory split now carries the direct storage child while this page remains the canonical global owner.
- 2026-06-12 C001 Batch C001-020:
  - Before: `86/88`, with stale `0xffffffff` initialization notes.
  - After: `87/90`.
  - Evidence: live IDA MCP `get_bytes` returned `00 00 00 00` for the exact slot in the active `b001_nexustk` database; `xrefs_to` still reports the same 20 constructor, teardown, launcher, map, session, and living-object refs.
