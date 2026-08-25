** TARGET-REPORT-UID:0001BH **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0001BH] MemmoveWrapper Source-Quality Report

## Assignment

- Agent: B006
- Mode: report-only first pass
- Current supervisor instruction: produce `tools/leaser/Agents/Agent-B006/research/0001BH-MemmoveWrapper-source-quality.md` for [UID:0001BH] `by-memory/0x00516220-0x00516238.MemmoveWrapper.md`; do not edit by-* docs, generated/project-level/manual coverage/tool-state/IDA DB files, and do not lease.
- Target: [UID:0001BH][by-memory/0x00516220-0x00516238.MemmoveWrapper.md](../../../by-memory/0x00516220-0x00516238.MemmoveWrapper.md)
- Current supervisor classification: source-quality blocker review for an already reconstructable, high-scoring MemoryMan utility child with blank formal C++.
- Current scores and parent state: target is `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000L7`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000L7`, blank formal C++.

## Current Target State

- Existing metadata: [UID:0001BH], `86/88`, owner/emitter [UID:0000L7][MemoryMan](../../../by-file/MemoryMan.md), reconstructable true, blank `EMITTER_POSITION_OPTIONAL`, blank formal C++.
- Existing owner/emitter/reconstructable state: attached to the `MemoryMan.cpp` source family as a copy/move helper near the allocation island.
- Existing C++/emitter state: blank because older docs left helper name/declaration and MemoryMan-vs-runtime-support source placement unresolved.
- Existing open questions: final helper/API name, whether this should emit C++ or be treated as CRT/runtime glue, whether the direct owner should be file-level [UID:0000L7] or class [UID:00007U], whether [UID:0001BI] must move as a pair, and whether current generated output is stale.
- Related target/support docs checked:
  - [UID:0001BI][by-memory/0x00516240-0x00516258.Memmove0Wrapper.md](../../../by-memory/0x00516240-0x00516258.Memmove0Wrapper.md)
  - [UID:0001BA][by-memory/0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md](../../../by-memory/0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md)
  - [UID:0000L7][by-file/MemoryMan.md](../../../by-file/MemoryMan.md)
  - [UID:00007U][by-class/MemoryMan.md](../../../by-class/MemoryMan.md)
  - [UID:0000T8][by-global/MemoryAllocationHelpers.md](../../../by-global/MemoryAllocationHelpers.md)
  - generated lead only: `auto-generated/NexusTK/util/MemoryMan.cpp`
  - prior/related reports as leads: B001 `0001BA-memoryman-allocation-source-split.md`, B001 `00013I-EncoderWriteBytes-source-quality.md`, B005 `0002QB-RawPasswordChangePacketWithAccount-source-quality.md`, B009 `0003ZJ-SoundManagerRotateReusableSampleSlotRaw-source-quality.md`, B011/B015 packet-helper reports mentioning [UID:0001BH].

## Executive Recommendation

[UID:0001BH] should move from file-owned blank-C++ support helper to a source-ready `MemoryMan` method child:

- `COMPLETION:90`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:00007U`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00007U`
- Formal C++:

```cpp
void *MemoryMan::MemmoveWrapper(void *destination, const void *source, size_t size)
{
    return memmove(destination, source, size);
}
```

The source-file route remains [UID:0000L7][MemoryMan](../../../by-file/MemoryMan.md) / `NexusTK/util/MemoryMan.cpp`. The direct semantic owner should be [UID:00007U][MemoryMan](../../../by-class/MemoryMan.md) because representative callers use the accepted MemoryMan unused-`this` protocol: call `GetMemoryMan()`, preserve/reload the singleton into `ECX`, then call this helper. This is the same source-shape rule already accepted for [UID:0001BD] `MemoryMan::AllocateBufferMemory(size_t size)`.

Reject separate CRT/runtime-support ownership. IDA MCP and raw PE evidence show this is a project call target with 604 direct rel32 calls in the NexusTK `.text` section. It wraps the IDA-named CRT implementation `_memmove` at `0x005c95b0`, but no dynamic import named `memmove` exists. The wrapper is therefore not an import thunk to delete from source documentation, and it should not stay blank only because callers may be rendered as source-facing `memmove(...)` in feature-specific C++ drafts.

## Supervisor Active Recheck

- The active instruction required a report-only source-quality pass for [UID:0001BH], with IDA MCP evidence required and no by-* edits or leases.
- No split repair is needed: `0x00516220-0x00516238` is an exact 24-byte function, followed by eight bytes of `0xcc` padding before sibling [UID:0001BI].
- Every source-bearing child in this report scope is resolved:
  - [UID:0001BH] is source-ready with method C++.
  - [UID:0001BI] is a paired sibling support item with parallel ABI/body evidence, but it should not receive formal C++ or metadata changes in this [UID:0001BH] callback unless the supervisor explicitly broadens the callback. Its support page should receive relationship notes only.

## Inference Research Guidance Check

- IDA fact: target body, range, ABI, callee, padding, xrefs, sibling body, and no import entries.
- Documentation evidence: current MemoryMan file/class/global pages route the helper island through `MemoryMan.cpp`; B008 establishes the unused-`this` `GetMemoryMan()`/`ECX` rule for MemoryMan methods; project aliases name `sub_516220` as `MemmoveWrapper` / `memmove`.
- Inference: `MemoryMan::MemmoveWrapper` is a project-resolved descriptive method name, not recovered original symbol proof. It is better than leaving raw `sub_516220` or inventing a new `CopyBytes` name because it matches the current target title, project alias table, and existing support-doc vocabulary.
- Stale Wave2/Wave3/simroot mentions encountered in old docs/generated output were treated as lead material only and not used as authority.

## Heuristic / Inference Reanalysis And Validation

| Issue | Resolution | Evidence | Classification |
| --- | --- | --- | --- |
| Raw name `sub_516220` | Use `MemoryMan::MemmoveWrapper` on the target page; feature callers may still describe the operation as `memmove(...)` where source drafts abstract the wrapper away. | Current target name, project alias table, decompile body, support-report precedent. | Inferred/descriptive, implementation-ready. |
| File-level helper vs class method | Direct owner/emitter should be [UID:00007U] class, source route [UID:0000L7] file. | `0x004f32e0` calls `GetMemoryMan`, stores the singleton, reloads it into `ECX`, then calls `sub_516240` and `sub_516220`; B008 uses the same unused-`this` evidence for `MemoryMan::AllocateBufferMemory`. | Strong inference from ABI and caller pattern. |
| CRT/runtime support route | Rejected. | `_memmove` is an internal IDA function at `0x005c95b0`, size `0x574`; `entity_query imports` finds zero `memmove`/allocation import entries; raw PE finds 604 project call sites to the wrapper. | Direct IDA/raw negative evidence. |
| C++ blank/no-code disposition | Rejected. | Target is reconstructable, above active C++ gate, has a valid emitter route, exact one-block behavior, exact ABI, and source-owner evidence. | Direct target repair. |
| Sibling [UID:0001BI] relationship | Keep paired in docs; do not implement sibling C++ from this report alone. | Sibling is same 24-byte shape around `_memmove_0`, 19 direct rel32 callers, adjacent padding. | Support sync only. |
| Existing generated output | Treat as stale generated lead only. | `auto-generated/NexusTK/util/MemoryMan.cpp` still shows [UID:0001BH] marker as `Completion:78 | Confidence:86 | Empty Emitter Marker`, contradicting current by-* metadata and this report. | Validator-owned refresh expected. |

Rejected alternatives:

- Keep [UID:0001BH] as [UID:0000L7] free file helper with `__stdcall` formal C++: rejected as weaker than the caller `ECX` receiver pattern and inconsistent with B008's accepted MemoryMan method rule.
- Rename target to `CopyBytes`, `CopyMemory`, or `MoveMemory`: rejected because no symbol, string, type, or caller text proves those spellings. `MemmoveWrapper` is already the project-resolved support name.
- Mark [UID:0001BH] non-emitting/no-code: rejected because it is a central project helper with 604 direct calls, not compiler-only deleting-destructor/static-lifetime/import glue.
- Move it with [UID:0001BI] to separate CRT wrapper source: rejected because no source-file string, import module, symbol metadata, or ownership evidence supports a separate runtime wrapper unit over the current MemoryMan utility island.

## Evidence Standards Used

Evidence types used:

- IDA MCP `idb_list`, `server_health`, `lookup_funcs`, `analyze_function`, `xrefs_to`, `callees`, `decompile`, `disasm`, `get_bytes`, and `entity_query`.
- Raw PE read-only rel32 scan for call counts and direct-call examples.
- Existing by-* docs and executed reports as lead/support evidence.
- Generated output only as stale lead evidence, not authority.
- `int_convert.py` for numeric conversions.

The evidence is strong enough because the target is a tiny one-block function with exact range, exact bytes, one callee, exact stack cleanup, broad direct call fanout, and a coherent MemoryMan source route. Confidence remains below final-audit level because the exact original method spelling and final class/header declaration placement are not symbol-proven.

## Evidence Checked

- IDA MCP availability:
  - `Test-NetConnection 127.0.0.1 -Port 13337` succeeded.
  - Listener: `127.0.0.1:13337`, owning process `13684`.
  - Visible processes included `idalib-mcp` PID `17084` and worker Python PID `26892`.
  - `initialize` returned server `ida-pro-mcp`, version `1.0.0`.
  - `idb_list` returned active session `80de0a67`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `26892`, not analyzing.
  - `server_health(database=80de0a67)` returned `status: ok`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`.
