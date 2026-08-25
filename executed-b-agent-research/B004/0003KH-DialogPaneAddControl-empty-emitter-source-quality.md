** TARGET-REPORT-UID:0003KH **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0003KH DialogPane AddControl Empty-Emitter Source-Quality Research


## Finalized Report / Current Recommendation

- Current implemented recommendation: [UID:0003KH] `by-memory/0x0049dc10-0x0049dc93.DialogPaneEnsureControlManagerAndAdd.md` is now `95/98` with the exact source-authored `void DialogPane::AddControl(ControlPane *control)` body in its formal CPP channel and a blank H channel; assignment-time state was `87/90` with blank formal code.
- Current disposition: canonical owner/emitter [UID:00003T] `DialogPane`, `RECONSTRUCTABLE:TRUE`, blank emitter position, and `Nested:0` are preserved. Callback command `000000018289` first emitted the method exactly once through [UID:00003T] -> [UID:0000IT] `NexusTK/ui/core/DialogPane.cpp`; the later supervisor Gate 2A generated readback preserves that exact topology.
- Applied support correction: the unsupported `void AddControl(unsigned char category, ControlPane *control);` declaration is removed from [UID:00003T]. The executable exposes exactly one `AddControl` function, and all 800 direct code xrefs pass one four-byte `ControlPane *` argument. The complete class declaration now resides in the class page's H channel with one supported AddControl declaration and `[[CHILDREN]]` exactly once; class CPP is blank and every unrelated declaration/field was preserved.
- Required source body:

```cpp
void DialogPane::AddControl(ControlPane *control)
{
    if (m_controlManager == NULL)
        m_controlManager = new List(sizeof(ControlPane *), 20);

    m_controlManager->Append(1, &control);
}
```

- Confidence: `98` for range, ABI, return, field, concrete container, allocation, append semantics, exception-lowering equivalence, ownership, and source route. The only material non-original-proof detail is the realistic source spelling `m_controlManager`; it is already the project-wide accepted field name and the live IDA member name.
- Current report lifecycle: initial implementation authorization passed Gate 1 at SHA `778BF6221BC0B82BCAB041A9B1DA3CACB031FD933E699C44E03F99569A843287`; after B004 completed the ordinary-document callback, the supervisor accepted the exact post-callback report SHA `56748DD399B94ABE61BA829E81F6349CC4AAFB9CC9A0FCE6244F39D0C6C61CE1` (72,080 bytes, 678 lines, 33 H2 headings, one execute marker) before the later supervisor stages. Supervisor Gate 2A, Gate 2B, IDB save/readback/catalog entry 0336, manual coverage application/validation, and current generated verification are complete. B004 performed no IDA, coverage, audit/catalog, or report-lifecycle mutation. Only supervisor-only `execute_report`/archive and post-execution registry/tracker confirmation remain.

## Supporting Research

- Live read-only IDA MCP session `5a570ede` targets `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. Final bounded health returned `status:ok`, module `NexusTK.exe`, imagebase `0x400000`, Hex-Rays ready, and strings cache ready with 2068 entries. `auto_analysis_ready:false` is context only under the explicit supervisor runtime override because all required bounded IDB-backed queries succeeded.
- Current target documentation already resolves most behavior but deliberately leaves formal C++ blank. That deliberate deferral is the assignment defect; it is not retained as a valid blocker.
- Assignment-time [UID:00003T] formal declaration contained both a one-argument and a two-argument category overload. Fresh binary/name/caller checks supported only the one-argument method. The category overload came from the historical custom-manager interpretation in the old B011 class report and survived later corrections even after the underlying object was proven generic `List`; the accepted callback removed only that overload.
- Historical pre-callback generated `auto-generated/NexusTK/ui/core/DialogPane.cpp` command `000000018160`, refreshed `2026-07-28T12:55:25-04:00`, SHA256 `754B5728FDA75319BDC620888EF30D2EC5A6EE40B3068ADAF5DFE1E2079AC073`, 19,578 bytes, 580 lines, had one UID0003KH Empty Emitter Marker, one one-argument declaration, one unsupported category declaration, zero target bodies, and no generated DialogPane.h.
- Historical callback generated state came from foreground command `000000018289`, refreshed `2026-07-28T13:58:10-04:00`: `DialogPane.cpp` SHA256 `28D17D7932E3C48393552456C5D3AEC8B2EBDE2A3A148ED8F18039BBA6C28701` and `DialogPane.h` SHA256 `9C4192B36813BD01D59157D8A874441F7122B02E164C2AF452F02A1E098891B8`. Current supervisor Gate 2A physical readback is `DialogPane.cpp` SHA256 `A640CD55F249CE1AB9739F05303418D99BED6ED17E956DF3D588F55950214B4F`, 16,854 bytes, 504 lines, and `DialogPane.h` SHA256 `C6CAAA259E2B3822C8961949123E2A91D3A459DFD409BD7A99458C87B2B193A8`, 3,257 bytes, 89 lines. Current physical invariants remain one UID0003KH target body/occurrence, zero target empty markers, zero category overloads, one class declaration in H, zero class declarations in CPP, one one-pointer declaration in H, and no duplicate/lost unrelated child code.
- Historical reports were used only as search leads. Fresh IDA and current ordinary docs control this recommendation. Stale Wave2/Wave3 references were ignored.

## Target

- Target UID: `0003KH`.
- Additional target UIDs: none.
- Declared-target inventory: [UID:0003KH] exact modeled method `[0x0049dc10,0x0049dc93)`; source-authored `DialogPane::AddControl(ControlPane *)`; direct class owner [UID:00003T].
- Target path: `by-memory/0x0049dc10-0x0049dc93.DialogPaneEnsureControlManagerAndAdd.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md`, `Files With Empty Emitters`, cross-screened against `by-memory / Not-Covered Files - Reconstructable`; assignment-time row `87/90`, average `88.5`, direct/additional/total report coverage `0/0/0`.
- Current supervisor classification: post-callback source-quality/empty-emitter repair with the post-callback Gate 1, independent Gate 2A, Gate 2B, manual coverage, and generated verification complete; only supervisor report execution/archive and post-execution registry/tracker confirmation remain.
- Assignment-time score and parent state: target `87/90`; owner/emitter UID00003T; class and file `92/94`; target formal CPP/H blank. Current callback state is target `95/98`, class `93/96`, file `93/95`, helper inventory `91/94`, layout `92/95`, and broad aggregate unchanged `92/94`.

## Current Target State

- Current metadata: `COMPLETION:95`, `CONFIDENCE:98`, `CANONICAL_OWNER:00003T`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00003T`, blank position, `Nested:0`.
- Current C++/emitter state: target CPP contains the exact accepted body; target H is blank. Current Gate 2A generated readback has one target body and zero target Empty Emitter Markers; command 18289 is preserved as historical callback provenance.
- Current implemented facts: exact range/padding, lazy allocation, `List(sizeof(ControlPane *), 20)`, `Append(1,&control)`, one-pointer ABI, four-byte pointer elements, exhaustive caller/negative evidence, ownership split, compiler lowering, source placement, score rationale, and historical category/custom-manager corrections are incorporated at report-level detail.
- Current external state: supervisor-owned C3KH-027 manual by-memory/class/file/type coverage application and validation are complete. B004 did not edit coverage.
- Related docs checked: UID00003T class, UID0000IT file, UID00012R broad method aggregate, UID00012S helper inventory, UID0001U4 layout, UID000079 List, List file/API docs, constructor/destructor/removal/find/count siblings, generated DialogPane source, research tracker, all relevant manual coverage rows, and matching historical B reports.
- Current artifact/lifecycle status: callback ordinary changes, post-callback Gate 1, independent Gate 2A, supervisor Gate 2B/save/readback/catalog, manual coverage validation, and current generated verification are complete. Only supervisor-only execute/archive and post-execution audit/registry/tracker confirmation remain.

## Executive Recommendation

- Implemented: exactly one protected, nonvirtual, source-authored `DialogPane::AddControl(ControlPane *)` definition emits from the exact child page.
- Use `new List(sizeof(ControlPane *), 20)`, not a raw 0x14-byte allocator call, direct constructor helper, custom `DialogControlManager`, vtable call, or byte argument.
- Keep `m_controlManager` as `List *` at `DialogPane+0x1fc`; List owns copied pointer slots, while DialogPane owns and destroys the pointed-to controls.
- Implemented: the unsupported category overload is removed from the class declaration. No second modeled `AddControl`, symbol, implementation page, call shape, or caller was found.
- Implemented: the complete class declaration is in the H channel, class CPP is blank, and `[[CHILDREN]]` remains once so exact by-memory bodies populate `DialogPane.cpp`.
- Keep the broad UID00012R and UID00012S aggregates nonduplicating. UID00012R remains a documentation aggregate with blank formal code; UID00012S remains nonreconstructable/nonemitting inventory.

## Supervisor Active Recheck

- The supervisor assigned UID0003KH because the current page is reconstructable, unreported, and emits an empty marker despite an already narrow source-authored method.
- No split repair is required. The exact modeled function is already isolated and aligned on both sides.
- Every source-bearing fact required for this child is resolved in this report: source signature, access, body, container type, element width, allocation, append operation, lifetime, exception behavior, owner/emitter, H/CPP placement, score, coverage payload, and IDA handoff.

## Inference Research Guidance Check

- Binary facts were separated from source reconstruction. Direct facts are the bytes, range, `__thiscall` ABI, one explicit pointer argument, `void` return, field offset, allocation size, constructor constants, virtual slot, xrefs, and cleanup behavior.
- Documentation evidence supplies accepted project names `DialogPane`, `ControlPane`, `List`, `m_controlManager`, `List::Append`, source path, and class access conventions.
- Inference supplies the realistic original spelling `AddControl`, `m_controlManager`, and use of `sizeof(ControlPane *)` rather than literal `4`. These names are consistent with the recovered project style and avoid IDA residue.
- Existing assumptions treated as uncertain: the category overload, custom manager ownership, byte argument, manager-owned controls, and the idea that blank formal C++ remained necessary.
- No Wave2/Wave3 artifact was accepted as authority. Any such historical mention was ignored.

## Heuristic / Inference Reanalysis And Validation

