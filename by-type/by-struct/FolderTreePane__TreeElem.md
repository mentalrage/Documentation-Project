*** UID:0001UJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00005A | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00005A | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// FolderTreePane::TreeElem is declared once in FolderTreePane.h by UID00005A;
// this support page intentionally emits no duplicate type definition.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# FolderTreePane::TreeElem

## Current Accepted UID0004YK Payload Construction

TreeElem is the 12-byte Folder payload, not the full 0x24 tree node. Its inline default constructor initializes only childrenLoaded and expanded to zero; name default-constructs, while rowIndex, depth, and implicit alignment bytes are not initialized. The surrounding TreeNode<TreeElem> owns the five generic links and disabled byte. This split explains the reset stores without synthetic reserved fields or an authored TreeStorage wrapper.

## Status

- Confidence: very strong for the exact 12-byte payload, pointer-backed name, row/depth/loaded/expanded fields, and nested class/file route; original PDB member spelling remains unavailable.
- Owner class: [UID:00005A][FolderTreePane](by-class/FolderTreePane.md)
- Owner file: [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md)
- Related memory: [UID:000157][0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md), plus exact 36-byte support children [UID:0002MW][0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct](by-memory/0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct.md), [UID:000447][0x004b5cc0-0x004b5ce5.FolderTreeElemRangeDestroy](by-memory/0x004b5cc0-0x004b5ce5.FolderTreeElemRangeDestroy.md), [UID:000449][0x004b5d20-0x004b5ddf.FolderTreeElemRangeCopyConstruct](by-memory/0x004b5d20-0x004b5ddf.FolderTreeElemRangeCopyConstruct.md), and [UID:00044B][0x004b5e80-0x004b5ebc.FolderTreeElemVectorStorageFree](by-memory/0x004b5e80-0x004b5ebc.FolderTreeElemVectorStorageFree.md)
- Current generated aliases such as `TreeStorageFolderTreeElemRecord` describe the enclosing node and are retained only as historical reverse-engineering names.
- Reconstructable: true. This NexusTK-authored 12-byte nested payload emits exactly once through UID00005A and UID0000JG; its current report-stage score is `91/94`.

## Historical 2026-07-14 B001 Hidden-State Finalization

The complete bounded reader/writer audit finalizes offset `+0x20` as `hidden`. Path selection at `0x004b2846`, per-node paint at `0x004b58e6`, and UID0002N0 at `0x004b5bf9` all skip a record when the byte is nonzero. UID0002MY root reset and lazy expansion initialize it to zero. UID0002MW at `0x004b563b/0x004b5641` and range copy at `0x004b5db8` preserve it while omitting the reserved bytes. No bounded family write sets it nonzero, and no deletion-only consumer exists.

The accepted declaration therefore uses `unsigned char hidden` while retaining the exact 36-byte layout. `isHidden` is the superseded B014 emitted spelling, `visibleTraversalSkip` is a descriptive historical alias, `hiddenOrDeleted` / `deleted` are rejected, and `isVisible` is rejected for inverse polarity. This name decision does not alter `previousSiblingIndex`'s explicitly inferred status or the reserved-byte exclusions.

## Historical 2026-06-30 B010 Formal Declaration And Empty-Emitter Cleanup

B010's accepted [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) FolderTreePane empty-emitter family implementation promotes the prior review-only declaration into the formal `RECONSTRUCTION_CPP CODE` block and raises this page from `86/89` to `88/91`. The declaration is intentionally nested under [UID:00005A][FolderTreePane](by-class/FolderTreePane.md) and emits through the class/file route; no owner or emitter change is made.

Historical MCP session `supervisor_resume_20260629` confirmed the remaining empty-family context: [UID:000346][0x004b3850-0x004b3ae2.FolderTreeHitTestTraversal](by-memory/0x004b3850-0x004b3ae2.FolderTreeHitTestTraversal.md) and [UID:000347][0x004b3af0-0x004b3d41.FolderTreeVisibleNavigationSearch](by-memory/0x004b3af0-0x004b3d41.FolderTreeVisibleNavigationSearch.md) use the same deque-backed visible traversal pattern as the accepted content/paint traversals; [UID:00034H][0x004b5810-0x004b59d5.FolderTreePaintNodeHelper](by-memory/0x004b5810-0x004b59d5.FolderTreePaintNodeHelper.md) consumes `name`, `rowIndex`, `depth`, and `expanded` while drawing each row. Its old description of [UID:000158][0x004b5650-0x004b5669.FolderTreePaneTreeDestructor](by-memory/0x004b5650-0x004b5669.FolderTreePaneTreeDestructor.md) as only constructor EH cleanup is superseded: UID000158 is retained complete-object Tree destructor support directly owned by UID0000F9, not a TreeElem method.

