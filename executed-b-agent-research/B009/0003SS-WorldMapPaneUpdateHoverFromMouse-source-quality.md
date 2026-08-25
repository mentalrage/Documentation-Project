# 0003SS WorldMapPane UpdateHoverFromMouse Source-Quality Research
** TARGET-REPORT-UID:0003SS **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **


## Finalized Report / Current Recommendation

- Current recommendation: reconstruct [UID:0003SS] as the private void WorldMapPane::UpdateHoverFromMouse() method in NexusTK/map/WorldMapPane.cpp, retain the existing UID0000G9 class owner and UID0000PB emitter, and raise the target from 85/88 to 93/94.
- Final disposition: the exact 0x66-byte function polls EventMan for the current cursor, calls WorldMapPane::HitTestNode(cursor.x, cursor.y), clears m_hoveredNodeIndex only when the hit-test misses, accepts a nonnegative hit only when m_reachableNodes marks it reachable, and calls Pane::InvalidateRect(0) only when the stored hover value changes.
- Ordinary callback result: C001-C026 and C043-C045 are implemented. The target now contains the exact formal CPP body at 93/94, its H fragment remains blank because UID0000G9 owns the declaration, and all seven support pages preserve the accepted behavior/boundary evidence without populating UID0003ST, UID0003SJ, or UID0003SM source bodies or granting those support UIDs report coverage.
- Supervisor-owned remainder: C027-C042 remain sealed and unchecked. Any later Gate 2, manual-coverage, execution, or archive disposition is authoritative only from external supervisor audit and validator-owned status/history metadata, not from a current pending state asserted by this report.
- Confidence: very high for range, ABI, behavior, fields, caller branches, side effects, owner, emitter, and source placement; high for the private descriptive names because no PDB or original source survives.

## Supporting Research

The 2026-08-24T08:40:57Z receipt from session supervisor_uid0000jr_canonical_verify_20260824_064700 and the 2026-08-24T11:26:39Z receipt from session supervisor_uid0000kf_postpromotion_verify_20260824_1034 are dated earlier research evidence, not current session authority. The latest report-repair read-only snapshot was taken on 2026-08-24T15:00:04Z through canonical-path session supervisor_uid0003qf_canonical_verify_20260824_143100. Runtime attestation identified listener PID 3612, redirector PID 24976, canonical path E:\NTK\Resources\NexusTK\NexusTK.exe.i64, and the current role-specific implementation manifests; bounded health returned status ok, Hex-Rays ready, image base 0x00400000, the canonical IDB path, input path C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe, auto_analysis_ready:false, and strings_cache_ready:true. Fresh func_profile, lookup_funcs, stack_frame, get_comments, get_bytes, xref_query, and type_inspect reads all succeeded. This remains a dated evidence snapshot; future-current authority requires a fresh supervisor attestation and bounded reread.

Earlier canonical-IDB receipts were 143,211,656 bytes with SHA256 61087D8ADDD7711165105997D2AA86318C5BEFC856015921DA6D9E798CEAAEF3 at 2026-08-24T08:14:37.4345386Z and SHA256 3A5DE2DE5C50ABFDAA0C627C10641704C69D91DDE96FB483DD36C3FDE3D66911 at 2026-08-24T10:28:24.9739425Z. The 2026-08-24T14:27:03.4932477Z repair snapshot was the same 143,211,656-byte canonical IDB with SHA256 B0B1EB4651D6AB2E122A25416DF56B5F2A9FF2CFB1253E734AFEA2AB36731D67. The imported executable at both the MCP input path and E:\NTK\Resources\NexusTK\NexusTK.exe remained 2,679,296 bytes with SHA256 9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632. Every hash is a dated disk receipt rather than permanent authority.

The B001 world-map split report and executed UID0003SC/UID0003SR reports were used only as leads. Every target behavior, boundary, caller, callee, field, type, and name-collision fact was independently rechecked through the dated 2026-08-24T15:00:04Z canonical MCP snapshot and ordinary/generated documentation; future gates must establish fresh authority again.

## Target

- Target UID: 0003SS.
- Additional target UIDs: none. UID0003ST, UID0003SJ, UID0003SM, UID0000G9, UID0000PB, UID0001O4, and UID0000VN are support destinations only.
- Target path: by-memory/0x005c5080-0x005c50e6.WorldMapPaneUpdateHoverFromMouse.md.
- Exact machine range: [0x005c5080,0x005c50e6), 0x66 bytes.
- Queue state at assignment: reconstructable, directly uncovered, score 85/88, owner UID0000G9, emitter UID0000PB, empty formal CPP/H, an active empty marker in auto-generated/NexusTK/map/WorldMapPane.cpp, and file completion 6/28 (21.4%).
- Durable classification: this report records the completed ordinary implementation callback for one reconstructable private WorldMapPane method; remaining supervisor-owned claims are sealed below.
- Source unit: NexusTK/map/WorldMapPane.cpp, with the class declaration owned by by-class/WorldMapPane.md and no target-owned duplicate header fragment.

## Current Target State

- Gate 1 pre-callback metadata was COMPLETION:85, CONFIDENCE:88, CANONICAL_OWNER:0000G9, RECONSTRUCTABLE:TRUE, EMITTER_UIDS:0000PB, blank optional position, Nested:0, and blank CPP/H blocks. That state is dated history, not current ordinary-document authority.
- Current ordinary metadata is COMPLETION:93, CONFIDENCE:94 with the same owner/emitter/reconstructable/position/Nested values. The exact CPP body is populated; the H block is intentionally blank because UID0000G9 already emits the declaration.
- Gate 1 prose had identified a hover helper and HitTestNode relation while retaining the older unresolved-name/field statement as current history. The callback replaced that stale active blocker with exact range/ABI/behavior/fields/callers/sibling/boundary/source evidence and an explicit historical-assumption resolution.
- Dated 2026-08-24T15:00:04Z IDA prestate is function sub_5C5080, public type unsigned int __thiscall(_DWORD *this), exact range 0x005c5080-0x005c50e6, five basic blocks, 39 instructions, no strings, and absent regular, repeatable, function-regular, and function-repeatable comments. The sibling retained the same raw type/name/comment shape at 0x005c50f0, and both proposed names remained collision-free.
- Current target body SHA256 is FDD207906B32F452FB48C445080B1C85C75E28B51EBCEF87CDF0F6E73C3F9041.
- Historical pre-callback generated snapshot: command 000000027513 / 2026-08-24T04:21:21-04:00, 13,304 bytes, SHA256 5989105221636CF92AC93ED967AB0504E0DFC1498A242DCD1AB556968C7D5948, 333 LF, zero CR, terminal LF, last write 2026-08-24T08:21:46.8751360Z, one UID0003SS empty marker, 22 total empty markers, one class declaration, and no WorldMapPane.h.
- Dated callback-generated receipt: command 000000027536 / 2026-08-24T05:16:12-04:00 completed foreground refresh; the resulting WorldMapPane.cpp was 13,670 bytes, SHA256 966F17663AC6FA924025DB6C2F4E716338A6D8E9B4FCF379656F241443A8AEFC, 347 LF, zero CR, terminal LF present, and last write 2026-08-24T09:16:44.7361870Z. This is callback history, not current generated identity.
- Dated later generated readback: header command 000000027608 / 2026-08-24T06:10:10-04:00 produced a 13,670-byte WorldMapPane.cpp with SHA256 F5736BF2BC4F7505647549700BBE4BBC3268BF0288F06E6819525C6B8041C678, 347 LF, zero CR, terminal LF present, and last write 2026-08-24T10:10:35.6282478Z. This is repair-cycle history after the callback, not current generated identity.
- Latest dated generated snapshot at this repair: header command 000000027631 / 2026-08-24T09:31:09-04:00. Physical auto-generated/NexusTK/map/WorldMapPane.cpp was 13,670 bytes, SHA256 11C47ACBC59CD5BA30A94C86D45C1EABF06F3C900CE60047188FC852500FF567, 347 LF, zero CR, terminal LF present, and last write 2026-08-24T13:31:41.3073793Z. Its semantics were unchanged from the earlier dated receipts: exactly one target declaration, one UID0003SS definition and marker, zero UID0003SS empty markers, one preserved UID0003ST empty marker, 21 total empty markers, and no WorldMapPane.h. Future-current generated authority requires a fresh supervisor physical reread.
- Under the assignment's fixed 28-item file metric, the callback produces the direct 6/28 to 7/28 improvement. The physical inventory proves the one target marker-to-definition transition: +366 bytes and +14 LF versus the dated baseline, with unrelated marker inventory preserved and only UID0003SS removed from the 22-marker baseline.
- Generated command identities are dated gate evidence, not permanent authority. Every later gate must freshly reread current metadata, physical identity, target declaration/body count, target marker absence, sibling marker preservation, remaining marker inventory, and header state.
- Current report execution/archive state is supervisor-owned and authoritative only from this report's current path plus validator-owned status/history metadata.

## Executive Recommendation

Accept UpdateHoverFromMouse as the highest-probability descriptive private source name already established in the complete WorldMapPane class declaration. Accept UpdateHoverFromMouseStrict for UID0003ST as a descriptive sibling name: strict means that only a reachable nonnegative hit may replace the current hover, so a miss cannot clear it.

The target must emit one ordinary member definition. It needs no split, child, new source file, new class field, custom bitset helper, raw offset access, event argument, return value, or H fragment. The source must preserve the binary's short-circuit ordering and must not add range guards, clear hover on unreachable hits, consume Event payload coordinates, or invalidate when no state changes.

## Supervisor Active Recheck

- The assignment that triggered this report explicitly named UID0003SS. Exact-artifact pre-callback Gate 1 passed 33/33 at 2026-08-24T09:05:40Z and authorized the bounded ordinary implementation callback; this is dated provenance, not a statement of current gate state.
- The exact target is already a correctly bounded child; no split-first repair is required.
- The dated 2026-08-24T15:00:04Z canonical MCP snapshot was available and all required read-only routes succeeded; future gates must re-establish current authority.
- UID0003SS is the only declared target. The sibling, hit-test, caller, owner, emitter, aggregate, and padding pages received precise support corrections but no additional coverage credit.
- Every target source blocker is resolved and implemented. Remaining uncertainty is lexical only and does not block behaviorally exact source.

## Inference Research Guidance Check

- Direct IDA facts: bytes, item heads, function ranges, instruction and basic-block counts, stack frames, caller/callee/xref sets, field offsets, UDT sizes, current names/types/comments, and the two branch differences.
- Documentation facts: accepted WorldMapPane/Point/Event/EventMan/Pane declarations, owner/emitter routes, generated marker state, and existing source-tree placement.
- Bounded inference: private source spellings UpdateHoverFromMouse and UpdateHoverFromMouseStrict, source-level void return, and normal std::vector<bool> indexing.
- Existing B001 uncertainty was treated as stale evidence, not copied forward. The current complete class UDT, current class formal, exact sibling comparison, and exact caller branches resolve it.
- The stale Wave3 non-function claim at 0x00590053 and all Wave2/Wave3 workflow artifacts were ignored. They have no bearing on this target.

## Heuristic / Inference Reanalysis And Validation

