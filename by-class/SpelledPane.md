*** UID:0000DK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000NZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SpelledPane

## Status

- Confidence: strong for class identity, constructor/method island, vtable data, and shared child-pane role; medium-high for final source-file ownership.
- Likely source file: [UID:0000NZ][SpelledPane](by-file/SpelledPane.md)
- Address range: [UID:0001HA][0x0056bb20-0x0056c3f1.SpelledPane](by-memory/0x0056bb20-0x0056c3f1.SpelledPane.md)
- Current recovered file: `source-3/simroot_v2/class_SpelledPane.cpp`
- Rebuild handling: source-authored class declaration and methods, with vtables and static delimiter storage regenerated from source declarations.
- Autogen parent: [UID:0000NZ][SpelledPane](by-file/SpelledPane.md), which is `86/80` and satisfies the parent gate for this now `86/80` class page.
- Final C++ gate: keep blank until entry-record fields, base/subobject names, helper names, and declaration layout are final-source quality.

## Class Purpose

`SpelledPane` is a shared child text pane used by self-look/status views and at least one system-message pane. It is constructed with a `TextEditPane`-style base, owns a timed/grouped entry list, rebuilds display text, rejects unsupported query paths, and schedules refresh behavior.

## Ownership And Layout Evidence

| Evidence | Meaning |
| --- | --- |
| [UID:0001HA][0x0056bb20-0x0056c3f1.SpelledPane](by-memory/0x0056bb20-0x0056c3f1.SpelledPane.md) | Constructor/method aggregate for the class, now documenting boundaries, entry helpers, parser dependencies, vtable/delimiter links, and parent caveats. |
| [UID:0000NZ][SpelledPane](by-file/SpelledPane.md) | Reviewed source-file parent under `NexusTK/ui/panels/`, with generated `SelfSaveOKPane` ownership pollution called out. |
| [UID:0002UZ][0x006242c4-0x00624384.SpelledPaneVtableData](by-memory/0x006242c4-0x00624384.SpelledPaneVtableData.md) | Exact RTTI plus four `SpelledPane` vtable views and constructor/destructor-neighborhood store xrefs. |
| [UID:000284][0x0066fe44-0x0066fe4a.SpelledPaneWhitespaceDelimiter](by-memory/0x0066fe44-0x0066fe4a.SpelledPaneWhitespaceDelimiter.md) | Parser-owned UTF-16 `" \t"` delimiter used only by the serialized-entry parser. |
| [UID:00023X][0x005729e0-0x00573232.LookPanePacketAndEntryVectorHelpers](by-memory/0x005729e0-0x00573232.LookPanePacketAndEntryVectorHelpers.md) | Entry-vector insert helper callers at `0x0056bdbc` and `0x0056c26d` tie vector support back to SpelledPane entry storage. |
| [UID:000240][0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers](by-memory/0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers.md) | Holds the scalar deleting destructor and vector erase/copy helpers in a mixed look/group/spelled support island. |

The class should remain a reusable child-pane class rather than being folded into `SelfSaveOKPane`, `SelfLookPane`, or `SystemMessagePanes`. Those consumers construct or drive it, while the entry list, parser delimiter, vtable views, and vector helper callers identify a distinct `SpelledPane` owner.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | `0x0056bb20-0x0056bbdb` | Constructs the child text pane with resolution-dependent layout. |
| `AddOrUpdateEntry` provisional | `0x0056bca0-0x0056be16` | Adds or updates grouped text/value entries and rebuilds display text. Current generated owner is `SelfSaveOKPane`, but caller evidence points here. |
| `RemoveEntry` provisional | `0x0056be20-0x0056be9f` | Removes a matching grouped entry and rebuilds display text. |
| `RebuildDisplayText` provisional | `0x0056bea0-0x0056c0d7` | Formats grouped entries into the embedded text pane, using localized format string id `222` for valued rows. |
| `ParseAndLoadEntries` provisional | `0x0056c0e0-0x0056c2da` | Parses serialized entries into the same entry vector. |
| [UID:000078][LineIterator](by-class/LineIterator.md) local helper | `0x004f3020`, `0x00573240`, `0x00573540` | Stack line reader used by `ParseAndLoadEntries`; current active output only has destructor support. |
| `IsQuerySupported` | `0x0056c2e0-0x0056c2e5` | Always-false virtual gate. |
| `IsAlternateQuerySupported` | `0x0056c2f0-0x0056c2f5` | Always-false alternate virtual gate. |
| `UpdateEntriesAndScheduleRefresh` | `0x0056c300-0x0056c3f1` | Updates entry text and schedules refresh. |
| entry-vector helpers | `0x00572fd0-0x00573232`, `0x00573880-0x005738fc`, `0x00573900-0x00573962` | Internal vector insert/erase helpers for entry records; not source-facing behavior. Covered by [UID:00023X][0x005729e0-0x00573232.LookPanePacketAndEntryVectorHelpers](by-memory/0x005729e0-0x00573232.LookPanePacketAndEntryVectorHelpers.md) and [UID:000240][0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers](by-memory/0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers.md). |
| scalar deleting destructor | `0x00573820-0x00573873` | Destructor in the mixed destructor island, covered by [UID:000240][0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers](by-memory/0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers.md). |

## Evidence Notes