- IDA MCP/manual-disassembly/raw-byte checks performed:
  - `lookup_funcs` for target, end, sibling, sibling end, successor, `_memmove`, `_memmove_0`.
  - `analyze_function`, `decompile`, `disasm`, `callees`, `xrefs_to`, and `get_bytes` for target and sibling.
  - `entity_query` for imports/names/functions matching `memmove`, `CopyMemory`, `MoveMemory`, `MemoryMan`, `GetMemoryMan`, and `g_pMemoryMan`.
  - Representative caller analysis for `0x004f32e0`, including disassembly around the `GetMemoryMan`/`ECX`/copy-wrapper sequence.
  - Raw PE rel32 scan over `.text` in `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`.
- Negative checks performed:
  - No dynamic imports for `memmove`, `memcpy`, `memset`, `malloc`, `free`, or `realloc` in `entity_query imports`.
  - No recovered wrapper source names other than IDA `_memmove`, `_memmove_0`, and MemoryMan RTTI/vtable names.
  - No source-file string or original symbol proof found in the checked docs/alias material.
- Failed/unavailable checks:
  - Initial optional calls used old/incorrect request shapes for `callers`, `decompile`, and `disasm`; the active schema did not expose `callers` and required singular `addr` for `decompile`/`disasm`. The evidence pass was rerun successfully with `analyze_function`, `xrefs_to`, `callees`, and singular-address `decompile`/`disasm`.

