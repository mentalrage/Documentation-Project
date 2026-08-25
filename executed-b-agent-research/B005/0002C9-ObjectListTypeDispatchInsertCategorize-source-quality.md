** TARGET-REPORT-UID:0002C9 **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002C9 ObjectListTypeDispatchInsertCategorize Source-Quality Report

Assignment: `B005-report-0002C9-object-list-insert-categorize-source-quality-20260626`  
Agent: `Agent-B005`  
Primary target: [UID:0002C9] `by-memory/0x005314a0-0x00531c10.ObjectListTypeDispatchInsertCategorize.md`  
Required report path: `tools/leaser/Agents/Agent-B005/research/0002C9-ObjectListTypeDispatchInsertCategorize-source-quality.md`

## Report-Only Status

This is a report-only B-agent pass. I did not lease files, did not edit by-* documentation, did not edit generated/project-level/manual coverage/tool-state files, and did not edit the IDA database. Several target/support by-* files were already dirty or untracked in the worktree before this report write; this pass does not rely on or alter those unowned changes.

IDA MCP was required and was available. Live MCP session used for this report:

- MCP endpoint: `http://127.0.0.1:13337/mcp`
- MCP session header: `ee653fd6-0aba-43b2-8aee-e57a1b9d139e`
- IDB session: `80de0a67`
- Database: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- `server_health`: `status=ok`, `auto_analysis_ready=true`, `hexrays_ready=true`, module `NexusTK.exe`, imagebase `0x400000`

## Recommendation Summary

- Keep [UID:0002C9] owned/emitted by [UID:00009Q] `ObjectList`, with source emission through [UID:0000M4] `NexusTK/map/ObjectList.cpp`.
- Raise [UID:0002C9] from `85/88` to `88/90`.
- Use the source-facing method name `ObjectList::AddObjectPane(ObjectPane *object)`.
- Treat `InsertByType`, `InsertByTypeDispatch`, and `ObjectListTypeDispatchInsertCategorize` as stale/descriptive aliases. `AddObjectPane` is preferred because the paired MapPane reindex helper already calls `m_objectList->AddObjectPane(objectPane)` and this target adds one pointer record to the correct ObjectList storage tier.
- Populate [UID:0002C9]'s formal C++ block with the exact one-method body in this report. The body emits only the target function. It introduces no standalone helper bodies, no lambdas, no namespace helpers, and no target-owned factoring functions.
- Close the current blockers at implementation level:
  - Method name: `AddObjectPane`.
  - Type field name: `ObjectPane::m_objectType` at `+0xf8`.
  - Tier names: structural ObjectList layout names from [UID:0001VG], not speculative game-domain enum names.
  - Helper names: use existing outside dependencies `ObjectPane::GetMapPosition`, `InitRectBounds`, `PointInRect`, and `List::GetElementAt` / `List::InsertAt`.
  - Object-type semantic labels: exact game-domain labels remain only partly proven, but they are no longer a C++ blocker because the formal body intentionally keeps numeric switch cases while mapping each case to a proven structural tier.

## Evidence Checked

Primary and support docs:

- [UID:0002C9] `by-memory/0x005314a0-0x00531c10.ObjectListTypeDispatchInsertCategorize.md`
- [UID:00023E] `by-memory/0x00531480-0x00532530.ObjectListCategorizeLookupHelpers.md`
- [UID:0002CA] `by-memory/0x00531c10-0x00532180.ObjectListTypeDispatchRemove.md`
- [UID:0002CC] `by-memory/0x005322d0-0x00532370.ObjectListTypeSpecificIndexDispatch.md`
- [UID:0002CE] `by-memory/0x00532450-0x00532530.ObjectListTypeIndexExistsSwitchHelper.md`
- [UID:00009Q] `by-class/ObjectList.md`
- [UID:0000M4] `by-file/ObjectList.md`
- [UID:0001VG] `by-type/by-struct/ObjectListLayout.md`
- [UID:00009R] `by-class/ObjectPane.md`
- [UID:0001D5] `by-memory/0x005372d0-0x005378fa.ObjectPane.md`
- [UID:0003XN] `by-memory/0x005372d0-0x00537395.ObjectPaneConstructor.md`
- [UID:0003XP] `by-memory/0x005374d0-0x005374eb.ObjectPaneGetMapPosition.md`
- [UID:00015S] `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md`
- [UID:0001VP] `by-type/by-struct/RectBoundsLayout.md`
- [UID:000079] `by-class/List.md`
- [UID:0002BA] `by-memory/0x00535b10-0x00535df0.ObjectListEncodedKeyAndRectHelpers.md`
- [UID:0002BB] `by-memory/0x00535df0-0x00536270.ObjectListTypeSpecificEncodedKeyLookupHelpers.md`
- [UID:0002BC] `by-memory/0x00536270-0x0053728e.ObjectListTierInsertRemoveHelpers.md`
- [UID:0002QN] `by-memory/0x00505e00-0x005060e3.MapPaneCreateOrUpdateObjectPane.md`
- [UID:00042D] `by-memory/0x00505940-0x005059cb.MapPaneReindexObjectPanePosition.md`
- Representative direct caller docs including [UID:0003TF], [UID:0003TH], [UID:0003TI], [UID:0003TR], [UID:0003TX], and [UID:00023D].

Prior accepted reports and trackers:

- `executed-b-agent-research/B010/00023F-ObjectListExtendedTypeLookupHelpers-source-quality.md`
- `by-memory` and support docs produced by B001/B006/B010 ObjectList passes
- Supervisor incorporation tracker rows for MapPane packet helper splits that call `sub_5314A0`

## Fresh IDA MCP Evidence

Live IDA MCP confirms the current target facts:

- `lookup_funcs`:
  - `0x00531480`: `sub_531480`, size `0x18`
  - `0x00531498`: not a function; eight `0xcc` bytes before this target
  - `0x005314a0`: `sub_5314A0`, size `0x73c`
  - `0x00531bdc`: not a function; target-owned switch table
  - `0x00531c10`: `sub_531C10`, size `0x532`
  - helper callees: `sub_5374D0` size `0x1b`, `sub_4B7C50` size `0x1f`, `sub_4B7E80` size `0x27`
- `xrefs_to 0x005314a0`: 18 code xrefs:
  - `0x005059b1`, `0x005060c9`, `0x0050a9be`, `0x0050e0b4`, `0x0050e1ee`, `0x0050e64d`, `0x0050e7c5`, `0x0050eb0d`, `0x0050edb0`, `0x0050ee90`, `0x0050efc4`, `0x0050f10b`, `0x0050fe4a`, `0x0051193e`, `0x00512ae6`, `0x00512ed7`, `0x005132d9`, and `0x00530e8f`.
- `xrefs_to 0x00531bdc`: one data xref from `0x005314d0` inside `sub_5314A0`.
- `callees 0x005314a0`: `sub_5374D0`, `sub_4B7C50`, `sub_4B7E80`, and `@__security_check_cookie@4`.
- `analyze_function 0x005314a0`: prototype `void __thiscall(_DWORD *this, int)`, size `1852`, 92 basic blocks, cyclomatic complexity 77, and comments identifying the 12-case switch and each case entry.
- `get_bytes 0x00531bdc size 52`: twelve dword entries followed by four `0xcc` bytes:
  - case `0`: `0x005315fa`
  - case `1`: `0x00531693`
  - case `2`: `0x00531738`
  - case `3`: `0x00531568`
  - case `4`: `0x005317cd`
  - case `5`: `0x005314d7`
  - case `6`: `0x00531862`
  - case `7`: `0x00531900`
  - case `8`: `0x0053199e`
  - case `9`: `0x00531a3c`
  - case `10`: `0x00531ada`
  - case `11`: `0x00531b6d`
  - then `0xcc 0xcc 0xcc 0xcc` through `0x00531c10`.
- `get_bytes 0x00531498 size 8`: eight `0xcc` bytes before the target start.
- `insn_query 0x005314a0-0x005314d7`:
  - null object pointer test at `0x005314b6-0x005314b8`
  - signed load `movsx eax, byte ptr [ecx+0F8h]` at `0x005314be`
  - 12-case range check at `0x005314c5`
  - switch jump through `jpt_5314D0[eax*4]` at `0x005314d0`.