| Issue | Reanalysis and evidence | Resolution |
| --- | --- | --- |
| Function identity | Exact modeled `[0x49dc10,0x49dc93)`, current name/prototype, 800 direct code xrefs, broad derived-dialog callers. | `DialogPane::AddControl(ControlPane *)`, source-authored. |
| Return type | IDA prototype/disassembly return `void`; callers consume no result; `retn 4` removes one explicit stack argument. | `void`. |
| Argument width | Stack member `control` is size 4 and typed `ControlPane *`; vcall receives `&control`. | One `ControlPane *`, not `char` or category byte. |
| Field | Live DialogPane UDT ordinal 471 has `List *m_controlManager` at `+0x1fc`; constructor/cleanup agree. | Retain `m_controlManager`. |
| Concrete container | Allocation is `0x14`; ctor is List `(4,20)`; vtable slot `+0x18` is accepted `Append`; sibling methods use `GetElementAt` and `RemoveAt`. | Generic `List`, not a custom manager. |
| Element semantics | `Append(1,&control)` copies one element of size 4. Destructor retrieves and destroys pointed-to controls. | List owns slot storage; DialogPane owns ControlPane objects. |
| Allocation source shape | MSVC lowering calls allocator, conditionally constructs, records EH state, and has constructor-failure delete funclet. | Human source is `new List(sizeof(ControlPane *), 20)`. |
| Null behavior | Field is lazily initialized. If allocation returns null in observed lowering, the later dereference would fail; ordinary source new-expression preserves normal allocation/exception behavior and generated cleanup. | No extra fallback or null return is invented. |
| Method access | Method is called by constructors/methods of many derived dialogs and is currently in the protected helper surface. | Protected nonvirtual member. |
| Category overload | Only one AddControl function/name exists; category-name alternatives return zero; every direct call has one pointer argument. | Remove the unsupported two-argument declaration. |
| Header/source placement | Assignment-time complete class declaration sat in CPP formal channel; project rule requires declarations/header source in H. | Applied: class shell moved to H, body child in CPP. |
| Original spelling | No original PDB symbol survives. Existing project-wide source-facing spelling is stable and realistic. | Use `AddControl`, `control`, `m_controlManager`; do not retain raw labels. |
| Score blocker | Prior score cap was an intentionally deferred code decision. This pass resolves it and all source-quality dependencies. | Raise target to `95/98`. |

Rejected alternatives:

- `EnsureControlManagerAndAdd`, `RegisterControl`, or `AddControlByCategory`: less source-natural or contradicted by current class/caller evidence.
- `DialogControlManager *`: contradicted by exact List constructor/vtable/layout evidence.
- `std::vector<ControlPane *>`: contradicted by the project's authored `List` class and exact ABI.
- Inline class-body definition: no evidence requires inline placement; a distinct large out-of-line body with EH metadata exists.
- Return `bool`, pointer, or status: no value contract exists.
- Hand-written allocator, vtable slot, SEH frame, cleanup funclet, or null-check return: compiler lowering, not plausible authored source.

## Evidence Standards Used

- Strong/direct: live IDA function lookup, exact bytes, disassembly, decompile, stack frame, function type, comments, complete 800-xref result, direct callees, type inspection, and adjacent boundaries.
- Strong/corroborating: current exact List constructor/Append docs, DialogPane constructor/destructor/removal/find/count docs, class/layout/file route, and generated source.
- Inference: source identifiers and `sizeof` spelling, constrained by current project style and all direct facts.
- Negative evidence: exact symbol/name queries for AddControl alternatives, absence of any second AddControl function, absence of data xrefs, no second-argument caller shape, and no custom-manager implementation.
- Tool limitation: no surviving original symbol proves exact historical spelling. That limits confidence from 100 but does not justify retaining decompiler labels or blank source.

## Evidence Checked

- IDA MCP: `server_health`, `lookup_funcs`, `analyze_function`, `decompile`, `disasm`, `get_bytes`, `callees`, `xrefs_to`/full xref result, `get_comments`, `stack_frame`, `type_query`, `type_inspect`, and `entity_query`.
- Exact functions checked: target, predecessor, successor, allocator wrapper, List constructor, List Append, DialogPane constructor/ordinary destructor, pointer/index removal, pointer lookup, raw count accessor, and representative BrowserDialog caller.
- Documentation checked: target; DialogPane class/file/layout; broad/helper aggregates; List class/file and exact API pages; sibling controls; generated DialogPane source; research tracker; manual memory/class/file/type coverage; matching executed reports.
- Negative checks: AddControl name inventory, proposed/alternative name collisions, second AddControl implementation, category argument use, non-code xrefs, unsupported owner candidates, generated duplicates, and range overlap.
- Initial report-only phase intentionally skipped IDA mutation/save, validators, generated refresh, coverage edits, and report lifecycle. During the accepted callback B004 ran only the authorized scoped ordinary-file validators and one foreground generated refresh; B004 left IDA, coverage, and lifecycle untouched. The supervisor later completed independent Gate 2A, Gate 2B with saved-IDB readback/catalog entry 0336, and manual coverage application/validation.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C3KH-001 | 0003KH | Exact range is `[0x0049dc10,0x0049dc93)`, size `0x83`. | Direct | lookup/disasm/bytes | target Status/IDA evidence | incorporate | applied/read back; SHA `5F881BD4D79AC8DDA02686E50D45B2F030296F305F9686A751000011C60D3093`; validator 18257 ok1 |
| C3KH-002 | 0003KH | Predecessor ends `0x49dc05`; 11 CC bytes precede target. | Direct | lookup/bytes | target Range | incorporate | applied/read back; target validator 18257 ok1 |
| C3KH-003 | 0003KH | Thirteen CC bytes follow target before successor `0x49dca0`. | Direct | lookup/bytes | target Range | incorporate | applied/read back; target validator 18257 ok1 |
| C3KH-004 | 0003KH | Exact source ABI is `void __thiscall(DialogPane *, ControlPane *)`. | Direct | function type/stack/disasm | target Behavior/CPP | incorporate | applied/read back; exact CPP generated once by historical callback command 18289 and preserved in current Gate 2A output |
| C3KH-005 | 0003KH | Field is `List *m_controlManager` at `+0x1fc`. | Direct/strong | UDT/decompile/layout | target/class/layout | incorporate | applied/read back in target/class/layout; validators 18257/18266/18287 ok1 |
| C3KH-006 | 0003KH | Null field triggers 0x14-byte allocation and `List(4,20)` construction. | Direct | disasm/decompile | target Behavior | incorporate | applied as exact binary plus source-shaped `sizeof` evidence; 18257 ok1 |
| C3KH-007 | 0003KH | Append vslot `+0x18` receives `(1,&control)`. | Direct | disasm/List docs | target Behavior/CPP | incorporate | applied/read back; target CPP exact; callback validators 18257/18289 and current Gate 2A passed |
| C3KH-008 | 0003KH | Element is one copied four-byte `ControlPane *`. | Direct/strong | ctor/Append/destructor | target Ownership | incorporate | applied at report-level detail across target/support docs |
| C3KH-009 | 0003KH | DialogPane owns pointed-to controls; List owns slot storage. | Strong | destructor/remove callers | target/class/file | incorporate | applied/read back in target/class/file/helper/layout/aggregate |
| C3KH-010 | 0003KH | MSVC EH funclet is compiler lowering of the new expression. | Direct/inference | disasm EH range | target Exception behavior | incorporate | applied with exact funclet/security-handler boundaries |
| C3KH-011 | 0003KH | Complete caller set is 800 code xrefs, 88 modeled callers, one unmodeled site. | Direct | full xref result | target/aggregate/file | incorporate | applied with zero-data/indirect conclusion in target/file/helper/aggregate |
| C3KH-012 | 0003KH | No indirect/data owner route exists in the xref result. | Direct negative | xref types | target Negative evidence | incorporate | applied/read back; no unsupported owner route introduced |
| C3KH-013 | 0003KH | Source body uses `new List(sizeof(ControlPane *), 20)`. | Strong inference | ABI/project style | target formal CPP | insert | applied exact formal CPP; historical command 18289 and current Gate 2A both verify one generated body |
| C3KH-014 | 0003KH | Target H remains blank. | Structural | emitter topology | target formal H | preserve blank | verified blank after callback validator 18257/refresh 18289 and current Gate 2A |
| C3KH-015 | 0003KH | Target becomes `95/98`; route/flags/position/Nested unchanged. | Strong | all evidence | target metadata | update | applied/read back; validator 18257 ok1 |
| C3KH-016 | 00003T | Remove unsupported category AddControl declaration. | Strong negative | name/function/caller inventory | class declaration/prose | remove/correct | applied; generated category overload count 0 |
| C3KH-017 | 00003T | Move complete declaration byte-for-text from CPP to H, with one accepted AddControl declaration and one `[[CHILDREN]]`. | Structural | current rule/generated state | class formal channels | move/correct | applied; class CPP blank/H complete; generated H class 1, CPP class 0 |
| C3KH-018 | 00003T | Class becomes `93/96`, preserving owner/emitter and all unrelated content. | Strong | corrected API/source route | class metadata | update | applied/read back; SHA `A5C705AE6E0F313DCC893927F571EDC5B2CAE7B890AAC01CCD1C3E1F604DC18E`; validator 18266 ok1 |
| C3KH-019 | 0000IT | File records exact AddControl body/header route and 800-call shared infrastructure. | Strong | target/class/callers | file role/inventory | incorporate | applied/read back; SHA `47062D446DB04849FEAFABD830571053DFE97A592347C9BC5CA127214A940513`; callback validators 18275/18289 and independent Gate 2A ok1 |
| C3KH-020 | 0000IT | File becomes `93/95`; path and file ownership unchanged. | Strong | source closure | file metadata | update | applied/read back; path/FILE ownership preserved |
| C3KH-021 | 00012S | Inventory records source-ready child, complete caller count, and rejected category overload while remaining nonemitting. | Strong | child/live xrefs | helper inventory | incorporate | applied/read back; SHA `8222A28BEC439B7FEAA1FC6AF17C8863C18795536A24070B8619CD1A816A1648`; validator 18282 ok1 |
| C3KH-022 | 00012S | Inventory becomes `91/94`, remains owner NONE, false, no emitter. | Strong | corrected child inventory | aggregate metadata | update | applied/read back; blank CPP/H and route preserved |
| C3KH-023 | 0001U4 | Layout records live UDT ordinal 471/readback and exact List pointer semantics. | Direct | type_inspect | layout evidence | incorporate | applied/read back; SHA `B76A8DE3CBD32439E9AAAFF7FD81EF77CFBF55CA66FE274F70793DD4CBFCBDAB`; validator 18287 ok1 |
| C3KH-024 | 0001U4 | Layout becomes `92/95`, route unchanged, formal code blank. | Strong | live UDT plus child | layout metadata | update | applied/read back; owner/emitter UID00003T preserved |
| C3KH-025 | 00012R | Broad aggregate adds exact AddControl child status but stays `92/94` and blank/nonduplicating. | Strong | exact child route | broad aggregate | incorporate only | applied bounded prose; SHA `9677744EB82FC0096A0EF6C61C1A8680F169CF7E899CBE70D4EB4C68239C934C`; validator 18288 ok1 |
| C3KH-026 | 000079 | Existing List declaration/API already supplies same-or-greater facts; no edit. | Strong | current docs/live helper | List class | verify unchanged | reread and verified same-or-greater; List/sibling pages unchanged |
| C3KH-027 | coverage | Manual rows need exact target insertion and stale support replacements. | Direct doc | manual coverage readback | supervisor-owned coverage files | supervisor apply | supervisor applied/validated exit0/ok1: memory child 95/helper 91/bounded aggregate, class 93, file 93, type 92; current coverage hashes recorded below; B004 did not edit |
| C3KH-028 | IDA | Preserve target name/type/current regular comment; add exact function-repeatable source-quality comment after fresh prestate check. | Strong | live prestate | supervisor Gate 2B | supervisor apply | supervisor applied/read back/saved; only function-repeatable channel changed; saved IDB SHA `8F2811531D092B6EF367402393E3BBF5AB2DE05738E2D0A22BE8A644C6D95F46`; catalog entry 0336 |
| C3KH-029 | generated | Expected output is DialogPane.h class declaration and exactly one target body in DialogPane.cpp, with zero target empty markers and no category overload. | Structural | accepted topology | validator-generated output | verify after callback | callback command 18289 historical; current Gate 2A verified CPP SHA `A640CD55F249CE1AB9739F05303418D99BED6ED17E956DF3D588F55950214B4F`, H SHA `C6CAAA259E2B3822C8961949123E2A91D3A459DFD409BD7A99458C87B2B193A8`, and all semantic counts |

