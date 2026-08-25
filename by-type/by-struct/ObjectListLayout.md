*** UID:0001VG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00009Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00009Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// ObjectList layout is represented by the ObjectList class fields and exact method children.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ObjectListLayout

## Status

- Entity kind: class layout support struct
- Confidence: very strong for exact size/offsets/types, semantic storage identities, allocation/cleanup symmetry, type/key mapping, accessor/dispatcher consumers, and ObjectList ownership; stripped original member spelling alone caps certainty.
- Proposed owner: [UID:00009Q][ObjectList](by-class/ObjectList.md), emitted through [UID:0000M4][ObjectList](by-file/ObjectList.md)
- Owner/emitter gate: attached to [UID:00009Q][ObjectList](by-class/ObjectList.md), which is `90/92`; the [UID:0000M4][ObjectList](by-file/ObjectList.md) source root is `90/92`.
- Evidence basis: live IDA MCP decompilation/disassembly of `ObjectList` lifecycle/accessor methods, the linked ObjectList accessor/sweep page, and [UID:0001D2][0x00532530-0x0053272e.ObjectListAccessorMethods](by-memory/0x00532530-0x0053272e.ObjectListAccessorMethods.md).
- Reconstruction note: this layout page emits only a comment marker in the current ObjectList batch. The fields are represented by the `ObjectList` class and exact method children; do not duplicate a standalone struct/class definition in `ObjectList.cpp`.

## Layout

```text
ObjectListLayout
  +0x00  void* vtable
  +0x04  int minX
  +0x08  int minY
  +0x0c  int gridWidth
  +0x10  int gridHeight
  +0x14  List* itemObjects
  +0x18  List* flyingObjects
  +0x1c  List** primaryEffectRows
  +0x20  List** secondaryEffectRows
  +0x24  List** livingObjectRows
  +0x28  List** staticObjectRows
  +0x2c  List* balloonObjects
  +0x30  List* hitBarObjects
  +0x34  List* damageNumberObjects
  +0x38  List* objectInfoObjects
  +0x3c  List* lightingObjects
  +0x40  List* soundObjects
```

Observed object size is `0x44` bytes. The constructor is called after allocating 68 bytes.

## Allocation Rules

- `itemObjects` and `flyingObjects` use capacity `(gridWidth + 4) * (gridHeight + 4) * 100`.
- `primaryEffectRows`, `secondaryEffectRows`, and `livingObjectRows` each have `gridHeight + 4` entries.
- `staticObjectRows` has `gridHeight + 12` entries.
- Row-list capacity is `(gridWidth + 4) * 10`.
- `damageNumberObjects` at `+0x34` is only allocated when the client variant flag at `0x0066da97` is set to `1`; destructor cleanup uses the same gate.

## IDA Verification

- [UID:0002JS][0x00530ee0-0x0053125d.ObjectListConstructor](by-memory/0x00530ee0-0x0053125d.ObjectListConstructor.md) stores the sentinel origin fields, grid dimensions, all row-list arrays, and global list tiers at the offsets listed above; [UID:0002C8][0x00531480-0x00531498.ObjectListOriginInitializedCheck](by-memory/0x00531480-0x00531498.ObjectListOriginInitializedCheck.md) later tests the `+0x08`/`+0x04` origin fields against that sentinel.
- [UID:0002JT][0x00531260-0x00531473.ObjectListDestructor](by-memory/0x00531260-0x00531473.ObjectListDestructor.md) destroys the same fields in the matching cleanup order, including conditional cleanup of `+0x34` when `byte_66DA97 == 1`.
- IDA MCP reports the constructor as `0x00530ee0-0x0053125d` and the ordinary destructor as `0x00531260-0x00531473`; the bytes between them are three `0xcc` alignment bytes.
- Constructor callers are in `MapPane::ChangeMap` and `MapPane::HandleEffectPacket`, confirming this layout belongs to the map object-index owner rather than a generic list container.
- [UID:0001D3][0x00532530-0x00532f67.ObjectListAccessorsAndSweeps](by-memory/0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md) records the accessor/sweep island that consumes the same flat/global list pointers, row-list arrays, `minX`, `minY`, `gridWidth`, and `gridHeight` fields.
- [UID:0001D2][0x00532530-0x0053272e.ObjectListAccessorMethods](by-memory/0x00532530-0x0053272e.ObjectListAccessorMethods.md) now documents the exact accessor methods over these ObjectList fields. [UID:00007R][MapPaneSpatialIndex](by-class/MapPaneSpatialIndex.md) remains a compatibility/search alias, not a separate allocated layout.
- 2026-06-16 C001 live IDA refresh reconfirmed constructor callers at `0x0050bc55` and `0x005106e2`, destructor reachability through scalar deleting destructor `0x00537296`, constructor writes from `+0x04` through `+0x40`, destructor cleanup of the same field set, and direct accessor disassembly returning `+0x14`, `+0x18`, and `+0x2c` through `+0x40`.
- Evidence-time C001 applied and saved `ObjectList_Constructor` and `ObjectList_Destructor` in IDA. Its decision not to promote then-provisional accessor/member names is historical; UID0002BB resolves the documentation/source-facing taxonomy without mutating IDA.

