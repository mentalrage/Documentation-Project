** TARGET-REPORT-UID:0003QZ **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# 0003QZ SelfLookPane2OnDraw Source-Quality Research

## Finalized Report / Current Recommendation

- Validator command `000000010601` performed the UID-preserving rename from historical `by-memory/0x005700e0-0x0057092c.SelfLookPane2OnDraw.md` to implemented `by-memory/0x005700e0-0x0057092c.SelfLookPane2OnActivate.md`. Primary-vtable slot `+0x48`, the shared Pane contract, sibling SelfLookPane/UserLookPane slots, and the packet argument prove `void SelfLookPane2::OnActivate(const unsigned char *packetData)`.
- UID0003QZ now preserves exact `[0x005700e0,0x0057092c)`, owner/emitter UID0000CV, `RECONSTRUCTABLE:TRUE`, blank optional position, and `Nested:0`; score is implemented at `92/94` and managed block R1 is exact.
- UID0001HK remains the non-emitting main-span split index with owner UID0000CV, blank emitter/position/formal C++, and `Nested:0`; score is implemented at `89/92`, with corrected target inventory, exact padding, and UID0004NA inserted in address order.
- Registered [UID:0004NA] `by-memory/0x00570e20-0x00570eef.SelfLookPane2ShowProfileViewRaw.md` serially through validator command `000000010607`, with owner/emitter UID0000CV, `RECONSTRUCTABLE:TRUE`, blank position, `Nested:0`, score `89/92`, and managed block R3.
- UID0000CV now carries exact managed class block R2: `PanelPane` inheritance, public virtual/member declarations needed by the current source family, class closure before `[[CHILDREN]]`, and the exact naturally padded `0xd90` layout; score is implemented at `92/93`.
- UID0000NL is implemented at `90/92`, UID00038M at `89/93`, and UID00038N at `90/94`, with exact source/compiler, table, and `+0x48` OnActivate evidence. Their owner/emitter routes remain unchanged. UID00038M remains blank-formal compiler inventory; UID00038N uses one comment-only compiler no-code line so generated output has no false Empty Emitter Marker and still emits no manual vtable/RTTI array.
- UID0003R9, UID0003RA, UID0004N5, and exact stale caller statements in SpelledPane class/file are synchronized without score/route/body changes. UserStatusPane, PacketBuffer, LivingObjectPane, LegendPane, ProfilePane, TextEditPane, and GeneralPurposePanel2 were re-read as verify-only dependencies; no contradictory current link required edits or ownership transfer.
- The target has no internal source split. Its SEH entry/exit, cookie check, range-check failure block, and external EH graph nodes are compiler lowering within the one source method. Predecessor and successor alignment remain parent-only.
- Overall recommendation confidence is very strong for behavior, layout, ABI, slot, owner, range, and source route; exact original spellings for several opaque packet/state fields remain descriptive inference and cap scores without blocking formal C++.

## Supporting Research

### Mandatory MCP provenance

