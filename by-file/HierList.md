*** UID:0000JV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# HierList

## Status

- Proposed module: `util/HierList.cpp`
- Confidence: strong for standalone class ownership and `util/` placement.
- Current recovered source: `source-3/simroot_v2/class_HierList.cpp`

## File Role

`HierList.cpp` owns the tree-aware list container used by [UID:0000KL][Layer](by-file/Layer.md) to manage child pane hierarchy. It is not a UI pane class itself; it is reusable list infrastructure layered on [UID:0000KS][List](by-file/List.md).

## Proposed Contents

- [UID:000065][HierList](by-class/HierList.md)
- [UID:0001UQ][HierListNode](by-type/by-struct/HierListNode.md)
- [UID:00016X][0x004ce730-0x004cee52.HierList](by-memory/0x004ce730-0x004cee52.HierList.md) non-emitting split/index and exact child range pages.
- `0x004ce7e0` accepted as formal `HierList::InsertLast(const void *parentPayload, const void *payload)` C++ on the exact child page
- `0x004ce840` accepted as formal `HierList::InsertFirst(const void *parentPayload, const void *payload)` C++ on the exact child page
- `0x004ce9b0` accepted as formal `HierList::InsertAfter(const void *parentPayload, const void *referencePayload, const void *payload)` C++ on the exact child page
- recursive node lookup helper at `0x004cec30` (`HierList::FindNodeByPayload`, with formal C++ on the exact child page)
- `0x004ceb00` accepted as formal `HierList::RemoveByPayload(const void *payload)` C++ on the exact child page
- [UID:0002I9][0x004ce760-0x004ce7d1.HierListNonDeletingDestructor](by-memory/0x004ce760-0x004ce7d1.HierListNonDeletingDestructor.md) accepted as formal source `HierList::~HierList()` C++ on the exact child page
- [UID:0002IM][0x004cedb0-0x004cee52.HierListScalarDeletingDestructor](by-memory/0x004cedb0-0x004cee52.HierListScalarDeletingDestructor.md) documented as compiler-generated scalar deleting destructor ABI wrapper/no-code evidence, not a hand-authored source method

## Evidence

