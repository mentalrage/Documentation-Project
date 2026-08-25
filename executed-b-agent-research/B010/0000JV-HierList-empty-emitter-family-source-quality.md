** TARGET-REPORT-UID:0000JV **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# [UID:0000JV] HierList Empty-Emitter Family Source-Quality Report

ASSIGNMENT_ID: B010-report-0000JV-HierList-empty-emitter-family-20260701
TARGET_UID: 0000JV
TARGET_DOC: by-file/HierList.md
GENERATED_OUTPUT: auto-generated/NexusTK/util/HierList.cpp
AGENT: Agent-B010
REPORT_MODE: report-only research
REPORT_STATUS: ready-for-supervisor-review

## Scope And Guardrails

This report audits [UID:0000JV] `by-file/HierList.md` and the current generated empty-emitter family for `NexusTK/util/HierList.cpp`.

Report-only restrictions were observed. I did not edit `by-*` documentation, generated files, generated reports, coverage reports, validator/tool state, queue files, archives, supervisor ledgers, or the IDA database. No leases were taken because this pass only writes the Agent-B010 research artifact.

Current empty markers in `auto-generated/NexusTK/util/HierList.cpp`:

- [UID:000065] `by-class/HierList.md`
- [UID:0002I8] `by-memory/0x004ce730-0x004ce760.HierListConstructor.md`
- [UID:0002IC] `by-memory/0x004ce860-0x004ce9ad.HierListInsertBefore.md`
- [UID:0002IF] `by-memory/0x004ceb50-0x004ceb62.HierListGetElementAt.md`
- [UID:0002IG] `by-memory/0x004ceb70-0x004ceba9.HierListInsertAt.md`
- [UID:0002IH] `by-memory/0x004cebb0-0x004cebb9.HierListAppend.md`
- [UID:0002II] `by-memory/0x004cebc0-0x004cebec.HierListRemoveAt.md`
- [UID:0002IJ] `by-memory/0x004cebf0-0x004cec22.HierListSwapElements.md`
- [UID:0002IL] `by-memory/0x004ced10-0x004ceda4.HierListUpdateHierarchy.md`
- [UID:0003BL] `by-memory/0x0061b340-0x0061b36c.HierListVtableData.md`
- [UID:0001UQ] `by-type/by-struct/HierListNode.md`

## Executive Recommendation

The HierList empty markers should be cleared in one implementation callback. Ten of the eleven blanks are source-facing declarations or source-authored methods/types. The vtable-data marker is compiler-generated binary data and should receive an explicit no-handwritten-code marker instead of `.rdata` dwords.

Recommended source route:

- File owner: [UID:0000JV] `by-file/HierList.md`
- Class owner: [UID:000065] `by-class/HierList.md`
- Node type owner: [UID:0001UQ] `by-type/by-struct/HierListNode.md`, nested/routed under [UID:000065]
- Exact method children: remain owned/emitted through [UID:000065]
- Non-emitting aggregate: [UID:00016X] `by-memory/0x004ce730-0x004cee52.HierList.md`

Recommended file-level metadata:

- [UID:0000JV] `by-file/HierList.md`: `COMPLETION:91`, `CONFIDENCE:91`
- Keep `CANONICAL_OWNER:FILE`
- Keep source path `NexusTK/util/`

Expected generated result after accepted implementation: `auto-generated/NexusTK/util/HierList.cpp` should have 17 total emitters, 17 filled, and 0 empty markers for the current HierList family, while preserving the six already accepted exact child bodies.

## Current Target State

Read current target/support documentation:

- `by-file/HierList.md`
- `by-class/HierList.md`
- `by-type/by-struct/HierListNode.md`
- `by-memory/0x004ce730-0x004ce760.HierListConstructor.md`
- `by-memory/0x004ce760-0x004ce7d1.HierListNonDeletingDestructor.md`
- `by-memory/0x004ce7e0-0x004ce839.HierListTailInsertWrapper.md`
- `by-memory/0x004ce840-0x004ce854.HierListDefaultInsertWrapper.md`
- `by-memory/0x004ce860-0x004ce9ad.HierListInsertBefore.md`
- `by-memory/0x004ce9b0-0x004ceafc.HierListInsertAfter.md`
- `by-memory/0x004ceb00-0x004ceb45.HierListRemoveNode.md`
- `by-memory/0x004ceb50-0x004ceb62.HierListGetElementAt.md`
- `by-memory/0x004ceb70-0x004ceba9.HierListInsertAt.md`
- `by-memory/0x004cebb0-0x004cebb9.HierListAppend.md`
- `by-memory/0x004cebc0-0x004cebec.HierListRemoveAt.md`
- `by-memory/0x004cebf0-0x004cec22.HierListSwapElements.md`
- `by-memory/0x004cec30-0x004ced0f.HierListFindNodeByData.md`
- `by-memory/0x004ced10-0x004ceda4.HierListUpdateHierarchy.md`
- `by-memory/0x004cedb0-0x004cee52.HierListScalarDeletingDestructor.md`
- `by-memory/0x004ce730-0x004cee52.HierList.md`
- `by-memory/0x0061b340-0x0061b36c.HierListVtableData.md`
- `by-class/List.md`
- `by-file/List.md`
- `by-memory/0x004f32b0-0x004f32da.ListGetElementAt.md`
- `by-memory/0x004f32e0-0x004f33b5.ListInsertRange.md`
- `by-memory/0x004f33c0-0x004f33d5.ListAppendRange.md`
- `by-memory/0x004f33e0-0x004f3493.ListRemoveRange.md`
- `by-memory/0x004f34b0-0x004f3532.ListSwapElements.md`

