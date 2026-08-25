** TARGET-REPORT-UID:0000IW **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0000IW] `DirectX` as `NexusTK/render/DirectX.cpp` and reconstruct the required sibling `DirectX.h`. Correct the class to `DirectX : public LObject, public Singleton<DirectX>`, move its declaration to H, publish and clear `g_pDirectX` through class-specific `Singleton<DirectX>` specializations, emit only the two source-authored DirectX method bodies, and complete the DirectX-associated `Error.h` support route with independently allocated Error/MyError CPP, H, method, compiler-wrapper, and coverage dispositions.
- Final disposition: whole-file reconstruction remains implemented and source-complete at ordinary-document/generated level. The historical Gate 1 generated C++ was incomplete and source-causally wrong where it substituted manual global writes for the Singleton base; the accepted callback corrected that state.
- Review disposition: this corrected artifact is submitted for fresh Gate 1 review, and the authoritative current result exists only in `tools/leaser/Agents/b-report-validation-audit.md`. Ordinary implementation remains preserved; supervisor Gate 2B separately owns Section 21 and follows only the result recorded in that audit ledger.
- Confidence: high. Fresh IDA RTTI, code, xref, byte, item, comment, frame, Error/MyError method, and attestation evidence supports `92/94` after authorized implementation and generated verification; `Error.h` is resolved by the exact coordinated support source in Section 22 rather than deferred.
- Implementation callback result (2026-08-14): all 137 active ordinary-document claims were either applied at their exact destination or physically verified at same-or-greater detail. The 23 historicalized nonauthoritative claims now carry truthful `excluded-with-reason` verification state, and the corrected 27 active supervisor-only IDA/manual-coverage/lifecycle rows remain `proposed`. Scoped validation and physical generated readback confirm complete `DirectX.cpp`, `DirectX.h`, `Error.cpp`, and `Error.h` assembly, including UID0002HO; the later preflight correction changes only report-held IDA prestate/action planning.
- Gate 2B repair result (2026-08-14): Gate 1 and Gate 2A passed for predecessor SHA256 `B5914B8C86E2A2A63B779C389FA435667F8C2E2423334211D7EF69B923DC7D41`; M01-M11 were supervisor-applied and validated under commands `000000023527` through `000000023531`; fresh preflight matched A01-A08/P01-P23 and all eight hashes; transient unsaved I01-I08 passed; I09 then failed because public `declare_type` parse success did not create an entry observable through same-database `type_query`. I10-I15 were not called, the unsaved partial worker was discarded, and clean recovery reopened the unchanged disk IDB. This additive repair removes the unsupported standalone declaration action, makes I09 an explicit read-only no-`declare_type` gate, and makes I10 the sole self-contained DirectX-pointer data/type/name action.

## Supporting Research

- Lifecycle authority is intentionally external to the body: execution, invalidation, callback, movement, and archive truth are authoritative only from the artifact's current path plus validator-owned status/history metadata.
- Agent-B004 performed all work directly and spawned no subagents.
- IDA MCP was mandatory and entirely read-only. No IDB rename, type, comment, patch, definition, save, or mutation was performed.
- Matching executed reports included B014 UID000137, B009 UID000295, B001 UID0001XE, and DirectX-consumer reports for Surface, ScreenPane, and GrafPort. They were dated leads only.
- Historical correction: B014/B009 recovered the lifetime writes but missed DirectX RTTI's `Singleton<DirectX>` base. Their manual-global and pure-helper source conclusions are superseded.
- Historical Gate 1 generated evidence was read only: `DirectX.cpp` command `000000023186`, refreshed `2026-08-13T15:06:39-04:00`, was the incomplete prestate. Callback-generated command `000000023312` is the physically verified current source assembly; this report-only repair did not regenerate it.
- Historical repair evidence was gathered read-only from attested sessions `supervisor-canonical-uid0002PR-retry2-20260813` and `supervisor-canonical-uid0000KZ-gate2b-20260813`; the latter was opened with automatic analysis disabled. This repair additionally used attested canonical session `supervisor-canonical-clean-20260813` for bounded `0x004a68e0` and A01-A08 byte-hash readback. No IDA save or mutation followed any pass.
- Fresh supervisor canonical preflight supersedes only the contradicted literal A01/A02/A04 types and A05 name/item action: A01 is `char *__thiscall(char *this)`, A02 is `int __thiscall(_DWORD *this)`, A03 remains `void()`, and A04 is `_DWORD *__thiscall(_DWORD *Block, char)`. A05 is an unnamed, untyped, undefined one-byte item with blank AR/AP and no live `unk_67AB20` symbol.
- A supervisor-only disposable-copy probe established the item-level A05 route without saving the probe IDB: after a parser-accepted opaque `struct DirectX;` declaration, fresh four-byte data at `0x0067ab20` accepted a DirectX-pointer type, exact name `g_pDirectX`, and `delete_existing:false`. Public readback was `[0x0067ab20,0x0067ab24)`, size 4, `is_data:true`, with blank regular/repeatable comments and all 19 incoming xrefs preserved. The later Gate 2B attempt proved that the preceding forward-declaration response was not independently enumerable and therefore cannot remain a required action or success gate.
- Historical report-repair prestate was rechecked read-only through public IDA MCP. `idb_list` identified dated canonical database/session `supervisor-uid0000KZ-rollback2-20260814` at exact input path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; exact `type_query` filter `^DirectX$` returned `total:0` and no records.
- Public MCP implementation evidence resolves the failed readback instead of deferring it: installed `api_types.py` `declare_type` reports success when `parse_decls_ctypes` returns zero parser errors but performs no numbered-type readback, while `type_query` builds its catalog exclusively from numbered local-type ordinals. A forward declaration can therefore return apparent success yet remain absent from `type_query`. Installed `api_modify.py` documents `make_data.type` as a full C declaration, parses it to a sized `tinfo_t` before mutation, and returns public address/name/type/size/ok fields; `inspect_items` independently exposes exact item head/end/size/name/type/classification.
- Historical Gate 2B attempt and recovery (2026-08-14): fresh preflight matched every A01-A08/P01-P23 prestate and all eight hashes; I01-I08 passed transiently; I09 returned one apparent declaration success but immediate same-database `type_query` remained `total:0`; I10-I15 were not called. The unsaved partial worker was discarded. Fresh recovery session `supervisor-uid0000IW-recovery-20260814` reopened the unchanged disk IDB with original names/comments/type/item state. Catalog entry 0446 and the audit-ledger state record `FAILED_CLOSED_UNSAVED_STATE_DISCARDED_RECONCILIATION_REQUIRED`; these are dated historical facts, not lifecycle-current assertions. Agent-B004 did not mutate or save IDA.

## Target

- Target UID: `0000IW`.
- Additional target UIDs: none.
- Declared-target inventory:

| UID | Path | Role |
| --- | --- | --- |
| `0000IW` | `by-file/DirectX.md` | Sole declared target and complete `DirectX.cpp` plus required `DirectX.h` root. |

- Target path: `by-file/DirectX.md`.
- Historical source queue/report row: `85/88`, blank reconstructability in `auto-generated/-ag-research-tracker.md`; Gate 1 target metadata was `85/88`, `CANONICAL_OWNER:FILE`, path `NexusTK/render/`.
- Historical assignment boundary: the supervisor assigned a report-only whole-file research/repair cycle and B004 made no ordinary-document implementation edits. Present callback/lifecycle authority is determined only from the artifact's current path, validator-owned status/history metadata, and current supervisor instructions.
- Gate 1 pre-implementation support scores: class UID00003Y `85/88`; global UID0000QS `90/90`; code UID000137 `88/91`; storage UID000295 `90/92`; vtable data UID0002MD `87/93`; diagnostic UID0003AY `85/91`; vtable type UID0003HP `88/93`.
- Implementation callback metadata: UID0000IW, UID00003Y, UID0000QS, UID000295, UID000137, UID0002MD, UID0003AY, and UID0003HP now read `92/94`; UID0000J5 is `89/90`, UID00004J is `90/92`, UID00008V is `91/93`, UID0002HO remains `90/92`, and UID0002TV remains `86/90`.
- Compilation-unit boundary: one DirectX class, one external singleton pointer, two class-specific Singleton specialization bodies, two handwritten lifecycle methods, and compiler-covered vtable/RTTI/EH/deleting-wrapper output. DirectDraw, LObject, shared Singleton, Application policy, and render consumers are dependencies, not file-owned bodies. The associated support scope independently completes the Error/MyError declarations, exact `MyError` constructor/formatter/ordinary destructor, exact `Error::GetErrorName`, and inline `Error::~Error` source cause; it also explicitly excludes duplicate CPP for the `0x004a68e0` Error and `0x004a6a10` MyError scalar deleting wrappers.

## Current Target State

- Historical Gate 1 metadata: `COMPLETION:85`, `CONFIDENCE:88`, projected `NexusTK/render/`, file owner.
- Historical Gate 1 emitter state: global emitted directly at file position 0; code and vtable emitted through class, preventing clean include, specialization, and method order.
- Historical Gate 1 CPP: defined `g_pDirectX`, declared a one-base class inside CPP, emitted manual global writes, and left UID0002MD as `Empty Emitter Marker`.
- Historical Gate 1 H: `auto-generated/NexusTK/render/DirectX.h` was absent and the class H block was blank.
- Stale assumptions: one direct base; unexplained "two-field" layout; private field; CPP-only declaration; manual global lifecycle; `0x004a1cc0` as purely compiler helper; physical storage child as definition owner.
- Docs checked: all DirectX by-file/class/global/memory/type pages; mixed containers; Singleton/Error/Application support; generated DirectX/Crasher/Singleton/Surface/GrafPort/ScreenPane; manual/generated coverage; matching reports.
- Complete inventory: four local functions, four separately dispositioned far ranges/thunks, five padding spans, one global, one vtable, one literal, one SDK GUID, ten RTTI objects, class/layout/template dependencies, imports, all callers and consumers. Sections 14-15 disposition every item.
- Historical generated completeness: five child entries, four nonempty and one empty, with wrong class/source order/Singleton cause/access/includes/H. Section 22 supplied the exact repairs now present in command `000000023312`.
- Dependency prestate and resolution: `../util/Error.h` is absent from historical validator command `000000023186`, but it is no longer deferred. Section 22 supplies a coherent guarded `Error`/`MyError` H block, exact `MyError` constructor identity, exact `Error::GetErrorName`, `MyError::FormatErrorMessage`, and `MyError::~MyError` CPP, plus explicit compiler/no-duplicate-CPP dispositions for `0x004a68e0` and `0x004a6a10`; Sections 25 and 33 allocate every affected Error support destination separately.
- Lifecycle/path statement: this body does not assert a current report-only, callback, execution, or archive state. The artifact's current path and validator-owned status/history metadata are the authority.
- Implementation callback current state: the Gate 1 prestate above is retained as research history. Ordinary by-* source, ownership, emitter, inventory, support, and score changes are now implemented and verified; generated files changed only through scoped validator refresh, and IDA/manual coverage/lifecycle state remains untouched by B004.
- Gate 2B historical state: manual coverage M01-M11 was supervisor-applied and validated under commands `000000023527`-`000000023531`; the first IDA transaction attempt failed closed at I09, was not saved, and was discarded. Recovery reopened original disk state, so Section 21 remains wholly proposed and is repaired for a fresh supervisor gate without claiming any transient I01-I08 mutation as current.

## Executive Recommendation

- Keep UID0000IW as file owner and UID00003Y as class owner/ordered assembly parent.
- Declare an `0x8`-byte `DirectX` with direct `LObject` and empty `Singleton<DirectX>` bases and public `LPDIRECTDRAW m_pDirectDraw` at `+0x4`.
- UID0000QS should emit the sole global plus two Singleton specializations as class child position 0; UID000295 becomes covered-by.
- UID000137 emits only constructor/destructor at position 1; scalar wrapper/far EH are compiler-covered.
- UID0002MD emits a compiler-covered marker at position 2. UID0003AY emits its throw-literal covered-by marker at position 3. UID0003OG remains external SDK data.
- Historical completion gate required coherent generated CPP/H with no empty marker or manual Singleton writes.
- Historical completion gate also required physical generated readback that `NexusTK/util/Error.h` exists with the exact DirectX-associated declarations and that `DirectX.cpp` compiles its `new MyError(...)` expressions against that header route.
- Callback completion readback satisfies that requirement: validator command `000000023312` assembled both source pairs; every Section 22 formal payload is present byte-for-byte after LF normalization, both generated marker orders are exact, and UID0002HO follows UID00008V in generated `Error.cpp`.
- Revised Gate 2B source-quality route: do not call `declare_type`. Treat expected `type_query total:0` as proof that no numbered local DirectX type is available, then make I10 self-contained with the full declaration `struct DirectX *g_pDirectX`, separate exact name `g_pDirectX`, and `delete_existing:false`. Verify the resulting four-byte item through the public `make_data` result and immediate `inspect_items` readback; do not require an unsupported standalone type-library row.

## Supervisor Active Recheck

- Historical trigger: Agent-B004 was assigned report-only whole-file research/repair with mandatory read-only IDA, and this cycle changed no by-* file. Current lifecycle authority is external as stated above.
- No new target split is needed. Existing exact children cover code, storage, vtable, diagnostic, and GUID; the repair is source-causal and emitter-order reconciliation.
- Every source-bearing item has exact formal CPP/H text or compiler-covered/external no-code proof in Section 22, including the DirectX-associated Error/MyError support source, exact UID0002HO payload identity, and the `0x004a68e0` compiler-wrapper source cause.
- Adjacent DIBitmap/EmployeeDialog, consumers, non-MyError Error siblings, shared Singleton template, COM APIs, runtime, and RTTI are explicitly dependent, compiler-generated, or excluded; no generic future-work bucket remains and no A/C-agent handoff is used.
- Historical Gate 1 passed on exact SHA256 `CE6CC820F576177B7CC08D12F7FECC4D5CC254A4CF7BFEA6FEFB04302850C525`, enabling the completed ordinary-document callback. Gate 1 and Gate 2A later passed on SHA256 `B5914B8C86E2A2A63B779C389FA435667F8C2E2423334211D7EF69B923DC7D41`, but Gate 2B failed closed at I09 and discarded all unsaved transient state. This repaired artifact is submitted for fresh Gate 1 review, and the authoritative current result exists only in `tools/leaser/Agents/b-report-validation-audit.md`. The 137 ordinary active rows remain complete; all 23 historicalized `excluded-with-reason` rows remain checked, and all 27 `proposed` supervisor-only rows remain unchecked as required.

## Inference Research Guidance Check

- `by-file/-guidance.md` requires exhaustive compilation-unit, sibling-H, generated-output, boundary, dependency, and ownership reconciliation. This report follows that whole-file gate.
- `by-structure.md` and incorporated inference guidance prevent generated names, old decompiler C++, and current emitter placement from becoming original-source proof.
- Direct IDA facts: PMDs/bases, bytes, function bounds, xrefs, vptr stores, global writes, and RTTI links. Inferences: normalized guard/includes, access token, names, and exact `NULL` spelling.
- Assumptions actively challenged: one-base declaration, manual singleton, private field, purely compiler-only `0x004a1cc0`, absent H, and exact-storage definition ownership.
- Wave2/Wave3 and the stale `source-3/simroot_v2/class_DirectX.cpp` reference were found and ignored as source authority. No current file exists at that path.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence | Disposition |
| --- | --- | --- |
| Missing Singleton base | DirectX CHD has DirectX, LObject, Singleton; Singleton PMD `+0x4`; ctor publishes complete object from `this+4`. | Declare direct `Singleton<DirectX>` base. |
| Layout | LObject vptr `+0x0`; empty Singleton `+0x4`; DirectDraw pointer `+0x4`; object size `0x8`. | EBO layout with size assertion. |
| Singleton source cause | Shared storage-free template and generated Crasher specializations match lowering. | Explicit consuming-module specializations; remove manual writes. |
| `0x004a1cc0` | Only clears global; sole ctor far-EH xref with Singleton subobject ECX; normal clear inlined. | Out-of-line Singleton destructor specialization, not DirectX helper. |
| Field access | Surface/GrafPort/ScreenPane directly use the field; no getter/friend family found. | Public is least-invented compileable access. |
| Header | Complete bases, field, methods, extern, and cross-module consumers require it. | DirectX.h mandatory. |
| Literal | Exact UTF-16 bytes, two ctor xrefs, no independent behavior. | Covered by throw expressions. |
| GUID | Typed IID, exact SDK bytes, one QueryInterface xref. | External `IID_IDirectDraw`, no local definition. |
| Vtable/RTTI | Exact slots/graph follow virtual multiple-inheritance declaration. | Compiler-covered, no handwritten table. |
| Emitter order | Current global precedes class emitter and physical child defines storage. | Class assembly: global 0, methods 1, vtable 2, diagnostic marker 3. |
| Error dependency | `new MyError` requires a complete type; current generated Error.h is absent, while fresh IDA resolves Error/MyError layout, slots, constructor, formatter, ordinary destructor, base Error scalar wrapper, MyError scalar wrapper, and common name body. | Include `../util/Error.h`; generate the exact coordinated source in Section 22; map `[0x004a68e0,0x004a691e)` to inline `Error::~Error()` and never emit the compiler flag/delete body as handwritten CPP. |
| Rejected alternatives | One base, generic static, class-static global, invented getter/friends, manual writes, standalone tables/data, consumer ownership. | Rejected by RTTI, xrefs, precedent, or compileability. |

## Evidence Standards Used

- Primary: read-only IDA attestation, functions, items, disassembly/decompilation, bytes, strings, conversions, imports, xrefs, globals, comments, RTTI/vtable graph, callers/callees, boundaries.
- Corroboration: current by-* docs/formal blocks, generated output, Singleton/Crasher precedent, coverage, and historical reports.
- Negative evidence: no fifth function, direct destructor caller, getter, separate Singleton ctor body, resource, source-owned GUID, current H, or consumer ownership.
- Evidence ladder: current binary facts outrank generated source and dated reports; project structure controls emitters; inference fills only source text absent from binary.
- Below 95 because no PDB proves exact tokens/access/guard/inlining and the IDA UDT remains intentionally absent. The DirectX-associated Error.h route is resolved; broader Error sibling reconstruction is outside this target's compile dependency and is not used as score credit.

## Evidence Checked