## Inference Claim Ledger

| Claim | Confidence | Evidence | Counter-evidence checked | Next verification / remaining uncertainty |
| --- | --- | --- | --- | --- |
| Target is exact function `0x00516220-0x00516238` | Very strong | MCP `lookup_funcs` size `0x18`; `0x00516238` not a function; bytes confirm 24-byte body then padding. | Sibling/successor lookups. | None. |
| Body is a wrapper around `memmove(destination, source, size)` | Very strong | `analyze_function` decompile and assembly: pushes size/source/destination, calls `_memmove`, returns with `retn 0Ch`. | `callees` returns only `_memmove`. | None. |
| Direct owner should be `MemoryMan` class [UID:00007U] | Strong | Representative caller stores `GetMemoryMan()` result and reloads it into `ECX` before copy-wrapper calls; B008 accepted same unused-`this` pattern. | File-level free helper considered; source route remains [UID:0000L7]. | Exact original method spelling/header declaration. |
| Source route remains `NexusTK/util/MemoryMan.cpp` | Strong | By-file [UID:0000L7], parent [UID:0001BA], class [UID:00007U], and helper-family docs all place the island there. | Separate CRT runtime source rejected. | Final header grouping for all helpers. |
| Formal C++ should be emitted | Strong | Reconstructable true, above gate, exact behavior, valid owner/emitter route. | No-code/runtime glue rejected. | None for target body. |
| `MemmoveWrapper` is acceptable name | Medium-high | Current target title, project alias table, existing support docs, no better recovered name. | `CopyBytes`, `CopyMemory`, `MoveMemory`, raw `sub_516220` rejected. | Future original symbols could rename. |
| Sibling [UID:0001BI] likely needs paired method audit | Strong as direction, out of scope for metadata | Same shape, same padding adjacency, `ECX` patterns in representative caller, 19 raw callers. | This report did not fully audit every sibling caller. | Future [UID:0001BI] target report or explicit callback broadening. |

## Positive Evidence Summary

- Direct IDA facts:
  - `sub_516220` at `0x00516220`, size `0x18` / 24 bytes.
  - Prototype displayed as `void *__stdcall(void *, void *Src, size_t Size)` because `this` is unused.
  - Decompiled body: `return memmove(a1, Src, Size);`
  - Assembly: prologue, push `Size`, push `Src`, push destination, call `_memmove`, add `esp, 0Ch`, pop `ebp`, `retn 0Ch`.
  - `callees` returns only `_memmove` at `0x005c95b0`.
  - `get_bytes` target body is `55 8b ec ff 75 10 ff 75 0c ff 75 08 e8 7f 33 0b 00 83 c4 0c 5d c2 0c 00`.
  - `0x00516238-0x00516240` is eight `0xcc` bytes.
- Corroborating evidence:
  - Raw PE scan found 604 (`0x25c`, Verified with `int_convert.py`) direct rel32 calls to `0x00516220`.
  - `xrefs_to 0x00516220` hit the MCP 100-xref page with `more:true`; first refs match the raw scan at `0x00457c3d`, `0x00457ddc`, `0x00457e6c`, `0x00457ed1`, `0x00457efc`, and others.
  - Representative caller `0x004f32e0` calls `GetMemoryMan`, reloads the saved singleton into `ECX`, then calls [UID:0001BI] and [UID:0001BH].
  - Current support docs already keep this helper in the MemoryMan utility source family and reject a separate CRT-wrapper source absent stronger evidence.

## IDA MCP Facts

- Function/range facts:
  - `lookup_funcs 0x00516220` -> `sub_516220`, size `0x18`.
  - `lookup_funcs 0x00516238` -> not a function.
  - `lookup_funcs 0x00516240` -> sibling `sub_516240`, size `0x18`.
  - `lookup_funcs 0x00516258` -> not a function.
  - `lookup_funcs 0x00516260` -> successor `sub_516260`, size `0x2e`.
  - `lookup_funcs _memmove` -> `0x005c95b0`, size `0x574` / 1396 bytes (Verified with `int_convert.py`).
  - `lookup_funcs _memmove_0` -> `0x005c9b30`, size `0x574`.
- Data/table/padding facts:
  - Target body is exactly 24 bytes (`0x18`, Verified with `int_convert.py`).
  - Target stack cleanup is `retn 0Ch`, 12 bytes (`0x0c`, Verified with `int_convert.py`).
  - Post-target padding is eight bytes (`0x08`, Verified with `int_convert.py`) of `0xcc`.
