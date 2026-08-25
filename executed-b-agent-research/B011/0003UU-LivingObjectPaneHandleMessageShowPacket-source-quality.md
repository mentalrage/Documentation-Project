** TARGET-REPORT-UID:0003UU **
** AUTHOR-AGENT-ID:B011 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0003UU LivingObjectPaneHandleMessageShowPacket Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003UU] as source-bearing reconstructable project code and keep the current file-local/static local-player server-packet helper route through [UID:0000KU] `by-file/LivingObjectPane.md`. Current target/support docs already contain the accepted implementation details; this callback updates the active report artifact after claim-by-claim verification.
- Final disposition: post-Gate-1 implementation/verification callback complete. No by-* docs needed edits because every accepted target/support fact was already present at same-or-greater detail; no leases were used, no validators were run by B011, and `execute_report` remains supervisor-only.
- Current metadata in the target after supervisor validator command `000000006862`: `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000KU`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KU`, blank emitter position.
- Source-facing name direction: `HandleMessageShowPacket` or `HandleServerMessageShowPacket`. `MessageShow` remains descriptive/inferred from behavior; the server packet name table entry for opcode `0x58` is `#88`, not a semantic recovered packet name.
- Formal C++ disposition: target formal C++ is already populated with the first-draft file-local/static helper body. The helper is not a `LivingObjectPane::` non-static member and not a `MessageShowPane::` method.
- Confidence: high for range, route, packet layout, callee behavior, and the not-a-class-method conclusion; medium-high for exact original translation-unit/linkage spelling.

## Supporting Research

- Historical lifecycle note: validator command `000000004167` marked the executed report for revalidation with `target_uid_unknown: 0003UU`; command `000000006861` returned the report from `executed-b-agent-research/B011` to this active B011 research path for repair. Those facts are preserved only as history in the validator-owned footer and here; they are not current top-level status headers.
- Supervisor scoped repair already run: command `000000006862`, timestamp `2026-07-05T07:04:07-04:00`, command `python .\tools\validator.py --mode file --file by-memory/0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket.md --apply --queue-timeout 240`, exit `0`, `ok: 1`.
- Reported effects of `000000006862`: `path_update`, `completion_update 88`, `confidence_update 90`, `canonical_owner_update 0000KU`, autogen registry updates, reference index additions, projected stats update, and `generated_refresh: deferred`.
- Gate 1 passed for this report at SHA256 `BFEC6E9A88E22BBE17D5E547691A04CAFB9D6909FDFA9A18E70649798FC9F79B`. The implementation/verification callback rechecked the accepted scope and found no by-* mismatch.
- Current docs confirm the previous B011 implementation is present in the target and support pages. This callback therefore made no by-* edits.
- Historical fallback evidence from the earlier report used local PE/Capstone because MCP was unavailable at that time. This repaired active report now includes a current MCP refresh from `supervisor_recovery_20260705`; old PE/Capstone scans remain corroborating evidence for raw byte/pointer-route claims that current bounded MCP tools do not expose directly.

## Target

- Target UID: [UID:0003UU]
- Target path: `source-3/project-documentation/by-memory/0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B011/research/0003UU-LivingObjectPaneHandleMessageShowPacket-source-quality.md`
- Current metadata: `88/90`, `CANONICAL_OWNER:0000KU`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KU`, blank `EMITTER_POSITION_OPTIONAL`.
- Current doc disposition: source-authored file-local/static local-player server-packet helper in the `LivingObjectPane.cpp` source neighborhood with `MessageShowPane` dependency.
- Current formal C++: populated as `static bool HandleMessageShowPacket(const unsigned char *packet)`.
- Current open questions: exact original helper linkage/spelling and exact original packet symbolic name remain inferred; these do not block current owner/emitter/C++ disposition.

## Current Target State

- Target header now has [UID:0003UU], `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000KU`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KU`, and blank `EMITTER_POSITION_OPTIONAL`.
- Formal C++ now emits a file-local `static bool HandleMessageShowPacket(const unsigned char *packet)` helper. It reads `packet[1]`, uses `PacketBufferReadUInt16BE(packet + 2)`, copies `packet + 4` through `memmove`, converts through `MultiByteToWideChar(0, 0, ...)`, updates or constructs `MessageShowPane`, deletes `g_pMessageShowPane` on close, and returns `true` on non-range-failure paths.
- Target body records the exact route, boundaries, packet layout, helper/global name resolution, rejected class/UserPane/MessageShowPane direct ownership alternatives, and first-draft C++ notes at report-level detail.
- Support docs checked and already synchronized include `by-file/LivingObjectPane.md`, `by-class/LivingObjectPane.md`, `by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md`, `by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md`, `by-file/UserPane.md`, `by-class/UserPane.md`, `by-file/MessageShowPane.md`, `by-class/MessageShowPane.md`, `by-global/g_pMessageShowPane.md`, `by-memory/0x0069b4f4-0x0069b4f8.g_pMessageShowPane.md`, `by-memory/0x00522530-0x005226ea.MessageShowPaneSetWrappedText.md`, and `by-memory/0x00625008-0x0062ce50.ServerPacketNameTable.md`.
- Current artifact/lifecycle status: active repaired report in B011 research folder, Gate 1 passed at the supervisor-provided SHA, and callback verification is complete. The validator-owned `VALIDATOR-REPORT-HISTORY` footer is preserved unchanged.

## Evidence Checked

- Target doc: `by-memory/0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket.md`.
- Caller doc: [UID:0003VB] `by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md`.
- Split index: [UID:0001KM] `by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md`.
- Owner candidates:
  - [UID:0000KU] `by-file/LivingObjectPane.md` (`88/85`).
  - [UID:00007B] `by-class/LivingObjectPane.md` (`85/85`).
  - [UID:0000P1] `by-file/UserPane.md` (`89/85`).
  - [UID:0000FQ] `by-class/UserPane.md`.
  - [UID:0000LB] `by-file/MessageShowPane.md` (`86/87`).
  - [UID:000087] `by-class/MessageShowPane.md` (`86/88`).
- MessageShow support:
  - [UID:0001C4] `by-memory/0x00522530-0x005226ea.MessageShowPaneSetWrappedText.md`.
  - [UID:0000RK] `by-global/g_pMessageShowPane.md`.
  - [UID:0001PX] `by-memory/0x0069b4f4-0x0069b4f8.g_pMessageShowPane.md`.
  - [UID:0002Y8] `by-memory/0x00521da0-0x005227c6.MessageShowPaneMethods.md`.
  - [UID:0003PC] `by-memory/0x0061fa4c-0x0061fadc.MessageShowPaneVtableData.md`.
