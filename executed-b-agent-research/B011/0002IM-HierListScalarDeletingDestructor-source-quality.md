** TARGET-REPORT-UID:0002IM **
** AUTHOR-AGENT-ID:B011 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B011 Report - [UID:0002IM] HierListScalarDeletingDestructor Source Quality

Agent: Agent-B011

Assignment id: B011-report-0002IM-hierlist-scalar-deleting-destructor-source-quality-20260626

Mode: report-only research first

Report date: 2026-06-26

Target: [UID:0002IM] `by-memory/0x004cedb0-0x004cee52.HierListScalarDeletingDestructor.md`

Required report path: `tools/leaser/Agents/Agent-B011/research/0002IM-HierListScalarDeletingDestructor-source-quality.md`

## Report-Only Compliance

This pass edited only this Agent-B011 research report. It did not edit target or support `by-*` docs, generated files, project-level files, validator state/cache, IDA DB, `by-memory/-coverage-report.md`, or any other `-coverage-report.md`.

No leases were taken because report-only work writes only under this agent's `research/` folder. No subagents were spawned.

IDA MCP was available and used. This report is not fallback-only.

The previous active `00016I-GrafPortDrawGlyph-source-quality.md` report is explicitly not current under this assignment and was not continued, edited, deleted, or submitted.

## Finalized Report / Current Recommendation

Current recommendation:

- Reclassify [UID:0002IM] from a source-emitting reconstructable method page to a non-emitting compiler ABI wrapper page.
- Keep [UID:0002IM] owned by [UID:000065] `HierList` as documentation ownership, but set `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and keep formal C++ blank.
- Add source-level destructor C++ to the companion source-authored destructor page [UID:0002I9] `by-memory/0x004ce760-0x004ce7d1.HierListNonDeletingDestructor.md`, not to [UID:0002IM].
- Update [UID:000065] `by-class/HierList.md`, [UID:0000JV] `by-file/HierList.md`, [UID:00016X] `by-memory/0x004ce730-0x004cee52.HierList.md`, and [UID:0003BL] `by-memory/0x0061b340-0x0061b36c.HierListVtableData.md` to reflect that the vtable points at compiler-generated scalar deleting destructor glue generated from the source `HierList::~HierList()` declaration/body.

Final disposition:

- [UID:0002IM] is compiler/linker-generated ABI glue, not a human-authored `HierList` method that should appear in original-looking source.
- The source-authored destructor semantics are already represented by [UID:0002I9] and can now receive formal source-shaped C++.
- The compiler should regenerate the scalar deleting destructor wrapper from `HierList::~HierList()` and the virtual class declaration.

Required action:

- Supervisor should validate this report. If accepted, send B011 an implementation callback for the target/support edits and scoped validators listed in the implementation checklist.

Confidence:

- Strong for the ABI-wrapper/no-code disposition of [UID:0002IM].
- Strong for source destructor semantics and first-draft C++ on [UID:0002I9].
- Not final-audit `95+` because exact original destructor declaration spelling, header organization, and full class declaration emission are still class-wide coordination work.

## Target

- Target UID: [UID:0002IM]
- Target path: `by-memory/0x004cedb0-0x004cee52.HierListScalarDeletingDestructor.md`
- Source queue/report row: `auto-generated/-ag-research-tracker.md` still lists this target under `## by-memory` -> `### Not-Covered Files - Reconstructable` with stale `76/88` score data.
- Current supervisor classification: report-only B-agent source-quality research.
- Current scores and parent state:
  - Target header currently reads `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:000065`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000065`, blank formal C++.
  - Direct class parent [UID:000065] `by-class/HierList.md` is `86/90`, owner/emitter [UID:0000JV].
  - File parent [UID:0000JV] `by-file/HierList.md` is `85/87`.
  - Physical aggregate [UID:00016X] `by-memory/0x004ce730-0x004cee52.HierList.md` is `88/91`, `RECONSTRUCTABLE:FALSE`, blank emitter, and already documents exact child pages.

## Current Target State

Existing metadata:

- [UID:0002IM] currently claims reconstructable/emitting status under [UID:000065] `HierList`.
- Its formal `RECONSTRUCTION_CPP CODE` block is blank.
- Its item summary says live IDA confirms the vtable slot, child-list release loop, base storage destructor call, scalar-delete flags, and conditional `this` free.

Existing owner/emitter/reconstructable state:

- The class owner is correct as documentation ownership because the vtable slot and teardown body belong to `HierList`.
- The emitter route is not correct for human source output if the page itself emits the scalar deleting destructor wrapper.
- The rebuild route should be: source `HierList::~HierList()` on [UID:0002I9] plus class/vtable declaration causes the compiler/linker to emit [UID:0002IM]-equivalent ABI glue.

Existing C++/emitter state:

- Formal C++ is blank.
- Prior docs defer the C++ decision because of destructor/wrapper policy uncertainty.
- This report resolves that blocker: do not write C++ into [UID:0002IM]; put source destructor C++ in [UID:0002I9].

Existing open questions, blockers, placeholder names, stale assumptions, or contradictory claims:

- Open blocker: whether [UID:0002IM] should emit as a reconstructable child or be treated as compiler ABI wrapper/no-code.
- Open blocker: whether source-level destructor semantics are covered by [UID:0002I9].
- Open blocker: whether formal C++ is ready and where it belongs.
- Stale/generated names: live IDB names are still `sub_4CEDB0`, `sub_4CE760`, `sub_4F32B0`, `sub_4F30E0`, and `sub_4F4AC0`. These are evidence aliases only and should not appear in finalized source C++.
- Stale tracker state: `auto-generated/-ag-research-tracker.md` still lists [UID:0002IM] as not-covered reconstructable at older `76/88` even though the live page reads `86/90`.

Related target/support docs checked:

- [UID:0002I9] `by-memory/0x004ce760-0x004ce7d1.HierListNonDeletingDestructor.md`
- [UID:00016X] `by-memory/0x004ce730-0x004cee52.HierList.md`
- [UID:000065] `by-class/HierList.md`
- [UID:0000JV] `by-file/HierList.md`
- [UID:0003BL] `by-memory/0x0061b340-0x0061b36c.HierListVtableData.md`
- [UID:0001UQ] `by-type/by-struct/HierListNode.md`
- [UID:000079] `by-class/List.md`
- [UID:000192] `by-memory/0x004f30e0-0x004f3139.ListNonDeletingDestructor.md`
- [UID:0003JW] `by-memory/0x004f32b0-0x004f32da.ListGetElementAt.md`
- [UID:0002II] `by-memory/0x004cebc0-0x004cebec.HierListRemoveAt.md`
- [UID:0002IE] active B001 report `tools/leaser/Agents/Agent-B001/research/0002IE-HierListRemoveNode-source-quality.md`
- [UID:00016X] executed B001 report `executed-b-agent-research/B001/00016X-hierlist-source-quality.md`

## Executive Recommendation

Best direct owner:

- Documentation owner: [UID:000065] `HierList`.
- Source emitter for human code: [UID:0002I9] through [UID:000065] -> [UID:0000JV], not [UID:0002IM].
- [UID:0002IM] should remain linked to `HierList` as ABI-wrapper evidence but should not emit source.

Recommended target disposition:

- [UID:0002IM] should be reclassified:
  - `COMPLETION:90`
  - `CONFIDENCE:93`
  - `CANONICAL_OWNER:000065`
  - `RECONSTRUCTABLE:FALSE`
  - blank `EMITTER_UIDS`
  - blank formal C++
- The page should keep detailed ABI-wrapper evidence, vtable slot facts, delete-flag behavior, child-list cleanup duplication, and no-code proof.

Recommended companion source disposition:

- [UID:0002I9] should be promoted as the source-authored `HierList::~HierList()` body:
  - `COMPLETION:90`
  - `CONFIDENCE:92`
  - keep owner/emitter/reconstructable metadata unchanged.
  - insert formal C++ for the human-written destructor body.

Exact condition for any remaining blocked assignment:

- No remaining current-pass blocker prevents the ABI-wrapper/no-code decision. Future class-wide work still needs to coordinate the complete `HierList` declaration, but that does not block reclassifying [UID:0002IM] or adding source destructor C++ to [UID:0002I9].

## Supervisor Active Recheck

Supervisor instruction:

- New assignment in `Agent-B011/goal.md` targets [UID:0002IM] and specifically asks B011 to attack whether the scalar deleting destructor remains emitting reconstructable or becomes ABI wrapper/no-code covered by the source destructor.

Split repair:

- No file split is needed. Existing pages already have exact range coverage:
  - [UID:0002I9] `0x004ce760-0x004ce7d1`
  - [UID:0002IM] `0x004cedb0-0x004cee52`
  - [UID:00016X] aggregate split index `0x004ce730-0x004cee52`

Source-bearing child status:

- [UID:0002I9] is the source-bearing destructor body.
- [UID:0002IM] is ABI-wrapper evidence generated from source destructor/class declaration and should be non-emitting.

## Inference Research Guidance Check

The incorporated inference discipline and `by-structure.md` affect this recommendation in three ways:

1. The project goal is exact runtime behavior with source that looks like the original developers' C++, not source polluted by decompiler labels or compiler wrapper functions.
2. Compiler/linker-generated artifacts should be documented and excluded from hand-authored source unless a source declaration is required to regenerate them.
3. Current unresolved source-quality blockers must be resolved now rather than left as "needs later class pass".

Existing documentation assumptions treated as uncertain:

- B001's aggregate report kept exact child pages [UID:0002I8]-[UID:0002IM] as reconstructable/emitting while also saying scalar deleting destructor glue should not be hand-authored. That is internally useful historical context but incomplete under the current stricter source-quality rule because it leaves [UID:0002IM] in the emitted source route.
- [UID:0002I9] remained blank because "destructor/source-policy sequencing" was not resolved. This report resolves the sequencing by separating source destructor C++ from compiler scalar deleting wrapper evidence.

Evidence categories:

- IDA fact: function boundaries, xrefs, vtable slot, decompilation, disassembly, byte ranges, pointer-pattern search results, callees, and basic block complexity.
- Documentation evidence: existing `HierList`, `List`, `HierListNode`, and prior B reports.
- Inference: exact human source spelling `HierList::~HierList()` and using `List::GetElementAt(index)` in first-draft source. This is strongly inferred from class/source context and accepted support docs, not recovered original symbol proof.

Wave2/Wave3 handling:

- Stale Wave2/Wave3 references were ignored as authority. Existing generated C++/source names were treated as leads only.

## Heuristic / Inference Reanalysis And Validation

### Issue 1: Should [UID:0002IM] emit code?

Best defensible decision:

- No. [UID:0002IM] is compiler ABI glue and should not emit human source.

Evidence:

- `xrefs_to 0x004cedb0` reports exactly one xref: data pointer at `0x0061b344`, the first `HierList` vtable slot.
- `find_bytes` for little-endian `0x004cedb0` (`B0 ED 4C 00`) finds exactly one match at `0x0061b344`.
- Disassembly shows the wrapper accepts a delete flag stack argument and returns with `retn 4`.
- Disassembly shows MSVC scalar/vector deleting destructor behavior: after running destructor cleanup, `flags & 1` controls object deallocation and `flags & 4` branches to a guarded path that pushes size `0x18` / 24 (Verified with int_convert.py) and calls `_guard_check_icall_nop`.
- The source-facing method for original code is the destructor body, not a public method taking delete flags.

Rejected alternative:

- Keeping [UID:0002IM] reconstructable/emitting with blank code preserves stale generated routing. It still causes generated source to represent the page as an empty emitter, and a future implementation might be tempted to hand-write compiler ABI logic. Reclassifying it now resolves the blocker.

### Issue 2: Does [UID:0002I9] cover the source destructor body?

Best defensible decision:

- Yes. [UID:0002I9] is the source-authored destructor body and should receive formal C++.

Evidence:

- [UID:0002I9] `lookup_funcs 0x004ce760` reports `sub_4CE760`, size `0x71` / 113 bytes (Verified with int_convert.py).
- The non-deleting destructor has the same cleanup loop as [UID:0002IM] but no delete-flag argument and returns with plain `retn`.
- [UID:0002I9] calls `List::GetElementAt` and the base `List` destructor body but does not call object free helper `sub_4F4AC0`.
- It has no direct xrefs and no raw pointer hits for little-endian `0x004ce760` (`60 E7 4C 00`), which is compatible with an unreferenced non-deleting destructor body retained by compiler/EH emission rather than a separately called game method.

Source-shape inference:

- Human-written source should be `HierList::~HierList()` with the child-list cleanup loop.
- The base `List::~List()` call should not be manually written in the C++ body. C++ compiler-generated destructor sequencing calls the base destructor after the derived destructor body.
- The source should not write the `HierList` vtable assignment, SEH/security-cookie setup, or raw `sub_4F30E0` call. Those are generated code artifacts.

### Issue 3: Which names are source-facing?

Best defensible names:

- `HierList::~HierList()` for [UID:0002I9].
- `HierListNode::childList` for row offset `+0x04`.
- `List::GetElementAt(index)` for `sub_4F32B0`.
- `m_count` for inherited count at `this + 0x0c`.

Evidence:

- [UID:0001UQ] documents `HierListNode +0x04` as `childList`.
- [UID:000079] documents `m_count` and `List::GetElementAt`.
- Current decompilation and disassembly show the loop index compared against `this[3]` / `m_count`, row fetch through `sub_4F32B0`, and child pointer loaded from row `+0x04`.

Rejected names:

- `sub_4CEDB0`, `sub_4CE760`, `sub_4F32B0`, and `dword`-style labels are IDA aliases only and must not appear in finalized source.
- `ScalarDeletingDestructor` is useful as a documentation label, not original human source.
- Adding a source method such as `ScalarDeletingDestructor(unsigned int flags)` is rejected as decompiler/compiler-shaped output.

### Issue 4: Are there unresolved score blockers?

Resolved blockers:

- Source/emitter route blocker: resolved by reclassifying [UID:0002IM] as non-emitting ABI wrapper and putting source C++ into [UID:0002I9].
- Formal C++ blocker: resolved for [UID:0002I9] with exact source-shaped destructor C++ below.
- Pointer/reachability blocker: resolved by current MCP xref and byte-pattern searches.
- Source-name blocker: resolved with human source-facing names from support docs and C++ destructor semantics.

Remaining uncertainty:

- Exact original header placement and whether members were named `m_count`, `childList`, or a nearby convention are not original-symbol proven. This limits score below `95+`, but does not block current implementation.

## Evidence Standards Used

Evidence types used:

- IDA MCP `server_health`, `idb_list`, `lookup_funcs`, `xrefs_to`, `callees`, `analyze_function`, `decompile`, `disasm`, `get_bytes`, and `find_bytes`.
- Current by-* docs for `HierList`, `List`, `HierListNode`, vtable data, and sibling methods.
- Prior executed B001 aggregate report as historical context.
- Active B001 remove-node report as directly related current research context.
- Local `int_convert.py` for numeric conversions.

Why evidence is strong enough:

- Multiple independent routes agree: vtable data xref, raw pointer scan, decompiler, disassembly, bytes, callee set, support docs, and C++ destructor ABI rules all point to the same wrapper/source split.

Tool limitations:

- IDA MCP cannot prove original source spelling. The report therefore uses best source-facing inferences and labels them as inferred.
- The compiler can emit scalar deleting destructor glue in several shapes depending on optimization/toolchain. The current binary shape is documented exactly; source output should remain human-shaped.

## Evidence Checked

### MCP availability and session

- Listener: `127.0.0.1:13337`, owning process PID `13684`, process `python.exe`.
- Worker session from `idb_list`: `80de0a67`, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, active worker PID `26892`, `is_analyzing:false`.
- `server_health`: `status:"ok"`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`.