- Xref facts:
  - `xrefs_to 0x00516220` returns first 100 with `more:true`.
  - Raw PE `.text` rel32 scan gives exact count 604 / `0x25c`.
  - Raw PE first call sites include `0x00457c3d`, `0x00457ddc`, `0x00457e6c`, `0x00457ed1`, `0x00457efc`, `0x00457f1d`, `0x00457f8d`, `0x00457fba`, `0x00457fdb`, `0x0045c3f8`.
  - Raw PE last five call sites: `0x005b55e6`, `0x005b6f7d`, `0x005b70b5`, `0x005b72fd`, `0x005b7405`.
- Vtable/global/type facts:
  - `entity_query names` for MemoryMan found `??_7MemoryMan@@6B@` and MemoryMan RTTI names, plus `_memmove` and `_memmove_0`.
  - No recovered source symbol for `MemmoveWrapper`, `MoveMemory`, `CopyMemory`, `GetMemoryMan`, or `g_pMemoryMan` was found by this query.
- Negative IDA facts:
  - `entity_query imports` found zero import entries matching `memmove|memcpy|memset|malloc|free|realloc`; `_memmove` and `_memmove_0` are internal functions in this IDB, not dynamic imports.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00516220-0x00516238` | [UID:0001BH](../../../by-memory/0x00516220-0x00516238.MemmoveWrapper.md) | `MemoryMan::MemmoveWrapper` method around `_memmove` | TRUE | Recommend [UID:00007U] | Recommend `90/90` | Source-ready target. |
| `0x00516238-0x00516240` | ignored padding | Eight `0xcc` bytes | FALSE | [UID:0000VN] ignored ledger | unchanged | Boundary support only. |
| `0x00516240-0x00516258` | [UID:0001BI](../../../by-memory/0x00516240-0x00516258.Memmove0Wrapper.md) | Paired wrapper around `_memmove_0` | TRUE | Currently [UID:0000L7] | current `86/88` | Support sync only; no C++ in this callback. |
| `0x00516258-0x00516260` | ignored padding | Eight `0xcc` bytes | FALSE | [UID:0000VN] ignored ledger | unchanged | Boundary support only. |
| `0x00516260-0x0051628e` | [UID:0001BJ](../../../by-memory/0x00516260-0x0051628e.MemoryManScalarDeletingDestructor.md) | Scalar deleting destructor successor | TRUE | [UID:00007U] | unchanged | Not part of target. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0051622c` | call `_memmove` `0x005c95b0` | Target wraps standard move-copy implementation. |
| `0x004f32e0` | calls `GetMemoryMan`, `AllocateBufferMemory`, `ReallocateOrThrow`, `Memmove0Wrapper`, `MemmoveWrapper` | Representative container/helper caller; reloads saved `GetMemoryMan()` result into `ECX` before wrapper calls. |
| `0x004f3389` | call `0x00516240` | Sibling wrapper call in same caller. |
| `0x004f33a7` | call `0x00516220` | Target wrapper call in same caller after `mov ecx, [ebp+var_8]`. |
| `0x00516240` sibling | calls `_memmove_0` `0x005c9b30` | Paired wrapper with same ABI/body shape. |
| Raw PE | 604 direct rel32 calls to `0x00516220` | Broad project utility fanout. |
| Raw PE | 19 direct rel32 calls to `0x00516240` | Paired sibling fanout. |

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion:
  - [UID:0000L7] already places copy wrappers in `MemoryMan.cpp` and rejects separate CRT-wrapper support absent stronger original-source evidence.
  - [UID:00007U] already records B008's rule that unused-`this` `__stdcall` decompiler output can still be a `MemoryMan` method when callers provide the singleton in `ECX`.
  - [UID:0000T8] classifies allocation/copy helpers as project-owned MemoryMan helper family, not third-party/runtime.
  - Project alias table resolves `sub_516220` to `MemmoveWrapper` / `memmove`.
- Existing docs that are stale/incomplete:
  - Target text says C++ is blank pending final copy-helper source split. This report resolves that blocker for [UID:0001BH].
  - Target/support wording that calls `_memmove` an "import" should be corrected to internal CRT implementation/function unless the implementation wants the looser historical phrasing in a superseded note.
  - Generated `auto-generated/NexusTK/util/MemoryMan.cpp` has stale empty marker metadata for [UID:0001BH] (`78/86`), not current by-* metadata.
- Generated/coverage report state:
  - Do not edit generated files or coverage reports manually. A validator-owned/generated refresh should update stale generated marker rows after the accepted by-* edits.

## Ranked Ownership Analysis

### 1. [UID:00007U] MemoryMan Class - Recommended Direct Owner

- Evidence for: caller ABI supplies `GetMemoryMan()` result in `ECX`; target returns with `retn 0Ch`, compatible with three-stack-argument MSVC `thiscall`; B008 establishes this method inference for unused-`this` MemoryMan bodies; target is in the MemoryMan island.
- Evidence against: target body does not dereference `this`; no recovered source symbol or UDT method signature proves original spelling.
- Decision: direct owner/emitter [UID:00007U], source route [UID:0000L7]. Residual exact-name uncertainty caps confidence but does not block formal C++.

