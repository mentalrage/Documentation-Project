** TARGET-REPORT-UID:00026H **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:00026H] ServerPacketNameTable Source-Routing Research

Assignment: `B001-goal2-memory-tool-server-packet-name-table-00026H-20260616`

Target: [UID:00026H][0x00625008-0x0062ce60.ServerPacketNameTable](../../../../../by-memory/0x00625008-0x0062ce60.ServerPacketNameTable.md)

## Final Recommendation

Do not move this table to `MapPane`, `PacketTransform`, `ProtocolSend`, or a new source root. The packet-name table and the two packet logging formats should remain Socket/protocol debug data under [UID:0000NS][Socket](../../../../../by-file/Socket.md), reconstructable as source-declared fixed `.rdata`, with final C++ still blank.

Do change the target boundary. The final `UNL.DLL` literal at `0x0062ce50-0x0062ce60` is not part of the packet-name table or packet logger. Live disassembly ties it to the adjacent `RegisterUniApp` literal at `0x0062ce60` through an unreferenced raw UniAPI registration helper at `0x00578ea0`. It should move out of [UID:00026H] and into the neighboring mixed non-emitting read-only-data support range.

Recommended target state after supervisor action:

- Rename/rerange [UID:00026H] to `by-memory/0x00625008-0x0062ce50.ServerPacketNameTable.md`.
- `COMPLETION:88`, `CONFIDENCE:90`.
- `CANONICAL_OWNER:0000NS`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000NS`.
- Final C++ remains blank.
- Keep `Socket.cpp` as the reconstruction route, but document that current live-use evidence is a retained raw debug logger with no direct callers.
- No immediate IDA DB edit.

Recommended support state:

- Expand/rename [UID:00026I] from `0x0062ce60-0x0062cfd8.AudioReadOnlyData` to a mixed non-emitting range starting at `0x0062ce50`, for example `by-memory/0x0062ce50-0x0062cfd8.NetworkAndAudioReadOnlyData.md`.
- Keep [UID:00026I] `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters and final C++.
- Update the shared coverage rows for [UID:00026H] and [UID:00026I]. The existing [UID:00026J] shared row is also stale from the earlier Batch 225 boundary repair; if the supervisor edits this local block, replace that row too.

## Current State Checked

Before this report, [UID:00026H] is:

- Path: `by-memory/0x00625008-0x0062ce60.ServerPacketNameTable.md`.
- Score: `80/88`.
- Owner/emitter: [UID:0000NS][Socket](../../../../../by-file/Socket.md).
- Disposition: `RECONSTRUCTABLE:TRUE`, blank final C++.
- Current page already identifies a `256 * 0x7e` UTF-16 packet-name table plus three tail strings, but explicitly leaves the full inventory and logging call path unresolved.

Generated/shared state checked:

- `auto-generated/by-memory-tool-report.md` lists this as reconstructable leaf range `0x00625008-0x0062ce60`, 32344 bytes.
- `auto-generated/-ag-memory-coverage.md` routes [UID:00026H] to `auto-generated/NexusTK/network/Socket.cpp`.
- `by-memory/-coverage-report.md` row still says `80%` and lists the full `0x00625008-0x0062ce60` range. It also has stale neighboring rows for [UID:00026I] and [UID:00026J].

Guidance basis:

- B001/source-structure guidance says ownership must follow direct semantic use and xref clusters, not address adjacency alone.
- `by-structure.md` allows source-declared `.rdata` to remain reconstructable when it is a single source artifact, but mixed-owner `.rdata` islands should become non-emitting indexes or exact children.
- `client_network.md`, `Socket.md`, `PacketTransform.md`, `ProtocolSend.md`, and `Session.md` keep the current network model split between Socket transport, PacketBuffer scalar helpers, PacketTransform key/XOR helpers, and non-promoted placeholders for ProtocolSend/Session.

## Binary And IDA Context

Live IDA MCP session:

- Session: `c001_midiplayer_rdata_20260615`.
- Input: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- IDB: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`.
- Imagebase: `0x400000`.
- `server_health`: status `ok`, Hex-Rays ready, strings cache ready, auto-analysis not ready in the inherited session. I therefore cross-checked table bytes and raw scans against the PE.

Raw PE:

- MD5: `4247e04e20b65d6414c7238aa8ff5515`.
- SHA-256: `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
- `.rdata`: `0x0060d000-0x0066c0be`, raw-backed through `0x0066c200`.
- Target bytes are raw-backed `.rdata`.

Conversions rechecked with `tools/int_convert.py`:

- `0x7e00` = 32256 bytes.
- `0x7e` = 126 bytes.
- `0x58` = 88 bytes.
- Current range size 32344 = `0x7e58`.
- Proposed [UID:00026H] range size `0x7e48` = 32328 bytes.
- `0x73` = 115; `0x74` = 116.

## Layout And Inventory

The PE-backed table inventory is:

- Table body: `0x00625008-0x0062ce08`, exactly 256 slots.
- Slot stride: `0x7e` bytes / 126 decimal bytes.
- Per-slot capacity: 63 UTF-16 code units including terminator/padding.
- Nonblank slots: 116, indices `0-115`.
- Blank zero-filled reserved slots: 140, indices `116-255`.
- Longest label: index `9`, `kServerNationAndTotemCheck`, 26 UTF-16 code units.
- No nonzero bytes after any slot's terminator.
- Packet logging formats: `0x0062ce08-0x0062ce50`.
- Non-packet tail to move: `0x0062ce50-0x0062ce60` `UNL.DLL`.

The packet logger guard at `0x00578f43` compares the first packet byte against `0x73`; for values `0-0x73` it computes `0x00625008 + opcode * 0x7e`. This exactly matches the last nonblank slot, index `115` / `0x73`, `kServerReconnect`. Slots `0x74-0xff` are real reserved table capacity, not missing decode work.

### Slot Inventory, Nonblank Entries

