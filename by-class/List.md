*** UID:000079 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KS | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KS | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "List.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_UTIL_LIST_H
#define NEXUSTK_UTIL_LIST_H

#include "LObject.h"

typedef int (__cdecl *ListCompareFunction)(const void *left,
                                           const void *right);

class List : public LObject
{
public:
    List(int elementSize, int pageSize);
    virtual ~List();
    virtual void *GetData();
    virtual void *GetElementAt(int index);
    virtual void InsertAt(int index, int count, void *source);
    virtual void Append(int count, void *source);
    virtual void RemoveAt(int index, int count);
    virtual void RemoveAll();
    virtual void SwapElements(int firstIndex, int secondIndex);
    void AssignFrom(List *source);
    void SetCount(int count);
    int GetCount() const { return m_count; }
    void Sort(ListCompareFunction compare);

protected:
    int m_elementSize;
    int m_pageSize;
    int m_count;
    void *m_data;

private:
    void ReserveElementCapacity(int elementCount);
    void ReservePageCapacity(int pageCount);
    int PageCountForElementCount(int elementCount);
};

typedef char ListSizeMustBe20[sizeof(List) == 0x14 ? 1 : -1];

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# List

## Status

- Confidence: strong for layout and core methods.
- Likely source file: [UID:0000KS][List](by-file/List.md)
- Constructor range: [UID:000191][0x004f3060-0x004f30d5.ListConstructor](by-memory/0x004f3060-0x004f30d5.ListConstructor.md)
- Core method index: [UID:00022S][0x004f3140-0x004f35fd.ListCoreMethods](by-memory/0x004f3140-0x004f35fd.ListCoreMethods.md)
- Scalar deleting destructor: [UID:00037L][0x004f3810-0x004f38a7.ListScalarDeletingDestructor](by-memory/0x004f3810-0x004f38a7.ListScalarDeletingDestructor.md)
- Historical recovered/generated lead: `source-3/simroot_v2/class_List.cpp` (not current authority; current authority is active IDA/MCP evidence and the by-* pages).

## Class Purpose

`List` is the shared fixed-width dynamic array container used across UI, render, archive-adjacent, map, and object systems. It inherits from `LObject`, stores an element size, grows in fixed page-size chunks, and exposes virtual element access and mutation helpers.

This is the real object constructed for the `ImageLib` resource-layout registry at object offset `+0x0c`; the earlier `ResourceLayoutStore` name is a generated semantic overlay over this generic container.

## UID000090 Complete Header Ownership - 2026-07-31

- The accepted declaration now lives in formal `List.h`, under complete `LObject.h`, rather than being emitted as a CPP-local class. This makes `List` legally consumable by `InputMan.cpp` and every other translation unit that invokes its members.
- `List.cpp` contains only the self-header include and exact child insertion route at class level. Constructor, destructor, public methods, and private capacity/page helpers remain emitted by their exact by-memory children; no body is duplicated here.
- The declaration preserves the accepted `0x14` ABI, seven virtual methods after the destructor, inline `GetCount`, protected four-dword state, private helpers, and `ListCompareFunction` signature. The size guard makes accidental source-layout drift visible.
- One C++03 include guard, `NEXUSTK_UTIL_LIST_H`, now encloses the complete formal H channel. This permits direct and transitive use from guarded `BlackHole.h` without changing or duplicating any declaration. The H-level child marker is intentionally absent because List has no H-emitting children; retaining it makes the validator emit the invalid literal `[[No Children Attached]]`.
- The historical CPP-local/PCH-only declaration shape is superseded. This ownership correction does not alter method ranges, runtime behavior, List/SortedList separation, or child emitter routes.

2026-06-19 B008 source-quality reanalysis resolves the constructor source shape as `List::List(int elementSize, int pageSize)`. The constructor calls [UID:0001BC][0x00516030-0x00516036.GetMemoryMan](by-memory/0x00516030-0x00516036.GetMemoryMan.md) and [UID:0001BE][0x005160d0-0x00516162.ZeroAllocateBufferMemory](by-memory/0x005160d0-0x00516162.ZeroAllocateBufferMemory.md) to zero-allocate `elementSize * pageSize` bytes, initializes the logical count to zero, and leaves payload ownership to the caller. `pageSize` is an element-count growth/initial-allocation quantum, not a byte count.

2026-06-26 B011 source-quality implementation resolves [UID:000192][0x004f30e0-0x004f3139.ListNonDeletingDestructor](by-memory/0x004f30e0-0x004f3139.ListNonDeletingDestructor.md) as the class-owned ordinary `List::~List()` body. The source destructor checks `m_data`, assigns `m_data = GetMemoryMan()->FreeBufferMemory(m_data)` when non-null, and relies on compiler-generated teardown for the `LObject` base. The containing translation unit remains [UID:0000KS][List](by-file/List.md), but the method owner/emitter is this `List` class, matching the constructor route.

