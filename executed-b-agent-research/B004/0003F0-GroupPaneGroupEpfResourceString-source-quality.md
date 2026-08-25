
# UID0003F0 GroupPane GROUP.EPF Resource String Source-Quality Report
** TARGET-REPORT-UID:0003F0 **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

## Finalized Report / Current Recommendation

- Dated B004 callback phase (2026-08-14): accepted ordinary-document implementation completed. B004 changed the ordinary by-* docs under scoped validation; validator-owned UID/registry state and generated output changed through those commands. B004 did not edit manual coverage, tracker/audit/catalog/lifecycle state, or mutate IDA.
- Dated supervisor closure (2026-08-15): Gate 2B applied and saved I01-I05 and verified no change for I06, I07A-I07D, and I08; manual coverage M01-M07 was applied and validated by commands 23813-23815. Validator history records command 23816 execution followed by command 23817 de-execution-for-rework. Those are historical receipts; this report prose asserts no lifecycle status or artifact location.
- Current target state: `COMPLETION:94`, `CONFIDENCE:95`, `CANONICAL_OWNER:0000JS`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JS`, blank emitter position, formal CPP covered-by marker, and blank formal H.
- Final source disposition: `[0x00624a84,0x00624a98)` is the compiler/linker-pooled storage for the UTF-16 literal `L"GROUP.EPF"`. Human source spells that literal at the three Group-family paint use sites. The callback created exact owning [UID:00050R][GroupPane::OnPaint](by-memory/0x0056c6c0-0x0056c731.GroupPaneOnPaint.md) and [UID:00050S][GroupPane2::OnPaint](by-memory/0x0056c970-0x0056c9e1.GroupPane2OnPaint.md) children while retaining the existing `NewGroupPane::OnPaint` body. It declares no invented `aGroupEpf`, `wszGroupEpf`, global, member, array table, or public header symbol.
- The physical data child remains directly routed through [UID:0000JS] `Group.cpp` because all three consumers belong to that translation unit. It does not become class-owned merely because the use sites are methods.
- The target's prior empty generated emitter is resolved by the exact formal CPP marker in Section 22 together with UID00050R, UID00050S, and existing UID0004Z5. Coherent-refresh command 23774 completed before physical `Group.cpp` readback proved one complete body for each paint override, one actual `L"GROUP.EPF"` expression in each body, and no missing/empty emitter for either older method.

## Supporting Research

- Current target: `by-memory/0x00624a84-0x00624a98.GroupPaneGroupEpfResourceString.md`, UID0003F0, now `94/95` after the accepted callback and generated-source proof.
- Historical queue basis at assignment: `auto-generated/-ag-research-tracker.md`, `by-memory` -> `Not-Covered Files - Reconstructable`, direct/additional/total reports `0/0/0` before this report.
- Current source owner: [UID:0000JS] `by-file/Group.md`, generated route `auto-generated/NexusTK/social/Group.cpp` and companion `Group.h`.
- Current physical parent: [UID:0002V2] `by-memory/0x00624788-0x00624c60.LookGroupCollectionResourceStringData.md`.
- Consumer documentation checked: [UID:00005Y] `GroupPane`, [UID:00005Z] `GroupPane2`, [UID:000090] `NewGroupPane`, [UID:0001HC] `GroupPanes`, and [UID:0004Z5] `NewGroupPaneOnPaint`.
- ABI support checked: [UID:0002NJ] `GroupPaneVtableData`, [UID:0002NK] `GroupPane2VtableData`, and [UID:0002NL] `NewGroupPaneVtableData`.
- Resource-use precedent checked: [UID:00044V] `SharedTabsPaletteResourceString`, which already treats `TABS.PAL` as pooled use-site data and records the two older Group paint consumers.
- Matching prior research checked: archived B001 report `executed-b-agent-research/B001/0002V2-LookGroupCollectionResourceStringData.md`. Its split and Group-file assignment remain valid, while its open choice between a use-site literal and Group-local constant is resolved here.
- No dedicated by-resource, by-item, by-global, or by-type page currently owns `GROUP.EPF`; exact searches found no such owner. That absence is consistent with a method-use literal, not evidence for inventing a resource object.

## Target

- Primary UID: `0003F0`.
- Path: `by-memory/0x00624a84-0x00624a98.GroupPaneGroupEpfResourceString.md`.
- Exact half-open range: `[0x00624a84,0x00624a98)`.
- Size: `0x14` / 20 bytes.
- Segment role: read-only UTF-16 resource-name literal in a mixed `.rdata` island.
- Current metadata: `94/95`, owner/emitter UID0000JS, reconstructable true, exact covered-by CPP marker, blank H.
- Current item summary preserves the exact bytes/range, three assigned source children/use sites, pooled-literal disposition, and no-standalone-object route.

## Current Target State

- IDA item head `0x00624a84`, end `0x00624a98`, size 20, current name `aGroupEpf`, current type `const wchar_t[]`, data true, code false.
- Exact bytes are `47 00 52 00 4f 00 55 00 50 00 2e 00 45 00 50 00 46 00 00 00`.
- The bytes decode exactly to UTF-16LE `GROUP.EPF` followed by one UTF-16 null terminator. There is no trailing alignment inside this child.
- Exact byte SHA256: `D630EA44A97C6F9364A71C8A3FE55CCF0B521F58B800044D29E35833F6756D0D`.
- Predecessor item: head `0x00624a50`, end `0x00624a84`, size 52, name `asc_624A50`, IDA type string empty/absent; its bytes interpret as UTF-16LE `------------------------\n\0`, which is byte interpretation rather than IDA type evidence.
- Successor item: head `0x00624a98`, end `0x00624ab0`, size 24, name `aCollections`, IDA type string empty/absent; its bytes interpret as UTF-16LE `Collections\0`, which is byte interpretation rather than IDA type evidence.
- Exact inbound xrefs: three data refs from `0x0056c6fd`, `0x0056c9ad`, and `0x0056cf39`. Exact outbound xrefs: zero.
- Historical pre-callback generated state emitted UID0003F0 as an `Empty Emitter Marker`, with only the NewGroupPane use present. Current validator-generated `Group.cpp` now contains complete UID00050R, UID00050S, and UID0004Z5 paint bodies and the target marker.
- IDA remained read-only throughout B004's callback. The supervisor later completed and saved the bounded Gate 2B work described in Section 21. Manual coverage, generated artifacts by hand, tracker/audit/catalog/lifecycle files, and report execution remained outside B004 authority.

## Executive Recommendation

1. UID0003F0 was raised from `85/88` to `94/95` after both new owning method children, the covered-by marker, eight scoped validations, and the three-use generated readback passed.
2. Keep direct file ownership/emission at UID0000JS and keep the physical mixed parent UID0002V2 no-owner/non-emitting.
3. The target now carries the exact three-line covered-by marker and blank H. UID-less child creation was validated as commands 23763/23764, which assigned UID00050R and UID00050S and enabled canonical reference reconciliation.
4. The complete human-written Section 22 bodies now live in those children, route through UID00005Y and UID00005Z at class-local position `40`, and are documented across the target, Group file, both classes, GroupPanes aggregate, and physical parent.
5. The source-facing role of `0x0056c970` is corrected from historical `DrawTabBackground` to `GroupPane2::OnPaint`, supported by its corresponding vtable slot and structural twin.
6. The supervisor completed the bounded Section 21 IDA handoff: two pure function renames, two function-repeatable comments, one data address-repeatable comment, and the independent no-change protections all passed saved poststate readback. The historical contracts remain for audit evidence and are not replay proposals.
7. Do not create a standalone resource constant, new source file, by-resource owner, data global, class field, or isolated header declaration. The new children have exact blank H channels; their `OnPaint` declarations remain class-level declaration work and must not be emitted as free declarations.

## Supervisor Active Recheck

- Historical B004 evidence prestate: MCP session `supervisor-uid0000KZ-gate2b-20260814`, path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, active worker PID 15932, was enumerated on 2026-08-14 before report evidence collection.
- Historical health evidence: `server_health` returned `status:ok`, imagebase `0x400000`, Hex-Rays ready, and string cache ready with 2068 entries. `auto_analysis_ready:false` did not block any bounded item, byte, string, xref, type, name, comment, or disassembly query.
- Historical read-only calls returned stable bytes, item heads, three xrefs, consumer identities, comment-channel prestates, destination-name absence, and type-catalog results. B004 called no MCP mutation endpoint.
- Current saved supervisor poststate: `GroupPane__OnPaint` resolves only to `0x0056c6c0`, `GroupPane2__OnPaint` resolves only to `0x0056c970`, each function has its exact Section 21 FP comment, and target `0x00624a84` has its exact Section 21 AP comment. All protected signatures, frames, ranges, items, bytes, neighbor type absences, and xref sets passed unchanged readback.
- Saved canonical IDB identity after Gate 2B: 143,207,841 bytes, SHA256 `B16863A05EA9E22E4911EC228FE7BD0C25D6DBE1639E791A400D0E311CFA143B`, UTC `2026-08-15T05:16:26.0599562Z`.

## Inference Research Guidance Check

- Exact facts and inferred source shape are separated. Bytes, item boundaries, xrefs, function starts, vtable refs, current names/types/comments, and generated text are direct facts.
- Repeated literal spelling at the three use sites is an inference from the direct immediate-address loads, lack of any intermediate object, identical literal pooling, existing NewGroupPane formal source, and contemporaneous C++ practice.
- The inference does not preserve IDA's `aGroupEpf` label in human source. That label describes a binary string item; it is not evidence of an original identifier.
- The source recommendation prioritizes exact behavior first, human-written mid-2000s C++ source shape second, and project naming consistency third.
- Wave2/Wave3 terminology, if encountered in historical material, was ignored as stale process terminology and supplied no evidence.

## Heuristic / Inference Reanalysis And Validation

### Candidate 1: repeated method-local literals at all three use sites

- Positive: each consumer directly pushes/uses `0x00624a84`; there is no load through a pointer variable, member, accessor, resource registry, or table.
- Positive: the modern accepted `NewGroupPane::OnPaint` formal source already spells `L"GROUP.EPF"` inline in the normal-background branch.
- Positive: the two older paint bodies are 43-instruction structural twins and use the same inline `TABS.PAL` then `GROUP.EPF` lookup sequence.
- Positive: MSVC string pooling naturally explains one physical address for repeated identical literals in one translation unit.
- Negative considered: one file-local named array could also compile to direct addresses. No binary-only test can recover an erased identifier.
- Resolution: choose repeated use-site literals. It is the least invented and most human-plausible source shape, and it matches the already accepted NewGroupPane source.

### Candidate 2: one file-local named `static const wchar_t` object

- Positive: all consumers are in `Group.cpp`, so file scope would be legal.
- Negative: no pointer/global wrapper, initializer, data xref beyond the three code operands, symbol evidence, or project resource-name table supports such an object.
- Negative: naming it would manufacture an unused abstraction absent from current source style.
- Resolution: reject. Do not emit or document a speculative source identifier as if recovered.

### Candidate 3: a class member or class-owned constant

- Negative: the same bytes serve three distinct classes. No object field is loaded, no per-class storage exists, and the data is outside all object layouts.
- Resolution: reject class ownership and header declaration.

### Candidate 4: resource subsystem ownership

- Negative: `ResourceLayoutTable_LookupLayoutEntry` consumes the literal but does not own its call-site argument. No by-resource page or resource manager declaration contains the item.
- Resolution: reject ResourceLayoutTable, EPFLib, PaletteLib, or a synthetic resource file as owner.

### Candidate 5: non-reconstructable compiler-only data

- Negative: compiler pooling created the physical cell, but the source-declared literal is required to reproduce all three behaviors. By-structure treats such source-declared/generated-binary material as reconstructable.
- Resolution: retain `RECONSTRUCTABLE:TRUE` with a no-standalone-object marker.

## Evidence Standards Used

- Half-open range and physical item boundaries require raw bytes plus IDA item-head readback.
- Source ownership requires consumer/xref convergence and source-file evidence, not physical adjacency.
- A source name or declaration requires positive source-shape evidence; a descriptive IDA label alone is insufficient.
- A no-code/covered-by decision requires exact proof that source behavior belongs at consumer use sites and that standalone emission would duplicate or invent storage.
- IDA recommendations require literal current state, exact proposed delta, independent action classification, safety constraints, and expected readback.
- Scores remain below the final 95/95 barrier unless both behavior and source expression are essentially final.

## Evidence Checked

- MCP: `idb_list`, `server_health`, `get_bytes`, `inspect_items`, `get_string`, `get_comments`, `xref_query`, `lookup_funcs`, `find_bytes`, `type_query`, `func_profile`, and bounded `disasm`.
- Exact byte/pointer searches: full 20-byte UTF-16 literal once at `0x00624a84`; VA byte pattern `84 4a 62 00` exactly at `0x0056c6fe`, `0x0056c9ae`, and `0x0056cf3a`; RVA pattern `84 4a 22 00` absent.
- Consumer bodies: complete 43-instruction disassemblies for `0x0056c6c0` and `0x0056c970`; exact documented/formal `NewGroupPane::OnPaint` at `0x0056ce50`.
- Vtable routes: exact data refs from `0x00624480`, `0x0062450c`, and `0x00624598` to the three paint functions.
- Types: `NewGroupPane` ordinal 965, size `0x110`, 10 members; `EPFTileContext` ordinal 512, size `0x28`, seven members; exact `GroupPane` and `GroupPane2` UDTs absent.
- Documentation: target, physical parent, Group file, three class pages, GroupPanes aggregate, NewGroupPaneOnPaint child, three vtable pages, SharedTabsPaletteResourceString, generated Group CPP/H, current research tracker, generated memory coverage, and relevant manual coverage rows.
- Prior report: archived UID0002V2 split research; no direct prior UID0003F0 report existed.
- Negative checks: no outbound xrefs, no duplicate literal bytes, no RVA pointer pattern, no destination function-name collision, no dedicated by-resource/item/global/type owner, and no evidence for a named source object.
- Failed/unavailable checks: none required for this bounded target. B004 performed no IDA mutation; the accepted ordinary-document callback and validator actions are recorded under `## Validator Results`; no required evidence check failed.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C01 | 0003F0 | Exact range is `[0x00624a84,0x00624a98)`, 20 bytes, with byte SHA256 `D630EA44A97C6F9364A71C8A3FE55CCF0B521F58B800044D29E35833F6756D0D`. | Very high | MCP bytes and item readback | UID0003F0 Range, Evidence | incorporate | applied |
| C02 | 0003F0 | The item is exact UTF-16LE `GROUP.EPF\0`; predecessor ends at `0x00624a84` and successor starts at `0x00624a98`. | Very high | Bytes, strings, three item heads | UID0003F0 Range, Boundary Evidence | incorporate | applied |
| C03 | 0003F0 | The literal occurs once physically; the three VA operand hits are the three consumers and no RVA pattern exists. | Very high | `find_bytes` exact counts | UID0003F0 Search Evidence | incorporate | applied |
| C04 | 00005Y | Data xref `0x0056c6fd` is inside exact GroupPane paint override `[0x0056c6c0,0x0056c731)`. | Very high | Complete disassembly and vtable slot `0x00624480` | UID0003F0 consumers; GroupPane method notes | incorporate | applied |
| C05 | 00005Z | Data xref `0x0056c9ad` is inside exact GroupPane2 paint override `[0x0056c970,0x0056c9e1)`. | Very high | Complete disassembly, structural twin, vtable slot `0x0062450c` | UID0003F0 consumers; GroupPane2 method notes | incorporate | applied |
| C06 | 0004Z5 | Data xref `0x0056cf39` is inside `NewGroupPane::OnPaint`; current formal source already spells the normal branch as `L"GROUP.EPF"`. | Very high | Xref, vtable slot `0x00624598`, current formal/generated source | UID0003F0 consumers; UID0004Z5 check-only | already-present | already-present |
| C07 | 0003F0 | UID0000JS Group is the narrowest direct source owner because all three consumers belong to `Group.cpp`. | High | Three-consumer convergence and current source route | UID0003F0 ownership/metadata; Group file | incorporate | applied |
| C08 | 0002V2 | The mixed physical parent remains owner NONE, reconstructable false, and non-emitting; exact child UID0003F0 carries this source-local literal. | Very high | Cross-owner island inventory and exact child split | UID0002V2 split inventory | incorporate | applied |
| C09 | 0003F0 | No GroupPane class is canonical owner of the pooled cell because three sibling classes consume it. | High | Exact consumer set and class boundaries | UID0003F0 rejected alternatives | incorporate | applied |
| C10 | 0003F0 | Human source should repeat `L"GROUP.EPF"` at the three paint use sites. | High | Direct operands, pooling, existing NewGroupPane source, era style | UID0003F0 source disposition; Group source notes | incorporate | applied |
| C11 | 0003F0 | No named source constant/global/member/resource object should be invented from IDA label `aGroupEpf`. | High | Negative pointer/object/table/type evidence | UID0003F0 no-code proof and history | reject-invalid | excluded-with-reason |
| C12 | 0003F0 | Target metadata should become `94/95`, owner/emitter UID0000JS, reconstructable true, blank position, but only after all three generated literal use sites exist. | High | Complete three-consumer closure plan and exact source route | UID0003F0 metadata and score rationale | incorporate | applied |
| C13 | 0003F0 | Formal CPP should be the exact three-line covered-by marker in Section 22. | Very high | No-standalone-object proof and emitter requirement | UID0003F0 formal CPP | incorporate | applied |
| C14 | 0003F0 | Formal H remains exactly blank because a method-use literal declares no header entity. | Very high | Source disposition and no public symbol | UID0003F0 formal H | already-present | already-present |
| C15 | 0003F0 | Historical wording that declaration style was not final must be retained as dated history and superseded by the use-site-literal decision. | High | Current target history plus completed inference audit | UID0003F0 Historical Assumptions | historicalize | applied |
| C16 | 0000JS | Group file documentation should record exact literal bytes, three paint consumers, direct file-local route, and no named object. | High | Target evidence and source convergence | `by-file/Group.md` source/resource sections | incorporate | applied |
| C17 | 00005Y | GroupPane documentation should retain `OnPaint`, add exact `TABS.PAL` plus `GROUP.EPF` frame-0 lookup/blit behavior, attach the new method child, and add `[[CHILDREN]]` to its CPP marker. | Very high | Complete 43-instruction body and vtable slot | `by-class/GroupPane.md` method/evidence/emitter sections | incorporate | applied |
| C18 | 00005Z | GroupPane2 address `0x0056c970` should be documented as `OnPaint`, historicalize `DrawTabBackground`, and attach the new method child through its existing `[[CHILDREN]]` route. | Very high | Corresponding vtable slot and structural twin | `by-class/GroupPane2.md` method/evidence/history/emitter sections | incorporate | applied |
| C19 | 000090 | NewGroupPane class already has the accepted `OnPaint` role and needs no metadata or source change for this literal. | Very high | Current class and UID0004Z5 source | `by-class/NewGroupPane.md` check-only | already-present | already-present |
| C20 | 0001HC | GroupPanes aggregate should record all three exact target xrefs and normalize `0x0056c970` to GroupPane2 OnPaint while remaining non-emitting. | High | Aggregate inventory plus current MCP | UID0001HC consumer/resource evidence | incorporate | applied |
| C21 | 0004Z5 | NewGroupPaneOnPaint already emits the correct inline literal and remains `94/95`; no duplicate target marker belongs there. | Very high | Current formal CPP and generated readback | UID0004Z5 check-only | already-present | already-present |
| C22 | 0002V2 | Physical-parent child row should describe exact bytes, three consumers, and covered-by use-site emission rather than only the old split assignment. | High | Current item/xref/source decision | UID0002V2 child inventory | incorporate | applied |
| C23 | 00044V | Shared TABS.PAL page is compatible precedent and remains unchanged; it already maps the two older paint paths to Group.cpp use sites. | High | Current UID00044V content | UID00044V check-only | already-present | already-present |
| C24 | 0002NJ | GroupPane primary vtable slot `0x00624480 -> 0x0056c6c0` proves OnPaint; vtable metadata/content otherwise remain unchanged. | Very high | Exact vtable xref and current page | UID0002NJ check-only | already-present | already-present |
| C25 | 0002NK | GroupPane2 corresponding primary slot `0x0062450c -> 0x0056c970` proves OnPaint; vtable metadata/content otherwise remain unchanged. | Very high | Exact vtable xref and current page | UID0002NK check-only | already-present | already-present |
| C26 | 0002NL | NewGroupPane primary slot `0x00624598 -> 0x0056ce50` confirms the third OnPaint consumer; page remains unchanged. | Very high | Exact vtable xref and current page | UID0002NL check-only | already-present | already-present |
| C27 | 0003F0 | Generated Group.cpp should replace UID0003F0's empty marker with the exact formal covered-by marker and contain complete GroupPane, GroupPane2, and NewGroupPane OnPaint bodies with exactly three real `L"GROUP.EPF"` expressions. | High | Current generated defect, two new child plans, and existing UID0004Z5 | Generated-output expectation only | incorporate | applied |
| C28 | 0003F0 | Generated Group.h receives no UID0003F0 contribution because no declaration exists. | Very high | Blank formal H proof | Generated-output expectation only | not-applicable | excluded-with-reason |
| C29 | 0003F0 | Supervisor applied the exact new UID0003F0 manual by-memory coverage row from Section 28. | High | Command 23813, exit 0/ok 1 | Supervisor-owned by-memory coverage | incorporate | applied |
| C30 | 0000JS | Supervisor applied the manual by-file Group row with the three-literal-use route and retained Group-family detail. | High | Command 23814, exit 0/ok 1 | Supervisor-owned by-file coverage | incorporate | applied |
| C31 | 00005Y | Supervisor applied the manual GroupPane class row with exact OnPaint resource behavior and retained split/vtable/destructor detail. | High | Command 23815, exit 0/ok 1 | Supervisor-owned by-class coverage | incorporate | applied |
| C32 | 00005Z | Supervisor applied the manual GroupPane2 class row with exact OnPaint resource behavior replacing the generic draw wording. | High | Command 23815, exit 0/ok 1 | Supervisor-owned by-class coverage | incorporate | applied |
| C33 | 0001HC | Supervisor applied the manual GroupPanes aggregate row with the exact literal/xref source disposition and retained non-emitting inventory detail. | High | Command 23813, exit 0/ok 1 | Supervisor-owned by-memory coverage | incorporate | applied |
| C34 | 00005Y | Supervisor applied and verified I01 pure rename `sub_56C6C0 -> GroupPane__OnPaint` with signature/frame/comments/xrefs protected. | High | Saved Gate 2B I01 `APPLIED_VERIFIED` readback | Gate 2B I01 | incorporate | applied |
| C35 | 00005Y | Supervisor applied and verified I02 exact GroupPane function-repeatable paint comment only. | High | Saved Gate 2B I02 `APPLIED_VERIFIED` readback | Gate 2B I02 | incorporate | applied |
| C36 | 00005Z | Supervisor applied and verified I03 pure rename `sub_56C970 -> GroupPane2__OnPaint` with signature/frame/comments/xrefs protected. | High | Saved Gate 2B I03 `APPLIED_VERIFIED` readback | Gate 2B I03 | incorporate | applied |
| C37 | 00005Z | Supervisor applied and verified I04 exact GroupPane2 function-repeatable paint comment only. | High | Saved Gate 2B I04 `APPLIED_VERIFIED` readback | Gate 2B I04 | incorporate | applied |
| C38 | 0003F0 | Supervisor applied and verified I05 exact address-repeatable comment on the pooled literal. | High | Saved Gate 2B I05 `APPLIED_VERIFIED` readback | Gate 2B I05 | incorporate | applied |
| C39 | 0003F0 | Supervisor verified I06 no-change protection for the current data name/type/range/bytes/xrefs while permitting only I05 AP. | Very high | Saved Gate 2B I06 `NO_CHANGE_VERIFIED` readback | Gate 2B I06 | incorporate | already-present |
| C40 | 0004Z5 | Existing NewGroupPane function name, exact prototype, comment, and sole vtable xref are evidence-only context and need no Gate 2B action. | Very high | Exact current readback | UID0004Z5 and IDA facts, inspect-only | already-present | already-present |
| C41 | 00005Y | Supervisor verified I07A-I07D no-change protection: GroupPane/GroupPane2 UDTs remain absent and both exact prototypes/frames remain protected while only I01-I04 name/comment deltas are present. | Very high | Saved Gate 2B I07A-I07D `NO_CHANGE_VERIFIED` readbacks | Gate 2B I07A-I07D | not-applicable | already-present |
| C42 | 0003F0 | Supervisor verified I08 no-change protection for predecessor/target/successor item heads, boundaries, type states, bytes, comments, and xrefs except the independent I05 target AP. | Very high | Saved Gate 2B I08 `NO_CHANGE_VERIFIED` readback | Gate 2B I08 | already-present | already-present |
| C43 | 0003F0 | Callback validation registered both UID-less child files as UID00050R/UID00050S, reconciled canonical references, validated every changed by-* file, coherently refreshed Group.cpp/H, and physically verified the target marker plus all three actual literal uses. | High | Validator UID allocation, commands 23763-23774, and physical generated readback | Validator Results and checklist | incorporate | applied |
| C44 | 0003F0 | No third-party import directive applies; the item is first-party NexusTK Group source data. | Very high | Consumer/source ownership | UID0003F0 source disposition | not-applicable | excluded-with-reason |
| C45 | 0003F0 | No Wave2/Wave3 artifact supplies current evidence or implementation authority. | Very high | Current skill rule and independent evidence | UID0003F0 evidence provenance | reject-stale | excluded-with-reason |
| C46 | 00050R | Created `by-memory/0x0056c6c0-0x0056c731.GroupPaneOnPaint.md` UID-less; validator command 23763 allocated UID00050R and accepted references now use its canonical UID link. | Very high | Exact function boundary, canonical TMP contract, and absent-path check | New GroupPane OnPaint child and affected support inventories | incorporate | applied |
| C47 | 00050R | The GroupPane child covers exactly 113 bytes with SHA256 `60A9066D737851AF85F810A77E699BC4C6A522A3005762FD2EEFE75C1826F8E3` and emits the complete Section 22 `void GroupPane::OnPaint()` body. | Very high | Complete 43-instruction disassembly and exact byte readback | New GroupPane OnPaint child evidence and formal CPP | incorporate | applied |
| C48 | 00050R | The GroupPane child metadata is `94/95`, owner/emitter UID00005Y, reconstructable true, class-local position `40`, nested zero, with exact blank formal H. | High | Exact behavior plus existing GroupPane-to-Group.cpp route | New GroupPane OnPaint child metadata and formal H | incorporate | applied |
| C49 | 00050S | Created `by-memory/0x0056c970-0x0056c9e1.GroupPane2OnPaint.md` UID-less; validator command 23764 allocated UID00050S and accepted references now use its canonical UID link. | Very high | Exact function boundary, canonical TMP contract, and absent-path check | New GroupPane2 OnPaint child and affected support inventories | incorporate | applied |
| C50 | 00050S | The GroupPane2 child covers exactly 113 bytes with SHA256 `FD4698757D9BFFA6D1FFD9254A7BD71D28566ACAE9B6DE5E87F4BF01FB95BDAE` and emits the complete Section 22 `void GroupPane2::OnPaint()` body. | Very high | Complete 43-instruction disassembly and exact byte readback | New GroupPane2 OnPaint child evidence and formal CPP | incorporate | applied |
| C51 | 00050S | The GroupPane2 child metadata is `94/95`, owner/emitter UID00005Z, reconstructable true, class-local position `40`, nested zero, with exact blank formal H. | High | Exact behavior plus existing GroupPane2-to-Group.cpp route | New GroupPane2 OnPaint child metadata and formal H | incorporate | applied |
| C52 | 00005Y | GroupPane's class CPP marker must retain its no-class-body comments and gain one `[[CHILDREN]]` token so the new position-40 method child reaches Group.cpp. | Very high | Current marker lacks a child insertion token | `by-class/GroupPane.md` formal CPP | incorporate | applied |
| C53 | 00005Z | GroupPane2's existing single `[[CHILDREN]]` token is the correct route for the new position-40 method child and must remain unique. | Very high | Current class formal CPP readback | `by-class/GroupPane2.md` formal CPP check-only | already-present | already-present |
| C54 | 00005Y,00005Z | The two new child H channels remain exactly blank; no isolated `virtual void OnPaint();` declaration may be emitted outside a complete class declaration. | Very high | Current class H state and C++ declaration scoping | New child formal H sections and class H check-only | not-applicable | excluded-with-reason |
| C55 | 0001HC,0000JS | GroupPanes and Group inventory both exact child paths, assigned UIDs 00050R/00050S, class ownership, address order, byte hashes, and Group.cpp route. | High | Complete consumer bodies and current source topology | Aggregate and by-file child/source-order inventories | incorporate | applied |
| C56 | 0003F0 | Generated Group.cpp verification must find exactly one `GroupPane::OnPaint`, one `GroupPane2::OnPaint`, one `NewGroupPane::OnPaint`, and exactly three actual `L"GROUP.EPF"` expressions, with no empty/missing emitter for either new child. | Very high | Formal bodies and existing UID0004Z5 generated body | Physical generated CPP readback | incorporate | applied |
| C57 | 0003F0 | Generated Group.h verification must preserve the current NewGroupPane declaration, add no free-standing OnPaint declaration from either child, and show no UID0003F0 H contribution. | Very high | Exact blank child/target H disposition | Physical generated H readback | already-present | already-present |
| C58 | 00050R,00050S | Callback validation created the two UID-less children under required leases; commands 23763 and 23764 allocated UID00050R and UID00050S, accepted TMP references were replaced with canonical UID links, all changed files passed scoped validation, and every lease was released. | Very high | Validator UID allocation/TMP contract and leasing workflow | Validator Results and callback receipts | incorporate | applied |
| C59 | 00050R,00050S | Supervisor applied exact address-ordered manual by-memory coverage rows for UID00050R at `0x0056c6c0-0x0056c731` and UID00050S at `0x0056c970-0x0056c9e1`, each at `94%` with very-strong evidence. | High | Command 23813, exit 0/ok 1 | Supervisor-owned by-memory coverage | incorporate | applied |
| C60 | 0003F0 | The target covered-by marker became true after C46-C58 source work and the three-use generated readback passed; C59 manual coverage was then completed independently and did not gate generated-source truth. | Very high | Gate 1 failure, corrected closure dependency, and command 23813 | UID0003F0 status, score, and generated-output sections | incorporate | applied |
| C61 | 00050R,00050S | Source order is UID00050R under GroupPane position 40, then UID00050S under GroupPane2 position 40, then existing NewGroupPane position/address order; no method body is emitted from the data page. | High | Executable order and nested emitter topology | New children, class pages, Group source-order notes | incorporate | applied |
| C62 | 0003F0 | No complete GroupPane/GroupPane2 class declaration is introduced by this focused repair; child CPP bodies are exact, while class-level H completion remains broader class work and cannot be replaced by invalid free declarations. | High | Missing exact UDTs and current class-H evidence | First-Draft C++ and generated H disposition | not-applicable | excluded-with-reason |

