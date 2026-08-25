** TARGET-REPORT-UID:0004I3 **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0004I3 ScrollNewGroupPaneHideRaw Source-Quality Research


## Finalized Report / Current Recommendation

- Current recommendation/status: implemented after supervisor Gate 1 acceptance at SHA256 `D6A1E9C5E77730989428256C77104645BBC3FE63A9E8228C299F6A236872A6A8`. Keep [UID:0004I3] `by-memory/0x00560ac0-0x00560ada.ScrollNewGroupPaneHideRaw.md` as the raw `ScrollNewGroupPane::Hide()` transition helper owned and emitted by [UID:0000CL] `ScrollNewGroupPane`, with source route through [UID:0000JS] `Group` / `auto-generated/NexusTK/social/Group.cpp`.
- Final disposition: the existing formal `ScrollNewGroupPane::Hide()` C++ is behavior-correct and was preserved exactly. The target received current B006 MCP evidence, generated-output/freshness facts, and the accepted score update from `86/89` to `88/90`.
- Implementation status: target by-memory page edited and scoped validator run. Support docs [UID:0000CL], [UID:0000JS], and [UID:0001GP] were verified as already containing the B007 raw child route and were not edited.
- Confidence: high for range, bytes, behavior, owner/emitter, and C++ preservation; still capped below final-audit levels by no IDA-modeled function, no direct xref, no VA/RVA pointer route, and no recovered original symbol for `Hide`.

## Supporting Research

- Assignment source: `Agent-B006/goal.md` first assigned [UID:0004I3] `by-memory/0x00560ac0-0x00560ada.ScrollNewGroupPaneHideRaw.md` as a report-first xHigh B-agent source-quality pass, then updated it to an implementation callback after Gate 1 acceptance.
- Current report path: `tools/leaser/Agents/Agent-B006/research/0004I3-ScrollNewGroupPaneHideRaw-source-quality.md`.
- Required old-report search terms used before conclusion: `TARGET-REPORT-UID:0004I3`, `0004I3`, `0x00560ac0`, `0x00560ada`, `ScrollNewGroupPaneHideRaw`, `ScrollNewGroupPane::Hide`, `ScrollNewGroupPaneShow`, `000452`, `0004I5`, `0x00560ae0`, `ScrollNewGroupPaneCore`, `0001GP`, `0000CL`, `0000JS`.
- Relevant old reports:
  - B007 `executed-b-agent-research/B007/000452-ScrollNewGroupPaneShow-source-quality.md` created UID0004I3 and UID0004I5 after proving the old `0x00560aba-0x00560b00` padding claim was stale. Its main assumptions remain current under the fresh MCP session, but its generated-output command metadata is historical. Gate 1/pre-callback `Group.cpp` was `validator-command-id: 000000007740`, refreshed `2026-07-06T20:08:27-04:00`; callback validation refreshed `Group.cpp` and generated coverage outputs to `validator-command-id: 000000007767`, refreshed `2026-07-07T01:45:25-04:00`.
  - B005 `executed-b-agent-research/B005/0001GP-ScrollNewGroupPaneCore-source-quality.md` is useful historical lead material for the core split but is stale where it originally treated `0x00560aba-0x00560b00` as broad padding. Current support docs already supersede that broad row.
  - B006 `executed-b-agent-research/B006/00044X-ScrollNewGroupPaneConstructor-source-quality.md` supports the constructor field map, especially `m_scrollEnabled` at `+0x102`.
  - B009 `executed-b-agent-research/B009/000455-ScrollNewGroupPaneOnScrollTimer-source-quality.md` is useful contrast: `OnScrollTimer` has vtable/data reachability, unlike this raw no-route helper.
- Broad `rg` searches also hit supervisor ledgers and assignment files. Those were treated as supervisor-owned context only, not research evidence, and were not edited.
- Generated state:
  - Gate 1/pre-callback check: `auto-generated/NexusTK/social/Group.cpp` had `validator-command-id: 000000007740`, `validator-refreshed-at: 2026-07-06T20:08:27-04:00`, and emitted UID0004I3 `ScrollNewGroupPane::Hide()` at `86/89`.
  - Gate 1/pre-callback check: `auto-generated/-ag-memory-coverage.md` and `auto-generated/-ag-coverage-report-by-memory.md` had `validator-command-id: 000000007760`, `validator-refreshed-at: 2026-07-07T01:05:04-04:00`, and listed UID0004I3 as coded, owner `0000CL`, emitter `0000CL`, generated to `auto-generated/NexusTK/social/Group.cpp`.
  - Post-callback generated check: `auto-generated/NexusTK/social/Group.cpp`, `auto-generated/-ag-memory-coverage.md`, and `auto-generated/-ag-coverage-report-by-memory.md` refreshed to `validator-command-id: 000000007767`, `validator-refreshed-at: 2026-07-07T01:45:25-04:00`; `auto-generated/-ag-research-tracker.md` subsequently refreshed to `validator-command-id: 000000007768`, `validator-refreshed-at: 2026-07-07T01:53:03-04:00`. `Group.cpp` emits UID0004I3 at `88/90`, and the research tracker lists UID0004I3 as `88/90`, average `89.0`, reconstructable true, direct report count `0`.

## Target

