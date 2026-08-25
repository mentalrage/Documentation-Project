** TARGET-REPORT-UID:0001OT **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# 0001OT g_pItemObjImageLib Source-Quality Report


## Finalized Report / Current Recommendation

- Applied target state: [UID:0001OT][0x0067a758-0x0067a75c.g_pItemObjImageLib](by-memory/0x0067a758-0x0067a75c.g_pItemObjImageLib.md) is `92/94`, semantic owner UID0000RA, `RECONSTRUCTABLE:FALSE`, blank emitter/position/formal C++, and `Nested:0`.
- Final disposition: UID0001OT is the exact four-byte loader-zero-filled physical slot for the process-wide `ItemObjImageLib` singleton pointer. It remains evidence-bearing binary storage, not a second source declaration or source definition.
- Applied source state: [UID:0000RA][g_pItemObjImageLib](by-global/g_pItemObjImageLib.md) is the sole externally linked module definition at position 0 in `NexusTK/render/ItemObjImageLib.cpp`; the complete UID0001UU declaration carries the matching `extern`, and publication/clear is expressed through direct `Singleton<ItemObjImageLib>` construction/destruction rather than handwritten assignments.
- Applied compiler-artifact state: the renamed constructor-unwind Singleton base destructor, scalar deleting destructor, vtable type, and raw RTTI/vtable data are source-declared/generated-binary, false/non-emitting pages with literally blank managed C++.
- Applied human-source state: the complete accepted constructor behavior is preserved after removing only compiler-lowered singleton publication, and UID00017O emits an empty ordinary destructor whose implicit member/base destruction regenerates the raw cleanup body.
- Confidence: very strong for address, size, zero initializer, 65-reference inventory, five lifetime writes, class hierarchy, PMD/EBO layout, one-definition policy, and source/compiler split; strong for the project-canonical global spelling and historical header spelling.
- Callback state: all accepted C01-C30 and Destinations 1-12 are implemented and validated; UID00017Y was UID-preserving renamed; final waited generation passed. The exact twelve-row manual coverage text remains supervisor-owned and unapplied by B002. B002 does not run report execution or lifecycle commands; current/future path and lifecycle state remain externally authoritative.

## Supporting Research

- Mandatory MCP evidence was collected from the live adopted NexusTK database session `9b0396a3`, discovered through `idb_list`. Final evidence-time health was `status:ok`, image base `0x00400000`, and auto-analysis, Hex-Rays, and string cache all ready. A valid bounded `get_bytes` call returned four zero bytes at `0x0067a758`; `xrefs_to` returned exactly 65 entries with `more:false`.
- Current active coordination at the final evidence read: B001 is implementing UID0001NI, B003 is researching UID0001OM, B004 is researching UID0001NJ, and B005 is repairing the analogous UID0001OS LanguageMan callback. None owns an ItemObjImageLib destination. `tools/leaser/lease.json`, the central lease report, and B002's lease report all showed no active leases.
- The active B005 LanguageMan artifact was read as an adjacent-family comparator at callback-state SHA256 `0163F5E068C05A094AA7DEEC52FF4BE37F7426FD843957E0506D884DCACB1DDC`; that path/hash is evidence-collection-time only and is not asserted as durable lifecycle state.
- The strongest completed exact lowering precedent is `executed-b-agent-research/B002/000180-MapTileImageLibSingletonClearHelper-source-quality.md`, SHA256 `1D5C298A1DE3FCECE9F1050E66228A662F85128EBFC8CF808517FD73B0359476`. It independently resolves the same direct Singleton base, PMD `+0x04`, EBO overlap, constructor EH base-destructor instantiation, implicit clear, scalar wrapper, and one-definition pattern.
- Exact ItemObjImageLib reports opened and preserved as historical/evidence inputs were:
  - `executed-b-agent-research/B005/0002SD-ItemObjImageLibConstructor-source-quality.md`, SHA256 `5E40CAE2204B65D6B5B0BD87F0115CDB9FF005743185BCB6571272B8D258987E`.
  - `executed-b-agent-research/B002/00017O-ItemObjImageLibDestructor-source-quality.md`, SHA256 `3965571D7BB42B40AEF2477097C8E42A06EB63DE4CB827C8564D70AC28E377BB`.
  - `executed-b-agent-research/B013/00017Y-ItemObjImageLibSingletonClearHelper-source-quality.md`, SHA256 `0F257FD4B3587C08A57B5BA19C58D53695F56128C1F711680079EC6C67CAD8B2`.
  - `executed-b-agent-research/B014/0002VC-ItemObjImageLibScalarDeletingDestructor-source-quality.md`, SHA256 `BEE41FA03017A58550CD028AC7942B2CB5D9D3A98AB9549715DDD862EE403488`.
  - `executed-b-agent-research/B005/00017N-ItemObjImageLibLocalMethodCluster-source-quality.md`, SHA256 `7D59926E4D62FC5462F8BBE6C6EA289BE62AB00B36912861CD3C7D0A232D72AD`.
  - `executed-b-agent-research/B007/0000KH-ItemObjImageLib-empty-emitter-family-source-quality.md`, SHA256 `C2F5EBCF369483BBFA25C1387603EDCB54E592DB62017DD428CCC05392B94E73`.
  - `executed-b-agent-research/B008/00006W-ItemObjImageLib-class-source-quality.md`, SHA256 `CE6D90CF1DAA3F501D4BB8388765FC48A7E7337ECC0E9839631FF3A0DE998BCB`.
- Search terms were `UID0001OT`, `UID:0001OT`, `0x0067a758`, `0x0067a75c`, `g_pItemObjImageLib`, `g_pItemObjectImageLib`, `g_pItemImageLib`, `dword_67A758`, `DAT_0067a758`, `ItemObjImageLib`, `Singleton<ItemObjImageLib>`, `UID0000RA`, `UID00006W`, `UID0000KH`, `UID00017N`, `UID0002SD`, `UID00017O`, `UID00017Y`, `UID0002VC`, `UID0001XW`, `UID0001UU`, and `UID0002ML`.
- Report roots searched: current `tools/leaser/Agents/Agent-B001` through `Agent-B005` research roots, central `executed-b-agent-research`, and `archived`. No prior direct UID0001OT report exists. The active roots yielded only the adjacent LanguageMan comparator; `archived` yielded no matching B-report artifact. The executed root yielded the direct family reports above and consumer reports used only to name reader groups.
- Consumer reports were not treated as storage owners. They corroborate that fitting-room, ranking, clan, exchange, inventory, item-menu, ItemObjectPane, SelfLook, and UserLook code reads the singleton to render/query item imagery.

## Target

- Target UID: `0001OT`.
- Target path: `by-memory/0x0067a758-0x0067a75c.g_pItemObjImageLib.md`.
- Exact range: half-open `0x0067a758-0x0067a75c`, four bytes.
- Evidence-time source queue row: `by-memory` -> `Not-Covered Files - Reconstructable` at historical tracker command `000000015419`.
- Evidence-time/pre-callback state: `86/90`, canonical owner UID0000RA, reconstructable true, emitter UID0000RA, blank position, comment-only formal, `Nested:0`.
- Applied state: `92/94`, canonical semantic owner UID0000RA, reconstructable false, blank emitter/position/formal, `Nested:0`; current SHA256 `6626BE385AA89F4BFC1C21A21BDCFF29936943F66C443F20440D60B6AAE7C0F0`, `15,559` bytes, `145` lines.

## Current Target State

- Evidence-time/pre-callback target SHA256 was `13DC9A1B4556B0BC8791ED43BEBBEFD80F484D6382B0B54B08CE8BE80755CB03` (`10,242` bytes, `103` lines). It recognized UID0000RA semantically but remained reconstructable/comment-emitting; that mixed state is superseded.
- Applied target SHA256 is `6626BE385AA89F4BFC1C21A21BDCFF29936943F66C443F20440D60B6AAE7C0F0` (`15,559` bytes, `145` lines). It preserves all 65 refs, five lifetime writes, 60 reads, zero bytes, boundaries, aliases, history, and negative evidence while cleanly separating physical storage from source emission.
- Evidence-time prose called `0x004dec82` a fallback clear and UID00017Y a standalone cleanup helper. Applied prose historicalizes those assumptions and records null-adjusted direct-base publication plus the constructor-unwind-only Singleton base destructor.
- Applied UID0000RA is `92/94`, owner/emitter UID0000KH, position 0, SHA256 `DA3F4792A86448158AD035A2A2B344DE1EE8F59725EAA215947C120F66D5D7DD`, with one local forward declaration and sole zero definition.
- Applied UID0001UU is `92/94`, owner/emitter UID00006W, position 1, SHA256 `53691404E9E41257E62956B7E82DC59F987E31BAFD2C1A7ABE8A3F84C7BB40A2`; it preserves the complete union and adds only direct Singleton inheritance and one external declaration.
- Applied constructor UID0002SD is SHA256 `27A5DB73AD7D77F921828DAAFAF3247567895AC2BA22D07C37B6C9BDDE41008E`, `92/94`, position 10, with Singleton initializer and zero explicit publication. Applied ordinary destructor UID00017O is SHA256 `9AB1FB6821E8401390F633AA69A0861E41F5721094ED60CFBE570F39FB4B882C`, `92/94`, position 30, with the exact empty source body.
- UID00017Y now exists only at `by-memory/0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonBaseDestructor.md`, SHA256 `B04CBC57947E403DDB8A06E9F9653A53AB18C094F652576D8F39447B9C460AF0`; the old path is absent. UID00017Y, UID0002VC, UID0001XW, and UID0002ML are false/non-emitting with blank formal C++ and retain exact compiler evidence.
- Evidence-time generated `auto-generated/NexusTK/render/ItemObjImageLib.cpp` is validator command `000000015419`, refreshed `2026-07-20T16:00:18-04:00`, SHA256 `FC0846C02199367D306AD8238A47252D7563CAF00F2D9869B63F3E31B8B2EFFA`, `7,625` bytes, `176` lines. It has one class without the Singleton base, one global definition, one constructor with an explicit publication assignment, comment emissions for UID00017Y/UID0002VC/UID0001XW/UID0002ML, and four unrelated draw-method Empty Emitter Markers. UID0001OT itself contributes no generated occurrence.
- Evidence-time tracker command `000000015419` has SHA256 `45FD1B3E9582E71DAA052A046E88AAD6ED51B92BDC19159B65E600A5F589E831`, `1,531,696` bytes, `6,206` lines. These generated/tracker observations are time-bounded evidence, not indefinite current-state claims.
- Callback waited command `000000015456`, refreshed `2026-07-20T16:49:16-04:00`, produced ItemObjImageLib.cpp SHA256 `9D79F134AB74CBE86EFE6925166D9F03F1DB5E6A38EBE815AEE4B7A9F4D0D719`, `6,435` bytes, `169` lines, and callback-time tracker SHA256 `19625F36DED092FF386B2DE22B37A2BB6F811080B17BDAD2CF789834BBB6E19E`, `1,532,009` bytes, `6,206` lines. At the final read, unrelated deferred command `000000015457`, refreshed `2026-07-20T16:59:27-04:00`, advanced only the shared tracker snapshot to SHA256 `A407593D1D037B33157874C9A5A3B3C0060F9A6BEB959FCA970D68944E3A20BB`, `1,532,253` bytes, `6,207` lines; affected ItemObjImageLib rows retain the callback scores/dispositions. These observations are time-bounded, not permanent latest-state claims.
- Generated source has exactly one complete `class ItemObjImageLib : public LObject, public Singleton<ItemObjImageLib>`, one extern declaration, one zero definition, one Singleton-initialized constructor, zero explicit `g_pItemObjImageLib = this`, and one empty destructor. It has zero UID0001OT/UID00017Y/UID0002VC/UID0001XW/UID0002ML occurrences, zero affected Empty Emitter Markers, and no handwritten scalar flags, size/delete guards, RTTI arrays, or vtable dwords. Exactly four unrelated draw Empty Emitter Markers remain.

