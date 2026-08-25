*** UID:0000UP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# Friend Name-List Sync Opcodes

## Status

- Confidence: strong for inbound/outbound behavior, exact flag storage, UI ordering, Socket-member ownership, raw-duplicate disposition, and source boundaries; inferred source naming remains the only material cap.
- Scope: inbound [UID:0001SO][MapServerPacketOpcode](by-type/by-enum/MapServerPacketOpcode.md) case `0x6a` / 106 and outbound opcode `0x77` / 119 (Verified with `int_convert.py`).
- Evidence basis: IDA MCP `lookup_funcs`, `xrefs_to`, `callees`, `get_bytes`, disassembly, and Hex-Rays checks refreshed through 2026-06-14.

## Inbound Opcode `0x6a`

[UID:0000L3][MapPane](by-file/MapPane.md) case `0x6a` reads one byte at payload cursor `1` through the shared packet byte reader, stores [UID:0000PG][g_friendNameListSyncEnabled](by-global/g_friendNameListSyncEnabled.md) to `value != 0`, performs the enabled-only immediate synchronization call, and returns success from the containing dispatcher.

If that byte is nonzero, the branch immediately calls [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendFriendNameListSync](by-memory/0x00574e50-0x0057536b.BuildAndSendFriendNameListSync.md) through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md).

IDA address evidence, refreshed 2026-05-30:

- The case body begins at `0x00508ae3`, annotated by IDA as `jumptable 00507CE2 case 106`.
- It calls the byte reader at `0x00508af5`.
- It writes `byte_66dee0` at `0x00508aff`.
- It calls `sub_574E50` at `0x00508b14` only when the byte is nonzero.
- The containing IDA function is `sub_507C90`, `0x00507c90-0x00508e06`; the case entry is reached through jump table `jpt_507CE2`.

A second 58-byte raw function-shaped body at [UID:0001AZ][0x00514380-0x005143ba.FriendNameListSyncRawHandler](by-memory/0x00514380-0x005143ba.FriendNameListSyncRawHandler.md) performs the same read/write/send sequence but currently has no IDA function object or direct xrefs to its start. Treat it as corroborating raw evidence, not the primary live route.

## Outbound Opcode `0x77`

[UID:0001HX][0x00574e50-0x0057536b.BuildAndSendFriendNameListSync](by-memory/0x00574e50-0x0057536b.BuildAndSendFriendNameListSync.md) builds opcode `0x77` from the 20 saved config string slots at `g_pConfig + 2691552` through `g_pConfig + 2691632`.

The slot count is `0x14` / 20, and the verified config offsets are `0x2911e0` / 2691552 through `0x291230` / 2691632 (Verified with `int_convert.py`).

IDA reports `sub_574E50` as `0x00574e50-0x0057536b`. Its direct callers/xrefs are the MapPane `0x6a` branch at `0x00508b14`, raw mirror body `0x005143ad`, and [UID:0000JN][FriendListDialog](by-file/FriendListDialog.md) `OnControlCommand` save path `0x0053f8ed`. `g_friendNameListSyncEnabled` is set at `0x00508aff` and `0x0051439c`, and checked at `0x0053f8dc` after the dialog stores all twenty slots and before its Socket-member upload call.

Observed outbound layout:

| Offset | Value |
| --- | --- |
| `0` | Opcode `0x77`. |
| `1` | Unique-name count. |
| `2+` | Repeated 13-byte records. Each record starts with `0x0c`, followed by 12 bytes copied from the narrow/ANSI name. |

The helper deduplicates nonempty names before writing them, allocates `packetSize + 1`, appends a zero byte, and queues the packet through request code `8`.

## 2026-06-14 Live IDA Refresh