## Positive Evidence Summary

- The target is a complete modeled function with exact boundaries and normal member-function ABI.
- Live typing identifies the receiver, argument, return, and field without casts or guessed widths.
- The actual object at `+0x1fc` is independently proven as generic List by constructor, vtable, sibling operations, destructor behavior, and accepted List docs.
- All 800 direct xrefs are code calls from dialog construction/layout routines, strongly proving shared base-class ownership and protected member access.
- One natural source body explains every semantic instruction and the compiler-generated allocation cleanup path.
- The current project already uses `new List(sizeof(Type), pageSize)` in recovered source, making `sizeof(ControlPane *)` the consistent human-written spelling.

## IDA MCP Facts

- Session: `5a570ede`; IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; live health `status:ok`.
- Target: `DialogPane_AddControl`, `[0x49dc10,0x49dc93)`, size `0x83`, 57 disassembly instructions including EH funclets, prototype `void __thiscall(DialogPane *this, ControlPane *control)`.
- Exact target bytes:

```text
55 8B EC 6A FF 68 09 D5 5F 00 64 A1 00 00 00 00 50 51 56 A1 24 2F 67 00 33 C5 50 8D 45 F4 64 A3 00 00 00 00 8B F1 8B 8E FC 01 00 00 85 C9 75 36 6A 14 E8 59 6E 05 00 83 C4 04 89 45 F0 C7 45 FC 00 00 00 00 85 C0 74 0F 6A 14 6A 04 8B C8 E8 FD 53 05 00 8B C8 EB 02 33 C9 C7 45 FC FF FF FF FF 89 8E FC 01 00 00 8B 01 8D 55 08 52 6A 01 FF 50 18 8B 4D F4 64 89 0D 00 00 00 00 59 5E 8B E5 5D C2 04 00
```

