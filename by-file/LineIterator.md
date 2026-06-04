*** UID:0000KQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/panels/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# LineIterator

## Status

- Confidence: strong for helper behavior, stack layout, caller ownership, and vtable boundary; medium for final standalone source-file status.
- Proposed placement: local helper in [UID:0000NZ][SpelledPane](by-file/SpelledPane.md), staged under `NexusTK/ui/panels/` for reconstruction bookkeeping.
- Covered memory docs: [UID:000190][0x004f3020-0x004f3060.LineIteratorReadNextLine](by-memory/0x004f3020-0x004f3060.LineIteratorReadNextLine.md), [UID:0001HL][0x00573240-0x00573247.LineIteratorDestructor](by-memory/0x00573240-0x00573247.LineIteratorDestructor.md), [UID:0001HO][0x00573540-0x00573564.LineIteratorScalarDeletingDestructor](by-memory/0x00573540-0x00573564.LineIteratorScalarDeletingDestructor.md)
- Type/layout docs: [UID:0001UY][LineIteratorLayout](by-type/by-struct/LineIteratorLayout.md), [UID:0001XZ][LineIterator_vtable](by-type/by-vtable/LineIterator_vtable.md)

## File Role

`LineIterator` is a tiny line-scanning helper used by `SpelledPane` serialized-entry parsing. Live IDA decompilation shows `sub_56C0E0` constructing a stack [UID:0001UY][LineIteratorLayout](by-type/by-struct/LineIteratorLayout.md) object with a vtable, `data`, `length`, and zero `offset` fields before repeatedly calling [UID:000190][0x004f3020-0x004f3060.LineIteratorReadNextLine](by-memory/0x004f3020-0x004f3060.LineIteratorReadNextLine.md).

The final source probably does not need a standalone `LineIterator.cpp`; this file page is retained as a documentation bucket for the class/helper artifact and should be interpreted as a local-helper record for `SpelledPane.cpp` unless later callers prove a shared text parsing utility.

2026-05-31 IDA MCP recheck confirms the same ownership evidence: `sub_4F3020` is a `0x40`-byte helper, its only callers are the two `sub_56C0E0` call sites, `sub_56C0E0` stack-constructs the four-field iterator, and the `0x00624784` vtable is a one-slot table followed immediately by the unrelated `LOOKEXT.EPF` string at `0x00624788`.

2026-06-02 documentation pass: [UID:000078][LineIterator](by-class/LineIterator.md), [UID:000190][0x004f3020-0x004f3060.LineIteratorReadNextLine](by-memory/0x004f3020-0x004f3060.LineIteratorReadNextLine.md), [UID:0001UY][LineIteratorLayout](by-type/by-struct/LineIteratorLayout.md), and [UID:0001XZ][LineIterator_vtable](by-type/by-vtable/LineIterator_vtable.md) all agree on the 16-byte runtime object, one-slot vtable boundary, destructor support, and `SpelledPane::ParseAndLoadEntries` caller-only use. The staged path now uses `NexusTK/ui/panels/` to keep the helper near SpelledPane while still avoiding a standalone source-file claim.

2026-06-04 live IDA MCP recheck: `sub_4F3020` spans `0x004f3020-0x004f3060`, `sub_56C0E0` spans `0x0056c0e0-0x0056c2db`, `sub_573240` spans `0x00573240-0x00573247`, and `sub_573540` spans `0x00573540-0x00573564`. `CodeRefsTo(0x004f3020)` returns only `0x0056c15b` and `0x0056c285`, both in `sub_56C0E0`; disassembly at `0x0056c13c-0x0056c15b` writes the vtable/data/length/offset stack object before the first call. Data at `0x00624780-0x00624788` is RTTI plus one vtable slot, `0x00624784 -> 0x00573540`, and `0x00624788` is the adjacent `LOOKEXT.EPF` string.

## Caveats

- The IDA vtable symbol at `0x00624784` has one function pointer followed immediately by unrelated wide-string bytes for `LOOKEXT.EPF`; see [UID:0001XZ][LineIterator_vtable](by-type/by-vtable/LineIterator_vtable.md). Treat `0x00624788` as string data, not a second `LineIterator` slot.
- The `ReadNextLine` method is not a virtual slot. IDA places it at `0x004f3020`, with only `SpelledPane::ParseAndLoadEntries` call sites currently observed.
- `LineIterator` ownership is inferred from stack construction, matching field use, destructor stores, and vtable data. The exact original declaration form remains unresolved.
- `PROPOSED_RECONSTRUCTION_PATH` names the likely folder, not proof of an original `LineIterator.cpp` file. Rebuild should fold this helper into `SpelledPane.cpp` or an adjacent local helper unless broader call evidence appears.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `84` | The file page now records role, likely local owner, staged path, exact read-line/destructor/vtable/layout docs, caller-only evidence, vtable/string boundary issue, parent-ready child docs, and no-standalone-file caveat. Completion remains capped because this is still a helper bucket rather than a confirmed original source file. |
| Confidence `84` | Confidence improves because live 2026-06-04 IDA evidence reconfirms all function ranges, two-only caller set, stack field initialization, destructor behavior, and one-slot vtable boundary. It remains below high-final confidence because the original declaration form and whether this was local, nested, header-only, or standalone remain unresolved. |

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
- 2026-06-04 IDA evidence and parent-readiness update:
  - What existed before: scored `78/78`, with stale non-IDA caveats and unassigned child docs.
  - Changed to: scored `84/84`.
  - Summary/evidence: live IDA MCP reverified exact function ranges, two-only `sub_4F3020` caller set, `sub_56C0E0` stack construction, destructor behavior, `0x00624784 -> 0x00573540`, and the `0x00624788` `LOOKEXT.EPF` boundary. This justifies moving the helper family out of the lowest queue tier and attaching reconstructable children to this parent, while still withholding final C++ because the original declaration/source placement is not 95+.