2026-06-29 B010 source-quality implementation resolves [UID:0003JV][0x004f32a0-0x004f32a4.ListGetData](by-memory/0x004f32a0-0x004f32a4.ListGetData.md) as a formal source-ready virtual accessor. Current MCP session `967f0703` reconfirmed the two-instruction body `mov eax, [ecx+0x10]; retn`, data xrefs at `0x00613124`, `0x0061b350`, `0x0061ce38`, and `0x0061ce64`, and the `List` vtable slot at `0x0061ce38` (`+0x0c`). The accepted body is `void *List::GetData() { return m_data; }`; `m_data` remains the inferred/descriptive field name for the `+0x10` raw backing buffer.

2026-06-29 B008 source-quality implementation resolves [UID:0003JT][0x004f3140-0x004f31cc.ListAssignFrom](by-memory/0x004f3140-0x004f31cc.ListAssignFrom.md) as a formal source-ready `List` method. Current MCP session `967f0703` reconfirmed the exact `0x8c` body, two Config wrapper refs, MemoryMan helper callees, and `0x004f31cc-0x004f31d0` padding. The accepted body is `void List::AssignFrom(List *source)`, copying source dimensions/count, freeing old `m_data`, allocating page-rounded replacement storage, and copying `m_elementSize * m_count` bytes from `source->m_data`.

2026-06-29 B012 source-quality implementation resolves [UID:0003JW][0x004f32b0-0x004f32da.ListGetElementAt](by-memory/0x004f32b0-0x004f32da.ListGetElementAt.md) as a formal source-ready virtual accessor. Current MCP session `967f0703` reconfirmed the exact `0x2a` body, no callees, vtable slot `+0x10` at `0x0061ce3c`, six `0xcc` padding bytes before `List::InsertAt`, and broad consumer xrefs. The accepted body is `void *List::GetElementAt(int index)`, returning `static_cast<unsigned char *>(m_data) + index * m_elementSize` for valid indices and preserving the binary special case where index zero is valid whenever `m_data` exists.

2026-06-29 B009 source-quality implementation resolves [UID:0003JU][0x004f31d0-0x004f329f.ListSetCount](by-memory/0x004f31d0-0x004f329f.ListSetCount.md) as a formal source-ready `List` count mutator. Current MCP session `967f0703` reconfirmed the exact `0xcf` body, `GetMemoryMan` / `AllocateBufferMemory` / `ReallocateBufferMemory` helper callees, twelve basic blocks, four direct raw/unmodeled code xrefs with no return-value use, `0xcc` padding before `List::GetData`, and no data/immediate/VA/RVA pointer refs. The accepted body is `void List::SetCount(int count)`: compute old/new page counts from `m_count`, `count`, and `m_pageSize`; allocate or reallocate `m_data` when the page count changes; and store `m_count = count`. `SetCount` is accepted as the source-facing name, while `SetSize` remains only a rejected/search alternate.

2026-06-29 B005 source-quality implementation resolves [UID:0003K3][0x004f3560-0x004f3597.ListReserveExactElementCountRaw](by-memory/0x004f3560-0x004f3597.ListReserveExactElementCountRaw.md) as a formal source-ready private `List` capacity helper. Current MCP session `b2ae72ec` reconfirmed the raw not-a-function state, exact helper body, five-byte pre-padding, 55-byte body, nine-byte post-padding, unique signature, target-internal `GetMemoryMan` / `AllocateBufferMemory` / `ReallocateBufferMemory` calls, and zero inbound xrefs. A local read-only PE scan found no direct `E8`/`E9` calls/jumps, absolute VA pointers, or RVA pointers to the helper. The accepted body is `void List::ReserveElementCapacity(int elementCount)`: compute `m_elementSize * elementCount`, allocate `m_data` when null, or reallocate existing `m_data`; it does not read or update `m_count` and does not use `m_pageSize`. `ReserveElementCapacity` is inferred source-facing spelling, while `ListReserveExactElementCountRaw` remains a descriptive/search alias and the no-xref/no-symbol state remains a confidence cap.

2026-07-01 B009 empty-emitter implementation resolves the remaining List-family empty markers. [UID:0003JX][0x004f32e0-0x004f33b5.ListInsertRange](by-memory/0x004f32e0-0x004f33b5.ListInsertRange.md), [UID:0003JY][0x004f33c0-0x004f33d5.ListAppendRange](by-memory/0x004f33c0-0x004f33d5.ListAppendRange.md), [UID:0003JZ][0x004f33e0-0x004f3493.ListRemoveRange](by-memory/0x004f33e0-0x004f3493.ListRemoveRange.md), [UID:0003K0][0x004f34a0-0x004f34ab.ListClear](by-memory/0x004f34a0-0x004f34ab.ListClear.md), [UID:0003K1][0x004f34b0-0x004f3532.ListSwapElements](by-memory/0x004f34b0-0x004f3532.ListSwapElements.md), and [UID:0003K2][0x004f3540-0x004f355b.ListSort](by-memory/0x004f3540-0x004f355b.ListSort.md) now have formal first-draft source bodies. The preferred source API is `InsertAt`, `Append`, `RemoveAt`, `RemoveAll`, `SwapElements`, and `Sort`; `ListInsertRange`, `ListAppendRange`, `ListRemoveRange`, and `ListClear` remain filename/search aliases for the observed multi-record or wrapper behavior. The accepted `ListCompareFunction` typedef supports the CRT `qsort` comparator route used by `List::Sort`.