## Executive Recommendation

- UID0001OT is now a non-emitting physical-storage page with UID0000RA retained as semantic owner, so the binary slot remains linked to source without becoming source itself.
- UID0000RA is the sole externally linked module definition at position `0`, preceded by a local class forward declaration; the complete UID0001UU block carries the matching `extern`, and the storage page has no second definition.
- UID0001UU now declares direct public `Singleton<ItemObjImageLib>` inheritance. This source statement accounts for constructor publication, constructor-EH clear, ordinary/scalar clear, RTTI hierarchy, and EBO.
- Constructor/destructor source routes through UID00006W at positions `10` and `30`. The constructor body is preserved except for the explicit global assignment and added Singleton initializer; the ordinary destructor is the accepted empty body.
- UID00017Y is UID-preserving renamed to `by-memory/0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonBaseDestructor.md` and is false/non-emitting. The scalar wrapper and both vtable pages are likewise false/non-emitting without loss of binary evidence.
- UID00017N remains a non-emitting split index, and all draw/glyph/table helper work remains unchanged.

## Supervisor Active Recheck

- Supervisor accepted exact pre-callback SHA256 `1206FEFA4A57BA79CD5FF60BF6EC58574F96FE9E602D8BA3DFCC7499747BD9F8` for implementation; this same report now records the completed bounded callback.
- The assigned item did not require a new child split. Existing exact children already cover constructor, ordinary destructor, EH base-destructor instantiation, scalar deleting destructor, layout, vtable, and raw vtable data.
- Every directly source-bearing item in the singleton-lifetime scope is applied with a destination-ready source body or exact false/non-emitting disposition. The four unrelated draw bodies retain their existing target-specific option-record blockers and were not changed.
- No duplicate report or child page was created. UID00017Y was UID-preserving renamed through validator command `000000015443`, which propagated the new path while retaining UID and evidence.

## Inference Research Guidance Check

- Binary facts, documentation facts, and inference are separated throughout. Direct addresses, bytes, xrefs, RTTI descriptors, PMD values, and EH jumps are IDA facts. Existing source-facing names and field declarations are documentation evidence. Original header spelling, linkage syntax, and template static-member spelling are bounded inference.
- Existing statements that the target is source-authored storage, the constructor contains a fallback clear, and UID00017Y is a standalone static cleanup helper were treated as uncertain and revalidated rather than inherited.
- `by-structure.md` source-shape discipline favors the human declaration that regenerates compiler output. Therefore direct Singleton inheritance replaces decompiler-shaped global writes, helper APIs, vptr stores, raw frees, scalar flags, and handwritten vtable arrays.
- The current project convention uses plausible mid-2000s C++, integer zero for null, complete class declarations, child-owned method definitions, and semantic global pages for one module definition.
- Any Wave2/Wave3 language found in old evidence was ignored as stale. No current explicit override authorizes it.

## Heuristic / Inference Reanalysis And Validation

- Physical versus semantic identity: four zero bytes and 65 direct operands prove physical storage, while UID0000RA supplies the source-facing typed variable. The backing page is therefore false/non-emitting, not a second declaration.
- Name: current IDA still displays raw `dword_67A758` in fresh decompilation. The project-wide class/global/consumer union consistently uses `g_pItemObjImageLib`; older `g_pItemObjectImageLib` and `g_pItemImageLib` spellings are aliases. `g_pItemObjImageLib` is accepted as the highest-probability source name but lexical confidence remains capped.
- Type: constructor publication stores an adjusted `ItemObjImageLib *`; all consumers use the same complete object and call class methods or access `m_itemInfos`. The type is `ItemObjImageLib *`, not `void *`, integer storage, reference, smart pointer, or pointer-to-pointer.
- Linkage: 60 reads span many source families. File-local/static linkage is rejected. The source policy is one external declaration in the class/header route and one definition in ItemObjImageLib.cpp.
- Singleton hierarchy: ItemObjImageLib RTTI contains self, LObject, and `Singleton<ItemObjImageLib>` base descriptors. The Singleton BCD PMD is `{mdisp=4,pdisp=-1,vdisp=0}` with attributes `0x40`; that is a direct nonvirtual empty base at `+0x04`.
- EBO: the complete object remains `0x28` bytes. The empty Singleton base at `+0x04` overlaps the first nonempty member, `ProtectedArray<ItemInfo> m_itemInfos`, at the same offset. Adding the base does not insert storage or move the accepted member layout.
- Constructor publication: the decompiler's branch tests the complete-object recovery from base receiver `this+4`; the `a1 == -4` form is a null-adjustment artifact. The two stores at `0x004dec7b` and `0x004dec82` are compiler lowering of direct Singleton base construction, not handwritten success/fallback statements.
- Constructor body: table selection, `ProtectedArray` initialization, default row, allocation/growth, and five-field row loading remain authored behavior and are preserved exactly. Only singleton publication moves from the body to base initialization.
- Ordinary destructor: exact bytes restore vptrs, free `m_itemInfos.m_entries`, clear the singleton, and tail-call LObject teardown. The reverse sequence exactly matches implicit destruction of member, Singleton base, then LObject base. No unique authored cleanup statement remains, so an empty destructor body is the complete human source.
- UID00017Y: exact eleven bytes clear the global and return; the only incoming code edge is constructor unwind funclet `0x00600158`, after `this+4` adjustment. The body is the out-of-line specialization of the source-declared Singleton base destructor. A free/static helper, atexit callback, public class method, and explicit specialization body are rejected.
- Scalar wrapper: the vtable-only `0x5c` body duplicates ordinary member/base cleanup, applies deleting flags and size/free mechanics, and is compiler-generated from the virtual destructor. It must not emit source.
- Vtable/RTTI: the three-slot table and complete-object locator are generated from the class and virtual declarations. Evidence-time comment markers polluted source; the applied pages are blank and false/non-emitting.
- Header/source policy: the complete class block can safely carry the external declaration. UID0000RA carries a local forward declaration plus the sole zero-initialized definition so generated source remains compile-visible even if file-level position `0` precedes the class block.
- Original template static-member spelling: the binary proves one slot and direct Singleton lowering but not whether the original template header called it a specialization/static member internally. Emitting an additional template static definition would duplicate storage, so it is rejected. The accepted project name maps that one storage location.
- Range: target is exactly four bytes. Adjacent zero singleton slots at `0x0067a750`, `0x0067a754`, `0x0067a75c`, and `0x0067a760` have distinct xref populations and are not part of UID0001OT.
- Score blockers: all required identity, range, liveness, caller, source shape, type, linkage, one-definition, template, compiler-artifact, ownership, formal-C++, and coverage blockers were closed. Remaining uncertainty is lexical only and explains the 94 confidence cap.

## Evidence Standards Used

- Direct IDA MCP evidence: `idb_list`, `server_health`, bounded bytes, global values, xrefs, function lookup, decompilation, disassembly, RTTI names/bytes, and caller/callee routes.
- Exact byte evidence: target zero storage; constructor, ordinary destructor, EH base destructor, scalar wrapper, vtable, RTTI hierarchy, and constructor unwind funclets.
- Structural evidence: complete object size, direct bases, PMD, EBO overlap, member offsets, vtable stores, destruction order, and neighboring slot boundaries.
- Liveness evidence: all 65 target references, unique startup constructor call, Application shutdown delete, unique EH funclet route, and vtable-only scalar wrapper route.
- Documentation evidence: current by-memory/by-global/by-class/by-file/by-struct/by-vtable pages, generated source, tracker, manual coverage, current active reports/goals, leases, and matching executed reports.
- Negative evidence: no independent function at the slot, no second storage, no ordinary caller to UID00017Y, no atexit/import/pointer route, no scalar ordinary caller, no source need for raw vtable data, and no separate consumer ownership.
- Confidence is below absolute only because source/PDB symbols do not prove original global/header/template-member spelling. That does not block behavior-identical source.

## Evidence Checked

