** TARGET-REPORT-UID:0002RO **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B005 Report-Only Research: 0002RO StringBase Allocation/Grow/COW Source Quality


## Report Metadata

- Agent: Agent-B005
- Mode: report-only research
- Assignment: `B005-report-0002RO-string-base-allocation-grow-and-cow-source-quality-20260626`
- Target: [UID:0002RO] `by-memory/0x00582d80-0x00583132.StringBaseAllocationGrowAndCow.md`
- Requested report path: `tools/leaser/Agents/Agent-B005/research/0002RO-StringBaseAllocationGrowAndCow-source-quality.md`
- MCP requirement: satisfied
- By-* edits performed: none
- Lease performed: none
- Generated/project-level/manual coverage/tool-state/IDA DB edits performed: none
- Status: `FINISHED_REPORT`

## Executive Recommendation

[UID:0002RO] should no longer remain C++-blank. The current source page is already above the current code-entry gate with `COMPLETION:85`, `CONFIDENCE:89`, `RECONSTRUCTABLE:TRUE`, and valid `EMITTER_UIDS:0001WS`. Live IDA MCP confirms the six helper functions, their exact byte boundaries, allocator paths, sentinel/pool usage, release-helper interaction, and sibling caller relationships. Existing source-quality support from [UID:0001WS] `StringBaseTemplate`, [UID:0000OA] `StringBase.md`, [UID:0001VQ] `RefCountedStringBufferHeader`, [UID:0000TM] `StringBufferSentinelsAndPools`, [UID:0002RN], [UID:0002RT], and [UID:0002RS] supplies enough project-level naming context for a first-draft formal reconstruction.

Recommended implementation action:

- Keep `CANONICAL_OWNER:0001WS`.
- Keep `EMITTER_UIDS:0001WS`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Raise to `COMPLETION:91`, `CONFIDENCE:92`.
- Populate `RECONSTRUCTION_CPP` with the formal block in this report.
- Update support docs only where they describe the StringBase method inventory and parent child status. Do not edit generated coverage or project-level tracker files by hand.

The remaining uncertainty is not behavioral. It is limited to final original-header spelling and whether the real source spelled these as public member helpers or private implementation helpers. That uncertainty is already compatible with first-draft C++ and should not keep this page blank.

## Current Target State

The authoritative target source page currently reports:

- `UID:0002RO`
- `COMPLETION:85`
- `CONFIDENCE:89`
- `CANONICAL_OWNER:0001WS`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0001WS`
- `RECONSTRUCTION_CPP` blank
- Item summary: ANSI/wide allocation, pool/heap choice, grow, and detach-on-share primitives over the 12-byte ref-counted string header.

Generated reports are stale relative to the source page:

- `auto-generated/-ag-research-tracker.md` still lists 0002RO as `78/86`, average `82.0`, no executed report.
- `auto-generated/-ag-coverage-report-by-memory.md` still lists 0002RO as `emits_code:false`, 78 percent strong.

These generated files are read-only for this assignment. The implementation callback should refresh them through the validator only.

## Current Code-Entry Gate Recheck

The current gate is satisfied:

- `RECONSTRUCTABLE:TRUE`: yes.
- Valid emitter: yes, `EMITTER_UIDS:0001WS`.
- Average score: `(85 + 89) / 2 = 87`, which is above 85.
- Code ownership: direct semantic owner is [UID:0001WS] `StringBaseTemplate`; file route is [UID:0000OA] `StringBase.md`.
- Evidence requirement: live MCP evidence was collected in this pass and agrees with the source documentation.

The old "95+ final audit" framing is not the current code-entry gate. It should not be used to keep this target blank.

## MCP Availability And Session

IDA MCP was available and responsive. I did not manage MCP or IDA.

Observed MCP session facts:

- Endpoint: `http://127.0.0.1:13337/mcp`
- Server: `ida-pro-mcp` version `1.0.0`
- Protocol: `2025-06-18`
- Database session: `80de0a67`
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Input path: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- Module: `NexusTK.exe`
- Imagebase: `0x400000`
- `auto_analysis_ready`: true
- `hexrays_ready`: true
- `strings_cache_ready`: true
- IDB `is_analyzing`: false

MCP tools used included `server_health`, `idb_list`, `lookup_funcs`, `entity_query`, `analyze_component`, `analyze_function`, `xrefs_to`, and `get_bytes`.

## Function Inventory

Live MCP confirms exactly six target functions in the target range:

| Address | IDA name | Size | Recommended source-facing name | Role |
| --- | --- | ---: | --- | --- |
| `0x00582d80` | `sub_582D80` | `0xac` | `AllocateAnsiBuffer` | Allocate or attach the ANSI empty sentinel, choose ANSI fixed pool or heap, initialize header and terminator. |
| `0x00582e30` | `sub_582E30` | `0xb2` | `AllocateWideBuffer` | Allocate or attach the wide empty sentinel, choose wide fixed pool or heap, initialize header and terminator. |
| `0x00582ef0` | `sub_582EF0` | `0xa8` | `GrowAnsiBuffer` | Retain old ANSI buffer, release current reference, allocate old length plus additional bytes, copy old payload, release retained old reference. |
| `0x00582fa0` | `sub_582FA0` | `0xab` | `GrowWideBuffer` | Wide twin of `GrowAnsiBuffer`, using UTF-16 element counts and byte copy size `2 * oldLength`. |
| `0x00583050` | `sub_583050` | `0x6f` | `DetachAnsiIfShared` | Copy-on-write detach for ANSI when `refCount > 1`; otherwise no-op. |
| `0x005830c0` | `sub_5830C0` | `0x72` | `DetachWideIfShared` | Wide copy-on-write detach when `refCount > 1`; otherwise no-op. |

Adjacent boundaries:

- `0x00582d70` is predecessor `sub_582D70` in sibling [UID:0002RN].
- `0x00583132` is not a function start.
- `0x00583140` is successor `sub_583140` in sibling [UID:0002RP].

No hidden modeled functions were found inside `0x00582d80-0x00583132`.

## Exact Range And Padding

The target range is correct and should not be split:

| Bytes | Classification |
| --- | --- |
| `0x00582d80-0x00582e2c` | `sub_582D80` body |
| `0x00582e2c-0x00582e30` | four `0xcc` padding bytes |
| `0x00582e30-0x00582ee2` | `sub_582E30` body |
| `0x00582ee2-0x00582ef0` | fourteen `0xcc` padding bytes |
| `0x00582ef0-0x00582f98` | `sub_582EF0` body |
| `0x00582f98-0x00582fa0` | eight `0xcc` padding bytes |
| `0x00582fa0-0x0058304b` | `sub_582FA0` body |
| `0x0058304b-0x00583050` | five `0xcc` padding bytes |
| `0x00583050-0x005830bf` | `sub_583050` body |
| `0x005830bf-0x005830c0` | one `0xcc` padding byte |
| `0x005830c0-0x00583132` | `sub_5830C0` body |
| `0x00583132-0x00583140` | fourteen `0xcc` padding bytes before successor |

The `0x00583132-0x00583140` padding belongs to the parent aggregation boundary. It does not need a new child and should not be modeled as emitted code.

## Behavioral Evidence By Function

### `0x00582d80` - `AllocateAnsiBuffer`

IDA prototype:

- `void *__thiscall(_DWORD *this, unsigned int)`

Behavior:

- If requested length is zero, writes the ANSI empty sentinel pointer `0x00670290` into `*this`.
- For nonzero length, selects storage by requested character capacity:
  - `<= 0x40`: allocate from `0x0069bb6c`, capacity field `64`.
  - `<= 0x80`: allocate from `0x0069bb94`, capacity field `128`.
  - `<= 0x100`: allocate from `0x0069bbbc`, capacity field `256`.
  - `<= 0x200`: allocate from `0x0069bbe4`, capacity field `512`.
  - `> 0x200`: heap allocation through `operator new(length + 13)`, capacity field `length`.
- Initializes `header->refCount = 1`.
- Initializes `header->length = length`.
- Writes `data[length] = '\0'`.
- Stores and returns the data pointer, which is `header + 0x0c`.

Source-quality conclusion:

- Name should be `AllocateAnsiBuffer`.
- It is a StringBase buffer-allocation method, not a PoolAllocator-owned function.
- The accepted formal reconstruction must inline the ANSI pool-selection and header-initialization logic inside this function. It must not define a local helper, namespace helper, lambda, or standalone source body for the pool-selection logic.

### `0x00582e30` - `AllocateWideBuffer`

IDA prototype:

- `void *__thiscall(_DWORD *this, unsigned int)`

Behavior:

- If requested length is zero, writes the wide empty sentinel pointer `0x00670278` into `*this`.
- For nonzero length, selects storage by requested wide-character capacity:
  - `<= 0x40`: allocate from `0x0069bacc`, capacity field `64`.
  - `<= 0x80`: allocate from `0x0069baf4`, capacity field `128`.
  - `<= 0x100`: allocate from `0x0069bb1c`, capacity field `256`.
  - `<= 0x200`: allocate from `0x0069bb44`, capacity field `512`.
  - `> 0x200`: heap allocation through `operator new(length * 2 + 14)`, capacity field `length`.
- Initializes `header->refCount = 1`.
- Initializes `header->length = length`.
- Writes `data[length] = L'\0'`.
- Stores and returns the wide data pointer.

Source-quality conclusion:

- Name should be `AllocateWideBuffer`.
- The function is the wide twin of `AllocateAnsiBuffer`.
- The `length * sizeof(wchar_t) + sizeof(RefCountedStringBufferHeader) + sizeof(wchar_t)` allocation expression exactly accounts for the observed `2 * length + 14` heap size on Windows.

### `0x00582ef0` - `GrowAnsiBuffer`

IDA prototype:

- `volatile LONG *__thiscall(void **this, unsigned int)`

Behavior:

- Reads the current ANSI data pointer.
- If current data equals `0x00670290`, calls `AllocateAnsiBuffer(additionalLength)` and returns.
- Otherwise, increments the old header refcount with `InterlockedIncrement`.
- Saves the old pointer in a local temporary.
- Calls `ReleaseAnsiBuffer` on the current object.
- Calls `AllocateAnsiBuffer(additionalLength + oldLength)`.
- Copies exactly `oldLength` bytes with `memmove`.
- Releases the retained old pointer through `ReleaseAnsiBuffer`.

Source-quality conclusion:

- Name should be `GrowAnsiBuffer`.
- This is an append-growth helper that takes an additional byte count, not a generic capacity checker.
- It is distinct from later [UID:0003NM] / [UID:0001J3] helper `0x00584b10`, whose source-facing name should remain `EnsureAnsiCapacity`.

### `0x00582fa0` - `GrowWideBuffer`

IDA prototype:

- `volatile LONG *__thiscall(void **this, unsigned int)`

Behavior:

- Reads the current wide data pointer.
- If current data equals `0x00670278`, calls `AllocateWideBuffer(additionalLength)` and returns.
- Otherwise, increments the old header refcount with `InterlockedIncrement`.
- Saves the old pointer in a local temporary.
- Calls `ReleaseWideBuffer` on the current object.
- Calls `AllocateWideBuffer(additionalLength + oldLength)`.
- Copies exactly `oldLength * sizeof(wchar_t)` bytes with `memmove`.
- Releases the retained old pointer through `ReleaseWideBuffer`.

Source-quality conclusion:

- Name should be `GrowWideBuffer`.
- This is the wide append-growth twin of `GrowAnsiBuffer`.
- It is distinct from later `0x00584ba0`, whose source-facing name should remain `EnsureWideCapacity`.

### `0x00583050` - `DetachAnsiIfShared`

IDA prototype:

- `volatile LONG *__thiscall(const void **this)`

Behavior:

- Reads current ANSI data pointer and its header.
- If `refCount <= 1`, returns without changing the object.
- If `refCount > 1`:
  - saves the old pointer in a local temporary,
  - stores old `length`,
  - calls `AllocateAnsiBuffer(length)`,
  - copies `length` bytes with `memmove`,
  - releases the old pointer through `ReleaseAnsiBuffer`.

Source-quality conclusion:

- Name should be `DetachAnsiIfShared`.
- `DetachAnsiForWrite` is a reasonable conceptual synonym, but `DetachAnsiIfShared` matches the already accepted source vocabulary in [UID:0002RQ] for the corresponding wide COW helper.

### `0x005830c0` - `DetachWideIfShared`

IDA prototype:

- `volatile LONG *__thiscall(const void **this)`

Behavior:

- Reads current wide data pointer and its header.
- If `refCount <= 1`, returns without changing the object.
- If `refCount > 1`:
  - saves the old pointer in a local temporary,
  - stores old `length`,
  - calls `AllocateWideBuffer(length)`,
  - copies `length * sizeof(wchar_t)` bytes with `memmove`,
  - releases the old pointer through `ReleaseWideBuffer`.