- Wave3 reports `SpelledPane` grade `97.5`.
- IDA confirms constructor xrefs from `SelfLookPane`, `SelfLookPane2`, and a system-message/new-system-message constructor.
- IDA caller checks on 2026-05-24 show the entry-list helpers currently emitted under `SelfSaveOKPane` are reached from self-look and system-message SpelledPane paths.
- `SpelledPane::UpdateEntriesAndScheduleRefresh` uses a subobject adjustment before calling the same rebuild helper, matching a frame-handler/timer facet inside SpelledPane rather than a separate SelfSave pane.
- [UID:000190][0x004f3020-0x004f3060.LineIteratorReadNextLine](by-memory/0x004f3020-0x004f3060.LineIteratorReadNextLine.md) is referenced in generated `ParseAndLoadEntries` source but not emitted as an active `LineIterator` method. Treat this as a generated-data gap around the local text parser.
- [UID:0002UZ][0x006242c4-0x00624384.SpelledPaneVtableData](by-memory/0x006242c4-0x00624384.SpelledPaneVtableData.md) confirms four `SpelledPane` vtable views and store xrefs, including the extra callback/facet view.
- [UID:000284][0x0066fe44-0x0066fe4a.SpelledPaneWhitespaceDelimiter](by-memory/0x0066fe44-0x0066fe4a.SpelledPaneWhitespaceDelimiter.md) confirms the parser delimiter bytes and four parser-only refs inside `0x0056c0e0-0x0056c2db`.

## Reconstruction Notes

- Recreate this as a source-level class under the [UID:0000NZ][SpelledPane](by-file/SpelledPane.md) source family unless a future file-split audit proves it was a local class in a larger look/status module.
- Regenerate vtables from the class declaration; do not hand-port [UID:0002UZ][0x006242c4-0x00624384.SpelledPaneVtableData](by-memory/0x006242c4-0x00624384.SpelledPaneVtableData.md) bytes.
- Keep the delimiter as source-declared parser data owned by `SpelledPane`.
- Leave final class C++ blank. The class identity is strong enough for parent routing, but field names, entry-record layout, exact base-class/subobject names, and final method names are not yet at the final-code threshold.

## Score Rationale

- Completion remains `86` because the class role, method inventory, helper islands, vtable data, delimiter data, generated-owner correction, and likely file parent are documented.
- Confidence is raised to `80` because the exact vtable and delimiter pages now corroborate the class identity and source ownership. It remains only medium-high because final declaration layout, field names, and original file-vs-local-class placement still need a source-quality audit.

## Cross-References

- [UID:0000NZ][SpelledPane](by-file/SpelledPane.md)
- [UID:0001Y0][LookPaneVtableFamily](by-type/by-vtable/LookPaneVtableFamily.md)
- [UID:0001HA][0x0056bb20-0x0056c3f1.SpelledPane](by-memory/0x0056bb20-0x0056c3f1.SpelledPane.md)
- [UID:0002UZ][0x006242c4-0x00624384.SpelledPaneVtableData](by-memory/0x006242c4-0x00624384.SpelledPaneVtableData.md)
- [UID:000284][0x0066fe44-0x0066fe4a.SpelledPaneWhitespaceDelimiter](by-memory/0x0066fe44-0x0066fe4a.SpelledPaneWhitespaceDelimiter.md)
- [UID:0000KQ][LineIterator](by-file/LineIterator.md)
- [UID:0000CX][SelfSaveOKPane](by-class/SelfSaveOKPane.md)
- [UID:0000CU][SelfLookPane](by-class/SelfLookPane.md)
- [UID:0000CV][SelfLookPane2](by-class/SelfLookPane2.md)
- [UID:00023X][0x005729e0-0x00573232.LookPanePacketAndEntryVectorHelpers](by-memory/0x005729e0-0x00573232.LookPanePacketAndEntryVectorHelpers.md)
- [UID:000240][0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers](by-memory/0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers.md)

## Changes

- 2026-06-07 - A007 class-parent confidence update:
  - Before: the page was `86/78`, reconstructable but unassigned, with method inventory and generated-owner caveats but no class-level vtable/delimiter dependency table or explicit parent-gate rationale.
  - Changed to: `86/80`, attached to [UID:0000NZ][SpelledPane](by-file/SpelledPane.md), added ownership/layout evidence, reconstruction notes, score rationale, and direct cross-links to the exact vtable and parser delimiter pages.
  - Evidence: UID-linked docs already prove the constructor/method aggregate, four `SpelledPane` vtable views, parser-only delimiter refs, vector-helper callers, mixed destructor island, and reviewed file parent. Final C++ remains blank because field/declaration details are still below the final-code gate.
- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `86`, confidence `78`.
- Evidence: the page documents the shared child-pane role, constructor/method/helper/destructor ranges, generated ownership corrections, caller evidence, line-iterator gap, and helper-island cross-references; confidence remains capped by final file ownership and provisional helper names.
- Before: the entry-vector helpers were listed as `0x00572fd0-0x00573231` and `0x00573900-0x00573961`, without covering the adjacent vector copy/cleanup helper at `0x00573880`.
- Changed to: the helper endpoints now follow IDA function ends, and the related insert/copy/erase helpers are cross-referenced through [UID:00023X][0x005729e0-0x00573232.LookPanePacketAndEntryVectorHelpers](by-memory/0x005729e0-0x00573232.LookPanePacketAndEntryVectorHelpers.md) and [UID:000240][0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers](by-memory/0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers.md).
- Evidence: 2026-05-28 IDA MCP shows `sub_572fd0` ends at `0x00573232`, `sub_573880` is called from that insert helper, and `sub_573900` ends at `0x00573962`.
- 2026-06-05: Marked reconstructable and left unassigned.
- Evidence: live IDA MCP `lookup_funcs` confirms the constructor, entry update/remove/rebuild/parse helpers, query gates, refresh helper, and scalar deleting destructor from `0x0056bb20` through `0x00573820`. The likely parent file meets 80/80, but this class confidence is `78`, so the parent UID stays blank.