Accepted 2026-07-14 evidence preserves this struct's exact role in destruction. UID000158 receives the containing `Tree<FolderTreePane::TreeElem>` object, not a TreeElem pointer. It selects `TreeStorage` at Tree `+4`; UID0002MX then walks 36-byte TreeElem records, destroys only each embedded `SimpleUString name` at record `+0x14`, validates/frees storage, and zeros begin/end/capacity before UID000158 tail-calls `LObject` teardown. The class's inline virtual destructor regenerates that sequence; this nested record's formal declaration, score, owner, emitter, and fields remain unchanged.

The `[[CHILDREN]]` route is deliberate: exact children such as copy-constructor support and storage/template users continue surfacing through the nested record declaration rather than as unresolved standalone helpers. `previousSiblingIndex` remains explicitly inferred because direct evidence is weaker than for `lastChildIndex` and `nextSiblingIndex`; `hidden` is the finalized source-facing name for the nonzero visible-traversal exclusion byte at `+0x20`.

## Historical Layout Hypothesis Superseded By UID0002MZ

Generated storage helpers and IDA decompilation agree that each tree node record is 36 bytes (`0x24`). The first five dwords are tree links/state, followed by a `SimpleUString`-style name object and visible-row metadata.

| Offset | Size | Provisional field | Evidence |
| --- | --- | --- | --- |
| `0x00` | 4 | `parentIndex` | `MoveToParent` reads this field; root is initialized to `-1`. |
| `0x04` | 4 | `firstChildIndex` | `MoveToFirstChild` reads this field; root/reset initializes to `-1`. |
| `0x08` | 4 | `lastChildIndex` | `FindFirstVisibleChild` seeds this with the first inserted child and later updates the parent record when another child is appended. |
| `0x0c` | 4 | `previousSiblingIndex` | Link/state field copied by storage helpers; Batch 127 insertion-context review supports previous-sibling semantics, but direct traversal evidence is weaker than for `lastChildIndex` and `nextSiblingIndex`, so the name remains explicitly inferred. |
| `0x10` | 4 | `nextSiblingIndex` | `MoveToNextVisibleSibling` reads this field. |
| `0x14` | 4 | `name` | Ref-counted/simple string handle copied by `sub_582A90`, destroyed by `sub_582B70`, and read by `GetNodeBounds` through `sub_584540`. |
| `0x18` | 2 | `rowIndex` | `GetNodeBounds` multiplies this signed word by `16` for the top Y coordinate. |
| `0x1a` | 2 | `depth` | `GetNodeBounds` multiplies this signed word by `16` for left indentation. |
| `0x1c` | 1 | `childrenLoaded` | `FindFirstVisibleChild` / best source-facing `ExpandNode` checks this before enumerating children and sets it to `1` after a successful lazy directory scan. |
| `0x1d` | 1 | `expanded` | `ExpandNode` sets this when expansion succeeds; `CollapseNode` clears `node + 0x1d`; key/mouse logic reads the same flag. |
| `0x1e` | 2 | padding/reserved | Not named yet. |
| `0x20` | 1 | `hidden` | Three semantic readers skip nonzero records; root/new records initialize zero; copy/relocation preserves the byte; no nonzero or deletion-only route exists. |
| `0x21` | 3 | padding/reserved | Required to reach 36-byte size. |

## Historical Binary Evidence Under Superseded Monolithic TreeElem Labels

The dated evidence below often calls each 36-byte node `TreeElem` or attributes vector helpers to `TreeStorage`. Current source mapping keeps that evidence but reads each record as `TreeNode<FolderTreePane::TreeElem>`, with only the 12-byte `data` payload authored by FolderTreePane and vector mechanics compiler-covered from UID0004YK.