- Target UID: `0004I3`.
- Target path: `by-memory/0x00560ac0-0x00560ada.ScrollNewGroupPaneHideRaw.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md` now lists UID0004I3 as `88/90`, average `89.0`, reconstructable true, direct report count `0`.
- Current supervisor classification: reconstructable by-memory source-quality target with Gate 1-accepted direct B-agent report coverage, now implemented pending supervisor Gate 2 review.
- Current scores and parent state: target is `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000CL`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CL`, blank `EMITTER_POSITION_OPTIONAL`; direct owner [UID:0000CL] remains `85/86` and routes to [UID:0000JS] `Group` at `90/86`.

## Current Target State

- Existing metadata after implementation callback: `88/90`, `CANONICAL_OWNER:0000CL`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CL`, blank emitter position.
- Existing C++ state: formal `RECONSTRUCTION_CPP CODE` is populated with `void ScrollNewGroupPane::Hide()` and is emitted in current generated `Group.cpp`.
- Existing target evidence: target page already records exact raw bytes, disassembly, no modeled function, no xrefs, no pointer-byte route, field mapping `+0x102` to `m_scrollEnabled`, inherited `+0x44` to `m_bounds`, and inherited invalidation through vtable slot `+0x20`.
- Existing blockers: no recovered original symbol, no IDA function object, no direct call/data xref to `0x00560ac0`, and non-unique raw helper byte pattern. These cap confidence but do not invalidate the target C++.
- Related target/support docs checked: [UID:0000CL] `by-class/ScrollNewGroupPane.md`, [UID:0000JS] `by-file/Group.md`, [UID:0001GP] `by-memory/0x00560900-0x0056141f.ScrollNewGroupPaneCore.md`, sibling [UID:000452] `ScrollNewGroupPaneShow`, sibling [UID:0004I5] `ScrollNewGroupPaneCanAdjustRaw`, sibling [UID:000455] `ScrollNewGroupPaneOnScrollTimer`, [UID:0002OS] vtable-data, and [UID:0001YR] vtable cluster.
- Current artifact/lifecycle status: this report remains in `Agent-B006/research` for supervisor review. The target by-* doc was edited under callback authorization; support by-* docs were verified and left unchanged. No report lifecycle/archive command has been run.

## Executive Recommendation

Implementation result: UID0004I3 is now `88/90`, owner/emitter/reconstructable fields and the formal C++ block are preserved, and current B006 evidence is present on the target page. Source placement, split boundaries, and support-page metadata were not changed. Support docs already contain the raw child route, exact core subrange, and Group.cpp source route at same-or-greater detail; callback verification found no missing support content.

## Supervisor Active Recheck

- Triggering instruction: B006 is assigned a report-first xHigh source-quality pass for UID0004I3 and must not implement by-* edits before Gate 1.
- Split repair requirement: no new split is needed in this pass. B007 already split the old `0x00560aba-0x00560b00` padding claim into padding, UID0004I3 raw `Hide`, padding, UID0004I5 raw `CanAdjust`, and padding.
- Source-bearing child state: UID0004I3 already exists, is reconstructable, emits C++, and is currently generated. The prior direct-report gap was closed by this UID0004I3-specific research report and implemented target-level evidence.

## Inference Research Guidance Check

- IDA fact: fresh MCP session `supervisor-nexustk-20260707` reports `server_health status: ok`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
- Documentation evidence: current target/support docs route `Hide` through `ScrollNewGroupPane` into `Group.cpp`, and current generated output emits the target body.
- Inference: `Hide` is a source-facing inferred name, not recovered symbol proof. It is supported by the adjacent `Show()` inverse helper and by repeated equivalent helper byte patterns across the binary.
- Stale material: B005's earlier broad padding row is historical only. Current docs and live MCP prove two raw helper bodies inside that old gap.

## Heuristic / Inference Reanalysis And Validation

- No xref/no IDA-modeled-function route: resolved as a documented raw source helper, not a reason to remove C++. `lookup_funcs` reports `0x00560ac0` and `0x00560ada` are not functions; `xrefs_to 0x00560ac0` reports zero incoming xrefs. `xref_query both` reports only the internal branch from `0x00560ac0` to `0x00560ac7`, not an external caller or table route.
- Correctness of formal C++: validated. Bytes at `0x00560ac0` compare byte `+0x102` to `1`, return when false, load vtable, pass `this+0x44`, store `0` to `+0x102`, call `[edx+0x20]`, and return. That exactly matches the existing transition-only `Hide()` C++.
- Field names: `m_scrollEnabled` at `+0x102` is supported by constructor initialization, adjacent `Show()`, `CanAdjust()`, paint/interaction checks, and the class field alias table. `m_bounds` at inherited `+0x44` is used across hit-test, part-rect, paint, and invalidation helpers.
- Vtable slot/invalidation target: the raw body calls through `[edx+0x20]` after pushing `this+0x44`. Current class helper notes name this inherited pane route `InvalidateRect(RectBounds *rect)`. The ScrollNewGroupPane-specific vtable docs list class slots for paint, mouse, `CanScroll`, and `OnScrollTimer`, confirming this raw helper is not reached through a ScrollNewGroupPane-specific vtable slot.
- B007 assumptions: current. Fresh MCP reconfirms the B007 split and no-route facts; current generated output is newer than B007's executed report metadata and still emits UID0004I3.
- Source placement: keep `ScrollNewGroupPane` class ownership and `Group.cpp` route. Direct [UID:0000JS] ownership is too broad, [UID:000090] `NewGroupPane` is a caller/container route, and generic scrollbar ownership lacks the target-local vtable and field evidence.
- Score/metadata movement: target-level current MCP, generated-output, byte-pattern, and support consistency evidence justify a modest score raise. No higher score is safe because the original symbol and static route remain unrecovered.

## Evidence Standards Used

- IDA MCP evidence used: `server_health`, `lookup_funcs`, `entity_query`, `xrefs_to`, `xref_query`, `get_bytes`, `insn_query`, `find_bytes`, and `make_signature_for_range`.
- Documentation evidence used: current target/support by-* pages, generated `Group.cpp`, generated memory coverage, generated research tracker, and relevant executed B-agent reports.
- Negative evidence used: no IDA function object, zero incoming xrefs, zero VA/RVA pointer-pattern matches, non-unique byte signature, and absence from ScrollNewGroupPane-specific vtable slots.
- Evidence strength: strong enough for target ownership, source placement, C++ preservation, and score improvement to `88/90`; not strong enough for final-audit score, original-name proof, or claiming a recovered static call route.

## Evidence Checked

