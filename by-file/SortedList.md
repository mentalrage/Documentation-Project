*** UID:0000NU | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# SortedList

## Status

- Proposed module: `util/SortedList.cpp`, or folded into `util/List.cpp` in a compact original layout.
- Confidence: strong for class behavior, medium for exact file split.
- Current recovered source: `source-3/simroot_v2/class_SortedList.cpp`

## File Role

`SortedList.cpp` is the likely owner of the sorted fixed-width list container that extends [UID:0000KS][List](by-file/List.md). The file should not be confused with UI list panes. Its known callers are model/container users such as [UID:0000I2][ChangeMan](by-file/ChangeMan.md) listener storage and [UID:000084][Message](by-class/Message.md) entry storage.

## Proposed Contents

- [UID:0000DF][SortedList](by-class/SortedList.md)
- the `SortedList` vtable at `0x0061ce58`
- sorted insertion and binary-search helpers at `0x004f3690` and `0x004f3780`

If the final source tree favors fewer utility files, this class can be folded into [UID:0000KS][List](by-file/List.md). The current proposed tree keeps it adjacent as `util/SortedList.cpp` because the binary has separate RTTI/vtable records and Wave2 import provenance uses `SortedList.cpp`.

## Evidence

- `SortedList::SortedList` constructs the same storage layout as `List`, stores a comparator at `+0x14`, and installs `SortedList` vtable.
- IDA names and RTTI place the `SortedList` vtable immediately after the `List` vtable.
- IDA confirms omitted helper functions at `0x004f3690` and `0x004f3780`; active Wave3 output does not currently include them.
- IDA caller checks on 2026-05-25 show `0x004f3690` called by `ChangeMan::Register` at `0x0047ed50`, and `0x004f3780` called by `ChangeMan::UnregisterFiltered`/dispatch helpers at `0x0047ed80` and `0x0047ee20`.
- `Message::Message` constructs a `SortedList` for fixed-size message entries.

## Cross-References

- [UID:0000DF][SortedList](by-class/SortedList.md)
- [UID:000193][0x004f3600-0x004f3a43.SortedList](by-memory/0x004f3600-0x004f3a43.SortedList.md)
- [UID:0000KS][List](by-file/List.md)
- [UID:000079][List](by-class/List.md)
- [UID:0000I2][ChangeMan](by-file/ChangeMan.md)
- [UID:0000ZX][0x0047ed50-0x0047ee18.ChangeManRegistrationMethods](by-memory/0x0047ed50-0x0047ee18.ChangeManRegistrationMethods.md)
- [UID:000084][Message](by-class/Message.md)

## Changes

- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `80` and confidence to `78`.
  - Evidence: document covers utility role, proposed contents, vtable/comparator behavior, omitted helper evidence, caller checks, List relationship, and cross-references; confidence remains limited by the final `SortedList.cpp` vs `List.cpp` split.