| Index | Address | Text |
|---:|---|---|
| 0 | `0x00625008` | `kServerVersionCheck` |
| 1 | `0x00625086` | `kServerNewUserCheck` |
| 2 | `0x00625104` | `kServerLoginCheck` |
| 3 | `0x00625182` | `kServerTileCheck` |
| 4 | `0x00625200` | `kServerUserPosition` |
| 5 | `0x0062527e` | `kServerUserAppearance` |
| 6 | `0x006252fc` | `kServerMap` |
| 7 | `0x0062537a` | `kServerDrawObjects` |
| 8 | `0x006253f8` | `kServerStatus` |
| 9 | `0x00625476` | `kServerNationAndTotemCheck` |
| 10 | `0x006254f4` | `kServerMessage` |
| 11 | `0x00625572` | `kServerMove` |
| 12 | `0x006255f0` | `kServerMoveObject` |
| 13 | `0x0062566e` | `kServerSay` |
| 14 | `0x006256ec` | `kServerRemoveObjects` |
| 15 | `0x0062576a` | `kServerAddInventory` |
| 16 | `0x006257e8` | `kServerRemoveInventory` |
| 17 | `0x00625866` | `kServerChangeDirection` |
| 18 | `0x006258e4` | `kServerCollection` |
| 19 | `0x00625962` | `kServerDamageEffect` |
| 20 | `0x006259e0` | `kServerNewPasswordCheck` |
| 21 | `0x00625a5e` | `kServerMapSize` |
| 22 | `0x00625adc` | `kServerFlyingObject` |
| 23 | `0x00625b5a` | `kServerAddSpell` |
| 24 | `0x00625bd8` | `kServerRemoveSpell` |
| 25 | `0x00625c56` | `kServerSoundEffect` |
| 26 | `0x00625cd4` | `kServerMotion` |
| 27 | `0x00625d52` | `kServerEnterEditingMode` |
| 28 | `0x00625dd0` | `#28` |
| 29 | `0x00625e4e` | `kServerChangeShape` |
| 30 | `0x00625ecc` | `#30` |
| 31 | `0x00625f4a` | `kServerChangeWeather` |
| 32 | `0x00625fc8` | `kServerChangeHour` |
| 33 | `0x00626046` | `kServerSelfSaveOK` |
| 34 | `0x006260c4` | `kServerRefreshUserOK` |
| 35 | `0x00626142` | `kServerOption` |
| 36 | `0x006261c0` | `kServerChangeCondition` |
| 37 | `0x0062623e` | `#37` |
| 38 | `0x006262bc` | `kServerMovePosition` |
| 39 | `0x0062633a` | `#39` |
| 40 | `0x006263b8` | `kServerCloseConnection` |
| 41 | `0x00626436` | `kServerEffectLayer` |
| 42 | `0x006264b4` | `#42` |
| 43 | `0x00626532` | `#43` |
| 44 | `0x006265b0` | `#44` |
| 45 | `0x0062662e` | `#45` |
| 46 | `0x006266ac` | `kServerFieldMap` |
| 47 | `0x0062672a` | `kServerScreenMenu` |
| 48 | `0x006267a8` | `kServerPursuitMessage` |
| 49 | `0x00626826` | `kServerBulletin` |
| 50 | `0x006268a4` | `#50` |
| 51 | `0x00626922` | `#51` |
| 52 | `0x006269a0` | `kServerObjectBubbleInfo` |
| 53 | `0x00626a1e` | `kServerShowPaper` |
| 54 | `0x00626a9c` | `kServerUserList` |
| 55 | `0x00626b1a` | `#55` |
| 56 | `0x00626b98` | `#56` |
| 57 | `0x00626c16` | `#57` |
| 58 | `0x00626c94` | `#58` |
| 59 | `0x00626d12` | `kServerRequestCRC` |
| 60 | `0x00626d90` | `#60` |
| 61 | `0x00626e0e` | `#61` |
| 62 | `0x00626e8c` | `#62` |
| 63 | `0x00626f0a` | `#63` |
| 64 | `0x00626f88` | `#64` |
| 65 | `0x00627006` | `#65` |
| 66 | `0x00627084` | `#66` |
| 67 | `0x00627102` | `#67` |
| 68 | `0x00627180` | `#68` |
| 69 | `0x006271fe` | `#69` |
| 70 | `0x0062727c` | `#70` |
| 71 | `0x006272fa` | `#71` |
| 72 | `0x00627378` | `#72` |
| 73 | `0x006273f6` | `#73` |
| 74 | `0x00627474` | `#74` |
| 75 | `0x006274f2` | `#75` |
| 76 | `0x00627570` | `#76` |
| 77 | `0x006275ee` | `#77` |
| 78 | `0x0062766c` | `#78` |
| 79 | `0x006276ea` | `#79` |
| 80 | `0x00627768` | `#80` |
| 81 | `0x006277e6` | `#81` |
| 82 | `0x00627864` | `#82` |
| 83 | `0x006278e2` | `kServerServerClose` |
| 84 | `0x00627960` | `#84` |
| 85 | `0x006279de` | `#85` |
| 86 | `0x00627a5c` | `#86` |
| 87 | `0x00627ada` | `#87` |
| 88 | `0x00627b58` | `#88` |
| 89 | `0x00627bd6` | `#89` |
| 90 | `0x00627c54` | `#90` |
| 91 | `0x00627cd2` | `#91` |
| 92 | `0x00627d50` | `#92` |
| 93 | `0x00627dce` | `#93` |
| 94 | `0x00627e4c` | `#94` |
| 95 | `0x00627eca` | `#95` |
| 96 | `0x00627f48` | `#96` |
| 97 | `0x00627fc6` | `#97` |
| 98 | `0x00628044` | `#98` |
| 99 | `0x006280c2` | `#99` |
| 100 | `0x00628140` | `#100` |
| 101 | `0x006281be` | `#101` |
| 102 | `0x0062823c` | `#102` |
| 103 | `0x006282ba` | `#103` |
| 104 | `0x00628338` | `#104` |
| 105 | `0x006283b6` | `#105` |
| 106 | `0x00628434` | `#106` |
| 107 | `0x006284b2` | `#107` |
| 108 | `0x00628530` | `#108` |
| 109 | `0x006285ae` | `#109` |
| 110 | `0x0062862c` | `#110` |
| 111 | `0x006286aa` | `#111` |
| 112 | `0x00628728` | `#112` |
| 113 | `0x006287a6` | `#113` |
| 114 | `0x00628824` | `#114` |
| 115 | `0x006288a2` | `kServerReconnect` |

