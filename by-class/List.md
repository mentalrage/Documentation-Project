*** UID:000079 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# List

## Status

- Confidence: strong for layout and core methods.
- Likely source file: [UID:0000KS][List](by-file/List.md)
- Constructor range: [UID:000191][0x004f3060-0x004f30d5.ListConstructor](by-memory/0x004f3060-0x004f30d5.ListConstructor.md)
- Core method range: [UID:00022S][0x004f3140-0x004f35fd.ListCoreMethods](by-memory/0x004f3140-0x004f35fd.ListCoreMethods.md)
- Current recovered source: `source-3/simroot_v2/class_List.cpp`

## Class Purpose

`List` is the shared fixed-width dynamic array container used across UI, render, archive-adjacent, map, and object systems. It inherits from `LObject`, stores an element size, grows in fixed page-size chunks, and exposes virtual element access and mutation helpers.

This is the real object constructed for the `ImageLib` resource-layout registry at object offset `+0x0c`; the earlier `ResourceLayoutStore` name is a generated semantic overlay over this generic container.

## Observed Layout

```text
0x00  vtable
+0x04  int elementSize
+0x08  int pageSize
+0x0c  int count
+0x10  void* data
```

IDA MCP decoded the `List` vtable at `0x0061ce2c` as:

| Slot | Offset | Method |
| --- | --- | --- |
| 0 | `+0x00` | `List::~List` / scalar deleting destructor |
| 1 | `+0x04` | inherited runtime/type helper at `0x004f4b10` |
| 2 | `+0x08` | inherited no-op virtual at `0x0041b6c0` |
| 3 | `+0x0c` | `List::GetData` |
| 4 | `+0x10` | `List::GetElementAt` |
| 5 | `+0x14` | `List::InsertAt` |
| 6 | `+0x18` | `List::Append` |
| 7 | `+0x1c` | `List::RemoveAt` |
| 8 | `+0x20` | `List::RemoveAll` |
| 9 | `+0x24` | `List::SwapElements` |

## Core Methods

| Method | Address | Role |
| --- | --- | --- |
| `List::List(int elementSize, int pageSize)` | `0x004f3060` | Initializes `LObject`, installs `List` vtable, zeroes count, and allocates `elementSize * pageSize` bytes. |
| `List::GetData` | `0x004f32a0` | Returns the backing buffer pointer. |
| `List::GetElementAt` | `0x004f32b0` | Returns `data + index * elementSize` when the index is valid. Index `0` is accepted when data exists. |
| `List::InsertAt` | `0x004f32e0` | Grows by page-size chunks, shifts trailing elements, increments count, and copies caller data into the inserted range. |
| `List::Append` | `0x004f33c0` | Dispatches to `InsertAt(count, countToAppend, source)`. |
| `List::RemoveAt` | `0x004f33e0` | Shifts elements down and shrinks allocation when a page becomes unused. |
| `List::RemoveAll` | `0x004f34a0` | Removes all current elements. |
| `List::SwapElements` | `0x004f34b0` | Swaps two fixed-size elements through a scratch buffer. |
| `List::Sort` | `0x004f3540` | Calls CRT `qsort` over the fixed-size element buffer. This is non-virtual. |
| `List::~List` non-deleting body | `0x004f30e0` | Shared teardown called by derived/embedded list owners; currently generated under `BlackHole`. |
| `List::~List` | `0x004f3810` | Frees the backing buffer, destroys `LObject`, and optionally deletes the object. |

## ResourceLayout Evidence

`ImageLib::ImageLib` allocates a 20-byte object and calls `List::List(elementSize=44, pageSize=10)` before storing the result at `ImageLib + 0x0c`. `ResourceLayoutTable::LoadResourceIndex` then appends a 44-byte resource-name record through vtable slot `+0x18`, and lookup paths retrieve records through slot `+0x10`.

That means the resource-layout registry should be modeled as:

```cpp
List* entryList; // elements are ResourceLayoutNameRecord, 0x2c bytes each
```

not as a distinct `ResourceLayoutStore` object with its own constructor or vtable.

## Cross-References

- [UID:0000KS][List](by-file/List.md)
- [UID:000191][0x004f3060-0x004f30d5.ListConstructor](by-memory/0x004f3060-0x004f30d5.ListConstructor.md)
- [UID:000192][0x004f30e0-0x004f3139.ListNonDeletingDestructor](by-memory/0x004f30e0-0x004f3139.ListNonDeletingDestructor.md)
- [UID:00022S][0x004f3140-0x004f35fd.ListCoreMethods](by-memory/0x004f3140-0x004f35fd.ListCoreMethods.md)
- [UID:00006E][ImageLib](by-class/ImageLib.md)
- [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md)
- [UID:0000DF][SortedList](by-class/SortedList.md)
- [UID:000065][HierList](by-class/HierList.md)
- [UID:00009Q][ObjectList](by-class/ObjectList.md)
- [UID:0001VT][ResourceLayoutNameRecord](by-type/by-struct/ResourceLayoutNameRecord.md)
- [UID:0001VU][ResourceLayoutStore](by-type/by-struct/ResourceLayoutStore.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `88/88`. Summary: the generic fixed-width dynamic array is documented with layout, vtable slots, core methods, destructor ownership, and resource-layout correction evidence, leaving only final source-level rewrite detail below full completion. Evidence: constructor/core/destructor memory pages, decoded vtable, `ImageLib` allocation/call evidence, and `ResourceLayoutStore` overlay correction.
