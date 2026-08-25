*** UID:0000DF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000NU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000NU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "SortedList.h"
#include "MemoryMan.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "List.h"

class SortedList : public List
{
public:
    SortedList(int elementSize,
               ListCompareFunction compare,
               int pageSize);
    virtual ~SortedList();
    virtual void *GetElementAt(int index);
    virtual void RemoveAt(int index, int count);
    virtual void RemoveAll();

    int InsertSorted(const void *element);
    int FindFirstEqual(const void *key);

private:
    ListCompareFunction m_compare;
};

typedef char SortedListSizeMustBe24[sizeof(SortedList) == 0x18 ? 1 : -1];

[[CHILDREN]]
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# SortedList

## Status

- Confidence: strong for layout, methods, comparator callback, vtable, utility ownership, and the standalone source route.
- Source file: [UID:0000NU][SortedList](by-file/SortedList.md), emitted as `NexusTK/util/SortedList.cpp` with `SortedList.h`.
- Autogen parent: [UID:0000NU][SortedList](by-file/SortedList.md)
- Main memory index: [UID:000193][0x004f3600-0x004f3a43.SortedList](by-memory/0x004f3600-0x004f3a43.SortedList.md)
- Historical generated source candidate: `class_SortedList.cpp`; use only as search context, not as authority.

## Class Purpose

`SortedList` is a small sorted fixed-width array container derived from [UID:000079][List](by-class/List.md). It keeps the same base layout and adds a compare callback at `+0x14`. It is used where callers need sorted insertion and lookup rather than only append/index operations.

## Observed Layout

```text
+0x00  vtable
+0x04  int m_elementSize
+0x08  int m_pageSize
+0x0c  int m_count
+0x10  void* m_data
+0x14  ListCompareFunction m_compare
```

The generated `sortContext` name for `+0x14` is misleading. IDA decompilation of `0x004f3690` and `0x004f3780` calls it as a comparator function pointer. The source-facing `m_compare` spelling is inferred but matches the accepted `ListCompareFunction` vocabulary in [UID:000079][List](by-class/List.md). The inherited four storage fields remain protected in `List`; only `m_compare` is private to this `0x18`-byte derived class.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| [UID:00037I][0x004f3600-0x004f3681.SortedListConstructor](by-memory/0x004f3600-0x004f3681.SortedListConstructor.md) | `SortedList::SortedList` | Builds the base `List`, stores the comparator, then switches to the `SortedList` vtable. |
| [UID:00037J][0x004f3690-0x004f377b.SortedListInsertSorted](by-memory/0x004f3690-0x004f377b.SortedListInsertSorted.md) | `int InsertSorted(const void *element)` | Finds the ordered insertion point with the comparator, grows the buffer, shifts and fixed-width copies the element, increments count, and returns its index. |
| [UID:00037K][0x004f3780-0x004f3803.SortedListFindFirstEqual](by-memory/0x004f3780-0x004f3803.SortedListFindFirstEqual.md) | `int FindFirstEqual(const void *key)` | Uses `bsearch`, converts the hit pointer to an index, then scans backward to the first equal record. |
| [UID:00037M][0x004f38b0-0x004f3947.SortedListScalarDeletingDestructor](by-memory/0x004f38b0-0x004f3947.SortedListScalarDeletingDestructor.md) | `SortedList::~SortedList` | Frees the backing buffer, destroys `LObject`, and optionally deletes `this`. |
| [UID:00037N][0x004f3950-0x004f397a.SortedListGetElementAt](by-memory/0x004f3950-0x004f397a.SortedListGetElementAt.md) | `SortedList::GetElementAt` | Same bounds/data behavior as `List::GetElementAt`. |
| [UID:00037O][0x004f3980-0x004f398b.SortedListClear](by-memory/0x004f3980-0x004f398b.SortedListClear.md) | `SortedList::RemoveAll` | Overrides the base `RemoveAll` slot and removes all current elements through `RemoveAt`. |
| [UID:00037P][0x004f3990-0x004f3a43.SortedListRemoveRange](by-memory/0x004f3990-0x004f3a43.SortedListRemoveRange.md) | `SortedList::RemoveAt` | Overrides the base range-removal slot, shifts elements down, and shrinks page allocation when possible. |

## Vtable And ABI

The `SortedList` vtable begins at `0x0061ce58` after complete-object locator `0x00649d78`. Its exact ten slots preserve inherited methods where `SortedList` does not override them:

