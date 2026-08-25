*** UID:0000NU | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# SortedList

## Status

- Current module: `NexusTK/util/SortedList.cpp` with public declaration in `NexusTK/util/SortedList.h`.
- Confidence: strong for class behavior, vtable/memory ownership, complete source inventory, and the standalone `NexusTK/util/` route.
- Historical generated source candidate: `class_SortedList.cpp`; use only as search context, not as authority.

## File Role

`SortedList.cpp` owns the sorted fixed-width list container that extends [UID:0000KS][List](by-file/List.md). `SortedList.h` owns the derived-class declaration. The module is a reusable utility container and must not be confused with UI list panes. Its known consumers include [UID:0000I2][ChangeMan](by-file/ChangeMan.md) listener storage and [UID:000084][Message](by-class/Message.md) entry storage.

## Proposed Contents

- [UID:0000DF][SortedList](by-class/SortedList.md)
- declaration-generated `SortedList` RTTI/vtable data at `0x0061ce54-0x0061ce84`, with vtable base `0x0061ce58`, documented by [UID:0003OL][0x0061ce28-0x0061ce84.ListSortedListVtableData](by-memory/0x0061ce28-0x0061ce84.ListSortedListVtableData.md)
- exact `SortedList` method pages [UID:00037I][0x004f3600-0x004f3681.SortedListConstructor](by-memory/0x004f3600-0x004f3681.SortedListConstructor.md), [UID:00037J][0x004f3690-0x004f377b.SortedListInsertSorted](by-memory/0x004f3690-0x004f377b.SortedListInsertSorted.md), [UID:00037K][0x004f3780-0x004f3803.SortedListFindFirstEqual](by-memory/0x004f3780-0x004f3803.SortedListFindFirstEqual.md), [UID:00037M][0x004f38b0-0x004f3947.SortedListScalarDeletingDestructor](by-memory/0x004f38b0-0x004f3947.SortedListScalarDeletingDestructor.md), [UID:00037N][0x004f3950-0x004f397a.SortedListGetElementAt](by-memory/0x004f3950-0x004f397a.SortedListGetElementAt.md), [UID:00037O][0x004f3980-0x004f398b.SortedListClear](by-memory/0x004f3980-0x004f398b.SortedListClear.md), and [UID:00037P][0x004f3990-0x004f3a43.SortedListRemoveRange](by-memory/0x004f3990-0x004f3a43.SortedListRemoveRange.md)
- source-facing virtual overrides `GetElementAt`, `RemoveAt`, and `RemoveAll`, plus public non-virtual helpers `InsertSorted` and `FindFirstEqual`; inherited `GetData`, `InsertAt`, `Append`, and `SwapElements` remain emitted by [UID:0000KS][List](by-file/List.md)
- `#include "SortedList.h"` and `#include "MemoryMan.h"` in the CPP shell, with the class declaration and `List.h` dependency in the H shell
- Explicit exclusion: [UID:00037L][0x004f3810-0x004f38a7.ListScalarDeletingDestructor](by-memory/0x004f3810-0x004f38a7.ListScalarDeletingDestructor.md) belongs to the base `List` route and must not be emitted into this module.

## Source Placement Decision

The current reconstruction uses standalone `NexusTK/util/SortedList.cpp` and `SortedList.h`. This route is selected by the dedicated by-file root, proposed source tree, generated owner route, separate RTTI/vtable identity, and the class-local method island. `SortedList.cpp` emits class-owned method children; `SortedList.h` emits the complete derived declaration. MemoryMan is a translation-unit implementation dependency and therefore appears in the CPP include shell rather than the public header.

## Historical Assumptions

Older revisions allowed folding the class into [UID:0000KS][List](by-file/List.md) because of binary adjacency and shared storage behavior. That remains historical search context, not an active source-placement alternative. It was superseded by the existing dedicated file root and current structural/generator evidence. The historical generated candidate `class_SortedList.cpp` likewise remains non-authoritative search context.

## Evidence

