** TARGET-REPORT-UID:0001J1 **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001J1 LObjectStringConstructionAndCow Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: accept [UID:0001J1] as a reviewed non-emitting StringBase aggregate/container, not as a source-emitting method page and not as `LObject` code.
- Final disposition: rename the target away from `LObject` to `0x00582500-0x00583206.StringBaseConstructionAndCow.md`, set the target itself to `RECONSTRUCTABLE:FALSE`, clear `CANONICAL_OWNER`/`EMITTER_UIDS`, and leave formal C++ blank. Exact child pages carry the source-bearing reconstruction state.
- Required action: implementation callback should update the target and support docs at report-level detail, including the raw-byte endpoint correction for the `0x005829c0` wide `vsnwprintf` shim.
- Confidence: high. The exact target bytes, child ranges, padding, sentinel/pool references, current source route, and historical `LObject` rejection are independently supported by current docs and a raw PE check against `E:\NTK\Resources\NexusTK\NexusTK.exe`.

## Target

- Target UID: `0001J1`
- Current target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00582500-0x00583206.LObjectStringConstructionAndCow.md`
- Recommended target path after implementation: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00582500-0x00583206.StringBaseConstructionAndCow.md`
- Current score/metadata: `COMPLETION:85`, `CONFIDENCE:87`, `CANONICAL_OWNER:0000OA`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OA`, formal C++ blank.
- Proposed score/metadata: `COMPLETION:87`, `CONFIDENCE:90`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++.
- Current generated route evidence: `auto-generated/-ag-memory-coverage.md` reports this UID as an emitter through `0000OA` into `auto-generated/NexusTK/util/StringBase.cpp`, but `auto-generated/NexusTK/util/StringBase.cpp` contains only an empty emitter marker for `0001J1`.
- Current supervisor-owned coverage row is stale: it still reports `82%` and reconstructable output, while the target header is already `85/87`.

## Executive Recommendation

[UID:0001J1] is a useful range map over the first contiguous StringBase construction/share/allocation/suffix island, but it is not itself a source-level function, method, class, data declaration, or original compilation unit. The exact source-bearing children are already split and assigned:

- [UID:0002RM] conversion/CRT shims, direct file route [UID:0000OA] `StringBase`.
- [UID:0002RN] share/assign/access helpers, direct file route [UID:0000OA] `StringBase`.
- [UID:0002RO] allocation/grow/COW primitives, direct type route [UID:0001WS] `StringBaseTemplate`, emitting through [UID:0000OA] `StringBase`.
- [UID:0002RP] suffix predicates, direct file route [UID:0000OA] `StringBase`.

The parent should match the later accepted source-quality disposition of [UID:0001J2] `StringBaseFormatConstructors` and [UID:0001J3] `StringBaseReleaseFormatAndMutation`: reviewed non-emitting aggregate/container, exact children reconstructable. Keeping `0001J1` as an emitter creates duplicate empty output in `StringBase.cpp` and invites a monolithic C++ block spanning many functions that already have child docs.

## Supervisor Active Recheck

- Assignment: B004 new report-only source-quality assignment for [UID:0001J1], with required recheck of exact child range inventory, owner decision, buffer layout, sentinel/pool globals, helper names, caller/reachability, source placement, split decisions, first-draft C++ eligibility/no-code proof, support checklist, and exact supervisor-owned coverage row.
- Report-only constraint honored: this report recommends changes but does not edit by-* docs and does not edit `by-memory/-coverage-report.md`.
- IDA MCP endpoint check: `http://127.0.0.1:13337/mcp` was unavailable in this session (`Unable to connect to the remote server`). Current live IDA claims in existing docs were treated as documentation evidence. New verification in this report comes from raw PE bytes, Capstone disassembly, current by-* docs, generated coverage, and generated source output.

## Inference Research Guidance Check

`by-structure.md` is decisive here. It says an aggregate/container should be `RECONSTRUCTABLE:FALSE` when the container is only an audit/index/section map or a convenience page whose exact children carry the real source ownership. It also says final C++ requires more than average score and an emitter route: the item must have a source shape and names that support final output.

Applied to this target:

- Fact: `0001J1` spans 33 IDA-modeled starts plus additional raw wrapper starts inside child `0002RM`.
- Fact: the exact children already carry the method/helper reconstruction routes.
- Fact: adjacent aggregate maps `0001J2` and `0001J3` have already been reclassified as reviewed non-emitting containers.
- Inference: `0001J1` should be aligned with those pages. It is not a separate method body and should not emit code.
- Inference: historical `LObject` title/file naming is stale and should be renamed to `StringBaseConstructionAndCow`.

