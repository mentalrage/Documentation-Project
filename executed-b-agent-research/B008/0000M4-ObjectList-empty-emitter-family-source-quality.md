** TARGET-REPORT-UID:0000M4 **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000M4 ObjectList Empty-Emitter Family Source-Quality Report


## Report Status

- Agent: Agent-B008
- Assignment ID: `B008-report-0000M4-ObjectList-empty-emitter-family-20260701`
- Mode: report-first research only
- Target: [UID:0000M4] `by-file/ObjectList.md`
- Generated file checked: `auto-generated/NexusTK/map/ObjectList.cpp`
- Report path: `tools/leaser/Agents/Agent-B008/research/0000M4-ObjectList-empty-emitter-family-source-quality.md`
- MCP state: available. `server_health` on database `supervisor_resume_20260629` returned `ok` during this pass.
- Write-scope result: this report only. No target/support by-* docs, generated files, coverage reports, ledgers, queues, IDA DB, or validator state were edited.

## Current Generated State

`auto-generated/NexusTK/map/ObjectList.cpp` was refreshed by validator command `000000003224` at `2026-07-01T03:54:15-04:00`. The file currently emits nine filled bodies and fourteen empty markers.

Filled emitters already present:

| UID | Current emitted body |
| --- | --- |
| `0002C8` | `bool ObjectList::HasValidGridOrigin()` |
| `0002C9` | `void ObjectList::AddObjectPane(ObjectPane *object)` |
| `0002CB` | `ObjectPane *ObjectList::ResolveObjectListKey(unsigned int key)` |
| `0002CC` | `unsigned int ObjectList::GetTypedObjectKey(ObjectPane *object)` |
| `0002CD` | `ObjectPane *ObjectList::FindByObjectId(int objectId)` |
| `0002CE` | `bool ObjectList::ContainsTypedObject(ObjectPane *object)` |
| `0001D2` | ObjectList accessor methods |
| `0002BB` | typed encoded-key lookup helpers |
| `0001D4` | comment-only scalar deleting destructor marker |

Empty markers in this family:

| UID | Page | Disposition |
| --- | --- | --- |
| `00009Q` | `by-class/ObjectList.md` | class shell/no-code marker candidate; do not duplicate child method bodies |
| `00023D` | static-object lighting sync helper | source body candidate, not first batch |
| `0001D1` | lifecycle aggregate | aggregate marker with `[[CHILDREN]]`, no duplicate body |
| `0002JS` | constructor | source body candidate, not first batch |
| `0002JT` | destructor | source body candidate, not first batch |
| `00023E` | categorize/lookup aggregate | aggregate marker with `[[CHILDREN]]`, no duplicate body |
| `0002CA` | remove dispatcher | first implementation body candidate |
| `0001D3` | accessors/sweeps aggregate | aggregate marker with `[[CHILDREN]]`, no duplicate body |
| `00023F` | extended helper aggregate | aggregate marker with `[[CHILDREN]]`, no duplicate body |
| `0002BA` | encoded-key/rect mixed child | no-code marker; split decoder later if assigned |
| `0002BC` | tier insert/remove helper cluster | no-code marker; optional split only for live `0x00537210` |
| `0002OF` | vtable data | source-declared/generated-binary marker |
| `0001VG` | layout page | represented by ObjectList class/layout docs, no duplicate struct body in this file batch |
| `0001YB` | vtable page | source-declared/generated-binary marker |

The queue basis row in `auto-generated/-ag-research-tracker.md` lists [UID:0000M4] with `23` total emitters, `9` filled, `14` empty, and `39.1%` filled coverage.

## Evidence Checked

Primary docs:

- `by-file/ObjectList.md`
- `auto-generated/NexusTK/map/ObjectList.cpp`
- `auto-generated/-ag-research-tracker.md`
- `by-class/ObjectList.md`
- `by-type/by-struct/ObjectListLayout.md`
- `by-type/by-vtable/ObjectList_vtable.md`
- all fourteen empty-marker target/support pages listed above

Accepted prior reports and ledgers checked:

- `executed-b-agent-research/B005/0002C9-ObjectListTypeDispatchInsertCategorize-source-quality.md`
- `executed-b-agent-research/B005/0002CB-ObjectListEncodedKeyResolve-source-quality.md`
- `executed-b-agent-research/B006/0002CC-ObjectListTypeSpecificIndexDispatch-source-quality.md`
- `executed-b-agent-research/B006/0002CE-ObjectListTypeIndexExistsSwitchHelper-source-quality.md`
- `executed-b-agent-research/B009/0002CD-ObjectListFindByObjectId-source-quality.md`
- `executed-b-agent-research/B010/00023F-ObjectListExtendedTypeLookupHelpers-source-quality.md`
- `executed-b-agent-research/B012/0001D2-MapPaneSpatialIndex-source-quality.md`
- `executed-b-agent-research/B014/0002BA-ObjectListEncodedKeyAndRectHelpers-source-quality.md`
- `executed-b-agent-research/B001/0002BC-ObjectListTierInsertRemoveHelpers-source-quality.md`
- `executed-b-agent-research/B003/0001D4-ObjectListScalarDeletingDestructor-source-quality.md`
- Agent-A010 notes for the accepted lifecycle/constructor/destructor routing batch
- supervisor notes for executed ObjectList batches and prior validator outcomes

Live MCP checks:

- `lookup_funcs` confirmed:
  - `0x00531c10` -> `sub_531C10`, size `0x532`
  - `0x005314a0` -> `sub_5314A0`, size `0x73c`
  - `0x00530ee0` -> `sub_530EE0`, size `0x37d`
  - `0x00531260` -> `sub_531260`, size `0x213`
  - `0x00537210` -> `sub_537210`, size `0x3e`
  - `0x00537290` -> `sub_537290`, size `0x38`
  - `0x00620288` -> not a function
- `analyze_function 0x00531c10` confirmed a 12-case switch on object type, prototype `void __thiscall(_DWORD *this, int)`, size `1330`, callees `sub_5374D0`, `sub_4B7C50`, `sub_4B7E80`, `sub_537210`, and `@__security_check_cookie@4`, 12 code xrefs, 80 basic blocks, and cyclomatic complexity 57.
- `analyze_function 0x00537210` confirmed the only modeled tier-remove helper scans `this+0x3c`, compares list entries with the object argument, removes with List vslot `+0x1c`, and has one caller from `0x005320d6` in `sub_531C10`.

## Ranked Ownership And Placement

1. [UID:00009Q] `ObjectList` class is the direct owner for class methods, layout, vtable-generated artifacts, and ObjectList helper families. The object receiver, field offsets `+0x04..+0x40`, constructor/destructor vptr stores, accepted child pages, and current generated route all support this.
2. [UID:0000M4] `ObjectList.cpp` is the source-file route. It should remain the by-file destination for `NexusTK/map/ObjectList.cpp`, but most exact emitters should be class-owned children routed through [UID:00009Q].
3. `MapPane` is rejected as owner. MapPane allocates/uses the ObjectList instance and owns wrapper call sites, but these helper bodies read ObjectList fields and dispatch over ObjectList storage.
4. `MapPaneSpatialIndex` is rejected as owner. Current docs retain it only as a compatibility/search alias for ObjectList accessors.
5. `List` and `RectBounds` are dependencies, not owners. `List` provides virtual storage operations and `RectBounds` helpers provide bounds setup/testing.

Source placement stays `NexusTK/map/ObjectList.cpp`. Header-style class/layout facts may be documented on `by-class/ObjectList.md` and `by-type/by-struct/ObjectListLayout.md`, but this implementation batch should not invent a new file or move bodies to `MapPane.cpp`, `ObjectPane.cpp`, `List.cpp`, or generic utility files.

## Highest-Value First Implementation Batch

Recommended first batch after supervisor acceptance:

1. Emit [UID:0002CA] `ObjectList::RemoveObjectPane(ObjectPane *object)`.
2. Add explicit no-code/comment markers to broad aggregate, vtable, layout, and mixed-helper pages that currently appear as empty emitters but should not emit standalone source bodies.
3. Update [UID:00009Q] and [UID:0000M4] prose to explain that empty markers are now either exact-body candidates, intentional aggregate markers, or generated-binary/type markers.
4. Do not implement constructor, destructor, or static-object lighting in this first batch. They are real source candidates, but their formal bodies require a separate child-specific pass for allocation/destruction helper naming and static-object lighting structure names.

This first batch is conservative: it clears one real missing method body and many false-positive empty markers without duplicating child C++ or flattening raw helper islands into fake source APIs.

