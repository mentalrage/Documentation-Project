** TARGET-REPORT-UID:000343 **
** AUTHOR-AGENT-ID:B013 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# [UID:000343] FolderTreeDirectoryEntryNameLess empty-emitter source-quality report

Assignment: `B013-report-000343-FolderTreeDirectoryEntryNameLess-empty-emitter-source-quality-20260628`  
Target: `by-memory/0x004b3350-0x004b33fc.FolderTreeDirectoryEntryNameLess.md`  
Original report revision mode: no by-* docs were edited during the research pass, no leases were taken, and no generated/project/manual coverage/tool/IDA state was modified by that pass.

Implementation callback status, 2026-06-28: accepted report details were applied to the target/support by-* docs, scoped validators were run, leases were released, and the checklist at the end of this report is checked with proof. `execute_report` was not run; supervisor owns execution after verification.

## Revised Recommendation

Resolve the empty-emitter state by inserting formal first-draft comparator C++ for [UID:000343], not a no-body marker.

Recommended target metadata:

| Field | Current | Recommended |
| --- | ---: | ---: |
| `COMPLETION` | `86` | `90` |
| `CONFIDENCE` | `88` | `91` |
| `CANONICAL_OWNER` | `0000JG` | `0000JG` |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` |
| `EMITTER_UIDS` | `0000JG` | `0000JG` |
| `EMITTER_POSITION_OPTIONAL` | blank | blank |

Exact formal `RECONSTRUCTION_CPP CODE` insertion:

```cpp
namespace {

static mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> >
MakeDirectoryEntryCompareName(
    const mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> >& name)
{
    mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > key(name);
    key.DetachWideIfShared();
    _wcsupr_s(const_cast<wchar_t *>(key.c_str()), key.length() + 1);
    return key;
}

static bool DirectoryEntryNameLess(const FolderTreePane::DirectoryEntry& lhs,
                                   const FolderTreePane::DirectoryEntry& rhs)
{
    mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > lhsName =
        MakeDirectoryEntryCompareName(lhs.name);
    mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > rhsName =
        MakeDirectoryEntryCompareName(rhs.name);

    return WideRangeCompare(lhsName.c_str(),
                            lhsName.c_str() + lhsName.length(),
                            rhsName.c_str(),
                            rhsName.c_str() + rhsName.length()) < 0;
}

} // namespace
```

This replaces the prior rejected marker-only recommendation. The exact original spelling of `SimpleUString` versus `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> >` remains inferred, but current B-agent rules require a best source-facing source shape when behavior and route are this strong. The formal block uses the project-established `StringBase` pointer-backed type vocabulary because the binary record field is a 4-byte pointer-backed wide string handle, and accepted StringBase docs already use `DetachWideIfShared`, `c_str()`, `length()`, `UpperWideInPlace` / `_wcsupr_s`, and `WideRangeCompare` in first-draft formal C++.

## Current Target State

[UID:000343] currently has:

- `COMPLETION:86`, `CONFIDENCE:88`.
- `CANONICAL_OWNER:0000JG`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JG`.
- Blank inline and multiline `RECONSTRUCTION_CPP CODE`.
- Status text calling it a reconstructable NexusTK source helper and a file-local comparison predicate over the 12-byte temporary directory-entry record used by `FindFirstVisibleChild`.
- Reconstruction text saying not to emit final C++ because the local entry type and string helper wrapper names remain inferred.

Generated state checked:

- `auto-generated/NexusTK/ui/controls/FolderTreePane.cpp` currently lists:
  - `// UID:000343 | by-memory\0x004b3350-0x004b33fc.FolderTreeDirectoryEntryNameLess.md | Completion:86 | Confidence:88 | Empty Emitter Marker`
- `auto-generated/-ag-research-tracker.md` currently lists UID000343 in `Files With Empty Emitters` with score `86/88`, average `87.0`, reconstructable `true`, and no executed report.

The current docs correctly identify the owner and broad behavior, but the blank-emitter state is no longer defensible. UID000343 clears the current combined score/emitter gate, has a file owner/emitter, and is the source anchor for the neighboring UID000446 normalizer marker.

## Prior Report And Support-Doc Leads Checked

The required prior-report/support-doc search was done before finalizing this revision. These were used as leads, not as substitutes for the current MCP evidence pass:

