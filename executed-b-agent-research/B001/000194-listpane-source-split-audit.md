** TARGET-REPORT-UID:000194 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 000194 ListPane Source Split Audit

## Final Recommendation

Create an executable seven-child split for [UID:000194][0x004f3a50-0x004f4a77.ListPane](../../../by-memory/0x004f3a50-0x004f4a77.ListPane.md), then reclassify [UID:000194] itself as a non-emitting `ListPane` split index under [UID:0000KT][ListPane](../../../by-file/ListPane.md).

This is not a no-change pass. The target is the only current `project-level/-auto-completion-stats.md` `Low_Completion` / `Low_Both` row at `80/88`, and live IDA plus raw PE checks support exact source-family children that clear the 85/85 gate. The raw no-function starts should not become standalone high-confidence method pages, because they still have no caller/pointer/branch route; instead they should be documented inside two exact ListPane-owned helper clusters where adjacency, field layout, internal callees, and source-file ownership are strong.

Do not add final C++ yet. The split resolves the source-container problem, but final original method names, several `ListPane` field names, and raw helper liveness remain below final-source quality.

## Current State Checked

- Target: [UID:000194] `by-memory/0x004f3a50-0x004f4a77.ListPane.md`.
- Current metadata: `COMPLETION:80`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000KT`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KT`, final C++ blank.
- Current `project-level/-auto-completion-stats.md`, generated `2026-06-16 03:39:16`, lists only [UID:000194] under `Low_Completion` and `Low_Both`.
- Current `auto-generated/by-memory-tool-report.md`, generated `2026-06-16 09:04:48`, reports Barrier Crossings, General Errors, Filename Errors, and Advanced-Error-Scan as `None`; [UID:000194] appears as largest leaf rank 96, 4135 bytes.
- Current `by-memory/-coverage-report.md` row line 2045 is the single reconstructable aggregate row.

## Evidence Checked

- Required docs read: `Agent-B001/goal.md`, `by-structure.md`, `Agent-B001/inference_research.md`, target [UID:000194], [UID:0000KT] `by-file/ListPane.md`, [UID:00007A] `by-class/ListPane.md`, [UID:0000CF] `ScrollablePane.md`, [UID:0000CS] `SelectionState.md`, `project-level/-auto-completion-stats.md`, `auto-generated/by-memory-tool-report.md`, `by-memory/-coverage-report.md` context, `by-memory/-guidance.md`, and [UID:0003OM] `ListPaneVtableData`.
- Source-tree evidence: `by-project-structure/proposed-source-tree.md` places `ListPane.cpp` under `ui/controls`, says `ListPane` owns `0x004f3a50-0x004f4a77`, keeps `SimpleListPane` as a sibling or folded small control adapter, and identifies `ArticleListPane`, `ChattingColorListPane`, `ServerItemMenuItemList`, and `SelectionState` output as generated owner pollution.
- IDA MCP session used: existing `b001_mappane_0001AW_20260616`; health reported input `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, IDB `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`, imagebase `0x400000`, Hex-Rays ready, active worker not analyzing.
- IDA function inventory: `entity_query(functions, 0x004f3a40-0x004f4a90)` reports 29 modeled functions inside the target and successor `LObject` starts at `0x004f4a80`/`0x004f4a90`.
- IDA names/globals: `entity_query(names/globals)` reports only `jpt_4F41B1` at `0x004f42ec` and `jpt_4F4331` at `0x004f43d0` inside the target as data names.
- IDA xrefs: modeled helper fanout remains broad: constructor 39 refs, base destructor 27 refs, `GetItemCount` 69 refs, append helper 47 refs, selected-entry 98 refs, selection count 14 refs, `IsItemSelected` 26 refs, scroll metrics 28 vtable/data refs each, input/key/paint methods vtable/data refs, and internal calls among navigation helpers.
- Raw no-function starts: `lookup_funcs` reports no function object at `0x004f3bb0`, `0x004f3be0`, `0x004f3cb0`, `0x004f3d00`, `0x004f4820`, or `0x004f4910`. `xrefs_to` reports zero xrefs to all six raw starts.
- Raw disassembly: IDA `disasm` confirms complete method-shaped raw bodies at all six raw starts. `make_signature_for_range(..., wildcard_operands=false)` confirms unique byte signatures for each raw body plus alignment.
- Raw PE scan: parsed `NexusTK.exe` PE sections and scanned for little-endian absolute VA dwords, RVA dwords, `E8/E9 rel32`, and `0F 8x rel32` branches to the six raw starts. No hits were found for any raw start. Switch-table heads did have expected absolute dword hits at their using instructions.
- Switch tables: PE bytes at `0x004f42ec-0x004f42fc` decode to `0x004f421c`, `0x004f41b8`, `0x004f4248`, `0x004f4290`; bytes at `0x004f43d0-0x004f43e0` decode to `0x004f434f`, `0x004f4338`, `0x004f43af`, `0x004f43af`. IDA `xrefs_to` reports one xref to each table, from `0x004f41b1` and `0x004f4331`.

## Source-Structure Decision

The physical range is a single reusable `ListPane` implementation block, not a mixed-owner container. The current generated-output pollution into `ArticleListPane`, `ChattingColorListPane`, `ServerItemMenuItemList`, and `SelectionState` is caller/heuristic pollution, not ownership evidence:

- Every helper reads the same `ListPane` state cluster: primary list `+0x130`, selected index `+0x134`, selection flag list `+0x138`, selection-mode byte `+0x13c`, item cell dimensions `+0x140/+0x144`, column/page byte `+0x148`, and drag/input byte `+0x149`.
- Constructor/destructor/vtable data route to [UID:0000KT] `ListPane`.
- `SelectionState` is already ignored as an alias for `ListPane::GetSelectionCount`, and live IDA still finds no independent `SelectionState` constructor/destructor/vtable/name.
- The broad caller fanout crosses board, mail, chat-color, clan, exchange, item/spell/menu, server select, phone book, power, and user-list panes. No derived feature owns the shared bodies.

Therefore:

- Create exact `ListPane` child clusters, not feature-owned method pages.
- Reclassify [UID:000194] as `RECONSTRUCTABLE:FALSE` / blank emitters after the children exist.
- Keep [UID:000194] `CANONICAL_OWNER:0000KT` as a source-family index, because the split index is still the `ListPane.cpp` executable family map.
- Do not create standalone raw helper pages for the six raw no-route starts. They are real retained ListPane bytes, but the evidence does not safely prove independent callable source methods.
- Do not edit IDA DB. The missing raw function objects are an important source-quality fact; force-creating functions without reachability would hide the blocker.

## UID Allocation Assumption

Assume current next available UID after supervisor-executed [UID:0003TY] is [UID:0003TZ]. Supervisor must re-check current UID availability before applying. If any concurrent allocation advanced the UID stream, keep the ranges/titles exactly and substitute the next free contiguous UID sequence.

| Proposed UID | File | Range | Score | Owner/emitter |
| --- | --- | --- | --- | --- |
| [UID:0003TZ] | `by-memory/0x004f3a50-0x004f3bb0.ListPaneConstructionAndBaseDestructor.md` | `0x004f3a50-0x004f3bb0` | `86/90` | [UID:0000KT] |
| [UID:0003U0] | `by-memory/0x004f3bb0-0x004f3f20.ListPaneItemSelectionStorageHelpers.md` | `0x004f3bb0-0x004f3f20` | `86/88` | [UID:0000KT] |
| [UID:0003U1] | `by-memory/0x004f3f20-0x004f4190.ListPaneScrollMetricVirtuals.md` | `0x004f3f20-0x004f4190` | `86/90` | [UID:0000KT] |
| [UID:0003U2] | `by-memory/0x004f4190-0x004f43e0.ListPaneInputKeyHandlersAndSwitchTables.md` | `0x004f4190-0x004f43e0` | `86/89` | [UID:0000KT] |
| [UID:0003U3] | `by-memory/0x004f43e0-0x004f45b0.ListPanePaintHitTestGeometry.md` | `0x004f43e0-0x004f45b0` | `86/89` | [UID:0000KT] |
| [UID:0003U4] | `by-memory/0x004f45b0-0x004f4920.ListPaneSelectionNavigationRawClampHelpers.md` | `0x004f45b0-0x004f4920` | `86/88` | [UID:0000KT] |
| [UID:0003U5] | `by-memory/0x004f4920-0x004f4a77.ListPaneEnsureVisibleDestructorThunks.md` | `0x004f4920-0x004f4a77` | `86/90` | [UID:0000KT] |

No `by-memory/-ignored.md` entries are recommended for internal alignment bytes in this batch. The child ranges intentionally cover method clusters with their internal compiler alignment and, for [UID:0003U2], switch-table data owned by the source `switch` statements. Existing external padding rows `0x004f3a43-0x004f3a50` and `0x004f4a77-0x004f4a80` remain unchanged.

## Exact Parent Metadata Change

Apply to `by-memory/0x004f3a50-0x004f4a77.ListPane.md` after creating the child pages:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Replace the parent disposition/status text with a split-index summary that says:

```text
## Status