Source-quality conclusion:

- Name should be `DetachWideIfShared`.
- This is the canonical COW detach helper for wide StringBase storage in this range.

## Sentinel And Pool Evidence

Sentinels:

| Address | Current IDA/global doc name | Role in target |
| --- | --- | --- |
| `0x00670290` | `off_670290`, `g_emptyAnsiBuffer`, `g_emptyAnsiString` | Empty ANSI string data pointer used by `AllocateAnsiBuffer` and `GrowAnsiBuffer`. |
| `0x00670278` | `Src`, `g_emptyWideBuffer`, `g_emptyWideString` | Empty wide string data pointer used by `AllocateWideBuffer` and `GrowWideBuffer`. |

ANSI pools:

| Address | Recommended name | Target allocation xref | Other expected xrefs |
| --- | --- | --- | --- |
| `0x0069bb6c` | `g_ansiPool64` | `0x00582da0` | constructor, release, cleanup |
| `0x0069bb94` | `g_ansiPool128` | `0x00582dbb` | constructor, release, cleanup |
| `0x0069bbbc` | `g_ansiPool256` | `0x00582dd6` | constructor, release, cleanup |
| `0x0069bbe4` | `g_ansiPool512` | `0x00582df1` | constructor, release, cleanup |

Wide pools:

| Address | Recommended name | Target allocation xref | Other expected xrefs |
| --- | --- | --- | --- |
| `0x0069bacc` | `g_widePool64` | `0x00582e50` | constructor, release, cleanup |
| `0x0069baf4` | `g_widePool128` | `0x00582e6b` | constructor, release, cleanup |
| `0x0069bb1c` | `g_widePool256` | `0x00582e86` | constructor, release, cleanup |
| `0x0069bb44` | `g_widePool512` | `0x00582ea1` | constructor, release, cleanup |

Pool xref pattern:

- Each pool has exactly the expected four-reference pattern: static construction, allocation, release, and cleanup.
- Live IDA still names the PoolAllocator methods as raw `sub_4B1400` and `sub_4B14C0`, but source documentation already resolves them as `PoolAllocator::Allocate()` and `PoolAllocator::Free(void*)`.
- `0x004b1400` decompiles as a critical-section protected free-list allocator and is correctly represented as `PoolAllocator::Allocate()`.
- `unknown_libname_19` at `0x005c7790` decompiles as `operator new(size_t)` and is correctly represented as `::operator new(...)`.

## Header Layout Evidence

The six functions all use the same 12-byte header immediately before the data pointer:

| Data-relative offset | Field | Evidence in target |
| --- | --- | --- |
| `data[-0x0c]` | `refCount` | Written as `1` by allocation helpers; incremented by grow helpers; tested by detach helpers. |
| `data[-0x08]` | `length` | Written as requested length by allocation helpers; read by grow/detach helpers for copy size and new length. |
| `data[-0x04]` | `capacity` | Written as pool threshold capacity or exact heap length by allocation helpers. |
| `data[0]` | `char[]` or `wchar_t[]` | Returned data pointer; target writes a null terminator at `length`. |

This agrees with [UID:0001VQ] `RefCountedStringBufferHeader`.

## Caller And Callee Evidence

Target-internal callee relationships:

- `GrowAnsiBuffer` calls `ReleaseAnsiBuffer`, `AllocateAnsiBuffer`, `memmove`, and `InterlockedIncrement`.
- `GrowWideBuffer` calls `ReleaseWideBuffer`, `AllocateWideBuffer`, `memmove`, and `InterlockedIncrement`.
- `DetachAnsiIfShared` calls `AllocateAnsiBuffer`, `memmove`, and `ReleaseAnsiBuffer`.
- `DetachWideIfShared` calls `AllocateWideBuffer`, `memmove`, and `ReleaseWideBuffer`.

Important external callers:

| Target helper | Representative caller evidence | Interpretation |
| --- | --- | --- |
| `AllocateAnsiBuffer` | called from construction/assignment helpers, this target's ANSI grow/detach helpers, and later `EnsureAnsiCapacity` | Foundational StringBase ANSI allocator. |
| `AllocateWideBuffer` | called from construction/assignment helpers, this target's wide grow/detach helpers, format/trim/split helpers, and later `EnsureWideCapacity` | Foundational StringBase wide allocator. |
| `GrowAnsiBuffer` | called from `0x00584160`, `0x00584200`, `0x00584280` in [UID:0002RS] | Append slow paths need additional capacity and preserve old contents. |
| `GrowWideBuffer` | called from `0x00584320`, `0x005843d0`, `0x00584470` in [UID:0002RS] | Wide append slow paths need additional capacity and preserve old contents. |
| `DetachAnsiIfShared` | called from `0x0049c800`, `0x0057bc60`, `0x005c0940`, `0x005c09f0` | Shared ANSI write/detach sites outside the immediate StringBase construction cluster. |
| `DetachWideIfShared` | called from `0x004918e0`, `0x0049cad0`, `0x004b2730`, `0x004b5c40`, `0x00583e70`, `0x00584600`, `0x005c2ac0` | Shared wide write/detach sites, including StringBase mutation helpers. |

Sibling support:

- [UID:0002RS] already uses `GrowAnsiBuffer` and `GrowWideBuffer` in accepted formal C++ for append slow paths.
- [UID:0002RT] already provides `ReleaseAnsiBuffer` and `ReleaseWideBuffer`, which are the release helpers used here.
- [UID:0002RQ] already uses `DetachWideIfShared` as source-facing COW vocabulary.
- [UID:0002RN] already references `AllocateAnsiBuffer` and `AllocateWideBuffer` in accepted constructor/assignment reconstruction.

## Ownership Analysis

Recommended owner/emitter:

- `CANONICAL_OWNER:0001WS`
- `EMITTER_UIDS:0001WS`

Rationale:

- Live RTTI/type metadata includes `mystr::StringBase< wchar_t, mychar_traits<wchar_t> >`.
- The target functions operate on the `StringBase` single-pointer object layout and the shared `RefCountedStringBufferHeader`.
- The source root is [UID:0000OA] `StringBase.md`, but the semantic method owner is [UID:0001WS] `StringBaseTemplate`.
- Sibling pages [UID:0002RN], [UID:0002RT], [UID:0002RS], and [UID:0002RQ] now consistently route StringBase method bodies through the StringBase file/template model.