- `TreeStorage_struct_FolderTreePane__TreeElem_::InsertAt` copy-constructs records at 36-byte stride and copy-constructs/destroys the `SimpleUString` at offset `0x14`.
- `Tree_struct_FolderTreePane__TreeElem_::ResetToSingleRoot` creates one root record, initializes the first five link dwords to `-1`, clears `childrenLoaded`, `expanded`, and `hidden`, and deliberately does not initialize `rowIndex`, `depth`, or reserved padding in that reset path.
- `TreeItor_struct_FolderTreePane__TreeElem_::MoveToParent`, `MoveToFirstChild`, and `MoveToNextVisibleSibling` read offsets `0x00`, `0x04`, and `0x10`.
- Older generated overlays disagreed on names near `0x1c-0x21`; current direct binary evidence resolves `childrenLoaded`, `expanded`, and `hidden`. Reserved bytes remain layout notation and are not copied source state.
- 2026-05-31 IDA MCP `lookup_funcs` confirms exact starts/sizes for the main layout users: insert `0x004b3d50` size `0x254`, copy constructor helper `0x004b55e0` size `0x6d`, storage destructor `0x004b56e0` size `0x7f`, reset-to-root `0x004b5b00` size `0xae`, iterator first-child `0x004b5bb0` size `0x20`, next-visible-sibling `0x004b5bd0` size `0x43`, and parent `0x004b5c20` size `0x1f`.
- 2026-05-31 IDA MCP decompilation of `0x004b55e0` proves the 36-byte record copy shape: five dwords at `+0x00..+0x10`, string handle at `+0x14`, words at `+0x18/+0x1a`, bytes at `+0x1c/+0x1d`, and byte at `+0x20`.
- 2026-05-31 IDA MCP decompilation of `0x004b5b00` destroys each record string at `record + 0x14`, rewinds storage, and creates one root record. Direct IDA byte read of `xmmword_619660` shows the first four root dwords are all `-1`, with the fifth dword also initialized to `-1` by the local `v6` before insertion.
- 2026-06-28 B009 accepted reset evidence from MCP session/database `agent_b009_0002my_20260628` refines that root initialization: [UID:0002MY][0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot](by-memory/0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot.md) default-constructs the local `name`, loads four `-1` dwords from `xmmword_619660`, stores the fifth `nextSiblingIndex` sentinel as a local `-1`, clears the loaded/expanded bytes at `+0x1c/+0x1d` and the hidden byte at `+0x20`, and has no writes to `rowIndex`, `depth`, or the reserved bytes. That is why the formal reset body uses `FolderTreePane::TreeElem root;` rather than value-initializing `root`.
- 2026-06-28 B015 accepted content-dimension traversal evidence from MCP session/database `agent_b009_0002my_20260628` confirms [UID:000344][0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal](by-memory/0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal.md) reads `parentIndex` at `+0x00` while computing depth, reads `lastChildIndex` at `+0x08` and inferred `previousSiblingIndex` at `+0x0c` while pushing expanded children, reads `name` at `+0x14` for text-width measurement, writes `rowIndex` at `+0x18` and `depth` at `+0x1a`, reads `expanded` at `+0x1d`, and does not read `TreeElem+0x20`. The visible-skip byte remains proven by `MoveToNextVisibleSibling`, not by this content-dimension traversal helper.
- 2026-06-28 B007 accepted paint traversal evidence from MCP session/database `agent_b009_0002my_20260628` confirms [UID:000345][0x004b3650-0x004b3848.FolderTreePaintTraversalCallback](by-memory/0x004b3650-0x004b3848.FolderTreePaintTraversalCallback.md) reads `lastChildIndex` at `+0x08`, follows inferred `previousSiblingIndex` at `+0x0c` while pushing children into its pending deque, and does not read `TreeElem+0x20`. The visible-skip byte remains proven by `MoveToNextVisibleSibling`, not by the paint traversal helper. Per-node paint state still routes through [UID:00034H][0x004b5810-0x004b59d5.FolderTreePaintNodeHelper](by-memory/0x004b5810-0x004b59d5.FolderTreePaintNodeHelper.md), which reads `name`, row/depth, and expansion state.
- 2026-05-31 IDA MCP decompilation confirms iterator accessors: `0x004b5bb0` reads `record + 0x04` as first child, `0x004b5bd0` reads `record + 0x10` as next sibling and skips records with byte `+0x20` set, and `0x004b5c20` reads `record + 0x00` as parent.
- 2026-05-31 IDA MCP decompilation confirms UI field use: `CollapseNode` at `0x004b2540` clears byte `+0x1d`, and `GetNodeBounds` at `0x004b3010` uses word `+0x1a` for left indentation and word `+0x18` for row Y position.
- 2026-06-08 Batch 127 IDA MCP decompilation of `FindFirstVisibleChild` at `0x004b1d50` confirms byte `+0x1c` gates lazy child enumeration and is set to `1` after the child directory scan, while byte `+0x1d` is set when the node becomes expanded. The same pass shows the first/last child linkage: a first inserted child updates parent offsets `+0x04` and `+0x08`, later sibling appends update the previous node's `+0x10` next link and the parent's `+0x08` last-child link.
- Batch 127 also reconfirmed `0x004b55e0` as the exact copy-constructor helper for this 36-byte record and `0x004b56e0` as the storage destructor that destroys only the embedded string handle at `+0x14` before freeing storage.
- 2026-06-26 B009 split evidence adds exact support children for the same layout: [UID:000447][0x004b5cc0-0x004b5ce5.FolderTreeElemRangeDestroy](by-memory/0x004b5cc0-0x004b5ce5.FolderTreeElemRangeDestroy.md) destroys `record + 0x14` at 36-byte stride, [UID:000449][0x004b5d20-0x004b5ddf.FolderTreeElemRangeCopyConstruct](by-memory/0x004b5d20-0x004b5ddf.FolderTreeElemRangeCopyConstruct.md) copy-constructs five leading dwords, `name`, row/depth words, and flag bytes, and [UID:00044B][0x004b5e80-0x004b5ebc.FolderTreeElemVectorStorageFree](by-memory/0x004b5e80-0x004b5ebc.FolderTreeElemVectorStorageFree.md) frees `36 * count` storage with MSVC large-allocation validation.
- 2026-06-28 B006 accepted [UID:0002MV][0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt](by-memory/0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt.md) evidence from resumed MCP session/database `agent_b009_0002my_20260628` reconfirms that storage insertion consumes this accepted 36-byte record layout. The insert body computes indexes and sizes by dividing pointer differences by `36`, copy-constructs the inserted slot through [UID:0002MW][0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct](by-memory/0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct.md), uses [UID:000449][0x004b5d20-0x004b5ddf.FolderTreeElemRangeCopyConstruct](by-memory/0x004b5d20-0x004b5ddf.FolderTreeElemRangeCopyConstruct.md) for prefix/suffix relocation, cleans old names through `sub_582B70(record + 0x14)`, and releases old storage after relocation. The [UID:0002MW][0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct](by-memory/0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct.md) and [UID:000449][0x004b5d20-0x004b5ddf.FolderTreeElemRangeCopyConstruct](by-memory/0x004b5d20-0x004b5ddf.FolderTreeElemRangeCopyConstruct.md) helper decompiles copy field values at `+0x00..+0x10`, `+0x14`, `+0x18/+0x1a`, `+0x1c/+0x1d`, and `+0x20`; they do not copy padding/reserved bytes at `+0x1e/+0x1f` or `+0x21-+0x23`. This keeps the reserved rows as layout notation, not proven copied source members.
- 2026-06-29 B010 accepted [UID:0002MW][0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct](by-memory/0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct.md) evidence under restored MCP session `992d23de` resolves the single-record copy helper as marker-only compiler-emitted support through this `FolderTreePane::TreeElem` declaration. Current `lookup_funcs`, `xrefs_to`/`find code_ref`, `callees`, decompile/disassembly, and byte checks confirm range `0x004b55e0-0x004b564d`, five callers (`0x004b2271`, `0x004b23ca`, `0x004b3e72`, `0x004b3ea7`, `0x004b5b81`), sole `SimpleUString` copy callee `0x00582a90`, predecessor padding `0x004b55d3-0x004b55e0`, successor padding `0x004b564d-0x004b5650`, and the same copied field set as above. The accepted formal output is a trace marker, not a standalone copy-constructor body; `TreeStorage` and template pages are caller/support context, not the direct owner of the copied record.