## Heuristic / Inference Reanalysis And Validation

### Historical `LObject` Label

- Issue: target filename/title still says `LObjectStringConstructionAndCow`.
- Best-supported interpretation: stale generated-owner pollution. The receiver field at offset `0` is a character-data pointer into a 12-byte-prefixed string buffer, not the true `LObject` vtable field.
- Evidence checked: [UID:0000KV] `LObject`, [UID:00007D] `LObject`, [UID:0000OA] `StringBase`, [UID:0000OB] `StringUtil`, [UID:0001WS] `StringBaseTemplate`, [UID:0001VQ] `RefCountedStringBufferHeader`, [UID:0000TM] `StringBufferSentinelsAndPools`, generated `StringBase.cpp`, generated `LObject.cpp`, and raw PE bytes for this range.
- Decision: reject `LObject` as direct source owner. Rename target to `StringBaseConstructionAndCow`.

### Direct Source Placement

- Best source module: [UID:0000OA] `StringBase` / `util/StringBase.cpp`.
- Broader context: [UID:0000OB] `StringUtil` / `util/StringUtil.cpp` remains the utility-string coordinator.
- Type-level owner for allocation/grow/COW child: [UID:0001WS] `StringBaseTemplate`.
- Evidence: `StringBase.md` explicitly owns the `0x00582500-0x00584d7d` ref-counted ANSI/UTF-16 family; `StringUtil.md` delegates this implementation to `StringBase`; `StringBaseTemplate.md` preserves `mystr::StringBase<wchar_t,mystr::mychar_traits<wchar_t>>`; raw target bytes contain the sentinel and pool immediate references expected for StringBase allocation/share/COW helpers.
- Decision: target container should not have its own canonical owner. Exact children should retain their existing `StringBase` or `StringBaseTemplate` owner routes.

### Ref-Counted Buffer Layout

- Best-supported layout: one object field, `m_data`, points to character data. Header immediately before data is:
  - `data - 0x0c`: `refCount`, changed by `InterlockedIncrement`/`InterlockedDecrement`.
  - `data - 0x08`: `length`, excluding NUL terminator.
  - `data - 0x04`: `capacity` or pool bucket size.
  - `data + 0x00`: ANSI or UTF-16 character data.
- Evidence checked: `RefCountedStringBufferHeader.md`, `SimpleUStringPointerBackedLayout.md`, allocation child `0002RO`, share/assign child `0002RN`, suffix child `0002RP`, raw call targets to allocation/release helpers, and raw sentinel/pool dword occurrences.
- Decision: layout is resolved for this target. Signedness and exact public type spelling remain non-final but do not block source placement.

### Sentinel And Pool Globals

- Best names:
  - `0x00670278`: `g_emptyWideBuffer` / `g_emptyWideString`, shared UTF-16 empty data/header sentinel.
  - `0x00670290`: `g_emptyAnsiBuffer` / `g_emptyAnsiString`, shared ANSI empty data/header sentinel.
  - `0x0069bacc`, `0x0069baf4`, `0x0069bb1c`, `0x0069bb44`: wide 64/128/256/512 pools.
  - `0x0069bb6c`, `0x0069bb94`, `0x0069bbbc`, `0x0069bbe4`: ANSI 64/128/256/512 pools.
- Raw PE dword occurrences in target:
  - `0x00670278`: immediate bytes at `0x00582618`, `0x00582a94`, `0x00582b21`, `0x00582c64`, `0x00582e3f`, `0x00582fcc`.
  - `0x00670290`: immediate bytes at `0x005827d8`, `0x005829f4`, `0x00582a81`, `0x00582bb4`, `0x00582d8f`, `0x00582f1c`.
  - wide pool dwords: `0x00582e51`, `0x00582e6c`, `0x00582e87`, `0x00582ea2`.
  - ANSI pool dwords: `0x00582da1`, `0x00582dbc`, `0x00582dd7`, `0x00582df2`.
- Existing docs often cite instruction addresses instead of immediate-byte addresses. That is not a contradiction; both refer to the same references.
- Decision: sentinel/pool meaning is resolved. Keep globals with [UID:0000TM] and source route [UID:0000OA].