- `executed-b-agent-research/B008/00005A-FolderTreePane-class-source-quality.md`: supports `FolderTreePane::DirectoryEntry` as the 12-byte scratch record family and separates it from the persistent 36-byte `TreeElem`.
- `executed-b-agent-research/B008/00034B-FolderTreeDirectoryEntrySortCore-source-quality.md` and `executed-b-agent-research/B009/00034C-FolderTreeDirectoryEntrySortPartition-source-quality.md`: treat the partition/introsort helpers as compiler/container support and route source shape to the owning directory-entry sort expression.
- `executed-b-agent-research/B009/00022E-FolderTreePaneVectorSupportHelpers-source-quality.md`: supports the local vector/scratch-record model around folder-tree child enumeration.
- `executed-b-agent-research/B001/000157-FolderTreePaneTreeAndSortHelpers.md`: supports the aggregate non-emitting split and identifies UID000343 as the comparator child rather than a whole aggregate owner.
- `executed-b-agent-research/B010/000155-FolderTreePaneCore-empty-emitter-source-quality.md`: supports the expansion/enumeration route but does not currently emit the comparator expression, which blocks a marker-only disposition for UID000343.
- Current by-* support docs checked as leads: `by-file/FolderTreePane.md`, `by-class/FolderTreePane.md`, `by-memory/0x004b1b90-0x004b32c9.FolderTreePaneCore.md`, `by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md`, `by-memory/0x004b4520-0x004b4fc5.FolderTreeDirectoryEntrySortCore.md`, and `by-memory/0x004b5c40-0x004b5cbc.FolderTreeDirectoryEntryNormalizeNameForCompare.md`.

## MCP And Tool Evidence Checked

Live IDA MCP was mandatory and was used. No IDA DB edits or MCP process-control actions were made.

MCP session/tool evidence:

- Endpoint: `http://127.0.0.1:13337/mcp`.
- JSON-RPC `initialize`: succeeded; server `ida-pro-mcp` version `1.0.0`, protocol `2025-06-18`.
- `tools/list`: 65 tools exposed, including `server_health`, `lookup_funcs`, `decompile`, `disasm`, `xrefs_to`, `callees`, `get_bytes`, `type_query`, `search_structs`, `idb_list`, and `idb_open`; current schemas require the explicit `database` argument for session-bound calls and `decompile` uses `addr`.
- `idb_list`: active session `agent_b009_0002my_20260628`, input path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, filename `NexusTK.exe.i64`, created at `2026-06-28T21:51:27.830021`, not analyzing, active `true`, backend worker, owned/adopted, worker PID `2412`.
- `server_health(database='agent_b009_0002my_20260628')`: status `ok`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, strings cache size `2067`.

Numeric conversions were checked with `tools/int_convert.py`:

- `0xac` = `172`.
- `0x0c` = `12`.
- `0x10` = `16`.
- `0x12` = `18`.
- `0x04` = `4`.
- `0x06` = `6`.
- `0x08` = `8`.
- `0x09` = `9`.
- `0x20` = `32`.
- `0x28` = `40`.

## Actual Evidence Checked

### Function Boundary

`lookup_funcs` with the active MCP session reports:

- `0x004b3350` is `sub_4B3350`, size `0xac`.
- `0x004b33fc` is not a function.
- The target is exactly `0x004b3350-0x004b33fc`, a 172-byte function.

`get_bytes` around the target confirms the physical boundary:

- Bytes before `0x004b3350` end with the predecessor return and `0xcc` padding.
- The target starts at `0x004b3350`.
- The function return ends before `0x004b33fc`.
- `0x004b33fc-0x004b3400` is four bytes of `0xcc` padding, and the next function starts at `0x004b3400`.

### Callers And Reachability

`xrefs_to(0x004b3350)` reports exactly three ordinary code references, all from `sub_4B44C0`:

- `0x004b44d0`.
- `0x004b44ea`.
- `0x004b4504`.

`xrefs_to(0x004b44c0)` reports five references from `sub_4B4520`:

- `0x004b45b2`.
- `0x004b45c3`.
- `0x004b45d6`.
- `0x004b45e7`.
- `0x004b45f7`.

`xrefs_to(0x004b4520)` reports one reference from `sub_4B5280` at `0x004b52e0`.

