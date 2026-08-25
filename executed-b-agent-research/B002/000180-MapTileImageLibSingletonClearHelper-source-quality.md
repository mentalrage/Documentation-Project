** TARGET-REPORT-UID:000180 **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# 000180 MapTileImageLib Singleton Base Destructor Ownership / Split Research


## Finalized Report / Current Recommendation

- Finalized callback result: the UID-preserving rename from historical path `by-memory/0x004e5bc0-0x004e5bcb.MapTileImageLibSingletonClearHelper.md` to `by-memory/0x004e5bc0-0x004e5bcb.MapTileImageLibSingletonBaseDestructor.md` is applied; the old ordinary path is absent. UID000180 is `93/96`, semantic owner [UID:00007T][MapTileImageLib](by-class/MapTileImageLib.md), `RECONSTRUCTABLE:FALSE`, with blank emitter/position/formal C++ and `Nested:0`.
- Final disposition: UID000180 is the exact out-of-line compiler instantiation of the source-declared `Singleton<MapTileImageLib>` base destructor used only by `MapTileImageLib` constructor exception unwinding. It is not a free/static clear API, a `MapTileImageLib` member method, an `atexit` callback, or an independent handwritten cleanup operation.
- Applied source route: direct `Singleton<MapTileImageLib>` inheritance, constructor base initialization, typed singleton storage, and implicit reverse-order base destruction now represent the behavior. Explicit `g_pMapTileImageLib` writes are absent from the constructor/destructor bodies, and UID0000RG remains the one typed source definition.
- Confidence: very strong for identity, bytes, range, unique signature, constructor EH state, direct RTTI base identity, PMD `+0x04`, empty-base overlap, ordinary/scalar copies, startup/shutdown lifetime, non-emission, and rename. Exact historical template-header filename, template static-member spelling, and original global spelling are not recovered and cap lexical confidence only.

## Supporting Research

