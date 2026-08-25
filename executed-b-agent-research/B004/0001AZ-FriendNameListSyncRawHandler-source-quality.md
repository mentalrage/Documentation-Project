** TARGET-REPORT-UID:0001AZ **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001AZ FriendNameListSyncRawHandler Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0001AZ] as retained reconstructable raw MapPane packet-handler evidence under [UID:0000L3] `MapPane`, but correct the half-open range and filename from `0x00514380-0x005143b7` to `0x00514380-0x005143ba`.
- Final disposition: retained raw duplicate evidence, not ignored, not merged into the live dispatcher page, and not emitted as an independent C++ helper.
- Required action: supervisor-owned range/path, support-link, score, and coverage-row updates only. This report did not edit by-* docs, generated docs, validator data, IDA DB, or `by-memory/-coverage-report.md`.
- Score recommendation: `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000L3`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000L3`, blank formal C++.
- Confidence: high for bytes, boundary, padding, duplicate behavior, and no-route evidence; capped below final because the original compiler/linker retention reason for the raw duplicate is still not proven.

## Target

- Target UID: `0001AZ`.
- Current target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00514380-0x005143b7.FriendNameListSyncRawHandler.md`.
- Recommended target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00514380-0x005143ba.FriendNameListSyncRawHandler.md`.
- Current state: `84/88`, `CANONICAL_OWNER:0000L3`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000L3`, blank formal C++.
- Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B004\research\0001AZ-FriendNameListSyncRawHandler-source-quality.md`.
- Assignment: `B004-goal2-friend-name-list-sync-raw-handler-source-quality-0001AZ-20260618`.
- Evidence inputs used: supervisor-provided local executable `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, local IDA DB presence check at `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`, existing IDA-backed by-* documentation, prewave/export metadata, old B001 MapPane packet split report as a lead only, raw PE byte scans, Capstone disassembly, and support-document searches.

## Executive Recommendation

[UID:0001AZ] should stay as a source-shaped retained raw duplicate body in the MapPane packet-handler evidence tree, but its documented half-open range is wrong. The current `0x00514380-0x005143b7` range is only `0x37` bytes / 55 bytes (Verified with `int_convert.py`) and stops immediately after `pop ebp`; it omits the real `ret 4` instruction bytes `c2 04 00` at `0x005143b7-0x005143ba`. The actual body is `0x00514380-0x005143ba`, length `0x3a` / 58 bytes (Verified with `int_convert.py`), followed by six `0xcc` alignment bytes at `0x005143ba-0x005143c0`.

The target should not receive formal C++. The live source route is the modeled `MapPane::HandlePacket` opcode `0x6a` branch at `0x00508ae3-0x00508b19`, and that branch already performs the same read, global write, flag test, and outbound sync send. Local PE scans found no direct VA, RVA, raw-offset, pointer-table, vtable-cell, rel32 call, rel32 jump, or rel32 conditional branch route to raw start `0x00514380`. Existing IDA-backed docs also report no IDA function object, direct xrefs, or callers for `0x00514380`. Emitting an independent source helper for [UID:0001AZ] would duplicate behavior without a proven source-level route.

The best source-policy result is therefore: retain the raw body for evidence, keep MapPane file ownership/source-family routing, raise the score modestly after the raw-byte and hidden-route pass, leave the C++ block blank, and represent source behavior in the live `MapPane::HandlePacket` case.

## Supervisor Active Recheck

