** TARGET-REPORT-UID:0003EM **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

## Finalized Report / Current Recommendation

- Current recommendation: ordinary implementation is complete for the source-ready signed-short member `InventoryPane2::HitTestButton(int y, int x) const`. It scans button ids `0..3`, obtains each rectangle through `InventoryPane2::GetButtonRect`, applies the canonical half-open `PointInRect(y, x, bounds)` contract, returns the first hit id, and returns signed `-1` on a miss.
- Final disposition: UID0003EM remains a source-authored raw helper owned/emitted by UID00006S at `InventoryPane.cpp` position `320`; its implemented score is `94/93`; its target H channel remains blank because UID00006S owns the complete declaration.
- Completed action: UID0003EM plus the seven bounded support pages now carry the full evidence, formal CPP/H, compiler-successor, caller-inlining, ownership, source-route, history, and no-change IDA detail. Dated supervisor receipts confirm the Section 28 coverage reconciliation and unchanged I01/I02 states; B001 did not edit coverage or IDA.
- Confidence: very strong for range, bytes, ABI, argument order, return width, loop, rectangles, callees, table lowering, ownership, and source route; strong for the stripped source spelling and `const` qualifier, which remain inference-backed rather than symbol-proved.

## Supporting Research

- The report is based on a fresh 2026-08-15 local-date read-only pass over the canonical NexusTK IDB, current by-* documents, current generated InventoryPane CPP/H, manual coverage, generated tracker/coverage snapshots, analogous hit-test pages, and matching archived B-report evidence.
- The matching archived UID0000KA report correctly preserves the target range/hash, raw/no-function status, zero inbound raw-start xrefs, owner/emitter route, source position, and approved comment. Its `int x,y` signature, static declaration, four-rectangle static array, and `+256` vertical offsets for buttons 2/3 are historical pre-reanalysis hypotheses and are rejected by the current bounded evidence.
- Dated shared-header dependency receipt: B006's UID0003EL report was read at SHA256 `48219DFA6D851D7A9B58D9B7333AAAF58A0381D573E35D80BAB39A6598E00652` together with pre-callback UID0003EL ordinary evidence at SHA256 `01C095DFA3C7DF69C89781CB792F4D53CDF2B895E49973DDC644D499ADAD6DBA`; B006's completed ordinary artifact was then reread at SHA256 `47607646C48B492D8FF323532BDF109A78A970990D1592E0C24707A19ABC1366`. The raw analysis and implementation prove a logical signed `short`, unsigned guard, and one final InitRectBounds call; this report preserves the shared UID00006S declaration `void GetSlotRect(short slot, RectBounds *rect) const;` while correcting UID0003EJ/UID0003EM. UID0003EL remains a support dependency, not an additional declared target or coverage claim.
- Current lifecycle state is authoritative only from this report's current path plus validator-owned status/history metadata. The ordinary report body makes no current execute/archive assertion.
- No Wave2/Wave3 evidence was used. Any such historical terminology encountered in old notes was treated as stale and non-authoritative.

## Target

- Target UID: `0003EM`.
- Additional target UIDs: `none`.
- Declared-target inventory: only [UID:0003EM] `by-memory/0x004ef7a0-0x004ef86d.InventoryPane2ButtonHitTestRaw.md`, the source-bearing raw button hit-test helper. UID0003EL is a shared owner-H support dependency and is not an additional target.
- Target path: `by-memory/0x004ef7a0-0x004ef86d.InventoryPane2ButtonHitTestRaw.md`.
- Source queue/report row: assignment-time `auto-generated/-ag-research-tracker.md` by-memory reconstructable queue row `85/88`, reconstructable true, zero reports.
- Durable role/disposition: accepted focused by-memory source-quality implementation is complete. Section 28 records the supervisor-owned coverage handoff, Section 21 records no-change IDA readback contracts, and this body makes no assertion about current coverage reconciliation, gate, execution, archive, or reassignment state.
- Current scores and parent state: target `94/93`; owner UID00006S `94/94`; non-emitting split parent UID0002SV `89/92`; compiler successor UID0003EN `86/92`.
- Source route: UID00006S `InventoryPane2`, emitted through UID0000KA `InventoryPane` into `NexusTK/ui/inventory/InventoryPane.cpp` at position `320`; declaration emitted in `InventoryPane.h` by UID00006S.

## Current Target State

- Implemented metadata: completion `94`, confidence `93`, canonical owner `00006S`, emitter `00006S`, position `320`, reconstructable true, `Nested:0`, and the exact source-ready Item Summary from Section 24.
- Implemented CPP state: UID0003EM contains the exact Section 22 signed-short y/x const-member loop with one local RectBounds and GetButtonRect source call. The former int/static/x-first/`kEventRects`/`+256` body is retained only as dated pre-callback history.
- Implemented H state: UID0003EM remains intentionally blank; UID00006S now declares `GetButtonRect(short,...) const`, preserves `GetSlotRect(short slot, RectBounds *rect) const`, and declares `HitTestButton(int y,int x) const` with signed-short return exactly once.
- Owner/emitter state remains unchanged. The raw body belongs to `InventoryPane2`, the `InventoryPane.cpp` compilation unit, and exact source position `320`.
- Resolved blockers: raw argument order, member/static classification, return width, source helper factorization, switch-table lowering, exact button geometry, callee identities, no-direct-xref liveness interpretation, declaration placement, generated source, and shared UID0003EL header compatibility are all implemented and verified.
- Dated pre-callback generated receipt: validator command `000000024453`, refreshed `2026-08-15T21:52:19-04:00`, produced stale CPP SHA256 `23EC72347D29D6D851786F11567AB6E0F99553036325B7D07DAF437897543423` and H SHA256 `B20C6A548B70DF82BE8833C5F62FE91BB5CF92A14FDF52B5D23C5C18F818D5BB`. Those identities document the rejected source only and are not current authority.
- Dated post-callback generated receipt: validator-owned command `000000024544`, refreshed `2026-08-15T23:39:20-04:00`, produced `InventoryPane.cpp` SHA256 `4ADE2663F41E3E9921E932EAB8B9636E6920991DF3F1DB293E39CB4B0E421BB6`, 23,535 bytes / 774 lines, and `InventoryPane.h` SHA256 `923E5621B8C35D1B8C9DA5FCFC12596AA58CBE461D961D80868A5314937E5C24`, 2,408 bytes / 76 lines. Current generated authority remains validator-owned and must be reread dynamically at later gates.
- Dated supervisor coverage receipt: `SUPERVISOR_COVERAGE_PASSED` for C39-C40. `by-memory/-coverage-report.md` SHA256 `AA23C646B3D531F70642D20054E67CD59B466B265E928A83B04DD4E94DF4DF70`, 2,275,465 bytes / 5,068 lines, contains merged UID0002SV detail followed by exactly one UID0003EJ, UID0003EL, UID0003EM, and UID0003EN row in address order.
- Dated supervisor IDA receipt: `GATE2B_PASSED` for I01-I02 with every protected no-change field exact. No IDA mutation, backup, or save was required; canonical disk remained SHA256 `D6EF0A13A878558E0C79F225439D7C2778BB86C040093EF26EEE4034FA3849EF`, 143,208,000 bytes.
- Related target/support docs checked: UID0003EM, UID00006S, UID0002SV, UID0003EJ, UID0003EL and B006's matching report, UID0003EN, UID00048U, UID00015S, UID00018J, UID0000KA, UID00051H, UID0004Q7, UID0003RH, manual by-memory/class/file coverage, generated memory coverage/research tracker, and the matching executed UID0000KA report.
- Current artifact/lifecycle status: the current report path and validator-owned status/history metadata are authoritative; this body is lifecycle-neutral.

## Executive Recommendation

- UID0003EM remains attached to UID00006S and UID0000KA; no new owner, free-helper page, static-data child, or second source file was created.
- The implemented source-facing method is a non-static const member with compiler-derived `__thiscall`, signed-short return, and `(y,x)` argument order. The raw target's switch/table is documented as compiler-inlined GetButtonRect lowering, not a handwritten rectangle array.
- The approved address-repeatable comment remains exact. The dated supervisor `GATE2B_PASSED` receipt verifies I01/I02 as already-present/no-change dispositions; no IDA mutation, backup, or save was required.
- Supervisor role/disposition: C39-C40 retain exact coverage handoff text plus the dated `SUPERVISOR_COVERAGE_PASSED` receipt, and I01/I02 retain complete no-change contracts plus the dated `GATE2B_PASSED` receipt. Execution/archive authority remains supervisor-only and is authoritative only from the current report path and validator-owned status/history metadata.

## Supervisor Active Recheck

- Trigger: the supervisor archived UID0000KA and reassigned B001 to focused UID0003EM source-quality research with the approved IDA comment already present.
- Split requirement: no new split is required. UID0003EM exactly covers `[0x004ef7a0,0x004ef86d)`; UID0003EN exactly covers successor alignment/table/padding `[0x004ef86d,0x004ef890)`.
- Source-bearing coverage: UID0003EM is the only declared target. Its source body, owner declaration dependency, rectangle helper dependency, inline/caller route, compiler successor, score, documentation destinations, coverage text, and IDA no-change contract are complete in this report.
- Implementation boundary: eight accepted ordinary by-* destinations were changed and scoped-validated; generated CPP/H changed only through validator ownership and were physically reread. Manual coverage, IDA, tracker/audit/catalog, and lifecycle state were not edited.

## Inference Research Guidance Check

- The inference discipline required raw bytes, instruction semantics, ABI cleanup, caller register setup, canonical geometry contracts, adjacent source ownership, and negative route evidence to agree before selecting a source-facing signature.
- Existing assumptions treated as uncertain were the target's `int` return, `(x,y)` order, `static` declaration, static rectangle array, `+256` geometry translation, direct-call expectation, and the notion that a local jump table proves a handwritten switch in this function.
- Direct IDA fact: the raw body has two stack arguments, ignores but ABI-preserves an ECX receiver, ends both exits with `retn 8`, increments/returns a 16-bit loop value, passes `[ebp+8]` as y and `[ebp+0x0c]` as x to `PointInRect`, and has no direct inbound xref.
- Documentation evidence: UID00015S establishes `InitRectBounds` and `PointInRect(y,x,bounds)`; UID00006S/UID0000KA establish class/file routing; UID0003EJ establishes the exact rectangle abstraction; analogous UID0004Q7 establishes the accepted human-source pattern where an out-of-line rectangle helper is inlined into a hit-test switch.
- Inference: the source name, private placement, and `const` qualifier are not present as retail symbols. They are the highest-probability source reconstruction from the complete family evidence.

## Heuristic / Inference Reanalysis And Validation