- Predecessor `DialogPane_SetBackgroundResource` is `[0x49db60,0x49dc05)`; `0x49dc05-0x49dc10` is eleven `CC` bytes.
- Successor `DialogPane_RemoveControl` begins `0x49dca0`; `0x49dc93-0x49dca0` is thirteen `CC` bytes.
- Direct callees: `sub_4F4AA0` allocator wrapper and `sub_4F3060` List constructor. Append is an indirect virtual call through List vslot `+0x18`.
- EH cleanup at `0x5fd4fe` calls `NexusTK_operator_delete_wrapper` for a constructor failure; `0x5fd509` is the security-cookie/C++ frame-handler path. These are compiler lowering.
- Stack frame: `Block +0x8 void *`, `var_C +0xc _DWORD`, `var_4 +0x14 _DWORD`, saved registers `+0x18`, return address `+0x1c`, source argument `control +0x20 ControlPane *`, and EH metadata `arg_4 +0x24 _DWORD`.
- DialogPane type ordinal 471 is size `0x26c` with exact `List *m_controlManager` member at `+0x1fc`.
- ControlPane type ordinal 443 is size `0x108`.
- List ordinal 485 and LObject ordinal 516 are named incomplete types in this IDA build, size sentinel `0xffffffffffffffff`, safe for pointer declarations. Their full source layouts are controlled by existing List/LObject docs, not completed by this target.
- `entity_query(functions, AddControl)` returns exactly one function. Exact name query `^DialogPane_AddControl$` returns one row at target. `DialogPane_AddControlControlPane` and `DialogPane_AddControlByCategory` return zero.
- Xrefs: exactly 800 inbound entries, all code; 88 modeled function groups and one call site at `0x452ceb` whose containing function metadata is absent from the xref response; zero data xrefs.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0049db60-0x0049dc05` | UID0003KG | predecessor `SetBackgroundResource` | true | UID00003T | `92/94` | separate exact child |
| `0x0049dc05-0x0049dc10` | aggregate-only padding | 11 CC bytes | false | none | n/a | preserve |
| `0x0049dc10-0x0049dc93` | UID0003KH target | `AddControl(ControlPane *)` | true | UID00003T | assignment `87/90`; current `95/98` | exact body applied/emitted once |
| `0x0049dc93-0x0049dca0` | aggregate-only padding | 13 CC bytes | false | none | n/a | preserve |
| `0x0049dca0-0x0049dcf8` | UID0003KI | pointer removal overload | true | UID00003T | `90/92` | existing exact child |
| `0x004f4aa0-0x004f4ab4` | allocation support | project operator-new wrapper | support | MemoryMan/runtime route | n/a | protect; no target-local IDA action |
| `0x004f3060-0x004f30d5` | UID000191 support | List constructor | true | UID000079 | current List score | existing exact API |
| `0x004f33c0-0x004f33d5` | UID0003JY support | List Append | true | UID000079 | current List score | existing exact API |

## Direct Xref / Caller Inventory

- Complete live result: 800 direct code call sites, zero data xrefs, grouped below into all 88 modeled caller functions plus the one unmodeled call site. Counts sum to 800.

| Caller range | Current name | Count | Exact call sites |
| --- | --- | ---: | --- |
| 0x41bdd0-0x41c250 | sub_41BDD0 | 8 | 0x41bfa9, 0x41bfea, 0x41c03a, 0x41c07c, 0x41c0be, 0x41c103, 0x41c148, 0x41c1af |
| 0x41cdc0-0x41d14b | sub_41CDC0 | 10 | 0x41ce7d, 0x41cec8, 0x41cf13, 0x41cf5e, 0x41cfa9, 0x41cff4, 0x41d03f, 0x41d08a, 0x41d0d5, 0x41d120 |
| 0x450ca0-0x451322 | sub_450CA0 | 11 | 0x450ea1, 0x450eef, 0x450f86, 0x450fcf, 0x451033, 0x45107c, 0x4510be, 0x45110a, 0x451153, 0x45119f, 0x4511e8 |
| 0x4523d0-0x452cda | sub_4523D0 | 8 | 0x45253c, 0x452544, 0x45271a, 0x45292c, 0x4529b1, 0x452b7b, 0x452bd1, 0x452c7c |
| 0x458610-0x45894b | sub_458610 | 7 | 0x4586ef, 0x45872f, 0x45876f, 0x4587b1, 0x4587f3, 0x458838, 0x45887d |
| 0x45dba0-0x45dd56 | RankingRewardInfoDialog_RankingRewardInfoDialog | 1 | 0x45dc81 |
| 0x469290-0x469426 | sub_469290 | 1 | 0x46937e |
| 0x46aa40-0x46ad0a | BrowserDialog_BrowserDialog | 4 | 0x46ab52, 0x46ab9c, 0x46ac66, 0x46acab |
| 0x46d050-0x46d324 | sub_46D050 | 2 | 0x46d191, 0x46d20e |
| 0x46e2a0-0x46e4b6 | WebBoardDialog_RefreshLayout | 2 | 0x46e38c, 0x46e40d |
| 0x46e640-0x46e8be | sub_46E640 | 3 | 0x46e73c, 0x46e78e, 0x46e7e0 |
| 0x472070-0x472869 | sub_472070 | 8 | 0x47236c, 0x4723c7, 0x472422, 0x47247c, 0x4726fc, 0x472757, 0x4727b2, 0x47280c |
| 0x472ca0-0x47398d | sub_472CA0 | 18 | 0x473020, 0x473075, 0x4730cf, 0x47313c, 0x4731a7, 0x473202, 0x473263, 0x4732c2, 0x473326, 0x47362d, 0x473682, 0x4736dc, 0x473749, 0x4737b4, 0x47380f, 0x473873, 0x4738d2, 0x473930 |
| 0x4753e0-0x476315 | sub_4753E0 | 24 | 0x4756da, 0x475731, 0x47579b, 0x475806, 0x475861, 0x4758bc, 0x475917, 0x475977, 0x4759d8, 0x475a3c, 0x475a9d, 0x475b94, 0x475e07, 0x475e5e, 0x475ec8, 0x475f33, 0x475f8e, 0x475fe9, 0x476044, 0x4760a7, 0x476108, 0x47616c, 0x4761cd, 0x4762c1 |
| 0x476c10-0x477151 | sub_476C10 | 12 | 0x476cda, 0x476d2c, 0x476d7e, 0x476dd0, 0x476e37, 0x476ea3, 0x476f14, 0x476f66, 0x476fb8, 0x47700d, 0x477077, 0x4770e3 |
| 0x4777a0-0x4781e5 | sub_4777A0 | 14 | 0x4778cc, 0x477924, 0x477975, 0x4779db, 0x477a7d, 0x477b31, 0x477ca7, 0x477d8d, 0x477de2, 0x477e36, 0x477e9f, 0x477f41, 0x477ff1, 0x478167 |
| 0x479110-0x479d2b | sub_479110 | 16 | 0x479490, 0x4794e5, 0x47953f, 0x4795aa, 0x479605, 0x479662, 0x4796cd, 0x47972c, 0x479a32, 0x479a87, 0x479ae1, 0x479b4c, 0x479ba7, 0x479c04, 0x479c6f, 0x479cce |
| 0x47b220-0x47c405 | sub_47B220 | 24 | 0x47b67b, 0x47b6d2, 0x47b73d, 0x47b798, 0x47b7f5, 0x47b85d, 0x47b8b8, 0x47b913, 0x47b974, 0x47b9d8, 0x47ba39, 0x47bb2e, 0x47befb, 0x47bf55, 0x47bfc0, 0x47c01b, 0x47c078, 0x47c0e0, 0x47c13b, 0x47c196, 0x47c1f7, 0x47c25b, 0x47c2bc, 0x47c3b1 |
| 0x47d050-0x47d7c1 | sub_47D050 | 14 | 0x47d131, 0x47d183, 0x47d1d5, 0x47d263, 0x47d2ca, 0x47d336, 0x47d3c4, 0x47d456, 0x47d525, 0x47d577, 0x47d5c9, 0x47d657, 0x47d6be, 0x47d72a |
| 0x4824e0-0x482b01 | sub_4824E0 | 6 | 0x482677, 0x4826c6, 0x482718, 0x482806, 0x48289e, 0x4829c4 |
| 0x488b40-0x488eab | sub_488B40 | 5 | 0x488c7e, 0x488cd3, 0x488d2b, 0x488d8f, 0x488dff |
| 0x489600-0x489de1 | sub_489600 | 11 | 0x489931, 0x489986, 0x4899e1, 0x489a45, 0x489aa9, 0x489b0d, 0x489b74, 0x489bde, 0x489c4e, 0x489cc4, 0x489d3a |
| 0x48a1c0-0x48a68a | sub_48A1C0 | 7 | 0x48a370, 0x48a3c5, 0x48a41d, 0x48a481, 0x48a4eb, 0x48a571, 0x48a5e7 |
| 0x48a810-0x48ace5 | sub_48A810 | 7 | 0x48a9c2, 0x48aa17, 0x48aa6f, 0x48aad3, 0x48ab3d, 0x48abcc, 0x48ac42 |
| 0x48b1c0-0x48b5f3 | sub_48B1C0 | 6 | 0x48b2d3, 0x48b32e, 0x48b3b9, 0x48b435, 0x48b4bf, 0x48b56a |
| 0x48c640-0x48cf75 | CollectionDialogPane_CollectionDialogPane | 14 | 0x48c7f2, 0x48c847, 0x48c899, 0x48c8ee, 0x48c94d, 0x48c99a, 0x48ca56, 0x48cbf2, 0x48cc47, 0x48cc99, 0x48ccee, 0x48cd4d, 0x48cd9a, 0x48ce55 |
| 0x49feb0-0x4a0575 | sub_49FEB0 | 5 | 0x4a0123, 0x4a0135, 0x4a02ec, 0x4a0304, 0x4a035d |
| 0x4a1d70-0x4a22ef | sub_4A1D70 | 5 | 0x4a1e64, 0x4a1eb3, 0x4a1f05, 0x4a1f57, 0x4a221d |
| 0x4a41c0-0x4a456b | sub_4A41C0 | 6 | 0x4a4285, 0x4a42d7, 0x4a432c, 0x4a43c3, 0x4a4459, 0x4a44e5 |
| 0x4a4770-0x4a4a25 | sub_4A4770 | 5 | 0x4a4827, 0x4a4873, 0x4a48c5, 0x4a491a, 0x4a4981 |
| 0x4ac8a0-0x4ad0aa | sub_4AC8A0 | 12 | 0x4ac9f9, 0x4aca51, 0x4acaac, 0x4acb07, 0x4acbb2, 0x4acc66, 0x4accf8, 0x4acd5f, 0x4ace16, 0x4ace81, 0x4acf05, 0x4acf83 |
| 0x4ae4c0-0x4ae8f5 | AddItemDialog_AddItemDialog | 8 | 0x4ae581, 0x4ae5cd, 0x4ae61f, 0x4ae6a3, 0x4ae730, 0x4ae77f, 0x4ae7d1, 0x4ae854 |
| 0x4af040-0x4af371 | AddItemWithCountDialog_AddItemWithCountDialog | 5 | 0x4af10f, 0x4af164, 0x4af1bf, 0x4af25a, 0x4af2ca |
| 0x4af570-0x4af8af | MixItemDialog_MixItemDialog | 6 | 0x4af649, 0x4af695, 0x4af6e4, 0x4af736, 0x4af788, 0x4af802 |
| 0x4b0490-0x4b0819 | sub_4B0490 | 4 | 0x4b067e, 0x4b06fe, 0x4b0717, 0x4b076f |
| 0x4b1590-0x4b18d6 | sub_4B1590 | 3 | 0x4b165b, 0x4b16af, 0x4b16f9 |
| 0x4f9d30-0x4fa0a9 | NewUserDialogPane_NewUserDialogPane | 6 | 0x4f9e10, 0x4f9e5f, 0x4f9eb1, 0x4f9f1e, 0x4f9f8d, 0x4fa003 |
| 0x4fa7a0-0x4faacd | LoginDialogPane_LoginDialogPane | 5 | 0x4fa880, 0x4fa8c6, 0x4fa912, 0x4fa995, 0x4faa01 |
| 0x4fb630-0x4fbfcf | sub_4FB630 | 17 | 0x4fb706, 0x4fb755, 0x4fb7a7, 0x4fb828, 0x4fb8a9, 0x4fb918, 0x4fb988, 0x4fb9dd, 0x4fba32, 0x4fbaa6, 0x4fbb2c, 0x4fbbe0, 0x4fbc80, 0x4fbd31, 0x4fbdd1, 0x4fbe72, 0x4fbf13 |
| 0x4fdd40-0x4fe460 | sub_4FDD40 | 14 | 0x4fde25, 0x4fde71, 0x4fdec3, 0x4fdf2d, 0x4fdf99, 0x4fe00c, 0x4fe082, 0x4fe14b, 0x4fe19a, 0x4fe1ec, 0x4fe259, 0x4fe2c8, 0x4fe33e, 0x4fe3ba |
| 0x4ffaa0-0x4ffd1d | StaffsDialogPane__Constructor | 3 | 0x4ffb8a, 0x4ffc08, 0x4ffc89 |
| 0x500090-0x5003e3 | BackStoryDialogPane__BackStoryDialogPane | 6 | 0x500174, 0x5001c6, 0x500217, 0x5002ae, 0x5002fd, 0x50034e |
| 0x500410-0x5005b4 | NewHistoryDialogPane__Constructor | 2 | 0x5004e7, 0x50053e |
| 0x5008c0-0x500c24 | sub_5008C0 | 4 | 0x500a8f, 0x500b09, 0x500b21, 0x500b7b |
| 0x517f30-0x518e17 | sub_517F30 | 19 | 0x5181de, 0x518233, 0x51828b, 0x5182e6, 0x51833d, 0x5183a7, 0x518500, 0x518770, 0x5187c5, 0x51881d, 0x518878, 0x5188cc, 0x518936, 0x518a6f, 0x518b71, 0x518bdc, 0x518c30, 0x518c9d, 0x518dac |
| 0x5198e0-0x51a276 | sub_5198E0 | 14 | 0x519b45, 0x519b9a, 0x519bf5, 0x519c50, 0x519ca4, 0x519d0b, 0x519d84, 0x519fe8, 0x51a03d, 0x51a095, 0x51a0f0, 0x51a144, 0x51a1ab, 0x51a21e |
| 0x51a520-0x51ac8e | sub_51A520 | 8 | 0x51a95c, 0x51a9b4, 0x51aa0f, 0x51aa6a, 0x51aabe, 0x51ab25, 0x51ab82, 0x51abea |
| 0x51b880-0x51c30a | sub_51B880 | 14 | 0x51bb5b, 0x51bbb0, 0x51bc08, 0x51bc63, 0x51bcba, 0x51bd24, 0x51bd86, 0x51c08a, 0x51c0df, 0x51c137, 0x51c192, 0x51c1e6, 0x51c250, 0x51c2b2 |
| 0x51ca40-0x51d51a | sub_51CA40 | 14 | 0x51cd5f, 0x51cdb4, 0x51ce0c, 0x51ce67, 0x51cebe, 0x51cf28, 0x51cf85, 0x51d29f, 0x51d2f4, 0x51d34c, 0x51d3a7, 0x51d3fb, 0x51d465, 0x51d4c2 |
| 0x51db40-0x51e4d3 | sub_51DB40 | 14 | 0x51ddb8, 0x51de0d, 0x51de65, 0x51dec0, 0x51df17, 0x51df81, 0x51dfde, 0x51e258, 0x51e2ad, 0x51e305, 0x51e360, 0x51e3b4, 0x51e41e, 0x51e47b |
| 0x51e9a0-0x51f136 | sub_51E9A0 | 8 | 0x51ee04, 0x51ee5c, 0x51eeb7, 0x51ef12, 0x51ef66, 0x51efcd, 0x51f02a, 0x51f092 |
| 0x51fc90-0x51ff6c | sub_51FC90 | 5 | 0x51fd47, 0x51fd93, 0x51fde5, 0x51fe3a, 0x51fea1 |
| 0x5200d0-0x5203be | sub_5200D0 | 5 | 0x5201a2, 0x5201ee, 0x520240, 0x520295, 0x5202fc |
| 0x528e60-0x52976c | sub_528E60 | 15 | 0x528f30, 0x528fc5, 0x52900d, 0x5290b3, 0x529101, 0x5291a7, 0x529208, 0x52928a, 0x5292da, 0x52942e, 0x5294b8, 0x529503, 0x529551, 0x5295a2, 0x5295f0 |
| 0x52a540-0x52b047 | sub_52A540 | 22 | 0x52a63c, 0x52a6af, 0x52a72b, 0x52a7a7, 0x52a805, 0x52a866, 0x52a90f, 0x52a9b8, 0x52aa32, 0x52aa8a, 0x52aae2, 0x52ab3a, 0x52ab9c, 0x52ac01, 0x52ac88, 0x52aced, 0x52ad52, 0x52adb7, 0x52ae4f, 0x52aec2, 0x52af14, 0x52af66 |
| 0x52c360-0x52cd49 | sub_52C360 | 20 | 0x52c463, 0x52c4d6, 0x52c552, 0x52c5ce, 0x52c62c, 0x52c68d, 0x52c6f1, 0x52c755, 0x52c7ba, 0x52c819, 0x52c87b, 0x52c8f8, 0x52c95a, 0x52c9b9, 0x52ca1b, 0x52caba, 0x52cb2d, 0x52cb8f, 0x52cbf1, 0x52cc50 |
| 0x52dd30-0x52e6eb | CreateUserDialogPane_Constructor | 19 | 0x52de32, 0x52dea5, 0x52df21, 0x52df9d, 0x52dff9, 0x52e058, 0x52e0c2, 0x52e126, 0x52e1a7, 0x52e228, 0x52e28a, 0x52e2ec, 0x52e34e, 0x52e3b0, 0x52e429, 0x52e48b, 0x52e4ed, 0x52e54c, 0x52e65b |
| 0x52f950-0x52ff9b | NexonclubRegistrationDialog__NexonclubRegistrationDialog | 14 | 0x52fa2d, 0x52fa84, 0x52faed, 0x52fb62, 0x52fbb0, 0x52fc01, 0x52fc52, 0x52fce7, 0x52fd3e, 0x52fdaa, 0x52fe1f, 0x52fe6d, 0x52febe, 0x52ff0f |
| 0x530640-0x530b00 | sub_530640 | 10 | 0x530728, 0x530774, 0x5307c6, 0x53081b, 0x530882, 0x53090f, 0x53095e, 0x5309b0, 0x530a05, 0x530a72 |
| 0x53d820-0x53dd4f | sub_53D820 | 7 | 0x53d915, 0x53d967, 0x53da00, 0x53dc10, 0x53dc51, 0x53dc92, 0x53dcd3 |
| 0x53e520-0x53e8cf | sub_53E520 | 6 | 0x53e5e2, 0x53e631, 0x53e6b2, 0x53e752, 0x53e7a4, 0x53e828 |
| 0x53e960-0x53ecd0 | sub_53E960 | 6 | 0x53ea22, 0x53ea71, 0x53ead5, 0x53eb71, 0x53ebc3, 0x53ec2d |
| 0x53ed90-0x53f07f | sub_53ED90 | 5 | 0x53ee70, 0x53eebf, 0x53ef3c, 0x53efa0, 0x53eff2 |
| 0x53f2c0-0x53f801 | sub_53F2C0 | 8 | 0x53f382, 0x53f3d4, 0x53f468, 0x53f50c, 0x53f5d6, 0x53f628, 0x53f6b8, 0x53f75c |
| 0x53f940-0x53fd95 | sub_53F940 | 7 | 0x53fa02, 0x53fa8d, 0x53fb0f, 0x53fb9a, 0x53fc25, 0x53fcac, 0x53fcfe |
| 0x541b30-0x541e29 | sub_541B30 | 5 | 0x541c1a, 0x541c69, 0x541cd5, 0x541d39, 0x541d8b |
| 0x542270-0x54248e | TargetOptionDialog_TargetOptionDialog | 3 | 0x542325, 0x542377, 0x5423ec |
| 0x545250-0x54565b | sub_545250 | 3 | 0x545349, 0x54546b, 0x545531 |
| 0x5470b0-0x5473ed | sub_5470B0 | 3 | 0x547277, 0x5472e7, 0x54734b |
| 0x548690-0x548a06 | PatchPane2__Constructor | 3 | 0x54885a, 0x5488cc, 0x54891e |
| 0x549c20-0x54a472 | PowerDialogPane__Constructor | 9 | 0x549cfa, 0x549d52, 0x549dad, 0x549e08, 0x549e63, 0x549ebe, 0x549f19, 0x549fcd, 0x54a134 |
| 0x54ce10-0x54db3e | sub_54CE10 | 12 | 0x54d109, 0x54d1a9, 0x54d25c, 0x54d30f, 0x54d3bd, 0x54d427, 0x54d731, 0x54d7ce, 0x54d87e, 0x54d931, 0x54d9d9, 0x54da43 |
| 0x54db90-0x54e8c7 | sub_54DB90 | 12 | 0x54de89, 0x54df2c, 0x54dfdf, 0x54e092, 0x54e140, 0x54e1aa, 0x54e4b4, 0x54e554, 0x54e607, 0x54e6ba, 0x54e762, 0x54e7cc |
| 0x54e920-0x54f8dd | sub_54E920 | 16 | 0x54ed20, 0x54ed8e, 0x54ee04, 0x54ee90, 0x54ef11, 0x54ef8c, 0x54f03c, 0x54f0a6, 0x54f490, 0x54f4fc, 0x54f570, 0x54f5f7, 0x54f673, 0x54f6e9, 0x54f793, 0x54f7fa |
| 0x54fb30-0x550afb | sub_54FB30 | 16 | 0x54ff30, 0x54ffa1, 0x55001a, 0x5500a6, 0x550127, 0x5501a2, 0x55024f, 0x5502b9, 0x5506a1, 0x550712, 0x55078b, 0x550817, 0x550898, 0x55090e, 0x5509b8, 0x550a1f |
| 0x551350-0x551511 | sub_551350 | 1 | 0x5514a4 |
| 0x551520-0x551f26 | HeadSelectDialog__Constructor | 13 | 0x551800, 0x55185b, 0x5518b9, 0x55191a, 0x551975, 0x5519d6, 0x551a3d, 0x551d13, 0x551d6e, 0x551dcc, 0x551e2d, 0x551e88, 0x551ee9 |
| 0x552110-0x55317a | sub_552110 | 20 | 0x5524b4, 0x552512, 0x552575, 0x5525eb, 0x552656, 0x5526c3, 0x55274b, 0x5527c7, 0x552877, 0x5528de, 0x552c76, 0x552cd4, 0x552d37, 0x552dad, 0x552e18, 0x552e82, 0x552f0a, 0x552f86, 0x553030, 0x553097 |
| 0x573d20-0x574301 | sub_573D20 | 8 | 0x573e16, 0x573e73, 0x573ec5, 0x574003, 0x5740d6, 0x574133, 0x574185, 0x57426c |
| 0x587bb0-0x588073 | ForcedInformMessageDialog__Constructor | 6 | 0x587ca9, 0x587d15, 0x587dc2, 0x587e14, 0x587f1b, 0x587f87 |
| 0x58b650-0x58c192 | sub_58B650 | 12 | 0x58b711, 0x58b760, 0x58b7b2, 0x58b865, 0x58b9c2, 0x58bbb9, 0x58bc4f, 0x58bca1, 0x58bcf3, 0x58bda3, 0x58befd, 0x58c0f7 |
| 0x58c350-0x58c9b5 | sub_58C350 | 8 | 0x58c6b6, 0x58c70e, 0x58c769, 0x58c7be, 0x58c813, 0x58c868, 0x58c8c0, 0x58c91a |
| 0x58d270-0x58d537 | sub_58D270 | 5 | 0x58d32b, 0x58d37a, 0x58d3cc, 0x58d42f, 0x58d492 |
| 0x58d750-0x58d9e3 | sub_58D750 | 3 | 0x58d811, 0x58d860, 0x58d8bc |
| 0x595900-0x595ae2 | sub_595900 | 2 | 0x5959d4, 0x595a68 |
| 0x599cc0-0x59aff0 | sub_599CC0 | 11 | 0x599e51, 0x599eac, 0x599f07, 0x59a022, 0x59a138, 0x59a24e, 0x59a364, 0x59a5c3, 0x59aa3c, 0x59ac93, 0x59af42 |
| 0x59bc90-0x59d198 | UserListDialogPane_UserListDialogPane | 25 | 0x59bdc3, 0x59be1e, 0x59bed4, 0x59bf6e, 0x59c07b, 0x59c42f, 0x59c4df, 0x59c560, 0x59c5bb, 0x59c63e, 0x59c6cc, 0x59c721, 0x59c7c2, 0x59c858, 0x59c937, 0x59c992, 0x59ca3f, 0x59cacf, 0x59cbdc, 0x59ce91, 0x59cf3b, 0x59cfb9, 0x59d014, 0x59d094, 0x59d0ef |
| 0x59e0d0-0x59e393 | PartySearchEditPane_PartySearchEditPane | 4 | 0x59e197, 0x59e1e9, 0x59e278, 0x59e302 |
| no modeled function | absent | 1 | 0x452ceb |

- Representative typed caller proof: BrowserDialog constructor calls at `0x46ab52`, `0x46ab9c`, `0x46ac66`, and `0x46acab` each pass a `ControlPane *` after allocating/constructing a control; no category value is pushed.
- Indirect caller inventory: none identified. The target has no data xrefs or function-pointer references; all 800 inbound xrefs are direct code calls.

## Documentation Evidence And IDA Status

- UID0003KH now records exact one-pointer ABI, range/padding, generic List allocation/Append, ownership, exhaustive reachability, compiler lowering, historical rejection, `95/98`, and exact CPP with blank H. Its current SHA is `5F881BD4D79AC8DDA02686E50D45B2F030296F305F9686A751000011C60D3093`; scoped validator 18257 passed.
- UID00003T now keeps the complete declaration in H, CPP blank, exactly one supported AddControl declaration and one source `[[CHILDREN]]` marker, with the category overload removed and full prior surface preserved. Current SHA `A5C705AE6E0F313DCC893927F571EDC5B2CAE7B890AAC01CCD1C3E1F604DC18E`; validator 18266 passed.
- UID0000IT now records exact `DialogPane.h`/`.cpp` placement, one-pointer AddControl body route, 800-call shared infrastructure, compiler/source boundary, and historical category/custom-manager rejection at `93/95`. Current SHA `47062D446DB04849FEAFABD830571053DFE97A592347C9BC5CA127214A940513`; validator 18275 and final refresh 18289 passed.
- UID00012S remains NONE/false/nonemitting with blank formal channels and now records source-ready UID0003KH, exact range/padding/semantics, full caller count, and category-overload rejection at `91/94`. Current SHA `8222A28BEC439B7FEAA1FC6AF17C8863C18795536A24070B8619CD1A816A1648`; callback validator 18282 and independent Gate 2A passed. Its supervisor-owned manual coverage row is current at `not_reconstructable : 91%`.
- UID0001U4 now records live UDT ordinal 471/size 0x26c/member readback, exact pointer-slot versus pointed-to-control lifetime, one-pointer caller/type proof, and rejected custom manager at `92/95`, with both formal channels blank. Current SHA `B76A8DE3CBD32439E9AAAFF7FD81EF77CFBF55CA66FE274F70793DD4CBFCBDAB`; validator 18287 passed.
- UID00012R retains `92/94`, owner/emitter UID00003T, true and blank formal channels while bounded control-band/ownership/reconstruction prose now names exact UID0003KH and historicalizes obsolete helper names. Current SHA `9677744EB82FC0096A0EF6C61C1A8680F169CF7E899CBE70D4EB4C68239C934C`; validator 18288 passed.
- UID000079, by-file/List, constructor/Append, and DialogPane destructor/remove/find/count pages were reread and already contain same-or-greater source-ready declarations, semantics, non-owning lifetime, and historical corrections; no contradiction required an edit.
- Generated command 18160 is historical pre-callback evidence, and command 18289 is historical callback/generated provenance. Current Gate 2A physical output is `DialogPane.cpp` SHA `A640CD55F249CE1AB9739F05303418D99BED6ED17E956DF3D588F55950214B4F` (16,854 bytes/504 lines) and `DialogPane.h` SHA `C6CAAA259E2B3822C8961949123E2A91D3A459DFD409BD7A99458C87B2B193A8` (3,257 bytes/89 lines); it preserves one target body, no target empty marker, no category overload, one class declaration in H, no class declaration in CPP, one one-pointer H declaration, and no duplicate/lost unrelated child code.
- Supervisor Gate 2A independently validated the target, DialogPane class/file, helper inventory, layout, broad aggregate, and foreground wait-generated scopes; every scoped run exited `0` with `ok: 1`, and all six ordinary hashes remained exactly those recorded in the ledger and Changed Files table.
- Supervisor manual coverage application/validation is current: by-memory SHA `B959E01340463233C5EE71064093C3519BF117C17B5EFF67252547E532ED066C`, by-class SHA `3B510D379C2B5DABD0E12E0660C640C664DB870639A6A993545652C3718D3E11`, by-file SHA `0197677783FFF85AECAFB3B8A7CDAE28123C2E7D7F779E1DEFDE13BECE4F6454`, and by-type/by-struct SHA `A40096AD099ACD4231FC0606753C79DC9815258162816E43B35907547D2285E0`; each coverage validator exited `0` with `ok: 1`.

## Ranked Ownership Analysis

### 1. DialogPane class UID00003T

- Evidence for: `this` is typed DialogPane; field is inside DialogPane at `+0x1fc`; destructor and all sibling methods use the same field; 800 callers are derived-dialog construction/layout routines; class already declares the method.
- Evidence against: none material. Exact original spelling is inferred, not symbol-proven.
- Decision: canonical owner and emitter.

### 2. DialogPane file UID0000IT

- Evidence for: accepted source root `NexusTK/ui/core/DialogPane.cpp/.h`; adjacent base methods share the same method island and route.
- Evidence against: file is a source root, not the direct canonical class owner.
- Decision: indirect file owner through UID00003T.

### 3. List class UID000079

- Evidence for: constructor and Append implement the storage dependency.
- Evidence against: List is the contained generic data structure; receiver and callers are DialogPane; List does not own the method.
- Decision: support dependency only.

### Proposed new file/grouping, if applicable

- No new source file or grouping. Reuse `NexusTK/ui/core/DialogPane.h` for the class declaration and `NexusTK/ui/core/DialogPane.cpp` for exact child definitions.

## Source Placement

- Applied placement: protected declaration in `DialogPane.h`; out-of-line body in `DialogPane.cpp`.
- This matches class receiver/state, adjacent method island, 800 shared callers, current file route, and mid-2000s class organization.
- Rejected: List.cpp, ControlPane.cpp, a synthetic DialogControlManager module, feature-dialog sources, free helper, inline body, or compiler-glue/no-owner treatment.
- No remaining placement uncertainty affects code emission; callback command 18289 first verified the split and the current Gate 2A physical readback preserves it exactly.

## Range / Split / Padding / Reclassification Analysis

- Exact target `[0x49dc10,0x49dc93)`, size `0x83`, is already a complete child.
- Predecessor ends at `0x49dc05`; preserve eleven CC padding bytes `[0x49dc05,0x49dc10)` outside target.
- Preserve thirteen CC bytes `[0x49dc93,0x49dca0)` before UID0003KI.
- EH funclets at `0x5fd4fe` and `0x5fd509` are compiler-owned fragments linked to the target but are not additional source children or handwritten source.
- No split, merge, range extension, child creation, or ownership reclassification is required.

## Negative Evidence Summary

- No second AddControl function or exact name exists.
- No caller passes a category byte or second explicit argument.
- No target instruction reads category, control id, state, or payload fields from `control`.
- No custom manager class is constructed; exact List vtable/constructor is used.
- No return value is defined or consumed.
- No data xref or indirect callback route suggests non-DialogPane ownership.
- No source evidence supports hand-authored allocator, raw vslot, SEH, or decompiler temporary forms.
- No target byte overlaps predecessor, successor, or alignment padding.

## IDA Rename / Type / Comment Recommendations

### Supervisor-Applied Gate 2B row

- Fresh supervisor prestate matched the accepted report. Backup `E:\NTK\Resources\NexusTK\NexusTK.exe.i64.bak-UID0003KH-prestate-20260728-143749` has SHA256 `0F92E471162B578F9FAC55CD9140D5BC13B2DD1771C7C4D0282C8CB14C272ECE` and size 143,189,962 bytes.
- The supervisor applied only IDA-3KH-001's function-repeatable comment, read it back exactly, preserved every protected channel/range/frame/byte/xref dependency, saved the IDB, and recorded catalog entry 0336 plus the Gate 2B audit entry. Saved IDB SHA256 is `8F2811531D092B6EF367402393E3BBF5AB2DE05738E2D0A22BE8A644C6D95F46`, size 143,189,293 bytes, mtime `2026-07-28T14:38:07.4155761-04:00`.

| ID | Entity and exact range | Exact verified prestate | Collision/name proof | Supervisor-applied action | Complete current readback and safety |
| --- | --- | --- | --- | --- | --- |
| IDA-3KH-001 | Function `[0x0049dc10,0x0049dc93)`, size `0x83` | Modeled head `0x0049dc10`, end `0x0049dc93`; name `DialogPane_AddControl`; declaration `void __thiscall(DialogPane *this, ControlPane *control)`; address-regular absent; address-repeatable absent; function-regular exact text `DialogPane::AddControl(ControlPane *). Lazily creates generic List(4,20) at +0x1fc and appends the control pointer.`; function-repeatable absent. | `entity_query(kind=names, regex=^DialogPane_AddControl$)` returned total 1 at `0x49dc10`; `lookup_funcs DialogPane_AddControl` returned this exact function. No rename was proposed. `DialogPane_AddControlControlPane` and `DialogPane_AddControlByCategory` returned zero and remain rejected names, not rename requests. | Supervisor preserved name, declaration, range, current function-regular text, and both absent address-comment channels; set function-repeatable exactly to `DialogPane::AddControl(ControlPane *control) lazily creates List(sizeof(ControlPane *), 20) in m_controlManager at +0x1fc and appends one non-owning ControlPane pointer slot with Append(1, &control); DialogPane owns the pointed-to controls.` | Exact readback passed: same head/end/name/declaration; address-regular absent; address-repeatable absent; function-regular unchanged exact text; function-repeatable exact applied payload. Target identity/type, neighboring functions, frame/padding, bytes, xrefs, function chunks/EH ranges, stack frame, and both neighboring padding fences remained preserved. |

### Protected type dependencies

| ID | Exact current state | Disposition and expected readback |
| --- | --- | --- |
| IDA-3KH-T01 | `DialogPane`, ordinal 471, UDT true, size `0x26c`, seven members; `m_controlManager` offset `0x1fc`, size 4, type `List *`. | Already present; no type/member action. Preserve exact size, members, and offsets. |
| IDA-3KH-T02 | `ControlPane`, ordinal 443, UDT true, size `0x108`, twelve members. | Already present; no action. Preserve; pointer use is exact. |
| IDA-3KH-T03 | `List`, ordinal 485, declaration `List`, incomplete/other, unknown-size sentinel `0xffffffffffffffff`, zero members in this MCP build. | No action. Do not replace or complete from this target. It safely parses `List *` and target prototype dependencies. |
| IDA-3KH-T04 | `LObject`, ordinal 516, declaration `LObject`, incomplete/other, unknown-size sentinel, zero members. | No action. Indirect List base dependency only. |

### Protected function dependencies

| ID | Entity/range/current channels | Disposition |
| --- | --- | --- |
| IDA-3KH-P01 | `sub_4F4AA0` `[0x004f4aa0,0x004f4ab4)`, size `0x14`; decompiler declaration `void *__cdecl sub_4F4AA0(size_t pExceptionObject)`; all four comment channels absent. | No target-local action. It is the project allocation wrapper; source target uses `new`. Preserve name/type/comments/bounds. |
| IDA-3KH-P02 | `sub_4F3060` `[0x004f3060,0x004f30d5)`, size `0x75`; decompiler declaration `_DWORD *__thiscall sub_4F3060(_DWORD *this, int a2, int a3)`; all four comment channels absent. | No target-local action. Existing List docs own source identity `List::List(int,int)`. Preserve bounds/current state. |
| IDA-3KH-P03 | `sub_4F33C0` `[0x004f33c0,0x004f33d5)`, size `0x15`; decompiler declaration `int __thiscall sub_4F33C0(_DWORD *this, int a2, int a3)`; all four comment channels absent. | No target-local action. Existing List docs own source identity `void List::Append(int,void *)`. Preserve bounds/current state. |

### Protected stack-frame/local state

- `Block +0x8 size4 void *`, `var_C +0xc size4 _DWORD`, `var_4 +0x14 size4 _DWORD`, `__saved_registers +0x18`, `__return_address +0x1c`, `control +0x20 size4 ControlPane *`, and `arg_4 +0x24 size4 _DWORD` are exact current frame entries.
- `Block`, `var_C`, `var_4`, and `arg_4` are compiler EH/security metadata. Do not rename or source-model them.
- Preserve source argument `control` exactly. Decompiler temporaries `m_controlManager` and `v4` do not require local-variable mutations; the source body expresses the field and new expression directly.
- No data-item action exists for this report.

## First-Draft C++ Recommendation

- Eligible for draft/finalized first source body: yes. The target clears the 95-quality barrier because the code is behaviorally exact, destination-ready, and source-natural.
- Target CPP block exact insertion:

```cpp
void DialogPane::AddControl(ControlPane *control)
{
    if (m_controlManager == NULL)
        m_controlManager = new List(sizeof(ControlPane *), 20);

    m_controlManager->Append(1, &control);
}
```

- Target H block: blank. The declaration belongs once in the class H emitter.
- Required [UID:00003T] formal-channel disposition: blank CPP; H contains the complete current class declaration with only the unsupported category overload removed and `[[CHILDREN]]` once after the class:

```cpp
class DialogPane : public Pane
{
public:
    DialogPane(const wchar_t *title, unsigned short dialogConfigId, unsigned char paneMode);
    virtual ~DialogPane();