`xrefs_to(0x004b5280)` reports:

- `0x004b214e` from `sub_4B1D50`.
- Recursive calls inside `sub_4B5280` at `0x004b5329` and `0x004b533d`.

This establishes the live route:

`FolderTreePane::FindFirstVisibleChild` / expansion path at `0x004b1d50` -> sort wrapper `0x004b5280` -> partition/sort core `0x004b4520` -> compare/swap helper `0x004b44c0` -> comparator [UID:000343] `0x004b3350`.

### Comparator Body Semantics

`callees(0x004b3350)` reports:

- `0x004b5c40`.
- `0x00583450`.
- `0x005840f0`.
- `0x00582b70`.

The active MCP decompilation of `0x004b3350` shows this behavior:

- A normalized temporary is produced for the second input via `0x004b5c40`.
- A normalized temporary is produced for the first input via `0x004b5c40`.
- If the two normalized string buffers have the same pointer, the compare result is `0`.
- Otherwise the helper obtains string metadata/length through `0x00583450` for both strings.
- It calls `0x005840f0` to compare the first normalized string range against the second normalized string range.
- It destroys both temporaries through `0x00582b70`.
- It returns `compareResult < 0`.

The active disassembly confirms the same lowering:

- SEH/security-cookie prologue and cleanup tails are compiler scaffolding.
- `0x004b3376` loads the second source parameter and calls `0x004b5c40` into a stack temporary.
- `0x004b3384` loads the first source parameter and calls `0x004b5c40`.
- `0x004b339f` compares normalized string buffer pointers and fast-paths equal pointers to false.
- `0x004b33c9` calls `0x005840f0` with first begin/end followed by second begin/end.
- `0x004b33d6` and `0x004b33de` destroy both temporaries.
- The return sequence shifts the sign bit of the compare result and returns a boolean.

The evidence supports source semantics of "left entry's normalized name sorts before right entry's normalized name." It does not support a reversed comparator.

### Normalization Helper And String API Names

The active MCP decompilation of `0x004b5c40` shows the comparison-key helper:

- Copy/share construct destination from the source name through `0x00582a90`.
- Detach/make writable through `0x005830c0`.
- Read string metadata through `0x00583450`.
- Uppercase `length + 1` wide characters in place through `0x00582980`.
- Return the destination string object.

`xrefs_to(0x004b5c40)` reports 26 code references, all in the folder-tree directory-entry sort neighborhood: two from UID000343 itself, four from `0x004b4240`, sixteen from `0x004b4520`, and four from `0x004b4fd0`. No observed reference routes this helper to `SpelledPane`, `FolderSelectDialog`, `TreeStorage`, or a shared public UI method owner.

Accepted string docs give source-facing names for these operations:

- [UID:0002RN] and [UID:00022D] use pointer-backed `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> >` and `length()` for the ref-counted wide string family.
- [UID:0002RO] names `0x005830c0` as `DetachWideIfShared`.
- [UID:0002RM] names `0x00582980` as the wide uppercase-in-place secure CRT wrapper and formalizes it as `_wcsupr_s` / `UpperWideInPlace`.
- [UID:0002RS] formal C++ uses `c_str()` and `WideRangeCompare` over wide ranges.

Therefore the revised formal body uses realistic source-facing names rather than blocking on missing original symbols.

### Sorting Context

The active MCP decompilation of `0x004b44c0` shows an order-three compare/swap dispatcher:

- It calls `0x004b3350(a2, a1)` and swaps through `0x004b5510(a2, a1)` if true.
- It calls `0x004b3350(a3, a2)` and swaps through `0x004b5510(a3, a2)` if true.
- After the second swap, it rechecks `0x004b3350(a2, a1)`.

The active MCP decompilation of `0x004b5510` shows a 12-byte directory-entry swap:

- It saves/copies the string field from the first record.
- It saves copied words at offsets `+4` and `+6`.
- It saves copied flag bytes at offsets `+8` and `+9`.
- It assigns the second record into the first and the saved temporary into the second.
- It destroys the temporary string.

The active MCP decompilation of `0x004b5280` shows the sort wrapper/introsort shell:

- It computes the element count from `(last - first) / 12`.
- It uses insertion sort support at `0x004b4240` for small ranges of `0x20` / 32 entries or fewer.
- Larger ranges route through the partition helper at `0x004b4520`, recursive calls back into `0x004b5280`, and heap/fallback support at `0x004b4fd0`.
- The wrapper repeatedly copies, assigns, and destroys the same 12-byte directory-entry record shape, so UID000343 is the comparator for that scratch-record sort and not a persistent tree-node comparator.

The active MCP decompilation of `0x004b1d50` confirms the owning use:

- It constructs the current path for a folder-tree node.
- It uses `FindFirstFileA` / `FindNextFileA`.
- It filters visible child directories with directory bit `0x10` and hidden mask `0x12`, excluding dot entries.
- It builds 12-byte temporary records with a name string, two word fields, and two byte flags.
- It advances the directory-entry vector pointer by three dwords, i.e. 12 bytes.
- It calls `0x004b5280` at `0x004b214e` to sort the entries.
- It consumes the sorted entries into the 36-byte `TreeElem` / `TreeStorage` nodes and marks child-loaded/expanded state.

The comparator belongs to the local child-directory sort expression. It is not a public UI method, storage method, shared string utility, or FolderSelectDialog helper.

### Type And Struct Evidence

The current MCP type catalog does not recover original source UDTs:

- `type_query` for `*DirectoryEntry*`, `*FolderTreePane*`, and `*TreeElem*` returned zero local type records.
- Valid `search_structs` calls for `DirectoryEntry`, `FolderTreePane`, and `TreeElem` returned empty arrays.

This no longer blocks source C++. It only means `FolderTreePane::DirectoryEntry` and the exact string facade spelling are inferred. The best inferred record layout is already supported by accepted FolderTreePane sort docs:

- offset `+0`: pointer-backed wide string handle, represented in formal C++ as `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> >` and described in prose as the `SimpleUString` facade when using UI-facing terminology.
- offset `+4`: `short rowIndex`.
- offset `+6`: `short depthOrIndent`.
- offset `+8`: `unsigned char childrenLoaded`.
- offset `+9`: `unsigned char expanded`.

The persistent `FolderTreePane::TreeElem` is a separate 36-byte tree node populated after sorting. It is not the comparator record type.

## Positive Evidence

- The exact function range and size are verified live.
- All ordinary callers are inside the local folder-tree directory-entry sort machinery.
- The body has no UI side effects and no external ownership behavior; it only constructs normalized comparison keys, compares wide ranges, destroys temporaries, and returns a signed-less-than boolean.
- The caller chain reaches the child-directory enumeration path in `FolderTreePane`.
- The sort records are 12-byte temporary directory entries, not the 36-byte persistent `TreeElem` nodes.
- Accepted B008/B009 reports already route the sort internals through a high-level `FolderTreePane::ExpandNode` / `EnsureChildrenLoaded` directory-entry sort expression.
- [UID:000446] already marks its normalization helper as reconstructed through UID000343 and the owning sort expression, so UID000343 must become the concrete comparator source anchor rather than stay blank.
- Accepted StringBase support docs supply realistic source-facing names for the exact string operations used by the comparator.

## Negative Evidence

- No caller points to a public `FolderTreePane` method entry for this range.
- No caller points to `FolderSelectDialog`, `TreeStorage`, `Tree`, `SpelledPane`, or a shared common library owner.
- No recovered IDA UDT proves original `DirectoryEntry` spelling.
- No PDB/debug/source symbol proves original `DirectoryEntryNameLess` spelling.
- UID000155 `FolderTreePaneCore` and the owning expansion method currently do not emit the child-directory sort expression; using a covered-by marker on UID000343 would still leave no actual emitted source expression for the comparator.
- A blank reconstruction block is not acceptable with `RECONSTRUCTABLE:TRUE` and `EMITTER_UIDS:0000JG`, because generated `FolderTreePane.cpp` emits UID000343 as an empty-emitter marker.

## Source-Shape Decision

### Accepted Shape: File-Local Static Comparator

Use a file-local helper in `FolderTreePane.cpp`:

- `DirectoryEntryNameLess` is source-facing and matches the current target filename/role.
- The function has no `this` pointer and no class state access, so it should not be a public or private `FolderTreePane` method body.
- The comparator is called by multiple Dinkumware/MSVC sort helper instantiations, which is more consistent with a stable named predicate/helper than with an inlined method body.
- The pre-C++11 codebase makes a lambda expression implausible as original source. A file-local static helper or function object is the better late-1990s / early-2000s source shape.
- The formal block uses `FolderTreePane::DirectoryEntry` as the source-facing scratch-record type because current FolderTreePane support docs already accept that naming direction. If a later class-header pass prefers a file-local `DirectoryEntry` instead of a nested `FolderTreePane::DirectoryEntry`, that is a declaration-placement adjustment, not a reason to leave UID000343 blank.

### Rejected Shape: Marker Covered By Owning Expansion Method

Rejected for this target. A marker-only covered-by disposition would require a specific owner target that already emits or is guaranteed to emit the source expression. Current evidence does not provide that:

- [UID:000155] `FolderTreePaneCore` still has an empty marker in generated `FolderTreePane.cpp`.
- [UID:00034B] and [UID:00034C] are sort-internal marker pages, not the high-level expansion method.
- [UID:000446] already points back to UID000343 for reconstruction.

Leaving UID000343 marker-only would preserve the same empty-emitter failure through a different comment.

### Rejected Shape: Local Lambda Or Method-Local Type Only

Rejected as the implementation recommendation. The codebase predates C++11 lambda use, and the compiled comparator appears as a standalone helper called from sort machinery. A method-local scratch vector still exists in the expansion method, but the comparator source should be represented as a file-local static helper over the scratch record.

### Rejected Shape: Public `FolderTreePane` Method

Rejected. The target has no `this`, vtable route, UI field access, or external caller. Public method emission would overstate the source API.

### Rejected Shape: Non-Reconstructable Compiler-Only Sort Internal

Rejected. UID000349/00034A/00034B/00034C/00034D/00034E are the sort/container support pages. UID000343 is the source ordering policy those helpers invoke. It is the correct place to emit first-draft comparator C++.

## Metadata And Score Rationale

Recommended `COMPLETION:90`:

- The report resolves the empty emitter with formal first-draft C++.
- Exact range, padding, caller chain, callee roles, sort context, record layout, owner/emitter, and support-doc updates are now implementation-ready.
- The report replaces the stale "names inferred" blocker with explicit inferred source-facing names.

Recommended `CONFIDENCE:91`:

- Live MCP confirms function boundary, decompile/disassembly semantics, caller chain, normalizer behavior, and negative type evidence.
- Existing executed FolderTreePane/StringBase reports corroborate the `DirectoryEntry`, `DetachWideIfShared`, `_wcsupr_s`, `c_str()`, `length()`, and `WideRangeCompare` vocabulary.
- Confidence stays below final-audit level because original PDB/source names are absent and the final public `SimpleUString` versus `StringBase` facade spelling remains a broader string-header question.

Do not raise this target to `95+` yet. The exact original comparator name, final `DirectoryEntry` declaration placement, and string facade spelling are inferred rather than symbol-proven.

## Exact Implementation Scope After Supervisor Acceptance

Do not edit any files in report-only mode. If the supervisor accepts this revised report, apply the following exact target/support edits only.

### Must Edit

1. `by-memory/0x004b3350-0x004b33fc.FolderTreeDirectoryEntryNameLess.md`

