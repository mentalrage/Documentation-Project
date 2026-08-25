** TARGET-REPORT-UID:00023F **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00023F ObjectListExtendedTypeLookupHelpers Source-Quality Report

Assignment: `B010-goal2-object-list-extended-type-lookup-helpers-source-quality-00023F-20260619`  
Agent: `Agent-B010`  
Primary target: [UID:00023F] `by-memory/0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md`  
Required report path: `tools/leaser/Agents/Agent-B010/research/00023F-ObjectListExtendedTypeLookupHelpers-source-quality.md`

## Report-Only Status

This is a report-only B-agent pass. I did not edit by-* target/support docs and did not edit `by-memory/-coverage-report.md`.

## Recommendation Summary

- Keep [UID:00023F] owned/emitted by [UID:00009Q] `ObjectList`, routed through [UID:0000M4] `NexusTK/map/ObjectList.cpp`.
- Raise [UID:00023F] from `85/86` to `87/88`. The source route, child boundaries, caller relationships, raw-start reachability, and practical source names are now substantially resolved, but the page is still a broad helper aggregate and should not receive a formal C++ body.
- Keep [UID:00023F] `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:00009Q`, `EMITTER_UIDS:00009Q`, and a blank formal `RECONSTRUCTION_CPP` block.
- Replace the current "blank because many names/groupings remain provisional" blocker with a resolved aggregate no-code proof: the range covers many independent ObjectList methods plus three child pages and raw retained copies; formal source should live on exact child/split pages, not on the aggregate.
- Update support docs to use source-facing ObjectList names, update the MapPane recenter support note because `0x00505b20 -> 0x00533f70` passes the new absolute tile origin, not a delta, and carry the direct PE reachability table into the target.
- For code generation, prefer exact children/splits:
  - [UID:0002BB] can receive first-draft C++ for the nine modeled type-specific encoded-key lookup methods after support names are updated.
  - [UID:0002BA] should stay blank as a combined child unless `0x00535ce0` is split as the live decoder. Its raw rectangle/encoder starts remain no-route.
  - [UID:0002BC] should stay blank as implemented by B001; only optional split `0x00537210` should emit.
  - Earlier modeled helpers inside [UID:00023F] should be split before formal C++ is populated. The aggregate should carry source shapes and names only.

## Evidence Checked

- Workflow and structure rules:
  - `tools/leaser/Agents/Supervisor.md`
  - `.codex/AGENTS.md`
  - `tools/leaser/Agents/Agent-B010/goal.md`
  - `by-project-structure/by-structure.md`
  - `by-project-structure/inference_research.md`
  - `by-project-structure/proposed-source-tree.md`
- Primary/support docs:
  - [UID:00023F] `by-memory/0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md`
  - [UID:00009Q] `by-class/ObjectList.md`
  - [UID:0000M4] `by-file/ObjectList.md`
  - [UID:0001VG] `by-type/by-struct/ObjectListLayout.md`
  - [UID:0002BA] `by-memory/0x00535b10-0x00535df0.ObjectListEncodedKeyAndRectHelpers.md`
  - [UID:0002BB] `by-memory/0x00535df0-0x00536270.ObjectListTypeSpecificEncodedKeyLookupHelpers.md`
  - [UID:0002BC] `by-memory/0x00536270-0x0053728e.ObjectListTierInsertRemoveHelpers.md`
  - [UID:00023E] `by-memory/0x00531480-0x00532530.ObjectListCategorizeLookupHelpers.md`
  - [UID:0002C9]/[UID:0002CA]/[UID:0002CB]/[UID:0002CC]/[UID:0002CD]/[UID:0002CE] ObjectList dispatch children
  - [UID:0001D3] `ObjectListAccessorsAndSweeps`
  - [UID:0002QM] `MapPaneRecenterAndSendPosition`
  - [UID:00037Q] `MapPaneObjectLookupHelpers`
  - [UID:00037R] `MapPaneResizeCommandInputCore`
  - [UID:00037X] `MapPaneInteractionMapChangeCore`
  - [UID:00037Y] `MapPaneTileObjectGridRenderCore`
  - [UID:0003TI]/[UID:0003TJ] static-object tile helpers
  - [UID:0001B1] `MapRefreshDimmerMethods`
  - [UID:0001L0]/[UID:0002S2]/[UID:0002S5]/[UID:00036T] target-selection consumers
  - [UID:0003IO] `SharedGmWideString`
- Prior accepted B evidence:
  - `Agent-B001/research/executed/0002BC-ObjectListTierInsertRemoveHelpers-source-quality.md`
  - Supervisor execution notes for B001 [UID:0002BC], including direct PE scan facts and no-code policy.
- Fresh checks run in this pass:
  - Local IDA MCP reachability check: `http://127.0.0.1:13337/mcp` unavailable (`Unable to connect to the remote server`).
  - Read-only PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; image base `0x00400000`; sections `.text`, `.rdata`, `.data`, `.rsrc`.
  - Capstone read-only disassembly for `0x00532f70`, `0x00533090`, `0x00533170` family samples, `0x00533a90`/`0x00533d00`, `0x00533f70`, `0x005347e0`, `0x00535900`, `0x005359e0`, `0x00535ad0`, and MapPane call sites `0x00505b20` / `0x0050bf61`.

## Direct Route Scan Results

Fresh direct PE scan over executable sections checked `E8` direct-call targets, `E9` direct-jump targets, static VA constants, and static RVA constants for every notable start in [UID:00023F]. Summary:

| Start | Direct branch/static refs found in current executable | Interpretation |
| --- | --- | --- |
| `0x00532f70` | none | Real raw helper body, no direct static route; do not emit as standalone source method. |
| `0x00533090` | `call 0x00533090` at `0x005054d4` | Live ObjectList row-object lookup consumed by MapPane. |
| `0x00533170` | `call 0x00533170` at `0x00506b02` | Live previous selectable-key ObjectList helper. |
| `0x005333b0` | `call 0x005333b0` at `0x00506b52` | Live next selectable-key ObjectList helper. |
| `0x00533600` | `call 0x00533600` at `0x00506ba2` | Live previous item-target variant. |
| `0x00533850` | `call 0x00533850` at `0x00506bf2` | Live next item-target variant. |
| `0x00533a90` | `call 0x00533a90` at `0x00506c45` | Live previous spell/living-target filtered variant. |
| `0x00533d00` | `call 0x00533d00` at `0x00506c95` | Live next spell/living-target filtered variant. |
| `0x00533f70` | `call 0x00533f70` at `0x00505b20` | Live ObjectList origin-update sweep from `MapPane::RecenterAndSendPosition`. |
| `0x005347e0` | `call 0x005347e0` at `0x0050bf61` | Live ObjectList bucket/row shift helper from MapPane tile/object-grid path. |
| `0x00535900` | `call 0x00535900` at `0x00507027`; `call 0x00535900` at `0x0050f4a9` | Live mark phase for visible/static object refresh. |
| `0x005359e0` | `call 0x005359e0` at `0x0050b199`; `call 0x005359e0` at `0x005149cf` | Live removal/prune phase; second caller is `MapRefreshDimmer` callback. |
| `0x00535ad0` | `call 0x00535ad0` at `0x00535425` | Live private bounds-builder used by `0x005347e0`. |
| `0x00535b10`, `0x00535b50`, `0x00535b90`, `0x00535bd0` | none | Real raw rectangle/key helpers but no direct route; keep as retained/private helper evidence. |
| `0x00535ce0` | calls at `0x00532198`, `0x0053318f`, `0x005333cf`, `0x0053361f`, `0x0053386f`, `0x00533aaf`, `0x00533d1f` | Live encoded-key decoder. |
| `0x00535df0` through `0x00536230` | direct jumps from `0x005322ed..0x00532335`; calls from raw predicate `0x0053246e..0x005324ee` | Live type-specific encoded-key lookup family. |
| `0x00536270` through `0x00537250` | none except `0x00537210` | Agrees with B001: raw tier copies are retained helper bodies; only `0x00537210` has a direct call. |
| `0x00537210` | `call 0x00537210` at `0x005320d6` | Only live out-of-line tier-remove helper in [UID:0002BC]. |

No static VA/RVA constants were found for these starts in the scan. This closes the broad "raw-start reachability unresolved" blocker with current negative/positive route evidence.

## Source Placement And Ownership

Keep the whole [UID:00023F] family with `ObjectList`, not `MapPane`.

Reasons:

- All helper bodies use `ObjectList` layout fields (`+0x04..+0x40`) or encoded ObjectList key formats.
- MapPane callers pass `MapPane +0x424` / `m_objectList` as the receiver before the calls.
- The MapPane wrapper layer owns user-facing traversal methods such as `MapPane::FindPreviousSelectableObject`, while these ObjectList helpers mutate or resolve ObjectList keys and row buckets.
- [UID:0000M4] already records `NexusTK/map/ObjectList.cpp` as the companion map object-index source file beside `MapPane.cpp`.
- [UID:0001VG] constructor/destructor evidence proves these fields are one `ObjectListLayout`, not loose MapPane arrays.

Rejected placements:

- `MapPane`: caller/orchestrator only for this family. It owns traversal wrappers and map-object update policy but not the storage helpers.
- `MapPaneSpatialIndex`: generated/provisional alias for early ObjectList accessors; not a separate original source class for this later helper family.
- `List`: List vslots are dependencies (`GetElementAt`, `InsertAt`, `RemoveAt`), not owners of ObjectList tier-selection policy.
- `RectGeometryHelpers`: `sub_4B7C50`/`sub_4B7E80` build/test rectangles but do not own ObjectList search behavior.
- `StaticObjectPane`, `LivingObjectPane`, `TargetSelectionInputPanes`, `MapRefreshDimmer`: consumers or object classes only.
- Raw helper/no-owner classification: wrong for modeled helper groups with ObjectList receiver and direct callers; only specific raw starts should be no-body/no-route inside the ObjectList owner.

## ObjectList Layout Names To Carry Forward

Use the [UID:0001VG] field names consistently:

| Offset | Name | Role in this family |
| --- | --- | --- |
| `+0x04` | `minX` / `m_originX` | ObjectList padded origin. `0x00533f70` compares arg0 against this field. |
| `+0x08` | `minY` / `m_originY` | ObjectList padded origin. `0x00533f70` compares arg1 against this field. |
| `+0x0c` | `gridWidth` | Bounds construction. |
| `+0x10` | `gridHeight` | Bounds construction. |
| `+0x14` | `primaryCellList` | Direct list; type/key prefix plain index. Also marked/pruned by `0x00535900/0x005359e0`. |
| `+0x18` | `secondaryCellList` | Direct list; key prefix `0x10000000`. |
| `+0x1c` | `primaryRowLists` | Row table; `0x2000` row selector family. |
| `+0x20` | `secondaryRowLists` | Row table; same `0x2000` selector family, distinct tier. |
| `+0x24` | `tertiaryRowLists` / front row bucket | Row table; `0x3000` selector family and target-selection traversal helpers. |
| `+0x28` | `extendedRowLists` / back or extended row bucket | Row table; `0x5000` selector family, bottom padding `10`. Also marked/pruned by `0x00535900/0x005359e0`. |
| `+0x2c` | `primaryGlobalList` | Direct global; prefix `0x60000000`. |
| `+0x30` | `secondaryGlobalList` | Direct global; prefix `0x70000000`. |
| `+0x34` | `alternateGlobalList` | Optional direct global, allocated only when `byte_66DA97 == 1`; prefix `0xc0000000`. |
| `+0x38` | `tertiaryGlobalList` | High direct global; prefix `0x80000000`. |
| `+0x3c` | `quaternaryGlobalList` | High direct global; prefix `0x90000000`; sole live out-of-line remove helper `0x00537210`. |
| `+0x40` | `quinaryGlobalList` | High direct global; prefix `0xa0000000`. |

Object fields observed in this pass:

- `+0xfc`: object id / serial, as used by ObjectList and MapPane lookup docs.
- `+0x100/+0x104`: object-list/map position words read by `sub_5374D0`.
- `+0x124`: refresh/prune mark byte; set by `0x00535900`, tested/removed by `0x005359e0`.
- `+0x128`: static-object id in MapPane static-object reconciliation docs.
- `+0x178`: living-target filter/category; `0x00533a90`/`0x00533d00` accept objects when filter arg is `-1` or equals this field.
- `+0x19a`: target-selectability/status byte; traversal helpers compare against `5` in the GM suffix paths.
- `+0x1d0`: skip/hidden/not-selectable flag for row search/traversal; helpers require zero.

## Encoded Key Categories

Carry the [UID:0002BA]/[UID:0002BB]/[UID:0002BC] key taxonomy into [UID:00023F]:

| Type | Encoded form | Storage |
| --- | --- | --- |
| `0` | `index` | `primaryCellList` |
| `1` | `0x10000000 | index` | `secondaryCellList` |
| `2` / `4` | `((rowDelta | 0x2000) << 16) | index` | `primaryRowLists` / `secondaryRowLists` family |
| `3` | `((rowDelta | 0x3000) << 16) | index` | `tertiaryRowLists` / front row bucket |
| `5` | `((rowDelta | 0x5000) << 16) | index` | `extendedRowLists` |
| `6` | `0x60000000 | index` | `primaryGlobalList` |
| `7` | `0x70000000 | index` | `secondaryGlobalList` |
| `8` | `0xc0000000 | index` | `alternateGlobalList` |
| `9` | `0x80000000 | index` | `tertiaryGlobalList` |
| `10` | `0x90000000 | index` | `quaternaryGlobalList` |
| `11` | `0xa0000000 | index` | `quinaryGlobalList` |
| other | `0xffffffff` | not found / invalid |

Preferred helper type names:

```cpp
static const unsigned int kObjectListKeyNotFound = 0xffffffffu;

struct ObjectListKeyParts
{
    unsigned char type;
    unsigned short rowOrSelector;
    unsigned short index;
};
```

`sub_535CE0` should be renamed or commented as `ObjectList::DecodeObjectListKey` or file-private `DecodeObjectListKey(unsigned int key, ObjectListKeyParts *parts)`. Its source ownership remains ObjectList, not MapPane.

## Source-Facing Grouping And Names

### `0x00532f70-0x00533089`

Current IDA: missed function start.  
Fresh route evidence: no direct call/jump/VA/RVA hit.  
Behavior evidence: Capstone shows a `thiscall`-shaped helper taking two coordinates, building padded ObjectList bounds via `sub_4B7C50`, testing with `sub_4B7E80`, scanning `+0x24` row list, comparing `sub_5374D0` position output, and requiring object byte `+0x1d0 == 0`.

Recommended description:

- "retained raw front-row blocking/visibility predicate"
- Source-facing fallback name: `ObjectList::HasBlockingFrontObjectAtOrOutsideBounds(int mapX, int mapY)` with low-medium confidence.
- Do not emit standalone C++ unless a future route is proven. The body is real but route-negative.

Why the awkward name is justified: the helper returns true immediately when the point fails the first padded-bounds test, and also returns true when it finds a matching unhidden object in `tertiaryRowLists`. Without a caller, the final semantic ("blocked", "invalid", or "visible") cannot be safely narrowed further.

### `0x00533090-0x00533168`

Current IDA: `sub_533090`.  
Fresh route evidence: direct call from `0x005054d4`.  
Behavior evidence: builds the normal `2`-tile padded bounds, selects `+0x24` row bucket, compares object coordinates through `sub_5374D0`, requires `+0x1d0 == 0`, and returns the object pointer or null.

Recommended source name:

```cpp
LivingObjectPane *ObjectList::FindFrontRowObjectAt(int mapX, int mapY);
```

Confidence: medium-high. Exact "front row" spelling is inferred from existing `GetFrontRowBucket` alias for `+0x24`; "FindObjectAt" is proven by pointer return and coordinate comparison.

### `0x00533170-0x00533f6d`

Current IDA: six modeled helpers `sub_533170`, `sub_5333B0`, `sub_533600`, `sub_533850`, `sub_533A90`, `sub_533D00`.  
Fresh route evidence: each has one direct call from the six MapPane traversal wrappers `0x00506ae0` through `0x00506c70`.  
Common behavior: each accepts `unsigned int *encodedKey`, decodes the current ObjectList key through `sub_535CE0`, scans `+0x24` row buckets around the decoded row/index, filters hidden objects via `+0x1d0`, checks object status/name conditions involving `+0x178`, `+0x19a`, the UTF-16 `L"GM"` pooled literal at `0x0061e6f8`, and writes a replacement encoded key on success.