- Evidence was collected on `2026-07-13` through streamable MCP endpoint `http://127.0.0.1:13337/mcp`, HTTP MCP session `021f141d-0c82-48a3-a769-081a18d34be8`, with database argument `supervisor_nexustk_20260713` in every IDB-backed target call.
- Fresh `idb_list` returned one adopted worker-backed NexusTK database: `supervisor_nexustk_20260713`, `NexusTK.exe.i64`, worker PID `2236`.
- Fresh `server_health` returned `status:ok`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, image base `0x00400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready with `2067` entries.
- Bounded `lookup_funcs`, `get_bytes`, `analyze_function`, `decompile`, `disasm`, `basic_blocks`, `xrefs_to`, `callees`, data reads, and bounded instruction searches returned real NexusTK IDB results. This is not a fallback-only report.
- One initial whole-`.text` `insn_query` for `push 0xd90` exceeded 60 seconds and returned zero scanned instructions. The listener, MCP session, and database remained healthy; all subsequent bounded calls succeeded. That broad timeout is discarded evidence, not an MCP outage. The narrowed GeneralPurposePanel neighborhood search found no `0D90h` allocation immediate, so exact complete-object size remains layout-derived rather than allocation-call-proven.

### Historical-report search provenance

Exact case-insensitive search terms were `0003QZ`, `0x005700e0`, `005700e0`, `SelfLookPane2OnDraw`, `SelfLookPane2OnActivate`, and `sub_5700E0`.

| Exact root searched | Outcome and target-specific classification |
| --- | --- |
| `source-3/project-documentation/tools/leaser/Agents/Agent-B001/**` | No active dedicated UID0003QZ report. |
| `source-3/project-documentation/tools/leaser/Agents/Agent-B002/**` | Goal mentions UID0003QZ only as recently changed support; no target overlap. |
| `source-3/project-documentation/tools/leaser/Agents/Agent-B003/**` | Current goal and this report are the assigned target artifacts; no prior B003 target report existed. |
| `source-3/project-documentation/tools/leaser/Agents/Agent-B004/**` | Goal records UID0003QZ as active B003 work; no competing report. |
| `source-3/project-documentation/tools/leaser/Agents/Agent-B005/**` | Goal mentions UID0003QZ only as recent support; no competing report. |
| `source-3/project-documentation/executed-b-agent-research/**` | Two exact material matches, classified below. Related B004/B005/B001 reports supply independently rechecked slot/sibling/view precedent. |
| `source-3/project-documentation/archived/**` | No exact-term match. |
| `source-3/project-documentation/tools/leaser/Agents/Older-Research/**` | No exact-term match. |
| `source-3/project-documentation/tools/leaser/Agents/SpecialReports/**` | No exact-term match. |

Material executed-report findings:

- B001 `0001HK-selflookpane2-source-split-audit.md`: created the exact child and correctly established its range, vtable data reference, broad class owner, and split-index position, but used the provisional `OnDraw`/draw-update label and left the complete body, packet fields, class layout, and formal C++ unresolved. Retain its boundary/split evidence; reject its method-role spelling.
- B001 `000284-SpelledPaneWhitespaceDelimiter-source-quality.md`: independently proves the call at `0x0057068e`, fixed 256-wide-character caller buffer at `this+0xb7c`, embedded SpelledPane at `this+0xfc`, and consumer-only relation to parser UID0004N5. It intentionally did not resolve the rest of UID0003QZ. Current MCP revalidated every one of those bounded facts.
- B004 `00015Y-GeneralPurposePanel2SwitchActiveChild-empty-emitter-source-quality.md`: independently models eight primary-slot `+0x48` consumers and proves the common virtual contract `OnActivate(const unsigned char *)`. This is caller/ABI support, not target ownership.
- B005 `0003RK-UserLookPaneParseLookPacket-source-quality.md`: the sibling `UserLookPane` primary `+0x48` method is accepted as `OnActivate(const unsigned char *)` and supplies source-facing PacketBuffer, ANSI-to-wide, UserStatus-like rich-text, and legend-loop precedent. Its different packet layout remains separate.
- B001 `0003RT-UserLookPaneShowBioView-source-quality.md`: supplies a source-facing ProfilePane view-switch comparator. Current raw SelfLookPane2 bytes were independently decoded; the comparator does not substitute for target evidence.

## Target

- UID: `0003QZ`.
- Historical assignment-time path: `by-memory/0x005700e0-0x0057092c.SelfLookPane2OnDraw.md`.
- Implemented target path: `by-memory/0x005700e0-0x0057092c.SelfLookPane2OnActivate.md` through UID-preserving validator rename command `000000010601`.
- Exact binary range: `[0x005700e0,0x0057092c)`.
- Exact size: `0x84c` / 2124 bytes, verified with `tools/int_convert.py`.
- Exact target-byte SHA256: `ADCD5C9EFA1FC2B2B303E49A505C265E81AB89B72ABE57F70CD2CBB1B073D38F`.
- First 16 bytes: `55 8B EC 6A FF 68 29 7E 60 00 64 A1 00 00 00 00`.
- Last 16 bytes: `E8 0E 6E 05 00 8B E5 5D C2 04 00 E8 29 6D 05 00`.
- Historical pre-callback metadata: `86/89`, owner/emitter UID0000CV, reconstructable true, blank position, `Nested:0`, blank formal C++.
- Implemented metadata: `92/94`, same owner/emitter/reconstructable/position/Nested state, complete R1 formal C++.

## Current Target State

- The historical pre-callback page called the method a draw/update path and said view-state fields, packet/data names, and helper names blocked C++. The implemented renamed page historicalizes those hypotheses and carries the complete source form.
- Valid bounded UID0004N5 caller evidence from executed B001 UID000284 is preserved and expanded into the complete packet flow rather than replaced.
- At evidence collection, read-only generated `auto-generated/NexusTK/ui/panels/SelfLookPane.cpp` had header command `000000010575`, timestamp `2026-07-13T19:00:41-04:00`, 644 lines, 23,469 bytes, SHA256 `4F1BA5181130B2705219BE41ED1275839A3DE61D7CE6567587294C207A8E99C6`; line 640 contained the UID0003QZ `86/89` Empty Emitter Marker. This is explicitly historical pre-callback generated state, not source authority or a future lifecycle assertion.
- B003's final waited validator command `000000010669`, timestamp `2026-07-14T03:45:18-04:00`, refreshed generated `SelfLookPane.cpp`: R2 closes before qualified definitions; R1 and R3 each occur once; UID0003QZ and UID00038N have no Empty Emitter Marker; stale OnDraw and raw vtable/RTTI arrays occur zero times; and all 23 UID snippet headers are unique. A later externally owned refresh, command `000000010686` at `2026-07-14T03:56:22-04:00`, was observed read-only and preserves those target-specific results; its current generated SHA256 is `CCC3F8A2D6802D6D0043C7AC8DFD860ED0ACADE66B7C313EEB7888325F1EF2A6`.
- The target is source-authored packet activation behavior. It parses state into SelfLookPane2, refreshes UserStatus display state, rebuilds SpelledPane and LegendPane children, restores the already selected view, and returns void.

## Executive Recommendation

The callback implemented one source method, one complete class declaration, and one newly split raw view helper. Only the target title/path was renamed; its UID and binary interval are preserved. The target was not split or moved to PacketBuffer/UserStatus/SpelledPane/ProfilePane/GeneralPurposePanel ownership, and no compiler SEH/range-check/vtable machinery was emitted.

R1 is complete source-facing C++ for `SelfLookPane2::OnActivate`. R2 closes the class before `[[CHILDREN]]` and orders natural fields to reproduce every proven offset through the `0xd90` extent without explicit raw-layout padding members. R3 preserves the omitted no-xref profile child as a retained source-shaped helper. The raw helper's absence from current active callers is a liveness confidence cap, not a reason to hide its exact body or leave `m_profilePane` unexplained.

## Implementation Callback State

- B003 completed the accepted ordinary by-* implementation, scoped validators, bounded verify-only reads, final waited generated refresh, and generated readback. Every B003 lease was released immediately after its scoped destination work.
- B003 did not manually edit generated, manual coverage/tracker, audit/supervisor, validator-state, IDA, lifecycle, or archive files. Validator-owned registry/projected-stat/generated refresh side effects are recorded below.
- C01-C20 and the callback checklist record final applied/already-present truth with exact destination and command proof; no implementation item remains blocked.
- Report validation/execution/count/path/move/archive state is external supervisor/validator-owned and is neither asserted nor directed by this artifact. B003 performed no execute, probe, move, archive, or lifecycle command.

## Inference Research Guidance Check

- The assignment title, existing owner, source route, score, class skeleton, and blank C++ were treated as hypotheses rather than authority.
- Exact executable facts are separated from source-facing names. Descriptive names are used where symbols do not reveal original identifiers; raw IDA labels and decompiler temporaries are absent from formal C++.
- Sibling methods and executed reports were used as comparators only after current target bytes, fields, and calls were independently checked.
- Source/compiler distinctions were applied to vptr stores, SEH state, security cookie, range-check branch, table data, and virtual dispatch.
- The split-first rule was applied to the omitted `[0x00570e20,0x00570eef)` source body and to target-internal compiler blocks. Physical adjacency alone was not used as ownership proof.

## Heuristic / Inference Reanalysis And Validation

| Issue | Reanalysis and resolution | Classification |
| --- | --- | --- |
| `OnDraw` title | Target does no drawing; primary `+0x48`, `ret 4`, packet reads, and sibling slots prove OnActivate. | Reject stale title; binary/contract-proven role. |
| Parameter | One callee-cleaned stack argument is read as byte packet data; sibling contract is const unsigned byte pointer. | `const unsigned char *packetData`. |
| Return | Normal and compiler-failure paths do not supply a source result; decompiler `void` agrees. | Source `void`. |
| Direct callers | No code xrefs exist because dispatch is virtual. Sole target ref is vtable cell `0x00624740`. | Normal virtual-only method. |
| Packet text | Every text field is an 8-bit byte-length ANSI sequence converted with CP_ACP into a bounded wide buffer and explicitly terminated. | Source-local force-inlined read helper in R1 matches the repeated compiler-inlined form. |
| State bytes | Three leading bytes, one BE32 value, and three toggle bytes have exact types/offsets but no semantic symbol. | Stable descriptive names; confidence cap only. |
| Equipment | Five fixed BE16/palette records map exactly to Head, LeftAccessory, RightAccessory, LeftSubAccessory, RightSubAccessory. | Binary and sibling selector proven. |
| Living sprite | `0x0053a8c0` copies exact 68-byte LivingSpriteConfig from the active local player. | Existing class dependency, no ownership transfer. |
| UserStatus calls | Two display-line setters, one name copy, and two dword getters use `g_activeUserStatusPane`. | Existing UID0001NN APIs. |
| Spelled text | Tabs become LF, text is copied to member `wchar_t[256]`, measured, and passed to UID0004N5 on `m_spelledPane`. | Exact caller-owned source and consumer route. |
| Legend loop | BE16 count; each row has symbol byte, color byte, length-prefixed text, appended CR, embedded 12x12 EPF object, selected text range, format command 2, and collapsed selection. | Complete source loop. |
| Range check | The only terminal exceptional block calls `__report_rangecheckfailure` if the terminator index reaches/exceeds the 256-wide local. | Compiler checked-array lowering; no source branch. |
| Refresh | Binary calls FrameHandler remove then schedule-next-frame on SpelledPane subobject `+0x174`; existing source abstraction is `RefreshScrollState()`. | Source-facing inline abstraction with direct order retained in prose. |
| View restore | Existing `m_viewMode` 1 calls ShowSpelledView, 2 calls ShowLegendView, and 0 performs no switch call. | Exact, no invented profile-mode branch. |
| Profile pointer | Omitted raw `[0x00570e20,0x00570eef)` dereferences `this+0x100` and performs a complete profile attach sequence. | New retained raw source child. |
| Profile liveness | No function record, direct xref, VA/RVA pointer, or internal call route was found; constructor also does not initialize `+0x100`. | Retained/dead source-shaped helper, not active mode. |
| Complete size | Highest exact field ends at `+0xd90`; natural alignment and five final dwords close the extent. No allocation immediate was found. | High-confidence exact layout extent, not allocation-call proof. |
| Source file | Class/file/vtables, contiguous family, generated route, and sibling methods all resolve to `NexusTK/ui/panels/SelfLookPane.cpp`. | Strong project route; original physical filename not symbol-proven. |

Rejected alternatives:

- `OnDraw`, `ParseLookPacket`, `UpdateView`, and `HandlePacket` are weaker than the shared virtual `OnActivate` contract.
- Direct ownership by PacketBuffer, UserStatusPane, LivingObjectPane, SpelledPane, LegendPane, ProfilePane, TextEditPane, or GeneralPurposePanel is rejected; those are dependencies, child types, or virtual dispatch context.
- A split at the legend loop, range-check block, or SEH blocks is rejected. They are source control flow/compiler lowering inside one method.
- A mode-3 Profile branch is rejected. The dormant raw helper contains no `m_viewMode` store and has no active caller.
- Explicit byte-padding arrays, raw offset comments, vptr assignments, cookie checks, SEH states, or manual range-check calls are rejected from formal C++.
- Raw `sub_` labels, `dword_` globals, and decompiler temporaries are rejected as source identifiers.

## Evidence Standards Used

- Primary: current live IDA bytes, hashes, function boundaries, decompilation, disassembly, CFG blocks, xrefs, callees, vtable cells, and bounded range scans.
- Secondary: current by-* metadata, generated output read-only state, exact sibling formal blocks, and executed reports.
- Negative: zero direct code xrefs, zero raw-profile start routes, no target-internal separate function, no target drawing calls, no active profile-mode branch, no constructor write to `+0x100`, no allocation immediate proving `0xd90`, and no symbol/path string proving another file.
- Arithmetic conversions `0x84c=2124`, `0xd90=3472`, `0xcf=207`, `0x100=256`, `0x80=128`, `0x44=68`, and `0x3c=60` were verified with `tools/int_convert.py`.

## Evidence Checked

- Mandatory MCP `idb_list`, `server_health`, target `lookup_funcs`, full `get_bytes`, `analyze_function`, `basic_blocks`, `decompile`, bounded disassembly, `xrefs_to`, and `callees`.
- Predecessor destructor end, target start/end, successor null stub, and all intervening alignment bytes.
- SelfLookPane2 primary/secondary/tertiary vtables, exact target slot, SelfLookPane/UserLookPane sibling slots, and GeneralPurposePanel2 slot contract.
- Constructor/destructor, OnPaint, input handlers, view helpers, raw toggle helpers, raw profile body, and field consumers throughout UID0001HK.
- UID0004N5 parser, UID000284 delimiter, UID0001NN UserStatus accessors, PacketBuffer scalar readers, LivingSpriteConfig getter, TextEditPane rich-text API, and EPFTextEditObject construction.
- Current class/file/vtable/parent docs, generated SelfLookPane.cpp, manual coverage rows, and historical reports under every root listed above.
- Exact historical search roots `source-3/project-documentation/archived/**`, `tools/leaser/Agents/Older-Research/**`, and `tools/leaser/Agents/SpecialReports/**`; all produced no exact-term match.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state | Implementation proof |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C01 | Mandatory evidence-time MCP database `supervisor_nexustk_20260713` was healthy and all bounded target reads returned real IDB data. | Very strong | Fresh idb_list/server_health and bounded calls. | Target/support MCP evidence and report provenance. | incorporate | applied | UID0003QZ Evidence records endpoint, HTTP/database sessions, health/readiness, and real bounded calls as evidence-time facts; final scoped target validator `000000010668` exited 0/`ok:1`. |
| C02 | UID0003QZ is exactly `[0x005700e0,0x0057092c)`, `0x84c`/2124 bytes, with stated hash/bytes and no internal source split. | Very strong | Full bytes, lookup, CFG, disassembly. | Renamed target and UID0001HK. | incorporate | applied | Renamed target carries exact interval/size/hash/CFG/boundaries; UID0001HK preserves one child and parent-only pads. Final validators: target `000000010668`, parent `000000010644`, both exit 0/`ok:1`. |
| C03 | Historical `SelfLookPane2OnDraw` is wrong; source method is `void SelfLookPane2::OnActivate(const unsigned char *)`. | Very strong | Primary +0x48, sibling family, packet reads, ret 4. | UID-preserving target rename, class/vtable/file/support links. | reject-stale | applied | Rename command `000000010601` preserved UID0003QZ and updated validator path state; class/file/vtable/parent/view/parser/SpelledPane links are synchronized by commands `000000010635`, `000000010637`, `000000010639`, `000000010641`, `000000010642`, `000000010644`, `000000010645`, `000000010646`, `000000010647`, `000000010652`, and `000000010668`. Final generated stale-name count is zero. |
| C04 | Target has zero code callers and one data xref at vtable cell `0x00624740`; dispatch is indirect through Pane OnActivate. | Very strong | xrefs/analyze/vtable reads/B004 contract. | Target, UID00038M/38N, GeneralPurposePanel2 support. | incorporate | applied | Exact target/vtable-family/vtable-child evidence is present; GeneralPurposePanel2 remained verify-only and consistent. Final validators `000000010647`, `000000010664`, and `000000010668` exited 0/`ok:1`. |
| C05 | Packet cursor begins at 1 and consumes three state bytes, six fixed byte-length ANSI text values, one BE32 state value, and one byte-length text value per legend row. | Very strong | Full decompile/disassembly and conversion calls. | Target behavior/R1/class fields. | incorporate | applied | Exact R1 is byte-for-byte present in UID0003QZ and matching R2 fields are in UID0000CV; commands `000000010668` and `000000010645` exited 0/`ok:1`. |
| C06 | UserStatus interactions set two display lines, copy one 128-wide name snapshot, and capture two dword display values. | Very strong | Calls 0x5b8670/86a0/85b0/8640/8650. | Target/class/UID0001NN support. | incorporate | applied | UID0003QZ R1/evidence and UID0000CV layout contain exact calls/storage. UID0001NN was verify-only and consistent; target/class final validators `000000010668`/`000000010645` passed. |
| C07 | Five equipment id/palette pairs and exact 68-byte LivingSpriteConfig populate the stated class layout. | Very strong | Packet readers, selectors, GetSpriteConfig. | Target/class/LivingObjectPane support. | incorporate | applied | R1 and exact `+0x108..+0x15d` R2/layout table carry the five pairs/config. LivingObjectPane remained verify-only; target/class validators passed. |
| C08 | Spelled text converts TAB to LF, copies to `wchar_t[256]` at `+0xb7c`, and calls UID0004N5 with measured length. | Very strong | Current caller bytes and executed UID000284 recheck. | Target/class/UID0004N5 support. | incorporate | applied | UID0003QZ, UID0000CV, UID0004N5, and SpelledPane class/file carry exact consumer/ownership facts. Commands `000000010639`, `000000010641`, `000000010642`, `000000010645`, and `000000010668` passed. |
| C09 | Legend rows use symbol/color/text, append CR, insert a 12x12 EPF object, apply format command 2, and preserve checked-array failure behavior. | Very strong | Loop disassembly/callees/TextEdit APIs. | Target R1 and TextEdit/Legend support prose. | incorporate | applied | Exact R1/evidence records every row operation and compiler range-check disposition; TextEditPane/LegendPane were verify-only and consistent. Target validator `000000010668` passed. |
| C10 | Target clears child state, removes/unregisters Spelled/Legend, refreshes Spelled scroll state, and restores only modes 1/2. | Very strong | Tail blocks and view helper calls. | Target, UID0003R9/3RA, class. | incorporate | applied | R1 plus UID0003R9/UID0003RA mode-specific caller prose and R2 enum are implemented; commands `000000010635`, `000000010637`, `000000010645`, and `000000010668` passed. |
| C11 | SelfLookPane2 has exact natural `0xd90` layout with four pane/resource pointers, 68-byte config, equipment, seven wide buffers, status/toggle fields, and five tail dwords. | Strong | Constructor/destructor/target/sibling consumers. | UID0000CV R2 and target layout table. | incorporate | applied | UID0000CV carries exact R2 and full offset table with natural non-member padding; R2 compares byte-for-byte to report. Final class validator `000000010645` passed. |
| C12 | Descriptive packet/field names close C++ blockers while preserving exact types/offsets and lexical uncertainty as a score cap. | Strong | Exhaustive consumers and absence of symbols. | Target/class/open questions. | incorporate | applied | UID0003QZ/UID0000CV use source-facing descriptive names, exact types, no raw offset comments, and retain lexical caps in prose; final validators `000000010668`/`000000010645` passed. |
| C13 | `[0x00570e20,0x00570eef)` is an omitted complete raw `ShowProfileView` source body using `m_profilePane` at `+0x100`. | Strong | 207 raw bytes, SHA256 `E9F54A601FFDCF542C3F285707C3502333B7332AA4076DF4FD96251FC8FE9B85`, full decode, Profile sibling precedent. | New validator-issued child and UID0001HK/class/file. | incorporate | applied | Serial registration command `000000010607` issued UID0004NA; final child/parent/class/file validators `000000010658`, `000000010644`, `000000010645`, `000000010646` passed and all links use the real UID. |
| C14 | Nine CC bytes precede raw profile helper, one CC follows it; target predecessor/successor alignment remains parent-only. | Very strong | Exact byte reads and function boundaries. | UID0001HK range/padding table and new child. | incorporate | applied | UID0001HK and UID0004NA preserve both inter-helper pads; UID0003QZ preserves its 9-byte predecessor and 4-byte successor pads. Validators `000000010644`, `000000010658`, `000000010668` passed. |
| C15 | Target/new child remain owned/emitted by UID0000CV through UID0000NL, blank position, Nested0; parent remains non-emitting Nested0. | Very strong | Existing route plus direct class/vtable evidence. | Metadata and support docs. | incorporate | applied | Metadata readback is exact on UID0003QZ/UID0004NA/UID0001HK/UID0000CV/UID0000NL; serial scoped validators passed and no relative nesting changed. |
| C16 | Target improves `86/89 -> 92/94`, is validator-renamed, and receives complete managed block R1. | Strong | All prior blockers closed; lexical caps retained. | Renamed UID0003QZ. | incorporate | applied | Rename `000000010601`; final target `000000010668`; R1 byte-for-byte comparison true; generated command `000000010669` emits R1 once with no UID0003QZ marker. |
| C17 | Class improves `89/91 -> 92/93` and receives exact managed declaration R2 with class closed before `[[CHILDREN]]`. | Strong | Complete method/layout evidence. | by-class/SelfLookPane2.md. | incorporate | applied | Final class validator `000000010645` passed; R2 byte-for-byte comparison true; generated command `000000010669` confirms class close precedes first qualified definition. |
| C18 | Parent/file/vtable pages receive exact inventory/route/slot/source/compiler evidence and bounded score changes; verify-only supports retain scores/routes. | Strong | Current docs plus target pass. | UID0001HK, UID0000NL, UID00038M/38N and named supports. | incorporate | applied | Final validators: parent `000000010644`, file `000000010646`, vtable family `000000010647`, vtable child compiler-comment repair `000000010664`, view/parser/Spelled supports `000000010635`/`000000010637`/`000000010639`/`000000010641`/`000000010642`; all exit 0/`ok:1`. Other named APIs stayed verify-only. |
| C19 | New raw child is `89/92`, reconstructable, receives R3, and retains no-route/uninitialized-pointer caveats without a false compiler/no-code marker. | Strong | Complete raw body plus negative route evidence. | UID0004NA child. | incorporate | applied | UID0004NA metadata/evidence/R3 are exact; registration `000000010607`, final child validator `000000010658`, R3 comparison true, and generated command `000000010669` emits it once. |
| C20 | Existing-UID manual coverage replacement/addition rows are exact and current now, including UID00038N and the serially registered UID0004NA raw-child row. The historical generated marker, rejected alternatives, validators, changed files, lifecycle boundary, and callback checklist remain exact; manual coverage text remains report-only and externally owned. | Very strong | Current artifacts and workflow. | Report final sections and all destinations. | incorporate | applied | Manual rows below use real UID0004NA and current scores; B003 did not edit manual coverage. Validator/results/files/checklist are reconciled; terminal waited command `000000010669` and no-lease readback prove callback completion without lifecycle action. |

## Positive Evidence Summary

- Exact full bytes, size, hash, entry signature, final return, and boundary padding close the function interval.
- Primary-vtable slot `+0x48` is consistent across SelfLookPane, SelfLookPane2, UserLookPane, and the GeneralPurposePanel2 dispatcher contract.
- Every target read/write maps to a naturally ordered class field; constructor, destructor, OnPaint, raw toggles, and view helpers independently corroborate the layout.
- Every callee has a source-facing project API or a bounded compiler/runtime disposition.
- The fixed SpelledPane source buffer and parser call independently match executed UID000284 evidence.
- The LegendPane loop matches the accepted UserLookPane rich-text source shape while preserving target-specific 256-wide checked storage and manual offset tracking.
- The omitted raw ProfilePane helper explains the otherwise unexplained `+0x100` class slot and the exact gap between existing view children.

## IDA MCP Facts

### Function, byte, and CFG facts

- `lookup_funcs(0x005700e0)` returns `sub_5700E0`, size `0x84c`; `0x0057092c` is not a function; `nullsub_52` starts at `0x00570930`, size 1.
- Full `get_bytes` returned exactly 2124 bytes and the SHA256 listed above.
- `analyze_function` reports IDA prototype `void __thiscall(int this, int)`, 568 disassembled instructions, 21 CFG nodes, cyclomatic complexity 7, zero direct code callers, and sole data xref `0x00624740`.
- Eighteen CFG blocks are in the target: `5700e0-5704ad`, `5704ad-5704b0`, `5704b0-5704bb`, `5704bb-5704c3`, `5704c3-5704c8`, `5704c8-5706ed`, `5706ed-5706f0`, `5706f0-57078e`, `57078e-5707b3`, `5707b3-5707ca`, `5707ca-5707cc`, `5707cc-570888`, `570888-5708f4`, `5708f4-5708f9`, `5708f9-570902`, `570902-570909`, `570909-570927`, and `570927-57092c`.
- The remaining analyzer nodes at `0x00607e1b`, `0x00607e29`, and `0x005c956c` are external compiler EH/range-check/runtime blocks, not target children.

### Boundary and padding facts

- Predecessor UID0003QY ends at `0x005700d7`; `[0x005700d7,0x005700e0)` is nine `cc` bytes.
- Target ends exactly at `0x0057092c`; `[0x0057092c,0x00570930)` is four `cc` bytes before `nullsub_52`.
- Existing ShowSpelledView ends at `0x00570e17`; `[0x00570e17,0x00570e20)` is nine `cc` bytes.
- Raw profile helper is exactly `[0x00570e20,0x00570eef)`, `0xcf`/207 bytes, 69 decoded instructions, SHA256 `E9F54A601FFDCF542C3F285707C3502333B7332AA4076DF4FD96251FC8FE9B85`, first 16 bytes `55 8B EC 83 EC 14 A1 24 2F 67 00 33 C5 89 45 FC`, and last 16 bytes `20 8B 4D FC 33 CD 5E E8 44 68 05 00 8B E5 5D C3`; it ends in `ret`, and `0x00570eef` is one `cc` byte before ShowLegendView at `0x00570ef0`.
- No IDA function object exists at the raw helper start or interior and no direct start xref was found.

### Vtable and dispatch facts

| Class | Primary base | Cell | Target | Source contract |
| --- | --- | --- | --- | --- |
| `SelfLookPane` | `0x00624188` | `+0x48` | `0x00565890` | `OnActivate(const unsigned char *)` sibling |
| `SelfLookPane2` | `0x006246f8` | `0x00624740` / `+0x48` | `0x005700e0` | this target |
| `UserLookPane` | sibling family | `+0x48` | `0x0059f610` | accepted OnActivate body |
| Pane base | family base | `+0x48` | pure/default contract | one packet-pointer argument |

SelfLookPane2 secondary and tertiary bases remain `0x00624748` and `0x00624778`. Constructor, cleanup, and scalar destructor stores remain exactly as documented; no manual vtable source array is recommended.

### Callee inventory

| Binary dependency | Source-facing role in R1 |
| --- | --- |
| `0x00575480` / `0x005754c0` | `PacketBufferReadUInt16BE` / `PacketBufferReadUInt32BE` |
| `MultiByteToWideChar` | CP_ACP conversion of byte-counted packet text |
| `_wcscpy_s` / `wcslen` | bounded member copy and parser length |
| `0x0053a8c0` | `LivingObjectPane::GetSpriteConfig` exact 68-byte copy |
| `0x005b85b0` / `0x005b8640` / `0x005b8650` | UserStatus name copy and two dword getters |
| `0x005b8670` / `0x005b86a0` | UserStatus display-line setters |
| `0x0056c0e0` | `SpelledPane::ParseAndLoadEntries` UID0004N5 |
| `0x0058e320` / `0x0058ea80` / `0x0058e270` / `0x0058fc30` | TextEdit clear, edit state, and text insertion/replacement family |
| `0x0058f2a0` / `0x0058fef0` | selection range and selection-format application |
| `0x005954c0` / `0x005905f0` | `EPFTextEditObject` construction and 12x12 object insertion |
| `0x004b6d20` then `0x004b6d00` | remove then next-frame schedule on SpelledPane handler; source `RefreshScrollState()` |
| `0x00570c80` / `0x00570ef0` | ShowSpelledView / ShowLegendView |
| `0x004f4aa0`, `0x00516030`, `0x00516220`, cookie/range helpers | allocation/runtime/compiler support, not target ownership |

## Function / Child Inventory

| Range | Current UID | Pre-callback status | Implemented status | Role |
| --- | --- | --- | --- | --- |
| `0x005700e0-0x0057092c` | UID0003QZ | implemented page, wrong title/blank code | validator-renamed target with R1 | `SelfLookPane2::OnActivate` |
| `0x00570930-0x00570931` | UID0003R0 | existing non-emitting stub | unchanged | one-byte null stub |
| `0x00570c00-0x00570c80` | UID0003R8 | existing helper | verify-only | default view |
| `0x00570c80-0x00570e17` | UID0003R9 | existing helper | caller/field prose sync | spelled view |
| `0x00570e17-0x00570e20` | ignored padding | parent-only | unchanged | nine CC bytes |
| `0x00570e20-0x00570eef` | UID0004NA | implemented retained source-shaped raw body | registered with R3 | dormant `ShowProfileView` |
| `0x00570eef-0x00570ef0` | ignored padding | parent-only | unchanged | one CC byte |
| `0x00570ef0-0x00570fb3` | UID0003RA | existing helper | caller/field prose sync | legend view |
| `0x00570fc0-0x00571c05` | UID0003RB | existing method | verify-only field consumer | OnPaint |

Validator command `000000010607` serially allocated UID0004NA to the exact raw child; every report and support reference now uses that issued UID rather than a temporary identifier.

## Direct Xref / Caller Inventory

| Item | Exact refs | Meaning |
| --- | --- | --- |
| target start `0x005700e0` | data xref `0x00624740` only; zero code xrefs | virtual-only primary slot `+0x48` |
| UID0004N5 parser | call at `0x0057068e` | target passes `m_spelledPane`, copied member buffer, measured length |
| ShowSpelledView | call inside target plus key/input callers | mode-1 restore |
| ShowLegendView | call inside target plus key/input callers | mode-2 restore |
| raw profile helper start | zero code/data start xrefs | retained/dead source body, not active mode |

The indirect external activation caller is represented by the GeneralPurposePanel2/Pane virtual contract, not a rel32 edge to this target. No false direct caller should be invented.

## Documentation Evidence And IDA Status

- Historical pre-callback target state had valid range, owner/emitter, parser caller, and split parent but stale title, Item Summary, role, blank-C++ blocker, and score. UID0003QZ now carries the implemented OnActivate identity, `92/94`, exact evidence, and R1.
- Historical UID0001HK omitted the complete raw profile helper and treated the gap as implicit space between ShowSpelled/ShowLegend. It now includes UID0004NA and exact pads; relative `Nested:0` remains unchanged because Nested is an address-sorted relative delta, not a child count.
- Historical UID0000CV was a partial class skeleton containing only SpelledPane/LegendPane pointers. It now contains exact R2, ProfilePane, all data fields, exact `0xd90` extent, and class closure before `[[CHILDREN]]`.
- UID0000NL retains the correct `NexusTK/ui/panels/SelfLookPane.cpp` route and now carries the resolved target/raw-child/source/compiler inventory while preserving the original-physical-file confidence cap.
- UID00038M/UID00038N retain exact table boundaries and stores and now identify `+0x48` as OnActivate. UID00038N uses only a compiler no-code comment; no table is manually emitted.
- UID0003R9/UID0003RA retain valid ranges, scores, routes, and callers; their target links and mode-specific field/caller prose are synchronized.
- UID0004N5 remains `92/94` parser source with unchanged route/body and corrected caller-title/fixed-buffer prose.
- Evidence-time generated command `000000010575` emitted the historical UID0003QZ Empty Emitter Marker; that observation is timestamped pre-callback evidence only. B003 terminal command `000000010669` emitted R1/R3 and the UID00038N compiler note with no UID0003QZ/UID00038N marker. Later externally owned command `000000010686` was observed read-only with the same target-specific emissions and zero such markers.

## Ranked Ownership Analysis

| Rank | Candidate | Assessment |
| ---: | --- | --- |
| 1 | UID0000CV `SelfLookPane2` | Accepted. Exact primary vtable slot, receiver layout, sibling methods, and class fields prove direct method ownership. |
| 2 | UID0000NL `SelfLookPane.cpp` | Accepted as source-file route, not direct method owner/emitter. |
| 3 | UID0000DK `SpelledPane` | Dependency only. Owns UID0004N5 parser called by target. |
| 4 | UID000074 `LegendPane` | Dependency only. Owns rich-text child methods. |
| 5 | ProfilePane | Dependency only. Explains raw helper receiver at `+0x100`; does not own SelfLookPane2 view switch. |
| 6 | UserStatusPane / LivingObjectPane / PacketBuffer | API/global dependencies only. |
| 7 | GeneralPurposePanel2 | Indirect activation dispatcher only. |
| 8 | Broad UID0001HK or vtable pages | Inventory/type evidence only; not source emitters for the method body. |

## Source Placement

- Direct owner/emitter: UID0000CV `SelfLookPane2`.
- File route: UID0000NL, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/panels/"`, generated file `NexusTK/ui/panels/SelfLookPane.cpp`.
- Target/new raw child optional position: blank, matching existing class child policy.
- Target/new raw child `Nested:0`; parent UID0001HK remains `Nested:0`.
- This is first-party NexusTK source. No `third_party_embeds/` import directive applies.

## Range / Split / Padding / Reclassification Analysis

- UID0003QZ remains exactly one modeled method. No internal child split is accepted.
- Preserve predecessor padding `[0x005700d7,0x005700e0)` and successor padding `[0x0057092c,0x00570930)` as parent-only ignored alignment; neither belongs to target bytes.
- Add raw profile child `[0x00570e20,0x00570eef)` between existing UID0003R9 and UID0003RA. Preserve `[0x00570e17,0x00570e20)` and `[0x00570eef,0x00570ef0)` as parent-only padding.
- Reclassify only the target title/role, not owner/emitter or range. Reclassify the raw profile body from omitted gap to retained source-shaped child.
- Preserve all existing children, raw toggle helpers, null stub, hit-test switch/table tail, parent range, and relative nesting.

## Negative Evidence Summary

- No draw primitive, resource-frame draw, clip, fill, blit, or text-render operation occurs in target; `OnDraw` is false.
- No direct code caller exists; no standalone packet dispatcher ownership follows.
- No internal target address is a separate modeled source function.
- No profile-mode value 3 branch or call exists in target.
- No constructor write initializes `m_profilePane` at `+0x100`; do not hide this historical/dormant caveat.
- No raw profile helper start xref/pointer/branch route exists.
- No target use initializes or owns UID000284 parser delimiter state.
- No exact original symbols distinguish the three leading state bytes, BE32 state value, or final tail dwords.
- No broad allocation search proved `sizeof(SelfLookPane2)==0xd90`; size rests on complete field extent/natural alignment evidence.
- No evidence supports moving SelfLookPane2 to UserLookPane.cpp, SpelledPane.cpp, ProfilePane.cpp, PacketBuffer, or GeneralPurposePanel.

## IDA Rename / Type / Comment Recommendations

- Validator-preserving document rename: `SelfLookPane2OnDraw` -> `SelfLookPane2OnActivate`, same UID/range.
- If IDA mutation is separately authorized outside this report, rename `sub_5700E0` to `SelfLookPane2__OnActivate` and type it `void __thiscall SelfLookPane2::OnActivate(const unsigned char *packetData)`.
- If separately authorized, model `0x00570e20-0x00570eef` as `SelfLookPane2__ShowProfileView_Raw` only after preserving its no-xref/raw provenance. This report does not mutate IDA.
- Prefer `unsigned char`, `unsigned short`, and `unsigned int` for packet/storage ABI. Use `wchar_t[256]`/`wchar_t[128]` exactly as laid out.
- Use descriptive field comments in documentation tables only. Do not emit raw offset, provisional, inferred, or reverse-engineering audit comments inside formal C++.

## First-Draft C++ Recommendation

### R1 - renamed UID0003QZ target

Destination: `by-memory/0x005700e0-0x0057092c.SelfLookPane2OnActivate.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
namespace
{
static __forceinline unsigned char ReadSelfLookPane2Text(
    const unsigned char *packetData,
    int &offset,
    char *multibyteText,
    wchar_t *text,
    int capacity)
{
    const unsigned char byteCount = packetData[offset++];
    memmove(multibyteText, packetData + offset, byteCount);
    multibyteText[byteCount] = 0;
    const unsigned char length = static_cast<unsigned char>(
        MultiByteToWideChar(CP_ACP,
                            0,
                            multibyteText,
                            byteCount,
                            text,
                            capacity));
    text[length] = 0;
    offset += byteCount;
    return length;
}
}

void SelfLookPane2::OnActivate(const unsigned char *packetData)
{
    int offset = 1;
    wchar_t identityLine1[256];
    wchar_t statusLineA[256];
    wchar_t auxiliaryText[256];
    wchar_t statusLineB[256];
    wchar_t spelledText[256];
    wchar_t legendText[256];
    char multibyteText[256];

    m_activationState0 = packetData[offset++];
    m_activationState1 = packetData[offset++];
    m_activationState2 = packetData[offset++];

    ReadSelfLookPane2Text(packetData,
                          offset,
                          multibyteText,
                          identityLine1,
                          256);

    const unsigned char identityLine2ByteCount = packetData[offset++];
    const int identityLine2Length =
        MultiByteToWideChar(CP_ACP,
                            0,
                            reinterpret_cast<const char *>(packetData + offset),
                            identityLine2ByteCount,
                            m_identityLine2,
                            255);
    m_identityLine2[identityLine2Length] = 0;
    offset += identityLine2ByteCount;

    ReadSelfLookPane2Text(packetData,
                          offset,
                          multibyteText,
                          statusLineA,
                          256);
    g_activeUserStatusPane->SetDisplayLineA(statusLineA);

    ReadSelfLookPane2Text(packetData,
                          offset,
                          multibyteText,
                          auxiliaryText,
                          256);
    m_equipmentToggleState = packetData[offset++];

    m_activationValue = PacketBufferReadUInt32BE(packetData + offset);
    offset += 4;

    ReadSelfLookPane2Text(packetData,
                          offset,
                          multibyteText,
                          statusLineB,
                          256);
    g_activeUserStatusPane->SetDisplayLineB(statusLineB);

    const unsigned short headId = PacketBufferReadUInt16BE(packetData + offset);
    offset += 2;
    const unsigned char headPalette = packetData[offset++];

    const unsigned short leftAccessoryId =
        PacketBufferReadUInt16BE(packetData + offset);
    offset += 2;
    const unsigned char leftAccessoryPalette = packetData[offset++];

    const unsigned short rightAccessoryId =
        PacketBufferReadUInt16BE(packetData + offset);
    offset += 2;
    const unsigned char rightAccessoryPalette = packetData[offset++];

    const unsigned short leftSubAccessoryId =
        PacketBufferReadUInt16BE(packetData + offset);
    offset += 2;
    const unsigned short rightSubAccessoryId =
        PacketBufferReadUInt16BE(packetData + offset);
    offset += 2;
    const unsigned char leftSubAccessoryPalette = packetData[offset++];
    const unsigned char rightSubAccessoryPalette = packetData[offset++];

    const unsigned char spelledLength =
        ReadSelfLookPane2Text(packetData,
                              offset,
                              multibyteText,
                              spelledText,
                              256);
    for (unsigned char index = 0; index < spelledLength; ++index)
    {
        if (spelledText[index] == L'\t')
            spelledText[index] = L'\n';
    }

    m_lookToggleState = packetData[offset++];
    m_statsToggleState = packetData[offset++];

    g_pLocalPlayer->GetSpriteConfig(&m_spriteConfig);

    m_headId = headId;
    m_headPalette = headPalette;
    m_leftAccessoryId = leftAccessoryId;
    m_leftAccessoryPalette = leftAccessoryPalette;
    m_rightAccessoryId = rightAccessoryId;
    m_rightAccessoryPalette = rightAccessoryPalette;
    m_leftSubAccessoryId = leftSubAccessoryId;
    m_rightSubAccessoryId = rightSubAccessoryId;
    m_leftSubAccessoryPalette = leftSubAccessoryPalette;
    m_rightSubAccessoryPalette = rightSubAccessoryPalette;

    wcscpy_s(m_identityLine1, 256, identityLine1);
    wcscpy_s(m_statusLineA, 256, statusLineA);
    wcscpy_s(m_statusLineB, 128, statusLineB);
    g_activeUserStatusPane->CopyNameLineA(m_statusName, 128);
    m_displayValueA = g_activeUserStatusPane->GetDisplayValueA();
    m_displayValueB = g_activeUserStatusPane->GetDisplayValueB();
    wcscpy_s(m_auxiliaryText, 256, auxiliaryText);
    wcscpy_s(m_spelledSourceText, 256, spelledText);

    m_spelledPane->ParseAndLoadEntries(m_spelledSourceText,
                                       static_cast<int>(wcslen(m_spelledSourceText)));

    m_legendPane->ClearText();
    m_legendPane->SetEditActiveState(true, false);

    const unsigned short legendEntryCount =
        PacketBufferReadUInt16BE(packetData + offset);
    offset += 2;
    short legendTextOffset = 0;

    for (unsigned short entry = 0; entry < legendEntryCount; ++entry)
    {
        const unsigned char symbolIndex = packetData[offset++];
        const unsigned char textColor = packetData[offset++];
        short legendLength =
            ReadSelfLookPane2Text(packetData,
                                  offset,
                                  multibyteText,
                                  legendText,
                                  256);
        legendText[legendLength++] = L'\r';
        legendText[legendLength] = 0;

        EPFTextEditObject *symbol =
            new EPFTextEditObject(m_legendPane, symbolIndex);
        m_legendPane->InsertText(L" ", 0);
        m_legendPane->InsertEmbeddedObject(symbol, 12, 12);

        const short textStart = static_cast<short>(legendTextOffset + 2);
        m_legendPane->SetText(legendText, legendLength, 0, 0);
        const short textEnd = static_cast<short>(textStart + legendLength);

        unsigned int formatData[3] = { 0, textColor, 0 };
        m_legendPane->SetSelectionRange(textStart, textEnd);
        m_legendPane->ApplySelectionFormat(2, formatData);
        m_legendPane->SetSelectionRange(textEnd, textEnd);
        legendTextOffset = textEnd;
    }

    m_legendPane->SetEditActiveState(false, false);
    m_profileState = 0;

    m_spelledPane->RemoveFromLayer();
    m_spelledPane->UnregisterEventHandler();
    m_legendPane->RemoveFromLayer();
    m_legendPane->UnregisterEventHandler();
    m_spelledPane->RefreshScrollState();

    if (m_viewMode == ViewMode_Spelled)
        ShowSpelledView();
    else if (m_viewMode == ViewMode_Legend)
        ShowLegendView();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

R1 deliberately uses existing source-facing APIs. The exact binary evidence immediately behind `RefreshScrollState()` is FrameHandler remove followed by schedule-next-frame on the SpelledPane `+0x174` handler view. The abstraction is retained because it is the accepted human source form and can inline to that order.

### R2 - UID0000CV SelfLookPane2 class

Destination: `by-class/SelfLookPane2.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class SelfLookPane2 : public PanelPane
{
public:
    enum ViewMode
    {
        ViewMode_Default = 0,
        ViewMode_Spelled = 1,
        ViewMode_Legend = 2
    };

    SelfLookPane2();
    virtual ~SelfLookPane2();

    virtual void OnActivate(const unsigned char *packetData);
    virtual bool OnPaint();
    virtual bool HandleKeyEvent(const PanelKeyEvent *event);
    virtual bool HandleEvent(const PanelMouseEvent *event);
    virtual bool OnPacketEvent(const PanelPacketEvent *event);

    void ShowDefaultView();
    void ShowSpelledView();
    void ShowProfileView();
    void ShowLegendView();
    void DrawStatText();
    void GetButtonRect(int buttonId, RectBounds *bounds) const;
    unsigned short HitTestButton(int x, int y) const;

private:
    unsigned char *m_statDigitFrames;
    SpelledPane *m_spelledPane;
    ProfilePane *m_profilePane;
    LegendPane *m_legendPane;
    LivingSpriteConfig m_spriteConfig;

    unsigned short m_headId;
    unsigned char m_headPalette;
    unsigned short m_leftAccessoryId;
    unsigned char m_leftAccessoryPalette;
    unsigned short m_rightAccessoryId;
    unsigned char m_rightAccessoryPalette;
    unsigned short m_leftSubAccessoryId;
    unsigned short m_rightSubAccessoryId;
    unsigned char m_leftSubAccessoryPalette;
    unsigned char m_rightSubAccessoryPalette;

    wchar_t m_identityLine1[256];
    wchar_t m_identityLine2[256];
    wchar_t m_statusLineA[256];
    wchar_t m_statusLineB[128];
    wchar_t m_statusName[128];
    unsigned int m_displayValueA;
    unsigned int m_displayValueB;
    unsigned char m_activationState0;
    unsigned char m_activationState1;
    unsigned char m_activationState2;
    unsigned int m_activationValue;
    unsigned int m_lastToggleTick;
    unsigned int m_toggleRepeatDelay;
    unsigned char m_equipmentToggleState;
    unsigned char m_lookToggleState;
    unsigned char m_statsToggleState;
    wchar_t m_auxiliaryText[256];
    wchar_t m_spelledSourceText[256];
    int m_viewMode;
    int m_profileState;
    int m_reservedViewState;
    int m_buttonFrameA;
    int m_buttonFrameB;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

R2 contains no explicit padding members. Old 32-bit MSVC natural alignment supplies the one-byte holes after the first three palette bytes, after the three activation bytes, and after the three toggle bytes. The class must close before `[[CHILDREN]]` so all child method definitions emit at namespace scope.

### R3 - new raw ShowProfileView child

Destination: [UID:0004NA] `by-memory/0x00570e20-0x00570eef.SelfLookPane2ShowProfileViewRaw.md`, serially assigned by validator command `000000010607`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void SelfLookPane2::ShowProfileView()
{
    m_legendPane->RemoveFromLayer();
    m_legendPane->UnregisterEventHandler();
    m_spelledPane->RemoveFromLayer();
    m_spelledPane->UnregisterEventHandler();

    m_profilePane->UnregisterEventHandler();
    m_profilePane->RemoveFromLayer();

    RectBounds profileBounds;
    InitRectBounds(&profileBounds, 17, 36, 174, 131);

    const unsigned short currentPosition =
        m_profilePane->GetScrollPosition(0);
    m_profilePane->ApplyScrollPosition(0, currentPosition, 0);
    m_profilePane->AddToLayer(&profileBounds,
                              0,
                              this,
                              g_mainUiLayerSlots.rootPaneLayerContext);
    m_profilePane->SetPaneOrder(0, this);
    InvalidateRect(&m_bounds);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

R3 intentionally does not write `m_viewMode`: no such store exists in the raw bytes. It also does not add a public mode-3 branch or constructor initialization for `m_profilePane`; both would invent behavior.

## Exact Class Layout

| Offset | Size | Source-facing field/type | Exact evidence and caveat |
| --- | ---: | --- | --- |
| inherited `+0x000..+0x0f7` | `0xf8` | `PanelPane` | Constructor/base/vtable family. |
| `+0x0f8` | 4 | `unsigned char *m_statDigitFrames` | Resource lookup id 99; OnPaint/stat use; destructor frees. Exact lexical type is descriptive. |
| `+0x0fc` | 4 | `SpelledPane *m_spelledPane` | Constructor, parser, view helpers, destructor. |
| `+0x100` | 4 | `ProfilePane *m_profilePane` | Raw ShowProfile helper only; constructor omission/no-route caveat retained. |
| `+0x104` | 4 | `LegendPane *m_legendPane` | Constructor, target rich text, view helpers, destructor. |
| `+0x108` | `0x44` | `LivingSpriteConfig m_spriteConfig` | Exact 68-byte getter copy; ends at `+0x14c`. |
| `+0x14c/+0x14e` | 2/1 | head id/palette | Selector 4; natural pad at `+0x14f`. |
| `+0x150/+0x152` | 2/1 | left accessory id/palette | Selector 7; natural pad at `+0x153`. |
| `+0x154/+0x156` | 2/1 | right accessory id/palette | Selector 8; natural pad at `+0x157`. |
| `+0x158/+0x15a/+0x15c/+0x15d` | 2/2/1/1 | left/right sub ids and palettes | Selectors 20/21; packed exact order. |
| `+0x15e` | `0x200` | `wchar_t m_identityLine1[256]` | First packet text. |
| `+0x35e` | `0x200` | `wchar_t m_identityLine2[256]` | Second packet text converted directly into member. |
| `+0x55e` | `0x200` | `wchar_t m_statusLineA[256]` | First UserStatus display text snapshot. |
| `+0x75e` | `0x100` | `wchar_t m_statusLineB[128]` | Second display text snapshot. |
| `+0x85e` | `0x100` | `wchar_t m_statusName[128]` | `CopyNameLineA` destination. |
| `+0x95e` | 2 | natural alignment | No explicit source field. |
| `+0x960/+0x964` | 4/4 | display values A/B | UserStatus dword getters. |
| `+0x968..+0x96a` | 3 | activation state bytes | packet[1..3], descriptive names. |
| `+0x96b` | 1 | natural alignment | No explicit source field. |
| `+0x96c` | 4 | activation value | BE32 packet field. |
| `+0x970/+0x974` | 4/4 | last toggle tick/repeat delay | Constructor/toggle helper consumers; delay initialized 1000. |
| `+0x978..+0x97a` | 3 | equipment/look/stats toggle states | Raw subtype 02/08/0B helpers prove mapping. |
| `+0x97b` | 1 | natural alignment | No explicit source field. |
| `+0x97c` | `0x200` | auxiliary text[256] | Fourth text sequence. |
| `+0xb7c` | `0x200` | spelled source text[256] | TAB-to-LF conversion and UID0004N5 source. |
| `+0xd7c` | 4 | view mode | Exact active values 0/1/2. |
| `+0xd80` | 4 | profile state | Constructor/target clear. Exact lexical meaning capped. |
| `+0xd84` | 4 | reserved view state | No observed read/write in checked family; retained to close exact extent. |
| `+0xd88/+0xd8c` | 4/4 | button frame state A/B | Constructor/OnPaint consumers. Descriptive names. |
| extent `+0xd90` |  | complete natural size | Highest field end; decimal 3472. |

Source access control: activation/paint/event methods must remain virtual and callable through the Pane interface. View/draw/geometry helpers can be public in the first-draft class because existing generated child definitions and current project convention expose them; data fields remain private. No external source directly accesses the new fields.

## Final Recommendation

The accepted C01-C20/R1-R3 implementation is complete. UID0003QZ is now OnActivate because retaining `OnDraw` would preserve a provably false virtual contract. Target behavior is implemented at `92/94`; remaining uncertainty is limited to original lexical spelling of opaque state fields and the physical source filename.

Implementation order was preserved: command `000000010607` registered UID0004NA before parent/class/file/report links were added. No other child, profile mode, duplicate parser body, manual vtable data, or explicit padding field was created.

## Recommended Target Doc Changes

Accepted callback specification, now applied and validated:

- Validator-preserving rename to `by-memory/0x005700e0-0x0057092c.SelfLookPane2OnActivate.md`, UID0003QZ unchanged.
- Set `COMPLETION:92`, `CONFIDENCE:94`; preserve owner/emitter UID0000CV, true, blank position, `Nested:0`.
- Item Summary: `Primary +0x48 SelfLookPane2 OnActivate override; exact 0x84c/2124-byte packet parser populates 0xd90 object state, LivingSpriteConfig/equipment/status/toggle fields, SpelledPane and LegendPane content, preserves mode-0 no-switch behavior, restores spelled/legend views, and emits complete source C++ with compiler SEH/range-check lowering excluded.`
- Insert R1 exactly and add all range/hash/CFG/vtable/packet/field/layout/callee/negative/source/compiler evidence from this report.
- Historicalize the former draw/update label and blank-C++ blockers; preserve executed UID000284 caller provenance as bounded prior support.

## Recommended Support Doc Changes

| Destination | Accepted change and implemented result |
| --- | --- |
| `by-memory/0x0056fe80-0x005729c3.SelfLookPane2.md` UID0001HK | `88/90 -> 89/92`; retain false/blank owner UID0000CV/Nested0; rename target row; add raw-profile child/padding rows; exhaustive child order and no-emission policy. |
| `by-class/SelfLookPane2.md` UID0000CV | `89/91 -> 92/93`; install R2; add exact layout table, packet/view/helper history, raw profile caveat, compiler exclusions, and target/new-child links. |
| `by-file/SelfLookPane.md` UID0000NL | `88/91 -> 90/92`; update SelfLookPane2 inventory, OnActivate route, omitted raw helper, source/compiler split, and historical title correction. |
| `by-type/by-vtable/SelfLookPaneFamilyVtables.md` UID00038M | `87/91 -> 89/93`; name SelfLookPane2 primary `+0x48` OnActivate, retain compiler no-code/blank formal and same owner/emitter route. |
| `by-memory/0x006246f4-0x00624780.SelfLookPane2VtableData.md` UID00038N | `89/92 -> 90/94`; record cell `0x00624740 -> UID0003QZ OnActivate`, exact slot contract, stores/bounds, no manual arrays; preserve owner/emitter/blank position/Nested0/formal. |
| `by-memory/0x00570c80-0x00570e17.SelfLookPane2ShowSpelledView.md` UID0003R9 | Score/route unchanged; replace target link/title and add mode-1/field/caller contract. |
| `by-memory/0x00570ef0-0x00570fb3.SelfLookPane2ShowLegendView.md` UID0003RA | Score/route unchanged; replace target link/title and add mode-2/field/caller contract. |
| `by-memory/0x0056c0e0-0x0056c2db.SpelledPaneParseAndLoadEntries.md` UID0004N5 | Score/route/body unchanged; rename caller link and preserve exact fixed-buffer consumer facts. |
| `by-memory/0x00570e20-0x00570eef.SelfLookPane2ShowProfileViewRaw.md` UID0004NA | Registered at `89/92`, owner/emitter UID0000CV, true, blank position, Nested0, R3, exact 207-byte SHA256/bounds/endpoint bytes/no-route/constructor-omission/profile-layout evidence. |
| GeneralPurposePanel2, UserStatusPane, LivingObjectPane, PacketBuffer, TextEditPane, SpelledPane, LegendPane, ProfilePane support | Verify-only unless exact current link/title prose needs bounded synchronization; preserve scores, routes, bodies, and unrelated detail. |

Exact support metadata preservation is part of C18: UID0001HK remains owner UID0000CV, non-reconstructable, blank emitter/position/formal C++, `Nested:0`; UID0000CV remains owner/emitter UID0000NL, reconstructable, blank position; UID0000NL remains `CANONICAL_OWNER:FILE` with path `NexusTK/ui/panels/`; UID00038M remains owner/emitter UID0000NL, reconstructable, blank position/formal C++; and UID00038N remains owner/emitter UID00038M, reconstructable, blank position, `Nested:0`, with one comment-only compiler no-code line instead of a false generated Empty Emitter Marker. Only the reported scores, title/link synchronization, evidence, R2 class body, and bounded UID00038N no-code comment changed on those existing destinations.

Use these exact Item Summary values for score-changing support pages:

- UID0001HK: `Non-emitting SelfLookPane2 method-span index with corrected primary +0x48 OnActivate role, exact constructor/destructor/activation/view/paint/input/packet/stat/button inventory, complete 0xd90 layout, retained raw ShowProfileView child, all internal padding, compiler exclusions, and child-only source emission through UID0000CV.`
- UID0000CV: `Complete PanelPane-derived 0xd90 SelfLookPane2 declaration with exact natural field layout, primary +0x48 OnActivate signature/body route, resource/Spelled/Profile/Legend pointers, LivingSpriteConfig/equipment/status/toggle/text/view fields, exact method inventory, retained raw profile helper, vtable/source/compiler evidence, class closure before child definitions, and descriptive-name confidence caps.`
- UID0000NL: `NexusTK/ui/panels/SelfLookPane.cpp source family with exact SelfLookPane/SelfLookPane2 splits, complete SelfLookPane2 OnActivate and 0xd90 declaration, retained raw ShowProfileView helper, corrected primary-vtable contract, SpelledPane/LegendPane/ProfilePane dependencies, packet/status/equipment/view behavior, vtable/compiler exclusions, and preserved original-physical-file confidence cap.`
- UID00038M: `Source-local SelfLookPane/SelfLookPane2 vtable family with exact table ranges/stores, SelfLookPane2 primary cell 0x00624740 -> UID0003QZ OnActivate, sibling +0x48 contract, compiler-generated no-manual-array disposition, blank formal C++, and unchanged UID0000NL route.`
- UID00038N: `Exact 0x006246f4-0x00624780 SelfLookPane2 RTTI/COL and three-view vtable data with constructor/cleanup/scalar-destructor stores, primary cell 0x00624740 -> UID0003QZ OnActivate, CollectionPane2/LineIterator boundaries, compiler-generated no-manual-array disposition, and unchanged UID00038M route.`
- UID0004NA raw child: `Exact 0x00570e20-0x00570eef retained 207-byte/SHA256-anchored SelfLookPane2 ShowProfileView source body with no modeled function or route, exact child detach/unregister order, ProfilePane pointer at +0x100, (17,36,174,131) bounds, vertical current-to-zero scroll application, root-layer attach, pane order, invalidation, adjacent padding, constructor-omission caveat, and complete R3 without a false mode-3 store.`

## Score And Metadata Recommendation

| Destination | Historical pre-callback | Implemented | Rationale |
| --- | ---: | ---: | --- |
| UID0003QZ target | `86/89` | `92/94` | Complete body, signature, slot, callers, fields, packet layout, children, range, and C++ resolved. |
| UID0001HK parent | `88/90` | `89/92` | Corrected child role and omitted raw body complete the split inventory; parent remains non-emitting. |
| UID0000CV class | `89/91` | `92/93` | Exact declaration/layout/size/field/access model and target/raw child now resolved. |
| UID0000NL file | `88/91` | `90/92` | Major SelfLookPane2 activation/layout/source gap closes while original filename remains inferred. |
| UID00038M vtable family | `87/91` | `89/93` | Key slot now has exact source contract; compiler no-code policy remains. |
| UID00038N exact vtable | `89/92` | `90/94` | Exact target cell and OnActivate identity close key slot ambiguity. |
| UID0004NA raw child | nonexistent | `89/92` | Complete source body and class owner; no route and uninitialized pointer cap score. |
| UID0003R9/3RA/4N5 and verify-only APIs | unchanged | unchanged | Bounded link/caller sync does not complete their broader source bodies. |

## Open Questions With Attempted Resolution

| Question | Checks performed | Resolution |
| --- | --- | --- |
| Is target really draw code? | Full body/callees, sibling vtables, dispatcher contract | No. Rename to OnActivate. |
| Does packet pointer need an Event wrapper? | ABI, slot comparator, direct byte reads | No. Exact source parameter is const unsigned byte pointer. |
| Are opaque leading bytes named? | All parent-range consumers and docs | Exact types/storage are known; use descriptive activation-state names, confidence cap only. |
| Is `+0x100` padding? | Raw range decode, all dereferences, sibling ProfilePane | No. It is `ProfilePane *m_profilePane`. |
| Is raw profile helper live? | function/xref/pointer/branch scans | No route found; retain source-shaped body with explicit caveat. |
| Should view mode add Profile=3? | target/raw/helper writes and callers | No. No evidence. |
| Is `0xd90` directly allocation-proven? | bounded caller/constructor searches | No allocation immediate; exact field extent/natural alignment still supports layout size. |
| Should frame calls be emitted directly? | generic FrameHandler helpers, accepted pane APIs, sibling source | Use human `RefreshScrollState()` and preserve direct remove/schedule order in evidence. |
| Does target own parser/delimiter? | UID0004N5/000284 callers and source route | No; target is a consumer only. |
| Does target need a split for range failure or SEH? | CFG/body/EH graph | No; compiler lowering only. |
| Is original physical file proved? | class/file/vtable/generated/resource searches | Current route is strongest; filename remains high-confidence project placement, not symbol fact. |
| Does any unresolved point block R1-R3? | all above plus source API declarations | No. Remaining uncertainty is lexical/liveness confidence only. |

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

B003 did not edit manual coverage or tracker files. The replacement/addition rows below are exact and current for external synchronization after the accepted callback, including the serially validator-issued UID0004NA raw-child row.

Replace the UID0001HK row in `by-memory/-coverage-report.md` with:

```text
    - [UID:0001HK][0x0056fe80-0x005729c3.SelfLookPane2](by-memory/0x0056fe80-0x005729c3.SelfLookPane2.md) 0x0056fe80-0x005729c3 | non-emitting class-method split index | SelfLookPane2 : not_reconstructable : 89% : very-strong : Exact SelfLookPane2 constructor/destructor/OnActivate/view/paint/input/packet/stat/button/raw-helper inventory with corrected primary +0x48 OnActivate role, complete 0xd90 layout, retained raw ShowProfileView child, all internal padding, compiler exclusions, and exact child-only source emission through SelfLookPane2.
```

For external supervisor-owned coverage synchronization, insert the renamed target and UID0004NA raw child beneath that parent in address order:

```text
        - [UID:0003QZ][0x005700e0-0x0057092c.SelfLookPane2OnActivate](by-memory/0x005700e0-0x0057092c.SelfLookPane2OnActivate.md) 0x005700e0-0x0057092c | virtual method | SelfLookPane2OnActivate : reconstructable : 92% : very-strong : Exact primary +0x48 OnActivate override with 0x84c/2124-byte hash/bounds, packet text/state/equipment/status/toggle parsing, 68-byte LivingSpriteConfig, SpelledPane parser call, LegendPane rich-text rows, child lifecycle, mode restore, compiler exclusions, complete 0xd90 field mapping, and formal C++.
        - [UID:0004NA][0x00570e20-0x00570eef.SelfLookPane2ShowProfileViewRaw](by-memory/0x00570e20-0x00570eef.SelfLookPane2ShowProfileViewRaw.md) 0x00570e20-0x00570eef | retained raw source helper | SelfLookPane2ShowProfileViewRaw : reconstructable : 89% : very-strong : Exact 207-byte/SHA256-anchored no-function/no-xref ProfilePane view helper with child detach/unregister order, (17,36,174,131) bounds, vertical scroll reset, root-layer attach, pane ordering, invalidation, constructor-omission caveat, and complete formal C++ without inventing a live mode-3 route.
```

Insert the exact UID00038N child beneath UID0002V1 in the `0x006245dc-0x00624788` address-sorted portion of `by-memory/-coverage-report.md`:

```text
            - [UID:00038N][0x006246f4-0x00624780.SelfLookPane2VtableData](by-memory/0x006246f4-0x00624780.SelfLookPane2VtableData.md) 0x006246f4-0x00624780 | vtable-data | SelfLookPane2VtableData : reconstructable : 90% : very-strong : Exact SelfLookPane2 RTTI/COL and primary/secondary/tertiary vtable-data interval with boundaries at CollectionPane2 and LineIterator, constructor/cleanup/scalar-destructor store refs, primary cell 0x00624740 -> UID0003QZ OnActivate, compiler-generated no-manual-array disposition, and unchanged source-local UID00038M parent route.
```

Replace the UID0000CV row in `by-class/-coverage-report.md` with:

```text
- [UID:0000CV][SelfLookPane2](by-class/SelfLookPane2.md) : reconstructable : 92% : very-strong : Complete PanelPane-derived 0xd90 SelfLookPane2 declaration with exact natural field layout, primary +0x48 OnActivate signature/body route, resource/Spelled/Profile/Legend pointers, LivingSpriteConfig/equipment/status/toggle/text/view fields, exact method inventory, retained raw profile helper, vtable/source/compiler evidence, class closure before child definitions, and descriptive-name confidence caps.
```

Replace the UID0000NL row in `by-file/-coverage-report.md` with:

```text
- [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md) : reconstructable : 90% : very-strong : `NexusTK/ui/panels/SelfLookPane.cpp` source family with exact SelfLookPane/SelfLookPane2 splits, complete SelfLookPane2 OnActivate and 0xd90 declaration, retained raw ShowProfileView helper, corrected primary-vtable contract, SpelledPane/LegendPane/ProfilePane dependencies, packet/status/equipment/view behavior, vtable/compiler exclusions, and preserved original-physical-file confidence cap.
```

Replace the UID00038M row in `by-type/by-vtable/-coverage-report.md` with:

```text
- [UID:00038M][SelfLookPaneFamilyVtables](by-type/by-vtable/SelfLookPaneFamilyVtables.md) : reconstructable : 89% : very-strong : Source-local SelfLookPane/SelfLookPane2 vtable layout with exact table ranges/stores, corrected SelfLookPane2 primary +0x48 OnActivate cell 0x00624740 -> UID0003QZ, sibling slot contract, compiler-generated no-manual-array disposition, and unchanged SelfLookPane.cpp owner/emitter route.
```

## Follow-Up Actions

- C01-C20 and R1-R3 were applied after supervisor authorization using the validator-preserving rename and serial new-file workflow; no B003 implementation item remains.
- Every changed/new/renamed ordinary page has scoped validator proof below. B003's final waited command `000000010669` supplies callback generated readback and header freshness; the later current shared header from externally owned command `000000010686` was checked read-only and preserves the same target-specific structure.
- B003 did not edit manual coverage/tracker content. Exact existing-UID and real-UID0004NA synchronization rows are supplied above for external supervisor-owned use.
- Report validation/execution/count/path/move/archive state remains external supervisor/validator-owned and is neither asserted nor directed by this artifact.

## Confidence

Overall recommendation confidence is `94/100`. Function bytes, range, hash, ABI, vtable cell, packet cursor, class offsets, callee roles, view branches, parser call, legend loop, and raw profile body are current IDB facts. Remaining uncertainty is limited to original field/helper spelling, original physical filename, raw-profile liveness, constructor omission intent, and direct allocation proof for the naturally closed `0xd90` extent. Those points cap scores but do not block source C++.

## Validator Results

- Historical report-only phase: no implementation validator was run before Gate 1. Evidence-time generated command `000000010575` remains explicitly historical pre-callback evidence.
- Every command below ran from `source-3/project-documentation` with `--mode file --apply --queue-timeout 240`; every listed command exited `0` with `ok:1`. All abbreviated times are exact local timestamps on `2026-07-14` with offset `-04:00`. Missing-UID diagnostics shown by several legacy pages were pre-existing validator-registry warnings and did not reject the scanned destination.

| Destination / purpose | Command ID(s), timestamp(s) | Result and side effects |
| --- | --- | --- |
| UID0003QZ validator-preserving rename and final target passes | `000000010601` at `03:21:03`; `000000010643` at `03:35:08`; `000000010666` at `03:43:28`; `000000010668` at `03:45:05` | Rename preserved UID/path mapping, updated seven reference-source paths and parser link, applied `92/94`/R1, then validated exact Item Summary, corrected hash, and durable MCP evidence. All exit 0/`ok:1`; generated refresh deferred. |
| UID0004NA serial registration/final child | `000000010607` at `03:22:31`; `000000010658` at `03:38:25` | Allocated real UID0004NA, registered `89/92`, owner/emitter UID0000CV, R3, and reference indices; final exact Item Summary/link normalization passed. |
| UID0001HK parent | `000000010612` at `03:23:56`; `000000010644` at `03:35:36` | Applied `89/92`, inventory/padding/UID0004NA links and exact Item Summary; completion/confidence/reference indices refreshed. |
| UID0000CV class | `000000010619` at `03:25:48`; `000000010645` at `03:36:03` | Applied `92/93`, exact R2/layout/prose/Item Summary; autogen code hash and target/raw-child references refreshed. |
| UID0000NL file | `000000010628` at `03:28:18`; `000000010646` at `03:36:26` | Applied `90/92`, source/compiler inventory and exact Item Summary; completion/confidence/reference indices refreshed. |
| UID00038M vtable family | `000000010630` at `03:29:18`; `000000010647` at `03:37:12` | Applied `89/93`, exact primary-slot/compiler evidence and Item Summary; registry/reference route refreshed. |
| UID00038N exact vtable | `000000010634` at `03:30:10`; `000000010652` at `03:37:49`; `000000010664` at `03:41:46` | Applied `90/94`, exact slot/stores/bounds/Item Summary; final bounded repair changed only blank code state to one compiler no-code comment, suppressing the false Empty Emitter Marker without emitting arrays. |
| UID0003R9 / UID0003RA view supports | `000000010635` at `03:31:20`; `000000010637` at `03:32:06` | Added exact OnActivate mode-1/mode-2 caller/field contracts; scores/routes/formals unchanged. |
| UID0004N5 parser support | `000000010639` at `03:32:37` | Added exact OnActivate fixed-buffer/TAB-to-LF consumer contract; score/route/body unchanged. |
| SpelledPane file/class bounded supports | `000000010641` at `03:33:19`; `000000010642` at `03:33:56` | Corrected only stale OnDraw caller statements to OnActivate and added UID link indices; scores/routes/bodies unchanged. |
| Intermediate waited generated checks | `000000010660` at `03:39:31`; `000000010665` at `03:41:57`; `000000010667` at `03:43:40` | All exit 0/`ok:1`; `000000010660` exposed UID00038N's false marker, `000000010665` proved its comment-only correction, and `000000010667` rechecked after exact target-hash repair. These are superseded by the terminal wait. |
| Terminal waited generated verification | `000000010669` at `03:45:18` | Exit 0/`ok:1`; rebuilt `4745` metadata nodes / `3844` edges and refreshed `281` generated metadata destinations. `SelfLookPane.cpp` header is command `000000010669`, timestamp `2026-07-14T03:45:18-04:00`, 929 lines / 33,539 bytes, SHA256 `9356741558BC0C777ACFA312F61F94A604516C6440D9F1B1FBF87CF6380DB8EA`. |
| Later external generated-state observation | `000000010686` at `03:56:22` | Read-only observation, not a B003-issued validator: current `SelfLookPane.cpp` header is command `000000010686`, timestamp `2026-07-14T03:56:22-04:00`, 929 lines / 33,539 bytes, SHA256 `CCC3F8A2D6802D6D0043C7AC8DFD860ED0ACADE66B7C313EEB7888325F1EF2A6`; B003 does not assert that command's unrelated side effects. |

Generated readback captured after B003 command `000000010669`: R2 closes before the first qualified SelfLookPane2 definition; R1 OnActivate count `1`; R3 ShowProfileView count `1`; correct-range UID0003QZ/UID0004NA header count `1` each; stale OnDraw count `0`; UID0003QZ and UID00038N Empty Emitter Marker counts `0`; UID00038N compiler no-code comment count `1`; raw vtable/RTTI array count `0`; 23 UID snippet headers with zero duplicates. Read-only recheck after external command `000000010686` produced the same target-specific counts and structure.

## Changed Files

- UID-preserving rename: historical `by-memory/0x005700e0-0x0057092c.SelfLookPane2OnDraw.md` -> current `by-memory/0x005700e0-0x0057092c.SelfLookPane2OnActivate.md`.
- New registered page: `by-memory/0x00570e20-0x00570eef.SelfLookPane2ShowProfileViewRaw.md` (UID0004NA).
- Changed ordinary pages: `by-memory/0x0056fe80-0x005729c3.SelfLookPane2.md`, `by-class/SelfLookPane2.md`, `by-file/SelfLookPane.md`, `by-type/by-vtable/SelfLookPaneFamilyVtables.md`, `by-memory/0x006246f4-0x00624780.SelfLookPane2VtableData.md`, `by-memory/0x00570c80-0x00570e17.SelfLookPane2ShowSpelledView.md`, `by-memory/0x00570ef0-0x00570fb3.SelfLookPane2ShowLegendView.md`, `by-memory/0x0056c0e0-0x0056c2db.SpelledPaneParseAndLoadEntries.md`, `by-file/SpelledPane.md`, and `by-class/SpelledPane.md`.
- Updated callback artifact: `tools/leaser/Agents/Agent-B003/research/0003QZ-SelfLookPane2OnDraw-source-quality.md`.
- Validator-owned side effects updated registry/projected-stat/generated metadata and generated C++; B003 did not manually edit any generated/coverage/tracker/validator-state file. Manual `-coverage-report.md`, audit/supervisor, IDA, lifecycle, executed-report, and archive files were not edited.

## Implementation Tracking Checklist

Research and callback completion record:

- [x] Supervisor accepted exact report SHA `D6BEDB48F13EBE9FCDDB1E34C1A0950A295285C2BA21B2C15DBE6D864C541E5D` before implementation.
- [x] Re-read every accepted target/support destination immediately after acquiring its one-file lease and before editing.
- [x] Captured mandatory MCP evidence remained materially consistent; exact evidence-time session/health facts were incorporated into UID0003QZ without asserting later availability.
- [x] Performed validator-preserving UID0003QZ rename to `SelfLookPane2OnActivate`; preserved UID/range/owner/emitter/position/Nested.
- [x] Set UID0003QZ to `92/94`, applied exact Item Summary, exhaustive evidence, and byte-for-byte R1 without compression.
- [x] Created/registered exact raw child `[0x00570e20,0x00570eef)` first; validator command `000000010607` issued UID0004NA, after which every temporary report placeholder was replaced.
- [x] Set UID0004NA to `89/92`, owner/emitter UID0000CV, true, blank position, Nested0, exact R3 and no-route/constructor-omission history.
- [x] Updated UID0001HK to `89/92`, false/blank, owner UID0000CV, Nested0, corrected target row, raw child, exact padding, and full child order.
- [x] Updated UID0000CV to `92/93` with exact R2, complete `0xd90` layout/prose, access model, history, and `[[CHILDREN]]` after class closure.
- [x] Updated UID0000NL to `90/92` with exact source inventory, route, historical title correction, raw helper, and compiler/source distinctions.
- [x] Updated UID00038M to `89/93` and UID00038N to `90/94` with exact `0x00624740` OnActivate slot and compiler no-code proof; routes/positions/nesting remained exact, and UID00038N uses only the bounded comment required to avoid a false marker.
- [x] Synchronized UID0003R9, UID0003RA, UID0004N5, and only stale bounded SpelledPane links/prose; verify-only scores/routes/bodies remain unchanged.
- [x] Preserved all existing children, raw helpers, parent/successor padding, target hash/range, mode-0 behavior, TAB-to-LF conversion, CR legend suffix, and UserStatus/Spelled ownership boundaries.
- [x] Preserved rejected OnDraw/direct-owner/mode-3/internal-split/manual-vtable/explicit-padding/raw-name alternatives and all negative evidence.
- [x] Ran scoped validation for every changed/new/renamed ordinary by-* page under serial one-file leases and released each immediately.
- [x] Ran final authorized `--wait-generated` command `000000010669` and recorded command IDs, timestamps, exits, `ok`, side effects, and header freshness.
- [x] Verified generated SelfLookPane.cpp closes R2 before definitions, contains R1/R3 once, retains unique existing snippet headers, has no UID0003QZ/00038N Empty Emitter Marker, no stale OnDraw, no raw vtable/RTTI arrays, and no duplicate/wrong-range emitter.
- [x] Updated C01-C20 to legal callback states with exact destination/validator/generated proof.
- [x] Updated Finalized/Current State, Validator Results, Changed Files, exact UID0004NA, and checklist to archive-neutral implementation-complete truth.
- [x] Supplied current exact manual coverage text for the parent, renamed target, real-UID raw child, class, file, vtable family, and exact UID00038N vtable child while leaving manual coverage/tracker edits external.
- [x] Confirmed `current_leases.md` contains no active lease and no B003 lease remains.
- [x] B003 ran no `execute_report`, report probe/lifecycle, move, or archive command and made no manual generated/coverage/tracker/audit/validator-state edit.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000010737","destination_path":"executed-b-agent-research/B003/0003QZ-SelfLookPane2OnDraw-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0003QZ-SelfLookPane2OnDraw-source-quality.md","timestamp":"2026-07-14T04:31:11-04:00","uid":"0003QZ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