    virtual void OnCreate(const RectBounds *bounds, int zOrder, Pane *parentPane, Layer *layer);
    virtual void OnShow(Pane *afterPane, Pane *beforePane);
    virtual void OnDestroy();
    virtual void OnHide();
    virtual void OnPaint();
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool HandleImeEvent(Event *event);
    virtual void OnControlCommand(int controlIndex, int notifyCode);
    virtual void UpdateActionButton();
    int FindControlIndex(const ControlPane *control) const;
    void CloseDialog();

protected:
    void StoreClampRect(const RectBounds *bounds);
    void ClearClampRect();
    void SetTitleText(const wchar_t *title);
    void SetBackgroundResource(const wchar_t *resourceName, short frameIndex);
    void AddControl(ControlPane *control);
    void RemoveControl(ControlPane *control);
    void RemoveControl(int controlIndex);
    int GetControlCount() const;
    ControlPane *GetChildControl(int controlIndex) const;

    template <class T>
    T *GetChild(int controlIndex) const
    {
        return static_cast<T *>(GetChildControl(controlIndex));
    }

    virtual void DrawBackground();
    virtual void DrawBorder();
    char HitTestControls(int mouseY, int mouseX, int *outControlId);
    void DispatchInputToControl(Event *event, int controlId);
    void SavePosition();
    void SetFocusedControl(int controlId);
    void SetPendingControl(int controlId);
    virtual void SetHoverControl(int controlId);
    void SetSelectionVisualState(int controlId, unsigned char state);
    void ActivateFocusedControl();
    void ActivatePendingControl();
    void RedrawSelectedControl();

