*** UID:0001TT | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:97 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00000W | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00000W | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// BlackHole's 0x14-byte object layout is represented by the source declaration
// `class BlackHole : public List`; no standalone layout struct is emitted here.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# BlackHoleLayout

## Status

- Confidence: strong.
- Owner class: [UID:00000W][BlackHole](by-class/BlackHole.md)
- Likely source file: [UID:0000HR][BlackHole](by-file/BlackHole.md)
- Vtable: [UID:0001X2][BlackHoleVtable](by-type/by-vtable/BlackHoleVtable.md)
- Size: `0x14` bytes.
- Reconstructable: yes, as source-level class layout information. The formal block intentionally emits only a no-standalone-layout comment because the class declaration on [UID:00000W][BlackHole](by-class/BlackHole.md) carries the source shape.

## Layout

`BlackHole` is best modeled as a [UID:000079][List](by-class/List.md) primary base plus a source-level `Singleton<BlackHole>` relationship. The constructor calls `List::List(4, 1024)` with `ecx=this`, so each queue entry is a 4-byte owned polymorphic object pointer and the initial capacity/page size is 1024 entries. No separate `List` member address is formed in the binary.

```text
0x00  List primary base vtable
+0x04 int elementSize      // 4 for object pointers
+0x08 int pageSize         // 1024 from BlackHole constructor
+0x0c int count
+0x10 void* entries
0x14  sizeof(BlackHole)
```

The source-facing queue entry type is most likely `LObject*`, because [UID:0002M4][0x00469200-0x00469233.BlackHoleReleaseQueuedOwnedObjects](by-memory/0x00469200-0x00469233.BlackHoleReleaseQueuedOwnedObjects.md) deletes each stored pointer through virtual destructor semantics. Use `void*` only as a conservative storage fallback if final headers cannot expose the common base yet.

## Vtable

IDA reports the [UID:0001X2][BlackHoleVtable](by-type/by-vtable/BlackHoleVtable.md) at `0x00613118`. Slot `0` points to `0x00469240`, the scalar deleting destructor. The remaining visible virtuals match the `List` virtual surface for data access, element lookup, insertion, removal, clearing, and swapping.

## Notes

- `BlackHole::EnqueueIfMissing` and `ReleaseQueuedOwnedObjects` use the inherited `List` vtable to retrieve slots and append or clear entries.
- `BlackHole::QueuePaneForDeferredDeletion` stores pane pointers in this same list after detaching event/layer/timer state.
- The list backing buffer is destroyed by the shared [UID:000192][0x004f30e0-0x004f3139.ListNonDeletingDestructor](by-memory/0x004f30e0-0x004f3139.ListNonDeletingDestructor.md) when `BlackHole` tears down.
- 2026-05-31 IDA MCP recheck confirms `BlackHole::BlackHole` at `0x004690b0` calls `List::List` / `0x004f3060` with `(4, 1024)`, stores [UID:0000Q8][g_pApplicationCleanupQueue](by-global/g_pApplicationCleanupQueue.md) / `dword_67A74C`, and installs the `BlackHole` vtable.
- 2026-05-31 IDA MCP recheck confirms `BlackHole::~BlackHole` at `0x00469100` and `BlackHole::ScalarDeletingDestructor` at `0x00469240` both clear `dword_67A74C` and call the shared list non-deleting destructor at `0x004f30e0`.

## Final Source Disposition

- The accepted declaration is explicitly `class BlackHole : public List, public Singleton<BlackHole>` and also declares the separately linked `extern BlackHole *g_pApplicationCleanupQueue` backing pointer.
- `List` is a primary base, not a composed member. The guarded BlackHole header carries `BlackHoleSizeMustBe20`, while this page remains a no-standalone-struct layout proof.

## Cross-References

- [UID:00000W][BlackHole](by-class/BlackHole.md)
- [UID:0000HR][BlackHole](by-file/BlackHole.md)
- [UID:0001X2][BlackHoleVtable](by-type/by-vtable/BlackHoleVtable.md)
- [UID:000079][List](by-class/List.md)
- [UID:0000Q8][g_pApplicationCleanupQueue](by-global/g_pApplicationCleanupQueue.md)

## Changes

- 2026-08-16 B009 UID0000MD accepted ordinary implementation: raised `88/93` to `94/97`, resolved the Singleton/global header shape, and retained the exact `0x14` List-primary-base layout without emitting a duplicate layout struct.

- 2026-07-01 B011 implementation callback for [UID:0000HR][BlackHole](by-file/BlackHole.md):
  - What changed: raised completion from `87` to `88` and inserted the accepted no-standalone-layout comment into the formal block.
  - Summary/evidence: the layout remains represented by `class BlackHole : public List` with `0x14`-byte inherited `List` storage, not a separate handwritten layout struct.

- 2026-06-06: Attached the layout to [UID:00000W][BlackHole](by-class/BlackHole.md) without changing scores.
  - Reasoning: the class is `84/92`, this layout is `82/92`, and the page already documents the `List(4, 1024)` base layout, vtable, singleton, constructor/destructor behavior, and final-source caveats, so it meets the parent gate.
  - Summary and evidence: the BlackHole class, file, aggregate memory, vtable, and singleton pages all agree that this 0x14-byte layout is the source-level layout evidence for the deferred deletion queue.
- 2026-06-17 B002 Rule 26 source-quality sync:
  - What changed: raised `82/92` to `87/93`, resolved the layout direction to `List` primary base with `Singleton<BlackHole>` source relationship, and documented the `LObject*` / owned-polymorphic pointer entry inference.
  - Summary/evidence: B002 confirmed the constructor passes `(4, 1024)` to `List::List` with `this`, methods use inherited `List` fields/vtable slots, and the drain method virtually deletes stored objects.