| Issue | Reanalysis and evidence | Disposition |
| --- | --- | --- |
| Raw start has no function | `lookup_funcs(0x004ef7a0)` returns no function, but 78 contiguous instructions form a complete prologue/body/two epilogues ending at exact `retn 8` boundary. | Source-authored retained raw body; do not create an IDA function. |
| No direct raw-start xref | Inbound code and data xrefs are zero. `InventoryPane2::OnMouseEvent` contains the same button loop and `GetButtonRect`/`PointInRect` chain at `0x004ef030-0x004ef075`, consistent with compiler inlining while retaining an out-of-line member body. | Liveness caveat retained; not a no-code result. |
| Static versus member | Every observed `sub_4EF630` call loads the owning `InventoryPane2` receiver into ECX immediately before `call`, and `sub_4EF630` uses `retn 8`. The target has the same two-argument callee-cleanup form and may legitimately leave ECX unused. | Non-static member, compiler-derived `__thiscall`; reject static helper. |
| Argument order | Target pushes `[ebp+0x0c]` as PointInRect x and `[ebp+0x08]` as y. Event authority and UID00015S independently map event `+0x08` to y and `+0x0c` to x. | Exact `(int y, int x)`. |
| Return width | Loop index is `si`, comparison is `cmp si,4`, hit uses `mov ax,si`, and miss uses `eax=-1`. Adjacent `HitTestSlot` and SelfLookPane2 hit-test families use signed-short semantics. | Exact source return `short`; reject `int`. |
| Rectangle source | Cases are exact `0:(59,259,81,277)`, `1:(112,259,134,277)`, `2:(168,66,185,83)`, `3:(168,84,185,101)`, default all `-1`. | Preserve exact pane/event-local values; reject `322/340` translated values. |
| Static rectangle array | No 64-byte four-RectBounds data object exists after or near the body. The only successor data is a five-dword code-target table. | Reject `kEventRects`; it would invent binary data and hide helper factoring. |
| Switch versus human source | UID0003EJ is independently emitted and called five times with ECX receiver. The target duplicates its exact switch/default and has a distinct local table, matching MSVC inlining. | Human source calls `GetButtonRect`; compiler emits the target-local switch table. |
| Callee names | MCP current names/types and function comments identify `InitRectBounds` and `PointInRect`; security-cookie calls occur on both returns. | Use canonical geometry APIs; omit security support from source. |
| `const` qualifier | No field is read/written; analogous accepted hit-test and adjacent geometry methods are const-qualified. Binary cannot encode the qualifier separately. | Use `const`, mark inferred, retain confidence cap. |
| Direct caller shape | Dated pre-callback generated UID00048U spelled two `HitTestButton(mouseX,mouseY)` calls. Binary cursor-move logic directly tests buttons 2/3 and left-down logic contains the inlined four-button loop; post-callback generated source spells both calls y/x. | Document the optimizer route and y/x contract; do not call either source spelling direct-xref proof. |
| Exact duplicate search | A generic 24-byte cookie/loop prologue occurs at nine addresses, but target-specific case-2 bytes occur only at `0x004ef7ec`; no exact body duplicate exists. | Treat generic matches as a source family, not byte identity. |

- Rejected alternatives: free function, static member, cdecl signature, x-first signature, integer return, static rectangle array, handwritten duplicate switch, source-authored jump-table object, global-coordinate `+256` geometry, function creation in IDA, and no-code/dead-code disposition.
- Remaining uncertainty: the retail source symbol and `const` token cannot be recovered from stripped bytes. This affects confidence by one point but does not block exact behavior, ABI-compatible declaration, ownership, source placement, or formal C++.

## Evidence Standards Used

- Primary evidence: live IDA MCP `idb_list`, `server_health`, `runtime_attestation`, `inspect_items`, `lookup_funcs`, `insn_query`, `decompile`, `get_bytes`, `get_comments`, `xref_query`, and bounded byte-pattern searches.
- Binary checks: complete 205-byte body, independent SHA256, 78-instruction bounded disassembly, stack cleanup, register widths, exact immediates, target-local table bytes/targets, padding bytes, caller-side ECX setup, and outbound callsites.
- Documentation checks: target, class owner, split parent, rectangle helper, compiler successor, mouse handler, RectGeometry owner, compilation unit, aggregate inventory page, manual coverage, generated CPP/H, tracker snapshots, source-family pages, and matching archived report.
- Negative evidence: no function, no inbound raw-start xref, no exact body duplicate, no static rectangle data object, no source-authored reason for security-cookie calls/table/padding, and no evidence for global-coordinate translation.
- Evidence ladder: exact bytes/instructions/types/xrefs outrank generated or historical prose; current canonical by-* contracts corroborate direct facts; source spelling/qualifiers are explicitly labeled inference.

## Evidence Checked