- `lookup_funcs` reconfirmed the primary MapPane dispatcher `sub_507C90` at `0x00507c90`, size `0x1176` / 4470 bytes; the FriendListDialog save path `sub_53F830` at `0x0053f830`, size `0xf1` / 241 bytes; and the sender helper `sub_574E50` at `0x00574e50`, size `0x51b` / 1307 bytes (Verified with `int_convert.py`).
- IDA still has no function object at raw mirror start `0x00514380`, and the next modeled function begins at `0x005143c0`. Byte evidence shows the raw mirror body ending with `retn 4`, followed by six `0xcc` bytes before the successor prologue.
- `xrefs_to 0x00574e50` reconfirmed three sender-helper references: `0x00508b14` inside `sub_507C90`, raw/no-function site `0x005143ad`, and `0x0053f8ed` inside `sub_53F830`.
- `xrefs_to 0x0066dee0` reconfirmed two writes at `0x00508aff` and raw/no-function site `0x0051439c`, plus the FriendListDialog read at `0x0053f8dc`.
- `get_bytes 0x0066dedc` shows `01 00 00 00` beginning at `0x0066dee0`, confirming the documented flag storage byte is initialized nonzero in the observed data image.
- `callees 0x00574e50` reconfirmed the packet-builder helper family and request/queue helpers, including `0x00516030`, `0x00516050`, `0x00516220`, `0x00596960`, and `0x00579710`; broader helper names remain provisional, so this item stays a routing/protocol note rather than an emitted source owner.

## 2026-06-16 Live IDA Refresh

- Live IDA MCP session `b001_selflookpane_0001H7_20260616` reconfirmed the same active NexusTK IDB (`NexusTK.exe`, image base `0x00400000`, Hex-Rays ready).
- `lookup_funcs` reconfirmed `sub_507C90` at `0x00507c90` size `0x1176`, raw mirror start `0x00514380` as not a function, successor `0x005143c0` size `0xbc`, `sub_53F830` at `0x0053f830` size `0xf1`, and `sub_574E50` at `0x00574e50` size `0x51b`.
- `xrefs_to 0x00574e50` again returned exactly three refs: `0x00508b14` in the MapPane dispatcher, raw/no-function site `0x005143ad`, and `0x0053f8ed` in the FriendListDialog save path. `xrefs_to 0x0066dee0` again returned the paired writes/read at `0x00508aff`, raw/no-function `0x0051439c`, and `0x0053f8dc`.
- `get_bytes 0x00514380 size 64` reconfirmed the raw duplicate body prologue, packet-byte read, `setnz byte_66DEE0`, flag-gated `call sub_574E50`, `retn 4`, and six `0xcc` bytes before `0x005143c0`.
- Decompilation of `0x00574e50` reconfirmed outbound opcode `119`, config-slot base `g_pConfig + 2691552`, twenty-slot iteration, fixed 13-byte record append with marker `12`, send-disabled byte at `this + 240206`, and queue dispatch through `sub_596960(..., 8, ...)`.

## Score Rationale

| Field | Score | Rationale |
| --- | --- | --- |
| Completion | `90` | The item records primary and raw inbound paths, exact cursor/value/return semantics, outbound helper route and packet layout, initialized bool definition, UI save-path ordering, Socket-member call, opcode values, config-slot offsets, direct xrefs, byte-level raw/flag evidence, and the complete non-emitting source boundary. |
| Confidence | `93` | Current IDA xrefs, function metadata, decompile snippets, bytes, exact source destinations, and supporting docs agree on the friend/name-list sync interpretation. The remaining cap is original packet/feature identifier spelling, not behavior, ownership, or routing. |

## Feature Interpretation

The old provisional name `BuildAndSendInventoryData` was misleading. [UID:00005J][FriendListDialog](by-class/FriendListDialog.md) writes the same 20 config slots before this helper is called, and IDA shows the other live call path is inbound map opcode `0x6a`. Current interpretation is a server-enabled friend/name-list sync: the server sends opcode `0x6a` with an enable/request byte, the client stores [UID:0000PG][g_friendNameListSyncEnabled](by-global/g_friendNameListSyncEnabled.md), and the client replies with opcode `0x77` containing the deduplicated configured names whenever the flag is enabled. `FriendListDialog::OnControlCommand` checks the same flag only after saving and trimming the edited names.

Keep the UI editor in [UID:0000JN][FriendListDialog](by-file/FriendListDialog.md). Keep the packet upload helper in the current request-sender cluster until the broader [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md) / queue-interface boundary is resolved.

