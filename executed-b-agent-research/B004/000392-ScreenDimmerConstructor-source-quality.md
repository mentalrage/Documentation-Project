** TARGET-REPORT-UID:000392 **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

# UID000392 ScreenDimmerConstructor Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: retain the implemented [UID:000392] exact source-authored `ScreenDimmer` constructor at `[0x00559b90,0x00559ce6)`, emitted through [UID:0000C8] `ScreenDimmer` and routed through [UID:0000NA] `NexusTK/ui/core/ScreenDimmer.cpp`.
- Final disposition: direct source body, no split and no covered-by/no-code treatment. The prior blank formal block was unsupported and has been replaced by the accepted exact constructor.
- Source contract: `ScreenDimmer(unsigned char dimLevel, Pane *parentPane)` on direct bases `Pane` and `Singleton<ScreenDimmer>`. Singleton publication is an implicit template-base construction consequence, not a handwritten assignment in this constructor body.
- Implemented ordinary-document scope: target UID000392, class UID0000C8, layout UID0003H8, file UID0000NA, global UID0000S5, and exact storage UID00029D. Parent aggregate UID0001GA, destructor UID000393, paint UID000394, singleton cleanup UID0001GB, vtable UID0003EF, factory UID000133/UID0000PJ, Pane/EventDispatcher/global dependencies, and ScreenFadeOut remained read-only verification support.
- Applied target score: `93/94`. Every applied score remains below `95` because original source symbols, exact lexical helper spellings, and original header organization were not recovered.

## Supporting Research

- Mandatory live IDA MCP research used NexusTK database session `6b2e78f3`. At evidence-collection time, `server_health` returned `status=ok`, image base `0x00400000`, and ready auto-analysis, Hex-Rays, and string cache; `lookup_funcs(0x00559b90)` and bounded `get_bytes` returned real target data.
- Concrete prior-report terms searched across every required root were `000392`, `0x00559b90`, `0x00559ce6`, `ScreenDimmerConstructor`, `ScreenDimmer`, `ScreenDimmer.cpp`, `0000C8`, `0000NA`, `0001GB`, `0x00607498`, `0x006074a1`, `000133`, `0x004a12b0`, `g_pScreenDimmer`, `ScreenFadeOut`, `AddModalHandler`, `AddToModalList`, and `statusPaneLayerContext`.
- Active report root `tools/leaser/Agents/Agent-B*/research/*.md`: no direct or support report matched those terms when searched. The assigned B004 artifact did not exist before this pass.
- Central executed root `executed-b-agent-research/**`: relevant matches were opened and classified individually:
  - `executed-b-agent-research/B002/B002-MEMTOOL-00559B90-ScreenDimmerAndFadeOut.md`: stale lead only. It carries `REPORT-VALIDATION-STATUS: needs-revalidation` because its target header is missing. Its exact child map, 14 constructor xrefs, and mixed-parent conclusion remain useful, but it does not close UID000392 source C++.
  - `executed-b-agent-research/B004/0001GB-ScreenDimmerSingletonClear-source-quality.md`: current support for the 11-byte non-emitting constructor-unwind cleanup target and current zero-valued singleton slot. This report did not resolve the constructor class base list.
  - `executed-b-agent-research/B002/000133-screen-dimmer-factory-source-quality.md`: current support for `0xfc` allocation, level `5`, parent-pointer argument order, `ScreenDimmer *CreateScreenDimmer(void)`, and `ScreenDimmer.cpp` ownership. Its old below-final-threshold blank-C++ conclusion is not a blocker for UID000392.
  - `executed-b-agent-research/B001/0000CA-ScreenFadeOut.md`: current support for a peer `ScreenFadeOut.cpp` source root and rejection of a combined dimmer/fade source owner.
  - `executed-b-agent-research/B005/0004FU-BulletinSessionActivateScreenDimmer-source-quality.md`: current caller-side support for the shared `CreateScreenDimmer()` factory; it does not own or define UID000392.
  - `executed-b-agent-research/B001/000141-EventDispatcher-source-quality.md`: current semantic support for `0x004a6fc0` as the modal-handler list insertion helper, under the descriptive name `AddModalHandler`.
  - `executed-b-agent-research/B011/00019K-InitializeMainUiGraph-source-quality.md`: current support for the inferred layer-slot field name `g_mainUiLayerSlots.statusPaneLayerContext`.
- Actual archive root `project-documentation/archived/**`: no relevant Markdown report matched the complete term set after validation-log paths were excluded. Incidental historical validator logs mentioning `ScreenDimmer.cpp` are not research evidence and were not treated as reports.
- `tools/leaser/Agents/Older-Research/**`: no relevant report match.
- `tools/leaser/Agents/SpecialReports/**`: no relevant report match.
- No direct prior UID000392 report was found. This artifact independently closes the constructor signature, direct base list, EBO overlap, helper contract, exact body, source route, and score blockers.

## Target

- Target UID: `000392`.
- Target path: `by-memory/0x00559b90-0x00559ce6.ScreenDimmerConstructor.md`.
- B004 research/implementation-callback artifact path: `tools/leaser/Agents/Agent-B004/research/000392-ScreenDimmerConstructor-source-quality.md`; external validation/execution/archive/count state is supervisor/validator-owned and is not asserted here.
- Historical queue row before this research: `auto-generated/-ag-research-tracker.md`, `by-memory` reconstructable not-covered queue, `86/90`, zero direct reports.
- Current target classification: source-authored constructor, direct owner/emitter UID0000C8, `RECONSTRUCTABLE:TRUE`, position `40`, exact managed formal C++, `Nested:8`.
- Exact binary range: `[0x00559b90,0x00559ce6)`, 342 bytes.

## Current Target State