- IDA MCP: enumerated current session before bounded calls; health `status:ok`; Hex-Rays and string cache ready; `auto_analysis_ready:false` recorded as context but did not block valid bounded queries.
- Runtime snapshot: attestation at `2026-08-16T01:59:59.670222+00:00` reported listener/worker/session agreement for the canonical IDB with no errors; this is a dated evidence receipt, not lifecycle authority.
- Raw target: `[0x004ef7a0,0x004ef86d)`, 205 bytes, SHA256 `800405216457402D4E1558484AF61A2AA78968AF38F980EE3D4DB9EF330B9054`.
- Successor items: alignment `[0x004ef86d,0x004ef870)` SHA256 `019F07BFE6BD5747F9F3B65F5A095DB04A0418D5F11C6FEEC58EAFF709860B66`; table `[0x004ef870,0x004ef884)` SHA256 `6FCD267F3BE4A21003EC3BBAF2A03040E1037A54ABCA6CFBCEE4BC152738C740`; padding `[0x004ef884,0x004ef890)` SHA256 `A0D08A155AA4E9AADD5DA959565DE99ACC8DC9DBDA96EC3852DDE76C97330902`.
- Complete body scan: 78 instructions; calls `InitRectBounds` at `0x004ef81d`, `PointInRect` at `0x004ef82a`, and security-cookie check at `0x004ef84c` and `0x004ef862`.
- Exact table scan: `0x004ef870` is `jpt_4EF7C1`, one inbound data xref from `0x004ef7c1`, and five outbound dword targets `0x004ef80c`, `0x004ef7c8`, `0x004ef7da`, `0x004ef7ec`, `0x004ef7fc`.
- Caller/inline scan: decompiled and disassembled UID00048U `0x004eeee0`; checked direct `GetButtonRect` calls and the inline loop at `0x004ef030-0x004ef075`.
- Duplicate scan: generic hit-test prologue at `0x00420a90`, `0x00499870`, `0x004eb1c0`, `0x004ee140`, `0x004ef7a0`, `0x0056e820`, `0x0057cdc0`, `0x0057e760`, and `0x0057f3e0`; target-specific case-2 sequence only at `0x004ef7ec`.
- Generated reads: dated pre-callback command `000000024453` captured the contradicted definition/declaration/call spelling; dated final post-callback command `000000024544` was physically checked for exact definitions, declarations, source order, duplicates, stale patterns, and B006 UID0003EL preservation.
- Dated 2026-08-15 manual coverage read: UID0002SV was stale at by-memory coverage line 2067; UID0003EJ/EM/EN rows were absent; UID00006S and UID0000KA rows were generic enough to remain accurate after the implemented focused corrections. Section 28 preserves the exact supervisor-owned handoff without asserting the coverage file's later state.
- Supervisor coverage verification: command `000000024617` at `2026-08-16T00:20:43-04:00` exited `0`, `ok:1`; only pre-existing missing-reference warnings `00039L` and `0003T6` remained; reference additions were exactly `0003EJ`, `0003EM`, and `0003EN`; the coverage lease was released. The verified file identity is SHA256 `AA23C646B3D531F70642D20054E67CD59B466B265E928A83B04DD4E94DF4DF70`, 2,275,465 bytes / 5,068 lines.
- Supervisor Gate 2B verification: I01 retained its raw one-byte code item, absent function/name/type, blank AR, exact AP, zero inbound xrefs, 205-byte body hash `800405216457402D4E1558484AF61A2AA78968AF38F980EE3D4DB9EF330B9054`, 78 instructions, and protected calls; I02 retained exact `jpt_4EF7C1` data/comment/xrefs and hash `6FCD267F3BE4A21003EC3BBAF2A03040E1037A54ABCA6CFBCEE4BC152738C740`. No save was needed.
- Shared owner-H dependency read: B006 UID0003EL report SHA256 `48219DFA6D851D7A9B58D9B7333AAAF58A0381D573E35D80BAB39A6598E00652`, including C3EL-025/C3EL-036 and its complete owner-H blocks; pre-callback UID0003EL page SHA256 `01C095DFA3C7DF69C89781CB792F4D53CDF2B895E49973DDC644D499ADAD6DBA`; post-B006 verify-only page SHA256 `47607646C48B492D8FF323532BDF109A78A970990D1592E0C24707A19ABC1366`. The evidence and implementation establish `short slot` and one final InitRectBounds; this report takes no UID0003EL score, coverage, or additional-target credit.
- Implementation exclusions: IDA mutation/save, manual coverage edits, generated direct edits, tracker/audit/catalog changes, lifecycle operations, archive movement, and process control were not performed. Scoped validators and generated readback were performed only under the accepted callback.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C01 | 0003EM | Exact source body is `[0x004ef7a0,0x004ef86d)`, 205 bytes, SHA256 `800405216457402D4E1558484AF61A2AA78968AF38F980EE3D4DB9EF330B9054`. | original-proof | MCP bytes and bounded disassembly | UID0003EM IDA Evidence | incorporate | applied |
| C02 | 0003EM | IDA has no function, name, or type at the one-byte code item `[0x004ef7a0,0x004ef7a1)`. | original-proof | inspect_items and lookup_funcs | UID0003EM Status and IDA Evidence | incorporate | applied |
| C03 | 0003EM | The raw start has zero inbound code xrefs and zero inbound data xrefs. | original-proof | xref_query direction-to result | UID0003EM IDA Evidence and score rationale | incorporate | applied |
| C04 | 0003EM | Two 4-byte arguments plus `retn 8` and the family ECX receiver route establish a non-static member ABI with compiler-derived `__thiscall`. | very-strong inference | target epilogues and five UID0003EJ caller sequences | UID0003EM Signature; UID00006S H | incorporate | applied |
| C05 | 0003EM | Argument order is exactly `int y` then `int x`; target passes stack `+0x08` as y and `+0x0c` as x. | original-proof | `0x004ef826-0x004ef82a` and UID00015S contract | UID0003EM Signature and formal CPP | incorporate | applied |
| C06 | 0003EM | Return and loop variable are signed `short`; hit returns `si` through AX and miss returns `-1`. | very strong | `cmp si,4`, `mov ax,si`, miss `eax=-1`, adjacent family | UID0003EM Signature and formal CPP | incorporate | applied |
| C07 | 0003EM | The body uses one stack-local `RectBounds` at `[ebp-0x14]`. | original-proof | complete disassembly and InitRectBounds call | UID0003EM Behavior | incorporate | applied |
| C08 | 0003EM | Button rectangles are exact ids 0 through 3 with values `(59,259,81,277)`, `(112,259,134,277)`, `(168,66,185,83)`, `(168,84,185,101)` and default all `-1`. | original-proof | immediate/switch disassembly | UID0003EM Behavior | incorporate | applied |
| C09 | 0003EM | `0x004b7c50` is canonical `InitRectBounds(RectBounds *,left,top,right,bottom)`. | original-proof | MCP type/decompile/comment and UID00015S | UID0003EM Callees | already-present | already-present |
| C10 | 0003EM | `0x004b7e80` is canonical half-open `PointInRect(int y,int x,const RectBounds *)`. | original-proof | MCP type/decompile/comment and UID00015S | UID0003EM Callees | already-present | already-present |
| C11 | 0003EM | Two security-cookie calls are compiler support caused by the local frame and emit no handwritten source statement. | original-proof | call scan and epilogues | UID0003EM compiler-lowering notes | incorporate | applied |
| C12 | 0003EM | Source behavior scans ids 0 through 3 in order, returns the first containing id, and returns signed `-1` after all miss. | original-proof | loop and branch disassembly | UID0003EM Behavior and formal CPP | incorporate | applied |
| C13 | 0003EN | Successor is exact 3-byte NOP alignment, 20-byte five-target jump table, and 12-byte CC padding with independently recorded hashes. | original-proof | MCP bytes/items/xrefs | UID0003EN Contents and Item Summary | incorporate | applied |
| C14 | 0003EM | The target-local switch table is compiler lowering of an inlined source call to UID0003EJ GetButtonRect. | very strong | exact duplicate switch/default plus analogous UID0004Q7 | UID0003EM Source Contract; UID0003EN | incorporate | applied |
| C15 | 0003EM | A handwritten four-RectBounds static array is invalid because no such data object exists and the observed data is a code-target table. | original-proof | bytes, item classification, negative data search | UID0003EM Historical Assumptions | reject-stale | applied |
| C16 | 0003EM | Current button 2/3 `+256` vertical values are stale; exact raw values are `66..83` and `84..101`. | original-proof | case immediates and UID0003EJ | UID0003EM CPP and history | reject-stale | applied |
| C17 | 0003EM | Formal target CPP is the exact signed-short const member loop in Section 22. | very strong | complete ABI/behavior/source-family synthesis | UID0003EM formal CPP | incorporate | applied |
| C18 | 0003EM | Target formal H remains blank because UID00006S owns the single class declaration. | very strong | emitter route and generated header ownership | UID0003EM formal H rationale | already-present | already-present |
| C19 | 00006S | Complete owner H must declare non-static `void GetButtonRect(short button, RectBounds *rect) const;` and `short HitTestButton(int y, int x) const;` while preserving the shared UID0003EL declaration `void GetSlotRect(short slot, RectBounds *rect) const;`; it must not regress GetSlotRect to stale `int`. | very strong | UID0003EJ ECX/retn ABI; UID0003EM argument/return proof; B006 UID0003EL report and current low-word raw evidence | by-class/InventoryPane2.md complete formal H | incorporate | applied |
| C20 | 0003EJ | Adjacent GetButtonRect CPP should use a short selector, const member, explicit switch, and InitRectBounds rather than a static data array. | very strong | function ABI, callsites, local successor table | UID0003EJ formal CPP and evidence | incorporate | applied |
| C21 | 00048U | OnMouseEvent contains source-equivalent inline use: direct ids 2/3 hover tests and a four-id left-down loop using y at Event `+0x08` and x at `+0x0c`. | original-proof | MCP decompile/disassembly | UID00048U Evidence | incorporate | applied |
| C22 | 0003EM | Zero raw-start xrefs are consistent with full inlining and do not prove dead or compiler-only code. | very strong | UID00048U inline duplicate and retained out-of-line body | UID0003EM liveness and score rationale | incorporate | applied |
| C23 | 0003EM | Address-repeatable comment at `0x004ef7a0` is already exact and must not be duplicated or replaced. | original-proof | get_comments literal readback | UID0003EM IDA handoff | already-present | already-present |
| C24 | 0003EM | No IDA function creation, rename, type application, frame creation, or comment write is recommended. | very strong | raw-item boundaries and exact existing AP | UID0003EM IDA handoff | not-applicable | excluded-with-reason |
| C25 | 0002SV | Parent must retain exact split while describing UID0003EM as signed-short y/x member source and UID0003EN as compiler inlining support. | very strong | complete target and successor audit | UID0002SV range/source-order rows | incorporate | applied |
| C26 | 0003EN | Companion must gain an exact Item Summary and identify its table as GetButtonRect-inlining lowering, not source data. | very strong | item bytes, targets, xref, source abstraction | UID0003EN metadata/prose | incorporate | applied |
| C27 | 0003EM | Target gets full report-level behavior, ABI, geometry, hash, xrefs, history, score, Item Summary, and formal source. | very strong | all report evidence | target document throughout | incorporate | applied |
| C28 | 00006S | Owner class keeps `94/94`, owner/emitter/source route, and method count while correcting only the two dependent declarations and method notes. | very strong | current class inventory plus target/helper evidence | by-class/InventoryPane2.md | incorporate | applied |
| C29 | 0000KA | InventoryPane file page keeps `94/94` and 28-definition inventory while correcting A24/A26 signatures, source shape, and generated expectation. | very strong | current whole-file page and target audit | by-file/InventoryPane.md | incorporate | applied |
| C30 | 00018J | InventoryPanes aggregate keeps range/split ownership but updates UID0003EM target detail and compiler-table relationship. | very strong | parent inventory and exact range audit | UID00018J inventory/source map | incorporate | applied |
| C31 | 00048U | Caller documentation must stop treating generated x-first calls as binary direct-xref evidence and record the exact inlined y/x route. | very strong | zero target xrefs and OnMouseEvent body | UID00048U Evidence and history | incorporate | applied |
| C32 | 00015S | RectGeometry formal contracts already provide exact InitRectBounds and PointInRect definitions needed by the target. | original-proof | current UID00015S formal CPP and MCP types | UID00015S no edit | already-present | already-present |
| C33 | 00051H | Legacy UID00051H is corroborating family evidence only; its stale int/x-first formal signature is not authority for UID0003EM. | very strong | parallel raw skeleton and current legacy page | UID0003EM historical/rejected alternatives | reject-stale | applied |
| C34 | 0003EM | No exact target body duplicate was found; target-specific case-2 bytes occur only at `0x004ef7ec`. | original-proof | bounded find_bytes result | UID0003EM negative evidence | incorporate | applied |
| C35 | 0003EM | Nine generic prologue matches are separately inventoried and rejected as exact duplicates. | original-proof | bounded generic pattern search and lookup_funcs | UID0003EM duplicate inventory | incorporate | applied |
| C36 | 0003EM | Owner `00006S`, emitter `00006S`, position `320`, reconstructable true, and `Nested:0` remain unchanged. | very strong | current routing and exact source body | UID0003EM metadata | already-present | already-present |
| C37 | 0003EM | Score becomes `94/93`; confidence stays below 94 because source spelling and constness are inferred and raw-start inbound xrefs remain zero. | very strong | resolved blockers plus retained uncertainty | UID0003EM metadata/score rationale | incorporate | applied |
| C38 | 0003EM | Item Summary becomes the exact source-ready signed-short y/x loop, helper, first-hit/miss, raw-start, and compiler-successor summary in Section 24. | very strong | complete report synthesis | UID0003EM Item Summary | incorporate | applied |
| C39 | 0002SV | Supervisor coverage reconciliation preserved the merged UID0002SV detail in `by-memory/-coverage-report.md` SHA256 `AA23C646B3D531F70642D20054E67CD59B466B265E928A83B04DD4E94DF4DF70`, 2,275,465 bytes / 5,068 lines. | very strong | `SUPERVISOR_COVERAGE_PASSED`; command `000000024617`, exit `0`, `ok:1` | supervisor-owned by-memory coverage | incorporate | applied |
| C40 | 0003EM | Supervisor coverage reconciliation produced exactly one UID0003EJ, UID0003EL, UID0003EM, and UID0003EN row in address order; reference additions were exactly UID0003EJ/EM/EN and only pre-existing warnings UID00039L/UID0003T6 remained. | very strong | `SUPERVISOR_COVERAGE_PASSED`; command `000000024617`, lease released | supervisor-owned by-memory coverage | incorporate | applied |
| C41 | 0003EM | Generated command `000000024453` CPP/H hashes are a dated pre-callback snapshot showing the stale target definition and declaration, not mutable lifecycle authority. | original-proof | physical generated read and hashes | report evidence; generated files read-only | historicalize | applied |
| C42 | 0003EM | Accepted callback must scoped-validate every changed by-* destination from project-documentation and record command metadata, exit, ok, warnings, hashes, and refresh state. | procedural | workflow and destination set | report Validator Results after callback | incorporate | applied |
| C43 | 0003EM | After fresh validator metadata, generated InventoryPane CPP/H must be physically reread for one corrected definition, one corrected declaration, declaration visibility, source order, no duplicate, and no stale static-array body. | procedural | workflow and generated route | report Validator Results after callback | incorporate | applied |
| C44 | 0003EM | Report has 33 exact headings, exact ledger/checklist twins, only formal C++ fences, lifecycle-neutral role/disposition prose with no mutable assertion about current coverage, Gate 2, execution/archive, or reassignment state, and exactly one terminal `READY_FOR_SUPERVISOR_EXECUTE` marker. | procedural | mechanical report audit | report artifact | incorporate | applied |

- Artifact allocation: `44 checked / 0 unchecked`. C01-C44 are implemented, already present, intentionally excluded, supervisor-verified, or mechanically verified as stated.

## Positive Evidence Summary

- The target is a complete 205-byte helper body with an exact hash, ordinary stack frame, local RectBounds, deterministic four-case geometry, first-hit loop, two cookie-checked returns, and canonical geometry calls.
- The two argument slots are semantically resolved: `[ebp+8]` is y and `[ebp+0x0c]` is x. This agrees with Event layout, direct OnMouseEvent accesses, PointInRect's canonical signature, and adjacent hit-test family conventions.
- The non-static member classification is stronger than static/free alternatives because every out-of-line GetButtonRect call establishes an ECX receiver, both methods use two-argument `retn 8`, and the target source role is class-private.
- UID0003EJ independently emits the exact rectangle abstraction. The target duplicates its full switch/default with a distinct local table, the same accepted inlining pattern documented for UID0004Q7.
- The zero direct xref is counterbalanced by exact source-equivalent inline behavior in UID00048U and by the retained out-of-line body in the same compilation-unit/helper order.

## IDA MCP Facts

