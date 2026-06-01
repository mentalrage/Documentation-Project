*** UID:0000PG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_friendNameListSyncEnabled

## Status

- Confidence: strong for address, observed use, and current source-facing name.
- Address: `0x0066dee0`.
- Exact memory: [UID:0001OM][0x0066dee0-0x0066dee1.FriendNameListSyncEnabled](by-memory/0x0066dee0-0x0066dee1.FriendNameListSyncEnabled.md).
- Current Wave3 id: `g_friendNameListSyncEnabled`.
- Former aliases: `byte_66DEE0`, `g_isCashShopEnabled`.
- Type/owner: `bool`, owned by `class_FriendListDialog.cpp`.

## Purpose

`g_friendNameListSyncEnabled` records whether the client should upload the configured friend/name-list data through outbound opcode `0x77`.

The server-facing path sets it from inbound map opcode `0x6a`. The social UI path reads it after [UID:0000JN][FriendListDialog](by-file/FriendListDialog.md) saves the 20 edited name slots; if it is set, the client sends [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendInventoryData](by-memory/0x00574e50-0x0057536b.BuildAndSendInventoryData.md). Former generated method/global names made this look like cash-shop or inventory code, but current caller and config-slot evidence favors friend/name-list sync.

## Evidence Notes

- IDA MCP `xrefs_to 0x0066dee0` on 2026-05-25 reports writes from `MapPane::HandlePacket` opcode `0x6a` at `0x00508aff` and the raw duplicate handler at `0x0051439c`, plus a read from `FriendListDialog::OnOkButton` at `0x0053f8dc`.
- IDA MCP disassembly at `0x00508af0` shows the opcode case reads one packet byte through `0x00575710`, stores `setnz byte_66DEE0`, and calls `0x00574e50` only when the byte is nonzero. Wave3 now exposes that storage as `g_friendNameListSyncEnabled`.
- IDA MCP disassembly at `0x0053f8dc` shows `FriendListDialog::OnOkButton` checks this byte before calling the same upload helper, then saves user settings and closes the dialog.
- Current `simroot_v2/class_FriendListDialog.cpp` defines `bool g_friendNameListSyncEnabled`.
- Current `simroot_v2/class_MapPane.cpp` declares `extern bool g_friendNameListSyncEnabled` and updates it from inbound opcode `0x6a`.

## Ownership

Current Wave3 ownership is `class_FriendListDialog.cpp`, with MapPane as a protocol writer. Do not assign it to cash-shop. The protocol/social name should remain unless later source evidence proves a narrower owner.

## Cross-References

- [UID:0001OM][0x0066dee0-0x0066dee1.FriendNameListSyncEnabled](by-memory/0x0066dee0-0x0066dee1.FriendNameListSyncEnabled.md)
- [UID:0000UP][FriendNameListSyncOpcodes](by-item/FriendNameListSyncOpcodes.md)
- [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendInventoryData](by-memory/0x00574e50-0x0057536b.BuildAndSendInventoryData.md)
- [UID:0001AZ][0x00514380-0x005143b7.FriendNameListSyncRawHandler](by-memory/0x00514380-0x005143b7.FriendNameListSyncRawHandler.md)
- [UID:0000JN][FriendListDialog](by-file/FriendListDialog.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0001QH][client_network](by-meta/client_network.md)
- [Wave3 data issue](../wave3_data_issues.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `86/84`. Summary/evidence: the page documents the address, current and former aliases, protocol/UI purpose, IDA xref evidence, ownership, and data-issue refs, with strong support for the current friend/name-list sync identity.