The same B009 pass resolves the two remaining raw helpers as source-authored private helpers instead of no-code blobs. [UID:0003K4][0x004f35a0-0x004f35db.ListReservePageCountRaw](by-memory/0x004f35a0-0x004f35db.ListReservePageCountRaw.md) emits `void List::ReservePageCapacity(int pageCount)`, which falls back to `m_pageSize` when the argument is zero and stores `GetMemoryMan()->ReallocateBufferMemory(m_data, m_elementSize * pageCount)` into `m_data`. [UID:0003K5][0x004f35e0-0x004f35fd.ListPageCountForElementCountRaw](by-memory/0x004f35e0-0x004f35fd.ListPageCountForElementCountRaw.md) emits `int List::PageCountForElementCount(int elementCount)`, returning one page for non-positive counts and otherwise `(elementCount - 1) / m_pageSize + 1`. Both helper names are inferred source-facing names; zero direct xrefs and no pointer-route hits remain confidence caps, not no-code proof.

## Observed Layout

```text
0x00  vtable
+0x04  int elementSize
+0x08  int pageSize
+0x0c  int count
+0x10  void* data
```

Source-facing field names recommended after B008 reanalysis are:

```text
0x00  compiler-emitted List vtable
+0x04  int m_elementSize
+0x08  int m_pageSize
+0x0c  int m_count
+0x10  void* m_data
```

The `m_` spellings are inferred/descriptive rather than proven original private member spellings. The semantics are stronger than raw offset names because the constructor, core methods, caller argument patterns, and destructor all agree: `m_elementSize` is the fixed byte stride, `m_pageSize` is the page/growth quantum in elements, `m_count` is the used element count, and `m_data` is the owned raw backing buffer.

IDA MCP decoded the `List` vtable at `0x0061ce2c` as:

| Slot | Offset | Method |
| --- | --- | --- |
| 0 | `+0x00` | `List::~List` / scalar deleting destructor |
| 1 | `+0x04` | inherited runtime/type helper at `0x004f4b10` |
| 2 | `+0x08` | inherited no-op virtual at `0x0041b6c0` |
| 3 | `+0x0c` | `List::GetData` |
| 4 | `+0x10` | `List::GetElementAt` |
| 5 | `+0x14` | `List::InsertAt` |
| 6 | `+0x18` | `List::Append` |
| 7 | `+0x1c` | `List::RemoveAt` |
| 8 | `+0x20` | `List::RemoveAll` |
| 9 | `+0x24` | `List::SwapElements` |

## Core Methods