## Historical Superseded 2026-06-19 B008 Source-Quality Implementation Sync

Accepted B008 reanalysis promotes the field names above from generic provisional names to the best source-facing names for documentation and future C++:

```cpp
struct FolderTreePane::TreeElem {
    int parentIndex;          // +0x00
    int firstChildIndex;      // +0x04
    int lastChildIndex;       // +0x08
    int previousSiblingIndex; // +0x0c, inferred
    int nextSiblingIndex;     // +0x10
    SimpleUString name;       // +0x14
    short rowIndex;           // +0x18
    short depth;              // +0x1a
    unsigned char childrenLoaded; // +0x1c
    unsigned char expanded;       // +0x1d
    unsigned char reserved1[2];   // +0x1e
    unsigned char isHidden;       // +0x20, visible-traversal skip flag
    unsigned char reserved2[3];   // +0x21
};
```

Rejected alternatives are now explicit: `+0x08` is not `nextSiblingIndex` because insertion updates parent `+0x08` as the last-child link, while sibling traversal uses `+0x10`; `+0x20` should not be called `deleted` without delete-path evidence; and the inconsistent generated `FolderTreeNodeRecord` overlays are weaker than the IDA-backed 36-byte copy/destruct/traversal evidence. `TreeElem` stays nested under [UID:00005A][FolderTreePane](by-class/FolderTreePane.md), emitted through the class/file route, while exact original field spelling and reusable template header factoring keep the score below final-audit.

B015's accepted [UID:000344][0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal](by-memory/0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal.md) implementation uses these source-facing field names directly in emitted C++: `parentIndex`, `lastChildIndex`, `previousSiblingIndex`, `name`, `rowIndex`, `depth`, and `expanded`. Preserve the negative evidence that this helper does not read `isHidden` / `visibleTraversalSkip`; hidden-row skipping remains tied to iterator traversal rather than the content-dimension body.

## Historical Superseded 2026-06-29 B010 Copy-Constructor Marker Sync