## Exact C++ Recommendation For UID 0002CA

Replace [UID:0002CA] `RECONSTRUCTION_CPP` with exactly this first-draft body:

```cpp
void ObjectList::RemoveObjectPane(ObjectPane *object)
{
    if (object == NULL)
        return;

    List *targetList = NULL;
    List **rowLists = NULL;
    bool rowBucket = false;
    bool fallbackRows = false;
    int bottomPadding = 2;

    switch (object->m_objectType) {
    case 0:
        targetList = m_primaryCellList;
        break;
    case 1:
        targetList = m_secondaryCellList;
        break;
    case 2:
        rowLists = m_primaryRowLists;
        rowBucket = true;
        fallbackRows = true;
        break;
    case 3:
        rowLists = m_tertiaryRowLists;
        rowBucket = true;
        fallbackRows = true;
        break;
    case 4:
        rowLists = m_secondaryRowLists;
        rowBucket = true;
        fallbackRows = true;
        break;
    case 5:
        rowLists = m_extendedRowLists;
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
        break;
    default:
        return;
    }

    if (rowBucket) {
        MapPoint position;
        object->GetMapPosition(&position);

        RectBounds bounds;
        InitRectBounds(&bounds,
                       m_minX - 2,
                       m_minY - 2,
                       m_minX + m_gridWidth + 2,
                       m_minY + m_gridHeight + bottomPadding);

        if (PointInRect(position.row, position.column, &bounds)) {
            List *rowList = rowLists[position.row - bounds.top];
            int count = rowList->GetCount();

            for (int index = 0; index < count; ++index) {
                ObjectPane *existing =
                    *static_cast<ObjectPane **>(rowList->GetElementAt(index));

                if (existing == object) {
                    rowList->RemoveAt(index, 1);
                    return;
                }
            }
        }

        if (!fallbackRows)
            return;

        int rowCount = m_gridHeight + 4;
        for (int rowIndex = rowCount - 1; rowIndex >= 0; --rowIndex) {
            List *rowList = rowLists[rowIndex];
            int count = rowList->GetCount();

            for (int index = 0; index < count; ++index) {
                ObjectPane *existing =
                    *static_cast<ObjectPane **>(rowList->GetElementAt(index));

                if (existing == object) {
                    rowList->RemoveAt(index, 1);
                    return;
                }
            }
        }

        return;
    }

    int count = targetList->GetCount();
    for (int index = 0; index < count; ++index) {
        ObjectPane *existing =
            *static_cast<ObjectPane **>(targetList->GetElementAt(index));

        if (existing == object) {
            targetList->RemoveAt(index, 1);
            return;
        }
    }
}
```

Why this is implementation-ready:

- It pairs directly with accepted [UID:0002C9] `ObjectList::AddObjectPane`.
- Live MCP confirms `sub_531C10` dispatches on the same `ObjectPane::m_objectType` byte at `+0xf8`.
- The field map matches accepted [UID:0001VG], [UID:0002C9], [UID:0002BC], [UID:0002CC], and [UID:0002CE] evidence.
- It emits one target-owned method body and does not emit raw tier-helper bodies, switch tables, security-cookie code, or local source APIs.
- It keeps numeric case labels because full semantic object-type enum names remain external.

Metadata recommendation for [UID:0002CA]:

| Field | Current | Recommended |
| --- | --- | --- |
| `COMPLETION` | `85` | `88` |
| `CONFIDENCE` | `88` | `90` |
| `CANONICAL_OWNER` | `00009Q` | keep |
| `EMITTER_UIDS` | `00009Q` | keep |
| `RECONSTRUCTABLE` | `TRUE` | keep |

## Exact No-Code / Marker Recommendations

These exact marker texts are recommended only after supervisor acceptance. They are intentionally comment-only or comment-plus-child markers; they are not substitute method bodies.

### UID 00009Q ObjectList Class

Recommended formal block:

```cpp
// ObjectList class-owned methods, layout, vtable, and helper children emit below.
[[CHILDREN]]
```

Rationale: the class page is the direct owner route for exact child method bodies and generated ABI artifacts. Do not duplicate every method body or hand-author a full header declaration in this by-file output pass.

### UID 0001D1 Lifecycle Aggregate

Recommended formal block:

```cpp
// ObjectList lifecycle aggregate; exact constructor and destructor children own source bodies.
[[CHILDREN]]
```

Rationale: this page is the constructor/destructor aggregate. It should route children, not duplicate their bodies.

### UID 00023E Categorize / Lookup Aggregate

Recommended formal block:

```cpp
// ObjectList categorize and lookup aggregate; exact child pages own emitted method bodies.
[[CHILDREN]]
```

Rationale: child pages already emit `HasValidGridOrigin`, `AddObjectPane`, resolver, key, id lookup, and membership methods; [UID:0002CA] should join them as the exact remove body.

### UID 0001D3 Accessors And Sweeps Aggregate

Recommended formal block:

```cpp
// ObjectList accessor and sweep aggregate; exact child pages own emitted method bodies.
[[CHILDREN]]
```

Rationale: [UID:0001D2] already emits accessors; later sweep helpers need exact pages or splits.

### UID 00023F Extended Helper Aggregate

Recommended formal block:

```cpp
// ObjectList extended helper aggregate; exact child and split pages own emitted method bodies.
[[CHILDREN]]
```

Rationale: B010 already accepted this as a broad aggregate whose source belongs on exact child/split pages, not on the physical aggregate.

### UID 0002BA Encoded Key And Rect Helpers

Recommended formal block:

```cpp
// Mixed ObjectList encoded-key and bounds helper island; split the live decoder before emitting source.
```

Rationale: B014 proved the combined target contains retained no-route raw helpers, one live decoder, table data, and padding. Only a future exact `0x00535ce0-0x00535db8` decoder split should emit first-draft decoder C++.

### UID 0002BC Tier Insert Remove Helpers

Recommended formal block:

```cpp
// ObjectList tier helper cluster retained as a combined no-code island; active dispatcher bodies own source.
```

Rationale: B001/B010 proved only `0x00537210` has a direct inbound call, while active add/remove dispatchers inline sibling behavior. Do not emit 27 standalone helper methods from this page.

### UID 0002OF Vtable Data

Recommended formal block:

```cpp
// ObjectList vtable data is generated from the class declaration and virtual destructor.
```

Rationale: the exact `.rdata` table is source-declared/generated-binary output. Do not hand-author a vtable array.

### UID 0001VG ObjectListLayout

Recommended formal block:

```cpp
// ObjectList layout is represented by the ObjectList class fields and exact method children.
```

Rationale: the layout page is strong evidence for fields and allocation rules, but emitting a second struct layout in this `.cpp` batch would duplicate class ownership.

### UID 0001YB ObjectList Vtable

Recommended formal block:

```cpp
// ObjectList vtable is generated from the class declaration and inherited LObject virtual surface.
```

Rationale: the three-slot vtable is source-declared/generated-binary output and should not be emitted as a hand-authored table.

## Not Recommended For First Batch

| UID | Reason |
| --- | --- |
| `00023D` static-object lighting sync | Real source helper, but still blocked by MapPane wrapper boundary, `StaticObjImageLib` field names, attached lighting object roles, and object virtual slot semantics. |
| `0002JS` constructor | Real source body, but formal source should wait for agreed allocation helper names and header/class declaration policy. |
| `0002JT` destructor | Real source body, but formal source should wait for agreed destroy/free helper names and class declaration policy. |
| `0001VG` full struct/class definition | Useful evidence, but not the safest first marker cleanup because the class page should own declaration policy. |
| `0002BA` decoder body | Needs an exact split for `0x00535ce0-0x00535db8`; do not emit from the combined mixed page. |
| `0002BC` live `0x00537210` helper body | Optional future split only. [UID:0002CA] can model the active remove behavior without emitting this helper as a public source API. |

## Claim And Incorporation Ledger