### Blank Reserved Slots

All slots from index `116` / `0x74` through index `255` / `0xff` are blank zero-filled UTF-16 slots. The first blank slot is `0x00628920`; the last blank slot starts at `0x0062cd8a` and ends at the table boundary `0x0062ce08`.

Grouped address inventory:

| Indices | Addresses | Text |
|---|---|---|
| `116-127` | `0x00628920-0x00628e8a` | blank |
| `128-143` | `0x00628f08-0x0062966a` | blank |
| `144-159` | `0x006296e8-0x00629e4a` | blank |
| `160-175` | `0x00629ec8-0x0062a62a` | blank |
| `176-191` | `0x0062a6a8-0x0062ae0a` | blank |
| `192-207` | `0x0062ae88-0x0062b5ea` | blank |
| `208-223` | `0x0062b668-0x0062bdca` | blank |
| `224-239` | `0x0062be48-0x0062c5aa` | blank |
| `240-255` | `0x0062c628-0x0062cd8a` | blank |

### Tail Strings

| Range | Text | Decision |
|---|---|---|
| `0x0062ce08-0x0062ce2c` | `%08x: packet %d\n` | Keep with [UID:00026H]. Used by the raw packet logger for packet bytes above `0x73`. |
| `0x0062ce2c-0x0062ce50` | `%08x: packet %s\n` | Keep with [UID:00026H]. Used by the raw packet logger for packet bytes `0-0x73`. |
| `0x0062ce50-0x0062ce60` | `UNL.DLL` | Move out of [UID:00026H]. Used with `RegisterUniApp`, not with the packet table. |

## IDA Evidence

IDA names in `0x00625008-0x0062ce60`:

- `0x00625008`: `aKserverversion`.
- `0x0062ce08`: `a08xPacketD`.
- `0x0062ce2c`: `a08xPacketS`.
- `0x0062ce50`: `aUnlDll`.
- `0x0062ce60`: `aRegisteruniapp`.

IDA string cache does not enumerate the wide table labels; it only reports `RegisterUniApp` inside this local span. The table inventory above is therefore PE-byte-derived, with IDA used for xrefs and code context.

Direct xrefs checked:

| Address | IDA xrefs | Interpretation |
|---|---:|---|
| `0x00625008` | 1 at `0x00578f4b` | Raw packet logger computes `base + opcode * 0x7e`. |
| `0x00625086`, `0x00625104`, `0x006288a2`, `0x00628920` | 0 in sampled IDA checks | No modeled direct per-entry xrefs. |
| `0x0062ce08` | 1 at `0x00578f55` | Raw packet logger numeric format. |
| `0x0062ce2c` | 1 at `0x00578f5a` | Raw packet logger string format. |
| `0x0062ce50` | 1 at `0x00578ea0` | Raw UniAPI registration helper, not packet logging. |
| `0x0062ce60` | 1 at `0x00578eb0` | Same raw UniAPI registration helper. |
| `0x0062ce70` | 1 at `0x00575c86` in `sub_575C30` | PacketTransform string-key helper `%s%s`, outside [UID:00026H]. |

Raw helper inventory immediately after `XorTransformBuffer`:

| Range | IDA function? | Xrefs to start | Behavior |
|---|---|---:|---|
| `0x00578ea0-0x00578ecc` | no | 0 | Pushes `UNL.DLL`, calls through `unk_69BE78`, resolves `RegisterUniApp` with `GetProcAddress`, then calls it with `GetCurrentProcessId()`. |
| `0x00578ed0-0x00578f24` | no | 0 | Copies a string/payload, uses `g_pApplication` and `unk_69BE90`, and selects resource/status IDs `0x402` or `0x403`. Not packet-name-table logic. |
| `0x00578f30-0x00578f6c` | no | 0 | Packet debug logger. Loads `g_pTimerMgr + 0x18`, reads first packet byte, maps `0-0x73` through the fixed table, otherwise logs the numeric byte, then calls `sub_579780`. |
| `0x00578f70+` | yes | normal STL/helper refs | Compiler/STL tree/string support documented by [UID:000245][0x00578f70-0x005797ae.StlTreeStringMapSupport](../../../../../by-memory/0x00578f70-0x005797ae.StlTreeStringMapSupport.md). |