B010's accepted [UID:0002MW][0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct](by-memory/0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct.md) implementation keeps the copy-constructor support routed through this nested record. Restored MCP session `992d23de` confirms the helper copies `parentIndex`, `firstChildIndex`, `lastChildIndex`, inferred `previousSiblingIndex`, `nextSiblingIndex`, copy-constructs `name`, copies `rowIndex`, `depth`, `childrenLoaded`, `expanded`, and `isHidden` / `visibleTraversalSkip`, and does not copy the reserved bytes at `+0x1e/+0x1f` or `+0x21-+0x23`.

The formal [UID:0002MW][0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct](by-memory/0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct.md) output is marker-only because the physical function is compiler-emitted support for this record and its storage/template users. Do not replace it with a raw `sub_582A90` helper body or an out-of-line handwritten copy constructor until a future declaration/header pass proves that source shape; current source-quality representation is the `TreeElem` declaration plus ordinary copy use in storage insertion/reset paths.

## Historical Superseded 2026-06-19 B014 TreeItor Field-Use Sync

B014 reanalysis of [UID:0000FB][TreeItor_struct_FolderTreePane__TreeElem_](by-class/TreeItor_struct_FolderTreePane__TreeElem_.md) confirms this record is the payload type read by the concrete iterator, not an iterator-owned layout. The iterator methods consume these exact fields:

| Iterator method | Field evidence | Current source-facing name |
| --- | --- | --- |
| `TreeItor<FolderTreePane::TreeElem>::MoveToParent()` | Reads record offset `+0x00`; direct caller at `0x004b2c92`. | `parentIndex` |
| `TreeItor<FolderTreePane::TreeElem>::MoveToFirstChild()` | Reads record offset `+0x04`; direct caller at `0x004b2cbe`. | `firstChildIndex` |
| `TreeItor<FolderTreePane::TreeElem>::MoveToNextVisibleSibling()` | Reads record offset `+0x10`, assigns each candidate sibling into the iterator, and loops while target byte `+0x20` is nonzero; direct caller at `0x004b23f2`. | `nextSiblingIndex` and `hidden` |

The 2026-06-19 B014 `isHidden` recommendation is historical. The completed family-wide audit now finalizes `hidden`: nonzero excludes the record from visible sibling/path/connector traversal, zero is written for root/new records, and copy helpers preserve the state. `hiddenOrDeleted`, `deleted`, inverse-polarity `isVisible`, and padding/unused are rejected.

## Score And Assignment Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 91 | Exact 12-byte payload, nested owner/file route, one-definition disposition, pointer-backed name, payload fields/alignment, and enclosing-node relationship are documented. |
| Confidence | 94 | Construction, insertion, copy, destruction, expansion, path, paint, bounds, iterator, and cross-specialization size evidence agree; original private member spelling lacks PDB proof. |
| Assignment | [UID:00005A][FolderTreePane](by-class/FolderTreePane.md) | The record remains nested under FolderTreePane and emits through the existing class/file route; no owner, emitter, nesting, or source-file change is required. |

## Historical Superseded 2026-06-16 Source-Quality Recheck

Live IDA MCP session `b001_0001KM_20260616` and the active generated tree sources were checked for final member naming and C++ eligibility:

- `lookup_funcs` still reports the core users at the expected boundaries: `0x004b1d50` size `0x7ea`, `0x004b2540` size `0x35`, `0x004b3010` size `0x74`, `0x004b3d50` size `0x254`, `0x004b55e0` size `0x6d`, `0x004b56e0` size `0x7f`, `0x004b5b00` size `0xae`, `0x004b5bb0` size `0x20`, `0x004b5bd0` size `0x43`, and `0x004b5c20` size `0x1f`.
- `type_query` and `search_structs` for `FolderTreePane` and `TreeElem` found no local NexusTK UDT, so IDA does not preserve the original `TreeElem` declaration or field names.
- `source-3/simroot_v2/class_FolderTreePane.cpp` was checked as generated-source evidence. It consistently uses the nested spelling `TreeItor<FolderTreePane::TreeElem>`/`TreeElem`, and the active generated logic names the visible operations `FindFirstVisibleChild`, `CollapseNode`, and selected-tree navigation. However, its local `FolderTreeNodeRecord` overlays are inconsistent with the stronger IDA-backed field map: one overlay names `+0x08` as `nextSiblingIndex` and leaves later fields as `reserved`, while the IDA pass keeps `+0x08` as last-child and `+0x10` as next-sibling.
- `source-3/simroot_v2/class_TreeStorage_struct_FolderTreePane__TreeElem_.cpp` was checked. It has a `static_assert(sizeof(TreeStorageFolderTreeElemRecord) == 36)` and models copy/destruction/allocation around `TreeStorageFolderTreeElemRecord`, but the record fields are still generated `field_00` style names in the destructor region.
- `source-3/simroot_v2/class_TreeItor_struct_FolderTreePane__TreeElem_.cpp` was checked. It agrees with IDA that `MoveToFirstChild` reads `36 * index + 4`, `MoveToParent` reads `36 * index + 0`, and `MoveToNextVisibleSibling` owns the next-visible traversal, but it does not recover the original field names.