- Confidence: very strong for ListPane ownership and exact child split boundaries.
- Range: `0x004f3a50-0x004f4a77` end-exclusive.
- Entity kind: non-emitting `ListPane` executable split index.
- Source owner: [UID:0000KT][ListPane](by-file/ListPane.md).
- Disposition: not reconstructable as one source-emitting range. Exact child pages carry the source-bearing method/helper evidence; this page remains the address-family map.

## Exact Children

| Child | Range | Role |
| --- | --- | --- |
| [UID:0003TZ][ListPaneConstructionAndBaseDestructor](by-memory/0x004f3a50-0x004f3bb0.ListPaneConstructionAndBaseDestructor.md) | `0x004f3a50-0x004f3bb0` | Constructor and non-deleting base destructor core. |
| [UID:0003U0][ListPaneItemSelectionStorageHelpers](by-memory/0x004f3bb0-0x004f3f20.ListPaneItemSelectionStorageHelpers.md) | `0x004f3bb0-0x004f3f20` | Item storage, insertion/removal, selection queries, and early raw no-function helper bodies. |
| [UID:0003U1][ListPaneScrollMetricVirtuals](by-memory/0x004f3f20-0x004f4190.ListPaneScrollMetricVirtuals.md) | `0x004f3f20-0x004f4190` | Scroll range, overflow/page-size, offset/content-size, and scroll delta virtuals. |
| [UID:0003U2][ListPaneInputKeyHandlersAndSwitchTables](by-memory/0x004f4190-0x004f43e0.ListPaneInputKeyHandlersAndSwitchTables.md) | `0x004f4190-0x004f43e0` | Mouse/input and key handlers plus owned switch tables. |
| [UID:0003U3][ListPanePaintHitTestGeometry](by-memory/0x004f43e0-0x004f45b0.ListPanePaintHitTestGeometry.md) | `0x004f43e0-0x004f45b0` | Paint, hit-test, and item-rectangle geometry methods. |
| [UID:0003U4][ListPaneSelectionNavigationRawClampHelpers](by-memory/0x004f45b0-0x004f4920.ListPaneSelectionNavigationRawClampHelpers.md) | `0x004f45b0-0x004f4920` | Selection update, keyboard navigation, raw clamp/notify body, page navigation, and raw tail shim. |
| [UID:0003U5][ListPaneEnsureVisibleDestructorThunks](by-memory/0x004f4920-0x004f4a77.ListPaneEnsureVisibleDestructorThunks.md) | `0x004f4920-0x004f4a77` | Ensure-visible helper, secondary/tertiary destructor adjustor thunks, and scalar deleting destructor. |

## Score Rationale

Completion should become `88` because the parent now records exact child coverage for every byte in the range, the raw no-function bodies, embedded switch tables, generated-output pollution, owner route, and source-placement decision. Confidence should become `90` because live IDA and raw PE checks verify the modeled starts, raw starts, switch-table references, xref fanout, source-tree placement, and lack of raw-start reachability. The parent stays below final-source/audit quality because final method names, field names, and raw helper liveness remain child-level blockers.
```

Leave the parent final C++ block blank.

## Exact Child Page Markdown

### [UID:0003TZ] `0x004f3a50-0x004f3bb0.ListPaneConstructionAndBaseDestructor.md`

```markdown
*** UID:0003TZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x004f3a50-0x004f3bb0.ListPaneConstructionAndBaseDestructor

## Status

- Range: `0x004f3a50-0x004f3bb0` end-exclusive.
- Entity kind: `ListPane` constructor/destructor cluster.
- Owner/emitter: [UID:0000KT][ListPane](by-file/ListPane.md).
- Parent split index: [UID:000194][0x004f3a50-0x004f4a77.ListPane](by-memory/0x004f3a50-0x004f4a77.ListPane.md).
- Final C++: blank pending final constructor signature, field names, and source-header shape.

