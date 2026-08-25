*** UID:0000Q5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000NS | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000NS | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
Socket *g_packetSender = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
extern Socket *g_packetSender;
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_packetSender / dword_67A7EC

## 2026-08-14 B003 Header Declaration Closure

- Final formal definition/declaration are `Socket *g_packetSender = NULL;` and `extern Socket *g_packetSender;`, using source-era null spelling and UID0000DD's complete class declaration.
- ChangePasswordDialogPane's two senders call the Socket member directly with an explicit `short` packet-length cast. UID0000Q5/UID0000NS remain `90/91`; lifecycle and transport ownership remain Socket-local.

## Status

- Confidence: strong for address, Socket lifetime ownership, and broad packet-send role; medium-high for final C++ type/name.
- Address: `0x0067a7ec`
- IDA name: `dword_67A7EC`
- Generated aliases observed: `g_packetSender`; some generated packet-send paths also emit `g_pCashShopRequest` for this same storage, but live IDA resolves those references to `dword_67A7EC`.
- Primary memory doc: [UID:0001P0][0x0067a7ec-0x0067a7f0.g_packetSender](by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md)
- Likely owner: [UID:0000NS][Socket](by-file/Socket.md) lifecycle for initialization/shutdown; consumed through Socket-owned queue/send helpers.
- Best current source-facing type: `Socket *`.

## Purpose

This four-byte global stores the process-wide outbound packet/send object used by feature packet builders. Most UI and gameplay features build small packet buffers and pass this global to the shared queue/send path around `0x00574bb0`.

[UID:0003UB][0x005a3ae0-0x005a3d39.UserPaneExecuteHotkeyAction](by-memory/0x005a3ae0-0x005a3d39.UserPaneExecuteHotkeyAction.md) is one exact feature consumer. Its chat-action branch loads this global as the `Socket` receiver before the call at `0x005a3d1d`, builds opcode `0x0e`, subtype `0`, a one-byte ACP text length, and the converted text bytes, and sends exactly `textLength + 3` bytes. The conversion-buffer terminator and packet-buffer terminator are local safety writes outside the sent length. The method has no sender-null guard and ignores the queue/send result. This evidence does not move ownership or emission away from Socket.

[UID:0004WO][0x00558240-0x00558391.SendScreenshotProofPacket](by-memory/0x00558240-0x00558391.SendScreenshotProofPacket.md) is the exact screenshot-proof consumer. It builds opcode `0x83`, copies 13 masked MD5-hex bytes, generates 16 random bytes with the first using `(rand() % 10) - 26` and the remaining fifteen using `rand() % 255`, copies the final 19 masked bytes, writes a local-only terminator at `packet[49]`, and calls `g_packetSender->QueueAndSendPacket(packet, 49)`. This is ScreenshotCapture feature-policy evidence only; the global's lifetime, type, and source definition remain Socket-owned.

UID000401 adds a direct-message send-path consumer: `0x005b1640` loads `g_packetSender` at `0x005b1764` and invokes `Socket::SendPacket` for the completed outbound whisper packet. The same function's blank-recipient path does not send, so this is a guarded consumer rather than an unconditional call site.

Best current source-facing type: `Socket *`. Socket constructor/destructor/unwind/scalar-deleting paths are the only observed writers, [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md) and sibling command helpers are now Socket-owned, and `Socket::HandleSocketCommand` consumes their queued commands. Keep a narrow caveat that a future recovered header may expose this through a sender typedef/interface, but do not use generated `CashShopRequest*` aliases as final type evidence.

Rejected or secondary aliases:

- `CashShopRequest *g_packetSender`: rejected as generated/OOAnalyzer alias pollution. Socket constructor/destructor/unwind/scalar-deleting paths own the writes, `Socket::HandleSocketCommand` consumes the queued commands, and the real `g_pCashShopRequest` storage is separate at `0x0067a738`.
- `Thread *g_packetSender`: too broad. Thread owns queue primitives, but callers use Socket command semantics and Socket-specific lifecycle controls this pointer.
- `void *g_packetSender`: acceptable only as a decompiler/generated fallback when the type system lacks `Socket`; source-facing documentation should use `Socket *`.
- Abstract sender/request interface: possible in original project style, but currently unproven by binary ownership, vtable, or call-site evidence. Keep only as a later-header caveat.

## Evidence Notes

