*** UID:0001US | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00006E | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00006E | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// [UID:0001US] no standalone layout C++ body.
// The ImageLib field layout is consumed by the ImageLib lifecycle and ResourceLayoutTable facet children; emitting a duplicate layout struct would conflict with the pending class/facet declaration route.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ImageLib Layout

## Status

- Confidence: strong for field offsets, list-backed registry mechanics, constructor source-shape mapping, and destructor use of `m_pEntryList`; medium-high overall because exact original private member spelling and the broader `ImageLib`/`ResourceLayoutTable` declaration split remain inferred.
- Owner class: [UID:00006E][ImageLib](by-class/ImageLib.md).
- Owner/emitter route: attached to [UID:00006E][ImageLib](by-class/ImageLib.md), which emits through [UID:0000K2][ImageLib](by-file/ImageLib.md). The class/file route is above the strict gate; the constructor and ordinary destructor children now carry formal C++ while this layout support page remains declaration/field documentation.
- Evidence: 2026-05-31 IDA constructor/destructor decompilation, vtable xrefs, `g_pEPFLib` storage xrefs, and function-boundary/byte-padding checks.

## Layout

```text
0x00  LObject/vtable
0x04  int m_refCount (inferred source-facing name)
0x08  int m_cacheLimit (inferred source-facing name; initialized from first callee argument)
0x0c  List* m_pEntryList (strongly supported by constructor/destructor/List evidence)
0x10  int m_maxCacheSize (inferred source-facing name; initialized to literal 1000000)
0x14  end / allocated size
```

The application call site at `0x004644e8` pushes two arguments before `ImageLib::ImageLib`: instruction order is `push 0x4e20` (`20000`), then `push 0x0f4240` (`1000000`). Because x86 stack arguments are consumed in reverse push order, callee `[ebp+8]` receives `1000000` and initializes `+0x08` / `m_cacheLimit`; callee `[ebp+0x0c]` receives `20000` and is unused in the recovered constructor body. The accepted constructor source is `ImageLib::ImageLib(int cacheLimit, int)`, preserving the binary ABI with an unnamed second `int`.

## Registry Field

Offset `+0x0c` is a 20-byte [UID:000079][List](by-class/List.md) constructed as `List::List(44, 10)`. Its rows are 44-byte [UID:0001VT][ResourceLayoutNameRecord](by-type/by-struct/ResourceLayoutNameRecord.md) entries. Current source-facing destructor C++ uses this field as `m_pEntryList`: [UID:000173][0x004d0070-0x004d011b.ImageLibDestructor](by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md) snapshots `m_pEntryList->GetCount()`, retrieves rows with `GetElementAt(index)`, frees each non-null `ResourceLayoutNameRecord::entries` pointer at row offset `+0x28`, deletes `m_pEntryList`, and stores zero back to `+0x0c`. The scalar deleting destructor repeats the same cleanup as compiler wrapper parity.

[UID:0001VU][ResourceLayoutStore](by-type/by-struct/ResourceLayoutStore.md) and [UID:0001VS][ResourceLayoutBucket](by-type/by-struct/ResourceLayoutBucket.md) are retained as provisional generated aliases over this list-backed model. The suspected custom store vtable is the generic `List` vtable at `0x0061ce2c`, not a separate proven `ImageLib` subobject vtable.

## 2026-06-14 IDA Recheck

- Live IDA MCP on `NexusTK.exe` session `a001_goal2_class_batch` reports `ImageLib::ImageLib` at `0x004cffb0` as size `0xbf`, ordinary destructor `0x004d0070` as size `0xab`, scalar deleting destructor `0x004e64a0` as size `0xd2`, and the startup allocation/call site inside `0x004639d0` as size `0x1082`.
- Disassembly at `0x004644e8` still pushes `0x4e20` and `0x0f4240` before the constructor call at `0x004644f4`, confirming the two-argument binary API.
- B001's 2026-06-27 source-quality pass resolves the stack mapping for that same call site: `[ebp+8]` is `1000000`, `[ebp+0x0c]` is `20000`, and the second argument is intentionally unnamed in the formal constructor definition because no reviewed constructor/destructor/ResourceLayout consumer uses it.
- Current constructor decompilation stores `g_pEPFLib` at `0x0067a744`, writes the `ImageLib` vtable `0x0061b654`, stores the first constructor argument at `+0x08`, clears `+0x04`, sets `+0x10` to `1000000`, and stores the `List::List(44, 10)` result at `+0x0c`.
- Current ordinary and scalar deleting destructor decompilation both reinstall vtable `0x0061b654`, iterate the list count at `list + 0x0c`, obtain rows through list virtual slot `+0x10`, free row payload pointer `row + 0x28`, destroy the list, clear `+0x0c`, clear `g_pEPFLib`, and chain to base cleanup.
- `xrefs_to 0x0061b654` reports only the constructor, ordinary destructor, and scalar deleting destructor vptr stores (`0x004d0009`, `0x004d009a`, `0x004e64d1`), keeping the layout tied to the concrete `ImageLib` class rather than the `ResourceLayoutTable` helper family.

