** TARGET-REPORT-UID:00031G **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID00031G IMEPaneFocusCaretAnchorHelper Source-Quality Research


## Finalized Report / Current Recommendation

- Current applied disposition: exact range `[0x004e8110,0x004e8192)` is documented and emitted as the retained source-authored `IMEPane::UpdateFocusCaretAnchor` method, not as a rare no-code helper. Destination 1 is installed, the method is declared on `IMEPane`, and UID00018A now carries the source-level helper call whose operation the shipped optimizer inlined.
- Final metadata: UID00031G retains its exact range, direct class owner/emitter UID00006H, `RECONSTRUCTABLE:TRUE`, blank optional position, and `Nested:0`; its score is `91/93`. UID00006H and UID00018A are `90/92`, UID000189 is `88/91`, UID0000K5 is `91/90`, and the accepted UID0000EO/UID0000ON scores remain `91/93` and `91/90`.
- Completed callback: Destinations 1-7 and C01-C30 are reconciled. The complete IME class union is preserved, the TextEditPane helper declarations are present, UID00018A uses the correct list-slot/source-call route and inherited pane-helper spelling, and the prior no-code conclusion remains only as labeled historical negative evidence.
- Confidence: very strong for range, receiver, fields, control flow, behavior, source family, and compiler-inline relationship; strong rather than final for exact original private-method/helper spellings because no symbols survive and no direct machine-code call targets the retained out-of-line body.
- Report status: B002 implementation, scoped validation, generated verification, and lease release are complete. Independent Gate 2 review and every current/future report path, manual-coverage, execution, move, archive, and lifecycle state remain external supervisor/validator-owned facts and are not asserted.

## Supporting Research

- The evidence pass was performed on 2026-07-14 after the supervisor replaced the expired worker with database `49ac345c`. Fresh `idb_list` identified NexusTK as the one adopted active database; `server_health` reported `ok` with auto-analysis, Hex-Rays, and string cache ready; bounded bytes at `0x004e8110` matched the expected prologue. These are evidence-collection-time observations, not an assertion that the session remains available later.
- Exact target bytes, disassembly, internal branch, endpoint behavior, neighboring functions, padding, function-model state, direct xrefs, byte signatures, raw pointer/immediate routes, and rel32 routes were rechecked live. Supplemental read-only PE scanning used the same NexusTK executable only to exhaust raw routes; conclusions do not rely on an offline substitute.
- Current ordinary documentation, generated `NexusTK/input/IMEPanes.cpp`, manual coverage rows, matching central executed B reports, active retained-agent report roots, legacy research roots, and archive roots were compared read-only.
- Historical B008 and B003 reports correctly recovered behavior but treated absence of a modeled function/direct xref as proof against source emission. Fresh analysis rejects that inference because the target has a complete source-method body and UID00018A contains the same operation as an optimizer-inlined copy. Existing accepted UID0004CE source already establishes this compiler/source-shape pattern: source-level constructor calls are emitted as inlined constructor-shaped machine code.
- No Wave2/Wave3 artifact was used as authority. The aggregate's stale `Wave3` taxonomy was historicalized during the callback without deleting its provenance.

## Target

- Target UID: `00031G`.
- Target path: `by-memory/0x004e8110-0x004e8192.IMEPaneFocusCaretAnchorHelper.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md` -> `by-memory` -> `Not-Covered Files - Reconstructable`.
- Evidence-time supervisor classification: unique report-only source-quality assignment; no exact executed target report and no active B001-B005 assignment collision was found.
- Current applied scores and parent state: `91/93`, canonical owner/emitter UID00006H, reconstructable true, blank optional position, `Nested:0`; parent class UID00006H emits through by-file UID0000K5.
- Exact binary range: `[0x004e8110,0x004e8192)`, 130 bytes.

## Current Target State

- Evidence-time / pre-callback metadata was internally inconsistent: headers said `86/90`, the Score Rationale said `85/89`, and aggregate/manual coverage rows retained older scores. The prior formal block emitted a rare no-code comment despite true/emitting metadata and a complete handwritten method body.
- Current UID00031G metadata and source are consistent: `91/93`, owner/emitter UID00006H, reconstructable true, blank optional position, `Nested:0`, exact Destination 1, and complete exact-range/evidence/history detail. Scoped validator `000000012594` applied this state.
- Current UID00018A is `90/92` and calls `UpdateFocusCaretAnchor`, then reads the two cached fields. Its accepted popup behavior remains intact, while the stale `List::GetAt`/direct-slot cast and `GetScreenOrigin` source spellings survive only as history. Scoped validator `000000012596` applied this state.
- Current UID00006H is `90/92` with the private target declaration in its preserved complete class union; current UID0000EO remains `91/93` with the Point forward declaration and both TextEditPane caret-helper declarations. Scoped validators `000000012595` and `000000012597` applied these states.
- Current UID000189 is `88/91` with its exact non-duplicating aggregate block retained and source-bearing target inventory corrected. UID0000K5 is `91/90` and UID0000ON remains `91/90`; both by-file roots contain prose only and no reconstruction metadata. Scoped validators `000000012598`, `000000012599`, and `000000012600` applied these states.
- Evidence-time generated snapshot at 2026-07-15T00:05:26-04:00, command `000000012582`, SHA256 `8B180EF4F8AAED8823D9CCD8C5157B39D2E560CB661C626BAE0F9D083BA150F4`, had one marker, zero target definitions, and one stale no-code comment. This is preserved as the pre-callback baseline.
- Final B002 callback verification readback at waited command `000000012621`, 2026-07-15T00:34:39-04:00, was `auto-generated/NexusTK/input/IMEPanes.cpp`, SHA256 `3B3FBFC29D5D74E89C03CE38D249045FC8764643B7286FC5F15FA502E9431DEA`, 21,555 bytes, 664 lines. At that verification point it had one complete IMEPane class, one target declaration, one target definition, one UID00018A source call, one target marker, zero target no-code/empty markers, and no duplicate class/helper/global/ABI source. This time-scoped callback refresh superseded the successful command-12601 snapshot after a concurrent generated refresh changed only generated metadata; later generated state is external and not asserted.
- B002 callback work is complete and every B002 lease is released. Independent validation, manual coverage, execution, movement, archive, and lifecycle state are external and not asserted.

## Executive Recommendation

- Keep the exact UID/range and direct IMEPane class route. This is neither a new child nor a split/merge candidate.
- Emit one private source method on IMEPane. Let UID00018A call it at source level; the shipped compiler's inlining explains why the executable has an inline copy at `0x004e74b0-0x004e751d` without a direct call to `0x004e8110`.
- Preserve the out-of-line body because it is a complete independently compiled method island with a normal receiver/prologue/epilogue, not an arbitrary instruction fragment.
- Do not emit raw vtable, thunk, EH, allocation, cleanup, or ABI source. None occurs in the target.
- Add compile-visible helper declarations to TextEditPane and retain accepted `Point`, `List`, and inherited Pane support rather than creating duplicate types or helpers.
- The accepted implementation is applied without unresolved source-quality blockers; independent Gate 2 review remains external.

## Supervisor Active Recheck

- The report-only pass was accepted at exact SHA256 `F740956B587C288DA32A2FED6489A6695E33B8DAB3BBBCEC6854EAFBBFCDFA08`; the subsequent bounded callback authorized Destinations 1-7 and C01-C30.
- Split repair is not required. The existing exact target range and parent relationship are stable.
- No child creation is required. The only source-bearing item in the assigned exact range is the one retained IMEPane method represented by UID00031G.
- All in-scope blockers are implemented and validated; none is deferred to later investigation.

## Inference Research Guidance Check

- Binary facts are separated from source-shape inference: exact bytes, registers, fields, branches, helper addresses, and absence of xrefs are facts; the private method name and source-level call/inlining relationship are evidence-backed source reconstruction.
- Existing documentation assumptions were treated as uncertain. In particular, no modeled IDA function and no direct xref were not accepted as no-code proof, `GetAt` was not accepted over the current List surface, and `GetScreenOrigin` was not accepted over the wider current `GetScreenOffset` evidence.
- `by-structure.md` rules support a source-bearing method child under a reconstructable class emitter and prohibit replacing source with a report-only proof comment when complete behavior can be reconstructed.
- Historical Wave2/Wave3 labels were ignored as stale workflow authority. The current target/class/file structure and live evidence control this recommendation.

