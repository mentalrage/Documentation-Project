** TARGET-REPORT-UID:0000LJ **
** AUTHOR-AGENT-ID:B011 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B011 Source-Quality Report: [UID:0000LJ] MonsterImageLib Empty-Emitter Family

Assignment ID: `B011-report-0000LJ-MonsterImageLib-empty-emitter-family-20260630`  
Agent: `Agent-B011`  
Mode: accepted report implemented in callback after initial report-only research  
Target: `by-file/MonsterImageLib.md`  
Generated output reviewed: `auto-generated/NexusTK/render/MonsterImageLib.cpp`  
Report path: `tools/leaser/Agents/Agent-B011/research/0000LJ-MonsterImageLib-empty-emitter-family-source-quality.md`

## Report And Callback Status

Initial report-only research edited no by-* documentation files, took no leases, and spawned no subagents. The accepted implementation callback then applied the report details to the listed by-* target/support docs under immediate edit leases, released all leases, and ran the scoped validators recorded below. B011 did not manually edit generated files, coverage reports, validator/tool state, IDA database files, supervisor ledgers, archives, or lock files; validator-owned generated/tool updates are listed in the callback results.

MCP was available and used. This report is not fallback-only.

## Executive Recommendation

`MonsterImageLib.cpp` currently has 17 emitted markers, 2 filled markers, and 15 empty markers. The two already filled markers are the accepted `MonsterImageLib::LoadMonsterTables` body (`[UID:0002JN]`) and the ordinary destructor (`[UID:00017D]`). The remaining empty family is not one uniform problem: it contains source structs/globals that should emit declarations, compiler-generated ABI pages that should emit formal no-code markers, a singleton clear helper that should emit a small source helper, and one by-item alias that should stop participating as a reconstructable emitter.

Recommended root score after implementation: `COMPLETION:89`, `CONFIDENCE:89` for `by-file/MonsterImageLib.md`. This is a meaningful score raise because every current empty emitter has an implementation-ready disposition, but it should not be raised to 90+ yet because important source bodies and class API surfaces still remain outside this pass: constructor source normalization, `LoadMonsterArchives`, `ClearLoadedData`, render/accessor methods, DATIndexVector ownership, and a full source-quality class declaration.

Primary disposition: keep `[UID:0000LJ]` as the file owner and route/source declarations through the existing family. Do not import the related `[UID:0001CM] MonsterImageLibTables` report as a duplicate direct answer; use it only as support for the shared animation table helper declarations already generated in `MonsterImageLibTables.cpp`.

## Current Generated State

Reviewed generated file:

- `auto-generated/NexusTK/render/MonsterImageLib.cpp`
- Header says `validator-command-id: 000000002929`
- Header says `refreshed: 2026-06-30T14:34:45-04:00`
- Filled markers: `[UID:0002JN] MonsterImageLibLoadMonsterTables`, `[UID:00017D] MonsterImageLibDestructor`
- Empty markers: `[UID:00008N]`, `[UID:00017E]`, `[UID:0003M1]`, `[UID:0001VA]`, `[UID:0001VB]`, `[UID:0001VC]`, `[UID:0001VD]`, `[UID:0001Y7]`, `[UID:0002MM]`, `[UID:0000RR]`, `[UID:0001PN]`, `[UID:0000VK]`, `[UID:0002VF]`, `[UID:000181]`, `[UID:00029K]`

The companion generated helper file `auto-generated/NexusTK/render/MonsterImageLibTables.cpp` was reviewed only as support. Its header says `validator-command-id: 000000002930` and `refreshed: 2026-06-30T14:37:30-04:00`. It already emits the accepted table helper declarations/bodies from `[UID:0001CM]`, including `ImageAnimationFrame`, `ImageAnimationGroup`, and `ImageAnimationTable`. This report does not duplicate that executed report.

## Documents Reviewed

Target and direct support:

- `by-file/MonsterImageLib.md`
- `by-class/MonsterImageLib.md`
- `by-memory/0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket.md`
- `by-memory/0x004e6750-0x004e6860.MonsterImageLibScalarDeletingDestructor.md`
- `by-memory/0x004e5990-0x004e5a62.VectorGrowArchiveIndex.md`
- `by-memory/0x004e5bd0-0x004e5bdb.MonsterImageLibSingletonClearHelper.md`
- `by-item/VectorGrowArchiveIndex_004E5990.md`
- `by-global/g_pMonsterImageLib.md`
- `by-memory/0x0069b440-0x0069b444.g_pMonsterImageLib.md`
- `by-memory/0x0069b424-0x0069b430.ImageLibraryFallbackRecord.md`

Type, vtable, and table support:

- `by-type/by-struct/MonsterArchiveBoundsBucket.md`
- `by-type/by-struct/MonsterArchiveBoundsEntry.md`
- `by-type/by-struct/MonsterImageEntry.md`
- `by-type/by-struct/MonsterImageLibLayout.md`
- `by-type/by-vtable/MonsterImageLibVtable.md`
- `by-memory/0x0061b6e0-0x0061b6f0.MonsterImageLibVtableData.md`
- `by-file/MonsterImageLibTables.md`
- `by-memory/0x00528930-0x00528d51.MonsterImageLibTables.md`
- `by-memory/0x004dac40-0x004dc420.MonsterImageLibLocalMethodCluster.md`
- `by-memory/0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables.md`
- `by-class/MonsterImageLibTable_5289D0.md`
- `by-class/MonsterImageLibTable_528BE0.md`

Prior reports used as leads, not as replacement output:

- `executed-b-agent-research/B007/0001CM-MonsterImageLibTables-empty-emitter-source-quality.md`
- `executed-b-agent-research/B003/00017E-MonsterImageLibGetArchiveBoundsBucket-source-quality.md`
- `executed-b-agent-research/B002/0003M1-MonsterImageLibScalarDeletingDestructor.md`
- `executed-b-agent-research/B011/00017D-MonsterImageLibDestructor-source-quality.md`

## MCP Evidence

MCP session state:

- JSON-RPC initialize call: id `101`
- JSON-RPC tools/list call: id `102`
- `idb_list`: id `103`
- Active IDB session: `supervisor_resume_20260629`
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Worker PID: `24256`
- Last accessed: `2026-06-30T14:32:16.948991`
- `server_health`: id `104`, `status: ok`, module `NexusTK.exe`, input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready: true`, `hexrays_ready: true`, `strings_cache_ready: true`, strings cache count `2067`

Function boundary evidence:

- `lookup_funcs` id `105`
- `0x004daec0`: function, size `0x14e`
- `0x004dac40`: function, size `0x27d`
- `0x004dbc60`: function, size `0x19b`
- `0x004dbe60`: function, size `0x315`
- `0x004dc240`: no function
- `0x004dc2e0`: function, size `0x135`
- `0x004e5990`: function, size `0xd2`
- `0x004e5a62`: no function
- `0x004e5bd0`: function, size `0xb`
- `0x004e5bdb`: no function
- `0x004e6750`: function, size `0x110`
- `0x004e6860`: no function
- `0x004f4b10`: function, size `0x6`
- `0x0041b6c0`: `nullsub_18`, size `0x3`
- `0x00528930`: function, size `0x17`
- `0x00528d51`: no function

Key xref evidence:

- `xrefs_to` id `108`
- `0x004dbe60`: callers at `0x004db647`, `0x004dc1b9`, and raw local call `0x004dc279`
- `0x004e5990`: one caller at `0x004dbd8f` inside `sub_4DBC60`
- `0x004e5bd0`: one cleanup-table xref at `0x005ffd87` from constructor setup
- `0x004e6750`: vtable data xref at `0x0061b6e4`
- `0x0061b6e4`: refs at `0x004daf16`, `0x004db036`, `0x004e677d`
- `0x0069b440`: 22 refs, including constructor writes at `0x004daef7`/`0x004daefe`, destructor/scalar cleanup paths, singleton clear helper, shutdown/cache-clear consumers, and render/UI consumers
- `0x0069b424`: refs at `0x00419fb0`, `0x004dacfe`, `0x004db33d`, `0x0060c280`
- `0x0069b42c`: refs at `0x004dad20`, `0x004dad30`, `0x004dad3d`, `0x004dad49`
- `0x0069b428`: no direct xrefs

Byte and scalar storage evidence:

- `get_bytes` id `110`
- `0x0069b420` size `28`: all zero bytes in the current IDB/PE image view
- `0x0061b6e0`: dwords decode as RTTI pointer `0x00648c14`, scalar deleting destructor `0x004e6750`, virtual slot `0x004f4b10`, virtual slot `0x0041b6c0`, then adjacent RidingImageLib RTTI/vtable data beginning at `0x0061b6f0`
- `0x004e5bd0`: bytes `c7 05 40 b4 69 00 00 00 00 00 c3`, then `int3` padding
- `0x004e5a62`: `int3` padding; no function at the exact end address
- `0x004e6860`: `int3` padding; no function at the exact end address
- `get_int` id `111`
- `0x0061b6e0`: `0x00648c14`
- `0x0061b6e4`: `0x004e6750`
- `0x0061b6e8`: `0x004f4b10`
- `0x0061b6ec`: `0x0041b6c0`
- `0x0069b424`: `0`
- `0x0069b428`: `0`
- `0x0069b42c`: `0`
- `0x0069b440`: `0`

Function analysis evidence:

- `analyze_function` ids `112` through `118`
- Constructor `0x004daec0`: size `0x14e`; caller `sub_4F5FB0`; calls base constructor, sets singleton storage, installs vtable, initializes archive/bounds vectors, calls `LoadMonsterTables`, then calls `LoadMonsterArchives`
- `LoadMonsterTables` `0x004dac40`: size `0x27d`; confirms use of `g_defaultMonsterAnimationTable` storage at `0x0069b424`/`0x0069b42c`, helper call `sub_5289D0(..., 0x15)`, seed frame duration `30000`, alpha `0`
- `LoadMonsterArchives` `0x004dbc60`: size `0x19b`; caller constructor; calls `sub_4E5990`; decompile shows fast append or slow grow/insert through a 4-byte archive offset vector
- `GetArchiveBoundsBucket` `0x004dbe60`: size `0x315`; confirms `this + 0x3c` cache, `DATA/MON%d.DAT` formatting, open archive cache at `this + 0x1c`, bucket allocation, payload pointer rebasing, and cache reuse
- `VectorGrowArchiveIndex` `0x004e5990`: size `0xd2`; one caller; confirms 4-byte entry grow/insert, length guard `0x3fffffff`, growth `capacity + capacity/2`, allocation, prefix/suffix `memmove`, storage replacement helper `0x004e6df0`
- `MonsterImageLibSingletonClearHelper` `0x004e5bd0`: size `0xb`; decompiles to assigning zero to `0x0069b440`; no callees
- `ScalarDeletingDestructor` `0x004e6750`: size `0x110`; sets vtable, calls `ClearLoadedData`, destroys MonsterImageLib owned vectors, calls base destructor, clears singleton storage, optionally deletes memory

Additional lookup/xref evidence:

- `lookup_funcs` id `120`
- `0x004db100`, `0x004db330`, `0x004db3b0`, `0x004db5c0`, and `0x004db8b0` are additional MonsterImageLib methods in the local cluster
- Static wrappers around the default animation table exist at `0x00419fb0` and `0x0060c280`
- Helper functions around `0x00528930`, `0x005289d0`, and `0x00528be0` are shared table helper routines already addressed by the executed `[UID:0001CM]` report

## Empty-Emitter Disposition Matrix

| UID | Current doc | Current role | Recommended implementation disposition |
| --- | --- | --- | --- |
| `00008N` | `by-class/MonsterImageLib.md` | Class owner marker | Emit a source-disposition marker plus `[[CHILDREN]]`; do not invent a full class declaration in this pass |
| `00017E` | `GetArchiveBoundsBucket` | Real method, no source-quality standalone body yet | Emit formal no-code comment preserving lazy DAT bounds-cache proof |
| `0003M1` | Scalar deleting destructor | Compiler-generated ABI thunk | Emit formal no-code comment pointing to ordinary destructor and vtable |
| `0001VA` | `MonsterArchiveBoundsBucket` | Concrete source-facing POD row | Emit struct declaration |
| `0001VB` | `MonsterArchiveBoundsEntry` | Concrete source-facing POD row | Emit struct declaration |
| `0001VC` | `MonsterImageEntry` | Concrete monster table row | Emit struct declaration with declarations for helper methods used by accepted loader source |
| `0001VD` | `MonsterImageLibLayout` | Evidence-only layout page | Emit formal no-code comment; do not duplicate class ABI struct |
| `0001Y7` | `MonsterImageLibVtable` | Compiler-generated class ABI table | Emit formal no-code comment plus `[[CHILDREN]]` |
| `0002MM` | Vtable data range | Exact `.rdata` range under vtable | Emit formal no-code comment covered by class/vtable |
| `0000RR` | `g_pMonsterImageLib` | Source global/singleton pointer | Emit single file-local pointer definition initialized to `NULL` |
| `0001PN` | exact storage `0x0069b440` | Storage child of singleton global | Correct stale initializer note to zero-filled storage and emit formal no-code comment covered by `0000RR` |
| `0000VK` | by-item vector grow alias | Duplicate/index alias | Mark non-reconstructable alias; clear emitter linkage and do not emit source |
| `0002VF` | `VectorGrowArchiveIndex` | Compiler-lowered vector grow path | Emit formal no-code comment; source belongs in `LoadMonsterArchives` when that method is reconstructed |
| `000181` | singleton clear helper | Tiny file-local cleanup helper | Emit `static void ClearMonsterImageLibSingleton()` body |
| `00029K` | default animation/fallback table | Source static object | Emit `static ImageAnimationTable g_defaultMonsterAnimationTable;` and correct zero-fill evidence |

## Per-UID Implementation Details

### [UID:0000LJ] `by-file/MonsterImageLib.md`

Recommended metadata:

- `COMPLETION:89`
- `CONFIDENCE:89`
- Keep `CANONICAL_OWNER:FILE`
- Keep `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/"`
- Keep source ownership over the MonsterImageLib family, but add a 2026-06-30 B011 disposition section that explicitly accounts for all 15 empty emitters.