### Helper Names And Generated Names

The original public names are not proven. The strongest descriptive names for implementation/support docs are:

- `0x00582500`: construct wide/StringBase UTF-16 from ANSI through default codepage conversion.
- `0x00582560`: construct/copy wide from raw UTF-16.
- `0x005825a0`: convert stored wide to ANSI.
- `0x00582610`: retain-or-copy wide buffer.
- `0x00582730`: construct/copy ANSI from raw ANSI.
- `0x00582770`: convert raw UTF-16 to ANSI.
- `0x005827d0`: retain-or-copy ANSI buffer.
- `0x00582920`: ANSI secure `vsnprintf` shim.
- `0x005829c0-0x005829f0`: wide secure `vsnwprintf` shim. This report corrects the old half-open prose endpoint; byte `0x005829ef` is the `ret`, so the body is not `0x005829c0-0x005829ef` half-open.
- `0x005829f0`: retain/share/copy ANSI buffer constructor helper.
- `0x00582a80`: initialize ANSI empty sentinel.
- `0x00582a90`: retain/share/copy wide buffer constructor helper.
- `0x00582b20`: initialize wide empty sentinel.
- `0x00582b30`: ANSI release wrapper over `0x005832f0`.
- `0x00582b70`: wide release wrapper over `0x005833a0`.
- `0x00582bb0`: COW-aware ANSI assignment.
- `0x00582c60`: COW-aware UTF-16 assignment.
- `0x00582d20`: raw NUL-terminated UTF-16 assignment.
- `0x00582d70`: indexed UTF-16 access helper.
- `0x00582d80`: allocate/init ANSI buffer.
- `0x00582e30`: allocate/init wide buffer.
- `0x00582ef0`: grow ANSI buffer while preserving contents.
- `0x00582fa0`: grow wide buffer while preserving contents.
- `0x00583050`: detach ANSI shared buffer for COW.
- `0x005830c0`: detach wide shared buffer for COW.
- `0x00583140`: ANSI `ends_with`/suffix predicate.
- `0x005831c0`: UTF-16 `ends_with`/suffix predicate.

Decision: use descriptive names in documentation. Do not claim original names such as exact overload spellings until a final API pass resolves `StringBase<char>`, `StringBase<wchar_t>`, `SimpleUString`, and facade aliases.

### Raw Helpers And Reachability

- Raw starts in `0002RM` are real code, not padding: `0x00582610`, `0x005827d0`, `0x00582890`, `0x005828a0`, `0x005828b0`, `0x005828c0`, `0x005828d0`, `0x00582920`, `0x00582960`, `0x00582970`, and `0x005829c0`.
- The raw starts are contiguous project-facing wrappers or helper bodies inside the string helper island. Zero direct start xrefs for some wrappers explains IDA non-promotion but does not justify ignoring them.
- The suffix helpers have ordinary direct callers from FolderTree/string utility consumer paths, but caller ownership is rejected because they operate on StringBase storage and caller spread is cross-subsystem.
- Decision: raw wrapper liveness is sufficiently explained by contiguous retained wrapper bodies and callee roles. Do not split them into ignored/runtime pages.

### Split/Range Decisions

- Keep the target half-open range `0x00582500-0x00583206`.
- Keep exact children unchanged, except for prose corrections and parent-link updates after target rename.
- Add/retain explicit target coverage for internal padding `0x00583132-0x00583140`.
- Keep adjacent ignored padding:
  - `0x005824f6-0x00582500`: pre-target StdioFile-to-StringBase padding.
  - `0x00583206-0x00583210`: post-target padding before `StringBaseAnsiFormatCtor`.
- Correct the internal prose for `0x005829c0`: half-open raw body is `0x005829c0-0x005829f0`, with `0xc3` `ret` at `0x005829ef`.

### Final C++ Impact

- Current metadata technically clears the minimum average score/emitter gate (`85/87`, emitter `0000OA`), but the target is an aggregate container rather than a source-level method.
- After the recommended reclassification to `RECONSTRUCTABLE:FALSE`, the C++ gate no longer applies to the parent.
- Exact children can later receive C++ or further method-level splits when public API names and signatures are ready.
- Do not populate a monolithic parent C++ block. It would duplicate children and would either overreach across 33 IDA-modeled starts or become a useless empty marker.

## Evidence Standards Used