- Wave3 import provenance names `HierList.cpp`.
- IDA MCP confirms the constructor, insertion, removal, lookup, hierarchy-update, and destructor functions in the `0x004ce730-0x004cee52` cluster.
- `Layer::AddChildBefore` calls `HierList::InsertBefore`; `Layer::AddChildAfter` calls `HierList::InsertAfter`; `Layer::RemoveChild` calls the remove-node helper at `0x004ceb00`.
- IDA caller checks on 2026-05-25 show the recursive find helper at `0x004cec30` is shared by both insert paths, the remove helper, and its own recursive descent.
- `HierList` installs its own vtable at `0x0061b344` but shares base `List` virtual behavior where it does not need tree-specific repair.
- 2026-06-14 live IDA MCP session `b001_0002bd` reconfirmed active `NexusTK.exe.i64` with auto-analysis and Hex-Rays ready.
- 2026-06-14 `lookup_funcs` reconfirmed the compact HierList cluster around constructor `0x004ce730`, non-deleting destructor `0x004ce760`, insert core `0x004ce860`, insert-after `0x004ce9b0`, remove helper `0x004ceb00`, recursive lookup `0x004cec30`, scalar deleting destructor `0x004cedb0`, no function objects at raw wrapper starts `0x004ce7e0`/`0x004ce840`, and the unrelated HourPane successor function at `0x004cee60`.
- 2026-06-14 `xrefs_to 0x004ce860` reconfirmed the three local wrapper/raw calls at `0x004ce802`, `0x004ce82e`, and `0x004ce84b`, plus the Layer-facing call at `0x004f0a3b`; `xrefs_to 0x004cec30` reconfirmed lookup use from both insert cores, remove, the tail wrapper, and recursive descent.
- 2026-06-14 `analyze_component` reconfirmed the class-local component, shared HierList vtable `0x0061b344`, shared security cookie use in the larger insert/destructor bodies, and internal call graph edges from remove/insert/insert-after into `FindNodeByData`.
- 2026-06-14 local `int_convert.py` verified representative cluster sizes used by the memory pages: `0x30` / 48, `0x71` / 113, `0x14d` / 333, `0x14c` / 332, `0x45` / 69, `0xdf` / 223, `0x94` / 148, and `0xa2` / 162.
- 2026-06-17 B001 source-quality review reclassifies [UID:00016X][0x004ce730-0x004cee52.HierList](by-memory/0x004ce730-0x004cee52.HierList.md) as a non-emitting method-cluster index, keeps exact child methods owned by [UID:000065][HierList](by-class/HierList.md), validates Layer as caller/consumer rather than owner, and treats `List` as the base container rather than the source owner for hierarchy-specific methods.
- 2026-06-25 B004 MCP session `80de0a67` reconfirmed [UID:0002IK][0x004cec30-0x004ced0f.HierListFindNodeByData](by-memory/0x004cec30-0x004ced0f.HierListFindNodeByData.md) as the recursive lookup helper used from the raw tail wrapper ref `0x004ce812`, insert-before refs `0x004ce8d5`/`0x004ce906`/`0x004ce974`, insert-after refs `0x004cea28`/`0x004cea59`/`0x004ceac3`, remove ref `0x004ceb12`, and self-recursion `0x004cecca`.
- 2026-06-26 B003 MCP session `cbb3bd71-c728-4640-983e-ef6623343878` on active IDB `80de0a67` accepted [UID:0002IA][0x004ce7e0-0x004ce839.HierListTailInsertWrapper](by-memory/0x004ce7e0-0x004ce839.HierListTailInsertWrapper.md) as `HierList::InsertLast(parentPayload, payload)`. The two direct raw calls at `0x004ce802` and `0x004ce82e` are `InsertLast` delegations into [UID:0002IC][0x004ce860-0x004ce9ad.HierListInsertBefore](by-memory/0x004ce860-0x004ce9ad.HierListInsertBefore.md) with either a tail payload reference or a null reference payload.
- 2026-06-26 B015 accepted [UID:0002IB][0x004ce840-0x004ce854.HierListDefaultInsertWrapper](by-memory/0x004ce840-0x004ce854.HierListDefaultInsertWrapper.md) as `HierList::InsertFirst(parentPayload, payload)` on active IDB session `80de0a67`. The direct raw call at `0x004ce84b` is now a source-level `InsertFirst` delegation into [UID:0002IC][0x004ce860-0x004ce9ad.HierListInsertBefore](by-memory/0x004ce860-0x004ce9ad.HierListInsertBefore.md) with a null sibling/reference payload, producing insertion at slot `0`.
- 2026-06-26 B007 accepted [UID:0002ID][0x004ce9b0-0x004ceafc.HierListInsertAfter](by-memory/0x004ce9b0-0x004ceafc.HierListInsertAfter.md) as `HierList::InsertAfter(parentPayload, referencePayload, payload)` on active IDB session `80de0a67`. Live MCP health id `635` confirmed an analysis-ready `NexusTK.exe.i64`; function/analyze/xref/byte/signature/disassembly checks confirmed the exact `0x004ce9b0-0x004ceafc` body, one Layer caller at `0x004f081a`, child-list creation, zeroed row allocation, `FindNodeByPayload` reference lookup, default append index `m_count - 1`, and the selected-list reference contract where root insertion still dispatches through `this` rather than the returned `referenceOwnerList`.
- 2026-06-26 B001 accepted [UID:0002IE][0x004ceb00-0x004ceb45.HierListRemoveNode](by-memory/0x004ceb00-0x004ceb45.HierListRemoveNode.md) as `HierList::RemoveByPayload(payload)` on active IDB session `80de0a67`. The method calls [UID:0002IK][0x004cec30-0x004ced0f.HierListFindNodeByData](by-memory/0x004cec30-0x004ced0f.HierListFindNodeByData.md) / `FindNodeByPayload(payload, &ownerList, &index)`, deletes and clears any `HierListNode::childList`, then dispatches `ownerList->RemoveAt(index, 1)`. `HierListRemoveNode` remains the stable by-memory label, but `RemoveByPayload` is the accepted source-facing role because the caller passes payload bytes rather than a node pointer.
- 2026-06-26 B011 accepted [UID:0002I9][0x004ce760-0x004ce7d1.HierListNonDeletingDestructor](by-memory/0x004ce760-0x004ce7d1.HierListNonDeletingDestructor.md) as the source `HierList::~HierList()` body and [UID:0002IM][0x004cedb0-0x004cee52.HierListScalarDeletingDestructor](by-memory/0x004cedb0-0x004cee52.HierListScalarDeletingDestructor.md) as non-emitting compiler scalar deleting destructor ABI glue. MCP session `80de0a67` confirmed [UID:0002IM][0x004cedb0-0x004cee52.HierListScalarDeletingDestructor](by-memory/0x004cedb0-0x004cee52.HierListScalarDeletingDestructor.md)'s vtable-only route at `0x0061b344`, unique raw pointer match at that slot, no direct caller route, delete-flag/object-free/guarded-size behavior, and the source destructor's matching child-list cleanup without delete-flag/free logic.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 85 | The page records the proposed `NexusTK/util/` source root, standalone class/file role, full cluster inventory, omitted raw wrappers/destructor/remove/find helpers, Layer/List relationships, vtable evidence, current live IDA boundary/xref/component evidence, and migration caveats. |
| Confidence | 87 | Current IDA evidence strongly supports the compact HierList utility container and file route. Confidence remains below final because original header/API overload names and final destructor/wrapper source form are not fully proven. |

