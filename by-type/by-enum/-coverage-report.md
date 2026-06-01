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

- [UID:0001SJ][BrowserDispatchEventId](by-type/by-enum/BrowserDispatchEventId.md) : reconstructable : 50% : medium : - Confidence: strong for observed DISPIDs, medium for final enum name.
- [UID:0001SK][BrowserInitFlags](by-type/by-enum/BrowserInitFlags.md) : reconstructable : 68% : medium-high : - Provisional Browser initial state word `0x0101`; IDA verifies the constructor write, while final enum/bitmask declaration remains open.
- [UID:0001SL][BrowserMessageId](by-type/by-enum/BrowserMessageId.md) : reconstructable : 50% : medium : - Confidence: strong for observed values, medium for final enum name.
- [UID:0001SM][BrowserOverlayStyle](by-type/by-enum/BrowserOverlayStyle.md) : reconstructable : 50% : medium : - Confidence: strong for observed values and owner; medium for original enum/constant name.
- [UID:0001SN][HttpGetNotificationState](by-type/by-enum/HttpGetNotificationState.md) : reconstructable : 50% : medium : - Confidence: strong for observed state values, medium for final names.
- [UID:0001SO][MapServerPacketOpcode](by-type/by-enum/MapServerPacketOpcode.md) : reconstructable : 50% : medium : - Confidence: strong for observed opcode values in `MapPane::HandlePacket`, medium for many working names.
- [UID:0001SP][MiscWorkThreadMessageId](by-type/by-enum/MiscWorkThreadMessageId.md) : reconstructable : 50% : medium : - Confidence: strong for observed values, medium for final symbolic names.
- [UID:0001SQ][NcauthNotificationState](by-type/by-enum/NcauthNotificationState.md) : reconstructable : 50% : medium : - Confidence: medium for semantic names, strong for values.
- [UID:0001SR][ThreadManMessageId](by-type/by-enum/ThreadManMessageId.md) : reconstructable : 50% : medium : - Kind: Win32 message-id group

## Covered Items To Ignore

- None recorded yet.

## Uncovered Items

- by-type/by-enum inventory baseline : uncovered : 0% : open : Full authoritative inventory for by-type/by-enum is not yet proven complete; compare this report against Wave3 when OPERATIONAL, simroot_v2, and IDA/MCP evidence.