Preferred names and call relationships:

| Start | MapPane wrapper | Preferred ObjectList helper name | Signature direction |
| --- | --- | --- | --- |
| `0x00533170` | `0x00506ae0` accepted as `MapPane::FindPreviousSelectableObject` | `ObjectList::MoveKeyToPreviousSelectableObject` | `bool (unsigned int *key)` |
| `0x005333b0` | `0x00506b30` accepted as `MapPane::FindNextSelectableObject` | `ObjectList::MoveKeyToNextSelectableObject` | `bool (unsigned int *key)` |
| `0x00533600` | `0x00506b80`, item-target alternate previous/up variant | `ObjectList::MoveKeyToPreviousItemTargetObject` | `bool (unsigned int *key)` |
| `0x00533850` | `0x00506bd0`, item-target alternate next/down variant | `ObjectList::MoveKeyToNextItemTargetObject` | `bool (unsigned int *key)` |
| `0x00533a90` | `0x00506c20`, SpellWho previous/up living target | `ObjectList::MoveKeyToPreviousLivingTarget` | `bool (unsigned int *key, int targetFilter)` |
| `0x00533d00` | `0x00506c70`, SpellWho next/down living target | `ObjectList::MoveKeyToNextLivingTarget` | `bool (unsigned int *key, int targetFilter)` |

The `targetFilter` name is evidence-backed: disassembly compares the extra argument against `-1` and against object field `+0x178`. SpellWho docs describe this wrapper argument as a direction/config-derived target option. The field's exact semantic name is still open, so use `targetFilter` or `livingTargetFilter`, not a final game-domain label.

Do not call these "type-specific add helpers"; they are better described as key-moving traversal helpers over the `+0x24` row list. They are called by MapPane traversal wrappers after `ObjectListTypeSpecificIndexDispatch` and before `ObjectListEncodedKeyResolve`.

### `0x00533f70-0x005347d5`

Current IDA: `sub_533F70`.  
Fresh route evidence: direct call from `0x00505b20` inside [UID:0002QM] `MapPane::RecenterAndSendPosition`.  
Important correction: the caller stores new `MapPane::m_tileOriginX/Y`, then pushes those absolute origin values to `0x00533f70`. The helper compares arg0/arg1 against ObjectList fields `+0x04/+0x08`. It is not passed precomputed deltas.

Preferred source name:

```cpp
void ObjectList::UpdateForViewportOrigin(int originX, int originY);
```

Alternative acceptable source names: `SetViewportOriginAndRefreshObjects`, `SetOriginAndRefreshObjects`.

Support-doc correction needed: [UID:0002QM] currently says the method passes deltas and its first-draft C++ calls:

```cpp
m_objectList->UpdateObjectsForViewportOrigin(m_tileOriginX - oldOriginX,
                                             m_tileOriginY - oldOriginY);
```

The binary call site instead passes:

```cpp
m_objectList->UpdateForViewportOrigin(m_tileOriginX, m_tileOriginY);
```

Impact: this is a source-quality correction for ObjectList/MapPane docs and first-draft C++. It does not change [UID:0002QM]'s ownership, but a later implementation callback should update that support page if within scope.

### `0x005347e0-0x005358f1`

Current IDA: `sub_5347E0`.  
Fresh route evidence: direct call from `0x0050bf61` inside [UID:00037Y] MapPane tile/object-grid path. The caller pushes `m_tileOriginY - oldOriginY` and `m_tileOriginX - oldOriginX`; this helper receives a delta pair. It branches immediately on the second argument equaling `1`, so it is optimized for directional/row-shift cases.

Preferred source name:

```cpp
void ObjectList::ShiftObjectBucketsForOriginDelta(int deltaX, int deltaY);
```

Alternative acceptable names: `ScrollObjectBucketsForDelta`, `ShiftObjectRowsForMapDelta`.

Behavior evidence: the body repeatedly scans/removes/reinserts or updates entries across row and direct tiers, calls `sub_5374D0`, uses List virtual slots `+0x10/+0x1c/+0x20`, calls `sub_516240` for temporary collection behavior, and calls `0x00535ad0` to build padded bounds. This is not a MapPane method even though it is called from MapPane's tile/object-grid update path.

### `0x00535900-0x005359df`

Current IDA: `sub_535900`.  
Fresh route evidence: direct calls from `0x00507027` and `0x0050f4a9`.  
Behavior evidence: sets byte `+0x124` to `1` for objects in `primaryCellList`, `tertiaryRowLists`, and `extendedRowLists`.

Preferred source name:

```cpp
void ObjectList::MarkVisibleObjectsForRefresh();
```

Alternative acceptable names: `MarkObjectRefreshEntries`, `MarkVisibleObjectListEntries`.

### `0x005359e0-0x00535ac2`

Current IDA: `sub_5359E0`.  
Fresh route evidence: direct calls from `0x0050b199` and `0x005149cf`; the latter is the MapRefreshDimmer secondary callback that refreshes active MapPane object state and clears the active refresh flag.  
Behavior evidence: walks the same `+0x14`, `+0x24`, and `+0x28` tiers backward; if object byte `+0x124` is nonzero, calls List vslot `+0x1c` with `(index, 1)` to remove it.