- Packet helper support:
  - [UID:0003YK] `by-memory/0x00575480-0x00575574.PacketBufferScalarBigEndianReadHelpers.md`.
  - [UID:0001BC] `by-memory/0x00516030-0x00516036.GetMemoryMan.md`.
  - [UID:0001BH] `by-memory/0x00516220-0x00516238.MemmoveWrapper.md`.
  - [UID:00026H] `by-memory/0x00625008-0x0062ce50.ServerPacketNameTable.md`.
- Prior B-report evidence:
  - `Agent-B001/research/executed/older/0001KM-livingobject-localplayer-source-split-audit.md` created the old "LivingObjectPane server-packet child with MessageShowPane dependency" hypothesis and explicitly marked source placement medium.
  - `Agent-B001/research/00007B-LivingObjectPane-class-source-quality.md` lists [UID:0003UU] as a local-player tail item, but does not resolve the `__stdcall`/no-`this` shape.
- Current MCP evidence from session `supervisor_recovery_20260705`:
  - `idb_list`: one active worker session, `NexusTK.exe.i64`, owned/adopted worker pid `19604`, `is_analyzing:false`.
  - `server_health`: `status:ok`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, strings cache ready.
  - `lookup_funcs`: `0x005ac070` is `sub_5AC070`, size `0x138`; `0x005ac1a8` and `0x005ac1b0` are not function starts; `0x005a8172` belongs to `sub_5A76C0`, size `0xbfd`.
  - `lookup_funcs` for helpers: `0x00522530` is `sub_522530`, size `0x1ba`; `0x00521da0` is `sub_521DA0`, size `0x220`; `0x00575470` is the `std::_Narrow_char_traits<char,int>::to_char_type` helper, size `0xa`; `0x00575480` is `sub_575480`, size `0x1a`; `0x00516030` is `sub_516030`, size `0x6`; `0x00516220` is `sub_516220`, size `0x18`.
  - `xrefs_to 0x005ac070`: exactly one code xref, from `0x005a8172` in `sub_5A76C0`; `more:false`, `xref_count:1`.
  - `xrefs_to 0x00522530` and `0x00521da0`: direct target calls at `0x005ac150` and `0x005ac17e`.
  - `xrefs_to 0x0069b4f4`: eight lifecycle/consumer refs, including target reads at `0x005ac0bc` and `0x005ac13f`.
  - `disasm 0x005ac070` capped at 120 instructions returned all 110 target/handler instructions and the relevant EH records, including `mov edi,[ebp+arg_0]`, packet byte/length reads, `ret 4`, and the range-check failure call.
  - `decompile 0x005ac070` confirms `char __stdcall sub_5AC070(int a1)`, two 32768-element local buffers, `sub_575480(a1+2)`, `sub_516220(MultiByteStr, a1+4, v1)`, `MultiByteToWideChar(0,0,...)`, update via `sub_522530`, allocation size `65796` / `0x10104`, constructor call `sub_521DA0`, scalar-delete close path, and return `1`.
  - Exact-name `lookup_funcs` negative check: `LivingObjectPaneHandleMessageShowPacket`, `HandleMessageShowPacket`, `HandleServerMessageShowPacket`, and `MessageShowPacket` are not IDA function names; current IDA symbol is still `sub_5AC070`.
- Historical/local PE/Capstone evidence from `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`:
  - PE image base `0x00400000`.
  - Function bytes and callsite disassembly for `0x005ac070-0x005ac1a8`.
  - PE-aware direct rel32 scan for target and MessageShow callees.
  - Server packet name table read for opcode `0x58`.
- Negative/failure checks:
  - Current MCP `find_bytes` schema lacks address-bound arguments, so it was not used for range-limited padding proof; the exact padding bytes remain historical PE byte evidence, while current MCP `lookup_funcs` confirms the end and successor are not function starts.
  - No by-* docs were edited during this callback, no scoped validator was run by B011, and no lifecycle/execute/archive command was run.

## Evidence Standards Used

- Direct IDA MCP facts are treated as highest weight for function boundaries, function names/sizes, xrefs, callee routes, decompiler calling convention, helper set, and singleton xrefs.
- Current by-* docs are treated as current project state and implementation-incorporation evidence, not as a substitute for MCP.
- Historical PE/Capstone scans are retained as corroborating evidence for exact raw bytes, PE-aware VA/RVA pointer scans, and packet-name table text where the current bounded MCP tool schema does not expose an equivalent narrow address-limited byte/pointer search.
- Older B001/B011 reports are used only as leads or historical context. The current recommendation depends on the current MCP refresh plus current by-* docs.
- The evidence is strong enough for `88/90` because the live route, body behavior, owner/emitter route, packet layout, helper names, and formal C++ shape are all backed by direct binary facts. It is not higher because original helper linkage/spelling and the exact original packet symbolic name remain unrecovered.

## IDA MCP Facts

### Function Range And Padding

- Current `lookup_funcs` reports `0x005ac070` as `sub_5AC070`, size `0x138` / 312 bytes.
- Current `lookup_funcs` reports `0x005ac1a8` and `0x005ac1b0` are not function starts.
- Entry bytes start with SEH/security-cookie/stack-probe setup:
  - `55 8b ec 6a ff 68 84 af 60 00 ... b8 08 80 01 00 e8 b5 b6 01 00`.
- The large stack reservation is `0x18008`, matching two local buffers:
  - `char multiByteText[0x8000]` at `ebp-0x8010`.
  - `WCHAR wideText[0x8000]` at `ebp-0x18010`.
- Preceding boundary: local PE bytes from `0x005ac060-0x005ac070` are `00 cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc`; treat `0x005ac061-0x005ac070` as alignment after the predecessor tail.
- Following boundary: `0x005ac1a8-0x005ac1b0` is eight `0xcc` bytes before the raw/projected `0x005ac1b0` position-sync helper.
- The terminal range-check failure call starts at `0x005ac1a3` and ends exactly at the page endpoint:
  - `0x005ac1a3: e8 ad b4 01 00 call 0x005c7655`.

### Caller / Route Facts

- Current `xrefs_to 0x005ac070` reports exactly one direct code xref: `0x005a8172` in function `sub_5A76C0`, size `0xbfd`.
- Historical PE-aware rel32 scan found the same single direct branch/call route to `0x005ac070`: `call 0x005ac070` at `0x005a8172`.
- No absolute VA bytes and no target-RVA bytes for `0x005ac070` were found in the executable scan.
- The caller is [UID:0003VB] `UserPane::OnServerMessage`.
- The relevant caller pseudocode is `case 0x58u: return sub_5AC070((int)v6);`.
- The raw callsite is:
  - `0x005a816b: push edi`
  - `0x005a816c: lea ecx, [ebx - 0xa0]`
  - `0x005a8172: call 0x005ac070`
- The callsite seeds `ecx` with the local-player/LivingObjectPane subobject address, but the callee does not consume that receiver as `this`.
- The target returns with `ret 4`, so it is a one-argument `__stdcall`-shaped helper, not a normal `__thiscall` member.

### Not-A-Thiscall Evidence