    void SlideOpenVertical();
    void SlideCloseVertical();
    void SlideOpenHorizontal(unsigned char direction);
    void SlideCloseHorizontal(unsigned char direction);
    void SlideShrink(unsigned char direction);
    void SlideExpand(unsigned char direction);

    wchar_t m_title[128];
    unsigned short m_dialogConfigId;
    List *m_controlManager;
    int m_focusedControlId;
    int m_pendingControlId;
    unsigned char m_isTitleDragActive;
    unsigned char m_savedPaneMode;
    int m_dragOriginX;
    int m_dragOriginY;
    int m_activeControlId;
    unsigned char m_pressedControlActive;
    int m_pressedControlId;
    unsigned char m_pressedHitType;
    int m_selectedControlId;
    unsigned char m_selectionVisualState;
    unsigned char m_clampDragToBounds;
    int m_dragClampMinY;
    int m_dragClampMinX;
    int m_dragClampMaxY;
    int m_dragClampMaxX;
    EPFTileContext m_backgroundTileContext;
    int m_backgroundImageWidth;
    bool m_hasCustomBackground;
};

[[CHILDREN]]
```

- Behavior preservation: lazy initialization, element width, page size, append count, address-of pointer copy, and ordinary allocation exception behavior are exact.
- Human source shape: no IDA labels, raw vslots, decompiler arrays, synthetic SEH, or literal object-size allocator calls remain.
- Naming convention: existing project member `m_` prefix and `PascalCase` method/type names; consistency is subordinate to binary behavior and plausible authored source.
- Third-party import directive: not applicable.

## Final Recommendation

- C3KH-001 through C3KH-029 are implemented/verified. Command 18289 remains historical callback/generated provenance; current Gate 2A verifies C3KH-029, supervisor manual coverage verifies C3KH-027, and saved-IDB readback/catalog entry 0336 verifies C3KH-028.
- Target is `95/98`, preserves owner/emitter/flags/position/Nested, contains exact CPP and blank H, retains complete evidence/history, and no longer defers the source body.
- Class has complete H, blank CPP, no unsupported category AddControl declaration, one one-pointer declaration, one source `[[CHILDREN]]`, score `93/96`, and preserved unrelated content.
- File has exact source/header route and shared caller evidence at `93/95`, with path/ownership preserved.
- Helper aggregate/layout/broad aggregate contain only the bounded accepted corrections and dispositions listed below; no duplicate target code was added.
- List and sibling docs were verified same-or-greater and left unchanged.
- IDA: supervisor applied only IDA-3KH-001 after matching fresh prestate; exact readback/save passed and all types/helpers/locals plus target/neighborhood channels and boundaries remained protected.
- Future work outside scope: unrelated DialogPane helper naming/visual-state/source bodies remain their own target passes and do not block UID0003KH.

## Recommended Target Doc Changes

- Target path: `by-memory/0x0049dc10-0x0049dc93.DialogPaneEnsureControlManagerAndAdd.md`.
- Applied metadata: `95/98`; owner/emitter UID00003T; true; blank position; `Nested:0`.
- Applied Item Summary: `Exact DialogPane::AddControl(ControlPane *) body; lazily creates List(sizeof(ControlPane *), 20) at +0x1fc and appends one non-owning ControlPane pointer slot with Append(1, &control), while DialogPane retains pointed-to control ownership.`
- Applied formal CPP: exact target body above. Formal H remains blank.
- Applied exact bytes/boundaries, 800-call inventory conclusion and representative proof, live UDT/prototype, allocation/EH lowering, List slot ownership, source access/placement, rejected category/custom-manager/byte/status alternatives, and score rationale.
- Historical B004/B011 assumptions remain in a clearly historical/superseded section explaining why the category/custom-manager interpretation was rejected.

## Recommended Support Doc Changes

- `by-class/DialogPane.md` UID00003T is `93/96`; complete declaration moved CPP -> H; only category AddControl declaration removed; exact UID0003KH body/callers/ownership/history added; unrelated code/prose preserved.
- `by-file/DialogPane.md` UID0000IT is `93/95`; exact H/CPP split, one-pointer AddControl route, broad callers, and custom-manager/category rejection recorded; source path preserved.
- `by-memory/0x0049dae0-0x0049dfc4.DialogControlPaneHelpers.md` UID00012S is `91/94`, owner NONE, false, no emitter, blank code; UID0003KH row/evidence is source-ready with complete caller count and corrected API.
- `by-type/by-struct/DialogPaneLayout.md` UID0001U4 is `92/95`, retains owner/emitter UID00003T and blank code, and includes live UDT/member/lifetime/rejected-manager evidence.
- `by-memory/0x0049d8a0-0x0049feae.DialogPane.md` UID00012R remains `92/94`, owner/emitter UID00003T, true, blank code, with bounded exact UID0003KH child/source-ready and stale-name corrections and no duplicate aggregate code.
- `by-class/List.md`, `by-file/List.md`, List constructor/Append pages, and DialogPane destructor/remove/find/count pages were reread; their content was same-or-greater, so no edit occurred.

## Score And Metadata Recommendation

- Target assignment-time state: `87/90`, owner/emitter UID00003T, true, blank formal C++/H.
- Target current applied state: `95/98`, same route/flags/position/Nested, exact CPP, blank H.
- Reason not lower: every behavioral, ABI, type, lifetime, placement, and code-shape blocker is resolved by live IDA plus current accepted support.
- Reason not higher: no original PDB/source proves the exact identifier spelling, and final compile/binary comparison has not yet been performed. This is a confidence cap, not a blank-code blocker.
- Score-improvement attempts: exact-body decision resolved; field/type resolved live; caller/reachability exhausted with 800 xrefs; category overload rejected by complete name/function/caller inventory; allocation/exception path resolved; source/header route resolved; manual coverage payload supplied; IDA handoff declaration-ready.
- Support current states: UID00003T `93/96`; UID0000IT `93/95`; UID00012S `91/94` false/nonemitting; UID0001U4 `92/95`; UID00012R remains `92/94`; List support unchanged.

## Open Questions With Attempted Resolution

- Exact original field spelling: checked current IDA member, class/layout/file docs, historical reports, generated source, and sibling methods. No original symbol exists. Best supported resolution is `m_controlManager`, already accepted consistently; no score/code blocker remains.
- Exact original method spelling: checked function/name catalog and current class surface. `AddControl` is the sole stable human-facing project name and describes all callers; retain it.
- Category overload existence: checked every AddControl function/name and all 800 call xrefs. No evidence supports it; remove it rather than deferring.
- Header versus source inline placement: distinct out-of-line body and project class/body routing support H declaration plus CPP definition. No unresolved placement blocker.
- Allocation failure semantics: observed compiler lowering and constructor cleanup are generated from ordinary `new`; no custom source fallback is justified. Use ordinary new-expression.
- Questions remaining unresolved: only original-source spelling proof and eventual compiler/binary identity comparison. Neither prevents a high-probability human source reconstruction or the recommended score.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- B004 inspected and supplied the exact manual-row payloads below but did not edit any coverage file. The supervisor later applied and validated them exactly; every coverage validator exited `0` with `ok: 1`.
- Current coverage hashes are: by-memory `B959E01340463233C5EE71064093C3519BF117C17B5EFF67252547E532ED066C`; by-class `3B510D379C2B5DABD0E12E0660C640C664DB870639A6A993545652C3718D3E11`; by-file `0197677783FFF85AECAFB3B8A7CDAE28123C2E7D7F779E1DEFDE13BECE4F6454`; by-type/by-struct `A40096AD099ACD4231FC0606753C79DC9815258162816E43B35907547D2285E0`.

`by-memory/-coverage-report.md`: supervisor-applied UID0003KH insertion under UID00012S in address order:

```markdown
        - [UID:0003KH][0x0049dc10-0x0049dc93.DialogPaneEnsureControlManagerAndAdd](by-memory/0x0049dc10-0x0049dc93.DialogPaneEnsureControlManagerAndAdd.md) 0x0049dc10-0x0049dc93 | method | DialogPaneAddControl : reconstructable : 95% : very-strong : Exact source-authored DialogPane::AddControl(ControlPane *) body; lazily creates List(sizeof(ControlPane *), 20) at +0x1fc, appends one non-owning pointer slot with Append(1, &control), preserves DialogPane ownership of child controls and compiler allocation cleanup, and emits once through UID00003T.