- Session: `supervisor_uid0000li_i13rollback_20260815`, canonical IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, active/adopted worker session at evidence time.
- Health: `status:ok`, `NexusTK.exe`, imagebase `0x400000`, Hex-Rays ready, string cache ready with 2068 entries, `auto_analysis_ready:false`; bounded valid queries succeeded.
- Target item: `0x004ef7a0` is one-byte code `[0x004ef7a0,0x004ef7a1)`, name absent, type absent, not contained in an IDA function.
- Target boundary: final hit-path instruction is `retn 8` at `[0x004ef86a,0x004ef86d)`; exact half-open body is `[0x004ef7a0,0x004ef86d)`.
- Target body: 205 bytes, 78 instructions, SHA256 `800405216457402D4E1558484AF61A2AA78968AF38F980EE3D4DB9EF330B9054`.
- Argument/return facts: EBX loads stack `+0x0c`; PointInRect pushes EBX as x and stack `+0x08` as y; loop and return use SI/AX; both exits use `retn 8`.
- Case facts: case dispatch normalizes `button+1`; cases 0/1/2/3 begin at `0x004ef7c8`, `0x004ef7da`, `0x004ef7ec`, `0x004ef7fc`; default begins `0x004ef80c`.
- Callees: `InitRectBounds` at `0x004ef81d`, `PointInRect` at `0x004ef82a`, security-cookie check at `0x004ef84c` and `0x004ef862`.
- Current callee types: `void __cdecl InitRectBounds(RectBounds *,int left,int top,int right,int bottom)` and `bool __cdecl PointInRect(int y,int x,const RectBounds *)`.
- Comments at target: AR absent; AP exactly `Source-authored InventoryPane2 fixed-button hit test retained as raw code; checks four event-space button rectangles and returns -1 on miss.`; FR not applicable; FP not applicable.
- Xrefs at target: inbound code absent; inbound data absent. Internal normal flow starts `0x004ef7a0 -> 0x004ef7a1`; outbound calls and table references remain inside the audited body/dependency set.
- Successor items: `[0x004ef86d,0x004ef870)` unnamed data alignment; `[0x004ef870,0x004ef884)` named data `jpt_4EF7C1`; `[0x004ef884,0x004ef890)` unnamed data padding; successor function `sub_4EF890` begins `0x004ef890`.
- Table comments: AR exactly `jump table for switch statement`; AP absent; FR not applicable; FP not applicable.
- Negative facts: no function frame or locals exist as IDA function metadata for the raw target; no exact duplicate body; no four-RectBounds data array; no external xref to the target start or table tail.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `[0x004ef720,0x004ef794)` | UID0003EL support dependency | source-authored InventoryPane2 slot rectangle member | yes, separate B006 target | UID00006S; split index UID0002SV | implemented by B006 at 92/94 | Shared complete-owner-H dependency only: preserve `GetSlotRect(short slot, RectBounds *rect) const;`, short ABI, unsigned guard, and one final InitRectBounds call; no additional-target or coverage credit in this report. |
| `[0x004ef794,0x004ef7a0)` | UID0000VN `by-memory/-ignored.md` | 12-byte CC predecessor padding | no source | UID0002SV | ignored/100 | Already exact; no edit. |
| `[0x004ef7a0,0x004ef86d)` | UID0003EM target | source-authored `InventoryPane2::HitTestButton` raw body | yes | UID00006S; split index UID0002SV | implemented 94/93 | Formal CPP and metadata implemented; target H blank; owner H declaration corrected and generated output verified. |
| `[0x004ef86d,0x004ef870)` | UID0003EN subrange | 3-byte NOP alignment | compiler-only | UID0002SV | 86/92 page | No source; exact hash retained. |
| `[0x004ef870,0x004ef884)` | UID0003EN subrange | five-entry inlined GetButtonRect switch table | compiler-only | UID0002SV | 86/92 page | No source; exact targets/xref/hash retained. |
| `[0x004ef884,0x004ef890)` | UID0003EN subrange | 12-byte CC padding | compiler-only | UID0002SV | 86/92 page | No source; exact hash retained. |
| `[0x004ef890,0x004ef962)` | UID0003EO sibling | source-authored InventoryPane2 slot hit test | yes | UID00006S; split index UID0002SV | 85/91 | Corroborating signed-short/y-x/member family; no target-report implementation claim. |
| `0x004ef630` | UID0003EJ sibling | source rectangle member and inlining abstraction | yes | UID00006S; split index UID0002SV | 85/91 | Formal CPP/signature support correction implemented, scoped-validated, and confirmed by the final generated readback. |
| `0x004b7c50` | UID00015S | shared InitRectBounds dependency | yes elsewhere | UID0000N2 / emitter UID0000BU | 92/93 | Definition and contract already complete; no edit. |
| `0x004b7e80` | UID00015S | shared PointInRect dependency | yes elsewhere | UID0000N2 / emitter UID0000BU | 92/93 | Definition and y/x half-open contract already complete; no edit. |
| `@__security_check_cookie@4` | compiler/runtime | stack-cookie support on both exits | compiler-covered | none | not applicable | No handwritten source or document destination beyond evidence. |
| `0x004eeee0` body fragment | UID00048U | source-equivalent inlined consumer route | yes | UID00006S; split index UID0002SU | 89/91 | Prose route/order correction implemented and scoped-validated; no direct target call is claimed. |
| `[0x004eb1c0,0x004eb291)` | UID00051H comparison | legacy InventoryPane same structural hit-test family | yes, separate target | UID00006R | 90/92 | Corroborating only; stale signature is not copied. |
| `[0x00486f90,0x00487292)` | UID0004Q7 comparison | accepted member hit test with inlined rectangle-helper switch | yes, separate target | UID00002K | 91/93 | Source-shape precedent only; no edit. |