- IDA names the storage `dword_67A7EC` at `0x0067a7ec`.
- The UID000401 support readback preserves this as a four-byte data item with value zero, best source-facing type `Socket *`, exact existing two-line regular comment, and absent repeatable comment; the full-frame SHA256 is `DF3F05CC3BB9E6B109AE4D7B63109444595C4775E8C8A175611D10FD8B6F958F`. No IDA mutation was performed by B006.
- IDA MCP `py_eval` on 2026-05-25 and 2026-05-26 found 489 xrefs to this storage. The 2026-05-25 sweep counted 219 recognized functions, spanning feature packet builders, UI dialogs, socket/reconnect code, and input panes.
- The same IDA MCP sweep found five direct writes at `0x00574828`, `0x0057482f`, `0x00574aaf`, `0x005794c0`, and `0x00579676`. These all fall in the [UID:0001HS][0x005747e0-0x00574ad8.SocketLifecycle](by-memory/0x005747e0-0x00574ad8.SocketLifecycle.md), constructor unwind cleanup at [UID:0001I6][0x005794c0-0x005794cb.ClearPacketSenderGlobal](by-memory/0x005794c0-0x005794cb.ClearPacketSenderGlobal.md), and Socket scalar deleting destructor family.
- [UID:0001I6][0x005794c0-0x005794cb.ClearPacketSenderGlobal](by-memory/0x005794c0-0x005794cb.ClearPacketSenderGlobal.md) is specifically the Socket constructor-unwind cleanup writer for `g_packetSender`. It is reached only by the EH tail-jump at `0x0060805e`, while ordinary destructor paths clear the global directly at `0x00574aaf` and `0x00579676`. This strengthens Socket lifetime ownership and `Socket *` source-facing type inference, but it does not create a separate packet-sender helper API.
- 2026-05-31 IDA MCP `py_eval` recheck again finds `0x0067a7ec` as `dword_67A7EC`, a 4-byte `.data` item with 489 data xrefs. Exact write refs remain Socket-lifetime writes only: set/constructor cleanup at `0x00574828` and `0x0057482f`, destructor clear at `0x00574aaf`, unwind clear at `0x005794c0`, and scalar-deleting destructor clear at `0x00579676`.
- [UID:0001HS][0x005747e0-0x00574ad8.SocketLifecycle](by-memory/0x005747e0-0x00574ad8.SocketLifecycle.md) documents the constructor setting this global and the normal destructor clearing it.
- [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md) documents `0x00574bb0` as the broad packet-copy and dispatch funnel used by many callers, but this current generated owner should not be treated as proof that the global itself is cash-shop-owned.
- [UID:0003UB][0x005a3ae0-0x005a3d39.UserPaneExecuteHotkeyAction](by-memory/0x005a3ae0-0x005a3d39.UserPaneExecuteHotkeyAction.md) loads `dword_67A7EC` into `ECX` for the call at `0x005a3d1d`. That branch sends its opcode-`0x0e`, subtype-`0`, length-prefixed ACP text packet with explicit length `textLength + 3`; neither local terminator is part of the sent payload.
- Historical generated/simroot lead: `source-3/simroot_v2/class_Socket.cpp` emitted `g_packetSender` as one `void*` global-data declaration, while `class_Thread.cpp` emitted the queue post helper at `0x00596960` as `Thread::DispatchRequest`. Current type/ownership authority is the by-* Socket lifecycle evidence and current IDA/MCP evidence; the send path likely crosses a generic base-thread queue primitive before Socket consumes command `8`.
- [UID:0000NM][SelfSaveInputPane](by-file/SelfSaveInputPane.md) uses the global for opcode `0x25`. The active optimized body loads this storage at `0x005b6845` and calls `QueueAndSendPacket` at `0x005b6858`; the retained helper loads it at `0x005b688b` and calls the same method at `0x005b689e`. These are two release-binary realizations of one recovered human-source call from `SelfSaveInputPane::OnConfirmInput()` to its private `SendSelfSavePacket()` helper, whose source statement is `g_packetSender->QueueAndSendPacket(packet, 1)`. This consumer evidence is consistent with the existing `Socket *` type and does not change Socket ownership.
- 2026-06-14 A003 live IDA MCP refresh reconfirmed the key Socket-owned bodies: `sub_5747E0` constructor/lifecycle setup is `0x1f9` / `505` bytes, `sub_574BB0` queue/send funnel is `0x63` / `99` bytes, unwind clear helper `sub_5794C0` is `0xb` / `11` bytes, and scalar deleting destructor `sub_5795A0` is `0x127` / `295` bytes (Verified with int_convert.py).
- 2026-06-14 decompilation of `sub_5747E0` publishes `dword_67A7EC = this` after base/thread initialization, or clears it on the adjusted-null constructor path. The same body then installs the `Socket` vtable and initializes socket buffers/state.
- 2026-06-14 decompilation of `sub_574BB0` confirms the broad queue/send funnel: if byte `this+240206` is clear, it allocates `length+1`, copies the packet bytes, null-terminates the buffer, and posts command `8` through `sub_596960`.
- 2026-06-14 decompilation of `sub_5794C0` confirms the unwind helper only clears `dword_67A7EC`; `sub_5795A0` clears the global at `0x00579676` during scalar deleting destruction after socket/resource cleanup. Current `xrefs_to 0x0067a7ec` still returns a high-fanout first page with `more: true`, consistent with the prior 489-xref IDA sweep, while the direct write sites remain Socket-lifetime refs documented above.

