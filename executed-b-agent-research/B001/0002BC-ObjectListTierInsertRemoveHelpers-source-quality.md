** TARGET-REPORT-UID:0002BC **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002BC ObjectListTierInsertRemoveHelpers Source-Quality Research

Assignment: `B001-goal2-objectlist-tier-insert-remove-source-quality-0002BC-20260618`  
Agent: `Agent-B001`  
Primary target: [UID:0002BC] `by-memory/0x00536270-0x0053728e.ObjectListTierInsertRemoveHelpers.md`  
Required report path: `tools/leaser/Agents/Agent-B001/research/0002BC-ObjectListTierInsertRemoveHelpers-source-quality.md`

This is report-only research. No `by-*` documentation, generated reports, generated source, IDA database, or `by-memory/-coverage-report.md` files were edited.

## Recommendation Summary

Recommended target disposition:

- Keep `CANONICAL_OWNER:00009Q`.
- Keep `EMITTER_UIDS:00009Q`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Raise the primary target from `COMPLETION:85` / `CONFIDENCE:85` to `COMPLETION:86` / `CONFIDENCE:88`.
- Correct the stale coverage row from `78%` to `86%` if the metadata bump is applied. If the supervisor keeps the header at `85`, still replace the stale `78%` row with `85%`.
- Do not populate formal C++ in the combined [UID:0002BC] target. The island is real code, but the direct PE reachability pass shows that only `0x00537210` has an inbound direct code reference. The active insert/remove dispatchers inline the sibling high-tier cases. Emitting all 27 starts as standalone source methods would overstate source API shape.
- If the supervisor wants emitted source for this area, model the behavior in the dispatch targets and optionally split the one live out-of-line helper `0x00537210` as `ObjectList::RemoveFromQuaternaryGlobalList`.

The previous open questions are closeable as documentation issues:

- Raw-start reachability is resolved for every start from `0x00536270` through `0x00537250`.
- Only `sub_537210` is modeled/xrefed because it is the only direct out-of-line helper call target in the active dispatchers.
- `+0x38`, `+0x3c`, and `+0x40` should retain the existing structural field names `tertiaryGlobalList`, `quaternaryGlobalList`, and `quinaryGlobalList` until object-type taxonomy proves semantic names.
- The row-table/direct-tier taxonomy is stable enough for source placement.
- List vtable slots `+0x10`, `+0x14`, and `+0x1c` are confirmed as element fetch, insertion, and removal.
- `sub_5374D0`, `sub_4B7C50`, and `sub_4B7E80` have source-facing helper roles, but should be referenced as shared support helpers rather than emitted from this target.

## Evidence Base And Limits

Read and used:

- `tools/leaser/Agents/Supervisor.md`
- `tools/leaser/Agents/Agent-B001/goal.md`
- `tools/leaser/Agents/Agent-B001/notes.md`
- `project-documentation/by-structure.md`
- `tools/leaser/Agents/Agent-B001/inference_research.md`
- Primary target [UID:0002BC] `by-memory/0x00536270-0x0053728e.ObjectListTierInsertRemoveHelpers.md`
- Owner/support docs [UID:00009Q] `by-class/ObjectList.md`, [UID:0000M4] `by-file/ObjectList.md`, [UID:0001VG] `by-type/by-struct/ObjectListLayout.md`
- Parent/sibling docs [UID:00023F], [UID:00023E], [UID:0002CA], [UID:0002BB], [UID:0001D3], [UID:0002JS], [UID:0002JT]
- List support doc [UID:000079] `by-class/List.md`
- Local exported function JSON under `resources/exported_data/functions`
- Direct PE byte scan against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`

Live IDA/MCP was attempted via JSON-RPC initialization to `http://127.0.0.1:13337/mcp`, but the endpoint was unavailable (`Unable to connect to the remote server`). This report therefore uses existing IDA/Ghidra exported data, local by-doc evidence, and a direct read-only PE scan. The lack of live MCP is the main reason not to push this target beyond `86/88`.

PE scan baseline:

- Input binary: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Image base: `0x00400000`
- `.text`: VA `0x1000`, virtual size `0x20b4ac`, raw pointer `0x400`, raw size `0x20b600`
- `.rdata`: VA `0x20d000`, virtual size `0x5f0be`, raw pointer `0x20ba00`, raw size `0x5f200`
- `.data`: VA `0x26d000`, virtual size `0x2fe24`, raw pointer `0x26ac00`, raw size `0xd800`
- `.rsrc`: VA `0x29d000`, virtual size `0x15c38`, raw pointer `0x278400`, raw size `0x15e00`

Scan method:

- Scanned all `.text` bytes for direct `E8 rel32` calls and `E9 rel32` jumps resolving to every target start.
- Scanned the whole file for little-endian VA constants and RVA constants for every target start.
- This does not prove there are no computed references synthesized at runtime, but it closes the ordinary direct-call, tail-jump, switch-table, import-table, and static-function-pointer cases for this island.

## Raw-Start Reachability

Direct PE scan results:

| Start | Export/IDA state | Direct `call` hit | Direct `jmp` hit | Static VA/RVA pointer hit | Reachability conclusion |
|---|---:|---:|---:|---:|---|
| `0x00536270` | Ghidra only | none | none | none | no direct binary reference found |
| `0x005362b0` | Ghidra only | none | none | none | no direct binary reference found |
| `0x005362f0` | Ghidra only | none | none | none | no direct binary reference found |
| `0x00536330` | Ghidra only | none | none | none | no direct binary reference found |
| `0x00536400` | Ghidra only | none | none | none | no direct binary reference found |
| `0x005364d0` | Ghidra only | none | none | none | no direct binary reference found |
| `0x005365a0` | Ghidra only | none | none | none | no direct binary reference found |
| `0x00536670` | Ghidra only | none | none | none | no direct binary reference found |
| `0x00536740` | Ghidra only | none | none | none | no direct binary reference found |
| `0x00536810` | Ghidra only | none | none | none | no direct binary reference found |
| `0x005368e0` | Ghidra only | none | none | none | no direct binary reference found |
| `0x005369b0` | Ghidra only | none | none | none | no direct binary reference found |
| `0x00536a80` | Ghidra only | none | none | none | no direct binary reference found |
| `0x00536b50` | Ghidra only | none | none | none | no direct binary reference found |
| `0x00536c20` | Ghidra only | none | none | none | no direct binary reference found |
| `0x00536ca0` | Ghidra only | none | none | none | no direct binary reference found |
| `0x00536d60` | Ghidra only | none | none | none | no direct binary reference found |
| `0x00536e70` | Ghidra only | none | none | none | no direct binary reference found |
| `0x00536eb0` | Ghidra only | none | none | none | no direct binary reference found |
| `0x00536ef0` | Ghidra only | none | none | none | no direct binary reference found |
| `0x00537000` | Ghidra only | none | none | none | no direct binary reference found |
| `0x00537110` | Ghidra only | none | none | none | no direct binary reference found |
| `0x00537150` | Ghidra only | none | none | none | no direct binary reference found |
| `0x00537190` | Ghidra only | none | none | none | no direct binary reference found |
| `0x005371d0` | Ghidra only | none | none | none | no direct binary reference found |
| `0x00537210` | IDA `sub_537210` | `0x005320d6` | none | none | the only directly referenced start in this island |
| `0x00537250` | Ghidra only | none | none | none | no direct binary reference found |

Exported function JSON agrees with the PE scan:

- Every start from `0x00536270` through `0x00537250` has a local exported Ghidra function record.
- All starts except `0x00537210` have zero Ghidra callers and no IDA function name/size.
- `0x00537210` has IDA name `sub_537210`, IDA size `62`, Ghidra caller count `1`, and the single call site `0x005320d6` from `0x00531c10`.

The target's "only modeled/xrefed `sub_537210` caveat" should be rewritten as a resolved reachability fact:

- The unmodeled raw siblings are valid helper-shaped code sequences with consistent prologues and decompilation.
- They are not reached by direct calls, direct jumps, static VA constants, or static RVA constants in the current executable.
- The active type-dispatch routines inline equivalent logic for the adjacent cases, so the most likely source explanation is retained specialized copies or decompiler-detected raw starts rather than a hidden public source API.

## Function Inventory And Taxonomy

Terminology in this table:

- `row` means the first word returned by `sub_5374D0`, sourced from object offset `+0x104`.
- `column` means the second word returned by `sub_5374D0`, sourced from object offset `+0x100`.
- The existing ObjectList layout names still describe `minX`, `minY`, `gridWidth`, and `gridHeight`; the helper island's internal call order uses the position pair as `(row, column)` in `sub_4B7E80(row, column, bounds)`.
- Flat/direct tiers sort by `row`, then `column`.
- Row-table tiers index `rows[row - minRow]`; within a selected row list they sort by `column`.

| Start | Field/tier | Family | Operation | Source-facing behavior |
|---|---|---|---|---|
| `0x00536270` | `+0x38 tertiaryGlobalList` | direct global | lookup/key | Scans the direct list, returns `0x80000000 | index` on pointer match, else `0xffffffff`. |
| `0x005362b0` | `+0x3c quaternaryGlobalList` | direct global | lookup/key | Scans the direct list, returns `0x90000000 | index` on pointer match, else `0xffffffff`. |
| `0x005362f0` | `+0x40 quinaryGlobalList` | direct global | lookup/key | Scans the direct list, returns `0xa0000000 | index` on pointer match, else `0xffffffff`. |
| `0x00536330` | `+0x28 extendedRowLists` | row table | insert | Builds bounds with bottom pad `+10`, requires containment, selects row by `row - minRow`, inserts before first existing object with larger column. |
| `0x00536400` | `+0x24 tertiaryRowLists` | row table | insert | Builds normal bounds with bottom pad `+2`, requires containment, selects row by `row - minRow`, inserts by column. |
| `0x005364d0` | `+0x14 primaryCellList` | direct flat/cell | insert | Builds normal bounds with bottom pad `+2`, requires containment, inserts into flat list sorted by row then column. |
| `0x005365a0` | `+0x18 secondaryCellList` | direct flat/cell | insert | Same direct sorted insert pattern as `+0x14`. |
| `0x00536670` | `+0x1c primaryRowLists` | row table | insert | Normal row-table insert, bottom pad `+2`, row-indexed and column-sorted. |
| `0x00536740` | `+0x20 secondaryRowLists` | row table | insert | Normal row-table insert, bottom pad `+2`, row-indexed and column-sorted. |
| `0x00536810` | `+0x2c primaryGlobalList` | direct global | insert | Direct sorted insert with bounds containment. |
| `0x005368e0` | `+0x30 secondaryGlobalList` | direct global | insert | Direct sorted insert with bounds containment. |
| `0x005369b0` | `+0x34 alternateGlobalList` | direct global | insert | Direct sorted insert with bounds containment; field is optional in constructor/destructor docs. |
| `0x00536a80` | `+0x38 tertiaryGlobalList` | direct global | insert | Direct sorted insert with bounds containment. |
| `0x00536b50` | `+0x3c quaternaryGlobalList` | direct global | insert | Direct sorted insert with bounds containment. |
| `0x00536c20` | `+0x40 quinaryGlobalList` | direct global | insert | Direct sorted insert with no bounds predicate and no security-cookie/Rect helper calls. |
| `0x00536ca0` | `+0x28 extendedRowLists` | row table | remove | Builds bottom pad `+10` bounds, removes only from the computed row when contained; no all-row fallback. |
| `0x00536d60` | `+0x24 tertiaryRowLists` | row table | remove | Tries computed row when contained, then scans all allocated rows backward from `gridHeight + 4 - 1` to `0` if not found. |
| `0x00536e70` | `+0x14 primaryCellList` | direct flat/cell | remove | Scans flat list by pointer equality and calls `List::RemoveAt(index, 1)`. |
| `0x00536eb0` | `+0x18 secondaryCellList` | direct flat/cell | remove | Same direct remove pattern as `+0x14`. |
| `0x00536ef0` | `+0x1c primaryRowLists` | row table | remove | Tries computed row, then all-row backward fallback across `gridHeight + 4` rows. |
| `0x00537000` | `+0x20 secondaryRowLists` | row table | remove | Tries computed row, then all-row backward fallback across `gridHeight + 4` rows. |
| `0x00537110` | `+0x2c primaryGlobalList` | direct global | remove | Direct pointer-equality remove. |
| `0x00537150` | `+0x30 secondaryGlobalList` | direct global | remove | Direct pointer-equality remove. |
| `0x00537190` | `+0x34 alternateGlobalList` | direct global | remove | Direct pointer-equality remove. |
| `0x005371d0` | `+0x38 tertiaryGlobalList` | direct global | remove | Direct pointer-equality remove; no direct inbound references found. |
| `0x00537210` | `+0x3c quaternaryGlobalList` | direct global | remove | Direct pointer-equality remove; this is IDA `sub_537210` and has the one direct call from `0x005320d6`. |
| `0x00537250` | `+0x40 quinaryGlobalList` | direct global | remove | Direct pointer-equality remove; no direct inbound references found. |