- Set `COMPLETION:90`.
- Set `CONFIDENCE:91`.
- Keep `CANONICAL_OWNER:0000JG`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JG`, blank `EMITTER_POSITION_OPTIONAL`.
- Insert the exact formal C++ block from this report in the multiline `RECONSTRUCTION_CPP CODE` block.
- Add an `Item Summary` equivalent to: file-local FolderTreePane directory-entry name-less comparator with formal first-draft C++, 12-byte scratch-record inputs, copied/detached/uppercased comparison keys, `WideRangeCompare`, and live MCP caller/callee/boundary evidence.
- Replace stale "do not emit final C++ yet" wording with the current source-shape rationale: original names are inferred, but current behavior and support docs are strong enough for formal first-draft comparator C++.
- Add current MCP evidence from session `agent_b009_0002my_20260628`: health ok, exact boundary, three callers from `0x004b44c0`, callee set, decompile/disassembly semantics, sort route through `0x004b5280`, normalizer behavior, and negative IDA UDT evidence.
- Preserve rejected alternatives: blank emitter, marker-only covered by UID000155, public method, local lambda-only, TreeElem/TreeStorage ownership, non-reconstructable sort internal.

2. `by-file/FolderTreePane.md`

- In the directory-entry sort policy, split UID000343 from the sort-internal helper group: UID000343 now emits the file-local `DirectoryEntryNameLess` comparator; UID000349/00034A/00034B/00034C/00034D/00034E remain compiler/container sort support.
- Record the source-facing scratch-record fields: `name` as pointer-backed wide `StringBase` / `SimpleUString` facade, `rowIndex`, `depthOrIndent`, `childrenLoaded`, and `expanded`.
- Record that UID000446 is normalization support covered by the UID000343 comparator body and the owning sort expression.

3. `by-class/FolderTreePane.md`

- Add the same source-placement decision at class level: comparator is file-local sort support over `FolderTreePane::DirectoryEntry`, not a public `FolderTreePane` method.
- Preserve the 12-byte scratch record versus 36-byte persistent `TreeElem` distinction.
- Mention that the owning high-level expansion method should call `std::sort` or the equivalent local sort over directory entries using `DirectoryEntryNameLess`.

4. `by-memory/0x004b1b90-0x004b32c9.FolderTreePaneCore.md`

- Add current route from the expansion/enumeration method to the sort wrapper and UID000343 comparator: `FindFirstVisibleChild` / `ExpandNode` builds 12-byte directory-entry records, calls `0x004b5280`, and the sort machinery invokes UID000343 for normalized-name ordering.
- Preserve directory filtering evidence: `FindFirstFileA` / `FindNextFileA`, directory bit `0x10`, hidden mask `0x12`, dot-entry exclusion, and post-sort insertion into 36-byte `TreeElem` nodes.

5. `by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md`

- Refresh the UID000343 child row to say it now carries formal first-draft `DirectoryEntryNameLess` comparator C++.
- Remove or supersede any stale aggregate wording that says the comparator should stay blank because names are inferred.
- Keep the aggregate itself non-emitting/mixed split; do not copy the UID000343 formal body into the aggregate.

6. `by-memory/0x004b5c40-0x004b5cbc.FolderTreeDirectoryEntryNormalizeNameForCompare.md`

- Preserve its existing marker-only formal block.
- Add a support note that UID000343 now supplies the concrete comparator C++ that covers this normalizer's source role.
- Keep the normalizer classified as compiler/string-lowering support, not a standalone public method.

7. `by-memory/0x004b4520-0x004b4fc5.FolderTreeDirectoryEntrySortCore.md`

- Update the source-level sort sketch/prose to name UID000343 as the formal first-draft comparator body.
- Preserve the existing no-standalone-body disposition for the partition/introsort support.
- Keep UID00034B as sort machinery, not as the owner of the comparator C++.

### Check-Only / No Edit Expected

These pages should be checked during implementation but should not be edited unless a direct contradiction is found:

- `by-memory/0x004b4240-0x004b44b3.FolderTreeDirectoryEntryInsertionSort.md`: already treats the page as sort support and calls UID000343; no target-specific contradiction is known.
- `by-memory/0x004b44c0-0x004b451b.FolderTreeDirectoryEntryCompareSwap3.md`: already describes order-three compare/swap support using UID000343; no required wording change beyond target cross-reference freshness.
- `by-memory/0x004b5280-0x004b5510.FolderTreeDirectoryEntrySortWrapper.md`: already routes source shape to the high-level sort expression and predicate; no required change unless it still says UID000343 is blank.
- `by-memory/0x004b5510-0x004b55d3.FolderTreeDirectoryEntrySwap.md`: swap helper is independent sort/container support; no required change.
- `by-type/by-struct/FolderTreePane__TreeElem.md`: already documents the persistent 36-byte tree node, which is negative proof against TreeElem ownership for the 12-byte sort record.
- `by-class/TreeStorage_struct_FolderTreePane__TreeElem_.md`: already documents persistent tree storage, which is negative proof against TreeStorage ownership for the comparator.

## Validator And Generated Refresh Expectations

After an implementation callback, run scoped validators for every changed by-* file. Use `--wait-generated` on the target and any changed file whose generated output route matters.

Expected target validator command shape:

> Executable block R001 was removed from this report and preserved verbatim in [000343-FolderTreeDirectoryEntryNameLess-empty-emitter-source-quality-removed.md](000343-FolderTreeDirectoryEntryNameLess-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected generated check after the target validator:

- `auto-generated/NexusTK/ui/controls/FolderTreePane.cpp` should no longer list UID000343 as an `Empty Emitter Marker`.
- The generated file should contain the formal `DirectoryEntryNameLess` comparator block if generated refresh completes for this route.

Do not run `execute_report`; supervisor owns execution after implementation verification.

## Implementation Tracking Checklist

- [x] Lease only the accepted edit set immediately before implementation. Proof: leased only the immediate edit batches: target/normalizer/sort-core earlier in the callback; then single-file core batch; then, after B006's `by-file`/`by-class`/aggregate leases expired at `2026-06-29T02:41:55Z`, leased `by-file/FolderTreePane.md`, `by-class/FolderTreePane.md`, and `by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md` for the final support batch.
- [x] Edit `by-memory/0x004b3350-0x004b33fc.FolderTreeDirectoryEntryNameLess.md`: set score to `90/91`, keep owner/emitter metadata unchanged, insert the exact formal C++ block, update Item Summary, current MCP evidence, source-shape decision, score rationale, and rejected alternatives. Proof: target header is `COMPLETION:90`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000JG`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JG`, blank emitter position; formal block contains `MakeDirectoryEntryCompareName` and `DirectoryEntryNameLess`; validator `000000000086` at `2026-06-28T22:32:14-04:00`, exit `0`, `ok: 1`, generated refresh completed.
- [x] Edit `by-file/FolderTreePane.md`: distinguish UID000343 as the formal comparator body, keep neighboring sort pages as compiler/container support, document the 12-byte scratch-record fields, and link UID000446 as covered normalization support. Proof: rows/notes now record the `0x004b1d50` lazy-expansion route through `0x004b5280`, [UID:000343] comparator, and [UID:000446] normalization; validator `000000000107` at `2026-06-28T22:43:50-04:00`, exit `0`, `ok: 1`, generated refresh completed.
- [x] Edit `by-class/FolderTreePane.md`: add the file-local comparator/source-placement note, 12-byte scratch record versus 36-byte `TreeElem` distinction, and high-level expansion sort expression using `DirectoryEntryNameLess`. Proof: Method Notes, Directory Entry Sort Policy, heuristic row, cross-reference, and change log now describe UID000343 as private/file-local comparator source; validator `000000000108` at `2026-06-28T22:44:06-04:00`, exit `0`, `ok: 1`, generated refresh completed.
- [x] Edit `by-memory/0x004b1b90-0x004b32c9.FolderTreePaneCore.md`: add the enumeration -> 12-byte record vector -> `0x004b5280` sort -> UID000343 comparator route and preserve directory filtering facts. Proof: Item Summary, `0x004b1d50` row, source-quality notes, B013 sync section, cross-reference, and change log updated; validator `000000000095` at `2026-06-28T22:38:26-04:00`, exit `0`, `ok: 1`.
- [x] Edit `by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md`: refresh UID000343 row and stale blank-C++ wording; keep the aggregate non-emitting. Proof: Item Summary and UID000343 inventory row now mark source-ready comparator child; B013 sync section keeps aggregate `RECONSTRUCTABLE:FALSE`/non-emitting; validator `000000000109` at `2026-06-28T22:44:26-04:00`, exit `0`, `ok: 1`, generated refresh completed.
- [x] Edit `by-memory/0x004b5c40-0x004b5cbc.FolderTreeDirectoryEntryNormalizeNameForCompare.md`: add that UID000343 now supplies the concrete comparator C++ covering this normalizer source role; keep UID000446 marker-only. Proof: Formal reconstruction and changes now state UID000343 supplies concrete comparator C++; validator `000000000082` at `2026-06-28T22:31:26-04:00`, exit `0`, `ok: 1`, generated refresh completed.
- [x] Edit `by-memory/0x004b4520-0x004b4fc5.FolderTreeDirectoryEntrySortCore.md`: update source-level sort prose to reference UID000343's formal comparator body while preserving UID00034B as sort machinery. Proof: Item Summary/Reconstruction Notes/sibling role map/change log name UID000343 formal comparator and keep UID00034B as comment-only sort machinery; validator `000000000084` at `2026-06-28T22:31:50-04:00`, exit `0`, `ok: 1`, generated refresh completed.
- [x] Check and record no-edit proof for `by-memory/0x004b4240-0x004b44b3.FolderTreeDirectoryEntryInsertionSort.md`. Proof: existing page already records sole caller from `0x004b5280`, 12-byte `DirectoryEntry` operation, [UID:000343] cross-reference, and no public hand-port guidance.
- [x] Check and record no-edit proof for `by-memory/0x004b44c0-0x004b451b.FolderTreeDirectoryEntryCompareSwap3.md`. Proof: existing page already records median/order-three support over 12-byte records, [UID:000343] as name-less predicate, [UID:00034E] swap support, and no public method disposition.
- [x] Check and record no-edit proof for `by-memory/0x004b5280-0x004b5510.FolderTreeDirectoryEntrySortWrapper.md`. Proof: existing page already records the only non-recursive caller from `FindFirstVisibleChild`, 12-byte sort loop/introsort driver role, likely [UID:000343] predicate, and owning expansion sort expression guidance.
- [x] Check and record no-edit proof for `by-memory/0x004b5510-0x004b55d3.FolderTreeDirectoryEntrySwap.md`. Proof: existing page already records 12-byte `DirectoryEntry` swap/copy support, [UID:000343] cross-reference, and distinction from 36-byte `TreeElem` copy construction.
- [x] Check and record no-edit proof for `by-type/by-struct/FolderTreePane__TreeElem.md`. Proof: existing page already documents the persistent 36-byte `TreeElem` layout and storage/traversal evidence, giving negative proof that UID000343's 12-byte scratch comparator is not `TreeElem` ownership.
- [x] Check and record no-edit proof for `by-class/TreeStorage_struct_FolderTreePane__TreeElem_.md`. Proof: existing page already documents contiguous 36-byte `TreeElem` storage, `InsertAt`/destructor/range-copy support, and template storage ownership, giving negative proof against moving the 12-byte comparator into TreeStorage.
- [x] Run scoped validators for every changed by-* file, with `--wait-generated` on the target. Proof: validator command IDs `000000000082`, `000000000084`, `000000000086`, `000000000095`, `000000000107`, `000000000108`, and `000000000109` all exited `0` with `ok: 1`; `--wait-generated` was used for target, normalizer, sort-core, by-file, by-class, and aggregate generated freshness. Validator side effects included projected stats/generated metadata refreshes, autogenerated backups, research/memory auto coverage refreshes, and known broad stale/missing registry warnings unrelated to UID000343.
- [x] Verify generated `auto-generated/NexusTK/ui/controls/FolderTreePane.cpp` no longer shows UID000343 as an `Empty Emitter Marker` after refresh. Proof: final generated header is `validator-command-id: 000000000109`, `validator-refreshed-at: 2026-06-28T22:44:26-04:00`; `rg` shows UID000343 at line 229 with `Completion:90 | Confidence:91`, `MakeDirectoryEntryCompareName`, and `DirectoryEntryNameLess`, and no UID000343 `Empty Emitter Marker` line. Other UID empty markers remain unrelated.
- [x] Release leases immediately after edit/validator batch. Proof: B013 released the core lease after validator `000000000095` and released `by-file`, `by-class`, and aggregate leases after validator `000000000109`; final `tools/leaser/Agents/current_leases.md` read shows no active B013 leases, only unrelated B010/B012/B014/B015 leases.
- [x] Do not execute or move this report; supervisor owns execution. Proof: this report remains in `tools/leaser/Agents/Agent-B013/research/`; no `execute_report` command was run.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B013","command_id":"000000004165","destination_path":"executed-b-agent-research/B013/000343-FolderTreeDirectoryEntryNameLess-empty-emitter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B013/research/000343-FolderTreeDirectoryEntryNameLess-empty-emitter-source-quality.md","timestamp":"2026-06-28T22:48:42","uid":"000343"} -->
<!-- {"agent":"B013","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000343-FolderTreeDirectoryEntryNameLess-empty-emitter-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B013/000343-FolderTreeDirectoryEntryNameLess-empty-emitter-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000343"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