Required content update:

- Record that `MonsterImageLib.cpp` is not blocked by unknown ownership for the current empty family.
- Record that `[UID:0002JN]` and `[UID:00017D]` are already represented by accepted source bodies.
- Record that the remaining empty markers are resolved by the dispositions in this report: formal no-code markers, formal struct/global declarations, one singleton clear helper body, and one non-reconstructable by-item alias.
- Record current MCP correction that default storage around `0x0069b424` and singleton storage at `0x0069b440` are zero-filled in the current IDB/PE image, not explicit `0xffffffff` bytes.

Do not add a broad implementation body for the entire file.

### [UID:00008N] `by-class/MonsterImageLib.md`

Recommended metadata:

- `COMPLETION:89`
- `CONFIDENCE:90`
- Keep `CANONICAL_OWNER:0000LJ`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:0000LJ`

Class audit:

- Constructor route: exact function `0x004daec0`, size `0x14e`; called by singleton/initializer wrapper `sub_4F5FB0`; initializes base `LObject`, writes `g_pMonsterImageLib`, installs vtable at `0x0061b6e4`, zeroes/initializes owned vectors, calls `LoadMonsterTables`, then `LoadMonsterArchives`.
- Destructor route: ordinary destructor `[UID:00017D]` is already emitted; scalar deleting destructor `[UID:0003M1]` is compiler-generated and should not be represented as an authored body.
- Vtable slots: RTTI pointer `0x00648c14`; slot 0 `0x004e6750` scalar deleting destructor; slot 1 `0x004f4b10`; slot 2 `0x0041b6c0`/`nullsub_18`. The exact vtable bytes belong to generated class ABI output, not a hand-authored source table.
- Method inventory checked: constructor `0x004daec0`, `LoadMonsterTables` `0x004dac40`, `LoadMonsterArchives` `0x004dbc60`, `GetArchiveBoundsBucket` `0x004dbe60`, `ClearLoadedData` `0x004dc2e0`, render/accessor local methods at `0x004db100`, `0x004db330`, `0x004db3b0`, `0x004db5c0`, `0x004db8b0`, destructor/scalar destructor, and singleton clear helper.
- Fields/offsets checked: vptr/base at `+0x00`; `m_monsters` pointer at `+0x04`; `m_monsterCount` at `+0x08`; unresolved/reserved word at `+0x0c`; archive offset vector at `+0x10/+0x14/+0x18`; open archive index/cache vector at `+0x1c` through its vector state; bounds bucket cache/index at `+0x3c` through its vector state.
- Base class checked: constructor and destructor call paths show `LObject` base construction/destruction.
- Direct child ownership checked: method/type/global children in this report are still properly owned by the class or file family; the class marker should route children but should not collapse all children into one handwritten declaration.

Why a full declaration shell is unsafe in this pass:

- Visibility, exact public/protected/private grouping, inherited virtual declarations, and signatures for several local methods are still not source-quality.
- The `+0x0c` field remains observed layout/storage but not source-named.
- DATIndexVector/open-archive/bounds-cache field types are not source-quality enough to declare as final class members.
- Emitting a class declaration with those details would hide unresolved API questions behind invented names. A marker plus `[[CHILDREN]]` is safe because it preserves ownership and causes resolved child pages to emit without inventing a full class body.

Recommended formal C++ block:

```cpp
// MonsterImageLib is the source owner for this family. Exact child methods,
// structs, globals, and compiler-generated ABI markers are emitted by their
// own UID pages until the full class declaration is source-quality.
[[CHILDREN]]
```

### [UID:00017E] `by-memory/0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket.md`

Recommended metadata:

- Keep `COMPLETION:88`
- Keep `CONFIDENCE:91`
- Keep `CANONICAL_OWNER:00008N`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:00008N`

Evidence to preserve:

- Exact function start `0x004dbe60`, size `0x315`; no source function at `0x004dc174`.
- Callers at `0x004db647` and `0x004dc1b9`, plus raw local call at `0x004dc279`.
- Cache/vector receiver is the class instance; bounds bucket cache is reached through the `this + 0x3c` area.
- The method formats and opens `DATA/MON%d.DAT`, uses the archive cache at `this + 0x1c`, parses bucket/count/entry records, allocates bucket/entry storage, rebases payload pointers, and returns cached bucket data.

Why no standalone body:

- A source-quality body would need final DATIndexVector/DAT reader types and ownership APIs that are not proven by this pass.
- A decompiler-shaped body would expose raw pointer arithmetic and allocation details that are not source-facing.
- This method is real and owned, but the source-quality representation is not available yet.

Recommended formal C++ block:

```cpp
// MonsterImageLib::GetArchiveBoundsBucket is intentionally not emitted as a
// standalone body yet. [UID:00017E] documents the exact lazy DATA/MON%d.DAT
// bounds-cache behavior, but source-quality C++ still requires final DAT
// archive/vector ownership APIs.
```

### [UID:0003M1] `by-memory/0x004e6750-0x004e6860.MonsterImageLibScalarDeletingDestructor.md`

Recommended metadata:

- `COMPLETION:86`
- `CONFIDENCE:91`
- Keep `CANONICAL_OWNER:00008N`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:00008N`

Evidence to preserve:

- Exact function start `0x004e6750`, size `0x110`; no function at `0x004e6860`.
- Vtable slot/xref at `0x0061b6e4`.
- Function sets the MonsterImageLib vtable, calls `ClearLoadedData`, destroys member vectors/base state, clears singleton storage, and conditionally deletes memory.
- The ordinary destructor `[UID:00017D]` is already the authored source body.

Recommended formal C++ block:

```cpp
// This scalar deleting destructor is compiler-generated from the
// MonsterImageLib virtual destructor and vtable. The authored destructor source
// is emitted by [UID:00017D].
```

### [UID:0001VA] `by-type/by-struct/MonsterArchiveBoundsBucket.md`

Recommended metadata:

- `COMPLETION:88`
- `CONFIDENCE:91`
- Keep `CANONICAL_OWNER:00008N`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:00008N`

Evidence:

- Used by `GetArchiveBoundsBucket` allocation/cache path.
- Layout is 12 bytes.
- Field evidence: count/header halfwords at offsets `0x00`, `0x02`, `0x04`, `0x06`; entry pointer at `0x08`.

Recommended formal C++ block:

```cpp
struct MonsterArchiveBoundsBucket
{
    unsigned short entryCount;
    unsigned short maxExtent02;
    unsigned short maxExtent04;
    unsigned short header06;
    MonsterArchiveBoundsEntry *entries;
};
```

### [UID:0001VB] `by-type/by-struct/MonsterArchiveBoundsEntry.md`

Recommended metadata:

- `COMPLETION:87`
- `CONFIDENCE:91`
- Keep `CANONICAL_OWNER:00008N`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:00008N`

Evidence:

- Used by `GetArchiveBoundsBucket`.
- Layout is 24 bytes.
- Stores rectangle/bounds data plus two rebased payload pointers.

Recommended formal C++ block:

```cpp
struct MonsterArchiveBoundsEntry
{
    RectBounds rect;
    const unsigned char *payloadStart;
    const unsigned char *payloadEnd;
};
```

Implementation note: if the validator reports declaration-order issues for `RectBounds`, the callback should add only the minimal forward/include-compatible note used elsewhere in the project. Do not replace `RectBounds` with raw integer fields unless the local type declaration is unavailable to the target emitter.

### [UID:0001VC] `by-type/by-struct/MonsterImageEntry.md`

Recommended metadata:

- `COMPLETION:88`
- `CONFIDENCE:89`
- Keep `CANONICAL_OWNER:00008N`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:00008N`

Evidence:

- Used by accepted `LoadMonsterTables` source `[UID:0002JN]`.
- Layout is 12 bytes.
- Field evidence: base frame index at `0x00`; animation group count at `0x04`; projection flag at `0x05`; palette/table id halfword at `0x06`; group pointer at `0x08`.
- Helper method names are supported by the accepted loader body and the companion `MonsterImageLibTables.cpp` support declarations.

Recommended formal C++ block:

```cpp
struct MonsterImageEntry
{
    int baseFrameIndex;
    unsigned char animationGroupCount;
    unsigned char projectionFlag;
    unsigned short paletteTableId;
    ImageAnimationGroup *groups;

    void AllocateGroups(unsigned int count);
    ImageAnimationGroup *GetGroup(unsigned int groupIndex);
    ImageAnimationFrame *GetFrame(unsigned int groupIndex, unsigned int frameIndex);
};
```

Do not emit helper method bodies from this page. Those routines belong to the accepted `[UID:0001CM]` helper family and the existing loader body only needs this struct surface to be source-readable.

### [UID:0001VD] `by-type/by-struct/MonsterImageLibLayout.md`

Recommended metadata:

- `COMPLETION:87`
- `CONFIDENCE:90`
- Keep `CANONICAL_OWNER:00008N`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:00008N`

Evidence:

- This page documents object layout evidence for the concrete `MonsterImageLib` class.
- Observed layout: base/vptr at `+0x00`, monster table pointer/count at `+0x04/+0x08`, unresolved word at `+0x0c`, archive offset vector at `+0x10/+0x14/+0x18`, open archive/index cache at `+0x1c`, and bounds bucket cache/index area around `+0x3c`.

Why no duplicate struct:

- A standalone `MonsterImageLibLayout` ABI struct would create an artificial source type and compete with the actual class declaration.
- The safe source route is the class page plus child declarations/methods.

Recommended formal C++ block:

```cpp
// MonsterImageLibLayout is an evidence page for the concrete MonsterImageLib
// object layout. Do not emit a duplicate ABI struct; source declarations belong
// on [UID:00008N] and exact child pages.
```

### [UID:0001Y7] `by-type/by-vtable/MonsterImageLibVtable.md`

Recommended metadata:

- `COMPLETION:87`
- `CONFIDENCE:92`
- Keep `CANONICAL_OWNER:00008N`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:00008N`

Evidence:

- Current bytes at `0x0061b6e0` decode to RTTI pointer `0x00648c14`, scalar deleting destructor `0x004e6750`, virtual slot `0x004f4b10`, and `nullsub_18` at `0x0041b6c0`.
- The adjacent vtable sequence begins at `0x0061b6f0`, so the MonsterImageLib exact vtable range is bounded.
- The vtable is compiler output from class virtual declarations and destructor semantics.

Recommended formal C++ block:

```cpp
// MonsterImageLib vtable bytes are compiler-generated from the class
// declaration and virtual destructor; do not hand-emit a source vtable object.
[[CHILDREN]]
```

### [UID:0002MM] `by-memory/0x0061b6e0-0x0061b6f0.MonsterImageLibVtableData.md`

Recommended metadata:

- `COMPLETION:90`
- `CONFIDENCE:92`
- Keep `CANONICAL_OWNER:0001Y7`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:0001Y7`

Evidence:

- Exact `.rdata` range is `0x0061b6e0-0x0061b6f0`.
- Current dwords are `0x00648c14`, `0x004e6750`, `0x004f4b10`, `0x0041b6c0`.
- This is generated-binary data tied to the class/vtable, not source-authored data.

Recommended formal C++ block:

```cpp
// Emitted vtable data for 0x0061b6e0-0x0061b6f0 is covered by
// [UID:0001Y7] and the MonsterImageLib class declaration. This exact .rdata
// range is compiler-generated output, not a hand-authored source table.
```

### [UID:0000RR] `by-global/g_pMonsterImageLib.md`

Recommended metadata:

- `COMPLETION:88`
- `CONFIDENCE:90`
- Keep `CANONICAL_OWNER:0000LJ`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:0000LJ`

Evidence:

- Exact storage is `0x0069b440`.
- Current storage value is zero.
- Constructor writes the singleton pointer; ordinary/scalar destructor and the clear helper clear it.
- 22 xrefs show normal singleton/global use across initialization, teardown, and UI/render consumers.

Recommended formal C++ block:

```cpp
static MonsterImageLib *g_pMonsterImageLib = NULL;
```

This should be the single source definition for the singleton pointer. The exact storage child `[UID:0001PN]` should not emit a second definition.

### [UID:0001PN] `by-memory/0x0069b440-0x0069b444.g_pMonsterImageLib.md`

Recommended metadata:

- `COMPLETION:88`
- `CONFIDENCE:91`
- Keep `CANONICAL_OWNER:0000RR`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:0000RR`

Required correction:

- Replace stale language that says initial bytes are `ff ff ff ff` or `0xffffffff`.
- Current MCP `get_bytes`/`get_int` shows `0x0069b440 == 0`.

Recommended formal C++ block:

```cpp
// The exact 0x0069b440 storage for g_pMonsterImageLib is emitted once by
// [UID:0000RR]. Current MCP evidence shows zero-filled .data storage, not an
// explicit 0xffffffff initializer.
```

### [UID:0000VK] `by-item/VectorGrowArchiveIndex_004E5990.md`

Recommended metadata:

- `COMPLETION:87`
- `CONFIDENCE:91`
- Set `RECONSTRUCTABLE:FALSE`
- Clear `EMITTER_UIDS`
- Keep an explicit note that the exact executable function disposition is owned by `[UID:0002VF]`

Evidence:

- This page is an item/index alias for `VectorGrowArchiveIndex`.
- The exact by-memory page `[UID:0002VF]` already owns the MCP-backed range and source-quality disposition.
- Keeping both pages reconstructable creates duplicate empty-emitter pressure without adding source code.

Recommended formal C++ block:

```cpp

```

No emitted C++ should be produced by this alias page. It should become a non-reconstructable evidence/index page.

### [UID:0002VF] `by-memory/0x004e5990-0x004e5a62.VectorGrowArchiveIndex.md`

Recommended metadata:

- `COMPLETION:88`
- `CONFIDENCE:92`
- Keep `CANONICAL_OWNER:0000LJ`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:0000LJ`

Evidence:

- Exact function start `0x004e5990`, size `0xd2`; no function at `0x004e5a62`.
- One caller at `0x004dbd8f` inside `LoadMonsterArchives` (`0x004dbc60`, size `0x19b`).
- Receiver/caller setup is the archive offset vector member of `MonsterImageLib`.
- Entry size is 4 bytes, not a `MonsterImageEntry` row and not a 32-byte layer row.
- Callees are allocation/grow support, `_memmove_0`, storage replacement helper `0x004e6df0`, and length guard helper `0x00421500`.

Why no standalone helper body:

- The function is a compiler-lowered vector grow/insert path for a source container operation in `LoadMonsterArchives`.
- Emitting a free helper body would preserve ABI mechanics instead of source behavior.
- Final source should represent this as an append/insert into the archive offset vector inside `LoadMonsterArchives` when that method is reconstructed.

Rejected alternatives:

- Do not mark it as direct `VectorHelpers` ownership; the only current caller is MonsterImageLib-specific.
- Do not emit a standalone vector-grow function body.
- Do not collapse it into `MonsterImageEntry`; the element size is 4 bytes and the caller is the archive offset vector.

Recommended formal C++ block:

```cpp
// VectorGrowArchiveIndex is the compiler-lowered grow/insert path for
// MonsterImageLib::LoadMonsterArchives' 4-byte archive-offset vector. Final
// source should express the operation in LoadMonsterArchives, not as a
// standalone helper body.
```

### [UID:000181] `by-memory/0x004e5bd0-0x004e5bdb.MonsterImageLibSingletonClearHelper.md`

Recommended metadata:

- `COMPLETION:88`
- `CONFIDENCE:93`
- Keep `CANONICAL_OWNER:0000LJ`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:0000LJ`

Evidence:

- Exact function start `0x004e5bd0`, size `0xb`; no function at `0x004e5bdb`.
- Bytes are a direct store of zero to `0x0069b440` followed by return.
- One cleanup-table xref at `0x005ffd87`.
- No callees.

Recommended formal C++ block:

```cpp
static void ClearMonsterImageLibSingleton()
{
    g_pMonsterImageLib = NULL;
}
```

Implementation note: keep the name file-local to avoid claiming a source symbol that is not proven externally.

### [UID:00029K] `by-memory/0x0069b424-0x0069b430.ImageLibraryFallbackRecord.md`

Recommended metadata:

- `COMPLETION:88`
- `CONFIDENCE:92`
- Keep `CANONICAL_OWNER:0000LJ`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:0000LJ`

Required correction:

- Replace stale all-`0xff`/`0xffffffff` storage language.
- Current MCP shows zero-filled storage for `0x0069b424`, `0x0069b428`, and `0x0069b42c`.

Evidence:

- `0x0069b424` has refs from static initialization wrapper `0x00419fb0`, `LoadMonsterTables` at `0x004dacfe`, out-of-range lookup fallback at `0x004db33d`, and cleanup wrapper `0x0060c280`.
- `0x0069b42c` has seeding refs in `LoadMonsterTables`.
- `LoadMonsterTables` seeds 21 animation groups through the accepted `[UID:0002JN]` body and the `[UID:0001CM]` helper family.

Recommended formal C++ block:

```cpp
static ImageAnimationTable g_defaultMonsterAnimationTable;
```

Do not emit an explicit initializer. The current storage is zero-filled and the constructor/static initialization path performs setup.

## Rejected Alternatives And No-Loss Proof

Rejected: raising the root to 90+ now.

- Reason: the empty-emitter family can be resolved, but the class source surface is not complete. Constructor source, `LoadMonsterArchives`, `ClearLoadedData`, render/accessor bodies, DAT reader ownership, and full class declaration remain unresolved.

Rejected: writing a standalone `VectorGrowArchiveIndex` body.

- Reason: MCP proves one MonsterImageLib caller inside `LoadMonsterArchives` and a 4-byte vector insertion path. A standalone body would document lowered vector mechanics rather than source behavior.

Rejected: moving `VectorGrowArchiveIndex` to generic `VectorHelpers`.

- Reason: no generic source-owner evidence was found in this pass. The current single caller is MonsterImageLib-specific, so the exact by-memory page should keep the local no-code disposition.

Rejected: emitting a duplicate `MonsterImageLibLayout` struct.

- Reason: layout evidence belongs to the actual class. A separate ABI struct would create a source type not proven by the binary or surrounding docs.

