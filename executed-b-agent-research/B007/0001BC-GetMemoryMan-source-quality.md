** TARGET-REPORT-UID:0001BC **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001BC GetMemoryMan Source-Quality Research

Initial report-only scope followed: no target/support by-* docs, generated files, project-level files, validator/tool state, IDA DB, `by-memory/-coverage-report.md`, or other `-coverage-report.md` files were edited before supervisor acceptance. Approved implementation callback scope is now complete: B007 edited only the accepted target/support by-* docs plus this report checklist, ran scoped validators, did not spawn subagents, did not touch IDA DB, and made no manual generated/project-level/manual coverage/tool-state edits.

## Finalized Report / Current Recommendation

- Current recommendation: update [UID:0001BC] `by-memory/0x00516030-0x00516036.GetMemoryMan.md` from a blank-code, source-shape-blocked accessor page to a source-ready file-level free helper in [UID:0000L7] `MemoryMan.cpp`.
- Final disposition: retain `CANONICAL_OWNER:0000L7`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000L7`, blank `EMITTER_POSITION_OPTIONAL`, and add formal accessor C++ on the target page.
- Recommended target score: raise from `COMPLETION:86`, `CONFIDENCE:90` to `COMPLETION:90`, `CONFIDENCE:92`.
- Required action: supervisor validation, then implementation callback to update the target plus the MemoryMan support docs listed below and run scoped validators.
- Confidence: very strong for binary behavior, boundary, global route, owner/emitter route, and free-helper source shape. Below final-audit because the exact original helper/global spelling is inferred from binary role and project naming, not recovered from debug/source symbols.

## Target

- Target UID: `0001BC`
- Target path: `by-memory/0x00516030-0x00516036.GetMemoryMan.md`
- Source queue/report row: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`
- Current supervisor classification: not covered by executed B-agent research; source-quality blockers are final accessor declaration/source shape, free helper versus method/inline form, source-facing global/helper names, padding after `0x00516036`, MemoryMan support-doc alignment, and first-draft C++ readiness.
- Current target metadata: `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000L7`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000L7`, blank formal C++.

## Current Target State

The existing target page is already correct on the central behavior: `0x00516030-0x00516036` is a six-byte accessor returning singleton storage `0x0069b4fc`, currently documented as [UID:0000RH] `g_pMemoryMan`. It correctly records the owner/emitter route through [UID:0000L7] `MemoryMan`, broad caller fanout, operator-wrapper relationships, and post-body padding. The remaining defect is disposition: it keeps formal C++ blank because the page had not resolved whether the original source shape was a method, free helper, or inline-adjacent accessor and whether the source-facing names were good enough for emitted code.

That blocker is now resolved for the target page. The best current source form is an out-of-line free helper in `MemoryMan.cpp`:

```cpp
MemoryMan* GetMemoryMan()
{
    return g_pMemoryMan;
}
```

This is not a claim that IDA recovered the exact original source spelling. It is the strongest source-facing reconstruction from the current evidence and matches the already accepted project alias/resolved-name convention.

## Supervisor Active Recheck

- Assignment id: `B007-report-0001BC-get-memory-man-source-quality-20260626`
- Mode: report-only research first. No by-* implementation edits were allowed or made.
- Split repair required before final report: no. The B001 split report already converted parent [UID:0001BA] into a non-emitting split index, created the ignored no-xref stub child [UID:0003VP], and recorded internal `0xcc` padding. This target remains the exact accessor child.
- Source-bearing child status: this exact child is source-bearing and eligible for formal C++ because it is reconstructable, has a nonblank emitter route to valid file root [UID:0000L7], and its current combined score is already greater than `85`.

## Evidence Standards Used

- IDA MCP evidence is ground truth for function boundary, disassembly, decompilation, bytes, xrefs, globals, type absence, and operator-wrapper callees.
- Existing by-* docs and executed B-agent reports are lead/support evidence; current MCP evidence below is the active verification.
- Generated `auto-generated/-ag-*` rows are state/queue evidence only. They are stale for some MemoryMan rows, including old scores and the missing renamed destructor path. Do not manually edit generated rows.
- Numeric conversions cited in decimal were checked with `python .\tools\int_convert.py --pretty` from `source-3/project-documentation`: `0x06` = 6 bytes, `0x20` = 32 bytes, `0x14` = 20 bytes, `0x40` = 64 bytes, `0x7e` = 126 bytes, `0x2e` = 46 bytes, `0x0f` = 15 bytes, `0x0a` = 10 bytes, and `0xb5` = 181 bytes with explicit two-byte size. (Verified with `int_convert.py`.)

## Current MCP Session

IDA MCP was available and responsive. This report is not fallback-only.

- Read-only status check time: `2026-06-26T16:21:17`.
- Endpoint: `http://127.0.0.1:13337/mcp`.
- Listener/process status: `Get-NetTCPConnection` showed `127.0.0.1:13337` with `Listen` on PID `13684` and established local connections; visible processes included `idalib-mcp` PID `17084` and Python worker PID `26892`.
- `initialize` returned server `ida-pro-mcp` version `1.0.0`, protocol `2025-06-18`.
- `idb_list` reported active session `80de0a67`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, backend `worker`, active worker PID `26892`, `is_analyzing:false`.
- `server_health(database=80de0a67)` returned `status:ok`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, strings cache size `2067`.
- Current read-only tools used: `lookup_funcs`, `decompile`, `disasm`, `get_bytes`, `xrefs_to`, `callees`, `list_globals`, `search_structs`, `type_query`, and `entity_query`.

## IDA MCP Facts

### Function / Boundary Facts

`lookup_funcs(database=80de0a67)` reports:

| Query | Result |
| --- | --- |
| `0x00516030` | function `sub_516030`, size `0x6` / 6 bytes (Verified with `int_convert.py`) |
| `0x00516036` | not a function |
| `0x00516040` | not a function |
| `0x00516045` | not a function |
| `0x00516050` | function `sub_516050`, size `0x7e` / 126 bytes (Verified with `int_convert.py`) |
| `0x004f4aa0` | function `sub_4F4AA0`, size `0x14` / 20 bytes (Verified with `int_convert.py`) |
| `0x004f4ac0` | function `sub_4F4AC0`, size `0x40` / 64 bytes (Verified with `int_convert.py`) |
| `0x00516000` | constructor function `sub_516000`, size `0x0f` / 15 bytes (Verified with `int_convert.py`) |
| `0x00516010` | resolves through atexit thunk `sub_60C260`, size `0x0a` / 10 bytes (Verified with `int_convert.py`) |
| `0x00516260` | scalar deleting destructor `sub_516260`, size `0x2e` / 46 bytes (Verified with `int_convert.py`) |
| `0x00516290` | successor `sub_516290`, size `0xb5` / 181 bytes (Verified with `int_convert.py`) |
| `0x0069b4fc`, `0x0069b3a8`, `0x0061eb08` | not functions |

### Accessor Body

`disasm 0x00516030` reports exactly two instructions:

```asm
0x00516030  mov eax, dword ptr unk_69B4FC
0x00516035  retn
```

`decompile 0x00516030` reports:

```c
int sub_516030()
{
  return unk_69B4FC; /*0x516035*/
}
```

The raw decompiler return type `int` is a type-recovery artifact. The only referenced object is the singleton pointer storage `0x0069b4fc`, which support docs and lifecycle xrefs identify as `MemoryMan* g_pMemoryMan`.

`get_bytes 0x00516030 size 0x20` confirms the exact byte window:

```text
0xa1 0xfc 0xb4 0x69 0x0 0xc3
0xcc 0xcc 0xcc 0xcc 0xcc 0xcc 0xcc 0xcc 0xcc 0xcc
0x33 0xc0 0xc2 0x4 0x0
0xcc 0xcc 0xcc 0xcc 0xcc 0xcc 0xcc 0xcc 0xcc 0xcc 0xcc
```

Interpretation: the six-byte accessor is `mov eax, [0x0069b4fc]; ret`, followed by ten `0xcc` bytes from `0x00516036-0x00516040`, then the separate ignored no-xref return-zero stub at `0x00516040-0x00516045`, then more `0xcc` padding before `AllocateBufferMemory` at `0x00516050`.

### Xrefs And Fanout

`xrefs_to 0x00516030 limit 120` returned 120 code xrefs with `more:true`. Early samples include `0x00457aca`, `0x00457c7a`, `0x00457e09`, `0x00457e18`, `0x0045801d`, `0x0045802e`, `0x0045828d`, `0x004583ef`, `0x00458451`, and `0x004584b5`. This current MCP pass reconfirms broad project fanout; B001's accepted raw PE scan remains the exact count lead at `612` rel32 calls.

`xrefs_to 0x0069b4fc` reports exactly four data xrefs:

| Xref | Meaning |
| --- | --- |
| `0x00516008` in `sub_516000` | constructor writes `this` to singleton pointer |
| `0x00516016` in `sub_60C260` / reset tail | ordinary destructor/reset clears singleton pointer |
| `0x00516030` in `sub_516030` | accessor reads singleton pointer |
| `0x00516270` in `sub_516260` | scalar deleting destructor clears singleton pointer |

`xrefs_to 0x00516040`, `0x00516036`, and `0x00516045` all report zero xrefs, preserving the B001 ignored-stub and padding model.

`xrefs_to 0x0061eb08` reports three vtable refs from constructor, reset/destructor, and scalar deleting destructor. `xrefs_to 0x0069b3a8` reports two static-object refs from the static initializer and atexit thunk. These support the singleton lifecycle model and reject feature-owner explanations for the pointer.

### Operator-Wrapper Relationship

`decompile 0x004f4aa0` reports:

```c
int __cdecl sub_4F4AA0(int pExceptionObject)
{
  sub_516030(); /*0x4f4aa6*/
  return sub_516050(pExceptionObject); /*0x4f4ab2*/
}
```

`decompile 0x004f4ac0` reports:

```c
int __cdecl sub_4F4AC0(void *Block)
{
  sub_516030(); /*0x4f4ae2*/
  return sub_516170(Block); /*0x4f4afc*/
}
```

`callees` confirms `0x004f4aa0` calls only `0x00516030` and `0x00516050`; `0x004f4ac0` calls only `0x00516030` and `0x00516170`. The accessor is therefore part of the MemoryMan-backed allocation policy surface, not a caller-owned helper.

### Name / Type / Source-Breadcrumb Checks

Current MCP negative evidence:

- `list_globals *MemoryMan*` returns the `MemoryMan` vtable/RTTI family: `??_7MemoryMan@@6B@`, `??_R4MemoryMan@@6B@`, `??_R3MemoryMan@@8`, `??_R2MemoryMan@@8`, `??_R1A@?0A@EA@MemoryMan@@8`, `??_R0?AVMemoryMan@@@8`, and `aAvmemoryman`.
- `list_globals *g_pMemoryMan*` returns no data.
- `entity_query strings/names/functions/globals` for `MemoryMan|GetMemoryMan|g_pMemoryMan|MemoryMan.cpp|Memory.cpp|MemoryUtil|516030|69B4FC` finds only the RTTI string `.?AVMemoryMan@@`, RTTI/vtable names, and function `sub_516030`; it does not find `GetMemoryMan`, `g_pMemoryMan`, or a source-file string.
- `search_structs MemoryMan` returns no local IDA structure.
- `type_query *MemoryMan*` returns zero type records.

