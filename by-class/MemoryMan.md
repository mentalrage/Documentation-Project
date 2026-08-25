*** UID:00007U | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000L7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "MemoryMan.h"
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#pragma once

#include <stddef.h>

class MemoryMan
{
public:
    MemoryMan();
    virtual ~MemoryMan();

    void *AllocateBufferMemory(size_t size);
    void *ZeroAllocateBufferMemory(size_t size);
    void *FreeBufferMemory(void *block);
    void *ReallocateBufferMemory(void *block, size_t newSize);
    void *MemmoveWrapper(void *destination, const void *source, size_t size);
    void *MoveBufferMemory(void *destination, const void *source, size_t size);
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MemoryMan

## Status

- Confidence: very strong for singleton role, live vtable/global wiring, static object lifetime, class lifecycle method routing, and allocation helper relationships; medium-high for final helper/header/global-operator factoring.
- Likely source file: [UID:0000L7][MemoryMan](by-file/MemoryMan.md)
- Main address range: [UID:0001BA][0x00516000-0x0051628e.MemoryManAndAllocationHelpers](by-memory/0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md)
- Layout note: [UID:0001V4][MemoryManLayout](by-type/by-struct/MemoryManLayout.md)
- Parent attachment: [UID:0000L7][MemoryMan](by-file/MemoryMan.md) has the current `NexusTK/util/` reconstruction path and owns the singleton/allocation utility source family.
- Reconstruction handling: attached to the `MemoryMan.cpp` / `MemoryMan.h` pair. This class page emits `#include "MemoryMan.h"` in CPP and the complete class declaration in H; method-body C++ still lives on exact child pages: [UID:0001B9][0x00516000-0x0051600f.MemoryManConstructor](by-memory/0x00516000-0x0051600f.MemoryManConstructor.md), [UID:0001BB][0x00516010-0x00516021.MemoryManDestructor](by-memory/0x00516010-0x00516021.MemoryManDestructor.md), [UID:0001BD][0x00516050-0x005160ce.AllocateBufferMemory](by-memory/0x00516050-0x005160ce.AllocateBufferMemory.md), [UID:0001BE][0x005160d0-0x00516162.ZeroAllocateBufferMemory](by-memory/0x005160d0-0x00516162.ZeroAllocateBufferMemory.md), [UID:0001BF][0x00516170-0x00516184.FreeBufferMemory](by-memory/0x00516170-0x00516184.FreeBufferMemory.md), [UID:0001BG][0x00516190-0x00516210.ReallocateOrThrow](by-memory/0x00516190-0x00516210.ReallocateOrThrow.md), [UID:0001BH][0x00516220-0x00516238.MemmoveWrapper](by-memory/0x00516220-0x00516238.MemmoveWrapper.md), and [UID:0001BI][0x00516240-0x00516258.Memmove0Wrapper](by-memory/0x00516240-0x00516258.Memmove0Wrapper.md). [UID:0001BC][0x00516030-0x00516036.GetMemoryMan](by-memory/0x00516030-0x00516036.GetMemoryMan.md) emits the file-level free-helper declaration after this class in the same header. [UID:000196][0x004f4aa0-0x004f4ab4.OperatorNewWrapper](by-memory/0x004f4aa0-0x004f4ab4.OperatorNewWrapper.md) and [UID:000197][0x004f4ac0-0x004f4b00.OperatorDeleteWrapper](by-memory/0x004f4ac0-0x004f4b00.OperatorDeleteWrapper.md) remain global operators in the file family, not class members.

## Class Purpose

`MemoryMan` is the process-wide memory manager singleton. The concrete object appears minimal: it stores a vtable pointer and is used mostly as a global allocation-policy anchor. B008 resolves the primary allocation body as the nonvirtual method `MemoryMan::AllocateBufferMemory(size_t size)` and the zero-fill allocation body as the nonvirtual method `MemoryMan::ZeroAllocateBufferMemory(size_t size)` even though those bodies do not dereference `this`; callers supply the singleton in `ECX` before each call. B002 resolves the free body as the nonvirtual method `MemoryMan::FreeBufferMemory(void *buffer)` for the same caller-ABI reason: representative callers obtain [UID:0001BC][0x00516030-0x00516036.GetMemoryMan](by-memory/0x00516030-0x00516036.GetMemoryMan.md), carry the result in `ECX`, pass one explicit stack argument, and use the zero return to clear pointer fields. B010 resolves the reallocation body as `MemoryMan::ReallocateBufferMemory(void *block, size_t newSize)` because all 10 current direct callers use the same `GetMemoryMan()`-to-`ECX` protocol before calling `0x00516190`; the historical `ReallocateOrThrow` name remains an alias and confidence cap. B006 resolves the primary copy/move wrapper as `MemoryMan::MemmoveWrapper(void *destination, const void *source, size_t size)` because representative caller `0x004f32e0` follows the same `GetMemoryMan()` / saved singleton / `ECX` reload pattern before calling `0x00516220`. B009 resolves the paired `_memmove_0` wrapper as `MemoryMan::MoveBufferMemory(void *destination, const void *source, size_t size)` because its 19 direct callers use the same `GetMemoryMan()`-to-`ECX` protocol for overlap-safe tail shifts, compaction, text-edit buffer movement, SoundManager sample rotation, and ObjectList slot movement. The accessor itself remains a file-level free helper under B007.

## Method Map

| Range | Method | Status | Role |
| --- | --- | --- | --- |
| [UID:0001B9][0x00516000-0x0051600f.MemoryManConstructor](by-memory/0x00516000-0x0051600f.MemoryManConstructor.md) | constructor | reconstructable child with formal method C++ | Installs the compiler vptr and stores `this` into `g_pMemoryMan`; B006 2026-06-26 accepts the source constructor body on the child page, with direct owner/emitter through this class. |
| [UID:0001BB][0x00516010-0x00516021.MemoryManDestructor](by-memory/0x00516010-0x00516021.MemoryManDestructor.md) | ordinary destructor/reset body | reconstructable child with formal destructor C++ | Source body clears `g_pMemoryMan`; compiler lowering reinstalls the vptr, and the body is reached from the generated atexit thunk for static object cleanup. |
| [UID:0001BD][0x00516050-0x005160ce.AllocateBufferMemory](by-memory/0x00516050-0x005160ce.AllocateBufferMemory.md) | `AllocateBufferMemory(size_t size)` | reconstructable child with formal method C++ | Nonvirtual allocation-policy method; returns `malloc(size)` on success and throws `new Win32Error` on failure. B008 accepts this method form because live callers load `GetMemoryMan()` into `ECX` before calling `0x00516050`. |
| [UID:0001BE][0x005160d0-0x00516162.ZeroAllocateBufferMemory](by-memory/0x005160d0-0x00516162.ZeroAllocateBufferMemory.md) | `ZeroAllocateBufferMemory(size_t size)` | reconstructable child with formal method C++ | Nonvirtual zero-initializing allocation-policy method; calls `malloc(size)`, throws `new Win32Error` on null, zero-fills the successful block with `memset(buffer, 0, size)`, and returns it. B008 accepts this method form because all 13 direct callers pass `GetMemoryMan()` in `ECX` before calling `0x005160d0`. |
| [UID:0001BF][0x00516170-0x00516184.FreeBufferMemory](by-memory/0x00516170-0x00516184.FreeBufferMemory.md) | `FreeBufferMemory(void *buffer)` | reconstructable child with formal method C++ | Nonvirtual deallocation-policy method; calls `free(buffer)` and returns `0` so callers can free and clear pointer slots. B002 accepts this method form because MCP session `80de0a67` found exact `0x14` / 20-byte body, exact 210 / `0xd2` code xrefs, and representative callers carrying `GetMemoryMan()` in `ECX` before calling `0x00516170`. |
| [UID:0001BG][0x00516190-0x00516210.ReallocateOrThrow](by-memory/0x00516190-0x00516210.ReallocateOrThrow.md) | `ReallocateBufferMemory(void *block, size_t newSize)` | reconstructable child with formal method C++ | Nonvirtual reallocation-policy method; returns `realloc(block, newSize)` on success and throws `new Win32Error` on null. B010 accepts this method form because MCP session `80de0a67` found the exact `0x80` / 128-byte body, exact 10 direct xrefs, and all caller contexts carrying `GetMemoryMan()` in `ECX` before calling `0x00516190`. The historical `ReallocateOrThrow` alias is preserved for trace/search context. |
| [UID:0001BH][0x00516220-0x00516238.MemmoveWrapper](by-memory/0x00516220-0x00516238.MemmoveWrapper.md) | `MemmoveWrapper(void *destination, const void *source, size_t size)` | reconstructable child with formal method C++ | Nonvirtual copy/move helper method; returns `memmove(destination, source, size)`. B006 accepts this method form because MCP session `80de0a67` found the exact 24-byte (`0x18`, Verified with `int_convert.py`) body, internal `_memmove` callee, exact raw PE 604 (`0x25c`, Verified with `int_convert.py`) direct-call fanout, and representative caller `0x004f32e0` carrying `GetMemoryMan()` in `ECX` before calling `0x00516220`. |
| [UID:0001BI][0x00516240-0x00516258.Memmove0Wrapper](by-memory/0x00516240-0x00516258.Memmove0Wrapper.md) | `MoveBufferMemory(void *destination, const void *source, size_t size)` | reconstructable child with formal method C++ | Nonvirtual overlap-safe move helper method; returns `memmove(destination, source, size)`. B009 accepts this method form because MCP session `80de0a67` found the exact 24-byte (`0x18`, Verified with `int_convert.py`) body, internal `_memmove_0` runtime duplicate callee, exact 19 (`0x13`, Verified with `int_convert.py`) direct xrefs, representative callers carrying `GetMemoryMan()` in `ECX` before calling `0x00516240`, and no object-field access or new layout fields. |
| [UID:0001BJ][0x00516260-0x0051628e.MemoryManScalarDeletingDestructor](by-memory/0x00516260-0x0051628e.MemoryManScalarDeletingDestructor.md) | scalar deleting destructor | reconstructable child | Vtable-slot deleting destructor; clears `g_pMemoryMan` and conditionally frees `this`. |

## Key Relationships

- [UID:0000RH][g_pMemoryMan](by-global/g_pMemoryMan.md) at `0x0069b4fc` is set by the constructor, returned by `GetMemoryMan`, and cleared by destructor/reset paths; the exact data page is [UID:0002B0][0x0069b4fc-0x0069b500.g_pMemoryMan](by-memory/0x0069b4fc-0x0069b500.g_pMemoryMan.md).
- [UID:00029R][0x0069b3a8-0x0069b3ac.MemoryManStaticObjectStorage](by-memory/0x0069b3a8-0x0069b3ac.MemoryManStaticObjectStorage.md) is the static `MemoryMan` object storage constructed by [UID:0000WA][0x00419f70-0x00419f86.MemoryManStaticInitializer](by-memory/0x00419f70-0x00419f86.MemoryManStaticInitializer.md).
- [UID:0000T8][MemoryAllocationHelpers](by-global/MemoryAllocationHelpers.md) wrap CRT allocation and throw [UID:0000G7][Win32Error](by-class/Win32Error.md) on failure.
- `operator_new` at `0x004f4aa0` calls `GetMemoryMan` before `AllocateBufferMemory`, making the singleton visible from most heap object construction paths.

## Live IDA Evidence

- 2026-06-04 live IDA MCP names the vtable at `0x0061eb08` as `??_7MemoryMan@@6B@`; the first slot points to `0x00516260`.
- Live xrefs to the vtable come from the constructor at `0x00516000`, the ordinary destructor/reset body at `0x00516010`, and the scalar deleting destructor at `0x0051626a`.
- Live xrefs to `g_pMemoryMan` / `0x0069b4fc` show constructor write `0x00516008`, reset clear `0x00516016`, accessor read `0x00516030`, and destructor clear `0x00516270`.
- Live xrefs to static object storage `0x0069b3a8` show only the static initializer at `0x00419f70` and atexit thunk at `0x0060c260`.
- Live IDA confirms exact modeled starts for the compact memory utility island: constructor `0x00516000-0x0051600f`, ordinary destructor/reset body `0x00516010-0x00516021`, accessor `0x00516030-0x00516036`, allocation helpers `0x00516050-0x00516258`, scalar deleting destructor `0x00516260-0x0051628e`, and neighboring `MenuPane` start at `0x00516290`.
- Live operator wrappers confirm `0x004f4aa0` calls `GetMemoryMan` then `AllocateBufferMemory`, and `0x004f4ac0` calls `GetMemoryMan` then `FreeBufferMemory`.
- Live allocation helper disassembly confirms `malloc` / `memset` / `realloc` paths, `Win32Error` construction through `0x004a60d0`, and C++ exception throws on allocation failure.

## 2026-06-26 B006 Constructor Source-Quality Recheck

B006 current MCP session `80de0a67` reconfirmed the constructor-specific evidence needed to remove the old target no-code blocker:

- `server_health(database=80de0a67)` returned `status:ok` for `NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, with auto-analysis, Hex-Rays, and strings cache ready.
- [UID:0001B9][0x00516000-0x0051600f.MemoryManConstructor](by-memory/0x00516000-0x0051600f.MemoryManConstructor.md) is a 15-byte function (`0x0f`, Verified with `int_convert.py`) with a four-instruction body: `MemoryMan` vptr store through vtable `0x0061eb08`, ABI return move, singleton pointer publication to `0x0069b4fc`, and return.
- The single constructor caller is `0x00419f75` inside [UID:0000WA][0x00419f70-0x00419f86.MemoryManStaticInitializer](by-memory/0x00419f70-0x00419f86.MemoryManStaticInitializer.md), which passes static object storage `0x0069b3a8` as `this` and registers atexit thunk `0x0060c260`.
- The reset/destructor relationship remains separate: [UID:0001O7][0x0060c260-0x0060c26a.MemoryManAtexitResetThunk](by-memory/0x0060c260-0x0060c26a.MemoryManAtexitResetThunk.md) loads the same static storage and jumps to [UID:0001BB][0x00516010-0x00516021.MemoryManDestructor](by-memory/0x00516010-0x00516021.MemoryManDestructor.md), while [UID:0001BJ][0x00516260-0x0051628e.MemoryManScalarDeletingDestructor](by-memory/0x00516260-0x0051628e.MemoryManScalarDeletingDestructor.md) remains the vtable-slot deleting-destructor body.
- Current xrefs preserve the lifecycle model: vtable `0x0061eb08` has exactly constructor/reset/deleting-destructor refs; static object storage `0x0069b3a8` has exactly static-initializer and atexit-thunk refs; singleton pointer storage `0x0069b4fc` has exactly constructor write, reset clear, accessor read, and scalar deleting destructor clear.
- `list_globals *MemoryMan*` returns the `MemoryMan` vtable/RTTI family but no recovered global symbol for `g_pMemoryMan`; `search_structs MemoryMan` and `type_query *MemoryMan*` return no local IDA UDT/type record. The source-facing `g_pMemoryMan` name and one-vptr layout remain inferred from project docs and lifecycle evidence.

The class-page declaration block is now present after the 2026-07-01 B009 empty-emitter callback. Executable constructor source still belongs to the exact by-memory method page [UID:0001B9][0x00516000-0x0051600f.MemoryManConstructor](by-memory/0x00516000-0x0051600f.MemoryManConstructor.md); the class page emits declarations/prototypes only. The remaining class-level uncertainty is exact original header placement/spelling, which caps this class page below final audit.

## 2026-06-26 B007 Accessor Source-Quality Recheck

B007 current MCP session `80de0a67` reconfirmed [UID:0001BC][0x00516030-0x00516036.GetMemoryMan](by-memory/0x00516030-0x00516036.GetMemoryMan.md) as the exact six-byte singleton accessor:

- `lookup_funcs` reports function `sub_516030` at `0x00516030`, size `0x06`, with no function at `0x00516036`, `0x00516040`, or `0x00516045`.
- Disassembly/decompilation reduce the body to `mov eax, [0x0069b4fc]; ret`, returning [UID:0000RH][g_pMemoryMan](by-global/g_pMemoryMan.md).
- Bytes preserve the six-byte body, ten `0xcc` bytes, separate ignored [UID:0003VP][0x00516040-0x00516045.MemoryManNoXrefReturnZeroStub](by-memory/0x00516040-0x00516045.MemoryManNoXrefReturnZeroStub.md), and padding before `0x00516050`.
- `xrefs_to 0x0069b4fc` remains exactly constructor write, reset clear, accessor read, and scalar deleting destructor clear; `xrefs_to 0x00516030` returns broad fanout with `more:true`.
- Operator wrappers call the accessor before allocation/free helpers, but the class method map does not absorb those free-helper/operator bodies.
- Negative evidence remains important: current IDB has `MemoryMan` RTTI/vtable names only, no recovered `GetMemoryMan` symbol, no recovered `g_pMemoryMan` global symbol, no source-file string, no local `MemoryMan` UDT, and no `MemoryMan` type record.

Decision: [UID:0001BC][0x00516030-0x00516036.GetMemoryMan](by-memory/0x00516030-0x00516036.GetMemoryMan.md) is source-ready as a file-level free helper emitted through [UID:0000L7][MemoryMan](by-file/MemoryMan.md). It is not rerouted to this class as `MemoryMan::GetMemoryMan()` because no current symbol/type evidence supports a scoped static method over the accepted file-helper route. This keeps `GetMemoryMan` out of the class method map while allowing later target-specific method decisions such as B008's accepted `MemoryMan::AllocateBufferMemory(size_t size)`.

## 2026-06-26 B008 AllocateBufferMemory Source-Quality Recheck

B008 current MCP session `80de0a67` resolves [UID:0001BD][0x00516050-0x005160ce.AllocateBufferMemory](by-memory/0x00516050-0x005160ce.AllocateBufferMemory.md) as a class-owned method body:

- `lookup_funcs` reports `sub_516050` at `0x00516050`, size `0x7e` / 126 bytes (Verified with int_convert.py), ending before the two-byte padding at `0x005160ce-0x005160d0`.
- The body calls `_malloc(size)` and returns the allocated block on success.
- The failure path allocates an 8-byte (`0x8`, Verified with int_convert.py) `Win32Error` through `sub_4F4AA0`, constructs it through `0x004a60d0`, and throws pointer metadata `__TI4PAVWin32Error@@`; `get_string 0x00674530` returns `.PAVWin32Error@@`.
- `xrefs_to 0x00516050` reports exactly 132 (`0x84`, Verified with int_convert.py) code xrefs with no truncation.
- Source-shape evidence is stronger than Hex-Rays' unused-`this` `__stdcall` display: the global `operator new` wrapper and representative direct callers call `GetMemoryMan()`, move or reload that singleton into `ECX`, push the size argument, then call `0x00516050`.
- The accepted source method is `MemoryMan::AllocateBufferMemory(size_t size)`. The accepted failure expression is `throw new Win32Error;`; `throw Win32Error();` is rejected because the binary throws a pointer type.

This B008 decision is target-specific. It does not weaken B007's file-level `GetMemoryMan` helper route, and it does not mass-reroute sibling helpers whose source forms still need their own target-level audits.

## 2026-06-26 B008 ZeroAllocateBufferMemory Source-Quality Recheck

B008 current MCP session `80de0a67` resolves [UID:0001BE][0x005160d0-0x00516162.ZeroAllocateBufferMemory](by-memory/0x005160d0-0x00516162.ZeroAllocateBufferMemory.md) as a class-owned method body:

- `server_health(database=80de0a67)` returned `status:ok` for `NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, with auto-analysis, Hex-Rays, and strings cache ready.
- `lookup_funcs` reports `sub_5160D0` at `0x005160d0`, size `0x92` / 146 bytes (Verified with `int_convert.py`), ending before `0x00516162`; the next helper [UID:0001BF][0x00516170-0x00516184.FreeBufferMemory](by-memory/0x00516170-0x00516184.FreeBufferMemory.md) begins at `0x00516170`.
- Boundary bytes preserve two `0xcc` bytes at `0x005160ce-0x005160d0` before the target and fourteen `0xcc` bytes (`0xe`, Verified with `int_convert.py`) at `0x00516162-0x00516170` before the free helper.
- The body calls `_malloc(size)`, stores the result, branches to the failure path on null, calls `_memset(buffer, 0, size)` only after successful allocation, returns the original block pointer, and ends with `retn 4`.
- The failure path allocates an 8-byte (`0x8`, Verified with `int_convert.py`) `Win32Error` exception object through `sub_4F4AA0`, constructs it through `0x004a60d0`, and throws pointer metadata `__TI4PAVWin32Error@@`; `get_string 0x00674530` returns `.PAVWin32Error@@`.
- `xrefs_to 0x005160d0` reports exactly 13 (`0xd`, Verified with `int_convert.py`) code xrefs with `more:false`.
- All 13 caller contexts load or preserve a [UID:0001BC][0x00516030-0x00516036.GetMemoryMan](by-memory/0x00516030-0x00516036.GetMemoryMan.md) result in `ECX` before calling `0x005160d0`: representative direct contexts include `0x004ce9e9`, `0x004f30b9`, `0x004f3659`, four sites in `sub_530EE0`, four sites in `sub_533F70`, `0x00553a32`, and `0x005564a2`.
- The accepted source method is `MemoryMan::ZeroAllocateBufferMemory(size_t size)`. The accepted failure expression is `throw new Win32Error;`; `throw Win32Error();`, raw `sub_5160D0`, caller ownership, Error.cpp ownership, independent global direct ownership, and handwritten EH/RTTI/runtime code are rejected.

This B008 decision is target-specific and follows the same unused-`this` ABI reasoning accepted for [UID:0001BD][0x00516050-0x005160ce.AllocateBufferMemory](by-memory/0x00516050-0x005160ce.AllocateBufferMemory.md). It preserves B007's [UID:0001BC][0x00516030-0x00516036.GetMemoryMan](by-memory/0x00516030-0x00516036.GetMemoryMan.md) as a file-level free helper. Later B002, B010, and B006 callbacks resolved [UID:0001BF][0x00516170-0x00516184.FreeBufferMemory](by-memory/0x00516170-0x00516184.FreeBufferMemory.md), [UID:0001BG][0x00516190-0x00516210.ReallocateOrThrow](by-memory/0x00516190-0x00516210.ReallocateOrThrow.md), and [UID:0001BH][0x00516220-0x00516238.MemmoveWrapper](by-memory/0x00516220-0x00516238.MemmoveWrapper.md) by their own target-level audits rather than by B008 mass rerouting.

## 2026-06-26 B002 FreeBufferMemory Source-Quality Recheck

B002 current MCP session `80de0a67` resolves [UID:0001BF][0x00516170-0x00516184.FreeBufferMemory](by-memory/0x00516170-0x00516184.FreeBufferMemory.md) as a class-owned method body:

- `server_health(database=80de0a67)` returned `status:ok` for `NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, with auto-analysis, Hex-Rays, and strings cache ready.
- `lookup_funcs` reports `sub_516170` at `0x00516170`, size `0x14` / 20 bytes (Verified with `int_convert.py`), ending before `0x00516184`; `0x00516162` and `0x00516184` are not functions.
- Disassembly is the exact eight-instruction body `push ebp; mov ebp, esp; push [ebp+Block]; call j___free_base; add esp, 4; xor eax, eax; pop ebp; retn 4`. The only callee is `j___free_base` at `0x005d3547`, a jump stub to `__free_base`.
- Bytes preserve fourteen `0xcc` bytes before the target, the 20 target bytes `55 8b ec ff 75 08 e8 cc d3 0b 00 83 c4 04 33 c0 5d c2 04 00`, twelve `0xcc` bytes after it, and a unique signature for the exact target range.
- `xref_query` reports exactly 210 (`0xd2`, Verified with `int_convert.py`) code xrefs with no continuation. Representative callers include the operator-delete wrapper, `ColorStringChattingMessageDestructorBody`, `ListNonDeletingDestructor`, `UrlAlertPane` destructor, `TextPad::Save`, and `BuildHandshakeBlock`.
- Source-shape evidence is stronger than Hex-Rays' unused-`this` `__stdcall int` display: representative callers call [UID:0001BC][0x00516030-0x00516036.GetMemoryMan](by-memory/0x00516030-0x00516036.GetMemoryMan.md), move or preserve the singleton in `ECX`, pass one stack `buffer` argument, then call `0x00516170`.
- The accepted source method is `MemoryMan::FreeBufferMemory(void *buffer)`. The accepted return expression is `return 0;`, not a status integer, because callers use `EAX` as a null pointer slot value after freeing.
- Negative evidence remains a class/header confidence cap: the current IDB has no recovered `FreeBufferMemory` global/method symbol, no source-file string, no local `MemoryMan` UDT/type record, and only the `MemoryMan` vtable/RTTI family. The report rejects a standalone file-level helper, [UID:0000T8][MemoryAllocationHelpers](by-global/MemoryAllocationHelpers.md) as direct owner/emitter, operator-delete-only/no-code handling, a target-local null guard, raw `sub_516170`/`j___free_base` final names, and using unrelated B012 pointer-slot evidence as proof.

This B002 decision is target-specific and follows the same unused-`this` ABI reasoning accepted for [UID:0001BD][0x00516050-0x005160ce.AllocateBufferMemory](by-memory/0x00516050-0x005160ce.AllocateBufferMemory.md) and [UID:0001BE][0x005160d0-0x00516162.ZeroAllocateBufferMemory](by-memory/0x005160d0-0x00516162.ZeroAllocateBufferMemory.md). It preserves B007's [UID:0001BC][0x00516030-0x00516036.GetMemoryMan](by-memory/0x00516030-0x00516036.GetMemoryMan.md) as a file-level free helper. Later B010 and B006 callbacks resolved [UID:0001BG][0x00516190-0x00516210.ReallocateOrThrow](by-memory/0x00516190-0x00516210.ReallocateOrThrow.md) and [UID:0001BH][0x00516220-0x00516238.MemmoveWrapper](by-memory/0x00516220-0x00516238.MemmoveWrapper.md) by their own target-level audits rather than by B002 mass rerouting.

## 2026-06-26 B010 ReallocateBufferMemory Source-Quality Recheck

B010 current MCP session `80de0a67` resolves [UID:0001BG][0x00516190-0x00516210.ReallocateOrThrow](by-memory/0x00516190-0x00516210.ReallocateOrThrow.md) as a class-owned method body:

- `server_health(database=80de0a67)` returned `status:ok` for `NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, with auto-analysis, Hex-Rays, and strings cache ready; listener `127.0.0.1:13337` was live on PID `13684`, with IDA/MCP worker PID `26892`.
- `lookup_funcs` reports `sub_516190` at `0x00516190`, size `0x80` / 128 bytes (Verified with `int_convert.py`), after twelve `0xcc` bytes at `0x00516184-0x00516190` and before sixteen `0xcc` bytes at `0x00516210-0x00516220`.
- Decompilation/disassembly show `_realloc(block, newSize)`, a null-result branch, success return with `retn 8`, and a failure path that allocates an 8-byte (`0x8`, Verified with `int_convert.py`) `Win32Error`, constructs it through `0x004a60d0`, pushes pointer throw metadata `__TI4PAVWin32Error@@`, and calls `__CxxThrowException@8`.
- `callees` reports only `_realloc`, `sub_4F4AA0`, `sub_4A60D0`, and `__CxxThrowException@8`; the SEH/security-cookie setup and exception runtime artifacts are compiler output and are not emitted in first-draft C++.
- `xrefs_to` / `xref_query` report exactly 10 direct code xrefs with `more:false`: `0x004b6247`, `0x004bb2a6`, `0x004f324d`, `0x004f3285`, `0x004f3354`, `0x004f3476`, `0x004f358a`, `0x004f35ca`, `0x004f3723`, and `0x004f3a26`.
- Representative callers call [UID:0001BC][0x00516030-0x00516036.GetMemoryMan](by-memory/0x00516030-0x00516036.GetMemoryMan.md), move or preserve the singleton in `ECX`, push `newSize` and `block`, and call `0x00516190`; examples include `0x004b6247`, `0x004bb2a6`, `0x004f3285`, `0x004f358a`, `0x004f3723`, and `0x004f3a26`.
- The accepted source method is `MemoryMan::ReallocateBufferMemory(void *block, size_t newSize)`. The historical `ReallocateOrThrow` name remains a target filename/source-queue alias and confidence cap, not the emitted formal API. Rejected alternatives include independent global/free-helper ownership, caller ownership, `MemoryMan::ReallocateOrThrow` as the emitted method name, `throw Win32Error();`, explicit runtime `_CxxThrowException` source, and [UID:0000G7][Win32Error](by-class/Win32Error.md) / `Error.cpp` ownership.
- Negative evidence remains a class/header confidence cap: the current IDB has no recovered decorated `MemoryMan::ReallocateBufferMemory` symbol, no recovered `ReallocateBufferMemory` or `ReallocateOrThrow` symbol, no source-file string, and no local `MemoryMan` UDT/type record.

This B010 decision is target-specific and follows the same unused-`this` ABI reasoning accepted for the allocation/free/memmove method bodies. It preserves B007's [UID:0001BC][0x00516030-0x00516036.GetMemoryMan](by-memory/0x00516030-0x00516036.GetMemoryMan.md) as a file-level free helper. B009 later resolves sibling [UID:0001BI][0x00516240-0x00516258.Memmove0Wrapper](by-memory/0x00516240-0x00516258.Memmove0Wrapper.md) as `MemoryMan::MoveBufferMemory`; global-operator/header declaration shape remains open.

## 2026-06-26 B006 MemmoveWrapper Source-Quality Recheck

B006 current MCP session `80de0a67` resolves [UID:0001BH][0x00516220-0x00516238.MemmoveWrapper](by-memory/0x00516220-0x00516238.MemmoveWrapper.md) as a class-owned method body:

- `server_health(database=80de0a67)` returned `status:ok` for `NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, with auto-analysis, Hex-Rays, and strings cache ready.
- `lookup_funcs` reports `sub_516220` at `0x00516220`, size `0x18` / 24 bytes (Verified with `int_convert.py`), ending before the eight `0xcc` padding bytes at `0x00516238-0x00516240` and sibling [UID:0001BI][0x00516240-0x00516258.Memmove0Wrapper](by-memory/0x00516240-0x00516258.Memmove0Wrapper.md).
- Disassembly/decompilation show a one-basic-block wrapper that pushes `size`, `source`, and `destination`, calls internal `_memmove` at `0x005c95b0`, returns with `retn 0Ch`, and reduces to `return memmove(destination, source, size);`.
- `_memmove` is an internal executable function/static runtime helper, not a dynamic import route or no-code IAT alias.
- Raw PE rel32 scanning gives the exact direct-call fanout as 604 (`0x25c`, Verified with `int_convert.py`), while sibling [UID:0001BI][0x00516240-0x00516258.Memmove0Wrapper](by-memory/0x00516240-0x00516258.Memmove0Wrapper.md) has 19 (`0x13`, Verified with `int_convert.py`) direct callers. B006 recorded that sibling relationship only; B009 later resolves [UID:0001BI][0x00516240-0x00516258.Memmove0Wrapper](by-memory/0x00516240-0x00516258.Memmove0Wrapper.md) as `MemoryMan::MoveBufferMemory`.
- Source-shape evidence is stronger than Hex-Rays' unused-`this` display: representative caller `0x004f32e0` calls [UID:0001BC][0x00516030-0x00516036.GetMemoryMan](by-memory/0x00516030-0x00516036.GetMemoryMan.md), preserves the singleton, reloads it into `ECX`, pushes the three explicit copy arguments, and calls `0x00516220`.
- Rejected alternatives remain documented on the child page: direct file-level free helper ownership, CRT/runtime/no-code routing, feature-caller ownership, merging with [UID:0001BI][0x00516240-0x00516258.Memmove0Wrapper](by-memory/0x00516240-0x00516258.Memmove0Wrapper.md) or the destructor wrapper, and unsupported names such as `CopyBytes`, `CopyMemory`, or `MoveMemory`.

The accepted source method is `MemoryMan::MemmoveWrapper(void *destination, const void *source, size_t size)`. This decision is target-specific and follows the same unused-`this` ABI reasoning accepted for [UID:0001BD][0x00516050-0x005160ce.AllocateBufferMemory](by-memory/0x00516050-0x005160ce.AllocateBufferMemory.md), [UID:0001BE][0x005160d0-0x00516162.ZeroAllocateBufferMemory](by-memory/0x005160d0-0x00516162.ZeroAllocateBufferMemory.md), and [UID:0001BF][0x00516170-0x00516184.FreeBufferMemory](by-memory/0x00516170-0x00516184.FreeBufferMemory.md). It preserves B007's [UID:0001BC][0x00516030-0x00516036.GetMemoryMan](by-memory/0x00516030-0x00516036.GetMemoryMan.md) as a file-level free helper. B009 later resolves paired sibling [UID:0001BI][0x00516240-0x00516258.Memmove0Wrapper](by-memory/0x00516240-0x00516258.Memmove0Wrapper.md) as the distinct method `MemoryMan::MoveBufferMemory`, preserving the shared MemoryMan ownership while using a semantic name for the smaller overlap/tail-move call family.

## 2026-06-26 B009 MoveBufferMemory Source-Quality Recheck

B009 current MCP session `80de0a67` resolves [UID:0001BI][0x00516240-0x00516258.Memmove0Wrapper](by-memory/0x00516240-0x00516258.Memmove0Wrapper.md) as a class-owned method body:

- MCP `server_health(database=80de0a67)` returned `status:ok` for `NexusTK.exe.i64`, with auto-analysis, Hex-Rays, and strings cache ready.
- `lookup_funcs` reports `sub_516240` at `0x00516240`, size `0x18` / 24 bytes (Verified with `int_convert.py`), ending before eight `0xcc` padding bytes at `0x00516258-0x00516260`; paired [UID:0001BH][0x00516220-0x00516238.MemmoveWrapper](by-memory/0x00516220-0x00516238.MemmoveWrapper.md) is the separate 24-byte wrapper at `0x00516220`.
- Boundary bytes preserve 16 `0xcc` bytes before [UID:0001BH][0x00516220-0x00516238.MemmoveWrapper](by-memory/0x00516220-0x00516238.MemmoveWrapper.md), eight bytes between the siblings, the exact [UID:0001BI][0x00516240-0x00516258.Memmove0Wrapper](by-memory/0x00516240-0x00516258.Memmove0Wrapper.md) body, and eight bytes before the scalar deleting destructor.
- Disassembly/decompilation show a one-basic-block wrapper that pushes `size`, `source`, and `destination`, calls internal runtime duplicate `_memmove_0` at `0x005c9b30`, adjusts the stack, and returns with `retn 0Ch`; formal source therefore calls standard `memmove(destination, source, size)`, not the IDA/runtime duplicate name.
- MCP `xrefs_to 0x00516240` returns exactly 19 (`0x13`, Verified with `int_convert.py`) direct code xrefs with no continuation. Representative callers in list insertion/removal, text edit, SoundManager, and ObjectList paths load or preserve [UID:0001BC][0x00516030-0x00516036.GetMemoryMan](by-memory/0x00516030-0x00516036.GetMemoryMan.md) in `ECX` before calling `0x00516240`.
- The body does not dereference `this`, and no new `MemoryMan` fields are implied. The method belongs to the existing one-vptr singleton layout as an unused-`this` helper, matching the accepted allocation/free/realloc/memmove method pattern.
- Naming remains intentionally asymmetric with [UID:0001BH][0x00516220-0x00516238.MemmoveWrapper](by-memory/0x00516220-0x00516238.MemmoveWrapper.md): B006 accepts the broad 604-call sibling as `MemoryMan::MemmoveWrapper`, while B009 uses `MemoryMan::MoveBufferMemory` for this 19-call overlap/tail-move sibling because the caller semantics are clearer than raw `_memmove_0` symmetry. Future name unification should preserve the direct owner/emitter [UID:00007U][MemoryMan](by-class/MemoryMan.md), the exact child ranges, the standard `memmove` behavior, and the distinction that [UID:0001BI][0x00516240-0x00516258.Memmove0Wrapper](by-memory/0x00516240-0x00516258.Memmove0Wrapper.md) is the overlap/tail-move helper.

Rejected alternatives for the class map remain direct CRT/no-code handling, a separate CRT-wrapper file, file-level free helper ownership, feature-caller ownership, raw names such as `Memmove0Wrapper`, `memmove_0`, or `_memmove_0`, and `MemoryMan::MoveMemory` because the Windows macro/API spelling is less safe than the local `BufferMemory` convention.

## 2026-06-26 B009 Destructor Source-Quality Recheck

B009 current MCP session `80de0a67` resolves [UID:0001BB][0x00516010-0x00516021.MemoryManDestructor](by-memory/0x00516010-0x00516021.MemoryManDestructor.md) as the source-ready ordinary destructor body:

- `server_health(database=80de0a67)` returned `status:ok` for `NexusTK.exe.i64`, with auto-analysis, Hex-Rays, and strings cache ready.
- The target is the exact 17-byte (`0x11`, Verified with `int_convert.py`) tail at `0x00516010-0x00516021`: vptr store through `MemoryMan::vftable`, `g_pMemoryMan` clear at `0x00516016`, and `retn` at `0x00516020`, followed by fifteen `0xcc` bytes at `0x00516021-0x00516030`.
- The atexit relationship is preserved: [UID:0000WA][0x00419f70-0x00419f86.MemoryManStaticInitializer](by-memory/0x00419f70-0x00419f86.MemoryManStaticInitializer.md) constructs static storage `0x0069b3a8` / `g_staticMemoryManObject` and registers [UID:0001O7][0x0060c260-0x0060c26a.MemoryManAtexitResetThunk](by-memory/0x0060c260-0x0060c26a.MemoryManAtexitResetThunk.md); the thunk loads that static object as `this` and jumps to the ordinary destructor tail.
- Current xrefs remain the narrow class-lifecycle set: one code edge to `0x00516010` from `0x0060c265`, one registration xref to `0x0060c260` from `0x00419f7a`, vtable `0x0061eb08` refs from constructor/ordinary destructor/scalar deleting destructor, static-object refs from initializer/thunk, and [UID:0000RH][g_pMemoryMan](by-global/g_pMemoryMan.md) refs from constructor write, ordinary destructor clear, accessor read, and scalar deleting destructor clear.
- Source-form decision: the accepted formal C++ is `MemoryMan::~MemoryMan() { g_pMemoryMan = 0; }`. The vptr store is compiler destructor lowering, not source; [UID:0001O7][0x0060c260-0x0060c26a.MemoryManAtexitResetThunk](by-memory/0x0060c260-0x0060c26a.MemoryManAtexitResetThunk.md) is compiler/static-lifetime glue, not handwritten project logic; and [UID:0001BJ][0x00516260-0x0051628e.MemoryManScalarDeletingDestructor](by-memory/0x00516260-0x0051628e.MemoryManScalarDeletingDestructor.md) remains the separate compiler wrapper with optional delete-flag behavior.
- Negative evidence remains a class/header confidence cap: current IDB has `MemoryMan` RTTI/vtable names only, no recovered `g_pMemoryMan`, `GetMemoryMan`, or static-object global symbol, no local `MemoryMan` UDT, and no `MemoryMan` type record. The class page keeps blank class-level C++ because final declaration factoring is still open, not because the exact ordinary destructor child is unresolved.

## Reconstruction Caveats

`MemoryMan` is a real project singleton and allocation-policy anchor. This page now emits its declaration/prototypes through `MemoryMan.h` and only the corresponding include through CPP. Do not duplicate child method bodies here, do not add file-level `GetMemoryMan()` as a class method, and do not add global `operator new/delete` as class members. Exact original header spelling remains a final-audit confidence cap, but no longer justifies a CPP-local declaration or blank H block.

Do not infer that `MemoryMan` only has one source-level method from any single emitted class body. Use the IDA-backed memory docs for class/file reconstruction. The earlier CPP-local declaration is preserved as superseded source-shape history; a shared header is required by `RingBuffer.cpp` and the independent MemoryMan method definitions.

## 2026-07-01 B009 Empty-Emitter Family Implementation

B009 resolves the class-page empty marker from the accepted [UID:0000L7][MemoryMan](by-file/MemoryMan.md) empty-emitter family report. The formal class declaration/prototype block is source-ready because accepted child pages already define constructor, ordinary destructor, allocation/free/reallocation, and copy/move behavior, while current IDA/MCP evidence ties the family to the `MemoryMan` RTTI/vtable route.

Evidence preserved from the report: vtable `0x0061eb08` has refs from constructor/reset/scalar deleting destructor; static object storage is `0x0069b3a8`; singleton pointer storage is `0x0069b4fc`; the observed binary layout is one vptr; and no recovered IDA UDT/type record or original source symbols for `GetMemoryMan`, `g_pMemoryMan`, or the static object were found. `GetMemoryMan` remains a file-level free helper through [UID:0000L7][MemoryMan](by-file/MemoryMan.md), and [UID:000196][0x004f4aa0-0x004f4ab4.OperatorNewWrapper](by-memory/0x004f4aa0-0x004f4ab4.OperatorNewWrapper.md)/[UID:000197][0x004f4ac0-0x004f4b00.OperatorDeleteWrapper](by-memory/0x004f4ac0-0x004f4b00.OperatorDeleteWrapper.md) remain global operator wrappers in the same file family.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 91 | The page records parent file attachment, live vtable/global/static-object evidence, class lifecycle method map, accepted child method C++ readiness, singleton allocation/copy helper relationships, operator wrapper links, utility island boundaries, reconstruction constraints, and now a formal class declaration/prototype block. |
| Confidence | 91 | Confidence is strong because current MCP ties constructor/reset/accessor/destructor behavior and source-declared data to `MemoryMan`, accepted reports resolve all exact method bodies, and the class declaration avoids duplicating file-level helpers/operators. It remains below final-source level because exact original header placement/spelling and global helper declarations are inferred. |
| Reconstructable | true | This is NexusTK-owned utility source behavior. Class-level C++ now emits declarations/prototypes only; method-body C++ remains on exact children such as [UID:0001B9][0x00516000-0x0051600f.MemoryManConstructor](by-memory/0x00516000-0x0051600f.MemoryManConstructor.md), [UID:0001BB][0x00516010-0x00516021.MemoryManDestructor](by-memory/0x00516010-0x00516021.MemoryManDestructor.md), [UID:0001BD][0x00516050-0x005160ce.AllocateBufferMemory](by-memory/0x00516050-0x005160ce.AllocateBufferMemory.md), [UID:0001BE][0x005160d0-0x00516162.ZeroAllocateBufferMemory](by-memory/0x005160d0-0x00516162.ZeroAllocateBufferMemory.md), [UID:0001BF][0x00516170-0x00516184.FreeBufferMemory](by-memory/0x00516170-0x00516184.FreeBufferMemory.md), [UID:0001BG][0x00516190-0x00516210.ReallocateOrThrow](by-memory/0x00516190-0x00516210.ReallocateOrThrow.md), [UID:0001BH][0x00516220-0x00516238.MemmoveWrapper](by-memory/0x00516220-0x00516238.MemmoveWrapper.md), and [UID:0001BI][0x00516240-0x00516258.Memmove0Wrapper](by-memory/0x00516240-0x00516258.Memmove0Wrapper.md). |

## Cross-References

- [UID:0000L7][MemoryMan](by-file/MemoryMan.md)
- [UID:0000RH][g_pMemoryMan](by-global/g_pMemoryMan.md)
- [UID:0000T8][MemoryAllocationHelpers](by-global/MemoryAllocationHelpers.md)
- [UID:0001V4][MemoryManLayout](by-type/by-struct/MemoryManLayout.md)
- [UID:0001BA][0x00516000-0x0051628e.MemoryManAndAllocationHelpers](by-memory/0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md)
- [UID:0001BF][0x00516170-0x00516184.FreeBufferMemory](by-memory/0x00516170-0x00516184.FreeBufferMemory.md)
- [UID:0001BI][0x00516240-0x00516258.Memmove0Wrapper](by-memory/0x00516240-0x00516258.Memmove0Wrapper.md)
- [UID:0000WA][0x00419f70-0x00419f86.MemoryManStaticInitializer](by-memory/0x00419f70-0x00419f86.MemoryManStaticInitializer.md)
- [UID:00029R][0x0069b3a8-0x0069b3ac.MemoryManStaticObjectStorage](by-memory/0x0069b3a8-0x0069b3ac.MemoryManStaticObjectStorage.md)
- [UID:0002B0][0x0069b4fc-0x0069b500.g_pMemoryMan](by-memory/0x0069b4fc-0x0069b500.g_pMemoryMan.md)
- [UID:0000J5][Error](by-file/Error.md)
- [UID:0000G7][Win32Error](by-class/Win32Error.md)

## Changes

- 2026-07-31 B006 UID0001G4 dependency-route callback:
  - Replaced the CPP-local class declaration with exact `#include "MemoryMan.h"` and moved the complete declaration/prototype block into H with `<stddef.h>`.
  - Preserved all accepted constructor/destructor/allocation/free/reallocation/copy/move methods, kept `GetMemoryMan()` as a free helper emitted after the class, and retained global operators outside the class.
  - Added the `MemoryMan.cpp` / `MemoryMan.h` source route required by the RingBuffer consumer without changing score, owner, method bodies, or allocator semantics.
- 2026-07-01 B009 MemoryMan empty-emitter family implementation:
  - Score changed from `COMPLETION:89`, `CONFIDENCE:90` to `COMPLETION:91`, `CONFIDENCE:91`.
  - Inserted formal class declaration/prototype C++ for `MemoryMan`, including constructor, virtual destructor, allocation/free/reallocation, and copy/move methods. Exact method bodies remain on child pages.
  - Preserved source-placement decisions: `GetMemoryMan` stays a file-level free helper; global `operator new/delete` stay global wrappers; no duplicate method bodies or duplicate helper/operator declarations were added here.
- 2026-06-26 B009 MoveBufferMemory implementation callback:
  - Score remains `COMPLETION:89`, `CONFIDENCE:90`; preserved `CANONICAL_OWNER:0000L7`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000L7`, blank `EMITTER_POSITION_OPTIONAL`, and blank class formal C++.
  - Summary/evidence: [UID:0001BI][0x00516240-0x00516258.Memmove0Wrapper](by-memory/0x00516240-0x00516258.Memmove0Wrapper.md) now emits formal `MemoryMan::MoveBufferMemory(void *destination, const void *source, size_t size)` C++ on the child page after MCP session `80de0a67` reconfirmed exact `0x18` / 24-byte size (Verified with `int_convert.py`), island padding before/after, internal `_memmove_0` runtime duplicate callee at `0x005c9b30`, exact 19 (`0x13`, Verified with `int_convert.py`) direct code xrefs, representative `GetMemoryMan()`-to-`ECX` caller protocol, overlap/tail-move caller semantics, [UID:0001BH][0x00516220-0x00516238.MemmoveWrapper](by-memory/0x00516220-0x00516238.MemmoveWrapper.md) sibling relationship, naming rationale, and rejected alternatives. No `MemoryMan` fields are added; this is an unused-`this` nonvirtual method body.
- 2026-06-26 B010 ReallocateBufferMemory implementation callback:
  - Score remains `COMPLETION:89`, `CONFIDENCE:90`; preserved `CANONICAL_OWNER:0000L7`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000L7`, blank `EMITTER_POSITION_OPTIONAL`, and blank class formal C++.
  - Summary/evidence: [UID:0001BG][0x00516190-0x00516210.ReallocateOrThrow](by-memory/0x00516190-0x00516210.ReallocateOrThrow.md) now emits formal `MemoryMan::ReallocateBufferMemory(void *block, size_t newSize)` C++ on the child page after MCP session `80de0a67` reconfirmed exact `0x80` / 128-byte size (Verified with `int_convert.py`), twelve-byte pre-padding, sixteen-byte post-padding, `_realloc` success path, pointer `throw new Win32Error` failure path, exact 10 direct code xrefs, all caller contexts passing `GetMemoryMan()` in `ECX`, and negative recovered-symbol/type evidence. The historical `ReallocateOrThrow` name remains an alias/confidence cap; B007's accessor free-helper route and B009's accepted [UID:0001BI][0x00516240-0x00516258.Memmove0Wrapper](by-memory/0x00516240-0x00516258.Memmove0Wrapper.md) `MoveBufferMemory` sibling state are preserved.
- 2026-06-26 B006 MemmoveWrapper implementation callback:
  - Score remains `COMPLETION:89`, `CONFIDENCE:90`; preserved `CANONICAL_OWNER:0000L7`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000L7`, blank `EMITTER_POSITION_OPTIONAL`, and blank class formal C++.
  - Summary/evidence: [UID:0001BH][0x00516220-0x00516238.MemmoveWrapper](by-memory/0x00516220-0x00516238.MemmoveWrapper.md) now emits formal `MemoryMan::MemmoveWrapper(void *destination, const void *source, size_t size)` C++ on the child page after MCP session `80de0a67` reconfirmed exact `0x18` / 24-byte size (Verified with `int_convert.py`), eight-byte padding before [UID:0001BI][0x00516240-0x00516258.Memmove0Wrapper](by-memory/0x00516240-0x00516258.Memmove0Wrapper.md), internal `_memmove` callee at `0x005c95b0` rather than a dynamic import, exact raw PE 604 (`0x25c`, Verified with `int_convert.py`) direct-call fanout, representative `GetMemoryMan()`-to-`ECX` caller protocol at `0x004f32e0`, and negative recovered-symbol/type evidence. B009 later resolves [UID:0001BI][0x00516240-0x00516258.Memmove0Wrapper](by-memory/0x00516240-0x00516258.Memmove0Wrapper.md) as `MemoryMan::MoveBufferMemory`.
- 2026-06-26 B002 FreeBufferMemory implementation callback:
  - Changed score to `COMPLETION:89`, `CONFIDENCE:90`; preserved `CANONICAL_OWNER:0000L7`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000L7`, blank `EMITTER_POSITION_OPTIONAL`, and blank class formal C++.
  - Summary/evidence: [UID:0001BF][0x00516170-0x00516184.FreeBufferMemory](by-memory/0x00516170-0x00516184.FreeBufferMemory.md) now emits formal `MemoryMan::FreeBufferMemory(void *buffer)` C++ on the child page after MCP session `80de0a67` reconfirmed exact `0x14` / 20-byte size (Verified with `int_convert.py`), padding/signature bytes, single `j___free_base` / `__free_base` callee, exact 210 (`0xd2`, Verified with `int_convert.py`) code xrefs, representative `GetMemoryMan()`-to-`ECX` caller protocol, zero-return pointer-field clearing, and negative recovered-symbol/type evidence. B007's accessor free-helper route is preserved; B002 did not itself reroute any sibling page, while later sibling-specific callbacks may resolve those pages independently.
- 2026-06-26 B008 ZeroAllocateBufferMemory implementation callback:
  - Score remains `COMPLETION:88`, `CONFIDENCE:90`; preserved `CANONICAL_OWNER:0000L7`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000L7`, blank `EMITTER_POSITION_OPTIONAL`, and blank class formal C++.
  - Summary/evidence: [UID:0001BE][0x005160d0-0x00516162.ZeroAllocateBufferMemory](by-memory/0x005160d0-0x00516162.ZeroAllocateBufferMemory.md) now emits formal `MemoryMan::ZeroAllocateBufferMemory(size_t size)` C++ on the child page after MCP session `80de0a67` reconfirmed exact `0x92` / 146-byte size (Verified with `int_convert.py`), two-byte pre-padding, fourteen-byte post-padding, `_malloc` and `_memset(buffer, 0, size)` success path, pointer `throw new Win32Error` failure path, exact 13 (`0xd`, Verified with `int_convert.py`) code xrefs, and all caller contexts loading `GetMemoryMan()` into `ECX`. B007's [UID:0001BC][0x00516030-0x00516036.GetMemoryMan](by-memory/0x00516030-0x00516036.GetMemoryMan.md) file-level free-helper route is preserved; later B002/B010/B006/B009 callbacks resolve the sibling free/reallocation/copy helpers by their own target-level audits.
- 2026-06-26 B009 implementation callback:
  - Score remains `COMPLETION:88`, `CONFIDENCE:90`; preserved `CANONICAL_OWNER:0000L7`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000L7`, blank `EMITTER_POSITION_OPTIONAL`, and blank class formal C++.
  - Summary/evidence: current MCP session `80de0a67` reconfirmed [UID:0001BB][0x00516010-0x00516021.MemoryManDestructor](by-memory/0x00516010-0x00516021.MemoryManDestructor.md)'s exact 17-byte ordinary destructor tail, `g_pMemoryMan` clear at `0x00516016`, fifteen-byte post-tail padding, atexit thunk/static-object relationship, vtable/static-object/global xrefs, scalar deleting destructor separation, and negative recovered-symbol/type evidence. The ordinary destructor method-body C++ now lives on [UID:0001BB][0x00516010-0x00516021.MemoryManDestructor](by-memory/0x00516010-0x00516021.MemoryManDestructor.md); this class page remains the class/header inventory and keeps C++ blank until declaration factoring is accepted.
- 2026-06-26 B008 implementation callback:
  - Score remains `COMPLETION:88`, `CONFIDENCE:90`; preserved `CANONICAL_OWNER:0000L7`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000L7`, blank `EMITTER_POSITION_OPTIONAL`, and blank class formal C++.
  - Summary/evidence: current MCP session `80de0a67` reconfirmed [UID:0001BD][0x00516050-0x005160ce.AllocateBufferMemory](by-memory/0x00516050-0x005160ce.AllocateBufferMemory.md)'s exact `0x7e` / 126-byte function (Verified with int_convert.py), padding boundary, 132 (`0x84`, Verified with int_convert.py) code xrefs, `malloc(size)` success path, `throw new Win32Error` pointer-throw failure path, and `GetMemoryMan()`-to-`ECX` caller protocol. The allocation method formal C++ now lives on [UID:0001BD][0x00516050-0x005160ce.AllocateBufferMemory](by-memory/0x00516050-0x005160ce.AllocateBufferMemory.md) as `MemoryMan::AllocateBufferMemory(size_t size)`. B007's [UID:0001BC][0x00516030-0x00516036.GetMemoryMan](by-memory/0x00516030-0x00516036.GetMemoryMan.md) free-helper route is preserved.
- 2026-06-26 B007 implementation callback:
  - Score remains `COMPLETION:88`, `CONFIDENCE:90`; preserved `CANONICAL_OWNER:0000L7`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000L7`, blank `EMITTER_POSITION_OPTIONAL`, and blank class formal C++.
  - Summary/evidence: current MCP session `80de0a67` reconfirmed [UID:0001BC][0x00516030-0x00516036.GetMemoryMan](by-memory/0x00516030-0x00516036.GetMemoryMan.md)'s six-byte body, exact bytes/padding/stub boundary, singleton pointer `0x0069b4fc`, broad fanout, operator-wrapper relationship, and absence of recovered helper/global/source-file/type symbols. The accessor formal C++ now lives on [UID:0001BC][0x00516030-0x00516036.GetMemoryMan](by-memory/0x00516030-0x00516036.GetMemoryMan.md) as a file-level helper through [UID:0000L7][MemoryMan](by-file/MemoryMan.md); it is not added to this class method map because no scoped symbol, `this` route, UDT, or type evidence supports `MemoryMan::GetMemoryMan()` over the accepted free-helper source form.
- 2026-06-26 B006 implementation callback:
  - Changed to: `COMPLETION:88`, `CONFIDENCE:90`; preserved `CANONICAL_OWNER:0000L7`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000L7`, blank `EMITTER_POSITION_OPTIONAL`, and blank class formal C++.
  - Summary/evidence: current MCP session `80de0a67` reconfirmed [UID:0001B9][0x00516000-0x0051600f.MemoryManConstructor](by-memory/0x00516000-0x0051600f.MemoryManConstructor.md)'s 15-byte constructor body, caller `0x00419f75`, vtable `0x0061eb08`, singleton pointer `0x0069b4fc`, static storage `0x0069b3a8`, reset/destructor separation, absence of a local `MemoryMan` UDT/type record, and absence of a recovered `g_pMemoryMan` global symbol. The constructor method-body C++ now lives on [UID:0001B9][0x00516000-0x0051600f.MemoryManConstructor](by-memory/0x00516000-0x0051600f.MemoryManConstructor.md); this class page remains the class/header inventory and keeps C++ blank until declaration factoring is accepted.
- 2026-06-16 B001 source-split audit: method map now routes [UID:0001B9][0x00516000-0x0051600f.MemoryManConstructor](by-memory/0x00516000-0x0051600f.MemoryManConstructor.md), [UID:0001BB][0x00516010-0x00516021.MemoryManDestructor](by-memory/0x00516010-0x00516021.MemoryManDestructor.md), and [UID:0001BJ][0x00516260-0x0051628e.MemoryManScalarDeletingDestructor](by-memory/0x00516260-0x0051628e.MemoryManScalarDeletingDestructor.md) as class lifecycle bodies. File-level allocation/copy helpers remain in [UID:0000L7][MemoryMan](by-file/MemoryMan.md).
- Completion/confidence score update: existed before as `0/0`; changed to `82/76`. Summary: the singleton memory manager and neighboring allocation helpers are well mapped, including constructor/reset/accessor paths, but confidence is capped by the question of how useful the original `MemoryMan` class abstraction was versus nearby free helper ownership. Evidence: linked memory-manager/allocation range, static initializer, atexit reset thunk/tail, `g_pMemoryMan`, layout note, and reconstruction caveats.
- Reconstructable metadata: existed before as blank; changed to `TRUE`. Summary: IDA confirms `MemoryMan` as NexusTK-owned source-level singleton state and helper-family anchor that must be represented in the rebuilt utility layer. Parent UID and C++ reconstruction remain blank because the final source shape, global operator placement, and exact original class/header form are below the `95+` final-source gate.
- 2026-06-04 live IDA refresh:
  - Changed to: `COMPLETION:86`, `CONFIDENCE:88`, and `AUTOGEN_PARENT_UID:0000L7`.
  - Evidence: live IDA MCP confirmed the named `MemoryMan` vtable at `0x0061eb08`, vtable xrefs from constructor/reset/destructor paths, `g_pMemoryMan` write/read/clear sites, static object xrefs, compact utility-island boundaries, operator new/delete calls through `GetMemoryMan`, allocation failure throw paths, and parent ownership under [UID:0000L7][MemoryMan](by-file/MemoryMan.md).
  - Remaining limits at that time: class-level C++ was blank because global operator placement, exact helper/header spelling, and final declarations were below the final-source threshold. Superseded by the 2026-07-01 B009 empty-emitter implementation, which adds the class declaration/prototype block while keeping exact method bodies on child pages.
