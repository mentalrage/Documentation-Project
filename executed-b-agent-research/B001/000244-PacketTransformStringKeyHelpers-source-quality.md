** TARGET-REPORT-UID:000244 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID000244 PacketTransformStringKeyHelpers Ownership / Split Research


## Finalized Report / Current Recommendation
- Applied result: [UID:000244] is a `92/94` non-emitting two-child split index under semantic owner [UID:0000M9][PacketTransform](../../../../../by-file/PacketTransform.md). Validator-issued [UID:0004ME] and [UID:0004MF] own and emit the exact source bodies at positions `20` and `30`.
- Final disposition: [UID:0004ME] `0x00575b90-0x00575c30` is a complete retained source helper that initializes the nine-byte alternate key/table state from one MD5 hex digest despite having no recovered inbound route. [UID:0004MF] `0x00575c30-0x00575caa` is the live helper that builds a 1,024-character packet-transform key text from login-derived text.
- Callback completion: both children were created/registered serially, all six managed blocks were applied exactly, source-facing `g_processArgList` was replaced by `g_packetTransformKeyText` throughout the bounded current/formal set, every named support page was synchronized, and root order is globals/raw/live/nonce/handshake/XOR at `10/20/30/40/50/60`.
- Confidence: high for boundaries, bodies, ABI, caller, MD5/format/free behavior, global layout, split, and PacketTransform ownership; medium-high for the inferred source-facing helper and global spellings because no original symbols or source strings survive.
- Current callback state: implementation and B001 verification are complete. B001 did not manually edit generated/coverage/tracker/supervisor/validator-owned files and ran no `execute_report`, report lifecycle, move, or archive command. Exact report validation/execution/count/path/archive state remains external supervisor/validator-owned and is neither asserted nor directed by this artifact.