| Issue | Current resolution | Basis | Classification |
| --- | --- | --- | --- |
| Raw name sub_5C5080 | WorldMapPane::UpdateHoverFromMouse | Existing accepted class declaration, class receiver, exact cursor/hit-test behavior, and two mouse-handler call sites | Descriptive, high confidence |
| Sibling name distinction | WorldMapPane::UpdateHoverFromMouseStrict | The sibling accepts only reachable nonnegative hits and preserves hover on misses; the target additionally clears on a miss | Descriptive, high confidence |
| Return type | void | No caller consumes EAX; the update path leaves the void InvalidateRect call result in EAX while no-change paths leave the hit index, proving no coherent source return contract | Inferred ABI/source model, very high confidence |
| Cursor input | g_pEventMan->GetCursorPosition(&cursorPosition) | Direct global load and call at 0x005c5093; target has no explicit arguments | Direct fact |
| Coordinate order | HitTestNode(cursorPosition.x, cursorPosition.y) | Point is y at +0x00 and x at +0x04; disassembly pushes y then x under cdecl stack order for thiscall arguments | Direct fact |
| Hover field | int m_hoveredNodeIndex at +0x1e8 | WorldMapPane UDT and target compare/store at 0x005c50ca/0x005c50d2 | Direct fact |
| Reachability field | std::vector<bool> m_reachableNodes at +0x274 | WorldMapPane UDT and exact Dinkumware bit-test lowering | Direct fact plus source-shape inference |
| Invalidation | Pane::InvalidateRect(0) | Primary vtable slot +0x20 and accepted Pane declaration | Direct cross-document fact |
| Event payload alternative | Rejected | Helpers poll current cursor and take no Event/Point argument; Event pointer coordinates are consumed only by drag arithmetic in the caller | Direct negative fact |
| Unreachable-hit clearing | Rejected | Both helpers branch around the store when the hit node is unreachable | Direct negative fact |
| Miss preservation in target | Rejected | Target cmp eax,-1 jumps to the compare/store block; only the sibling jumps to exit | Direct negative fact |
| Custom bitset/global helper | Rejected | Field is accepted std::vector<bool>; no target-owned data/string/table exists | Direct type/source evidence |
| New file/header | Rejected | Existing UID0000PB/UID0000G9 route already supplies the source unit and declaration | Documentation and emitter evidence |

## Evidence Standards Used

The evidence ladder prioritized the dated 2026-08-24T15:00:04Z live IDA bytes/disassembly/profile evidence, exact caller/callee/xref and type/frame state, accepted class/type declarations, then dated generated/manual-documentation reads. Historical reports were corroboration only. The source body is accepted because every operation maps to a named class/global/type contract and the sibling/caller comparison closes all meaningful branch ambiguity; later gates must reread time-sensitive authority.

Lexical confidence remains below original-proof because no PDB, source archive, RTTI method symbol, string, or mangled private symbol preserves the original helper spellings. That limitation caps confidence at 94 but does not justify retaining raw names or blank source.

## Evidence Checked

- Fresh runtime_attestation, server_health, and idb_list for the current canonical route and process/session identity, followed by literal pre/post inspect_items, func_profile, stack_frame, get_bytes, get_comments, lookup_funcs, and paginated xref_query reads for the action and protection entities.
- func_profile, disasm, decompile, basic_blocks, stack_frame, inspect_items, get_bytes, get_comments, lookup_funcs, xrefs_to, xrefs_to_field, and type_inspect on target, sibling, caller, hit-test, EventMan dependency, global, UDTs, and boundaries.
- Exact target and sibling 102-byte bodies, three adjacent padding spans, physical executable range hashes, and zero end/gap xrefs.
- Full target and sibling 39-instruction disassemblies and five-block CFGs.
- Full decompilations of target, sibling, HitTestNode, and HandleMouseEvent.
- Current by-memory target/sibling/hit-test/caller/aggregate/ignored pages, by-class WorldMapPane/Pane/Event/EventMan pages, by-file WorldMapPane page, manual by-memory/by-class/by-file coverage, generated WorldMapPane.cpp, research tracker, completion stats, unresolved report, and matching executed B001/B003/B004 reports.
- Negative searches for target/sibling proposed IDA-name collisions, existing comments, strings, data refs, end-address xrefs, a target manual-coverage row, a separate target source unit, and a generated WorldMapPane.h.
- The report-only research pass performed no validator, lifecycle, execute, IDA mutation/save/manage, coverage write, generated write, registry, tracker, catalog, or audit action.
- The accepted callback ran only the eight scoped file validators recorded below. Their normal validator-owned projected-stats/reference/generated side effects are receipts, not manual edits. B009 performed no manual generated/coverage/tracker/registry/audit/catalog edit and no IDA or lifecycle action.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C001 | 0003SS | Preserve the exact target range [0x005c5080,0x005c50e6), size 0x66, 39 instructions, five blocks, and body SHA256 FDD207906B32F452FB48C445080B1C85C75E28B51EBCEF87CDF0F6E73C3F9041. | Very high | Dated 2026-08-24T15:00:04Z MCP function, CFG, disassembly, bytes, and physical executable readback. | UID0003SS Boundaries and IDA Evidence | incorporate | applied |
| C002 | 0003SS | Preserve eleven CC bytes at [0x005c5075,0x005c5080), ten CC bytes at [0x005c50e6,0x005c50f0), and ten CC bytes at [0x005c5156,0x005c5160) as non-source alignment outside all three functions. | Very high | Dated MCP items, bytes, zero xrefs, and exact padding hashes. | UID0003SS Boundary Evidence; UID0003ST Boundary Evidence; by-memory/-ignored.md | incorporate | applied |
| C003 | 0003SS | Reconstruct the source ABI as private void WorldMapPane::UpdateHoverFromMouse() with no explicit arguments and one eight-byte Point local; the incidental EAX values are not a return contract. | Very high | Callers ignore EAX; update and no-update paths leave unrelated values; exact frame. | UID0003SS ABI and formal CPP | incorporate | applied |
| C004 | 0003SS | Record g_pEventMan->GetCursorPosition(&cursorPosition) as the sole input source and preserve Point y/+0x00, x/+0x04 with HitTestNode(cursorPosition.x, cursorPosition.y). | Very high | Direct global/call instructions, EventMan type, Point UDT, push order. | UID0003SS Behavior and formal CPP | incorporate | applied |
| C005 | 0003SJ | Record that HitTestNode returns a valid node index or -1 after strict +/-20 map-space bounds over 0x94-byte nodes, with EPF center 512/384 and legacy center 320/240. | Very high | Full current decompile, two exact hover-helper callers, WorldMapNode stride. | UID0003SJ Evidence; UID0003SS Hit-Test Contract | incorporate | applied |
| C006 | 0003SS | Bind the +0x274 read to std::vector<bool> m_reachableNodes and preserve the compiler-lowered word/bit test as normal source indexing. | Very high | WorldMapPane UDT and exact instructions 0x005c50ab-0x005c50c3. | UID0003SS Field Contract and formal CPP | incorporate | applied |
| C007 | 0003SS | Bind the +0x1e8 compare/store to int m_hoveredNodeIndex and preserve it as distinct from short m_currentNodeIndex at +0x1ec. | Very high | WorldMapPane UDT, target writes, caller reads, accepted class contract. | UID0003SS Field Contract; UID0000G9 Input Contract | incorporate | applied |
| C008 | 0003SS | Preserve the exact target predicate: accept -1 or a reachable nonnegative hit, reject an unreachable hit, and write only when the accepted value differs from m_hoveredNodeIndex. | Very high | Exact CFG/disassembly and sibling comparison. | UID0003SS Behavior and formal CPP | incorporate | applied |
| C009 | 0003SS | Preserve the sole side effects as the conditional hover write followed by Pane::InvalidateRect(0); no write, invalidation, allocation, packet, timer, cursor, or return side effect occurs otherwise. | Very high | Exact 39-instruction body and Pane slot contract. | UID0003SS Side Effects and formal CPP | incorporate | applied |
| C010 | 0003SM | Record the 0x005c40f5 left-button-down call: when navigation is inactive, refresh hover before choosing drag when hover is -1 versus StartTravelToNode(current hover). | Very high | Full HandleMouseEvent decompile and EventType values. | UID0003SM Branch Contract; UID0003SS Caller Inventory | incorporate | applied |
| C011 | 0003SM | Record the 0x005c4187 left-button-up call: after an active drag, show cursor, clear m_draggingView, then run the clear-capable target helper. | Very high | Full HandleMouseEvent decompile and exact callsite. | UID0003SM Branch Contract; UID0003SS Caller Inventory | incorporate | applied |
| C012 | 0003ST | Record the 0x005c4237 cursor-move route: when not dragging and navigation is inactive, the strict sibling accepts only reachable hits and preserves hover on misses or unreachable hits. | Very high | Full caller and sibling decompilations. | UID0003ST Exact Distinction; UID0003SM Branch Contract | incorporate | applied |
| C013 | 0003SS | Accept UpdateHoverFromMouse as the highest-probability descriptive private source name while preserving the absence of original-symbol proof. | High | Existing class declaration plus exact behavior/callsite role and no collision. | UID0003SS Status, naming rationale, CPP | incorporate | applied |
| C014 | 0003ST | Accept UpdateHoverFromMouseStrict as the descriptive sibling name because its nonnegative-reachable-only predicate is strictly narrower than UID0003SS. | High | Exact binary difference, existing class declaration, and no collision. | UID0003ST Status and Exact Distinction | incorporate | applied |
| C015 | 0003SS | Preserve canonical owner UID0000G9, emitter UID0000PB, Nested:0, reconstructable true, blank optional position, and NexusTK/map/WorldMapPane.cpp placement. | Very high | Current metadata, class/file ownership, caller/callee family. | UID0003SS metadata and Source Placement | incorporate | applied |
| C016 | 0003SS | Insert the exact First-Draft section body into the target RECONSTRUCTION_CPP CODE block with no raw offsets, decompiler labels, extra guards, or sibling body. | Very high | Complete target behavior and accepted source types. | UID0003SS formal CPP | incorporate | applied |
| C017 | 0003SS | Keep the target RECONSTRUCTION_H CODE block empty because UID0000G9 already emits exactly void UpdateHoverFromMouse(); and a second declaration would duplicate class-owned source. | Very high | Current UID0000G9 formal H and emitter structure. | UID0003SS formal H disposition | incorporate | applied |
| C018 | 0003SS | Raise UID0003SS from 85/88 to 93/94 while preserving all other metadata; the cap reflects inferred private spelling and no rebuilt-binary comparison. | High | All prior blockers resolved; lexical/original-source evidence remains unavailable. | UID0003SS metadata and Score Rationale | incorporate | applied |
| C019 | 0003SS | Replace the stale target summary/status/evidence with the complete range, ABI, fields, predicate, callers, sibling distinction, side effects, boundaries, source route, negative evidence, and historicalized old blocker. | Very high | Complete current research inventory. | by-memory/0x005c5080-0x005c50e6.WorldMapPaneUpdateHoverFromMouse.md | incorporate | applied |
| C020 | 0003ST | Correct the sibling support page from provisional distinction to exact reachable-hit-only/no-clear behavior, accepted descriptive name, caller at 0x005c4237, and exact padding; keep its metadata and formal blocks unchanged. | Very high | Complete sibling body/caller evidence; UID0003ST is not an additional target. | by-memory/0x005c50f0-0x005c5156.WorldMapPaneUpdateHoverFromMouseStrict.md | incorporate | applied |
| C021 | 0003SJ | Correct the HitTestNode support page with current Point input order, exact centers/strict bounds/stride/result contract, and retire the stale unresolved-node-field statement without populating its formal blocks. | Very high | Complete current HitTestNode decompile and accepted WorldMapNode declaration. | by-memory/0x005c37e0-0x005c38fd.WorldMapPaneHitTestNode.md | incorporate | applied |
| C022 | 0003SM | Correct the HandleMouseEvent support page with exact event types, two target calls, one strict-sibling call, navigation/drag gates, payload-only drag use, and historicalize its stale field/event blocker without populating its formal blocks. | Very high | Complete current caller decompile, Event UDT, EventType declaration. | by-memory/0x005c40c0-0x005c4245.WorldMapPaneHandleMouseEvent.md | incorporate | applied |
| C023 | 0000G9 | Add an exact hover-helper input contract to WorldMapPane: target clears on miss, sibling preserves on miss, both reject unreachable hits and invalidate only on change; preserve the existing declarations, layout, score, and formal source. | Very high | Current class UDT/formal plus exact two-function comparison. | by-class/WorldMapPane.md Input Method Family | incorporate | applied |
| C024 | 0000PB | Add the exact UID0003SS source/emitter contract and callback generated-readback expectations to WorldMapPane.cpp documentation without changing the file score, path, or unrelated inventory. | Very high | Existing emitter route and dated command-000000027631 generated snapshot. | by-file/WorldMapPane.md Hover Source Contract | incorporate | applied |
| C025 | 0001O4 | Replace the aggregate's raw target/sibling labels with accepted descriptive names/roles and add the two ten-byte hover-family alignment gaps while preserving parent non-emission and every unrelated child. | Very high | Exact current functions/items/bytes and established split parent. | by-memory/0x005c2ac0-0x005c5c87.WorldMapPane.md inventory/boundaries | incorporate | applied |
| C026 | 0000VN | Add exact ignored entries for [0x005c50e6,0x005c50f0) and [0x005c5156,0x005c5160), each ten CC bytes with zero xrefs and no authored source. | Very high | Dated MCP items, bytes, hashes, xrefs, and 2026-08-24T12:49:20Z shared-file reread. | by-memory/-ignored.md | incorporate | applied |
| C027 | 0003SS | Supervisor Gate 2B executes I01 only: pure-rename 0x005c5080 from sub_5C5080 to WorldMapPane__UpdateHoverFromMouse after the literal cumulative prestate, collision, immutable-envelope, and P01-P08 checks, then reread before continuing. | High | Dated raw name/collision proof and the independent I01 stage contract. | IDA I01 target rename | incorporate | proposed |
| C028 | 0003SS | Supervisor Gate 2B executes I02 only after I01 readback: apply exact type void __thiscall WorldMapPane__UpdateHoverFromMouse(WorldMapPane *this), permit only the bounded target cache refresh, and prove the complete frame/immutable state unchanged. | Very high | Source-void proof, exact UDT/frame, and the independent I02 stage contract. | IDA I02 target type/frame | incorporate | proposed |
| C029 | 0003SS | Supervisor Gate 2B executes I03 only after I02 readback: set the exact target address-repeatable comment, leave the other three channels absent, and prove all prior cumulative state and protections unchanged. | High | Proven behavior and the independent I03 stage contract. | IDA I03 target repeatable comment | incorporate | proposed |
| C030 | 0003ST | Supervisor Gate 2B executes I04 only after target final-state readback: pure-rename 0x005c50f0 from sub_5C50F0 to WorldMapPane__UpdateHoverFromMouseStrict after the literal sibling collision/prestate checks. | High | Dated raw name/collision proof and the independent I04 stage contract. | IDA I04 sibling rename | incorporate | proposed |
| C031 | 0003ST | Supervisor Gate 2B executes I05 only after I04 readback: apply exact type void __thiscall WorldMapPane__UpdateHoverFromMouseStrict(WorldMapPane *this), permit only the bounded sibling cache refresh, and prove the frame/immutable state unchanged. | Very high | Source-void proof, exact UDT/frame, and the independent I05 stage contract. | IDA I05 sibling type/frame | incorporate | proposed |
| C032 | 0003ST | Supervisor Gate 2B executes I06 only after I05 readback: set the exact sibling address-repeatable comment, leave the other three channels absent, and prove both cumulative final states and every protection unchanged. | High | Proven sibling behavior and the independent I06 stage contract. | IDA I06 sibling repeatable comment | incorporate | proposed |
| C033 | 0003SS | Protect target bytes, five-block CFG, Point local, xrefs at 0x005c40f5/0x005c4187, callees, and all non-name/type/repeatable-comment state through IDA application. | Very high | Exact current target inventory. | IDA 0x005c5080 protection row | incorporate | proposed |
| C034 | 0003ST | Protect sibling bytes, five-block CFG, Point local, xref at 0x005c4237, callees, and all non-name/type/repeatable-comment state through IDA application. | Very high | Exact current sibling inventory. | IDA 0x005c50f0 protection row | incorporate | proposed |
| C035 | 0003SJ | Make no IDA change to HitTestNode at 0x005c37e0; protect its current exact range/type/comments/hash and two hover-helper xrefs. | Very high | Current function/item/comments/xrefs and body hash. | IDA 0x005c37e0 no-change protection | incorporate | proposed |
| C036 | 0003SM | Make no IDA change to HandleMouseEvent at 0x005c40c0; protect its current exact range/type/comments/hash and vtable data xref at 0x00631450. | Very high | Current function/item/comments/xref and body hash. | IDA 0x005c40c0 no-change protection | incorporate | proposed |
| C037 | 0003SS | Make no IDA change to EventMan__GetCursorPosition at 0x004a9090; protect its exact name/range/type, four comment channels, complete three-row frame, 21 bytes/hash, 68 enumerated inbound code xrefs, one outbound flow xref, and shared ownership. | Very high | Dated repair-snapshot function/item/comments/frame/bytes and complete paginated xref readback. | IDA P03 literal no-change dependency | incorporate | proposed |
| C038 | 0003SS | Make no IDA change to g_pEventMan at 0x0067a754; protect its exact four-byte data item/name/type, two comment channels, four zero bytes/hash, 210 enumerated inbound data xrefs, zero outbound xrefs, and rejected target ownership. | Very high | Dated repair-snapshot item/comments/bytes and complete paginated xref readback. | IDA P04 literal no-change dependency | incorporate | proposed |
| C039 | 0000G9 | Make no IDA UDT change; protect WorldMapPane size 0x298, m_hoveredNodeIndex +0x1e8 int, m_reachableNodes +0x274/0x10, and Point size 8 with y/x offsets 0/4. | Very high | Current type_inspect readback. | IDA WorldMapPane/Point UDT no-change protection | incorporate | proposed |
| C040 | 0000VN | Make no IDA change to any P06-P08 padding item; protect each literal absent name/type, exact head/end/size/data kind, comment channels, CC bytes/hash, zero inbound/outbound xrefs, and identical required postread. | Very high | Dated repair-snapshot item/comments/bytes and complete bidirectional xref pre/post readback. | IDA P06-P08 literal no-change protections | incorporate | proposed |
| C041 | 0003SS | Insert the exact supervisor-owned UID0003SS manual by-memory coverage row after the existing 0x005c5075-0x005c5080 alignment row. | Very high | Current manual row is absent and target score/summary will change. | by-memory/-coverage-report.md exact insertion | incorporate | proposed |
| C042 | 0000VN | Insert the two exact supervisor-owned manual by-memory padding rows around UID0003ST in address order. | Very high | Current manual rows are absent and by-memory/-ignored.md will change. | by-memory/-coverage-report.md exact insertions | incorporate | proposed |
| C043 | 0003SS | During an accepted callback, run one scoped file validator for each changed ordinary by-* page and use wait-generated on the target's final validator; no validator is run in this report-only pass. | Very high | Current role boundary and validator workflow. | Validator Results and callback checklist | incorporate | applied |
| C044 | 0003SS | Physically reread the dated generated WorldMapPane.cpp snapshot and prove one target declaration, one target definition, no UID0003SS empty marker, preserved UID0003ST marker, unchanged unrelated content, exact command/time/hash/bytes/line endings, and no target-created header; require a fresh supervisor reread at any later gate. | Very high | Dated generated command 000000027631 physical readback and exact CPP/H disposition. | Dated generated verification | incorporate | applied |
| C045 | 0003SS | Preserve rejected event-payload/custom-bitset/raw-offset/extra-guard/return-value/new-file/duplicate-H alternatives, historicalize the old unresolved-name/field blocker, and record that third-party import is not applicable to first-party WorldMapPane source. | Very high | Positive and negative evidence inventory. | Target/support history and source disposition | incorporate | applied |

