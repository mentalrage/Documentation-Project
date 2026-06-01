*** UID:0000Q5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000NS | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_packetSender / dword_67A7EC

## Status

- Confidence: strong for address, Socket lifetime ownership, and broad packet-send role; medium-low for final C++ type/name.
- Address: `0x0067a7ec`
- IDA name: `dword_67A7EC`
- Generated aliases observed: `g_packetSender`; some generated packet-send paths also emit `g_pCashShopRequest` for this same storage, but live IDA resolves those references to `dword_67A7EC`.
- Primary memory doc: [UID:0001P0][0x0067a7ec-0x0067a7f0.g_packetSender](by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md)
- Likely owner: [UID:0000NS][Socket](by-file/Socket.md) lifecycle for initialization/shutdown; consumed through the current [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md)-style queue/send helpers.

## Purpose

This four-byte global stores the process-wide outbound packet/send object used by feature packet builders. Most UI and gameplay features build small packet buffers and pass this global to the shared queue/send path around `0x00574bb0`.

Use `g_packetSender` as a documentation alias for now. Do not use the generated `CashShopRequest*` type as final proof; IDA write evidence now shows Socket owns the global lifetime, while current generated call sites still route through the `CashShopRequest::QueueAndSendPacket` name. Current docs still need to reconcile whether the source-level type was `Socket*`, a request/sender interface, or a broader network worker base.

## Evidence Notes

- IDA names the storage `dword_67A7EC` at `0x0067a7ec`.
- IDA MCP `py_eval` on 2026-05-25 and 2026-05-26 found 489 xrefs to this storage. The 2026-05-25 sweep counted 219 recognized functions, spanning feature packet builders, UI dialogs, socket/reconnect code, and input panes.
- The same IDA MCP sweep found five direct writes at `0x00574828`, `0x0057482f`, `0x00574aaf`, `0x005794c0`, and `0x00579676`. These all fall in the [UID:0001HS][0x005747e0-0x00574ad8.SocketLifecycle](by-memory/0x005747e0-0x00574ad8.SocketLifecycle.md), constructor unwind cleanup at [UID:0001I6][0x005794c0-0x005794cb.ClearPacketSenderGlobal](by-memory/0x005794c0-0x005794cb.ClearPacketSenderGlobal.md), and Socket scalar deleting destructor family.
- 2026-05-31 IDA MCP `py_eval` recheck again finds `0x0067a7ec` as `dword_67A7EC`, a 4-byte `.data` item with 489 data xrefs. Exact write refs remain Socket-lifetime writes only: set/constructor cleanup at `0x00574828` and `0x0057482f`, destructor clear at `0x00574aaf`, unwind clear at `0x005794c0`, and scalar-deleting destructor clear at `0x00579676`.
- [UID:0001HS][0x005747e0-0x00574ad8.SocketLifecycle](by-memory/0x005747e0-0x00574ad8.SocketLifecycle.md) documents the constructor setting this global and the normal destructor clearing it.
- [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md) documents `0x00574bb0` as the broad packet-copy and dispatch funnel used by many callers, but this current generated owner should not be treated as proof that the global itself is cash-shop-owned.
- Current `simroot_v2/class_Socket.cpp` emits `g_packetSender` as one `void*` global-data declaration, while `class_Thread.cpp` emits the queue post helper at `0x00596960` as `Thread::DispatchRequest`. The send path likely crosses a generic base-thread queue primitive before Socket consumes command `8`.
- [UID:0000NM][SelfSaveInputPane](by-file/SelfSaveInputPane.md) uses the global for opcode `0x25`; current IDA xrefs in that neighborhood are at `0x005b6845` and raw helper offset `0x005b688b`, reconfirmed on 2026-05-26.

## Naming Rule

When a generated file emits a feature-local type for this address, keep the feature behavior in that file's docs but normalize the storage to this page. The global is not owned by the feature merely because it sends one packet through it.

If a generated file emits `g_pCashShopRequest` for a packet-send path, verify the address before using the name. Live IDA checks on 2026-05-25 show `ChangeSpellSlotInputPane`, `NewUserMiscDialogPane`, and `MainMenuPane` packet-send paths read `dword_67A7EC`, while the real [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md) storage is `dword_67A738` and has FileDownloader lifetime.

2026-05-27 IDA MCP recheck reconfirmed the `ChangeSpellSlotInputPane::SubmitSpellSlotChange` path: it calls `QueueAndSendPacket` at `0x00574bb0` with receiver `dword_67A7EC` after building opcode `0x30`, subcommand `1`, source slot, and destination slot.

2026-05-27 IDA MCP recheck of `ChangeItemSlotInputPane::OnSubmitInput` at `0x005b3080` confirms the item-slot companion path uses the same sender global. It builds opcode `0x30`, subcommand `0`, source slot, and destination slot, then calls `0x00574bb0(dword_67A7EC, packet, 4)`.

