** TARGET-REPORT-UID:000344 **
** AUTHOR-AGENT-ID:B015 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# [UID:000344] FolderTreeContentDimensionsTraversal Empty-Emitter Source-Quality Report

## Report-Only Scope

- Agent: B015
- Assignment: `B015-report-000344-FolderTreeContentDimensionsTraversal-empty-emitter-source-quality-20260628`
- Target: [UID:000344][0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal](../../../../../by-memory/0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal.md)
- Current target state: `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000JG`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JG`, blank `EMITTER_POSITION_OPTIONAL`, and blank formal `RECONSTRUCTION_CPP CODE`.
- Original generated symptom: `auto-generated/NexusTK/ui/controls/FolderTreePane.cpp` emitted [UID:000344] as `Empty Emitter Marker`.
- Implementation result: validator command `000000000132` refreshed generated output at `2026-06-28T22:50:23-04:00`; [UID:000344] now emits the accepted `Tree<FolderTreePane::TreeElem>::TraverseContentDimensions` body at generated lines `258-309`.
- Report-only restrictions honored: no by-* documentation edits, no generated-file edits, no project-level edits, no manual `-coverage-report.md` edits, no tool-state edits, no IDA database writes, no leases, and no subagents.

## Disposition

[UID:000344] should not remain an empty emitter. It is a source-shaped, reconstructable helper with a live owner/emitter route through [UID:0000JG][FolderTreePane](../../../../../by-file/FolderTreePane.md), and current MCP evidence resolves the behavior well enough for formal first-draft C++.

Recommended implementation disposition:

- Keep `CANONICAL_OWNER:0000JG`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `EMITTER_UIDS:0000JG`.
- Keep `EMITTER_POSITION_OPTIONAL:` blank.
- Raise target scores from `86/88` to `90/91`.
- Replace the blank formal C++ block with the exact C++ in the "Formal C++ To Insert" section.
- Update support docs at report-level detail, especially [UID:0000JG][FolderTreePane](../../../../../by-file/FolderTreePane.md), [UID:00005A][FolderTreePane class](../../../../../by-class/FolderTreePane.md), [UID:000155][FolderTreePaneCore](../../../../../by-memory/0x004b1b90-0x004b32c9.FolderTreePaneCore.md), [UID:000157][FolderTreePaneTreeAndSortHelpers](../../../../../by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md), [UID:0001UJ][FolderTreePane::TreeElem](../../../../../by-type/by-struct/FolderTreePane__TreeElem.md), and the local tree-template support pages.

This is not a covered-by/no-code marker case. The target has its own ordinary function body, one ordinary caller, a complete function boundary, and source-level behavior that is not already emitted by a parent declaration. It is also not a split/container repair: the range exactly matches one IDA function and is already a child of the correct non-emitting aggregate [UID:000157].

## Current MCP And Generated Evidence

Live IDA MCP was available for this report. `idb_list` command `201` reported one active session, `supervisor_20260628_resume`, for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, active worker PID `5124`, created `2026-06-28T15:10:19.304678`, last accessed `2026-06-28T19:52:09.653213`. `server_health` command `202` returned `status:ok`, module `NexusTK.exe`, input binary `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, and strings cache size `2067`.

Earlier in the same MCP-backed pass, `server_health` command `115` also returned `status:ok` for the same IDB and confirmed Hex-Rays and strings cache readiness. The generated source file read during this report had validator header `validator-command-id: 000000005324`, `validator-refreshed-at: 2026-06-28T19:53:27-04:00`, and source by-file UID `0000JG`. That generated file still contained:

```text
// UID:000344 | by-memory\0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal.md | Completion:86 | Confidence:88 | Empty Emitter Marker
```

`auto-generated/-ag-research-tracker.md` listed [UID:000344] as `86/88`, average `87.0`, reconstructable `true`, and reports `0`. This assignment supplies the missing source-quality report for that zero-report empty-emitter state.

### 2026-06-28 MCP Restore Refresh

Per supervisor resume, B015 reran a read-only MCP evidence pass instead of relying only on the earlier `supervisor_20260628_resume` session. JSON-RPC `idb_list` id `3` returned the current active IDB session `agent_b009_0002my_20260628` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, created `2026-06-28T21:51:27.830021`, owned/adopted by the worker, `is_analyzing:false`, with PID and worker PID `2412`. B015 used that current active session for the refreshed evidence below.