- This was explicitly assigned as report-only. No split or target-file edit was performed.
- The assignment required exact bytes, boundary, padding, modeled-function absence, route checks, comparison to live opcode `0x6a`, source-placement policy, name/source-quality decisions, and coverage/support replacement text.
- IDA MCP was checked at `127.0.0.1:13337` during this pass and remains offline (`TcpTestSucceeded: False`). The report compensates with local PE raw bytes from the known executable, existing IDA-backed docs, prewave/export metadata, and targeted searches.
- The local executable and IDA DB paths specified by the supervisor both exist:
  - `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
  - `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`

## Raw Boundary, Bytes, Padding, And PE Mapping

PE mapping from `NexusTK.exe`:

- Image base: `0x00400000`.
- `.text` section: RVA `0x00001000`, virtual size `0x0020b4ac`, raw file pointer `0x00000400`, raw size `0x0020b600`.
- Target VA: `0x00514380`.
- Target RVA: `0x00114380` / 1131392 (Verified with `int_convert.py`).
- Target raw file offset: `0x00113780` / 1128320 (Verified with `int_convert.py`).
- Formula: `raw = 0x00000400 + ((0x00514380 - 0x00400000) - 0x00001000) = 0x00113780`.

Raw byte findings:

| Range | Meaning | Length | SHA-256 |
| --- | --- | ---: | --- |
| `0x00514380-0x005143b7` | current documented range; incomplete body | `0x37` / 55 bytes (Verified with `int_convert.py`) | `cec9731c0b2b846bbfd1730fdf10cf1ca3e7dafb6ad135e16717a82595416a31` |
| `0x00514380-0x005143ba` | corrected complete body | `0x3a` / 58 bytes (Verified with `int_convert.py`) | `85d29ffc817b1143fdca4f3d14358bcfccd18e9248a0f2f04bd5596fb32b0e3f` |
| `0x005143ba-0x005143c0` | post-body alignment padding | `0x6` / 6 bytes (Verified with `int_convert.py`) | `33cc4a00a0f04735602819132da3e3fac4cdeb8ec7aee92551dc79ba8488e722` |
| `0x005143b7-0x005143c0` | old omitted tail plus padding | `0x9` / 9 bytes | `555d98cbeb8abf478da22fcb27418cb26a23babc09b0925c55a2ebe826439460` |

Correct body plus padding byte listing:

```text
00514380: 55 8b ec 51 8d 45 fc c7 45 fc 01 00 00 00 50 ff
00514390: 75 08 e8 79 13 06 00 83 c4 08 84 c0 0f 95 05 e0
005143a0: de 66 00 84 c0 74 0b 8b 0d ec a7 67 00 e8 9e 0a
005143b0: 06 00 b0 01 8b e5 5d c2 04 00 cc cc cc cc cc cc
```

Capstone disassembly of corrected body:

```asm
00514380: 55                      push ebp
00514381: 8b ec                   mov ebp, esp
00514383: 51                      push ecx
00514384: 8d 45 fc                lea eax, [ebp - 4]
00514387: c7 45 fc 01 00 00 00    mov dword ptr [ebp - 4], 1
0051438e: 50                      push eax
0051438f: ff 75 08                push dword ptr [ebp + 8]
00514392: e8 79 13 06 00          call 0x575710
00514397: 83 c4 08                add esp, 8
0051439a: 84 c0                   test al, al
0051439c: 0f 95 05 e0 de 66 00    setne byte ptr [0x66dee0]
005143a3: 84 c0                   test al, al
005143a5: 74 0b                   je 0x5143b2
005143a7: 8b 0d ec a7 67 00       mov ecx, dword ptr [0x67a7ec]
005143ad: e8 9e 0a 06 00          call 0x574e50
005143b2: b0 01                   mov al, 1
005143b4: 8b e5                   mov esp, ebp
005143b6: 5d                      pop ebp
005143b7: c2 04 00                ret 4
```

Boundary conclusion: the current target path/title/range is stale. The correct half-open body range is `0x00514380-0x005143ba`; the six-byte padding range is `0x005143ba-0x005143c0`; successor `sub_5143C0` begins at `0x005143c0`.

## Live Dispatcher Comparison

The requested live branch comparison range `0x00508af3-0x00508b19` is `0x26` bytes / 38 bytes and hashes to `4ce0c841c4e972c6cbae1306b1f8f29fdc81aab28222c28b8318ccb3c5b7a8ea`. The wider semantic case fragment `0x00508ae3-0x00508b1d` is also `0x3a` / 58 bytes (Verified with `int_convert.py`) and hashes to `11493d623ec931a2f6f540488fd63f9873db5ca0a57a3d4cda3a773663643826`.

Live branch disassembly:

```asm
00508ae3: 8d 85 b0 fb ff ff       lea eax, [ebp - 0x450]
00508ae9: c7 85 b0 fb ff ff 01 00 00 00 mov dword ptr [ebp - 0x450], 1
00508af3: 50                      push eax
00508af4: 57                      push edi
00508af5: e8 16 cc 06 00          call 0x575710
00508afa: 83 c4 08                add esp, 8
00508afd: 84 c0                   test al, al
00508aff: 0f 95 05 e0 de 66 00    setne byte ptr [0x66dee0]
00508b06: 84 c0                   test al, al
00508b08: 0f 84 bc f2 ff ff       je 0x507dca
00508b0e: 8b 0d ec a7 67 00       mov ecx, dword ptr [0x67a7ec]
00508b14: e8 37 c3 06 00          call 0x574e50
00508b19: b0 01                   mov al, 1
```

Comparison result:

- Both bodies initialize a packet cursor to `1`.
- Both call `0x00575710` to read one byte from the packet buffer at cursor offset `1`, meaning the first payload byte after the opcode byte.
- Both store `byte_66DEE0 = (readByte != 0)`.
- Both test the same byte and call `0x00574e50` through `dword_67A7EC` only when the read byte is nonzero.
- Both set return success (`al = 1`).
- The live branch uses the modeled dispatcher packet pointer in `edi`, local cursor `[ebp-0x450]`, and branches to the dispatcher common success path on zero. The raw body uses a standalone `__stdcall`-shaped shell with `[ebp+8]`, a local cursor `[ebp-4]`, and its own `ret 4`.

This proves semantic duplication but not reachability of the raw body. Source emission belongs to the live branch.

## Hidden Route And Xref Recheck

Fresh local PE route scans for target start `0x00514380`:

| Route encoding checked | Bytes searched | Result |
| --- | --- | --- |
| Absolute VA dword `0x00514380` | `80 43 51 00` | 0 hits |
| RVA dword `0x00114380` | `80 43 11 00` | 0 hits |
| Raw file-offset dword `0x00113780` | `80 37 11 00` | 0 hits |
| `.text` `E8`/`E9` rel32 call or jump target | decoded target equals `0x00514380` | 0 hits |
| `.text` `0F 80-8F` rel32 conditional branch target | decoded target equals `0x00514380` | 0 hits |

Vtable/pointer-table conclusion: conventional MSVC vtables and callback tables store VA dwords. The zero-hit absolute VA scan across the executable rules out a normal direct vtable cell, callback-table cell, jump-table cell, or untyped pointer-table route to `0x00514380`.

Positive controls from the same scan:

- Absolute dword `0x0066dee0` was found exactly three times in loaded `.text`: VA `0x00508b02`, VA `0x0051439f`, and VA `0x0053f8de`. These align with the live write, raw write, and `FriendListDialog` read of `byte_66DEE0`.
- Absolute dword `0x0067a7ec` was found 489 times, matching the high-use `g_packetSender` global documented by [UID:0000Q5].
- Absolute dword `0x00574e50` had 0 file hits because calls to it are encoded as rel32 calls, as expected.

Existing IDA-backed documentation rechecked:

- [UID:0001AZ] target page records 2026-06-05 IDA MCP `lookup_funcs` for `0x00514380` and `0x005143b7` as `Not a function`; next modeled functions are `sub_5143C0` at `0x005143c0-0x0051447c` and `sub_514480` at `0x00514480-0x00514579`.
- The same page records 2026-06-05 IDA MCP `xrefs_to 0x00514380` and `callers 0x00514380` as no direct references.
- The page records a prior loaded-segment dword pointer scan with no dword equal to `0x00514380`.
- Prewave/export metadata models a Ghidra `FUN_00514380` of size `58` with Ghidra `num_callers = 0`, but IDA fields are null. This is useful body-shape corroboration, not proof that IDA or the source should treat the raw body as a real function.

Final no-route conclusion: there is no current defensible direct/static/callback/vtable/jump-table route to raw start `0x00514380`.

## Heuristic / Inference Reanalysis And Validation

### Range, bytes, and padding

- Raw-byte proven: body is `0x00514380-0x005143ba`, not `0x00514380-0x005143b7`; `0x005143b7-0x005143ba` is `ret 4`; `0x005143ba-0x005143c0` is six `0xcc` bytes.
- Existing claim status: target docs already said IDA disassembly ended through `0x005143b9` and padding began at `0x005143ba`, but the page title/path/header and coverage row still used the stale truncated end. The report upgrades this from a prose note to a required range/path correction.
- Rejected alternative: treating `0x005143b7-0x005143c0` as padding is byte-proven false because the first three bytes are `c2 04 00`.

### Modeled-function absence and raw helper role

- Raw-byte proven: the bytes decode as a complete compact `__stdcall`-shaped body with one packet argument and `ret 4`.
- Existing IDA-backed docs: IDA does not model a function at `0x00514380`; no direct xrefs/callers; successor function starts at `0x005143c0`.
- Inference: the raw item is source-shaped retained duplicate evidence, not live dispatch source and not padding.
- Rejected alternative: creating a new source helper named `FriendNameListSyncRawHandler` is not justified because no caller, table, vtable, or computed branch route is known.

### Duplicate relationship to live `MapPane::HandlePacket` opcode `0x6a`

- Raw-byte proven: the raw and live bodies share the exact semantic sequence: cursor `1`, `0x00575710` read, `setne [0x66dee0]`, flag test, `mov ecx, [0x67a7ec]`, `call 0x00574e50`, return success.
- Documentation evidence: [UID:0000UP] `FriendNameListSyncOpcodes`, [UID:0000L3] `MapPane`, and [UID:0001AW] `MapPanePacketHandlers` all describe the raw item as duplicate evidence of the live opcode `0x6a` branch.
- Inference: source emission should remain in `MapPane::HandlePacket`; [UID:0001AZ] is retained to preserve raw evidence and corroborate names/xrefs.
- Rejected alternative: merging the raw body into the live dispatcher page would lose exact orphan/raw-range evidence and obscure the `0x005143ba-0x005143c0` padding boundary before `sub_5143C0`.

### `byte_66DEE0` role and name

- Raw-byte proven: raw site `0x0051439c` writes `setne byte ptr [0x66dee0]`.
- Live-byte proven: live branch `0x00508aff` writes the same global from the same read byte.
- Documentation evidence: [UID:0000PG] names this as `g_friendNameListSyncEnabled`, [UID:0001OM] records exact byte storage `0x0066dee0-0x0066dee1`, and xrefs are live MapPane write `0x00508aff`, raw write `0x0051439c`, and `FriendListDialog` read `0x0053f8dc`.
- Best interpretation: `byte_66DEE0` is a process-global flag enabling the friend/name-list upload path after the server requests or allows it. It is not just a transient packet byte because `FriendListDialog::OnOkButton` later reads it before deciding whether to send after saving.
- Source-facing name: `g_friendNameListSyncEnabled` is descriptive/inferred, not proven original.
- Rejected alternatives: `g_isCashShopEnabled` is contradicted by the live opcode path, FriendListDialog read, outbound `0x77` friend-name-list builder, and the separate `0x0067a738` download-dispatcher storage whose `g_pCashShopRequest` name is now documented as a stale alias; a generic `byte_66DEE0` placeholder is lower quality and no longer needed.

### `0x00574e50` helper role, signature, and source placement

- Existing IDA-backed docs: [UID:0001HX] `0x00574e50-0x0057536b.BuildAndSendFriendNameListSync` is exact IDA function `sub_574E50`, size `0x51b` / 1307 bytes (Verified with `int_convert.py`), with callers at live MapPane `0x00508b14`, raw site `0x005143ad` as a non-function xref, and `FriendListDialog::OnOkButton` `0x0053f8ed`.
- Behavior evidence from support docs: builds outbound opcode `0x77` / 119 (Verified with `int_convert.py`), iterates 20 friend-name slots (Verified with `int_convert.py`) at `g_pConfig + 0x2911e0` through `+0x291230`, emits 13-byte records (Verified with `int_convert.py`) with marker `0x0c`, checks send-disabled byte at `this + 0x3aa4e` / 240206 (Verified with `int_convert.py`), and queues through the Socket send path with command `8`.
- Best descriptive name: `BuildAndSendFriendNameListSync`.
- Best signature direction: `void __thiscall BuildAndSendFriendNameListSync(Socket *sender)` or a Socket member-style method taking `this` in `ecx`; current docs route it under Socket [UID:0000DD].
- Rejected alternatives: `BuildAndSendInventoryData`, `CashShopRequest::meth_0x574e50`, or a FriendListDialog method are stale/generated aliases. The called object is `g_packetSender` at `0x0067a7ec`, not `g_pCashShopRequest` at `0x0067a738`, and the payload is the 20-slot friend/name list.

### Packet byte semantics

- Raw-byte proven: the raw body initializes cursor `1` and calls `0x00575710`; prewave/export for `0x00575710` shows a cursor-byte read that returns `*(packet + *cursor)` and increments `*cursor`.
- Live-byte proven: the live branch uses the same cursor initialization and read.
- Best interpretation: inbound server opcode `0x6a` / 106 (Verified with `int_convert.py`) carries a one-byte control flag at payload offset `1`. Nonzero stores true and immediately sends the current name-list sync reply. Zero stores false and suppresses the immediate send.
- Source-facing reader name: `PacketBufferReadByteAtCursor` or `ReadCursorByte`, descriptive/inferred.
- Rejected alternative: multi-byte length, record count, status code, or cash-shop enable byte is unsupported. Only one byte is read; the result gates the friend-name-list upload helper.

### `g_packetSender` and Socket send path

- Raw-byte proven: both raw and live branches load `[0x0067a7ec]` into `ecx` immediately before `call 0x00574e50`.
- Documentation evidence: [UID:0000Q5] names `dword_67A7EC` as `g_packetSender`, type `Socket *`, with 489 xrefs and Socket lifecycle writes; [UID:0001HU] documents the shared queue/send packet path.
- Best interpretation: `0x00574e50` is invoked as a Socket/send-layer helper on the global packet sender instance.
- Rejected alternative: `dword_67A7EC` as cash shop request pointer is contradicted by [UID:0000Q5] and the separate [UID:0000QH] `g_pCashShopRequest` / `g_pFileDownloader` storage at `0x0067a738` documented elsewhere. The send path relationship is Socket-level, not MapPane-owned.

### `FriendListDialog` caller relationship

- Documentation evidence: [UID:0000JN] and [UID:00005J] describe `FriendListDialog::OnOkButton` saving the 20 configured names, reading `byte_66DEE0` at `0x0053f8dc`, and calling `0x00574e50` at `0x0053f8ed` when the flag is enabled.
- Best interpretation: `FriendListDialog` is the UI/configuration owner for the saved friend-name list and a consumer of the sync-enabled flag. It does not own [UID:0001AZ] because [UID:0001AZ] is a duplicate inbound packet branch, not a dialog method.
- Global owner inference: keeping [UID:0000PG] under `FriendListDialog` remains defensible because the flag gates dialog save-triggered upload and the feature data is the friend list. The live write still belongs to MapPane packet handling.
- Rejected alternative: moving [UID:0001AZ] to `FriendListDialog` conflates state ownership and packet-dispatch ownership.

### Owner, emitter, and C++ policy

- Best owner/source-family: [UID:0000L3] `MapPane` file, because the only live source behavior is `MapPane::HandlePacket` opcode `0x6a`, and the raw body sits under [UID:0001AW] `MapPanePacketHandlers`.
- Best emitter policy: keep `EMITTER_UIDS:0000L3` for consistency with retained raw MapPane packet evidence, but leave the target formal C++ blank with a target-specific no-code proof. The source code should be represented in the live dispatcher branch, not duplicated under the raw body.
- Rejected alternative: clearing the owner/emitter and marking the item ignored would under-document a source-shaped body with meaningful xrefs-from and would diverge from the nearby retained raw duplicate convention used by [UID:0001AX].
- Rejected alternative: populating `RECONSTRUCTION_CPP` for [UID:0001AZ] would duplicate the live branch and imply reachability that route scans do not support.

### Existing B001 split-report claims

- Validated: old B001 was correct that [UID:0001AZ] is retained raw duplicate evidence, that final C++ should stay blank, and that the live dispatcher route should carry source behavior.
- Superseded: old B001 coverage text kept the stale `0x00514380-0x005143b7` range. This pass proves the exact target range should become `0x00514380-0x005143ba`.
- Refined: old B001 suggested `86/90`; this pass agrees with `86/90` after the range correction and local PE hidden-route scan.

### Remaining blocker

The only material unresolved question is why this duplicate source-shaped body was retained in the binary despite having no current direct/static/pointer route. Evidence checked: local VA/RVA/raw dword scans, rel32 call/jump/jcc scans, existing IDA `lookup_funcs`, existing IDA xrefs/callers, prewave caller count, successor boundary, and related support docs. No defensible original-source or linker-retention explanation can be proven from available evidence. This caps confidence below final-audit range but does not block range correction, ownership, score raise, or no-code policy because source behavior is already proven in the live dispatcher branch.

## Documentation Evidence Rechecked

- [UID:0001AZ] target doc: strong behavior notes and prior IDA evidence remain valid, but the title/path/range is stale and the score can now rise after independent PE byte and route validation.
- [UID:0001AW] `MapPanePacketHandlers`: child-table, function-inventory, and cross-reference links need mechanical range/path update from `...b7` to `...ba`.
- [UID:0000L3] `MapPane`: correctly states that live opcode `0x6a` is the proven source route and raw [UID:0001AZ] has no xrefs; links need range/path update.
- [UID:00007Q] `MapPane` class: supports live dispatcher relationship. No class-ownership change recommended because the raw body has no receiver and source-family placement is file-level.
- [UID:0000UP] `FriendNameListSyncOpcodes`: behavior, opcode roles, and support names remain valid; links and the stale raw range mention need update.
- [UID:0000PG] `byte_66DEE0` and [UID:0001OM] storage page: `g_friendNameListSyncEnabled` role remains valid; links need range/path update.
- [UID:0001HX] `BuildAndSendFriendNameListSync`: helper role and Socket placement remain valid.
- [UID:0000Q5] `g_packetSender`: `dword_67A7EC` alias and Socket pointer interpretation remain valid.
- [UID:0000JN] / [UID:00005J] `FriendListDialog`: caller relationship remains valid and does not transfer ownership of the raw packet body.
- [UID:0001SO] `MapServerPacketOpcode`: opcode `0x6a` semantics remain valid; the raw duplicate link needs range/path update.
- Generated/project-level files and validator registry contain old paths because the target file has not been renamed. They should be regenerated/refreshed by the supervisor/validator path, not edited manually by B004.

## Ranked Ownership And Source Alternatives

### 1. [UID:0000L3] MapPane file - accepted

- Evidence for: live modeled branch is inside `MapPane::HandlePacket`; raw body duplicates that branch; parent aggregate [UID:0001AW] is MapPane packet handlers; source tree placement is `NexusTK/map/MapPane.cpp`; no raw receiver requires class-level method ownership.
- Evidence against: raw body itself has no caller and no IDA function. This prevents independent source C++, not MapPane-family evidence placement.
- Decision: keep `CANONICAL_OWNER:0000L3` and `EMITTER_UIDS:0000L3`; final C++ blank.

### 2. [UID:00007Q] MapPane class - rejected as direct owner for this raw item

- Evidence for: the live dispatcher is a MapPane method and opcode handling is class behavior.
- Evidence against: raw [UID:0001AZ] has no `this` load, no class receiver, no vtable route, and no function object. Current target already uses file owner, which better matches a retained no-receiver raw duplicate.
- Decision: keep class as contextual support only.

### 3. [UID:0000JN] FriendListDialog file - rejected as raw target owner

- Evidence for: `FriendListDialog::OnOkButton` reads `g_friendNameListSyncEnabled` and calls the same outbound helper after saving friend names.
- Evidence against: it is a consumer/UI state owner, not the inbound packet dispatcher route. The raw body duplicates MapPane opcode handling, not dialog code.
- Decision: retain FriendListDialog as global/feature support owner for `g_friendNameListSyncEnabled`; do not move [UID:0001AZ].

### 4. [UID:0000DD] / [UID:0000NS] Socket - rejected as raw target owner

- Evidence for: `0x00574e50` is Socket/send-path code and is called through `g_packetSender`.
- Evidence against: [UID:0001AZ] is a packet-receive branch that only invokes the Socket helper; callee ownership does not own the caller body.
- Decision: keep [UID:0001HX] and `g_packetSender` in Socket documentation; do not move [UID:0001AZ].

### 5. [UID:0000UP] FriendNameListSyncOpcodes item - rejected as source owner

- Evidence for: best protocol-level explanation for opcode `0x6a`, outbound opcode `0x77`, the flag, and helper relationship.
- Evidence against: by-item protocol docs are explanatory support, not a final source file or emitter for the raw body.
- Decision: keep as support/cross-reference.

### 6. `CANONICAL_OWNER:NONE` / ignored raw bytes - rejected

- Evidence for: no direct route to raw start is proven.
- Evidence against: body is not padding; it is a complete source-shaped duplicate with meaningful xrefs-from and a documented MapPane packet-handler aggregate context. Nearby [UID:0001AX] uses the same retained raw duplicate convention.
- Decision: do not mark ignored and do not clear the MapPane source-family assignment.

## First-Draft C++ Recommendation

Do not populate [UID:0001AZ] `RECONSTRUCTION_CPP`. The target-specific no-code proof is:

- raw start `0x00514380` has no modeled IDA function;
- local PE scans find no VA, RVA, raw-offset, vtable/pointer-table, rel32 call, rel32 jump, or rel32 conditional-branch route;
- existing IDA-backed docs report no direct xrefs/callers;
- the live `MapPane::HandlePacket` branch at `0x00508ae3-0x00508b19` already implements the behavior;
- adding code to [UID:0001AZ] would duplicate source behavior and imply unproven reachability.

The source behavior should instead be represented in the live dispatcher branch, approximately:

```cpp
case 0x6a:
{
    int cursor = 1;
    const bool enabled = PacketBufferReadByteAtCursor(packet, &cursor) != 0;
    g_friendNameListSyncEnabled = enabled;
    if (enabled)
    {
        BuildAndSendFriendNameListSync(g_packetSender);
    }
    return true;
}
```

Name status for this illustrative source snippet:

- `0x6a`: verified inbound opcode value, descriptive role `friend/name-list sync control`, original enum name not recovered.
- `PacketBufferReadByteAtCursor`: descriptive/inferred name for `0x00575710`.
- `g_friendNameListSyncEnabled`: descriptive/inferred source-facing name for `byte_66DEE0`.
- `BuildAndSendFriendNameListSync`: descriptive/inferred source-facing name for `0x00574e50`.
- `g_packetSender`: resolved source-facing name for `dword_67A7EC` from [UID:0000Q5].

## Score And Metadata Recommendations

Recommended target metadata after supervisor applies the range/path repair:

```text
*** UID:0001AZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000L3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Recommended target title:

