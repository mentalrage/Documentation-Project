*** UID:0000UP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Friend Name-List Sync Opcodes

## Status

- Confidence: strong for the observed inbound/outbound relationship; medium for final protocol names.
- Scope: inbound [UID:0001SO][MapServerPacketOpcode](by-type/by-enum/MapServerPacketOpcode.md) case `0x6a` and outbound opcode `0x77`.
- Evidence basis: IDA MCP `xrefs`, disassembly, and Hex-Rays checks on 2026-05-30.

## Inbound Opcode `0x6a`

[UID:0000L3][MapPane](by-file/MapPane.md) case `0x6a` reads one byte at payload cursor `1` through the shared packet byte reader, stores [UID:0000PG][byte_66DEE0](by-global/byte_66DEE0.md) to `value != 0`, and returns success.

If that byte is nonzero, the branch immediately calls [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendInventoryData](by-memory/0x00574e50-0x0057536b.BuildAndSendInventoryData.md) through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md).

IDA address evidence, refreshed 2026-05-30:

- The case body begins at `0x00508ae3`, annotated by IDA as `jumptable 00507CE2 case 106`.
- It calls the byte reader at `0x00508af5`.
- It writes `byte_66dee0` at `0x00508aff`.
- It calls `sub_574E50` at `0x00508b14` only when the byte is nonzero.
- The containing IDA function is `sub_507C90`, `0x00507c90-0x00508e06`; the case entry is reached through jump table `jpt_507CE2`.

A second raw function-shaped body at [UID:0001AZ][0x00514380-0x005143b7.FriendNameListSyncRawHandler](by-memory/0x00514380-0x005143b7.FriendNameListSyncRawHandler.md) performs the same read/write/send sequence but currently has no IDA function object or direct xrefs to its start. Treat it as corroborating raw evidence, not the primary live route.

## Outbound Opcode `0x77`

[UID:0001HX][0x00574e50-0x0057536b.BuildAndSendInventoryData](by-memory/0x00574e50-0x0057536b.BuildAndSendInventoryData.md) builds opcode `0x77` from the 20 saved config string slots at `g_pConfig + 2691552` through `g_pConfig + 2691632`.

IDA reports `sub_574E50` as `0x00574e50-0x0057536b`. Its direct callers/xrefs are the MapPane `0x6a` branch at `0x00508b14`, raw mirror body `0x005143ad`, and [UID:0000JN][FriendListDialog](by-file/FriendListDialog.md) OK/save path `0x0053f8ed`. `byte_66DEE0` is set at `0x00508aff` and `0x0051439c`, and checked at `0x0053f8dc` before the dialog save path sends the same upload.

Observed outbound layout:

| Offset | Value |
| --- | --- |
| `0` | Opcode `0x77`. |
| `1` | Unique-name count. |
| `2+` | Repeated 13-byte records. Each record starts with `0x0c`, followed by 12 bytes copied from the narrow/ANSI name. |

The helper deduplicates nonempty names before writing them, allocates `packetSize + 1`, appends a zero byte, and queues the packet through request code `8`.

## Feature Interpretation

The old provisional name `BuildAndSendInventoryData` was misleading. [UID:00005J][FriendListDialog](by-class/FriendListDialog.md) writes the same 20 config slots before this helper is called, and IDA shows the other call path is inbound map opcode `0x6a`. Current best interpretation is a server-enabled friend/name-list sync: the server sends opcode `0x6a` with an enable/request byte, the client stores [UID:0000PG][byte_66DEE0](by-global/byte_66DEE0.md), and the client replies with opcode `0x77` containing the deduplicated configured names whenever the flag is enabled. `FriendListDialog::OnOkButton` also checks the same flag after saving the edited names.

Keep the UI editor in [UID:0000JN][FriendListDialog](by-file/FriendListDialog.md). Keep the packet upload helper in the current request-sender cluster until the broader [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md) / queue-interface boundary is resolved.

The former `g_isCashShopEnabled` alias mapped to this same flag and should not be used for new documentation.

## FriendListDialog Save Path

IDA decompilation of `sub_53F830`, `0x0053f830-0x0053f921`, shows the dialog OK path iterating 20 entries, reading text control values, storing them back to `g_pConfig + 2691552 + slot*4`, trimming or normalizing against `off_67027C`, checking `byte_66DEE0`, and calling `sub_574E50(g_packetSender)` only when the flag is enabled. This ties the UI editor, global flag, and outbound opcode helper together without relying on generated source names.

## Cross-References

- [UID:0001SO][MapServerPacketOpcode](by-type/by-enum/MapServerPacketOpcode.md)
- [UID:0001QK][client_opcodes](by-meta/client_opcodes.md)
- [UID:0001QH][client_network](by-meta/client_network.md)
- [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendInventoryData](by-memory/0x00574e50-0x0057536b.BuildAndSendInventoryData.md)
- [UID:0000PG][byte_66DEE0](by-global/byte_66DEE0.md)
- [UID:0001OM][0x0066dee0-0x0066dee1.FriendNameListSyncEnabled](by-memory/0x0066dee0-0x0066dee1.FriendNameListSyncEnabled.md)
- [UID:0001AZ][0x00514380-0x005143b7.FriendNameListSyncRawHandler](by-memory/0x00514380-0x005143b7.FriendNameListSyncRawHandler.md)
- [UID:0001HT][0x00574b90-0x00575377.CashShopRequestSendQueue](by-memory/0x00574b90-0x00575377.CashShopRequestSendQueue.md)
- [UID:0000JN][FriendListDialog](by-file/FriendListDialog.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)

## Changes

- Before: the page had `COMPLETION:0` and `CONFIDENCE:0`, and its evidence section referenced current generated output state.
- Changed to: `COMPLETION:78` and `CONFIDENCE:86`, with the evidence basis rewritten around IDA xrefs, disassembly, and Hex-Rays for the map case, outbound packet builder, raw mirror handler, global flag, and FriendListDialog save path.
- Summary/evidence: IDA MCP on 2026-05-30 confirms `sub_507C90` case `0x6a` at `0x00508ae3`, `sub_574E50` at `0x00574e50-0x0057536b`, raw mirror code at `0x00514380-0x005143b7`, global writes/checks for `byte_66DEE0`, and `sub_53F830` calling the sender after saving the 20 configured names.