- The first packet pointer load is `0x005ac0a2: mov edi, [ebp+8]`.
- The initial `ecx` from the caller is not stored as `this`, unlike neighboring handlers:
  - `0x005aa480` stores `ecx` into `esi` and writes fields such as `esi+0x1340fc`.
  - `0x005ab860` stores `ecx` into `ebx` and later reads `ebx+0x13eb0c`.
  - `0x005abda0` stores `ecx` into `esi`.
  - `0x005ac280` stores `ecx` at a local and reads fields such as `this+0x3cb0`.
- In [UID:0003UU], `ecx` is later loaded from `g_pMessageShowPane` for virtual destructor/update calls and from `g_pMemoryMan` only as incidental register state before `memmove`; it is not the caller-provided object pointer.
- Therefore [UID:0003UU] should not be described as a `LivingObjectPane` instance method. A file-local/static helper in the local-player packet source group is the safest source shape.

### Packet Layout Facts

The only direct caller is `UserPane::OnServerMessage` opcode `0x58`. The packet table entry for `0x58` at `0x00627b58` decodes as UTF-16 `#88`, not a semantic name. `MessageShow` is inferred from behavior.

Target packet fields:

| Packet offset | Evidence | Best name / role |
| --- | --- | --- |
| `payload[0]` | Dispatcher case `0x58` in `UserPane::OnServerMessage`; table label `#88` at `0x00627b58`. | Server opcode `0x58`; descriptive name `MessageShow`, not table-proven. |
| `payload[1]` | `0x005ac0aa lea ecx,[edi+1]`, call `0x00575470`, `test al,al`. | Show/update flag; zero means close active overlay, nonzero means create/update. |
| `payload+2` | `0x005ac0d5 lea eax,[edi+2]`, call `0x00575480`, `movzx esi, ax`. | Big-endian 16-bit text byte length via `PacketBufferReadUInt16BE`. |
| `payload+4` | `0x005ac0e4 lea eax,[edi+4]`, copy length `esi` through `0x00516220`. | Encoded narrow text bytes. |

The body does not parse a second subtype after opcode `0x58`; `payload[1]` is the state/enable byte.

### Callee / Helper Facts

| Address | Existing support name | Role in [UID:0003UU] |
| --- | --- | --- |
| `0x00516030` | `GetMemoryMan` | Returns `g_pMemoryMan`; called before copy helper, but source draft can use `memmove` directly. |
| `0x00516220` | `MemmoveWrapper` | Copies `textLength` bytes from `payload+4` into the local narrow buffer. |
| `0x00575470` | `std::_Narrow_char_traits<char,int>::to_char_type` / tiny byte read | Reads one byte from `payload+1`; do not make this a project helper name. |
| `0x00575480` | `PacketBufferReadUInt16BE` | Reads the big-endian text byte count from `payload+2`. |
| `IAT 0x0060d120` | `MultiByteToWideChar` | Converts the copied narrow bytes with code page `0` / `CP_ACP`, flags `0`, destination capacity `0x8000`. |
| `0x00522530` | `MessageShowPane::SetWrappedText` | Updates the existing overlay text when `g_pMessageShowPane` is non-null. |
| `0x004f4aa0` | operator new wrapper | Allocates `0x10104` bytes for a new `MessageShowPane`. |
| `0x00521da0` | `MessageShowPane::MessageShowPane` | Constructs the overlay with the converted wide text; constructor stores `g_pMessageShowPane`. |
| `vtable[0]` on `g_pMessageShowPane` | scalar deleting destructor slot | Close path calls the virtual scalar deleting destructor with delete flag `1`. |
| `0x005c7655` | `__report_rangecheckfailure` | Compiler/runtime range-check failure for local-buffer indexing. |

Local helper disassembly confirmed:

- `0x00575470-0x0057547a`: reads `byte ptr [arg]` and returns it in `al`; this is runtime/char-traits glue, not a source-level packet API.
- `0x00575480-0x0057549a`: computes `payload[0] * 0x100 + payload[1]`; this is exactly `PacketBufferReadUInt16BE`.
- `0x00516030-0x00516036`: returns `dword ptr [0x0069b4fc]` / `g_pMemoryMan`.
- `0x00516220-0x00516238`: pushes `(size, src, dst)`, calls `_memmove`, and returns with `ret 0x0c`.

### MessageShowPane Lifecycle Facts Used