- Raw PE evidence from `E:\NTK\Resources\NexusTK\NexusTK.exe`.
- PE section mapping: image base `0x00400000`, `.text` `0x00401000-0x0060c600`, raw pointer `0x400`.
- Binary hashes: MD5 `4247e04e20b65d6414c7238aa8ff5515`, SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
- Target raw offset: `0x181900`.
- Target byte hash: SHA-256 `3446c9944c1a1107f149aef58b0a7b30abe1d801d72bda9dd20f11c5a36a46ee`.
- Capstone disassembly was used only for local byte/instruction confirmation; it does not replace IDA function ownership facts.
- Existing by-* docs were treated as evidence to recheck, not as authority.
- IDA MCP was unavailable for new live checks in this session, so older IDA MCP facts remain documentation evidence with the dates already recorded in target/support docs.

## Raw PE Facts

| Range | Role | Raw offset | SHA-256 / bytes |
| --- | --- | ---: | --- |
| `0x005824f6-0x00582500` | pre-target padding | `0x1818f6` | `cc cc cc cc cc cc cc cc cc cc` |
| `0x00582500-0x00583206` | full target aggregate | `0x181900` | `3446c9944c1a1107f149aef58b0a7b30abe1d801d72bda9dd20f11c5a36a46ee` |
| `0x00582500-0x005829f0` | child `0002RM` | `0x181900` | `07fbf895c0e55a67b2b8d26f67c0ca644d28bc6f1f74e0f00e316467d7767f7b` |
| `0x005829b6-0x005829c0` | internal padding | `0x181db6` | `cc cc cc cc cc cc cc cc cc cc` |
| `0x005829c0-0x005829f0` | raw wide `vsnwprintf` shim including `ret` | `0x181dc0` | starts `55 8b ec ff 75 18 6a 00`; byte at `0x005829ef` is `c3` |
| `0x005829f0-0x00582d80` | child `0002RN` | `0x181df0` | `7ac2144565dd769cef485fe7307cf9439465bc760bde14b6f331319eac909a97` |
| `0x00582d80-0x00583132` | child `0002RO` | `0x182180` | `c3e57d22a7a4235694826cd9213054c23316c098e43effcd5d720ddbd035a3e9` |
| `0x00583132-0x00583140` | internal padding | `0x182532` | `cc cc cc cc cc cc cc cc cc cc cc cc cc cc` |
| `0x00583140-0x00583206` | child `0002RP` | `0x182540` | `8d84564d92a19cf2e28b57635d625cb1d83d2d08f35055d979aa8959805313f4` |
| `0x00583206-0x00583210` | post-target padding | `0x182606` | `cc cc cc cc cc cc cc cc cc cc` |

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct owner/emitter | Current score | Recommendation |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00582500-0x005829f0` | [UID:0002RM] `by-memory/0x00582500-0x005829f0.StringBaseConversionAndCrtShims.md` | conversion constructors, raw share/copy starts, CRT compare/case/format shims | TRUE | [UID:0000OA] `StringBase` | `86/88` | keep source-bearing; correct `0x005829c0-0x005829f0` raw shim wording |
| `0x005829f0-0x00582d80` | [UID:0002RN] `by-memory/0x005829f0-0x00582d80.StringBaseShareAssignAndAccess.md` | share/copy, sentinel init, release wrappers, assignment, wide access | TRUE | [UID:0000OA] `StringBase` | `86/89` | keep source-bearing; refresh parent link after rename |
| `0x00582d80-0x00583132` | [UID:0002RO] `by-memory/0x00582d80-0x00583132.StringBaseAllocationGrowAndCow.md` | allocation, grow, COW detach | TRUE | [UID:0001WS] `StringBaseTemplate`, emits via [UID:0000OA] | `85/89` | keep source-bearing and preserve template owner nuance |
| `0x00583132-0x00583140` | no UID, internal padding | `0xcc` alignment before suffix child | FALSE/padding | none | n/a | document in parent; no child page needed |
| `0x00583140-0x00583206` | [UID:0002RP] `by-memory/0x00583140-0x00583206.StringBaseSuffixChecks.md` | ANSI/wide suffix predicates | TRUE | [UID:0000OA] `StringBase` | `85/88` | keep source-bearing; refresh parent link after rename |
| `0x00582500-0x00583206` | [UID:0001J1] current target | parent aggregate/container over the above | currently TRUE | currently [UID:0000OA] | `85/87` | change to non-emitting container `87/90`, owner/emitter blank |

## IDA-Modeled Function Starts

Existing child docs identify 33 IDA-modeled starts inside the aggregate:

- `0002RM`: `0x00582500`, `0x00582560`, `0x005825a0`, `0x00582670`, `0x00582680`, `0x00582730`, `0x00582770`, `0x00582830`, `0x005828e0`, `0x00582900`, `0x00582950`, `0x00582980`, `0x005829a0`.
- `0002RN`: `0x005829f0`, `0x00582a50`, `0x00582a80`, `0x00582a90`, `0x00582af0`, `0x00582b20`, `0x00582b30`, `0x00582b70`, `0x00582bb0`, `0x00582c60`, `0x00582d20`, `0x00582d70`.
- `0002RO`: `0x00582d80`, `0x00582e30`, `0x00582ef0`, `0x00582fa0`, `0x00583050`, `0x005830c0`.
- `0002RP`: `0x00583140`, `0x005831c0`.

Raw/non-promoted starts in `0002RM` that should remain documented as code:

- `0x00582610`, `0x005827d0`, `0x00582890`, `0x005828a0`, `0x005828b0`, `0x005828c0`, `0x005828d0`, `0x00582920`, `0x00582960`, `0x00582970`, `0x005829c0`.

## Direct Xref / Caller / Callee Inventory

Raw Capstone relative-call targets inside the target align with the documented StringBase dependency graph:

| Callee | Calls inside target | Meaning |
| --- | ---: | --- |
| `0x005151b0` | 2 | default ANSI-to-wide conversion wrapper |
| `0x005151d0` | 3 | default wide-to-ANSI conversion wrapper |
| `0x00582d80` | 9 | ANSI allocation helper |
| `0x00582e30` | 9 | wide allocation helper |
| `0x005832f0` | 7 | ANSI release helper outside target |
| `0x005833a0` | 7 | wide release helper outside target |
| `0x00584060` | 1 | byte-range comparator for ANSI suffix path |
| `0x00584550` | 1 | wide offset/range compare helper for UTF-16 suffix path |
| `0x00584b10` | 2 | ANSI capacity grow/copy helper in later StringBase family |
| `0x00584ba0` | 2 | wide capacity grow/copy helper in later StringBase family |
| `0x004b1400` | 8 | pool allocator allocation call path for bucketed string buffers |
| `0x005c95b0` | 15 | `memmove`-style payload copy dependency |
| IAT slot `0x0060d174` | 8 | import call slot used by the Interlocked retain path documented in child pages |

Caller ownership inference:

- Broad conversion, assignment, allocation, and suffix callers are consumers, not owners.
- `StringBase` is stronger than any feature caller because the helpers operate on common string-buffer internals, use shared sentinels/pools, and have cross-subsystem fan-in.
- Suffix direct callers from `sub_4B1D50`, `sub_57A890`, and `sub_4B3090` prove utility use, not FolderTree/Deque/local feature ownership.

## Documentation Evidence And IDA Status

Strong supporting docs:

- [UID:0000OA] `StringBase.md`: preferred source root for `0x00582500-0x00584d7d`, rejects `LObject` pollution, lists `0001J1` as core string-buffer family.
- [UID:0000OB] `StringUtil.md`: broad utility-string coordinator; delegates ref-counted `StringBase` implementation to `StringBase.cpp`.
- [UID:0001WS] `StringBaseTemplate.md`: preserves `mystr::StringBase<wchar_t,mystr::mychar_traits<wchar_t>>` compiler metadata and attaches to `StringBase`.
- [UID:0001VQ] `RefCountedStringBufferHeader.md`: records the 12-byte header and assignment gate to `StringBase`.
- [UID:0000TM] `StringBufferSentinelsAndPools.md`: records sentinel/pool roles and source-specific static data ownership.
- [UID:0000KV] and [UID:00007D] `LObject`: now explicitly keep `LObject` to the tiny runtime/base shell and reject the `0x00582500+` string family as true `LObject` source.
- [UID:0001J2] and [UID:0001J3]: adjacent string-family aggregate maps are already reviewed non-emitting containers after exact child splits.

Stale/incomplete docs to fix:

- Target filename/H1 still says `LObjectStringConstructionAndCow`.
- Target still says `RECONSTRUCTABLE:TRUE` and emits an empty marker, unlike adjacent aggregate maps.
- Target and `0002RM` prose use half-open-looking text `0x005829c0-0x005829ef` for the wide `vsnwprintf` shim; raw bytes show the correct half-open body is `0x005829c0-0x005829f0`.
- `0002RN` still uses stale `90/90+` code-entry wording. The current gate is average score > 85 with valid emitter route, but final C++ remains blocked by source shape/API names.
- `by-memory/-coverage-report.md` row is stale at `82%` and reconstructable.

## Ranked Ownership Analysis

### 1. Non-emitting container with StringBase child/source context

- Evidence for: target spans multiple child pages and 33 IDA-modeled starts; exact children already carry real owners; generated `StringBase.cpp` contains only an empty marker for this parent; adjacent string aggregate pages use non-emitting container disposition; by-structure instructs this treatment for reviewed containers whose exact children own reconstruction.
- Evidence against: current target metadata still points to `StringBase` and reconstructable true.
- Decision: accepted. Change parent to non-emitting container and keep source placement facts in body.

### 2. Direct [UID:0000OA] `StringBase` source-emitting aggregate

- Evidence for: all contained behavior is in the `StringBase` family and current generated route surfaces to `StringBase.cpp`.
- Evidence against: parent has no independent source shape and duplicates children; it includes internal padding; one child routes more narrowly through `StringBaseTemplate`; source C++ would have to be many method/helper definitions already represented by children.
- Decision: reject as target metadata. Keep `StringBase` as owner context for exact children.

### 3. Direct [UID:0001WS] `StringBaseTemplate` owner for the entire target

- Evidence for: allocation/grow/COW child `0002RO` is best modeled as template-family internals and emits through `StringBase`.
- Evidence against: conversion/CRT shims, assignment/access wrappers, and suffix helpers are not all strictly template-type docs; several children use file owner [UID:0000OA]. The target as a whole is a range map, not a template declaration.
- Decision: reject for parent. Preserve only for `0002RO` and type/layout support.

### 4. [UID:0000OB] `StringUtil`

- Evidence for: StringUtil is the broad utility-string coordinator and may be where the original project placed headers.
- Evidence against: current source-tree and compiler metadata favor dedicated `StringBase.cpp` for this ref-counted buffer core; `StringUtil` owns adjacent/simple/facade utilities, not this exact buffer implementation.
- Decision: reject as direct target owner. Keep as broader context.

### 5. [UID:0000KV]/[UID:00007D] `LObject`

- Evidence for: historical recovered labels and old generated output grouped this code under LObject.
- Evidence against: true `LObject` is a small vtable/runtime-class shell; this range uses offset `0` as a data pointer and touches StringBase header/sentinel/pool state; current `LObject` docs explicitly reject this family as base-object source.
- Decision: reject. Rename target.

### 6. Runtime/CRT/PoolAllocator/feature callers

- Evidence for: target contains CRT forwarding shims and calls the pool allocator; callers include many feature modules.
- Evidence against: project-facing wrappers are source-authored StringBase code; pool mechanics live in PoolAllocator but concrete string pool usage is StringBase; callers are consumers.
- Decision: reject as direct owner.

## First-Draft C++ / No-Code Proof

No parent C++ should be entered for [UID:0001J1].

Exact proof:

- The target is not one function. It spans 33 IDA-modeled starts plus raw wrapper starts.
- It has four exact source-bearing children and an internal padding gap.
- Exact children already own the reconstruction route to `StringBase.cpp` or `StringBaseTemplate`.
- A parent C++ block would either duplicate child output or become a misleading marker in `StringBase.cpp`.
- Current generated output already shows the bad state: `StringBase.cpp` contains an empty emitter marker for `0001J1` and then separate child markers.
- Adjacent `0001J2` and `0001J3` establish the current source-quality pattern for this family: broad aggregate maps are non-emitting containers; exact children carry reconstruction.
- Public API names and signatures remain unresolved for the child methods. It is safer to write C++ on exact method/helper pages after a final naming pass than to write a monolithic aggregate.

If the supervisor declines the reclassification and keeps `0001J1` as an emitter for a transitional pass, the only acceptable formal C++ would be a single `//` marker under Supervisor override 28. That is not my preferred recommendation because clearing the emitter route is cleaner and matches `0001J2`/`0001J3`.

