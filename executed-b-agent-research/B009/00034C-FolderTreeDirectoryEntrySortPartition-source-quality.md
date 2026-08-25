** TARGET-REPORT-UID:00034C **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00034C FolderTreeDirectoryEntrySortPartition Source-Quality Reanalysis

## Finalized Report / Current Recommendation

- Current recommendation: accept the target as owned by [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md), but correct the source-quality interpretation from "sort partition/merge helper" to a MSVC/Dinkumware `std::sort` heap fallback helper.
- Best target name: `FolderTreeDirectoryEntryAdjustHeap`.
- Final disposition: reconstructable source-derived/template-instantiation support for `FolderTreePane` child-directory sorting; not a handwritten standalone source helper.
- Required action: rename/rewrite the target documentation around the `std::_Adjust_heap` / heap sift-down role, keep owner/emitter route `0000JG`, add a target-specific no-code proof, and optionally emit only a comment marker rather than a function body.
- Score recommendation: `COMPLETION:88`, `CONFIDENCE:91`. This is an increase from `85/87`, supported by direct PE disassembly and call-site reconstruction, but still below final-audit quality because live IDA MCP was unavailable and original source symbols are not preserved.
- Confidence: high for role correction, owner/reachability, and source placement; medium-high for exact original STL helper spelling because it is inferred from the MSVC/Dinkumware algorithm shape rather than recovered symbols.

## Target