- [UID:0000RK] and [UID:0001PX] identify `g_pMessageShowPane` at `0x0069b4f4`.
- `g_pMessageShowPane` has direct packet-handler reads at `0x005ac0bc` and `0x005ac13f`.
- The close path reads `g_pMessageShowPane`, tests for null, loads the vtable, pushes delete flag `1`, and calls vtable slot zero. This is `delete g_pMessageShowPane`, and the ordinary/scalar destructor clears the singleton.
- The update path calls [UID:0001C4] `MessageShowPane::SetWrappedText` at `0x005ac150`.
- The create path allocates exactly `0x10104` bytes, then calls `MessageShowPane::MessageShowPane(wideText)` at `0x005ac17e`.
- [UID:0001C4] currently records this target as its only direct caller at `0x005ac150`.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C001 | [UID:0003UU] is one exact modeled function at `0x005ac070-0x005ac1a8`, size `0x138`, with successor `0x005ac1b0` outside the page. | High | Current MCP `lookup_funcs` `sub_5AC070` size `0x138`; `0x005ac1a8` and `0x005ac1b0` not functions; historical PE padding bytes. | Target `Function Range And Boundaries`; split index function map. | Keep current boundary/padding/range text. | already-present |
| C002 | The only live direct route is `UserPane::OnServerMessage` opcode `0x58` calling `0x005ac070` at `0x005a8172`. | High | Current MCP `xrefs_to 0x005ac070` one xref at `0x005a8172`; dispatcher docs and historical rel32 scan agree. | Target `Dispatch Route And Call Shape`; `by-memory/0x005a76c0-...UserPaneHandleServerMessage.md`; UserPane file/class docs. | Keep the opcode/callsite route and no-pointer-route caveat. | already-present |
| C003 | The helper is not a `LivingObjectPane` instance method; it is `ret 4`, reads one stack packet pointer, ignores caller-seeded `ecx`, and touches no `LivingObjectPane` fields. | High | MCP disasm/decompile: `mov edi,[ebp+arg_0]`, `retn 4`; current target/support docs record neighboring contrast. | Target `Dispatch Route And Call Shape` and `Ownership And Source Placement`; `by-class/LivingObjectPane.md`. | Keep direct class-method rejection and file-local/static helper wording. | already-present |
| C004 | Canonical owner/emitter should be [UID:0000KU] `by-file/LivingObjectPane.md`, not [UID:00007B], [UID:0000P1], or [UID:0000LB]. | Medium-high | Address/source-family locality, single dispatcher route, no `this` use, dependency direction to MessageShowPane. | Target metadata/status; `by-file/LivingObjectPane.md`; support owner notes. | Keep owner/emitter `0000KU`; preserve rejected alternatives. | already-present |
| C005 | Packet layout is opcode `0x58`, `payload[1]` show/close flag, `payload+2` BE16 text byte count, `payload+4` narrow bytes; `MessageShow` is descriptive because table slot `0x00627b58` is `#88`. | High for layout, medium-high for name. | MCP disasm/decompile packet reads; historical packet table read; dispatcher case. | Target `Packet Layout`; server packet table doc. | Keep exact layout and descriptive-name caveat. | already-present |
| C006 | Close/update/create behavior uses `g_pMessageShowPane`: delete through scalar-deleting destructor flag `1`, call `MessageShowPane::SetWrappedText`, or allocate `0x10104` and construct `MessageShowPane`. | High | MCP disasm/decompile; `xrefs_to 0x00522530`, `0x00521da0`, `0x0069b4f4`; support docs. | Target `Behavior`; `g_pMessageShowPane`; MessageShowPane file/class and SetWrappedText docs. | Keep behavior and dependency evidence. | already-present |
| C007 | Formal C++ first draft is appropriate as file-local `static bool HandleMessageShowPacket(const unsigned char *packet)` with range-check fail-fast behavior. | Medium-high | Combined score/emitter gate clears at `88/90` with `0000KU`; MCP decompile/disasm confirms exact body. | Target formal `RECONSTRUCTION_CPP CODE` block. | Keep current formal C++ body; no new edit needed. | already-present |
| C008 | Prior top-level `REPORT-VALIDATION-STATUS` and `REPORT-REVALIDATION-REASON` must not remain as current active-report headers; history belongs in body/footer. | High | Supervisor assignment and goal.md narrow override; validator history footer carries historical events. | Report `Supporting Research`; top report metadata header. | Remove top-level status/reason lines; preserve footer unchanged. | applied |
| C009 | Validator command `000000006862` is current supervisor-run mapping/metadata repair and must be recorded with effects. | High | Supervisor goal.md command metadata. | Report `Supporting Research`, `Validator Results`, `Changed Files`, checklist. | Record command id, timestamp, exit, ok count, side effects, generated refresh deferred. | applied |
| C010 | Gate-1 callback verification found no concrete by-* mismatch, so scoped validators are not required in this callback. | High | Current target/support rg checks show accepted facts present in the authorized target and support docs; B-agent workflow requires validators after by-* edits only. | Report `Validator Results`, `Changed Files`, and `Implementation Tracking Checklist`. | Record no-validator reason and ready state. | applied |

## Positive Evidence Summary

- Direct MCP evidence supports the exact function boundary, sole caller, helper set, return convention, packet fields, MessageShowPane calls, singleton xrefs, and decompiler shape.
- Current target/support docs already contain the previous implementation details at report-level detail, including target metadata `88/90`, owner/emitter `0000KU`, formal C++ body, route and packet-layout evidence, and rejected alternatives.
- The strongest inference chain is: `UserPane::OnServerMessage` dispatches opcode `0x58` to `sub_5AC070`; `sub_5AC070` takes a packet pointer by stack and ignores the seeded local-player receiver; the body manipulates `MessageShowPane` singleton state but lives in the local-player packet helper neighborhood; therefore it is best emitted as a file-local/static `LivingObjectPane.cpp` helper, while MessageShowPane and UserPane remain dependency/dispatcher support.

## Negative Evidence Summary

- No current IDA function is named `LivingObjectPaneHandleMessageShowPacket`, `HandleMessageShowPacket`, `HandleServerMessageShowPacket`, or `MessageShowPacket`; `lookup_funcs` only resolves `sub_5AC070`.
- No `LivingObjectPane` field read/write or meaningful `this` use appears in the target body; [UID:00007B] is context, not direct class owner.
- UserPane has the exact dispatcher call but no field ownership inside the callee, so caller-only evidence does not make [UID:0000P1]/[UID:0000FQ] canonical owner.
- MessageShowPane owns the overlay class/global/method dependencies, but the helper takes a packet pointer and sits outside the MessageShowPane method cluster, so [UID:0000LB]/[UID:000087] is not canonical owner for this target.
- Historical PE scan found no VA/RVA pointer route to the target; current MCP proved the code xref route but the current bounded schema did not expose an equivalent address-limited raw pointer scan.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x005ac070-0x005ac1a8` | [UID:0003UU] `by-memory/0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket.md` | Live opcode `0x58` message-show packet helper; file-local/static C++ body. | `TRUE` | [UID:0000KU] `by-file/LivingObjectPane.md` | `88/90` | Current target docs already implemented. |
| `0x005ac1a8-0x005ac1b0` | padding | Eight `0xcc` alignment bytes before successor helper. | n/a | n/a | n/a | Not part of [UID:0003UU]. |
| `0x005ac1b0` successor | Separate raw/projected position-sync helper page | Not part of this target. | Separate target policy | Separate page | n/a | Excluded from this report. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x005a8172 -> 0x005ac070` | Current MCP `xrefs_to 0x005ac070`: one code xref in `sub_5A76C0` / [UID:0003VB]. | Sole live direct dispatcher route, opcode `0x58`. |
| `0x005ac150 -> 0x00522530` | Current MCP `xrefs_to 0x00522530`: one code xref from target. | Existing overlay update via `MessageShowPane::SetWrappedText`. |
| `0x005ac17e -> 0x00521da0` | Current MCP `xrefs_to 0x00521da0`: one code xref from target. | New overlay construction. |
| `0x005ac0bc` and `0x005ac13f` | Current MCP `xrefs_to 0x0069b4f4` includes target reads. | Close-path and update/create-path reads of `g_pMessageShowPane`. |

## Documentation Evidence And IDA Status

- Target page currently records the B011 implementation details and formal C++ body.
- `by-file/LivingObjectPane.md` lists [UID:0003UU] as a file-local/static message-show server packet helper under `LivingObjectPane.cpp`, not a class member.
- `by-class/LivingObjectPane.md` records the no-`this` packet-helper caveat so class declarations do not absorb the helper as a normal member method.
- `by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md` records [UID:0003UU] in the local-player split index as the positive routed contrast in the packet-helper tail.
- `by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md`, `by-file/UserPane.md`, and `by-class/UserPane.md` record that UserPane owns the dispatcher case only.
- `by-file/MessageShowPane.md`, `by-class/MessageShowPane.md`, `by-global/g_pMessageShowPane.md`, `by-memory/0x0069b4f4-0x0069b4f8.g_pMessageShowPane.md`, and `by-memory/0x00522530-0x005226ea.MessageShowPaneSetWrappedText.md` preserve dependency/consumer evidence without assigning this helper to MessageShowPane.
- `by-memory/0x00625008-0x0062ce50.ServerPacketNameTable.md` records the opcode `0x58` slot text as `#88`.
- IDA status: current IDA name remains `sub_5AC070`; source-facing helper names are documentation/source reconstruction inferences, not recovered IDA symbols.