## Positive Evidence Summary

- The target has two exact caller instructions, both inside the one WorldMapPane mouse virtual, and no data/vtable/string reference of its own.
- Both target and sibling call the same current-cursor reader and same node hit-test, use the same reachability and hover fields, and have identical 0x66-byte source shape except for the miss branch.
- Current UDTs supply every source-facing type and field needed by the target: WorldMapPane 0x298, Point 8, m_hoveredNodeIndex +0x1e8, and m_reachableNodes +0x274.
- The caller's left-down, left-up, and cursor-move branches explain why two variants exist and why the target must be clear-capable.
- Before the accepted callback, the established class/file route declared the method and emitted an empty UID0003SS target marker at the correct source position; the dated command-000000027631 generated snapshot contains the exact UID0003SS definition and no UID0003SS empty marker.

## IDA MCP Facts

- Target 0x005c5080: sub_5C5080, size 0x66, 39 instructions, five blocks, current type unsigned int __thiscall(_DWORD *this), stack Point position@0x4/8; saved-registers@0xc/4; return-address@0x10/4.
- Sibling 0x005c50f0: sub_5C50F0, same size/instruction/block/frame shape and current type.
- Target CFG blocks are [0x5c5080,0x5c50aa), [0x5c50aa,0x5c50ca), [0x5c50ca,0x5c50d2), [0x5c50d2,0x5c50e1), and [0x5c50e1,0x5c50e6).
- Sibling CFG blocks are [0x5c50f0,0x5c511a), [0x5c511a,0x5c513a), [0x5c513a,0x5c5142), [0x5c5142,0x5c5151), and [0x5c5151,0x5c5156).
- Target xrefs: 0x005c40f5 and 0x005c4187. Sibling xref: 0x005c4237. HitTestNode xrefs: target 0x005c50a0 and sibling 0x005c5110.
- Target and sibling callees: EventMan__GetCursorPosition 0x004a9090 and HitTestNode 0x005c37e0, plus virtual Pane::InvalidateRect through slot +0x20.
- Target/sibling function comments are absent in all four channels. Proposed names WorldMapPane__UpdateHoverFromMouse and WorldMapPane__UpdateHoverFromMouseStrict have no current collision.
- Target body SHA256 FDD207906B32F452FB48C445080B1C85C75E28B51EBCEF87CDF0F6E73C3F9041; sibling body SHA256 4017DFFB7CEE0A9A2360732A3561618C1091D1CC38434821B41B9B6118CC32F6.
- Padding hashes: [0x5c5075,0x5c5080) 3682C0A62515050101266CC639BF81F5D8C5395F49E7DA93FCC22603018E0943; each ten-byte CC span hashes to 22E52BBA61DA8AD6732BE550205A10B89A1BB3B0EA491BE07DE9294F0EB6F045.
- xrefs_to_field returned no modeled field xrefs because the two functions still have raw _DWORD receiver types. Exact offset instructions plus type_inspect close the field mapping; the empty field-xref result is retained as tool-state negative evidence.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Report disposition |
| --- | --- | --- | --- |
| 0x005c5075-0x005c5080 | UID0000VN / by-memory/-ignored.md | Eleven-byte predecessor alignment | No code; preserve |
| 0x005c5080-0x005c50e6 | UID0003SS target | Clear-capable hover update | Emit exact CPP, no H |
| 0x005c50e6-0x005c50f0 | UID0000VN / by-memory/-ignored.md | Ten-byte inter-function alignment | No code; document |
| 0x005c50f0-0x005c5156 | UID0003ST support | Reachable-hit-only hover update | Behavior/name support correction; formal stays unchanged |
| 0x005c5156-0x005c5160 | UID0000VN / by-memory/-ignored.md | Ten-byte successor alignment | No code; document |
| 0x005c37e0-0x005c38fd | UID0003SJ support | Node hit-test used by both helpers | Exact relation/input correction; formal stays unchanged |
| 0x005c40c0-0x005c4245 | UID0003SM support | Mouse virtual and sole caller family | Exact branch correction; formal stays unchanged |
| 0x004a9090-0x004a90a5 | UID00004O dependency | EventMan current cursor reader | Shared dependency; no target ownership/code |
| 0x0067a754-0x0067a758 | EventMan global dependency | g_pEventMan | Shared dependency; no target ownership/code |
| WorldMapPane UDT | UID0000G9 | Class layout/declaration owner | Preserve, add exact method-family behavior |
| WorldMapPane.cpp | UID0000PB | Sole source emitter | Preserve path/owner; the accepted callback replaced the target empty marker with the exact CPP definition |