The nested owner and emitter route remain correct. Final C++ remains blank because the IDA layout is strong but generated/source names are not yet final-quality enough for a declaration block.

## Cross-References

- [UID:00005A][FolderTreePane](by-class/FolderTreePane.md)
- [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md)
- [UID:0000FC][TreeStorage_struct_FolderTreePane__TreeElem_](by-class/TreeStorage_struct_FolderTreePane__TreeElem_.md)
- [UID:0000F9][Tree_struct_FolderTreePane__TreeElem_](by-class/Tree_struct_FolderTreePane__TreeElem_.md)
- [UID:000344][0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal](by-memory/0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal.md)
- [UID:000345][0x004b3650-0x004b3848.FolderTreePaintTraversalCallback](by-memory/0x004b3650-0x004b3848.FolderTreePaintTraversalCallback.md)
- [UID:00034H][0x004b5810-0x004b59d5.FolderTreePaintNodeHelper](by-memory/0x004b5810-0x004b59d5.FolderTreePaintNodeHelper.md)
- [UID:0002MY][0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot](by-memory/0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot.md)
- [UID:0000FB][TreeItor_struct_FolderTreePane__TreeElem_](by-class/TreeItor_struct_FolderTreePane__TreeElem_.md)
- [UID:0001WP][FolderTreePaneTreeTemplates](by-type/by-template/FolderTreePaneTreeTemplates.md)
- [UID:000447][0x004b5cc0-0x004b5ce5.FolderTreeElemRangeDestroy](by-memory/0x004b5cc0-0x004b5ce5.FolderTreeElemRangeDestroy.md)
- [UID:000449][0x004b5d20-0x004b5ddf.FolderTreeElemRangeCopyConstruct](by-memory/0x004b5d20-0x004b5ddf.FolderTreeElemRangeCopyConstruct.md)
- [UID:00044B][0x004b5e80-0x004b5ebc.FolderTreeElemVectorStorageFree](by-memory/0x004b5e80-0x004b5ebc.FolderTreeElemVectorStorageFree.md)

## 2026-07-29 UID0002MZ Exact Payload Reconciliation

- `FolderTreePane::TreeElem` is the exact 12-byte payload nested and emitted once through [UID:00005A][FolderTreePane](by-class/FolderTreePane.md); this page's formal CPP and H blocks are intentionally blank to avoid duplicate definition.
- Payload layout: four-byte pointer-backed `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > name` at `+0x00`; signed `short rowIndex` at `+0x04`; signed `short depth` at `+0x06`; `childrenLoaded` at `+0x08`; `expanded` at `+0x09`; implicit alignment at `+0x0a..+0x0b`.
- The surrounding generic `TreeNode<TreeElem>` owns five link indices at node `+0x00..+0x10`, this payload at node `+0x14`, and generic `disabled` at node `+0x20`, yielding the proven 36-byte concrete node.
- The name type is the one-pointer `mystr::StringBase` compiler family. The separate 24-byte SSO `SimpleUString` interpretation is rejected by the exact payload width.
- All prior 36-byte copy/reset/traversal evidence remains valuable but describes the enclosing node. The earlier monolithic 36-byte `TreeElem`, explicit source padding arrays, and concrete `hidden` payload member are preserved above only as superseded reconstruction history.
- Supervisor Gate 2B catalog entry `0365` created the matching `FolderTreePaneTreeElem` IDA analysis UDT at exact size `0x0c`: `StringBaseWide name +0`, `rowIndex +4`, `depth +6`, `childrenLoaded +8`, and `expanded +9`. The enclosing `FolderTreePaneTreeNode` is exact size `0x24`, places this payload at `+0x14`, and retains generic `disabled +0x20`.
- IDA's parser initially produced `0x0a`/`0x20` tails from unannotated U02/U03 declarations. The supervisor used `struct __declspec(align(4))` in IDA only, producing the intended implicit tails without synthetic padding members. Human-source formal C++ remains the natural declaration above and must not inherit that analysis-tool annotation or explicit padding arrays.
- Saved IDB `412DA7E8...519CD` supersedes the earlier no-local-UDT snapshots. Those older negative checks remain useful history about absent recovered PDB names, not current analysis-type state.

## Changes

### 2026-08-24 UID0004YK Gate 2A Vector-Model Correction

- UID000158 remains containing-Tree destructor evidence rather than a `FolderTreePane::TreeElem` method. Its evidence alone did not establish a source container type, but the completed dual-instance UID0004YK analysis now does: `Tree<T>` directly owns `std::vector<TreeNode<T> >`, and the Folder instance supplies the 12-byte payload inside each 36-byte node. Member, element, vector, base, vtable, EH, and scalar-wrapper teardown remain compiler consequences rather than handwritten payload methods.

