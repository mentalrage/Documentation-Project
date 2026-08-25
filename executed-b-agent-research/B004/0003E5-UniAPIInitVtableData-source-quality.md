** TARGET-REPORT-UID:0003E5 **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

# UID0003E5 UniAPIInitVtableData Ownership / Split Research

## Finalized Report / Current Recommendation

- Current implemented state: the exact half-open `[0x0062e578,0x0062e580)` child retains `Nested:8` and direct semantic owner UID0000FE `UniAPIInit`, is `94/96`, and is `RECONSTRUCTABLE:FALSE` with blank emitter, position, and formal C++. Its eight bytes are compiler-emitted MSVC RTTI/vtable data, not a source declaration or handwritten table.
- Final disposition: `0x0062e578` is the pointer immediately preceding the vtable address point and names the `UniAPIInit` complete-object locator at `0x00651a2c`; `0x0062e57c` is the one-slot `??_7UniAPIInit@@6B@` address point whose sole entry is scalar deleting destructor `0x00599a10`. The source causes are the `UniAPIInit` class declaration, an out-of-line constructor, an out-of-line empty virtual destructor, and one file-local static object in `NexusTK/platform/PlatformApi.cpp`.
- Callback result: after exact-artifact supervisor Gate 1 acceptance, B004 applied C01-C44 and the destination-specific formal blocks. The four exact UID0001KE children were registered serially as UID0004N6, UID0004N7, UID0004N8, and UID0004N9 before cross-references were added; all bounded support pages were then synchronized. No manual RTTI, vtable dword, vptr store, deleting-destructor, cleanup-wrapper, or startup-wrapper source was introduced.
- Confidence: very strong for every target byte, both boundaries, full RTTI hierarchy, one-slot virtual contract, all direct/interior xrefs, compiler-data disposition, class name, source file, and ordinary/scalar destructor relationship; strong for the inferred file-local variable spelling and public access spelling. The absent original PDB and original source cap completion below 95 and do not leave any implementation choice unresolved.

## Supporting Research

- Assignment source: current B004 `goal.md` selected UID0003E5 from the generated `Not-Covered Files - Reconstructable` row at `85/91`, combined `88.0`, report count `0`. That row is an evidence-time queue snapshot, not permanent post-callback truth.
- Mandatory live MCP evidence was collected through `http://127.0.0.1:13337/mcp`. Evidence-time `idb_list` returned the single active/adopted session `supervisor_nexustk_20260713` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; evidence-time `server_health` returned `status=ok`, image base `0x00400000`, input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, auto-analysis ready, Hex-Rays ready, and string cache ready with 2067 entries. Bounded IDB-backed byte, function, disassembly, decompile, and xref calls succeeded. This records evidence-time health and does not assert indefinite session availability.
- Input identity independently checked read-only: size `2,679,296`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, SHA256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
- Exact old-report search terms: `UID0003E5`, `UID:0003E5`, `0x0062e578`, `0x0062e57c`, `UniAPIInitVtableData`, `UniAPIInit`, `0x00599a10`, `0x006702c4`, `0x0060c440`, `PlatformApi`, `scalar deleting destructor`, and `complete object locator`.
- Evidence-time active report roots `tools/leaser/Agents/Agent-B001/research` through `Agent-B005/research`: no matching report. B004's assigned `goal.md` was assignment metadata, not prior exact-target research.
- `tools/leaser/Agents/Older-Research/**`: no match for the exact UID/address/name terms. `tools/leaser/Agents/SpecialReports/**`: no match. No separate `archived-b-agent-research` root exists in the current tree.
- Direct/relevant executed reports opened and classified:
  - `executed-b-agent-research/B007/0000FE-UniAPIInit-class-source-quality.md`: accepted the exact class/static-object model and declaration but did not decode the complete COL/type/base hierarchy or repair the constructor/destructor definitions that were missing from the evidence-time generated output.
  - `executed-b-agent-research/B014/0001KE-UniAPIInit-source-quality.md`: supplied the valid seven-part executable-island split and no-route evidence. Its prior defer was conditional on exact child creation and finalized dispatch declarations; those conditions are now resolved, so the retained constructor-shaped body can become an exact source-bearing child while the duplicate and deleting wrapper remain non-emitting.
  - `executed-b-agent-research/B015/0000WD-WideApiDispatchInit-source-quality.md`: confirmed the sole live startup-table route and compiler-wrapper no-code policy. It did not emit a source constructor and therefore left the evidence-time generated output link-incomplete.
  - `executed-b-agent-research/B004/00026R-TransferServerReadOnlyData-source-quality.md`: direct predecessor/boundary lead. It correctly moved UID0003E5's start to `0x0062e578` and set `Nested:8`, but expressly did not perform dedicated target RTTI/source-quality research.
  - `executed-b-agent-research/B011/0002P0-UrlAlertPaneVtableData-source-quality.md` and `B011/0001KF-UrlAlertPane-source-quality.md`: successor-only evidence. They confirm `0x0062e580` belongs to `UrlAlertPane` and provide no ownership route into the target.
  - `executed-b-agent-research/B001/0002AS-WideApiDispatchPointerTable-source-quality.md`: establishes the accepted 44-slot PlatformApi declaration body used by the constructor recommendation.
- Broader executed-report matches that merely mention `UniAPIInit` as a PlatformApi dependency or adjacent range were classified as indirect leads and did not control this report.
- Read-only `source-3/third_party_embeds` inspection found only jsoncpp, libjpeg, lodepng, and zlib source families. Searches for `UniAPI`, `WideApi`, `GetVersionExA`, `ReadUtf16CodeUnitFromFile`, and the target addresses returned no match. UID0003E5 is project-owned MSVC output; no import directive applies.
- Read-only generated `auto-generated/NexusTK/platform/PlatformApi.cpp` header records validator command `000000010559` and refresh time `2026-07-13T18:45:04-04:00`. It emits the class declaration, main dispatch globals, helpers, and `static UniAPIInit s_uniAPIInit;`, but no `UniAPIInit::UniAPIInit()` or `UniAPIInit::~UniAPIInit()` definition. It emits UID0003E5, UID0000WD, and UID0001KE as empty markers. This is direct generated-output proof of the source-definition gap, not authority over binary facts.
- Post-callback generated readback is separately recorded under Validator Results. Validator command `000000010640` superseded the evidence-time generated snapshot for implementation verification: it contains exactly one class declaration, constructor definition, destructor definition, and static object, plus 47 dispatch declarations and 47 constructor assignments, with none of UID0003E5, UID0001KE, UID0000WD, UID0001O9, UID0004N8, or UID0004N9 emitted as code or an empty marker.
- One broad all-text `insn_query` exceeded the client timeout. It supplied no claim. Immediate bounded health and real target-byte checks succeeded, followed by all focused calls listed below; therefore this was a discarded overbroad query, not an MCP outage and not a basis for fallback-only research.
- Historical Wave2/Wave3 labels such as generated `~UniAPIInit` at `0x005995b0` were found in ordinary docs and old reports. They were retained only as superseded provenance and were not accepted as source names or boundary authority.

## Target

- Target UID: `0003E5`.
- Target path: `by-memory/0x0062e578-0x0062e580.UniAPIInitVtableData.md`.
- Assigned report path: `tools/leaser/Agents/Agent-B004/research/0003E5-UniAPIInitVtableData-source-quality.md`.
- Source queue/report row: evidence-time `auto-generated/-ag-research-tracker.md`, `## by-memory`, `### Not-Covered Files - Reconstructable`, `85/91`, combined `88.0`, count `0`.
- Historical pre-callback supervisor classification: report-only exact-target source-quality assignment; implementation was not authorized before Gate 1 acceptance.
- Current implemented scores and parent state: target `94/96`, owner UID0000FE, false/non-emitting, blank formal C++, `Nested:8`; direct mixed read-only parent UID00026S is `90/95`, `NONE/FALSE`, blank/non-emitting, `Nested:-8`.

## Current Target State

- Implemented metadata: exact UID and corrected eight-byte path remain valid; `CANONICAL_OWNER:0000FE` and `Nested:8` remain valid. The stale `RECONSTRUCTABLE:TRUE` plus `EMITTER_UIDS:0000FE` pair was replaced by false/non-emitting compiler-data metadata.
- Implemented owner/emitter/reconstructable state: semantic owner remains the class, not PlatformApi file root or adjacent UrlAlertPane. Compiler data is documented under the class and does not independently emit source.
- Implemented C++/emitter state: blank formal C++ remains exact under class ownership, false reconstructability, blank emitter, and exhaustive no-code proof. Constructor/destructor source now emits from UID0004N6/UID0004N7.
- Historical pre-callback open questions, blockers, placeholder names, stale assumptions, or contradictory claims, all resolved by this callback:
  - the page did not decode the COL, type descriptor, class hierarchy descriptor, base array, or base descriptor;
  - it mixed instruction/xref addresses with encoded immediate byte addresses;
  - it said only a destructor declaration was needed, while generated output lacks both required constructor and destructor definitions;
  - it retained duplicate Markdown links and historical one-dword wording;
  - it did not decide whether UID0001KE needed exact children or whether the ordinary destructor body should emit source;
  - it did not reconcile false/non-emitting compiler data with a true/empty-emitter header;
  - it did not inspect third-party embeds or manual coverage rows under the current workflow.
- Related target/support docs checked: UID00026S, UID0002P0, UID0001KE, UID0000WD, UID0001O9, UID00028B, UID0000FE, UID0000ML, UID0000TQ, UID0002AS, UID0001Q1, UID0002A6, UID0001KF, `by-memory/-coverage-report.md`, `by-class/-coverage-report.md`, `by-file/-coverage-report.md`, `by-global/-coverage-report.md`, current generated PlatformApi source, old reports, and third-party embed roots.
- Current artifact/lifecycle boundary: implementation and scoped/generated verification are complete, all B004 leases are released, and no implementation item remains. B004 performed no report execution, probe, move, or archive command. Report validation, execution, count, path, move, and archive state are external supervisor/validator-owned and are not asserted by this artifact.

## Executive Recommendation

- Implemented outcome keeps `[0x0062e578,0x0062e580)` intact. Splitting the COL pointer from the one-slot address point would create two artificial dword pages for one compiler-emitted class ABI unit and would not improve source ownership or generation.
- UID0003E5 is class-owned non-reconstructable/non-emitting compiler data at `94/96`, with `Nested:8`, exact path/title, and blank managed C++.
- Mixed aggregate UID0001KE is split into four exact children while the aggregate remains a non-emitting index: source-bearing constructor UID0004N6 `[0x005995b0,0x005997dd)`, source-bearing empty ordinary destructor UID0004N7 `[0x005997e0,0x005997e7)`, non-emitting retained duplicate initializer UID0004N8 `[0x005997f0,0x00599a0b)`, and non-emitting scalar deleting destructor UID0004N9 `[0x00599a10,0x00599a34)`. The three internal `0xcc` runs remain documented in UID0001KE, and exact UID0000VN `-ignored` manual text is supplied without creating ordinary padding pages.
- UID0000WD is non-reconstructable/non-emitting startup/static-lifetime wrapper evidence. The complete source constructor emits only from UID0004N6, not from the live wrapper or aggregate.
- The empty out-of-line destructor emits only from UID0004N7. The scalar deleting wrapper, vptr-only cleanup wrapper, vtable/COL, and object-vptr bytes do not emit handwritten source.
- The existing class declaration and static object definition are preserved, exact declarations for `SendMessageW` and the two tail dispatch globals are applied, and PlatformApi/class/global support facts are synchronized. Generated readback confirms one complete human source model without the relevant empty-marker ambiguity.

## Supervisor Active Recheck