- MCP health and bounds: live session `9b0396a3`, `status:ok`, target bytes `00 00 00 00`, surrounding singleton window zero, and distinct neighboring slots.
- Target xrefs: exact 65-entry result with `more:false`; every address was grouped and classified below. Five are lifetime writes and 60 are reads.
- Lifetime bodies: constructor `0x004dec30-0x004dee1b`, ordinary destructor `0x004dee20-0x004dee4d`, EH base destructor `0x004e5ba0-0x004e5bab`, scalar wrapper `0x004e6580-0x004e65dc`, startup caller, shutdown delete, and vtable refs.
- RTTI: ItemObjImageLib complete-object locator/hierarchy and `Singleton<ItemObjImageLib>` BCD/CHD/base array, including PMD `+0x04` and direct-base attributes.
- Current ordinary docs: target, semantic global, class, file, layout, constructor, destructor, helper, scalar wrapper, vtable type/data, local aggregate, adjacent storage/global pages, Application, and representative consumer pages.
- Current generated/tracker/manual files: ItemObjImageLib.cpp, `-ag-research-tracker.md`, and by-memory/by-global/by-class/by-file/by-struct/by-vtable manual coverage files.
- Reports: all direct family reports listed under Supporting Research plus the MapTile and LanguageMan direct-Singleton comparators.
- Search roots/outcomes: current agent research roots had no direct UID0001OT report; executed root had the historical family reports; archived root had no direct match.
- Negative routes checked: function object at storage, extra storage aliases, helper callers/callees, data/VA/RVA helper pointers, static/atexit route, second global definition, and consumer-source ownership.
- One malformed client-side `get_bytes` request initially omitted the current required `regions` wrapper; `tools/list` was reread and the corrected bounded call succeeded. This was a client schema error, not MCP unavailability, and no evidence relies on the malformed call.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | UID0001OT is exactly four loader-zero-filled bytes at `0x0067a758-0x0067a75c`. | 99% | bounded bytes and boundaries retained in target SHA `6626BE...C0F0` | Destination 1 target | incorporate | applied |
| C02 | UID0001OT is physical backing storage and must be false/non-emitting with blank formal C++. | 98% | target metadata/formal plus zero generated UID occurrence | Destination 1 target | incorporate | applied |
| C03 | UID0000RA is the sole typed module definition for the slot. | 97% | global SHA `DA3F47...D7DD`; one generated definition | Destination 2 global | incorporate | applied |
| C04 | The complete target inventory is exactly 65 refs, with no truncation. | 99% | complete inventory retained on target/global/class/file | target/global/class/file prose | incorporate | applied |
| C05 | Five refs are constructor/ordinary/EH/scalar lifetime writes. | 99% | all five exact write addresses retained | target/global/lifecycle prose | incorporate | applied |
| C06 | The other 60 refs are reads across 26 consumer/startup-shutdown groups. | 98% | complete grouped read inventory retained | target/global/file prose | incorporate | applied |
| C07 | `g_pItemObjImageLib` is the accepted project-canonical typed source name. | 94% | one extern/definition and synchronized prose | target/global/class/file | incorporate | applied |
| C08 | `g_pItemObjectImageLib`, `g_pItemImageLib`, `dword_67A758`, and `DAT_0067a758` are historical/raw aliases only. | 94% | superseded aliases retained explicitly as history | target/global/file history | historicalize | applied |
| C09 | The pointer has external linkage; static/file-local placement is invalid. | 97% | generated one extern plus one non-static definition | Destination 2 and Source Placement | reject-invalid | applied |
| C10 | Header/source policy is one `extern` declaration plus one zero-initialized definition. | 97% | final generated exact counts `1/1` | Destinations 2-3 | incorporate | applied |
| C11 | ItemObjImageLib directly inherits `Singleton<ItemObjImageLib>`. | 99% | UID0001UU and generated direct base | Destination 3 layout | incorporate | applied |
| C12 | The Singleton base is nonvirtual at PMD `+0x04` and overlaps `m_itemInfos` through EBO. | 99% | layout/class/file/aggregate callback sections | layout/class/file prose | incorporate | applied |
| C13 | Constructor stores at `0x004dec7b/82` are compiler base-construction lowering. | 98% | constructor prose and removal of explicit assignment | Destination 4 constructor | reject-stale | applied |
| C14 | The accepted table-loading constructor body remains otherwise unchanged. | 97% | Destination 4 retained body plus exact generated readback | Destination 4 constructor | already-present | already-present |
| C15 | The ordinary human destructor is an empty body; all observed operations are implicit member/base lowering. | 98% | UID00017O exact empty formal and generated definition | Destination 5 destructor | incorporate | applied |
| C16 | UID00017Y is the EH-only Singleton base destructor and was UID-preserving renamed descriptively. | 99% | command `000000015443`; old absent/new present, same UID | Destination 6 helper | incorporate | applied |
| C17 | UID0002VC is a compiler scalar deleting destructor and must be false/non-emitting. | 99% | UID0002VC `93/96`, false/blank, zero generated occurrence | Destination 7 scalar | incorporate | applied |
| C18 | UID0001XW is source-declared/generated-binary vtable support and must be false/non-emitting. | 98% | UID0001XW `92/95`, false/blank, zero generated occurrence | Destination 8 vtable type | incorporate | applied |
| C19 | UID0002ML is raw compiler RTTI/vtable data and must be false/non-emitting. | 99% | UID0002ML `92/95`, class-owned false/blank | Destination 9 vtable data | incorporate | applied |
| C20 | UID0001UU must preserve the complete class union while adding the direct Singleton base and external global declaration. | 98% | layout SHA `536914...40A2`; generated structural equality | Destination 3 layout | incorporate | applied |
| C21 | UID00006W remains the semantic class route and must document the direct Singleton/compiler split. | 97% | class SHA `2ADC66...D432`, `92/94` | Destination 10 class prose | incorporate | applied |
| C22 | UID0000KH remains the sole source file and must document header/source one-definition placement. | 97% | file SHA `51B29C...BC2A`, `92/94` | Destination 11 file prose | incorporate | applied |
| C23 | UID00017N remains a false/non-emitting split index with exact children; it must not duplicate source. | 98% | aggregate SHA `663D4A...117`, `90/93`, false/blank | Destination 12 aggregate prose | already-present | already-present |
| C24 | Application startup constructs once and shutdown deletes once; Application does not own the global. | 98% | existing Application evidence reread unchanged | Destination 13 verify-only | already-present | already-present |
| C25 | Adjacent EventMan/LanguageMan/MapTile/NewHuman slots are distinct singleton storage, not one aggregate. | 99% | target range/boundary prose retained | target/global range prose | incorporate | applied |
| C26 | Scores/metadata match the destination matrix exactly. | 96% | all twelve destination hashes and validator registry updates | Score And Metadata Recommendation | incorporate | applied |
| C27 | Generated output must contain one class, extern, definition, constructor, and destructor with zero affected artifact markers/duplicates. | 97% | command `000000015456`, SHA `9D79F1...D719` | generated verification checklist | incorporate | applied |
| C28 | Stale fallback/static-cleanup/handwritten-wrapper/vtable assumptions remain labeled historical, not deleted. | 98% | changed-page history and supersession labels retained | all changed docs/history | historicalize | applied |
| C29 | Twelve current manual coverage rows require the exact supervisor-owned replacements below. | 99% | six current manual files reread; exact handoff rebased and preserved | manual coverage handoff | incorporate | excluded-with-reason |
| C30 | Callback must use serial leases, UID-preserving validator rename, scoped validators, waited generation, and no prohibited edits/lifecycle actions. | 99% | commands `15433-15456`, one-file leases, final zero leases | implementation checklist | incorporate | applied |

## Positive Evidence Summary

- The exact slot is zero initialized, four bytes wide, and referenced 65 times without truncation.
- The lifetime quartet plus the constructor's null-adjustment store produce five writes at exactly the places direct Singleton base lowering predicts.
- RTTI independently names `Singleton<ItemObjImageLib>` and fixes its direct nonvirtual PMD at `+0x04`.
- Complete size `0x28` and accepted `ProtectedArray<ItemInfo>` at `+0x04` prove EBO overlap rather than a missing field.
- Constructor unwind state adjusts to the `+0x04` base and jumps only to the exact eleven-byte clear body.
- Ordinary and scalar destruction repeat member cleanup, Singleton clear, and LObject teardown in reverse source order.
- Startup has one constructor call; shutdown reads/deletes the same global; 60 other reads span many source modules.
- Final generated output has only one semantic global definition, proving the physical page does not need and must not emit.
- MapTileImageLib and current LanguageMan evidence independently show the same compiler pattern and source disposition.

## IDA MCP Facts