## 2026-06-27 Destructor Field-Use Resolution

B006 MCP session `80de0a67` preserves the `+0x0c` interpretation and resolves the source use for destructor emission. The binary still reads the count directly from the `List` object's `+0x0c` field and calls the virtual element accessor through slot `+0x10`, but the source-shaped body should use `m_pEntryList->GetCount()` and `m_pEntryList->GetElementAt(index)`. The row payload field is [UID:0001VT][ResourceLayoutNameRecord](by-type/by-struct/ResourceLayoutNameRecord.md) `entries` at `+0x28`; it is caller-owned payload, not generic `List` storage. The `ResourceLayoutTable`/`recordStore` alias remains a non-virtual API/facet caveat and does not replace the `ImageLib` member storage name for this destructor.

## 2026-06-27 Constructor Field-Use Resolution

B001's accepted constructor implementation resolves the constructor-facing names/types without changing this support page's score. `+0x04` is inferred `m_refCount`; constructor EH investigation showed the cleanup thunk adjustment to `this+4` ultimately jumps to a helper that only clears `g_pEPFLib`, so no separate subobject destructor is proven there. `+0x08` is inferred `m_cacheLimit`, initialized from the first callee stack argument. `+0x0c` is strongly supported `m_pEntryList`, allocated as `new List(sizeof(ResourceLayoutNameRecord), 10)` and consumed by both the ordinary destructor and ResourceLayout method family. `+0x10` is inferred `m_maxCacheSize`, initialized to literal `1000000`.

B001 checked ResourceLayout/ImageLib consumers at `0x004d0120`, `0x004d02f0`, `0x004d0530`, `0x004d1730`, `0x004d1780`, and `0x004d17c0`; they use object `+0x0c` as the layout-entry list and do not read ImageLib object `+0x04`, `+0x08`, or `+0x10`. Other text-search hits for `[esi+8]`, `[esi+10h]`, and `[esi+0Ch]` in the surrounding range were ResourceLayout row/local/helper records unless specifically object `+0x0c`.

## Score Rationale

Completion is `86` because the object extent, singleton/vtable anchors, two-argument constructor call site, all stored fields, list element size/count, destructor row payload release, class/file route, and explicit no-standalone-layout marker are current IDA-auditable and now have constructor/destructor plus ResourceLayout child source-shape support. Confidence is `90` because the live decompiler and xref checks directly prove the field offsets and lifecycle behavior; it remains below final-audit range because exact original private member spellings and the exact `ImageLib` versus `ResourceLayoutTable` source API split are still inferred rather than symbol-proven.

## 2026-08-16 ResourceLayoutTable Facet Closure

The accepted whole-file reconstruction keeps this page as non-emitting layout evidence while centralizing the source declaration in [UID:00006E][ImageLib](by-class/ImageLib.md). The `ResourceLayoutTable` facet over the same `ImageLib` object consists of nine out-of-line methods in source order: `LoadResourceIndex`, `LookupLayoutEntry`, `CopyEntryTileContext`, `GetEntryRect`, `GetFrameSize`, `GetEntryCount`, `FindResourceIndex`, private `GetEntry`, and the constructor/destructor-backed family route documented by the owner. `GetResourceLayout(int) const` is the separate H-only inline accessor. This is an API/source-placement closure, not a second object or a layout change.

[UID:00054V][0x004d1830-0x004d1860.ResourceLayoutTableGetEntry](by-memory/0x004d1830-0x004d1860.ResourceLayoutTableGetEntry.md) proves the private row-selection path over the existing `+0x0c` `List *m_pEntryList`: it calls `GetElementAt(resourceIndex)` and returns the selected 24-byte `ResourceLayoutEntry` row at `entryIndex`. The child adds no storage, vtable slot, tail field, or score change. The constructor still creates the generic registry as `List(sizeof(ResourceLayoutNameRecord), 10)`, and the destructor still frees each row's `entries` payload before deleting the list.

