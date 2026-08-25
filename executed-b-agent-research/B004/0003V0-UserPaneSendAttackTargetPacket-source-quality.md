** TARGET-REPORT-UID:0003V0 **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

# UID0003V0 UserPaneSendAttackTargetPacket Source-Quality Research

## Finalized Report / Current Recommendation

- Current callback state: [UID:0003V0] is the source-authored `UserPane::SendAttackTargetPacket(char direction)` member over exact range `[0x005ad360,0x005ad441)` at applied `92/94`, with owner/emitter UID0000FQ, reconstructable true, blank emitter position, `Nested:0`, and exact Destination 1 formal body.
- Final disposition: one unsplit 225-byte UserPane member in `NexusTK/ui/panels/UserPane.cpp`. It has one direct caller function with four call sites, not four caller functions. The source body uses `MapRect`, `MapPane::GetAdjacentVisibleTileBounds`, its returned bounds checksum, value-first PacketBuffer writers, a 12-byte opcode-`0x82` payload, and one unsent local terminator.
- Callback state: the supervisor accepted exact Gate 1 artifact SHA256 `A36C2F5EC38984FD93B3BFE567FC5784F4F8C81EDFD6D81833065C3BE01D1BB6`. Both staged phases are complete: all seven accepted ordinary destinations are applied or preserved as specified, each changed page passed scoped validation, and final waited command `13366` proves the generated target/class union.
- Confidence: very strong for range, bytes, CFG, ABI domain, owner, caller/callee graph, fields, packet bytes/order/length, source route, and complete C++ eligibility; strong for the stripped method/parameter/local spellings and original local array capacity.

## Supporting Research

- Assignment history: B004 first completed the target-specific report-only pass for [UID:0003V0] `by-memory/0x005ad360-0x005ad441.UserPaneSendAttackTargetPacket.md`. After exact-artifact Gate 1 acceptance, the supervisor authorized a staged callback. Phase A applied UID0003V0 and UID0003YJ; two explicit shared-lane releases then authorized the collision-safe UserPane class/file/index/caller/ignored additions. B004 manually edited only the seven accepted ordinary destinations and this report; manual coverage, generated output, tracker, audit, supervisor state, validator state, IDA database, lifecycle state, and other-agent artifacts were not manually edited.
- Evidence-time MCP: streamable MCP protocol session `56ad31fa-95d6-494f-9ae0-99b9c59f24b0` returned the sole active NexusTK database `64c11373`, worker PID `21508`. `server_health` returned `status:ok`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, and 2,067 cached strings. Bounded target/helper lookup, bytes, decompile, xref, basic-block, callee, and byte-pattern calls succeeded. Availability is stated only for the evidence collection time, not indefinitely.
- Exact old-report search terms: `UID0003V0`, `UID:0003V0`, `0x005ad360`, `0x5ad360`, `0x005ad441`, `UserPaneSendAttackTargetPacket`, `SendAttackTargetPacket`, `AttackTargetPacket`, `GetAttackTargetRect`, `GetAdjacentVisibleTileBounds`, `MapRect`, `NxRect`, `targetId`, `boundsChecksum`, `PacketBufferWriteUInt8`, `PacketBufferWriteUInt16BE`, `g_packetSender`, `UserPane`, `LivingObjectPane`, `UID0000FQ`, `UID0000P1`, `UID0001KM`, and owner/source-family terms.
- Central executed root `executed-b-agent-research/**`: no dedicated prior UID0003V0 report exists. The relevant matching reports actually opened and classified were:
  - B001 `0002QY-MotionAnimationTimerTick-empty-emitter-source-quality.md`, SHA256 `08B58B97B76635467AC02E1FB182BCDF56C01FE1B7AB754941AA3233A408782A`: broad UserPane integration authority that created the current path/owner/body at retained `86/89`; it counted four call sites as four callers and used the now-disproved `NxRect`, `GetAttackTargetRect`, `targetId`, direct-byte, and destination-first writer body.
  - B003 `0003V9-UserPaneHandleKeyEvent-source-quality.md`, SHA256 `B960D0AB84425FB4EDF94A9325D3EA363FB11B9D3CC95512FAA914EA98FF3331`: direct caller authority for four case branches and argument values `3,0,1,2` in source switch order; it did not audit the target body.
  - B014 `000428-MapPaneGetAdjacentVisibleTileBounds-source-quality.md`, SHA256 `9801DF6769CAB7EC40F9BD8F28C8EB5D955AE9269BD66D0F40E39F88EA9B18B3`: direct callee authority for `MapRect`, adjacent visible bounds, checksum return, exact two-caller graph, and MapPane ownership; its historical current body uses the established unsigned-direction API and remains otherwise valid.
  - B001 `0001KM-livingobject-localplayer-source-split-audit.md`, SHA256 `2D5E2E9348C546FBB26C5302EEFE49C42FBCC9F02EC313231C718889C1F8127B`, and retry SHA256 `015A9612DF9011F22889E88F1F5231C66C9DE9BE27B2A6D51EE39079783C8EA1`: exact `0xe1` boundary and four-site lead; old LivingObjectPane ownership is superseded by current UserPane layout/route.
  - B001 `0003H4-UserPaneSendDirectionPacket-source-quality.md`, SHA256 `E740CD2F9A911422383E212D6F32A7BB364109DF2CBDC020FEE649501ECF0A9F`: incidental UserPane class declaration only; no target-specific packet/body audit.
  - B001 `0003EB-LivingObjectPaneActionNegativeOneFloatConstant.md`, SHA256 `5A7D03304DFFA06F4FC956A26FAF972DBFC2C1F2D925F46BAD2413016D75B840`: searched/opened as required owner-family lead; no exact UID/address/name/helper match and no direct target evidence.
  - B014 `0003UD-LivingObjectPaneTryPerformAction-source-quality.md`, SHA256 `13626003CCF885183785728740D50F5FF2B12465043608E241E245B828106CCE`: searched/opened as required action-family lead; no exact UID/address/name/helper match and no direct target evidence.
  - B004 `0001KL-UserPane-source-quality.md`, SHA256 `477BC1F399BA263B0C28C7E77E65F1B3D20BADE92DDCF85195FFF101E1D5952F`: searched/opened as a UserPane aggregate lead; no exact UID/address/name/helper match.
  - B001 `00024A-UserPaneVirtualDword1340F8Accessor-source-quality.md`: current `m_mapPane` field and UserPane receiver support; no target body audit.
  - B001 `0003U6-UserPaneProcessMovement-source-quality.md`: direct sibling consumer of the same MapPane helper and packet writers; supports current direction/MapRect/checksum vocabulary without owning UID0003V0.
- Shared report roots and callback-coordination evidence:
  - B002's finalized artifact is now `executed-b-agent-research/B002/0003H5-UserPaneSendAutoFaceDirectionPacket-source-quality.md`, SHA256 `9A496D06D6ED0A85D2B6AEFFEEE83A296D88E462DB445CAEE843EBFD16CB8D54`. It supplies the terminal H4/H5/HUZ source chain and corrected [UID:0003UZ] links. B004 reread that archive and every shared destination after the second lane release, preserving all B002 facts while adding only UID0003V0 detail.
  - B003's finalized artifact is `executed-b-agent-research/B003/0003UA-UserPaneDispatchConfiguredShortcutHotkey-source-quality.md`, SHA256 `CBF904524713FA38CE76C5FC14D9DB65B74D05E96FEC337125746BEDBD31D86D`. Its `CompactShortcutRecord { wchar_t code; unsigned char isSpellMode; }`, natural-tail, class-closure, Config, and UserPane source-order union remains present byte-for-byte outside the accepted target delta.
  - B005's finalized artifact is `executed-b-agent-research/B005/0003UP-UserPaneHandleMovementReplyPacket-source-quality.md`, SHA256 `CB31E9B73313D6E87D94F83515D2FE1F8402C81D908CD25424F3920ED3C400FF`. Its UID0003UP/UQ movement-reply, Config, profile, movement-state, class/file/index, and generated policies remain present. Current verify-only Config hashes are class `9ECA99799904B0DD1E6D14E0C84DC784B578E2C31555C3AD7472C9B7A304B473` and file `91984E67C9F7E99F2252203A65C892654531030AF190C7DAB7E2F0497FE3D577`.
- `tools/leaser/Agents/Older-Research/**` and `tools/leaser/Agents/SpecialReports/**`: explicit searches with the exact UID/address/name/helper/owner/source-family terms returned no direct matching report.
- Actual project archive root `source-3/project-documentation/archived/**`: inspected directly; it contained 95 files, six JSON and 89 log files, zero Markdown reports, and therefore no target report to open/classify.
- Wave2/Wave3 material: stale Wave-era assumptions appeared only through historical documentation/report language. No Wave artifact was used as current evidence.

## Target

- Target UID: `0003V0`.
- Target path: `by-memory/0x005ad360-0x005ad441.UserPaneSendAttackTargetPacket.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md`, `## by-memory` -> `### Not-Covered Files - Reconstructable`; evidence-time row `86/89`, reconstructable true, zero target reports.
- Implementation callback state: both phases and all accepted implementation/validation items are complete; independent report review, execution, count, path, move, and archive state remain external supervisor/validator-owned.
- Current scores and parent state: `92/94`; canonical owner/emitter UID0000FQ UserPane; reconstructable true; blank emitter position; `Nested:0`; exact source-ready formal C++ applied on the target page.
- Pre-callback assignment baseline: target SHA256 `3DD4BE9AD7F546677E34FAA6935F29CF4A4886A84887E4EE41BAEAAB6A03C060`, 6,367 bytes, 85 physical lines. Current target SHA256 is `1C0748AC408BC66C403D0375F5059B3093860DE9F248C0E82872ECF1336E8888`, 14,012 bytes, 139 physical lines.

## Current Target State

- The completed callback preserves UID0000FQ UserPane as owner/emitter, UID0000P1 `NexusTK/ui/panels/UserPane.cpp` as source route, reconstructable true, blank position, exact half-open range, and `Nested:0`.
- The target formal now exactly preserves the `m_isMoving` return, plain-char direction, `MapRect` adjacent-visible bounds/checksum lookup, six UInt8 and three UInt16BE value-first calls, explicit narrowing, no-clamp differences, local byte 12 zero, and send length 12.
- Stale `NxRect`, `GetAttackTargetRect`, `targetId`, direct-byte, destination-first, generic `action`, unsigned-target, and blank/open-C++ states survive only as explicit historical/rejected evidence. Validator command `13329` normalized three target-page UID links without changing that evidence.
- Manual by-memory coverage application remains supervisor-owned. Current read-only hash `DE7F3A933FDECAF92F4924FAE5EF750A2539A03E47240F0F0C6B400D8C5857EC` still carries the stale `86%`/four-caller target row at line 3340 and no exact padding row before the UID0004R4 successor at line 3341; the replacement/addition handoff below remains required external work.
- Historical pre-callback generated checkpoint command `13328`/SHA256 `75E0F93227029088FEA2A744EAC44DD46CEBB5B7FFB78EF19D7852EE852B6ECA` still had the stale target body. Earlier commands `13322`, `13317`, `13309`, `13308`, `13298`, `13286`, `13272`, `13264`, `13252`, and `13239` remain evidence-time history only, not durable lifecycle assertions.
- Historical Phase A generated checkpoint command `13329`/SHA256 `304BF934D6F1EF6F1DD20A5D21C1CDFB1DF06EA6B4C3EEE78504BA5C7049279D` proved the corrected definition before the class declaration changed. Final waited command `000000013366`, refreshed `2026-07-15T18:12:05-04:00`, now owns the current generated state: SHA256 `D0F4649538FF7A9DBAF8A612B3B176F8F8E4A3CA588B3F97BE8FCA13DB97CB4B`, 90,317 bytes/2,697 lines, with one matching declaration, definition, and provenance plus the exact target body and zero stale target tokens.
- Current artifact/lifecycle boundary: exact-artifact Gate 1 acceptance, both lane releases, and callback completion are historical/current coordination facts. B004 performed no manual coverage, report execution, counting, movement, or archive action; those lifecycle states remain external supervisor/validator-owned and are not asserted or directed by this artifact.