```

Supervisor-applied UID00012S row:

```markdown
    - [UID:00012S][0x0049dae0-0x0049dfc4.DialogControlPaneHelpers](by-memory/0x0049dae0-0x0049dfc4.DialogControlPaneHelpers.md) 0x0049dae0-0x0049dfc4 | helper-cluster | DialogControlPaneHelpers : not_reconstructable : 91% : very-strong : Non-emitting DialogPane helper inventory over exact class-owned children and alignment; UID0003KH now carries exact List-backed AddControl source with 800 direct code xrefs, while pointer/index removal, pointer lookup, count, focus, selection, activation, clamp, title, and background bodies remain on their exact child pages.
```

Supervisor-applied bounded UID00012R row:

```markdown
    - [UID:00012R][0x0049d8a0-0x0049feae.DialogPane](by-memory/0x0049d8a0-0x0049feae.DialogPane.md) 0x0049d8a0-0x0049feae | class-method aggregate | DialogPane : reconstructable : 92% : very-strong : Exact DialogPane base-method aggregate with complete lifecycle/control/animation inventory, exact AddControl/SetBackgroundResource/DrawBackground/DrawBorder/SetHoverControl children, three-view class route, 0x26c layout, retained raw islands and padding, source-literal/resource roles, and blank nonduplicating aggregate C++.