- Assignment source at research time: `tools/leaser/Agents/Agent-B002/goal.md`, report-only UID000180 pass, required provenance `CHATGPT | 5.6 | xHigh`. The later exact-artifact Gate 1 acceptance authorized this bounded implementation callback.
- Evidence-time queue snapshot: `auto-generated/-ag-research-tracker.md` reported UID000180 at `86/90`, reconstructable `true`, reports `0`; this is historical tracker evidence, not a current tracker assertion.
- Mandatory MCP evidence was collected from evidence-time NexusTK database session `2625e5c6` through streamable endpoint `http://127.0.0.1:13337/mcp`. Evidence-collection-time health was `ok`, with auto-analysis, Hex-Rays, and string cache ready. These are evidence-time observations, not a claim of future session availability.
- Binary identity from `survey_binary` JSON-RPC id `130`: NexusTK.exe, x86, image base `0x00400000`, image size `0x002b3000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, SHA256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
- The target, class, file, global, storage, constructor, ordinary destructor, scalar deleting destructor, layout, vtable, aggregate, Application startup/shutdown, generated C++, generated tracker, and every affected manual coverage row were read during research and re-read during callback verification.
- Existing B003/B011/B015 conclusions were treated as historical leads, not authority. Their exact bytes, global refs, and range facts survive; their unresolved generic cleanup/helper source identity is superseded by current RTTI and EH evidence.
- Strong accepted comparators are current UID0000Y0 `RankingDialogSingletonBaseDestructor` and UID00033X `MixItemDialogSingletonBaseDestructor`: both use the same eleven-byte zero-store body, adjusted Singleton-base receiver in constructor EH, direct RTTI/EBO identity, ordinary/scalar inlining, semantic class owner, non-reconstructable state, blank emitter, and blank formal C++.

### Report roots and terms searched

- Exact terms: `UID000180`, `UID:000180`, `0x004e5bc0`, `0x004e5bcb`, `MapTileImageLibSingletonClearHelper`, `ClearMapTileImageLibSingleton`, `MapTileImageLibSingletonBaseDestructor`, `Singleton<MapTileImageLib>`, `g_pMapTileImageLib`, `UID00007T`, `UID0000L5`, `UID0000RG`, `UID0002IZ`, `UID000178`, `UID0002J2`, `constructor`, `destructor`, `scalar`, `static cleanup`, `initializer`, `atexit`, and `unwind`.
- Active report roots `tools/leaser/Agents/Agent-B001/research` through `Agent-B015/research`: no active exact UID/range report was found. B001-B005 had no conflicting active UID000180 artifact.
- Central executed root `executed-b-agent-research`: matching direct/family artifacts opened were `B003/000178-00017G-00017I-00017W-00017X-00017Z-000180-0002J2-image-library-cleanup-source-quality.md`, `B003/0002IZ-0002J1-maptileimagelib-source-quality.md`, `B011/0000L5-MapTileImageLib-empty-emitter-family-source-quality.md`, `B015/000177-MapTileImageLibLocalMethodCluster-source-quality.md`, and `B008/0002H8-ApplicationShutdown-empty-emitter-source-quality.md`.
- Central executed comparator artifacts opened were `B004/0000Y0-RankingDialogClearSingletonHelper-source-quality.md`, `B003/0004BT-MixItemDialogConstructor-source-quality.md`, `B001/00017X-HumanImageLibSingletonClearHelper-source-quality.md`, `B004/00017W-EffectObjImageLibSingletonClearHelper-source-quality.md`, `B002/00017Z-LightObjImageLibSingletonClearHelper-source-quality.md`, and `B013/00017Y-ItemObjImageLibSingletonClearHelper-source-quality.md`.
- Legacy/secondary roots `tools/leaser/Agents/Older-Research` and `tools/leaser/Agents/SpecialReports`: no exact UID/range/name match.
- Archived root `archived`: no exact UID/range/name match.
- Historical direct findings: B003 assigned `85/90`, file owner/emitter, and blank C++; B011 implemented the current `86/90` comment-bearing no-code state; B015 retained the exact range as separate tail support. All three lacked current direct `Singleton<MapTileImageLib>` RTTI/PMD and unwind-map resolution.

## Target

- Target UID: `000180`.
- Applied target path: `by-memory/0x004e5bc0-0x004e5bcb.MapTileImageLibSingletonBaseDestructor.md`; historical old path `by-memory/0x004e5bc0-0x004e5bcb.MapTileImageLibSingletonClearHelper.md` is absent.
- Evidence-time tracker row: by-memory Not-Covered Files - Reconstructable, `86/90`, reports `0`; no current/future tracker or report-count state is asserted.
- Callback authorization basis: supervisor exact-artifact Gate 1 passed report SHA `7149D77CC7DDDBFC658DBD04F46245796F70EF0A899E0E85AD8127A999ECFAF7` at `2026-07-14T20:35:14-04:00`.
- Applied metadata: `93/96`, `CANONICAL_OWNER:00007T`, `RECONSTRUCTABLE:FALSE`, blank emitter/position/formal block, `Nested:0`.

## Current Target State

- Evidence-time / pre-callback metadata was internally contradictory: `RECONSTRUCTABLE:TRUE`, file emitter UID0000L5, and comment-bearing output represented a function already proved to have no handwritten API. This is preserved as superseded history.
- Applied target state uses semantic class owner UID00007T and no emitter. The literally blank managed block removes UID000180 from generated C++ while the class/constructor/destructor/global constructs emit the causal source.
- Evidence-time open questions were helper name, static cleanup provenance, atexit/initializer route, and whether the clear was handwritten. Direct RTTI, FuncInfo/unwind map, adjusted receiver, ordinary/scalar copies, and pointer-route negatives closed all four before callback and remain the applied rationale.
- Applied class/constructor/destructor state includes the direct `Singleton<MapTileImageLib>` base, direct base initializer, and no manual global publication/clear. UID0002J2 is now `93/96`, semantic owner UID00007T, false/non-emitting with blank emitter/position/formal C++.
- UID0001V2/UID0001Y3/UID0000RG/UID0001OU/UID0000L5 carry the accepted layout/vtable/global/storage/file synchronization. UID000177 received only the documented concrete-drift prose correction; Application startup/shutdown remained read-only.
- Related docs checked: UID00007T class, UID0000L5 file, UID0000RG global, UID0001OU storage, UID0002IZ constructor, UID000178 destructor, UID0002J2 scalar wrapper, UID0001V2 layout, UID0001Y3 vtable, UID000177 aggregate, Application startup/shutdown docs, generated `MapTileImageLib.cpp`, and all affected manual coverage rows.
- Callback drift recheck after UID path propagation found and documented one concrete Destination 11 contradiction before the aggregate edit: UID000177 retained active `ClearMapTileImageLibSingleton`, `cleanup/static-unwind glue`, and file-routed helper wording even though its core `86/91`, ownerless/non-emitting index, four exact children, padding, and out-of-range support boundaries remained correct. The goal's concrete-drift exception authorized the bounded prose-only correction, now applied with no metadata/range/formal/child change; Application startup/shutdown remained read-only.
- B002 callback work is complete: eleven ordinary pages were changed in twelve serial lease/edit/validation passes because the final audit corrected one target evidence-hash transcription, every changed page passed its scoped validator, all leases were released, and final waited generated command `000000012233` completed. Current/future report path, report count, validation, execution, move, and archive state are external validator/supervisor-owned and are not asserted here.

## Executive Recommendation

- Direct semantic owner UID00007T and source route UID0000L5 `NexusTK/render/MapTileImageLib.cpp` are applied.
- UID000180 is UID-preserving renamed and reclassified to `93/96`, false/non-emitting, blank emitter/position/formal C++, `Nested:0`; no child or duplicate body was created.
- The complete class has direct `Singleton<MapTileImageLib>` inheritance; the constructor initializes it; the ordinary destructor omits manual clear. Compiler lowering regenerates publication/fallback, state-1 EH cleanup, ordinary clear, and scalar clear.
- UID0002J2 is false/non-emitting compiler ABI support, and UID000178 remains the unique handwritten destructor body.
- UID0000RG remains the only typed source definition; UID0001OU remains covered backing storage.
- No source-bearing item remains blocked. Original template-header/static-member spelling remains lexically unknown but does not affect behavior-identical class/global reconstruction.

## Supervisor Active Recheck

- The supervisor assigned the report-only pass to resolve the reconstructable/no-code/static-cleanup contradiction, then accepted exact report SHA `7149D77C...ECFAF7` for this bounded callback. This records the authorization event without asserting any later lifecycle state.
- No range split or new child is required. The exact range is one eleven-byte function with clean five-byte `0xcc` padding on each side.
- Every source-bearing construct in scope has an exact destination: class inheritance, constructor, ordinary destructor, global definition, and support declarations. Exact compiler-generated target/scalar functions have complete positive no-code proof and blank formal destinations.

## Inference Research Guidance Check

- The workflow's inference discipline required testing the existing helper label instead of preserving it because it appeared in prior docs. Generated names, absent ordinary callers, and a short body were treated as weak evidence until the constructor EH state and RTTI base identity were recovered.
- IDA facts are kept separate from inference: direct RTTI names and PMD values, unwind-map actions, exact stores, bytes, xrefs, and vtable slots are facts; the descriptive page title and exact reconstructed global/template spelling are inference.
- Evidence-time docs were treated as fallible where they described UID000180 as file-level static cleanup and omitted the Singleton base. The callback has now applied the binary-proved source shape.
- Historical Wave2/Wave3 references in class/vtable documentation were found. They were ignored as stale labels; no Wave artifact controls this recommendation.

## Heuristic / Inference Reanalysis And Validation

- Generated-name issue: IDA names the target `sub_4E5BC0`. `MapTileImageLibSingletonBaseDestructor` is a descriptive source-identity page title, not a claimed recovered linker symbol.
- Helper-role issue: one zero store and return could describe a free helper, but the only inbound route is an EH action that computes `this+4` before tail-jumping. The receiver is externally established and unused by the specialization body.
- Type issue: original RTTI string `.?AV?$Singleton@VMapTileImageLib@@@@` and direct BCD PMD `+4/-1/0` prove the type `Singleton<MapTileImageLib>` and direct nonvirtual base status.
- Layout issue: `MapTileImageLib` size is `0x0c`; `LObject` occupies `+0x00`, the empty Singleton base is addressed at `+0x04`, and `tileFrameTable` also occupies `+0x04`. This is empty-base optimization, not a hidden pointer/member or four-byte guard.
- Constructor issue: pre-callback source manually assigned the singleton. Binary order instead constructs LObject, establishes EH state 0, publishes through the adjusted Singleton base, establishes state 1, then installs the derived vptr and constructs later state. The applied direct base initializer is the only source shape that explains that ordering and state-specific cleanup.
- Destructor issue: ordinary and scalar destruction free derived members, clear the global, then tear down LObject. Reverse direct-base order makes the zero store implicit Singleton destruction between derived body and LObject teardown. The authored destructor body ends after freeing `tileRecords`.
- Static-lifetime issue: no target VA/RVA pointer, initializer table entry, function pointer, normal call, imported `atexit`, or imported `onexit` route exists. Application explicitly allocates/constructs the object during startup and virtually deletes it during shutdown. UID000180 is construction-failure cleanup, not process-exit registration.
- Source placement issue: target semantic context is the class, but source behavior is split across the class declaration, constructor/destructor, and typed global in MapTileImageLib.cpp. A free file-local helper would duplicate generic base semantics.
- Generated pollution issue: pre-callback `RECONSTRUCTABLE:TRUE` caused a UID000180 comment marker. Applied non-reconstructable blank formal state removes the target from generated source while preserving binary documentation.
- Naming issue: `g_pMapTileImageLib` remains the accepted reconstructed external name. Binary proves a typed singleton slot but not exact source symbol or whether the generic template used a static-member indirection/macro. Do not invent `ms_instance`, `s_instance`, or a template specialization body.
- Rejected alternatives: free `ClearMapTileImageLibSingleton`, member `MapTileImageLib::ClearSingleton`, explicit target-local template specialization, `atexit` callback, static object destructor, constructor catch block, stored guard member, aggregate child, padding, and source-level scalar deleting destructor. Each conflicts with one or more direct EH/RTTI/layout/vtable/xref facts.
- No behavior blocker remains. Lexical template-header/static-member uncertainty caps confidence but does not justify source duplication or blank class inheritance.

## Evidence Standards Used

- Primary evidence: current IDA MCP health, binary survey, function lookup/profile/decompile/disassembly, basic blocks, raw bytes, exact/wildcard signatures, direct/data xrefs, pointer/RVA searches, FuncInfo/unwind map, RTTI COL/CHD/BCD bytes, startup/shutdown decompilation, ordinary/scalar destructor parity, and neighboring helper family.
- Secondary evidence: by-* pages and generated C++ read at research/callback time, evidence-time generated tracker, affected manual coverage rows, and executed report artifacts.
- Negative evidence: no target pointer/RVA hits, no ordinary call, no function-table route, no atexit/onexit import, no vtable slot, no branch/callee/string/argument use, no second source body, and no target range overlap.
- Evidence ladder: direct binary structure and control flow outrank older documentation labels. Accepted analogous singleton-base-destructor pages corroborate but do not substitute for target-specific RTTI/EH proof.
- Tool limits: one broad rendered-listing search for `atexit` exceeded the 30-second client timeout after `imports_query` had already returned zero matching imports. Narrowed retries over the complete target/constructor/destructor/scalar family range `[0x004d1800,0x004e6800)` completed with zero `atexit` and zero `onexit` listing hits at ids `143` and `144`; health id `145` remained `ok`. No conclusion relies on the timed-out broad search.

## Evidence Checked

- `idb_list`: evidence-time adopted NexusTK database `2625e5c6`; callback made no MCP/IDA calls and does not assert present session availability.
- `server_health`: evidence-time `status:ok`, image base `0x00400000`, analysis/Hex-Rays/strings ready.
- JSON-RPC ids `10`, `11`, `12`, `13`, `20`-`23`: target/constructor analysis, target/global xrefs, bytes, complete constructor disassembly/decompile, and blocks.
- Ids `50`-`72`: RTTI strings, vtable COL pointer, complete COL/CHD/base-array/BCD bytes, direct Singleton PMD, and COL xref.
- Ids `80`-`93`: constructor FuncInfo, three unwind entries, action chunks, and exact state-1 cleanup action.
- Ids `100`-`102`: ten adjacent eleven-byte helper functions, their one EH inbound xref each, globals, boundaries, and family inventory.
- Ids `110`-`114`: ordinary/scalar destruction, startup, shutdown, constructor/destructor/scalar xrefs.
- Ids `120`-`122`: raw VA/RVA/rel32/global-operand searches, exact action bytes, RTTI block, and profiles.
- Ids `130`, `140`, `143`-`145`: binary survey, zero `atexit`/`onexit` imports, zero narrowed family-range listing hits, and final evidence-time health `ok`.
- Local exact target-byte SHA256: `713E52BBE86EE6798C2A3DD7CAEB42D40A7A658E0736B01351DB0FCD4103EEF7` for `c7 05 5c a7 67 00 00 00 00 00 c3`.
- Current docs and generated paths listed under Current Target State were opened directly. Manual rows were read from `by-memory/-coverage-report.md`, `by-class/-coverage-report.md`, `by-file/-coverage-report.md`, `by-global/-coverage-report.md`, `by-type/by-struct/-coverage-report.md`, and `by-type/by-vtable/-coverage-report.md`.
- Failed/unavailable checks: no required bounded target call failed. The single broad `search_text` timeout is recorded above; narrowed retries completed successfully with zero hits. No IDA mutation tool was called.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | UID000180 is exact function `[0x004e5bc0,0x004e5bcb)`, size `0x0b`, two instructions, one block, complexity 1. | High | MCP ids 10, 13, 20, 122 | Destination 1 target range/status | incorporate | applied |
| C02 | Exact bytes are `c7 05 5c a7 67 00 00 00 00 00 c3`, SHA256 `713E...EEF7`, storing zero to `0x0067a75c` then returning. | High | ids 10, 12, 20; local SHA | Destination 1 exact body/evidence | incorporate | applied |
| C03 | Five `0xcc` bytes precede and follow the target; no padding or neighbor belongs to the target. | High | ids 12, 20, 121 | Destination 1 boundary/padding | incorporate | applied |
| C04 | Exact signature is unique; operand-wildcard shape is non-unique; VA and RVA pointer bytes have zero hits; one unique rel32 jump exists. | High | ids 82-84, 120 | Destination 1 signature/negative evidence | incorporate | applied |
| C05 | Sole inbound route is constructor EH action `0x005ff9b5-0x005ff9c0`, with `this+4` then tail-jump at `0x005ff9bb`; no ordinary caller exists. | High | ids 11, 21-23, 90-93, 121 | Destination 1 EH/source identity | incorporate | applied |
| C06 | Constructor FuncInfo `0x0065e248` has max state 3 and unwind entries `(-1,5ff9ad)`, `(0,5ff9b5)`, `(1,5ff9c0)`; state 1 destroys Singleton. | High | ids 80, 81, 90, 91 | Destinations 1 and 3 | incorporate | applied |
| C07 | Original RTTI proves direct `Singleton<MapTileImageLib>` base: three hierarchy entries and BCD PMD `+4/-1/0`, attributes `0x40`. | High | ids 50, 51, 60, 61, 70, 71 | Destinations 1, 2, 6, 7 | incorporate | applied |
| C08 | Singleton base is empty and overlaps `tileFrameTable` at `+0x04`; complete size stays `0x0c`. | High | RTTI BCD; layout; ctor field refs | Destinations 2 and 6 | incorporate | applied |
| C09 | Strongest identity is compiler-instantiated `Singleton<MapTileImageLib>::~Singleton()`, not a standalone helper. | High | C05-C08; UID0000Y0/00033X comparators | Destination 1 rename/disposition | incorporate | applied |
| C10 | Constructor publication/fallback at `0x004d18a3/aa` is inlined Singleton base construction and must not remain a handwritten body assignment. | High | ids 21, 22; state order; RTTI | Destination 3 exact formal body | reject-stale | applied |
| C11 | Ordinary clear at `0x004d19f9` is implicit Singleton base destruction after the authored derived cleanup and before LObject teardown. | High | id 110; RTTI/reverse order | Destination 4 exact formal body | reject-stale | applied |
| C12 | UID0002J2 repeats derived cleanup plus Singleton clear, LObject teardown, delete flags, and free as compiler scalar wrapper; no handwritten body belongs there. | High | id 111; vtable xref | Destination 5 metadata/formal | incorporate | applied |
| C13 | Global slot has exactly ten direct operand/xref sites, including four zero-store sequences and constructor publication. | High | ids 11, 82, 120 | Destinations 1, 3-5, 8, 9 | incorporate | applied |
| C14 | Startup allocates `0x0c` and calls constructor at `0x004f6055`; shutdown reads/deletes the pointer at `0x004f6622`. | High | ids 112-114 | Destinations 8-10; verify-only Application | incorporate | applied |
| C15 | Ten contiguous `0x0b` zero-store helpers from `0x004e5b70` through `0x004e5c00` each have one EH inbound route and one singleton target. | High | ids 100-102 | Destination 1 family/comparator evidence | incorporate | applied |
| C16 | No atexit/onexit import, target pointer, initializer table, callback table, or normal function route supports static-process cleanup classification. | High | ids 82, 120, 140; xrefs | Destination 1 negative/no-code proof | reject-stale | applied |
| C17 | UID-preserving title/path must become `MapTileImageLibSingletonBaseDestructor`; old helper names remain historical aliases only. | High | source identity; comparator naming | Destination 1 and links/coverage | incorporate | applied |
| C18 | Target metadata should become `93/96`, owner UID00007T, false, blank emitter/position/formal, Nested 0. | High | complete direct evidence | Destination 1 metadata | incorporate | applied |
| C19 | A blank target formal block is required; comment-bearing pseudo-source would still be generated target output. | High | non-emitting policy; evidence-time generated marker | Destination 1 formal block | reject-invalid | applied |
| C20 | Complete class declaration must add direct `Singleton<MapTileImageLib>` while preserving LObject, fields, methods, and children. | High | RTTI/layout/ctor | Destination 2 formal block | incorporate | applied |
| C21 | Complete constructor draft must initialize the Singleton base and omit manual global publication while preserving all accepted tile-loading behavior. | High | ctor disasm/EH/RTTI | Destination 3 formal block | incorporate | applied |
| C22 | Complete ordinary destructor draft must preserve resource frees and omit the implicit Singleton clear. | High | ordinary/scalar/reverse base order | Destination 4 formal block | incorporate | applied |
| C23 | Scalar wrapper must be `93/96`, semantic owner UID00007T, false, blank emitter/position/formal, Nested 0. | High | vtable/ordinary parity/compiler ABI | Destination 5 | incorporate | applied |
| C24 | Layout support must record direct LObject and Singleton bases, PMD/EBO overlap, fields, and size without duplicate C++. | High | RTTI/layout/field accesses | Destination 6 | incorporate | applied |
| C25 | Vtable support must record COL/CHD/base-array addresses, exact three-entry hierarchy, Singleton BCD, and compiler-only ABI. | High | ids 51, 60, 61, 70, 71 | Destination 7 | incorporate | applied |
| C26 | UID0000RG remains the sole typed global definition and must document Singleton base publication/clear rather than manual method assignments. | High | global refs/source route | Destination 8 | incorporate | applied |
| C27 | UID0001OU remains covered storage, now with exact ten refs and direct Singleton base source cause; no duplicate definition. | High | ids 11, 12, 120 | Destination 9 | incorporate | applied |
| C28 | UID0000L5 file prose must route direct inheritance and implicit lifetime, historicalize helper/static cleanup, and preserve unrelated tile source. | High | class/file/generated evidence | Destination 10 | incorporate | applied |
| C29 | UID000177 retains its non-source aggregate/index role with no metadata/range/owner/formal/child change but required the documented bounded stale-prose repair; Application startup/shutdown remain unchanged verify-only support. | High | callback drift/readback; ids 112-114 | Destination 11 bounded prose drift repair; Destination 12 read-only proof | incorporate | applied |
| C30 | Manual coverage rows must be replaced by the exact supervisor-owned rows below; callback validation must prove no target/scalar marker, one class/global, and no duplicate manual stores. | High | manual row readback; command 000000012233 | Destination 13 text retained; manual application external; generated proof applied | incorporate | excluded-with-reason |

### Terminal Callback Destination Proof

- Ledger totals: `30` claims = `29 applied`, `0 already-present`, `1 excluded-with-reason`, `0 blocked`; all Action cells retain the accepted vocabulary. C30 is excluded only for supervisor-owned manual coverage application; its exact replacement text remains below and its generated assertions are applied.
- C01-C09/C15-C19 -> Destination 1 `by-memory/0x004e5bc0-0x004e5bcb.MapTileImageLibSingletonBaseDestructor.md`, SHA256 `C1DF02B751B5611ABC39B60FB619FB59FE53A41C54643E538636AEF78BE7D8F2`; old path absent. Its exact evidence line records target-byte SHA256 `713E52BBE86EE6798C2A3DD7CAEB42D40A7A658E0736B01351DB0FCD4103EEF7`.
- C07-C08/C20 -> Destination 2 `by-class/MapTileImageLib.md`, SHA256 `B2D85ED71180142EAD1B8210A001550A42C931783CB656445C1C89F49AB18CFF`.
- C06/C10/C13/C21 -> Destination 3 `by-memory/0x004d1860-0x004d199e.MapTileImageLibConstructor.md`, SHA256 `81C3A6E4055792C85DC0F3355FD1B254E521A346067B0BAD4EC1E6AC45B69C54`.
- C11/C13/C22 -> Destination 4 `by-memory/0x004d19a0-0x004d1a1c.MapTileImageLibDestructor.md`, SHA256 `F1BDAB1D9BB10271558D6346C381A4DDAC88E6353139D319FCE60588C4AB75FC`.
- C12-C13/C23 -> Destination 5 `by-memory/0x004e66a0-0x004e6748.MapTileImageLibScalarDeletingDestructor.md`, SHA256 `0A08CA2230E201F349C07478A77F886080367304EE448877E56535AC560E59F2`.
- C07-C08/C24 -> Destination 6 `by-type/by-struct/MapTileImageLibLayout.md`, SHA256 `DAB476D80C4C3773474841EBE0A58A507090FDA6E9BA527BBB4DCAE28BB9C9E8`.
- C07/C25 -> Destination 7 `by-type/by-vtable/MapTileImageLibVtable.md`, SHA256 `39AA02C909CEC8B3E3AB9F33C0F596A66325754795C8F0241B54F0B30EE372ED`.
- C13-C14/C26 -> Destination 8 `by-global/g_pMapTileImageLib.md`, SHA256 `0E402BFB413C40A633C1DF3E941085267CB302A7F9D689F6B46C3913FA50579E`.
- C13-C14/C27 -> Destination 9 `by-memory/0x0067a75c-0x0067a760.g_pMapTileImageLib.md`, SHA256 `6514BC62A521D60047699CEE532CC0400C0D6088184F9C6803BB0D404C222933`.
- C14/C28 -> Destination 10 `by-file/MapTileImageLib.md`, SHA256 `5D69446ABC45AEB1412B8C853BE5DF4A0B46B82BB071D915241AA709A3D1666D`; it has no managed by-file reconstruction metadata.
- C29 -> Destination 11 `by-memory/0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster.md`, SHA256 `95E91CEE7406CAE59CC7D87F32D485242A6C05338D5185697591CD2A2073624E`; score/owner/range/formal/children were preserved and only documented stale target prose changed.
- C14/C29 -> Destination 12 read-only hashes: `by-file/Application.md` `DBE808B0E733263B7ECF07FFE93804EA222BEFED9E9C58FA9453F4C018DB2AAD`; `by-memory/0x004f5fb0-0x004f6490.ApplicationStartup.md` `01885FE7CFB22BBC19369A60D6881083C90692651C5306B3DB8F78037ACF2926`; `by-memory/0x004f6490-0x004f66a5.ApplicationShutdown.md` `DF47B7F3528DAF49A10718A0BECB123BB0394C043A6773726B2FA2BCB2EB62F0`. Startup `0x004f6055` and shutdown `0x004f6622` remain documented; no edit/validator was used.
- C30 -> final generated `auto-generated/NexusTK/render/MapTileImageLib.cpp`, SHA256 `6011218F8DF959EC4CF1C1B85F1710CE4D0BF61EEE6DB4ACF50589633F85C36A`, command `000000012233`; exact manual supervisor-owned replacement text remains under its required heading and was not manually applied.

## Positive Evidence Summary

- The source receiver identity is carried outside UID000180: constructor unwind action loads complete `this`, adds `4`, and tail-jumps to the target.
- Original RTTI independently identifies the direct base at exactly that displacement as `Singleton<MapTileImageLib>`.
- The constructor's state machine makes Singleton live at state 1 and invokes UID000180 precisely when later construction fails.
- Ordinary and scalar destruction inline the same zero store in the exact reverse-base position before LObject teardown.
- Startup and shutdown explicitly construct/delete the singleton object; no process-exit callback registration reaches UID000180.
- RankingDialog and MixItemDialog accepted pages independently establish the same source-declared/generated-binary representation for identical evidence shapes.

## IDA MCP Facts

- Function/range: `sub_4E5BC0`, `0x0b`, one block, two instructions, no callees/strings/arguments/receiver reads.
- Data/padding: target bytes/hash above; five `0xcc` bytes on each side; next helper at `0x004e5bd0` is separate.
- Xrefs: one inbound code xref at `0x005ff9bb`; data xref to `0x0067a75c`; no direct ordinary caller list.
- EH: target is a callee of the state-1 action, not itself the EH funclet. State 0 destroys LObject; state 1 destroys Singleton; state 2 destroys the constructor-local DATFile object.
- RTTI: MapTile TypeDescriptor `0x00676738`; Singleton TypeDescriptor `0x00676758`; COL `0x00648774`; CHD `0x00648788`; base array `0x00648798`; self BCD `0x006487a8`; Singleton BCD `0x006487c4` with PMD `4/-1/0`.
- Vtable: `0x0061b660 -> COL 0x00648774`; slots at `0x0061b664` are `0x004e66a0`, `0x004f4b10`, and `0x0041b6c0`.
- Global: exact operand bytes for `0x0067a75c` occur ten times; exact zero-store prefix occurs at constructor fallback, ordinary destructor, UID000180, and scalar wrapper.
- Negative: no VA pointer bytes `c0 5b 4e 00`, no RVA pointer bytes `c0 5b 0e 00`, no atexit/onexit import, no target vtable/data slot, no second target body.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004d1860-0x004d199e` | UID0002IZ constructor | Handwritten class constructor; Singleton publication is implicit base construction | TRUE | UID00007T | `92/94` | Applied source emitter with direct base initializer |
| `0x004d19a0-0x004d1a1c` | UID000178 ordinary destructor | Unique handwritten derived cleanup; Singleton clear is implicit base destruction | TRUE | UID00007T | `92/95` | Applied source emitter without duplicate clear |
| `0x004d1a20-0x004d1b72` | UID0002J0 DrawTile | Unrelated accepted source method | TRUE | UID00007T | `88/90` | Verify-only |
| `0x004d1b80-0x004d1f22` | UID0002J1 loader | Unrelated accepted file-local helper | TRUE | UID0000L5 | `89/92` | Verify-only |
| `0x004e5bc0-0x004e5bcb` | UID000180 target | EH-only `Singleton<MapTileImageLib>` base-destructor instantiation | FALSE | UID00007T semantic | `93/96` | UID-preserving rename applied; blank/non-emitting |
| `0x004e66a0-0x004e6748` | UID0002J2 scalar deleting destructor | Compiler ABI wrapper around ordinary/implicit base destruction | FALSE | UID00007T semantic | `93/96` | Applied blank/non-emitting compiler support |
| `0x0061b660-0x0061b670` | UID0003BQ vtable data | Compiler RTTI/vtable evidence | FALSE | UID00007T semantic | unchanged | Verify-only exact data child |
| `0x0067a75c-0x0067a760` | UID0001OU storage | Covered singleton storage | TRUE | UID0000RG | `91/94` | Applied comment-only covered storage |
| class | UID00007T MapTileImageLib | Direct LObject plus Singleton class declaration | TRUE | UID0000L5 | `92/94` | Applied complete source declaration |
| file | UID0000L5 MapTileImageLib | Source module owner | root | FILE | `91/93` | Applied prose synchronization; no by-file metadata |

