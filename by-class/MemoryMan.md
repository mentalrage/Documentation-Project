*** UID:00007U | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000L7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MemoryMan

## Status

- Confidence: strong for singleton role, live vtable/global wiring, static object lifetime, and allocation helper relationships; medium for final helper/header factoring.
- Likely source file: [UID:0000L7][MemoryMan](by-file/MemoryMan.md)
- Main address range: [UID:0001BA][0x00516000-0x0051628e.MemoryManAndAllocationHelpers](by-memory/0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md)
- Layout note: [UID:0001V4][MemoryManLayout](by-type/by-struct/MemoryManLayout.md)
- Parent attachment: [UID:0000L7][MemoryMan](by-file/MemoryMan.md) has the current `NexusTK/util/` reconstruction path and owns the singleton/allocation utility source family.
- Reconstruction handling: attached to `MemoryMan.cpp`; C++ remains blank until helper placement, global operator placement, and final declarations reach the final-source bar.

## Class Purpose

`MemoryMan` is the process-wide memory manager singleton. The concrete object appears minimal: it stores a vtable pointer and is used mostly as a global allocation-policy anchor. The actual allocation behavior is implemented by nearby free helpers that wrap `malloc`, `free`, `realloc`, and copy routines.

## Method Map

| Range | Method | Status | Role |
| --- | --- | --- | --- |
| [UID:0001B9][0x00516000-0x0051600f.MemoryManConstructor](by-memory/0x00516000-0x0051600f.MemoryManConstructor.md) | constructor | reconstructable child | Installs `MemoryMan` vtable and stores `this` into `g_pMemoryMan`. |
| [UID:0001O7][0x0060c260-0x0060c26a.MemoryManAtexitResetThunk](by-memory/0x0060c260-0x0060c26a.MemoryManAtexitResetThunk.md) plus [UID:0001BB][0x00516010-0x00516021.MemoryManGlobalResetTail](by-memory/0x00516010-0x00516021.MemoryManGlobalResetTail.md) | static-object reset | static-lifetime support | Registered with `_atexit`; resets the static object vtable and clears `g_pMemoryMan`. |
| [UID:0001BJ][0x00516260-0x0051628e.MemoryManScalarDeletingDestructor](by-memory/0x00516260-0x0051628e.MemoryManScalarDeletingDestructor.md) | scalar deleting destructor | reconstructable child | Reinstalls vtable, clears `g_pMemoryMan`, and optionally deletes `this`. |

## Key Relationships

- [UID:0000RH][g_pMemoryMan](by-global/g_pMemoryMan.md) at `0x0069b4fc` is set by the constructor, returned by `GetMemoryMan`, and cleared by destructor/reset paths; the exact data page is [UID:0002B0][0x0069b4fc-0x0069b500.g_pMemoryMan](by-memory/0x0069b4fc-0x0069b500.g_pMemoryMan.md).
- [UID:00029R][0x0069b3a8-0x0069b3ac.MemoryManStaticObjectStorage](by-memory/0x0069b3a8-0x0069b3ac.MemoryManStaticObjectStorage.md) is the static `MemoryMan` object storage constructed by [UID:0000WA][0x00419f70-0x00419f86.MemoryManStaticInitializer](by-memory/0x00419f70-0x00419f86.MemoryManStaticInitializer.md).
- [UID:0000T8][MemoryAllocationHelpers](by-global/MemoryAllocationHelpers.md) wrap CRT allocation and throw [UID:0000G7][Win32Error](by-class/Win32Error.md) on failure.
- `operator_new` at `0x004f4aa0` calls `GetMemoryMan` before `AllocateBufferMemory`, making the singleton visible from most heap object construction paths.

## Live IDA Evidence