| Slot | Target | Source role |
| --- | --- | --- |
| `+0x00` | `0x004f38b0` | `SortedList` scalar deleting destructor wrapper for the virtual destructor. |
| `+0x04` | `0x004f4b10` | Inherited `LObject` virtual slot. |
| `+0x08` | `0x0041b6c0` | Inherited `LObject` virtual slot. |
| `+0x0c` | `0x004f32a0` | Inherited `List::GetData`. |
| `+0x10` | `0x004f3950` | `SortedList::GetElementAt`. |
| `+0x14` | `0x004f32e0` | Inherited `List::InsertAt`. |
| `+0x18` | `0x004f33c0` | Inherited `List::Append`. |
| `+0x1c` | `0x004f3990` | `SortedList::RemoveAt`. |
| `+0x20` | `0x004f3980` | `SortedList::RemoveAll`. |
| `+0x24` | `0x004f34b0` | Inherited `List::SwapElements`. |

The only direct xref to the vtable base is the constructor store at `0x004f3669`. `InsertSorted` and `FindFirstEqual` are public non-virtual methods and therefore do not occupy vtable slots. The formal size guard preserves `sizeof(SortedList) == 0x18`.

## InsertSorted Invariants And Consumers

[UID:00037J][0x004f3690-0x004f377b.SortedListInsertSorted](by-memory/0x004f3690-0x004f377b.SortedListInsertSorted.md) calls `m_compare(element, current)` and advances on equality, so duplicate keys are inserted after existing equal keys. It retains the base fixed-width storage/page arithmetic, grows only across a page boundary, overlap-shifts the suffix, increments `m_count`, copies one element, and returns the inserted index. It intentionally preserves the binary's absence of null comparator/source checks, zero-page-size guards, arithmetic overflow checks, and allocator-result recovery; project allocation/reallocation failure propagates through the accepted `Win32Error *` throw behavior.

Exactly thirteen direct code callers use `InsertSorted`: `ChangeMan::Register` at `0x0047ed75` ignores the returned index, while twelve Message calls at `0x00520f4c`, `0x00520fbc`, `0x0052102e`, `0x0052109e`, `0x0052110c`, `0x0052117c`, `0x005211f2`, `0x00521261`, `0x005212cd`, `0x0052133d`, `0x005213ff`, and `0x005214a2` immediately pass EAX to normalizer calls at `0x00520f54`, `0x00520fc4`, `0x00521036`, `0x005210a6`, `0x00521114`, `0x00521184`, `0x005211fa`, `0x00521269`, `0x005212d5`, `0x00521345`, `0x00521407`, and `0x005214aa`. That split proves a meaningful insertion-index return rather than a bool or void contract.

## Source Placement

The current reconstruction uses standalone `NexusTK/util/SortedList.cpp` and `SortedList.h` under [UID:0000NU][SortedList](by-file/SortedList.md). The CPP shell includes both `SortedList.h` and `MemoryMan.h`: the self-header supplies the complete class declaration, while `MemoryMan.h` supplies `MemoryMan`, `GetMemoryMan`, `size_t`, and the allocator/move/copy member declarations required by method children. The public header does not expose a MemoryMan type and therefore includes only `List.h`.

## Historical Assumptions

Earlier revisions left a `List.cpp` fold active because the class is adjacent to `List` in the binary and shares its storage behavior. That remains useful historical search context but is rejected for current reconstruction: a dedicated by-file root, the proposed source tree, separate RTTI/vtable identity, generated route, and class-local method island all select standalone `SortedList.cpp`/`.h`. The historical `class_SortedList.cpp` generated name is likewise search context, not source authority.

## Ownership Notes

Older generated output omitted the non-virtual helper methods at `0x004f3690` and `0x004f3780`. IDA confirms both are real functions between the constructor and destructor. The known helper callers are [UID:0000I2][ChangeMan](by-file/ChangeMan.md) registration/dispatch wrappers at `0x0047ed50`, `0x0047ed80`, and `0x0047ee20`, which store and query `ChangeManEntry` records in a sorted list.

For reconstructed source, keep these helpers with `SortedList` even if older generated class files did not emit them.

The ChangeMan family uses the following SortedList roles: `int InsertSorted(const void *element)` inserts a 0x10-byte `ChangeManEntry`, `FindFirstEqual` lower-bounds owner groups, virtual slot `+0x10` returns an entry by index, and virtual slot `+0x1c` removes a count-one range. The source-facing spellings are inferred from behavior and the accepted base-class API, while the formal class declaration now records the selected source shape instead of retaining raw aliases.