Conclusion: `MemoryMan` as a class is recovered from RTTI/vtable metadata. `GetMemoryMan` and `g_pMemoryMan` are source-facing project reconstruction names inferred from role and lifecycle, not recovered original symbol names. That caps confidence below final-audit but does not block formal target C++.

## Documentation Evidence Checked

- Target page [UID:0001BC] records the exact six-byte boundary, direct singleton read, broad fanout, operator-wrapper relationships, current `86/90` score, and blank formal C++ due to source-shape uncertainty.
- [UID:0000L7] `by-file/MemoryMan.md` places the singleton accessor, global pointer, allocation/free/realloc/copy helpers, and global operators in `NexusTK/util/MemoryMan.cpp`; it also records that B006 accepted constructor C++ on child [UID:0001B9] while broader helper/operator/header caveats remain.
- [UID:00007U] `by-class/MemoryMan.md` maps class lifecycle methods only: constructor, ordinary destructor/reset, and scalar deleting destructor. It does not currently treat `GetMemoryMan` as a class method.
- [UID:0000RH] `by-global/g_pMemoryMan.md` records the singleton pointer role, lifecycle xrefs, source-facing name caveat, and blank global C++.
- [UID:0000T8] `by-global/MemoryAllocationHelpers.md` names `GetMemoryMan` as the file-level/shared MemoryMan accessor in the allocation helper family.
- [UID:0001BA] parent split index records that exact child pages own the source-bearing bodies and that this accessor stays with [UID:0000L7].
- [UID:0003VP] ignored child and [UID:0000VN] ignored ledger cover the post-accessor no-xref stub and alignment, so no split or padding repair is needed for this target.
- [UID:000196] and [UID:000197] operator wrapper pages confirm direct call edges through `GetMemoryMan` to allocate/free helpers.
- B001 executed report `executed-b-agent-research/B001/0001BA-memoryman-allocation-source-split.md` is accepted historical context for split/range/source-family decisions and raw PE call counts.
- B006 executed report `executed-b-agent-research/B006/0001B9-MemoryManConstructor-source-quality.md` is accepted historical context for current MCP session `80de0a67`, MemoryMan lifecycle, `g_pMemoryMan` name caveat, and the precedent that exact child bodies may emit even while broader header/static-object/operator factoring remains a support-doc confidence cap.
- `by-project-structure/proposed-source-tree.md` places this source family at `util/MemoryMan.cpp` and says it owns the 4-byte singleton object, `g_pMemoryMan`, constructor/reset/destructor behavior, `GetMemoryMan`, allocation/free/realloc helpers, copy wrappers, and global operator front ends.
- `project-level/-resolved-multple-aliases.md` maps `dword_69B4FC` to `g_pMemoryMan` and `sub_516030` to `GetMemoryMan`; `project-level/-resolved.md` still carries some raw-name references as pending in unrelated docs, which is support evidence that the project-wide source-facing names exist but not original symbol proof.

## Heuristic / Inference Reanalysis And Validation

### Source Form: Free Helper Versus Class Method

Best inference: `GetMemoryMan` is a file-level free helper in `MemoryMan.cpp`, not a `MemoryMan` instance method and not currently proven as a static class method.

Evidence for free helper:

- The function takes no `this` argument, has no arguments, reads the process global pointer directly, and has broad call fanout from allocation/copy/packet/helper code.
- B001 split research assigns file-level helpers and globals, including `GetMemoryMan`, to [UID:0000L7], while routing only constructor/destructor/scalar deleting destructor through [UID:00007U].
- [UID:0000T8] treats it as a helper-family API alongside global operators and allocation/free/realloc/copy helpers.
- Current entity/name searches find no recovered scoped symbol or UDT that would support `MemoryMan::GetMemoryMan`.
- A central out-of-line free function is more plausible than header-inline source because the binary contains hundreds of direct calls to one shared address.

Evidence against free helper:

- A `static MemoryMan::GetMemoryMan()` method could compile to the same no-argument code if no source symbol survives.
- The helper returns a `MemoryMan*`, so class-scoped source is possible as a source-design alternative.

Decision: keep direct owner/emitter [UID:0000L7] and use unqualified `GetMemoryMan()` in formal C++. Class-static source remains possible but weaker and would contradict the current accepted source-family split without hard symbol evidence.

### Source-Facing Names

Best helper name: `GetMemoryMan`.

Best global name: `g_pMemoryMan`.

Evidence:

- The target's only behavior is returning singleton storage.
- Project alias reports resolve `sub_516030` to `GetMemoryMan` and `dword_69B4FC` to `g_pMemoryMan`.
- Many executed reports already use `GetMemoryMan()` as the source-facing MemoryMan accessor name after checking target-local behavior.
- Current MCP proves every `0x0069b4fc` xref is MemoryMan lifecycle/access, so `g_pMemoryMan` is semantically precise.

Counter-evidence:

- Current MCP does not recover either exact source symbol.
- `g_pMemoryMan` is a project convention name, not an IDA global.

Decision: use `MemoryMan* GetMemoryMan()` and `return g_pMemoryMan;` in formal C++. Record the inferred-name caveat in target/support docs and keep confidence below final-audit.

### Inline-Adjacent / Covered-By Alternative

Rejected. The current IDA function object is real, is exactly six bytes, and has broad direct call fanout. If the original source had been purely header-inline at all caller sites, the expected binary shape would not be one central function with hundreds of calls. If the compiler emitted an out-of-line copy for an inline function, the reconstruction still needs an out-of-line body to reproduce the observed central function.

### Padding And Stub Boundary

No target split or range repair is required. Current bytes show the six-byte accessor, ten `0xcc` bytes, the exact ignored no-xref return-zero stub [UID:0003VP], then padding to `0x00516050`. Current xrefs to `0x00516036`, `0x00516040`, and `0x00516045` are zero. The B001 padding/stub handling remains valid.