- Historical Gate 1 instruction required a report-only UID0003E5 pass, mandatory MCP, full literal template, exhaustive blocker resolution, and improvement beyond `85/91`; it forbade by-* edits, leases, implementation validators, IDA mutation, generated/coverage/tracker/audit/lifecycle edits, and report execution. The supervisor subsequently accepted exact SHA `22B88E9EBB75DAB6CB83A8DBC947E1BFF1CF76DB0617C7A149ADF5D290B528D1` and authorized the bounded callback now recorded as complete.
- The assigned eight-byte item does not itself require a split. Its executable support aggregate does require exact children before source definitions can be emitted without pretending the mixed island is one function.
- Every source-bearing item named by the analysis has an implementation-ready disposition now: constructor child gets the complete constructor body; ordinary-destructor child gets the empty destructor definition; class and static object preserve exact source declarations. Duplicate initializer, scalar deleting wrapper, cleanup wrapper, live startup wrapper, COL, and vtable bytes have exhaustive non-emitting dispositions.

## Inference Research Guidance Check

- `by-structure.md` requires the narrowest semantic owner, separate emitter routing, final-output source rather than decompiler scaffolding, compiler/source separation, and a combined-score gate before code entry. It also defines `Nested` as a relative delta rather than a child count.
- Existing assumptions treated as uncertain or possibly wrong: current reconstructable/emitter state, one-dword historical target shape, address labels that mixed instruction starts and operands, prior decision to defer exact executable children, the claim that only a virtual declaration was needed, public access, static variable spelling, and the generated `~UniAPIInit` name at `0x005995b0`.
- Direct IDA facts: bytes, functions, symbols, RTTI fields, xrefs, ranges, and instruction operands. Documentation evidence: current by-* metadata, manual rows, old report conclusions, and generated output. Inference: public access, file-local variable spelling, and original source formatting. These categories remain separate throughout.
- Wave2/Wave3 names were found and rejected as stale where they conflict with current bytes and source shape. No current explicit override makes those artifacts authoritative.

## Heuristic / Inference Reanalysis And Validation

| Issue | Reanalysis and evidence | Resolution |
| --- | --- | --- |
| Exact target contents | Live bytes are `2c 1a 65 00 10 9a 59 00`, SHA256 `948fcf94cb71466557020f53110c9760fa68fdf07ef5ea6b1af4afff41570878`. | Two dwords only: COL pointer `0x00651a2c`, then scalar deleting destructor slot `0x00599a10`. |
| Target start | Predecessor ends exactly at `0x0062e578` after float `0x3cf5c28f`; the dword at the target start is not predecessor padding. | Preserve corrected start `0x0062e578`. |
| Target end | `0x0062e580` contains `0x00651a74`, the next class's COL pointer; `0x0062e584` contains `0x00599c00`, its first slot. | Preserve end `0x0062e580`; no overlap with UrlAlertPane. |
| COL identity | `0x00651a2c` is named `??_R4UniAPIInit@@6B@` and contains signature/offset/cdOffset all zero, type descriptor `0x00679a10`, hierarchy `0x00651a40`. | Original-proof UniAPIInit primary COL at offset zero. |
| Type/class identity | `0x00679a10` is `??_R0?AVUniAPIInit@@@8`; payload string is `.?AVUniAPIInit@@`. `V` encodes a class type. | `class UniAPIInit` is symbol-proven, not a descriptive invention. |
| Hierarchy | CHD reports one base; base array points only to `0x00651a58`; PMD is `(0,-1,0)` and descriptor points back to the same type/hierarchy. | No inheritance, one complete object view, no adjustor table or secondary vtable. |
| Vtable shape | Address point `0x0062e57c` is named `??_7UniAPIInit@@6B@` and has one slot. | One virtual member only: virtual destructor contract. |
| Slot target | `0x00599a10-0x00599a34` is a 36-byte modeled function; it resets the vptr, tests deletion flag bit 0, conditionally frees four bytes, returns `this`, and uses `ret 4`. | MSVC scalar deleting destructor, compiler ABI output, no handwritten body. |
| Ordinary destructor | `0x005997e0-0x005997e7` is exactly `mov [ecx], vftable; ret`, SHA256 `9a82628b7670ef966c093a11f481e40e335b7faa4a17ea03adf5e4518fab8196`. | Empty out-of-line `UniAPIInit::~UniAPIInit()` source definition; vptr reset is generated. |
| Object size/layout | Scalar deleting wrapper passes size 4; static storage is exactly one initialized dword; RTTI has no bases; no field access exists. | Vptr-only four-byte class, no source data members. |
| Constructor source | Retained `[0x005995b0,0x005997dd)` body uses `ECX/ESI` as `this`, writes the vptr, executes exact dispatch setup, returns `this`, and is 557 bytes with SHA256 `cacf94bcd2620c4f923fd439ed2471e7cc03c870e8e6e1e04baee87bf9acb0e2`. | Exact source-bearing out-of-line constructor child despite no current route; source semantics are independently live as an inlined startup copy. |
| Constructor liveness | `0x005995b0` has no xref and is not IDA-modeled, but live startup function `0x0041a280` has the same dispatch semantics and sole startup-table xref `0x0060d71c`. | Retained out-of-line body plus inlined live copy is the best compiler/linker explanation; no-route does not erase coherent source. |
| Duplicate initializer | `[0x005997f0,0x00599a0b)` is 539 bytes, SHA256 `3f13fb8e786a058916e0bdb6a0d20c496065ce0069098544e19a0ebb3343e9d8`, lacks `this`/vptr/atexit and has no route. | Retained duplicate projection; exact non-emitting child, not a second human helper. |
| Live startup wrapper | `0x0041a280-0x0041a4a8` is a real 552-byte function with SHA256 `6a85720401745f0a079c6ebfebedfc8f9c54a14df5e4f7f8c16a763d5e0abd31`; it registers `0x0060c440` through `_atexit`. | Compiler startup/static-lifetime wrapper around inlined constructor semantics; false/non-emitting page. |
| Static object | `0x006702c4` initially contains `0x0062e57c`, has one write xref from cleanup wrapper, and ends before unrelated bytes at `0x006702c8`. | Source is one file-local `static UniAPIInit s_uniAPIInit;`, not a raw vptr global. |
| Cleanup wrapper | `0x0060c440-0x0060c44b` only writes the vtable address back to static storage and returns; sole reference is registration at `0x0041a48d`. | Compiler-generated static cleanup thunk, false/non-emitting. |
| Address inconsistency | IDA xrefs attach to instruction starts; historical PE prose sometimes listed operand byte starts. | Use instruction/xref starts `0x5995d7`, `0x5997e0`, `0x599a1a`, `0x60c440`; separately record vtable immediate starts `0x5995d9`, `0x5997e2`, `0x599a1c`, `0x60c446`, and cleanup destination operand `0x60c442`. |
| Direct/interior xrefs | Every byte `0x62e578-0x62e57b` and `0x62e57d-0x62e57f` has zero direct xrefs; address point has exactly five. COL has one pointer ref from target. | Complete direct/interior inventory; no hidden secondary slot or overlapping object. |
| `Nested:8` | UID00026S has relative `Nested:-8` after TransferServer children, UID0003E5 enters one child level with `+8`, UID0002P0 stays there with `0`, and UID00026T returns with `-8`. | Retain `Nested:8`; it is a relative indentation delta, not eight children. |
| Public access | Original access is not encoded in RTTI. A file-scope object must be allowed to construct/destruct, and existing class form uses public constructor/destructor. | Keep `public:` as the highest-probability human source form; mark access as inferred, not PDB-proven. |
| Destructor syntax | C++11 `= default` is implausible for the target era; inline empty body is possible but weaker than the retained out-of-line seven-byte body. | Declare virtual destructor in class and emit one out-of-line empty definition. |
| Static variable name | Binary proves object shape and file-local lifetime but not spelling. Current project convention and accepted docs use `s_uniAPIInit`. | Preserve that inferred descriptive spelling; do not claim original-symbol proof. |
| Source file | Dispatch globals, helper definitions, class declaration, startup wrapper, and static object already route to UID0000ML `NexusTK/platform/PlatformApi.cpp`. | Keep one project-owned source unit; no separate `UniAPIInit.cpp`, header requirement, or third-party route. |
| Current source gap | Generated PlatformApi source declares constructor/destructor and instantiates the static object but defines neither method. | Create exact source-bearing constructor/destructor children; this resolves the link/source-quality blocker now. |
| Target C++ | Handwriting COL/vtable dwords or comments in the formal block would represent ABI output rather than developer source. | Blank target block plus false/non-emitting metadata and exhaustive proof. |

Rejected alternatives:

- Split UID0003E5 into two four-byte children: rejected because both dwords form one ABI address-point unit with one class owner and one source cause; split would add bookkeeping without source fidelity.
- Keep UID0003E5 reconstructable with an empty emitter or covered-by comment: rejected because the data is wholly compiler-generated; current project precedent uses false/non-emitting vtable pages, and a comment would pollute generated C++.
- Emit a manual `void *`, dword array, COL struct, vtable array, explicit vptr initializer, or deleting-destructor function: rejected as reverse-engineering scaffolding.
- Treat `0x00599a10` as the source destructor body: rejected by deletion-flag ABI, conditional deallocation, `ret 4`, and separate ordinary destructor body.
- Treat `0x005997e0` as compiler-only and leave no destructor definition: rejected because the source virtual destructor requires one definition and the evidence-time generated output lacked it; the human body is empty even though the binary vptr reset is generated. Current generated output now contains the accepted definition.
- Emit constructor semantics from UID0000WD: rejected because that exact function is the compiler startup wrapper and registers cleanup. The exact retained constructor-shaped child is the correct source body destination.
- Emit both raw initializer projections: rejected because only one has `this`/vptr/constructor return shape; the second is an unrouted duplicate and would duplicate source.
- Keep UID0001KE as reconstructable/empty-emitting mixed code: rejected because exact children can now represent every source-bearing and compiler-only subrange.
- Move ownership to UrlAlertPane, TransferServerDialogPane, an API consumer, or `WideApiDispatchTable`: rejected by exact boundaries, RTTI identity, and source semantics.
- Introduce a standalone `UniAPIInit.cpp` or public header: rejected because all evidence and existing route support a private PlatformApi translation-unit helper class.
- Use a `third_party_embeds/...` import: rejected because no matching embedded source exists and the class is NexusTK-specific platform glue.

## Evidence Standards Used

- Evidence types: live MCP health/session state, exact bytes, modeled functions, disassembly, Hex-Rays output, all target-byte xrefs, RTTI symbols and raw structures, constructor/destructor/cleanup bodies, startup-table route, static storage, adjacent ranges, executable hashes, current by-* docs, generated source, manual coverage rows, prior reports, and negative third-party/report searches.
- The evidence is strong enough because every target byte and boundary is directly known, the compiler symbols preserve the class/RTTI identity, all five address-point references have a single coherent lifetime interpretation, and the retained/live bodies independently corroborate the source model.
- Evidence ladder: direct bytes and symbols control exact identity/range; xrefs and function bodies control behavior/lifetime; existing docs and generated output identify synchronization gaps; source spelling/access/factoring uses bounded inference only after direct evidence. `.rdata`/RTTI and `.text`/`.data` roles are kept distinct.
- Tool limitations: no original PDB/source and no modeled IDA function at two retained starts. These limit original spelling/build provenance, not the class contract or implementation-ready source decision. The one discarded broad query does not weaken focused successful checks.

## Evidence Checked