- Inventory totals: one source-bearing declared target, three exact compiler successor spans, one predecessor padding span, two direct behavioral geometry dependencies, one compiler dependency, one inlined consumer fragment, one adjacent source abstraction, one adjacent return/ABI corroborator, and two source-family comparison bodies.
- Every target-owned item has an explicit source/no-source, ownership, metadata, destination, ledger, and checklist disposition. Generic pattern matches outside this inventory are rejected in Section 15 because they share only a compiler/loop skeleton.

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004ef7a0` | inbound code xrefs: zero; inbound data xrefs: zero | No direct caller or pointer route to the raw start. |
| `0x004ef7a0 -> 0x004ef7a1` | internal fallthrough | Normal first-instruction flow, not an external caller. |
| `0x004ef7c1 -> 0x004ef870` | one data xref | Sole table-base reference from the target switch dispatch. |
| `0x004ef870 -> 0x004ef80c` | table entry 0 | Default and normalized case `-1`. |
| `0x004ef874 -> 0x004ef7c8` | table entry 1 | Button 0 rectangle. |
| `0x004ef878 -> 0x004ef7da` | table entry 2 | Button 1 rectangle. |
| `0x004ef87c -> 0x004ef7ec` | table entry 3 | Button 2 rectangle. |
| `0x004ef880 -> 0x004ef7fc` | table entry 4 | Button 3 rectangle. |
| `0x004ef81d -> 0x004b7c50` | call InitRectBounds | Constructs the local candidate rectangle. |
| `0x004ef82a -> 0x004b7e80` | call PointInRect | Tests y/x against half-open bounds. |
| `0x004ef84c`, `0x004ef862` | calls security-cookie checker | Compiler epilogue support; no source statement. |
| `0x004ef030-0x004ef075` in UID00048U | source-equivalent inlined use | Four-id short loop, member rectangle call at `0x004ef04b`, PointInRect(y,x) at `0x004ef05a`, then actions only for ids 2/3. |
| `0x004eef7b`, `0x004eef88` in UID00048U | calls UID0003EJ with ECX owner | Hover path directly checks button rectangles 2 and 3. |
| `0x004eeda9`, `0x004eedff`, `0x004eef7b`, `0x004eef88`, `0x004ef04b` | all observed UID0003EJ callers | Each loads an InventoryPane2 receiver into ECX before the two-argument `retn 8` member call. |
| Generic prologue matches | `0x00420a90`, `0x00499870`, `0x004eb1c0`, `0x004ee140`, `0x004ef7a0`, `0x0056e820`, `0x0057cdc0`, `0x0057e760`, `0x0057f3e0` | Shared compiler/short-loop hit-test skeleton; not exact target duplicates. |
| Target-specific case-2 bytes | only `0x004ef7ec` | Rejects an exact duplicate-body claim. |

## Documentation Evidence And IDA Status

- Current ordinary docs: UID0003EM now has exact formal CPP, `94/93` metadata, Item Summary, raw hash/ABI/geometry/inlining/history/no-change-IDA evidence; UID0003EJ has the signed-short const-member switch; UID0003EN has exact hashes/xrefs/compiler-lowering disposition; UID00048U records inlined y/x routes and corrected source calls; UID0002SV, UID00018J, UID00006S, and UID0000KA carry the complete split/owner/source-order/generated contract.
- Shared B006 dependency remains intact: UID0003EL ordinary source is `92/94` with logical short, unsigned guard, one final InitRectBounds call, and inlined UID0003EO liveness. UID00006S preserves the exact owner declaration `void GetSlotRect(short slot, RectBounds *rect) const;`; UID0003EL itself was verify-only and was not edited or scored by B001.
- Historical evidence preserved: archived UID0000KA range/hash/comment/ownership facts remain valid. Its source signature/array/translated coordinates are explicitly superseded rather than silently deleted.
- Generated callback receipt: command `000000024544` produced the physically verified CPP/H identities in Current Target State and Section 31. No generated file was edited directly.
- Coverage disposition: Section 28 preserves the exact handoff and dated `SUPERVISOR_COVERAGE_PASSED` receipt. The returned file contains merged UID0002SV detail and exactly one UID0003EJ/EL/EM/EN row in address order; later authority remains the owning coverage file and validator metadata.
- IDA status: the dated supervisor `GATE2B_PASSED` receipt verifies the raw target and jump table unchanged. I01 is already-present and I02 is no-change; no mutation, backup, or save was required.

## Ranked Ownership Analysis

### 1. InventoryPane2 / InventoryPane.cpp

- Evidence for: exact location inside the InventoryPane2 tail island; identical geometry shared with UID0003EJ; OnMouseEvent inline use; class receiver ABI; source order between GetSlotRect and HitTestSlot; existing owner/emitter/vtable/file route.
- Evidence against: no direct inbound xref and no retail symbol at the raw start.
- Decision: retain UID00006S owner/emitter and UID0000KA source file. Inlining explains the route gap without inventing ownership.

### 2. InventoryPane.cpp file-local helper

- Evidence for: no target field accesses and the raw body leaves ECX unused.
- Evidence against: two-argument `retn 8`, member-family receiver setup on UID0003EJ, current class-private helper grouping, and no explicit receiver argument reject ordinary cdecl file-local source.
- Decision: reject. A non-static member may legally leave `this` unused.

### 3. RectBounds geometry module or compiler-only body

- Evidence for: behavioral calls are generic RectBounds helpers; target has zero direct xrefs.
- Evidence against: button ids, exact InventoryPane2 geometry, local source order, and OnMouseEvent inline action use are pane policy. The body is much more than compiler glue.
- Decision: reject generic ownership and no-code classification. UID00015S remains a dependency only.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: none.
- Likely full contents: existing `InventoryPane.cpp` and `InventoryPane.h` route remains authoritative.
- Candidate related items accepted: UID0003EJ source abstraction and UID0003EN compiler successor.
- Candidate related items rejected: static rectangle global, standalone jump-table source, separate geometry module, and new helper file.

## Source Placement

- Recommended placement: private `InventoryPane2` member definition in `NexusTK/ui/inventory/InventoryPane.cpp`, UID0003EM position `320`, after UID0003EL and before UID0003EO.
- Declaration placement: private member declaration in UID00006S's `InventoryPane2` class block in generated `InventoryPane.h`; UID0003EM target H remains blank.
- Dependency placement: UID0003EJ defines the preceding member rectangle abstraction at position `300`; UID00015S remains the sole shared geometry definition.
- Rejected placements: class-static/free helper, RectBounds.cpp, compiler table source, generated file direct edit, and a new compilation unit.
- Remaining uncertainty: exact original access spelling is inferred as private from current class organization; it does not affect behavior or ABI.

## Range / Split / Padding / Reclassification Analysis

- Target code range remains exactly `[0x004ef7a0,0x004ef86d)`. No byte is moved into or out of UID0003EM.
- Predecessor `[0x004ef794,0x004ef7a0)` is twelve `CC` bytes and stays ignored padding.
- `[0x004ef86d,0x004ef870)` is `0f 1f 00`, 3 bytes, SHA256 `019F07BFE6BD5747F9F3B65F5A095DB04A0418D5F11C6FEEC58EAFF709860B66`.
- `[0x004ef870,0x004ef884)` is five little-endian targets, 20 bytes, SHA256 `6FCD267F3BE4A21003EC3BBAF2A03040E1037A54ABCA6CFBCEE4BC152738C740`.
- `[0x004ef884,0x004ef890)` is twelve `CC` bytes, SHA256 `A0D08A155AA4E9AADD5DA959565DE99ACC8DC9DBDA96EC3852DDE76C97330902`.
- UID0003EN remains non-reconstructable/non-emitting. Its table belongs to compiler lowering of the target's inlined GetButtonRect call, not to a static rectangle object.
- UID0002SV remains a mixed, parentless, non-emitting split-audit container. Exact child ownership and source positions remain unchanged.
- No merge, new child, range rename, padding reclassification, table ownership change, or aggregate emitter is justified.

## Negative Evidence Summary

- No IDA function, function name, type, frame, or direct inbound xref exists at `0x004ef7a0`.
- No exact body duplicate exists. The nine generic prologue matches do not share target geometry or whole-body bytes.
- No 64-byte static RectBounds array exists in the successor or nearby data. The dated pre-callback generated `kEventRects` source was therefore decompiler-shaped invention and is absent from the verified post-callback target body.
- No instruction adds 256 to button 2/3 vertical coordinates; values 322/339 and 340/357 are contradicted.
- No source-level call to the target survives in the binary. UID00048U instead carries inline-equivalent logic; generated C++ call spelling is not xref evidence.
- No evidence supports cdecl/static source. Explicit ECX receiver preparation for the shared rectangle member and callee-cleanup ABI reject that route.
- No evidence justifies creating a function in IDA merely to gain a name/type/frame; doing so risks unsupported boundary and xref mutation.
- No generic RectBounds ownership follows from calls to geometry helpers. Pane-specific cases and actions remain InventoryPane2 policy.
- No jump-table, alignment, padding, or security-cookie source should be emitted.

## IDA Rename / Type / Comment Recommendations

No IDA mutation is recommended. The following rows are complete protected current states for Gate 2B readback; there is no endpoint invocation or operational package.

| ID | Entity and literal current prestate | Semantic disposition | Complete expected readback / protections |
| --- | --- | --- | --- |
| I01 | Address `0x004ef7a0`; raw body `[0x004ef7a0,0x004ef86d)`; 205 bytes; body SHA256 `800405216457402D4E1558484AF61A2AA78968AF38F980EE3D4DB9EF330B9054`; item `[0x004ef7a0,0x004ef7a1)` width 1 is code; function absent; name absent; type absent; IDA function frame not applicable; AR absent; AP exactly `Source-authored InventoryPane2 fixed-button hit test retained as raw code; checks four event-space button rectangles and returns -1 on miss.`; FR not applicable; FP not applicable; inbound code xrefs absent; inbound data xrefs absent; internal first flow `0x004ef7a0 -> 0x004ef7a1`; calls at `0x004ef81d`, `0x004ef82a`, `0x004ef84c`, `0x004ef862`. | Already present. Preserve the approved address-repeatable comment; perform no rename, type, function, frame, or comment action. | Function remains absent; name remains absent; type remains absent; frame remains not applicable; AR remains absent; AP remains exactly the literal prestate text; FR remains not applicable; FP remains not applicable; item/range/size/body bytes/hash remain exact; inbound code/data xrefs remain absent; all internal flow and callsites remain unchanged. Any mismatch stops the handoff. |
| I02 | Address `0x004ef870`; item `[0x004ef870,0x004ef884)` width 20 is data; name exactly `jpt_4EF7C1`; type absent; AR exactly `jump table for switch statement`; AP absent; FR not applicable; FP not applicable; bytes exactly `0c f8 4e 00 c8 f7 4e 00 da f7 4e 00 ec f7 4e 00 fc f7 4e 00`; SHA256 `6FCD267F3BE4A21003EC3BBAF2A03040E1037A54ABCA6CFBCEE4BC152738C740`; inbound data xref exactly `0x004ef7c1 -> 0x004ef870`; outbound data targets exactly `0x004ef80c`, `0x004ef7c8`, `0x004ef7da`, `0x004ef7ec`, `0x004ef7fc`; inbound code xrefs absent. | No change recommended. Existing compiler-table identity/comment are sufficient. | Name/type/item/range/width/bytes/hash remain exact; AR remains exact; AP remains absent; FR remains not applicable; FP remains not applicable; one inbound and five outbound data xrefs remain exact; no code xref or source-authored data identity is created. Any mismatch stops the handoff. |

- Supervisor no-change receipt: `GATE2B_PASSED`. I01 remained unnamed/untyped one-byte raw code with no function, blank AR, exact existing AP, zero inbound xrefs, exact 205-byte hash `800405216457402D4E1558484AF61A2AA78968AF38F980EE3D4DB9EF330B9054`, 78 instructions, and exact protected calls. I02 remained exact 20-byte `jpt_4EF7C1` data with blank type, AR `jump table for switch statement`, blank AP, hash `6FCD267F3BE4A21003EC3BBAF2A03040E1037A54ABCA6CFBCEE4BC152738C740`, one inbound and five exact outbound data xrefs, and no code xref.
- Save disposition: no IDA mutation, backup, or save was required. Canonical disk remained SHA256 `D6EF0A13A878558E0C79F225439D7C2778BB86C040093EF26EEE4034FA3849EF`, 143,208,000 bytes.
- Dependency state outside the action table: `InitRectBounds` and `PointInRect` current names/types/function comments are already sufficient and receive no Gate 2B action.
- Negative constraints: do not define a function at the target; do not apply a signature or stack frame; do not rename the raw item or table; do not add/replace any comment; do not modify bytes, item boundaries, table targets, xrefs, alignment, or padding.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. The body, ABI, return semantics, geometry, dependencies, ownership, source order, and human-source factoring are resolved.
- Target CPP block disposition: replace UID0003EM formal CPP with the following exact block.

```cpp
short InventoryPane2::HitTestButton(int y, int x) const
{
    RectBounds bounds;
    for (short button = 0; button < 4; ++button)
    {
        GetButtonRect(button, &bounds);
        if (PointInRect(y, x, &bounds))
            return button;
    }
    return -1;
}
```

- Target H block disposition: keep UID0003EM formal H blank because UID00006S owns the sole class declaration.
- Required UID0003EJ formal CPP support replacement:

```cpp
void InventoryPane2::GetButtonRect(short button, RectBounds *rect) const
{
    switch (button)
    {
    case 0:
        InitRectBounds(rect, 59, 259, 81, 277);
        break;
    case 1:
        InitRectBounds(rect, 112, 259, 134, 277);
        break;
    case 2:
        InitRectBounds(rect, 168, 66, 185, 83);
        break;
    case 3:
        InitRectBounds(rect, 168, 84, 185, 101);
        break;
    default:
        InitRectBounds(rect, -1, -1, -1, -1);
        break;
    }
}
```

- Required UID00006S formal H replacement, preserving every unrelated declaration and field and merging the independently evidenced B006 UID0003EL correction. The complete block must retain `GetSlotRect(short slot, RectBounds *rect) const;`; UID0003EL remains a support dependency rather than an additional target of this report:

```cpp
class InventoryPane2 : public PanelPane
{
public:
    InventoryPane2();
    virtual ~InventoryPane2();

    virtual void OnActivate(const unsigned char *packetData);
    virtual void OnPaint();
    virtual bool OnKeyEvent(Event *event);
    virtual bool OnMouseEvent(Event *event);
    virtual bool OnServerMessage(Event *message);

private:
    void PlayItemEffect();
    void SendUseItemSlotPacketRaw(unsigned char slot);
    void SendDragDropItemPacketRaw(unsigned char slot, unsigned char dragSource);
    void GetButtonRect(short button, RectBounds *rect) const;
    void GetSlotRect(short slot, RectBounds *rect) const;
    short HitTestButton(int y, int x) const;
    int HitTestSlot(int x, int y) const;
    static int VisibleOrdinalToInventorySlot(int ordinal);

    unsigned char m_pageIndex;
    bool m_isLastPage;
    unsigned char m_reservedFA[2];
    int m_viewMode;
    int m_unusedState;
    int m_listButtonState;
    int m_gridButtonState;
};