## Why Only `sub_537210` Is Modeled/Xrefed

`0x00531c10` is the active type-dispatch remove routine documented by [UID:0002CA]. Its local exported decompilation shows:

- Case `9` uses `this->mbr_0x38` inline, scans the direct list, and reaches the shared `List::RemoveAt` label.
- Case `10` calls `meth_0x537210(this, (int)param_1)` and returns.
- Case `0xb` uses `this->mbr_0x40` inline, scans the direct list, and reaches the same shared removal label.
- The shared label calls through vtable slot `+0x1c`.

The direct PE scan independently confirms the only direct branch into this island is `call 0x00537210` at `0x005320d6`.

`0x005314a0`, the active insert dispatch helper, similarly inlines direct insert cases for `+0x38`, `+0x3c`, and `+0x40`; it calls `sub_5374D0`, `sub_4B7C50`, `sub_4B7E80`, and the security cookie helper, but has no direct calls to the raw insert helper starts `0x00536330` through `0x00536c20`.

Therefore the current docs' caveat should be resolved as:

> `sub_537210` is the only modeled/xrefed helper because it is the only direct out-of-line helper call retained by the active remove dispatcher. The sibling raw starts are valid specialized helper bodies but are not directly referenced by the current executable; adjacent active behavior is inlined into the dispatchers.

This rejects the "missing IDA xref" explanation for ordinary direct calls. It remains theoretically possible that an unusual runtime-computed address reaches one of the raw starts, but no static direct-call, direct-jump, VA-pointer, or RVA-pointer evidence supports that.

## High-Tier Field Names

The current best source-facing field names for the three high direct tiers are:

- `+0x38`: `tertiaryGlobalList`
- `+0x3c`: `quaternaryGlobalList`
- `+0x40`: `quinaryGlobalList`

Evidence:

- [UID:00009Q] `ObjectList.md`, [UID:0001VG] `ObjectListLayout.md`, [UID:0002JS] constructor, and [UID:0002JT] destructor agree that `+0x38`, `+0x3c`, and `+0x40` are additional always-allocated direct/global `List*` tiers.
- [UID:0001D3] accessors return `+0x38`, `+0x3c`, and `+0x40` as separate internal global lists.
- The helper island treats all three as direct `List*` fields, not `List**` row tables.
- The lookup prefixes are stable: `+0x38` maps to `0x80000000`, `+0x3c` maps to `0x90000000`, and `+0x40` maps to `0xa0000000`.

Rejected alternatives:

- Do not rename them to specific object-type names yet. The support set does not yet prove which render/object type at object offset `+0xf8` corresponds to each high direct tier.
- Do not use `MapPaneSpatialIndex` as owner or field prefix. Constructor/destructor/layout evidence shows these are ObjectList-owned fields.
- Do not invent `highGlobalList1/2/3`; the existing structural names already preserve order and are used by the current ObjectList docs.

Recommended support-doc note:

> The names `tertiaryGlobalList`, `quaternaryGlobalList`, and `quinaryGlobalList` are structural placeholder names for the direct global tiers at `+0x38`, `+0x3c`, and `+0x40`. They are currently the preferred source-facing names until object-type taxonomy proves semantic render-layer names.

## Row-Table Versus Direct-Tier Taxonomy

Confirmed row-table tiers:

- `+0x1c primaryRowLists`
- `+0x20 secondaryRowLists`
- `+0x24 tertiaryRowLists`
- `+0x28 extendedRowLists`

These are `List**` row arrays. They use:

- `sub_5374D0` to fetch object position.
- `sub_4B7C50` to build bounds.
- `sub_4B7E80` to test whether the object is within bounds.
- `row - minRow` to select a row-list pointer.
- List vslot `+0x10` to inspect elements.
- List vslot `+0x14` for insertions.
- List vslot `+0x1c` for removals.

The `+0x28` extended row tier differs from the other row tables:

- Insert and remove use bottom pad `+10`, matching the constructor's larger row allocation family.
- Remove at `0x00536ca0` removes only from the computed row when the object is in bounds; it does not perform the all-row fallback.

The `+0x1c`, `+0x20`, and `+0x24` row tiers use normal bottom pad `+2` for bounds and a `gridHeight + 4` fallback scan on remove.

Confirmed direct/flat tiers:

- `+0x14 primaryCellList`
- `+0x18 secondaryCellList`
- `+0x2c primaryGlobalList`
- `+0x30 secondaryGlobalList`
- `+0x34 alternateGlobalList`
- `+0x38 tertiaryGlobalList`
- `+0x3c quaternaryGlobalList`
- `+0x40 quinaryGlobalList`

These are `List*` fields, not row tables. Insertions keep the flat list sorted by the helper position pair, first word then second word. Removals scan by pointer equality.

Important correction for source prose:

- `+0x14` and `+0x18` are direct flat/cell lists in this island, not row-table arrays.
- The position helper returns two words used here as `(row, column)` rather than conventional `(x, y)`. This is visible because `sub_4B7E80(first, second, bounds)` compares the second argument against `minX/maxX` and the first argument against `minY/maxY`, and row-table selection uses `first - minY`.

## Shared Helper Roles

### `sub_5374D0`

Exported facts:

- Address: `0x005374d0`
- IDA name: `sub_5374D0`
- Size: `27`
- Ghidra signature: `undefined __thiscall meth_0x5374d0(LivingObjectPane * this, undefined4 * param_1)`
- IDA signature: `_DWORD *__thiscall(_DWORD *this, _DWORD *)`
- Caller counts: Ghidra `244`, IDA `244`

Behavior:

- Writes object offset `+0x104` to `out[0]`.
- Writes object offset `+0x100` to `out[1]`.
- Returns the output pointer in IDA's model.

Recommended source-facing signature:

```cpp
struct ObjectListPosition {
    int row;    // binary word 0, object offset +0x104
    int column; // binary word 1, object offset +0x100
};

ObjectListPosition* LivingObjectPane::GetObjectListPosition(ObjectListPosition* out);
```

If existing source docs later prove the original field names are `x`/`y`, the parameter names can be changed, but this island's algorithms should retain the observed order: first word indexes row lists and is sorted before the second word.

### `sub_4B7C50`

Exported facts:

- Address: `0x004b7c50`
- IDA name: `sub_4B7C50`
- Size: `31`
- Ghidra signature: `undefined __cdecl FUN_004b7c50(undefined4 * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5)`
- IDA signature: `int __cdecl(_DWORD *, int, int, int, int)`
- Caller counts: Ghidra `1731`, IDA `1731`

Behavior:

- Stores `out[0] = arg2`.
- Stores `out[1] = arg3`.
- Stores `out[2] = arg4`.
- Stores `out[3] = arg5`.

Recommended source-facing signature:

```cpp
struct RectBounds {
    int minColumn; // stored word 0, ObjectList passes minX
    int minRow;    // stored word 1, ObjectList passes minY
    int maxColumn; // stored word 2, ObjectList passes minX + gridWidth + pad
    int maxRow;    // stored word 3, ObjectList passes minY + gridHeight + pad
};

void SetRectBounds(RectBounds* out, int minColumn, int minRow, int maxColumn, int maxRow);
```

IDA's reconstruction leaves the fourth scalar in EAX, but call sites use this helper as a mutating bounds initializer and ignore the return value.

### `sub_4B7E80`

Exported facts:

- Address: `0x004b7e80`
- IDA name: `sub_4B7E80`
- Size: `39`
- Ghidra signature: `undefined4 __cdecl FUN_004b7e80(int param_1, int param_2, int * param_3)`
- IDA signature: `bool __cdecl(int, int, _DWORD *)`
- Caller counts: Ghidra `270`, IDA `270`

Behavior:

- Returns true when `bounds[0] <= param_2 && param_2 < bounds[2] && bounds[1] <= param_1 && param_1 < bounds[3]`.
- In ObjectList call sites this is `ContainsPoint(row, column, bounds)`.

Recommended source-facing signature:

```cpp
bool RectBoundsContainsPoint(int row, int column, const RectBounds* bounds);
```

The helper is shared outside ObjectList. Do not emit it from [UID:0002BC]; reference the existing Rect/geometry helper documentation.

## List Virtual Slots

[UID:000079] `List.md` supports the vtable slot names used by this island:

- `+0x10`: `List::GetElementAt`
- `+0x14`: `List::InsertAt`
- `+0x18`: `List::Append` (not directly used in this target)
- `+0x1c`: `List::RemoveAt`

Observed call forms in this island:

- Fetch: `(**(code **)(*list + 0x10))(index)` in Ghidra output. Source-facing use is `list->GetElementAt(index)`.
- Insert: `(**(code **)(*list + 0x14))(index, 1, &object)`. Source-facing use is `list->InsertAt(index, 1, &object)`.
- Remove: `(**(code **)(*list + 0x1c))(index, 1)`. Source-facing use is `list->RemoveAt(index, 1)`.

