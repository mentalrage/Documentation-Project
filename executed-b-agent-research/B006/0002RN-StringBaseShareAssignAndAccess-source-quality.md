** TARGET-REPORT-UID:0002RN **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002RN StringBase Share/Assign/Access Source-Quality Research

Agent: B006  
Assignment id: `B006-report-0002RN-stringbase-share-assign-and-access-20260625`  
Mode: report-only research first  
Target: [UID:0002RN] `by-memory/0x005829f0-0x00582d80.StringBaseShareAssignAndAccess.md`

Report path: `tools/leaser/Agents/Agent-B006/research/0002RN-StringBaseShareAssignAndAccess-source-quality.md`

Status: report-only research complete. No target/support by-* docs, generated reports, project-level files, coverage reports, validator state/cache, or IDA database state were edited. No leases were taken. No subagents were spawned.

## Executive Recommendation

Update [UID:0002RN] from the current source header state:

- `COMPLETION:86`
- `CONFIDENCE:89`
- `CANONICAL_OWNER:0000OA`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000OA`
- blank `EMITTER_POSITION_OPTIONAL`
- blank formal `RECONSTRUCTION_CPP CODE`

Recommended target state:

- `COMPLETION:91`
- `CONFIDENCE:92`
- `CANONICAL_OWNER:0001WS`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0001WS`
- blank `EMITTER_POSITION_OPTIONAL`
- populate the target formal `RECONSTRUCTION_CPP CODE` block with the exact first-draft C++ in this report.

Recommended Item Summary:

`StringBaseTemplate ANSI/wide share-or-copy initialization, counted data initialization, empty sentinel initialization, destructor release, assignment-style copy/share helpers, raw wide literal assignment, and wide index access over the 12-byte ref-counted buffer header.`

Reason: current IDA MCP evidence resolves the exact twelve-function range, every internal padding span, all target behavior details, source-facing names, helper liveness, and source placement. The target is not a mixed CRT/file-local child like [UID:0002RM]; it is a pure `StringBaseTemplate` constructor/destructor/assignment/access helper cluster. Direct ownership should therefore move to [UID:0001WS] `StringBaseTemplate`, which already emits through [UID:0000OA] `StringBase` to `NexusTK/util/StringBase.cpp`.

The target now clears the current first-draft C++ gate. Remaining uncertainty is final original method spelling and public/private header split, not target behavior, range, liveness, or owner route.

## Current Target State

Target page read during this report:

- Path: `by-memory/0x005829f0-0x00582d80.StringBaseShareAssignAndAccess.md`
- Header: `COMPLETION:86`, `CONFIDENCE:89`, `CANONICAL_OWNER:0000OA`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OA`, blank `EMITTER_POSITION_OPTIONAL`, blank formal `RECONSTRUCTION_CPP CODE`
- Current Item Summary: `Ref-counted ANSI/wide share, sentinel init, release wrappers, COW-aware assignment, raw wide assignment, and indexed wide access helpers.`
- Current stale issue: the target says C++ remains blank because final API/source signature names and overload grouping are unresolved. Under the current by-structure gate, those are confidence caps, not a no-code blocker for this exact source-bearing child.
- Current stale issue: the target keeps direct [UID:0000OA] file ownership. Current sibling evidence makes [UID:0001WS] the better direct owner for this exact type-method helper cluster while preserving [UID:0000OA] as the generated source root.
- Current stale issue: the target describes the assignment helpers too generally. MCP confirms important edge behavior: the empty-source fast path in `0x00582bb0` and `0x00582c60` stores the empty sentinel without releasing the current destination, and the private-copy reuse path copies the visible byte/code-unit count without rewriting the destination stored length or terminator. This must be documented as binary behavior, not normalized into a textbook `operator=`.

Generated state checked during this report is stale and must not be hand-edited:

- `auto-generated/NexusTK/util/StringBase.cpp` still has [UID:0002RN] as `Completion:76 | Confidence:84 | Empty Emitter Marker`.
- `auto-generated/-ag-research-tracker.md` still lists [UID:0002RN] as `76/84`.
- `auto-generated/-ag-coverage-report-by-memory.md` still lists [UID:0002RN] as `76%`, `emits_code:false`, and the old summary.
- `project-level/-auto-completion-stats.md` did not return a [UID:0002RN] hit in the scoped search.

## Live MCP Provenance

IDA MCP was mandatory for this report and was available.

Current MCP/session facts:

- Endpoint used by the report pass: `http://127.0.0.1:13337/mcp`.
- Server: `ida-pro-mcp` version `1.0.0`.
- Active database/session id: `80de0a67`.
- IDB path from `idb_list`: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- `server_health` for session `80de0a67`: status `ok`, module `NexusTK.exe`, imagebase `0x400000`, auto analysis ready, Hex-Rays ready, strings cache ready, and not currently analyzing.

MCP tool categories used:

- `tools/list`, `idb_list`, and `server_health` for availability/session proof.
- `lookup_funcs` and `analyze_component` for function inventory, sizes, component edges, globals, and callees.
- `decompile`, `disasm`, and `analyze_function` for per-function behavior, caller counts, callees, and instruction details.
- `get_bytes` for all internal boundary/padding spans and successor entry bytes.
- `xrefs_to` for function-entry and sentinel references.
- `list_globals` for preserved `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t>>` compiler metadata.

No IDA DB edits were made.

## Exact Range And Boundary Evidence

Current MCP `lookup_funcs`/`analyze_component` over the assigned starts confirms the exact target function inventory:

| Range | Size | Current IDA name | Recommended source-facing role |
| --- | ---: | --- | --- |
| `0x005829f0-0x00582a48` | `0x58` / 88 | `sub_5829F0` | `ShareOrCopyAnsiFromStringBase`: shares positive-refcount ANSI storage or private-copies non-shareable non-empty storage through `EnsureAnsiCapacity` and `memmove`. |
| `0x00582a50-0x00582a75` | `0x25` / 37 | `sub_582A50` | `InitializeAnsiFromCountedBytes`: allocates an ANSI buffer of the requested byte count and copies exactly that count. |
| `0x00582a80-0x00582a8a` | `0x0a` / 10 | `sub_582A80` | `InitializeEmptyAnsi`: stores `g_emptyAnsiString` / `0x00670290`. |
| `0x00582a90-0x00582aeb` | `0x5b` / 91 | `sub_582A90` | `ShareOrCopyWideFromStringBase`: wide twin of the ANSI share/private-copy initializer through `EnsureWideCapacity`. |
| `0x00582af0-0x00582b1e` | `0x2e` / 46 | `sub_582AF0` | `InitializeWideFromRange`: derives `(last - first) / 2`, allocates wide storage, and copies exactly `2 * count` bytes. |
| `0x00582b20-0x00582b2a` | `0x0a` / 10 | `sub_582B20` | `InitializeEmptyWide`: stores `g_emptyWideString` / `0x00670278`. |
| `0x00582b30-0x00582b66` | `0x36` / 54 | `sub_582B30` | ANSI destructor/release body, forwarding to `ReleaseAnsiBuffer` at `0x005832f0`. |
| `0x00582b70-0x00582ba6` | `0x36` / 54 | `sub_582B70` | Wide destructor/release body, forwarding to `ReleaseWideBuffer` at `0x005833a0`. |
| `0x00582bb0-0x00582c58` | `0xa8` / 168 | `sub_582BB0` | `AssignAnsiFromStringBase`: assignment-style share/copy helper with self guard, share-retain fast path, visible-length clamp, and private-copy fallback. |
| `0x00582c60-0x00582d1e` | `0xbe` / 190 | `sub_582C60` | `AssignWideFromStringBase`: wide twin with manual UTF-16 length scan and the same share/copy policy. |
| `0x00582d20-0x00582d61` | `0x41` / 65 | `sub_582D20` | `AssignWideLiteral`: releases current wide storage, computes `wcslen`, allocates, and copies raw UTF-16 bytes. |
| `0x00582d70-0x00582d80` | `0x10` / 16 | `sub_582D70` | `GetWideAt`: returns `m_data[index]` as a 16-bit code unit. |

Current MCP `get_bytes` confirms every internal gap is `0xcc` padding, and the target end is exactly half-open at `0x00582d80`:

| Span | Bytes |
| --- | --- |
| `0x00582a48-0x00582a50` | eight `0xcc` bytes |
| `0x00582a75-0x00582a80` | eleven `0xcc` bytes |
| `0x00582a8a-0x00582a90` | six `0xcc` bytes |
| `0x00582aeb-0x00582af0` | five `0xcc` bytes |
| `0x00582b1e-0x00582b20` | two `0xcc` bytes |
| `0x00582b2a-0x00582b30` | six `0xcc` bytes |
| `0x00582b66-0x00582b70` | ten `0xcc` bytes |
| `0x00582ba6-0x00582bb0` | ten `0xcc` bytes |
| `0x00582c58-0x00582c60` | eight `0xcc` bytes |
| `0x00582d1e-0x00582d20` | two `0xcc` bytes |
| `0x00582d61-0x00582d70` | fifteen `0xcc` bytes |

`get_bytes 0x00582d80 size 8` returns `55 8b ec 56 8b 75 08 57`, the prologue of successor [UID:0002RO] `StringBaseAllocationGrowAndCow`. No split or range adjustment is recommended. This is a contiguous source-authored helper cluster with normal function alignment padding.

## Component, Caller, And Callee Evidence

`analyze_component` over the twelve starts reports all twelve as interface functions and records no internal call-graph edges among them. The common state is the caller-owned `StringBase` object pointer and the shared 12-byte buffer header, not an internal dispatcher.

Shared globals in the component:

- `0x00670290` / `off_670290`: ANSI empty sentinel, read or stored by `0x005829f0`, `0x00582a80`, and `0x00582bb0`.
- `0x00670278` / `Src`: wide empty sentinel, read or stored by `0x00582a90`, `0x00582b20`, and `0x00582c60`.
- `0x00672f24` / security cookie: referenced by the ANSI/wide release wrappers because the compiler emitted C++ EH/security-cookie scaffolding. This is compiler frame protection, not source string logic.

Per-function caller/callee evidence from `analyze_function`:

| Function | Direct callees | Caller count and representative callers |
| --- | --- | --- |
| `0x005829f0` | `InterlockedIncrement`, `0x00584b10`, `_memmove` | 11 caller functions / 19 code xrefs, including `0x0049c800`, `0x005797b0`, `0x0057a890`, `0x0057b860`, `0x0057bc60`, `0x0057bd90`, `0x0057be60`, `0x0057bed0`, and `0x005c09xx` groups. |
| `0x00582a50` | `0x00582d80`, `_memmove` | 4 callers: `0x00575a10`, `0x00575a90`, `0x00575ac0`, `0x00575b50`. |
| `0x00582a80` | none | 13 callers, including `0x00419f50`, `0x0048e550`, `0x0049c3e0`, `0x0049c570`, `0x0049c600`, `0x004b12a0`, `0x004b1340`, `0x00517f30`, `0x005198e0`, `0x00579e30`, `0x0057a890`, `0x005822d0`, `0x00582380`. |
| `0x00582a90` | `InterlockedIncrement`, `0x00584ba0`, `_memmove` | 34 caller functions / 60 code xrefs, including `0x004926a0`, `0x0049c600`, `0x0049c800`, `0x0049cad0`, `0x0049cbb0`, `0x0049cc40`, `0x004b1d50`, `0x004b2730`, `0x004b3090`, `0x004b4240`, `0x004b4520`, `0x004e13b0`, `0x0056bca0`, and `0x005b7140`. |
| `0x00582af0` | `0x00582e30`, `_memmove` | 1 caller: `0x004f3020`. |
| `0x00582b20` | none | 37 callers, including `Application__Constructor`, `0x0046f810`, `0x0046ff50`, `0x00470f20`, `0x0048e550`, `0x00499910`, `0x00499fe0`, `0x0049a410`, `0x0049c600`, and UI/string caller groups. |
| `0x00582b30` | `0x005832f0` | 50 callers, including local/vector cleanup and ANSI temporary destruction paths such as `0x0048e780`, `0x004926a0`, `0x00494020`, `0x0049c3e0`, `0x0049c570`, `0x0049c600`, `0x0049c800`, `0x004a17b0`, `0x004a6690`, `0x004b1340`, and `0x004b1d50`. |
| `0x00582b70` | `0x005833a0` | 50 callers, including wide temporary cleanup paths such as `0x004543f0`, `0x0045f3a0`, `0x00463970`, `0x00467230`, `0x0046f480`, `0x00470330`, `0x00470740`, `0x0048e780`, `0x0048ebc0`, and `0x004926a0`. |
| `0x00582bb0` | `0x005832f0`, `InterlockedIncrement`, `0x00582d80`, `_memmove` | 10 caller functions, including `0x0049c3e0`, `0x004f6d80`, `0x00502e30`, `0x00507c90`, `0x00513da0`, `0x00517f30`, `0x005198e0`, `0x00579e30`, `0x0057a890`, and `0x005822d0`. |
| `0x00582c60` | `0x005833a0`, `InterlockedIncrement`, `0x00582e30`, `_memmove` | 23 caller functions / 48 code xrefs, including `0x004918e0`, `0x0049c570`, `0x0049c600`, `0x004a6690`, `0x004b1340`, `0x004b1d50`, `0x004b3090`, `0x004b4240`, `0x004b4520`, `0x004b4fd0`, `0x004b5280`, `0x004e13b0`, and `0x00529ee0`. |
| `0x00582d20` | `0x005833a0`, `0x00582e30`, `_memmove` | 19 callers, including `Application__Constructor`, `0x00464f50`, `0x0046f810`, `0x00470f20`, `0x004926a0`, `0x00499910`, `0x00499bf0`, `0x0049a410`, `0x004a6550`, and `0x004afe40`. |
| `0x00582d70` | none | 1 caller: `0x004b2730`. |