### 2. [UID:0000L7] MemoryMan File - Source Route, Not Direct Owner

- Evidence for: all support docs route this utility island to `NexusTK/util/MemoryMan.cpp`; final source file should still emit the method body.
- Evidence against: file-level free-helper ownership fails to explain the repeated `GetMemoryMan()`/`ECX` receiver pattern as well as class method ownership.
- Decision: keep as source-file route and support owner for generated file placement, but change target direct owner/emitter to [UID:00007U].

### 3. Separate CRT/Runtime Support Source - Rejected

- Evidence for: body is just a call to `_memmove`.
- Evidence against: no import entry, no source-file string, no runtime-wrapper metadata, adjacent MemoryMan island placement, 604 project call sites, and existing support docs reject the split absent stronger evidence.
- Decision: do not split to CRT/runtime support.

### 4. No-Code / Direct `memmove` Only - Rejected For Target

- Evidence for: many feature-level first-draft C++ blocks reasonably render call sites as `memmove(...)`.
- Evidence against: [UID:0001BH] is an actual central project function with broad direct callers and valid MemoryMan route. Feature-level abstraction does not prove the wrapper target itself should stay blank.
- Decision: target emits wrapper method C++; feature targets may still cite [UID:0001BH] while using source-facing `memmove(...)` when appropriate.

### Proposed New File/Grouping

- Proposed owner/name/path: [UID:00007U] `MemoryMan::MemmoveWrapper` emitted through [UID:0000L7] `NexusTK/util/MemoryMan.cpp`.
- Likely full contents: MemoryMan singleton lifecycle, allocation methods, free/realloc/zero-allocation helpers, copy wrappers, and related global operators as documented by [UID:0000L7].
- Candidate related items that belong: [UID:0001BI] likely paired method wrapper after its own target-level audit; allocation/free/realloc/copy helpers remain in the same utility source family.
- Candidate related items rejected: caller feature modules, PacketBuffer, Socket, ProtocolSend, and separate CRT-wrapper source.
- Standalone/narrow/broad inference: narrow exact child method inside the already accepted broad MemoryMan utility source family.

## Source Placement

- Recommended source file/class/global/module placement: direct class owner/emitter [UID:00007U], source-file route [UID:0000L7] / `NexusTK/util/MemoryMan.cpp`.
- Why this fits: target is adjacent to accepted MemoryMan helpers, uses the same `GetMemoryMan()`/unused-`this` caller protocol as accepted `AllocateBufferMemory`, and has project-wide utility fanout.
- Rejected placements: free `__stdcall` helper, CRT/runtime source, feature callers, PacketBuffer, Socket/networking, and no-owner.
- Remaining uncertainty: exact original method spelling and whether final class header exposes the method publicly or in an internal utility declaration. The source body is still implementation-ready.

## Range / Split / Padding / Reclassification Analysis

- Exact range/boundary facts: `0x00516220-0x00516238`, 24 bytes; end-exclusive `0x00516238` is not a function; eight `0xcc` bytes until sibling `0x00516240`.
- Children/subranges to create/repair/merge: none.
- Padding/table/data/code distinctions: post-target and post-sibling gaps are padding, not source code.
- Parent/container impact: [UID:0001BA] remains a non-emitting split index; it should update the [UID:0001BH] row and sync note but keep aggregate C++ blank.

## Negative Evidence Summary

- No dynamic import entry for `memmove`; `_memmove` is an internal IDA function at `0x005c95b0`.
- No recovered source symbol proves `CopyBytes`, `CopyMemory`, `MoveMemory`, or an exact original `MemmoveWrapper` spelling.
- No evidence supports moving this helper to a caller feature module.
- No evidence supports merging it with [UID:0001BI] or scalar deleting destructor; boundaries and padding are exact.
- No evidence supports leaving the target blank as compiler-generated/import glue; broad direct calls and MemoryMan caller protocol are positive project-source evidence.

## IDA Rename / Type / Comment Recommendations

- Proposed source-facing name: `MemoryMan::MemmoveWrapper`.
- Proposed source-facing signature: `void *MemoryMan::MemmoveWrapper(void *destination, const void *source, size_t size)`.
- Evidence: project alias table, target page title, exact memmove body, MemoryMan `ECX` caller pattern.
- Items intentionally left unchanged: no IDA DB function rename, type, or comment edit is requested or allowed in this task.
- IDA DB edits: unsafe/out of scope under the current supervisor instruction.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes.
- Recommended code:

```cpp
void *MemoryMan::MemmoveWrapper(void *destination, const void *source, size_t size)
{
    return memmove(destination, source, size);
}
```

