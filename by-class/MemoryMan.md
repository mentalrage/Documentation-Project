*** UID:00007U | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MemoryMan

## Status

- Confidence: strong for singleton role and method behavior, medium for final class usefulness.
- Likely source file: [UID:0000L7][MemoryMan](by-file/MemoryMan.md)
- Current generated file: `source-3/simroot_v2/class_MemoryMan.cpp`
- Main address range: [UID:0001BA][0x00516000-0x0051628e.MemoryManAndAllocationHelpers](by-memory/0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md)
- Layout note: [UID:0001V4][MemoryManLayout](by-type/by-struct/MemoryManLayout.md)

## Class Purpose

`MemoryMan` is the process-wide memory manager singleton. The concrete object appears minimal: it stores a vtable pointer and is used mostly as a global allocation-policy anchor. The actual allocation behavior is implemented by nearby free helpers that wrap `malloc`, `free`, `realloc`, and copy routines.

## Method Map

| Range | Method | Status | Role |
| --- | --- | --- | --- |
| [UID:0001B9][0x00516000-0x0051600f.MemoryManConstructor](by-memory/0x00516000-0x0051600f.MemoryManConstructor.md) | constructor | omitted from active class output | Installs `MemoryMan` vtable and stores `this` into `g_pMemoryMan`. |
| [UID:0001O7][0x0060c260-0x0060c26a.MemoryManAtexitResetThunk](by-memory/0x0060c260-0x0060c26a.MemoryManAtexitResetThunk.md) plus [UID:0001BB][0x00516010-0x00516021.MemoryManGlobalResetTail](by-memory/0x00516010-0x00516021.MemoryManGlobalResetTail.md) | static-object reset | omitted from active class output | Registered with `_atexit`; resets the static object vtable and clears `g_pMemoryMan`. |
| [UID:0001BJ][0x00516260-0x0051628e.MemoryManScalarDeletingDestructor](by-memory/0x00516260-0x0051628e.MemoryManScalarDeletingDestructor.md) | scalar deleting destructor | active generated method | Reinstalls vtable, clears `g_pMemoryMan`, and optionally deletes `this`. |

## Key Relationships

- [UID:0000RH][g_pMemoryMan](by-global/g_pMemoryMan.md) at `0x0069b4fc` is set by the constructor, returned by `GetMemoryMan`, and cleared by destructor/reset paths.
- `dword_69B3A8` is the static `MemoryMan` object storage constructed by [UID:0000WA][0x00419f70-0x00419f86.MemoryManStaticInitializer](by-memory/0x00419f70-0x00419f86.MemoryManStaticInitializer.md).
- [UID:0000T8][MemoryAllocationHelpers](by-global/MemoryAllocationHelpers.md) wrap CRT allocation and throw [UID:0000G7][Win32Error](by-class/Win32Error.md) on failure.
- `operator_new` at `0x004f4aa0` calls `GetMemoryMan` before `AllocateBufferMemory`, making the singleton visible from most heap object construction paths.

## Current Data Caveats

Active `class_MemoryMan.cpp` only emits the scalar deleting destructor and duplicate marker-only `global-data g_pMemoryMan` rows. Live IDA confirms the omitted static initializer, constructor, atexit reset thunk/tail, singleton accessor, zero-alloc helper, delete wrapper, and copy wrappers.

Do not infer that `MemoryMan` only has one method in the original source. The active generated class is incomplete for source reconstruction.

2026-05-26 recheck: current `simroot_v2` is unchanged for this class, while IDA MCP still confirms the missing constructor/accessor/reset paths and nearby allocation/copy helpers. Use IDA-backed memory docs for class/file reconstruction.

## Cross-References

- [UID:0000L7][MemoryMan](by-file/MemoryMan.md)
- [UID:0000RH][g_pMemoryMan](by-global/g_pMemoryMan.md)
- [UID:0000T8][MemoryAllocationHelpers](by-global/MemoryAllocationHelpers.md)
- [UID:0001V4][MemoryManLayout](by-type/by-struct/MemoryManLayout.md)
- [UID:0001BA][0x00516000-0x0051628e.MemoryManAndAllocationHelpers](by-memory/0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md)
- [UID:0000WA][0x00419f70-0x00419f86.MemoryManStaticInitializer](by-memory/0x00419f70-0x00419f86.MemoryManStaticInitializer.md)
- [UID:0000J5][Error](by-file/Error.md)
- [UID:0000G7][Win32Error](by-class/Win32Error.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `82/76`. Summary: the singleton memory manager and neighboring allocation helpers are well mapped, including omitted constructor/reset/accessor paths, but confidence is capped by the question of how useful the original `MemoryMan` class abstraction was versus nearby free helper ownership. Evidence: linked memory-manager/allocation range, static initializer, atexit reset thunk/tail, `g_pMemoryMan`, layout note, and active generated-source omission caveats.
- Reconstructable metadata: existed before as blank; changed to `TRUE`. Summary: IDA confirms `MemoryMan` as NexusTK-owned source-level singleton state and helper-family anchor that must be represented in the rebuilt utility layer. Parent UID and C++ reconstruction remain blank because the final source shape, global operator placement, and exact original class/header form are below the `95+` final-source gate.