- IDA MCP/manual-disassembly/raw-byte checks performed: fresh `idb_list`; evidence-time `server_health`; target/adjacent bytes; COL, CHD, base array, BCD, and type descriptor bytes; target/interior/COL/hierarchy/type/static-slot/startup/wrapper xrefs; function lookups at `0x5995b0`, `0x5997e0`, `0x5997f0`, `0x599a10`, and endpoints; disassembly/decompilation of ordinary destructor, scalar deleting destructor, and cleanup wrapper; bounded bytes/hashes for constructor, duplicate initializer, live startup wrapper, and padding; static slot read; exact instruction/operand reconciliation.
- by-* docs checked: target UID0003E5; parent UID00026S; successor UID0002P0; executable aggregate UID0001KE; live wrapper UID0000WD; cleanup UID0001O9; static slot UID00028B; class UID0000FE; file UID0000ML; global table UID0000TQ; main table UID0002AS; SendMessage slot UID0001Q1; tail UID0002A6; successor executable UID0001KF; relevant class/file/global/memory manual coverage rows.
- Old/generated/tracker evidence checked: the six directly relevant executed artifacts classified under Supporting Research; active B001-B005 research roots; Older-Research; SpecialReports; generated PlatformApi source and header; generated memory coverage; research tracker row; no generated file was edited.
- Third-party checks: enumerated `source-3/third_party_embeds` and searched project names, API family names, helper names, and target addresses; no direct or family match.
- Negative checks performed: all non-address-point target bytes have zero xrefs; no target-start xref; no successor overlap; no secondary RTTI base; no field/member access; no constructor/ordinary-destructor route; no route to duplicate initializer; no third-party source; no exact active/Older/Special report; no plausible handwritten ABI-data form.
- Failed, unavailable, or intentionally skipped checks during the pre-callback evidence pass: one broad text-wide `insn_query` timed out and was discarded; focused calls succeeded. No IDA mutations, validators, leases, lifecycle probes, or generated refreshes were attempted during that report-only phase. Callback validators and generated refresh are recorded separately below; B004 still performed no IDA mutation or report lifecycle command.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | Target bytes are exactly `2c 1a 65 00 10 9a 59 00` with recorded SHA256. | direct | MCP bytes and local hash | UID0003E5 Observed Contents/Evidence | incorporate | applied |
| C02 | Target range remains exactly `[0x0062e578,0x0062e580)`. | direct | predecessor/target/successor bytes | UID0003E5 Range | incorporate | applied |
| C03 | `0x0062e578` points to COL `0x00651a2c`; `0x0062e57c` is address point and slot `0x00599a10`. | direct | bytes, symbols | UID0003E5 Layout | incorporate | applied |
| C04 | COL fields are `(0,0,0,0x679a10,0x651a40)`. | direct | MCP raw RTTI bytes | UID0003E5 RTTI | incorporate | applied |
| C05 | Type descriptor proves class name `UniAPIInit`. | direct | `.?AVUniAPIInit@@` | UID0003E5; UID0000FE | incorporate | applied |
| C06 | Hierarchy has exactly one self base with PMD `(0,-1,0)` and no inheritance. | direct | CHD/base array/BCD | UID0003E5; UID0000FE | incorporate | applied |
| C07 | One-slot vtable proves one virtual destructor contract and no other virtual method. | very strong | vtable size/slot target | UID0003E5; UID0000FE | incorporate | applied |
| C08 | Target has zero direct/interior xrefs except five at address point. | direct | xrefs for all eight bytes | UID0003E5 Xrefs | incorporate | applied |
| C09 | Five address-point refs are instruction starts `5995d7`, `5997e0`, `599a1a`, `60c440`, and static slot `6702c4`. | direct | MCP xrefs/disassembly | UID0003E5; all support bodies | incorporate | applied |
| C10 | Encoded vtable immediates begin at `5995d9`, `5997e2`, `599a1c`, `60c446`; cleanup destination operand begins `60c442`. | direct | instruction bytes | UID0003E5 and support corrections | incorporate | applied |
| C11 | Scalar deleting wrapper is compiler ABI support over four-byte `this`. | direct | disasm/decompile | UID0004N9; UID0003E5 | incorporate | applied |
| C12 | Ordinary destructor is empty human source represented by exact seven-byte vptr-reset body. | very strong | modeled function/body/hash | UID0004N7; UID0000FE | incorporate | applied |
| C13 | Class is vptr-only size four with no source fields or bases. | very strong | delete size/static slot/RTTI | UID0000FE; UID0003E5 | incorporate | applied |
| C14 | Retained `0x5995b0-0x5997dd` is the source-bearing out-of-line constructor body. | strong | this/vptr/body/return/live inline copy | UID0004N6 | incorporate | applied |
| C15 | `0x5997f0-0x599a0b` is a non-emitting duplicate initializer projection. | strong | body shape, no this/vptr/atexit/xrefs | UID0004N8 | incorporate | applied |
| C16 | `0x41a280` remains sole live startup/static wrapper and must not emit handwritten source. | very strong | startup-table xref/atexit/body | UID0000WD | incorporate | applied |
| C17 | `0x60c440` remains compiler cleanup wrapper and must not emit. | direct | body and sole registration ref | UID0001O9 | incorporate | applied |
| C18 | `0x6702c4` is one static UniAPIInit object, not raw pointer storage. | very strong | initial vptr/only write/end boundary | UID00028B | incorporate | applied |
| C19 | Highest-probability object spelling remains `s_uniAPIInit`, explicitly inferred. | strong inference | current convention/static role | UID00028B; UID0000ML | incorporate | applied |
| C20 | Highest-probability class access is public constructor/virtual destructor. | strong inference | static construction/destruction and accepted class form | UID0000FE | incorporate | applied |
| C21 | Source placement is private PlatformApi translation-unit code. | very strong | current route and cross-subsystem globals | UID0000ML; UID0000FE | incorporate | applied |
| C22 | UID0003E5 becomes `94/96`, owner 0000FE, false, blank emitter/position/C++, Nested 8. | very strong | complete target audit | UID0003E5 metadata | incorporate | applied |
| C23 | UID00026S remains a false/non-emitting mixed parent but gains complete child facts and `90/95`. | very strong | exact two-child bounds | UID00026S | incorporate | applied |
| C24 | UID0001KE becomes a false/non-emitting mixed index at `92/94`. | very strong | complete seven-part split | UID0001KE | incorporate | applied |
| C25 | Create constructor child `[0x5995b0,0x5997dd)` at `92/93`, owner/emitter 0000FE, true, Nested 8. | strong | exact retained source body | UID0004N6 | incorporate | applied |
| C26 | Create ordinary-destructor child `[0x5997e0,0x5997e7)` at `93/96`, owner/emitter 0000FE, true, Nested 0. | very strong | exact modeled body | UID0004N7 | incorporate | applied |
| C27 | Create duplicate-projection child `[0x5997f0,0x599a0b)` at `91/93`, owner 0000ML, false/non-emitting, Nested 0. | strong | exact body/no-route | UID0004N8 | incorporate | applied |
| C28 | Create scalar-deleting child `[0x599a10,0x599a34)` at `94/97`, owner 0000FE, false/non-emitting, Nested 0. | direct | exact ABI body/vtable route | UID0004N9 | incorporate | applied |
| C29 | Change UID0001KF `Nested` from 0 to -8 only, closing the new UID0001KE child level. | direct | relative nesting rule/address order | UID0001KF metadata | incorporate | applied |
| C30 | Preserve all three exact `0xcc` padding intervals in UID0001KE and supply their absent manual UID0000VN `-ignored` rows as exact supervisor-owned report text without creating ordinary pages or editing coverage. | direct | exact CC bytes and inspected absent rows | UID0001KE/report coverage text | incorporate | applied |
| C31 | UID0000WD becomes `91/93`, owner 0000ML, false/non-emitting, blank formal. | very strong | compiler startup-wrapper disposition | UID0000WD | incorporate | applied |
| C32 | UID0001O9 becomes `91/95`, owner NONE, false/non-emitting, blank formal. | direct | exact cleanup thunk | UID0001O9 | incorporate | applied |
| C33 | UID00028B becomes `91/94`, owner/emitter 0000ML, true, existing static-object formal preserved. | very strong | static storage/lifetime | UID00028B | incorporate | applied |
| C34 | UID0000FE becomes `93/95`, owner/emitter 0000ML, true, exact class formal preserved. | very strong | complete RTTI/class/source model | UID0000FE | incorporate | applied |
| C35 | UID0000ML becomes `90/88` with complete source model; unrelated AutoInit/MAPI content preserved. | strong | source-family reconciliation | UID0000ML | incorporate | applied |
| C36 | UID0000TQ becomes `92/91`; accepted grouped-global model and rejected struct/raw aliases preserved. | strong | full initializer/table declarations | UID0000TQ | incorporate | applied |
| C37 | UID0001Q1 becomes `91/93` and emits exact `g_pfnSendMessageW` declaration. | very strong | slot writer/consumers/current naming | UID0001Q1 | incorporate | applied |
| C38 | UID0002A6 becomes `91/93` and emits exact locale/file-attributes declarations. | very strong | exact two slots/initializer | UID0002A6 | incorporate | applied |
| C39 | New constructor formal block uses all 47 exact accepted dispatch names and preserves unconditional reader assignment and NT-only branch. | strong | retained/live bodies and current declarations | UID0004N6 formal C++ | incorporate | applied |
| C40 | New destructor formal block is one empty out-of-line definition. | very strong | exact ordinary destructor | UID0004N7 formal C++ | incorporate | applied |
| C41 | Target, aggregate, duplicate, scalar, live wrapper, and cleanup formal blocks remain blank. | direct | compiler/no-code proofs | named destinations | already-present | already-present |
| C42 | No third-party inline import applies. | direct negative | embed enumeration/search | target/file report notes | not-applicable | excluded-with-reason |
| C43 | Supply exact current replacement/addition rows for every existing UID and all four registered child UIDs; no allocation placeholder remains. | direct | inspected manual rows plus serial validator registration | supervisor-owned coverage text in this report only | incorporate | applied |
| C44 | Preserve rejected alternatives, historical Wave3 caveat, no-route facts, hashes, and source-vs-generated distinctions without compression. | very strong | current/old evidence | every changed destination | incorporate | applied |

### Callback Claim-By-Claim Destination Proof