| Claim / fact preserved | Action | Destination / exclusion | Verification state | Incorporation proof |
| --- | --- | --- | --- | --- |
| Generated `auto-generated/NexusTK/map/ObjectList.cpp` pre-callback baseline was command `000000003224`, refreshed `2026-07-01T03:54:15-04:00`, source by-file UID `0000M4`. | incorporate | `by-file/ObjectList.md` generated-output audit/update note | applied | `by-file/ObjectList.md` now records command `000000003224`, refreshed timestamp, `23/9/14/39.1%`, and report coverage `0`; validator `000000003254` ok:1 exit 0. Final generated header is newer: command `000000003278`, refreshed `2026-07-01T04:40:06-04:00`. |
| Tracker state for [UID:0000M4] was `23` total emitters, `9` filled, `14` empty, `39.1%` filled, report coverage `0`. | incorporate | `by-file/ObjectList.md` generated-output audit/update note | applied | Counts are preserved as the pre-callback audit baseline in `by-file/ObjectList.md`; generated/tracker files were not manually edited. |
| ObjectList source route is `NexusTK/map/ObjectList.cpp`; direct class-owned emitters route through [UID:00009Q], while [UID:0000M4] remains the source-file route. | incorporate | `by-file/ObjectList.md`; `by-class/ObjectList.md` | applied | `by-file/ObjectList.md` and `by-class/ObjectList.md` now state the route split, exact-child ownership, and rejected owners (`MapPane`, `MapPaneSpatialIndex`, `List`, `RectBounds`, `ObjectPane`, generic utility/helper files). Validators `000000003254` and `000000003256` ok:1 exit 0. |
| [UID:0002CA] `ObjectListTypeDispatchRemove` is the first real method-body candidate for the callback. | incorporate | `by-memory/0x00531c10-0x00532180.ObjectListTypeDispatchRemove.md`; support summaries in `by-memory/0x00531480-0x00532530.ObjectListCategorizeLookupHelpers.md`, `by-class/ObjectList.md`, and `by-file/ObjectList.md` | applied | Target now emits `ObjectList::RemoveObjectPane(ObjectPane *object)` and support pages name it as an exact child body. Validators `000000003255`, `000000003258`, `000000003256`, and `000000003254` ok:1 exit 0. Generated `ObjectList.cpp` lines for UID0002CA show `Completion:88 | Confidence:90` followed by `void ObjectList::RemoveObjectPane(ObjectPane *object)`. |
| [UID:0002CA] boundary facts: body `0x00531c10-0x00532142`, switch table/alignment `0x00532142-0x00532180`, IDA function `sub_531C10`, size `0x532`, successor [UID:0002CB] at `0x00532180`. | incorporate | `by-memory/0x00531c10-0x00532180.ObjectListTypeDispatchRemove.md` | applied | Boundary/table ownership remains in the target evidence and reconstruction notes; generated output emits only the method body, not switch-table data. Validator `000000003255` ok:1 exit 0. |
| [UID:0002CA] live MCP evidence: 12-case switch on `ObjectPane::m_objectType` at `+0xf8`, prototype `void __thiscall(_DWORD *this, int)`, 12 code xrefs, 80 basic blocks, complexity 57, callees `sub_5374D0`, `sub_4B7C50`, `sub_4B7E80`, `sub_537210`, and security-cookie helper. | incorporate | `by-memory/0x00531c10-0x00532180.ObjectListTypeDispatchRemove.md` | applied | B008 MCP evidence is incorporated in target evidence/change log; the formal C++ excludes switch-table and security-cookie artifacts. Validator `000000003255` ok:1 exit 0. |
| [UID:0002CA] live `sub_537210` relationship: `0x00537210` scans `this+0x3c`, removes through List vslot `+0x1c`, and has one caller from `0x005320d6` in `sub_531C10`. | incorporate | `by-memory/0x00531c10-0x00532180.ObjectListTypeDispatchRemove.md`; `by-memory/0x00536270-0x0053728e.ObjectListTierInsertRemoveHelpers.md` | applied | Target cites `sub_537210` as evidence for the active remove dispatcher; [UID:0002BC] now carries the combined no-code marker and preserves one-live-helper split policy. Validators `000000003255` and `000000003262` ok:1 exit 0. |
| [UID:0002CA] metadata should change from `85/88` to `88/90`, preserving `CANONICAL_OWNER:00009Q`, `EMITTER_UIDS:00009Q`, and `RECONSTRUCTABLE:TRUE`. | incorporate | `by-memory/0x00531c10-0x00532180.ObjectListTypeDispatchRemove.md` | applied | Header now has `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:00009Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00009Q`; validator `000000003255` ok:1 exit 0. |
| [UID:0002CA] formal C++ should be the exact `void ObjectList::RemoveObjectPane(ObjectPane *object)` body from this report. | incorporate | `by-memory/0x00531c10-0x00532180.ObjectListTypeDispatchRemove.md` formal `RECONSTRUCTION_CPP` block | applied | Formal block is populated with the report body, numeric cases, accepted structural field names, and no raw helper bodies/table/security-cookie code; generated `ObjectList.cpp` emits it at UID0002CA. Validator `000000003255` ok:1 exit 0. |
| [UID:00009Q] class page should not duplicate all method bodies. | incorporate | `by-class/ObjectList.md` | applied | Formal block now emits `// ObjectList class-owned methods, layout, vtable, and helper children emit below.` plus `[[CHILDREN]]`; prose states exact children own method bodies. Validator `000000003256` ok:1 exit 0. |
| [UID:0001D1] lifecycle aggregate should route children, not duplicate constructor/destructor bodies. | incorporate | `by-memory/0x00530ee0-0x00531473.ObjectListLifecycle.md` | applied | Formal block now emits `// ObjectList lifecycle aggregate; exact constructor and destructor children own source bodies.` plus `[[CHILDREN]]`; constructor/destructor remain future child-specific work. Validator `000000003257` ok:1 exit 0. |
| [UID:00023E] categorize/lookup aggregate should route exact children and include [UID:0002CA] as emitted remove body. | incorporate | `by-memory/0x00531480-0x00532530.ObjectListCategorizeLookupHelpers.md` | applied | Formal block now emits `// ObjectList categorize and lookup aggregate; exact child pages own emitted method bodies.` plus `[[CHILDREN]]`; inventory/prose names UID0002CA as emitted `RemoveObjectPane`. Validator `000000003258` ok:1 exit 0. |
| [UID:0001D3] accessor/sweep aggregate should route exact children, not duplicate [UID:0001D2] accessors or later sweep helpers. | incorporate | `by-memory/0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md` | applied | Formal block now emits `// ObjectList accessor and sweep aggregate; exact child pages own emitted method bodies.` plus `[[CHILDREN]]`; prose states exact children own bodies. Validator `000000003259` ok:1 exit 0. |
| [UID:00023F] extended helper aggregate should remain broad aggregate/source index, not an emitted body. | incorporate | `by-memory/0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md` | applied | Formal block now emits `// ObjectList extended helper aggregate; exact child and split pages own emitted method bodies.` plus `[[CHILDREN]]`; B010 broad-aggregate no-code proof remains. Validator `000000003260` ok:1 exit 0. |
| [UID:0002BA] mixed encoded-key/rect helper page should not emit combined body. | incorporate | `by-memory/0x00535b10-0x00535df0.ObjectListEncodedKeyAndRectHelpers.md` | applied | Formal block now emits `// Mixed ObjectList encoded-key and bounds helper island; split the live decoder before emitting source.`; B014 future decoder split policy remains. Validator `000000003261` ok:1 exit 0. |
| [UID:0002BC] tier helper cluster should not emit 27 standalone helper methods. | incorporate | `by-memory/0x00536270-0x0053728e.ObjectListTierInsertRemoveHelpers.md` | applied | Formal block now emits `// ObjectList tier helper cluster retained as a combined no-code island; active dispatcher bodies own source.`; B001/B010 raw-start route proof remains. Validator `000000003262` ok:1 exit 0. |
| [UID:0002OF] vtable data is source-declared/generated-binary output. | incorporate | `by-memory/0x00620284-0x00620294.ObjectListVtableData.md` | applied | Formal block now emits `// ObjectList vtable data is generated from the class declaration and virtual destructor.` and avoids a hand-authored vtable array. Validator `000000003263` ok:1 exit 0. |
| [UID:0001VG] layout page should inform class fields, not emit duplicate struct/class body. | incorporate | `by-type/by-struct/ObjectListLayout.md` | applied | Formal block now emits `// ObjectList layout is represented by the ObjectList class fields and exact method children.`; no duplicate struct/class body was added. Validator `000000003264` ok:1 exit 0. |
| [UID:0001YB] vtable page is source-declared/generated-binary output. | incorporate | `by-type/by-vtable/ObjectList_vtable.md` | applied | Formal block now emits `// ObjectList vtable is generated from the class declaration and inherited LObject virtual surface.` and avoids a hand-authored vtable array. Validator `000000003265` ok:1 exit 0. |
| [UID:00023D] static-object lighting sync is not in this first callback. | not-applicable | No edit to `by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md` | excluded-with-reason | Excluded per accepted callback. Final generated `ObjectList.cpp` still shows UID00023D only as an `Empty Emitter Marker`, matching future-work status. |
| [UID:0002JS] constructor and [UID:0002JT] destructor are not in this first callback. | not-applicable | No edits to `by-memory/0x00530ee0-0x0053125d.ObjectListConstructor.md` or `by-memory/0x00531260-0x00531473.ObjectListDestructor.md` | excluded-with-reason | Excluded per accepted callback. Final generated `ObjectList.cpp` still shows UID0002JS and UID0002JT only as `Empty Emitter Marker`s; lifecycle aggregate routes them through children. |
| Broad by-file/class pages must not emit duplicate method bodies. | incorporate | `by-file/ObjectList.md`; `by-class/ObjectList.md` | applied | `by-file/ObjectList.md` and `by-class/ObjectList.md` now state no-duplicate-body policy; generated output has one UID0002CA method body and comments/child markers for broad aggregate/type/vtable pages. Validators `000000003254` and `000000003256` ok:1 exit 0. |
| Generated reports, generated C++, project-level generated files, manual `-coverage-report.md`, validator state, queues, archives, supervisor ledgers, and IDA DB remain tool/supervisor-owned. | not-applicable | No manual edits to excluded files | excluded-with-reason | Only accepted by-* docs and this Agent-B008 report were manually edited. Validators refreshed generated/tool-owned files through `--apply --wait-generated`; generated `ObjectList.cpp` was inspected only. |

