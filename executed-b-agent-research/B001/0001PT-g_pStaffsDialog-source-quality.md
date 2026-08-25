** TARGET-REPORT-UID:0001PT **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0001PT g_pStaffsDialog Ownership / One-Definition Research

## Finalized Report / Current Recommendation

- Current applied target: [UID:0001PT] `by-memory/0x0069b490-0x0069b494.g_pStaffsDialog.md` is exact physical evidence at `92/94`, owned by semantic global UID0000SC, `RECONSTRUCTABLE:FALSE`, blank emitter/position/formal C++, and retained `Nested:-4`.
- Applied source disposition: UID0000SC owns the sole external definition `StaffsDialogPane *g_pStaffsDialog = NULL;` in UID0000O3 `NexusTK/login/StaffsDialogPane.cpp`. The physical slot is PE loader-zeroed storage and emits no second definition.
- Applied source closure: `StaffsDialogPane` is `DialogPane` plus direct empty `Singleton<StaffsDialogPane>` base; authored publish/clear statements and an explicit destructor are absent; the inherited `OnControlCommand(int,int)` slot is used; the `STAFF.EPF` resource-name pointer emits once as a file-local definition.
- Applied compiler/data closure: the Singleton base destructor, two adjustor thunks, scalar deleting wrapper, physical resource pointer, vtables, RTTI, and broad read-only-data index are fully documented non-emitting evidence.
- Applied split/registration: validator command `000000016007` issued UID0004VJ to exact physical child `by-memory/0x0061d930-0x0061d9cc.StaffsDialogPaneVtableData.md`; command `000000016010` then issued UID0004VK to semantic page `by-type/by-vtable/StaffsDialogPaneVtables.md`. D9 retains `Nested:0`, physical containment under UID00025Q, and semantic `CANONICAL_OWNER:0000DY`; no provisional UID token remains.
- Confidence: very strong for bytes, PE mapping, four-write lifetime, class identity, direct Singleton EBO, vtable/RTTI layout, compiler/source split, resource pointer, and one-definition route; high for descriptive source spellings and retained-source classification because no original symbols or direct constructor route survive.
- Current report state: the accepted implementation callback is complete at the canonical research path. B001 performed the ordinary edits, short leases, scoped validators, and final waited generated refresh enumerated below; B001 performed no manual coverage/generated/tracker edit, IDA mutation, report execution, move, archive, or lifecycle action. Current report path/count/execution/archive state remains external supervisor/validator-owned state.

## Supporting Research