## Positive Evidence Summary

- The exact 20-byte item is independently confirmed by bytes, item boundaries, and decoded string value.
- Three and only three inbound data xrefs resolve to GroupPane-family paint bodies in one source root.
- The two older bodies are complete structural twins that load `TABS.PAL`, load frame 0 of `GROUP.EPF`, and blit to pane bounds.
- All three function starts are independently bound to corresponding primary paint vtable slots.
- Current accepted NewGroupPane source already uses `L"GROUP.EPF"` inline, giving direct project-local source-shape precedent.
- The literal bytes are unique, and all raw VA operand hits correspond exactly to the three xrefs.
- Existing file ownership, aggregate split, and generated route all converge on UID0000JS.

## IDA MCP Facts

- Historical evidence session: `supervisor-uid0000KZ-gate2b-20260814`, read-only use on 2026-08-14, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, imagebase `0x400000`. The raw names and absent comments below are dated pre-mutation evidence, not current saved state.
- Target item remained `0x00624a84-0x00624a98`, `aGroupEpf`, `const wchar_t[]`, data, size 20.
- Historical target comments: AR absent; AP absent; FR not applicable; FP not applicable. Current saved comments: AR absent; AP exactly `Compiler/linker-pooled UTF-16 L"GROUP.EPF" literal referenced by GroupPane::OnPaint, GroupPane2::OnPaint, and NewGroupPane::OnPaint; source reconstruction keeps the literal at those use sites rather than declaring a standalone object.`; FR not applicable; FP not applicable.
- Target xrefs: count 3, exact set `{0x0056c6fd -> 0x00624a84 data, 0x0056c9ad -> 0x00624a84 data, 0x0056cf39 -> 0x00624a84 data}`. Outbound count 0.
- Function `0x0056c6c0`: historical name `sub_56C6C0`; current saved name `GroupPane__OnPaint`; range `[0x0056c6c0,0x0056c731)`, 43 instructions, exact protected `func_profile` prototype `int __thiscall(char *this)`, one vtable data xref from `0x00624480`. Bounded disassembly annotates the inherited drawing object as `GrafPort *`, but that annotation is not substituted for the literal prototype.
- Function `0x0056c970`: historical name `sub_56C970`; current saved name `GroupPane2__OnPaint`; range `[0x0056c970,0x0056c9e1)`, 43 instructions, exact protected `func_profile` prototype `int __thiscall(char *this)`, one vtable data xref from `0x0062450c`. Bounded disassembly likewise annotates the inherited drawing object as `GrafPort *`.
- Historical prestate for both older functions was AR absent; AP absent; FR absent; FP absent. Current `GroupPane__OnPaint` channels are AR absent; AP absent; FR absent; FP exactly `Paints the GroupPane background by loading frame 0 from GROUP.EPF with TABS.PAL and blitting it to the pane bounds.` Current `GroupPane2__OnPaint` channels are AR absent; AP absent; FR absent; FP exactly `Paints the GroupPane2 background by loading frame 0 from GROUP.EPF with TABS.PAL and blitting it to the pane bounds.` Their protected frames remain identical: `outContext` offset `0x0c`, size `0x28`, type `EPFTileContext`; `var_4` offset `0x34`, size `0x4`, type `_DWORD`; `__saved_registers` offset `0x38`, size `0x4`, type `_DWORD`; `__return_address` offset `0x3c`, size `0x4`, type `_UNKNOWN *`.
- Function `0x0056ce50`: `NewGroupPane__OnPaint`, range `[0x0056ce50,0x0056da03)`, exact current prototype `void __thiscall(NewGroupPane *this)`, one vtable data xref from `0x00624598`; AR absent; AP absent; FR absent; FP exactly `Renders NewGroupPane background, member rows, names, status, HP/MP bars, and numeric glyph strings.` This unchanged consumer is evidence-only context, not a Gate 2B action row.
- Historical destination lookups for `GroupPane__OnPaint` and `GroupPane2__OnPaint` returned not found. Current saved lookups bind them uniquely to `0x0056c6c0` and `0x0056c970`, respectively.
- Local types: exact GroupPane absent; exact GroupPane2 absent; NewGroupPane ordinal 965 size 272; EPFTileContext ordinal 512 size 40.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `[0x00624a84,0x00624a98)` | UID0003F0 target | Pooled UTF-16 `GROUP.EPF` storage | true | UID0000JS | current `94/95` | Exact formal covered-by marker verified with complete three-use source output |
| `[0x0056c6c0,0x0056c731)` | [UID:00050R][GroupPaneOnPaint](by-memory/0x0056c6c0-0x0056c731.GroupPaneOnPaint.md) | `GroupPane::OnPaint` consumer and owning body | true | UID00005Y | current `94/95`, position `40` | Exact Section 22 body emitted; H blank; scoped validations 23763 and 23765 passed |
| `[0x0056c970,0x0056c9e1)` | [UID:00050S][GroupPane2OnPaint](by-memory/0x0056c970-0x0056c9e1.GroupPane2OnPaint.md) | `GroupPane2::OnPaint` consumer and owning body | true | UID00005Z | current `94/95`, position `40` | Exact Section 22 body emitted; H blank; scoped validations 23764 and 23766 passed |
| `[0x0056ce50,0x0056da03)` | UID0004Z5 | `NewGroupPane::OnPaint` consumer | true | UID000090 | `94/95` unchanged | Exact inline literal already emitted |
| `[0x00624788,0x00624c60)` | UID0002V2 | Mixed physical resource/constant index | false | none | `88/92` unchanged | Non-emitting parent; target remains exact child |
| `0x00624480` | UID0002NJ | GroupPane primary paint slot | generated-binary | UID0001XP | `88/92` unchanged | Confirms first consumer role |
| `0x0062450c` | UID0002NK | GroupPane2 corresponding paint slot | generated-binary | UID0001XP | `88/92` unchanged | Confirms second consumer role |
| `0x00624598` | UID0002NL | NewGroupPane primary paint slot | generated-binary | UID0001XP | `91/95` unchanged | Confirms third consumer role |

