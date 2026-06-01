*** UID:0001TT | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# BlackHoleLayout

## Status

- Confidence: strong.
- Owner class: [UID:00000W][BlackHole](by-class/BlackHole.md)
- Likely source file: [UID:0000HR][BlackHole](by-file/BlackHole.md)
- Vtable: [UID:0001X2][BlackHoleVtable](by-type/by-vtable/BlackHoleVtable.md)
- Size: `0x14` bytes.
- Reconstructable: yes, as source-level class layout information. Do not emit C++ from this type page until the final `List` declaration and singleton wrapper ownership are fully audited.

## Layout

`BlackHole` has no known fields beyond its [UID:000079][List](by-class/List.md) base layout. The constructor calls `List::List(4, 1024)`, so each queue entry is a 4-byte object pointer and the initial capacity/page size is 1024 entries.

```text
0x00  vtable
+0x04 int elementSize      // 4 for object pointers
+0x08 int pageSize         // 1024 from BlackHole constructor
+0x0c int count
+0x10 void* entries
0x14  sizeof(BlackHole)
```

## Vtable

IDA reports the [UID:0001X2][BlackHoleVtable](by-type/by-vtable/BlackHoleVtable.md) at `0x00613118`. Slot `0` points to `0x00469240`, the scalar deleting destructor. The remaining visible virtuals match the `List` virtual surface for data access, element lookup, insertion, removal, clearing, and swapping.

## Notes

- `BlackHole::EnqueueIfMissing` and `ReleaseQueuedOwnedObjects` use the inherited `List` vtable to retrieve slots and append or clear entries.
- `BlackHole::QueuePaneForDeferredDeletion` stores pane pointers in this same list after detaching event/layer/timer state.
- The list backing buffer is destroyed by the shared [UID:000192][0x004f30e0-0x004f3139.ListNonDeletingDestructor](by-memory/0x004f30e0-0x004f3139.ListNonDeletingDestructor.md) when `BlackHole` tears down.
- 2026-05-31 IDA MCP recheck confirms `BlackHole::BlackHole` at `0x004690b0` calls `List::List` / `0x004f3060` with `(4, 1024)`, stores [UID:0000Q8][g_pApplicationCleanupQueue](by-global/g_pApplicationCleanupQueue.md) / `dword_67A74C`, and installs the `BlackHole` vtable.
- 2026-05-31 IDA MCP recheck confirms `BlackHole::~BlackHole` at `0x00469100` and `BlackHole::ScalarDeletingDestructor` at `0x00469240` both clear `dword_67A74C` and call the shared list non-deleting destructor at `0x004f30e0`.

## Open Questions

- Final source should decide whether `BlackHole` is written as a concrete `List` subclass, a singleton wrapper around a `List`, or a project-specific container typedef.
- The layout is strong, but final source naming should wait for the surrounding singleton/template policy.

## Cross-References

- [UID:00000W][BlackHole](by-class/BlackHole.md)
- [UID:0000HR][BlackHole](by-file/BlackHole.md)
- [UID:0001X2][BlackHoleVtable](by-type/by-vtable/BlackHoleVtable.md)
- [UID:000079][List](by-class/List.md)
- [UID:0000Q8][g_pApplicationCleanupQueue](by-global/g_pApplicationCleanupQueue.md)