No new child, split, merge, or padding page is recommended.

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x005ff9b5` | constructor unwind action entry | Loads saved complete object and forms Singleton base address |
| `0x005ff9bb -> 0x004e5bc0` | sole target code xref | Tail-jump from state-1 EH action |
| `0x004d18a3` | store `this` to global | Inlined Singleton base construction |
| `0x004d18aa` | zero-store fallback | Adjusted-base null lowering, not authored branch |
| `0x004d19f9` | ordinary zero store | Inlined Singleton base destruction |
| `0x004e6700` | scalar zero store | Inlined Singleton base destruction within wrapper |
| `0x004f6055 -> 0x004d1860` | sole constructor caller | Application startup allocation/construction |
| `0x004f6622` | global read and virtual delete | Application shutdown destruction |
| `0x00424431`, `0x0050c3cb`, `0x0050d978`, `0x0054976f` | consumer reads | Terrain/photo/map consumers; do not own lifetime |
| `0x0061b664 -> 0x004e66a0` | vtable slot | Scalar deleting destructor ABI route |

## Documentation Evidence And IDA Status

- Evidence-time / pre-callback UID000180 preserved bytes/xrefs/boundaries but was stale on identity, owner, reconstructable/emitter state, and comment-bearing output. UID00007T omitted the direct Singleton base; UID0002IZ/UID000178 handwrote global stores; UID0002J2 emitted a comment; UID0001V2/UID0001Y3 omitted direct-base RTTI/EBO; UID0000RG/UID0001OU/UID0000L5 retained helper terminology. These facts are historical and superseded by the applied destinations.
- Applied current ordinary state: UID000180 `93/96` false/blank under semantic class owner; UID00007T direct Singleton class; UID0002IZ direct base initializer; UID000178 resource-only authored body; UID0002J2 `93/96` false/blank; UID0001V2/UID0001Y3 direct-base layout/RTTI; UID0000RG one definition; UID0001OU covered storage; UID0000L5 direct-lifetime prose; UID000177 bounded target-prose synchronization.
- Final waited generated `auto-generated/NexusTK/render/MapTileImageLib.cpp` command `000000012233` has one direct-base class, one constructor/destructor/DrawTile/loader, one typed global, no manual constructor publication or destructor clear, no UID000180/UID0002J2 output, and no raw ABI output.
- Manual coverage remains supervisor-owned. Validator path propagation updated UID000180's link to the renamed path, but the row text/scores and other family rows remain stale; the exact supervisor replacement text below is intentionally unapplied by B002.

## Ranked Ownership Analysis

### 1. UID00007T MapTileImageLib semantic owner

- Evidence for: direct Singleton base RTTI is in MapTileImageLib's complete hierarchy; constructor EH supplies the MapTile complete object and `+4` base address; ordinary/scalar destruction copies occur within MapTile methods.
- Evidence against: UID000180 has no source method declaration and must not emit through the class.
- Decision: retain UID00007T as semantic owner only; blank target emitter/formal state.

### 2. UID0000L5 MapTileImageLib.cpp source module

- Evidence for: class, methods, global, loader, and all MapTile resources route through this file.
- Evidence against: a file root is not the semantic identity of an instantiated direct-base destructor and should not emit the exact target.
- Decision: source route for the causal declarations, not target metadata owner/emitter.

### 3. UID0000RG global or a standalone cleanup utility

- Evidence for: exact body mutates only the singleton slot.
- Evidence against: global storage cannot explain adjusted receiver, base RTTI, EH state, EBO, or normal/scalar copies. No independent helper route exists.
- Decision: reject direct ownership and standalone utility identity.

### Proposed new file/grouping, if applicable

- Not applicable. The source file remains `NexusTK/render/MapTileImageLib.cpp`; no new file, utility group, or template page is required for this bounded callback.

## Source Placement

- Applied placement: direct `Singleton<MapTileImageLib>` inheritance on UID00007T, explicit base initialization on UID0002IZ, implicit reverse-order destruction after UID000178's body, typed definition on UID0000RG, all routed through UID0000L5.
- This placement fits the original RTTI hierarchy, object offset, constructor EH state, ordinary/scalar order, and existing render source tree.
- Rejected placements: public/private class clear method, file-local clear helper, Application shutdown helper, by-global emitter, aggregate child, static initializer/atexit callback, and explicit specialization body.
- Remaining placement uncertainty: only the historical generic Singleton header/static-member spelling is unknown. Existing project convention consistently reconstructs the direct `Singleton<T>` base and accepted typed global name, which is behaviorally sufficient.

## Range / Split / Padding / Reclassification Analysis

- Exact target remains `[0x004e5bc0,0x004e5bcb)`, eleven bytes. The UID-preserving rename retained the range endpoints and changed only the descriptive suffix; the old path is absent.
- `[0x004e5bbb,0x004e5bc0)` and `[0x004e5bcb,0x004e5bd0)` are five-byte `0xcc` padding spans.
- Neighbor `0x004e5bb0` clears `0x0069b450`; neighbor `0x004e5bd0` clears `0x0069b440`. Neither range, global, or owner belongs to UID000180.
- Reclassification is source-declared/generated-binary Singleton base destruction, false/non-emitting. No target split/merge/new child is needed.
- UID000177 remains a separate non-emitting index over `0x004d1860-0x004d1f30`; target and scalar remain outside it.

## Negative Evidence Summary

- No ordinary caller, vtable slot, function pointer, data pointer, static initializer table, atexit/onexit import, target VA/RVA hit, callback registration, branch, callee, string, argument use, return use, or object-field read supports a handwritten helper.
- Consumer reads of `g_pMapTileImageLib` prove global use, not ownership of UID000180.
- Physical adjacency to nine sibling clear bodies proves compiler patterning but not shared range ownership.
- Existing file-owner metadata and generated comment are documentation artifacts, not binary proof.
- A manual constructor assignment plus catch cannot explain direct-base RTTI, adjusted receiver, explicit EH state transition, EBO overlap, and ordinary/scalar base-order copies.
- An explicit target specialization would duplicate the generic source contract and is not evidenced by a normal address route or symbol.

## IDA Rename / Type / Comment Recommendations

- Safe source-facing page/IDA direction: `MapTileImageLibSingletonBaseDestructor` for `sub_4E5BC0`, explicitly descriptive rather than original-symbol proof.
- Recovered type: `Singleton<MapTileImageLib>` direct nonvirtual empty base at PMD `+4/-1/0`.
- Preserve `g_pMapTileImageLib` as accepted reconstructed global; do not claim it as recovered original spelling.
- Reject and preserve historically only: `MapTileImageLibSingletonClearHelper`, `ClearMapTileImageLibSingleton`, `MapTileImageLib::ClearSingleton`, and generic `static cleanup helper`.
- No IDA DB rename/type/comment edit was made during research or callback; the page rename is documentation-only.

## First-Draft C++ Recommendation

- Eligible source C++: complete class declaration, constructor, ordinary destructor, global definition, and covered support comments below.
- Ineligible exact binary C++: UID000180 and UID0002J2. Their managed bodies must be literally blank.
- The blocks below are destination-specific exact formal insertion text. No body-only or illustrative C++ exists elsewhere in this report.

### Destination 1: UID000180 renamed target

```text
*** UID:000180 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007T | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Source-declared/generated-binary Singleton<MapTileImageLib> base-destructor instantiation reached only through constructor EH; direct +0x04 RTTI/EBO identity and ordinary/scalar copies prove generic base lifetime, not a handwritten clear helper. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### Destination 2: UID00007T complete class declaration