`server_health` id `301` returned `status:ok`, module `NexusTK.exe`, input binary `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, and strings cache size `2067`. `tools/list` confirmed the read-only analysis tools used for this pass. It did not expose a `callers` tool; attempted `callers` id `304` failed with `Method 'callers' not found`, so current caller proof uses `xrefs_to` id `303` and `analyze_function` id `306`. No mutating MCP tools were used.

The generated source file inspected during this restore refresh had validator header `validator-command-id: 000000000025`, `validator-refreshed-at: 2026-06-28T21:57:41-04:00`, and source by-file UID `0000JG`. It still contained the same empty-emitter symptom for [UID:000344]:

```text
// UID:000344 | by-memory\0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal.md | Completion:86 | Confidence:88 | Empty Emitter Marker
```

## Function Boundary And Route

MCP `lookup_funcs` command `101` confirmed:

| Address | Function | Size |
| --- | --- | --- |
| `0x004b3400` | `sub_4B3400` | `0x245` bytes, decimal `581` |
| `0x004b3645` | no function start | exclusive end of target range |
| `0x004b2f60` | `sub_4B2F60` | `0xa6` bytes, decimal `166` |
| `0x004b3010` | `sub_4B3010` | `0x74` bytes, decimal `116` |
| `0x004b3650` | `sub_4B3650` | `0x1f8` bytes, decimal `504` |
| `0x004b3850` | `sub_4B3850` | `0x292` bytes, decimal `658` |
| `0x004b3af0` | `sub_4B3AF0` | `0x251` bytes, decimal `593` |
| `0x004b5810` | `sub_4B5810` | `0x1c5` bytes, decimal `453` |

Byte evidence from MCP `get_bytes` command `122` confirmed four `0xcc` bytes before `0x004b3400`, a normal prologue at `0x004b3400`, a `ret 8` endpoint before `0x004b3645`, eleven `0xcc` bytes after `0x004b3645`, and the next function start at `0x004b3650`. The target is not a partial range or an aggregate child with missing boundaries.

MCP `xrefs_to` command `102` reported exactly one ordinary code xref to `0x004b3400`: callsite `0x004b2fbf` inside `sub_4B2F60`, the documented [UID:000155] `FolderTreePane::CalculateContentDimensions` path. It reported no xrefs to `0x004b3645`. Negative pointer/ref checks also support the current route:

- `find code_ref` command `111` found the same single code ref to `0x004b3400` and none to `0x004b3645`.
- `find data_ref` command `112` found no data refs to either boundary.
- `find immediate` command `113` found no immediate hits for decimal `4928512` (`0x004b3400`) or `4929093` (`0x004b3645`).
- `find_bytes` command `114` found no VA/RVA pointer encodings for the start or end.

The restore refresh repeated the boundary and route checks on session `agent_b009_0002my_20260628`: `lookup_funcs` id `302` returned `sub_4B3400` at `0x004b3400` with size `0x245` and no function at `0x004b3645`; `xrefs_to` id `303` again found only callsite `0x004b2fbf` to the target and no xrefs to the exclusive end; `get_bytes` id `307` again confirmed `int3` padding before the target, `ret 8` before `0x004b3645`, and padding before the next function at `0x004b3650`; `find` ids `308` through `310` and `find_bytes` id `311` again found no boundary data references, immediate references, or pointer encodings.

This helper is reached through the FolderTreePane source route only. The previous B001 and B008 reports were right to keep this range with [UID:0000JG] rather than `LObject`, `StringBase`, GrafPort, a standalone traversal class, or generated helper-owner pollution.

## Caller Evidence

MCP `decompile` command `108` for `0x004b2f60` shows `FolderTreePane::CalculateContentDimensions` builds a temporary `TreeItor<FolderTreePane::TreeElem>` and a three-field context on the stack, then calls the target:

- The temporary iterator stores vtable `0x0061a510`, tree pointer `this + 76`, and current index `0`.
- `this + 76` is dword-index form of byte offset `0x130`, decimal `304`, matching the accepted `m_tree` field on [UID:00005A].
- The context locals are `FolderTreePane *pane`, row count initialized to `0`, and maximum width initialized to `0`.
- The call at `0x004b2fbf` passes the tree receiver, the iterator address, and the context address.
- After the helper returns, the caller writes content width from `maxWidth` plus horizontal scroll/bounds terms and content height from `16 * rowCount - 4` plus vertical scroll/bounds terms.

This proves the target is the retained traversal body behind `CalculateContentDimensions`, not a generic tree method called broadly by other controls. The helper must be documented as file-local/project-template support under `FolderTreePane.cpp`, while the public source-facing method remains `FolderTreePane::CalculateContentDimensions`.

## Target Behavior From Hex-Rays

MCP `decompile` commands `107` and `123` for `0x004b3400` show the target as `void __thiscall sub_4B3400(_DWORD *this, int a2, int a3)`. The receiver is the concrete `Tree<FolderTreePane::TreeElem> *`, not `FolderTreePane *`. The first explicit argument is a `TreeItor<FolderTreePane::TreeElem> *`; its current index is read from `a2 + 8`. The second explicit argument is the three-field content-dimension context used by the caller.

The body creates a pending-node container, seeds it with the iterator's current node index, and then repeatedly processes nodes. The container shape in the optimized binary is Dinkumware/STL deque-like segmented storage: it allocates 8-byte blocks through `operator new`, grows through `sub_43E0B0`, and destroys through `sub_439E00`. Source-facing C++ should express this as `std::deque<int>` used with `push_back`, `back`, and `pop_back`. That preserves the observed LIFO traversal without forcing compiler-specific deque internals into source documentation.

For each node index popped from the pending container, the helper:

- Resolves the `TreeElem` record through the tree storage.
- Walks the `parentIndex` chain at `TreeElem +0x00` until `-1`, counting parent links to compute visible depth.
- Writes the computed depth to `TreeElem +0x1a`, decimal `26`.
- Writes the current row count from context offset `+0x04` to `TreeElem +0x18`, decimal `24`.
- Reads the node name from `TreeElem +0x14`, decimal `20`, converts it to a null-terminated UTF-16 pointer through `0x00584540`, then calls `0x004baa70`.
- Uses accepted GrafPort text-helper naming for `0x004baa70`: `GrafPort::GetTextWidth(const wchar_t *text)`.
- Computes row width as `GetTextWidth(node.name) + 16 * (depth + 1)`.
- Updates context offset `+0x08` when that row width exceeds the current maximum.
- Increments context row count at offset `+0x04`.
- If `TreeElem::expanded` at `+0x1d`, decimal `29`, is true and `lastChildIndex` at `+0x08`, decimal `8`, is not `-1`, pushes child indices starting from `lastChildIndex` and following `previousSiblingIndex` at `+0x0c`, decimal `12`, until `-1`.

Because the pending container is popped from the back, pushing children from `lastChildIndex` backward through `previousSiblingIndex` makes the visible traversal process first children before later siblings. This is a behavior detail that should be preserved in the target and support docs.

No code in this target reads `TreeElem +0x20` (`isHidden` / visible traversal skip flag). That is negative evidence against folding this body into `MoveToNextVisibleSibling` behavior or documenting a hidden-node skip here. The helper relies on the tree's child/sibling links and each node's `expanded` flag.

MCP `callees` command `121` reported target callees `operator new` at `0x005c74f6`, container seed/helper `0x004a88e0`, SimpleUString/wide-pointer helper `0x00584540`, GrafPort text width overload `0x004baa70`, deque grow helper `0x0043e0b0`, and deque destroy helper `0x00439e00`. It reported that the caller `0x004b2f60` calls only the target. `analyze_function` command `110` reported size `581`, 35 basic blocks, and cyclomatic complexity `13`.

The restore refresh reconfirmed this behavior: `callees` id `305` returned the same target callees, `analyze_function` id `306` reported `sub_4B3400` as a 581-byte function with 35 basic blocks, cyclomatic complexity `13`, and caller `sub_4B2F60`, and full decompile ids `315` through `317` reconfirmed the target, caller, and consumer data flow summarized in this report.

## Consumer Evidence

MCP `decompile` command `109` for `0x004b3010` shows the accepted `GetNodeBounds` helper consumes exactly the row/depth values written by this target:

- It reads `TreeElem +0x1a` (`depth`) to compute the left edge as `16 * depth`.
- It reads `TreeElem +0x18` (`rowIndex`) to compute top and bottom as `16 * rowIndex` and `top + 16`.
- It measures the same node name through `0x004baa70` and sets the right edge as `left + textWidth + 16`.

This cross-check confirms that [UID:000344] is the layout pass that prepares per-node row/depth metadata for bounds, paint, hit-test, and selection calculations. The helper is not dead code and not merely compiler-generated container glue.

## Existing Documentation Reconciliation

The target page already contains most of the right behavioral facts: owner [UID:0000JG], only ordinary caller `CalculateContentDimensions`, row/depth writes, name-width measurement, content-width/row-count updates, and expanded-child traversal. The stale part is the no-C++ decision. Current evidence resolves the blocker well enough to emit first-draft C++.

Prior B001 research created this exact child page from the larger [UID:000157] helper aggregate and assigned it to [UID:0000JG] with `86/88`. Prior B008 research kept [UID:000344], [UID:000345], [UID:000346], [UID:000347], and [UID:00034H] as file-local FolderTreePane helpers rather than public class APIs. Those ownership and split conclusions remain valid. The correction is narrower: [UID:000344] now has enough function-level evidence for formal C++, while its sibling traversal helpers may remain separate empty-emitter decisions until individually reviewed.

[UID:000157] should remain `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, and non-emitting. It is a container/inventory page, not the place to emit this traversal body. Its child row for [UID:000344] should be updated to say the content-dimension traversal is now first-draft C++ ready and emits through [UID:0000JG].