## Inventory

| Address | IDA status | Role |
| --- | --- | --- |
| `0x004f3a50-0x004f3b5b` | modeled `sub_4F3A50`, size `0x10b` | `ListPane` constructor. |
| `0x004f3b5b-0x004f3b60` | `0xcc` alignment | Constructor-to-destructor padding inside the source family. |
| `0x004f3b60-0x004f3ba5` | modeled `sub_4F3B60`, size `0x45` | Non-deleting destructor/base cleanup body called by derived destructors. |
| `0x004f3ba5-0x004f3bb0` | `0xcc` alignment | Padding before item/selection helper cluster. |

## Evidence

- IDA `entity_query(functions, 0x004f3a40-0x004f4a90)` confirms function starts at `0x004f3a50` and `0x004f3b60`, ending before the raw helper start at `0x004f3bb0`.
- `analyze_function(0x004f3a50)` decompiles the constructor: it calls `ScrollablePane` construction, writes three `ListPane` vtable views at `this`, `this+0xa0`, and `this+0xa4`, allocates two `List` instances, sets selected index `+0x134` to `-1`, stores the primary/selection lists at `+0x130/+0x138`, stores selection/layout bytes at `+0x13c/+0x148/+0x149`, initializes cell dimensions at `+0x140/+0x144`, and marks the pane visible.
- `xrefs_to 0x004f3a50` reports 39 code refs spanning board/article, mail, chat-color, clan, exchange, item/spell/menu, server-select, phone-book, power, and user-list construction paths.
- `analyze_function(0x004f3b60)` decompiles the non-deleting cleanup: it restores the same three `ListPane` vtable views, deletes the two owned list objects at `+0x130` and `+0x138` when present, then chains to `ScrollablePane` teardown.
- `xrefs_to 0x004f3b60` reports 27 code refs from derived list-pane destructors and cleanup wrappers.

## Source Placement

The range belongs in `NexusTK/ui/controls/ListPane.cpp`. `ScrollablePane` owns the base scrolling infrastructure, but this cluster owns selectable list state and must not migrate to feature files that only construct derived lists.

## Remaining Blockers

- Constructor parameters are clear by behavior but original names are not recovered.
- Field names for `+0x130`, `+0x134`, `+0x138`, `+0x13c`, `+0x140`, `+0x144`, `+0x148`, and `+0x149` remain inferred layout names.
- Final C++ should wait for a coordinated `ListPane` class declaration and virtual method naming pass.

## Cross-References

- [UID:000194][0x004f3a50-0x004f4a77.ListPane](by-memory/0x004f3a50-0x004f4a77.ListPane.md)
- [UID:0000KT][ListPane](by-file/ListPane.md)
- [UID:00007A][ListPane](by-class/ListPane.md)
- [UID:0000CF][ScrollablePane](by-class/ScrollablePane.md)
- [UID:0003OM][0x0061ce84-0x0061cf44.ListPaneVtableData](by-memory/0x0061ce84-0x0061cf44.ListPaneVtableData.md)
```

### [UID:0003U0] `0x004f3bb0-0x004f3f20.ListPaneItemSelectionStorageHelpers.md`

```markdown
*** UID:0003U0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x004f3bb0-0x004f3f20.ListPaneItemSelectionStorageHelpers

## Status

- Range: `0x004f3bb0-0x004f3f20` end-exclusive.
- Entity kind: `ListPane` item-storage and selection-helper cluster.
- Owner/emitter: [UID:0000KT][ListPane](by-file/ListPane.md).
- Parent split index: [UID:000194][0x004f3a50-0x004f4a77.ListPane](by-memory/0x004f3a50-0x004f4a77.ListPane.md).
- Final C++: blank pending final helper names, field names, and raw no-route disposition.

## Inventory

| Address | IDA status | Role |
| --- | --- | --- |
| `0x004f3bb0-0x004f3bcb` | raw no-function body, padded to `0x004f3bd0` | Copies content extent fields `+0x140/+0x144` into caller output. |
| `0x004f3bd0-0x004f3bdf` | modeled `sub_4F3BD0` | Returns primary list count or zero. |
| `0x004f3be0-0x004f3bfb` | raw no-function body, padded to `0x004f3c00` | Computes page/row count from primary list count and signed byte `+0x148`. |
| `0x004f3c00-0x004f3c4b` | modeled `sub_4F3C00` | Inserts one item and a cleared selection flag at caller index. |
| `0x004f3c50-0x004f3ca4` | modeled `sub_4F3C50` | Appends one item and a cleared selection flag at tail. |
| `0x004f3cb0-0x004f3cfd` | raw no-function body, padded to `0x004f3d00` | Indexed insert into both primary and selection lists with caller-supplied count/stride-like arguments. |
| `0x004f3d00-0x004f3d56` | raw no-function body, padded to `0x004f3d60` | Tail insert helper over both primary and selection lists. |
| `0x004f3d60-0x004f3db7` | modeled `sub_4F3D60` | Removes items, clears selected index, syncs scroll state, and notifies selection change. |
| `0x004f3dc0-0x004f3dcf` | modeled `sub_4F3DC0` | Fetches selected entry through the primary list. |
| `0x004f3dd0-0x004f3e1c` | modeled `sub_4F3DD0` | Sets multi-select/selection-mode byte and clears selection flags. |
| `0x004f3e20-0x004f3e74` | modeled `sub_4F3E20` | Counts selected flags or returns single-selection presence. |
| `0x004f3e80-0x004f3ef7` | modeled `sub_4F3E80` | Exports selected indices to caller buffer. |
| `0x004f3f00-0x004f3f1b` | modeled `sub_4F3F00` | Tests whether an item is selected. |

## Evidence