- Target UID: `00034C`
- Current target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x004b4fd0-0x004b5271.FolderTreeDirectoryEntrySortPartition.md`
- Recommended target path after rename: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x004b4fd0-0x004b5271.FolderTreeDirectoryEntryAdjustHeap.md`
- Current target scores and metadata: `COMPLETION:85`, `CONFIDENCE:87`, `CANONICAL_OWNER:0000JG`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JG`, formal C++ blank.
- Current coverage row: "partition/merge helper called from the sort wrapper."
- Current supervisor classification: source-quality reanalysis for reconstructable `85/87` target.
- Report-only status: no by-* docs, generated docs, coverage reports, or project-level files were edited.

## Executive Recommendation

The current owner and emitter route are correct: this range belongs with `ui/controls/FolderTreePane.cpp` because it is only directly reached from the local folder-tree directory-entry sort wrapper, which is only non-recursively called from `FolderTreePane::FindFirstVisibleChild`. The current helper name and role are stale. Direct PE disassembly shows `0x004b4fd0` is not the partition helper; it is the heap-adjust/sift-down helper used by the wrapper when the introsort depth/ideal budget is exhausted.

The best source-facing interpretation is:

- `0x004b5280`: MSVC/Dinkumware-style `_Sort` / introsort driver over 12-byte folder directory-entry records.
- `0x004b4520`: likely `_Unguarded_partition` or partitioning helper, not the whole "sort core."
- `0x004b4fd0`: `_Adjust_heap` / sift-down helper for the heapsort fallback.
- `0x004b4240`: `_Insertion_sort` for the small-range tail.
- `0x004b44c0`: median/order-three compare-swap helper.
- `0x004b3350`: comparison predicate over entry names.

The target should remain under [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md), but final source should be represented by the owning folder-tree sort expression, probably a local `std::sort(entries.begin(), entries.end(), FolderTreeDirectoryEntryNameLess)` or equivalent local sort over a temporary `DirectoryEntry` vector. Do not emit a handwritten standalone `FolderTreeDirectoryEntryAdjustHeap` function body as final C++.

## Supervisor Active Recheck

- The prompt explicitly assigned [UID:00034C] `0x004b4fd0-0x004b5271.FolderTreeDirectoryEntrySortPartition.md`; this overrides the older active B009 notes that mention a Browser target.
- The assigned item does not require a split. PE disassembly confirms the documented half-open range is one function body with length `0x2a1` / 673 bytes.
- The target does require source-quality repair because the prior "partition/merge" label is contradicted by wrapper call-site shape and the target's heap-index control flow.
- No direct by-* edits were made because the assignment is report-only.

## Inference Research Guidance Check

`by-structure.md` requires source-quality work past the 85/85 threshold when helper names, source placement, final C++, or generated placeholder issues remain. That applies here: the page already clears 85/85, but the source-level helper role is still wrong/incomplete.

`inference_research.md` says source ownership should not be inferred from address adjacency alone. This report uses stronger evidence:

- direct call-site facts from the executable bytes;
- 12-byte record-stride arithmetic;
- caller/callee clustering inside `FindFirstVisibleChild`;
- MSVC/Dinkumware sort algorithm shape;
- negative evidence against non-folder-tree callers;
- existing FolderTreePane file/class/type pages as documentation evidence, not authority.

IDA MCP was unavailable during this B009 pass, so live IDA results from current docs are treated as previous documentation evidence. Direct PE disassembly from `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe` was used as the fresh binary evidence source.

## Heuristic / Inference Reanalysis And Validation

### Issue: current helper name `FolderTreeDirectoryEntrySortPartition`

- Existing claim checked: the target is a "partition/merge helper" called from the sort wrapper.
- Fresh evidence checked: direct Capstone disassembly of `0x004b4fd0-0x004b5271`, full wrapper disassembly of `0x004b5280-0x004b5510`, and a direct `.text` rel32 scan for calls to `0x004b4fd0`.
- Best inference: rename/descriptively reinterpret as `FolderTreeDirectoryEntryAdjustHeap`, matching MSVC/Dinkumware `_Adjust_heap` over a 12-byte entry type.
- Evidence:
  - Wrapper path at `0x004b538d` runs only when range length is greater than `0x20` and the third wrapper argument, matching `std::_Sort`'s ideal/depth budget, is not positive.
  - Wrapper loops from `count / 2` toward zero, copy-constructs an element into a stack temp, and calls `0x004b4fd0(first, holeIndex, count, &temp, pred)`.
  - Wrapper second heap loop moves the first element to the shrinking end, copy-constructs the former end into a temp, and calls `0x004b4fd0(first, 0, newCount, &temp, pred)`.
  - Target body computes child indices `2 * hole + 1` / `2 * hole + 2`, selects a child by name comparison, copies selected child records down the heap, handles the single-child even-length case, bubbles the temp value upward against parents, and writes the temp to the final hole.
- Rejected alternative: "partition/merge helper." A partition helper would scan from both ends around a pivot or return partition boundaries. This target receives a hole index and length, walks binary-heap child/parent indices, and is only called from the heap fallback path.
- Rejected alternative: custom NexusTK hand-written heap helper. The surrounding wrapper exactly matches Dinkumware introsort control flow, so this is more likely compiler-instantiated STL algorithm support caused by a source `std::sort`-style call.
- Remaining blocker: no recovered symbol or debug type proves the original Dinkumware internal function name. Use descriptive `AdjustHeap` and record `_Adjust_heap` as inferred/template role, not recovered source name.

### Issue: helper signature and argument names

- Existing docs only list callees/callers, not the source signature.
- Best-supported signature:

```cpp
// descriptive, not final emitted source
static void FolderTreeDirectoryEntryAdjustHeap(
    FolderTreeDirectoryEntry* first,
    int holeIndex,
    int length,
    FolderTreeDirectoryEntry* value,
    FolderTreeDirectoryEntryNameLess pred);