No function body, vtable, UDT, import, global, resource object, padding child, RTTI record, or compiler thunk lies inside the 20-byte data target. The source-output closure scope nevertheless includes the two exact consumer bodies whose absence made the prior covered-by claim false. Those bodies stay in their own exact by-memory ranges and class owners; the data target does not absorb their ranges.

## Direct Xref / Caller Inventory

| Literal xref | Containing function | Function inbound route | Exact use |
| --- | --- | --- | --- |
| `0x0056c6fd` | `[0x0056c6c0,0x0056c731)` current `GroupPane__OnPaint` (historical `sub_56C6C0`) | `0x00624480 -> 0x0056c6c0`, data/vtable | Passes `L"GROUP.EPF"`, frame 0, and local EPFTileContext to ResourceLayoutTable lookup. |
| `0x0056c9ad` | `[0x0056c970,0x0056c9e1)` current `GroupPane2__OnPaint` (historical `sub_56C970`) | `0x0062450c -> 0x0056c970`, data/vtable | Same frame-0 resource lookup for GroupPane2. |
| `0x0056cf39` | `[0x0056ce50,0x0056da03)` `NewGroupPane__OnPaint` | `0x00624598 -> 0x0056ce50`, data/vtable | Normal background branch; expanded branch chooses `L"ITEMINVE.EPF"` frame 3. |

- No direct caller invokes the literal; xrefs are immediate data operands inside the consumers.
- No code/data xref originates from the target.
- No fourth code, data, immediate, VA, RVA, or raw pointer route exists in the bounded searches.
- Current saved caller identities/comments are `GroupPane__OnPaint` with FP `Paints the GroupPane background by loading frame 0 from GROUP.EPF with TABS.PAL and blitting it to the pane bounds.` and `GroupPane2__OnPaint` with FP `Paints the GroupPane2 background by loading frame 0 from GROUP.EPF with TABS.PAL and blitting it to the pane bounds.` Target `0x00624a84` has AP `Compiler/linker-pooled UTF-16 L"GROUP.EPF" literal referenced by GroupPane::OnPaint, GroupPane2::OnPaint, and NewGroupPane::OnPaint; source reconstruction keeps the literal at those use sites rather than declaring a standalone object.` The exact xref sets above remained unchanged.

## Documentation Evidence And IDA Status

- Target page: exact split/file assignment retained; evidence, pooled-use disposition, historical assumption, formal marker, and `94/95` current metadata are now complete.
- Group file: current source root now includes the exact `GROUP.EPF` pooling decision, three method routes, source order, hashes, and generated acceptance criteria.
- GroupPane: UID00050R is attached at position `40`; its class CPP marker now has exactly one `[[CHILDREN]]`, and exact palette/frame/blit evidence plus target linkage are documented.
- GroupPane2: UID00050S is attached through the preserved single `[[CHILDREN]]`; the method row is now `OnPaint`, with `DrawTabBackground` retained only as a historical descriptive alias.
- NewGroupPane and UID0004Z5: already source-ready and correct; inspect-only for this target.
- UID0001HC: now preserves both exact method children, byte hashes, source order, target xrefs, and normalized GroupPane2 method role while remaining non-emitting.
- UID0002V2: child inventory now carries exact bytes/hash, three use-site routes, and the pooled-literal no-object disposition while preserving mixed-parent metadata.
- UID00044V: accepted no-standalone string-pool precedent; no edit needed.
- Current saved IDA: target name/type remains `aGroupEpf` / `const wchar_t[]`; `GroupPane__OnPaint` has FP `Paints the GroupPane background by loading frame 0 from GROUP.EPF with TABS.PAL and blitting it to the pane bounds.`; `GroupPane2__OnPaint` has FP `Paints the GroupPane2 background by loading frame 0 from GROUP.EPF with TABS.PAL and blitting it to the pane bounds.`; target `0x00624a84` has AP `Compiler/linker-pooled UTF-16 L"GROUP.EPF" literal referenced by GroupPane::OnPaint, GroupPane2::OnPaint, and NewGroupPane::OnPaint; source reconstruction keeps the literal at those use sites rather than declaring a standalone object.` NewGroupPane's existing FP remains unchanged. The dated raw-name/comment-absent prestate is retained only as historical evidence above.
- Generated Group.cpp: command 23774 replaced the target empty marker with its covered-by comment and emitted one complete UID00050R body, one complete UID00050S body, and the existing complete NewGroupPane body. Generated Group.h has no target/new-child contribution or free-standing declaration.

## Ranked Ownership Analysis

1. **UID0000JS Group file, accepted, 95/100.** All three exact consumers are Group-family methods routed into `Group.cpp`; no other source file consumes the literal.
2. **No canonical owner with three class emitters, rejected, 60/100.** This would model compiler pooling but discard the stronger fact that all consumers share one translation unit and one current file emitter.
3. **UID00005Y GroupPane class, rejected, 35/100.** GroupPane is only one of three sibling consumers.
4. **UID000090 NewGroupPane class, rejected, 30/100.** It has the most complete source but does not own the two older uses.
5. **ResourceLayoutTable/EPFLib resource subsystem, rejected, 10/100.** Loader APIs consume the argument and do not own caller literals.
6. **Synthetic resource/constants file, rejected, 5/100.** No source root, table, accessor, pointer cell, or cross-file declaration supports it.

## Source Placement

