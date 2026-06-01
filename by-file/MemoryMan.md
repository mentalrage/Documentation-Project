*** UID:0000L7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# MemoryMan

## Status

- Confidence: strong for allocator/singleton behavior from live IDA MCP, medium for final file name.
- Proposed module: `NexusTK/util/MemoryMan.cpp`
- Proposed header: `NexusTK/util/MemoryMan.h`
- Current generated sources: `class_MemoryMan.cpp`, recovered `operator_new_004F4AA0.cpp`, `AllocateBufferMemory_00516050.cpp`, `FreeBufferMemory_00516170.cpp`, and `ReallocateOrThrow_00516190.cpp`.
- Main memory doc: [UID:0001BA][0x00516000-0x0051628e.MemoryManAndAllocationHelpers](by-memory/0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md)
- Related globals: [UID:0000RH][g_pMemoryMan](by-global/g_pMemoryMan.md), [UID:0000T8][MemoryAllocationHelpers](by-global/MemoryAllocationHelpers.md)

## File Role

This source family is the client heap-allocation policy layer. It wraps CRT allocation functions, throws [UID:0000G7][Win32Error](by-class/Win32Error.md) on allocation failure, exposes the global `MemoryMan` singleton accessor, and supplies project-wide allocation/copy helpers used by UI, loaders, containers, networking, and image/resource code.

The original project may have named the source `MemoryMan.cpp` because Wave2 imported the class from `MemoryMan.cpp`. A shorter `Memory.cpp` or `MemoryUtil.cpp` remains possible, but the current best reconstruction is one utility source module rather than several one-function recovered files.

## Proposed Contents

| Entity | Address/range | Current generated state | Proposed ownership |
| --- | --- | --- | --- |
| `MemoryMan` static initializer | [UID:0000WA][0x00419f70-0x00419f86.MemoryManStaticInitializer](by-memory/0x00419f70-0x00419f86.MemoryManStaticInitializer.md) | not active class output | `MemoryMan.cpp`; constructs static `dword_69B3A8` and registers atexit reset. |
| `MemoryMan` constructor | [UID:0001B9][0x00516000-0x0051600f.MemoryManConstructor](by-memory/0x00516000-0x0051600f.MemoryManConstructor.md) | omitted from active class output | `MemoryMan.cpp`; installs vtable and sets `g_pMemoryMan`. |
| `MemoryMan` atexit reset thunk/tail | [UID:0001O7][0x0060c260-0x0060c26a.MemoryManAtexitResetThunk](by-memory/0x0060c260-0x0060c26a.MemoryManAtexitResetThunk.md) plus [UID:0001BB][0x00516010-0x00516021.MemoryManGlobalResetTail](by-memory/0x00516010-0x00516021.MemoryManGlobalResetTail.md) | omitted from active class output | `MemoryMan.cpp`; clears `g_pMemoryMan` for the static object. |
| `GetMemoryMan` | [UID:0001BC][0x00516030-0x00516036.GetMemoryMan](by-memory/0x00516030-0x00516036.GetMemoryMan.md) | omitted from active class output | `MemoryMan.cpp`; returns `g_pMemoryMan`. |
| `AllocateBufferMemory` | [UID:0001BD][0x00516050-0x005160ce.AllocateBufferMemory](by-memory/0x00516050-0x005160ce.AllocateBufferMemory.md) | recovered one-global file | `MemoryMan.cpp`; `malloc` or throw `Win32Error`. |
| zero-initializing allocation helper | [UID:0001BE][0x005160d0-0x00516162.ZeroAllocateBufferMemory](by-memory/0x005160d0-0x00516162.ZeroAllocateBufferMemory.md) | omitted from active output | `MemoryMan.cpp`; `malloc`, zero-fill, or throw `Win32Error`. |
| `FreeBufferMemory` | [UID:0001BF][0x00516170-0x00516184.FreeBufferMemory](by-memory/0x00516170-0x00516184.FreeBufferMemory.md) | recovered one-global file | `MemoryMan.cpp`; `free(block); return 0`. |
| `ReallocateOrThrow` | [UID:0001BG][0x00516190-0x00516210.ReallocateOrThrow](by-memory/0x00516190-0x00516210.ReallocateOrThrow.md) | recovered one-global file | `MemoryMan.cpp`; `realloc` or throw `Win32Error`. |
| copy wrappers | `0x00516220-0x00516258` | omitted from active output | `MemoryMan.cpp` or adjacent CRT wrapper support; wrappers around [UID:0001BH][0x00516220-0x00516238.MemmoveWrapper](by-memory/0x00516220-0x00516238.MemmoveWrapper.md) variants including [UID:0001BI][0x00516240-0x00516258.Memmove0Wrapper](by-memory/0x00516240-0x00516258.Memmove0Wrapper.md). |
| `MemoryMan` scalar deleting destructor | [UID:0001BJ][0x00516260-0x0051628e.MemoryManScalarDeletingDestructor](by-memory/0x00516260-0x0051628e.MemoryManScalarDeletingDestructor.md) | active `class_MemoryMan.cpp` | `MemoryMan.cpp`; clears `g_pMemoryMan` and optionally deletes `this`. |
| `operator new` wrapper | [UID:000196][0x004f4aa0-0x004f4ab4.OperatorNewWrapper](by-memory/0x004f4aa0-0x004f4ab4.OperatorNewWrapper.md) | recovered one-global file | Same utility source family or global operator source; calls `GetMemoryMan`, then `AllocateBufferMemory`. |
| `operator delete` wrapper | [UID:000197][0x004f4ac0-0x004f4b00.OperatorDeleteWrapper](by-memory/0x004f4ac0-0x004f4b00.OperatorDeleteWrapper.md) | not emitted as dedicated MemoryMan/global file | Same utility source family or global operator source; calls `GetMemoryMan`, then `FreeBufferMemory`. |