```markdown
# 0x00514380-0x005143ba - Friend Name-List Sync Raw Handler
```

Score rationale:

- Completion `86`: the page can include exact PE-derived raw bytes, corrected boundary, exact padding, VA/RVA/raw-offset mapping, live-branch comparison, no-route scans, modeled-function absence, support-doc revalidation, source-name decisions, and no-code proof. It remains capped because the duplicate retention reason is not provable.
- Confidence `90`: raw bytes and route scans are direct local evidence, and existing docs provide IDA-backed xrefs/function facts. It remains below final-audit confidence because current IDA MCP is offline and no original-source symbol or route explains why the duplicate exists.

## Coverage And Support Replacement Text

Do not edit `by-memory/-coverage-report.md` directly. If the supervisor applies this report, replace the current [UID:0001AZ] row under the [UID:0001AW] block, between [UID:0001AY] and [UID:0001B0], with:

```markdown
        - [UID:0001AZ][0x00514380-0x005143ba.FriendNameListSyncRawHandler](by-memory/0x00514380-0x005143ba.FriendNameListSyncRawHandler.md) 0x00514380-0x005143ba | retained raw duplicate packet-handler body | FriendNameListSyncRawHandler : reconstructable : 86% : strong : Raw PE bytes and existing IDA-backed docs confirm a 58-byte source-shaped duplicate of the live `MapPane::HandlePacket` opcode `0x6a` friend/name-list sync branch; corrected half-open range includes the `ret 4` at `0x005143b7-0x005143ba`, followed by six `0xcc` bytes before `sub_5143C0`, with no modeled IDA function, no direct caller/xref, no VA/RVA/raw-offset pointer-table hit, and no rel32 call/jump route to `0x00514380`; final C++ stays blank because emission belongs to the live dispatcher branch.
```