Read generated output:

- `auto-generated/NexusTK/util/HierList.cpp`

The current generated file was refreshed by validator command `000000003641` at `2026-07-01T06:45:06-04:00`. It contains six filled accepted HierList methods:

- [UID:0002I9] `HierList::~HierList()`
- [UID:0002IA] `void HierList::InsertLast(const void *parentPayload, const void *payload)`
- [UID:0002IB] `void HierList::InsertFirst(const void *parentPayload, const void *payload)`
- [UID:0002ID] `void HierList::InsertAfter(const void *parentPayload, const void *referencePayload, const void *payload)`
- [UID:0002IE] `void HierList::RemoveByPayload(const void *payload)`
- [UID:0002IK] `HierListNode *HierList::FindNodeByPayload(const void *payload, HierList **outOwnerList, int *outIndex)`

Those accepted bodies should be preserved; this report does not duplicate them in file or aggregate pages.

## Live IDA MCP Evidence

Live IDA MCP was available and used. Final health check:

- `idb_list` call id `200`: one active IDB session, `supervisor_resume_20260629`, path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `14860`, `is_analyzing:false`.
- `server_health` call id `201`: `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, strings cache size `2067`.

Schema-current/bounded calls used:

- `tools/list`: current schemas for `server_health`, `lookup_funcs`, `decompile`, `disasm`, `analyze_function`, `xrefs_to`, and `get_bytes`.
- `lookup_funcs` call ids `90-98`: exact HierList empty-source function/range check.
- `decompile` call ids `100-103`, `110-113`: exact function targets only.
- `xrefs_to` call ids `130-145`: exact target and vtable-slot addresses only, capped at 8 or 12 xrefs.
- `get_bytes` call id `141`: exact vtable data bytes at `0x0061b340`, size 48.
- `disasm` call id `150`: bounded caller snippets for the Layer constructor/use site.
- `analyze_function` call ids `170-177`: exact function summaries without broad disassembly.

Function/range findings:

| Address | MCP result |
| --- | --- |
| `0x004ce730` | `sub_4CE730`, size `0x30` |
| `0x004ce860` | `sub_4CE860`, size `0x14d` |
| `0x004ceb50` | `sub_4CEB50`, size `0x12` |
| `0x004ceb70` | `sub_4CEB70`, size `0x39` |
| `0x004cebb0` | `sub_4CEBB0`, size `0x09` |
| `0x004cebc0` | `sub_4CEBC0`, size `0x2c` |
| `0x004cebf0` | `sub_4CEBF0`, size `0x32` |
| `0x004ced10` | `sub_4CED10`, size `0x94` |
| `0x0061b340` | no function object; data bytes only |

Key decompiler findings:

- Constructor `0x004ce730`: calls `List` constructor with `payloadSize + 11` and page size `32`, stores `ownerNode` at `this[5]`, installs `HierList::vftable`, then writes this list pointer to `ownerNode->childList`.
- Insert-before core `0x004ce860`: allocates a temporary row with `AllocateBufferMemory(m_elementSize)`, clears row child-list pointer, copies `m_elementSize - 11` payload bytes, resolves optional parent/reference payloads through `FindNodeByPayload`, lazy-constructs a child `HierList` when needed, inserts at `referenceIndex + 1`, and frees the temporary row.
- GetElementAt `0x004ceb50`: returns `List::GetElementAt(index) + 8`, exposing caller payload rather than the hierarchy row header.
- InsertAt `0x004ceb70`: calls base `List::InsertAt`, then repairs shifted old rows with `UpdateHierarchy(index + count, m_count - 1, false)` only when insertion occurred before the old tail.
- Append `0x004cebb0`: tail delegates to base `List::Append`.
- RemoveAt `0x004cebc0`: calls base `List::RemoveAt`, then repairs `index..m_count-1` when rows remain after the removal point.
- SwapElements `0x004cebf0`: calls base `List::SwapElements`, then repairs each swapped row independently.
- UpdateHierarchy `0x004ced10`: for each row in an inclusive range, reads `node->childList`, writes `childList->ownerNode` to either the current node or null, and writes each child node's `parent` to either the current node or null depending on the clear flag.

Vtable data evidence:

`get_bytes(0x0061b340, 48)` returned:

```text
0x00  0x00648324  RTTI/COL-adjacent locator
+0x04  0x004cedb0  HierList scalar deleting destructor wrapper
+0x08  0x004f4b10  inherited runtime/type helper
+0x0c  0x0041b6c0  inherited no-op/runtime helper
+0x10  0x004f32a0  inherited List::GetData
+0x14  0x004ceb50  HierList::GetElementAt
+0x18  0x004ceb70  HierList::InsertAt
+0x1c  0x004cebb0  HierList::Append
+0x20  0x004cebc0  HierList::RemoveAt
+0x24  0x004f34a0  inherited List::RemoveAll
+0x28  0x004cebf0  HierList::SwapElements
```

This proves [UID:0003BL] is vtable/RTTI data generated from the class declaration and virtual method set; it is not a handwritten source initializer.

## Positive Evidence

- Current `List` support docs have accepted formal signatures for the base virtual methods. `List::InsertAt`, `Append`, `RemoveAt`, and `SwapElements` are source-facing `void` methods; HierList overrides should match those signatures and treat IDA return values as unused register artifacts.
- Existing accepted HierList children already establish the public source names `InsertLast`, `InsertFirst`, `InsertAfter`, `RemoveByPayload`, and private `FindNodeByPayload`.
- The `HierListNode` layout is stable: `parent` at `+0x00`, `childList` at `+0x04`, flexible payload at `+0x08`, and three trailing stride bytes accounted for by `payloadSize + 11`.
- Constructor evidence connects the root `HierList` to the Layer constructor and the owner-node backpointer model.
- Insert-before evidence is now ready because current MCP reconfirms the same parent/reference/payload contract accepted for `InsertAfter`, with the two expected differences: no-reference defaults to `-1` and insertion at head, and this path uses non-zeroing `AllocateBufferMemory`.
- UpdateHierarchy is source-authored private helper code, not vtable or raw data. All direct callers are HierList mutation overrides, and the helper's field writes match the documented `HierListNode` and `HierList::ownerNode` layout.

## Negative Evidence And Rejections

- Reject file-level body duplication: [UID:0000JV] should summarize and route the class family; exact method C++ belongs on child pages through [UID:000065].
- Reject aggregate emission from [UID:00016X] `HierList`: it is a non-emitting physical range/index page, and exact method pages already own the source bodies.
- Reject List ownership for HierList overrides: List supplies base storage primitives, but the `+8` payload projection, `ownerNode`, child-list lifecycle, and hierarchy repair are HierList-specific.
- Reject Layer ownership: Layer constructs and consumes root HierList instances, but it does not own the generic tree-list implementation.
- Reject hand-authored vtable dwords for [UID:0003BL]: the bytes are compiler-generated from class declarations and virtual methods.
- Reject raw IDA names (`sub_4CE860`, `FindNodeByData`, `ListInsertRange`) as source-facing names where current docs and accepted bodies support `InsertBefore`, `FindNodeByPayload`, `InsertAt`, `Append`, `RemoveAt`, and `SwapElements`.
- Reject a future-only deferral for the current blanks. The current base List docs, HierList child docs, node layout, live MCP decompilation, and vtable evidence are sufficient for first-draft C++ or a target-specific generated-data no-code marker.

## Heuristic And Source-Quality Reanalysis

The main prior blocker was class-wide sequencing: several children were blank because base List method names, `HierListNode` field names, source-facing overload names, and return policy were not yet resolved. That blocker no longer applies.

Resolved current-pass items:

- Base virtual method signatures are now accepted on `List`: `void InsertAt`, `void Append`, `void RemoveAt`, `void SwapElements`.
- Return-register artifacts in HierList mutation wrappers should not be surfaced as source returns. This matches accepted List behavior.
- `HierListNode` should be emitted as a flexible payload struct. The three extra bytes in the `payloadSize + 11` stride are padding/alignment/reserved stride bytes, not semantic fields.
- `ownerNode` at `HierList +0x14` is a real class field. It stores the parent row for child lists and is written by constructor and `UpdateHierarchy`.
- `InsertBefore` has enough evidence for the exact public source name because accepted `InsertFirst`, `InsertLast`, and `InsertAfter` use that name and call shape.
- `UpdateHierarchy` remains the best source-facing helper name for now because it is already the filename/search label and accurately describes both owner-pointer and parent-pointer repair. `RepairHierarchyLinks` is a readable alternate, but changing the name now would add churn without stronger evidence.

## Ranked Ownership And Source Placement

1. [UID:0000JV] `by-file/HierList.md` is the file owner for `NexusTK/util/HierList.cpp`.
2. [UID:000065] `by-class/HierList.md` should own the declaration shell and route exact method children.
3. Exact method pages [UID:0002I8], [UID:0002IC], [UID:0002IF], [UID:0002IG], [UID:0002IH], [UID:0002II], [UID:0002IJ], and [UID:0002IL] should carry formal source bodies.
4. [UID:0001UQ] `HierListNode` should carry the flexible payload struct declaration under [UID:000065].
5. [UID:0003BL] should carry a formal no-handwritten-vtable-data marker.
6. [UID:00016X] should remain a support/index page and should be updated only to remove stale "still blank/deferred" wording for the children resolved by this report.

## Split, Range, And Container Analysis

The current split is correct. The source-bearing methods are already exact child ranges with padding boundaries around each method. [UID:00016X] is only the physical class-island aggregate and should remain `RECONSTRUCTABLE:FALSE` with blank `EMITTER_UIDS`.

Container model:

```text
List base:
  +0x04 m_elementSize
  +0x08 m_pageSize
  +0x0c m_count
  +0x10 m_data