#endif
```

- Behavior preservation: the target loop produces the observed signed-short induction/return, local RectBounds, first-hit semantics, and y/x PointInRect call. Inlining the switch-bearing UID0003EJ member explains the target's second table without source duplication.
- Source-shape rationale: a private rectangle helper plus private hit-test loop is the established project and analogous mid-2000s C++ shape; static arrays, jump-table declarations, raw addresses, and cookie mechanics are compiler/decompiler artifacts.
- Third-party import: not applicable; this is reconstructed first-party C++.

## Final Recommendation

- Ordinary implementation is complete for C01-C38 and C41-C43; C44 post-implementation report mechanics are also complete. The dated supervisor receipt verifies C39-C40 applied with exact merged coverage order and identity, yielding 44/44 checked claims.
- UID0003EM is `94/93` with full Item Summary/evidence/history, exact CPP block, blank H rationale, and unchanged owner/emitter/position.
- UID00006S remains `94/94` with corrected GetButtonRect and HitTestButton declarations, B006's independently evidenced `void GetSlotRect(short slot, RectBounds *rect) const;` declaration, and all other methods/fields/source routing preserved.
- UID0003EL: support dependency only. Preserve its `short` owner-H contract from the dated B006/current-evidence receipt without declaring it as an additional target or claiming its score/coverage work.
- UID0003EJ keeps ownership/position and now carries the exact const-member switch source; its rectangle evidence remains valid. UID0003EN stays non-reconstructable/non-emitting with exact compiler-inlining hashes/xrefs.
- UID0002SV, UID0000KA, UID00018J, and UID00048U now carry the exact target signature/source-shape/inlined-route corrections without loss of valid inventory or unrelated source.
- UID00015S: no edit; its current formal geometry contracts already satisfy the target.
- Items left non-emitting: predecessor padding, UID0003EN alignment/table/padding, and security-cookie support.
- Future work outside this assignment: legacy UID00051H and other generic hit-test family members may deserve separate focused signature audits; none is used to weaken or defer the resolved UID0003EM contract.

## Recommended Target Doc Changes

- Target path: `by-memory/0x004ef7a0-0x004ef86d.InventoryPane2ButtonHitTestRaw.md`.
- Metadata: `COMPLETION:94`, `CONFIDENCE:93`; owner `00006S`, reconstructable true, emitter `00006S`, position `320`, `Nested:0` unchanged.
- Item Summary exact value: `Source-ready signed-short InventoryPane2 button hit test: scans ids 0 through 3, obtains each rectangle through GetButtonRect, applies half-open PointInRect(y,x), returns the first hit or -1; exact raw-body hash/no-function/zero-inbound-xref evidence and compiler-only switch successor are preserved.`
- Formal CPP is the Section 22 target block. Formal H remains blank with UID00006S declaration ownership rationale.
- Implemented at report depth: exact range/hash/instruction count; ABI and y/x order; signed-short loop/return; local RectBounds; all cases/default; exact callees/callsites; inline route; successor bytes/hashes/targets/xref; owner/source placement; score cap; IDA no-change contract.
- Historicalized: pre-callback `int x,y`, static status, static kEventRects array, translated button 2/3 coordinates, and generated direct-call assumptions remain explicitly labeled rejected hypotheses.

## Recommended Support Doc Changes

| Support path | Exact facts to incorporate | Metadata/source disposition |
| --- | --- | --- |
| `by-class/InventoryPane2.md` UID00006S | Implemented corrected GetButtonRect and HitTestButton declarations; preserved the B006-evidenced `void GetSlotRect(short slot, RectBounds *rect) const;` declaration; recorded signed-short y/x target and inlined helper lowering; preserved all 15 methods, fields, bounds route, and compiler exclusions. | Score `94/94`, owner/emitter, class layout, source route unchanged; complete formal H matches Section 22. |
| `by-memory/0x004ef630-0x004ef702.InventoryPane2ButtonRectHelper.md` UID0003EJ | Implemented ECX receiver/five-caller, two-argument `retn 8`, signed-short selector, explicit switch/default, and exact four-rectangle evidence; replaced static-array formal source. | `85/91`, owner `00006S`, position `300`; formal CPP is Section 22 support block. |
| `by-memory/0x004ef720-0x004ef794.InventoryPane2SlotRectBuilderRaw.md` UID0003EL | Verify-only shared owner-H dependency: B006's implemented raw evidence requires `void GetSlotRect(short slot, RectBounds *rect) const;`, which the complete UID00006S H replacement preserves. | B006 independently implemented UID0003EL at `92/94`; B001 made no UID0003EL ordinary edit, score change, coverage claim, or additional-target declaration. |
| `by-memory/0x004ef86d-0x004ef890.InventoryPane2ButtonHitTestSwitchTableAndPadding.md` UID0003EN | Implemented exact Item Summary, per-span hashes, one inbound/five outbound data xrefs, and compiler-inlined GetButtonRect relationship. | `86/92`, owner none, reconstructable false, non-emitting, blank CPP/H. |
| `by-memory/0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor.md` UID0002SV | Preserved complete split; revised target row to signed-short y/x const member and successor row to compiler inlining support; retained no aggregate source and all B006 detail. | `89/92`, owner none, reconstructable false, blank CPP/H. |
| `by-memory/0x004eeee0-0x004ef290.InventoryPane2OnMouseEvent.md` UID00048U | Implemented exact inline route at `0x004ef030-0x004ef075`, direct hover checks of ids 2/3, Event y/x offsets, corrected y/x formal calls, and binary-direct-xref rejection. | `89/91`; owner/emitter/position and unrelated formal behavior unchanged. |
| `by-file/InventoryPane.md` UID0000KA | Implemented A20/A24/A26 behavior/signature/source-shape/generated expectations and preserved 28-definition inventory, full source route, B006 A25 evidence, all unrelated detail, and scores. | `94/94`; generated files changed only through validator ownership. |
| `by-memory/0x004ea130-0x004efbb7.InventoryPanes.md` UID00018J | Implemented target inventory row, exact geometry, and tail compiler-table relationship; preserved aggregate boundaries/exclusions. | Score/owner/emitter unchanged. |
| `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md` UID00015S | No edit: exact InitRectBounds and PointInRect definitions/types are already present. | `92/93` unchanged. |
| Manual `by-memory/-coverage-report.md` | Replace stale UID0002SV row and insert exact UID0003EJ/EM/EN rows from Section 28. | Supervisor-owned manual edit only. |

## Score And Metadata Recommendation

- Historical pre-callback target: `85/88`, owner/emitter UID00006S, position `320`, reconstructable true, blank Item Summary.
- Implemented target: `94/93`; owner/emitter/position/reconstructable/Nested unchanged; exact Item Summary and formal CPP populated; target H blank.
- Completion increase rationale: range/hash, ABI, argument order, return width, local type, complete behavior, all rectangles/default, callee contracts, table/padding split, inlined route, human source shape, declaration route, coverage text, and no-change IDA contract are now closed.
- Confidence rationale: direct instructions and current canonical contracts are decisive. Confidence remains 93 because no retail symbol or direct target xref proves the chosen method spelling/const token, even though class/source-family evidence is very strong.
- Reason not lower: no behavior, data, range, ownership, source-placement, or formal-source blocker remains.
- Reason not higher: stripped identity and constness are inference; zero inbound target xrefs remain an explicit liveness caveat.
- Support scores: UID00006S `94/94`, UID0003EJ `85/91`, UID0003EN `86/92`, UID0002SV `89/92`, UID00048U `89/91`, UID0000KA `94/94`, UID00018J current score all unchanged.

## Open Questions With Attempted Resolution

| Question | Evidence checked | Resolution and impact |
| --- | --- | --- |
| Is the helper static/free or a member? | Target cleanup, five GetButtonRect caller ECX loads, class/source order, absence of explicit receiver argument. | Non-static member is strongest and ABI-compatible. Static/free rejected. |
| Is argument order x/y or y/x? | Exact pushes, Event offsets, UID00015S type/comment, UID00048U direct calls. | Resolved exactly as y then x. |
| Is return int or short? | SI loop, AX return, -1 path, adjacent/similar helpers. | Resolved as signed short. |
| Are button 2/3 y values translated by +256? | Exact immediates in target and UID0003EJ, PointInRect inputs, no add instruction. | No. Exact values are 66/83 and 84/101. |
| Is the source a static rectangle array or switch/helper call? | Successor item type/bytes, absence of array data, independently emitted UID0003EJ, analogous UID0004Q7. | Source calls GetButtonRect; compiler inlines switch. |
| Why is there no direct caller? | Full UID00048U decompile/disassembly and exact inline loop. | Inlining explains the source-equivalent use; retain zero-xref confidence cap. |
| Is `const` exact? | No writes, adjacent geometry declarations, accepted hit-test family style. | Highest-probability inferred qualifier; ABI unaffected; one-point confidence cap. |
| Should IDA define/name/type the raw body? | No function object, no xrefs, exact current comment, split boundaries. | No; protected no-change is safer and fully documents semantics. |

- Unresolved retail evidence: original PDB/source spelling and explicit const/access tokens are unavailable. No reasonable bounded current evidence can recover them. This does not block the formal source because the chosen form is behaviorally exact and ABI-compatible.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Dated 2026-08-15 callback inspection set: `by-memory/-coverage-report.md`, `by-class/-coverage-report.md`, and `by-file/-coverage-report.md`.
- At that read, by-class UID00006S and by-file UID0000KA rows were accurate at their generic scope and required no focused text change.
- The exact supervisor-owned UID0002SV replacement text derived from that read, positioned after the UID0000VN `0x004ef62e-0x004ef630` padding row, is:

>         - [UID:0002SV][0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor](by-memory/0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor.md) 0x004ef630-0x004efa95 | method/helper-group | InventoryPane2TailHelpersAndDestructor : not_reconstructable : 89% : very strong : Final non-emitting split-audit container with five authored InventoryPane2 tail helpers at positions 300-340, exact raw/no-function retention, signed-short y/x button hit-test source, compiler-inlined rectangle switches/tables, complete padding and adjustor ownership, and UID0003ER scalar-delete compiler support; exact children emit through UID00006S while this mixed parent emits no aggregate C++.

- The exact supervisor-owned child rows derived from that read, positioned immediately below the UID0002SV replacement in address order, are:

>             - [UID:0003EJ][0x004ef630-0x004ef702.InventoryPane2ButtonRectHelper](by-memory/0x004ef630-0x004ef702.InventoryPane2ButtonRectHelper.md) 0x004ef630-0x004ef702 | member rectangle helper | InventoryPane2ButtonRectHelper : reconstructable : 85% : very strong : Exact const InventoryPane2 member rectangle helper with signed-short button selector, four explicit switch cases, all-minus-one default, InitRectBounds writes, five ECX-receiver callers, compiler switch successor, formal CPP at position 300, and no invented static rectangle array.
>
>             - [UID:0003EM][0x004ef7a0-0x004ef86d.InventoryPane2ButtonHitTestRaw](by-memory/0x004ef7a0-0x004ef86d.InventoryPane2ButtonHitTestRaw.md) 0x004ef7a0-0x004ef86d | raw member hit-test helper | InventoryPane2ButtonHitTestRaw : reconstructable : 94% : very strong : Source-ready signed-short InventoryPane2 HitTestButton(y,x) const member with exact 205-byte hash, zero raw-start inbound xrefs, four-id first-hit loop, GetButtonRect inlining proof, canonical half-open PointInRect contract, exact local geometry, -1 miss, position 320 formal CPP, owner declaration route, and protected existing IDA comment.
>
>             - [UID:0003EN][0x004ef86d-0x004ef890.InventoryPane2ButtonHitTestSwitchTableAndPadding](by-memory/0x004ef86d-0x004ef890.InventoryPane2ButtonHitTestSwitchTableAndPadding.md) 0x004ef86d-0x004ef890 | compiler table and padding | InventoryPane2ButtonHitTestSwitchTableAndPadding : not_reconstructable : 86% : very strong : Exact three-byte NOP alignment, five-target GetButtonRect-inlining switch table with one local inbound data xref, and twelve CC bytes before HitTestSlot; compiler-generated, non-emitting, and covered by UID0003EM source.

- Generated tracker and generated coverage are validator-owned outputs; this report supplies no handwritten row text for them, and their state is authoritative from the generated artifacts and validator metadata.
- Supervisor reconciliation receipt: `SUPERVISOR_COVERAGE_PASSED`. `by-memory/-coverage-report.md` SHA256 `AA23C646B3D531F70642D20054E67CD59B466B265E928A83B04DD4E94DF4DF70`, 2,275,465 bytes / 5,068 lines, contains merged UID0002SV detail and exactly one UID0003EJ, UID0003EL, UID0003EM, and UID0003EN row in address order. Command `000000024617` at `2026-08-16T00:20:43-04:00` exited `0`, `ok:1`; only pre-existing warnings UID00039L/UID0003T6 remained, reference additions were UID0003EJ/EM/EN, and the lease was released.
- Role boundary: B001 did not edit supervisor-owned manual coverage. This section preserves both the exact handoff text and dated supervisor result; later authority remains the coverage file and validator metadata.

## Follow-Up Actions

- Artifact-review disposition: this report, the eight changed ordinary pages, validator receipts, and generated readback form the bounded evidence set for any supervisor Gate 1/Gate 2A audit; gate status is authoritative from the supervisor audit record, not this prose.
- Ordinary implementation and scoped validation are complete; no generated file was directly edited.
- Dated callback receipt: generated command `000000024544` was physically reread for exact definitions/declarations, declaration visibility, source order, no duplicate, B006 A25 preservation, and no stale UID0003EM kEventRects body.
- Coverage role: Section 28 preserves exact supervisor-owned replacement/insertion text and the dated `SUPERVISOR_COVERAGE_PASSED` receipt for C39-C40; later coverage authority remains the owning file and validator metadata.
- IDA role: I01/I02 remain already-present/no-change protected-state contracts, with the dated `GATE2B_PASSED` receipt confirming exact readback and no mutation, backup, or save.
- Lifecycle role: execution/archive authority remains supervisor-only and is authoritative only from the report's current path plus validator-owned status/history metadata; B001 performed no lifecycle action in this reconciliation.
- A-agent action: none identified.
- Agent-assignment role: current B001 work is authoritative only from the current goal and lease state. Supervisor policy governs immediate same-agent reassignment after lifecycle completion; this report neither delays reassignment nor predicts a particular next target.

## Confidence

- Recommendation confidence: `93/100`.
- Score confidence: very strong for `94/93` under current evidence.
- Directly proved: range, size, bytes/hash, item boundaries, no-function state, inbound xref absence, instructions, stack slots, y/x order, short loop/return, rectangles, calls, table/padding, comments, and source-equivalent inline route.
- Inferred but strongly constrained: `HitTestButton` retail spelling, private access, and const qualifier.
- Remaining uncertainty does not affect behavior, ownership, emitter route, source position, split, formal target body, or IDA no-change disposition.

## Validator Results

- Exact callback cwd for every scoped file command: `E:\NTK\GhidraBridge\source-3\project-documentation`; validator-reported canonical root: `C:\FastStorage\NTK_Sources\source-3\project-documentation`.

| Destination | Exact single-line command | command_id / timestamp | Exit / ok | Literal warnings or errors | Generated state / material side effects |
| --- | --- | --- | --- | --- | --- |
| UID0003EM | `python .\tools\validator.py --mode file --file by-memory/0x004ef7a0-0x004ef86d.InventoryPane2ButtonHitTestRaw.md --apply --queue-timeout 240` | `000000024512`; `2026-08-15T23:15:19-04:00` | `0` / `1` | `missing_ref_uid 0003EN` twice; errors absent | deferred; completion/confidence to `94/93`, three UID-link normalizations, four reference additions, registry/stats side effects. |
| UID0003EJ | `python .\tools\validator.py --mode file --file by-memory/0x004ef630-0x004ef702.InventoryPane2ButtonRectHelper.md --apply --queue-timeout 240` | `000000024514`; `2026-08-15T23:16:21-04:00` | `0` / `1` | warnings absent; errors absent | deferred; registry/reference/stats side effects. |
| UID0003EN | `python .\tools\validator.py --mode file --file by-memory/0x004ef86d-0x004ef890.InventoryPane2ButtonHitTestSwitchTableAndPadding.md --apply --queue-timeout 240` | `000000024516`; `2026-08-15T23:17:07-04:00` | `0` / `1` | warnings absent; errors absent | deferred; new UID mapping plus completion/confidence/owner/registry/reference/stats side effects. |
| UID00048U | `python .\tools\validator.py --mode file --file by-memory/0x004eeee0-0x004ef290.InventoryPane2OnMouseEvent.md --apply --queue-timeout 240` | `000000024517`; `2026-08-15T23:17:45-04:00` | `0` / `1` | warnings absent; errors absent | deferred; registry/stats side effects. |
| UID00018J | `python .\tools\validator.py --mode file --file by-memory/0x004ea130-0x004efbb7.InventoryPanes.md --apply --queue-timeout 240` | `000000024518`; `2026-08-15T23:18:43-04:00` | `0` / `1` | warnings absent; errors absent | deferred; three projected-stats row updates. |
| UID00006S initial merge | `python .\tools\validator.py --mode file --file by-class/InventoryPane2.md --apply --queue-timeout 240` | `000000024525`; `2026-08-15T23:20:35-04:00` | `0` / `1` | warnings absent; errors absent | deferred; registry/stats side effects. |
| UID0002SV | `python .\tools\validator.py --mode file --file by-memory/0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor.md --apply --queue-timeout 240` | `000000024528`; `2026-08-15T23:22:04-04:00` | `0` / `1` | `missing_ref_uid` for `0003EK`, `0003EQ`, `0003ES`, and `0003ET`, each twice; errors absent | deferred; stats side effects; warnings are pre-existing registry omissions and did not block `ok:1`. |
| UID0000KA owning route | `python .\tools\validator.py --mode file --file by-file/InventoryPane.md --apply --queue-timeout 240` | `000000024531`; `2026-08-15T23:24:04-04:00` | `0` / `1` | warnings absent; errors absent | deferred; owning route/stats refresh. |
| UID00006S first bounded post-B006 spelling reconciliation | `python .\tools\validator.py --mode file --file by-class/InventoryPane2.md --apply --queue-timeout 240` | `000000024534`; `2026-08-15T23:26:05-04:00` | `0` / `1` | warnings absent; errors absent | deferred; class/stats refresh. B006's `short`/one-call semantics remained intact; a later delayed shared-file write restored only the `bounds` spelling, requiring the final row below. |
| UID00006S final stable spelling reconciliation | `python .\tools\validator.py --mode file --file by-class/InventoryPane2.md --apply --queue-timeout 240` | `000000024544`; `2026-08-15T23:39:20-04:00` | `0` / `1` | warnings absent; errors absent | deferred; registry/stats refresh. After three stable hash checks and no active shared lease, owner-H output spelling is `rect`; all B006 short/unsigned-guard/one-final-InitRectBounds evidence remains unchanged. |

- Supervisor-owned coverage validator receipt, not a B001 command: command `000000024617` at `2026-08-16T00:20:43-04:00` exited `0`, `ok:1`; only pre-existing missing-reference warnings `00039L` and `0003T6` remained; the three reference additions were `0003EJ`, `0003EM`, and `0003EN`; the coverage lease was released. The exact invocation string was not included in the returned evidence and is not inferred here.
- Final queue observation `000000024545` at `2026-08-15T23:39:47-04:00` reported zero queued/processing ordinary or generated-refresh jobs. It was an inspection, not a scoped file validation receipt.
- Final generated readback is a dated validator-owned receipt for command `000000024544` / refreshed `2026-08-15T23:39:20-04:00`: `InventoryPane.cpp` SHA256 `4ADE2663F41E3E9921E932EAB8B9636E6920991DF3F1DB293E39CB4B0E421BB6`, 23,535 bytes / 774 lines; `InventoryPane.h` SHA256 `923E5621B8C35D1B8C9DA5FCFC12596AA58CBE461D961D80868A5314937E5C24`, 2,408 bytes / 76 lines.
- Physical CPP readback: exactly one UID0003EJ definition at line 680, one B006 UID0003EL definition at line 703 with one final InitRectBounds call at line 734, one UID0003EM definition at line 738, and UID0003EO next at line 751; UID00048U has exactly two y/x calls at lines 552 and 581. UID0003EM has no duplicate, `kEventRects`, `+256` rectangle body, or empty marker.
- Physical H readback: InventoryPane2 has exactly one `GetButtonRect(short button, RectBounds *rect) const;` at line 61, one `GetSlotRect(short slot, RectBounds *rect) const;` at line 62, and one signed-short `HitTestButton(int y, int x) const;` at line 63. Legacy InventoryPane declarations are separate class-owned source and are not UID0003EM stale duplicates.
- Current generated truth remains validator-owned and must be reread dynamically at each later supervisor gate; the identities above are callback-time receipts, not permanent lifecycle authority.

## Changed Files

- Same report updated in place: `tools/leaser/Agents/Agent-B001/research/0003EM-InventoryPane2ButtonHitTestRaw-source-quality.md`; exact post-write report identity is returned out of band to avoid a self-referential hash.

| Changed ordinary destination | Final SHA256 | Bytes | Physical lines |
| --- | --- | ---: | ---: |
| `by-memory/0x004ef7a0-0x004ef86d.InventoryPane2ButtonHitTestRaw.md` | `23168F8AD91D0E650D219CAF38F9E1E501C255A69E5F550C391F13E685047108` | 10,666 | 100 |
| `by-memory/0x004ef630-0x004ef702.InventoryPane2ButtonRectHelper.md` | `BB05F9168D0C42F1C0ADA13FF56E2683DAFE19C20E643B1938A8C6392A0D6D14` | 7,263 | 94 |
| `by-memory/0x004ef86d-0x004ef890.InventoryPane2ButtonHitTestSwitchTableAndPadding.md` | `0E468C40B639A1647F350CA72F1A34E52AD83898C4D145243CB1A4F0A20F2E1F` | 5,534 | 62 |
| `by-memory/0x004eeee0-0x004ef290.InventoryPane2OnMouseEvent.md` | `010291B9C536E7BBFB401824030B2F1FFDBFEDD898B3DDCE720B66FE951EDCF1` | 9,009 | 131 |
| `by-class/InventoryPane2.md` | `0998E1EB1FAF43131984B81B3E5EE0C6981A782F7BC99E738EDF79A8DD140CA4` | 32,815 | 201 |
| `by-memory/0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor.md` | `A4B8C4501797652E47B905A7417190093047A49DA6EA0DC71F2DB27409637187` | 37,178 | 217 |
| `by-file/InventoryPane.md` | `FEF7F7F7D63C7C367929E36F2E1B938A46A6A5847C75D66487B3CED48CF095EA` | 78,648 | 482 |
| `by-memory/0x004ea130-0x004efbb7.InventoryPanes.md` | `C17A20CA893E0FD09F67EC7029861E07BBD27C87B5092E0919EEA2847C98C37A` | 68,000 | 445 |

- Supervisor-owned reconciliation artifact, not edited by B001: `by-memory/-coverage-report.md` SHA256 `AA23C646B3D531F70642D20054E67CD59B466B265E928A83B04DD4E94DF4DF70`, 2,275,465 bytes / 5,068 lines; command `000000024617` verified merged UID0002SV detail plus exactly one UID0003EJ/EL/EM/EN row in address order.
- Read-only B006 dependency: UID0003EL final SHA256 `47607646C48B492D8FF323532BDF109A78A970990D1592E0C24707A19ABC1366`, 11,886 bytes / 128 lines. B001 did not edit or score it.
- Validator-owned generated side effects are the CPP/H receipts above; they were never edited directly. B001 did not edit manual coverage, IDA, tracker/audit/catalog, goal/notes, or lifecycle files; the coverage identity above is the supervisor-returned artifact.
- Dated B001 callback side effects: B001 did not rename, move, or archive the report and did not run `execute_report` or another lifecycle command. Any later execution/archive state is supervisor-owned and authoritative only from the report's current path plus validator-owned status/history metadata.

## Implementation Tracking Checklist

| Done | Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| [x] | C01 | 0003EM | Exact source body is `[0x004ef7a0,0x004ef86d)`, 205 bytes, SHA256 `800405216457402D4E1558484AF61A2AA78968AF38F980EE3D4DB9EF330B9054`. | original-proof | MCP bytes and bounded disassembly | UID0003EM IDA Evidence | incorporate | applied |
| [x] | C02 | 0003EM | IDA has no function, name, or type at the one-byte code item `[0x004ef7a0,0x004ef7a1)`. | original-proof | inspect_items and lookup_funcs | UID0003EM Status and IDA Evidence | incorporate | applied |
| [x] | C03 | 0003EM | The raw start has zero inbound code xrefs and zero inbound data xrefs. | original-proof | xref_query direction-to result | UID0003EM IDA Evidence and score rationale | incorporate | applied |
| [x] | C04 | 0003EM | Two 4-byte arguments plus `retn 8` and the family ECX receiver route establish a non-static member ABI with compiler-derived `__thiscall`. | very-strong inference | target epilogues and five UID0003EJ caller sequences | UID0003EM Signature; UID00006S H | incorporate | applied |
| [x] | C05 | 0003EM | Argument order is exactly `int y` then `int x`; target passes stack `+0x08` as y and `+0x0c` as x. | original-proof | `0x004ef826-0x004ef82a` and UID00015S contract | UID0003EM Signature and formal CPP | incorporate | applied |
| [x] | C06 | 0003EM | Return and loop variable are signed `short`; hit returns `si` through AX and miss returns `-1`. | very strong | `cmp si,4`, `mov ax,si`, miss `eax=-1`, adjacent family | UID0003EM Signature and formal CPP | incorporate | applied |
| [x] | C07 | 0003EM | The body uses one stack-local `RectBounds` at `[ebp-0x14]`. | original-proof | complete disassembly and InitRectBounds call | UID0003EM Behavior | incorporate | applied |
| [x] | C08 | 0003EM | Button rectangles are exact ids 0 through 3 with values `(59,259,81,277)`, `(112,259,134,277)`, `(168,66,185,83)`, `(168,84,185,101)` and default all `-1`. | original-proof | immediate/switch disassembly | UID0003EM Behavior | incorporate | applied |
| [x] | C09 | 0003EM | `0x004b7c50` is canonical `InitRectBounds(RectBounds *,left,top,right,bottom)`. | original-proof | MCP type/decompile/comment and UID00015S | UID0003EM Callees | already-present | already-present |
| [x] | C10 | 0003EM | `0x004b7e80` is canonical half-open `PointInRect(int y,int x,const RectBounds *)`. | original-proof | MCP type/decompile/comment and UID00015S | UID0003EM Callees | already-present | already-present |
| [x] | C11 | 0003EM | Two security-cookie calls are compiler support caused by the local frame and emit no handwritten source statement. | original-proof | call scan and epilogues | UID0003EM compiler-lowering notes | incorporate | applied |
| [x] | C12 | 0003EM | Source behavior scans ids 0 through 3 in order, returns the first containing id, and returns signed `-1` after all miss. | original-proof | loop and branch disassembly | UID0003EM Behavior and formal CPP | incorporate | applied |
| [x] | C13 | 0003EN | Successor is exact 3-byte NOP alignment, 20-byte five-target jump table, and 12-byte CC padding with independently recorded hashes. | original-proof | MCP bytes/items/xrefs | UID0003EN Contents and Item Summary | incorporate | applied |
| [x] | C14 | 0003EM | The target-local switch table is compiler lowering of an inlined source call to UID0003EJ GetButtonRect. | very strong | exact duplicate switch/default plus analogous UID0004Q7 | UID0003EM Source Contract; UID0003EN | incorporate | applied |
| [x] | C15 | 0003EM | A handwritten four-RectBounds static array is invalid because no such data object exists and the observed data is a code-target table. | original-proof | bytes, item classification, negative data search | UID0003EM Historical Assumptions | reject-stale | applied |
| [x] | C16 | 0003EM | Current button 2/3 `+256` vertical values are stale; exact raw values are `66..83` and `84..101`. | original-proof | case immediates and UID0003EJ | UID0003EM CPP and history | reject-stale | applied |
| [x] | C17 | 0003EM | Formal target CPP is the exact signed-short const member loop in Section 22. | very strong | complete ABI/behavior/source-family synthesis | UID0003EM formal CPP | incorporate | applied |
| [x] | C18 | 0003EM | Target formal H remains blank because UID00006S owns the single class declaration. | very strong | emitter route and generated header ownership | UID0003EM formal H rationale | already-present | already-present |
| [x] | C19 | 00006S | Complete owner H must declare non-static `void GetButtonRect(short button, RectBounds *rect) const;` and `short HitTestButton(int y, int x) const;` while preserving the shared UID0003EL declaration `void GetSlotRect(short slot, RectBounds *rect) const;`; it must not regress GetSlotRect to stale `int`. | very strong | UID0003EJ ECX/retn ABI; UID0003EM argument/return proof; B006 UID0003EL report and current low-word raw evidence | by-class/InventoryPane2.md complete formal H | incorporate | applied |
| [x] | C20 | 0003EJ | Adjacent GetButtonRect CPP should use a short selector, const member, explicit switch, and InitRectBounds rather than a static data array. | very strong | function ABI, callsites, local successor table | UID0003EJ formal CPP and evidence | incorporate | applied |
| [x] | C21 | 00048U | OnMouseEvent contains source-equivalent inline use: direct ids 2/3 hover tests and a four-id left-down loop using y at Event `+0x08` and x at `+0x0c`. | original-proof | MCP decompile/disassembly | UID00048U Evidence | incorporate | applied |
| [x] | C22 | 0003EM | Zero raw-start xrefs are consistent with full inlining and do not prove dead or compiler-only code. | very strong | UID00048U inline duplicate and retained out-of-line body | UID0003EM liveness and score rationale | incorporate | applied |
| [x] | C23 | 0003EM | Address-repeatable comment at `0x004ef7a0` is already exact and must not be duplicated or replaced. | original-proof | get_comments literal readback | UID0003EM IDA handoff | already-present | already-present |
| [x] | C24 | 0003EM | No IDA function creation, rename, type application, frame creation, or comment write is recommended. | very strong | raw-item boundaries and exact existing AP | UID0003EM IDA handoff | not-applicable | excluded-with-reason |
| [x] | C25 | 0002SV | Parent must retain exact split while describing UID0003EM as signed-short y/x member source and UID0003EN as compiler inlining support. | very strong | complete target and successor audit | UID0002SV range/source-order rows | incorporate | applied |
| [x] | C26 | 0003EN | Companion must gain an exact Item Summary and identify its table as GetButtonRect-inlining lowering, not source data. | very strong | item bytes, targets, xref, source abstraction | UID0003EN metadata/prose | incorporate | applied |
| [x] | C27 | 0003EM | Target gets full report-level behavior, ABI, geometry, hash, xrefs, history, score, Item Summary, and formal source. | very strong | all report evidence | target document throughout | incorporate | applied |
| [x] | C28 | 00006S | Owner class keeps `94/94`, owner/emitter/source route, and method count while correcting only the two dependent declarations and method notes. | very strong | current class inventory plus target/helper evidence | by-class/InventoryPane2.md | incorporate | applied |
| [x] | C29 | 0000KA | InventoryPane file page keeps `94/94` and 28-definition inventory while correcting A24/A26 signatures, source shape, and generated expectation. | very strong | current whole-file page and target audit | by-file/InventoryPane.md | incorporate | applied |
| [x] | C30 | 00018J | InventoryPanes aggregate keeps range/split ownership but updates UID0003EM target detail and compiler-table relationship. | very strong | parent inventory and exact range audit | UID00018J inventory/source map | incorporate | applied |
| [x] | C31 | 00048U | Caller documentation must stop treating generated x-first calls as binary direct-xref evidence and record the exact inlined y/x route. | very strong | zero target xrefs and OnMouseEvent body | UID00048U Evidence and history | incorporate | applied |
| [x] | C32 | 00015S | RectGeometry formal contracts already provide exact InitRectBounds and PointInRect definitions needed by the target. | original-proof | current UID00015S formal CPP and MCP types | UID00015S no edit | already-present | already-present |
| [x] | C33 | 00051H | Legacy UID00051H is corroborating family evidence only; its stale int/x-first formal signature is not authority for UID0003EM. | very strong | parallel raw skeleton and current legacy page | UID0003EM historical/rejected alternatives | reject-stale | applied |
| [x] | C34 | 0003EM | No exact target body duplicate was found; target-specific case-2 bytes occur only at `0x004ef7ec`. | original-proof | bounded find_bytes result | UID0003EM negative evidence | incorporate | applied |
| [x] | C35 | 0003EM | Nine generic prologue matches are separately inventoried and rejected as exact duplicates. | original-proof | bounded generic pattern search and lookup_funcs | UID0003EM duplicate inventory | incorporate | applied |
| [x] | C36 | 0003EM | Owner `00006S`, emitter `00006S`, position `320`, reconstructable true, and `Nested:0` remain unchanged. | very strong | current routing and exact source body | UID0003EM metadata | already-present | already-present |
| [x] | C37 | 0003EM | Score becomes `94/93`; confidence stays below 94 because source spelling and constness are inferred and raw-start inbound xrefs remain zero. | very strong | resolved blockers plus retained uncertainty | UID0003EM metadata/score rationale | incorporate | applied |
| [x] | C38 | 0003EM | Item Summary becomes the exact source-ready signed-short y/x loop, helper, first-hit/miss, raw-start, and compiler-successor summary in Section 24. | very strong | complete report synthesis | UID0003EM Item Summary | incorporate | applied |
| [x] | C39 | 0002SV | Supervisor coverage reconciliation preserved the merged UID0002SV detail in `by-memory/-coverage-report.md` SHA256 `AA23C646B3D531F70642D20054E67CD59B466B265E928A83B04DD4E94DF4DF70`, 2,275,465 bytes / 5,068 lines. | very strong | `SUPERVISOR_COVERAGE_PASSED`; command `000000024617`, exit `0`, `ok:1` | supervisor-owned by-memory coverage | incorporate | applied |
| [x] | C40 | 0003EM | Supervisor coverage reconciliation produced exactly one UID0003EJ, UID0003EL, UID0003EM, and UID0003EN row in address order; reference additions were exactly UID0003EJ/EM/EN and only pre-existing warnings UID00039L/UID0003T6 remained. | very strong | `SUPERVISOR_COVERAGE_PASSED`; command `000000024617`, lease released | supervisor-owned by-memory coverage | incorporate | applied |
| [x] | C41 | 0003EM | Generated command `000000024453` CPP/H hashes are a dated pre-callback snapshot showing the stale target definition and declaration, not mutable lifecycle authority. | original-proof | physical generated read and hashes | report evidence; generated files read-only | historicalize | applied |
| [x] | C42 | 0003EM | Accepted callback must scoped-validate every changed by-* destination from project-documentation and record command metadata, exit, ok, warnings, hashes, and refresh state. | procedural | workflow and destination set | report Validator Results after callback | incorporate | applied |
| [x] | C43 | 0003EM | After fresh validator metadata, generated InventoryPane CPP/H must be physically reread for one corrected definition, one corrected declaration, declaration visibility, source order, no duplicate, and no stale static-array body. | procedural | workflow and generated route | report Validator Results after callback | incorporate | applied |
| [x] | C44 | 0003EM | Report has 33 exact headings, exact ledger/checklist twins, only formal C++ fences, lifecycle-neutral role/disposition prose with no mutable assertion about current coverage, Gate 2, execution/archive, or reassignment state, and exactly one terminal `READY_FOR_SUPERVISOR_EXECUTE` marker. | procedural | mechanical report audit | report artifact | incorporate | applied |

- Checklist allocation: `44 checked / 0 unchecked`.
- Ordinary target/support implementation, scoped validators, generated readback, and post-implementation report mechanics are complete. These artifacts form the durable evidence set for supervisor review without asserting current gate status.
- Checklist role allocation: C39-C40 are checked from the dated `SUPERVISOR_COVERAGE_PASSED` receipt. I01/I02 retain already-present/no-change dispositions verified by `GATE2B_PASSED`; no save was needed. Execution/archive state remains supervisor-owned and dynamically authoritative from path plus validator history.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000024623","destination_path":"executed-b-agent-research/B001/0003EM-InventoryPane2ButtonHitTestRaw-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/0003EM-InventoryPane2ButtonHitTestRaw-source-quality.md","timestamp":"2026-08-16T00:45:57-04:00","uid":"0003EM"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