- Applied target metadata: `COMPLETION:93`, `CONFIDENCE:94`, `CANONICAL_OWNER:0000C8`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000C8`, position `40`, exact formal constructor, `Nested:8`.
- Applied support metadata: UID0000C8 `92/94` position `10`; UID0003H8 `92/94` false/non-emitting with blank position/formal; UID0000NA `91/92`; UID0000S5 `92/94` position `20`; UID00029D `92/94` position `30`.
- The six ordinary destinations now contain the exact direct Pane/Singleton bases, EBO/field overlap, source route, branch behavior, implicit singleton lifecycle, support/global/storage dispositions, historical evidence, negative evidence, rejected alternatives, and score caps at report-level detail.
- Fresh generated readback `auto-generated/NexusTK/ui/core/ScreenDimmer.cpp`, validator command `000000011880` at `2026-07-14T17:05:52-04:00`, contains one class, one UID000392 constructor, one UID0000S5 definition, one UID00029D marker, and no Empty Emitter Marker for UID0000C8/UID000392/UID0000S5/UID00029D.
- Manual coverage remains supervisor-owned and was not edited. The exact additions/replacements below remain the durable proposed coverage text; this artifact does not assert external application state.
- Implementation and validators are complete. External report validation, execution, archive, and count state are not asserted in the artifact.

## Executive Recommendation

- UID000392 remains one exact constructor child; no normal block, EH fragment, security-cookie lowering, or alignment was split into handwritten children.
- Direct semantic owner/emitter UID0000C8 was retained, and constructor source position `40` places it through the closed class `[[CHILDREN]]` route.
- `ScreenDimmer` is implemented as `Pane` plus direct `Singleton<ScreenDimmer>` empty base. The Singleton base descriptor has `mdisp=0xf8`, and EBO overlaps it with the one-byte `m_dimLevel` field at the same complete-object offset.
- The constructor body emits without explicit vptr stores, singleton assignment, Singleton constructor/destructor calls, receiver adjustments, SEH, cookie checks, or return-this lowering.
- Normalize source dependencies to `g_useEpfAssets`, `g_pScreenPane`, `g_mainUiLayerSlots.statusPaneLayerContext`, `g_pEventDispatcher`, inherited `GetBounds`, `AddToLayer`, `SetPaneOrder`, `RemoveFromLayer`, `UnregisterEventHandler`, and `EventDispatcher::AddToModalList`.
- UID0000S5 emits one external-linkage singleton definition and UID00029D emits one comment-only source-declared/generated-binary coverage marker; no duplicate global storage is present.
- UID0003H8 is non-emitting declaration/layout support because the complete class block on UID0000C8 owns the actual source declaration.

## Supervisor Active Recheck

- Historical Gate 1 state: the direct-target report-only artifact at SHA-256 `C2BC0B5C0F8D97A8FB7C875C525A16019218277A64152705F778E933D053A467` was accepted for this bounded implementation callback.
- Current artifact state: C01-C44, all four managed blocks, all six bounded ordinary destinations, scoped validators, and waited generated verification are complete.
- No new child is required: the exact target already covers the complete modeled source constructor. Predecessor and successor padding are already represented by UID0000VN/manual coverage.
- Every source-bearing issue triggered by UID000392 is resolved and incorporated: signature, direct bases, EBO, field, helper names, modal contract, full branch body, source route, owner/emitter/order, class/global/layout support, generated expectation, manual coverage text, and scores.
- Compiler-only EH, vtable, adjustor, scalar-delete, cookie, and return-this mechanics remain excluded with exact evidence rather than deferred.

## Inference Research Guidance Check

- `by-structure.md` requires the narrowest semantic owner and distinguishes ownership from output routing. UID000392 therefore stays class-owned by UID0000C8 and emits through the class, rather than bypassing the class to UID0000NA.
- `EMITTER_POSITION_OPTIONAL` is source ordering, while `Nested` is the relative coverage delta from the preceding address-sorted row. `Nested:8` is retained and is not interpreted as a child count.
- Direct IDA facts are ranges, bytes, hashes, xrefs, instructions, offsets, RTTI descriptors, vtables, calls, globals, and control flow. Current documentation evidence supplies accepted project source names. Inferences are limited to original lexical spellings and the human-readable constructor variable names.
- Stale assumptions treated as uncertain and rechecked were the old 95/95 C++ gate, combined ScreenDimmer/ScreenFadeOut ownership, standalone singleton-clear helper, raw Pane offset fields, direct `g_pScreenDimmer = this`, `AddModalHandler` versus `AddToModalList`, and blank-C++ status.
- Wave2/Wave3 and `simroot_v2` mentions were found only as historical source hints. They were not used as binary proof. The current IDB, current by-* docs, current generated output, and current report roots control this recommendation.

## Heuristic / Inference Reanalysis And Validation

1. **Constructor identity and signature.** IDA's `int __thiscall sub_559B90(int this, char a2, int a3)` is a decompiler artifact. `ret 8`, byte load from `[ebp+8]`, pointer load from `[ebp+0xc]`, all callers pushing dim then parent, and direct storage to `+0xf8` prove source signature `ScreenDimmer(unsigned char dimLevel, Pane *parentPane)`. `char` is rejected because levels are palette selectors `0..7`, and `int` is rejected because only the low byte is consumed.
2. **Direct base list.** Live RTTI names include `Singleton<ScreenDimmer>`. The ScreenDimmer hierarchy descriptor has seven entries: ScreenDimmer, Pane, GrafPort, LObject, EventHandler, TimerHandler, and Singleton. The Singleton base descriptor at `0x0064b4ac` has `mdisp=0xf8`, `pdisp=-1`, `vdisp=0`, attributes `0x40`. The correct source bases are `Pane` and `Singleton<ScreenDimmer>`; EventHandler and TimerHandler are inherited through Pane.
3. **EBO and field overlap.** The complete allocation is `0xfc`. Pane/inherited storage ends at `+0xf8`; the empty Singleton base is placed at `+0xf8`, and `m_dimLevel` is also a byte at `+0xf8`. This is normal MSVC empty-base optimization, not a union, padding field, raw pointer, or second object member.
4. **Singleton publication.** The null-adjust decompilation branch derives the complete object from Singleton-subobject `this+0xf8`. It is compiler lowering of the Singleton base constructor. Handwriting `g_pScreenDimmer = this` in UID000392 would duplicate template-base semantics and is rejected.
5. **Failure cleanup.** At `0x00607498`, the EH funclet loads complete `this`, adds `0xf8`, and jumps to UID0001GB. UID0001GB ignores ECX and clears the global. This is the generated Singleton base destructor used during constructor unwind. No explicit try/catch, helper call, or global clear belongs in human constructor source.
6. **Pane constructor and vtables.** `Pane::Pane(2)` is the only explicit direct-base initializer needed. Stores to primary `0x00623484`, EventHandler-view `0x006234d0`, and TimerHandler-view `0x00623500` are compiler consequences of the class declaration.
7. **Bounds helper.** `0x004b8e00` copies the 16-byte inherited bounds at receiver `+0x44` to an output pointer and returns that pointer. Current source uses `GetBounds(&bounds)` across Pane-family callers. Raw `sub_4B8E00`, `m_bounds` memcpy, and a fabricated free helper are rejected.
8. **Layer helpers.** `0x00544c70`, `0x00544d30`, `0x00544ce0`, and `0x00544d70` match inherited `AddToLayer`, `SetPaneOrder`, `RemoveFromLayer`, and `UnregisterEventHandler`. The raw calls and direct offset access are unnecessary.
9. **Layer context.** Three reads of `0x0069b378` are accepted caller-side uses of inferred `g_mainUiLayerSlots.statusPaneLayerContext`. A raw `dword_69B378`, anonymous Layer pointer, or ScreenDimmer-owned global is rejected.
10. **Asset selector.** The branch compares the one-byte `g_useEpfAssets` value with `1`. Current project source declares it as bool, so `if (g_useEpfAssets)` is the best source shape. The branch must not be renamed high-resolution-only because the global selects broader EPF/current asset behavior.
11. **Modal helper spelling.** `0x004a6fc0` appends an EventHandler pointer to the dispatcher modal list. B001's descriptive report uses `AddModalHandler`; current EventDispatcher class docs, current ModelessDialogPane formal source, and the historical recovered import use `AddToModalList`. `AddToModalList` is selected for consistency with the strongest active source contract; `AddModalHandler` remains a descriptive alias, not a second method.
12. **Modal receiver adjustment.** The binary passes `this+0xa0`. Source passes `this`; normal C++ conversion from ScreenDimmer through Pane to inherited EventHandler produces the adjustment. `GetEventHandlerView()`, pointer arithmetic, and reinterpret casts are unnecessary in this constructor.
13. **Redundant bounds read.** In the EPF/current branch, `g_pScreenPane->GetBounds(&bounds)` is immediately followed by `parentPane->GetBounds(&bounds)`. Both calls are retained. Removing the first as apparently dead changes the observed source/optimization shape and is not justified.
14. **Attach-detach-rebind sequence.** The EPF/current branch first attaches with null parent and orders `(NULL,NULL)`. When `parentPane != g_pScreenPane`, it removes, unregisters, rereads parent bounds, reattaches with `parentPane`, and orders `(NULL,parentPane)`. This apparently redundant sequence is preserved exactly; it is not simplified to one conditional attach.
15. **Legacy branch.** The non-EPF branch uses root-screen bounds, null parent, status layer, and null/null order only. No parent bounds read or rebind occurs.
16. **Return ABI.** EAX returns complete `this` and the function ends `ret 8`, as expected for MSVC constructor lowering. Human C++ has no explicit return statement.
17. **Source placement.** Class, global lifecycle, factory, exact storage, and broad cross-file callers converge on `NexusTK/ui/core/ScreenDimmer.cpp`; physical adjacency to ScreenFadeOut does not merge peer sources.
18. **Range/split.** The modeled function is complete and all detached EH pieces are compiler-owned. No bounded child or parent merge improves source fidelity.
19. **Generated output.** Empty markers are caused by blank formal blocks, not missing route. The exact class, constructor, singleton definition, and storage marker remove the target-related empty state without introducing compiler-only bodies.
20. **Remaining uncertainty.** No PDB proves `dimLevel`, `parentPane`, `m_dimLevel`, `AddToModalList`, or the exact header name. Binary behavior and current source-family conventions make these implementation-ready, but those lexical limits cap every score below `95`.

## Evidence Standards Used

- Highest weight: live MCP bytes, function boundaries, decompile/disassembly, normal and EH CFG, callers/callees, RTTI names/descriptors, vtable entries/xrefs, exact global bytes/xrefs, and current function neighborhood.
- Corroborating weight: current by-memory/by-class/by-file/by-global/by-type pages, current generated `ScreenDimmer.cpp`, current tracker, current manual coverage rows, and current executed reports with exact target relevance.
- Inference weight: source-facing variable/helper names and source-file/header placement, accepted only where binary behavior and multiple current docs agree.
- Negative evidence: no alternate entry, no pointer/table route to another source body, no second constructor, no caller-local owner, no ScreenFadeOut singleton relationship, no source reason to emit EH/vptr/cookie/adjustor/delete mechanics, and no direct prior UID000392 report.
- The evidence is sufficient for formal C++ because every branch, argument, callee role, layout offset, direct base, source route, and failure semantic has a bounded explanation. Missing original lexical symbols prevent `95+`, not implementation.

## Evidence Checked

- MCP health and identity: fresh `idb_list`, `server_health`, `lookup_funcs(0x00559b90)`, and bounded target `get_bytes` against database `6b2e78f3`.
- Target: `lookup_funcs`, decompile, disassembly/analyze batch, bytes/hash, normal CFG, EH fragments, function neighborhood, callers, callees, xrefs, stack arguments, and return instruction.
- Boundaries: predecessor `[0x00559b50,0x00559b8b)`, five `0xcc` bytes `[0x00559b8b,0x00559b90)`, target, ten `0xcc` bytes `[0x00559ce6,0x00559cf0)`, successor destructor `[0x00559cf0,...)`.
- Callers: all 14 call sites at `0x004a134c`, `0x004fa377`, `0x004fae00`, `0x004fc2cf`, `0x004fe757`, `0x00506fb5`, `0x00514951`, `0x0052bb97`, `0x0052be2f`, `0x0052d587`, `0x0052d81f`, `0x0052ef27`, `0x0052f1bf`, and `0x00574405`.
- Dependencies: Pane constructor and layer helpers; `0x004b8e00`; EventDispatcher `0x004a6fc0`; globals at `0x0066da97`, `0x0067a7cc`, `0x0067ab30`, `0x0069ae08`, and `0x0069b378`.
- RTTI/vtables: ScreenDimmer names at `0x00623484/0x006234d0/0x00623500`, RTTI descriptors/arrays at `0x0064b460-0x0064b4fc`, type descriptors at `0x00677844` and `0x00677860`, and vtable store/xref triads.
- Current docs read: UID000392, UID0000C8, UID0003H8, UID0000NA, UID0000S5, UID00029D, UID000393, UID000394, UID0001GB, UID0003EF, UID000133, UID0000PJ, UID0001GA, Pane, EventHandler, EventDispatcher, MainUiLayerSlots, g_useEpfAssets, g_pScreenPane, g_pEventDispatcher, and ScreenFadeOut.
- Manual coverage read-only comparison: `by-memory/-coverage-report.md`, `by-class/-coverage-report.md`, `by-file/-coverage-report.md`, `by-global/-coverage-report.md`, and `by-type/by-struct/-coverage-report.md`.
- Prior-report roots and exact relevant paths are enumerated under Supporting Research.
- Failed/unavailable checks: none material. One schema-correction request established that `get_bytes` requires `regions`; the corrected bounded call succeeded. No IDA mutation was requested or performed.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | UID000392 is exactly `[0x00559b90,0x00559ce6)`, 342 bytes, SHA-256 `D603E699C9647FD255A7A5DAC58FD75CBA34D2ED8A73DC1ECB2F27CA77B98755`. | Very strong | MCP lookup/get_bytes/hash. | UID000392 boundaries/evidence/item summary | incorporate | applied |
| C02 | Five leading and ten trailing `0xcc` bytes are padding outside the target. | Very strong | Bounded bytes and neighbor functions. | UID000392 boundaries; manual coverage row | incorporate | applied |
| C03 | Primary body has 105 instructions; the complete analysis records nine normal blocks plus detached EH/compiler blocks. | Very strong | MCP analyze/decompile/disasm. | UID000392 CFG section | incorporate | applied |
| C04 | The function has 14 live constructor call sites and is not dead/retained-only. | Very strong | Code xrefs and caller decompiles. | UID000392 liveness/caller table | incorporate | applied |
| C05 | Source signature is `ScreenDimmer(unsigned char dimLevel, Pane *parentPane)`. | Strong | `ret 8`, stack loads, all callers, byte field. | UID000392 formal; UID0000C8 declaration | incorporate | applied |
| C06 | Direct bases are `Pane` and `Singleton<ScreenDimmer>`. | Very strong | RTTI type/name/hierarchy descriptors. | UID0000C8 formal/layout; UID0003H8 | incorporate | applied |
| C07 | EventHandler `+0xa0` and TimerHandler `+0xa4` are inherited Pane facets, not direct ScreenDimmer fields/bases. | Very strong | RTTI list, vtables, adjustors, Pane docs. | UID0000C8/UID0003H8 | incorporate | applied |
| C08 | Singleton EBO is at `+0xf8` and overlaps one-byte `m_dimLevel` at `+0xf8`; object size is `0xfc`. | Very strong | BCD mdisp, field write, allocation callers. | UID0000C8/UID0003H8/UID000392 | incorporate | applied |
| C09 | Singleton publication is implicit base construction, not a handwritten constructor statement. | Very strong | Null-adjust lowering, RTTI, HourPane/TransferServer controls. | UID000392 formal/rationale | reject-stale | applied |
| C10 | UID0001GB is generated Singleton-base unwind cleanup and remains false/non-emitting. | Very strong | EH jump, ignored ECX, target body, accepted report. | UID000392 support; UID0001GB verify-only | already-present | already-present |
| C11 | `Pane(2)` is the sole explicit direct-base initializer represented by target source. | Very strong | First call and class bases. | UID000392 formal | incorporate | applied |
| C12 | Three ScreenDimmer vptr stores are compiler output and must not appear in source. | Very strong | Vtable stores/xrefs/RTTI. | UID000392 negative evidence; UID0003EF verify-only | reject-invalid | excluded-with-reason |
| C13 | `g_useEpfAssets` is the source-facing bool for `0x0066da97`. | Strong | Current global docs, 366-ref role, target compare. | UID000392 formal | already-present | already-present |
| C14 | `g_pScreenPane` is the source-facing root-pane pointer for `0x0067a7cc`. | Very strong | Current global/storage docs and 145 refs. | UID000392 formal | already-present | already-present |
| C15 | `GetBounds(&bounds)` is the source-facing call for `0x004b8e00`. | Strong | Exact 16-byte copy and broad Pane-family source use. | UID000392 formal | incorporate | applied |
| C16 | The EPF branch must preserve both consecutive root and parent bounds reads. | Very strong | Exact decompile/disassembly. | UID000392 formal/behavior | incorporate | applied |
| C17 | Initial EPF attach is null-parent status layer followed by null/null pane order. | Very strong | Call arguments and helper contracts. | UID000392 formal/behavior | incorporate | applied |
| C18 | Non-root parent branch must remove, unregister, reread bounds, reattach to parent, and reorder after parent. | Very strong | Exact CFG/call sequence. | UID000392 formal/behavior | incorporate | applied |
| C19 | Legacy branch uses only root bounds, null parent, status layer, and null/null order. | Very strong | Exact CFG/call sequence. | UID000392 formal/behavior | incorporate | applied |
| C20 | `g_mainUiLayerSlots.statusPaneLayerContext` is the accepted source-facing `0x0069b378` name. | Strong | Current MainUiLayerSlots docs and 14 refs. | UID000392 formal; UID0000NA support | already-present | already-present |
| C21 | `AddToLayer`, `SetPaneOrder`, `RemoveFromLayer`, and `UnregisterEventHandler` are inherited Pane helper names. | Strong | Current Pane docs and exact helper bodies. | UID000392 formal | incorporate | applied |
| C22 | `0x004a6fc0` is selected as `EventDispatcher::AddToModalList(EventHandler *)`; `AddModalHandler` is a rejected descriptive alias for this source block. | Strong | Current class/formal callers, historical import, B001 semantic report. | UID000392 formal/naming rationale | incorporate | applied |
| C23 | Source passes `this` to AddToModalList; compiler supplies the inherited `+0xa0` EventHandler adjustment. | Very strong | Binary argument, RTTI, Pane facets. | UID000392 formal/negative evidence | incorporate | applied |
| C24 | Constructor return in EAX and `ret 8` are compiler ABI, not explicit source. | Very strong | Tail disassembly and callers. | UID000392 negative evidence | reject-invalid | excluded-with-reason |
| C25 | Security-cookie and SEH FuncInfo `0x00664828` are compiler output. | Very strong | Prologue/epilogue/EH blocks. | UID000392 negative evidence | reject-invalid | excluded-with-reason |
| C26 | No child split or merge is needed. | Very strong | Complete function/boundary/CFG audit. | UID000392 metadata/range section | already-present | already-present |
| C27 | Canonical owner and emitter remain UID0000C8; position becomes `40`; `Nested:8` remains. | Very strong | Semantic ownership, route, by-structure ordering. | UID000392 metadata | incorporate | applied |
| C28 | UID000392 score becomes `93/94`. | Strong | Closed evidence matrix and lexical caps. | UID000392 metadata/coverage | incorporate | applied |
| C29 | UID0000C8 receives a closed complete class declaration with `[[CHILDREN]]`, position `10`, and score `92/94`. | Strong | RTTI/layout/vtables/method inventory. | by-class/ScreenDimmer.md | incorporate | applied |
| C30 | UID0003H8 becomes `92/94`, `RECONSTRUCTABLE:FALSE`, blank emitter/position/formal, retaining owner UID0000C8. | Very strong | Class declaration covers layout; no duplicate type output. | by-type/by-struct/ScreenDimmerLayout.md | incorporate | applied |
| C31 | UID0000NA remains `NexusTK/ui/core/`, becomes `91/92`, and records the complete class/global/constructor route. | Strong | File family, factory/global/peer split. | by-file/ScreenDimmer.md | incorporate | applied |
| C32 | UID0000S5 becomes `92/94`, position `20`, and emits one `ScreenDimmer *g_pScreenDimmer = NULL;` definition. | Strong | Typed 40-xref lifecycle and external consumers. | by-global/g_pScreenDimmer.md | incorporate | applied |
| C33 | UID00029D becomes `92/94`, position `30`, and emits only a covered-storage marker to avoid a duplicate definition. | Very strong | Exact zero slot and source-declared/generated-binary policy. | by-memory/0x0069ae08-0x0069ae0c.g_pScreenDimmer.md | incorporate | applied |
| C34 | UID000393 destructor remains source-authored but its body/score are outside this constructor callback. | Very strong | Exact sibling boundary and current page. | UID000393 verify-only | not-applicable | excluded-with-reason |
| C35 | UID000394 OnPaint remains source-authored and supplies field semantics, but its body/score remain unchanged. | Very strong | Vtable slot and current page. | UID000394 verify-only | not-applicable | excluded-with-reason |
| C36 | UID0003EF vtable data remains compiler-generated/source-declared with no handwritten table. | Very strong | RTTI/vtable stores and current disposition. | UID0003EF verify-only | already-present | already-present |
| C37 | UID000133/UID0000PJ factory remain unchanged; their caller evidence supports this signature. | Strong | Factory body/report/current docs. | Factory pages verify-only | already-present | already-present |
| C38 | UID0001GA remains a false/non-emitting mixed index; exact child row already exists. | Very strong | Peer-class split and exact child inventory. | UID0001GA verify-only | already-present | already-present |
| C39 | ScreenFadeOut remains a peer source file/class and is not a constructor support edit. | Very strong | Separate RTTI/vtables/fields/source report. | ScreenFadeOut verify-only | reject-invalid | excluded-with-reason |
| C40 | Generated readback is one class declaration, one UID000392 constructor body, one singleton definition, one storage marker, and zero UID000392 Empty Emitter Marker. | Strong | Current route, applied formal blocks, and waited command 11880. | Generated readback criteria | incorporate | applied |
| C41 | Target/manual class/file/global/layout/storage coverage rows require exact supervisor-owned updates. | Very strong | Read-only row comparison. | Exact coverage section | incorporate | already-present |
| C42 | Old 95/95 and blank-C++ blockers are stale under the current combined-score/emitter rule. | Very strong | Current by-structure standard and complete evidence. | Target/class/file history | reject-stale | applied |
| C43 | Rejected source alternatives are handwritten singleton assignment/clear, explicit EBO member/union, raw offsets, explicit vptrs, AddModalHandler duplicate, one-step reattach simplification, and no-code. | Strong | Binary/source-contract comparison. | Target/support rejected alternatives | incorporate | applied |
| C44 | Original lexical names remain inference caps only; no in-scope investigable blocker remains. | Strong | Exhaustive current docs, MCP, reports, callers, RTTI. | Scores/open questions/final recommendation | incorporate | applied |

### Callback Proof By Claim

| Claim | Terminal proof |
| --- | --- |
| Proof C01 | UID000392 Status/Raw Evidence/Item Summary record the exact range, 342 bytes, and SHA-256; clean validator `000000011864` returned exit `0`, `ok:1`. |
| Proof C02 | UID000392 Boundaries records the five leading and ten trailing `0xcc` bytes outside the function; exact manual coverage text remains below for supervisor-owned use. |
| Proof C03 | UID000392 Raw Evidence records 105 primary instructions, nine normal blocks, and detached compiler EH/cookie blocks; validator `11864` is clean. |
| Proof C04 | UID000392 lists all 14 exact call sites and rejects dead/retained-only status; validator `11864` is clean. |
| Proof C05 | UID000392 and UID0000C8 contain the identical `unsigned char dimLevel, Pane *parentPane` signature; generated command `11880` contains one matching declaration and definition. |
| Proof C06 | UID0000C8 formal C++ and UID0003H8 layout both record direct `Pane, Singleton<ScreenDimmer>` bases; clean validators `11872` and `11867` verify both pages. |
| Proof C07 | UID0000C8 Layout Notes/Source Contract and UID0003H8 Layout identify `+0xa0` EventHandler and `+0xa4` TimerHandler as inherited Pane facets; no direct-base fields were emitted. |
| Proof C08 | UID000392, UID0000C8, and UID0003H8 record BCD `mdisp=0xf8`, overlapping one-byte `m_dimLevel`, three-byte tail padding, and total `0xfc`; validators `11864`, `11872`, and `11867` are clean. |
| Proof C09 | UID000392 Source And Compiler Disposition and UID0000S5 lifecycle text explicitly reject handwritten publication; generated `11880` has zero `g_pScreenDimmer = this`. |
| Proof C10 | UID0001GB was reread and left unchanged; UID000392/UID0000C8/UID0000S5/UID00029D preserve its generated unwind-cleanup proof without adding an emitter or body. |
| Proof C11 | UID000392 exact formal body contains only `Pane(2)` as an explicit base initializer; generated `11880` matches once. |
| Proof C12 | UID000392/UID0000C8/UID0003H8 classify all three vptr stores as compiler output; generated `11880` contains zero `vptr`, vftable, or explicit vtable writes. |
| Proof C13 | Existing `g_useEpfAssets` support was preserved and the target formal body uses it directly; no support page edit was required. |
| Proof C14 | Existing `g_pScreenPane` support was preserved and the target formal body uses it for both required root-bounds paths; no support page edit was required. |
| Proof C15 | UID000392 formal C++ uses `GetBounds(&bounds)` at all observed sites and target prose retains the exact 16-byte-copy helper evidence. |
| Proof C16 | UID000392 formal body and Behavior retain consecutive root then parent bounds reads in the EPF/current branch; generated `11880` retains both in order. |
| Proof C17 | UID000392 formal body retains null-parent status-layer attachment followed by `SetPaneOrder(NULL, NULL)`; generated `11880` matches. |
| Proof C18 | UID000392 formal body retains remove, unregister, parent bounds reread, parent reattach, and parent order in the non-root branch; generated `11880` matches. |
| Proof C19 | UID000392 legacy branch retains only root bounds, null parent, status layer, and null/null order; generated `11880` matches. |
| Proof C20 | Existing `g_mainUiLayerSlots.statusPaneLayerContext` support was preserved; UID000392 and UID0000NA use the accepted field name without changing its owner. |
| Proof C21 | UID000392 uses `AddToLayer`, `SetPaneOrder`, `RemoveFromLayer`, and `UnregisterEventHandler`; raw helper names/offsets are absent from generated `11880`. |
| Proof C22 | UID000392 uses `AddToModalList`; target naming rationale preserves `AddModalHandler` only as a rejected descriptive alias. |
| Proof C23 | UID000392 passes source `this`; UID0000C8/UID0003H8 preserve inherited EventHandler adjustment evidence; generated `11880` has no cast or `+0xa0` arithmetic. |
| Proof C24 | UID000392 Source And Compiler Disposition excludes EAX return-this and `ret 8`; generated `11880` has no explicit constructor return. |
| Proof C25 | UID000392 excludes security cookie, SEH, and FuncInfo lowering; generated `11880` contains zero `__security` or EH-lowering tokens. |
| Proof C26 | UID000392 retained its UID/path/range and `Nested:8`; no child, split, merge, or rename was created. |
| Proof C27 | UID000392 headers retain owner/emitter UID0000C8 and `Nested:8`, with applied position `40`; validator `11864` and generated `11880` verify the route. |
| Proof C28 | UID000392 headers are `93/94`; validator `11864` recorded both updates and generated `11880` reports those scores. |
| Proof C29 | UID0000C8 is `92/94`, position `10`, and closes the class before `[[CHILDREN]]`; clean validator `11874` and generated `11880` verify one class. |
| Proof C30 | UID0003H8 is `92/94`, false, blank emitter/position/formal, owner UID0000C8; validator `11867` is clean and generated output contains no duplicate layout block. |
| Proof C31 | UID0000NA is `91/92`, retains `NexusTK/ui/core/`, and records positions `10/20/30/40`, ScreenFadeOut peer split, dependencies, and compiler exclusions; validator `11869` is clean. |
| Proof C32 | UID0000S5 is `92/94`, position `20`, with the exact one-line definition; validator `11870` is clean and generated `11880` counts one definition. |
| Proof C33 | UID00029D is `92/94`, position `30`, with only the exact covered-storage marker; final validator `11875` is clean and generated `11880` counts one marker and no second definition. |
| Proof C34 | UID000393 was reread as source-authored sibling evidence and intentionally left outside this constructor callback; no ordinary edit or validator was applied to it. |
| Proof C35 | UID000394 was reread as source-authored field-semantics evidence and intentionally left outside this callback; no ordinary edit or validator was applied to it. |
| Proof C36 | UID0003EF was reread as compiler vtable support and left unchanged; generated `11880` contains no handwritten table body. |
| Proof C37 | UID000133 and UID0000PJ remained unchanged; their factory allocation/caller evidence is preserved in target/class/file/global prose. Their unrelated pre-existing empty markers remain visible and are not target defects. |
| Proof C38 | UID0001GA remained the unchanged false/non-emitting mixed index; UID000392 retained its exact child relationship without editing the aggregate. |
| Proof C39 | ScreenFadeOut pages remained unchanged and UID0000NA preserves the peer-file split in prose; no ownership or score was moved. |
| Proof C40 | Final waited command `11880` proves one class, one UID000392 constructor, one UID0000S5 definition, one UID00029D marker, and zero target/class/global/storage Empty Emitter Markers. |
| Proof C41 | All six exact manual coverage additions/replacements remain verbatim below; no manual `-coverage-report.md` was edited and external application state is not asserted. |
| Proof C42 | UID000392/UID0000C8/UID00029D historicalize the old 95/95 and blank-C++ conclusions; all accepted formal blocks are installed and generated by `11880`. |
| Proof C43 | Target/class/layout/global/storage/file pages preserve the explicit singleton/EBO/raw-offset/vptr/alias/simplification/no-code rejection set; generated negative searches are all zero. |
| Proof C44 | Applied scores retain sub-95 lexical/header/compiler caps while every in-scope implementation item is complete; no callback item is blocked. |

## Positive Evidence Summary

- Exact function bytes, hash, half-open range, padding, return convention, normal CFG, detached EH blocks, and callee set are stable and internally consistent.
- Fourteen direct call sites prove liveness. All pass a byte-sized dim constant and a Pane-family parent; factory allocation is exactly `0xfc`.
- RTTI directly names `ScreenDimmer` and `Singleton<ScreenDimmer>`, enumerates the inherited Pane/GrafPort/LObject/EventHandler/TimerHandler chain, and places Singleton at `+0xf8`.
- Constructor, ordinary destructor, scalar deleting destructor, vtables, singleton storage, factory, and current generated route all converge on the same class/file family.
- The exact source body can represent every application-level operation without decompiler temporaries or ABI offsets. Compiler-only behavior is separately explained rather than discarded.
- Strongest inference chain: caller ABI plus byte field proves the signature; RTTI plus EH displacement proves direct Singleton EBO; exact helper calls plus current support names prove the source body; owner/global/factory evidence proves `ScreenDimmer.cpp` placement.

## IDA MCP Facts

- Database: `6b2e78f3`, NexusTK image base `0x00400000`; health was `ok` when evidence was collected.
- Function: `sub_559B90`, `[0x00559b90,0x00559ce6)`, size `0x156`, 105 primary instructions, 14 code xrefs, no strings.
- Exact SHA-256: `D603E699C9647FD255A7A5DAC58FD75CBA34D2ED8A73DC1ECB2F27CA77B98755`.
- Exact target bytes:

```text
55 8b ec 6a ff 68 a6 74 60 00 64 a1 00 00 00 00 50 83 ec 1c a1 24 2f 67 00 33 c5 89 45 f0 53 56 57 50 8d 45 f4 64 a3 00 00 00 00 8b f1 89 75 dc 8b 5d 0c 6a 02 89 75 d8 e8 93 a8 fe ff 8d 8e f8 00 00 00 c7 45 fc 00 00 00 00 85 c9 74 0d 8d 81 08 ff ff ff a3 08 ae 69 00 eb 0a c7 05 08 ae 69 00 00 00 00 00 8a 45 08 8d be a0 00 00 00 c7 06 84 34 62 00 c7 07 d0 34 62 00 c7 86 a4 00 00 00 00 35 62 00 80 3d 97 da 66 00 01 88 01 8d 45 e0 8b 0d cc a7 67 00 c6 45 fc 01 50 75 68 e8 ce f1 f5 ff 8d 45 e0 8b cb 50 e8 c3 f1 f5 ff ff 35 78 b3 69 00 8d 45 e0 8b ce 6a 00 6a 00 50 e8 1e b0 fe ff 6a 00 6a 00 8b ce e8 d3 b0 fe ff 3b 1d cc a7 67 00 74 55 8b ce e8 74 b0 fe ff 8b ce e8 fd b0 fe ff 8d 45 e0 8b cb 50 e8 82 f1 f5 ff ff 35 78 b3 69 00 8d 45 e0 8b ce 53 6a 00 50 e8 de af fe ff 53 eb 1c e8 66 f1 f5 ff ff 35 78 b3 69 00 8d 45 e0 8b ce 6a 00 6a 00 50 e8 c1 af fe ff 6a 00 6a 00 8b ce e8 76 b0 fe ff 8b 0d 30 ab 67 00 57 e8 fa d2 f4 ff 8b c6 8b 4d f4 64 89 0d 00 00 00 00 59 5f 5e 5b 8b 4d f0 33 cd e8 4f da 06 00 8b e5 5d c2 08 00
```

- Normal blocks: `[0x00559b90,0x00559bde)`, `[0x00559bde,0x00559beb)`, `[0x00559beb,0x00559bf5)`, `[0x00559bf5,0x00559c2d)`, `[0x00559c2d,0x00559c65)`, `[0x00559c65,0x00559c95)`, `[0x00559c95,0x00559cb1)`, `[0x00559cb1,0x00559cba)`, `[0x00559cba,0x00559ce6)`.
- Compiler EH blocks: `0x00607490` Pane teardown tail, `0x00607498-0x006074a6` Singleton cleanup tail, and `0x006074a6-0x006074cc` security-cookie/CxxFrameHandler lowering. Function info is at `0x00664828`.
- Callees: `0x00544460` Pane constructor, `0x004b8e00` bounds copy, `0x00544c70` AddToLayer, `0x00544d30` SetPaneOrder, `0x00544ce0` RemoveFromLayer, `0x00544d70` UnregisterEventHandler, `0x004a6fc0` modal-list insertion, and `0x005c772f` security-cookie check.
- Vtable bases: primary `0x00623484`, EventHandler facet `0x006234d0`, TimerHandler facet `0x00623500`. Each has constructor, ordinary-destructor, and scalar-destructor store refs.
- RTTI: ScreenDimmer BCD `0x0064b460`; CHD `0x0064b47c` with seven base entries; BCA `0x0064b48c`; Singleton base BCD `0x0064b4ac` with `mdisp=0xf8`; type descriptors `0x00677844` and `0x00677860`.
- Singleton storage `0x0069ae08`: bytes `00 00 00 00`, 40 data refs. Constructor refs are `0x00559be4/0x00559beb`; ordinary destructor clear is `0x00559d9b`; UID0001GB clear is `0x0055a030`; scalar wrapper clear is `0x0055a122`.
- Layer slot `0x0069b378`: 14 refs total, including target uses at `0x00559c3d`, `0x00559c7e`, and `0x00559c9a`.
- Negative IDA facts: no alternate target entry, no switch/jump table, no target strings, no embedded child data, no source vtable array, no second singleton storage, and no normal source call to UID0001GB.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `[0x00559b50,0x00559b8b)` | current predecessor function | Prior ScreenPane teardown support | unchanged | ScreenPane family | unchanged | Outside target |
| `[0x00559b8b,0x00559b90)` | UID0000VN row | Five-byte alignment | false/ignored | none | `100` | Keep unchanged |
| `[0x00559b90,0x00559ce6)` | UID000392 | ScreenDimmer human constructor | true | UID0000C8 | `86/90 -> 93/94` | Direct emit, no split |
| `[0x00559ce6,0x00559cf0)` | UID0000VN row | Ten-byte alignment | false/ignored | none | `100` | Keep unchanged |
| `[0x00559cf0,0x00559dc4)` | UID000393 | Human ordinary destructor | true | UID0000C8 | unchanged | Verify-only sibling |
| `[0x00559dd0,0x00559e2d)` | UID000394 | Human OnPaint override | true | UID0000C8 | unchanged | Verify-only sibling |
| `[0x0055a030,0x0055a03b)` | UID0001GB | Singleton base unwind destructor support | false | UID0000NA | `89/93` | Keep non-emitting |
| `[0x00623480,0x00623508)` | UID0003EF | ScreenDimmer RTTI/vtable data | generated-binary | UID0000C8 | unchanged | No handwritten table |
| `[0x0069ae08,0x0069ae0c)` | UID00029D | Exact singleton storage | true/covered storage | UID0000NA | `89/91 -> 92/94` | Marker only |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004a134c` in `0x004a12b0` | Factory passes level `5` and one of active dialog host, `g_pScreenPane`, or `g_activeMapPane` | Confirms shared constructor and argument order |
| `0x004fa377` in `0x004fa1d0` | Level `5`, `g_pScreenPane` | New-user/dialog path |
| `0x004fae00` in `0x004fad00` | Level `5`, `g_pScreenPane` | Login/dialog path |
| `0x004fc2cf` in `0x004fc010` | Level `5`, `g_pScreenPane` | New-user miscellaneous path |
| `0x004fe757` in `0x004fe560` | Level `5`, `g_pScreenPane` | Password/dialog path |
| `0x00506fb5` in `0x00506df0` | Level `3`, `g_pScreenPane` | MapRefreshDimmer-derived construction |
| `0x00514951` in `0x00514920` | Level `3`, `g_pScreenPane` | Map refresh/transition construction |
| `0x0052bb97` in `0x0052b9f0` | Level `5`, dialog/back host `0x0067aba4` | Dialog parent confirms Pane-family argument |
| `0x0052be2f` in `0x0052bdd0` | Level `5`, `g_pScreenPane` | Dialog path |
| `0x0052d587` in `0x0052d3e0` | Level `5`, `g_pScreenPane` | Dialog path |
| `0x0052d81f` in `0x0052d7c0` | Level `5`, `g_pScreenPane` | Dialog path |
| `0x0052ef27` in `0x0052ed80` | Level `5`, `g_pScreenPane` | Dialog path |
| `0x0052f1bf` in `0x0052f160` | Level `5`, `g_pScreenPane` | Dialog path |
| `0x00574405` in `0x00574340` | Level `5`, branch-selects `g_pScreenPane` or dialog/back host `0x0067aba4` | Reconnect/transition parent selection |
| target -> `0x00544460` | Pane constructor with mode `2` | Explicit source base initializer |
| target -> `0x004b8e00` | Three root/parent bounds call sites plus repeated parent call | Exact `GetBounds` behavior |
| target -> `0x00544c70/0x00544d30` | Three attach/order routes | Layer and order semantics |
| target -> `0x00544ce0/0x00544d70` | EPF non-root rebind route | Remove/unregister semantics |
| target -> `0x004a6fc0` | One modal-list insertion with adjusted `this+0xa0` | Implicit EventHandler conversion in source |
| EH `0x006074a1` -> UID0001GB | Sole code xref to cleanup target | Generated Singleton unwind cleanup only |