## Executive Recommendation

- Retain the exact UID/path/range and UserPane owner/emitter/source route. No rename, owner move, split, new source file, raw-helper conversion, covered-by downgrade, or no-code disposition is justified.
- The target is `92/94` with Destination 1 applied, and the complete Destination 2 UserPane declaration now uses `char direction` instead of `unsigned char action`. Plain `char` is selected because the target preserves the incoming stack dword for the MapPane call but independently executes `movsx eax, bl` before pushing direction to the UInt8 writer, while Hex-Rays also models the target parameter as `char`. The four live callers push only positive immediates `0/1/2/3` and therefore cannot distinguish signedness. Explicit `signed char` is the code-generation-equivalent spelling runner-up under the observed signed-byte contract; `unsigned char` is rejected because no matching x86 MSVC/source-conversion evidence shows it produces the target's signed promotion.
- Use `MapRect targetBounds` and `m_mapPane->GetAdjacentVisibleTileBounds(direction, &targetBounds)`. Name the returned 16-bit value `boundsChecksum`; direct callee behavior computes a rectangle checksum, not an object/target ID.
- Preserve all actual UInt8/UInt16 helper calls using value-first source order and all explicit casts/narrowing. Keep `unsigned char packet[13]`: exact source writes require 13 bytes and current sibling conventions use payload-plus-local-terminator capacity. A 16-byte declaration is the bounded runner-up because MSVC reserves an aligned 16-byte stack slot, but three untouched bytes do not prove authored capacity 16.
- `by-memory/-ignored.md` now records `[0x005ad441,0x005ad450)` as exact 15-byte all-`0xcc` compiler/linker alignment before independent successor UID0004R4. It carries no handwritten source and creates no child.
- Shared callback condition is satisfied. B004 reread the finalized B002/B003/B005 artifacts and each live destination after the supervisor releases, preserved their complete union, applied only the bounded UID0003V0 delta, scoped-validated each page, and released every lease immediately.

## Supervisor Active Recheck

- The supervisor assigned a fresh direct-target pass because the existing nonblank C++ and `86/89` score were not trusted as final.
- Split repair is not required for the function body. Exact modeled end `0x005ad441` is already represented; only the separate 15-byte successor alignment is missing from ignored-padding documentation.
- The sole source-bearing item in the target range is UID0003V0 itself. Its complete Destination 1 source body is applied and validated. The adjacent padding has exhaustive no-source proof and is now recorded in Destination 7 without a child or source emitter.
- All mandated blocker classes were rechecked: complete body, ABI/domain, callers, MapPane rectangle/checksum helper, packet format and length, local capacity, field/type/name choices, owner/emitter/file route, range/boundaries, score, manual coverage, support dependencies, generated output, and historical contradictions.

## Inference Research Guidance Check

- IDA fact, current documentation, and inference are separated throughout. Bytes, CFG, stack offsets, direct calls, field displacements, packet length, xrefs, and padding are direct facts. UserPane/MapPane/PacketBuffer/Socket names are current documentation corroborated by independent children. Local variable and exact original method/parameter spellings are inference.
- Existing documentation was treated as fallible. The broad 0002QY report supplied a useful owner/range/body lead but its `NxRect`, `GetAttackTargetRect`, `targetId`, destination-first writer order, and four-caller statement were independently retested and rejected.
- Consumer xrefs establish liveness, not ownership. The one caller is UserPane and the target accesses UserPane-only displacements, so owner assignment is independently supported. MapPane and Socket remain callees/dependencies.
- Compiler evidence is not emitted as source. Security-cookie instructions and the 15-byte `0xcc` alignment are excluded; source expresses the packet/body semantics and lets the toolchain regenerate mechanics.
- Wave2/Wave3 names and output were ignored as stale. Historical LivingObjectPane ownership remains useful only as a rejected provenance record.

## Heuristic / Inference Reanalysis And Validation

| Issue | Existing state | Reanalysis and selected result | Classification |
| --- | --- | --- | --- |
| Owner | UserPane current; LivingObjectPane in nested history | UserPane retained: receiver reads `+0x1340f8`, `+0x13ead8`, and `+0x13eadc`, beyond the `0x20c` base and inside the complete UserPane layout | direct plus documented |
| Method name | `SendAttackTargetPacket` | Retained project-stable spelling; opcode `0x82`, alternate-arrow cases, adjacent directional bounds, and packet send all support attack-target semantics | inferred, very strong |
| Parameter name | pre-callback `action`; current target/class `direction` | Values are exact compass cases and the MapPane callee switches on direction; target and complete class declaration now agree | inferred, very strong |
| Parameter type | pre-callback target/class `unsigned char`; current target/class plain `char` | Target `movsx eax, bl` before the UInt8 call is direct signed-promotion evidence; helper-call `push ebx` and caller immediates `0..3` are non-discriminating. Explicit `signed char` is the equivalent-spelling runner-up; unsigned remains rejected without matching compiler proof | direct plus inferred spelling, very strong |
| Rectangle type | pre-callback `NxRect`; current target `MapRect` | Current shared `MapRect` has four signed 32-bit edges and the exact 16-byte copy contract | documented plus direct layout |
| MapPane helper | pre-callback `GetAttackTargetRect`; current target `GetAdjacentVisibleTileBounds` | UID000428 and live callee prove clamped adjacent row/column, map clipping, optional output, and checksum return | direct plus documented |
| Returned value | pre-callback `targetId`; current target `boundsChecksum` | Callee returns `ComputeTileRectChecksum(&bounds)` | direct plus inferred spelling |
| UInt8 writes | pre-callback direct assignments; current target has six calls | Exact `PacketBufferWriteUInt8(value, destination)` calls cover opcode, direction, viewport bytes, and widths | direct ABI |
| UInt16 order | pre-callback destination first; current target uses value first | Exact `PacketBufferWriteUInt16BE(value, destination)` calls cover left, top, and checksum | direct ABI |
| Coordinate narrowing | implicit | Preserve explicit narrowing from int edges and int viewport fields to 8/16-bit packet widths without adding clamp or validation | direct semantics |
| Packet layout | 13-byte local, 12-byte send | Retain exact offsets `0..12`, payload `0..11`, unsent zero at 12; Socket appends a second terminator to its queued copy | direct |
| Local capacity | `[13]` | Retain as primary payload-plus-terminator declaration; `[16]` is runner-up from aligned stack reservation, not an exact source requirement | inferred, strong |
| Guard | `m_isMoving` | Retain early return on inherited byte `+0x1c4`; no other state gate exists | direct plus documented |
| Caller count | four callers | Correct to one function, four call sites at `0x005a5e40/54/68/7c` | direct |
| Range | `[0x005ad360,0x005ad441)` | Retain exact function; add separate `[0x005ad441,0x005ad450)` ignored alignment | direct |
| Split | unsplit | Retain one function; three CFG blocks are normal control flow, not children | direct |
| Source route | UserPane.cpp | Retain UID0000P1; UserPane class/file and address-family placement agree | direct plus documented |
| Generated state | corrected declaration, definition, and target body | waited command `13366` proves exact parity/counts with zero stale target tokens | generated evidence |
| Shared coordination | complete | finalized B002/B003/B005 artifacts and all live destinations were reread/rebased; both release gates are historical coordination evidence | current workspace fact |

Rejected alternatives:

- LivingObjectPane ownership is rejected by derived-only receiver offsets and current UserPane source integration.
- MapPane ownership is rejected because MapPane is loaded from a UserPane field and used as a callee receiver.
- A file-local free helper is rejected because the target receives UserPane in ECX and accesses three UserPane fields.
- `GetAttackTargetRect`, `NxRect`, and `targetId` are rejected by the exact existing UID000428 helper contract.
- Destination-first PacketBuffer calls are rejected by helper stack-argument reads and established current PacketBuffer evidence.
- A 13-byte transmitted packet is rejected because `QueueAndSendPacket` receives literal length 12; byte 12 is local-only.
- `packet[12]` or a body without the explicit zero is rejected because the machine writes offset 12.
- Local-capacity controls were checked rather than inferred from frame size alone. The target's exact accesses establish a 13-byte minimum; current UID0003W7 source-shape material independently uses `packet[13]` for a 12-byte payload plus byte-12 terminator; UID0003KW instead uses a preallocated member packet buffer and therefore does not constrain this local declaration; SelfSave's accepted `[16]` conclusion depended on a separate matching-toolchain probe and cannot be transferred to this frame. No matching x86 MSVC compiler was available for a new local probe. The evidence therefore ranks `[13]` first and aligned `[16]` second without claiming the frame interval alone proves either spelling.
- `unsigned char direction` is rejected as the target source type. The four direct callers push only `0`, `2`, `3`, and `1`, so they prove current-call equivalence but not source signedness. In the target, `mov ebx,[ebp+arg_0]` followed by `push ebx` to MapPane does not discriminate because the callee consumes the low byte; the separate `movsx eax,bl` before the UInt8 call does discriminate the target's promotion. The MapPane helper independently uses `movsx` before its `0..3` switch; signed and unsigned interpretations still send every other 8-bit pattern to the same default through unsigned `ja`. The UInt8 writer reads/stores only the low byte, so its current unsigned declaration preserves the same packet byte for all 256 bit patterns. These controls support plain `char` for this target while leaving the helper/writer behavior, scores, and formals unchanged.
- Defensive null checks, rectangle clamping in this method, range checks, packet-builder objects, and send-result handling are rejected because the binary has none.
- A target split, inline-only/covered-by classification, compiler-wrapper classification, no-code marker, or parent-emitted body is rejected by the modeled out-of-line function and four direct calls.

No investigable blocker remains. The only residual uncertainty is stripped lexical spelling (`char` versus explicit `signed char`, which is code-generation equivalent under the observed signed-byte contract) and authored local capacity `13` versus aligned `16`; both are reflected in confidence and do not affect the implementation-ready body.

## Evidence Standards Used

- Primary evidence: live IDA MCP `idb_list`, `server_health`, `lookup_funcs`, `get_bytes`, `decompile`, `xref_query`, `basic_blocks`, `callees`, and `find_bytes` on database `64c11373`.
- Binary evidence: exact 225 target bytes, exact 15 padding bytes, three basic blocks, five direct callees including cookie support, four inbound code xrefs in one function, and zero absolute-VA/RVA byte-pattern routes.
- Documentation evidence: current target/class/file/parent/caller/MapPane helper/PacketBuffer/Socket/global/field pages; generated UserPane.cpp; manual coverage rows; validator-owned tracker; matching central/current reports and evidence-time active-root searches.
- Negative evidence: no target data xref, pointer/table route, interior child, successor overlap, target Empty Emitter Marker, second caller function, target string, independent padding xref, or source role for the alignment.
- The evidence ladder supports very-strong behavior/ownership/range conclusions. Confidence remains below 95 because stripped symbols do not prove literal method/local names or the source declaration capacity selected by stack allocation.