Caller disassembly samples support the source roles:

- `0x0049c800` uses `0x005829f0` and `0x00582a90` in local temporary/list insertion sequences, followed by `0x00582b30`/`0x00582b70` cleanup calls.
- `0x0057a890` uses `0x005829f0` for ANSI string vector/local copy construction and `0x00582bb0` for same-family assignment/copy-down behavior.
- `0x004b2730` uses `0x00582a90` for wide temporary construction and `0x00582b70` for cleanup.

This is live shared string infrastructure, not dead raw helper code and not feature-local ownership.

## Behavior Evidence

### Share-Or-Copy Initializers

`0x005829f0` and `0x00582a90` have the same policy over ANSI and wide buffers:

- Load the source object's `m_data`.
- Read `refCount` at `data - 0x0c`.
- If `refCount >= 0`, share the source buffer. Non-empty source buffers increment the source refcount with `InterlockedIncrement`; empty source buffers simply store the empty sentinel.
- If `refCount < 0` and the source is not the empty sentinel, copy a private payload. ANSI calls `0x00584b10`; wide calls `0x00584ba0`. The current support source-facing names should be `EnsureAnsiCapacity` and `EnsureWideCapacity`.
- Copy exactly `sourceHeader->length` bytes for ANSI or `2 * sourceHeader->length` bytes for wide with `memmove`.

The private-copy path calls capacity helpers, not the raw allocation helpers directly. This is why `0x00584b10` should be treated as an ANSI ensure-capacity helper rather than a generic unrelated grow routine.

### Counted And Empty Initializers

`0x00582a50` calls `AllocateAnsiBuffer(count)` at `0x00582d80`, then copies exactly `count` bytes from the caller-supplied source. It relies on the allocator to set length and NUL termination.

`0x00582af0` receives two raw wide pointers, derives the code-unit count as `(last - first) >> 1`, calls `AllocateWideBuffer(count)` at `0x00582e30`, and copies exactly `2 * count` bytes.

`0x00582a80` stores the ANSI empty sentinel `0x00670290`. `0x00582b20` stores the wide empty sentinel `0x00670278`.

### Destructor/Release Wrappers

`0x00582b30` and `0x00582b70` are 54-byte destructor-style wrappers. Disassembly shows compiler C++ EH/security-cookie scaffolding, then exactly one source-relevant call:

- `0x00582b30` calls `ReleaseAnsiBuffer` / `0x005832f0`.
- `0x00582b70` calls `ReleaseWideBuffer` / `0x005833a0`.

The SEH/cookie frame should not become source logic. It is evidence that these are destructor/release bodies in the `StringBase` type family.

### Assignment-Style Helpers

`0x00582bb0` and `0x00582c60` are assignment-style share/copy helpers, but the target docs should not over-normalize them into a fully general textbook `operator=`:

- Source empty fast path: if `source.m_data` is the empty sentinel, the helper stores the empty sentinel into `this->m_data` and returns. It does not call `ReleaseAnsiBuffer`/`ReleaseWideBuffer` on the existing destination before this store.
- Self-assignment guard: if `this->m_data == source.m_data`, return the destination unchanged.
- Share fast path: if the destination is shareable or already empty, and the source is shareable, release the current destination, increment the source refcount, and store the source pointer.
- Private-copy path: start from source header `length`, scan the visible source text with `strlen` or a manual UTF-16 loop, and clamp the copy length to the visible NUL-terminated length if the stored header length is larger.
- Grow path: if destination `refCount > 1` or destination capacity is less than the copy length, release the destination and allocate a same-length ANSI/wide buffer before copying.
- In-place private-copy path: if the destination is already exclusive/unshared and capacity is enough, the helper copies into the existing buffer but does not rewrite `header->length` or a NUL terminator in this function. The implementation documentation must preserve this exact binary fact.

This behavior explains why the recommended source-facing names are `AssignAnsiFromStringBase` and `AssignWideFromStringBase` rather than claiming symbol-proof of public `operator=` spelling. A final declaration pass may wrap or rename these helpers, but the target body must keep the exact release/share/copy order and the empty-source quirk.

### Raw Wide Literal Assignment And Index Access

`0x00582d20` always releases current wide storage through `ReleaseWideBuffer`, computes `wcslen(source)`, allocates with `AllocateWideBuffer`, and copies `2 * length` bytes. It does not copy the terminator explicitly because `AllocateWideBuffer` writes the terminator and stored length.

`0x00582d70` is a 16-byte indexed access helper: it returns `m_data[index]` as a 16-bit code unit. It has one caller at `0x004b2730`, a wide string comparison/replacement caller context.

## Dependency Helper Evidence

MCP decompiled the direct dependency helpers used by this target:

- `0x00582d80` / `AllocateAnsiBuffer`: empty length stores `g_emptyAnsiString`; non-empty allocation chooses ANSI 64/128/256/512 pools or heap-allocates `requested + 13`, writes `refCount = 1`, terminator, length, capacity, and stores `header + 0x0c`.
- `0x00582e30` / `AllocateWideBuffer`: empty length stores `g_emptyWideString`; non-empty allocation chooses wide 64/128/256/512 pools or heap-allocates `2 * requested + 14`, writes `refCount = 1`, terminator, length, capacity, and stores `header + 0x0c`.
- `0x005832f0` / `ReleaseAnsiBuffer`: ignores the ANSI sentinel, decrements non-sentinel refcounts with `InterlockedDecrement`, returns capacity 64/128/256/512 to the ANSI pools or heap-frees larger headers, and resets `m_data` to `g_emptyAnsiString`.
- `0x005833a0` / `ReleaseWideBuffer`: wide twin of the ANSI release path, resetting to `g_emptyWideString`.
- `0x00584b10` / recommended `EnsureAnsiCapacity`: grows ANSI storage only when requested capacity exceeds `data[-1]`, preserving the old length and payload, writing the terminator and length, and releasing the old pointer through `ReleaseAnsiBuffer`.
- `0x00584ba0` / `EnsureWideCapacity`: grows wide storage only when requested capacity exceeds `data[-1]`, preserving `2 * oldLength`, writing the terminator and length, and releasing the old pointer through `ReleaseWideBuffer`.

