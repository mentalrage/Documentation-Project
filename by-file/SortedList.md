*** UID:0000NU | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# SortedList

## Status

- Proposed module: `util/SortedList.cpp`, or folded into `util/List.cpp` in a compact original layout.
- Confidence: strong for class behavior, vtable/memory ownership, and `NexusTK/util/` placement; medium-high for exact standalone `SortedList.cpp` versus folded `List.cpp` split.
- Historical generated source candidate: `class_SortedList.cpp`; use only as search context, not as authority.

## File Role

`SortedList.cpp` is the likely owner of the sorted fixed-width list container that extends [UID:0000KS][List](by-file/List.md). The file should not be confused with UI list panes. Its known callers are model/container users such as [UID:0000I2][ChangeMan](by-file/ChangeMan.md) listener storage and [UID:000084][Message](by-class/Message.md) entry storage.

## Proposed Contents

- [UID:0000DF][SortedList](by-class/SortedList.md)
- the `SortedList` vtable at `0x0061ce58`
- sorted insertion and binary-search helpers at `0x004f3690` and `0x004f3780`

If the final source tree favors fewer utility files, this class can be folded into [UID:0000KS][List](by-file/List.md). The current proposed tree keeps it adjacent as `util/SortedList.cpp` because the binary has separate RTTI/vtable records and the documented helper cluster is class-local to `SortedList`.

## Evidence

- `SortedList::SortedList` constructs the same storage layout as `List`, stores a comparator at `+0x14`, and installs `SortedList` vtable.
- IDA names and RTTI place the `SortedList` vtable immediately after the `List` vtable.
- IDA confirms helper functions at `0x004f3690` and `0x004f3780`; older generated output omitted them, so the owning project docs should remain authoritative.
- IDA caller checks on 2026-05-25 show `0x004f3690` called by `ChangeMan::Register` at `0x0047ed50`, and `0x004f3780` called by `ChangeMan::UnregisterFiltered`/dispatch helpers at `0x0047ed80` and `0x0047ee20`.
- `Message::Message` constructs a `SortedList` for fixed-size message entries.

## Score Rationale

- Completion is raised to `84` because the file page now ties the source root to the class page, exact memory cluster, vtable placement, comparator layout, sorted insert/search helpers, ChangeMan caller evidence, Message construction evidence, and proposed-source-tree utility placement.
- Confidence is raised to `84` because current project documentation and recorded IDA evidence agree that this is a reusable utility container under `NexusTK/util/`; the remaining uncertainty is only whether final source keeps a standalone `SortedList.cpp` or folds it into `List.cpp`.
- Final C++ remains blank because the complete source-ready declaration, helper names, and exact folded-vs-standalone source shape are not yet at the `95/95` final-source gate.

## Cross-References

- [UID:0000DF][SortedList](by-class/SortedList.md)
- [UID:000193][0x004f3600-0x004f3a43.SortedList](by-memory/0x004f3600-0x004f3a43.SortedList.md)
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
