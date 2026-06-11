*** UID:0001US | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:00006E | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ImageLib Layout

## Status

- Confidence: strong for field offsets and list-backed registry mechanics, medium-high overall because final source-facing field names and the unused second constructor argument remain unresolved.
- Owner class: [UID:00006E][ImageLib](by-class/ImageLib.md).
- Autogen parent: attached to [UID:00006E][ImageLib](by-class/ImageLib.md); the class scores `82/82` and this layout scores `82/86`, so both sides satisfy the 80/80 parent gate.
- Evidence: 2026-05-31 IDA constructor/destructor decompilation, vtable xrefs, `g_pEPFLib` storage xrefs, and function-boundary/byte-padding checks.

## Layout

```text
0x00  LObject/vtable
0x04  int refCountOrState
0x08  int constructorLimitOrCacheLimit
0x0c  List* resourceLayoutList
0x10  int maxCacheSize
0x14  end / allocated size
```

The application call site at `0x004644e8` pushes two arguments before `ImageLib::ImageLib`: `0x0f4240` (`1000000`) and `0x4e20` (`20000`). IDA decompilation stores the first stack argument at `+0x08`, initializes `+0x10` to `1000000`, and does not show an obvious body use of the second stack argument. Keep the two-argument API in reconstruction notes until the original parameter names are proven.

## Registry Field

Offset `+0x0c` is a 20-byte [UID:000079][List](by-class/List.md) constructed as `List::List(44, 10)`. Its rows are 44-byte [UID:0001VT][ResourceLayoutNameRecord](by-type/by-struct/ResourceLayoutNameRecord.md) entries. Each row has a payload/resource pointer at offset `+0x28`; both `ImageLib` destructor bodies release that payload before destroying the list.

[UID:0001VU][ResourceLayoutStore](by-type/by-struct/ResourceLayoutStore.md) and [UID:0001VS][ResourceLayoutBucket](by-type/by-struct/ResourceLayoutBucket.md) are retained as provisional generated aliases over this list-backed model. The suspected custom store vtable is the generic `List` vtable at `0x0061ce2c`, not a separate proven `ImageLib` subobject vtable.

## Cross-References

- [UID:0000K2][ImageLib](by-file/ImageLib.md)
- [UID:00006E][ImageLib](by-class/ImageLib.md)
- [UID:0001XR][ImageLibVtable](by-type/by-vtable/ImageLibVtable.md)
- [UID:000172][0x004cffb0-0x004e6572.ImageLib](by-memory/0x004cffb0-0x004e6572.ImageLib.md)
- [UID:0002IN][0x004cffb0-0x004d006f.ImageLibConstructor](by-memory/0x004cffb0-0x004d006f.ImageLibConstructor.md)
- [UID:000173][0x004d0070-0x004d011b.ImageLibDestructor](by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md)
- [UID:0002IO][0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor](by-memory/0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor.md)
- [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md)
- [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md)
- [UID:0001VT][ResourceLayoutNameRecord](by-type/by-struct/ResourceLayoutNameRecord.md)

## Changes

- 2026-06-06: Attached the layout to [UID:00006E][ImageLib](by-class/ImageLib.md). Scores remain `82/86`; this is a parent metadata sync based on the already-documented EPF image-library layout and the class page's `82/82` score.
- 2026-05-31 IDA-backed scoring update:
  - What existed before: `COMPLETION:0`, `CONFIDENCE:0`, and `RECONSTRUCTABLE:` blank despite detailed layout notes.
  - Changed to: `COMPLETION:82`, `CONFIDENCE:86`, and `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: IDA MCP decompilation confirms the `0x14` object layout, `+0x0c` as a `List*`, `List::List(44, 10)` registry construction, vtable storage at `0x0061b654`, and destructor iteration over 44-byte records with payload pointer at `+0x28`. Scores remain below `95` because original field names, second constructor parameter semantics, and the final `ResourceLayoutTable`/`ImageLib` source boundary are not fully closed.