## Heuristic / Inference Reanalysis And Validation

### 1. Source Placement

Best-supported source placement: [UID:0000KU] `NexusTK/map/LivingObjectPane.cpp`, but as a file-local/static helper, not as a `LivingObjectPane` class member.

Evidence for [UID:0000KU]:

- The function is physically in the local-player/server-packet helper tail, between other local-player packet handlers and raw projected helpers.
- Its only caller is the `UserPane::OnServerMessage` local-player packet dispatcher.
- Neighboring functions in this address band are server-packet helpers that are currently routed through the local-player/LivingObjectPane source family.
- The caller still computes the adjusted local-player/LivingObjectPane subobject in `ecx`, matching the surrounding packet-helper call convention, even though this one helper does not use it.
- [UID:0000KU] currently clears the direct file gate (`88/85`).

Evidence against [UID:00007B] class method:

- The target is `ret 4` / one stack argument, not `ret 4` with meaningful `ecx` receiver use.
- It has no `LivingObjectPane` field loads or stores.
- Neighboring true local-player methods preserve and dereference the caller `ecx`; this helper does not.

Evidence against [UID:0000P1] / [UID:0000FQ] UserPane ownership:

- `UserPane::OnServerMessage` is the dispatcher and exact caller, but the helper has no `UserPane` field access.
- The function sits in the server-packet helper cluster after the dispatcher rather than inside the main UserPane virtual method body.
- UserPane should document the opcode `0x58` route, but the helper body is not a UserPane method in the class-layout sense.

Evidence against [UID:0000LB] / [UID:000087] MessageShowPane canonical ownership:

- The function operates almost entirely on `MessageShowPane` state, so MessageShowPane is a real dependency and likely source-level feature name.
- However, the binary address neighborhood and only caller place this body with local-player server-packet dispatch, not with the `MessageShowPane` method cluster at `0x00521da0-0x005227c6`.
- The function is not a `MessageShowPane` method either: it takes a packet pointer, not `MessageShowPane *this`.
- MessageShowPane support docs should keep the packet-handler consumer evidence, but should not list this helper as a direct MessageShowPane source body unless future original-source/file-order evidence overrides the address/caller route.

### 2. Packet Name / Subtype

- Resolved: opcode is `0x58`, reached by `case 0x58u` in [UID:0003VB].
- Resolved: `payload[1]` is an on/off or show/update flag.
- Resolved: `payload+2` is a big-endian 16-bit byte count.
- Resolved: `payload+4` is narrow text payload.
- Not recovered as original name: the server packet name table entry at `0x00627b58` is `#88`, not `kServerMessageShow`.
- Best descriptive names: `kServerMessageShow` for documentation and `HandleMessageShowPacket` for the helper, both explicitly inferred/descriptive.

### 3. Helper Names

- `sub_575470`: do not name as a project helper in this target. It is a tiny runtime/char-traits byte accessor. Source draft should use `packet[1]`.
- `sub_575480`: use existing `PacketBufferReadUInt16BE`.
- `sub_516220`: use existing `memmove` / `MemoryMove` wording. The source draft can call `memmove`.
- `sub_516030`: existing `GetMemoryMan`; not source-important in this helper except as utility lowering before `memmove`.
- `sub_522530`: use `MessageShowPane::SetWrappedText`.
- `dword_69B4F4`: use `g_pMessageShowPane`.

### 4. Range / Split / Merge

- The target range is exact and should remain one function page.
- No split is needed inside `0x005ac070-0x005ac1a8`: the close/update/create behavior is one packet helper.
- The terminal range-check path is part of the same function, not a separate child.
- The eight `0xcc` bytes at `0x005ac1a8-0x005ac1b0` belong in ignored padding, not this page.
- The successor raw helper at `0x005ac1b0` remains separate.

### 5. Final C++ Readiness

- The current item is eligible under the active combined-score/emitter gate if routed through [UID:0000KU].
- Remaining uncertainty is mainly original translation-unit name and whether the helper was declared as `static`, anonymous-namespace, or file-scope free function.
- That uncertainty does not block a first draft because:
  - The function is standalone.
  - Packet layout is exact.
  - Helper names are either existing support names or can be expressed with standard C APIs.
  - The C++ body stays inside the exact function range.
- Draft should not be a `LivingObjectPane::` non-static method and should not be `MessageShowPane::` method.

## Ranked Ownership Analysis

### 1. [UID:0000KU] LivingObjectPane file - Accepted

- Evidence for: address neighborhood, local-player/server-packet source family, only caller from server-message dispatcher, source family gate clears, and neighboring packet helper pattern.
- Evidence against: no `LivingObjectPane` object state is touched.
- Decision: accept as file-level/static helper ownership, not class method ownership. This is the best compromise between binary source locality and the no-`this` fact.

### 2. [UID:0000P1] UserPane file - Plausible but weaker

- Evidence for: exact caller is `UserPane::OnServerMessage`, and the helper consumes only packet/global state.
- Evidence against: function lives in the broader local-player helper tail and support docs already treat most callees as delegated local-player packet bodies; assigning this one to UserPane would over-weight caller ownership.
- Decision: reject as canonical owner; update UserPane docs to describe the opcode `0x58` call accurately.

### 3. [UID:0000LB] MessageShowPane file - Feature owner/dependency, not canonical code owner

- Evidence for: all visible effects are `MessageShowPane` singleton/update/create/delete.
- Evidence against: not a `MessageShowPane` method, only route is server dispatcher, and address/source locality is not the MessageShowPane method cluster.
- Decision: reject as canonical owner for [UID:0003UU]; preserve as dependency/support owner for class, singleton, vtable, constructor, destructor, and `SetWrappedText`.

### 4. [UID:00007B] LivingObjectPane class - Current metadata, reject as direct owner

- Evidence for: older B001 local-player tail route and caller-seeded adjusted `ecx`.
- Evidence against: target does not use `ecx` as `this`, uses no class fields, and compiles as one-argument `__stdcall`.
- Decision: replace `CANONICAL_OWNER:00007B` / `EMITTER_UIDS:00007B` with file-level `0000KU`.

### 5. No-code / compiler glue - Rejected

- Evidence for: none beyond runtime helper calls and compiler range-check/security boilerplate.
- Evidence against: one live caller, custom packet parsing, UI state changes, allocation, update/delete behavior, and nontrivial project control flow.
- Decision: source-bearing, first-draft C++ ready.

## Source Placement

