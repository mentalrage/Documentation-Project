*** UID:000065 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# HierList

## Status

- Confidence: strong for behavior and source ownership.
- Likely source file: [UID:0000JV][HierList](by-file/HierList.md)
- Main memory range: [UID:00016X][0x004ce730-0x004cee52.HierList](by-memory/0x004ce730-0x004cee52.HierList.md)
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
+0x14  void* parentNodeOrOwner
```

The constructor calls `List::List(elementSize + 11, 32)`, stores the owner/parent pointer at `+0x14`, installs the `HierList` vtable, and writes the new list into `parentNode + 4`.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x004ce730-0x004ce760` | [UID:0002I8][0x004ce730-0x004ce760.HierListConstructor](by-memory/0x004ce730-0x004ce760.HierListConstructor.md) | Constructs the base list and links the list to the parent node. |
| `0x004ce760-0x004ce7d1` | [UID:0002I9][0x004ce760-0x004ce7d1.HierListNonDeletingDestructor](by-memory/0x004ce760-0x004ce7d1.HierListNonDeletingDestructor.md) | Releases child lists and destroys the base list. Missing from active Wave3 output. |
| `0x004ce7e0-0x004ce839` | [UID:0002IA][0x004ce7e0-0x004ce839.HierListTailInsertWrapper](by-memory/0x004ce7e0-0x004ce839.HierListTailInsertWrapper.md) | IDA-unmodeled wrapper that chooses a tail/default sibling and forwards to the insert-before core. |
| `0x004ce840-0x004ce854` | [UID:0002IB][0x004ce840-0x004ce854.HierListDefaultInsertWrapper](by-memory/0x004ce840-0x004ce854.HierListDefaultInsertWrapper.md) | IDA-unmodeled wrapper that forwards a null sibling to the insert-before core. |
| `0x004ce860-0x004ce9ad` | [UID:0002IC][0x004ce860-0x004ce9ad.HierListInsertBefore](by-memory/0x004ce860-0x004ce9ad.HierListInsertBefore.md) | Finds or creates the target child list and inserts before a sibling. |
| `0x004ce9b0-0x004ceafc` | [UID:0002ID][0x004ce9b0-0x004ceafc.HierListInsertAfter](by-memory/0x004ce9b0-0x004ceafc.HierListInsertAfter.md) | Finds or creates the target child list and inserts after a sibling. |
| `0x004ceb00-0x004ceb45` | [UID:0002IE][0x004ceb00-0x004ceb45.HierListRemoveNode](by-memory/0x004ceb00-0x004ceb45.HierListRemoveNode.md) | Finds a node by payload, destroys its child list, then removes it from its owner list. Missing from active Wave3 output. |
| `0x004ceb50-0x004ceb62` | [UID:0002IF][0x004ceb50-0x004ceb62.HierListGetElementAt](by-memory/0x004ceb50-0x004ceb62.HierListGetElementAt.md) | Returns caller payload at stored node `+0x08`. |
| `0x004ceb70-0x004ceba9` | [UID:0002IG][0x004ceb70-0x004ceba9.HierListInsertAt](by-memory/0x004ceb70-0x004ceba9.HierListInsertAt.md) | Delegates to `List::InsertAt`, then repairs child parent pointers. |
| `0x004cebb0-0x004cebb9` | [UID:0002IH][0x004cebb0-0x004cebb9.HierListAppend](by-memory/0x004cebb0-0x004cebb9.HierListAppend.md) | Delegates to `List::Append`. |
| `0x004cebc0-0x004cebec` | [UID:0002II][0x004cebc0-0x004cebec.HierListRemoveAt](by-memory/0x004cebc0-0x004cebec.HierListRemoveAt.md) | Delegates to `List::RemoveAt`, then repairs following child parent pointers. |
| `0x004cebf0-0x004cec22` | [UID:0002IJ][0x004cebf0-0x004cec22.HierListSwapElements](by-memory/0x004cebf0-0x004cec22.HierListSwapElements.md) | Delegates to `List::SwapElements`, then repairs both swapped nodes. |
| `0x004cec30-0x004ced0f` | [UID:0002IK][0x004cec30-0x004ced0f.HierListFindNodeByData](by-memory/0x004cec30-0x004ced0f.HierListFindNodeByData.md) | Recursive payload comparison helper. Missing from active Wave3 output. |
| `0x004ced10-0x004ceda4` | [UID:0002IL][0x004ced10-0x004ceda4.HierListUpdateHierarchy](by-memory/0x004ced10-0x004ceda4.HierListUpdateHierarchy.md) | Updates or clears child-list parent references after structural changes. |
| `0x004cedb0-0x004cee52` | [UID:0002IM][0x004cedb0-0x004cee52.HierListScalarDeletingDestructor](by-memory/0x004cedb0-0x004cee52.HierListScalarDeletingDestructor.md) | Destructor wrapper that optionally deletes `this`. |