```

- Evidence:
  - Target reads `[ebp+0x08]` as the record base pointer and forms addresses as `first + index * 12`.
  - Target reads `[ebp+0x0c]` into `ebx` as the current hole index.
  - Target reads `[ebp+0x10]` as heap length and computes `(length - 1) / 2`.
  - Target reads `[ebp+0x14]` as the temporary value pointer and writes that value into the final hole at `0x004b5233-0x004b525c`.
  - Wrapper passes a fifth argument at `[ebp+0x14]`, but the target body does not use `[ebp+0x18]`; this matches an optimized-away stateless predicate/template parameter.
- Rejected alternative: `a1/a2/a3/a4` placeholder names. The heap-control-flow evidence is strong enough to name the parameters descriptively.

### Issue: local record type and fields

- Existing docs model a 12-byte record as string handle `+0x00`, words `+0x04/+0x06`, and flag bytes `+0x08/+0x09`.
- Fresh construction/consumption evidence from `FindFirstVisibleChild`:
  - records are collected in a vector at stack slots `[ebp-0x16c, -0x168, -0x164]`;
  - `0x004b20fb` calls the vector insert/grow helper when capacity is exhausted;
  - `0x004b214e` calls the sort wrapper with begin/end/count/predicate-like argument;
  - after sorting, each record's string and four payload fields are copied into a 36-byte `FolderTreePane::TreeElem` stack record before insertion through `0x004b55e0`/`0x004b3d50`.
- Best-supported type name: `FolderTreeDirectoryEntry` or, in source-local form, `FolderTreePane::DirectoryEntry` / local `DirectoryEntry`.
- Best-supported fields for the sort helper page:
  - `+0x00`: `name`, confirmed because all sort comparisons normalize/copy this string and compare UTF-16 ranges.
  - `+0x04`: `payloadWord0`, copied transparently by vector/sort/swap/tree insertion; exact source semantic is not resolved by this target.
  - `+0x06`: `payloadWord1`, same.
  - `+0x08`: `payloadByte0`, copied transparently.
  - `+0x09`: `payloadByte1`, copied transparently.
  - `+0x0a-0x0b`: padding/reserved by 12-byte stride.
- Rejected alternative: naming the payload fields as final `row`, `depth`, `childrenEnumerated`, or `expanded` in this target. They are copied into the corresponding later `TreeElem` construction path, but the heap helper itself only proves transparent payload movement and string comparison. The class/type pages are better homes for final `TreeElem` semantics.

### Issue: owner and source placement

- Existing owner: [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md).
- Best inference: keep `CANONICAL_OWNER:0000JG` and `EMITTER_UIDS:0000JG`.
- Evidence:
  - Direct PE scan found exactly two direct calls to `0x004b4fd0`, at `0x004b5400` and `0x004b54c0`, both inside `0x004b5280`.
  - Existing docs and wrapper disassembly place `0x004b5280` as the directory-entry sort wrapper whose only non-recursive caller is `FindFirstVisibleChild` at `0x004b214e`.
  - `FindFirstVisibleChild` is in `FolderTreePaneCore` and is part of lazy child-directory enumeration for the filesystem tree control.
  - [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) is `89/85` and documents the scratch directory-entry vector/sort helpers as file-local support.
- Rejected alternatives:
  - [UID:00005A][FolderTreePane](by-class/FolderTreePane.md): weaker direct owner because this is compiler/STL support for a local source algorithm, not a method or class-owned member.
  - [UID:000157][FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md): aggregate is intentionally `RECONSTRUCTABLE:FALSE` and parent-blank.
  - `StringBase` / string helper ownership: the helper consumes string operations but is controlled by folder-tree sort reachability.
  - generic STL/runtime owner: useful for source-shape explanation, but the concrete instantiation is caused by FolderTreePane's local entry type/comparator and should be tracked in the FolderTreePane source context.

### Issue: final C++ / emitted-code readiness

- Gate status: current metadata has `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JG`, and average score `86`, so the current policy requires either a first-draft C++ recommendation or exact no-code proof.
- Best recommendation: no standalone function body should be entered for this target. Add a target-specific no-code proof and, if a generated-output marker is required, emit only a comment marker.
- No-code proof:
  - The body is an MSVC/Dinkumware STL algorithm instantiation (`_Adjust_heap`) generated from source-level sorting, not a likely handwritten NexusTK function.
  - The surrounding wrapper shape is the standard introsort driver: small ranges go to insertion sort, positive ideal/depth calls an unguarded partition helper and recurses, exhausted ideal/depth builds a heap and sorts it.
  - Hand-porting this helper would reconstruct compiler template internals as project source and would make the source less like a mid-2000s Visual C++ codebase.
  - Correct reconstructed source should express the owning `FindFirstVisibleChild` behavior as a local vector/list of directory entries sorted by name, letting the compiler regenerate heap fallback support if needed.
- Suggested formal code marker if the implementation checklist chooses to avoid a missing-code tracker entry:

```cpp
// Compiler-emitted MSVC/Dinkumware std::_Adjust_heap instantiation for FolderTreePane child-directory entry sorting.
// Recreated by the owning FolderTreePane child-directory sort expression; no standalone handwritten source.
```

### Issue: existing open questions and stale uncertainty

- "Exact source algorithm expression remains inferred" can be narrowed: the algorithm expression is not arbitrary unknown partitioning; it is a Dinkumware/MSVC introsort heap-adjust helper emitted for a source-level sort.
- "Partition/merge" should be moved to historical/stale assumption text or replaced. The true partition helper is likely [UID:00034B][0x004b4520-0x004b4fc5.FolderTreeDirectoryEntrySortCore](by-memory/0x004b4520-0x004b4fc5.FolderTreeDirectoryEntrySortCore.md), which calls the compare-swap median helper at `0x004b44c0`.
- Remaining uncertainty is limited to exact original source spelling: whether the original code used `std::sort`, a local wrapper around `std::sort`, or another Dinkumware-compatible sort call. That uncertainty should block a full function body, not ownership/source placement.

## Evidence Standards Used

- Direct executable evidence: PE section parse and Capstone disassembly from `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`.
- Direct xref evidence: manual scan of `.text` for direct `call rel32` targets to `0x004b4fd0`.
- Documentation evidence: current target and sibling by-memory pages, [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md), [UID:00005A][FolderTreePane](by-class/FolderTreePane.md), [UID:000157][FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md), [UID:00022E][FolderTreePaneVectorSupportHelpers](by-memory/0x004b5c40-0x004b5efc.FolderTreePaneVectorSupportHelpers.md), and the older B001 executed split report.
- Negative evidence: no direct `.text` calls outside `0x004b5280`; no target use of UI state or globals other than the security cookie; no evidence for an exported or class method.
- Limitation: live IDA MCP at `http://127.0.0.1:13337/mcp` was not reachable during this pass. The report therefore does not claim fresh live IDA MCP confirmation; it uses direct PE disassembly plus existing IDA-backed documentation.