Rejected: hand-emitting `MonsterImageLib` vtable data.

- Reason: current bytes identify compiler-generated class ABI output; source should express virtual declarations/destructor ownership, not a static table.

Rejected: preserving stale `0xffffffff` storage text for `g_pMonsterImageLib` or `ImageLibraryFallbackRecord`.

- Reason: current MCP bytes and ints show zero-filled storage at `0x0069b440` and `0x0069b424-0x0069b430`.

Rejected: treating the related `[UID:0001CM] MonsterImageLibTables` report as sufficient for this target.

- Reason: `[UID:0001CM]` supports helper declarations and table routines, but `[UID:0000LJ]` still owns the file-level empty emitter family listed above.

## Support Docs To Edit After Acceptance

Primary target:

- `by-file/MonsterImageLib.md`

Direct implementation docs:

- `by-class/MonsterImageLib.md`
- `by-memory/0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket.md`
- `by-memory/0x004e6750-0x004e6860.MonsterImageLibScalarDeletingDestructor.md`
- `by-memory/0x004e5990-0x004e5a62.VectorGrowArchiveIndex.md`
- `by-memory/0x004e5bd0-0x004e5bdb.MonsterImageLibSingletonClearHelper.md`
- `by-item/VectorGrowArchiveIndex_004E5990.md`
- `by-global/g_pMonsterImageLib.md`
- `by-memory/0x0069b440-0x0069b444.g_pMonsterImageLib.md`
- `by-memory/0x0069b424-0x0069b430.ImageLibraryFallbackRecord.md`
- `by-type/by-struct/MonsterArchiveBoundsBucket.md`
- `by-type/by-struct/MonsterArchiveBoundsEntry.md`
- `by-type/by-struct/MonsterImageEntry.md`
- `by-type/by-struct/MonsterImageLibLayout.md`
- `by-type/by-vtable/MonsterImageLibVtable.md`
- `by-memory/0x0061b6e0-0x0061b6f0.MonsterImageLibVtableData.md`

Support docs to re-read before editing but only change if validators or current text require it:

- `by-file/MonsterImageLibTables.md`
- `by-memory/0x00528930-0x00528d51.MonsterImageLibTables.md`
- `by-memory/0x004dac40-0x004dc420.MonsterImageLibLocalMethodCluster.md`
- `by-memory/0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables.md`

## Validator Results For Implementation Callback