### Function and boundary checks

- `lookup_funcs 0x004cedb0`: `sub_4CEDB0`, size `0xa2` / 162 bytes (Verified with int_convert.py).
- `lookup_funcs 0x004cee52`: not a function.
- `lookup_funcs 0x004cee60`: next function `sub_4CEE60`, size `0x4f`, HourPane successor.
- `lookup_funcs 0x004ce760`: `sub_4CE760`, size `0x71` / 113 bytes (Verified with int_convert.py).
- `lookup_funcs 0x004ce7d1`: not a function.
- `get_bytes 0x004ceda4 size 190`: twelve `0xcc` bytes before [UID:0002IM], exact scalar-wrapper body, fourteen `0xcc` bytes after `retn 4`, then HourPane successor prologue. `0xcc` is 204 decimal (Verified with int_convert.py).
- `get_bytes 0x004ce750 size 145`: constructor epilogue, non-deleting destructor body, fifteen `0xcc` bytes after `retn`, then [UID:0002IA] prologue.
- `get_bytes 0x0061b340 size 48`: RTTI locator pointer then vtable slot `0x0061b344 -> 0x004cedb0`, followed by inherited/HierList virtual method slots and HourPane locator boundary at `0x0061b36c`.

### Xrefs and pointer-pattern checks

- `xrefs_to 0x004cedb0`: exactly one xref, data at `0x0061b344`.
- `xrefs_to 0x004ce760`: no xrefs.
- `xrefs_to 0x0061b344`: five vtable-store/data refs from constructor `0x004ce74e`, non-deleting destructor `0x004ce789`, insert-before `0x004ce93e`, insert-after `0x004cea8d`, and scalar deleting destructor `0x004cede0`.
- `find_bytes "B0 ED 4C 00"`: one match at `0x0061b344`.
- `find_bytes "60 E7 4C 00"`: zero matches.
- `find_bytes "44 B3 61 00"`: five matches at `0x004ce750`, `0x004ce78b`, `0x004ce940`, `0x004cea8f`, and `0x004cede2`.

### Callees and decompilation

- `callees 0x004cedb0`: `0x004f32b0` `List::GetElementAt`, `0x004f30e0` `List::~List` non-deleting body, `0x004f4ac0` object free helper, and `0x0041b6a0` `_guard_check_icall_nop`.
- `callees 0x004ce760`: `0x004f32b0` and `0x004f30e0`.
- `analyze_function 0x004cedb0`: prototype decompiled as `_DWORD *__thiscall(_DWORD *Block, char)`, size 162, 14 basic blocks, cyclomatic complexity 4, one data xref from vtable, no callers.
- `analyze_function 0x004ce760`: prototype decompiled as `void __thiscall(_DWORD *this)`, size 113, 7 basic blocks, cyclomatic complexity 3, no xrefs/callers.
- `decompile 0x004cedb0`: shows vtable write, loop over `Block[3]`, `sub_4F32B0(Block, index)`, child-list load at row `+0x04`, virtual deleting call with flag `1`, clear row `+0x04`, base destructor call, and delete-flag tests.
- `decompile 0x004ce760`: same vtable write and child-list cleanup loop, then base destructor call, with no delete-flag tests and no object free helper.

### Focused disassembly checks

Scalar deleting wrapper [UID:0002IM]:

```text
4cede0 mov dword ptr [esi], offset ??_7HierList@@6B@
4cede6 cmp [esi+0Ch], edi
4cedf3 call sub_4F32B0
4cedfa mov ecx, [ebx+4]
4cee03 push 1
4cee05 call dword ptr [edx]
4cee07 mov dword ptr [ebx+4], 0
4cee16 call sub_4F30E0
4cee1e test al, 1
4cee22 test al, 4
4cee27 call sub_4F4AC0
4cee31 push 18h
4cee34 call @_guard_check_icall_nop@4
4cee4f retn 4
```

Non-deleting destructor [UID:0002I9]:

```text
4ce789 mov dword ptr [edi], offset ??_7HierList@@6B@
4ce78f cmp [edi+0Ch], esi
4ce797 call sub_4F32B0
4ce79e mov ecx, [ebx+4]
4ce7a7 push 1
4ce7a9 call dword ptr [edx]
4ce7ab mov dword ptr [ebx+4], 0
4ce7ba call sub_4F30E0
4ce7d0 retn
```

## Inference Claim Ledger

| Claim | Confidence | Evidence | Counter-evidence checked | Next verification / remaining uncertainty |
| --- | --- | --- | --- | --- |
| [UID:0002IM] is compiler scalar deleting destructor ABI glue, not source-authored C++ | Strong | One vtable data xref, one raw pointer hit at vtable slot, delete flag stack parameter, `retn 4`, `flags & 1` free path, `flags & 4` guarded size path | Checked direct xrefs, raw pointer hits, decompile/disasm, non-deleting companion | Exact compiler version not proven; does not block no-code disposition |
| [UID:0002I9] is the source `HierList::~HierList()` body | Strong | Same cleanup loop without delete flags/free helper, no direct caller, source destructor semantics, base destructor call at end | Checked [UID:0002IM], [UID:000192], vtable refs, docs | Exact header declaration still class-wide work |
| Formal C++ belongs in [UID:0002I9], not [UID:0002IM] | Strong | Source-shaped code should not include delete flags, vtable writes, SEH, security cookie, or manual scalar-wrapper free path | Checked prior B001 aggregate report and current target docs | Class-wide declaration pass should later integrate all method declarations |
| `HierListNode::childList` is the row `+0x04` field cleaned by destructor | Strong | [UID:0001UQ], decompile/disasm loads `[row+4]`, virtual delete call, clear `[row+4]` | Checked remove-node and lookup support docs | Exact original member spelling not symbol-proven |
| `List::GetElementAt(index)` is the source-facing row accessor in destructor C++ | Strong | [UID:0003JW], direct `sub_4F32B0` call with valid index loop | Checked base List docs and destructor disassembly | Whether final code uses explicit `List::` qualifier is source-style inference |