HierList extension:
  +0x14 HierListNode *ownerNode

HierListNode row:
  +0x00 HierListNode *parent
  +0x04 HierList *childList
  +0x08 unsigned char payload[1]  // flexible payload marker
```

The binary stride is `payloadSize + 11`, not `sizeof(HierListNode)` in ordinary C++ terms. This is compatible with `payload[1]`: `8 + payloadSize + 3` bytes are allocated per row, with the trailing three bytes acting as stride padding/reserved bytes. Do not model those three bytes as named source fields unless a future caller proves semantics.

## Score And Metadata Recommendations

| UID | Current | Recommended | Metadata disposition |
| --- | --- | --- | --- |
| 0000JV `by-file/HierList.md` | `85/87` | `91/91` | keep `CANONICAL_OWNER:FILE`; source path `NexusTK/util/` |
| 000065 `by-class/HierList.md` | `86/90` | `91/92` | keep `CANONICAL_OWNER:0000JV`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JV` |
| 0001UQ `HierListNode.md` | `86/91` | `90/92` | keep `CANONICAL_OWNER:000065`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000065` |
| 0002I8 constructor | `86/91` | `90/92` | keep class ownership/emission |
| 0002IC InsertBefore | `86/90` | `90/92` | keep class ownership/emission |
| 0002IF GetElementAt | `88/92` | `90/92` | keep class ownership/emission |
| 0002IG InsertAt | `86/91` | `90/92` | keep class ownership/emission |
| 0002IH Append | `86/92` | `89/92` | keep class ownership/emission |
| 0002II RemoveAt | `86/91` | `90/92` | keep class ownership/emission |
| 0002IJ SwapElements | `86/91` | `90/92` | keep class ownership/emission |
| 0002IL UpdateHierarchy | `88/92` | `90/92` | keep class ownership/emission |
| 0003BL VtableData | `86/90` | `88/92` | keep class ownership/emission but emit no-handwritten-code marker |
| 00016X aggregate support | `88/91` | `90/92` | keep `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS` |

## Formal Reconstruction Text

### [UID:000065] `by-class/HierList.md`

Insert this declaration shell in `RECONSTRUCTION_CPP CODE`. Do not duplicate already accepted exact method bodies in this class prose; child pages still own bodies.

```cpp
struct HierListNode;