## Documentation Evidence And IDA Status

- Target and class docs now agree on direct Pane/Singleton inheritance, inherited `+0xa0/+0xa4` facets, EBO/byte overlap at `+0xf8`, `0xfc` size, 14 calls, singleton lifecycle, and source route.
- UID0003H8 now records direct Singleton EBO and is complete false/non-emitting declaration support with blank formal C++.
- UID0000NA separates ScreenDimmer from ScreenFadeOut, owns the factory/global family, and records the complete class/constructor/global output route and applied score.
- UID0000S5/UID00029D identify the typed singleton, zero slot, 40-ref lifecycle, external-linkage definition, and nonduplicating source-declared/generated-binary storage split.
- UID0001GB remains correct as false/non-emitting. The stronger interpretation is specifically Singleton-base constructor-unwind destruction at EBO displacement `+0xf8`.
- UID0003EF is correct as generated vtable/RTTI data. No ordinary source array is recommended.
- Current generated output from final waited command `11880` proves the emitter chain and content are live: one class, one constructor, one singleton definition, and one storage marker with no target-related empty marker. No routing change beyond the applied positions was needed.
- Manual coverage rows are not validator-generated truth and require the exact read-only updates supplied below.

## Ranked Ownership Analysis

### 1. ScreenDimmer class UID0000C8 through ScreenDimmer file UID0000NA