## Naming Rule

When a generated file emits a feature-local type for this address, keep the feature behavior in that file's docs but normalize the storage to this page. The global is not owned by the feature merely because it sends one packet through it.

If a generated file emits `g_pCashShopRequest` for a packet-send path, verify the address before using the name. Live IDA checks on 2026-05-25 show `ChangeSpellSlotInputPane`, `NewUserMiscDialogPane`, and `MainMenuPane` packet-send paths read `dword_67A7EC`, while the real [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md) storage is `dword_67A738` and has FileDownloader lifetime.

2026-05-27 IDA MCP recheck reconfirmed the `ChangeSpellSlotInputPane::SubmitSpellSlotChange` path: it calls `QueueAndSendPacket` at `0x00574bb0` with receiver `dword_67A7EC` after building opcode `0x30`, subcommand `1`, source slot, and destination slot.

2026-05-27 IDA MCP recheck of `ChangeItemSlotInputPane::OnSubmitInput` at `0x005b3080` confirms the item-slot companion path uses the same sender global. It builds opcode `0x30`, subcommand `0`, source slot, and destination slot, then calls `0x00574bb0(dword_67A7EC, packet, 4)`.

2026-06-26 B010 support sync adds [UID:00021Y][0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers](by-memory/0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers.md) as a ClanBankPane feature packet-builder consumer of this global. The retained raw submit helper builds opcode `0x36`, subtype `0x0d` for constructor action `10` / mode `0` or `0x0c` for action `16` / mode `1`, selected slot as zero-extended UInt16BE, multi-count flag, and UInt32BE amount, then calls `g_packetSender->QueueAndSendPacket(packet, 9)`. The retained raw close helper sends `{0x36,0x0b}` length `2`. Live MCP and PE evidence still shows no function/xref/data-flow/pointer/rel32 route to either raw start, so this is concrete feature-consumer/type evidence only; [UID:0000NS][Socket](by-file/Socket.md) remains the owner/emitter for `g_packetSender`, and no ClanBank ownership is implied for the global.

2026-06-29 B001 support sync supersedes the 2026-06-26 B006 blank-C++ note for retained raw sender [UID:00042U][0x005b31a0-0x005b3215.ChangeItemSlotPacketRawSender](by-memory/0x005b31a0-0x005b3215.ChangeItemSlotPacketRawSender.md). Both the live submit method [UID:0001M6][0x005b3010-0x005b3196.ChangeItemSlotInputPane](by-memory/0x005b3010-0x005b3196.ChangeItemSlotInputPane.md) and retained raw sender [UID:00042U][0x005b31a0-0x005b3215.ChangeItemSlotPacketRawSender](by-memory/0x005b31a0-0x005b3215.ChangeItemSlotPacketRawSender.md) build opcode `0x30`, subcommand `0`, source/destination slot bytes, a local-only trailing zero, and send length `4` through `g_packetSender->QueueAndSendPacket`. UID00042U now emits first-draft file-scope `SendChangeItemSlotPacket` through [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md); the no-function/xref/pointer/rel32 route evidence remains a callgraph/name caveat, and [UID:0000NS][Socket](by-file/Socket.md) remains the owner/emitter for this global.

2026-06-26 B006 support sync for [UID:0001LZ][0x005b1ec0-0x005b2152.SayToGroupMessageInputPane](by-memory/0x005b1ec0-0x005b2152.SayToGroupMessageInputPane.md) adds the group target-message submit path as another feature packet-builder consumer. The live `OnSubmitInput()` path builds opcode `0x19`, appends one-byte group-name length, group-name bytes, one-byte message length, and message bytes, checks the final `packetLength = groupNameLen + messageLen + 3` against the packet cap, writes a local-only terminator outside the sent length, then calls `g_packetSender->QueueAndSendPacket(packet, static_cast<short>(packetLength))`. This is consumer/type evidence for the existing `Socket *g_packetSender` decision only; it does not move ownership of `g_packetSender` out of [UID:0000NS][Socket](by-file/Socket.md).