- `insn_query` for calls in the function returns 60 calls:
  - repeated direct calls to `sub_5374D0`, `sub_4B7C50`, and `sub_4B7E80`
  - repeated virtual calls through `List` vtable slot `+0x10` for element access
  - one common final virtual call through `List` vtable slot `+0x14` at `0x00531bc6` for insertion
  - the security-cookie check at `0x00531bd1`.
- `insn_query 0x00531bbe-0x00531bdc`: common tail passes `index`, count `1`, and the address of a one-pointer local slot to `call dword ptr [eax+14h]`, then returns through `retn 4`.

Helper decompiles:

- `sub_5374D0`: writes `this[65]` / object offset `+0x104` to output word 0 and `this[64]` / object offset `+0x100` to output word 1. Source role: `ObjectPane::GetMapPosition(MapPoint *out) const`, where this target uses output word 0 as row and word 1 as column.
- `sub_4B7C50`: writes a four-int `RectBounds` as `left, top, right, bottom`.
- `sub_4B7E80`: returns `bounds.left <= column && column < bounds.right && bounds.top <= row && row < bounds.bottom`.

## Behavioral Resolution

`sub_5314A0` is the active ObjectList add/register helper. It receives an `ObjectPane *`, returns immediately for null, reads `object->m_objectType` at `+0xf8`, and adds the pointer to one ObjectList tier chosen by that type.

The target does not call the raw insertion helper starts in [UID:0002BC]. This is important for the formal code: [UID:0002BC] documents those raw starts as mostly route-negative retained/specialized copies, while the active dispatcher inlines equivalent tier-selection and ordered-insert behavior. The formal C++ for [UID:0002C9] should therefore inline list selection and bounds logic inside this one method rather than call target-owned `InsertInto...` helpers.

Case-to-tier mapping is fully resolved at structural level:

| Object type case | Storage tier | Bounds gate | Insert ordering |
| ---: | --- | --- | --- |
| `0` | `m_primaryCellList` / `+0x14` | normal pad `2` | row, then column |
| `1` | `m_secondaryCellList` / `+0x18` | normal pad `2` | row, then column |
| `2` | `m_primaryRowLists[row - bounds.top]` / `+0x1c` | normal pad `2` | column only within selected row |
| `3` | `m_tertiaryRowLists[row - bounds.top]` / `+0x24` | normal pad `2` | column only within selected row |
| `4` | `m_secondaryRowLists[row - bounds.top]` / `+0x20` | normal pad `2` | column only within selected row |
| `5` | `m_extendedRowLists[row - bounds.top]` / `+0x28` | bottom pad `10` | column only within selected row |
| `6` | `m_primaryGlobalList` / `+0x2c` | normal pad `2` | row, then column |
| `7` | `m_secondaryGlobalList` / `+0x30` | normal pad `2` | row, then column |
| `8` | `m_alternateGlobalList` / `+0x34` | normal pad `2` | row, then column |
| `9` | `m_tertiaryGlobalList` / `+0x38` | normal pad `2` | row, then column |
| `10` | `m_quaternaryGlobalList` / `+0x3c` | normal pad `2` | row, then column |
| `11` | `m_quinaryGlobalList` / `+0x40` | no bounds gate in this target | row, then column |

The bounds gate uses:

```cpp
InitRectBounds(&bounds,
               m_minX - 2,
               m_minY - 2,
               m_minX + m_gridWidth + 2,
               m_minY + m_gridHeight + bottomPadding);
```

where `bottomPadding` is `10` only for object type `5` and `2` otherwise. Case `11` directly selects `m_quinaryGlobalList` and skips the `InitRectBounds` / `PointInRect` test.

The ordered insertion rule is stable after equal coordinates:

- Direct-list/global tiers insert before the first existing object whose row is greater than the new row, or whose row is equal and column is greater than the new column.
- Row-list tiers already select a single row bucket and insert before the first existing object whose column is greater than the new column.
- The final insertion passes `&object` as a one-pointer element payload to `List::InsertAt(index, 1, &object)`.

## Naming Resolution

Recommended target method:

```cpp
void ObjectList::AddObjectPane(ObjectPane *object);
```