| Claim | Applied destination and independent proof |
| --- | --- |
| C01 | UID0003E5 now records the exact eight bytes and SHA256; scoped validator `000000010602` returned exit `0`, `ok:1`. |
| C02 | UID0003E5 retains exact `[0x0062e578,0x0062e580)` path/range; UID00026S and verify-only UID0002P0 preserve the successor boundary. |
| C03 | UID0003E5 Layout records COL `0x00651a2c`, address point `0x0062e57c`, and slot target `0x00599a10`; command `000000010602` accepted it. |
| C04 | UID0003E5 RTTI records exact COL tuple `(0,0,0,0x679a10,0x651a40)` under the same scoped validation. |
| C05 | UID0003E5 and UID0000FE retain symbol-proven `.?AVUniAPIInit@@`; class validator `000000010626` returned exit `0`, `ok:1`. |
| C06 | UID0003E5 and UID0000FE record the one-self-base hierarchy and PMD `(0,-1,0)` without invented inheritance. |
| C07 | UID0003E5 and UID0000FE record the one-slot virtual-destructor-only contract; generated readback has one class declaration and no handwritten vtable body. |
| C08 | UID0003E5 preserves the exhaustive per-byte negative xref inventory and five address-point references. |
| C09 | UID0003E5 plus UID0004N6, UID0004N7, UID0004N9, UID0001O9, and UID00028B record all five exact instruction/static references. |
| C10 | UID0003E5 and the exact support pages distinguish instruction starts from immediate/destination operand starts, including `0x60c442` versus `0x60c446`. |
| C11 | Registered UID0004N9 is `94/97`, owner UID0000FE, false/non-emitting with four-byte-this/delete-flag ABI proof; command `000000010596` returned `ok:1`. |
| C12 | Registered UID0004N7 is `93/96`, owner/emitter UID0000FE, true, and contains the exact empty out-of-line destructor formal block; command `000000010589` returned `ok:1`. |
| C13 | UID0000FE and UID0003E5 preserve vptr-only size-four/no-base/no-field proof; no raw layout member was introduced. |
| C14 | Registered UID0004N6 is `92/93`, owner/emitter UID0000FE, true, with exact retained constructor behavior/hash/no-route evidence; command `000000010587` returned `ok:1`. |
| C15 | Registered UID0004N8 is `91/93`, owner UID0000ML, false/non-emitting, with exact duplicate/no-this/no-vptr/no-atexit/no-route proof; command `000000010592` returned `ok:1`. |
| C16 | UID0000WD is `91/93`, owner UID0000ML, false/non-emitting and blank; command `000000010618` returned `ok:1`. |
| C17 | UID0001O9 is `91/95`, owner NONE, false/non-emitting and blank; command `000000010621` returned `ok:1`. |
| C18 | UID00028B is `91/94`, owner/emitter UID0000ML, true, and retains exact `static UniAPIInit s_uniAPIInit;`; command `000000010622` returned `ok:1`. |
| C19 | UID00028B and UID0000ML retain `s_uniAPIInit` as bounded inferred spelling rather than original-symbol fact. |
| C20 | UID0000FE retains the accepted public constructor/virtual destructor declaration and explicitly bounded access inference. |
| C21 | UID0000FE and UID0000ML route the complete model to `NexusTK/platform/PlatformApi.cpp`; file validator `000000010631` returned `ok:1`. |
| C22 | UID0003E5 is exactly `94/96`, owner UID0000FE, false, blank emitter/position/formal, `Nested:8`; command `000000010602` registered the metadata transition. |
| C23 | UID00026S is `90/95`, NONE/false/non-emitting with exact UniAPIInit and UrlAlert children; command `000000010605` returned `ok:1`. |
| C24 | UID0001KE is `92/94`, NONE/false/non-emitting with exact seven-part child/padding index; command `000000010611` returned `ok:1`. |
| C25 | UID0004N6 was serially registered first at `[0x005995b0,0x005997dd)`, with UID reread from validator command `000000010587`. |
| C26 | UID0004N7 was serially registered second at `[0x005997e0,0x005997e7)`, with UID reread from validator command `000000010589`. |
| C27 | UID0004N8 was serially registered third at `[0x005997f0,0x00599a0b)`, with UID reread from validator command `000000010592`. |
| C28 | UID0004N9 was serially registered fourth at `[0x00599a10,0x00599a34)`, with UID reread from validator command `000000010596`. |
| C29 | UID0001KF changed only `Nested:0 -> -8`; command `000000010614` returned exit `0`, `ok:1`. |
| C30 | UID0001KE retains exact three-, nine-, and five-byte `0xcc` intervals; the three UID0000VN manual rows below are exact supervisor-owned text and no padding page was created. |
| C31 | UID0000WD metadata/no-code proof is applied and generated command `000000010640` emits neither its body nor an empty marker. |
| C32 | UID0001O9 metadata/no-code proof is applied and generated command `000000010640` emits neither its body nor an empty marker. |
| C33 | UID00028B metadata/source declaration is applied and generated command `000000010640` contains exactly one static object definition. |
| C34 | UID0000FE is `93/95`, owner/emitter UID0000ML, true, with the exact accepted class block and full child/RTTI inventory. |
| C35 | UID0000ML is `90/88` with complete UniAPIInit source route while all unrelated AutoInit/MAPI/helper content remains present; its validator reported only three pre-existing unrelated UID0003OT missing-reference diagnostics. |
| C36 | UID0000TQ is `92/91` with the grouped-global model, all 47 destinations, and raw/struct/consumer alternatives preserved; command `000000010633` returned `ok:1`. |
| C37 | UID0001Q1 is `91/93` and contains the exact `g_pfnSendMessageW` declaration; command `000000010636` changed its autogen state from blank to block and returned `ok:1`. |
| C38 | UID0002A6 is `91/93` and contains the exact locale/file-attributes declarations; command `000000010638` changed its autogen state from blank to block and returned `ok:1`. |
| C39 | UID0004N6 contains all 47 accepted assignments, including unconditional reader setup and the NT-only branch; generated command `000000010640` readback counts 47 constructor assignments. |
| C40 | UID0004N7 contains exactly one empty out-of-line definition; generated command `000000010640` readback counts one destructor definition. |
| C41 | UID0003E5, UID0001KE, UID0004N8, UID0004N9, UID0000WD, and UID0001O9 remain blank/non-emitting as applicable; generated readback finds none as code or empty markers. |
| C42 | No import directive was added because exhaustive `third_party_embeds` inspection found no applicable source family; project-owned PlatformApi routing remains exact. |
| C43 | Manual coverage files were not edited. This report now supplies exact existing-UID and real-UID child text using UID0004N6 through UID0004N9; a full report search after registration finds zero allocation placeholders. |
| C44 | Target and every support page retain hashes, no-route/liveness distinctions, historical Wave3 labels, rejected owner/source/raw-data alternatives, and source-versus-compiler boundaries; no unrelated content was removed. |

## Positive Evidence Summary

- Direct facts supporting the recommendation: exact target bytes and boundaries; preserved MSVC RTTI names; complete self-only hierarchy; one vtable slot; exact ordinary/scalar destructor bodies; exact constructor/static-cleanup stores; initialized static object; sole startup route; all direct/interior xrefs.
- Corroborating documentation/generated-report evidence: current class/static formal blocks already express the right declaration model; accepted dispatch declaration page supplies 44 names; generated PlatformApi source proves the missing two method definitions and current empty-marker pollution; recent compiler-data pages establish false/non-emitting precedent.
- Strongest inference chain: RTTI proves a no-base class named `UniAPIInit`; its sole vtable slot is deleting-destructor glue over a four-byte object; the separate seven-byte vptr-reset function is an empty ordinary destructor; retained constructor body and live inlined startup copy perform identical platform setup; static object storage/atexit wrapper prove file-local lifetime. Therefore one public polymorphic helper class, out-of-line constructor/empty destructor, and static object are sufficient and highest probability.

## IDA MCP Facts

- Function/range facts:
  - `0x005995b0` and `0x005997f0` are not IDA-modeled functions and have zero xrefs; their exact coherent byte ranges are retained projections.
  - `sub_5997E0` is exactly `0x005997e0-0x005997e7`, two instructions.
  - `sub_599A10` is exactly `0x00599a10-0x00599a34`, 15 instructions.
  - `sub_60C440` is exactly `0x0060c440-0x0060c44b`.
  - `sub_41A280` is exactly `0x0041a280-0x0041a4a8`, reached only through startup table data `0x0060d71c`.
- Data/table/padding facts:
  - target bytes and hash are recorded above;
  - predecessor bytes end with UTF-16 `.PAD`, terminator/alignment, and float `0x3cf5c28f` before target;
  - successor starts with UrlAlert COL `0x651a74` then slot `0x599c00`;
  - UID0001KE internal padding is three, nine, and five `0xcc` bytes at the exact documented intervals;
  - static object bytes are `7c e5 62 00` followed by unrelated `57 00 01 00`.
- Xref facts:
  - no xref to `0x62e578`; one xref from it to COL `0x651a2c`;
  - exactly five refs to address point `0x62e57c`;
  - no refs to target interior bytes or successor COL address `0x62e580`;
  - scalar deleting destructor has exactly one xref, the vtable slot;
  - static slot has exactly one xref, cleanup writer;
  - cleanup wrapper has exactly one xref, registration inside live startup wrapper.
- Vtable/global/type facts:
  - COL `0x00651a2c` exact dwords are `0x00000000`, `0x00000000`, `0x00000000`, `0x00679a10`, `0x00651a40` for signature, object offset, constructor-displacement offset, type descriptor, and class hierarchy descriptor;
  - type descriptor `0x00679a10` contains RTTI type-info vftable pointer `0x00635078`, spare dword zero, and NUL-terminated `.?AVUniAPIInit@@`;
  - CHD `0x00651a40` exact dwords are signature zero, attributes zero, base count one, base-array pointer `0x00651a50`; the array's only dword is `0x00651a58`;
  - BCD `0x00651a58` exact semantic fields are type descriptor `0x00679a10`, contained-base count zero, PMD `mdisp=0`, `pdisp=-1`, `vdisp=0`, attributes `0x40`, and hierarchy pointer `0x00651a40`;
  - the table has one slot and no secondary views;
  - static object is four bytes and initialized to the address point.
- Negative IDA facts: no class fields/bases, no extra slots, no constructor or ordinary-destructor route, no duplicate-initializer route, no target-start xref, no overlap, no source symbols for the static variable or dispatch globals.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0041a280-0x0041a4a8` | UID0000WD `WideApiDispatchInit.md` | compiler startup wrapper/inlined constructor | false | UID0000ML | `91/93` applied | blank/non-emitting |
| `0x005995b0-0x00599a34` | UID0001KE `UniAPIInit.md` | mixed executable index | false | NONE | `92/94` applied | blank/non-emitting parent |
| `0x005995b0-0x005997dd` | UID0004N6 `UniAPIInitConstructor.md` | source constructor body | true | UID0000FE | `92/93` applied | exact child/formal body |
| `0x005997dd-0x005997e0` | UID0000VN `-ignored.md` coverage row | 3-byte padding | false | UID0001KE | 100 | manual row to add; no ordinary page |
| `0x005997e0-0x005997e7` | UID0004N7 `UniAPIInitDestructor.md` | source empty virtual destructor | true | UID0000FE | `93/96` applied | exact child/formal body |
| `0x005997e7-0x005997f0` | UID0000VN `-ignored.md` coverage row | 9-byte padding | false | UID0001KE | 100 | manual row to add; no ordinary page |
| `0x005997f0-0x00599a0b` | UID0004N8 `RetainedWideApiDispatchInitProjection.md` | retained duplicate projection | false | UID0000ML | `91/93` applied | exact blank child |
| `0x00599a0b-0x00599a10` | UID0000VN `-ignored.md` coverage row | 5-byte padding | false | UID0001KE | 100 | manual row to add; no ordinary page |
| `0x00599a10-0x00599a34` | UID0004N9 `UniAPIInitScalarDeletingDestructor.md` | MSVC deleting wrapper | false | UID0000FE | `94/97` applied | exact blank child |
| `0x0060c440-0x0060c44b` | UID0001O9 | compiler static cleanup | false | NONE | `91/95` applied | blank/non-emitting |
| `0x0062e578-0x0062e624` | UID00026S | mixed read-only index | false | NONE | `90/95` applied | blank/non-emitting parent |
| `0x0062e578-0x0062e580` | UID0003E5 | COL pointer + one-slot address point | false | UID0000FE | `94/96` applied | exact target, blank |
| `0x0062e580-0x0062e624` | UID0002P0 | UrlAlertPane RTTI/vtable | unchanged | UID0000FF | unchanged | successor only |
| `0x006702c4-0x006702c8` | UID00028B | source static object storage | true | UID0000ML | `91/94` applied | existing static formal |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0062e578` | no incoming xref; dword points to `0x00651a2c` | compiler COL back-pointer location |
| `0x0062e57c` | `0x005995d7` instruction; immediate at `0x005995d9` | retained constructor vptr store |
| `0x0062e57c` | `0x005997e0` instruction; immediate at `0x005997e2` | ordinary destructor vptr reset |
| `0x0062e57c` | `0x00599a1a` instruction; immediate at `0x00599a1c` | scalar deleting wrapper vptr reset |
| `0x0062e57c` | `0x0060c440` instruction; immediate at `0x0060c446` | static cleanup vptr reset; destination operand starts `0x0060c442` |
| `0x0062e57c` | initialized dword at `0x006702c4` | static object initial vptr |
| `0x00651a2c` | pointer at `0x0062e578` | one COL use |
| `0x00651a40` | COL field `0x651a3c`, BCD field `0x651a70` | hierarchy self-reference |
| `0x00679a10` | COL field `0x651a38`, BCD field `0x651a58` | type descriptor use |
| `0x00599a10` | vtable slot `0x0062e57c` | sole virtual dispatch target |
| `0x006702c4` | write at `0x0060c440` | sole static object writer after initialization |
| `0x0060c440` | address at `0x0041a48d` | `_atexit` registration in live wrapper |
| `0x0041a280` | startup table data `0x0060d71c` | sole live initialization route |
| `0x005995b0`, `0x005997e0`, `0x005997f0` | no incoming xrefs | retained/out-of-line bodies without current route |

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion: UID0000FE class declaration; UID00028B static object definition; UID0001KE exact internal ranges; UID0000WD startup route; UID0001O9 cleanup disposition; UID0002AS accepted main table declarations; UID00026S/UID0002P0 exact adjacency.
- Historical stale docs corrected by the callback: UID0003E5 true/empty-emitter state, incomplete RTTI, mixed instruction/operand addresses, duplicate links, and declaration-only destructor premise; UID0001KE reconstructable mixed parent; UID0000WD reconstructable empty wrapper; PlatformApi source-completeness wording; final declaration caveats on UID0001Q1/UID0002A6.
- Current generated/manual coverage state: generated PlatformApi source is fresh to command `000000010640` and contains the complete constructor/destructor/static/declaration source counts with all accepted negative checks. Manual coverage rows remain supervisor-owned and were not edited; exact replacement/addition text with real child UIDs is supplied below. Generated reports are read-only evidence and are not manual edit destinations.

