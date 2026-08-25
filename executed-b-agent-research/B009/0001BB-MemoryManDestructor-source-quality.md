** TARGET-REPORT-UID:0001BB **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001BB MemoryManDestructor Source-Quality Research

Report-only scope followed: no target/support by-* docs, generated files, project-level files, validator/tool state, IDA DB, `by-memory/-coverage-report.md`, or other `-coverage-report.md` files were edited. No leases were taken and no subagents were spawned.

## Finalized Report / Current Recommendation

[UID:0001BB] `by-memory/0x00516010-0x00516021.MemoryManDestructor.md` is ready for formal first-draft destructor C++ on the exact target page.

The old blocker was broader than the target: the page waited for final static-object declaration spelling, ordinary destructor/source shape, atexit thunk separation, scalar-deleting destructor separation, `g_pMemoryMan` name confidence, vtable-reset handling, and `MemoryMan.cpp` placement. Current MCP evidence and existing MemoryMan support docs resolve those as target-specific blockers:

- The exact range is a 17-byte (`0x11`, Verified with `int_convert.py`) ordinary destructor/reset tail at `0x00516010-0x00516021`, reached only from the compiler atexit thunk at `0x0060c260`.
- The atexit thunk is not handwritten source for this page. It loads the source-declared static `MemoryMan` object storage and jumps to this destructor tail.
- The compiler vptr store to `MemoryMan::vftable` is destructor lowering and should not be hand-written.
- The source-authored destructor body is only the singleton clear: `g_pMemoryMan = 0;`.
- The scalar deleting destructor at [UID:0001BJ] remains a separate vtable-slot compiler wrapper/deleting body and should not be merged into this target.
- Direct owner/emitter stay [UID:00007U] `MemoryMan`; source-file route remains [UID:0000L7] `MemoryMan` / `NexusTK/util/MemoryMan.cpp`.

Recommended target score: raise `COMPLETION:86`, `CONFIDENCE:90` to `COMPLETION:90`, `CONFIDENCE:92`. Keep `CANONICAL_OWNER:00007U`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007U`, blank `EMITTER_POSITION_OPTIONAL`, and `Nested:0`.

## Current Documentation State

The target is currently strongly documented as the ordinary `MemoryMan` destructor/reset body but keeps blank formal C++ with this note:

- C++ remains blank until static-object declaration, destructor spelling, and scalar-deleting destructor separation are final-source quality.

That is now stale for this exact page. The broader MemoryMan static/global/header questions still cap final-audit confidence for support pages, but they do not block [UID:0001BB]'s own formal destructor body because the target C++ does not name the static object and does not need to model the atexit thunk or deleting-destructor wrapper.

Current generated reports are stale for this UID: `auto-generated/-ag-research-tracker.md` and `auto-generated/-ag-coverage-report-by-memory.md` still show the old `MemoryManGlobalResetTail` path, older `78/86` state, and a `file_missing` row for the renamed file. Do not edit those generated files manually. The source target/support docs plus scoped validators and report execution should refresh validator-owned state; if the stale missing path remains, the supervisor should use documented validator lifecycle cleanup rather than hand-editing generated/tool state.

## Local Docs And Reports Checked

- Target: `by-memory/0x00516010-0x00516021.MemoryManDestructor.md`.
- Direct owner/source route: `by-class/MemoryMan.md`, `by-file/MemoryMan.md`.
- Lifecycle/support pages: `by-memory/0x00419f70-0x00419f86.MemoryManStaticInitializer.md`, `by-memory/0x0060c260-0x0060c26a.MemoryManAtexitResetThunk.md`, `by-memory/0x00516000-0x0051600f.MemoryManConstructor.md`, `by-memory/0x00516030-0x00516036.GetMemoryMan.md`, `by-memory/0x00516260-0x0051628e.MemoryManScalarDeletingDestructor.md`, `by-memory/0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md`, `by-memory/0x0069b3a8-0x0069b3ac.MemoryManStaticObjectStorage.md`, `by-memory/0x0069b4fc-0x0069b500.g_pMemoryMan.md`, `by-global/g_pMemoryMan.md`, `by-global/MemoryAllocationHelpers.md`, and `by-type/by-struct/MemoryManLayout.md`.
- Source tree/name context: `by-project-structure/proposed-source-tree.md` places this family at `util/MemoryMan.cpp`; `project-level/-resolved.md` has a pending source-facing alias `dword_69B3A8 -> g_staticMemoryManObject`; `project-level/-resolved-multple-aliases.md` maps `dword_69B4FC` to `g_pMemoryMan` and `sub_516030` to `GetMemoryMan`.
- B-agent report leads: executed B001 report `executed-b-agent-research/B001/0001BA-memoryman-allocation-source-split.md`, executed B006 report `executed-b-agent-research/B006/0001B9-MemoryManConstructor-source-quality.md`, and active B007 report `tools/leaser/Agents/Agent-B007/research/0001BC-GetMemoryMan-source-quality.md`.

## Current MCP Session

IDA MCP was available and responsive. This report is not fallback-only.

- Endpoint: `http://127.0.0.1:13337/mcp`.
- Read-only listener/process check: `127.0.0.1:13337` was listening on PID `13684`; visible MCP/IDA-related processes included `idalib-mcp` PID `17084` and Python worker PID `26892`.
- `initialize` returned server `ida-pro-mcp` version `1.0.0`, protocol `2025-06-18`.
- `tools/list` showed the active schema with single-address `addr` calls for `decompile`/`disasm` and explicit `database` arguments.
- `idb_list` reported active session `80de0a67`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, backend `worker`, active worker PID `26892`, `is_analyzing:false`.
- A first local wrapper call to `server_health` omitted `database` after failing to parse the session id; MCP correctly returned `database is required`. This was a request-shape mistake, not an MCP outage. Reissued with `database=80de0a67`, `server_health` returned `status:ok`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, strings cache size `2067`.
- Read-only tools used: `lookup_funcs`, `decompile`, `disasm`, `get_bytes`, `xrefs_to`, `find_bytes`, `list_globals`, `entity_query`, `search_structs`, and `type_query`.

