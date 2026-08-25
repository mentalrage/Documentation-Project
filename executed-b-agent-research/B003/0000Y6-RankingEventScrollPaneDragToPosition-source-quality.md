** TARGET-REPORT-UID:0000Y6 **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0000Y6 RankingEventScrollPaneDragToPosition Ownership / Source-Quality Research


## Finalized Report / Current Recommendation

- Implemented recommendation: UID0000Y6 remains the source-authored private method `void RankingEventScrollPane::DragToPosition(int y, int x)` under class owner/emitter UID0000BO and file UID0000MZ. Its exact managed C++ now uses source-facing `owner->SetScrollPosition(0, oldPosition, newPosition)` factorization, and the target score is `90/92` from `86/90`.
- Implemented disposition: reconstructable, owner/emitter unchanged, no split, no new child, no source-file move, and no change to `Nested:0` or blank optional emitter position.
- Callback state: C01-C20 were incorporated and validated. The canonical by-memory filename remains `0x0045ac10-0x0045adc3...` because this project names the inclusive last byte; the modeled function is `[0x0045ac10, 0x0045adc4)`.
- Confidence: strong for range, signature, callers, coordinate order, arithmetic, state fields, owner/child synchronization, source placement, and first-draft C++; inferred period-appropriate spellings remain below original-symbol proof.

## Supporting Research

- B003 performed an independent report-only pass on 2026-07-12 using live IDA MCP database `bf5519ae`, current by-* documentation, accepted sibling reports, and current generated output.
- MCP evidence was collected while `idb_list` request `1131` listed one healthy NexusTK worker session and `server_health` request `1132` reported `status:ok`, imagebase `0x400000`, and analysis, Hex-Rays, and strings cache ready.
- Gate 1 correction re-read B005 report `tools/leaser/Agents/Agent-B005/research/0000Y5-RankingEventScrollPaneRawHoverDragHelpers-source-quality.md`, especially its independent `0x0045b200` evidence and Destination 6. B003 then independently rechecked the method, both modeled callers, and UID0000Y6's expanded tail through MCP requests `1201-1206`; the factorization conclusion below is not copied without verification.
- The initial report-only artifact was created at the assigned B003 research path before any supervisor-owned lifecycle operation. During the accepted callback B003 used short one-file leases, ran the scoped validators and final waited generated verification recorded below, and released each lease immediately. B003 ran no execute, lifecycle, move, archive, generated-file edit, or IDA mutation command.
- Wave2/Wave3 artifacts were not used as authority. Historical by-memory report text was treated only as a search lead where encountered.

## Target

- Target UID: `0000Y6`.
- Target path: `by-memory/0x0045ac10-0x0045adc3.RankingEventScrollPaneDragToPosition.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md` -> `by-memory` -> `Not-Covered Files - Reconstructable`.
- Supervisor callback classification: accepted implementation of C01-C20 from report SHA `197763CFB8A279D81C02392E482DF0DFD10DE52B3328D9F473A733EA01C7258C`.
- Implemented scores and parent state: `90/92`, `CANONICAL_OWNER:0000BO`, `EMITTER_UIDS:0000BO`, `RECONSTRUCTABLE:TRUE`, blank optional position, `Nested:0`.

## Current Target State

- Metadata identifies a reconstructable `RankingEventScrollPane` helper routed through class UID0000BO and file UID0000MZ.
- The exact managed formal C++ is populated with the accepted method body and factorized owner call.
- Target prose records all six callers, the owner/list/child update path, modeled end-exclusive address `0x0045adc4`, exact formulas, signed division semantics, no-change behavior, source return type, and inferred-name limits.
- The title/path endpoint `0x0045adc3` is the inclusive last byte and is not a one-byte range defect. The exact function size is `0x1b4`, so the half-open binary range is `[0x0045ac10, 0x0045adc4)`.
- Historical pre-callback generated command `000000008716`, refreshed `2026-07-12T20:14:06-04:00`, represented UID0000Y6 as an Empty Emitter Marker because the target block was blank. Final waited generated command `000000008769`, refreshed `2026-07-12T20:46:07-04:00`, emits one UID0000Y6 body and no UID0000Y6 Empty Emitter Marker.
- Related docs checked: UID0000BO, UID0000BN, UID0001VO, UID0001YK, UID0000MZ, UID0000Y3, UID0000Y4, UID0000Y5, UID0001ZA, UID0001ZB, UID00015S, and sibling drag helpers UID0001GX/UID0001H0.
- Callback implementation and required validator verification are complete. Report execution, count/path state, move, archive, and any later generated state are external supervisor/validator-owned state and are not asserted or directed by this artifact.

## Executive Recommendation

- Direct owner: UID0000BO `RankingEventScrollPane`; callback consumer/support owner: UID0000BN `RankingEventListPane`; source file: UID0000MZ `NexusTK/ui/dialogs/RankingDialog.cpp`.
- Retain the method name `DragToPosition`. It is already accepted by UID0000Y3, UID0000Y4, UID0000Y5, UID0001VO, and generated `RankingDialog.cpp`, and its behavior is a direct drag/track coordinate-to-scroll conversion.
- Use signature `void RankingEventScrollPane::DragToPosition(int y, int x)`. The binary is `__thiscall`, consumes two 32-bit coordinates, returns with `retn 8`, and has no stable source return value; all six callers ignore EAX.
- Target is `90/92`; narrow support evidence was added to UID0000BO, UID0000BN, UID0001VO, UID0001YK, and UID0000MZ with the accepted support scores.
- Do not move this target to a generic scrollbar module, direct `RankingEventListPane` ownership, or a raw-helper container. Do not merge the following alignment or raw reset helper into the target.