## Migration Notes

Do not migrate directly from active `class_HierList.cpp` without adding or preserving the IDA-confirmed helper functions:

- `0x004ce760` `HierList::~HierList()` source destructor body, now represented by formal exact-child C++
- `0x004ce7e0` `InsertLast(parentPayload, payload)` tail insert wrapper, now represented by formal exact-child C++
- `0x004ce840` `InsertFirst(parentPayload, payload)` null-reference/head insert wrapper, now represented by formal exact-child C++
- `0x004ceb00` `RemoveByPayload(payload)` removal helper, now represented by formal exact-child C++

[UID:0002IK][0x004cec30-0x004ced0f.HierListFindNodeByData](by-memory/0x004cec30-0x004ced0f.HierListFindNodeByData.md) is now represented by formal exact-child C++ as `HierList::FindNodeByPayload`; it should be included in the source route rather than treated as an empty-marker-only missing helper. The file-level source scaffold needs the C runtime byte-compare declaration, such as `<string.h>` or the project-local equivalent, for that method body's `memcmp` call.

[UID:0002IA][0x004ce7e0-0x004ce839.HierListTailInsertWrapper](by-memory/0x004ce7e0-0x004ce839.HierListTailInsertWrapper.md) is now represented by formal exact-child C++ as `HierList::InsertLast`; it should be included in the source route rather than treated as an empty-marker-only raw wrapper. Its accepted source form depends on inherited `m_count`, explicit `List::GetElementAt`, `HierListNode::payload`, `HierListNode::childList`, and `FindNodeByPayload`.

[UID:0002IB][0x004ce840-0x004ce854.HierListDefaultInsertWrapper](by-memory/0x004ce840-0x004ce854.HierListDefaultInsertWrapper.md) is now represented by formal exact-child C++ as `HierList::InsertFirst`; it should be included in the source route rather than treated as an unresolved raw wrapper. Its accepted source form is the compact delegate `InsertBefore(parentPayload, NULL, payload)`, with the null sibling/reference causing the insert-before core to place the new row at index `0`.

[UID:0002ID][0x004ce9b0-0x004ceafc.HierListInsertAfter](by-memory/0x004ce9b0-0x004ceafc.HierListInsertAfter.md) is now represented by formal exact-child C++ as `HierList::InsertAfter`; it should be included in the source route rather than treated as an unresolved empty-marker insert-after core. Its accepted source form allocates a zero-filled temporary `HierListNode`, copies `m_elementSize - 11` payload bytes, resolves optional parent/reference payloads through `FindNodeByPayload`, lazily creates `parentNode->childList`, and inserts at `referenceIndex + 1`. Null reference appends by defaulting the selected root/child list index to `count - 1`; this differs from [UID:0002IC][0x004ce860-0x004ce9ad.HierListInsertBefore](by-memory/0x004ce860-0x004ce9ad.HierListInsertBefore.md), whose null-reference default is `-1`. The root/reference branch records `referenceOwnerList` but still dispatches through `this`, so final source should preserve the selected-list reference contract and not rewrite the method as arbitrary returned-owner insertion.