## Evidence Checked

- IDA MCP checks: fresh session discovery and health; target/helper/successor/caller lookup; target and padding bytes; target and MapPane-helper decompilation; target/helper basic blocks and callees; inbound xrefs to target/end/successor; VA/RVA pointer-pattern scans; exact caller-function attribution.
- Current docs opened: UID0003V0, UID0000FQ, UID0000P1, UID0001KM, UID0003V9, UID000428, UID0003YJ, UID0001HU, UID0000Q5, `g_packetSender` storage, viewport-field support, MapPane class/file, UserPane class/file, ignored padding, manual memory/class/file/global coverage, generated UserPane.cpp, tracker, and current leases.
- Old reports opened/classified under Supporting Research. `Older-Research`, `SpecialReports`, actual `archived`, central executed, and active Agent-B001..B005 roots were explicitly searched with the recorded terms.
- Negative checks: zero pointer pattern hits for target VA/RVA; zero xrefs at `0x005ad441`; one function/four callsites only; no modeled child in target; all-`0xcc` successor interval; no exact prior direct target report; no B004 lease remains.
- Failed or skipped checks: the first `get_bytes` request used `address` instead of the advertised `addr` schema and returned parse errors; the schema was refreshed and the bounded request was repeated successfully. No evidence conclusion depends on the failed request. No matching x86 MSVC compiler was available for a local source-capacity probe, so the report uses exact accesses plus explicitly ranked sibling/toolchain controls. No validator, IDA mutation, lifecycle command, or generated refresh was permitted or run.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C3V0-001 | Retain UID0003V0 and exact `[0x005ad360,0x005ad441)` range. | very strong | lookup size `0xe1`; bytes; current path | Destination 1 | already-present | already-present |
| C3V0-002 | Raise target `86/89 -> 92/94`. | strong | complete behavior/route/type closure | Destination 1 | incorporate | applied |
| C3V0-003 | Retain owner/emitter UID0000FQ, reconstructable true, blank position, `Nested:0`. | very strong | receiver layout and current routing | Destination 1 | already-present | already-present |
| C3V0-004 | Retain source route UID0000P1 / `NexusTK/ui/panels/UserPane.cpp`. | very strong | class/file/address family | Destinations 1, 3, 4 | already-present | already-present |
| C3V0-005 | Replace stale target formal with complete Destination 1. | very strong | target decompile/bytes/helpers | Destination 1 | incorporate | applied |
| C3V0-006 | Retain source name `SendAttackTargetPacket`. | strong | opcode/caller/source family | Destinations 1-4 | already-present | already-present |
| C3V0-007 | Rename source parameter `action` to `direction`. | very strong | four directional caller cases; switch callee | Destinations 1, 2 | incorporate | applied |
| C3V0-008 | Select plain `char direction`; retain explicit `signed char` only as the code-generation-equivalent spelling runner-up and reject unsigned. | very strong | target `movsx eax,bl`; Hex-Rays `char`; non-discriminating caller constants/helper push | Destinations 1, 2 | incorporate | applied |
| C3V0-009 | Replace `NxRect` with `MapRect`. | very strong | UID000428 and 16-byte callee output | Destination 1 | incorporate | applied |
| C3V0-010 | Replace `GetAttackTargetRect` with `GetAdjacentVisibleTileBounds`. | very strong | direct callee `0x505650`; current UID000428 | Destination 1 | incorporate | applied |
| C3V0-011 | Replace `targetId` with `boundsChecksum`. | very strong | callee tail `ComputeTileRectChecksum` | Destination 1 | incorporate | applied |
| C3V0-012 | Preserve early `m_isMoving` return at inherited `+0x1c4`. | very strong | target first branch; current layout | Destination 1 | already-present | already-present |
| C3V0-013 | Preserve cached `m_mapPane` at `+0x1340f8`. | very strong | target read; UID00024A | Destination 1 | already-present | already-present |
| C3V0-014 | Preserve `m_viewportColumn`/`m_viewportRow` at `+0x13ead8/+0x13eadc`. | very strong | target reads; UID0002RW | Destination 1 | already-present | already-present |
| C3V0-015 | Emit opcode `0x82` through value-first UInt8 writer. | very strong | call `0x575380` at `0x5ad3a1` | Destinations 1, 6 | incorporate | applied |
| C3V0-016 | Emit plain-char direction at packet offset 1 through the value-first UInt8 writer, preserving target `movsx` and the exact low byte. | very strong | `movsx eax,bl`; call `0x5ad3ae`; writer low-byte read | Destinations 1, 6 | incorporate | applied |
| C3V0-017 | Emit narrowed viewport column/row at offsets 2/3. | very strong | calls `0x5ad3bd/cc` | Destinations 1, 6 | incorporate | applied |
| C3V0-018 | Emit narrowed left/top as UInt16BE at offsets 4/6. | very strong | calls `0x5ad3d8/e4` | Destinations 1, 6 | incorporate | applied |
| C3V0-019 | Emit width/height edge differences as UInt8 at offsets 8/9 without clamping. | very strong | subtract/call sequences | Destinations 1, 6 | incorporate | applied |
| C3V0-020 | Emit 16-bit bounds checksum at offset 10. | very strong | return AX and call `0x5ad411` | Destinations 1, 6 | incorporate | applied |
| C3V0-021 | Correct every scalar helper to raw value-first source order. | very strong | UID0003YJ ABI and disassembly | Destinations 1, 6 | incorporate | applied |
| C3V0-022 | Keep `packet[12] = 0` as explicit unsent local terminator. | very strong | store `0x5ad422`; send length 12 | Destination 1 | already-present | already-present |
| C3V0-023 | Keep source capacity `packet[13]`; record aligned `[16]` runner-up. | strong | touched offsets and frame/cookie spacing | Destination 1 | incorporate | applied |
| C3V0-024 | Keep send call `g_packetSender->QueueAndSendPacket(packet, 12)`. | very strong | call `0x5ad429`; UID0001HU/Q5 | Destination 1 | already-present | already-present |
| C3V0-025 | Preserve Socket's separate queued-copy terminator; do not count it as payload. | very strong | UID0001HU body | Destination 1 evidence | incorporate | applied |
| C3V0-026 | Correct caller count to one function/four sites. | very strong | xref_query with shared fn `0x5a5bd0` | Destinations 1, 4, 5 | incorporate | applied |
| C3V0-027 | Preserve caller direction map: key cases `0x80/81/82/83 -> 3/0/1/2`. | very strong | current UID0003V9 and callsite bytes | Destinations 1, 4, 5 | incorporate | applied |
| C3V0-028 | Retain UID0003V9 formal body unchanged. | very strong | current source already exact | Destination 5 | already-present | already-present |
| C3V0-029 | Retain UID000428 formal body/score/owner unchanged; its current unsigned declaration is not evidence for target signedness because helper `movsx` and switch-default behavior were checked directly. | very strong | helper low-byte `movsx`; all non-0..3 patterns take the same default | verify-only UID000428 | already-present | already-present |
| C3V0-030 | Retain MapPane class/file formals/scores unchanged; target plain-char conversion preserves all helper case/default results across the full byte domain. | very strong | low-byte ABI and exhaustive `0..255` switch partition | verify-only UID00007Q/0000L3 | already-present | already-present |
| C3V0-031 | Retain UID0001HU Socket formal/score/owner unchanged. | very strong | exact current sender behavior | verify-only UID0001HU | already-present | already-present |
| C3V0-032 | Retain g_packetSender global/storage formal/score/owner unchanged. | very strong | current Socket lifetime/type | verify-only UID0000Q5/0001P0 | already-present | already-present |
| C3V0-033 | Add target as exact UID0003YJ value-first consumer, including signed promotion before the direction write and low-byte preservation, without changing helper score/formal. | very strong | nine target writer calls; `movsx eax,bl`; writer reads `[arg_0]` byte | Destination 6 | incorporate | applied |
| C3V0-034 | Add exact target behavior/source-quality detail to UID0001KM row. | strong | exact target pass | Destination 4 | incorporate | applied |
| C3V0-035 | Add exact target source/dependency/one-definition detail to by-file/UserPane. | strong | route and generated readback | Destination 3 | incorporate | applied |
| C3V0-036 | Apply complete UserPane class Destination 2 preserving all unrelated union bytes. | very strong | current full formal plus one target parameter name/type delta | Destination 2 | incorporate | applied |
| C3V0-037 | Historicalize target's stale LivingObjectPane ownership and blank/open-C++ claims. | very strong | current accepted owner/formal plus MCP | Destination 1 | historicalize | applied |
| C3V0-038 | Preserve broad 0002QY report facts as history while rejecting its stale names/order/count. | very strong | fresh direct comparison | Destination 1/support prose | reject-stale | applied |
| C3V0-039 | Retain unsplit source-bearing method disposition; no covered-by/no-code marker. | very strong | modeled function and four calls | Destination 1 | already-present | already-present |
| C3V0-040 | Add exact `[0x005ad441,0x005ad450)` 15-CC ignored alignment and SHA256. | very strong | get_bytes and zero xrefs | Destination 7 | incorporate | applied |
| C3V0-041 | Do not create a child for CFG blocks or padding. | very strong | function CFG and compiler alignment | Destination 1/7 | reject-invalid | applied |
| C3V0-042 | Replace stale target manual coverage row with exact supervisor text. | very strong | manual row versus MCP/current recommendation | manual by-memory coverage | incorporate | excluded-with-reason |
| C3V0-043 | Add exact ignored-padding manual coverage row after target. | very strong | absent current row and exact interval | manual by-memory coverage | incorporate | excluded-with-reason |
| C3V0-044 | Preserve other inspected manual rows because their current path/score/source facts remain true. | very strong | read-only row comparison | manual class/file/global/memory coverage | already-present | already-present |
| C3V0-045 | Serialize and callback-time rebase shared UserPane destinations against accepted B002/B005 unions. | very strong | finalized shared artifacts/current workspace state | Destinations 2-4 | incorporate | applied |
| C3V0-046 | Run one scoped validator per changed ordinary page and one waited target refresh only after callback. | very strong | workflow and generated dependency | callback verification | incorporate | applied |

### Callback Proof

- C3V0-001 through C3V0-003, C3V0-005, C3V0-009 through C3V0-025, and C3V0-037 through C3V0-039 are terminal on Destination 1. UID0003V0 retained its UID/range/owner/emitter/reconstructable/blank-position/`Nested:0` contract, moved `86/89 -> 92/94`, received the exact Destination 1 managed definition and Item Summary, and now carries complete range/bytes/CFG/frame/owner/caller/signedness/MapPane/packet/boundary/negative/history/score proof. Scoped validator `000000013329` returned exit `0`, `ok:1`; final page SHA256 is `1C0748AC408BC66C403D0375F5059B3093860DE9F248C0E82872ECF1336E8888`.
- C3V0-015 through C3V0-021 and C3V0-033 are terminal across Destinations 1 and 6. UID0003YJ records all six UInt8 and three UInt16BE call sites, raw value-first order, target `movsx`, writer low-byte storage, explicit narrowing/no-clamp behavior, spare-zero overwrites, local byte-12 terminator, and 12-byte send while retaining `87/91`, UID0000M8 owner/emitter, `Nested:8`, boundaries, xref totals, and a blank formal block. Scoped validator `000000013331` returned exit `0`, `ok:1`; final page SHA256 is `7BAB13784EB789F6886309E9D165BF3936995EC14587F176BC457F70A88BF781`.
- C3V0-029 through C3V0-032 and C3V0-044 remain `already-present`: their verify-only MapPane, Socket, global/storage, and unaffected manual-row dispositions were preserved without ordinary edits.
- C3V0-004/C006/C028 and all other preserved contracts are `already-present`; C3V0-007/C008/C026/C027/C034-C036/C040/C041/C045/C046 are `applied` across Destinations 2-5 and 7 under validators `13357`-`13366`. C3V0-042/C043 are terminal `excluded-with-reason` because manual coverage is expressly supervisor-owned; their exact current replacement/addition text remains below. Final ledger counts are 28 `applied`, 16 `already-present`, 2 `excluded-with-reason`, and 0 `blocked`.