## Naming Notes

Current source-facing member names are semantic: `m_itemObjects`, `m_flyingObjects`, `m_primaryEffectRows`, `m_secondaryEffectRows`, `m_livingObjectRows`, `m_staticObjectRows`, `m_balloonObjects`, `m_hitBarObjects`, `m_damageNumberObjects`, `m_objectInfoObjects`, `m_lightingObjects`, and `m_soundObjects`. UID `0001D2` retains the accepted public accessor spellings `GetPrimaryCellList`, `GetSecondaryCellList`, `GetPrimaryRowBucket`, `GetSecondaryRowBucket`, `GetVisibleObjectList`, `GetSecondaryGlobalList`, `GetAlternateGlobalList`, `GetTertiaryGlobalList`, `GetQuaternaryGlobalList`, `GetQuinaryGlobalList`, `GetFrontRowBucket`, and `GetBackRowBucket`; public method names need not mirror private member names.

Historical `primaryCellList`, `secondaryCellList`, `primaryRowLists`, `secondaryRowLists`, `tertiaryRowLists`, `extendedRowLists`, `primaryGlobalList`, `secondaryGlobalList`, `alternateGlobalList`, `tertiaryGlobalList`, `quaternaryGlobalList`, and `quinaryGlobalList` remain searchable structural aliases only. `MapPaneSpatialIndex`, `GetLayer0*`, `GetLayer1*`, and `GetInternalList` are also historical/search aliases. The 2026-06-16 decision not to promote then-provisional names into IDA remains valid provenance, but no longer describes a source reconstruction blocker.

B005's [UID:0002C8][0x00531480-0x00531498.ObjectListOriginInitializedCheck](by-memory/0x00531480-0x00531498.ObjectListOriginInitializedCheck.md) source-quality pass confirms the field-lifecycle evidence for the `+0x04` and `+0x08` origin/min-coordinate fields. The target helper compares `+0x08` first, then `+0x04`, against the signed uninitialized-origin sentinel `-30000` (`0xFFFF8AD0`, little-endian `d0 8a ff ff`). Formal code should continue to use `m_minX` for `+0x04` and `m_minY` for `+0x08`, while retaining B010's origin/min-coordinate alias wording when explaining absolute-origin update helpers.

For source-facing reconstruction, `+0x38`, `+0x3c`, and `+0x40` are `m_objectInfoObjects`, `m_lightingObjects`, and `m_soundObjects`. [UID:0002BC][0x00536270-0x0053728e.ObjectListTierInsertRemoveHelpers](by-memory/0x00536270-0x0053728e.ObjectListTierInsertRemoveHelpers.md) confirms direct-list lookup/insert/remove behavior and lookup prefixes `0x80000000`, `0x90000000`, and `0xa0000000`; exact ObjectPane constructor tags and the active add/remove/accessor family fix the corresponding object-info, lighting, and sound meanings.

B006's [UID:0002CE][0x00532450-0x00532530.ObjectListTypeIndexExistsSwitchHelper](by-memory/0x00532450-0x00532530.ObjectListTypeIndexExistsSwitchHelper.md) reanalysis cross-checks the lower storage fields from the typed-membership side: cases `0..8` dispatch over `+0x14`, `+0x18`, `+0x1c`, `+0x24`, `+0x20`, `+0x28`, `+0x2c`, `+0x30`, and `+0x34` respectively. UID0002BB closes the former taxonomy gap with exact producer tags and complete helper bodies.