## Source-Placement Decision

Best current source placement is `NexusTK/ui/controls/FolderTreePane.cpp` through [UID:0000JG]. The helper should be represented as a concrete `Tree<FolderTreePane::TreeElem>` specialization/helper used by `FolderTreePane::CalculateContentDimensions`.

The function is not a public `FolderTreePane` method because the binary receiver is the tree object, and only the caller supplies the owning pane pointer through the context. It is also not a generic shared `Tree<T>` implementation with broad ownership proof. Current docs already accept likely local/shared template support, but no scored shared `Tree.h` or global tree-template by-file route supersedes [UID:0000JG]. Emitting this body in `FolderTreePane.cpp` is consistent with existing generated `TreeItor<FolderTreePane::TreeElem>` specializations that already use `m_tree->m_storage[...]` in the same source file.

The source-facing text-measure call should use inherited/project vocabulary `GetTextWidth`, backed by accepted [UID:00016C] GrafPort documentation for `0x004baa70` as `GrafPort::GetTextWidth(const wchar_t *text)`. In this target the call is source-facing as `context->pane->GetTextWidth(node.name.c_str())`: the context pane supplies the inherited GrafPort receiver state, while the binary helper is the null-terminated overload.

## Heuristic / Inference Reanalysis And Validation

| Issue | Current decision | Evidence / rejected alternatives | Score and C++ impact |
| --- | --- | --- | --- |
| Empty-emitter symptom | Emit formal first-draft C++ for [UID:000344]. | The target has an ordinary body, complete function boundary, sole caller, concrete consumer of written fields, and no owner-route defect. Covered-by/no-code and marker-only treatments are rejected. | Resolves the blank-emitter blocker and supports raising from `86/88` to `90/91`. |
| Direct owner/emitter | Keep [UID:0000JG] as canonical owner and sole emitter. | Sole callsite is from `FolderTreePane::CalculateContentDimensions`; receiver is `Tree<FolderTreePane::TreeElem> *`, while the context carries the owning pane. Direct ownership by [UID:00005A], GrafPort, runtime/STL, `LObject`, or a generic tree page is not supported. | No ownership repair is needed; the generated marker exists because formal C++ is blank. |
| Source-facing helper name | Use `Tree<FolderTreePane::TreeElem>::TraverseContentDimensions` as the documented source-facing helper. | `type_query` id `312`, `entity_query` id `313`, and `search_text` id `314` found no original symbol/type/name proof for `FolderTree`, `ContentDimensions`, or `TreeItor` in the target range. The name is inferred from behavior and receiver. | Name inference caps confidence below high-90s but is not a blocker for first-draft source. |
| Context struct | Use `FolderTreeContentDimensionsContext { pane, rowCount, maxWidth }`. | Caller decompile initializes exactly pane/0/0 and passes the stack address; target reads offsets `+0x00`, `+0x04`, and `+0x08` with those roles. | Exact field order is strong enough for formal C++; struct name remains source-facing. |
| Pending container | Use `std::deque<int>` with `push_back`, `back`, and `pop_back`. | Binary shows deque-like segmented container machinery and LIFO use. Raw Dinkumware internals would be compiler noise; `std::stack<int>` is source-equivalent but hides observed deque operations. | `std::deque<int>` is the best evidence-preserving source form. |
| `TreeElem` fields | Use accepted fields `parentIndex`, `lastChildIndex`, `previousSiblingIndex`, `name`, `rowIndex`, `depth`, and `expanded`. | Target reads/writes exact offsets for these fields. It does not read `isHidden` at `+0x20`, so hidden-node skip behavior must not be imported into this helper. | Field-name inference is acceptable because the support docs already carry these roles. |
| Range/split state | Do not split or merge the range. | `lookup_funcs`, byte padding, `xrefs_to`, and negative pointer/reference searches confirm `0x004b3400-0x004b3645` is exactly one function. | No split/range repair required. |
| Remaining score blockers | Historical exact source names and shared-template header factoring remain unresolved. | No original symbol/type catalog proof was recovered; no scored shared `Tree.h` route supersedes [UID:0000JG]. | These residual uncertainties cap the recommendation at `90/91`, not below emit threshold. |