## Heuristic / Inference Reanalysis And Validation

1. **Raw-helper liveness:** IDA has no function object at `0x004e8110` and no inbound modeled xref. That is a tool/reachability observation, not proof of compiler-only output. The bytes have an ordinary thiscall method frame, full two-branch semantics, independent return sites, stable padding boundaries, and exact family placement. Best disposition: retained source method whose known source call was optimized inline.
2. **Source-operation identity:** UID00018A contains the same focus-list lookup, three helper calls, point sums, and anchor writes. Its global IMEPane receiver and different register allocation prove an inline semantic duplicate, not byte identity. Existing UID0004CE accepted source uses ordinary constructor calls despite inlined constructor-shaped binary sequences, providing project/compiler precedent.
3. **Receiver and fields:** ECX becomes EDI; reads at `+0x104/+0x110` and writes at `+0x118/+0x11c` match the complete IMEPane layout. Horizontal sum writes `+0x11c` and vertical sum writes `+0x118`; the empty branch writes both zero.
4. **List semantics:** virtual slot `+0x10` is current `List::GetElementAt(int)`, returning an element-storage address. The subsequent `mov esi,[eax]` requires a pointer-slot dereference. A direct cast of the returned slot to TextEditPane is rejected.
5. **TextEdit helper identity:** `0x0058f050` writes two signed-short caret/selection values from TextEditPane state and returns with two arguments. `0x0058f740` consumes the first short and writes a local Point. Accepted descriptive names remain `GetCaretRange` and `GetCaretLocalPoint`; exact original spelling is not symbol-proven.
6. **Pane geometry identity:** `0x005447c0` reads inherited Pane owner/layer state at `+0xa8`, delegates to Layer screen-offset logic when present, and otherwise writes `(0,0)`. Current broad source evidence uses `Pane::GetScreenOffset`; historical `GetScreenOrigin` is superseded.
7. **Control flow:** count `<= 0`, including a negative value, clears both anchors. Positive count subtracts one and performs the lookup. There are no null, bounds, helper-failure, or sentinel checks and no fallback after helper calls.
8. **Local types:** the first helper writes two shorts; the next two helpers write current `Point { int y; int x; }` values. The target adds pane and caret X separately from Y. No rectangle temporary exists despite the old generic description.
9. **Source order:** predecessor SetFocusPane ends at `0x004e810b`, five `0xcc` bytes precede the target, fourteen `0xcc` bytes follow it, and IsIMESupported begins at `0x004e81a0`. The stable order is SetFocusPane, UpdateFocusCaretAnchor, IsIMESupported.
10. **Compiler/source exclusions:** no exception region, cookie, vptr store, allocator, free, destructor, thunk, adjustor, scalar-delete flag, or ABI table occurs. All 130 bytes derive from ordinary source statements plus routine prologue/epilogue and virtual dispatch.
11. **Rejected no-code alternative:** a comment cannot regenerate the target bytes and contradicts true/emitting metadata. Absence of direct xrefs does not meet the rare proof standard because a complete source method and an optimizer-inline source route are available.
12. **Rejected merge alternative:** leaving the duplicated UID00018A statements as source would represent behavior but would not preserve the most plausible original operation or retained out-of-line method. It also perpetuates a wrong list access shape.
13. **Rejected global/free-helper alternative:** all target fields are receiver-relative IMEPane state and the method island uses ECX as the complete object. A free helper taking IMEPane is less plausible than a private method.
14. **Name confidence cap:** `UpdateFocusCaretAnchor` describes the exact persistent side effect and matches project style, but no PDB string proves the spelling. This caps confidence at 93 rather than 94+.

## Evidence Standards Used

- Primary evidence: live IDA MCP database `49ac345c`, bounded function lookup, exact bytes, disassembly, xrefs, byte searches, helper decompilation/disassembly, and adjacent function/range checks.
- Secondary evidence: current by-memory/by-class/by-file/by-type docs, generated C++, manual coverage rows, central executed reports, and the read-only exported Ghidra record for the same bytes.
- Supplemental negative evidence: read-only PE scan for exact virtual-address bytes, RVA bytes, and executable-section E8/E9 rel32 destinations.
- Evidence ladder: exact machine behavior and stable layout outrank stale report conclusions; current accepted declarations outrank historical aliases; source-shape inference is accepted when it explains both the retained body and inline copy without inventing behavior.
- Tool limits: IDA does not model the target as a function and cannot return function blocks/callees for it. Two broad instruction-query attempts timed out, so their partial/non-results were discarded; later bounded calls succeeded and the session remained healthy. These limits cap naming/reachability confidence but do not block reconstruction.

## Evidence Checked