class HierList : public List {
public:
    HierList(int payloadSize, HierListNode *ownerNode);
    virtual ~HierList();

    void InsertLast(const void *parentPayload, const void *payload);
    void InsertFirst(const void *parentPayload, const void *payload);
    void InsertBefore(const void *parentPayload, const void *referencePayload, const void *payload);
    void InsertAfter(const void *parentPayload, const void *referencePayload, const void *payload);
    void RemoveByPayload(const void *payload);

    virtual void *GetElementAt(int index);
    virtual void InsertAt(int index, int count, void *source);
    virtual void Append(int count, void *source);
    virtual void RemoveAt(int index, int count);
    virtual void SwapElements(int firstIndex, int secondIndex);

protected:
    HierListNode *ownerNode;

private:
    HierListNode *FindNodeByPayload(const void *payload, HierList **outOwnerList, int *outIndex);
    void UpdateHierarchy(int firstIndex, int lastIndex, bool clearParent);
};
```

### [UID:0001UQ] `by-type/by-struct/HierListNode.md`

```cpp
struct HierListNode {
    HierListNode *parent;
    HierList *childList;
    unsigned char payload[1];
};
```

Implementation note: document `payload[1]` as a flexible payload marker. The binary row allocation uses `payloadSize + 11`; the three extra bytes are stride padding/reserved bytes and should not be given source semantics.

### [UID:0002I8] `HierListConstructor`

```cpp
HierList::HierList(int payloadSize, HierListNode *owner)
    : List(payloadSize + 11, 32),
      ownerNode(owner)
{
    owner->childList = this;
}
```

### [UID:0002IC] `HierListInsertBefore`

```cpp
void HierList::InsertBefore(const void *parentPayload, const void *referencePayload, const void *payload)
{
    MemoryMan *memoryMan = GetMemoryMan();
    HierListNode *node =
        static_cast<HierListNode *>(memoryMan->AllocateBufferMemory(m_elementSize));
    node->childList = NULL;
    memoryMan->MemmoveWrapper(node->payload, payload, m_elementSize - 11);

    int referenceIndex;
    if (parentPayload == NULL) {
        HierList *referenceOwnerList;
        if (referencePayload != NULL) {
            FindNodeByPayload(referencePayload, &referenceOwnerList, &referenceIndex);
        } else {
            referenceOwnerList = this;
            referenceIndex = -1;
        }

        node->parent = ownerNode;
        InsertAt(referenceIndex + 1, 1, node);
    } else {
        HierListNode *parentNode = FindNodeByPayload(parentPayload, NULL, NULL);
        HierList *childList = parentNode->childList;
        if (childList == NULL) {
            childList = new HierList(m_elementSize - 11, parentNode);
        }

        if (referencePayload != NULL) {
            FindNodeByPayload(referencePayload, NULL, &referenceIndex);
        } else {
            referenceIndex = -1;
        }

        node->parent = parentNode;
        childList->InsertAt(referenceIndex + 1, 1, node);
    }

    memoryMan->FreeBufferMemory(node);
}
```

The `referenceOwnerList` local is intentionally retained as a source-facing companion to `InsertAfter` and because `FindNodeByPayload` can fill it, but current decompile shows the root/no-parent insertion dispatches through `this->InsertAt(...)`, not `referenceOwnerList->InsertAt(...)`.

### [UID:0002IF] `HierListGetElementAt`

```cpp
void *HierList::GetElementAt(int index)
{
    return static_cast<unsigned char *>(List::GetElementAt(index)) + 8;
}
```

No null guard should be inserted; the binary expression is base pointer plus `8`.

### [UID:0002IG] `HierListInsertAt`

```cpp
void HierList::InsertAt(int index, int count, void *source)
{
    int oldCount = m_count;
    List::InsertAt(index, count, source);
    if (oldCount > index) {
        UpdateHierarchy(index + count, m_count - 1, false);
    }
}
```

### [UID:0002IH] `HierListAppend`

```cpp
void HierList::Append(int count, void *source)
{
    List::Append(count, source);
}
```

### [UID:0002II] `HierListRemoveAt`

```cpp
void HierList::RemoveAt(int index, int count)
{
    List::RemoveAt(index, count);
    if (index <= m_count - 1) {
        UpdateHierarchy(index, m_count - 1, false);
    }
}
```

### [UID:0002IJ] `HierListSwapElements`

```cpp
void HierList::SwapElements(int firstIndex, int secondIndex)
{
    List::SwapElements(firstIndex, secondIndex);
    UpdateHierarchy(firstIndex, firstIndex, false);
    UpdateHierarchy(secondIndex, secondIndex, false);
}
```

### [UID:0002IL] `HierListUpdateHierarchy`

```cpp
void HierList::UpdateHierarchy(int firstIndex, int lastIndex, bool clearParent)
{
    for (int index = firstIndex; index <= lastIndex; ++index) {
        HierListNode *node = static_cast<HierListNode *>(List::GetElementAt(index));
        HierList *childList = node->childList;
        if (childList == NULL) {
            continue;
        }

        HierListNode *parentNode = clearParent ? NULL : node;
        childList->ownerNode = parentNode;

        for (int childIndex = 0; childIndex < childList->m_count; ++childIndex) {
            HierListNode *childNode =
                static_cast<HierListNode *>(childList->List::GetElementAt(childIndex));
            childNode->parent = parentNode;
        }
    }
}
```

### [UID:0003BL] `HierListVtableData`

Formal no-code marker:

```cpp
/* NC-0003BL: HierList vtable/RTTI data is compiler-generated from the
   HierList class declaration, destructor, and virtual method set. Do not
   hand-port the .rdata dwords as handwritten C++; source reconstruction
   belongs to the class declaration and exact method pages. */