Recommended parent/support replacements:

1. In [UID:0001AW] `by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md`, replace the child table row:

```markdown
| [UID:0001AZ][0x00514380-0x005143ba.FriendNameListSyncRawHandler](by-memory/0x00514380-0x005143ba.FriendNameListSyncRawHandler.md) | Contained 58-byte raw duplicate of the live opcode `0x6a` friend/name-list sync path; body ends at `0x005143ba` and is followed by six `0xcc` bytes before `sub_5143C0`. |
```

2. In the same parent function inventory, replace the raw-start row with:

```markdown
| `0x00514380` | not modeled | none | Raw duplicate [UID:0001AZ][0x00514380-0x005143ba.FriendNameListSyncRawHandler](by-memory/0x00514380-0x005143ba.FriendNameListSyncRawHandler.md); no direct xrefs/callers or VA/RVA/raw-offset/rel32 route currently reported. |
```

3. In the same parent cross-reference list, replace the old link with:

```markdown
- [UID:0001AZ][0x00514380-0x005143ba.FriendNameListSyncRawHandler](by-memory/0x00514380-0x005143ba.FriendNameListSyncRawHandler.md)
```

4. In [UID:0000L3] `by-file/MapPane.md`, replace the old raw duplicate sentence in the send-helper recheck paragraph with:

```markdown
A 58-byte raw duplicate handler at [UID:0001AZ][0x00514380-0x005143ba.FriendNameListSyncRawHandler](by-memory/0x00514380-0x005143ba.FriendNameListSyncRawHandler.md) has the same behavior but no current xrefs; its corrected body includes the `ret 4` at `0x005143b7-0x005143ba`, followed by six `0xcc` bytes before `sub_5143C0`.
```

Also replace the MapPane cross-reference link with the same `0x00514380-0x005143ba` link.

5. In [UID:0000UP] `by-item/FriendNameListSyncOpcodes.md`, replace the first raw mirror sentence with:

```markdown
A second 58-byte raw function-shaped body at [UID:0001AZ][0x00514380-0x005143ba.FriendNameListSyncRawHandler](by-memory/0x00514380-0x005143ba.FriendNameListSyncRawHandler.md) performs the same read/write/send sequence but currently has no IDA function object or direct xrefs to its start. Treat it as corroborating raw evidence, not the primary live route.
```

Replace its cross-reference link with the same `0x00514380-0x005143ba` link, and replace the stale change-log phrase:

```markdown
raw mirror code at `0x00514380-0x005143ba`
```

6. In [UID:0000PG] `by-global/byte_66DEE0.md`, replace the [UID:0001AZ] link with:

```markdown
- [UID:0001AZ][0x00514380-0x005143ba.FriendNameListSyncRawHandler](by-memory/0x00514380-0x005143ba.FriendNameListSyncRawHandler.md)
```

7. In [UID:0001OM] `by-memory/0x0066dee0-0x0066dee1.FriendNameListSyncEnabled.md`, replace the explanatory sentence with:

```markdown
- The `0x0051439c` write is in [UID:0001AZ][0x00514380-0x005143ba.FriendNameListSyncRawHandler](by-memory/0x00514380-0x005143ba.FriendNameListSyncRawHandler.md), an unmodeled 58-byte duplicate body with the same read, store, and optional send sequence.
```

Also replace its cross-reference link with the same `0x00514380-0x005143ba` link.

8. In [UID:0001SO] `by-type/by-enum/MapServerPacketOpcode.md`, replace the raw duplicate clause with:

```markdown
A raw duplicate at [UID:0001AZ][0x00514380-0x005143ba.FriendNameListSyncRawHandler](by-memory/0x00514380-0x005143ba.FriendNameListSyncRawHandler.md) performs the same sequence but has no current direct xrefs.
```

Generated/project-level files should not be manually patched; refresh them after the target rename and coverage/support updates.

## Validator And Command Results

Commands/results from this pass:

- `Test-NetConnection 127.0.0.1 -Port 13337`: `TcpTestSucceeded : False`. IDA MCP unavailable.
- `Test-Path E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`: `True`.
- `Test-Path E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`: `True`.
- Local PE extractor over `NexusTK.exe`: produced `.text` mapping, body/padding hashes, byte listings, hidden-route zero-hit scans, and positive controls for `0x0066dee0`/`0x0067a7ec`.
- Capstone disassembly over local PE bytes: confirmed corrected raw body and live dispatcher branch instructions shown above.
- `rg` support-link search: found stale `0x00514380-0x005143b7` links/ranges in non-generated support docs listed in the replacement section; generated/project-level paths also contain old strings and should be refreshed, not edited manually.
- No validator apply command was run because this assignment is report-only and no by-* files were edited.

Conversion note: decimal conversions cited in this report were checked in the assignment notes with `int_convert.py`. During the resumed pass, `rg --files` under `E:\NTK\GhidraBridge` and `C:\Users\admin\Desktop\CTools` did not locate the helper path, so no new decimal-only facts were introduced beyond the already checked conversion set.

## Changed Files

- Created: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B004\research\0001AZ-FriendNameListSyncRawHandler-source-quality.md`.
- Modified: none outside the required Agent-B004 report.
- Renamed: none.
- Generated/project-level/by-memory coverage edits: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/0001AZ-FriendNameListSyncRawHandler-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:29","uid":"0001AZ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