### Final C++ Readiness

The target clears the formal-code gate:

- `RECONSTRUCTABLE:TRUE`.
- Nonblank emitter [UID:0000L7] reaches file root `NexusTK/util/MemoryMan.cpp`.
- Current score average is `(86 + 90) / 2 = 88`, already above `85`; recommended score is `90/92`.
- Body, boundary, source placement, names, and meaningful dependencies are documented.
- Formal C++ contains only this target's own source body and no outside static-object/global declaration body.

## Inference Claim Ledger

| Claim | Confidence | Evidence | Counter-evidence checked | Next verification / remaining uncertainty |
| --- | --- | --- | --- | --- |
| `0x00516030-0x00516036` is exactly the accessor body | Confirmed | `lookup_funcs`, `disasm`, `decompile`, `get_bytes`; `0x00516036` not a function | Checked successor bytes and ignored stub; no xrefs to `0x00516036` | None for boundary unless IDB changes |
| Accessor returns singleton pointer storage `0x0069b4fc` | Confirmed | `mov eax, [unk_69B4FC]`; xrefs to `0x0069b4fc` exactly constructor write/reset clear/accessor read/scalar-dtor clear | Checked globals and lifecycle support pages | Exact original global spelling not recovered |
| Direct source owner/emitter should remain [UID:0000L7] `MemoryMan.cpp` | Strongly inferred | B001 split report, file/helper docs, broad callers, operator wrappers, proposed source tree | Class-static method alternative considered; no recovered scoped symbol/UDT | Matching PDB/linker map could rename or rescope |
| Best formal source body is `MemoryMan* GetMemoryMan(){ return g_pMemoryMan; }` | Strongly inferred | Exact behavior, accepted source-facing names, current code gate, B006 constructor precedent | Raw `int sub_516030`, method form, inline/covered-by form rejected | Future symbol evidence could rename helper/global |
| No target split or post-body code merge is required | Confirmed | `get_bytes`, `lookup_funcs`, `xrefs_to` for padding/stub addresses, B001 ignored child page | Checked no-xref stub and next function boundary | Future reachability evidence for `0x00516040` would be a separate [UID:0003VP] issue |

## Positive Evidence Summary

- Current MCP directly confirms the function body and range.
- Current MCP directly confirms the singleton pointer route.
- Current MCP directly confirms broad fanout and operator-wrapper use.
- Existing accepted B001/B006 reports and current support docs consistently place this exact child in the MemoryMan utility source family.
- Negative name/type searches explain why the target cannot claim original symbol proof, but they do not create a blocker: the project already uses source-facing inferred names for this family, and this body is mechanically exact.

## Negative Evidence Summary

- No recovered `GetMemoryMan` symbol, `g_pMemoryMan` symbol, `MemoryMan.cpp` string, local `MemoryMan` UDT, or type record exists in the current IDB.
- No `this` parameter, vtable write, or object field access appears in the accessor body, so instance method ownership is rejected.
- A static class method remains binary-equivalent but lacks positive evidence and is weaker than the current file-level helper/source-family model.
- No xrefs to `0x00516036`, `0x00516040`, or `0x00516045` require changing the accessor range.
- Generated reports are stale for some rows; do not treat their old scores/paths as current source truth.

## Ranked Ownership Analysis

### 1. [UID:0000L7] `MemoryMan.cpp` file-level helper

- Evidence for: current by-file, helper-family, parent split, proposed source tree, broad callers, global operator wrapper callees, direct singleton global access, and accepted B001 source-split recommendation all put this helper in `MemoryMan.cpp`.
- Evidence against: exact source symbol and original declaration spelling are not recovered.
- Decision: accepted. Keep `CANONICAL_OWNER:0000L7` and `EMITTER_UIDS:0000L7`.

### 2. [UID:00007U] `MemoryMan` class static method

- Evidence for: the helper returns a `MemoryMan*`; static class methods compile without a `this` argument.
- Evidence against: no recovered scoped symbol, no class UDT/type, no class-page method-map evidence, and existing accepted split routes only lifecycle bodies through the class.
- Decision: rejected for current docs. Do not change owner/emitter to [UID:00007U].

### 3. Inline/header-only helper

- Evidence for: a trivial accessor might have been declared in a header in source.
- Evidence against: the binary has one central six-byte function with broad direct calls; source reconstruction needs that out-of-line body to reproduce the executable.
- Decision: rejected as the formal target shape. Header declaration may exist, but this by-memory page should emit the out-of-line body.

### 4. No-code / marker-only disposition

- Evidence for: older docs left C++ blank because exact public API spelling was not final-proof.
- Evidence against: current code-entry gate is met; body is exact; source placement and names are strong enough; no-code would keep a real source-bearing function unmodeled.
- Decision: rejected. Add formal C++.

## First-Draft C++ Recommendation

Eligible for draft C++: yes.

