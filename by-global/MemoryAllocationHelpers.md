*** UID:0000T8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000L7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MemoryAllocationHelpers

## Status

- Confidence: strong for behavior, boundaries, and shared utility role; medium-high for final source split.
- Likely owner: [UID:0000L7][MemoryMan](by-file/MemoryMan.md)
- Entity kind: global helper family
- Main memory doc: [UID:0001BA][0x00516000-0x0051628e.MemoryManAndAllocationHelpers](by-memory/0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md)

## Role

These helpers implement the client allocation policy around CRT allocation calls. They are project-owned wrappers, not third-party library code and not feature-owned code. Allocation failure constructs [UID:0000G7][Win32Error](by-class/Win32Error.md) and throws through the original C++ exception path.

The page is a name-centric helper-family index. Exact bodies live in the linked [UID:0001BA][0x00516000-0x0051628e.MemoryManAndAllocationHelpers](by-memory/0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md) island and the non-contiguous operator wrapper pages. The source-owner decision is still [UID:0000L7][MemoryMan](by-file/MemoryMan.md), not this global page.

## Helper Map

| Symbol | Address/range | Behavior | Source migration note |
| --- | --- | --- | --- |
| `operator new` | [UID:000196][0x004f4aa0-0x004f4ab4.OperatorNewWrapper](by-memory/0x004f4aa0-0x004f4ab4.OperatorNewWrapper.md) | Calls `GetMemoryMan`, then `AllocateBufferMemory(size)`. | Global operator wrapper near MemoryMan. |
| `operator delete` | [UID:000197][0x004f4ac0-0x004f4b00.OperatorDeleteWrapper](by-memory/0x004f4ac0-0x004f4b00.OperatorDeleteWrapper.md) | Calls `GetMemoryMan`, then `FreeBufferMemory(block)`. | Global operator wrapper near MemoryMan. |
| `GetMemoryMan` | [UID:0001BC][0x00516030-0x00516036.GetMemoryMan](by-memory/0x00516030-0x00516036.GetMemoryMan.md) | Returns [UID:0000RH][g_pMemoryMan](by-global/g_pMemoryMan.md). | File-local/shared MemoryMan accessor. |
| `AllocateBufferMemory` | [UID:0001BD][0x00516050-0x005160ce.AllocateBufferMemory](by-memory/0x00516050-0x005160ce.AllocateBufferMemory.md) | `malloc(size)` or throw `Win32Error`. | MemoryMan allocation helper. |
| zero-alloc helper | [UID:0001BE][0x005160d0-0x00516162.ZeroAllocateBufferMemory](by-memory/0x005160d0-0x00516162.ZeroAllocateBufferMemory.md) | `malloc(size)`, `memset(block, 0, size)`, or throw `Win32Error`. | MemoryMan allocation helper. |
| `FreeBufferMemory` | [UID:0001BF][0x00516170-0x00516184.FreeBufferMemory](by-memory/0x00516170-0x00516184.FreeBufferMemory.md) | `free(block); return 0`. | MemoryMan free helper. |
| `ReallocateOrThrow` | [UID:0001BG][0x00516190-0x00516210.ReallocateOrThrow](by-memory/0x00516190-0x00516210.ReallocateOrThrow.md) | `realloc(block, newSize)` or throw `Win32Error`. | MemoryMan reallocation helper. |
| copy wrapper | [UID:0001BH][0x00516220-0x00516238.MemmoveWrapper](by-memory/0x00516220-0x00516238.MemmoveWrapper.md) | `memmove(dst, src, size)`. | Utility copy wrapper near MemoryMan. |
| alternate copy wrapper | [UID:0001BI][0x00516240-0x00516258.Memmove0Wrapper](by-memory/0x00516240-0x00516258.Memmove0Wrapper.md) | alternate `memmove` wrapper. | Utility copy wrapper near MemoryMan. |

## Boundary And Fanout Evidence

| Evidence area | Documentation result |
| --- | --- |
| Static setup | [UID:0000WA][0x00419f70-0x00419f86.MemoryManStaticInitializer](by-memory/0x00419f70-0x00419f86.MemoryManStaticInitializer.md) constructs the static `MemoryMan` object and registers the atexit reset thunk. |
| Compact helper island | [UID:0001BA][0x00516000-0x0051628e.MemoryManAndAllocationHelpers](by-memory/0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md) records constructor, reset tail, accessor, allocation/free/realloc/copy helpers, scalar deleting destructor, local alignment gaps, and the neighboring `0x00516290` menu-pane boundary. |
| Global operators | [UID:000196][0x004f4aa0-0x004f4ab4.OperatorNewWrapper](by-memory/0x004f4aa0-0x004f4ab4.OperatorNewWrapper.md) and [UID:000197][0x004f4ac0-0x004f4b00.OperatorDeleteWrapper](by-memory/0x004f4ac0-0x004f4b00.OperatorDeleteWrapper.md) route project-wide allocation/deallocation through `GetMemoryMan` and the allocation/free helpers. |
| Failure handling | `AllocateBufferMemory`, zero-allocation, and `ReallocateOrThrow` construct [UID:0000G7][Win32Error](by-class/Win32Error.md) and throw through the original C++ exception path when CRT allocation returns null. |
| Runtime classification | The helpers call CRT routines, but the policy layer and operator wrappers are NexusTK-owned source behavior; do not classify this family as third-party/runtime. |