## Positive Evidence Summary

- Exact modeled function `sub_5AD360`, size `0xe1`, matches the current half-open target range and ends before 15 `0xcc` bytes.
- The receiver reads one inherited movement byte and three UserPane-only fields, proving a UserPane member rather than a free function or base member.
- Four direct calls all originate in one UserPane key handler and pass only the four compass direction values.
- Direct callee `sub_505650` is the independently documented MapPane adjacent-visible-bounds/checksum member and writes one 16-byte MapRect.
- The target calls shared scalar writers in exact opcode/direction/viewport/left/top/width/height/checksum order, then sends literal length 12 through the canonical Socket sender.
- Current class/file/parent/caller/generated/manual sources independently agree on the UID/range/owner/route and reveal the bounded stale details corrected here.
- The strongest inference chain is caller direction cases -> MapPane direction switch -> adjacent MapRect/checksum -> opcode-`0x82` packet serialization. It closes every body/name/type blocker without invented offset access or defensive behavior.

## IDA MCP Facts

- Database at evidence time: `64c11373`, `NexusTK.exe.i64`, imagebase `0x400000`, worker PID `21508`, healthy/readiness flags true.
- Final bounded MCP probe immediately before artifact verification rediscovered the same sole session, returned `server_health status:ok` with auto-analysis/Hex-Rays/strings ready, resolved `0x005ad360` to `sub_5AD360` size `0xe1`, and reread first 16 bytes `55 8b ec 83 ec 24 a1 24 2f 67 00 33 c5 89 45 fc`. This proves availability at final verification time only.
- Function: `sub_5AD360`, start `0x005ad360`, size `0xe1`, end `0x005ad441`; first 16 bytes `55 8b ec 83 ec 24 a1 24 2f 67 00 33 c5 89 45 fc`; last 16 bytes `4d fc 33 cd 5f e8 f4 a2 01 00 8b e5 5d c2 04 00`.
- Target SHA256: `5068082ECAFC229276C501CD2490218880D8C1F23386EB50510B28D202915000`; SHA1 `00CDD317E1753FFA477A6553883A20E096219DDB`.
- CFG: three blocks `[0x5ad360,0x5ad380)`, `[0x5ad380,0x5ad430)`, `[0x5ad430,0x5ad441)`; one early conditional and cyclomatic complexity 2.
- Stack: 16-byte MapRect at `[ebp-0x24,ebp-0x14)`, packet base at `ebp-0x14`, touched through `ebp-0x8` inclusive, three untouched bytes before cookie at `ebp-4`, frame allocation `0x24`.
- Callees: `0x00505650`, `0x00575380`, `0x005753a0`, `0x00574bb0`, and security-cookie check `0x005c772f`.
- Caller xrefs: `0x005a5e40`, `0x005a5e54`, `0x005a5e68`, and `0x005a5e7c`; every xref reports containing function `sub_5A5BD0`, start `0x005a5bd0`, size `0x1852`.
- Caller argument instructions are exact positive immediates: `push 0` at `0x005a5e38`, `push 2` at `0x005a5e4c`, `push 3` at `0x005a5e60`, and `push 1` at `0x005a5e74`, followed by target calls at `0x005a5e40/54/68/7c`. They prove the case map but cannot distinguish signed from unsigned byte source types.
- Target signedness chain: `mov ebx,[ebp+arg_0]` at `0x005ad38a`; `push ebx` at `0x005ad38f` into MapPane; then, independently, `movsx eax,bl` at `0x005ad3aa` and `push eax` at `0x005ad3ad` into the UInt8 writer. Hex-Rays models target argument `a2` as plain `char`.
- MapPane conversion control: `sub_505650` executes `movsx eax,[ebp+arg_0]` at `0x00505670`, then `cmp eax,3` / unsigned `ja` default. Bytes `0..3` select the four cases; every other byte pattern selects default under either sign or zero extension, so the helper's current unsigned declaration is full-domain behavior-equivalent but not positive evidence that the target parameter was unsigned.
- UInt8 conversion control: `sub_575380` reads only `al = byte ptr [ebp+arg_0]` at `0x00575386`, stores that byte at `0x00575389`, and writes the spare zero at `0x0057538b`. Therefore the target's sign-extended high 24 bits are not observed by the writer, while the explicit target `movsx` remains direct evidence for a plain/signed-char source promotion.
- Pointer scans: zero matches for little-endian target VA `60 D3 5A 00` and RVA `60 93 1A 00`.
- Padding: `[0x005ad441,0x005ad450)` is 15 bytes of `cc`, SHA256 `54CC9DD9593316E80CCAF5D10856E6502A0D75F20473A92FA01D63228EF1624C`, with zero xrefs to start. Successor `sub_5AD450` is independent size `0xaf` and has its own callers.
- MapPane helper: `sub_505650`, modeled size `0xce`, ten CFG blocks, direct clamped-bounds/SetRect/intersection/checksum calls, direction switch `0..3`, optional output copy, and 16-bit checksum return.
- No target string, vtable slot, function pointer, data pointer, raw duplicate route, or interior source child was found.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `[0x005ad360,0x005ad441)` | UID0003V0 target | UserPane member and sole source body | true | UID0000FQ | `86/89 -> 92/94` | retain unsplit; replace formal |
| `[0x005ad441,0x005ad450)` | UID0000VN `by-memory/-ignored.md` | compiler/linker alignment | false/no source | ignored index | ignored | add exact padding entry |
| `0x005ad450` successor | UID0004R4 ToggleTargetSelectionPane | independent file helper | true | existing owner | `90/92` | verify-only, unchanged |
| `0x00505650` callee | UID000428 GetAdjacentVisibleTileBounds | MapPane method plus attached table | true | UID00007Q | `90/92` | verify-only, unchanged |
| `0x005a5bd0` caller | UID0003V9 HandleKeyOrTextEvent | one UserPane caller with four sites | true | UID0000FQ | `92/94` | body verify-only; prose bounded |
| `0x00575380/0x005753a0` | UID0003YJ scalar writers | shared value-first serializers | true | UID0000M8 | `87/91` | add consumer evidence only |
| `0x00574bb0` | UID0001HU QueueAndSendPacket | Socket queued-copy sender | true | UID0000DD | `91/92` | verify-only, unchanged |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x005a5e40` | UID0003V9 -> target, argument `0` in machine order / case `0x81` | north/up adjacent attack strip |
| `0x005a5e54` | UID0003V9 -> target, argument `2` / case `0x83` | south/down adjacent attack strip |
| `0x005a5e68` | UID0003V9 -> target, argument `3` / case `0x80` | west/left adjacent attack strip |
| `0x005a5e7c` | UID0003V9 -> target, argument `1` / case `0x82` | east/right adjacent attack strip |
| `0x005ad390` | target -> UID000428 | compute adjacent clipped MapRect and checksum |
| `0x005ad3a1..0x005ad411` | target -> UID0003YJ scalar helpers | serialize nine logical packet fields in value-first ABI |
| `0x005ad429` | target -> UID0001HU through `g_packetSender` | queue/send exactly 12 payload bytes |
| `0x005ad441` | zero xrefs | alignment start, no source entry |
| `0x005ad450` | two independent calls in UID0003V9 | successor is unrelated target-selection helper |

## Documentation Evidence And IDA Status

- Current target/class/file/parent paths correctly establish UID, exact range, UserPane owner/emitter, source file, reconstruction state, and member name.
- UID000428 and MapPane class/file correctly establish `MapRect`, `GetAdjacentVisibleTileBounds`, exact direction cases, map clipping, and checksum return. They are stronger than the target's stale helper/type names.
- UID0003YJ correctly establishes raw value-first writer ABI and spare-zero semantics. UID0001HU and UID0000Q5 correctly establish canonical Socket sender and explicit-length behavior.
- UID0003V9 formal body remains exact and unchanged for the four directional calls. Its new bounded prose and UID0001KM/by-file support now distinguish one caller function from four call sites; only the supervisor-owned manual target row remains stale at `four callers`.
- Target nested history has been historicalized on UID0003V0 without deletion: current top/formal/proof states UserPane and complete source C++, while the older LivingObjectPane/unresolved/blank material is explicitly dated and rejected.
- Historical pre-callback generated command `13328` contained the stale target body, and Phase A command `13329` temporarily paired the corrected definition with the old class declaration. Final waited command `13366`/SHA256 `D0F4649538FF7A9DBAF8A612B3B176F8F8E4A3CA588B3F97BE8FCA13DB97CB4B` emits one matching plain-char declaration/definition/provenance and the exact nine-call sequence with zero stale target tokens or empty marker.
- Historical pre-callback tracker command `13328` listed target `86/89`, and Phase A command `13336` was an intermediate read-only checkpoint. Current validator-owned tracker command `13366`, SHA256 `63F3151FAD76728A62B516316E04A8235DAD199F4ED83F0ABC55E4C9423FD1B4`, lists UID0003V0 at `92/94`; this is generated freshness evidence, not a report execution/count/lifecycle assertion.
- Manual coverage status is supervisor-owned and read-only. Current hash `DE7F3A933FDECAF92F4924FAE5EF750A2539A03E47240F0F0C6B400D8C5857EC` retains the stale target row at line 3340 and lacks the padding row before UID0004R4 at line 3341. The exact UID0003V0 replacement and ignored-padding addition text remain below; UID0003YJ score/path facts remain unchanged after its accepted consumer synchronization.

## Ranked Ownership Analysis

### 1. UserPane / UID0000FQ

- Evidence for: ECX receiver; inherited `m_isMoving`; derived `m_mapPane`, `m_viewportColumn`, `m_viewportRow`; sole caller UID0003V9; source-family adjacency; current complete class/file route.
- Evidence against: none. Literal method spelling remains stripped, but role and class are not ambiguous.
- Decision: retain canonical owner/emitter UID0000FQ and source route UID0000P1.

### 2. MapPane / UID00007Q

- Evidence for: target calls a MapPane method and uses MapRect/checksum data.
- Evidence against: MapPane is loaded from `UserPane+0x1340f8`; target also reads UserPane viewport fields and inherited movement state; callers invoke the UserPane receiver.
- Decision: dependency/callee owner only, not target owner. UID000428 remains unchanged.

### 3. PacketBuffer or Socket

- Evidence for: shared serializers and queue/send funnel are direct callees.
- Evidence against: neither owns feature-specific opcode, UserPane fields, caller route, or rectangle selection.
- Decision: shared utility dependencies only. No ownership move or new ProtocolSend helper.

### Proposed new file/grouping, if applicable

- Not applicable. Existing `NexusTK/ui/panels/UserPane.cpp` is exact. No standalone packet source file, MapPane file move, helper grouping, or new class is justified.

## Source Placement

- Recommended placement: member declaration in UserPane's complete header/class emitter UID0000FQ and out-of-class definition on exact child UID0003V0 through by-file UID0000P1 / `NexusTK/ui/panels/UserPane.cpp`.
- Required dependencies: complete UserPane declaration, MapPane header/type visibility for `MapRect` and `GetAdjacentVisibleTileBounds`, PacketBuffer scalar-writer declarations, and external `Socket *g_packetSender`/Socket method declaration.
- This placement matches the sole caller, receiver fields, adjacent UserPane method island, and current generated source order.
- Rejected placements: LivingObjectPane.cpp, MapPane.cpp, PacketBuffer.cpp, Socket.cpp, TargetSelectionInputPanes.cpp, a new ProtocolSend module, and a synthetic aggregate body.
- Remaining uncertainty: exact original include arrangement and literal private method/local names are stripped. Existing source routing is sufficiently complete and is not blocked.

## Range / Split / Padding / Reclassification Analysis

- Exact target range: `[0x005ad360,0x005ad441)`, 225 bytes, SHA256 `5068082ECAFC229276C501CD2490218880D8C1F23386EB50510B28D202915000`.
- The three basic blocks are one ordinary guarded function. No independent prologue, return ABI, xref, table, data object, thunk, wrapper, or source child exists inside the range.
- Exact following padding: `[0x005ad441,0x005ad450)`, 15 all-`cc` bytes, SHA256 `54CC9DD9593316E80CCAF5D10856E6502A0D75F20473A92FA01D63228EF1624C`, no xrefs. Add it to UID0000VN ignored documentation and let compiler/linker output regenerate it.
- Successor `0x005ad450` is a separate modeled `sub_5AD450` size `0xaf` / current UID0004R4. The padding proves no overlap or fallthrough.
- Parent UID0001KM remains an ownerless, non-reconstructable, blank-formal mixed index at `90/92`, `Nested:0`. Target remains `Nested:0`; ignored padding is not a child and does not alter cumulative nesting.
- No UID rename, path rename, child registration, aggregate reclassification, or owner move is proposed.

## Negative Evidence Summary

- Zero target-start data/pointer/table xrefs and zero VA/RVA byte-pattern hits. Liveness is nevertheless direct through four rel32 calls.
- Zero xrefs to padding start and no modeled function/data inside the interval.
- No second caller function, no vtable slot, no callback pointer, no duplicated raw target body, and no inline-only route.
- No target string or resource establishes a better literal method/local name.
- No evidence for `NxRect`, `GetAttackTargetRect`, or target/object ID return semantics survives comparison with the direct callee.
- No null guard for `m_mapPane` or `g_packetSender`, no rectangle validity branch, no width/height clamp, no send result, and no exception/error path exist; source must not add them.
- The adjacent target-selection helper does not own or absorb the sender. Proximity is not ownership.
- Current broad reports are leads, not substitutes for this direct pass. Their valid owner/range facts are retained and stale body details are explicitly rejected.

## IDA Rename / Type / Comment Recommendations

- Source-facing function: retain `UserPane::SendAttackTargetPacket`; parameter spelling `direction`; select plain `char` from the direct target promotion chain. Explicit `signed char` is the equivalent-spelling runner-up; unsigned is rejected without matching x86 MSVC/source evidence.
- Source-facing local/type names: `MapRect targetBounds`, `unsigned short boundsChecksum`, `unsigned char packet[13]`.
- Source-facing callee: `MapPane::GetAdjacentVisibleTileBounds`; shared writer names `PacketBufferWriteUInt8` and `PacketBufferWriteUInt16BE`; sender `g_packetSender->QueueAndSendPacket`.
- Preserve current IDA raw names `sub_5AD360`, `sub_505650`, `sub_575380`, `sub_5753A0`, `sub_574BB0`, and `dword_67A7EC` only in evidence. They must not enter formal source.
- No IDA DB rename/type/comment edit was requested or performed. Documentation source names are sufficient.

## First-Draft C++ Recommendation

- Eligible: yes. UID0003V0 is a modeled, live, source-authored UserPane member with all behavior and dependencies closed.
- Destination 1, exact managed block applied to `by-memory/0x005ad360-0x005ad441.UserPaneSendAttackTargetPacket.md`:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void UserPane::SendAttackTargetPacket(char direction)
{
    if (m_isMoving)
        return;

    MapRect targetBounds;
    const unsigned short boundsChecksum =
        m_mapPane->GetAdjacentVisibleTileBounds(direction, &targetBounds);

    unsigned char packet[13];
    PacketBufferWriteUInt8(0x82, packet);
    PacketBufferWriteUInt8(direction, packet + 1);
    PacketBufferWriteUInt8(
        static_cast<unsigned char>(m_viewportColumn), packet + 2);
    PacketBufferWriteUInt8(
        static_cast<unsigned char>(m_viewportRow), packet + 3);
    PacketBufferWriteUInt16BE(
        static_cast<unsigned short>(targetBounds.left), packet + 4);
    PacketBufferWriteUInt16BE(
        static_cast<unsigned short>(targetBounds.top), packet + 6);
    PacketBufferWriteUInt8(
        static_cast<unsigned char>(
            targetBounds.right - targetBounds.left),
        packet + 8);
    PacketBufferWriteUInt8(
        static_cast<unsigned char>(
            targetBounds.bottom - targetBounds.top),
        packet + 9);
    PacketBufferWriteUInt16BE(boundsChecksum, packet + 10);
    packet[12] = 0;

    g_packetSender->QueueAndSendPacket(packet, 12);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Destination 2, exact complete managed block for `by-class/UserPane.md`; it preserves the full current union and changes only the target declaration from `unsigned char action` to `char direction`:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;
class MapPane;
class SelectObjectWithKeyboardPane;
class UserPane;
struct MapPoint;
struct ServerMessageEvent;

MapPoint *DirectionToTileOffset(
    MapPoint *outOffset, unsigned char direction);
void __stdcall DispatchCopiedEventPayload(
    const void *data, size_t size);

void ToggleTargetSelectionPane(bool alternateMode);
void NavigateTargetSelection(bool previous, bool chooseLocalPlayer);
void ReverseTargetSelectionDirection();
extern bool g_selectObjectTargetModeActive;
extern bool g_targetObjectTargetModeActive;
extern SelectObjectWithKeyboardPane *g_activeSelectObjectWithKeyboardPane;

static bool __stdcall HandleUIPanelSwitchPacket(
    const unsigned char *packet);
static void __stdcall SendDirectionPacket(unsigned char direction);
static void SendOpcode7Command(unsigned char command);
void RefreshGroupMemberMarkers(UserPane *userPane);
void ClearGroupMemberMarkers(UserPane *userPane);

struct GroupMemberRecord
{
    unsigned int memberId;                      // +0x000
    wchar_t name[128];                          // +0x004
    bool active;                                // +0x104
    unsigned short faceId;                      // +0x106
    unsigned char hairId;                       // +0x108
    unsigned char faceColor;                    // +0x109
    unsigned char hairColor;                    // +0x10a
    unsigned char skinColor;                    // +0x10b
    unsigned char bodyColor;                    // +0x10c
    unsigned char helmetId;                     // +0x10d
    unsigned char helmetColor;                  // +0x10e
    unsigned short faceDecorationId;            // +0x110
    unsigned char faceDecorationColor;          // +0x112
    unsigned short hairDecorationId;            // +0x114
    unsigned char hairDecorationColor;          // +0x116
    unsigned short secondFaceDecorationId;      // +0x118
    unsigned char secondFaceDecorationColor;    // +0x11a
    unsigned int maximumHitPoints;              // +0x11c
    unsigned int currentHitPoints;              // +0x120
    unsigned int maximumManaPoints;             // +0x124
    unsigned int currentManaPoints;              // +0x128
};

struct LocalInventorySlotRecord
{
    unsigned char active;
    unsigned char reserved001;
    unsigned short itemId;
    unsigned char iconStyle;
    unsigned char reserved005;
    wchar_t displayName[80];
    wchar_t itemMetaKey[80];
    wchar_t ownerName[80];
    unsigned char reserved1e6[2];
    unsigned int quantityOrCount;
    unsigned char quantityPromptFlag;
    unsigned char reserved1ed[3];
    unsigned int currentDurability;
    unsigned int protectionCount;
    unsigned char targetMode;
    unsigned char reserved1f9[3];
};

struct MovementWaypointSegment
{
    int startX;
    int startY;
    int endX;
    int endY;
};

struct SpellCommandSlotRecord
{
    unsigned char active;
    unsigned char reserved001[3];
    int inputKind;
    unsigned char reserved008[0xa0];
    wchar_t prompt[80];
};

struct LocalMovementHistoryRecord
{
    unsigned char active;
    unsigned char reserved01[3];
    int tileY;
    int tileX;
    unsigned char direction;
    unsigned char reserved0d[3];
};

class UserPane : public LivingObjectPane
{
public:
    enum UserTimerMessage
    {
        kUserPaneMovementStep = 20
    };

    UserPane();
    virtual ~UserPane();

    virtual void OnBoundsChanged(const RectBounds *bounds);
    virtual void OnClipBounds(RectBounds *clip, RectBounds *out);
    virtual void ShowNameLabel();
    virtual void HideNameLabel();
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool OnServerMessage(const ServerMessageEvent *event);
    virtual bool OnAnimationStep(int message, int frameOrDirection, int aux);
    virtual MapPane *GetMapPane();

    void SendGiveItemPacket(signed char slot, bool allItems);
    void SendDropItemPacket(signed char slot, bool allItems);
    CollectionPlayerDataView &GetCollectionData();
    const CollectionPlayerDataView &GetCollectionData() const;

    MapPoint *GetViewportPosition(MapPoint *outPosition) const;
    void ProcessMovement(unsigned char direction);
    void InitializeWalkAnimation(unsigned char direction);
    void StartDirectionalAnimation(char direction);
    LocalInventorySlotRecord *GetInventorySlotAddress(char inventorySlot);
    void DispatchConfiguredShortcutHotkey(short hotkeyNumber, int unused);
    void ExecuteHotkeyAction(short hotkey);
    void UseInventorySlot(unsigned char slot);
    void UseCommandSlot(unsigned char slot);
    void TryPerformAction();
    bool WarpToPosition(int x, int y, int viewportColumn, int viewportRow);
    LocalMovementHistoryRecord *GetActiveMovementHistoryRecordByIndex(
        unsigned char recordIndex);
    void ClearAllMovementHistoryRecords();
    void ClearMovementHistoryRecordByIndex(int recordIndex);
    void UpdateScreenPosition();
    void SendMovementPacket(unsigned char direction);
    void TryDispatchFunctionKeyShortcut(
        unsigned short functionKeyOrdinal, unsigned int currentTick);
    void CopyDeferredUserListPacket(
        const unsigned char *packetData, size_t packetSize);
    bool ParsePlayerSettingsPacket(const unsigned char *packet);
    bool ParseInventorySlotUpdatePacket(const unsigned char *packet);
    bool HandleServerEntryPacket(const unsigned char *packet);
    bool HandleWarpPacket(const unsigned char *packet);
    bool HandleMovementReplyPacket(const unsigned char *packet);
    bool HandleExtendedMovementReplyPacket(const unsigned char *packet);
    bool HandleChatMessagePacket(const unsigned char *packet);
    bool HandleUserListPacket(const ServerMessageEvent *event);
    bool HandlePositionSyncPacket(const unsigned char *packet);
    bool ParseGroupListPacket(const unsigned char *packet);
    void SendMovementWaypointPacket(
        unsigned char direction, unsigned short token,
        const MovementWaypointSegment *segment);
    void SendFaceDirectionPacket(unsigned char direction);
    void SendAutoFaceDirectionPacket();
    void SendActionPacketWithAutoFace();
    void SendAttackTargetPacket(char direction);
    void BuildInventorySlotRangeText(wchar_t *outText) const;
    void BuildSpellSlotRangeText(wchar_t *outText) const;

private:
    friend class MapPane;
    friend void RefreshGroupMemberMarkers(UserPane *userPane);
    friend void ClearGroupMemberMarkers(UserPane *userPane);

    GroupMemberRecord *FindGroupMemberById(unsigned int memberId);

    SpellCommandSlotRecord *GetSpellCommandSlotRecord(unsigned char slot)
    {
        return &m_spellCommandSlots[slot - 1];
    }

    void ClearMovementHistoryToken()
    {
        m_movementState[2] = 0;
        m_movementState[3] = 0;
    }

    void SetMovementReplyState()
    {
        m_movementState[1] = 1;
        m_movementState[2] = 1;
    }

    bool IsDirectionDelayActive() const
    {
        return m_movementState[4] != 0;
    }

    void SetDirectionDelayActive(bool active)
    {
        m_movementState[4] = active ? 1 : 0;
    }

    unsigned char m_userPaneBaseTail[0x0c];
    GroupMemberRecord m_groupMembers[50];
    signed char m_groupMemberCount;
    unsigned char m_preCollectionState[0x203];
    int m_currentSayMode;
    unsigned char m_preCollectionCommandState[2];
    bool m_collectionPanelSoundEnabled;
    unsigned char m_postCollectionCommandState[9];
    int m_localPlayerHitRadius;
    CollectionPlayerDataView m_collectionData;
    int m_screenX;
    int m_screenY;
    unsigned int m_screenState;
    RectBounds m_screenHitBounds;
    RectBounds m_screenLowerHitBounds;
    MapPane *m_mapPane;
    unsigned char m_playerSettingsState[8];
    LocalInventorySlotRecord m_inventorySlots[52];
    SpellCommandSlotRecord m_spellCommandSlots[52];
    bool m_spellCommandSlotsReady;
    unsigned char m_preViewportState[3];
    int m_viewportColumn;
    int m_viewportRow;
    int m_viewportHalfColumns;
    int m_viewportHalfRows;
    int m_viewportRemainingColumns;
    int m_viewportRemainingRows;
    unsigned char m_movementState[5];
    unsigned char m_preActionTickState[3];
    unsigned int m_lastActionTick;
    unsigned int m_lastMapCommandTick;
    unsigned int m_lastGroundItemCommandTick;
    List *m_whisperHistoryOther;
    List *m_outgoingWhisperRecipientHistory;
    List *m_incomingWhisperSenderHistory;
    unsigned char m_whisperHistorySource;
    unsigned char m_preMovementHistory[3];
    LocalMovementHistoryRecord *m_movementHistoryRecords;
    int m_movementHistoryCapacity;
    unsigned char m_movementHistoryWriteIndex;
    bool m_inputLocked;
    unsigned char m_movementHistoryState[2];
    unsigned char *m_deferredUserListPacket;
    size_t m_deferredUserListPacketSize;
    int m_deferredUserListCount;
    unsigned int m_deferredUserListDeadline;
    bool m_deferredUserListActive;
    unsigned char m_preMovementTicks[3];
    unsigned int m_lastMovementSendTick;
    unsigned int m_lastMovementInputTick;
    unsigned char m_actionMode;
    unsigned char m_userPaneTrailingState0;
    bool m_includeAdjacentMovementTargets;
    unsigned char m_userPaneTrailingState2[0x45];
};

typedef char GroupMemberRecordSizeMustBe300[
    sizeof(GroupMemberRecord) == 0x12c ? 1 : -1];
typedef char LocalInventorySlotRecordSizeMustBe508[
    sizeof(LocalInventorySlotRecord) == 0x1fc ? 1 : -1];
typedef char SpellCommandSlotRecordSizeMustBe328[
    sizeof(SpellCommandSlotRecord) == 0x148 ? 1 : -1];
typedef char LocalMovementHistoryRecordSizeMustBe16[
    sizeof(LocalMovementHistoryRecord) == 0x10 ? 1 : -1];
typedef char UserPaneSizeMustBe1305476[
    sizeof(UserPane) == 0x13eb84 ? 1 : -1];

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Behavior preservation: the code retains the exact signed-byte direction promotion, guard, helper calls, field narrowing, field order, spare zeros, explicit terminator, and sent length. Plain `char` matches target `movsx`; MapPane consumes the same low byte and maps every non-`0..3` pattern to default, while the UInt8 writer stores the same low byte for all 256 patterns. The source introduces no branch, clamp, null guard, wrapper, packet cursor, status return, or compiler mechanic.
- Source-era shape: fixed stack packet plus shared scalar writers and explicit casts matches established UserPane packet senders and the late-1990s/early-2000s utility API. `MapRect` and the MapPane helper are current project vocabulary, not decompiler labels.
- No third-party import directive applies. This is first-party NexusTK C++.

## Final Recommendation

- Destination 1 applies target `92/94`, the same UID/path/range/owner/emitter/reconstructable/position/nesting, complete plain-`char` C++, exact Item Summary, and full retained evidence/history.
- Destination 6 applies the complete UID0003YJ consumer proof with its score, metadata, nesting, boundaries, and blank formal unchanged.
- Destinations 2-5 and 7 are applied additively against the finalized B002/B003/B005 union: complete class declaration, file/source route, mixed-index detail, caller cardinality/map, and exact ignored alignment all now agree with the target.
- Keep UID000428, MapPane class/file, UID0001HU, g_packetSender global/storage, successor UID0004R4, viewport-field sources, and all unrelated UserPane siblings verify-only and unchanged.
- No ownerless item, no-code source body, source split, new child, IDA edit, staged hold, or investigable technical blocker remains.
- External lifecycle state is supervisor/validator-owned. This artifact neither asserts nor directs execution, count, move, or archive outcomes.

## Recommended Target Doc Changes

- Path: `by-memory/0x005ad360-0x005ad441.UserPaneSendAttackTargetPacket.md`.
- Applied `COMPLETION:92`, `CONFIDENCE:94`; retained UID0003V0, `CANONICAL_OWNER:0000FQ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000FQ`, blank emitter position, and `Nested:0`.
- Destination 1 was applied exactly and scoped-validated by command `13329`; final SHA256 `1C0748AC408BC66C403D0375F5059B3093860DE9F248C0E82872ECF1336E8888`.
- Exact Item Summary: `Source-ready UserPane plain-char directional attack-target sender with one movement-state gate, MapPane adjacent-visible MapRect/checksum, value-first opcode-0x82 serialization, exact viewport/rectangle fields, 12-byte payload plus unsent local terminator, one caller function/four call sites, and complete C++.`
- The target page now contains the exact bytes/hash/CFG/ABI/caller/callee/field/packet/range/padding/source-route/generated/manual evidence from this report at report-level detail.
- Historicalize all LivingObjectPane, unresolved signature/name, blank-C++, `NxRect`, `GetAttackTargetRect`, `targetId`, destination-first, direct-byte, and four-caller assumptions. Preserve them as rejected provenance rather than deleting them.
- Preserve no-pointer-route evidence as route classification only; it does not override four direct calls or justify no-code.

## Recommended Support Doc Changes

- Destination 2 `by-class/UserPane.md`: retained `93/94`, UID/path/owner/emitter/position, inheritance, records, fields, size guards, every method, `[[CHILDREN]]`, and unrelated prose/formals; applied the complete report block and bounded evidence under validator `13357`. Current SHA256 is `E26015F2CCD8AC4A85AB9577FD6787B5CBDDFA0087FCE029FD5F5CED89EE865B`. Normalized managed-block parity with the report is exact.
- Destination 3 `by-file/UserPane.md`: retained `92/93`, route/path, source inventory, and prose-only status; added exact caller, MapRect/checksum, writer, payload/terminator, dependency, and one-definition policy under validator `13358`. Current SHA256 is `61E8074B8ACAD9E78C8564C71AC1F1B2170F732EE42B9293734E6D1E085D1B85`.
- Destination 4 `by-memory/0x005a2de0-0x005ad441.UserPaneLocalPlayerExtensions.md`: retained `90/92`, NONE/FALSE/blank emitter/position/formal, `Nested:0`, every child and unrelated history; replaced both shallow target rows and added complete bounded detail under validator `13359`. Current SHA256 is `1C722A0EADF365953B017B4228A2A928BD037EF80D7BEEC95BC453D9FF5D2C87`.
- Destination 5 `by-memory/0x005a5bd0-0x005a7422.UserPaneHandleKeyOrTextEvent.md`: retained `92/94`, metadata, and complete formal byte-for-byte; added exact one-function/four-site and `0x80/81/82/83 -> 3/0/1/2` prose under validator `13363`. Current SHA256 is `DCCB409399ADD8407B10A3D1820C6BA3ED701C46A47CD5C836A5D9B7E2D7DD36`.
- Destination 6 `by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md`: applied UID0003V0's exact six UInt8 and three UInt16BE calls, value-first order, target `movsx`, writer low-byte preservation, narrowing/no-clamp semantics, spare-zero overwrite, explicit byte-12 zero, and 12-byte send. Command `13331` validated the page at final SHA256 `7BAB13784EB789F6886309E9D165BF3936995EC14587F176BC457F70A88BF781`; `87/91`, owner/emitter, blank formal, split/nesting, all prior consumers, and ABI caveats are preserved.
- Destination 7 `by-memory/-ignored.md`: added only `[0x005ad441,0x005ad450)` with exact 15 `cc` bytes, SHA256, no-xref/no-source proof, predecessor UID0003V0, successor UID0004R4, and compiler-regenerated disposition. Validator `13364` exposed and normalized one newly mistyped owner UID; B004 corrected it to UID0000OH and validator `13365` removed the transient UID0000RG reference. Current SHA256 is `C6CB2C06605740D6E68A796357F95A71897F13C5A358326BA444CC2D6E646B31` with the complete prior union preserved.
- Verify-only unchanged: UID000428, by-class/MapPane, by-file/MapPane, UID0001HU, UID0000Q5, UID0001P0, UID0002RW, UID00024A, UID0004R4, and every unrelated UserPane sibling. Their current unsigned declarations are not used as evidence for target signedness; direct low-byte/default-path analysis proves the selected target conversion preserves their full behavior.

## Score And Metadata Recommendation

- Historical pre-callback target: `86/89`, UID0003V0, owner/emitter UID0000FQ, reconstructable true, blank position, `Nested:0`.
- Current callback target: `92/94`, all metadata except scores unchanged.
- Completion rises because exact body, shared types/helpers, argument order, packet fields/length, caller cardinality, source route, range, padding, generated state, and manual handoff are closed. Confidence rises because live MCP and independent current dependencies converge.
- Reason not higher: stripped symbols do not prove literal method/parameter/local spellings; plain `char` versus explicit `signed char` remains a code-generation-equivalent spelling choice; 16-byte aligned stack reservation leaves `[13]` versus `[16]` authored capacity lexically uncertain. These do not alter the full-domain direction behavior or packet behavior.
- Score-improvement attempts completed: exact bytes/hash/range; CFG/frame; xref and pointer-route; caller values/count; helper decompile and signature; writer ABI; Socket length/terminator; field layout; sibling packet-shape/local-capacity controls; old-report/current-doc/generated/manual/tracker searches; source owner/placement; padding/successor; active shared-work coordination.
- Support scores and metadata remain unchanged. No unrelated score inflation is recommended.

## Open Questions With Attempted Resolution

- Exact original parameter signedness: resolved to plain `char`. The target's own `movsx eax,bl` before UInt8 serialization and Hex-Rays `char` outweigh family style; caller pushes `0/2/3/1` and the helper-call `push ebx` are non-discriminating. MapPane maps every non-`0..3` byte pattern to default under either extension, and UInt8 stores only the low byte, so the selected source preserves the complete 8-bit behavior. Explicit `signed char` remains only a code-generation-equivalent spelling runner-up; unsigned is rejected absent matching compiler evidence.
- Exact original local capacity: exact accesses require 13 bytes, while the compiler reserves an aligned 16-byte slot. Selected `[13]` because it expresses 12-byte payload plus explicit local terminator and matches current source conventions. `[16]` remains a bounded runner-up; no packet behavior changes.
- Exact original method/local spellings: no symbols, strings, or UDT names survive. Selected stable project names grounded in behavior. Alternative names are lexical only and do not justify blank C++.
- Whether UInt8 calls should be replaced by assignments: rejected. The target contains direct calls to the shared helper, and current helper docs identify the source API.
- Whether the helper return is a target ID: rejected. Live helper returns rectangle checksum after clipping.
- Whether padding belongs to the target: rejected by exact function end, all-`cc` interval, zero xrefs, and independent successor.
- Remaining unresolved questions: none that block score, owner, range, source placement, or formal C++. Only the documented lexical alternatives remain.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Read-only manual rows inspected: by-memory UID0003V0, UID0001KM, UID0003V9, UID000428, UID0003YJ, UID0001HU, UID0000VN neighborhood; by-class UID0000FQ and UID00007Q; by-file UID0000P1, UID0000L3, and UID0000M8; by-global UID0000Q5. Existing rows were compared against every proposed path/title/score/reconstructable/split/source-quality change.
- Historical report-only manual baselines were by-memory `813C1D7B...0D7E`, by-class `EE221C5F...1FE3`, by-file `C245479A...A8CF`, and by-global `61BC4D63...5425`. Current callback-time by-memory coverage SHA256 is `DE7F3A933FDECAF92F4924FAE5EF750A2539A03E47240F0F0C6B400D8C5857EC`; direct line 3340 still has `86% : strong` and `four-caller`, and no `0x005ad441-0x005ad450` row exists. The full current neighborhood keeps UID0003UY, UID0003H4, UID0003H5, and UID0003UZ at lines 3336-3339, the stale UID0003V0 row at line 3340, and UID0004R4 at line 3341. Replacing only line 3340 and inserting the padding row immediately before the current line-3341 successor therefore preserves every surrounding row and the exact target-to-padding-to-successor adjacency.
- Replace current UID0003V0 row at `by-memory/-coverage-report.md` current line 3340 with exactly:

```text
        - [UID:0003V0][0x005ad360-0x005ad441.UserPaneSendAttackTargetPacket](by-memory/0x005ad360-0x005ad441.UserPaneSendAttackTargetPacket.md) 0x005ad360-0x005ad441 | UserPane member | UserPaneSendAttackTargetPacket : reconstructable : 92% : very-strong : Exact source-ready one-caller-function/four-callsite plain-char directional opcode-0x82 sender with m_isMoving gate, target movsx promotion, MapPane adjacent-visible MapRect/checksum, value-first scalar serialization, viewport and rectangle fields, 12-byte payload plus unsent local terminator, exact range/hash, UserPane.cpp route, and complete C++.