## Positive Evidence Summary

- [UID:0002IM] is reachable only from `HierList` vtable slot `0x0061b344`.
- [UID:0002IM] has delete-flag logic and returns with `retn 4`, matching scalar deleting destructor ABI shape.
- [UID:0002I9] has the same cleanup loop without delete-flag logic, matching the source destructor body.
- Both forms write the `HierList` vtable, iterate `m_count`, fetch rows via `List::GetElementAt`, delete non-null child lists through virtual slot `0`, clear `childList`, and call base `List` destructor.
- Existing `HierListNode` and `List` docs provide source-facing names sufficient for formal destructor C++.
- Reclassifying [UID:0002IM] removes generated-output pollution while preserving exact binary evidence.

## IDA MCP Facts

Function/range facts:

- [UID:0002IM] is `0x004cedb0-0x004cee52`, size `0xa2` / 162 bytes (Verified with int_convert.py).
- [UID:0002I9] is `0x004ce760-0x004ce7d1`, size `0x71` / 113 bytes (Verified with int_convert.py).
- [UID:0002IM] is followed by fourteen `0xcc` bytes before `0x004cee60`.
- [UID:0002I9] is followed by padding before [UID:0002IA].

Vtable/data facts:

- `0x0061b344` contains little-endian pointer bytes `B0 ED 4C 00`.
- `0x0061b340` is the `HierList` RTTI-adjacent locator pointer.
- The next class locator boundary is HourPane at `0x0061b36c`.
- Vtable stores use `0x0061b344` from constructor, non-deleting destructor, insert-before, insert-after, and scalar deleting destructor.

Xref facts:

- [UID:0002IM] has one incoming data xref at the vtable.
- [UID:0002I9] has no incoming xrefs and no raw pointer hits.
- `List::~List` non-deleting body has calls from both [UID:0002I9] and [UID:0002IM].

Negative IDA facts:

- No original source symbol was recovered for [UID:0002IM] or [UID:0002I9].
- No string/constant evidence names the destructor.
- No direct code caller uses [UID:0002IM]; dispatch is vtable-driven.
- No pointer route to [UID:0002I9] was found.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004ce760-0x004ce7d1` | [UID:0002I9] `by-memory/0x004ce760-0x004ce7d1.HierListNonDeletingDestructor.md` | Source-authored `HierList::~HierList()` destructor body | TRUE | [UID:000065] | current `86/90`, recommend `90/92` | Should emit formal source C++ |
| `0x004cedb0-0x004cee52` | [UID:0002IM] `by-memory/0x004cedb0-0x004cee52.HierListScalarDeletingDestructor.md` | Compiler scalar deleting destructor wrapper | recommend FALSE | [UID:000065] documentation owner | current `86/90`, recommend `90/93` | Should not emit formal source C++ |
| `0x004ce730-0x004cee52` | [UID:00016X] `by-memory/0x004ce730-0x004cee52.HierList.md` | Non-emitting split/index | FALSE | [UID:000065] | `88/91` | Needs child table/source-quality sync only |
| `0x0061b340-0x0061b36c` | [UID:0003BL] `by-memory/0x0061b340-0x0061b36c.HierListVtableData.md` | Vtable/RTTI-adjacent data | TRUE as generated-binary data | [UID:000065] | `86/90` | Needs note that slot 0 is compiler-generated wrapper |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0061b344 -> 0x004cedb0` | data xref to [UID:0002IM] | `HierList` primary vtable slot 0 points at scalar deleting destructor |
| `0x004cede0` | vtable store inside [UID:0002IM] | wrapper reinstalls `HierList` vtable during destruction |
| `0x004ce789` | vtable store inside [UID:0002I9] | source destructor body also reinstalls `HierList` vtable during destructor state |
| `0x004cedf3`, `0x004ce797` | call `0x004f32b0` | row fetch through `List::GetElementAt` |
| `0x004cee16`, `0x004ce7ba` | call `0x004f30e0` | base `List::~List()` generated destructor chain |
| `0x004cee27` | call `0x004f4ac0` | object memory free in scalar deleting wrapper only |
| `0x004cee34` | call `_guard_check_icall_nop` after push `0x18` | guarded delete/vector-delete-shaped ABI path, not source method logic |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- [UID:0002I9] already documents the non-deleting destructor as source-authored destructor body, with child-list cleanup and base list destruction.
- [UID:0002IM] already documents vtable-only xref state, delete flags, conditional `this` free, and caveat not to hand-write wrapper as normal project C++.
- [UID:00016X] already says scalar deleting destructor is compiler ABI glue and should not be hand-authored as ordinary source.
- [UID:0003BL] vtable data records slot `0x0061b344 -> 0x004cedb0`.
- [UID:0001UQ] records `childList` and payload layout.

Existing docs that are stale, incomplete, or contradicted:

- [UID:0002IM] still has `RECONSTRUCTABLE:TRUE` and `EMITTER_UIDS:000065`, which contradicts the "do not hand-write wrapper" source policy.
- [UID:0002I9] still leaves formal C++ blank because prior docs deferred destructor/source-policy sequencing.
- [UID:000065], [UID:0000JV], and [UID:00016X] should stop listing [UID:0002IM] as source-emitting child output and instead explain it is compiler wrapper evidence generated from the source destructor.
- `auto-generated/-ag-research-tracker.md` has stale score/reconstructable queue state for [UID:0002IM].

Generated/coverage report state:

- `auto-generated/-ag-memory-coverage.md` currently shows [UID:0002IM] as `emits` through [UID:000065] into `auto-generated/NexusTK/util/HierList.cpp`.
- This should be refreshed by validators after source metadata changes. B011 must not edit generated reports directly.

## Ranked Ownership Analysis

### 1. [UID:000065] `HierList` documentation owner, non-emitting ABI wrapper

Evidence for:

- Vtable slot belongs to `HierList`.
- Wrapper manipulates `HierList` row child lists and calls `List` base destructor.
- Existing class/file/aggregate docs all agree on `HierList` source cluster ownership.

Evidence against:

- It is not human-authored source code and should not emit as a method body.

Decision:

- Keep [UID:000065] as documentation owner; set [UID:0002IM] non-reconstructable and non-emitting.

### 2. [UID:0002I9] source destructor body as source-emitting companion

Evidence for:

- Same child-list cleanup without delete flags.
- This is the code a human developer would write as `HierList::~HierList()`.
- Base `List` destructor call is a compiler-generated destructor chain from source inheritance, not source syntax.

Evidence against:

- No direct xrefs. This is not problematic because destructor bodies can be retained for EH/debug/compiler reasons while vtable dispatch uses scalar deleting destructor.

Decision:

- Add formal source C++ to [UID:0002I9].

### 3. Source-emitting [UID:0002IM] as `HierList::ScalarDeletingDestructor`

Evidence for:

- Exact binary code exists and runs from the vtable.
- It contains class-specific cleanup duplicated from destructor body.

Evidence against:

- Delete-flag argument, guarded flag branch, `retn 4`, object free helper, and vtable-only pointer route are compiler ABI wrapper traits.
- Original human C++ would not include a method named scalar deleting destructor or a delete-flag parameter.
- Emitting this page would pollute final source with compiler/decompiler shape.

Decision:

- Reject as final source route.