## Numeric Conversion Evidence

Conversions were checked from `E:\NTK\GhidraBridge` with `python .\source-3\project-documentation\tools\int_convert.py --pretty`.

- `0x11` = 17 bytes for the target destructor/reset tail. (Verified with `int_convert.py`.)
- `0x0a` = 10 bytes for the atexit thunk function at `0x0060c260`. (Verified with `int_convert.py`.)
- `0x0f` = 15 bytes for the constructor. (Verified with `int_convert.py`.)
- `0x2e` = 46 bytes for the scalar deleting destructor. (Verified with `int_convert.py`.)
- `0x16` = 22 bytes for the static initializer. (Verified with `int_convert.py`.)
- `0x00516010` little-endian bytes are `10 60 51 00`; `0x00516021` little-endian bytes are `21 60 51 00`. (Verified with `int_convert.py`.)
- `0x0060c260`, `0x0069b3a8`, `0x0069b4fc`, and `0x0061eb08` convert to little-endian bytes `60 c2 60 00`, `a8 b3 69 00`, `fc b4 69 00`, and `08 eb 61 00`. (Verified with `int_convert.py`.)

## MCP Evidence

### Function And Boundary Facts

`lookup_funcs(database=80de0a67)` reports:

| Query | Result |
| --- | --- |
| `0x00419f70` | function `sub_419F70`, size `0x16` / 22 bytes (Verified with `int_convert.py`) |
| `0x00419f86` | not a function |
| `0x00516000` | function `sub_516000`, size `0x0f` / 15 bytes (Verified with `int_convert.py`) |
| `0x0051600f` | not a function |
| `0x00516010` | resolves through non-contiguous modeled `sub_60C260`, size `0x0a` / 10-byte public thunk (Verified with `int_convert.py`) |
| `0x00516021` | not a function |
| `0x00516030` | function `sub_516030`, size `0x06` / 6 bytes |
| `0x00516036` | not a function |
| `0x00516260` | function `sub_516260`, size `0x2e` / 46 bytes (Verified with `int_convert.py`) |
| `0x0051628e` | not a function |
| `0x00516290` | successor function `sub_516290`, size `0xb5` / 181 bytes (Verified with `int_convert.py`) |
| `0x0060c260` | function `sub_60C260`, size `0x0a` / 10 bytes (Verified with `int_convert.py`) |
| `0x0060c26a`, `0x0061eb08`, `0x0069b3a8`, `0x0069b4fc` | not functions |

The target's source-bearing bytes are the tail chunk, not the public thunk. The target half-open range remains `0x00516010-0x00516021`: instructions at `0x00516010`, `0x00516016`, and `0x00516020`, followed by padding at `0x00516021`.

### Disassembly And Decompilation

`disasm 0x0060c260` reports the public atexit thunk:

- `0x0060c260`: `mov ecx, offset unk_69B3A8`
- `0x0060c265`: `jmp loc_516010`

`disasm 0x00516010` reports the thunk plus the non-contiguous tail chunk:

- `0x0060c260`: `mov ecx, offset unk_69B3A8`
- `0x0060c265`: `jmp loc_516010`
- `0x00516010`: `mov dword ptr [ecx], offset ??_7MemoryMan@@6B@`
- `0x00516016`: `mov dword ptr unk_69B4FC, 0`
- `0x00516020`: `retn`

`decompile 0x00516010` and `decompile 0x0060c260` both reduce the modeled function to:

- store `MemoryMan::vftable` into `unk_69B3A8`;
- clear `unk_69B4FC` to zero.

This confirms the binary action but also shows why source reconstruction must split the compiler thunk from the source destructor body. The vtable store is destructor lowering for the object at `this`; the handwritten source effect is the singleton clear.

`decompile 0x00419f70` confirms the paired static initializer:

- call `sub_516000(&unk_69B3A8)` at `0x00419f75`;
- register `atexit(sub_60C260)` at `0x00419f85`.

`decompile 0x00516000` confirms the constructor publishes `this` through `unk_69B4FC`; `decompile 0x00516030` confirms the accessor returns that same storage; `decompile 0x00516260` confirms the scalar deleting destructor restores the vtable, clears `unk_69B4FC`, conditionally calls the generic delete helper, and returns the object pointer.