## Supervisor Callback Recheck

- The accepted callback required C01-C20 implementation, exact drag math, owner/list/child semantics, source names/types, complete managed C++, scoped validation, and final waited generated verification; each item is complete.
- No split repair is required. The only range clarification is inclusive filename endpoint `0x0045adc3` versus modeled end-exclusive `0x0045adc4`.
- This target is the sole source-bearing function in its page. The preceding UID0000Y5 raw island ends at `0x0045ac10`; the following twelve `0xcc` bytes and UID0000Y7 raw reset helper remain separate.

## Inference Research Guidance Check

- IDA facts, documentation evidence, and inference are separated throughout this report.
- Existing assumptions treated as uncertain were the decompiler `int` return, provisional x/y names, provisional owner accessor wording, unsigned-versus-signed word types, track-limit local names, and the idea that missing original symbols require blank C++.
- Binary and accepted geometry evidence resolve y-first coordinates, signed-short position/range storage, exact formulas, and the owner route. Source spellings `DragToPosition`, `GetOwnerPane`, and `SetScrollPosition` are high-probability inferred names established by the local class family; owner fields and `UpdateScrollBarState` remain binary evidence for the inlined callee body, not direct member accesses in the recommended Y6 source.
- Wave2/Wave3 mentions and legacy recovered artifacts were ignored as stale unless corroborated by current MCP/by-* evidence.

## Heuristic / Inference Reanalysis And Validation

| Issue | Resolution | Evidence class |
| --- | --- | --- |
| Return type | `void`, not decompiler `int`; no path intentionally returns a value and all callers discard EAX. | IDA fact plus source inference |
| Coordinate order | `(int y, int x)`; vertical uses first argument and horizontal uses second. | Direct caller disassembly, canonical `Point` layout |
| Part helper | `GetPartRect(kRankingScrollPartThumb, &thumbRect)`. | Accepted UID0001ZB and call operand `2` |
| Orientation | `m_orientation == 0` vertical; nonzero horizontal. | Direct branches plus UID0001VO/Y4/ZB |
| Position/range types | signed `short` fields at `+0xfe/+0x100`; arithmetic promotes to signed `int`. | Accepted layout plus `movsx`/word operations |
| Drag anchor | `Point m_thumbDragOffset`, y at `+0x108`, x at `+0x10c`. | UID00015S/Y3/Y5 and direct subtraction sites |
| Track rectangles | copies of `m_bounds`; leading collapses the ending edge, trailing collapses the starting edge. | Direct SIMD copies and edge stores |
| Clamp | thumb start clamps to track start and `trackEnd - thumbExtent`; `+1` is preserved before clamp. | `cmovl`, `cmovge`, direct arithmetic |
| Division/rounding | signed `idiv`, truncation toward zero; no denominator guard. | Direct `cdq; idiv` in both branches |
| Vertical asymmetry | numerator uses `m_scrollRange + 1`, then caps to `m_scrollRange`. | Direct `inc ecx`, compare/cap |
| Horizontal asymmetry | numerator uses `m_scrollRange` with no explicit post-cap. | Direct `movsx` and division branch |
| Owner accessor | `GetOwnerPane()` for inherited primary slot `+0x1c`. | Vtable `0x00610a68 -> 0x005447a0` and accepted sibling naming |
| Owner callback factorization | UID0000Y6's changed tail is the normalized body of `RankingEventListPane::SetScrollPosition(int, short, short)` at `0x0045b200`; source uses `owner->SetScrollPosition(0, oldPosition, newPosition)`. | Exact sequence comparison, `retn 0x0c`, and two modeled callers |
| Inlined owner fields/helpers | owner `+0x108` child, owner `+0x10c` position, conditional child invalidation, `UpdateScrollBarState`, and owner invalidation prove the callee match but are not written directly by Y6 source. | `0x45ad79-0x45adae` versus `0x45b210-0x45b245` |
| No-change path | no owner lookup, writes, refresh, or invalidation. | Branch at `0x0045ad6e -> 0x0045adb1` |
| Source placement | private ranking scrollbar method in `RankingDialog.cpp`. | Feature-local callers, owner, resources, classes |

Rejected alternatives:

- `int`/`short` return is rejected because the unchanged path can leave an arithmetic temporary in EAX while the changed path leaves an invalidation result; no caller consumes either value.
- `(x, y)` is rejected by all six call sequences, `Point` y/x storage, and the vertical/horizontal argument reads.
- Generic `ScrollPane` ownership is rejected because this exact method synchronizes `RankingEventListPane` fields and calls ranking-specific `0x0045b080`.
- Direct list-pane method ownership is rejected because ECX is the scroll child, fields through `+0x10c` are scroll-pane fields before the owner callback, and callers are scroll-pane methods/raw helpers.
- Direct Y6 access to `owner->m_scrollPosition`, `owner->m_scrollPane`, and their private internals is rejected as decompiler/inliner expansion. The expanded instruction sequence exactly matches independently modeled `RankingEventListPane::SetScrollPosition`, and its two ordinary callers prove the three-argument source API.
- A helper abstraction that omits duplicate cursor/origin sampling or adds a sentinel fallback is rejected because it would change observed behavior.
- Defensive divide-by-zero checks, range preclamps, rounding-to-nearest, and removal of `+1` are rejected as behavior changes.
- Renaming/moving the target to a different source file or merging UID0000Y7 is rejected by contiguous class/file evidence and the explicit padding boundary.