- Recommended source placement remains [UID:0000KU] `NexusTK/map/LivingObjectPane.cpp` as a file-local/static packet helper in the local-player/server-packet neighborhood.
- This placement fits address locality and existing local-player packet-helper grouping while respecting the no-`this` body shape.
- Rejected placements: [UID:00007B] class member method, [UID:0000P1]/[UID:0000FQ] UserPane method, and [UID:0000LB]/[UID:000087] MessageShowPane method.
- Remaining uncertainty: exact original linkage/spelling, such as `static` free function versus anonymous-namespace/internal helper, is not recovered. This does not change the current owner/emitter route or first-draft C++ body.

## Range / Split / Padding / Reclassification Analysis

- Exact modeled function range is `0x005ac070-0x005ac1a8`, size `0x138`.
- No child split is needed inside the page. The close, update, create, conversion, and range-check paths are one helper.
- Historical PE bytes show preceding alignment `0x005ac061-0x005ac070` and following eight `0xcc` bytes at `0x005ac1a8-0x005ac1b0`.
- Current MCP `lookup_funcs` confirms the endpoint and successor are not function starts under the current IDB.
- Reclassification already present: target moved from class-owned `LivingObjectPane` method framing to [UID:0000KU] file-local/static packet helper.

## First-Draft C++ Recommendation

Recommended formal C++ is already present in [UID:0003UU] after metadata changed to file-level [UID:0000KU]. This is draft source, not final audited source. `MessageShowPacket` and `PacketBufferReadUInt16BE` are descriptive/support names; `__report_rangecheckfailure` is retained only to preserve the observed fail-fast range-check path until the reconstruction framework decides whether compiler array-bound checks are generated automatically.

```cpp
static bool HandleMessageShowPacket(const unsigned char *packet)
{
    char multiByteText[0x8000];
    wchar_t wideText[0x8000];

    if (packet[1] == 0)
    {
        if (g_pMessageShowPane != NULL)
            delete g_pMessageShowPane;

        return true;
    }

    unsigned int textLength = PacketBufferReadUInt16BE(packet + 2);
    memmove(multiByteText, packet + 4, textLength);

    if (textLength >= 0x8000)
        __report_rangecheckfailure();

    multiByteText[textLength] = '\0';

    unsigned int wideLength = (unsigned short)MultiByteToWideChar(
        CP_ACP,
        0,
        multiByteText,
        textLength,
        wideText,
        0x8000);

    if (wideLength >= 0x8000)
        __report_rangecheckfailure();

    wideText[wideLength] = L'\0';

    if (g_pMessageShowPane != NULL)
        g_pMessageShowPane->SetWrappedText(wideText);
    else
        new MessageShowPane(wideText);

    return true;
}
```

Implementation notes for this draft:

- `delete g_pMessageShowPane` must be understood as the virtual scalar deleting destructor call with flag `1`; the destructor/scalar wrapper clears the singleton.
- `new MessageShowPane(wideText)` corresponds to `operator new(0x10104)` then constructor `0x00521da0`. The constructor stores `g_pMessageShowPane`.
- The packet opcode `0x58` is not tested inside this helper because the caller dispatches only that case.
- If the project style avoids direct `__report_rangecheckfailure` in formal source, the implementation callback should document an equivalent compiler-generated range-check lowering. Do not silently turn these paths into ordinary returns because the binary fail-fast behavior is explicit.

## Historical Accepted Target Detail From Original Report

Target: `by-memory/0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket.md`

The original report recommended the following target facts. They are now already present in the current target page after prior implementation and supervisor validator command `000000006862`; this section preserves the accepted detail and is not a new edit request.

Metadata now present:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Already-present body details:

- Replace "LivingObjectPane server packet handler with MessageShowPane dependency" with "file-local/static local-player server-packet helper in the LivingObjectPane source neighborhood with MessageShowPane dependency".
- State that the function is not a `LivingObjectPane` instance method:
  - `ret 4` / one stack packet argument.
  - Caller seeds `ecx` at `0x005a816c`, but callee never uses it as `this`.
  - No `LivingObjectPane` fields are read or written.
- Add exact caller route:
  - `UserPane::OnServerMessage` case `0x58` calls `0x005ac070` at `0x005a8172`.
  - PE scan found one direct rel32 call and no VA/RVA pointer route.
- Add exact packet layout:
  - `payload[0] = 0x58` dispatcher opcode.
  - `payload[1]` show/update flag; zero closes the overlay.
  - `payload+2` big-endian 16-bit text byte length via `PacketBufferReadUInt16BE`.
  - `payload+4` narrow text bytes.
  - Server packet name table entry `0x00627b58` is `#88`, so `MessageShow` remains inferred/descriptive.
- Add exact behavior:
  - Close path: if `payload[1] == 0` and `g_pMessageShowPane` is non-null, call virtual scalar deleting destructor with delete flag `1`; return true.
  - Open/update path: copy byte-counted payload text into `char[0x8000]`, NUL-terminate, convert with `MultiByteToWideChar(CP_ACP, 0, ..., 0x8000)`, NUL-terminate `WCHAR[0x8000]`.
  - If `g_pMessageShowPane` is non-null, call `MessageShowPane::SetWrappedText`.
  - Else allocate `0x10104` bytes and construct `MessageShowPane(wideText)`.
  - Always returns `1` on non-range-fail paths.
- Add helper-name resolution:
  - `sub_575470` is a byte accessor/runtime char-traits helper; source should use `packet[1]`.
  - `sub_575480` is `PacketBufferReadUInt16BE`.
  - `sub_516220` is `memmove`.
  - `dword_69B4F4` is `g_pMessageShowPane`.
- Current target page already has the first-draft C++ above and the reasoning that the combined-score/emitter gate is satisfied after file-level reroute.
- Preserve historical B001 route as superseded:
  - Older B001 correctly found the live route and MessageShowPane dependency but treated the helper as a LivingObjectPane server-packet child at medium source-placement confidence. The no-`this` recheck refines that to `LivingObjectPane.cpp` file-local/static helper, not `LivingObjectPane` class method.

## Historical Accepted Support Detail From Original Report

The original report recommended the following support-doc sync. Current support docs checked during this callback already contain these facts at report-level detail, so this section is historical/already-present detail rather than a new B011 edit request.

### `by-file/LivingObjectPane.md`

- Add [UID:0003UU] to the local-player/server-packet helper content as a file-local/static helper, not a class instance method.
- Include the exact `case 0x58` route, payload layout, `g_pMessageShowPane` dependency, and first-draft source shape.
- State that `MessageShowPane` owns the overlay class/singleton/update methods, while `LivingObjectPane.cpp` owns this local-player packet helper by source locality.

### `by-class/LivingObjectPane.md`

- Replace any wording that implies [UID:0003UU] is an ordinary `LivingObjectPane` method.
- Keep it as a local-player packet-family helper/dependency in the class neighborhood, with a note that it has no `this` usage and should route through [UID:0000KU] if implemented.
- Preserve class-wide caveats for local-player packet-tail boundaries, but do not let those caveats block [UID:0003UU]'s source-bearing helper decision.

### `by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md`