- MCP initialization/session: fresh streamable transport session `22bd833d-91ce-4933-b91e-0081246338a7`, schema refresh through `tools/list`, then `idb_list` and `server_health`; database `49ac345c`; evidence calls 301-390. Health call 302 reported `ok`; target/helper lookups and bounded bytes/disassembly succeeded afterward.
- Exact target: bytes and disassembly for `[0x004e8110,0x004e8192)`; SHA256 `B9CB8897FC3A0E7C2AE761E8E83F6751E4741A731D33E2A22EA67317DF264AA8`.
- Boundaries: predecessor padding `[0x004e810b,0x004e8110)` is five `0xcc` bytes, SHA256 `992CF51486F901AA1AA7D1F63E18C150C9156166E08E0B9E59CC3FAF98177329`; successor padding `[0x004e8192,0x004e81a0)` is fourteen `0xcc` bytes, SHA256 `1E875C76536C8496BED8C8760B539327F24ACFFBCF0A4B941877B4BFB4C44356`.
- Adjacent functions: SetFocusPane at `0x004e80a0`, size `0x6b`, ends `0x004e810b`; IsIMESupported at `0x004e81a0`, size `0x5`.
- Function model: lookups at start, last byte, and exclusive end found no target function; helper lookups at `0x0058f050`, `0x0058f740`, and `0x005447c0` succeeded.
- Routes: zero external xrefs to target start/end; only internal conditional branch `0x004e8121 -> 0x004e817d`; zero exact VA/RVA byte hits; zero raw E8/E9 rel32 destinations; zero absolute-immediate route found. A 19-byte target prologue signature occurred once at `0x004e8110`, and the helper-call-pair signature occurred once at `0x004e8141`.
- Supplemental raw-route input: NexusTK PE SHA256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`, image base `0x00400000`, target RVA `0x000e8110`; full raw-file VA/RVA scans and executable `.text` rel32 decoding each found zero target routes.
- Inline duplicate: live decompile/disassembly of UID00018A around `0x004e74b0-0x004e751d` showed the same field reads, last-slot dereference, helper sequence, point additions, writes, and clear behavior.
- Helpers: `0x0058f050` exact ten-instruction/two-output short getter; `0x0058f740` caret-index-to-local-Point operation; `0x005447c0` Pane/Layer screen-offset operation with zero fallback.
- Current docs opened: UID00031G, UID000189, UID00006H, UID0000K5, UID00018A, UID0004CC, UID0004CD, UID0000EO, UID0000ON, current Point/RectGeometry, List, Pane/Layer geometry, g_pIMEPane, and generated IMEPanes.cpp.
- Historical exported evidence: `resources/exported_data/functions/0x004e8110.json` models the same bytes as a fastcall-like function and recovers the same behavior, but its stale FittingRoom-like local type is rejected. It is corroboration only, not current authority.
- Exact old-report terms: `TARGET-REPORT-UID:00031G`, `UID00031G`, `UID:00031G`, `0x004e8110`, `0x004e8192`, `IMEPaneFocusCaretAnchorHelper`, `UpdateFocusCaretAnchor`, `focusCaretAnchor`, `GetCaretRange`, `GetCaretLocalPoint`, `GetScreenOrigin`, `GetScreenOffset`, `IMEPane`, and `IMEPanes`.
- Central executed root searched: `executed-b-agent-research`. Relevant artifacts opened: `B008/0000K5-IMEPanes-empty-emitter-family-source-quality.md` (historical no-code conclusion, SHA256 `0CA4DCCEAEC01D430CFD46BECEDF073BA5671161130A18370AD52301E0DE4A6A`); `B003/00018A-ime-composition-set-composition-string-source-quality.md` (inline sequence/helper names, SHA256 `62D20F35F656769032B302F451856CAE5AABB9EDCC5332970E987AC3E5E2B7D7`); `B006/0004CC-IMEPaneSetFocusPane-by-memory-source-quality.md` (predecessor range/List API, SHA256 `44D9D79ACD9C7143F55465428B653C13623DF4DBBB4ED128C14169CD19B143EC`); `B007/0004CD-IMEPaneIsIMESupported-by-memory-source-quality.md` (successor range/padding, SHA256 `191D1F9F7B1D6CAC8ABE898BD68580534FE075DDCBF091DC4F7627ED9CA9D104`); `B008/0004CA-IMEPaneConstructor-by-memory-source-quality.md` (class fields/lifecycle, SHA256 `D3A231727CD318E4B4347A01C42D80E7CA00A093EF361AB0375FD2F0CB47919C`); `B011/0004CB-IMEPaneOrdinaryDestructor-by-memory-source-quality.md` (field/member teardown, SHA256 `16CB433444E8A345F4D77EB63EF0BE5F19DE5C9CF257B551DCC70063A88A5757`); and `B009/0004C3-IMECompositionPaneOnMouseEvent-source-quality.md` (anchor field order, SHA256 `BDF6B07483D3D947693FDBC89E5E463DAC891E68204DAB242500AB45AE6D01EB`). No exact UID00031G target report exists.
- Legacy roots searched: `tools/leaser/Agents/Older-Research` had no match. `tools/leaser/Agents/SpecialReports` had only three UID0004CC benchmark reports, used only as adjacent support and not target authority.
- Archived roots searched: `archived/b-agent-reports-20260623` and `archived/duplicate-loose-b-agent-reports` had no match.
- Active roots searched: `tools/leaser/Agents/Agent-B001/research` through `Agent-B005/research`; no target/family match and no collision was found. The assigned B002 report did not yet exist during the search.
- Manual coverage read-only rows inspected: by-memory lines 1819, 1820, 1823; by-class lines 258 and 549; by-file lines 122 and 284.
- Report-only-pass exclusions: no IDA mutation, validator, report lifecycle command, broad callgraph, or generated refresh occurred before Gate 1. Authorized callback validators and the generated refresh are recorded separately below; IDA and lifecycle state remained untouched.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | UID00031G remains exact range `[0x004e8110,0x004e8192)`. | 100 | Exact bytes, stable padding, adjacent starts. | Destination 1 target range/status/evidence; validator `000000012594` | incorporate | applied |
| C02 | Target bytes SHA256 is `B9CB8897FC3A0E7C2AE761E8E83F6751E4741A731D33E2A22EA67317DF264AA8`. | 100 | Bounded byte read/hash. | Destination 1 Evidence Notes; validator `000000012594` | incorporate | applied |
| C03 | Five leading and fourteen trailing `0xcc` bytes are padding outside the target. | 100 | Exact bounded bytes/hashes. | Destinations 1 and 5 range inventories; validators `000000012594`/`000000012598` | incorporate | applied |
| C04 | No evidence-time IDA function object existed at target start, but the bytes form one complete ordinary thiscall method. | 98 | Lookup plus exact disassembly/prologue/returns. | Destinations 1, 2, 5, 6 history; validators `000000012594`/`000000012595`/`000000012598`/`000000012599` | historicalize | applied |
| C05 | No direct modeled xref, raw VA/RVA pointer, absolute route, or E8/E9 rel32 route reaches the target. | 100 | MCP xrefs/search plus full executable-section scan. | Destinations 1, 2, 5, 6 negative evidence; validators `000000012594`/`000000012595`/`000000012598`/`000000012599` | incorporate | applied |
| C06 | Absence of a direct machine route does not justify no-code because UID00018A contains the source call's optimizer-inline expansion. | 95 | Exact semantic/instruction sequence and accepted compiler precedent. | Destinations 1, 3, 5, 6; final B002 generated command `000000012621` | reject-invalid | applied |
| C07 | Source-facing identity is private `IMEPane::UpdateFocusCaretAnchor`. | 92 | Receiver fields, class placement, operation, style. | Destinations 1 and 2; validators `000000012594`/`000000012595` | incorporate | applied |
| C08 | UID00031G retains canonical owner/emitter UID00006H, reconstructable true, blank position, Nested 0. | 99 | Complete-object receiver and source tree. | Destination 1 metadata; validator `000000012594` | already-present | already-present |
| C09 | Target score is `91/93`. | 94 | All behavior/C++ blockers closed; naming/xref cap remains. | Destination 1 metadata/rationale; validator `000000012594` | incorporate | applied |
| C10 | Positive branch uses focus count at `+0x110` and list at `+0x104`. | 100 | Exact field reads and class layout. | Destinations 1, 2, 5; validators `000000012594`/`000000012595`/`000000012598` | incorporate | applied |
| C11 | The selected element is the last list entry and the returned element-storage address is dereferenced once. | 100 | Subtract-one sequence, virtual slot, `mov esi,[eax]`. | Destinations 1 and 3; validators `000000012594`/`000000012596` | incorporate | applied |
| C12 | `0x0058f050` supplies two signed-short caret/selection outputs. | 98 | Exact helper disassembly. | Destinations 1, 3, 4, 7; validators `000000012594`/`000000012596`/`000000012597`/`000000012600` | incorporate | applied |
| C13 | `0x0058f740` maps the first short to a local Point. | 97 | Caller stack shape and helper decompile. | Destinations 1, 3, 4, 7; validators `000000012594`/`000000012596`/`000000012597`/`000000012600` | incorporate | applied |
| C14 | `0x005447c0` is inherited Pane screen-offset support with zero fallback. | 97 | Helper decompile and broad accepted support. | Destinations 1, 3, 6; current Pane support remained verify-only | already-present | already-present |
| C15 | Current Point order is `y` then `x`; horizontal sum writes `+0x11c`, vertical sum writes `+0x118`. | 100 | Point formal layout and exact stores. | Destinations 1, 2, 3, 5; validators `000000012594`/`000000012595`/`000000012596`/`000000012598` | incorporate | applied |
| C16 | Count `<= 0`, including negative, clears X then Y to zero. | 100 | `jle` and exact empty branch. | Destinations 1, 2, 5; validators `000000012594`/`000000012595`/`000000012598` | incorporate | applied |
| C17 | Positive branch has no null, bounds, sentinel, or helper-failure checks. | 100 | Full disassembly. | Destinations 1, 3, 5, 6; validators `000000012594`/`000000012596`/`000000012598`/`000000012599` | incorporate | applied |
| C18 | Target contains no allocation, free, EH, cookie, vptr, scalar wrapper, thunk, or cleanup source. | 100 | Full range disassembly. | Destinations 1, 5, 6; validators `000000012594`/`000000012598`/`000000012599` | incorporate | applied |
| C19 | UID00018A calls UID00031G at source level and then reads cached anchors. | 94 | Inline equivalence and source-shape precedent. | Destination 3; validator `000000012596`; final B002 generated command `000000012621` | incorporate | applied |
| C20 | UID00018A is `90/92`; owner/emitter/class route remains unchanged. | 93 | Compile/source correction with stable binary behavior. | Destination 3 metadata/rationale; validator `000000012596` | incorporate | applied |
| C21 | IMEPane complete declaration includes the private helper declaration and preserves all current fields/friends/methods. | 99 | Compile visibility and current class union. | Destination 2; validator `000000012595` | incorporate | applied |
| C22 | UID00006H is `90/92`; owner/emitter/position remain `0000K5/0000K5/0`. | 94 | Complete class/helper route. | Destination 2 metadata/rationale; validator `000000012595` | incorporate | applied |
| C23 | TextEditPane declares the two accepted caret helpers using Point and short contracts. | 96 | Exact helper ABI and existing consumers. | Destination 4; validator `000000012597` | incorporate | applied |
| C24 | UID0000EO retains `91/93`, owner/emitter UID0000ON, true, and its existing position. | 98 | New declarations close a gap but do not remove broader class caps. | Destination 4 metadata/rationale; validator `000000012597` | already-present | already-present |
| C25 | UID000189 remains a non-duplicating aggregate with `[[CHILDREN]]`; score is `88/91`. | 95 | Stable family range and final source child closure. | Destination 5; validator `000000012598` | incorporate | applied |
| C26 | UID0000K5 remains the IMEPanes source owner with corrected retained-method/inlining prose; score is `91/90`. | 94 | Family clustering and generated path. | Destination 6; validator `000000012599` | incorporate | applied |
| C27 | UID0000ON contains helper/source dependency prose without by-file reconstruction metadata; score remains `91/90`. | 96 | Current by-file rule and class route. | Destination 7; validator `000000012600` | incorporate | applied |
| C28 | UID0004CC, UID0004CD, Point, List, Pane/Layer, and g_pIMEPane stay verify-only. | 99 | Current same-or-greater detail; no contradiction. | Read-only verification list; no bounded repair required | already-present | already-present |
| C29 | Prior no-code, `GetAt`, direct-slot-cast, and `GetScreenOrigin` claims remain labeled historical/superseded, not silently deleted. | 99 | No-loss rule and current support. | Destinations 1-7 history; validators `000000012594`-`000000012600` | historicalize | applied |
| C30 | Exact stale manual coverage rows require supervisor-owned replacement text; generated coverage is not a substitute. | 100 | Read-only row comparison. | Exact Manual Supervisor-Owned Coverage Or Tracker Text; B002 made no manual coverage edit | incorporate | excluded-with-reason |

## Positive Evidence Summary

- Exact 130-byte range has an ordinary receiver frame, meaningful locals, one condition, two complete returns, and no undecoded bytes.
- Every receiver-relative field matches IMEPane: list `+0x104`, count `+0x110`, anchor Y `+0x118`, anchor X `+0x11c`.
- The positive path's three helper calls and point arithmetic are fully explained by current TextEditPane, Point, Pane, and Layer evidence.
- The negative path precisely clears the same persistent fields.
- UID00018A independently reproduces the operation against `g_pIMEPane`; its differing register allocation/global receiver is what optimized source-level inlining should produce.
- Stable method-family order and exact padding isolate the body from SetFocusPane and IsIMESupported.
- Current generated source proves the only blocker is documentation/source shape: it emits a comment where a complete method and call route belong.

## IDA MCP Facts

- Function/range facts: no function model at `0x004e8110`; SetFocusPane is `0x004e80a0-0x004e810b`; IsIMESupported begins `0x004e81a0`; exact target is 130 bytes.
- Exact target bytes:

  `55 8B EC 83 EC 18 57 8B F9 8B 87 10 01 00 00 85`
  `C0 7E 5A 8B 97 04 01 00 00 8D 8F 04 01 00 00 56`
  `48 50 FF 52 10 8B 30 8D 45 FC 50 8D 45 F8 8B CE`
  `50 E8 0A 6F 0A 00 FF 75 F8 8D 45 F0 8B CE 50 E8`
  `EC 75 0A 00 8D 45 E8 8B CE 50 E8 61 C6 05 00 8B`
  `55 E8 8B 45 EC 03 55 F0 03 45 F4 89 87 1C 01 00`
  `00 5E 89 97 18 01 00 00 5F 8B E5 5D C3 33 D2 33`
  `C0 89 87 1C 01 00 00 89 97 18 01 00 00 5F 8B E5`
  `5D C3`
- Exact instruction/CFG inventory: `0x004e8110-0x004e8119` establishes EBP, a `0x18` local frame, and EDI as receiver; `0x004e8119-0x004e8123` reads count and branches on `jle` to `0x004e817d`; `0x004e8123-0x004e8137` loads list/count-minus-one, dispatches virtual slot `+0x10`, and dereferences the pointer slot into ESI; `0x004e8137-0x004e8146` prepares two short outputs and calls `0x0058f050`; `0x004e8146-0x004e8157` passes the first short and a Point output to ESI for `0x0058f740`; `0x004e8157-0x004e8165` passes a second Point output to ESI for `0x005447c0`; `0x004e8165-0x004e8172` adds matching X and Y components and stores X at `+0x11c`; `0x004e8172-0x004e817d` stores Y at `+0x118` and returns; `0x004e817d-0x004e8192` zeros EDX/EAX, stores X then Y, and returns. There are two semantic branches and two exits.
- Data/table/padding facts: five predecessor and fourteen successor `0xcc` bytes; target uses six stack-local words/dwords within a `0x18` local frame.
- Xref facts: no inbound target xrefs; one internal conditional branch to the clear path; no raw direct address/rel32 route.
- Vtable/global/type facts: target is a nonvirtual private-style IMEPane operation; UID00018A accesses the same object via `g_pIMEPane`; current Point order is Y/X and List element access returns slot storage.
- Negative IDA facts: no target symbol/function object, no exception data, no allocation/free, no null/failure path, no wrapper/adjustor/vtable data, and no compiler cleanup island.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Recommended Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004e8110-0x004e8192` | UID00031G target | retained private IMEPane anchor refresh method | true | UID00006H | `91/93` | applied body; no split |
| `0x004e7470-0x004e763c` | UID00018A | composition text method and source-level caller | true | UID00006G | `90/92` | applied source call; optimized bytes remain explained |
| IMEPane class | UID00006H | declaration/layout emitter | true | UID0000K5 | `90/92` | private declaration applied; complete union preserved |
| IME pane family | UID000189 | aggregate/source-order container | true | UID0000K5 | `88/91` | children marker retained; target row/history applied |
| TextEditPane class | UID0000EO | helper declaration support | true | UID0000ON | `91/93` | two declarations applied; complete union preserved |
| IMEPanes file | UID0000K5 | source root | true | source tree | `91/90` | prose/source route applied; no formal metadata |
| TextEditPane file | UID0000ON | source root/support | true | source tree | `91/90` | prose applied; no formal metadata |
| padding | no UID | five bytes before, fourteen after | false | none | not applicable | remain padding; no child |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| target start | zero modeled inbound xrefs | retained body is not directly called in shipped machine code |
| target start | zero raw VA/RVA/immediate/rel32 routes | no hidden binary call/data route was missed |
| `0x004e8121` | branch to `0x004e817d` | count `<= 0` selects clear path |
| `0x004e812f` | virtual List element lookup | obtains storage for last focus-pane pointer |
| `0x004e8141` | call `0x0058f050` | obtains two short caret/selection values |
| `0x004e8152` | call `0x0058f740` | obtains caret-local Point from first short |
| `0x004e8160` | call `0x005447c0` | obtains pane screen offset Point |
| UID00018A inline slice | same operation at `0x004e74b0-0x004e751d` | optimized source-level call route |