2026-06-26 B006 support sync for [UID:0001M4][0x005b2f70-0x005b2fcb.SendEmotionPacket](by-memory/0x005b2f70-0x005b2fcb.SendEmotionPacket.md) adds the Emotion feature packet helper reached only from [UID:0001M3][0x005b29c0-0x005b2f68.EmotionInputPane](by-memory/0x005b29c0-0x005b2f68.EmotionInputPane.md). The helper builds opcode `0x1d`, writes the caller-provided selector byte after the handler's `selector - 0x0b` conversion, stores a local-only zero byte at `packet[2]`, and sends exactly length `2` through `g_packetSender->QueueAndSendPacket(packet, 2)` using an unsigned-char scratch packet. This is consumer/type evidence only; [UID:0000NS][Socket](by-file/Socket.md) remains the owner/emitter for the global and queue/send method, while [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md) owns the Emotion feature code.

2026-06-28 B009 support sync for [UID:0001MJ][0x005b5440-0x005b5547.GroupInputPane](by-memory/0x005b5440-0x005b5547.GroupInputPane.md) adds the source-ready `GroupInputPane::OnConfirmInput()` opcode `0x2e` command-submit path as another CommandInputPanes feature packet-builder consumer. The method gates on current line length, copies the wide command text, converts through `WideCharToMultiByte(CP_ACP,0,...)`, writes opcode `0x2e`, writes one-byte `encodedLength`, copies exactly `encodedLength` converted text bytes, stores local-only terminators outside the explicit send length, computes `packetLength = encodedLength + 2`, and calls `g_packetSender->QueueAndSendPacket(packet, static_cast<short>(packetLength))`. This is consumer/type evidence only; [UID:0000NS][Socket](by-file/Socket.md) remains the owner/emitter for `g_packetSender`, while [UID:00005W][GroupInputPane](by-class/GroupInputPane.md) / [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md) remain the feature/source owners for the packet builder.

2026-05-27 IDA MCP recheck of `DropGoldInputPane` and `GiveGoldInputPane` confirms the gold prompt paths also use this sender. `0x005b4bb0` sends opcode `0x24` plus a four-byte amount, and `0x005b52f0` sends opcode `0x2a` plus a four-byte amount; both call `0x00574bb0(dword_67A7EC, packet, 5)`.

2026-05-27 IDA MCP recheck of `TakeOffInputPane` and `ThrowReallyInputPane` confirms more item-action consumers. `0x005b2720` sends shortcut opcode `0x2d` with length `1`; `0x005b27c0` and `0x005b2830` send equipment-removal opcode `0x1f` with selector byte and length `2`; `0x005b5b80` sends throw opcode `0x17`, mode byte `1`, and stored slot with length `3`.

2026-06-21 B006 [UID:0001M2][0x005b27c0-0x005b2827.SendTakeOffPacket](by-memory/0x005b27c0-0x005b2827.SendTakeOffPacket.md) source-quality sync resolves the helper's first-draft C++ as `g_packetSender->QueueAndSendPacket(packet, 2)` after two `PacketBufferWriteUInt8` calls and a local-only terminator. This is a focused consumer example for the `Socket *` type decision, not owner evidence for `TakeOffInputPane`, `SelfLookPane`, `ProtocolSend`, or a feature-local sender global.

2026-06-21 B007 [UID:0002RI][0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers](by-memory/0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers.md) source-quality sync adds the legacy spell direct-cast consumers. The `CastSpell` direct route at `0x0057cb50` and retained no-route helper body `0x0057cc70-0x0057ccd0` both build opcode `0x0f` plus the one-based spell slot, clear a local-only scratch byte, and call `g_packetSender->QueueAndSendPacket(packet, 2)`. This is feature packet-builder evidence for `SpellInventoryPane.cpp`; Socket remains owner of the sender global and queue/send method.

2026-06-19 B008 [UID:0002RY][0x005b6c30-0x005b6c7c.SendBlockListenModePacket](by-memory/0x005b6c30-0x005b6c7c.SendBlockListenModePacket.md) source-quality sync adds the raw BlockListen fixed request consumer. The helper builds opcode `0x0d` plus subcommand `0x01`, clears a local-only scratch byte, and calls `g_packetSender->QueueAndSendPacket(packet, 2)`. This is feature packet-builder evidence for [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md); Socket remains owner of this global and the queue/send method, and generated `g_pCashShopRequest` aliases remain rejected for `0x0067a7ec`.

