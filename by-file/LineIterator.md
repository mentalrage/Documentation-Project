*** UID:0000KQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/panels/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# LineIterator

## Status

- Confidence: medium-high for helper role and SpelledPane-local placement, low for final standalone source-file status.
- Proposed placement: local helper in [UID:0000NZ][SpelledPane](by-file/SpelledPane.md), staged under `NexusTK/ui/panels/` for reconstruction bookkeeping.
- Current generated source: `source-3/simroot_v2/class_LineIterator.cpp`
- Covered memory docs: [UID:000190][0x004f3020-0x004f3060.LineIteratorReadNextLine](by-memory/0x004f3020-0x004f3060.LineIteratorReadNextLine.md), [UID:0001HL][0x00573240-0x00573247.LineIteratorDestructor](by-memory/0x00573240-0x00573247.LineIteratorDestructor.md), [UID:0001HO][0x00573540-0x00573564.LineIteratorScalarDeletingDestructor](by-memory/0x00573540-0x00573564.LineIteratorScalarDeletingDestructor.md)
- Type/layout docs: [UID:0001UY][LineIteratorLayout](by-type/by-struct/LineIteratorLayout.md), [UID:0001XZ][LineIterator_vtable](by-type/by-vtable/LineIterator_vtable.md)

## File Role

`LineIterator` is a tiny line-scanning helper used by `SpelledPane` serialized-entry parsing. Active generated output emits only destructor support, while `source-3/simroot_v2/class_SelfSaveOKPane.cpp` and IDA decompilation show `SpelledPane::ParseAndLoadEntries` constructing a stack [UID:0001UY][LineIteratorLayout](by-type/by-struct/LineIteratorLayout.md) object with `data`, `length`, and `offset` fields before repeatedly calling [UID:000190][0x004f3020-0x004f3060.LineIteratorReadNextLine](by-memory/0x004f3020-0x004f3060.LineIteratorReadNextLine.md).

The final source probably does not need a standalone `LineIterator.cpp`; this file page is retained as a documentation bucket for the generated class artifact and should be interpreted as a local-helper record for `SpelledPane.cpp` unless later callers prove a shared text parsing utility.

2026-05-26 recheck using current `simroot_v2` and IDA MCP only: active `class_LineIterator.cpp` still emits only destructor support at `0x00573240` and `0x00573540`; `ReadNextLine` remains a separate modeled `0x40`-byte function at `0x004f3020` with only two callers, both inside `SpelledPane::ParseAndLoadEntries`.

2026-05-31 IDA MCP recheck confirms the same ownership evidence without relying on generated output: `sub_4F3020` is a `0x40`-byte helper, its only callers are the two `sub_56C0E0` call sites, `sub_56C0E0` stack-constructs the four-field iterator, and the `0x00624784` vtable is a one-slot table followed immediately by the unrelated `LOOKEXT.EPF` string at `0x00624788`.

2026-06-02 documentation pass: [UID:000078][LineIterator](by-class/LineIterator.md), [UID:000190][0x004f3020-0x004f3060.LineIteratorReadNextLine](by-memory/0x004f3020-0x004f3060.LineIteratorReadNextLine.md), [UID:0001UY][LineIteratorLayout](by-type/by-struct/LineIteratorLayout.md), and [UID:0001XZ][LineIterator_vtable](by-type/by-vtable/LineIterator_vtable.md) all agree on the 16-byte runtime object, one-slot vtable boundary, destructor support, and `SpelledPane::ParseAndLoadEntries` caller-only use. The staged path now uses `NexusTK/ui/panels/` to keep the helper near SpelledPane while still avoiding a standalone source-file claim.

## Caveats

- The generated vtable symbol at `0x00624784` has one function pointer followed immediately by unrelated wide-string bytes for `LOOKEXT.EPF`; see [UID:0001XZ][LineIterator_vtable](by-type/by-vtable/LineIterator_vtable.md). Active generated code/metadata has confused that vtable/string neighborhood.
- The `ReadNextLine` method is not emitted as an active `LineIterator` method in `simroot_v2`; IDA places it at `0x004f3020`, with only `SpelledPane::ParseAndLoadEntries` call sites currently observed.
- `class_LineIterator.meta_wave3` currently derives a 4-byte struct with only `vftptr_0x0`; the runtime layout is at least 16 bytes.
- `PROPOSED_RECONSTRUCTION_PATH` names the likely folder, not proof of an original `LineIterator.cpp` file. Rebuild should fold this helper into `SpelledPane.cpp` or an adjacent local helper unless broader call evidence appears.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `78` | The file page records role, likely local owner, staged path, exact read-line/destructor/vtable/layout docs, caller-only evidence, generated omissions, vtable/string boundary issue, and no-standalone-file caveat. Completion remains capped because it is a generated artifact bucket rather than a confirmed original source file. |
| Confidence `78` | Confidence improves because the class, memory, layout, and vtable pages all agree on behavior and SpelledPane-local usage. It remains below high confidence because the final original declaration form and whether this was local, nested, header-only, or standalone remain unresolved. |

## Cross-References

- [UID:000078][LineIterator](by-class/LineIterator.md)
- [UID:0001UY][LineIteratorLayout](by-type/by-struct/LineIteratorLayout.md)
- [UID:0001XZ][LineIterator_vtable](by-type/by-vtable/LineIterator_vtable.md)
- [UID:000190][0x004f3020-0x004f3060.LineIteratorReadNextLine](by-memory/0x004f3020-0x004f3060.LineIteratorReadNextLine.md)
- [UID:0000NZ][SpelledPane](by-file/SpelledPane.md)
- [UID:0001HA][0x0056bb20-0x0056c3f1.SpelledPane](by-memory/0x0056bb20-0x0056c3f1.SpelledPane.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:72` and `CONFIDENCE:62`.
  - Summary/evidence: tiny line-scanner role, active generated omissions, stack-layout use by `SpelledPane`, destructor support, vtable/string-neighborhood caveat, and canonical memory/type refs are documented; confidence stays low because final standalone source-file status is weak and the page mainly documents helper placement rather than a mature source module.
- 2026-05-31 score update:
  - What existed before: `COMPLETION:72` and `CONFIDENCE:62`.
  - Changed to: `COMPLETION:76` and `CONFIDENCE:70`.
  - Summary/evidence: current IDA MCP reverified `ReadNextLine` callers, stack iterator construction, destructor functions, and the one-slot vtable boundary. Confidence remains capped because this page is probably not a real standalone `LineIterator.cpp`; final placement likely belongs under or near `SpelledPane`.
- 2026-06-02 source-placement update:
  - What existed before: scored `76/70` with blank reconstruction path.
  - Changed to: scored `78/78` and staged under `NexusTK/ui/panels/`.
  - Summary/evidence: exact class/memory/layout/vtable pages now provide enough agreement to stage this as a SpelledPane-local helper record, while preserving the caveat that no standalone `LineIterator.cpp` is proven.