This is a by-memory target, not a whole-file assignment. The table is exhaustive for the target body, its two adjacent boundaries, exact sibling comparison, sole caller family, direct callee, consumed fields/types, and source route. Unrelated WorldMapPane methods remain outside this report.

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| 0x005c40f5 -> 0x005c5080 | UID0003SM left-button-down branch | Refresh before drag-versus-travel decision |
| 0x005c4187 -> 0x005c5080 | UID0003SM left-button-up after drag | Clear-capable refresh after ending drag |
| 0x005c4237 -> 0x005c50f0 | UID0003SM cursor move | Reachable-hit-only passive hover update |
| 0x005c5093 -> 0x004a9090 | EventMan::GetCursorPosition | Target polls current cursor |
| 0x005c50a0 -> 0x005c37e0 | WorldMapPane::HitTestNode | Target converts cursor to node index/-1 |
| 0x005c5103 -> 0x004a9090 | EventMan::GetCursorPosition | Sibling polls same current cursor |
| 0x005c5110 -> 0x005c37e0 | WorldMapPane::HitTestNode | Sibling uses same hit-test |
| 0x00631450 -> 0x005c40c0 | WorldMapPane input-handler vtable | Confirms caller as class input virtual |
| 0x005c50e6, 0x005c5156 | zero xrefs | Confirms exact ends/padding starts |

## Documentation Evidence And IDA Status

- UID0000G9 already declares both void methods and exact fields. That class-level acceptance supersedes the target page's old statement that the fields are unresolved.
- UID00004O already declares EventMan::GetCursorPosition(Point *) and g_pEventMan. UID0000A2 declares Pane::InvalidateRect(const RectBounds *) as primary slot +0x20.
- UID0003SJ and UID0003SM retain their unchanged metadata and blank formal bodies, but their ordinary pages now carry the accepted exact hit-test and mouse-branch contracts with former blockers historicalized. Those support corrections are not complete source-body incorporation.
- UID0000PB is the established map/WorldMapPane.cpp emitter. The dated command-000000027631 generated snapshot confirms one UID0003SS definition and no target empty marker while preserving the UID0003ST empty marker.
- The read-only manual by-memory coverage comparison found the parent and predecessor alignment but no UID0003SS or two new padding rows. Exact supervisor-owned insertion text is supplied below; a later supervisor gate must reread current manual rows.
- The dated 2026-08-24T15:00:04Z IDA snapshot had raw names/types for target/sibling, complete useful UDTs, and no comments or proposed-name collisions.

## Ranked Ownership Analysis

### 1. WorldMapPane class / WorldMapPane.cpp

- Evidence for: exact WorldMapPane receiver, private class fields, private HitTestNode call, sole class mouse-handler caller, existing class declarations, existing source emitter, and address-family placement.
- Evidence against: no original private symbols.
- Decision: retain UID0000G9 owner and UID0000PB emitter. Lexical uncertainty does not weaken ownership.

### 2. EventMan / Event.cpp

- Evidence for: target reads g_pEventMan and calls GetCursorPosition.
- Evidence against: EventMan is only a shared input provider; the target reads/writes WorldMapPane state and is called only by WorldMapPane.
- Decision: reject ownership. Preserve as dependency only.

### 3. Generic input/helper module

- Evidence for: cursor polling and hit testing are input-related.
- Evidence against: no free-function callers, data, strings, independent state, or source boundary; method is private and class-specific.
- Decision: reject a new file or generic helper.

### Proposed new file/grouping, if applicable

Not applicable. The existing NexusTK/map/WorldMapPane.cpp and class declaration are exact.

## Source Placement

- Recommended definition: NexusTK/map/WorldMapPane.cpp through UID0000PB.
- Recommended declaration: the already-present private void UpdateHoverFromMouse(); in UID0000G9's class formal.
- Target H fragment: empty to avoid duplicate declaration.
- Rejected placements: Event.cpp, MapPane.cpp, a generic hover helper file, a custom vector/bitset source file, and a new target-specific header.
- Remaining uncertainty: only original private spelling, not module/class placement.

## Range / Split / Padding / Reclassification Analysis

- The target item starts exactly at 0x005c5080 and ends at the ret byte 0x005c50e5; 0x005c50e6 is outside the function.
- Predecessor BuildReachabilityData ends at 0x005c5075. Eleven CC bytes occupy [0x005c5075,0x005c5080).
- Ten CC bytes occupy [0x005c50e6,0x005c50f0) before the sibling.
- Sibling ends at 0x005c5156. Ten CC bytes occupy [0x005c5156,0x005c5160) before FindPredecessorNode.
- All three gaps are IDA data items, not code, have zero inbound xrefs at their starts, and require no split or source emission.
- UID0003SS remains one reconstructable child. The broad UID0001O4 parent remains non-emitting and unsplit.

## Negative Evidence Summary

- No original/mangled symbol, PDB, source string, RTTI method name, import, or data pointer proves either private spelling.
- No caller reads EAX after either hover helper, and helper exits do not produce one coherent value.
- No Event pointer or coordinates are passed to either helper.
- No target string, resource, packet, timer, allocation, deallocation, cursor show/hide, navigation write, or global write exists.
- No target/sibling proposed-name collision exists.
- No xref reaches either function end or either new padding start.
- No evidence supports clearing on unreachable hits, clearing on sibling misses, unconditional invalidation, a custom bitset class, raw offset source, an extra index guard, another source file, or duplicate H declaration.

## IDA Rename / Type / Comment Recommendations

These are six declarative, independently staged entity handoffs for supervisor Gate 2B. B009 performed no IDA mutation, rename, type write, comment write, cache action, save, process management, or file replacement. The supervisor must establish fresh external isolation/runtime/backup/save/persistence/rollback authority before any action. Every row has one persistent mutation; the only permitted nonpersistent side effect is the exact bounded cache refresh attached to a `set_type` row. Any mismatch, collision, unavailable endpoint, ambiguous poststate, byte/frame/xref drift, partial action, or failed readback stops the transaction without save.

Current action schema:

- Function rename uses rename with pure:true, allow_overwrite:false, dry_run:false, and stop_on_error:true. Pure mode must skip function-directory /vibe/ placement and decompiler-refresh side effects.
- Function type uses set_type with kind function and the exact named signature below.
- After each type application, force_recompile is permitted only for that exact function as a cache-only refresh before fresh public type/decompile/frame readback. It is not a second persistent mutation and is forbidden on every rename/comment row.
- The one comment channel uses set_address_repeatable_comments at the exact entry. set_comments is not authorized.

The following immutable action-envelope facts are part of the literal prestate, poststate, and protection set for **every** I01-I06 row rather than inferred shorthand. Target 0x005c5080 remains one code function [0x005c5080,0x005c50e6), size 0x66, 39 instructions, five CFG blocks [0x5c5080,0x5c50aa), [0x5c50aa,0x5c50ca), [0x5c50ca,0x5c50d2), [0x5c50d2,0x5c50e1), [0x5c50e1,0x5c50e6), body SHA256 FDD207906B32F452FB48C445080B1C85C75E28B51EBCEF87CDF0F6E73C3F9041, exact frame `position`@0x4/8:`Point`, `__saved_registers`@0xc/4:`_DWORD`, `__return_address`@0x10/4:`_UNKNOWN *`, inbound code xrefs 0x005c40f5 and 0x005c4187, direct callees EventMan__GetCursorPosition@0x004a9090 and HitTestNode@0x005c37e0, and virtual Pane::InvalidateRect slot +0x20. Sibling 0x005c50f0 remains one code function [0x005c50f0,0x005c5156), size 0x66, 39 instructions, five CFG blocks [0x5c50f0,0x5c511a), [0x5c511a,0x5c513a), [0x5c513a,0x5c5142), [0x5c5142,0x5c5151), [0x5c5151,0x5c5156), body SHA256 4017DFFB7CEE0A9A2360732A3561618C1091D1CC38434821B41B9B6118CC32F6, the same three-row frame, inbound code xref 0x005c4237, the same two direct callees, and the same virtual slot. Exact body bytes, item heads/kinds, all unlisted comment channels, xrefs, callees, frames, CFGs, ranges, hashes, and P01-P08 are NO_CHANGE at every stage.

| Row | Literal cumulative prestate at this stage | Exactly one persistent mutation and permitted cache action | Literal cumulative poststate and mandatory readback |
| --- | --- | --- | --- |
| I01 target rename | Target name `sub_5C5080`; public type `unsigned int __thiscall(_DWORD *this)`; address regular/repeatable and function regular/repeatable comments all absent. Sibling name `sub_5C50F0`; same raw public type; all four comments absent. Both proposed-name collisions absent. All immutable envelope facts and P01-P08 match literally. | Pure rename target entry 0x005c5080 to `WorldMapPane__UpdateHoverFromMouse` with `pure:true`, `allow_overwrite:false`, `dry_run:false`, `stop_on_error:true`. No type, comment, cache, frame, analysis, or sibling action. | Target name exact `WorldMapPane__UpdateHoverFromMouse`; target type remains exact `unsigned int __thiscall(_DWORD *this)`; all four target comments remain absent. Sibling remains exact raw name/type with all comments absent. Reread all immutable envelope facts and P01-P08. Any mismatch or partial action stops without save. |
| I02 target type | Target name `WorldMapPane__UpdateHoverFromMouse`; target public type `unsigned int __thiscall(_DWORD *this)`; all four target comments absent. Sibling remains `sub_5C50F0`, raw public type, all comments absent. All immutable envelope facts and P01-P08 match literally. | Set only the target function type at 0x005c5080 to `void __thiscall WorldMapPane__UpdateHoverFromMouse(WorldMapPane *this)`. Then permit one bounded target-only force_recompile cache refresh and fresh readback. No rename/comment/frame/sibling mutation. | Target name unchanged; public type exact `void __thiscall(WorldMapPane *this)`; fresh decompile header exact `void __thiscall WorldMapPane__UpdateHoverFromMouse(WorldMapPane *this)`; three-row frame unchanged; all four comments absent. Sibling remains exact raw name/type/comments. Reread all immutable envelope facts and P01-P08. Any mismatch, refresh spillover, or partial action stops without save. |
| I03 target address-repeatable comment | Target name `WorldMapPane__UpdateHoverFromMouse`; target public type `void __thiscall(WorldMapPane *this)`; target address regular, address repeatable, function regular, and function repeatable comments all absent; target frame remains exact. Sibling remains `sub_5C50F0`, raw public type, all comments absent. All immutable envelope facts and P01-P08 match literally. | Set only target address-repeatable comment at 0x005c5080 to `Polls the current cursor, hit-tests WorldMapPane nodes, clears m_hoveredNodeIndex on a miss, accepts only reachable hits, and invalidates only when the hover value changes.` No rename/type/cache/frame/sibling action. | Target name/type/frame remain exact; address-repeatable comment equals the literal sentence; target address regular and both function comment channels remain absent. Sibling remains exact raw name/type/comments. Reread all immutable envelope facts and P01-P08. Any mismatch or partial action stops without save. |
| I04 sibling rename | Target is final through I03: name `WorldMapPane__UpdateHoverFromMouse`, public type `void __thiscall(WorldMapPane *this)`, exact target address-repeatable comment, other three comments absent, exact frame. Sibling name `sub_5C50F0`; public type `unsigned int __thiscall(_DWORD *this)`; all four sibling comments absent; sibling proposed-name collision absent. All immutable envelope facts and P01-P08 match literally. | Pure rename sibling entry 0x005c50f0 to `WorldMapPane__UpdateHoverFromMouseStrict` with `pure:true`, `allow_overwrite:false`, `dry_run:false`, `stop_on_error:true`. No type, comment, cache, frame, or target action. | Target final state remains exact. Sibling name exact `WorldMapPane__UpdateHoverFromMouseStrict`; sibling type remains exact `unsigned int __thiscall(_DWORD *this)`; all four sibling comments remain absent. Reread all immutable envelope facts and P01-P08. Any mismatch or partial action stops without save. |
| I05 sibling type | Target final state remains exact. Sibling name `WorldMapPane__UpdateHoverFromMouseStrict`; sibling public type `unsigned int __thiscall(_DWORD *this)`; all four sibling comments absent; sibling frame remains exact. All immutable envelope facts and P01-P08 match literally. | Set only the sibling function type at 0x005c50f0 to `void __thiscall WorldMapPane__UpdateHoverFromMouseStrict(WorldMapPane *this)`. Then permit one bounded sibling-only force_recompile cache refresh and fresh readback. No rename/comment/frame/target mutation. | Target final state remains exact. Sibling name unchanged; public type exact `void __thiscall(WorldMapPane *this)`; fresh decompile header exact `void __thiscall WorldMapPane__UpdateHoverFromMouseStrict(WorldMapPane *this)`; three-row frame unchanged; all four sibling comments absent. Reread all immutable envelope facts and P01-P08. Any mismatch, refresh spillover, or partial action stops without save. |
| I06 sibling address-repeatable comment | Target final state remains exact. Sibling name `WorldMapPane__UpdateHoverFromMouseStrict`; sibling public type `void __thiscall(WorldMapPane *this)`; sibling address regular, address repeatable, function regular, and function repeatable comments all absent; sibling frame remains exact. All immutable envelope facts and P01-P08 match literally. | Set only sibling address-repeatable comment at 0x005c50f0 to `Polls the current cursor, hit-tests WorldMapPane nodes, accepts only reachable hits, preserves m_hoveredNodeIndex on misses or unreachable hits, and invalidates only when the hover value changes.` No rename/type/cache/frame/target action. | Target final state remains exact. Sibling name/type/frame remain exact; address-repeatable comment equals the literal sentence; sibling address regular and both function comment channels remain absent. Reread all immutable envelope facts and P01-P08. Any mismatch or partial action stops without save. |