2026-06-20 B004 [UID:0003UT][0x005abda0-0x005abee8.UserPaneHandleUIPanelSwitchPacket](by-memory/0x005abda0-0x005abee8.UserPaneHandleUIPanelSwitchPacket.md) source-quality sync adds another LivingObjectPane feature-packet builder consumer. Private helper candidate `0x005acfe0-0x005ad02c` is called only by the UI-panel switch handler before SelfLookPane `+0x232c` writes; it writes bytes `{0x2d, 0x00}`, writes an unsent local terminator at byte `2`, loads this global as the sender, and calls [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md) with explicit length `2`. This is sender-global use, not owner evidence for Socket moving into `LivingObjectPane`.

2026-05-27 IDA MCP recheck of `WieldInputPane` and `WearInputPane` confirms the neighboring weapon/equipment senders. `0x005b6410` sends Wield opcode `0x12` with selector `0` for the `-` path, `0x005b6500` sends Wield opcode `0x12` with the validated selector, and `0x005b66a0` sends Wear opcode `0x1e` with the validated selector; each sends length `2`.

2026-05-27 IDA MCP recheck of `ThrowInputPane`, `UseInputPane`, and `EatInputPane` confirms the next item-action cluster. `0x005b59d0` sends Throw opcode `0x17`, mode byte `0`, and validated slot with length `3` after checking byte source-facing `g_pUserPane + 0x3ec0` / stable alias [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) / historical `dword_67A748 + 0x3ec0`; `0x005b6000` sends Eat opcode `0x1a` plus the validated slot with length `2`. `UseInputPane` does not send directly; it validates the same slot-letter range and dispatches to [UID:0001KN][0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot](by-memory/0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot.md).

## Assignment Decision

Owner and emitter route remain [UID:0000NS][Socket](by-file/Socket.md). This global scores above the current code-entry numeric threshold, and the Socket route plus five Socket-lifetime writes make the canonical definition `Socket *g_packetSender = nullptr;` appropriate. A recovered header could still refine the exposed type through a sender typedef/interface, but that bounded caveat does not justify suppressing or relocating the accepted canonical definition.

## Score Rationale

- Completion `90`: exact storage, alias conflicts, five Socket-lifetime writes, broad read fan-in, queue/send funnel, feature packet examples including both lowered SelfSave callsites, ownership rule, direct Socket parent, current IDA decompilation of constructor/clear/destructor/send bodies, and the canonical global definition are documented.
- Confidence `91`: IDA-backed write evidence and the Socket parent route support ownership assignment. Confidence remains below final because a recovered header could still expose a narrow sender typedef/interface around the current `Socket *` storage.

## Cross-References

- [UID:0001P0][0x0067a7ec-0x0067a7f0.g_packetSender](by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md)
- [UID:0000NS][Socket](by-file/Socket.md)
- [UID:0001HS][0x005747e0-0x00574ad8.SocketLifecycle](by-memory/0x005747e0-0x00574ad8.SocketLifecycle.md)
- [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md)
- [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md)
- [UID:0000OR][Thread](by-file/Thread.md)
- [UID:0001QH][client_network](by-meta/client_network.md)
- [UID:0000NM][SelfSaveInputPane](by-file/SelfSaveInputPane.md)
- [UID:000401][0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods](by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md)
- [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md)
- [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md)
- [UID:00004B][EmotionInputPane](by-class/EmotionInputPane.md)
- [UID:0001M3][0x005b29c0-0x005b2f68.EmotionInputPane](by-memory/0x005b29c0-0x005b2f68.EmotionInputPane.md)
- [UID:0001M4][0x005b2f70-0x005b2fcb.SendEmotionPacket](by-memory/0x005b2f70-0x005b2fcb.SendEmotionPacket.md)
- [UID:0001MJ][0x005b5440-0x005b5547.GroupInputPane](by-memory/0x005b5440-0x005b5547.GroupInputPane.md)
- [UID:0001LZ][0x005b1ec0-0x005b2152.SayToGroupMessageInputPane](by-memory/0x005b1ec0-0x005b2152.SayToGroupMessageInputPane.md)
- [UID:00001J][ChangeItemSlotInputPane](by-class/ChangeItemSlotInputPane.md)
- [UID:00042U][0x005b31a0-0x005b3215.ChangeItemSlotPacketRawSender](by-memory/0x005b31a0-0x005b3215.ChangeItemSlotPacketRawSender.md)
- [UID:00001M][ChangeSpellSlotInputPane](by-class/ChangeSpellSlotInputPane.md)
- [UID:000043][DropGoldInputPane](by-class/DropGoldInputPane.md)
- [UID:00005T][GiveGoldInputPane](by-class/GiveGoldInputPane.md)
- [UID:0000EC][TakeOffInputPane](by-class/TakeOffInputPane.md)
- [UID:0001M2][0x005b27c0-0x005b2827.SendTakeOffPacket](by-memory/0x005b27c0-0x005b2827.SendTakeOffPacket.md)
- [UID:0000EZ][ThrowReallyInputPane](by-class/ThrowReallyInputPane.md)
- [UID:0000EY][ThrowInputPane](by-class/ThrowInputPane.md)
- [UID:0000FG][UseInputPane](by-class/UseInputPane.md)
- [UID:0001KN][0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot](by-memory/0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot.md)
- [UID:000047][EatInputPane](by-class/EatInputPane.md)
- [UID:0000G4][WieldInputPane](by-class/WieldInputPane.md)
- [UID:0001MS][0x005b6500-0x005b6560.SendWieldPacket](by-memory/0x005b6500-0x005b6560.SendWieldPacket.md)
- [UID:0000G0][WearInputPane](by-class/WearInputPane.md)
- [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md)
- [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md)
- [Wave3 data issues](../wave3_data_issues.md)
- [UID:00021Y][0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers](by-memory/0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers.md)