- Physical binary placement: `.rdata` child `[0x00624a84,0x00624a98)` inside UID0002V2.
- Human source placement: repeated `L"GROUP.EPF"` arguments in `GroupPane::OnPaint`, `GroupPane2::OnPaint`, and `NewGroupPane::OnPaint` in `NexusTK/social/Group.cpp`.
- Documentation emitter placement: UID0003F0 remains emitted through UID0000JS and contributes only the formal covered-by marker. The new `GroupPane::OnPaint` child emits through UID00005Y at class-local position `40`; the new `GroupPane2::OnPaint` child emits through UID00005Z at class-local position `40`; UID0004Z5 remains the third method emitter.
- Header placement: UID0003F0 and both new method children have exactly blank H channels. The literal creates no declaration, and a bare `virtual void OnPaint();` cannot be emitted outside a complete class declaration. Current GroupPane/GroupPane2 class H blocks remain unchanged in this focused repair.
- Source order: `GroupPane` class and its position-40 OnPaint child precede `GroupPane2` and its position-40 OnPaint child, followed later by the existing NewGroupPane method family. The target marker can remain at UID0003F0's routed data position because it documents binary coverage rather than defining an object.

## Range / Split / Padding / Reclassification Analysis

- Start `0x00624a84` is an exact item head and follows the prior string's terminator at `0x00624a84`.
- End `0x00624a98` is both the target end and exact successor item head.
- All 20 bytes belong to the literal including its one two-byte terminator; no internal padding or second literal exists.
- No split is needed. Splitting the terminator, merging the predecessor, or absorbing `Collections` would violate IDA item and string boundaries.
- The parent UID0002V2 remains a physical mixed-owner index. Reclassifying only the child as source-local reconstructable evidence remains correct.
- No new by-item, by-global, by-type, by-resource, RTTI, or vtable child is warranted for this data range.
- Two new by-memory method children are warranted outside the data range solely to close the two missing source use sites: `[0x0056c6c0,0x0056c731)` and `[0x0056c970,0x0056c9e1)`. They do not change UID0003F0's boundaries or ownership.

## Negative Evidence Summary

- No intermediate pointer/global/member is read before any use.
- No duplicate physical UTF-16 literal exists.
- No outbound xref or table entry originates from the target.
- No RVA pointer pattern exists; all three VA pattern matches are instruction operands already accounted for.
- No original source symbol survives, and `aGroupEpf` is an IDA data label rather than a defensible developer identifier.
- No GroupPane or GroupPane2 UDT currently exists in IDA, so this report cannot safely type their functions without broader class-layout work.
- No dedicated resource/global/type/item documentation owner exists.
- Physical adjacency to SpelledPane and CollectionPane strings does not imply shared source ownership.
- A file-local named array remains theoretically possible but is less supported than repeated use-site literals and would add an unnecessary human abstraction.
- Current GroupPane/GroupPane2 class H declarations remain incomplete. This prevents claiming final class-header closure, but it does not justify omitting the exact independently owned CPP method bodies or inventing free-standing declarations.

## IDA Rename / Type / Comment Recommendations

All rows originated as a dated 2026-08-14 read-only handoff. Fresh 2026-08-15 Gate 2B preflight in session `supervisor-uid0000IA-rollback-20260815` failed closed before mutation and corrected I08's predecessor/successor IDA type strings to literal empty/absent state; that session identifier is dated evidence only. The supervisor later reread every literal prestate and completed the bounded handoff. The contracts below remain historical Gate 2B authority and audit evidence; they are not replay proposals.

| ID | Classification | Public endpoint | Exact historical pre-action prestate | Proposed action | Safety and protected state | Exact expected readback |
| --- | --- | --- | --- | --- | --- | --- |
| I01 | apply | `rename`, function batch, `pure:true` | Function `[0x0056c6c0,0x0056c731)`, name `sub_56C6C0`, destination `GroupPane__OnPaint` absent; exact prototype at the historical pre-action readback `int __thiscall(char *this)`; complete physical frame rows: `outContext` at `+0x0c`, width `0x28`, type `EPFTileContext`; `var_4` at `+0x34`, width `0x4`, type `_DWORD`; `__saved_registers` at `+0x38`, width `0x4`, type `_DWORD`; `__return_address` at `+0x3c`, width `0x4`, type `_UNKNOWN *`; AR absent; AP absent; FR absent; FP absent; inbound xref count 1, exact set `{0x00624480 -> 0x0056c6c0 data}`. | Rename only to `GroupPane__OnPaint`. | No overwrite; no function-directory/decompiler/type/frame/comment/item/xref change. Stop on source-name/range/destination collision or any prestate mismatch. | Function remains `[0x0056c6c0,0x0056c731)` with name exactly `GroupPane__OnPaint`; destination resolves only to `0x0056c6c0`; exact prototype remains `int __thiscall(char *this)`; physical frame rows remain `outContext` at `+0x0c`, width `0x28`, type `EPFTileContext`; `var_4` at `+0x34`, width `0x4`, type `_DWORD`; `__saved_registers` at `+0x38`, width `0x4`, type `_DWORD`; `__return_address` at `+0x3c`, width `0x4`, type `_UNKNOWN *`; AR absent; AP absent; FR absent; FP absent; instructions remain unchanged; inbound xref count remains 1 with exact set `{0x00624480 -> 0x0056c6c0 data}`. |
| I02 | apply | `set_repeatable_comments` | Function object exists at exact range `[0x0056c6c0,0x0056c731)`. Before its sole dependency I01, its name is `sub_56C6C0` and destination `GroupPane__OnPaint` is absent; the required I01 post-rename precondition is that `GroupPane__OnPaint` resolves only to `0x0056c6c0`. Exact prototype is `int __thiscall(char *this)`. Complete physical frame rows are `outContext` at `+0x0c`, width `0x28`, type `EPFTileContext`; `var_4` at `+0x34`, width `0x4`, type `_DWORD`; `__saved_registers` at `+0x38`, width `0x4`, type `_DWORD`; and `__return_address` at `+0x3c`, width `0x4`, type `_UNKNOWN *`. AR absent; AP absent; FR absent; FP absent. Inbound xref count 1, exact set `{0x00624480 -> 0x0056c6c0 data}`; outbound function xref state is not changed by this action. | After verified I01 only, set FP exactly `Paints the GroupPane background by loading frame 0 from GROUP.EPF with TABS.PAL and blitting it to the pane bounds.` | Stop if I01 did not leave the sole destination binding `GroupPane__OnPaint -> 0x0056c6c0`, if the exact range/prototype/frame/comments/xref prestate differs, or if a destination collision exists. Change FP only; preserve name, prototype, every physical frame row, AR, AP, FR, bytes, function range, instructions, and the exact inbound xref set. | Function object remains `[0x0056c6c0,0x0056c731)`, name `GroupPane__OnPaint`, with destination resolving only to `0x0056c6c0`; prototype remains `int __thiscall(char *this)`; frame remains `outContext +0x0c/0x28 EPFTileContext`, `var_4 +0x34/0x4 _DWORD`, `__saved_registers +0x38/0x4 _DWORD`, `__return_address +0x3c/0x4 _UNKNOWN *`; AR absent; AP absent; FR absent; FP equals the exact proposed text; inbound xref count remains 1 with exact set `{0x00624480 -> 0x0056c6c0 data}`. |
| I03 | apply | `rename`, function batch, `pure:true` | Function `[0x0056c970,0x0056c9e1)`, name `sub_56C970`, destination `GroupPane2__OnPaint` absent; exact prototype at the historical pre-action readback `int __thiscall(char *this)`; complete physical frame rows: `outContext` at `+0x0c`, width `0x28`, type `EPFTileContext`; `var_4` at `+0x34`, width `0x4`, type `_DWORD`; `__saved_registers` at `+0x38`, width `0x4`, type `_DWORD`; `__return_address` at `+0x3c`, width `0x4`, type `_UNKNOWN *`; AR absent; AP absent; FR absent; FP absent; inbound xref count 1, exact set `{0x0062450c -> 0x0056c970 data}`. | Rename only to `GroupPane2__OnPaint`. | No overwrite; preserve type/frame/comments/item/xrefs. Stop on source-name/range/destination collision or any prestate mismatch. | Function remains `[0x0056c970,0x0056c9e1)` with name exactly `GroupPane2__OnPaint`; destination resolves only to `0x0056c970`; exact prototype remains `int __thiscall(char *this)`; physical frame rows remain `outContext` at `+0x0c`, width `0x28`, type `EPFTileContext`; `var_4` at `+0x34`, width `0x4`, type `_DWORD`; `__saved_registers` at `+0x38`, width `0x4`, type `_DWORD`; `__return_address` at `+0x3c`, width `0x4`, type `_UNKNOWN *`; AR absent; AP absent; FR absent; FP absent; instructions remain unchanged; inbound xref count remains 1 with exact set `{0x0062450c -> 0x0056c970 data}`. |
| I04 | apply | `set_repeatable_comments` | Function object exists at exact range `[0x0056c970,0x0056c9e1)`. Before its sole dependency I03, its name is `sub_56C970` and destination `GroupPane2__OnPaint` is absent; the required I03 post-rename precondition is that `GroupPane2__OnPaint` resolves only to `0x0056c970`. Exact prototype is `int __thiscall(char *this)`. Complete physical frame rows are `outContext` at `+0x0c`, width `0x28`, type `EPFTileContext`; `var_4` at `+0x34`, width `0x4`, type `_DWORD`; `__saved_registers` at `+0x38`, width `0x4`, type `_DWORD`; and `__return_address` at `+0x3c`, width `0x4`, type `_UNKNOWN *`. AR absent; AP absent; FR absent; FP absent. Inbound xref count 1, exact set `{0x0062450c -> 0x0056c970 data}`; outbound function xref state is not changed by this action. | After verified I03 only, set FP exactly `Paints the GroupPane2 background by loading frame 0 from GROUP.EPF with TABS.PAL and blitting it to the pane bounds.` | Stop if I03 did not leave the sole destination binding `GroupPane2__OnPaint -> 0x0056c970`, if the exact range/prototype/frame/comments/xref prestate differs, or if a destination collision exists. Change FP only; preserve name, prototype, every physical frame row, AR, AP, FR, bytes, function range, instructions, and the exact inbound xref set. | Function object remains `[0x0056c970,0x0056c9e1)`, name `GroupPane2__OnPaint`, with destination resolving only to `0x0056c970`; prototype remains `int __thiscall(char *this)`; frame remains `outContext +0x0c/0x28 EPFTileContext`, `var_4 +0x34/0x4 _DWORD`, `__saved_registers +0x38/0x4 _DWORD`, `__return_address +0x3c/0x4 _UNKNOWN *`; AR absent; AP absent; FR absent; FP equals the exact proposed text; inbound xref count remains 1 with exact set `{0x0062450c -> 0x0056c970 data}`. |
| I05 | apply | `set_address_repeatable_comments` | Data item kind data/code false, range `[0x00624a84,0x00624a98)`, literal width 20, name `aGroupEpf`, type `const wchar_t[]`; AR absent; AP absent; FR not applicable; FP not applicable; bytes hash `D630EA44A97C6F9364A71C8A3FE55CCF0B521F58B800044D29E35833F6756D0D`; inbound xref count 3, exact set `{0x0056c6fd data, 0x0056c9ad data, 0x0056cf39 data}`; outbound count 0. | Set AP exactly `Compiler/linker-pooled UTF-16 L"GROUP.EPF" literal referenced by GroupPane::OnPaint, GroupPane2::OnPaint, and NewGroupPane::OnPaint; source reconstruction keeps the literal at those use sites rather than declaring a standalone object.` | Change AP only. Preserve AR, item kind data/code false, name, type, literal width 20, bytes, item heads, and exact xref sets. | AP equals the exact proposed text; AR absent; item kind remains data/code false; range remains `[0x00624a84,0x00624a98)` with literal width 20; name remains `aGroupEpf`; type remains `const wchar_t[]`; bytes hash remains `D630EA44A97C6F9364A71C8A3FE55CCF0B521F58B800044D29E35833F6756D0D`; FR not applicable; FP not applicable; inbound xref count remains 3 with exact set `{0x0056c6fd data, 0x0056c9ad data, 0x0056cf39 data}`; outbound count remains 0. |
| I06 | no change recommended | none | Exact data item: kind data/code false, start `0x00624a84`, end `0x00624a98`, width 20, name `aGroupEpf`, type `const wchar_t[]`; bytes `47 00 52 00 4F 00 55 00 50 00 2E 00 45 00 50 00 46 00 00 00`; byte SHA256 `D630EA44A97C6F9364A71C8A3FE55CCF0B521F58B800044D29E35833F6756D0D`; decoded UTF-16LE `GROUP.EPF\0`; AR absent; AP absent; FR not applicable; FP not applicable. Inbound xref count 3, exact set `{0x0056c6fd -> 0x00624a84 data, 0x0056c9ad -> 0x00624a84 data, 0x0056cf39 -> 0x00624a84 data}`; outbound xref count 0, exact set `{}`. | Do not rename data, set type, make data, merge/split items, or create a source-object label. | I05 may change only AP to `Compiler/linker-pooled UTF-16 L"GROUP.EPF" literal referenced by GroupPane::OnPaint, GroupPane2::OnPaint, and NewGroupPane::OnPaint; source reconstruction keeps the literal at those use sites rather than declaring a standalone object.` All other literal state is protected. | Kind remains data/code false; start `0x00624a84`, end `0x00624a98`, width 20, name `aGroupEpf`, type `const wchar_t[]`; bytes remain `47 00 52 00 4F 00 55 00 50 00 2E 00 45 00 50 00 46 00 00 00`, SHA256 `D630EA44A97C6F9364A71C8A3FE55CCF0B521F58B800044D29E35833F6756D0D`, decoded `GROUP.EPF\0`; AR absent; AP equals the exact permitted I05 text; FR not applicable; FP not applicable; inbound count remains 3 with exact set `{0x0056c6fd -> 0x00624a84 data, 0x0056c9ad -> 0x00624a84 data, 0x0056cf39 -> 0x00624a84 data}`; outbound count remains 0 with exact set `{}`. |
| I07A | no change recommended | none | Exact-name type readback for `GroupPane`: absent, result count 0; therefore no ordinal, size, or member list exists. | Do not declare, import, rename, or modify a `GroupPane` UDT in this target pass. | The source class shape is not proven by this literal assignment; no type action is authorized. | Exact-name type readback for `GroupPane` remains absent with result count 0 and no ordinal, size, or members. |
| I07B | no change recommended | none | Exact-name type readback for `GroupPane2`: absent, result count 0; therefore no ordinal, size, or member list exists. | Do not declare, import, rename, or modify a `GroupPane2` UDT in this target pass. | The source class shape is not proven by this literal assignment; no type action is authorized. | Exact-name type readback for `GroupPane2` remains absent with result count 0 and no ordinal, size, or members. |
| I07C | no change recommended | none | Function object exists at range `[0x0056c6c0,0x0056c731)`, historical pre-action name `sub_56C6C0`, exact prototype at the historical pre-action readback `int __thiscall(char *this)`. Complete frame: `outContext` `+0x0c/0x28 EPFTileContext`; `var_4` `+0x34/0x4 _DWORD`; `__saved_registers` `+0x38/0x4 _DWORD`; `__return_address` `+0x3c/0x4 _UNKNOWN *`. AR absent; AP absent; FR absent; FP absent. Inbound xref count 1, exact set `{0x00624480 -> 0x0056c6c0 data}`. | Do not call `set_type`, rename stack/frame rows, resize/retype the frame, or change AR/AP/FR. Independent I01 may change only the function name to `GroupPane__OnPaint`; independent I02 may change only FP to its exact proposed text. | No type/frame/local action is authorized; stop if any historical pre-action literal function state differs before the independent permitted rows. | Function object remains `[0x0056c6c0,0x0056c731)`, post-I01 name `GroupPane__OnPaint`, prototype `int __thiscall(char *this)`; frame remains `outContext +0x0c/0x28 EPFTileContext`, `var_4 +0x34/0x4 _DWORD`, `__saved_registers +0x38/0x4 _DWORD`, `__return_address +0x3c/0x4 _UNKNOWN *`; AR absent; AP absent; FR absent; post-I02 FP exactly `Paints the GroupPane background by loading frame 0 from GROUP.EPF with TABS.PAL and blitting it to the pane bounds.`; inbound xref count remains 1 with exact set `{0x00624480 -> 0x0056c6c0 data}`. |
| I07D | no change recommended | none | Function object exists at range `[0x0056c970,0x0056c9e1)`, historical pre-action name `sub_56C970`, exact prototype at the historical pre-action readback `int __thiscall(char *this)`. Complete frame: `outContext` `+0x0c/0x28 EPFTileContext`; `var_4` `+0x34/0x4 _DWORD`; `__saved_registers` `+0x38/0x4 _DWORD`; `__return_address` `+0x3c/0x4 _UNKNOWN *`. AR absent; AP absent; FR absent; FP absent. Inbound xref count 1, exact set `{0x0062450c -> 0x0056c970 data}`. | Do not call `set_type`, rename stack/frame rows, resize/retype the frame, or change AR/AP/FR. Independent I03 may change only the function name to `GroupPane2__OnPaint`; independent I04 may change only FP to its exact proposed text. | No type/frame/local action is authorized; stop if any historical pre-action literal function state differs before the independent permitted rows. | Function object remains `[0x0056c970,0x0056c9e1)`, post-I03 name `GroupPane2__OnPaint`, prototype `int __thiscall(char *this)`; frame remains `outContext +0x0c/0x28 EPFTileContext`, `var_4 +0x34/0x4 _DWORD`, `__saved_registers +0x38/0x4 _DWORD`, `__return_address +0x3c/0x4 _UNKNOWN *`; AR absent; AP absent; FR absent; post-I04 FP exactly `Paints the GroupPane2 background by loading frame 0 from GROUP.EPF with TABS.PAL and blitting it to the pane bounds.`; inbound xref count remains 1 with exact set `{0x0062450c -> 0x0056c970 data}`. |
| I08 | no change recommended | none | Predecessor: kind data/code false, start `0x00624a50`, end `0x00624a84`, width 52, name `asc_624A50`, IDA type string empty/absent, bytes `2D 00 2D 00 2D 00 2D 00 2D 00 2D 00 2D 00 2D 00 2D 00 2D 00 2D 00 2D 00 2D 00 2D 00 2D 00 2D 00 2D 00 2D 00 2D 00 2D 00 2D 00 2D 00 2D 00 2D 00 2D 00 0A 00 00 00`, SHA256 `B405817BEE0B323F2394E2B6A7E08C57877A8B7004808F826908187609792162`; the bytes independently interpret as UTF-16LE `------------------------\n\0`, and that decoding is byte interpretation rather than IDA type evidence; AR absent; AP absent; FR not applicable; FP not applicable; inbound xref count 1, exact set `{0x0056bfc1 -> 0x00624a50 data}`; outbound count 0, set `{}`. Target: kind data/code false, start `0x00624a84`, end `0x00624a98`, width 20, name `aGroupEpf`, type `const wchar_t[]`, bytes `47 00 52 00 4F 00 55 00 50 00 2E 00 45 00 50 00 46 00 00 00`, SHA256 `D630EA44A97C6F9364A71C8A3FE55CCF0B521F58B800044D29E35833F6756D0D`, decoded `GROUP.EPF\0`; AR absent; AP absent; FR not applicable; FP not applicable; inbound xref count 3, exact set `{0x0056c6fd -> 0x00624a84 data, 0x0056c9ad -> 0x00624a84 data, 0x0056cf39 -> 0x00624a84 data}`; outbound count 0, set `{}`. Successor: kind data/code false, start `0x00624a98`, end `0x00624ab0`, width 24, name `aCollections`, IDA type string empty/absent, bytes `43 00 6F 00 6C 00 6C 00 65 00 63 00 74 00 69 00 6F 00 6E 00 73 00 00 00`, SHA256 `E30E67EFC77048C55A4842DE279C5F3E4F5AC4CB534474E6DF8F67A68C2BD557`; the bytes independently interpret as UTF-16LE `Collections\0`, and that decoding is byte interpretation rather than IDA type evidence; AR absent; AP absent; FR not applicable; FP not applicable; inbound xref count 4, exact set `{0x0056ea80 -> 0x00624a98 data, 0x0056ead3 -> 0x00624a98 data, 0x0056f8cc -> 0x00624a98 data, 0x0056f966 -> 0x00624a98 data}`; outbound count 0, set `{}`. | Preserve all three exact item heads, ends, kinds, widths, names, literal type states, bytes, byte-decoded strings, comments, and xref sets: predecessor and successor IDA type strings remain empty/absent, while the target remains typed `const wchar_t[]`. The sole permitted delta, performed only by independent I05, is target AP becoming `Compiler/linker-pooled UTF-16 L"GROUP.EPF" literal referenced by GroupPane::OnPaint, GroupPane2::OnPaint, and NewGroupPane::OnPaint; source reconstruction keeps the literal at those use sites rather than declaring a standalone object.` | No undefine, make-data, retyping, merge, split, string recreation, boundary adjustment, neighbor type assignment, neighbor comment change, or xref change. | Predecessor remains data/code false `[0x00624a50,0x00624a84)`, width 52, `asc_624A50`, with IDA type string empty/absent, exact bytes and SHA256 `B405817BEE0B323F2394E2B6A7E08C57877A8B7004808F826908187609792162`; the unchanged bytes interpret as UTF-16LE `------------------------\n\0`, not as IDA type evidence; AR absent, AP absent, FR/FP not applicable, inbound set `{0x0056bfc1 -> 0x00624a50 data}`, outbound `{}`. Target remains data/code false `[0x00624a84,0x00624a98)`, width 20, `aGroupEpf`, `const wchar_t[]`, exact bytes and SHA256 `D630EA44A97C6F9364A71C8A3FE55CCF0B521F58B800044D29E35833F6756D0D`, decoded `GROUP.EPF\0`, AR absent, AP exactly `Compiler/linker-pooled UTF-16 L"GROUP.EPF" literal referenced by GroupPane::OnPaint, GroupPane2::OnPaint, and NewGroupPane::OnPaint; source reconstruction keeps the literal at those use sites rather than declaring a standalone object.`, FR/FP not applicable, inbound set `{0x0056c6fd -> 0x00624a84 data, 0x0056c9ad -> 0x00624a84 data, 0x0056cf39 -> 0x00624a84 data}`, outbound `{}`. Successor remains data/code false `[0x00624a98,0x00624ab0)`, width 24, `aCollections`, with IDA type string empty/absent, exact bytes and SHA256 `E30E67EFC77048C55A4842DE279C5F3E4F5AC4CB534474E6DF8F67A68C2BD557`; the unchanged bytes interpret as UTF-16LE `Collections\0`, not as IDA type evidence; AR absent, AP absent, FR/FP not applicable, inbound set `{0x0056ea80 -> 0x00624a98 data, 0x0056ead3 -> 0x00624a98 data, 0x0056f8cc -> 0x00624a98 data, 0x0056f966 -> 0x00624a98 data}`, outbound `{}`. |