B006's [UID:0002CC][0x005322d0-0x00532370.ObjectListTypeSpecificIndexDispatch](by-memory/0x005322d0-0x00532370.ObjectListTypeSpecificIndexDispatch.md) implementation adds the value-returning cross-check for the same typed ObjectList field route. `ObjectList::GetTypedObjectKey(ObjectPane *object)` uses `object->m_objectType` cases `0..8`, calls the same typed key helpers as [UID:0002CE][0x00532450-0x00532530.ObjectListTypeIndexExistsSwitchHelper](by-memory/0x00532450-0x00532530.ObjectListTypeIndexExistsSwitchHelper.md), and returns `kObjectListKeyNotFound` when the type is outside that range:

| Object type case | `GetTypedObjectKey` helper | ObjectListLayout field |
| ---: | --- | --- |
| `0` | `FindItemObjectKey` | `+0x14 m_itemObjects` |
| `1` | `FindFlyingObjectKey` | `+0x18 m_flyingObjects` |
| `2` | `FindPrimaryEffectObjectKey` | `+0x1c m_primaryEffectRows` |
| `3` | `FindLivingObjectKey` | `+0x24 m_livingObjectRows` |
| `4` | `FindSecondaryEffectObjectKey` | `+0x20 m_secondaryEffectRows` |
| `5` | `FindStaticObjectKey` | `+0x28 m_staticObjectRows` |
| `6` | `FindBalloonObjectKey` | `+0x2c m_balloonObjects` |
| `7` | `FindHitBarObjectKey` | `+0x30 m_hitBarObjects` |
| `8` | `FindDamageNumberObjectKey` | `+0x34 m_damageNumberObjects` |

B009's [UID:0002CD][0x00532370-0x00532443.ObjectListFindByObjectId](by-memory/0x00532370-0x00532443.ObjectListFindByObjectId.md) source-quality pass cross-checks the id-lookup consumer side: `ObjectList::FindByObjectId(int objectId)` reads `m_gridHeight + 4`, scans `m_livingObjectRows`, then `m_itemObjects`, then `m_flyingObjects`, and compares each returned `ObjectPane`'s `m_objectId` at `+0xfc`. Keep `m_objectSerial` only as an ObjectPane/protocol historical alias caveat.

B005's [UID:0002C9][0x005314a0-0x00531c10.ObjectListTypeDispatchInsertCategorize](by-memory/0x005314a0-0x00531c10.ObjectListTypeDispatchInsertCategorize.md) source-quality pass adds the active insertion consumer map for all `ObjectPane::m_objectType` cases without changing offsets:

| Object type case | ObjectListLayout field | Bounds behavior in `ObjectList::AddObjectPane` |
| ---: | --- | --- |
| `kObjectPaneTypeItem` (`0`) | `+0x14 m_itemObjects` | normal 2-tile pad |
| `kObjectPaneTypeFlying` (`1`) | `+0x18 m_flyingObjects` | normal 2-tile pad |
| `kObjectPaneTypePrimaryEffect` (`2`) | `+0x1c m_primaryEffectRows[row - bounds.top]` | normal 2-tile pad |
| `kObjectPaneTypeLiving` (`3`) | `+0x24 m_livingObjectRows[row - bounds.top]` | normal 2-tile pad |
| `kObjectPaneTypeSecondaryEffect` (`4`) | `+0x20 m_secondaryEffectRows[row - bounds.top]` | normal 2-tile pad |
| `kObjectPaneTypeStatic` (`5`) | `+0x28 m_staticObjectRows[row - bounds.top]` | bottom pad `10` |
| `kObjectPaneTypeBalloon` (`6`) | `+0x2c m_balloonObjects` | normal 2-tile pad |
| `kObjectPaneTypeHitBar` (`7`) | `+0x30 m_hitBarObjects` | normal 2-tile pad |
| `kObjectPaneTypeDamageNumber` (`8`) | `+0x34 m_damageNumberObjects` | normal 2-tile pad |
| `kObjectPaneTypeObjectInfo` (`9`) | `+0x38 m_objectInfoObjects` | normal 2-tile pad |
| `kObjectPaneTypeLighting` (`10`) | `+0x3c m_lightingObjects` | normal 2-tile pad |
| `kObjectPaneTypeSound` (`11`) | `+0x40 m_soundObjects` | no bounds gate |

This confirms all twelve semantic identities on the active add/remove path. `ObjectPaneType` values come from exact derived-constructor tag writes, so the earlier numeric-only disposition is superseded.