## Documentation Evidence And IDA Status

- Evidence-time / pre-callback UID00031G documented most behavior but retained a no-code block, no-call requirement, stale score rationale, and “local point/rect” wording. UID00006H omitted the declaration; UID00018A used the wrong List API/cast and historical pane-helper alias; UID000189 retained stale no-code/Wave3 implications; UID0000EO omitted both caret-helper declarations.
- Current UID00031G has exact Destination 1, `91/93`, the exact range/hash/CFG/helpers/padding/no-check/source-operation evidence, and labeled history (`000000012594`).
- Current UID00006H has `90/92`, the complete preserved class union, private target declaration, exact method order, field/list/Point support, and historicalized no-code statement (`000000012595`).
- Current UID00018A has `90/92`, the source call and cached-anchor reads, correct helper names, and unchanged composition popup behavior (`000000012596`).
- Current UID0000EO remains `91/93` and has the Point forward declaration plus exact two helper declarations in the preserved complete class union (`000000012597`).
- Current UID000189 has `88/91`, exact aggregate formal block, corrected source-bearing target row/order, and historicalized Wave3/no-code text (`000000012598`).
- Current UID0000K5 is `91/90` and UID0000ON remains `91/90`; both are prose-only by-file roots, neither contains reconstruction metadata, and both retain unrelated family detail (`000000012599`/`000000012600`).
- Evidence-time generated IMEPanes.cpp at command `000000012582` had one class, one target marker, zero target definitions, and one stale no-code comment. Final B002 callback command `000000012621` had one class, one declaration, one definition, one source call, zero target no-code/empty markers, and no duplicate helper/class/global/ABI output.

## Ranked Ownership Analysis

### 1. UID00006H IMEPane

- Evidence for: complete-object receiver, exact fields, placement among IMEPane methods, g_pIMEPane inline duplicate, current aggregate/class/file ownership, and friend access from IMECompositionPane.
- Evidence against: no surviving symbol and no direct binary xref.
- Decision: accepted direct semantic owner and emitter. The negative evidence caps confidence but does not outweigh the exact object layout.

### 2. UID00006G IMECompositionPane

