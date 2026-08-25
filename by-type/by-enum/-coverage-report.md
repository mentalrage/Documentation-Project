*** UID:0001SG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# by-type/by-enum Coverage Report

## Summary

- Last generated: 2026-05-26
- Folder: `by-type/by-enum`
- Coverage summary: 9 covered reconstructable rows, 0 covered ignored rows, 1 uncovered inventory placeholder row.
- Confidence summary: baseline report generated from existing documentation pages and `-ignored.md`; ignored rows are driven by the local ignored ledger, while reconstructable row confidence is heuristic until IDA/MCP or manual verification raises it.
- Ordering: alphabetic by item name, except `by-memory`, which is sorted by the first address in the row.

## Covered Items To Replicate

- [UID:0001SJ][BrowserDispatchEventId](by-type/by-enum/BrowserDispatchEventId.md) : reconstructable : 86% : strong : A004 Batch 097 assigned to [UID:0000HV][Browser](by-file/Browser.md) after live IDA confirmed BrowserControlPane dispatch cases `104/250/251/252/259/263/270`, BrowserWindow old-host overlap for `250/251/252/259/263/270`, navigation URL/cancel-pointer/token behavior, browser COM/event declaration ownership, and browser-specific fallback behavior; final symbolic names remain provisional.
- [UID:0001SK][BrowserInitFlags](by-type/by-enum/BrowserInitFlags.md) : reconstructable : 86% : strong : Provisional Browser `0x0101` state-word/bitmask initializer; A002 2026-06-16 live IDA reconfirmed Browser constructor size/caller, five vtable stores, nearby member clears, exact `+0x22c` write, `+0x230` member construction, owner route, absence of Browser local type evidence, and enum-vs-bitmask caveat.
- [UID:0001SL][BrowserMessageId](by-type/by-enum/BrowserMessageId.md) : reconstructable : 85% : strong : Browser window/thread message constants attached to Browser, with live IDA confirmation of legacy control message cases `15/256/257/260/261`, private thread messages `1280/1281`, close-message `PostThreadMessageA` producers, Win32-versus-private declaration boundary, PlatformApi `SendMessageW` dispatch-slot separation, redraw handling, consumer split, and browser-module placement documented; final symbolic names and redraw producer remain provisional.
- [UID:0001SM][BrowserOverlayStyle](by-type/by-enum/BrowserOverlayStyle.md) : reconstructable : 86% : strong : Browser overlay constants `236` and `128` attached to Browser; A002 2026-06-16 live IDA refresh reconfirmed `DrawBrowserStatusOverlay` bounds, vtable anchor, overlay-state gate, localized-string lookup, style-helper call, broad generic helper fan-in, absence of Browser-specific local enum evidence, source migration checklist, and keep-out rules; final enum-vs-constant declaration remains open.
- [UID:0001SN][HttpGetNotificationState](by-type/by-enum/HttpGetNotificationState.md) : reconstructable : 86% : strong : A004 Batch 097 assigned to [UID:000069][httpget__Notification](by-class/httpget__Notification.md) after live IDA confirmed `FetchHTTPContent` producer states `0-4`, `ProcessWorkItem` `GeHt` dispatch, `0x68747470` post channel, `_AUTOBUF<unsigned char>` chunk payloads, and destructor-owned payload release for states `1` and `4`; final enum declaration names remain provisional.
- [UID:0001SO][MapServerPacketOpcode](by-type/by-enum/MapServerPacketOpcode.md) | observed inbound opcode index | MapServerPacketOpcode : reconstructable : 88% : very strong : MapPane inbound opcode index with exact opcode-0x15 direct bool dispatch to source-ready HandleEffectMapStatePacket and its map/dimension/flags/name/day-night/config payload, exact opcode-0x20 hour/minute validation and brightness-table mapping, corrected quadratic tint-not-duration semantics, SetDayNightFadeTarget route, retained UID0001AX raw duplicate evidence, and exact opcode-0x1d direct bool dispatch to source-ready HandleObjectStatusPacket with BE32 object id, full/partial ObjectStatusBlob, object-info byte, counted ACP name, living/item refresh behavior and unconditional success; blank formal enum remains correct because original constant spellings and unrelated case payloads remain unproven.
- [UID:0001SP][MiscWorkThreadMessageId](by-type/by-enum/MiscWorkThreadMessageId.md) : reconstructable : 86% : strong : MiscWorkThread async message constants now attached to [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md); A005 Batch 174 live IDA rechecked the `ProcessWorkItem` switch, HTTP/NCA modeled producers, raw browse-directory producer, payload cleanup, notification channels, default Thread fallback, and `int_convert.py` value pairs.
- [UID:0001SQ][NcauthNotificationState](by-type/by-enum/NcauthNotificationState.md) : reconstructable : 88% : very-strong : Six-value ncauth::NotificationState enum emitted in UID00008X's MiscWorkThread.h namespace child position, with Accepted=0, IdRejected=1, PasswordRejected=2, RejectedOther=3, OpenFailed=4, ReadFailed=5, exact producer immediates at 0x00527c43, 0x005285bc, and 0x0053025a, payload state offset +4, and complete registration-dialog consumer mapping; raw CPP enum duplication is removed.
- [UID:0001SR][ThreadManMessageId](by-type/by-enum/ThreadManMessageId.md) : reconstructable : 85% : very-strong : Assigned to [UID:0000EW][ThreadMan](by-class/ThreadMan.md) after A004 Batch 173 live IDA MCP reconfirmed the raw wrapper starts, worker-loop function/caller, `0x0464-0x0468` / `1124-1128` message cases, and `ThreadManWatchRecord` effects; final symbolic names and header spelling remain below the 95/95 C++ gate.

## Covered Items To Ignore

- None recorded yet.

## Uncovered Items

- by-type/by-enum inventory baseline : uncovered : 0% : open : Full authoritative inventory for by-type/by-enum is not yet proven complete; compare this report against Wave3 when OPERATIONAL, simroot_v2, and IDA/MCP evidence.