```

Supervisor-applied UID00003T row in `by-class/-coverage-report.md`:

```markdown
- [UID:00003T][DialogPane](by-class/DialogPane.md) : reconstructable : 93% : very-strong : Complete no-loss 0x26c DialogPane header declaration with exact lifecycle/input/control/animation methods, one supported AddControl(ControlPane *) declaration, source-ready AddControl/SetBackgroundResource/DrawBackground/DrawBorder/SetHoverControl children, exact generic List control storage, compiler-vtable separation, and DialogPane.cpp ownership.
```

Supervisor-applied single exact UID0000IT row in `by-file/-coverage-report.md`:

```markdown
- [UID:0000IT][DialogPane](by-file/DialogPane.md) : reconstructable : 93% : very-strong : Base dialog source module with complete 0x26c DialogPane declaration in NexusTK/ui/core/DialogPane.h, exact List-backed AddControl plus background/border/hover bodies in DialogPane.cpp, lifecycle/control/list/input/animation families, 800 shared AddControl call sites, dialog-frame resources, derived consumers, active-dialog state, and compiler/source separation.
```

Supervisor-applied UID0001U4 row in `by-type/by-struct/-coverage-report.md`:

```markdown
- [UID:0001U4][DialogPaneLayout](by-type/by-struct/DialogPaneLayout.md) : reconstructable : 92% : very-strong : Exact 0x26c DialogPane inherited layout with live IDA UDT readback, List *m_controlManager at +0x1fc storing four-byte ControlPane pointer slots, title/config/drag/selection/clamp state, one EPFTileContext background field at +0x23c, trailing width/bool state, natural tail padding, and complete class-header route.
```

## Follow-Up Actions

- Completed supervisor stages: exact post-callback Gate 1 for SHA `56748DD399B94ABE61BA829E81F6349CC4AAFB9CC9A0FCE6244F39D0C6C61CE1`, independent Gate 2A, Gate 2B/save/readback/catalog entry 0336, manual coverage application/validation, and current generated topology verification.
- Remaining supervisor-only action: run `execute_report`, archive through validator-owned lifecycle, and confirm post-execution audit/registry/tracker state.
- B004: remain idle on this same report; do not run or probe any lifecycle command.

## Confidence

- Recommendation confidence: `98/100`.
- Score confidence: high; target `95/98` is justified by exact destination-ready source and comprehensive live evidence.
- Remaining uncertainty: only original identifier spelling and final compiler identity, neither of which warrants IDA-style names or blank source.

## Validator Results

- All callback validators were run serially from `source-3/project-documentation`; all exited `0` with `ok: 1`. Command 18289 and its hashes below are historical callback/generated provenance:

| Command | Timestamp | Scope | Result |
| --- | --- | --- | --- |
| `000000018257` | `2026-07-28T13:51:10-04:00` | `by-memory/0x0049dc10-0x0049dc93.DialogPaneEnsureControlManagerAndAdd.md` | exit 0, ok1; 95/98 and CPP block registered |
| `000000018266` | `2026-07-28T13:52:31-04:00` | `by-class/DialogPane.md` | exit 0, ok1; 93/96 and CPP->H registration applied |
| `000000018275` | `2026-07-28T13:53:46-04:00` | `by-file/DialogPane.md` | exit 0, ok1; 93/95 applied |
| `000000018282` | `2026-07-28T13:54:57-04:00` | `by-memory/0x0049dae0-0x0049dfc4.DialogControlPaneHelpers.md` | exit 0, ok1; 91/94 applied |
| `000000018287` | `2026-07-28T13:55:52-04:00` | `by-type/by-struct/DialogPaneLayout.md` | exit 0, ok1; 92/95 applied |
| `000000018288` | `2026-07-28T13:57:06-04:00` | `by-memory/0x0049d8a0-0x0049feae.DialogPane.md` | exit 0, ok1; bounded prose accepted, score unchanged |
| `000000018289` | `2026-07-28T13:58:10-04:00` | final `by-file/DialogPane.md --wait-generated` | exit 0, ok1; foreground generated refresh completed |

- Validator warnings were pre-existing missing-reference registry notices for UIDs such as 0003KD/0003KP/0003AW and project-wide autogen diagnostics; no scoped command failed and none contradicted the accepted UID0003KH implementation.
- Historical command 18289 readback: `DialogPane.cpp` SHA256 `28D17D7932E3C48393552456C5D3AEC8B2EBDE2A3A148ED8F18039BBA6C28701`, 16,854 bytes, 504 lines; `DialogPane.h` SHA256 `9C4192B36813BD01D59157D8A874441F7122B02E164C2AF452F02A1E098891B8`, 3,257 bytes, 89 lines, with timestamp metadata `2026-07-28T13:58:10-04:00`.
- Supervisor Gate 2A independently reran the target, class, file, helper-inventory, layout, broad-aggregate, and foreground wait-generated scopes; every run exited `0` with `ok: 1`, and ordinary hashes remained unchanged from the Changed Files table.
- Current Gate 2A generated readback: `DialogPane.cpp` SHA256 `A640CD55F249CE1AB9739F05303418D99BED6ED17E956DF3D588F55950214B4F`, 16,854 bytes, 504 lines; `DialogPane.h` SHA256 `C6CAAA259E2B3822C8961949123E2A91D3A459DFD409BD7A99458C87B2B193A8`, 3,257 bytes, 89 lines.
- Current semantic invariants: target body 1; target UID occurrence in CPP 1; target empty markers 0; category-overload declarations 0; class declarations CPP 0/H 1; one-pointer H declaration 1; duplicate UID markers CPP 0/H 0. Unrelated child code remains present and unique, providing no-loss/no-duplication readback.
- Supervisor coverage validators each exited `0` with `ok: 1`; current hashes are by-memory `B959E01340463233C5EE71064093C3519BF117C17B5EFF67252547E532ED066C`, by-class `3B510D379C2B5DABD0E12E0660C640C664DB870639A6A993545652C3718D3E11`, by-file `0197677783FFF85AECAFB3B8A7CDAE28123C2E7D7F779E1DEFDE13BECE4F6454`, and by-type/by-struct `A40096AD099ACD4231FC0606753C79DC9815258162816E43B35907547D2285E0`.

## Changed Files

- Same report reconciled in place: `tools/leaser/Agents/Agent-B004/research/0003KH-DialogPaneAddControl-empty-emitter-source-quality.md`.
- Modified ordinary pages:

| Path | Current SHA256 | Bytes | Lines | Scoped validator |
| --- | --- | ---: | ---: | --- |
| `by-memory/0x0049dc10-0x0049dc93.DialogPaneEnsureControlManagerAndAdd.md` | `5F881BD4D79AC8DDA02686E50D45B2F030296F305F9686A751000011C60D3093` | 10,057 | 95 | 18257 ok1 |
| `by-class/DialogPane.md` | `A5C705AE6E0F313DCC893927F571EDC5B2CAE7B890AAC01CCD1C3E1F604DC18E` | 41,897 | 345 | 18266 ok1 |
| `by-file/DialogPane.md` | `47062D446DB04849FEAFABD830571053DFE97A592347C9BC5CA127214A940513` | 32,814 | 187 | 18275 ok1; 18289 ok1/wait-generated |
| `by-memory/0x0049dae0-0x0049dfc4.DialogControlPaneHelpers.md` | `8222A28BEC439B7FEAA1FC6AF17C8863C18795536A24070B8619CD1A816A1648` | 26,258 | 190 | 18282 ok1 |
| `by-type/by-struct/DialogPaneLayout.md` | `B76A8DE3CBD32439E9AAAFF7FD81EF77CFBF55CA66FE274F70793DD4CBFCBDAB` | 25,653 | 163 | 18287 ok1 |
| `by-memory/0x0049d8a0-0x0049feae.DialogPane.md` | `9677744EB82FC0096A0EF6C61C1A8680F169CF7E899CBE70D4EB4C68239C934C` | 34,808 | 196 | 18288 ok1 |

- Verify-only List and DialogPane sibling pages were unchanged because they contained same-or-greater accepted facts. No ordinary path was renamed or created.
- Each ordinary file was leased only immediately before its edit, retained through its scoped validation, and successfully unleased immediately afterward. No B004 lease remains on these paths.
- Generated artifacts changed only through validator-owned refreshes; command 18289 is callback provenance and the current Gate 2A hashes are recorded above. B004 did not edit generated artifacts manually. B004 did not edit coverage or IDA; the supervisor later completed both under the recorded Gate 2B and coverage evidence.
- Report execution remains not run. B004 did not run, probe, dry-run, move, archive, or invoke `execute_report` or any report lifecycle command.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor exact-artifact Gate 1 passed accepted SHA before implementation.
- [x] Target/support docs updated: UID0003KH, UID00003T, UID0000IT, UID00012S, UID0001U4, and bounded UID00012R prose; List/sibling pages reread and unchanged because not contradicted.
- [x] Every declared additional UID has target-specific evidence, recommendation, ledger rows, destination docs, and validation: no additional report UID declared.
- [x] Current target state and actual evidence checked recorded.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score changes applied: target 95/98; class 93/96; file 93/95; helper inventory 91/94; layout 92/95; broad aggregate unchanged 92/94.
- [x] Score-limiting blockers researched to resolution: exact code, field/type, callers, source placement, category-overload correction, exception lowering, and coverage payload complete.
- [x] Owner/emitter/reconstructable dispositions applied: target route unchanged; UID00012S remains NONE/false/nonemitting; other support routes unchanged.
- [x] Split/rename/new-child disposition applied: no split/new child; unsupported declaration removed; physical target path retained as historical descriptive alias.
- [x] Source placement, range/padding/reclassification, and IDA rename/type/comment handoff documented.
- [x] Supervisor Gate 2B handoff and application complete: exact target range/name/type/four channels/collision proof verified; only the accepted function-repeatable comment changed; protected types/functions/locals/bounds/bytes/xrefs preserved; IDB saved/read back and catalog entry 0336 recorded.
- [x] Formal block disposition applied: exact target CPP; blank target H; class declaration moved to class H.
- [x] Third-party import directive confirmed not applicable.
- [x] Exact target/support facts incorporated at report-level detail.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Wave2/Wave3 mentions encountered and ignored as stale.
- [x] Open questions closed or documented as nonblocking evidence-backed uncertainty.
- [x] Validators run serially for every changed ordinary by-* page.
- [x] Current Gate 2A generated refresh verified: one DialogPane.h declaration, one target CPP body, zero target empty markers, zero category overloads, and no duplicate/lost unrelated child code; supervisor manual coverage text is applied and validated.

Implementation callback pass:
- [x] Supervisor-owned IDA action applied/read back/saved exactly; B004 did not perform the mutation.
- [x] Report accepted by supervisor for implementation at exact SHA `778BF6221BC0B82BCAB041A9B1DA3CACB031FD933E699C44E03F99569A843287`.
- [x] All accepted target/support doc details incorporated at report-level detail.
- [x] Every declared primary/support destination verified against ledger and docs.
- [x] Claim And Incorporation Ledger updated with applied hashes/validators/readback.
- [x] Metadata/score/owner/emitter/split/rename/CPP/H changes applied or explicitly preserved with reason.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions resolved or retained only with evidence-backed rationale.
- [x] Scoped validators run serially and command IDs/results recorded.
- [x] Generated CPP/H refresh completed by validator and physical semantic counts/hashes recorded.
- [x] All accepted C3KH-001 through C3KH-029 implementation items are applied and verified; no accepted claim remains pending.
- [x] Supervisor Gate 2A independent verification complete; every scoped validator and foreground wait-generated run exited 0/ok1, ordinary hashes remained unchanged, and current generated hashes/topology match.
- [x] Supervisor Gate 2B IDA application/save/readback/catalog complete; saved IDB SHA and catalog entry 0336 recorded.
- [x] Supervisor manual coverage application and validation complete; exact row dispositions and current coverage hashes recorded.
- [x] Supervisor exact post-callback Gate 1 accepted SHA `56748DD399B94ABE61BA829E81F6349CC4AAFB9CC9A0FCE6244F39D0C6C61CE1` before Gate 2A/Gate 2B/coverage reconciliation.
- [ ] Supervisor-only execute/archive and post-execution audit/registry confirmation complete.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000018347","destination_path":"executed-b-agent-research/B004/0003KH-DialogPaneAddControl-empty-emitter-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0003KH-DialogPaneAddControl-empty-emitter-source-quality.md","timestamp":"2026-07-28T15:21:11-04:00","uid":"0003KH"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