Rejected owners:

- `PoolAllocator`: owns allocator mechanics only. The pool globals are consumed by StringBase allocation/release helpers.
- `RefCountedStringBufferHeader`: owns layout evidence only, not behavior.
- `StringBufferSentinelsAndPools`: owns global storage and pool instances only, not the helper methods.
- `LObject` or caller modules: caller pollution from stale generated rows and external mutators; no direct ownership.
- `SimpleUString` or facade classes: possible public typedef/facade context, but not the direct owner of this byte range.
- File-only [UID:0000OA] as canonical owner: correct source root, but less precise than the accepted template owner [UID:0001WS].

## Name Resolution

Accepted names:

| Address | Accepted source-facing name |
| --- | --- |
| `0x00582d80` | `AllocateAnsiBuffer` |
| `0x00582e30` | `AllocateWideBuffer` |
| `0x00582ef0` | `GrowAnsiBuffer` |
| `0x00582fa0` | `GrowWideBuffer` |
| `0x00583050` | `DetachAnsiIfShared` |
| `0x005830c0` | `DetachWideIfShared` |

Rejected or downgraded alternatives:

- `EnsureAnsiCapacity` / `EnsureWideCapacity` for `0x00582ef0` / `0x00582fa0`: reject. These names are already reserved by current support docs for later helpers `0x00584b10` and `0x00584ba0`, which perform capacity-check behavior. The target grow helpers take an additional count and allocate a new total length after retaining/releasing the old buffer.
- `ReserveAdditionalAnsi` / `ReserveAdditionalWide`: possible semantic description, but weaker than accepted sibling usage. [UID:0002RS] already calls these helpers `GrowAnsiBuffer` and `GrowWideBuffer`.
- `CopyOnWriteAnsi` / `CopyOnWriteWide`: too broad and confusable with assignment/copy helpers. `Detach*IfShared` is clearer and already matches local vocabulary.
- `AllocateStringBuffer`: too generic; the target has exact ANSI and wide twins.
- Raw IDA names `sub_582D80`, `sub_582E30`, `sub_582EF0`, `sub_582FA0`, `sub_583050`, `sub_5830C0`: implementation placeholders only, not source-facing names.

## Source Placement Recommendation

The generated C++ should be emitted through:

- Owner: [UID:0001WS] `StringBaseTemplate`
- Source file root: [UID:0000OA] `StringBase.md`
- Probable path: `NexusTK/util/StringBase.cpp`

Support documentation should treat this as a direct StringBase template helper group. It should not become a new source file and should not be moved under PoolAllocator.

## Reclassification Recommendation

No reclassification is needed:

- Keep as a by-memory target.
- Keep parent [UID:0001J1] as non-emitting aggregation.
- Keep six functions under one target because they are tightly paired ANSI/wide allocation, growth, and COW primitives over the same header and global pool model.
- Do not create a padding target for `0x00583132-0x00583140`.
- Do not split allocation from grow/detach unless a future source audit proves separate original helper ownership. Current evidence favors a single source-quality child for this helper cluster.

## Negative Evidence Summary

Negative evidence checked and resolved:

- Live IDA does not have compiler-recovered names for the six helpers. That is expected and does not outweigh source-quality evidence from sibling reports and decompilation.
- Live IDA still names `PoolAllocator::Allocate` as `sub_4B1400`. The PoolAllocator support docs and decompilation semantics resolve the source-facing name; raw IDA naming should not block 0002RO.
- Generated tracker and coverage rows are stale at `78/86` and `emits_code:false`. The target source page is newer and authoritative; generated files must be refreshed by validator.
- The exact public API/header declaration remains uncertain. That affects final polish, not whether a first-draft reconstruction should exist.
- The original source may have used private helper names rather than exactly public method names. Current sibling pages already use these helper names, so consistency is more valuable than keeping a blank page.

## Inference Claim Ledger

| Claim | Evidence type | Strength | Disposition |
| --- | --- | --- | --- |
| Six functions exactly cover the target body. | MCP `lookup_funcs`, `entity_query`, `get_bytes` | Strong | Accepted. |
| 0002RO belongs to StringBaseTemplate. | Target page, sibling docs, RTTI/type metadata, behavior | Strong | Accepted. |
| `AllocateAnsiBuffer` / `AllocateWideBuffer` names are source-ready. | Sibling [UID:0002RN], direct behavior, allocator model | Strong | Accepted. |
| `GrowAnsiBuffer` / `GrowWideBuffer` names are source-ready for `0x00582ef0`/`0x00582fa0`. | Sibling [UID:0002RS] accepted C++ and direct callers | Strong | Accepted. |
| `EnsureAnsiCapacity` / `EnsureWideCapacity` should not name this pair. | Later helper docs [UID:0001J3]/[UID:0003NM], behavior difference | Strong | Rejected for this pair. |
| `DetachAnsiIfShared` / `DetachWideIfShared` names are source-ready. | Direct behavior, [UID:0002RQ] vocabulary, caller usage | Medium-strong | Accepted. |
| Score can move to 91/92. | Gate satisfied, live MCP recheck, sibling score pattern | Strong | Recommended. |
| Formal code should be emitted now. | Gate satisfied, behavior complete, owner/emitter valid | Strong | Recommended. |

## IDA Rename/Type/Comment Recommendations

These are IDA-side recommendations only. This report did not edit the IDA DB.

Function names:

- Rename `sub_582D80` to `StringBase_AllocateAnsiBuffer` or the project-standard demangled equivalent.
- Rename `sub_582E30` to `StringBase_AllocateWideBuffer`.
- Rename `sub_582EF0` to `StringBase_GrowAnsiBuffer`.
- Rename `sub_582FA0` to `StringBase_GrowWideBuffer`.
- Rename `sub_583050` to `StringBase_DetachAnsiIfShared`.
- Rename `sub_5830C0` to `StringBase_DetachWideIfShared`.

Type suggestions:

- Model data pointers as `char *` and `wchar_t *` members of `mystr::StringBase`.
- Model `data - 0x0c` as `RefCountedStringBufferHeader`.
- Model pool globals as `PoolAllocator` instances.
- Model `sub_4B1400` as `PoolAllocator::Allocate()`.
- Model `sub_4B14C0` as `PoolAllocator::Free(void *)`.
- Model `unknown_libname_19` as `operator new(size_t)`.

Comment suggestions:

- At `0x00582d80`: "ANSI StringBase buffer allocation; zero length attaches shared empty sentinel; nonzero selects 64/128/256/512 pool or heap."
- At `0x00582e30`: "Wide StringBase buffer allocation; capacity is in wchar_t elements."
- At `0x00582ef0`: "Grow ANSI buffer by additional length; retain old header before releasing current pointer."
- At `0x00582fa0`: "Grow wide buffer by additional length; copy oldLength * sizeof(wchar_t)."
- At `0x00583050`: "Detach ANSI buffer only when shared."
- At `0x005830c0`: "Detach wide buffer only when shared."

## Proposed Target Metadata

Recommended header changes for `by-memory/0x00582d80-0x00583132.StringBaseAllocationGrowAndCow.md`:

```text
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0001WS | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0001WS | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Recommended item summary:

```text
StringBaseTemplate ANSI/wide allocation, append-growth, and detach-if-shared primitives over the 12-byte ref-counted string buffer header.
```

## Formal C++ Recommendation

Insert the following in the target page's `RECONSTRUCTION_CPP` field during implementation. This is intended as a first-draft reconstruction aligned with existing StringBase sibling pages, the current source-quality gate, and the current Rule 26 range standard.

Range-safe source-shape decision:

- The formal block emits exactly the six modeled functions in [UID:0002RO]: `AllocateAnsiBuffer`, `AllocateWideBuffer`, `GrowAnsiBuffer`, `GrowWideBuffer`, `DetachAnsiIfShared`, and `DetachWideIfShared`.
- It intentionally does not define `AllocateAnsiHeader`, `AllocateWideHeader`, `HeaderFromData`, lambdas, local namespace helpers, or any other standalone function body. Pool selection and header-pointer recovery are inlined inside the six target functions.
- Calls to `ReleaseAnsiBuffer` and `ReleaseWideBuffer` are calls to already-modeled sibling functions from [UID:0002RT]. They are callees of the target functions in the binary, not additional function bodies emitted by 0002RO.
- The previous `StringBase<char, mychar_traits<char> > oldValue; oldValue.m_data = oldData;` source shape is removed from this recommendation. Although sibling documentation has used that shape as a readable stand-in, it can imply constructor/destructor cleanup bodies outside the target range. This report's corrected formal block uses a direct one-pointer slot call instead: it treats the local saved data pointer's address as a `StringBase<T>` receiver only for the existing release call. That matches the binary call shape `Release*( &savedOldDataPointer )`, avoids constructing a temporary object, avoids an implicit destructor, and does not introduce an out-of-range helper body.
- The `reinterpret_cast` receiver in the release lines is a range-faithful representation of the documented `StringBase<T>` layout: the object is one data pointer at offset zero. It should not be factored into a new helper during implementation.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
namespace mystr {

template <>
char *
StringBase<char, mychar_traits<char> >::AllocateAnsiBuffer(unsigned int length)
{
    if (length == 0) {
        m_data = g_emptyAnsiString;
        return m_data;
    }

    RefCountedStringBufferHeader *header = 0;
    if (length <= 64) {
        header = static_cast<RefCountedStringBufferHeader *>(
            g_ansiPool64.Allocate());
        header->capacity = 64;
    } else if (length <= 128) {
        header = static_cast<RefCountedStringBufferHeader *>(
            g_ansiPool128.Allocate());
        header->capacity = 128;
    } else if (length <= 256) {
        header = static_cast<RefCountedStringBufferHeader *>(
            g_ansiPool256.Allocate());
        header->capacity = 256;
    } else if (length <= 512) {
        header = static_cast<RefCountedStringBufferHeader *>(
            g_ansiPool512.Allocate());
        header->capacity = 512;
    } else {
        header = static_cast<RefCountedStringBufferHeader *>(
            ::operator new(length +
                           sizeof(RefCountedStringBufferHeader) +
                           sizeof(char)));
        header->capacity = length;
    }

    header->refCount = 1;
    header->length = length;
    char *data = reinterpret_cast<char *>(header + 1);
    data[length] = '\0';
    m_data = data;
    return m_data;
}

template <>
wchar_t *
StringBase<wchar_t, mychar_traits<wchar_t> >::AllocateWideBuffer(
    unsigned int length)
{
    if (length == 0) {
        m_data = g_emptyWideString;
        return m_data;
    }

    RefCountedStringBufferHeader *header = 0;
    if (length <= 64) {
        header = static_cast<RefCountedStringBufferHeader *>(
            g_widePool64.Allocate());
        header->capacity = 64;
    } else if (length <= 128) {
        header = static_cast<RefCountedStringBufferHeader *>(
            g_widePool128.Allocate());
        header->capacity = 128;
    } else if (length <= 256) {
        header = static_cast<RefCountedStringBufferHeader *>(
            g_widePool256.Allocate());
        header->capacity = 256;
    } else if (length <= 512) {
        header = static_cast<RefCountedStringBufferHeader *>(
            g_widePool512.Allocate());
        header->capacity = 512;
    } else {
        header = static_cast<RefCountedStringBufferHeader *>(
            ::operator new(length * sizeof(wchar_t) +
                           sizeof(RefCountedStringBufferHeader) +
                           sizeof(wchar_t)));
        header->capacity = length;
    }

    header->refCount = 1;
    header->length = length;
    wchar_t *data = reinterpret_cast<wchar_t *>(header + 1);
    data[length] = L'\0';
    m_data = data;
    return m_data;
}

template <>
void
StringBase<char, mychar_traits<char> >::GrowAnsiBuffer(
    unsigned int additionalLength)
{
    char *oldData = m_data;
    if (oldData == g_emptyAnsiString) {
        AllocateAnsiBuffer(additionalLength);
        return;
    }

    const RefCountedStringBufferHeader *oldHeader =
        reinterpret_cast<const RefCountedStringBufferHeader *>(oldData) - 1;
    const unsigned int oldLength = oldHeader->length;
    InterlockedIncrement(const_cast<LONG *>(&oldHeader->refCount));

    ReleaseAnsiBuffer();
    AllocateAnsiBuffer(oldLength + additionalLength);
    memmove(m_data, oldData, oldLength);

    reinterpret_cast<StringBase<char, mychar_traits<char> > *>(&oldData)
        ->ReleaseAnsiBuffer();
}

template <>
void
StringBase<wchar_t, mychar_traits<wchar_t> >::GrowWideBuffer(
    unsigned int additionalLength)
{
    wchar_t *oldData = m_data;
    if (oldData == g_emptyWideString) {
        AllocateWideBuffer(additionalLength);
        return;
    }

    const RefCountedStringBufferHeader *oldHeader =
        reinterpret_cast<const RefCountedStringBufferHeader *>(oldData) - 1;
    const unsigned int oldLength = oldHeader->length;
    InterlockedIncrement(const_cast<LONG *>(&oldHeader->refCount));

    ReleaseWideBuffer();
    AllocateWideBuffer(oldLength + additionalLength);
    memmove(m_data, oldData, oldLength * sizeof(wchar_t));

    reinterpret_cast<StringBase<wchar_t, mychar_traits<wchar_t> > *>(&oldData)
        ->ReleaseWideBuffer();
}

template <>
void
StringBase<char, mychar_traits<char> >::DetachAnsiIfShared()
{
    char *oldData = m_data;
    RefCountedStringBufferHeader *oldHeader =
        reinterpret_cast<RefCountedStringBufferHeader *>(oldData) - 1;
    if (oldHeader->refCount <= 1) {
        return;
    }

    const unsigned int length = oldHeader->length;

    AllocateAnsiBuffer(length);
    memmove(m_data, oldData, length);

    reinterpret_cast<StringBase<char, mychar_traits<char> > *>(&oldData)
        ->ReleaseAnsiBuffer();
}

template <>
void
StringBase<wchar_t, mychar_traits<wchar_t> >::DetachWideIfShared()
{
    wchar_t *oldData = m_data;
    RefCountedStringBufferHeader *oldHeader =
        reinterpret_cast<RefCountedStringBufferHeader *>(oldData) - 1;
    if (oldHeader->refCount <= 1) {
        return;
    }

    const unsigned int length = oldHeader->length;

    AllocateWideBuffer(length);
    memmove(m_data, oldData, length * sizeof(wchar_t));

    reinterpret_cast<StringBase<wchar_t, mychar_traits<wchar_t> > *>(&oldData)
        ->ReleaseWideBuffer();
}

} // namespace mystr
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

## Support Documentation Recommendations

Recommended support-doc changes during implementation:

- `by-file/StringBase.md`: add/update a current evidence note that [UID:0002RO] now carries first-draft formal C++ for `AllocateAnsiBuffer`, `AllocateWideBuffer`, `GrowAnsiBuffer`, `GrowWideBuffer`, `DetachAnsiIfShared`, and `DetachWideIfShared`; mention the 91/92 recommendation after execution.
- `by-type/by-template/StringBaseTemplate.md`: add the six 0002RO helper names to the method inventory and direct helper table. Keep 0001WS as the semantic owner/emitter route.
- `by-memory/0x00582500-0x00583206.StringBaseConstructionAndCow.md`: update the child row/status for 0002RO and preserve the `0x00583132-0x00583140` padding note.
- Optional support sync only if already in edit scope: `by-type/by-struct/RefCountedStringBufferHeader.md` may add 0002RO as direct allocation/grow/detach evidence for `refCount`, `length`, and `capacity`.
- Optional support sync only if already in edit scope: `by-global/StringBufferSentinelsAndPools.md` may add current MCP confirmation that 0002RO consumes the eight StringBase pool globals and two empty sentinels.

Recommended no-change/check-only support docs:

- [UID:0002RN] already supports `AllocateAnsiBuffer` / `AllocateWideBuffer`.
- [UID:0002RT] already supports `ReleaseAnsiBuffer` / `ReleaseWideBuffer`.
- [UID:0002RS] already supports `GrowAnsiBuffer` / `GrowWideBuffer` as append slow-path dependencies.
- [UID:0002RQ] already supports `DetachWideIfShared` vocabulary.
- [UID:0001J3] and [UID:0003NM] already reserve `EnsureAnsiCapacity` / `EnsureWideCapacity` for the later `0x00584b10` / `0x00584ba0` helpers.
- `by-file/PoolAllocator.md` and `by-type/by-struct/PoolAllocatorLayout.md` already support the `PoolAllocator::Allocate` and pool-layout evidence.

## Manual Coverage / Tracker Text

No manual coverage text is recommended in this report-only assignment.

Generated rows are stale and should be refreshed by validator after implementation. Do not manually edit:

- `auto-generated/-ag-research-tracker.md`
- `auto-generated/-ag-coverage-report-by-memory.md`
- any `-coverage-report.md`

No project-level tracker or tool-state edits are required from Agent-B005.

## Validator Recommendation

This report-only pass did not run the by-* validator because no by-* documents were changed.

Implementation callback should run scoped validation after applying target/support changes. Suggested commands from `source-3/project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0002RO-StringBaseAllocationGrowAndCow-source-quality-removed.md](0002RO-StringBaseAllocationGrowAndCow-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If support docs are edited, run the same file-scoped validator for each edited support document. After validation, re-read the target page and generated outputs to ensure:

- target header reports `91/92`;
- `RECONSTRUCTION_CPP` is nonblank and preserved;
- generated StringBase output contains the six 0002RO function bodies and no 0002RO-owned standalone helper definitions;
- generated coverage/tracker rows no longer report stale `78/86` or `emits_code:false`.

Supervisor execution path, if using report execution:

> Executable block R002 was removed from this report and preserved verbatim in [0002RO-StringBaseAllocationGrowAndCow-source-quality-removed.md](0002RO-StringBaseAllocationGrowAndCow-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

The implementation agent should adjust command spelling only if the validator help for this workspace differs.

## Open Questions And Resolutions

1. Should 0002RO stay blank until original public API names are exact?

   Resolution: no. Current gate is satisfied and behavior is fully reconstructable. Exact public header polish is a final-audit concern, not a first-draft blocker.

2. Should `GrowAnsiBuffer` / `GrowWideBuffer` be renamed to `EnsureAnsiCapacity` / `EnsureWideCapacity`?

   Resolution: no. Later functions `0x00584b10` and `0x00584ba0` already carry the `Ensure*Capacity` meaning. 0002RO's grow helpers take an additional count and are directly referenced by accepted append code as `Grow*Buffer`.

3. Should the COW helpers use `Detach*ForWrite` instead of `Detach*IfShared`?

   Resolution: use `DetachAnsiIfShared` and `DetachWideIfShared`. The names encode the exact branch condition and match accepted local vocabulary from [UID:0002RQ].

4. Should PoolAllocator own this target because fixed pools are used?

   Resolution: no. PoolAllocator owns allocation mechanics. The target owns StringBase string-buffer policy and header initialization.

5. Should the target split into allocation, grow, and detach children?

   Resolution: no current split. The six functions are one coherent StringBase helper cluster, already assigned as one child under [UID:0001J1]. No evidence requires separate source ownership.

6. Should the formal C++ define local helper functions such as `AllocateAnsiHeader`, `AllocateWideHeader`, or `HeaderFromData`?

   Resolution: no. Those names are useful analysis shorthand but are not modeled function starts in `0x00582d80-0x00583132`. The corrected formal C++ inlines pool selection and header recovery inside the six target functions, so 0002RO emits no standalone source bodies outside its modeled range.

7. Should the formal C++ use a temporary `StringBase` object named `oldValue` or `oldString` to release the saved old pointer?

   Resolution: no for this target report. That shape can imply constructor/destructor cleanup outside the range. The corrected formal block uses the saved local data pointer as the one-pointer `StringBase<T>` receiver only for the already-modeled `ReleaseAnsiBuffer` or `ReleaseWideBuffer` call. This preserves the binary's retained-release call shape without adding constructor, destructor, or wrapper-helper bodies to 0002RO.

## Final Recommendation

Implement 0002RO now as a source-ready first-draft C++ target.

Recommended result after implementation:

- `COMPLETION:91`
- `CONFIDENCE:92`
- `CANONICAL_OWNER:0001WS`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0001WS`
- Nonblank formal C++ as provided above: six target function bodies only, with no 0002RO-owned standalone helper bodies
- Support docs synchronized for StringBase file/template and parent child status
- Generated coverage/tracker refreshed by validator only

## Changed Files In This Report-Only Pass

- Created and revised `tools/leaser/Agents/Agent-B005/research/0002RO-StringBaseAllocationGrowAndCow-source-quality.md`

No by-* docs, generated docs, project-level files, tool-state files, manual coverage reports, or IDA DB files were edited.

## Implementation Tracking Checklist

- [x] Supervisor reviews this report and approves implementation.
  Proof: supervisor accepted the revised report and `goal.md` supplied the implementation callback for [UID:0002RO].
- [x] Target page `by-memory/0x00582d80-0x00583132.StringBaseAllocationGrowAndCow.md` keeps `CANONICAL_OWNER:0001WS`.
  Proof: post-validation re-read shows `CANONICAL_OWNER:0001WS`.
- [x] Target page keeps `EMITTER_UIDS:0001WS`.
  Proof: post-validation re-read shows `EMITTER_UIDS:0001WS`.
- [x] Target page keeps `RECONSTRUCTABLE:TRUE`.
  Proof: post-validation re-read shows `RECONSTRUCTABLE:TRUE`.
- [x] Target page raises score to `COMPLETION:91`, `CONFIDENCE:92`.
  Proof: target validator command `000000003075` reported `completion_update 0002RO ... 91` and `confidence_update 0002RO ... 92`; post-validation re-read confirms both header values.
- [x] Target page item summary is updated to mention allocation, append-growth, and detach-if-shared primitives.
  Proof: target `Item Summary` now names `StringBaseTemplate` ANSI/wide allocation, append-growth, and detach-if-shared primitives over the 12-byte ref-counted string buffer header.
- [x] Target page `RECONSTRUCTION_CPP` is populated with the corrected formal block from this report.
  Proof: target header now contains nonblank formal C++ between `RECONSTRUCTION_CPP CODE:BEGIN/END`.
- [x] Target formal C++ emits only the six modeled target functions and does not define `AllocateAnsiHeader`, `AllocateWideHeader`, `HeaderFromData`, lambdas, namespace helpers, or other standalone helper bodies.
  Proof: target block and generated [UID:0002RO] section contain only `AllocateAnsiBuffer`, `AllocateWideBuffer`, `GrowAnsiBuffer`, `GrowWideBuffer`, `DetachAnsiIfShared`, and `DetachWideIfShared`; the generated `HeaderFromData` matches are in a later non-0002RO section.
- [x] Target formal C++ inlines pool selection and header-pointer recovery inside the six target functions.
  Proof: `AllocateAnsiBuffer` and `AllocateWideBuffer` contain inline 64/128/256/512 pool/heap selection and header initialization; grow/detach functions recover headers with direct `reinterpret_cast<...>(oldData) - 1`.
- [x] Target formal C++ uses direct one-pointer saved-slot release calls for old data pointers and does not construct `StringBase oldValue` or `StringBase oldString` temporaries.
  Proof: target block uses `reinterpret_cast<StringBase<...> *>(&oldData)->Release...Buffer()` and post-validation search finds no `oldValue` or `oldString` in the 0002RO target/generated section.
- [x] Target page body preserves exact function boundaries and padding, especially `0x00583132-0x00583140` as padding.
  Proof: target covered-range table records the six exact function ranges plus `0x00583132-0x00583140` as fourteen `0xcc` bytes.
- [x] Target page documents `AllocateAnsiBuffer` at `0x00582d80`.
  Proof: target covered-range table and behavior section document `0x00582d80` as `AllocateAnsiBuffer`.
- [x] Target page documents `AllocateWideBuffer` at `0x00582e30`.
  Proof: target covered-range table and behavior section document `0x00582e30` as `AllocateWideBuffer`.
- [x] Target page documents `GrowAnsiBuffer` at `0x00582ef0`.
  Proof: target covered-range table and behavior section document `0x00582ef0` as `GrowAnsiBuffer`.
- [x] Target page documents `GrowWideBuffer` at `0x00582fa0`.
  Proof: target covered-range table and behavior section document `0x00582fa0` as `GrowWideBuffer`.
- [x] Target page documents `DetachAnsiIfShared` at `0x00583050`.
  Proof: target covered-range table and behavior section document `0x00583050` as `DetachAnsiIfShared`.
- [x] Target page documents `DetachWideIfShared` at `0x005830c0`.
  Proof: target covered-range table and behavior section document `0x005830c0` as `DetachWideIfShared`.
- [x] Target page rejects `EnsureAnsiCapacity` / `EnsureWideCapacity` as names for the `0x00582ef0` / `0x00582fa0` pair.
  Proof: ownership/rejected-alternatives section rejects those names for the grow pair because the functions always allocate `oldLength + additionalLength`.
- [x] Target page preserves `0x00584b10` / `0x00584ba0` as the later `EnsureAnsiCapacity` / `EnsureWideCapacity` helpers.
  Proof: target page body names the later capacity helpers separately from the 0002RO grow pair.
- [x] Target page documents ANSI sentinel `0x00670290` and wide sentinel `0x00670278`.
  Proof: target sentinel/pool evidence lists `g_emptyAnsiString` / `0x00670290` and `g_emptyWideString` / `0x00670278` references.
- [x] Target page documents ANSI pools `0x0069bb6c`, `0x0069bb94`, `0x0069bbbc`, `0x0069bbe4`.
  Proof: target evidence lists all four ANSI pool globals and their use by `AllocateAnsiBuffer`.
- [x] Target page documents wide pools `0x0069bacc`, `0x0069baf4`, `0x0069bb1c`, `0x0069bb44`.
  Proof: target evidence lists all four wide pool globals and their use by `AllocateWideBuffer`.
- [x] Target page documents `RefCountedStringBufferHeader` fields `refCount`, `length`, and `capacity`.
  Proof: target header/sentinel/pool table records `refCount`, `length`, and `capacity` at the 12-byte header offsets.
- [x] Target page documents `PoolAllocator::Allocate()` and `::operator new(...)` allocation routes.
  Proof: target allocation behavior records fixed pool allocation for <=64/128/256/512 and heap `::operator new(...)` for larger lengths.
- [x] Target page documents interaction with `ReleaseAnsiBuffer` and `ReleaseWideBuffer`.
  Proof: target grow/detach behavior and caller/callee evidence document `ReleaseAnsiBuffer` / `ReleaseWideBuffer` dependencies from [UID:0002RT].
- [x] `by-file/StringBase.md` is synchronized with 0002RO's formal-code status and six helper names.
  Proof: `by-file/StringBase.md` now has an allocation/grow/COW helper-group row, evidence, cross-reference, and changes entry for 0002RO; validator command `000000003067` at `2026-06-26T17:27:08-04:00` returned `ok: 1`.
- [x] `by-type/by-template/StringBaseTemplate.md` is synchronized with 0002RO's six helper names and owner/emitter route.
  Proof: `StringBaseTemplate.md` now has the 0002RO method-inventory paragraph, direct-helper table update, evidence, cross-reference, and changes entry; validator command `000000003068` at `2026-06-26T17:27:14-04:00` returned `ok: 1`.
- [x] Parent `by-memory/0x00582500-0x00583206.StringBaseConstructionAndCow.md` is synchronized with 0002RO's formal-code status and padding note.
  Proof: parent Item Summary, covered-range row, helper inventory, no-code proof, and changes entry now state 0002RO is a `91/92` formal-code child while the parent remains non-emitting; validator command `000000003069` at `2026-06-26T17:27:24-04:00` returned `ok: 1`.
- [x] Optional support sync for `by-type/by-struct/RefCountedStringBufferHeader.md` is applied only if in implementation scope.
  Proof: support sync was in scope because current detail was weaker; header doc now records 0002RO allocation/grow/detach field evidence and cross-reference; validator command `000000003070` at `2026-06-26T17:27:30-04:00` returned `ok: 1`.
- [x] Optional support sync for `by-global/StringBufferSentinelsAndPools.md` is applied only if in implementation scope.
  Proof: support sync was in scope because current detail was weaker; sentinel/pool doc now records 0002RO direct empty-sentinel and eight-pool use plus detach-through-release behavior; validator command `000000003072` at `2026-06-26T17:27:58-04:00` returned `ok: 1`.
- [x] No generated/project-level/tool-state/IDA DB/manual coverage files are edited by hand.
  Proof: only target/support by-* docs and this B005 report were manually edited. Validator-owned generated/project-level refreshes occurred only through validator commands; no IDA DB, tool-state, generated source/report, or manual `-coverage-report.md` file was hand-edited.
- [x] Run scoped validator on the target page with `--apply` and `--wait-generated`.
  Proof: `python .\tools\validator.py --mode file --file by-memory\0x00582d80-0x00583132.StringBaseAllocationGrowAndCow.md --apply --queue-timeout 240 --wait-generated` returned exit `0`, `ok: 1`, command `000000003075`, timestamp `2026-06-26T17:28:23-04:00`, and `generated_refresh: completed`.
- [x] Run scoped validator on each edited support page.
  Proof: support validators all returned exit `0`, `ok: 1`: `by-file/StringBase.md` command `000000003067`; `StringBaseTemplate.md` command `000000003068`; parent command `000000003069`; `RefCountedStringBufferHeader.md` command `000000003070`; `StringBufferSentinelsAndPools.md` command `000000003072`.
- [x] Re-read target page after validation and confirm metadata/code persisted.
  Proof: post-validation `Select-String` confirms target metadata `91/92`, owner/emitter `0001WS`, `RECONSTRUCTABLE:TRUE`, formal code begin marker, and direct saved-slot release casts; no `oldValue` / `oldString` temporary appears in the 0002RO block.
- [x] Re-read generated output after validation and confirm the six 0002RO function bodies are present, no 0002RO helper bodies were introduced, and stale generated `78/86` / `emits_code:false` state is gone.
  Proof: target validator command `000000003075` completed generated refresh, and the final inspected `auto-generated/NexusTK/util/StringBase.cpp` header was newer (`validator-command-id: 000000003081`, `validator-refreshed-at: 2026-06-26T17:29:22-04:00`). The extracted [UID:0002RO] section shows `Completion:91 | Confidence:92` and exactly the six accepted function bodies, with no 0002RO `AllocateAnsiHeader`, `AllocateWideHeader`, `HeaderFromData`, lambda, namespace helper, local helper, `oldValue`, or `oldString`.
- [x] Record validator command IDs/timestamps in the implementation checkpoint.
  Proof: command IDs/timestamps are recorded in this checklist and will be summarized in the B005 checkpoint. Known unrelated validator diagnostics were the existing stale `0001J2` missing-reference warnings on some support docs and broad stale autogen registry / missing coverage-metadata entries during target generated refresh.
- [x] Lease discipline completed.
  Proof: B005 leased the immediate edit files, refreshed leases for the remaining validator batch, re-leased target/global when the first window expired during validation, and released active target/global leases after validation; `current_leases.md` then showed no active B005 lease rows.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/0002RO-StringBaseAllocationGrowAndCow-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0002RO-StringBaseAllocationGrowAndCow-source-quality.md","timestamp":"2026-06-26T17:38:30","uid":"0002RO"} -->
<!-- {"agent":"B005","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002RO-StringBaseAllocationGrowAndCow-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B005/0002RO-StringBaseAllocationGrowAndCow-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002RO"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
