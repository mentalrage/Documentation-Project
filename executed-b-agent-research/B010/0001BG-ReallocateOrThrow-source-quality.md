** TARGET-REPORT-UID:0001BG **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B010 report: [UID:0001BG] ReallocateOrThrow source-quality recheck

Assignment: `B010-report-0001BG-reallocate-or-throw-source-quality-20260626`

Target: [UID:0001BG] `by-memory/0x00516190-0x00516210.ReallocateOrThrow.md`

Mode: report-only research first. No target/support by-* docs, generated files, project-level files, manual coverage reports, validator/tool-state files, leases, or IDA DB files were edited. IDA MCP evidence was required and was obtained live; this report does not rely on fallback-only evidence.

## Result

[UID:0001BG] is implementation-ready under the same allocation-family source-shape rule accepted for [UID:0001BD] `AllocateBufferMemory`.

Recommended source disposition:

- Direct semantic owner/emitter: [UID:00007U] `MemoryMan`.
- Source file route: [UID:0000L7] `NexusTK/util/MemoryMan.cpp`.
- Best first-draft source API: `MemoryMan::ReallocateBufferMemory(void *block, size_t newSize)`.
- Historical/source-queue alias to preserve as a confidence cap: `ReallocateOrThrow`.
- Failure source expression: `throw new Win32Error;`.
- Target path/UID: keep the assigned target path for this implementation pass; update the page text to state that `ReallocateOrThrow` is a historical alias and that the formal source API is `MemoryMan::ReallocateBufferMemory`.

Recommended target metadata:

```text
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007U | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007U | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Formal C++ to insert:

```cpp
void *MemoryMan::ReallocateBufferMemory(void *block, size_t newSize)
{
    void *newBlock = realloc(block, newSize);
    if (newBlock == NULL) {
        throw new Win32Error;
    }
    return newBlock;
}
```

Do not keep the formal C++ blank for the old "final helper API/source shape unresolved" blocker. Current live MCP caller evidence resolves the file-level-vs-method question for this target. Do not route the body to `Error.cpp`, a caller page, or an independent free helper.

## Live MCP Session

Live IDA MCP was available and responsive. No MCP process was started, stopped, restarted, or otherwise managed.

- Read-only status check time: `2026-06-26T17:22:13.2572536-04:00`.
- Endpoint: `http://127.0.0.1:13337/mcp`.
- Listener/process status: `Get-NetTCPConnection` showed `127.0.0.1:13337` in `Listen` state on PID `13684`; visible processes included `idalib-mcp` PID `17084`, listener Python PID `13684`, and worker Python PID `26892`.
- `initialize` returned server `ida-pro-mcp` version `1.0.0`, protocol `2025-06-18`.
- `idb_list` reported active session `80de0a67`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, backend `worker`, worker PID `26892`, `is_analyzing:false`.
- `server_health(database=80de0a67)` returned `status:ok`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, strings cache size `2067`.
- Read-only MCP tools used: `lookup_funcs`, `decompile`, `disasm`, `get_bytes`, `xrefs_to`, `xref_query`, `callees`, `analyze_function`, `insn_query`, `entity_query`, `get_string`, `type_query`, `search_structs`, and `int_convert`.

## Current Target State

Current target metadata:

- `COMPLETION:85`
- `CONFIDENCE:88`
- `CANONICAL_OWNER:0000L7`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000L7`
- blank formal C++

The current page correctly records the central behavior: `realloc(block, newSize)` followed by the same allocation-failure `Win32Error` throw path used by allocation siblings. The remaining defects are source-level disposition:

- It treats the helper as a file-level/global allocation helper.
- It leaves formal C++ blank because final API spelling, exception declaration shape, and source placement were unresolved.
- It does not incorporate the accepted [UID:0001BD] method-route precedent or the current caller `GetMemoryMan()` to `ECX` evidence for this exact target.

## Documentation Evidence Checked

Checked target and support docs:

- [UID:0001BG] target page.
- [UID:0000L7] `by-file/MemoryMan.md`.
- [UID:00007U] `by-class/MemoryMan.md`.
- [UID:0000T8] `by-global/MemoryAllocationHelpers.md` (the goal text's `[UID:0001B5]` reference appears to mean this helper-family page).
- [UID:0001BA] `by-memory/0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md`.
- Sibling target pages [UID:0001BD] `AllocateBufferMemory`, [UID:0001BE] `ZeroAllocateBufferMemory`, and [UID:0001BF] `FreeBufferMemory`.
- Accepted executed B-agent reports B007 [UID:0001BC], B008 [UID:0001BD], and B015 [UID:00018S] where they bear on `GetMemoryMan`, `AllocateBufferMemory`, and `FreeBufferMemory` source-facing method syntax.
- `by-project-structure/proposed-source-tree.md` for historical MemoryMan family placement. This is project-level and must not be edited in the current implementation scope.
- `by-memory/-report.old.md` historical Wave2 row for `0x00516190`, which records `ReallocateOrThrow` as a global/restored name. This is historical source-queue context, not current MCP authority.
- Current generated artifacts were read only: `auto-generated/NexusTK/util/MemoryMan.cpp`, `auto-generated/-ag-research-tracker.md`, and `auto-generated/-ag-coverage-report-by-memory.md`.

Generated-state caveat:

- Current generated `MemoryMan.cpp` still has an empty emitter marker for [UID:0001BG] with stale `78/86` metadata.
- Current generated tracker and generated coverage also still show stale `78/86` rows for [UID:0001BG].
- Do not manually edit generated or coverage files. If this report is accepted for implementation, scoped validators and generated refresh should reconcile those rows from the source docs.

## Boundary Evidence

Live MCP confirms the target range exactly:

| Query | Result |
| --- | --- |
| `0x00516184` through `0x0051618f` | not functions; direct bytes are twelve `0xcc` bytes before the target |
| `0x00516190` | function `sub_516190`, size `0x80` / 128 bytes (Verified with `int_convert.py`) |
| `0x00516210` | not a function; direct bytes at `0x00516210-0x00516220` are sixteen `0xcc` bytes (Verified with `int_convert.py`) |
| `0x00516220` | successor function `sub_516220`, size `0x18` / 24 bytes (Verified with `int_convert.py`) |

Direct byte checks:

- `get_bytes 0x00516184 size 12`: twelve `0xcc` bytes before the target.
- `get_bytes 0x00516190 size 16`: starts with `55 8b ec 6a ff 68 e7 30 60 00 64 a1 00 00 00 00`, the normal prologue and SEH setup.
- `get_bytes 0x00516200 size 32`: includes the throw call tail ending at `0x0051620b`, then sixteen `0xcc` bytes from `0x00516210-0x00516220`.

No split/range repair is required.

## Body Evidence

Live `decompile 0x00516190` reports:

```c
void *__stdcall sub_516190(void *Block, size_t pExceptionObject)
{
  void *result;

  result = realloc(Block, pExceptionObject); /*0x5161b8*/
  if ( !result ) /*0x5161c2*/
  {
    ... sub_4F4AA0(8);          /*0x5161d7*/
    ... sub_4A60D0(...);        /*0x5161ef*/
    _CxxThrowException(..., &__TI4PAVWin32Error__); /*0x51620b*/
  }
  return result; /*0x5161cf*/
}
```

Live `disasm 0x00516190` confirms:

- `0x005161b2`: pushes size.
- `0x005161b5`: pushes block.
- `0x005161b8`: calls `_realloc`.
- `0x005161bd`: pops the two CRT arguments with `add esp, 8`.
- `0x005161c0-0x005161d2`: tests the result and returns it on success with `retn 8`.
- `0x005161d5-0x005161d7`: pushes `8` and calls `sub_4F4AA0` for the exception object allocation.
- `0x005161ed-0x005161ef`: moves the allocated object to `ECX` and calls `sub_4A60D0`.
- `0x005161fe`: pushes `__TI4PAVWin32Error@@`.
- `0x00516203-0x0051620b`: pushes the exception-object slot and calls `__CxxThrowException@8`.

Live `callees 0x00516190` returns only:

- `_realloc`
- `sub_4F4AA0`
- `sub_4A60D0`
- `__CxxThrowException@8`

The SEH/security-cookie setup and EH cleanup funclet are compiler output. Do not emit `_CxxThrowException`, `_ThrowInfo`, cleanup state variables, RTTI names, explicit stack cookies, or explicit EH cleanup in first-draft C++.

## Exception Shape

The failure path is a pointer throw, not a by-value `Win32Error` throw.

Live evidence:

- `entity_query` reports `__TI4PAVWin32Error@@` at `0x006590d4`, `__CTA4PAVWin32Error@@` at `0x006590e4`, `__CT??_R0PAVWin32Error@@@8` at `0x006590f8`, and pointer RTTI `??_R0PAVWin32Error@@@8` at `0x00674528`.
- `get_string 0x00674530` returns `.PAVWin32Error@@`, confirming pointer-to-`Win32Error` metadata.
- `xrefs_to 0x006590d4` reports `xref_count:25`, `more:false`; selected refs include [UID:0001BD] at `0x005160bc`, [UID:0001BE] at `0x00516150`, and this target at `0x005161fe`.
- `xrefs_to 0x004a60d0` reports `xref_count:27`, `more:false`; selected refs include [UID:0001BD] at `0x005160ad`, [UID:0001BE] at `0x00516141`, and this target at `0x005161ef`.
- `decompile 0x004a60d0` confirms the constructor source shape: base error setup, `Win32Error` vtable install, `GetLastError()` stored at `this[1]`, then return `this`.

Correct source expression:

```cpp
throw new Win32Error;
```

Rejected exception alternatives:

- `throw Win32Error();` is rejected because the throw-info is `PAVWin32Error`, not object throw-info.
- Explicit `_CxxThrowException`, `__TI4PAVWin32Error@@`, `__CTA4PAVWin32Error@@`, or RTTI symbol names are compiler/runtime output.
- Routing the helper to [UID:0000G7] `Win32Error` or `Error.cpp` is rejected. The error object is a dependency, not the owner.

## Caller Fanout And Call Protocol

Live `xrefs_to`/`xref_query` for `0x00516190` report exactly 10 code xrefs, `more:false`.

Current call sites:

| Call site | Function context |
| --- | --- |
| `0x004b6247` | `sub_4B61E0`, size `0x161` / 353 bytes (Verified with `int_convert.py`) |
| `0x004bb2a6` | raw/IDA-unowned function-shaped region beginning at `0x004bb260` |
| `0x004f324d` | `sub_4F31D0`, size `0xcf` / 207 bytes (Verified with `int_convert.py`) |
| `0x004f3285` | `sub_4F31D0`, same function |
| `0x004f3354` | `sub_4F32E0`, size `0xd5` / 213 bytes (Verified with `int_convert.py`) |
| `0x004f3476` | `sub_4F33E0`, size `0xb3` / 179 bytes (Verified with `int_convert.py`) |
| `0x004f358a` | raw/IDA-unowned function-shaped region beginning at `0x004f3560` |
| `0x004f35ca` | raw/IDA-unowned function-shaped region beginning at `0x004f35a0` |
| `0x004f3723` | `sub_4F3690`, size `0xeb` / 235 bytes (Verified with `int_convert.py`) |
| `0x004f3a26` | `sub_4F3990`, size `0xb3` / 179 bytes (Verified with `int_convert.py`) |

The important source-shape fact is consistent: call sites obtain the MemoryMan singleton, move it into `ECX`, then call the realloc helper with two stack arguments.

Representative live snippets:

```asm
4b6237  call sub_516030
4b623c  mov ecx, eax
4b6241  push edi
4b6246  push eax
4b6247  call sub_516190
```

The same site branches to [UID:0001BD] `sub_516050` when the old block is null:

```asm
4b6242  test eax, eax
4b6244  jz short loc_4B624E
4b6246  push eax
4b6247  call sub_516190
4b624e  call sub_516050
```

Other caller examples:

```asm
4bb29f  call sub_516030
4bb2a4  mov ecx, eax
4bb29b  push ecx
4bb29c  push dword ptr [esi+20h]
4bb2a6  call sub_516190
```

```asm
4f3279  call sub_516030
4f3281  mov ecx, eax
4f3283  push esi
4f3284  push edi
4f3285  call sub_516190
```

```asm
4f3566  call sub_516030
4f3576  mov ecx, eax
4f3575  push ecx
4f3589  push edx
4f358a  call sub_516190
```

```asm
4f36fa  call sub_516030
4f3702  mov ecx, eax
4f370e  push eax
4f3722  push edx
4f3723  call sub_516190
```

```asm
4f3a1a  call sub_516030
4f3a22  mov ecx, eax
4f3a24  push edi
4f3a25  push esi
4f3a26  call sub_516190
```

Interpretation:

- The target body does not read `ECX`, so Hex-Rays infers `__stdcall`.
- The caller protocol still loads `GetMemoryMan()` into `ECX` immediately before the helper call.
- The target returns with `retn 8`, which fits an MSVC `thiscall` member taking two stack arguments and an unused hidden `this`.
- This is the same source-shape issue B008 resolved for [UID:0001BD] `AllocateBufferMemory`: unused `this` does not make the body a free global helper when callers consistently pass the singleton in `ECX`.

## Source-Shape Reanalysis

### Method Versus Free Helper

Best source form: `MemoryMan` nonvirtual method emitted through `MemoryMan.cpp`.

Positive evidence:

- Every checked realloc call-site context obtains `GetMemoryMan()` and moves the result into `ECX` before calling `0x00516190`.
- Several call sites branch between [UID:0001BD] `AllocateBufferMemory` and this realloc helper under the same `GetMemoryMan()`/`ECX` setup.
- B008 accepted [UID:0001BD] as `MemoryMan::AllocateBufferMemory(size_t size)` despite Hex-Rays `__stdcall`, because live caller assembly passes the singleton in `ECX` and the method body does not need to read fields.
- B015 accepted higher-level C++ using `MemoryMan::FreeBufferMemory(void*)` as a first-draft source-facing MemoryMan method name, while preserving exact original API spelling as a confidence cap.
- B007 keeps `GetMemoryMan()` itself as a file-level free helper in `MemoryMan.cpp`; that fits this target's source use as `GetMemoryMan()->ReallocateBufferMemory(...)`.

Negative/capping evidence:

- IDA has no recovered decorated symbol for `MemoryMan::ReallocateBufferMemory`.
- `entity_query` for `ReallocateBufferMemory`, `ReallocateOrThrow`, `AllocateBufferMemory`, `ZeroAllocateBufferMemory`, `FreeBufferMemory`, `MemoryMan::`, and `516190` found only `SEH_516190` plus the RTTI string `.?AVMemoryMan@@`.
- `type_query *MemoryMan*` returns zero type records; `search_structs MemoryMan` returns no local structure.
- The historical Wave2 row in `by-memory/-report.old.md` says `0x00516190` was restored as global `ReallocateOrThrow` with `void* __stdcall ReallocateOrThrow(void* block, std::size_t newSize)`. That row predates the accepted B008 method-route correction and appears to follow the same decompiler/global inference now rejected for this allocation family.
- Current support docs still call this a file-level/global helper pending audit.

Decision: class-method source syntax is stronger than the stale free-helper/global model. Keep [UID:0000L7] as the source-file route, but change direct owner/emitter to [UID:00007U].

### API Name

Best first-draft source API: `ReallocateBufferMemory`.

Evidence for `ReallocateBufferMemory`:

- It is the natural source sibling of the already accepted `AllocateBufferMemory` method and the established `FreeBufferMemory` method name used by accepted higher-level C++.
- The live callers explicitly branch between `AllocateBufferMemory` for null/empty storage and this helper for existing storage. That is a source-level resize operation, not a general "throw helper" API.
- The method belongs to the MemoryMan allocation policy surface; `MemoryMan::ReallocateBufferMemory` is clearer and more consistent than `MemoryMan::ReallocateOrThrow`.

Evidence for retaining `ReallocateOrThrow` as an alias only:

- The current target filename and old Wave2 row use `ReallocateOrThrow`.
- That name is behaviorally correct: the helper calls `realloc` and throws on failure.
- However, it was attached to the old global/free-helper model and is not recovered from the current IDB as a symbol, string, function, global, or type.

Decision: formal C++ should use `MemoryMan::ReallocateBufferMemory(void *block, size_t newSize)`. Preserve `ReallocateOrThrow` in documentation as a historical/source-queue alias and confidence cap, not as the emitted API name.

## Ownership Ranking

1. [UID:00007U] `MemoryMan` method, emitted through `MemoryMan.cpp` - best. It matches current caller `GetMemoryMan()`/`ECX` protocol, B008 allocation-method precedent, and the two-stack-argument `retn 8` method ABI.
2. [UID:0000L7] `MemoryMan.cpp` file route - correct as the source file route, but too broad as direct owner/emitter for this method after the caller protocol is considered.
3. [UID:0000T8] `MemoryAllocationHelpers` - support/grouping index only. It should describe this method as part of the allocation helper surface, not emit it directly.
4. Historical global/free helper `ReallocateOrThrow` - rejected as direct source form. It preserves a useful alias but does not explain the live `ECX = GetMemoryMan()` setup.
5. [UID:0000G7] `Win32Error` / `Error.cpp` - rejected. The error class is constructed and thrown on failure but does not own the realloc wrapper.
6. Individual container/list callers - rejected by shared 10-call fanout and the centralized MemoryMan utility island.

## Recommended Target Changes

For `by-memory/0x00516190-0x00516210.ReallocateOrThrow.md`:

- Set metadata to `90/90`, owner/emitter [UID:00007U], `RECONSTRUCTABLE:TRUE`.
- Keep the UID and path for this implementation callback; do not create a new child or split the range.
- Update status/entity kind from "global allocation helper" to `MemoryMan` reallocation method/helper.
- State source route as [UID:0000L7] `NexusTK/util/MemoryMan.cpp`; direct semantic owner/emitter is [UID:00007U].
- Update Item Summary to say this is `MemoryMan::ReallocateBufferMemory` with historical alias `ReallocateOrThrow`, wrapping `realloc` and throwing `new Win32Error` on failure.
- Insert the exact formal C++ block from this report.
- Add live MCP evidence from session `80de0a67`:
  - health/session/process status,
  - exact `0x80` / 128-byte boundary,
  - pre/post `0xcc` padding,
  - decompile/disasm behavior,
  - exact 10 xrefs,
  - caller `GetMemoryMan()` to `ECX` protocol,
  - callees,
  - pointer throw-info and Win32Error constructor evidence.
- Record rejected alternatives: free global helper, `MemoryMan::ReallocateOrThrow` as the emitted API, caller-owned helpers, `throw Win32Error();`, runtime `_CxxThrowException` source, and `Error.cpp` ownership.
- Preserve confidence caps: no recovered decorated/source symbol; historical Wave2 global `ReallocateOrThrow`; no IDA UDT/type record; support docs currently stale until implementation.

Score rationale:

- Completion `90`: exact range, bytes, body, caller fanout, caller ABI/source protocol, exception shape, source owner route, API name decision, rejected alternatives, and formal first-draft C++ are all documented.
- Confidence `90`: behavior and method route are strong. Confidence stays below [UID:0001BD]'s accepted `91` because this target has a historical global alias conflict and `ReallocateBufferMemory` is a pattern-based source API name rather than a recovered symbol.

## Recommended Support Changes

These are implementation-callback recommendations only; they were not applied in this report-only pass.

### [UID:00007U] `by-class/MemoryMan.md`

- Add [UID:0001BG] `ReallocateBufferMemory(void *block, size_t newSize)` to the method map.
- Note that the body does not dereference `this`, but callers consistently pass `GetMemoryMan()` in `ECX`.
- Preserve B007's decision that `GetMemoryMan()` itself remains a file-level helper.
- Preserve B008's accepted `AllocateBufferMemory(size_t size)` method row.

Suggested support text:

```text
`ReallocateBufferMemory(void *block, size_t newSize)` is source-shaped as a nonvirtual `MemoryMan` method even though the body does not dereference `this`. Live callers call `GetMemoryMan()`, move the returned singleton to `ECX`, push `newSize` and `block`, and call `0x00516190`; the method returns `realloc(block, newSize)` or throws `new Win32Error` on failure. The historical `ReallocateOrThrow` name remains an alias/confidence cap, not the formal API used for first-draft C++.
```

### [UID:0000L7] `by-file/MemoryMan.md`

- Preserve `NexusTK/util/MemoryMan.cpp` as the source file route.
- Change the proposed contents row for [UID:0001BG] from file-level `ReallocateOrThrow` to method body `MemoryMan::ReallocateBufferMemory(void *block, size_t newSize)` routed through `MemoryMan.cpp`.
- Keep broader file caveats for global operators, copy wrappers, exact globals/static object/header factoring, and sibling pages that have not been audited.

### [UID:0000T8] `by-global/MemoryAllocationHelpers.md`

- Keep this page as the allocation-helper family index.
- Update [UID:0001BG] from an independent `ReallocateOrThrow` global to the MemoryMan-backed method `ReallocateBufferMemory`.
- State that `ReallocateOrThrow` remains a historical alias and behavior summary.
- Do not emit C++ from this global/index page.

### [UID:0001BA] `MemoryManAndAllocationHelpers`

- Update the covered-range row for [UID:0001BG] to source-ready child method wording.
- Preserve the parent as a non-emitting split index with blank formal C++.
- Note that the exact child now carries formal C++, while the aggregate continues to record island boundaries and family relationships.

### Sibling Pages

- [UID:0001BD] `AllocateBufferMemory`: no change required beyond support references. It already implements the accepted method-route precedent.
- [UID:0001BE] `ZeroAllocateBufferMemory`: do not mass-reroute or emit this sibling in this callback unless the supervisor explicitly expands scope. It should receive its own audit.
- [UID:0001BF] `FreeBufferMemory`: do not mass-edit this sibling target in this callback unless directly required for consistency. B015 already demonstrates accepted higher-level source syntax `MemoryMan::FreeBufferMemory(void*)`, but the exact sibling target page still deserves its own implementation callback.

### Project-Level And Generated Files

- `by-project-structure/proposed-source-tree.md` still says `ReallocateOrThrow` belongs to the same utility family. This is useful historical/source-family context but is project-level and must not be edited under the current constraints.
- Generated files currently contain stale empty-emitter rows for [UID:0001BG]. Do not manually edit them. Run scoped validators and generated-refresh checks after accepted by-* edits.

## Open Questions

Closed for this target:

- Exact primary range and padding.
- `realloc` success path.
- Failure allocation, constructor call, and pointer-throw shape.
- Direct caller count.
- Method-vs-free-helper source route.
- First-draft C++ readiness.

Remaining but non-blocking:

- Exact original decorated symbol/name is not recovered. `ReallocateBufferMemory` is a first-draft source-facing API name inferred from the accepted MemoryMan method family and current caller protocol.
- The historical `ReallocateOrThrow` name may remain useful for search/trace compatibility.
- Exact header declaration location and public/private visibility remain broader MemoryMan header factoring questions.
- [UID:0001BE] and [UID:0001BF] still need their own target-level implementation callbacks before broad helper-family cleanup is complete.

## Validation Needs

No validator was run for this report-only pass because only this research report was created.

If the supervisor accepts this report for implementation, acquire leases only for files edited immediately, then run scoped validators for every edited by-* file from `source-3/project-documentation`, for example:

> Executable block R001 was removed from this report and preserved verbatim in [0001BG-ReallocateOrThrow-source-quality-removed.md](0001BG-ReallocateOrThrow-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

After validators and any generated refresh complete, read generated output only to verify that:

- `auto-generated/NexusTK/util/MemoryMan.cpp` no longer has an empty emitter marker for [UID:0001BG].
- The [UID:0001BG] generated block emits the `MemoryMan::ReallocateBufferMemory` formal C++.
- Generated tracker/coverage rows no longer show stale `78/86` empty-emitter state.

Do not manually edit generated/project-level/manual coverage/tool-state files.

## Implementation Checklist

Report-only proof:

- [x] Used project-level `ntk-b-agent-workflow` skill and read the required workflow references.
- [x] Read `Agent-B010/goal.md` and followed the report-only assignment.
- [x] Did not spawn subagents.
- [x] Did not acquire leases.
- [x] Did not edit target/support by-* docs.
- [x] Did not edit generated, project-level, manual coverage, validator/tool-state, or IDA DB files.
- [x] Obtained live IDA MCP evidence from session `80de0a67`; MCP was available and responsive.
- [x] Checked current target/support docs, sibling docs, accepted B007/B008/B015 reports, stale generated rows, and historical Wave2 global-name context.
- [x] Produced this report at `tools/leaser/Agents/Agent-B010/research/0001BG-ReallocateOrThrow-source-quality.md`.

Implementation callback checklist, if accepted:

- [x] Leased only the target/support by-* files needed for this callback. Proof: target [UID:0001BG] was leased, edited, validated, and unleased; support files were leased as `by-class/MemoryMan.md`, `by-file/MemoryMan.md`, `by-global/MemoryAllocationHelpers.md`, and `by-memory/0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md`. After a B006 lease interval cleared, B010 reacquired those four support leases before the final validator/generated-check/release batch.
- [x] Updated [UID:0001BG] target metadata to `COMPLETION:90`, `CONFIDENCE:90`, `CANONICAL_OWNER:00007U`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00007U`. Proof: target validator `000000003092`, timestamp `2026-06-26T17:40:27-04:00`, exit `0`, `ok:1`, reported `completion_update`, `confidence_update`, and `canonical_owner_update 0001BG ... 00007U`.
- [x] Inserted the exact `MemoryMan::ReallocateBufferMemory(void *block, size_t newSize)` C++ block from this report, using `realloc`, null check, `throw new Win32Error`, and return. Proof: generated `auto-generated/NexusTK/util/MemoryMan.cpp` refresh `000000003138` emits [UID:0001BG] at `Completion:90 | Confidence:90` with that formal function body.
- [x] Updated [UID:0001BG] target text with live MCP session `80de0a67`, listener/process/session health, exact `0x80` range/padding, body/callee evidence, pointer-throw `new Win32Error` shape, exact 10 xrefs, caller `GetMemoryMan()`/`ECX` method-route proof, historical `ReallocateOrThrow` alias, rejected alternatives, and score rationale.
- [x] Updated [UID:00007U] `by-class/MemoryMan.md` to add [UID:0001BG] as a `MemoryMan` method while preserving B007/B008 and current B002/B006/B009 decisions. Validator proof: command `000000003131`, timestamp `2026-06-26T18:06:43-04:00`, exit `0`, `ok:1`, warning `missing_ref_uid 0003VP`, generated refresh deferred.
- [x] Updated [UID:0000L7] `by-file/MemoryMan.md` to keep `NexusTK/util/MemoryMan.cpp` as the file route and describe [UID:0001BG] as `MemoryMan::ReallocateBufferMemory`. Validator proof: command `000000003132`, timestamp `2026-06-26T18:06:50-04:00`, exit `0`, `ok:1`, warnings `missing_ref_uid 0003VP` x3, generated refresh deferred.
- [x] Updated [UID:0000T8] `by-global/MemoryAllocationHelpers.md` to keep the grouping/index role and remove independent-global wording for [UID:0001BG]. Validator proof: command `000000003133`, timestamp `2026-06-26T18:06:57-04:00`, exit `0`, `ok:1`, warnings `missing_ref_uid 0003VP` x3, generated refresh deferred.
- [x] Updated [UID:0001BA] aggregate covered-range/source-readiness wording while preserving `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and blank formal C++. Validator proof: command `000000003134`, timestamp `2026-06-26T18:07:06-04:00`, exit `0`, `ok:1`, warnings `missing_ref_uid 0003VP` x5, generated refresh deferred.
- [x] Checked [UID:0001BE] and [UID:0001BF] sibling pages for direct contradictions only. Proof: [UID:0001BE] already carries formal `MemoryMan::ZeroAllocateBufferMemory(size_t size)` with owner/emitter [UID:00007U]; [UID:0001BF] already carries formal `MemoryMan::FreeBufferMemory(void *buffer)` with owner/emitter [UID:00007U]. No B010 sibling C++ implementation was made.
- [x] Did not manually edit `by-project-structure/proposed-source-tree.md`, generated files, project-level files, manual coverage reports, validator/tool-state files, or IDA DB files. Validator-owned side effects were limited to normal validator/projected stats/generated refresh updates.
- [x] Ran validators on every edited by-* file. Proof: target `000000003092`; support validators `000000003131`, `000000003132`, `000000003133`, and `000000003134`; all exited `0` with `ok:1`. Only warnings were pre-existing `missing_ref_uid 0003VP` references in support pages.
- [x] Verified generated output when current by reading generated files only. Proof: queue status `000000003135` showed generated refresh processing latest support command `000000003134`; after completion, generated `auto-generated/NexusTK/util/MemoryMan.cpp` header shows `validator-command-id: 000000003138`, `validator-refreshed-at: 2026-06-26T18:07:57-04:00`, and [UID:0001BG] emits `MemoryMan::ReallocateBufferMemory` at `90/90`. `auto-generated/-ag-research-tracker.md` row for [UID:0001BG] is `90/90`; `auto-generated/-ag-coverage-report-by-memory.md` row for [UID:0001BG] is `emits_code:true`, `90%`, `very-strong`.
- [x] Released leases immediately after the edit/validator/generated-check batch. Proof: `python .\tools\leaser\leaser.py B010 unlease ...` returned `Success` for all four support files, and `current_leases.md` search found no B010 or target/support lease entries afterward. Target [UID:0001BG] had already been unleased after target validation.
- [x] Updated this checklist with proof for every accepted implementation item.
- [x] No accepted implementation item remains unapplied; blocker count `0`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000004165","destination_path":"executed-b-agent-research/B010/0001BG-ReallocateOrThrow-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B010/research/0001BG-ReallocateOrThrow-source-quality.md","timestamp":"2026-06-26T18:16:18","uid":"0001BG"} -->
<!-- {"agent":"B010","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001BG-ReallocateOrThrow-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B010/0001BG-ReallocateOrThrow-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001BG"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