No local rename is proposed: both current stack locals are already position:Point and pure mode cannot rename locals. No UDT/member/data action is proposed.

| Protection row | Literal current state | Required disposition |
| --- | --- | --- |
| P01 HitTestNode 0x005c37e0 | sub_5C37E0, [0x005c37e0,0x005c38fd), type int __thiscall(int this, int, int), all comments absent, body hash D60AE105E1769444629835A7E6CCC0F7C162B31D31CAF66BD245E962BE3A4EA1, xrefs exactly 0x005c50a0 and 0x005c5110 | NO_CHANGE; this report does not authorize rename/type/comment/frame/body mutation |
| P02 HandleMouseEvent 0x005c40c0 | sub_5C40C0, [0x005c40c0,0x005c4245), type char __thiscall(int this, int), all comments absent, body hash A4FE00B42FB9EF305459C8AB4F2A1FB42EB747C5854A1F9F535849252F5C566E, sole entry xref data 0x00631450 | NO_CHANGE; preserve secondary EventHandler-view ABI and all state |
| P03 EventMan cursor reader 0x004a9090 | Function name EventMan__GetCursorPosition, range [0x004a9090,0x004a90a5), size 0x15, code; type void __thiscall(EventMan *this, Point *position); address regular absent; address repeatable absent; function regular exact `Source EventMan::GetCursorPosition(Point *), copying project-order y then x coordinates.`; function repeatable absent; complete frame `__saved_registers`@0x0/4:`_DWORD`, `__return_address`@0x4/4:`_UNKNOWN *`, `position`@0x8/4:`Point *`; bytes `55 8B EC 8B 55 08 8B 41 04 89 02 8B 41 08 89 42 04 5D C2 04 00`; SHA256 693F907D95DEA0B728E2B481FA541319A3B5FD257F6CCF30CABABDFA9ECF7BC7; exactly 68 inbound `to` code xrefs at the P03 seal below and one outbound `from` code-flow xref 0x004a9090 -> 0x004a9091 | NO_CHANGE; preserve every literal field and endpoint. Required postread must match the full prestate byte for byte; any name/range/kind/type/comment/frame/byte/hash/xref drift is a hard stop. |
| P04 g_pEventMan 0x0067a754 | Item name g_pEventMan, head 0x0067a754, end 0x0067a758, size 4, data and not code; type EventMan *; address regular exact `g_pEventMan: shared EventMan singleton used by EventMan_TranslateEventKey and event dispatch helpers.`; address repeatable absent; function comment channels not applicable to this data item; bytes `00 00 00 00`; SHA256 DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119; exactly 210 inbound `to` data xrefs at the P04 seal below and zero outbound xrefs | NO_CHANGE; no target ownership, rename, type, comment, resize, byte, kind, or xref change. Required postread must match the full prestate byte for byte; any drift is a hard stop. |
| P05 UDTs | WorldMapPane size 664/0x298; m_hoveredNodeIndex +0x1e8 size4 int; m_reachableNodes +0x274 size16 WorldMapBoolVector; Point size8, y +0 size4 int, x +4 size4 int | NO_CHANGE; exact member/type/size protections |
| P06 predecessor pad | Name absent; type absent; head 0x005c5075, end 0x005c5080, size 11, data and not code; address regular exact `Start of eleven 0xcc alignment bytes outside WorldMapPane_BuildReachabilityData; successor begins at 0x005c5080.`; address repeatable absent; function comment channels not applicable; bytes `CC CC CC CC CC CC CC CC CC CC CC`; SHA256 3682C0A62515050101266CC639BF81F5D8C5395F49E7DA93FCC22603018E0943; zero inbound and zero outbound xrefs | NO_CHANGE; required postread must preserve every literal field, byte, comment channel, and zero/zero xref state; any drift is a hard stop. |
| P07 middle pad | Name absent; type absent; head 0x005c50e6, end 0x005c50f0, size 10, data and not code; address regular absent; address repeatable absent; function comment channels not applicable; bytes `CC CC CC CC CC CC CC CC CC CC`; SHA256 22E52BBA61DA8AD6732BE550205A10B89A1BB3B0EA491BE07DE9294F0EB6F045; zero inbound and zero outbound xrefs | NO_CHANGE; required postread must preserve every literal field, byte, comment channel, and zero/zero xref state; any drift is a hard stop. |
| P08 successor pad | Name absent; type absent; head 0x005c5156, end 0x005c5160, size 10, data and not code; address regular absent; address repeatable absent; function comment channels not applicable; bytes `CC CC CC CC CC CC CC CC CC CC`; SHA256 22E52BBA61DA8AD6732BE550205A10B89A1BB3B0EA491BE07DE9294F0EB6F045; zero inbound and zero outbound xrefs | NO_CHANGE; required postread must preserve every literal field, byte, comment channel, and zero/zero xref state; any drift is a hard stop. |

P03 inbound-xref seal: exactly 68 `to` / `code` endpoints, sorted ascending with no pagination remainder: `0x41db0a`, `0x41ddf3`, `0x41e1fa`, `0x41e503`, `0x41e8cd`, `0x41e9a4`, `0x41e9f1`, `0x459bde`, `0x459d3a`, `0x45a020`, `0x45a42a`, `0x45a723`, `0x45aa9a`, `0x45ab6d`, `0x45ac44`, `0x45ac91`, `0x497c74`, `0x4c786d`, `0x55c6c9`, `0x55ca7f`, `0x55cfde`, `0x55d114`, `0x55d3cc`, `0x55d816`, `0x55da02`, `0x55dffa`, `0x55e099`, `0x55e25a`, `0x55e2fc`, `0x55e42b`, `0x55e4cd`, `0x55f8ea`, `0x55fbd3`, `0x55ff9a`, `0x5602a3`, `0x56066d`, `0x560744`, `0x560791`, `0x560d9a`, `0x561083`, `0x56144a`, `0x561753`, `0x561b1d`, `0x561bf4`, `0x561c41`, `0x56224a`, `0x562533`, `0x5628fa`, `0x562c03`, `0x562fcd`, `0x5630a4`, `0x5630f1`, `0x5636fa`, `0x5639e3`, `0x563daa`, `0x5640b3`, `0x56447d`, `0x564554`, `0x5645a1`, `0x564ba6`, `0x564c9c`, `0x564e5a`, `0x565023`, `0x5652bd`, `0x565394`, `0x5653cc`, `0x5c5093`, `0x5c5103`. P03 outbound-xref seal: exactly one `from` / `code` ordinary-flow endpoint, 0x004a9090 -> 0x004a9091.

P04 inbound-xref seal: exactly 210 `to` / `data` endpoints, sorted ascending with no pagination remainder: `0x41daff`, `0x41dde9`, `0x41e1f0`, `0x41e4fc`, `0x41e8c6`, `0x41e99a`, `0x41e9e7`, `0x41fbbf`, `0x4519ba`, `0x459bd7`, `0x459d2f`, `0x45a016`, `0x45a420`, `0x45a71c`, `0x45aa93`, `0x45ab66`, `0x45ac3a`, `0x45ac87`, `0x464b24`, `0x466011`, `0x4661fc`, `0x466254`, `0x4663d5`, `0x46642d`, `0x466449`, `0x46647c`, `0x46649e`, `0x466501`, `0x46665d`, `0x466671`, `0x466960`, `0x466971`, `0x466990`, `0x4669a4`, `0x4669cd`, `0x466ac0`, `0x469533`, `0x46d4ba`, `0x46fa2d`, `0x470f98`, `0x47c73a`, `0x47f384`, `0x47f6fe`, `0x484cda`, `0x488922`, `0x4889d6`, `0x494f7a`, `0x497c6d`, `0x49852d`, `0x49e6ee`, `0x4a71fb`, `0x4a8b89`, `0x4a8b90`, `0x4a8f26`, `0x4ab3e0`, `0x4ab44c`, `0x4b0e5a`, `0x4c7866`, `0x4c7f5a`, `0x4c829a`, `0x4e8ea1`, `0x4e8ebd`, `0x4e8ef8`, `0x4e8f37`, `0x4e8f4f`, `0x4e8fee`, `0x4e9263`, `0x4e929d`, `0x4ea95a`, `0x4ec957`, `0x4eee6a`, `0x4f25aa`, `0x4f282b`, `0x4f292a`, `0x4f2aeb`, `0x4f2c0b`, `0x4f2ce7`, `0x4f4208`, `0x4f42cf`, `0x4f430a`, `0x4f649d`, `0x4f6c07`, `0x4fc662`, `0x4ffb24`, `0x4fff2b`, `0x5005d6`, `0x506e5b`, `0x516a7a`, `0x52087a`, `0x527879`, `0x527926`, `0x527946`, `0x527a7f`, `0x527afb`, `0x527b5d`, `0x527c3d`, `0x527fa3`, `0x52815b`, `0x5285b6`, `0x52b89a`, `0x5465f8`, `0x54b0d4`, `0x54b1d0`, `0x557a0d`, `0x557a22`, `0x557a4d`, `0x557de9`, `0x557dfe`, `0x557e29`, `0x5581ab`, `0x5581c0`, `0x5581eb`, `0x55c6bf`, `0x55ca75`, `0x55cfd1`, `0x55d107`, `0x55d3bf`, `0x55d809`, `0x55d9f8`, `0x55dfea`, `0x55e250`, `0x55e2f2`, `0x55e421`, `0x55e4c3`, `0x55f8df`, `0x55fbc9`, `0x55ff90`, `0x56029c`, `0x560666`, `0x56073a`, `0x560787`, `0x560d8f`, `0x561079`, `0x561440`, `0x56174c`, `0x561b16`, `0x561bea`, `0x561c37`, `0x56223f`, `0x562529`, `0x5628f0`, `0x562bfc`, `0x562fc6`, `0x56309a`, `0x5630e7`, `0x5636ef`, `0x5639d9`, `0x563da0`, `0x5640ac`, `0x564476`, `0x56454a`, `0x564597`, `0x564b9a`, `0x564c92`, `0x564e50`, `0x56501c`, `0x5652b6`, `0x56538a`, `0x5653c2`, `0x568bda`, `0x56da1a`, `0x571c1a`, `0x57c08a`, `0x57c71a`, `0x57d8da`, `0x57edba`, `0x57f955`, `0x57fcb9`, `0x58037e`, `0x5858da`, `0x58816a`, `0x58967a`, `0x590a8e`, `0x59404b`, `0x594207`, `0x595b0a`, `0x59d92d`, `0x5a19aa`, `0x5a36a8`, `0x5a5077`, `0x5a5c41`, `0x5a5e12`, `0x5ade4a`, `0x5ae41d`, `0x5aedda`, `0x5af71b`, `0x5b001a`, `0x5b13aa`, `0x5b1c6a`, `0x5b2737`, `0x5b301a`, `0x5b326a`, `0x5b358a`, `0x5b395a`, `0x5b3e9b`, `0x5b458a`, `0x5b48ba`, `0x5b4d9a`, `0x5b504a`, `0x5b570a`, `0x5b596a`, `0x5b5d7a`, `0x5b5f9a`, `0x5b61fa`, `0x5b63aa`, `0x5b663a`, `0x5b692a`, `0x5c3e7d`, `0x5c508c`, `0x5c50fc`. P04 outbound-xref seal: zero `from` endpoints.

