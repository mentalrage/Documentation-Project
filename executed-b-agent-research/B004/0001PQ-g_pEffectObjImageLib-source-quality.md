** TARGET-REPORT-UID:0001PQ **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

# 0001PQ g_pEffectObjImageLib Source-Quality Research

## Finalized Report / Current Recommendation

- Implemented recommendation: [UID:0001PQ] `by-memory/0x0069b44c-0x0069b450.g_pEffectObjImageLib.md` is now `92/94`, `RECONSTRUCTABLE:FALSE`, owner UID0000QT, blank emitter/position/formal C++, and `Nested:0`; the prior `86/90` reconstructable marker state is historical.
- One-definition result: [UID:0000QT] `by-global/g_pEffectObjImageLib.md` is the sole source definition, with external linkage and exact C++03-era source `EffectObjImageLib *g_pEffectObjImageLib = 0;`; the complete class declaration supplies one `extern` declaration.
- Lifetime decision: source declares `EffectObjImageLib : public LObject, public Singleton<EffectObjImageLib>`. Direct RTTI and PMD `+4/-1/0` prove empty-base optimization and explain the constructor publication, constructor-unwind clear, ordinary-destructor clear, scalar-wrapper clear, and tiny clear helper without handwritten singleton assignments.
- Physical-data decision: the target lies in the loader-zero tail of `.data`, beyond the section's file-backed raw size. It has no valid raw PE file offset; current IDB bytes are four zero bytes. Historical `0xffffffff` is rejected as a stale or invalid raw-offset interpretation.
- Source closure: the callback supplied complete class, global, constructor, and ordinary-destructor C++; kept the physical slot, local cluster, layout, singleton-clear helper, scalar deleting destructor, vtable, and exact vtable data blank/non-emitting with exhaustive source-declared/generated-binary proof; and preserved existing render/get-info/load/helper bodies.
- Callback state: all twelve accepted ordinary destinations were updated and scoped-validated under one-file leases; command `000000015948` completed the waited generated refresh. B004 manually edited no coverage/generated/tracker/audit/supervisor/validator/IDA/lifecycle file and ran no report lifecycle command. External report validation/execution/movement/archive/count state remains supervisor/validator-owned and is not asserted by this artifact.

## Supporting Research