- `lookup_funcs` confirms modeled starts at `0x004f3bd0`, `0x004f3c00`, `0x004f3c50`, `0x004f3d60`, `0x004f3dc0`, `0x004f3dd0`, `0x004f3e20`, `0x004f3e80`, and `0x004f3f00`.
- IDA reports no function object at raw starts `0x004f3bb0`, `0x004f3be0`, `0x004f3cb0`, and `0x004f3d00`. `xrefs_to` reports no xrefs to these raw starts.
- Local PE scan found no absolute VA, RVA, `E8/E9 rel32`, or `0F 8x rel32` hits to those four raw starts.
- Raw disassembly confirms complete method-shaped bodies: `0x004f3bb0` copies `+0x140/+0x144` to output and returns `retn 4`; `0x004f3be0` divides `(count - 1)` by signed byte `+0x148`; `0x004f3cb0` and `0x004f3d00` insert into both list fields and call the scroll sync/helper path.
- `make_signature_for_range` reports unique raw-byte signatures for the four raw bodies plus padding.
- Modeled helper xrefs prove the shared ListPane route: `0x004f3bd0` has 69 refs, `0x004f3c50` has 47 refs, `0x004f3dc0` has 98 refs, `0x004f3e20` has 14 refs, `0x004f3e80` has 19 refs, and `0x004f3f00` has 26 refs across unrelated list-pane users.
- `SelectionState` support documentation already records that `0x004f3e20` is a `ListPane` helper, not an independent class.

## Source Placement

This cluster belongs to `ListPane.cpp`. Current generated source owners `ArticleListPane`, `ChattingColorListPane`, `ServerItemMenuItemList`, and `SelectionState` are caller-biased pollution. The raw bodies should remain part of this cluster until a real call/pointer route or final source name is recovered.

## Remaining Blockers

- The raw starts are real retained bytes but have no direct reachability evidence; do not split them into standalone high-confidence pages yet.
- Helper names such as `InsertItem`, `AddEntry`, `GetSelectionCount`, and `GetSelectedIndices` are behavioral names, not recovered original names.
- Final field names for the two lists, selected index, selection-mode byte, and cell/page-size fields remain inferred.

## Cross-References

- [UID:000194][0x004f3a50-0x004f4a77.ListPane](by-memory/0x004f3a50-0x004f4a77.ListPane.md)
- [UID:0000KT][ListPane](by-file/ListPane.md)
- [UID:00007A][ListPane](by-class/ListPane.md)
- [UID:0000CS][SelectionState](by-class/SelectionState.md)
```

### [UID:0003U1] `0x004f3f20-0x004f4190.ListPaneScrollMetricVirtuals.md`

```markdown
*** UID:0003U1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x004f3f20-0x004f4190.ListPaneScrollMetricVirtuals

## Status

- Range: `0x004f3f20-0x004f4190` end-exclusive.
- Entity kind: `ListPane` virtual scroll-metric method cluster.
- Owner/emitter: [UID:0000KT][ListPane](by-file/ListPane.md).
- Parent split index: [UID:000194][0x004f3a50-0x004f4a77.ListPane](by-memory/0x004f3a50-0x004f4a77.ListPane.md).
- Final C++: blank pending final virtual names and field names.

## Inventory

| Address | IDA size | Role |
| --- | ---: | --- |
| `0x004f3f20` | `0xbe` | Computes scroll range from item count, cell size, page columns, and viewport dimensions. |
| `0x004f3fe0` | `0x61` | Computes overflow count. |
| `0x004f4050` | `0x49` | Computes page size. |
| `0x004f40a0` | `0x31` | Returns current scroll offset. |
| `0x004f40e0` | `0x57` | Computes content size. |
| `0x004f4140` | `0x49` | Computes scroll delta/page-step value. |

## Evidence

- `entity_query(functions)` confirms all six modeled starts and exact sizes.
- `xrefs_to` reports 28 mostly data/vtable refs for each of the six starts. Representative refs include `0x00613d30-0x00613d44`, `0x00613e94-0x00613ea8`, `0x00614320-0x00614334`, and `0x0061cef0` family slots, matching inherited/reused ListPane virtuals.
- Decompilation and current target docs show the methods read the primary item count at `+0x130/+0x0c`, inherited scroll state, cell dimensions `+0x140/+0x144`, and column/page byte `+0x148`.
- Source-tree and support docs classify these as reusable list-control behavior, not feature-list code.

## Source Placement

Keep this cluster in `ui/controls/ListPane.cpp`. `ScrollablePane` provides base scroll state and scrollbars, but these methods translate `ListPane` item geometry into scroll metrics.

## Remaining Blockers

- Final virtual method names are still behavioral and should be coordinated with the `ScrollablePane`/`ListPane` declaration.
- Exact member names for inherited scroll-state offsets are not finalized.

## Cross-References

- [UID:000194][0x004f3a50-0x004f4a77.ListPane](by-memory/0x004f3a50-0x004f4a77.ListPane.md)
- [UID:0000KT][ListPane](by-file/ListPane.md)
- [UID:00007A][ListPane](by-class/ListPane.md)
- [UID:0000CF][ScrollablePane](by-class/ScrollablePane.md)
- [UID:0003OM][0x0061ce84-0x0061cf44.ListPaneVtableData](by-memory/0x0061ce84-0x0061cf44.ListPaneVtableData.md)
```

### [UID:0003U2] `0x004f4190-0x004f43e0.ListPaneInputKeyHandlersAndSwitchTables.md`

```markdown
*** UID:0003U2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x004f4190-0x004f43e0.ListPaneInputKeyHandlersAndSwitchTables

## Status

- Range: `0x004f4190-0x004f43e0` end-exclusive.
- Entity kind: `ListPane` input/key handler cluster with owned compiler switch tables.
- Owner/emitter: [UID:0000KT][ListPane](by-file/ListPane.md).
- Parent split index: [UID:000194][0x004f3a50-0x004f4a77.ListPane](by-memory/0x004f3a50-0x004f4a77.ListPane.md).
- Final C++: blank pending final event/key enum names and virtual names.

## Inventory

| Address | IDA status | Role |
| --- | --- | --- |
| `0x004f4190-0x004f42ec` | modeled `sub_4F4190`, size `0x15c` | Mouse/input handler. |
| `0x004f42ec-0x004f42fc` | global `jpt_4F41B1` | Four-entry switch table used by `0x004f41b1`. |
| `0x004f42fc-0x004f4300` | `0xcc` alignment | Padding before key handler. |
| `0x004f4300-0x004f43ce` | modeled `sub_4F4300`, size `0xce` | Key handler. |
| `0x004f43d0-0x004f43e0` | global `jpt_4F4331` after two-byte align | Four-entry key switch table used by `0x004f4331`. |

## Evidence