- IDA sessions `supervisor-canonical-uid0002PR-retry2-20260813`, `supervisor-canonical-uid0000KZ-gate2b-20260813`, and `supervisor-canonical-clean-20260813`, path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; schema-1 runtime attestations returned `ok:true`, and all work was read-only. Session identities are dated evidence, not permanent current-state assertions.
- Checked all four functions, far chunks, bytes, literal, 19 global xrefs, vtable slots/stores, GUID, ten RTTI objects, item/comment prestate, imports, callers/callees, and adjacent boundaries.
- Checked every DirectX page, mixed page, Singleton/Error/Application support, current generated consumers, tracker/coverage, and matching reports. The Error support pass additionally checked current by-file/class/layout/vtable/aggregate/constructor routes and fresh exact functions `0x004a67a0`, `0x004a6840`, `0x004a6860`, `0x004a68e0`, `0x004a6a10`, and `0x004a6a70`; `0x004a68e0` received fresh bounds, 62-byte SHA256, disassembly, decompile, item/type/comment/frame, xref, and callee readback.
- Negative searches covered names, addresses, reports, current H/CPP, resources, getters/friends, and predecessor/successor ownership.
- IDA conversion verified `0xf6=246`, `0x5c=92`, `0xb=11`, `0x9a=154`, `0x8=8`, `0x18=24`, `0x28=40`, `0x40=64`, `0x68=104`.
- Historical Gate 1 boundary: validator, generated refresh, IDA mutation, web research, execute_report, and lifecycle actions were intentionally skipped during report-only research because local evidence resolved the research.
- Implementation callback evidence: eighteen leased ordinary destinations passed scoped validation; command `000000023304` performed the coherent DirectX/Error generated refresh, and command `000000023312` repaired and verified the UID0002HO child assembly. IDA, manual coverage, execute_report, archive, and lifecycle actions remained excluded.
- Fresh report-repair evidence is supervisor-supplied canonical preflight plus the unsaved disposable-copy A05 probe and B004's current read-only public `idb_list`/`type_query` confirmation of the active canonical database and zero-record `DirectX` type prestate. It corrects report prestate and future Gate 2B actions only; B004 made no IDA mutation or save and reran no validator during this report-only repair.
- Gate 2B failure/recovery evidence is supervisor-supplied and dated 2026-08-14: M01-M11 commands `000000023527`-`000000023531`; exact A01-A08/P01-P23 and hash preflight; transient unsaved I01-I08 success; I09 apparent parser success followed by same-database `type_query total:0`; I10-I15 not called; discarded worker; clean recovery session `supervisor-uid0000IW-recovery-20260814`; catalog entry 0446; and audit state `FAILED_CLOSED_UNSAVED_STATE_DISCARDED_RECONCILIATION_REQUIRED`.
- Public-tool behavior was checked read-only in the installed MCP implementation. `api_types.py` lines 160-182 show `declare_type` returning success solely from zero `parse_decls_ctypes` errors; lines 563-590 show `type_query` enumerating only `get_numbered_type` ordinals. `api_modify.py` lines 1487-1582 show `make_data` accepting a full C declaration, rejecting unsized parses before mutation, using `SetType` when `delete_existing:false`, and returning public type/name/size/ok fields. Public `inspect_items` provides the independent item-level readback required by revised I10.
- Whole-file search result: every modeled code/data/type/import/resource candidate, caller/xref, neighboring boundary, related page, generated fragment, and report is inventoried or rejected below.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C0000IW-001 | 0000IW | DirectX remains the sole render compilation-unit owner at NexusTK/render/DirectX.cpp with a required DirectX.h. | High | File grouping, callers, generated consumers, and required complete declaration. | by-file/DirectX.md status, inventory, and source audit | incorporate | applied |
| C0000IW-002 | 0000IW | DirectX directly inherits LObject and Singleton<DirectX>, is size 0x8, and overlaps the empty Singleton base with m_pDirectDraw at +0x4. | High | Fresh RTTI PMDs, constructor lowering, field accesses, and allocation layout. | by-class/DirectX.md layout and formal H | incorporate | applied |
| C0000IW-003 | 0000IW | The class formal H must become the complete guarded DirectX.h declaration. | High | Missing generated H and cross-module direct consumers. | by-class/DirectX.md RECONSTRUCTION_H | incorporate | applied |
| C0000IW-004 | 0000IW | The class formal CPP must include DirectX.h and Error.h then emit ordered children. | High | Required source order and MyError complete-type dependency. | by-class/DirectX.md RECONSTRUCTION_CPP | incorporate | applied |
| C0000IW-005 | 0000IW | Retired grouped global/specialization source authority; C0000IW-178 through C0000IW-180 are the sole canonical per-definition/method actions. | High | Gate 1 allocation repair and exact three-definition formal block. | report ledger, source allocation, and checklist | historicalize | excluded-with-reason |
| C0000IW-006 | 0000IW | Exact storage UID000295 must be covered by the semantic global definition rather than define the pointer a second time. | High | One-definition rule and corrected semantic-global route. | by-memory/0x0067ab20-0x0067ab24.g_pDirectX.md formal CPP | incorporate | applied |
| C0000IW-007 | 0000IW | DirectX constructor initializes both bases and m_pDirectDraw, creates DirectDraw, queries IID_IDirectDraw, and pointer-throws MyError on either failure without manual global writes. | High | Local/far disassembly, calls, literal xrefs, and Singleton source cause. | by-memory/0x004a1b60-0x004a1d6a.DirectX.md formal CPP | incorporate | applied |
| C0000IW-008 | 0000IW | DirectX destructor releases m_pDirectDraw and nulls it without manual global clear or null guard. | High | Exact destructor and reverse base-destruction semantics. | by-memory/0x004a1b60-0x004a1d6a.DirectX.md formal CPP | incorporate | applied |
| C0000IW-009 | 0000IW | Function 0x004a1cc0 is the out-of-line Singleton<DirectX> destructor specialization used by constructor unwind, not a standalone DirectX helper. | High | Sole far-EH xref, ECX subobject setup, body, and ordinary inlining. | by-memory DirectX aggregate classification | historicalize | applied |
| C0000IW-010 | 0000IW | Function 0x004a1cd0 and its far handlers are compiler-generated scalar deleting destructor coverage. | High | Vtable route, flags 1 and 4, delete call, no source-only behavior. | by-memory DirectX aggregate marker policy | incorporate | applied |
| C0000IW-011 | 0000IW | Exact DirectX vtable data is compiler-covered and needs a nonempty covered-by marker. | High | Four exact dwords and three vptr stores. | by-memory DirectXVtableData formal CPP | incorporate | applied |
| C0000IW-012 | 0000IW | The diagnostic range is covered by the constructor throw literal and needs no standalone definition. | High | Exact UTF-16 bytes and two ctor xrefs. | by-memory DirectXDiagnosticString formal CPP | incorporate | applied |
| C0000IW-013 | 0000IW | IID_IDirectDraw at 0x00631570 is external SDK data, not file-owned initialized data. | High | IID type, exact bytes, one QueryInterface xref. | by-memory DirectDrawGuidConstant source disposition | already-present | already-present |
| C0000IW-014 | 0000IW | Retired grouped RTTI authority; C0000IW-035 through C0000IW-044 are the sole canonical per-object claims. | High | Gate 1 atomicity repair and exact ten-object inventory. | report ledger, inventory, and checklist | historicalize | excluded-with-reason |
| C0000IW-015 | 0000IW | Retired grouped function/far authority; C0000IW-045 through C0000IW-053 are the sole canonical local/far/no-fifth claims. | High | Gate 1 atomicity repair and exact modeled/far boundaries. | report ledger, inventory, and checklist | historicalize | excluded-with-reason |
| C0000IW-016 | 0000IW | Retired grouped padding authority; C0000IW-054 through C0000IW-058 are the sole canonical span claims. | High | Gate 1 atomicity repair and exact half-open CC ranges. | report ledger, inventory, and checklist | historicalize | excluded-with-reason |
| C0000IW-017 | 0000IW | Retired all-xrefs aggregate authority; C0000IW-059 through C0000IW-103 are the sole canonical caller/callee/xref claims. | High | Gate 1 atomicity repair and fresh complete item-level queries. | report ledger, xref inventory, and checklist | historicalize | excluded-with-reason |
| C0000IW-018 | 0000IW | DirectDrawCreate, QueryInterface, and Release are external COM dependencies, not imported source bodies. | High | IAT 0x0060d024 and indirect calls. | by-file dependency inventory | incorporate | applied |
| C0000IW-019 | 0000IW | The DirectX.cpp source action must include ../util/Error.h because both MyError allocations require the complete coordinated declaration supplied in Section 22. | High | Two exact MyError allocation/constructor routes and the C++ complete-type requirement. | by-file/DirectX.md dependency audit | incorporate | applied |
| C0000IW-020 | 0000IW | m_pDirectDraw should be public because unrelated modules access it directly and no getter/friend family is evidenced. | Medium-high | Surface, GrafPort, ScreenPane routes. | by-class formal H and access rationale | incorporate | applied |
| C0000IW-021 | 0000IW | Retired grouped five-document child-order authority; C0000IW-138 through C0000IW-145 are the sole canonical class-entry and child-metadata actions. | High | Gate 1 physical-destination allocation repair. | report ledger, source placement, and checklist | historicalize | excluded-with-reason |
| C0000IW-022 | 0000IW | Generated DirectX.cpp is incomplete due to wrong bases, manual writes, private field, missing includes/H, and empty marker. | High | Physical readback of command 000000023186. | by-file generated-source audit | incorporate | applied |
| C0000IW-023 | 0000IW | Target file score should become 92/94 after implementation and coherent generated verification. | Medium-high | Whole-file closure plus in-scope Error/MyError header closure, with only bounded original-token uncertainty. | by-file metadata and score rationale | incorporate | applied |
| C0000IW-024 | 0000IW | DirectX class score should become 92/94 after H, layout, access, and emitter repair. | Medium-high | RTTI/layout and exact formal H plan. | by-class metadata and score rationale | incorporate | applied |
| C0000IW-025 | 0000IW | Retired grouped global/storage score authority; C0000IW-146 and C0000IW-147 independently allocate the two physical score changes. | Medium-high | Gate 1 physical-destination allocation repair. | report ledger, score section, and checklist | historicalize | excluded-with-reason |
| C0000IW-026 | 0000IW | DirectX code aggregate should become 92/94 after method and compiler-coverage repair. | Medium-high | Complete local/far inventory and formal methods. | code aggregate metadata | incorporate | applied |
| C0000IW-027 | 0000IW | Retired grouped vtable-type/data score authority; C0000IW-148 and C0000IW-149 independently allocate the two physical score changes. | Medium-high | Gate 1 physical-destination allocation repair. | report ledger, score section, and checklist | historicalize | excluded-with-reason |
| C0000IW-028 | 0000IW | DirectX diagnostic child should become 92/94 after covered-by source-literal repair. | Medium-high | Bytes, boundaries, both xrefs. | by-memory DirectXDiagnosticString | incorporate | applied |
| C0000IW-029 | 0000IW | Prior manual-global and pure-helper conclusions must remain historical and superseded. | High | Fresh RTTI/Singleton contradiction. | by-file/DirectX.md historical notes | reject-stale | applied |
| C0000IW-030 | 0000IW | Retired original grouped IDA authority; C0000IW-110-C0000IW-111 and C0000IW-150-C0000IW-161 are the sole canonical atomic mutation claims. | High | Gate 1 allocation repair and exact eight-entity/fourteen-action handoff. | report ledger, Section 21, and checklist | historicalize | excluded-with-reason |
| C0000IW-031 | 0000IW | Retired grouped manual-coverage authority; C0000IW-112-C0000IW-119 and C0000IW-175-C0000IW-177 are the sole canonical per-operation claims. | High | Gate 1 allocation repair and exact eleven supervisor-only operations. | report ledger, Section 28, and checklist | historicalize | excluded-with-reason |
| C0000IW-032 | 0000IW | DIBitmap predecessor, EmployeeDialog successor, Application policy, and render consumers are excluded as DirectX source. | High | Boundaries and consumer-only roles. | by-file/DirectX.md exclusions | reject-invalid | applied |
| C0000IW-033 | 0000IW | No third-party import directive or resource child belongs to this module. | High | Dependency/resource searches show SDK use only. | by-file dependency audit | not-applicable | excluded-with-reason |
| C0000IW-034 | 0000IW | Only this report changes in report-only work and lifecycle actions remain supervisor-owned. | High | Assignment boundary, lease, changed-file readback. | report Changed Files and checklist | incorporate | proposed |
| C0000IW-035 | 0000IW | RTTI COL 0x0064681c-0x00646830 is compiler-generated DirectX support linking vtable prelude 0x00618e60, type descriptor 0x00675be0, and CHD 0x00646830. | High | Fresh item/byte/link readback. | by-class/DirectX.md RTTI evidence | incorporate | applied |
| C0000IW-036 | 0000IW | RTTI CHD 0x00646830-0x00646840 is compiler-generated and records count 3 with BCA 0x00646840. | High | Fresh CHD fields and direct link. | by-class/DirectX.md RTTI evidence | incorporate | applied |
| C0000IW-037 | 0000IW | RTTI BCA 0x00646840-0x00646850 lists DirectX BCD 0x00646850, existing LObject BCD 0x00640348, and Singleton BCD 0x0064686c. | High | Fresh three-entry BCA readback. | by-class/DirectX.md RTTI evidence | incorporate | applied |
| C0000IW-038 | 0000IW | DirectX self BCD 0x00646850-0x0064686c is compiler-generated with PMD {0,-1,0}. | High | Fresh BCD field readback. | by-class/DirectX.md layout evidence | incorporate | applied |
| C0000IW-039 | 0000IW | Singleton<DirectX> base BCD 0x0064686c-0x00646888 is compiler-generated with PMD {+4,-1,0}, type 0x00675bf8, and CHD 0x00646888. | High | Fresh BCD/PMD/link readback. | by-class/DirectX.md inheritance evidence | incorporate | applied |
| C0000IW-040 | 0000IW | Singleton<DirectX> CHD 0x00646888-0x00646898 is compiler-generated hierarchy support. | High | Fresh range and link readback. | by-class/DirectX.md RTTI evidence | incorporate | applied |
| C0000IW-041 | 0000IW | Singleton<DirectX> BCA 0x00646898-0x006468a0 is compiler-generated and points to self BCD 0x006468a0. | High | Fresh BCA pointer readback. | by-class/DirectX.md RTTI evidence | incorporate | applied |
| C0000IW-042 | 0000IW | Singleton<DirectX> self BCD 0x006468a0-0x006468bc is compiler-generated with self PMD {0,-1,0}. | High | Fresh BCD field readback. | by-class/DirectX.md RTTI evidence | incorporate | applied |
| C0000IW-043 | 0000IW | DirectX type descriptor 0x00675be0-0x00675bf8 is compiler-generated and names .?AVDirectX@@. | High | Fresh descriptor bytes/name and COL link. | by-class/DirectX.md RTTI evidence | incorporate | applied |
| C0000IW-044 | 0000IW | Singleton<DirectX> type descriptor 0x00675bf8-0x00675c20 is compiler-generated and names .?AV?$Singleton@VDirectX@@@@. | High | Fresh descriptor bytes/name and BCD link. | by-class/DirectX.md RTTI evidence | incorporate | applied |
| C0000IW-045 | 000137 | Function 0x004a1b60-0x004a1c56 is the sole DirectX source constructor body. | High | Fresh modeled extent, disassembly, one caller, and source calls. | by-memory/0x004a1b60-0x004a1d6a.DirectX.md function inventory | incorporate | applied |
| C0000IW-046 | 000137 | Function 0x004a1c60-0x004a1cbc is the DirectX ordinary destructor body. | High | Fresh modeled extent, Release path, base teardown, and no direct caller. | by-memory/0x004a1b60-0x004a1d6a.DirectX.md function inventory | incorporate | applied |
| C0000IW-047 | 000137 | Function 0x004a1cc0-0x004a1ccb is the out-of-line Singleton<DirectX> destructor specialization used by constructor unwind. | High | Exact two-instruction body and sole inbound xref 0x005fd71e. | by-memory DirectX aggregate function inventory | incorporate | applied |
| C0000IW-048 | 000137 | Function 0x004a1cd0-0x004a1d6a is compiler-generated DirectX scalar-deleting-destructor coverage. | High | Fresh extent, vtable inbound route, flags, destruction, and optional delete. | by-memory/0x004a1b60-0x004a1d6a.DirectX.md function inventory | incorporate | applied |
| C0000IW-049 | 000137 | Far range 0x005fd710-0x005fd750 is constructor EH/unwind support and emits no handwritten body. | High | Fresh disassembly of base cleanup, Singleton cleanup, allocation cleanup, cookie, and frame handler. | by-memory DirectX aggregate far inventory | incorporate | applied |
| C0000IW-050 | 000137 | Far range 0x005fd754-0x005fd76b is destructor SEH/cookie/frame-handler support and emits no handwritten body. | High | Fresh destructor disassembly and range boundary. | by-memory DirectX aggregate far inventory | incorporate | applied |
| C0000IW-051 | 000137 | Far range 0x005f6800-0x005f6817 is scalar-wrapper SEH/cookie/frame-handler support and emits no handwritten body. | High | Fresh scalar-wrapper disassembly and range boundary. | by-memory DirectX aggregate far inventory | incorporate | applied |
| C0000IW-052 | 000137 | Far thunk at 0x005c91f2 is scalar-wrapper terminate support and emits no handwritten DirectX body. | High | Fresh jump-to-_terminate disassembly. | by-memory DirectX aggregate far inventory | incorporate | applied |
| C0000IW-053 | 000137 | No fifth DirectX function exists between predecessor end 0x004a1b5e and successor start 0x004a1d70. | High | Fresh function listing, exact four extents, padding bytes, and successor lookup. | by-memory DirectX aggregate function inventory | incorporate | applied |
| C0000IW-054 | 000137 | Padding `[0x004a1b5e,0x004a1b60)` is the two-byte CC boundary after DIBitmap and before the DirectX constructor. | High | Raw bytes and predecessor/constructor boundaries. | by-memory DirectX aggregate padding inventory | incorporate | applied |
| C0000IW-055 | 000137 | Padding `[0x004a1c56,0x004a1c60)` is the ten-byte CC boundary between DirectX constructor and destructor. | High | Raw bytes and both modeled extents. | by-memory DirectX aggregate padding inventory | incorporate | applied |
| C0000IW-056 | 000137 | Padding `[0x004a1cbc,0x004a1cc0)` is the four-byte CC boundary between DirectX destructor and Singleton destructor specialization. | High | Raw bytes and both modeled extents. | by-memory DirectX aggregate padding inventory | incorporate | applied |
| C0000IW-057 | 000137 | Padding `[0x004a1ccb,0x004a1cd0)` is the five-byte CC boundary between Singleton destructor specialization and scalar wrapper. | High | Raw bytes and both modeled extents. | by-memory DirectX aggregate padding inventory | incorporate | applied |
| C0000IW-058 | 000137 | Padding `[0x004a1d6a,0x004a1d70)` is the six-byte CC boundary between the scalar wrapper and EmployeeDialog successor. | High | Raw bytes and scalar/successor boundaries. | by-memory DirectX aggregate padding inventory | incorporate | applied |
| C0000IW-059 | 000137 | DirectX constructor has one inbound call at 0x004645aa from Application__Startup. | High | Fresh xref query total and caller function. | by-memory DirectX aggregate direct-xref inventory | incorporate | applied |
| C0000IW-060 | 000137 | DirectX constructor calls LObject_constructor at 0x004a1b8c -> 0x004f4a80. | High | Fresh disassembly direct call. | by-memory DirectX aggregate callee inventory | incorporate | applied |
| C0000IW-061 | 000137 | DirectX constructor calls DirectDrawCreate at 0x004a1bcb -> 0x005c5c87/IAT 0x0060d024. | High | Fresh disassembly and import route. | by-memory DirectX aggregate callee inventory | incorporate | applied |
| C0000IW-062 | 000137 | DirectX constructor performs the IDirectDraw QueryInterface indirect call at 0x004a1be0 using object vslot +0x00. | High | Fresh disassembly and argument setup. | by-memory DirectX aggregate callee inventory | incorporate | applied |
| C0000IW-063 | 000137 | Retired grouped allocation-callee authority; C0000IW-132 and C0000IW-133 are the sole canonical per-callsite claims. | High | Gate 1 atomicity repair and exact two allocation callsites. | report ledger, xref inventory, and checklist | historicalize | excluded-with-reason |
| C0000IW-064 | 000137 | Retired grouped MyError-callee authority; C0000IW-134 and C0000IW-135 are the sole canonical per-callsite claims. | High | Gate 1 atomicity repair and exact two constructor callsites. | report ledger, xref inventory, and checklist | historicalize | excluded-with-reason |
| C0000IW-065 | 000137 | DirectX constructor converges both failure branches on __CxxThrowException at 0x004a1c51 -> 0x005ca20a. | High | Fresh disassembly and MyError throw-info route. | by-memory DirectX aggregate callee inventory | incorporate | applied |
| C0000IW-066 | 000137 | Constructor far cleanup 0x005fd713 tail-jumps to LObject_destructor 0x004f4a90. | High | Fresh far disassembly. | by-memory DirectX aggregate far/xref inventory | incorporate | applied |
| C0000IW-067 | 000137 | Constructor far cleanup 0x005fd71e tail-jumps to Singleton<DirectX> destructor specialization 0x004a1cc0. | High | Fresh far disassembly and sole inbound xref. | by-memory DirectX aggregate far/xref inventory | incorporate | applied |
| C0000IW-068 | 000137 | Retired grouped far-cleanup-callee authority; C0000IW-136 and C0000IW-137 are the sole canonical per-callsite claims. | High | Gate 1 atomicity repair and exact two cleanup callsites. | report ledger, xref inventory, and checklist | historicalize | excluded-with-reason |
| C0000IW-069 | 000137 | DirectX destructor invokes IDirectDraw::Release indirectly at 0x004a1c91 through vslot +0x08. | High | Fresh destructor disassembly. | by-memory DirectX aggregate callee inventory | incorporate | applied |
| C0000IW-070 | 000137 | DirectX destructor calls LObject_destructor at 0x004a1ca7 -> 0x004f4a90 after Singleton clear lowering. | High | Fresh destructor disassembly. | by-memory DirectX aggregate callee inventory | incorporate | applied |
| C0000IW-071 | 000137 | DirectX destructor has no direct code caller and is reached virtually through the DirectX vtable. | High | Fresh caller count zero plus vtable slot route. | by-memory DirectX aggregate caller inventory | incorporate | applied |
| C0000IW-072 | 000137 | Singleton<DirectX> destructor specialization 0x004a1cc0 has exactly one inbound code xref at 0x005fd71e. | High | Fresh complete xref query. | by-memory DirectX aggregate caller inventory | incorporate | applied |
| C0000IW-073 | 000137 | DirectX scalar wrapper 0x004a1cd0 has one inbound data route from vtable slot 0x00618e64. | High | Fresh complete xref query and vtable bytes. | by-memory DirectX aggregate caller inventory | incorporate | applied |
| C0000IW-074 | 000137 | DirectX scalar wrapper invokes IDirectDraw::Release indirectly at 0x004a1d08 through vslot +0x08. | High | Fresh scalar-wrapper disassembly. | by-memory DirectX aggregate callee inventory | incorporate | applied |
| C0000IW-075 | 000137 | DirectX scalar wrapper calls LObject_destructor at 0x004a1d1e -> 0x004f4a90. | High | Fresh scalar-wrapper disassembly. | by-memory DirectX aggregate callee inventory | incorporate | applied |
| C0000IW-076 | 000137 | DirectX scalar wrapper conditionally calls NexusTK_operator_delete_wrapper at 0x004a1d2f -> 0x004f4ac0. | High | Fresh scalar-wrapper disassembly and flags path. | by-memory DirectX aggregate callee inventory | incorporate | applied |
| C0000IW-077 | 000137 | DirectX scalar wrapper flag-4 path calls _guard_check_icall_nop at 0x004a1d4e -> 0x0041b6a0. | High | Fresh scalar-wrapper disassembly. | by-memory DirectX aggregate callee inventory | incorporate | applied |
| C0000IW-078 | 000137 | DirectX scalar-wrapper far thunk 0x005c91f2 tail-jumps to _terminate 0x005dce60. | High | Fresh far disassembly. | by-memory DirectX aggregate far/callee inventory | incorporate | applied |
| C0000IW-079 | 0000QS | g_pDirectX xref 0x00464b44 is an Application__Shutdown read. | High | Fresh exact global xref row. | by-global/g_pDirectX.md xref inventory | incorporate | applied |
| C0000IW-080 | 0000QS | g_pDirectX xref 0x004a1ba2 publishes the complete DirectX object from the non-null Singleton base path. | High | Fresh exact global xref row and constructor arithmetic. | by-global/g_pDirectX.md lifetime inventory | incorporate | applied |
| C0000IW-081 | 0000QS | g_pDirectX xref 0x004a1ba9 writes NULL on the null-adjustment branch of inlined Singleton construction. | High | Fresh exact global xref row and constructor branch. | by-global/g_pDirectX.md lifetime inventory | incorporate | applied |
| C0000IW-082 | 0000QS | g_pDirectX xref 0x004a1c9d clears the pointer during ordinary DirectX destruction. | High | Fresh exact global xref row. | by-global/g_pDirectX.md lifetime inventory | incorporate | applied |
| C0000IW-083 | 0000QS | g_pDirectX xref 0x004a1cc0 clears the pointer in the out-of-line Singleton destructor specialization. | High | Fresh exact global xref row and exact helper body. | by-global/g_pDirectX.md lifetime inventory | incorporate | applied |
| C0000IW-084 | 0000QS | g_pDirectX xref 0x004a1d14 clears the pointer in compiler-generated scalar deletion. | High | Fresh exact global xref row. | by-global/g_pDirectX.md lifetime inventory | incorporate | applied |
| C0000IW-085 | 0000QS | g_pDirectX xref 0x004b8d78 is a render/UI consumer read. | High | Fresh exact global xref row. | by-global/g_pDirectX.md consumer inventory | incorporate | applied |
| C0000IW-086 | 0000QS | g_pDirectX xref 0x004b92bc is a render/UI consumer read. | High | Fresh exact global xref row. | by-global/g_pDirectX.md consumer inventory | incorporate | applied |
| C0000IW-087 | 0000QS | g_pDirectX xref 0x004b9800 is a render/UI consumer read. | High | Fresh exact global xref row. | by-global/g_pDirectX.md consumer inventory | incorporate | applied |
| C0000IW-088 | 0000QS | g_pDirectX xref 0x004bb83f is a render/UI consumer read. | High | Fresh exact global xref row. | by-global/g_pDirectX.md consumer inventory | incorporate | applied |
| C0000IW-089 | 0000QS | g_pDirectX xref 0x00556b22 is a ScreenPane destructor consumer read. | High | Fresh exact global xref row. | by-global/g_pDirectX.md consumer inventory | incorporate | applied |
| C0000IW-090 | 0000QS | g_pDirectX xref 0x00556b77 is a second ScreenPane destructor consumer read. | High | Fresh exact global xref row. | by-global/g_pDirectX.md consumer inventory | incorporate | applied |
| C0000IW-091 | 0000QS | g_pDirectX xref 0x005574a0 is a Surface/GrafPort-family consumer read. | High | Fresh exact global xref row. | by-global/g_pDirectX.md consumer inventory | incorporate | applied |
| C0000IW-092 | 0000QS | g_pDirectX xref 0x005576d0 is a Surface/GrafPort-family consumer read. | High | Fresh exact global xref row. | by-global/g_pDirectX.md consumer inventory | incorporate | applied |
| C0000IW-093 | 0000QS | g_pDirectX xref 0x005583d0 is a DirectDraw consumer read. | High | Fresh exact global xref row. | by-global/g_pDirectX.md consumer inventory | incorporate | applied |
| C0000IW-094 | 0000QS | g_pDirectX xref 0x005586a3 is an InitializeSurfaceRenderCallbacks consumer read. | High | Fresh exact global xref row. | by-global/g_pDirectX.md consumer inventory | incorporate | applied |
| C0000IW-095 | 0000QS | g_pDirectX xref 0x00558875 is a DirectDraw consumer read. | High | Fresh exact global xref row. | by-global/g_pDirectX.md consumer inventory | incorporate | applied |
| C0000IW-096 | 0000QS | g_pDirectX xref 0x00558b24 is a second read in the 0x00558840 DirectDraw consumer. | High | Fresh exact global xref row. | by-global/g_pDirectX.md consumer inventory | incorporate | applied |
| C0000IW-097 | 0000QS | g_pDirectX xref 0x00559a63 is the final exact DirectDraw consumer read. | High | Fresh exact global xref row; query total is 19 with no continuation. | by-global/g_pDirectX.md consumer inventory | incorporate | applied |
| C0000IW-098 | 0002MD | DirectX vtable xref 0x004a1bbf installs 0x00618e64 during construction. | High | Fresh exact vptr-store disassembly. | by-memory DirectXVtableData xref inventory | incorporate | applied |
| C0000IW-099 | 0002MD | DirectX vtable xref 0x004a1c88 restores 0x00618e64 during ordinary destruction. | High | Fresh exact vptr-store disassembly. | by-memory DirectXVtableData xref inventory | incorporate | applied |
| C0000IW-100 | 0002MD | DirectX vtable xref 0x004a1cf8 restores 0x00618e64 during scalar deletion. | High | Fresh exact vptr-store disassembly. | by-memory DirectXVtableData xref inventory | incorporate | applied |
| C0000IW-101 | 0003AY | Diagnostic literal xref 0x004a1bfb supplies the QueryInterface-failure MyError message. | High | Fresh exact literal xref and branch disassembly. | by-memory DirectXDiagnosticString xref inventory | incorporate | applied |
| C0000IW-102 | 0003AY | Diagnostic literal xref 0x004a1c31 supplies the DirectDrawCreate-failure MyError message. | High | Fresh exact literal xref and branch disassembly. | by-memory DirectXDiagnosticString xref inventory | incorporate | applied |
| C0000IW-103 | 0003OG | IID_IDirectDraw xref 0x004a1bd8 is the sole direct GUID use and feeds QueryInterface. | High | Fresh exact GUID xref query. | by-memory DirectDrawGuidConstant xref inventory | already-present | already-present |
| C0000IW-104 | 0000IW | Retired A01 two-mutation authority; C0000IW-150 and C0000IW-151 are the sole canonical constructor rename and comment actions. | Medium-high | Gate 1 IDA action-allocation repair. | report ledger, IDA handoff, and checklist | historicalize | excluded-with-reason |
| C0000IW-105 | 0000IW | Retired A02 two-mutation authority; C0000IW-152 and C0000IW-153 are the sole canonical destructor rename and comment actions. | Medium-high | Gate 1 IDA action-allocation repair. | report ledger, IDA handoff, and checklist | historicalize | excluded-with-reason |
| C0000IW-106 | 0000IW | Retired A03 two-mutation authority; C0000IW-154 and C0000IW-155 are the sole canonical Singleton-destructor rename and comment actions. | Medium-high | Gate 1 IDA action-allocation repair. | report ledger, IDA handoff, and checklist | historicalize | excluded-with-reason |
| C0000IW-107 | 0000IW | Retired A04 two-mutation authority; C0000IW-156 and C0000IW-157 are the sole canonical scalar-wrapper rename and comment actions. | Medium-high | Gate 1 IDA action-allocation repair. | report ledger, IDA handoff, and checklist | historicalize | excluded-with-reason |
| C0000IW-108 | 0000IW | Retired A05 two-mutation rename/comment authority; C0000IW-158, C0000IW-187, and C0000IW-159 are the sole canonical no-standalone-type preflight, self-contained fresh data/type/name action, and comment steps. | Medium-high | Fresh canonical preflight disproved the old symbol; Gate 2B disproved enumerable forward-type readback; the disposable-copy probe established the item-level route. | report ledger, IDA handoff, and checklist | historicalize | excluded-with-reason |
| C0000IW-109 | 0000IW | Retired A06 two-mutation authority; C0000IW-160 and C0000IW-161 are the sole canonical IID rename and comment actions. | Medium-high | Gate 1 IDA action-allocation repair. | report ledger, IDA handoff, and checklist | historicalize | excluded-with-reason |
| C0000IW-110 | 0000IW | IDA action I14 independently adds the exact address-repeatable comment at COL cell 0x00618e60 while preserving name, type, item, xrefs, and 4-byte SHA256. | Medium-high | Fresh literal A07 prestate and SHA256 B474BB52FFB7CCFC2DF90E99C09953CCF65E7E4886858CB13E8E8775584E957A. | Supervisor Gate 2B I14 | incorporate | proposed |
| C0000IW-111 | 0000IW | IDA action I15 independently adds the exact address-repeatable comment at literal head 0x00618e70 while preserving split item, name, type, xrefs, and 140-byte SHA256. | Medium-high | Fresh literal A08 prestate and SHA256 538C0281DE2C7CEFCEDC5B949737DD09ED86FD7D7D8FE8B1E8C355E652AD446B. | Supervisor Gate 2B I15 | incorporate | proposed |
| C0000IW-112 | 0000IW | Supervisor-only manual coverage operation M01 replaces the UID0000IW by-file row with the exact Section 28 text. | High | Physical manual by-file coverage readback. | by-file/-coverage-report.md UID0000IW | incorporate | proposed |
| C0000IW-113 | 00003Y | Supervisor-only manual coverage operation M02 replaces the UID00003Y by-class row with the exact Section 28 text. | High | Physical manual by-class coverage readback. | by-class/-coverage-report.md UID00003Y | incorporate | proposed |
| C0000IW-114 | 0000QS | Supervisor-only manual coverage operation M03 replaces the UID0000QS by-global row with the exact Section 28 text. | High | Physical manual by-global coverage readback. | by-global/-coverage-report.md UID0000QS | incorporate | proposed |
| C0000IW-115 | 000137 | Supervisor-only manual coverage operation M04 replaces the UID000137 by-memory row with the exact Section 28 text. | High | Physical manual by-memory coverage readback. | by-memory/-coverage-report.md UID000137 | incorporate | proposed |
| C0000IW-116 | 0002MD | Supervisor-only manual coverage operation M05 replaces the UID0002MD by-memory row with the exact Section 28 text. | High | Physical manual by-memory coverage readback. | by-memory/-coverage-report.md UID0002MD | incorporate | proposed |
| C0000IW-117 | 0003AY | Supervisor-only manual coverage operation M06 inserts the absent UID0003AY by-memory row with the exact Section 28 text. | High | Physical absence in manual by-memory coverage. | by-memory/-coverage-report.md UID0003AY | incorporate | proposed |
| C0000IW-118 | 000295 | Supervisor-only manual coverage operation M07 replaces the UID000295 by-memory row with the exact Section 28 text. | High | Physical manual by-memory coverage readback. | by-memory/-coverage-report.md UID000295 | incorporate | proposed |
| C0000IW-119 | 0003HP | Supervisor-only manual coverage operation M08 replaces the UID0003HP by-vtable row with the exact Section 28 text. | High | Physical manual by-vtable coverage readback. | by-type/by-vtable/-coverage-report.md UID0003HP | incorporate | proposed |
| C0000IW-120 | 0000J5 | The Error file support action owns the required NexusTK/util/Error.h generation route; absence in command 000000023186 is historical prestate, not deferred work. | High | Physical generated absence plus fresh Error/MyError IDA and existing hierarchy docs. | by-file/Error.md DirectX support closure and generated audit | incorporate | applied |
| C0000IW-121 | 00004J | Retired grouped Error CPP/H authority; C0000IW-162 and C0000IW-163 independently allocate the formal H block and GetErrorName CPP action. | High | Gate 1 CPP/H destination allocation repair. | report ledger, source section, and checklist | historicalize | excluded-with-reason |
| C0000IW-122 | 00008V | Retired grouped MyError CPP/H/method authority; C0000IW-164 through C0000IW-166 independently allocate H, formatter CPP, and destructor CPP actions. | High | Gate 1 CPP/H method allocation repair. | report ledger, source section, and checklist | historicalize | excluded-with-reason |
| C0000IW-123 | 00008V | MyError::FormatErrorMessage is exactly the 0x004a6840-0x004a6858 wcscpy_s wrapper returning int-compatible errno_t from m_messageText at +0x04. | High | Fresh nine-instruction decompile/disassembly, sole wcscpy_s callee, vtable route. | by-memory ErrorWrappers exact formatter split evidence | incorporate | applied |
| C0000IW-124 | 00008V | MyError::~MyError is exactly 0x004a6860-0x004a6882, frees m_messageText at +0x04, restores Error vtable state, and tears down LObject. | High | Fresh ten-instruction decompile/disassembly and callees. | by-memory ErrorWrappers exact destructor split evidence | incorporate | applied |
| C0000IW-125 | 00004J | Error::GetErrorName is exactly 0x004a6a70-0x004a6a76 and returns L"Error" for the common +0x10 slot. | High | Fresh two-instruction decompile/disassembly and vtable evidence. | by-memory ErrorDestructorAndNameHelpers exact GetErrorName row | incorporate | applied |
| C0000IW-126 | 0002HO | Retired grouped constructor-channel authority; C0000IW-173 and C0000IW-174 independently allocate exact CPP identity and blank-H disposition. | High | Gate 1 constructor CPP/H identity repair. | report ledger, source section, and checklist | historicalize | excluded-with-reason |
| C0000IW-127 | 00013X | Retired aggregate ErrorWrappers support authority; C0000IW-123 and C0000IW-124 are the sole canonical per-function memory-page actions. | High | Gate 1 expanded-support allocation repair. | report ledger, Error inventory, and checklist | historicalize | excluded-with-reason |
| C0000IW-128 | 0002TV | The 0x004a6a10 MyError scalar deleting destructor remains compiler-covered by the ordinary 0x004a6860 destructor and must not emit a duplicate source body. | High | Fresh wrapper disassembly, vtable route, free/base/delete paths. | by-memory/0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers.md coverage reconciliation | incorporate | applied |
| C0000IW-129 | 0002ND | Error/MyError vtable data remains compiler-generated from the new declarations; no raw table source is added. | High | Exact Error and MyError five-slot rows at 0x00619344 and 0x00619434. | by-memory/0x00619340-0x00619448.ErrorHierarchyVtableData.md source-cause reconciliation | incorporate | applied |
| C0000IW-130 | 0001UE | Error support declarations must preserve sizeof(Error)==0x4 and sizeof(MyError)==0x8 with m_messageText at +0x04. | High | Fresh constructor/formatter/destructor offsets and existing layout family. | by-type/by-struct/ErrorObjectLayouts.md support declaration reconciliation | incorporate | applied |
| C0000IW-131 | 0001XI | Error support declarations must preserve the five-slot virtual order: destructor, inherited runtime, inherited message-change, FormatErrorMessage, GetErrorName. | High | Exact base/MyError vtable rows and WinMain consumer contract. | by-type/by-vtable/ErrorHierarchyVtables.md support declaration reconciliation | incorporate | applied |
| C0000IW-132 | 000137 | DirectX constructor QueryInterface-failure allocation site 0x004a1be8 calls NexusTK_operator_new 0x004f4aa0 for one 8-byte MyError object. | High | Fresh exact disassembly at 0x004a1be6-0x004a1bed. | by-memory DirectX aggregate callee inventory | incorporate | applied |
| C0000IW-133 | 000137 | DirectX constructor DirectDrawCreate-failure allocation site 0x004a1c1e calls NexusTK_operator_new 0x004f4aa0 for one 8-byte MyError object. | High | Fresh exact disassembly at 0x004a1c1c-0x004a1c23. | by-memory DirectX aggregate callee inventory | incorporate | applied |
| C0000IW-134 | 000137 | DirectX constructor QueryInterface-failure site 0x004a1c02 calls MyError constructor 0x004a67a0. | High | Fresh exact disassembly and Error support readback. | by-memory DirectX aggregate callee inventory | incorporate | applied |
| C0000IW-135 | 000137 | DirectX constructor DirectDrawCreate-failure site 0x004a1c38 calls MyError constructor 0x004a67a0. | High | Fresh exact disassembly and Error support readback. | by-memory DirectX aggregate callee inventory | incorporate | applied |
| C0000IW-136 | 000137 | Constructor far cleanup site 0x005fd727 calls NexusTK_operator_delete_wrapper 0x004f4ac0. | High | Fresh exact far disassembly of QueryInterface-failure allocation cleanup. | by-memory DirectX aggregate far/callee inventory | incorporate | applied |
| C0000IW-137 | 000137 | Constructor far cleanup site 0x005fd732 calls NexusTK_operator_delete_wrapper 0x004f4ac0. | High | Fresh exact far disassembly of DirectDrawCreate-failure allocation cleanup. | by-memory DirectX aggregate far/callee inventory | incorporate | applied |
| C0000IW-138 | 00003Y | DirectX class assembly must list semantic global UID0000QS as child position 0. | High | Include/specialization-before-method order and emitter graph. | by-class/DirectX.md child assembly entry for UID0000QS | incorporate | applied |
| C0000IW-139 | 0000QS | g_pDirectX metadata must route through emitter UID00003Y at position 0. | High | Corrected class assembly and source order. | by-global/g_pDirectX.md emitter metadata | incorporate | applied |
| C0000IW-140 | 00003Y | DirectX class assembly must list code UID000137 as child position 1. | High | Method order after global/specializations. | by-class/DirectX.md child assembly entry for UID000137 | incorporate | applied |
| C0000IW-141 | 000137 | DirectX code metadata must route through emitter UID00003Y at position 1. | High | Exact method owner and ordered source assembly. | by-memory/0x004a1b60-0x004a1d6a.DirectX.md emitter metadata | incorporate | applied |
| C0000IW-142 | 00003Y | DirectX class assembly must list vtable-data UID0002MD as child position 2. | High | Compiler-covered marker after methods. | by-class/DirectX.md child assembly entry for UID0002MD | incorporate | applied |
| C0000IW-143 | 0002MD | DirectX vtable-data metadata must route through emitter UID00003Y at position 2. | High | Exact class source cause and marker order. | by-memory/0x00618e60-0x00618e70.DirectXVtableData.md emitter metadata | incorporate | applied |
| C0000IW-144 | 00003Y | DirectX class assembly must list diagnostic UID0003AY as child position 3. | High | Literal marker follows vtable marker. | by-class/DirectX.md child assembly entry for UID0003AY | incorporate | applied |
| C0000IW-145 | 0003AY | DirectX diagnostic metadata must route through emitter UID00003Y at position 3. | High | Exact literal source use and marker order. | by-memory/0x00618e70-0x00618efc.DirectXDiagnosticString.md emitter metadata | incorporate | applied |
| C0000IW-146 | 0000QS | The semantic g_pDirectX page should become 92/94 after exact global/specialization source and ownership repair. | Medium-high | Singleton lowering, 19 xrefs, and exact formal source. | by-global/g_pDirectX.md score metadata | incorporate | applied |
| C0000IW-147 | 000295 | The exact g_pDirectX storage page should become 92/94 after covered-by repair. | Medium-high | Exact zero bytes, 19 xrefs, and one-definition route. | by-memory/0x0067ab20-0x0067ab24.g_pDirectX.md score metadata | incorporate | applied |
| C0000IW-148 | 0003HP | The DirectXVtable semantic type page should become 92/94 after inheritance and compiler-source reconciliation. | Medium-high | Exact slots, RTTI graph, and completed declaration. | by-type/by-vtable/DirectXVtable.md score metadata | incorporate | applied |
| C0000IW-149 | 0002MD | The exact DirectX vtable-data page should become 92/94 after marker and source-cause repair. | Medium-high | Exact data, vptr stores, RTTI, and class route. | by-memory/0x00618e60-0x00618e70.DirectXVtableData.md score metadata | incorporate | applied |
| C0000IW-150 | 0000IW | IDA action I01 pure-renames function 0x004a1b60 from sub_4A1B60 to DirectX__Constructor and changes no other field. | Medium-high | Fresh literal prestate, complete frame, and 246-byte hash 645B88E4E96B0F7A412BA5096EB7DAEE18E8163AB6CEDDB5F887C83BEB70CAEE. | Supervisor Gate 2B I01 | incorporate | proposed |
| C0000IW-151 | 0000IW | IDA action I02 sets only the exact function-regular constructor comment at 0x004a1b60. | Medium-high | Empty FR prestate and protected A01 readback. | Supervisor Gate 2B I02 | incorporate | proposed |
| C0000IW-152 | 0000IW | IDA action I03 pure-renames function 0x004a1c60 from sub_4A1C60 to DirectX__Destructor and changes no other field. | Medium-high | Fresh literal prestate, complete frame, and 92-byte hash 293CE407F59B697391951ACD0FCECD5807D965C6DBCF6D9604A501FDD023D356. | Supervisor Gate 2B I03 | incorporate | proposed |
| C0000IW-153 | 0000IW | IDA action I04 sets only the exact function-regular destructor comment at 0x004a1c60. | Medium-high | Empty FR prestate and protected A02 readback. | Supervisor Gate 2B I04 | incorporate | proposed |
| C0000IW-154 | 0000IW | IDA action I05 pure-renames function 0x004a1cc0 from sub_4A1CC0 to Singleton_DirectX__Destructor and changes no other field. | Medium-high | Fresh literal prestate, complete frame, and 11-byte hash E00FE42EBA5658269EE3AC5105DC88398EDD86A2C111FA90F968B2418616D5D7. | Supervisor Gate 2B I05 | incorporate | proposed |
| C0000IW-155 | 0000IW | IDA action I06 sets only the exact function-regular Singleton-destructor comment at 0x004a1cc0. | Medium-high | Empty FR prestate and protected A03 readback. | Supervisor Gate 2B I06 | incorporate | proposed |
| C0000IW-156 | 0000IW | IDA action I07 pure-renames function 0x004a1cd0 from sub_4A1CD0 to DirectX__ScalarDeletingDestructor and changes no other field. | Medium-high | Fresh literal prestate, complete frame, and 154-byte hash 553D6FD33B5FF374442F50A2D039184431170252AE989712E5E176F9A401500D. | Supervisor Gate 2B I07 | incorporate | proposed |
| C0000IW-157 | 0000IW | IDA action I08 sets only the exact function-regular scalar-wrapper comment at 0x004a1cd0. | Medium-high | Empty FR prestate and protected A04 readback. | Supervisor Gate 2B I08 | incorporate | proposed |
| C0000IW-158 | 0000IW | IDA step I09 is a read-only public preflight that requires same-database exact-name `type_query` to remain `total:0`, rechecks A05/P05, and explicitly does not call `declare_type`; a forward-declaration parser-success record is not an observable numbered local type. | High | Gate 2B returned apparent `declare_type` success followed by immediate `type_query total:0`; installed public MCP code proves those endpoints use parser-error and numbered-ordinal criteria respectively. | Supervisor Gate 2B I09 | incorporate | proposed |
| C0000IW-159 | 0000IW | IDA action I11 sets only the exact address-repeatable g_pDirectX comment at 0x0067ab20 after the fresh data action passes exact readback. | Medium-high | Blank AP prestate plus disposable-copy A05 data readback and protected P05 state. | Supervisor Gate 2B I11 | incorporate | proposed |
| C0000IW-160 | 0000IW | IDA action I12 uses public `rename` with exact `batch.data` old/new binding `old:"stru_631570"`, `new:"IID_IDirectDraw"`, first dry-run then apply, and requires the sole result to resolve address `0x00631570` without error or alternate match. | Medium-high | Fresh literal A06 prestate, exact public data-rename schema, sole current symbol match, and 16-byte hash DC3CA51EE680125BA815CBCE6C7C0D8E82F979CD9DF015CA3EC29438487EC5D2. | Supervisor Gate 2B I12 | incorporate | proposed |
| C0000IW-161 | 0000IW | IDA action I13 sets only the exact address-repeatable IID_IDirectDraw comment at 0x00631570. | Medium-high | Empty AP prestate and protected A06 readback. | Supervisor Gate 2B I13 | incorporate | proposed |
| C0000IW-162 | 00004J | The Error class H action emits the single complete guarded Error/MyError declaration block, including inline empty virtual Error destructor and size assertions. | High | Complete-type compile requirement, layout/vtable evidence, and exact Section 22 H. | by-class/Error.md RECONSTRUCTION_H | incorporate | applied |
| C0000IW-163 | 00004J | The Error class CPP action emits only exact Error::GetErrorName returning L"Error". | High | Fresh exact 0x004a6a70-0x004a6a76 body and vtable slot. | by-class/Error.md RECONSTRUCTION_CPP | incorporate | applied |
| C0000IW-164 | 00008V | The MyError class H action remains blank because its complete declaration is owned by the coordinated UID00004J Error H block. | High | Single-header ownership and duplicate-declaration avoidance. | by-class/MyError.md RECONSTRUCTION_H disposition | not-applicable | excluded-with-reason |
| C0000IW-165 | 00008V | The MyError formatter CPP action emits only exact MyError::FormatErrorMessage for [0x004a6840,0x004a6858). | High | Fresh nine-instruction wcscpy_s wrapper and +0x04 field. | by-class/MyError.md RECONSTRUCTION_CPP formatter method | incorporate | applied |
| C0000IW-166 | 00008V | The MyError destructor CPP action emits only exact MyError::~MyError for [0x004a6860,0x004a6882). | High | Fresh ordinary destructor body, array delete, Error vtable restore, and LObject teardown. | by-class/MyError.md RECONSTRUCTION_CPP destructor method | incorporate | applied |
| C0000IW-167 | 00004J | Function [0x004a68e0,0x004a691e) is the 62-byte compiler-generated Error scalar deleting destructor caused by inline Error::~Error; it must not receive duplicate handwritten CPP. | High | Fresh 26-instruction disassembly/decompile, type, frame, one vtable route, and SHA256 E8144E5BF8ADF60BD3FE8347E1B3871E3029191871D04A6AFE3B2B4C8BF00B2F. | by-memory/0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers.md exact function row | incorporate | applied |
| C0000IW-168 | 00004J | Error scalar deleting destructor 0x004a68e0 has exactly one inbound data xref, 0x00619344 -> 0x004a68e0, from the base Error vtable destructor slot and no direct code caller. | High | Fresh complete xref query and exact vtable cell. | by-memory ErrorDestructorAndNameHelpers exact xref row | incorporate | applied |
| C0000IW-169 | 00004J | Error scalar deleting destructor instruction 0x004a68e6 stores Error::vftable 0x00619344 into the object before inherited teardown. | High | Fresh exact disassembly and data reference. | by-memory ErrorDestructorAndNameHelpers exact data-flow row | incorporate | applied |
| C0000IW-170 | 00004J | Error scalar deleting destructor callsite 0x004a68ec calls LObject_destructor 0x004f4a90. | High | Fresh exact disassembly and callee query. | by-memory ErrorDestructorAndNameHelpers exact callee row | incorporate | applied |
| C0000IW-171 | 00004J | Error scalar deleting destructor callsite 0x004a68fd conditionally calls NexusTK_operator_delete_wrapper 0x004f4ac0 when flag bit 1 is set and bit 4 is clear. | High | Fresh exact disassembly/decompile and callee query. | by-memory ErrorDestructorAndNameHelpers exact callee row | incorporate | applied |
| C0000IW-172 | 00004J | Error scalar deleting destructor callsite 0x004a690f uses _guard_check_icall_nop 0x0041b6a0 for the flag-4 sized-delete path with object size 4. | High | Fresh exact disassembly/decompile and callee query. | by-memory ErrorDestructorAndNameHelpers exact callee row | incorporate | applied |
| C0000IW-173 | 0002HO | The MyError constructor CPP action preserves the exact eight-line formal payload in Section 22; normalized UTF-8 LF with terminal newline is 222 bytes, SHA256 F3283F846DA3D69C8DF1F97FF2FE06A98B5BAF39A3CA86D1FCD553D1B09B22F5. | High | Physical current formal block plus fresh 157-byte function hash D361B3F2AF84E2EE716E34E77FEB4C493ABD0EE73AEA13CDD0EF0504E719470A. | by-memory/0x004a67a0-0x004a683d.MyErrorConstructor.md RECONSTRUCTION_CPP | already-present | applied |
| C0000IW-174 | 0002HO | The MyError constructor H action remains blank because the constructor declaration is supplied once by UID00004J Error H. | High | Current blank H and coordinated declaration ownership. | by-memory/0x004a67a0-0x004a683d.MyErrorConstructor.md RECONSTRUCTION_H disposition | not-applicable | excluded-with-reason |
| C0000IW-175 | 0000J5 | Supervisor-only manual coverage operation M09 replaces the changed UID0000J5 by-file row with the exact Section 28 text. | High | Physical current manual row at by-file/-coverage-report.md line 86. | by-file/-coverage-report.md UID0000J5 | incorporate | proposed |
| C0000IW-176 | 00004J | Supervisor-only manual coverage operation M10 replaces the changed UID00004J by-class row with the exact Section 28 text. | High | Physical current manual row at by-class/-coverage-report.md line 189. | by-class/-coverage-report.md UID00004J | incorporate | proposed |
| C0000IW-177 | 00008V | Supervisor-only manual coverage operation M11 replaces the changed UID00008V by-class row with the exact Section 28 text. | High | Physical current manual row at by-class/-coverage-report.md line 344. | by-class/-coverage-report.md UID00008V | incorporate | proposed |
| C0000IW-178 | 0000QS | The g_pDirectX formal CPP action emits only the sole zero-initialized DirectX pointer definition. | High | ODR, exact storage, and corrected semantic-global ownership. | by-global/g_pDirectX.md RECONSTRUCTION_CPP global definition | incorporate | applied |
| C0000IW-179 | 0000QS | The Singleton<DirectX> constructor-specialization CPP action emits only publication of static_cast<DirectX *>(this) to g_pDirectX. | High | RTTI PMD +4, constructor lowering, and shared Singleton policy. | by-global/g_pDirectX.md RECONSTRUCTION_CPP constructor method | incorporate | applied |
| C0000IW-180 | 0000QS | The Singleton<DirectX> destructor-specialization CPP action emits only clearing g_pDirectX to NULL. | High | Ordinary/inlined clear, exact 0x004a1cc0 unwind specialization, and shared Singleton policy. | by-global/g_pDirectX.md RECONSTRUCTION_CPP destructor method | incorporate | applied |
| C0000IW-181 | 000255 | The mixed DirectXBitmapReadOnlyData page receives only corrected DirectX Singleton/RTTI context and retains its current score, owner, and non-emitting disposition. | High | Exact mixed range plus independently verified DirectX RTTI split. | by-memory/0x00618e50-0x00618efc.DirectXBitmapReadOnlyData.md context | incorporate | applied |
| C0000IW-182 | 0001XE | The mixed DIBitmapDirectXVtables page retains its current score, owner, and DIBitmap/DirectX split with no source-emitter action. | High | Exact vtable boundaries and separate class ownership. | by-type/by-vtable/DIBitmapDirectXVtables.md no-change disposition | already-present | already-present |
| C0000IW-183 | 0000J5 | The Error file page may become 89/90 only after the exact coordinated Error.h route and generated verification; broader sibling work receives no score credit. | Medium-high | Complete DirectX-associated support closure with bounded wider-file incompleteness. | by-file/Error.md score metadata | incorporate | applied |
| C0000IW-184 | 00004J | The Error class page may become 90/92 after exact H/GetErrorName source plus checked 0x004a68e0 compiler-wrapper coverage and generated Error.h verification. | Medium-high | Exact declaration, method, layout/vtable, wrapper hash, xref, and callees. | by-class/Error.md score metadata | incorporate | applied |
| C0000IW-185 | 00008V | The MyError class page may become 91/93 after exact formatter/destructor source, constructor identity, coordinated-H route, and 0x004a6a10 no-duplicate coverage. | Medium-high | Exact three source methods, layout, vtable, and compiler-wrapper disposition. | by-class/MyError.md score metadata | incorporate | applied |
| C0000IW-186 | 0002TV | The ErrorDestructorAndNameHelpers aggregate remains 86/90: checked 0x004a68e0 closes classification but adds no handwritten source and does not justify aggregate score inflation. | High | Exact compiler-generated proof for Error and MyError scalar wrappers. | by-memory/0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers.md score metadata | already-present | applied |
| C0000IW-187 | 0000IW | IDA action I10 independently calls public `make_data` at 0x0067ab20 with full self-contained declaration `struct DirectX *g_pDirectX`, separate exact name `g_pDirectX`, and `delete_existing:false`; it is the sole type/data/name action and is not a rename. | High | Public implementation parses a full sized declaration before mutation; a pointer to an incomplete `struct DirectX` is four bytes; disposable-copy item readback produced the exact four-byte named DirectX-pointer data state while preserving bytes, blank AR/AP, and all 19 xrefs. | Supervisor Gate 2B I10 | incorporate | proposed |