- Live IDA MCP database `9b0396a3` was rediscovered through `idb_list` on 2026-07-21 at `14:41:24-04:00`. `server_health` returned `status:ok`, image base `0x00400000`, auto-analysis ready, Hex-Rays ready, and string cache ready with 2,067 entries. Bounded `get_bytes(0x0069b440,24)` returned 24 zero bytes, including the exact target.
- Current executable input is `C:/Users/admin/Desktop/Clone/NexusTK/NexusTK.exe`, SHA256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`. Structured PE parsing identifies `.data` at VA `0x0066d000`, virtual size `0x2fe24`, raw pointer `0x0026ac00`, and raw size `0x0000d800`.
- The target's `.data` relative offset is `0x2e44c`, which is inside virtual size but outside raw size. The arithmetic expression `0x26ac00 + 0x2e44c = 0x29904c` is not a valid target file offset because it crosses the `.data` raw extent. Windows loader zero-fill, not a file-backed dword, supplies the initial four zero bytes.
- Concrete prior-report searches used `UID0001PQ`, `UID:0001PQ`, `0x0069b44c`, `0x69b44c`, `g_pEffectObjImageLib`, `dword_69B44C`, `unk_69B44C`, `EffectObjImageLib`, `Singleton<EffectObjImageLib>`, `0x004ddf60`, `0x004de050`, `0x004e5b70`, `0x004e62f0`, `EFFECT.EPF`, `ApplicationStartup`, `ApplicationShutdown`, `EffectObjectPane`, and owner/source-family terms.
- At research preflight, `tools/leaser/Agents/Agent-B001` through `Agent-B005` were searched and no then-active report claimed UID0001PQ or any accepted ordinary destination. The B005 report then active at `tools/leaser/Agents/Agent-B005/research/00029O-MainUiLayerSlotsTail-source-quality.md` contained only broad `new EffectObjImageLib` and `delete g_pEffectObjImageLib` startup/shutdown lines; it was an incidental lifecycle lead with no target ownership, score, formal, or callback claim.
- `executed-b-agent-research/B008/0000IY-EffectObjImageLib-empty-emitter-family-source-quality.md`, SHA256 `D1516B0456BDE46F6A7166E5468179884BAA26B9A38FDB898633DD411FD12859`, was opened as the broad family baseline. Its method/resource inventory remains useful, but its class marker, reconstructable physical-slot marker, and explicit singleton assignments predate the direct Singleton-base proof and are superseded by this target-specific pass.
- `executed-b-agent-research/B002/0002H9-EffectObjImageLibConstructor-empty-emitter-source-quality.md`, SHA256 `A72443A0F8FAF3534DB7CCE61751E6368EE4360F4272D5E89D9122132327076A`, was opened. Its exact body, caller, resource, and failure-path evidence is retained; its explicit `g_pEffectObjImageLib = this` source is superseded by direct `Singleton<EffectObjImageLib>` RTTI/PMD and the `this == -4` adjustment chain.
- `executed-b-agent-research/B004/00017W-EffectObjImageLibSingletonClearHelper-source-quality.md`, SHA256 `5E1F716172EC81D804F2F1CFA4EC05FDAE8F7E07D4D2765F169C98A0FCCEA03A`, was opened. Its exact two-instruction body and no-ordinary-caller evidence are retained; its remaining open static-lifetime wording is closed as compiler lowering of the direct Singleton base.
- `executed-b-agent-research/B007/0002H7-ApplicationStartup-source-quality.md`, SHA256 `B0968756A5E4415DA44DA4C69B2BF85C82A15D7AE06EF12900784B291C83E3FF`, and `executed-b-agent-research/B008/0002H8-ApplicationShutdown-empty-emitter-source-quality.md`, SHA256 `519E9822E7C580873CAA332FF100C7FD99BD4A06A088F0843087C3CF674B6041`, were opened. They confirm allocation/construction and virtual deletion order but remain lifecycle consumers, not source owners of this definition.
- Consumer reports opened and classified were B010 EffectObjectPaneCore SHA256 `6A45B65C3CEF484A1EB174C699D3EB2022CC92A023644DE0C6F4E4797BDFC7F5`, B007 MapPaneObjectEffectDescriptorDispatch SHA256 `C4E6FDB3199A9C0F06057395223BA5C03DEECE33E4F4709FDB3AC349A1403B38`, B005 MapPaneCoordinateEffectDescriptorDispatch SHA256 `D39EB77C34DE4A8020664853D053CE016E6399AB801EBCD11000CE55CFF02583`, and B001 UserPaneProcessMovement SHA256 `93F0BCAC417B6C72E1A368963D0104ACD85595CD5EF264B57A2B81DF8DAF9AE8`. Each corroborates a read route and none supplies storage or ownership.
- `tools/leaser/Agents/Older-Research/**` and `tools/leaser/Agents/SpecialReports/**` were explicitly searched with the same UID/address/global/class/helper/source-family terms; neither root has a direct match. The actual project `archived/**` root exists and contains zero Markdown reports.
- Current comparator [UID:0001P2] `g_pFontImageLib` and its class/global/constructor/destructor/vtable family were opened. That independently accepted `LObject, Singleton<T>` family has the same PMD `+4/-1/0`, compiler-lowered publication/reverse clear, one semantic global definition, false physical storage, complete class declaration, and blank compiler pages. It is policy corroboration, not substitute target evidence.

## Target

- UID: `0001PQ`.
- Path: `by-memory/0x0069b44c-0x0069b450.g_pEffectObjImageLib.md`.
- Range: `[0x0069b44c,0x0069b450)`, exactly four bytes.
- Pre-callback file SHA256: `60EFC3E11A51A128F58F884BF92A09A4C6A7F7A7EF2F0D33E1DC9F3E755AA859`, 9,928 bytes / 101 lines.
- Exact target-byte SHA256: `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119` for `00 00 00 00`.
- Historical pre-callback metadata: `86/90`, owner/emitter UID0000QT, reconstructable true, blank position, marker-only formal, `Nested:0`.
- Current implemented metadata: `92/94`, owner UID0000QT, reconstructable false, blank emitter/position/formal, `Nested:0`; current SHA256 is `04E6C53C17B97640F1F5BC14EEE389A757AAB2C22C1ED37E69115000172A4770`, 11,681 bytes / 106 lines.

## Current Target State

- The ordinary target records exact loader-zero/no-raw-file evidence, all 12 xrefs, direct Singleton-base cause, false/non-emitting metadata, and an exactly blank formal block. The current manual by-memory row remains materially stale and still says `0xffffffff`; the literal supervisor-owned replacement below remains unapplied.
- Semantic [UID:0000QT] emits the sole definition at position `4` with external-linkage/header-extern/one-definition and implicit direct-base lifetime proof. [UID:00004A] emits the complete direct-base class closed before `[[CHILDREN]]`.
- UID0002H9 and UID00017L retain all authored behavior and contain zero explicit global lifecycle assignments. UID00017W, UID0002HC, UID0001U9, UID0001XG, UID0002MK, UID0001PQ, and UID00017K are false/blank non-source pages as accepted.
- Commands `000000015889`, `000000015922`, `000000015932`, `000000015933`, and `000000015935` are historical research checkpoints. B004 scoped implementation commands are `000000015936` through `000000015947`; B004's waited command/header `000000015948` refreshed at `2026-07-21T15:16:14-04:00` and remains the durable implementation proof.
- At B004 callback verification time command 15948 produced `EffectObjImageLib.cpp` SHA256 `4363623841663DFE9E9C6583D849902A7E86610F966D00395D6EBD4007AE94FE`, 15,304 bytes / 498 lines. Unrelated external commands 15956/15957 are historical intermediate checkpoints. At final readback, external command/header `000000015959`, refreshed `2026-07-21T15:28:49-04:00`, produced current SHA256 `FA31878988CEFBBBCA0D584CA700AF4049E7397450B7E759E1ACD2FF41EFF98E`, with unchanged 15,304-byte / 498-line structure and the same verified semantics: one complete direct-base class; one global definition; one each constructor/destructor/RenderEffectFrame/GetEffectInfo/LoadEffectTables definition; one BuildEffectArchiveTable definition; one GetSpriteBounds definition; zero UID0001PQ/00017W/0002HC/0001U9/0001XG/0002MK/00017K and `Empty Emitter Marker`; and no explicit singleton lifecycle write, raw label, vptr, cookie, delete flag, `sub_`, or `loc_` source.
- At B004 callback verification time command 15948 produced tracker SHA256 `32F24ADAF597AA36009C951650D8EF229A87800B1603218EF5E6EEEBD8D0D0C1`, 1,548,249 bytes / 6,263 lines. Commands 15956/15957 are historical intermediate external checkpoints. At final readback, current external command/header `000000015959`, refreshed `2026-07-21T15:28:49-04:00`, produced tracker SHA256 `C99C5725E3A5EC4ECAD9ED7C829CC09E2461C8629386F02DE8B7B8B4322F3D6B`, 1,548,360 bytes / 6,263 lines. Generated/tracker provenance may advance again; command-15948 semantics are durable callback evidence and command 15959 is time-bounded final-readback authority.
- Implementation and validators are complete with zero leases. External report validation/execution/count/path/movement/archive state is supervisor/validator-owned and not tracked as pending or asserted here.

## Executive Recommendation

- UID0001PQ is implemented as exact physical singleton backing storage, not a second source definition: false/non-emitting with every byte/xref/lifetime/neighbor fact retained.
- `g_pEffectObjImageLib` remains the highest-probability human source symbol with type `EffectObjImageLib *`, external linkage, one header `extern`, and one `NexusTK/render/EffectObjImageLib.cpp` definition initialized to `0`.
- `EffectObjImageLib : public LObject, public Singleton<EffectObjImageLib>` is implemented. The direct empty singleton base carries publication and reverse clear; constructor/destructor source contains no explicit global lifecycle statements.
- The class marker was replaced by the complete declaration closed before `[[CHILDREN]]`; existing method bodies and type declarations were preserved, with only the accepted constructor/destructor lifecycle and compiler-support corrections applied.
- UID00017W, UID0002HC, UID0001U9, UID0001XG, UID0002MK, UID0001PQ, and UID00017K are blank/non-emitting while retaining their complete binary evidence in prose.
- Application, MapPane, UserPane, EffectObjectPane, render/get-info/load helpers, adjacent globals, LObject, ProtectedArray, and shared resource pages were verified same-or-greater and remained unchanged.

## Supervisor Active Recheck

- Historical Gate 1 checks covered target bytes/PE mapping, all 12 references, direct-base RTTI, one-definition source placement, source-clean formal blocks, no-code proof, score rationale, manual rows, generated route, old-report classifications, and an unchecked callback plan.
- Callback verification confirms no child registration or rename was required and edits remained bounded to UID0001PQ, UID0000QT, UID00004A, UID0000IY, UID00017K, UID0002H9, UID00017L, UID00017W, UID0002HC, UID0001U9, UID0001XG, and UID0002MK.
- Source-bearing UID00017M, UID0002HA, UID0002HB, UID0000U4, and UID0000UR remained verify-only with their current formals and hashes unchanged.
- Formal report validation, implementation review, execution, path, movement, archive, and counting are external supervisor/validator concerns; this section records evidence boundaries without directing or asserting those lifecycle actions.

## Inference Research Guidance Check

- Direct facts are limited to bytes, sections, raw-size bounds, xrefs, functions, calls, decompilation, RTTI names/PMDs, vtables, allocation/lifetime routes, and absence results.
- `g_pEffectObjImageLib`, member names, header/implementation split, and `= 0` spelling are source inferences. They are selected from the complete project family and compiler behavior, not represented as recovered debug symbols.
- The `this == -4` branch is not read literally as authored source. RTTI proves a direct Singleton base at `+4`; subtracting that adjustment from a null base pointer yields the decompiler's `-4` complete-object artifact.
- The historical `0xffffffff` claim is not retained as an alternate current initializer. Structured PE bounds prove the target has no file-backed bytes, and live loader/IDB state is zero.
- `= 0` is chosen over `NULL` and omitted initializer because current project source policy is C++03-era, existing singleton definitions use `0`, and the exact generated definition already uses `0`. `NULL` or no initializer would be runtime-equivalent but less consistent; `nullptr` is anachronistic.

## Heuristic / Inference Reanalysis And Validation

1. **Raw value.** The target is in `.data` virtual tail, not its raw file extent. Four loader zeros are exact. `0xffffffff` and any raw offset at `0x29904c` are rejected.
2. **Pointer width and type.** PE32, four-byte storage, receiver use in `GetEffectInfo`, `GetSpriteBounds`, `RenderEffectFrame`, and virtual deletion establish `EffectObjImageLib *`.
3. **Name.** `g_pEffectObjImageLib` is supported by existing source family, symmetric image-library globals, startup/shutdown reconstruction, and all consumers. `dword_69B44C` and `unk_69B44C` are rejected as source names.
4. **Linkage.** Application, MapPane, UserPane, and EffectObjectPane read the symbol across source modules. File-static/internal linkage is rejected; one external definition plus header extern is required.
5. **Physical versus semantic page.** UID0001PQ is binary storage evidence; UID0000QT is the semantic source definition. Emitting both would violate one-definition behavior.
6. **Class hierarchy.** EffectObjImageLib CHD has three entries: EffectObjImageLib, LObject BCD `??_R1A@?0A@EA@LObject@@8`, and `Singleton<EffectObjImageLib>`. Singleton PMD is `+4/-1/0`, attribute `0x40`, proving a direct non-virtual empty base.
7. **Base order.** Constructor calls LObject setup before singleton publication, and ordinary teardown clears singleton before LObject destruction. Source order `LObject, Singleton<EffectObjImageLib>` exactly regenerates that forward/reverse order.
8. **Constructor lowering.** `this == -4`, global store/clear, and adjustment are compiler output from `Singleton<EffectObjImageLib>()`; explicit branch, pointer arithmetic, vptr stores, and global assignment are rejected from authored source.
9. **Destructor lowering.** Authored resource cleanup precedes global clear and LObject teardown. Reverse direct-base destruction regenerates both tail operations; explicit global clear and base-destructor call are rejected.
10. **Tiny clear helper.** Exact bytes `c7 05 4c b4 69 00 00 00 00 00 c3`, one constructor cleanup xref, no receiver, no callees, and no ordinary callers prove compiler EH/static cleanup support, not `ClearEffectObjImageLibSingleton()`.
11. **Scalar wrapper.** Vtable-only dispatch, delete flags, full ordinary cleanup parity, optional operator delete, and receiver return prove compiler scalar deleting-destructor output. It has no authored body.
12. **Vtable/RTTI.** Three slots are compiler scalar destructor, inherited `LObject::GetRuntimeClass`, and inherited default `LObject::OnChangeMessage`. The source class and virtual destructor regenerate all table/RTTI bytes; handwritten arrays are rejected.
13. **Layout.** Application allocates exactly `0x60` bytes. LObject occupies `+0`; singleton EBO occupies/overlaps `+4`; the first ProtectedArray also begins at `+4`. The rest remains exact through `effectFileInfo +0x5c`, ending at the exact `0x60` object size.
14. **Startup.** Application allocates/constructs the object once at `0x004f6113`. Startup is a consumer/lifecycle orchestrator, not the source owner.
15. **Shutdown.** Application reads the global at `0x004f65d2` and dispatches virtual delete if nonzero. This proves externally visible lifetime, not a second definition.
16. **Seven readers.** Three descriptor lookups, three EffectObjectPane bounds/render routes, and one shutdown read use the same typed pointer. No reader writes or owns storage.
17. **Source file.** Existing owner, resource literals, method island, helper order, and generated route select `NexusTK/render/EffectObjImageLib.cpp`. `Effects.cpp`, MapPane, Application, or generic ImageLib placement is rejected.
18. **Score blockers.** Raw mapping, initializer, symbol, type, linkage, owner, lifetime cause, class hierarchy, no-code pages, source placement, and one-definition routing are resolved. Remaining private lexical uncertainty caps confidence but does not block implementation.

## Evidence Standards Used

- Primary: live IDA MCP `idb_list`, `server_health`, `get_bytes`, `lookup_funcs`, `decompile`, `xref_query`, `entity_query`, names, vtable/RTTI reads, and bounded negative searches on database `9b0396a3`.
- Independent raw evidence: SHA256 and structured PE section parsing of the exact executable, with virtual-versus-raw range validation rather than blind VA arithmetic.
- Structural: constructor/destructor order, direct-base PMD, EBO overlap, vtable slots, startup/shutdown call shape, one-definition requirement, and all 12 direct data references.
- Documentation: current target/support pages, current generated source, current manual rows, current by-file route, adjacent singleton pages, LObject source contract, and executed reports opened as leads.
- Negative: no raw target bytes, no second storage definition, no source-level clear-helper caller, no handwritten scalar-wrapper route, no consumer-owned storage, no alternate class type, and no direct prior target report.
- Comparator: independently accepted FontImageLib direct-base/physical-storage policy, used only after target evidence independently established the same compiler shape.

## Evidence Checked

- Target bytes `[0x0069b44c,0x0069b450)`, 24-byte neighbor window, target-byte SHA, segment identity, PE virtual/raw bounds, and executable SHA.
- Exactly 12 data xrefs, with function starts/sizes and per-site read/write classification.
- Constructor `0x004ddf60-0x004de04e`, ordinary destructor `0x004de050-0x004de189`, clear helper `0x004e5b70-0x004e5b7b`, scalar wrapper `0x004e62f0-0x004e6456`, startup `0x004f5fb0`, and shutdown `0x004f6490`.
- Consumer functions `0x0050e320`, `0x0050e850`, `0x005388c0`, `0x00538960`, `0x00538af0`, and `0x005a2e00`.
- EffectObjImageLib RTTI COL/CHD/base array, LObject BCD at `0x00640348`, Singleton BCD at `0x00648e44`, PMD `+4/-1/0`, and three-slot vtable data.
- Current target/global/class/file/layout/cluster/constructor/destructor/clear/scalar/vtable/vtable-data pages and exact hashes.
- Historical research-time generated `EffectObjImageLib.cpp` at command 15935, its emitted UID inventory, missing member definitions, and marker state; commands 15889/15922/15932 are earlier historical checkpoints.
- Callback-time generated `EffectObjImageLib.cpp` at command 15948, SHA256 `4363623841663DFE9E9C6583D849902A7E86610F966D00395D6EBD4007AE94FE`, 15,304 bytes / 498 lines, and its exact one-definition/source-body/no-marker assertions.
- Historical research-time tracker command 15935 and earlier command 15933; callback-time tracker command 15948, SHA256 `32F24ADAF597AA36009C951650D8EF229A87800B1603218EF5E6EEEBD8D0D0C1`, 1,548,249 bytes / 6,263 lines. Tracker lifecycle remains external validator-owned.
- Historical external refreshes 15956/15957 and final-readback external command 15959 were read. At command 15959 generated SHA256 is `FA31878988CEFBBBCA0D584CA700AF4049E7397450B7E759E1ACD2FF41EFF98E` and tracker SHA256 is `C99C5725E3A5EC4ECAD9ED7C829CC09E2461C8629386F02DE8B7B8B4322F3D6B`; generated semantics remain identical to command 15948.
- Current by-memory, by-global, by-class, by-file, by-struct, and by-vtable manual rows and hashes.
- Active B001-B005 roots, executed reports listed under Supporting Research, `Older-Research`, `SpecialReports`, and actual `archived` root.
- Adjacent singleton storage pages and current FontImageLib comparator family.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C1PQ-001 | Target is exact `[0x0069b44c,0x0069b450)` four-byte storage. | 100 | IDB item/range and adjacent pages | UID0001PQ range/storage | incorporate | applied |
| C1PQ-002 | Target bytes are `00 00 00 00`, hash `DF3F...B81119`. | 100 | MCP get_bytes | UID0001PQ storage/evidence | incorporate | applied |
| C1PQ-003 | Target is loader-zero `.data` virtual tail with no valid raw bytes. | 99 | PE section parser/raw-size bound | UID0001PQ storage/evidence | incorporate | applied |
| C1PQ-004 | Historical `0xffffffff` is stale and rejected. | 99 | no raw mapping plus live zero bytes | UID0001PQ history/manual row | reject-stale | applied |
| C1PQ-005 | Storage type is `EffectObjImageLib *`. | 98 | PE32 width and typed receiver uses | UID0001PQ/UID0000QT | incorporate | applied |
| C1PQ-006 | Human source name is `g_pEffectObjImageLib`. | 94 | family naming and all source consumers | UID0001PQ/UID0000QT | incorporate | applied |
| C1PQ-007 | Global has external linkage and one `.cpp` definition. | 97 | cross-module reads and ODR | UID0000QT/class/file | incorporate | applied |
| C1PQ-008 | Physical UID0001PQ is false/non-emitting and blank. | 99 | one-definition policy | UID0001PQ metadata/formal | incorporate | applied |
| C1PQ-009 | Exactly 12 direct data refs exist. | 100 | live xref_query | UID0001PQ/UID0000QT | incorporate | applied |
| C1PQ-010 | Five refs are compiler-lowered publication/clears. | 99 | ctor/dtor/helper/scalar decompile | lifecycle sections | incorporate | applied |
| C1PQ-011 | Seven refs are shutdown/map/user/effect consumers. | 99 | xref/function classification | read inventory | incorporate | applied |
| C1PQ-012 | Constructor is authored source at exact 0xee bytes. | 99 | decompile/boundary/caller | UID0002H9 | incorporate | applied |
| C1PQ-013 | Constructor global store is implicit Singleton-base lowering. | 98 | RTTI PMD plus `this==-4` chain | UID0002H9 formal/prose | reject-stale | applied |
| C1PQ-014 | Ordinary destructor authored cleanup remains source. | 99 | exact 0x13a decompile | UID00017L | incorporate | applied |
| C1PQ-015 | Ordinary destructor global clear is implicit reverse-base lowering. | 98 | direct-base order and tail call | UID00017L formal/prose | reject-stale | applied |
| C1PQ-016 | UID00017W is compiler cleanup support with no authored body. | 99 | 11 bytes, one EH xref, no callers/callees | UID00017W | incorporate | applied |
| C1PQ-017 | UID0002HC is compiler scalar deleting support with no authored body. | 99 | vtable/delete-flag/optional free | UID0002HC | incorporate | applied |
| C1PQ-018 | Startup is lifecycle orchestrator, not owner. | 98 | sole constructor caller and sibling order | verify-only startup/file | already-present | already-present |
| C1PQ-019 | Shutdown is lifecycle consumer, not owner. | 98 | global read and virtual delete | verify-only shutdown/file | already-present | already-present |
| C1PQ-020 | MapPane descriptor routes are consumers. | 98 | calls to GetEffectInfo | target/global/file | incorporate | applied |
| C1PQ-021 | EffectObjectPane bounds/render routes are consumers. | 98 | exact three reads/calls | target/global/file | incorporate | applied |
| C1PQ-022 | UserPane movement route is a descriptor consumer. | 97 | 0x5a2ee5/0x5a2ef4 | target/global/file | incorporate | applied |
| C1PQ-023 | Adjacent image singleton slots remain distinct. | 99 | exact addresses/24-byte zeros/docs | UID0001PQ | incorporate | applied |
| C1PQ-024 | RTTI direct bases are LObject and Singleton<EffectObjImageLib>. | 99 | CHD/base descriptors/names | class/layout/vtables | incorporate | applied |
| C1PQ-025 | Singleton PMD `+4/-1/0` proves EBO overlap. | 99 | BCD bytes/name | class/layout | incorporate | applied |
| C1PQ-026 | Source base order is LObject then Singleton. | 97 | construction and reverse destruction order | class/ctor/dtor | incorporate | applied |
| C1PQ-027 | Vtable slots are scalar dtor, GetRuntimeClass, OnChangeMessage. | 99 | dwords and LObject contract | UID0001XG/UID0002MK | incorporate | applied |
| C1PQ-028 | Vtable/RTTI are source-declared/generated-binary and blank. | 99 | compiler table provenance | UID0001XG/UID0002MK | incorporate | applied |
| C1PQ-029 | Exact layout includes Singleton EBO at +4 and existing fields through +0x5c. | 98 | RTTI plus ctor/render/load/dtor | UID0001U9 | incorporate | applied |
| C1PQ-030 | Complete class declaration is required before member bodies. | 97 | pre-callback generated source lacked the class; command 15948 emits one complete class | UID00004A | incorporate | applied |
| C1PQ-031 | Class header carries exactly one extern declaration. | 97 | external linkage/one-definition | UID00004A | incorporate | applied |
| C1PQ-032 | Definition initializer `= 0` is highest probability. | 94 | current source convention and runtime | UID0000QT | incorporate | applied |
| C1PQ-033 | Source placement is `NexusTK/render/EffectObjImageLib.cpp`. | 96 | current owner/resource/method route | UID0000IY | incorporate | applied |
| C1PQ-034 | UID00017K remains false index with the complete current child/source union. | 98 | mixed local method/helper inventory | UID00017K | incorporate | applied |
| C1PQ-035 | UID00017M formal/body remains verify-only unchanged. | 98 | direct render evidence | UID00017M | already-present | already-present |
| C1PQ-036 | UID0002HA formal/body remains verify-only unchanged. | 99 | 52-byte copy/three callers | UID0002HA | already-present | already-present |
| C1PQ-037 | UID0002HB formal/body remains verify-only unchanged. | 97 | table loader evidence | UID0002HB | already-present | already-present |
| C1PQ-038 | Target score is 92/94. | 95 | all target blockers resolved | UID0001PQ metadata | incorporate | applied |
| C1PQ-039 | Semantic global score is 92/94. | 94 | name/type/linkage/lifetime closure | UID0000QT metadata | incorporate | applied |
| C1PQ-040 | Class score is 92/94. | 94 | complete class/direct-base/formal closure | UID00004A metadata | incorporate | applied |
| C1PQ-041 | File score is 92/93. | 93 | complete source/compiler union | UID0000IY metadata/prose | incorporate | applied |
| C1PQ-042 | Constructor/destructor/compiler/layout/vtable support scores/dispositions are synchronized. | 94 | destination-specific evidence | D4-D11 | incorporate | applied |
| C1PQ-043 | Manual rows require literal no-loss replacements. | 100 | current row readback | coverage handoff | incorporate | excluded-with-reason |
| C1PQ-044 | Generated output must contain one class/global and source bodies, no target/compiler markers. | 98 | source routing and one-definition | final waited assertions | incorporate | applied |
| C1PQ-045 | IDA should rename/type the global only under supervisor mutation authority. | 96 | stripped name/type closure | IDA recommendations | incorporate | excluded-with-reason |
| C1PQ-046 | No investigable blocker or future child work remains in the plan. | 94 | full evidence and destination closure | report/checklist | incorporate | applied |

Claim-specific callback proof:

- C1PQ-001: command 15936 preserved exact target range `[0x0069b44c,0x0069b450)`; current target hash is `04E6...A4770`.
- C1PQ-002: UID0001PQ now retains exact `00 00 00 00` bytes and target-byte hash `DF3F...B81119`.
- C1PQ-003: UID0001PQ records `.data` relative `0x2e44c`, virtual-size inclusion, raw-size exclusion, and loader-zero disposition.
- C1PQ-004: UID0001PQ and UID0000QT historicalize and reject `0xffffffff`; the manual row remains an external literal replacement.
- C1PQ-005: UID0001PQ and UID0000QT record the four-byte `EffectObjImageLib *` type.
- C1PQ-006: UID0001PQ, UID0000QT, and UID0000IY consistently use `g_pEffectObjImageLib` and reject IDA labels.
- C1PQ-007: UID0000QT emits the sole external definition and UID00004A emits exactly one header `extern` declaration.
- C1PQ-008: command 15936 changed UID0001PQ to false with blank emitter, position, and formal; generated occurrence count is zero.
- C1PQ-009: UID0001PQ and UID0000QT preserve all 12 exact data references.
- C1PQ-010: D1, D2, D4-D7 classify exactly five publication/clear refs as direct Singleton-base compiler lowering.
- C1PQ-011: D1, D2, and D12 preserve the seven shutdown/map/user/effect consumer reads.
- C1PQ-012: command 15939 preserved the exact `0xee` constructor range, caller, resources, and authored body.
- C1PQ-013: Destination 4 is exact and contains direct base initialization with zero explicit global assignment.
- C1PQ-014: command 15940 preserved the complete `0x13a` authored cleanup body.
- C1PQ-015: Destination 5 is exact and contains zero explicit global clear while retaining reverse-base proof in prose.
- C1PQ-016: command 15941 made UID00017W false/blank and preserved its 11 bytes, sole cleanup xref, and no-caller proof.
- C1PQ-017: command 15942 made UID0002HC false/blank and preserved vtable, flags, cleanup parity, optional-free, and return evidence.
- C1PQ-018: startup UID00017M support remained unchanged at hash `8A978A2C...FF3E3`; D12 records orchestrator-only ownership.
- C1PQ-019: shutdown support remained unchanged; D12 records consumer-only ownership and virtual deletion.
- C1PQ-020: D1, D2, and D12 preserve the exact MapPane GetEffectInfo routes.
- C1PQ-021: D1, D2, and D12 preserve all three EffectObjectPane bounds/render routes.
- C1PQ-022: D1, D2, and D12 preserve the UserPane `0x005a2ee5/0x005a2ef4` descriptor route.
- C1PQ-023: D1 preserves UID0001PP and UID0001PR neighbor boundaries and distinct singleton identities.
- C1PQ-024: D3 and D8-D10 record direct LObject and Singleton bases from the exact RTTI descriptors.
- C1PQ-025: D3 and D8-D10 record Singleton PMD `+4/-1/0` and EBO overlap.
- C1PQ-026: D3-D5 preserve authored base order `LObject, Singleton<EffectObjImageLib>` and reverse teardown.
- C1PQ-027: D9-D10 resolve the exact scalar-destructor, GetRuntimeClass, and OnChangeMessage slots without changing dwords.
- C1PQ-028: commands 15944-15945 made D9-D10 false/blank; command 15948 emitted no handwritten table source.
- C1PQ-029: command 15943 preserved every layout offset through `+0x5c`, exact size `0x60`, and added Singleton EBO.
- C1PQ-030: command 15938 installed the complete class closed before `[[CHILDREN]]`; generated class count is one.
- C1PQ-031: Destination 3 contains exactly one `extern EffectObjImageLib *g_pEffectObjImageLib;` declaration.
- C1PQ-032: Destination 2 emits exactly one `EffectObjImageLib *g_pEffectObjImageLib = 0;` definition.
- C1PQ-033: command 15947 preserved `NexusTK/render/EffectObjImageLib.cpp` ownership and complete source/compiler union.
- C1PQ-034: command 15946 preserved UID00017K as a false/blank exact local index with the complete child/source/compiler union.
- C1PQ-035: UID00017M remained verify-only at hash `8A978A2C...FF3E3`, with its managed body unchanged.
- C1PQ-036: UID0002HA remained verify-only at hash `897046AB...CAC1`, with its managed body unchanged.
- C1PQ-037: UID0002HB remained verify-only at hash `B9FF9F8C...ED32`, with its managed body unchanged.
- C1PQ-038: command 15936 applied target score `92/94` and false/non-emitting metadata.
- C1PQ-039: command 15937 applied semantic-global score `92/94` while preserving emitter position 4.
- C1PQ-040: command 15938 applied class score `92/94` and the complete declaration.
- C1PQ-041: command 15947 applied file score `92/93` without adding a formal header.
- C1PQ-042: commands 15939-15946 synchronized D4-D11 scores, ownership, reconstructability, nesting, formals, and complete evidence.
- C1PQ-043: all six manual files were reread at callback verification time and the literal no-loss replacements below remain unapplied because coverage is supervisor-owned.
- C1PQ-044: waited command 15948 proved one class/global and each accepted source definition, zero target/compiler/data UIDs, zero relevant Empty Emitter Markers, and no reverse-engineering source residue.
- C1PQ-045: the rename/type/comment recommendation remains excluded from implementation because IDA mutation is supervisor-owned; B004 made no IDA change.
- C1PQ-046: all 12 accepted ordinary destinations are implemented and validated, all 11 managed blocks are exact, generated assertions pass, and no implementation item or lease remains.

## Positive Evidence Summary

- Four exact zero bytes and no raw PE bytes resolve initialization.
- Twelve exact xrefs close the complete lifetime/consumer inventory.
- Direct RTTI names and PMD close the source hierarchy and explain all otherwise artificial lifecycle stores.
- Constructor/destructor control-flow order matches forward/reverse direct-base construction.
- Vtable slots align exactly with LObject inheritance and a virtual source destructor.
- Current source family already converges on one global name, one type, one file, and one resource owner.
- FontImageLib independently demonstrates the same compiler/source policy in this project.

## IDA MCP Facts

- Session/database: `9b0396a3`; healthy at evidence time `2026-07-21T14:41:24-04:00`.
- Target bytes: `00 00 00 00`; 24-byte neighborhood `0x0069b440-0x0069b458` is all zero in the loaded image.
- Constructor: `sub_4DDF60`, size `0xee`; global refs at `0x004ddf9f/0x004ddfa6`; one caller at `0x004f6113` after Application allocates exactly `0x60` bytes.
- Destructor: `sub_4DE050`, size `0x13a`; global clear `0x004de167`; LObject teardown call `0x004de173`.
- Clear helper: `sub_4E5B70`, size `0x0b`, exact `mov [0x69b44c],0; ret`.
- Scalar wrapper: `sub_4E62F0`, size `0x166`; global clear `0x004e640e`; delete flags and optional free.
- RTTI names include EffectObjImageLib COL/CHD, LObject BCD `??_R1A@?0A@EA@LObject@@8` at `0x00640348`, and Singleton BCD `??_R1A@?0A@EA@?$Singleton@VEffectObjImageLib@@@@8` at `0x00648e44`.
- Singleton BCD PMD is `mdisp=4`, `pdisp=-1`, `vdisp=0`, attribute `0x40`.
- Vtable at `0x0061b724` has slots `0x004e62f0`, `0x004f4b10`, and `0x0041b6c0`.

## Function / Child Inventory

| Range | Current UID | Source role | Recommended disposition |
| --- | --- | --- | --- |
| `0x004ddf60-0x004dec30` | UID00017K | mixed local index | false/non-emitting, complete current inventory |
| `0x004ddf60-0x004de04e` | UID0002H9 | authored constructor | true; corrected direct-base source |
| `0x004de050-0x004de189` | UID00017L | authored ordinary destructor | true; resource cleanup without explicit clear |
| `0x004de190-0x004de29f` | UID00017M | authored renderer | verify-only current formal |
| `0x004de2a0-0x004de3d2` | UID0000UR | authored free bounds helper | verify-only current formal |
| `0x004de3e0-0x004de420` | UID0002HA | authored descriptor accessor | verify-only current formal |
| `0x004de420-0x004de7c2` | UID0000U4 | authored archive builder | verify-only current formal |
| `0x004de7d0-0x004dec23` | UID0002HB | authored table loader | verify-only current formal |
| `0x004e5b70-0x004e5b7b` | UID00017W | compiler cleanup support | false/non-emitting blank |
| `0x004e62f0-0x004e6456` | UID0002HC | compiler scalar deleting destructor | false/non-emitting blank |
| `0x0061b720-0x0061b730` | UID0002MK | generated RTTI/vtable data | false/non-emitting blank |
| `0x0069b44c-0x0069b450` | UID0001PQ | physical singleton storage | false/non-emitting blank |

No split or new child registration is triggered: every executable/source/compiler body already has an exact page, and the target range is already exact.

## Direct Xref / Caller Inventory

| Address | Function | Classification | Exact role |
| --- | --- | --- | --- |
| `0x004ddf9f` | `0x004ddf60`, size `0xee` | write | Singleton base publishes complete object |
| `0x004ddfa6` | `0x004ddf60`, size `0xee` | write | null-adjust/unwind fallback clears slot |
| `0x004de167` | `0x004de050`, size `0x13a` | write | reverse Singleton base destruction clears slot |
| `0x004e5b70` | `0x004e5b70`, size `0x0b` | write | compiler constructor-cleanup helper clears slot |
| `0x004e640e` | `0x004e62f0`, size `0x166` | write | scalar wrapper's inlined reverse Singleton clear |
| `0x004f65d2` | `0x004f6490`, size `0x215` | read | Application shutdown virtual-deletes singleton |
| `0x0050e331` | `0x0050e320`, size `0x196` | read | object-target effect descriptor request |
| `0x0050e893` | `0x0050e850`, size `0x1e0` | read | coordinate effect descriptor request |
| `0x005388fa` | `0x005388c0`, size `0x96` | read | EffectObjectPane sprite bounds/setup |
| `0x00538982` | `0x00538960`, size `0x69` | read | EffectObjectPane sprite bounds/setup |
| `0x00538b97` | `0x00538af0`, size `0xba` | read | EffectObjectPane render frame |
| `0x005a2ee5` | `0x005a2e00`, size `0x8de` | read | UserPane movement effect descriptor lookup |

- Constructor has exactly one direct caller at `0x004f6113` in Application startup.
- GetEffectInfo has three modeled callers at `0x0050e33b`, `0x0050e89d`, and `0x005a2ef4`.
- Effect renderer has one modeled call from `0x00538ba0`.
- Clear helper has no ordinary caller/callee; its sole code xref is compiler cleanup metadata/flow at `0x0060008a`.

## Documentation Evidence And IDA Status

- Current target/global ordinary documentation records zero loaded bytes, all 12 refs, one-definition routing, and direct Singleton-base lifetime. Current manual by-memory coverage still says `0xffffffff`; the literal replacement below remains supervisor-owned and unapplied.
- Current constructor/destructor formals are source-bearing and contain zero explicit singleton writes; the direct base regenerates publication and clear behavior.
- Current class/layout/vtable pages carry the complete direct-base source contract, exact inherited slot names, and false/non-emitting compiler disposition.
- Current file route is correct, all source method/helper pages exist, and command 15948 generated one coherent class/source unit with no class marker.
- IDA remains stripped at `unk_69B44C`. Rename/type guidance is retained as an excluded supervisor-owned recommendation; no IDA mutation occurred.
- Evidence gathered around the active session was revalidated after the final health check; no fallback-only conclusion is used.

## Ranked Ownership Analysis

1. **UID0000QT semantic global under UID0000IY EffectObjImageLib.cpp: selected.** It owns the one source definition and matches all lifecycle/resource/source routes.
2. **UID00004A class header contract: selected declaration support.** It owns the complete class, direct bases, fields, methods, and one extern declaration, but not a second definition.
3. **Application: rejected as owner.** It constructs and destroys the dependency only.
4. **EffectObjectPane/MapPane/UserPane: rejected as owners.** They are seven exact consumers and define no storage.
5. **Generic ImageLib/EPF resources/ProtectedArray: rejected as owner.** They are bases or reusable dependencies, not the effect singleton source module.
6. **Physical UID0001PQ: rejected as source owner.** It is exact binary storage evidence and would duplicate UID0000QT if emitted.
7. **Static/file-local or Singleton template static member: rejected.** Cross-module source consumers and established project naming require an external symbol; no evidence supports changing the semantic definition to a template specialization.

## Source Placement

- Implementation: `NexusTK/render/EffectObjImageLib.cpp` through UID0000IY.
- Header-facing class/global declaration: represented by UID00004A's complete class block and `extern EffectObjImageLib *g_pEffectObjImageLib;`.
- Definition: UID0000QT at established emitter position `4`, after the three resource structs and before the class.
- Constructor/destructor/member bodies: class-owned children under UID00004A and `[[CHILDREN]]`.
- Compiler/data pages: no source text and no generated marker.
- Exact original header filename is stripped; this is a confidence cap, not a source-placement blocker.

## Range / Split / Padding / Reclassification Analysis

- UID0001PQ already has the exact four-byte range. No split, merge, rename, or child is needed.
- The target is bounded by UID0001PP `g_pStaticObjImageLib` at `[0x0069b448,0x0069b44c)` and UID0001PR `g_pLightObjImageLib` at `[0x0069b450,0x0069b454)`; all remain distinct.
- The target's presence in `.data` virtual size but absence from `.data` raw size is not padding and not missing coverage. It is loader-zero storage represented by a semantic source definition elsewhere.
- UID00017K remains a mixed/index page over its exact local method island and is blank/false. Its ordinary page now records actual `[0x004ddf60,0x004dec30)` scope; the manual row ending at `0x004e6455` remains stale and is corrected by the literal supervisor-owned handoff below. Helper/scalar tails remain separate pages.
- UID00017W and UID0002HC ranges are exact and stay separate. No padding row changes are triggered.
- UID0002MK exact vtable-data range stays `[0x0061b720,0x0061b730)`; successor ProtectedArray<ItemInfo> starts at `0x0061b730`.
- `Nested:0` remains correct for every listed destination; no raw indentation delta changes are required.

## Negative Evidence Summary

- No file-backed raw bytes exist for the target; any `0xffffffff` raw read uses an invalid mapping.
- No thirteenth xref, alternate pointer slot, alias symbol, or writer exists.
- No consumer allocates, publishes, clears, or defines the global.
- No static/file-local use is possible across Application, MapPane, UserPane, and EffectObjectPane source routes.
- No ordinary caller or receiver exists for UID00017W.
- No source-level scalar deleting-destructor signature is required; delete flags and optional free are compiler ABI mechanics.
- No handwritten RTTI, COL, base descriptor, vtable array, vptr write, pointer adjustment, EH cookie, or delete wrapper is justified.
- No direct prior UID0001PQ B-report exists; older broad reports do not establish the direct-base correction.
- No source name/PDB proves private member spellings or exact header name; confidence is capped accordingly.

## IDA Rename / Type / Comment Recommendations

- Rename `unk_69B44C` / historical `dword_69B44C` to `g_pEffectObjImageLib` only in a supervisor-authorized IDA mutation phase.
- Apply type `EffectObjImageLib *` to the global and all direct references.
- Comment the target as loader-zero backing storage for the externally linked singleton definition, published/cleared by compiler-lowered `Singleton<EffectObjImageLib>` base construction/destruction.
- Apply/retain `EffectObjImageLib : LObject, Singleton<EffectObjImageLib>` type information with Singleton PMD `+4/-1/0` and EBO overlap.
- Name vtable slots `~EffectObjImageLib` deleting support, inherited `LObject::GetRuntimeClass`, and inherited `LObject::OnChangeMessage` default.
- Do not rename UID00017W as a human `Clear...` API or UID0002HC as an authored method.

## First-Draft C++ Recommendation

The eleven accepted managed blocks below are now installed byte-for-byte in Destinations 1-11; Destination 12 correctly remains a prose-only file route without a managed header.

Destination 1, UID0001PQ, exact managed block; payload intentionally blank because UID0000QT owns the one source definition:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 2, UID0000QT, exact sole definition:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class EffectObjImageLib;

EffectObjImageLib *g_pEffectObjImageLib = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 3, UID00004A, complete class/header contract:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class AlphaMaskSurface;
class MapPane;
struct ArchiveMetadataTable;
struct RectBounds;

ArchiveMetadataTable *BuildEffectArchiveTable(const wchar_t *unusedArchiveName);

class EffectObjImageLib;
extern EffectObjImageLib *g_pEffectObjImageLib;

class EffectObjImageLib : public LObject, public Singleton<EffectObjImageLib>
{
public:
    EffectObjImageLib();
    virtual ~EffectObjImageLib();

    int RenderEffectFrame(
        MapPane *mapPaneOrRenderContext,
        RectBounds *destinationBounds,
        int frameResourceId,
        int timerDelayAndRenderArg,
        float renderScalar,
        int lightingAndRenderArg,
        AlphaMaskSurface *overlayMaskGate,
        float overlayStrength);
    EffectInfo *GetEffectInfo(EffectInfo *outInfo, int effectId);

private:
    void LoadEffectTables();

    ProtectedArray<EffectInfo> effectInfoArray;
    EffectInfo effectInfoScratch;
    ProtectedArray<EffectPixMapInfo> effectPixMapInfoArray;
    EffectPixMapInfo fallbackFrameRemap;
    ArchiveMetadataTable *effectFileInfo;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 4, UID0002H9, corrected constructor. The existing body is preserved except direct base initializers are explicit and the handwritten singleton assignment is removed:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
EffectObjImageLib::EffectObjImageLib()
    : LObject(),
      Singleton<EffectObjImageLib>(),
      effectInfoArray(10),
      effectPixMapInfoArray(10),
      effectFileInfo(0)
{
    LoadEffectTables();

    effectFileInfo = BuildEffectArchiveTable(L"EFFECT.EPF");
    if (effectPixMapInfoArray.count < effectFileInfo->frameCount)
    {
        DestroyDATFileMgr();
        DestroyExceptionHandler();
        MessageBoxW(0, L"Error on Effect File!", L"Data Error", MB_ICONEXCLAMATION);
        __loaddll(0);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 5, UID00017L, corrected ordinary destructor. Existing authored cleanup is preserved and only the compiler-lowered global clear is removed:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
EffectObjImageLib::~EffectObjImageLib()
{
    for (int i = 0; i < effectInfoArray.count; ++i)
    {
        EffectInfo *info = &effectInfoArray.entries[i];

        if (info->secondaryFrames != 0)
        {
            delete [] info->secondaryFrames;
        }
        info->secondaryFrames = 0;
        info->secondaryFrameCount = 0;
        info->secondaryRangeStart = -1;
        info->secondaryRangeEnd = -1;

        if (info->primaryFrames != 0)
        {
            delete [] info->primaryFrames;
        }
        info->primaryFrames = 0;
        info->primaryFrameCount = 0;
        info->primaryRangeStart = -1;
        info->primaryRangeEnd = -1;
    }

    if (effectFileInfo != 0)
    {
        if (effectFileInfo->records != 0)
        {
            delete [] effectFileInfo->records;
        }
        delete effectFileInfo;
        effectFileInfo = 0;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 6, UID00017W, exact blank compiler-cleanup block:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 7, UID0002HC, exact blank compiler scalar-wrapper block:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 8, UID0001U9, exact blank layout-evidence block because Destination 3 emits the real fields:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 9, UID0001XG, exact blank compiler vtable/RTTI block:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 10, UID0002MK, exact blank physical vtable-data block:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 11, UID00017K, exact blank aggregate/index block, unchanged in source shape:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 12 is `by-file/EffectObjImageLib.md`, which has no managed C++ header. It receives the exact source/compiler/global union, generated contract, and historical corrections only.

## Final Recommendation

- C1PQ-001 through C1PQ-046 and Destinations 1-12 are implemented at the accepted bounded scope, with C1PQ-043 and C1PQ-045 excluded only because manual coverage and IDA mutation remain supervisor-owned.
- The target is source-declared/generated-binary backing storage, not a source definition and not an unresolved blank emitter.
- The complete human source carrier is the union of UID0000QT definition, UID00004A class/extern, UID0002H9 constructor, UID00017L destructor, and preserved source-bearing method/helper children.
- Direct `Singleton<EffectObjImageLib>` inheritance is the decisive closure. It preserves exact runtime writes while removing reverse-engineering-shaped explicit global lifecycle source.
- No source-quality blocker remains. Original private spellings and exact header filename remain confidence caps only.

## Recommended Target Doc Changes

- Applied UID0001PQ as `COMPLETION:92`, `CONFIDENCE:94`, `CANONICAL_OWNER:0000QT`, `RECONSTRUCTABLE:FALSE`, blank emitter/position/formal, `Nested:0`.
- Replaced marker-only status with exact no-code proof: one semantic UID0000QT definition owns source; the physical page retains binary bytes/range/xrefs/lifetime only.
- Added PE `.data` virtual/raw mapping and rejected `0xffffffff` with exact reason.
- Reclassified all five writes as compiler-lowered direct Singleton-base lifecycle effects and all seven reads as non-owner consumers.
- Preserved every exact address, caller, neighbor, historical correction, and cross-reference.

## Recommended Support Doc Changes

- Applied UID0000QT at `92/94`, position `4`, preserving its exact definition and adding external-linkage/header-extern/one-definition, loader-zero storage, direct Singleton-base lifetime, and rejected alternatives.
- Applied UID00004A at `92/94`, position `10`, replacing the marker with Destination 3, exact direct bases, EBO, full fields/method declarations, inherited virtual slots, one extern, and class closure before `[[CHILDREN]]`.
- Applied UID0002H9 at `92/94` with exact Destination 4, direct-base lowering proof, and shared UID0000UN `ArchiveMetadataTable::frameCount`; all resource/error behavior remains.
- Applied UID00017L at `92/94` with exact Destination 5, removing only explicit singleton clear and preserving all resource cleanup.
- Applied UID00017W at `93/96`, owner UID0000IY, false/non-emitting blank, with exact compiler-unwind proof and historical helper interpretation.
- Applied UID0002HC at `93/96`, owner UID00004A, false/non-emitting blank, with exact scalar-wrapper proof.
- Applied UID0001U9 at `92/94`, owner UID00004A, false/non-emitting blank, preserving exact layout and adding Singleton EBO.
- Applied UID0001XG at `92/95`, owner UID00004A, false/non-emitting blank, resolving inherited slot names and direct hierarchy.
- Applied UID0002MK at `92/95`, owner UID0000IY, false/non-emitting blank, preserving exact dwords/xrefs/boundaries and adding direct hierarchy.
- Applied UID00017K at `90/93`, false/non-emitting blank, with corrected local ordinary range, current scores, exact child source/compiler split, and closed split/source-name claims; its stale manual range remains covered by the handoff below.
- Applied UID0000IY at `92/93`, preserving all resource/method/formal detail and adding complete source contract, implicit lifetime, one-definition route, command-15948 generated proof, and historical marker output.
- Verified unchanged: UID00017M, UID0002HA, UID0002HB, UID0000U4, UID0000UR, UID0000UN shared EPF archive declarations, startup, shutdown, consumer pages, adjacent globals, LObject, ProtectedArray, resource records, ImageLibraryLoadErrorFlag, and shared EPF/Palette support.

## Score And Metadata Recommendation

| Destination | Before callback | Implemented | Rationale |
| --- | --- | --- | --- |
| UID0001PQ | 86/90 true marker | 92/94 false blank | exact PE/bytes/xrefs/direct-base/one-definition closure |
| UID0000QT | 88/90 | 92/94 | exact name/type/linkage/definition/lifetime closure |
| UID00004A | 86/89 marker | 92/94 complete class | direct hierarchy, exact layout, complete declarations |
| UID0000IY | 90/88 | 92/93 | complete source/compiler/global union; filename cap retained |
| UID0002H9 | 91/92 | 92/94 | exact direct-base source correction |
| UID00017L | 90/92 | 92/94 | exact authored cleanup versus base teardown split |
| UID00017W | 86/91 true marker | 93/96 false blank | exact compiler cleanup provenance |
| UID0002HC | 88/91 true marker | 93/96 false blank | exact compiler scalar-wrapper provenance |
| UID0001U9 | 86/89 true marker | 92/94 false blank | exact complete layout plus class coverage |
| UID0001XG | 85/90 true marker | 92/95 false blank | exact slots/direct RTTI/source regeneration |
| UID0002MK | 86/91 true marker | 92/95 false blank | exact physical vtable data/no handwritten source |
| UID00017K | 86/90 false | 90/93 false | exact current child union and stale range/debt closure |

Completion remains below 95 where private source spelling or exact filename is stripped. Confidence does not claim byte-identical rebuilding of compiler-generated RTTI addresses; it claims behavior/source-shape reconstruction and correct compiler-generated disposition.

## Open Questions With Attempted Resolution

- **Was the original definition explicitly initialized?** `= 0` is selected over omitted initialization and `NULL` because current project source convention and existing emitter use it. Runtime cannot distinguish omitted zero-init, so confidence is capped at 94.
- **Was the symbol a Singleton template static member?** No current name/type/source route supports changing the established external global. Direct Singleton inheritance explains lifecycle without changing storage ownership; retain `g_pEffectObjImageLib`.
- **Did the source explicitly assign/clear the global?** No. Direct RTTI, PMD, `this+4/-4` adjustment, and forward/reverse call order make implicit base lowering overwhelmingly stronger.
- **Was UID00017W a human helper?** No. One constructor-cleanup xref, no ordinary callers, no receiver/callee, and exact sibling helper pattern close this.
- **Should compiler pages emit explanatory comments?** No. Their by-* prose is the evidence; formal blocks stay exactly blank to avoid generated pseudo-source markers.
- **What is the exact header filename?** Stripped. Existing `NexusTK/render/EffectObjImageLib.cpp` route is strong; exact header spelling remains a score cap, not deferred implementation work.
- **Are private field names exact?** No symbols remain. Existing names are accepted descriptive source names constrained by exact offsets/types/uses. No better evidence-backed names were found.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Current read-only baseline at callback verification time:

- `by-memory/-coverage-report.md` SHA256 `718220A7AD5EE56EBAF5DA1595B6D90B15C9FC55BF787520D94280026AC7E7B9`, 1,908,790 bytes / 4,475 lines. Unrelated external validators advanced this hash after the initial `0DF939...09E87`, intermediate `80BB55...0A2441`, and callback checkpoint `1D95BA...E1EE1`; all seven EffectObjImageLib rows below remain byte-for-byte stale and unapplied.
- `by-global/-coverage-report.md` SHA256 `37B8E52C08B74B94D6D6060D2FAEB738A70CF0BD873ACEC0E69A2D96602F79CF`, 94,337 / 214; the UID0000QT row remains unchanged at line 83.
- `by-class/-coverage-report.md` SHA256 `84425C08771A718EF418CF91156F6903F9CB8BF13BE1806294A6B7E2F149FABF`, 247,645 / 623; the UID00004A row remains unchanged at line 179.
- `by-file/-coverage-report.md` SHA256 `52E229C5CB12F3DDAC0962451D66B5A9985AEE961356A186E487B3F3E8B15BC3`, 145,081 / 316; the UID0000IY row remains unchanged at line 79.
- `by-type/by-struct/-coverage-report.md` SHA256 `EE8D6DF57A1E4C5AEF9B00A4A5FA1BF5B4933B689D1F9AA7CE8996F24EE78B98`, 56,735 / 137; the UID0001U9 row remains unchanged at line 40.
- `by-type/by-vtable/-coverage-report.md` SHA256 `8B4284A41EF4B334AF1B51230D9BF7DCFDBA945AB133EB794F8EC869D59D08E5`, 64,555 bytes / 142 lines; the UID0001XG row remains unchanged at line 50.

In `by-memory/-coverage-report.md`, replace current UID00017K row at final-readback line 1798 with:

```markdown
    - [UID:00017K][0x004ddf60-0x004dec30.EffectObjImageLibLocalMethodCluster](by-memory/0x004ddf60-0x004dec30.EffectObjImageLibLocalMethodCluster.md) 0x004ddf60-0x004dec30 | mixed local method index | EffectObjImageLib local source/compiler island : not_reconstructable : 90% : very-strong : Exact non-emitting local index for constructor, ordinary destructor, RenderEffectFrame, GetSpriteBounds, GetEffectInfo, BuildEffectArchiveTable, and LoadEffectTables source plus separately ranged singleton-clear/scalar compiler tails; direct LObject and Singleton<EffectObjImageLib> source hierarchy, implicit publication/clear, complete child/formal ownership, resource/state/layout/vtable/global routes, exact boundaries, and no aggregate C++ or remaining split/source-emitter debt.
```

Replace current UID0002H9 row at final-readback line 1799, immediately after UID00017K, with:

```markdown
    - [UID:0002H9][0x004ddf60-0x004de04e.EffectObjImageLibConstructor](by-memory/0x004ddf60-0x004de04e.EffectObjImageLibConstructor.md) 0x004ddf60-0x004de04e | constructor | EffectObjImageLib::EffectObjImageLib : reconstructable : 92% : very-strong : Exact 0xee-byte authored constructor with sole Application startup caller, direct LObject then Singleton<EffectObjImageLib> base initialization, compiler-lowered +0x04 EBO publication/null-adjust cleanup, protected EffectInfo/EffectPixMapInfo arrays at capacity 10, LoadEffectTables, EFFECT.EPF archive metadata, frame-count validation, exact fatal helpers/literals, and no handwritten global/vptr/EH source.
```

Replace current UID00017L row at final-readback line 1800, immediately after UID0002H9, with:

```markdown
    - [UID:00017L][0x004de050-0x004de189.EffectObjImageLibDestructor](by-memory/0x004de050-0x004de189.EffectObjImageLibDestructor.md) 0x004de050-0x004de189 | ordinary destructor | EffectObjImageLib::~EffectObjImageLib : reconstructable : 92% : very-strong : Exact 0x13a-byte authored destructor with 0x34-stride descriptor iteration, secondary/primary frame-array frees and resets, archive metadata/payload deletion, implicit ProtectedArray cleanup, compiler-lowered reverse Singleton<EffectObjImageLib> clear before LObject teardown, scalar-wrapper parity, and no explicit global/vptr/base-destructor source.
```

Replace current UID00017W row at final-readback line 1834 with:

```markdown
    - [UID:00017W][0x004e5b70-0x004e5b7b.EffectObjImageLibSingletonClearHelper](by-memory/0x004e5b70-0x004e5b7b.EffectObjImageLibSingletonClearHelper.md) 0x004e5b70-0x004e5b7b | compiler singleton cleanup support | EffectObjImageLib Singleton-base unwind clear : not_reconstructable : 93% : very-strong : Exact c7 05 4c b4 69 00 00 00 00 00 c3 body with one constructor-cleanup xref at 0x0060008a, no receiver/callees/ordinary callers, direct Singleton<EffectObjImageLib> PMD +0x04 cause, five following cc bytes excluded, and exact blank no-helper source disposition.
```

Replace current UID0002HC row at final-readback line 1851 with:

```markdown
    - [UID:0002HC][0x004e62f0-0x004e6456.EffectObjImageLibScalarDeletingDestructor](by-memory/0x004e62f0-0x004e6456.EffectObjImageLibScalarDeletingDestructor.md) 0x004e62f0-0x004e6456 | compiler scalar deleting destructor | EffectObjImageLib deleting support : not_reconstructable : 93% : very-strong : Exact 0x166-byte vtable-only compiler wrapper with full ordinary-cleanup parity, reverse Singleton<EffectObjImageLib> clear, LObject teardown, flags 1/4 predicate, optional operator delete, receiver return, and exact blank no-wrapper source disposition generated from the virtual ordinary destructor.
```

Replace current UID0002MK row at final-readback line 3982 with:

```markdown
        - [UID:0002MK][0x0061b720-0x0061b730.EffectObjImageLibVtableData](by-memory/0x0061b720-0x0061b730.EffectObjImageLibVtableData.md) 0x0061b720-0x0061b730 | source-declared/generated-binary vtable data | EffectObjImageLibVtableData : not_reconstructable : 92% : very-strong : Exact EffectObjImageLib COL plus three-slot primary vtable with compiler scalar destructor, inherited LObject::GetRuntimeClass and LObject::OnChangeMessage, constructor/destructor/scalar stores, direct EffectObjImageLib/LObject/Singleton<EffectObjImageLib> RTTI hierarchy and PMD +0x04 EBO, ProtectedArray<ItemInfo> successor boundary, and blank no-raw-table source regeneration route.
```

Replace current UID0001PQ row at final-readback line 4375 with:

```markdown
    - [UID:0001PQ][0x0069b44c-0x0069b450.g_pEffectObjImageLib](by-memory/0x0069b44c-0x0069b450.g_pEffectObjImageLib.md) 0x0069b44c-0x0069b450 | physical singleton storage | g_pEffectObjImageLib backing slot : not_reconstructable : 92% : very-strong : Exact four-byte loader-zero .data virtual-tail storage with no valid raw PE bytes, live bytes 00 00 00 00, 12 refs split into five compiler-lowered Singleton<EffectObjImageLib> publication/clear effects and seven shutdown/map/user/effect-object reads, direct PMD +0x04 EBO cause, exact adjacent singleton boundaries, historical 0xffffffff rejection, and sole semantic definition through UID0000QT with no duplicate marker/body.
```

In `by-global/-coverage-report.md`, replace current UID0000QT row at final-readback line 83 with:

```markdown
- [UID:0000QT][g_pEffectObjImageLib](by-global/g_pEffectObjImageLib.md) : reconstructable : 92% : very-strong : Sole externally linked EffectObjImageLib pointer definition at source position 4 with local class forward declaration, exact false loader-zero backing UID0001PQ, zero initializer, 12-reference lifecycle/consumer closure, direct Singleton<EffectObjImageLib> PMD +0x04 publication/reverse-clear cause, one class-header extern, EffectObjImageLib.cpp ownership, and rejected duplicate/static/template-member/explicit-lifecycle alternatives.
```

In `by-class/-coverage-report.md`, replace current UID00004A row at final-readback line 179 with:

```markdown
- [UID:00004A][EffectObjImageLib](by-class/EffectObjImageLib.md) : reconstructable : 92% : very-strong : Complete EffectObjImageLib declaration with direct LObject then Singleton<EffectObjImageLib> bases, Singleton PMD +0x04 EBO, one extern global, virtual destructor, exact RenderEffectFrame/GetEffectInfo/LoadEffectTables surface, ProtectedArray<EffectInfo> plus scratch, ProtectedArray<EffectPixMapInfo> plus fallback, archive metadata field, exact constructor/ordinary-destructor source, inherited GetRuntimeClass/OnChangeMessage slots, compiler clear/scalar/vtable exclusions, and class closure before source children.
```

In `by-file/-coverage-report.md`, replace current UID0000IY row at final-readback line 79 with:

```markdown
- [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md) : reconstructable : 92% : very-strong : NexusTK/render/EffectObjImageLib.cpp owns one zero g_pEffectObjImageLib definition, complete LObject plus Singleton<EffectObjImageLib> class/header extern, constructor/destructor/render/get-info/load source, GetSpriteBounds and archive-builder helpers, exact EFFECT.TBL/EFFECT.FRM/EFFECT.EPF/EFFECT.EPD/palette resource union, compiler clear/scalar/layout/vtable/RTTI exclusions, loader-zero backing, startup/shutdown and all seven runtime consumers, one-definition generated contract, and preserved private-name/original-filename confidence caps.
```

In `by-type/by-struct/-coverage-report.md`, replace current UID0001U9 row at final-readback line 40 with:

```markdown
- [UID:0001U9][EffectObjImageLibLayout](by-type/by-struct/EffectObjImageLibLayout.md) : not_reconstructable : 92% : very-strong : Exact non-emitting EffectObjImageLib layout evidence covered by the complete class: LObject/vptr at +0, direct empty Singleton<EffectObjImageLib> PMD +0x04 overlapping ProtectedArray<EffectInfo>, EffectInfo scratch +0x14, ProtectedArray<EffectPixMapInfo> +0x48, fallback remap +0x58, archive metadata +0x5c, constructor/render/load/destructor uses, three vptr stores, 12 singleton refs, and no duplicate layout struct/marker source.
```

In `by-type/by-vtable/-coverage-report.md`, replace current UID0001XG row at final-readback line 50 with:

```markdown
- [UID:0001XG][EffectObjImageLibVtable](by-type/by-vtable/EffectObjImageLibVtable.md) : not_reconstructable : 92% : very-strong : Exact compiler-generated EffectObjImageLib three-slot vtable with scalar deleting destructor, inherited LObject::GetRuntimeClass and LObject::OnChangeMessage, direct EffectObjImageLib/LObject/Singleton<EffectObjImageLib> RTTI hierarchy, PMD +0x04 EBO, lifecycle stores, exact UID0002MK data and neighbor boundaries, and blank no-handwritten-table source disposition.
```

- Exact order/anchor rule: replace rows in place without moving unrelated rows. UID0002H9 and UID00017L remain immediately after UID00017K in address order; UID00017W and UID0002HC remain at their current exact-address positions; UID0002MK remains within the current read-only-data hierarchy; UID0001PQ remains between UID0001PP and UID0001PR. No addition/deletion row is required.
- Every listed row is literal destination-ready text. B004 must not edit manual coverage; the supervisor must reread current hashes/anchors before applying because unrelated validators can advance them.

## Follow-Up Actions

- C1PQ-001 through C1PQ-046 and Destinations 1-12 are implemented at report-level detail; no implementation item remains.
- Every accepted ordinary destination was reread, edited under one short lease, scoped-validated, and immediately released. Verify-only source bodies and unrelated facts remained unchanged.
- Final waited command 15948 ran after all ordinary leases cleared and established the generated assertions recorded below.
- The literal manual-coverage replacements remain complete and unapplied in this artifact because manual coverage is supervisor-owned; their present destination rows were reread without editing.
- Report validation/execution/counting/path/movement/archive and external lifecycle state remain supervisor/validator-owned and are intentionally neither asserted nor directed by this artifact.

## Confidence

- Target range/bytes/PE mapping: `99/100`.
- Xref/lifetime inventory: `100/100`.
- Type/linkage/one-definition: `97/100`.
- Direct-base/implicit-lifetime source model: `98/100`.
- Global spelling and `= 0` initializer: `94/100`.
- Class layout/method surface: `94/100`.
- Exact original private identifiers/header spelling: `82/100`, retained only as a confidence cap.
- Overall recommendation: `95/100`.

## Validator Results

- MCP calls remained read-only and did not mutate IDA. Commands 15889, 15922, 15932, 15933, and 15935 are historical research checkpoints, not callback validators.

| Command | Timestamp (America/New_York) | Scoped final path | Exit / ok | Warnings | Validator-managed side effects |
| --- | --- | --- | --- | --- | --- |
| `000000015936` | `2026-07-21T15:00:18-04:00` | `by-memory/0x0069b44c-0x0069b450.g_pEffectObjImageLib.md` | `0 / 1` | none | registry true-to-false, emitter and formal cleared, score/projection updates, generated refresh deferred |
| `000000015937` | `2026-07-21T15:01:28-04:00` | `by-global/g_pEffectObjImageLib.md` | `0 / 1` | none | score/projection updates and generated refresh deferred |
| `000000015938` | `2026-07-21T15:02:59-04:00` | `by-class/EffectObjImageLib.md` | `0 / 1` | none | managed-block hash and score/projection updates, generated refresh deferred |
| `000000015939` | `2026-07-21T15:04:25-04:00` | `by-memory/0x004ddf60-0x004de04e.EffectObjImageLibConstructor.md` | `0 / 1` | none | managed-block hash and score/projection updates, generated refresh deferred |
| `000000015940` | `2026-07-21T15:05:24-04:00` | `by-memory/0x004de050-0x004de189.EffectObjImageLibDestructor.md` | `0 / 1` | none | managed-block hash and score/projection updates, generated refresh deferred |
| `000000015941` | `2026-07-21T15:06:27-04:00` | `by-memory/0x004e5b70-0x004e5b7b.EffectObjImageLibSingletonClearHelper.md` | `0 / 1` | none | registry true-to-false, emitter/formal clearing, score/projection updates, generated refresh deferred |
| `000000015942` | `2026-07-21T15:07:23-04:00` | `by-memory/0x004e62f0-0x004e6456.EffectObjImageLibScalarDeletingDestructor.md` | `0 / 1` | none | registry true-to-false, emitter/formal clearing, score/projection updates, generated refresh deferred |
| `000000015943` | `2026-07-21T15:08:18-04:00` | `by-type/by-struct/EffectObjImageLibLayout.md` | `0 / 1` | none | registry true-to-false, emitter/formal clearing, score/projection and stats updates, generated refresh deferred |
| `000000015944` | `2026-07-21T15:09:45-04:00` | `by-type/by-vtable/EffectObjImageLibVtable.md` | `0 / 1` | none | registry true-to-false, emitter/formal clearing, score/projection and stats updates, generated refresh deferred |
| `000000015945` | `2026-07-21T15:10:52-04:00` | `by-memory/0x0061b720-0x0061b730.EffectObjImageLibVtableData.md` | `0 / 1` | none | registry true-to-false, emitter/formal clearing, score/projection updates, generated refresh deferred |
| `000000015946` | `2026-07-21T15:14:04-04:00` | `by-memory/0x004ddf60-0x004dec30.EffectObjImageLibLocalMethodCluster.md` | `0 / 1` | none | score/projection updates and generated refresh deferred |
| `000000015947` | `2026-07-21T15:16:00-04:00` | `by-file/EffectObjImageLib.md` | `0 / 1` | none | score/projection updates and generated refresh deferred |
| `000000015948` | `2026-07-21T15:16:14-04:00` | waited target refresh on `by-memory/0x0069b44c-0x0069b450.g_pEffectObjImageLib.md` | `0 / 1` | unrelated pre-existing `autogen_children_*` and `autogen_emitter_has_no_code` warnings | full registry rebuild (`5,224` nodes / `4,149` edges), generated metadata refresh (`280`), generated source/tracker completion |

- All eleven current destination managed blocks are byte-equal to Destinations 1-11 after line-ending normalization; Destination 12 correctly has no managed header.
- Command 15948 produced `auto-generated/NexusTK/render/EffectObjImageLib.cpp`, SHA256 `4363623841663DFE9E9C6583D849902A7E86610F966D00395D6EBD4007AE94FE`, 15,304 bytes / 498 lines. It has exactly one complete class, global definition, constructor, destructor, RenderEffectFrame, GetEffectInfo, LoadEffectTables, BuildEffectArchiveTable definition, and GetSpriteBounds definition.
- Generated UID0001PQ, UID00017W, UID0002HC, UID0001U9, UID0001XG, UID0002MK, UID00017K, and `Empty Emitter Marker` counts are zero. `g_pEffectObjImageLib = this`, `this == -4`, `dword_69B44C`, `vftable`, delete-flag source, `sub_`, and `loc_` counts are zero; the only global assignment is the sole `= 0` definition.
- The same command produced tracker SHA256 `32F24ADAF597AA36009C951650D8EF229A87800B1603218EF5E6EEEBD8D0D0C1`, 1,548,249 bytes / 6,263 lines. These command-15948 values are callback-time proof and are time-bounded against unrelated later external refreshes.
- Final read-only reconciliation found current external command/header 15959, refreshed `2026-07-21T15:28:49-04:00`: generated SHA256 `FA31878988CEFBBBCA0D584CA700AF4049E7397450B7E759E1ACD2FF41EFF98E`, 15,304 bytes / 498 lines, and tracker SHA256 `C99C5725E3A5EC4ECAD9ED7C829CC09E2461C8629386F02DE8B7B8B4322F3D6B`, 1,548,360 bytes / 6,263 lines. Every command-15948 structural assertion remained true. B004 did not run command 15959; 15956/15957 are retained only as historical external intermediate checkpoints.
- Every ordinary lease was released immediately after its scoped validation; final lease inventory was empty.

## Changed Files

- `by-memory/0x0069b44c-0x0069b450.g_pEffectObjImageLib.md`: SHA256 `04E6C53C17B97640F1F5BC14EEE389A757AAB2C22C1ED37E69115000172A4770`, 11,681 bytes / 106 lines.
- `by-global/g_pEffectObjImageLib.md`: SHA256 `086324E9954DDBA848CAE8413EC00B5AA1732DC1B648B4CA0B46A027D9843C9B`, 10,066 / 88.
- `by-class/EffectObjImageLib.md`: SHA256 `A805E2E8EE703425CB341F67A5013B1BAEBF6693415A16D73E67525F18FA6626`, 19,443 / 170.
- `by-memory/0x004ddf60-0x004de04e.EffectObjImageLibConstructor.md`: SHA256 `88B0C9A0BAC0572756134C39088EA72A3792C90B7B6B5B0A2126A64C5CA6CC3E`, 16,542 / 167.
- `by-memory/0x004de050-0x004de189.EffectObjImageLibDestructor.md`: SHA256 `E38D6ABC55214A64C88440EB3B90EB81BB85418330B448CF7E68B28A8A480CA0`, 12,082 / 136.
- `by-memory/0x004e5b70-0x004e5b7b.EffectObjImageLibSingletonClearHelper.md`: SHA256 `D026CB879F933A85ED44C84070E63EA557A1B665022DBC225BA7E9EF24A93024`, 10,889 / 76.
- `by-memory/0x004e62f0-0x004e6456.EffectObjImageLibScalarDeletingDestructor.md`: SHA256 `FDB25E60CCF55145BD6F9DB1021669986773D55625F73816588D8553A975303C`, 9,835 / 93.
- `by-type/by-struct/EffectObjImageLibLayout.md`: SHA256 `9CF24F0065F80C83C63C534B9A5D430696A81B80D17639F7AD8CD6BEBB8BFA66`, 13,301 / 107.
- `by-type/by-vtable/EffectObjImageLibVtable.md`: SHA256 `8B80394063212C5F22F30A8A16FC99A5A811F6A7804F5DBD7F65259A029FDC79`, 8,758 / 103.
- `by-memory/0x0061b720-0x0061b730.EffectObjImageLibVtableData.md`: SHA256 `D12B238A40144D988119EE798116724A7C091AD56542D9B9D8D3DC13E58E1F17`, 9,565 / 113.
- `by-memory/0x004ddf60-0x004dec30.EffectObjImageLibLocalMethodCluster.md`: SHA256 `EF3D3CA8D8DD8A9BC3AE4145B72E20A2AF2D727471670B55C335B5EEBBFB33B6`, 20,319 / 157.
- `by-file/EffectObjImageLib.md`: SHA256 `2029012434466823DFECB6CBD136410F4B5B7267E7C33C413318492E86E031EA`, 25,621 / 149.
- `tools/leaser/Agents/Agent-B004/research/0001PQ-g_pEffectObjImageLib-source-quality.md`: updated in place with callback proof; its exact artifact hash and metrics are reported after the final double-read.
- Verify-only unchanged hashes: UID00017M `8A978A2C09E569C40571363F200C6A300A1F34219400C7675D73A24CEF5FF3E3`; UID0002HA `897046AB1A3BD874C53547FBAAD56C274DD97C21F51F7B307C6127209B59CAC1`; UID0002HB `B9FF9F8C0F63A925A8DC0B97A5B7C82C3F554645E10B1A57B6D282FC90D4ED32`; UID0000U4 `855EE2199F026CE3ECF8882E7B9A3F4495CE9BC44A47C77FFFED73DD0719D12D`; UID0000UR `1CF73E60E8E08F7D95A2FA84C6504E40528BC1838B5D75F558D560196BC7006F`; UID0000UN `072E8DB2CAA99DCA19F5925C7179154325B016390DC015C271F6353C7E7512B3`.
- B004 did not manually edit manual coverage, generated source, tracker, audit, supervisor, validator state, IDA, lifecycle, queue, lock, goal, or archive files. Validator-generated source/tracker changes are recorded only as command side effects. Zero leases remain.

## Implementation Tracking Checklist

Implementation callback verification:

- [x] Supervisor exact-artifact Gate 1 accepted before implementation.
- [x] Re-read every accepted destination immediately before editing.
- [x] Confirm no destination has a conflicting active lease.
- [x] Apply UID0001PQ `92/94`, owner UID0000QT, false, blank emitter/position/formal, Nested 0.
- [x] Preserve UID0001PQ exact range, byte hash, 12 refs, neighbors, and all historical evidence.
- [x] Add exact PE virtual/raw mapping and reject stale `0xffffffff`.
- [x] Apply UID0000QT `92/94`, position 4, exact sole zero definition.
- [x] Add one external-linkage/header-extern/one-definition contract to UID0000QT.
- [x] Apply UID00004A `92/94` and Destination 3 byte-for-byte.
- [x] Confirm UID00004A class closes before `[[CHILDREN]]`.
- [x] Preserve existing EffectInfo, EffectFrameRecord, EffectPixMapInfo, render, get-info, and load declarations/bodies.
- [x] Apply direct `LObject, Singleton<EffectObjImageLib>` base order and PMD/EBO proof.
- [x] Apply UID0002H9 `92/94` and Destination 4 without explicit singleton assignment.
- [x] Preserve all UID0002H9 resource/error/caller/range evidence.
- [x] Correct only the stale constructor-local `entryCount` token to shared `ArchiveMetadataTable::frameCount` and preserve UID0000UN unchanged.
- [x] Apply UID00017L `92/94` and Destination 5 without explicit singleton clear.
- [x] Preserve all UID00017L descriptor/archive cleanup evidence.
- [x] Apply UID00017W `93/96`, false/non-emitting, exact blank Destination 6.
- [x] Preserve UID00017W exact bytes/xref/no-caller/history proof.
- [x] Apply UID0002HC `93/96`, false/non-emitting, exact blank Destination 7.
- [x] Preserve UID0002HC cleanup/delete-flag/vtable/history proof.
- [x] Apply UID0001U9 `92/94`, false/non-emitting, exact blank Destination 8.
- [x] Preserve all UID0001U9 offsets and add Singleton EBO.
- [x] Apply UID0001XG `92/95`, false/non-emitting, exact blank Destination 9.
- [x] Name inherited vtable slots without changing exact dwords.
- [x] Apply UID0002MK `92/95`, false/non-emitting, exact blank Destination 10.
- [x] Preserve exact UID0002MK bytes/xrefs/boundaries.
- [x] Apply UID00017K `90/93`, false/non-emitting, exact blank Destination 11.
- [x] Correct UID00017K exact local range and complete source/compiler child union.
- [x] Apply UID0000IY `92/93` no-loss source/compiler/global/resource union.
- [x] Preserve exact filename/private-name confidence caps.
- [x] Verify UID00017M formal remains byte-for-byte unchanged.
- [x] Verify UID0002HA formal remains byte-for-byte unchanged.
- [x] Verify UID0002HB formal remains byte-for-byte unchanged.
- [x] Verify UID0000U4 and UID0000UR formals remain byte-for-byte unchanged.
- [x] Verify startup/shutdown pages remain same-or-greater and unchanged.
- [x] Verify MapPane/UserPane/EffectObjectPane consumer pages remain same-or-greater and unchanged.
- [x] Verify adjacent singleton pages remain unchanged.
- [x] Verify LObject/ProtectedArray/resource support remains unchanged.
- [x] Confirm no child registration, path rename, split, padding, or nesting edit is required.
- [x] Confirm all 11 managed destination blocks match this report exactly.
- [x] Confirm no draft/example C++ exists outside formal blocks in ordinary destinations.
- [x] Confirm one-definition policy: only UID0000QT defines the pointer.
- [x] Confirm one extern declaration appears in the complete class/header contract.
- [x] Confirm constructor/destructor source has zero explicit global lifecycle writes.
- [x] Confirm compiler/data destinations emit zero comments, markers, or bodies.
- [x] Scoped-validate UID0001PQ while leased and release immediately.
- [x] Scoped-validate UID0000QT while leased and release immediately.
- [x] Scoped-validate UID00004A while leased and release immediately.
- [x] Scoped-validate UID0002H9 while leased and release immediately.
- [x] Scoped-validate UID00017L while leased and release immediately.
- [x] Scoped-validate UID00017W while leased and release immediately.
- [x] Scoped-validate UID0002HC while leased and release immediately.
- [x] Scoped-validate UID0001U9 while leased and release immediately.
- [x] Scoped-validate UID0001XG while leased and release immediately.
- [x] Scoped-validate UID0002MK while leased and release immediately.
- [x] Scoped-validate UID00017K while leased and release immediately.
- [x] Scoped-validate UID0000IY while leased and release immediately.
- [x] Record every validator command ID, timestamp, exit, ok, warnings, and side effects.
- [x] Run one final authorized UID0001PQ validation with `--wait-generated` after leases clear.
- [x] Verify one complete EffectObjImageLib class and one global definition.
- [x] Verify one each constructor, destructor, RenderEffectFrame, GetEffectInfo, and LoadEffectTables.
- [x] Verify BuildEffectArchiveTable and GetSpriteBounds remain exactly once.
- [x] Verify zero UID0001PQ/UID00017W/UID0002HC/UID0001U9/UID0001XG/UID0002MK/UID00017K marker/body output.
- [x] Verify zero relevant Empty Emitter Markers and duplicate source.
- [x] Verify zero explicit singleton assignment/clear, raw offset, vptr, cookie, delete flag, IDA label, or handwritten RTTI/vtable source.
- [x] Re-read current manual coverage and preserve literal handoff text without editing coverage.
- [x] Reconcile C1PQ-001 through C1PQ-046 to legal terminal callback states with destination proof.
- [x] Populate Validator Results and Changed Files only from actual callback evidence.
- [x] Check implementation rows only after independent destination/validator/generated verification.
- [x] Confirm no forbidden ordinary or restricted file was modified outside accepted scope.
- [x] Confirm no execute_report, probe, count, move, archive, revalidation, or lifecycle command was run.
- [x] Confirm zero leases remain.

READY_FOR_SUPERVISOR_GATE2_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000015994","destination_path":"executed-b-agent-research/B004/0001PQ-g_pEffectObjImageLib-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0001PQ-g_pEffectObjImageLib-source-quality.md","timestamp":"2026-07-21T15:53:48-04:00","uid":"0001PQ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