- MCP session/evidence summary: `idb_list` active session `supervisor-nexustk-20260707`; `server_health` status `ok`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready true, Hex-Rays ready true.
- MCP `lookup_funcs`: `0x00560aa0` is `sub_560AA0` size `0x1a`; `0x00560aba`, `0x00560ac0`, `0x00560ada`, `0x00560ae0`, and `0x00560afa` are not functions; `0x00560b00` is `sub_560B00` size `0x1e1`; `0x0056caae` and `0x0056cac3` resolve inside `sub_56CA20`.
- MCP `entity_query functions` in `0x00560a90-0x00560b10`: only `sub_560AA0` at `0x00560aa0` and `sub_560B00` at `0x00560b00` are modeled functions.
- MCP `xrefs_to`: `0x00560aa0` has one code xref at `0x0056cac3`; `0x00560ac0` has zero xrefs; `0x00560ae0` has zero xrefs; `0x00560b00` has one data xref at `0x00623f6c`.
- MCP `xref_query both`: UID0004I3 reports one internal code edge from raw start to branch target `0x00560ac7`; UID0004I5 similarly reports an internal branch to `0x00560ae7`. These are internal control-flow edges, not incoming external references.
- MCP `get_bytes`: `0x00560aba-0x00560b00` contains six `0xcc` bytes, the UID0004I3 body, six `0xcc` bytes, the UID0004I5 body, and six `0xcc` bytes. UID0004I3 bytes are `80 b9 02 01 00 00 01 75 10 8b 11 8d 41 44 50 c6 81 02 01 00 00 00 ff 52 20 c3`.
- MCP `insn_query 0x00560aa0-0x00560b00`: confirms `Show` instructions at `0x00560aa0-0x00560ab9`, alignment at `0x00560aba`, raw `Hide` instructions at `0x00560ac0-0x00560ad9`, alignment at `0x00560ada`, raw `CanAdjust` instructions at `0x00560ae0-0x00560af9`, and alignment at `0x00560afa`.
- MCP `find_bytes`: exact UID0004I3 body pattern appears at `0x41d830`, `0x459a20`, `0x494c10`, `0x55c3c0`, `0x55f610`, `0x560ac0`, `0x561f70`, `0x563420`, and `0x5648d0`; pointer patterns `c0 0a 56 00` and `c0 0a 16 00` have zero matches.
- MCP `make_signature_for_range 0x00560ac0-0x00560ada`: signature `80 B9 ? ? ? ? ? 75 ? 8B 11 8D 41 ? 50 C6 81 ? ? ? ? ? FF 52 ? C3`, `unique:false`.
- by-* docs checked: target UID0004I3, siblings UID000452/UID0004I5/UID000455, support UID0000CL/UID0000JS/UID0001GP/UID0002OS/UID0001YR.
- Generated docs checked read-only: `auto-generated/NexusTK/social/Group.cpp`, `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-coverage-report-by-memory.md`.
- Failed/unavailable/skipped checks: no decompile was attempted for UID0004I3 because IDA does not model it as a function. No support validators were run because callback-time support docs were verified as already-present and were not edited.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-0004I3-001 | UID0004I3 remains exact half-open range `0x00560ac0-0x00560ada`, bounded by padding at `0x00560aba-0x00560ac0` and `0x00560ada-0x00560ae0`. | High | MCP `get_bytes`, `insn_query`, support [UID:0001GP]. | Target `Address Range And Boundary`; [UID:0001GP] already-present. | applied | Target now records B006 `insn_query` neighborhood and exact padding/raw split; [UID:0001GP] verified already-present and not edited. |
| C-0004I3-002 | The body clears `m_scrollEnabled` only when it is currently true and invalidates `m_bounds` only on that transition. | High | MCP bytes/disassembly; current C++ block; sibling `Show()`. | Target `Behavior` and `Raw Code Evidence`. | applied | Target raw evidence and score rationale now state the guarded store/invalidate behavior; formal C++ was preserved exactly. |
| C-0004I3-003 | Existing formal `ScrollNewGroupPane::Hide()` C++ is correct and should be preserved exactly. | High | Instruction-by-instruction MCP validation. | Target formal `RECONSTRUCTION_CPP CODE`. | already-present | Verified after edit: formal block still contains the same `void ScrollNewGroupPane::Hide()` body and no body-only replacement was made. |
| C-0004I3-004 | `+0x102` is `m_scrollEnabled`; inherited `+0x44` is `m_bounds`; `[edx+0x20]` is inherited `InvalidateRect(&m_bounds)`. | High | Constructor, class alias table, raw instructions, support helper notes. | Target evidence; [UID:0000CL] already-present. | applied | Target evidence now ties the raw compare/store/call to these fields; [UID:0000CL] field/helper support verified already-present and not edited. |
| C-0004I3-005 | No recovered direct/static route exists: no function object, no incoming xrefs, no VA/RVA pointer-pattern hits, and non-unique byte signature. | High | MCP `lookup_funcs`, `xrefs_to`, `find_bytes`, `make_signature_for_range`. | Target `Caller And Route Evidence`; score rationale. | applied | Target caller/route evidence records no function object, zero `xrefs_to`, internal-only `xref_query`, zero pointer-pattern hits, repeated byte-pattern hits, and non-unique signature. |
| C-0004I3-006 | Direct semantic owner remains [UID:0000CL] `ScrollNewGroupPane`; emitter remains [UID:0000CL] through [UID:0000JS] `Group`. | High | Class method family, field use, current support docs, generated `Group.cpp`. | Target metadata and ownership sections. | already-present | Metadata remained `CANONICAL_OWNER:0000CL`, `EMITTER_UIDS:0000CL`, reconstructable true; support route verified in [UID:0000CL]/[UID:0000JS]. |
| C-0004I3-007 | Do not assign a source-order emitter position during this pass; blank position avoids renumbering existing positioned core children and is already accepted support state. | Medium-high | Current target and [UID:0000CL]/[UID:0000JS] support notes. | Target metadata. | already-present | `EMITTER_POSITION_OPTIONAL:` remains blank after implementation. |
| C-0004I3-008 | Generated output emits UID0004I3 from `Group.cpp`; generated coverage also lists the target as coded. | High | Gate 1/pre-callback `Group.cpp` command `000000007740`; coverage command `000000007760`; callback validator command `000000007767`; generated tracker refresh `000000007768`. | Target generated-output evidence; report validator proof. | applied | Target records Gate 1/pre-callback generated facts; scoped validator refreshed `Group.cpp` and coverage outputs to `000000007767` at `2026-07-07T01:45:25-04:00`; generated tracker is current at `000000007768`, refreshed `2026-07-07T01:53:03-04:00`; UID0004I3 is `88/90`. |
| C-0004I3-009 | B007's raw child creation assumptions remain current; B005's old broad padding assumption is historical/stale. | High | Fresh MCP recheck and current support docs. | Target/support history notes. | applied | Target change log and evidence record B007 as current and B005 broad padding as stale; support split [UID:0001GP] verified already-present. |
| C-0004I3-010 | Recommended metadata is `COMPLETION:88`, `CONFIDENCE:90`; owner/emitter/reconstructable/position/C++ otherwise unchanged. | Medium-high | Current evidence removes target-level evidence gaps but not original-name/static-route blockers. | Target metadata. | applied | Target metadata is now `88/90`; owner `0000CL`, reconstructable true, emitter `0000CL`, blank position, `Nested:0`, and formal C++ are unchanged. |
| C-0004I3-011 | Support docs [UID:0000CL], [UID:0000JS], and [UID:0001GP] already contain the raw child route and do not require edits unless they change before callback. | High | Current support docs read this pass. | Support docs verification. | already-present | Callback-time checks found class, file, and core support content present; no support docs were edited. |
| C-0004I3-012 | No generated files, coverage files, validator state, supervisor ledgers, lifecycle headers/footers, archives, or forbidden lifecycle commands may be manually edited/run. | High | Assignment boundaries and B-agent workflow. | Checklist/validator sections. | excluded-with-reason | No manual generated/coverage/validator-state/supervisor-ledger/lifecycle/archive edits or commands were performed; generated/projected stats changes were validator-owned side effects of scoped command `000000007767`. |