2026-05-27 IDA MCP recheck of `DropGoldInputPane` and `GiveGoldInputPane` confirms the gold prompt paths also use this sender. `0x005b4bb0` sends opcode `0x24` plus a four-byte amount, and `0x005b52f0` sends opcode `0x2a` plus a four-byte amount; both call `0x00574bb0(dword_67A7EC, packet, 5)`.

2026-05-27 IDA MCP recheck of `TakeOffInputPane` and `ThrowReallyInputPane` confirms more item-action consumers. `0x005b2720` sends shortcut opcode `0x2d` with length `1`; `0x005b27c0` and `0x005b2830` send equipment-removal opcode `0x1f` with selector byte and length `2`; `0x005b5b80` sends throw opcode `0x17`, mode byte `1`, and stored slot with length `3`.

2026-05-27 IDA MCP recheck of `WieldInputPane` and `WearInputPane` confirms the neighboring weapon/equipment senders. `0x005b6410` sends Wield opcode `0x12` with selector `0` for the `-` path, `0x005b6500` sends Wield opcode `0x12` with the validated selector, and `0x005b66a0` sends Wear opcode `0x1e` with the validated selector; each sends length `2`.

2026-05-27 IDA MCP recheck of `ThrowInputPane`, `UseInputPane`, and `EatInputPane` confirms the next item-action cluster. `0x005b59d0` sends Throw opcode `0x17`, mode byte `0`, and validated slot with length `3` after checking byte `dword_67A748 + 0x3ec0`; `0x005b6000` sends Eat opcode `0x1a` plus the validated slot with length `2`. `UseInputPane` does not send directly; it validates the same slot-letter range and dispatches to [UID:0001KN][0x005a3e30-0x005a3ff3.UseInventorySlotDispatch](by-memory/0x005a3e30-0x005a3ff3.UseInventorySlotDispatch.md).

## Cross-References

- [UID:0001P0][0x0067a7ec-0x0067a7f0.g_packetSender](by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md)
- [UID:0000NS][Socket](by-file/Socket.md)
- [UID:0001HS][0x005747e0-0x00574ad8.SocketLifecycle](by-memory/0x005747e0-0x00574ad8.SocketLifecycle.md)
- [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md)
- [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md)
- [UID:0000OR][Thread](by-file/Thread.md)
- [UID:0001QH][client_network](by-meta/client_network.md)
- [UID:0000NM][SelfSaveInputPane](by-file/SelfSaveInputPane.md)
- [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md)
- [UID:00001J][ChangeItemSlotInputPane](by-class/ChangeItemSlotInputPane.md)
- [UID:00001M][ChangeSpellSlotInputPane](by-class/ChangeSpellSlotInputPane.md)
- [UID:000043][DropGoldInputPane](by-class/DropGoldInputPane.md)
- [UID:00005T][GiveGoldInputPane](by-class/GiveGoldInputPane.md)
- [UID:0000EC][TakeOffInputPane](by-class/TakeOffInputPane.md)
- [UID:0001M2][0x005b27c0-0x005b2827.SendTakeOffPacket](by-memory/0x005b27c0-0x005b2827.SendTakeOffPacket.md)
- [UID:0000EZ][ThrowReallyInputPane](by-class/ThrowReallyInputPane.md)
- [UID:0000EY][ThrowInputPane](by-class/ThrowInputPane.md)
- [UID:0000FG][UseInputPane](by-class/UseInputPane.md)
- [UID:0001KN][0x005a3e30-0x005a3ff3.UseInventorySlotDispatch](by-memory/0x005a3e30-0x005a3ff3.UseInventorySlotDispatch.md)
- [UID:000047][EatInputPane](by-class/EatInputPane.md)
- [UID:0000G4][WieldInputPane](by-class/WieldInputPane.md)
- [UID:0001MS][0x005b6500-0x005b6560.SendWieldPacket](by-memory/0x005b6500-0x005b6560.SendWieldPacket.md)
- [UID:0000G0][WearInputPane](by-class/WearInputPane.md)
- [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- 2026-05-31 reconstruction metadata and grading:
  - What existed before: `COMPLETION:0`, `CONFIDENCE:0`, blank `RECONSTRUCTABLE`, and no autogen parent.
  - Changed to: `COMPLETION:84`, `CONFIDENCE:82`, `RECONSTRUCTABLE:TRUE`, parent [UID:0000NS][Socket](by-file/Socket.md), and ordered file-local position `80`.
  - Summary/evidence: IDA MCP reconfirms the storage address, 489 xrefs, and all five direct writes in the Socket constructor/destructor family. Final C++ remains blank because the final source-facing type and request/sender interface boundary are still unresolved.
