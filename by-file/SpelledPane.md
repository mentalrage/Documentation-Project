*** UID:0000NZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/panels/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# SpelledPane

## Status

- Confidence: strong for constructor/method behavior; medium for final original source-file ownership.
- Proposed module: `ui/panels/SpelledPane.cpp`, or a local class in a broader look/status pane source after final split review.
- Current recovered source: `class_SpelledPane.cpp`
- Main address doc: [UID:0001HA][0x0056bb20-0x0056c3f1.SpelledPane](by-memory/0x0056bb20-0x0056c3f1.SpelledPane.md)
- Vtable/layout anchor: [UID:0001Y0][LookPaneVtableFamily](by-type/by-vtable/LookPaneVtableFamily.md)

## File Role

`SpelledPane` is a reusable child text pane used by self-look/status UI and at least one system-message/new-system-message construction path. It wraps `TextEditPane`-style behavior, owns a timed/grouped entry list, rebuilds display text from that list, rejects unsupported query paths through tiny vtable gates, and schedules refresh callbacks.

IDA confirms four `SpelledPane` vtable views at `0x006242c8`, `0x00624340`, `0x00624370`, and `0x0062437c`. The fourth view matches the extra frame-handler-style callback path around `0x0056c300`; keep it as layout evidence until the final declaration is reconstructed.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `SpelledPane` constructor | `0x0056bb20-0x0056bbdb` | Constructs the child text pane with resolution-dependent layout and `TextEditPane` base setup. |
| entry add/update helper | `0x0056bca0-0x0056be16` | Inserts or updates grouped `{text,value,category}` style entries, then rebuilds display text. Current generated owner is polluted as `SelfSaveOKPane`. |
| entry remove helper | `0x0056be20-0x0056be9f` | Removes a matching entry and rebuilds display text. Current generated owner is polluted as `SelfSaveOKPane`. |
| display rebuild helper | `0x0056bea0-0x0056c0d7` | Formats grouped entries, inserts a separator between groups, and writes the text into the embedded text pane. |
| serialized entry parser | `0x0056c0e0-0x0056c2da` | Parses serialized entries into the same entry vector and rebuilds display text. |
| [UID:0000KQ][LineIterator](by-file/LineIterator.md) local helper | `0x004f3020`, `0x00573240`, `0x00573540` | Stack line reader used by serialized entry parsing; active generated output only emits destructor support and an incomplete 4-byte layout. |
| `IsQuerySupported` / `IsAlternateQuerySupported` | `0x0056c2e0`, `0x0056c2f0` | Tiny always-false virtual gates. |
| `UpdateEntriesAndScheduleRefresh` | `0x0056c300-0x0056c3f1` | Updates entry text/state and schedules pane refresh behavior. |
| entry-vector insert/erase helpers | `0x00572fd0-0x00573232`, `0x00573880-0x005738fc`, `0x00573900-0x00573962` | Non-source-facing vector machinery used by the entry add/remove/parse helpers; documented in [UID:00023X][0x005729e0-0x00573232.LookPanePacketAndEntryVectorHelpers](by-memory/0x005729e0-0x00573232.LookPanePacketAndEntryVectorHelpers.md) and [UID:000240][0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers](by-memory/0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers.md). |
| scalar deleting destructor | `0x00573820-0x00573873` | Destructor body in the mixed self-look destructor/thunk island; covered by [UID:000240][0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers](by-memory/0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers.md). |

## Evidence Notes

- Wave3 reports `SpelledPane` grade `97.5`.
- IDA confirms constructor xrefs from `SelfLookPane::SelfLookPane` at `0x005656cc`, `SelfLookPane2::SelfLookPane2` at `0x0056ff1e`, and a system-message/new-system-message constructor at `0x005886bd`.
- The extra `0x005886bd` xref means `SpelledPane` is shared UI infrastructure, not exclusively self-look-local.
- IDA caller checks on 2026-05-24 show `0x0056bca0`, `0x0056be20`, and `0x0056c0e0` are called by self-look and system-message paths, while `0x0056c300` adjusts from a frame-handler subobject back to the owner before calling the same display rebuild helper. That supports SpelledPane entry-storage ownership over the current generated `SelfSaveOKPane` label.
- `source-3/simroot_v2/class_SelfSaveOKPane.cpp` currently emits the entry helpers and broad text-edit methods under `SelfSaveOKPane`; treat that as generated-data pollution.
- The same generated file constructs a stack [UID:0000KQ][LineIterator](by-file/LineIterator.md) in `ParseAndLoadEntries`. [UID:000190][0x004f3020-0x004f3060.LineIteratorReadNextLine](by-memory/0x004f3020-0x004f3060.LineIteratorReadNextLine.md) is not emitted as an active `LineIterator` method, but IDA confirms it is called only from this parser in the current database. The 16-byte layout is documented as [UID:0001UY][LineIteratorLayout](by-type/by-struct/LineIteratorLayout.md), and the one-slot vtable/string boundary is documented as [UID:0001XZ][LineIterator_vtable](by-type/by-vtable/LineIterator_vtable.md).

## Cross-References

- [UID:0000DK][SpelledPane](by-class/SpelledPane.md)
- [UID:0001Y0][LookPaneVtableFamily](by-type/by-vtable/LookPaneVtableFamily.md)
- [UID:0001HA][0x0056bb20-0x0056c3f1.SpelledPane](by-memory/0x0056bb20-0x0056c3f1.SpelledPane.md)
- [UID:0000KQ][LineIterator](by-file/LineIterator.md)
- [UID:0001UY][LineIteratorLayout](by-type/by-struct/LineIteratorLayout.md)
- [UID:0001XZ][LineIterator_vtable](by-type/by-vtable/LineIterator_vtable.md)
- [UID:0000NN][SelfSaveOKPane](by-file/SelfSaveOKPane.md)
- [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md)
- [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)
- [UID:00023X][0x005729e0-0x00573232.LookPanePacketAndEntryVectorHelpers](by-memory/0x005729e0-0x00573232.LookPanePacketAndEntryVectorHelpers.md)
- [UID:000240][0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers](by-memory/0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers.md)

## Changes

- 2026-06-05: Assigned projected reconstruction folder.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank, so the by-file row remained a generated-root coverage error.
  - After: set the folder to `NexusTK/ui/panels/`.
  - Evidence: live IDA MCP lookup confirms the documented `SpelledPane` constructor anchor at `0x0056bb20`; proposed-source-tree places the reusable child text pane in the self-look/status panel family while preserving the documented final split caveat.
- Before: the entry-vector helper summary omitted the `0x00573880` helper and used older end addresses for the insert/erase helpers.
- Changed to: the helper list now follows the IDA-confirmed ranges and links to the new by-memory pages that split the former unknown coverage gaps.
- Evidence: 2026-05-28 IDA MCP disassembly and xref sweep over `0x005729c3-0x005739a0`.
- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `86` and confidence to `80`.
  - Evidence: document covers role, proposed contents, vtable/layout anchor, IDA caller evidence, generated-owner pollution, LineIterator dependency, helper-vector correction, and cross-references; confidence remains capped by final original source-file ownership.