- IDA `entity_query(functions)` confirms modeled handler starts at `0x004f4190` and `0x004f4300`.
- IDA `entity_query(names/globals)` confirms only `jpt_4F41B1` and `jpt_4F4331` as data names in this cluster.
- `xrefs_to 0x004f42ec` reports one data ref from `0x004f41b1` inside `sub_4F4190`; PE bytes decode to targets `0x004f421c`, `0x004f41b8`, `0x004f4248`, and `0x004f4290`.
- `xrefs_to 0x004f43d0` reports one data ref from `0x004f4331` inside `sub_4F4300`; PE bytes decode to targets `0x004f434f`, `0x004f4338`, `0x004f43af`, and `0x004f43af`.
- `xrefs_to 0x004f4190` reports vtable/data refs plus two direct derived/base forwarding callers; `xrefs_to 0x004f4300` reports vtable/data refs plus direct key-handler callers from clan/list helper code.
- Current docs and decompilation show the input handler uses event-manager mouse capture/release, hit-testing through `0x004f4480`, selection update through `0x004f45b0`, and visibility adjustment through `0x004f4920`. The key handler dispatches navigation through `0x004f47c0` and `0x004f4880`.

## Source Placement

The switch tables are compiler-generated binary data owned by the two source `switch` statements. They should not be emitted as standalone source objects and do not justify separate owner pages.

## Remaining Blockers

- Event type and key-code names are not finalized.
- The original names for the selection/navigation helpers called from this cluster remain inferred.
- Final C++ should wait for the complete `ListPane` virtual declaration and event enum mapping.

## Cross-References

- [UID:000194][0x004f3a50-0x004f4a77.ListPane](by-memory/0x004f3a50-0x004f4a77.ListPane.md)
- [UID:0000KT][ListPane](by-file/ListPane.md)
- [UID:00007A][ListPane](by-class/ListPane.md)
- [UID:0003U3][0x004f43e0-0x004f45b0.ListPanePaintHitTestGeometry](by-memory/0x004f43e0-0x004f45b0.ListPanePaintHitTestGeometry.md)
- [UID:0003U4][0x004f45b0-0x004f4920.ListPaneSelectionNavigationRawClampHelpers](by-memory/0x004f45b0-0x004f4920.ListPaneSelectionNavigationRawClampHelpers.md)
- [UID:0003U5][0x004f4920-0x004f4a77.ListPaneEnsureVisibleDestructorThunks](by-memory/0x004f4920-0x004f4a77.ListPaneEnsureVisibleDestructorThunks.md)
```

### [UID:0003U3] `0x004f43e0-0x004f45b0.ListPanePaintHitTestGeometry.md`

```markdown
*** UID:0003U3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x004f43e0-0x004f45b0.ListPanePaintHitTestGeometry

## Status

- Range: `0x004f43e0-0x004f45b0` end-exclusive.
- Entity kind: `ListPane` paint, hit-test, and geometry method cluster.
- Owner/emitter: [UID:0000KT][ListPane](by-file/ListPane.md).
- Parent split index: [UID:000194][0x004f3a50-0x004f4a77.ListPane](by-memory/0x004f3a50-0x004f4a77.ListPane.md).
- Final C++: blank pending final row-draw virtual names and rectangle type names.

## Inventory

| Address | IDA size | Role |
| --- | ---: | --- |
| `0x004f43e0` | `0x93` | Paint visible list items and dispatch derived row drawing. |
| `0x004f4473-0x004f4480` | alignment | Padding before hit-test method. |
| `0x004f4480` | `0xbf` | Hit-test a coordinate against item rectangles. |
| `0x004f453f-0x004f4540` | alignment | Padding before item-rectangle method. |
| `0x004f4540` | `0x62` | Compute item rectangle from index, cell size, columns, and scroll origin. |
| `0x004f45a2-0x004f45b0` | alignment | Padding before selection-update method. |

## Evidence

- `entity_query(functions)` confirms modeled starts at `0x004f43e0`, `0x004f4480`, and `0x004f4540`.
- `xrefs_to 0x004f43e0` reports 28 vtable/data refs across reusable and derived list panes.
- `analyze_function(0x004f4480)` confirms hit-test clamps the requested coordinate to visible bounds, iterates item count from primary list `+0x130`, calls the item-rectangle virtual slot, and tests the point against the rectangle.
- `analyze_function(0x004f4540)` confirms item rectangle construction from cell width/height `+0x144/+0x140`, signed column count byte `+0x148`, and visible origin offsets around `+0x120/+0x124`.
- Existing target docs record `OnPaint` dispatching feature-specific item drawing through a virtual row-draw slot, which matches `ListPane` reusable ownership.

## Source Placement

This is generic `ListPane` drawing and geometry. Derived feature panes own row rendering content, but this cluster owns the reusable iteration, hit-test, and item-rectangle math.

## Remaining Blockers

- The draw-item virtual name and exact rectangle helper type names remain inferred.
- Final field names for visible bounds and cell dimensions remain layout names.

## Cross-References

- [UID:000194][0x004f3a50-0x004f4a77.ListPane](by-memory/0x004f3a50-0x004f4a77.ListPane.md)
- [UID:0000KT][ListPane](by-file/ListPane.md)
- [UID:00007A][ListPane](by-class/ListPane.md)
- [UID:0003U2][0x004f4190-0x004f43e0.ListPaneInputKeyHandlersAndSwitchTables](by-memory/0x004f4190-0x004f43e0.ListPaneInputKeyHandlersAndSwitchTables.md)
```

### [UID:0003U4] `0x004f45b0-0x004f4920.ListPaneSelectionNavigationRawClampHelpers.md`

```markdown
*** UID:0003U4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x004f45b0-0x004f4920.ListPaneSelectionNavigationRawClampHelpers

## Status

- Range: `0x004f45b0-0x004f4920` end-exclusive.
- Entity kind: `ListPane` selection and navigation helper cluster.
- Owner/emitter: [UID:0000KT][ListPane](by-file/ListPane.md).
- Parent split index: [UID:000194][0x004f3a50-0x004f4a77.ListPane](by-memory/0x004f3a50-0x004f4a77.ListPane.md).
- Final C++: blank pending final method names and raw no-route disposition.

## Inventory