```

## Recommended Target And Support Doc Changes

- `by-file/HierList.md`: update score to `91/91`; summarize that the remaining 11 empty markers have implementation-ready dispositions; record generated expectation `17/17/0`; keep file-level ownership and avoid duplicating child bodies.
- `by-class/HierList.md`: update score to `91/92`; insert the declaration shell above; preserve current field model with `ownerNode` at complete object `+0x14`; list the accepted and newly proposed source method names.
- `by-type/by-struct/HierListNode.md`: update score to `90/92`; insert the flexible payload struct; document `payload[1]` and `payloadSize + 11` stride/padding semantics.
- `by-memory/0x004ce730-0x004ce760.HierListConstructor.md`: insert constructor formal C++; update evidence with current MCP decompile/range/caller proof.
- `by-memory/0x004ce860-0x004ce9ad.HierListInsertBefore.md`: insert formal C++; update decompile evidence including root dispatch through `this->InsertAt`, child-list lazy allocation, null-reference default `-1`, non-zeroing allocation, payload copy, and temporary-row free.
- `by-memory/0x004ceb50-0x004ceb62.HierListGetElementAt.md`: insert formal C++; document base node pointer plus payload offset `+8`.
- `by-memory/0x004ceb70-0x004ceba9.HierListInsertAt.md`: insert formal `void` override; record that return register artifacts are rejected because current List virtual API is `void`.
- `by-memory/0x004cebb0-0x004cebb9.HierListAppend.md`: insert formal `void` override delegating to base `List::Append`.
- `by-memory/0x004cebc0-0x004cebec.HierListRemoveAt.md`: insert formal `void` override and shifted-range repair.
- `by-memory/0x004cebf0-0x004cec22.HierListSwapElements.md`: insert formal `void` override and two single-row repairs.
- `by-memory/0x004ced10-0x004ceda4.HierListUpdateHierarchy.md`: insert formal private helper body; keep helper name `UpdateHierarchy`; document clear-parent flag.
- `by-memory/0x0061b340-0x0061b36c.HierListVtableData.md`: insert no-handwritten-code marker; preserve vtable slot evidence.
- `by-memory/0x004ce730-0x004cee52.HierList.md`: support-only update; keep non-emitting aggregate, but historicalize stale child-C++ deferral for this newly resolved set.

## Claim And Incorporation Ledger

| Claim | Source evidence | Target/support edit | Action | Verification state |
| --- | --- | --- | --- | --- |
| [UID:0000JV] remains the file owner for `NexusTK/util/HierList.cpp`. | Current `by-file/HierList.md`; generated `HierList.cpp`; goal current empty-marker set. | Updated `by-file/HierList.md` to `91/91`; added 11-marker disposition, `17/17/0` expectation, file owner route, and file-level body duplication rejection. Validator `000000003686`, exit `0`, `ok:1`. | incorporate | applied |
| [UID:000065] should emit a declaration shell instead of an empty marker. | Current class layout; accepted child bodies; current List signatures; MCP vtable bytes. | Populated `by-class/HierList.md` formal class declaration and source-route prose. Validator `000000003687`, exit `0`, `ok:1`. | incorporate | applied |
| [UID:0001UQ] is source-level `HierListNode` with flexible payload. | Current node doc layout; constructor/insertion/update decompile field refs. | Populated `by-type/by-struct/HierListNode.md` formal struct and stride/padding note. Validator `000000003688`, exit `0`, `ok:1`. | incorporate | applied |
| [UID:0002I8] is source-level `HierList::HierList`. | MCP decompile id `100`; analyze id `170`; Layer caller xref `0x004f0562`. | Inserted constructor formal C++ and current MCP proof in `by-memory/0x004ce730-0x004ce760.HierListConstructor.md`. Validator `000000003689`, exit `0`, `ok:1`. | incorporate | applied |
| [UID:0002IC] is source-level `HierList::InsertBefore`. | MCP decompile id `101`; analyze id `171`; xrefs ids `130-145`; accepted `InsertFirst`, `InsertLast`, `InsertAfter` docs. | Inserted `InsertBefore` formal C++ plus allocation/root-dispatch/lazy-child/default-index/free-tail evidence in `by-memory/0x004ce860-0x004ce9ad.HierListInsertBefore.md`. Validator `000000003690`, exit `0`, `ok:1`. | incorporate | applied |
| [UID:0002IF] is source-level `HierList::GetElementAt`. | MCP decompile id `102`; vtable byte slot `0x0061b354`. | Inserted payload-offset accessor C++ and no-null-guard rationale in `by-memory/0x004ceb50-0x004ceb62.HierListGetElementAt.md`. Validator `000000003691`, exit `0`, `ok:1`. | incorporate | applied |
| [UID:0002IG] is source-level `HierList::InsertAt` override. | MCP decompile id `103`; analyze id `173`; List accepted `void InsertAt`. | Inserted void override C++ and return-register rejection in `by-memory/0x004ceb70-0x004ceba9.HierListInsertAt.md`. Validator `000000003692`, exit `0`, `ok:1`. | incorporate | applied |
| [UID:0002IH] is source-level `HierList::Append` override. | MCP decompile id `110`; List accepted `void Append`; vtable bytes. | Inserted void delegation C++ in `by-memory/0x004cebb0-0x004cebb9.HierListAppend.md`. Validator `000000003693`, exit `0`, `ok:1`. | incorporate | applied |
| [UID:0002II] is source-level `HierList::RemoveAt` override. | MCP decompile id `111`; analyze id `175`; List accepted `void RemoveAt`. | Inserted remove/repair C++ in `by-memory/0x004cebc0-0x004cebec.HierListRemoveAt.md`. Validator `000000003694`, exit `0`, `ok:1`. | incorporate | applied |
| [UID:0002IJ] is source-level `HierList::SwapElements` override. | MCP decompile id `112`; analyze id `176`; List accepted `void SwapElements`. | Inserted swap/repair C++ in `by-memory/0x004cebf0-0x004cec22.HierListSwapElements.md`. Validator `000000003696`, exit `0`, `ok:1`. | incorporate | applied |
| [UID:0002IL] is source-level private `UpdateHierarchy`. | MCP decompile id `113`; analyze id `177`; xrefs to calls from InsertAt/RemoveAt/SwapElements. | Inserted helper C++ and clear-parent behavior in `by-memory/0x004ced10-0x004ceda4.HierListUpdateHierarchy.md`. Validator `000000003698`, exit `0`, `ok:1`. | incorporate | applied |
| [UID:0003BL] is compiler-generated vtable/RTTI data, not handwritten C++. | MCP `get_bytes` id `141`; vtable xrefs and constructor/vtable stores. | Inserted formal no-handwritten-code marker `NC-0003BL` in `by-memory/0x0061b340-0x0061b36c.HierListVtableData.md`. Validator `000000003700`, exit `0`, `ok:1`. | incorporate | applied |
| [UID:00016X] should remain non-emitting aggregate/index. | Current aggregate metadata and exact child pages. | Updated `by-memory/0x004ce730-0x004cee52.HierList.md` to `90/92`, kept `RECONSTRUCTABLE:FALSE`/blank `EMITTER_UIDS`, and historicalized stale deferral. Validator `000000003702`, exit `0`, `ok:1`. | incorporate | applied |
| Existing filled children must be preserved. | Generated `HierList.cpp` command `000000003641`; current child docs [UID:0002I9], [UID:0002IA], [UID:0002IB], [UID:0002ID], [UID:0002IE], [UID:0002IK]. | Generated `auto-generated/NexusTK/util/HierList.cpp` refreshed at command `000000003713`; each filled child UID appears once and no duplicate bodies were added. | already-present | already-present |
| `List` support signatures are now adequate for HierList return policy. | Current `by-class/List.md` and current List child docs. | No List support docs changed; return policy incorporated into HierList class and method pages. | already-present | already-present |
| `referenceOwnerList` in `InsertBefore` should not drive root insertion dispatch. | Current MCP decompile id `101` shows no-parent path calls `this` virtual slot; accepted InsertAfter follows same root dispatch shape. | Documented caveat in `by-memory/0x004ce860-0x004ce9ad.HierListInsertBefore.md`; formal C++ uses `InsertAt(...)` on `this` for the no-parent path. Validator `000000003690`, exit `0`, `ok:1`. | incorporate | applied |

## Implementation Tracking Checklist

Callback implementation state: every accepted item is checked, applied, already present, or explicitly accounted for.

- [x] `by-file/HierList.md`: set `COMPLETION:91`, `CONFIDENCE:91`; added current empty-family disposition and generated `17/17/0` expectation. State: applied; validator `000000003686`, `2026-07-01T07:01:04-04:00`, exit `0`, `ok:1`.
- [x] `by-class/HierList.md`: set `COMPLETION:91`, `CONFIDENCE:92`; inserted the declaration shell; preserved `CANONICAL_OWNER:0000JV`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JV`. State: applied; validator `000000003687`, `2026-07-01T07:01:16-04:00`, exit `0`, `ok:1`.
- [x] `by-type/by-struct/HierListNode.md`: set `COMPLETION:90`, `CONFIDENCE:92`; inserted flexible payload struct; documented row stride and padding. State: applied; validator `000000003688`, `2026-07-01T07:01:27-04:00`, exit `0`, `ok:1`.
- [x] `by-memory/0x004ce730-0x004ce760.HierListConstructor.md`: set `90/92`; inserted constructor body and current MCP proof. State: applied; validator `000000003689`, `2026-07-01T07:01:38-04:00`, exit `0`, `ok:1`.
- [x] `by-memory/0x004ce860-0x004ce9ad.HierListInsertBefore.md`: set `90/92`; inserted `InsertBefore` body; recorded non-zeroing allocation, root dispatch, lazy child construction, default `-1`, and free-helper tail. State: applied; validator `000000003690`, `2026-07-01T07:01:49-04:00`, exit `0`, `ok:1`.
- [x] `by-memory/0x004ceb50-0x004ceb62.HierListGetElementAt.md`: set `90/92`; inserted payload accessor body. State: applied; validator `000000003691`, `2026-07-01T07:02:00-04:00`, exit `0`, `ok:1`.
- [x] `by-memory/0x004ceb70-0x004ceba9.HierListInsertAt.md`: set `90/92`; inserted void override body; rejected return-register artifact. State: applied; validator `000000003692`, `2026-07-01T07:02:10-04:00`, exit `0`, `ok:1`.
- [x] `by-memory/0x004cebb0-0x004cebb9.HierListAppend.md`: set `89/92`; inserted void base-delegation body. State: applied; validator `000000003693`, `2026-07-01T07:02:21-04:00`, exit `0`, `ok:1`.
- [x] `by-memory/0x004cebc0-0x004cebec.HierListRemoveAt.md`: set `90/92`; inserted void remove/repair body. State: applied; validator `000000003694`, `2026-07-01T07:02:32-04:00`, exit `0`, `ok:1`.
- [x] `by-memory/0x004cebf0-0x004cec22.HierListSwapElements.md`: set `90/92`; inserted void swap/repair body. State: applied; validator `000000003696`, `2026-07-01T07:02:42-04:00`, exit `0`, `ok:1`.
- [x] `by-memory/0x004ced10-0x004ceda4.HierListUpdateHierarchy.md`: set `90/92`; inserted private helper body; recorded clear-parent behavior. State: applied; validator `000000003698`, `2026-07-01T07:03:02-04:00`, exit `0`, `ok:1`.
- [x] `by-memory/0x0061b340-0x0061b36c.HierListVtableData.md`: set `88/92`; inserted formal no-handwritten-vtable-data marker. State: applied; validator `000000003700`, `2026-07-01T07:03:23-04:00`, exit `0`, `ok:1`.
- [x] `by-memory/0x004ce730-0x004cee52.HierList.md`: set `90/92`; kept non-emitting aggregate metadata; historicalized stale deferral wording. State: applied; validator `000000003702`, `2026-07-01T07:03:44-04:00`, exit `0`, `ok:1`.
- [x] Run scoped validators after implementation edits:

> Executable block R001 was removed from this report and preserved verbatim in [0000JV-HierList-empty-emitter-family-source-quality-removed.md](0000JV-HierList-empty-emitter-family-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Validator proof: all 13 listed commands were run from `E:\NTK\GhidraBridge\source-3\project-documentation` with `--wait-generated`; all exited `0` with `ok:1`.

- [x] Inspect refreshed `auto-generated/NexusTK/util/HierList.cpp` for current validator command id/timestamp and confirm none of the 11 old empty markers remain. State: applied; final observed header is `validator-command-id: 000000003713`, `validator-refreshed-at: 2026-07-01T07:06:26-04:00`, newer than final scoped command `000000003702`; `rg "Empty Emitter Marker"` found no matches; all 17 expected UID blocks are present.
- [x] If implementation edits add any optional support page not listed above, run the same scoped validator with `--wait-generated` for that page. State: not applicable; no optional support pages were edited.

## Blockers

No MCP availability blocker remains. Live IDA MCP evidence was collected successfully and reconfirmed healthy at the end of the pass. No implementation was performed because this assignment is report-only.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000004165","destination_path":"executed-b-agent-research/B010/0000JV-HierList-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B010/research/0000JV-HierList-empty-emitter-family-source-quality.md","timestamp":"2026-07-01T07:07:49","uid":"0000JV"} -->
<!-- {"agent":"B010","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000JV-HierList-empty-emitter-family-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B010/0000JV-HierList-empty-emitter-family-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000JV"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