## Evidence

- `source-3/simroot_v2/class_MemoryMan.meta_wave3` imports `MemoryMan` from `MemoryMan.cpp`, with a 4-byte layout and a single active method at `0x00516260`.
- Live IDA MCP confirms `0x00419f70` constructs static `dword_69B3A8` with `MemoryMan::MemoryMan` and registers the atexit thunk `0x0060c260`.
- Live IDA MCP confirms `0x00516000` installs the vtable and writes `dword_69B4FC = this`.
- Live IDA MCP confirms `0x00516030` returns `dword_69B4FC`, matching a process-wide singleton accessor.
- Recovered global metadata and live IDA callers show broad fanout across loaders, UI panes, containers, and infrastructure.
- Live IDA MCP decompilation shows the allocation failure path constructs a `Win32Error` object through `0x004a60d0` and throws through the original C++ exception path.
- `0x00516290` begins the neighboring `MenuPane`/menu item island, so `0x00516000-0x0051628e` is a compact reviewed memory utility island rather than an arbitrary broad range.
- 2026-05-26 IDA MCP recheck reconfirms the omitted active-output bodies: `0x004f4ac0` calls `GetMemoryMan` then `FreeBufferMemory`, `0x00516000` writes `g_pMemoryMan`, `0x00516030` returns it, `0x005160d0` zero-fills the allocation, and `0x00516220` / `0x00516240` wrap the two IDA memmove names.
- 2026-05-31 IDA MCP recheck reconfirms the compact utility island and exact modeled starts: `0x00419f70`, `0x00516000`, `0x00516010`, `0x00516030`, `0x00516050`, `0x005160d0`, `0x00516170`, `0x00516190`, `0x00516220`, `0x00516240`, `0x00516260`, and the atexit thunk at `0x0060c260`. Xrefs still show broad allocator fanout for `GetMemoryMan`, allocation/free/copy helpers, and static-object/storage refs for `0x0069b3a8` and `0x0069b4fc`.

## Generated Output Caveats

- Active `class_MemoryMan.cpp` only emits the scalar deleting destructor at `0x00516260` and duplicate marker-only `global-data g_pMemoryMan` rows.
- `0x00419f70`, `0x00516000`, `0x0060c260`/`0x00516010`, `0x00516030`, `0x005160d0`, `0x00516220`, `0x00516240`, and `0x004f4ac0` are not currently emitted as active MemoryMan/source-family code.
- `operator_new_004F4AA0.cpp` and `FreeBufferMemory_00516170.cpp` still show duplicate active include lines after the normalized include section.
- The current generated helper names use a mix of `MemoryMan`, `MemoryManager`, raw `sub_516030`, and standalone recovered-global files. Treat those as staging names until the source family is migrated.
- 2026-05-26 `simroot_v2` snapshot still has this split. Do not use current generated file boundaries to infer that these helpers originally lived in separate source files.

## Source-Structure Decision

Use `util/MemoryMan.cpp` as the working owner for the singleton, allocation wrappers, and copy helpers. Keep `operator_new` linked to the same utility family even if final C++ migration emits it as a global operator in a separate runtime support source.

Do not place `AllocateBufferMemory` or `ReallocateOrThrow` under any caller module. Their behavior is allocator policy and their fanout is project-wide.

## Cross-References

- [UID:00007U][MemoryMan](by-class/MemoryMan.md)
- [UID:0000RH][g_pMemoryMan](by-global/g_pMemoryMan.md)
- [UID:0000T8][MemoryAllocationHelpers](by-global/MemoryAllocationHelpers.md)
- [UID:0001V4][MemoryManLayout](by-type/by-struct/MemoryManLayout.md)
- [UID:0001BA][0x00516000-0x0051628e.MemoryManAndAllocationHelpers](by-memory/0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md)
- [UID:0000WA][0x00419f70-0x00419f86.MemoryManStaticInitializer](by-memory/0x00419f70-0x00419f86.MemoryManStaticInitializer.md)
- [UID:000196][0x004f4aa0-0x004f4ab4.OperatorNewWrapper](by-memory/0x004f4aa0-0x004f4ab4.OperatorNewWrapper.md)
- [UID:000197][0x004f4ac0-0x004f4b00.OperatorDeleteWrapper](by-memory/0x004f4ac0-0x004f4b00.OperatorDeleteWrapper.md)
- [UID:0000J5][Error](by-file/Error.md)
- [UID:0000G7][Win32Error](by-class/Win32Error.md)
- [UID:0001QA][client_containers](by-meta/client_containers.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:88` and `CONFIDENCE:82`.
  - Summary/evidence: allocator/singleton policy, static initializer, constructor/reset/accessor, allocation/free/realloc/copy helpers, operator wrappers, IDA evidence, generated caveats, and source-structure decision are documented; confidence is capped by final file name and global operator placement.
- 2026-05-31 projected reconstruction path:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank and the proposed module allowed `util/MemoryMan.cpp` or `util/Memory.cpp`.
  - Changed to: `NexusTK/util/MemoryMan.cpp` with path value `NexusTK/util/`.
  - Summary/evidence: `by-project-structure/proposed-source-tree.md` already places the allocation policy module as `util/MemoryMan.cpp`, and the current IDA MCP recheck confirms a compact utility island with broad cross-subsystem allocator fanout rather than ownership by any single caller module.
