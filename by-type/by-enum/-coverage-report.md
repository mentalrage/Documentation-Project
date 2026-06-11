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
- [UID:0001SK][BrowserInitFlags](by-type/by-enum/BrowserInitFlags.md) : reconstructable : 82% : strong : Provisional Browser `0x0101` state-word/bitmask initializer with live constructor-window evidence, Browser subobject placement, exact `+0x22c` write, adjacent field separation, scoped cluster scan, parent attachment, and enum-vs-bitmask caveat documented.
- [UID:0001SL][BrowserMessageId](by-type/by-enum/BrowserMessageId.md) : reconstructable : 80% : strong : Browser window/thread message constants attached to Browser, with legacy control message cases `15/256/257/260/261`, private thread messages `1280/1281`, Win32-versus-private declaration boundary, paint/key filtering, PlatformApi `SendMessageW` dispatch-slot separation, redraw handling, consumer split, and browser-module placement documented; final symbolic names remain provisional.
- [UID:0001SM][BrowserOverlayStyle](by-type/by-enum/BrowserOverlayStyle.md) : reconstructable : 80% : strong : Browser overlay constants `236` and `128` with value-use map, localized-string lookup, style-helper call, overlay-state gate exclusion, declaration-boundary notes, browser parent attachment, BrowserControlPaneOld evidence, source migration checklist, reconstruction guidance, resource cross-reference, and keep-out rules documented; final enum-vs-constant declaration remains open.
- [UID:0001SN][HttpGetNotificationState](by-type/by-enum/HttpGetNotificationState.md) : reconstructable : 86% : strong : A004 Batch 097 assigned to [UID:000069][httpget__Notification](by-class/httpget__Notification.md) after live IDA confirmed `FetchHTTPContent` producer states `0-4`, `ProcessWorkItem` `GeHt` dispatch, `0x68747470` post channel, `_AUTOBUF<unsigned char>` chunk payloads, and destructor-owned payload release for states `1` and `4`; final enum declaration names remain provisional.
- [UID:0001SO][MapServerPacketOpcode](by-type/by-enum/MapServerPacketOpcode.md) : reconstructable : 80% : strong : MapPane inbound opcode index with dispatcher boundary, MapPane-switch scope limits, route categories, observed packet values, representative case targets, Socket packet-name-table cross-checks for selected labels, day/night raw-body caveat, friend-name-list sync trigger, dialog/object/weather/timer routes, MapPane parent attachment, ServerPacketNameTable separation, declaration-readiness notes, and protocol-name caveats documented.
- [UID:0001SP][MiscWorkThreadMessageId](by-type/by-enum/MiscWorkThreadMessageId.md) : reconstructable : 74% : strong : MiscWorkThread async message constants with FourCC-like ids for directory browse, HTTP fetch, and NCA update, worker switch behavior, payload cleanup, notification channels, and default Thread fallback documented.
- [UID:0001SQ][NcauthNotificationState](by-type/by-enum/NcauthNotificationState.md) : reconstructable : 80% : strong : NCA auth/update notification states; live IDA confirms producer values, payload state offset `+4`, the only `NCAu` consumer compare, success handling for state `0`, and localized message-id mapping for states `1-5`.
- [UID:0001SR][ThreadManMessageId](by-type/by-enum/ThreadManMessageId.md) : reconstructable : 74% : strong : ThreadMan private Win32 message-id group `0x0464-0x0468` with raw PostThreadMessage wrappers, worker-loop switch cases, watch-record registration/unregistration/probe handling, and separation from generic Thread queue messages documented.

## Covered Items To Ignore

- None recorded yet.

## Uncovered Items

- by-type/by-enum inventory baseline : uncovered : 0% : open : Full authoritative inventory for by-type/by-enum is not yet proven complete; compare this report against Wave3 when OPERATIONAL, simroot_v2, and IDA/MCP evidence.