- 2026-06-04 live IDA MCP names the vtable at `0x0061eb08` as `??_7MemoryMan@@6B@`; the first slot points to `0x00516260`.
- Live xrefs to the vtable come from the constructor at `0x00516000`, the reset tail at `0x00516010`, and the scalar deleting destructor at `0x0051626a`.
- Live xrefs to `g_pMemoryMan` / `0x0069b4fc` show constructor write `0x00516008`, reset clear `0x00516016`, accessor read `0x00516030`, and destructor clear `0x00516270`.
- Live xrefs to static object storage `0x0069b3a8` show only the static initializer at `0x00419f70` and atexit thunk at `0x0060c260`.
- Live IDA confirms exact modeled starts for the compact memory utility island: constructor `0x00516000-0x0051600f`, reset tail `0x00516010-0x00516021`, accessor `0x00516030-0x00516036`, allocation helpers `0x00516050-0x00516258`, scalar deleting destructor `0x00516260-0x0051628e`, and neighboring `MenuPane` start at `0x00516290`.
- Live operator wrappers confirm `0x004f4aa0` calls `GetMemoryMan` then `AllocateBufferMemory`, and `0x004f4ac0` calls `GetMemoryMan` then `FreeBufferMemory`.
- Live allocation helper disassembly confirms `malloc` / `memset` / `realloc` paths, `Win32Error` construction through `0x004a60d0`, and C++ exception throws on allocation failure.

## Reconstruction Caveats

`MemoryMan` is a real project singleton and allocation-policy anchor, but final source still needs a decision on whether global operators and copy wrappers live in `MemoryMan.cpp` or a neighboring runtime-support source. Keep generated C++ blank until that split and the final declarations reach 95/95.

Do not infer that `MemoryMan` only has one source-level method from any single emitted class body. Use the IDA-backed memory docs for class/file reconstruction.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 86 | The page now records parent file attachment, exact live vtable/global/static-object evidence, child method map, singleton allocation helper relationships, operator wrapper links, utility island boundaries, and reconstruction constraints. |
| Confidence | 88 | Confidence is strong because live IDA ties constructor/reset/accessor/destructor behavior and source-declared data to `MemoryMan`; it remains below final-source level due to unresolved global operator/copy-wrapper placement and final declaration factoring. |
| Reconstructable | true | This is NexusTK-owned utility source behavior; final C++ remains blank below the 95/95 bar. |

## Cross-References

- [UID:0000L7][MemoryMan](by-file/MemoryMan.md)
- [UID:0000RH][g_pMemoryMan](by-global/g_pMemoryMan.md)
- [UID:0000T8][MemoryAllocationHelpers](by-global/MemoryAllocationHelpers.md)
- [UID:0001V4][MemoryManLayout](by-type/by-struct/MemoryManLayout.md)
- [UID:0001BA][0x00516000-0x0051628e.MemoryManAndAllocationHelpers](by-memory/0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md)
- [UID:0000WA][0x00419f70-0x00419f86.MemoryManStaticInitializer](by-memory/0x00419f70-0x00419f86.MemoryManStaticInitializer.md)
- [UID:00029R][0x0069b3a8-0x0069b3ac.MemoryManStaticObjectStorage](by-memory/0x0069b3a8-0x0069b3ac.MemoryManStaticObjectStorage.md)
- [UID:0002B0][0x0069b4fc-0x0069b500.g_pMemoryMan](by-memory/0x0069b4fc-0x0069b500.g_pMemoryMan.md)
- [UID:0000J5][Error](by-file/Error.md)
- [UID:0000G7][Win32Error](by-class/Win32Error.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `82/76`. Summary: the singleton memory manager and neighboring allocation helpers are well mapped, including constructor/reset/accessor paths, but confidence is capped by the question of how useful the original `MemoryMan` class abstraction was versus nearby free helper ownership. Evidence: linked memory-manager/allocation range, static initializer, atexit reset thunk/tail, `g_pMemoryMan`, layout note, and reconstruction caveats.
- Reconstructable metadata: existed before as blank; changed to `TRUE`. Summary: IDA confirms `MemoryMan` as NexusTK-owned source-level singleton state and helper-family anchor that must be represented in the rebuilt utility layer. Parent UID and C++ reconstruction remain blank because the final source shape, global operator placement, and exact original class/header form are below the `95+` final-source gate.
- 2026-06-04 live IDA refresh:
  - Changed to: `COMPLETION:86`, `CONFIDENCE:88`, and `AUTOGEN_PARENT_UID:0000L7`.
  - Evidence: live IDA MCP confirmed the named `MemoryMan` vtable at `0x0061eb08`, vtable xrefs from constructor/reset/destructor paths, `g_pMemoryMan` write/read/clear sites, static object xrefs, compact utility-island boundaries, operator new/delete calls through `GetMemoryMan`, allocation failure throw paths, and parent ownership under [UID:0000L7][MemoryMan](by-file/MemoryMan.md).
  - Remaining limits: C++ remains blank because global operator placement, copy-wrapper ownership, and final declarations are still below the final-source threshold.
