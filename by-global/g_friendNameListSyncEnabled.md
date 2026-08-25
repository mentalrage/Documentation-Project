*** UID:0000PG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JN | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JN | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_friendNameListSyncEnabled

## Status

- Confidence: very strong for address, one-byte bool type, true initializer, exact references, source-facing role, external linkage, and sole-definition route; exact original lexical/header spelling remains the only cap.
- Address: `0x0066dee0`.
- Exact memory: [UID:0001OM][0x0066dee0-0x0066dee1.FriendNameListSyncEnabled](by-memory/0x0066dee0-0x0066dee1.FriendNameListSyncEnabled.md).
- Current source-facing id: `g_friendNameListSyncEnabled`.
- Former aliases: `byte_66DEE0`, `g_isCashShopEnabled`.
- Type/owner: external `bool`, owned by [UID:0000JN][FriendListDialog](by-file/FriendListDialog.md) at `NexusTK/social/FriendListDialog.cpp`.
- Emission: this semantic page is a child container. Exact storage child [UID:0001OM][0x0066dee0-0x0066dee1.FriendNameListSyncEnabled](by-memory/0x0066dee0-0x0066dee1.FriendNameListSyncEnabled.md) emits the sole `.cpp` definition `bool g_friendNameListSyncEnabled = true;`.
- Header declaration: consuming translation units require `extern bool g_friendNameListSyncEnabled;` in a shared declaration header. The original header filename is not recovered, so that requirement is documented in prose and is deliberately not emitted beside the definition in `FriendListDialog.cpp`.

## Purpose

`g_friendNameListSyncEnabled` records whether the client should upload the configured friend/name-list data through outbound opcode `0x77`.

The server-facing path sets it from inbound map opcode `0x6a`. The social UI path reads it after [UID:0000JN][FriendListDialog](by-file/FriendListDialog.md) saves the 20 edited name slots; if it is set, the client sends [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendFriendNameListSync](by-memory/0x00574e50-0x0057536b.BuildAndSendFriendNameListSync.md). Former method/global aliases made this look like cash-shop or inventory code, but current caller and config-slot evidence favors friend/name-list sync.

## Evidence Notes

- IDA MCP `xrefs_to 0x0066dee0` on 2026-05-25 reports writes from `MapPane::HandlePacket` opcode `0x6a` at `0x00508aff` and the raw duplicate handler at `0x0051439c`, plus a read from `FriendListDialog::OnOkButton` at `0x0053f8dc`.
- 2026-06-18 B004 rechecked the raw duplicate write at `0x0051439c` and corrected that raw body's full range to [UID:0001AZ][0x00514380-0x005143ba.FriendNameListSyncRawHandler](by-memory/0x00514380-0x005143ba.FriendNameListSyncRawHandler.md). The write remains part of a no-route retained duplicate of the live opcode `0x6a` branch, not evidence for a cash-shop owner.
- IDA MCP disassembly at `0x00508af0` shows the opcode case reads one packet byte through `0x00575710`, stores `setnz byte_66DEE0`, and calls `0x00574e50` only when the byte is nonzero.
- IDA MCP disassembly at `0x0053f8dc` shows `FriendListDialog::OnOkButton` checks this byte before calling the same upload helper, then saves user settings and closes the dialog.
- IDA MCP recheck on 2026-06-05 confirmed three direct xrefs: writes from map packet opcode paths at `0x00508aff` and `0x0051439c`, plus the `FriendListDialog::OnOkButton` read at `0x0053f8dc`.
- 2026-06-14 live IDA MCP refresh under session `b001_0002bd` reconfirmed `xrefs_to 0x0066dee0` as exactly those same three refs: `0x00508aff` in `sub_507C90`, raw/no-function site `0x0051439c`, and `0x0053f8dc` in `sub_53F830`.
- The same refresh reconfirmed related sender-helper refs to `sub_574E50` at `0x00508b14`, raw/no-function site `0x005143ad`, and `0x0053f8ed`, tying each flag write/read path to the friend-name-list upload route.
- `get_bytes 0x0066dedc` returned `28 00 28 00 01 00 00 00 64 12 62 00 53 00 55 00`; the byte at `0x0066dee0` is the `01` in that sequence, confirming the observed initialized storage for this bool.

## 2026-07-20 B003 Source Closure