## Evidence Standards Used

- Evidence types: fresh MCP `idb_list`/health, function lookup, decompilation, full disassembly, compact analysis, xrefs, bytes, vtable integer reads, signatures, caller/callee bodies, current by-* docs, accepted reports, and generated output.
- Direct binary evidence controls range, calls, fields, arithmetic, and ordering. Current accepted docs control stable source-facing types/names where symbols are absent. Naming that is not symbol-proven is labeled inferred.
- Evidence is strong enough for first-draft C++ because every control-flow and arithmetic operation maps directly. Confidence remains below final-source level because original private method/member spellings and the full class declaration are not symbol-proven.

## Evidence Checked

- MCP requests `1011-1013`, `1021-1023`, `1041-1043`, `1101-1105`, `1111-1114`, `1121-1124`, `1131-1134`, and correction requests `1201-1206` covered session health, target/caller lookup, target decompile/disassembly, six xrefs, raw callers, owner/list helpers, vtable slot, bytes, signature, `0x0045b200` prototype/body, and both modeled SetScrollPosition call sites.
- Current by-* pages, executed reports for UID0000Y3/Y4/ZA/ZB, B005's current UID0000Y5 report, geometry UID00015S, and sibling cursor-to-position methods UID0001GX/UID0001H0 were checked.
- Negative checks: no xref at `0x0045adc4`; no incoming xref/function at raw successor `0x0045add0`; no target data/vtable xref; no non-ranking callee; no stable return consumer; no owner action on equal old/new value.
- Historical report-only phase: validators, generated refresh, leases, IDA edits, and lifecycle commands were intentionally skipped. Accepted callback phase: the six scoped validators and final waited generated verification below completed; no IDA edit or lifecycle command was run. No valid MCP `tools/call` failed during evidence collection.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | Evidence-time MCP database `bf5519ae` was healthy and ready during the original and correction passes. | Direct/strong | requests 1131-1132 and 1201-1202 | target / IDA MCP Evidence | Added durable evidence-time facts. | Incorporated; target validator `000000008759` |
| C02 | Function is `[0x45ac10,0x45adc4)`, size `0x1b4`; filename endpoint adc3 is inclusive. | Direct/strong | 1102, 1112, 1105 | target / Address Range | Preserved path and clarified half-open range. | Incorporated; target validator `000000008759` |
| C03 | `0x45adc4-0x45add0` is 12-byte `0xcc` padding; add0 is raw UID0000Y7 start. | Direct/strong | 1105, 1134 | target / range analysis | Preserved padding as separate from target and UID0000Y7. | Incorporated; target validator `000000008759` |
| C04 | Signature is `void DragToPosition(int y, int x)`. | Strong inference | 1112 and six caller sequences | target / formal block | Inserted exact managed body. | Incorporated; target `000000008759`, generated `000000008769` |
| C05 | Exactly six direct calls exist at 459c1c, 459c38, 45aad8, 45aaf4, 45abab, 45abd4. | Direct/strong | 1114, 1134 | target, class, file | Added complete caller inventory. | Incorporated; `000000008759`, `000000008760`, `000000008767` |
| C06 | Coordinates and drag offsets are canonical y/x. | Direct/strong | Y3/Y5 disassembly, UID00015S | target, class, layout | Added exact parameter/field contract. | Incorporated; `000000008759`, `000000008760`, `000000008763` |
| C07 | Two cursor/origin samples and sentinel branches precede leading/trailing bounds copies. | Direct/strong | 1111-1112 | target / behavior and C++ | Preserved literally. | Incorporated; target `000000008759` |
| C08 | Nonzero orientation is horizontal; zero is vertical. | Direct/strong | 1112, UID0001VO | target, layout | Added exact branch contract. | Incorporated; `000000008759`, `000000008763` |
| C09 | Horizontal formula uses x, offset.x, +1, signed range, clamped track travel, signed truncating division. | Direct/strong | 1112 | target / math and C++ | Added exact formula. | Incorporated; `000000008759`, `000000008763` |
| C10 | Vertical formula uses y, offset.y, +1, `(range+1)`, signed division, then caps to range. | Direct/strong | 1112 | target / math and C++ | Added exact formula. | Incorporated; `000000008759`, `000000008763` |
| C11 | No explicit zero-span guard, nearest rounding, or horizontal post-cap exists. | Direct/strong | 1112 | target / negatives | Preserved negative evidence. | Incorporated; `000000008759`, `000000008763` |
| C12 | Equal old/new value exits without owner lookup or side effects. | Direct/strong | 45ad6a-45adb1 | target / behavior and C++ | Added exact early return semantics. | Incorporated; `000000008759`, `000000008760`, `000000008761` |
| C13 | Slot +1c resolves through inherited 5447a0 owner lookup to RankingEventListPane. | Strong | 1101, 1121, owner context | target, vtable | Used `GetOwnerPane` and labeled inferred spelling. | Incorporated; `000000008759`, `000000008765` |
| C14 | UID0000Y6's changed tail exactly matches the guarded body of independently modeled `RankingEventListPane::SetScrollPosition`. | Direct/strong | 1203, 1205, 1206 | target, list class | Normalized expanded fields to method call. | Incorporated; `000000008759`, `000000008761` |
| C15 | The owner method contract is `void SetScrollPosition(int unusedMode, short oldPosition, short newPosition)` and Y6 supplies leading `0`. | Direct/strong | `retn 0x0c`; 45b4c1-45b4c4 and 45b4dc-45b4e6 | target formal block, list class | Used exact three-argument call. | Incorporated; `000000008759`, `000000008761`, generated `000000008769` |
| C16 | Owner +10c store, conditional child +fe sync/invalidation, `UpdateScrollBarState`, and owner invalidation are callee-body evidence, not direct Y6 source accesses. | Direct/strong | 45ad79-45adae equals 45b210-45b245 | target analysis, list class | Preserved semantics through factorized call. | Incorporated; `000000008759`, `000000008761` |
| C17 | Target remains owner/emitter UID0000BO, file UID0000MZ, reconstructable true, Nested 0. | Strong | callers/classes/file/vtables | target metadata | Preserved unchanged. | Incorporated; target validator `000000008759` |
| C18 | Raise target 86/90 to 90/92 and populate formal C++. | Strong | all resolved blockers | target metadata/score | Applied score and exact block. | Incorporated; target `000000008759`, generated `000000008769` |
| C19 | Add narrow class/layout/vtable/file support updates and specified scores without class-level C++. | Strong | current support state | five support docs | Applied destination-specific prose/score plan. | Incorporated; `000000008760`, `000000008761`, `000000008763`, `000000008765`, `000000008767` |
| C20 | Preserve raw-helper/no-function facts, rejected generic ownership, generated-history marker, and no defensive behavior. | Strong | current docs and negative checks | target/support history | Preserved accepted negatives/history and B005-owned broader work. | Incorporated; all six scoped validators and generated `000000008769` |