The former `g_isCashShopEnabled` alias mapped to this same flag and should not be used for new documentation.

## 2026-06-16 Blocker Investigation

- Reconstructability/source ownership: this page remains `RECONSTRUCTABLE:FALSE` because it documents a protocol relationship, not a distinct source-emitting function, variable, enum, or table. The code-bearing pieces already live in MapPane, FriendListDialog, Socket/send-helper, and the exact global flag pages.
- Helper owner: the sender helper is still not a FriendListDialog method. Current xrefs show MapPane, FriendListDialog, and one raw flag-gated body all call `0x00574e50`; the helper also checks Socket state and queues command `8`, matching [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendFriendNameListSync](by-memory/0x00574e50-0x0057536b.BuildAndSendFriendNameListSync.md)'s Socket ownership.
- Raw mirror reachability: current `lookup_funcs`, `xrefs_to`, raw bytes, and B004 PE route scans still show no modeled function, direct xref, VA/RVA/raw-offset pointer, or rel32 control-flow route to `0x00514380`. Keep it as corroborating raw evidence rather than a second opcode owner.
- Protocol names: `FriendNameListSyncOpcodes`, `g_friendNameListSyncEnabled`, and `BuildAndSendFriendNameListSync` remain behavior-backed names. No current IDA symbol or packet-name table entry recovered the original source names for opcode `0x6a` or outbound `0x77`.

## FriendListDialog Save Path

IDA decompilation of `sub_53F830`, `0x0053f830-0x0053f921`, shows `FriendListDialog::OnControlCommand` iterating 20 entries, reading text control values, storing them back to `g_pConfig + 2691552 + slot*4`, trimming both sides against the wide whitespace literal, checking `g_friendNameListSyncEnabled`, and calling `g_packetSender->BuildAndSendFriendNameListSync()` only when the flag is enabled. The handler then calls `SaveUserSettings()` unconditionally before closing and removing the dialog. This ties the UI editor, global flag, Socket-owned outbound helper, and profile save boundary together from binary evidence.

## 2026-07-20 Source-Boundary Closure