## Cross-References

- [UID:0000K2][ImageLib](by-file/ImageLib.md)
- [UID:00006E][ImageLib](by-class/ImageLib.md)
- [UID:0001XR][ImageLibVtable](by-type/by-vtable/ImageLibVtable.md)
- [UID:000172][0x004cffb0-0x004d011b.ImageLibLifecycleCluster](by-memory/0x004cffb0-0x004d011b.ImageLibLifecycleCluster.md)
- [UID:0002IN][0x004cffb0-0x004d006f.ImageLibConstructor](by-memory/0x004cffb0-0x004d006f.ImageLibConstructor.md)
- [UID:000173][0x004d0070-0x004d011b.ImageLibDestructor](by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md)
- [UID:0002IO][0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor](by-memory/0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor.md)
- [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md)
- [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md)
- [UID:0001VT][ResourceLayoutNameRecord](by-type/by-struct/ResourceLayoutNameRecord.md)

## Changes

- 2026-08-16 B001 ResourceLayoutTable whole-file implementation: no score change. Recorded the centralized owner declaration, the complete nine-definition facet plus H-only `GetResourceLayout(int) const` accessor, and assigned child [UID:00054V][0x004d1830-0x004d1860.ResourceLayoutTableGetEntry](by-memory/0x004d1830-0x004d1860.ResourceLayoutTableGetEntry.md). The new child consumes the existing `+0x0c` list and 24-byte entry rows; it does not alter the exact `0x14` layout or create a standalone layout emitter.

- 2026-06-30 B011 empty-emitter family implementation:
  - Changed score from `85/89` to `86/90` and inserted the formal no-standalone-layout marker.
  - Summary/evidence: the layout is exact and consumed by ImageLib lifecycle plus ResourceLayoutTable facet children, but a duplicate layout struct would conflict with the pending class/facet declaration route. The accepted marker closes this empty emitter without inventing a source type separate from the class declaration.
- 2026-06-27 B006 destructor source-quality implementation: no score change. Added the accepted destructor source-shape detail for `+0x0c` as `m_pEntryList`, `ResourceLayoutNameRecord::entries` cleanup at `+0x28`, `delete m_pEntryList`, and nulling of the field. MCP session `80de0a67` confirms the direct field/count/slot evidence while preserving the `ResourceLayoutTable` alias caveat.
- 2026-06-27 B001 constructor source-quality implementation: no score change. Updated the field ledger with inferred `m_refCount`, inferred `m_cacheLimit`, strongly supported `m_pEntryList`, inferred `m_maxCacheSize`, the corrected caller push/callee stack mapping (`20000` pushed first but unused as `[ebp+0x0c]`; `1000000` pushed second and stored as `[ebp+8]`), and ResourceLayout consumer negative evidence showing the broader API/facet split does not block the constructor body.
- 2026-06-14 A002 score pass: raised from `82/86` to `85/89` after live IDA MCP reconfirmed the two-argument startup call site, constructor field stores, `List::List(44, 10)` registry allocation, destructor row-payload cleanup at record `+0x28`, vtable store xrefs, and the class/file emitter route. The then-open constructor C++ blockers were superseded by the 2026-06-27 B001 source-quality implementation above.
- 2026-06-06: Attached the layout to [UID:00006E][ImageLib](by-class/ImageLib.md). Scores remain `82/86`; this is a parent metadata sync based on the already-documented EPF image-library layout and the class page's `82/82` score.
- 2026-05-31 IDA-backed scoring update:
  - What existed before: `COMPLETION:0`, `CONFIDENCE:0`, and `RECONSTRUCTABLE:` blank despite detailed layout notes.
  - Changed to: `COMPLETION:82`, `CONFIDENCE:86`, and `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: IDA MCP decompilation confirms the `0x14` object layout, `+0x0c` as a `List*`, `List::List(44, 10)` registry construction, vtable storage at `0x0061b654`, and destructor iteration over 44-byte records with payload pointer at `+0x28`. Scores remain below `95` because original field names, second constructor parameter semantics, and the final `ResourceLayoutTable`/`ImageLib` source boundary are not fully closed.