- Reason it preserves exact original behavior: forwards the three stack arguments in destination/source/size order to `memmove` and returns the CRT return value. A nonvirtual MSVC method with unused `this` supplied in `ECX` matches the observed `retn 0Ch` cleanup.
- Reason it matches plausible mid-2000s source shape: project code already routes allocation helpers through a process-wide `MemoryMan` singleton; representative callers preserve `GetMemoryMan()` as the receiver before copy-wrapper calls; B008 accepted the same pattern for `MemoryMan::AllocateBufferMemory`.
- Inferred names/types used: `MemmoveWrapper`, `destination`, `source`, `size`; `const void *source` is source-facing const-correctness over the binary-equivalent `void *Src`.
- Naming/coding convention used: existing project alias and by-memory target name. Do not rename to `CopyBytes` or `MoveMemory` without original-symbol proof.
- Reason code should remain blank: not applicable.
- Exact no-code proof: not applicable; no-code is rejected.

## Final Recommendation

- Exact changes recommended:
  - Target [UID:0001BH]: update metadata to `90/90`, owner/emitter [UID:00007U], formal C++ above, and source-quality prose.
  - Support docs: sync [UID:00007U], [UID:0000L7], [UID:0000T8], [UID:0001BA], and [UID:0001BI] relationship notes.
- Exact parent assignments recommended:
  - Direct owner/emitter: [UID:00007U].
  - Source route: [UID:0000L7] / `NexusTK/util/MemoryMan.cpp`.
- Exact items left no-owner/non-emitting:
  - Padding `0x00516238-0x00516240` remains ignored/non-emitting.
  - Parent [UID:0001BA] remains non-emitting split index.
  - Sibling [UID:0001BI] remains pending for formal C++ unless separately assigned or callback is broadened.
- Future work outside this assignment: a target-level [UID:0001BI] report can likely apply the same class-method analysis to `MemoryMan::Memmove0Wrapper`, but this report should not silently implement sibling metadata/C++.

## Recommended Target Doc Changes

- Target path: `by-memory/0x00516220-0x00516238.MemmoveWrapper.md`
- Exact report facts to incorporate:
  - Current MCP session `80de0a67`, worker PID `26892`, health ok, module `NexusTK.exe`.
  - `lookup_funcs` exact size/end facts.
  - `analyze_function` body/prototype/assembly.
  - `_memmove` at `0x005c95b0`, size `0x574`, internal function not import.
  - 604 (`0x25c`) raw PE direct rel32 callers.
  - Eight-byte post-target padding.
  - Representative caller `0x004f32e0` evidence for MemoryMan method ownership.
  - Sibling relationship to [UID:0001BI].