## Positive Evidence Summary

- Direct binary facts: exact UID0004I3 bytes implement a guarded transition from enabled to disabled, pass `this+0x44` to the inherited invalidation slot, and return. The surrounding bytes prove the half-open raw body boundary and padding islands.
- Corroborating documentation/generated evidence: target/support docs already route this helper through `ScrollNewGroupPane` into `Group.cpp`; current generated output emits the exact formal `Hide()` body; generated memory coverage lists UID0004I3 as coded.
- Strongest inference chain: adjacent modeled `Show()` sets the same byte true and invalidates through the same route; UID0004I3 is the inverse raw body; support docs identify the fields and class route; therefore `ScrollNewGroupPane::Hide()` is the best source-facing name even without original-symbol proof.

## IDA MCP Facts

- Function/range facts: `0x00560ac0` is not an IDA function; only adjacent `sub_560AA0` and `sub_560B00` are modeled in the bounded neighborhood.
- Byte/disassembly facts: UID0004I3 bytes are `80 b9 02 01 00 00 01 75 10 8b 11 8d 41 44 50 c6 81 02 01 00 00 00 ff 52 20 c3`.
- Xref facts: no incoming xrefs to `0x00560ac0`; the only `xref_query` result is the helper's own internal branch. Pointer-byte patterns for VA `0x00560ac0` and RVA `0x00160ac0` have zero matches.
- Vtable/global/type facts: specific ScrollNewGroupPane vtable slots document virtual methods around this family; UID0004I3 is not one of those slots. Its invalidation call uses an inherited pane vtable dispatch through the object primary vtable.
- Negative IDA facts: no function object, no external xrefs, no pointer route, non-unique signature, and no recovered source symbol.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00560aa0-0x00560aba` | [UID:000452] `ScrollNewGroupPaneShow` | Modeled show/enable transition helper | TRUE | `0000CL` | `89/91` | Direct caller from `NewGroupPane`; formal C++. |
| `0x00560aba-0x00560ac0` | no child | Padding | FALSE | none | n/a | Six `0xcc` bytes. |
| `0x00560ac0-0x00560ada` | [UID:0004I3] `ScrollNewGroupPaneHideRaw` | Raw hide/disable transition helper | TRUE | `0000CL` | `88/90` | Formal C++ correct; no external route. |
| `0x00560ada-0x00560ae0` | no child | Padding | FALSE | none | n/a | Six `0xcc` bytes. |
| `0x00560ae0-0x00560afa` | [UID:0004I5] `ScrollNewGroupPaneCanAdjustRaw` | Raw enabled-and-range predicate | TRUE | `0000CL` | `88/90` | Formal C++; no external route. |
| `0x00560afa-0x00560b00` | no child | Padding | FALSE | none | n/a | Six `0xcc` bytes before mouse virtual. |
| `0x00560b00-0x00560ce1` | [UID:000453] `ScrollNewGroupPaneHandleMouseEvent` | Secondary-vtable mouse/input method | TRUE | `0000CL` | `89/90` | Data vtable xref; formal C++. |
| `0x00560d00-0x00560d33` | [UID:000455] `ScrollNewGroupPaneOnScrollTimer` | TimerHandler-adjusted callback | TRUE | `0000CL` | `88/90` | Vtable/data route; formal C++. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00560aa0` | code xref from `0x0056cac3` inside `sub_56CA20` | `NewGroupPane` constructor calls adjacent `Show()`. |
| `0x00560ac0` | zero incoming xrefs | `Hide()` raw start has no recovered static call/table route. |
| `0x00560ac7` | internal branch target from `0x00560ac0` | Internal control flow only, not a caller. |
| `0x00560ad6` | `call dword ptr [edx+20h]` | Inherited pane invalidation after pushing `this+0x44`. |
| `0x00560ae0` | zero incoming xrefs | Sibling raw predicate also has no recovered static route. |
| `0x00560b00` | data xref from `0x00623f6c` | Next method is vtable-dispatched, unlike UID0004I3. |

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion: UID0004I3 target, UID000452 Show, UID0004I5 CanAdjust, UID0001GP core split, UID0000CL class, UID0000JS file, UID0002OS vtable-data, and UID0001YR vtable cluster.
- Existing docs that are stale, incomplete, or contradicted: B005's old broad `0x00560aba-0x00560b00` padding assumption is historical and has already been superseded in current docs.
- Generated/coverage report state: Gate 1/pre-callback `Group.cpp` command was `000000007740` and generated memory coverage command was `000000007760`; post-callback scoped validation refreshed `Group.cpp` and generated coverage headers to `validator-command-id: 000000007767`, refreshed `2026-07-07T01:45:25-04:00`; generated tracker is newer at `validator-command-id: 000000007768`, refreshed `2026-07-07T01:53:03-04:00`; UID0004I3 is `88/90`.