## 2026-07-13 B003 UID0000ZW Helper Contract

- Exact UID00037J disassembly proves `int SortedList::InsertSorted(const void *element)`: it computes the insertion index in EBX, comparator-scans, page-grows, shifts occupied trailing bytes, increments count, copies exactly `elementSize` bytes, executes `mov eax, ebx`, and returns with `retn 4`.
- ChangeMan constructs this class with `elementSize == 0x10`, comparator `CompareChangeEntries`, and page size 100. UID0000ZW passes a stack ChangeManEntry and intentionally ignores the returned index.
- The ignored ChangeMan result supports a `void ChangeMan::Register` contract without weakening this helper's genuine `int` return. No caller-visible bool conversion or ChangeMan-local insertion helper exists.
- Field layout, all exact child ranges, comparator ownership, and the neighboring List destructor exclusion remain unchanged. The former source-split caveat is resolved in favor of the standalone by-file route; `List.cpp` folding remains only historical context.
- The historical `91/90` score closed the helper-signature/return/use blocker but predated the complete formal declaration, vtable inventory, dependency shell, and source-placement decision.

2026-06-11 live IDA MCP reconfirms `0x004f3690` performs comparator-driven ordered insertion with chunked grow/shift/copy behavior, `0x004f3780` performs `_bsearch` plus backward first-equal scanning, and `0x004f3990` shifts and shrinks fixed-width storage. The same pass reconfirms `0x004f3810-0x004f38a7` is the neighboring `List` destructor, not a `SortedList` method.

2026-06-11 continuation split: exact method pages [UID:00037I][0x004f3600-0x004f3681.SortedListConstructor](by-memory/0x004f3600-0x004f3681.SortedListConstructor.md), [UID:00037J][0x004f3690-0x004f377b.SortedListInsertSorted](by-memory/0x004f3690-0x004f377b.SortedListInsertSorted.md), [UID:00037K][0x004f3780-0x004f3803.SortedListFindFirstEqual](by-memory/0x004f3780-0x004f3803.SortedListFindFirstEqual.md), [UID:00037M][0x004f38b0-0x004f3947.SortedListScalarDeletingDestructor](by-memory/0x004f38b0-0x004f3947.SortedListScalarDeletingDestructor.md), [UID:00037N][0x004f3950-0x004f397a.SortedListGetElementAt](by-memory/0x004f3950-0x004f397a.SortedListGetElementAt.md), [UID:00037O][0x004f3980-0x004f398b.SortedListClear](by-memory/0x004f3980-0x004f398b.SortedListClear.md), and [UID:00037P][0x004f3990-0x004f3a43.SortedListRemoveRange](by-memory/0x004f3990-0x004f3a43.SortedListRemoveRange.md) now attach directly to this class after clearing the strict child+parent `85/85` gate. The neighboring [UID:00037L][0x004f3810-0x004f38a7.ListScalarDeletingDestructor](by-memory/0x004f3810-0x004f38a7.ListScalarDeletingDestructor.md) attaches to [UID:000079][List](by-class/List.md), which closes the former mixed-ownership blocker.

## Cross-References