### Bytes And Padding

`get_bytes 0x00516000 size 0x40` returns, in order:

- constructor bytes at `0x00516000-0x0051600f`;
- one `0xcc` byte at `0x0051600f`;
- destructor/reset tail bytes at `0x00516010-0x00516021`:
  `c7 01 08 eb 61 00 c7 05 fc b4 69 00 00 00 00 00 c3`;
- fifteen `0xcc` bytes from `0x00516021-0x00516030`;
- `GetMemoryMan` bytes `a1 fc b4 69 00 c3` at `0x00516030-0x00516036`;
- ten `0xcc` bytes after the accessor in the sampled window.

`get_bytes 0x0060c260 size 0x10` returns the thunk bytes `b9 a8 b3 69 00 e9 a6 9d f0 ff`, then six `0xcc` bytes.

`get_bytes 0x00419f70 size 0x20` returns the static-initializer bytes that load `0x0069b3a8`, call `0x00516000`, push `0x0060c260`, call `_atexit`, pop, return, and then alignment bytes.

`get_bytes 0x00516260 size 0x30` confirms the scalar deleting destructor's separate 46-byte body and two trailing `0xcc` bytes before `0x00516290`.

`get_bytes 0x0061eb04 size 0x10` returns the RTTI pointer before the vtable, the vtable slot pointer `0x00516260`, and the next vtable/RTTI-family data. `get_bytes 0x0069b3a8 size 4` and `get_bytes 0x0069b4fc size 4` both currently read `00 00 00 00` in the IDB view. The static object storage page currently says `ff ff ff ff`; implementation should either update that stale raw-data line to the current MCP byte evidence or explicitly preserve it only if a separate raw-file audit proves a different file-image value.

### Xrefs And Direct-Operand Routes

`xrefs_to(database=80de0a67)` reports:

- `0x00516010`: exactly one code xref, from `0x0060c265` inside `sub_60C260`.
- `0x0060c260`: exactly one xref, the static-initializer data ref at `0x00419f7a`.
- `0x0061eb08`: exactly three data refs, constructor `0x00516000`, ordinary destructor/reset tail `0x00516010`, and scalar deleting destructor `0x0051626a`.
- `0x0069b3a8`: exactly two data refs, static initializer `0x00419f70` and atexit thunk `0x0060c260`.
- `0x0069b4fc`: exactly four data refs, constructor write `0x00516008`, ordinary destructor/reset clear `0x00516016`, accessor read `0x00516030`, and scalar deleting destructor clear `0x00516270`.
- `0x00516260`: one data xref from the `MemoryMan` vtable slot at `0x0061eb08`.

`find_bytes` for little-endian operand patterns reinforces the xref picture:

- `10 60 51 00` and `21 60 51 00`: zero matches, so no data pointer route targets the destructor-tail start/end directly.
- `60 c2 60 00`: one match at `0x00419f7b`, the static initializer's atexit registration.
- `a8 b3 69 00`: two matches at `0x00419f71` and `0x0060c261`, the static object passed to constructor/destructor.
- `fc b4 69 00`: four matches at `0x0051600a`, `0x00516018`, `0x00516031`, and `0x00516272`, the constructor/destructor/accessor/scalar-deleting singleton routes.
- `08 eb 61 00`: three matches at `0x00516002`, `0x00516012`, and `0x0051626c`, the constructor/destructor/scalar-deleting vtable stores.

### Name And Type Negative Evidence

`list_globals *MemoryMan*` returns only the `MemoryMan` RTTI/vtable family, including `??_7MemoryMan@@6B@`, RTTI data, and the `.?AVMemoryMan@@` string. `list_globals *g_pMemoryMan*`, `*69B4FC*`, and `*69B3A8*` return no named data.

`entity_query` for `MemoryMan|GetMemoryMan|g_pMemoryMan|MemoryMan.cpp|Memory.cpp|MemoryUtil|516010|69B4FC|69B3A8` finds `MemoryMan` RTTI/vtable names and function names `sub_516260` / `sub_60C260`, but no recovered `GetMemoryMan`, `g_pMemoryMan`, source-file string, or static-object symbol.

`search_structs MemoryMan` returns no local struct. `type_query *MemoryMan*` returns zero type records.

Conclusion: `MemoryMan` as a class is strongly recovered from RTTI/vtable evidence. `g_pMemoryMan` and `g_staticMemoryManObject` are source-facing reconstruction names, not recovered source/PDB symbols. This caps confidence below final audit but does not block first-draft destructor C++ because the source behavior and owner route are direct IDA facts.

## Heuristic / Inference Reanalysis

### Ordinary Destructor / Reset Source Shape

Best source form: `MemoryMan::~MemoryMan()` with a single source-authored statement clearing `g_pMemoryMan`.

Evidence:

- The target is reached only after the atexit thunk loads the static object address as `ecx`, which is the MSVC `this` register.
- The target writes the `MemoryMan` vtable and clears the singleton pointer, exactly matching ordinary destructor lowering for a class with a source-level destructor body.
- Existing accepted destructor pages such as `KeySpeedMgr::~KeySpeedMgr`, `DescPane::~DescPane`, and `ChattingBackPane::~ChattingBackPane` use the same rule: vptr restores and base/destructor machinery are compiler output; the formal source block contains only the source-visible singleton clear.
- There is no compare against `this`, no guard, and no conditional route before clearing `0x0069b4fc`. Do not add `if (g_pMemoryMan == this)`.

Decision: formal target C++ should be exactly `MemoryMan::~MemoryMan() { g_pMemoryMan = 0; }`.

### Atexit Thunk Relationship

Best interpretation: [UID:0001O7] is compiler/static-lifetime glue generated from a source-declared file-scope `MemoryMan` object. It is not a source helper and not part of this target's formal code.

Evidence:

- The thunk has one registration xref from `_atexit` in [UID:0000WA].
- It loads `0x0069b3a8` as `this` and jumps to the ordinary destructor tail.
- [UID:0000WA] and [UID:0001O7] are already `RECONSTRUCTABLE:FALSE`, no-owner/no-emitter compiler/static-lifetime pages.

Decision: keep [UID:0000WA] and [UID:0001O7] no-code/non-reconstructable and document that they are regenerated from the source static object plus destructor. Do not paste their logic into [UID:0001BB].

### Static Object Declaration

Best current source-facing static-object name: `g_staticMemoryManObject`, from `project-level/-resolved.md`'s pending alias for `dword_69B3A8`. This name is not recovered from IDA; it is a project-level reconstructed name that should replace raw `dword_69B3A8` in source-facing prose while preserving the raw IDA label as evidence.

The exact static-object declaration is not needed inside [UID:0001BB]'s formal block. The target destructor uses `this`; the static initializer/atexit thunk supply the static object address in generated binary glue. The source-family docs should now state that the object is a file-scope static `MemoryMan` object in `MemoryMan.cpp`, named `g_staticMemoryManObject` for current reconstruction purposes, and that [UID:0000WA]/[UID:0001O7] are generated from that lifetime.

This resolves the static-object blocker for [UID:0001BB]. It remains a support-page confidence cap because no original static-object symbol was recovered, and because the static object storage page may need a separate formal declaration pass.

### `g_pMemoryMan` Name

Best current source-facing name: `g_pMemoryMan`.

Evidence:

- `project-level/-resolved-multple-aliases.md` maps `dword_69B4FC` to `g_pMemoryMan`.
- Every current IDA xref to `0x0069b4fc` belongs to the `MemoryMan` lifecycle/accessor quartet: constructor write, ordinary destructor clear, accessor read, scalar deleting destructor clear.
- Constructor [UID:0001B9] and accessor [UID:0001BC] already use `g_pMemoryMan` in accepted formal C++.

Decision: use `g_pMemoryMan` in [UID:0001BB] formal C++. The name remains inferred, not original-symbol proof, so confidence stays below final audit.

### Scalar Deleting Destructor Separation

Best interpretation: [UID:0001BJ] is the vtable-slot scalar deleting destructor/deleting wrapper. It duplicates the vtable reset and singleton clear and optionally frees the object when the deleting flag low bit is set.

Decision: do not merge [UID:0001BJ] into [UID:0001BB] and do not hand-write scalar deleting destructor code as source. After [UID:0001BB] gets formal destructor C++, [UID:0001BJ] should update its wording so blank C++ is justified by compiler wrapper/deleting-destructor handling, not by unresolved ordinary destructor source shape.

### Source File Placement

Best source route: direct semantic owner/emitter [UID:00007U] `MemoryMan`, surfacing through [UID:0000L7] `MemoryMan` / `NexusTK/util/MemoryMan.cpp`.

Evidence:

- The body is class lifecycle code: `ecx`/`this` object pointer, `MemoryMan` vtable store, singleton clear.
- [UID:00007U] owns the constructor, ordinary destructor, and scalar deleting destructor.
- [UID:0000L7] owns the source family and proposed path `NexusTK/util/MemoryMan.cpp`.
- The helper/accessor/allocation bodies remain file-level, not class-owned, matching B001/B006/B007 decisions.

Decision: keep owner/emitter unchanged for [UID:0001BB].

## Formal C++ Disposition

Eligible for first-draft C++: yes.

Gate:

- `RECONSTRUCTABLE:TRUE`.
- Nonblank emitter [UID:00007U], which reaches file root [UID:0000L7].
- Current average score `(86 + 90) / 2 = 88`, already above the active `>85` gate; recommended score becomes `90/92`.
- Body, boundary, source placement, dependency name, generated-wrapper exclusions, and rejected alternatives are documented.