## Inference Claim Ledger

| Claim | Confidence | Evidence | Counter-evidence checked | Remaining uncertainty |
| --- | --- | --- | --- | --- |
| [UID:000344] is source-authored FolderTreePane helper code emitted through [UID:0000JG]. | High | Sole caller `0x004b2f60`, context pane pointer, tree receiver at the FolderTreePane tree field, generated by-file route already `0000JG`. | Boundary refs, pointer encodings, broad owner candidates, and aggregate-owner alternatives checked. | None material for source placement. |
| Formal first-draft C++ is appropriate now. | Strong | Target behavior, caller context, consumer use of row/depth, callee set, and generated empty marker are all current and consistent. | No-code marker, owner repair, split repair, and raw compiler-helper interpretations rejected. | Exact historical helper/context names remain inferred. |
| The target has no hidden-node skip. | Confirmed for this function | Decompile reads `expanded` and child/sibling indices, writes row/depth, and never reads `TreeElem +0x20`. | Compared against nearby visible traversal semantics and consumer bounds behavior. | Other sibling traversal helpers may use hidden/visible rules, but they are separate targets. |
| `std::deque<int>` is the right source-level pending container. | Strong | Observed segmented-container allocation/grow/destroy and explicit back-pop/push-back LIFO behavior. | Raw Dinkumware internals and `std::stack<int>` considered. | Original source may have used an alias/wrapper, but semantics and emitted code remain accurate. |