These dependency checks resolve the old helper-name blocker. The target C++ should use `AllocateAnsiBuffer`, `AllocateWideBuffer`, `ReleaseAnsiBuffer`, `ReleaseWideBuffer`, `EnsureAnsiCapacity`, and `EnsureWideCapacity`.

## Sentinel, Header, And Type Evidence

Current MCP sentinel xrefs:

- `xrefs_to 0x00670290` reports 16 total ANSI sentinel refs; target-relevant refs are `0x005829f3`, `0x00582a80`, and `0x00582bb3`.
- `xrefs_to 0x00670278` reports 23 total wide sentinel refs; target-relevant refs are `0x00582a93`, `0x00582b20`, and `0x00582c63`.

Header field model:

- `data - 0x0c`: `refCount`, changed with `InterlockedIncrement`/`InterlockedDecrement`; negative values mean non-shareable/exclusive/private storage.
- `data - 0x08`: stored character length.
- `data - 0x04`: capacity / pool bucket size.
- `data + 0x00`: ANSI or UTF-16 character payload.

MCP `list_globals` with `*StringBase*` returns preserved compiler metadata for the type family, including vtables and RTTI names containing `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t>>` at representative addresses `0x0061fcd4`, `0x0061fcec`, `0x0061ff70`, `0x0062004c`, `0x00620094`, `0x00622cf4`, `0x0064c610`, and `0x0064c9c8`. This supports a `StringBaseTemplate` direct owner, with `StringBase.cpp` as source root.

## Source-Facing Names

Apply these names or document an implementation-specific replacement:

| Address | Current IDA name | Recommended source-facing name |
| --- | --- | --- |
| `0x005829f0` | `sub_5829F0` | `ShareOrCopyAnsiFromStringBase` |
| `0x00582a50` | `sub_582A50` | `InitializeAnsiFromCountedBytes` |
| `0x00582a80` | `sub_582A80` | `InitializeEmptyAnsi` |
| `0x00582a90` | `sub_582A90` | `ShareOrCopyWideFromStringBase` |
| `0x00582af0` | `sub_582AF0` | `InitializeWideFromRange` |
| `0x00582b20` | `sub_582B20` | `InitializeEmptyWide` |
| `0x00582b30` | `sub_582B30` | `StringBase<char>::~StringBase` body / `DestroyAnsi` evidence wording |
| `0x00582b70` | `sub_582B70` | `StringBase<wchar_t>::~StringBase` body / `DestroyWide` evidence wording |
| `0x00582bb0` | `sub_582BB0` | `AssignAnsiFromStringBase` |
| `0x00582c60` | `sub_582C60` | `AssignWideFromStringBase` |
| `0x00582d20` | `sub_582D20` | `AssignWideLiteral` |
| `0x00582d70` | `sub_582D70` | `GetWideAt` |

Support helper names to apply or synchronize:

- `0x00582d80`: `AllocateAnsiBuffer`
- `0x00582e30`: `AllocateWideBuffer`
- `0x005832f0`: `ReleaseAnsiBuffer`
- `0x005833a0`: `ReleaseWideBuffer`
- `0x00584b10`: `EnsureAnsiCapacity` preferred; if existing support pages retain `GrowAnsiBuffer`, document it as the same capacity-ensure helper and do not confuse it with the earlier append/grow helpers.
- `0x00584ba0`: `EnsureWideCapacity`
- `0x00670290`: `g_emptyAnsiString`
- `0x00670278`: `g_emptyWideString`
- 12-byte prefix type: `RefCountedStringBufferHeader`

Raw `sub_`, `off_`, and `Src` labels should remain only in MCP evidence/search context.

## Owner And Source Placement

Recommended direct canonical owner/emitter: [UID:0001WS] `StringBaseTemplate`.

Evidence for [UID:0001WS]:

- The entire target is a method/helper cluster over `StringBase` object layout: `m_data` at offset `0`, 12-byte ref-counted header immediately before data, ANSI/wide sentinels, copy-on-write/share semantics, and destructor/assignment/access behavior.
- It has no file-local CRT shims or mixed external utility wrappers like [UID:0002RM].
- [UID:0002RO] already routes through [UID:0001WS] for allocation/grow/COW primitives, and [UID:0002RT] now routes through [UID:0001WS] for release/capacity/detach helpers.
- MCP `list_globals` continues to expose compiler metadata preserving `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t>>`.
- [UID:0001WS] itself emits through [UID:0000OA] `StringBase`, so generated output still lands in `auto-generated/NexusTK/util/StringBase.cpp`.

Rejected direct owners:

- [UID:0000OA] `StringBase` as direct child owner only: still the source-file root, but too coarse for this pure constructor/destructor/assignment/access type-method cluster after comparable StringBase primitive children moved to [UID:0001WS].
- [UID:0001J1] `StringBaseConstructionAndCow`: non-emitting aggregate/container over exact children; it should map the child, not own emitted source.
- [UID:0000OB] `StringUtil`: broad utility-string coordinator, not the direct owner of the ref-counted pointer-backed buffer implementation.
- [UID:0000D9] `SimpleUString` or `SimpleUStringVector`: useful facade/caller context for some wide string uses, but current compiler metadata and target internals support `mystr::StringBase`.
- [UID:0000KV] `LObject`: stale generated-owner pollution over an unrelated true `LObject` shell.
- [UID:0000MM] `PoolAllocator`: owns allocator mechanics, not source string methods or sentinel/string pool declarations.
- Feature callers such as UI, Application, LanguageMan, File, and packet/helper modules: consumers only.

## Formal RECONSTRUCTION_CPP CODE Recommendation