- [UID:0001OM][0x0066dee0-0x0066dee1.FriendNameListSyncEnabled](by-memory/0x0066dee0-0x0066dee1.FriendNameListSyncEnabled.md) is the sole external bool definition, initialized `true`, and emitted through [UID:0000PG][g_friendNameListSyncEnabled](by-global/g_friendNameListSyncEnabled.md) in `FriendListDialog.cpp`; its cross-translation-unit declaration belongs in a shared header.
- The live inbound case owns packet parsing and the first conditional send. The no-entry raw mirror retains the same complete source body as corroborating/duplicate evidence but has no independent start route and is not emitted as a second handler.
- `FriendListDialog::OnControlCommand` owns UI read/trim/store and its second conditional send. The serializer remains a Socket member because its three callers, socket state checks, packet builder, and request-code-8 queue dispatch reject dialog, MapPane, cash-shop, or free-function ownership.
- This item remains `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, with blank emitter, position, and formal C++ because it is the protocol relationship across those source-emitting destinations, not an additional declaration or implementation.

## Cross-References

- [UID:0001SO][MapServerPacketOpcode](by-type/by-enum/MapServerPacketOpcode.md)
- [UID:0001QK][client_opcodes](by-meta/client_opcodes.md)
- [UID:0001QH][client_network](by-meta/client_network.md)
- [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendFriendNameListSync](by-memory/0x00574e50-0x0057536b.BuildAndSendFriendNameListSync.md)
- [UID:0000PG][g_friendNameListSyncEnabled](by-global/g_friendNameListSyncEnabled.md)
- [UID:0001OM][0x0066dee0-0x0066dee1.FriendNameListSyncEnabled](by-memory/0x0066dee0-0x0066dee1.FriendNameListSyncEnabled.md)
- [UID:0001AZ][0x00514380-0x005143ba.FriendNameListSyncRawHandler](by-memory/0x00514380-0x005143ba.FriendNameListSyncRawHandler.md)
- [UID:0001HT][0x00574b90-0x00575377.CashShopRequestSendQueue](by-memory/0x00574b90-0x00575377.CashShopRequestSendQueue.md)
- [UID:0000JN][FriendListDialog](by-file/FriendListDialog.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)

## Changes

- 2026-07-20 B003 source-quality implementation:
  - Raised the non-emitting protocol item from `86/89` to `90/93` while preserving `NONE/FALSE`, blank emitter/position/formal, and all existing opcode, packet-layout, xref, raw-range, and queue evidence.
  - Added exact cursor/read/store/conditional-send semantics, sole initialized global definition placement, UI save/trim/sync/save/close order, Socket-member ownership, raw no-entry source retention, and explicit source destination boundaries.
  - Historicalized `OnOkButton`, `byte_66DEE0`, `g_isCashShopEnabled`, inventory-data naming, and free-style send expressions as superseded aliases without discarding their provenance.

- 2026-06-18 B004 raw duplicate range/source-quality:
  - Updated [UID:0001AZ][0x00514380-0x005143ba.FriendNameListSyncRawHandler](by-memory/0x00514380-0x005143ba.FriendNameListSyncRawHandler.md) references to `0x00514380-0x005143ba`; the old `0x00514380-0x005143b7` range omitted the `ret 4` at `0x005143b7-0x005143ba`.
  - Preserved the protocol result: opcode `0x6a` is the live inbound control flag path, `g_friendNameListSyncEnabled` stores the nonzero flag, outbound opcode `0x77` is sent through `BuildAndSendFriendNameListSync`, and the raw duplicate remains corroborating evidence rather than a second source owner.
- 2026-06-05: Reconstructable metadata changed from blank to `FALSE`.
  - Before: the opcode relationship note was unclassified in autogen coverage.
  - After: it is explicitly non-reconstructable as a standalone item because it is protocol/routing documentation; the reconstructable source behavior belongs to MapPane, FriendListDialog, the packet sender helper, globals, and enum/type pages linked below.
  - Evidence: the page documents opcode `0x6a`, outbound opcode `0x77`, the global flag, and caller relationships, but it is not itself a separate function, declaration, or data object that should emit C++.

- Before: the page had `COMPLETION:0` and `CONFIDENCE:0`, and its evidence section mixed in non-authoritative output state.
- Changed to: `COMPLETION:78` and `CONFIDENCE:86`, with the evidence basis rewritten around IDA xrefs, disassembly, and Hex-Rays for the map case, outbound packet builder, raw mirror handler, global flag, and FriendListDialog save path.
- Summary/evidence: IDA MCP on 2026-05-30 confirms `sub_507C90` case `0x6a` at `0x00508ae3`, `sub_574E50` at `0x00574e50-0x0057536b`, raw mirror code at `0x00514380-0x005143ba`, global writes/checks for `byte_66DEE0`, and `sub_53F830` calling the sender after saving the 20 configured names.
- 2026-06-14: Raised completion/confidence from `78/86` to `85/88`.
  - Before: the page had the protocol relationship but lacked current function-size, raw-boundary, flag-byte, callee, and score-rationale evidence.
  - After: the page documents refreshed IDA function metadata, direct sender/flag xrefs, raw mirror no-function status, byte-level padding/initialization evidence, verified decimal conversions, and why it remains non-reconstructable as a standalone item.
  - Evidence: live IDA MCP `lookup_funcs`, `xrefs_to`, `callees`, and `get_bytes` on 2026-06-14 plus local `int_convert.py` checks.
- 2026-06-16 A002: Raised completion/confidence from `85/88` to `86/89`.
  - Before: the page already documented the protocol route but did not record a current recheck of the raw mirror bytes, sender decompile details, and non-emitting source-quality decision.
  - After: added a 2026-06-16 live IDA refresh and blocker investigation while keeping `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, and blank emitter fields.
  - Evidence: `lookup_funcs`, `xrefs_to`, `get_bytes`, and `decompile` on session `b001_selflookpane_0001H7_20260616` reconfirmed the two modeled caller paths, one raw no-function mirror, the same three flag refs, the initialized flag byte neighborhood, outbound opcode/slot/record/send queue behavior, and the absence of evidence for a standalone source-emitting owner.