## Positive Evidence Summary

- RTTI directly names `Singleton<DirectX>` at PMD `+0x4`; constructor lowering publishes the complete object from that subobject.
- Shared `Singleton<T>` and generated Crasher source establish the storage-free template plus consuming-module specialization pattern.
- Four local functions, far handlers, global, vtable, diagnostic, GUID, and RTTI reconcile with one compact source pair.
- Direct generated consumers prove a complete header is needed and make a private field implausible without invented declarations.
- DirectX's two `new MyError` paths require a complete `MyError` declaration. Fresh Error-family readback closes that dependency with the exact existing constructor, formatter, ordinary destructor, `Error::GetErrorName`, and inline-destructor source causes for compiler-generated scalar wrappers.
- Checked function `[0x004a68e0,0x004a691e)` is a 62-byte Error scalar deleting destructor with one base-vtable inbound route, no direct code caller, exact teardown/delete/guard callees, and no independent handwritten CPP body.
- RTTI plus lowering plus project precedent plus global xrefs is sufficient to supersede manual singleton source.
- Gate 2B failure is positive tool-contract evidence: `declare_type` parser success is not proof of a numbered local type, and immediate `type_query total:0` correctly exposed that distinction before any save.
- Revised I10 is publicly observable without a standalone type-library row: `make_data` accepts a full C declaration and returns address/name/type/size/ok, while immediate `inspect_items` independently reads the exact four-byte data head/range/name/type/classification. This preserves the known `DirectX *` semantics instead of degrading the global to `void *` or an IDA-generated label.

## IDA MCP Facts

- Dated read-only session/path evidence: `supervisor-canonical-clean-20260813`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. Schema-version-1 runtime attestation supplied that exact expected database/path and returned `ok:true` with no errors; current Gate 2B must re-list rather than reuse this historical session identifier.
- Functions: `0x004a1b60` size `0xf6`; `0x004a1c60` size `0x5c`; `0x004a1cc0` size `0xb`; `0x004a1cd0` size `0x9a`; successor `0x004a1d70` is unrelated.
- Far code: ctor `0x005fd710-0x005fd74f`; dtor `0x005fd754-0x005fd76a`; scalar handlers `0x005f6800-0x005f6816` and `0x005c91f2`.
- Padding: `0x004a1b5e-0x004a1b60`, `0x004a1c56-0x004a1c60`, `0x004a1cbc-0x004a1cc0`, `0x004a1ccb-0x004a1cd0`, `0x004a1d6a-0x004a1d70`.
- Global `0x0067ab20`: zero, exactly 19 xrefs; current item `[0x0067ab20,0x0067ab21)` is one byte, unnamed (`name=""`), untyped (`type=""`), undefined, `is_code:false`, and `is_data:false`. There is no live `unk_67AB20` symbol.
- Vtable `0x00618e60-0x00618e70`: COL `0x0064681c`; slots scalar deleting dtor, inherited `LObject::GetRuntimeClass`, inherited `LObject::OnChangeMessage`; stores `0x004a1bbf`, `0x004a1c88`, `0x004a1cf8`.
- Literal `0x00618e70-0x00618efc`: `DirectX not installed, or is corrupted. Please install DirectX again.`; xrefs `0x004a1bfb`, `0x004a1c31`.
- GUID `0x00631570-0x00631580`: current `stru_631570`, type `IID`, sole use `0x004a1bd8`.
- RTTI objects: COL `0x0064681c`; CHD `0x00646830`; BCA `0x00646840`; DirectX BCD `0x00646850`; existing LObject BCD `0x00640348`; Singleton BCD `0x0064686c`; Singleton CHD `0x00646888`; BCA `0x00646898`; self BCD `0x006468a0`; type descriptors `0x00675be0`, `0x00675bf8`.
- CHD count is three. Singleton PMD `{+0x4,-1,0}`; type string `.?AV?$Singleton@VDirectX@@@@`.
- Error scalar deleting destructor: `sub_4A68E0`, type `LObject *__thiscall(LObject *Block, char)`, exact range `[0x004a68e0,0x004a691e)`, 62 bytes and 26 instructions. It stores `Error::vftable` `0x00619344` at `0x004a68e6`, calls `LObject_destructor` at `0x004a68ec`, conditionally calls `NexusTK_operator_delete_wrapper` at `0x004a68fd`, and reaches `_guard_check_icall_nop` at `0x004a690f` on the flag-4 sized-delete path with object size 4. Its only inbound route is data xref `0x00619344 -> 0x004a68e0`; direct code callers are zero.
- Error scalar wrapper entry item is one-byte code; name/type are exactly as above; `AR=""`, `AP=""`, `FR=""`, `FP=""`. Complete frame rows are saved registers `+0x4`, return address `+0x8`, and `arg_0` `+0xc`; no Error IDA action is recommended.
- Exact Error scalar-wrapper bytes over `[0x004a68e0,0x004a691e)` hash to SHA256 `E8144E5BF8ADF60BD3FE8347E1B3871E3029191871D04A6AFE3B2B4C8BF00B2F`.
- Immutable A01-A08 bounded-prestate hashes are: A01 `[0x004a1b60,0x004a1c56)` 246 bytes `645B88E4E96B0F7A412BA5096EB7DAEE18E8163AB6CEDDB5F887C83BEB70CAEE`; A02 `[0x004a1c60,0x004a1cbc)` 92 bytes `293CE407F59B697391951ACD0FCECD5807D965C6DBCF6D9604A501FDD023D356`; A03 `[0x004a1cc0,0x004a1ccb)` 11 bytes `E00FE42EBA5658269EE3AC5105DC88398EDD86A2C111FA90F968B2418616D5D7`; A04 `[0x004a1cd0,0x004a1d6a)` 154 bytes `553D6FD33B5FF374442F50A2D039184431170252AE989712E5E176F9A401500D`; A05 `[0x0067ab20,0x0067ab24)` 4 bytes `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`; A06 `[0x00631570,0x00631580)` 16 bytes `DC3CA51EE680125BA815CBCE6C7C0D8E82F979CD9DF015CA3EC29438487EC5D2`; A07 `[0x00618e60,0x00618e64)` 4 bytes `B474BB52FFB7CCFC2DF90E99C09953CCF65E7E4886858CB13E8E8775584E957A`; A08 `[0x00618e70,0x00618efc)` 140 bytes `538C0281DE2C7CEFCEDC5B949737DD09ED86FD7D7D8FE8B1E8C355E652AD446B`.
- Regular/repeatable address and function comments are absent at all inspected action entities.
- Gate 2B dated attempt: fresh preflight matched A01-A08/P01-P23 and all eight hashes; transient I01-I08 passed; I09 returned apparent parser success but same-database `type_query` remained `total:0`; I10-I15 were not called. No save occurred.
- Clean recovery: the unsaved worker was discarded and `supervisor-uid0000IW-recovery-20260814` reopened the unchanged disk IDB with the original function/data names, blank action comments, absent numbered `DirectX` type, and original A05 undefined item state. This session identifier is dated evidence only and must be re-listed at the next gate.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| Source pair | UID0000IW | Whole unit | Yes | FILE | 85/88 to 92/94 | Complete CPP/H plan; C0000IW-001, C0000IW-003-C004, C0000IW-022-C023. |
| Class/layout | UID00003Y | Bases, virtual dtor, public field | Yes | UID0000IW | 85/88 to 92/94 | CPP include plus complete H; C0000IW-002-C004, C0000IW-020, C0000IW-024. |
| Class child entry: global | UID00003Y | Position 0 assembly entry | Yes | UID00003Y | n/a | One entry action; C0000IW-138. |
| Global emitter metadata | UID0000QS | Emitter UID00003Y, position 0 | Yes | UID00003Y | n/a | One metadata action; C0000IW-139. |
| Class child entry: code | UID00003Y | Position 1 assembly entry | Yes | UID00003Y | n/a | One entry action; C0000IW-140. |
| Code emitter metadata | UID000137 | Emitter UID00003Y, position 1 | Yes | UID00003Y | n/a | One metadata action; C0000IW-141. |
| Class child entry: vtable | UID00003Y | Position 2 assembly entry | Yes | UID00003Y | n/a | One entry action; C0000IW-142. |
| Vtable emitter metadata | UID0002MD | Emitter UID00003Y, position 2 | Yes | UID00003Y | n/a | One metadata action; C0000IW-143. |
| Class child entry: diagnostic | UID00003Y | Position 3 assembly entry | Yes | UID00003Y | n/a | One entry action; C0000IW-144. |
| Diagnostic emitter metadata | UID0003AY | Emitter UID00003Y, position 3 | Yes | UID00003Y | n/a | One metadata action; C0000IW-145. |
| `0x004a1b60-0x004a1c56` | UID000137 | Source constructor | Yes | UID00003Y | 88/91 to 92/94 | Emit ctor only; C0000IW-007, C0000IW-045. |
| `0x005fd710-0x005fd750` | UID000137 support | Constructor EH/unwind far range | Compiler-covered | UID000137 | n/a | No handwritten body; C0000IW-049. |
| `0x004a1c60-0x004a1cbc` | UID000137 | Source ordinary destructor | Yes | UID00003Y | 88/91 to 92/94 | Emit dtor only; C0000IW-008, C0000IW-046. |
| `0x005fd754-0x005fd76b` | UID000137 support | Destructor SEH far range | Compiler-covered | UID000137 | n/a | No handwritten body; C0000IW-050. |
| `0x004a1cc0-0x004a1ccb` | UID000137/UID0000QS | Singleton dtor specialization | Yes via global | UID0000QS | to 92/94 | Emit specialization once, no DirectX helper; C0000IW-009, C0000IW-047, C0000IW-180. |
| `0x004a1cd0-0x004a1d6a` | UID000137 | Scalar deleting wrapper | Compiler-covered | UID00003Y | to 92/94 | No handwritten body; C0000IW-010, C0000IW-048. |
| `0x005f6800-0x005f6817` | UID000137 support | Scalar-wrapper SEH far range | Compiler-covered | UID000137 | n/a | No handwritten body; C0000IW-051. |
| `0x005c91f2` | UID000137 support | Scalar-wrapper terminate far thunk | Compiler-covered | UID000137 | n/a | No handwritten body; C0000IW-052. |
| Local function cardinality | UID000137 | Exactly four modeled local functions; no fifth | No extra source | UID000137 | n/a | Preserve exact four-function model; C0000IW-053. |
| Inlined Singleton ctor specialization | UID0000QS | Publishes complete object | Source definition | UID00003Y after repair | to 92/94 | Emit one explicit constructor specialization; C0000IW-179. |
| `[0x004a1b5e,0x004a1b60)` | UID0000VN/UID000137 support | Two-byte CC predecessor boundary | No | ignored/compiler | 100/n/a | Preserve no-code; C0000IW-054. |
| `[0x004a1c56,0x004a1c60)` | UID000137 support | Ten-byte CC ctor/dtor boundary | No | ignored/compiler | 100/n/a | Preserve no-code; C0000IW-055. |
| `[0x004a1cbc,0x004a1cc0)` | UID000137 support | Four-byte CC dtor/specialization boundary | No | ignored/compiler | 100/n/a | Preserve no-code; C0000IW-056. |
| `[0x004a1ccb,0x004a1cd0)` | UID000137 support | Five-byte CC specialization/wrapper boundary | No | ignored/compiler | 100/n/a | Preserve no-code; C0000IW-057. |
| `[0x004a1d6a,0x004a1d70)` | UID000137 support | Six-byte CC successor boundary | No | ignored/compiler | 100/n/a | Preserve no-code; C0000IW-058. |
| `0x0067ab20-0x0067ab24` | UID000295 | Exact global storage | Covered | UID0000QS | 90/92 to 92/94 | Covered-by marker and independent score action; C0000IW-006, C0000IW-147. |
| Semantic `g_pDirectX` definition | UID0000QS | Sole zero-initialized definition | Yes | UID00003Y after repair | 90/90 to 92/94 | Independent CPP action; C0000IW-178. |
| Semantic `g_pDirectX` constructor specialization | UID0000QS | Publication method | Yes | UID00003Y after repair | 90/90 to 92/94 | Independent CPP action; C0000IW-179. |
| Semantic `g_pDirectX` destructor specialization | UID0000QS | Clear method | Yes | UID00003Y after repair | 90/90 to 92/94 | Independent CPP action; C0000IW-180. |
| Semantic `g_pDirectX` score | UID0000QS | Page metadata | n/a | UID00003Y after repair | 90/90 to 92/94 | Independent score action; C0000IW-146. |
| `0x00618e60-0x00618e70` | UID0002MD | COL pointer and vtable | Compiler-covered | UID00003Y | 87/93 to 92/94 | Marker and independent score action; C0000IW-011, C0000IW-149. |
| DirectX virtual layout | UID0003HP | Semantic vtable type | Compiler-covered | UID00003Y | 88/93 to 92/94 | CPP/H blank and independent score action; C0000IW-011, C0000IW-148. |
| `0x00618e70-0x00618efc` | UID0003AY | Failure literal | Source-literal-covered | UID00003Y after route repair | 85/91 to 92/94 | Covered-by marker at child 3; C0000IW-012, C0000IW-028. |
| `0x00631570-0x00631580` | UID0003OG | SDK IID | External | NONE | 88/91 unchanged | Use SDK declaration; C0000IW-013. |
| `0x0064681c-0x00646830` | mixed RTTI support | DirectX COL | Compiler-generated | UID00003Y cause | n/a | No source object; C0000IW-035. |
| `0x00646830-0x00646840` | mixed RTTI support | DirectX CHD | Compiler-generated | UID00003Y cause | n/a | Three-base proof; C0000IW-036. |
| `0x00646840-0x00646850` | mixed RTTI support | DirectX BCA | Compiler-generated | UID00003Y cause | n/a | DirectX/LObject/Singleton entries; C0000IW-037. |
| `0x00646850-0x0064686c` | mixed RTTI support | DirectX self BCD | Compiler-generated | UID00003Y cause | n/a | PMD `0,-1,0`; C0000IW-038. |
| `0x0064686c-0x00646888` | mixed RTTI support | Singleton base BCD | Compiler-generated | UID00003Y cause | n/a | PMD `+4,-1,0`; C0000IW-039. |
| `0x00646888-0x00646898` | mixed RTTI support | Singleton CHD | Compiler-generated | class/template cause | n/a | No code; C0000IW-040. |
| `0x00646898-0x006468a0` | mixed RTTI support | Singleton BCA | Compiler-generated | class/template cause | n/a | No code; C0000IW-041. |
| `0x006468a0-0x006468bc` | mixed RTTI support | Singleton self BCD | Compiler-generated | class/template cause | n/a | No code; C0000IW-042. |
| `0x00675be0-0x00675bf8` | mixed RTTI support | DirectX type descriptor | Compiler-generated | UID00003Y cause | n/a | Exact string; C0000IW-043. |
| `0x00675bf8-0x00675c20` | mixed RTTI support | Singleton type descriptor | Compiler-generated | class/template cause | n/a | Exact string; C0000IW-044. |
| DirectDrawCreate IAT `0x0060d024` | DDRAW | Bootstrap API | External | external | n/a | Include ddraw; C0000IW-018. |
| QueryInterface/Release indirect slots | COM | Acquire/release | External | external | n/a | Preserve calls; C0000IW-018. |
| LObject ctor/dtor `0x004f4a80`/`0x004f4a90` | LObject support | Primary base | Dependency | class declaration | n/a | Include LObject.h; C0000IW-002. |
| Shared `Singleton<T>` | UID0004ZK/0004ZL | Empty protected template | Dependency | util/Singleton.h | 90/92, 92/94 | Include, do not duplicate; C0000IW-002, C0000IW-179-C0000IW-180. |
| DirectX Error include | UID0000IW | Include complete `../util/Error.h` | Source dependency | UID0000IW | 92/94 scoped | One DirectX source action; C0000IW-019. |
| Error file support | UID0000J5 | Required generated `NexusTK/util/Error.h` route | Associated support | util/Error | 88/87 to 89/90 | One file-support action; C0000IW-120. |
| Error H | UID00004J | Single guarded Error/MyError declaration | Source | UID0000J5 | 86/89 to 90/92 | Independent H action; C0000IW-162. |
| `0x004a6a70-0x004a6a76` | UID00004J | `Error::GetErrorName` | Source | UID0000J5 | scoped | Independent CPP method and memory fact; C0000IW-125, C0000IW-163. |
| `[0x004a68e0,0x004a691e)` | UID00004J | Error scalar deleting destructor | Compiler-covered | inline `Error::~Error()` | scoped | Exact no-duplicate-CPP disposition; C0000IW-167. |
| `0x00619344 -> 0x004a68e0` | UID00004J | Sole Error-wrapper inbound route; no direct caller | Compiler-covered | Error vtable | scoped | One xref fact; C0000IW-168. |
| `0x004a68e6` | UID00004J | Error vtable restore | Compiler-covered | Error scalar wrapper | scoped | One data-flow fact; C0000IW-169. |
| `0x004a68ec` | UID00004J | LObject teardown call | Compiler-covered | Error scalar wrapper | scoped | One callee fact; C0000IW-170. |
| `0x004a68fd` | UID00004J | Conditional operator-delete call | Compiler-covered | Error scalar wrapper | scoped | One callee fact; C0000IW-171. |
| `0x004a690f` | UID00004J | Flag-4 guard/sized-delete path | Compiler-covered | Error scalar wrapper | scoped | One callee fact; C0000IW-172. |
| MyError H | UID00008V | Blank; declaration supplied by Error H | No duplicate source | UID00004J | scoped | Independent H disposition; C0000IW-164. |
| `0x004a6840-0x004a6858` | UID00008V | `MyError::FormatErrorMessage` | Source | UID0000J5 | 87/90 to 91/93 | Independent CPP method; C0000IW-123, C0000IW-165. |
| `0x004a6860-0x004a6882` | UID00008V | `MyError::~MyError` | Source | UID0000J5 | 87/90 to 91/93 | Independent CPP method; C0000IW-124, C0000IW-166. |
| `[0x004a67a0,0x004a683d)` | UID0002HO | `MyError::MyError` | Existing exact source | UID0000J5 | 90/92 unchanged | Exact CPP payload identity; C0000IW-173. |
| MyError constructor H | UID0002HO | Blank; declaration supplied by Error H | No duplicate source | UID00004J | 90/92 unchanged | Independent H disposition; C0000IW-174. |
| `0x004a6a10` | UID0002TV | MyError scalar deleting destructor | Compiler-covered | `MyError::~MyError()` | unchanged | No duplicate CPP; C0000IW-128. |
| Error/MyError vtable data | UID0002ND | Five-slot raw tables | Compiler-covered | completed declarations | unchanged | Marker-only source cause; C0000IW-129. |
| Error/MyError layouts | UID0001UE | 0x4/0x8 and field +0x04 | Declaration evidence | Error H | unchanged | Exact type disposition; C0000IW-130. |
| Error/MyError semantic vtables | UID0001XI | Five-slot order | Declaration evidence | Error H | unchanged | Exact type disposition; C0000IW-131. |
| `operator new`/throw helpers | runtime | Allocation/dispatch | External | runtime | n/a | Source `new`/`throw`, no bodies; C0000IW-065, C0000IW-132-C0000IW-137. |
| `0x004a1b10-0x004a1b5e` | DIBitmap family | Predecessor | Excluded | DIBitmap | n/a | Boundary only; C0000IW-032. |
| `0x004a1d70...` | EmployeeDialog family | Successor | Excluded | EmployeeDialog | n/a | Boundary only; C0000IW-032. |
| Application startup/shutdown | Application docs | Allocate/delete | Consumer policy | Application | n/a | Not DirectX-owned; C0000IW-032. |
| Surface/GrafPort/ScreenPane | consumer docs | Read global/public field | Consumers | own files | n/a | Access evidence only; C0000IW-020, C0000IW-032. |
| Mixed `.rdata` UID000255 | container | DIBitmap/vtable/literal | Non-emitting | NONE | 86/91 | Correct context, keep non-owner; C0000IW-181. |
| Mixed vtable UID0001XE | type index | DIBitmap/DirectX split | Non-emitting | NONE | 89/93 | Keep split with no action; C0000IW-182. |