```

- Insert immediately after that target row and before UID0004R4 with exactly:

```text
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005ad441-0x005ad450 | padding | UserPane attack-target sender to target-selection helper alignment : ignored : 100% : very-strong : Exact fifteen-byte all-0xcc compiler/linker alignment after UID0003V0 and before independent UID0004R4; SHA256 54CC9DD9593316E80CCAF5D10856E6502A0D75F20473A92FA01D63228EF1624C, zero xrefs, and no handwritten source role.
```

- No other manual replacement is required: UID0000FQ/0000P1 rows remain correct at `93/94` and `92/93` and do not spell the target's stale local names; UID0001KM and UID0003V9 rows remain correct on score/path/reconstructable/split; UID000428 already states the adjacent-visible MapRect/checksum contract and its row does not assert target signedness; UID0003YJ already states value-first ABI and low-byte writing; UID0001HU and UID0000Q5 remain correct; MapPane rows are unchanged.
- No tracker text is supplied. `auto-generated/-ag-research-tracker.md` is validator-owned and was read only.
- B004 must not apply manual rows because manual coverage is supervisor-owned and explicitly forbidden in this assignment.

## Follow-Up Actions

- The supervisor accepted the exact pre-callback artifact and authorized the staged callback. Both shared-lane releases were consumed, all accepted ordinary implementation and generated verification are complete, and no implementation item remains.
- B004 itself performed no manual coverage, report execution/count, report movement, or archive action. Validation, execution, count, path, move, and archive state are external supervisor/validator-owned and are neither asserted nor directed by this artifact.
- A-agent actions: none. No owner, IDA mutation, source split, or unavailable evidence is delegated.
- B004 future research actions: none for target behavior, source shape, owner, range, caller graph, packet layout, helper identities, source route, or C++ eligibility. Residual lexical uncertainty is already scored rather than deferred.

## Confidence

- Recommendation confidence: very strong for retention as one live UserPane source member and for every behavior/range/packet/source-route decision.
- Score confidence: strong for `92/94`; all investigable blockers are resolved, with remaining uncertainty limited to stripped lexical spelling and local capacity.
- Evidence-time MCP confidence: health and bounded calls succeeded on database `64c11373`; no claim relies on the failed wrong-schema byte request.
- Final signedness MCP pass: fresh protocol session `3821b75f-f145-4655-a3d2-dd73b720be08` ran `idb_list`, `server_health`, target/helper/writer `decompile` and `disasm`, target `xrefs_to`, and caller disassembly successfully through `2026-07-15T17:05:00-04:00`. The sole evidence-time IDB was `64c11373`/worker PID 21508; health was `ok` with analysis/Hex-Rays/string cache ready. The exact target, caller, MapPane, and UInt8 instruction chains recorded above are from this pass.
- Remaining uncertainty has no owner/emitter/range/C++ impact.

## Validator Results

- Historical report-only state: no validator or generated-refresh command was run before exact-artifact Gate 1 acceptance.
- Phase A Destination 1 command: `python .\tools\validator.py --mode file --file by-memory/0x005ad360-0x005ad441.UserPaneSendAttackTargetPacket.md --apply --queue-timeout 240`; command ID `000000013329`; timestamp `2026-07-15T17:31:31-04:00`; process exit `0`; scanned Markdown `1`; `ok:1`; warnings/errors `0`.
- Command `13329` applied `completion_update:1` (`92`), `confidence_update:1` (`94`), `autogen_registry_update:1`, `reference_index_add:3`, `uid_link_update:3`, `projected_stats_update:1`, and deferred generated refresh. Validator-managed link normalization changed UID0003V9 to its exact titled link, UID000428 to current path `0x00505650-0x00505730.MapPaneGetAdjacentVisibleTileBounds.md`, and UID0001HU to current path `0x00574bb0-0x00574c13.QueueAndSendPacket.md`; no unrelated target prose or formal content changed.
- Phase A Destination 6 command: `python .\tools\validator.py --mode file --file by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md --apply --queue-timeout 240`; command ID `000000013331`; timestamp `2026-07-15T17:32:40-04:00`; process exit `0`; scanned Markdown `1`; `ok:1`; warnings/errors `0`.
- Command `13331` applied `reference_index_add:1` for UID0003V0, `projected_stats_update:1`, and deferred generated refresh. It made no content rewrite, score/formal/metadata change, warning, or error on UID0003YJ.
- Destination 2 command `python .\tools\validator.py --mode file --file by-class/UserPane.md --apply --queue-timeout 240`; command ID `000000013357`; timestamp `2026-07-15T18:02:27-04:00`; exit `0`; `ok:1`. Side effects were autogen registry update, UID0003V0 reference-index add, projected stats update, and deferred generation. Five pre-existing missing UID0003V8/UID0003VC references were warned; no target-specific error or unintended managed-block change occurred.
- Destination 3 command `python .\tools\validator.py --mode file --file by-file/UserPane.md --apply --queue-timeout 240`; command ID `000000013358`; timestamp `2026-07-15T18:03:11-04:00`; exit `0`; `ok:1`. Side effects were UID0003V0 reference-index add, projected stats update, and deferred generation. Eighteen pre-existing missing-reference warnings were reported; no target-specific error or by-file formal metadata was introduced.
- Destination 4 command `python .\tools\validator.py --mode file --file by-memory/0x005a2de0-0x005ad441.UserPaneLocalPlayerExtensions.md --apply --queue-timeout 240`; command ID `000000013359`; timestamp `2026-07-15T18:04:14-04:00`; exit `0`; `ok:1`. Side effects were UID000428/UID0004R4 reference-index adds, projected stats update, and deferred generation. Seven pre-existing UID0003JN/UID0003V8/UID0003VC warnings were reported; parent metadata/formal remained exact.
- Destination 5 command `python .\tools\validator.py --mode file --file by-memory/0x005a5bd0-0x005a7422.UserPaneHandleKeyOrTextEvent.md --apply --queue-timeout 240`; command ID `000000013363`; timestamp `2026-07-15T18:10:12-04:00`; exit `0`; `ok:1`; warnings/errors `0`. Side effects were projected stats update and deferred generation; the managed caller body remained unchanged.
- Destination 7 first command `python .\tools\validator.py --mode file --file by-memory/-ignored.md --apply --queue-timeout 240`; command ID `000000013364`; timestamp `2026-07-15T18:11:15-04:00`; exit `0`; `ok:1`. The broad page retained 271 pre-existing missing-reference warnings, added four reference-index entries, and normalized the newly mistyped UID0000RG owner link to its registry target. B004 immediately corrected that new line to actual TargetSelectionInputPanes UID0000OH while the same lease remained active.
- Destination 7 corrective command with the same scoped syntax: command ID `000000013365`; timestamp `2026-07-15T18:11:43-04:00`; exit `0`; `ok:1`. It removed the transient UID0000RG reference, retained the 271 pre-existing broad-page warnings, updated projected stats, and deferred generation. Direct readback has exact UID0000OH text and no target-interval UID0000RG link.
- Final authorized command `python .\tools\validator.py --mode file --file by-memory/0x005ad360-0x005ad441.UserPaneSendAttackTargetPacket.md --apply --queue-timeout 240 --wait-generated`; command ID `000000013366`; timestamp `2026-07-15T18:12:05-04:00`; exit `0`; `ok:1`; generated refresh completed at the same command/timestamp. Side effects were registry rebuild (`4998` nodes/`4028` edges), generated metadata refresh `281`, fallback child inserts `14`, missing-child-marker warnings `85`, emitter-no-code warnings `160`, and projected stats update. Those broad generated warnings are unrelated to UID0003V0; the target has no empty marker or missing body.
- Current `auto-generated/NexusTK/ui/panels/UserPane.cpp`: command/header `13366`, SHA256 `D0F4649538FF7A9DBAF8A612B3B176F8F8E4A3CA588B3F97BE8FCA13DB97CB4B`, 90,317 bytes, 2,697 lines. Counts are declaration `1`, definition `1`, provenance `1`, `MapRect targetBounds` `1`, `GetAdjacentVisibleTileBounds` `1`, target UInt8 calls `6`, target UInt16BE calls `3`, `packet[13]` `1`, `packet[12] = 0` `1`, and `QueueAndSendPacket(packet, 12)` `1`. Target Empty Emitter Marker, stale unsigned declaration, `NxRect`, `GetAttackTargetRect`, and `targetId` counts are all `0`.
- Shared-union generated readback remains collision-free: one each UID0003H5, UID0003UZ, UID0003UA, UID0003UP, and UID0003UQ definition; UID0003H4 has one file-scope prototype and one definition, not duplicate source bodies. The complete UserPane class closes before qualified definitions, and existing B002/B003/B005 content is preserved.
- Formal equality after CRLF/LF normalization: report Destination 1 equals UID0003V0 exactly, 36 lines, SHA256 `0CE0E13A038B302FF83C2E6710342723D52132671414D9625A45D7804A05E06D`; report Destination 2 equals by-class/UserPane exactly, 269 lines, SHA256 `FC5A2DA4A441ACB0F1A935D3C999C0266933AD182DDCF3D4BE804F9803D6901F`.

## Changed Files

- Historical creation: `tools/leaser/Agents/Agent-B004/research/0003V0-UserPaneSendAttackTargetPacket-source-quality.md`. The same report is modified in place with complete callback proof.
- B004 modified exactly the seven accepted ordinary by-* destinations below. B004 manually modified no restricted/manual/generated/tracker/audit/supervisor/validator/lifecycle/IDA file. Generated registry/statistics/reference artifacts changed only through authorized scoped validators and the final waited refresh recorded above.
- Complete before/after inventory:

| # | Ordinary destination | Pre-callback SHA256 | Current SHA256 / validator proof |
| ---: | --- | --- | --- |
| 1 | `by-memory/0x005ad360-0x005ad441.UserPaneSendAttackTargetPacket.md` | `3DD4BE9AD7F546677E34FAA6935F29CF4A4886A84887E4EE41BAEAAB6A03C060` | applied/validated `1C0748AC408BC66C403D0375F5059B3093860DE9F248C0E82872ECF1336E8888` |
| 2 | `by-class/UserPane.md` | `31F6DC7CBEECDBF6791EDFD45726C9BE45543F03BC1259857220F60935271B88` | `E26015F2CCD8AC4A85AB9577FD6787B5CBDDFA0087FCE029FD5F5CED89EE865B`; `13357` |
| 3 | `by-file/UserPane.md` | `0B19A8D0EF7F40B1ABD37540C63BD1482197BE5886E4DC22208C66BF0A0932A3` | `61E8074B8ACAD9E78C8564C71AC1F1B2170F732EE42B9293734E6D1E085D1B85`; `13358` |
| 4 | `by-memory/0x005a2de0-0x005ad441.UserPaneLocalPlayerExtensions.md` | `913963EF854015CFDD672090F9704C24CD0EA07B521C45951350E3538ABD03EA` | `1C722A0EADF365953B017B4228A2A928BD037EF80D7BEEC95BC453D9FF5D2C87`; `13359` |
| 5 | `by-memory/0x005a5bd0-0x005a7422.UserPaneHandleKeyOrTextEvent.md` | `223EA17E0DE68BD44C3A4B6C73CD0A5A559E9D318C803A6BD09C9B62A545F68A` | `DCCB409399ADD8407B10A3D1820C6BA3ED701C46A47CD5C836A5D9B7E2D7DD36`; `13363` |
| 6 | `by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md` | `04431D4E22FC9701E2A4B53D6087D0EF36ADFFBAEEF7112A087F21799106C263` | applied/validated `7BAB13784EB789F6886309E9D165BF3936995EC14587F176BC457F70A88BF781` |
| 7 | `by-memory/-ignored.md` | `6AD59C28E4CFA27D35B93989804E9BDE365F467630D0ED822CEE9240909B779C` | `C6CB2C06605740D6E68A796357F95A71897F13C5A358326BA444CC2D6E646B31`; `13364`, corrective `13365` |

- Verify-only baselines: UID000428 `1589E4F1E3A221A9059A8FA4B882F16C317F40E5A0930406F97BD5F6EBB0B232`; by-class/MapPane `D3F3533C3AE10F1139D37F177012F4FE5F8D367F43FAD3C3F0F7FA8E1CE7A4C0`; by-file/MapPane `C0EA3DCA80F8306455CE1AE24100FCDD5976A41A2872B2139551DB6FCF4F20E3`; UID0001HU `D1CB9DC553688DF59312849A06CA968DD9ECA2E623CA937348B25E7E787224E2`; g_packetSender `B79FB4848A0D59B7A1F45A01032BDA67CFD1D1EC2274C732D294188C898FCE1F`; Config class/file `9ECA99799904B0DD1E6D14E0C84DC784B578E2C31555C3AD7472C9B7A304B473` / `91984E67C9F7E99F2252203A65C892654531030AF190C7DAB7E2F0497FE3D577`. These were read only and preserve the complete overlap contracts.
- Leases used/released: B004 took one short lease per Destination 1, 6, 2, 3, 4, 5, and 7 immediately before its edit/validator window. Every `unlease` returned `Success`; the temporary hold arrived only after UID0001KM command `13359` and release were complete. Destination 7 stayed leased only for commands `13364`/`13365` and the immediate owner-link correction. Final readback reports no active lease.
- Report execution: not run. No report lifecycle/probe/count/move/archive command was run.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation completed for exact pre-callback SHA256 `A36C2F5EC38984FD93B3BFE567FC5784F4F8C81EDFD6D81833065C3BE01D1BB6` before implementation.
- [x] Applied C3V0-001 through C3V0-046 exactly: 28 `applied`, 16 `already-present`, 2 manual-coverage `excluded-with-reason`, and 0 `blocked`.
- [x] Applied Destination 1 to UID0003V0 with exact `char direction` and raised `86/89 -> 92/94` without changing UID/owner/emitter/reconstructable/position/nesting/range/route; validator `13329` passed.
- [x] Applied complete Destination 2 to by-class/UserPane, changing only target `unsigned char action` to `char direction` in the formal while preserving the complete current union; validator `13357` passed and normalized parity is exact.
- [x] Updated by-file/UserPane, UID0001KM, and UID0003V9 at report-level detail without changing their scores or formal-body dispositions; validators `13358`, `13359`, and `13363` passed.
- [x] Updated UID0003YJ with exact target consumer evidence without changing score/owner/emitter/nesting/formal; validator `13331` passed.
- [x] Added exact `[0x005ad441,0x005ad450)` ignored alignment without creating a child or changing UID0000VN metadata; commands `13364`/`13365` passed.
- [x] Preserved UID000428, MapPane class/file, UID0001HU, g_packetSender global/storage, UID0002RW, UID00024A, UID0004R4, Config class/file, and unrelated UserPane siblings verify-only throughout the callback.
- [x] Preserved exact bytes/hash/CFG/frame/ABI/caller/callee/field/packet/range/padding evidence in the report and accepted destinations.
- [x] Preserved one caller function/four call sites, exact positive immediate pushes, exact case/direction mapping, and their non-discriminating signedness status on UID0003V0.
- [x] Preserved target `movsx eax,bl`, MapPane low-byte/default-path equivalence, UInt8 low-byte storage, opcode/field order, value-first writers, narrowing, no-clamp behavior, local byte-12 zero, send length 12, and Socket queued-copy terminator distinction across Destinations 1 and 6.
- [x] Preserved `[13]` as the highest-probability local capacity and `[16]` as bounded runner-up without conflating inference with binary fact.
- [x] Historicalized stale LivingObjectPane/blank/open/NxRect/GetAttackTargetRect/targetId/destination-first/four-caller claims on the target without deleting provenance.
- [x] Consumed both `SHARED_LANE_RELEASED` authorizations; reread/rebased finalized B002/B003/B005 artifacts and all five shared destinations without loss.
- [x] Kept all proposed C++ only in the two exact complete managed blocks; emitted no sample/body-only/decompiler C++.
- [x] Confirmed third-party import is not applicable; no import directive or third-party block was added.
- [x] Retained exact manual coverage replacement/addition pending supervisor ownership; B004 did not edit coverage.
- [x] Before callback authorization, B004 ran no validator, generated refresh, IDA mutation, execute_report, lifecycle, count, move, or archive command.
- [x] Final rehash completed for all seven destinations, generated UserPane.cpp, tracker, manual coverage, finalized B002/B003/B005 reports, Config verification pages, and leases.

Implementation callback pass:

- [x] Exact report artifact SHA256 `A36C2F5EC38984FD93B3BFE567FC5784F4F8C81EDFD6D81833065C3BE01D1BB6` accepted by supervisor for implementation.
- [x] Shared B002/B003/B005 callback order was obeyed; no shared edit began before direct release and then-current artifact/destination reread.
- [x] Destination 1 reread under a short B004 lease, edited exactly, scoped-validated by command `13329` (`exit 0`, `ok:1`), and lease released successfully.
- [x] Destination 2 reread/rebased under a short B004 lease, complete formal applied without loss, scoped-validated by `13357`, and lease released immediately.
- [x] Destination 3 reread/rebased under a short B004 lease, bounded prose applied, scoped-validated by `13358`, and lease released immediately.
- [x] Destination 4 reread/rebased under a short B004 lease, bounded row/detail applied, scoped-validated by `13359`, and lease released immediately.
- [x] Destination 5 reread under a short B004 lease, bounded one-caller/four-site prose applied with formal unchanged, scoped-validated by `13363`, and lease released immediately.
- [x] Destination 6 reread under a short B004 lease, exact consumer proof applied with formal/score unchanged, scoped-validated by command `13331` (`exit 0`, `ok:1`), and lease released successfully.
- [x] Destination 7 reread under a short B004 lease, exact padding entry added without loss, scoped-validated by `13364` and corrective `13365`, and lease released immediately.
- [x] All C3V0 claims reconciled to legal terminal states with claim-group destination/validator proof: 28 `applied`, 16 `already-present`, 2 `excluded-with-reason`, 0 `blocked`.
- [x] Historical, negative, rejected, ranked-alternative, score-cap, and active-coordination evidence preserved without compression.
- [x] One authorized final waited UID0003V0 validation completed after all ordinary edits under command `13366`.
- [x] Historical Phase A and final command-13366 UserPane.cpp readbacks are recorded; matching class declaration and every final target assertion pass.
- [x] Current path/hash/command/timestamp/exit/ok/warning/side-effect inventory recorded for all seven changed pages and the final waited refresh.
- [x] Exact manual coverage handoff retained for supervisor; no manual coverage edit performed by B004.
- [x] All accepted implementation items are terminal; no B004 lease remains and no forbidden manual file or lifecycle command was used.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000013373","destination_path":"executed-b-agent-research/B004/0003V0-UserPaneSendAttackTargetPacket-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0003V0-UserPaneSendAttackTargetPacket-source-quality.md","timestamp":"2026-07-15T18:34:57-04:00","uid":"0003V0"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