## Changes

- 2026-08-13 B006 UID000401 support callback:
  - Added the exact direct-message consumer at `0x005b1764`, its guarded send semantics, and the support-readback physical-state/hash evidence.
  - Preserved the accepted `90/91` score, `Socket *` source-facing type, ownership, emitter state, comments, and IDA state; B006 did not mutate IDA.
- 2026-07-24 B004 UID0001G9 screenshot-proof support synchronization: score, type, owner/emitter, and formal definition are unchanged. Added exact [UID:0004WO][0x00558240-0x00558391.SendScreenshotProofPacket](by-memory/0x00558240-0x00558391.SendScreenshotProofPacket.md) consumer evidence for opcode `0x83`, 13+16+19 payload construction, local-only terminator, and explicit 49-byte queue/send while preserving Socket ownership.
- 2026-07-15 B005 UID0003UB implementation callback support sync:
  - Added the exact UserPane hotkey chat-action consumer: opcode `0x0e`, subtype `0`, one-byte ACP text length, converted text, explicit send length `textLength + 3`, and the sender load/call at `0x005a3d1d`.
  - Preserved `Socket *g_packetSender = nullptr;`, [UID:0000NS][Socket](by-file/Socket.md) ownership/emission, all five Socket-lifetime writes, score `90/91`, the 489-reference evidence, and every rejected alias/type alternative. The conversion and packet terminators remain local-only, and the consumer supplies no sender-null or send-result handling.
- 2026-07-13 B004 UID0003O7 implementation callback support sync:
  - Recorded the active SelfSave sender load/call pair at `0x005b6845`/`0x005b6858` and retained helper load/call pair at `0x005b688b`/`0x005b689e` as two lowered release realizations of one human-source private-helper call.
  - Preserved `Socket *g_packetSender = nullptr;`, [UID:0000NS][Socket](by-file/Socket.md) ownership/emission, the five Socket-lifetime writes, 489-reference evidence, score `90/91`, and all rejected alias/type alternatives.
- 2026-06-30 B007 implementation callback: raised score from `86/88` to `90/91`; formal C++ now emits the single canonical source definition `Socket *g_packetSender = nullptr;`. Current MCP confirms the `0x0067a7ec` high-fanout global refs and Socket lifecycle writers; [UID:0001P0][0x0067a7ec-0x0067a7f0.g_packetSender](by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md) documents the exact storage slot and must not duplicate this definition.
- 2026-06-26 B010 [UID:00021Y][0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers](by-memory/0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers.md) support sync:
  - Added the ClanBankPane raw opcode `0x36` submit/close helper island as a concrete `g_packetSender->QueueAndSendPacket` consumer.
  - Preserved Socket ownership, `Socket *` source-facing type, and rejected `CashShopRequest*`/feature-owned aliases for `0x0067a7ec`.
- 2026-06-07: Normalized the item-action busy-byte evidence from historical `dword_67A748` to [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md).
  - Before: the `ThrowInputPane`/`UseInputPane`/`EatInputPane` evidence used the raw collection-data storage name.
  - After: the page links the resolved collection-data global while retaining the historical label and `+0x3ec0` offset for traceability.
  - Evidence: the generated resolved-name report maps `dword_67A748` to `g_pCollectionData`, and the existing IDA evidence ties that byte check to item-action packet-send gating before use of `g_packetSender`.