## Fresh Binary Evidence

Fresh local command evidence:

- IDA MCP availability check failed with "Unable to connect to the remote server."
- Executable checked:
  - `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
  - `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
  - Both exist and have length `2679296`.
- PE parse:
  - image base `0x00400000`;
  - `.text` virtual range `0x00401000-0x0060cfdc` by section size;
  - `.rdata` starts at `0x0060e000`;
  - `.data` starts at `0x00670000`.
- Target bytes:
  - range `0x004b4fd0-0x004b5271`;
  - length `673` bytes (`0x2a1`);
  - md5 of target bytes `eebf4f657624fe43e8718883b3df7a9a`;
  - first 16 bytes `55 8b ec 6a ff 68 40 ef 5f 00 64 a1 00 00 00 00`;
  - last 16 bytes `f4 64 89 0d 00 00 00 00 59 5f 5e 5b 8b e5 5d c3`.

Key target disassembly facts:

- Prologue and EH/security-cookie setup at `0x004b4fd0-0x004b4ff2`.
- Base pointer argument loaded from `[ebp+0x08]`.
- Hole index loaded from `[ebp+0x0c]`.
- Heap length loaded from `[ebp+0x10]`.
- Temporary value pointer read from `[ebp+0x14]`.
- Better-child selection loop:
  - computes `2 * hole`;
  - compares records at child offsets `+0x0c` and `+0x18`;
  - calls `0x004b5c40`, `0x00583450`, and `0x005840f0` to normalize and compare names;
  - copies the selected child into the hole through `0x00582c60` plus payload field copies.
- Single-child case:
  - if the hole is the final internal node and length is even, copies the final child into the hole.
- Push-up phase:
  - compares the saved value with parent nodes;
  - copies parent records down while needed;
  - writes the saved value into the final hole at `0x004b5233-0x004b525c`.
- Epilogue at `0x004b525f-0x004b5270`.

Direct call scan:

- `0x004b5400 -> 0x004b4fd0`
- `0x004b54c0 -> 0x004b4fd0`
- No other direct `call rel32` target to `0x004b4fd0` was found in `.text`.

## Function / Child Inventory

