*** UID:0000T8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MemoryAllocationHelpers

## Status

- Confidence: strong for behavior and shared utility role, medium for final source split.
- Likely owner: [UID:0000L7][MemoryMan](by-file/MemoryMan.md)
- Entity kind: global helper family
- Main memory doc: [UID:0001BA][0x00516000-0x0051628e.MemoryManAndAllocationHelpers](by-memory/0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md)

## Role

These helpers implement the client allocation policy around CRT allocation calls. They are project-owned wrappers, not third-party library code and not feature-owned code. Allocation failure constructs [UID:0000G7][Win32Error](by-class/Win32Error.md) and throws through the original C++ exception path.

## Helper Map

| Symbol | Address/range | Behavior | Current generated state |
| --- | --- | --- | --- |
| `operator new` | [UID:000196][0x004f4aa0-0x004f4ab4.OperatorNewWrapper](by-memory/0x004f4aa0-0x004f4ab4.OperatorNewWrapper.md) | Calls `GetMemoryMan`, then `AllocateBufferMemory(size)`. | Active recovered global file. |
| `operator delete` | [UID:000197][0x004f4ac0-0x004f4b00.OperatorDeleteWrapper](by-memory/0x004f4ac0-0x004f4b00.OperatorDeleteWrapper.md) | Calls `GetMemoryMan`, then `FreeBufferMemory(block)`. | Not emitted as a dedicated active MemoryMan/global file. |
| `GetMemoryMan` | [UID:0001BC][0x00516030-0x00516036.GetMemoryMan](by-memory/0x00516030-0x00516036.GetMemoryMan.md) | Returns [UID:0000RH][g_pMemoryMan](by-global/g_pMemoryMan.md). | Omitted from active class output. |
| `AllocateBufferMemory` | [UID:0001BD][0x00516050-0x005160ce.AllocateBufferMemory](by-memory/0x00516050-0x005160ce.AllocateBufferMemory.md) | `malloc(size)` or throw `Win32Error`. | Active recovered global file. |
| zero-alloc helper | [UID:0001BE][0x005160d0-0x00516162.ZeroAllocateBufferMemory](by-memory/0x005160d0-0x00516162.ZeroAllocateBufferMemory.md) | `malloc(size)`, `memset(block, 0, size)`, or throw `Win32Error`. | Omitted from active output. |
| `FreeBufferMemory` | [UID:0001BF][0x00516170-0x00516184.FreeBufferMemory](by-memory/0x00516170-0x00516184.FreeBufferMemory.md) | `free(block); return 0`. | Active recovered global file. |
| `ReallocateOrThrow` | [UID:0001BG][0x00516190-0x00516210.ReallocateOrThrow](by-memory/0x00516190-0x00516210.ReallocateOrThrow.md) | `realloc(block, newSize)` or throw `Win32Error`. | Active recovered global file. |
| copy wrapper | [UID:0001BH][0x00516220-0x00516238.MemmoveWrapper](by-memory/0x00516220-0x00516238.MemmoveWrapper.md) | `memmove(dst, src, size)`. | Omitted from active output. |
| alternate copy wrapper | [UID:0001BI][0x00516240-0x00516258.Memmove0Wrapper](by-memory/0x00516240-0x00516258.Memmove0Wrapper.md) | alternate `memmove` wrapper. | Omitted from active output. |

## Ownership Notes

`AllocateBufferMemory`, `FreeBufferMemory`, and `ReallocateOrThrow` currently emit as separate recovered files because they were restored as Wave2 globals. For source reconstruction, keep them with the [UID:0000L7][MemoryMan](by-file/MemoryMan.md) utility module unless later original-source evidence proves a separate runtime allocation file.

`operator new` and `operator delete` may be declared as global operators in the final C++ source, but their implementations belong to the same memory utility family. They are not application feature helpers.

Live IDA MCP confirms the omitted `operator delete` wrapper at `0x004f4ac0-0x004f4b00`, which routes through `GetMemoryMan` and `FreeBufferMemory` and has broad caller fanout.

2026-05-26 recheck: current `simroot_v2` still emits only some helpers as recovered one-function files and omits `operator delete`, `GetMemoryMan`, zero-alloc, and both copy wrappers. IDA MCP decompilation still confirms those omitted wrappers and the `Win32Error` throw path for allocation failure.

## Cross-References

- [UID:0000L7][MemoryMan](by-file/MemoryMan.md)
- [UID:00007U][MemoryMan](by-class/MemoryMan.md)
- [UID:0000RH][g_pMemoryMan](by-global/g_pMemoryMan.md)
- [UID:0001V4][MemoryManLayout](by-type/by-struct/MemoryManLayout.md)
- [UID:0001BA][0x00516000-0x0051628e.MemoryManAndAllocationHelpers](by-memory/0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md)
- [UID:0000J5][Error](by-file/Error.md)
- [UID:0000G7][Win32Error](by-class/Win32Error.md)
- [UID:0001QA][client_containers](by-meta/client_containers.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `78/84`.
  - Before: page documented the allocation helper family, helper map, MemoryMan ownership, omitted wrappers, and throw path but remained unevaluated.
  - After: score reflects documented global new/delete wrappers, allocation/free/realloc/copy helpers, active/omitted generated state, and source-family decision.
  - Evidence: linked memory pages cover `operator new/delete`, `GetMemoryMan`, malloc/zero/realloc/free wrappers, memmove wrappers, and `Win32Error` allocation-failure behavior.