Preferred source name:

```cpp
void ObjectList::RemoveMarkedVisibleObjects();
```

Alternative acceptable names: `PruneMarkedVisibleObjects`, `RemoveRefreshMarkedObjects`.

This should be paired in docs with `0x00535900` as a mark/prune sequence for object refresh, not as an arbitrary cleanup helper.

### `0x00535ad0-0x00535b04`

Current IDA: `sub_535AD0`.  
Fresh route evidence: direct call from `0x00535425` inside `0x005347e0`.  
Behavior evidence: receives a `RectBounds *` argument, builds the normal `2`-tile padded ObjectList bounds from `+0x04/+0x08/+0x0c/+0x10` through `sub_4B7C50`, and returns.

Preferred source name:

```cpp
void ObjectList::BuildPaddedObjectBounds(RectBounds *bounds) const;
```

This is a private ObjectList helper. Do not assign it to `RectGeometryHelpers`; `sub_4B7C50` remains the shared rectangle constructor dependency.

## Child Policy

### [UID:0002BA] `ObjectListEncodedKeyAndRectHelpers`

Recommended metadata: `COMPLETION:86`, `CONFIDENCE:88`; owner/emitter unchanged [UID:00009Q].

Policy:

- Keep combined child formal C++ blank.
- It contains four raw starts with no direct static route (`0x00535b10`, `0x00535b50`, `0x00535b90`, `0x00535bd0`) plus the live decoder `0x00535ce0` and a compiler jump table.
- Safe source names:
  - `BuildPaddedObjectBounds2` / `BuildNormalObjectBounds` for `0x00535b10`
  - `BuildExtendedBottomObjectBounds` for `0x00535b50`
  - `BuildPaddedObjectBoundsDuplicate` for `0x00535b90`, retained/no-route
  - `EncodeObjectListKey` for `0x00535bd0`, retained/no-route in current executable
  - `DecodeObjectListKey` for `0x00535ce0`, live and strongly named
- Optional future exact split: `0x00535ce0-0x00535db8` can emit `DecodeObjectListKey`; do not emit the raw rectangle helpers until a route or source inlining policy is proven.

### [UID:0002BB] `ObjectListTypeSpecificEncodedKeyLookupHelpers`

Recommended metadata: `COMPLETION:86`, `CONFIDENCE:90`; owner/emitter unchanged [UID:00009Q].

Policy:

- This child is eligible for first-draft C++ after support docs accept structural field names and private helper style.
- It has nine modeled functions, direct dispatch refs, bounded padding, and no raw no-route starts.
- Prefer direct method names tied to field names rather than speculative game object-type names:

| Start | Preferred name |
| --- | --- |
| `0x00535df0` | `FindExtendedRowKey` |
| `0x00535ec0` | `FindTertiaryRowKey` / `FindFrontRowKey` |
| `0x00535f90` | `FindPrimaryCellKey` |
| `0x00535fd0` | `FindSecondaryCellKey` |
| `0x00536010` | `FindPrimaryRowKey` |
| `0x005360e0` | `FindSecondaryRowKey` |
| `0x005361b0` | `FindPrimaryGlobalKey` |
| `0x005361f0` | `FindSecondaryGlobalKey` |
| `0x00536230` | `FindAlternateGlobalKey` |

First-draft C++ shape for this child:

```cpp
static unsigned int MakeRowKey(unsigned int rowSelector, unsigned int index)
{
    return (rowSelector << 16) | index;
}

static unsigned int FindObjectInDirectTier(List *list,
                                           LivingObjectPane *object,
                                           unsigned int prefix)
{
    if (list == NULL)
        return kObjectListKeyNotFound;

    for (int i = 0; i < list->GetCount(); ++i)
    {
        if (list->GetElementAt(i) == object)
            return prefix | static_cast<unsigned int>(i);
    }

    return kObjectListKeyNotFound;
}

static unsigned int FindObjectInRowTier(List **rows,
                                        int firstRow,
                                        int lastRow,
                                        int keyBase,
                                        LivingObjectPane *object)
{
    ObjectListPosition pos;
    object->GetObjectListPosition(&pos);

    if (pos.row < firstRow || pos.row >= lastRow)
        return kObjectListKeyNotFound;

    List *row = rows[pos.row - firstRow];
    if (row == NULL)
        return kObjectListKeyNotFound;

    for (int i = 0; i < row->GetCount(); ++i)
    {
        if (row->GetElementAt(i) == object)
            return MakeRowKey((pos.row - firstRow) | keyBase, i);
    }

    return kObjectListKeyNotFound;
}

unsigned int ObjectList::FindPrimaryCellKey(LivingObjectPane *object)
{
    return FindObjectInDirectTier(m_primaryCellList, object, 0);
}

unsigned int ObjectList::FindSecondaryCellKey(LivingObjectPane *object)
{
    return FindObjectInDirectTier(m_secondaryCellList, object, 0x10000000);
}

unsigned int ObjectList::FindPrimaryGlobalKey(LivingObjectPane *object)
{
    return FindObjectInDirectTier(m_primaryGlobalList, object, 0x60000000);
}
```

The formal code should either include all nine wrappers in [UID:0002BB] or wait until exact per-helper splits exist. Do not put this code on [UID:00023F].

### [UID:0002BC] `ObjectListTierInsertRemoveHelpers`

Recommended metadata: keep `COMPLETION:86`, `CONFIDENCE:88`.

Policy:

- Preserve B001 no-code policy for the combined child.
- Current scan agrees with B001: all raw starts from `0x00536270` through `0x00537250` have no direct branch/VA/RVA hit except `0x00537210`.
- Optional future exact split: `0x00537210` can emit `ObjectList::RemoveFromQuaternaryGlobalList(LivingObjectPane *object)`.
- Do not emit all raw retained copies as standalone public/private methods.

## Aggregate C++ Policy

Formal [UID:00023F] C++ should remain blank.

Target-specific no-code proof:

- [UID:00023F] is not one source function. It is a physical aggregate spanning raw starts, modeled starts, private helpers, compiler table/alignment regions, and three child pages.
- Several starts in the aggregate are no-route retained copies (`0x00532f70`, `0x00535b10`, `0x00535b50`, `0x00535b90`, `0x00535bd0`, most of [UID:0002BC]).
- Child pages already own exact lower subranges; putting code in [UID:00023F] would duplicate or paste child output.
- The source-facing shape is a set of `ObjectList` private methods/helpers in `ObjectList.cpp`, not an aggregate method body.
- Exact modeled helpers in the early part should be split before formal source is emitted, especially `0x00533090`, the six key traversal helpers, `0x00533f70`, `0x005347e0`, `0x00535900`, `0x005359e0`, and `0x00535ad0`.

Source-shape snippets to carry in prose, not the aggregate formal block:

```cpp
LivingObjectPane *ObjectList::FindFrontRowObjectAt(int mapX, int mapY);

bool ObjectList::MoveKeyToPreviousSelectableObject(unsigned int *key);
bool ObjectList::MoveKeyToNextSelectableObject(unsigned int *key);
bool ObjectList::MoveKeyToPreviousItemTargetObject(unsigned int *key);
bool ObjectList::MoveKeyToNextItemTargetObject(unsigned int *key);
bool ObjectList::MoveKeyToPreviousLivingTarget(unsigned int *key, int targetFilter);
bool ObjectList::MoveKeyToNextLivingTarget(unsigned int *key, int targetFilter);

void ObjectList::UpdateForViewportOrigin(int originX, int originY);
void ObjectList::ShiftObjectBucketsForOriginDelta(int deltaX, int deltaY);
void ObjectList::MarkVisibleObjectsForRefresh();
void ObjectList::RemoveMarkedVisibleObjects();
void ObjectList::BuildPaddedObjectBounds(RectBounds *bounds) const;
```

## Open Questions Closed Or Narrowed

- Raw-start reachability: closed for current executable by direct PE scan. `0x00532f70` and raw rectangle/key/tier copies are route-negative; `0x00537210` remains the only directly called lower-tier raw/model helper in [UID:0002BC].
- MapPane versus ObjectList ownership: closed. MapPane owns wrappers/policy; ObjectList owns storage/key/tier operations.
- `0x00533f70` argument semantics: corrected. Arguments are new absolute ObjectList/MapPane tile origin values, not deltas.
- `0x005347e0` argument semantics: narrowed. Arguments are origin deltas from MapPane tile/object-grid path.
- Six `0x00533170` traversal helpers: narrowed to previous/next selectable, item-target, and living/spell filtered variants with direct wrapper evidence.
- Encoded-key categories: accepted from child docs and direct dispatch evidence.
- High-tier field names: use structural `tertiaryGlobalList`, `quaternaryGlobalList`, `quinaryGlobalList`; do not invent final game semantic names.

Remaining uncertainty:

- Exact original spelling for row/global tier fields and object type values.
- Exact semantic name for object field `+0x178`.
- Exact source spelling for object flag `+0x1d0` and mark byte `+0x124`.
- Whether raw no-route helpers were original static helpers later inlined elsewhere, dead retained helpers, or missed dynamic routes. Current static route evidence does not justify standalone emission.

## Recommended Metadata

| UID | Current | Recommended | Notes |
| --- | --- | --- | --- |
| [UID:00023F] | `85/86` | `87/88` | Resolved source grouping, names, raw reachability, child policy, and aggregate no-code proof. |
| [UID:0002BA] | `85/88` | `86/88` | Add route-negative raw helper proof and final name policy; combined child C++ blank. |
| [UID:0002BB] | `85/88` | `86/90` | Modeled live helper family with source-ready structural names; can receive child-level draft C++. |
| [UID:0002BC] | `86/88` | keep `86/88` | Already accepted/executed by B001; current scan agrees. |