Exact formal `RECONSTRUCTION_CPP CODE` insertion text for [UID:0001BB]:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
MemoryMan::~MemoryMan()
{
    g_pMemoryMan = 0;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Notes:

- Do not emit the vtable store. It is compiler-generated vptr restoration for the destructor.
- Do not emit the atexit thunk or static initializer logic. They are compiler/static-lifetime glue generated from the source-level static object.
- Do not emit a scalar deleting destructor wrapper here.
- Do not use raw labels such as `unk_69B4FC`, `dword_69B3A8`, `loc_516010`, or `sub_60C260`.
- `g_pMemoryMan = 0;` is the accepted exact target block. `NULL` would be binary-equivalent, but `0` matches the accepted nearby `KeySpeedMgr` singleton-clear precedent and keeps this block simple and era-plausible.

## Rejected Alternatives And Negative Evidence

- Keep formal C++ blank because the static object name is unrecovered: rejected. The target body does not name the static object; it receives `this`.
- Use `MemoryManGlobalResetTail` / file-level reset helper: rejected. B001 already renamed/rerouted this item, and current MCP shows the thunk passes a `MemoryMan` object as `this`.
- Hand-write the vtable assignment: rejected. The vptr store is compiler destructor lowering from the class declaration.
- Hand-write the atexit thunk: rejected. [UID:0001O7] is compiler/static-lifetime glue with one registration xref.
- Merge scalar deleting destructor logic into this target: rejected. [UID:0001BJ] has the deleting flag parameter and optional free path; it remains separate.
- Add `if (g_pMemoryMan == this)`: rejected. No compare exists in the ordinary destructor or scalar deleting destructor; the binary unconditionally clears.
- Use raw decompiler names (`unk_69B4FC`, `unk_69B3A8`, `sub_60C260`) in source: rejected. Current project aliases and lifecycle evidence support `g_pMemoryMan`, `g_staticMemoryManObject` in support prose, and `MemoryMan::~MemoryMan()`.
- Reroute directly to [UID:0000L7]: rejected as direct ownership. [UID:0000L7] remains the source file route, but this is class lifecycle code owned by [UID:00007U].
- Treat `0x00516010` as a standalone normal IDA function: rejected. Current `lookup_funcs` resolves it through the non-contiguous `sub_60C260` thunk model; documentation should preserve the chunk/source-body distinction.

## Score And Metadata Recommendation

Current target metadata:

- `COMPLETION:86`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:00007U`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00007U`
- blank formal C++

Recommended target metadata:

- `COMPLETION:90`
- `CONFIDENCE:92`
- keep `CANONICAL_OWNER:00007U`
- keep `RECONSTRUCTABLE:TRUE`
- keep `EMITTER_UIDS:00007U`
- keep blank `EMITTER_POSITION_OPTIONAL`
- add formal destructor C++

Rationale:

- Completion rises because the target will no longer have blank formal C++, and the page can carry current MCP session proof, exact 17-byte target body, padding, xrefs, static object/thunk relationship, source-authored singleton clear, source-file route, `g_pMemoryMan` name decision, rejected alternatives, and scalar-deleting separation.
- Confidence rises because the range, behavior, singleton storage, class owner/emitter route, static initializer/atexit relationship, and support-page consistency are directly verified in the active IDB. It stays below final audit because no recovered source symbol proves the exact `g_pMemoryMan` or static object spelling, no local `MemoryMan` UDT/type record exists, and broader MemoryMan header/global-operator/copy-wrapper factoring remains outside this target.

## Recommended Target Doc Changes

Target path: `by-memory/0x00516010-0x00516021.MemoryManDestructor.md`

Required target changes if accepted:

- Set `COMPLETION:90`, `CONFIDENCE:92`; preserve owner/emitter/reconstructable metadata and `Nested:0`.
- Insert the exact formal C++ block from this report.
- Update `Item Summary` to say the ordinary destructor source body is now accepted, while vptr reset and atexit thunk are compiler/static-lifetime effects.
- Replace the stale "C++ remains blank" note with the current disposition: source body is `g_pMemoryMan = 0;`; vptr restore is compiler lowering; static object/atexit thunk and scalar deleting destructor are separate pages.
- Add current MCP session `80de0a67` evidence: health, `lookup_funcs`, `disasm`, `decompile`, `get_bytes`, `xrefs_to`, `find_bytes`, and negative symbol/type checks.
- Preserve exact range and padding: 17 target bytes at `0x00516010-0x00516021`, fifteen `0xcc` bytes at `0x00516021-0x00516030`.
- Preserve rejected alternatives and negative evidence from this report.

Recommended target `Item Summary`:

`Source-ready ordinary MemoryMan destructor: compiler vptr restore plus source-authored g_pMemoryMan clear reached from the static-object atexit thunk; formal destructor C++ now accepted.`

## Recommended Support Doc Changes

### `by-class/MemoryMan.md`

- Keep metadata unchanged unless implementation discovers a contradiction.
- Update the method map row for [UID:0001BB] to say it is a reconstructable child with formal destructor C++.
- Add a B009 source-quality note with current MCP facts: target tail body, `g_pMemoryMan` clear, vtable reset as compiler lowering, atexit thunk relationship, scalar deleting destructor separation, no local UDT/type record, and source route through `MemoryMan.cpp`.
- Preserve blank class-level formal C++ as a class/header declaration factoring issue, not a blocker for the exact destructor child.

### `by-file/MemoryMan.md`

- Keep `COMPLETION:89`, `CONFIDENCE:86`, proposed path `NexusTK/util/`, and `CANONICAL_OWNER:FILE`.
- Update proposed contents/generation caveats to say [UID:0001BB] now emits formal ordinary destructor C++ on the child page, alongside [UID:0001B9] constructor and [UID:0001BC] accessor readiness.
- State that `MemoryMan.cpp` should describe the file-scope static `MemoryMan` object with source-facing name `g_staticMemoryManObject` for current docs, while [UID:0000WA] and [UID:0001O7] remain generated from static lifetime.
- Preserve broader global operator/copy-wrapper/header/static-object declaration confidence caps as file-level issues, not target C++ blockers.

### `by-global/g_pMemoryMan.md`

- Keep metadata and blank formal global C++ unchanged.
- Add current B009 proof that [UID:0001BB] clears `0x0069b4fc` at `0x00516016`, and that `xrefs_to 0x0069b4fc` remains exactly constructor write, ordinary destructor clear, accessor read, and scalar deleting destructor clear.
- State that `g_pMemoryMan` is accepted for [UID:0001BB]'s formal destructor C++ even though IDA still has no recovered global symbol.

### `by-type/by-struct/MemoryManLayout.md`

- Keep metadata and blank layout C++ unchanged.
- Add current B009 proof that the ordinary destructor writes only the vptr at `+0x00` and clears `g_pMemoryMan`; it adds no allocation-policy fields and does not change the one-vptr binary layout.
- Update any wording that says ordinary destructor source shape remains unresolved.

### `by-memory/0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md`

- Keep parent `RECONSTRUCTABLE:FALSE`, blank emitter, and split-index status.
- Update the [UID:0001BB] covered-range row/final-C++ exclusion text to say the exact destructor child now carries formal source C++, while the parent remains no-code because exact children own source.

### `by-memory/0x00419f70-0x00419f86.MemoryManStaticInitializer.md`

- Keep `RECONSTRUCTABLE:FALSE`, no owner/emitter, and blank formal C++.
- Add current B009 proof only if the page lacks it: the initializer constructs the file-scope static `MemoryMan` object now named `g_staticMemoryManObject` in source-facing docs and registers [UID:0001O7] through `_atexit`.
- Preserve standalone-source exclusion.

### `by-memory/0x0060c260-0x0060c26a.MemoryManAtexitResetThunk.md`

- Keep `RECONSTRUCTABLE:FALSE`, no owner/emitter, and blank formal C++.
- Add current B009 proof that it loads `g_staticMemoryManObject`/`0x0069b3a8` into `ecx`, jumps to [UID:0001BB], has one registration xref from `0x00419f7a`, and should not be hand-written.

### `by-memory/0x0069b3a8-0x0069b3ac.MemoryManStaticObjectStorage.md`

- Keep owner/emitter [UID:0000L7], reconstructable state, and blank formal C++ unless the supervisor explicitly accepts a separate storage-declaration code pass.
- Replace or annotate raw `dword_69B3A8` prose with source-facing `g_staticMemoryManObject` while keeping raw IDA labels searchable.
- Reconcile stale raw data: current MCP `get_bytes` reads `00 00 00 00`; the page currently says `ff ff ff ff`. If implementation has no stronger raw-file evidence, update the raw-data line to current MCP bytes and note that the static initializer writes the vptr at runtime.

### `by-memory/0x0069b4fc-0x0069b500.g_pMemoryMan.md`

- No route/score/C++ change required.
- Check that the page already records the destructor clear at `0x00516016`; if not, add the current B009 xref proof and current zero bytes. If it already carries same-or-greater detail, record no-edit proof during implementation.

### `by-memory/0x00516260-0x0051628e.MemoryManScalarDeletingDestructor.md`

- Keep owner/emitter [UID:00007U] and metadata unless implementation discovers a direct contradiction.
- Update reconstruction notes so blank formal C++ is justified by scalar deleting destructor/compiler wrapper separation, not by unresolved ordinary destructor source shape.
- Do not merge its optional delete-flag path into [UID:0001BB].

## Manual Coverage / Tracker Text

None. Do not manually edit `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, `by-memory/-coverage-report.md`, project-level generated files, validator state, or any `-coverage-report.md`.

Generated state is currently stale for old `MemoryManGlobalResetTail` rows. After accepted implementation, run scoped validators on edited source docs. The supervisor can then execute this report through validator lifecycle. If stale missing old-path rows persist, use documented validator cleanup/rescan commands; do not hand-edit generated files.

## Validator Results

Report-only pass: no validators were run because no by-* docs were edited.

Implementation callback validators run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

| File | command_id | command_timestamp | exit | ok | warnings | generated_refresh |
| --- | --- | --- | ---: | ---: | --- | --- |
| `by-memory\0x00516010-0x00516021.MemoryManDestructor.md` | `000000003012` | `2026-06-26T17:06:10-04:00` | 0 | 1 | `missing_ref_target:141`, `missing_ref_uid:12` from existing coverage/reference state | `deferred` (`000000003012`, same timestamp) |
| `by-class\MemoryMan.md` | `000000003013` | `2026-06-26T17:06:36-04:00` | 0 | 1 | `missing_ref_uid:1` | `deferred` (`000000003013`, same timestamp) |
| `by-file\MemoryMan.md` | `000000003014` | `2026-06-26T17:06:38-04:00` | 0 | 1 | `missing_ref_uid:3` | `deferred` (`000000003014`, same timestamp) |
| `by-global\g_pMemoryMan.md` | `000000003015` | `2026-06-26T17:06:40-04:00` | 0 | 1 | `missing_ref_uid:1` | `deferred` (`000000003015`, same timestamp) |
| `by-type\by-struct\MemoryManLayout.md` | `000000003017` | `2026-06-26T17:06:47-04:00` | 0 | 1 | `missing_ref_uid:2` | `deferred` (`000000003017`, same timestamp) |
| `by-memory\0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md` | `000000003018` | `2026-06-26T17:06:48-04:00` | 0 | 1 | `missing_ref_uid:5` | `deferred` (`000000003018`, same timestamp) |
| `by-memory\0x00419f70-0x00419f86.MemoryManStaticInitializer.md` | `000000003019` | `2026-06-26T17:06:54-04:00` | 0 | 1 | none reported | `deferred` (`000000003019`, same timestamp) |
| `by-memory\0x0060c260-0x0060c26a.MemoryManAtexitResetThunk.md` | `000000003021` | `2026-06-26T17:07:00-04:00` | 0 | 1 | none reported | `deferred` (`000000003021`, same timestamp) |
| `by-memory\0x0069b3a8-0x0069b3ac.MemoryManStaticObjectStorage.md` | `000000003022` | `2026-06-26T17:07:02-04:00` | 0 | 1 | none reported | `deferred` (`000000003022`, same timestamp) |
| `by-memory\0x00516260-0x0051628e.MemoryManScalarDeletingDestructor.md` | `000000003023` | `2026-06-26T17:07:03-04:00` | 0 | 1 | none reported | `deferred` (`000000003023`, same timestamp) |

Generated-header freshness: no generated output was used for implementation. Validator-owned generated refresh was deferred for every scoped command; no manual generated report, coverage report, validator state, tool state, or IDA DB edits were made.

## Changed Files

- Created by B009: `tools/leaser/Agents/Agent-B009/research/0001BB-MemoryManDestructor-source-quality.md`
- Modified by implementation: `by-memory/0x00516010-0x00516021.MemoryManDestructor.md`, `by-class/MemoryMan.md`, `by-file/MemoryMan.md`, `by-global/g_pMemoryMan.md`, `by-type/by-struct/MemoryManLayout.md`, `by-memory/0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md`, `by-memory/0x00419f70-0x00419f86.MemoryManStaticInitializer.md`, `by-memory/0x0060c260-0x0060c26a.MemoryManAtexitResetThunk.md`, `by-memory/0x0069b3a8-0x0069b3ac.MemoryManStaticObjectStorage.md`, and `by-memory/0x00516260-0x0051628e.MemoryManScalarDeletingDestructor.md`.
- Conditional no-edit proof: `by-memory/0x0069b4fc-0x0069b500.g_pMemoryMan.md` already records the destructor clear at `0x00516016` and the constructor write / destructor clear / accessor read / scalar deleting destructor clear xref quartet at same-or-greater detail; no edit was needed.
- Leases acquired: initial B009 lease batch succeeded for the ten edited by-* files; it expired during the long edit pass, then a renewed batch succeeded before validators. Final `unlease` command succeeded for all ten edited by-* files.
- IDA DB edits: none.

## Implementation Tracking Checklist

Initial report-only pass and implementation callback:

- [x] Supervisor validation required before implementation. Proof: supervisor accepted this report and assigned implementation callback in `goal.md`.
- [x] Target doc updated: `by-memory/0x00516010-0x00516021.MemoryManDestructor.md` now has `COMPLETION:90`, `CONFIDENCE:92`, owner/emitter [UID:00007U], current MCP evidence, source-form decision, rejected alternatives, score rationale, and exact formal C++ block.
- [x] Target formal C++ applied exactly: `MemoryMan::~MemoryMan()` body contains only `g_pMemoryMan = 0;` in the formal `RECONSTRUCTION_CPP CODE` block.
- [x] Target range/padding facts incorporated: target body `0x00516010-0x00516021`, `0x11` / 17 bytes (Verified with `int_convert.py`), `retn` at `0x00516020`, fifteen `0xcc` bytes at `0x00516021-0x00516030`, and no function at `0x00516021`.
- [x] Target xref facts incorporated: one code xref to `0x00516010` from `0x0060c265`, one atexit registration xref to `0x0060c260` from `0x00419f7a`, vtable/static-object/global operand refs, and the four `g_pMemoryMan` lifecycle refs.
- [x] Target source-form facts incorporated: vptr store documented as compiler destructor lowering; atexit thunk documented as generated static-lifetime glue; scalar deleting destructor documented as separate; no guard/compare added around the singleton clear.
- [x] `by-class/MemoryMan.md` updated. Proof: method map now marks [UID:0001BB] as reconstructable child with formal destructor C++; B009 section records ordinary destructor source body, atexit relationship, vptr lowering, scalar deleting separation, negative type/symbol evidence, and blank class-level C++ caveat.
- [x] `by-file/MemoryMan.md` updated. Proof: proposed contents/generation caveats/source-structure decision now state [UID:0001BB] emits formal child C++, source route remains `MemoryMan.cpp`, `g_staticMemoryManObject` is the source-facing static object name, and broader file-level caps remain.
- [x] `by-global/g_pMemoryMan.md` updated. Proof: B009 evidence records destructor clear at `0x00516016`, the exact lifecycle xref quartet, current zero bytes, and the inferred-name caveat while preserving blank formal global C++.
- [x] `by-type/by-struct/MemoryManLayout.md` updated. Proof: B009 layout check records that the ordinary destructor writes only vptr `+0x00` and clears `g_pMemoryMan`, adding no observed fields.
- [x] `by-memory/0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md` updated. Proof: [UID:0001BB] row and B009 sync now mark the exact child source-ready while preserving parent `RECONSTRUCTABLE:FALSE` split-index status.
- [x] `by-memory/0x00419f70-0x00419f86.MemoryManStaticInitializer.md` updated. Proof: retains non-reconstructable compiler/static initializer handling and records source-facing `g_staticMemoryManObject` plus B009 construction/`atexit` evidence.
- [x] `by-memory/0x0060c260-0x0060c26a.MemoryManAtexitResetThunk.md` updated. Proof: retains non-reconstructable thunk handling and records source-facing `g_staticMemoryManObject` load plus jump-to-[UID:0001BB] proof.
- [x] `by-memory/0x0069b3a8-0x0069b3ac.MemoryManStaticObjectStorage.md` updated. Proof: raw `dword_69B3A8` prose now includes source-facing `g_staticMemoryManObject`; stale `ff ff ff ff` raw data is reconciled to current MCP `00 00 00 00`.
- [x] `by-memory/0x0069b4fc-0x0069b500.g_pMemoryMan.md` no-edit proof recorded. Proof: page already records destructor clear at `0x00516016` and the constructor write / destructor clear / accessor read / scalar deleting destructor clear quartet at same-or-greater detail.
- [x] `by-memory/0x00516260-0x0051628e.MemoryManScalarDeletingDestructor.md` updated. Proof: blank-C++ rationale is now compiler wrapper/deleting-destructor separation; ordinary destructor source shape is no longer unresolved.
- [x] Metadata/score changes applied. Proof: only [UID:0001BB] target score changed to `90/92`; support-page scores stayed unchanged.
- [x] Owner/emitter/reconstructable changes applied. Proof: no ownership/reconstructable route changes; target remains `CANONICAL_OWNER:00007U`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007U`.
- [x] Split/rename/new-child changes applied. Proof: none needed; exact target path/range and existing B001 split were preserved.
- [x] Source-placement and IDA rename/type/comment disposition applied. Proof: source-facing names were documented in docs only; no IDA DB rename/type/comment edits were made.
- [x] Historical/stale assumptions and rejected alternatives preserved. Proof: old blank-C++ blocker superseded; `MemoryManGlobalResetTail`, file-level helper ownership, handwritten vtable store, handwritten atexit thunk, scalar deleting merge, raw decompiler names, and guarded singleton clear remain explicitly rejected.
- [x] Open questions documented. Proof: exact original spelling of `g_pMemoryMan` and `g_staticMemoryManObject` remains unrecovered and caps confidence below final audit, but no longer blocks target C++.
- [x] Validators run after accepted implementation. Proof: ten scoped validator commands listed in `Validator Results`, all exit `0` with `ok:1`, command IDs/timestamps/warnings/generated-refresh state recorded.
- [x] Generated report refresh expectation handled. Proof: validator-owned generated refresh was `deferred` for all scoped commands; no manual generated report, manual coverage report, validator/tool state, or IDA DB edits were made. Existing missing-ref warnings remain validator/supervisor lifecycle state.
- [x] Report accepted by supervisor for implementation. Proof: implementation callback present in `goal.md`.
- [x] All accepted target/support doc details incorporated at report-level detail. Proof: target and ten support/no-edit items above are accounted for.
- [x] Metadata/score/C++ changes applied or explicitly not applied with reason. Proof: target C++/score changed; support C++/scores preserved with documented rationale.
- [x] Conditional no-edit proofs recorded for support pages not modified. Proof: `by-memory/0x0069b4fc-0x0069b500.g_pMemoryMan.md` no-edit proof recorded above.
- [x] Leases acquired only for immediate edit/validator batch and released immediately afterward. Proof: initial lease batch succeeded, renewal succeeded before validators after expiry, and final `unlease` succeeded for all ten edited by-* files.
- [x] Remaining unapplied accepted items listed with exact blocker, if any. Proof: none remain unapplied.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000004165","destination_path":"executed-b-agent-research/B009/0001BB-MemoryManDestructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/0001BB-MemoryManDestructor-source-quality.md","timestamp":"2026-06-26T17:12:10","uid":"0001BB"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