[UID:0002IE][0x004ceb00-0x004ceb45.HierListRemoveNode](by-memory/0x004ceb00-0x004ceb45.HierListRemoveNode.md) is now represented by formal exact-child C++ as `HierList::RemoveByPayload`; it should be included in the source route rather than treated as an unresolved blank remove helper. Its accepted source form resolves a caller payload to `node`, `ownerList`, and `index` through `FindNodeByPayload`, releases `node->childList` with source-level `delete`, clears the child pointer, and removes one owner-list row with `ownerList->RemoveAt(index, 1)`.

[UID:0002I9][0x004ce760-0x004ce7d1.HierListNonDeletingDestructor](by-memory/0x004ce760-0x004ce7d1.HierListNonDeletingDestructor.md) is now represented by formal exact-child C++ as `HierList::~HierList()`. Its accepted source body iterates inherited `m_count`, uses `List::GetElementAt(index)` to fetch each `HierListNode`, deletes non-null `node->childList`, and clears the pointer. Do not manually emit `List::~List()` or object-free logic inside that body; the compiler emits base destructor chaining and [UID:0002IM][0x004cedb0-0x004cee52.HierListScalarDeletingDestructor](by-memory/0x004cedb0-0x004cee52.HierListScalarDeletingDestructor.md) for scalar-delete ABI behavior.

[UID:0002IM][0x004cedb0-0x004cee52.HierListScalarDeletingDestructor](by-memory/0x004cedb0-0x004cee52.HierListScalarDeletingDestructor.md) must remain generated wrapper evidence, not a hand-authored source method. The stale generated destructor body that references a delete flag in a no-argument source signature is superseded by the current split: source emits `HierList::~HierList()` through [UID:0002I9][0x004ce760-0x004ce7d1.HierListNonDeletingDestructor](by-memory/0x004ce760-0x004ce7d1.HierListNonDeletingDestructor.md), and the compiler/linker regenerates the scalar deleting wrapper.

Do not emit aggregate C++ from [UID:00016X][0x004ce730-0x004cee52.HierList](by-memory/0x004ce730-0x004cee52.HierList.md). Populate HierList source through the class declaration and exact child pages. B010's 2026-07-01 implementation resolves the former blanks for `InsertBefore`, `GetElementAt`, mutation wrappers, `UpdateHierarchy`, constructor, `HierListNode`, and vtable data; exact accepted children remain the source body route and the aggregate stays non-emitting.

## Cross-References

- [UID:000065][HierList](by-class/HierList.md)
- [UID:00016X][0x004ce730-0x004cee52.HierList](by-memory/0x004ce730-0x004cee52.HierList.md)
- [UID:0000KS][List](by-file/List.md)
- [UID:0000KL][Layer](by-file/Layer.md)

## Changes