```text
*** UID:00007T | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000L5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class MapTileImageLib : public LObject, public Singleton<MapTileImageLib>
{
public:
    MapTileImageLib();
    virtual ~MapTileImageLib();

    void DrawTile(void *drawTarget, const RectBounds *destinationRect, unsigned int tileId);

private:
    ArchiveMetadataTable *tileFrameTable;
    MapTileRecord *tileRecords;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 3: UID0002IZ complete constructor

```text
*** UID:0002IZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007T | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007T | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
MapTileImageLib::MapTileImageLib()
    : Singleton<MapTileImageLib>(),
      tileFrameTable(0),
      tileRecords(0)
{
    tileFrameTable = LoadTileEpfMetadata(L"TILE.EPF");

    DATFile tileTable;
    tileTable.Open(L"TILE.TBL");

    unsigned int tileCount = 0;
    tileTable.Read(&tileCount, sizeof(tileCount));

    if (tileFrameTable == 0 || tileCount != tileFrameTable->frameCount)
    {
        ShowFatalTileFileError(L"Error on Tile File!");
        return;
    }

    tileRecords = tileCount != 0 ? new MapTileRecord[tileCount] : 0;

    for (unsigned int index = 0; index < tileCount; ++index)
    {
        short packedRecord = 0;
        tileTable.Read(&packedRecord, sizeof(packedRecord));

        tileRecords[index].allowPaletteFilter = packedRecord < 0;
        tileRecords[index].paletteIndex =
            static_cast<unsigned short>(packedRecord & 0x7fff);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Exact source constructor with direct Singleton<MapTileImageLib> base initialization, compiler-lowered +0x04 EBO publication and state-1 cleanup, startup-only caller, metadata/TILE.TBL loading, record decode, and no duplicate handwritten singleton assignment. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:4 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### Destination 4: UID000178 complete ordinary destructor

```text
*** UID:000178 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007T | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007T | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
MapTileImageLib::~MapTileImageLib()
{
    MemoryManager *memory = GetMemoryMan();

    if (tileFrameTable != 0) {
        if (tileFrameTable->records != 0) {
            memory->Free(tileFrameTable->records);
        }

        memory->Free(tileFrameTable);
    }

    free(tileRecords);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Unique handwritten MapTileImageLib destructor body with exact metadata/table/tile-record frees; direct Singleton base destruction owns the following global clear before LObject teardown, so no duplicate singleton assignment is emitted. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### Destination 5: UID0002J2 scalar wrapper

```text
*** UID:0002J2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007T | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Exact vtable-only compiler scalar deleting wrapper around the ordinary derived cleanup, implicit Singleton clear, LObject teardown, delete flags, size guard, and storage free; UID000178 is the sole handwritten destructor source. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### Destination 6: UID0001V2 layout support

```text
*** UID:0001V2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007T | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007T | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// No separate layout C++ should be emitted for [UID:0001V2].
// The MapTileImageLib declaration emitted by [UID:00007T][MapTileImageLib](by-class/MapTileImageLib.md) owns the
// LObject base at +0x00, empty Singleton<MapTileImageLib> base at +0x04,
// ArchiveMetadataTable pointer at +0x04, and MapTileRecord pointer at +0x08.
// Direct RTTI PMD +0x04 and the 0x0c complete size prove EBO overlap.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 7: UID0001Y3 vtable/RTTI support

```text
*** UID:0001Y3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007T | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007T | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// No handwritten vtable or RTTI data should be emitted for [UID:0001Y3].
// The MapTileImageLib declaration, virtual destructor, and direct empty
// Singleton<MapTileImageLib> base regenerate the three-slot vtable and
// three-entry MapTileImageLib/LObject/Singleton class hierarchy.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 8: UID0000RG sole global definition

```text
*** UID:0000RG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000L5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
MapTileImageLib *g_pMapTileImageLib = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 9: UID0001OU covered backing storage

```text
*** UID:0001OU | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000RG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000RG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Backing storage for g_pMapTileImageLib is emitted by [UID:0000RG][g_pMapTileImageLib](by-global/g_pMapTileImageLib.md).
// This exact zero-initialized slot is published and cleared by the direct
// Singleton<MapTileImageLib> base lifetime; do not duplicate its definition.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Exact zero-initialized MapTileImageLib singleton slot with ten direct refs and direct Singleton base publication/unwind/ordinary/scalar lifetime; UID0000RG owns the sole source definition. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### Destination 10: UID0000L5 file prose only

- Do not add reconstruction metadata to the by-file root.
- Replace the current probable static-cleanup/helper explanation with the exact direct `Singleton<MapTileImageLib>` source route, constructor state-1 EH cleanup, implicit normal/scalar base destruction, and non-emitting target/scalar distinction.
- State that UID0000RG remains the one global definition and that constructor/destructor child bodies no longer handwrite singleton publication/clear.
- Preserve every unrelated tile-loading, record, draw, metadata-loader, resource, source-tree, and historical detail.

### Destination 11: UID000177 aggregate verify-only

- Preserve `86/91`, owner NONE, false/non-emitting index, exact four local children, padding, and target/scalar as out-of-range support. Only validator-managed link propagation from the UID000180 rename is expected.

### Destination 12: Application startup/shutdown verify-only

- Preserve current Application pages. They already record startup constructor call `0x004f6055` and shutdown singleton read/delete `0x004f6622`; no ownership or C++ change is required.

### Destination 13: supervisor-owned manual coverage

- Apply only the exact rows under `Exact Manual Supervisor-Owned Coverage Or Tracker Text`; B002 must not edit those files.

### Behavior/source-shape rationale

- The class and constructor declarations cause compiler publication before later member construction and establish the exact EH state that reaches UID000180.
- The empty direct base at PMD `+4` explains why the target ignores its receiver and why the first data field shares that displacement.
- The destructor body omits the zero store so compiler reverse-base destruction recreates the observed clear exactly once before LObject teardown.
- Blank target/scalar blocks avoid source APIs and ABI wrappers that the compiler already regenerates.
- Mid-2000s MSVC multiple-inheritance, EBO, FuncInfo, and scalar-deleting-wrapper shapes directly match the observed binary.

## Final Recommendation

- Destinations 1-10 are applied at full report detail. Destination 11 received the documented bounded prose-only drift repair with core index state unchanged; Destination 12 is verified read-only. Destination 13 exact manual text remains supplied but unapplied under supervisor-only ownership.
- Parent/source assignments: UID000180 and UID0002J2 retain semantic class owner UID00007T but no emitter; class/method/global routes remain under UID0000L5.
- Items left non-emitting: exact Singleton base destructor UID000180 and scalar deleting wrapper UID0002J2, because source declarations regenerate both.
- No future binary research is required for source behavior. Only original lexical template-header/static-member names remain unavailable and are not callback blockers.

## Recommended Target Doc Changes

- Applied target path: UID-preserving rename to `by-memory/0x004e5bc0-0x004e5bcb.MapTileImageLibSingletonBaseDestructor.md`; old path absent.
- Applied exact bytes/hash/instructions/range/padding/signatures, sole EH xref, constructor FuncInfo/unwind states, adjusted receiver, direct RTTI/BCD/PMD/EBO, ordinary/scalar copies, ten global refs, startup/shutdown, neighbor family, pointer/import negatives, accepted comparators, and source/no-code disposition.
- Applied metadata: `93/96`, owner UID00007T, false, blank emitter/position/formal, Nested 0, exact Item Summary.
- Preserved old helper title, B003/B011/B015 provenance, static-cleanup interpretation, and comment-bearing output only as explicitly superseded history with reasons.

## Recommended Support Doc Changes

- Applied `by-class/MapTileImageLib.md`: Destination 2, direct Singleton base, RTTI hierarchy, EBO, corrected method inventory/title, implicit lifetime, `92/94`.
- Applied `by-memory/0x004d1860-0x004d199e.MapTileImageLibConstructor.md`: Destination 3, state/unwind evidence, implicit publication, no manual assignment, `92/94`.
- Applied `by-memory/0x004d19a0-0x004d1a1c.MapTileImageLibDestructor.md`: Destination 4, implicit base clear, preserved resource body, `92/95`.
- Applied `by-memory/0x004e66a0-0x004e6748.MapTileImageLibScalarDeletingDestructor.md`: Destination 5, `93/96`, false/non-emitting, exact wrapper proof.
- Applied `by-type/by-struct/MapTileImageLibLayout.md`: Destination 6, direct bases/PMD/EBO/size, `92/96`.
- Applied `by-type/by-vtable/MapTileImageLibVtable.md`: Destination 7, exact COL/CHD/BCD hierarchy, `92/96`.
- Applied `by-global/g_pMapTileImageLib.md`: Destination 8, exact ten refs and direct-base lifetime, `91/94`.
- Applied `by-memory/0x0067a75c-0x0067a760.g_pMapTileImageLib.md`: Destination 9, exact storage/source cause, `91/94`.
- Applied `by-file/MapTileImageLib.md`: Destination 10 prose, `91/93`, no by-file reconstruction metadata.
- UID000177 concrete-drift prose was synchronized without metadata/range/child/formal change. Application file/startup/shutdown remained read-only at the hashes recorded above.

## Score And Metadata Recommendation

- Evidence-time target was `86/90`, file owner/emitter UID0000L5, true, blank position, comment formal, Nested 0.
- Applied target is `93/96`, semantic class owner UID00007T, false, blank emitter/position/formal, Nested 0.
- Completion rose seven points because helper identity, EH state, direct base type/displacement, source representation, owner, rename, no-code policy, global lifetime, pointer routes, and coverage text were resolved.
- Confidence rose six points because source identity is jointly direct from RTTI and control flow, not inferred from size/absence. It remains capped at 96 because original template header/static-member/global spelling is not symbolically recovered.
- Score blockers attempted: exact source identity resolved by RTTI BCD; liveness resolved by unwind map; static/atexit route rejected by imports/pointers/xrefs; normal lifetime resolved by ordinary/scalar copies; source placement resolved by class/file/global graph; range resolved by bytes/padding; naming resolved descriptively with historical aliases; generated duplication resolved by false/blank target and corrected class/method blocks.
- Support score changes are applied exactly in Destinations 2-10. No score was raised solely from inherited report text.

## Open Questions With Attempted Resolution

- Is UID000180 handwritten? Resolved no: adjusted EH receiver plus direct base RTTI and base-order copies prove compiler instantiation.
- Is it static cleanup or atexit? Resolved no: no registration/pointer/import route; startup/shutdown explicitly construct/delete; target is constructor-failure state action.
- Is the source a free helper or member? Resolved neither: generic direct base lifetime is the source construct.
- Why does the target not read `this`? Resolved: the Singleton specialization only clears static storage; receiver identity is carried by the adjusted EH action and RTTI.
- Why is the Singleton base at the same offset as `tileFrameTable`? Resolved: direct empty base EBO overlap at `+4`.
- Should constructor/destructor retain manual global writes? Resolved no: they are inlined base construction/destruction and would duplicate restored inheritance.
- Exact template header/static-member spelling? Unresolved lexically after RTTI, type catalog, current docs, generated source, all report roots, and symbol/string searches. This caps confidence but has no owner/C++/behavior impact; only original headers or symbols could recover it.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Callback readback inspected manual rows for UID000180, UID0002IZ, UID000178, UID0002J2, UID0001OU, UID00007T, UID0000L5, UID0000RG, UID0001V2, and UID0001Y3. Validator command `000000012203` propagated UID000180's renamed link into `by-memory/-coverage-report.md`; row classifications/scores/details and all other listed rows remain stale relative to applied ordinary state.
- Exact supervisor-owned replacement text remains below. B002 did not manually edit any coverage row or add tracker text.

`by-memory/-coverage-report.md` exact replacements:

```text
    - [UID:000180][0x004e5bc0-0x004e5bcb.MapTileImageLibSingletonBaseDestructor](by-memory/0x004e5bc0-0x004e5bcb.MapTileImageLibSingletonBaseDestructor.md) 0x004e5bc0-0x004e5bcb | source-declared/generated-binary base destructor | Singleton<MapTileImageLib> base destructor : not_reconstructable : 93% : very-strong : Exact eleven-byte EH-only Singleton base-destructor instantiation with unique bytes/signature, sole constructor state-1 tail-jump, direct `Singleton<MapTileImageLib>` RTTI PMD +0x04 and EBO identity, ordinary/scalar inlined copies, ten singleton-slot refs, exhaustive no-atexit/no-helper proof, semantic class owner UID00007T, and blank non-emitting formal C++.
        - [UID:0002IZ][0x004d1860-0x004d199e.MapTileImageLibConstructor](by-memory/0x004d1860-0x004d199e.MapTileImageLibConstructor.md) 0x004d1860-0x004d199e | constructor | MapTileImageLib::MapTileImageLib : reconstructable : 92% : very-strong : Exact source constructor with direct `Singleton<MapTileImageLib>` base initialization, compiler-lowered +0x04 EBO publication and state-1 cleanup, startup-only caller, metadata loading, `TILE.TBL` validation, 4-byte record allocation/decode, and no duplicate handwritten singleton assignment.
        - [UID:000178][0x004d19a0-0x004d1a1c.MapTileImageLibDestructor](by-memory/0x004d19a0-0x004d1a1c.MapTileImageLibDestructor.md) 0x004d19a0-0x004d1a1c | destructor | MapTileImageLib::~MapTileImageLib : reconstructable : 92% : very-strong : Unique handwritten ordinary destructor body with exact metadata/table/tile-record frees; direct Singleton base destruction owns the following global clear before LObject teardown, so the formal body contains no duplicate singleton assignment.
        - [UID:0002J2][0x004e66a0-0x004e6748.MapTileImageLibScalarDeletingDestructor](by-memory/0x004e66a0-0x004e6748.MapTileImageLibScalarDeletingDestructor.md) 0x004e66a0-0x004e6748 | source-declared/generated-binary scalar deleting destructor | MapTileImageLib scalar deleting destructor : not_reconstructable : 93% : very-strong : Exact vtable-only compiler ABI wrapper that expands the ordinary derived cleanup, implicit Singleton clear, LObject teardown, delete flags, size guard, and storage free; ordinary UID000178 is the sole handwritten destructor source and this formal block is blank.
    - [UID:0001OU][0x0067a75c-0x0067a760.g_pMapTileImageLib](by-memory/0x0067a75c-0x0067a760.g_pMapTileImageLib.md) 0x0067a75c-0x0067a760 | global pointer storage | g_pMapTileImageLib : reconstructable : 91% : very-strong : Exact four-byte zero-initialized singleton slot with ten direct refs; direct `Singleton<MapTileImageLib>` construction/destruction explains publication, constructor-unwind clear, ordinary clear, and scalar clear, while UID0000RG remains the sole source definition.
```

`by-class/-coverage-report.md` exact replacement:

```text
- [UID:00007T][MapTileImageLib](by-class/MapTileImageLib.md) : reconstructable : 92% : very-strong : Complete terrain tile image-library declaration with direct `LObject` and empty `Singleton<MapTileImageLib>` bases, exact three-entry RTTI hierarchy and PMD +0x04 EBO overlap, 0x0c layout, source constructor/destructor/draw inventory, file-local metadata loader, typed singleton storage, and compiler-only base-destructor/scalar/vtable distinctions.
```

`by-file/-coverage-report.md` exact replacement:

```text
- [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md) : reconstructable : 91% : very-strong : Terrain tile image-library source module in `NexusTK/render/` with complete class/global/helper/method routing, direct `Singleton<MapTileImageLib>` source lifetime, exact constructor-EH/ordinary/scalar singleton behavior, tile EPF/TBL loading, record decode/draw behavior, and non-emitting compiler base-destructor/scalar/vtable support.
```

`by-global/-coverage-report.md` exact replacement:

```text
- [UID:0000RG][g_pMapTileImageLib](by-global/g_pMapTileImageLib.md) : reconstructable : 91% : very-strong : Sole typed MapTileImageLib singleton definition at `0x0067a75c`, with ten exact refs spanning direct Singleton base publication/fallback/unwind/ordinary/scalar lifetime, explicit Application startup/shutdown, map/photo consumers, zero storage, class/file owner route, and no duplicate constructor/destructor definition.
```

`by-type/by-struct/-coverage-report.md` exact replacement:

```text
- [UID:0001V2][MapTileImageLibLayout](by-type/by-struct/MapTileImageLibLayout.md) : reconstructable : 92% : very-strong : Exact 0x0c MapTileImageLib layout with LObject at +0x00, direct empty Singleton<MapTileImageLib> RTTI base at PMD +0x04 overlapping `tileFrameTable` by EBO, `tileRecords` at +0x08, and constructor/draw/destructor validation without duplicate layout C++.
```

`by-type/by-vtable/-coverage-report.md` exact replacement for both duplicate UID0001Y3 rows:

```text
- [UID:0001Y3][MapTileImageLibVtable](by-type/by-vtable/MapTileImageLibVtable.md) : reconstructable : 92% : very-strong : Exact COL `0x00648774`, three-entry MapTileImageLib/LObject/Singleton hierarchy, direct Singleton PMD +0x04, primary table `0x0061b664` with scalar deleting wrapper and inherited slots, constructor/destructor vptr refs, successor boundary, and compiler-regenerated no-raw-vtable disposition.
```

- Reason B002 must not apply these directly: manual coverage is supervisor-owned; ordinary page validators do not authorize B agents to edit it, and validator-generated coverage is not a substitute.

## Follow-Up Actions

- B002 ordinary implementation, scoped validation, lease release, final generated readback, and same-report reconciliation are complete. No additional B002 source research or ordinary edit remains in this callback.
- Manual coverage and any current/future report validation, execution, move, archive, tracker, report-count, or lifecycle state are external validator/supervisor-owned and are not asserted by this report.
- A-agent actions: none.

## Confidence

- Recommendation confidence: very strong.
- Score confidence: strong; comparator parity supports `93/96` for the target and scalar, while source pages retain lower caps for unresolved historical lexical names.
- Remaining uncertainty: original Singleton template header/static-member and global symbol spelling only; no behavioral, range, owner, emission, formal C++, or callback blocker remains.

## Validator Results

- All implementation validation commands ran from `source-3/project-documentation` as scoped file validators with `--apply --queue-timeout 240`; each returned process exit `0`, validator `ok:1`, and deferred generation unless noted. Informational command `000000012231` printed validator CLI help only; it performed no scan, apply, or generated refresh.

| Command | Timestamp | Scoped page / purpose | Result, warnings, and side effects |
| --- | --- | --- | --- |
| `000000012203` | `2026-07-14T20:42:23-04:00` | renamed UID000180 target | `ok:1`; `path_update:1`; owner/score/autogen state applied; `uid_link_update:16`; old path removed before scan. Existing repository-wide `missing_ref_uid:293` warnings were reported. Validator-managed path propagation touched known references including class/file/global pages, `by-memory/-coverage-report.md`, `by-memory/-ignored.md`, and the neighboring LightObj helper page; no manual coverage edit occurred. |
| `000000012204` | `2026-07-14T20:43:39-04:00` | UID00007T class | `ok:1`; `92/94`; formal hash updated; no warning. |
| `000000012205` | `2026-07-14T20:44:34-04:00` | UID0002IZ constructor | `ok:1`; `92/94`; formal hash/reference index updated; no warning. |
| `000000012206` | `2026-07-14T20:45:27-04:00` | UID000178 destructor | `ok:1`; `92/95`; formal hash updated; no warning. |
| `000000012207` | `2026-07-14T20:46:21-04:00` | UID0002J2 scalar wrapper | `ok:1`; `93/96`; true/emitter/comment state changed to false/blank; no warning. |
| `000000012216` | `2026-07-14T20:47:33-04:00` | UID0001V2 layout | `ok:1`; `92/96`; formal hash updated; generated stats row removal/rescore recommendation only. |
| `000000012218` | `2026-07-14T20:48:24-04:00` | UID0001Y3 vtable | `ok:1`; `92/96`; formal hash updated. Three pre-existing `missing_ref_uid 0003BQ` warnings remain on this page; they are unrelated to UID000180 and were not introduced by the callback. |
| `000000012219` | `2026-07-14T20:49:16-04:00` | UID0000RG global | `ok:1`; `91/94`; generated stats row removal/rescore recommendation only. |
| `000000012221` | `2026-07-14T20:50:02-04:00` | UID0001OU storage | `ok:1`; `91/94`; formal hash updated; no warning. |
| `000000012225` | `2026-07-14T20:51:07-04:00` | UID0000L5 by-file prose | `ok:1`; `91/93`; reference index updates only; no by-file reconstruction metadata. |
| `000000012227` | `2026-07-14T20:51:23-04:00` | first waited readback | `ok:1`; `generated_refresh:completed`; later superseded only because the documented UID000177 drift repair became an additional ordinary change. Repository-wide existing autogen warnings were emitted. |
| `000000012229` | `2026-07-14T20:53:53-04:00` | UID000177 bounded prose drift repair | `ok:1`; metadata/range/formal/children unchanged; no warning. |
| `000000012230` | `2026-07-14T20:54:08-04:00` | second waited readback | `ok:1`; `generated_refresh:completed`; later superseded only because final report audit found one transcribed target-byte SHA256 in Destination 1 did not match the report's already-correct local hash. Existing repository-wide autogen warnings were emitted. |
| `000000012231` | `2026-07-14T21:04:42-04:00` | validator CLI syntax check | Usage/help output only; no page scan, apply, generated refresh, or documentation side effect. |
| `000000012232` | `2026-07-14T21:05:17-04:00` | UID000180 evidence-hash transcription correction | `ok:1`; exact bytes unchanged; corrected only the SHA256 spelling to `713E52BBE86EE6798C2A3DD7CAEB42D40A7A658E0736B01351DB0FCD4103EEF7`; projected-stats update/no-op note only; generated refresh deferred. |
| `000000012233` | `2026-07-14T21:05:29-04:00` | final `--wait-generated` refresh | `ok:1`; `generated_refresh:completed`; generated registry rebuilt and validator-owned generated metadata refreshed. Existing repository-wide `autogen_children_*`/`autogen_emitter_has_no_code` warnings are unrelated to this target. |

- Final generated readback: `auto-generated/NexusTK/render/MapTileImageLib.cpp`, SHA256 `6011218F8DF959EC4CF1C1B85F1710CE4D0BF61EEE6DB4ACF50589633F85C36A`; header command `000000012233`, refreshed `2026-07-14T21:05:29-04:00`.
- Exact count/absence proof: class `1`; constructor `1`; destructor `1`; DrawTile `1`; loader `1`; typed global definition `1`; indented/manual constructor assignment `0`; indented/manual destructor clear `0`; UID000180 marker/body `0`; UID0002J2 marker/body `0`; stale helper/title aliases `0`; raw vtable/RTTI/scalar ABI declarations or definitions `0` (explanatory no-code comments remain). Source order is class, constructor, destructor, DrawTile, support types/global, loader, with no unrelated MapTile behavior removed.
- Evidence-time MCP listing timeout remains historical research evidence only. Callback used no MCP/IDA operation and asserts no present session state.

## Changed Files

- Renamed under UID-preserving validator workflow: `by-memory/0x004e5bc0-0x004e5bcb.MapTileImageLibSingletonClearHelper.md` -> `by-memory/0x004e5bc0-0x004e5bcb.MapTileImageLibSingletonBaseDestructor.md`; old path absent.
- Modified ordinary destinations: `by-class/MapTileImageLib.md`; constructor UID0002IZ; destructor UID000178; scalar wrapper UID0002J2; `by-type/by-struct/MapTileImageLibLayout.md`; `by-type/by-vtable/MapTileImageLibVtable.md`; `by-global/g_pMapTileImageLib.md`; singleton storage UID0001OU; `by-file/MapTileImageLib.md`; bounded concrete-drift aggregate UID000177.
- Verify-only unchanged: `by-file/Application.md`, Application startup UID0002H7, Application shutdown UID0002H8, UID0002J0 DrawTile, UID0002J1 loader, UID0003BQ raw vtable data, and unrelated MapTile support.
- Validator-managed rename-reference side effects included path-only updates in `by-memory/-coverage-report.md`, `by-memory/-ignored.md`, and `by-memory/0x004e5bb0-0x004e5bbb.LightObjImageLibSingletonClearHelper.md`, plus references in changed MapTile pages. These were not manual edits and did not alter supervisor-owned coverage semantics.
- Validator-owned generated files and metadata were refreshed by commands `000000012227`, `000000012230`, and final command `000000012233`; B002 did not edit them manually.
- Updated this same report: `tools/leaser/Agents/Agent-B002/research/000180-MapTileImageLibSingletonClearHelper-source-quality.md`.
- Lease proof: eleven distinct ordinary pages were edited through twelve successful Agent-B002 lease/edit/validator/release passes because Destination 1 received the final one-line evidence-hash correction under a fresh lease; every lease was released immediately after its scoped validator, and final `tools/leaser/Agents/current_leases.md` contains zero active lease rows.
- Restricted-command proof: no manual coverage/generated/tracker/audit/supervisor/validator-state/lifecycle/archive/IDA edit; no `execute_report`, report-count/registry probe, lifecycle, move, or archive command ran.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor exact-artifact Gate 1 validation accepted SHA `7149D77C...ECFAF7` before implementation.
- [x] UID000180 target: UID-preserving rename to `by-memory/0x004e5bc0-0x004e5bcb.MapTileImageLibSingletonBaseDestructor.md`; applied `93/96`, class semantic owner, false, blank emitter/position/formal, exact Item Summary, Nested 0, and full evidence.
- [x] `by-class/MapTileImageLib.md`: applied Destination 2, direct Singleton base, exact hierarchy/EBO/lifetime, corrected inventory, and `92/94`.
- [x] `by-memory/0x004d1860-0x004d199e.MapTileImageLibConstructor.md`: applied Destination 3, `92/94`, direct base initializer, state/unwind proof, and no manual global assignment.
- [x] `by-memory/0x004d19a0-0x004d1a1c.MapTileImageLibDestructor.md`: applied Destination 4, `92/95`, preserved frees, and removed implicit base clear from the authored body.
- [x] `by-memory/0x004e66a0-0x004e6748.MapTileImageLibScalarDeletingDestructor.md`: applied Destination 5, `93/96`, class semantic owner, false, blank emitter/position/formal, and exact ABI no-code proof.
- [x] `by-type/by-struct/MapTileImageLibLayout.md`: applied Destination 6, direct bases/PMD/EBO/size, no duplicate class C++, and `92/96`.
- [x] `by-type/by-vtable/MapTileImageLibVtable.md`: applied Destination 7, exact COL/CHD/base descriptors and compiler-only ABI, and `92/96`.
- [x] `by-global/g_pMapTileImageLib.md`: applied Destination 8, retained the sole definition, synchronized ten refs/direct-base lifetime, and set `91/94`.
- [x] `by-memory/0x0067a75c-0x0067a760.g_pMapTileImageLib.md`: applied Destination 9, retained covered storage/no duplicate, added direct-base lifetime, and set `91/94`.
- [x] `by-file/MapTileImageLib.md`: applied Destination 10 prose only, no reconstruction metadata, preserved unrelated tile source, and set `91/93`.
- [x] UID000177 concrete drift was documented before its bounded prose repair; `86/91`, owner/range/formal/children/padding remain unchanged. Application startup/shutdown pages passed read-only Destination 12 verification.
- [x] Supervisor-owned manual coverage: Destination 13 exact replacements remain supplied and B002 did not manually edit the files; validator path propagation only is recorded.
- [x] Current target state and actual evidence checked are recorded archive-neutrally.
- [x] Claim And Incorporation Ledger updated for C01-C30; Action values remain restricted to `incorporate`, `already-present`, `historicalize`, `reject-stale`, `reject-invalid`, or `not-applicable`; terminal states are `29 applied`, `1 excluded-with-reason`, `0 blocked`.
- [x] Metadata/score changes applied: target `93/96`; exact support scores in Destinations 2-10.
- [x] Score-limiting blockers resolved, including RTTI, EH, static/atexit, duplicate stores, source identity, ownership, and no-code state.
- [x] Owner/emitter/reconstructable changes applied: target and scalar semantic class owner, false, blank emitter/position/formal.
- [x] Split/rename/new-child decision applied: UID-preserving target rename only; no split/new child.
- [x] Source-placement, range, padding, reclassification, and descriptive rename decisions applied.
- [x] Exact source C++ and no-code proof applied only through Destinations 1-9 managed blocks.
- [x] Third-party import directive confirmed not applicable.
- [x] Exact target/support facts incorporated at report-level detail.
- [x] Historical B003/B011/B015 assumptions, rejected helper names, and negative evidence preserved.
- [x] Wave2/Wave3 mentions retained only as stale historical authority.
- [x] Open questions closed or documented as lexical-only uncertainty.
- [x] One scoped validator ran for each changed ordinary page; final authorized waited generated refresh completed.
- [x] Generated verification proved one complete class, one ctor/dtor/draw/loader, one typed global, zero manual constructor/destructor stores, no UID000180/UID0002J2 output, and no handwritten ABI/vtable data.
- [x] Exact supervisor-owned manual coverage rows supplied and left unapplied by B002.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation.
- [x] Re-read every destination and active lease state before each edit.
- [x] UID-preserving rename applied and old ordinary path absent.
- [x] All accepted target/support details incorporated without loss; one documented UID000177 concrete-drift repair was bounded to prose.
- [x] C01-C30 ledger states changed to legal final callback states with separate destination/hash proof.
- [x] Metadata/score/owner/emitter/rename/formal changes applied exactly.
- [x] Historical assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions and lexical confidence caps synchronized.
- [x] One short lease used per ordinary edit and released immediately after scoped validation.
- [x] Scoped validator command id/timestamp/exit/ok/warnings/side effects recorded for every changed ordinary page.
- [x] Final waited generated refresh completed and exact source/absence/count/order assertions recorded.
- [x] Manual coverage rows left under supervisor ownership; only validator-managed UID path propagation occurred.
- [x] Every lease released; no ordinary accepted claim remains unapplied. C30 manual coverage application is explicitly external/excluded-with-reason.
- [x] No execute_report, lifecycle, move, archive, manual generated, tracker, audit, supervisor, validator-state, coverage, or IDA mutation command used.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000012358","destination_path":"executed-b-agent-research/B002/000180-MapTileImageLibSingletonClearHelper-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/000180-MapTileImageLibSingletonClearHelper-source-quality.md","timestamp":"2026-07-14T21:51:27-04:00","uid":"000180"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
