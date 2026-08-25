*** UID:0000KQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NONE" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# LineIterator

## Status

- Confidence: very strong for helper behavior, stack layout, class/source ownership, compiler split, and vtable boundary; high for rejecting a standalone source file.
- Current disposition: reviewed non-source historical index with path/owner `NONE`. The complete local helper emits through [UID:0000NZ][SpelledPane](by-file/SpelledPane.md).
- Covered memory docs: [UID:000190][0x004f3020-0x004f3060.LineIteratorReadNextLine](by-memory/0x004f3020-0x004f3060.LineIteratorReadNextLine.md), [UID:0001HL][0x00573240-0x00573247.LineIteratorDestructor](by-memory/0x00573240-0x00573247.LineIteratorDestructor.md), [UID:0001HO][0x00573540-0x00573564.LineIteratorScalarDeletingDestructor](by-memory/0x00573540-0x00573564.LineIteratorScalarDeletingDestructor.md), [UID:00038W][0x00624780-0x00624788.LineIteratorVtableData](by-memory/0x00624780-0x00624788.LineIteratorVtableData.md)
- Type/layout docs: [UID:0001UY][LineIteratorLayout](by-type/by-struct/LineIteratorLayout.md), [UID:0001XZ][LineIterator_vtable](by-type/by-vtable/LineIterator_vtable.md)

## File Role

`LineIterator` is a tiny line-scanning helper used by `SpelledPane` serialized-entry parsing. Live IDA decompilation shows `sub_56C0E0` constructing a stack [UID:0001UY][LineIteratorLayout](by-type/by-struct/LineIteratorLayout.md) object with a vtable, `data`, `length`, and zero `offset` fields before repeatedly calling [UID:000190][0x004f3020-0x004f3060.LineIteratorReadNextLine](by-memory/0x004f3020-0x004f3060.LineIteratorReadNextLine.md).

The reconstructed source does not need a standalone `LineIterator.cpp`. This page is retained as the complete historical family index, while source emits as a file-private UID000078 helper through `SpelledPane.cpp`. No later caller, allocation, registration, constructor, or static-state evidence supports a shared translation unit.

2026-07-07 B011 callback: UID000190 now emits first-draft `LineIterator::ReadNextLine` C++ through [UID:000078][LineIterator](by-class/LineIterator.md), while this by-file page remains the reconstruction bucket under `NexusTK/ui/panels/`. The accepted evidence does not prove an original standalone `LineIterator.cpp`; it proves a class-shaped helper used only by [UID:0000NZ][SpelledPane](by-file/SpelledPane.md) parsing.

2026-05-31 IDA MCP recheck confirms the same ownership evidence: `sub_4F3020` is a `0x40`-byte helper, its only callers are the two `sub_56C0E0` call sites, `sub_56C0E0` stack-constructs the four-field iterator, and the `0x00624784` vtable is a one-slot table followed immediately by the unrelated `LOOKEXT.EPF` string at `0x00624788`.

2026-06-02 documentation pass: [UID:000078][LineIterator](by-class/LineIterator.md), [UID:000190][0x004f3020-0x004f3060.LineIteratorReadNextLine](by-memory/0x004f3020-0x004f3060.LineIteratorReadNextLine.md), [UID:0001UY][LineIteratorLayout](by-type/by-struct/LineIteratorLayout.md), and [UID:0001XZ][LineIterator_vtable](by-type/by-vtable/LineIterator_vtable.md) all agree on the 16-byte runtime object, one-slot vtable boundary, destructor support, and `SpelledPane::ParseAndLoadEntries` caller-only use. The staged path now uses `NexusTK/ui/panels/` to keep the helper near SpelledPane while still avoiding a standalone source-file claim.

2026-06-04 live IDA MCP recheck: `sub_4F3020` spans `0x004f3020-0x004f3060`, `sub_56C0E0` spans `0x0056c0e0-0x0056c2db`, `sub_573240` spans `0x00573240-0x00573247`, and `sub_573540` spans `0x00573540-0x00573564`. `CodeRefsTo(0x004f3020)` returns only `0x0056c15b` and `0x0056c285`, both in `sub_56C0E0`; disassembly at `0x0056c13c-0x0056c15b` writes the vtable/data/length/offset stack object before the first call. Data at `0x00624780-0x00624788` is RTTI plus one vtable slot, `0x00624784 -> 0x00573540`, and `0x00624788` is the adjacent `LOOKEXT.EPF` string.

2026-06-12 Agent-A004 Batch 272 live IDA MCP recheck: `idb_meta` verified the same `NexusTK.exe` md5 `4247e04e20b65d6414c7238aa8ff5515`; `lookup_funcs` reconfirmed `sub_4F3020` as `0x40` / 64 bytes, `sub_56C0E0` as `0x1fb` / 507 bytes, `sub_573240` as `0x7` / 7 bytes, and `sub_573540` as `0x24` / 36 bytes (sizes Verified with int_convert.py). The vtable slot at `0x00624784` still points to `0x00573540`, the only `ReadNextLine` callers remain the two `sub_56C0E0` call sites, and `0x00624788` decodes as UTF-16 `LOOKEXT.EPF`. This clears the strict parent gate for the LineIterator class and vtable child while retaining the local-helper placement caveat.

## Caveats