Evidence-only type context outside the action/protection rows: `NewGroupPane` remains ordinal 965, size 272, 10 members, and `EPFTileContext` remains ordinal 512, size 40, seven members. Neither type is an action target or required protected poststate for this bounded handoff.

Supervisor Gate 2B completion results:

| ID | Result | Saved poststate |
| --- | --- | --- |
| I01 | `APPLIED_VERIFIED` | `GroupPane__OnPaint` resolves only to `0x0056c6c0`; signature, complete frame, comments, bytes/range, instructions, and exact single vtable xref remained protected. |
| I02 | `APPLIED_VERIFIED` | FP is exactly `Paints the GroupPane background by loading frame 0 from GROUP.EPF with TABS.PAL and blitting it to the pane bounds.`; AR/AP/FR and all other protected state remained unchanged. |
| I03 | `APPLIED_VERIFIED` | `GroupPane2__OnPaint` resolves only to `0x0056c970`; signature, complete frame, comments, bytes/range, instructions, and exact single vtable xref remained protected. |
| I04 | `APPLIED_VERIFIED` | FP is exactly `Paints the GroupPane2 background by loading frame 0 from GROUP.EPF with TABS.PAL and blitting it to the pane bounds.`; AR/AP/FR and all other protected state remained unchanged. |
| I05 | `APPLIED_VERIFIED` | Target AP is exactly `Compiler/linker-pooled UTF-16 L"GROUP.EPF" literal referenced by GroupPane::OnPaint, GroupPane2::OnPaint, and NewGroupPane::OnPaint; source reconstruction keeps the literal at those use sites rather than declaring a standalone object.`; target AR and all protected item state remained unchanged. |
| I06 | `NO_CHANGE_VERIFIED` | Target name/type/range/width/bytes/xrefs and non-AP comment channels remained exact; only the independently authorized I05 AP delta is present. |
| I07A | `NO_CHANGE_VERIFIED` | Exact-name `GroupPane` UDT remains absent with result count 0. |
| I07B | `NO_CHANGE_VERIFIED` | Exact-name `GroupPane2` UDT remains absent with result count 0. |
| I07C | `NO_CHANGE_VERIFIED` | GroupPane function prototype and complete physical frame remained exact while the independently authorized I01/I02 name/FP deltas are present. |
| I07D | `NO_CHANGE_VERIFIED` | GroupPane2 function prototype and complete physical frame remained exact while the independently authorized I03/I04 name/FP deltas are present. |
| I08 | `NO_CHANGE_VERIFIED` | Predecessor, target, and successor item heads/ends/kinds/widths/names/type states/bytes/xrefs remained exact; only target AP changed under I05. |

The supervisor saved the canonical IDB after verified readback: 143,207,841 bytes, SHA256 `B16863A05EA9E22E4911EC228FE7BD0C25D6DBE1639E791A400D0E311CFA143B`, UTC `2026-08-15T05:16:26.0599562Z`. No local/stack rename, function type, data rename/type, UDT, vtable, RTTI, import, or compiler-artifact mutation occurred; only I01-I05 changed their explicitly authorized names/comments.

## First-Draft C++ Recommendation

- UID0003F0 is eligible for formal CPP as a target-specific covered-by marker rather than a data definition.
- Exact UID0003F0 `RECONSTRUCTION_CPP CODE` insertion text:

```cpp
// [UID:0003F0] No standalone source object is emitted for this pooled literal.
// L"GROUP.EPF" is reconstructed at the GroupPane::OnPaint,
// GroupPane2::OnPaint, and NewGroupPane::OnPaint use sites.
```

- Exact UID0003F0 `RECONSTRUCTION_H CODE` disposition: blank. Do not add a comment, declaration, include, constant, macro, extern, member, or forward declaration to the H channel.

### New `GroupPane::OnPaint` child

- Exact new path: `by-memory/0x0056c6c0-0x0056c731.GroupPaneOnPaint.md`.
- UID allocation receipt: created without a guessed UID under lease; validator command 23763 assigned UID00050R. Canonical references now use [UID:00050R][0x0056c6c0-0x0056c731.GroupPaneOnPaint](by-memory/0x0056c6c0-0x0056c731.GroupPaneOnPaint.md), and the post-reconciliation scoped pass was command 23765.
- Current exact metadata: `COMPLETION:94`, `CONFIDENCE:95`, `CANONICAL_OWNER:00005Y`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00005Y`, `EMITTER_POSITION_OPTIONAL:40`, `Nested:0`.
- Exact range and bytes: `[0x0056c6c0,0x0056c731)`, 113 bytes, SHA256 `60A9066D737851AF85F810A77E699BC4C6A522A3005762FD2EEFE75C1826F8E3`.
- Exact `RECONSTRUCTION_CPP CODE` insertion text:

```cpp
void GroupPane::OnPaint()
{
    EPFTileContext background;
    DLPalette *tabPalette = g_pPaletteLib->GetPaletteByName(L"TABS.PAL");

    g_pEPFLib->LookupLayoutEntry(L"GROUP.EPF", 0, &background);
    g_pfnBlitSprite(this, &background, &background.m_bounds,
                    &m_visibleBounds, 0, tabPalette, 0);
}
```

- Exact `RECONSTRUCTION_H CODE` disposition: blank. The eventual `virtual void OnPaint();` declaration belongs inside a complete GroupPane class declaration, not in a free-standing method child fragment. The focused callback added one `[[CHILDREN]]` token to UID00005Y's existing CPP marker and did not manufacture an incomplete class H declaration.

### New `GroupPane2::OnPaint` child

- Exact new path: `by-memory/0x0056c970-0x0056c9e1.GroupPane2OnPaint.md`.
- UID allocation receipt: created without a guessed UID under lease; validator command 23764 assigned UID00050S. Canonical references now use [UID:00050S][0x0056c970-0x0056c9e1.GroupPane2OnPaint](by-memory/0x0056c970-0x0056c9e1.GroupPane2OnPaint.md), and the post-reconciliation scoped pass was command 23766.
- Current exact metadata: `COMPLETION:94`, `CONFIDENCE:95`, `CANONICAL_OWNER:00005Z`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00005Z`, `EMITTER_POSITION_OPTIONAL:40`, `Nested:0`.
- Exact range and bytes: `[0x0056c970,0x0056c9e1)`, 113 bytes, SHA256 `FD4698757D9BFFA6D1FFD9254A7BD71D28566ACAE9B6DE5E87F4BF01FB95BDAE`.
- Exact `RECONSTRUCTION_CPP CODE` insertion text:

```cpp
void GroupPane2::OnPaint()
{
    EPFTileContext background;
    DLPalette *tabPalette = g_pPaletteLib->GetPaletteByName(L"TABS.PAL");

    g_pEPFLib->LookupLayoutEntry(L"GROUP.EPF", 0, &background);
    g_pfnBlitSprite(this, &background, &background.m_bounds,
                    &m_visibleBounds, 0, tabPalette, 0);
}
```

- Exact `RECONSTRUCTION_H CODE` disposition: blank for the same class-scope reason. UID00005Z already has one `[[CHILDREN]]` token in its CPP marker; preserve it exactly once.

- Body fidelity: both 43-instruction functions create the `0x28` EPFTileContext local, resolve `TABS.PAL`, look up `GROUP.EPF` frame 0, and call the same blitter with source bounds and receiver `+0x44` visible bounds. The two functions are structurally identical apart from relocated call displacements and their receiver classes.
- Behavior preservation: each original consumer still passes the exact UTF-16 resource name to the same lookup path; compiler pooling may regenerate one physical cell.
- Human-source preservation: repeated literals match the current accepted NewGroupPane source and ordinary mid-2000s C++ resource-call style. The formal marker is documentation output, not a claim that the original developers wrote that comment.
- Rejected source: no `aGroupEpf`, no `g_GroupEpf`, no `kGroupEpf`, no raw address, no byte array, and no standalone `static const wchar_t[]` definition.
- Third-party import: not applicable; this is first-party source-local literal evidence.

## Final Recommendation

- All C01-C62 claims are implemented, applied, or verified with exact receipts. Supervisor-owned C29-C33/C59 manual coverage was applied and validated by commands 23813-23815; C34-C39/C41-C42 reached saved Gate 2B applied/no-change-verified closure. B004 did not perform those supervisor-owned actions.
- The historical Section 21 contracts remain audit evidence only. C40 remains evidence-only inspect state, and no Gate 2B mutation should be replayed from this report.
- UID0003F0 retains owner/emitter/reconstructable routing and is now `94/95` because UID00050R, UID00050S, and all three actual generated literal expressions are present.
- Do not broaden the target range or duplicate the source object.
- The two older paint bodies remain separate executable ranges and class-owned UID00050R/UID00050S children. They are not emitted from the 20-byte data page.
- No target-specific ordinary-document/source blocker remains after implementation. Exact erased local spelling is not needed because no local source identifier is recommended; `tabPalette` and `background` are evidence-aligned human names rather than IDA labels.

## Recommended Target Doc Changes

- Target path: `by-memory/0x00624a84-0x00624a98.GroupPaneGroupEpfResourceString.md`.
- Metadata is now `94/95` after three-use generated verification; owner `0000JS`, reconstructable true, emitter `0000JS`, blank position, and nested zero are retained.
- Item Summary now carries exact range/value/hash, three consumers with assigned child UIDs, Group.cpp use-site route, and no-standalone-object disposition.
- Formal CPP contains the exact Section 22 marker; H remains blank.
- Exhaustive target sections now preserve bytes/boundaries, xrefs/consumers, source-shape decision, ownership, rejected alternatives, generated expectations/receipt, score rationale, and historical assumptions.
- The 2026-06-12 B001 split remains valid history; only its then-unresolved literal-versus-constant choice is historicalized and superseded.
- Do not delete valid links to UID0002V2, UID0000JS, or UID0001HC.

## Recommended Support Doc Changes

- [UID:00050R][GroupPaneOnPaint](by-memory/0x0056c6c0-0x0056c731.GroupPaneOnPaint.md) and [UID:00050S][GroupPane2OnPaint](by-memory/0x0056c970-0x0056c9e1.GroupPane2OnPaint.md) now carry the exact Section 22 metadata/body/blank-H dispositions, position `40`, positive/negative evidence, and support links.
- `by-file/Group.md` UID0000JS now maps the pooled item to all three OnPaint literals and records both assigned child UIDs in source order without inventing a named object/header declaration; `91/88` is retained.
- `by-class/GroupPane.md` UID00005Y now records the exact paint flow, links UID00050R, and contains exactly one CPP `[[CHILDREN]]`; `85/87` is retained.
- `by-class/GroupPane2.md` UID00005Z now identifies OnPaint, historicalizes `DrawTabBackground`, records the exact paint flow, links UID00050S, and preserves its existing single CPP token; `85/88` is retained.
- UID0001HC and UID0002V2 now preserve both assigned child paths, hashes, three-xref use-site routing, corrected method identity, and no-emission parent dispositions.
- Inspect-only/no edit: UID000090, UID0004Z5, UID00044V, UID0002NJ, UID0002NK, UID0002NL unless the callback reread finds a direct contradiction. Their current relevant claims are already present.
- Generated files are never edited directly. Expected validator-owned refresh is documented under Sections 27 and 31.

## Score And Metadata Recommendation

| Field | Pre-callback | Current | Rationale |
| --- | --- | --- | --- |
| COMPLETION | 85 | 94 | Exact bytes, boundaries, all consumers, ownership, source placement, no-code route, formal marker, two complete method children, support impact, coverage text, generated verification, and IDA handoff are resolved. |
| CONFIDENCE | 88 | 95 | Direct byte/item/xref/vtable/body and generated-source evidence is complete; only erased original lexical choice between repeated literals and a file-local constant is inferential, and the least-invented source shape is selected. |
| CANONICAL_OWNER | 0000JS | 0000JS | All three consumers are Group.cpp methods. |
| RECONSTRUCTABLE | TRUE | TRUE | Source-declared literal behavior is required even though physical pooling is compiler generated. |
| EMITTER_UIDS | 0000JS | 0000JS | One Group.cpp route covers all use sites and the marker. |
| EMITTER_POSITION_OPTIONAL | blank | blank | No source-order-sensitive data definition is emitted. |
| CPP | blank | exact Section 22 marker installed | Removes the empty emitter without inventing storage. |
| H | blank | blank | No declaration exists. |

- Not higher: the binary cannot prove whether the original developers repeated the literal or named one file-local array, and complete GroupPane/GroupPane2 class H declarations remain broader class work. The focused method bodies and literal disposition are nevertheless exact enough for the current verified `94/95`.
- Not lower: no range, byte, xref, consumer, owner, source file, literal spelling, no-code route, missing CPP method body, output marker, manual-coverage, or target IDA handoff question remains open.

## Open Questions With Attempted Resolution

- **Was there an original named constant?** Exhausted direct xrefs, raw VA/RVA pointer patterns, duplicate bytes, nearby objects, source docs, generated source, and prior research. No positive evidence exists. Resolved to repeated use-site literals as the safest human-source reconstruction.
- **Is GroupPane2's method really OnPaint?** The corresponding primary vtable slot `0x0062450c`, structural identity with GroupPane OnPaint, and same render behavior resolve it as OnPaint. `DrawTabBackground` is historical descriptive wording, not the best source-facing override name.
- **Should the physical cell be non-reconstructable?** No. The standalone storage is compiler pooled, but the literal is source-declared and behaviorally required. Resolved to reconstructable covered-by output.
- **Should the target own the two formerly absent generated old-pane bodies?** No. Their executable ranges now have exact UID00050R and UID00050S children owned by UID00005Y and UID00005Z. Emitting them from this data page would violate range ownership. The child emitters and covered-by marker now produce all three real uses.
- **Can the missing H declarations be emitted from the method children?** No. A member declaration must be inside the complete class declaration. Because current GroupPane/GroupPane2 class H blocks are intentionally incomplete and exact UDTs are absent, both method-child H channels remain blank; the completed callback verified that no invalid free declaration was generated.
- **Should IDA function types be corrected now?** No. Exact GroupPane/GroupPane2 UDTs are absent and a safe complete frame delta is not available. The report resolves names/comments while explicitly protecting type/frame state rather than deferring an unbounded action.
- No open question remains that blocks the current post-callback `94/95` target state.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

The B agent did not edit these files. M01-M07 below are preserved verbatim as the historical accepted supervisor input. The supervisor applied them and validated the affected manual coverage reports with commands 23813-23815; the receipts below document their completed disposition.

### M01 insert in `by-memory/-coverage-report.md`

Insert after UID0003EZ and before the next address-higher child row:

`        - [UID:0003F0][0x00624a84-0x00624a98.GroupPaneGroupEpfResourceString](by-memory/0x00624a84-0x00624a98.GroupPaneGroupEpfResourceString.md) 0x00624a84-0x00624a98 | method-use pooled UTF-16 resource literal | GroupPaneGroupEpfResourceString : reconstructable : 94% : very-strong : Exact L"GROUP.EPF" bytes and three GroupPane-family OnPaint xrefs; compiler/linker-pooled storage is reconstructed through complete GroupPane, GroupPane2, and NewGroupPane use-site method emitters plus a formal covered-by marker, not a named standalone object.`

### M02 replace UID0000JS in `by-file/-coverage-report.md`

`- [UID:0000JS][Group](by-file/Group.md) : reconstructable : 91% : very-strong : Group/social source root covering GroupListPane, GroupPane/GroupPane2, fully resolved NewGroupPane and ScrollNewGroupPane families, exact packet/layout/render/input/scroll behavior, GroupMemberMarkers, shared scrollbar constants, retained helper/source-lowering evidence, exact pooled GROUP.EPF routing through three OnPaint use-site literals and dedicated GroupPane/GroupPane2 method children without a named data object, current NewGroupPane 0x110 declaration and twenty-one-child split plan, and exact Group.cpp emitter topology without handwritten compiler vtables or broad-range duplication.`

### M03 replace UID00005Y in `by-class/-coverage-report.md`

`- [UID:00005Y][GroupPane](by-class/GroupPane.md) : reconstructable : 85% : strong : Assigned to [UID:0000JS][Group](by-file/Group.md); evidence covers exact GroupPane executable endpoints, the dedicated OnPaint child with TABS.PAL plus GROUP.EPF frame-0 lookup/blit source, vtable-data dword/xref refresh, destructor/thunk refs, GroupPaneFamilyVtables linkage, and the remaining class-declaration/source-split caveat across group-pane variants.`

### M04 replace UID00005Z in `by-class/-coverage-report.md`

`- [UID:00005Z][GroupPane2](by-class/GroupPane2.md) : reconstructable : 85% : strong : Alternate group pane attached to Group.cpp with constructor/destructor/layout/stub coverage and a dedicated OnPaint child identified by the corresponding vtable slot; OnPaint uses TABS.PAL and GROUP.EPF frame 0 before blitting the pane bounds. Exact vtable data, destructor/thunk refs, and the remaining class-declaration/split caveat against GroupPane are preserved.`

### M05 replace UID0001HC in `by-memory/-coverage-report.md`

`    - [UID:0001HC][0x0056c4c0-0x0056e939.GroupPanes](by-memory/0x0056c4c0-0x0056e939.GroupPanes.md) : non-reconstructable : 92% : very-strong : Non-emitting physical split index over GroupPane, GroupPane2, and NewGroupPane; current live IDA resolves every modeled body, dedicated GroupPane and GroupPane2 OnPaint child routes, all four retained raw NewGroupPane helpers, exact source-facing roles and field layout, the pooled GROUP.EPF literal's three OnPaint xrefs/use-site route, twenty-one NewGroupPane child ranges, every int3 padding span, Group.cpp routing, packet/render/input/scroll/map-marker behavior, and compiler vtable/destructor/thunk boundaries without conflating the aggregate with source C++.`

### M06 insert new GroupPane OnPaint child in `by-memory/-coverage-report.md`

Insert this exact UID00050R row in address order:

`    - [UID:00050R][0x0056c6c0-0x0056c731.GroupPaneOnPaint](by-memory/0x0056c6c0-0x0056c731.GroupPaneOnPaint.md) 0x0056c6c0-0x0056c731 | GroupPane::OnPaint | GroupPaneOnPaint : reconstructable : 94% : very-strong : Exact 113-byte GroupPane paint override; loads TABS.PAL, resolves GROUP.EPF frame 0 into EPFTileContext, and blits the source bounds to the pane visible bounds through the GroupPane class emitter.`

### M07 insert new GroupPane2 OnPaint child in `by-memory/-coverage-report.md`

Insert this exact UID00050S row in address order:

`    - [UID:00050S][0x0056c970-0x0056c9e1.GroupPane2OnPaint](by-memory/0x0056c970-0x0056c9e1.GroupPane2OnPaint.md) 0x0056c970-0x0056c9e1 | GroupPane2::OnPaint | GroupPane2OnPaint : reconstructable : 94% : very-strong : Exact 113-byte GroupPane2 paint override and structural twin of GroupPane::OnPaint; loads TABS.PAL, resolves GROUP.EPF frame 0 into EPFTileContext, and blits the source bounds to the pane visible bounds through the GroupPane2 class emitter.`

- Tracker: no manual edit. Tracker and report lifecycle state remain validator-owned; this sentence asserts no artifact location or execution state.
- Generated coverage: no manual edit.

Supervisor manual-coverage completion receipts:

| Command ID | Timestamp | Scope | Result |
| --- | --- | --- | --- |
| 23813 | `2026-08-15T01:20:17-04:00` | `by-memory/-coverage-report.md`; applied M01, M05, M06, and M07 | Exit `0`; `ok:1`; exact UID0003F0/UID0001HC/UID00050R/UID00050S rows validated. Pre-existing unrelated `missing_ref_uid` warnings for UID00039L and UID0003T6 did not fail this target. |
| 23814 | `2026-08-15T01:20:24-04:00` | `by-file/-coverage-report.md`; applied M02 | Exit `0`; `ok:1`; exact UID0000JS row validated with no target warning/error. |
| 23815 | `2026-08-15T01:20:37-04:00` | `by-class/-coverage-report.md`; applied M03 and M04 | Exit `0`; `ok:1`; exact UID00005Y/UID00005Z rows validated. Validator removed a stale UID0002NK reference-index entry because the accepted replacement no longer linked it; no target warning/error. |

## Follow-Up Actions