## Ownership Notes

For source reconstruction, keep the allocation helpers with the [UID:0000L7][MemoryMan](by-file/MemoryMan.md) utility module unless later original-source evidence proves a separate runtime allocation file.

`operator new` and `operator delete` may be declared as global operators in the final C++ source, but their implementations belong to the same memory utility family. They are not application feature helpers.

Live IDA MCP confirms the omitted `operator delete` wrapper at `0x004f4ac0-0x004f4b00`, which routes through `GetMemoryMan` and `FreeBufferMemory` and has broad caller fanout.

2026-05-26 recheck: IDA MCP decompilation confirms `operator delete`, `GetMemoryMan`, zero-alloc, both copy wrappers, and the `Win32Error` throw path for allocation failure.
2026-06-05 recheck: IDA MCP confirmed helper boundaries at `0x00516030`, `0x00516050`, `0x005160d0`, `0x00516170`, `0x00516190`, `0x00516220`, and `0x00516240`, with malloc/free/realloc/memmove callees and broad allocation-wrapper fanout.

## Reconstruction Caveats

Keep `RECONSTRUCTION_CPP CODE` blank here. The helper family is reconstructable, but final source still needs the original declaration shape for global `operator new` / `operator delete`, the final names for the zero-allocation and copy wrappers, and a decision on whether the copy wrappers are in `MemoryMan.cpp` or a small adjacent runtime-support source.

Do not split the one-function recovered globals into separate original files just because generated output currently does. The current source-level evidence favors one utility source family centered on `MemoryMan.cpp`, with global operators either emitted there or in an adjacent allocation-support unit.

## Cross-References

- [UID:0000L7][MemoryMan](by-file/MemoryMan.md)
- [UID:00007U][MemoryMan](by-class/MemoryMan.md)
- [UID:0000RH][g_pMemoryMan](by-global/g_pMemoryMan.md)
- [UID:0001V4][MemoryManLayout](by-type/by-struct/MemoryManLayout.md)
- [UID:0001BA][0x00516000-0x0051628e.MemoryManAndAllocationHelpers](by-memory/0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md)
- [UID:0000WA][0x00419f70-0x00419f86.MemoryManStaticInitializer](by-memory/0x00419f70-0x00419f86.MemoryManStaticInitializer.md)
- [UID:000196][0x004f4aa0-0x004f4ab4.OperatorNewWrapper](by-memory/0x004f4aa0-0x004f4ab4.OperatorNewWrapper.md)
- [UID:000197][0x004f4ac0-0x004f4b00.OperatorDeleteWrapper](by-memory/0x004f4ac0-0x004f4b00.OperatorDeleteWrapper.md)
- [UID:0000J5][Error](by-file/Error.md)
- [UID:0000G7][Win32Error](by-class/Win32Error.md)
- [UID:0001QA][client_containers](by-meta/client_containers.md)

## Changes

- 2026-06-06 helper-family evidence pass:
  - Changed to: `COMPLETION:86` and `CONFIDENCE:88`.
  - Summary/evidence: expanded this index with compact-island boundaries, static setup, global operator wrappers, throw-path classification, source-family ownership, and reconstruction caveats. The score remains below final-source quality because global operator placement, zero/copy wrapper names, and final declarations are still open.
- 2026-05-30: Grading changed from `0/0` to `78/84`.
  - Before: page documented the allocation helper family, helper map, MemoryMan ownership, omitted wrappers, and throw path but remained unevaluated.
  - After: score reflects documented global new/delete wrappers, allocation/free/realloc/copy helpers, and source-family decision.
  - Evidence: linked memory pages cover `operator new/delete`, `GetMemoryMan`, malloc/zero/realloc/free wrappers, memmove wrappers, and `Win32Error` allocation-failure behavior.
- 2026-06-05: Marked reconstructable and attached to [UID:0000L7][MemoryMan](by-file/MemoryMan.md).
  - Reason: live IDA MCP recheck confirms this is source-authored project allocation policy code with helper bodies and broad callers centered on the MemoryMan utility module.