- Metadata/score/owner/emitter/reconstructable/C++ changes:
  - `COMPLETION:90`
  - `CONFIDENCE:90`
  - `CANONICAL_OWNER:00007U`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:00007U`
  - Formal C++ block exactly as above.
  - Suggested Item Summary: `` `MemoryMan::MemmoveWrapper` is a 24-byte unused-this wrapper that returns `memmove(destination, source, size)`; current MCP and raw PE evidence confirm the exact body, eight-byte padding, 604 direct callers, and source route through `NexusTK/util/MemoryMan.cpp`. ``
- Historical/stale assumptions/rejected alternatives to preserve:
  - Supersede "blank pending final copy-helper source split"; source split is resolved for this target.
  - Preserve that exact original method spelling is inferred/descriptive, not symbol-proven.
  - Preserve rejection of separate CRT wrapper source absent future original metadata.

## Recommended Support Doc Changes

- Support path: `by-class/MemoryMan.md`
  - Add [UID:0001BH] to method map as `MemmoveWrapper(void *destination, const void *source, size_t size)`, reconstructable child with formal method C++.
  - Add B006 2026-06-26 sync note with MCP/raw evidence and unused-`this` rule.
  - Keep class page C++ blank; score can remain `88/90` because final class/header declaration factoring and sibling copy-wrapper audit remain open.

- Support path: `by-file/MemoryMan.md`
  - Update `copy wrappers` row and generated caveats: [UID:0001BH] now emits as `MemoryMan::MemmoveWrapper` through this file; [UID:0001BI] remains pending paired audit.
  - Preserve source route `NexusTK/util/MemoryMan.cpp`.
  - Keep file score `89/86` unless supervisor wants a broader file-level rescore after multiple copy/helper callbacks.

- Support path: `by-global/MemoryAllocationHelpers.md`
  - Update helper map row for [UID:0001BH] from unresolved utility copy wrapper to accepted `MemoryMan::MemmoveWrapper` method in the MemoryMan-backed helper family.
  - Clarify this global page remains a helper-family index, not the direct owner/emitter.
  - Keep score `86/88`.

- Support path: `by-memory/0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md`
  - Update covered-ranges row for [UID:0001BH] as source-ready `MemoryMan::MemmoveWrapper` child.
  - Add B006 sync note with MCP session, exact range/body/padding/fanout, and class-owner route.
  - Keep parent non-emitting aggregate C++ blank and metadata `88/90`.

- Support path: `by-memory/0x00516240-0x00516258.Memmove0Wrapper.md`
  - Add relationship note: [UID:0001BH] now resolves as `MemoryMan::MemmoveWrapper`; sibling [UID:0001BI] has parallel 24-byte `_memmove_0` body and 19 rel32 callers, but should keep formal C++ blank and metadata unchanged until a dedicated sibling audit or explicit callback broadening.
  - Correct "import" wording if touched, using internal `_memmove_0` implementation/function.

- Generated/project-level/manual coverage/tracker files:
  - Do not edit manually. Validator-owned generated refresh is expected to update stale generated marker/output after accepted by-* changes. No explicit manual `-coverage-report.md` or tracker text is required from B006.

## Score And Metadata Recommendation

- Current score/metadata:
  - `86/88`, owner/emitter [UID:0000L7], reconstructable true, blank C++.
- Recommended score/metadata:
  - `90/90`, owner/emitter [UID:00007U], reconstructable true, formal C++ inserted.
- Score rationale:
  - Completion rises because the remaining source-quality blockers are resolved: exact formal body, direct class owner, source route, ABI, callee route, boundary/padding, broad caller count, sibling relationship, and stale generated-output caveat.
  - Confidence rises to 90 because current MCP and raw PE evidence are strong. It is not higher because no original symbol/type/header metadata proves the exact method spelling or final class declaration exposure.
- Score-improvement attempt:
  - Helper name blocker: checked project aliases, target/support docs, IDA names/functions; no better original name found; chose existing project-resolved `MemmoveWrapper`.
  - Owner blocker: checked representative caller disassembly and B008 precedent; rerouted direct owner to class.
  - Runtime/source split blocker: checked imports, `_memmove` function lookup, raw fanout, support docs; rejected separate CRT source.
  - C++ blocker: checked active gate and exact behavior; formal method C++ is safe.
- Metadata fields:
  - Change target `CANONICAL_OWNER` and `EMITTER_UIDS` to `00007U`.
  - Keep `RECONSTRUCTABLE:TRUE` and blank `EMITTER_POSITION_OPTIONAL`.

## Open Questions With Attempted Resolution

- Exact original method name:
  - Evidence checked: IDA names/functions, project aliases, target/support docs, executed reports.
  - Resolution: use `MemmoveWrapper` as current source-facing descriptive/project-resolved method name.
  - Remaining uncertainty: future original symbols could prove `CopyBytes`, `MoveMemory`, or another name. This caps confidence but does not block implementation.
- Sibling [UID:0001BI]:
  - Evidence checked: current MCP lookup/analyze/xrefs/bytes and raw count.
  - Resolution: document relationship and leave metadata/C++ unchanged for now.
  - Remaining uncertainty: dedicated sibling audit should decide formal `MemoryMan::Memmove0Wrapper` code.
- Caller-source convention:
  - Evidence checked: current feature reports use both `memmove` and `MemmoveWrapper` depending target style.
  - Resolution: target wrapper emits method C++; feature-level source drafts may still render individual copy operations as `memmove(...)` while citing [UID:0001BH].
  - Remaining uncertainty: project-wide final source style may later standardize caller spelling.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- File/placement: none.
- Exact replacement/insert/delete text: none.
- Reason B agent must not apply it directly: generated auto coverage/tracker rows are validator/supervisor-owned. The target Item Summary and metadata should drive generated refresh after validation.

## Follow-Up Actions

- Supervisor actions: review/accept this report, then issue an implementation callback for the target/support by-* docs if accepted.
- A-agent actions: none.
- B006 future research actions: only if assigned, perform a paired source-quality audit for [UID:0001BI].

## Confidence

- Recommendation confidence: strong.
- Score confidence: strong for `90/90`; not final-audit `95+`.
- Remaining uncertainty: exact original method spelling and final class/header declaration factoring.

## Validator Results

Implementation validators run from `E:\NTK\GhidraBridge\source-3\project-documentation` after the accepted by-* edits:

| File | Command id | Timestamp | Exit | Result |
|---|---:|---|---:|---|
| `by-memory/0x00516220-0x00516238.MemmoveWrapper.md` | `000000003121` | `2026-06-26T18:04:59-04:00` | 0 | `ok: 1`; target metadata/C++ accepted; validator inserted header/link/index/stats updates. |
| `by-class/MemoryMan.md` | `000000003122` | `2026-06-26T18:05:00-04:00` | 0 | `ok: 1`; known pre-existing `missing_ref_uid 0003VP` warning only. |
| `by-file/MemoryMan.md` | `000000003123` | `2026-06-26T18:05:02-04:00` | 0 | `ok: 1`; known pre-existing `missing_ref_uid 0003VP` warnings only. |
| `by-global/MemoryAllocationHelpers.md` | `000000003124` | `2026-06-26T18:05:14-04:00` | 0 | `ok: 1`; known pre-existing `missing_ref_uid 0003VP` warnings only. |
| `by-memory/0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md` | `000000003126` | `2026-06-26T18:05:21-04:00` | 0 | `ok: 1`; known pre-existing `missing_ref_uid 0003VP` warnings only. |
| `by-memory/0x00516240-0x00516258.Memmove0Wrapper.md` | `000000003127` | `2026-06-26T18:05:22-04:00` | 0 | `ok: 1`; sibling relationship note preserved with B009's concurrent accepted implementation. |

Validator-owned side effects recorded: `uid_link_insert`, reference-index/autogen-registry updates, `projected_stats_update`, and deferred generated refresh. B006 did not manually edit generated/project-level/tool-state/IDA DB/manual coverage files.

Lease status: B006 leased only the immediate by-* edit batch, then released all six leases after validators. Post-release shared lease report shows no active B006 leases on the edited files; unrelated B014 leases are active on separate Application/Exception/SendPositionUpdate files.

## Changed Files

- Implementation-modified by-* files:
  - `by-memory/0x00516220-0x00516238.MemmoveWrapper.md`
  - `by-class/MemoryMan.md`
  - `by-file/MemoryMan.md`
  - `by-global/MemoryAllocationHelpers.md`
  - `by-memory/0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md`
  - `by-memory/0x00516240-0x00516258.Memmove0Wrapper.md`
- Agent-owned report/checklist file updated:
  - `tools/leaser/Agents/Agent-B006/research/0001BH-MemmoveWrapper-source-quality.md`
- Concurrent state preserved:
  - [UID:0001BI] was implemented by B009 while B006 waited on leases. B006 did not apply 0001BI metadata/C++ in this callback and updated only the sibling relationship note around that accepted B009 state.

## Implementation Tracking Checklist

Implementation callback pass:

- [x] Supervisor validation required before implementation.
  - Proof: supervisor callback explicitly accepted this report and assigned implementation for [UID:0001BH].
- [x] Target/support docs updated.
  - Proof: target, MemoryMan class/file docs, global helper doc, parent memory-range doc, and sibling note all edited and validated.
- [x] Current target state and actual evidence checked recorded.
  - Proof: target/support docs now cite MCP session `80de0a67`, health-ok lookup/analyze/disasm/bytes/callee/import-negative evidence; raw PE direct-call counts 604 (`0x25c`) to [UID:0001BH] and 19 to [UID:0001BI]; and `int_convert.py` conversions for range, `retn 0Ch`, padding, parent size, and fanout.
- [x] Metadata/score changes applied to target [UID:0001BH].
  - Proof: target validator command `000000003121` accepted `COMPLETION:90`, `CONFIDENCE:90`, `CANONICAL_OWNER:00007U`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007U`, and blank emitter position.