Gate 2B handoff totals are exactly six ordered action rows, I01-I06: six persistent mutations comprising two pure renames, two function type applications, and two address-repeatable comment applications. I02 and I05 each additionally permit one bounded same-function cache-only force_recompile followed by fresh public readback. Exactly eight NO_CHANGE protections, P01-P08, apply before and after every action row. P03/P04/P06-P08 comprise five independently literal protection rows with endpoint seals; P01/P02/P05 retain their exact contracts. Any partial read, pagination remainder, mismatch, drift, spillover, or partial action fails closed without save.

B009's earlier no-mutation pre/post read pair was sealed by dated 2026-08-24T11:30:42Z attestations. The later 2026-08-24T15:00:04Z canonical repair snapshot independently reconfirmed both raw target/sibling names/types, exact three-row frames, absent comments, collision absence, exact 0x66 bytes, five-block/39-instruction profiles, caller/callee sets, CC padding bytes, and zero padding xrefs; canonical disk identity at 2026-08-24T14:27:03.4932477Z was 143,211,656 bytes with SHA256 B0B1EB4651D6AB2E122A25416DF56B5F2A9FF2CFB1253E734AFEA2AB36731D67. The earlier complete P03/P04 endpoint seals remain dated evidence and were not rewritten as permanently current. These read-only snapshots prove report repair caused no IDA change; neither replaces the supervisor's fresh before/after Gate 2B readback.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. UID0003SS is reconstructable and already routed through UID0000PB.
- Exact target RECONSTRUCTION_CPP CODE insertion:

~~~cpp
void WorldMapPane::UpdateHoverFromMouse()
{
    Point cursorPosition;
    g_pEventMan->GetCursorPosition(&cursorPosition);

    const int nodeIndex =
        HitTestNode(cursorPosition.x, cursorPosition.y);

    if ((nodeIndex == -1 || m_reachableNodes[nodeIndex]) &&
        m_hoveredNodeIndex != nodeIndex)
    {
        m_hoveredNodeIndex = nodeIndex;
        InvalidateRect(0);
    }
}
~~~

- Exact target RECONSTRUCTION_H CODE disposition: keep the multiline block empty. UID0000G9 already emits the one private declaration void UpdateHoverFromMouse();.
- Behavior preservation: short-circuit evaluation prevents indexing at -1, unreachable hits retain prior hover, misses clear, equal values skip the write/invalidation, and no extra checks or side effects are introduced.
- Source shape: normal private member code, typed Point, EventMan member call, HitTestNode, std::vector<bool> indexing, named class field, and inherited invalidation match the accepted mid-2000s source model.
- Third-party import: not applicable. This is first-party NexusTK class source, not a vetted staged embed.

## Final Recommendation

Implement UID0003SS exactly as the formal body above and raise it to 93/94. Preserve its owner/emitter/path/range. Keep its H block empty and its optional position blank. Incorporate the support-page corrections without populating support formal blocks or granting additional target coverage.

The supervisor should apply I01-I06 in exact order only under freshly established Gate 2B authority, stop without save after any failed stage/readback, and leave P01-P08 unchanged. No target split, renamed ordinary path, new UID, new source file, header, global, field, or manual/generated direct edit is warranted.

## Recommended Target Doc Changes

- Dated callback disposition: applied at full report detail and independently scoped-validated by command 000000027536; that command is a historical callback receipt, not current generated authority.
- Path: by-memory/0x005c5080-0x005c50e6.WorldMapPaneUpdateHoverFromMouse.md.
- Metadata: 93/94; preserve UID, owner, reconstructable, emitter, optional position, Nested:0.
- Formal CPP: exact body in the First-Draft section.
- Formal H: blank with exact duplicate-declaration proof.
- Item Summary: Exact clear-capable WorldMapPane cursor-hover update: polls EventMan, hit-tests nodes, clears on a miss, accepts reachable hits, and invalidates only when m_hoveredNodeIndex changes.
- Add exact sections for ABI/frame, behavior, caller branches, field contract, sibling distinction, boundaries/padding/hash, source placement, negative evidence, score, and change history.
- Historicalize the 2026-06-16 unresolved-name/field blocker as superseded by current UID0000G9/Point/EventMan types and the fresh sibling/caller proof.

## Recommended Support Doc Changes

Callback disposition: all seven rows below were applied at full report detail, scoped-validated, and reread. Support metadata/formal blocks/routes remained unchanged except for the explicitly accepted prose/inventory additions.

| Support path | Exact callback incorporation |
| --- | --- |
| by-memory/0x005c50f0-0x005c5156.WorldMapPaneUpdateHoverFromMouseStrict.md | Preserve all metadata/formal blocks; replace provisional distinction with exact reachable-hit-only, miss-preserving behavior, source-void ABI, 0x005c4237 caller, hash/frame/padding facts, and accepted descriptive name. |
| by-memory/0x005c37e0-0x005c38fd.WorldMapPaneHitTestNode.md | Add exact Point x/y argument relation, view-center conversion, strict +/-20 test, 0x94 stride, index/-1 result, and two-caller relation; historicalize only the stale node-field blocker. |
| by-memory/0x005c40c0-0x005c4245.WorldMapPaneHandleMouseEvent.md | Add exact event-type/drag/navigation routes and target/sibling callsites; state that helper input comes from EventMan while Event payload coordinates serve drag arithmetic. Preserve formal blocks/metadata. |
| by-class/WorldMapPane.md | Add exact hover helper contract under Input/field evidence; preserve declaration spellings, complete H, size/layout, score, and unrelated content. |
| by-file/WorldMapPane.md | Add UID0003SS source contract and exact callback generated-readback requirements; preserve 92/93, path, complete inventory, and unrelated source. |
| by-memory/0x005c2ac0-0x005c5c87.WorldMapPane.md | Replace raw target/sibling inventory roles with accepted descriptive roles; add both ten-byte gap rows; preserve broad parent non-emission, score, and unrelated children. |
| by-memory/-ignored.md | Add exact two ten-byte CC alignment entries with hashes/zero-xref/source disposition and links to neighboring children/owners. |

No support path is renamed. No support formal body is populated. No by-file/by-class score or source route changes.

## Score And Metadata Recommendation

- Pre-callback target: 85/88, reconstructable true, owner UID0000G9, emitter UID0000PB, blank formal CPP/H.
- Current target: 93/94 with complete CPP and intentionally blank H; all non-score metadata is preserved.
- Completion increase rationale: exact body/boundaries/hash, ABI/frame/source return, callers, callees, fields, sibling distinction, side effects, source name/placement, formal CPP/H disposition, generated expectation, and manual coverage text are all closed.
- Confidence increase rationale: all behavior and types are current live facts; only private lexical spelling and rebuilt-binary equivalence remain inferential/unavailable.
- Reason not 95+: no original source/PDB/private symbol and no compiled source-to-binary comparison. The target source is behavior-ready, but exact original spelling is not original-proof.
- Preserve all non-score metadata exactly.
- Support scores remain unchanged because this report does not claim complete formal implementations for UID0003ST, UID0003SJ, or UID0003SM.

## Open Questions With Attempted Resolution

- Original target spelling: no symbol/string/PDB/source route exists. Best resolution is the established descriptive UpdateHoverFromMouse, supported by exact behavior. This does not block source.
- Original sibling spelling: same negative evidence. Best resolution is the established UpdateHoverFromMouseStrict because its predicate is narrower. This does not block the target.
- Source return: exhaustive caller and exit-state review rejects unsigned int; void is the only coherent model.
- Input source: exact body rejects Event payload input and proves current EventMan polling.
- Hover/reachability fields: current UDT and offset accesses close both names/types.
- Why two helpers: caller branches plus the one miss-branch difference close the question. Target is clear-capable for click/release; sibling is passive reachable-hit-only cursor motion.
- No target behavior question remains unresolved. A rebuilt comparison could increase original-form confidence but is not required for callback correctness.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Current by-memory/-coverage-report.md has parent UID0001O4 and the predecessor alignment row at 0x005c5075-0x005c5080, but no UID0003SS row and no rows for the two newly documented gaps. The supervisor should insert the following rows immediately after the existing 0x005c5075-0x005c5080 row, in this address order:

~~~text
        - [UID:0003SS][0x005c5080-0x005c50e6.WorldMapPaneUpdateHoverFromMouse](by-memory/0x005c5080-0x005c50e6.WorldMapPaneUpdateHoverFromMouse.md) 0x005c5080-0x005c50e6 | private class method | WorldMapPane::UpdateHoverFromMouse : reconstructable : 93% : very strong : Exact source-ready clear-capable hover update polls EventMan for current Point coordinates, calls HitTestNode(x,y), clears m_hoveredNodeIndex on a miss, accepts only reachable nonnegative hits through m_reachableNodes, invalidates only when the value changes, preserves exact void ABI/frame/callers/hash/padding, and emits through WorldMapPane.cpp with the declaration owned by UID0000G9.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005c50e6-0x005c50f0 | padding | WorldMapPane hover-helper alignment : ignored : 100% : very strong : Ten exact 0xcc bytes with zero xrefs between UID0003SS and UID0003ST; non-source and non-emitting.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005c5156-0x005c5160 | padding | WorldMapPane hover-to-predecessor alignment : ignored : 100% : very strong : Ten exact 0xcc bytes with zero xrefs between UID0003ST and UID0003SU; non-source and non-emitting.
~~~

The existing by-class UID0000G9 and by-file UID0000PB manual rows remain accurate because their scores, paths, ownership, reconstruction state, class shape, and complete child-route statements do not change. UID0003ST/UID0003SJ/UID0003SM metadata and formal state also remain unchanged, so no manual row is claimed for them. Auto-generated coverage/tracker files remain validator-owned and receive no manual text.

## Follow-Up Actions

- B009 ordinary work is complete for C001-C026 and C043-C045.
- Any later Gate 2A documentation review, six-stage I01-I06 Gate 2B disposition, C041-C042 manual-coverage action, report execution, or archive movement is supervisor-owned. Its current state is authoritative only from external supervisor audit plus this report's current path and validator-owned status/history metadata.
- No B009 work remains on UID0003SS unless the supervisor returns this same report for a specific repair. This report does not infer or assert a pending or completed external gate or lifecycle state.

## Confidence

- Recommendation confidence: very high.
- Behavior/ABI/field/source-placement confidence: very high.
- Private source-name confidence: high/descriptive, not original-proof.
- Score confidence: high at 93/94.
- Remaining uncertainty: original private spelling and rebuilt-byte equivalence only.

## Validator Results

- Report-only research commands: none, as required before Gate 1.
- The table below is the dated ordinary callback validator receipt set. Command 000000027536 proves the callback validation event; the later physical generated snapshots are also dated receipts and do not establish future-current authority.