### Historical Superseded Pre-UID0004YK Change Log

The dated entries below preserve their evidence chronology. Their former no-vector/custom-storage source conclusions are historical and are superseded by the dual-instance UID0004YK direct-vector model above.

- 2026-07-14 B001 UID0002N0 hidden-state implementation:
  - Changed score `88/91` to `90/93`; owner/emitter UID00005A, reconstructable true, blank position, and `[[CHILDREN]]` remain unchanged.
  - Applied the exact managed declaration with `hidden` at `+0x20`; preserved all link/name/row/depth/state fields, `previousSiblingIndex` inference, record size, and both reserved spans.
  - Added the complete path/paint/iterator read inventory, reset/new-record zero initialization, single/range-copy preservation, reserved-byte exclusions, no-nonzero-writer and no-deletion-only negative evidence, and rejected/historical aliases.

- 2026-07-14 B001 UID000158 record-lifetime synchronization:
  - Preserved `88/91`, owner/emitter UID00005A, reconstructable true, blank position, and the complete accepted TreeElem formal declaration.
  - Corrected UID000158 to retained containing-Tree destructor support and distinguished it from UID0002MX's per-record name destruction. Recorded Tree receiver, storage-at-`+4`, 36-byte stride, name-at-`+0x14`, free/zero behavior, and LObject tail teardown without changing any field inference.
  - Preserved negative evidence: UID000158 is not a struct-owned method, does not justify `std::vector`, and does not hand-author record/member/base compiler teardown.
- 2026-06-29 B010 [UID:0002MW][0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct](by-memory/0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct.md) implementation sync:
  - Score unchanged at `86/89`.
  - Added [UID:0002MW][0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct](by-memory/0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct.md) as exact single-record copy-constructor support for this nested record, with restored MCP session `992d23de` proof for copied fields, non-copied reserved padding, five callers, sole `SimpleUString` copy callee, and marker-only source routing through this `TreeElem` declaration.
  - Evidence: B010 restored MCP calls confirmed range `0x004b55e0-0x004b564d`, size `0x6d`, decompile/disassembly field order, support route through `InsertAt`/range-copy/reset, predecessor/successor `0xcc` padding, and absent original UDTs; no new field names were invented.

- 2026-06-28 B015 [UID:000344][0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal](by-memory/0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal.md) implementation support sync:
  - Score unchanged at `86/89`.
  - Added content-dimension traversal field-use evidence: [UID:000344][0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal](by-memory/0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal.md) writes `rowIndex` and `depth`, reads `parentIndex`, `lastChildIndex`, inferred `previousSiblingIndex`, `name`, and `expanded`, and does not read the `+0x20` hidden/visible-skip byte. That keeps `+0x20` tied to iterator visible-sibling traversal rather than content measurement.
  - Evidence: B015 MCP session/database `agent_b009_0002my_20260628` confirmed the target range, sole `CalculateContentDimensions` call, row/depth consumer, last-child/previous-sibling child loop, and absence of a `+0x20` read in the traversal body.

- 2026-06-28 B006 [UID:0002MV][0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt](by-memory/0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt.md) implementation support sync:
  - Score unchanged at `86/89`.
  - Added current MCP confirmation that the storage insert/grow path consumes the accepted 36-byte `FolderTreePane::TreeElem` layout, copy-constructs inserted and relocated records through [UID:0002MW][0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct](by-memory/0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct.md) / [UID:000449][0x004b5d20-0x004b5ddf.FolderTreeElemRangeCopyConstruct](by-memory/0x004b5d20-0x004b5ddf.FolderTreeElemRangeCopyConstruct.md), and cleans names at `+0x14` while preserving padding/reserved bytes as non-copied layout gaps.
  - Evidence: B006 resumed MCP session `agent_b009_0002my_20260628` confirmed the `0x004b3d50` decompile/disassembly, helper decompiles, caller contexts, and missing original UDTs; no new field names were invented.

- 2026-06-28 B007 [UID:000345][0x004b3650-0x004b3848.FolderTreePaintTraversalCallback](by-memory/0x004b3650-0x004b3848.FolderTreePaintTraversalCallback.md) implementation support sync:
  - Score unchanged at `86/89`.
  - Added paint traversal field-use evidence: [UID:000345][0x004b3650-0x004b3848.FolderTreePaintTraversalCallback](by-memory/0x004b3650-0x004b3848.FolderTreePaintTraversalCallback.md) directly consumes `lastChildIndex` and inferred `previousSiblingIndex` for child descent, while row/depth/name/expanded drawing state remains in [UID:00034H][0x004b5810-0x004b59d5.FolderTreePaintNodeHelper](by-memory/0x004b5810-0x004b59d5.FolderTreePaintNodeHelper.md). The pass also records negative evidence that [UID:000345][0x004b3650-0x004b3848.FolderTreePaintTraversalCallback](by-memory/0x004b3650-0x004b3848.FolderTreePaintTraversalCallback.md) does not read the `+0x20` hidden/visible-skip byte, so that field remains tied to the iterator next-visible-sibling helper.
  - Evidence: B007 MCP session/database `agent_b009_0002my_20260628` confirmed the target range, helper call at `0x004b375f`, last-child/previous-sibling child loop, and absence of a `+0x20` read in the traversal body.