All four should keep `CANONICAL_OWNER:00009Q`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00009Q`.

## Exact Recommended Implementation Instructions

When supervisor sends an implementation callback, lease and update at least:

- `by-memory/0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md`
- `by-memory/0x00535b10-0x00535df0.ObjectListEncodedKeyAndRectHelpers.md`
- `by-memory/0x00535df0-0x00536270.ObjectListTypeSpecificEncodedKeyLookupHelpers.md`
- `by-memory/0x00536270-0x0053728e.ObjectListTierInsertRemoveHelpers.md` only if synchronizing the parent text; no score change needed.
- `by-class/ObjectList.md`
- `by-file/ObjectList.md`
- `by-type/by-struct/ObjectListLayout.md`
- `by-memory/0x005059d0-0x00505bf8.MapPaneRecenterAndSendPosition.md` for the origin/delta correction.
- `by-memory/0x00506970-0x00506cdd.MapPaneObjectLookupHelpers.md` for the three traversal wrapper pairs if source names are accepted.
- `by-memory/0x00514920-0x00514a0d.MapRefreshDimmerMethods.md` if adding the `RemoveMarkedVisibleObjects` back-reference.

Target update details for [UID:00023F]:

- Change metadata to `COMPLETION:87`, `CONFIDENCE:88`; keep owner/emitter/reconstructable unchanged.
- Add direct PE scan summary table or prose equivalent.
- Replace stale "source names/raw-start reachability unresolved" with the names and policies in this report.
- Update function family table:
  - `0x00532f70`: retained raw front-row blocking/visibility predicate; no direct route.
  - `0x00533090`: `FindFrontRowObjectAt`.
  - `0x00533170` through `0x00533d00`: six encoded-key traversal helpers; previous/next selectable, item-target, living-target filtered.
  - `0x00533f70`: `UpdateForViewportOrigin(int originX, int originY)`, absolute origin.
  - `0x005347e0`: `ShiftObjectBucketsForOriginDelta(int deltaX, int deltaY)`.
  - `0x00535900`: `MarkVisibleObjectsForRefresh`.
  - `0x005359e0`: `RemoveMarkedVisibleObjects`.
  - `0x00535ad0`: `BuildPaddedObjectBounds(RectBounds *) const`.
- Keep formal C++ blank and add the aggregate no-code proof above.
- Add rejected alternatives and child emission policy.

Support doc changes:

- [UID:00009Q] `ObjectList.md`: add the source-facing helper names and pair `MarkVisibleObjectsForRefresh` / `RemoveMarkedVisibleObjects`; clarify `MapPaneSpatialIndex` is only a generated alias, not the owner.
- [UID:0000M4] `ObjectList.md`: list the extended helper families under `ObjectList.cpp` and mention formal emission should happen on exact children/splits.
- [UID:0001VG] `ObjectListLayout.md`: add `+0x124`, `+0x178`, `+0x19a`, `+0x1d0` as referenced object-pane fields if this doc tracks observed dependent object fields; otherwise put those in ObjectList class notes only.
- [UID:0002QM] `MapPaneRecenterAndSendPosition.md`: change `m_objectList->UpdateObjectsForViewportOrigin(m_tileOriginX - oldOriginX, m_tileOriginY - oldOriginY)` to an absolute-origin call and update prose saying `0x00505b20` pushes new `m_tileOriginX`/`m_tileOriginY`.
- [UID:00037Q] `MapPaneObjectLookupHelpers.md`: add that the six MapPane wrappers are thin MapPane methods over ObjectList key traversal helpers; accepted source names exist for the first pair, inferred item/spell filtered roles for later pairs.
- [UID:0001B1] `MapRefreshDimmerMethods.md`: annotate `0x005149cf -> 0x005359e0` as `ObjectList::RemoveMarkedVisibleObjects()`.

## Exact Pending Coverage Replacement Text

Do not edit `by-memory/-coverage-report.md` during the report pass. Supervisor-owned replacement block:

```markdown
    - [UID:00023F][0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers](by-memory/0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md) 0x00532f70-0x0053728e | ObjectList helper aggregate | ObjectListExtendedTypeLookupHelpers : reconstructable : 87% : strong : ObjectList extended helper aggregate with exact bounds, ObjectList class/file route through `NexusTK/map/ObjectList.cpp`, modeled and IDA-missed starts rechecked by direct PE route scan, source-facing grouping resolved for front-row lookup, encoded-key traversal, viewport-origin update, origin-delta bucket shift, mark/prune refresh helpers, and padded-bounds builder, MapPane caller wrappers separated from ObjectList ownership, encoded-key field/tier taxonomy synchronized with child pages, raw starts `0x00532f70`/`0x00535b10`/`0x00535b50`/`0x00535b90`/`0x00535bd0` and most tier-copy starts route-negative, child emission policy documented, successor scalar-destructor padding proof preserved, and formal aggregate C++ intentionally blank because source output belongs on exact child/split pages rather than this broad physical aggregate.
        - [UID:0002BA][0x00535b10-0x00535df0.ObjectListEncodedKeyAndRectHelpers](by-memory/0x00535b10-0x00535df0.ObjectListEncodedKeyAndRectHelpers.md) 0x00535b10-0x00535df0 | helper-island | ObjectListEncodedKeyAndRectHelpers : reconstructable : 86% : strong : Attached ObjectList encoded-key/rect helper island with raw rectangle helpers at `0x00535b10`/`0x00535b50`/`0x00535b90`, raw packed-key builder at `0x00535bd0`, live modeled decoder `sub_535CE0`, twelve-entry jump table, documented padding spans, direct PE scan confirming no direct `call`/`jmp`/VA/RVA route to the raw rectangle/key-builder starts, source-facing names `BuildPaddedObjectBounds`/`BuildExtendedBottomObjectBounds`/`EncodeObjectListKey`/`DecodeObjectListKey`, parent/successor boundary agreement, and combined-child formal C++ deferred unless the live decoder or another exact helper is split for emission.
        - [UID:0002BB][0x00535df0-0x00536270.ObjectListTypeSpecificEncodedKeyLookupHelpers](by-memory/0x00535df0-0x00536270.ObjectListTypeSpecificEncodedKeyLookupHelpers.md) 0x00535df0-0x00536270 | helper-family | ObjectListTypeSpecificEncodedKeyLookupHelpers : reconstructable : 86% : strong : Attached ObjectList type-specific encoded-key lookup helper family with nine modeled live functions, direct dispatch refs from `ObjectListTypeSpecificIndexDispatch` and the raw existence predicate, documented padding spans, ObjectList field offsets `+0x14/+0x18/+0x1c/+0x20/+0x24/+0x28/+0x2c/+0x30/+0x34`, packed row/global key forms, preferred structural names `FindPrimaryCellKey`/`FindSecondaryCellKey`/`FindPrimaryRowKey`/`FindSecondaryRowKey`/`FindTertiaryRowKey`/`FindExtendedRowKey`/`FindPrimaryGlobalKey`/`FindSecondaryGlobalKey`/`FindAlternateGlobalKey`, parent/adjacent child boundary agreement, and child-level first-draft C++ ready once accepted while final semantic object-type names remain provisional.
        - [UID:0002BC][0x00536270-0x0053728e.ObjectListTierInsertRemoveHelpers](by-memory/0x00536270-0x0053728e.ObjectListTierInsertRemoveHelpers.md) 0x00536270-0x0053728e | helper-cluster | ObjectListTierInsertRemoveHelpers : reconstructable : 86% : strong : ObjectList tier search/insert/remove helper cluster with all raw helper starts from `0x00536270` through `0x00537250` inventoried, direct PE scan confirming no `call`/`jmp`/VA/RVA references to any raw start except the sole direct call to modeled `sub_537210` at `0x005320d6`, ObjectList field offsets `+0x14..+0x40`, stable structural high-tier names `tertiaryGlobalList`/`quaternaryGlobalList`/`quinaryGlobalList` for `+0x38/+0x3c/+0x40`, row-table versus direct-tier helper taxonomy, List virtual slots `+0x10/+0x14/+0x1c`, helper roles for `sub_5374D0`/`sub_4B7C50`/`sub_4B7E80`, parent ObjectList extended-helper island, adjacent scalar-destructor padding proof, and formal C++ deferred because the unreferenced specialized copies require source-level dedup/no-code treatment rather than emitted standalone methods.
