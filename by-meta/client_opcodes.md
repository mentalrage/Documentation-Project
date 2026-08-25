*** UID:0001QK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Client Opcodes

Catalog all opcodes, analyze what they do, and record the code that consumes or emits them. This page should stay as the index; detailed opcode families should live in `by-type/by-enum`, `by-item`, or feature-specific docs.

## Current Opcode Families

- [UID:0001SO][MapServerPacketOpcode](by-type/by-enum/MapServerPacketOpcode.md) tracks the inbound map/game-world dispatch table owned by [UID:0000L3][MapPane](by-file/MapPane.md). The current table comes from `MapPane::HandlePacket` at `0x00507c90` and includes map transitions, object updates, weather/state changes, dialog creation, board/web-board paths, timer pane updates, and challenge/response packets.
- [UID:0000V1][PacketBufferHelpers](by-item/PacketBufferHelpers.md) document the shared scalar/string packet read/write helpers used across packet families.
- [UID:0000UP][FriendNameListSyncOpcodes](by-item/FriendNameListSyncOpcodes.md) documents inbound map opcode `0x6a` and outbound opcode `0x77`. Inbound `0x6a` sets [UID:0000PG][g_friendNameListSyncEnabled](by-global/g_friendNameListSyncEnabled.md) and, when enabled, triggers [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendFriendNameListSync](by-memory/0x00574e50-0x0057536b.BuildAndSendFriendNameListSync.md), which serializes the 20 friend/name-list config slots written by [UID:0000JN][FriendListDialog](by-file/FriendListDialog.md). The generated inventory name and `g_isCashShopEnabled` alias are provisional/misleading.
- [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md) documents outbound web-board request opcode `0x73` and packet/event byte `0x62` forwarding into active and old web-board response handlers.
- [UID:0001QH][client_network](by-meta/client_network.md) tracks socket framing, packet transforms, outbound send helpers, and cross-feature protocol notes.

## Open Work

- Split inbound and outbound opcode namespaces when enough packet builders are documented.
- Convert high-confidence packet groups into enum/type docs with feature ownership and payload layouts.
- Keep feature-owned packet builders with their feature modules unless evidence proves a central `ProtocolSend.cpp`.