- 2026-06-28 B009 [UID:0002MY][0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot](by-memory/0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot.md) implementation sync:
  - Score unchanged at `86/89`.
  - Added reset-root evidence that the formal reset body writes the five link fields to `-1`, clears `childrenLoaded`, `expanded`, and `isHidden`, and intentionally leaves `rowIndex`, `depth`, and reserved padding untouched because the live binary performs no writes to those fields after default string construction.
  - Evidence: B009 MCP session `agent_b009_0002my_20260628` confirmed reset decompilation/disassembly, `xmmword_619660` sentinel bytes, and the absence of row/depth writes in this path.

- 2026-06-26 B009 [UID:00022E][0x004b5c40-0x004b5efc.FolderTreePaneVectorSupportHelpers](by-memory/0x004b5c40-0x004b5efc.FolderTreePaneVectorSupportHelpers.md) support sync:
  - Score unchanged at `86/89`.
  - Added exact 36-byte support children [UID:000447][0x004b5cc0-0x004b5ce5.FolderTreeElemRangeDestroy](by-memory/0x004b5cc0-0x004b5ce5.FolderTreeElemRangeDestroy.md), [UID:000449][0x004b5d20-0x004b5ddf.FolderTreeElemRangeCopyConstruct](by-memory/0x004b5d20-0x004b5ddf.FolderTreeElemRangeCopyConstruct.md), and [UID:00044B][0x004b5e80-0x004b5ebc.FolderTreeElemVectorStorageFree](by-memory/0x004b5e80-0x004b5ebc.FolderTreeElemVectorStorageFree.md) as additional proof for the `TreeElem` record's name offset, field-copy shape, and storage width.
- 2026-06-19 B014 TreeItor field-use sync:
  - Score unchanged at `86/89`.
  - Summary/evidence: B014 tied the iterator methods directly to `parentIndex`, `firstChildIndex`, `nextSiblingIndex`, and `+0x20` visible-traversal skip semantics. The best source-facing `+0x20` name is now `isHidden` / `visibleTraversalSkip`, with `hiddenOrDeleted` retained only as historical/generated uncertainty until all writers are reconciled.

- 2026-06-08 A006 Batch 127 layout and parent-gate refresh:
  - What existed before: score `76/86`, reconstructable, with `AUTOGEN_PARENT_UID` blank and several flag/link fields still weakly named.
  - Changed to: score `85/88` and `AUTOGEN_PARENT_UID:00005A`.
  - Summary/evidence: live IDA decompilation of `FindFirstVisibleChild`, `CollapseNode`, `GetNodeBounds`, iterator helpers, copy construction, and storage destruction resolved the lazy-enumeration byte at `+0x1c`, expanded byte at `+0x1d`, last-child link at `+0x08`, next-sibling link at `+0x10`, hidden/deleted byte at `+0x20`, and string lifetime at `+0x14`. The direct class parent now clears the corrected gate.
- 2026-05-31:
  - What existed before: the page had a useful generated-layout hypothesis but was still scored `0/0`, had `RECONSTRUCTABLE` blank, and treated the string/metadata split at `+0x14` as uncertain.
  - Changed to: scored `76/86`, marked reconstructable, and refined the proven field split from IDA MCP decompilation of copy, reset, iterator, collapse, and bounds helpers.
  - Summary/evidence: IDA confirms the 36-byte record stride, five leading link/state dwords, 4-byte string handle at `+0x14`, row/depth words at `+0x18/+0x1a`, expanded byte at `+0x1d`, and hidden/deleted byte at `+0x20`. Final names for `+0x08`, `+0x0c`, and `+0x1c` remain below the 95+ threshold.
- 2026-06-16 A002 source-quality pass:
  - Before: `85/88`.
  - After: `86/89`.
  - Summary/evidence: live IDA MCP session `b001_0001KM_20260616` reconfirmed exact helper boundaries and no local `FolderTreePane::TreeElem` UDT; generated `class_FolderTreePane.cpp`, `class_TreeStorage_struct_FolderTreePane__TreeElem_.cpp`, and `class_TreeItor_struct_FolderTreePane__TreeElem_.cpp` were checked for declaration/name leads. They support nested ownership and 36-byte storage, but inconsistent local overlays keep final field names and emitted C++ below final-source quality.