- 2026-07-01 B010 accepted empty-emitter family implementation:
  - Raised this file to `COMPLETION:91`, `CONFIDENCE:91` after resolving the current 11 generated empty markers for `auto-generated/NexusTK/util/HierList.cpp`; expected refreshed generated state is `17` total HierList emitters, `17` filled, `0` empty.
  - Preserved [UID:0000JV][HierList](by-file/HierList.md) as the file owner for `NexusTK/util/HierList.cpp`; [UID:000065][HierList](by-class/HierList.md) owns the class declaration and exact child pages own source method bodies. File-level body duplication is rejected, so already accepted exact children [UID:0002I9][0x004ce760-0x004ce7d1.HierListNonDeletingDestructor](by-memory/0x004ce760-0x004ce7d1.HierListNonDeletingDestructor.md), [UID:0002IA][0x004ce7e0-0x004ce839.HierListTailInsertWrapper](by-memory/0x004ce7e0-0x004ce839.HierListTailInsertWrapper.md), [UID:0002IB][0x004ce840-0x004ce854.HierListDefaultInsertWrapper](by-memory/0x004ce840-0x004ce854.HierListDefaultInsertWrapper.md), [UID:0002ID][0x004ce9b0-0x004ceafc.HierListInsertAfter](by-memory/0x004ce9b0-0x004ceafc.HierListInsertAfter.md), [UID:0002IE][0x004ceb00-0x004ceb45.HierListRemoveNode](by-memory/0x004ceb00-0x004ceb45.HierListRemoveNode.md), and [UID:0002IK][0x004cec30-0x004ced0f.HierListFindNodeByData](by-memory/0x004cec30-0x004ced0f.HierListFindNodeByData.md) remain the only source body locations for their methods.
  - Recorded that [UID:0002I8][0x004ce730-0x004ce760.HierListConstructor](by-memory/0x004ce730-0x004ce760.HierListConstructor.md), [UID:0002IC][0x004ce860-0x004ce9ad.HierListInsertBefore](by-memory/0x004ce860-0x004ce9ad.HierListInsertBefore.md), [UID:0002IF][0x004ceb50-0x004ceb62.HierListGetElementAt](by-memory/0x004ceb50-0x004ceb62.HierListGetElementAt.md), [UID:0002IG][0x004ceb70-0x004ceba9.HierListInsertAt](by-memory/0x004ceb70-0x004ceba9.HierListInsertAt.md), [UID:0002IH][0x004cebb0-0x004cebb9.HierListAppend](by-memory/0x004cebb0-0x004cebb9.HierListAppend.md), [UID:0002II][0x004cebc0-0x004cebec.HierListRemoveAt](by-memory/0x004cebc0-0x004cebec.HierListRemoveAt.md), [UID:0002IJ][0x004cebf0-0x004cec22.HierListSwapElements](by-memory/0x004cebf0-0x004cec22.HierListSwapElements.md), [UID:0002IL][0x004ced10-0x004ceda4.HierListUpdateHierarchy](by-memory/0x004ced10-0x004ceda4.HierListUpdateHierarchy.md), [UID:0001UQ][HierListNode](by-type/by-struct/HierListNode.md), and [UID:000065][HierList](by-class/HierList.md) now have formal first-draft C++ or declaration content, while [UID:0003BL][0x0061b340-0x0061b36c.HierListVtableData](by-memory/0x0061b340-0x0061b36c.HierListVtableData.md) has a formal no-handwritten-vtable-data marker. [UID:00016X][0x004ce730-0x004cee52.HierList](by-memory/0x004ce730-0x004cee52.HierList.md) remains the non-emitting physical aggregate/index.
  - Current B010 MCP evidence used active session `supervisor_resume_20260629`, with function sizes for `0x004ce730`, `0x004ce860`, `0x004ceb50`, `0x004ceb70`, `0x004cebb0`, `0x004cebc0`, `0x004cebf0`, and `0x004ced10`, plus vtable bytes at `0x0061b340`. That evidence resolved base-List return policy, `HierListNode` flexible-payload layout, `InsertBefore` source shape, and generated vtable-data handling.

- 2026-06-26 B007 accepted source-quality implementation support update:
  - Recorded [UID:0002ID][0x004ce9b0-0x004ceafc.HierListInsertAfter](by-memory/0x004ce9b0-0x004ceafc.HierListInsertAfter.md) as formal exact-child `HierList::InsertAfter` C++ and removed it from the unresolved empty-marker insert-core bucket.
  - Updated proposed contents and migration notes so `0x004ce9b0` must be emitted through its exact child page, with generated output refreshed through validators rather than manual generated-file edits.
  - Preserved [UID:0002IC][0x004ce860-0x004ce9ad.HierListInsertBefore](by-memory/0x004ce860-0x004ce9ad.HierListInsertBefore.md) as the remaining insert-core formal-C++ gap until its own callback is accepted.

- 2026-06-26 B011 accepted source-quality implementation support update:
  - Recorded [UID:0002I9][0x004ce760-0x004ce7d1.HierListNonDeletingDestructor](by-memory/0x004ce760-0x004ce7d1.HierListNonDeletingDestructor.md) as formal exact-child `HierList::~HierList()` C++.
  - Recorded [UID:0002IM][0x004cedb0-0x004cee52.HierListScalarDeletingDestructor](by-memory/0x004cedb0-0x004cee52.HierListScalarDeletingDestructor.md) as non-emitting compiler scalar deleting destructor ABI evidence and removed it from the hand-authored destructor source bucket.
  - Updated migration notes so the stale delete-flag-in-source destructor shape is superseded by source `HierList::~HierList()` plus compiler-generated scalar deleting wrapper output.