Totals: eight independently allocated DirectX class-entry/emitter actions, five DirectX source definition/method actions, four local functions, four separately recorded far ranges/thunks, five individually recorded padding spans, fourteen exact DirectX data/RTTI objects plus external GUID, two adjacent exclusions, three consumer families, and the complete six-function Error/MyError source-or-compiler family. Every row cites active ledger/checklist authority; retired grouped rows carry no content authority.

## Direct Xref / Caller Inventory

| Claim | Exact source -> target | Meaning / disposition |
| --- | --- | --- |
| C0000IW-059 | `0x004645aa -> 0x004a1b60` | Sole constructor caller. |
| C0000IW-060 | `0x004a1b8c -> 0x004f4a80` | LObject constructor callee. |
| C0000IW-061 | `0x004a1bcb -> 0x005c5c87` / IAT `0x0060d024` | DirectDrawCreate callee/import. |
| C0000IW-062 | `0x004a1be0 -> [IDirectDraw+0x00]` | QueryInterface indirect callee. |
| C0000IW-065 | `0x004a1c51 -> 0x005ca20a` | Shared converged throw helper call. |
| C0000IW-066 | `0x005fd713 -> 0x004f4a90` | Constructor far LObject cleanup. |
| C0000IW-067 | `0x005fd71e -> 0x004a1cc0` | Constructor far Singleton cleanup. |
| C0000IW-132 | `0x004a1be8 -> 0x004f4aa0` | QueryInterface-failure 8-byte MyError allocation call. |
| C0000IW-133 | `0x004a1c1e -> 0x004f4aa0` | DirectDrawCreate-failure 8-byte MyError allocation call. |
| C0000IW-134 | `0x004a1c02 -> 0x004a67a0` | QueryInterface-failure MyError constructor call. |
| C0000IW-135 | `0x004a1c38 -> 0x004a67a0` | DirectDrawCreate-failure MyError constructor call. |
| C0000IW-136 | `0x005fd727 -> 0x004f4ac0` | QueryInterface-failure allocation cleanup call. |
| C0000IW-137 | `0x005fd732 -> 0x004f4ac0` | DirectDrawCreate-failure allocation cleanup call. |
| C0000IW-069 | `0x004a1c91 -> [IDirectDraw+0x08]` | Ordinary destructor Release. |
| C0000IW-070 | `0x004a1ca7 -> 0x004f4a90` | Ordinary destructor base teardown. |
| C0000IW-071 | no inbound code xref to `0x004a1c60`; virtual slot route | Ordinary destructor virtual liveness. |
| C0000IW-072 | `0x005fd71e -> 0x004a1cc0` | Sole Singleton destructor-specialization caller. |
| C0000IW-073 | `0x00618e64 -> 0x004a1cd0` | Scalar wrapper vtable-only inbound route. |
| C0000IW-074 | `0x004a1d08 -> [IDirectDraw+0x08]` | Scalar wrapper Release. |
| C0000IW-075 | `0x004a1d1e -> 0x004f4a90` | Scalar wrapper base teardown. |
| C0000IW-076 | `0x004a1d2f -> 0x004f4ac0` | Scalar wrapper optional delete. |
| C0000IW-077 | `0x004a1d4e -> 0x0041b6a0` | Scalar wrapper flag-4 guard path. |
| C0000IW-078 | `0x005c91f2 -> 0x005dce60` | Scalar wrapper terminate far thunk. |
| C0000IW-079 | `0x00464b44 -> 0x0067ab20` | Application shutdown read. |
| C0000IW-080 | `0x004a1ba2 -> 0x0067ab20` | Complete-object publication write. |
| C0000IW-081 | `0x004a1ba9 -> 0x0067ab20` | Null-adjustment publication write. |
| C0000IW-082 | `0x004a1c9d -> 0x0067ab20` | Ordinary destruction clear. |
| C0000IW-083 | `0x004a1cc0 -> 0x0067ab20` | Out-of-line Singleton clear. |
| C0000IW-084 | `0x004a1d14 -> 0x0067ab20` | Scalar-deletion clear. |
| C0000IW-085 | `0x004b8d78 -> 0x0067ab20` | Independent render/UI consumer read. |
| C0000IW-086 | `0x004b92bc -> 0x0067ab20` | Independent render/UI consumer read. |
| C0000IW-087 | `0x004b9800 -> 0x0067ab20` | Independent render/UI consumer read. |
| C0000IW-088 | `0x004bb83f -> 0x0067ab20` | Independent render/UI consumer read. |
| C0000IW-089 | `0x00556b22 -> 0x0067ab20` | Independent ScreenPane destructor read. |
| C0000IW-090 | `0x00556b77 -> 0x0067ab20` | Second independent ScreenPane destructor read. |
| C0000IW-091 | `0x005574a0 -> 0x0067ab20` | Independent Surface/GrafPort-family read. |
| C0000IW-092 | `0x005576d0 -> 0x0067ab20` | Independent Surface/GrafPort-family read. |
| C0000IW-093 | `0x005583d0 -> 0x0067ab20` | Independent DirectDraw consumer read. |
| C0000IW-094 | `0x005586a3 -> 0x0067ab20` | InitializeSurfaceRenderCallbacks read. |
| C0000IW-095 | `0x00558875 -> 0x0067ab20` | Independent DirectDraw consumer read. |
| C0000IW-096 | `0x00558b24 -> 0x0067ab20` | Second read in the 0x00558840 consumer. |
| C0000IW-097 | `0x00559a63 -> 0x0067ab20` | Final exact DirectDraw consumer read. |
| C0000IW-098 | `0x004a1bbf -> 0x00618e64` | Constructor vptr store. |
| C0000IW-099 | `0x004a1c88 -> 0x00618e64` | Ordinary destructor vptr store. |
| C0000IW-100 | `0x004a1cf8 -> 0x00618e64` | Scalar wrapper vptr store. |
| C0000IW-101 | `0x004a1bfb -> 0x00618e70` | QueryInterface-failure literal xref. |
| C0000IW-102 | `0x004a1c31 -> 0x00618e70` | DirectDrawCreate-failure literal xref. |
| C0000IW-103 | `0x004a1bd8 -> 0x00631570` | Sole IID_IDirectDraw xref. |
| C0000IW-168 | `0x00619344 -> 0x004a68e0`; direct code callers `0` | Sole Error scalar-wrapper inbound vtable route and explicit no-code-caller disposition. |
| C0000IW-169 | `0x004a68e6 -> 0x00619344` | Error scalar wrapper restores the base Error vtable. |
| C0000IW-170 | `0x004a68ec -> 0x004f4a90` | Error scalar wrapper calls `LObject_destructor`. |
| C0000IW-171 | `0x004a68fd -> 0x004f4ac0` | Error scalar wrapper conditionally calls the operator-delete wrapper. |
| C0000IW-172 | `0x004a690f -> 0x0041b6a0` | Error scalar wrapper flag-4 sized-delete path calls the guard helper. |

The complete global query returned exactly the nineteen independently listed C0000IW-079 through C0000IW-097 rows with no continuation. Constructor and far-cleanup calls are split to one claim per exact callsite, including C0000IW-132 through C0000IW-137; retired C0000IW-063, C0000IW-064, and C0000IW-068 have no grouped authority. RTTI direct links remain one-to-one under C0000IW-035 through C0000IW-044. The checked Error wrapper likewise has one claim per independently relevant inbound/data/callee route under C0000IW-168 through C0000IW-172; no all-xrefs aggregate claim remains authoritative.

## Documentation Evidence And IDA Status

- Supporting: file placement/role; exact code/global/vtable/literal/GUID ranges; Application lifecycle; consumer boundaries; storage-free Singleton; Crasher specialization precedent.
- Stale: Singleton base/source cause omitted; class CPP/H split wrong; manual writes; physical-child definition; empty vtable marker; stale manual rows; missing diagnostic row.
- Generated: command `000000023186` incomplete; DirectX.h absent; no generated edit performed.
- Generated callback readback: command `000000023312`, refreshed `2026-08-14T03:11:59-04:00`, contains ordered DirectX UIDs `00003Y,0000QS,000295,000137,0002MD,0003AY,0003HP` and ordered Error UIDs `00004J,00008V,0002HO`. Final artifacts are `DirectX.cpp` 2091 bytes/57 lines/SHA256 `1BB62A6F09563DCB00104D6BCC99BF39073105FA0F87E5ACFDD142E452846CAF`, `DirectX.h` 775/29/`96D9A9B616069670488EDF1665F9C2C1DEC24A31644B948592EA22FFC27BF377`, `Error.cpp` 9393/94/`7DBAEBC578B08133E06271824D499F8CB0AA96890334A548C2A11E3782234B2F`, and `Error.h` 1106/46/`8DC7B65CDF603A3654BAB281324CFBE510154F1BED3F02AD8BE2B675B049EA9E`.
- IDA function names remain `sub_4A1B60`, `sub_4A1C60`, `sub_4A1CC0`, and `sub_4A1CD0`; A05 at `0x0067ab20` is unnamed; A06 remains `stru_631570`; A07 is unnamed; A08 remains `aDi`. Every action-relevant AR/AP/FR/FP comment channel is blank in fresh preflight.
- Error support prestate: generated `NexusTK/util/Error.h` is absent; UID0002HO has an exact constructor CPP and blank H; Error/MyError class routes are incomplete. Fresh read-only IDA closes `0x004a67a0`, `0x004a6840`, `0x004a6860`, `0x004a68e0`, `0x004a6a10`, and `0x004a6a70` to exact source or compiler-only dispositions.
- Error support callback result: the absent-header statement is retained as command-`000000023186` prestate. Generated `NexusTK/util/Error.h` now matches UID00004J H exactly, and generated `Error.cpp` contains exact UID00004J, UID00008V, and UID0002HO CPP payloads; `0x004a68e0` and `0x004a6a10` remain compiler-covered with no duplicate bodies.
- Historical reports retain reverified bounds/xrefs only; source-cause conclusions are explicitly superseded.
- IDA Gate 2B documentation status: ordinary by-* and generated source remain valid and unchanged. The failed unsaved I09 attempt changes only the supervisor handoff: standalone opaque-type declaration/readback is rejected, `type_query total:0` is expected, and the DirectX-pointer type is carried by I10's full data declaration with item-level public readback.

## Ranked Ownership Analysis

### 1. DirectX file/class route
- Evidence for: RTTI, methods, global publication, vtable, literal, GUID use, startup/shutdown, consumers.
- Evidence against: original filenames/text not retained.
- Decision: accepted `NexusTK/render/DirectX.cpp` plus H.

### 2. Shared Singleton/global as top owner
- Evidence for: lifecycle pattern and global definition.
- Evidence against: template has no DirectX storage; global is module child.
- Decision: dependency/child only; global routes through class for order.

### 3. Application or render consumers
- Evidence for: allocation/deletion and field reads.
- Evidence against: no DirectX vtable or interface lifetime ownership.
- Decision: rejected owners.

### 4. Error/MyError associated support route
- Evidence for: DirectX allocates and constructs `MyError`; UID0002HO already owns the constructor source; fresh Error-family functions, layouts, vtables, and exact call routes identify the remaining declaration/method source.
- Evidence against competing ownership: DirectX does not own Error implementation, UID00013X is an aggregate evidence page rather than a source owner, and compiler scalar wrappers do not justify separate hand-authored bodies.
- Decision: accepted under the existing `NexusTK/util/Error.cpp` plus `Error.h` route. UID00004J owns the single coordinated H and `Error::GetErrorName`; UID00008V owns formatter/destructor CPP; UID0002HO retains constructor CPP; `0x004a68e0` and `0x004a6a10` are compiler-generated from inline/ordinary destructors and emit no duplicate CPP.

### Proposed new file/grouping, if applicable
- No new module. Add required sibling DirectX.h under existing root.
- Full contents: guarded class declaration/includes/extern/size assertion; CPP H/Error includes, global/specializations, two methods.
- Reject adjacent code, consumer bodies, moving Error implementation into DirectX, Singleton primary template, and SDK bodies.
- Narrow one-class wrapper module.

## Source Placement

- `NexusTK/render/DirectX.cpp` and `.h`; util LObject/Singleton/Error and ddraw remain dependencies.
- Fits current tree and render wrapper responsibility.
- Reject Application, Surface, GrafPort, ScreenPane, util, and mixed data containers as source owners.
- Associated support remains at `NexusTK/util/Error.cpp` plus `NexusTK/util/Error.h`: UID00004J H owns both declarations and inline empty `Error::~Error()`; UID00004J CPP owns only `Error::GetErrorName`; UID00008V CPP owns formatter and ordinary destructor; UID0002HO CPP retains the exact constructor. Compiler-generated `[0x004a68e0,0x004a691e)` and `0x004a6a10` receive no separate source bodies.
- Implementation readback confirms both placements without duplication. The generated render and util source pairs contain the exact formal payloads at their declared child positions, while the SDK GUID, mixed containers, scalar wrappers, RTTI, vtables, and padding remain external, non-emitting, or compiler-generated as dispositioned.
- Only normalized include/guard text remains uncertain.

## Range / Split / Padding / Reclassification Analysis

- Exact half-open local range `0x004a1b60-0x004a1d6a`, with four modeled functions under C0000IW-045-C048 and no fifth under C0000IW-053.
- C0000IW-054: `[0x004a1b5e,0x004a1b60)`, two CC bytes, predecessor/constructor boundary.
- C0000IW-055: `[0x004a1c56,0x004a1c60)`, ten CC bytes, constructor/destructor boundary.
- C0000IW-056: `[0x004a1cbc,0x004a1cc0)`, four CC bytes, destructor/Singleton-specialization boundary.
- C0000IW-057: `[0x004a1ccb,0x004a1cd0)`, five CC bytes, Singleton-specialization/scalar-wrapper boundary.
- C0000IW-058: `[0x004a1d6a,0x004a1d70)`, six CC bytes, scalar-wrapper/EmployeeDialog boundary.
- UID000137 may remain aggregate because every local item now has source/compiler disposition.
- Reclassify `0x004a1cc0` from pure helper to source Singleton dtor specialization body used by compiler unwind; never emit as DirectX method.
- UID000295 becomes covered storage; UID0000QS owns definition.
- UID0002MD/UID0003AY emit explanatory markers. The ten RTTI objects remain individually no-code under C0000IW-035-C044 and need no new children.
- Error scalar wrapper `[0x004a68e0,0x004a691e)` is separately bounded and compiler-covered by the inline empty virtual `Error::~Error()` in UID00004J H; its SHA256 is `E8144E5BF8ADF60BD3FE8347E1B3871E3029191871D04A6AFE3B2B4C8BF00B2F`, and no handwritten CPP range is allocated.
- UID000255/UID0001XE remain mixed non-owners; DIBitmap/EmployeeDialog remain outside.

## Negative Evidence Summary

- No fifth function, direct ordinary-dtor caller, separate Singleton ctor function, getter, friend family, generic Singleton cell, resource, source-owned GUID, or valid headerless route.
- No PDB proves exact access/guard/token spelling.
- Literal has no independent address-taking behavior.
- Adjacent code/data and consumer reads do not prove ownership.
- Existing CPP does not prove completeness; absent H and empty marker disprove it.
- `0x004a68e0` does not justify a handwritten Error destructor-wrapper CPP: vtable-only liveness, flag-controlled delete/guard lowering, and the inline empty virtual destructor are complete compiler-source proof.
- Public `declare_type` success does not prove installation of `struct DirectX;`: the endpoint reports zero parser errors, whereas `type_query` sees only numbered local types. The observed `total:0` after apparent success rejects the old I09 contract.
- A standalone numbered DirectX UDT is unnecessary for A05 and would add unsupported state. A full `struct DirectX *g_pDirectX` declaration is sized through its pointer, keeps source-quality semantics, and can be verified at the data item; `void *`, raw `dword`, destructive item replacement, and retrying the nonexistent `unk_67AB20` rename are rejected.

## IDA Rename / Type / Comment Recommendations

This is a declarative Gate 2B handoff, not a transaction program. `AR` is address regular, `AP` address repeatable, `FR` function regular, and `FP` function repeatable. Literal empty channels are written as `""`; data entities have `FR/FP=N/A`. Agent-B004 performed no IDA mutation.

Transaction-wide order and fail-closed rules:

- Before A01, the supervisor must re-list sessions, require the active canonical session whose `input_path` is exactly `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, require current disk hash/size, `server_health.status:ok`, Hex-Rays readiness, and fresh schema-1 runtime attestation `ok:true` with no errors. Recovery session `supervisor-uid0000IW-recovery-20260814` is dated clean-recovery evidence only; Gate 2B must use the freshly re-listed active canonical session ID in every public endpoint's `database` field and must not bind a rollback/probe/stale session. Reproduce every A01-A08 and P01-P23 prestate exactly and create a verified collision-safe backup.
- Destination names `DirectX__Constructor`, `DirectX__Destructor`, `Singleton_DirectX__Destructor`, `DirectX__ScalarDeletingDestructor`, `g_pDirectX`, and `IID_IDirectDraw` were absent in fresh preflight. Recheck before each action; any address other than the row target is a collision and stops with no overwrite, suffix, or save. Exact-name `type_query` for `^DirectX$` must return `total:0` immediately before I09 and again as part of I09. That zero-row result is expected because public `type_query` enumerates numbered local types only; it is not permission to call `declare_type`. Any nonzero result, omitted field, database mismatch, or incompatible preexisting item/type is a collision/parser stop.
- Function renames use public `rename.batch.func` with each exact function `addr`/`name`, first `dry_run:true` and then `dry_run:false`, while retaining the active canonical `database`, `pure:true`, `allow_overwrite:false`, and `stop_on_error:true`. A06/I12 is not a function-style address/name request: it uses public `rename.batch.data` with exact `old:"stru_631570"` and `new:"IID_IDirectDraw"`, first `dry_run:true` and then `dry_run:false`, with the same database and safety flags; both responses must resolve only `0x00631570`. A05 is explicitly excluded from rename and standalone type declaration: I09 is read-only and must not call `declare_type`; I10 uses public `make_data` with exact full declaration `struct DirectX *g_pDirectX`, separate name `g_pDirectX`, and `delete_existing:false`; I11 independently adds AP. Function comments use `set_function_comments`; AP-only comments use `set_address_repeatable_comments`. No other type, stack/local, make-data, undefine, function-creation, UDT, patch, or ordinary-address-comment action is authorized.
- The supervisor's disposable-copy pure-rename dry-run from `unk_67AB20` to `g_pDirectX` failed because the old symbol does not exist. That failed route is negative evidence and must not be retried, substituted, or treated as an optional fallback for I09/I10.
- A01-A08 are immutable entity-prestate/protection records, not grouped mutation actions. Execute ordered I01 through I15, recognizing I09 as a read-only preflight and the other fourteen rows as mutations. Each I row depends on the transaction prerequisites and exact successful readback of every lower-numbered I row; after every mutation repeat the complete corresponding A/P readback.
- A current type mismatch is a parser/type stop. I09 authorizes no mutation and explicitly prohibits `declare_type`; I10 is the sole authorized A05 item/type/name action and does not permit destructive replacement of an incompatible existing item. Public `make_data` must parse the self-contained pointer declaration and return one successful result, then public `inspect_items` must prove the exact item-level state. `type_query` may and is expected to remain `total:0` because an attached incomplete-tag pointer need not create a numbered local-library type; do not use that catalog as I10 item-type readback. Any endpoint parse rejection, result-count/error/type/readback mismatch, collision, item/range/width drift, unexpected AR/AP/FR/FP text, frame/local delta, xref delta, byte delta, or readback omission stops all later actions. B004 performed and authorizes no IDA save; the supervisor may perform exactly one save only after all mutation/readback gates pass, followed by separate verifier readback and documented rollback if needed.
- Only after I01-I15 and P01-P23 all pass may the supervisor perform one save, open a separate verifier, and repeat complete readback. Every A01-A08 bounded byte range/count/SHA256 must read back unchanged before save and in the separate verifier. A post-save mismatch uses the supervisor's verified-backup guarded rollback procedure; it never authorizes in-place repair or a second save. The B agent never saves or rolls back IDA.

Eight exact entity-prestate and protection rows:

| ID / claim | Exact address, head/range/width, and literal prestate | Ordered action and dependencies | Exact expected readback and local stop condition |
| --- | --- | --- | --- |
| A01 | Function `[0x004a1b60,0x004a1c56)`, width/count 246; entry item `[0x004a1b60,0x004a1b61)`, width 1, code; name `sub_4A1B60`; live type `char *__thiscall(char *this)`; `AR=""`, `AP=""`, `FR=""`, `FP=""`; frame F01; inbound C0000IW-059; SHA256 `645B88E4E96B0F7A412BA5096EB7DAEE18E8163AB6CEDDB5F887C83BEB70CAEE`. | Mutations are independently allocated to I01/C0000IW-150 and I02/C0000IW-151; A01 itself authorizes none. | Name/FR become only the I01/I02 values. Range/count/head/width/code/type/frame/xrefs/AR/AP/FP remain exact, and the same 246-byte SHA256 must read back unchanged. Any omission or drift stops. |
| A02 | Function `[0x004a1c60,0x004a1cbc)`, width/count 92; entry item `[0x004a1c60,0x004a1c61)`, width 1, code; name `sub_4A1C60`; live type `int __thiscall(_DWORD *this)`; `AR=""`, `AP=""`, `FR=""`, `FP=""`; frame F02; no inbound code xref; SHA256 `293CE407F59B697391951ACD0FCECD5807D965C6DBCF6D9604A501FDD023D356`. | Mutations are independently allocated to I03/C0000IW-152 and I04/C0000IW-153. | Name/FR become only the I03/I04 values. All other listed state remains exact, and the same 92-byte SHA256 must read back unchanged. Any omission or drift stops. |
| A03 | Function `[0x004a1cc0,0x004a1ccb)`, width/count 11; first item `[0x004a1cc0,0x004a1cca)`, width 10, code, followed by `retn`; name `sub_4A1CC0`; type `void()`; `AR=""`, `AP=""`, `FR=""`, `FP=""`; frame F03; inbound C0000IW-072; SHA256 `E00FE42EBA5658269EE3AC5105DC88398EDD86A2C111FA90F968B2418616D5D7`. | Mutations are independently allocated to I05/C0000IW-154 and I06/C0000IW-155. | Name/FR become only the I05/I06 values. All other listed state remains exact, and the same 11-byte SHA256 must read back unchanged. Any omission or drift stops. |
| A04 | Function `[0x004a1cd0,0x004a1d6a)`, width/count 154; entry item `[0x004a1cd0,0x004a1cd1)`, width 1, code; name `sub_4A1CD0`; live type `_DWORD *__thiscall(_DWORD *Block, char)`; `AR=""`, `AP=""`, `FR=""`, `FP=""`; frame F04; inbound C0000IW-073; SHA256 `553D6FD33B5FF374442F50A2D039184431170252AE989712E5E176F9A401500D`. | Mutations are independently allocated to I07/C0000IW-156 and I08/C0000IW-157. | Name/FR become only the I07/I08 values. All other listed state remains exact, and the same 154-byte SHA256 must read back unchanged. Any omission or drift stops. |
| A05 | Current undefined item `[0x0067ab20,0x0067ab21)`, width 1; semantic storage `[0x0067ab20,0x0067ab24)`, width/count 4; name `""`; type `""`; `is_code:false`, `is_data:false`; `AR=""`, `AP=""`, `FR/FP=N/A`; frame/stack N/A; xrefs C0000IW-079-C097; SHA256 `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`. There is no live `unk_67AB20`. Active canonical exact `type_query` prestate for `^DirectX$` is zero records. | I09/C0000IW-158 repeats the read-only same-database zero-row type and exact A05/P05 preflight without calling `declare_type`; I10/C0000IW-187 performs the sole self-contained fresh four-byte data/type/name action; I11/C0000IW-159 independently adds AP. | After I09, `type_query total:0` and all A05/P05 address/item state remain unchanged. After I10, public `make_data` and immediate `inspect_items` must prove item `[0x0067ab20,0x0067ab24)`, size 4, name `g_pDirectX`, a canonical pointer-to-DirectX type string (`DirectX *` or `struct DirectX *` after whitespace normalization), `is_code:false`, `is_data:true`, `AR=""`, `AP=""`, all 19 xrefs preserved, and the same SHA256. After I11 only AP changes. Any parser/result/readback rejection, existing-item deletion, width/name/type/classification/comment/xref/byte mismatch, `void *`/raw-integer fallback, or omitted field stops. |
| A06 | Data item `[0x00631570,0x00631580)`, width/count 16; name `stru_631570`; type `IID`; `AR=""`, `AP=""`, `FR/FP=N/A`; frame/stack N/A; sole inbound C0000IW-103; SHA256 `DC3CA51EE680125BA815CBCE6C7C0D8E82F979CD9DF015CA3EC29438487EC5D2`. | I12/C0000IW-160 independently uses public `rename.batch.data` with `old:"stru_631570"` and `new:"IID_IDirectDraw"`, dry-run then apply; I13/C0000IW-161 independently adds AP only after I12 exact applied readback. | I12 dry-run and apply each return exactly one no-error data result identifying address `0x00631570`, with no alternate match; after apply only the name is `IID_IDirectDraw`. I13 then changes only AP. Item type `IID`, exact range/count, sole xref, AR, bytes, and the same 16-byte SHA256 remain unchanged throughout. Any result-count/address/old/new/error/alternate-match or protected-state drift stops. |
| A07 | Data cell `[0x00618e60,0x00618e64)`, width/count 4; name `""`; type `""`; `is_data:true`; `AR=""`, `AP=""`, `FR/FP=N/A`; frame/stack N/A; outbound C0000IW-035 and no inbound xref; SHA256 `B474BB52FFB7CCFC2DF90E99C09953CCF65E7E4886858CB13E8E8775584E957A`. | Sole mutation is I14/C0000IW-110. | Only AP becomes the I14 value. All other listed state remains exact, and the same 4-byte SHA256 must read back unchanged. Any drift stops. |
| A08 | Current item `[0x00618e70,0x00618e74)`, width 4, inside logical literal `[0x00618e70,0x00618efc)`, width/count 140; name `aDi`; type `const wchar_t`; `AR=""`, `AP=""`, `FR/FP=N/A`; frame/stack N/A; inbound C0000IW-101-C102; SHA256 `538C0281DE2C7CEFCEDC5B949737DD09ED86FD7D7D8FE8B1E8C355E652AD446B`. | Sole mutation is I15/C0000IW-111. | Only AP becomes the I15 value. Split head/name/type/range/count/xrefs/AR/terminator/successor remain exact, and the same 140-byte SHA256 must read back unchanged. Any rebuild/merge/drift stops. |

Atomic ordered Gate 2B rows:

| ID / claim | Exact mutation | Dependency | Exact expected readback |
| --- | --- | --- | --- |
| I01 / C0000IW-150 | Pure rename `0x004a1b60`: `sub_4A1B60` -> `DirectX__Constructor`. | Transaction prerequisites and A01/P01 prestate. | Only name changes; A01/P01, including SHA256, otherwise exact. |
| I02 / C0000IW-151 | Set FR at `0x004a1b60` exactly `Constructs DirectX, invokes the Singleton<DirectX> publication path, creates DirectDraw, and queries IID_IDirectDraw into m_pDirectDraw.` | I01 exact readback. | Only FR changes in addition to I01 name; A01/P01 otherwise exact. |
| I03 / C0000IW-152 | Pure rename `0x004a1c60`: `sub_4A1C60` -> `DirectX__Destructor`. | I02 exact readback. | Only name changes for A02; A02/P02, including SHA256, otherwise exact. |
| I04 / C0000IW-153 | Set FR at `0x004a1c60` exactly `Releases m_pDirectDraw, clears the field, invokes Singleton<DirectX> teardown, then destroys LObject.` | I03 exact readback. | Only FR changes in addition to I03 name; A02/P02 otherwise exact. |
| I05 / C0000IW-154 | Pure rename `0x004a1cc0`: `sub_4A1CC0` -> `Singleton_DirectX__Destructor`. | I04 exact readback. | Only name changes for A03; A03/P03, including SHA256, otherwise exact. |
| I06 / C0000IW-155 | Set FR at `0x004a1cc0` exactly `Out-of-line Singleton<DirectX> destructor specialization used by DirectX constructor unwind; clears g_pDirectX.` | I05 exact readback. | Only FR changes in addition to I05 name; A03/P03 otherwise exact. |
| I07 / C0000IW-156 | Pure rename `0x004a1cd0`: `sub_4A1CD0` -> `DirectX__ScalarDeletingDestructor`. | I06 exact readback. | Only name changes for A04; A04/P04, including SHA256, otherwise exact. |
| I08 / C0000IW-157 | Set FR at `0x004a1cd0` exactly `Compiler-generated scalar deleting destructor for DirectX; destruction and optional delete are controlled by flags.` | I07 exact readback. | Only FR changes in addition to I07 name; A04/P04 otherwise exact. |
| I09 / C0000IW-158 | Read-only same-database public `type_query` with `filter:"^DirectX$"`, `kind:"any"`, `count:20`, `include_decl:true`, `include_members:true`, and `include_relationships:true`; also repeat exact A05/P05 item/name/type/comment/xref/byte prestate. Explicitly do not call `declare_type`: public parser success for `struct DirectX;` was observed not to create an enumerable numbered type. | I08 exact readback, freshly re-listed active canonical `database`, and exact A05/P05 prestate. | `type_query` returns exactly one query result with `total:0` and no rows; A05/P05 and every address remain byte-for-byte unchanged. Any nonzero/malformed/omitted result, database/path mismatch, state delta, or attempted type declaration stops with no save. |
| I10 / C0000IW-187 | Call public `make_data` against the freshly re-listed active canonical `database` with exactly one item `{addr:"0x0067ab20",type:"struct DirectX *g_pDirectX",name:"g_pDirectX",delete_existing:false}`. This is the sole A05 type/data/name mutation, is not a rename, and must not reference `unk_67AB20`. | I09 exact zero-row/no-mutation readback and exact A05/P05 prestate. | `make_data` returns exactly one result with `addr:"0x0067ab20"`, `name:"g_pDirectX"`, `size:4`, `ok:true`, no `error`, and a returned type that normalizes to pointer-to-DirectX (`DirectX *` or `struct DirectX *`). Immediate same-database public `inspect_items` request `addrs:"0x0067ab20"` returns exactly one result with `addr:"0x0067ab20"`, `head:"0x67ab20"`, `end:"0x67ab24"`, `size:4`, `name:"g_pDirectX"`, the same pointer-to-DirectX meaning, `is_code:false`, `is_data:true`, and no `error`. AR/AP remain blank, all 19 inbound xrefs and the four-byte SHA256 remain unchanged. A `void *`, integer, blank, differently targeted, differently sized, destructive, extra-row, or omitted-field result stops. `type_query total:0` remains acceptable and is not item-type readback. |
| I11 / C0000IW-159 | Set AP at `0x0067ab20` exactly `Process-wide DirectX pointer published and cleared by Singleton<DirectX> specializations; exact storage is 0x0067ab20-0x0067ab24.` | I10 exact postreadback. | Only AP changes after I10; the exact four-byte data/name/type, blank AR, 19 xrefs, and SHA256 remain unchanged. |
| I12 / C0000IW-160 | Call public `rename` twice against the freshly re-listed active canonical `database`. Dry-run request: `batch:{data:{old:"stru_631570",new:"IID_IDirectDraw"},dry_run:true,pure:true,allow_overwrite:false,stop_on_error:true}`. Apply request is identical except `dry_run:false`. No function-style `addr`/`name` fields and no `batch.func` entry are authorized for A06. | I11 exact readback, exact A06/P06 prestate, current `stru_631570` resolving only to `0x00631570`, and destination `IID_IDirectDraw` remaining collision-free. The apply call is permitted only after the dry-run response passes every expected field. | Dry-run and apply must each report `summary.total:1`, `ok:1`, `failed:0`, `stopped:false` and exactly one `data` result with `addr:"0x00631570"`, `old:"stru_631570"`, `new:"IID_IDirectDraw"`, the matching dry-run state, and no `error`; any missing/extra row, alternate address/match, error, or summary mismatch stops. Applied entity readback must show only the name changed to `IID_IDirectDraw`; A06/P06 exact `IID` type, `[0x00631570,0x00631580)` range, width/count 16, sole C0000IW-103 xref, blank AR/AP, bytes, and SHA256 remain exact. I13 remains a separate AP-only action. |
| I13 / C0000IW-161 | Set AP at `0x00631570` exactly `SDK IID_IDirectDraw used by DirectX::DirectX QueryInterface.` | I12 exact readback. | Only AP changes in addition to I12 name; A06/P06 otherwise exact. |
| I14 / C0000IW-110 | Set AP at `0x00618e60` exactly `DirectX complete-object locator pointer; virtual slots begin at 0x00618e64.` | I13 exact readback. | Only A07 AP changes; A07/P07, including SHA256, otherwise exact. |
| I15 / C0000IW-111 | Set AP at `0x00618e70` exactly `True start of DirectX failure literal through 0x00618efc; used by both constructor failure paths.` | I14 exact readback. | Only A08 AP changes; A08/P08, including SHA256, otherwise exact. |

Complete current frame and stack protection:

| Frame | Current rows, each `name@offset/size:type` | Proposed delta and expected readback |
| --- | --- | --- |
| F01 / A01 | `Block@0xc/0x4:void *`; `var_18@0x10/0x4:LObject *`; `lpDD@0x14/0x4:LPDIRECTDRAW`; `pExceptionObject@0x18/0x4:_DWORD`; `var_C@0x1c/0x4:_DWORD`; `var_4@0x24/0x4:_DWORD`; `__saved_registers@0x28/0x4:_DWORD`; `__return_address@0x2c/0x4:_UNKNOWN *`; `arg_4@0x34/0x4:_DWORD`. | No delta. All nine rows are protected byte-for-byte; no local/argument rename or type change. |
| F02 / A02 | `var_C@0x8/0x4:_DWORD`; `__saved_registers@0x14/0x4:_DWORD`; `__return_address@0x18/0x4:_UNKNOWN *`; `arg_4@0x20/0x4:_DWORD`. | No delta. All four rows protected. |
| F03 / A03 | `__return_address@0x0/0x4:_UNKNOWN *`. | No delta. Sole row protected; do not materialize a `this` row. |
| F04 / A04 | `var_C@0x8/0x4:_DWORD`; `var_4@0x10/0x4:_DWORD`; `__saved_registers@0x14/0x4:_DWORD`; `__return_address@0x18/0x4:_UNKNOWN *`; `arg_0@0x1c/0x4:_DWORD`. | No delta. All five rows protected; do not rename/retype `arg_0`. |

Individual protected-item rows:

| Protection ID | Exact protected item | Required no-change readback |
| --- | --- | --- |
| P01 | A01 function/head/range/type/frame/channels, caller C0000IW-059, callees C0000IW-060 through C0000IW-062, C0000IW-065 through C0000IW-067, and C0000IW-132 through C0000IW-137, far range C0000IW-049, and exact 246-byte SHA256 `645B88E4E96B0F7A412BA5096EB7DAEE18E8163AB6CEDDB5F887C83BEB70CAEE`. | Only I01 name and I02 FR may differ; the exact hash and all other listed state must remain unchanged. |
| P02 | A02 function/head/range/type/frame/channels, C0000IW-069-C071, far range C0000IW-050, and exact 92-byte SHA256 `293CE407F59B697391951ACD0FCECD5807D965C6DBCF6D9604A501FDD023D356`. | Only I03 name and I04 FR may differ; hash and all other state unchanged. |
| P03 | A03 function/first item/trailing return/range/type/frame/channels, C0000IW-072/C0000IW-083, and exact 11-byte SHA256 `E00FE42EBA5658269EE3AC5105DC88398EDD86A2C111FA90F968B2418616D5D7`. | Only I05 name and I06 FR may differ; hash and all other state unchanged. |
| P04 | A04 function/head/range/type/frame/channels, C0000IW-073-C078/C0000IW-084, far ranges C0000IW-051-C052, and exact 154-byte SHA256 `553D6FD33B5FF374442F50A2D039184431170252AE989712E5E176F9A401500D`. | Only I07 name and I08 FR may differ; hash and all other state unchanged. |
| P05 | A05 one-byte unnamed/untyped undefined pre-item, semantic four-byte storage, blank AR/AP, each exact C0000IW-079-C097 xref, exact 4-byte SHA256 `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`, no `unk_67AB20`, and same-database exact-name local-type prestate `DirectX total:0`. | I09 is read-only, must preserve `DirectX total:0`, and must not call `declare_type`. I10 alone may attach the self-contained `struct DirectX *g_pDirectX` declaration and exact name with `delete_existing:false`, verified through `make_data` plus `inspect_items`. I11 may then change only AP. Hash, bytes, all 19 xrefs, AR, address, and range remain unchanged. |
| P06 | A06 exact `[0x00631570,0x00631580)` 16-byte IID item, type `IID`, value/bytes, blank AR/AP, sole C0000IW-103 inbound use, and exact SHA256 `DC3CA51EE680125BA815CBCE6C7C0D8E82F979CD9DF015CA3EC29438487EC5D2`. | I12 may change only the name through the exact one-match `rename.batch.data` dry-run/apply contract; I13 may then change only AP. Range, width/count, `IID` type, value/bytes, sole xref, AR, and hash remain unchanged. |
| P07 | A07 four-byte unnamed/untyped data cell, value/link C0000IW-035, AR, following vtable boundary, and exact SHA256 `B474BB52FFB7CCFC2DF90E99C09953CCF65E7E4886858CB13E8E8775584E957A`. | Only I14 AP may differ; hash and all other state unchanged. |
| P08 | A08 split four-byte literal head, complete 140-byte logical literal, name/type, AR, C0000IW-101-C102, successor boundary, and exact SHA256 `538C0281DE2C7CEFCEDC5B949737DD09ED86FD7D7D8FE8B1E8C355E652AD446B`. | Only I15 AP may differ; hash and all other state unchanged. |
| P09 | Padding data head/range `[0x004a1b5e,0x004a1b60)`, width 2; name/type `""`; `AR=""`, `AP=""`, `FR/FP=N/A`; two `cc` bytes; xrefs 0; C0000IW-054. | Exact no-change; never define, rename, type, comment, merge, or convert. |
| P10 | Padding data head/range `[0x004a1c56,0x004a1c60)`, width 10; name/type `""`; `AR=""`, `AP=""`, `FR/FP=N/A`; ten `cc` bytes; xrefs 0; C0000IW-055. | Exact no-change under the same stop/no-save rule. |
| P11 | Padding data head/range `[0x004a1cbc,0x004a1cc0)`, width 4; name/type `""`; `AR=""`, `AP=""`, `FR/FP=N/A`; four `cc` bytes; xrefs 0; C0000IW-056. | Exact no-change under the same stop/no-save rule. |
| P12 | Padding data head/range `[0x004a1ccb,0x004a1cd0)`, width 5; name/type `""`; `AR=""`, `AP=""`, `FR/FP=N/A`; five `cc` bytes; xrefs 0; C0000IW-057. | Exact no-change under the same stop/no-save rule. |
| P13 | Padding data head/range `[0x004a1d6a,0x004a1d70)`, width 6; name/type `""`; `AR=""`, `AP=""`, `FR/FP=N/A`; six `cc` bytes; xrefs 0; C0000IW-058. | Exact no-change, including successor `0x004a1d70`. |
| P14 | DirectX COL logical range `[0x0064681c,0x00646830)`, width `0x14`; first data head `[0x0064681c,0x00646820)`, width 4; name `??_R4DirectX@@6B@`; type `""`; `AR="signature"`, `AP=""`, `FR/FP=N/A`; inbound `0x00618e60`; C0000IW-035. | Exact heads/range/width/name/type/channels/fields/bytes/xref unchanged. |
| P15 | DirectX CHD logical range `[0x00646830,0x00646840)`, width `0x10`; first data head width 4; name `??_R3DirectX@@8`; type `""`; `AR="signature"`, `AP=""`, `FR/FP=N/A`; inbound `0x0064682c,0x00646868`; C0000IW-036. | Exact no-change, including count 3 and BCA link. |
| P16 | DirectX BCA logical range `[0x00646840,0x00646850)`, width `0x10`; first data head width 4; name `??_R2DirectX@@8`; type `""`; `AR="reference to base class decription 1"`, `AP=""`, `FR/FP=N/A`; inbound `0x0064683c`, outbound `0x00646850`; C0000IW-037. | Exact no-change, including literal typo and all three entries. |
| P17 | DirectX self BCD logical range `[0x00646850,0x0064686c)`, width `0x1c`; first data head width 4; name `??_R1A@?0A@EA@DirectX@@8`; type `""`; `AR="reference to type description"`, `AP=""`, `FR/FP=N/A`; inbound `0x00646840`, outbound `0x00675be0`; C0000IW-038. | Exact no-change, including PMD and CHD fields. |
| P18 | Singleton base BCD logical range `[0x0064686c,0x00646888)`, width `0x1c`; first data head width 4; name `??_R13?0A@EA@?$Singleton@VDirectX@@@@8`; type `""`; `AR="reference to type description"`, `AP=""`, `FR/FP=N/A`; inbound `0x00646848`, outbound `0x00675bf8`; C0000IW-039. | Exact no-change, including PMD `{+4,-1,0}` and CHD link. |
| P19 | Singleton CHD logical range `[0x00646888,0x00646898)`, width `0x10`; first data head width 4; name `??_R3?$Singleton@VDirectX@@@@8`; type `""`; `AR="signature"`, `AP=""`, `FR/FP=N/A`; inbound `0x00646884,0x006468b8`; C0000IW-040. | Exact no-change, including self-hierarchy fields. |
| P20 | Singleton BCA logical range `[0x00646898,0x006468a0)`, width 8; first data head width 4; name `??_R2?$Singleton@VDirectX@@@@8`; type `""`; `AR="reference to base class decription 1"`, `AP=""`, `FR/FP=N/A`; inbound `0x00646894`, outbound `0x006468a0`; C0000IW-041. | Exact no-change, including literal typo. |
| P21 | Singleton self BCD logical range `[0x006468a0,0x006468bc)`, width `0x1c`; first data head width 4; name `??_R1A@?0A@EA@?$Singleton@VDirectX@@@@8`; type `""`; `AR="reference to type description"`, `AP=""`, `FR/FP=N/A`; inbound `0x00646898`, outbound `0x00675bf8`; C0000IW-042. | Exact no-change, including PMD and CHD fields. |
| P22 | DirectX type descriptor logical range `[0x00675be0,0x00675bf8)`, width `0x18`; first data head width 4; name `??_R0?AVDirectX@@@8`; type `""`; `AR="reference to RTTI's vftable"`, `AP=""`, `FR/FP=N/A`; inbound `0x00646828,0x00646850`, outbound `0x00635078`; C0000IW-043. | Exact no-change, including decorated payload/string and all xrefs. |
| P23 | Singleton type descriptor logical range `[0x00675bf8,0x00675c20)`, width `0x28`; first data head width 4; name `??_R0?AV?$Singleton@VDirectX@@@@@8`; type `""`; `AR="reference to RTTI's vftable"`, `AP=""`, `FR/FP=N/A`; inbound `0x0064686c,0x006468a0`, outbound `0x00635078`; C0000IW-044. | Exact no-change, including decorated payload/string and all xrefs. |

Future UDT invariant remains evidence-only: size `0x8`, LObject `+0x0`, empty Singleton PMD `+0x4`, and `LPDIRECTDRAW` field `+0x4`. No UDT action is authorized. Decorated RTTI/vtable names, five padding spans, far chunks, adjacent functions, and the absent fifth function are protected no-change state.

## First-Draft C++ Recommendation

- Eligible: yes. Exact block contents follow.
- Source order: class includes/children; global child 0; methods child 1; vtable marker child 2; diagnostic marker child 3; class H complete.

UID00003Y CPP:
```cpp
#include "DirectX.h"
#include "../util/Error.h"

[[CHILDREN]]
```

UID00003Y H:
```cpp
#ifndef NEXUSTK_RENDER_DIRECTX_H
#define NEXUSTK_RENDER_DIRECTX_H

#include "../util/LObject.h"
#include "../util/Singleton.h"
#include <ddraw.h>

class DirectX : public LObject, public Singleton<DirectX>
{
public:
    DirectX();
    virtual ~DirectX();

    LPDIRECTDRAW m_pDirectDraw;
};

extern DirectX *g_pDirectX;

typedef char DirectXSizeMustBe0x8[
    sizeof(DirectX) == 0x8 ? 1 : -1];

#endif
```

DirectX-associated Error support is part of this report's allocated support scope, not an A/C-agent handoff. The coordinated support below completes the declarations and every source-bearing or compiler-only Error/MyError function needed to make DirectX compile while leaving unrelated Error siblings on their existing routes.

Exact Error/MyError source identity and disposition:

| Function | Owner/destination | Formal disposition |
| --- | --- | --- |
| `[0x004a67a0,0x004a683d)` `MyError::MyError` | UID0002HO CPP | Preserve the exact constructor CPP block below; UID0002HO H remains blank under C0000IW-174. |
| `[0x004a6840,0x004a6858)` `MyError::FormatErrorMessage` | UID00008V CPP | Emit only the formatter method below under C0000IW-165. |
| `[0x004a6860,0x004a6882)` `MyError::~MyError` | UID00008V CPP | Emit only the ordinary destructor method below under C0000IW-166. |
| `[0x004a68e0,0x004a691e)` Error scalar deleting destructor | UID00004J H source cause; UID0002TV-neighbor memory evidence | Compiler-generated from inline empty virtual `Error::~Error()` in the coordinated H. Exact 62-byte SHA256 `E8144E5BF8ADF60BD3FE8347E1B3871E3029191871D04A6AFE3B2B4C8BF00B2F`; no separate handwritten CPP under C0000IW-167. |
| `0x004a6a10` MyError scalar deleting destructor | UID00008V ordinary-destructor source cause; UID0002TV memory evidence | Compiler-generated from `MyError::~MyError()`; no duplicate CPP under C0000IW-128. |
| `[0x004a6a70,0x004a6a76)` `Error::GetErrorName` | UID00004J CPP | Emit only the exact method below under C0000IW-163. |

UID00004J CPP:
```cpp
#include "Error.h"
#include <wchar.h>

const wchar_t *Error::GetErrorName() const
{
    return L"Error";
}
```

UID00004J H:
```cpp
#ifndef NEXUSTK_UTIL_ERROR_H
#define NEXUSTK_UTIL_ERROR_H

#include "LObject.h"
#include <stddef.h>

class Error : public LObject
{
public:
    virtual ~Error()
    {
    }

    virtual int FormatErrorMessage(
        wchar_t *destination,
        size_t destinationChars) const = 0;
    virtual const wchar_t *GetErrorName() const;
};

class MyError : public Error
{
public:
    MyError(const wchar_t *message);
    virtual ~MyError();

    virtual int FormatErrorMessage(
        wchar_t *destination,
        size_t destinationChars) const;

private:
    wchar_t *m_messageText;
};

typedef char ErrorSizeMustBe0x4[
    sizeof(Error) == 0x4 ? 1 : -1];
typedef char MyErrorSizeMustBe0x8[
    sizeof(MyError) == 0x8 ? 1 : -1];

#endif
```

UID00008V CPP:
```cpp
int MyError::FormatErrorMessage(
    wchar_t *destination,
    size_t destinationChars) const
{
    return wcscpy_s(destination, destinationChars, m_messageText);
}

MyError::~MyError()
{
    delete [] m_messageText;
}
```

UID00008V H stays blank because UID00004J owns the single coordinated guarded header block. UID0002HO retains its existing exact constructor CPP and blank H. UID00013X records the two exact MyError method splits, UID0002TV records ordinary-destructor coverage of the `0x004a6a10` scalar wrapper, and UID0002ND/UID0001UE/UID0001XI remain marker/type evidence rather than duplicate source emitters.

UID0002HO CPP, exact current payload identity:
```cpp
MyError::MyError(const wchar_t *message)
{
    size_t length = wcslen(message);

    m_messageText = new wchar_t[length + 1];
    wcsncpy_s(m_messageText, length + 1, message, length);
    m_messageText[length] = L'\0';
}
```

For that fenced payload only, normalized UTF-8 with LF line endings and one terminal newline is exactly 222 bytes with SHA256 `F3283F846DA3D69C8DF1F97FF2FE06A98B5BAF39A3CA86D1FCD553D1B09B22F5`. The machine body `[0x004a67a0,0x004a683d)` is 157 bytes with SHA256 `D361B3F2AF84E2EE716E34E77FEB4C493ABD0EE73AEA13CDD0EF0504E719470A`. UID0002HO H remains blank because UID00004J H supplies the declaration once.

UID0000QS CPP:
```cpp
DirectX *g_pDirectX = NULL;

template <>
Singleton<DirectX>::Singleton()
{
    g_pDirectX = static_cast<DirectX *>(this);
}

template <>
Singleton<DirectX>::~Singleton()
{
    g_pDirectX = NULL;
}

[[CHILDREN]]
```

UID0000QS H stays blank. UID000295 CPP:
```cpp
// Emitted code for this range is covered by [UID:0000QS][g_pDirectX](by-global/g_pDirectX.md).
```

UID000295 H stays blank. UID000137 CPP:
```cpp
DirectX::DirectX()
    : LObject(),
      Singleton<DirectX>(),
      m_pDirectDraw(NULL)
{
    LPDIRECTDRAW lpDD = NULL;
    if (DirectDrawCreate(NULL, &lpDD, NULL) < 0) {
        throw new MyError(L"DirectX not installed, or is corrupted. Please install DirectX again.");
    }

    if (lpDD->QueryInterface(IID_IDirectDraw, (LPVOID *)&m_pDirectDraw) < 0) {
        throw new MyError(L"DirectX not installed, or is corrupted. Please install DirectX again.");
    }
}