- `SortedList::SortedList` constructs the same storage layout as `List`, stores a comparator at `+0x14`, and installs `SortedList` vtable.
- IDA names and RTTI place the `SortedList` vtable immediately after the `List` vtable.
- IDA confirms helper functions at `0x004f3690` and `0x004f3780`; older generated output omitted them, so the owning project docs should remain authoritative.
- IDA caller checks on 2026-05-25 show `0x004f3690` called by `ChangeMan::Register` at `0x0047ed50`, and `0x004f3780` called by `ChangeMan::UnregisterFiltered`/dispatch helpers at `0x0047ed80` and `0x0047ee20`.
- `Message::Message` constructs a `SortedList` for fixed-size message entries.
- 2026-06-11 live IDA MCP reconfirms the class-local functions at `0x004f3600`, `0x004f3690`, `0x004f3780`, `0x004f38b0`, `0x004f3950`, `0x004f3980`, and `0x004f3990`; `0x004f3810-0x004f38a7` is a neighboring `List` destructor and must not be pulled into `SortedList.cpp`.
- 2026-06-11 live IDA MCP `xrefs_to 0x0061ce58` reports the `SortedList` vtable write only from the constructor at `0x004f3669`, which supports the standalone class identity while leaving the final standalone-versus-`List.cpp` source split as a caveat.
- 2026-06-11 continuation split created exact child method pages for every `SortedList` method in the mixed island and assigned them to [UID:0000DF][SortedList](by-class/SortedList.md); the neighboring [UID:00037L][0x004f3810-0x004f38a7.ListScalarDeletingDestructor](by-memory/0x004f3810-0x004f38a7.ListScalarDeletingDestructor.md) belongs to [UID:0000KS][List](by-file/List.md).
- The `SortedList` vtable contains the scalar deleting destructor, inherited `LObject` slots, inherited `List::GetData`, `List::InsertAt`, `List::Append`, and `List::SwapElements`, plus `SortedList::GetElementAt`, `SortedList::RemoveAt`, and `SortedList::RemoveAll`. Only the constructor at `0x004f3669` references the vtable base.
- [UID:00037J][0x004f3690-0x004f377b.SortedListInsertSorted](by-memory/0x004f3690-0x004f377b.SortedListInsertSorted.md) inserts after existing equal keys, uses page-counted MemoryMan allocation/reallocation, overlap-shifts the suffix, copies one fixed-width record, and returns its insertion index. ChangeMan intentionally ignores that index; twelve Message helpers immediately pass it to their duplicate-sequence normalizer.
- Failure semantics remain the binary's project style: allocation/reallocation failure follows the accepted `Win32Error *` throw path, and the source adds no modern null, page-size, or overflow guards.

## Score Rationale

- Completion and confidence are `92/92` because this file root now records the standalone CPP/H decision, complete class/method/vtable inventory, formal dependency routing, comparator layout, sorted insertion/search behavior, exact consumer roles, generated vtable disposition, and explicit exclusion of the neighboring `List` scalar wrapper.
- Current evidence agrees on reusable utility ownership under `NexusTK/util/`. Exact original physical filename text is not preserved, which caps the score without reopening the resolved current placement.
- Formal source is emitted through [UID:0000DF][SortedList](by-class/SortedList.md) and its exact method children rather than duplicated in this by-file page.

## Cross-References