Populate [UID:0002RN] with the following exact formal block. This is first-draft target C++, not an illustrative side sample.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
namespace mystr {

template <>
StringBase<char, mychar_traits<char> > &
StringBase<char, mychar_traits<char> >::ShareOrCopyAnsiFromStringBase(
    const StringBase<char, mychar_traits<char> > &source)
{
    char *sourceData = source.m_data;
    const RefCountedStringBufferHeader *sourceHeader =
        reinterpret_cast<const RefCountedStringBufferHeader *>(sourceData) - 1;

    char *resultData = g_emptyAnsiString;
    if (sourceHeader->refCount >= 0) {
        if (sourceData != g_emptyAnsiString) {
            InterlockedIncrement(
                const_cast<LONG *>(&sourceHeader->refCount));
            resultData = sourceData;
        }

        m_data = resultData;
        return *this;
    }

    if (sourceData == g_emptyAnsiString) {
        m_data = resultData;
        return *this;
    }

    EnsureAnsiCapacity(sourceHeader->length);
    memmove(m_data, sourceData, sourceHeader->length);
    return *this;
}

template <>
StringBase<char, mychar_traits<char> > &
StringBase<char, mychar_traits<char> >::InitializeAnsiFromCountedBytes(
    const char *source,
    unsigned int count)
{
    AllocateAnsiBuffer(count);
    memmove(m_data, source, count);
    return *this;
}

template <>
StringBase<char, mychar_traits<char> > &
StringBase<char, mychar_traits<char> >::InitializeEmptyAnsi()
{
    m_data = g_emptyAnsiString;
    return *this;
}

template <>
StringBase<wchar_t, mychar_traits<wchar_t> > &
StringBase<wchar_t, mychar_traits<wchar_t> >::ShareOrCopyWideFromStringBase(
    const StringBase<wchar_t, mychar_traits<wchar_t> > &source)
{
    wchar_t *sourceData = source.m_data;
    const RefCountedStringBufferHeader *sourceHeader =
        reinterpret_cast<const RefCountedStringBufferHeader *>(sourceData) - 1;

    wchar_t *resultData = g_emptyWideString;
    if (sourceHeader->refCount >= 0) {
        if (sourceData != g_emptyWideString) {
            InterlockedIncrement(
                const_cast<LONG *>(&sourceHeader->refCount));
            resultData = sourceData;
        }

        m_data = resultData;
        return *this;
    }

    if (sourceData == g_emptyWideString) {
        m_data = resultData;
        return *this;
    }

    EnsureWideCapacity(sourceHeader->length);
    memmove(m_data, sourceData, sourceHeader->length * sizeof(wchar_t));
    return *this;
}

template <>
StringBase<wchar_t, mychar_traits<wchar_t> > &
StringBase<wchar_t, mychar_traits<wchar_t> >::InitializeWideFromRange(
    const wchar_t *first,
    const wchar_t *last)
{
    const unsigned int count = static_cast<unsigned int>(last - first);
    AllocateWideBuffer(count);
    memmove(m_data, first, count * sizeof(wchar_t));
    return *this;
}

template <>
StringBase<wchar_t, mychar_traits<wchar_t> > &
StringBase<wchar_t, mychar_traits<wchar_t> >::InitializeEmptyWide()
{
    m_data = g_emptyWideString;
    return *this;
}

template <>
StringBase<char, mychar_traits<char> >::~StringBase()
{
    ReleaseAnsiBuffer();
}

template <>
StringBase<wchar_t, mychar_traits<wchar_t> >::~StringBase()
{
    ReleaseWideBuffer();
}

template <>
StringBase<char, mychar_traits<char> > &
StringBase<char, mychar_traits<char> >::AssignAnsiFromStringBase(
    const StringBase<char, mychar_traits<char> > &source)
{
    char *sourceData = source.m_data;
    if (sourceData == g_emptyAnsiString) {
        m_data = g_emptyAnsiString;
        return *this;
    }

    char *data = m_data;
    if (data == sourceData) {
        return *this;
    }

    RefCountedStringBufferHeader *destinationHeader =
        reinterpret_cast<RefCountedStringBufferHeader *>(data) - 1;
    const RefCountedStringBufferHeader *sourceHeader =
        reinterpret_cast<const RefCountedStringBufferHeader *>(sourceData) - 1;

    if ((destinationHeader->refCount >= 0 || data == g_emptyAnsiString) &&
        sourceHeader->refCount >= 0) {
        ReleaseAnsiBuffer();
        InterlockedIncrement(
            const_cast<LONG *>(&sourceHeader->refCount));
        m_data = sourceData;
        return *this;
    }

    unsigned int copyLength = sourceHeader->length;
    const unsigned int visibleLength =
        static_cast<unsigned int>(strlen(sourceData));
    if (visibleLength < copyLength) {
        copyLength = visibleLength;
    }

    if (destinationHeader->refCount > 1 ||
        destinationHeader->capacity < copyLength) {
        ReleaseAnsiBuffer();
        AllocateAnsiBuffer(copyLength);
        data = m_data;
    }

    memmove(data, sourceData, copyLength);
    return *this;
}

template <>
StringBase<wchar_t, mychar_traits<wchar_t> > &
StringBase<wchar_t, mychar_traits<wchar_t> >::AssignWideFromStringBase(
    const StringBase<wchar_t, mychar_traits<wchar_t> > &source)
{
    wchar_t *sourceData = source.m_data;
    if (sourceData == g_emptyWideString) {
        m_data = g_emptyWideString;
        return *this;
    }

    wchar_t *data = m_data;
    if (data == sourceData) {
        return *this;
    }

    RefCountedStringBufferHeader *destinationHeader =
        reinterpret_cast<RefCountedStringBufferHeader *>(data) - 1;
    const RefCountedStringBufferHeader *sourceHeader =
        reinterpret_cast<const RefCountedStringBufferHeader *>(sourceData) - 1;

    if ((destinationHeader->refCount >= 0 || data == g_emptyWideString) &&
        sourceHeader->refCount >= 0) {
        ReleaseWideBuffer();
        InterlockedIncrement(
            const_cast<LONG *>(&sourceHeader->refCount));
        m_data = sourceData;
        return *this;
    }

    unsigned int copyLength = sourceHeader->length;
    const unsigned int visibleLength =
        static_cast<unsigned int>(wcslen(sourceData));
    if (visibleLength < copyLength) {
        copyLength = visibleLength;
    }

    if (destinationHeader->refCount > 1 ||
        destinationHeader->capacity < copyLength) {
        ReleaseWideBuffer();
        AllocateWideBuffer(copyLength);
        data = m_data;
    }

    memmove(data, sourceData, copyLength * sizeof(wchar_t));
    return *this;
}

template <>
StringBase<wchar_t, mychar_traits<wchar_t> > &
StringBase<wchar_t, mychar_traits<wchar_t> >::AssignWideLiteral(
    const wchar_t *source)
{
    ReleaseWideBuffer();
    const unsigned int count = static_cast<unsigned int>(wcslen(source));
    AllocateWideBuffer(count);
    memmove(m_data, source, count * sizeof(wchar_t));
    return *this;
}

template <>
wchar_t
StringBase<wchar_t, mychar_traits<wchar_t> >::GetWideAt(
    unsigned int index) const
{
    return m_data[index];
}

} // namespace mystr
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

