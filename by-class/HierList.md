*** UID:000065 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct HierListNode;

class HierList : public List {
    friend class Layer;

public:
    HierList(int payloadSize, HierListNode *ownerNode);
    virtual ~HierList();

    void InsertLast(const void *parentPayload, const void *payload);
    void InsertFirst(const void *parentPayload, const void *payload);
    void InsertBefore(const void *parentPayload,
        const void *referencePayload, const void *payload);
    void InsertAfter(const void *parentPayload,
        const void *referencePayload, const void *payload);
    void RemoveByPayload(const void *payload);

    virtual void *GetElementAt(int index);
    virtual void InsertAt(int index, int count, void *source);
    virtual void Append(int count, void *source);
    virtual void RemoveAt(int index, int count);
    virtual void SwapElements(int firstIndex, int secondIndex);

protected:
    HierListNode *ownerNode;

private:
    HierListNode *FindNodeByPayload(const void *payload,
        HierList **outOwnerList, int *outIndex);
    void UpdateHierarchy(int firstIndex, int lastIndex, bool clearParent);

    [[CHILDREN]]
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# HierList

## Layer Consumer Synchronization - 2026-07-14

[UID:000073][Layer](by-class/Layer.md) is now an explicit friend solely so its exact private source can read `HierList::ownerNode` for the root row. This declaration-only access change does not move HierList source, change its `91/92` score, alter owner/emitter UID0000JV, or replace any existing accepted method body.

Layer supplies a 48-byte `LayerNode` payload to HierList. Each physical row therefore contains `HierListNode::parent` at `+0x00`, `childList` at `+0x04`, payload at `+0x08`, and the established 59-byte total stride. `Layer::AddChildBefore` calls UID0002IC, `AddChildAfter` calls UID0002ID, and `RemoveChild` calls UID0002IE. Layer's private search uses the optional owning-list/index outputs, while generic allocation, insertion, removal, and hierarchy repair remain HierList-owned.

The full managed declaration is replaced as one exact destination block. No prose-only declaration delta exists outside it, and no Layer implementation body is added to this page.



## Status

- Confidence: strong for behavior and source ownership.
- Likely source file: [UID:0000JV][HierList](by-file/HierList.md)
- Main memory range: [UID:00016X][0x004ce730-0x004cee52.HierList](by-memory/0x004ce730-0x004cee52.HierList.md), a non-emitting split/index whose exact child pages carry method output.
- Current recovered source: `source-3/simroot_v2/class_HierList.cpp`

## Class Purpose

`HierList` is a hierarchical list container built on [UID:000079][List](by-class/List.md). Each stored row has a small hierarchy header plus caller payload bytes. Child rows are represented by lazily allocated nested `HierList` instances, which lets UI layer code model parent/child pane trees while reusing the fixed-width list machinery.

## Observed Layout

```text
+0x00  List base/vtable
+0x04  int elementSizeWithHierarchyOverhead
+0x08  int pageSize
+0x0c  int count
+0x10  void* data
+0x14  HierListNode* ownerNode
```

The constructor calls `List::List(payloadSize + 11, 32)`, stores the owner/parent node pointer at `+0x14`, installs the `HierList` vtable, and writes the new list into `ownerNode + 0x04`.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x004ce730-0x004ce760` | [UID:0002I8][0x004ce730-0x004ce760.HierListConstructor](by-memory/0x004ce730-0x004ce760.HierListConstructor.md) | Constructs the base list and links the list to the parent node. |
| `0x004ce760-0x004ce7d1` | [UID:0002I9][0x004ce760-0x004ce7d1.HierListNonDeletingDestructor](by-memory/0x004ce760-0x004ce7d1.HierListNonDeletingDestructor.md) | Accepted source-authored `HierList::~HierList()` formal exact-child C++; releases child lists and lets compiler destructor sequencing emit base `List::~List()`. |
| `0x004ce7e0-0x004ce839` | [UID:0002IA][0x004ce7e0-0x004ce839.HierListTailInsertWrapper](by-memory/0x004ce7e0-0x004ce839.HierListTailInsertWrapper.md) | Accepted source-authored `HierList::InsertLast(const void *parentPayload, const void *payload)`; selects the root or child tail payload and delegates to `InsertBefore`. |
| `0x004ce840-0x004ce854` | [UID:0002IB][0x004ce840-0x004ce854.HierListDefaultInsertWrapper](by-memory/0x004ce840-0x004ce854.HierListDefaultInsertWrapper.md) | Accepted source-authored `HierList::InsertFirst(const void *parentPayload, const void *payload)` with formal exact-child C++; forwards a null reference payload to `InsertBefore`. |
| `0x004ce860-0x004ce9ad` | [UID:0002IC][0x004ce860-0x004ce9ad.HierListInsertBefore](by-memory/0x004ce860-0x004ce9ad.HierListInsertBefore.md) | Core `InsertBefore(parentPayload, referencePayload, payload)` implementation used by `InsertLast`, `InsertFirst`, and `Layer`. |
| `0x004ce9b0-0x004ceafc` | [UID:0002ID][0x004ce9b0-0x004ceafc.HierListInsertAfter](by-memory/0x004ce9b0-0x004ceafc.HierListInsertAfter.md) | Accepted source-authored `HierList::InsertAfter(const void *parentPayload, const void *referencePayload, const void *payload)` with formal exact-child C++; inserts after a reference payload or appends the selected root/child list tail. |
| `0x004ceb00-0x004ceb45` | [UID:0002IE][0x004ceb00-0x004ceb45.HierListRemoveNode](by-memory/0x004ceb00-0x004ceb45.HierListRemoveNode.md) | Accepted source-authored `HierList::RemoveByPayload(const void *payload)` with formal exact-child C++; resolves a payload to node/owner/index, deletes any child list, then removes one row through the owner list. |
| `0x004ceb50-0x004ceb62` | [UID:0002IF][0x004ceb50-0x004ceb62.HierListGetElementAt](by-memory/0x004ceb50-0x004ceb62.HierListGetElementAt.md) | Returns caller payload at stored node `+0x08`. |
| `0x004ceb70-0x004ceba9` | [UID:0002IG][0x004ceb70-0x004ceba9.HierListInsertAt](by-memory/0x004ceb70-0x004ceba9.HierListInsertAt.md) | Delegates to `List::InsertAt`, then repairs child parent pointers. |
| `0x004cebb0-0x004cebb9` | [UID:0002IH][0x004cebb0-0x004cebb9.HierListAppend](by-memory/0x004cebb0-0x004cebb9.HierListAppend.md) | Delegates to `List::Append`. |
| `0x004cebc0-0x004cebec` | [UID:0002II][0x004cebc0-0x004cebec.HierListRemoveAt](by-memory/0x004cebc0-0x004cebec.HierListRemoveAt.md) | Delegates to `List::RemoveAt`, then repairs following child parent pointers. |
| `0x004cebf0-0x004cec22` | [UID:0002IJ][0x004cebf0-0x004cec22.HierListSwapElements](by-memory/0x004cebf0-0x004cec22.HierListSwapElements.md) | Delegates to `List::SwapElements`, then repairs both swapped nodes. |
| `0x004cec30-0x004ced0f` | [UID:0002IK][0x004cec30-0x004ced0f.HierListFindNodeByData](by-memory/0x004cec30-0x004ced0f.HierListFindNodeByData.md) | Recursive payload comparison helper; exact child now carries formal first-draft `HierList::FindNodeByPayload` C++ and should not be treated as an empty-marker-only blocker. |
| `0x004ced10-0x004ceda4` | [UID:0002IL][0x004ced10-0x004ceda4.HierListUpdateHierarchy](by-memory/0x004ced10-0x004ceda4.HierListUpdateHierarchy.md) | Updates or clears child-list parent references after structural changes. |
| `0x004cedb0-0x004cee52` | [UID:0002IM][0x004cedb0-0x004cee52.HierListScalarDeletingDestructor](by-memory/0x004cedb0-0x004cee52.HierListScalarDeletingDestructor.md) | Compiler scalar deleting destructor ABI wrapper/no-code evidence; vtable-only route at `0x0061b344`, delete-flag/object-free handling, regenerated from `HierList::~HierList()` rather than hand-authored. |

## Ownership Notes

`Layer` is the main known client: its add-before/add-after/remove-child paths call the `HierList` insertion/removal API. The container itself should stay in a utility module and be consumed by `Layer`, not absorbed into `Layer.cpp`, because Wave2 import provenance and RTTI identify a standalone `HierList` class.

Wave3 active output historically omitted real HierList-local code: `0x004ce760`, `0x004ce7e0`, `0x004ce840`, `0x004ceb00`, and `0x004cec30`. These should be preserved in source migration. IDA caller checks on 2026-05-25 show `0x004ceb00` called by `Layer::RemoveChild` at `0x004f0a60`, while `0x004cec30` is called by `InsertBefore`, `InsertAfter`, `RemoveNode`, and itself recursively. IDA MCP `py_eval` on 2026-05-31 decoded the `0x004ce7e0` and `0x004ce840` wrappers even though IDA has no function objects for them.

The non-deleting destructor body at `0x004ce760` currently has no direct IDA caller. The scalar deleting wrapper at `0x004cedb0` duplicates the child-list teardown and handles the delete flag, while active `simroot_v2/class_HierList.cpp` emits a no-argument destructor body that still references a missing `deletionFlags` variable. Use the IDA wrapper shape before rewriting C++.

2026-06-17 B001 source-quality review keeps the exact method pages as the emitting route and makes [UID:00016X][0x004ce730-0x004cee52.HierList](by-memory/0x004ce730-0x004cee52.HierList.md) a non-emitting split/index. Best current source names from contextual evidence are `FindNodeByPayload` for the recursive data search, `RemoveByPayload` for the removal helper, and `RepairParentLinks` / `UpdateChildOwnerLinks` for hierarchy repair; existing page names remain stable documentation labels until a coordinated class source pass decides final API spelling.

2026-06-25 B004 accepted source-quality implementation resolves [UID:0002IK][0x004cec30-0x004ced0f.HierListFindNodeByData](by-memory/0x004cec30-0x004ced0f.HierListFindNodeByData.md) as the private emitted method `HierListNode *FindNodeByPayload(const void *payload, HierList **outOwnerList, int *outIndex);`. The method body uses inherited [UID:000079][List](by-class/List.md) fields `m_elementSize` and `m_count`, explicitly calls `List::GetElementAt(index)` for raw row access, compares against [UID:0001UQ][HierListNode](by-type/by-struct/HierListNode.md) `payload`, and recurses through `HierListNode::childList`. The support decision is target-local: the broader raw wrappers, destructor variants, remove helper, and hierarchy repair names still need coordinated class-wide C++ cleanup.

2026-06-26 B003 accepted source-quality implementation resolves [UID:0002IA][0x004ce7e0-0x004ce839.HierListTailInsertWrapper](by-memory/0x004ce7e0-0x004ce839.HierListTailInsertWrapper.md) as the emitted public method `void HierList::InsertLast(const void *parentPayload, const void *payload);`. The method uses [UID:000079][List](by-class/List.md) `m_count` and explicit `List::GetElementAt(m_count - 1)` raw-row access to find the current root tail when `parentPayload == NULL`, uses `FindNodeByPayload(parentPayload, NULL, NULL)` plus `HierListNode::childList` to find a parent's child-list tail, then delegates to [UID:0002IC][0x004ce860-0x004ce9ad.HierListInsertBefore](by-memory/0x004ce860-0x004ce9ad.HierListInsertBefore.md) with either the tail payload or a null reference payload. This report also fixes the insertion-family relationship: [UID:0002IB][0x004ce840-0x004ce854.HierListDefaultInsertWrapper](by-memory/0x004ce840-0x004ce854.HierListDefaultInsertWrapper.md) is the likely `InsertFirst(parentPayload, payload)`/head counterpart, [UID:0002IC][0x004ce860-0x004ce9ad.HierListInsertBefore](by-memory/0x004ce860-0x004ce9ad.HierListInsertBefore.md) is the three-argument `InsertBefore` core, and [UID:0002ID][0x004ce9b0-0x004ceafc.HierListInsertAfter](by-memory/0x004ce9b0-0x004ceafc.HierListInsertAfter.md) is the three-argument `InsertAfter` core. Rejected alternatives for [UID:0002IA][0x004ce7e0-0x004ce839.HierListTailInsertWrapper](by-memory/0x004ce7e0-0x004ce839.HierListTailInsertWrapper.md) are `Append`, `Layer` ownership, `List` ownership, a renamed file route, padding/no-source handling, and `InsertAtTailOfParent` as the primary source name.

2026-06-26 B015 accepted source-quality implementation resolves [UID:0002IB][0x004ce840-0x004ce854.HierListDefaultInsertWrapper](by-memory/0x004ce840-0x004ce854.HierListDefaultInsertWrapper.md) as the emitted public method `void HierList::InsertFirst(const void *parentPayload, const void *payload);`. The method is the compact first/default insertion wrapper: it forwards `parentPayload`, a null sibling/reference payload, and `payload` to [UID:0002IC][0x004ce860-0x004ce9ad.HierListInsertBefore](by-memory/0x004ce860-0x004ce9ad.HierListInsertBefore.md) as `InsertBefore(parentPayload, NULL, payload)`. Accepted evidence on active IDB session `80de0a67` records no modeled function or direct start xrefs at `0x004ce840`, the exact 20-byte wrapper body, unique signature/body match, and direct call `0x004ce84b -> 0x004ce860`. B010's 2026-07-01 class declaration implementation supersedes the former class-level blank-C++ state while preserving this exact child as the method body route.

2026-06-26 B007 accepted source-quality implementation resolves [UID:0002ID][0x004ce9b0-0x004ceafc.HierListInsertAfter](by-memory/0x004ce9b0-0x004ceafc.HierListInsertAfter.md) as the emitted public insertion core `void HierList::InsertAfter(const void *parentPayload, const void *referencePayload, const void *payload);`. The method allocates a zero-filled temporary `HierListNode`, copies `m_elementSize - 11` payload bytes, resolves the optional parent through accepted `FindNodeByPayload`, lazily creates `parentNode->childList` when needed, and inserts at `referenceIndex + 1`. Its null-reference behavior appends by defaulting the selected root/child list index to `m_count - 1`, unlike [UID:0002IC][0x004ce860-0x004ce9ad.HierListInsertBefore](by-memory/0x004ce860-0x004ce9ad.HierListInsertBefore.md), whose null-reference default is `-1`. The root/reference branch records but does not dispatch through the returned `referenceOwnerList`; the accepted source contract assumes the reference payload belongs to the already selected target list. B010's 2026-07-01 class declaration implementation supersedes the former class-level blank-C++ state while confirming that exact child [UID:0002ID][0x004ce9b0-0x004ceafc.HierListInsertAfter](by-memory/0x004ce9b0-0x004ceafc.HierListInsertAfter.md) remains the method body route.

2026-06-26 B001 accepted source-quality implementation resolves [UID:0002IE][0x004ceb00-0x004ceb45.HierListRemoveNode](by-memory/0x004ceb00-0x004ceb45.HierListRemoveNode.md) as the emitted public removal helper `void HierList::RemoveByPayload(const void *payload);`. The method consumes a caller payload pointer, calls the accepted private [UID:0002IK][0x004cec30-0x004ced0f.HierListFindNodeByData](by-memory/0x004cec30-0x004ced0f.HierListFindNodeByData.md) / `FindNodeByPayload(payload, &ownerList, &index)` helper, deletes and clears any `HierListNode::childList`, then calls the resolved owner list's virtual `RemoveAt(index, 1)` path. The by-memory label `HierListRemoveNode` remains a stable search/documentation alias, but the source-facing API should use `RemoveByPayload` because the caller does not pass a node pointer. B010's 2026-07-01 class declaration implementation supersedes the former class-level blank-C++ state while confirming that exact child [UID:0002IE][0x004ceb00-0x004ceb45.HierListRemoveNode](by-memory/0x004ceb00-0x004ceb45.HierListRemoveNode.md) remains the method body route.

2026-06-26 B011 accepted source-quality implementation resolves the destructor policy. [UID:0002I9][0x004ce760-0x004ce7d1.HierListNonDeletingDestructor](by-memory/0x004ce760-0x004ce7d1.HierListNonDeletingDestructor.md) is the source-authored `HierList::~HierList()` body and now carries formal exact-child C++; it iterates `m_count`, fetches rows through `List::GetElementAt(index)`, deletes non-null `HierListNode::childList`, and clears the child pointer. [UID:0002IM][0x004cedb0-0x004cee52.HierListScalarDeletingDestructor](by-memory/0x004cedb0-0x004cee52.HierListScalarDeletingDestructor.md) remains owned by this class for documentation but is non-reconstructable/non-emitting compiler scalar deleting destructor ABI glue. MCP session `80de0a67` confirmed the scalar wrapper's vtable-only pointer route at `0x0061b344`, no direct caller/raw pointer route beyond that slot, delete-flag/object-free/guarded-size behavior, and `retn 4`. Do not expose delete flags, object-free helpers, vtable stores, SEH/security-cookie scaffolding, or IDA `sub_` labels in final `HierList` source.

## Autogen Status

Attach this class to [UID:0000JV][HierList](by-file/HierList.md) as reconstructable metadata for `util/HierList.cpp`. B010's 2026-07-01 implementation inserts the class declaration shell and resolves the former flexible payload, `InsertBefore`, hierarchy-repair, and declaration-set blockers. Exact children [UID:0002I9][0x004ce760-0x004ce7d1.HierListNonDeletingDestructor](by-memory/0x004ce760-0x004ce7d1.HierListNonDeletingDestructor.md), [UID:0002IA][0x004ce7e0-0x004ce839.HierListTailInsertWrapper](by-memory/0x004ce7e0-0x004ce839.HierListTailInsertWrapper.md), [UID:0002IB][0x004ce840-0x004ce854.HierListDefaultInsertWrapper](by-memory/0x004ce840-0x004ce854.HierListDefaultInsertWrapper.md), [UID:0002IC][0x004ce860-0x004ce9ad.HierListInsertBefore](by-memory/0x004ce860-0x004ce9ad.HierListInsertBefore.md), [UID:0002ID][0x004ce9b0-0x004ceafc.HierListInsertAfter](by-memory/0x004ce9b0-0x004ceafc.HierListInsertAfter.md), [UID:0002IE][0x004ceb00-0x004ceb45.HierListRemoveNode](by-memory/0x004ceb00-0x004ceb45.HierListRemoveNode.md), [UID:0002IF][0x004ceb50-0x004ceb62.HierListGetElementAt](by-memory/0x004ceb50-0x004ceb62.HierListGetElementAt.md), [UID:0002IG][0x004ceb70-0x004ceba9.HierListInsertAt](by-memory/0x004ceb70-0x004ceba9.HierListInsertAt.md), [UID:0002IH][0x004cebb0-0x004cebb9.HierListAppend](by-memory/0x004cebb0-0x004cebb9.HierListAppend.md), [UID:0002II][0x004cebc0-0x004cebec.HierListRemoveAt](by-memory/0x004cebc0-0x004cebec.HierListRemoveAt.md), [UID:0002IJ][0x004cebf0-0x004cec22.HierListSwapElements](by-memory/0x004cebf0-0x004cec22.HierListSwapElements.md), [UID:0002IK][0x004cec30-0x004ced0f.HierListFindNodeByData](by-memory/0x004cec30-0x004ced0f.HierListFindNodeByData.md), and [UID:0002IL][0x004ced10-0x004ceda4.HierListUpdateHierarchy](by-memory/0x004ced10-0x004ceda4.HierListUpdateHierarchy.md) carry method bodies. [UID:0002IM][0x004cedb0-0x004cee52.HierListScalarDeletingDestructor](by-memory/0x004cedb0-0x004cee52.HierListScalarDeletingDestructor.md) is deliberately excluded from exact-child source emission because it is compiler-generated deleting-destructor ABI glue.

## Cross-References

- [UID:0000JV][HierList](by-file/HierList.md)
- [UID:00016X][0x004ce730-0x004cee52.HierList](by-memory/0x004ce730-0x004cee52.HierList.md)
- [UID:0001UQ][HierListNode](by-type/by-struct/HierListNode.md)
- [UID:000079][List](by-class/List.md)
- [UID:000073][Layer](by-class/Layer.md)

## Changes

- 2026-07-01 B010 accepted empty-emitter family implementation:
  - Raised this class to `COMPLETION:91`, `CONFIDENCE:92` and inserted the formal declaration shell for `HierList : public List`, preserving owner/emitter route [UID:0000JV][HierList](by-file/HierList.md) and exact-child body ownership.
  - The declaration preserves the accepted public insertion API (`InsertLast`, `InsertFirst`, `InsertBefore`, `InsertAfter`), `RemoveByPayload`, the virtual override set (`GetElementAt`, `InsertAt`, `Append`, `RemoveAt`, `SwapElements`), private `FindNodeByPayload`, and private `UpdateHierarchy`.
  - Preserved the class field model with inherited `List` fields plus `HierListNode *ownerNode` at complete object offset `+0x14`. This owner node is written by the constructor, read by root insertion helpers, and refreshed by `UpdateHierarchy`; [UID:0001UQ][HierListNode](by-type/by-struct/HierListNode.md) now supplies the formal flexible-payload node type.
  - Base `List` support now proves the source-facing return policy: `InsertAt`, `Append`, `RemoveAt`, and `SwapElements` are `void`; IDA return-register artifacts in the HierList override decompilations are not source API returns.
  - Rejected file-level or aggregate-level duplication of existing accepted child bodies. This page is the class declaration route; exact method bodies remain on their by-memory children.

- 2026-06-26 B007 accepted source-quality implementation support update:
  - Recorded [UID:0002ID][0x004ce9b0-0x004ceafc.HierListInsertAfter](by-memory/0x004ce9b0-0x004ceafc.HierListInsertAfter.md) as formal `HierList::InsertAfter(const void *parentPayload, const void *referencePayload, const void *payload)` C++ rather than an empty-marker-only insert-after core.
  - Added the insertion-family declaration context beside accepted `InsertFirst`, `InsertLast`, `RemoveByPayload`, and `FindNodeByPayload`, while preserving class-level blank C++ for coordinated declaration/source cleanup.
  - Documented the selected-list reference contract, default append behavior (`count - 1` before `+ 1`), zeroed allocation, and distinction from sibling [UID:0002IC][0x004ce860-0x004ce9ad.HierListInsertBefore](by-memory/0x004ce860-0x004ce9ad.HierListInsertBefore.md), which remained blank at that time and is superseded by B010's 2026-07-01 formal `InsertBefore` implementation.

- 2026-06-26 B011 accepted source-quality implementation support update:
  - Recorded [UID:0002I9][0x004ce760-0x004ce7d1.HierListNonDeletingDestructor](by-memory/0x004ce760-0x004ce7d1.HierListNonDeletingDestructor.md) as formal `HierList::~HierList()` C++ rather than a missing/blank destructor policy blocker.
  - Recorded [UID:0002IM][0x004cedb0-0x004cee52.HierListScalarDeletingDestructor](by-memory/0x004cedb0-0x004cee52.HierListScalarDeletingDestructor.md) as non-emitting compiler scalar deleting destructor ABI evidence generated from the class destructor/declaration.
  - Preserved class-level blank C++ for the coordinated declaration/source cleanup while documenting that the destructor source/no-code split is resolved.

- 2026-06-26 B001 accepted source-quality implementation support update:
  - Recorded [UID:0002IE][0x004ceb00-0x004ceb45.HierListRemoveNode](by-memory/0x004ceb00-0x004ceb45.HierListRemoveNode.md) as formal `HierList::RemoveByPayload(const void *payload)` C++ rather than a blank remove helper.
  - Documented the support dependency on `FindNodeByPayload(payload, &ownerList, &index)`, `HierListNode::childList`, and owner-list `RemoveAt(index, 1)`.
  - Preserved class-level blank C++ while documenting that [UID:0002IE][0x004ceb00-0x004ceb45.HierListRemoveNode](by-memory/0x004ceb00-0x004ceb45.HierListRemoveNode.md) now has exact-child first-draft C++ routed through this class.

- 2026-06-26 B015 accepted source-quality implementation support update:
  - Recorded [UID:0002IB][0x004ce840-0x004ce854.HierListDefaultInsertWrapper](by-memory/0x004ce840-0x004ce854.HierListDefaultInsertWrapper.md) as formal `HierList::InsertFirst(const void *parentPayload, const void *payload)` C++ rather than a likely/no-formal-C++ sibling note.
  - Updated the insertion-family method map: `0002IA` is `InsertLast`, `0002IB` is `InsertFirst`, `0002IC` is `InsertBefore`, and `0002ID` is `InsertAfter`.
  - Preserved class-level blank C++ while documenting that [UID:0002IB][0x004ce840-0x004ce854.HierListDefaultInsertWrapper](by-memory/0x004ce840-0x004ce854.HierListDefaultInsertWrapper.md) now has exact-child first-draft C++ routed through this class.

- 2026-06-26 B003 accepted source-quality implementation support update:
  - Recorded [UID:0002IA][0x004ce7e0-0x004ce839.HierListTailInsertWrapper](by-memory/0x004ce7e0-0x004ce839.HierListTailInsertWrapper.md) as formal `HierList::InsertLast(const void *parentPayload, const void *payload)` C++ rather than an empty raw-wrapper marker.
  - Updated the insertion-family method map at that time: `0002IA` is `InsertLast`, `0002IB` was the likely `InsertFirst`/head counterpart without B003 formal C++, `0002IC` is `InsertBefore`, and `0002ID` is `InsertAfter`. B015 supersedes the `0002IB` no-formal-C++ state with formal `InsertFirst` C++.
  - Documented the accepted support dependencies on `List::GetElementAt`, inherited `m_count`, `HierListNode::payload`, `HierListNode::childList`, and `FindNodeByPayload`, and recorded rejected `Append`/`Layer`/`List`/rename/padding alternatives.

- 2026-06-25 B004 accepted source-quality implementation support update:
  - Recorded [UID:0002IK][0x004cec30-0x004ced0f.HierListFindNodeByData](by-memory/0x004cec30-0x004ced0f.HierListFindNodeByData.md) as formal first-draft `HierList::FindNodeByPayload` C++ rather than an empty generated marker.
  - Added the private method declaration/source-shape context: `HierListNode *FindNodeByPayload(const void *payload, HierList **outOwnerList, int *outIndex);`.
  - Documented that the method intentionally uses inherited `m_elementSize`/`m_count`, explicit base `List::GetElementAt(index)` raw-row access, `HierListNode::payload`, and `HierListNode::childList`, while broader wrappers/destructors still require a class-wide source pass.

- 2026-06-17 B001 HierList source-quality support update:
  - Clarified that [UID:00016X][0x004ce730-0x004cee52.HierList](by-memory/0x004ce730-0x004cee52.HierList.md) is now a non-emitting split/index while exact child methods carry source ownership under this class.
  - Standardized the class owner field at `+0x14` as `ownerNode`, clarified child node linkage through `ownerNode + 0x04`, and recorded B001's best current method-name inferences and rejected `Layer`/`List` ownership alternatives.
  - Kept class score and formal C++ unchanged; this pass fixes routing/source-quality support while deferring class-wide C++ until signatures and wrapper policy are coordinated.

- Completion/confidence score update: existed before as `0/0`; changed to `84/88`. Summary: container purpose, observed layout, constructor/destructor and mutation/search methods, omitted Wave3-local functions, Layer consumption, and rewrite caveats are documented in detail with strong confidence. Evidence: `0x004ce730-0x004cee52.HierList`, `HierListNode`, `List`, and `Layer` cross-references plus caller notes for missing active-output methods.

### 2026-05-31 - Exact child pages and raw wrappers added

- What existed before: method coverage was summarized through one aggregate memory page and omitted the raw wrapper bodies in the former `0x004ce7d1-0x004ce85f` gap.
- Changed to: score raised to `86/90`, `RECONSTRUCTABLE:TRUE`, and the method map now links exact child range pages including `0x004ce7e0` and `0x004ce840`.
- Summary/evidence: IDA MCP function enumeration, disassembly, xrefs, and byte review confirmed all function/wrapper/padding boundaries. The page remains below 95 because final source names, overload shape, and C++ declaration form are not exhaustively audited.

### 2026-06-02 - Parent attachment

- What existed before: class metadata was reconstructable but had no autogen parent.
- Changed to: attached to [UID:0000JV][HierList](by-file/HierList.md) with C++ blank.
- Summary/evidence: the file page is `82/85`, this class is `86/90`, and both pages identify `util/HierList.cpp` as the correct owner while preserving final-code caveats.