| Range / Item | UID / Path | Role After Reanalysis | Reconstructable | Direct Parent | Score Recommendation | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004b4fd0-0x004b5271` | [UID:00034C][0x004b4fd0-0x004b5271.FolderTreeDirectoryEntrySortPartition](by-memory/0x004b4fd0-0x004b5271.FolderTreeDirectoryEntrySortPartition.md) | `FolderTreeDirectoryEntryAdjustHeap`, MSVC/Dinkumware heap-adjust/sift-down helper for sort fallback | `TRUE`, source-derived/template support | [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) | `88/91` | rename/rewrite recommended |
| `0x004b5280-0x004b5510` | [UID:00034D][0x004b5280-0x004b5510.FolderTreeDirectoryEntrySortWrapper](by-memory/0x004b5280-0x004b5510.FolderTreeDirectoryEntrySortWrapper.md) | introsort driver / `_Sort`-style wrapper | `TRUE` | [UID:0000JG] | no score change required by this report | support-doc update recommended |
| `0x004b4520-0x004b4fc5` | [UID:00034B][0x004b4520-0x004b4fc5.FolderTreeDirectoryEntrySortCore](by-memory/0x004b4520-0x004b4fc5.FolderTreeDirectoryEntrySortCore.md) | likely unguarded partition helper, not heap adjust | `TRUE` | [UID:0000JG] | no score change required by this report | future/source-quality rename candidate |
| `0x004b4240-0x004b44b3` | [UID:000349][0x004b4240-0x004b44b3.FolderTreeDirectoryEntryInsertionSort](by-memory/0x004b4240-0x004b44b3.FolderTreeDirectoryEntryInsertionSort.md) | insertion-sort helper for small ranges | `TRUE` | [UID:0000JG] | no score change required | existing name remains good |
| `0x004b44c0-0x004b451b` | [UID:00034A][0x004b44c0-0x004b451b.FolderTreeDirectoryEntryCompareSwap3](by-memory/0x004b44c0-0x004b451b.FolderTreeDirectoryEntryCompareSwap3.md) | median/order-three compare-swap helper | `TRUE` | [UID:0000JG] | no score change required | existing name remains acceptable |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004b5400` | direct call to `0x004b4fd0` from `0x004b5280` | `_Make_heap`-style loop: copy a parent entry into temp, adjust heap at that hole index over full count. |
| `0x004b54c0` | direct call to `0x004b4fd0` from `0x004b5280` | `_Sort_heap`-style loop: move root to shrinking end, adjust heap from hole `0` over reduced count. |
| `0x004b214e` | existing docs and fresh disassembly show call to `0x004b5280` from `FindFirstVisibleChild` | Sorts the collected child directory-entry vector before creating `TreeElem` children. |
| `0x004b20fb` | call to `0x004b3fb0` from `FindFirstVisibleChild` | Inserts/grows the same 12-byte entry vector before sorting. |
| `0x004b2238-0x004b2260`, `0x004b2391-0x004b23b9` | copies sorted entry payload into `TreeElem` stack records | Confirms the sort moves the whole 12-byte record, not only the string pointer. |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- [UID:00034C][0x004b4fd0-0x004b5271.FolderTreeDirectoryEntrySortPartition](by-memory/0x004b4fd0-0x004b5271.FolderTreeDirectoryEntrySortPartition.md) already has exact range, two callers in `0x004b5280`, callee set, 12-byte record movement, and owner route.
- [UID:00034D][0x004b5280-0x004b5510.FolderTreeDirectoryEntrySortWrapper](by-memory/0x004b5280-0x004b5510.FolderTreeDirectoryEntrySortWrapper.md) documents the wrapper's insertion-sort and recursive partition behavior. Fresh disassembly extends that to the exhausted-ideal heap fallback.
- [UID:000348][0x004b3fb0-0x004b4232.FolderTreeDirectoryEntryVectorInsertAt](by-memory/0x004b3fb0-0x004b4232.FolderTreeDirectoryEntryVectorInsertAt.md) documents the 12-byte vector shape and sole `FindFirstVisibleChild` caller.
- [UID:00022E][0x004b5c40-0x004b5efc.FolderTreePaneVectorSupportHelpers](by-memory/0x004b5c40-0x004b5efc.FolderTreePaneVectorSupportHelpers.md) documents `0x004b5c40` as the local normalization helper heavily used by sort/compare paths.
- [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) and [UID:00005A][FolderTreePane](by-class/FolderTreePane.md) document `FindFirstVisibleChild` and the child-directory scratch vector/sort helpers as FolderTreePane source contents.

Existing docs that are stale or incomplete:

- [UID:00034C] target title/current name and coverage row say "SortPartition"/"partition/merge helper." This should be corrected.
- [UID:00034B] `SortCore` is likely the partition helper based on its call shape and median compare-swap use. It does not need to be edited for this target unless the supervisor accepts broader support cleanup, but the target report should not continue calling `00034C` the partition helper.
- [UID:00034D] should mention the heap fallback path and Dinkumware introsort pattern.
- The sort-family pages currently treat the helper bodies as local source helpers. The more precise source-quality framing is "source-derived STL/template instantiation support for FolderTreePane's local sort expression."

Generated/coverage report state:

- `by-memory/-coverage-report.md` currently has a `00034C` child row under the `000157` split inventory with `85% : strong`.
- `project-level/-auto-completion-stats.md` lists `00034C` as `85/87` average `86.0`.
- This report recommends updating the by-memory coverage row only after the target/support docs are changed by an implementation callback.

## Ranked Ownership Analysis

### 1. [UID:0000JG] FolderTreePane.cpp

- Evidence for:
  - The target's only direct callers are inside `0x004b5280`.
  - `0x004b5280` is the child-directory sort wrapper reached from `FindFirstVisibleChild`.
  - `FindFirstVisibleChild` constructs the local 12-byte entry vector from filesystem enumeration, sorts it, and converts entries into `FolderTreePane::TreeElem` children.
  - The file page is a `89/85` parent and explicitly includes child-entry sort/vector helpers.
- Evidence against:
  - The target is likely compiler/STL template support, not handwritten `FolderTreePane.cpp` source.
  - The generic algorithm shape is Dinkumware, not unique UI business logic.
- Decision:
  - Keep [UID:0000JG] as canonical owner and emitter because the concrete instantiation is source-derived from FolderTreePane's local sort. Document that it should be rebuilt through the source-level sort expression, not a standalone function.

### 2. [UID:00005A] FolderTreePane class

- Evidence for:
  - `FindFirstVisibleChild` is a class method, and the sorted records become `FolderTreePane::TreeElem` nodes.
- Evidence against:
  - The helper is not a method, does not consume `this`, and has no class-vtable/type ownership.
  - The direct source construct is a file-local temporary vector sort, not class layout or a virtual/member method.
- Decision:
  - Reject as direct canonical owner. Use class docs as support evidence only.

### 3. Generic STL/Dinkumware runtime/template owner

- Evidence for:
  - Algorithm matches Dinkumware `std::_Adjust_heap` and belongs to compiler-instantiated algorithm machinery.
- Evidence against:
  - The concrete function is specialized to the FolderTreePane entry record/comparator and only reached from FolderTreePane's local sort.
  - There is no existing focused by-type template owner for this exact sort instantiation, and creating one for this one helper would not improve source routing.
- Decision:
  - Use as source-shape/rebuild classification, not as canonical owner. Keep FolderTreePane route and document no-code policy.

### 4. [UID:000157] FolderTreePaneTreeAndSortHelpers aggregate

- Evidence for:
  - It contains the target as an exact child row.
- Evidence against:
  - The aggregate is `RECONSTRUCTABLE:FALSE`, parent-blank, and exists only as a split inventory across mixed child owners and support types.
- Decision:
  - Reject as direct parent/emitter.

## Negative Evidence Summary

- The target is not the partition helper: no two-ended scan, no partition-boundary return, and no pivot-pair output.
- The target has no ordinary direct callers outside `0x004b5280`; fresh `.text` rel32 scan found only `0x004b5400` and `0x004b54c0`.
- The target has no direct dependency on `FolderTreePane::this`, vtables, UI state, filesystem APIs, or folder icon resources.
- The fifth predicate argument is optimized away in the target, matching an inlined/stateless comparator template rather than a source callback.
- Address locality alone is not the ownership basis; reachability through `FindFirstVisibleChild` and concrete entry-record usage are the ownership basis.

## First-Draft C++ / Exact No-Code Proof

The target currently meets the minimum code-entry gate, but a standalone function body should not be entered.

Exact no-code proof:

1. `0x004b5280` matches MSVC/Dinkumware `std::_Sort`: range length is computed by dividing pointer deltas by `12`, small ranges at or below `0x20` call insertion sort, positive ideal/depth calls a partition helper and recurses/tail-loops, and non-positive ideal/depth falls back to heap build/sort.
2. `0x004b4fd0` matches `_Adjust_heap`: it receives `(first, holeIndex, length, value, pred)`, walks child indices in a binary heap, handles the one-child case, bubbles the saved value upward, and writes it back to the final hole.
3. This body is compiler-instantiated STL/template support generated from a source-level sort expression. Emitting it as a handwritten function would preserve decompiler/compiler internals instead of plausible original mid-2000s C++ source.
4. The behavior should be reconstructed in the owning source by sorting the collected child directory entries, not by adding this internal helper as project-authored code.