## Open-Question Closure

| Question | Closure |
| --- | --- |
| Is the target really `LObject` source? | No. Historical generated label only. Rename to StringBase. |
| Is `StringBase` or `StringUtil` the better source placement? | `StringBase.cpp` for this ref-counted buffer implementation; `StringUtil.cpp` remains broader coordinator. |
| Does `StringBaseTemplate` matter? | Yes for `0002RO` and layout/type docs; do not flatten that child nuance into file-only ownership. |
| Is the buffer layout understood? | Yes: one data pointer plus 12-byte header before data. |
| Are sentinels/pools understood? | Yes: `0x00670278`, `0x00670290`, and eight 64/128/256/512 bucket pools. |
| Is there an undocumented byte gap before `0x005829f0`? | No. The old prose endpoint is off by one in half-open terms; `0x005829ef` is `ret`. |
| Does `0x00583132-0x00583140` need a child? | No. Raw bytes are `0xcc` padding; parent should document it. |
| Can parent C++ be written now? | No. Parent is a container; exact children are the source-bearing units. |
| Are original public API names final? | No. Descriptive names are strong enough for docs, not for final aggregate C++. This caps child/source-code readiness, not parent container confidence. |

## Proposed Metadata / Score Rationale

Recommended target metadata after implementation:

```text
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Rationale:

- Completion `87`: target will document exact children, padding, raw PE evidence, source placement, rejected historical owner, and no-code/container proof. It remains below final-audit levels because child public API names and exact source declarations are not final.
- Confidence `90`: high confidence for range, children, layout, sentinel/pool references, source placement, and container disposition. It stays below `95+` because final original names and `StringBase`/`SimpleUString` facade API spelling remain inferred.
- `CANONICAL_OWNER:NONE`: the page itself is an aggregate map, not a direct source item. Exact children keep owners.
- `RECONSTRUCTABLE:FALSE`: exact child pages carry source-bearing reconstruction.
- blank `EMITTER_UIDS`: prevents duplicate empty output in `StringBase.cpp`.

## Exact Support-Doc Implementation Checklist

Target doc:

- Rename `by-memory/0x00582500-0x00583206.LObjectStringConstructionAndCow.md` to `by-memory/0x00582500-0x00583206.StringBaseConstructionAndCow.md`.
- Update H1 to `# 0x00582500-0x00583206 StringBase Construction And COW`.
- Replace status with reviewed non-emitting aggregate/container disposition.
- Apply proposed metadata above.
- Preserve detailed source-placement evidence: `StringBase.cpp` direct context, `StringUtil.cpp` broad context, `StringBaseTemplate` for allocation/grow/COW child.
- Add raw PE evidence from this report, including target hash, child hashes, sentinel/pool immediate-byte references, and exact internal padding.
- Correct raw wide `vsnwprintf` subspan to `0x005829c0-0x005829f0`.
- Add a first-draft C++ / no-code proof section saying no parent C++ should be emitted because exact children carry source reconstruction.