- Active database at final evidence read: `9b0396a3`, `NexusTK.exe.i64`, worker PID `15732`; server health `ok`, analysis/Hex-Rays/strings ready.
- Target bytes: `00 00 00 00`; SHA256 of the four-byte value is `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`.
- Surrounding `0x0067a748-0x0067a768` window was zero. The 32-byte window SHA256 is `66687AADF862BD776C8FC18B8E9F8E20089714856EE233B3902A591D0D5F2925`.
- Constructor `0x004dec30-0x004dee1b`: `0x1eb` bytes, SHA256 `87FD11568820B71E40D1BEFE6E43C7169A1CF7291D110A4748B86E50A35B8B81`; sole direct source caller is Application startup at `0x004f602f`.
- Ordinary destructor raw body `0x004dee20-0x004dee4d`: 45 bytes, SHA256 `43923353D14426CC5B262962F8DF73FCC506EA3D4823D551F3BA6BC5E142F2C7`; no modeled function at its raw start.
- EH base destructor `0x004e5ba0-0x004e5bab`: bytes `c7 05 58 a7 67 00 00 00 00 00 c3`, SHA256 `8D2BC97237A2D699543DE8F26AC840C61FEDFEDDBED8AEB91273E84A610DBAF4`.
- Constructor EH funclet window `0x00600150-0x00600168`: SHA256 `412EF9ABD32D8D7614BBF1481E95C980244186E9AC44FCB01C2526580C5053BA`; at `0x00600152` it loads the saved complete object, adds four, and at `0x00600158` jumps to UID00017Y.
- Scalar wrapper `0x004e6580-0x004e65dc`: 92 bytes, SHA256 `A141D732FDF0EBEBF822883E3370C0BBCA79E4B5CF3F34805781DF42EDA8F495`.
- Vtable data `0x0061b738-0x0061b748`: 16 bytes, SHA256 `C50D749B32F94DC794B774469F1EF64FF8E905C2D76D741BC82ADF44D37B3CBF`.
- RTTI hierarchy bytes: 156 bytes, SHA256 `A64A7E16A5B833F13880134FF1EBAB8A1D83187342016BDADA08F84706D9852A`; hierarchy entries are ItemObjImageLib, LObject, and Singleton<ItemObjImageLib>.
- Singleton BCD PMD: `mdisp=4`, `pdisp=-1`, `vdisp=0`; attributes `0x40`.
- Vtable xrefs: constructor writes at `0x004dec8c`, raw destructor at `0x004dee23`, scalar wrapper at `0x004e6586`; the scalar wrapper is reached only through the vtable.
- Application shutdown reads the global at `0x004f6632`, checks it, and invokes its deleting destructor with flag `1`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Applied score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0067a758-0x0067a75c` | UID0001OT target | physical singleton backing slot | false | UID0000RA semantic global | `92/94` | applied blank non-emitting Destination 1 |
| semantic variable | UID0000RA by-global | sole external definition | true | UID0000KH file | `92/94` | applied Destination 2, position 0 |
| class/layout | UID0001UU by-struct | complete class/header declaration | true | UID00006W class | `92/94` | applied Destination 3, position 1 |
| `0x004dec30-0x004dee1b` | UID0002SD constructor | human constructor plus compiler base lowering | true | UID00006W class | `92/94` | applied Destination 4, position 10 |
| `0x004dee20-0x004dee4d` | UID00017O destructor | empty human destructor plus implicit member/base lowering | true | UID00006W class | `92/94` | applied Destination 5, position 30 |
| `0x004e5ba0-0x004e5bab` | UID00017Y renamed Singleton base destructor | compiler EH-only base-destructor instantiation | false | UID00006W semantic class | `93/96` | applied blank Destination 6 |
| `0x004e6580-0x004e65dc` | UID0002VC scalar deleting destructor | compiler ABI wrapper | false | UID00006W semantic class | `93/96` | applied blank Destination 7 |
| type route | UID0001XW vtable | compiler vtable/RTTI type support | false | UID00006W semantic class | `92/95` | applied blank Destination 8 |
| `0x0061b738-0x0061b748` | UID0002ML vtable data | raw compiler RTTI/vtable bytes | false | UID00006W semantic class | `92/95` | applied blank Destination 9 |
| class route | UID00006W class | semantic class/child registry | true | UID0000KH file | `92/94` | applied prose support; formal union preserved |
| source root | UID0000KH file | `NexusTK/render/ItemObjImageLib.cpp` | file root | FILE | `92/94` | applied prose support only |
| `0x004dec30-0x004df500` | UID00017N aggregate | non-emitting exact split index | false | NONE | `90/93` | applied support; child inventory/no duplicate source preserved |

## Direct Xref / Caller Inventory

The MCP result contains exactly 65 xrefs: five writes and 60 reads. Addresses below are complete, not representative-only.

| Function / source-facing group | Exact refs | Count | Disposition |
| --- | --- | --- | --- |
| FittingRoomListPane paint `0x0041f2b0` | `0x0041f72d`, `0x0041f79c`, `0x0041f854` | 3 reads | item rendering consumer |
| RankingDialog paint `0x0045b630` | `0x0045bb5a`, `0x0045bbbe`, `0x0045bc21` | 3 reads | item rendering consumer |
| RankingRewardInfoDialog OnPaint `0x0045df90` | `0x0045e7f6`, `0x0045e860`, `0x0045e8f0` | 3 reads | reward rendering consumer |
| ClanItemListPane draw `0x0048b0a0` | `0x0048b0fd` | 1 read | item-list consumer |
| ClanBankItemListPane draw `0x0048c040` | `0x0048c0ca`, `0x0048c145` | 2 reads | item-list consumer |
| EmployeeDialogPane OnPaint `0x004a2560` | `0x004a2869`, `0x004a2888` | 2 reads | employee-item consumer |
| EmployeeItemPropertyDialogPane OnPaint `0x004a4570` | `0x004a45e7`, `0x004a4638` | 2 reads | item-property consumer |
| ExchangeItemListPane DrawItemEntry `0x004ae1c0` | `0x004ae208`, `0x004ae2b2`, `0x004ae35f`, `0x004ae3d4` | 4 reads | exchange consumer |
| MyItemListPane DrawListEntry `0x004aec90` | `0x004aed0c`, `0x004aedbc`, `0x004aeec0`, `0x004aef3e` | 4 reads | item-list consumer |
| WillBeChangedItemPane constructor/core `0x004c78e0` | `0x004c79a6` | 1 read | item-pane consumer |
| WillBeChangedItemPane OnPaint `0x004c7bb0` | `0x004c7bdb`, `0x004c7c77`, `0x004c7e1e` | 3 reads | item rendering consumer |
| ItemObjImageLib constructor `0x004dec30` | `0x004dec7b`, `0x004dec82` | 2 writes | Singleton base publication/null-adjustment lowering |
| raw ordinary destructor | `0x004dee3b` | 1 write | implicit Singleton base destruction |
| UID00017Y EH base destructor | `0x004e5ba0` | 1 write | constructor unwind clear |
| UID0002VC scalar wrapper | `0x004e659e` | 1 write | implicit Singleton base destruction copy |
| InventoryPane OnPaint `0x004ea2a0` | `0x004ea408`, `0x004ea490`, `0x004ea6bb`, `0x004ea73d` | 4 reads | inventory consumer |
| NewInventoryPane paint `0x004ebb20` | `0x004ebd72`, `0x004ebe2f`, `0x004ec396`, `0x004ec3d9` | 4 reads | inventory consumer |
| InventoryPane2 OnPaint `0x004ee6f0` | `0x004ee863`, `0x004ee8d6`, `0x004eeba6`, `0x004eebf4` | 4 reads | inventory consumer |
| Application shutdown `0x004f6490` | `0x004f6632` | 1 read | lifetime consumer/delete, not owner |
| MapPane CreateOrUpdateObjectPane `0x00505e00` | `0x00505eac` | 1 read | direct ItemInfo consumer |
| ServerItemMenuItemList draw `0x0051b3e0` | `0x0051b482`, `0x0051b52b`, `0x0051b69d`, `0x0051b716` | 4 reads | item-menu consumer |
| ClientItemMenuItemList draw `0x0051c6c0` | `0x0051c73c`, `0x0051c7e6`, `0x0051c8d7`, `0x0051c955` | 4 reads | item-menu consumer |
| ArgumentedMenuMenuItemList DrawMenuItem `0x0051f840` | `0x0051f8d5`, `0x0051f97e` | 2 reads | item-menu consumer |
| ObjectImageControlPane OnPaint `0x005205c0` | `0x00520768`, `0x005207f2` | 2 reads | image-preview consumer |
| ItemObjectPane ClearOutputRects `0x00537bf0` | `0x00537bfa` | 1 read | bounds helper consumer |
| ItemObjectPane RenderFrame `0x00537c70` | `0x00537c8c` | 1 read | item-render consumer |
| FlyingObjectPane GetBoundingRect `0x00537d80` | `0x00537e59` | 1 read | glyph-bounds consumer |
| SelfLookPane OnPaint `0x00567480` | `0x00567493` | 1 read | look-pane consumer |
| SelfLookPane2 OnPaint `0x00570fc0` | `0x00570fe9` | 1 read | look-pane consumer |
| UserLookPane OnDraw `0x005a0640` | `0x005a065a` | 1 read | look-pane consumer |

Count proof: reader counts sum to 60; the two constructor writes plus ordinary, EH, and scalar clears sum to five; total is 65.

## Documentation Evidence And IDA Status

- Evidence-time target/global pages already preserved exact address, storage, owner, aliases, 65-ref count, lifetime sites, and consumer categories, but their source disposition was stale. Current target/global pages retain all evidence and apply the false-storage/sole-definition split.
- UID0001UU preserves the complete accepted method/access/member union, including four draw declarations, public `GetItemGlyphBounds`, MapPane friendship, private refresh helper, and `ProtectedArray<ItemInfo> m_itemInfos`; current SHA `536914...40A2` adds only direct Singleton inheritance and the external declaration.
- UID0002SD preserves complete table-loading source and now applies the bounded direct Singleton initializer/no-body-assignment/class-position correction. UID00017O now emits the exact empty authored destructor.
- UID00017Y, UID0002VC, UID0001XW, and UID0002ML retain exact bytes/control-flow/table evidence and now have the accepted false/non-emitting blank-formal dispositions.
- UID00017N remains a non-emitting local split index, now `90/93`, and preserves unrelated draw blockers. It is support, not an alternate source emitter.
- Historical generated command `000000015419` records pre-callback pollution. Final command `000000015456` proves that affected pollution is gone; exactly four unrelated draw Empty Emitter Markers remain outside this correction.
- Generated tracker state changed only through validators. The twelve manual rows remain stale at the final read and are excluded from B002 write scope; exact supervisor-owned replacements are supplied below against current hashes and anchors.
- Current IDA uses `sub_4DEC30`, `sub_4E5BA0`, `sub_4E6580`, and raw `dword_67A758` in fresh output despite historical saved-name claims. This report does not mutate IDA and treats source-facing names separately.

## Ranked Ownership Analysis

### 1. UID0000RA semantic global in UID0000KH ItemObjImageLib.cpp

- Evidence for: one physical slot, typed class use, all 65 refs, constructor/destructor lifetime, current source route, and broad cross-TU reads.
- Evidence against: exact original global/static-member spelling is not symbol-proven.
- Decision: accepted as sole semantic source definition and physical target owner. Lexical uncertainty caps confidence but does not justify duplicate storage.

### 2. UID00006W ItemObjImageLib class with direct Singleton base

- Evidence for: RTTI directly names ItemObjImageLib, LObject, and Singleton<ItemObjImageLib>; PMD `+0x04`, EBO, constructor EH, ordinary/scalar order, and all class consumers agree.
- Evidence against: the generic Singleton template source header itself is not recovered.
- Decision: accepted semantic owner for constructor, destructor, EH base destructor, scalar wrapper, layout, and vtable artifacts.

### 3. UID0001OT physical storage as source owner

- Evidence for: exact bytes and all operand refs terminate at this address.
- Evidence against: address identity is not a separate source entity; UID0000RA already defines the storage, and a second declaration/definition duplicates output.
- Decision: rejected as emitter. Retain only semantic owner UID0000RA and binary evidence.

### 4. Application or UI consumers

- Evidence for: startup constructs, shutdown deletes, and many UI modules read the pointer.
- Evidence against: no consumer declares the storage or establishes class lifetime; all use a preexisting singleton.
- Decision: rejected as ownership. Application and consumers remain verify-only dependencies.

### Proposed new file/grouping, if applicable

- No new source file, report, or child page is needed.
- Retain `NexusTK/render/ItemObjImageLib.cpp` as the sole source root.
- UID00017Y received a validator-managed UID-preserving descriptive path rename, not a new UID or duplicate page.

## Source Placement

- Header-facing declaration: after the complete `ItemObjImageLib` class declaration in UID0001UU, emit one external declaration. This is the highest-probability original-style compile-visible route because every consumer needs the typed global and the complete class page is already the effective header declaration.
- Source definition: UID0000RA at position `0` in `NexusTK/render/ItemObjImageLib.cpp`, with a local class forward declaration immediately before the one zero-initialized definition. The local forward makes generated ordering safe even when the file-level global precedes the class block.
- Constructor/destructor: class-owned qualified definitions in the same file, positions `10` and `30`. Existing UID0003ND remains position `20`; unrelated children preserve current order.
- Compiler-only pages: UID00017Y, UID0002VC, UID0001XW, and UID0002ML keep semantic class ownership but no emitter/formal source.
- Rejected placements: physical by-memory definition, Application.cpp, consumer UI files, static/internal variable, function-local static, explicit standalone clear helper, handwritten scalar wrapper, handwritten vtable array, and a second template static-member definition.
- Exact original header filename and template member spelling remain unrecovered. Current validator architecture co-locates header/source formals in generated ItemObjImageLib.cpp; the report distinguishes their intended original placement while keeping generated output compile-valid.

## Range / Split / Padding / Reclassification Analysis

- UID0001OT is exactly `[0x0067a758,0x0067a75c)`. It contains one four-byte pointer and no padding, table tail, count, guard, or adjacent field.
- Adjacent slots are `g_pLanguageMan` at `0x0067a750`, `g_pEventMan` at `0x0067a754`, `g_pMapTileImageLib` at `0x0067a75c`, and `g_pNewHumanImageLib` at `0x0067a760`. Zero bytes do not merge these independent variables.
- Existing exact code/data children are sufficient. No new split is required.
- UID00017Y path rename is semantic reclassification only; exact bytes/range/UID remain unchanged.
- UID00017N remains a non-emitting index over the local method island. Constructor/destructor/helper/scalar/vtable pages remain separate exact children/support.
- Reclassifying compiler artifacts false/non-emitting removes comments from generated source but preserves all binary documentation and links.

## Negative Evidence Summary

- No function exists at `0x0067a758`; it is zero-initialized data.
- No second ItemObjImageLib singleton slot, independent alias storage, import, IAT entry, pointer-to-pointer, or aggregate field was found.
- No ordinary caller or callee exists for UID00017Y; its sole code route is constructor EH cleanup after `+4` adjustment.
- No atexit registration, static-init table, data pointer, VA pointer, or RVA pointer makes UID00017Y a source helper.
- No ordinary direct caller reaches UID0002VC; the vtable points to it, matching compiler deleting-destructor emission.
- No source needs raw RTTI/vtable arrays; the class declaration and virtual destructor regenerate them.
- No UI consumer writes the slot or owns construction. Broad reads are linkage evidence, not ownership evidence.
- No exact source/PDB symbol proves the longer aliases or raw IDA name as preferable to `g_pItemObjImageLib`.
- No evidence supports preserving explicit constructor publication, destructor clear, vptr stores, buffer free, LObject tail call, delete flags, size guard, storage free, or vtable dwords as handwritten source.

## IDA Rename / Type / Comment Recommendations

- Source-facing data name: `g_pItemObjImageLib`, type `ItemObjImageLib *`, external linkage. Retain raw `dword_67A758` only in address-level evidence.
- Source-facing class hierarchy: `ItemObjImageLib : public LObject, public Singleton<ItemObjImageLib>`.
- Source-facing method names: preserve the accepted constructor/destructor and existing draw/glyph/refresh names.
- Descriptive generated-binary name: UID00017Y path/title `ItemObjImageLibSingletonBaseDestructor`, not `SingletonClearHelper`. This communicates the direct template role without inventing a callable project API.
- Scalar and vtable names remain descriptive ABI/data names, never public source declarations.
- Do not rename aliases into separate globals. `g_pItemObjectImageLib`, `g_pItemImageLib`, `DAT_0067a758`, and `dword_67A758` all map to the one accepted slot/name.
- No IDA mutation is requested or authorized. These are documentation/source recommendations only.

## First-Draft C++ Recommendation

- Exactly nine managed destination blocks follow. They are destination-specific exact insertion text. Destinations 1 and 6-9 are intentionally blank no-code blocks.
- All human C++ in scope is contained inside these managed blocks. No third-party import applies.

### Destination 1: UID0001OT physical backing storage

```text
*** UID:0001OT | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000RA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Exact four-byte zero-initialized physical backing slot for g_pItemObjImageLib with complete 65-reference inventory, five direct Singleton base/compiler lifetime writes, 60 cross-source reads, distinct adjacent singleton boundaries, and sole typed source definition owned by UID0000RA; this storage page is false/non-emitting and cannot duplicate source. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### Destination 2: UID0000RA sole module definition

