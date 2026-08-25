*** UID:0001VU | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ResourceLayoutStore

## Status

- Entity kind: provisional generated alias over [UID:000079][List](by-class/List.md)
- Confidence: strong that the storage is `List`; low that a distinct `ResourceLayoutStore` class existed.
- Proposed owner: [UID:0000K2][ImageLib](by-file/ImageLib.md) / [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md)
- Evidence basis: IDA MCP decompilation of `ImageLib::ImageLib`, decoded `List` vtable slots, and generated `class_ResourceLayoutTable.cpp`.

## Role

`ResourceLayoutStore` should currently be treated as a documentation alias for the `List*` reachable from the `ImageLib` / `ResourceLayoutTable` object at offset `+0x0c`. It stores 44-byte [UID:0001VT][ResourceLayoutNameRecord](by-type/by-struct/ResourceLayoutNameRecord.md) rows.

IDA MCP decompilation of `ImageLib::ImageLib` at `0x004cffb0` proves the field is initialized as:

```text
List::List(elementSize = 44, pageSize = 10)
```

2026-06-19 B008 source-quality reanalysis of [UID:000191][0x004f3060-0x004f30d5.ListConstructor](by-memory/0x004f3060-0x004f30d5.ListConstructor.md) strengthens this conclusion. Raw caller evidence shows `List::List` has 61 generic call sites across UI, resource, text, hierarchy, map/object, and chat systems; `ImageLib` is only one consumer with the specific argument pair `List(44, 10)`. There is no separate `ResourceLayoutStore` vtable, and the vtable at `0x0061ce2c` is the generic `List` table.

The virtual calls made by the layout methods resolve to the generic `List` vtable:

- vtable `+0x10`: `List::GetElementAt`
- vtable `+0x18`: `List::Append`

The earlier generated names such as `GetNameRecord`, `RegisterBucket`, and `GetBucket` are semantic overlays for those generic list operations, not evidence of a separate vtable.

## Observed Storage Layout

The actual object layout is [UID:000079][List](by-class/List.md):

```text
+0x00  vtable
+0x04  elementSize = 44
+0x08  pageSize = 10
+0x0c  count
+0x10  ResourceLayoutNameRecord* data
```

`FindResourceIndex` reads `count` from `List + 0x0c`, obtains the first element with `List::GetElementAt(0)`, then scans records in 44-byte strides using `wcscmp`.

## Reconstruction Guidance

Do not create a standalone `ResourceLayoutStore` class in reconstructed source from current evidence. Prefer one of:

```cpp
List* m_entryList;
// or, in documentation/comments only:
List<ResourceLayoutNameRecord>* m_entryList;
```

Keep this file as a cross-reference target because older notes and generated overlays still use `ResourceLayoutStore`.

Do not emit `ResourceLayoutStore::ResourceLayoutStore` or specialize [UID:000191][0x004f3060-0x004f30d5.ListConstructor](by-memory/0x004f3060-0x004f30d5.ListConstructor.md) for resource-layout behavior. The source route for the constructor remains [UID:000079][List](by-class/List.md) through [UID:0000KS][List](by-file/List.md); ResourceLayout code should document that the registry field is a generic `List` of 44-byte [UID:0001VT][ResourceLayoutNameRecord](by-type/by-struct/ResourceLayoutNameRecord.md) rows.

## Open Questions

- Decide whether final reconstructed source should use a typed wrapper/helper around `List` for readability, even if the original binary used the generic container directly.
- Confirm the final names of the 44-byte [UID:0001VT][ResourceLayoutNameRecord](by-type/by-struct/ResourceLayoutNameRecord.md) fields.

These questions do not reopen standalone ownership for this page. A readability wrapper would be a source-level helper choice around generic `List` storage, not proof that a separate binary-backed `ResourceLayoutStore` object or constructor existed.

## Cross-References

- [UID:000079][List](by-class/List.md)
- [UID:0000KS][List](by-file/List.md)
- [UID:000191][0x004f3060-0x004f30d5.ListConstructor](by-memory/0x004f3060-0x004f30d5.ListConstructor.md)
- [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md)
- [UID:00006E][ImageLib](by-class/ImageLib.md)
- [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md)
- [UID:0001VS][ResourceLayoutBucket](by-type/by-struct/ResourceLayoutBucket.md)
- [UID:0001VT][ResourceLayoutNameRecord](by-type/by-struct/ResourceLayoutNameRecord.md)
- [UID:000174][0x004d0120-0x004d1860.ResourceLayoutTable](by-memory/0x004d0120-0x004d1860.ResourceLayoutTable.md)

## Changes

- 2026-06-21 B008 Rule 26 source-quality incorporation:
  - Added B008's generic `List` constructor caller evidence and explicit rejection of `ResourceLayoutStore::ResourceLayoutStore`.
  - Clarified that future typed-wrapper discussion is only a readability/source-shape question and does not make this alias reconstructable as an independent class.

- 2026-05-31: Scored and marked as a stale standalone reconstruction target.
  - Before: metadata was `0/0` with blank reconstruction state even though the page said not to create a standalone `ResourceLayoutStore` class.
  - After: set completion/confidence to `84/90` and `RECONSTRUCTABLE:FALSE`; keep the page as a search/cross-reference alias for older generated output.
  - Evidence: IDA MCP decompilation confirms the field is a generic `List` constructed with element size `44` and page size `10`; vtable xrefs at `0x0061ce2c` are generic `List` constructor/destructor/method code, not a custom store class.