## Ranked Ownership Analysis

### 1. [UID:0000CL] `ScrollNewGroupPane`

- Evidence for: raw body uses `ScrollNewGroupPane` scroll-tail field `+0x102`, inherited bounds at `+0x44`, adjacent `Show` and `CanAdjust` helpers, current class method inventory, and Group.cpp generated route through the class page.
- Evidence against: no direct caller or vtable slot points to the raw start.
- Decision: keep as direct owner and emitter. The no-route caveat limits confidence but does not outweigh class-local field and adjacency evidence.

### 2. [UID:0000JS] `Group`

- Evidence for: Group file owns `NewGroupPane`, constructs and shows the custom scroll child, and is the generated source root for `ScrollNewGroupPane`.
- Evidence against: by-structure requires the narrowest direct semantic owner; UID0004I3 is a class method, not a file-level free function.
- Decision: keep as source-file route only through [UID:0000CL], not direct canonical owner.

### 3. [UID:000090] `NewGroupPane`

- Evidence for: `NewGroupPane` constructs the scrollbar and directly calls adjacent `Show()`.
- Evidence against: UID0004I3's receiver fields and method family belong to `ScrollNewGroupPane`; no direct `NewGroupPane` call to `Hide()` survives.
- Decision: reject as direct owner. It is caller/container context, not method owner.

### 4. Generic shared scrollbar owner or new `ScrollBar` source file

- Evidence for: exact hide byte pattern appears at multiple addresses and likely reflects a shared scrollbar helper idiom.
- Evidence against: this instance is tied to `ScrollNewGroupPane` fields, vtable layout, and Group source route; no separate shared source file/page owns this exact method.
- Decision: reject for this pass. Mention the repeated pattern only as naming/source-shape support.

### 5. No-owner/non-emitting

- Evidence for: no modeled function, no xrefs, no pointer route, non-unique signature.
- Evidence against: class-local field mapping, adjacent inverse `Show()`, current support docs, generated emission, and reconstructable source behavior are strong.
- Decision: reject. The item should remain class-owned and emitting.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: no new file or grouping. Keep `ScrollNewGroupPane::Hide()` through `NexusTK/social/Group.cpp`.
- Likely full contents: existing `Group.cpp` route with exact group-pane and ScrollNewGroupPane child methods.
- Candidate related items that belong: siblings UID000452 and UID0004I5 already belong to the same class route.
- Candidate related items rejected: direct file-level `Group` ownership and a new generic shared scrollbar file are unsupported for this exact target.

## Source Placement

- Recommended source file/class/global/module placement: `ScrollNewGroupPane` class method emitted through [UID:0000CL] into [UID:0000JS] `NexusTK/social/Group.cpp`.
- Why this placement fits source-tree and subsystem context: `NewGroupPane` constructs the custom scrollbar child, the class page owns the field/vtable/method family, and the generated file already assembles this child under the Group feature source root.
- Rejected placements and why: direct `Group.cpp` free function is too broad; direct `NewGroupPane` method is caller/container confusion; separate generic scrollbar file lacks local ownership proof.
- Remaining placement uncertainty: final whole-class header/source split for `ScrollNewGroupPane` remains broader class work; it does not block this exact child method.

## Range / Split / Padding / Reclassification Analysis

- Exact range/boundary facts: UID0004I3 is `0x00560ac0-0x00560ada` half-open. MCP bytes confirm preceding padding `0x00560aba-0x00560ac0` and following padding `0x00560ada-0x00560ae0`.
- Children/subranges: no new child creation recommended. Existing split into `Show`, padding, `Hide`, padding, `CanAdjust`, padding, `HandleMouseEvent` remains current.
- Padding/table/data/code distinctions: all three six-byte islands in `0x00560aba-0x00560b00` are `0xcc` alignment. UID0004I3 and UID0004I5 are executable raw method bodies despite no IDA function objects.
- Parent/container impact: [UID:0001GP] remains a non-emitting split index. No parent metadata change is recommended.

## Negative Evidence Summary

- No IDA-modeled function at `0x00560ac0` or `0x00560ada`; this prevents Hex-Rays decompile proof and original function naming.
- No incoming xrefs to `0x00560ac0`; the only `xref_query` record is internal branch flow.
- No VA/RVA pointer-pattern hits for `0x00560ac0`; no table route was found in the bounded raw-pointer check.
- `make_signature_for_range` is non-unique, and exact bytes appear at eight other addresses. This supports common source shape but prevents UID-specific uniqueness.
- No ScrollNewGroupPane-specific vtable slot targets UID0004I3. The slot call in the body is inherited invalidation, not a reachability route to `Hide()`.
- These negatives cap the score and prevent a final-original-symbol claim, but they do not disprove class ownership or the formal C++ body.