| Address | IDA status | Role |
| --- | --- | --- |
| `0x004f45b0-0x004f47b1` | modeled `sub_4F45B0`, size `0x201` | Selection update for single, multi, ctrl-toggle, and shift-range selection. |
| `0x004f47c0-0x004f481c` | modeled `sub_4F47C0`, size `0x5c` | Navigate to previous/edge item and notify selection. |
| `0x004f4820-0x004f487c` | raw no-function body, padded to `0x004f4880` | Clamp selected index, ensure item visible, and notify through virtual slot `+0x78`. |
| `0x004f4880-0x004f4907` | modeled `sub_4F4880`, size `0x87` | Navigate forward/page-style and notify selection. |
| `0x004f4910-0x004f4919` | raw no-function tail shim, padded to `0x004f4920` | Frame shim that tail-jumps to `0x004f4880`. |

## Evidence

- `entity_query(functions)` confirms modeled starts at `0x004f45b0`, `0x004f47c0`, and `0x004f4880`.
- `xrefs_to 0x004f45b0` reports 32 refs including direct code refs and vtable/data refs. Decompilation shows selection-flag list mutation, rectangle union/invalidations, selected index `+0x134`, selection flag list `+0x138`, and mode byte `+0x13c`.
- `xrefs_to 0x004f47c0` reports one direct call from `OnKeyEvent` at `0x004f4342`.
- `xrefs_to 0x004f4880` reports direct calls from `OnKeyEvent` at `0x004f43b9` and raw shim `0x004f4914`.
- IDA reports no function object and no xrefs to raw starts `0x004f4820` and `0x004f4910`; local PE scan also finds no absolute VA, RVA, or direct relative branch hits to those starts.
- Raw disassembly at `0x004f4820` reads selected index `+0x134`, clamps against primary-list count at `+0x130/+0x0c`, calls [UID:0003U5][0x004f4920-0x004f4a77.ListPaneEnsureVisibleDestructorThunks](by-memory/0x004f4920-0x004f4a77.ListPaneEnsureVisibleDestructorThunks.md), then dispatches virtual slot `+0x78`.
- Raw disassembly at `0x004f4910` is `push ebp; mov ebp, esp; pop ebp; jmp sub_4F4880`, followed by alignment.
- `make_signature_for_range` reports unique byte signatures for both raw bodies.

## Source Placement

Keep all bytes in `ListPane.cpp`. The raw bodies are ListPane-shaped and use the same selection state, but lack reachability evidence for standalone method pages. Treat them as retained ListPane evidence inside this cluster until another route appears.

## Remaining Blockers

- The raw `0x004f4820` body and `0x004f4910` shim have no direct start xrefs or PE pointer/branch hits. That prevents promoting them to standalone final methods.
- `OnItemSelected`, `NavigateSelection`, and `NavigateSelectionPage` are behavioral names rather than recovered original names.
- Final selection-state field names and modifier flag names remain unresolved.

## Cross-References

- [UID:000194][0x004f3a50-0x004f4a77.ListPane](by-memory/0x004f3a50-0x004f4a77.ListPane.md)
- [UID:0000KT][ListPane](by-file/ListPane.md)
- [UID:00007A][ListPane](by-class/ListPane.md)
- [UID:0003U2][0x004f4190-0x004f43e0.ListPaneInputKeyHandlersAndSwitchTables](by-memory/0x004f4190-0x004f43e0.ListPaneInputKeyHandlersAndSwitchTables.md)
- [UID:0003U5][0x004f4920-0x004f4a77.ListPaneEnsureVisibleDestructorThunks](by-memory/0x004f4920-0x004f4a77.ListPaneEnsureVisibleDestructorThunks.md)
```

### [UID:0003U5] `0x004f4920-0x004f4a77.ListPaneEnsureVisibleDestructorThunks.md`

```markdown
*** UID:0003U5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x004f4920-0x004f4a77.ListPaneEnsureVisibleDestructorThunks

## Status

- Range: `0x004f4920-0x004f4a77` end-exclusive.
- Entity kind: `ListPane` ensure-visible helper and destructor/thunk cluster.
- Owner/emitter: [UID:0000KT][ListPane](by-file/ListPane.md).
- Parent split index: [UID:000194][0x004f3a50-0x004f4a77.ListPane](by-memory/0x004f3a50-0x004f4a77.ListPane.md).
- Final C++: blank pending final virtual names, field names, and compiler-thunk handling in the class declaration.

## Inventory

| Address | IDA size | Role |
| --- | ---: | --- |
| `0x004f4920` | `0xc0` | Ensure target item rectangle is visible by adjusting inherited scroll state. |
| `0x004f49e0` | `0x0b` | Secondary destructor adjustor thunk. |
| `0x004f49eb` | `0x0b` | Tertiary destructor adjustor thunk. |
| `0x004f4a00` | `0x77` | Scalar deleting destructor / deleting wrapper. |

## Evidence

- `entity_query(functions)` confirms modeled starts at `0x004f4920`, `0x004f49e0`, `0x004f49eb`, and `0x004f4a00`, with `sub_4F4A00` ending exactly at `0x004f4a77`.
- Existing coverage confirms `0x004f4a77-0x004f4a80` is `0xcc` padding before `LObjectRuntimeShell`.
- `analyze_function(0x004f4920)` confirms the ensure-visible helper calls the item-rectangle virtual slot, compares against visible bounds, and adjusts scroll position through `sub_55E950` and `sub_55EAE0`.
- `xrefs_to 0x004f4920` reports eight refs from input/key/navigation helpers, including raw `0x004f4820` at `0x004f4866`.
- `xrefs_to 0x004f49e0` and `0x004f49eb` report data refs at `0x0061cf0c` and `0x0061cf3c`, matching secondary/tertiary ListPane vtable views.
- `xrefs_to 0x004f4a00` reports jumps from both adjustor thunks and data ref `0x0061ce84`, matching the primary scalar deleting destructor vtable slot.
- `analyze_function(0x004f4a00)` confirms vtable restore, owned list cleanup, `ScrollablePane` teardown, and optional object free through `sub_4F4AC0`.

## Source Placement

The ensure-visible helper is source-authored `ListPane` logic. The two small adjustor thunks are compiler-generated from the `ListPane` inheritance/destructor declaration and should not be hand-authored as independent final source.

## Remaining Blockers

- Final source should express the class destructor and virtual method declarations, not raw adjustor thunk bodies.
- Inherited scroll-state fields and item-rectangle virtual names are still not final.

## Cross-References