B005's [UID:0002CB][0x00532180-0x005322d0.ObjectListEncodedKeyResolve](by-memory/0x00532180-0x005322d0.ObjectListEncodedKeyResolve.md) implementation adds the inverse resolver cross-check. `ObjectList::ResolveObjectListKey(ObjectListKey key)` decodes a packed key and maps decoded key types `0..9` to these fields:

| Decoded key type | ObjectListLayout field in resolver |
| ---: | --- |
| `0` | `+0x14 m_itemObjects` |
| `1` | `+0x18 m_flyingObjects` |
| `2` | `+0x1c m_primaryEffectRows[rowSelector]` |
| `3` | `+0x24 m_livingObjectRows[rowSelector]` |
| `4` | `+0x20 m_secondaryEffectRows[rowSelector]` |
| `5` | `+0x28 m_staticObjectRows[rowSelector]` |
| `6` | `+0x2c m_balloonObjects` |
| `7` | `+0x30 m_hitBarObjects` |
| `8` | `+0x34 m_damageNumberObjects` |
| `9` | `+0x38 m_objectInfoObjects` |

The resolver intentionally does not handle decoder categories `10` and `11`: the binary compares the decoded type against `9` and returns `NULL` for larger values, so `m_lightingObjects` and `m_soundObjects` remain add/lookup-family tiers but are not returned through [UID:0002CB][0x00532180-0x005322d0.ObjectListEncodedKeyResolve](by-memory/0x00532180-0x005322d0.ObjectListEncodedKeyResolve.md). The typed-key family also preserves two exact noncanonical encodings: secondary-effect type `4` returns key category `2`, and damage-number type `8` uses high prefix `0xc0000000`; these are observed behavior, not normalization opportunities.

B010's [UID:00023F][0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers](by-memory/0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md) pass keeps the same ObjectList field names and adds dependent object-pane field observations needed by this layout's helper consumers. These offsets are not `ObjectListLayout` fields, but they explain how ObjectList methods compare, mark, filter, and key objects:

| Object offset | Observed role in ObjectList helpers |
| ---: | --- |
| `+0xfc` | object id / serial used by ObjectList and MapPane lookup docs |
| `+0x100` | object-list/map column word read by `sub_5374D0` into the second output word |
| `+0x104` | object-list/map row word read by `sub_5374D0` into the first output word; row-table selection uses this word |
| `+0x124` | refresh/prune mark byte set by `ObjectList::MarkVisibleObjectsForRefresh` and tested/removed by `ObjectList::RemoveMarkedVisibleObjects` |
| `+0x128` | static-object id in MapPane static-object reconciliation docs |
| `+0x178` | living-target filter/category compared by previous/next living target helpers when the filter argument is not `-1` |
| `+0x19a` | target-selectability/status byte compared against `5` in GM suffix traversal paths |
| `+0x1d0` | hidden/not-selectable skip flag; row search/traversal helpers require it to be zero |

For source-facing reconstruction, `sub_5374D0` should continue to be modeled as an object-position helper whose first word is the row and second word is the column. If later source docs prove the original names were `x`/`y`, callers must still preserve the observed order: the first word selects ObjectList row arrays and sorts before the second word.

## Score Rationale

- Completion is `92` because the page records the exact `0x44` size, every field offset/type/semantic identity, constructor/destructor symmetry, allocation counts and variant gate, all twelve type-to-storage routes, accessor and id-lookup consumers, encoded-key resolver limits, secondary-effect/category-2 and damage-number/category-C quirks, ownership/emission, compiler-output disposition, and historical aliases.
- Confidence is `94` because lifecycle writes/cleanup, direct accessor bytes, add/remove dispatch, exact constructor type tags, nine specialized key helpers, resolver behavior, and caller use independently agree on the layout. Exact stripped private-member spellings remain inferred, so the score stays below certainty without leaving a C++ or layout blocker.

## Cross-References