C++ caveats:

- Method names are inferred source-facing names, not symbol-proven final public names.
- `ShareOrCopyAnsiFromStringBase` / `ShareOrCopyWideFromStringBase` intentionally differ from [UID:0002RM] `InitializeAnsiFromStringBase` / `InitializeWideFromStringBase` names because this target owns modeled copy/share helper functions at new addresses and should not duplicate raw-start names already accepted for [UID:0002RM].
- `EnsureAnsiCapacity` is the recommended source-facing name for `0x00584b10`. If implementation keeps existing support wording `GrowAnsiBuffer`, the target should explicitly state that it is the same ANSI capacity-ensure helper.
- The destructor specializations represent the source-relevant body of the two release wrappers; compiler EH/security-cookie scaffolding is not included.
- The assignment helpers intentionally preserve the binary's empty-source fast path without release and the in-place private-copy path without stored-length/terminator rewrite.

## Score Recommendation

Recommended `91/92`:

- Completion rises from `86` to `91` because this pass resolves the previous final-name/source-route/no-code blockers with live MCP-backed behavior, boundary, padding, liveness, dependency-helper, sentinel, type-metadata, source-facing name, owner/emitter, and formal C++ evidence.
- Confidence rises from `89` to `92` because decompilation, disassembly, component analysis, caller/callee counts, sentinel xrefs, dependency helper bodies, and existing StringBaseTemplate support all converge on the same StringBase type-family interpretation.
- The score stays below final audit because exact original public method spellings, exact header/API grouping, relationship to `SimpleUString` facade names, and exact helper declaration order remain source-polish caveats.
- Do not raise above `95` without a full final string-family declaration/API audit.

No unresolved open question blocks first-draft target C++.

## Target Documentation Implementation Requirements

If accepted, update `by-memory/0x005829f0-0x00582d80.StringBaseShareAssignAndAccess.md` at report-level detail:

- Set metadata to `COMPLETION:91`, `CONFIDENCE:92`, `CANONICAL_OWNER:0001WS`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0001WS`, blank `EMITTER_POSITION_OPTIONAL`.
- Replace the Item Summary with the recommended summary.
- Replace stale blank-C++/API-blocker wording with current code-entry rationale and insert the exact formal C++ block from this report.
- Update the covered range table with current source-facing names, exact sizes, roles, and the all-`0xcc` padding boundary table.
- Document live MCP session `80de0a67` evidence categories from this report: function inventory, decompilation/disassembly, component globals, dependency helpers, caller/callee counts, sentinel xrefs, `list_globals` type metadata, and generated-state drift.
- Preserve and highlight corrected behavior details: empty-source assignment path does not release old storage; private-copy reuse path does not update stored length or terminator; destructor wrappers contain compiler EH/security-cookie scaffolding around a single release call.
- Replace raw labels in prose with source-facing names except in evidence/search contexts.
- Add owner/emitter rationale for [UID:0001WS] direct routing through [UID:0000OA].
- Add rejected alternatives and negative evidence from this report.

## Support Documentation Implementation Requirements

Recommended support updates if this report is accepted:

1. `by-type/by-template/StringBaseTemplate.md`
   - Add [UID:0002RN] to the declaration/method inventory and Direct Helper Groups table as a direct `StringBaseTemplate` constructor/destructor/assignment/access helper group.
   - Record the recommended names: `ShareOrCopyAnsiFromStringBase`, `InitializeAnsiFromCountedBytes`, `InitializeEmptyAnsi`, `ShareOrCopyWideFromStringBase`, `InitializeWideFromRange`, `InitializeEmptyWide`, destructor release bodies, `AssignAnsiFromStringBase`, `AssignWideFromStringBase`, `AssignWideLiteral`, and `GetWideAt`.
   - Preserve page-level formal C++ blank for the full template declaration; [UID:0002RN] carries target-specific first-draft C++.

2. `by-file/StringBase.md`
   - Add [UID:0002RN] to likely contents/source-placement notes as the first-draft-emitting share/assign/access helper group that routes directly through [UID:0001WS] but surfaces in `NexusTK/util/StringBase.cpp`.
   - Record the source route correction from file-only owner to template direct owner.
   - Preserve [UID:0000OA] as source root and [UID:0000OB] `StringUtil` as broad context only.

3. `by-memory/0x00582500-0x00583206.StringBaseConstructionAndCow.md`
   - Update the child row/status and Item Summary to reflect [UID:0002RN] as `91/92`, first-draft C++ bearing, and direct [UID:0001WS] owner/emitter.
   - Keep the aggregate non-emitting with `CANONICAL_OWNER:NONE` and `RECONSTRUCTABLE:FALSE`.
   - Update the summary to mention 0002RN alongside 0002RM as a formal-code child if the accepted implementation adds the target C++.

4. `by-type/by-struct/RefCountedStringBufferHeader.md`
   - Add current [UID:0002RN] evidence that copy/share, assignment, and indexed access directly read `refCount`, `length`, and `capacity`; negative refcounts select private-copy behavior; assignment private-copy paths clamp to visible string length.
   - Preserve the current field offsets and negative/non-shareable interpretation.

5. `by-global/StringBufferSentinelsAndPools.md`
   - Add target evidence for `g_emptyAnsiString` refs at `0x005829f3`, `0x00582a80`, `0x00582bb3` and `g_emptyWideString` refs at `0x00582a93`, `0x00582b20`, `0x00582c63`.
   - Preserve global ownership under [UID:0000OA] and pool mechanics under [UID:0000MM].

6. `by-memory/0x00584990-0x00584d7e.StringBaseSpliceGrowAndSubstring.md`
   - Synchronize the `0x00584b10` support name to `EnsureAnsiCapacity` or document `GrowAnsiBuffer` as an accepted synonym for the same ANSI capacity-ensure helper used by [UID:0002RN].
   - Confirm existing `0x00584ba0` `EnsureWideCapacity` wording.
   - No score change is required unless the support edit becomes broader than name/evidence synchronization.

7. `by-memory/0x005832f0-0x00584d7e.StringBaseReleaseFormatAndMutation.md`
   - Optional but useful support sync: ensure the later-helper table names `0x00584b10` consistently with [UID:0002RN] and keeps `0x00584ba0` as `EnsureWideCapacity`.
   - No score change expected.

Check-only support docs unless direct contradiction appears during implementation:

- [UID:0002RO] `StringBaseAllocationGrowAndCow`: already documents `AllocateAnsiBuffer` and `AllocateWideBuffer`; no routine edit expected unless target implementation needs a cross-link.
- [UID:0002RT] `StringBaseReleaseAndCapacity`: already documents `ReleaseAnsiBuffer`, `ReleaseWideBuffer`, and `EnsureWideCapacity`; no routine edit expected unless implementation wants to add [UID:0002RN] as a direct consumer.
- [UID:0002RM] `StringBaseConversionAndCrtShims`: already uses raw-start `Initialize...FromStringBase` names. Do not rename those during this callback; just avoid colliding target names in [UID:0002RN].
- [UID:0001W4] `SimpleUStringPointerBackedLayout`: already sufficient for facade/layout caveats unless implementation adds another evidence row.
- [UID:0000OB] `StringUtil`: check for direct-owner contradiction only; keep it broad context.

## Generated And Coverage State

No validators were run in this report-only pass.

Implementation should run scoped validators for every changed by-* doc from `source-3/project-documentation`, recording command, `command_id`, `command_timestamp`, exit code, `ok` count, and generated-refresh state. Use `--wait-generated` on the target validator if generated `StringBase.cpp` freshness is required.

Suggested target validator after accepted edits:

`python .\tools\validator.py --mode file --file by-memory\0x005829f0-0x00582d80.StringBaseShareAssignAndAccess.md --apply --queue-timeout 240 --wait-generated`

Generated refresh expectation:

- [UID:0002RN] should no longer appear as `76/84` empty emitter marker in `auto-generated/NexusTK/util/StringBase.cpp` after accepted implementation and target validation.
- `auto-generated/-ag-research-tracker.md` and `auto-generated/-ag-coverage-report-by-memory.md` should refresh through validator/executed-report lifecycle, not manual edits.
- If the normal validator path reverts [UID:0002RN] to stale `76/84`, stale Item Summary, or empty marker because of old generated/default state, stop and report `PAUSED_VALIDATOR_METADATA_CONFLICT` with exact output. Do not edit generated files, validator state/cache, project-level generated files, or coverage reports.

## Remaining Open Questions

These are confidence caps, not implementation blockers:

- Exact original public method spelling is not symbol-proven. The recommended names are current best source-facing names based on behavior and project naming.
- Exact public/private header split for `StringBase` is still unresolved. [UID:0001WS] should remain the declaration/type context and [UID:0000OA] the file source root.
- `SimpleUString`, `WideString`, or typedef/facade names may expose some wide helpers publicly. Current direct implementation evidence still favors `mystr::StringBase`.
- `0x00584b10` has existing support wording as `GrowAnsiBuffer`; this report recommends normalizing it to `EnsureAnsiCapacity` for symmetry with `EnsureWideCapacity`, or documenting the synonym explicitly.

No open question justifies leaving [UID:0002RN] without formal C++ or leaving owner/emitter at the coarse file-only route.

## Rejected Alternatives And Negative Evidence

- Do not split this target. All twelve functions are modeled starts, all internal gaps are `0xcc`, and `0x00582d80` is the next successor prologue.
- Do not classify the target as a non-emitting aggregate. It contains exact source-bearing helper bodies.
- Do not keep the old blank-C++ rationale solely because original API spelling is incomplete. The current gate is cleared and behavior is known.
- Do not call `0x00582bb0` / `0x00582c60` fully general public `operator=` bodies without noting the empty-source no-release behavior and in-place no-length-update behavior.
- Do not turn the `0x00582b30` / `0x00582b70` EH/security-cookie frame into source logic.
- Do not rename this to `LObject`; the receiver is pointer-backed `StringBase` storage, not an `LObject` vtable object.
- Do not move ownership to caller modules, `StringUtil`, `PoolAllocator`, or `SimpleUString` facade pages.
- Do not collapse ANSI and wide sentinels or helper names; the binary has separate sentinel globals, allocation helpers, release helpers, and capacity helpers.

## Implementation Tracking Checklist

- [x] Target `by-memory/0x005829f0-0x00582d80.StringBaseShareAssignAndAccess.md`: set metadata to `COMPLETION:91`, `CONFIDENCE:92`, `CANONICAL_OWNER:0001WS`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0001WS`, blank `EMITTER_POSITION_OPTIONAL`. Proof: post-validator reread shows lines 1-6 with UID `0002RN`, `COMPLETION:91`, `CONFIDENCE:92`, `CANONICAL_OWNER:0001WS`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0001WS`.
- [x] Target Item Summary replaced with the recommended `StringBaseTemplate ANSI/wide share-or-copy...` summary. Proof: post-validator reread shows the exact accepted summary in the target metadata block.
- [x] Target formal `RECONSTRUCTION_CPP CODE` populated with the exact block from this report. Proof: target reread shows `ShareOrCopyAnsiFromStringBase`, `AssignAnsiFromStringBase`, `AssignWideFromStringBase`, `AssignWideLiteral`, and `GetWideAt` inside the formal block.
- [x] Target body updated at report-level detail with current MCP provenance, exact function inventory, sizes, padding table, sentinel xrefs, caller/callee counts, dependency helper behavior, source-facing names, owner/emitter rationale, score rationale, and rejected alternatives. Proof: target sections now record MCP session `80de0a67`, the twelve-function table, all-`0xcc` padding gaps, ANSI/wide sentinel refs, dependency helpers, caller/callee counts, owner/emitter rationale, score rationale, and rejected alternatives.
- [x] Target stale assumptions corrected: current code-entry gate replaces old blank-C++/API blocker; empty-source assignment no-release behavior and private-copy no-length-update behavior are documented; destructor security-cookie scaffolding is compiler artifact only. Proof: target status and behavior notes now document all three corrections explicitly.
- [x] `by-type/by-template/StringBaseTemplate.md` synchronized with [UID:0002RN] as a direct template/type helper group and target-specific first-draft C++ route; page-level formal C++ remains blank. Proof: declaration inventory, evidence, Direct Helper Groups, cross-reference, and Changes sections now include [UID:0002RN], while the page formal C++ block remains empty.
- [x] `by-file/StringBase.md` synchronized with [UID:0002RN] as a first-draft-emitting helper group routed through [UID:0001WS] but generated into `NexusTK/util/StringBase.cpp`. Proof: likely contents, evidence, cross-reference, and Changes sections now record the route correction and generated source root.
- [x] `by-memory/0x00582500-0x00583206.StringBaseConstructionAndCow.md` child row/status and summary synchronized while aggregate stays non-emitting. Proof: Item Summary mentions `0002RN` as `91/92` formal StringBaseTemplate C++; Covered Range row routes [UID:0002RN] through [UID:0001WS] and keeps aggregate metadata `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`.
- [x] `by-type/by-struct/RefCountedStringBufferHeader.md` updated with [UID:0002RN] refcount/length/capacity/share/private-copy/assignment evidence if accepted in callback scope. Proof: Evidence and IDA Verification Notes now document [UID:0002RN] reads of `refCount`, `length`, and `capacity`, negative refcount private-copy behavior, visible-length clamping, and indexed access.
- [x] `by-global/StringBufferSentinelsAndPools.md` updated with [UID:0002RN] ANSI/wide empty sentinel references if accepted in callback scope. Proof: Allocation Users/Evidence/Changes now record ANSI refs at `0x005829f3`, `0x00582a80`, `0x00582bb3` and wide refs at `0x00582a93`, `0x00582b20`, `0x00582c63`.
- [x] `by-memory/0x00584990-0x00584d7e.StringBaseSpliceGrowAndSubstring.md` synchronized so `0x00584b10` is `EnsureAnsiCapacity` or explicitly documented as the `GrowAnsiBuffer` synonym used by [UID:0002RN]. Proof: Covered Range, Behavior Notes, Evidence, Cross-References, and Changes now document `EnsureAnsiCapacity` / historical `GrowAnsiBuffer` for `0x00584b10`; `0x00584ba0` remains `EnsureWideCapacity`.
- [x] `by-memory/0x005832f0-0x00584d7e.StringBaseReleaseFormatAndMutation.md` checked and, if needed, support-synchronized for the `0x00584b10` / `0x00584ba0` helper names. Proof: later-helper table and Generated Output Caveats now document `EnsureAnsiCapacity` / `GrowAnsiBuffer` for `0x00584b10` and keep `0x00584ba0` as `EnsureWideCapacity`.
- [x] Check-only support docs reviewed for contradiction: [UID:0002RO], [UID:0002RT], [UID:0002RM], [UID:0001W4], [UID:0000OB]. Proof: `rg` review found [UID:0002RO], [UID:0002RT], and [UID:0002RM] already consistent with allocator/release/raw-start naming; [UID:0001W4] only preserves facade/layout caveats; [UID:0000OB] keeps `StringUtil` as broad context and does not claim direct ownership of [UID:0002RN].
- [x] Scoped validators run for every changed by-* file from `source-3/project-documentation`; record exact command, `command_id`, `command_timestamp`, exit code, `ok` count, and generated-refresh state. Proof:
  - `python .\tools\validator.py --mode file --file by-memory\0x005829f0-0x00582d80.StringBaseShareAssignAndAccess.md --apply --queue-timeout 240 --wait-generated`; `command_id: 000000001799`; `command_timestamp: 2026-06-25T17:08:43-04:00`; exit `0`; `ok: 1`; `generated_refresh: completed`.
  - `python .\tools\validator.py --mode file --file by-type\by-template\StringBaseTemplate.md --apply --queue-timeout 240`; `command_id: 000000001802`; `command_timestamp: 2026-06-25T17:09:14-04:00`; exit `0`; `ok: 1`; `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-file\StringBase.md --apply --queue-timeout 240`; `command_id: 000000001804`; `command_timestamp: 2026-06-25T17:09:24-04:00`; exit `0`; `ok: 1`; `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-memory\0x00582500-0x00583206.StringBaseConstructionAndCow.md --apply --queue-timeout 240`; `command_id: 000000001806`; `command_timestamp: 2026-06-25T17:09:37-04:00`; exit `0`; `ok: 1`; `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-type\by-struct\RefCountedStringBufferHeader.md --apply --queue-timeout 240`; `command_id: 000000001808`; `command_timestamp: 2026-06-25T17:09:42-04:00`; exit `0`; `ok: 1`; `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-global\StringBufferSentinelsAndPools.md --apply --queue-timeout 240`; `command_id: 000000001810`; `command_timestamp: 2026-06-25T17:09:49-04:00`; exit `0`; `ok: 1`; `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-memory\0x00584990-0x00584d7e.StringBaseSpliceGrowAndSubstring.md --apply --queue-timeout 240`; `command_id: 000000001812`; `command_timestamp: 2026-06-25T17:09:54-04:00`; exit `0`; `ok: 1`; `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-memory\0x005832f0-0x00584d7e.StringBaseReleaseFormatAndMutation.md --apply --queue-timeout 240`; `command_id: 000000001814`; `command_timestamp: 2026-06-25T17:10:05-04:00`; exit `0`; `ok: 1`; `generated_refresh: deferred`.
- [x] Target validator run with `--wait-generated` if generated output freshness matters; re-read target and `auto-generated/NexusTK/util/StringBase.cpp` to confirm [UID:0002RN] no longer emits as a stale empty marker. Proof: generated reread shows `// UID:0002RN ... Completion:91 | Confidence:92` and code for `ShareOrCopyAnsiFromStringBase`, `AssignAnsiFromStringBase`, `AssignWideFromStringBase`, `AssignWideLiteral`, and `GetWideAt`; no [UID:0002RN] empty marker remains.
- [x] Generated/tracker/coverage expectations handled through validators/executed-report lifecycle only. No manual edits to `auto-generated/*`, `project-level/*`, validator state/cache, IDA DB, or any `-coverage-report.md`. Proof: generated `StringBase.cpp` and generated/project-level refreshes came from validator command `000000001799` (`autogen_cpp_update: 1`, `memory_auto_coverage_update: 1`, `research_tracker_update: 1`); no manual edits were made to generated, project-level, validator state/cache, IDA DB, or coverage files.
- [x] If validator reverts target metadata/summary/C++ to stale `76/84` or empty marker, report `PAUSED_VALIDATOR_METADATA_CONFLICT` with exact output instead of editing generated/default state. Proof: not triggered; target reread remains `91/92` with accepted summary and formal code.
- [x] Leases taken only for immediate implementation edit/validator batches and released immediately afterward. Proof: B006 acquired the immediate edit set before by-* edits. After validators, `python tools/leaser/leaser.py B006 unlease ...` reported no active B006 lease for the target/aggregate helper pages and B010-owned active leases for overlapping support pages; `current_leases.md` reread shows no B006 active lease rows. No further by-* edits were made after that lease check.

## Report-Only Compliance

- No leases taken.
- No by-* target/support docs edited.
- No generated files edited.
- No project-level files edited.
- No coverage reports edited.
- No validator state/cache edited.
- No IDA DB edits made.
- No subagents spawned.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000004165","destination_path":"executed-b-agent-research/B006/0002RN-StringBaseShareAssignAndAccess-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B006/research/0002RN-StringBaseShareAssignAndAccess-source-quality.md","timestamp":"2026-06-25T17:20:34","uid":"0002RN"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