- The IDA vtable symbol at `0x00624784` has one function pointer followed immediately by unrelated wide-string bytes for `LOOKEXT.EPF`; see [UID:0001XZ][LineIterator_vtable](by-type/by-vtable/LineIterator_vtable.md). Treat `0x00624788` as string data, not a second `LineIterator` slot.
- The `ReadNextLine` method is not a virtual slot. IDA places it at `0x004f3020`, with only `SpelledPane::ParseAndLoadEntries` call sites currently observed.
- LineIterator class ownership is proven by stack construction, matching field use, destructor stores, root RTTI, and vtable data. Exact private-header versus source-local token placement remains inferred.
- `PROPOSED_RECONSTRUCTION_PATH:"NONE"` records the rejected standalone route. UID000078 and its source-bearing children emit through SpelledPane; this index does not generate a second file.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `92` | The page preserves the complete helper family, exact ranges, source/compiler decomposition, layout/vtable/RTTI evidence, two-only caller route, rejected standalone responsibility, and current SpelledPane emission route. It is complete as a non-source historical index. |
| Confidence `94` | Fresh target-specific evidence resolves class ownership and rejects standalone translation-unit emission. Exact private-header versus source-local spelling remains the only material placement cap. |

## Cross-References

- [UID:000078][LineIterator](by-class/LineIterator.md)
- [UID:0001UY][LineIteratorLayout](by-type/by-struct/LineIteratorLayout.md)
- [UID:0001XZ][LineIterator_vtable](by-type/by-vtable/LineIterator_vtable.md)
- [UID:000190][0x004f3020-0x004f3060.LineIteratorReadNextLine](by-memory/0x004f3020-0x004f3060.LineIteratorReadNextLine.md)
- [UID:00038W][0x00624780-0x00624788.LineIteratorVtableData](by-memory/0x00624780-0x00624788.LineIteratorVtableData.md)
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
- 2026-06-12 Agent-A004 Batch 272 parent-gate update:
  - What existed before: scored `84/84`, below the current strict direct-parent gate for newly routing [UID:00038W][0x00624780-0x00624788.LineIteratorVtableData](by-memory/0x00624780-0x00624788.LineIteratorVtableData.md).
  - Changed to: scored `86/86` with the exact vtable-data child added to the covered memory docs.
  - Summary/evidence: live IDA MCP reverified the same function ranges, caller-only `ReadNextLine` use, vtable/stack-construction/destructor xrefs, and byte-verified `LOOKEXT.EPF` boundary; the unresolved standalone-source question remains documented as the reason scores stay below final-audit levels.
- 2026-07-07 Agent-B011 UID000190 callback:
  - What existed before: the page described UID000190 as a helper bucket member without target-specific active method C++.
  - Changed to: documented that UID000190 now emits first-draft `LineIterator::ReadNextLine` C++ through [UID:000078][LineIterator](by-class/LineIterator.md), while this file page remains a `NexusTK/ui/panels/` reconstruction bucket rather than proof of an original standalone source file.
  - Summary/evidence: accepted B011 report rechecked MCP session `43ccf853`, exact `0x004f3020-0x004f3060` body, two parser callers, stack-object setup, StringBase dependency, and rejected standalone/source-owner alternatives.

## 2026-07-15 B003 UID0001HL Historical-Index Callback

### Complete family inventory

| UID / range | Current source/compiler disposition |
| --- | --- |
| UID000078 class | Sole complete source declaration; inline constructor and explicit inline empty virtual destructor; emits through UID0000NZ at position 10. |
| UID000190 `[0x004f3020,0x004f3060)` | Human out-of-line `ReadNextLine`, position 20, exact body unchanged. |
| UID0001HL `[0x00573240,0x00573247)` | Live EH-only complete-object destructor materialization, covered marker at position 30. |
| UID0001HO `[0x00573540,0x00573564)` | Compiler scalar-deleting wrapper, false/non-emitting. |
| UID0001UY layout | Non-emitting exact 16-byte support owned by UID000078. |
| UID0001XZ vtable | Non-emitting compiler ABI inventory owned by UID000078. |
| UID00038W `[0x00624780,0x00624788)` | Exact RTTI plus one-slot data interval, covered marker at position 40. |

### Rejected standalone route

- UID000190 has exactly two callers, both in `SpelledPane::ParseAndLoadEntries`; parser code performs the only observed construction. Vtable-address refs are limited to that construction and the two destructor artifacts.
- No heap construction, constructor function, external method caller, registration table, target VA/RVA pointer, shared static state, or independent module responsibility exists.
- A tiny private adjacent header cannot be excluded, but it would still belong to the SpelledPane source family and does not justify a standalone generated root.
- Path/owner `NONE` is therefore an evidence-backed source disposition, not a deletion of the documented family. All exact behavior, ranges, bytes, callers, layout, RTTI/vtable boundaries, history, and rejected alternatives remain on this index and linked pages.

### Source/compiler boundary and historical correction

- Human source is the UID000078 class plus UID000190 body. UID0001HL and UID00038W carry covered markers for retained/generated binary ranges. UID0001HO, UID0001UY, and UID0001XZ are non-emitting compiler/support pages.
- Do not create another class/struct declaration, scalar-deleting method, explicit vptr, raw RTTI/vtable arrays, operator-delete code, EH/cookie scaffolding, raw addresses, or decompiler labels in a LineIterator translation unit.
- Historical staged `NexusTK/ui/panels/` routing and unresolved standalone wording above remain useful provenance but are superseded by the direct source-quality audit. Current score `92/94` measures completion of this reviewed non-source index.