The [UID:0001I5][XorTransformBuffer](../../../../../by-memory/0x00578e00-0x00578e94.XorTransformBuffer.md) page already says the `UNL.DLL` helper begins after the transform function and is unrelated to XOR/packet transform behavior. This pass refines the data side of that boundary: `UNL.DLL` also is unrelated to the packet-name table.

The packet logger body at `0x00578f30`:

- `0x00578f33`: loads [UID:0000SI][g_pTimerMgr](../../../../../by-global/g_pTimerMgr.md) / `0x0067ab80`.
- `0x00578f38`: reads `[TimerMgr + 0x18]`, likely the timer/tick value for the `%08x` prefix.
- `0x00578f3b-0x00578f40`: reads the first byte from the packet pointer argument.
- `0x00578f43`: compares the byte against `0x73`.
- `0x00578f48`: multiplies by `0x7e`.
- `0x00578f4b`: adds `0x00625008`.
- `0x00578f55`: loads `%08x: packet %d\n`.
- `0x00578f5a`: loads `%08x: packet %s\n`.
- `0x00578f5f`: selects numeric vs string format based on `opcode > 0x73`.
- `0x00578f63`: calls `sub_579780`, documented as an STL/CRT diagnostic/output helper in [UID:000245].

This gives a precise source-use model for the table, but not a live runtime call path. The logger has no IDA function object and no callers.

## Raw PE Scan Evidence

Exact raw scans were run over the local PE, not only through IDA xrefs.

Raw start reachability:

| Target | Absolute VA dword hits | RVA dword hits | Direct relative call/jump hits |
|---|---:|---:|---:|
| `0x00578ea0` | 0 | 0 | 0 |
| `0x00578ed0` | 0 | 0 | 0 |
| `0x00578f30` | 0 | 0 | 0 |

Table and tail dword scans:

| Value | Raw result |
|---|---|
| `0x00625008` | one real `.text` operand hit at `0x00578f4c` inside the raw packet logger. |
| `0x0062ce08` | one real `.text` operand hit at `0x00578f56` inside the raw packet logger. |
| `0x0062ce2c` | one real `.text` operand hit at `0x00578f5b` inside the raw packet logger. |
| `0x0062ce50` | one real `.text` operand hit at `0x00578ea1` inside the raw UniAPI helper. |
| `0x0062ce60` | one real `.text` operand hit at `0x00578eb1` inside the raw UniAPI helper. |
| `0x0062ce70` | one real `.text` operand hit at `0x00575c87` inside live `sub_575C30`. |

I also scanned all 256 table slot starts as exact VA/RVA dwords. That found the real table-base operand and one false positive:

- Real: slot 0 / `0x00625008` in the raw logger.
- False positive: slot 16 / `0x006257e8` appears as an unaligned byte run at `0x004b1674`, which is the opcode/displacement bytes for `call sub_4B78D0` inside `sub_4B1590` / FolderSelectDialog construction. IDA `xrefs_to 0x006257e8` returns zero. This is not a packet table reference.

No raw evidence supports per-entry external users, a pointer table to the logger, or an alternate source-use route.

## Ownership Alternatives

### Socket / Network Protocol Debug

This remains the best route for the packet table and two packet log formats.

Evidence:

- The table follows [UID:00026G][SocketReadOnlyData](../../../../../by-memory/0x00624f20-0x00625008.SocketReadOnlyData.md), which contains the Socket vtable and transport/parser literals.
- The only real table xref is a packet debug logger in the Socket/PacketTransform address neighborhood.
- [UID:0000NS][Socket](../../../../../by-file/Socket.md) owns stateful transport, receive parsing, final outbound framing, and `g_packetSender` lifetime.
- `client_network.md` treats Socket as the low-level transport owner while leaving feature packet builders in feature files.
- No standalone `ProtocolDebug.cpp` or `ProtocolSend.cpp` source unit is proven. [UID:0000MV][ProtocolSend](../../../../../by-file/ProtocolSend.md) explicitly remains `PROPOSED_RECONSTRUCTION_PATH:"NONE"`.