- [UID:00009Q][ObjectList](by-class/ObjectList.md)
- [UID:0000M4][ObjectList](by-file/ObjectList.md)
- [UID:0001D1][0x00530ee0-0x00531473.ObjectListLifecycle](by-memory/0x00530ee0-0x00531473.ObjectListLifecycle.md)
- [UID:0002JS][0x00530ee0-0x0053125d.ObjectListConstructor](by-memory/0x00530ee0-0x0053125d.ObjectListConstructor.md)
- [UID:0002JT][0x00531260-0x00531473.ObjectListDestructor](by-memory/0x00531260-0x00531473.ObjectListDestructor.md)
- [UID:0002C8][0x00531480-0x00531498.ObjectListOriginInitializedCheck](by-memory/0x00531480-0x00531498.ObjectListOriginInitializedCheck.md)
- [UID:0001D2][0x00532530-0x0053272e.ObjectListAccessorMethods](by-memory/0x00532530-0x0053272e.ObjectListAccessorMethods.md)
- [UID:0001D3][0x00532530-0x00532f67.ObjectListAccessorsAndSweeps](by-memory/0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md)
- [UID:0002C9][0x005314a0-0x00531c10.ObjectListTypeDispatchInsertCategorize](by-memory/0x005314a0-0x00531c10.ObjectListTypeDispatchInsertCategorize.md)
- [UID:0002CB][0x00532180-0x005322d0.ObjectListEncodedKeyResolve](by-memory/0x00532180-0x005322d0.ObjectListEncodedKeyResolve.md)
- [UID:0002CC][0x005322d0-0x00532370.ObjectListTypeSpecificIndexDispatch](by-memory/0x005322d0-0x00532370.ObjectListTypeSpecificIndexDispatch.md)
- [UID:00023F][0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers](by-memory/0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md)
- [UID:000079][List](by-class/List.md)

## Changes

### 2026-07-14 B002 UID0002BB Semantic Layout Implementation

- What changed: raised completion/confidence from `85/90` to `92/94`; replaced the current structural layout with the exact semantic item/flying/effect/living/static/balloon/hit-bar/damage-number/object-info/lighting/sound fields; synchronized allocation, accessor, dispatch, resolver, and key-quirk evidence; preserved the exact class-field marker and labeled all prior names as historical aliases.
- Why: the complete derived-constructor tag inventory and active ObjectList lifecycle/dispatch/accessor/key-helper family close every former type/name blocker while preserving the exact offsets, types, size, behavior, and no-duplicate-source disposition.

### 2026-07-01 B008 Layout Comment Marker

- What changed: the formal block now emits only `// ObjectList layout is represented by the ObjectList class fields and exact method children.`
- Why: B008 accepted this page as layout evidence, not a duplicate `.cpp` struct/class body. The field layout informs [UID:00009Q][ObjectList](by-class/ObjectList.md) and exact method children.

- 2026-06-27 B012 accessor-method naming sync:
  - What changed: replaced stale `MapPaneSpatialIndex`/layer-name pending wording with the accepted ObjectList accessor-method names from [UID:0001D2][0x00532530-0x0053272e.ObjectListAccessorMethods](by-memory/0x00532530-0x0053272e.ObjectListAccessorMethods.md), while keeping structural field names and semantic-tier caveats.
  - Evidence: B012 live MCP confirmed the direct field loads, row-bucket bodies, exact endpoints, and ObjectList receiver layout; no IDA type/member edits were made.
- 2026-06-06: Synced the layout page with the updated ObjectList accessor/sweep parent and `MapPaneSpatialIndex` compatibility alias wording. Scores remain `82/88`; no new field offsets were promoted, but the ownership notes now match the linked memory/class/file pages.
- 2026-06-06: Attached the object-index layout to [UID:00009Q][ObjectList](by-class/ObjectList.md). Scores remain `82/88`; this pass only records the direct class parent now that the class page clears the gate.
- 2026-06-16 C001 type-layout refresh:
  - Before: `82/88`, with layout offsets documented but current parent-gate wording stale and support [UID:0001D3][0x00532530-0x00532f67.ObjectListAccessorsAndSweeps](by-memory/0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md) still below the strict completion gate.
  - After: `85/90`, preserving owner/emitter route through [UID:00009Q][ObjectList](by-class/ObjectList.md) and final C++ blank.
  - Evidence: live IDA reconfirmed constructor/destructor field symmetry, row/global tier allocation rules, optional `+0x34` gate through `byte_66DA97`, constructor/destructor xrefs, direct accessor offsets, and current saved IDA names for the lifecycle pair. Accessor/sweep method and member names remain provisional, so no IDA type/member edits or helper-function renames were applied.
- 2026-06-18 B001 tier-helper sync:
  - What changed: added the [UID:0002BC][0x00536270-0x0053728e.ObjectListTierInsertRemoveHelpers](by-memory/0x00536270-0x0053728e.ObjectListTierInsertRemoveHelpers.md) high direct-tier field conclusion for `+0x38/+0x3c/+0x40`.
  - Evidence: the tier helper island confirms these offsets are direct `List*` tiers with lookup-key prefixes and insert/remove coverage; final semantic render/object-type names remain outside this layout pass.