- [UID:000194][0x004f3a50-0x004f4a77.ListPane](by-memory/0x004f3a50-0x004f4a77.ListPane.md)
- [UID:0000KT][ListPane](by-file/ListPane.md)
- [UID:00007A][ListPane](by-class/ListPane.md)
- [UID:0000CF][ScrollablePane](by-class/ScrollablePane.md)
- [UID:0003OM][0x0061ce84-0x0061cf44.ListPaneVtableData](by-memory/0x0061ce84-0x0061cf44.ListPaneVtableData.md)
```

## Support Doc Actions

### `by-file/ListPane.md`

Recommended metadata change:

```text
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Reason: exact child split and raw/no-route disposition are now documented. Do not raise higher because final field names, final virtual names, `SimpleListPane` fold/separate decision, and final C++ remain unresolved.

Add this paragraph under `## Status` after the main address range bullet:

```text
- Exact executable children: [UID:0003TZ][ListPaneConstructionAndBaseDestructor](by-memory/0x004f3a50-0x004f3bb0.ListPaneConstructionAndBaseDestructor.md) through [UID:0003U5][ListPaneEnsureVisibleDestructorThunks](by-memory/0x004f4920-0x004f4a77.ListPaneEnsureVisibleDestructorThunks.md). The parent [UID:000194] is now a non-emitting split index.
```

Replace the migration note that starts `Split or name the newly documented raw ListPane islands` with:

```text
- The raw `ListPane` islands are now contained in exact children [UID:0003U0][0x004f3bb0-0x004f3f20.ListPaneItemSelectionStorageHelpers](by-memory/0x004f3bb0-0x004f3f20.ListPaneItemSelectionStorageHelpers.md) and [UID:0003U4][0x004f45b0-0x004f4920.ListPaneSelectionNavigationRawClampHelpers](by-memory/0x004f45b0-0x004f4920.ListPaneSelectionNavigationRawClampHelpers.md). Keep them in `ListPane.cpp`, but leave final C++ blank until raw reachability and original helper names are recovered.
```

### `by-class/ListPane.md`

No metadata change is required; current `90/88` already reflects strong class ownership and remains below final-source quality. Add these bullets to `## Cross-References`:

```text
- [UID:0003TZ][0x004f3a50-0x004f3bb0.ListPaneConstructionAndBaseDestructor](by-memory/0x004f3a50-0x004f3bb0.ListPaneConstructionAndBaseDestructor.md)
- [UID:0003U0][0x004f3bb0-0x004f3f20.ListPaneItemSelectionStorageHelpers](by-memory/0x004f3bb0-0x004f3f20.ListPaneItemSelectionStorageHelpers.md)
- [UID:0003U1][0x004f3f20-0x004f4190.ListPaneScrollMetricVirtuals](by-memory/0x004f3f20-0x004f4190.ListPaneScrollMetricVirtuals.md)
- [UID:0003U2][0x004f4190-0x004f43e0.ListPaneInputKeyHandlersAndSwitchTables](by-memory/0x004f4190-0x004f43e0.ListPaneInputKeyHandlersAndSwitchTables.md)
- [UID:0003U3][0x004f43e0-0x004f45b0.ListPanePaintHitTestGeometry](by-memory/0x004f43e0-0x004f45b0.ListPanePaintHitTestGeometry.md)
- [UID:0003U4][0x004f45b0-0x004f4920.ListPaneSelectionNavigationRawClampHelpers](by-memory/0x004f45b0-0x004f4920.ListPaneSelectionNavigationRawClampHelpers.md)
- [UID:0003U5][0x004f4920-0x004f4a77.ListPaneEnsureVisibleDestructorThunks](by-memory/0x004f4920-0x004f4a77.ListPaneEnsureVisibleDestructorThunks.md)
```

### `by-class/SelectionState.md`, `by-class/ScrollablePane.md`