Exact formal `RECONSTRUCTION_CPP CODE` insertion text for [UID:0001BC]:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
MemoryMan* GetMemoryMan()
{
    return g_pMemoryMan;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Reason it preserves exact behavior:

- It reads the same singleton pointer and returns it.
- It has no arguments, no side effects, no conditional behavior, and no callee dependencies.
- The compiler should emit the observed load/return shape when `g_pMemoryMan` is a process-global `MemoryMan*`.

Reason it matches plausible original source:

- A small out-of-line `GetMemoryMan` free helper in `MemoryMan.cpp` is consistent with broad cross-module call sites and the nearby allocation helper family.
- It avoids raw labels (`sub_516030`, `unk_69B4FC`) and decompiler type artifacts (`int`) in final source.
- It does not hand-write padding, startup/atexit glue, vptr stores, or unrelated helper bodies.

Names/types used:

- `MemoryMan*`: inferred from RTTI/vtable class evidence and singleton lifecycle.
- `GetMemoryMan`: inferred source-facing helper name already resolved project-wide.
- `g_pMemoryMan`: inferred source-facing global name already resolved project-wide.

No-code proof: not applicable. The target is source-ready and should not remain blank.

## Final Recommendation

- Apply target metadata: `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:0000L7`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000L7`, blank `EMITTER_POSITION_OPTIONAL`, `Nested:0`.
- Insert the formal C++ block above on [UID:0001BC].
- Preserve the current exact range `0x00516030-0x00516036`; do not split, merge, or rename the file.
- Keep [UID:0003VP] and padding rows unchanged.
- Keep [UID:0000L7] as direct owner/emitter; do not reroute to [UID:00007U].
- Update support docs to say the accessor's own C++ blocker is resolved while broader MemoryMan header/operator/copy/static-object declaration questions remain confidence caps for their own pages.

## Recommended Target Doc Changes

Target path: `by-memory/0x00516030-0x00516036.GetMemoryMan.md`

Exact facts to incorporate:

- Current MCP session `80de0a67` health and active `NexusTK.exe.i64` facts.
- `lookup_funcs`: `sub_516030`, size `0x6` / 6 bytes (Verified with `int_convert.py`), end-exclusive `0x00516036` not a function.
- `disasm`/`decompile`: `mov eax, dword ptr unk_69B4FC; retn`; decompiler returns `unk_69B4FC`.
- `get_bytes`: exact six-byte body, ten `0xcc` bytes, separate [UID:0003VP] `33 c0 c2 04 00`, and padding before `0x00516050`.
- `xrefs_to 0x0069b4fc`: constructor write, reset clear, accessor read, scalar deleting destructor clear.
- `xrefs_to 0x00516030`: broad fanout, at least 120 returned with `more:true`; preserve B001 raw PE count of `612` rel32 callers as accepted historical exact count.
- Operator wrapper current MCP decompilation/callees: `0x004f4aa0` calls `GetMemoryMan` then `AllocateBufferMemory`; `0x004f4ac0` calls `GetMemoryMan` then `FreeBufferMemory`.
- Negative symbol/type evidence: current IDB has MemoryMan RTTI/vtable names only, no recovered `GetMemoryMan`, `g_pMemoryMan`, source-file string, local UDT, or type record.
- Source-form conclusion: file-level free helper in `MemoryMan.cpp`, not class method, not marker-only, not inline-only.
- Formal C++ block from this report.

Recommended target metadata/score:

```text
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000L7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Recommended target `Item Summary`:

```text
Source-ready MemoryMan singleton accessor: exact six-byte body at 0x00516030 returns g_pMemoryMan, has broad allocation/copy fanout, remains a file-level helper in MemoryMan.cpp, and now has formal accessor C++.
```

## Recommended Support Doc Changes

### `by-file/MemoryMan.md`

- Keep `COMPLETION:89`, `CONFIDENCE:86`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/"`, `CANONICAL_OWNER:FILE`.
- Update the `GetMemoryMan` row and generated caveats to state that [UID:0001BC] now emits formal free-helper C++ on the child page.
- Preserve the broader caveats for exact static-object declaration spelling, global operator placement, copy-wrapper placement, and final header factoring as file-level confidence caps.
- Add current B007 evidence summary: six-byte accessor body, direct `g_pMemoryMan` return, broad MCP fanout, operator wrappers, no recovered helper/global symbol, free-helper source-form decision.

### `by-class/MemoryMan.md`

- Keep current metadata and blank class-level C++.
- Add or preserve wording that `GetMemoryMan` remains a file-level helper routed through [UID:0000L7], while class [UID:00007U] owns constructor, ordinary destructor/reset, and scalar deleting destructor.
- State that B007 rejected rerouting [UID:0001BC] as a class method because no current symbol/type evidence supports a scoped static method over the accepted file-helper route.

### `by-global/g_pMemoryMan.md`

- Keep current metadata and blank formal global C++.
- Add current B007 proof that the accessor reads `0x0069b4fc`, and current xrefs to that storage are exactly constructor write, reset clear, accessor read, and scalar deleting destructor clear.
- State that `g_pMemoryMan` remains an inferred source-facing name, not a recovered IDA global symbol, but is now accepted for the [UID:0001BC] formal accessor body.

### `by-global/MemoryAllocationHelpers.md`

- Keep current metadata and blank helper-family C++.
- Update the helper map/source-placement notes to say [UID:0001BC] `GetMemoryMan` formal C++ is ready as a file-level MemoryMan helper; global operator and copy-wrapper declarations remain separate blockers for those pages.

### `by-memory/0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md`

- Keep parent metadata `RECONSTRUCTABLE:FALSE`, blank emitter, and non-emitting split-index status.
- Update the `GetMemoryMan` covered-range row and final-C++ exclusion wording so it no longer implies [UID:0001BC] is blank or blocked; parent remains no-code because exact children carry source.

### `by-type/by-struct/MemoryManLayout.md`

- No required metadata change.
- Optional support update: add B007 note that `GetMemoryMan` reads the singleton pointer and does not imply an additional object field beyond the one-vptr binary layout.

### Conditional No-Edit Proofs

No support edit is required unless implementation finds a contradiction in these pages:

- `by-memory/0x00419f70-0x00419f86.MemoryManStaticInitializer.md`
- `by-memory/0x0060c260-0x0060c26a.MemoryManAtexitResetThunk.md`
- `by-memory/0x0069b3a8-0x0069b3ac.MemoryManStaticObjectStorage.md`
- `by-memory/0x0069b4fc-0x0069b500.g_pMemoryMan.md`
- `by-memory/0x004f4aa0-0x004f4ab4.OperatorNewWrapper.md`
- `by-memory/0x004f4ac0-0x004f4b00.OperatorDeleteWrapper.md`

These pages already support the target recommendation at current detail. Edit them only if they still state that [UID:0001BC] must remain blank or that its source form is unresolved.

## Score And Metadata Recommendation

Current target score/metadata:

- `COMPLETION:86`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:0000L7`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000L7`
- blank formal C++

Recommended target score/metadata:

- `COMPLETION:90`
- `CONFIDENCE:92`
- keep `CANONICAL_OWNER:0000L7`
- keep `RECONSTRUCTABLE:TRUE`
- keep `EMITTER_UIDS:0000L7`
- add formal C++

Score rationale:

- Completion rises because the report closes the source-form/name/C++ blocker, records current MCP session facts, byte window, broad fanout, operator-wrapper relationship, negative symbol/type search, rejected alternatives, and exact formal C++.
- Confidence rises because all material binary facts are direct and the source placement is consistent with accepted B001/B006 MemoryMan support docs. It remains below final-audit because exact original helper/global spelling, exact header declaration placement, and class-static-vs-free source proof remain unrecovered.
- Reason not higher: no PDB/map/source string, no recovered `GetMemoryMan` symbol, no recovered `g_pMemoryMan` symbol, no local UDT/type record, and support pages still need broader MemoryMan header/global/operator declaration factoring.

Score-improvement attempt:

- Source-form blocker: resolved to file-level free helper after checking body shape, accepted B001 split, class method alternatives, and source-tree/helper docs.
- Name blocker: resolved to inferred source-facing `GetMemoryMan`/`g_pMemoryMan` with explicit no-original-symbol caveat.
- Padding/range blocker: resolved by current bytes and xrefs plus B001 ignored stub page.
- Operator-wrapper blocker: resolved by current `decompile`/`callees` for `0x004f4aa0` and `0x004f4ac0`.
- First-draft C++ blocker: resolved by exact formal block above.

## Open Questions With Attempted Resolution

- Exact original spelling of `GetMemoryMan`: unresolved because current IDB has no such symbol. Resolution for current docs: use `GetMemoryMan` as the strongest source-facing reconstructed name; this is good enough for first-draft C++ and caps confidence below final-audit.
- Exact original spelling/linkage of `g_pMemoryMan`: unresolved because current IDB has no global symbol. Resolution for current docs: use `g_pMemoryMan` because every xref belongs to MemoryMan singleton lifecycle/access; do not claim recovered original proof.
- Was the source written as `MemoryMan::GetMemoryMan()` instead of free `GetMemoryMan()`? Current evidence cannot prove impossible, but the accepted MemoryMan source split, helper-family docs, broad free-helper use, and lack of scoped symbol make free helper the best current reconstruction. No further current investigation route is left short of external symbol/source metadata.
- Was this inline in a header? Rejected for this exact binary target because a central out-of-line function exists and must be reconstructed.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Not applicable. Do not manually edit `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, `by-memory/-coverage-report.md`, or any other coverage report. The target/support source docs plus scoped validators should refresh generated state. The current generated research tracker and auto coverage report are stale for parts of the MemoryMan family and should be refreshed through validator-owned workflows only.

## Validator Results

- Report-only pass: no validators run because no by-* docs were edited.
- Implementation callback validators from `E:\NTK\GhidraBridge\source-3\project-documentation`:

| File | Command id / timestamp | Exit | ok | Generated refresh | Warnings / side effects |
| --- | --- | ---: | ---: | --- | --- |
| `by-memory\0x00516030-0x00516036.GetMemoryMan.md` | `000000002950` / `2026-06-26T16:39:07-04:00` | 0 | 1 | deferred, command id/timestamp same | Metadata updates for `90/92`, `insert_header_blank`, `missing_ref_uid 0003VP`, reference-index adds for `0001BD`/`0001BF`, projected stats update. |
| `by-file\MemoryMan.md` | `000000002951` / `2026-06-26T16:39:18-04:00` | 0 | 1 | deferred, command id/timestamp same | `missing_ref_target 0001BB` for stale validator target `by-memory/0x00516010-0x00516021.MemoryManGlobalResetTail.md`; `missing_ref_uid 0003VP`; validator inserted UID link for `0001BC`; projected stats update. Source text already links current `MemoryManDestructor.md`, so no manual registry/state edit was made. |
| `by-class\MemoryMan.md` | `000000002952` / `2026-06-26T16:39:27-04:00` | 0 | 1 | deferred, command id/timestamp same | Same stale `0001BB` target warning, `missing_ref_uid 0003VP`, validator UID link insertions for `0001BC`, reference-index add, projected stats update. |
| `by-global\g_pMemoryMan.md` | `000000002953` / `2026-06-26T16:39:33-04:00` | 0 | 1 | deferred, command id/timestamp same | Same stale `0001BB` target warning, `missing_ref_uid 0003VP`, validator UID link insertion for `0001BC`, reference-index adds for `000196`/`000197`, projected stats update. |
| `by-global\MemoryAllocationHelpers.md` | `000000002954` / `2026-06-26T16:39:49-04:00` | 0 | 1 | deferred, command id/timestamp same | `missing_ref_uid 0003VP`, validator UID link insertion for `0001BC`, canonical-owner/autogen registry refresh, projected stats update. |
| `by-memory\0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md` | `000000002955` / `2026-06-26T16:39:58-04:00` | 0 | 1 | deferred, command id/timestamp same | Same stale `0001BB` target warning, `missing_ref_uid 0003VP`, validator UID link insertions for `0001BC`, reference-index adds for `0000VN`/`0001BK`, metadata/autogen registry refresh, projected stats update. |

- Generated-refresh queue proof: `python .\tools\validator.py --queue-status` returned command id `000000002956`, timestamp `2026-06-26T16:40:11-04:00`, `queued jobs:0`, `processing jobs:0`, `queued generated refresh jobs:0`, and `processing generated refresh jobs:0`. Generated files were not manually edited; validator-owned refresh/state side effects are recorded above.
- Optional layout validator not run because `by-type/by-struct/MemoryManLayout.md` was not edited. Conditional support validators not run because the conditional pages were checked and required no edits.

## Changed Files

- Created by B007: `tools/leaser/Agents/Agent-B007/research/0001BC-GetMemoryMan-source-quality.md`
- Modified by B007 during approved implementation callback:
  - `by-memory/0x00516030-0x00516036.GetMemoryMan.md`
  - `by-file/MemoryMan.md`
  - `by-class/MemoryMan.md`
  - `by-global/g_pMemoryMan.md`
  - `by-global/MemoryAllocationHelpers.md`
  - `by-memory/0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md`
  - this report checklist/proof file.
- Not modified after equal-or-greater detail/no-contradiction check: `by-type/by-struct/MemoryManLayout.md`, `by-memory/0x00419f70-0x00419f86.MemoryManStaticInitializer.md`, `by-memory/0x0060c260-0x0060c26a.MemoryManAtexitResetThunk.md`, `by-memory/0x0069b3a8-0x0069b3ac.MemoryManStaticObjectStorage.md`, `by-memory/0x0069b4fc-0x0069b500.g_pMemoryMan.md`, `by-memory/0x004f4aa0-0x004f4ab4.OperatorNewWrapper.md`, and `by-memory/0x004f4ac0-0x004f4b00.OperatorDeleteWrapper.md`.
- Leases acquired for the immediate edit/validator batch: `python .\tools\leaser\leaser.py B007 lease by-memory\0x00516030-0x00516036.GetMemoryMan.md by-file\MemoryMan.md by-class\MemoryMan.md by-global\g_pMemoryMan.md by-global\MemoryAllocationHelpers.md by-memory\0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md` returned `Success` for all six files.
- Lease release proof: explicit `python .\tools\leaser\leaser.py B007 unlease ...` after validators returned `Rejected[No active lease]` for all six paths because the short leases had already expired/cleared. `tools/leaser/Agents/current_leases.md` then showed only unrelated B004 leases and no B007 rows; `tools/leaser/Agents/Agent-B007/current_leases.md` showed stale expired Supervisor rows only and no B007 rows.
- IDA DB edits: none.
- Manual generated/project-level/manual coverage/tool-state edits: none. Validators performed their normal registry/projected-stats/generated-refresh side effects.

## Follow-Up Actions

- Supervisor: verify the changed docs/checklist/validator results claim by claim, then execute this report through the validator if accepted.
- B007 implementation callback: complete; no unchecked accepted items remain.
- Future research outside this target: only needed if external source/PDB/map evidence later recovers exact `GetMemoryMan`/`g_pMemoryMan` spelling or proves a class-static method form.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Proof: supervisor sent `IMPLEMENTATION CALLBACK APPROVED` and updated `goal.md`; callback applied under assignment `B007-report-0001BC-get-memory-man-source-quality-20260626`.
- [x] Target doc to update: `by-memory/0x00516030-0x00516036.GetMemoryMan.md`; set target metadata to `90/92`, keep owner/emitter [UID:0000L7], add current MCP evidence, source-form decision, rejected alternatives, score rationale, and exact formal C++ block. Proof: target header now shows `COMPLETION:90`, `CONFIDENCE:92`, unchanged `CANONICAL_OWNER:0000L7`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000L7`, blank emitter position, updated item summary, formal `MemoryMan* GetMemoryMan(){ return g_pMemoryMan; }` body, and sections `2026-06-26 B007 Source-Quality Implementation`, `Reconstruction Notes`, `Score Rationale`, and `Changes`.
- [x] Support doc to update: `by-file/MemoryMan.md`; record [UID:0001BC] formal C++ readiness, keep source route `NexusTK/util/MemoryMan.cpp`, and preserve broader header/operator/copy/static-object caveats as file-level confidence caps. Proof: `Proposed Contents`, `Evidence`, `Generated Output Caveats`, `Source-Structure Decision`, `Score Rationale`, and `Changes` now include the B007 accessor disposition while score/path/owner remain unchanged.
- [x] Support doc to update: `by-class/MemoryMan.md`; preserve class lifecycle-only method map and add/reconfirm why [UID:0001BC] stays file-level, not class-owned. Proof: `Method Map` remains constructor/destructor/scalar deleting destructor only, and `2026-06-26 B007 Accessor Source-Quality Recheck`, `Reconstruction Caveats`, `Score Rationale`, and `Changes` document the rejected class-static/method route.
- [x] Support doc to update: `by-global/g_pMemoryMan.md`; add current B007 accessor proof and inferred-name caveat; keep global formal C++ blank. Proof: `Evidence`, `Source Migration Caveats`, and `Changes` include B007 accessor read/body/xref/operator-wrapper/negative-symbol facts and preserve blank global C++ plus exact-declaration-spelling caveat.
- [x] Support doc to update: `by-global/MemoryAllocationHelpers.md`; record that `GetMemoryMan` accessor C++ is ready while global operator/copy-wrapper source details remain separate page blockers. Proof: `Helper Map`, `Ownership Notes`, `Reconstruction Caveats`, and `Changes` now call [UID:0001BC] source-ready and keep family-level/global-operator/copy-wrapper blockers separate.
- [x] Support doc to update: `by-memory/0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md`; update covered-range/source-readiness wording for [UID:0001BC] while preserving non-emitting split-index status. Proof: item summary, `Covered Ranges`, `2026-06-26 B007 GetMemoryMan Source-Quality Sync`, `Final C++ Exclusion`, and `Changes` now say exact child [UID:0001BC] carries source while parent stays `RECONSTRUCTABLE:FALSE` and blank emitter/C++.
- [x] Optional support doc to update if implementation finds it useful: `by-type/by-struct/MemoryManLayout.md`; note that accessor read does not add object fields beyond the one-vptr binary layout. Proof/no edit: no edit required because current `Layout`, `Evidence Notes`, `2026-06-16 A001 Evidence Refresh`, and `2026-06-26 B006 Constructor Layout Check` already say binary layout is one vptr, allocation policy routes through `GetMemoryMan` and nearby helpers, xrefs to `0x0069b4fc` include accessor read, and no allocation-policy fields are observed.
- [x] Conditional support docs to check and leave no-edit proof or update if contradictory: static initializer, atexit thunk, static object storage, singleton storage, operator new wrapper, and operator delete wrapper pages listed in this report. Proof/no edit: all six were checked. Static initializer and atexit thunk classify compiler/static-lifetime glue regenerated from source-level static object; static object storage and singleton storage already record MemoryMan ownership/xrefs; operator wrappers already record `GetMemoryMan` -> allocation/free callees and keep their own C++ blank only for operator declaration style. None states [UID:0001BC] must remain blank or source-form-unresolved.
- [x] Metadata/score changes to apply: only [UID:0001BC] target score changes to `90/92`; support-page scores remain unchanged unless implementation discovers a current contradiction requiring score movement. Proof: only target score changed; support-page headers retain prior scores.
- [x] Owner/emitter/reconstructable changes to apply: none; target remains `CANONICAL_OWNER:0000L7`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000L7`. Proof: target header unchanged for those fields; support docs preserve owner/emitter fields.
- [x] Split/rename/new-child changes to apply: none; preserve exact target path/range and [UID:0003VP] ignored stub/padding decisions. Proof: no file renames/children; target and parent sections keep six-byte range, ten-byte padding, ignored [UID:0003VP] stub, and parent split-index model.
- [x] Source-placement and IDA rename/type/comment disposition to apply: document free-helper source placement in `MemoryMan.cpp`; no IDA DB rename/type/comment edits requested. Proof: target/support docs document file-level helper in `MemoryMan.cpp`; no IDA DB edits were made.
- [x] First-draft C++ to apply: exact formal block `MemoryMan* GetMemoryMan(){ return g_pMemoryMan; }` in the target's formal `RECONSTRUCTION_CPP CODE` block. Proof: target formal block contains the accepted `MemoryMan* GetMemoryMan()` function body returning `g_pMemoryMan` and uses no IDA/decompiler labels.
- [x] Exact target/support facts to incorporate at report-level detail: current MCP session `80de0a67`, function size `0x06`, disasm/decompile, bytes, xrefs, operator-wrapper callees, negative symbol/type searches, B001/B006 support context, and generated-state caveat. Proof: target contains the full B007 source-quality section; support docs contain scoped copies of the relevant facts by role; validator/generated refresh state is recorded above.
- [x] Historical/stale assumptions and rejected alternatives to preserve: old blank-C++ blocker superseded; class-static method, inline-only, marker-only/no-code, raw `int sub_516030`, and padding/stub merge alternatives rejected. Proof: target `Source-form decision` list and support `Changes` sections preserve these rejections; old historical `Changes` entries remain below the new superseding B007 entry.
- [x] Open questions to close/document: exact original helper/global spelling and class-static-vs-free method proof remain unrecovered but no longer block target C++; future PDB/map/source evidence could rename globally. Proof: target `Score Rationale` and support docs preserve the no-symbol/no-UDT/no-source-file-string caveat while accepting current C++.
- [x] Validators to run after accepted implementation: target and edited support files with `python .\tools\validator.py --mode file --file <path> --apply --queue-timeout 240`; record command id, timestamp, exit code, ok count, warnings, and generated refresh state. Proof: validator table above records commands/results `000000002950` through `000000002955`, all exit `0`, `ok:1`.
- [x] Generated report refresh expected: validator-owned generated reports should refresh from source docs; do not manually edit generated reports or manual coverage reports. Proof: each validator returned `generated_refresh: deferred`; queue-status `000000002956` showed no queued/processing jobs or generated refresh jobs. No manual generated/project-level/manual coverage edits were made.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation. Proof: callback prompt and `goal.md` override accepted this report.
- [x] All accepted target/support doc details incorporated at report-level detail. Proof: six accepted by-* docs were edited; layout and conditional pages recorded as equal-or-greater/no-contradiction above.
- [x] Metadata/score/C++ changes applied or explicitly not applied with reason. Proof: target `90/92` and formal C++ applied; owner/emitter/reconstructable unchanged; support scores/C++ unchanged with role-specific reasons.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved. Proof: target and support docs now record no recovered helper/global/source-file/type symbols, rejected class-static/inline/no-code/raw-decompiler/padding-stub alternatives, and superseded blank-C++ blocker.
- [x] Conditional no-edit proofs recorded for support pages not modified. Proof: layout and six conditional support pages listed above.
- [x] Validators run and results recorded. Proof: validator table records command ids `000000002950` through `000000002955`, queue-status `000000002956`, exit codes, ok counts, warnings, and generated-refresh state.
- [x] Leases acquired only for immediate edit/validator batch and released immediately afterward. Proof: B007 lease command succeeded for the six edited by-* files; explicit unlease after validators found no active lease because leases had expired/cleared; current lease reports show no B007 rows.
- [x] Remaining unapplied accepted items listed with exact blocker, if any. Proof: none remain; stale validator warnings are registry/tool-owned (`0001BB` stale target path and missing `0003VP` registry UID) and were not accepted implementation content to repair manually.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/0001BC-GetMemoryMan-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/0001BC-GetMemoryMan-source-quality.md","timestamp":"2026-06-26T16:46:02","uid":"0001BC"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