| Method | Address | Role |
| --- | --- | --- |
| `List::List(int elementSize, int pageSize)` | `0x004f3060` | Initializes `LObject`, installs `List` vtable, zeroes `m_count`, and stores `GetMemoryMan()->ZeroAllocateBufferMemory(elementSize * pageSize)` into `m_data`. |
| `List::AssignFrom(List *source)` / `CopyFrom` search alternate | [UID:0003JT][0x004f3140-0x004f31cc.ListAssignFrom](by-memory/0x004f3140-0x004f31cc.ListAssignFrom.md) | Formal source-ready method that copies another list's layout/count, frees and reallocates storage, and copies element bytes. |
| `List::SetCount` | [UID:0003JU][0x004f31d0-0x004f329f.ListSetCount](by-memory/0x004f31d0-0x004f329f.ListSetCount.md) | Formal source-ready `void List::SetCount(int count)` method that computes old/new page counts from `m_count`, `count`, and `m_pageSize`, grows with `GetMemoryMan()->AllocateBufferMemory` or `ReallocateBufferMemory`, shrinks with `ReallocateBufferMemory`, and stores the requested `m_count`. `SetSize` is only a rejected/search alternate. |
| `List::GetCount` | inline source accessor / direct field read | Formal `int GetCount() const { return m_count; }` returns `m_count` at object offset `+0x0c`; inline expansion explains callers that decompile as direct field reads with no modeled call, including DialogPane UID0003KK. |
| `List::GetData` | [UID:0003JV][0x004f32a0-0x004f32a4.ListGetData](by-memory/0x004f32a0-0x004f32a4.ListGetData.md) | Formal source accessor returning `m_data`, the `+0x10` backing buffer pointer, as `void *List::GetData()`. |
| `List::GetElementAt` | [UID:0003JW][0x004f32b0-0x004f32da.ListGetElementAt](by-memory/0x004f32b0-0x004f32da.ListGetElementAt.md) | Formal source accessor returning `m_data + index * m_elementSize` as `void *List::GetElementAt(int index)` when valid; index `0` is accepted whenever `m_data` exists. |
| `List::InsertAt` | [UID:0003JX][0x004f32e0-0x004f33b5.ListInsertRange](by-memory/0x004f32e0-0x004f33b5.ListInsertRange.md) | Formal source-ready virtual insertion method. It computes old/new minimum-one page counts, allocates or reallocates `m_data` when the inserted count crosses a page boundary, shifts the tail upward with `MemoryMan::MoveBufferMemory`, increments `m_count`, and copies caller records into the gap with `MemoryMan::MemmoveWrapper`. The decompiler return is a helper-return artifact; the source API is `void`. |
| `List::Append` | [UID:0003JY][0x004f33c0-0x004f33d5.ListAppendRange](by-memory/0x004f33c0-0x004f33d5.ListAppendRange.md) | Formal source-ready wrapper that dispatches to `InsertAt(m_count, count, source)` through the insert slot, preserving derived insertion behavior. |
| `List::RemoveAt` | [UID:0003JZ][0x004f33e0-0x004f3493.ListRemoveRange](by-memory/0x004f33e0-0x004f3493.ListRemoveRange.md) | Formal source-ready virtual removal method. It compacts the tail with `MemoryMan::MoveBufferMemory`, compares old/new page counts, shrinks with `MemoryMan::ReallocateBufferMemory` when a page drops, uses the `m_pageSize` fallback when computed capacity is zero, and stores the new count. |
| `List::RemoveAll` | [UID:0003K0][0x004f34a0-0x004f34ab.ListClear](by-memory/0x004f34a0-0x004f34ab.ListClear.md) | Formal source-ready remove-all wrapper `RemoveAt(0, m_count)`. `ListClear` remains a descriptive/search alias only. |
| `List::SwapElements` | [UID:0003K1][0x004f34b0-0x004f3532.ListSwapElements](by-memory/0x004f34b0-0x004f3532.ListSwapElements.md) | Formal source-ready virtual method that treats both stack arguments as indices, rejects IDA's misleading `Size` parameter artifact, allocates one scratch element, fetches elements via `GetElementAt`, performs three `MemmoveWrapper` copies, and frees the scratch buffer. |
| `List::Sort` | [UID:0003K2][0x004f3540-0x004f355b.ListSort](by-memory/0x004f3540-0x004f355b.ListSort.md) | Formal source-ready non-virtual method that calls CRT `qsort(m_data, m_count, m_elementSize, compare)` using the class-level `ListCompareFunction` typedef. |
| `List::ReserveElementCapacity` | [UID:0003K3][0x004f3560-0x004f3597.ListReserveExactElementCountRaw](by-memory/0x004f3560-0x004f3597.ListReserveExactElementCountRaw.md) | Formal source-ready private helper that reserves backing storage for an exact element count by allocating or reallocating `m_data` through `GetMemoryMan`; it uses `m_elementSize` but does not update `m_count` or use `m_pageSize`. Current source name is inferred; no xrefs, direct calls, or pointer routes were found. |
| `List::ReservePageCapacity` | [UID:0003K4][0x004f35a0-0x004f35db.ListReservePageCountRaw](by-memory/0x004f35a0-0x004f35db.ListReservePageCountRaw.md) | Formal source-ready private raw helper. IDA still does not model it as a function and no direct xref/pointer route was found, but the raw body is source-shaped, has a unique signature, uses `m_elementSize`, `m_pageSize`, and `m_data`, and reallocates through `MemoryMan::ReallocateBufferMemory`. |
| `List::PageCountForElementCount` | [UID:0003K5][0x004f35e0-0x004f35fd.ListPageCountForElementCountRaw](by-memory/0x004f35e0-0x004f35fd.ListPageCountForElementCountRaw.md) | Formal source-ready private raw helper. IDA still does not model it as a function and no direct xref/pointer route was found, but the raw body is source-shaped, uniquely signed, and exactly computes rounded-up page count from `m_pageSize`. |
| `List::~List` non-deleting body | [UID:000192][0x004f30e0-0x004f3139.ListNonDeletingDestructor](by-memory/0x004f30e0-0x004f3139.ListNonDeletingDestructor.md) | Class-owned source destructor body: if `m_data` is non-null, stores `GetMemoryMan()->FreeBufferMemory(m_data)` back into `m_data`; compiler-generated code restores the vtable and runs `LObject` base teardown around the source body. |
| `List::~List` scalar deleting wrapper | [UID:00037L][0x004f3810-0x004f38a7.ListScalarDeletingDestructor](by-memory/0x004f3810-0x004f38a7.ListScalarDeletingDestructor.md) | Compiler ABI wrapper around `List::~List()` plus optional object deletion; do not hand-write wrapper logic in source C++. |

2026-06-25 B002 registration/source-summary repair keeps the method direction above but clarifies generated state. The exact child pages [UID:0003JT][0x004f3140-0x004f31cc.ListAssignFrom](by-memory/0x004f3140-0x004f31cc.ListAssignFrom.md) through [UID:0003K5][0x004f35e0-0x004f35fd.ListPageCountForElementCountRaw](by-memory/0x004f35e0-0x004f35fd.ListPageCountForElementCountRaw.md) are the source-bearing `List` method/helper bodies; [UID:00022S][0x004f3140-0x004f35fd.ListCoreMethods](by-memory/0x004f3140-0x004f35fd.ListCoreMethods.md) is only the non-emitting index. Source-facing names should prefer `AssignFrom`, `SetCount`, `GetData`, `GetElementAt`, `InsertAt`, `Append`, `RemoveAt`, `RemoveAll`, `SwapElements`, and `Sort`; the private raw helpers should be documented as capacity/page-count helpers such as `ReserveElementCapacity`, `ReservePageCapacity`, and `PageCountForElementCount`, not preserved as raw `sub_4F3560`-style artifacts. In that B002 pass, formal child C++ remained deferred pending child-specific source-shape review.

