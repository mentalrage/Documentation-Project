*** UID:0000KS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# List

## Status

- Proposed module: `util/List.cpp`
- Confidence: strong for `List` behavior, medium for exact original folder.
- Current recovered source: `source-3/simroot_v2/class_List.cpp`
- Related recovered source: `source-3/simroot_v2/class_SortedList.cpp`
- Related adjacent module: [UID:0000JV][HierList](by-file/HierList.md)

## File Role

`List.cpp` is the likely shared container implementation file for the client's fixed-width dynamic array container. The class is generic infrastructure, not a UI-list widget: it is constructed by render/resource code, UI list panes, object-list systems, map/object tables, and other subsystems.

The original project may have used a flat Visual C++ source tree, but in the current reconstructed layout this belongs under `util/` beside other cross-cutting support code. [UID:0000NU][SortedList](by-file/SortedList.md) is close enough that it may have lived in the same source file or an adjacent `SortedList.cpp`. [UID:0000JV][HierList](by-file/HierList.md) is a separate tree-aware container built on `List` and should remain adjacent utility code rather than being absorbed by `Layer.cpp`. Broader collection placement is tracked in [UID:0001QA][client_containers](by-meta/client_containers.md).

## Contained Types

Likely contents:

- [UID:000079][List](by-class/List.md)
- [UID:0000DF][SortedList](by-class/SortedList.md) or an adjacent `SortedList.cpp` if later source-layout evidence favors a split
- the `List` vtable and fixed-width array helpers

`ListPane`, `SimpleListPane`, and the many `*ListPane` UI classes are consumers or subclasses of UI pane code, not owners of this generic container implementation.

## Evidence

- `List::List` at `0x004f3060` has broad fan-in across render, UI, map, object, and resource-loading code.
- `0x004f30e0` is a non-deleting list destructor body currently emitted under `BlackHole`, but its body and caller set show shared `List` teardown.
- [UID:00022S][0x004f3140-0x004f35fd.ListCoreMethods](by-memory/0x004f3140-0x004f35fd.ListCoreMethods.md) contains the main dynamic-array implementation bodies for assignment, resize, access, insert/remove, clear, swap, sort, reserve, and page-count helpers.
- IDA MCP decoded the vtable at `0x0061ce2c` as the generic `List` virtual surface, with `SortedList` RTTI immediately after the `List` vtable entries.
- `ImageLib::ImageLib` constructs a `List` with 44-byte elements for the EPF/EPD resource-layout registry; this confirms render code depends on the generic utility container rather than owning a custom store class.
- `SortedList::SortedList` constructs the same base layout, then switches to the `SortedList` vtable.
- `HierList::HierList` calls `List::List(elementSize + 11, 32)` and installs a tree-aware vtable, proving it is derived utility container code rather than a `Layer`-owned private helper.
- [UID:0000M4][ObjectList](by-file/ObjectList.md) allocates many `List` instances for map object row buckets and global object tiers. It is a consumer of this generic container, not an owner of `List` itself.
- 2026-05-31 IDA MCP recheck: `List::List` remains `0x004f3060-0x004f30d5` with 61 modeled code xrefs, `List` non-deleting destructor remains `0x004f30e0-0x004f3139` with 13 modeled code xrefs, and the first core-method body remains `0x004f3140-0x004f31cc`. IDA also still shows `SortedList` construction at `0x004f3600-0x004f3681` and the `List` vtable at `0x0061ce2c` referenced by `List` and adjacent derived constructors/destructors. This supports utility placement, while the `SortedList` same-file question remains open.

## Source-Structure Decision

Use `util/List.cpp` as the working module. This is more faithful than placing `List` under `ui/` because the container is used well beyond UI widgets, and better than placing it under `render/` because render only consumes it.

## Cross-References

- [UID:000079][List](by-class/List.md)
- [UID:000191][0x004f3060-0x004f30d5.ListConstructor](by-memory/0x004f3060-0x004f30d5.ListConstructor.md)
- [UID:000192][0x004f30e0-0x004f3139.ListNonDeletingDestructor](by-memory/0x004f30e0-0x004f3139.ListNonDeletingDestructor.md)
- [UID:00022S][0x004f3140-0x004f35fd.ListCoreMethods](by-memory/0x004f3140-0x004f35fd.ListCoreMethods.md)
- [UID:0000NU][SortedList](by-file/SortedList.md)
- [UID:0000JV][HierList](by-file/HierList.md)
- [UID:0001VU][ResourceLayoutStore](by-type/by-struct/ResourceLayoutStore.md)
- [UID:0000M4][ObjectList](by-file/ObjectList.md)
- [UID:0000K2][ImageLib](by-file/ImageLib.md)
- [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md)
- [UID:0001QA][client_containers](by-meta/client_containers.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:82`.
  - Summary/evidence: fixed-width container role, contained/adjacent types, broad fan-in, constructor/destructor/core method refs, vtable evidence, `SortedList`/`HierList` relationship, source-structure decision, and cross-references are documented; confidence is capped by exact original folder and whether `SortedList` shared the source file.
- 2026-05-31 projected reconstruction path:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank.
  - Changed to: `NexusTK/util/`.
  - Summary/evidence: `by-project-structure/proposed-source-tree.md` places `List.cpp` under `util/`, and the 2026-05-31 IDA MCP recheck confirms broad non-feature caller evidence for the fixed-width container implementation.