## Open Questions With Attempted Resolution

- Original helper/context names: searched current IDB type/name/text surfaces with `type_query` id `312`, `entity_query` id `313`, and `search_text` id `314`; no original proof was recovered. Use inferred source-facing names and keep the confidence cap.
- Shared template header factoring: support docs allow local/shared `Tree<FolderTreePane::TreeElem>` template support, but no scored shared-header by-file route is stronger than [UID:0000JG]. Emit via `FolderTreePane.cpp` for this callback.
- Queue abstraction: decompile proves deque-like segmented storage and LIFO operations. Use `std::deque<int>` instead of compiler internals or `std::stack<int>`.
- Hidden/visible filtering: this target does not read the `isHidden` slot, so do not document or emit hidden-node skipping inside [UID:000344].

## Formal C++ To Insert

Insert this as the exact formal `RECONSTRUCTION_CPP CODE` content on [UID:000344]. Do not place it only in prose, examples, or a side section.

```cpp
struct FolderTreeContentDimensionsContext
{
    FolderTreePane *pane;
    int rowCount;
    int maxWidth;
};

template <>
void Tree<FolderTreePane::TreeElem>::TraverseContentDimensions(
    TreeItor<FolderTreePane::TreeElem> *start,
    FolderTreeContentDimensionsContext *context)
{
    std::deque<int> pending;
    pending.push_back(start->GetIndex());

    while (!pending.empty())
    {
        const int nodeIndex = pending.back();
        pending.pop_back();

        FolderTreePane::TreeElem &node = m_storage[nodeIndex];

        int depth = 0;
        for (int parentIndex = node.parentIndex; parentIndex != -1;
             parentIndex = m_storage[parentIndex].parentIndex)
        {
            ++depth;
        }

        node.depth = static_cast<short>(depth);
        node.rowIndex = static_cast<short>(context->rowCount);

        const int rowWidth =
            context->pane->GetTextWidth(node.name.c_str()) + (16 * (depth + 1));
        if (context->maxWidth < rowWidth)
        {
            context->maxWidth = rowWidth;
        }

        ++context->rowCount;

        if (node.expanded && node.lastChildIndex != -1)
        {
            for (int childIndex = node.lastChildIndex; childIndex != -1;
                 childIndex = m_storage[childIndex].previousSiblingIndex)
            {
                pending.push_back(childIndex);
            }
        }
    }
}
```

Notes for implementer:

- `std::deque<int>` is the source-facing form chosen for the observed compiler deque/segmented-container machinery. `std::stack<int>` is a possible source abstraction, but `std::deque<int>` with explicit back/pop_back/push_back better records the current binary evidence.
- `TraverseContentDimensions` is a source-facing helper name, not a proven original symbol. It is preferable to keeping `FolderTreeContentDimensionsTraversal` in emitted C++ because the binary receiver is `Tree<FolderTreePane::TreeElem> *`.
- `FolderTreeContentDimensionsContext` is a source-facing name for the caller's stack context. It has exact field order evidence: `pane`, `rowCount`, `maxWidth`.
- `node.name.c_str()` is source-facing shorthand for the accepted local string storage read at `TreeElem +0x14` followed by the `0x00584540` pointer helper.

## Metadata And Score Recommendation

Recommended target header after implementation:

```text
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Completion should rise because the page can now carry a formal first-draft helper body, exact caller/callee route, exact row/depth/name-width behavior, and exact split/source placement. Confidence should rise because live MCP reconfirmed the function boundary, sole caller, callee set, consumer of row/depth fields, no pointer/data-reference surprises, and current generated empty marker. It should remain below final/high-90s because the exact historical source names for `TraverseContentDimensions`, `FolderTreeContentDimensionsContext`, and the local tree-template factoring are inferred, and no IDA type catalog entry or original source symbol was recovered. MCP `type_query` command `130` found no local UDT/original type proof for `*FolderTree*`, `*Content*Dimension*`, or `*TreeItor*`; `entity_query` command `131` found no names in `0x004b3300-0x004b3700`; `search_text` command `132` found no recovered text label for `ContentDimensions` in the same range.

The 2026-06-28 restore refresh using current session `agent_b009_0002my_20260628` confirmed the same recommendation. At report-acceptance time the generated output still showed the stale `86/88` empty-emitter marker, and the current MCP evidence did not introduce any new owner, range, no-code, or source-placement blocker. The implementation callback resolved that stale generated state with validator command `000000000132`.

## Required Support-Doc Updates For Callback

The implementation callback should incorporate this report at report-level detail, not as a short summary.

Recommended target update:

- [UID:000344][0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal](../../../../../by-memory/0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal.md): update scores to `90/91`; keep owner/emitter route; add the formal C++; replace the stale "Do not emit final C++ yet" language with a source-quality implementation note that records the receiver as `Tree<FolderTreePane::TreeElem> *`, explicit arguments as iterator/context, the `std::deque<int>` pending list, parent-depth walk, `rowIndex` and `depth` writes, `GetTextWidth` plus indent width calculation, row-count/max-width updates, expanded-child push order, and negative `isHidden` evidence.

Recommended support updates:

- [UID:0000JG][FolderTreePane](../../../../../by-file/FolderTreePane.md): add a B015 source-quality note that [UID:000344] now emits formal first-draft C++ in `FolderTreePane.cpp`, through the existing owner route. Preserve that [UID:000157] remains a non-emitting inventory/container and that sibling traversal helpers remain separate decisions. Record the context fields `pane`, `rowCount`, `maxWidth`, `Tree<FolderTreePane::TreeElem>::TraverseContentDimensions`, and `GrafPort::GetTextWidth` dependency.
- [UID:00005A][FolderTreePane](../../../../../by-class/FolderTreePane.md): update the `CalculateContentDimensions` method notes to say it initializes a `TreeItor<TreeElem>` at root index `0`, passes a stack context to the tree traversal helper, then stores content width/height from `maxWidth` and `rowCount`. Keep [UID:000344] out of the public API list except as private/file-local helper support.
- [UID:000155][FolderTreePaneCore](../../../../../by-memory/0x004b1b90-0x004b32c9.FolderTreePaneCore.md): update the `CalculateContentDimensions` child row/evidence with current MCP facts: sole call to `0x004b3400`, tree field at byte `0x130`, context initialized to pane/0/0, and post-call content extent calculation.
- [UID:000157][FolderTreePaneTreeAndSortHelpers](../../../../../by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md): update the [UID:000344] child row to say it is now a source-ready emitted helper through [UID:0000JG], while the aggregate remains `RECONSTRUCTABLE:FALSE` and non-emitting.
- [UID:0001UJ][FolderTreePane::TreeElem](../../../../../by-type/by-struct/FolderTreePane__TreeElem.md): add B015 evidence tying [UID:000344] to `parentIndex`, `lastChildIndex`, `previousSiblingIndex`, `name`, `rowIndex`, `depth`, and `expanded`. Preserve that this helper does not read `isHidden`.
- [UID:0001WP][FolderTreePaneTreeTemplates](../../../../../by-type/by-template/FolderTreePaneTreeTemplates.md): add that the content-dimension traversal is a concrete `Tree<FolderTreePane::TreeElem>` specialization/helper in the current emitted file, with shared-header factoring still unresolved.
- [UID:0000F9][Tree_struct_FolderTreePane__TreeElem_](../../../../../by-class/Tree_struct_FolderTreePane__TreeElem_.md): add the `TraverseContentDimensions` helper declaration/role if this page is used as the local `Tree<T>` support declaration. The generated `TreeItor` methods already rely on `m_storage`, and the new helper also uses `m_storage` directly.

No support edit is required on [UID:000345], [UID:000346], [UID:000347], or [UID:00034H] during this callback unless the supervisor explicitly expands scope. They are useful comparison points, but each has separate unresolved source-quality decisions.

## Validator Plan For Implementation Callback

Run scoped validators from `E:\NTK\GhidraBridge\source-3\project-documentation` after the by-* edits, with `--wait-generated` at least on the target and route files:

> Executable block R001 was removed from this report and preserved verbatim in [000344-FolderTreeContentDimensionsTraversal-empty-emitter-source-quality-removed.md](000344-FolderTreeContentDimensionsTraversal-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

After validators, inspect `auto-generated/NexusTK/ui/controls/FolderTreePane.cpp` and prove:

- [UID:000344] no longer appears as an `Empty Emitter Marker`.
- [UID:000344] emits the formal C++ body from this report.
- Other unrelated empty markers in `FolderTreePane.cpp` are unchanged/out of scope.
- The generated header refresh command ID/timestamp are reported if generated output refreshes.

## Rejected Alternatives

- Covered-by/no-code marker: rejected. [UID:000344] is an ordinary function body with a real caller and behavior not represented by an existing declaration alone.
- Clear `EMITTER_UIDS`: rejected. The target already has the correct `0000JG` route, and the generated empty marker exists because C++ is blank, not because ownership is wrong.
- Move ownership to `FolderTreePane` class [UID:00005A]: rejected as a direct owner change. The class should document the private helper relationship, but the emitting route remains the by-file [UID:0000JG]. The binary receiver is the tree, not the pane.
- Move ownership to GrafPort/text helpers: rejected. GrafPort supplies `GetTextWidth`, but the caller, tree fields, and traversal state are FolderTreePane-specific.
- Move ownership to `LObject`, `StringBase`, or generic runtime/STL pages: rejected by sole caller, receiver, and prior B001/B008 source-quality decisions.
- Split the range: rejected. MCP function boundary, bytes, and the next function at `0x004b3650` confirm the exact target range.
- Keep blank C++ due inferred names: rejected. The remaining inferred names are ordinary first-draft caveats, not blockers. The helper body, data flow, caller route, and emitted source placement are sufficiently resolved for `90/91`.
- Emit as `std::stack<int>`: not recommended. It may be source-equivalent, but the binary evidence is better captured by an explicit `std::deque<int>` with LIFO operations.

## Implementation Callback Results

Accepted implementation completed for [UID:000344][0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal](../../../../../by-memory/0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal.md).

Edited target/support docs:

- [UID:000344][0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal](../../../../../by-memory/0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal.md)
- [UID:0000JG][FolderTreePane](../../../../../by-file/FolderTreePane.md)
- [UID:00005A][FolderTreePane](../../../../../by-class/FolderTreePane.md)
- [UID:000155][FolderTreePaneCore](../../../../../by-memory/0x004b1b90-0x004b32c9.FolderTreePaneCore.md)
- [UID:000157][FolderTreePaneTreeAndSortHelpers](../../../../../by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md)
- [UID:0001UJ][FolderTreePane::TreeElem](../../../../../by-type/by-struct/FolderTreePane__TreeElem.md)
- [UID:0001WP][FolderTreePaneTreeTemplates](../../../../../by-type/by-template/FolderTreePaneTreeTemplates.md)
- [UID:0000F9][Tree_struct_FolderTreePane__TreeElem_](../../../../../by-class/Tree_struct_FolderTreePane__TreeElem_.md)

Lease proof:

- Initial B015 implementation leases succeeded for the eight accepted by-* files at `2026-06-29T02:23:23Z`, then were renewed/reacquired as overlapping B-agent windows allowed. B015 did not edit while another agent held an active lease; when B006/B013 held overlapping FolderTreePane support pages, B015 paused and resumed after reacquiring the exact pages.
- Final validator-batch leases succeeded for all eight accepted by-* files before validation.
- Final release command after validation returned `Success` for all eight accepted by-* files.
- Final `tools/leaser/Agents/current_leases.md` check showed no active B015 leases; only unrelated B011 Error-page leases remained.

Validator proof from `E:\NTK\GhidraBridge\source-3\project-documentation`:

| File | Command | Timestamp | Result |
| --- | --- | --- | --- |
| `by-memory\0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal.md` | `000000000124` | `2026-06-28T22:50:10-04:00` | `ok: 1`, `completion_update 90`, `confidence_update 91`, generated refresh skipped by `--no-generated-refresh`. |
| `by-file\FolderTreePane.md` | `000000000125` | `2026-06-28T22:50:12-04:00` | `ok: 1`, generated refresh skipped. |
| `by-class\FolderTreePane.md` | `000000000126` | `2026-06-28T22:50:13-04:00` | `ok: 1`, generated refresh skipped. |
| `by-memory\0x004b1b90-0x004b32c9.FolderTreePaneCore.md` | `000000000127` | `2026-06-28T22:50:15-04:00` | `ok: 1`, inserted UID000344 links, generated refresh skipped. |
| `by-memory\0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md` | `000000000128` | `2026-06-28T22:50:17-04:00` | `ok: 1`, inserted UID000344/345/346/347 links, generated refresh skipped. |
| `by-type\by-struct\FolderTreePane__TreeElem.md` | `000000000129` | `2026-06-28T22:50:18-04:00` | `ok: 1`, inserted UID000344 link, generated refresh skipped. |
| `by-type\by-template\FolderTreePaneTreeTemplates.md` | `000000000130` | `2026-06-28T22:50:20-04:00` | `ok: 1`, recorded UID000344 reference, generated refresh skipped. |
| `by-class\Tree_struct_FolderTreePane__TreeElem_.md` | `000000000131` | `2026-06-28T22:50:22-04:00` | `ok: 1`, inserted UID000344 link, generated refresh skipped. |
| target generated refresh | `000000000132` | `2026-06-28T22:50:23-04:00` | `ok: 1`, `generated_refresh: completed`, `autogen_cpp_update: 1`. |

Generated-output proof:

- `auto-generated/NexusTK/ui/controls/FolderTreePane.cpp` now has `validator-command-id: 000000000132` and `validator-refreshed-at: 2026-06-28T22:50:23-04:00`.
- The generated UID000344 block now starts at line `258` as `// UID:000344 ... Completion:90 | Confidence:91`.
- Lines `259-309` emit `FolderTreeContentDimensionsContext` and `template <> void Tree<FolderTreePane::TreeElem>::TraverseContentDimensions(...)` with the accepted `std::deque<int>` traversal body.
- The generated UID000344 block no longer appears as `Empty Emitter Marker`; unrelated existing empty markers in the same generated file remain out of scope.