2026-06-29 B010 narrows that child-C++ deferral for [UID:0003JV][0x004f32a0-0x004f32a4.ListGetData](by-memory/0x004f32a0-0x004f32a4.ListGetData.md) only. `List::GetData` has no MemoryMan/helper dependency and now carries formal source C++ through this class route. Broader allocation, capacity, copy, and raw helper pages remain subject to their own child-specific source-shape review.

2026-06-29 B008 also narrows that deferral for [UID:0003JT][0x004f3140-0x004f31cc.ListAssignFrom](by-memory/0x004f3140-0x004f31cc.ListAssignFrom.md). The method's MemoryMan helper dependencies now have accepted source-facing names and formal C++ on their own pages, so UID0003JT emits `void List::AssignFrom(List *source)` through this class route. This does not make the remaining allocation/capacity/raw helper children source-ready without their own reports.

2026-06-29 B012 narrows the same deferral for [UID:0003JW][0x004f32b0-0x004f32da.ListGetElementAt](by-memory/0x004f32b0-0x004f32da.ListGetElementAt.md). The method has no helper dependency and uses only the accepted `m_elementSize`, `m_count`, and `m_data` field roles, so UID0003JW emits `void *List::GetElementAt(int index)` through this class route. This does not make the remaining insertion/removal/capacity/raw-helper children source-ready without their own reports.

2026-06-29 B009 narrows that deferral for [UID:0003JU][0x004f31d0-0x004f329f.ListSetCount](by-memory/0x004f31d0-0x004f329f.ListSetCount.md). The method's allocation helper dependencies now have accepted source-facing names and formal C++ on their own pages, so UID0003JU emits `void List::SetCount(int count)` through this class route. This does not make the remaining insertion/removal/capacity/raw-helper children source-ready without their own reports.

2026-06-29 B005 narrows that deferral for [UID:0003K3][0x004f3560-0x004f3597.ListReserveExactElementCountRaw](by-memory/0x004f3560-0x004f3597.ListReserveExactElementCountRaw.md). The helper's allocation dependencies have accepted source-facing names, and B005 current MCP/raw-PE evidence proves the exact private `List` body and no-reference confidence cap, so UID0003K3 emits `void List::ReserveElementCapacity(int elementCount)` through this class route.

2026-07-01 B009 supersedes the remaining B002/B005 child-C++ deferral for [UID:0003JX][0x004f32e0-0x004f33b5.ListInsertRange](by-memory/0x004f32e0-0x004f33b5.ListInsertRange.md) through [UID:0003K5][0x004f35e0-0x004f35fd.ListPageCountForElementCountRaw](by-memory/0x004f35e0-0x004f35fd.ListPageCountForElementCountRaw.md). Current MCP call ids `40` through `71`, current docs, accepted MemoryMan helper names, and the existing `List` field layout support formal source bodies for the six remaining modeled methods and the two raw helpers. The raw helper no-direct-xref state remains documented as a confidence cap, not a reason to keep empty markers.

## Ownership And Payload Semantics

`List` owns only the raw backing buffer at `m_data`. It does not know how to construct, destroy, or free payloads stored inside records. Caller-specific owners must drain payloads before `List` teardown when needed: `ResourceLayoutNameRecord +0x28` payloads are freed by ImageLib/ResourceLayout destructor bodies before the generic `List` is destroyed; `BlackHole` drains and deletes queued object pointers before inherited `List` storage cleanup; `ChattingPane`, `ObjectList`, and other pointer-list consumers own or observe pointed-to objects according to their own class rules.

DialogPane is another pointer-list consumer. Its `List(4, 20)` stores four-byte `ControlPane *` values, appends through `Append(1, &control)`, removes through `RemoveAt(index, 1)`, dereferences `GetElementAt` slots for pointer comparison/destruction, and uses inline `GetCount()` for direct `+0x0c` count reads. DialogPane owns the pointed-to controls; List owns only its backing buffer.

Representative constructor callers validate the generic fixed-width-storage model: `BlackHole` uses `List(4, 1024)` for owned object pointers, `ImageLib` uses `List(44, 10)` for `ResourceLayoutNameRecord` rows, `HierList` uses `List(payloadSize + 0x0b, 32)` before installing its derived vtable, text-edit and text-box helpers use `List(16, 16)` temporary rectangle lists, and TextEditPane constructs a `List(2, 128)` text-storage table plus 16-byte line/style/format tables. These callers reject feature-specific constructor ownership.

## ResourceLayout Evidence

`ImageLib::ImageLib` allocates a 20-byte object and calls `List::List(elementSize=44, pageSize=10)` before storing the result at `ImageLib + 0x0c`. `ResourceLayoutTable::LoadResourceIndex` then appends a 44-byte resource-name record through vtable slot `+0x18`, and lookup paths retrieve records through slot `+0x10`.

B006 destructor implementation uses the same model in source form: [UID:000173][0x004d0070-0x004d011b.ImageLibDestructor](by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md) reads `m_count` from `List +0x0c` as `GetCount()`, retrieves 44-byte records through the virtual `GetElementAt` slot `+0x10`, and deletes the list through the virtual destructor route after caller-specific `ResourceLayoutNameRecord::entries` payloads are freed.