Why `AddObjectPane`:

- The body adds a pointer to one ObjectList storage tier and never removes or returns a key.
- [UID:00042D] already emits `m_objectList->AddObjectPane(objectPane)` for the MapPane reindex remove/add workflow.
- The paired remove target [UID:0002CA] should converge on `ObjectList::RemoveObjectPane(ObjectPane *object)`.
- `InsertByType` from [UID:0002QN] is behaviorally close but less aligned with the existing remove/add pair and should become an alias or be replaced in support C++.

Rejected target method names:

- `ObjectListTypeDispatchInsertCategorize`: documentation label, not source-grade.
- `InsertByTypeDispatch`: decompiler/documentation-shaped and preserves implementation mechanics in the API name.
- `CategorizeObjectPane`: underspecifies that the method mutates List storage through `InsertAt`.
- `InsertObjectInDirectTier` or `InsertIntoPrimaryCellList`: wrong granularity for this target; those are helper/label shapes, not the active dispatcher method.

Object-type names:

- `ObjectPane::m_objectType` is resolved as the field name.
- Exact game-domain enum labels are only partly proven by [UID:00009R] (`0` item/ground item, `1` flying object, `3` living, `5` static, plus separate constructor evidence for `8` damage number, `10` lighting, and `11` sound).
- Do not invent final labels for cases `2`, `4`, `6`, `7`, or `9` in this target.
- The implementation-ready solution is to keep numeric `case` labels in formal C++ and document the structural storage tier for each case. This avoids a false enum while resolving the target's behavior and making the C++ emit-ready.

## Formal C++ Recommendation

Replace the empty [UID:0002C9] `RECONSTRUCTION_CPP CODE` block with this exact one-body target text. This formal block emits only `ObjectList::AddObjectPane`; it does not define `Allocate...`, `HeaderFrom...`, `InsertInto...`, local helper functions, lambdas, templates, namespace helpers, or any other target-owned helper body.

```cpp
void ObjectList::AddObjectPane(ObjectPane *object)
{
    if (object == NULL)
        return;

    List *targetList = NULL;
    bool rowBucket = false;
    bool requireBounds = true;
    int bottomPadding = 2;

    switch (object->m_objectType) {
    case 0:
        targetList = m_primaryCellList;
        break;
    case 1:
        targetList = m_secondaryCellList;
        break;
    case 2:
        rowBucket = true;
        break;
    case 3:
        rowBucket = true;
        break;
    case 4:
        rowBucket = true;
        break;
    case 5:
        rowBucket = true;
        bottomPadding = 10;
        break;
    case 6:
        targetList = m_primaryGlobalList;
        break;
    case 7:
        targetList = m_secondaryGlobalList;
        break;
    case 8:
        targetList = m_alternateGlobalList;
        break;
    case 9:
        targetList = m_tertiaryGlobalList;
        break;
    case 10:
        targetList = m_quaternaryGlobalList;
        break;
    case 11:
        targetList = m_quinaryGlobalList;
        requireBounds = false;
        break;
    default:
        return;
    }

    MapPoint position;
    object->GetMapPosition(&position);

    RectBounds bounds;
    if (requireBounds) {
        InitRectBounds(&bounds,
                       m_minX - 2,
                       m_minY - 2,
                       m_minX + m_gridWidth + 2,
                       m_minY + m_gridHeight + bottomPadding);

        if (!PointInRect(position.row, position.column, &bounds))
            return;
    }

    if (rowBucket) {
        int rowIndex = position.row - bounds.top;

        switch (object->m_objectType) {
        case 2:
            targetList = m_primaryRowLists[rowIndex];
            break;
        case 3:
            targetList = m_tertiaryRowLists[rowIndex];
            break;
        case 4:
            targetList = m_secondaryRowLists[rowIndex];
            break;
        case 5:
            targetList = m_extendedRowLists[rowIndex];
            break;
        }
    }

    int insertIndex = 0;
    int count = targetList->GetCount();

    while (insertIndex < count) {
        ObjectPane *existing =
            *static_cast<ObjectPane **>(targetList->GetElementAt(insertIndex));

        MapPoint existingPosition;
        existing->GetMapPosition(&existingPosition);

        if (rowBucket) {
            if (position.column < existingPosition.column)
                break;
        } else {
            if (position.row < existingPosition.row ||
                (position.row == existingPosition.row &&
                 position.column < existingPosition.column)) {
                break;
            }
        }

        ++insertIndex;
    }

    targetList->InsertAt(insertIndex, 1, &object);
}
```