- Live IDA MCP database `9b0396a3` was healthy with auto-analysis, Hex-Rays, and strings cache ready. The exact one-byte image value is `01`; target-byte SHA256 is `4BF5122F344554C53BDE2EBB8CD2B7E3D1600AD631C385A5D7CCE23C7785459A`.
- Exactly three direct storage refs exist: live MapPane write `0x00508aff`, retained no-entry raw duplicate write `0x0051439c`, and FriendListDialog read `0x0053f8dc`. No ref reaches successor bytes `0x0066dee1-0x0066dee3`.
- The live opcode `0x6a` / 106 branch starts with payload cursor `1`, reads exactly one byte, advances the cursor once, stores `value != 0`, calls the Socket-owned sender at `0x00508b14` only when true, and returns success in both states.
- [UID:0001AZ][0x00514380-0x005143ba.FriendNameListSyncRawHandler](by-memory/0x00514380-0x005143ba.FriendNameListSyncRawHandler.md) repeats read/store/conditional-send behavior but has no function object, caller, entry xref, absolute pointer, RVA pointer, or independent source route. It remains retained source-covered raw evidence, not a second definition or function.
- FriendListDialog reads the same bool only after copying, trimming, and storing all twenty configured names. A true value calls `g_packetSender->BuildAndSendFriendNameListSync()`, then `SaveUserSettings()` runs unconditionally before dialog close/removal.
- The sender serializes outbound opcode `0x77` / 119 from the twenty config slots, deduplicates nonempty names, writes a count byte plus fixed 13-byte records beginning with marker `0x0c`, and queues request code `8`.
- External linkage is required because accepted MapPane and FriendListDialog source routes directly reference the same storage and no accessor exists. File-local `static`, anonymous-namespace storage, function-local static, duplicate definitions, and a same-TU redundant `extern` are rejected.
- Source ownership remains UID0000JN `NexusTK/social/FriendListDialog.cpp`: MapPane is the protocol writer and Socket is the serializer. Physical OptionPane/Palette adjacency and historical cash-shop/inventory aliases do not transfer ownership.
- Exact range remains `0x0066dee0-0x0066dee1`; [UID:00027X][0x0066dee1-0x0066dee4.FriendNameOptionPalettePadding](by-memory/0x0066dee1-0x0066dee4.FriendNameOptionPalettePadding.md) remains separate three-byte zero padding and [UID:00027Y][0x0066dee4-0x0066df00.OptionPaletteStaticResourceData](by-memory/0x0066dee4-0x0066df00.OptionPaletteStaticResourceData.md) begins the next data item.
- Historical names `byte_66DEE0`, `g_isCashShopEnabled`, and cash-shop/inventory helper interpretations remain search provenance only. The best source-facing spelling is `g_friendNameListSyncEnabled`.

## Score Rationale

| Field | Score | Rationale |
| --- | --- | --- |
| Completion | `92` | Exact storage/type/initializer, three refs, packet/UI/helper flow, external linkage, source owner, semantic path, child-emitted sole definition, separate shared-header declaration requirement, boundaries, raw duplicate, negatives, aliases, and formal container route are closed. |
| Confidence | `94` | Binary behavior, width, initializer, refs, owner/emitter, and one-definition model are very strong. The cap below 95 is only exact original symbol/header spelling, not behavior or rebuild readiness. |

## Ownership

Current ownership is [UID:0000JN][FriendListDialog](by-file/FriendListDialog.md), with MapPane as protocol writer and Socket as serializer. Exact child UID0001OM supplies the only `.cpp` definition through this semantic container. Do not assign storage ownership to cash-shop, MapPane, Socket, OptionPane, or Palette data.

## Cross-References

- [UID:0001OM][0x0066dee0-0x0066dee1.FriendNameListSyncEnabled](by-memory/0x0066dee0-0x0066dee1.FriendNameListSyncEnabled.md)
- [UID:0000UP][FriendNameListSyncOpcodes](by-item/FriendNameListSyncOpcodes.md)
- [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendFriendNameListSync](by-memory/0x00574e50-0x0057536b.BuildAndSendFriendNameListSync.md)
- [UID:0001AZ][0x00514380-0x005143ba.FriendNameListSyncRawHandler](by-memory/0x00514380-0x005143ba.FriendNameListSyncRawHandler.md)
- [UID:0000JN][FriendListDialog](by-file/FriendListDialog.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0001QH][client_network](by-meta/client_network.md)

## Changes

- 2026-07-20 B003 UID0001OM accepted callback:
  - Raised `87/87 -> 92/94`, set emitter position `0`, and populated exact container-only `[[CHILDREN]]` formal.
  - Closed bool/true initializer, exact three-ref lifecycle, packet/UI/Socket behavior, external linkage, sole-definition placement, separate shared-header declaration requirement, source ownership, padding boundaries, negative routes, and historical aliases.
  - The page is renamed validator-aware to `by-global/g_friendNameListSyncEnabled.md`; UID0000PG, owner/emitter UID0000JN, reconstructable state, and full history remain unchanged.

- 2026-06-18 B004 friend/name-list raw duplicate source-quality:
  - Updated [UID:0001AZ][0x00514380-0x005143ba.FriendNameListSyncRawHandler](by-memory/0x00514380-0x005143ba.FriendNameListSyncRawHandler.md) to corrected range `0x00514380-0x005143ba` and retained the `g_friendNameListSyncEnabled` interpretation. The old cash-shop alias remains rejected because live MapPane opcode `0x6a`, the raw duplicate, and `FriendListDialog` all use this byte for friend/name-list sync.
- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `86/84`. Summary/evidence: the page documents the address, current and former aliases, protocol/UI purpose, IDA xref evidence, ownership, and data-issue refs, with strong support for the current friend/name-list sync identity.
- 2026-06-05: Marked reconstructable and attached to [UID:0000JN][FriendListDialog](by-file/FriendListDialog.md).
  - Reason: live IDA MCP recheck confirms the bool is source-declared social dialog/protocol state: MapPane packet handlers write it, and `FriendListDialog::OnOkButton` consumes it before sending the friend-name list update.
- 2026-06-14: Raised completion/confidence from `86/84` to `87/87`.
  - Before: the page documented the global's purpose but confidence lagged because the live refs, related sender-helper refs, and initialized byte evidence were not all recorded together.
  - After: the page records current `xrefs_to` results, sender-helper linkage, raw/no-function mirror sites, initialized byte evidence, and a score rationale while keeping final source spelling/linkage provisional.
  - Evidence: live IDA MCP `xrefs_to` and `get_bytes` on 2026-06-14.