That means the resource-layout registry should be modeled as:

```cpp
List* entryList; // elements are ResourceLayoutNameRecord, 0x2c bytes each
```

not as a distinct `ResourceLayoutStore` object with its own constructor or vtable.

B008 reanalysis explicitly rejects `ResourceLayoutStore::ResourceLayoutStore` as a source route for [UID:000191][0x004f3060-0x004f30d5.ListConstructor](by-memory/0x004f3060-0x004f30d5.ListConstructor.md). The resource-layout registry is one consumer of the generic constructor, not a specialization of it.

## Cross-References

- [UID:0000KS][List](by-file/List.md)
- [UID:000191][0x004f3060-0x004f30d5.ListConstructor](by-memory/0x004f3060-0x004f30d5.ListConstructor.md)
- [UID:000192][0x004f30e0-0x004f3139.ListNonDeletingDestructor](by-memory/0x004f30e0-0x004f3139.ListNonDeletingDestructor.md)
- [UID:00022S][0x004f3140-0x004f35fd.ListCoreMethods](by-memory/0x004f3140-0x004f35fd.ListCoreMethods.md)
- [UID:0003JT][0x004f3140-0x004f31cc.ListAssignFrom](by-memory/0x004f3140-0x004f31cc.ListAssignFrom.md)
- [UID:0003JU][0x004f31d0-0x004f329f.ListSetCount](by-memory/0x004f31d0-0x004f329f.ListSetCount.md)
- [UID:0003JV][0x004f32a0-0x004f32a4.ListGetData](by-memory/0x004f32a0-0x004f32a4.ListGetData.md)
- [UID:0003JW][0x004f32b0-0x004f32da.ListGetElementAt](by-memory/0x004f32b0-0x004f32da.ListGetElementAt.md)
- [UID:0003JX][0x004f32e0-0x004f33b5.ListInsertRange](by-memory/0x004f32e0-0x004f33b5.ListInsertRange.md)
- [UID:0003JY][0x004f33c0-0x004f33d5.ListAppendRange](by-memory/0x004f33c0-0x004f33d5.ListAppendRange.md)
- [UID:0003JZ][0x004f33e0-0x004f3493.ListRemoveRange](by-memory/0x004f33e0-0x004f3493.ListRemoveRange.md)
- [UID:0003K0][0x004f34a0-0x004f34ab.ListClear](by-memory/0x004f34a0-0x004f34ab.ListClear.md)
- [UID:0003K1][0x004f34b0-0x004f3532.ListSwapElements](by-memory/0x004f34b0-0x004f3532.ListSwapElements.md)
- [UID:0003K2][0x004f3540-0x004f355b.ListSort](by-memory/0x004f3540-0x004f355b.ListSort.md)
- [UID:0003K3][0x004f3560-0x004f3597.ListReserveExactElementCountRaw](by-memory/0x004f3560-0x004f3597.ListReserveExactElementCountRaw.md)
- [UID:0003K4][0x004f35a0-0x004f35db.ListReservePageCountRaw](by-memory/0x004f35a0-0x004f35db.ListReservePageCountRaw.md)
- [UID:0003K5][0x004f35e0-0x004f35fd.ListPageCountForElementCountRaw](by-memory/0x004f35e0-0x004f35fd.ListPageCountForElementCountRaw.md)
- [UID:00037L][0x004f3810-0x004f38a7.ListScalarDeletingDestructor](by-memory/0x004f3810-0x004f38a7.ListScalarDeletingDestructor.md)
- [UID:00006E][ImageLib](by-class/ImageLib.md)
- [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md)
- [UID:0000DF][SortedList](by-class/SortedList.md)
- [UID:000065][HierList](by-class/HierList.md)
- [UID:00009Q][ObjectList](by-class/ObjectList.md)
- [UID:0001VT][ResourceLayoutNameRecord](by-type/by-struct/ResourceLayoutNameRecord.md)
- [UID:0001VU][ResourceLayoutStore](by-type/by-struct/ResourceLayoutStore.md)
- [UID:0001BC][0x00516030-0x00516036.GetMemoryMan](by-memory/0x00516030-0x00516036.GetMemoryMan.md)
- [UID:0001BE][0x005160d0-0x00516162.ZeroAllocateBufferMemory](by-memory/0x005160d0-0x00516162.ZeroAllocateBufferMemory.md)
- [UID:0001BF][0x00516170-0x00516184.FreeBufferMemory](by-memory/0x00516170-0x00516184.FreeBufferMemory.md)

## Changes

- 2026-08-16 B009 UID0000MD dependency implementation: raised `92/91` to `93/94`, added exactly one `NEXUSTK_UTIL_LIST_H` guard around the complete existing formal H, and removed the empty H-only child marker after physical generated readback exposed its literal invalid placeholder. All declarations, CPP child placement, method routes, and the `0x14` size assertion are unchanged.

- 2026-07-31 B002 UID000090 dependency callback: moved the complete accepted `List` declaration unchanged from CPP into H under `LObject.h`, added the `0x14` size guard and child route, and reduced class-level CPP to `List.h` plus children so InputMan can consume a complete header type.