## Implementation Tracking Checklist

- [x] Lease only the accepted by-* files immediately before editing; do not lease during report-only work. Proof: final B015 lease/release batch covered exactly the accepted eight by-* files, and final release returned `Success` for all eight.
- [x] Preserve/incorporate the 2026-06-28 current MCP restore evidence from session `agent_b009_0002my_20260628`: target/support docs now cite `server_health`, `lookup_funcs`, `xrefs_to`, `get_bytes`, negative find/find_bytes/type/name/text checks, failed unavailable `callers` note, and generated empty-marker state.
- [x] Update [UID:000344] metadata to `COMPLETION:90`, `CONFIDENCE:91`, keep owner/emitter route `0000JG`, and keep blank `EMITTER_POSITION_OPTIONAL`. Proof: validator command `000000000124` recorded `completion_update 90`, `confidence_update 91`, and `canonical_owner_update 0000JG`.
- [x] Insert the exact formal C++ from this report into [UID:000344] `RECONSTRUCTION_CPP CODE` block. Proof: generated `FolderTreePane.cpp` lines `259-309` emit the accepted context and `TraverseContentDimensions` body.
- [x] Replace stale "Do not emit final C++ yet" language on [UID:000344] with the live MCP behavior, route, source-placement, and score rationale. Proof: target page has `2026-06-28 B015 Accepted Implementation Sync` and updated score rationale.
- [x] Update [UID:0000JG] `by-file/FolderTreePane.md` with the first-draft C++ route, context struct, helper role, and aggregate/sibling scope notes. Proof: file page has the `content-dimension traversal helper` proposed-content row and B015 generated-output/no-code policy entry.
- [x] Update [UID:00005A] `by-class/FolderTreePane.md` with `CalculateContentDimensions` caller/context/content-extents detail while keeping [UID:000344] private/file-local support. Proof: class method table and heuristic row cite `TraverseContentDimensions` as private/file-local tree support.
- [x] Update [UID:000155] `FolderTreePaneCore` with caller and post-call extent evidence. Proof: core range table, touched-state table, source-facing name table, and B015 change entry cite the `0x004b2fbf` call, `this+0x130` receiver, and context fields.
- [x] Update [UID:000157] `FolderTreePaneTreeAndSortHelpers` to record [UID:000344] as emitted source-ready child while the aggregate remains non-emitting. Proof: aggregate child row now names `Tree<FolderTreePane::TreeElem>::TraverseContentDimensions`, and B015 section keeps `RECONSTRUCTABLE:FALSE`.
- [x] Update [UID:0001UJ] `FolderTreePane::TreeElem` with row/depth/name/expanded/lastChild/previousSibling evidence and negative `isHidden` evidence. Proof: struct evidence notes and B015 change entry cite all those fields and the no-`+0x20` read.
- [x] Update tree-template support pages [UID:0001WP] and [UID:0000F9]. Proof: template page exact-memory table and tree-wrapper class method table both include `TraverseContentDimensions`.
- [x] Run scoped validators for every edited by-* file and record command, `command_id`, `command_timestamp`, exit code, `ok` count, and generated-refresh state. Proof: commands `000000000124` through `000000000132` all exited `0`; each file-mode validator reported `ok: 1`; final command `000000000132` reported `generated_refresh: completed`.
- [x] Inspect `auto-generated/NexusTK/ui/controls/FolderTreePane.cpp` after generated refresh and prove [UID:000344] no longer appears as an `Empty Emitter Marker` and emits the accepted formal body. Proof: lines `258-309` contain the UID000344 body; no UID000344 empty marker appears.
- [x] Release leases immediately after the edit/validator batch and record release/expiry state. Proof: final B015 unlease command returned `Success` for all eight accepted by-* paths; final lease report shows no active B015 leases.

## Implementation Closeout

Implementation is complete. [UID:000344] is now a formal first-draft C++ emitter under [UID:0000JG], not a no-code marker or ownership repair.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B015","command_id":"000000004165","destination_path":"executed-b-agent-research/B015/000344-FolderTreeContentDimensionsTraversal-empty-emitter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B015/research/000344-FolderTreeContentDimensionsTraversal-empty-emitter-source-quality.md","timestamp":"2026-06-28T22:56:30","uid":"000344"} -->
<!-- {"agent":"B015","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000344-FolderTreeContentDimensionsTraversal-empty-emitter-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B015/000344-FolderTreeContentDimensionsTraversal-empty-emitter-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000344"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