- 2026-06-21 B006 typed-membership cross-check:
  - Added the [UID:0002CE][0x00532450-0x00532530.ObjectListTypeIndexExistsSwitchHelper](by-memory/0x00532450-0x00532530.ObjectListTypeIndexExistsSwitchHelper.md) case-to-storage mapping for `+0x14` through `+0x34`, while preserving all current structural placeholder names.
- 2026-06-26 B009 id-lookup cross-check:
  - Added [UID:0002CD][0x00532370-0x00532443.ObjectListFindByObjectId](by-memory/0x00532370-0x00532443.ObjectListFindByObjectId.md)'s exact read-side consumer evidence for `+0x10`, `+0x24`, `+0x14`, and `+0x18`, with `ObjectPane::m_objectId` at `+0xfc` primary and `m_objectSerial` retained only as an alias/caveat.
- 2026-06-21 B010 extended-helper dependent-field sync:
  - Added object-pane offset observations used by [UID:00023F][0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers](by-memory/0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md), including object id, position words, refresh mark byte, static-object id, living-target filter/status bytes, and hidden/not-selectable flag. These are documented as dependent object fields rather than members of `ObjectListLayout`.
- 2026-06-26 B005 HasValidGridOrigin sentinel cross-check:
  - Added [UID:0002C8][0x00531480-0x00531498.ObjectListOriginInitializedCheck](by-memory/0x00531480-0x00531498.ObjectListOriginInitializedCheck.md)'s `+0x08/+0x04` `-30000` sentinel predicate evidence, preserving `m_minX`/`m_minY` as formal field names while retaining origin/min-coordinate alias wording for lifecycle and viewport-origin discussions.
- 2026-06-26 B005 AddObjectPane consumer map:
  - Added [UID:0002C9][0x005314a0-0x00531c10.ObjectListTypeDispatchInsertCategorize](by-memory/0x005314a0-0x00531c10.ObjectListTypeDispatchInsertCategorize.md)'s active add-dispatch case-to-field mapping for object-type cases `0..11`, including case `5` bottom pad `10`, case `11` no-bounds behavior, and direct high-tier use of `+0x38/+0x3c/+0x40`.
- 2026-06-26 B005 ResolveObjectListKey resolver map:
  - Added [UID:0002CB][0x00532180-0x005322d0.ObjectListEncodedKeyResolve](by-memory/0x00532180-0x005322d0.ObjectListEncodedKeyResolve.md)'s decoded-key case-to-field mapping for resolver cases `0..9`, plus the explicit no-cases-`10`/`11` note for `+0x3c/+0x40`.
- 2026-06-26 B006 GetTypedObjectKey field map:
  - Added [UID:0002CC][0x005322d0-0x00532370.ObjectListTypeSpecificIndexDispatch](by-memory/0x005322d0-0x00532370.ObjectListTypeSpecificIndexDispatch.md)'s object-type case-to-field mapping for cases `0..8`, matching [UID:0002CE][0x00532450-0x00532530.ObjectListTypeIndexExistsSwitchHelper](by-memory/0x00532450-0x00532530.ObjectListTypeIndexExistsSwitchHelper.md)'s predicate dispatch and preserving the current structural names for `+0x14`, `+0x18`, `+0x1c`, `+0x24`, `+0x20`, `+0x28`, `+0x2c`, `+0x30`, and `+0x34`.

### 2026-05-31 - Verified Constructor/Destructor Layout Agreement

- What existed before: the layout page listed ObjectList offsets and allocation rules but did not link to exact child lifecycle pages or record the constructor/destructor boundary evidence.
- What changed: the page now links the exact constructor and destructor pages, records the IDA-confirmed ranges, and ties allocation/cleanup behavior directly to the field offsets.
- Why: IDA MCP decompilation and byte checks show the constructor populates each listed field, the destructor cleans up the same layout, and the `0x0053125d-0x00531260` gap is padding rather than source-authored code.

### 2026-06-04 - Wording Refresh

- Score unchanged at `82/88`.
- What changed: replaced importer/output wording in the evidence-basis line with current documentation evidence.
- Why: the layout evidence comes from live IDA lifecycle/accessor analysis plus the linked ObjectList alias docs; importer-derived filenames are not needed to support the layout.