- 2026-07-12 B004 UID00012T support implementation:
  - Kept `92/91`, owner/emitter UID0000KS, reconstructable true, every accepted virtual/nonvirtual/private method, field layout, and source route.
  - Added only formal inline `int GetCount() const { return m_count; }`, matching the already-documented source accessor/direct-field lowering and exact `+0x0c` reads.
  - Added DialogPane `List(4, 20)` pointer-consumer evidence without changing List ownership semantics or any existing child score/body.

- 2026-07-01 Agent-B009 accepted implementation callback:
  - Raised this class page to `COMPLETION:92`, `CONFIDENCE:91` and populated the formal class declaration with `ListCompareFunction`, the accepted virtual API, non-virtual helpers, four `m_` fields, and private capacity/page-count helpers.
  - Recorded that [UID:0003JX][0x004f32e0-0x004f33b5.ListInsertRange](by-memory/0x004f32e0-0x004f33b5.ListInsertRange.md), [UID:0003JY][0x004f33c0-0x004f33d5.ListAppendRange](by-memory/0x004f33c0-0x004f33d5.ListAppendRange.md), [UID:0003JZ][0x004f33e0-0x004f3493.ListRemoveRange](by-memory/0x004f33e0-0x004f3493.ListRemoveRange.md), [UID:0003K0][0x004f34a0-0x004f34ab.ListClear](by-memory/0x004f34a0-0x004f34ab.ListClear.md), [UID:0003K1][0x004f34b0-0x004f3532.ListSwapElements](by-memory/0x004f34b0-0x004f3532.ListSwapElements.md), [UID:0003K2][0x004f3540-0x004f355b.ListSort](by-memory/0x004f3540-0x004f355b.ListSort.md), [UID:0003K4][0x004f35a0-0x004f35db.ListReservePageCountRaw](by-memory/0x004f35a0-0x004f35db.ListReservePageCountRaw.md), and [UID:0003K5][0x004f35e0-0x004f35fd.ListPageCountForElementCountRaw](by-memory/0x004f35e0-0x004f35fd.ListPageCountForElementCountRaw.md) now carry formal first-draft source under this class and route to [UID:0000KS][List](by-file/List.md).
  - Historicalized the older broad child-C++ deferral for those pages. The raw helpers [UID:0003K4][0x004f35a0-0x004f35db.ListReservePageCountRaw](by-memory/0x004f35a0-0x004f35db.ListReservePageCountRaw.md) and [UID:0003K5][0x004f35e0-0x004f35fd.ListPageCountForElementCountRaw](by-memory/0x004f35e0-0x004f35fd.ListPageCountForElementCountRaw.md) remain no-IDA-function/no-direct-xref helpers, but current source-shaped raw-body evidence supports private source declarations instead of empty/no-code markers.
- 2026-06-29 Agent-B005 implementation callback:
  - Marked [UID:0003K3][0x004f3560-0x004f3597.ListReserveExactElementCountRaw](by-memory/0x004f3560-0x004f3597.ListReserveExactElementCountRaw.md) as a formal source-ready private `void List::ReserveElementCapacity(int elementCount)` helper routed through this class to [UID:0000KS][List](by-file/List.md).
  - Preserved current MCP session `b2ae72ec` raw not-a-function state, exact body/padding/signature evidence, accepted `GetMemoryMan` / `AllocateBufferMemory` / `ReallocateBufferMemory` dependency names, no `m_count`/`m_pageSize` update, and no-xref/direct-call/pointer negative evidence as confidence caps.
  - Rejected MemoryMan ownership, SortedList ownership, feature/caller ownership, new source/free-helper ownership, aggregate emission, and continuing UID0003K3 as an empty emitter/no-code child.
- 2026-06-29 Agent-B009 implementation callback:
  - Marked [UID:0003JU][0x004f31d0-0x004f329f.ListSetCount](by-memory/0x004f31d0-0x004f329f.ListSetCount.md) as a formal source-ready `void List::SetCount(int count)` method routed through this class to [UID:0000KS][List](by-file/List.md).
  - Preserved current MCP session `967f0703` range/callee/xref/padding/negative-reference evidence, accepted `SetCount` over the rejected `SetSize` alternate, and narrowed the old broad child-C++ deferral so it no longer applies to UID0003JU.
- 2026-06-29 Agent-B012 implementation callback:
  - Marked [UID:0003JW][0x004f32b0-0x004f32da.ListGetElementAt](by-memory/0x004f32b0-0x004f32da.ListGetElementAt.md) as a formal source-ready `void *List::GetElementAt(int index)` method routed through this class to [UID:0000KS][List](by-file/List.md).
  - Preserved the zero-index-with-storage special case, current MCP session `967f0703` vtable/xref/padding evidence, and the distinction between this no-callee accessor and sibling List children still waiting for their own source-shape reviews.
- 2026-06-29 B008 ListAssignFrom implementation callback:
  - Marked [UID:0003JT][0x004f3140-0x004f31cc.ListAssignFrom](by-memory/0x004f3140-0x004f31cc.ListAssignFrom.md) as a formal source-ready `void List::AssignFrom(List *source)` method routed through this class to [UID:0000KS][List](by-file/List.md).
  - Historicalized the recovered `class_List.cpp` line as a generated lead only, not current authority, and narrowed the old broad child-C++ deferral so it no longer applies to UID0003JT.