## Positive Evidence Summary

- `sub_45AC10` is a real modeled function with six local class-family callers and no unrelated route.
- Every field access agrees with UID0001VO and accepted UID0000Y3/Y4/Y5/ZA/ZB.
- The horizontal and vertical branches are fully visible in disassembly, including edge collapse, thumb extent, clamps, signed division, and vertical-only cap.
- The changed path is instruction-sequence equivalent to the guarded body of owner-side `RankingEventListPane::SetScrollPosition` at `0x0045b200`. UID0000Y6 has already proved old/new differ, so an inlined call naturally omits the callee's guard; the source-facing call is `SetScrollPosition(0, oldPosition, newPosition)`.
- The inherited slot +1c owner lookup and owner fields tie the method to `RankingEventListPane`; all target callers remain within `RankingEventScrollPane`.

## IDA MCP Facts

- Function/range: lookup request `1102` reports `sub_45AC10`, size `0x1b4`; full disassembly request `1112` reports 140 instructions and final `retn 8` at `0x45adc1`.
- Bytes: request `1105` shows `5d c2 08 00` at `0x45adc0-0x45adc3`, then twelve `cc` bytes through `0x45adcf`, then raw prologue at `0x45add0`.
- Xrefs: request `1134` reports six code xrefs and no data xrefs to target; zero xrefs at `0x45adc4` and `0x45add0`.
- Binary callees before source refactorization: direct `GetPartRect`, two `GetCursorPosition`, two `GetScreenOffset`, inlined-body `UpdateScrollBarState`, and security cookie; three indirect calls are owner lookup, inlined conditional child invalidation, and inlined owner invalidation.
- Vtable: `0x00610a68`, primary slot `+0x1c`, contains `0x005447a0`; request `1121` shows shared owner/parent lookup behavior through pane association state.
- Owner method: request `1203` reports `0x0045b200` as 26 instructions with arguments `(int, short, short)` and `retn 0x0c`; argument 1 is unread, argument 2 is compared with argument 3, and the changed body matches UID0000Y6 from owner child load through final invalidation.
- Owner call sites: request `1204` shows both `HandleEvent` calls pass three arguments. At `0x45b4c1-0x45b4c4` the leading argument is zero in EAX; at `0x45b4dc-0x45b4e6` the pushes are new, old, zero in machine order, yielding source order `(0, oldPosition, newPosition)`.
- Negative: target range signature request `1133` is not unique, so uniqueness is not used as ownership proof.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0045a990-0x0045ac0f` | UID0000Y5 | raw hover/press/drag callers | true | UID0000BO | 86/90 | preserve |
| `0x0045ac10-0x0045adc3` inclusive | UID0000Y6 | modeled drag-to-position method | true | UID0000BO | 86/90 -> 90/92 | populate C++ |
| `0x0045adc4-0x0045adcf` | ignored/alignment context | 12 bytes `0xcc` | no | parent-only | unchanged | preserve |
| `0x0045add0-0x0045ae2b` | UID0000Y7 | raw reset-state helper | true/raw caveat | UID0000BO | 86/90 | preserve |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00459c1c` | UID0000Y3 direct call | active thumb path, `(localY, localX)` |
| `0x00459c38` | UID0000Y3 direct call | matching non-thumb active-part path |
| `0x0045aad8` | UID0000Y5 raw begin-interaction call | immediate active-thumb update |
| `0x0045aaf4` | UID0000Y5 raw begin-interaction call | active non-thumb update after hit-test |
| `0x0045abab` | UID0000Y5 raw refresh call | repeated active-thumb update |
| `0x0045abd4` | UID0000Y5 raw refresh call | repeated non-thumb update after hit-test |
| `0x0045ad74` | indirect primary slot +1c | get owning `RankingEventListPane` |
| `0x0045ad9c` | indirect child slot +20 | invalidate changed scroll child bounds |
| `0x0045ada1` | direct `0x0045b080` | recompute list scrollbar state |
| `0x0045adae` | indirect owner slot +20 | invalidate owner/list bounds |
| `0x0045b200` | independently modeled owner method | `SetScrollPosition(int, short, short)`, exact factorized source operation |
| `0x0045b4c4`, `0x0045b4e6` | two ordinary owner-method calls | prove leading `0`, old, new call contract |