The decompiler often omits the explicit `this` register in the rendered virtual call; the virtual slot mapping is nevertheless consistent with the List class support doc and the argument shapes.

## Source-Facing Helper Signatures

These signatures are recommended descriptive names for documentation and possible future source reconstruction. They are not asserted as original source names.

```cpp
// Shared support helpers; do not emit from UID 0002BC.
ObjectListPosition* LivingObjectPane::GetObjectListPosition(ObjectListPosition* out); // sub_5374D0
void SetRectBounds(RectBounds* out, int minColumn, int minRow, int maxColumn, int maxRow); // sub_4B7C50
bool RectBoundsContainsPoint(int row, int column, const RectBounds* bounds); // sub_4B7E80

// Private source-shape helpers if the dispatcher targets are reconstructed.
static unsigned int FindObjectInDirectTier(List* list, LivingObjectPane* object, unsigned int keyPrefix);
static void InsertObjectInDirectTier(List* list, LivingObjectPane* object, const RectBounds* boundsOrNull);
static void InsertObjectInRowTable(List** rows, const RectBounds& bounds, LivingObjectPane* object);
static void RemoveObjectFromDirectTier(List* list, LivingObjectPane* object);
static void RemoveObjectFromExactRowTable(List** rows, const RectBounds& bounds, LivingObjectPane* object);
static void RemoveObjectFromRowTableWithFallback(List** rows, int rowCount, const RectBounds& bounds, LivingObjectPane* object);
```

If one method per tier is documented, use these signatures:

```cpp
unsigned int ObjectList::FindInTertiaryGlobalList(LivingObjectPane* object);      // 0x00536270, +0x38, prefix 0x80000000
unsigned int ObjectList::FindInQuaternaryGlobalList(LivingObjectPane* object);    // 0x005362b0, +0x3c, prefix 0x90000000
unsigned int ObjectList::FindInQuinaryGlobalList(LivingObjectPane* object);       // 0x005362f0, +0x40, prefix 0xa0000000
void ObjectList::InsertIntoExtendedRowLists(LivingObjectPane* object);            // 0x00536330, +0x28, bottom pad +10
void ObjectList::InsertIntoTertiaryRowLists(LivingObjectPane* object);            // 0x00536400, +0x24, bottom pad +2
void ObjectList::InsertIntoPrimaryCellList(LivingObjectPane* object);             // 0x005364d0, +0x14
void ObjectList::InsertIntoSecondaryCellList(LivingObjectPane* object);           // 0x005365a0, +0x18
void ObjectList::InsertIntoPrimaryRowLists(LivingObjectPane* object);             // 0x00536670, +0x1c
void ObjectList::InsertIntoSecondaryRowLists(LivingObjectPane* object);           // 0x00536740, +0x20
void ObjectList::InsertIntoPrimaryGlobalList(LivingObjectPane* object);           // 0x00536810, +0x2c
void ObjectList::InsertIntoSecondaryGlobalList(LivingObjectPane* object);         // 0x005368e0, +0x30
void ObjectList::InsertIntoAlternateGlobalList(LivingObjectPane* object);         // 0x005369b0, +0x34
void ObjectList::InsertIntoTertiaryGlobalList(LivingObjectPane* object);          // 0x00536a80, +0x38
void ObjectList::InsertIntoQuaternaryGlobalList(LivingObjectPane* object);        // 0x00536b50, +0x3c
void ObjectList::InsertIntoQuinaryGlobalList(LivingObjectPane* object);           // 0x00536c20, +0x40, no bounds predicate
void ObjectList::RemoveFromExtendedRowLists(LivingObjectPane* object);            // 0x00536ca0, +0x28, exact row only
void ObjectList::RemoveFromTertiaryRowLists(LivingObjectPane* object);            // 0x00536d60, +0x24, fallback scan
void ObjectList::RemoveFromPrimaryCellList(LivingObjectPane* object);             // 0x00536e70, +0x14
void ObjectList::RemoveFromSecondaryCellList(LivingObjectPane* object);           // 0x00536eb0, +0x18
void ObjectList::RemoveFromPrimaryRowLists(LivingObjectPane* object);             // 0x00536ef0, +0x1c, fallback scan
void ObjectList::RemoveFromSecondaryRowLists(LivingObjectPane* object);           // 0x00537000, +0x20, fallback scan
void ObjectList::RemoveFromPrimaryGlobalList(LivingObjectPane* object);           // 0x00537110, +0x2c
void ObjectList::RemoveFromSecondaryGlobalList(LivingObjectPane* object);         // 0x00537150, +0x30
void ObjectList::RemoveFromAlternateGlobalList(LivingObjectPane* object);         // 0x00537190, +0x34
void ObjectList::RemoveFromTertiaryGlobalList(LivingObjectPane* object);          // 0x005371d0, +0x38
void ObjectList::RemoveFromQuaternaryGlobalList(LivingObjectPane* object);        // 0x00537210, +0x3c, live direct call
void ObjectList::RemoveFromQuinaryGlobalList(LivingObjectPane* object);           // 0x00537250, +0x40
```

Recommended strategy: prefer the private helper signatures in reconstructed dispatcher code. Use one method per tier only as documentation labels or if the supervisor intentionally splits live and non-live helper bodies.

## Deduplication And Private-Helper Strategy

The binary contains 27 specialized helper bodies in this island:

- 3 direct-tier lookup/key helpers.
- 12 insert helpers.
- 12 remove helpers.

The source should not be reconstructed as 27 public ObjectList methods without qualification. Reasons:

- Direct PE scan found no direct inbound reference to 26 of the 27 starts.
- Active dispatchers inline equivalent code for many cases.
- Only `0x00537210` is demonstrably called as an out-of-line helper.
- The helper bodies are highly mechanical variants over field offset, row-table versus direct-tier storage, bounds pad, and fallback policy.

Recommended source-shape interpretation:

- Keep [UID:0002BC] as an ObjectList helper-cluster documentation target.
- Keep formal target C++ blank for the combined island.
- In eventual source output, reconstruct active behavior in [UID:00023E]/[UID:0002CA] dispatchers using private helper functions such as `RemoveObjectFromDirectTier`, `InsertObjectInDirectTier`, and row-table variants.
- Optionally split `0x00537210` if the supervisor wants a formal method for the one live out-of-line helper.

This approach preserves all binary details while avoiding a misleading public API surface.

## Heuristic / Inference Reanalysis And Validation

Evidence checked:

- Current target [UID:0002BC] open questions, metadata, raw-start inventory, and blank C++ section.
- Owner and layout support docs [UID:00009Q], [UID:0000M4], [UID:0001VG], constructor [UID:0002JS], destructor [UID:0002JT], and accessors [UID:0001D3].
- Sibling dispatch docs [UID:00023E] and [UID:0002CA].
- Sibling encoded-key helper docs [UID:0002BB].
- List support doc [UID:000079].
- Local exported JSON records for all starts from `0x00536270` through `0x00537250`.
- Local exported JSON records for `0x005314a0`, `0x00531c10`, `0x005374d0`, `0x004b7c50`, and `0x004b7e80`.
- Read-only direct PE scan over `NexusTK.exe` for `E8`/`E9` targets and static VA/RVA constants.

Validated current docs:

- Validates ObjectList ownership/emitter placement under [UID:00009Q].
- Validates `RECONSTRUCTABLE:TRUE` for source understanding.
- Validates that the target is a helper cluster belonging to ObjectList rather than List, Rect, or MapPane.
- Validates List slots `+0x10`, `+0x14`, and `+0x1c`.
- Validates row-table/direct-tier families and field offsets `+0x14` through `+0x40`.
- Validates the current note that only `sub_537210` is modeled/xrefed, but upgrades it from caveat to resolved fact.

Contradicted or refined current docs:

- The stale coverage row's `78%` no longer reflects the target's actual support level after raw-start reachability and helper roles were checked. It should become `86%` if the recommended target metadata is applied, or at least `85%` if metadata remains unchanged.
- Any prose implying lookup/insert sort order as conventional `(x, y)` should be corrected for this island. The helper returns and uses a first word from object `+0x104` and second word from object `+0x100`; row tables index by the first word and flat tiers sort by first word then second word.
- The unresolved "maybe missing IDA xref" explanation is weaker than the PE evidence. Ordinary static references are absent for all raw siblings except `0x00537210`.

Best current inferences:

- The unreferenced raw helpers are compiler-retained or decompiler-detected specialized copies of tier operations, not directly used source API entry points in the current executable.
- The source likely had shared private helper patterns or switch-local logic rather than public one-method-per-tier APIs.
- `+0x38`, `+0x3c`, and `+0x40` should keep structural names until the object-type taxonomy proves semantic names.
- The one live out-of-line helper at `0x00537210` corresponds to removing an object from `quaternaryGlobalList`.

Rejected alternatives:

- "IDA missed the xrefs": rejected for direct calls/jumps/static pointers because the direct PE scan found none for 26 raw starts.
- "All starts should emit as normal source methods": rejected because only one is called and the active dispatchers inline neighboring variants.
- "The high-tier lists can be semantically named now": rejected because current evidence proves structure and tier order, not object-type semantics.
- "ObjectList field `+0x14`/`+0x18` are row tables": rejected for this island because they are dereferenced as direct `List*`, not `List**`.
- "Rect helpers should be emitted from ObjectList": rejected because `sub_4B7C50` and `sub_4B7E80` have hundreds/thousands of callers and are shared geometry support.

Unresolved blockers:

- Live IDA/MCP was unavailable, so this report could not create fresh live labels or inspect live xref UI state.
- Original class/field names for object offsets `+0x100` and `+0x104` remain unresolved; the report uses `column` and `row` to reflect this island's observed use.
- Object-type taxonomy for `+0xf8` cases is still needed before `tertiaryGlobalList`/`quaternaryGlobalList`/`quinaryGlobalList` can receive semantic render-layer names.

Impact:

- Score: recommend [UID:0002BC] `86/88`, not higher because live MCP was unavailable and semantic object-type names remain unresolved.
- Owner: no change, [UID:00009Q] remains correct.
- Emitter: no change, `ObjectList.cpp` under [UID:00009Q] remains correct.
- Source placement: active behavior belongs in ObjectList dispatchers and private ObjectList helpers, not in Rect/List support files.
- C++: formal C++ should remain blank in this combined target. Optional split/emission is defensible only for the one live `0x00537210` out-of-line helper.

## First-Draft C++ Recommendation

Formal [UID:0002BC] C++ recommendation: do not populate the target's formal C++ block.

Reason:

- The target is a combined helper island with 27 specialized starts.
- The direct PE scan proves only `0x00537210` has a direct inbound call.
- The active dispatchers inline equivalent sibling behavior.
- Emitting this combined target as 27 source methods would create a misleading source-facing API.

Reference C++ for future dispatcher reconstruction or an optional `0x00537210` split:

```cpp
struct ObjectListPosition {
    int row;    // object offset +0x104
    int column; // object offset +0x100
};

struct RectBounds {
    int minColumn;
    int minRow;
    int maxColumn;
    int maxRow;
};

static bool RectBoundsContainsPoint(int row, int column, const RectBounds& bounds)
{
    return bounds.minColumn <= column && column < bounds.maxColumn &&
           bounds.minRow <= row && row < bounds.maxRow;
}

static RectBounds MakeObjectListBounds(const ObjectList* list, int bottomPad)
{
    RectBounds bounds;
    SetRectBounds(&bounds,
                  list->minX - 2,
                  list->minY - 2,
                  list->minX + list->gridWidth + 2,
                  list->minY + list->gridHeight + bottomPad);
    return bounds;
}

static int FindObjectSlot(List* list, LivingObjectPane* object)
{
    const int count = list->count;
    for (int index = 0; index < count; ++index) {
        LivingObjectPane** slot =
            static_cast<LivingObjectPane**>(list->GetElementAt(index));
        if (*slot == object) {
            return index;
        }
    }
    return -1;
}

static void RemoveObjectFromDirectTier(List* list, LivingObjectPane* object)
{
    const int index = FindObjectSlot(list, object);
    if (index >= 0) {
        list->RemoveAt(index, 1);
    }
}

static void InsertObjectInDirectTier(List* list,
                                     LivingObjectPane* object,
                                     const RectBounds* boundsOrNull)
{
    ObjectListPosition position;
    object->GetObjectListPosition(&position);

    if (boundsOrNull != nullptr &&
        !RectBoundsContainsPoint(position.row, position.column, *boundsOrNull)) {
        return;
    }

    int index = 0;
    const int count = list->count;
    while (index < count) {
        LivingObjectPane** slot =
            static_cast<LivingObjectPane**>(list->GetElementAt(index));
        ObjectListPosition existing;
        (*slot)->GetObjectListPosition(&existing);
        if (position.row < existing.row ||
            (position.row == existing.row && position.column < existing.column)) {
            break;
        }
        ++index;
    }

    list->InsertAt(index, 1, &object);
}

static void InsertObjectInRowTable(List** rows,
                                   const RectBounds& bounds,
                                   LivingObjectPane* object)
{
    ObjectListPosition position;
    object->GetObjectListPosition(&position);

    if (!RectBoundsContainsPoint(position.row, position.column, bounds)) {
        return;
    }

    List* rowList = rows[position.row - bounds.minRow];
    int index = 0;
    const int count = rowList->count;
    while (index < count) {
        LivingObjectPane** slot =
            static_cast<LivingObjectPane**>(rowList->GetElementAt(index));
        ObjectListPosition existing;
        (*slot)->GetObjectListPosition(&existing);
        if (position.column < existing.column) {
            break;
        }
        ++index;
    }

    rowList->InsertAt(index, 1, &object);
}

// The only live out-of-line helper in UID 0002BC if split/emitted:
void ObjectList::RemoveFromQuaternaryGlobalList(LivingObjectPane* object)
{
    RemoveObjectFromDirectTier(this->quaternaryGlobalList, object);
}
```

This draft is intentionally generic. The formal dispatcher targets should decide whether to inline the private helpers or emit them as local static functions in `ObjectList.cpp`.

## Recommended Target Metadata Changes

Placement: primary target header in `by-memory/0x00536270-0x0053728e.ObjectListTierInsertRemoveHelpers.md`.

Recommended replacement:

```text
COMPLETION:86
CONFIDENCE:88
CANONICAL_OWNER:00009Q
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00009Q
EMITTER_POSITION_OPTIONAL:
```

Rationale:

- Completion rises because raw-start reachability, high-tier field naming, helper roles, source-facing signatures, taxonomy, coverage correction, and no-code proof are now resolved.
- Confidence rises because the direct PE scan confirms the xref shape independently of exported JSON.
- The score should not exceed `88` confidence while live MCP is unavailable and high-tier semantic object-type names remain unresolved.

## Recommended Target Text Replacements

Placement: replace the current reachability/open-question prose in [UID:0002BC].

Recommended replacement section:

```md
## Reachability Resolution

All raw starts from `0x00536270` through `0x00537250` have exported local function records and helper-shaped bodies. A direct PE scan of `NexusTK.exe` found no `E8` direct-call target, `E9` direct-jump target, static VA constant, or static RVA constant for any raw start except `0x00537210`. The sole direct hit is `call 0x00537210` at `0x005320d6` from the active remove dispatcher `0x00531c10`.

`0x00537210` is IDA `sub_537210` and removes an object from the direct global tier at `+0x3c` (`quaternaryGlobalList`). The adjacent high-tier remove cases for `+0x38` and `+0x40` are inlined in `0x00531c10`; the active insert dispatcher likewise inlines the high-tier direct insert cases and does not call the raw insert helper starts. Therefore the sibling raw starts are documented as valid specialized helper bodies with no direct inbound static reference in the current executable, not as independently proven public source methods.
```

Placement: add after the field/tier table or evidence summary.

Recommended insertion:

```md
## Source-Facing Tier Names

The high direct tiers should currently use structural ObjectList field names:

- `+0x38` `tertiaryGlobalList`
- `+0x3c` `quaternaryGlobalList`
- `+0x40` `quinaryGlobalList`

These are structural placeholder names, not final semantic render-layer names. Constructor, destructor, layout, accessor, lookup-key, insert, and remove evidence all prove they are direct `List*` global tiers. Object-type taxonomy has not yet proved semantic names for the object classes assigned to these tiers.
```

Placement: replace the current open-question section.

Recommended replacement:

```md
## Open Questions

Resolved for this target:

- Raw-start reachability: closed. Only `0x00537210` has a direct inbound static code reference; all other raw starts in this island have no direct `call`/`jmp`/VA/RVA hit in the scanned executable.
- Why only `sub_537210` is modeled/xrefed: closed. It is the only out-of-line helper call retained by the active remove dispatcher; sibling high-tier behavior is inlined.
- High-tier field names: closed at structural-name level. Use `tertiaryGlobalList`, `quaternaryGlobalList`, and `quinaryGlobalList` until object-type taxonomy proves semantic names.
- Deduplication/private-helper strategy: closed for this combined target. Do not emit all 27 starts as standalone formal methods; reconstruct active dispatcher behavior with private helpers, and optionally split only live `0x00537210`.

Still external to this target:

- Final semantic object-type names for `+0x38/+0x3c/+0x40` require object-type taxonomy work outside this helper island.
- Formal C++ should remain blank in this combined target unless the supervisor splits the one live helper `0x00537210`.
```

## Coverage Row Correction

Placement: `by-memory/-coverage-report.md`, under the existing `0x00532f70-0x0053728e` ObjectList extended helper island children, replacing the stale [UID:0002BC] row currently showing `78%`.

Recommended replacement row if the metadata bump to `COMPLETION:86` is accepted:

```md
        - [UID:0002BC][0x00536270-0x0053728e.ObjectListTierInsertRemoveHelpers](by-memory/0x00536270-0x0053728e.ObjectListTierInsertRemoveHelpers.md) 0x00536270-0x0053728e | helper-cluster | ObjectListTierInsertRemoveHelpers : reconstructable : 86% : strong : ObjectList tier search/insert/remove helper cluster with all raw helper starts from `0x00536270` through `0x00537250` inventoried, direct PE scan confirming no `call`/`jmp`/VA/RVA references to any raw start except the sole direct call to modeled `sub_537210` at `0x005320d6`, ObjectList field offsets `+0x14..+0x40`, stable structural high-tier names `tertiaryGlobalList`/`quaternaryGlobalList`/`quinaryGlobalList` for `+0x38/+0x3c/+0x40`, row-table versus direct-tier helper taxonomy, List virtual slots `+0x10/+0x14/+0x1c`, helper roles for `sub_5374D0`/`sub_4B7C50`/`sub_4B7E80`, parent ObjectList extended-helper island, adjacent scalar-destructor padding proof, and formal C++ deferred because the unreferenced specialized copies require source-level dedup/no-code treatment rather than emitted standalone methods.
```

Fallback if the supervisor keeps the primary target at `COMPLETION:85`: use the same text but replace `86%` with `85%`. The stale `78%` value should not remain.

## Recommended Support-Doc Changes

Placement: [UID:00009Q] `by-class/ObjectList.md`, field layout or open-questions section.

Recommended insertion:

```md
The direct global tiers at `+0x38`, `+0x3c`, and `+0x40` should currently retain the structural names `tertiaryGlobalList`, `quaternaryGlobalList`, and `quinaryGlobalList`. The ObjectList tier helper island proves these are direct `List*` tiers and assigns lookup prefixes `0x80000000`, `0x90000000`, and `0xa0000000`, respectively. Semantic render/object-type names remain deferred until object-type taxonomy for the dispatcher `+0xf8` cases is complete.
```

Placement: [UID:0001VG] `by-type/by-struct/ObjectListLayout.md`, field note for `+0x38/+0x3c/+0x40`.

Recommended insertion:

```md
For source-facing reconstruction, `tertiaryGlobalList`, `quaternaryGlobalList`, and `quinaryGlobalList` are preferred structural placeholder names for `+0x38`, `+0x3c`, and `+0x40`. The helper island at [UID:0002BC] confirms direct-list lookup/insert/remove behavior for all three fields, but does not prove final semantic object-type names.
```

Placement: [UID:0002BB] `by-memory/0x00535df0-0x00536270.ObjectListTypeSpecificEncodedKeyLookupHelpers.md`, metadata header, if the supervisor is doing sibling cleanup.

Recommended replacement:

```text
CANONICAL_OWNER:00009Q
EMITTER_UIDS:00009Q
```

Reason: [UID:0002BB] is another ObjectList helper sibling and its prose already points toward [UID:00009Q]; keeping owner/emitter on [UID:0000M4] is stale after the ObjectList class gate cleared. This is sibling hygiene, not required to close [UID:0002BC].

Placement: [UID:00023F] parent `ObjectListExtendedTypeLookupHelpers.md`, child summary for [UID:0002BC].

Recommended update:

```md
[UID:0002BC] now has a closed raw-start reachability analysis: only `0x00537210` has a direct inbound static call (`0x005320d6`), while every other raw start from `0x00536270` through `0x00537250` has no direct `call`/`jmp`/VA/RVA reference in the scanned executable. The child should remain documented as an ObjectList helper cluster with formal C++ deferred unless the live `0x00537210` helper is split.
```

## Validation Notes

Commands run were read-only except for creation of this report file. No by-doc or generated artifacts were edited.

Validation performed:

- Read required supervisor/agent instructions.
- Confirmed target and support-doc current states.
- Confirmed exported function records for all target starts.
- Confirmed helper exports for `sub_5374D0`, `sub_4B7C50`, and `sub_4B7E80`.
- Confirmed dispatch evidence from `0x005314a0` and `0x00531c10`.
- Ran direct read-only PE scan for raw-start reachability.

No formal documentation validator was run because this report intentionally does not modify the `by-*` docs or generated coverage files.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0002BC-ObjectListTierInsertRemoveHelpers-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:21","uid":"0002BC"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