Range-safety proof:

- This block contains exactly one function body, matching the one modeled function at `0x005314a0-0x00531bdc`.
- The switch table and `0xcc` alignment bytes at `0x00531bdc-0x00531c10` are compiler/linker output owned by the target page, not source text.
- Outside calls are to already documented external functions or class APIs: `ObjectPane::GetMapPosition`, `InitRectBounds`, `PointInRect`, `List::GetElementAt`, and `List::InsertAt`. `List::GetCount` is the source accessor for the observed `List::m_count` read and follows the existing [UID:0002BB] formal-code precedent; it is not a target-owned helper body.
- The target-owned tier logic is inlined in the method body. It does not call route-negative raw insertion helpers in [UID:0002BC].
- The code intentionally uses numeric cases rather than a new `ObjectPaneType` enum because not all semantic enum labels are proven.
- The source-level `&object` argument models the observed one-pointer local slot passed to `List::InsertAt`.

## Recommended Metadata And Target Text Changes

For [UID:0002C9]:

- Set `COMPLETION:88`.
- Set `CONFIDENCE:90`.
- Keep `CANONICAL_OWNER:00009Q`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `EMITTER_UIDS:00009Q`.
- Replace the `Item Summary` with:

```markdown
ObjectList::AddObjectPane typed insertion dispatcher with exact `sub_5314A0` function/table bounds, 12-case switch over `ObjectPane::m_objectType` at `+0xf8`, structural case-to-tier mapping across `primaryCellList`/row lists/global tiers through `+0x40`, normal `2`-tile bounds gates for cases `0..4` and `6..10`, extended bottom pad `10` for case `5`, no bounds gate for case `11`, ordered insertion by row/column or column within row bucket, final `List::InsertAt(index, 1, &object)` payload shape, live 18-caller and helper-callee evidence, and first-draft C++ emitted as one target method body with no target-owned helper functions.
```

Target prose updates:

- Replace provisional method-name wording with `ObjectList::AddObjectPane(ObjectPane *object)`.
- Add the case-to-tier table from this report.
- Add the current MCP evidence block: session `80de0a67`, `lookup_funcs`, `xrefs_to`, `callees`, `analyze_function`, `get_bytes`, and helper decompiles.
- Correct any wording that calls `sub_4B7C50` / `sub_4B7E80` list helpers. They are `RectBounds` helpers.
- State that [UID:0002BC] raw tier insertion helpers are not called by this active dispatcher; the active target inlines equivalent selection/insertion logic.
- Keep semantic object-type labels explicitly non-final, but no longer list them as a blocker to this target's formal C++ because numeric switch cases plus structural tier names are implementation-ready.

## Support-Doc Plan For Implementation Callback

When supervisor sends the implementation callback, update these files if still consistent with current local state:

- `by-memory/0x005314a0-0x00531c10.ObjectListTypeDispatchInsertCategorize.md`
  - Main target: metadata, item summary, behavior, evidence, case-to-tier table, formal C++ block, score rationale, and changes.
- `by-memory/0x00531480-0x00532530.ObjectListCategorizeLookupHelpers.md`
  - Parent sync: name child [UID:0002C9] as `ObjectList::AddObjectPane`, keep [UID:0002CA] paired as remove, and preserve compiler table ownership.
- `by-memory/0x00531c10-0x00532180.ObjectListTypeDispatchRemove.md`
  - Pairing sync only: update source-facing name direction to `ObjectList::RemoveObjectPane(ObjectPane *object)` and note it is paired with [UID:0002C9] `AddObjectPane`. Do not emit [UID:0002CA] C++ unless separately assigned.
- `by-class/ObjectList.md`
  - Method inventory sync: add or replace the insertion dispatcher name with `AddObjectPane`, note `InsertByType` as stale alias, and add the structural 12-case tier map.