- [x] Score-limiting blockers researched to resolution.
  - Proof: docs now resolve helper/API placement as `MemoryMan::MemmoveWrapper`, source route through [UID:0000L7] / `MemoryMan.cpp`, and reject CRT/no-code ownership because the wrapper calls internal `_memmove` at `0x005c95b0` and has broad project fanout.
- [x] Owner/emitter/reconstructable changes applied.
  - Proof: target metadata now uses direct owner/emitter [UID:00007U]; support docs retain source-route context through [UID:0000L7].
- [x] Split/rename/new-child decisions applied.
  - Proof: no new child/split/rename was created; target keeps exact range `0x00516220-0x00516238`; padding `0x00516238-0x00516240` is documented; [UID:0001BI] B009 state was preserved rather than overwritten by B006.
- [x] Source-placement, range/split/padding/reclassification, and IDA-change decisions applied or confirmed not applicable.
  - Proof: docs now place the C++ as a `MemoryMan` class method; no IDA DB edits, renames, types, or comments were made.
- [x] First-draft C++ inserted and no-code rejection preserved.
  - Proof: target includes the exact accepted `void *MemoryMan::MemmoveWrapper(void *destination, const void *source, size_t size)` block and records rejection of runtime-glue/no-code disposition.
- [x] Exact target/support doc facts incorporated at report-level useful detail.
  - Proof: target/support docs include MCP/raw PE facts, `GetMemoryMan()`/ECX owner route, internal `_memmove` route, 604-call fanout, exact range/padding, sibling relation, rejected alternatives, and confidence cap.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
  - Proof: docs supersede "blank pending final copy-helper source split", preserve exact-name uncertainty as the 90 confidence cap, and reject file-level direct owner, CRT/runtime/no-code, feature-caller owner, sibling merge, and unsupported names such as `CopyBytes`/`CopyMemory`/`MoveMemory`.
- [x] Wave2/Wave3 mentions or artifacts handled.
  - Proof: implementation relies on current MCP/raw PE evidence; older simroot/Wave references remain lead-only where encountered and were not used as authority.
- [x] Open questions closed or documented as evidence-backed unresolved.
  - Proof: original header spelling/source declaration remains the explicit confidence cap; [UID:0001BI] is no longer B006-unresolved because B009 concurrently resolved it and B006 preserved that accepted state.
- [x] Validators run during implementation.
  - Proof: scoped validators for all six changed by-* files passed with exit 0 / `ok: 1`; command ids `000000003121`, `000000003122`, `000000003123`, `000000003124`, `000000003126`, and `000000003127`.
- [x] Generated report refresh / supervisor-owned coverage handling observed.
  - Proof: B006 made no manual generated/project-level/tool-state/IDA DB/manual coverage edits; validator-owned registry/index/stats/link side effects and deferred generated refresh were recorded.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000004165","destination_path":"executed-b-agent-research/B006/0001BH-MemmoveWrapper-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B006/research/0001BH-MemmoveWrapper-source-quality.md","timestamp":"2026-06-26T18:09:46","uid":"0001BH"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