Exact child/support docs:

- `by-memory/0x00582500-0x005829f0.StringBaseConversionAndCrtShims.md`
  - Update parent link to the renamed target.
  - Correct all half-open wording for the wide `vsnwprintf` shim to `0x005829c0-0x005829f0`; explicitly note byte `0x005829ef` is the `ret`.
  - Keep metadata `86/88`, owner/emitter [UID:0000OA], unless another implementation pass changes child C++ readiness.
- `by-memory/0x005829f0-0x00582d80.StringBaseShareAssignAndAccess.md`
  - Update parent link to the renamed target.
  - Replace stale `90/90+` code-entry gate wording with current source-quality blocker wording: average/emitter gate is minimum only; C++ remains blocked by final API/source signature naming.
- `by-memory/0x00582d80-0x00583132.StringBaseAllocationGrowAndCow.md`
  - Update parent link to the renamed target.
  - Preserve canonical owner/emitter [UID:0001WS] and note that it emits through [UID:0000OA].
- `by-memory/0x00583140-0x00583206.StringBaseSuffixChecks.md`
  - Update parent link to the renamed target.
  - Replace wording that says the broader aggregate is below gate with wording that the parent is a reviewed non-emitting container.
- `by-file/StringBase.md`
  - Update links/display text from `LObjectStringConstructionAndCow` to `StringBaseConstructionAndCow`.
  - Add that `0001J1` is now a non-emitting aggregate map like `0001J2`/`0001J3`, with exact children carrying output.