- Mandatory live IDA evidence used active NexusTK database `9b0396a3`. Fresh `idb_list` returned one active worker, PID 15732, `is_analyzing:false`; `server_health` returned `status:ok`, imagebase `0x00400000`, auto-analysis ready, Hex-Rays ready, and strings ready.
- A fresh valid bounded `get_bytes` read at `0x0069b490` returned `00 00 00 00`; a fresh valid bounded `xrefs_to` returned exactly four data references and `more:false`.
- Current executable: `C:/Users/admin/Desktop/Clone/NexusTK/NexusTK.exe`, SHA256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`, 2,679,296 bytes.
- Historical search terms included `UID0001PT`, `0001PT`, `0x0069b490`, `69B490`, `g_pStaffsDialog`, `dword_69B490`, `StaffsDialogPane`, `Singleton<StaffsDialogPane>`, `STAFF.EPF`, `STAFFS2`, `OnDialogAction`, and `OnControlCommand`.
- Active roots checked: `tools/leaser/Agents/Agent-B001/research/**` through `Agent-B015/research/**`. No direct UID0001PT report existed; matches were adjacent/shared support only.
- Central executed root checked: `executed-b-agent-research/**`.
  - Direct core lead opened: `executed-b-agent-research/B014/00019Z-StaffsDialogPaneCore-source-quality.md`, SHA256 `87830DB703EA1B5942746A7FF24D43F7F8BC174F7CADB32018DF339B1A36DD7B`. Current evidence preserves its resource/control behavior but supersedes explicit singleton publication, free event helper, vague layer name, and `OnDialogAction`.
  - Direct destructor lead opened: `executed-b-agent-research/B005/0001AH-0001AJ-NewHistoryStaffsDialogPaneDestructorPair-source-quality.md`, SHA256 `2B4E09FFAF2E2F7766A47F5E38F83F728BB3A3F8152AA9ED994607B0BA59D846`. Current RTTI/EBO evidence supersedes its authored destructor-clear conclusion.
  - Main UI lead opened: `executed-b-agent-research/B002/0002AF-g_pMainUiGraph-source-quality.md`, SHA256 `87CCCE75D2F8158D9DF8591DEB474325AED63888DB3CBC8AE67AE41AD5988ABF`. Current ordinary docs independently support `g_mainUiLayerSlots.overlayPaneLayerContext` and `g_pMainMenuPane`.
  - Adjacent reports opened/classified as incidental: B010 UID00019J close-dialog singleton support, B001 UID0001A1 HistoryViewingPane, and B003 UID0001AI ScrolledPictureControlPane. They establish neighboring ranges or compiler patterns, not target ownership.
- `tools/leaser/Agents/Older-Research/**` was searched for the UID, address, global/class/resource names, and source-family terms; no direct or incidental match was found.
- `tools/leaser/Agents/SpecialReports/**` was searched with the same terms; no direct or incidental match was found.
- Explicit historical conclusion: there is no prior direct UID0001PT report. Executed B014/B005/B002 artifacts are evidence-time leads only; live bytes, xrefs, current docs, and current source routing are authority.
- Historical Wave2/Wave3 material was not used as authority.

## Target

- Target UID: `0001PT`.
- Target path: `by-memory/0x0069b490-0x0069b494.g_pStaffsDialog.md`.
- Source queue: current validator-owned research tracker, `## by-memory` -> `### Not-Covered Files - Reconstructable`.
- Current metadata: `92/94`, owner UID0000SC, reconstructable false, blank emitter/position/formal C++, `Nested:-4`.
- Current ordinary hash after callback: `934B46686FB6E8D0311A23517DC1729B46A9C7294DA2BDC47DB780BDCD9AF0B0`, 9,154 bytes / 84 lines. Pre-callback SHA256 `D5AB8D1B003D75B00D3F571CA3DA2FB3B01BD0ED9BA15EB50D70C3A3D218AB33` is historical evidence-time provenance.
- Exact target bytes SHA256: `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`.

## Current Target State

- The target page now identifies the four-byte Staffs dialog singleton slot, its four reference sites, PE loader-zeroing, and the final physical/compiler disposition without a stale source conclusion.
- The current slot bytes are `00 00 00 00`. PE arithmetic proves the slot is not raw-file-backed; the loader supplies zero because the address lies inside virtual `.data` beyond `SizeOfRawData`.
- The constructor's publish/null-fallback sequence is the compiler lowering of direct `Singleton<StaffsDialogPane>` base construction at complete-object offset `+0x26c`.
- The clear at `0x00502410` is the exact compiler-emitted Singleton base destructor used by constructor EH cleanup.
- The clear at `0x00502cc6` is inside the scalar deleting wrapper and is the implicit Singleton base teardown, not evidence for an authored StaffsDialogPane destructor statement.
- Current ordinary docs emit only the accepted source causes. B001 waited command `000000016069` first produced the accepted body; external command `000000016091` later changed only its validator header. After the final bounded D11-D13 current-state corrections, B001's final waited command `000000016100` at `2026-07-21T17:15:43-04:00` is the current `auto-generated/NexusTK/login/StaffsDialogPane.cpp` authority: SHA256 `31A80B2C5875DC31ABF1BA1255018BE99DE8EDE0881164F3A1BF703F9E530E1B`, 2,626 bytes / 79 lines. Readback proves the accepted source body, order, and counts remain identical across commands 16069, 16091, and 16100; only validator header freshness changed.
- Current generated output has one UID0000SC/global definition, one UID0002ZI/resource-pointer definition, one UID0000DY/class declaration, and one UID00019Z constructor/`OnControlCommand` body in source order. It has zero UID0001PT/UID0001A9/UID0001AE/UID0001AJ markers, explicit Staffs destructor, authored singleton publish/clear beyond the sole `NULL` definition, stale action/event/layer tokens, Empty Emitter Markers, raw vtable/RTTI, or duplicate source bodies.
- Commands 15981, 15993, and 15999 and their recorded hashes are historical pre-callback generated evidence. Command 15999's old source body contained the explicit publish/destructor defects that this callback removed.
- B001 changed the fifteen ordinary D1-D15 destinations listed below. D16's two verify-only MainMenuPane destinations were reread and remained unchanged.

## Executive Recommendation

- Route physical UID0001PT to semantic UID0000SC and make only UID0000SC emit the typed external definition.
- Complete UID0000DY as a fieldless direct `DialogPane, Singleton<StaffsDialogPane>` class of size `0x26c`, with constructor and protected virtual `OnControlCommand(int,int)`; do not declare an explicit destructor.
- Correct UID00019Z to authored constructor/action source while excluding Singleton publication, vptr writes, EH, scalar-delete, and raw event/layer aliases.
- Reclassify UID0001A9, UID0001AE, and UID0001AJ as class-owned compiler output with blank C++; apply validator-aware UID-preserving path/title corrections to UID0001A9 and UID0001AJ.
- Split exact Staffs vtable/RTTI data from UID00025Q into new physical and semantic non-emitting pages while preserving the mixed aggregate. D9 is a physical child of UID00025Q with `Nested:0`, but its semantic canonical owner is class UID0000DY; containment does not transfer source ownership to the aggregate.
- Emit `kStaffsDialogEpfName` once from UID0002ZI and make physical UID00027M non-emitting.
- Preserve UID0001RM at `87/92`: payload provenance remains open, but that resource packaging issue does not block the source declaration or constructor.

## Supervisor Active Recheck

- The supervisor assigned UID0001PT to resolve physical/semantic ownership, loader state, class source shape, Singleton lifetime, destructor/compiler boundary, vtable/RTTI layout, generated one-definition behavior, and score blockers.
- The target slot itself does not split. Two exact support pages are required for the independently bounded Staffs vtable cluster.
- Every source-bearing item in scope has destination-ready C++ below. Every compiler/data-only item has an exact blank managed block and evidence-backed no-code disposition.
- No investigable issue remains deferred. Original lexical spelling and absent constructor entry route are explicit confidence caps, not implementation blockers.

## Inference Research Guidance Check

- Direct IDA fact: target bytes, xrefs, functions, instructions, vtable cells, RTTI descriptors/PMDs, literal/pointer references, and absence of constructor routes.
- Direct PE fact: section RVAs, virtual/raw sizes, target delta, raw scan results, and loader-zero consequence.
- Documentation fact: current UIDs, parent routes, DialogPane virtual signature, EventMan modifier API, MainUiLayerSlots field, source path, resource provenance, and generated output.
- Inference: descriptive source spellings `g_pStaffsDialog`, `kStaffsDialogEpfName`, `controlId`, and retained-source classification. None is presented as recovered PDB text.
- Existing docs and old reports were treated as potentially stale. Their exact behavior was retained only where current evidence independently confirmed it.
- Wave2/Wave3 artifacts were ignored as stale/non-authoritative.

## Heuristic / Inference Reanalysis And Validation

- Zero versus `0xffffffff`: live bytes and PE mapping prove zero. The old `ff ff ff ff` observation cannot describe this executable slot because no raw bytes map to it.
- Physical versus semantic definition: the four-byte page is physical evidence. The by-global page is the semantic source definition. Emitting both would violate one-definition behavior.
- Linkage: the pointer is externally named and shared as a project global; use external definition in StaffsDialogPane.cpp, not file-local `static`, a class static member, or an authored Singleton member.
- Constructor publication: the compiler first constructs the direct Singleton base at `this+0x26c`; the adjusted-null sequence proves template-base lowering. It must not survive as handwritten assignment.
- Destructor source cause: the generated base destructor and scalar wrapper clear the slot. No unique Staffs-authored cleanup remains, so the strongest source shape omits an explicit destructor entirely.
- Class layout: `DialogPane` supplies size `0x26c`; the direct empty Singleton base has PMD `{0x26c,-1,0}` and adds no authored field. No reserved/padding member is needed.
- Action identity: primary vtable offset `+0x48` is DialogPane's established `OnControlCommand(int controlIndex, int notifyCode)`, not a separate `OnDialogAction` API.
- Event-state helper: `0x004a90b0` reads one byte from EventMan and writes it through an output pointer. Current EventMan docs name this API `GetModifierState(unsigned char *)`. The old free helper and named flag constant have no declaration evidence.
- Flag source shape: preserve exact literal bit `0x02`; do not invent a stronger enum or constant.
- Layer operand: `0x0069b36c` is current accepted `g_mainUiLayerSlots.overlayPaneLayerContext`; `0x0067aba4` remains `g_pMainMenuPane`.
- Resource pointer: `0x0066db44` is raw-backed mutable pointer storage targeting const UTF-16. The source declaration is a file-local mutable pointer-to-const string, not an array and not a duplicate physical definition.
- Constructor liveness: no direct pointer, RVA, rel32 call/jump, startup/factory/menu-command, or ordinary xref reaches `0x004ffaa0`. Vtables/resources and complete source body prove class/source identity. Retained linked source with absent runtime entry is more defensible than inventing a caller or calling the code compiler-only.
- Vtables/RTTI: three views and eight-entry hierarchy are compiler products of the declaration. They must be documented, not emitted as arrays.
- Rejected alternatives: in-game GM/staff manager ownership, MainMenuPane-owned global, class-static pointer, file-static singleton pointer, explicit ordinary destructor clear, authored EH helper, authored adjustor thunks, authored scalar wrapper, hand-written vtables/RTTI, generic free event helper, invented event enum, vague `g_mainUiLayer`, and duplicate resource pointer definition.

## Evidence Standards Used

- Highest weight: current executable bytes, valid bounded live MCP results, PE arithmetic, disassembly, decompilation, xrefs, RTTI records, vtable slots, constructor stores, and exact range hashes.
- Supporting weight: current ordinary by-* docs, source-tree routes, generated output, manual coverage rows, and independently revalidated historical reports.
- Negative evidence was bounded and reproducible: zero reads, zero additional xrefs, zero constructor absolute/RVA/rel32 routes, no additional writer/clear path, and no target report in all required historical roots.
- Binary behavior and layout are direct facts. Source spellings without symbols are descriptive inferences and cap confidence without blocking source-ready C++.

## Evidence Checked

- MCP transport: fresh initialize, `idb_list`, `server_health`, valid `get_bytes`, `xrefs_to`, `lookup_funcs`, decompile, disassembly, global listing, string/literal, RTTI, and bounded vtable queries on database `9b0396a3`.
- Exact target read: `0x0069b490`, four zero bytes, exact hash above.
- Functions checked: `0x004ffaa0`, `0x004ffd20`, `0x00502410`, `0x00502592`, `0x0050259d`, `0x00502cc0`, and helper `0x004a90b0`.
- Data checked: target slot, `0x0066db44` resource pointer, `STAFF.EPF`, `STAFFS2`, `STAFFS`, vtable cluster `0x0061d930-0x0061d9cc`, RTTI cluster `0x0064a7f0-0x0064a8cc`, and adjacent class boundaries.
- PE/raw checks: section table, raw mapping, target absolute/RVA occurrence scan, constructor VA/RVA scan, and direct E8/E9 route scan.
- Ordinary docs checked: D1-D16 listed below, DialogPane, EventMan, MainUiLayerSlots, MixItemDialog comparator, and neighboring ScrolledPicture/History vtable ranges.
- Generated file was checked read-only at commands 15981 and 15993 during research and rebased to final-repair evidence-time command 15999 before return.
- Manual coverage checked read-only for by-memory, by-global, by-class, by-file, by-resource, and by-type/by-vtable.
- Historical roots checked: active agent research, central executed reports, Older-Research, and SpecialReports.
- One MCP client-shape attempt used obsolete singular `address/size` and returned missing `regions/addrs`; `tools/list` supplied the exact schema and valid bounded calls then succeeded. This was a client request-shape limitation, not MCP unavailability.
- During the initial report-only evidence pass ordinary edits, ordinary leases, validators, generated refreshes, coverage edits, IDA mutation, execute, lifecycle, move, and archive actions were intentionally not performed. During the accepted implementation callback B001 performed the ordinary edits, short leases, scoped validators, and final waited generated refresh enumerated later; manual coverage edits, IDA mutation, execute, lifecycle, move, and archive actions remained unperformed by B001.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C1PT-001 | Target range is exactly `[0x0069b490,0x0069b494)`. | very high | MCP bytes; adjacent globals | D1 | incorporate | applied |
| C1PT-002 | Exact target bytes are `00 00 00 00`, SHA256 `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`. | very high | valid `get_bytes` | D1 | incorporate | applied |
| C1PT-003 | Target RVA is `0x0029b490` and lies in virtual `.data`. | very high | PE arithmetic | D1 | incorporate | applied |
| C1PT-004 | Target has no raw backing and is PE loader-zeroed. | very high | `.data` delta/raw size | D1/D2 | incorporate | applied |
| C1PT-005 | Historical `ff ff ff ff` is disproved and must be historicalized. | very high | C1PT-002/004 | D1/D2 | reject-stale | applied |
| C1PT-006 | Exact neighbors are UID0002XM ending at `0x0069b490` and UID0001PU starting at `0x0069b494`. | very high | current exact pages | D1 | incorporate | applied |
| C1PT-007 | Exactly four target xrefs exist and `more:false`. | very high | live `xrefs_to` | D1/D2 | incorporate | applied |
| C1PT-008 | `0x004ffaf6` is constructor Singleton publication. | very high | disasm/decompile | D1/D2/D5 | incorporate | applied |
| C1PT-009 | `0x004ffafd` is constructor adjusted-null fallback. | very high | disasm/decompile | D1/D2/D5 | incorporate | applied |
| C1PT-010 | `0x00502410` is constructor-EH Singleton base clear. | very high | body/xref/RTTI | D1/D2/D6 | incorporate | applied |
| C1PT-011 | `0x00502cc6` is scalar-wrapper Singleton base clear. | very high | body/vtable/RTTI | D1/D2/D8 | incorporate | applied |
| C1PT-012 | No read or additional lifetime route exists. | very high | exhaustive four-xref set | D1/D2 | incorporate | applied |
| C1PT-013 | Exact source type is `StaffsDialogPane *`. | very high | constructor/vtables/RTTI | D1/D2/D3 | incorporate | applied |
| C1PT-014 | `g_pStaffsDialog` is the strongest project source-facing name. | high | current docs/peer globals | D1/D2/D3 | incorporate | applied |
| C1PT-015 | UID0001PT is physical evidence and becomes false/non-emitting with blank C++. | very high | one-definition analysis | D1 | incorporate | applied |
| C1PT-016 | UID0000SC owns the sole typed definition. | very high | semantic route | D2 | incorporate | applied |
| C1PT-017 | The pointer definition has external, not file-local or member, linkage. | high | shared-global convention/route | D2/D3/D4 | incorporate | applied |
| C1PT-018 | Source initializer is `NULL`, preserving project-era style and loader-zero value. | high | peer source/style/bytes | D2 | incorporate | applied |
| C1PT-019 | UID0000O3 is the source file owner. | very high | class/resource/method family | D2-D5/D12 | incorporate | applied |
| C1PT-020 | Emitter order is global 0, resource pointer 5, class 10, core 20. | high | source dependency order | D2-D5/D12 | incorporate | applied |
| C1PT-021 | Constructor is `[0x004ffaa0,0x004ffd1d)`, size `0x27d`. | very high | lookup/range bytes | D5 | incorporate | applied |
| C1PT-022 | Action method is `[0x004ffd20,0x004ffd3d)`, size `0x1d`. | very high | lookup/range bytes | D5 | incorporate | applied |
| C1PT-023 | Core range hash is `CDDAD4A5965999D02DF7997BB2432E1E956715AEC8662C30AB08381407035533`. | very high | exact bytes | D5 | incorporate | applied |
| C1PT-024 | Constructor hash is `F69996A83BF863E91FE9F5F851A2F6C2170A8CDF2AF28016E8F6648A2484BB09`. | very high | exact bytes | D5 | incorporate | applied |
| C1PT-025 | Action hash is `6819557D26D0641115A7AA8C33861F06992C10EE4DF66F3992F3826AE0AC33DD`. | very high | exact bytes | D5 | incorporate | applied |
| C1PT-026 | StaffsDialogPane directly derives from DialogPane. | very high | RTTI/ctor | D3/D5/D9/D10 | incorporate | applied |
| C1PT-027 | StaffsDialogPane directly derives from `Singleton<StaffsDialogPane>`. | very high | RTTI/ctor lowering | D3/D5/D6/D8-D10 | incorporate | applied |
| C1PT-028 | Singleton PMD is `{0x26c,-1,0}`. | very high | RTTI BCD | D1-D3/D9/D10 | incorporate | applied |
| C1PT-029 | Singleton is an empty base at complete-object end. | very high | PMD/object size | D3/D9/D10 | incorporate | applied |
| C1PT-030 | Complete object size is `0x26c`. | very high | DialogPane size/PMD/wrapper | D3/D8-D10 | incorporate | applied |
| C1PT-031 | StaffsDialogPane has no authored data members. | very high | layout/constructor stores | D3/D4 | incorporate | applied |
| C1PT-032 | Explicit constructor publication is compiler/base lowering and must be removed. | very high | Singleton construction pattern | D5 | reject-stale | applied |
| C1PT-033 | No unique authored destructor statement exists. | very high | base/wrapper split | D3/D4/D8 | reject-stale | applied |
| C1PT-034 | UID0001A9 is the generated Singleton base destructor used by EH. | very high | body/xref/RTTI | D6 | incorporate | applied |
| C1PT-035 | UID0001A9 exact hash is `77A9BB7ED5A69A15F22050B91BEE28CAE42E3C9E1F48AB05AA015C41BB13BC10`. | very high | exact bytes | D6 | incorporate | applied |
| C1PT-036 | UID0001AE contains two exact `0xb` adjustor thunks at `-0xa0` and `-0xa4`. | very high | disasm/vtable refs | D7 | incorporate | applied |
| C1PT-037 | UID0001AE exact hash is `A4540150A3BED1E0ACCF56D3161DA2C72155E3540F65F493E56010414B49B5C3`. | very high | exact bytes | D7 | incorporate | applied |
| C1PT-038 | UID0001AJ is a compiler scalar deleting wrapper, not authored destructor source. | very high | flags/calls/vtable | D8 | incorporate | applied |
| C1PT-039 | UID0001AJ exact hash is `B3F75C65CBE8843320BC941E3309AAF94331F163D1398F6FD62D3886A04BD582`. | very high | exact bytes | D8 | incorporate | applied |
| C1PT-040 | `0x0049d9f0` is DialogPane base teardown despite polluted labels. | very high | current DialogPane docs/body | D8 | reject-stale | applied |
| C1PT-041 | Delete flags, conditional free, guard, and vptr work are compiler/base output. | very high | wrapper ABI | D7/D8 | incorporate | applied |
| C1PT-042 | The class declaration must omit an explicit destructor. | very high | C1PT-033/041 | D3 | incorporate | applied |
| C1PT-043 | Staffs vtable cluster is exactly `[0x0061d930,0x0061d9cc)`, 156 bytes. | very high | raw data/boundaries | D9/D10/D11 | incorporate | applied |
| C1PT-044 | Vtable-cluster SHA256 is `E7A4B9BD17874390E125AB2A291521F5A64FB8DB3FF247836324DAD20CC8F86E`. | very high | exact bytes | D9/D10 | incorporate | applied |
| C1PT-045 | Primary locator/base are `0x0061d930/0x0061d934`. | very high | vtable data | D9/D10 | incorporate | applied |
| C1PT-046 | Secondary locator/base are `0x0061d990/0x0061d994`. | very high | vtable data | D9/D10 | incorporate | applied |
| C1PT-047 | Tertiary locator/base are `0x0061d9c0/0x0061d9c4`. | very high | vtable data | D9/D10 | incorporate | applied |
| C1PT-048 | Constructor stores all three vptrs at object offsets 0, `0xa0`, and `0xa4`. | very high | ctor disasm | D3/D5/D9/D10 | incorporate | applied |
| C1PT-049 | Primary slot zero points to scalar wrapper `0x00502cc0`. | very high | vtable data | D8-D10 | incorporate | applied |
| C1PT-050 | Primary `+0x48` cell `0x0061d97c` points to `0x004ffd20`. | very high | vtable xref | D5/D9/D10 | incorporate | applied |
| C1PT-051 | Source method name is `OnControlCommand`, not `OnDialogAction`. | very high | DialogPane slot contract | D3-D5 | reject-stale | applied |
| C1PT-052 | Exact source signature is `void OnControlCommand(int controlId, int notifyCode)`. | very high | base declaration/body ABI | D3/D5 | incorporate | applied |
| C1PT-053 | Secondary destructor cells route through the two UID0001AE thunks. | very high | vtable refs | D7/D9/D10 | incorporate | applied |
| C1PT-054 | Tertiary terminal cell `0x0061d9c8 -> 0x00544e90` is inherited/shared. | high | vtable data/current support | D9/D10 | incorporate | applied |
| C1PT-055 | RTTI cluster `[0x0064a7f0,0x0064a8cc)` SHA is `48E3DA5BFA1F1604A4C05013B550EC882D731A95D551B546B88D413EE0D5ADA7`. | very high | exact RTTI bytes | D9/D10 | incorporate | applied |
| C1PT-056 | RTTI hierarchy has eight entries: Staffs, DialogPane, Pane, GrafPort, LObject, EventHandler, TimerHandler, Singleton. | very high | CHD/base array | D3/D9/D10 | incorporate | applied |
| C1PT-057 | Singleton BCD attributes `0x40` and PMD prove direct nonvirtual EBO. | very high | RTTI BCD | D3/D9/D10 | incorporate | applied |
| C1PT-058 | UID0000DY receives a complete source declaration with no fields/destructor. | very high | closed class analysis | D3 | incorporate | applied |
| C1PT-059 | `0x0066db44` contains pointer `0x0061e484` to UTF-16 `STAFF.EPF`. | very high | pointer/literal bytes | D12-D14 | incorporate | applied |
| C1PT-060 | The resource pointer has five constructor refs. | very high | xrefs | D12-D14 | incorporate | applied |
| C1PT-061 | The literal has only the pointer-slot xref. | very high | xrefs | D12-D14 | incorporate | applied |
| C1PT-062 | Source resource declaration is file-local `const wchar_t *` pointer storage. | high | section/consumer set/style | D12 | incorporate | applied |
| C1PT-063 | Physical UID00027M becomes false/non-emitting to prevent duplication. | very high | one-definition policy | D13 | incorporate | applied |
| C1PT-064 | Semantic UID0002ZI emits the sole resource-pointer definition. | very high | source route | D12 | incorporate | applied |
| C1PT-065 | Resource pointer position is 5, between singleton global and class. | high | dependency/source order | D12 | incorporate | applied |
| C1PT-066 | Constructor preserves all five `kStaffsDialogEpfName` uses. | very high | ctor xrefs/body | D5/D12 | incorporate | applied |
| C1PT-067 | `0x004a90b0` is `EventMan::GetModifierState(unsigned char *)`. | very high | helper body/current EventMan docs | D5 | incorporate | applied |
| C1PT-068 | Alternate text selection preserves literal bit `0x02`. | very high | ctor branch | D5/D14 | incorporate | applied |
| C1PT-069 | `GetCurrentEventFlags` and named event constant are unsupported and removed. | very high | helper/type audit | D5 | reject-stale | applied |
| C1PT-070 | Layer operand is `g_mainUiLayerSlots.overlayPaneLayerContext`. | very high | current MainUiLayerSlots union | D5/D16 | incorporate | applied |
| C1PT-071 | Show parent is `g_pMainMenuPane`. | very high | current MainMenu union/call | D5/D16 | incorporate | applied |
| C1PT-072 | Constructor preserves frame/image/button/text/modal/keyboard/show/open order and constants. | very high | decompile/disasm | D5 | incorporate | applied |
| C1PT-073 | `STAFFS2` is selected when bit 2 is set; otherwise `STAFFS`. | very high | branch/literals | D5/D14 | incorporate | applied |
| C1PT-074 | OnControlCommand handles only control id 1 and ignores notify code. | very high | exact action body | D5 | incorporate | applied |
| C1PT-075 | Source placement is `NexusTK/login/StaffsDialogPane.cpp`. | very high | bounded owner family | D2-D5/D12 | incorporate | applied |
| C1PT-076 | Constructor has zero direct xrefs and zero VA/RVA/rel32 routes. | very high | xrefs/raw scan | D3-D5 | incorporate | applied |
| C1PT-077 | The out-of-line class source is retained linked source, not compiler-only code. | high | complete body/vtables/resources | D3-D5 | incorporate | applied |
| C1PT-078 | Absent entry route caps confidence but does not justify blank source. | high | evidence ladder | D3-D5 | incorporate | applied |
| C1PT-079 | UID00025Q remains a non-emitting mixed index and gains exact Staffs child inventory only. | very high | broad mixed range | D11 | incorporate | applied |
| C1PT-080 | New exact physical vtable child is required with `Nested:0`, physical containment under UID00025Q, and semantic canonical owner UID0000DY. | very high | exact bounded cluster; current sibling nesting sequence | D9/D11 | incorporate | applied |
| C1PT-081 | New semantic StaffsDialogPaneVtables page is required and remains non-emitting. | very high | source/compiler separation | D10 | incorporate | applied |
| C1PT-082 | New pages must be registered serially and linked only after real UIDs are issued. | very high | UID workflow | D9/D10/report | incorporate | applied |
| C1PT-083 | UID0001PT score becomes `92/94`. | very high | exhaustive closure | D1 | incorporate | applied |
| C1PT-084 | UID0000SC score becomes `92/94`. | very high | type/linkage/definition closure | D2 | incorporate | applied |
| C1PT-085 | UID0000DY score becomes `92/94`. | high | complete class; route cap | D3 | incorporate | applied |
| C1PT-086 | UID0000O3 score becomes `92/93`. | high | complete bounded source union | D4 | incorporate | applied |
| C1PT-087 | UID00019Z score becomes `92/94`. | high | complete body/source names | D5 | incorporate | applied |
| C1PT-088 | UID0001A9/UID0001AE/UID0001AJ become `92/96`, class-owned, false/non-emitting. | very high | exact compiler proof | D6-D8 | incorporate | applied |
| C1PT-089 | D9 is `92/96`, canonical owner UID0000DY, false/non-emitting, blank emitter/position/C++, and `Nested:0`; D10 is `92/96`, class-owned, false/non-emitting, and has no by-memory nesting metadata. | very high | exact data/compiler proof and relative address-sorted hierarchy | D9/D10 | incorporate | applied |
| C1PT-090 | UID0002ZI becomes `92/94`; UID00027M becomes `92/95` false/non-emitting. | very high | resource one-definition closure | D12/D13 | incorporate | applied |
| C1PT-091 | UID00025Q and UID0001RM retain `86/92` and `87/92`. | very high | bounded support scope | D11/D14 | already-present | already-present |
| C1PT-092 | No padding range is added; exact existing padding remains sufficient. | very high | boundary bytes/current ignored | D15 | not-applicable | excluded-with-reason |
| C1PT-093 | D15 requires exact no-loss replacement of all four current UID0001A9/UID0001AJ references: helper evidence, thunk owner link, predecessor-padding link/title, and padding owner link; helper wording must identify direct Singleton base destruction and wrapper wording must identify the scalar deleting destructor. | very high | current `-ignored.md` lines 1350, 1376, 1384, and 1388 plus surrounding blocks | D15 | incorporate | applied |
| C1PT-094 | Final-repair command 15999 is the latest observed pre-callback generated baseline; commands 15993 and 15981 are historical header provenance for the same source body. | very high | generated readback/header-only comparison | report | historicalize | applied |
| C1PT-095 | Final generation must contain one global, one resource pointer, one class, one constructor, and one OnControlCommand. | very high | source plan | generated assertions | incorporate | applied |
| C1PT-096 | Final generation must contain no explicit destructor/publish/clear, stale names, empty markers, raw vtable/RTTI, helper/thunk/wrapper duplicates. | very high | source/compiler plan | generated assertions | incorporate | applied |
| C1PT-097 | Executed reports are evidence-time leads, not authority. | very high | independent recheck | report history | historicalize | applied |
| C1PT-098 | Older-Research and SpecialReports contain no direct target report. | very high | explicit root search | report history | already-present | already-present |
| C1PT-099 | Exact no-loss manual coverage rows below preserve every valid current-row fact, add only accepted closure, and require supervisor-owned application after implementation verification. | very high | verbatim current-row comparison and row-by-row no-loss matrix | coverage handoff | incorporate | excluded-with-reason |
| C1PT-100 | Report-only phase performs no ordinary implementation, validator, coverage, IDA mutation, or lifecycle action. | very high | assignment boundary | report/checklist | incorporate | already-present |

### Callback Verification Notes

| Claim ID | Final state | Destination-specific callback proof |
| --- | --- | --- |
| C1PT-001 | applied | D1 current range/title is `[0x0069b490,0x0069b494)`; scoped command 16066 passed and current D1 SHA is `934B4668...F0B0`. |
| C1PT-002 | applied | D1 Exact Storage Evidence records `00 00 00 00` and full SHA256 `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`; command 16066 passed. |
| C1PT-003 | applied | D1 records RVA `0x0029b490` and its `.data` mapping; command 16066 passed. |
| C1PT-004 | applied | D1/D2 record that the RVA lies beyond raw-backed `.data` and is loader-zeroed; commands 16066/16063 passed. |
| C1PT-005 | applied | D1/D2 Historical And Superseded Assumptions reject `ff ff ff ff` using current bytes/PE arithmetic; commands 16066/16063 passed. |
| C1PT-006 | applied | D1 preserves UID0002XM predecessor and UID0001PU successor boundaries; command 16066 passed. |
| C1PT-007 | applied | D1/D2 retain exactly four write xrefs and `more:false`; commands 16066/16063 passed. |
| C1PT-008 | applied | D1/D2/D5 identify `0x004ffaf6` as direct Singleton publication lowering, not authored source; commands 16066/16063/16056 passed. |
| C1PT-009 | applied | D1/D2/D5 identify `0x004ffafd` as the adjusted-null fallback of Singleton lowering; commands 16066/16063/16056 passed. |
| C1PT-010 | applied | D1/D2 and renamed D6 identify `0x00502410` as constructor-EH Singleton base clear; D6 full command 16053 passed. |
| C1PT-011 | applied | D1/D2/D8 identify `0x00502cc6` as scalar-wrapper Singleton base clear; D8 command 16037 passed. |
| C1PT-012 | applied | D1/D2 preserve the exhaustive write-only four-xref result and no additional lifetime/read route; commands 16066/16063 passed. |
| C1PT-013 | applied | D1/D2/D3 use exact source type `StaffsDialogPane *`; commands 16066/16063/16059 passed. |
| C1PT-014 | applied | D1/D2/D3 use `g_pStaffsDialog` consistently and preserve inference provenance; commands 16066/16063/16059 passed. |
| C1PT-015 | applied | D1 header is `92/94`, owner UID0000SC, false/non-emitting, blank position/formal, `Nested:-4`; command 16066 passed. |
| C1PT-016 | applied | D2 is the sole typed definition and D1 is physical-only; D2 command 16063, B001 command 16069, and final current command 16100 prove one emitted definition. |
| C1PT-017 | applied | D2/D3/D4 identify external global linkage and reject file-local/member duplication; commands 16063/16059/16061 passed. |
| C1PT-018 | applied | D2 formal uses exact `StaffsDialogPane *g_pStaffsDialog = NULL;`; command 16063 and current command-16100 generated count are one. |
| C1PT-019 | applied | D2-D5/D12 all retain source owner/emitter UID0000O3 and `NexusTK/login/StaffsDialogPane.cpp`; their scoped commands passed. |
| C1PT-020 | applied | D2/D12/D3/D5 positions are `0/5/10/20`; current command 16100 orders their UID markers at offsets `318/489/667/990`, unchanged from command 16069. |
| C1PT-021 | applied | D5 Covered Range and callback evidence record constructor `[0x004ffaa0,0x004ffd1d)`, size `0x27d`; command 16056 passed. |
| C1PT-022 | applied | D5 records `OnControlCommand` `[0x004ffd20,0x004ffd3d)`, size `0x1d`; command 16056 passed. |
| C1PT-023 | applied | D5 records full core SHA256 `CDDAD4A5965999D02DF7997BB2432E1E956715AEC8662C30AB08381407035533`; command 16056 passed. |
| C1PT-024 | applied | D5 records constructor SHA256 `F69996A83BF863E91FE9F5F851A2F6C2170A8CDF2AF28016E8F6648A2484BB09`; command 16056 passed. |
| C1PT-025 | applied | D5 records method SHA256 `6819557D26D0641115A7AA8C33861F06992C10EE4DF66F3992F3826AE0AC33DD`; command 16056 passed. |
| C1PT-026 | applied | D3/D5/D9/D10 identify direct `DialogPane` inheritance; commands 16059/16056/16068/16010 passed. |
| C1PT-027 | applied | D3/D5/D6/D8-D10 identify direct `Singleton<StaffsDialogPane>` inheritance/source cause; all destination validators passed. |
| C1PT-028 | applied | D1-D3/D9/D10 preserve Singleton PMD `{0x26c,-1,0}`; relevant scoped validators passed. |
| C1PT-029 | applied | D3/D9/D10 record direct empty base placement at complete-object end; commands 16059/16068/16010 passed. |
| C1PT-030 | applied | D3/D8-D10 record complete object size `0x26c`; commands 16059/16037/16068/16010 passed. |
| C1PT-031 | applied | D3/D4 state that StaffsDialogPane adds no authored fields; commands 16059/16061 passed. |
| C1PT-032 | applied | D5 formal contains no `g_pStaffsDialog = this`; command 16056 passed and current command-16100 generated count is zero. |
| C1PT-033 | applied | D3/D4/D8 omit an authored destructor and historicalize the prior clear; commands 16059/16061/16037 passed. |
| C1PT-034 | applied | Renamed D6 is exact `StaffsDialogPaneSingletonBaseDestructor`, class-owned false/non-emitting; path command 16030 and full command 16053 passed. |
| C1PT-035 | applied | D6 records full byte SHA256 `77A9BB7ED5A69A15F22050B91BEE28CAE42E3C9E1F48AB05AA015C41BB13BC10`; command 16053 passed. |
| C1PT-036 | applied | D7 documents both exact `0xb` `-0xa0/-0xa4` adjustor thunks; command 16039 passed. |
| C1PT-037 | applied | D7 records full span SHA256 `A4540150A3BED1E0ACCF56D3161DA2C72155E3540F65F493E56010414B49B5C3`; command 16039 passed. |
| C1PT-038 | applied | Renamed D8 is a compiler scalar deleting wrapper, `92/96`, false/non-emitting, blank formal; commands 16035/16037 passed. |
| C1PT-039 | applied | D8 records full byte SHA256 `B3F75C65CBE8843320BC941E3309AAF94331F163D1398F6FD62D3886A04BD582`; command 16037 passed. |
| C1PT-040 | applied | D8 explicitly resolves `0x0049d9f0` as DialogPane teardown and historicalizes polluted Boost/TransferReplyAlert labels; command 16037 passed. |
| C1PT-041 | applied | D7/D8 classify delete flags, conditional free, guard, vptr/base work, and adjustors as compiler/base output; commands 16039/16037 passed. |
| C1PT-042 | applied | D3 formal has no destructor declaration; command 16059 and current command-16100 generated readback confirm omission. |
| C1PT-043 | applied | D9/D10/D11 record exact `[0x0061d930,0x0061d9cc)` 156-byte cluster; commands 16068/16010/16042 passed. |
| C1PT-044 | applied | D9/D10 record full cluster SHA256 `E7A4B9BD17874390E125AB2A291521F5A64FB8DB3FF247836324DAD20CC8F86E`; commands 16068/16010 passed. |
| C1PT-045 | applied | D9/D10 record primary locator/base `0x0061d930/0x0061d934`; commands 16068/16010 passed. |
| C1PT-046 | applied | D9/D10 record secondary locator/base `0x0061d990/0x0061d994`; commands 16068/16010 passed. |
| C1PT-047 | applied | D9/D10 record tertiary locator/base `0x0061d9c0/0x0061d9c4`; commands 16068/16010 passed. |
| C1PT-048 | applied | D3/D5/D9/D10 record constructor vptr stores at offsets `0`, `0xa0`, and `0xa4`; all scoped commands passed. |
| C1PT-049 | applied | D8-D10 record primary slot zero to scalar wrapper `0x00502cc0`; commands 16037/16068/16010 passed. |
| C1PT-050 | applied | D5/D9/D10 record primary `+0x48`, cell `0x0061d97c`, to `0x004ffd20`; commands 16056/16068/16010 passed. |
| C1PT-051 | applied | D3-D5 use current `OnControlCommand` and retain `OnDialogAction` only as superseded history; commands 16059/16061/16056 passed. |
| C1PT-052 | applied | D3/D5 formal blocks use exact `void OnControlCommand(int controlId, int notifyCode)`; current command 16100 contains one matching definition. |
| C1PT-053 | applied | D7/D9/D10 preserve both secondary destructor cells and adjusted thunk routes; commands 16039/16068/16010 passed. |
| C1PT-054 | applied | D9/D10 record inherited/shared `0x0061d9c8 -> 0x00544e90`; commands 16068/16010 passed. |
| C1PT-055 | applied | D9/D10 record RTTI cluster hash `48E3DA5BFA1F1604A4C05013B550EC882D731A95D551B546B88D413EE0D5ADA7`; commands 16068/16010 passed. |
| C1PT-056 | applied | D3/D9/D10 list all eight hierarchy entries without loss; commands 16059/16068/16010 passed. |
| C1PT-057 | applied | D3/D9/D10 record BCD attributes `0x40`, PMD, direct nonvirtual EBO; commands 16059/16068/16010 passed. |
| C1PT-058 | applied | D3 now carries the complete fieldless two-base class declaration with constructor/virtual and no destructor; command 16059 passed. |
| C1PT-059 | applied | D12-D14 record `0x0066db44 -> 0x0061e484` UTF-16 `STAFF.EPF`; final scoped commands 16094/16096/16048 passed. |
| C1PT-060 | applied | D12-D14 retain all five constructor xrefs; final scoped commands 16094/16096/16048 passed. |
| C1PT-061 | applied | D12-D14 record the literal's sole pointer-slot xref; final scoped commands 16094/16096/16048 passed. |
| C1PT-062 | applied | D12 formal emits file-local `static const wchar_t *kStaffsDialogEpfName`; command 16094 and current command-16100 readback confirm one definition. |
| C1PT-063 | applied | D13 is now `92/95`, false/non-emitting, blank emitter/position/formal; final command 16096 passed and generated marker count is zero. |
| C1PT-064 | applied | D12 UID0002ZI is the sole resource-pointer emitter; final scoped command 16094 and current command-16100 generated count are one. |
| C1PT-065 | applied | D12 position is `5`, between global position `0` and class position `10`; final command 16094 and generated order prove it. |
| C1PT-066 | applied | D5 formal preserves all five `kStaffsDialogEpfName` uses; command 16056 and generated readback confirm exact body. |
| C1PT-067 | applied | D5/D14 identify `0x004a90b0` as `EventMan::GetModifierState(unsigned char *)`; commands 16056/16048 passed. |
| C1PT-068 | applied | D5/D14 preserve literal modifier bit `0x02`; commands 16056/16048 and generated readback confirm it. |
| C1PT-069 | applied | D5/D14 remove current `GetCurrentEventFlags`/invented enum and preserve them only as history; current command 16100 counts both zero. |
| C1PT-070 | applied | D5 uses `g_mainUiLayerSlots.overlayPaneLayerContext`; D16 verify-only MainMenu hashes remained unchanged and current command 16100 contains the exact field. |
| C1PT-071 | applied | D5 uses `g_pMainMenuPane`; D16 verify-only union preserves the same concrete parent route and current command 16100 contains it. |
| C1PT-072 | applied | D5 formal/evidence preserves frame, image, button, text, modal, keyboard, attach, show, and open order/constants; command 16056 passed. |
| C1PT-073 | applied | D5/D14 retain `STAFFS2` when bit `0x02` is set and `STAFFS` otherwise; commands 16056/16048 passed. |
| C1PT-074 | applied | D5 exact method handles only control id `1` and explicitly ignores notify code; command 16056 and generated readback confirm it. |
| C1PT-075 | applied | D2-D5/D12 all retain `NexusTK/login/StaffsDialogPane.cpp`; scoped validators and generated source UID0000O3 route agree. |
| C1PT-076 | applied | D3-D5 preserve zero direct constructor xrefs and zero VA/RVA/rel32 routes as a confidence cap; commands 16059/16061/16056 passed. |
| C1PT-077 | applied | D3-D5 classify the complete out-of-line body as retained linked source, not compiler-only code; current command 16100 emits it once. |
| C1PT-078 | applied | D3-D5 retain absent entry route as confidence cap while scores/formals are source-ready; commands 16059/16061/16056 passed. |
| C1PT-079 | applied | D11 remains `86/92`, NONE-owned, false/non-emitting and adds only exact Staffs child inventory; final command 16098 passed with one pre-existing UID00036V warning. |
| C1PT-080 | applied | D9 was created first as UID0004VJ with `Nested:0`, physical UID00025Q containment, semantic owner UID0000DY; commands 16007/16008/16068 prove registration/current page. |
| C1PT-081 | applied | D10 was created second as UID0004VK, class-owned false/non-emitting with blank formal; command 16010 proves registration/current page. |
| C1PT-082 | applied | Serial registration order is command 16007 UID0004VJ before command 16010 UID0004VK; all links/manual text use real UIDs and no provisional token remains. |
| C1PT-083 | applied | D1 header/readback is current `92/94`; command 16066 passed. |
| C1PT-084 | applied | D2 header/readback is current `92/94`; command 16063 passed. |
| C1PT-085 | applied | D3 header/readback is current `92/94`; command 16059 passed. |
| C1PT-086 | applied | D4 header/readback is current `92/93`; command 16061 passed. |
| C1PT-087 | applied | D5 header/readback is current `92/94`; command 16056 passed. |
| C1PT-088 | applied | D6/D7/D8 headers are each current `92/96`, owner UID0000DY, false/non-emitting, blank formal; commands 16053/16039/16037 passed. |
| C1PT-089 | applied | D9/D10 are each current `92/96`, UID0000DY-owned, false/non-emitting; D9 has `Nested:0`, D10 has no by-memory nesting field; commands 16068/16010 passed. |
| C1PT-090 | applied | D12 is current `92/94` source emitter and D13 current `92/95` physical non-emitter; final commands 16094/16096 passed. |
| C1PT-091 | already-present | D11/D14 retained accepted `86/92` and `87/92` while adding bounded facts; final commands 16098/16048 passed without score changes. |
| C1PT-092 | excluded-with-reason | D15 readback proves existing padding is sufficient; no new padding row was accepted or added, while exact four reference replacements passed command 16051. |
| C1PT-093 | applied | D15 exact helper block, thunk owner, predecessor-padding link/title, and padding owner now use Singleton-base/scalar-wrapper paths; SHA `88847D17...65A2`, command 16051 passed. |
| C1PT-094 | applied | Commands 15981/15993/15999 remain historical pre-callback evidence; command 16069 is initial callback proof, command 16091 is an intermediate external header epoch, and final B001 command 16100 is current authority for the same accepted body. |
| C1PT-095 | applied | Current command-16100 readback counts exactly one global, resource pointer, class, constructor, and `OnControlCommand` in accepted order, unchanged from command 16069. |
| C1PT-096 | applied | Current command-16100 readback counts zero explicit destructor/publish/additional clear, stale names, Empty Emitter Markers, physical/compiler markers, vtable/RTTI, or duplicate body. |
| C1PT-097 | applied | Supporting Research retains executed B014/B005/B002 artifacts as evidence-time leads and states current bytes/docs/source routing are authority. |
| C1PT-098 | already-present | Supporting Research preserves path-specific Older-Research/SpecialReports searches and explicit no-direct-report result. |
| C1PT-099 | excluded-with-reason | Current manual hashes/rows were reread no-loss; exact replacement/insertion text uses UID0004VJ/UID0004VK and remains unapplied because manual coverage is supervisor-owned. |
| C1PT-100 | already-present | Evidence Checked preserves the initial report-only no-edit/no-validator/no-lifecycle boundary and separately records the later accepted callback actions; B001 still performed no manual coverage, IDA, execute, move, archive, or lifecycle action. |

## Positive Evidence Summary

- Four live writes align exactly with direct Singleton base construction/destruction, and there are no reads or unrelated consumers.
- RTTI independently proves the exact direct-base hierarchy, empty-base PMD, and complete size.
- Constructor vptr stores, three vtable views, scalar wrapper, and adjustor offsets agree with DialogPane layout.
- The action cell is the established DialogPane `OnControlCommand` slot.
- Exact resource pointer/literal xrefs and exclusive constructor uses support file-local source placement.
- MixItemDialog provides a current same-ABI comparator: direct DialogPane plus Singleton EBO, implicit destructor, compiler base clear, scalar wrapper, adjustor thunks, and non-emitting vtables.

## IDA MCP Facts

- Active database: `9b0396a3`; module `NexusTK.exe`; imagebase `0x00400000`.
- Target bytes: four zero bytes.
- Target xrefs: `0x004ffaf6`, `0x004ffafd`, `0x00502410`, `0x00502cc6`.
- Function records: `sub_4FFAA0` size `0x27d`; `sub_4FFD20` size `0x1d`; `sub_502410` size `0xb`; `sub_502592` size `0xb`; `sub_50259D` size `0xb`; `sub_502CC0` size `0x45`.
- Constructor xrefs: zero.
- Vtable cells: `0x0061d934 -> 0x00502cc0`, `0x0061d97c -> 0x004ffd20`, `0x0061d994 -> 0x00502592`, `0x0061d9c4 -> 0x0050259d`, `0x0061d9c8 -> 0x00544e90`.
- Constructor vptr stores: `0x0061d934`, `0x0061d994`, `0x0061d9c4`.
- RTTI: eight-entry hierarchy and Singleton PMD `{0x26c,-1,0}`, attributes `0x40`.
- Resource pointer: `0x0066db44 -> 0x0061e484`, five constructor refs; literal has one pointer-slot ref.
- Negative facts: no target reads, no additional target refs, no constructor pointer/RVA/rel32 route, no authored-only destructor action, no additional Staffs fields.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `[0x004ffaa0,0x004ffd3d)` | UID00019Z / D5 | constructor plus OnControlCommand | true | UID0000O3 | current `92/94` | implemented and validated source body |
| `[0x00502410,0x0050241b)` | UID0001A9 / D6 | Singleton base destructor/EH cleanup | false | UID0000DY | current `92/96` | UID-preserving rename and compiler disposition implemented/validated |
| `[0x00502592,0x005025a8)` | UID0001AE / D7 | two destructor adjustor thunks | false | UID0000DY | current `92/96` | compiler disposition implemented/validated |
| `[0x00502cc0,0x00502d05)` | UID0001AJ / D8 | scalar deleting destructor wrapper | false | UID0000DY | current `92/96` | UID-preserving rename and compiler disposition implemented/validated |
| `[0x0061d930,0x0061d9cc)` | UID0004VJ / D9 | exact physical vtable cluster | false | physical UID00025Q; canonical UID0000DY | current `92/96` | registered exact page, `Nested:0` |
| StaffsDialogPaneVtables | UID0004VK / D10 | semantic compiler-data inventory | false | UID0000DY | current `92/96` | registered semantic page |
| `[0x0066db44,0x0066db48)` | UID00027M / D13 | physical STAFF.EPF pointer | false | UID0002ZI | current `92/95` | non-emitting physical evidence implemented/validated |
| StaffsDialogEpfResourcePointer | UID0002ZI / D12 | sole source pointer definition | true | UID0000O3 | current `92/94` | source definition implemented/validated |
| `[0x0069b490,0x0069b494)` | UID0001PT / D1 | physical singleton slot | false | UID0000SC | current `92/94` | non-emitting physical evidence implemented/validated |
| g_pStaffsDialog | UID0000SC / D2 | sole source global definition | true | UID0000O3 | current `92/94` | source definition implemented/validated |
| StaffsDialogPane | UID0000DY / D3 | complete class declaration | true | UID0000O3 | current `92/94` | complete declaration implemented/validated |
| StaffsDialogPane.cpp | UID0000O3 / D4 | source root | true | source tree | current `92/93` | complete bounded union implemented/validated |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004ffaf6` | write to `0x0069b490` | Singleton publication lowering |
| `0x004ffafd` | write zero to `0x0069b490` | adjusted-null fallback lowering |
| `0x00502410` | write zero; EH xref `0x00601e35` | generated Singleton base destructor |
| `0x00502cc6` | write zero in scalar wrapper | implicit Singleton base teardown |
| `0x0061d97c` | data xref to `0x004ffd20` | virtual OnControlCommand route |
| `0x0061d934` | data xref to `0x00502cc0` | primary scalar deleting slot |
| `0x0061d994` | data xref to `0x00502592` | secondary adjusted destructor |
| `0x0061d9c4` | data xref to `0x0050259d` | tertiary adjusted destructor |
| `0x0066db44` | five constructor refs | STAFF.EPF pointer consumers |
| `0x0061e484` | one ref from `0x0066db44` | UTF-16 literal indirection |
| constructor `0x004ffaa0` | no direct xref/route | retained linked source; no invented opener |

## Documentation Evidence And IDA Status

- D1-D8 now contain the accepted behavioral facts, source/compiler authorship, names, metadata, and historicalized superseded assumptions.
- DialogPane current formal and prose identify primary `+0x48` as `OnControlCommand(int,int)`.
- EventMan current support identifies `0x004a90b0` as `GetModifierState(unsigned char *)`.
- MainUiLayerSlots current support identifies `0x0069b36c` as `overlayPaneLayerContext`.
- UID0001RM accurately separates source selection from missing staff-specific resource payload provenance.
- UID00025Q remains a mixed non-emitting aggregate and now indexes exact Staffs vtable child UID0004VJ without taking semantic ownership.
- Historical generated command 15999 confirms the pre-callback routing defects and empty emitters; commands 15993 and 15981 had the same old source body. B001 command 16069 first verified the accepted duplicate-free union, external command 16091 preserved it, and final B001 command 16100 is current. Generated output is verification evidence, not binary authority, and later unrelated validator epochs remain external.
- Current supervisor-owned manual rows remain stale or absent for the accepted metadata/path/new-child changes; the exact real-UID no-loss handoff appears below and was not applied by B001.

## Ranked Ownership Analysis

### 1. StaffsDialogPane.cpp semantic global/class source

- Evidence for: exclusive Staffs constructor/destructor lifetime, RTTI class identity, `STAFF.EPF` consumer set, source route, peer singleton pattern, and existing UID0000O3 ownership.
- Evidence against: no direct constructor caller and no original symbol spelling.
- Decision: accepted. The absent entry route caps confidence but does not outweigh the complete exclusive source family.

### 2. MainMenuPane source

- Evidence for: the dialog is shown under `g_pMainMenuPane` and uses a main UI layer.
- Evidence against: MainMenuPane neither stores nor writes the Staffs slot, and the exact class/resource/method family has its own source root.
- Decision: rejected as owner; retained as verify-only dependency.

### 3. Compiler/template-only or gameplay staff manager

- Evidence for: Singleton produces compiler lifetime code; the name Staffs could be misread as game staff.
- Evidence against: authored constructor/action UI body and staff/credits resources prove retained source; no GM/gameplay reference touches the slot.
- Decision: rejected. Only the base-lifetime/data artifacts are compiler-generated.

### Proposed new file/grouping, if applicable

- No new source file. Keep `NexusTK/login/StaffsDialogPane.cpp`.
- Added semantic vtable documentation UID0004VK and exact backing-memory UID0004VJ.
- Do not create a standalone global source, vtable source, RTTI source, destructor source, or resource-pointer source.

## Source Placement

- Source file: `NexusTK/login/StaffsDialogPane.cpp`.
- Order: UID0000SC global at 0, UID0002ZI resource pointer at 5, UID0000DY class at 10, UID00019Z methods at 20.
- The class declaration causes compiler vtables, RTTI, implicit virtual destructor, Singleton publication/clear, scalar wrapper, and adjustor thunks.
- Rejected placements: MainMenuPane.cpp, EventMan.cpp, ScrolledTextControlPane.cpp, a generic globals file, a generic resource table, and a standalone vtable/destructor unit.

## Range / Split / Padding / Reclassification Analysis

- UID0001PT remains the exact indivisible four-byte slot. No target split or padding child is required.
- UID0001A9 and UID0001AJ received UID-preserving validator-aware renames only; their ranges did not change.
- UID00025Q exact Staffs subrange is `[0x0061d930,0x0061d9cc)`, between ScrolledPicture ending `0x0061d930` and HistoryViewing starting `0x0061d9cc`.
- Current address-sorted hierarchy is explicit: UID00025Q has `Nested:0`; its first exact child UID0003BY has `Nested:8`; sibling UID0004PP has `Nested:0`. D9 sorts immediately after UID0004PP and therefore must use `Nested:0`, preserving the same physical-child level. D9 does not change later UID0002OV `Nested:4`, its subsequent sibling levels, or UID00025R `Nested:-4` closure.
- Physical containment and semantic ownership are separate: D9 is physically nested under mixed aggregate UID00025Q for coverage/index structure, while `CANONICAL_OWNER:0000DY` records that the StaffsDialogPane declaration is the compiler-data source cause. UID00025Q remains `CANONICAL_OWNER:NONE` and gains no source/emitter ownership.
- D9 UID0004VJ and D10 UID0004VK were created serially. D9 is the exact physical range with `Nested:0`; D10 is the semantic compiler-data inventory and has no by-memory `Nested` field. Both are false/non-emitting.
- Existing `by-memory/-ignored.md` continues to record the EH helper, thunks, and neighboring padding; only the accepted renamed path/title and compiler/source wording was synchronized.
- No new ignored span was added.

## Negative Evidence Summary

- No target reads or fifth xref.
- No raw target initializer bytes; no valid `ff ff ff ff` source for this slot.
- No direct constructor xref, absolute-VA pointer, RVA pointer, or rel32 call/jump.
- No MainMenuPane write or ownership field.
- No authored clear helper call or independent API route.
- No unique authored destructor cleanup after removing implicit Singleton/DialogPane/compiler work.
- No extra Staffs member field, reserved tail, or explicit Singleton storage.
- No separate `OnDialogAction` virtual contract at the occupied DialogPane slot.
- No declaration evidence for `GetCurrentEventFlags`, `kStaffsDialogAlternateTextEventFlag`, or `g_mainUiLayer`.
- No reason to handwrite vtable, RTTI, scalar-delete, adjustor, EH, vptr, or delete-flag code.

## IDA Rename / Type / Comment Recommendations

- Report source-facing names: `g_pStaffsDialog`, `StaffsDialogPane`, `OnControlCommand`, `controlId`, `notifyCode`, `modifierState`, and `kStaffsDialogEpfName`.
- Rename D6 title/path to `StaffsDialogPaneSingletonBaseDestructor`.
- Rename D8 title/path to `StaffsDialogPaneScalarDeletingDestructor`.
- New D9/D10 names are exact descriptive documentation names, not claimed recovered symbols.
- Preserve raw IDA labels as evidence history where useful.
- No IDA database rename/type/comment mutation is requested or authorized.

## First-Draft C++ Recommendation

Destination D1: `by-memory/0x0069b490-0x0069b494.g_pStaffsDialog.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination D2: `by-global/g_pStaffsDialog.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class StaffsDialogPane;

StaffsDialogPane *g_pStaffsDialog = NULL;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination D3: `by-class/StaffsDialogPane.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class StaffsDialogPane : public DialogPane,
                         public Singleton<StaffsDialogPane>
{
public:
    StaffsDialogPane();

protected:
    virtual void OnControlCommand(int controlId, int notifyCode);
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination D5: `by-memory/0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
StaffsDialogPane::StaffsDialogPane()
    : DialogPane(g_emptyWideString, -1, true),
      Singleton<StaffsDialogPane>()
{
    RECT frameRect;
    RECT controlRect;
    unsigned char modifierState;

    g_pEventMan->GetModifierState(&modifierState);

    GetDialogResourceFrame(kStaffsDialogEpfName, 0, &frameRect);
    AddControl(new EPFImageControlPane(kStaffsDialogEpfName, 0, true, frameRect, L"NPAL8.PAL"));
    LoadDialogResource(kStaffsDialogEpfName, 0);

    GetDialogResourceFrame(kStaffsDialogEpfName, 0, &frameRect);
    SetRect(&controlRect,
            (frameRect.right - frameRect.left) / 2 - 31,
            322,
            (frameRect.right - frameRect.left) / 2 + 31,
            346);
    AddControl(new ImageButtonControlPane(14, controlRect));

    SetRect(&controlRect, 38, 62, 230, 305);
    AddControl(new ScrolledTextControlPane((modifierState & 0x02) != 0 ? L"STAFFS2" : L"STAFFS",
                                           controlRect,
                                           50));

    SetCloseOnEscape(true);
    SetModal(true);
    EnableKeyboardInput(true);

    GetDialogResourceFrame(kStaffsDialogEpfName, 0, &frameRect);
    OffsetRect(&frameRect, frameRect.left - frameRect.right + 630, 130);
    AttachToLayer(frameRect, 0, 0, g_mainUiLayerSlots.overlayPaneLayerContext);
    Show(0, g_pMainMenuPane);
    SlideOpen();
}

void StaffsDialogPane::OnControlCommand(int controlId, int notifyCode)
{
    (void)notifyCode;

    if (controlId == 1) {
        SlideClose();
        CloseDialog();
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination D6 after UID-preserving rename: `by-memory/0x00502410-0x0050241b.StaffsDialogPaneSingletonBaseDestructor.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination D7: `by-memory/0x00502592-0x005025a8.StaffsDialogPaneDestructorThunks.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination D8 after UID-preserving rename: `by-memory/0x00502cc0-0x00502d05.StaffsDialogPaneScalarDeletingDestructor.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination D9 new physical vtable page: `by-memory/0x0061d930-0x0061d9cc.StaffsDialogPaneVtableData.md`. Its exact metadata is `COMPLETION:92`, `CONFIDENCE:96`, `CANONICAL_OWNER:0000DY`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and `Nested:0`. It is physically contained under UID00025Q while semantically owned by UID0000DY.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination D10 new semantic page: `by-type/by-vtable/StaffsDialogPaneVtables.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination D11: `by-memory/0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination D12: `by-global/StaffsDialogEpfResourcePointer.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static const wchar_t *kStaffsDialogEpfName = L"STAFF.EPF";

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination D13: `by-memory/0x0066db44-0x0066db48.StaffsDialogEpfResourcePointer.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- These are the only source/declaration/example blocks. D4, D14, D15, and D16 are prose/route/support destinations and receive no C++.
- D1, D6-D11, and D13 remain blank because their exact bytes are physical/compiler/index evidence generated from D2/D3/D5/D12 source causes.
- No third-party import directive applies.

## Final Recommendation

- D1-D16 and C1PT-001 through C1PT-100 are applied/verified without compression; the exact bytes, hashes, xrefs, boundaries, source/compiler distinctions, negative evidence, and rejected historical assumptions remain preserved.
- D9 was registered first as UID0004VJ and D10 second as UID0004VK; all links and manual handoff text use those real UIDs.
- MainMenuPane class/file remained verify-only after reread confirmed the accepted `g_pMainMenuPane` and separate overlay-layer facts.
- Resource payload provenance remains outside source closure; no missing resource content was invented.

## Recommended Target Doc Changes

- D1 target path: `by-memory/0x0069b490-0x0069b494.g_pStaffsDialog.md`.
- Applied `COMPLETION:92`, `CONFIDENCE:94`, owner UID0000SC, reconstructable false, blank emitters/position/formal, and retained `Nested:-4`.
- Replaced stale current-source publication/destructor text with exact physical-slot, PE zero-fill, four-write Singleton lowering, one-definition, no-read, neighbor, source/compiler, and historical `ff` evidence.
- Preserved all useful earlier evidence as dated/superseded history with rejection reasons.

## Recommended Support Doc Changes

- D2 `by-global/g_pStaffsDialog.md`: `92/94`, owner/emitter UID0000O3, position 0, exact typed definition, one-definition/lifetime/PE/history evidence.
- D3 `by-class/StaffsDialogPane.md`: `92/94`, owner/emitter UID0000O3, position 10, complete declaration, direct bases/EBO/layout, no explicit destructor, exact OnControlCommand slot, full child links.
- D4 `by-file/StaffsDialogPane.md`: `92/93`, preserve `NexusTK/login/` route; document exact source order, complete source/compiler union, retained-source caveat, resource dependencies, and exclusions.
- D5 core: `92/94`, position 20, exact formal body and all behavior/range/hash/caller/negative/history evidence.
- D6 UID0001A9: UID-preserving rename to exact path/title, `92/96`, class owner UID0000DY, false/non-emitting, blank position/C++; exact Singleton base destructor proof.
- D7 UID0001AE: `92/96`, class owner UID0000DY, false/non-emitting, blank position/C++; exact two-thunk proof.
- D8 UID0001AJ: UID-preserving rename to exact scalar-wrapper path/title, `92/96`, class owner UID0000DY, false/non-emitting, blank position/C++; historicalize B005 authored-destructor conclusion.
- D9: created/registered first as UID0004VJ at `92/96`, canonical owner UID0000DY, false/non-emitting, blank emitter/position/C++, and exact `Nested:0`; physical containment under UID00025Q is documented separately from class ownership.
- D10: created/registered second as UID0004VK at `92/96`, owner UID0000DY, false/non-emitting, and blank emitter/position/C++; no by-memory `Nested` metadata applies.
- D11 UID00025Q: preserve `86/92`, NONE/false/blank; add exact Staffs child range, three views, method/wrapper cells, RTTI/EBO, predecessor/successor, and links.
- D12 UID0002ZI: `92/94`, owner/emitter UID0000O3, position 5, exact file-local pointer definition and xref/source evidence.
- D13 UID00027M: `92/95`, owner UID0002ZI, false/non-emitting, blank emitter/position/C++; exact physical pointer/literal/neighbor evidence.
- D14 UID0001RM: preserve `87/92`; add closed EventMan bit-source and resource-pointer definition route without changing payload-provenance blockers.
- D15 `by-memory/-ignored.md`: exact four-reference/block replacements below were applied while preserving all ranges, surrounding evidence, owner lists, padding facts, and unrelated rows.
- D16 MainMenuPane class/file: verify-only reread found no direct contradiction; scores/content were preserved unchanged.

### D15 Exact No-Loss Replacement Text

Historical Gate 1 readback inspected `by-memory/-ignored.md` SHA256 `65E1CFBF76C650F49F781DEC52BDEE25D4AD2801D7113F249EE4B707B5E3CA60`, 1,099,672 bytes / 5,339 lines. Callback command 16051 applied the four accepted replacements; current D15 SHA256 is `88847D175F657AC6D8FE13C153B2C32DAC2245093E1F104AB2CEFE2D93AC65A2`, 1,100,053 bytes / 5,339 lines. The first replacement intentionally covered the complete former lines-1348-through-1352 block so the compiler/source disposition remains internally coherent.

Applied D15 block:

```text
- `0x00502410-0x0050241b` - `Singleton<StaffsDialogPane>` base-destructor instantiation used by `StaffsDialogPane` constructor EH cleanup.
  - Why ignored: compiler-generated direct Singleton base destruction that clears `g_pStaffsDialog` during constructor unwind; not a normal handwritten helper or StaffsDialogPane method.
  - Evidence: [UID:0001A9][0x00502410-0x0050241b.StaffsDialogPaneSingletonBaseDestructor](by-memory/0x00502410-0x0050241b.StaffsDialogPaneSingletonBaseDestructor.md) records IDA MCP lookup/decompile/xref evidence: the exact eleven-byte body only writes zero to `0x0069b490`, has no ordinary callers or callees, has constructor-context unwind xref `0x00601e35`, and is caused by the direct `Singleton<StaffsDialogPane>` base at `+0x26c`.
  - Replacement/procurement: no external dependency or handwritten source body; regenerated by the compiler from the direct `Singleton<StaffsDialogPane>` base declaration and constructor unwind path.
  - Owner docs: [UID:0000O3][StaffsDialogPane](by-file/StaffsDialogPane.md), [UID:0000DY][StaffsDialogPane](by-class/StaffsDialogPane.md), [UID:0000SC][g_pStaffsDialog](by-global/g_pStaffsDialog.md).
```

Applied thunk-owner line:

```text
  - Owner docs: [UID:0000O3][StaffsDialogPane](by-file/StaffsDialogPane.md), [UID:0000DY][StaffsDialogPane](by-class/StaffsDialogPane.md), [UID:0001AJ][0x00502cc0-0x00502d05.StaffsDialogPaneScalarDeletingDestructor](by-memory/0x00502cc0-0x00502d05.StaffsDialogPaneScalarDeletingDestructor.md).
```

Applied predecessor-padding line:

```text
- `0x00502cbd-0x00502cc0` - alignment padding between [UID:00019X][0x004ff400-0x004ff7cd.ScrolledTextControlPaneForMadeByCore](by-memory/0x004ff400-0x004ff7cd.ScrolledTextControlPaneForMadeByCore.md) `ScrolledTextControlPaneForMadeBy` and [UID:0001AJ][0x00502cc0-0x00502d05.StaffsDialogPaneScalarDeletingDestructor](by-memory/0x00502cc0-0x00502d05.StaffsDialogPaneScalarDeletingDestructor.md) `StaffsDialogPaneScalarDeletingDestructor`.
```

Applied padding-owner line:

```text
  - Owner docs: [UID:00019X][0x004ff400-0x004ff7cd.ScrolledTextControlPaneForMadeByCore](by-memory/0x004ff400-0x004ff7cd.ScrolledTextControlPaneForMadeByCore.md) `ScrolledTextControlPaneForMadeBy`, [UID:0001AJ][0x00502cc0-0x00502d05.StaffsDialogPaneScalarDeletingDestructor](by-memory/0x00502cc0-0x00502d05.StaffsDialogPaneScalarDeletingDestructor.md).
```

The UID0001AE evidence link and its exact range/xrefs remain unchanged. Current readback confirms these replacements account for every UID0001A9/UID0001AJ path/title occurrence in D15.

## Score And Metadata Recommendation

- D1 `86/90 -> 92/94`: byte/storage/lifetime/one-definition blockers closed; physical page becomes non-emitting.
- D2 `86/90 -> 92/94`: type, linkage, initializer, owner, position, and sole definition closed.
- D3 current `87/87 -> 92/94`: complete direct bases, EBO, size, no fields, virtual identity, implicit destructor, and child/compiler routing closed.
- D4 current `86/88 -> 92/93`: complete bounded source union closed; confidence capped by absent direct constructor route and inferred original lexical names.
- D5 `88/90 -> 92/94`: exact ranges, hashes, API names, globals, body, and compiler exclusions closed.
- D6-D8 `84/90`, `84/90`, `88/90` -> `92/96`: exact compiler-generated identities and no-code causes closed.
- D9 new `92/96`: canonical owner UID0000DY, false/non-emitting, blank emitter/position/C++, exact `Nested:0`, physically contained by UID00025Q; exact cluster/RTTI/slots/source cause close all metadata blockers.
- D10 new `92/96`: canonical owner UID0000DY, false/non-emitting, blank emitter/position/C++; semantic compiler-data inventory has no by-memory nesting field.
- D12 `87/92 -> 92/94`; D13 `88/92 -> 92/95`: definition/pointer/storage one-definition closed.
- D11 and D14 retain current scores because this callback only adds bounded support closure; resource payload provenance remains outside source reconstruction.
- No score is inflated to 100 because original symbols, direct constructor route, and missing staff-specific resource payloads remain absent.

## Open Questions With Attempted Resolution

- Why no constructor caller? Checked ordinary xrefs, data pointers, RVA/VA constants, rel32 calls/jumps, startup/factory/menu-command paths, vtables, globals, and old reports. Best resolution: retained linked source without a surviving entry route. This caps confidence but does not block source.
- Was the slot initialized to `-1`? Checked live bytes and PE raw/virtual mapping. Resolution: no; it is loader-zeroed, and old `ff` evidence is superseded.
- Is the clear handwritten? Checked RTTI PMD, ctor adjustment, EH xref, wrapper order, and same-pattern comparator. Resolution: no; direct Singleton base causes it.
- Is an explicit Staffs destructor required? Removed compiler/base work and found no authored remainder. Resolution: omit it.
- Is the action method `OnDialogAction`? Checked exact inherited vtable slot and current DialogPane declaration. Resolution: `OnControlCommand(int,int)`.
- What names the event bit? Checked helper body and current EventMan API. Resolution: use `GetModifierState` and literal `0x02`; no stronger enum name is defensible.
- Is `STAFF.EPF` an array or pointer? Checked `.data` slot, literal, and xrefs. Resolution: file-local mutable pointer to const wide characters.
- Remaining uncertainty: original lexical spellings and missing resource payloads. Neither changes exact behavior, ownership, formal C++, or metadata disposition.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Callback-completion read-only manual hashes:
  - `by-memory/-coverage-report.md`: SHA256 `60BBCA2FB98496CBAFCCE13126EAAD3482451D0105469916404B8936822B8E7D`, 1,921,168 bytes / 4,487 lines. The Gate 1 SHA256 `F58C92FA4B1082A51AECC942BDF9467819F4FE44D594F10062BA7F6C1D3C01ED` and earlier SHA256 `69DAD2B0004C9BB609E78B3F3A7EDF5191340AAD98F4BCD37ACC8B0E95052767` are historical evidence-time provenance; every UID0001PT-scope row below was reread from the current file and remains unapplied.
  - `by-global/-coverage-report.md`: SHA256 `0C2533250EAD5038B464B6C104730C21054E36E49D1C8865C30D2BEC976A0732`, 95,363 bytes / 214 lines.
  - `by-class/-coverage-report.md`: SHA256 `F805ACBF02650ED517F0E969D365275AA284A442DCDB569F00919BE3FC0E6AA0`, 249,506 bytes / 623 lines.
  - `by-file/-coverage-report.md`: SHA256 `1F89FD7F25F02035BCB0572B30F8CE6091B36E730335D6D6E42EA3EADB1C62E8`, 146,478 bytes / 316 lines.
  - `by-resource/-coverage-report.md`: SHA256 `EF28BB82AE827E585B5F85E3F45D590A665C54095C2767CF970820493FA1DD72`, 16,981 bytes / 50 lines.
  - `by-type/by-vtable/-coverage-report.md`: SHA256 `E4E68E13401E2E05867FFD0A4485C53B93DD2C0A8FDF66148960244DD05D5F3A`, 65,118 bytes / 142 lines.
- These snapshots are mutable supervisor-owned evidence. B001 did not edit them. Current readback confirms the accepted replacement/insertion rows below remain absent and pending supervisor application; UID0001RM remains present once with the quoted unchanged text.

Replace the current UID0001PT by-memory row in place with:

```text
    - [UID:0001PT][0x0069b490-0x0069b494.g_pStaffsDialog](by-memory/0x0069b490-0x0069b494.g_pStaffsDialog.md) 0x0069b490-0x0069b494 | loader-zero physical singleton slot | g_pStaffsDialog physical storage : not_reconstructable : 92% : very-strong : Exact four-byte PE loader-zeroed StaffsDialogPane pointer storage with SHA256 DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119, four write-only Singleton lifecycle refs across constructor, cleanup helper, and destructor, no raw initializer/read route, semantic definition UID0000SC, and blank physical emitter/formal C++; preserves the 2026-06-06 live-IDA lifecycle evidence while superseding its stale initialized-data characterization with exact PE zero-fill proof.
```

Replace the current UID00019Z by-memory row in place with:

```text
    - [UID:00019Z][0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore](by-memory/0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore.md) 0x004ffaa0-0x004ffd3d | class method cluster | StaffsDialogPaneCore : reconstructable : 92% : very-strong : Exact source-ready StaffsDialogPane constructor and OnControlCommand cluster with singleton and DialogPane/Singleton initialization, STAFF.EPF/NPAL8.PAL resources, EventMan modifier bit 0x02 STAFFS2/STAFFS selection, controls, close control, overlay-layer attachment, g_pMainMenuPane show parent, exact boundaries/ranges/hashes, absent direct constructor route, and compiler publication/vptr/EH/destructor exclusions; supersedes only the generic historical action spelling.
```

Replace the UID0001A9 row and path in place with:

```text
    - [UID:0001A9][0x00502410-0x0050241b.StaffsDialogPaneSingletonBaseDestructor](by-memory/0x00502410-0x0050241b.StaffsDialogPaneSingletonBaseDestructor.md) 0x00502410-0x0050241b | compiler Singleton base destructor | StaffsDialogPaneSingletonBaseDestructor : ignored : 92% : very-strong : Live IDA confirms the exact eleven-byte Singleton<StaffsDialogPane> base-destructor instantiation, constructor-unwind context, one constructor-EH xref, sole typed singleton/global clear, direct +0x26c RTTI/EBO cause, no ordinary caller or callee, and blank non-emitting formal C++.
```

Replace the UID0001AE row in place with:

```text
    - [UID:0001AE][0x00502592-0x005025a8.StaffsDialogPaneDestructorThunks](by-memory/0x00502592-0x005025a8.StaffsDialogPaneDestructorThunks.md) 0x00502592-0x005025a8 | compiler destructor adjustor thunks | StaffsDialogPaneDestructorThunks : ignored : 92% : very-strong : Live IDA confirms the exact two eleven-byte -0xa0/-0xa4 receiver-adjusting vtable thunks to the StaffsDialogPane scalar deleting wrapper, with both vtable refs, both deleting-wrapper code refs, no ordinary callers, primary/secondary/tertiary class-layout proof, and blank non-emitting formal C++.
```

Replace the UID0001AJ row and path in place with:

```text
    - [UID:0001AJ][0x00502cc0-0x00502d05.StaffsDialogPaneScalarDeletingDestructor](by-memory/0x00502cc0-0x00502d05.StaffsDialogPaneScalarDeletingDestructor.md) 0x00502cc0-0x00502d05 | compiler scalar deleting destructor | StaffsDialogPaneScalarDeletingDestructor : ignored : 92% : very-strong : Live IDA confirms the exact 69-byte compiler scalar deleting wrapper, implicit Singleton clear, DialogPane base cleanup/teardown, delete-flag and conditional-free ABI, primary vtable ref plus two adjusted thunk code routes, exact trailing 0x00502d05-0x00502d10 alignment boundary, no unique authored destructor statement, and blank non-emitting formal C++.
```

Insert the new physical vtable row as an eight-space-indented direct physical child of UID00025Q, immediately after the ScrolledPicture child ending at `0x0061d930` and before the HistoryViewing child starting at `0x0061d9cc`. D9 carries `Nested:0` and real validator-issued UID0004VJ. The manual row's physical indentation does not change semantic `CANONICAL_OWNER:0000DY`:

```text
        - [UID:0004VJ][0x0061d930-0x0061d9cc.StaffsDialogPaneVtableData](by-memory/0x0061d930-0x0061d9cc.StaffsDialogPaneVtableData.md) 0x0061d930-0x0061d9cc | compiler vtable/RTTI data | StaffsDialogPaneVtableData : not_reconstructable : 92% : very-strong : Exact 156-byte three-view StaffsDialogPane vtable cluster physically contained by mixed index UID00025Q and semantically owned by class UID0000DY, with Nested 0, primary/secondary/tertiary locator bases, scalar wrapper and -0xa0/-0xa4 adjustor slots, OnControlCommand at primary +0x48, constructor stores, eight-entry RTTI hierarchy, direct Singleton +0x26c EBO, exact predecessor/successor boundaries, and blank non-emitting C++.
```

Replace UID00025Q broad row in place with the following. The complete current row through "each exact child carries its own owner and rebuild disposition" is retained verbatim; only the final appended sentence adds the accepted ScrolledPicture/Staffs/History child facts:

```text
    - [UID:00025Q][0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData](by-memory/0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md) 0x0061d264-0x0061e5b4 | mixed read-only data index | MainMenuNewUserReadOnlyData : ignored : 86% : very-strong : Exact mixed-owner non-emitting index with current boundaries/resources and exact nested vtable children, including NewUserDialogPane vtable data 0x0061d2ec-0x0061d384 before the LoginDialogPane successor; each exact child carries its own owner and rebuild disposition. Additional exact child facts preserve ScrolledPictureControlPane at 0x0061d88c-0x0061d930, add physically nested StaffsDialogPane vtable data 0x0061d930-0x0061d9cc with semantic owner UID0000DY, and retain HistoryViewingPane as the successor owner beginning at 0x0061d9cc.
```

Replace UID00027M in place with:

```text
    - [UID:00027M][0x0066db44-0x0066db48.StaffsDialogEpfResourcePointer](by-memory/0x0066db44-0x0066db48.StaffsDialogEpfResourcePointer.md) 0x0066db44-0x0066db48 | physical resource pointer | StaffsDialogEpfResourcePointer storage : not_reconstructable : 92% : very-strong : Exact mutable .data pointer value 0x0061e484 to UTF-16 STAFF.EPF, five StaffsDialogPane constructor refs, literal-only pointer-slot xref, retained direct semantic parent UID0002ZI routed to source owner UID0000O3, predecessor StartupLogoBinkRestartFlag and successor MapPane CMAP pointer boundaries, and blank physical emitter/formal C++ under one-definition policy; preserves the 2026-06-07 A010 Batch077 parent/source-route provenance while superseding physical reconstruction.
```

Replace UID0000SC by-global row in place with:

```text
- [UID:0000SC][g_pStaffsDialog](by-global/g_pStaffsDialog.md) : reconstructable : 92% : very-strong : Sole external StaffsDialogPane pointer definition in login/StaffsDialogPane.cpp with NULL initializer, exact loader-zero physical child UID0001PT at 92/94, four write-only direct-Singleton lifetime refs across the exact constructor/action/helper/scalar-wrapper function bounds, retained C001 2026-06-16 refresh and saved IDA function-rename provenance, +0x26c RTTI/EBO source cause, absent constructor route as a confidence cap, no duplicate physical emitter, and resolved declaration/linkage/source placement.
```

Replace UID0002ZI by-global row in place with:

```text
- [UID:0002ZI][StaffsDialogEpfResourcePointer](by-global/StaffsDialogEpfResourcePointer.md) : reconstructable : 92% : very-strong : Sole file-local static const-wchar_t pointer definition kStaffsDialogEpfName = L"STAFF.EPF" in StaffsDialogPane.cpp, with exact physical child UID00027M, source owner UID0000O3, 0x0061e484 UTF-16 literal, five constructor refs, literal-only pointer-slot xref, split adjacent CMAP neighbor, source position 5, and one-definition/non-emitting physical-storage closure; preserves the 2026-06-07 A010 Batch077 AUTOGEN_PARENT_UID routing provenance while superseding its earlier score cap.
```

Replace UID0000DY by-class row in place with:

```text
- [UID:0000DY][StaffsDialogPane](by-class/StaffsDialogPane.md) : reconstructable : 92% : very-strong : Live IDA-backed complete fieldless DialogPane plus direct Singleton<StaffsDialogPane> declaration at size 0x26c with constructor, protected OnControlCommand(int,int), implicit virtual destructor, exact action/destructor/thunk evidence across +0/+0xa0/+0xa4 vtable views, +0x26c EBO/RTTI hierarchy, compiler-helper/wrapper exclusions, singleton lifetime, resource/global ownership, and login source route.
```

Replace UID0000O3 by-file row in place with:

```text
- [UID:0000O3][StaffsDialogPane](by-file/StaffsDialogPane.md) : reconstructable : 92% : very-strong : Complete NexusTK/login/StaffsDialogPane.cpp union with sole g_pStaffsDialog and STAFF.EPF pointer definitions, complete fieldless DialogPane/Singleton-derived class, source-ready constructor and OnControlCommand, exact global/resource/class/method order, pre-login staff/credits role, resource dependencies, live function/xref evidence, retained-source zero-route caveat, and non-emitting Singleton/EH/thunk/scalar/vtable/RTTI physical artifacts; preserves the 2026-06-07 A010 Batch077 UID0002ZI parent-routing/migration provenance while superseding its earlier score cap.
```

Insert this real-UID row alphabetically in `by-type/by-vtable/-coverage-report.md`:

```text
- [UID:0004VK][StaffsDialogPaneVtables](by-type/by-vtable/StaffsDialogPaneVtables.md) : ignored : 92% : very-strong : Non-emitting compiler-generated StaffsDialogPane primary/secondary/tertiary vtable and RTTI inventory for exact 0x0061d930-0x0061d9cc backing data, with scalar/adjustor/OnControlCommand cells, constructor stores, eight-entry DialogPane/Singleton hierarchy, direct +0x26c EBO, exact boundaries, and class-declaration regeneration without handwritten tables.
```

The current UID0001RM by-resource row remains exact and requires no edit:

```text
- [UID:0001RM][staff-dialog-resources](by-resource/staff-dialog-resources.md) : reconstructable : 87% : strong : Staff credits dialog resources with `STAFF.EPF` pointer-route evidence, `STAFFS`/`STAFFS2` text switch, refreshed `NPAL8.PAL` shared-palette xref count and staff constructor hit, frame/palette/text/close-control role matrix, forced-inform `DLGSTAFF.*` exclusion, source-versus-payload rebuild boundary, current `bint2.dat` `NPAL8.PAL` `DLPalette` provenance, and corrected archive/loose/raw scan classifying `STAFF.EPF`/`STAFFS`/`STAFFS2` as UTF-16 executable-literal-only blockers in the audited package while event-flag/shared-palette questions remain.
```

- Tracker rows are validator-owned and receive no manual text.
- Reason B001 does not apply these rows: all manual `-coverage-report.md` files are supervisor-owned and may be synchronized only after implementation verification.

No-loss manual-row recheck:

| Row | Current valid detail preserved in proposed text | Accepted closure appended |
| --- | --- | --- |
| UID0001PT | exact range, global-pointer role, four lifecycle xrefs, StaffsDialogPane identity, 2026-06-06 evidence provenance | loader-zero hash, false physical disposition, semantic definition; stale initialized-data characterization explicitly superseded |
| UID00019Z | singleton, `STAFF.EPF`/`NPAL8.PAL`, `STAFFS`/`STAFFS2`, controls, layer, `g_pMainMenuPane`, close behavior, boundaries, source-ready body | exact APIs, hashes, source/compiler exclusions; generic action spelling superseded |
| UID0001A9 | exact helper range, sole clear, EH xref, no caller/callee, live-IDA provenance | renamed Singleton base-destructor identity and `+0x26c` cause |
| UID0001AE | exact two thunks, vtable refs, deleting-wrapper refs, receiver adjustments, no ordinary callers, live-IDA provenance | class-owned compiler no-code disposition |
| UID0001AJ | exact range, clear, base teardown, flags, primary/thunk routes, trailing padding, live-IDA provenance | scalar-wrapper rename and no-authored-destructor closure |
| UID00025Q | complete current row is a literal prefix, including NewUserDialogPane before LoginDialogPane and per-child ownership | ScrolledPicture/Staffs/History facts appended only |
| UID00027M | direct UID0002ZI parent, UID0000O3 route, target, five refs, literal-only xref, split neighbors, 2026-06-07 A010 provenance | false physical one-definition disposition |
| UID0000SC | four-ref lifecycle, function family/bounds context, matching child, C001 2026-06-16 and saved-rename provenance, route caveat | sole typed definition and resolved placement |
| UID0002ZI | UID0000O3 parent route, UID00027M child, literal, five refs, literal-only xref, split CMAP neighbor, 2026-06-07 A010 provenance | exact file-local definition and position |
| UID0000DY | method family, singleton lifetime, action/destructor/thunk vtable evidence, compiler exclusions, login route, live-IDA provenance | complete declaration, EBO, implicit destructor |
| UID0000O3 | pre-login role, source ownership, resource pointer/dependencies, compiler exclusions, vtable refs, singleton lifetime, 2026-06-07 A010 provenance | complete no-loss source order/union |
| new D9/D10 | no current row exists | exact issued-UID insertions after callback registration |
| UID0001RM | exact current row quoted verbatim | no manual edit required |

## Follow-Up Actions

- Supervisor actions: independently review the terminal callback artifact and, if accepted, apply the exact still-pending manual coverage handoff. Coverage application and report validation/execution/count/path/move/archive state remain external supervisor/validator-owned.
- A-agent actions: none.
- B001 callback actions: complete. D1-D15 were implemented and validated, D16 was verified unchanged, both real UIDs were registered serially, the final waited refresh/readback passed, and no B001 work remains.
- Report validation/execution/count/path/move/archive state remains external supervisor/validator-owned and is neither asserted nor directed by this artifact.

## Confidence

- Recommendation confidence: very strong.
- Score confidence: very strong for D1/D2/D5-D13; high for D3/D4 because direct constructor route and original lexical symbols are absent.
- Remaining uncertainty: original source spellings and unavailable resource payloads only. Exact behavior, ownership, source placement, and compiler/data exclusions are closed.

## Validator Results

- MCP health and bounded research calls succeeded on live database `9b0396a3`; no callback-time binary uncertainty required mutation or a replacement query.
- Registration/initial ordinary validators, all exit `0`, `ok:1` unless noted, generated deferred unless noted:
  - D9 registration `000000016007`, `2026-07-21T16:39:20-04:00`, issued UID0004VJ; D9 correction `000000016008`, `2026-07-21T16:40:09-04:00`, exact physical page validated.
  - D10 registration `000000016010`, `2026-07-21T16:41:13-04:00`, issued UID0004VK.
  - D1 `000000016013`, `2026-07-21T16:42:42-04:00`; D2 `000000016015`, `2026-07-21T16:43:59-04:00`; D3 `000000016017`, `2026-07-21T16:45:42-04:00`; D4 `000000016022`, `2026-07-21T16:47:27-04:00`; D5 `000000016026`, `2026-07-21T16:50:24-04:00`.
  - D6 default rename validation `000000016028`, `2026-07-21T16:51:11-04:00`, exited `1` because validator cross-reference propagation attempted the protected supervisor-owned `by-memory/-coverage-report.md` and received `WinError 5 Access is denied`; no manual coverage edit occurred. Documented `--uid-only` rename command `000000016030`, `2026-07-21T16:51:44-04:00`, exited `0`, `ok:1`, updated UID0001A9's path/metadata and skipped generation; full scoped D6 command `000000016053`, `2026-07-21T16:58:09-04:00`, then exited `0`, `ok:1` with generation deferred.
  - D7 initial `000000016032`, `2026-07-21T16:52:11-04:00`, then post-D8-link correction `000000016039`, `2026-07-21T16:53:55-04:00`, both exit `0`, `ok:1`.
  - D8 documented `--uid-only` rename command `000000016035`, `2026-07-21T16:53:03-04:00`, exit `0`, `ok:1`, updated UID0001AJ path/metadata and skipped generation; full scoped command `000000016037`, `2026-07-21T16:53:35-04:00`, exit `0`, `ok:1`.
  - D11 `000000016042`, `2026-07-21T16:55:31-04:00`, exit `0`, `ok:1`, with one pre-existing missing UID00036V warning; D12 `000000016044`, `2026-07-21T16:55:57-04:00`; D13 `000000016046`, `2026-07-21T16:56:33-04:00`; D14 `000000016048`, `2026-07-21T16:57:11-04:00`; D15 `000000016051`, `2026-07-21T16:57:54-04:00`, exit `0`, `ok:1`, with 234 pre-existing missing-ref warnings (224 suppressed).
  - Final current-state corrections after whole-destination self-audit: D12 `000000016094`, `2026-07-21T17:14:40-04:00`; D13 `000000016096`, `2026-07-21T17:15:03-04:00`; D11 `000000016098`, `2026-07-21T17:15:30-04:00`, with the same one pre-existing UID00036V warning. Each exited `0`, `ok:1`, generation deferred.
- Initial waited target command `000000016069`, `2026-07-21T17:02:21-04:00`, and final waited target command `000000016100`, `2026-07-21T17:15:43-04:00`, each ran `python tools/validator.py --mode file --file by-memory/0x0069b490-0x0069b494.g_pStaffsDialog.md --apply --wait-generated`, exited `0`, `ok:1`, and completed generated refresh. Command 16100 is terminal callback proof. Its project-wide generated side effects were validator-owned metadata refresh plus pre-existing aggregate warnings: 13 `autogen_children_fallback_insert`, 76 `autogen_children_marker_missing`, and 121 `autogen_emitter_has_no_code`; none is a Staffs target error.
- Generated `auto-generated/NexusTK/login/StaffsDialogPane.cpp`: current B001 command/header `000000016100`, refreshed `2026-07-21T17:15:43-04:00`, SHA256 `31A80B2C5875DC31ABF1BA1255018BE99DE8EDE0881164F3A1BF703F9E530E1B`, 2,626 bytes / 79 lines. Historical callback command 16069/hash `050B8735...34F2` and external command 16091/hash `02F90DFE...4DA3` have the identical 75-line body and differ only in validator header freshness. Current counts are one each for UID0000SC, UID0002ZI, UID0000DY, UID00019Z, global definition, resource-pointer definition, class declaration, constructor, and `OnControlCommand`; zero for UID0001PT/UID0001A9/UID0001AE/UID0001AJ markers, explicit destructor, `g_pStaffsDialog = this`, extra clear assignment, `OnDialogAction`, `GetCurrentEventFlags`, invented event constant, vague `g_mainUiLayer`, Empty Emitter Marker, raw vtable/RTTI, or duplicate. Source order byte offsets remain UID0000SC `318`, UID0002ZI `489`, UID0000DY `667`, UID00019Z `990`.
- Final read-only tracker snapshot observed validator-owned `auto-generated/-ag-research-tracker.md` at unrelated deferred command `000000016102`, refreshed `2026-07-21T17:18:11-04:00`, SHA256 `3234D4A35582E5ABC307B5E9CE5AA4CD147C95F5E4CA00AF60EFCB5EC106D2A0`, 1,550,872 bytes / 6,274 lines. Commands 16072/16091/16098 are historical intermediate epochs; this and any later unrelated tracker epoch do not alter command-16100 Staffs source proof.

## Changed Files

- Modified D1 `by-memory/0x0069b490-0x0069b494.g_pStaffsDialog.md`: SHA256 `934B46686FB6E8D0311A23517DC1729B46A9C7294DA2BDC47DB780BDCD9AF0B0`, 9,154 bytes / 84 lines.
- Modified D2 `by-global/g_pStaffsDialog.md`: SHA256 `EBA1107A6DC9AA8059BDBFE36F86079951F9DA91AC6847780BCEE3CF6724163C`, 10,102 bytes / 91 lines.
- Modified D3 `by-class/StaffsDialogPane.md`: SHA256 `1B5E6971A095190BBFC03D0714B91324083D599A374571E34102B025F1DC0334`, 16,426 bytes / 137 lines.
- Modified D4 `by-file/StaffsDialogPane.md`: SHA256 `3A3110DD1667ECB2EA6C50B5832C80402C8DC18813EEF088736BBBC7CFB94AB2`, 18,422 bytes / 131 lines.
- Modified D5 `by-memory/0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore.md`: SHA256 `3BADB5175A6804EB7493DC73EBCA0DAE021708377E9F85B2DE4A5D4B5C1A5BD8`, 14,862 bytes / 156 lines.
- UID-preserving D6 rename/current path `by-memory/0x00502410-0x0050241b.StaffsDialogPaneSingletonBaseDestructor.md`: SHA256 `027454EBCA51D89F0BE8E562C8BE505564CF358E60AA6521B7C95AD049B5AE44`, 4,813 bytes / 61 lines; old `StaffsDialogPaneSingletonClear.md` path absent.
- Modified D7 `by-memory/0x00502592-0x005025a8.StaffsDialogPaneDestructorThunks.md`: SHA256 `133FBD6328F3C5F2C7CBFC8D947ED44689B5DE4746971A2E269528D61CF00719`, 4,697 bytes / 65 lines.
- UID-preserving D8 rename/current path `by-memory/0x00502cc0-0x00502d05.StaffsDialogPaneScalarDeletingDestructor.md`: SHA256 `3435B0F5EA60CFA77B9643BC15ACBF05C88050AA9783A9E5A77856D92A9061CF`, 7,658 bytes / 73 lines; old `StaffsDialogPaneDestructor.md` path absent.
- Created/registered D9 UID0004VJ `by-memory/0x0061d930-0x0061d9cc.StaffsDialogPaneVtableData.md`: SHA256 `16923E3277222BEC975541B2819AF0975A8C429BA4FBB64F522D5960CF373060`, 9,090 bytes / 96 lines.
- Created/registered D10 UID0004VK `by-type/by-vtable/StaffsDialogPaneVtables.md`: SHA256 `2D8FF137BAB37279F4BF2377E62E0F4E5EA740AECAFF5A2E01973944D7813AB8`, 8,096 bytes / 101 lines.
- Modified D11 `by-memory/0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md`: SHA256 `FB49B7F81C1F818ACA859534FFD699278BA062F5D222C9FA521F2926041531C9`, 32,275 bytes / 185 lines.
- Modified D12 `by-global/StaffsDialogEpfResourcePointer.md`: SHA256 `055DA8AFEB6D223A35ECB4E9BD02DA72D8F403E1FF4615B2587CD50A0D704C61`, 5,559 bytes / 63 lines.
- Modified D13 `by-memory/0x0066db44-0x0066db48.StaffsDialogEpfResourcePointer.md`: SHA256 `714B2F9F7BF539D3ED15A19961E4D3FA64DC7749EA84AE63E37AC6DC326D3223`, 7,273 bytes / 76 lines.
- Modified D14 `by-resource/staff-dialog-resources.md`: SHA256 `2B2D443808AE4C85BC8E1F93C2E1C2AAFE164BD2C489BAA80516EC5077AC8971`, 15,789 bytes / 134 lines.
- Modified D15 `by-memory/-ignored.md`: SHA256 `88847D175F657AC6D8FE13C153B2C32DAC2245093E1F104AB2CEFE2D93AC65A2`, 1,100,053 bytes / 5,339 lines.
- Verified-only D16 unchanged: `by-class/MainMenuPane.md` SHA256 `520E7A713CF5001E4317C3BE8FCFF09C13D4EA160CBE5537395F6F92C20DB7EA`, 35,103 bytes / 206 lines; `by-file/MainMenuPane.md` SHA256 `3C41D148F5C4A44D6C2BFA41BA70EDF8270CD83298C9C9340E97247065011AA6`, 45,064 bytes / 222 lines. Both retain concrete `g_pMainMenuPane` and separate `0x0069b36c` layer/context facts.
- This same report is the only non-ordinary file edited by B001. Manual coverage, generated/tracker, audit/supervisor, validator-state, IDA, and lifecycle/archive files were not manually edited. B001 did not execute, move, or archive the report.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor exact-artifact Gate 1 validation completed.
- [x] D1 target physical-slot metadata, PE mapping, bytes, refs, history, and blank formal applied.
- [x] D2 semantic global definition, type, linkage, initializer, order, and one-definition evidence applied.
- [x] D3 complete class declaration, bases, EBO, size, virtual identity, implicit destructor, and children applied.
- [x] D4 source file score, order, owner union, retained-source caveat, dependencies, and exclusions applied.
- [x] D5 exact constructor/OnControlCommand formal, ranges, hashes, APIs, resources, and compiler exclusions applied.
- [x] D6 validator-aware UID0001A9 rename and Singleton base-destructor disposition applied.
- [x] D7 adjustor-thunk class-owned compiler disposition applied.
- [x] D8 validator-aware UID0001AJ rename and scalar-wrapper disposition applied.
- [x] D9 physical vtable page created and registered with a real validator UID, `Nested:0`, physical container UID00025Q, and canonical owner UID0000DY.
- [x] D10 semantic vtable page created and registered with a real validator UID.
- [x] Both provisional UID tokens replaced everywhere before any dependent links or manual rows are finalized.
- [x] D11 broad read-only aggregate exact Staffs child inventory added after the complete current UID00025Q row prefix without losing the NewUserDialogPane-before-LoginDialogPane fact.
- [x] D12 sole file-local STAFF.EPF pointer definition and source evidence applied.
- [x] D13 physical resource pointer non-emitting disposition applied.
- [x] D14 resource support synchronized without score/payload-history loss.
- [x] D15 exact lines 1348-1352, 1376, 1384, and 1388 replaced from the literal blocks above; all four UID0001A9/UID0001AJ references, ranges, evidence, owner links, and padding facts independently reread.
- [x] D16 MainMenu class/file verify-only union rechecked and preserved.
- [x] C1PT-001 through C1PT-100 accepted/rejected claim by claim.
- [x] Every accepted target/support fact incorporated at report-level detail.
- [x] Metadata/score/owner/emitter/reconstructable/position changes applied exactly.
- [x] No unauthorized target split, padding row, standalone source file, or raw compiler table created.
- [x] All 12 destination managed blocks applied exactly; no proposed C++ left prose-only.
- [x] Historical `ff`, explicit publish/destructor, stale action/helper/layer names, and polluted labels preserved only as superseded history.
- [x] Negative evidence and rejected alternatives preserved.
- [x] Resource payload blockers preserved outside source closure.
- [x] One short lease held only around each ordinary edit and released immediately after scoped validation.
- [x] One scoped validator run for every changed ordinary by-* page.
- [x] Final waited target validation run after all ordinary leases clear.
- [x] Generated StaffsDialogPane.cpp contains one global definition.
- [x] Generated StaffsDialogPane.cpp contains one file-local STAFF.EPF pointer definition.
- [x] Generated StaffsDialogPane.cpp contains one complete class declaration.
- [x] Generated StaffsDialogPane.cpp contains one constructor and one OnControlCommand definition.
- [x] Generated output contains zero explicit Staffs destructor, explicit singleton publish/clear, `OnDialogAction`, `GetCurrentEventFlags`, fake event constant, or vague `g_mainUiLayer`.
- [x] Generated output contains zero UID0001PT/UID0001A9/UID0001AE/UID0001AJ/vtable physical markers or Empty Emitter Markers.
- [x] Generated output contains no raw vtable/RTTI/EH/thunk/scalar-delete body or duplicate.
- [x] Exact generated command/header/hash/count/order assertions recorded.
- [x] Every proposed manual row independently no-loss compared to the current row; exact supervisor-owned text retained and updated with real UIDs.
- [x] No B001 manual coverage, tracker, generated, audit, supervisor, validator-state, IDA, execute, move, archive, or lifecycle edit/action occurred.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation.
- [x] Every accepted D1-D16 detail incorporated without compression or unrelated loss.
- [x] Every C1PT ledger row converted from `proposed` to a legal terminal callback state.
- [x] Destination-specific proof recorded for every claim.
- [x] Every current destination reread after lease and concurrent changes rebased.
- [x] Both new pages registered serially and all links use real issued UIDs.
- [x] Every changed ordinary page scoped-validated and command/timestamp/exit/ok/warnings recorded.
- [x] Every ordinary lease released immediately after its scoped validation.
- [x] Final waited generated refresh/readback completed.
- [x] Exact changed-file hashes, sizes, lines, formals, and generated assertions recorded.
- [x] Exact manual coverage handoff remains supervisor-owned.
- [x] Remaining unapplied accepted claim, if any, listed with exact blocker.
- [x] Zero B001 leases remain.

READY_FOR_SUPERVISOR_GATE2_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000016123","destination_path":"executed-b-agent-research/B001/0001PT-g_pStaffsDialog-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/0001PT-g_pStaffsDialog-source-quality.md","timestamp":"2026-07-21T17:40:02-04:00","uid":"0001PT"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