## IDA Rename / Type / Comment Recommendations

- Proposed source-facing names/types/comments: keep `ScrollNewGroupPane::Hide()`, `m_scrollEnabled`, `m_bounds`, and `InvalidateRect(&m_bounds)`.
- Evidence for each proposed name/type/comment: adjacent `Show()` inverse behavior; constructor/class alias table; raw `this+0x44` invalidation pattern; generated/source-route consistency.
- Items intentionally left unchanged and why: no IDA database rename is requested, and no stronger original symbol claim should be added.
- Whether IDA DB edits are safe, unsafe, or not requested: not requested. B-agent documentation pass must not edit IDA DB.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. UID0004I3 is reconstructable, has confirmed emitter route through [UID:0000CL] to [UID:0000JS], current combined score is above the code-entry gate, and the formal block is already populated.
- Recommended/implemented code action: preserve the existing formal block exactly; only the target metadata score changed after supervisor Gate 1 acceptance.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ScrollNewGroupPane::Hide()
{
    if (!m_scrollEnabled) {
        return;
    }

    m_scrollEnabled = false;
    InvalidateRect(&m_bounds);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Reason it preserves exact original behavior: matches the raw branch, guarded store to `+0x102`, `this+0x44` invalidation argument, vtable `+0x20` call, and return.
- Reason it matches plausible original precompiled source shape: adjacent source-facing `Show()` uses the inverse early-return style and the class support pages use `m_` field names and `InvalidateRect(&m_bounds)`.
- Inferred source-facing names/types/fields used instead of IDA/decompiler labels: `m_scrollEnabled` for `+0x102`, `m_bounds` for `+0x44`, and `InvalidateRect` for the inherited `+0x20` callback.
- Naming/coding style convention used and evidence for consistency: current generated `Group.cpp` uses ordinary member methods, early returns, and `m_` fields for ScrollNewGroupPane children.
- Reason code should remain blank, if applicable: not applicable.
- Exact no-code proof, if not eligible: not applicable.

## Final Recommendation

- Exact changes implemented: updated UID0004I3 target evidence with current B006 MCP facts and generated-output facts; changed metadata from `86/89` to `88/90`; preserved owner/emitter/reconstructable/blank position/formal C++.
- Exact parent assignments preserved: kept `CANONICAL_OWNER:0000CL` and `EMITTER_UIDS:0000CL`; kept source route through [UID:0000JS] `Group`.
- Exact items left no-owner/non-emitting and why: none for UID0004I3; no-owner/non-emitting is rejected because the class route and formal C++ are supported.
- Exact future work outside scope: whole-class `ScrollNewGroupPane` header/source declaration polish and possible shared scrollbar naming reconciliation remain broader class work.

## Recommended Target Doc Changes

- Target path: `by-memory/0x00560ac0-0x00560ada.ScrollNewGroupPaneHideRaw.md`.
- Exact report facts to incorporate:
  - Add current B006 MCP session `supervisor-nexustk-20260707`, health state, and exact lookup/xref/bytes/insn/find-bytes results.
  - Record that `xrefs_to 0x00560ac0` remains zero and that `xref_query` only sees internal branch flow, not a caller.
  - Record exact Gate 1/pre-callback generated `Group.cpp` header `validator-command-id: 000000007740`, `validator-refreshed-at: 2026-07-06T20:08:27-04:00`, plus generated memory coverage command `000000007760`, refreshed `2026-07-07T01:05:04-04:00`; record callback validator refresh command `000000007767`, refreshed `2026-07-07T01:45:25-04:00`, and generated tracker command `000000007768`, refreshed `2026-07-07T01:53:03-04:00`, in this report.
  - Preserve the B007 historical split facts but label B005's broad padding assumption as stale/historical.
  - Record the repeated exact byte pattern matches and non-unique signature as source-shape support, not original-symbol proof.
- Metadata/score/owner/emitter/reconstructable/C++ changes:
  - `COMPLETION:86` -> `COMPLETION:88`.
  - `CONFIDENCE:89` -> `CONFIDENCE:90`.
  - Keep `CANONICAL_OWNER:0000CL`.
  - Keep `RECONSTRUCTABLE:TRUE`.
  - Keep `EMITTER_UIDS:0000CL`.
  - Keep blank `EMITTER_POSITION_OPTIONAL`.
  - Preserve the formal C++ block exactly.
- Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: no function object, no direct/static xrefs, no pointer route, no original symbol, non-unique signature, and stale B005 broad padding row.

## Recommended Support Doc Changes

- Support path: `by-class/ScrollNewGroupPane.md`.
  - Exact report facts to incorporate: no required edit in this report. The class page already lists UID0004I3 as raw `Hide`, records first-draft C++/no static route, documents `m_scrollEnabled`, `m_bounds`, and inherited `InvalidateRect`, and routes through [UID:0000JS].
  - Metadata/link/score/coverage/source-placement changes: none recommended; verified already-present during callback.
- Support path: `by-file/Group.md`.
  - Exact report facts to incorporate: no required edit in this report. The file page already lists UID0004I3 and UID0004I5 in the ScrollNewGroupPane proposed-content row and preserves the `Group.cpp` source route.
  - Metadata/link/score/coverage/source-placement changes: none recommended; verified already-present during callback.
- Support path: `by-memory/0x00560900-0x0056141f.ScrollNewGroupPaneCore.md`.
  - Exact report facts to incorporate: no required edit in this report. The split index already has the exact padding/raw/padding/raw/padding subranges and links UID0004I3.
  - Metadata/link/score/coverage/source-placement changes: none recommended; verified already-present during callback.
- Sibling/helper pages [UID:000452], [UID:0004I5], and [UID:000455]: no edits recommended. They were checked for source placement and score reasoning.

## Score And Metadata Recommendation

- Pre-callback score/metadata: `COMPLETION:86`, `CONFIDENCE:89`, `CANONICAL_OWNER:0000CL`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CL`, blank position, formal C++ present.
- Implemented score/metadata: `COMPLETION:88`, `CONFIDENCE:90`, same owner/emitter/reconstructable/position/C++.
- Score rationale and reason not higher/lower:
  - Higher than the pre-callback score because this direct report adds fresh target-level MCP session evidence, current generated-output freshness, exact no-route proof, repeated byte-pattern evidence, and explicit confirmation that B007 assumptions remain current.
  - Not higher than `88/90` because no IDA function, external xref, VA/RVA pointer route, unique signature, original symbol, or direct call/table route exists. `Show()` can score higher because it has a direct constructor call; UID0004I3 does not.
- Score-improvement attempt:
  - No xref/no modeled function blocker: attempted with `lookup_funcs`, `entity_query`, `xrefs_to`, `xref_query`, pointer-pattern `find_bytes`; result remains no route, documented as confidence cap.
  - C++ correctness blocker: resolved with bytes/disassembly and formal block preservation.
  - Field-name blocker: resolved through class alias table, constructor, and sibling helper evidence.
  - Vtable/invalidation blocker: resolved as inherited invalidation call, not a source-reachability slot.
  - B007 assumption freshness blocker: resolved by current MCP and generated-output checks.
  - Source placement blocker: resolved through [UID:0000CL] direct class owner and [UID:0000JS] source-file route.
- Metadata fields changed or left unchanged: changed only completion/confidence; left owner/emitter/reconstructable/position/C++ unchanged.

## Open Questions With Attempted Resolution

- Open question: Was the original source name exactly `Hide`? Evidence checked: adjacent `Show()`, repeated exact hide-pattern matches, support docs, generated output, and symbol/vtable/xref state. Best supported resolution: use `Hide()` as inferred source-facing name. Remaining unresolved: no PDB/source symbol or static route proves exact original spelling; confidence cap remains.
- Open question: How was this raw helper reached at runtime? Evidence checked: xrefs, pointer encodings, vtable slots, bounded function query, and sibling docs. Best supported resolution: no current static route survives in IDA; treat it as raw retained source method paired with `Show()`. Remaining unresolved: caller/table route unavailable; score cap remains.
- Open question: Should this helper be non-emitting because it has no route? Evidence checked: by-structure code-entry gate, current emitter chain, generated output, support docs, and formal C++. Best supported resolution: no, it remains emitting because the class route and behavior are strong and current generated output already emits it.
- Open question: Should support docs be edited? Evidence checked: UID0000CL, UID0000JS, UID0001GP, UID000452, UID0004I5, UID000455. Best supported resolution after callback-time verification: no support edits were needed; current support docs already preserve the accepted route and split facts.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Not applicable. UID0004I3 metadata changes were applied to the target by-memory page and refreshed through scoped validator command `000000007767`. B006 did not hand-edit `auto-generated/-ag-*` files, manual coverage reports, supervisor trackers, or validator state.

## Follow-Up Actions

- Supervisor actions: Gate 2 review this implemented callback and validator result.
- B006 implementation-callback actions after acceptance: complete; target by-* doc was edited, support docs were verified already-present, this report ledger/checklist was updated, the scoped validator was run, and B006 stopped at `READY_FOR_SUPERVISOR_GATE2_REVIEW`.
- Future broader work: whole-class `ScrollNewGroupPane` declaration/header reconciliation remains outside this UID0004I3 pass.

## Confidence

- Recommendation confidence: high for target update and C++ preservation.
- Score confidence: medium-high for `88/90`; remaining no-route/original-symbol facts prevent a higher recommendation.
- Remaining uncertainty: exact original source symbol and hidden runtime reachability mechanism are unrecovered.

## Validator Results

- Scoped command run from `source-3/project-documentation`:
  - `python .\tools\validator.py --mode file --file by-memory\0x00560ac0-0x00560ada.ScrollNewGroupPaneHideRaw.md --apply --queue-timeout 240`
- Exit code: `0`.
- Validator metadata: `command_id: 000000007767`; `command_timestamp: 2026-07-07T01:45:25-04:00`; `mode: file`; `apply: True`.
- Validator result counts: scanned markdown files `1`; `ok: 1`; `completion_update: 1`; `confidence_update: 1`; `projected_stats_update: 1`; `stats_incremental_noop: 1`.
- Target updates reported by validator: completion update for UID0004I3 to `88`; confidence update for UID0004I3 to `90`.
- Generated refresh state: validator reported `generated_refresh: deferred`, `generated_refresh_command_id: 000000007767`, `generated_refresh_timestamp: 2026-07-07T01:45:25-04:00`.
- Post-command generated header comparison:
  - `auto-generated/NexusTK/social/Group.cpp`: `validator-command-id: 000000007767`, `validator-refreshed-at: 2026-07-07T01:45:25-04:00`; UID0004I3 emitted at `88/90`.
  - `auto-generated/-ag-memory-coverage.md`: `validator-command-id: 000000007767`, `validator-refreshed-at: 2026-07-07T01:45:25-04:00`; UID0004I3 remains coded owner/emitter `0000CL`.
  - `auto-generated/-ag-coverage-report-by-memory.md`: `validator-command-id: 000000007767`, `validator-refreshed-at: 2026-07-07T01:45:25-04:00`; UID0004I3 row shows `88% : very-strong`.
  - `auto-generated/-ag-research-tracker.md`: `validator-command-id: 000000007768`, `validator-refreshed-at: 2026-07-07T01:53:03-04:00`, `validator-refresh-source: foreground-generated-refresh`; UID0004I3 row shows `88/90`, average `89.0`.
- Any unresolved validator warnings/errors: none observed.

## Changed Files

- Created during report-only pass: `tools/leaser/Agents/Agent-B006/research/0004I3-ScrollNewGroupPaneHideRaw-source-quality.md`.
- Modified during implementation callback:
  - `by-memory/0x00560ac0-0x00560ada.ScrollNewGroupPaneHideRaw.md`.
  - `tools/leaser/Agents/Agent-B006/research/0004I3-ScrollNewGroupPaneHideRaw-source-quality.md`.
- Verified already-present and not edited:
  - `by-class/ScrollNewGroupPane.md`.
  - `by-file/Group.md`.
  - `by-memory/0x00560900-0x0056141f.ScrollNewGroupPaneCore.md`.
- Validator-owned/generated refresh side effects observed after scoped command `000000007767`:
  - `auto-generated/NexusTK/social/Group.cpp` refreshed.
  - `auto-generated/-ag-memory-coverage.md` refreshed.
  - `auto-generated/-ag-coverage-report-by-memory.md` refreshed.
  - `auto-generated/-ag-research-tracker.md` refreshed to command `000000007768`.
  - `project-level/-auto-completion-stats.md` projected path completion section updated.
- Renamed: none.
- Report execution: not run. B006 did not run `execute_report`, dry-run/probing execute variants, registry lifecycle commands, manual report moves, archive moves, or any equivalent report execution/archive command.
- Other forbidden writes: no manual generated edits, manual coverage edits, validator-state edits, supervisor-ledger edits, lifecycle header/footer edits, archive edits, queue edits, or IDA DB edits were performed.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor Gate 1 validation passed at SHA256 `D6A1E9C5E77730989428256C77104645BBC3FE63A9E8228C299F6A236872A6A8` before any by-* implementation.
- [x] Target doc edit: `by-memory/0x00560ac0-0x00560ada.ScrollNewGroupPaneHideRaw.md` now includes current B006 MCP evidence from session `supervisor-nexustk-20260707`, including health, lookup, function-neighborhood, bytes, disassembly, xrefs, pointer-pattern, and signature facts.
- [x] Target metadata edit: `COMPLETION:86` changed to `COMPLETION:88`; `CONFIDENCE:89` changed to `CONFIDENCE:90`.
- [x] Target metadata preservation: `CANONICAL_OWNER:0000CL`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CL`, blank `EMITTER_POSITION_OPTIONAL`, and `Nested:0` preserved.
- [x] Formal C++ preservation: exact formal `ScrollNewGroupPane::Hide()` `RECONSTRUCTION_CPP CODE` block preserved; no body-only snippet or prose-only replacement made.
- [x] No-xref caveat: target preserves that `0x00560ac0` has no IDA function object, no incoming xrefs, no VA/RVA pointer-pattern hits, and only an internal branch in `xref_query`.
- [x] Field/source-shape facts: target incorporates or preserves `m_scrollEnabled` at `+0x102`, `m_bounds` at `+0x44`, and inherited `InvalidateRect(&m_bounds)` through vtable `+0x20`.
- [x] Range/split facts: target/support state preserves exact subranges `0x00560aba-0x00560ac0` padding, `0x00560ac0-0x00560ada` Hide, `0x00560ada-0x00560ae0` padding, `0x00560ae0-0x00560afa` CanAdjust, and `0x00560afa-0x00560b00` padding.
- [x] B007/B005 history: target records B007's raw child creation as current and B005's broad padding assumption as historical/stale.
- [x] Support doc verification: [UID:0000CL] `by-class/ScrollNewGroupPane.md` already lists UID0004I3 as raw Hide with first-draft C++/no static route and correct field aliases; not edited.
- [x] Support doc verification: [UID:0000JS] `by-file/Group.md` already lists UID0004I3/UID0004I5 in the ScrollNewGroupPane route; not edited.
- [x] Support doc verification: [UID:0001GP] `by-memory/0x00560900-0x0056141f.ScrollNewGroupPaneCore.md` already lists the exact padding/raw helper split; not edited.
- [x] Sibling/helper verification: [UID:000452], [UID:0004I5], and [UID:000455] left unchanged; no callback-time regression found.
- [x] Generated-output/freshness check: generated `Group.cpp`, memory coverage, and coverage report headers refreshed to validator command `000000007767`, timestamp `2026-07-07T01:45:25-04:00`; research tracker refreshed later to command `000000007768`, timestamp `2026-07-07T01:53:03-04:00`.
- [x] Scoped validator run: target file validator for `by-memory\0x00560ac0-0x00560ada.ScrollNewGroupPaneHideRaw.md`; support validators not run because support docs were not edited.
- [x] Claim And Incorporation Ledger update: accepted claims changed from `proposed` to `applied`, `already-present`, or `excluded-with-reason` with proof.
- [x] Forbidden actions avoided: did not run `execute_report`, dry-run/probing execute variants, registry lifecycle commands, manual report moves, archive moves, manual generated edits, manual coverage edits, validator-state edits, supervisor-ledger edits, lifecycle header/footer edits, or IDA DB edits.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation: Gate 1 passed at SHA256 `D6A1E9C5E77730989428256C77104645BBC3FE63A9E8228C299F6A236872A6A8`.
- [x] Target evidence and score update incorporated at report-level detail.
- [x] Support docs verified as already-present; none edited.
- [x] Formal C++ block preserved exactly.
- [x] Owner/emitter/reconstructable/position fields preserved exactly except for accepted score changes.
- [x] Negative evidence and open-question caveats preserved.
- [x] Scoped validator run and results recorded with command, command id, timestamp, exit code, and ok count.
- [x] Generated-output freshness checked: target generated outputs at `000000007767` and generated tracker newer at `000000007768`.
- [x] Claim And Incorporation Ledger updated with final verification states and proof.
- [x] Lease status: target lease acquired before edit and released after validator; final lease check found no active B006 lease for UID0004I3.
- [x] Remaining unapplied accepted items: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000007774","destination_path":"executed-b-agent-research/B006/0004I3-ScrollNewGroupPaneHideRaw-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B006/research/0004I3-ScrollNewGroupPaneHideRaw-source-quality.md","timestamp":"2026-07-07T01:57:22-04:00","uid":"0004I3"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