The original validator plan in this report used the old `tools/validators/validate_by_file.py` shape. The supervisor rejected that plan for the callback. B011 used only the amended command form from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0000LJ-MonsterImageLib-empty-emitter-family-source-quality-removed.md](0000LJ-MonsterImageLib-empty-emitter-family-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

The final/root validation was run with `--wait-generated`:

> Executable block R002 was removed from this report and preserved verbatim in [0000LJ-MonsterImageLib-empty-emitter-family-source-quality-removed.md](0000LJ-MonsterImageLib-empty-emitter-family-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Validator result table:

| File | command_id | command_timestamp | Exit | ok | Generated refresh |
| --- | --- | --- | ---: | ---: | --- |
| `by-class/MonsterImageLib.md` | `000000002977` | `2026-06-30T15:02:56-04:00` | 0 | 1 | deferred |
| `by-memory/0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket.md` | `000000002978` | `2026-06-30T15:02:58-04:00` | 0 | 1 | deferred |
| `by-memory/0x004e6750-0x004e6860.MonsterImageLibScalarDeletingDestructor.md` | `000000002979` | `2026-06-30T15:03:00-04:00` | 0 | 1 | deferred |
| `by-memory/0x004e5990-0x004e5a62.VectorGrowArchiveIndex.md` | `000000002980` | `2026-06-30T15:03:02-04:00` | 0 | 1 | deferred |
| `by-memory/0x004e5bd0-0x004e5bdb.MonsterImageLibSingletonClearHelper.md` | `000000002981` | `2026-06-30T15:03:04-04:00` | 0 | 1 | deferred |
| `by-item/VectorGrowArchiveIndex_004E5990.md` | `000000002982` | `2026-06-30T15:03:06-04:00` | 0 | 1 | deferred |
| `by-global/g_pMonsterImageLib.md` | `000000002983` | `2026-06-30T15:03:08-04:00` | 0 | 1 | deferred |
| `by-memory/0x0069b440-0x0069b444.g_pMonsterImageLib.md` | `000000002984` | `2026-06-30T15:03:09-04:00` | 0 | 1 | deferred |
| `by-memory/0x0069b424-0x0069b430.ImageLibraryFallbackRecord.md` | `000000002985` | `2026-06-30T15:03:11-04:00` | 0 | 1 | deferred |
| `by-type/by-struct/MonsterArchiveBoundsBucket.md` | `000000002986` | `2026-06-30T15:03:13-04:00` | 0 | 1 | deferred |
| `by-type/by-struct/MonsterArchiveBoundsEntry.md` | `000000002987` | `2026-06-30T15:03:15-04:00` | 0 | 1 | deferred |
| `by-type/by-struct/MonsterImageEntry.md` | `000000002988` | `2026-06-30T15:03:17-04:00` | 0 | 1 | deferred |
| `by-type/by-struct/MonsterImageLibLayout.md` | `000000002989` | `2026-06-30T15:03:18-04:00` | 0 | 1 | deferred |
| `by-type/by-vtable/MonsterImageLibVtable.md` | `000000002990` | `2026-06-30T15:03:20-04:00` | 0 | 1 | deferred |
| `by-memory/0x0061b6e0-0x0061b6f0.MonsterImageLibVtableData.md` | `000000002991` | `2026-06-30T15:03:22-04:00` | 0 | 1 | deferred |
| `by-file/MonsterImageLib.md --wait-generated` | `000000002992` | `2026-06-30T15:03:31-04:00` | 0 | 1 | completed |
| `by-file/MonsterImageLib.md --wait-generated` rerun | `000000002993` | `2026-06-30T15:04:43-04:00` | 0 | 1 | completed |

Validator side effects were validator-owned only: `tools/validator.ini` registry rebuilds/updates, `project-level/-auto-completion-stats.md` projected stats updates, `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, generated C++ metadata refreshes, and `tools/validator_autogen_backup/*` backup creation. No generated files or tool state were edited manually by B011.

Queue/freshness checks:

- `python .\tools\validator.py --queue-status` command `000000002994` at `2026-06-30T15:05:31-04:00` showed one generated-refresh job still processing.
- `python .\tools\validator.py --queue-status` command `000000002995` at `2026-06-30T15:05:51-04:00` showed `queued jobs: 0`, `processing jobs: 0`, `queued generated refresh jobs: 0`, and `processing generated refresh jobs: 0`.
- `auto-generated/NexusTK/render/MonsterImageLib.cpp` contains the accepted emitted content and no `empty reconstruction` markers. It contains UID markers/output for `00008N`, `00017E`, `0003M1`, `0001VA`, `0001VB`, `0001VC`, `0001VD`, `0001Y7`, `0002MM`, `0000RR`, `0002VF`, `000181`, and `00029K`.
- `0000VK` correctly no longer emits because it is now `RECONSTRUCTABLE:FALSE` with blank `EMITTER_UIDS`.
- `0001PN` has a formal covered-by block in its by-memory page but does not surface in `MonsterImageLib.cpp` because [UID:0000RR] emits the single singleton pointer definition and intentionally does not include child output. This avoids a duplicate pointer definition and removes the former empty marker.
- Final generated header after the queue drained: `validator-command-id: 000000002991`, `validator-refreshed-at: 2026-06-30T15:03:22-04:00`, `validator-refresh-source: deferred-generated-refresh`. This header is older than the final root validator command `000000002993`, but the queue was empty afterward and the generated content includes all accepted child-generated changes. Treat `000000002991` as the last generated-changing child refresh for `MonsterImageLib.cpp`; root command `000000002993` completed generated-refresh processing without further content changes to that file.

## Claim And Incorporation Ledger

| Claim | Evidence | Incorporation result |
| --- | --- | --- |
| MCP was available and used | `server_health` id `104` returned `status: ok`; IDB session `supervisor_resume_20260629` active | Applied. Preserved in `by-file/MonsterImageLib.md` 2026-06-30 B011 section and target/support docs where relevant; no fallback-only implementation claims were added. |
| Root generated file had 15 empty markers | Original `MonsterImageLib.cpp` header `000000002929`, refreshed `2026-06-30T14:34:45-04:00` | Applied. `by-file/MonsterImageLib.md` now records all 15 dispositions. Refreshed generated file has no `empty reconstruction` markers; `0000VK` and `0001PN` no longer surface as empty markers. |
| `[UID:0002JN]` and `[UID:00017D]` were already filled | Generated output and support docs reviewed | Already-present/preserved. No method bodies were rewritten; file/class docs now explicitly preserve them as filled accepted source bodies. |
| Class marker can safely route children but not become full declaration | Constructor/destructor/vtable/method/field audit completed; unresolved field/API/signature issues remain | Applied in `by-class/MonsterImageLib.md`: metadata `89/90`, formal class marker plus `[[CHILDREN]]`, and full class route audit. |
| `GetArchiveBoundsBucket` is real but not source-quality yet | MCP function size `0x315`, callers, DAT/cache behavior confirmed | Applied in `by-memory/0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket.md`: formal target-specific cache/DAT API no-code marker; detailed evidence preserved. |
| Scalar deleting destructor is compiler-generated | MCP size `0x110`, vtable xref `0x0061b6e4`, ordinary destructor already emitted | Applied in `by-memory/0x004e6750-0x004e6860.MonsterImageLibScalarDeletingDestructor.md`: metadata `86/91`, formal compiler-generated wrapper marker. |
| Bounds bucket and bounds entry are source-facing structs | `GetArchiveBoundsBucket` allocation/cache path and existing struct docs | Applied in `MonsterArchiveBoundsBucket.md` (`88/91`) and `MonsterArchiveBoundsEntry.md` (`87/91`) with formal declarations. |
| `MonsterImageEntry` is a source-facing loader row | Accepted loader source uses it; layout docs and `[UID:0001CM]` helper declarations support it | Applied in `by-type/by-struct/MonsterImageEntry.md`: metadata `88/89`, formal row declaration with helper declarations only. |
| `MonsterImageLibLayout` is evidence-only | Layout is for concrete class; duplicate ABI struct would be artificial | Applied in `by-type/by-struct/MonsterImageLibLayout.md`: metadata `87/90`, formal evidence-only no-duplicate-struct marker. |
| Vtable and exact vtable bytes are compiler output | Current dwords and vtable xrefs confirmed by MCP | Applied in `MonsterImageLibVtable.md` (`87/92`) and `MonsterImageLibVtableData.md` (`90/92`) with formal no-standalone/covered-by markers. |
| `g_pMonsterImageLib` is source global | Exact storage, constructor/destructor/helper refs, zero current value | Applied in `by-global/g_pMonsterImageLib.md`: metadata `88/90`, formal `static MonsterImageLib *g_pMonsterImageLib = NULL;`. |
| Exact singleton storage stale initializer must be corrected | `get_int 0x0069b440 == 0` | Applied in `by-memory/0x0069b440-0x0069b444.g_pMonsterImageLib.md`: metadata `88/91`, stale `0xffffffff` historicalized/corrected, formal covered-by marker. |
| by-item vector page is duplicate alias | Exact function page owns range/disposition | Applied in `by-item/VectorGrowArchiveIndex_004E5990.md`: `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, alias-only evidence, no C++. |
| by-memory vector grow is compiler-lowered local path | MCP size/caller/callees and 4-byte vector behavior confirmed | Applied in `by-memory/0x004e5990-0x004e5a62.VectorGrowArchiveIndex.md`: metadata `88/92`, formal compiler-lowered vector no-code marker. |
| Singleton clear helper is source-quality enough | Function is 11 bytes, one store-to-zero, cleanup-table xref | Applied in `by-memory/0x004e5bd0-0x004e5bdb.MonsterImageLibSingletonClearHelper.md`: metadata `88/93`, formal `static void ClearMonsterImageLibSingleton()` body. |
| Fallback/default animation table is source global | MCP zero storage, init/cleanup refs, loader seeding refs | Applied in `by-memory/0x0069b424-0x0069b430.ImageLibraryFallbackRecord.md`: metadata `88/92`, stale all-`0xff` historicalized/corrected, formal `static ImageAnimationTable g_defaultMonsterAnimationTable;`. |
| Related `[UID:0001CM]` report is support only | Executed B007 report and generated helper file reviewed | Applied as support-only. `MonsterImageLibTables` and `LoadMonsterTables` support docs were re-read during callback and not edited; direct concrete declarations were applied only to UID0000LJ family docs. |

## Implementation Tracking Checklist

- [x] Update `by-file/MonsterImageLib.md` to `COMPLETION:89`, `CONFIDENCE:89`, add B011 empty-emitter family disposition, and record current MCP zero-fill corrections. Proof: metadata and 2026-06-30 B011 section added; validator `000000002992` and rerun `000000002993` both `ok: 1`.
- [x] Update `by-class/MonsterImageLib.md` to `COMPLETION:89`, `CONFIDENCE:90`, add the class audit, and replace the blank formal block with the marker plus `[[CHILDREN]]`. Proof: formal block populated and class audit added; validator `000000002977` exited 0, `ok: 1`.
- [x] Update `by-memory/0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket.md` with the formal no-code marker and preserve exact size/caller/cache/DAT evidence. Proof: formal target-specific no-code block added; validator `000000002978` exited 0, `ok: 1`.
- [x] Update `by-memory/0x004e6750-0x004e6860.MonsterImageLibScalarDeletingDestructor.md` to `COMPLETION:86`, `CONFIDENCE:91`, and add the compiler-generated destructor marker. Proof: metadata/formal marker applied; validator `000000002979` exited 0, `ok: 1`.
- [x] Update `by-type/by-struct/MonsterArchiveBoundsBucket.md` to `COMPLETION:88`, `CONFIDENCE:91`, and emit the 12-byte struct declaration. Proof: metadata/formal struct applied; validator `000000002986` exited 0, `ok: 1`.
- [x] Update `by-type/by-struct/MonsterArchiveBoundsEntry.md` to `COMPLETION:87`, `CONFIDENCE:91`, and emit the 24-byte struct declaration. Proof: metadata/formal struct applied; validator `000000002987` exited 0, `ok: 1`.
- [x] Update `by-type/by-struct/MonsterImageEntry.md` to `COMPLETION:88`, `CONFIDENCE:89`, and emit the row struct declaration with helper method declarations only. Proof: metadata/formal struct applied; validator `000000002988` exited 0, `ok: 1`.
- [x] Update `by-type/by-struct/MonsterImageLibLayout.md` to `COMPLETION:87`, `CONFIDENCE:90`, and add the evidence-only layout marker. Proof: metadata/formal marker applied; validator `000000002989` exited 0, `ok: 1`.
- [x] Update `by-type/by-vtable/MonsterImageLibVtable.md` to `COMPLETION:87`, `CONFIDENCE:92`, and add the compiler-generated vtable marker plus `[[CHILDREN]]`. Proof: metadata/formal marker applied; validator `000000002990` exited 0, `ok: 1`.
- [x] Update `by-memory/0x0061b6e0-0x0061b6f0.MonsterImageLibVtableData.md` to `COMPLETION:90`, `CONFIDENCE:92`, and add the exact-range covered-by marker. Proof: metadata/formal marker applied; validator `000000002991` exited 0, `ok: 1`.
- [x] Update `by-global/g_pMonsterImageLib.md` to `COMPLETION:88`, `CONFIDENCE:90`, and emit `static MonsterImageLib *g_pMonsterImageLib = NULL;`. Proof: metadata/formal definition applied; validator `000000002983` exited 0, `ok: 1`.
- [x] Update `by-memory/0x0069b440-0x0069b444.g_pMonsterImageLib.md` to `COMPLETION:88`, `CONFIDENCE:91`, correct stale `0xffffffff` text to zero-filled storage, and add the covered-by marker. Proof: metadata/storage correction/formal marker applied; validator `000000002984` exited 0, `ok: 1`.
- [x] Update `by-item/VectorGrowArchiveIndex_004E5990.md` to `RECONSTRUCTABLE:FALSE`, clear `EMITTER_UIDS`, keep alias evidence, and emit no C++. Proof: metadata changed and alias-only evidence added; validator `000000002982` exited 0, `ok: 1`.
- [x] Update `by-memory/0x004e5990-0x004e5a62.VectorGrowArchiveIndex.md` to `COMPLETION:88`, `CONFIDENCE:92`, and add the local compiler-lowered vector no-code marker with size/caller/callee proof. Proof: metadata/formal marker applied; validator `000000002980` exited 0, `ok: 1`.
- [x] Update `by-memory/0x004e5bd0-0x004e5bdb.MonsterImageLibSingletonClearHelper.md` to `COMPLETION:88`, `CONFIDENCE:93`, and emit the `static void ClearMonsterImageLibSingleton()` helper body. Proof: metadata/formal helper body applied; validator `000000002981` exited 0, `ok: 1`.
- [x] Update `by-memory/0x0069b424-0x0069b430.ImageLibraryFallbackRecord.md` to `COMPLETION:88`, `CONFIDENCE:92`, correct stale all-`0xff` language to zero-filled storage, and emit `static ImageAnimationTable g_defaultMonsterAnimationTable;`. Proof: metadata/storage correction/formal declaration applied; validator `000000002985` exited 0, `ok: 1`.
- [x] Re-read support docs for `MonsterImageLibTables` and `LoadMonsterTables` before editing to avoid overwriting B007/B011/B003/B002 incorporated details; edit only if validators require support refresh. Proof: re-read `by-file/MonsterImageLibTables.md`, `by-memory/0x00528930-0x00528d51.MonsterImageLibTables.md`, `by-memory/0x004dac40-0x004dc420.MonsterImageLibLocalMethodCluster.md`, and `by-memory/0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables.md`; no support edits were required by validators.
- [x] Run scoped validators from `source-3/project-documentation`, including target file validation with `--wait-generated`. Proof: validators `000000002977` through `000000002993` all exited 0 with `ok: 1`; root `--wait-generated` commands `000000002992` and `000000002993` reported `generated_refresh: completed`.
- [x] Record validator command IDs, timestamps, exit codes, ok counts, generated `MonsterImageLib.cpp` freshness, leases used/released, and any explicitly deferred items in the implementation checkpoint. Proof: this report section and final callback checkpoint record validator table, generated header/content state, lease commands, release state, and no unchecked blockers.

## Final Report Disposition

Implementation callback is complete for the accepted UID0000LJ report details. The report remains in `tools/leaser/Agents/Agent-B011/research/` for supervisor verification/execution. No manual generated files, coverage reports, validator/tool state, IDA DB files, supervisor ledgers, archives, or lock files were edited by B011.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B011","command_id":"000000004165","destination_path":"executed-b-agent-research/B011/0000LJ-MonsterImageLib-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B011/research/0000LJ-MonsterImageLib-empty-emitter-family-source-quality.md","timestamp":"2026-06-30T15:12:45","uid":"0000LJ"} -->
<!-- {"agent":"B011","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000LJ-MonsterImageLib-empty-emitter-family-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B011/0000LJ-MonsterImageLib-empty-emitter-family-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000LJ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