No direct changes recommended. `SelectionState` already has `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, and describes itself as a generated alias for `ListPane::GetSelectionCount`. `ScrollablePane` remains only a base/dependency owner.

## Coverage Report Replacement

Do not edit `by-memory/-coverage-report.md` directly as B001. Supervisor should replace the current single row at line 2045, between the existing rows:

```text
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004f3a43-0x004f3a50 | padding | SortedList to ListPane alignment : ignored : 100% : strong : IDA MCP shows `sub_4F3990` ends at `0x004f3a43`; remaining bytes are `0xcc` alignment before `sub_4F3A50`.
```

and:

```text
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004f4a77-0x004f4a80 | padding | ListPane to LObjectRuntimeShell alignment : ignored : 100% : strong : IDA MCP shows `sub_4F4A00` ends at `0x004f4a77`; remaining bytes are `0xcc` alignment before `sub_4F4A80`.
```

with this exact block:

```text
    - [UID:000194][0x004f3a50-0x004f4a77.ListPane](by-memory/0x004f3a50-0x004f4a77.ListPane.md) 0x004f3a50-0x004f4a77 | class method split index | ListPane : not_reconstructable : 88% : very-strong : Reclassified non-emitting ListPane split index after exact children [UID:0003TZ]-[UID:0003U5] cover construction/destruction, item/selection storage helpers including raw no-function bodies, scroll metrics, input/key handlers with switch tables, paint/hit-test geometry, selection/navigation helpers including raw clamp/shim bodies, and ensure-visible/destructor thunk material. Direct source-family route remains [UID:0000KT][ListPane](by-file/ListPane.md); parent C++ stays blank while children carry source evidence.
        - [UID:0003TZ][0x004f3a50-0x004f3bb0.ListPaneConstructionAndBaseDestructor](by-memory/0x004f3a50-0x004f3bb0.ListPaneConstructionAndBaseDestructor.md) 0x004f3a50-0x004f3bb0 | constructor/destructor cluster | ListPaneConstructionAndBaseDestructor : reconstructable : 86% : very-strong : Exact ListPane constructor and non-deleting destructor child; live IDA confirms modeled starts `0x004f3a50`/`0x004f3b60`, constructor caller fanout, three ListPane vtable stores, two owned List allocations, selected-index/list-field initialization, destructor cleanup of both owned lists, ScrollablePane chaining, and internal `0xcc` alignment.
        - [UID:0003U0][0x004f3bb0-0x004f3f20.ListPaneItemSelectionStorageHelpers](by-memory/0x004f3bb0-0x004f3f20.ListPaneItemSelectionStorageHelpers.md) 0x004f3bb0-0x004f3f20 | item/selection helper cluster | ListPaneItemSelectionStorageHelpers : reconstructable : 86% : strong : Exact ListPane storage/selection helper child; live IDA confirms modeled list/count/insert/remove/selection helpers, broad cross-feature caller fanout, and raw no-function starts `0x004f3bb0`, `0x004f3be0`, `0x004f3cb0`, `0x004f3d00` with unique bytes, shared ListPane field layout, no xrefs, and no PE VA/RVA/relative-branch hits.
        - [UID:0003U1][0x004f3f20-0x004f4190.ListPaneScrollMetricVirtuals](by-memory/0x004f3f20-0x004f4190.ListPaneScrollMetricVirtuals.md) 0x004f3f20-0x004f4190 | virtual method cluster | ListPaneScrollMetricVirtuals : reconstructable : 86% : very-strong : Exact ListPane scroll-metric virtual cluster; live IDA confirms six modeled starts from `0x004f3f20` through `0x004f4140`, vtable/data refs across derived list panes, item-count/cell-size/scroll-state calculations, and source placement in reusable `ListPane.cpp`.
        - [UID:0003U2][0x004f4190-0x004f43e0.ListPaneInputKeyHandlersAndSwitchTables](by-memory/0x004f4190-0x004f43e0.ListPaneInputKeyHandlersAndSwitchTables.md) 0x004f4190-0x004f43e0 | input/key handler cluster | ListPaneInputKeyHandlersAndSwitchTables : reconstructable : 86% : strong : Exact ListPane mouse/input and key handler child with owned switch tables; live IDA confirms modeled `sub_4F4190`/`sub_4F4300`, `jpt_4F41B1` and `jpt_4F4331` table xrefs/dwords, event-manager capture/release path, hit-test/selection/ensure-visible/navigation callees, and reusable vtable ownership.
        - [UID:0003U3][0x004f43e0-0x004f45b0.ListPanePaintHitTestGeometry](by-memory/0x004f43e0-0x004f45b0.ListPanePaintHitTestGeometry.md) 0x004f43e0-0x004f45b0 | paint/hit-test geometry | ListPanePaintHitTestGeometry : reconstructable : 86% : strong : Exact ListPane paint, hit-test, and item-rectangle child; live IDA confirms modeled `0x004f43e0`, `0x004f4480`, and `0x004f4540`, vtable refs, visible-item iteration, row-draw virtual dispatch, coordinate clamp/hit-test behavior, item-rectangle cell math, and internal alignment.
        - [UID:0003U4][0x004f45b0-0x004f4920.ListPaneSelectionNavigationRawClampHelpers](by-memory/0x004f45b0-0x004f4920.ListPaneSelectionNavigationRawClampHelpers.md) 0x004f45b0-0x004f4920 | selection/navigation helper cluster | ListPaneSelectionNavigationRawClampHelpers : reconstructable : 86% : strong : Exact ListPane selection/navigation child; live IDA confirms modeled selection update and navigation starts, raw no-function clamp/notify body `0x004f4820` and tail shim `0x004f4910` with unique bytes, no raw-start xrefs or PE VA/RVA/relative-branch hits, internal calls to EnsureItemVisible, and shared selected-index/list-field state.
        - [UID:0003U5][0x004f4920-0x004f4a77.ListPaneEnsureVisibleDestructorThunks](by-memory/0x004f4920-0x004f4a77.ListPaneEnsureVisibleDestructorThunks.md) 0x004f4920-0x004f4a77 | ensure-visible/destructor cluster | ListPaneEnsureVisibleDestructorThunks : reconstructable : 86% : very-strong : Exact ListPane ensure-visible and destructor/thunk child; live IDA confirms modeled `0x004f4920`, adjustor thunks `0x004f49e0`/`0x004f49eb`, scalar deleting destructor `0x004f4a00`, vtable refs at `0x0061ce84`/`0x0061cf0c`/`0x0061cf3c`, scroll adjustment behavior, owned-list cleanup, optional delete, and boundary at existing `0x004f4a77-0x004f4a80` padding.
```

## Validation Order

Run from `source-3/project-documentation` after creating/editing docs:

> Executable block R001 was removed from this report and preserved verbatim in [000194-listpane-source-split-audit-removed.md](000194-listpane-source-split-audit-removed.md). The archived block is non-authoritative and must not be executed.

After `memory_ranges.py report`, rerun or refresh `project-level/-auto-completion-stats.md` by the normal supervisor stats workflow. Expected result: [UID:000194] should disappear from `Low_Completion` and `Low_Both`; by-memory tool should stay clean for Barrier/General/Filename/Advanced sections.

## Rejected Alternatives

- **Keep [UID:000194] reconstructable aggregate with only a score bump:** rejected. Exact child boundaries are now strong enough, and leaving one 4135-byte reconstructable leaf preserves the only current auto-completion low row.
- **Create six standalone raw helper pages:** rejected. IDA has no function objects, `xrefs_to` has no start refs, PE scan has no VA/RVA/direct-branch hits, and original names are not recovered. Standalone pages would either be below-gate or overstate liveness.
- **Route helpers through derived feature panes:** rejected. Broad caller fanout and field layout tie the bodies to reusable `ListPane`; Article/Chatting/ServerItemMenu/SelectionState generated owners are pollution.
- **Merge into `ScrollablePane` / `ScrollBar.cpp`:** rejected. The code depends on scroll state but owns item list, selection, hit-test, paint, and row geometry semantics.
- **IDA DB repair:** not recommended. Creating functions at the raw starts would be a presentation convenience, not source evidence, and would obscure the no-route finding.

## Remaining Blockers After Execution

- Final C++ remains blocked by original method names, precise class field names, and raw helper reachability.
- The `SimpleListPane` fold-vs-separate source-file decision remains a support-doc migration question, not a blocker for reclassifying [UID:000194].
- The raw bodies at `0x004f3bb0`, `0x004f3be0`, `0x004f3cb0`, `0x004f3d00`, `0x004f4820`, and `0x004f4910` are documented as source-owned retained bytes, but their lack of caller/pointer/branch route still prevents standalone final-source treatment.

## No Direct Edit Confirmation

For this B001 assignment I created only this research report. I did not edit by-* documentation, generated reports, IDA DB, `by-memory/-coverage-report.md`, or tool configuration files.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/000194-listpane-source-split-audit.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:19","uid":"000194"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000194-listpane-source-split-audit-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/000194-listpane-source-split-audit.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000194"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