```

## Validator Commands For Implementation

Run from `source-3/project-documentation` after an implementation callback, for every touched file:

> Executable block R001 was removed from this report and preserved verbatim in [00023F-ObjectListExtendedTypeLookupHelpers-source-quality-removed.md](00023F-ObjectListExtendedTypeLookupHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Only validate optional support docs if edited.

## IDA Rename / Type / Comment Recommendations

Use comments first if the IDA database policy avoids renaming uncertain helpers.

High-confidence:

- `sub_533090` -> `ObjectList_FindFrontRowObjectAt`
- `sub_535CE0` -> `ObjectList_DecodeObjectListKey`
- `sub_535900` -> `ObjectList_MarkVisibleObjectsForRefresh`
- `sub_5359E0` -> `ObjectList_RemoveMarkedVisibleObjects`
- `sub_535AD0` -> `ObjectList_BuildPaddedObjectBounds`
- `sub_537210` -> `ObjectList_RemoveFromQuaternaryGlobalList`

Medium-high:

- `sub_533F70` -> `ObjectList_UpdateForViewportOrigin`
- `sub_5347E0` -> `ObjectList_ShiftObjectBucketsForOriginDelta`
- `sub_533170` -> `ObjectList_MoveKeyToPreviousSelectableObject`
- `sub_5333B0` -> `ObjectList_MoveKeyToNextSelectableObject`
- `sub_533A90` -> `ObjectList_MoveKeyToPreviousLivingTarget`
- `sub_533D00` -> `ObjectList_MoveKeyToNextLivingTarget`

Medium:

- `sub_533600` -> `ObjectList_MoveKeyToPreviousItemTargetObject`
- `sub_533850` -> `ObjectList_MoveKeyToNextItemTargetObject`
- raw `0x00532f70` comment only: `ObjectList retained front-row blocking/visibility predicate; no direct static route found`
- raw `0x00535b10`/`0x00535b50`/`0x00535b90` comments only: rectangle-bounds helpers; no direct route found.
- raw `0x00535bd0` comment only: packed ObjectList key encoder; no direct route found.

Suggested types:

```cpp
struct ObjectListKeyParts
{
    unsigned char type;
    unsigned short rowOrSelector;
    unsigned short index;
};

void __thiscall ObjectList::BuildPaddedObjectBounds(RectBounds *bounds);
LivingObjectPane *__thiscall ObjectList::FindFrontRowObjectAt(int mapX, int mapY);
bool __thiscall ObjectList::MoveKeyToPreviousSelectableObject(unsigned int *key);
bool __thiscall ObjectList::MoveKeyToNextSelectableObject(unsigned int *key);
bool __thiscall ObjectList::MoveKeyToPreviousLivingTarget(unsigned int *key, int targetFilter);
bool __thiscall ObjectList::MoveKeyToNextLivingTarget(unsigned int *key, int targetFilter);
void __thiscall ObjectList::UpdateForViewportOrigin(int originX, int originY);
void __thiscall ObjectList::ShiftObjectBucketsForOriginDelta(int deltaX, int deltaY);
void __thiscall ObjectList::MarkVisibleObjectsForRefresh();
void __thiscall ObjectList::RemoveMarkedVisibleObjects();
```

## FINISHED

Report written to `source-3/project-documentation/tools/leaser/Agents/Agent-B010/research/00023F-ObjectListExtendedTypeLookupHelpers-source-quality.md`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000004165","destination_path":"executed-b-agent-research/B010/00023F-ObjectListExtendedTypeLookupHelpers-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:34","uid":"00023F"} -->
<!-- {"agent":"B010","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00023F-ObjectListExtendedTypeLookupHelpers-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B010/00023F-ObjectListExtendedTypeLookupHelpers-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00023F"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