- Evidence for: constructor/destructor/OnPaint vtable identity, direct ScreenDimmer RTTI, Singleton specialization, class field, singleton global/storage, factory, broad class construction, and existing generated route.
- Evidence against: no original source/PDB path string. This is only a lexical confidence cap.
- Decision: accepted. UID000392 remains class-owned/emitted; UID0000C8 remains file-owned/emitted.

### 2. Direct ScreenDimmer file ownership bypassing the class

- Evidence for: singleton and factory are file-owned, and all output lands in one file.
- Evidence against: UID000392 is an ordinary member constructor and the class is the narrowest semantic owner. Bypassing it violates `by-structure.md` and breaks coherent class-child ordering.
- Decision: rejected for target ownership; retained only as the terminal file route.

### 3. Factory, caller, MapRefreshDimmer, dialog, or ScreenFadeOut ownership

- Evidence for: these items construct or consume ScreenDimmer, and ScreenFadeOut is adjacent.
- Evidence against: none owns the ScreenDimmer vtables, `m_dimLevel`, Singleton specialization, global lifecycle, or full caller fanout. ScreenFadeOut has distinct RTTI/vtables/fields and a peer source root.
- Decision: rejected.

### 4. No-code/compiler-generated constructor

- Evidence for: vptr writes, Singleton lowering, EH, cookie, and return-this are compiler mechanics.
- Evidence against: Pane initialization, field initialization, branch-specific bounds/attachment/order behavior, rebind sequence, and modal registration are source-authored and live.
- Decision: rejected. Only compiler mechanics remain non-emitting.