- 2026-06-22 Rule 26 support sync from B001 [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md):
  - Updated item-action busy-byte wording to source-facing `g_pUserPane + 0x3ec0`; [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) remains the stable alias.

- 2026-05-31 reconstruction metadata and grading:
  - What existed before: `COMPLETION:0`, `CONFIDENCE:0`, blank `RECONSTRUCTABLE`, and no autogen parent.
  - Changed to: `COMPLETION:84`, `CONFIDENCE:82`, `RECONSTRUCTABLE:TRUE`, parent [UID:0000NS][Socket](by-file/Socket.md), and ordered file-local position `80`.
  - Summary/evidence: IDA MCP reconfirms the storage address, 489 xrefs, and all five direct writes in the Socket constructor/destructor family. The 2026-06-30 callback now emits `Socket *g_packetSender = nullptr;`; a later recovered header could still refine the source-facing typedef/interface boundary.
- 2026-06-10 A001 strict gate repair:
  - Changed scores from `84/82` to `85/85`.
  - Summary/evidence: the direct Socket file parent now clears `90/89`, while this page documents exact `0x0067a7ec` storage, 489 data xrefs, five Socket-only lifetime writes, broad feature/UI sender reads, the queue/send funnel, real `g_pCashShopRequest` storage separation, and final type caveats. The child/direct-parent gate is satisfied, and the formal block now emits the accepted canonical `Socket *` definition.
- 2026-06-14 A003 goal2 score pass: raised `85/85` to `86/88`.
  - Evidence: live IDA MCP reconfirmed the Socket constructor publish/fallback clear, queue/send funnel behavior, unwind clear helper, scalar deleting destructor clear at `0x00579676`, high-fanout sender refs, and non-dead-ended Socket owner/emitter route.
  - Code-entry decision: no reconstruction C++ was added; the route and numeric gate are present, but final `Socket*` versus sender-interface type, generated `CashShopRequest` alias cleanup, and request-thread boundary remain below source-quality evidence.
- 2026-06-17 B003 Socket lifecycle source-quality pass:
  - Before: the page left the source-facing type unresolved between `Socket*`, a request/sender interface, and generated `CashShopRequest*` aliases.
  - After: documented `Socket *` as the best current source-facing type, with only a later-header typedef/interface caveat.
  - Evidence: B003 reconfirmed Socket-only lifetime writes, Socket-owned command helpers, `Socket::HandleSocketCommand` consumers, and separate real `g_pCashShopRequest` storage at `0x0067a738`.
- 2026-06-18 B003 ClearPacketSenderGlobal source-quality pass:
  - Before: this page listed the `0x005794c0` write but did not fully distinguish constructor-unwind cleanup from a possible helper API.
  - After: [UID:0001I6][0x005794c0-0x005794cb.ClearPacketSenderGlobal](by-memory/0x005794c0-0x005794cb.ClearPacketSenderGlobal.md) is documented as the Socket constructor-unwind cleanup writer only; `Socket *` remains the best current source-facing type, and generated `void *`, `CashShopRequest *`, `Thread *`, or unproven interface names remain rejected/secondary.
  - Evidence: B003 raw PE/Capstone recheck found one EH tail-jump route, no target pointer/table route, and the same five Socket-family writes with 489 positive-control global references.
- 2026-06-20 B006 Socket support sync:
  - Added explicit rejected alias list for `CashShopRequest *`, `Thread *`, `void *`, and speculative sender-interface interpretations.
  - Evidence: B006 reconfirmed 489 `g_packetSender` VA hits, Socket-only lifecycle writes, command-helper ownership, and real `g_pCashShopRequest` separation.
- 2026-06-20 B004 [UID:0003UT][0x005abda0-0x005abee8.UserPaneHandleUIPanelSwitchPacket](by-memory/0x005abda0-0x005abee8.UserPaneHandleUIPanelSwitchPacket.md) support sync:
  - Added the private ACK helper candidate `0x005acfe0-0x005ad02c` as a consumer that sends `{0x2d, 0x00}` length `2` through this global and [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md), while preserving Socket ownership for the global.
- 2026-06-21 B006 SendTakeOffPacket support sync:
  - Added [UID:0001M2][0x005b27c0-0x005b2827.SendTakeOffPacket](by-memory/0x005b27c0-0x005b2827.SendTakeOffPacket.md) as a source-ready `g_packetSender->QueueAndSendPacket(packet, 2)` consumer with no score or ownership change.