## Ownership Notes

`Layer` is the main known client: its add-before/add-after/remove-child paths call the `HierList` insertion/removal API. The container itself should stay in a utility module and be consumed by `Layer`, not absorbed into `Layer.cpp`, because Wave2 import provenance and RTTI identify a standalone `HierList` class.

Wave3 active output currently omits real HierList-local code: `0x004ce760`, `0x004ce7e0`, `0x004ce840`, `0x004ceb00`, and `0x004cec30`. These should be preserved in source migration. IDA caller checks on 2026-05-25 show `0x004ceb00` called by `Layer::RemoveChild` at `0x004f0a60`, while `0x004cec30` is called by `InsertBefore`, `InsertAfter`, `RemoveNode`, and itself recursively. IDA MCP `py_eval` on 2026-05-31 decoded the `0x004ce7e0` and `0x004ce840` wrappers even though IDA has no function objects for them.

The non-deleting destructor body at `0x004ce760` currently has no direct IDA caller. The scalar deleting wrapper at `0x004cedb0` duplicates the child-list teardown and handles the delete flag, while active `simroot_v2/class_HierList.cpp` emits a no-argument destructor body that still references a missing `deletionFlags` variable. Use the IDA wrapper shape before rewriting C++.

## Autogen Status

Attach this class to [UID:0000JV][HierList](by-file/HierList.md) as reconstructable metadata for `util/HierList.cpp`. C++ remains blank because the final overload/source-name shape for the raw wrappers and destructor variants is not at the `95+` final-code gate.

## Cross-References

- [UID:0000JV][HierList](by-file/HierList.md)
- [UID:00016X][0x004ce730-0x004cee52.HierList](by-memory/0x004ce730-0x004cee52.HierList.md)
- [UID:0001UQ][HierListNode](by-type/by-struct/HierListNode.md)
- [UID:000079][List](by-class/List.md)
- [UID:000073][Layer](by-class/Layer.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `84/88`. Summary: container purpose, observed layout, constructor/destructor and mutation/search methods, omitted Wave3-local functions, Layer consumption, and rewrite caveats are documented in detail with strong confidence. Evidence: `0x004ce730-0x004cee52.HierList`, `HierListNode`, `List`, and `Layer` cross-references plus caller notes for missing active-output methods.

### 2026-05-31 - Exact child pages and raw wrappers added

- What existed before: method coverage was summarized through one aggregate memory page and omitted the raw wrapper bodies in the former `0x004ce7d1-0x004ce85f` gap.
- Changed to: score raised to `86/90`, `RECONSTRUCTABLE:TRUE`, and the method map now links exact child range pages including `0x004ce7e0` and `0x004ce840`.
- Summary/evidence: IDA MCP function enumeration, disassembly, xrefs, and byte review confirmed all function/wrapper/padding boundaries. The page remains below 95 because final source names, overload shape, and C++ declaration form are not exhaustively audited.

### 2026-06-02 - Parent attachment

- What existed before: class metadata was reconstructable but had no autogen parent.
- Changed to: attached to [UID:0000JV][HierList](by-file/HierList.md) with C++ blank.
- Summary/evidence: the file page is `82/85`, this class is `86/90`, and both pages identify `util/HierList.cpp` as the correct owner while preserving final-code caveats.