- [UID:0000NU][SortedList](by-file/SortedList.md)
- [UID:000193][0x004f3600-0x004f3a43.SortedList](by-memory/0x004f3600-0x004f3a43.SortedList.md)
- [UID:00037I][0x004f3600-0x004f3681.SortedListConstructor](by-memory/0x004f3600-0x004f3681.SortedListConstructor.md)
- [UID:00037J][0x004f3690-0x004f377b.SortedListInsertSorted](by-memory/0x004f3690-0x004f377b.SortedListInsertSorted.md)
- [UID:00037K][0x004f3780-0x004f3803.SortedListFindFirstEqual](by-memory/0x004f3780-0x004f3803.SortedListFindFirstEqual.md)
- [UID:00037M][0x004f38b0-0x004f3947.SortedListScalarDeletingDestructor](by-memory/0x004f38b0-0x004f3947.SortedListScalarDeletingDestructor.md)
- [UID:00037N][0x004f3950-0x004f397a.SortedListGetElementAt](by-memory/0x004f3950-0x004f397a.SortedListGetElementAt.md)
- [UID:00037O][0x004f3980-0x004f398b.SortedListClear](by-memory/0x004f3980-0x004f398b.SortedListClear.md)
- [UID:00037P][0x004f3990-0x004f3a43.SortedListRemoveRange](by-memory/0x004f3990-0x004f3a43.SortedListRemoveRange.md)
- [UID:000079][List](by-class/List.md)
- [UID:00001K][ChangeMan](by-class/ChangeMan.md)
- [UID:0000ZX][0x0047ed50-0x0047ee18.ChangeManRegistrationMethods](by-memory/0x0047ed50-0x0047ee18.ChangeManRegistrationMethods.md)
- [UID:000084][Message](by-class/Message.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `86`, confidence `82`.
- Evidence: the page documents layout, comparator field correction, method map, omitted helper ownership, caller evidence, and source-placement options; confidence remains capped by final file split uncertainty.
- 2026-06-05: Marked reconstructable and left unassigned.
- Evidence: live IDA MCP `lookup_funcs` confirms the constructor, sorted insert/search helpers, destructor, access, clear, and remove-range anchors at `0x004f3600`, `0x004f3690`, `0x004f3780`, `0x004f38b0`, `0x004f3950`, `0x004f3980`, and `0x004f3990`. The likely standalone parent [UID:0000NU][SortedList](by-file/SortedList.md) is only `80/78`, so the parent UID stays blank.
- 2026-06-06 parent attachment:
  - Before: confidence was `82`, generated-source wording was still present, and `AUTOGEN_PARENT_UID` stayed blank because the file parent was only `80/78`.
  - Changed to: confidence `84`, `AUTOGEN_PARENT_UID:0000NU`, and generated-source names demoted to search context only.
  - Evidence: [UID:0000NU][SortedList](by-file/SortedList.md) is now `84/84`, this class is `86/84`, and both clear the 80/80 parent gate. The exact source split from [UID:0000KS][List](by-file/List.md) remains a caveat, so C++ remains blank.
- 2026-06-11 Agent-A001 Batch 158 gate refresh:
  - What existed before: `COMPLETION:86`, `CONFIDENCE:84`, attached under the older gate but below the strict 85/85 confidence threshold.
  - Changed to: `COMPLETION:87`, `CONFIDENCE:86`; parent remains [UID:0000NU][SortedList](by-file/SortedList.md), now `85/85`.
  - Evidence: live IDA MCP reconfirmed exact method boundaries, comparator callback use, insert/search/remove behaviors, the `SortedList` vtable write, ChangeMan helper callers, and the neighboring `List` destructor exclusion. Final C++ remains blank below the 95+ code gate.
- 2026-06-11 Agent-A001 Batch 158 continuation split:
  - What existed before: `COMPLETION:87`, `CONFIDENCE:86`, with the method map still pointing at raw ranges inside a mixed aggregate.
  - Changed to: `COMPLETION:89`, `CONFIDENCE:89`; parent remains [UID:0000NU][SortedList](by-file/SortedList.md).
  - Evidence: exact child method pages now cover all `SortedList` methods in the island and attach to this class; the embedded `List` destructor has its own [UID:00037L][0x004f3810-0x004f38a7.ListScalarDeletingDestructor](by-memory/0x004f3810-0x004f38a7.ListScalarDeletingDestructor.md) child and direct [UID:000079][List](by-class/List.md) parent.
- 2026-07-13 B003 UID0000ZW implementation:
  - Changed `89/89 -> 91/90` and added the exact `int InsertSorted(const void *element)` return contract, fixed-width insertion behavior, and UID0000ZW ignored-result evidence while preserving the blank formal block and file-split caveat.
- 2026-08-03 Agent-B005 UID00037J accepted ordinary implementation callback:
  - Changed `91/90 -> 94/94`, populated the formal CPP dependency shell and complete `SortedList : public List` H declaration, including public non-virtual sorted helpers, exact overrides, private comparator, `0x18` size guard, and child routes.
  - Added the exact ten-slot vtable, constructor-only vtable xref, thirteen InsertSorted callers/twelve index-normalizer pairs, after-equals invariant, allocation/failure behavior, and the current standalone `SortedList.cpp`/`.h` route.
  - Retained the former `List.cpp` fold only as a rejected historical assumption and preserved all exact method children plus the neighboring List-destructor exclusion.

## Score Rationale

Completion and confidence are `94/94`. The page now owns a complete source-ready declaration and legal CPP include shell, exact `0x18` layout, inherited/overridden method map, ten-slot vtable, constructor xref, comparator and duplicate-order semantics, full InsertSorted consumer inventory, failure behavior, direct child routing, and standalone source placement. The remaining cap reflects inferred original identifier/access spelling and the fact that this target pass did not independently final-audit every sibling body; it does not block current formal source.