| Path | Exact scoped command | command_id | command_timestamp | Exit / ok | Generated state |
| --- | --- | --- | --- | --- | --- |
| by-memory/0x005c50f0-0x005c5156.WorldMapPaneUpdateHoverFromMouseStrict.md | `python .\tools\validator.py --mode file --file by-memory/0x005c50f0-0x005c5156.WorldMapPaneUpdateHoverFromMouseStrict.md --apply --queue-timeout 240` | 000000027521 | 2026-08-24T05:10:48-04:00 | 0 / 1 | deferred |
| by-memory/0x005c37e0-0x005c38fd.WorldMapPaneHitTestNode.md | `python .\tools\validator.py --mode file --file by-memory/0x005c37e0-0x005c38fd.WorldMapPaneHitTestNode.md --apply --queue-timeout 240` | 000000027522 | 2026-08-24T05:11:24-04:00 | 0 / 1 | deferred |
| by-memory/0x005c40c0-0x005c4245.WorldMapPaneHandleMouseEvent.md | `python .\tools\validator.py --mode file --file by-memory/0x005c40c0-0x005c4245.WorldMapPaneHandleMouseEvent.md --apply --queue-timeout 240` | 000000027527 | 2026-08-24T05:12:05-04:00 | 0 / 1 | deferred |
| by-class/WorldMapPane.md | `python .\tools\validator.py --mode file --file by-class/WorldMapPane.md --apply --queue-timeout 240` | 000000027529 | 2026-08-24T05:12:39-04:00 | 0 / 1 | deferred |
| by-file/WorldMapPane.md | `python .\tools\validator.py --mode file --file by-file/WorldMapPane.md --apply --queue-timeout 240` | 000000027530 | 2026-08-24T05:13:22-04:00 | 0 / 1 | deferred |
| by-memory/0x005c2ac0-0x005c5c87.WorldMapPane.md | `python .\tools\validator.py --mode file --file by-memory/0x005c2ac0-0x005c5c87.WorldMapPane.md --apply --queue-timeout 240` | 000000027531 | 2026-08-24T05:14:10-04:00 | 0 / 1 | deferred |
| by-memory/-ignored.md | `python .\tools\validator.py --mode file --file by-memory/-ignored.md --apply --queue-timeout 240` | 000000027532 | 2026-08-24T05:15:03-04:00 | 0 / 1 | deferred |
| by-memory/0x005c5080-0x005c50e6.WorldMapPaneUpdateHoverFromMouse.md | `python .\tools\validator.py --mode file --file by-memory/0x005c5080-0x005c50e6.WorldMapPaneUpdateHoverFromMouse.md --apply --queue-timeout 240 --wait-generated` | 000000027536 | 2026-08-24T05:16:12-04:00 | 0 / 1 | completed |

- The historical final target callback validator reported `autogen_cpp_update: 1` for UID0000PB and completed foreground generated refresh at command 000000027536 / 2026-08-24T05:16:12-04:00. Its dated physical write receipt was 13,670 bytes, SHA256 966F17663AC6FA924025DB6C2F4E716338A6D8E9B4FCF379656F241443A8AEFC, 347 LF, zero CR, terminal LF, and last write 2026-08-24T09:16:44.7361870Z. Normal validator-owned reference index, projected stats, auto-coverage, research-tracker, metadata, and registry refreshes were not manually edited by B009.
- Dated later generated readback: command 000000027608 / 2026-08-24T06:10:10-04:00 produced 13,670 bytes, SHA256 F5736BF2BC4F7505647549700BBE4BBC3268BF0288F06E6819525C6B8041C678, 347 LF, zero CR, terminal LF, and last write 2026-08-24T10:10:35.6282478Z; this is not current authority.
- Latest dated physical generated readback at this repair: auto-generated/NexusTK/map/WorldMapPane.cpp was 13,670 bytes, SHA256 11C47ACBC59CD5BA30A94C86D45C1EABF06F3C900CE60047188FC852500FF567, 347 LF, zero CR, terminal LF, last write 2026-08-24T13:31:41.3073793Z; header command/time exactly 000000027631 / 2026-08-24T09:31:09-04:00. Future-current authority requires a fresh supervisor physical reread.
- Generated completion audit: exactly one `void UpdateHoverFromMouse();` declaration, exactly one `void WorldMapPane::UpdateHoverFromMouse()` definition, one UID0003SS marker attached to that definition, zero UID0003SS empty markers, one preserved UID0003ST empty marker, and 21 total empty markers. The prior 22-marker/333-LF baseline changed by the one target marker-to-body replacement to 21 markers/347 LF; unrelated child markers and surrounding source remain present. No auto-generated/NexusTK/map/WorldMapPane.h exists.
- No execute_report, lifecycle, queue-management, broad validator, dry-run lifecycle, IDA, manual coverage, or manual generated-file command was run.

## Changed Files

- Modified ordinary page: by-memory/0x005c5080-0x005c50e6.WorldMapPaneUpdateHoverFromMouse.md; 12,145 bytes; SHA256 8BB1670A1C5DD6F35CEEC358C4FCFF1386A96383D1F0BE25477375DBFDCC1A86.
- Modified ordinary page: by-memory/0x005c50f0-0x005c5156.WorldMapPaneUpdateHoverFromMouseStrict.md; 7,034 bytes; SHA256 13C2EBF90A59F80442E0965BAE6B1EB2A323B25CA277F1F8A42A8CEE08E656A7.
- Modified ordinary page: by-memory/0x005c37e0-0x005c38fd.WorldMapPaneHitTestNode.md; 5,516 bytes; SHA256 CF7E8874E0C072748BF1F0C718FC28284E55AAB263978C3DF8628B2F327D1AF2.
- Modified ordinary page: by-memory/0x005c40c0-0x005c4245.WorldMapPaneHandleMouseEvent.md; 6,051 bytes; SHA256 8E776C7310A929E7B131BB8855390C047BCC92ADDAFB146966A43CC3D92AF368.
- Modified ordinary page: by-class/WorldMapPane.md; 29,781 bytes; SHA256 E19D4C91972D2A0D2723FEDC5F9CD0F31A42C3EA64F73DAE25043E839F3FF839.
- Modified ordinary page: by-file/WorldMapPane.md; 25,255 bytes; SHA256 AF9E1C893339E75903730081879CD2EAB429D0379D101BC2B62AC5468A91C789.
- Modified ordinary page: by-memory/0x005c2ac0-0x005c5c87.WorldMapPane.md; 29,557 bytes; SHA256 497AF8BA0689EEF15055EEF58FC4B6DF10B4CF2CD516277EEA825A3BDC7E020C.
- Dated callback ordinary-write receipt: by-memory/-ignored.md was 1,151,512 bytes with SHA256 92A98848BCB0A73381559F0D6D84C8E9CBB17E74A6F1A7ED136D1E7455FB2A84 immediately after the UID0003SS callback write; this is not current shared-file identity.
- Latest dated shared-file readback at this repair: by-memory/-ignored.md was 1,153,328 bytes, SHA256 8DB054EB291F182CAD2983EE25246FD660B2265356C718341CFADDA0AB3A92D7, 5,520 LF, zero CR, terminal LF, and last write 2026-08-24T12:49:20.2426623Z. Physical text inspection found exactly one complete C026 entry for [0x005c50e6,0x005c50f0) and exactly one complete C026 entry for [0x005c5156,0x005c5160). Future-current authority requires a fresh supervisor physical reread.
- Modified report: tools/leaser/Agents/Agent-B009/research/0003SS-WorldMapPaneUpdateHoverFromMouse-source-quality.md; current mechanics and identity are sealed below after final reread.
- Validator-owned side effects include refreshed generated metadata/reports/registry/tracker and auto-generated/NexusTK/map/WorldMapPane.cpp. B009 did not edit any generated file directly.
- Manual coverage, audit, catalog, registry, tracker, lifecycle, other-agent, and executed-archive files manually modified by B009: none. IDA/MCP mutation/save/manage actions: none.
- Report lifecycle boundary: execution/archive state is supervisor-owned and authoritative only from the report's current path plus validator-owned status/history metadata. This callback artifact carries exactly one standalone `READY_FOR_SUPERVISOR_EXECUTE` marker after the checklist.

## Implementation Tracking Checklist