- `by-file/StringUtil.md`
  - Update links/display text and keep `StringBase.cpp` as the preferred owner for this ref-counted buffer core.
- `by-file/LObject.md` and `by-class/LObject.md`
  - Update cross-reference display text/path after rename.
  - Preserve historical-owner rejection: the true `LObject` runtime shell is separate.
- `by-type/by-template/StringBaseTemplate.md`
  - Update cross-reference display text/path after rename.
  - Preserve `StringBaseTemplate` as direct type owner for allocation/grow/COW child behavior.
- `by-type/by-struct/RefCountedStringBufferHeader.md`
  - Update cross-reference display text/path after rename.
  - Add or preserve the resolved layout summary and target container disposition if referenced.
- `by-type/by-struct/SimpleUStringPointerBackedLayout.md`
  - Update cross-reference display text/path after rename.
  - Keep `SimpleUString` as alias/facade context, not direct owner for this target.
- `by-global/StringBufferSentinelsAndPools.md`
  - Update cross-reference display text/path after rename.
  - Preserve direct owner [UID:0000OA] for the grouped global page.
- `by-meta/client_string_handling.md`
  - Update cross-reference display text/path after rename.
  - Preserve model: `StringBase.cpp` for ref-counted core, `StringUtil.cpp` broad coordinator.