## Implementation Tracking Checklist

- [x] Lease only the callback edit set immediately before editing, then release leases after validators. Proof: leases were acquired for the 12 accepted by-* docs before edits; post-validator unlease attempt returned `Rejected[No active lease]` for all 12 paths, so no active B008 lease remained to release.
- [x] Edit `by-file/ObjectList.md`: generated-output audit baseline, route split, rejected owners, no-duplicate-body policy, 14-empty-marker triage, and UID0002CA promotion were incorporated. Metadata change: none. Validator: `000000003254`, timestamp `2026-07-01T04:35:28-04:00`, `ok:1`, exit 0, generated refresh completed.
- [x] Edit `by-memory/0x00531c10-0x00532180.ObjectListTypeDispatchRemove.md`: metadata now `88/90` with owner/emitter preserved; exact `void ObjectList::RemoveObjectPane(ObjectPane *object)` body inserted; MCP boundary/callee/xref facts and no-table/no-cookie policy incorporated. Validator: `000000003255`, timestamp `2026-07-01T04:35:39-04:00`, `ok:1`, exit 0, generated refresh completed.
- [x] Edit `by-class/ObjectList.md`: formal marker exactly `// ObjectList class-owned methods, layout, vtable, and helper children emit below.` plus `[[CHILDREN]]`; prose sync for UID0002CA and no duplicate class bodies. Validator: `000000003256`, timestamp `2026-07-01T04:35:49-04:00`, `ok:1`, exit 0, generated refresh completed.
- [x] Edit `by-memory/0x00530ee0-0x00531473.ObjectListLifecycle.md`: formal marker exactly `// ObjectList lifecycle aggregate; exact constructor and destructor children own source bodies.` plus `[[CHILDREN]]`; constructor/destructor remain future exact-child work. Validator: `000000003257`, timestamp `2026-07-01T04:35:59-04:00`, `ok:1`, exit 0, generated refresh completed.
- [x] Edit `by-memory/0x00531480-0x00532530.ObjectListCategorizeLookupHelpers.md`: formal marker exactly `// ObjectList categorize and lookup aggregate; exact child pages own emitted method bodies.` plus `[[CHILDREN]]`; UID0002CA inventory/prose now says emitted `RemoveObjectPane`; existing child bodies preserved. Validator: `000000003258`, timestamp `2026-07-01T04:36:09-04:00`, `ok:1`, exit 0, generated refresh completed.
- [x] Edit `by-memory/0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md`: formal marker exactly `// ObjectList accessor and sweep aggregate; exact child pages own emitted method bodies.` plus `[[CHILDREN]]`; prose states no duplicate [UID:0001D2]/future sweep bodies. Validator: `000000003259`, timestamp `2026-07-01T04:36:19-04:00`, `ok:1`, exit 0, generated refresh completed.
- [x] Edit `by-memory/0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md`: formal marker exactly `// ObjectList extended helper aggregate; exact child and split pages own emitted method bodies.` plus `[[CHILDREN]]`; B010 no-code proof and child/split policy preserved. Validator: `000000003260`, timestamp `2026-07-01T04:36:29-04:00`, `ok:1`, exit 0, generated refresh completed.
- [x] Edit `by-memory/0x00535b10-0x00535df0.ObjectListEncodedKeyAndRectHelpers.md`: formal marker exactly `// Mixed ObjectList encoded-key and bounds helper island; split the live decoder before emitting source.`; future decoder split policy preserved. Validator: `000000003261`, timestamp `2026-07-01T04:36:39-04:00`, `ok:1`, exit 0, generated refresh completed.
- [x] Edit `by-memory/0x00536270-0x0053728e.ObjectListTierInsertRemoveHelpers.md`: formal marker exactly `// ObjectList tier helper cluster retained as a combined no-code island; active dispatcher bodies own source.`; route-negative raw-start proof and one-live-helper policy preserved. Validator: `000000003262`, timestamp `2026-07-01T04:36:50-04:00`, `ok:1`, exit 0, generated refresh completed.
- [x] Edit `by-memory/0x00620284-0x00620294.ObjectListVtableData.md`: formal marker exactly `// ObjectList vtable data is generated from the class declaration and virtual destructor.`; no hand-authored vtable array. Validator: `000000003263`, timestamp `2026-07-01T04:37:00-04:00`, `ok:1`, exit 0, generated refresh completed.
- [x] Edit `by-type/by-struct/ObjectListLayout.md`: formal marker exactly `// ObjectList layout is represented by the ObjectList class fields and exact method children.`; no duplicate struct/class emission. Validator: `000000003264`, timestamp `2026-07-01T04:37:10-04:00`, `ok:1`, exit 0, generated refresh completed.
- [x] Edit `by-type/by-vtable/ObjectList_vtable.md`: formal marker exactly `// ObjectList vtable is generated from the class declaration and inherited LObject virtual surface.`; no hand-authored vtable array. Validator: `000000003265`, timestamp `2026-07-01T04:37:20-04:00`, `ok:1`, exit 0, generated refresh completed.
- [x] Do not edit excluded exact future-work pages. Proof: `by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md`, `by-memory/0x00530ee0-0x0053125d.ObjectListConstructor.md`, and `by-memory/0x00531260-0x00531473.ObjectListDestructor.md` were not edited; generated `ObjectList.cpp` still lists UID00023D, UID0002JS, and UID0002JT as `Empty Emitter Marker`s.
- [x] Inspect generated `auto-generated/NexusTK/map/ObjectList.cpp` header after validators. Proof: final header is `validator-command-id: 000000003278`, `validator-refreshed-at: 2026-07-01T04:40:06-04:00`, source by-file UID `0000M4`.
- [x] Verify generated-output expectation. Proof: final generated `ObjectList.cpp` shows UID0002CA with `Completion:88 | Confidence:90` and emits `void ObjectList::RemoveObjectPane(ObjectPane *object)`; search shows UID0002CA is not an `Empty Emitter Marker`. Previously filled ObjectList bodies remain (`HasValidGridOrigin`, `AddObjectPane`, `ResolveObjectListKey`, `GetTypedObjectKey`, `FindByObjectId`). Aggregate/type/vtable pages emit comments/child markers only and no duplicate raw helper bodies.
- [x] Explicit no-edit rule for callback followed. Proof: no manual edits were made to generated reports, generated `auto-generated/NexusTK/**` C++, generated/project-level reports, manual `-coverage-report.md`, `tools/validator.ini`, queue/state/lock files, archives, supervisor ledgers, or IDA DB; validators refreshed generated state through `--apply --wait-generated`.
- [x] Callback report proof updated. Proof: this ledger/checklist now records `applied` or `excluded-with-reason` state for every accepted row, with validator and generated-output proof; no rows are blocked.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004165","destination_path":"executed-b-agent-research/B008/0000M4-ObjectList-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B008/research/0000M4-ObjectList-empty-emitter-family-source-quality.md","timestamp":"2026-07-01T04:43:07","uid":"0000M4"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