- 2026-06-27 B006 ImageLib destructor support note: no score change. Added `List::GetCount` as the source-facing accessor for direct `m_count` reads and recorded that [UID:000173][0x004d0070-0x004d011b.ImageLibDestructor](by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md) uses `GetCount`, virtual `GetElementAt`, and virtual list deletion over `List(44, 10)` records.
- 2026-06-21 B008 Rule 26 source-quality incorporation:
  - Added source-facing field names `m_elementSize`, `m_pageSize`, `m_count`, and `m_data`, clarified that spellings are inferred/descriptive, and linked constructor allocation to `GetMemoryMan()->ZeroAllocateBufferMemory(elementSize * pageSize)`.
  - Documented ownership semantics: generic `List` owns only raw backing storage while caller-specific classes own payload lifetimes.
  - Added representative caller evidence and explicit ResourceLayoutStore rejection so [UID:000191][0x004f3060-0x004f30d5.ListConstructor](by-memory/0x004f3060-0x004f30d5.ListConstructor.md) is not misread as a resource-layout specialization.

- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` and attached to [UID:0000KS][List](by-file/List.md) because this class is 88/88 and the parent file is 86/82. Live IDA MCP on `NexusTK.exe` confirmed the constructor/destructor and fixed-width array methods at `0x004f3060`, `0x004f30e0`, `0x004f32a0`, `0x004f32b0`, `0x004f32e0`, `0x004f33c0`, `0x004f33e0`, `0x004f34a0`, `0x004f34b0`, `0x004f3540`, and scalar deleting destructor `0x004f3810`.
- Completion/confidence score update: existed before as `0/0`; changed to `88/88`. Summary: the generic fixed-width dynamic array is documented with layout, vtable slots, core methods, destructor ownership, and resource-layout correction evidence, leaving only final source-level rewrite detail below full completion. Evidence: constructor/core/destructor memory pages, decoded vtable, `ImageLib` allocation/call evidence, and `ResourceLayoutStore` overlay correction.
- 2026-06-11 Agent-A001 Batch 158 continuation split:
  - What existed before: `COMPLETION:88`, `CONFIDENCE:88`, with the scalar deleting destructor only named by raw address.
  - Changed to: `COMPLETION:89`, `CONFIDENCE:89`; parent remains [UID:0000KS][List](by-file/List.md).
  - Evidence: [UID:00037L][0x004f3810-0x004f38a7.ListScalarDeletingDestructor](by-memory/0x004f3810-0x004f38a7.ListScalarDeletingDestructor.md) now carries exact range, vtable-reset, backing-buffer free, `LObject` destructor, delete-flag behavior, and ownership evidence. This also repairs the former mixed `SortedList` aggregate blocker.
- 2026-06-12 Agent-A001 Goal 2 ListCore split:
  - Added exact child references [UID:0003JT][0x004f3140-0x004f31cc.ListAssignFrom](by-memory/0x004f3140-0x004f31cc.ListAssignFrom.md) through [UID:0003K5][0x004f35e0-0x004f35fd.ListPageCountForElementCountRaw](by-memory/0x004f35e0-0x004f35fd.ListPageCountForElementCountRaw.md) for the copied-state, count, accessor, insert/append/remove/clear/swap/sort, and raw reserve/page-count helper bodies.
  - Evidence: [UID:00022S][0x004f3140-0x004f35fd.ListCoreMethods](by-memory/0x004f3140-0x004f35fd.ListCoreMethods.md) now records the live IDA MCP boundary, decompilation, raw disassembly, unique signature, xref, and padding checks behind the split.
- 2026-06-25 Agent-B002 accepted report implementation:
  - Recorded that the exact core child pages are the registered source-bearing `List` method/helper bodies and the aggregate remains a no-code/non-emitting index.
  - Preserved `RemoveAll` as the preferred source API wording for the `0x004f34a0` wrapper while keeping the `ListClear` child filename as a search alias, and documented the raw helpers as private capacity/page-count helpers rather than raw IDA artifacts.

- 2026-06-26 Agent-B011 implementation callback:
  - Updated [UID:000192][0x004f30e0-0x004f3139.ListNonDeletingDestructor](by-memory/0x004f30e0-0x004f3139.ListNonDeletingDestructor.md) as class-owned formal `List::~List()` source instead of a file-level/generated-owner placeholder.
  - Evidence: IDA MCP session `80de0a67` reconfirmed `sub_4F30E0` size `0x59`, direct callees `GetMemoryMan`, `FreeBufferMemory`, and `LObject` teardown, 13 refs including EH/unwind refs, and the `0x0061ce2c` vtable route through the scalar deleting wrapper.
- 2026-06-29 Agent-B010 implementation callback:
  - Updated [UID:0003JV][0x004f32a0-0x004f32a4.ListGetData](by-memory/0x004f32a0-0x004f32a4.ListGetData.md) as formal `void *List::GetData()` source returning `m_data`.
  - Preserved the accepted inferred `m_data` field role at `+0x10`, current MCP session `967f0703` vtable-slot evidence, and the distinction between this simple accessor and the still-deferred broader List helper source-shape work.