## Ranked Ownership Analysis

### 1. UID0000FE UniAPIInit class

- Evidence for: exact RTTI class name; target is its primary COL/address point; all five references are its constructor/destructor/static-lifetime uses; scalar deleting slot and class declaration form a direct semantic contract.
- Evidence against: class is itself emitted through PlatformApi and the target data is not handwritten class source.
- Decision: accepted as `CANONICAL_OWNER:0000FE`; target gets no emitter because it is compiler-generated.

### 2. UID0000ML PlatformApi file

- Evidence for: owns the translation unit, dispatch globals, live startup wrapper, static object, retained constructor, and helper family.
- Evidence against: source-file root is broader than the direct class semantic owner of RTTI/vtable data.
- Decision: accepted as transitive source route for class/method/static declarations, rejected as target direct owner.

### 3. UID0000TQ WideApiDispatchTable or adjacent UI families

- Evidence for: dispatch globals are initialized by the constructor; TransferServer and UrlAlert data are adjacent.
- Evidence against: table is a constructor dependency, not class/vtable owner; exact RTTI/boundaries reject adjacent ownership.
- Decision: rejected for target ownership. Preserve only dependency and boundary links.

### Implemented new grouping

- Implemented owner/name/path: no new by-file source root. Four exact by-memory children UID0004N6 through UID0004N9 were created under UID0001KE, and the two source-bearing method definitions route through UID0000FE to existing UID0000ML.
- Likely full contents: complete constructor definition, empty destructor definition, retained duplicate projection no-code evidence, scalar deleting destructor no-code evidence.
- Candidate related items that belong: existing UID0000WD, UID0001O9, UID00028B, UID0003E5, dispatch table pages, class and file docs.
- Candidate related items rejected: UrlAlertPane, TransferServerDialogPane, dispatch consumers, separate `UniAPIInit.cpp`, third-party source.
- Standalone, narrow, or broad source-file inference: narrow private class inside existing broad `PlatformApi.cpp`; no standalone source file.

## Source Placement

- Recommended source file/class/global/module placement: class declaration, constructor/destructor definitions, grouped dispatch globals, helpers, and file-local static object in `NexusTK/platform/PlatformApi.cpp` under UID0000ML.
- Why this placement fits source-tree and subsystem context: the code selects Windows ANSI/wide API behavior shared by many unrelated consumers; startup-table and static-object lifetime are translation-unit-local; existing generated route already places every dependency there.
- Rejected placements and why: consumer modules only read individual dispatch slots; adjacent UI classes are boundary neighbors only; a new public header/source pair lacks external class use; third-party embeds contain no match.
- Remaining placement uncertainty, if any: original file name and static object spelling are not symbol-proven, but current established PlatformApi route is substantially stronger than all alternatives and is implementation-ready.

## Range / Split / Padding / Reclassification Analysis

- Exact target range/boundary facts: target is aligned, eight bytes, and exactly bounded by TransferServer fade float before and UrlAlert COL after. No internal padding or overlap exists.
- Target split decision: no split. COL pointer at address-point minus four and one-slot address point are one compiler ABI unit.
- Executable aggregate children to create serially in ascending address order:
  - `[0x005995b0,0x005997dd)` `UniAPIInitConstructor`;
  - `[0x005997e0,0x005997e7)` `UniAPIInitDestructor`;
  - `[0x005997f0,0x00599a0b)` `RetainedWideApiDispatchInitProjection`;
  - `[0x00599a10,0x00599a34)` `UniAPIInitScalarDeletingDestructor`.
- Padding/table/data/code distinctions: exact padding at `[0x5997dd,0x5997e0)`, `[0x5997e7,0x5997f0)`, and `[0x599a0b,0x599a10)` remains ignored and described by UID0001KE; add absent manual UID0000VN rows but no ordinary pages. Target and parent are `.rdata` compiler data; static object is `.data`; constructor/destructor/wrappers are `.text`.
- Parent/container impact: UID0001KE becomes false/non-emitting and gets child inventory. New first child uses `Nested:8`; later children use 0; immediate successor UID0001KF changes to `Nested:-8`. UID00026S remains false parent; target keeps +8, successor keeps 0, UID00026T already closes with -8.
- Reclassification impact: target, UID0001KE, and UID0000WD stop generating empty markers; only source-bearing constructor/destructor and existing class/static declarations emit source.

## Negative Evidence Summary

- Checked and rejected: target split, neighboring ownership, extra slots/bases/fields, handwritten ABI data, target covered-by comment, source deleting wrapper, source cleanup wrapper, source startup wrapper, second source initializer, separate file/header, third-party import, and generated Wave3 naming.
- Consumer/read xrefs do not prove target ownership: consumers touch dispatch globals, not RTTI/vtable bytes. Adjacent addresses belong to predecessor/successor classes by exact dwords. The five address-point refs are class lifetime operations, not five source definitions.
- No-route evidence does not erase retained source: the constructor body is coherent, class-shaped, and independently realized by the live inlined startup copy. Conversely, the duplicate projection lacks `this`, vptr, cleanup registration, and any route, so it remains non-emitting.
- Original access/static-variable spelling remain absent from binary symbols. The report uses bounded high-probability forms and does not present them as direct proof.

## IDA Rename / Type / Comment Recommendations

- Proposed source-facing names/types/comments after supervisor approval, not performed by B004:
  - define/type `0x005995b0-0x005997dd` as retained `UniAPIInit::UniAPIInit()` constructor body;
  - rename/type `0x005997e0` as `UniAPIInit::~UniAPIInit()` with `thiscall` `UniAPIInit *this` and no source-visible return;
  - comment `0x005997f0` as retained duplicate PlatformApi dispatch initializer projection, not original source function;
  - rename/comment `0x00599a10` as `UniAPIInit::ScalarDeletingDestructor` with compiler deletion flags;
  - retain/comment `0x0060c440` as `UniAPIInitStaticCleanupWrapper`;
  - retain IDA's `??_R4UniAPIInit@@6B@`, `??_7UniAPIInit@@6B@`, and type descriptor names;
  - comment instruction-start versus operand-byte address distinctions exactly as listed.
- Evidence for each proposed name/type/comment: RTTI identity, `this` use, vptr stores, ordinary/scalar ABI forms, static registration, and no-route duplicate classification.
- Items intentionally left unchanged: target raw bytes, RTTI structures, adjacent UrlAlert names, dispatch consumer aliases not in accepted table docs, and inferred static object name in IDA.
- Whether IDA DB edits are safe, unsafe, or not requested: no IDA mutation is requested or permitted in this report-only assignment. These are documentation recommendations for a separately authorized IDA pass.

## First-Draft C++ Recommendation