### 4. `List` or `Layer` ownership

Evidence for:

- `List` supplies the base row access and destructor cleanup.
- `Layer` is a major consumer of `HierList` APIs.

Evidence against:

- The wrapper is in the `HierList` vtable and manipulates `HierListNode::childList`.
- `Layer` has no ownership role here.

Decision:

- Reject `List` and `Layer` ownership.

## Source Placement

Recommended source file/class/global/module placement:

- Source destructor: `NexusTK/util/HierList.cpp`, class `HierList`, [UID:0002I9].
- ABI wrapper evidence: [UID:0002IM], non-emitting `by-memory` evidence page under [UID:000065] documentation ownership.
- Vtable data: [UID:0003BL] remains source-declared/generated-binary data for `HierList`.

Why this placement fits source-tree and subsystem context:

- `HierList` is a utility tree-aware list container, not a UI pane.
- [UID:0000JV] already owns the `NexusTK/util/` route.
- `Layer` uses `HierList`; it does not own the implementation.

Rejected placements:

- `Layer.cpp`: rejected as consumer only.
- `List.cpp`: rejected as base-class support only.
- A new destructor-wrapper source file: rejected as compiler-artifact driven organization.

Remaining placement uncertainty:

- Final header/source declaration layout for `HierList` remains class-wide work but does not affect current target disposition.

## Range / Split / Padding / Reclassification Analysis

Exact range/boundary facts:

- [UID:0002IM] starts at `0x004cedb0` and ends at `0x004cee52`.
- The function is size `0xa2` / 162 bytes (Verified with int_convert.py).
- `0x004cee52-0x004cee60` is `0xcc` padding before HourPane successor `0x004cee60`.
- [UID:0002I9] starts at `0x004ce760` and ends at `0x004ce7d1`.
- `0x004ce7d1` is not a function and padding follows before [UID:0002IA].

Children/subranges:

- No new child page is needed.
- [UID:0002IM] is an exact child but should be reclassified from source-emitting reconstructable to non-emitting compiler ABI wrapper.
- [UID:0002I9] remains exact child source destructor and should receive formal C++.

Padding/table/data/code distinctions:

- [UID:0002IM] itself is executable code but compiler-generated wrapper code.
- Vtable data at [UID:0003BL] should be regenerated by compiler/linker from source declarations.
- Internal and successor `0xcc` spans remain padding and should not emit.

Parent/container impact:

- [UID:00016X] aggregate remains non-emitting split/index. Its child table should mark [UID:0002IM] as compiler ABI wrapper/no-code and [UID:0002I9] as the source destructor body.

## Negative Evidence Summary

Checked and rejected:

- Direct code xrefs to [UID:0002IM]: none.
- Pointer routes to [UID:0002IM] outside vtable: none found.
- Pointer routes to [UID:0002I9]: none found.
- Strings/constants that reveal source names: none.
- A source-level scalar deleting destructor function: rejected due ABI flag and vtable-only evidence.
- Hand-written call to base `List::~List()` in `HierList::~HierList()` C++: rejected because C++ destructor chaining emits that call automatically.
- Hand-written memory free of `this` in destructor C++: rejected because delete wrapper handles object free outside the human destructor body.
- Treating absence of original symbols as a blocker: rejected. Current rules require best source-facing inference.

## IDA Rename / Type / Comment Recommendations

Proposed source-facing names/types/comments:

- Source destructor body [UID:0002I9]: `HierList::~HierList()`.
- ABI wrapper [UID:0002IM]: keep documentation label `HierListScalarDeletingDestructor`; do not use as source method name.
- `sub_4F32B0`: source-facing `List::GetElementAt`.
- `sub_4F30E0`: source-facing `List::~List()` non-deleting base destructor body.
- `sub_4F4AC0`: allocator/free helper for object memory in compiler deleting destructor path; do not expose in source destructor.
- `HierListNode +0x04`: `childList`.

IDA DB edits:

- No IDA DB edits are requested in this report-only pass. Naming/type changes in IDA may be safe later, but this task only writes a report.

## First-Draft C++ Recommendation

### [UID:0002IM] target formal C++ disposition

Eligible for draft C++:

- No. The target page documents compiler-generated scalar deleting destructor glue and should not carry formal source C++.

Reason code should remain blank:

- Original-looking C++ should author only `HierList::~HierList()`.
- The delete-flag parameter, object free helper call, guarded size path, vtable store, SEH frame, security cookie, and `retn 4` are compiler output.
- Adding a source method for these would make final code look reverse-engineered rather than like mid-2000s human-written game-client C++.

Exact no-code proof:

- MCP session `80de0a67` confirms [UID:0002IM] has exactly one incoming xref from `HierList` vtable slot `0x0061b344`, no direct callers, one raw pointer match at the same vtable slot, delete-flag tests `flags & 1` and `flags & 4`, object free helper call, guarded path with size `0x18` / 24 (Verified with int_convert.py), and `retn 4`. These are compiler scalar deleting destructor traits. The source destructor body is [UID:0002I9].

### [UID:0002I9] companion source destructor C++ disposition

Eligible for draft C++:

- Yes. This is the source-authored destructor body.