Recommended formal C++ handling:

- Preferred: leave the target's formal C++ block function-body-free and document the no-code proof in the page.
- If the implementation workflow requires a nonblank emitted marker for an eligible emitter, use only:

```cpp
// Compiler-emitted MSVC/Dinkumware std::_Adjust_heap instantiation for FolderTreePane child-directory entry sorting.
// Recreated by the owning FolderTreePane child-directory sort expression; no standalone handwritten source.
```

Do not emit a full helper body in this target.

## Exact Supervisor-Owned Coverage Row Text

Current row location: under [UID:000157][0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md) in `by-memory/-coverage-report.md`.

Replace the current `00034C` row with this text after the target rename/support update is accepted and implemented:

```text
        - [UID:00034C][0x004b4fd0-0x004b5271.FolderTreeDirectoryEntryAdjustHeap](by-memory/0x004b4fd0-0x004b5271.FolderTreeDirectoryEntryAdjustHeap.md) 0x004b4fd0-0x004b5271 | heap adjust helper | FolderTreeDirectoryEntryAdjustHeap : reconstructable : 88% : very strong : Assigned to [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md); MSVC/Dinkumware `std::sort` heap-fallback `_Adjust_heap`-style helper for 12-byte child directory-entry records, reached only from the sort wrapper's exhausted-depth heap path and reconstructed through the owning FolderTreePane child-directory sort expression rather than as a handwritten partition helper.
```

If the supervisor chooses not to rename the file immediately, use this temporary row instead:

```text
        - [UID:00034C][0x004b4fd0-0x004b5271.FolderTreeDirectoryEntrySortPartition](by-memory/0x004b4fd0-0x004b5271.FolderTreeDirectoryEntrySortPartition.md) 0x004b4fd0-0x004b5271 | heap adjust helper | FolderTreeDirectoryEntryAdjustHeap : reconstructable : 88% : very strong : Assigned to [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md); current filename is stale, but source-quality reanalysis identifies this as the MSVC/Dinkumware `std::sort` heap-fallback `_Adjust_heap`-style helper for 12-byte child directory-entry records, not a partition/merge helper.
```

## Target / Support Implementation Checklist

Target doc [UID:00034C]:

- Rename file to `0x004b4fd0-0x004b5271.FolderTreeDirectoryEntryAdjustHeap.md`.
- Change title/current name from `FolderTreeDirectoryEntrySortPartition` to `FolderTreeDirectoryEntryAdjustHeap`.
- Update status/entity kind to "heap-adjust/sift-down helper for FolderTreePane child-directory entry sorting; MSVC/Dinkumware `std::sort` fallback support."
- Keep `CANONICAL_OWNER:0000JG`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000JG`.
- Recommended score: `COMPLETION:88`, `CONFIDENCE:91`.
- Add a historical/stale-assumption note explaining that the old partition/merge name was rejected because direct disassembly shows heap child/parent index adjustment.
- Add PE evidence from this report: target byte length/md5, direct calls at `0x004b5400` and `0x004b54c0`, helper signature, child-selection loop, single-child case, push-up loop, and final writeback.
- Add exact no-code proof and either keep the formal C++ block blank or insert only the two-line comment marker shown above if the supervisor wants a nonblank emitter marker.
- Cross-reference [UID:00034D], [UID:00034B], [UID:000349], [UID:000348], [UID:000343], and [UID:00022E].

Support doc [UID:00034D] `0x004b5280-0x004b5510.FolderTreeDirectoryEntrySortWrapper.md`:

- Add that the wrapper matches a MSVC/Dinkumware `_Sort`/introsort driver over 12-byte records.
- Document the exhausted-ideal/depth path:
  - first loop builds a heap by calling [UID:00034C] for each parent hole from `count / 2 - 1` downward;
  - second loop performs sort-heap behavior by moving the root to the shrinking end and calling [UID:00034C] with hole `0`.
- Keep the existing owner/emitter unless a broader support source-quality pass decides to rename it to `FolderTreeDirectoryEntryIntroSort`.

Support doc [UID:00034B] `0x004b4520-0x004b4fc5.FolderTreeDirectoryEntrySortCore.md`:

- Add a caveat that source-quality reanalysis of [UID:00034C] indicates `00034B` is the better candidate for the partition helper.
- Future rename candidate: `FolderTreeDirectoryEntryUnguardedPartition` or `FolderTreeDirectoryEntryPartition`.
- Do not force this rename from this report alone unless the implementation callback includes broader sort-family cleanup.

Support doc [UID:000157] aggregate:

- Update the child row/description for [UID:00034C] from "sort partition/merge helper" to "heap adjust helper."
- Keep aggregate `RECONSTRUCTABLE:FALSE`, parent blank, and inventory role unchanged.

Support docs [UID:0000JG] and [UID:00005A]:

- No owner/source-placement change needed.
- Optional source-quality note: the child-directory scratch sort appears to compile through MSVC/Dinkumware introsort helpers; final FolderTreePane source should prefer a local `std::sort` or equivalent source-level expression over emitted internal helper bodies.

Coverage:

- Do not let B009 edit `by-memory/-coverage-report.md`.
- Supervisor should apply the exact replacement row from this report after target/support docs are updated.

Validation expected after implementation:

- `python .\tools\validator.py --mode file --file .\by-memory\0x004b4fd0-0x004b5271.FolderTreeDirectoryEntryAdjustHeap.md --apply --queue-timeout 240`
- If support docs are edited:
  - `python .\tools\validator.py --mode file --file .\by-memory\0x004b5280-0x004b5510.FolderTreeDirectoryEntrySortWrapper.md --apply --queue-timeout 240`
  - `python .\tools\validator.py --mode file --file .\by-memory\0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md --apply --queue-timeout 240`
  - run the target again after rename if the validator updates UID path annotations.

## Final Recommendation

- Exact changes recommended:
  - Rename/reclassify target as `FolderTreeDirectoryEntryAdjustHeap`.
  - Raise target to `88/91`.
  - Preserve owner/emitter route `0000JG`.
  - Add exact no-code proof; do not emit a full C++ function body.
  - Update coverage row text under the supervisor-owned coverage report.
- Items left unchanged:
  - No split required.
  - No new owner file required.
  - No class/type/global owner reroute required.
  - No by-memory aggregate reclassification required.
- Future work outside this target:
  - A broader sort-family source-quality pass should consider renaming [UID:00034B] from `SortCore` to an unguarded partition name and [UID:00034D] to an introsort driver name if the supervisor wants the entire cluster source-shaped.

## Follow-Up Actions

- Supervisor action: review this report; if accepted, send B009 an implementation checklist that applies the target rename/rewrite and the accepted support updates under normal leases; apply the supervisor-owned coverage row after implementation.
- A-agent action: none required before B009 implementation.
- B009 future action: if assigned implementation, lease the target/support docs, make the accepted changes, run scoped validators, and report exact validator outputs. Do not edit `by-memory/-coverage-report.md`.

## Confidence

- Recommendation confidence: high.
- Score confidence: high enough for `88/91`, not high enough for 95+ because live IDA MCP was unavailable and original debug/source names are not recovered.
- Remaining uncertainty: exact original source line may have been `std::sort`, a wrapper around `std::sort`, or equivalent Dinkumware algorithm use; this does not affect the target's owner or heap-adjust role, but it blocks a full standalone emitted C++ body.

## Validator Results

- No validator was run because this was a report-only pass and no by-* documentation was edited.
- Fresh local evidence commands run:
  - IDA MCP tools/list PowerShell check: failed to connect.
  - PE existence checks for both documented executable paths: both exist.
  - Capstone PE-disassembly script for target, wrapper, call-scan, and `FindFirstVisibleChild` record construction/consumption.

## Changed Files

- Created:
  - `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B009\research\00034C-FolderTreeDirectoryEntrySortPartition-source-quality.md`
- Modified:
  - none outside this report.
- Renamed:
  - none.
- Moved to executed:
  - none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000004165","destination_path":"executed-b-agent-research/B009/00034C-FolderTreeDirectoryEntrySortPartition-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:33","uid":"00034C"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