1. No target-specific ordinary-document, IDA, or manual-coverage action remains; the dated callback, completed Gate 2B, and applied manual coverage need no replay.
2. All 62 claims are closed in the exact ledger/checklist twin. Further target work begins only if later evidence invalidates a specific poststate.
3. Historical command 23816 recorded execution, and historical command 23817 recorded de-execution-for-rework. Lifecycle/archive status is supervisor- and validator-owned and is not asserted by this report prose.

## Confidence

- Bytes/range/item boundaries: 100% direct.
- Consumer/xref set: 100% direct for current IDB.
- OnPaint roles: very high, based on corresponding vtable slots and full bodies.
- Group.cpp ownership: very high, based on all-consumer convergence and current source graph.
- Repeated use-site literal source shape: high, not absolute; it is the least invented form and matches current accepted source.
- Overall recommendation: current post-callback `94/95` is justified and intentionally below final-completion territory. The two children, formal marker, and three-use generated readback now exist.

## Validator Results

- Historical report-first Gate 1 receipt: artifact SHA256 `71ACCFAA4A8AED572CF73E69D6E0D2469B7383BFBF843D9A1AE9C955BDA321FC` was accepted before the authorized implementation/receipt reconciliation. This statement records that dated decision only and asserts no later Gate 1 or lifecycle state.
- Exact working directory for every callback command: `E:\NTK\GhidraBridge\source-3\project-documentation` (validator canonical root readback: `C:\FastStorage\NTK_Sources\source-3\project-documentation`).

| Command ID | Timestamp | Exact single-line command | Result | Generated state / side effects |
| --- | --- | --- | --- | --- |
| 23763 | `2026-08-14T23:01:19-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x0056c6c0-0x0056c731.GroupPaneOnPaint.md --apply --queue-timeout 240` | Exit `0`; allocator assigned UID00050R; this allocation result did not emit an `ok` field; no error. | Generated refresh deferred; registered metadata/owner/emitter/position/formal CPP/H and projected stats. |
| 23764 | `2026-08-14T23:01:25-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x0056c970-0x0056c9e1.GroupPane2OnPaint.md --apply --queue-timeout 240` | Exit `0`; allocator assigned UID00050S; this allocation result did not emit an `ok` field; no error. | Generated refresh deferred; registered metadata/owner/emitter/position/formal CPP/H and projected stats. |
| 23765 | `2026-08-14T23:04:31-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x0056c6c0-0x0056c731.GroupPaneOnPaint.md --apply --queue-timeout 240` | Exit `0`; `ok:1`; no warning/error. | Generated refresh deferred. |
| 23766 | `2026-08-14T23:04:33-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x0056c970-0x0056c9e1.GroupPane2OnPaint.md --apply --queue-timeout 240` | Exit `0`; `ok:1`; no warning/error. | Generated refresh deferred. |
| 23767 | `2026-08-14T23:04:48-04:00` | `python .\tools\validator.py --mode file --file by-class/GroupPane.md --apply --queue-timeout 240` | Exit `0`; `ok:1`; no warning/error. | Generated refresh deferred. |
| 23768 | `2026-08-14T23:05:01-04:00` | `python .\tools\validator.py --mode file --file by-class/GroupPane2.md --apply --queue-timeout 240` | Exit `0`; `ok:1`; no warning/error. | Generated refresh deferred. |
| 23769 | `2026-08-14T23:05:04-04:00` | `python .\tools\validator.py --mode file --file by-file/Group.md --apply --queue-timeout 240` | Exit `0`; `ok:1`; no warning/error. | Generated refresh deferred. |
| 23770 | `2026-08-14T23:05:06-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x0056c4c0-0x0056e939.GroupPanes.md --apply --queue-timeout 240` | Exit `0`; `ok:1`; no warning/error. | Generated refresh deferred. |
| 23771 | `2026-08-14T23:05:09-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x00624788-0x00624c60.LookGroupCollectionResourceStringData.md --apply --queue-timeout 240` | Exit `0`; `ok:1`; no warning/error. | Generated refresh deferred. |
| 23772 | `2026-08-14T23:05:12-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x00624a84-0x00624a98.GroupPaneGroupEpfResourceString.md --apply --queue-timeout 240` | Exit `0`; `ok:1`; no warning/error. | Generated refresh deferred. |
| 23774 | `2026-08-14T23:05:30-04:00` | `python .\tools\validator.py --mode file --file by-file/Group.md --apply --wait-generated --queue-timeout 240` | Exit `0`; `ok:1`; generated refresh completed. | Rebuilt the emitter registry and validator-owned generated outputs. The command reported project-wide pre-existing marker/no-code warnings, but no UID0003F0/UID00050R/UID00050S error. |
| 23813 | `2026-08-15T01:20:17-04:00` | `python .\tools\validator.py --mode file --file by-memory/-coverage-report.md --apply --queue-timeout 240` | Exit `0`; `ok:1`; M01/M05/M06/M07 validated. | Generated refresh deferred; pre-existing unrelated `missing_ref_uid` warnings for UID00039L and UID0003T6 did not fail this target. |
| 23814 | `2026-08-15T01:20:24-04:00` | `python .\tools\validator.py --mode file --file by-file/-coverage-report.md --apply --queue-timeout 240` | Exit `0`; `ok:1`; M02 validated; no target warning/error. | Generated refresh deferred. |
| 23815 | `2026-08-15T01:20:37-04:00` | `python .\tools\validator.py --mode file --file by-class/-coverage-report.md --apply --queue-timeout 240` | Exit `0`; `ok:1`; M03/M04 validated. | Generated refresh deferred; a stale UID0002NK reference-index entry was removed because the accepted replacement row no longer linked it. |

- UID allocation produced two distinct canonical identities, UID00050R and UID00050S. Current changed docs and this report contain zero unresolved TMP tokens.
- Physical `Group.cpp` readback: SHA256 `57C61589C5C65BADE02CA2ED32D3083C6242A9BD034F34A6DCE024E34BB24ABD`, 52,287 bytes, 1,430 lines, generated file timestamp `2026-08-14 23:06:07 -04:00`. It contains exactly one complete `GroupPane::OnPaint`, one complete `GroupPane2::OnPaint`, and one complete `NewGroupPane::OnPaint`; each body has one actual `L"GROUP.EPF"` expression, total three. UID00050R/UID00050S each have one source marker and zero empty markers. UID0003F0 has its exact covered-by marker, zero empty markers, and zero data definitions.
- Physical `Group.h` readback: SHA256 `CB550DC5146C4466B0B5257F2AAE499D21C05A2476E81FA75402FC97EF716CDF`, 1,849 bytes, 50 lines, generated file timestamp `2026-08-14 23:06:07 -04:00`. It retains exactly one `class NewGroupPane : public PanelPane`, contains zero UID00050R/UID00050S/UID0003F0 markers, and contains zero free-standing `GroupPane::OnPaint` or `GroupPane2::OnPaint` declarations.
- Manual coverage M01-M07 was supervisor-applied and validated by commands 23813-23815.
- Supervisor Gate 2B completed and saved I01-I05 as `APPLIED_VERIFIED` and I06/I07A-I07D/I08 as `NO_CHANGE_VERIFIED`; the saved canonical IDB is 143,207,841 bytes with SHA256 `B16863A05EA9E22E4911EC228FE7BD0C25D6DBE1639E791A400D0E311CFA143B`, UTC `2026-08-15T05:16:26.0599562Z`.
- Validator-owned lifecycle receipt 23816 at `2026-08-15T01:21:49-04:00` historically executed the report into `executed-b-agent-research/B004/0003F0-GroupPaneGroupEpfResourceString-source-quality.md`.
- Validator-owned lifecycle receipt 23817 at `2026-08-15T01:26:32-04:00` historically invalidated the command-23816 execution and recorded destination path `tools/leaser/Agents/Agent-B004/research/0003F0-GroupPaneGroupEpfResourceString-source-quality.md` for rework. This is a dated receipt, not a claim about later artifact location or execution state.

## Changed Files

- B004 created [UID:00050R][`by-memory/0x0056c6c0-0x0056c731.GroupPaneOnPaint.md`](by-memory/0x0056c6c0-0x0056c731.GroupPaneOnPaint.md) and [UID:00050S][`by-memory/0x0056c970-0x0056c9e1.GroupPane2OnPaint.md`](by-memory/0x0056c970-0x0056c9e1.GroupPane2OnPaint.md).
- B004 modified `by-memory/0x00624a84-0x00624a98.GroupPaneGroupEpfResourceString.md`, `by-class/GroupPane.md`, `by-class/GroupPane2.md`, `by-file/Group.md`, `by-memory/0x0056c4c0-0x0056e939.GroupPanes.md`, and `by-memory/0x00624788-0x00624c60.LookGroupCollectionResourceStringData.md`.
- B004 modified this same report to record implementation/validation receipts and exact twin states.
- Validator commands updated validator-owned UID/registry/projected-stat/generated artifacts. B004 did not edit generated files directly.
- B004 did not edit manual coverage, tracker, audit, catalog, goal, notes, or lifecycle files. The supervisor later applied manual coverage M01-M07, completed and saved Gate 2B, and used validator-owned lifecycle commands 23816/23817; those actions are not attributed to B004.
- B004 queried IDA read-only and did not save or mutate it. The supervisor later applied the bounded I01-I05 changes, verified I06/I07A-I07D/I08 no-change state, and saved the canonical IDB.
- Every ordinary destination was leased only for callback edit/validation and all eight leases were released successfully. This report was separately leased only for this narrow report-text reconciliation and released immediately afterward.
- Lifecycle/archive status is outside B004 report prose and remains supervisor- and validator-owned. Commands 23816 and 23817 are retained only as dated historical receipts, not as present-state assertions.

## Implementation Tracking Checklist

The following 62 rows mirror Section 11 exactly. All 62 rows are checked: B004 completed the ordinary/check-only claims, and the 14 supervisor-owned manual-coverage and IDA rows carry explicit applied/no-change-verified receipts without attributing those actions to B004.