| Done | Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| [x] | C001 | 0003SS | Preserve the exact target range [0x005c5080,0x005c50e6), size 0x66, 39 instructions, five blocks, and body SHA256 FDD207906B32F452FB48C445080B1C85C75E28B51EBCEF87CDF0F6E73C3F9041. | Very high | Dated 2026-08-24T15:00:04Z MCP function, CFG, disassembly, bytes, and physical executable readback. | UID0003SS Boundaries and IDA Evidence | incorporate | applied |
| [x] | C002 | 0003SS | Preserve eleven CC bytes at [0x005c5075,0x005c5080), ten CC bytes at [0x005c50e6,0x005c50f0), and ten CC bytes at [0x005c5156,0x005c5160) as non-source alignment outside all three functions. | Very high | Dated MCP items, bytes, zero xrefs, and exact padding hashes. | UID0003SS Boundary Evidence; UID0003ST Boundary Evidence; by-memory/-ignored.md | incorporate | applied |
| [x] | C003 | 0003SS | Reconstruct the source ABI as private void WorldMapPane::UpdateHoverFromMouse() with no explicit arguments and one eight-byte Point local; the incidental EAX values are not a return contract. | Very high | Callers ignore EAX; update and no-update paths leave unrelated values; exact frame. | UID0003SS ABI and formal CPP | incorporate | applied |
| [x] | C004 | 0003SS | Record g_pEventMan->GetCursorPosition(&cursorPosition) as the sole input source and preserve Point y/+0x00, x/+0x04 with HitTestNode(cursorPosition.x, cursorPosition.y). | Very high | Direct global/call instructions, EventMan type, Point UDT, push order. | UID0003SS Behavior and formal CPP | incorporate | applied |
| [x] | C005 | 0003SJ | Record that HitTestNode returns a valid node index or -1 after strict +/-20 map-space bounds over 0x94-byte nodes, with EPF center 512/384 and legacy center 320/240. | Very high | Full current decompile, two exact hover-helper callers, WorldMapNode stride. | UID0003SJ Evidence; UID0003SS Hit-Test Contract | incorporate | applied |
| [x] | C006 | 0003SS | Bind the +0x274 read to std::vector<bool> m_reachableNodes and preserve the compiler-lowered word/bit test as normal source indexing. | Very high | WorldMapPane UDT and exact instructions 0x005c50ab-0x005c50c3. | UID0003SS Field Contract and formal CPP | incorporate | applied |
| [x] | C007 | 0003SS | Bind the +0x1e8 compare/store to int m_hoveredNodeIndex and preserve it as distinct from short m_currentNodeIndex at +0x1ec. | Very high | WorldMapPane UDT, target writes, caller reads, accepted class contract. | UID0003SS Field Contract; UID0000G9 Input Contract | incorporate | applied |
| [x] | C008 | 0003SS | Preserve the exact target predicate: accept -1 or a reachable nonnegative hit, reject an unreachable hit, and write only when the accepted value differs from m_hoveredNodeIndex. | Very high | Exact CFG/disassembly and sibling comparison. | UID0003SS Behavior and formal CPP | incorporate | applied |
| [x] | C009 | 0003SS | Preserve the sole side effects as the conditional hover write followed by Pane::InvalidateRect(0); no write, invalidation, allocation, packet, timer, cursor, or return side effect occurs otherwise. | Very high | Exact 39-instruction body and Pane slot contract. | UID0003SS Side Effects and formal CPP | incorporate | applied |
| [x] | C010 | 0003SM | Record the 0x005c40f5 left-button-down call: when navigation is inactive, refresh hover before choosing drag when hover is -1 versus StartTravelToNode(current hover). | Very high | Full HandleMouseEvent decompile and EventType values. | UID0003SM Branch Contract; UID0003SS Caller Inventory | incorporate | applied |
| [x] | C011 | 0003SM | Record the 0x005c4187 left-button-up call: after an active drag, show cursor, clear m_draggingView, then run the clear-capable target helper. | Very high | Full HandleMouseEvent decompile and exact callsite. | UID0003SM Branch Contract; UID0003SS Caller Inventory | incorporate | applied |
| [x] | C012 | 0003ST | Record the 0x005c4237 cursor-move route: when not dragging and navigation is inactive, the strict sibling accepts only reachable hits and preserves hover on misses or unreachable hits. | Very high | Full caller and sibling decompilations. | UID0003ST Exact Distinction; UID0003SM Branch Contract | incorporate | applied |
| [x] | C013 | 0003SS | Accept UpdateHoverFromMouse as the highest-probability descriptive private source name while preserving the absence of original-symbol proof. | High | Existing class declaration plus exact behavior/callsite role and no collision. | UID0003SS Status, naming rationale, CPP | incorporate | applied |
| [x] | C014 | 0003ST | Accept UpdateHoverFromMouseStrict as the descriptive sibling name because its nonnegative-reachable-only predicate is strictly narrower than UID0003SS. | High | Exact binary difference, existing class declaration, and no collision. | UID0003ST Status and Exact Distinction | incorporate | applied |
| [x] | C015 | 0003SS | Preserve canonical owner UID0000G9, emitter UID0000PB, Nested:0, reconstructable true, blank optional position, and NexusTK/map/WorldMapPane.cpp placement. | Very high | Current metadata, class/file ownership, caller/callee family. | UID0003SS metadata and Source Placement | incorporate | applied |
| [x] | C016 | 0003SS | Insert the exact First-Draft section body into the target RECONSTRUCTION_CPP CODE block with no raw offsets, decompiler labels, extra guards, or sibling body. | Very high | Complete target behavior and accepted source types. | UID0003SS formal CPP | incorporate | applied |
| [x] | C017 | 0003SS | Keep the target RECONSTRUCTION_H CODE block empty because UID0000G9 already emits exactly void UpdateHoverFromMouse(); and a second declaration would duplicate class-owned source. | Very high | Current UID0000G9 formal H and emitter structure. | UID0003SS formal H disposition | incorporate | applied |
| [x] | C018 | 0003SS | Raise UID0003SS from 85/88 to 93/94 while preserving all other metadata; the cap reflects inferred private spelling and no rebuilt-binary comparison. | High | All prior blockers resolved; lexical/original-source evidence remains unavailable. | UID0003SS metadata and Score Rationale | incorporate | applied |
| [x] | C019 | 0003SS | Replace the stale target summary/status/evidence with the complete range, ABI, fields, predicate, callers, sibling distinction, side effects, boundaries, source route, negative evidence, and historicalized old blocker. | Very high | Complete current research inventory. | by-memory/0x005c5080-0x005c50e6.WorldMapPaneUpdateHoverFromMouse.md | incorporate | applied |
| [x] | C020 | 0003ST | Correct the sibling support page from provisional distinction to exact reachable-hit-only/no-clear behavior, accepted descriptive name, caller at 0x005c4237, and exact padding; keep its metadata and formal blocks unchanged. | Very high | Complete sibling body/caller evidence; UID0003ST is not an additional target. | by-memory/0x005c50f0-0x005c5156.WorldMapPaneUpdateHoverFromMouseStrict.md | incorporate | applied |
| [x] | C021 | 0003SJ | Correct the HitTestNode support page with current Point input order, exact centers/strict bounds/stride/result contract, and retire the stale unresolved-node-field statement without populating its formal blocks. | Very high | Complete current HitTestNode decompile and accepted WorldMapNode declaration. | by-memory/0x005c37e0-0x005c38fd.WorldMapPaneHitTestNode.md | incorporate | applied |
| [x] | C022 | 0003SM | Correct the HandleMouseEvent support page with exact event types, two target calls, one strict-sibling call, navigation/drag gates, payload-only drag use, and historicalize its stale field/event blocker without populating its formal blocks. | Very high | Complete current caller decompile, Event UDT, EventType declaration. | by-memory/0x005c40c0-0x005c4245.WorldMapPaneHandleMouseEvent.md | incorporate | applied |
| [x] | C023 | 0000G9 | Add an exact hover-helper input contract to WorldMapPane: target clears on miss, sibling preserves on miss, both reject unreachable hits and invalidate only on change; preserve the existing declarations, layout, score, and formal source. | Very high | Current class UDT/formal plus exact two-function comparison. | by-class/WorldMapPane.md Input Method Family | incorporate | applied |
| [x] | C024 | 0000PB | Add the exact UID0003SS source/emitter contract and callback generated-readback expectations to WorldMapPane.cpp documentation without changing the file score, path, or unrelated inventory. | Very high | Existing emitter route and dated command-000000027631 generated snapshot. | by-file/WorldMapPane.md Hover Source Contract | incorporate | applied |
| [x] | C025 | 0001O4 | Replace the aggregate's raw target/sibling labels with accepted descriptive names/roles and add the two ten-byte hover-family alignment gaps while preserving parent non-emission and every unrelated child. | Very high | Exact current functions/items/bytes and established split parent. | by-memory/0x005c2ac0-0x005c5c87.WorldMapPane.md inventory/boundaries | incorporate | applied |
| [x] | C026 | 0000VN | Add exact ignored entries for [0x005c50e6,0x005c50f0) and [0x005c5156,0x005c5160), each ten CC bytes with zero xrefs and no authored source. | Very high | Dated MCP items, bytes, hashes, xrefs, and 2026-08-24T12:49:20Z shared-file reread. | by-memory/-ignored.md | incorporate | applied |
| [ ] | C027 | 0003SS | Supervisor Gate 2B executes I01 only: pure-rename 0x005c5080 from sub_5C5080 to WorldMapPane__UpdateHoverFromMouse after the literal cumulative prestate, collision, immutable-envelope, and P01-P08 checks, then reread before continuing. | High | Dated raw name/collision proof and the independent I01 stage contract. | IDA I01 target rename | incorporate | proposed |
| [ ] | C028 | 0003SS | Supervisor Gate 2B executes I02 only after I01 readback: apply exact type void __thiscall WorldMapPane__UpdateHoverFromMouse(WorldMapPane *this), permit only the bounded target cache refresh, and prove the complete frame/immutable state unchanged. | Very high | Source-void proof, exact UDT/frame, and the independent I02 stage contract. | IDA I02 target type/frame | incorporate | proposed |
| [ ] | C029 | 0003SS | Supervisor Gate 2B executes I03 only after I02 readback: set the exact target address-repeatable comment, leave the other three channels absent, and prove all prior cumulative state and protections unchanged. | High | Proven behavior and the independent I03 stage contract. | IDA I03 target repeatable comment | incorporate | proposed |
| [ ] | C030 | 0003ST | Supervisor Gate 2B executes I04 only after target final-state readback: pure-rename 0x005c50f0 from sub_5C50F0 to WorldMapPane__UpdateHoverFromMouseStrict after the literal sibling collision/prestate checks. | High | Dated raw name/collision proof and the independent I04 stage contract. | IDA I04 sibling rename | incorporate | proposed |
| [ ] | C031 | 0003ST | Supervisor Gate 2B executes I05 only after I04 readback: apply exact type void __thiscall WorldMapPane__UpdateHoverFromMouseStrict(WorldMapPane *this), permit only the bounded sibling cache refresh, and prove the frame/immutable state unchanged. | Very high | Source-void proof, exact UDT/frame, and the independent I05 stage contract. | IDA I05 sibling type/frame | incorporate | proposed |
| [ ] | C032 | 0003ST | Supervisor Gate 2B executes I06 only after I05 readback: set the exact sibling address-repeatable comment, leave the other three channels absent, and prove both cumulative final states and every protection unchanged. | High | Proven sibling behavior and the independent I06 stage contract. | IDA I06 sibling repeatable comment | incorporate | proposed |
| [ ] | C033 | 0003SS | Protect target bytes, five-block CFG, Point local, xrefs at 0x005c40f5/0x005c4187, callees, and all non-name/type/repeatable-comment state through IDA application. | Very high | Exact current target inventory. | IDA 0x005c5080 protection row | incorporate | proposed |
| [ ] | C034 | 0003ST | Protect sibling bytes, five-block CFG, Point local, xref at 0x005c4237, callees, and all non-name/type/repeatable-comment state through IDA application. | Very high | Exact current sibling inventory. | IDA 0x005c50f0 protection row | incorporate | proposed |
| [ ] | C035 | 0003SJ | Make no IDA change to HitTestNode at 0x005c37e0; protect its current exact range/type/comments/hash and two hover-helper xrefs. | Very high | Current function/item/comments/xrefs and body hash. | IDA 0x005c37e0 no-change protection | incorporate | proposed |
| [ ] | C036 | 0003SM | Make no IDA change to HandleMouseEvent at 0x005c40c0; protect its current exact range/type/comments/hash and vtable data xref at 0x00631450. | Very high | Current function/item/comments/xref and body hash. | IDA 0x005c40c0 no-change protection | incorporate | proposed |
| [ ] | C037 | 0003SS | Make no IDA change to EventMan__GetCursorPosition at 0x004a9090; protect its exact name/range/type, four comment channels, complete three-row frame, 21 bytes/hash, 68 enumerated inbound code xrefs, one outbound flow xref, and shared ownership. | Very high | Dated repair-snapshot function/item/comments/frame/bytes and complete paginated xref readback. | IDA P03 literal no-change dependency | incorporate | proposed |
| [ ] | C038 | 0003SS | Make no IDA change to g_pEventMan at 0x0067a754; protect its exact four-byte data item/name/type, two comment channels, four zero bytes/hash, 210 enumerated inbound data xrefs, zero outbound xrefs, and rejected target ownership. | Very high | Dated repair-snapshot item/comments/bytes and complete paginated xref readback. | IDA P04 literal no-change dependency | incorporate | proposed |
| [ ] | C039 | 0000G9 | Make no IDA UDT change; protect WorldMapPane size 0x298, m_hoveredNodeIndex +0x1e8 int, m_reachableNodes +0x274/0x10, and Point size 8 with y/x offsets 0/4. | Very high | Current type_inspect readback. | IDA WorldMapPane/Point UDT no-change protection | incorporate | proposed |
| [ ] | C040 | 0000VN | Make no IDA change to any P06-P08 padding item; protect each literal absent name/type, exact head/end/size/data kind, comment channels, CC bytes/hash, zero inbound/outbound xrefs, and identical required postread. | Very high | Dated repair-snapshot item/comments/bytes and complete bidirectional xref pre/post readback. | IDA P06-P08 literal no-change protections | incorporate | proposed |
| [ ] | C041 | 0003SS | Insert the exact supervisor-owned UID0003SS manual by-memory coverage row after the existing 0x005c5075-0x005c5080 alignment row. | Very high | Current manual row is absent and target score/summary will change. | by-memory/-coverage-report.md exact insertion | incorporate | proposed |
| [ ] | C042 | 0000VN | Insert the two exact supervisor-owned manual by-memory padding rows around UID0003ST in address order. | Very high | Current manual rows are absent and by-memory/-ignored.md will change. | by-memory/-coverage-report.md exact insertions | incorporate | proposed |
| [x] | C043 | 0003SS | During an accepted callback, run one scoped file validator for each changed ordinary by-* page and use wait-generated on the target's final validator; no validator is run in this report-only pass. | Very high | Current role boundary and validator workflow. | Validator Results and callback checklist | incorporate | applied |
| [x] | C044 | 0003SS | Physically reread the dated generated WorldMapPane.cpp snapshot and prove one target declaration, one target definition, no UID0003SS empty marker, preserved UID0003ST marker, unchanged unrelated content, exact command/time/hash/bytes/line endings, and no target-created header; require a fresh supervisor reread at any later gate. | Very high | Dated generated command 000000027631 physical readback and exact CPP/H disposition. | Dated generated verification | incorporate | applied |
| [x] | C045 | 0003SS | Preserve rejected event-payload/custom-bitset/raw-offset/extra-guard/return-value/new-file/duplicate-H alternatives, historicalize the old unresolved-name/field blocker, and record that third-party import is not applicable to first-party WorldMapPane source. | Very high | Positive and negative evidence inventory. | Target/support history and source disposition | incorporate | applied |

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000027641","destination_path":"executed-b-agent-research/B009/0003SS-WorldMapPaneUpdateHoverFromMouse-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/0003SS-WorldMapPaneUpdateHoverFromMouse-source-quality.md","timestamp":"2026-08-24T11:38:21-04:00","uid":"0003SS"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