- `by-project-structure/proposed-source-tree.md`
  - Update display text/path if it references the old target filename; keep the `LObject.cpp` / `StringBase.cpp` split unchanged.
- Run validator with `--apply` on the renamed target and each edited support doc during implementation. Let the validator update UID references and autogen state. Do not manually edit `validator.ini`.
- Do not edit `by-memory/-coverage-report.md`; supervisor applies the exact row below.

## Exact Supervisor-Owned Coverage Row

Placement context: replace the current [UID:0001J1] row in `by-memory/-coverage-report.md` between child rows [UID:0002RN] and [UID:0002RO] after the target rename/metadata implementation.

Exact replacement row:

```text
    - [UID:0001J1][0x00582500-0x00583206.StringBaseConstructionAndCow](by-memory/0x00582500-0x00583206.StringBaseConstructionAndCow.md) : ignored : 87% : strong : Reviewed non-emitting StringBase construction/COW aggregate/container over exact source-bearing children [UID:0002RM], [UID:0002RN], [UID:0002RO], and [UID:0002RP]; raw PE verification confirms target `0x00582500-0x00583206`, the `0x005829c0-0x005829f0` raw wide `vsnwprintf` shim, internal `0x00583132-0x00583140` padding, sentinel/pool immediate refs, and `StringBase.cpp`/`StringBaseTemplate` source placement while rejecting historical `LObject` ownership.
```

If the supervisor intentionally defers the file rename, keep the same row text but use the current link target and display text. That is not the preferred final state.

## Validator Baseline

Scoped read-only validator baseline run:

_Executable command block removed from the research report; preserved in [0001J1-LObjectStringConstructionAndCow-source-quality-removed.md](0001J1-LObjectStringConstructionAndCow-source-quality-removed.md)._

Result:

- Exit code: `0`
- `apply: False`
- `scanned markdown files: 1`
- `ok: 1`
- `ok 0001J1 by-memory/0x00582500-0x00583206.LObjectStringConstructionAndCow.md UID header exists`
- Dry run only; no by-* docs, coverage report, generated reports, or validator state were intentionally edited.
- The dry run also surfaced project-wide `autogen_emitter_has_no_code` entries, including the StringBase source root; that is consistent with this target currently emitting only an empty marker.

## Final Recommendation

Implement the report as a source-quality correction:

1. Rename `0001J1` from stale `LObjectStringConstructionAndCow` to `StringBaseConstructionAndCow`.
2. Reclassify the parent as a reviewed non-emitting aggregate/container.
3. Keep exact child pages as source-bearing reconstruction units with their current `StringBase` / `StringBaseTemplate` routes.
4. Correct the raw wide `vsnwprintf` half-open subspan to `0x005829c0-0x005829f0`.
5. Leave parent formal C++ blank and do not add a monolithic aggregate body.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/0001J1-LObjectStringConstructionAndCow-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:29","uid":"0001J1"} -->
<!-- {"agent":"B004","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001J1-LObjectStringConstructionAndCow-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B004/0001J1-LObjectStringConstructionAndCow-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001J1"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