- Evidence for: UID00018A contains the inlined operation and is the source-level caller.
- Evidence against: target body receives an IMEPane object and touches only IMEPane state; UID00018A is a consumer, not target owner.
- Decision: rejected as target owner; retained as caller/support destination.

### 3. Free/file-local IMEPanes helper

- Evidence for: no virtual slot or external call and no symbol.
- Evidence against: ECX complete-object receiver and private-state operation fit a member; current class friend relationship supports the source call.
- Decision: rejected as less plausible and less source-safe.

### Proposed new file/grouping, if applicable

- Not applicable. Existing UID0000K5 is the stable narrow source root and no new file, class, child, or grouping is needed.

## Source Placement

- Applied placement: the private IMEPane declaration is in UID00006H and the out-of-line definition is in the IMEPane child order between SetFocusPane and IsIMESupported, emitted through UID0000K5 into `NexusTK/input/IMEPanes.cpp`.
- UID00018A in the same source file invokes the private method through its existing IMECompositionPane friendship, allowing the compiler to inline it exactly as observed.
- TextEditPane helper declarations are in UID0000EO and its normal TextEditPane header/source route. They are dependencies, not duplicate definitions in IMEPanes.
- Rejected placements: direct by-file formal blocks (forbidden/non-emitting), IMECompositionPane ownership (wrong receiver), free static helper (weaker source shape), and comment-only representation (cannot regenerate bytes).
- Remaining placement uncertainty: none with implementation impact. Exact header include ordering is source-tree prose, while ordinary generated dependencies provide compile visibility.

## Range / Split / Padding / Reclassification Analysis

- Exact code range remains `[0x004e8110,0x004e8192)` with no gap or mixed data.
- `[0x004e810b,0x004e8110)` and `[0x004e8192,0x004e81a0)` remain padding and must not be absorbed.
- No split, merge, rename, new UID, or parent change is justified.
- Applied reclassification is source-disposition only: from stale “raw helper rare no-code” to retained source-authored IMEPane method.
- Parent UID000189 remains a non-duplicating aggregate whose formal body is only its existing comment plus `[[CHILDREN]]`.

## Negative Evidence Summary

- No modeled IDA function, direct xref, raw pointer, address immediate, or direct rel32 route was found.
- No vtable entry references the body, so it is not a virtual callback.
- No independent caller besides the optimized inline source operation can be recovered from the binary.
- No original symbol proves the exact method/helper/field spelling.
- No null, list-bounds, slot-null, pane-null, helper-failure, invalid-origin, or negative-count repair path exists; adding any would change behavior.
- No cleanup/EH/compiler-wrapper source exists in the range.
- These facts reject claims of direct runtime reachability and final naming proof. They do not reject source emission because the body and optimizer-inline relationship explain all bytes.

## IDA Rename / Type / Comment Recommendations

- Source-facing target name: `IMEPane::UpdateFocusCaretAnchor`, descriptive/inferred, high confidence.
- Receiver type: `IMEPane *`; current generic/raw labels are rejected.
- Fields: retain `focusPaneList`, `focusPaneCount`, `focusCaretAnchorY`, and `focusCaretAnchorX` with current offsets.
- Helpers: retain descriptive `TextEditPane::GetCaretRange`, `TextEditPane::GetCaretLocalPoint`, and current broad `Pane::GetScreenOffset`. Historical `GetScreenOrigin` is superseded.
- Locals: two short caret outputs and two Point values; do not describe a Rect temporary.
- IDA DB edits are not requested or permitted by this assignment. Recommendations apply to documentation/source only.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. The target and three source-bearing support destinations below are implementation-ready. The aggregate block is included to prove exact no-duplicate preservation.