## Documentation Evidence And IDA Status

- UID0000Y3 and UID0000Y5 already prove all six calls pass y then x and use the same part constants.
- UID0001ZB supplies accepted `GetPartRect`, rectangle types, sentinel convention, orientation, and thumb geometry names.
- UID00015S supplies `Point { y, x }`, conventional `RectBounds { left, top, right, bottom }`, and canonical y-first geometry APIs.
- UID0000BN supplies accepted list methods `UpdateScrollBarState` and `SetScrollPosition`; B005 Destination 6 identifies the factorization, and B003 requests `1203-1206` independently confirm the exact three-argument contract and sequence match.
- Stale/incomplete text is limited to UID0000Y6's blank formal block and deferral language, plus support docs that do not yet record this exact resolved method contract.
- Generated UID0000Y6 Empty Emitter Marker is pre-implementation generated state, not no-code evidence.

## Ranked Ownership Analysis

### 1. RankingEventScrollPane / RankingDialog.cpp

- Evidence for: receiver fields, six class-local callers, sibling methods, class vtables/layout, owner callback, and feature file route all agree.
- Evidence against: exact original private spellings are absent.
- Decision: accepted direct owner/emitter UID0000BO and file route UID0000MZ.

### 2. RankingEventListPane

- Evidence for: receives the changed value, owns child at +108, stores list position at +10c, refreshes and invalidates.
- Evidence against: it is reached only after the scroll-pane owner lookup; target's pre-callback fields and all callers are scroll-pane-local.
- Decision: support/callback owner only, not target owner.

### 3. Generic ScrollBar/ScrollPane module

- Evidence for: arithmetic resembles UID0001GX and UID0001H0 sibling scrollbar helpers.
- Evidence against: target directly touches ranking list state and calls ranking-specific `0x0045b080`; address neighborhood and callers are ranking-local.
- Decision: reject move. Shared behavioral ancestry does not override concrete feature ownership.

## Source Placement

- Recommended placement: private `RankingEventScrollPane` method in UID0000MZ `NexusTK/ui/dialogs/RankingDialog.cpp`.
- This matches current class ownership, generated path, ranking executable island, and adjacent source methods.
- Rejected placements: generic `ScrollBar.cpp`, separate `RankingEventScrollPane.cpp`, direct `RankingEventListPane` ownership, and raw UID0000Y5/Y7 containers.
- Remaining uncertainty is only exact original physical file split/name; it is not strong enough to disturb the established UID0000MZ route.

## Range / Split / Padding / Reclassification Analysis

- Exact modeled range: `[0x0045ac10, 0x0045adc4)`, size `0x1b4`; project filename endpoint `0x0045adc3` is the inclusive final byte.
- Predecessor UID0000Y5 final raw return ends at `0x0045ac0f`; target starts immediately at `0x0045ac10`. No predecessor padding is absorbed.
- Successor padding is exactly `0x0045adc4-0x0045add0`, twelve `0xcc` bytes, with zero xrefs at the first padding byte.
- UID0000Y7 begins raw code at `0x0045add0`, has no IDA function or incoming xref, and remains a separate raw helper page.
- No split, merge, rename, reclassification, child registration, or padding ownership change is recommended.

## Negative Evidence Summary

- No target data/vtable entry exists because this is a nonvirtual private helper.
- No external caller, packet route, render-helper route, pointer table, or alternate class receiver was found.
- No stable return contract exists; EAX differs by path and is ignored.
- No source evidence supports x-first arguments, unsigned range semantics, nearest rounding, denominator guard, or a generic owner callback.
- No evidence supports exposing or directly accessing `RankingEventListPane` private fields from Y6 source. The observed owner/child dereferences are the compiler-expanded `SetScrollPosition` body and must be represented by that method call.
- No evidence supports moving adjacent padding or UID0000Y7 into the modeled target.

## IDA Rename / Type / Comment Recommendations