### Proposed new file/grouping, if applicable

- Not applicable. `by-file/ScreenDimmer.md` already supplies `NexusTK/ui/core/ScreenDimmer.cpp` and `ScreenDimmer.h` placement.
- No new class, file, global, layout, or by-memory page is needed.

## Source Placement

- Recommended placement: class declaration in `NexusTK/ui/core/ScreenDimmer.h` or the project-equivalent adjacent header; constructor and singleton definition in `NexusTK/ui/core/ScreenDimmer.cpp`.
- This fits the existing file UID0000NA, generic UI overlay role, factory and global ownership, peer `ScreenFadeOut.cpp` split, and callers across dialogs/map/reconnect.
- Rejected placements: `DialogSession.cpp`, individual dialog files, `MapRefreshDimmer.cpp`, `ScreenPane.cpp`, `Effects.cpp`, `ScreenFadeOut.cpp`, and a new singleton/globals source file.
- Remaining uncertainty: the original header may have had another filename or kept the class declaration local. That does not change the established `.cpp` route or formal class/source contract.

## Range / Split / Padding / Reclassification Analysis

- Exact target range is stable and complete. No internal address is a separately routed source child.
- Leading `[0x00559b8b,0x00559b90)` and trailing `[0x00559ce6,0x00559cf0)` are pure `0xcc` alignment and remain outside UID000392.
- Normal source operations belong to one constructor. Detached `0x00607490-0x006074cc` blocks are compiler EH/cookie support and must not be copied into the method.
- UID0001GB remains a separate exact binary child because it is a real 11-byte function target, but its source disposition remains false/non-emitting.
- UID0003H8 is reclassified from reconstructable blank emitter to false/non-emitting declaration support. Its facts are incorporated into the class declaration while the page remains the exact layout evidence record.
- UID0001GA remains a false mixed index over peer source families and is not reopened.
- `Nested:8` on UID000392 is retained as the validator/manual-coverage relative nesting delta.