### Destination 1 - UID00031G target formal block

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void IMEPane::UpdateFocusCaretAnchor()
{
    if (focusPaneCount > 0) {
        TextEditPane *focusPane =
            *static_cast<TextEditPane **>(
                focusPaneList.GetElementAt(focusPaneCount - 1));

        short caretIndex;
        short caretEnd;
        focusPane->GetCaretRange(&caretIndex, &caretEnd);

        Point caretPoint;
        focusPane->GetCaretLocalPoint(&caretPoint, caretIndex);

        Point paneOrigin;
        focusPane->GetScreenOffset(&paneOrigin);

        focusCaretAnchorX = paneOrigin.x + caretPoint.x;
        focusCaretAnchorY = paneOrigin.y + caretPoint.y;
    } else {
        focusCaretAnchorX = 0;
        focusCaretAnchorY = 0;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 2 - UID00006H complete IMEPane formal block

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;
class IMECandidatePane;
class IMECompositionPane;
class IMEStatusPane;
class List;
class Pane;

class IMEPane : public Pane
{
    friend class IMECandidatePane;
    friend class IMECompositionPane;

public:
    IMEPane();
    virtual ~IMEPane();

    void SetFocusPane(Pane *pane, bool focused);
    bool IsIMESupported(const Event *event);
    bool HandleIMEMessage(const Event *event);

private:
    void UpdateFocusCaretAnchor();

    IMEStatusPane *statusPane;       // +0xf8, status child slot deleted by root teardown; not a UID0004CE branch.
    Pane *activeChildPane;           // +0xfc, active composition/candidate child or popup anchor.
    IMECandidatePane *candidatePane; // +0x100, root-owned candidate popup child.
    List focusPaneList;              // +0x104, focused text-entry pane pointer slots.
    int focusPaneCount;              // +0x110, embedded focusPaneList count slot alias.
    int focusCaretAnchorY;           // +0x118.
    int focusCaretAnchorX;           // +0x11c.
};

extern IMEPane *g_pIMEPane;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 3 - UID00018A complete formal block

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void IMECompositionPane::SetCompositionString(const wchar_t *text, int length)
{
    if (length > 255) {
        length = 255;
    }

    const int popupTextWidth = MeasureTextWidth(text, length);
    const int lineHeight = GetLineHeight();

    IMEPane *imePane = g_pIMEPane;
    imePane->UpdateFocusCaretAnchor();

    const int anchorX = imePane->focusCaretAnchorX;
    const int anchorY = imePane->focusCaretAnchorY;

    RectBounds popupRect;
    popupRect.left = anchorX;
    popupRect.top = anchorY;
    popupRect.right = (popupTextWidth > 0) ? anchorX + popupTextWidth + 4 : anchorX;
    popupRect.bottom = anchorY + lineHeight + 4;

    const int screenWidth = g_pScreenPane->GetScreenWidth();
    const int screenHeight = g_pScreenPane->GetScreenHeight();

    if (popupRect.right >= screenWidth) {
        TranslateRectBounds(&popupRect, screenWidth - popupRect.right, 0);
    }
    if (popupRect.top >= screenHeight) {
        TranslateRectBounds(&popupRect, 0, screenHeight - popupRect.bottom);
    }
    if (popupRect.left < 0) {
        TranslateRectBounds(&popupRect, -popupRect.left, 0);
    }
    if (popupRect.top < 0) {
        TranslateRectBounds(&popupRect, 0, -popupRect.top);
    }

    SetBounds(&popupRect, 0);

    wcsncpy_s(compositionText, 256, text, length);
    compositionText[length] = 0;

    compositionCursorX = MeasureTextWidth(compositionText, GetCompositionCursorPosition()) + 3;
    Invalidate(&bounds);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 4 - UID0000EO complete TextEditPane formal block

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;
class List;
class TextEditObject;
class TextEditScrap;
struct Point;
namespace mystr {
template <class CharT> struct mychar_traits;
template <class CharT, class Traits> class StringBase;
}

class TextEditPane : public ScrollablePane
{
public:
    TextEditPane(int maxWidth,
                 int maxHeight,
                 int contentWidth,
                 int contentHeight,
                 int backgroundColor,
                 int scrollColor,
                 char hasHorizontalScrollbar,
                 char hasVerticalScrollbar,
                 unsigned int styleFlags,
                 unsigned short legacyAssetMode,
                 char isReadOnly,
                 char inputMode);
    virtual ~TextEditPane();

    short CopyWideText(wchar_t *outText, short capacity) const;
    mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > GetText() const;
    short GetTextLength() const;
    void GetCaretRange(short *start, short *end) const;
    void GetCaretLocalPoint(Point *point, short caretIndex) const;
    unsigned char *EncodeState(unsigned short *outSize) const;
    void DecodeState(const unsigned char *data, unsigned short size);

    void InsertText(const wchar_t *text, int flags);
    void SetText(const wchar_t *text, short length, short selectStart, short selectEnd);
    void ClearText();
    void SetSelectionRange(short start, short end);
    void SelectAll();
    void ApplySelectionFormat(unsigned char formatMask, const void *formatData);
    void InsertEmbeddedObject(TextEditObject *object, int width, int height);
    void SetMaxLength(short maxLength);
    void SetMaxLines(short maxLines);
    void EnableMaskedText();
    void SetEditActiveState(bool editActive, bool selectAll);
    bool IsEmpty() const;
    void ScrollToTop();
    unsigned char GetMode() const { return m_mode; }

    void PasteFromClipboard(TextEditScrap *scrap);
    short GetLineCount() const;
    void SetViewportBounds(const RectBounds *bounds);
    void GetTextAreaBounds(RectBounds *bounds) const;
    void SetTextAreaBounds(const RectBounds *bounds);
    virtual void OnDraw();

protected:
    virtual int OnKeyEvent(Event *event);
    virtual int OnMouseEvent(Event *event);

    void InvalidateTextRegion(short start, short end);
    void DeleteSelection();
    void FindWordBoundary(short index, short *wordStart, short *wordEnd) const;
    void AutoScrollSelectionToPoint(int x, int y);

private:
    List *m_textStorage;
    List *m_lineTable;
    List *m_styleRuns;
    List *m_formatRecords;
    short m_selectionStart;
    short m_selectionEnd;
    unsigned int m_editorFlags;
    unsigned char m_mouseMode;
    unsigned char m_dirty;
    unsigned char m_maskedText;
    short m_maxLength;
    short m_maxLines;
    unsigned char m_inputState;
    unsigned char m_lineLimitState;
    unsigned char m_formatMode;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 5 - UID000189 aggregate formal block, preserved exactly

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Aggregate IME pane method-family range. Exact source bodies are owned by the
// method/class child pages listed below; this page preserves the source-order
// insertion point for the IMEPanes.cpp family.

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

- Destination 6 is prose-only UID0000K5 by-file/IMEPanes; no reconstruction metadata or formal block may be added.
- Destination 7 is prose-only UID0000ON by-file/TextEditPane; no reconstruction metadata or formal block may be added.
- Behavior preservation: Destination 1 exactly keeps the positive lookup/helper/order/stores and count-nonpositive clear path. Destination 3 preserves every post-anchor UID00018A statement while representing the original helper call that produced the inline machine sequence.
- Source-era fit: private class helper, pointer-slot list storage, short caret indices, out-Point APIs, explicit NULL-era surrounding style, and an out-of-line definition eligible for optimization are plausible for the project's late-1999 through mid-2000s Visual C++ source.
- No code remains blank. The prior rare no-code proof is rejected because it cannot regenerate a source-bearing method.

## Final Recommendation

- Applied target Destination 1 and metadata `91/93` retain owner/emitter UID00006H, true, blank position, Nested 0, exact range, and complete evidence/history.
- Applied complete IMEPane Destination 2 preserves all existing class details, adds one private declaration, sets UID00006H to `90/92`, and keeps owner/emitter/position `0000K5/0000K5/0`.
- Applied complete UID00018A Destination 3 replaces only the duplicated anchor operation with the source-level helper call and cached field reads, sets it to `90/92`, and retains owner/emitter UID00006G.
- Applied complete TextEditPane Destination 4 has two helper declarations and the Point forward declaration; UID0000EO retains `91/93` and its owner/emitter route.
- UID000189 Destination 5 remains exact; only its target inventory/history/score changed to `88/91`.
- Prose-only source/dependency/history updates are applied to UID0000K5 and UID0000ON without by-file reconstruction metadata.
- UID0004CC, UID0004CD, Point/RectGeometry, List, Pane/Layer, g_pIMEPane, and other IME siblings were reread and remain unchanged because no concrete target-specific contradiction was found.
- No ownerless/non-emitting item, new child, split, rename, or later source blocker remains in this assignment.

## Recommended Target Doc Changes

- Target path: `by-memory/0x004e8110-0x004e8192.IMEPaneFocusCaretAnchorHelper.md`.
- Applied: the formal proof comment is replaced by Destination 1 exactly.
- Applied: `COMPLETION:91`, `CONFIDENCE:93`; `CANONICAL_OWNER:00006H`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00006H`, blank position, and `Nested:0` are retained.
- Applied: Item Summary identifies one retained private IMEPane source method, exact range/hash, last-pointer-slot lookup, three helper roles, anchor X/Y writes, clear branch, no-check behavior, stable padding, and optimizer-inline source route.
- Preserved: exact bytes/hash, full instruction/CFG behavior, helper addresses/contracts, no-null/no-failure behavior, padding, negative routes, source placement, score cap, rejected alternatives, and historical B008/B003 conclusions labeled superseded.
- Applied: future no-declaration/no-call directions are historicalized without deleting the zero-direct-xref/function-object facts.

## Recommended Support Doc Changes

- Applied `by-class/IMEPane.md` UID00006H Destination 2 at `90/92`, including method table/layout/evidence/history/source order and retained-method/optimizer-inline relationship; every unrelated method/field/friend remains.
- Applied UID00018A Destination 3 at `90/92`, including source call versus optimized bytes, pointer-slot dereference, current screen-offset name, and unchanged popup behavior; caller, clamp, geometry, copy, cursor, and invalidate facts remain.
- Applied `by-class/TextEditPane.md` UID0000EO Destination 4 at retained `91/93`, including exact helper ABI/evidence and complete prior class union.
- Retained UID000189 Destination 5 exactly and applied `88/91`, corrected UID00031G source-bearing inventory, score prose, and historical Wave3/no-code wording.
- Applied prose-only UID0000K5 update at `91/90`; method order, source call/inlining, TextEdit dependencies, no-check behavior, and rejected alternatives are present with no formal metadata.
- Applied prose-only UID0000ON update at retained `91/90`; caret-range/local-point helper contracts consumed by IMEPanes are present with no formal metadata.
- Verified read-only with no target-specific drift: UID0004CC SetFocusPane, UID0004CD IsIMESupported, Point/RectGeometry, List, Pane/Layer geometry, g_pIMEPane, and all unrelated IME/TextEdit children.

## Score And Metadata Recommendation

| Destination | Pre-callback | Current applied | Metadata disposition |
| --- | --- | --- | --- |
| UID00031G target | `86/90` | `91/93` | retain owner/emitter UID00006H, true, blank position, Nested 0 |
| UID00006H IMEPane | `88/91` | `90/92` | retain owner/emitter UID0000K5, true, position 0 |
| UID00018A | `88/91` | `90/92` | retain owner/emitter UID00006G, true, existing position/Nested |
| UID000189 aggregate | `87/90` | `88/91` | retain owner/emitter UID0000K5, true, aggregate marker |
| UID0000K5 file | `90/88` | `91/90` | retain source root; prose-only page |
| UID0000EO TextEditPane | `91/93` | `91/93` | retain owner/emitter UID0000ON and class route |
| UID0000ON file | `91/90` | `91/90` | retain source root; prose-only page |

- Target completion rises materially because exact bytes/hash, boundaries, full branch behavior, helper contracts, field types/order, source call, and compile surface are now closed and a complete formal body replaces a comment.
- Target confidence stops at 93 because original private/helper spellings and out-of-line runtime reachability are not symbol/direct-xref proven.
- UID00006H/UID00018A rise because the declaration/call route becomes source-safe and behavior-identical; their broader unrelated confidence caps remain.
- UID000189 and UID0000K5 rise only enough to reflect closure of their last stale target-specific no-code route; they retain broader family/file uncertainty.
- UID0000EO/UID0000ON do not rise because two helper declarations close this dependency but do not resolve their broad remaining private-table/helper-name caps.
- Score-blocker audit: function-object absence checked and reclassified; all route forms exhausted; inline source route proven; helper ABIs resolved; list indirection resolved; Point ordering resolved; source placement resolved; formal compile surfaces supplied; generated/manual coverage expectations specified. No investigable blocker is deferred.

## Open Questions With Attempted Resolution

- **Is the target dead/unreferenced source or compiler-only output?** All route scans found no runtime reference, but complete method shape plus an exact optimizer-inline source operation support retained source. Resolution: retained source-authored method; no direct runtime-call claim.
- **Was the original method name exact?** No symbol/string/report proves it. Operation and project naming support `UpdateFocusCaretAnchor`. Resolution: use the descriptive source name and cap confidence at 93.
- **Should UID00018A keep the inline statements in source?** The source-level helper call explains both the retained body and inline bytes, while duplicated statements do not explain why the body exists. Resolution: call the helper.
- **Does List return the object or element storage?** Exact post-call dereference and current List formal API resolve storage. Resolution: dereference one TextEditPane pointer slot.
- **Which caret output is used?** The first short is passed to local-point helper; the second is discarded after the call. Resolution: retain two outputs and use the first as caret index.
- **Is pane geometry `GetScreenOrigin` or `GetScreenOffset`?** Current broad helper evidence and implementation usage favor `GetScreenOffset`; the older name is descriptive history. Resolution: use current name.
- **Are any checks or cleanup missing from the draft?** Full 130-byte disassembly has none. Resolution: do not invent them.
- Questions remaining unresolved with implementation impact: none. Exact historical spellings remain inherently unprovable and are reflected only in confidence caps.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Inspected read-only manual rows: `by-memory/-coverage-report.md` lines 1819/1820/1823, `by-class/-coverage-report.md` lines 258/549, and `by-file/-coverage-report.md` lines 122/284. All seven need replacement because scores or target-specific source descriptions change. B002 must not apply these supervisor-owned rows.
- Replace by-memory UID000189 row at its existing indentation with:

    - [UID:000189][0x004e70f0-0x004e8433.IMEPaneFamily](by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md) 0x004e70f0-0x004e8433 | class-method-cluster | IMEPaneFamily : reconstructable : 88% : very-strong : Assigned to [UID:0000K5][IMEPanes](by-file/IMEPanes.md); exact IME method/child order, raw destructor splits, retained source-authored UID00031G focus-caret helper and optimizer-inline UID00018A call route, g_pIMEPane usage, InputMan boundary, and padding through 0x004e8433 are documented without duplicate aggregate source.

- Replace by-memory UID00018A row at its existing indentation with:

        - [UID:00018A][0x004e7470-0x004e763c.IMECompositionSetCompositionString](by-memory/0x004e7470-0x004e763c.IMECompositionSetCompositionString.md) 0x004e7470-0x004e763c | method | IMECompositionPane::SetCompositionString : reconstructable : 90% : very-strong : Exact 0x1cc composition-popup method and sole OnKeyEvent caller; source-level UID00031G anchor-refresh call explains the optimized inline sequence, while clamp/measure/screen-clamp/bounded-copy/cursor-width/invalidate behavior and IMECompositionPane ownership remain complete.

- Replace by-memory UID00031G row at its existing indentation with:

        - [UID:00031G][0x004e8110-0x004e8192.IMEPaneFocusCaretAnchorHelper](by-memory/0x004e8110-0x004e8192.IMEPaneFocusCaretAnchorHelper.md) 0x004e8110-0x004e8192 | method | IMEPane::UpdateFocusCaretAnchor : reconstructable : 91% : very-strong : Retained source-authored IMEPane method with exact 130-byte body/hash, stable five/fourteen-byte padding, last focus-list pointer-slot lookup, caret/local/screen-offset helpers, X/Y cached-anchor update or count-nonpositive clear behavior, no null/failure checks, and optimizer-inline source call in UID00018A.

- Replace by-class UID00006H row with:

- [UID:00006H][IMEPane](by-class/IMEPane.md) : reconstructable : 90% : very-strong : Process-level pane-side IME coordinator attached to IMEPanes with complete singleton/focus-list/child-popup layout and lifecycle, SetFocusPane, private UID00031G UpdateFocusCaretAnchor declaration/source route, IsIMESupported/HandleIMEMessage, singleton clear/scalar wrapper distinctions, g_pIMEPane evidence, and InputMan boundary.

- Replace by-class UID0000EO row with:

- [UID:0000EO][TextEditPane](by-class/TextEditPane.md) : reconstructable : 91% : very-strong : Full TextEditPane declaration with by-value wide StringBase GetText ABI, exact GetCaretRange and GetCaretLocalPoint Point/short contracts used by IMEPanes, text-area/selection/scroll APIs, preserved storage/editor/drawing/paste/viewport/callback/field surfaces, class closure before children, and remaining broad table/helper-name confidence caps.

- Replace by-file UID0000K5 row with:

- [UID:0000K5][IMEPanes](by-file/IMEPanes.md) : reconstructable : 91% : very-strong : NexusTK/input/IMEPanes.cpp source root with complete status/composition/candidate/root pane ordering, g_pIMEPane singleton, UID00031G retained focus-caret method plus UID00018A optimizer-inline call route, raw destructor/helper and scalar-wrapper distinctions, candidate-string support, owner-pollution closures, and InputMan boundary documented.

- Replace by-file UID0000ON row with:

- [UID:0000ON][TextEditPane](by-file/TextEditPane.md) : reconstructable : 91% : strong : Rich text editor implementation with current class/support/callback inventory, source-visible GetCaretRange/GetCaretLocalPoint contracts consumed by IMEPanes, by-value wide StringBase GetText ABI, target-proven text-area/selection/scroll APIs, active-editor/serialization/scrollbar ownership, exact support-object split, and preserved broad table/helper-name caps.

- Reason B002 must not apply: manual `-coverage-report.md` files are supervisor-owned and explicitly read-only; validator-generated coverage does not synchronize them.

## Follow-Up Actions

- B002 callback work is complete: each accepted ordinary destination was reread, edited under one short serial lease, scoped-validated, and released before the next lease.
- Final B002 generated verification passed: exactly one IMEPane class, one target declaration, one target definition between SetFocusPane and IsIMESupported, one UID00018A source call, no target no-code proof/empty marker, no duplicated inline source sequence, and no duplicate helper/class/global/ABI source.
- Supervisor: independently perform Gate 2 review of this exact artifact and ordinary/generated readback.
- Supervisor-only external action: apply/reconcile exact manual coverage rows if accepted. Current/future validation, report execution, move, archive, path, and lifecycle state remain supervisor/validator-owned and are not asserted.
- A-agent actions: none.
- B002 future research or implementation actions: none within this target; no blocker is deferred.

## Confidence

- Recommendation confidence: 93/100.
- Score confidence: 95/100.
- Remaining uncertainty: exact historical spelling and why the linker retained an unreferenced out-of-line copy. Neither changes behavior, owner/emitter, source placement, or formal C++ readiness.

## Validator Results

- Accepted validator form for each ordinary page was `python .\tools\validator.py --mode file --file '<path>' --apply --queue-timeout 240`; the final authorized form added `--wait-generated` for `by-file/IMEPanes.md`.

| Command ID | Timestamp | Ordinary page / purpose | Exit / ok | Warnings and side effects | Lease result |
| --- | --- | --- | --- | --- | --- |
| `000000012594` | `2026-07-15T00:15:45-04:00` | UID00031G target | `0 / 1` | completion/confidence and target content applied; generated refresh deferred; no unresolved target warning | released immediately |
| `000000012595` | `2026-07-15T00:16:52-04:00` | UID00006H IMEPane | `0 / 1` | metadata/class content applied; generated refresh deferred; no unresolved target warning | released immediately |
| `000000012596` | `2026-07-15T00:18:12-04:00` | UID00018A | `0 / 1` | metadata/formal content applied; generated refresh deferred; no unresolved target warning | released immediately |
| `000000012597` | `2026-07-15T00:19:11-04:00` | UID0000EO TextEditPane | `0 / 1` | content applied; eight pre-existing `missing_ref_uid` occurrences (`00040S`, `00040T`, `0003M8`, `0003FD`, `0003FC`); no callback-introduced warning | released immediately |
| `000000012598` | `2026-07-15T00:20:26-04:00` | UID000189 aggregate | `0 / 1` | metadata/inventory/history applied; exact aggregate block retained; generated refresh deferred | released immediately |
| `000000012599` | `2026-07-15T00:21:53-04:00` | UID0000K5 by-file prose | `0 / 1` | prose/score applied; no reconstruction metadata; generated refresh deferred | released immediately |
| `000000012600` | `2026-07-15T00:22:41-04:00` | UID0000ON by-file prose | `0 / 1` | prose applied; pre-existing reference inventory produced 59 `missing_ref_uid` occurrences with 49 suppressed; callback added only UID00018A/UID00031G reference-index entries | released immediately |
| `000000012601` | `2026-07-15T00:22:56-04:00` | final authorized UID0000K5 `--wait-generated` | `0 / 1` | generated refresh completed; project-wide registry rebuild reported pre-existing `autogen_children_fallback_insert:14`, `autogen_children_marker_missing:86`, `autogen_emitter_has_no_code:171`, and `generated_metadata_refresh:281`; no target failure | no lease required; UID0000K5 lease was already released |
| `000000012621` | `2026-07-15T00:34:39-04:00` | final recheck after concurrent generated-metadata drift, UID0000K5 `--wait-generated` | `0 / 1` | generated refresh completed; same project-wide warning counts `14/86/171/281`; projected completion-stats section refreshed as a validator side effect; no target failure | no lease required; all ordinary leases were already released |

- One local runner invocation before command `000000012621` timed out after 5.021 seconds before returning command metadata; no result from that invocation was accepted. The repeated waited invocation completed normally and is the final proof.
- Final generated readback: `auto-generated/NexusTK/input/IMEPanes.cpp`, command `000000012621`, SHA256 `3B3FBFC29D5D74E89C03CE38D249045FC8764643B7286FC5F15FA502E9431DEA`, 21,555 bytes, 664 lines.
- Exact counts: IMEPane class `1`; target declaration `1`; target definition `1`; UID00018A source call `1`; UID00031G marker `1`; `GetCaretRange` use `1`; `GetCaretLocalPoint` use `1`; `IMEPane *g_pIMEPane = NULL;` definition `1`; target no-code phrase `0`; target Empty Emitter Marker `0`; handwritten vtable-array/adjustor ABI definitions `0`.
- Exact order: UID00018A source call line 240; IMEPane class line 397; declaration line 411; SetFocusPane definition line 460; target marker/definition lines 475-476; IsIMESupported definition line 502; singleton definition line 651. The target is emitted exactly once in accepted child order and UID00018A contains no duplicate expanded anchor sequence.
- MCP results remain research evidence, not validator results; exact calls and time-scoped health are recorded above. No validator error remains unresolved.

## Changed Files

- Modified ordinary page: `by-memory/0x004e8110-0x004e8192.IMEPaneFocusCaretAnchorHelper.md`, SHA256 `231DEC37A3157357D2B8BF7D1DC0F653E7FA4670E0B94949B7AF8A78741262A3`.
- Modified ordinary page: `by-class/IMEPane.md`, SHA256 `C6893AB78634343D5D27D17EEC145DF1F3E5A8B67CCDC18E02115D2AF2C2A1BA`.
- Modified ordinary page: `by-memory/0x004e7470-0x004e763c.IMECompositionSetCompositionString.md`, SHA256 `0D19D7507D808D8D68DE751F4E1D67A1FDB9D4A215D6654AA0685C4F3771A7BB`.
- Modified ordinary page: `by-class/TextEditPane.md`, SHA256 `02AC17071776CBED5283E75146844660A3A8892F8FA338857BEA425EEAE3276D`.
- Modified ordinary page: `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md`, SHA256 `30912AF312E5816B5F5183C91512468BEBAEFF0433C3745E7DBFBF2593FDFF20`.
- Modified ordinary page: `by-file/IMEPanes.md`, SHA256 `F87D29349AE35D02080AA56D270AB7052A2FECCC24191F9A727CDDF5BABE42DA`.
- Modified ordinary page: `by-file/TextEditPane.md`, SHA256 `513A31F114E130956BCFD0177B20117B3A244D40AAA8E8BA364D77B371E39AF5`.
- Modified agent-local artifact: `tools/leaser/Agents/Agent-B002/research/00031G-IMEPaneFocusCaretAnchorHelper-source-quality.md`; final SHA256 is reported with the Gate 2 handoff.
- Validator-generated read-only verification output: `auto-generated/NexusTK/input/IMEPanes.cpp`, SHA256 `3B3FBFC29D5D74E89C03CE38D249045FC8764643B7286FC5F15FA502E9431DEA`; B002 did not edit it manually.
- Renamed: none.
- Leases: seven short serial ordinary-page leases acquired and released in destination order; the current shared lease report contains no B002 entry.
- Validators: scoped commands `000000012594`-`000000012600` and successful waited commands `000000012601`/`000000012621`, all exit 0 / ok 1; `000000012621` is B002's final time-scoped generated proof.
- Manual coverage/generated/tracker/audit/supervisor/validator-state/lifecycle files manually edited: none.
- IDA mutation: none.
- Report execution/lifecycle/probe/move/archive: not run.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor accepted exact report SHA256 `F740956B587C288DA32A2FED6489A6695E33B8DAB3BBBCEC6854EAFBBFCDFA08` before implementation.
- [x] Confirm target UID00031G exact range/hash/padding/function-model/xref/raw-route evidence in the target page.
- [x] Apply target `91/93`, retained UID00006H owner/emitter, true, blank position, Nested 0, and Destination 1.
- [x] Apply UID00006H `90/92`, retained UID0000K5 owner/emitter/position, complete Destination 2, method order, and historical no-code correction.
- [x] Apply UID00018A `90/92`, retained owner/emitter, complete Destination 3, source-level call/inlining proof, and all unchanged popup behavior.
- [x] Apply UID0000EO Destination 4 with Point forward declaration and both helper declarations; retain `91/93` and full class union.
- [x] Preserve UID000189 Destination 5 exactly; apply `88/91`, corrected target inventory, source-bearing disposition, and historicalized Wave3/no-code text.
- [x] Apply prose-only UID0000K5 source-order/dependency/history update and `91/90`; add no by-file reconstruction metadata.
- [x] Apply prose-only UID0000ON helper-contract update; retain `91/90`; add no by-file reconstruction metadata.
- [x] Verify UID0004CC, UID0004CD, Point/RectGeometry, List, Pane/Layer, g_pIMEPane, and unrelated siblings remain same-or-greater and unchanged absent concrete drift.
- [x] Preserve exact no-direct-route evidence while rejecting its stale no-code interpretation.
- [x] Preserve historical B008/B003 provenance, old helper aliases, rejected alternatives, and reasons.
- [x] Confirm every C01-C30 Action uses only the permitted enum and every final state is exactly `applied`, `already-present`, or `excluded-with-reason`.
- [x] Confirm no new child/split/rename/owner change and no third-party import directive applies.
- [x] Close all score/C++ blockers with no “later investigation” deferral.
- [x] Run one short lease, scoped validator, and immediate release for each changed ordinary page only after callback authorization.
- [x] Run one final authorized `--wait-generated` refresh and verify exact class/declaration/definition/call/order/no-marker counts.
- [x] Leave manual coverage unchanged and provide the seven exact supervisor-owned replacement rows above.
- [x] Reconcile report-only and implementation callback checklist state only after the corresponding work was verified.

Implementation callback pass:
- [x] Exact report accepted by supervisor for implementation.
- [x] C01-C30 applied/already-present/excluded-with-reason states recorded legally with separate destination proof.
- [x] Target Destination 1 and all target evidence incorporated without compression.
- [x] IMEPane Destination 2 installed without loss or duplicate declarations.
- [x] UID00018A Destination 3 installed with all non-anchor behavior preserved.
- [x] TextEditPane Destination 4 installed with the complete prior class union preserved.
- [x] Aggregate Destination 5 preserved and target row/history synchronized.
- [x] Both prose-only by-file destinations updated without reconstruction metadata.
- [x] All verify-only pages reread; no concrete target-specific drift required a bounded repair.
- [x] One scoped validator per changed ordinary page recorded with command, ID, timestamp, exit, ok count, warnings, and side effects.
- [x] Every lease released immediately after its page validator and no B002 lease remains.
- [x] Final waited generated refresh recorded and IMEPanes.cpp exact counts/order/assertions pass.
- [x] Changed Files, Validator Results, Current Target State, ledger, and checklist reconciled to durable callback truth.
- [x] Manual coverage rows remain unedited by B002 and are left for supervisor application.
- [x] No generated/tracker/audit/supervisor/validator-state/lifecycle/IDA file manually edited and no report execution/probe/move/archive command run.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000012644","destination_path":"executed-b-agent-research/B002/00031G-IMEPaneFocusCaretAnchorHelper-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/00031G-IMEPaneFocusCaretAnchorHelper-source-quality.md","timestamp":"2026-07-15T00:55:28-04:00","uid":"00031G"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