Confidence caveat:

- The raw logger has no callers. This makes the table retained debug/instrumentation evidence, not a proven live receive path. It does not justify moving the table out of Socket/protocol ownership, but it does block final C++.

### MapPane

Rejected for the table.

Evidence:

- [UID:0001SO][MapServerPacketOpcode](../../../../../by-type/by-enum/MapServerPacketOpcode.md) documents the live `MapPane::HandlePacket` switch subset and explicitly keeps it separate from the broader Socket/protocol packet-name table.
- The table has labels for login/new-user/version, bulletin, field-map, status, reconnect, and many placeholder server labels beyond MapPane-specific routes.
- The raw packet logger is not reached from `MapPane::HandlePacket`; it only consumes an arbitrary packet pointer's first byte and logs a global timer/tick prefix.

### PacketTransform

Rejected for the table.

Evidence:

- PacketTransform owns key setup, nonce/XOR helpers, and transform globals.
- The `%s%s` literal at `0x0062ce70` belongs to PacketTransform string-key expansion, but it is outside the proposed [UID:00026H] range.
- The packet-name table stores debug labels and log formats, not transform state, key material, or nonce data.

### ProtocolSend / Session / Generated Protocol Table Source

Not promoted.

Evidence:

- [UID:0000MV][ProtocolSend](../../../../../by-file/ProtocolSend.md) and [UID:0000NP][Session](../../../../../by-file/Session.md) are explicitly non-promoted placeholders with `PROPOSED_RECONSTRUCTION_PATH:"NONE"`.
- No `ProtocolSend`, `ServerPacketNameTable`, source path, PDB, or linker-map evidence was found in current docs or IDA string/name queries.
- The table declaration could have been a file-local Socket/protocol debug array, a generated protocol-name table, or a private helper in a network source file. The binary does not prove the original declaration spelling or header/source split.

## Split / Merge / Reclassification Decision

Recommended split is a boundary shrink, not a child-page split of the table itself.

Keep together:

- `0x00625008-0x0062ce08` table.
- `0x0062ce08-0x0062ce50` packet logger formats.

Reason:

- The raw packet logger is the only real source-use site for both the table and the two formats.
- Its opcode guard exactly matches the last nonblank table slot.
- This is one coherent retained packet debug artifact.

Move out:

- `0x0062ce50-0x0062ce60` `UNL.DLL`.

Reason:

- It is used by a different raw helper (`0x00578ea0`) with `RegisterUniApp`.
- Keeping `UNL.DLL` in [UID:00026H] splits a two-string UniAPI registration pair across two pages and incorrectly describes `UNL.DLL` as packet logging support.

Do not merge [UID:00026H] with [UID:00026G] `SocketReadOnlyData`:

- [UID:00026G] has Socket vtable/parser/error literals.
- [UID:00026H] has a fixed packet-name/debug table with a different declaration shape.

Do not make [UID:00026H] non-emitting:

- After moving `UNL.DLL`, [UID:00026H] is one source-authored static data artifact, not a mixed owner index.
- The raw logger/table are no-xref retained debug evidence, but exact binary reconstruction still needs a source-level declaration if this object is to be reproduced.
- Final C++ should remain blank until the retained-debug source policy, declaration name, linkage, and whether to recreate the raw logger are settled.

Do not create separate children for every table entry:

- The source shape is one fixed two-dimensional array, not 256 independent string literals.
- There are no per-slot direct xrefs except the table-base computation.

## Final C++ Blockers

Resolved blockers:

- Full table inventory is now known.
- Blank/reserved entries are identified as true zero-filled slots `116-255`.
- Tail string ownership is resolved: the two packet formats stay with the table; `UNL.DLL` moves.
- MapPane, PacketTransform, ProtocolSend, and Session alternatives were checked and rejected.