- [UID:0000DF][SortedList](by-class/SortedList.md)
- [UID:000193][0x004f3600-0x004f3a43.SortedList](by-memory/0x004f3600-0x004f3a43.SortedList.md)
- [UID:00037I][0x004f3600-0x004f3681.SortedListConstructor](by-memory/0x004f3600-0x004f3681.SortedListConstructor.md)
- [UID:00037J][0x004f3690-0x004f377b.SortedListInsertSorted](by-memory/0x004f3690-0x004f377b.SortedListInsertSorted.md)
- [UID:00037K][0x004f3780-0x004f3803.SortedListFindFirstEqual](by-memory/0x004f3780-0x004f3803.SortedListFindFirstEqual.md)
- [UID:00037M][0x004f38b0-0x004f3947.SortedListScalarDeletingDestructor](by-memory/0x004f38b0-0x004f3947.SortedListScalarDeletingDestructor.md)
- [UID:00037N][0x004f3950-0x004f397a.SortedListGetElementAt](by-memory/0x004f3950-0x004f397a.SortedListGetElementAt.md)
- [UID:00037O][0x004f3980-0x004f398b.SortedListClear](by-memory/0x004f3980-0x004f398b.SortedListClear.md)
- [UID:00037P][0x004f3990-0x004f3a43.SortedListRemoveRange](by-memory/0x004f3990-0x004f3a43.SortedListRemoveRange.md)
- [UID:0000KS][List](by-file/List.md)
- [UID:000079][List](by-class/List.md)
- [UID:0000I2][ChangeMan](by-file/ChangeMan.md)
- [UID:0000ZX][0x0047ed50-0x0047ee18.ChangeManRegistrationMethods](by-memory/0x0047ed50-0x0047ee18.ChangeManRegistrationMethods.md)
- [UID:000084][Message](by-class/Message.md)

## Changes

- 2026-06-05 projected-path assignment:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, so the by-file row remained a generated-root coverage error.
  - Changed to: `NexusTK/util/`.
  - Summary/evidence: live IDA MCP lookup confirms the documented `SortedList` anchors at `0x004f3600` and `0x004f3690`; proposed-source-tree keeps `SortedList.cpp` with shared utility/container code rather than UI, map, or render ownership.

- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `80` and confidence to `78`.
  - Evidence: document covers utility role, proposed contents, vtable/comparator behavior, omitted helper evidence, caller checks, List relationship, and cross-references; confidence remains limited by the final `SortedList.cpp` vs `List.cpp` split.
- 2026-06-06 parent-chain evidence refresh:
  - Before: the page still cited recovered/generated source as context and stayed at `80/78`, which blocked [UID:0000DF][SortedList](by-class/SortedList.md) from attaching to this by-file root despite the class and utility placement evidence.
  - Changed to: completion `84`, confidence `84`, and generated-source names demoted to search context only.
  - Summary/evidence: [UID:0000DF][SortedList](by-class/SortedList.md), [UID:000193][0x004f3600-0x004f3a43.SortedList](by-memory/0x004f3600-0x004f3a43.SortedList.md), [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md), ChangeMan caller docs, and Message construction docs support a `NexusTK/util/` source root. The standalone-vs-`List.cpp` split remains a caveat, so no reconstruction C++ was added.
- 2026-06-11 Agent-A001 Batch 158 gate refresh:
  - What existed before: `COMPLETION:84`, `CONFIDENCE:84`, just below the strict 85/85 gate.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:85`.
  - Summary/evidence: live IDA MCP reconfirmed the exact SortedList-owned method functions, the vtable write at `0x004f3669`, ChangeMan helper callers, and the neighboring `List::~List` span at `0x004f3810-0x004f38a7`. The file parent now clears the strict gate for direct `SortedList` children, while final C++ remains blank below the 95+ code gate.
- 2026-06-11 Agent-A001 Batch 158 continuation split:
  - What existed before: `COMPLETION:85`, `CONFIDENCE:85`, with the exact method split still pending.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:86`.
  - Summary/evidence: exact `SortedList` method pages now attach through [UID:0000DF][SortedList](by-class/SortedList.md), while the embedded `List` destructor child attaches through [UID:000079][List](by-class/List.md) and [UID:0000KS][List](by-file/List.md). The file remains above the strict parent gate.
- 2026-08-03 Agent-B005 UID00037J accepted ordinary implementation callback:
  - Changed `86/86 -> 92/92` and adopted standalone `NexusTK/util/SortedList.cpp` plus `SortedList.h` as the current route.
  - Added the complete declaration/method/vtable/dependency/consumer inventory, InsertSorted ordering and failure behavior, and the explicit UID00037L base-List exclusion.
  - Retained the former `List.cpp` fold only as a rejected historical assumption instead of an active blocker.