## Supporting Research
- MCP endpoint: `http://127.0.0.1:13337/mcp`, streamable JSON-RPC transport initialized with `Accept: application/json, text/event-stream`.
- Transport session used for this pass: `e538b66c-9e11-42d7-8f92-42d99659c90f`.
- IDB database argument used on every IDB-backed tool call: `supervisor_nexustk_20260713`.
- Final evidence-time health check: JSON-RPC call `27`, `idb_list`, ran at `2026-07-13T13:43:27-04:00` and returned one active/adopted session, worker PID `2236`, `is_analyzing:false`. Call `28`, `server_health`, returned `status:"ok"` with auto-analysis, Hex-Rays, and strings cache ready. Call `29`, `lookup_funcs`, reconfirmed raw `0x00575b90` as not a function, modeled `sub_575C30` size `0x7a`, `sub_515290` size `0x7a`, and `sub_443A00` size `0x2e`.
- Earlier current-pass calls `5-26` supplied the target disassembly, decompilation, caller slice, xrefs, helper analyses, entity search, boundary bytes, signature search, and liveness negatives detailed below. No IDA mutation tool was called.
- Read-only PE supplement: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, SHA-256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`. This supplement corroborates the healthy live MCP evidence; it is not outage fallback.

### Historical report-search provenance

The following exact case-insensitive term set was checked before treating UID000244 as uncovered: `UID000244`, bare `000244`, `PacketTransformStringKeyHelpers`, `0x00575b90`, `0x00575c30`, historical/generated `sub_575C30`, `ArgList`, and `g_processArgList`, and owner/source-family `PacketTransform` and `Socket`. The active B-report root was searched independently from the central executed, research-time archive, legacy Older-Research, and SpecialReports roots; the broader `tools/leaser/Agents/**` search was used only to find adjacent assignment/notes evidence and was not substituted for those roots.

| Search root | Markdown files checked | Per-term matching-file counts in the term order above | Root disposition |
| --- | ---: | --- | --- |
| Active B reports: `tools/leaser/Agents/Agent-B*/research/**` | 12 | `1, 1, 1, 1, 1, 1, 1, 1, 1, 1` | Every hit is this report itself. No other active B report covers the target, address pair, historical names, or source family. |
| Central executed B reports: `executed-b-agent-research/**` | 2,142 | `0, 8, 0, 7, 2, 3, 20, 6, 15, 259` | Exact-address and historical-name hits were opened below. Broad `PacketTransform`, `Socket`, and `ArgList` hits were narrowed by target/address/name co-occurrence and source context; direct dependencies and incidental family mentions are classified separately below. |
| Research-time archive root: `archived/**` | 0 | `0, 0, 0, 0, 0, 0, 0, 0, 0, 0` | At the recorded search time the root contained no Markdown reports, so that search found no direct or incidental target coverage. This is historical search evidence, not an assertion about later archive state. |
| Legacy research: `tools/leaser/Agents/Older-Research/**` | 3 | `0, 0, 0, 0, 0, 0, 0, 0, 0, 0` | The B011 GrafPort/JsonCpp and B014 ScrollCollectionPane reports contain none of the required terms and are unrelated to this target. |
| Special reports: `tools/leaser/Agents/SpecialReports/**` | 5 | `0, 0, 0, 0, 0, 0, 0, 0, 0, 0` | The third-party inventory and four UID0004CC benchmark reports contain none of the required terms and are unrelated to this target. |

Relevant matching paths were opened and classified as follows:

| Search root / terms | Matching paths opened or classified | Result |
| --- | --- | --- |
| Active assignment/notes context under `tools/leaser/Agents/**` using target UID/address/name terms | `Agent-B001/goal.md`; `Agent-A001/notes.md`; this report | The goal is this assignment. A001 notes contain direct 2026-06-16 support research and the old blank-C++ blocker, but they are notes rather than a dedicated B report. This report is the only active B-report hit and cannot serve as prior coverage for itself. |
| Central executed: target/address/name terms | `B001/0001I5-XorTransformBuffer-source-quality.md`; `B001/0001HZ-packetbuffer-helpers-source-quality.md`; `B004/000286-PacketTransformAlternateSizeAndLut-source-quality.md`; `B011/0001I0-PacketNonceInitialization-source-quality.md`; `B013/0002AL-PacketTransformMutableState-source-quality.md`; `B012/0001I2-BuildHandshakeBlock-source-quality.md`; `B003/0001HS-socket-lifecycle-source-quality.md`; `B012/000243-PacketBufferLengthPrefixedReadHelpers-source-quality.md` | Dependency, sibling, lifecycle, or physical-adjacency evidence only. These reports respectively leave the raw helper unresolved, separate PacketBuffer ownership, decode alternate-size/table support, preserve the old aggregate caveat, establish mutable storage, cover handshake/nonce/XOR/Socket dependencies, or prove predecessor padding. None resolves the exact two-body target's liveness, split, names, scores, and complete C++. |
| Central executed: `sub_575C30` / formatter adjacency | `B001/00026H-server-packet-name-table-source-routing.md` | Incidental literal-adjacency evidence only. It identifies `%s%s` at `0x0062ce70` as referenced by `sub_575C30` and explicitly places it outside UID00026H; it does not research UID000244. |
| Central executed: `ArgList` / `g_processArgList` / `Socket` | `B006/0000DD-Socket-class-source-quality.md`; `B007/0000NS-Socket-empty-emitter-family-source-quality.md`; `B003/0001HS-socket-lifecycle-source-quality.md`; `B011/0001I0-PacketNonceInitialization-source-quality.md`; `B001/0001I5-XorTransformBuffer-source-quality.md`; `B013/0002AL-PacketTransformMutableState-source-quality.md` | Historical/support evidence only. The Socket class/family reports preserve the stale `g_processArgList` declaration and allocation/free lifecycle; the other four establish target-adjacent writer/consumer/storage facts. They support this report's rename and historicalization but do not constitute direct target coverage. The other 14 `ArgList` hits are unrelated image, UI, error, formatting, or container contexts. |
| Central executed: all 15 `PacketTransform` matches | The eight direct dependency/support reports above; `B001/00026H-server-packet-name-table-source-routing.md`; `B006/0000DD-Socket-class-source-quality.md`; `B007/0000NS-Socket-empty-emitter-family-source-quality.md`; `B007/0001B7-Md5BytesHex-source-quality.md`; `B001/000237-MD5EndianEncodeDecodeHelpers-source-quality.md`; `B005/0001B8-Md5FilePathHex-source-quality.md`; `B009/0002ZW-OldSystemMessagePaneResourcePointerTable-source-quality.md` | The MD5 reports reject PacketTransform/Socket ownership for separate MD5 utility bodies while retaining packet code as a consumer; the OldSystemMessagePane report names only a generated PacketTransform.cpp side effect. Together with the direct support group, these are source-family, dependency, or incidental mentions, not a dedicated UID000244 report. |
| Central executed: broad `Socket` | 259 matching reports, narrowed to the Socket/PacketTransform paths above by target address/name/history co-occurrence and contextual inspection | The retained paths provide lifecycle/owner support. Remaining matches concern generic transport calls, packet senders, errors, dialogs, or unrelated Socket members and do not mention the exact target UID/name/address pair as coverage. |
| Central executed: bare `000244` | UID000245, UID000354, UID0002QR, UID0000HT, UID0000N4, UID0003NZ, UID0000MN reports plus `B003/0001HS-socket-lifecycle-source-quality.md` | Seven hits are command IDs or incidental numeric text and were rejected by path/title/context. The B003 lifecycle report is support evidence already classified above. |
| `archived/**`, `Older-Research/**`, and `SpecialReports/**` | no relevant matches | The explicit per-root searches above found no direct target report, generated-name predecessor, owner-family report, or incidental dependency requiring a technical recommendation change. |

Research-time conclusion: the recorded active B research, central executed research, archive, `Older-Research/**`, and `SpecialReports/**` searches found no dedicated prior B report for UID000244 or the exact half-open range `[0x00575b90,0x00575caa)`. All opened matches were support, historical-name, adjacency, dependency, or incidental family evidence. This provenance does not assert later lifecycle/archive state and does not change the accepted split, scores, source route, rename, or formal C++ conclusions.

## Target
- Target UID: `000244`.
- Target path: `by-memory/0x00575b90-0x00575caa.PacketTransformStringKeyHelpers.md`.
- Historical source-selection row: `auto-generated/-ag-research-tracker.md`, by-memory `Not-Covered Files - Reconstructable`, score `86/90`, with report count `0` at research selection time only.
- Accepted callback classification: supervisor Gate 1 passed exact report SHA256 `09E8B23D70682F3723283EF5853801B3137D5FA66943742544E845599951EF56`; this same report then received the bounded implementation callback.
- Applied parent state: `92/94`, `CANONICAL_OWNER:0000M9`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank position, exact blank formal C++, `Nested:2`, and exact children UID0004ME/UID0004MF in address order.

## Current Target State
- Current metadata treats the physical two-function range as a non-emitting split index; exact source-bearing children own each complete function.
- Current body evidence records boundaries, the one live caller, four table-window copies, surrounding padding, the absence of a raw-start route, and the unique raw body.
- Historical helper semantics were stale in two material ways and are now explicitly superseded:
  - `sub_515290` is described as a duplicate-string helper. Current IDA and MD5 docs prove it is `Md5StringHex`, returning a heap-allocated 32-character lowercase MD5 hex string.
  - The live loop is described as concatenating the current string with a duplicate of itself. It actually appends `Md5StringHex(currentKeyText)` once per iteration.
- `ArgList` / `g_processArgList` is retained only as historical IDA/generated provenance. Current bounded formal/source-facing documentation uses `g_packetTransformKeyText` for the 1,025-byte allocation containing exactly 1,024 transform-key characters plus terminator and consumed modulo 1,024.
- Parent C++ is blank only as an exact no-duplicate split index. Both child bodies, helper contracts, storage, and source route are applied and generated.
- Raw liveness is resolved as a retained source helper with no recovered inbound route, not padding, compiler glue, or a reason to suppress its body.
- Related current docs checked: PacketTransform file/item/global pages, mutable and initialized global ranges, Socket lifecycle, nonce initialization, handshake block, XOR transform, InitializeMainUiGraph, MD5 file/aggregate, MemoryMan accessor/memmove wrapper, adjacent PacketBuffer helper, ignored padding, generated PacketTransform/Socket output, tracker, and executed reports listed above.
- Current B001 work state: all accepted callback work, scoped validation, waited generation, and generated checks are complete; no B001 work remains. B001 ran validators only as authorized, and ran no `execute_report`, report lifecycle, move, or archive operation. Artifact path/count/lifecycle state is external supervisor/validator-owned.

## Executive Recommendation
- Applied direct owner/source file: [UID:0000M9][PacketTransform](../../../../../by-file/PacketTransform.md), reconstruction path `NexusTK/network/PacketTransform.cpp`.
- Applied children: [UID:0004ME] `InitializePacketTransformAlternateKey` is `91/92` at position `20`; [UID:0004MF] `BuildPacketTransformKeyText` is `92/94` at position `30`; both are UID0000M9-owned/emitted and reconstructable.
- Applied parent: UID000244 is `92/94`, `RECONSTRUCTABLE:FALSE`, blank-emitter, blank-position, blank-C++, `Nested:2`, with exact address-ordered `[[CHILDREN]]` links.
- Applied global disposition: preserved `g_packetXorAlternateSize`, `g_packetNonceScratch`, and `g_packetXorTableAlternate`; replaced only stale current use of `g_processArgList` with `g_packetTransformKeyText` throughout the bounded formal/support set.
- Applied order: [UID:0000TG] root position `10`; initialized/mutable declaration children `10/20`; raw/live/nonce/handshake/XOR functions `20/30/40/50/60`. Generated declarations precede all function bodies.
- No remaining target blocker requires deferral. Exact original spellings and original private-`Socket.cpp` versus separate-file layout remain confidence caps only.

## Supervisor Active Recheck
- Supervisor Gate 1 accepted exact SHA256 `09E8B23D70682F3723283EF5853801B3137D5FA66943742544E845599951EF56` and authorized C244-001 through C244-044 implementation on this same report.
- Split registration was serialized: validator command `000000010058` issued UID0004ME first; command `000000010061` issued UID0004MF second; only then were parent/support links applied.
- Every accepted destination and managed block is applied below with command-level proof. B001 performed no report lifecycle action.

## Inference Research Guidance Check
- `by-structure.md` requires singular source-bearing functions to carry their own reconstruction metadata and requires real registered UIDs before links. That makes a two-child split preferable to aggregate emission.
- Existing documentation names and generated aliases were treated as hypotheses. IDA names `sub_575C30`, `Size`, `ArgList`, and `unk_*` were not accepted as final source names.
- Direct IDA fact: instruction bytes, function sizes, xrefs, calls, globals, strings, return forms, and caller slice.
- Documentation evidence: accepted source-facing APIs such as `Md5StringHex`, `GetMemoryMan`, `MemoryMan::MemmoveWrapper`, PacketTransform globals, and Socket lifetime.
- Inference: exact helper names, `g_packetTransformKeyText`, and separate `PacketTransform.cpp` source placement. These are marked inferred/descriptive rather than original-symbol proof.
- Wave2/Wave3 material encountered through project searches was treated as stale historical lead only. No Wave2/Wave3 generated name or prototype overrides the evidence-time MCP results, callback-current by-* docs, or executed B research.

## Heuristic / Inference Reanalysis And Validation

| Issue | Current reanalysis | Evidence and classification | Disposition |
| --- | --- | --- | --- |
| Aggregate shape | The range contains two complete adjacent functions, not one function. | Raw disassembly, modeled function metadata, independent returns; direct IDA fact. | Split into exact children; parent becomes an index. |
| Raw function modeling | IDA still lacks a function object at `0x00575b90`, but all 160 bytes decode as one stack-frame helper ending `retn 4`. | Calls `GetMemoryMan`, `Md5StringHex`, five `MemmoveWrapper` sites, and `free`; direct IDA fact. | Source-bearing child, not ignored bytes. |
| Raw liveness | No start route or interior-entry route was recovered. | MCP start/interior xrefs, PE control-flow scan, pointer-value scan; direct negative evidence. | Retained unrouted source; confidence cap, not no-code. |
| `sub_515290` role | It hashes a NUL-terminated ANSI string and returns heap MD5 hex text. It is not `_strdup`. | Current `analyze_function 0x00515290`, current MD5 docs, five xrefs; direct fact plus accepted naming. | Call `Md5StringHex`; free each returned buffer. |
| Raw alternate-key behavior | One MD5 hex digest is truncated to the current nine-byte alternate length, copied into scratch, then replicated into four nine-byte windows. | Exact instruction stream and global values; direct fact. | Name `InitializePacketTransformAlternateKey`. |
| Live helper initial value | It computes `MD5(MD5(loginText))`, not two generic duplicates. | Three static `Md5StringHex` call sites in the live function; direct fact. | Initial key text is the second digest. |
| Live expansion | Each of 31 iterations appends the 32-character MD5 hex digest of the entire current key text. | Decompile/disassembly at `0x575c71-0x575ca2`; direct fact. | Final length is `32 + 31 * 32 = 1024`. |
| Formatter | `sub_443A00` is the local secure variadic formatter over `__stdio_common_vsprintf_s`. | Current analysis, size `0x2e`, 54 callers; direct fact. | Source-facing `sprintf_s(buffer, 1025, ...)`. |
| Overlapping source/destination | The loop passes the same global pointer as destination and first `%s` source, plus the new digest as second source. | Exact push order at `0x575c7c-0x575c91`; direct fact. | Preserve this observable source shape; do not silently replace with `strcat_s`. |
| Temporary lifetime | Raw frees one MD5 string. Live frees both initial digest strings and one loop digest each iteration. | `j___free_base` calls at raw `0x575c22` and live `0x575c5e`, `0x575c64`, `0x575c97`; direct fact. | Use `free` exactly; do not route these `_strdup` results through MemoryMan. |
| Global pointer name | `ArgList` does not describe the produced/consumed data. | 1,025-byte Socket allocation, 1,024-character producer, nonce-only consumer; strongest semantic inference. | Rename to `g_packetTransformKeyText`. |
| Other global names | Existing length, scratch, and alternate-table names accurately express current behavior despite being inferred. | Multiple accepted current docs and direct xrefs. | Keep; document original-spelling uncertainty. |
| Owner | Both bodies mutate PacketTransform globals and depend on MD5/MemoryMan as utilities. | Global xrefs, sibling functions, generated route; direct evidence plus source-placement inference. | PacketTransform owns; MD5/MemoryMan/Socket are dependencies or consumers. |
| Compiler scaffolding | Both functions have ordinary frame/register-save/return code and no SEH, cookie, RTTI, vtable, EH cleanup, range-check, delete wrapper, or adjustor behavior. | Full disassembly and entity analysis; direct negative evidence. | Emit ordinary free functions. |
| Padding | Four `0xcc` bytes precede the raw helper and six `0xcc` bytes follow the live helper. No internal gap separates the two functions. | `get_bytes` and existing `-ignored.md`; direct fact. | Preserve existing ignored rows; no new ignored span. |
| Generated output | Waited command `000000010108` emits both exact children once and contains no UID000244 row/marker, aggregate duplicate, or stale global token. | Generated `PacketTransform.cpp` count/order assertions below. | Applied and independently verified. |

Rejected alternatives:
- Keep aggregate source-emitting: rejected because two independently callable functions need separate metadata, scores, names, histories, and route evidence.
- Keep aggregate blank: rejected because both exact bodies are source-ready and the raw no-route condition is a liveness cap, as accepted raw MD5 helper precedents demonstrate.
- Mark raw helper dead/non-reconstructable: rejected because it is unique, complete, calls project helpers, writes live transform globals, has a normal source ABI, and is not compiler-generated.
- Put helpers under PacketBuffer: rejected because no packet cursor or scalar serialization state is touched.
- Put helpers under Socket: rejected because Socket only allocates/frees the key-text buffer and the live MainUiGraph path calls the helper as a free function.
- Put helpers under MD5: rejected because MD5 is a utility dependency; transform globals and final purpose remain PacketTransform-owned.
- Keep `PacketTransform_ExpandProcessArgKeyText`: rejected as awkward generated-style naming and because the value is packet key text, not a process argument list.
- Rename the scratch/length/table globals speculatively: rejected because current accepted names are already accurate enough and broader churn would not add source certainty.
- Replace overlapping `sprintf_s` with a cleaner append API: rejected because it would no longer represent the observed call graph or argument order.

## Evidence Standards Used
- Live IDA MCP: `idb_list`, `server_health`, `lookup_funcs`, `get_bytes`, `insn_query`, `decompile`, `disasm`, `xrefs_to`, `analyze_function`, `callees`, `find_bytes`, and `entity_query`.
- Binary context: complete raw-body decode, modeled caller slice, global xrefs, imported/runtime helper behavior, section layout, and adjacent boundaries.
- Read-only PE supplement: exact body uniqueness, direct rel32 call/jump/conditional-branch destinations, and absolute-VA/RVA/raw-offset values into the full raw range.
- Documentation: current target/support pages, `by-structure.md`, validator emitter-order rules, generated PacketTransform/Socket files, tracker, A001 notes, and executed B reports.
- Negative evidence was used to cap confidence and classify the raw body as retained/unrouted. It was not misused to erase a complete source-authored body.
- Evidence ladder: direct bytes/body/caller/global facts outrank historical prose; current accepted helper names and owner routes inform source presentation; names without original symbols remain explicit inference.

## Evidence Checked
- JSON-RPC call `8`: 49-instruction full raw decode over `0x00575b90-0x00575c30`.
- Calls `9`, `10`, `12`, `13`: live helper decompile, 40-instruction disassembly, prototype/body analysis, and callee inventory.
- Call `11`: target/global xrefs for both starts, alternate size, scratch, key-text pointer, and alternate table.
- Call `14`: caller slice `0x004f84f0-0x004f8560`, including `WideCharToMultiByte` and the call at `0x004f8544`.
- Calls `17`, `24`, `25`: `Md5StringHex` body/prototype and five exact call sites.
- Calls `19`, `26`: formatter body/prototype, proving secure `vsprintf_s` semantics.
- Calls `16`, `23`: all 49 raw instruction starts checked. After excluding ordinary linear fallthrough, zero external or non-fallthrough xrefs enter the raw interior.
- Call `20`: unique 32-byte raw prologue signature at `0x00575b90`; zero exact `90 5B 57 00` absolute-VA or `90 5B 17 00` RVA pattern hits.
- Call `21`: only `sub_575C30` and successor `sub_575CB0` are modeled in the neighborhood; no current PacketTransform/StringKey/ProcessArg names survive.
- Call `22`: boundary bytes prove four `0xcc` bytes at `0x00575b8c-0x00575b90`, exact raw/live adjacency, and six `0xcc` bytes at `0x00575caa-0x00575cb0`.
- PE scan: `.text` target raw offsets `0x00174f90-0x00175030`; full 160-byte body SHA-256 `AF4B0534FC9880313FA31FE479DD1E9AD5043561B2DBFA367C3852CC625E9990`; exactly one full-body match; zero rel32 call/jump/Jcc destinations into the raw range; zero absolute-VA, RVA, or raw-offset dword values into any byte of the raw range.
- Numeric checks with `tools/int_convert.py`: `0xa0 = 160`, `0x7a = 122`, `0x401 = 1025`, `0x1f = 31`, `0x20 = 32`, `0x400 = 1024`, `0x9 = 9`, `0x30 = 48`, and `0x0c = 12`. One initial shell-bundled invocation and one undersized `0xa0` conversion failed; values were rerun individually, with `0xa0` using size two, and all listed conversions succeeded.
- Historical report search: the complete exact term set, five required root paths, per-term matching-file counts, opened paths, and direct-versus-support/incidental classifications are recorded under `Supporting Research` -> `Historical report-search provenance`. This explicitly includes `Older-Research/**`, `SpecialReports/**`, `sub_575C30`, `ArgList`, `g_processArgList`, `PacketTransform`, and `Socket` rather than relying on the broad active-agent search.
- No mandatory check was unavailable. No IDA mutation or validator was attempted.

## Claim And Incorporation Ledger
| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C244-001 | Current evidence came from healthy database `supervisor_nexustk_20260713`; final health calls 27-29 succeeded. | High | `idb_list`, `server_health`, `lookup_funcs` at `2026-07-13T13:43:27-04:00` | Target evidence/history; support evidence notes | incorporate | applied |
| C244-002 | The recorded active B research, central executed research, research-time archive, `Older-Research/**`, and `SpecialReports/**` searches found no dedicated prior report for UID000244 or `[0x00575b90,0x00575caa)`; all relevant matches were classified as support, adjacency, dependency, historical, or incidental evidence. | High | Exact term set, per-root matching-file matrix, and opened-path classifications under Supporting Research | Target status/history; report search provenance | incorporate | already-present |
| C244-003 | UID000244 contains two functions and must become a split index. | High | Complete disassemblies and independent returns | UID000244 metadata/body/children | incorporate | applied |
| C244-004 | Parent metadata becomes `92/94`, owner UID0000M9, reconstructable false, blank emitter/position/C++, `Nested:2`. | High | Split rules and exact child readiness | UID000244 header/summary/status | incorporate | applied |
| C244-005 | Create child `0x00575b90-0x00575c30.InitializePacketTransformAlternateKey.md` serially and use its real validator UID. | High | Exact raw boundary/body | New raw child | incorporate | applied |
| C244-006 | Create child `0x00575c30-0x00575caa.BuildPacketTransformKeyText.md` only after the first registration and use its real validator UID. | High | Exact modeled boundary/body | New live child | incorporate | applied |
| C244-007 | Raw child is a 160-byte, 49-instruction, one-argument void helper ending `retn 4`. | High | Calls 8, 22, 29; int conversion | New raw child behavior/evidence | incorporate | applied |
| C244-008 | Raw child obtains MemoryMan first, then calls `Md5StringHex(keyText)`. | High | Instructions `0x575b95-0x575ba7`; call 24 | New raw child behavior/C++ | incorporate | applied |
| C244-009 | Raw child copies exactly `g_packetXorAlternateSize` bytes, currently 9, from the digest into scratch. | High | Instructions and `0x0066fe50 = 9` | Raw child; UID000286; globals | incorporate | applied |
| C244-010 | Raw child replicates scratch into four windows at offsets `0`, `size`, `2*size`, `3*size`. | High | Four `sub_516220` calls and addresses | Raw child; mutable/global support | incorporate | applied |
| C244-011 | Raw child frees the MD5 heap string with CRT `free`, not MemoryMan. | High | `j___free_base` at `0x575c22`; MD5 `_strdup` provenance | Raw child behavior/C++ | incorporate | applied |
| C244-012 | Raw child has no EH, cookie, vtable, RTTI, adjustor, delete, or range-check scaffold. | High | Full body/callee inventory | Raw child negative evidence | incorporate | applied |
| C244-013 | Raw start has zero inbound IDA xrefs. | High | Calls 11 and 23 | Raw child liveness/negative evidence | incorporate | applied |
| C244-014 | No external/non-fallthrough xref enters any of the 49 raw instruction starts. | High | Calls 16 and 23 | Raw child liveness/negative evidence | incorporate | applied |
| C244-015 | PE has no direct call/jump/Jcc destination into any byte of the raw range. | High | Read-only PE scan | Raw child liveness/negative evidence | incorporate | applied |
| C244-016 | PE has no absolute-VA, RVA, or raw-offset value into any byte of the raw range. | High | Read-only PE scan; call 20 controls | Raw child liveness/negative evidence | incorporate | applied |
| C244-017 | The complete raw body occurs exactly once. | High | Full-body SHA/signature scan | Raw child uniqueness evidence | incorporate | applied |
| C244-018 | Raw child remains reconstructable/emitting retained source despite no recovered route. | Medium-high | Complete project body, live globals, accepted raw-helper precedent | Raw child disposition/metadata | incorporate | applied |
| C244-019 | Raw source-facing name is `InitializePacketTransformAlternateKey(char *keyText)`. | Medium-high | Exact semantic role; absent original symbols | Raw child title/C++/prose | incorporate | applied |
| C244-020 | Live child is `sub_575C30`, 122 bytes, 40 instructions, `void __stdcall(char *)`, one caller. | High | Calls 6, 9, 10, 12, 29 | Live child evidence/metadata | incorporate | applied |
| C244-021 | Caller at `0x004f8544` follows CP_ACP `WideCharToMultiByte` into a 128-byte local buffer. | High | Call 14 | Live child caller/source context; UID00019K | incorporate | applied |
| C244-022 | Live child computes `firstDigest = Md5StringHex(keyText)` then `secondDigest = Md5StringHex(firstDigest)`. | High | Calls at `0x575c38`, `0x575c40` | Live child behavior/C++ | incorporate | applied |
| C244-023 | Initial write is bounded `sprintf_s(..., 1025, "%s", secondDigest)`. | High | Formatter analysis and disassembly | Live child behavior/C++ | incorporate | applied |
| C244-024 | Both initial digest buffers are freed immediately after the bounded write. | High | Calls at `0x575c5e`, `0x575c64` | Live child lifecycle/C++ | incorporate | applied |
| C244-025 | Loop executes exactly 31 times. | High | `mov edi, 0x1f`, decrement/JNZ | Live child behavior/C++ | incorporate | applied |
| C244-026 | Each loop iteration hashes the entire current key text and appends the 32-character digest via `"%s%s"`. | High | `0x575c71-0x575c97`, MD5 contract | Live child behavior/C++ | incorporate | applied |
| C244-027 | Final key text is exactly 1,024 characters plus terminator in a 1,025-byte allocation. | High | `32 + 31*32`; Socket allocation `0x401` | Live child; mutable state; Socket lifecycle | incorporate | applied |
| C244-028 | Live helper source-facing name is `BuildPacketTransformKeyText(char *keyText)`. | Medium-high | Producer/consumer semantics and no original symbol | Live child title/C++; UID00019K | incorporate | applied |
| C244-029 | Rename source-facing `g_processArgList` to `g_packetTransformKeyText`. | High semantic / medium original-name | Exact producer, lifetime, and nonce consumer graph | UID0002AL, UID0001I0, UID0001HS, file/item/global/support prose | reject-stale | applied |
| C244-030 | Preserve `g_packetXorAlternateSize`, `g_packetNonceScratch`, and `g_packetXorTableAlternate`. | Medium-high | Existing accepted definitions remain behaviorally accurate | Global/mutable/initialized pages | already-present | already-present |
| C244-031 | PacketTransform remains canonical owner/emitter; Socket, MD5, and MemoryMan remain dependency/context owners only. | High | Global writes, utility calls, caller/lifetime split | Parent/children/file/item/global | incorporate | applied |
| C244-032 | Root emitter order becomes globals `10`, raw helper `20`, live helper `30`, nonce `40`, handshake `50`, XOR `60`. | High | Validator position semantics and dependency order | UID0000TG, new children, UID0001I0/I2/I5 | incorporate | applied |
| C244-033 | Internal global declaration order becomes initialized state `10`, mutable state `20`. | High | Declarations and dependency order | UID000286 and UID0002AL metadata | incorporate | applied |
| C244-034 | Six destination-specific managed blocks in this report are the exact callback shapes. | High | Binding rule and current blocks | Parent, two children, UID0002AL, UID0001I0, UID0001HS | incorporate | applied |
| C244-035 | `sub_443A00` is represented as `sprintf_s`, not a raw helper or generic copy. | High | Call 26 | Live child C++/evidence | incorporate | applied |
| C244-036 | `sub_516220` remains `MemoryMan::MemmoveWrapper` in the raw helper. | High | Current accepted UID0001BH and raw ECX route | Raw child C++/evidence | already-present | already-present |
| C244-037 | `Md5StringHex` remains MD5-owned and is only a dependency of these helpers. | High | Current MD5 docs and call graph | MD5 file/aggregate support | incorporate | applied |
| C244-038 | Existing ignored rows for `0x00575b8c-0x00575b90` and `0x00575caa-0x00575cb0` remain sufficient. | High | Call 22; current `-ignored.md` | `by-memory/-ignored.md` inspection only | already-present | already-present |
| C244-039 | Historical duplicate-string/self-duplication and aggregate-blank claims must remain only as superseded history. | High | Current helper analyses contradict them | Target/file/item/global changes | historicalize | applied |
| C244-040 | Generated PacketTransform must contain both child bodies once, declarations first, no parent empty marker, and no stale global token. | High | Applied routing and generated state | Final waited generated verification | incorporate | applied |
| C244-041 | Generated Socket must use only `g_packetTransformKeyText` for allocation/free/nulling. | High | Formal Socket block rename | Final waited generated verification | incorporate | applied |
| C244-042 | Manual coverage reports remain supervisor-owned; current stale/absent affected rows require exact replacement/addition text, which this report supplies without B001 editing coverage/generated/tracker/supervisor/validator state. | High | Read-only inspection of all fifteen affected manual coverage destinations after callback | Exact Manual Supervisor-Owned Coverage Or Tracker Text; callback boundary | incorporate | applied |
| C244-043 | No IDA rename/type/comment mutation is required for source reconstruction. | High | Source-facing docs can preserve inferred names without DB mutation | IDA recommendation/boundary | not-applicable | excluded-with-reason |
| C244-044 | Report-only phase runs no validators or lifecycle commands. | High | Assignment boundary | Validator Results / Changed Files | not-applicable | already-present |

### Callback Verification Notes

| Claim ID | Detailed callback proof |
| --- | --- |
| C244-001 | The evidence-time MCP/database provenance remains intact in this report and in the two child evidence sections; callback introduced no new binary uncertainty and did not mutate IDA. |
| C244-002 | The accepted active/executed/archive/Older-Research/SpecialReports term matrix and opened-path classifications remain unchanged in `Supporting Research`; implementation did not discover conflicting prior coverage. |
| C244-003 | UID000244 now has `RECONSTRUCTABLE:FALSE`, blank emitter/position/C++, `Nested:2`, and exact UID0004ME/UID0004MF child links in address order. |
| C244-004 | Parent validator `000000010068` returned exit `0`, `ok:1` for applied `92/94`, semantic owner UID0000M9, blank emission fields/block, and `Nested:2`. |
| C244-005 | Validator `000000010058` registered `by-memory/0x00575b90-0x00575c30.InitializePacketTransformAlternateKey.md` and issued real UID0004ME before any parent/support link used it. |
| C244-006 | Only after UID0004ME registration, validator `000000010061` registered `by-memory/0x00575c30-0x00575caa.BuildPacketTransformKeyText.md` and issued real UID0004MF. |
| C244-007 | UID0004ME records the exact 160-byte/49-instruction/retn-4 evidence and one-argument `void` source ABI; command `000000010058` validated the page. |
| C244-008 | UID0004ME behavior and exact managed block obtain `MemoryMan *memoryMan = GetMemoryMan()` before `Md5StringHex(keyText)`. |
| C244-009 | UID0004ME and UID000286 record five independent size reads, current value nine, and the digest-to-scratch copy; UID000286 validated under `000000010081`. |
| C244-010 | UID0004ME preserves all four offset windows `0`, `size`, `2*size`, and `3*size`; global/mutable pages synchronize the same layout. |
| C244-011 | UID0004ME exact block ends with direct `free(digest)` and documents `_strdup`/CRT ownership rather than MemoryMan release. |
| C244-012 | UID0004ME retains complete no-EH/cookie/vtable/RTTI/adjustor/delete/range-check negative evidence and ordinary-free-function disposition. |
| C244-013 | UID0004ME records zero raw-start IDA xrefs with evidence-time MCP call references. |
| C244-014 | UID0004ME records all 49 instruction starts checked and zero external/non-fallthrough interior entries. |
| C244-015 | UID0004ME preserves the PE direct-call/jump/Jcc negative scan over every byte of the raw range. |
| C244-016 | UID0004ME preserves zero absolute-VA/RVA/raw-offset pointer-value hits into the raw range. |
| C244-017 | UID0004ME preserves full-body SHA256 `AF4B0534FC9880313FA31FE479DD1E9AD5043561B2DBFA367C3852CC625E9990` and exactly one body match. |
| C244-018 | UID0004ME is `RECONSTRUCTABLE:TRUE`, owned/emitted by UID0000M9 at position `20`; generated output contains the body once despite the retained no-route cap. |
| C244-019 | UID0004ME title, summary, prose, and exact block consistently use `InitializePacketTransformAlternateKey(char *keyText)`. |
| C244-020 | UID0004MF records `sub_575C30`, 122 bytes, 40 instructions, one caller, and one-argument void ABI; validator `000000010061` returned exit `0`. |
| C244-021 | UID0004MF and UID00019K record the `0x004f8544` call after `WideCharToMultiByte(CP_ACP, ...)` into a 128-byte local; UID00019K validator `000000010092` returned `ok:1`. |
| C244-022 | UID0004MF exact block has first and second `Md5StringHex` calls in observed order; generated lines 121-122 contain each once. |
| C244-023 | UID0004MF exact block and generated line 124 use bounded `sprintf_s(g_packetTransformKeyText, 1025, "%s", secondDigest)`. |
| C244-024 | UID0004MF exact block frees `firstDigest` and `secondDigest` immediately after the initial write. |
| C244-025 | UID0004MF exact block uses `iteration < 31`; prose retains `mov edi,0x1f`/decrement-JNZ evidence. |
| C244-026 | UID0004MF exact block hashes the complete current global and preserves overlapping destination/first-source `"%s%s"` formatting plus per-iteration free. |
| C244-027 | UID0004MF, UID0002AL, UID0001HS, file/item/global pages record 1,024 characters plus NUL in the `0x401` allocation. |
| C244-028 | UID0004MF title/block and UID00019K caller inventory consistently use `BuildPacketTransformKeyText(char *keyText)`. |
| C244-029 | UID0002AL, UID0001I0, and UID0001HS exact blocks use `g_packetTransformKeyText`; bounded current prose and generated PacketTransform/Socket contain no stale token, while dated history is explicit. |
| C244-030 | `g_packetXorAlternateSize`, `g_packetNonceScratch`, and `g_packetXorTableAlternate` remain unchanged in exact blocks and support metadata; no speculative rename was introduced. |
| C244-031 | Parent/children/file/item/global pages route both bodies to UID0000M9; MD5 pages identify utility-provider status, Socket lifecycle identifies allocation/free context, and MemoryMan remains a called utility. |
| C244-032 | Headers verify root positions UID0000TG `10`, UID0004ME `20`, UID0004MF `30`, UID0001I0 `40`, UID0001I2 `50`, and UID0001I5 `60`; generated body order matches. |
| C244-033 | UID000286 and UID0002AL headers are positions `10` and `20` under UID0000TG; generated initialized state precedes mutable declarations. |
| C244-034 | A normalized full-marker comparison found exactly six report blocks and exact equality with parent, UID0004ME, UID0004MF, UID0002AL, UID0001I0, and UID0001HS destinations. |
| C244-035 | UID0004MF block uses `sprintf_s`; generated PacketTransform contains exactly two `sprintf_s(` call expressions and no raw formatter name. |
| C244-036 | UID0004ME preserves five `memoryMan->MemmoveWrapper` calls and the accepted GetMemoryMan receiver route. |
| C244-037 | `by-file/MD5.md` and UID0001B6 record raw call `0x00575b9f` plus live calls `0x00575c38/40/77`, exact free ownership, and PacketTransform-consumer/MD5-provider ownership; validators `000000010094` and `000000010095` passed. |
| C244-038 | Read-only inspection of `by-memory/-ignored.md` line 4116 found both accepted spans; it was not edited or validated. |
| C244-039 | Parent/file/item/global changes preserve dated old duplicate/self-concat/blank-emitter provenance while current sections state one-digest raw seeding and successive MD5 appends. |
| C244-040 | Waited command `000000010108` completed; PacketTransform counts are UID0004ME/UID0004MF and each five function definitions `1`, MD5 calls `4`, formatter calls `2`, UID000244 `0`, parent marker `0`, stale token `0`. |
| C244-041 | Generated Socket counts are constructor `1`, destructor `1`, new-token allocation/test/free/null `1` each, and stale token `0`; surrounding lifecycle/transform bodies remain in prior order. |
| C244-042 | Read-only inspection found thirteen stale existing manual coverage rows and two absent child rows across by-memory/by-file/by-item/by-global coverage. The exact fifteen-row supervisor replacement/addition text is supplied below; B001 did not edit any coverage/generated/tracker/supervisor/validator-state file. |
| C244-043 | No IDA mutation or MCP process-management command was run during callback; accepted source-facing inference remains documented without DB edits. |
| C244-044 | Before Gate 1 the report-only phase ran no validators or lifecycle commands. Callback validators were run only after authorization; B001 still ran no `execute_report`, lifecycle, move, or archive command. |

## Positive Evidence Summary
- The raw range is a complete ordinary helper with a stable one-argument ABI, eight project/runtime calls (one accessor, one MD5 helper, five memmoves, and one free), five exact size reads, four table writes, and one scratch write.
- The modeled helper has a sole live caller in the login-to-main-UI path, complete decompilation, exact MD5 and secure-format dependencies, and a mathematically closed 1,024-character result.
- `g_packetTransformKeyText` has a complete lifecycle and dataflow: Socket allocates/frees 1,025 bytes; `BuildPacketTransformKeyText` fills 1,024 characters plus NUL; `InitializePacketNonce` indexes modulo 1,024.
- Both helpers are physically and semantically inside the PacketTransform family between PacketBuffer parsing and nonce initialization.
- The strongest inference chain is direct: MD5 hex helper behavior + exact call sites + formatter operands + allocation size + nonce modulo establish the key-text semantics without relying on generated prose.

## IDA MCP Facts
- Function/range facts:
  - `0x00575b90-0x00575c30`: no IDA function object; 160 bytes; 49 instructions; normal frame; `retn 4`.
  - `0x00575c30-0x00575caa`: `sub_575C30`; size `0x7a` / 122; 40 instructions; three basic blocks; complexity two; `retn 4`.
  - `0x00515290`: `sub_515290`; size `0x7a`; accepted source role `Md5StringHex`.
  - `0x00443a00`: `sub_443A00`; size `0x2e`; secure variadic formatter.
- Data/table/padding facts:
  - Alternate size at `0x0066fe50` initializes to `9`.
  - Scratch is `0x0069ba4c-0x0069ba58`, 12 bytes.
  - Key-text pointer is at `0x0069ba58`.
  - Alternate table is `0x0069ba94-0x0069bac4`, 48 bytes.
  - Pre/post target padding is four/six `0xcc` bytes.
- Xref facts:
  - Raw start: zero.
  - Live start: one code xref at `0x004f8544`.
  - `Md5StringHex`: five call sites, one raw target call, three static live-target calls, one StartupWindow call.
  - Formatter: 54 callers total; target calls at `0x575c58` and `0x575c91`.
- Vtable/global/type facts: neither target body is a method, virtual target, vtable entry, RTTI entity, or compiler wrapper. Both use one explicit `char *` parameter and no `this`.
- Negative IDA facts: no current source-quality PacketTransform/StringKey/ProcessArg name in the target neighborhood; no raw external/interior entry; no EH/chunk evidence.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00575b90-0x00575caa` | UID000244 current path | Physical two-function split index | `FALSE` | UID0000M9 semantic owner; no emitter | `92/94` | Applied non-emitting split index |
| `0x00575b90-0x00575c30` | UID0004ME / `by-memory/0x00575b90-0x00575c30.InitializePacketTransformAlternateKey.md` | Retained no-route MD5-to-nine-byte alternate-key/table initializer | `TRUE` | UID0000M9 | `91/92` | Registered and emitted at position `20` |
| `0x00575c30-0x00575caa` | UID0004MF / `by-memory/0x00575c30-0x00575caa.BuildPacketTransformKeyText.md` | Live login-text-to-1,024-character transform key builder | `TRUE` | UID0000M9 | `92/94` | Registered and emitted at position `30` |
| `0x00575cb0-0x00575d83` | UID0001I0 | Per-packet alternate-key selection and table replication | `TRUE` | UID0000M9 | `89/91` | Rename applied; emitted at position `40` |
| `0x00577030-0x0057713d` | UID0001I2 | Primary handshake key-table builder | `TRUE` | UID0000M9 | `88/90` | Existing body preserved; position `50` applied |
| `0x00578e00-0x00578e94` | UID0001I5 | Repeated-key XOR helper | `TRUE` | UID0000M9 | `90/91` | Existing body preserved; position `60` applied |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00575b90` | zero start xrefs; zero external interior entries | Retained/unrouted source helper |
| `0x00575b95` | calls `GetMemoryMan` | Obtains receiver for four `MemoryMan::MemmoveWrapper` calls |
| `0x00575b9f` | calls `Md5StringHex` | Produces one heap MD5 hex digest |
| `0x00575bb7`, `0x00575bce`, `0x00575be7`, `0x00575c01`, `0x00575c1c` | five `MemmoveWrapper` calls | Scratch copy plus four table-window copies |
| `0x00575c22` | calls `free` | Releases raw helper digest |
| `0x00575c30` | caller `0x004f8544` in `sub_4F7D10` | Live login/main-UI setup route |
| `0x00575c38`, `0x00575c40`, `0x00575c77` | calls `Md5StringHex` | Double initial hash plus per-iteration hash |
| `0x00575c58`, `0x00575c91` | calls secure formatter | Initial bounded write and bounded append |
| `0x00575c5e`, `0x00575c64`, `0x00575c97` | calls `free` | Releases initial and loop digest strings |
| `0x004f8531-0x004f8544` | `WideCharToMultiByte` then live helper | CP_ACP login text supplies the key seed |
| `0x0069ba58` | Socket allocation/free, live helper writes, nonce helper reads | Packet-transform key-text storage |

## Documentation Evidence And IDA Status
- Supporting current docs:
  - MD5 pages already identify `sub_515290` as `Md5StringHex` returning heap hex text.
  - MemoryMan pages already identify `sub_516030` as `GetMemoryMan` and `sub_516220` as `MemoryMan::MemmoveWrapper`.
  - UID000286 and UID0002AL already define the size, scratch, pointer, and table storage.
  - UID0001HS already proves the 1,025-byte allocation/free lifecycle.
  - UID0001I0 already proves modulo-1,024 key-text consumption.
- Historical stale/incomplete state now superseded:
  - At research time UID000244 and PacketTransform item/file/global pages described MD5 calls as string duplication.
  - At research time UID000244 said the loop duplicated/self-concatenated rather than appending successive MD5 digests.
  - At research time `g_processArgList` remained an unresolved semantic name in multiple pages.
  - At research time aggregate blank C++ and no-split metadata did not match the evidence; current parent blank C++ is solely the applied split-index no-duplicate disposition.
- Historical generated state at research time:
  - `auto-generated/NexusTK/network/PacketTransform.cpp`, command `000000009979`, contains initialized and mutable declarations plus nonce/handshake/XOR bodies and UID000244 as an Empty Emitter Marker.
- Current generated state after waited command `000000010108`:
  - `PacketTransform.cpp` was refreshed at `2026-07-13T14:41:08-04:00`; UID0004ME, UID0004MF, UID0001I0, UID0001I2, and UID0001I5 occur once in source order after initialized/mutable declarations; UID000244 occurs zero times.
  - Exact expression counts are four `Md5StringHex(` calls and two `sprintf_s(` calls. `g_processArgList` occurs zero times; `g_packetTransformKeyText` supplies the declaration and producer/consumer uses.
  - `Socket.cpp` contains one ordinary constructor and one ordinary destructor; allocation, null test, free, and null assignment each use `g_packetTransformKeyText` once, and `g_processArgList` occurs zero times.
  - Generated files are evidence only and were not edited.

## Ranked Ownership Analysis

### 1. PacketTransform / `NexusTK/network/PacketTransform.cpp`
- Evidence for: both helpers write PacketTransform global state, feed nonce/XOR behavior, sit in the PacketTransform function island, and already route through UID0000M9.
- Evidence against: exact original source may have been a private section of `Socket.cpp`.
- Decision: accepted reconstruction owner/emitter. It yields a coherent utility module and preserves existing project routing.

### 2. Private free helpers in `Socket.cpp`
- Evidence for: Socket allocates/frees the key-text buffer and owns packet transport sequencing.
- Evidence against: the live caller is MainUiGraph, the functions have no `Socket *this`, and their state/helper siblings are already PacketTransform-owned.
- Decision: plausible original-file alternative but rejected as the reconstruction route.

### 3. MD5, MemoryMan, or PacketBuffer
- Evidence for: MD5 and MemoryMan are direct dependencies; physical adjacency places the range after PacketBuffer helpers.
- Evidence against: none owns the mutated transform globals or final key/table semantics.
- Decision: rejected as owners; retain as dependencies/adjacency only.

### Proposed new file/grouping, if applicable
- Proposed owner/name/path: no new by-file owner; retain UID0000M9 `NexusTK/network/PacketTransform.cpp`.
- Likely full contents: transform initialized/mutable globals, both string-key children, nonce initialization, handshake table builder, XOR transform helper.
- Candidate related items included: UID000286, UID0002AL, UID0001I0, UID0001I2, UID0001I5.
- Candidate related items rejected: Socket lifecycle and stateful encode/decode methods, MD5 implementation, MemoryMan wrappers, PacketBuffer readers/writers.
- Source-file inference: a narrow reconstruction module representing a probable private network-transform source section.

## Source Placement
- Recommended source: `NexusTK/network/PacketTransform.cpp`, owner UID0000M9.
- This placement keeps declarations before free helper bodies and keeps stateful Socket methods separate.
- Rejected `PacketBuffer.cpp`: wrong state and role.
- Rejected `MD5.cpp`: hash provider rather than transform owner.
- Rejected direct `Socket.cpp`: possible historical layout, but weaker than the established reconstruction grouping.
- Remaining uncertainty: original source may have placed these free helpers in a private portion of `Socket.cpp`; this does not block reconstruction.

## Range / Split / Padding / Reclassification Analysis
- Exact range facts:
  - Raw child: `[0x00575b90,0x00575c30)`, including `retn 4` bytes through `0x00575c2f`.
  - Live child: `[0x00575c30,0x00575caa)`, 122 bytes.
  - No internal padding exists between children.
- Child creation:
  1. Create/register raw child; capture issued UID.
  2. Create/register live child; capture issued UID.
  3. Only then update UID000244 and support links with real UIDs.
- Existing padding:
  - `[0x00575b8c,0x00575b90)`: four `0xcc`, already in UID0000VN.
  - `[0x00575caa,0x00575cb0)`: six `0xcc`, already in UID0000VN.
- Parent impact: UID000244 becomes a non-emitting exact split index, retains PacketTransform as semantic owner, and receives a post-body `[[CHILDREN]]` list in address order.
- No merge, ignored-code conversion, or compiler-artifact reclassification is supported.

## Negative Evidence Summary
- No raw function object, start xref, external interior xref, rel32 control route, absolute-VA pointer, RVA pointer, raw-offset pointer, duplicate full body, table/callback route, or exception-only route was found.
- No source symbol, PDB/map string, local type, or source filename recovers either original helper spelling.
- No method receiver, vtable slot, RTTI reference, member field, or class ABI supports Socket/class ownership.
- No packet cursor/buffer scalar state supports PacketBuffer ownership.
- No generated output or old report overrides current MD5 semantics; old duplicate-string prose is rejected.
- The negative route evidence does not prove the raw body is compiler artifact or non-source. Its complete project-helper/global behavior proves the opposite.

## IDA Rename / Type / Comment Recommendations
- Source-facing names:
  - `0x00575b90`: `InitializePacketTransformAlternateKey(char *keyText)`.
  - `0x00575c30`: `BuildPacketTransformKeyText(char *keyText)`.
  - `0x0069ba58`: `char *g_packetTransformKeyText`.
- Keep existing source-facing names/types for `Md5StringHex`, `g_packetXorAlternateSize`, `g_packetNonceScratch`, and `g_packetXorTableAlternate`.
- Suggested comments, if a separate authorized IDA pass ever occurs: raw helper is retained/no recovered inbound route; live helper produces 1,024 MD5-derived characters from CP_ACP login text.
- IDA DB edits are not required or requested by this report. No rename/type/comment mutation belongs in the callback unless separately authorized.

## First-Draft C++ Recommendation
- Applied draft C++: both exact children emit their accepted bodies. The parent is blank only because it is a non-emitting index.
- Managed-block count in this report: exactly six. These complete destination shapes were applied and exact-compared, not treated as body-only samples.

Destination: `by-memory/0x00575b90-0x00575caa.PacketTransformStringKeyHelpers.md` parent index:

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination: [UID:0004ME] `by-memory/0x00575b90-0x00575c30.InitializePacketTransformAlternateKey.md`:

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void InitializePacketTransformAlternateKey(char *keyText)
{
    MemoryMan *memoryMan = GetMemoryMan();
    char *digest = Md5StringHex(keyText);

    memoryMan->MemmoveWrapper(g_packetNonceScratch,
                              digest,
                              g_packetXorAlternateSize);
    memoryMan->MemmoveWrapper(g_packetXorTableAlternate,
                              g_packetNonceScratch,
                              g_packetXorAlternateSize);
    memoryMan->MemmoveWrapper(g_packetXorTableAlternate + g_packetXorAlternateSize,
                              g_packetNonceScratch,
                              g_packetXorAlternateSize);
    memoryMan->MemmoveWrapper(g_packetXorTableAlternate + 2 * g_packetXorAlternateSize,
                              g_packetNonceScratch,
                              g_packetXorAlternateSize);
    memoryMan->MemmoveWrapper(g_packetXorTableAlternate + 3 * g_packetXorAlternateSize,
                              g_packetNonceScratch,
                              g_packetXorAlternateSize);

    free(digest);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination: [UID:0004MF] `by-memory/0x00575c30-0x00575caa.BuildPacketTransformKeyText.md`:

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void BuildPacketTransformKeyText(char *keyText)
{
    char *firstDigest = Md5StringHex(keyText);
    char *secondDigest = Md5StringHex(firstDigest);

    sprintf_s(g_packetTransformKeyText, 1025, "%s", secondDigest);

    free(firstDigest);
    free(secondDigest);

    for (int iteration = 0; iteration < 31; ++iteration) {
        char *nextDigest = Md5StringHex(g_packetTransformKeyText);
        sprintf_s(g_packetTransformKeyText,
                  1025,
                  "%s%s",
                  g_packetTransformKeyText,
                  nextDigest);
        free(nextDigest);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination: [UID:0002AL] `by-memory/0x0069ba40-0x0069bac4.PacketTransformMutableState.md`:

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
unsigned char g_handshakeSeedBytes[12];
unsigned char g_packetNonceScratch[12];
char *g_packetTransformKeyText;
int g_packetTransformStride;
unsigned char g_packetSequenceByte;
static unsigned char s_packetTransformSequencePadding[3];
unsigned char g_packetXorTablePrimary[48];
unsigned char g_packetXorTableAlternate[48];
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination: [UID:0001I0] `by-memory/0x00575cb0-0x00575d83.PacketNonceInitialization.md`:

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void InitializePacketNonce(unsigned short nonceBase, unsigned char nonceMiddle)
{
    const int alternateSize = g_packetXorAlternateSize;
    int step = nonceMiddle * nonceMiddle;

    for (int index = 0; index < alternateSize; ++index) {
        const int keyIndex = (nonceBase + index * step) % 1024;
        step += 3;
        g_packetNonceScratch[index] = g_packetTransformKeyText[keyIndex];
    }

    if (static_cast<unsigned int>(alternateSize) >= sizeof(g_packetNonceScratch)) {
        __report_rangecheckfailure(alternateSize);
    }

    g_packetNonceScratch[alternateSize] = 0;

    memmove(g_packetXorTableAlternate,
            g_packetNonceScratch,
            static_cast<size_t>(alternateSize));
    memmove(g_packetXorTableAlternate + alternateSize,
            g_packetNonceScratch,
            static_cast<size_t>(alternateSize));
    memmove(g_packetXorTableAlternate + 2 * alternateSize,
            g_packetNonceScratch,
            static_cast<size_t>(alternateSize));
    memmove(g_packetXorTableAlternate + 3 * alternateSize,
            g_packetNonceScratch,
            static_cast<size_t>(alternateSize));
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination: [UID:0001HS] `by-memory/0x005747e0-0x00574ad8.SocketLifecycle.md`:

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
Socket::Socket()
    : Thread(0x800),
      m_socket(INVALID_SOCKET),
      m_socketConnected(false),
      m_serialTransportHandle(INVALID_HANDLE_VALUE),
      m_transportMode(0),
      m_protocolModeFlag(0),
      m_connectionFlag(0),
      m_sendDisabled(0),
      m_connectionStatus(0),
      m_connectionRetryDelay(10)
{
    g_packetSender = this;

    srand(static_cast<unsigned int>(time(nullptr)));

    char seed[] = "UrkcnItni";
    BuildHandshakeBlock(sizeof(seed), seed);

    g_packetTransformKeyText = static_cast<char *>(AllocatePacketQueueMemory(0x401));

    m_activeReadBuffer = m_receiveBufferPrimary;
    m_alternateReadBuffer = m_receiveBufferAlternate;
    ClearSocketReceiveAndFrameState();

    if (g_pConfig->GetTransportMode() == 6) {
        m_transportMode = 6;
        PostMode6StartupMessages();
    }
}

Socket::~Socket()
{
    if (m_socket != INVALID_SOCKET) {
        closesocket(m_socket);
        m_socket = INVALID_SOCKET;
        m_socketConnected = false;
    }

    if (m_serialTransportHandle != INVALID_HANDLE_VALUE)
        CloseTransport();

    if (g_pConfig->GetTransportMode() == 6)
        PostMode6ShutdownMessages();

    if (g_packetTransformKeyText != nullptr) {
        FreePacketQueueMemory(g_packetTransformKeyText);
        g_packetTransformKeyText = nullptr;
    }

    g_packetSender = nullptr;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

- Behavior preservation:
  - Raw block preserves helper call order, five independent global-size reads, one scratch copy, four window copies, and direct `free`.
  - Live block preserves double initial MD5, exact capacity, two initial frees, 31 hash/append/free iterations, and overlapping destination/first-source formatter operands.
  - Rename blocks preserve storage, formulas, allocation size, and teardown behavior while replacing only the stale semantic token.
- Human source shape: ordinary free helpers, named globals, existing project MemoryMan/MD5 APIs, `sprintf_s`, and simple loops match the accepted mid-2000s project style better than decompiler temporaries or raw labels.
- Inferred names: helper names, `keyText`, digest local names, `iteration`, and `g_packetTransformKeyText`.
- Parent no-code proof: the parent has no unique source body after exact children own every byte. Its blank block prevents duplicate aggregate emission; it is not a blank-code deferral.
- Third-party import directive: not applicable. These are NexusTK project helpers, not vetted third-party source.

## Final Recommendation
- Applied: UID000244 is split and both child bodies are implemented exactly under validator-issued UID0004ME/UID0004MF.
- Applied: PacketTransform owner/emitter routing and deterministic declaration/function ordering are current and generated.
- Applied: the bounded producer/consumer/lifetime formal set uses `g_packetTransformKeyText`; `g_processArgList` remains only in explicitly dated/historical prose.
- Applied: raw no-route evidence is preserved and the former duplicate-string/aggregate-blank interpretation is historicalized.
- Leave exact original symbol spelling and original private-section/file layout as confidence caps only.
- Do not mutate IDA, generated output, coverage/tracker/audit state, or report lifecycle state manually.
- Manual coverage synchronization is genuinely required but remains supervisor-owned; this report supplies exact replacement/addition text for all thirteen stale rows and two absent child rows under `Exact Manual Supervisor-Owned Coverage Or Tracker Text`.

## Recommended Target Doc Changes
- Target path: `by-memory/0x00575b90-0x00575caa.PacketTransformStringKeyHelpers.md`.
- Applied metadata:
  - `COMPLETION:92`
  - `CONFIDENCE:94`
  - preserve `CANONICAL_OWNER:0000M9`
  - `RECONSTRUCTABLE:FALSE`
  - blank `EMITTER_UIDS`
  - blank `EMITTER_POSITION_OPTIONAL`
  - exact blank parent managed block above
  - `Nested:2`
- Exact parent Item Summary: `Non-emitting split index for one retained no-route MD5-derived alternate-key initializer and one live login-text key builder; exact children own both source bodies and PacketTransform emission.`
- Replaced aggregate source-emitter language with an exact two-child index and address-ordered inventory.
- Added post-body `[[CHILDREN]]` after validator-issued UID0004ME and UID0004MF were known.
- Preserved all old evidence as dated history, explicitly superseding only:
  - `sub_515290` as duplicate-string;
  - self-duplication expansion;
  - unresolved global-name blocker;
  - blank aggregate C++ as a current recommendation.
- Preserved raw liveness negatives, caller, padding, ownership rejections, and old MCP chronology.

## Recommended Support Doc Changes
- New raw child path, applied as UID0004ME:
  - Created at `91/92`, owner/emitter UID0000M9, position `20`, reconstructable true, Nested 0, exact managed block, complete raw body/evidence/liveness/history.
  - Exact Item Summary: `Source-ready retained PacketTransform helper that MD5-hashes key text, copies the first nine digest bytes into scratch, replicates four alternate-key windows, frees the digest, and has exhaustive no-route and unique-body evidence.`
- New live child path, applied as UID0004MF:
  - Created at `92/94`, owner/emitter UID0000M9, position `30`, reconstructable true, Nested 0, exact managed block, caller/MD5/format/free/key-length evidence.
  - Exact Item Summary: `Source-ready live PacketTransform helper that converts login-derived key text into a 1,024-character MD5 chain with bounded secure formatting, exact temporary frees, and one MainUiGraph caller.`
- `by-file/PacketTransform.md`:
  - Raised `89/85 -> 91/90`.
  - Replaced aggregate blank/raw blocker with exact children and complete semantics.
  - Applied `g_packetTransformKeyText`.
  - Preserved separate-file versus private-`Socket.cpp` uncertainty.
- `by-item/PacketTransformHelpers.md`:
  - Raised `88/90 -> 91/93`.
  - Replaced raw/live inventory names and stale duplicate/self-concat behavior.
  - Recorded that the overview remains blank only because exact children emit, not because blockers remain.
- `by-global/PacketTransformGlobals.md`:
  - Raised `88/90 -> 90/92`.
  - Set root `EMITTER_POSITION_OPTIONAL:10`.
  - Renamed `g_processArgList` to `g_packetTransformKeyText`.
  - Added exact 1,025-byte allocation/1,024-character contents and raw/live/nonce flow.
- [UID:000286] `by-memory/0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut.md`:
  - Raised `88/89 -> 89/91`.
  - Set position `10` under UID0000TG.
  - Replaced generic raw-helper wording with one MD5 digest, nine-byte length, scratch copy, and four windows; preserved all LUT/reserved-dword content and C++ unchanged.
- [UID:0002AL] `by-memory/0x0069ba40-0x0069bac4.PacketTransformMutableState.md`:
  - Raised `88/91 -> 90/93`.
  - Set position `20` under UID0000TG.
  - Applied exact declaration block rename and full producer/consumer semantics.
- [UID:0001I0] `by-memory/0x00575cb0-0x00575d83.PacketNonceInitialization.md`:
  - Raised `88/90 -> 89/91`.
  - Set root position `40`.
  - Applied exact managed block rename; preserved formula, range check, callers, table copies, and all unrelated evidence.
- [UID:0001I2] `by-memory/0x00577030-0x0057713d.BuildHandshakeBlock.md`:
  - Set root position `50`; made no score or C++ change.
- [UID:0001I5] `by-memory/0x00578e00-0x00578e94.XorTransformBuffer.md`:
  - Set root position `60`; made no score or C++ change.
- [UID:0001HS] `by-memory/0x005747e0-0x00574ad8.SocketLifecycle.md`:
  - Applied exact managed block rename and prose sync only; preserved `90/92`, owner/emitter, blank position, and unrelated Socket content.
- [UID:00019K] `by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md`:
  - Named the call at `0x004f8544` `BuildPacketTransformKeyText`, recorded CP_ACP conversion and the 1,024-character result; made no score/C++ change.
- `by-file/MD5.md` and `by-memory/0x005151f0-0x00515f48.MD5HashHelpers.md`:
  - Recorded the raw call at `0x00575b9f` plus the three live static call sites and clarified transform-helper ownership; made no score/C++/metadata change.
- `by-memory/-ignored.md`:
  - Already sufficient; read-only inspection confirmed both accepted padding spans, so no edit was made.

## Score And Metadata Recommendation
- Historical target before callback: `86/90`, owner/emitter UID0000M9, reconstructable true, blank position/C++, Nested 0.
- Applied parent: `92/94`, semantic owner UID0000M9, reconstructable false, blank emitter/position/C++, Nested 2.
- Applied raw child UID0004ME: `91/92`, owner/emitter UID0000M9, position 20, reconstructable true.
- Applied live child UID0004MF: `92/94`, owner/emitter UID0000M9, position 30, reconstructable true.
- Reason parent is not higher: exact original source names and original separate-file/private-Socket layout are not symbol-proven.
- Reason raw child is not higher: no recovered inbound route and no original name.
- Reason live child is not higher: source-facing name and global spelling remain inferred, and exact original intent behind overlapping secure formatting is not source-proven even though the binary call is exact.
- Score-improvement attempts:
  - Raw body blocker: decoded all 49 instructions; resolved.
  - Raw route blocker: checked start, every instruction start, direct branches/calls, pointer encodings, duplicates, entities, tables/callbacks, and EH shape; resolved to retained/unrouted source with confidence cap.
  - MD5 helper blocker: analyzed `sub_515290` and current MD5 docs; resolved as `Md5StringHex`.
  - Formatter blocker: analyzed `sub_443A00`; resolved as secure `sprintf_s` source form.
  - Live expansion blocker: decoded operands/loop and calculated exact final length; resolved.
  - Global naming blocker: reconciled allocation, producer, and consumer; resolved as `g_packetTransformKeyText`.
  - Owner/source blocker: ranked PacketTransform/Socket/MD5/PacketBuffer; resolved to existing PacketTransform route.
  - Aggregate C++ blocker: split children and supplied exact blocks; resolved.
- Metadata not changed: accepted canonical owners for initialized/mutable data and existing helper pages; reconstructable states and formal code of UID000286, UID0001I2, and UID0001I5.

## Open Questions With Attempted Resolution
- Is raw `0x00575b90` live?
  - Checked IDA start/interior xrefs, function/name entities, direct control routes, all pointer encodings, body duplicates, table/callback patterns, and exception/compiler shape.
  - Resolution: no runtime route is recovered. The complete source body is retained/unrouted project code and is emitted; this remains a confidence cap.
- What does `sub_515290` do?
  - Checked current decompile, callees, xrefs, MD5 docs, and return ownership.
  - Resolution: `Md5StringHex`, heap 32-character digest, freed with CRT `free`.
- What does the live loop append?
  - Checked exact push order and calls.
  - Resolution: MD5 of the entire current key text, 31 times; not a duplicate of the string.
- What is `ArgList`?
  - Checked Socket 1,025-byte lifetime, live producer, nonce modulo-1,024 consumer, and all xrefs.
  - Resolution: packet-transform key text; use `g_packetTransformKeyText`.
- Should the target split?
  - Checked exact boundaries, returns, source roles, and by-structure.
  - Resolution: yes, two children; parent index only.
- Where did original source live?
  - Checked island, globals, caller, Socket lifetime, MD5/PacketBuffer alternatives, and current project route.
  - Resolution: reconstruct in PacketTransform.cpp. Private Socket source remains possible but does not block.
- Exact original helper/global spellings:
  - No symbols/source strings exist. The report supplies descriptive source-facing names grounded in behavior.
  - Remaining impact: confidence cap only; no score or C++ blocker remains.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text
- B001 read the current manual coverage reports after callback and did not edit them. Thirteen existing rows are stale and two validator-created child rows are absent. Exact supervisor-owned replacement/addition text follows.
- `auto-generated/-ag-research-tracker.md` already contains current `92/94` non-reconstructable UID000244 and current `91/92`/`92/94` reconstructable UID0004ME/UID0004MF rows, so no manual tracker replacement is required.

Fixed affected-destination matrix:

| Manual coverage report | Changed destinations inspected | Current result | Exact report disposition |
| --- | --- | --- | --- |
| `by-memory/-coverage-report.md` | UID000244, UID0004ME, UID0004MF, UID0001HS, UID00019K, UID0001B6, UID0001I0, UID0001I2, UID0001I5, UID000286, UID0002AL | Nine existing rows are stale; UID0004ME/UID0004MF are absent. | Replace nine rows and add two address-ordered nested child rows using the exact text below. |
| `by-file/-coverage-report.md` | UID0000M9 PacketTransform; UID0000L6 MD5 | Both existing rows are stale. | Replace both rows using the exact text below. |
| `by-item/-coverage-report.md` | UID0000V3 PacketTransformHelpers | Existing row is stale. | Replace the row using the exact text below. |
| `by-global/-coverage-report.md` | UID0000TG PacketTransformGlobals | Existing row is stale. | Replace the row using the exact text below. |

Per-destination fixed-matrix self-review:

| Destination | Current manual row state read | Current by-* state read | Synchronization decision |
| --- | --- | --- | --- |
| UID000244 | Present as reconstructable `82%` aggregate emitter. | `92/94`, non-reconstructable/non-emitting split index, Nested 2. | Replace. |
| UID0004ME | Absent. | `91/92`, reconstructable UID0000M9 emitter at position 20. | Add as first nested child. |
| UID0004MF | Absent. | `92/94`, reconstructable UID0000M9 emitter at position 30. | Add as second nested child. |
| UID0001HS | Present at `82%` with stale key-buffer/C++-blocker summary. | `90/92`; exact g_packetTransformKeyText constructor/destructor block and lifecycle. | Replace. |
| UID00019K | Present at `78%` without UID0004MF caller semantics. | `90/91`; CP_ACP/128-byte caller and exact 1,024-character result documented. | Replace. |
| UID0001B6 | Present at `82%` without current source-ready children/four-site inventory. | `87/90`; exact four PacketTransform Md5StringHex call sites and ownership boundary documented. | Replace. |
| UID0001I0 | Present at `85%` with ArgList/unresolved-prototype wording. | `89/91`; g_packetTransformKeyText formal block and position 40. | Replace. |
| UID0001I2 | Present at `85%` with final-name/global blocker wording. | `88/90`; formal C++ and position 50. | Replace. |
| UID0001I5 | Present at `82%` with unresolved source prototype wording. | `90/91`; resolved void ABI/formal C++ and position 60. | Replace. |
| UID000286 | Present at `85%` without exact UID0004ME semantics/position. | `89/91`; exact raw one-digest behavior and position 10 under UID0000TG. | Replace. |
| UID0002AL | Present at `86%` with generic key-buffer wording. | `90/93`; exact g_packetTransformKeyText declarations/flow and position 20. | Replace. |
| UID0000M9 | Present at `88%` without split children/current source order. | `91/90`; exact split, bodies, global flow, and `10/20/30/40/50/60` order. | Replace. |
| UID0000L6 | Present at `86%` without current source-ready/four-call details. | `89/88`; current MD5 child readiness and PacketTransform dependency inventory. | Replace. |
| UID0000V3 | Present at `87%` with unresolved raw/prototype caveats. | `91/93`; exact child inventory/semantics and blank-overview-only disposition. | Replace. |
| UID0000TG | Present at `86%` with final declarations still open. | `90/92`; exact declarations, key-text flow, and positions. | Replace. |

### `by-memory/-coverage-report.md`

Replace the current UID00019K row with:

```text
    - [UID:00019K][0x004f7d10-0x004f8b2a.InitializeMainUiGraph](by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md) : reconstructable : 90% : strong : Exact MainUiGraph bootstrap range with boundary, padding, sole login-success caller, graph-pointer handoff, frame resources, layer contexts, active map-session tail, and source-owner route; the newer-layout branch converts login-derived wide text with `WideCharToMultiByte(CP_ACP, ...)` into a 128-byte local and calls UID0004MF `BuildPacketTransformKeyText` at `0x004f8544`, producing exactly 1,024 MD5-derived characters plus NUL while the broad initializer retains its target-specific blank-C++ proof.
```

Replace the current UID0001B6 row with:

```text
    - [UID:0001B6][0x005151f0-0x00515f48.MD5HashHelpers](by-memory/0x005151f0-0x00515f48.MD5HashHelpers.md) : reconstructable : 87% : strong : IDA-confirmed MD5 helper island with modeled/raw boundaries, shared utility ownership, caller map, padding, source-ready Md5BytesHex/Md5FilePathHex/Md5Encode/Md5Decode children, retained aggregate blockers for Md5BytesRaw and MD5Context spelling, and exact PacketTransform Md5StringHex call inventory at raw `0x00575b9f` plus live `0x00575c38`, `0x00575c40`, and `0x00575c77`; MD5 owns the hash/heap-string contract while UID0004ME/UID0004MF remain PacketTransform-owned consumers.
```

Replace the current UID0001HS row with:

```text
    - [UID:0001HS][0x005747e0-0x00574ad8.SocketLifecycle](by-memory/0x005747e0-0x00574ad8.SocketLifecycle.md) 0x005747e0-0x00574ad8 | constructor/destructor cluster | SocketLifecycle : reconstructable : 90% : very-strong : Source-ready Socket constructor/destructor lifecycle with Thread base setup/teardown, handshake seed, receive/frame buffers, transport defaults, g_packetSender lifetime, mode-6 dispatch, Winsock/alternate-transport close paths, and exact `g_packetTransformKeyText` lifecycle: allocate `0x401` bytes, let UID0004MF fill 1,024 characters plus NUL, conditionally free, and null the pointer; adjacent event wrappers and compiler scalar/unwind siblings remain excluded.
```

Replace the current UID000244 row and insert the two nested child rows immediately below it, before the existing `0x00575caa-0x00575cb0` ignored-padding row, with this exact block:

```text
    - [UID:000244][0x00575b90-0x00575caa.PacketTransformStringKeyHelpers](by-memory/0x00575b90-0x00575caa.PacketTransformStringKeyHelpers.md) 0x00575b90-0x00575caa | packet-transform split index | PacketTransformStringKeyHelpers : not_reconstructable : 92% : very-strong : Non-emitting split index for one retained no-route MD5-derived alternate-key initializer and one live login-text key builder; semantic owner remains PacketTransform, exact children UID0004ME/UID0004MF own every source byte and emit at positions 20/30, and the parent preserves blank C++ solely to prevent aggregate duplication.
      - [UID:0004ME][0x00575b90-0x00575c30.InitializePacketTransformAlternateKey](by-memory/0x00575b90-0x00575c30.InitializePacketTransformAlternateKey.md) 0x00575b90-0x00575c30 | retained packet-transform helper | InitializePacketTransformAlternateKey : reconstructable : 91% : very-strong : Source-ready retained helper that obtains MemoryMan, MD5-hashes key text once, copies the current nine-byte alternate size into scratch, replicates four alternate-key windows through five MemmoveWrapper calls, frees the heap digest with CRT free, and preserves exhaustive zero-entry/pointer/duplicate-route evidence as a liveness cap rather than suppressing the unique body.
      - [UID:0004MF][0x00575c30-0x00575caa.BuildPacketTransformKeyText](by-memory/0x00575c30-0x00575caa.BuildPacketTransformKeyText.md) 0x00575c30-0x00575caa | packet-transform helper | BuildPacketTransformKeyText : reconstructable : 92% : very-strong : Source-ready live helper with sole MainUiGraph caller; computes MD5(MD5(login-derived key text)), performs a bounded 1,025-byte seed write, frees both initial digests, then executes 31 successive whole-current-text MD5 append/free iterations with overlapping secure-format operands for exactly 1,024 characters plus NUL in g_packetTransformKeyText.
```

Replace the current UID0001I0 row with:

```text
    - [UID:0001I0][0x00575cb0-0x00575d83.PacketNonceInitialization](by-memory/0x00575cb0-0x00575d83.PacketNonceInitialization.md) 0x00575cb0-0x00575d83 | packet transform helper | PacketNonceInitialization : reconstructable : 89% : strong : Source-ready position-40 PacketTransform helper with exact `(nonceBase + index * step) % 1024` selection over g_packetTransformKeyText, `step = nonceMiddle * nonceMiddle` then `+3`, default alternate size 9, scratch write/terminator/range-check behavior, four alternate-table windows, two Socket callers, resolved memmove wrapper, and preserved following alignment.
```

Replace the current UID0001I2 row with:

```text
    - [UID:0001I2][0x00577030-0x0057713d.BuildHandshakeBlock](by-memory/0x00577030-0x0057713d.BuildHandshakeBlock.md) 0x00577030-0x0057713d | packet transform helper | BuildHandshakeBlock : reconstructable : 88% : strong : Source-ready position-50 PacketTransform helper with exact formal C++; copies the caller seed into transform state, mutates/restores bytes 6 and 3, records stride, writes four primary XOR-table windows, frees the caller block, and is called only from the Socket constructor and command 14 while original symbol/file placement remains a confidence cap.
```

Replace the current UID0001I5 row with:

```text
    - [UID:0001I5][0x00578e00-0x00578e94.XorTransformBuffer](by-memory/0x00578e00-0x00578e94.XorTransformBuffer.md) 0x00578e00-0x00578e94 | packet transform helper | XorTransformBuffer : reconstructable : 90% : strong : Source-ready position-60 PacketTransform XOR primitive with exact `0x94` boundary, six Socket call sites, no callees, resolved source/destination/length/key/keyWordCount ABI, void return, repeated dword-key modulo loop, one-to-three-byte tail cases, in-place safety, resolved key globals, and separate aligned UNL.DLL successor.
```

Replace the current UID000286 row with:

```text
    - [UID:000286][0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut](by-memory/0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut.md) 0x0066fe50-0x00670258 | packet transform globals | PacketTransformAlternateSizeAndLut : reconstructable : 89% : strong : Position-10 initialized PacketTransformGlobals declarations for alternate size 9, reserved zero dword, and 256-entry repeated-byte dword LUT; exact raw UID0004ME one-digest nine-byte scratch/four-window behavior, nonce/encrypted-packet/socket-command consumers, data samples, xrefs, and boundary before aConnaddr are documented while the formal LUT block remains unchanged.
```

Replace the current UID0002AL row with:

```text
    - [UID:0002AL][0x0069ba40-0x0069bac4.PacketTransformMutableState](by-memory/0x0069ba40-0x0069bac4.PacketTransformMutableState.md) 0x0069ba40-0x0069bac4 | global-data cluster | PacketTransformMutableState : reconstructable : 90% : very-strong : Position-20 mutable PacketTransformGlobals declarations for handshake seed, nonce scratch, 1,025-byte g_packetTransformKeyText pointer, stride, sequence byte/padding, and primary/alternate XOR tables; exact UID0004ME/UID0004MF producers, UID0001I0 modulo-1,024 consumer, Socket allocation/free lifecycle, zero-initialized 132-byte storage, field xrefs, and StartupWindow successor boundary are documented.
```

### `by-file/-coverage-report.md`

Replace the current UID0000L6 MD5 row with:

```text
- [UID:0000L6][MD5](by-file/MD5.md) : reconstructable : 89% : strong : Shared MD5 utility assigned to `NexusTK/util/MD5.cpp` with modeled/raw helper split, update/final/transform chain, source-ready byte/file/endian children, cross-subsystem caller map, padding and fallback behavior, and exact PacketTransform Md5StringHex calls at raw `0x00575b9f` plus live `0x00575c38`, `0x00575c40`, and `0x00575c77`; UID0004ME/UID0004MF remain PacketTransform-owned consumers and free every returned heap digest with CRT free.
```

Replace the current UID0000M9 PacketTransform row with:

```text
- [UID:0000M9][PacketTransform](by-file/PacketTransform.md) : reconstructable : 91% : strong : Source-ready packet-transform module with deterministic globals/raw/live/nonce/handshake/XOR emission order `10/20/30/40/50/60`, non-emitting UID000244 split index, exact UID0004ME retained alternate-key initializer, exact UID0004MF 1,024-character MD5-chain builder, g_packetTransformKeyText producer/consumer/lifecycle semantics, initialized/mutable global children, preserved no-route evidence, and separate-file versus private-Socket placement retained only as a confidence cap.
```

### `by-item/-coverage-report.md`

Replace the current UID0000V3 row with:

```text
- [UID:0000V3][PacketTransformHelpers](by-item/PacketTransformHelpers.md) : reconstructable : 91% : very strong : PacketTransform helper inventory synchronized to exact UID0004ME/UID0004MF children, one-digest nine-byte alternate-key initialization, double-initial-MD5 plus 31 successive digest appends for 1,024-character g_packetTransformKeyText, nonce/handshake/XOR bodies, initialized/mutable global declarations, Socket callers/lifecycle, MD5 and MemoryMan dependency boundaries, retained raw no-route negatives, and blank overview C++ solely because exact children emit.
```

### `by-global/-coverage-report.md`

Replace the current UID0000TG row with:

```text
- [UID:0000TG][PacketTransformGlobals](by-global/PacketTransformGlobals.md) : reconstructable : 90% : very-strong : Position-10 PacketTransform global root with initialized/mutable declaration children at positions 10/20; documents alternate size/LUT, handshake seed, nonce scratch, 1,025-byte g_packetTransformKeyText, stride/sequence/padding, primary/alternate XOR tables, UID0004ME/UID0004MF producer behavior, UID0001I0 modulo-1,024 consumption, Socket allocation/free lifecycle, field xrefs, exact formal declarations, and original spelling/file placement only as confidence caps.
```

- No other changed destination has a distinct manual coverage row. The exact rows above cover every stale/absent affected row found by the fixed matrix. B001 performed no manual coverage or tracker edit.

## Follow-Up Actions
- B001 callback and same-report Gate 1 repair work are complete; no target/support/validator/generated-verification/report-text item remains for B001.
- Exact manual coverage replacement/addition text is supplied in this artifact without editing coverage. Whether/when that supervisor-owned text is applied is external state and is not asserted or directed here.
- Exact report validation/execution/count/path/move/archive state remains external supervisor/validator-owned and is neither asserted nor directed by this artifact.
- No second target or unrelated source-layout research was started.

## Confidence
- Recommendation confidence: `94/100` for split, behavior, owner route, and formal source shape.
- Score confidence: high; applied scores preserve meaningful caps for route/name/source-file uncertainty.
- Remaining uncertainty: original spellings, original private-section/file organization, and why the linker retained the unrouted raw helper.

## Validator Results
- All commands ran from `source-3/project-documentation`. Every scoped by-* validator exited `0` with `ok:1`; ordinary runs deferred generated refresh until the authorized final waited command.
- This same-report Gate 1 repair ran no validator or implementation command; it used read-only coverage/tracker inspection and changed only this report.

| Command ID | Timestamp EDT | Scoped invocation / purpose | Exit / ok | Material result and side effects |
| --- | --- | --- | --- | --- |
| `000000010058` | `2026-07-13T14:21:45-04:00` | file validator, new raw child | `0 / 1` | Registered path and issued UID0004ME; registry/reference/stats projection updated; generation deferred. |
| `000000010061` | `2026-07-13T14:22:48-04:00` | file validator, new live child | `0 / 1` | Registered path and issued UID0004MF after UID0004ME; registry/reference/stats projection updated; generation deferred. |
| `000000010068` | `2026-07-13T14:25:54-04:00` | file validator, UID000244 parent | `0 / 1` | Applied `92/94`, non-emitting split metadata, `Nested:2`, and real child links; registry/reference/stats projection updated. |
| `000000010072` | `2026-07-13T14:27:12-04:00` | file validator, `by-file/PacketTransform.md` | `0 / 1` | Applied `91/90` and exact split/global/source-order support; generation deferred. |
| `000000010075` | `2026-07-13T14:28:45-04:00` | file validator, `by-item/PacketTransformHelpers.md` | `0 / 1` | Applied `91/93` exact helper inventory and child-emission no-code proof; generation deferred. |
| `000000010078` | `2026-07-13T14:30:05-04:00` | file validator, `by-global/PacketTransformGlobals.md` | `0 / 1` | Applied `90/92`, root position `10`, current key-text flow, and registry/stats updates. |
| `000000010081` | `2026-07-13T14:31:02-04:00` | file validator, UID000286 | `0 / 1` | Applied `89/91`, position `10`, exact raw initializer semantics; formal LUT block preserved. |
| `000000010083` | `2026-07-13T14:31:51-04:00` | file validator, UID0002AL | `0 / 1` | Applied `90/93`, position `20`, exact renamed declaration block and producer/consumer detail. |
| `000000010085` | `2026-07-13T14:33:15-04:00` | file validator, UID0001I0 | `0 / 1` | Applied `89/91`, position `40`, exact renamed nonce block and preserved formula/range/caller evidence. |
| `000000010087` | `2026-07-13T14:35:14-04:00` | file validator, UID0001I2 | `0 / 1` | Registry position changed blank to `50`; score and C++ unchanged. |
| `000000010089` | `2026-07-13T14:35:51-04:00` | file validator, UID0001I5 | `0 / 1` | Registry position changed blank to `60`; score and C++ unchanged. |
| `000000010091` | `2026-07-13T14:36:51-04:00` | file validator, UID0001HS | `0 / 1` | Exact Socket managed rename/lifecycle detail applied; validator normalized three UID links and added UID0004MF reference index. |
| `000000010092` | `2026-07-13T14:37:30-04:00` | file validator, UID00019K | `0 / 1` | Applied caller name/CP_ACP/128-byte/1,024-character context; one pre-existing unrelated missing UID0003ZI reference warning remained nonfatal. |
| `000000010094` | `2026-07-13T14:38:06-04:00` | file validator, `by-file/MD5.md` | `0 / 1` | Applied four-site inventory and ownership boundary; four pre-existing UID0003J1 missing-reference emissions remained nonfatal; UID0004ME/MF links normalized. |
| `000000010095` | `2026-07-13T14:38:41-04:00` | file validator, UID0001B6 MD5 aggregate | `0 / 1` | Applied four-site inventory/ownership exclusion; UID0004ME/MF links and reference index updated. |
| `000000010100` | `2026-07-13T14:39:32-04:00` | file revalidation, UID0001I0 historical-token clarification | `0 / 1` | Confirmed phrase-only provenance correction; stats projection refreshed; generation deferred. |
| `000000010106` | `2026-07-13T14:40:22-04:00` | file revalidation, PacketTransform historical-token clarification | `0 / 1` | Confirmed evidence-time wording; stats projection refreshed; generation deferred. |
| `000000010108` | `2026-07-13T14:41:08-04:00` | file validator on PacketTransform with `--wait-generated` | `0 / 1` | Generated refresh completed; registry rebuilt (`4689` nodes / `3811` edges), generated metadata refreshed, and validator-owned memory coverage refreshed. Broad pre-existing warnings (`15` fallback inserts, `83` missing preferred child markers, `200` no-code emitters) were unrelated to this target. |

- Generated freshness: `PacketTransform.cpp` header records command `000000010108` / `2026-07-13T14:41:08-04:00` and filesystem write `14:41:18`; `Socket.cpp` filesystem write is `14:41:20`, both after the waited command timestamp.
- PacketTransform assertions: UID000244 count `0`; UID0004ME/UID0004MF counts `1/1`; raw/live/nonce/handshake/XOR definition counts each `1`; four `Md5StringHex(` expressions; two `sprintf_s(` expressions; stale token count `0`; parent empty-marker count `0`. Initialized/mutable declarations precede line-ordered bodies UID0004ME (`93`), UID0004MF (`118`), UID0001I0 (`140`), UID0001I2 (`172`), UID0001I5 (`214`).
- Socket assertions: one constructor at line `169`, one destructor at line `200`; new-token allocation/test/free/null counts each `1`; total new-token count `4`; stale token count `0`; surrounding lifecycle and transform bodies remain present and ordered.
- Managed-block assertion: exactly six report blocks; normalized full marker/header/body/footer comparison returned `True` for all six destination files.
- Remaining limitations are evidence caps only: original helper/global spellings, original separate-file versus private-Socket organization, and the reason the linker retained UID0004ME without a recovered route. No accepted implementation item is blocked.

## Changed Files
- Created ordinary by-* pages:
  - `by-memory/0x00575b90-0x00575c30.InitializePacketTransformAlternateKey.md` (UID0004ME).
  - `by-memory/0x00575c30-0x00575caa.BuildPacketTransformKeyText.md` (UID0004MF).
- Modified ordinary by-* pages:
  - `by-memory/0x00575b90-0x00575caa.PacketTransformStringKeyHelpers.md`
  - `by-file/PacketTransform.md`
  - `by-item/PacketTransformHelpers.md`
  - `by-global/PacketTransformGlobals.md`
  - `by-memory/0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut.md`
  - `by-memory/0x0069ba40-0x0069bac4.PacketTransformMutableState.md`
  - `by-memory/0x00575cb0-0x00575d83.PacketNonceInitialization.md`
  - `by-memory/0x00577030-0x0057713d.BuildHandshakeBlock.md`
  - `by-memory/0x00578e00-0x00578e94.XorTransformBuffer.md`
  - `by-memory/0x005747e0-0x00574ad8.SocketLifecycle.md`
  - `by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md`
  - `by-file/MD5.md`
  - `by-memory/0x005151f0-0x00515f48.MD5HashHelpers.md`
- Modified callback artifact: this same report.
- Same-report Gate 1 repair after failed SHA `7D97F10B37AC11399E8E9BEE224FB4873AA33A0834A5E7C377B9175CCB1FD80D`: modified only this report; no by-* or manual coverage page was changed and no validator was rerun.
- Read-only verification: `by-memory/-ignored.md` already contained both accepted spans and was not edited.
- Validator-owned side effects only: command `000000010108` refreshed generated/coverage/registry metadata. B001 did not manually edit generated, coverage, tracker, supervisor/audit, validator-state, queue, lock, or lifecycle files.
- No by-* file was renamed. B001 did not execute, move, or archive this report.
- Lease proof: every ordinary existing-file lease was acquired only immediately before its edit and released after its scoped validator; each release returned `Success`. New children were created while the parent split lease was held and registered serially. Final shared lease report at `2026-07-13T14:51:21-04:00` showed `No active leases` and therefore no B001 row.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor Gate 1 passed exact SHA256 `09E8B23D70682F3723283EF5853801B3137D5FA66943742544E845599951EF56` before implementation.
- [x] Target/support set recorded: UID000244; two validator-created children; PacketTransform file/item/global; UID000286; UID0002AL; UID0001I0; UID0001I2; UID0001I5; UID0001HS; UID00019K; MD5 file/aggregate.
- [x] Research-time target state and actual evidence were recorded before callback and preserved as historical context.
- [x] Historical search provenance records exact target/address/name, `sub_575C30`, `ArgList`, `g_processArgList`, `PacketTransform`, and `Socket` terms across active, central executed, `archived/**`, `Older-Research/**`, and `SpecialReports/**`, with relevant matches classified.
- [x] Gate 1 ledger used only allowed Action values and `proposed` states; callback ledger now uses only legal callback states with separate proof.
- [x] Exact parent/child/support score and position plan was complete before callback.
- [x] Score/C++ blockers were resolved to exact source, split, or retained-unrouted disposition.
- [x] Owner/emitter/reconstructable plan identified a non-emitting parent and UID0000M9-owned/emitted children.
- [x] Split/rename/new-child plan required serialized real UIDs and `g_packetTransformKeyText`.
- [x] Source placement, range/split/padding/reclassification, and no-IDA-mutation dispositions were complete.
- [x] Exactly six destination-specific managed blocks were present and accepted.
- [x] Third-party import directive was confirmed not applicable.
- [x] Report-level target/support facts were complete before callback.
- [x] Historical duplicate/self-duplication/blank-aggregate assumptions and negative evidence were preserved for callback.
- [x] Wave2/Wave3 material was treated as stale authority only.
- [x] Open questions were closed or retained solely as explicit confidence caps.
- [x] Scoped one-page validator and short-lease plan was explicit.
- [x] Final authorized waited generation and PacketTransform/Socket assertions were explicit.

Implementation callback pass:
- [x] Exact accepted report SHA was used for this same-report implementation callback.
- [x] Child one was created/validated first; command `000000010058` issued UID0004ME before links.
- [x] Child two was created/validated second; command `000000010061` issued UID0004MF before links.
- [x] All accepted target/support details were incorporated at report-level detail across the exact fifteen by-* pages.
- [x] C244-001 through C244-044 use legal callback states and have separate claim-level proof.
- [x] Parent/child metadata, scores, owners, emitters, positions, nesting, links, summaries, and all six exact managed blocks are applied.
- [x] Historical assumptions, rejected alternatives, and all raw/live negative evidence are preserved.
- [x] `g_processArgList` is absent from bounded current/formal/generated state; remaining by-* mentions are explicitly historical/dates.
- [x] Scoped validators ran one page at a time; IDs, timestamps, exits, `ok`, warnings, and side effects are recorded above.
- [x] Every one-file lease was released after its scoped validator; final lease report has no B001 row.
- [x] Final authorized command `000000010108` completed with waited generated refresh.
- [x] Generated PacketTransform declarations precede bodies; raw/live/nonce/handshake/XOR each occur once; MD5 calls are `4`; formatter calls are `2`; UID000244/parent marker/aggregate duplicate/stale token are absent.
- [x] Generated Socket uses the new token once each for allocation/test/free/null, has no stale token, and preserves surrounding bodies/order.
- [x] No accepted item is blocked or unapplied; remaining issues are confidence caps only.

Same-report Gate 1 repair:
- [x] Removed the contradictory current generated-state sentence; current Socket evidence now consistently records four `g_packetTransformKeyText` lifecycle uses and zero `g_processArgList` uses.
- [x] Read all four current manual coverage reports without editing them and inspected every changed destination row.
- [x] Fixed matrix accounts for thirteen stale existing rows and two absent validator-created child rows across by-memory/by-file/by-item/by-global coverage.
- [x] Supplied exact supervisor-owned replacement/addition text for UID000244, UID0004ME, UID0004MF, UID0001HS, UID00019K, UID0001B6, UID0001I0, UID0001I2, UID0001I5, UID000286, UID0002AL, UID0000M9, UID0000L6, UID0000V3, and UID0000TG.
- [x] Reclassified C244-042 to legal `incorporate` / `applied` state with separate proof while preserving the no-manual-coverage-edit boundary.
- [x] Confirmed the generated research tracker already has current UID000244/UID0004ME/UID0004MF metadata and requires no manual replacement text.
- [x] Preserved all 44 claims, 44 proof rows, six formal blocks, implementation validators, generated assertions, changed-file history, and lifecycle-neutral wording.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000010160","destination_path":"executed-b-agent-research/B001/000244-PacketTransformStringKeyHelpers-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/000244-PacketTransformStringKeyHelpers-source-quality.md","timestamp":"2026-07-13T15:18:13-04:00","uid":"000244"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