- `by-file/ObjectList.md`
  - Source root sync: record that `ObjectList.cpp` owns `ObjectList::AddObjectPane` and that the exact child [UID:0002C9] carries the formal body.
- `by-type/by-struct/ObjectListLayout.md`
  - Layout consumer sync: add [UID:0002C9]'s case-to-field mapping and the special case `5` bottom pad `10` / case `11` no-bounds behavior. Do not change layout offsets.
- `by-memory/0x00505e00-0x005060e3.MapPaneCreateOrUpdateObjectPane.md`
  - Caller formal C++ sync: replace `m_objectList->InsertByType(...)` with `m_objectList->AddObjectPane(...)` and replace `RemoveByType` with `RemoveObjectPane`.
- `by-memory/0x00505940-0x005059cb.MapPaneReindexObjectPanePosition.md`
  - No implementation edit required. It already uses `AddObjectPane` / `RemoveObjectPane` and should remain evidence only for this callback.

Do not update generated coverage or any `-coverage-report.md` during the B-agent implementation callback unless the supervisor explicitly assigns coverage ownership.

## Validator Commands For Implementation

Run scoped validators from `source-3/project-documentation` for every edited file:

> Executable block R001 was removed from this report and preserved verbatim in [0002C9-ObjectListTypeDispatchInsertCategorize-source-quality-removed.md](0002C9-ObjectListTypeDispatchInsertCategorize-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Do not validate `by-memory/0x00505940-0x005059cb.MapPaneReindexObjectPanePosition.md` for this callback unless the supervisor explicitly expands the implementation scope to include that evidence-only page.

## Implementation Tracking Checklist

- [x] Leased `by-memory/0x005314a0-0x00531c10.ObjectListTypeDispatchInsertCategorize.md`; updated [UID:0002C9] metadata to `88/90`; populated the exact one-body `ObjectList::AddObjectPane(ObjectPane *object)` formal C++ block; added B005 MCP session `80de0a67`, the 18-caller set, switch entries, helper roles, case-to-tier table, score rationale, open-question closure, and 2026-06-26 change entry. Validator: `python .\tools\validator.py --mode file --file by-memory/0x005314a0-0x00531c10.ObjectListTypeDispatchInsertCategorize.md --apply --queue-timeout 240 --wait-generated`, command_id `000000003142`, timestamp `2026-06-26T18:08:57-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed` with generated command_id `000000003142`.
- [x] Leased `by-memory/0x00531480-0x00532530.ObjectListCategorizeLookupHelpers.md`; updated the child inventory/prose to name [UID:0002C9] as `ObjectList::AddObjectPane`, preserved [UID:0002CA] as paired remove direction and compiler-data ownership on exact children. Validator: `python .\tools\validator.py --mode file --file by-memory/0x00531480-0x00532530.ObjectListCategorizeLookupHelpers.md --apply --queue-timeout 240 --wait-generated`, command_id `000000003145`, timestamp `2026-06-26T18:09:18-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed` with generated command_id `000000003145`.
- [x] Leased `by-memory/0x00531c10-0x00532180.ObjectListTypeDispatchRemove.md`; synchronized only paired naming toward `ObjectList::RemoveObjectPane(ObjectPane *object)` and the [UID:0002C9] add/remove relationship; left formal C++ blank. Validator: `python .\tools\validator.py --mode file --file by-memory/0x00531c10-0x00532180.ObjectListTypeDispatchRemove.md --apply --queue-timeout 240 --wait-generated`, command_id `000000003149`, timestamp `2026-06-26T18:09:41-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed` with generated command_id `000000003149`.
- [x] Leased `by-class/ObjectList.md`; added `AddObjectPane` to the method inventory and evidence, marked `InsertByType`/`InsertByTypeDispatch` as stale aliases/search terms, and included the structural 12-case tier map. Validator: `python .\tools\validator.py --mode file --file by-class/ObjectList.md --apply --queue-timeout 240 --wait-generated`, command_id `000000003151`, timestamp `2026-06-26T18:10:06-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed` with generated command_id `000000003151`; existing unrelated warning retained for missing [UID:00023D] old helper path.
- [x] Leased `by-file/ObjectList.md`; updated `ObjectList.cpp` source-root notes for [UID:0002C9] `AddObjectPane` formal emission and exact-child/no-duplicate-body policy. Validator: `python .\tools\validator.py --mode file --file by-file/ObjectList.md --apply --queue-timeout 240 --wait-generated`, command_id `000000003152`, timestamp `2026-06-26T18:10:35-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed` with generated command_id `000000003152`; existing unrelated warnings retained for missing [UID:0003IO] registry entry and missing [UID:00023D] old helper path.
- [x] Leased `by-type/by-struct/ObjectListLayout.md`; added [UID:0002C9]'s consumer mapping without changing offsets, including case `5` bottom pad `10`, case `11` no-bounds behavior, and cases `9..11` direct high-tier fields. Validator: `python .\tools\validator.py --mode file --file by-type/by-struct/ObjectListLayout.md --apply --queue-timeout 240 --wait-generated`, command_id `000000003153`, timestamp `2026-06-26T18:10:54-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed` with generated command_id `000000003153`.
- [x] Leased `by-memory/0x00505e00-0x005060e3.MapPaneCreateOrUpdateObjectPane.md`; replaced formal/prose `InsertByType` with `AddObjectPane` and `RemoveByType` with `RemoveObjectPane`. Validator: `python .\tools\validator.py --mode file --file by-memory/0x00505e00-0x005060e3.MapPaneCreateOrUpdateObjectPane.md --apply --queue-timeout 240 --wait-generated`, command_id `000000003154`, timestamp `2026-06-26T18:11:12-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed` with generated command_id `000000003154`.
- [x] Did not edit `by-memory/0x00505940-0x005059cb.MapPaneReindexObjectPanePosition.md`; it already supports the `AddObjectPane` name and remained evidence-only for this callback.
- [x] Ran the scoped validators listed above for every changed by-* file with `--wait-generated`; all seven returned exit `0`, `ok: 1`, and `generated_refresh: completed`.
- [x] Lease cleanup: initial B005 lease command returned `Success` for all seven edited by-* files. Post-validator `unlease` returned `Rejected[No active lease]` for all seven because no B005 lease remained active; follow-up `tools/leaser/Agents/Agent-B005/current_leases.md` showed no active B005 leases.
- [x] No manual edits were made to generated/project-level/manual coverage/tool-state/IDA DB files or any `-coverage-report.md`; only validator-owned generated/projected metadata refreshes occurred from the scoped `--apply --wait-generated` validator runs.

## Open Questions Closed Or Narrowed

Closed for [UID:0002C9]:

- Method name blocker: resolved to `ObjectList::AddObjectPane(ObjectPane *object)`.
- Helper role blocker: `sub_5374D0` is `ObjectPane::GetMapPosition`; `sub_4B7C50` / `sub_4B7E80` are RectBounds helpers, not list helpers.
- Tier names blocker: structural tier names from `ObjectListLayout` are sufficient and implementation-ready.
- C++ blocker: resolved by a one-body formal block that emits no target-owned helper bodies and keeps numeric switch cases.
- Raw helper confusion: [UID:0002BC] raw insertion helper starts are not direct callees; active insertion logic is in [UID:0002C9].

Still external to this target:

- Full game-domain `ObjectPaneType` enum labels for all values `0..11` remain broader ObjectPane/subclass taxonomy work. This does not block [UID:0002C9] implementation because the binary itself dispatches on numeric values and the structural tier map is exact.
- Original spelling of `PointInRect` versus a project-specific wrapper name remains external to [UID:0002C9]. The [UID:0002C9] implementation should use the documented source-facing `PointInRect` behavior and must not define a local wrapper.

## FINISHED_REPORT

Report-only research is complete and implementation-ready for supervisor review.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/0002C9-ObjectListTypeDispatchInsertCategorize-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0002C9-ObjectListTypeDispatchInsertCategorize-source-quality.md","timestamp":"2026-06-26T18:23:06","uid":"0002C9"} -->
<!-- {"agent":"B005","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002C9-ObjectListTypeDispatchInsertCategorize-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B005/0002C9-ObjectListTypeDispatchInsertCategorize-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002C9"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