```text
*** UID:0000RA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ItemObjImageLib;

ItemObjImageLib *g_pItemObjImageLib = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 3: UID0001UU complete header/class declaration

```text
*** UID:0001UU | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00006W | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00006W | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ItemObjImageLib : public LObject, public Singleton<ItemObjImageLib>
{
public:
    ItemObjImageLib();
    virtual ~ItemObjImageLib();

    int DrawItemImage(void *drawOwner, const RectBounds *dstRect, short itemId, unsigned char paletteFlags, AlphaMaskSurface *overlayMask, float overlayStrength);
    int DrawItemImageIn43x43Slot(void *drawOwner, RectBounds *dstRect, short itemId, unsigned char paletteFlags, AlphaMaskSurface *overlayMask, float overlayStrength);
    int DrawItemImageUnscaled(void *drawOwner, RectBounds *dstRect, short itemId, unsigned char paletteFlags);
    int DrawItemImageScaled(void *drawOwner, RectBounds *dstRect, short itemId, unsigned char paletteFlags);
    void GetItemGlyphBounds(short itemId, RectBounds *outBounds);

private:
    friend class MapPane;

    void RefreshItemFrameAvailability();

    ProtectedArray<ItemInfo> m_itemInfos;
};

extern ItemObjImageLib *g_pItemObjImageLib;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 4: UID0002SD complete constructor