- Eligible for draft C++: target itself is not eligible. Existing class and static-object source pages remain eligible; new constructor and ordinary-destructor children are eligible; existing SendMessage/tail pointer pages are eligible for missing declarations. Mixed/container/compiler pages remain blank.
- Target UID0003E5 exact managed block, which must remain blank:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- UID0000FE exact managed class block, preserving current declaration:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class UniAPIInit
{
public:
    UniAPIInit();
    virtual ~UniAPIInit();
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- New `[0x005995b0,0x005997dd)` constructor child exact managed block:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
UniAPIInit::UniAPIInit()
{
    OSVERSIONINFOA versionInfo;

    versionInfo.dwOSVersionInfoSize = sizeof(versionInfo);
    GetVersionExA(&versionInfo);

    g_pfnReadUtf16CodeUnitFromFile = ReadUtf16CodeUnitFromFile;

    if (versionInfo.dwPlatformId == VER_PLATFORM_WIN32_NT) {
        g_pfnFindWindowW = FindWindowW;
        g_pfnOpenFileMappingW = OpenFileMappingW;
        g_pfnCreateMutexW = CreateMutexW;
        g_pfnCreateDialogParamW = CreateDialogParamW;
        g_pfnLoadLibraryW = LoadLibraryW;
        g_pfnCreateFileW = CreateFileW;
        g_pfnCreateProcessW = CreateProcessW;
        g_pfnCreateEventW = CreateEventW;
        g_pfnRegisterClassW = RegisterClassW;
        g_pfnCreateWindowExW = CreateWindowExW;
        g_pfnCreateFileMappingW = CreateFileMappingW;
        g_pfnCreateSemaphoreW = CreateSemaphoreW;
        g_pfnDefWindowProcW = DefWindowProcW;
        g_pfnRegisterClipboardFormatW = RegisterClipboardFormatW;
        g_pfnCharUpperBuffW = CharUpperBuffW;
        g_pfnCreateDirectoryW = CreateDirectoryW;
        g_pfnDeleteFileW = DeleteFileW;
        g_pfnDispatchMessageW = DispatchMessageW;
        g_pfnFindFirstFileW = FindFirstFileW;
        g_pfnFormatMessageW = FormatMessageW;
        g_pfnGetCurrentDirectoryW = GetCurrentDirectoryW;
        g_pfnGetModuleFileNameW = GetModuleFileNameW;
        g_pfnGetModuleHandleW = GetModuleHandleW;
        g_pfnGetWindowsDirectoryW = GetWindowsDirectoryW;
        g_pfnGlobalGetAtomNameW = GlobalGetAtomNameW;
        g_pfnLoadCursorW = LoadCursorW;
        g_pfnLoadIconW = LoadIconW;
        g_pfnPeekMessage = PeekMessageW;
        g_pfnPostMessageW = PostMessageW;
        g_pfnRegCreateKeyExW = RegCreateKeyExW;
        g_pfnRegDeleteKeyW = RegDeleteKeyW;
        g_pfnRegEnumValueW = RegEnumValueW;
        g_pfnRegQueryInfoKeyW = RegQueryInfoKeyW;
        g_pfnRegQueryValueExW = RegQueryValueExW;
        g_pfnRegSetValueExW = RegSetValueExW;
        g_pfnSetCurrentDirectoryW = SetCurrentDirectoryW;
        g_pfnWideOpenFile = _wfopen;
        g_pfnWideStat = _wstat64i32;
        g_pfnGetFileVersionInfoSizeW = GetFileVersionInfoSizeW;
        g_pfnGetFileVersionInfoW = GetFileVersionInfoW;
        g_pfnVerQueryValueW = VerQueryValueW;
        g_pfnImmGetCompositionStringW = ImmGetCompositionStringW;
        g_pfnImmGetCandidateListW = ImmGetCandidateListW;
        g_pfnSendMessageW = SendMessageW;
        g_pfnGetLocaleInfoW = GetLocaleInfoW;
        g_pfnSetFileAttributesW = SetFileAttributesW;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- New `[0x005997e0,0x005997e7)` ordinary-destructor child exact managed block:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
UniAPIInit::~UniAPIInit()
{
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- UID0001Q1 exact managed declaration block:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
LRESULT (WINAPI *g_pfnSendMessageW)(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- UID0002A6 exact managed declaration block:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
int (WINAPI *g_pfnGetLocaleInfoW)(LCID locale, LCTYPE localeType, LPWSTR data, int dataCount);
BOOL (WINAPI *g_pfnSetFileAttributesW)(LPCWSTR fileName, DWORD fileAttributes);
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- UID00028B exact managed static-object block, preserving current spelling:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static UniAPIInit s_uniAPIInit;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- UID0001KE parent, new duplicate-projection child, new scalar-deleting child, UID0000WD live wrapper, and UID0001O9 cleanup wrapper each use this exact blank managed block:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Third-party import directive: not applicable. No vetted embedded source matches this project-owned class; no `third_party_embeds/...` directive should be added, and all ordinary multiline blocks above remain as shown.
- Reason the emitted code preserves exact original behavior: it reproduces the uninitialized `OSVERSIONINFOA` local with only size assigned, ignores the `GetVersionExA` return like the binary, unconditionally installs the UTF-16 reader, performs all 47 accepted NT-only pointer assignments in observed order, provides an empty virtual destructor, and lets the compiler generate vptr, RTTI, deleting wrapper, startup, and cleanup mechanics.
- Reason it matches plausible mid-2000s source: out-of-line constructor/destructor, Win32 SDK types/constants, explicit function-pointer globals, no C++11 syntax, no decompiler labels, and one file-local static initializer object match the observed MSVC codegen and project conventions.
- Inferred source-facing names/types/fields: `versionInfo`, `s_uniAPIInit`, public access, and `g_pfn*` names are high-probability reconstructed names; `UniAPIInit`, Win32 API types, addresses, branch condition, and helper identity are directly supported.
- Naming/coding style convention: preserve accepted PlatformApi `g_pfn*` global names, `s_` file-static prefix, brace style, `NULL`-era SDK types, and out-of-line member definitions already used by the project.
- Reason target and compiler pages remain blank: none corresponds to a source-authored declaration/body independent of the source blocks above; any text in those formal blocks would either duplicate source or hand-port ABI output.
- Exact target-specific no-code proof: eight target bytes are one COL pointer plus one compiler-selected function address; type/hierarchy/vtable are generated from class/destructor declarations; all five refs are generated vptr/address uses; no source reads the target as data; no third-party static table exists; source rebuilding requires no raw bytes; false/non-emitting metadata prevents empty-marker ambiguity.

## Final Recommendation

- Exact changes implemented: target reclassification/score/evidence; full UID0001KE child split; source constructor/destructor definitions; compiler-page no-code dispositions; class/static/table declaration synchronization; corrected instruction/operand addresses; generated-source verification; exact existing-UID and real-child-UID manual coverage text.
- Exact parent assignments recommended: target and new constructor/destructor/scalar child direct owner UID0000FE; duplicate projection direct owner UID0000ML; static/live wrapper/file globals remain PlatformApi-owned; mixed parents remain NONE.
- Exact items left no-owner/non-emitting and why: UID00026S and UID0001KE are mixed indices; UID0001O9 is pure compiler cleanup. Target and scalar child retain class ownership but no emitter because they are generated ABI data.
- Exact implementation work remaining: none. Original static variable spelling/PDB provenance could refine names if historical source appears, but it is not an implementation blocker and does not justify another target pass.

## Recommended Target Doc Changes

- Target path: `by-memory/0x0062e578-0x0062e580.UniAPIInitVtableData.md`.
- Exact report facts to incorporate: all bytes/hash; exact dwords/bounds; full COL/type/hierarchy/base inventory; one-slot scalar deleting target; all direct/interior xrefs; instruction/operand address distinction; object size; class/static/source relation; no-split decision; third-party negative; generated-state proof; target-specific no-code proof.
- Metadata/score/owner/emitter/reconstructable/C++ changes: `85/91 -> 94/96`; retain owner `0000FE`; `TRUE -> FALSE`; clear emitter; keep blank position/formal; retain `Nested:8`; replace Item Summary with: `Exact non-emitting UniAPIInit COL-pointer-plus-one-slot-vtable child with complete self-only RTTI hierarchy, scalar deleting destructor slot, static-object lifetime stores, and source class/destructor regeneration contract verified; no handwritten ABI data.`
- Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: prior one-dword start as superseded history; UID00026R correction history; old Wave3 label as stale; no manual dwords; no UrlAlert/Transfer ownership; no split; no third-party import; no extra bases/slots/xrefs.

## Recommended Support Doc Changes

- `by-memory/0x0062e578-0x0062e624.UniApiUrlAlertReadOnlyData.md`: `86/92 -> 90/95`; retain NONE/FALSE/blank/`Nested:-8`; add exact two-child layout, target full disposition, successor boundary, and no handwritten parent code.
- `by-memory/0x005995b0-0x00599a34.UniAPIInit.md`: `87/89 -> 92/94`; set owner NONE, false, blank emitter/position/formal; retain all seven exact intervals, hashes, routes, historical caveats, and rejected alternatives; add four real child links after registration; change Item Summary to a concise non-emitting mixed-index description.
- New `by-memory/0x005995b0-0x005997dd.UniAPIInitConstructor.md`: create/register first; `92/93`, owner/emitter UID0000FE, true, blank position, constructor formal block, `Nested:8`; include full retained/live comparison, hash, no-route evidence, complete assignment behavior, source inference, and rejection of compiler-only status.
- New `by-memory/0x005997e0-0x005997e7.UniAPIInitDestructor.md`: create/register second; `93/96`, owner/emitter UID0000FE, true, blank position, empty destructor formal block, `Nested:0`; include exact bytes/hash, two instructions, no-route fact, scalar relation, and out-of-line source decision.
- New `by-memory/0x005997f0-0x00599a0b.RetainedWideApiDispatchInitProjection.md`: create/register third; `91/93`, owner UID0000ML, false, blank emitter/position/formal, `Nested:0`; preserve exact behavior/hash and no-this/no-vptr/no-atexit/no-route rejection.
- New `by-memory/0x00599a10-0x00599a34.UniAPIInitScalarDeletingDestructor.md`: create/register fourth; `94/97`, owner UID0000FE, false, blank emitter/position/formal, `Nested:0`; include exact bytes/hash, flag/free/size/return ABI, vtable xref, and exhaustive no-code proof.
- `by-memory/0x00599a40-0x00599cb3.UrlAlertPane.md`: metadata-only `Nested:0 -> -8` after child creation; preserve every other byte/content/score/formal item.
- `by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md`: `87/91 -> 91/93`; retain owner UID0000ML; set false and clear emitter; blank formal remains; add live-wrapper hash/route, source constructor child, and explicit non-emitting compiler-wrapper disposition.
- `by-memory/0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper.md`: `86/91 -> 91/95`; retain NONE/FALSE/blank; add exact instruction/operand distinction, sole registration/static writer facts, source destructor link, and no-code proof.
- `by-memory/0x006702c4-0x006702c8.UniAPIInitVtablePointerSlot.md`: `86/90 -> 91/94`; retain owner/emitter UID0000ML, true, blank position, exact existing static-object formal; add four-byte class layout, exact initial bytes/successor, and constructor/destructor source links.
- `by-class/UniAPIInit.md`: `90/88 -> 93/95`; retain owner/emitter UID0000ML and exact class block; add complete RTTI hierarchy, size/no-field proof, public-access inference, exact constructor/destructor child links, compiler support inventory, and generated-source completeness result.
- `by-file/PlatformApi.md`: `88/85 -> 90/88`; preserve unrelated AutoInit/MAPI/helpers/scores facts; replace deferred constructor/destructor wording with the complete source model, exact child links, source-vs-compiler dispositions, and no-third-party result.
- `by-global/WideApiDispatchTable.md`: `90/86 -> 92/91`; preserve grouped globals and rejected raw/struct/consumer alternatives; record that all 47 initializer destinations now have declaration pages and constructor source.
- `by-memory/0x0069bec4-0x0069bec8.g_browserControlKeyCallback.md`: `88/90 -> 91/93`; retain UID/path/owner/emitter/true/Nested; add exact formal `g_pfnSendMessageW` declaration and remove final-declaration caveat while preserving stale alias/consumer history.
- `by-memory/0x0069bec8-0x0069bed0.WideApiDispatchTailPointers.md`: `88/88 -> 91/93`; retain owner/emitter UID0000TQ/true/Nested; add exact two declarations and preserve exact bounds/unrelated successor.
- `by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md`: no metadata/formal change; verify-only that all 44 existing declarations and names used by the constructor remain exact.
- `by-memory/0x0062e580-0x0062e624.UrlAlertPaneVtableData.md`: no edit; successor boundary verification only.

## Score And Metadata Recommendation

- Historical pre-callback target score/metadata: `85/91`, owner/emitter UID0000FE, true, blank position/formal, `Nested:8`.
- Current implemented target score/metadata: `94/96`, owner UID0000FE, false, blank emitter/position/formal, `Nested:8`.
- Score rationale and reason not higher/lower: completion rises nine points because every byte, boundary, RTTI structure, xref, related body, source declaration, generated effect, support split, manual row, and rejected alternative is now documented. Confidence rises five because symbols and direct bytes prove the class ABI. Completion stays below 95 because no original source/PDB proves formatting/access/static-variable spelling; those do not affect target disposition.
- Score-improvement attempts:
  - exact-byte/blocker: resolved with bytes and hashes;
  - COL/type/hierarchy blocker: resolved through all RTTI structures;
  - xref/address blocker: resolved per byte and instruction/operand;
  - class/destructor source blocker: resolved with exact children and formal blocks;
  - mixed aggregate blocker: resolved with complete child plan and nesting repair;
  - generated empty-marker blocker: resolved by false reclassification and source emitters;
  - source-name/type/access blocker: original-proof class/type, inferred public access/static name, no unresolved decision;
  - third-party blocker: exhaustive negative search, project-owned decision;
  - source-placement blocker: existing PlatformApi route confirmed;
  - manual coverage blocker: exact existing-UID and real-child-UID replacement/addition rows are supplied after serial UID allocation and a zero-placeholder report search; manual application remains supervisor-owned.
- Metadata fields to change or leave unchanged: retain UID/path/title/owner/Nested; change scores/reconstructable/emitter; keep position/formal blank; replace Item Summary. Support metadata is enumerated above.

## Open Questions With Attempted Resolution

- Open question: should target remain reconstructable because source regenerates it? Evidence checked: current project precedent, generated empty-marker behavior, by-structure source-vs-compiler rule, TransferServer vtable page. Resolution: false/non-emitting while retaining semantic class owner.
- Open question: does the COL pointer need its own child? Evidence checked: MSVC address-point layout, identical class/source cause, exact eight-byte bounds. Resolution: no split.
- Open question: where do constructor/destructor source definitions belong? Evidence checked: retained exact bodies, live startup copy, class/static generated output, current aggregate. Resolution: two exact source-bearing children under UID0001KE, emitted via class.
- Open question: is the constructor retained source or dead compiler output? Evidence checked: full coherent thiscall shape, vptr store, return-this, exact dispatch behavior, live inlined copy, no route. Resolution: retained out-of-line source body; liveness caveat preserved.
- Open question: is `0x5997f0` a second source helper? Evidence checked: no `this`, no vptr, no atexit, no route, duplicate behavior. Resolution: non-emitting retained projection.
- Open question: access and static spelling. Evidence checked: RTTI, static construction/destruction legality, current conventions, old reports, absent symbols. Resolution: public access and `s_uniAPIInit` are highest-probability bounded inferences; no alternative changes behavior.
- Questions remaining unresolved: original PDB/source formatting and variable spelling only. They cap scores but do not block metadata, source blocks, split, route, or generated behavior. No currently available evidence can prove them, and another binary-only pass would not improve them.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Inspected manual rows: by-memory UID0000WD, UID0001KE, UID0001O9, UID00026S, UID0003E5, UID0002P0, UID00028B, UID0001Q1, and UID0002A6; by-class UID0000FE; by-file UID0000ML; by-global UID0000TQ. Searches for exact internal padding starts `0x005997dd`, `0x005997e7`, and `0x00599a0b` found no manual rows. Existing rows are stale relative to implemented scores, reclassifications, split inventory, and formal source completeness, and the three padding rows require supervisor-owned additions.
- Exactness boundary after serial registration: every row below is exact/current supervisor-owned replacement or addition text. The four former pre-registration templates now contain validator-assigned UIDs UID0004N6, UID0004N7, UID0004N8, and UID0004N9; no allocation placeholder remains. B004 did not edit the manual coverage files.
- `auto-generated/-ag-research-tracker.md` is validator-owned and was not manually edited. Read-only post-refresh inspection shows UID0003E5 at `94/96`, `RECONSTRUCTABLE:false`, report count `0`, with no emitter/position, rather than the historical true/empty-emitter queue state; lifecycle/count interpretation remains external validator/supervisor-owned.
- File/placement: `by-memory/-coverage-report.md`, replace current UID0000WD row:

```text
    - [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md) 0x0041a280-0x0041a4a8 | compiler startup initializer wrapper | WideApiDispatchInit : ignored : 91% : very-strong : Sole startup-table route for inlined UniAPIInit construction and static cleanup registration; exact dispatch behavior is emitted by the retained constructor child, while this compiler wrapper remains non-emitting with no handwritten atexit code.
```

- Same file: the UID0001KE parent row, four real-UID child rows, and three UID0000VN padding rows below are exact/current supervisor-owned text after serial registration and UID reread. They remain report-supplied text only; B004 did not apply them to manual coverage:

```text
    - [UID:0001KE][0x005995b0-0x00599a34.UniAPIInit](by-memory/0x005995b0-0x00599a34.UniAPIInit.md) 0x005995b0-0x00599a34 | split executable index | UniAPIInit : ignored : 92% : very-strong : Non-emitting mixed index over retained constructor source, exact ordinary destructor, retained duplicate initializer, scalar deleting destructor, and three exact padding intervals; exact children carry source or compiler dispositions.
        - [UID:0004N6][0x005995b0-0x005997dd.UniAPIInitConstructor](by-memory/0x005995b0-0x005997dd.UniAPIInitConstructor.md) 0x005995b0-0x005997dd | constructor | UniAPIInitConstructor : reconstructable : 92% : very-strong : Retained out-of-line UniAPIInit constructor body with this/vptr setup, exact PlatformApi dispatch assignments, live inlined startup counterpart, no-route caveat, and complete human source definition.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005997dd-0x005997e0 | padding | UniAPIInit constructor-to-destructor alignment : ignored : 100% : very-strong : Exact three `0xcc` bytes between the retained constructor body and ordinary destructor.
        - [UID:0004N7][0x005997e0-0x005997e7.UniAPIInitDestructor](by-memory/0x005997e0-0x005997e7.UniAPIInitDestructor.md) 0x005997e0-0x005997e7 | destructor | UniAPIInitDestructor : reconstructable : 93% : very-strong : Exact two-instruction vptr-reset ordinary destructor generated from one empty out-of-line virtual destructor definition.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005997e7-0x005997f0 | padding | UniAPIInit destructor-to-duplicate alignment : ignored : 100% : very-strong : Exact nine `0xcc` bytes between the ordinary destructor and retained duplicate initializer projection.
        - [UID:0004N8][0x005997f0-0x00599a0b.RetainedWideApiDispatchInitProjection](by-memory/0x005997f0-0x00599a0b.RetainedWideApiDispatchInitProjection.md) 0x005997f0-0x00599a0b | retained compiler projection | RetainedWideApiDispatchInitProjection : ignored : 91% : very-strong : Exact unrouted duplicate dispatch initializer without this, vptr store, or cleanup registration; preserved as non-emitting compiler/linker provenance.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00599a0b-0x00599a10 | padding | UniAPIInit duplicate-to-deleting-destructor alignment : ignored : 100% : very-strong : Exact five `0xcc` bytes before the scalar deleting destructor.
        - [UID:0004N9][0x00599a10-0x00599a34.UniAPIInitScalarDeletingDestructor](by-memory/0x00599a10-0x00599a34.UniAPIInitScalarDeletingDestructor.md) 0x00599a10-0x00599a34 | compiler scalar deleting destructor | UniAPIInitScalarDeletingDestructor : ignored : 94% : very-strong : Exact one-slot MSVC deleting wrapper over a four-byte UniAPIInit object; resets vptr, conditionally frees on flag bit 0, returns this, and is regenerated from the virtual destructor contract.
```

- Post-registration applicability: the four child rows are now exact with validator-assigned UIDs UID0004N6 through UID0004N9, and a post-registration full-report search confirms that no allocation placeholder token remains. Manual coverage application remains external supervisor-owned work and was not performed by B004.

- Same file, replace UID0001O9 row:

```text
    - [UID:0001O9][0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper](by-memory/0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper.md) 0x0060c440-0x0060c44b | compiler static cleanup wrapper | UniAPIInitStaticCleanupWrapper : ignored : 91% : very-strong : Exact vptr-only static cleanup wrapper registered once by the live startup initializer; source lifetime is represented by the static UniAPIInit object and empty virtual destructor.
```

- Same file, replace UID00026S and UID0003E5 rows; leave UID0002P0 unchanged:

```text
    - [UID:00026S][0x0062e578-0x0062e624.UniApiUrlAlertReadOnlyData](by-memory/0x0062e578-0x0062e624.UniApiUrlAlertReadOnlyData.md) 0x0062e578-0x0062e624 | split vtable-data index | UniApiUrlAlertReadOnlyData : ignored : 90% : very-strong : Non-emitting mixed index over exact UniAPIInit and UrlAlertPane RTTI/vtable children with complete boundary, ownership, and generated-data dispositions.
        - [UID:0003E5][0x0062e578-0x0062e580.UniAPIInitVtableData](by-memory/0x0062e578-0x0062e580.UniAPIInitVtableData.md) 0x0062e578-0x0062e580 | RTTI/vtable-data | UniAPIInitVtableData : not_reconstructable : 94% : very-strong : Exact non-emitting UniAPIInit COL-pointer-plus-one-slot-vtable child with complete self-only RTTI hierarchy, scalar deleting destructor slot, static-object lifetime stores, and source class/destructor regeneration contract verified; no handwritten ABI data.
```

- Same file, replace UID00028B row:

```text
    - [UID:00028B][0x006702c4-0x006702c8.UniAPIInitVtablePointerSlot](by-memory/0x006702c4-0x006702c8.UniAPIInitVtablePointerSlot.md) 0x006702c4-0x006702c8 | static object storage | UniAPIInitVtablePointerSlot : reconstructable : 91% : very-strong : Exact four-byte file-local static UniAPIInit object storage initialized to the class address point and reset only by compiler cleanup; emits the static object declaration rather than a raw pointer.
```

- Same file, replace UID0001Q1 and UID0002A6 rows:

```text
    - [UID:0001Q1][0x0069bec4-0x0069bec8.g_browserControlKeyCallback](by-memory/0x0069bec4-0x0069bec8.g_browserControlKeyCallback.md) 0x0069bec4-0x0069bec8 | PlatformApi dispatch pointer | g_pfnSendMessageW : reconstructable : 91% : very-strong : Exact SendMessageW dispatch slot with startup assignment, broad consumers, stale browser alias history, and complete source declaration.
    - [UID:0002A6][0x0069bec8-0x0069bed0.WideApiDispatchTailPointers](by-memory/0x0069bec8-0x0069bed0.WideApiDispatchTailPointers.md) 0x0069bec8-0x0069bed0 | PlatformApi dispatch pointer pair | WideApiDispatchTailPointers : reconstructable : 91% : very-strong : Exact GetLocaleInfoW and SetFileAttributesW tail slots with complete source declarations, startup assignments, and boundary before unrelated user-list storage.
```

- File/placement: `by-class/-coverage-report.md`, replace UID0000FE row:

```text
- [UID:0000FE][UniAPIInit](by-class/UniAPIInit.md) : reconstructable : 93% : very-strong : Symbol-proven vptr-only PlatformApi helper class with complete self-only RTTI, public constructor and virtual destructor declaration, exact retained constructor/ordinary destructor source children, compiler deleting/cleanup/vtable support dispositions, and file-local static object lifetime.
```

- File/placement: `by-file/-coverage-report.md`, replace UID0000ML row:

```text
- [UID:0000ML][PlatformApi](by-file/PlatformApi.md) : reconstructable : 90% : strong : Platform/OLE compatibility source root with complete UniAPIInit class, constructor, empty virtual destructor, static object, wide API dispatch declarations/initializer semantics, compiler-wrapper dispositions, and preserved unrelated AutoInit/MAPI/helper evidence.
```

- File/placement: `by-global/-coverage-report.md`, replace UID0000TQ row:

```text
- [UID:0000TQ][WideApiDispatchTable](by-global/WideApiDispatchTable.md) : reconstructable : 92% : very-strong : PlatformApi-owned grouped function-pointer globals covering all 47 observed constructor assignments, including source declarations for SendMessageW and tail slots, with exact split storage, broad consumers, and rejected raw-dword/consumer-owned/forced-struct alternatives.
```

- Reason B agent must not apply it directly: all listed `-coverage-report.md` files are manual supervisor-owned coverage artifacts explicitly forbidden to B004. Validator-generated coverage refresh does not replace this manual text.

## Follow-Up Actions

- Lifecycle boundary: implementation and verification are complete, and no implementation item remains. Report validation, execution, count, path, move, and archive state remain external supervisor/validator-owned and are neither asserted nor directed by this artifact.
- A-agent actions: none required for this B report. Optional future IDA naming/type work is separately authorized work, not a prerequisite.
- B004 actions remaining: none. B004 performed the accepted C01-C44 callback, released every lease, and performed no report execution, probe, move, or archive command.

## Confidence

- Recommendation confidence: very strong.
- Score confidence: strong; `94/96` deliberately reflects near-final exact target evidence while keeping completion below 95 due absent source/PDB.
- Remaining uncertainty: original public formatting and `s_uniAPIInit` spelling only; neither changes class ABI, target disposition, constructor/destructor behavior, source route, split, or formal C++.

## Validator Results

- Every ordinary destination was leased only for its immediate edit, reread after lease acquisition, scoped-validated from `source-3/project-documentation`, and released immediately. All scoped commands returned exit `0`, `ok:1`.

| Command ID | Timestamp | Scoped path / purpose | Exit / ok | Applied side effects and result |
| --- | --- | --- | --- | --- |
| `000000010587` | `2026-07-14T03:17:32-04:00` | `by-memory/0x005995b0-0x005997dd.UniAPIInitConstructor.md` | `0 / 1` | Inserted UID0004N6; updated path/score/owner/autogen/reference registries and projected stats; generated refresh deferred. |
| `000000010589` | `2026-07-14T03:18:15-04:00` | `by-memory/0x005997e0-0x005997e7.UniAPIInitDestructor.md` | `0 / 1` | Inserted UID0004N7 with corresponding registry/reference/projected-stat updates; generated refresh deferred. |
| `000000010592` | `2026-07-14T03:19:05-04:00` | `by-memory/0x005997f0-0x00599a0b.RetainedWideApiDispatchInitProjection.md` | `0 / 1` | Inserted UID0004N8 with corresponding registry/reference/projected-stat updates; generated refresh deferred. |
| `000000010596` | `2026-07-14T03:19:48-04:00` | `by-memory/0x00599a10-0x00599a34.UniAPIInitScalarDeletingDestructor.md` | `0 / 1` | Inserted UID0004N9 with corresponding registry/reference/projected-stat updates; generated refresh deferred. |
| `000000010602` | `2026-07-14T03:21:34-04:00` | `by-memory/0x0062e578-0x0062e580.UniAPIInitVtableData.md` | `0 / 1` | Applied `94/96`, true-to-false autogen transition, emitter clearing, child references, and projected stats; generated refresh deferred. |
| `000000010605` | `2026-07-14T03:22:22-04:00` | `by-memory/0x0062e578-0x0062e624.UniApiUrlAlertReadOnlyData.md` | `0 / 1` | Applied `90/95`, normalized six child UID links, added four references, and updated projected stats; generated refresh deferred. |
| `000000010611` | `2026-07-14T03:23:43-04:00` | `by-memory/0x005995b0-0x00599a34.UniAPIInit.md` | `0 / 1` | Applied `92/94`, owner UID0000ML-to-NONE, true-to-false, emitter clearing, nine link normalizations, four reference additions, and one stale-reference removal; generated refresh deferred. |
| `000000010614` | `2026-07-14T03:24:24-04:00` | `by-memory/0x00599a40-0x00599cb3.UrlAlertPane.md` | `0 / 1` | Applied only `Nested:0 -> -8`; unrelated metadata/content remained unchanged; generated refresh deferred. |
| `000000010618` | `2026-07-14T03:25:25-04:00` | `by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md` | `0 / 1` | Applied `91/93`, true-to-false, emitter clearing, two link normalizations, two child references, and projected stats; generated refresh deferred. |
| `000000010621` | `2026-07-14T03:26:22-04:00` | `by-memory/0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper.md` | `0 / 1` | Applied `91/95`, added two source-child references, and updated projected stats; generated refresh deferred. |
| `000000010622` | `2026-07-14T03:26:57-04:00` | `by-memory/0x006702c4-0x006702c8.UniAPIInitVtablePointerSlot.md` | `0 / 1` | Applied `91/94`, normalized four links, added three child references, and updated projected stats; generated refresh deferred. |
| `000000010626` | `2026-07-14T03:28:09-04:00` | `by-class/UniAPIInit.md` | `0 / 1` | Applied `93/95`, normalized one UID link, added four child references, and updated projected stats; generated refresh deferred. |
| `000000010631` | `2026-07-14T03:29:19-04:00` | `by-file/PlatformApi.md` | `0 / 1` | Applied `90/88`, normalized two links, added four child references, and updated projected stats. It also reported three pre-existing unrelated `missing_ref_uid 0003OT` diagnostics; no UID0003OT page was changed. |
| `000000010633` | `2026-07-14T03:30:03-04:00` | `by-global/WideApiDispatchTable.md` | `0 / 1` | Applied `92/91`, normalized two links, added one constructor reference, and updated projected stats; generated refresh deferred. |
| `000000010636` | `2026-07-14T03:31:46-04:00` | `by-memory/0x0069bec4-0x0069bec8.g_browserControlKeyCallback.md` | `0 / 1` | Applied `91/93`, exact `SendMessageW` declaration, blank-to-block autogen transition, two link normalizations, two references, and projected stats; generated refresh deferred. |
| `000000010638` | `2026-07-14T03:32:37-04:00` | `by-memory/0x0069bec8-0x0069bed0.WideApiDispatchTailPointers.md` | `0 / 1` | Applied `91/93`, exact two tail declarations, blank-to-block autogen transition, two link normalizations, two references, and projected stats; generated refresh deferred. |
| `000000010640` | `2026-07-14T03:33:05-04:00` | final authorized target `--wait-generated` refresh | `0 / 1` | Rebuilt autogen registry (`4745` nodes / `3844` edges), refreshed `281` generated metadata outputs, and completed generated refresh. Project-wide informational diagnostics were `15` fallback inserts, `83` missing preferred children markers, and `198` emitting-children-only rows; none blocks this scoped callback. |

- Read-only generated proof for `auto-generated/NexusTK/platform/PlatformApi.cpp`: header command is exactly `000000010640`; one `class UniAPIInit`, one `UniAPIInit::UniAPIInit()`, one `UniAPIInit::~UniAPIInit()`, and one `static UniAPIInit s_uniAPIInit;`; 47 `g_pfn*` declarations and 47 constructor assignments; exact `SendMessageW`, `GetLocaleInfoW`, and `SetFileAttributesW` declarations/assignments are present through those counts.
- Negative generated proof: zero UID/code/empty-marker occurrences for target UID0003E5, aggregate UID0001KE, live wrapper UID0000WD, cleanup UID0001O9, duplicate UID0004N8, and scalar wrapper UID0004N9; no explicit `0x0062e57c`, `_atexit`, deleting-wrapper, vptr, RTTI-dword, or manual ABI body text.
- Verify-only proof: UID0002AS formal block remains exactly 44 dispatch declarations; UID0002P0 remains unchanged at `[0x0062e580,0x0062e624)` with its original `86/92`, owner/emitter UID0000FF, true, and `Nested:0` boundary state.

## Changed Files

- Created ordinary pages: `by-memory/0x005995b0-0x005997dd.UniAPIInitConstructor.md` (UID0004N6), `by-memory/0x005997e0-0x005997e7.UniAPIInitDestructor.md` (UID0004N7), `by-memory/0x005997f0-0x00599a0b.RetainedWideApiDispatchInitProjection.md` (UID0004N8), and `by-memory/0x00599a10-0x00599a34.UniAPIInitScalarDeletingDestructor.md` (UID0004N9).
- Modified ordinary pages: `by-memory/0x0062e578-0x0062e580.UniAPIInitVtableData.md`, `by-memory/0x0062e578-0x0062e624.UniApiUrlAlertReadOnlyData.md`, `by-memory/0x005995b0-0x00599a34.UniAPIInit.md`, `by-memory/0x00599a40-0x00599cb3.UrlAlertPane.md`, `by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md`, `by-memory/0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper.md`, `by-memory/0x006702c4-0x006702c8.UniAPIInitVtablePointerSlot.md`, `by-class/UniAPIInit.md`, `by-file/PlatformApi.md`, `by-global/WideApiDispatchTable.md`, `by-memory/0x0069bec4-0x0069bec8.g_browserControlKeyCallback.md`, and `by-memory/0x0069bec8-0x0069bed0.WideApiDispatchTailPointers.md`.
- Modified report: `tools/leaser/Agents/Agent-B004/research/0003E5-UniAPIInitVtableData-source-quality.md` with real UIDs, applied ledger/proof, validator/generated evidence, changed-file inventory, and checked callback state.
- Renamed: none. Verify-only and unchanged ordinary pages: UID0002AS and UID0002P0.
- Manual coverage, tracker, audit, supervisor, validator-state, IDA, lifecycle, queue, lock, and archive files: not manually edited. Generated output was refreshed only by authorized validator command `000000010640` and inspected read-only.
- Lease state: each ordinary-page lease was released immediately after its scoped validator; final lease inspection reports no B004 lease.
- Report lifecycle: B004 ran no `execute_report`, probe, count, move, archive, or other report lifecycle command.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation required before implementation: exact report SHA `22B88E9EBB75DAB6CB83A8DBC947E1BFF1CF76DB0617C7A149ADF5D290B528D1` received Gate 1 acceptance before any callback edit.
- [x] Target/support docs identified: UID0003E5, UID00026S, UID0001KE, UID0004N6-UID0004N9, UID0001KF nesting only, UID0000WD, UID0001O9, UID00028B, UID0000FE, UID0000ML, UID0000TQ, UID0001Q1, UID0002A6; UID0002AS/UID0002P0 verify-only.
- [x] Current target state and actual evidence recorded: exact bytes/hash, bounds, full RTTI, all xrefs, all lifetime bodies, generated source, reports, embeds, and manual coverage rows.
- [x] Claim And Incorporation Ledger updated with legal Action and Verification state for C01-C44 plus separate claim-by-claim destination proof.
- [x] Metadata/score changes applied: target `94/96`; every bounded support score/reclassification matches Recommended Support Doc Changes.
- [x] Score-limiting blockers researched to resolution: all named target/source/split/name/type/coverage/generated blockers are resolved; no rare exception is used.
- [x] Owner/emitter/reconstructable changes applied: target class-owned false/non-emitting; UID0001KE NONE/false; UID0000WD false; child ownership/emission exact above.
- [x] Split/new-child changes applied: no target split; four UID0001KE children registered in ascending order; no rename; UID0001KF relative nesting changed to `-8` only.
- [x] Source-placement, range/split/padding/reclassification, and optional IDA recommendations recorded: complete PlatformApi placement, exact ranges/padding, false reclassifications, and no unauthorized IDA mutation.
- [x] First-draft C++ and no-code proof applied: exact class, constructor, destructor, SendMessage, tail, and static blocks; all compiler/container blocks remain blank with exhaustive proof.
- [x] Third-party import decision applied: no matching embed/import; target multiline block remains blank.
- [x] Exact target/support facts incorporated at report-level detail: C01-C44 and destination sections preserve all bytes, hashes, xrefs, RTTI, liveness, source, history, and negatives.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: Wave3 name, one-dword history, no-route facts, old defer reason, and all rejected source/data/owner/split alternatives.
- [x] Wave2/Wave3 artifacts encountered were explicitly historicalized; current bytes/source model control.
- [x] Open questions closed or bounded: only original formatting/spelling remains nonblocking with score impact recorded.
- [x] Validators completed: one scoped file validation per changed ordinary page after its short lease, serial new-page registration, and final authorized `--wait-generated` refresh after all ordinary validations.
- [x] Generated/manual proof completed: one class, constructor, destructor, and static object; 47 declarations and 47 assignments; no target/parent/wrapper/cleanup/duplicate/scalar empty marker or ABI body; exact existing-UID and real-child-UID manual coverage text supplied for external supervisor handling.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation at the exact pre-callback SHA recorded above.
- [x] All accepted target/support details incorporated at report-level depth without removing unrelated or historical content.
- [x] C01-C44 ledger, legal states, and claim-by-claim destination proof reconciled to current implementation truth.
- [x] Metadata, scores, owners, emitters, split, nesting, and exact managed C++ changes applied; no rename was required.
- [x] Four children registered serially in ascending address order as UID0004N6, UID0004N7, UID0004N8, and UID0004N9; each UID was reread from its validator result; every allocation token was replaced in the report/manual-row text; full-report search confirms zero allocation placeholder remains.
- [x] Historical/stale assumptions, rejected alternatives, hashes, no-route facts, and negative evidence preserved.
- [x] Open questions resolved or documented with evidence-backed nonblocking uncertainty.
- [x] Every scoped validator and its command/timestamp/exit/ok/side effects recorded; every lease released immediately.
- [x] Validator command `000000010640` completed the final waited generated refresh; exact positive/negative readback is recorded above.
- [x] B004 performed no manual coverage/generated/tracker/audit/supervisor/validator-state/lifecycle edit and no report execute/probe/move/archive command; external lifecycle state is intentionally not tracked as pending implementation work.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000010687","destination_path":"executed-b-agent-research/B004/0003E5-UniAPIInitVtableData-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0003E5-UniAPIInitVtableData-source-quality.md","timestamp":"2026-07-14T03:57:13-04:00","uid":"0003E5"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