Still unresolved:

- Original symbol name is not proven. `ServerPacketNameTable` is a documentation name; IDA only names the base `aKserverversion`.
- Original declaration shape is strongly inferred but not final. Plausible source is a file-local array such as `static const wchar_t s_serverPacketNames[256][63]`, but exact name/linkage/header placement are not recoverable from the current binary.
- The packet logger at `0x00578f30` has no direct callers or function object. It may be retained debug code from the Socket/network translation unit. No live call path currently proves the table is used at runtime.
- The source policy for emitting retained no-xref debug helpers alongside retained data is not fully settled. Until that policy is settled, final C++ should stay blank even with a higher documentation score.

These unresolved items do not justify lowering confidence below the current gate because they affect final source emission, not the table bytes, range, or best owner.

## IDA DB Recommendation

No immediate IDA DB edit is recommended.

Creating IDA functions at `0x00578ea0`, `0x00578ed0`, and `0x00578f30` would be mechanically safe based on ret/alignment boundaries, but it is low value for this assignment and could hide the important current fact that these are no-function/no-xref retained raw bodies. Keep the IDA DB untouched unless the supervisor starts a specific raw-helper cleanup. If that cleanup happens, document the raw helper page(s) first, then optionally define functions/comments in IDA.

## Exact Supervisor Actions

### 1. Update [UID:00026H]

Rename and update:

- From: `by-memory/0x00625008-0x0062ce60.ServerPacketNameTable.md`
- To: `by-memory/0x00625008-0x0062ce50.ServerPacketNameTable.md`

Header changes:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000NS | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000NS | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Required content changes:

- Change address range to `0x00625008-0x0062ce50`.
- Remove `UNL.DLL` from the target layout/observed contents.
- Add the full inventory summary from this report: 116 nonblank slots `0-115`, blank slots `116-255`, no nonzero padding.
- Add the raw logger evidence at `0x00578f30-0x00578f6c`, including the `opcode <= 0x73` guard and no-xref/no-function status.
- Add a note that the table is retained Socket/protocol debug evidence and final C++ remains blank because declaration/linkage and retained-debug emission policy are not final.

### 2. Update [UID:00026I]

Recommended rename and rerange:

- From: `by-memory/0x0062ce60-0x0062cfd8.AudioReadOnlyData.md`
- To: `by-memory/0x0062ce50-0x0062cfd8.NetworkAndAudioReadOnlyData.md`

Recommended header:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Required content changes:

- Change address range to `0x0062ce50-0x0062cfd8`.
- Retitle from pure `Audio Read-Only Data` to a mixed network/audio read-only data index.
- Add `0x0062ce50` `UNL.DLL`, referenced at `0x00578ea0`, as the paired module string for `0x0062ce60` `RegisterUniApp`.
- Keep `0x0062ce70` `%s%s` as PacketTransform string-key helper evidence.
- Keep SoundManager and SoundStatusPane source-owner subrange map unchanged.
- Keep successor boundary `0x0062cfd8`.

### 3. Reference Updates

If the supervisor applies the rename/rerange:

- Update references to `by-memory/0x00625008-0x0062ce60.ServerPacketNameTable.md` in:
  - `by-type/by-enum/MapServerPacketOpcode.md`
  - `by-meta/client_network.md`
  - `by-memory/0x00624f20-0x00625008.SocketReadOnlyData.md`
  - `by-memory/0x0060d670-0x0066d000.ReadOnlyDataSection.md`
  - any generated validator-managed reference indexes through validator/regeneration.
- Update references to `by-memory/0x0062ce60-0x0062cfd8.AudioReadOnlyData.md` in neighboring docs, especially [UID:00026J] and audio support pages.
- Update `tools/validator.ini` UID path records through the validator workflow, not manual editing, if the validator expects path registration.

### 4. Shared `by-memory/-coverage-report.md` Rows

Do not let B001 apply these directly. Placement context: replace the current [UID:00026H] row immediately after [UID:00026G] and the current [UID:00026I] row immediately before [UID:00026J].

Replacement [UID:00026H] row:

```text
    - [UID:00026H][0x00625008-0x0062ce50.ServerPacketNameTable](by-memory/0x00625008-0x0062ce50.ServerPacketNameTable.md) 0x00625008-0x0062ce50 | fixed string table | ServerPacketNameTable : reconstructable : 88% : strong : Fixed-width Socket/protocol packet-name debug table plus packet log formats; PE-backed inventory confirms 256 UTF-16 slots at 0x7e stride, 116 nonblank labels for indices 0-115, zero-filled reserved slots 116-255, no nonzero per-slot padding, packet formats at 0x0062ce08/0x0062ce2c, exact raw no-function logger use at 0x00578f30 with guard opcode <= 0x73, no callers/pointers/relative-branch hits to the raw logger, rejected MapPane/PacketTransform/ProtocolSend ownership, and final C++ still blank until retained-debug source policy and declaration names are finalized.
```

Replacement [UID:00026I] row:

```text
    - [UID:00026I][0x0062ce50-0x0062cfd8.NetworkAndAudioReadOnlyData](by-memory/0x0062ce50-0x0062cfd8.NetworkAndAudioReadOnlyData.md) 0x0062ce50-0x0062cfd8 | mixed-rdata index | NetworkAndAudioReadOnlyData : ignored : 88% : very strong : Non-emitting mixed `.rdata` index now starts at `UNL.DLL` because live IDA/raw disassembly ties `0x0062ce50` `UNL.DLL` and `0x0062ce60` `RegisterUniApp` to the same unreferenced raw UniAPI registration helper at `0x00578ea0`; also retains `0x0062ce70` `%s%s` packet-transform string-key format, SoundManager vtable/audio formats, SoundStatusPane vtables/captions, and corrected SpellInventoryPane successor boundary at `0x0062cfd8`. Keep `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters/final C++ because exact owner pages carry source emission.
```

Neighbor stale row already present; if editing this local block, replace [UID:00026J] too:

```text
    - [UID:00026J][0x0062cfd8-0x0062d418.SpellInventoryMacroReadOnlyData](by-memory/0x0062cfd8-0x0062d418.SpellInventoryMacroReadOnlyData.md) 0x0062cfd8-0x0062d418 | mixed-rdata index | SpellInventoryMacroReadOnlyData : ignored : 87% : very strong : Non-emitting mixed `.rdata` index starting at the `SpellInventoryPane` primary RTTI locator after Batch 225; documents SpellInventoryPane/NewSpellInventoryPane/SpellInventoryPane2 vtables, spell inventory resource strings/constants, exact MacroEditControlPane vtable child, macro hotkey/mode strings, and StartupWindow successor boundary at `0x0062d418`. Keep `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters/final C++ because source emission belongs to exact spell inventory and MacroDialogs children.
```

### 5. Validation Order

Recommended supervisor validation order after applying doc/range changes:

> Executable block R001 was removed from this report and preserved verbatim in [00026H-server-packet-name-table-source-routing-removed.md](00026H-server-packet-name-table-source-routing-removed.md). The archived block is non-authoritative and must not be executed.

If the supervisor chooses not to rename [UID:00026I], validate the existing [UID:00026I] path after its range/title/body update instead.

## No-Change Items

No change recommended for:

- [UID:0000NS][Socket](../../../../../by-file/Socket.md): current network/Socket source root remains valid.
- [UID:0000M9][PacketTransform](../../../../../by-file/PacketTransform.md): no table ownership change; only the successor `%s%s` literal remains PacketTransform evidence.
- [UID:0001SO][MapServerPacketOpcode](../../../../../by-type/by-enum/MapServerPacketOpcode.md): keep it as the MapPane switch subset and only update links/range text if [UID:00026H] is renamed.
- IDA DB: leave untouched for now.

## Files Changed By B001

Only this report was created. No by-* docs, generated reports, IDA DB, or `by-memory/-coverage-report.md` were edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/00026H-server-packet-name-table-source-routing.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:21","uid":"00026H"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00026H-server-packet-name-table-source-routing-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/00026H-server-packet-name-table-source-routing.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00026H"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