| Done | Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| [x] | C01 | 0003F0 | Exact range is `[0x00624a84,0x00624a98)`, 20 bytes, with byte SHA256 `D630EA44A97C6F9364A71C8A3FE55CCF0B521F58B800044D29E35833F6756D0D`. | Very high | MCP bytes and item readback | UID0003F0 Range, Evidence | incorporate | applied |
| [x] | C02 | 0003F0 | The item is exact UTF-16LE `GROUP.EPF\0`; predecessor ends at `0x00624a84` and successor starts at `0x00624a98`. | Very high | Bytes, strings, three item heads | UID0003F0 Range, Boundary Evidence | incorporate | applied |
| [x] | C03 | 0003F0 | The literal occurs once physically; the three VA operand hits are the three consumers and no RVA pattern exists. | Very high | `find_bytes` exact counts | UID0003F0 Search Evidence | incorporate | applied |
| [x] | C04 | 00005Y | Data xref `0x0056c6fd` is inside exact GroupPane paint override `[0x0056c6c0,0x0056c731)`. | Very high | Complete disassembly and vtable slot `0x00624480` | UID0003F0 consumers; GroupPane method notes | incorporate | applied |
| [x] | C05 | 00005Z | Data xref `0x0056c9ad` is inside exact GroupPane2 paint override `[0x0056c970,0x0056c9e1)`. | Very high | Complete disassembly, structural twin, vtable slot `0x0062450c` | UID0003F0 consumers; GroupPane2 method notes | incorporate | applied |
| [x] | C06 | 0004Z5 | Data xref `0x0056cf39` is inside `NewGroupPane::OnPaint`; current formal source already spells the normal branch as `L"GROUP.EPF"`. | Very high | Xref, vtable slot `0x00624598`, current formal/generated source | UID0003F0 consumers; UID0004Z5 check-only | already-present | already-present |
| [x] | C07 | 0003F0 | UID0000JS Group is the narrowest direct source owner because all three consumers belong to `Group.cpp`. | High | Three-consumer convergence and current source route | UID0003F0 ownership/metadata; Group file | incorporate | applied |
| [x] | C08 | 0002V2 | The mixed physical parent remains owner NONE, reconstructable false, and non-emitting; exact child UID0003F0 carries this source-local literal. | Very high | Cross-owner island inventory and exact child split | UID0002V2 split inventory | incorporate | applied |
| [x] | C09 | 0003F0 | No GroupPane class is canonical owner of the pooled cell because three sibling classes consume it. | High | Exact consumer set and class boundaries | UID0003F0 rejected alternatives | incorporate | applied |
| [x] | C10 | 0003F0 | Human source should repeat `L"GROUP.EPF"` at the three paint use sites. | High | Direct operands, pooling, existing NewGroupPane source, era style | UID0003F0 source disposition; Group source notes | incorporate | applied |
| [x] | C11 | 0003F0 | No named source constant/global/member/resource object should be invented from IDA label `aGroupEpf`. | High | Negative pointer/object/table/type evidence | UID0003F0 no-code proof and history | reject-invalid | excluded-with-reason |
| [x] | C12 | 0003F0 | Target metadata should become `94/95`, owner/emitter UID0000JS, reconstructable true, blank position, but only after all three generated literal use sites exist. | High | Complete three-consumer closure plan and exact source route | UID0003F0 metadata and score rationale | incorporate | applied |
| [x] | C13 | 0003F0 | Formal CPP should be the exact three-line covered-by marker in Section 22. | Very high | No-standalone-object proof and emitter requirement | UID0003F0 formal CPP | incorporate | applied |
| [x] | C14 | 0003F0 | Formal H remains exactly blank because a method-use literal declares no header entity. | Very high | Source disposition and no public symbol | UID0003F0 formal H | already-present | already-present |
| [x] | C15 | 0003F0 | Historical wording that declaration style was not final must be retained as dated history and superseded by the use-site-literal decision. | High | Current target history plus completed inference audit | UID0003F0 Historical Assumptions | historicalize | applied |
| [x] | C16 | 0000JS | Group file documentation should record exact literal bytes, three paint consumers, direct file-local route, and no named object. | High | Target evidence and source convergence | `by-file/Group.md` source/resource sections | incorporate | applied |
| [x] | C17 | 00005Y | GroupPane documentation should retain `OnPaint`, add exact `TABS.PAL` plus `GROUP.EPF` frame-0 lookup/blit behavior, attach the new method child, and add `[[CHILDREN]]` to its CPP marker. | Very high | Complete 43-instruction body and vtable slot | `by-class/GroupPane.md` method/evidence/emitter sections | incorporate | applied |
| [x] | C18 | 00005Z | GroupPane2 address `0x0056c970` should be documented as `OnPaint`, historicalize `DrawTabBackground`, and attach the new method child through its existing `[[CHILDREN]]` route. | Very high | Corresponding vtable slot and structural twin | `by-class/GroupPane2.md` method/evidence/history/emitter sections | incorporate | applied |
| [x] | C19 | 000090 | NewGroupPane class already has the accepted `OnPaint` role and needs no metadata or source change for this literal. | Very high | Current class and UID0004Z5 source | `by-class/NewGroupPane.md` check-only | already-present | already-present |
| [x] | C20 | 0001HC | GroupPanes aggregate should record all three exact target xrefs and normalize `0x0056c970` to GroupPane2 OnPaint while remaining non-emitting. | High | Aggregate inventory plus current MCP | UID0001HC consumer/resource evidence | incorporate | applied |
| [x] | C21 | 0004Z5 | NewGroupPaneOnPaint already emits the correct inline literal and remains `94/95`; no duplicate target marker belongs there. | Very high | Current formal CPP and generated readback | UID0004Z5 check-only | already-present | already-present |
| [x] | C22 | 0002V2 | Physical-parent child row should describe exact bytes, three consumers, and covered-by use-site emission rather than only the old split assignment. | High | Current item/xref/source decision | UID0002V2 child inventory | incorporate | applied |
| [x] | C23 | 00044V | Shared TABS.PAL page is compatible precedent and remains unchanged; it already maps the two older paint paths to Group.cpp use sites. | High | Current UID00044V content | UID00044V check-only | already-present | already-present |
| [x] | C24 | 0002NJ | GroupPane primary vtable slot `0x00624480 -> 0x0056c6c0` proves OnPaint; vtable metadata/content otherwise remain unchanged. | Very high | Exact vtable xref and current page | UID0002NJ check-only | already-present | already-present |
| [x] | C25 | 0002NK | GroupPane2 corresponding primary slot `0x0062450c -> 0x0056c970` proves OnPaint; vtable metadata/content otherwise remain unchanged. | Very high | Exact vtable xref and current page | UID0002NK check-only | already-present | already-present |
| [x] | C26 | 0002NL | NewGroupPane primary slot `0x00624598 -> 0x0056ce50` confirms the third OnPaint consumer; page remains unchanged. | Very high | Exact vtable xref and current page | UID0002NL check-only | already-present | already-present |
| [x] | C27 | 0003F0 | Generated Group.cpp should replace UID0003F0's empty marker with the exact formal covered-by marker and contain complete GroupPane, GroupPane2, and NewGroupPane OnPaint bodies with exactly three real `L"GROUP.EPF"` expressions. | High | Current generated defect, two new child plans, and existing UID0004Z5 | Generated-output expectation only | incorporate | applied |
| [x] | C28 | 0003F0 | Generated Group.h receives no UID0003F0 contribution because no declaration exists. | Very high | Blank formal H proof | Generated-output expectation only | not-applicable | excluded-with-reason |
| [x] | C29 | 0003F0 | Supervisor applied the exact new UID0003F0 manual by-memory coverage row from Section 28. | High | Command 23813, exit 0/ok 1 | Supervisor-owned by-memory coverage | incorporate | applied |
| [x] | C30 | 0000JS | Supervisor applied the manual by-file Group row with the three-literal-use route and retained Group-family detail. | High | Command 23814, exit 0/ok 1 | Supervisor-owned by-file coverage | incorporate | applied |
| [x] | C31 | 00005Y | Supervisor applied the manual GroupPane class row with exact OnPaint resource behavior and retained split/vtable/destructor detail. | High | Command 23815, exit 0/ok 1 | Supervisor-owned by-class coverage | incorporate | applied |
| [x] | C32 | 00005Z | Supervisor applied the manual GroupPane2 class row with exact OnPaint resource behavior replacing the generic draw wording. | High | Command 23815, exit 0/ok 1 | Supervisor-owned by-class coverage | incorporate | applied |
| [x] | C33 | 0001HC | Supervisor applied the manual GroupPanes aggregate row with the exact literal/xref source disposition and retained non-emitting inventory detail. | High | Command 23813, exit 0/ok 1 | Supervisor-owned by-memory coverage | incorporate | applied |
| [x] | C34 | 00005Y | Supervisor applied and verified I01 pure rename `sub_56C6C0 -> GroupPane__OnPaint` with signature/frame/comments/xrefs protected. | High | Saved Gate 2B I01 `APPLIED_VERIFIED` readback | Gate 2B I01 | incorporate | applied |
| [x] | C35 | 00005Y | Supervisor applied and verified I02 exact GroupPane function-repeatable paint comment only. | High | Saved Gate 2B I02 `APPLIED_VERIFIED` readback | Gate 2B I02 | incorporate | applied |
| [x] | C36 | 00005Z | Supervisor applied and verified I03 pure rename `sub_56C970 -> GroupPane2__OnPaint` with signature/frame/comments/xrefs protected. | High | Saved Gate 2B I03 `APPLIED_VERIFIED` readback | Gate 2B I03 | incorporate | applied |
| [x] | C37 | 00005Z | Supervisor applied and verified I04 exact GroupPane2 function-repeatable paint comment only. | High | Saved Gate 2B I04 `APPLIED_VERIFIED` readback | Gate 2B I04 | incorporate | applied |
| [x] | C38 | 0003F0 | Supervisor applied and verified I05 exact address-repeatable comment on the pooled literal. | High | Saved Gate 2B I05 `APPLIED_VERIFIED` readback | Gate 2B I05 | incorporate | applied |
| [x] | C39 | 0003F0 | Supervisor verified I06 no-change protection for the current data name/type/range/bytes/xrefs while permitting only I05 AP. | Very high | Saved Gate 2B I06 `NO_CHANGE_VERIFIED` readback | Gate 2B I06 | incorporate | already-present |
| [x] | C40 | 0004Z5 | Existing NewGroupPane function name, exact prototype, comment, and sole vtable xref are evidence-only context and need no Gate 2B action. | Very high | Exact current readback | UID0004Z5 and IDA facts, inspect-only | already-present | already-present |
| [x] | C41 | 00005Y | Supervisor verified I07A-I07D no-change protection: GroupPane/GroupPane2 UDTs remain absent and both exact prototypes/frames remain protected while only I01-I04 name/comment deltas are present. | Very high | Saved Gate 2B I07A-I07D `NO_CHANGE_VERIFIED` readbacks | Gate 2B I07A-I07D | not-applicable | already-present |
| [x] | C42 | 0003F0 | Supervisor verified I08 no-change protection for predecessor/target/successor item heads, boundaries, type states, bytes, comments, and xrefs except the independent I05 target AP. | Very high | Saved Gate 2B I08 `NO_CHANGE_VERIFIED` readback | Gate 2B I08 | already-present | already-present |
| [x] | C43 | 0003F0 | Callback validation registered both UID-less child files as UID00050R/UID00050S, reconciled canonical references, validated every changed by-* file, coherently refreshed Group.cpp/H, and physically verified the target marker plus all three actual literal uses. | High | Validator UID allocation, commands 23763-23774, and physical generated readback | Validator Results and checklist | incorporate | applied |
| [x] | C44 | 0003F0 | No third-party import directive applies; the item is first-party NexusTK Group source data. | Very high | Consumer/source ownership | UID0003F0 source disposition | not-applicable | excluded-with-reason |
| [x] | C45 | 0003F0 | No Wave2/Wave3 artifact supplies current evidence or implementation authority. | Very high | Current skill rule and independent evidence | UID0003F0 evidence provenance | reject-stale | excluded-with-reason |
| [x] | C46 | 00050R | Created `by-memory/0x0056c6c0-0x0056c731.GroupPaneOnPaint.md` UID-less; validator command 23763 allocated UID00050R and accepted references now use its canonical UID link. | Very high | Exact function boundary, canonical TMP contract, and absent-path check | New GroupPane OnPaint child and affected support inventories | incorporate | applied |
| [x] | C47 | 00050R | The GroupPane child covers exactly 113 bytes with SHA256 `60A9066D737851AF85F810A77E699BC4C6A522A3005762FD2EEFE75C1826F8E3` and emits the complete Section 22 `void GroupPane::OnPaint()` body. | Very high | Complete 43-instruction disassembly and exact byte readback | New GroupPane OnPaint child evidence and formal CPP | incorporate | applied |
| [x] | C48 | 00050R | The GroupPane child metadata is `94/95`, owner/emitter UID00005Y, reconstructable true, class-local position `40`, nested zero, with exact blank formal H. | High | Exact behavior plus existing GroupPane-to-Group.cpp route | New GroupPane OnPaint child metadata and formal H | incorporate | applied |
| [x] | C49 | 00050S | Created `by-memory/0x0056c970-0x0056c9e1.GroupPane2OnPaint.md` UID-less; validator command 23764 allocated UID00050S and accepted references now use its canonical UID link. | Very high | Exact function boundary, canonical TMP contract, and absent-path check | New GroupPane2 OnPaint child and affected support inventories | incorporate | applied |
| [x] | C50 | 00050S | The GroupPane2 child covers exactly 113 bytes with SHA256 `FD4698757D9BFFA6D1FFD9254A7BD71D28566ACAE9B6DE5E87F4BF01FB95BDAE` and emits the complete Section 22 `void GroupPane2::OnPaint()` body. | Very high | Complete 43-instruction disassembly and exact byte readback | New GroupPane2 OnPaint child evidence and formal CPP | incorporate | applied |
| [x] | C51 | 00050S | The GroupPane2 child metadata is `94/95`, owner/emitter UID00005Z, reconstructable true, class-local position `40`, nested zero, with exact blank formal H. | High | Exact behavior plus existing GroupPane2-to-Group.cpp route | New GroupPane2 OnPaint child metadata and formal H | incorporate | applied |
| [x] | C52 | 00005Y | GroupPane's class CPP marker must retain its no-class-body comments and gain one `[[CHILDREN]]` token so the new position-40 method child reaches Group.cpp. | Very high | Current marker lacks a child insertion token | `by-class/GroupPane.md` formal CPP | incorporate | applied |
| [x] | C53 | 00005Z | GroupPane2's existing single `[[CHILDREN]]` token is the correct route for the new position-40 method child and must remain unique. | Very high | Current class formal CPP readback | `by-class/GroupPane2.md` formal CPP check-only | already-present | already-present |
| [x] | C54 | 00005Y,00005Z | The two new child H channels remain exactly blank; no isolated `virtual void OnPaint();` declaration may be emitted outside a complete class declaration. | Very high | Current class H state and C++ declaration scoping | New child formal H sections and class H check-only | not-applicable | excluded-with-reason |
| [x] | C55 | 0001HC,0000JS | GroupPanes and Group inventory both exact child paths, assigned UIDs 00050R/00050S, class ownership, address order, byte hashes, and Group.cpp route. | High | Complete consumer bodies and current source topology | Aggregate and by-file child/source-order inventories | incorporate | applied |
| [x] | C56 | 0003F0 | Generated Group.cpp verification must find exactly one `GroupPane::OnPaint`, one `GroupPane2::OnPaint`, one `NewGroupPane::OnPaint`, and exactly three actual `L"GROUP.EPF"` expressions, with no empty/missing emitter for either new child. | Very high | Formal bodies and existing UID0004Z5 generated body | Physical generated CPP readback | incorporate | applied |
| [x] | C57 | 0003F0 | Generated Group.h verification must preserve the current NewGroupPane declaration, add no free-standing OnPaint declaration from either child, and show no UID0003F0 H contribution. | Very high | Exact blank child/target H disposition | Physical generated H readback | already-present | already-present |
| [x] | C58 | 00050R,00050S | Callback validation created the two UID-less children under required leases; commands 23763 and 23764 allocated UID00050R and UID00050S, accepted TMP references were replaced with canonical UID links, all changed files passed scoped validation, and every lease was released. | Very high | Validator UID allocation/TMP contract and leasing workflow | Validator Results and callback receipts | incorporate | applied |
| [x] | C59 | 00050R,00050S | Supervisor applied exact address-ordered manual by-memory coverage rows for UID00050R at `0x0056c6c0-0x0056c731` and UID00050S at `0x0056c970-0x0056c9e1`, each at `94%` with very-strong evidence. | High | Command 23813, exit 0/ok 1 | Supervisor-owned by-memory coverage | incorporate | applied |
| [x] | C60 | 0003F0 | The target covered-by marker became true after C46-C58 source work and the three-use generated readback passed; C59 manual coverage was then completed independently and did not gate generated-source truth. | Very high | Gate 1 failure, corrected closure dependency, and command 23813 | UID0003F0 status, score, and generated-output sections | incorporate | applied |
| [x] | C61 | 00050R,00050S | Source order is UID00050R under GroupPane position 40, then UID00050S under GroupPane2 position 40, then existing NewGroupPane position/address order; no method body is emitted from the data page. | High | Executable order and nested emitter topology | New children, class pages, Group source-order notes | incorporate | applied |
| [x] | C62 | 0003F0 | No complete GroupPane/GroupPane2 class declaration is introduced by this focused repair; child CPP bodies are exact, while class-level H completion remains broader class work and cannot be replaced by invalid free declarations. | High | Missing exact UDTs and current class-H evidence | First-Draft C++ and generated H disposition | not-applicable | excluded-with-reason |

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000023816","destination_path":"executed-b-agent-research/B004/0003F0-GroupPaneGroupEpfResourceString-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0003F0-GroupPaneGroupEpfResourceString-source-quality.md","timestamp":"2026-08-15T01:21:49-04:00","uid":"0003F0"} -->
<!-- {"agent":"B004","command_id":"000000023817","destination_path":"tools/leaser/Agents/Agent-B004/research/0003F0-GroupPaneGroupEpfResourceString-source-quality.md","details":"report returned to active agent research for rework","event":"de-executed-for-rework","source_path":"executed-b-agent-research/B004/0003F0-GroupPaneGroupEpfResourceString-source-quality.md","timestamp":"2026-08-15T01:26:32-04:00","uid":"0003F0"} -->
<!-- {"agent":"B004","command_id":"000000023956","destination_path":"executed-b-agent-research/B004/0003F0-GroupPaneGroupEpfResourceString-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0003F0-GroupPaneGroupEpfResourceString-source-quality.md","timestamp":"2026-08-15T04:29:57-04:00","uid":"0003F0"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