- Update the child inventory row for [UID:0003UU] to say:
  - exact function `0x005ac070-0x005ac1a8`;
  - one caller at `0x005a8172`;
  - opcode `0x58`;
  - no `this` use;
  - file-level [UID:0000KU] route rather than class [UID:00007B].
- Keep [UID:0001KM] non-emitting split-index status.

### `by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md`

- Change the delegated-handler list entry for `0x005ac070` from "LivingObjectPane packet handler" to "local-player file-local `HandleMessageShowPacket` helper".
- Add that `case 0x58` is exact and directly calls the helper with the payload pointer.
- Do not inline the helper into the dispatcher C++ unless a future whole-dispatcher reconstruction chooses to inline all same-source helper bodies; the binary has a real call.

### `by-file/UserPane.md` / `by-class/UserPane.md`

- Add only a caller/dispatcher note if needed:
  - `UserPane::OnServerMessage` case `0x58` routes to the local-player message-show helper.
  - The helper itself does not use UserPane fields and should not be UserPane-owned solely from caller evidence.

### `by-file/MessageShowPane.md`

- Update the "Proposed Contents" row for `HandleMessageShowPacket`.
- Recommended wording: this packet helper is a local-player server-packet consumer of `MessageShowPane`, not a direct `MessageShowPane.cpp` source body under current evidence.
- Keep the behavior details as dependency evidence:
  - reads `g_pMessageShowPane`;
  - updates through `SetWrappedText`;
  - creates via `MessageShowPane(wideText)`;
  - closes through scalar deleting destructor.
- Preserve the broader `MessageShowPane.cpp` versus `MessageDialogs.cpp` caveat for the class/singleton file, but do not use that caveat to block [UID:0003UU]'s local-player packet helper source.

### `by-class/MessageShowPane.md`

- Keep [UID:0003UU] as the only direct caller for `SetWrappedText` and constructor consumer.
- Clarify that [UID:0003UU] is an external packet-handler helper, not a `MessageShowPane` method.

### `by-global/g_pMessageShowPane.md` and `by-memory/0x0069b4f4-0x0069b4f8.g_pMessageShowPane.md`

- Add/refine the [UID:0003UU] packet-handler consumer details:
  - close path reads at `0x005ac0bc`;
  - update/create path reads at `0x005ac13f`;
  - close uses virtual scalar deleting destructor with delete flag `1`;
  - update calls `MessageShowPane::SetWrappedText`;
  - create calls `MessageShowPane::MessageShowPane`.

### `by-memory/0x00522530-0x005226ea.MessageShowPaneSetWrappedText.md`

- Keep [UID:0003UU] as the only direct caller at `0x005ac150`.
- Update the caller description from generic packet handler to opcode `0x58` message-show packet helper.

### `by-memory/0x00625008-0x0062ce50.ServerPacketNameTable.md`

- Optional support update: add opcode `0x58` table observation if maintaining packet-name notes:
  - slot address `0x00627b58`, text `#88`;
  - semantic name not recovered, descriptive name inferred from handler.

## Historical Supervisor-Owned Coverage Text

`by-memory/-coverage-report.md` is supervisor/validator-owned and was not edited by B011. The earlier report supplied the following manual row text as historical supervisor-owned coverage guidance. Current command `000000006862` repaired UID mapping/reference state and reported `generated_refresh: deferred`; this row is not a current manual edit request from this repaired report.

```markdown
        - [UID:0003UU][0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket](by-memory/0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket.md) 0x005ac070-0x005ac1a8 | file-local server-packet helper | HandleMessageShowPacket : reconstructable : 88% : very strong : B011 2026-06-19 source-quality recheck: exact `0x138` modeled `__stdcall` helper with only rel32 caller `UserPane::OnServerMessage` case `0x58` at `0x005a8172`, no VA/RVA/pointer route, no `LivingObjectPane` `this` usage despite caller seeding `ecx`, packet layout `opcode 0x58`, `payload[1]` show/close flag, `payload+2` big-endian text byte count, `payload+4` encoded text, `GetMemoryMan`/`memmove` copy to `0x8000`-byte scratch, `CP_ACP` `MultiByteToWideChar` into `WCHAR[0x8000]`, existing `g_pMessageShowPane->SetWrappedText`, new `MessageShowPane` allocation size `0x10104`/constructor call, delete path through vtable scalar-deleting destructor flag `1`, eight-byte trailing padding before `0x005ac1b0`, and recommended file-level owner/emitter [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md) rather than [UID:00007B] class or [UID:0000LB] MessageShowPane; first-draft C++ ready as a local-player packet helper.
```

## Historical Validation Plan From Original Report

The original report listed the scoped validators that would be needed after by-* implementation. In the current repair pass, B011 did not edit by-* docs and did not run validators. Current validator state is instead the supervisor-run command `000000006862` recorded under `Validator Results`.

Historical implementation validation plan from the original report:

> Executable block R001 was removed from this report and preserved verbatim in [0003UU-LivingObjectPaneHandleMessageShowPacket-source-quality-removed.md](0003UU-LivingObjectPaneHandleMessageShowPacket-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the implementation changes only the target plus a smaller support subset, run the same scoped validator over each touched file. Because [UID:0003UU] owner/emitter metadata changes from class [UID:00007B] to file [UID:0000KU] and formal C++ becomes nonblank, also run the scoped autogen refresh/validation if the supervisor's implementation checklist requires generated output refresh:

> Executable block R002 was removed from this report and preserved verbatim in [0003UU-LivingObjectPaneHandleMessageShowPacket-source-quality-removed.md](0003UU-LivingObjectPaneHandleMessageShowPacket-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Do not edit `by-memory/-coverage-report.md`; apply the exact row above only through supervisor-owned coverage sync.

## Final Recommendation

- Current target/support docs already reflect the accepted recommendation: [UID:0003UU] is a source-bearing file-local/static `LivingObjectPane.cpp` packet helper, not a `LivingObjectPane` member, UserPane method, or MessageShowPane method.
- No by-* edit was required in this implementation/verification callback.
- Supervisor may proceed with the supervisor-only execution decision; `execute_report` remains supervisor-only.
- Future work outside this report: final original source linkage/spelling audit and broader packet-name recovery if independent packet metadata is found.

## Recommended Target Doc Changes

- Target path: `by-memory/0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket.md`.
- Already present after prior implementation and command `000000006862`: metadata `88/90`, owner/emitter `0000KU`, first-draft formal C++ body, exact route/callsite, no-`this` proof, packet layout, MessageShowPane lifecycle behavior, helper/global name resolution, boundary/padding notes, and rejected alternatives.
- No new target edit is proposed for this callback.

## Recommended Support Doc Changes

- Mandatory support sync from the original report is already present at report-level detail in `by-file/LivingObjectPane.md`, `by-class/LivingObjectPane.md`, `by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md`, `by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md`, `by-file/UserPane.md`, `by-class/UserPane.md`, `by-file/MessageShowPane.md`, `by-class/MessageShowPane.md`, `by-global/g_pMessageShowPane.md`, `by-memory/0x0069b4f4-0x0069b4f8.g_pMessageShowPane.md`, `by-memory/0x00522530-0x005226ea.MessageShowPaneSetWrappedText.md`, and `by-memory/0x00625008-0x0062ce50.ServerPacketNameTable.md`.
- No support doc edit is proposed for this callback.
- `by-memory/-coverage-report.md` and generated reports remain supervisor/validator-owned and were not edited.

## Score And Metadata Recommendation

- Historical pre-implementation target state was `85/86`, owner/emitter [UID:00007B], blank formal C++.
- Current target state is `88/90`, owner/emitter [UID:0000KU], reconstructable `TRUE`, and populated formal C++.
- The score is justified by current MCP proof of exact boundary, sole caller, helper behavior, packet layout, and owner/emitter route. It is not higher because exact original linkage/spelling and original packet symbolic name are not recovered, and the file-local placement remains an evidence-backed source inference rather than original source proof.
- Metadata recommendation is to keep the current target metadata unchanged.

## Open Questions With Attempted Resolution

- Original translation-unit spelling remains inferred. [UID:0000KU] is recommended over [UID:0000P1] because of address/source-family locality and over [UID:0000LB] because the function is a server-packet helper outside the MessageShowPane method cluster.
- Original packet symbolic name remains unrecovered. The table says `#88`, so `MessageShow` is descriptive, not a recovered source label.
- Original helper declaration style remains inferred: likely file-local `static bool HandleMessageShowPacket(const unsigned char *packet)` or similar. It should not be a non-static class method.
- Final C++ should keep the range-check fail-fast behavior. If later source-generation rules emit compiler range checks from local array indexing, the explicit `__report_rangecheckfailure` calls can be removed from human-facing source while preserving binary behavior.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- No manual coverage-report edit is requested in this active repair pass.
- Historical report text supplied a by-memory coverage row for supervisor-owned manual sync, but command `000000006862` repaired UID mapping/reference state and generated refresh is validator-owned/deferred. Do not edit `by-memory/-coverage-report.md` manually from this report.

## Follow-Up Actions

- Supervisor: after independent verification, run the appropriate report execution lifecycle command if the current artifact still matches execution policy.
- B011: no by-* implementation action is pending unless supervisor returns a concrete mismatch.
- Generated/coverage state: leave validator-owned generated refresh handling to supervisor/validator lifecycle.

## Confidence

- Recommendation confidence: high for current target owner/emitter/source-shape disposition.
- Score confidence: high for keeping `88/90`.
- Remaining uncertainty: original helper linkage/spelling and original symbolic packet name.

## Validator Results

- B011 did not run validators during this implementation/verification callback because no by-* docs were edited. B011 also did not run `execute_report` or any lifecycle/archive command.
- Supervisor-run command recorded for current state:
  - `command_id`: `000000006862`
  - `command_timestamp`: `2026-07-05T07:04:07-04:00`
  - command: `python .\tools\validator.py --mode file --file by-memory/0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket.md --apply --queue-timeout 240`
  - exit code: `0`
  - ok count: `1`
  - side effects: `path_update`, `completion_update 88`, `confidence_update 90`, `canonical_owner_update 0000KU`, autogen registry updates, reference index additions, projected stats update, `generated_refresh: deferred`.
- No current command-specific warnings were provided in the supervisor assignment; generated refresh remains validator-owned/deferred.

## Changed Files

- Modified in this callback: `source-3/project-documentation/tools/leaser/Agents/Agent-B011/research/0003UU-LivingObjectPaneHandleMessageShowPacket-source-quality.md`.
- Current by-* docs verified already-present but not edited in this callback: target [UID:0003UU] and support docs listed above.
- Leases used: none; report-only work in B011 research folder does not require a lease.
- Validators run by B011: none.
- Generated files edited: none.
- Coverage report edited: no.
- Report execution/lifecycle command run by B011: not run.

## Implementation Tracking Checklist

- [x] Removed the top-level `REPORT-VALIDATION-STATUS` / `REPORT-REVALIDATION-REASON` lines under the supervisor narrow override.
- [x] Preserved the validator-owned `VALIDATOR-REPORT-HISTORY` footer unchanged.
- [x] Historicalized `target_uid_unknown: 0003UU` and de-execution status in `Supporting Research`.
- [x] Added current MCP evidence from active session `supervisor_recovery_20260705`.
- [x] Recorded supervisor-run validator command `000000006862` with timestamp, command, exit code, ok count, side effects, and deferred generated refresh state.
- [x] Verified target doc current state: `88/90`, owner/emitter `0000KU`, reconstructable `TRUE`, formal C++ populated, and report-level facts already present.
- [x] Verified support docs already contain the prior B011 target/support details at current-state level.
- [x] Recorded claim-by-claim incorporation states as `already-present` or `applied`.
- [x] Supervisor Gate 1 passed at SHA256 `BFEC6E9A88E22BBE17D5E547691A04CAFB9D6909FDFA9A18E70649798FC9F79B`.
- [x] Completed callback claim-by-claim verification against target/support docs with no by-* mismatch found.
- [x] Skipped scoped validators because no by-* files were edited in this callback.
- [x] Confirmed no by-* docs, generated files, coverage reports, validator state, supervisor ledgers, lifecycle/archive files, or registry state were edited by B011 in this callback.
- [x] Confirmed no validator, `execute_report`, dry-run/probing execute variant, lifecycle/archive command, registry command, or manual report move was run by B011.
- [x] Ready for supervisor execute decision.
- [ ] Supervisor-only `execute_report` / lifecycle execution.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003UU","source_path":"executed-b-agent-research/B011/0003UU-LivingObjectPaneHandleMessageShowPacket-source-quality.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- {"agent":"B011","command_id":"000000006861","destination_path":"tools/leaser/Agents/Agent-B011/research/0003UU-LivingObjectPaneHandleMessageShowPacket-source-quality.md","details":"report returned to active agent research for rework","event":"de-executed-for-rework","source_path":"executed-b-agent-research/B011/0003UU-LivingObjectPaneHandleMessageShowPacket-source-quality.md","timestamp":"2026-07-05T07:03:50-04:00"} -->
<!-- {"agent":"B011","command_id":"000000006869","destination_path":"executed-b-agent-research/B011/0003UU-LivingObjectPaneHandleMessageShowPacket-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B011/research/0003UU-LivingObjectPaneHandleMessageShowPacket-source-quality.md","timestamp":"2026-07-05T07:25:04-04:00","uid":"0003UU"} -->
<!-- {"agent":"B011","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0003UU-LivingObjectPaneHandleMessageShowPacket-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B011/0003UU-LivingObjectPaneHandleMessageShowPacket-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0003UU"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