DirectX::~DirectX()
{
    m_pDirectDraw->Release();
    m_pDirectDraw = NULL;
}
```

UID000137 H stays blank. UID0002MD CPP:
```cpp
// DirectX vtable and RTTI data are compiler-generated from [UID:00003Y][DirectX](by-class/DirectX.md).
```

UID0002MD H stays blank; UID0003HP CPP/H stay blank as semantic type documentation. UID0003AY CPP:
```cpp
// This literal is emitted by the two failure throws in [UID:000137][DirectX](by-memory/0x004a1b60-0x004a1d6a.DirectX.md).
```

UID0003AY H stays blank; UID0003OG stays blank because SDK supplies it.

Explicit specializations reproduce pointer adjustment/publication/clear; base order reproduces RTTI/destruction; methods preserve all calls/failures/release and intentionally preserve no local `lpDD` release and no dtor null guard. The Error support H supplies the complete `MyError` type required by both `new MyError` expressions. Fresh `0x004a67a0`, `0x004a6840`, `0x004a6860`, `0x004a68e0`, `0x004a6a10`, and `0x004a6a70` evidence now gives every source-bearing or compiler-only Error/MyError function an exact CPP/H/no-code disposition. Style matches current C++98/Win32 reconstruction. Third-party import is not applicable.

## Final Recommendation

- Accept 164 active independently verifiable claims for fresh Gate 1 review and retain 23 explicitly historicalized claims in `excluded-with-reason` state only as nonauthoritative allocation history. C0000IW-158 now atomically allocates the no-`declare_type` read-only preflight, C0000IW-187 allocates the sole self-contained A05 data/type/name action, and C0000IW-159 retains the separate AP action.
- Keep sole target/file owner and apply formal/emitter repairs to UID00003Y, UID0000QS, UID000295, UID000137, UID0002MD, UID0003AY.
- Apply the associated Error support closure to UID0000J5, UID00004J, UID00008V, UID0002HO, UID00013X, UID0002TV, UID0002ND, UID0001UE, and UID0001XI using the exact Section 22 CPP/H and no-duplicate-source dispositions. This includes the exact UID0002HO constructor payload and checked `[0x004a68e0,0x004a691e)` compiler-wrapper disposition.
- Keep UID0003HP semantic blank, UID0003OG external, mixed pages non-owning.
- Apply scores only after scoped validators and coherent DirectX CPP/H plus Error.h readback.
- IDA remains separately supervisor-owned.
- Gate 2B must use the revised Section 21 public sequence: expected zero-row numbered-type preflight at I09, no standalone type declaration, exact full-declaration `make_data` plus `inspect_items` readback at I10, and the existing separate I11-I15 actions. The 2026-08-14 failed unsaved attempt and clean recovery are historical evidence only.
- No A/C-agent or generic future-work handoff remains. Broader Error siblings retain their existing ownership, but the DirectX-associated Error/MyError header, constructor, formatter, ordinary destructor, name method, and two scalar-wrapper no-code routes are complete within this report's support scope.
- Implementation disposition: ordinary-document work remains complete. This corrected artifact is submitted for fresh Gate 1 review, and the authoritative current result exists only in `tools/leaser/Agents/b-report-validation-audit.md`; Gate 2 handling of corrected unchecked supervisor-owned IDA/manual-coverage/lifecycle rows follows only the result recorded there.

## Recommended Target Doc Changes

- Target: `by-file/DirectX.md`.
- Set `92/94`; keep `NexusTK/render/` and file owner.
- Incorporate direct bases, EBO/size, public field, Singleton specializations, source order, required H, dependencies, exhaustive inventory/xrefs, and generated audit.
- Historicalize the one-base/manual-global/pure-helper assumptions and missing `source-3/simroot_v2/class_DirectX.cpp` reference.
- Preserve negative evidence and the resolved Error.h prestate/closure evidence.
- Applied and scoped-validated as specified; generated readback confirms the target metadata, exhaustive inventories, formal source, child order, and support dependency.

## Recommended Support Doc Changes

| Path | Exact recommendation |
| --- | --- |
| `by-class/DirectX.md` formal source/layout | Set `92/94`; exact CPP/H from Section 22; document two bases, EBO, size, public field, extern, dependencies; C0000IW-002-C004/C0000IW-024. |
| `by-class/DirectX.md` child 0 entry | Add only UID0000QS at position 0; C0000IW-138. |
| `by-class/DirectX.md` child 1 entry | Add only UID000137 at position 1; C0000IW-140. |
| `by-class/DirectX.md` child 2 entry | Add only UID0002MD at position 2; C0000IW-142. |
| `by-class/DirectX.md` child 3 entry | Add only UID0003AY at position 3; C0000IW-144. |
| `by-global/g_pDirectX.md` emitter metadata | Set emitter `00003Y`, position `0`; C0000IW-139. |
| `by-global/g_pDirectX.md` definition CPP | Emit only `DirectX *g_pDirectX = NULL;`; C0000IW-178. |
| `by-global/g_pDirectX.md` constructor specialization CPP | Emit only the exact publication method; C0000IW-179. |
| `by-global/g_pDirectX.md` destructor specialization CPP | Emit only the exact clear method; C0000IW-180. |
| `by-global/g_pDirectX.md` score | Set `92/94`; C0000IW-146. |
| `by-memory/0x0067ab20-0x0067ab24.g_pDirectX.md` | Set `92/94`; replace definition with covered-by marker; preserve bytes/xrefs; correct source owner. |
| `by-memory/0x004a1b60-0x004a1d6a.DirectX.md` source/inventory | Set `92/94`; exact methods; reclassify `0x004a1cc0`; add far/padding/source/compiler inventory; C0000IW-026/C0000IW-045-C0000IW-078/C0000IW-132-C0000IW-137. |
| `by-memory/0x004a1b60-0x004a1d6a.DirectX.md` emitter metadata | Set emitter `00003Y`, position `1`; C0000IW-141. |
| `by-memory/0x00618e60-0x00618e70.DirectXVtableData.md` marker/score | Set `92/94`; marker and corrected inheritance/RTTI; C0000IW-011/C0000IW-149. |
| `by-memory/0x00618e60-0x00618e70.DirectXVtableData.md` emitter metadata | Set emitter `00003Y`, position `2`; C0000IW-143. |
| `by-type/by-vtable/DirectXVtable.md` | Set `92/94`; formal blocks remain blank; class declaration is source cause; C0000IW-148. |
| `by-memory/0x00618e70-0x00618efc.DirectXDiagnosticString.md` source/score | Set `92/94`; insert literal covered-by marker; preserve bytes/xrefs; C0000IW-012/C0000IW-028. |
| `by-memory/0x00618e70-0x00618efc.DirectXDiagnosticString.md` emitter metadata | Set emitter `00003Y`, position `3`; C0000IW-145. |
| `by-memory/0x00618e50-0x00618efc.DirectXBitmapReadOnlyData.md` | Add only corrected RTTI/Singleton context; retain score/owner/non-emitting state; C0000IW-181. |
| `by-type/by-vtable/DIBitmapDirectXVtables.md` | No edit: retain current score/owner and mixed DIBitmap/DirectX split; C0000IW-182. |
| `by-memory/0x00631570-0x00631580.DirectDrawGuidConstant.md` | No score/code change; retain external SDK GUID and corrected ctor route. |
| Singleton file/template | Already present at same-or-greater detail; no edit. |
| `by-file/Error.md` support closure | Record current absent-header prestate, coordinated ownership, and generated Error.h verification requirement; C0000IW-120. |
| `by-class/Error.md` H | Emit only the complete guarded Error/MyError declaration and size-assertion block, including inline empty virtual `Error::~Error()`; C0000IW-162. |
| `by-class/Error.md` CPP | Emit only exact `Error::GetErrorName`; C0000IW-163. |
| `by-class/MyError.md` H | Keep blank and record declaration coverage by UID00004J H; C0000IW-164. |
| `by-class/MyError.md` formatter CPP | Emit only exact `MyError::FormatErrorMessage`; C0000IW-165. |
| `by-class/MyError.md` destructor CPP | Emit only exact `MyError::~MyError`; C0000IW-166. |
| `by-memory/0x004a67a0-0x004a683d.MyErrorConstructor.md` CPP | Preserve the exact 222-byte Section 22 constructor payload with SHA256 `F3283F846DA3D69C8DF1F97FF2FE06A98B5BAF39A3CA86D1FCD553D1B09B22F5`; C0000IW-173. |
| `by-memory/0x004a67a0-0x004a683d.MyErrorConstructor.md` H | Keep blank because UID00004J H owns the declaration; C0000IW-174. |
| `by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md` formatter row | Record `[0x004a6840,0x004a6858)` as the source-emitted formatter; C0000IW-123. |
| `by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md` destructor row | Record `[0x004a6860,0x004a6882)` as the source-emitted ordinary destructor; C0000IW-124. |
| `by-memory/0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers.md` Error scalar function row | Record `[0x004a68e0,0x004a691e)` as the 62-byte compiler-generated scalar deleting destructor caused by inline `Error::~Error()`, with exact SHA256 and no duplicate CPP; C0000IW-167. |
| `by-memory/0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers.md` Error scalar inbound row | Record sole `0x00619344 -> 0x004a68e0` route and zero direct code callers; C0000IW-168. |
| `by-memory/0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers.md` Error scalar vtable-store row | Record `0x004a68e6 -> 0x00619344`; C0000IW-169. |
| `by-memory/0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers.md` Error scalar base-teardown row | Record `0x004a68ec -> 0x004f4a90`; C0000IW-170. |
| `by-memory/0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers.md` Error scalar delete row | Record `0x004a68fd -> 0x004f4ac0` and flag disposition; C0000IW-171. |
| `by-memory/0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers.md` Error scalar guard row | Record `0x004a690f -> 0x0041b6a0` and size-4 flag path; C0000IW-172. |
| `by-memory/0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers.md` GetErrorName row | Record `[0x004a6a70,0x004a6a76)` as source-emitted `Error::GetErrorName`; C0000IW-125. |
| `by-memory/0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers.md` MyError scalar row | Keep `0x004a6a10` compiler-covered by the ordinary MyError destructor with no duplicate CPP; C0000IW-128. |
| `by-file/Error.md` score metadata | Set no higher than `89/90` after generated support verification; C0000IW-183. |
| `by-class/Error.md` score metadata | Set no higher than `90/92` after H/GetErrorName/0x004a68e0 closure and generated verification; C0000IW-184. |
| `by-class/MyError.md` score metadata | Set no higher than `91/93` after formatter/destructor/constructor/H-route closure; C0000IW-185. |
| `by-memory/0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers.md` score metadata | Retain `86/90`; the new `0x004a68e0` proof changes classification completeness, not source quantity; C0000IW-186. |
| `by-memory/0x00619340-0x00619448.ErrorHierarchyVtableData.md` | Keep marker-only raw data; update source cause to the completed Error/MyError declarations; C0000IW-129. |
| `by-type/by-struct/ErrorObjectLayouts.md` | Record compile-support declarations preserving Error size 4 and MyError size 8 with `m_messageText` at `+0x04`; C0000IW-130. |
| `by-type/by-vtable/ErrorHierarchyVtables.md` | Record the completed five-slot declaration order and exact formatter/name routes; no raw table source; C0000IW-131. |
| Application/Surface/GrafPort/ScreenPane | No ownership edit; consumers only. |
| Proposed source tree | Path unchanged; add H only if sibling headers are explicitly listed. |

Every affected by-memory, by-class, by-global, by-type, mixed-container, dependency, consumer, and source-tree page has an edit or no-edit disposition.

Implementation result: every edit row above was applied at its independently allocated destination. The `DirectDrawGuidConstant` and `DIBitmapDirectXVtables` no-change rows were physically verified at SHA256 `9C9A969903E216FAA389793C9FE59491A500017F33952DF444196F195AF4117F` and `B5BCA9DDB309DC994AD9442E864DCDB3490565987E94FDC7EDF1D9520DE63E8C`; no ordinary destination remains deferred.

## Score And Metadata Recommendation

- Target: `85/88` to `92/94`; same file owner/path.
- DirectX support: UID00003Y, 0000QS, 000295, 000137, 0002MD, 0003HP, 0003AY all to `92/94`.
- Error support scoring is deliberately scoped: C0000IW-184 permits UID00004J to rise from `86/89` to `90/92` after exact CPP/H, checked `0x004a68e0` compiler coverage, and generated Error.h verification; C0000IW-185 permits UID00008V to rise from `87/90` to `91/93` after exact formatter/destructor emission and retained compiler-only `0x004a6a10`; C0000IW-183 permits UID0000J5 to rise from `88/87` to `89/90` because this closes the DirectX-required subset but does not claim all sibling formatters complete. UID0002HO remains `90/92`; C0000IW-186 keeps UID0002TV at `86/90`, and other aggregate/type/data support scores remain unchanged because the checked wrapper gains disposition evidence but no new handwritten source.
- Emitter order: UID0000QS emitter `00003Y` position `0`; UID000137 `00003Y` position `1`; UID0002MD `00003Y` position `2`; UID0003AY `00003Y` position `3`; UID000295 remains child of UID0000QS but marker-only.
- Reconstructable states stay true for source/covered children; mixed containers stay false/non-emitting; GUID stays external.
- Score attempt: ten atomic RTTI claims close bases/layout; four local plus four far and five atomic padding claims close code range; individually allocated caller/callee/xref claims close liveness; consumers close H/access; Singleton/Crasher closes source cause; raw data closes GUID/literal/vtable. Error support is independently checkable through the file route, H, three source methods, exact existing constructor identity, two compiler-only scalar wrappers, five exact `0x004a68e0` routes, layout/vtable evidence, and three manual-row operations.
- Not 95+: no PDB, bounded text/access/guard uncertainty, no IDA UDT mutation, and broader Error sibling source remains outside this DirectX compile-support score.
- Applied-score verification: all stated formal-source and generated-readback prerequisites now pass, so the listed DirectX and scoped Error scores are current ordinary-document metadata rather than projections. The confidence caps and unchanged support scores remain justified by the same independently verifiable claim set.
- Fresh IDA-prestate and Gate 2B correction has no ordinary-document score effect: the corrected live A01/A02/A04 types are IDA analysis types, not proposed C++ signatures. The A05 item probe supports the `DirectX *g_pDirectX` interpretation, while the failed standalone declaration readback rejects only that unsupported public action. Source scores remain unchanged; this corrected artifact is submitted for fresh Gate 1 review, whose authoritative current result exists only in `tools/leaser/Agents/b-report-validation-audit.md`.

## Open Questions With Attempted Resolution

| Question | Evidence | Resolution/impact |
| --- | --- | --- |
| Multiple inheritance? | Complete RTTI/PMDs/type strings/ctor arithmetic. | Resolved: LObject plus Singleton. |
| `0x004a1cc0` source? | Sole far-EH call, ECX, body, template policy, ordinary inlining. | Source specialization body with compiler placement; not DirectX helper. |
| Field private? | Cross-module direct accesses; no getter/friends. | Public is least-invented; non-PDB token caps confidence. |
| Storage definition owner? | ODR, semantic-global precedent, Crasher. | Semantic global defines; physical child covered. |
| Header required? | Complete-base rules and consumers. | Yes; headerless rejected. |
| Error.h available? | Current generated util readback shows absence; fresh Error/MyError functions, layouts, slots, and existing constructor source determine the needed support. | Resolved in scope: Section 22 provides the exact guarded declaration, exact existing constructor, formatter, ordinary destructor, GetErrorName, and both scalar-wrapper no-code dispositions; implementation verification must reread generated Error.h. |
| What is checked function `0x004a68e0`? | Exact 62-byte/26-instruction body, scalar-wrapper type/frame, base-vtable-only inbound route, vtable restore, base teardown, optional delete, flag-4 guard path, and SHA256. | Closed: compiler-generated Error scalar deleting destructor caused by inline empty virtual `Error::~Error()` in UID00004J H. Destination is the ErrorDestructorAndNameHelpers exact function/xref/callee rows; no separate CPP and no open support handoff. |
| What are the exact live A01/A02/A04 types and supported A05 action? | Fresh canonical preflight returned `char *__thiscall(char *this)`, `int __thiscall(_DWORD *this)`, and `_DWORD *__thiscall(_DWORD *Block, char)`; A05 had blank name/type and an undefined one-byte item. The old-symbol rename dry-run failed. The disposable-copy item probe preserved all 19 xrefs, but fresh Gate 2B proved an apparent forward-declaration success remained absent from immediate same-database `type_query`. Installed public code explains the split: `declare_type` checks parser errors; `type_query` enumerates numbered ordinals. | Resolved: preserve the three live function types without type mutations; do not call `declare_type`; accept expected `type_query total:0` as the numbered-type prestate; then use sole public `make_data` item `struct DirectX *g_pDirectX` with separate exact name and `delete_existing:false`. Require one successful four-byte result plus immediate `inspect_items` pointer-to-DirectX readback, unchanged bytes/xrefs/blank AR/AP, then add AP separately. No `unk_67AB20` rename or `void *` fallback remains. |
| Release local lpDD? | Exact ctor. | No release present; preserve behavior. |
| Destructor null guard? | Exact dtor. | None; do not invent. |
| Exact original tokens? | No PDB. | Canonical/best-source names; confidence below 95. |

No open question blocks DirectX CPP/H or its MyError compile dependency. The report's associated Error support is self-contained; broader unrelated Error siblings retain their existing ownership without becoming a dependency deferral.

Implementation closure: generated `Error.h` was physically reread and matches Section 22; generated `Error.cpp` contains the exact UID0002HO constructor after UID00008V. The historical absent-header question is therefore closed in the implemented artifact, not merely by proposed source.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

These exact manual rows are preserved as the dated supervisor-owned handoff text. The supervisor reports that M01-M11 were applied and validated on 2026-08-14 under commands `000000023527` through `000000023531`; B004 did not edit or reread those coverage files during this narrow repair. Generated `-ag-*` files are not manual destinations. Per the explicit repair requirement, the eleven supervisor-only claim/checklist rows remain unchecked/proposed rather than being recertified by B004.

- M01 / C0000IW-112, `by-file/-coverage-report.md`, replace UID0000IW:

`- [UID:0000IW][DirectX](by-file/DirectX.md) : reconstructable : 92% : very-strong : Source-complete NexusTK/render/DirectX.cpp plus required DirectX.h; fresh RTTI proves direct LObject and empty Singleton<DirectX> bases, 0x8 EBO layout, public m_pDirectDraw at +0x4, sole g_pDirectX definition with explicit Singleton specializations, exact constructor/destructor source, compiler-covered deleting/EH/vtable/RTTI data, literal/GUID dependencies, atomic callers/callees/xrefs/padding, ordered emitters, and a coordinated generated Error.h route with exact Error/MyError declarations and support methods.`

- M02 / C0000IW-113, `by-class/-coverage-report.md`, replace UID00003Y:

`- [UID:00003Y][DirectX](by-class/DirectX.md) : reconstructable : 92% : very-strong : Source-complete 0x8 DirectX declaration assigned to [UID:0000IW][DirectX](by-file/DirectX.md), with direct LObject and Singleton<DirectX> bases, empty-base overlap with public LPDIRECTDRAW m_pDirectDraw at +0x4, complete guarded DirectX.h, extern g_pDirectX, exact lifecycle methods, ordered child emission, and compiler-covered vtable/RTTI/deleting/EH artifacts.`

- M03 / C0000IW-114, `by-global/-coverage-report.md`, replace UID0000QS:

`- [UID:0000QS][g_pDirectX](by-global/g_pDirectX.md) : reconstructable : 92% : very-strong : Sole zero-initialized DirectX pointer definition plus explicit Singleton<DirectX> constructor/destructor specializations, with exact 0x0067ab20 storage, 19-reference lifecycle/consumer closure, empty-base pointer adjustment, class-child source position 0, one header extern, and rejection of manual DirectX-method writes, generic template storage, duplicate physical-child definition, and consumer ownership.`

- M04 / C0000IW-115, `by-memory/-coverage-report.md`, replace UID000137:

`    - [UID:000137][0x004a1b60-0x004a1d6a.DirectX](by-memory/0x004a1b60-0x004a1d6a.DirectX.md) : reconstructable : 92% : very-strong : Complete DirectX code cluster with exact constructor and ordinary destructor source, out-of-line Singleton<DirectX> destructor specialization at 0x004a1cc0, compiler-covered scalar deleting destructor and far EH, four modeled functions, five padding boundaries, DirectDraw/MyError dependencies, exact failure literal and IID routes, and removal of stale manual g_pDirectX writes.`

- M05 / C0000IW-116, `by-memory/-coverage-report.md`, replace UID0002MD:

`      - [UID:0002MD][0x00618e60-0x00618e70.DirectXVtableData](by-memory/0x00618e60-0x00618e70.DirectXVtableData.md) 0x00618e60-0x00618e70 | vtable | DirectXVtableData : reconstructable : 92% : very-strong : Exact DirectX COL pointer and three-slot vtable with scalar deleting destructor and inherited LObject slots, three vptr stores, complete DirectX/LObject/Singleton<DirectX> RTTI graph, diagnostic successor boundary, direct class ownership, and compiler-covered source marker at class-child position 2.`

- M06 / C0000IW-117, `by-memory/-coverage-report.md`, insert after UID0002MD because UID0003AY is absent:

`      - [UID:0003AY][0x00618e70-0x00618efc.DirectXDiagnosticString](by-memory/0x00618e70-0x00618efc.DirectXDiagnosticString.md) 0x00618e70-0x00618efc | string data | DirectXDiagnosticString : reconstructable : 92% : very-strong : Exact UTF-16 DirectX installation/corruption diagnostic with true start, EmployeeDialog RTTI successor boundary, both constructor failure xrefs, and formal covered-by disposition through the two MyError throw literals rather than standalone static data.`

- M07 / C0000IW-118, `by-memory/-coverage-report.md`, replace UID000295:

`    - [UID:000295][0x0067ab20-0x0067ab24.g_pDirectX](by-memory/0x0067ab20-0x0067ab24.g_pDirectX.md) 0x0067ab20-0x0067ab24 | global pointer | g_pDirectX : reconstructable : 92% : very-strong : Exact zero-initialized four-byte DirectX singleton storage with 19 xrefs, constructor publication and destructor/unwind/deleting-wrapper clears explained by Singleton<DirectX> specializations, adjacent singleton boundaries, semantic-global sole-definition ownership, and formal covered-by marker preventing duplicate storage source.`

- M08 / C0000IW-119, `by-type/by-vtable/-coverage-report.md`, replace UID0003HP:

`- [UID:0003HP][DirectXVtable](by-type/by-vtable/DirectXVtable.md) : reconstructable : 92% : very-strong : Source-local DirectX virtual layout routed to [UID:00003Y][DirectX](by-class/DirectX.md), with exact COL-inclusive data, three slots, vptr stores, full LObject plus Singleton<DirectX> RTTI hierarchy, compiler-covered deletion/vtable policy, and diagnostic successor boundary.`

- M09 / C0000IW-175, `by-file/-coverage-report.md`, replace the physically read UID0000J5 row:

`- [UID:0000J5][Error](by-file/Error.md) : reconstructable : 89% : very-strong : Shared NexusTK/util/Error.cpp plus required Error.h source root; DirectX-associated closure supplies the complete guarded Error/MyError declarations, exact MyError constructor/formatter/ordinary destructor, Error::GetErrorName, inline Error::~Error source cause for the compiler-generated 0x004a68e0 scalar deleting wrapper, explicit no-duplicate treatment for 0x004a6a10, exact layout/vtable routes, and generated Error.h verification while broader sibling formatters retain their existing owners.`

- M10 / C0000IW-176, `by-class/-coverage-report.md`, replace the physically read UID00004J row:

`- [UID:00004J][Error](by-class/Error.md) : reconstructable : 90% : very-strong : Complete source-facing Error declaration attached to Error.cpp, with guarded Error.h ownership for Error and MyError, exact 0x4/0x8 layouts and five-slot virtual contract, inline empty virtual Error::~Error source cause for compiler-generated scalar deleting wrapper [0x004a68e0,0x004a691e), sole base-vtable route, exact teardown/delete/guard callees, and Error::GetErrorName returning L"Error".`

- M11 / C0000IW-177, `by-class/-coverage-report.md`, replace the physically read UID00008V row:

`- [UID:00008V][MyError](by-class/MyError.md) : reconstructable : 91% : very-strong : Complete heap-message Error.cpp class route with declaration supplied once by Error.h, exact MyError constructor payload, m_messageText at +0x04, exact wcscpy_s formatter [0x004a6840,0x004a6858), ordinary array-owning destructor [0x004a6860,0x004a6882), compiler-only scalar deleting wrapper 0x004a6a10, PasswordError inheritance context, and no duplicate H or wrapper CPP.`

B004 must not apply or independently recertify these because manual coverage is supervisor-owned and explicitly forbidden. M01-M11 are eleven independent operations with exact one-to-one C0000IW-112 through C0000IW-119 and C0000IW-175 through C0000IW-177 ledger/checklist authority; retired C0000IW-031 has no aggregate authority. Their dated supervisor application/validation receipts are recorded above while their report control rows remain unchecked/proposed as instructed.

## Follow-Up Actions

- Artifact review authority is determined by the report's current path plus validator-owned lifecycle/status metadata; the review should check sections, parity, evidence, formal source, scores, exact manual text, and the report-only boundary.
- Any later implementation authority is explicit and destination-scoped. B004 leases each accepted ordinary page immediately before editing and releases it immediately afterward.
- Any later validation uses the scoped validator per changed page, one coherent refresh, and physical DirectX.cpp/H plus util/Error.h comparison against inventory/order/formal source.
- Section 21 remains a declarative supervisor-owned IDA handoff; B004 remains read-only unless a separately authorized role changes that boundary. The repaired I09/I10 route is complete and nondeferred: no standalone type declaration, expected zero-row numbered-type preflight, then one self-contained four-byte DirectX-pointer `make_data` action with immediate item-level public readback.
- Manual/generated closure remains with its owning supervisor/process.
- The associated support allocation includes the exact Error/MyError destinations in Section 25 together with accepted DirectX destinations; no A/C-agent handoff exists.
- Ordinary callback work is complete, and this corrected artifact is submitted for fresh Gate 1 review. The authoritative current result exists only in `tools/leaser/Agents/b-report-validation-audit.md`; when that ledger authorizes continuation, the supervisor control rows remain exactly C0000IW-110, C0000IW-111, C0000IW-150 through C0000IW-161, C0000IW-187, C0000IW-112 through C0000IW-119, C0000IW-175 through C0000IW-177, and lifecycle row C0000IW-034. M01-M11 have dated supervisor application/validation receipts but remain proposed in this B004 artifact per the explicit repair instruction; B004 does not infer lifecycle closure from those receipts.

## Confidence

- Recommendation: high, about 94%.
- Score: high for `92/94` after authorized implementation and generated verification.
- Strongest facts: RTTI graph, local/far/padding inventory, global xrefs, vtable/literal/GUID, Singleton precedent, exact Error constructor identity, and checked `0x004a68e0` body/hash/xref/callee closure.
- Remaining uncertainty is limited to original text/access/guard/inlining tokens and absent PDB evidence. Error.h is resolved by the scoped formal support source and later generated-file verification, not deferred research.
- Implementation confidence remains about 94%: all 137 ordinary active claims have destination proof and generated source parity; only the explicitly supervisor-owned operations and bounded original-token uncertainty remain.
- Corrected IDA-handoff confidence is high: fresh live prestate, the A05 item probe, the failed-forward-declaration evidence, and public MCP implementation behavior support fourteen ordered mutations plus the read-only I09 gate. This corrected artifact is submitted for fresh Gate 1 review; the authoritative current result and any resulting Gate 2 eligibility exist only in `tools/leaser/Agents/b-report-validation-audit.md`.

## Validator Results

- Historical Gate 1 result: no validator ran during report-only research; command `000000023186` remained incomplete with wrong DirectX bases/source cause/access/order, an empty marker, absent DirectX.h, and absent util/Error.h.
- Same-report Gate 2B repair: no validator was run, no generated file changed, and no IDA mutation or save was made by B004. Read-only public endpoint/source inspection proved why forward-declaration parser success is not numbered-type readback and replaced the failed I09/I10 contract with the exact no-`declare_type` preflight and self-contained `make_data`/`inspect_items` sequence.
- Historical supervisor validation fact (2026-08-14): manual coverage M01-M11 was applied and validated under commands `000000023527` through `000000023531`. Per the current repair instruction, all supervisor-only ledger/checklist rows remain unchecked/proposed; B004 did not rerun, edit, or independently recertify those coverage files.
- Historical supervisor Gate 2B fact (2026-08-14): A01-A08/P01-P23 and all eight hashes matched; I01-I08 passed transiently; I09 failed its required public readback; I10-I15 were not called; no save occurred; the partial worker was discarded; clean recovery reopened unchanged disk state.
- Implementation callback scoped receipts, all `ok:1`:

| Command ID | Timestamp (`-04:00`) | Scoped destination | Result |
| --- | --- | --- | --- |
| `000000023265` | `2026-08-14T02:50:15` | `by-class/DirectX.md` | pass |
| `000000023266` | `2026-08-14T02:51:27` | `by-global/g_pDirectX.md` | pass |
| `000000023267` | `2026-08-14T02:52:16` | `by-memory/0x0067ab20-0x0067ab24.g_pDirectX.md` | pass |
| `000000023268` | `2026-08-14T02:55:14` | `by-memory/0x004a1b60-0x004a1d6a.DirectX.md` | pass |
| `000000023269` | `2026-08-14T02:55:57` | `by-memory/0x00618e60-0x00618e70.DirectXVtableData.md` | pass |
| `000000023270` | `2026-08-14T02:56:41` | `by-type/by-vtable/DirectXVtable.md` | pass |
| `000000023272` | `2026-08-14T02:57:24` | `by-memory/0x00618e70-0x00618efc.DirectXDiagnosticString.md` | pass |
| `000000023273` | `2026-08-14T02:57:59` | `by-memory/0x00618e50-0x00618efc.DirectXBitmapReadOnlyData.md` | pass |
| `000000023277` | `2026-08-14T03:00:50` | `by-file/DirectX.md` | pass |
| `000000023280` | `2026-08-14T03:02:22` | `by-class/Error.md` | pass |
| `000000023283` | `2026-08-14T03:03:25` | `by-class/MyError.md` | pass; initial assembly check exposed missing child marker |
| `000000023285` | `2026-08-14T03:04:05` | `by-memory/0x004a67a0-0x004a683d.MyErrorConstructor.md` | pass |
| `000000023287` | `2026-08-14T03:05:01` | `by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md` | pass |
| `000000023289` | `2026-08-14T03:06:22` | `by-memory/0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers.md` | pass |
| `000000023294` | `2026-08-14T03:06:58` | `by-memory/0x00619340-0x00619448.ErrorHierarchyVtableData.md` | pass |
| `000000023295` | `2026-08-14T03:07:33` | `by-type/by-struct/ErrorObjectLayouts.md` | pass |
| `000000023296` | `2026-08-14T03:08:27` | `by-type/by-vtable/ErrorHierarchyVtables.md` | pass |
| `000000023302` | `2026-08-14T03:09:53` | `by-file/Error.md` | pass |
| `000000023304` | `2026-08-14T03:10:18` | `by-file/DirectX.md --wait-generated` | pass; coherent generated refresh completed |
| `000000023312` | `2026-08-14T03:11:59` | `by-class/MyError.md --wait-generated` | pass; final UID0002HO child assembly completed |

- Physical generated parity: all eight source-bearing formal blocks are contained exactly after CRLF/LF normalization. Ordered DirectX emitter markers are UID00003Y, UID0000QS, UID000295, UID000137, UID0002MD, UID0003AY, UID0003HP; ordered Error source markers are UID00004J, UID00008V, UID0002HO. The four final generated hashes are recorded in Section 16 and below.
- Final report-only script scan checks this report and finds no executable PowerShell, Python, batch, shell, JavaScript, or C# fence/content; CPP/H formal-source fences remain the only executable-language payload authorized by the report.
- Final literal self-check records exactly 33 headings in the required order and 187/187 ledger/checklist eight-field parity. Verification states are exactly `applied:131`, `proposed:27`, `already-present:3`, `excluded-with-reason:26`, and `blocked:0`. Done allocation is 160 checked completed/historical rows and 27 unchecked proposed supervisor-only rows. The report has one terminal Gate 1 readiness marker and no active B004 lease after release.

## Changed Files

- Report updated additively: `tools/leaser/Agents/Agent-B004/research/0000IW-DirectX-file-source-quality.md`; its final self-hash is reported externally after release so the artifact does not contain a recursive self-hash.
- Current same-report repair changed only this report. The ordinary documents and validator-owned generated artifacts listed below are preserved implementation-callback history and were not edited or regenerated during this repair.
- Current Gate 2B repair sections changed: `Finalized Report / Current Recommendation`, `Supporting Research`, `Current Target State`, `Executive Recommendation`, `Supervisor Active Recheck`, `Evidence Checked`, `Claim And Incorporation Ledger`, `Positive Evidence Summary`, `IDA MCP Facts`, `Documentation Evidence And IDA Status`, `Negative Evidence Summary`, `IDA Rename / Type / Comment Recommendations`, `Final Recommendation`, `Score And Metadata Recommendation`, `Open Questions With Attempted Resolution`, `Exact Manual Supervisor-Owned Coverage Or Tracker Text`, `Follow-Up Actions`, `Confidence`, `Validator Results`, `Changed Files`, and `Implementation Tracking Checklist`.
- Ordinary documents directly changed and final SHA256:

| Path | SHA256 |
| --- | --- |
| `by-class/DirectX.md` | `4383273BAE9CC6EB6501F4B4C1DCF1A9D05334E73B5898B87F076BA814303BE6` |
| `by-global/g_pDirectX.md` | `71F4CFFCC51C4BEDC3B1E7477C4C2527DD79AC972883C342A2395598216AB560` |
| `by-memory/0x0067ab20-0x0067ab24.g_pDirectX.md` | `0F202A41A18E9C50C4AF5684490C45A8020C0F339C03072FE520FF498ACEAECC` |
| `by-memory/0x004a1b60-0x004a1d6a.DirectX.md` | `A2648B40C6098A25915272EAA5CA780491CC77A82579DB717411612E7596E7D3` |
| `by-memory/0x00618e60-0x00618e70.DirectXVtableData.md` | `30B57A1876A0EF2602C7C3449F0345679D1A2E6B1C6439C730EB5E0CEAA2DADF` |
| `by-type/by-vtable/DirectXVtable.md` | `AB88152C2634B89C198E9BF8EB3B090914B31D070A08114011EF2154C7E0B7EE` |
| `by-memory/0x00618e70-0x00618efc.DirectXDiagnosticString.md` | `B57805592DD7028D2A535EF009C60CED52A380C9D7D00A0BE26F388664746F7C` |
| `by-memory/0x00618e50-0x00618efc.DirectXBitmapReadOnlyData.md` | `FAAD9FF9280E0F274AB98A7288C921F24F2B95E6F174728FB2CC9820E9F5E472` |
| `by-file/DirectX.md` | `1B7C8225281FBFDEB10D40BAA7D61E8C20C72BF3386DAD0FE77622C4BEB64172` |
| `by-class/Error.md` | `BDAA850C62B62292C57E6E868234B55391B0C6234A352E3E6DBE88B8D9A476AB` |
| `by-class/MyError.md` | `63AB25A65107556B91BB2F95AACCBA7A188C29C44F24CB02782A3C6051689D7E` |
| `by-memory/0x004a67a0-0x004a683d.MyErrorConstructor.md` | `B9155915D5543F7BD1D43392A48712F3BBAF068BC334EA8DE33FF44D84F8E12F` |
| `by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md` | `5A5B069AC7BB476FEBA2C9F88A330941D75A7813923D541E9962B9A67A336BE7` |
| `by-memory/0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers.md` | `0FBA7428E73F62A355E2BE2A768D3E03918CE69C92DE72685511F6A0DC986528` |
| `by-memory/0x00619340-0x00619448.ErrorHierarchyVtableData.md` | `6DC127910D0A047011EB997CFAE71B758E88BBBD25E930C4CDC2E66D54338D41` |
| `by-type/by-struct/ErrorObjectLayouts.md` | `3968E43895075B66CB8E754525F04FC30128654B7E80EFDAE38D2CB2D4CCEDE9` |
| `by-type/by-vtable/ErrorHierarchyVtables.md` | `6C564BB3953C087049B44E402BBFC93182B1C5A38B0BAAD7D2AA29A4CF1BD207` |
| `by-file/Error.md` | `13373D444AAA31D1A7AEEA88CBD0B938229625B950BAABE236AF6F11A77C94EA` |

- Physically verified without edit: `by-memory/0x00631570-0x00631580.DirectDrawGuidConstant.md` SHA256 `9C9A969903E216FAA389793C9FE59491A500017F33952DF444196F195AF4117F`; `by-type/by-vtable/DIBitmapDirectXVtables.md` SHA256 `B5BCA9DDB309DC994AD9442E864DCDB3490565987E94FDC7EDF1D9520DE63E8C`.
- Validator-owned generated outputs, never manually edited: `NexusTK/render/DirectX.cpp` SHA256 `1BB62A6F09563DCB00104D6BCC99BF39073105FA0F87E5ACFDD142E452846CAF`; `DirectX.h` `96D9A9B616069670488EDF1665F9C2C1DEC24A31644B948592EA22FFC27BF377`; `NexusTK/util/Error.cpp` `7DBAEBC578B08133E06271824D499F8CB0AA96890334A548C2A11E3782234B2F`; `Error.h` `8DC7B65CDF603A3654BAB281324CFBE510154F1BED3F02AD8BE2B675B049EA9E`.
- No manual coverage, generated, tracker, audit, assignment, goal, registry/lifecycle, or unrelated file was edited. No IDA state was mutated. Scoped validators alone performed their authorized generated/registry refresh side effects.
- Lease history: each ordinary destination was leased immediately before its edit/validator batch and released immediately afterward. The report was leased only for this additive update and is released before handoff.
- Lifecycle boundary: execution/archive truth remains supervisor-owned from current path and validator metadata. B004 ran no execute_report variant, lifecycle command, or move.

## Implementation Tracking Checklist

Canonical claim checklist:

| Done | Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| [x] | C0000IW-001 | 0000IW | DirectX remains the sole render compilation-unit owner at NexusTK/render/DirectX.cpp with a required DirectX.h. | High | File grouping, callers, generated consumers, and required complete declaration. | by-file/DirectX.md status, inventory, and source audit | incorporate | applied |
| [x] | C0000IW-002 | 0000IW | DirectX directly inherits LObject and Singleton<DirectX>, is size 0x8, and overlaps the empty Singleton base with m_pDirectDraw at +0x4. | High | Fresh RTTI PMDs, constructor lowering, field accesses, and allocation layout. | by-class/DirectX.md layout and formal H | incorporate | applied |
| [x] | C0000IW-003 | 0000IW | The class formal H must become the complete guarded DirectX.h declaration. | High | Missing generated H and cross-module direct consumers. | by-class/DirectX.md RECONSTRUCTION_H | incorporate | applied |
| [x] | C0000IW-004 | 0000IW | The class formal CPP must include DirectX.h and Error.h then emit ordered children. | High | Required source order and MyError complete-type dependency. | by-class/DirectX.md RECONSTRUCTION_CPP | incorporate | applied |
| [x] | C0000IW-005 | 0000IW | Retired grouped global/specialization source authority; C0000IW-178 through C0000IW-180 are the sole canonical per-definition/method actions. | High | Gate 1 allocation repair and exact three-definition formal block. | report ledger, source allocation, and checklist | historicalize | excluded-with-reason |
| [x] | C0000IW-006 | 0000IW | Exact storage UID000295 must be covered by the semantic global definition rather than define the pointer a second time. | High | One-definition rule and corrected semantic-global route. | by-memory/0x0067ab20-0x0067ab24.g_pDirectX.md formal CPP | incorporate | applied |
| [x] | C0000IW-007 | 0000IW | DirectX constructor initializes both bases and m_pDirectDraw, creates DirectDraw, queries IID_IDirectDraw, and pointer-throws MyError on either failure without manual global writes. | High | Local/far disassembly, calls, literal xrefs, and Singleton source cause. | by-memory/0x004a1b60-0x004a1d6a.DirectX.md formal CPP | incorporate | applied |
| [x] | C0000IW-008 | 0000IW | DirectX destructor releases m_pDirectDraw and nulls it without manual global clear or null guard. | High | Exact destructor and reverse base-destruction semantics. | by-memory/0x004a1b60-0x004a1d6a.DirectX.md formal CPP | incorporate | applied |
| [x] | C0000IW-009 | 0000IW | Function 0x004a1cc0 is the out-of-line Singleton<DirectX> destructor specialization used by constructor unwind, not a standalone DirectX helper. | High | Sole far-EH xref, ECX subobject setup, body, and ordinary inlining. | by-memory DirectX aggregate classification | historicalize | applied |
| [x] | C0000IW-010 | 0000IW | Function 0x004a1cd0 and its far handlers are compiler-generated scalar deleting destructor coverage. | High | Vtable route, flags 1 and 4, delete call, no source-only behavior. | by-memory DirectX aggregate marker policy | incorporate | applied |
| [x] | C0000IW-011 | 0000IW | Exact DirectX vtable data is compiler-covered and needs a nonempty covered-by marker. | High | Four exact dwords and three vptr stores. | by-memory DirectXVtableData formal CPP | incorporate | applied |
| [x] | C0000IW-012 | 0000IW | The diagnostic range is covered by the constructor throw literal and needs no standalone definition. | High | Exact UTF-16 bytes and two ctor xrefs. | by-memory DirectXDiagnosticString formal CPP | incorporate | applied |
| [x] | C0000IW-013 | 0000IW | IID_IDirectDraw at 0x00631570 is external SDK data, not file-owned initialized data. | High | IID type, exact bytes, one QueryInterface xref. | by-memory DirectDrawGuidConstant source disposition | already-present | already-present |
| [x] | C0000IW-014 | 0000IW | Retired grouped RTTI authority; C0000IW-035 through C0000IW-044 are the sole canonical per-object claims. | High | Gate 1 atomicity repair and exact ten-object inventory. | report ledger, inventory, and checklist | historicalize | excluded-with-reason |
| [x] | C0000IW-015 | 0000IW | Retired grouped function/far authority; C0000IW-045 through C0000IW-053 are the sole canonical local/far/no-fifth claims. | High | Gate 1 atomicity repair and exact modeled/far boundaries. | report ledger, inventory, and checklist | historicalize | excluded-with-reason |
| [x] | C0000IW-016 | 0000IW | Retired grouped padding authority; C0000IW-054 through C0000IW-058 are the sole canonical span claims. | High | Gate 1 atomicity repair and exact half-open CC ranges. | report ledger, inventory, and checklist | historicalize | excluded-with-reason |
| [x] | C0000IW-017 | 0000IW | Retired all-xrefs aggregate authority; C0000IW-059 through C0000IW-103 are the sole canonical caller/callee/xref claims. | High | Gate 1 atomicity repair and fresh complete item-level queries. | report ledger, xref inventory, and checklist | historicalize | excluded-with-reason |
| [x] | C0000IW-018 | 0000IW | DirectDrawCreate, QueryInterface, and Release are external COM dependencies, not imported source bodies. | High | IAT 0x0060d024 and indirect calls. | by-file dependency inventory | incorporate | applied |
| [x] | C0000IW-019 | 0000IW | The DirectX.cpp source action must include ../util/Error.h because both MyError allocations require the complete coordinated declaration supplied in Section 22. | High | Two exact MyError allocation/constructor routes and the C++ complete-type requirement. | by-file/DirectX.md dependency audit | incorporate | applied |
| [x] | C0000IW-020 | 0000IW | m_pDirectDraw should be public because unrelated modules access it directly and no getter/friend family is evidenced. | Medium-high | Surface, GrafPort, ScreenPane routes. | by-class formal H and access rationale | incorporate | applied |
| [x] | C0000IW-021 | 0000IW | Retired grouped five-document child-order authority; C0000IW-138 through C0000IW-145 are the sole canonical class-entry and child-metadata actions. | High | Gate 1 physical-destination allocation repair. | report ledger, source placement, and checklist | historicalize | excluded-with-reason |
| [x] | C0000IW-022 | 0000IW | Generated DirectX.cpp is incomplete due to wrong bases, manual writes, private field, missing includes/H, and empty marker. | High | Physical readback of command 000000023186. | by-file generated-source audit | incorporate | applied |
| [x] | C0000IW-023 | 0000IW | Target file score should become 92/94 after implementation and coherent generated verification. | Medium-high | Whole-file closure plus in-scope Error/MyError header closure, with only bounded original-token uncertainty. | by-file metadata and score rationale | incorporate | applied |
| [x] | C0000IW-024 | 0000IW | DirectX class score should become 92/94 after H, layout, access, and emitter repair. | Medium-high | RTTI/layout and exact formal H plan. | by-class metadata and score rationale | incorporate | applied |
| [x] | C0000IW-025 | 0000IW | Retired grouped global/storage score authority; C0000IW-146 and C0000IW-147 independently allocate the two physical score changes. | Medium-high | Gate 1 physical-destination allocation repair. | report ledger, score section, and checklist | historicalize | excluded-with-reason |
| [x] | C0000IW-026 | 0000IW | DirectX code aggregate should become 92/94 after method and compiler-coverage repair. | Medium-high | Complete local/far inventory and formal methods. | code aggregate metadata | incorporate | applied |
| [x] | C0000IW-027 | 0000IW | Retired grouped vtable-type/data score authority; C0000IW-148 and C0000IW-149 independently allocate the two physical score changes. | Medium-high | Gate 1 physical-destination allocation repair. | report ledger, score section, and checklist | historicalize | excluded-with-reason |
| [x] | C0000IW-028 | 0000IW | DirectX diagnostic child should become 92/94 after covered-by source-literal repair. | Medium-high | Bytes, boundaries, both xrefs. | by-memory DirectXDiagnosticString | incorporate | applied |
| [x] | C0000IW-029 | 0000IW | Prior manual-global and pure-helper conclusions must remain historical and superseded. | High | Fresh RTTI/Singleton contradiction. | by-file/DirectX.md historical notes | reject-stale | applied |
| [x] | C0000IW-030 | 0000IW | Retired original grouped IDA authority; C0000IW-110-C0000IW-111 and C0000IW-150-C0000IW-161 are the sole canonical atomic mutation claims. | High | Gate 1 allocation repair and exact eight-entity/fourteen-action handoff. | report ledger, Section 21, and checklist | historicalize | excluded-with-reason |
| [x] | C0000IW-031 | 0000IW | Retired grouped manual-coverage authority; C0000IW-112-C0000IW-119 and C0000IW-175-C0000IW-177 are the sole canonical per-operation claims. | High | Gate 1 allocation repair and exact eleven supervisor-only operations. | report ledger, Section 28, and checklist | historicalize | excluded-with-reason |
| [x] | C0000IW-032 | 0000IW | DIBitmap predecessor, EmployeeDialog successor, Application policy, and render consumers are excluded as DirectX source. | High | Boundaries and consumer-only roles. | by-file/DirectX.md exclusions | reject-invalid | applied |
| [x] | C0000IW-033 | 0000IW | No third-party import directive or resource child belongs to this module. | High | Dependency/resource searches show SDK use only. | by-file dependency audit | not-applicable | excluded-with-reason |
| [ ] | C0000IW-034 | 0000IW | Only this report changes in report-only work and lifecycle actions remain supervisor-owned. | High | Assignment boundary, lease, changed-file readback. | report Changed Files and checklist | incorporate | proposed |
| [x] | C0000IW-035 | 0000IW | RTTI COL 0x0064681c-0x00646830 is compiler-generated DirectX support linking vtable prelude 0x00618e60, type descriptor 0x00675be0, and CHD 0x00646830. | High | Fresh item/byte/link readback. | by-class/DirectX.md RTTI evidence | incorporate | applied |
| [x] | C0000IW-036 | 0000IW | RTTI CHD 0x00646830-0x00646840 is compiler-generated and records count 3 with BCA 0x00646840. | High | Fresh CHD fields and direct link. | by-class/DirectX.md RTTI evidence | incorporate | applied |
| [x] | C0000IW-037 | 0000IW | RTTI BCA 0x00646840-0x00646850 lists DirectX BCD 0x00646850, existing LObject BCD 0x00640348, and Singleton BCD 0x0064686c. | High | Fresh three-entry BCA readback. | by-class/DirectX.md RTTI evidence | incorporate | applied |
| [x] | C0000IW-038 | 0000IW | DirectX self BCD 0x00646850-0x0064686c is compiler-generated with PMD {0,-1,0}. | High | Fresh BCD field readback. | by-class/DirectX.md layout evidence | incorporate | applied |
| [x] | C0000IW-039 | 0000IW | Singleton<DirectX> base BCD 0x0064686c-0x00646888 is compiler-generated with PMD {+4,-1,0}, type 0x00675bf8, and CHD 0x00646888. | High | Fresh BCD/PMD/link readback. | by-class/DirectX.md inheritance evidence | incorporate | applied |
| [x] | C0000IW-040 | 0000IW | Singleton<DirectX> CHD 0x00646888-0x00646898 is compiler-generated hierarchy support. | High | Fresh range and link readback. | by-class/DirectX.md RTTI evidence | incorporate | applied |
| [x] | C0000IW-041 | 0000IW | Singleton<DirectX> BCA 0x00646898-0x006468a0 is compiler-generated and points to self BCD 0x006468a0. | High | Fresh BCA pointer readback. | by-class/DirectX.md RTTI evidence | incorporate | applied |
| [x] | C0000IW-042 | 0000IW | Singleton<DirectX> self BCD 0x006468a0-0x006468bc is compiler-generated with self PMD {0,-1,0}. | High | Fresh BCD field readback. | by-class/DirectX.md RTTI evidence | incorporate | applied |
| [x] | C0000IW-043 | 0000IW | DirectX type descriptor 0x00675be0-0x00675bf8 is compiler-generated and names .?AVDirectX@@. | High | Fresh descriptor bytes/name and COL link. | by-class/DirectX.md RTTI evidence | incorporate | applied |
| [x] | C0000IW-044 | 0000IW | Singleton<DirectX> type descriptor 0x00675bf8-0x00675c20 is compiler-generated and names .?AV?$Singleton@VDirectX@@@@. | High | Fresh descriptor bytes/name and BCD link. | by-class/DirectX.md RTTI evidence | incorporate | applied |
| [x] | C0000IW-045 | 000137 | Function 0x004a1b60-0x004a1c56 is the sole DirectX source constructor body. | High | Fresh modeled extent, disassembly, one caller, and source calls. | by-memory/0x004a1b60-0x004a1d6a.DirectX.md function inventory | incorporate | applied |
| [x] | C0000IW-046 | 000137 | Function 0x004a1c60-0x004a1cbc is the DirectX ordinary destructor body. | High | Fresh modeled extent, Release path, base teardown, and no direct caller. | by-memory/0x004a1b60-0x004a1d6a.DirectX.md function inventory | incorporate | applied |
| [x] | C0000IW-047 | 000137 | Function 0x004a1cc0-0x004a1ccb is the out-of-line Singleton<DirectX> destructor specialization used by constructor unwind. | High | Exact two-instruction body and sole inbound xref 0x005fd71e. | by-memory DirectX aggregate function inventory | incorporate | applied |
| [x] | C0000IW-048 | 000137 | Function 0x004a1cd0-0x004a1d6a is compiler-generated DirectX scalar-deleting-destructor coverage. | High | Fresh extent, vtable inbound route, flags, destruction, and optional delete. | by-memory/0x004a1b60-0x004a1d6a.DirectX.md function inventory | incorporate | applied |
| [x] | C0000IW-049 | 000137 | Far range 0x005fd710-0x005fd750 is constructor EH/unwind support and emits no handwritten body. | High | Fresh disassembly of base cleanup, Singleton cleanup, allocation cleanup, cookie, and frame handler. | by-memory DirectX aggregate far inventory | incorporate | applied |
| [x] | C0000IW-050 | 000137 | Far range 0x005fd754-0x005fd76b is destructor SEH/cookie/frame-handler support and emits no handwritten body. | High | Fresh destructor disassembly and range boundary. | by-memory DirectX aggregate far inventory | incorporate | applied |
| [x] | C0000IW-051 | 000137 | Far range 0x005f6800-0x005f6817 is scalar-wrapper SEH/cookie/frame-handler support and emits no handwritten body. | High | Fresh scalar-wrapper disassembly and range boundary. | by-memory DirectX aggregate far inventory | incorporate | applied |
| [x] | C0000IW-052 | 000137 | Far thunk at 0x005c91f2 is scalar-wrapper terminate support and emits no handwritten DirectX body. | High | Fresh jump-to-_terminate disassembly. | by-memory DirectX aggregate far inventory | incorporate | applied |
| [x] | C0000IW-053 | 000137 | No fifth DirectX function exists between predecessor end 0x004a1b5e and successor start 0x004a1d70. | High | Fresh function listing, exact four extents, padding bytes, and successor lookup. | by-memory DirectX aggregate function inventory | incorporate | applied |
| [x] | C0000IW-054 | 000137 | Padding `[0x004a1b5e,0x004a1b60)` is the two-byte CC boundary after DIBitmap and before the DirectX constructor. | High | Raw bytes and predecessor/constructor boundaries. | by-memory DirectX aggregate padding inventory | incorporate | applied |
| [x] | C0000IW-055 | 000137 | Padding `[0x004a1c56,0x004a1c60)` is the ten-byte CC boundary between DirectX constructor and destructor. | High | Raw bytes and both modeled extents. | by-memory DirectX aggregate padding inventory | incorporate | applied |
| [x] | C0000IW-056 | 000137 | Padding `[0x004a1cbc,0x004a1cc0)` is the four-byte CC boundary between DirectX destructor and Singleton destructor specialization. | High | Raw bytes and both modeled extents. | by-memory DirectX aggregate padding inventory | incorporate | applied |
| [x] | C0000IW-057 | 000137 | Padding `[0x004a1ccb,0x004a1cd0)` is the five-byte CC boundary between Singleton destructor specialization and scalar wrapper. | High | Raw bytes and both modeled extents. | by-memory DirectX aggregate padding inventory | incorporate | applied |
| [x] | C0000IW-058 | 000137 | Padding `[0x004a1d6a,0x004a1d70)` is the six-byte CC boundary between the scalar wrapper and EmployeeDialog successor. | High | Raw bytes and scalar/successor boundaries. | by-memory DirectX aggregate padding inventory | incorporate | applied |
| [x] | C0000IW-059 | 000137 | DirectX constructor has one inbound call at 0x004645aa from Application__Startup. | High | Fresh xref query total and caller function. | by-memory DirectX aggregate direct-xref inventory | incorporate | applied |
| [x] | C0000IW-060 | 000137 | DirectX constructor calls LObject_constructor at 0x004a1b8c -> 0x004f4a80. | High | Fresh disassembly direct call. | by-memory DirectX aggregate callee inventory | incorporate | applied |
| [x] | C0000IW-061 | 000137 | DirectX constructor calls DirectDrawCreate at 0x004a1bcb -> 0x005c5c87/IAT 0x0060d024. | High | Fresh disassembly and import route. | by-memory DirectX aggregate callee inventory | incorporate | applied |
| [x] | C0000IW-062 | 000137 | DirectX constructor performs the IDirectDraw QueryInterface indirect call at 0x004a1be0 using object vslot +0x00. | High | Fresh disassembly and argument setup. | by-memory DirectX aggregate callee inventory | incorporate | applied |
| [x] | C0000IW-063 | 000137 | Retired grouped allocation-callee authority; C0000IW-132 and C0000IW-133 are the sole canonical per-callsite claims. | High | Gate 1 atomicity repair and exact two allocation callsites. | report ledger, xref inventory, and checklist | historicalize | excluded-with-reason |
| [x] | C0000IW-064 | 000137 | Retired grouped MyError-callee authority; C0000IW-134 and C0000IW-135 are the sole canonical per-callsite claims. | High | Gate 1 atomicity repair and exact two constructor callsites. | report ledger, xref inventory, and checklist | historicalize | excluded-with-reason |
| [x] | C0000IW-065 | 000137 | DirectX constructor converges both failure branches on __CxxThrowException at 0x004a1c51 -> 0x005ca20a. | High | Fresh disassembly and MyError throw-info route. | by-memory DirectX aggregate callee inventory | incorporate | applied |
| [x] | C0000IW-066 | 000137 | Constructor far cleanup 0x005fd713 tail-jumps to LObject_destructor 0x004f4a90. | High | Fresh far disassembly. | by-memory DirectX aggregate far/xref inventory | incorporate | applied |
| [x] | C0000IW-067 | 000137 | Constructor far cleanup 0x005fd71e tail-jumps to Singleton<DirectX> destructor specialization 0x004a1cc0. | High | Fresh far disassembly and sole inbound xref. | by-memory DirectX aggregate far/xref inventory | incorporate | applied |
| [x] | C0000IW-068 | 000137 | Retired grouped far-cleanup-callee authority; C0000IW-136 and C0000IW-137 are the sole canonical per-callsite claims. | High | Gate 1 atomicity repair and exact two cleanup callsites. | report ledger, xref inventory, and checklist | historicalize | excluded-with-reason |
| [x] | C0000IW-069 | 000137 | DirectX destructor invokes IDirectDraw::Release indirectly at 0x004a1c91 through vslot +0x08. | High | Fresh destructor disassembly. | by-memory DirectX aggregate callee inventory | incorporate | applied |
| [x] | C0000IW-070 | 000137 | DirectX destructor calls LObject_destructor at 0x004a1ca7 -> 0x004f4a90 after Singleton clear lowering. | High | Fresh destructor disassembly. | by-memory DirectX aggregate callee inventory | incorporate | applied |
| [x] | C0000IW-071 | 000137 | DirectX destructor has no direct code caller and is reached virtually through the DirectX vtable. | High | Fresh caller count zero plus vtable slot route. | by-memory DirectX aggregate caller inventory | incorporate | applied |
| [x] | C0000IW-072 | 000137 | Singleton<DirectX> destructor specialization 0x004a1cc0 has exactly one inbound code xref at 0x005fd71e. | High | Fresh complete xref query. | by-memory DirectX aggregate caller inventory | incorporate | applied |
| [x] | C0000IW-073 | 000137 | DirectX scalar wrapper 0x004a1cd0 has one inbound data route from vtable slot 0x00618e64. | High | Fresh complete xref query and vtable bytes. | by-memory DirectX aggregate caller inventory | incorporate | applied |
| [x] | C0000IW-074 | 000137 | DirectX scalar wrapper invokes IDirectDraw::Release indirectly at 0x004a1d08 through vslot +0x08. | High | Fresh scalar-wrapper disassembly. | by-memory DirectX aggregate callee inventory | incorporate | applied |
| [x] | C0000IW-075 | 000137 | DirectX scalar wrapper calls LObject_destructor at 0x004a1d1e -> 0x004f4a90. | High | Fresh scalar-wrapper disassembly. | by-memory DirectX aggregate callee inventory | incorporate | applied |
| [x] | C0000IW-076 | 000137 | DirectX scalar wrapper conditionally calls NexusTK_operator_delete_wrapper at 0x004a1d2f -> 0x004f4ac0. | High | Fresh scalar-wrapper disassembly and flags path. | by-memory DirectX aggregate callee inventory | incorporate | applied |
| [x] | C0000IW-077 | 000137 | DirectX scalar wrapper flag-4 path calls _guard_check_icall_nop at 0x004a1d4e -> 0x0041b6a0. | High | Fresh scalar-wrapper disassembly. | by-memory DirectX aggregate callee inventory | incorporate | applied |
| [x] | C0000IW-078 | 000137 | DirectX scalar-wrapper far thunk 0x005c91f2 tail-jumps to _terminate 0x005dce60. | High | Fresh far disassembly. | by-memory DirectX aggregate far/callee inventory | incorporate | applied |
| [x] | C0000IW-079 | 0000QS | g_pDirectX xref 0x00464b44 is an Application__Shutdown read. | High | Fresh exact global xref row. | by-global/g_pDirectX.md xref inventory | incorporate | applied |
| [x] | C0000IW-080 | 0000QS | g_pDirectX xref 0x004a1ba2 publishes the complete DirectX object from the non-null Singleton base path. | High | Fresh exact global xref row and constructor arithmetic. | by-global/g_pDirectX.md lifetime inventory | incorporate | applied |
| [x] | C0000IW-081 | 0000QS | g_pDirectX xref 0x004a1ba9 writes NULL on the null-adjustment branch of inlined Singleton construction. | High | Fresh exact global xref row and constructor branch. | by-global/g_pDirectX.md lifetime inventory | incorporate | applied |
| [x] | C0000IW-082 | 0000QS | g_pDirectX xref 0x004a1c9d clears the pointer during ordinary DirectX destruction. | High | Fresh exact global xref row. | by-global/g_pDirectX.md lifetime inventory | incorporate | applied |
| [x] | C0000IW-083 | 0000QS | g_pDirectX xref 0x004a1cc0 clears the pointer in the out-of-line Singleton destructor specialization. | High | Fresh exact global xref row and exact helper body. | by-global/g_pDirectX.md lifetime inventory | incorporate | applied |
| [x] | C0000IW-084 | 0000QS | g_pDirectX xref 0x004a1d14 clears the pointer in compiler-generated scalar deletion. | High | Fresh exact global xref row. | by-global/g_pDirectX.md lifetime inventory | incorporate | applied |
| [x] | C0000IW-085 | 0000QS | g_pDirectX xref 0x004b8d78 is a render/UI consumer read. | High | Fresh exact global xref row. | by-global/g_pDirectX.md consumer inventory | incorporate | applied |
| [x] | C0000IW-086 | 0000QS | g_pDirectX xref 0x004b92bc is a render/UI consumer read. | High | Fresh exact global xref row. | by-global/g_pDirectX.md consumer inventory | incorporate | applied |
| [x] | C0000IW-087 | 0000QS | g_pDirectX xref 0x004b9800 is a render/UI consumer read. | High | Fresh exact global xref row. | by-global/g_pDirectX.md consumer inventory | incorporate | applied |
| [x] | C0000IW-088 | 0000QS | g_pDirectX xref 0x004bb83f is a render/UI consumer read. | High | Fresh exact global xref row. | by-global/g_pDirectX.md consumer inventory | incorporate | applied |
| [x] | C0000IW-089 | 0000QS | g_pDirectX xref 0x00556b22 is a ScreenPane destructor consumer read. | High | Fresh exact global xref row. | by-global/g_pDirectX.md consumer inventory | incorporate | applied |
| [x] | C0000IW-090 | 0000QS | g_pDirectX xref 0x00556b77 is a second ScreenPane destructor consumer read. | High | Fresh exact global xref row. | by-global/g_pDirectX.md consumer inventory | incorporate | applied |
| [x] | C0000IW-091 | 0000QS | g_pDirectX xref 0x005574a0 is a Surface/GrafPort-family consumer read. | High | Fresh exact global xref row. | by-global/g_pDirectX.md consumer inventory | incorporate | applied |
| [x] | C0000IW-092 | 0000QS | g_pDirectX xref 0x005576d0 is a Surface/GrafPort-family consumer read. | High | Fresh exact global xref row. | by-global/g_pDirectX.md consumer inventory | incorporate | applied |
| [x] | C0000IW-093 | 0000QS | g_pDirectX xref 0x005583d0 is a DirectDraw consumer read. | High | Fresh exact global xref row. | by-global/g_pDirectX.md consumer inventory | incorporate | applied |
| [x] | C0000IW-094 | 0000QS | g_pDirectX xref 0x005586a3 is an InitializeSurfaceRenderCallbacks consumer read. | High | Fresh exact global xref row. | by-global/g_pDirectX.md consumer inventory | incorporate | applied |
| [x] | C0000IW-095 | 0000QS | g_pDirectX xref 0x00558875 is a DirectDraw consumer read. | High | Fresh exact global xref row. | by-global/g_pDirectX.md consumer inventory | incorporate | applied |
| [x] | C0000IW-096 | 0000QS | g_pDirectX xref 0x00558b24 is a second read in the 0x00558840 DirectDraw consumer. | High | Fresh exact global xref row. | by-global/g_pDirectX.md consumer inventory | incorporate | applied |
| [x] | C0000IW-097 | 0000QS | g_pDirectX xref 0x00559a63 is the final exact DirectDraw consumer read. | High | Fresh exact global xref row; query total is 19 with no continuation. | by-global/g_pDirectX.md consumer inventory | incorporate | applied |
| [x] | C0000IW-098 | 0002MD | DirectX vtable xref 0x004a1bbf installs 0x00618e64 during construction. | High | Fresh exact vptr-store disassembly. | by-memory DirectXVtableData xref inventory | incorporate | applied |
| [x] | C0000IW-099 | 0002MD | DirectX vtable xref 0x004a1c88 restores 0x00618e64 during ordinary destruction. | High | Fresh exact vptr-store disassembly. | by-memory DirectXVtableData xref inventory | incorporate | applied |
| [x] | C0000IW-100 | 0002MD | DirectX vtable xref 0x004a1cf8 restores 0x00618e64 during scalar deletion. | High | Fresh exact vptr-store disassembly. | by-memory DirectXVtableData xref inventory | incorporate | applied |
| [x] | C0000IW-101 | 0003AY | Diagnostic literal xref 0x004a1bfb supplies the QueryInterface-failure MyError message. | High | Fresh exact literal xref and branch disassembly. | by-memory DirectXDiagnosticString xref inventory | incorporate | applied |
| [x] | C0000IW-102 | 0003AY | Diagnostic literal xref 0x004a1c31 supplies the DirectDrawCreate-failure MyError message. | High | Fresh exact literal xref and branch disassembly. | by-memory DirectXDiagnosticString xref inventory | incorporate | applied |
| [x] | C0000IW-103 | 0003OG | IID_IDirectDraw xref 0x004a1bd8 is the sole direct GUID use and feeds QueryInterface. | High | Fresh exact GUID xref query. | by-memory DirectDrawGuidConstant xref inventory | already-present | already-present |
| [x] | C0000IW-104 | 0000IW | Retired A01 two-mutation authority; C0000IW-150 and C0000IW-151 are the sole canonical constructor rename and comment actions. | Medium-high | Gate 1 IDA action-allocation repair. | report ledger, IDA handoff, and checklist | historicalize | excluded-with-reason |
| [x] | C0000IW-105 | 0000IW | Retired A02 two-mutation authority; C0000IW-152 and C0000IW-153 are the sole canonical destructor rename and comment actions. | Medium-high | Gate 1 IDA action-allocation repair. | report ledger, IDA handoff, and checklist | historicalize | excluded-with-reason |
| [x] | C0000IW-106 | 0000IW | Retired A03 two-mutation authority; C0000IW-154 and C0000IW-155 are the sole canonical Singleton-destructor rename and comment actions. | Medium-high | Gate 1 IDA action-allocation repair. | report ledger, IDA handoff, and checklist | historicalize | excluded-with-reason |
| [x] | C0000IW-107 | 0000IW | Retired A04 two-mutation authority; C0000IW-156 and C0000IW-157 are the sole canonical scalar-wrapper rename and comment actions. | Medium-high | Gate 1 IDA action-allocation repair. | report ledger, IDA handoff, and checklist | historicalize | excluded-with-reason |
| [x] | C0000IW-108 | 0000IW | Retired A05 two-mutation rename/comment authority; C0000IW-158, C0000IW-187, and C0000IW-159 are the sole canonical no-standalone-type preflight, self-contained fresh data/type/name action, and comment steps. | Medium-high | Fresh canonical preflight disproved the old symbol; Gate 2B disproved enumerable forward-type readback; the disposable-copy probe established the item-level route. | report ledger, IDA handoff, and checklist | historicalize | excluded-with-reason |
| [x] | C0000IW-109 | 0000IW | Retired A06 two-mutation authority; C0000IW-160 and C0000IW-161 are the sole canonical IID rename and comment actions. | Medium-high | Gate 1 IDA action-allocation repair. | report ledger, IDA handoff, and checklist | historicalize | excluded-with-reason |
| [ ] | C0000IW-110 | 0000IW | IDA action I14 independently adds the exact address-repeatable comment at COL cell 0x00618e60 while preserving name, type, item, xrefs, and 4-byte SHA256. | Medium-high | Fresh literal A07 prestate and SHA256 B474BB52FFB7CCFC2DF90E99C09953CCF65E7E4886858CB13E8E8775584E957A. | Supervisor Gate 2B I14 | incorporate | proposed |
| [ ] | C0000IW-111 | 0000IW | IDA action I15 independently adds the exact address-repeatable comment at literal head 0x00618e70 while preserving split item, name, type, xrefs, and 140-byte SHA256. | Medium-high | Fresh literal A08 prestate and SHA256 538C0281DE2C7CEFCEDC5B949737DD09ED86FD7D7D8FE8B1E8C355E652AD446B. | Supervisor Gate 2B I15 | incorporate | proposed |
| [ ] | C0000IW-112 | 0000IW | Supervisor-only manual coverage operation M01 replaces the UID0000IW by-file row with the exact Section 28 text. | High | Physical manual by-file coverage readback. | by-file/-coverage-report.md UID0000IW | incorporate | proposed |
| [ ] | C0000IW-113 | 00003Y | Supervisor-only manual coverage operation M02 replaces the UID00003Y by-class row with the exact Section 28 text. | High | Physical manual by-class coverage readback. | by-class/-coverage-report.md UID00003Y | incorporate | proposed |
| [ ] | C0000IW-114 | 0000QS | Supervisor-only manual coverage operation M03 replaces the UID0000QS by-global row with the exact Section 28 text. | High | Physical manual by-global coverage readback. | by-global/-coverage-report.md UID0000QS | incorporate | proposed |
| [ ] | C0000IW-115 | 000137 | Supervisor-only manual coverage operation M04 replaces the UID000137 by-memory row with the exact Section 28 text. | High | Physical manual by-memory coverage readback. | by-memory/-coverage-report.md UID000137 | incorporate | proposed |
| [ ] | C0000IW-116 | 0002MD | Supervisor-only manual coverage operation M05 replaces the UID0002MD by-memory row with the exact Section 28 text. | High | Physical manual by-memory coverage readback. | by-memory/-coverage-report.md UID0002MD | incorporate | proposed |
| [ ] | C0000IW-117 | 0003AY | Supervisor-only manual coverage operation M06 inserts the absent UID0003AY by-memory row with the exact Section 28 text. | High | Physical absence in manual by-memory coverage. | by-memory/-coverage-report.md UID0003AY | incorporate | proposed |
| [ ] | C0000IW-118 | 000295 | Supervisor-only manual coverage operation M07 replaces the UID000295 by-memory row with the exact Section 28 text. | High | Physical manual by-memory coverage readback. | by-memory/-coverage-report.md UID000295 | incorporate | proposed |
| [ ] | C0000IW-119 | 0003HP | Supervisor-only manual coverage operation M08 replaces the UID0003HP by-vtable row with the exact Section 28 text. | High | Physical manual by-vtable coverage readback. | by-type/by-vtable/-coverage-report.md UID0003HP | incorporate | proposed |
| [x] | C0000IW-120 | 0000J5 | The Error file support action owns the required NexusTK/util/Error.h generation route; absence in command 000000023186 is historical prestate, not deferred work. | High | Physical generated absence plus fresh Error/MyError IDA and existing hierarchy docs. | by-file/Error.md DirectX support closure and generated audit | incorporate | applied |
| [x] | C0000IW-121 | 00004J | Retired grouped Error CPP/H authority; C0000IW-162 and C0000IW-163 independently allocate the formal H block and GetErrorName CPP action. | High | Gate 1 CPP/H destination allocation repair. | report ledger, source section, and checklist | historicalize | excluded-with-reason |
| [x] | C0000IW-122 | 00008V | Retired grouped MyError CPP/H/method authority; C0000IW-164 through C0000IW-166 independently allocate H, formatter CPP, and destructor CPP actions. | High | Gate 1 CPP/H method allocation repair. | report ledger, source section, and checklist | historicalize | excluded-with-reason |
| [x] | C0000IW-123 | 00008V | MyError::FormatErrorMessage is exactly the 0x004a6840-0x004a6858 wcscpy_s wrapper returning int-compatible errno_t from m_messageText at +0x04. | High | Fresh nine-instruction decompile/disassembly, sole wcscpy_s callee, vtable route. | by-memory ErrorWrappers exact formatter split evidence | incorporate | applied |
| [x] | C0000IW-124 | 00008V | MyError::~MyError is exactly 0x004a6860-0x004a6882, frees m_messageText at +0x04, restores Error vtable state, and tears down LObject. | High | Fresh ten-instruction decompile/disassembly and callees. | by-memory ErrorWrappers exact destructor split evidence | incorporate | applied |
| [x] | C0000IW-125 | 00004J | Error::GetErrorName is exactly 0x004a6a70-0x004a6a76 and returns L"Error" for the common +0x10 slot. | High | Fresh two-instruction decompile/disassembly and vtable evidence. | by-memory ErrorDestructorAndNameHelpers exact GetErrorName row | incorporate | applied |
| [x] | C0000IW-126 | 0002HO | Retired grouped constructor-channel authority; C0000IW-173 and C0000IW-174 independently allocate exact CPP identity and blank-H disposition. | High | Gate 1 constructor CPP/H identity repair. | report ledger, source section, and checklist | historicalize | excluded-with-reason |
| [x] | C0000IW-127 | 00013X | Retired aggregate ErrorWrappers support authority; C0000IW-123 and C0000IW-124 are the sole canonical per-function memory-page actions. | High | Gate 1 expanded-support allocation repair. | report ledger, Error inventory, and checklist | historicalize | excluded-with-reason |
| [x] | C0000IW-128 | 0002TV | The 0x004a6a10 MyError scalar deleting destructor remains compiler-covered by the ordinary 0x004a6860 destructor and must not emit a duplicate source body. | High | Fresh wrapper disassembly, vtable route, free/base/delete paths. | by-memory/0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers.md coverage reconciliation | incorporate | applied |
| [x] | C0000IW-129 | 0002ND | Error/MyError vtable data remains compiler-generated from the new declarations; no raw table source is added. | High | Exact Error and MyError five-slot rows at 0x00619344 and 0x00619434. | by-memory/0x00619340-0x00619448.ErrorHierarchyVtableData.md source-cause reconciliation | incorporate | applied |
| [x] | C0000IW-130 | 0001UE | Error support declarations must preserve sizeof(Error)==0x4 and sizeof(MyError)==0x8 with m_messageText at +0x04. | High | Fresh constructor/formatter/destructor offsets and existing layout family. | by-type/by-struct/ErrorObjectLayouts.md support declaration reconciliation | incorporate | applied |
| [x] | C0000IW-131 | 0001XI | Error support declarations must preserve the five-slot virtual order: destructor, inherited runtime, inherited message-change, FormatErrorMessage, GetErrorName. | High | Exact base/MyError vtable rows and WinMain consumer contract. | by-type/by-vtable/ErrorHierarchyVtables.md support declaration reconciliation | incorporate | applied |
| [x] | C0000IW-132 | 000137 | DirectX constructor QueryInterface-failure allocation site 0x004a1be8 calls NexusTK_operator_new 0x004f4aa0 for one 8-byte MyError object. | High | Fresh exact disassembly at 0x004a1be6-0x004a1bed. | by-memory DirectX aggregate callee inventory | incorporate | applied |
| [x] | C0000IW-133 | 000137 | DirectX constructor DirectDrawCreate-failure allocation site 0x004a1c1e calls NexusTK_operator_new 0x004f4aa0 for one 8-byte MyError object. | High | Fresh exact disassembly at 0x004a1c1c-0x004a1c23. | by-memory DirectX aggregate callee inventory | incorporate | applied |
| [x] | C0000IW-134 | 000137 | DirectX constructor QueryInterface-failure site 0x004a1c02 calls MyError constructor 0x004a67a0. | High | Fresh exact disassembly and Error support readback. | by-memory DirectX aggregate callee inventory | incorporate | applied |
| [x] | C0000IW-135 | 000137 | DirectX constructor DirectDrawCreate-failure site 0x004a1c38 calls MyError constructor 0x004a67a0. | High | Fresh exact disassembly and Error support readback. | by-memory DirectX aggregate callee inventory | incorporate | applied |
| [x] | C0000IW-136 | 000137 | Constructor far cleanup site 0x005fd727 calls NexusTK_operator_delete_wrapper 0x004f4ac0. | High | Fresh exact far disassembly of QueryInterface-failure allocation cleanup. | by-memory DirectX aggregate far/callee inventory | incorporate | applied |
| [x] | C0000IW-137 | 000137 | Constructor far cleanup site 0x005fd732 calls NexusTK_operator_delete_wrapper 0x004f4ac0. | High | Fresh exact far disassembly of DirectDrawCreate-failure allocation cleanup. | by-memory DirectX aggregate far/callee inventory | incorporate | applied |
| [x] | C0000IW-138 | 00003Y | DirectX class assembly must list semantic global UID0000QS as child position 0. | High | Include/specialization-before-method order and emitter graph. | by-class/DirectX.md child assembly entry for UID0000QS | incorporate | applied |
| [x] | C0000IW-139 | 0000QS | g_pDirectX metadata must route through emitter UID00003Y at position 0. | High | Corrected class assembly and source order. | by-global/g_pDirectX.md emitter metadata | incorporate | applied |
| [x] | C0000IW-140 | 00003Y | DirectX class assembly must list code UID000137 as child position 1. | High | Method order after global/specializations. | by-class/DirectX.md child assembly entry for UID000137 | incorporate | applied |
| [x] | C0000IW-141 | 000137 | DirectX code metadata must route through emitter UID00003Y at position 1. | High | Exact method owner and ordered source assembly. | by-memory/0x004a1b60-0x004a1d6a.DirectX.md emitter metadata | incorporate | applied |
| [x] | C0000IW-142 | 00003Y | DirectX class assembly must list vtable-data UID0002MD as child position 2. | High | Compiler-covered marker after methods. | by-class/DirectX.md child assembly entry for UID0002MD | incorporate | applied |
| [x] | C0000IW-143 | 0002MD | DirectX vtable-data metadata must route through emitter UID00003Y at position 2. | High | Exact class source cause and marker order. | by-memory/0x00618e60-0x00618e70.DirectXVtableData.md emitter metadata | incorporate | applied |
| [x] | C0000IW-144 | 00003Y | DirectX class assembly must list diagnostic UID0003AY as child position 3. | High | Literal marker follows vtable marker. | by-class/DirectX.md child assembly entry for UID0003AY | incorporate | applied |
| [x] | C0000IW-145 | 0003AY | DirectX diagnostic metadata must route through emitter UID00003Y at position 3. | High | Exact literal source use and marker order. | by-memory/0x00618e70-0x00618efc.DirectXDiagnosticString.md emitter metadata | incorporate | applied |
| [x] | C0000IW-146 | 0000QS | The semantic g_pDirectX page should become 92/94 after exact global/specialization source and ownership repair. | Medium-high | Singleton lowering, 19 xrefs, and exact formal source. | by-global/g_pDirectX.md score metadata | incorporate | applied |
| [x] | C0000IW-147 | 000295 | The exact g_pDirectX storage page should become 92/94 after covered-by repair. | Medium-high | Exact zero bytes, 19 xrefs, and one-definition route. | by-memory/0x0067ab20-0x0067ab24.g_pDirectX.md score metadata | incorporate | applied |
| [x] | C0000IW-148 | 0003HP | The DirectXVtable semantic type page should become 92/94 after inheritance and compiler-source reconciliation. | Medium-high | Exact slots, RTTI graph, and completed declaration. | by-type/by-vtable/DirectXVtable.md score metadata | incorporate | applied |
| [x] | C0000IW-149 | 0002MD | The exact DirectX vtable-data page should become 92/94 after marker and source-cause repair. | Medium-high | Exact data, vptr stores, RTTI, and class route. | by-memory/0x00618e60-0x00618e70.DirectXVtableData.md score metadata | incorporate | applied |
| [ ] | C0000IW-150 | 0000IW | IDA action I01 pure-renames function 0x004a1b60 from sub_4A1B60 to DirectX__Constructor and changes no other field. | Medium-high | Fresh literal prestate, complete frame, and 246-byte hash 645B88E4E96B0F7A412BA5096EB7DAEE18E8163AB6CEDDB5F887C83BEB70CAEE. | Supervisor Gate 2B I01 | incorporate | proposed |
| [ ] | C0000IW-151 | 0000IW | IDA action I02 sets only the exact function-regular constructor comment at 0x004a1b60. | Medium-high | Empty FR prestate and protected A01 readback. | Supervisor Gate 2B I02 | incorporate | proposed |
| [ ] | C0000IW-152 | 0000IW | IDA action I03 pure-renames function 0x004a1c60 from sub_4A1C60 to DirectX__Destructor and changes no other field. | Medium-high | Fresh literal prestate, complete frame, and 92-byte hash 293CE407F59B697391951ACD0FCECD5807D965C6DBCF6D9604A501FDD023D356. | Supervisor Gate 2B I03 | incorporate | proposed |
| [ ] | C0000IW-153 | 0000IW | IDA action I04 sets only the exact function-regular destructor comment at 0x004a1c60. | Medium-high | Empty FR prestate and protected A02 readback. | Supervisor Gate 2B I04 | incorporate | proposed |
| [ ] | C0000IW-154 | 0000IW | IDA action I05 pure-renames function 0x004a1cc0 from sub_4A1CC0 to Singleton_DirectX__Destructor and changes no other field. | Medium-high | Fresh literal prestate, complete frame, and 11-byte hash E00FE42EBA5658269EE3AC5105DC88398EDD86A2C111FA90F968B2418616D5D7. | Supervisor Gate 2B I05 | incorporate | proposed |
| [ ] | C0000IW-155 | 0000IW | IDA action I06 sets only the exact function-regular Singleton-destructor comment at 0x004a1cc0. | Medium-high | Empty FR prestate and protected A03 readback. | Supervisor Gate 2B I06 | incorporate | proposed |
| [ ] | C0000IW-156 | 0000IW | IDA action I07 pure-renames function 0x004a1cd0 from sub_4A1CD0 to DirectX__ScalarDeletingDestructor and changes no other field. | Medium-high | Fresh literal prestate, complete frame, and 154-byte hash 553D6FD33B5FF374442F50A2D039184431170252AE989712E5E176F9A401500D. | Supervisor Gate 2B I07 | incorporate | proposed |
| [ ] | C0000IW-157 | 0000IW | IDA action I08 sets only the exact function-regular scalar-wrapper comment at 0x004a1cd0. | Medium-high | Empty FR prestate and protected A04 readback. | Supervisor Gate 2B I08 | incorporate | proposed |
| [ ] | C0000IW-158 | 0000IW | IDA step I09 is a read-only public preflight that requires same-database exact-name `type_query` to remain `total:0`, rechecks A05/P05, and explicitly does not call `declare_type`; a forward-declaration parser-success record is not an observable numbered local type. | High | Gate 2B returned apparent `declare_type` success followed by immediate `type_query total:0`; installed public MCP code proves those endpoints use parser-error and numbered-ordinal criteria respectively. | Supervisor Gate 2B I09 | incorporate | proposed |
| [ ] | C0000IW-159 | 0000IW | IDA action I11 sets only the exact address-repeatable g_pDirectX comment at 0x0067ab20 after the fresh data action passes exact readback. | Medium-high | Blank AP prestate plus disposable-copy A05 data readback and protected P05 state. | Supervisor Gate 2B I11 | incorporate | proposed |
| [ ] | C0000IW-160 | 0000IW | IDA action I12 uses public `rename` with exact `batch.data` old/new binding `old:"stru_631570"`, `new:"IID_IDirectDraw"`, first dry-run then apply, and requires the sole result to resolve address `0x00631570` without error or alternate match. | Medium-high | Fresh literal A06 prestate, exact public data-rename schema, sole current symbol match, and 16-byte hash DC3CA51EE680125BA815CBCE6C7C0D8E82F979CD9DF015CA3EC29438487EC5D2. | Supervisor Gate 2B I12 | incorporate | proposed |
| [ ] | C0000IW-161 | 0000IW | IDA action I13 sets only the exact address-repeatable IID_IDirectDraw comment at 0x00631570. | Medium-high | Empty AP prestate and protected A06 readback. | Supervisor Gate 2B I13 | incorporate | proposed |
| [x] | C0000IW-162 | 00004J | The Error class H action emits the single complete guarded Error/MyError declaration block, including inline empty virtual Error destructor and size assertions. | High | Complete-type compile requirement, layout/vtable evidence, and exact Section 22 H. | by-class/Error.md RECONSTRUCTION_H | incorporate | applied |
| [x] | C0000IW-163 | 00004J | The Error class CPP action emits only exact Error::GetErrorName returning L"Error". | High | Fresh exact 0x004a6a70-0x004a6a76 body and vtable slot. | by-class/Error.md RECONSTRUCTION_CPP | incorporate | applied |
| [x] | C0000IW-164 | 00008V | The MyError class H action remains blank because its complete declaration is owned by the coordinated UID00004J Error H block. | High | Single-header ownership and duplicate-declaration avoidance. | by-class/MyError.md RECONSTRUCTION_H disposition | not-applicable | excluded-with-reason |
| [x] | C0000IW-165 | 00008V | The MyError formatter CPP action emits only exact MyError::FormatErrorMessage for [0x004a6840,0x004a6858). | High | Fresh nine-instruction wcscpy_s wrapper and +0x04 field. | by-class/MyError.md RECONSTRUCTION_CPP formatter method | incorporate | applied |
| [x] | C0000IW-166 | 00008V | The MyError destructor CPP action emits only exact MyError::~MyError for [0x004a6860,0x004a6882). | High | Fresh ordinary destructor body, array delete, Error vtable restore, and LObject teardown. | by-class/MyError.md RECONSTRUCTION_CPP destructor method | incorporate | applied |
| [x] | C0000IW-167 | 00004J | Function [0x004a68e0,0x004a691e) is the 62-byte compiler-generated Error scalar deleting destructor caused by inline Error::~Error; it must not receive duplicate handwritten CPP. | High | Fresh 26-instruction disassembly/decompile, type, frame, one vtable route, and SHA256 E8144E5BF8ADF60BD3FE8347E1B3871E3029191871D04A6AFE3B2B4C8BF00B2F. | by-memory/0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers.md exact function row | incorporate | applied |
| [x] | C0000IW-168 | 00004J | Error scalar deleting destructor 0x004a68e0 has exactly one inbound data xref, 0x00619344 -> 0x004a68e0, from the base Error vtable destructor slot and no direct code caller. | High | Fresh complete xref query and exact vtable cell. | by-memory ErrorDestructorAndNameHelpers exact xref row | incorporate | applied |
| [x] | C0000IW-169 | 00004J | Error scalar deleting destructor instruction 0x004a68e6 stores Error::vftable 0x00619344 into the object before inherited teardown. | High | Fresh exact disassembly and data reference. | by-memory ErrorDestructorAndNameHelpers exact data-flow row | incorporate | applied |
| [x] | C0000IW-170 | 00004J | Error scalar deleting destructor callsite 0x004a68ec calls LObject_destructor 0x004f4a90. | High | Fresh exact disassembly and callee query. | by-memory ErrorDestructorAndNameHelpers exact callee row | incorporate | applied |
| [x] | C0000IW-171 | 00004J | Error scalar deleting destructor callsite 0x004a68fd conditionally calls NexusTK_operator_delete_wrapper 0x004f4ac0 when flag bit 1 is set and bit 4 is clear. | High | Fresh exact disassembly/decompile and callee query. | by-memory ErrorDestructorAndNameHelpers exact callee row | incorporate | applied |
| [x] | C0000IW-172 | 00004J | Error scalar deleting destructor callsite 0x004a690f uses _guard_check_icall_nop 0x0041b6a0 for the flag-4 sized-delete path with object size 4. | High | Fresh exact disassembly/decompile and callee query. | by-memory ErrorDestructorAndNameHelpers exact callee row | incorporate | applied |
| [x] | C0000IW-173 | 0002HO | The MyError constructor CPP action preserves the exact eight-line formal payload in Section 22; normalized UTF-8 LF with terminal newline is 222 bytes, SHA256 F3283F846DA3D69C8DF1F97FF2FE06A98B5BAF39A3CA86D1FCD553D1B09B22F5. | High | Physical current formal block plus fresh 157-byte function hash D361B3F2AF84E2EE716E34E77FEB4C493ABD0EE73AEA13CDD0EF0504E719470A. | by-memory/0x004a67a0-0x004a683d.MyErrorConstructor.md RECONSTRUCTION_CPP | already-present | applied |
| [x] | C0000IW-174 | 0002HO | The MyError constructor H action remains blank because the constructor declaration is supplied once by UID00004J Error H. | High | Current blank H and coordinated declaration ownership. | by-memory/0x004a67a0-0x004a683d.MyErrorConstructor.md RECONSTRUCTION_H disposition | not-applicable | excluded-with-reason |
| [ ] | C0000IW-175 | 0000J5 | Supervisor-only manual coverage operation M09 replaces the changed UID0000J5 by-file row with the exact Section 28 text. | High | Physical current manual row at by-file/-coverage-report.md line 86. | by-file/-coverage-report.md UID0000J5 | incorporate | proposed |
| [ ] | C0000IW-176 | 00004J | Supervisor-only manual coverage operation M10 replaces the changed UID00004J by-class row with the exact Section 28 text. | High | Physical current manual row at by-class/-coverage-report.md line 189. | by-class/-coverage-report.md UID00004J | incorporate | proposed |
| [ ] | C0000IW-177 | 00008V | Supervisor-only manual coverage operation M11 replaces the changed UID00008V by-class row with the exact Section 28 text. | High | Physical current manual row at by-class/-coverage-report.md line 344. | by-class/-coverage-report.md UID00008V | incorporate | proposed |
| [x] | C0000IW-178 | 0000QS | The g_pDirectX formal CPP action emits only the sole zero-initialized DirectX pointer definition. | High | ODR, exact storage, and corrected semantic-global ownership. | by-global/g_pDirectX.md RECONSTRUCTION_CPP global definition | incorporate | applied |
| [x] | C0000IW-179 | 0000QS | The Singleton<DirectX> constructor-specialization CPP action emits only publication of static_cast<DirectX *>(this) to g_pDirectX. | High | RTTI PMD +4, constructor lowering, and shared Singleton policy. | by-global/g_pDirectX.md RECONSTRUCTION_CPP constructor method | incorporate | applied |
| [x] | C0000IW-180 | 0000QS | The Singleton<DirectX> destructor-specialization CPP action emits only clearing g_pDirectX to NULL. | High | Ordinary/inlined clear, exact 0x004a1cc0 unwind specialization, and shared Singleton policy. | by-global/g_pDirectX.md RECONSTRUCTION_CPP destructor method | incorporate | applied |
| [x] | C0000IW-181 | 000255 | The mixed DirectXBitmapReadOnlyData page receives only corrected DirectX Singleton/RTTI context and retains its current score, owner, and non-emitting disposition. | High | Exact mixed range plus independently verified DirectX RTTI split. | by-memory/0x00618e50-0x00618efc.DirectXBitmapReadOnlyData.md context | incorporate | applied |
| [x] | C0000IW-182 | 0001XE | The mixed DIBitmapDirectXVtables page retains its current score, owner, and DIBitmap/DirectX split with no source-emitter action. | High | Exact vtable boundaries and separate class ownership. | by-type/by-vtable/DIBitmapDirectXVtables.md no-change disposition | already-present | already-present |
| [x] | C0000IW-183 | 0000J5 | The Error file page may become 89/90 only after the exact coordinated Error.h route and generated verification; broader sibling work receives no score credit. | Medium-high | Complete DirectX-associated support closure with bounded wider-file incompleteness. | by-file/Error.md score metadata | incorporate | applied |
| [x] | C0000IW-184 | 00004J | The Error class page may become 90/92 after exact H/GetErrorName source plus checked 0x004a68e0 compiler-wrapper coverage and generated Error.h verification. | Medium-high | Exact declaration, method, layout/vtable, wrapper hash, xref, and callees. | by-class/Error.md score metadata | incorporate | applied |
| [x] | C0000IW-185 | 00008V | The MyError class page may become 91/93 after exact formatter/destructor source, constructor identity, coordinated-H route, and 0x004a6a10 no-duplicate coverage. | Medium-high | Exact three source methods, layout, vtable, and compiler-wrapper disposition. | by-class/MyError.md score metadata | incorporate | applied |
| [x] | C0000IW-186 | 0002TV | The ErrorDestructorAndNameHelpers aggregate remains 86/90: checked 0x004a68e0 closes classification but adds no handwritten source and does not justify aggregate score inflation. | High | Exact compiler-generated proof for Error and MyError scalar wrappers. | by-memory/0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers.md score metadata | already-present | applied |
| [ ] | C0000IW-187 | 0000IW | IDA action I10 independently calls public `make_data` at 0x0067ab20 with full self-contained declaration `struct DirectX *g_pDirectX`, separate exact name `g_pDirectX`, and `delete_existing:false`; it is the sole type/data/name action and is not a rename. | High | Public implementation parses a full sized declaration before mutation; a pointer to an incomplete `struct DirectX` is four bytes; disposable-copy item readback produced the exact four-byte named DirectX-pointer data state while preserving bytes, blank AR/AP, and all 19 xrefs. | Supervisor Gate 2B I10 | incorporate | proposed |

Initial report-only pass:

- [x] Historical pre-implementation supervisor validation was completed for the prior ordinary callback; this repaired artifact still requires a fresh exact-artifact Gate 1 audit before any remaining supervisor-owned action.
- [x] Historical 2026-08-14 Gate 2B failure is reconciled: predecessor SHA passed Gate 1/Gate 2A; M01-M11 commands are recorded; I01-I08 were transient only; failed I09 was unsaved; I10-I15 were not called; clean recovery restored original state.
- [x] Exhaustive whole-file and associated Error support inventory reconciled against read-only IDA, all related pages, generated output, consumers, and reports, including checked `[0x004a68e0,0x004a691e)`.
- [x] Every owned/excluded item has role, ownership, placement, CPP/H or no-code, metadata, destination, ledger, checklist.
- [x] Generated CPP/H audited and every defect has an exact repair; the absent Error.h dependency is resolved by scoped formal support source.
- [x] Target/support destinations exhaustively listed.
- [x] Additional target check complete: none.
- [x] Current state/evidence recorded.
- [x] Ledger has 187 canonical records with exact eight-field checklist parity: verification states are 131 `applied`, 27 `proposed`, 3 `already-present`, 26 `excluded-with-reason`, and 0 `blocked`; Done allocation is 160 checked and 27 unchecked, with one physical destination or mutation per active allocation claim.
- [x] Scores/metadata/blockers resolved or bounded; no Error.h deferral remains.
- [x] Owner/emitter/split/source/range/padding/reclassification dispositions complete.
- [ ] Gate 2B IDA handoff remains supervisor-unapplied in recovered disk state; I09/I10 now specify the exact no-`declare_type` public sequence and observable item-level success gate.
- [x] Exact DirectX and self-contained Error-support CPP/H/no-code dispositions are complete, including UID0002HO payload identity and both scalar wrappers; no third-party import applies.
- [x] Historical/negative/Wave2/Wave3/open-question handling complete.
- [x] Validator/generated/manual closure plan complete.

Implementation callback pass:

- [ ] Corrected supervisor-owned IDA remains B004-read-only; its current eligibility is determined only by `tools/leaser/Agents/b-report-validation-audit.md`.
- [x] Accepted inventory claims incorporated across every destination.
- [x] Accepted CPP/H/routes applied and coherently generated without incomplete fragments.
- [x] Supervisor accepted implementation callback on Gate 1 SHA256 `CE6CC820F576177B7CC08D12F7FECC4D5CC254A4CF7BFEA6FEFB04302850C525`.
- [x] Primary UID independently verified; no additional UID.
- [x] Ledger states updated with destination proof and exact checklist parity.
- [x] Scores/metadata/owner/emitter/markers/source applied or dispositioned.
- [x] Historical/negative/open-question content preserved.
- [x] Scoped validators and coherent generated refresh recorded.
- [x] DirectX.cpp/H and generated util/Error.cpp/H physically reread against Section 22, including exact UID0002HO payload identity.
- [x] No accepted ordinary item remains blocked; only the exact supervisor-only claims listed in Follow-Up Actions remain unchecked. This corrected artifact is submitted for fresh Gate 1 review, and the authoritative current result exists only in `tools/leaser/Agents/b-report-validation-audit.md`.
- [x] Body is lifecycle-neutral.

READY_FOR_SUPERVISOR_GATE1_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000023535","destination_path":"executed-b-agent-research/B004/0000IW-DirectX-file-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0000IW-DirectX-file-source-quality.md","timestamp":"2026-08-14T13:09:00-04:00","uid":"0000IW"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