```text
*** UID:0002SD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00006W | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00006W | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
ItemObjImageLib::ItemObjImageLib()
    : Singleton<ItemObjImageLib>()
{
    m_itemInfos.m_count = 0;
    m_itemInfos.m_entries = 0;
    m_itemInfos.m_defaultCapacity = 10;

    m_itemInfos.m_defaultEntry.itemTableId = -1;
    m_itemInfos.m_defaultEntry.paletteSlot = -1;
    m_itemInfos.m_defaultEntry.alpha = 0.0f;
    m_itemInfos.m_defaultEntry.lightImageIndex = -1;
    m_itemInfos.m_defaultEntry.allowPaletteFilter = false;

    DATFile itemTable;
    itemTable.Open(g_useEpfAssets ? L"ITEM.TBL" : L"ITEM.TBD");

    int itemCount = 0;
    ReadEncodedTableInt(&itemTable, &itemCount);

    if (itemCount > 0 && m_itemInfos.m_count != itemCount) {
        ItemInfo *newEntries =
            static_cast<ItemInfo *>(operator new(sizeof(ItemInfo) * itemCount));

        if (m_itemInfos.m_entries != 0) {
            int copyCount = itemCount;
            if (m_itemInfos.m_count < copyCount)
                copyCount = m_itemInfos.m_count;

            memmove(newEntries, m_itemInfos.m_entries, sizeof(ItemInfo) * copyCount);
            free(m_itemInfos.m_entries);
        }

        m_itemInfos.m_count = itemCount;
        m_itemInfos.m_entries = newEntries;
    }

    for (int index = 0; index < itemCount; ++index) {
        ItemInfo itemInfo;
        ReadEncodedTableInt(&itemTable, &itemInfo.itemTableId);
        ReadEncodedTableInt(&itemTable, &itemInfo.paletteSlot);
        ReadEncodedTableFloat(&itemTable, &itemInfo.alpha);
        ReadEncodedTableInt(&itemTable, &itemInfo.lightImageIndex);

        int allowPaletteFilter = 0;
        ReadEncodedTableInt(&itemTable, &allowPaletteFilter);
        itemInfo.allowPaletteFilter = allowPaletteFilter != 0;

        ItemInfo *slot = &m_itemInfos.m_defaultEntry;
        if (index >= 0 && index < m_itemInfos.m_count)
            slot = &m_itemInfos.m_entries[index];

        *slot = itemInfo;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Exact startup-only ItemObjImageLib source constructor with direct Singleton<ItemObjImageLib> base initialization, compiler-lowered +0x04 EBO publication and unwind clear, complete ProtectedArray<ItemInfo> initialization, ITEM.TBL/ITEM.TBD selection, 20-byte row growth/copy/free, five-field row loading, default fallback row, exact range/padding, and no duplicate handwritten singleton assignment. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:4 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### Destination 5: UID00017O complete ordinary destructor

```text
*** UID:00017O | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00006W | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00006W | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:30 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
ItemObjImageLib::~ItemObjImageLib()
{
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Empty authored ItemObjImageLib ordinary destructor whose compiler-generated lowering restores the derived/template vptrs, destroys ProtectedArray<ItemInfo> and frees its entry buffer, destroys Singleton<ItemObjImageLib> and clears g_pItemObjImageLib, then tears down LObject; exact raw range, bytes, padding, scalar parity, and no duplicate handwritten cleanup are documented. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### Destination 6: UID00017Y UID-preserving renamed Singleton base destructor

```text
*** UID:00017Y | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00006W | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Exact eleven-byte compiler-emitted Singleton<ItemObjImageLib> base-destructor instantiation reached only by the ItemObjImageLib constructor unwind funclet after +0x04 base adjustment; direct RTTI/PMD/EBO and ordinary/scalar copies prove implicit template lifetime, not a handwritten clear helper. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### Destination 7: UID0002VC scalar deleting destructor

```text
*** UID:0002VC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00006W | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Exact vtable-only compiler scalar deleting destructor for ItemObjImageLib, duplicating the empty ordinary destructor's implicit ProtectedArray/Singleton/LObject teardown before delete-flag, size-guard, and storage-free ABI mechanics; UID00017O is the sole handwritten destructor source. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### Destination 8: UID0001XW vtable type support

```text
*** UID:0001XW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00006W | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 9: UID0002ML raw RTTI/vtable data

```text
*** UID:0002ML | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00006W | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Exact compiler RTTI complete-object locator and three-slot ItemObjImageLib vtable data with direct ItemObjImageLib/LObject/Singleton<ItemObjImageLib> hierarchy, constructor/ordinary/scalar vptr stores, adjacent ProtectedArray table boundaries, and no handwritten table source. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

- Behavior preservation: direct base construction publishes before member initialization and supplies the exact EH state; reverse destruction frees the member before clearing the singleton and tearing down LObject.
- One-definition preservation: Destination 3 declares externally; Destination 2 defines once; Destination 1 emits nothing.
- Compiler exclusion: no vptr writes, explicit Singleton assignments/clears, member free, base teardown, EH funclet, scalar flags, size guard, object free, RTTI array, or vtable dword is handwritten.

## Final Recommendation

- Destinations 1-9 are applied exactly and remain reproduced below as the accepted formal contract.
- Class/file/aggregate prose support is applied at report-level detail without altering unrelated draw, glyph, table, resource, MapPane friendship, field, or historical evidence.
- UID00017Y's validator-managed UID-preserving path rename is complete; UID, links, registry state, and manual-row destination are coherent.
- Keep UID0001OT semantic owner UID0000RA despite false/non-emitting state; semantic documentation ownership is independent of emission.
- Keep UID0000RA owner/emitter UID0000KH and UID0001UU owner/emitter UID00006W.
- Keep four unresolved draw children outside this correction unchanged; their option-record no-code proofs do not block the singleton lifetime/source shape.
- No future source-quality research or B002 implementation remains for this assignment. Ordinary validation and generated verification are complete; the exact manual coverage handoff and lifecycle remain supervisor/validator-owned.

## Recommended Target Doc Changes

- Target: `by-memory/0x0067a758-0x0067a75c.g_pItemObjImageLib.md`.
- Applied Destination 1 metadata/formal/summary exactly; final SHA256 `6626BE385AA89F4BFC1C21A21BDCFF29936943F66C443F20440D60B6AAE7C0F0`.
- Preserved exact address/size/zero storage, all 65 refs, five lifetime write addresses, every consumer group, adjacent boundaries, class/global/file links, and historical provenance.
- Replaced present-source fallback/helper language with direct Singleton base lowering while preserving former wording as explicitly superseded history.
- Recorded UID0000RA as semantic owner and sole source definition; false/non-emitting does not mean unowned or undocumented.
- Recorded exact byte/hash, full read/write count proof, direct base/PMD/EBO evidence, and generated no-duplicate contract.

## Recommended Support Doc Changes

- `by-global/g_pItemObjImageLib.md`: Destination 2 applied at `92/94`, position `0`, SHA256 `DA3F4792A86448158AD035A2A2B344DE1EE8F59725EAA215947C120F66D5D7DD`.
- `by-type/by-struct/ItemObjImageLibLayout.md`: Destination 3 applied at `92/94`, position `1`, SHA256 `53691404E9E41257E62956B7E82DC59F987E31BAFD2C1A7ABE8A3F84C7BB40A2`.
- `by-memory/0x004dec30-0x004dee1b.ItemObjImageLibConstructor.md`: Destination 4 applied at `92/94`, position `10`, SHA256 `27A5DB73AD7D77F921828DAAFAF3247567895AC2BA22D07C37B6C9BDDE41008E`.
- `by-memory/0x004dee20-0x004dee4d.ItemObjImageLibDestructor.md`: Destination 5 applied at `92/94`, position `30`, SHA256 `9AB1FB6821E8401390F633AA69A0861E41F5721094ED60CFBE570F39FB4B882C`.
- `by-memory/0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonBaseDestructor.md`: UID-preserving rename and Destination 6 applied at `93/96`, SHA256 `B04CBC57947E403DDB8A06E9F9653A53AB18C094F652576D8F39447B9C460AF0`; old path absent.
- `by-memory/0x004e6580-0x004e65dc.ItemObjImageLibScalarDeletingDestructor.md`: Destination 7 applied at `93/96`, SHA256 `A4EA1ECB117A02E2D064574D0D4390E1091B74615015F99EDF1ACD9C0C48D210`.
- `by-type/by-vtable/ItemObjImageLibVtable.md`: Destination 8 applied at `92/95`, SHA256 `DACC8B94E12DD6FE8FB43B49C7DFA0733E5F59E50F20D5D3AF9F8CDB050E01E4`.
- `by-memory/0x0061b738-0x0061b748.ItemObjImageLibVtableData.md`: Destination 9 applied at `92/95`, SHA256 `BBFE82BEED84C7B7C2DA041589841A549B78E3CBE4E279DBDACCF3F9A75114BC`.
- `by-class/ItemObjImageLib.md`: prose support applied at `92/94`, SHA256 `2ADC66F58CE60C7B54179AC63479588FDF5AC18CA598E1DE099DA093BEE8D432`, preserving the complete class-route/children formal.
- `by-file/ItemObjImageLib.md`: prose-only support applied at `92/94`, SHA256 `51B29C88CC7E8F3DC0696081CA5C3BCA5290BCFA3187BE7A7E3B67F411A5BC2A`; no by-file reconstruction metadata was added.
- `by-memory/0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster.md`: support applied at `90/93`, SHA256 `663D4A1CF8FC387A644550038E5ADF01DD6979469AA3F8D24524FF3DA6EE2117`, preserving NONE/false/blank formal and all children.
- Application startup/shutdown, adjacent singleton slots/globals, UID0003ND, UID0000UQ, UID00041R-UID00041U, ItemInfo, and consumer pages are read-only verification dependencies unless a callback reread proves a direct contradiction.

## Score And Metadata Recommendation

| Destination | Evidence-time | Applied | Owner / reconstructable / emitter / position | Rationale |
| --- | --- | --- | --- | --- |
| UID0001OT | `86/90` | `92/94` | `0000RA / FALSE / blank / blank` | Physical/semantic split, complete refs, direct base, no-code, and ODR closed. |
| UID0000RA | `88/89` | `92/94` | `0000KH / TRUE / 0000KH / 0` | Sole external definition, type/linkage/name/lifetime closed. |
| UID0001UU | `89/92` | `92/94` | `00006W / TRUE / 00006W / 1` | Complete class plus direct Singleton/extern/PMD/EBO closure. |
| UID0002SD | `87/90` | `92/94` | `00006W / TRUE / 00006W / 10` | Complete source body and exact compiler publication disposition. |
| UID00017O | `86/92` | `92/94` | `00006W / TRUE / 00006W / 30` | Exact empty human destructor and implicit cleanup proof. |
| UID00017Y | `87/93` | `93/96` | `00006W / FALSE / blank / blank` | Exact EH-only Singleton base destructor identity and rename. |
| UID0002VC | `87/92` | `93/96` | `00006W / FALSE / blank / blank` | Exact compiler scalar wrapper and no-code closure. |
| UID0001XW | `85/91` | `92/95` | `00006W / FALSE / blank / blank` | Exact generated vtable/type disposition. |
| UID0002ML | `86/91` | `92/95` | `00006W / FALSE / blank / blank` | Exact raw RTTI/vtable generated-data disposition. |
| UID00006W | `88/89` | `92/94` | `0000KH / TRUE / 0000KH / blank` | Complete semantic class/lifetime/source/compiler union. |
| UID0000KH | `90/88` | `92/94` | `FILE` | Exact header/source one-definition and full class lifecycle. |
| UID00017N | `86/90` | `90/93` | `NONE / FALSE / blank / blank` | Exact non-emitting split index with corrected lifetime taxonomy. |

- Completion does not exceed 93 because several pages document compiler output rather than independent authored source and four unrelated draw children still have their own no-code blockers.
- Confidence is capped at 94-96 because the binary lacks original source/PDB names for the header, generic template member, and exact global spelling.
- No score is raised merely because an older report exists. Each change follows current MCP and current ordinary-document reconciliation.

## Open Questions With Attempted Resolution

- Is UID0001OT itself a source variable? Resolved no: it is the physical address realization of UID0000RA and cannot emit separately without duplication.
- Is `0x004dec82` a handwritten fallback clear? Resolved no: decompilation's `a1 == -4` derives from null-adjusted recovery of the complete object from the direct base receiver.
- Is UID00017Y a handwritten clear function? Resolved no: unique constructor EH jump, direct base adjustment, RTTI identity, no callers/pointers, and ordinary/scalar copies prove a compiler-emitted Singleton base destructor.
- Does the ordinary destructor need explicit cleanup source? Resolved no: member, Singleton, and LObject implicit destruction explain every instruction in exact reverse source order. Empty source is complete.
- Should the original variable be emitted as a template static specialization instead? The exact template-member spelling is unrecovered. One binary slot and current project convention support one accepted external global definition; adding a second specialization is behaviorally invalid. This lexical uncertainty only caps confidence.
- Where does the external declaration belong? Resolved to the complete class/header block because it is source-safe, visible to consumers, and does not duplicate storage. The by-global block remains the one source definition.
- Are aliases separate variables? Resolved no: every alias maps to the same address and no second storage exists.
- Are consumer pages owners? Resolved no: they only read the already-published singleton.
- Any issue still requiring research before callback? No. Exact original header/template spelling is irrecoverable lexical detail with no score/C++ blocker effect beyond the stated confidence cap.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Final callback read-only comparison used current hashes: by-memory `3A973DF5CDA032AA04EB3A1B3C18F207A5A475CA9E0A92A2575E5F1070A0F65E` (`1,864,341` bytes, `4,415` lines), by-global `F5DB17EA8D145825B0B64FDB550180EB2150C14410AADF8D26D338C22BF80EAF` (`90,666` bytes, `213` lines), by-class `7300D965E1A9E2DECDAB0515784DAEF79E970E3360EB3793DC9DD34BF24BEEFC` (`241,643` bytes, `623` lines), by-file `4AA835711FC1DBC8FEE994DB2E7C62293A5779588B49BDAE898C480B0FD6B651` (`138,772` bytes, `316` lines), by-struct `FEB144165B08A72402ED071C1C359C7A9BCE12A93541B84C2721A1D477805AE0` (`57,041` bytes, `137` lines), and by-vtable `A7E941EBE2CF1A061CF7AD9517087949B581565D49400C1E0D13E2FFA0393B70` (`65,083` bytes, `142` lines).
- Current stale-row anchors were reread exactly: by-memory UID00017N/2SD/17O/2VC/17Y/2ML/1OT at lines `1770/1771/1772/1775/1802/3926/4195`; by-global UID0000RA line `100`; by-class UID00006W line `273`; by-file UID0000KH line `134`; by-struct UID0001UU line `62`; by-vtable UID0001XW line `73`.
- The twelve rows below remain stale and require exact supervisor-owned application. C29 is terminal `excluded-with-reason` because B002 is prohibited from editing manual coverage; the complete handoff itself is current, exact, and callback-complete. Supervisor must reread the mutable union immediately before applying and preserve unrelated changes.

1. Replace UID00017N at its current by-memory address-sorted anchor with:

`    - [UID:00017N][0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster](by-memory/0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster.md) 0x004dec30-0x004df500 | non-emitting exact split index | ItemObjImageLib local method cluster : ignored : 90% : very-strong : Exact non-emitting ItemObjImageLib constructor/destructor/draw/glyph split index with complete child ranges and padding, direct LObject plus Singleton<ItemObjImageLib> source hierarchy, compiler publication/unwind/ordinary/scalar/vtable separation, complete ProtectedArray<ItemInfo> and resource/remap evidence, preserved draw options-record no-code proofs, and no aggregate duplicate source.`

2. Replace UID0002SD immediately under UID00017N with:

`        - [UID:0002SD][0x004dec30-0x004dee1b.ItemObjImageLibConstructor](by-memory/0x004dec30-0x004dee1b.ItemObjImageLibConstructor.md) 0x004dec30-0x004dee1b | constructor | ItemObjImageLib::ItemObjImageLib : reconstructable : 92% : very-strong : Exact startup-only source constructor with direct Singleton<ItemObjImageLib> base initialization, compiler-lowered +0x04 EBO publication/unwind clear, complete ProtectedArray<ItemInfo> initialization, ITEM.TBL/ITEM.TBD selection, 20-byte row growth/copy/free, five-field row loading, fallback row, exact boundary/padding, and no duplicate handwritten singleton assignment.`

3. Replace UID00017O immediately after the constructor row with:

`        - [UID:00017O][0x004dee20-0x004dee4d.ItemObjImageLibDestructor](by-memory/0x004dee20-0x004dee4d.ItemObjImageLibDestructor.md) 0x004dee20-0x004dee4d | destructor | ItemObjImageLib::~ItemObjImageLib : reconstructable : 92% : very-strong : Empty authored ordinary destructor whose compiler lowering restores derived/template vptrs, destroys ProtectedArray<ItemInfo> and frees its entries, destroys Singleton<ItemObjImageLib> and clears g_pItemObjImageLib, then tears down LObject; exact raw bytes, range, padding, scalar parity, and no duplicate handwritten cleanup are documented.`

4. Replace UID0002VC at its current by-memory anchor with:

`        - [UID:0002VC][0x004e6580-0x004e65dc.ItemObjImageLibScalarDeletingDestructor](by-memory/0x004e6580-0x004e65dc.ItemObjImageLibScalarDeletingDestructor.md) 0x004e6580-0x004e65dc | compiler scalar deleting destructor | ItemObjImageLib scalar deleting destructor : ignored : 93% : very-strong : Exact vtable-only compiler wrapper around UID00017O's empty source destructor and implicit ProtectedArray/Singleton/LObject teardown, followed by deleting flags, object-size guard, optional storage free, and return-this ABI behavior; false/non-emitting with blank formal C++.`

5. Replace UID00017Y and its old path at the current `0x004e5ba0` anchor with:

`    - [UID:00017Y][0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonBaseDestructor](by-memory/0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonBaseDestructor.md) 0x004e5ba0-0x004e5bab | compiler EH base destructor | Singleton<ItemObjImageLib> base destructor : ignored : 93% : very-strong : Exact eleven-byte constructor-unwind-only Singleton base-destructor instantiation with one funclet jump after +0x04 base adjustment, direct RTTI/PMD/EBO identity, no ordinary callers/callees/pointer route, ordinary/scalar inlined copies, and blank non-emitting formal C++.`

6. Replace UID0002ML at its current read-only-data anchor with:

`        - [UID:0002ML][0x0061b738-0x0061b748.ItemObjImageLibVtableData](by-memory/0x0061b738-0x0061b748.ItemObjImageLibVtableData.md) 0x0061b738-0x0061b748 | compiler RTTI/vtable data | ItemObjImageLib vtable data : ignored : 92% : very-strong : Exact complete-object locator and three-slot vtable with ItemObjImageLib/LObject/Singleton<ItemObjImageLib> hierarchy, constructor/ordinary/scalar vptr stores, adjacent ProtectedArray table boundaries, and blank non-emitting formal because the compiler regenerates all raw data from the class virtual set.`

7. Replace UID0001OT at its current global-storage anchor with:

`    - [UID:0001OT][0x0067a758-0x0067a75c.g_pItemObjImageLib](by-memory/0x0067a758-0x0067a75c.g_pItemObjImageLib.md) 0x0067a758-0x0067a75c | singleton backing storage | g_pItemObjImageLib : ignored : 92% : very-strong : Exact four-byte zero-initialized physical slot with complete 65-reference inventory, five direct Singleton base/compiler lifetime writes, 60 cross-source reads, distinct adjacent singleton boundaries, canonical semantic owner UID0000RA, and one typed external source definition; false/non-emitting with no duplicate C++.`

8. Replace UID0000RA in `by-global/-coverage-report.md` with:

`- [UID:0000RA][g_pItemObjImageLib](by-global/g_pItemObjImageLib.md) : reconstructable : 92% : very-strong : Sole externally linked ItemObjImageLib singleton pointer definition at position 0 in NexusTK/render/ItemObjImageLib.cpp, preceded by a local class forward declaration and matched by one header extern after the complete class declaration. Exact storage UID0001OT has 65 refs, five compiler/direct-Singleton lifetime writes, 60 cross-source reads, one-definition policy, canonical-name/alias evidence, and no physical-page duplicate.`

9. Replace UID00006W in `by-class/-coverage-report.md` with:

`- [UID:00006W][ItemObjImageLib](by-class/ItemObjImageLib.md) : reconstructable : 92% : very-strong : Complete ItemObjImageLib class/source route with direct LObject plus Singleton<ItemObjImageLib> inheritance, PMD +0x04 EBO over ProtectedArray<ItemInfo>, exact constructor and empty ordinary destructor source, compiler-only unwind/scalar/vtable support, sole external g_pItemObjImageLib definition/header declaration policy, full draw/glyph/refresh/member/access union, and preserved child-owned source/no-code decisions.`

10. Replace UID0000KH in `by-file/-coverage-report.md` with:

`- [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md) : reconstructable : 92% : very-strong : NexusTK/render/ItemObjImageLib.cpp owns one position-0 typed g_pItemObjImageLib definition with local forward declaration, while the complete class/header block carries the matching extern and direct LObject plus Singleton<ItemObjImageLib> hierarchy. Exact constructor/empty-destructor source, implicit singleton/member/base lifetime, compiler-only EH/scalar/vtable artifacts, complete 65-ref consumer inventory, layout, resources, draw/glyph/refresh methods, aliases, and one-definition policy are documented without by-file reconstruction metadata.`

11. Replace UID0001UU in `by-type/by-struct/-coverage-report.md` with:

`- [UID:0001UU][ItemObjImageLibLayout](by-type/by-struct/ItemObjImageLibLayout.md) : reconstructable : 92% : very-strong : Complete ItemObjImageLib declaration with direct LObject plus Singleton<ItemObjImageLib> bases, direct-base PMD +0x04 EBO overlapping ProtectedArray<ItemInfo>, exact 0x28 size, complete constructor/destructor/draw/glyph/refresh/member/access union, MapPane friendship, one external g_pItemObjImageLib header declaration, and child-owned definitions/compiler exclusions.`

12. Replace UID0001XW in `by-type/by-vtable/-coverage-report.md` with:

`- [UID:0001XW][ItemObjImageLibVtable](by-type/by-vtable/ItemObjImageLibVtable.md) : ignored : 92% : very-strong : Source-declared/generated-binary ItemObjImageLib vtable/RTTI type support with exact three-slot table, direct ItemObjImageLib/LObject/Singleton<ItemObjImageLib> hierarchy, constructor/ordinary/scalar vptr stores, compiler-only raw data, semantic class owner UID00006W, and blank non-emitting formal C++.`

- Generated tracker text is validator-owned and must not be edited manually. After callback validation, supervisor should verify its rows reflect ordinary metadata.

## Follow-Up Actions

- Supervisor accepted exact pre-callback SHA `1206FEFA4A57BA79CD5FF60BF6EC58574F96FE9E602D8BA3DFCC7499747BD9F8`; B002's accepted implementation, scoped validators, rename, final waited refresh, readback, report reconciliation, and lease releases are complete.
- Generated assertions passed: one complete class with direct Singleton base; one external declaration; one global definition; one constructor with Singleton initializer and zero explicit assignments; one empty ordinary destructor; zero UID0001OT/UID00017Y/UID0002VC/UID0001XW/UID0002ML markers or bodies; no duplicate global; no handwritten scalar/vtable/RTTI source; exactly four unrelated draw markers preserved.
- Supervisor-owned handoff: the twelve exact manual coverage replacements remain available above against the final-read union. Their application and validation are external to B002 and are not falsely claimed here.
- Lifecycle: B002 never runs report execution/move/archive commands. Current/future path, validation, execution, move, and archive state are external validator/supervisor-owned facts.
- No additional B-agent research or duplicate report is recommended for this target.

## Confidence

- Recommendation confidence: `98%` for physical/semantic split and one-definition policy.
- Source-shape confidence: `98%` for direct Singleton base, PMD/EBO, constructor publication, empty ordinary destructor, EH/scalar/vtable compiler dispositions.
- Name/linkage confidence: `94%` for `g_pItemObjImageLib` and exact header/source spelling.
- Score confidence: `96%` for the destination matrix.
- Remaining uncertainty: original header filename, generic Singleton template implementation spelling, and exact PDB global alias. None changes behavior, ownership, emission, or destination-ready C++.

## Validator Results

- Every ordinary validator exited `0` with `ok:1`; generated refresh was deferred on commands `000000015433` through `000000015455` and completed only on final command `000000015456`.

| Command | Timestamp | Destination/result | Warnings and side effects |
| --- | --- | --- | --- |
| `000000015433` | `2026-07-20T16:33:38-04:00` | UID0001OT applied, exit 0/ok 1 | Metadata/registry/stats updates; generated deferred. |
| `000000015434` | `2026-07-20T16:34:32-04:00` | UID0000RA applied, exit 0/ok 1 | Position/formal/score registry and stats updates; generated deferred. |
| `000000015435` | `2026-07-20T16:35:31-04:00` | UID0001UU applied, exit 0/ok 1 | Formal/score/reference-index and stats updates; generated deferred. |
| `000000015438` | `2026-07-20T16:37:18-04:00` | UID0002SD applied, exit 0/ok 1 | Owner/emitter/position/formal and stats updates; generated deferred. |
| `000000015439` | `2026-07-20T16:38:13-04:00` | UID00017O applied, exit 0/ok 1 | Owner/emitter/position/formal, one link-label normalization, and stats updates; generated deferred. |
| `000000015443` | `2026-07-20T16:41:08-04:00` | UID00017Y UID-preserving rename/Destination 6, exit 0/ok 1 | Path update old -> new, seven reference-source path updates, 25 UID-link updates with 15 suppressed, registry/score updates; 267 pre-existing missing-reference warnings; generated deferred. |
| `000000015448` | `2026-07-20T16:43:27-04:00` | UID0002VC applied, exit 0/ok 1 | Four registry changes plus score/stats updates; generated deferred. |
| `000000015449` | `2026-07-20T16:44:14-04:00` | UID0001XW applied, exit 0/ok 1 | Four registry changes, score/stats row removal/rescore notice; generated deferred. |
| `000000015450` | `2026-07-20T16:44:59-04:00` | UID0002ML applied, exit 0/ok 1 | Class-owner, four registry, score/stats updates; generated deferred. |
| `000000015453` | `2026-07-20T16:46:32-04:00` | UID00006W applied, exit 0/ok 1 | Score/stats updates; four pre-existing UID0003LZ missing-reference warnings; generated deferred. |
| `000000015454` | `2026-07-20T16:47:50-04:00` | UID0000KH applied, exit 0/ok 1 | Score/stats updates; six pre-existing UID0003LZ/UID0003ZN missing-reference warnings; generated deferred. |
| `000000015455` | `2026-07-20T16:49:03-04:00` | UID00017N applied, exit 0/ok 1 | Score/stats updates; six pre-existing UID0003LZ/UID0003ZN missing-reference warnings; generated deferred. |
| `000000015456` | `2026-07-20T16:49:16-04:00` | final UID0000KH `--wait-generated`, exit 0/ok 1 | Registry rebuild and generated metadata refresh completed; six current file missing-reference warnings plus unrelated project-wide marker/emitter notices; no target failure. |

- Final generated readback: `auto-generated/NexusTK/render/ItemObjImageLib.cpp` SHA256 `9D79F134AB74CBE86EFE6925166D9F03F1DB5E6A38EBE815AEE4B7A9F4D0D719`, `6,435` bytes, `169` lines, command `000000015456`. All exact structural/count assertions passed as recorded under Current Target State.
- Managed-block equality: all nine report blocks are byte-equal after newline normalization to the exact destination prefixes. Block SHA256 values are UID0001OT `DBAEDA4A9C758A5410BCD90304E576A6508BFD9D1375797B39E3E7C5716EEF20`, UID0000RA `CC5039FD8835195334B637E6F32998CCDA14E77A458E9278DB348C6B5702821C`, UID0001UU `E41F16C542D00279262202B24D76F42FF6494635DCAAAA3D6BE31032AE09542E`, UID0002SD `F4BE374988A1517C91BC175A8DFFEC677FC0D74641E444BA2524265549D93B0B`, UID00017O `BA6889FBF73C6F69953E8A552170CB7AB779B4EF57281C4120B094C25E3645C6`, UID00017Y `88724481AD3CC145800C2659D0CFDE018AD689245E0C037C8DAA4F425761471F`, UID0002VC `1172A95D175E9FC85BCF555D108D36D78FCB50861EDCCDB214A8622CC85B5A91`, UID0001XW `5466C8D56E4FE4F5E8F087AEADE1B136D1270659EA266163B0086D657B086267`, and UID0002ML `6A80DAF7135466027E9283B9386A2BCF357243862AE50339ACA711A8F13FDACC`.
- Callback-time tracker proof from command `000000015456` was SHA256 `19625F36DED092FF386B2DE22B37A2BB6F811080B17BDAD2CF789834BBB6E19E`, `1,532,009` bytes, `6,206` lines. Final read-only shared tracker checkpoint is external deferred command `000000015457`, timestamp `2026-07-20T16:59:27-04:00`, SHA256 `A407593D1D037B33157874C9A5A3B3C0060F9A6BEB959FCA970D68944E3A20BB`, `1,532,253` bytes, `6,207` lines; all affected rows still show final scores and false/true dispositions. B002 did not edit the tracker.
- Historical generated command `000000015419` and its pre-callback hashes remain evidence only. MCP session `9b0396a3` was healthy at evidence collection; no IDA mutation occurred.
- Lifecycle/report execution commands: none run or probed by B002.

## Changed Files

- Same report updated in place: `tools/leaser/Agents/Agent-B002/research/0001OT-g_pItemObjImageLib-source-quality.md`.
- Modified ordinary docs and final SHA256 values:
  - `by-memory/0x0067a758-0x0067a75c.g_pItemObjImageLib.md` -> `6626BE385AA89F4BFC1C21A21BDCFF29936943F66C443F20440D60B6AAE7C0F0`.
  - `by-global/g_pItemObjImageLib.md` -> `DA3F4792A86448158AD035A2A2B344DE1EE8F59725EAA215947C120F66D5D7DD`.
  - `by-type/by-struct/ItemObjImageLibLayout.md` -> `53691404E9E41257E62956B7E82DC59F987E31BAFD2C1A7ABE8A3F84C7BB40A2`.
  - `by-memory/0x004dec30-0x004dee1b.ItemObjImageLibConstructor.md` -> `27A5DB73AD7D77F921828DAAFAF3247567895AC2BA22D07C37B6C9BDDE41008E`.
  - `by-memory/0x004dee20-0x004dee4d.ItemObjImageLibDestructor.md` -> `9AB1FB6821E8401390F633AA69A0861E41F5721094ED60CFBE570F39FB4B882C`.
  - `by-memory/0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonBaseDestructor.md` -> `B04CBC57947E403DDB8A06E9F9653A53AB18C094F652576D8F39447B9C460AF0` (UID-preserving rename; old path absent).
  - `by-memory/0x004e6580-0x004e65dc.ItemObjImageLibScalarDeletingDestructor.md` -> `A4EA1ECB117A02E2D064574D0D4390E1091B74615015F99EDF1ACD9C0C48D210`.
  - `by-type/by-vtable/ItemObjImageLibVtable.md` -> `DACC8B94E12DD6FE8FB43B49C7DFA0733E5F59E50F20D5D3AF9F8CDB050E01E4`.
  - `by-memory/0x0061b738-0x0061b748.ItemObjImageLibVtableData.md` -> `BBFE82BEED84C7B7C2DA041589841A549B78E3CBE4E279DBDACCF3F9A75114BC`.
  - `by-class/ItemObjImageLib.md` -> `2ADC66F58CE60C7B54179AC63479588FDF5AC18CA598E1DE099DA093BEE8D432`.
  - `by-file/ItemObjImageLib.md` -> `51B29C88CC7E8F3DC0696081CA5C3BCA5290BCFA3187BE7A7E3B67F411A5BC2A`.
  - `by-memory/0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster.md` -> `663D4A1CF8FC387A644550038E5ADF01DD6979469AA3F8D24524FF3DA6EE2117`.
- Modified manual coverage/generated/tracker/audit/supervisor/validator/IDA files: none.
- Validator-managed generated/tracker/registry/stat side effects are recorded above and were not manually edited by B002.
- Renamed: UID00017Y old `...SingletonClearHelper.md` to current `...SingletonBaseDestructor.md`, preserving UID through command `000000015443`.
- Leases: one ordinary destination at a time; every lease released immediately after its scoped validator; final lease ledger shows zero B002 and zero total leases.
- Report execution/lifecycle: B002 did not run or probe any command. Lifecycle state is external and authoritative only from the current path and validator-owned history.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor Gate 1 passed exact pre-callback SHA `1206FEFA4A57BA79CD5FF60BF6EC58574F96FE9E602D8BA3DFCC7499747BD9F8` before implementation.
- [x] Confirmed ledger actions use only `incorporate`, `already-present`, `historicalize`, `reject-stale`, `reject-invalid`, or `not-applicable`.
- [x] Confirmed all C01-C30 report-only verification states were exactly `proposed` before callback and are now legal terminal states.
- [x] Reread target immediately before callback and preserved unrelated detail.
- [x] Applied Destination 1 metadata, blank formal, summary, and full storage evidence to UID0001OT.
- [x] Retained UID0001OT semantic owner UID0000RA while clearing reconstructable/emitter/position.
- [x] Applied Destination 2 to UID0000RA with score, position 0, forward declaration, and sole definition.
- [x] Applied Destination 3 to UID0001UU without losing any current declarations, access, fields, or friendship.
- [x] Added direct Singleton base and external global declaration only once.
- [x] Applied Destination 4 to UID0002SD with class owner/emitter and position 10.
- [x] Preserved the accepted constructor body byte-for-byte except the explicit singleton assignment.
- [x] Applied Destination 5 to UID00017O with class owner/emitter, position 30, and exact empty body.
- [x] Preserved exact destructor bytes/range/padding and historical no-code assumption as superseded.
- [x] UID-preserving renamed UID00017Y through validator-managed path correction.
- [x] Applied Destination 6 false/non-emitting metadata and blank formal to renamed UID00017Y.
- [x] Applied Destination 7 false/non-emitting metadata and blank formal to UID0002VC.
- [x] Applied Destination 8 false/non-emitting metadata and blank formal to UID0001XW.
- [x] Applied Destination 9 false/non-emitting metadata and blank formal to UID0002ML.
- [x] Updated UID00006W class prose/score with direct Singleton, one-definition, and compiler split without changing its complete child union.
- [x] Updated UID0000KH file prose/score only; no by-file reconstruction metadata was added.
- [x] Updated UID00017N score/prose only; preserved NONE/false/blank and complete child/padding union.
- [x] Preserved UID0003ND, UID0000UQ, UID00041R-UID00041U, ItemInfo, Application, adjacent globals, and consumers; no concrete drift required edits.
- [x] Preserved all 65 refs and the exact five-write/60-read count proof at report-level detail.
- [x] Preserved RTTI/PMD/EBO, exact bytes/hashes, lifetime order, negative evidence, rejected alternatives, and alias history.
- [x] Confirmed no third-party import directive applies.
- [x] Confirmed no new child/report/UID was created.
- [x] Confirmed no duplicate global definition or template static definition is emitted.
- [x] Applied exact scores/owners/emitters/positions/Nested values from the matrix.
- [x] Reread current B001-B005 goals/reports and lease ledger before final current-state claims.
- [x] Reread all twelve ordinary destinations after leasing and before editing.
- [x] Leased only one ordinary file immediately around its edit/validation.
- [x] Released each ordinary lease immediately after its scoped validator.
- [x] Recorded every validator command ID, timestamp, exit, ok count, warnings, and side effects.
- [x] Ran one final authorized `--wait-generated` ItemObjImageLib refresh after all ordinary leases cleared.
- [x] Verified one complete ItemObjImageLib class with direct Singleton base.
- [x] Verified exactly one external declaration and one global definition.
- [x] Verified one constructor with Singleton initializer and zero explicit global assignment.
- [x] Verified one empty ordinary destructor and no duplicate destructor.
- [x] Verified zero UID0001OT marker/source occurrence.
- [x] Verified zero UID00017Y, UID0002VC, UID0001XW, and UID0002ML source/marker pollution.
- [x] Verified no handwritten scalar flags, delete/size guards, RTTI arrays, or vtable dwords.
- [x] Verified unrelated draw child markers and all current class/file union content are preserved.
- [x] Rechecked tracker rows after generated refresh without editing tracker manually.
- [x] Rechecked all six manual coverage files and preserved later unrelated rows.
- [x] Preserved the twelve exact manual coverage replacements as a supervisor-owned handoff; B002 did not edit coverage.
- [x] Terminalized C01-C30 only from ordinary/validator/generated proof using legal callback states.
- [x] Checked callback rows only where exact destination proof exists; C29 is explicitly excluded with reason.
- [x] Recorded final ordinary/generated hashes and zero lease count.
- [x] Confirmed zero prohibited manual generated/coverage/tracker/audit/supervisor/validator-state/IDA/lifecycle edits.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support facts incorporated without compression.
- [x] All nine managed blocks byte-equal at their exact destinations.
- [x] UID00017Y real renamed path/UID/link propagation verified.
- [x] All C01-C30 claims terminal with legal verification states and separate proof.
- [x] All ordinary scoped validators passed and all leases released.
- [x] Final waited generated assertions passed on independently reread output.
- [x] Exact manual supervisor-owned coverage handoff rebased without editing coverage.
- [x] Remaining unapplied accepted items are zero; C29 is the exact evidence-backed external-write exclusion.
- [x] Same report reconciled to callback-complete archive-neutral truth for Gate 2.

READY_FOR_SUPERVISOR_GATE2_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000015472","destination_path":"executed-b-agent-research/B002/0001OT-g_pItemObjImageLib-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0001OT-g_pItemObjImageLib-source-quality.md","timestamp":"2026-07-20T17:10:10-04:00","uid":"0001OT"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