## Negative Evidence Summary

- No alternative function entry, tail chunk, child data, switch table, or source body covers UID000392.
- No direct source symbol proves the exact lexical argument/member/helper names; names are accepted inference and scores remain below 95.
- No evidence supports explicit EventHandler or TimerHandler direct bases on ScreenDimmer; RTTI proves they are inherited through Pane.
- No evidence supports a stored Singleton pointer/member, explicit union, or padding member at `+0xf8`; the direct Singleton BCD and field write prove EBO overlap.
- No evidence supports handwritten singleton publish/clear in UID000392; template-base construction and EH destruction account for both.
- No evidence supports emitting vptr stores, adjustor thunks, deleting-destructor flags, SEH records, cookie checks, return-this, or raw receiver adjustments.
- No evidence supports simplifying away the first bounds read or attach/detach/rebind sequence.
- Broad consumers prove liveness, not caller ownership. Physical adjacency proves layout neighborhood, not ScreenFadeOut ownership.
- Historical pre-callback blank generated markers proved missing formal source, not a rare no-code disposition; final waited command `11880` removes all target/class/global/storage empty markers.

## IDA Rename / Type / Comment Recommendations

- Source-facing function identity: `ScreenDimmer::ScreenDimmer(unsigned char dimLevel, Pane *parentPane)`.
- Source-facing field: `unsigned char m_dimLevel` at `+0xf8`.
- Source-facing direct bases: `Pane`, `Singleton<ScreenDimmer>`.
- Source-facing globals/helpers: `g_useEpfAssets`, `g_pScreenPane`, `g_mainUiLayerSlots.statusPaneLayerContext`, `g_pEventDispatcher`, `GetBounds`, `AddToLayer`, `SetPaneOrder`, `RemoveFromLayer`, `UnregisterEventHandler`, `AddToModalList`.
- Historical/current IDA aliases to preserve in prose only: `sub_559B90`, `byte_66DA97`, `dword_67A7CC`, `unk_67AB30`, `unk_69AE08`, `unk_69B378`, and descriptive `AddModalHandler`.
- Intentionally unchanged: IDA database names/types/comments. The assignment forbids IDA mutation, and documentation names are sufficient.

## First-Draft C++ Recommendation

- Eligible and applied: yes. The target has a confirmed route, implementation-ready score, exact signature/layout/control flow, and resolved source dependencies.
- The following four blocks are the complete exact managed destination text applied to UID000392, UID0000C8, UID0000S5, and UID00029D. No illustrative or body-only C++ exists elsewhere in this report; UID0003H8 remains formally blank by exact no-duplicate proof.