- 2026-06-26 B001 accepted source-quality implementation support update:
  - Recorded [UID:0002IE][0x004ceb00-0x004ceb45.HierListRemoveNode](by-memory/0x004ceb00-0x004ceb45.HierListRemoveNode.md) as formal exact-child `HierList::RemoveByPayload` C++ and removed it from the unresolved blank remove-helper bucket.
  - Updated proposed contents and migration notes so `0x004ceb00` must be emitted through its exact child page.
  - Added current MCP proof context for `0x004f0b25` calling the payload removal helper from `Layer::RemoveChild`, and for the target's lookup, child-list delete/clear, and owner-list `RemoveAt(index, 1)` behavior.

- 2026-06-26 B015 accepted source-quality implementation support update:
  - Recorded [UID:0002IB][0x004ce840-0x004ce854.HierListDefaultInsertWrapper](by-memory/0x004ce840-0x004ce854.HierListDefaultInsertWrapper.md) as formal exact-child `HierList::InsertFirst` C++ and removed it from the unresolved wrapper bucket.
  - Updated proposed contents and migration notes so `0x004ce840` must be emitted through its exact child page.
  - Added current MCP proof context for `0x004ce84b` delegating from `InsertFirst` into the `InsertBefore` core with a null sibling/reference payload.

- 2026-06-26 B003 accepted source-quality implementation support update:
  - Recorded [UID:0002IA][0x004ce7e0-0x004ce839.HierListTailInsertWrapper](by-memory/0x004ce7e0-0x004ce839.HierListTailInsertWrapper.md) as formal exact-child `HierList::InsertLast` C++ and removed it from the unresolved empty-marker wrapper bucket.
  - Updated migration notes at that time so `0x004ce840` remained the likely `InsertFirst`/head counterpart without B003 formal C++, while `0002IA` must be emitted through its exact child page. B015 supersedes the `0x004ce840` no-formal-C++ state with formal `InsertFirst` exact-child output.
  - Added current MCP proof context for `0x004ce802`/`0x004ce82e` delegating from `InsertLast` into the `InsertBefore` core.

- 2026-06-25 B004 accepted source-quality implementation support update:
  - Recorded [UID:0002IK][0x004cec30-0x004ced0f.HierListFindNodeByData](by-memory/0x004cec30-0x004ced0f.HierListFindNodeByData.md) as formal `HierList::FindNodeByPayload` C++ on the exact child page.
  - Added current MCP session `80de0a67` fan-in evidence from raw wrapper, insert-before, insert-after, remove, and self-recursion refs.
  - Updated migration notes so the recursive lookup is no longer treated as an empty-marker-only blocker and recorded the `memcmp` include/declaration requirement for the `HierList.cpp` source scaffold.

- 2026-06-17 B001 HierList source-quality support update:
  - Recorded [UID:00016X][0x004ce730-0x004cee52.HierList](by-memory/0x004ce730-0x004cee52.HierList.md) as a non-emitting split/index and confirmed exact child pages remain the source-bearing route for `util/HierList.cpp`.
  - Added the B001 ownership/source-placement conclusion: `HierList` remains a standalone utility file, `Layer` is caller evidence only, and `List` is the base storage implementation rather than owner of hierarchy-specific code.
  - Kept file score/path unchanged; the accepted report updates the aggregate and child pages rather than changing the file root.

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:78` and `CONFIDENCE:80`.
  - Summary/evidence: standalone tree-list role, `List`/`Layer` relationship, constructor/destructor/helper evidence, migration caveats, and type references are documented; completion is lower because detailed per-method mapping and source-form pseudocode remain light.

- 2026-05-31 exact range split and projected path:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank and the file page listed only the broad aggregate plus three omitted helpers.
  - Changed to: path set to `NexusTK/util/`, scores raised to `82/85`, and migration notes now include the raw wrapper bodies.
  - Summary/evidence: proposed source tree already places `HierList.cpp` under `util/`; IDA MCP verified exact function/wrapper ranges and confirmed `Layer` consumes the container without making it a UI-owned file.

- 2026-06-14 Goal 2 support pass:
  - What existed before: scored `82/85` and supported the target wrappers but lacked current post-refresh IDA evidence.
  - Changed to: scored `85/87` with current live IDA MCP lookup/xref/component evidence and an explicit score rationale.
  - Summary/evidence: IDA reconfirmed the compact class-local HierList cluster, raw unmodeled wrapper starts, `Layer` call into the insert core, recursive lookup fan-in, shared HierList vtable, and unrelated HourPane successor. The file remains below final-audit confidence until the exact original API/header names and wrapper/destructor source form are settled.