- Source-facing method/type: `void RankingEventScrollPane::DragToPosition(int y, int x)`.
- Fields: `short m_scrollPosition`, `short m_scrollRange`, `unsigned char m_orientation`, `Point m_thumbDragOffset`, inherited `RectBounds m_bounds`.
- Owner API: `void RankingEventListPane::SetScrollPosition(int unusedMode, short oldPosition, short newPosition)`; Y6 calls it with `0`, `oldPosition`, and `newPosition`. Owner `m_scrollPane +0x108`, `m_scrollPosition +0x10c`, `UpdateScrollBarState`, and invalidations document the inlined callee implementation only.
- Helpers: `GetPartRect`, `GetOwnerPane`, `RankingEventListPane::SetScrollPosition`, `g_pEventMan->GetCursorPosition`, and `GetScreenOffset`.
- Locals: `thumbRect`, `leadingRect`, `trailingRect`, `thumbStart`, `maxThumbStart`, `trackStart`, `trackSpan`, `oldPosition`, `newPosition`.
- All names except already established public/shared helper spellings are inferred source-facing names, not original-symbol proof.
- IDA rename/type/comment edits are not requested and were prohibited in this phase.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. All method-level range, type, arithmetic, caller, and side-effect blockers are resolved.
- Recommended code: exact target managed block insertion follows.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void RankingEventScrollPane::DragToPosition(int y, int x)
{
    const short oldPosition = m_scrollPosition;
    RectBounds thumbRect;
    RectBounds leadingRect;
    RectBounds trailingRect;
    Point cursor;
    Point origin;

    GetPartRect(kRankingScrollPartThumb, &thumbRect);

    g_pEventMan->GetCursorPosition(&cursor);
    GetScreenOffset(&origin);
    if (origin.y != -1000 || origin.x != -1000) {
        leadingRect = m_bounds;
        if (m_orientation != 0) {
            leadingRect.right = leadingRect.left;
        } else {
            leadingRect.bottom = leadingRect.top;
        }
    }

    g_pEventMan->GetCursorPosition(&cursor);
    GetScreenOffset(&origin);
    if (origin.y != -1000 || origin.x != -1000) {
        trailingRect = m_bounds;
        if (m_orientation != 0) {
            trailingRect.left = trailingRect.right;
        } else {
            trailingRect.top = trailingRect.bottom;
        }
    }

    short newPosition;
    if (m_orientation != 0) {
        int thumbStart = x - m_thumbDragOffset.x + 1;
        const int trackStart = leadingRect.right;
        if (thumbStart < trackStart) {
            thumbStart = trackStart;
        }

        const int maxThumbStart = trailingRect.left +
            thumbRect.left - thumbRect.right;
        if (thumbStart > maxThumbStart) {
            thumbStart = maxThumbStart;
        }

        const int trackSpan = trailingRect.left + thumbRect.left -
            thumbRect.right - leadingRect.right;
        newPosition = static_cast<short>(
            (m_scrollRange * (thumbStart - leadingRect.right)) /
            trackSpan);
    } else {
        int thumbStart = y - m_thumbDragOffset.y + 1;
        const int trackStart = leadingRect.bottom;
        if (thumbStart < trackStart) {
            thumbStart = trackStart;
        }

        const int maxThumbStart = trailingRect.top +
            thumbRect.top - thumbRect.bottom;
        if (thumbStart > maxThumbStart) {
            thumbStart = maxThumbStart;
        }

        const int trackSpan = trailingRect.top + thumbRect.top -
            thumbRect.bottom - leadingRect.bottom;
        newPosition = static_cast<short>(
            ((m_scrollRange + 1) *
             (thumbStart - leadingRect.bottom)) /
            trackSpan);

        if (newPosition > m_scrollRange) {
            newPosition = m_scrollRange;
        }
    }

    if (oldPosition == newPosition) {
        return;
    }

    RankingEventListPane *owner =
        static_cast<RankingEventListPane *>(GetOwnerPane());
    owner->SetScrollPosition(0, oldPosition, newPosition);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

- Exact behavior preservation: the block retains two cursor/origin samples, sentinel-controlled uninitialized local behavior, orientation asymmetry, `+1`, exact clamps, signed truncating divisions, vertical-only cap, no-change early return, and all owner/child synchronization through the independently verified `SetScrollPosition` callee semantics.
- Plausible original source shape: the code follows the accepted UID0001GX sibling shape and UID0000Y3/Y4/ZB style, while factoring the compiler-expanded owner tail back into its independently modeled source method. This avoids illegal/private direct member access and matches two ordinary callers.
- Inferred names/types are listed in the prior section. No decompiler names, SIMD intrinsics, security-cookie operations, or vtable lowering appear in source.
- Class-level UID0000BO/UID0000BN C++ remains blank under its existing broader class-surface proof. That does not block this method-level managed body, consistent with already emitted UID0000Y3/Y4/ZA/ZB method bodies.

## Final Recommendation

- C01-C20 are implemented exactly.
- Target owner/emitter UID0000BO, file UID0000MZ, reconstructable true, blank optional position, and `Nested:0` are preserved.
- Only the target formal C++ block was populated; class/layout/vtable/file support formal C++ remains unchanged.
- UID0000Y5, UID0000Y7, UID0000Y3, UID0000Y4, UID0001ZA, and UID0001ZB behavior/code remains unchanged. B005-owned broader class/split work was preserved.
- Leave generated, coverage, tracker, validator state, report execution, and lifecycle state to external supervisor/validator workflows.

## Recommended Target Doc Changes

- Target path: `by-memory/0x0045ac10-0x0045adc3.RankingEventScrollPaneDragToPosition.md`.
- Raised `86/90 -> 90/92`; preserved UID, owner, emitter, reconstructable, optional position, and Nested metadata.
- Inserted the exact managed block above.
- Added exact range/padding, six callers, signature/return rationale, coordinate/field table, formulas, signed division/rounding, normalized `SetScrollPosition(0, old, new)` owner call, no-change behavior, MCP facts, score rationale, rejected alternatives, and source placement.
- Historicalized the old "Do not emit final C++ yet" blocker as superseded by evidence-time MCP, accepted y/x geometry, sibling source, and owner-method evidence.

## Recommended Support Doc Changes

- `by-class/RankingEventScrollPane.md`: raised `87/89 -> 88/90`; added exact `void DragToPosition(int y, int x)`, formulas, fields, six callers, `GetOwnerPane()->SetScrollPosition(0, old, new)` factorization, no-change behavior, and source-ready target status. Class-level C++ and owner/emitter remain unchanged; B005 retains ownership of broader class-block/split work. Validator `000000008760`.
- `by-class/RankingEventListPane.md`: kept `87/89`, metadata, and formal block unchanged; documented exact `void SetScrollPosition(int unusedMode, short oldPosition, short newPosition)`, both ordinary leading-zero calls, and UID0000Y6's inlined-equivalent source call. Render exclusions are preserved. Validator `000000008761`.
- `by-type/by-struct/RankingEventScrollPaneLayout.md`: raised `85/89 -> 87/91`; added signed-short types, exact orientation-specific formulas, `Point` component use, `+1`, clamping/division/cap behavior, and owner/list distinction. Formal C++ remains blank. Validator `000000008763`.
- `by-type/by-vtable/RankingEventScrollPaneVtables.md`: kept `86/90`; added that target is nonvirtual, uses inherited primary slot `+0x1c` (`0x00610a68 -> 0x005447a0`) for owner retrieval, and is reached only by direct class-local calls. Route/score remain unchanged. Validator `000000008765`.
- `by-file/RankingDialog.md`: kept `88/91`; replaced UID0000Y6 blank-target wording with implemented signature/owner/file evidence and preserved existing pollution exclusions/source route. Validator `000000008767`.
- UID0000Y3 and UID0000Y5 already contain exact y-first call facts and require no content change unless link text is mechanically refreshed. UID0000Y4, UID0001ZA, UID0001ZB, and UID00015S remain read-only support.

## Score And Metadata Recommendation

- Target implemented: `86/90 -> 90/92`.
- Completion rises because exact factorized formal C++, all callers, boundaries/padding, arithmetic, field/type map, owner method contract, synchronization semantics, negatives, and source placement are complete.
- Confidence rises because fresh MCP, accepted local support, generated calls, and sibling implementations agree. It remains `92`, not final/high-90s, because original private symbol names and full class declarations are not recovered.
- Support score changes are limited to newly resolved method/member/layout evidence as listed above. File and vtable routes are unchanged.
- No target metadata changes beyond score and C++ content.

Score-improvement attempts:

- Return blocker: exhausted caller and epilogue evidence; resolved to `void`.
- Coordinate blocker: exhausted all six callers plus Point/geometry support; resolved to y/x.
- Type blocker: checked direct sign extension and accepted layout; resolved to signed short fields/int arithmetic.
- Owner blocker: checked vtable slot, shared owner lookup, owner constructor/fields, and owner methods; resolved.
- Factorization/private-access blocker: independently disassembled `0x0045b200`, both modeled call sites, and UID0000Y6's changed tail; resolved to `owner->SetScrollPosition(0, oldPosition, newPosition)`.
- Math blocker: full disassembly resolves every clamp/division/cap operation.
- Name blocker: accepted family names and period style support defensible first-draft names; only original-symbol proof remains unavailable and caps confidence rather than C++ eligibility.
- Placement blocker: feature-local callgraph and owner route preserve UID0000MZ.

## Open Questions With Attempted Resolution

- Exact original spelling of `DragToPosition`, `GetOwnerPane`, parameter names, and locals is not symbol-proven. Accepted sibling/local docs and generated call sites make the recommended spellings the strongest defensible source-facing choice.
- Owner callback arity/factorization is resolved, not open: `0x0045b200` has one unused integer plus old/new short arguments, ends `retn 0x0c`, and both modeled callers provide leading `0`. UID0000Y6's expanded changed tail exactly matches its guarded body, so direct owner field access is rejected in favor of `SetScrollPosition(0, oldPosition, newPosition)`.
- Exact original full class declaration remains unresolved because UID0000BO/BN include raw constructor and multiple inherited interface surfaces. This does not block the exact method body and should not be solved by inventing unrelated overrides in this report.
- Whether the original project used `short`, `signed short`, or a typedef is not recoverable from the binary. `short` matches current accepted docs and exact 16-bit signed behavior.
- No unresolved method-level question requires blank C++, lower ownership, or a split. Stronger resolution would require original symbols/source, which is unavailable.

## Follow-Up Actions

- Implementation and required scoped/generated verification are complete. B003 performed no execute, lifecycle, move, or archive command.
- Report validation/execution, count/path state, move/archive state, and any later generated state are external supervisor/validator-owned; this artifact neither asserts nor directs those states.
- No B003 implementation item remains.

## Confidence

- Recommendation confidence: `92/100`.
- Score confidence: strong; `90/92` matches neighboring source-ready ranking methods and the completeness of direct evidence.
- Remaining uncertainty: original private spellings/full class surface only; no behavioral uncertainty remains in the proposed body.

## Validator Results

| Command ID | Timestamp | Scope / command | Exit | Result |
| --- | --- | --- | --- | --- |
| `000000008759` | `2026-07-12T20:42:26-04:00` | `python tools\validator.py --mode file --file by-memory\0x0045ac10-0x0045adc3.RankingEventScrollPaneDragToPosition.md --apply` | `0` | `ok:1`; `90/92`; managed block registered; generated refresh deferred |
| `000000008760` | `2026-07-12T20:43:18-04:00` | `python tools\validator.py --mode file --file by-class\RankingEventScrollPane.md --apply` | `0` | `ok:1`; `88/90`; generated refresh deferred |
| `000000008761` | `2026-07-12T20:43:42-04:00` | `python tools\validator.py --mode file --file by-class\RankingEventListPane.md --apply` | `0` | `ok:1`; `87/89`; generated refresh deferred |
| `000000008763` | `2026-07-12T20:44:29-04:00` | `python tools\validator.py --mode file --file by-type\by-struct\RankingEventScrollPaneLayout.md --apply` | `0` | `ok:1`; `87/91`; generated refresh deferred |
| `000000008765` | `2026-07-12T20:44:57-04:00` | `python tools\validator.py --mode file --file by-type\by-vtable\RankingEventScrollPaneVtables.md --apply` | `0` | `ok:1`; `86/90`; generated refresh deferred |
| `000000008767` | `2026-07-12T20:45:46-04:00` | `python tools\validator.py --mode file --file by-file\RankingDialog.md --apply` | `0` | `ok:1`; `88/91`; generated refresh deferred |
| `000000008769` | `2026-07-12T20:46:07-04:00` | `python tools\validator.py --mode autogen --apply --wait-generated` | `0` | generated refresh completed |

- Each edited by-* file received exactly one scoped validator while leased, and its lease was released immediately afterward.
- Final `auto-generated/NexusTK/ui/dialogs/RankingDialog.cpp` verification: UID0000Y6 count `1`; exact method signature count `1`; factorized call count `1`; UID0000Y6 Empty Emitter Marker count `0`. The UID comment is at generated line 622, method signature at line 623, and `owner->SetScrollPosition(0, oldPosition, newPosition)` at line 706.
- The final autogen pass reported existing broad-project diagnostics (`16` fallback inserts, `81` missing markers, `220` emitters without code); none is a UID0000Y6 scoped validation failure.

## Changed Files

- Historical report artifact created and callback-updated: `tools/leaser/Agents/Agent-B003/research/0000Y6-RankingEventScrollPaneDragToPosition-source-quality.md`.
- Modified: `by-memory/0x0045ac10-0x0045adc3.RankingEventScrollPaneDragToPosition.md`.
- Modified: `by-class/RankingEventScrollPane.md`.
- Modified: `by-class/RankingEventListPane.md`.
- Modified: `by-type/by-struct/RankingEventScrollPaneLayout.md`.
- Modified: `by-type/by-vtable/RankingEventScrollPaneVtables.md`.
- Modified: `by-file/RankingDialog.md`.
- Renamed: none.
- New by-* pages: none.
- Validator-owned generated refresh completed; B003 did not manually edit generated, coverage, tracker, supervisor, or validator-state files.
- B003 report execution/lifecycle/move/archive commands: none.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation is recorded.
- [x] Target/support docs to update are enumerated destination by destination.
- [x] Current target state and actual evidence checked are recorded.
- [x] Claim And Incorporation Ledger contains C01-C20 with destinations and verification state.
- [x] Metadata/score changes are specified.
- [x] Score-limiting blockers were researched to method-level resolution; residual original-symbol uncertainty is an evidence-backed confidence cap.
- [x] Owner/emitter/reconstructable state is explicitly preserved.
- [x] Split/rename/new-child work is confirmed not applicable; exact padding is preserved.
- [x] Source placement, range, padding, and nonvirtual vtable relationship are resolved.
- [x] Exact managed first-draft target C++ is supplied.
- [x] Third-party import directive is confirmed not applicable.
- [x] Exact target/support facts are supplied at report-level detail.
- [x] Historical blank-C++ assumption, rejected alternatives, raw-helper caveats, and negative evidence are preserved.
- [x] Wave2/Wave3 artifacts are rejected as stale authority.
- [x] Open questions are closed or documented as original-source-only confidence caps.
- [x] Implementation-phase validator scope is identified: one scoped validator per edited by-* file and final waited generated verification, only after supervisor authorization.
- [x] Generated refresh is external validator-owned; no manual generated/tracker/coverage edit is recommended.

Implementation callback pass:

- [x] Report SHA `197763CFB8A279D81C02392E482DF0DFD10DE52B3328D9F473A733EA01C7258C` accepted by supervisor for implementation.
- [x] C01-C20 incorporated claim by claim.
- [x] Target `86/90 -> 90/92`; owner/emitter/reconstructable/position/nesting preserved; exact managed block applied.
- [x] Support scores/evidence applied exactly; B005-owned broader class/split work and unrelated history preserved.
- [x] Exactly one scoped validator run per changed by-* file with command IDs/timestamps/exits recorded; each short lease released immediately.
- [x] Final waited generated refresh and exact `RankingDialog.cpp` UID0000Y6 body/duplicate/marker checks recorded.
- [x] Ledger, validator results, changed files, and checklist updated with implementation proof.
- [x] No accepted item remains unapplied; no B003 implementation blocker remains.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000008789","destination_path":"executed-b-agent-research/B003/0000Y6-RankingEventScrollPaneDragToPosition-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0000Y6-RankingEventScrollPaneDragToPosition-source-quality.md","timestamp":"2026-07-12T20:56:23-04:00","uid":"0000Y6"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