- 2026-06-21 B007 SpellInventoryPane direct-cast support sync:
  - Added [UID:0002RI][0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers](by-memory/0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers.md) direct-cast sender examples for the in-line route and retained raw helper, both sending `{0x0f, spellSlot}` length `2` with a local-only scratch byte and no ownership change.
- 2026-06-19 B008 SendBlockListenModePacket support sync:
  - Added [UID:0002RY][0x005b6c30-0x005b6c7c.SendBlockListenModePacket](by-memory/0x005b6c30-0x005b6c7c.SendBlockListenModePacket.md) as a raw BlockListen feature-packet consumer that sends `{0x0d, 0x01}` length `2` through `g_packetSender->QueueAndSendPacket`, with no Socket ownership change and no reuse of stale `g_pCashShopRequest` aliases.
- 2026-06-26 B006 ChangeItemSlot raw-sender support sync:
  - Added [UID:00042U][0x005b31a0-0x005b3215.ChangeItemSlotPacketRawSender](by-memory/0x005b31a0-0x005b3215.ChangeItemSlotPacketRawSender.md) as the retained no-route item-slot raw sender companion to [UID:0001M6][0x005b3010-0x005b3196.ChangeItemSlotInputPane](by-memory/0x005b3010-0x005b3196.ChangeItemSlotInputPane.md).
  - Evidence: B006 MCP session `80de0a67` confirms both paths build opcode `0x30`, subcommand `0`, source/destination slot bytes, and send length `4` through this global. Socket ownership for `g_packetSender` remains unchanged.
- 2026-06-29 B001 UID00042U support sync:
  - Historicalized active `simroot_v2/class_Socket.cpp` wording as generated lead material and updated UID00042U from blank-C++ consumer to source-bearing `SendChangeItemSlotPacket` consumer through [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md).
  - Evidence: current MCP session `d4d50b81` and supplemental PE route scan preserve no modeled function/xref/pointer/rel32 route for UID00042U, but exact opcode `0x30`, subcommand `0`, source/destination stack bytes, local-only terminator, and send length `4` through `g_packetSender->QueueAndSendPacket` remain concrete feature-consumer/type evidence. Socket ownership of `g_packetSender` is unchanged.
- 2026-06-26 B006 SayToGroupMessageInputPane support sync:
  - Added [UID:0001LZ][0x005b1ec0-0x005b2152.SayToGroupMessageInputPane](by-memory/0x005b1ec0-0x005b2152.SayToGroupMessageInputPane.md) as a feature packet-builder consumer for opcode `0x19` group-name/message sends.
  - Evidence: B006 MCP session `80de0a67` confirms the target submit method serializes group-name length/bytes and message length/bytes inline, computes `packetLength = groupNameLen + messageLen + 3`, writes a local-only terminator outside the sent length, and calls `g_packetSender->QueueAndSendPacket(packet, static_cast<short>(packetLength))`. This preserves [UID:0000NS][Socket](by-file/Socket.md) ownership and does not add formal C++ to this global page.
- 2026-06-26 B006 EmotionInputPane support sync:
  - Added [UID:0001M4][0x005b2f70-0x005b2fcb.SendEmotionPacket](by-memory/0x005b2f70-0x005b2fcb.SendEmotionPacket.md) as the packet-builder consumer reached by [UID:0001M3][0x005b29c0-0x005b2f68.EmotionInputPane](by-memory/0x005b29c0-0x005b2f68.EmotionInputPane.md).
  - Evidence: B006 MCP session `80de0a67` confirms the Emotion handler computes selector values from the `a-l`, `m-n`, and `o-p` input ranges before calling the helper; the helper builds opcode `0x1d`, writes the selector byte, clears a local-only scratch byte, and sends length `2` through `g_packetSender->QueueAndSendPacket`. This is consumer/type evidence only; [UID:0000NS][Socket](by-file/Socket.md) ownership, scores, and blank formal C++ remain unchanged.
- 2026-06-28 B009 GroupInputPane submit support sync:
  - Added [UID:0001MJ][0x005b5440-0x005b5547.GroupInputPane](by-memory/0x005b5440-0x005b5547.GroupInputPane.md) as a source-ready opcode `0x2e` group-command submit consumer.
  - Evidence: B009 MCP session `agent_b009_0002my_20260628` confirms the method writes opcode `0x2e`, one-byte encoded length, converted text bytes, local-only terminators, and sends exactly `encodedLength + 2` through `g_packetSender->QueueAndSendPacket`. This is consumer/type evidence only; [UID:0000NS][Socket](by-file/Socket.md) ownership, scores, and blank formal C++ remain unchanged.
