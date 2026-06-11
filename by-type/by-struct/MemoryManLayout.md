*** UID:0001V4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:00007U | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MemoryManLayout

## Status

- Confidence: strong for observed binary size, vtable field, singleton storage, and static-object lifecycle; medium-high for whether additional source-only members existed.
- Likely owner header: `util/MemoryMan.h`
- Related class: [UID:00007U][MemoryMan](by-class/MemoryMan.md)
- Autogen parent: attached to [UID:00007U][MemoryMan](by-class/MemoryMan.md); the class scores `86/88` and this layout scores `84/88`, so both sides satisfy the 80/80 parent gate.

## Layout

Current binary layout is minimal:

```text
MemoryMan
  +0x00  MemoryMan vptr
```

Observed size: `4` bytes.

The process-global static object storage is `dword_69B3A8` / `0x0069b3a8`. Live IDA shows [UID:0000WA][0x00419f70-0x00419f86.MemoryManStaticInitializer](by-memory/0x00419f70-0x00419f86.MemoryManStaticInitializer.md) constructing that storage and registering an atexit reset thunk at [UID:0001O7][0x0060c260-0x0060c26a.MemoryManAtexitResetThunk](by-memory/0x0060c260-0x0060c26a.MemoryManAtexitResetThunk.md). The singleton pointer [UID:0000RH][g_pMemoryMan](by-global/g_pMemoryMan.md) lives at `0x0069b4fc`.

## Evidence Notes

- IDA `list_globals *MemoryMan*` reports `??_7MemoryMan@@6B@` at `0x0061eb08` and RTTI complete-object locator `??_R4MemoryMan@@6B@` at `0x0064b5bc`.
- IDA `get_u32` shows `0x0061eb04 -> 0x0064b5bc`, `0x0061eb08 -> 0x00516260`, and `0x0061eb0c` begins the next RTTI pointer, so the binary vtable has one confirmed slot: the scalar deleting destructor.
- IDA decompile for [UID:0001B9][0x00516000-0x0051600f.MemoryManConstructor](by-memory/0x00516000-0x0051600f.MemoryManConstructor.md) writes `MemoryMan::vftable` to `this + 0x00` and stores `this` into `dword_69B4FC`.
- IDA decompile for [UID:0001BB][0x00516010-0x00516021.MemoryManGlobalResetTail](by-memory/0x00516010-0x00516021.MemoryManGlobalResetTail.md) writes the same vtable to `dword_69B3A8` and clears `dword_69B4FC`.
- IDA decompile for [UID:0001BJ][0x00516260-0x0051628e.MemoryManScalarDeletingDestructor](by-memory/0x00516260-0x0051628e.MemoryManScalarDeletingDestructor.md) writes the same vtable to `this + 0x00`, clears `dword_69B4FC`, and conditionally deletes `this`.
- IDA `xrefs_to 0x0069b3a8` lands only in the static initializer and reset thunk/tail; `xrefs_to 0x0069b4fc` lands in constructor, reset tail, accessor, and scalar deleting destructor.
- Allocation policy state is not stored in the object in current evidence; the helper family wraps CRT allocation calls directly.
- `source-3/simroot_v2/class_MemoryMan.meta_wave3` is consistent with the 4-byte one-vptr layout, but is only a generated lead. The IDA evidence above is the authority for the score.

## Open Questions

- Whether the original source used `MemoryMan` as a nominal manager class with most behavior in free/static helper functions, or whether optimization removed source-level members.
- Whether the copy wrappers at `0x00516220` and `0x00516240` were declared in the same header or a neighboring CRT/memory utility header.

## Cross-References

- [UID:0000L7][MemoryMan](by-file/MemoryMan.md)
- [UID:00007U][MemoryMan](by-class/MemoryMan.md)
- [UID:0000RH][g_pMemoryMan](by-global/g_pMemoryMan.md)
- [UID:0000T8][MemoryAllocationHelpers](by-global/MemoryAllocationHelpers.md)
- [UID:0001BA][0x00516000-0x0051628e.MemoryManAndAllocationHelpers](by-memory/0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md)

## Changes

- 2026-06-06: Attached the static singleton layout to [UID:00007U][MemoryMan](by-class/MemoryMan.md). Scores remain `84/88`; this parent sync follows the already documented one-vptr object and class ownership.
- Completion/confidence metadata:
  - What existed before: `COMPLETION:0`, `CONFIDENCE:0`, and blank `RECONSTRUCTABLE`.
  - Changed to: `COMPLETION:84`, `CONFIDENCE:88`, and `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: IDA confirms a 4-byte one-vptr `MemoryMan` static singleton object, one-slot vtable, constructor/reset/destructor writes, static storage at `0x0069b3a8`, singleton pointer at `0x0069b4fc`, and no observed allocation-policy fields inside the object. Parent UID and C++ reconstruction remain blank because final source shape is below the `95+` final-source gate.