### Destination 1: UID000392 target

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
ScreenDimmer::ScreenDimmer(unsigned char dimLevel, Pane *parentPane)
    : Pane(2),
      m_dimLevel(dimLevel)
{
    RectBounds bounds;

    if (g_useEpfAssets) {
        g_pScreenPane->GetBounds(&bounds);
        parentPane->GetBounds(&bounds);
        AddToLayer(&bounds, 0, NULL, g_mainUiLayerSlots.statusPaneLayerContext);
        SetPaneOrder(NULL, NULL);

        if (parentPane != g_pScreenPane) {
            RemoveFromLayer();
            UnregisterEventHandler();
            parentPane->GetBounds(&bounds);
            AddToLayer(&bounds,
                       0,
                       parentPane,
                       g_mainUiLayerSlots.statusPaneLayerContext);
            SetPaneOrder(NULL, parentPane);
        }
    } else {
        g_pScreenPane->GetBounds(&bounds);
        AddToLayer(&bounds, 0, NULL, g_mainUiLayerSlots.statusPaneLayerContext);
        SetPaneOrder(NULL, NULL);
    }

    g_pEventDispatcher->AddToModalList(this);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 2: UID0000C8 class

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ScreenDimmer : public Pane, public Singleton<ScreenDimmer>
{
public:
    ScreenDimmer(unsigned char dimLevel, Pane *parentPane);
    virtual ~ScreenDimmer();

    virtual void OnPaint();

private:
    unsigned char m_dimLevel;
};

extern ScreenDimmer *g_pScreenDimmer;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 3: UID0000S5 singleton definition

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
ScreenDimmer *g_pScreenDimmer = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 4: UID00029D exact storage marker

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Exact storage for g_pScreenDimmer is represented by [UID:0000S5][g_pScreenDimmer](by-global/g_pScreenDimmer.md); this range is source-declared/generated-binary storage evidence.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Exact behavior preserved: both EPF/current bounds reads, initial null-parent attach/order, conditional detach/unregister/rebind, legacy root attach, modal registration, byte field initialization, Pane mode, and implicit Singleton lifetime.
- Most plausible source shape: conventional mid-2000s MSVC constructor initializer list with direct base template, ordinary inherited calls, stack `RectBounds`, `NULL`, and no explicit ABI lowering.
- Rejected from C++: explicit global publish/clear, explicit Singleton calls, vptr stores, pointer offsets, raw helper names, security cookie, SEH, return-this, and direct storage writes.
- Generated verification: final waited validator command `000000011880` at `2026-07-14T17:05:52-04:00` emits each block once in `auto-generated/NexusTK/ui/core/ScreenDimmer.cpp` with no target/class/global/storage Empty Emitter Marker or forbidden compiler lowering.

## Final Recommendation

- C01-C44 are incorporated, already present, or excluded with the exact reason recorded in the terminal ledger and claim proof table.
- UID000392 retains its path, UID, owner/emitter, reconstructable state, and `Nested:8`, with applied position `40`, score `93/94`, full evidence, and exact formal body.
- UID0000C8 is complete as `Pane, Singleton<ScreenDimmer>`, score `92/94`, position `10`, with the class closed before `[[CHILDREN]]`.
- UID0003H8 is false/non-emitting `92/94` declaration support with blank emitter/position/formal.
- UID0000NA remains the direct `NexusTK/ui/core/` file root at `91/92` with the complete current route detail.
- UID0000S5 emits exactly one typed singleton definition at `92/94`, position `20`; UID00029D emits only the exact storage marker at `92/94`, position `30`.
- UID0001GB, UID0003EF, UID000393, UID000394, UID000133, UID0000PJ, UID0001GA, Pane/EventDispatcher/global dependencies, and ScreenFadeOut remained read-only verification support. No implementation item remains.

## Recommended Target Doc Changes

- Target path: `by-memory/0x00559b90-0x00559ce6.ScreenDimmerConstructor.md`.
- Applied metadata: `93/94`, owner/emitter `0000C8`, true, position `40`, exact formal block, `Nested:8` unchanged.
- Applied Item Summary: `Source-ready ScreenDimmer constructor with Pane(2), direct Singleton<ScreenDimmer> EBO publication at +0xf8, overlapping unsigned-byte m_dimLevel, exact EPF/current and legacy bounds/attachment/order branches, conditional remove/unregister/rebind behavior, inherited EventHandler modal-list registration, 14 callers, complete 0xfc layout, compiler-only vptr/EH/cookie/return exclusions, and direct ScreenDimmer.cpp route.`
- Incorporated exact bytes/hash, nine normal blocks, detached EH facts, caller/callee inventory, RTTI/BCD evidence, direct base list, EBO overlap, source names, branch semantics, source placement, rejected alternatives, generated expectation, and score caps.
- Historicalized the stale blank-C++/unresolved-Pane-helper wording and direct handwritten singleton-assignment implication. Raw aliases remain binary provenance only.

## Recommended Support Doc Changes

- `by-class/ScreenDimmer.md`: applied `87/86 -> 92/94`, position `10`, exact class block, direct Pane/Singleton bases, inherited EventHandler/TimerHandler facets, EBO overlap, full virtual surface, constructor signature, implicit singleton lifetime, helper/source route, compiler exclusions, and rejected raw/direct-assignment alternatives.
- `by-type/by-struct/ScreenDimmerLayout.md`: applied `86/91 -> 92/94`, retained owner UID0000C8, changed true to false, cleared emitter/position, and kept formal blank. It records Pane through `+0xf7`, inherited facets, direct Singleton EBO at `+0xf8`, overlapping one-byte `m_dimLevel`, three-byte natural tail padding, and complete size `0xfc`.
- `by-file/ScreenDimmer.md`: applied `87/86 -> 91/92`, preserved `NexusTK/ui/core/`, and records the complete class/global/constructor route, peer ScreenFadeOut split, source order, and no handwritten compiler bodies.
- `by-global/g_pScreenDimmer.md`: applied `87/89 -> 92/94`, retained owner/emitter UID0000NA, position `20`, exact one-definition formal block, external-linkage typed pointer, 40 refs, implicit Singleton lifecycle, and extern declaration in the class block.
- `by-memory/0x0069ae08-0x0069ae0c.g_pScreenDimmer.md`: applied `89/91 -> 92/94`, retained owner/emitter UID0000NA, position `30`, exact covered-storage marker, verified zero bytes, 40 refs, source-declared/generated-binary handling, and rejection of stale `0xffffffff`/duplicate definition.
- Verify-only and unchanged: UID0001GB, UID0003EF, UID000393, UID000394, UID000133, UID0000PJ, UID0001GA, Pane, EventHandler/EventDispatcher, MainUiLayerSlots, g_useEpfAssets, g_pScreenPane, g_pEventDispatcher, and ScreenFadeOut.

## Score And Metadata Recommendation

| Destination | Pre-callback | Applied | Metadata decision | Cap |
| --- | --- | --- | --- | --- |
| UID000392 target | `86/90` | `93/94` | owner/emitter 0000C8, true, position 40, Nested 8, full body | No original symbols/helper lexemes |
| UID0000C8 class | `87/86` | `92/94` | owner/emitter 0000NA, true, position 10, complete class | Header filename/lexical names inferred |
| UID0003H8 layout | `86/91` | `92/94` | owner 0000C8, false, blank emitter/position/formal | EBO proven; no source debug types |
| UID0000NA file | `87/86` | `91/92` | path/FILE owner unchanged | Original source map absent |
| UID0000S5 global | `87/89` | `92/94` | owner/emitter 0000NA, true, position 20, one definition | `g_p` lexical spelling inferred |
| UID00029D storage | `89/91` | `92/94` | owner/emitter 0000NA, true, position 30, marker only | Linker placement not source-authored |

- Score-improvement attempts closed every listed blocker: all callers fixed signature/order; RTTI fixed direct bases; BCD fixed EBO offset; vtables fixed inherited facets/virtual surface; helpers and current docs fixed names; source roots fixed placement; EH fixed failure semantics; generated output fixed route diagnosis; coverage inspection fixed manual text.
- Scores remain below `95` only for unrecovered original lexical names, exact header organization, and compiler-version-equivalence risk. No score is held below implementation readiness.

## Open Questions With Attempted Resolution

- **Was singleton publication handwritten?** Checked null-adjust code, EH displacement, UID0001GB, RTTI type descriptors, BCD bytes, and sibling HourPane/TransferServer patterns. Resolution: no; it is direct `Singleton<ScreenDimmer>` base construction and EBO.
- **Is the second argument Pane, BackPane, or void pointer?** Checked all 14 callers, factory report, `AddToLayer` parent use, and bounds helper consumers. Resolution: `Pane *` is the broadest exact source contract accepted by current ScreenDimmer docs; narrower BackPane would reject valid Pane-family caller documentation.
- **Is dim level signed?** Checked stored width, OnPaint cases `0..7`, and caller constants `3/5`. Resolution: `unsigned char`.
- **What is `0x004a6fc0` called?** Checked current EventDispatcher class, current Modeless formal, B001 semantic report, and recovered import history. Resolution: use `AddToModalList`; retain `AddModalHandler` as descriptive alias only.
- **Should the first EPF root bounds call be removed?** Checked exact instruction and decompile order. Resolution: no; preserve both calls.
- **Should reattachment be collapsed?** Checked every block/call argument. Resolution: no; preserve initial attach/order and conditional remove/unregister/rebind/order sequence.
- **Does layout emit separately?** Checked by-structure and class completeness. Resolution: no; false/non-emitting support avoids duplicate class C++.
- **Does storage emit a second global?** Checked global/storage ownership and one-definition policy. Resolution: no; global defines, storage emits only a coverage marker.
- No evidence-backed source question remains that prevents implementation. Original token spellings remain explicitly capped rather than deferred.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Inspected rows: by-memory parent neighborhood and UID00029D, by-class UID0000C8, by-file UID0000NA, by-global UID0000S5, and by-type/by-struct UID0003H8. UID000392 is absent.
- The B agent must not apply these rows because manual `-coverage-report.md` files are supervisor-owned and forbidden by this assignment.

### Add under UID0001GA in `by-memory/-coverage-report.md`, before the UID0001GB row

```text
        - [UID:000392][0x00559b90-0x00559ce6.ScreenDimmerConstructor](by-memory/0x00559b90-0x00559ce6.ScreenDimmerConstructor.md) 0x00559b90-0x00559ce6 | constructor | ScreenDimmerConstructor : reconstructable : 93% : very-strong : Source-ready ScreenDimmer constructor with exact 342-byte SHA-256 D603E699C9647FD255A7A5DAC58FD75CBA34D2ED8A73DC1ECB2F27CA77B98755, 105 primary instructions, nine normal CFG blocks plus compiler EH/cookie fragments, 14 live callers, Pane(2), direct Singleton<ScreenDimmer> EBO at +0xf8 overlapping unsigned-byte m_dimLevel, exact EPF/current and legacy bounds/attachment/order branches, conditional remove/unregister/rebind, inherited +0xa0 EventHandler modal-list registration, owner/emitter UID0000C8 position 40, full formal C++, and explicit vptr/EH/cookie/return-this exclusions.
```

### Replace UID00029D in `by-memory/-coverage-report.md`

```text
    - [UID:00029D][0x0069ae08-0x0069ae0c.g_pScreenDimmer](by-memory/0x0069ae08-0x0069ae0c.g_pScreenDimmer.md) 0x0069ae08-0x0069ae0c | global pointer | g_pScreenDimmer : reconstructable : 92% : very-strong : Exact zero-filled four-byte ScreenDimmer singleton slot with 40 live refs, direct Singleton<ScreenDimmer> base publication/ordinary/scalar/unwind cleanup lifecycle, owner/emitter UID0000NA, source-declared/generated-binary disposition, one-definition ownership on UID0000S5, and a comment-only covered-storage marker that prevents duplicate global C++.
```

### Replace UID0000C8 in `by-class/-coverage-report.md`

```text
- [UID:0000C8][ScreenDimmer](by-class/ScreenDimmer.md) : reconstructable : 92% : very-strong : Source-complete Pane and Singleton<ScreenDimmer> declaration with inherited EventHandler/TimerHandler facets at +0xa0/+0xa4, Singleton EBO and unsigned-byte m_dimLevel overlap at +0xf8, 0xfc size, constructor/virtual destructor/OnPaint surface, typed singleton extern, exact class-child route, modal/layer helper contracts, peer ScreenFadeOut split, and compiler vtable/EH/adjustor/scalar-wrapper exclusions.
```

### Replace UID0000NA in `by-file/-coverage-report.md`

```text
- [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md) : reconstructable : 91% : very-strong : `NexusTK/ui/core/ScreenDimmer.cpp` owner for the complete Pane/Singleton ScreenDimmer class, source-ready constructor, typed g_pScreenDimmer definition and exact storage marker, CreateScreenDimmer factory family, non-emitting Singleton unwind cleanup, explicit ScreenFadeOut peer-file split, and compiler-only vtable/EH/adjustor/delete exclusions.
```

### Replace UID0000S5 in `by-global/-coverage-report.md`

```text
- [UID:0000S5][g_pScreenDimmer](by-global/g_pScreenDimmer.md) : reconstructable : 92% : very-strong : External-linkage `ScreenDimmer *g_pScreenDimmer = NULL;` source definition in ScreenDimmer.cpp with exact zero-filled storage UID00029D, 40 refs, direct Singleton<ScreenDimmer> publication/ordinary/scalar/unwind cleanup lifecycle, class extern declaration, one-definition policy, broad consumer evidence, and rejected raw/void/duplicate-storage alternatives.
```

### Replace UID0003H8 in `by-type/by-struct/-coverage-report.md`

```text
- [UID:0003H8][ScreenDimmerLayout](by-type/by-struct/ScreenDimmerLayout.md) : not_reconstructable : 92% : very-strong : Non-emitting exact 0xfc ScreenDimmer declaration support with Pane/GrafPort through +0xf7, inherited EventHandler/TimerHandler facets at +0xa0/+0xa4, direct empty Singleton<ScreenDimmer> base at +0xf8 overlapping one-byte m_dimLevel, three-byte natural tail padding, and complete class ownership on UID0000C8 without duplicate layout C++.
```

## Follow-Up Actions

- No ordinary implementation item remains. The six accepted destination pages, C01-C44, all four exact managed blocks, scoped validators, waited generated readback, and checklist reconciliation are complete.
- The exact manual additions/replacements above remain complete supervisor-owned text and stand independently of validator-generated coverage. This artifact neither asserts nor directs their external application.
- Report validation, execution, count, path movement, and archive state are external supervisor/validator-owned facts. B004 performed no report execution, lifecycle, move, archive, probe, count, or manual coverage command.
- A-agent actions: none required by the source-quality result.

## Confidence

- Recommendation confidence: very strong for direct owner, source file, signature widths/order, direct bases, EBO/layout, complete control flow, helper roles, liveness, and no-split/direct-emission disposition.
- Score confidence: strong. The `93/94` target score reflects exhaustive current binary and documentation evidence without claiming recovered original source text.
- Remaining uncertainty: exact original variable/member/helper lexemes, original header filename, and exact compiler flags. These are documented sub-95 caps and do not justify blank C++.

## Validator Results

- All commands ran from `source-3/project-documentation` with exit code `0` and `ok:1`. Scoped commands deferred generated refresh until the final waited command.

| Command ID | Timestamp | Scope/result | Warnings and side effects |
| --- | --- | --- | --- |
| `000000011863` | `2026-07-14T16:49:50-04:00` | UID000392 initial scoped apply; score/position/formal registry updates. | One `missing_ref_uid 000393` from a newly added successor link; repaired in place before final target validation. Generated refresh deferred. |
| `000000011864` | `2026-07-14T16:50:06-04:00` | UID000392 final scoped apply, clean. | No target warning; projected stats section update; generated refresh deferred. |
| `000000011865` | `2026-07-14T16:50:58-04:00` | UID0000C8 scoped apply; score/position/formal registry updates. | Two `missing_ref_uid 0003H8` warnings because the existing layout page had not yet been registered; resolved by serial UID0003H8 validation and command `11872`. |
| `000000011866` | `2026-07-14T16:51:47-04:00` | UID0003H8 initial scoped apply; registered its current path and false/non-emitting metadata. | Six pre-existing missing UID-link warnings for verify-only UID000393/000394/0003EF; converted only those outbound tokens to exact prose/path evidence. |
| `000000011867` | `2026-07-14T16:52:05-04:00` | UID0003H8 final scoped apply, clean. | No target warning; generated refresh deferred. |
| `000000011868` | `2026-07-14T16:52:51-04:00` | UID0000NA initial scoped apply; score and route detail accepted. | Nine pre-existing missing UID00036Q peer-file links; converted only the outbound tokens to exact verify-only prose/path evidence. |
| `000000011869` | `2026-07-14T16:53:27-04:00` | UID0000NA final scoped apply, clean. | No target warning; generated refresh deferred. |
| `000000011870` | `2026-07-14T16:54:05-04:00` | UID0000S5 scoped apply, clean. | Score/position/formal registry updates; generated refresh deferred. |
| `000000011871` | `2026-07-14T16:55:14-04:00` | UID00029D scoped apply, clean. | Score/position/formal registry updates; generated refresh deferred. |
| `000000011872` | `2026-07-14T16:55:28-04:00` | UID0000C8 post-registration scoped rescan, clean. | Added the now-valid UID0003H8 reference index; no ordinary content change. |
| `000000011873` | `2026-07-14T16:55:41-04:00` | UID0000NA earlier `--wait-generated`, exit `0`, `ok:1`; generated refresh completed. | Established the first complete generated body before the final historical-wording cleanup; global unrelated warnings were `85` missing-child-marker, `180` child-only emitters, and `14` fallback inserts. |
| `000000011874` | `2026-07-14T17:02:47-04:00` | UID0000C8 historical-wording repair scoped apply, clean. | Time-scoped the 2026-05-26 generated/MCP note; no metadata/formal change; generated refresh deferred. |
| `000000011875` | `2026-07-14T17:03:09-04:00` | UID00029D historical-wording repair scoped apply, clean. | Time-scoped the 2026-06-16 blank-formal note and identified its 2026-07-14 supersession; no metadata/formal change; generated refresh deferred. |
| `000000011876` | `2026-07-14T17:03:21-04:00` | UID0000NA earlier `--wait-generated`, exit `0`, `ok:1`; generated refresh completed. | Refreshed after the two historical-wording repairs; global unrelated warnings were `85` missing-child-marker, `180` child-only emitters, and `14` fallback inserts, and unrelated `MapPane.cpp` refreshed. |
| `000000011879` | `2026-07-14T17:05:36-04:00` | UID0000NA generated-order clarification scoped apply, clean. | Added the exact class-child versus file-level position explanation; no metadata/formal change; generated refresh deferred. |
| `000000011880` | `2026-07-14T17:05:52-04:00` | UID0000NA final `--wait-generated`, exit `0`, `ok:1`; generated refresh completed. | Rebuilt autogen registry and validator-generated C++/coverage metadata after every ordinary edit. Global unrelated warnings were `85` missing-child-marker, `180` child-only emitters, and `14` fallback inserts; none names UID000392/0000C8/0003H8/0000NA/0000S5/00029D as an error. |

- Fresh generated header: `validator-command-id: 000000011880`, `validator-refreshed-at: 2026-07-14T17:05:52-04:00`, source by-file UID0000NA. This is newer than final destination validators `11874`, `11875`, and `11879`.
- Exact generated order: UID0000C8 trace/class at lines `7-20`; nested UID000392 trace/definition begins at lines `22-23`; UID0000S5 trace/definition at lines `54-55`; UID00029D trace/marker at lines `57-58`. Position `40` is class-child scoped at `[[CHILDREN]]`, while positions `20` and `30` are file-level, so this order is intentional and documented on UID0000NA.
- Exact generated positive counts: `class ScreenDimmer` `1`; `ScreenDimmer::ScreenDimmer` `1`; `ScreenDimmer *g_pScreenDimmer = NULL;` `1`; UID00029D exact storage marker `1`.
- Exact generated negative counts: UID000392/UID0000C8/UID0000S5/UID00029D Empty Emitter Markers `0`; `g_pScreenDimmer = this` `0`; `dword_69AE08` `0`; `unk_69AE08` `0`; `__security` `0`; `vptr` `0`; `ScalarDeleting` `0`; `delete this` `0`.
- Unrelated UID0000PJ and UID000133 Empty Emitter Markers remain in generated output and are outside this constructor callback; C37 deliberately left those factory pages unchanged.

## Changed Files

- Modified ordinary destinations:
  - `by-memory/0x00559b90-0x00559ce6.ScreenDimmerConstructor.md` - `93/94`, position `40`, exact constructor, complete target evidence; clean final validator `11864`.
  - `by-class/ScreenDimmer.md` - `92/94`, position `10`, closed Pane/Singleton class block and complete support evidence; clean final validator `11874`.
  - `by-type/by-struct/ScreenDimmerLayout.md` - `92/94`, false/non-emitting, blank formal, complete EBO/layout proof; clean final validator `11867`.
  - `by-file/ScreenDimmer.md` - `91/92`, retained `NexusTK/ui/core/`, complete source route/order, nested-versus-file-level ordering proof, and peer/compiler boundaries; clean final validator `11879`, final waited refresh `11880`.
  - `by-global/g_pScreenDimmer.md` - `92/94`, position `20`, sole typed definition and lifecycle proof; clean validator `11870`.
  - `by-memory/0x0069ae08-0x0069ae0c.g_pScreenDimmer.md` - `92/94`, position `30`, exact storage marker and source-declared/generated-binary proof; clean final validator `11875`.
- Modified agent-owned artifact: `tools/leaser/Agents/Agent-B004/research/000392-ScreenDimmerConstructor-source-quality.md` - terminal C01-C44 states/proof, validators, generated readback, changed files, and checked callback checklist.
- Renamed/created ordinary pages: none.
- Verify-only and unchanged: UID0001GB, UID0003EF, UID000393, UID000394, UID000133, UID0000PJ, UID0001GA, Pane, EventHandler/EventDispatcher, MainUiLayerSlots, g_useEpfAssets, g_pScreenPane, g_pEventDispatcher, and ScreenFadeOut pages.
- Validator-managed side effects only: validator registry metadata, generated `auto-generated/NexusTK/ui/core/ScreenDimmer.cpp`, generated coverage metadata, projected stats, and research tracker refresh. B004 did not manually edit any generated/tracker/validator-owned file.
- Leases used serially and released: UID000392 released after `11864`; UID0000C8 released after `11865` and historical-wording repair `11874`; UID0003H8 released after `11867`; UID0000NA released after `11869` and ordering clarification `11879`; UID0000S5 released after `11870`; UID00029D released after `11871` and historical-wording repair `11875`. No B004 lease remains.
- Restricted/manual coverage/audit/supervisor/lifecycle/queue/lock/archive files manually modified: none. Report execution/lifecycle command: not run.

## Implementation Tracking Checklist

Initial report-only pass (historical Gate 1 research phase):
- [x] Historical supervisor Gate 1 acceptance for exact pre-callback SHA `C2BC0B5...` recorded without asserting the current artifact's external lifecycle state.
- [x] Bounded destinations remained exactly UID000392, UID0000C8, UID0003H8, UID0000NA, UID0000S5, and UID00029D.
- [x] Current target state and actual evidence checked remain substantive and are reconciled to post-callback truth.
- [x] Claim And Incorporation Ledger records legal terminal verification states for C01-C44, with separate claim-by-claim proof.
- [x] Metadata/score changes applied exactly as listed: `93/94`, `92/94`, `92/94`, `91/92`, `92/94`, `92/94`.
- [x] Score-limiting blockers remain resolved to implementation-ready evidence; no blocker was deferred.
- [x] Owner/emitter/reconstructable decisions applied: target/class/global ownership retained, only UID0003H8 reclassified false/non-emitting, positions `10/20/30/40` applied.
- [x] Split/rename/new-child changes confirmed not applicable; no path or UID changed.
- [x] Source placement, exact range/padding, EBO overlap, inherited facets, and compiler reclassification incorporated.
- [x] Four exact formal managed blocks applied; UID0003H8 remains blank by exact no-duplicate proof.
- [x] Third-party import directive confirmed not applicable.
- [x] Exact target/support facts incorporated at report-level detail across all six destinations.
- [x] Historical stale gate/direct-assignment/helper aliases, rejected alternatives, and negative evidence preserved and historicalized.
- [x] Wave2/Wave3/simroot mentions retained only as historical hints, not proof.
- [x] Open questions closed or bounded by explicit sub-95 lexical caps.
- [x] Scoped validators completed for every changed ordinary page; repair/rescan command history is recorded above.
- [x] Final waited command `11880` completed after every ordinary edit and exact ScreenDimmer.cpp readback passed all positive/negative assertions.
- [x] Manual coverage additions/replacements remain supplied verbatim for supervisor-owned application; no coverage file was edited by B004.

Implementation callback pass:
- [x] Exact pre-callback report SHA was accepted by the supervisor for this bounded implementation.
- [x] Every destination was reread after short lease acquisition; unrelated/concurrent history and support content were preserved.
- [x] C01-C44 are terminal at report-level detail with exact per-claim destination/generated proof.
- [x] UID000392 exact formal body is applied once; generated `11880` reports no target Empty Emitter Marker.
- [x] UID0000C8 class is closed before `[[CHILDREN]]`; Pane/Singleton bases, complete surface, and typed extern are preserved.
- [x] UID0003H8 false/non-emitting reclassification is applied with blank emitter/position/formal and complete layout proof.
- [x] UID0000S5 one definition and UID00029D one covered-storage marker are applied without duplication.
- [x] Verify-only pages remained unchanged; only validator-managed reference/registry/generated state changed.
- [x] One-file edit leases, scoped validators, and immediate releases are recorded for all six ordinary destinations.
- [x] Waited generated readback proves one class, one UID000392 definition, one singleton definition, one storage marker, zero target-related empty markers, zero handwritten EH/vtable/adjustor/scalar-wrapper bodies, and no duplicate source body.
- [x] Validator Results, Changed Files, current-state wording, exact manual coverage text, recommendations, and both checklist phases reflect callback truth.
- [x] No implementation item or lease remains; no manual coverage/generated/tracker/audit/supervisor/validator-state/lifecycle file was edited and no report lifecycle command was run.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000011919","destination_path":"executed-b-agent-research/B004/000392-ScreenDimmerConstructor-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/000392-ScreenDimmerConstructor-source-quality.md","timestamp":"2026-07-14T17:27:54-04:00","uid":"000392"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