Recommended code:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
HierList::~HierList()
{
    for (int index = 0; index < m_count; ++index) {
        HierListNode *node = static_cast<HierListNode *>(List::GetElementAt(index));
        if (node->childList != NULL) {
            delete node->childList;
            node->childList = NULL;
        }
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Reason it preserves exact original behavior:

- `index < m_count` matches the loop compare against `this + 0x0c`.
- `List::GetElementAt(index)` matches the direct call to `0x004f32b0`.
- `node->childList` matches row offset `+0x04`.
- `delete node->childList` expresses the virtual deleting destructor call with delete flag `1` without exposing compiler ABI flags.
- Clearing `node->childList = NULL` matches the store to row `+0x04`.
- The source body omits explicit `List::~List()` because C++ emits the base destructor chain automatically after the derived destructor body.

Reason it matches plausible original source shape:

- It is ordinary C++ destructor code a late-1990s/mid-2000s developer would write.
- It uses `NULL` and straightforward loop/source names consistent with older C++ style.
- It does not expose vtable writes, SEH/security-cookie scaffolding, delete flags, or IDA labels.

Inferred source-facing names/types/fields used:

- `m_count` from accepted `List` layout.
- `HierListNode` and `childList` from accepted node layout.
- `List::GetElementAt` from accepted List virtual/accessor docs.

Naming/coding style convention:

- `m_` inherited field style follows accepted `List` docs.
- `NULL` is used instead of `nullptr` for era-appropriate source.

## Final Recommendation

Exact recommended target changes:

- [UID:0002IM] target:
  - Change `COMPLETION:86 -> 90`.
  - Change `CONFIDENCE:90 -> 93`.
  - Keep `CANONICAL_OWNER:000065`.
  - Change `RECONSTRUCTABLE:TRUE -> FALSE`.
  - Blank `EMITTER_UIDS`.
  - Keep formal C++ blank.
  - Add no-code proof and current MCP evidence.
  - Replace "source-authored destructor wrapper / compiler ABI wrapper; source class still reconstructable" wording with "compiler ABI wrapper generated from source destructor; wrapper itself non-emitting".

Exact companion changes:

- [UID:0002I9] companion source destructor:
  - Change `COMPLETION:86 -> 90`.
  - Change `CONFIDENCE:90 -> 92`.
  - Keep owner/emitter/reconstructable metadata unchanged.
  - Insert the exact `HierList::~HierList()` formal C++ block above.
  - Add note that base `List::~List()` is implicit in C++ destructor chaining.

Exact items left no-owner/non-emitting:

- [UID:0002IM] should be non-emitting because it is compiler-generated ABI glue.

Exact future work outside this assignment:

- Class-wide `HierList` declaration pass should coordinate method declarations, header/source order, and remaining child C++ for insert cores, remove/repair helpers, and vtable-driven methods.

## Recommended Target Doc Changes

Target path:

- `by-memory/0x004cedb0-0x004cee52.HierListScalarDeletingDestructor.md`

Exact report facts to incorporate:

- MCP session `80de0a67` health/status.
- Boundary facts for `0x004cedb0-0x004cee52`.
- Vtable-only xref and raw pointer-search evidence.
- Delete-flag ABI proof: `flags & 1`, `flags & 4`, `sub_4F4AC0`, guarded size `0x18` / 24, `retn 4`.
- Relationship to [UID:0002I9] source destructor body.
- No-code proof and reclassification rationale.
- Historical assumption that this exact page should emit as a reconstructable child is superseded by current ABI-wrapper analysis.

Metadata/score/owner/emitter/reconstructable/C++ changes:

- `COMPLETION:90`
- `CONFIDENCE:93`
- `CANONICAL_OWNER:000065`
- `RECONSTRUCTABLE:FALSE`
- blank `EMITTER_UIDS`
- blank formal C++

Historical/stale assumptions, rejected alternatives, and negative evidence to preserve:

- Preserve prior vtable-only and child-list cleanup evidence.
- Add that source should not hand-author scalar deleting destructor logic.
- Preserve negative pointer/caller evidence.
- Preserve rejected `Layer`/`List` ownership.

## Recommended Support Doc Changes

Support path:

- `by-memory/0x004ce760-0x004ce7d1.HierListNonDeletingDestructor.md`

Exact report facts to incorporate:

- This page is the source-authored `HierList::~HierList()` body.
- Add formal C++ block from this report.
- Add current MCP comparison with [UID:0002IM].
- Add that the base `List::~List()` call is compiler destructor chaining, so it is not written manually in the destructor source body.

Metadata/link/score/coverage/source-placement changes:

- `COMPLETION:90`
- `CONFIDENCE:92`
- metadata otherwise unchanged.

Support path:

- `by-memory/0x004ce730-0x004cee52.HierList.md`

Exact report facts to incorporate:

- Update child table entry for [UID:0002IM] to "compiler scalar deleting destructor wrapper/no-code".
- Update child table entry for [UID:0002I9] to "source `HierList::~HierList()` destructor body with formal C++".
- Keep aggregate non-emitting.

Support path:

- `by-class/HierList.md`

Exact report facts to incorporate:

- Method map should describe [UID:0002I9] as formal `HierList::~HierList()` source body.
- Method map should describe [UID:0002IM] as compiler scalar deleting destructor wrapper, non-emitting/no-code.
- Autogen status should not list [UID:0002IM] as exact child output.

Support path:

- `by-file/HierList.md`

Exact report facts to incorporate:

- Proposed contents should list source destructor at `0x004ce760`.
- Migration notes should say scalar deleting destructor `0x004cedb0` is generated wrapper evidence, not source to hand-port.
- The generated-output route should depend on `HierList::~HierList()` and compiler vtable/destructor emission.

Support path:

- `by-memory/0x0061b340-0x0061b36c.HierListVtableData.md`

Exact report facts to incorporate:

- Slot `0x0061b344` points to generated scalar deleting destructor wrapper [UID:0002IM].
- This vtable data should be regenerated from the class declaration and virtual destructor, not hand-authored.

Support path:

- `by-type/by-struct/HierListNode.md`

Exact report facts to incorporate:

- No required edit. Existing `childList` and payload layout already support this report.

Support path:

- `by-class/List.md`, `by-memory/0x004f30e0-0x004f3139.ListNonDeletingDestructor.md`, `by-memory/0x004f32b0-0x004f32da.ListGetElementAt.md`

Exact report facts to incorporate:

- No required edit. Existing `m_count`, `m_data`, `List::GetElementAt`, and base destructor docs already support this report.

## Score And Metadata Recommendation

Current [UID:0002IM] score/metadata:

- `COMPLETION:86`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:000065`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:000065`
- blank formal C++

Recommended [UID:0002IM] score/metadata:

- `COMPLETION:90`
- `CONFIDENCE:93`
- `CANONICAL_OWNER:000065`
- `RECONSTRUCTABLE:FALSE`
- blank `EMITTER_UIDS`
- blank formal C++

Score rationale and reason not higher/lower:

- Completion rises because the page can now close the source-policy blocker, distinguish source destructor from ABI wrapper, record current MCP proof, and stop emitting an empty generated source marker.
- Confidence rises because vtable-only reachability, pointer-pattern evidence, delete-flag disassembly, non-deleting companion comparison, and C++ source-shape rules all agree.
- Do not raise to `95+` because exact compiler version, class declaration text, and final integrated `HierList` source/header are still not fully audited.
- Do not leave lower because the current source-quality blocker is resolved and implementation-ready.

Current [UID:0002I9] score/metadata:

- `COMPLETION:86`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:000065`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:000065`
- blank formal C++

Recommended [UID:0002I9] score/metadata:

- `COMPLETION:90`
- `CONFIDENCE:92`
- metadata otherwise unchanged.
- formal `HierList::~HierList()` C++ inserted.

Score-improvement attempt:

- Blocker: wrapper/source destructor policy. Resolved by separating [UID:0002IM] no-code wrapper from [UID:0002I9] source destructor.
- Blocker: formal C++ readiness. Resolved for [UID:0002I9]; rejected for [UID:0002IM] with exact no-code proof.
- Blocker: placeholder names. Resolved through accepted source-facing names from support docs.
- Blocker: reachability. Resolved through vtable xref and pointer-pattern checks.

## Open Questions With Attempted Resolution

Open question: Should [UID:0002IM] remain reconstructable/emitting?

- Evidence checked: xrefs, pointer patterns, vtable data, disassembly, decompilation, byte ranges, non-deleting destructor relationship, support docs, prior B001 report.
- Resolution: no. It should be non-reconstructable/non-emitting compiler ABI wrapper evidence.
- Score/C++ impact: target score rises, formal C++ remains blank, generated empty emitter marker should disappear after validation/execute flow.

Open question: Where should source destructor C++ go?

- Evidence checked: [UID:0002I9] decompilation/disassembly, [UID:0002IM] comparison, `List` and `HierListNode` support docs.
- Resolution: [UID:0002I9] should receive `HierList::~HierList()` formal C++.
- Score/C++ impact: [UID:0002I9] can rise and generate source-shaped destructor body.

Open question: Should destructor C++ manually call `List::~List()` or object free?

- Evidence checked: C++ destructor semantics, disassembly showing base destructor call only in compiled output, scalar wrapper free path only in [UID:0002IM].
- Resolution: no. The source body should delete child lists and let the compiler emit base destructor chaining and scalar deleting wrapper free logic.
- Score/C++ impact: avoids decompiler-shaped source and preserves plausible original source shape.

Open question: Are any helper pages missing?

- Evidence checked: existing exact pages [UID:0002I9], [UID:0002IM], [UID:0003JW], [UID:000192], [UID:0001UQ], [UID:0003BL].
- Resolution: no new pages are needed.

Remaining unresolved issue:

- Exact original member spelling and header declaration layout remain class-wide future work. This does not block current source/no-code disposition because the recommended C++ uses already accepted project-local source-facing names.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

No manual `-coverage-report.md` edit is requested from B011. B agents must not edit coverage-report files.

Do not write rows into validator-owned `auto-generated/-ag-*` reports. The supervisor should use validators and `execute_report` to refresh generated research/coverage state.

If the supervisor later chooses to manually update legacy `by-memory/-coverage-report.md`, the exact replacement intent for the [UID:0002IM] row is:

```markdown
        - [UID:0002IM][0x004cedb0-0x004cee52.HierListScalarDeletingDestructor](by-memory/0x004cedb0-0x004cee52.HierListScalarDeletingDestructor.md) 0x004cedb0-0x004cee52 | compiler-generated | HierListScalarDeletingDestructor : ignored/non-emitting : 90% : very-strong : Compiler scalar deleting destructor wrapper reached only through the HierList vtable slot; duplicates `HierList::~HierList()` child-list cleanup, applies delete flags and optional object free, and should be regenerated from the class destructor rather than hand-authored as source.
```

Reason B agent must not apply it directly:

- Coverage-report files are supervisor-owned by current workflow to avoid edit collisions.

## Follow-Up Actions

Supervisor actions:

- Validate this report and checklist.
- If accepted, send B011 an implementation callback.
- After B011 implementation, verify target/support docs claim-by-claim.
- Run `python .\tools\validator.py execute_report B011 0002IM-HierListScalarDeletingDestructor-source-quality.md 0002IM --apply` only after verification succeeds.

A-agent actions:

- None required.

B011 future implementation actions if accepted:

- Apply target/support edits listed below.
- Run scoped validators.
- Update this checklist with proof.
- Return implementation result for supervisor verification.

## Confidence

Recommendation confidence:

- Strong for reclassifying [UID:0002IM] as compiler ABI wrapper/no-code.
- Strong for [UID:0002I9] as source destructor body.

Score confidence:

- `90/93` for [UID:0002IM] is justified by current MCP proof and resolved source policy.
- `90/92` for [UID:0002I9] is justified by current MCP proof and source C++ readiness.

Remaining uncertainty:

- Exact original member names and header declaration order are inferred, not symbol-proven.
- Exact compiler version is not proven.
- Full class-wide source pass still needed before `HierList` reaches final audit quality.

## Validator Results

Commands run:

- `python .\tools\validator.py --mode file --file by-memory/0x004cedb0-0x004cee52.HierListScalarDeletingDestructor.md --apply --queue-timeout 240 --wait-generated`
- `python .\tools\validator.py --mode file --file by-memory/0x004ce760-0x004ce7d1.HierListNonDeletingDestructor.md --apply --queue-timeout 240 --wait-generated`
- `python .\tools\validator.py --mode file --file by-memory/0x004ce730-0x004cee52.HierList.md --apply --queue-timeout 240 --wait-generated`
- `python .\tools\validator.py --mode file --file by-class/HierList.md --apply --queue-timeout 240 --wait-generated`
- `python .\tools\validator.py --mode file --file by-file/HierList.md --apply --queue-timeout 240 --wait-generated`
- `python .\tools\validator.py --mode file --file by-memory/0x0061b340-0x0061b36c.HierListVtableData.md --apply --queue-timeout 240 --wait-generated`

Results:

- [UID:0002IM] validator command `000000002516`, timestamp `2026-06-26T06:26:04-04:00`, exited `0`, `ok: 1`, generated refresh completed.
- [UID:0002I9] validator command `000000002517`, timestamp `2026-06-26T06:26:34-04:00`, exited `0`, `ok: 1`, generated refresh completed.
- [UID:00016X] validator command `000000002519`, timestamp `2026-06-26T06:26:53-04:00`, exited `0`, `ok: 1`, generated refresh completed.
- [UID:000065] validator command `000000002521`, timestamp `2026-06-26T06:27:16-04:00`, exited `0`, `ok: 1`, generated refresh completed.
- [UID:0000JV] validator command `000000002524`, timestamp `2026-06-26T06:27:36-04:00`, exited `0`, `ok: 1`, generated refresh completed.
- [UID:0003BL] validator command `000000002525`, timestamp `2026-06-26T06:28:01-04:00`, exited `0`, `ok: 1`, generated refresh completed.

Unresolved validator warnings/errors:

- No blocking errors from the scoped files. The validator still reported unrelated stale registry/missing-file noise, including the pre-existing missing target for [UID:00025H] referenced from the vtable-data validation.

## Changed Files

Created:

- `tools/leaser/Agents/Agent-B011/research/0002IM-HierListScalarDeletingDestructor-source-quality.md`

Modified:

- `by-memory/0x004cedb0-0x004cee52.HierListScalarDeletingDestructor.md`
- `by-memory/0x004ce760-0x004ce7d1.HierListNonDeletingDestructor.md`
- `by-memory/0x004ce730-0x004cee52.HierList.md`
- `by-class/HierList.md`
- `by-file/HierList.md`
- `by-memory/0x0061b340-0x0061b36c.HierListVtableData.md`
- `tools/leaser/Agents/Agent-B011/research/0002IM-HierListScalarDeletingDestructor-source-quality.md`

Validator-driven generated refreshes may have updated generated/projected validator outputs. No generated, project-level, coverage-report, tool-state, or IDA DB files were manually edited by Agent-B011.

Renamed:

- None.

Report execution:

- Implementation callback complete; report execution/move to `research/executed/` remains supervisor-owned.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Proof: accepted implementation callback was written in `Agent-B011/goal.md` before edits and named [UID:0002IM] plus companion [UID:0002I9].
- [x] Lease only immediate accepted edit files immediately before implementation; do not lease during report review. Proof: B011 leased the six accepted by-* files only for the edit/validator batch; release check after validation reported no active B011 leases.
- [x] Update [UID:0002IM] `by-memory/0x004cedb0-0x004cee52.HierListScalarDeletingDestructor.md`: set `COMPLETION:90`, `CONFIDENCE:93`, keep `CANONICAL_OWNER:000065`, set `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, keep formal C++ blank. Proof: header now has `COMPLETION:90`, `CONFIDENCE:93`, `CANONICAL_OWNER:000065`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and blank formal C++.
- [x] Update [UID:0002IM] item summary/status to state compiler scalar deleting destructor wrapper generated from `HierList::~HierList()`, not source-emitting method code. Proof: item summary/status now name it a compiler scalar deleting destructor ABI wrapper and route source to [UID:0002I9].
- [x] Add [UID:0002IM] current MCP evidence: session `80de0a67`, health OK, exact range `0x004cedb0-0x004cee52`, vtable-only xref `0x0061b344`, raw pointer match only at `0x0061b344`, no direct callers, delete-flag disassembly, helper callees, and endpoint padding. Proof: new B011 ABI-wrapper reclassification section records those exact MCP checks and byte/range facts.
- [x] Add [UID:0002IM] no-code proof and rejected alternatives: no source `ScalarDeletingDestructor(flags)` method, no manual object free in source destructor, no `Layer`/`List` ownership. Proof: [UID:0002IM] now has no-code proof, rejected alternatives, and superseded historical assumption notes.
- [x] Update [UID:0002I9] `by-memory/0x004ce760-0x004ce7d1.HierListNonDeletingDestructor.md`: set `COMPLETION:90`, `CONFIDENCE:92`, keep owner/emitter/reconstructable metadata unchanged. Proof: header now has `90/92` with owner/emitter/reconstructable unchanged.
- [x] Insert the exact formal `HierList::~HierList()` `RECONSTRUCTION_CPP CODE` block from this report into [UID:0002I9]. Proof: [UID:0002I9] formal C++ now emits only the source destructor body that deletes nested `childList` values and clears pointers.
- [x] Add [UID:0002I9] current MCP comparison against [UID:0002IM], including no delete-flag/free path and source-shaped destructor body rationale. Proof: [UID:0002I9] B011 source destructor C++ pass records the comparison and keeps base destructor/scalar delete/free out of hand-authored source.
- [x] Update [UID:00016X] `by-memory/0x004ce730-0x004cee52.HierList.md`: mark [UID:0002I9] as formal source destructor C++ and [UID:0002IM] as non-emitting compiler scalar deleting destructor wrapper; keep aggregate `RECONSTRUCTABLE:FALSE` and blank emitter. Proof: functions table, evidence notes, autogen status, and source-quality decisions now distinguish those two roles.
- [x] Update [UID:000065] `by-class/HierList.md`: method map/source notes should identify [UID:0002I9] as `HierList::~HierList()` formal source body and [UID:0002IM] as compiler ABI wrapper/no-code. Proof: method map, ownership notes, autogen status, and changes section now carry the distinction.
- [x] Update [UID:0000JV] `by-file/HierList.md`: proposed contents/migration notes should route source destructor through [UID:0002I9] and state [UID:0002IM] is generated wrapper evidence, not a hand-authored method. Proof: proposed contents and migration notes now route destructor source to [UID:0002I9] and treat [UID:0002IM] as generated wrapper evidence.
- [x] Update [UID:0003BL] `by-memory/0x0061b340-0x0061b36c.HierListVtableData.md`: note slot `0x0061b344` points at generated scalar deleting destructor wrapper regenerated from class declaration/destructor. Proof: item summary, observed contents row, and reconstruction notes now document that slot policy.
- [x] Confirm no required edit to [UID:0001UQ] `HierListNode`, [UID:000079] `List`, [UID:000192] `ListNonDeletingDestructor`, or [UID:0003JW] `ListGetElementAt` because existing support docs already provide the necessary `childList`, `m_count`, `List::GetElementAt`, and base destructor semantics. Proof: callback accepted those support docs as sufficient; [UID:0002I9] and support updates now reference those roles without requiring additional edits.
- [x] Do not edit generated files, project-level generated reports, validator/tool state, IDA DB, `by-memory/-coverage-report.md`, or any other `-coverage-report.md`. Proof: Agent-B011 made manual edits only to accepted by-* docs and this report; any generated/projected validator refresh output was produced by scoped validators, not hand-edited.
- [x] Run scoped target validator: `python .\tools\validator.py --mode file --file by-memory/0x004cedb0-0x004cee52.HierListScalarDeletingDestructor.md --apply --queue-timeout 240 --wait-generated`. Proof: command `000000002516`, timestamp `2026-06-26T06:26:04-04:00`, exit `0`, `ok: 1`, generated refresh completed.
- [x] Run scoped source-destructor validator: `python .\tools\validator.py --mode file --file by-memory/0x004ce760-0x004ce7d1.HierListNonDeletingDestructor.md --apply --queue-timeout 240 --wait-generated`. Proof: command `000000002517`, timestamp `2026-06-26T06:26:34-04:00`, exit `0`, `ok: 1`, generated refresh completed.
- [x] Run scoped aggregate validator if edited: `python .\tools\validator.py --mode file --file by-memory/0x004ce730-0x004cee52.HierList.md --apply --queue-timeout 240 --wait-generated`. Proof: command `000000002519`, timestamp `2026-06-26T06:26:53-04:00`, exit `0`, `ok: 1`, generated refresh completed.
- [x] Run scoped class validator if edited: `python .\tools\validator.py --mode file --file by-class/HierList.md --apply --queue-timeout 240 --wait-generated`. Proof: command `000000002521`, timestamp `2026-06-26T06:27:16-04:00`, exit `0`, `ok: 1`, generated refresh completed.
- [x] Run scoped file validator if edited: `python .\tools\validator.py --mode file --file by-file/HierList.md --apply --queue-timeout 240 --wait-generated`. Proof: command `000000002524`, timestamp `2026-06-26T06:27:36-04:00`, exit `0`, `ok: 1`, generated refresh completed.
- [x] Run scoped vtable-data validator if edited: `python .\tools\validator.py --mode file --file by-memory/0x0061b340-0x0061b36c.HierListVtableData.md --apply --queue-timeout 240 --wait-generated`. Proof: command `000000002525`, timestamp `2026-06-26T06:28:01-04:00`, exit `0`, `ok: 1`, generated refresh completed.
- [x] After validators, check generated-refresh metadata if generated `auto-generated/NexusTK/util/HierList.cpp`, `auto-generated/-ag-memory-coverage.md`, or `auto-generated/-ag-research-tracker.md` is used as proof; do not hand-edit generated reports. Proof: all six validators reported generated refresh completed; generated output was not used as primary proof beyond validator success.
- [x] Release all leases immediately after implementation edit/validator batch. Proof: explicit B011 unlease command after validators returned `Rejected[No active lease]` for all six files, and `current_leases.md` had no B011 matches.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation. Proof: accepted callback in `Agent-B011/goal.md` named the exact implementation scope.
- [x] All accepted target/support doc details incorporated at report-level detail. Proof: [UID:0002IM], [UID:0002I9], [UID:00016X], [UID:000065], [UID:0000JV], and [UID:0003BL] now carry the accepted destructor/source-wrapper distinction.
- [x] Metadata/score/owner/emitter/C++ changes applied or explicitly not applied with reason. Proof: [UID:0002IM] changed to `90/93`, non-reconstructable, blank emitter/C++; [UID:0002I9] changed to `90/92` and formal destructor C++; support docs updated without owner/emitter drift.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved. Proof: [UID:0002IM] includes no-code proof, rejected alternatives, and superseded historical assumption notes instead of pruning prior interpretation.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale. Proof: remaining uncertainty is limited to exact original member names/header order/compiler version/full class-wide final audit; none blocks accepted implementation.
- [x] Validators run and results recorded with command IDs/timestamps. Proof: see Validator Results above.
- [x] Generated report refresh completed by validator or reported as deferred/stale. Proof: all six scoped validators reported generated refresh completed.
- [x] Remaining unapplied accepted items listed with exact blocker. Proof: no accepted implementation items remain unapplied.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B011","command_id":"000000004165","destination_path":"executed-b-agent-research/B011/0002IM-HierListScalarDeletingDestructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B011/research/0002IM-HierListScalarDeletingDestructor-source-quality.md","timestamp":"2026-06-26T06:36:08","uid":"0002IM"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
