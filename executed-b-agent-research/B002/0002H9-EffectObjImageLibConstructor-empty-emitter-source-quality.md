** TARGET-REPORT-UID:0002H9 **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002H9 EffectObjImageLib Constructor Empty-Emitter Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0002H9] owned by [UID:00004A][EffectObjImageLib](../../../by-class/EffectObjImageLib.md), keep `RECONSTRUCTABLE:TRUE`, keep emitter route [UID:00004A] -> [UID:0000IY][EffectObjImageLib](../../../by-file/EffectObjImageLib.md) / `auto-generated/NexusTK/render/EffectObjImageLib.cpp`, and populate the formal constructor C++ block.
- Final disposition: UID0002H9 is an eligible source-bearing empty emitter. Current MCP session `3fa0535f` confirms the exact constructor body, one startup caller, constructor-only loader/archive helper calls, singleton publish/clear behavior, vtable/protected-array setup, `EFFECT.EPF` metadata build, fatal frame-count validation, and boundary padding. The remaining field/helper-name uncertainties are support-level confidence caps, not blockers for first-draft constructor C++.
- Required action if accepted: update UID0002H9 from `88/90` to `91/92`, fill the blank formal `RECONSTRUCTION_CPP CODE` block with the exact constructor body below, replace stale `95/95 final-code gate` wording with the current active code-entry gate/source-quality rationale, and synchronize [UID:00004A] / [UID:0000IY] wording that UID0002H9 now emits first-draft source-ready `EffectObjImageLib::EffectObjImageLib()`.
- Confidence: high for range, owner, emitter, startup caller, field offsets, resource filenames, failure path, and source-readiness; medium-high for exact original private member spelling and the exact original name of the archive-table type.

Implementation callback result, 2026-06-29: accepted target/support details were applied to UID0002H9, [UID:00004A], and [UID:0000IY]. Target metadata is now `91/92`, owner/emitter/reconstructable metadata is unchanged, the exact formal constructor C++ is present, support docs are synchronized with scores unchanged, validators `000000001137`, `000000001138`, and `000000001139` returned `ok: 1`, generated `auto-generated/NexusTK/render/EffectObjImageLib.cpp` is refreshed at `validator-command-id: 000000001143`, and UID0002H9 no longer appears as an empty emitter.

## Target

- Target UID: `0002H9`
- Target path: `by-memory/0x004ddf60-0x004de04e.EffectObjImageLibConstructor.md`
- Source queue/report row: `auto-generated/-ag-research-tracker.md` -> `## Files With Empty Emitters`
- Current generated file: `auto-generated/NexusTK/render/EffectObjImageLib.cpp`
- Current metadata: `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:00004A`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00004A`, blank formal C++.
- Pre-callback generated state: `EffectObjImageLib.cpp` header `validator-command-id: 000000001127`, `validator-refreshed-at: 2026-06-29T19:49:02-04:00`; UID0002H9 appeared as an `Empty Emitter Marker`.
- Post-callback generated state: `EffectObjImageLib.cpp` header `validator-command-id: 000000001143`, `validator-refreshed-at: 2026-06-29T20:08:32-04:00`, source `deferred-generated-refresh`; UID0002H9 emits `EffectObjImageLib::EffectObjImageLib()` and has no UID0002H9 empty marker.
- MCP session used: `3fa0535f`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `server_health` status `ok`, auto-analysis ready, Hex-Rays ready, strings cache ready.

## Current Target State

The target already has the correct exact class owner, emitter route, reconstructable flag, range, item summary, startup caller, and related support links. Its only generated-output blocker is blank formal C++. The existing target text still says final C++ remains blank because protected-array field names, archive metadata helper declarations, and error/helper names remain below the old `95/95` final-code gate. Current `by-structure.md` uses the combined score/emitter source-quality gate, and UID0002H9 clears it: `(88 + 90) / 2 = 89`, with nonblank emitter [UID:00004A] and valid generated route.

The named blockers are now resolved enough for a first-draft constructor:

- Protected-array field names: [UID:0001U9][EffectObjImageLibLayout](../../../by-type/by-struct/EffectObjImageLibLayout.md), [UID:0001U8][EffectInfo](../../../by-type/by-struct/EffectInfo.md), [UID:0001U7][EffectFrameRecord](../../../by-type/by-struct/EffectFrameRecord.md), and [UID:0001UA][EffectPixMapInfo](../../../by-type/by-struct/EffectPixMapInfo.md) already provide stable descriptive member names and exact offsets. Exact original spellings remain confidence caps, not constructor blockers.
- Effect descriptor/resource layout names: `EFFECT.TBL`, `EFFECT.FRM`, `EFFECT.EPF`, `EffectInfo`, `EffectFrameRecord`, and `EffectPixMapInfo` are already documented at same-or-greater detail in support pages.
- Archive metadata helper declaration: [UID:0000U4][BuildEffectArchiveTable_004DE420](../../../by-item/BuildEffectArchiveTable_004DE420.md) is the accepted source-facing helper name and is owned by [UID:0000IY]. [UID:0000UN][EPFArchiveMetadataTable](../../../by-item/EPFArchiveMetadataTable.md) documents the `entryCount` table header used by the constructor validation.
- Error/helper naming: current MCP plus executed B001 reports resolve `0x00467380` as `DestroyDATFileMgr` and `0x004673a0` as `DestroyExceptionHandler`; both are Application fatal-load cleanup helpers called immediately before the constructor's `MessageBoxW` / `__loaddll(0)` failure path.
- Singleton publish/clear behavior: [UID:0000QT][g_pEffectObjImageLib](../../../by-global/g_pEffectObjImageLib.md), [UID:0001PQ][0x0069b44c-0x0069b450.g_pEffectObjImageLib](../../../by-memory/0x0069b44c-0x0069b450.g_pEffectObjImageLib.md), and [UID:00017W][0x004e5b70-0x004e5b7b.EffectObjImageLibSingletonClearHelper](../../../by-memory/0x004e5b70-0x004e5b7b.EffectObjImageLibSingletonClearHelper.md) already document the publish, constructor fallback/null clear, cleanup helper, destructor clears, and consumer reads. The impossible `this == -4` decompiler branch is constructor/unwind cleanup shape and should not be promoted into source-facing normal logic.
- Startup caller: executed B007 `0002H7-ApplicationStartup-source-quality.md` documents the image-library startup construction sequence and explicitly lists `new EffectObjImageLib;`.
- Vtable/protected-array setup: [UID:0001XG][EffectObjImageLibVtable](../../../by-type/by-vtable/EffectObjImageLibVtable.md), [UID:0001U9], and current MCP confirm the primary vtable and embedded protected-array vtables.
- `EFFECT.TBL` / `EFFECT.FRM` loading: [UID:0002HB][0x004de7d0-0x004dec23.EffectObjImageLibLoadEffectTables](../../../by-memory/0x004de7d0-0x004dec23.EffectObjImageLibLoadEffectTables.md) documents the loader, resource layouts, and constructor-only caller.
- `EFFECT.EPF` metadata build and frame-count validation: current MCP confirms the constructor passes `L"EFFECT.EPF"` to `0x004de420`, stores the result at `+0x5c`, and compares `effectPixMapInfoArray.count` at `+0x4c` with the archive table's first `uint16`.

## Executive Recommendation

Populate UID0002H9 with first-draft constructor C++. Use the existing descriptive field names from support docs: `effectInfoArray`, `effectPixMapInfoArray`, and `effectFileInfo`. Keep the owner/emitter/reconstructable metadata unchanged. Raise target completion/confidence to `91/92`; do not raise higher because exact original private member spellings, final `ProtectedArray` constructor declaration spelling, and final archive-table type name remain inferred.

No split, rename, new child, owner change, emitter change, IDA rename, or IDA type edit is required for this target.

## Evidence Checked

- MCP availability:
  - `idb_list`: active session `3fa0535f`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, not analyzing, active/owned/adopted.
  - `server_health`: status `ok`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- MCP target checks:
  - `lookup_funcs` for `0x004ddf60`, `0x004de04e`, `0x004de050`, `0x004de7d0`, `0x004de420`, `0x004f6113`, `0x0061b724`, and `0x0069b44c`.
  - `analyze_function 0x004ddf60`.
  - `decompile 0x004ddf60`.
  - `callees 0x004ddf60`.
  - `xrefs_to 0x004ddf60`, `0x0069b44c`, `0x0061b724`, `0x004de7d0`, `0x004de420`, `0x0061c1b8`, `0x0061c1d0`, and `0x0061b8a8`.
  - `get_bytes` for `0x004ddf58`, `0x004ddf60`, `0x004de04e`, `0x0069b44c`, `0x0061b8a8`, and `0x0061c1d0`.
  - `get_string` for `0x0061c1b8`, `0x0061c1d0`, `0x0061c230`, and `0x0061c248`.
  - `analyze_function 0x00467380` and `0x004673a0` for fatal cleanup helper roles.
- Current docs checked:
  - Target [UID:0002H9].
  - [UID:00004A] `by-class/EffectObjImageLib.md`.
  - [UID:0000IY] `by-file/EffectObjImageLib.md`.
  - [UID:00017K], [UID:0001U9], [UID:0001XG], [UID:0000QT], [UID:0001PQ], [UID:0002HB], [UID:0000U4], [UID:0000UN], [UID:0001U8], [UID:0001U7], [UID:0001UA], [UID:0000MU], [UID:00017L], and [UID:00017W].
  - `by-structure.md` code-entry/emitter rules.
  - `auto-generated/NexusTK/render/EffectObjImageLib.cpp` and `auto-generated/-ag-research-tracker.md`.
- Old report search terms:
  - `0002H9`, `0x004ddf60`, `EffectObjImageLibConstructor`, `EffectObjImageLib::EffectObjImageLib`, `BuildEffectArchiveTable`, `EFFECT.EPF`, `g_pEffectObjImageLib`, `DestroyDATFileMgr`, `DestroyExceptionHandler`, `sub_467380`, and `sub_4673A0`.
- Relevant old reports opened/used as leads:
  - B007 `0002H7-ApplicationStartup-source-quality.md`.
  - B002 `00017M-effectobj-render-frame-source-quality.md`.
  - B003 `000178-00017G-00017I-00017W-00017X-00017Z-000180-0002J2-image-library-cleanup-source-quality.md`.
  - B007 `0000E2-StaticObjImageLib-class-source-quality.md`.
  - B001 `0000YV-DestroyDATFileMgr.md`.
  - B001 `0000YW-DestroyExceptionHandler.md`.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | UID0002H9 is eligible for formal C++ because it is reconstructable, has emitter `00004A`, clears the combined score gate, and generated output showed only an empty marker. | High | Target metadata; `by-structure.md`; pre-callback generated `EffectObjImageLib.cpp` command `000000001127`; post-callback generated header command `000000001143`. | UID0002H9 metadata/status; generated expectation | incorporate | applied: UID0002H9 formal C++ inserted; validator `000000001137` ok; generated header `000000001143` now emits UID0002H9 body with no UID0002H9 empty marker. |
| C02 | The source-facing function is `EffectObjImageLib::EffectObjImageLib()`. | High | Class/file docs, startup report `new EffectObjImageLib`, MCP decompile prototype `_DWORD *__thiscall(_DWORD *this)`. | UID0002H9 formal C++; class/file method wording | incorporate | applied: formal target block begins `EffectObjImageLib::EffectObjImageLib()`; class method row and file owned-method row say source-ready constructor. |
| C03 | Exact function body is `0x004ddf60-0x004de04e`; `0x004de04e` is not a function and `0x004de050` starts the ordinary destructor. | High | MCP `lookup_funcs`; `get_bytes` shows `0xcc 0xcc` at `0x004de04e`. | UID0002H9 boundary/evidence | incorporate | applied: target Boundary Evidence and IDA Evidence record range, `cc cc` padding, non-function end, and successor destructor. |
| C04 | The constructor has exactly one direct code xref/caller at `0x004f6113` inside Application startup function `0x004f5fb0`. | High | MCP `analyze_function` caller list and `xrefs_to 0x004ddf60`; executed B007 startup report. | UID0002H9 caller evidence; class/file support | incorporate | applied: target IDA Evidence and Callers/Callees record one startup caller; class/file sync notes include `0x004f6113`. |
| C05 | The constructor publishes `g_pEffectObjImageLib`, with a decompiler-visible fallback null clear from constructor/unwind shape. | High | MCP decompile stores to `0x0069b44c`; singleton support docs; `xrefs_to 0x0069b44c` returns lifecycle/consumer refs. | UID0002H9 behavior; singleton support wording | incorporate | applied: formal C++ uses normal `g_pEffectObjImageLib = this;`; target Behavior/Reconstruction Notes preserve fallback-clear/unwind interpretation; singleton docs treated already-present. |
| C06 | The formal source should express normal `g_pEffectObjImageLib = this;`, not an artificial `this == -4` branch. | Medium-high | B003 cleanup-glue policy; UID00017W no-code proof; valid constructors cannot receive `this == -4`; source-level cleanup helper captures generated/unwind clear behavior. | UID0002H9 reconstruction notes/C++ rationale | incorporate | applied: formal C++ contains no `this == -4`; target notes explicitly reject encoding that decompiler branch. |
| C07 | Constructor initializes `ProtectedArray<EffectInfo>` and `ProtectedArray<EffectPixMapInfo>` with capacity/count field `10`. | High | MCP decompile/vtable refs; `EffectObjImageLibLayout`; ProtectedArray support. | UID0002H9 C++; layout/support sync | incorporate | applied: formal initializer list uses `effectInfoArray(10)` and `effectPixMapInfoArray(10)`; target IDA Evidence records capacity-10 setup; layout/support already present. |
| C08 | `LoadEffectTables()` is constructor-only, loads `EFFECT.TBL` and `EFFECT.FRM`, and remains the child-owned loader body. | High | MCP call at `0x004ddffb`; `xrefs_to 0x004de7d0` one constructor call; UID0002HB docs. | UID0002H9 C++; UID0002HB already-present proof | incorporate | applied/already-present: formal C++ calls `LoadEffectTables()` only; target notes say not to inline body; UID0002HB support already carries loader details. |
| C09 | `BuildEffectArchiveTable(L"EFFECT.EPF")` is the source-facing archive helper call; the result is stored in `effectFileInfo` at `+0x5c`. | High | MCP decompile call at `0x004de007`, string `0x0061c1b8`, store at `this[23]`; UID0000U4 docs. | UID0002H9 C++; UID0000U4 support | incorporate | applied/already-present: formal C++ assigns `effectFileInfo = BuildEffectArchiveTable(L"EFFECT.EPF")`; target IDA Evidence records string/call/store; UID0000U4 support already carries helper details. |
| C10 | The failure condition is `effectPixMapInfoArray.count < effectFileInfo->entryCount`. | High | MCP decompile compares `this[19]` (`+0x4c`) against first `uint16` of archive table; layout and EPF table docs. | UID0002H9 behavior/C++ | incorporate | applied: exact condition appears in formal C++; target Behavior/IDA Evidence records `+0x4c` versus first archive-table word. |
| C11 | Failure path calls `DestroyDATFileMgr`, `DestroyExceptionHandler`, `MessageBoxW(0, L"Error on Effect File!", L"Data Error", MB_ICONEXCLAMATION)`, then `__loaddll(0)`. | High | MCP decompile; helper analyses at `0x00467380`/`0x004673a0`; B001 helper reports; string/byte reads for `0x0061c1d0` and `0x0061b8a8`; import call. | UID0002H9 C++; rejected-helper notes | incorporate | applied: formal C++ contains all four calls; target IDA Evidence/Callers/Changes record helper names, message text, caption, flag, and termination. |
| C12 | `EFFECT.TBL`, `EFFECT.FRM`, `EFFECT.EPF`, descriptor, frame-record, remap, archive-table, singleton, vtable, and startup evidence are already present in support docs at same-or-greater detail. | High | Read support docs listed above. | Support docs | already-present except source-ready sync notes | already-present/applied: existing support docs retained; class/file source-ready sync notes added; other support pages not edited because same-or-greater detail was already present. |
| C13 | Owner/emitter/reconstructable route should not change. | High | Class/file docs, local cluster, startup caller only constructs dependency, consumers read singleton but do not own it. | UID0002H9 metadata | incorporate | applied: target remains `CANONICAL_OWNER:00004A`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00004A`, blank optional emitter position; class/file scores unchanged. |
| C14 | Recommended target score after formal C++ is `91/92`, not higher. | Medium-high | Empty-emitter blocker resolved; source spellings for private fields, `ProtectedArray` constructor API, and archive-table type remain inferred. | UID0002H9 score rationale | incorporate | applied: target metadata is `COMPLETION:91`, `CONFIDENCE:92`; Score Rationale preserves caps; optional class/file score bumps excluded by current goal. |

## Positive Evidence Summary

- Direct MCP facts support a single exact constructor at `0x004ddf60`, size `0xee`, with a clean successor destructor at `0x004de050`.
- The body has exactly the constructor responsibilities documented by the class/file/layout pages: base construction, singleton publication, vtable setup, embedded protected-array initialization, effect table loading, effect archive metadata build, frame-count validation, and fatal mismatch handling.
- The generated file route is current and valid: [UID:0000IY] emits to `auto-generated/NexusTK/render/EffectObjImageLib.cpp`, and UID0002H9 is included there as an empty marker.
- Support docs already resolve the named constructor dependencies well enough for a first-draft method body.

## IDA MCP Facts

### Function/range facts

| Item | MCP result | Meaning |
| --- | --- | --- |
| `0x004ddf60` | `sub_4DDF60`, size `0xee` | Constructor body `0x004ddf60-0x004de04e`. |
| `0x004de04e` | not a function; bytes `cc cc` | Correct exclusive end/alignment. |
| `0x004de050` | `sub_4DE050`, size `0x13a` | Successor ordinary destructor. |
| `0x004f6113` | inside `sub_4F5FB0`, size `0x4e0` | Startup allocation/constructor caller. |
| `0x0061b724` | not a function | EffectObjImageLib vtable data. |
| `0x0069b44c` | not a function; bytes `00 00 00 00` | Singleton pointer storage. |

### Constructor decompile facts

MCP `analyze_function 0x004ddf60` reports prototype `_DWORD *__thiscall(_DWORD *this)`, caller `sub_4F5FB0`, and callees `__loaddll`, `MessageBoxW`, `sub_4F4A80`, `sub_4DE7D0`, `sub_4DE420`, `sub_467380`, and `sub_4673A0`.

Key body facts:

- calls `sub_4F4A80(this)` at `0x004ddf89` for base `LObject`;
- stores `this` to `0x0069b44c` at `0x004ddf9f` and has a fallback clear at `0x004ddfa6`;
- writes `EffectObjImageLib::vftable` at `0x004ddfb0`;
- writes `ProtectedArray<EffectInfo>::vftable` at `0x004ddfb6`;
- zeroes bytes in the scratch descriptor at offsets `+0x20` and `+0x38`;
- sets descriptor-array capacity/count/storage fields to initial capacity `10` and zero count/storage;
- writes `ProtectedArray<EffectPixMapInfo>::vftable` at `+0x48`;
- sets remap-array capacity/count/storage fields to initial capacity `10` and zero count/storage;
- calls `LoadEffectTables` at `0x004ddffb`;
- calls `BuildEffectArchiveTable` with `L"EFFECT.EPF"` at `0x004de007`;
- stores returned archive metadata pointer to `+0x5c`;
- compares remap count at `+0x4c` against the archive table's first `uint16`;
- on mismatch calls cleanup helpers, shows `L"Error on Effect File!"` with caption bytes for `L"Data Error"`, and calls `__loaddll(0)`.

### Xref facts

| Target | MCP xrefs | Meaning |
| --- | --- | --- |
| `0x004ddf60` | one code xref at `0x004f6113` in `sub_4F5FB0` | One startup constructor caller. |
| `0x0069b44c` | 12 direct refs | Constructor publish/null clear; destructor/helper/scalar clears; shutdown/map/effect/living reads. |
| `0x0061b724` | three data refs at constructor/destructor/scalar destructor | Vtable store/use set. |
| `0x004de7d0` | one code xref at `0x004ddffb` | Loader is constructor-only. |
| `0x004de420` | one code xref at `0x004de007` | Archive builder is constructor-only in this source family. |
| `0x0061c1b8` | one data xref at `0x004de000` | Constructor `EFFECT.EPF` literal. |
| `0x0061c1d0` | one data xref at `0x004de03a` | Constructor `Error on Effect File!` literal. |

### String/byte facts

- `get_string 0x0061c1b8` -> `EFFECT.EPF`.
- `get_string 0x0061c1d0` -> `Error on Effect File!`.
- `get_string 0x0061c230` -> `EFFECT.TBL`.
- `get_string 0x0061c248` -> `EFFECT.FRM`.
- `get_bytes 0x0061b8a8` decodes UTF-16LE `Data Error`, followed by another `Error` literal; the constructor uses the `0x0061b8a8` caption pointer.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004ddf60-0x004de04e` | [UID:0002H9](../../../by-memory/0x004ddf60-0x004de04e.EffectObjImageLibConstructor.md) | `EffectObjImageLib::EffectObjImageLib()` | TRUE | [UID:00004A] | current `88/90`, recommend `91/92` | formal C++ ready |
| `0x004de050-0x004de189` | [UID:00017L](../../../by-memory/0x004de050-0x004de189.EffectObjImageLibDestructor.md) | ordinary destructor | TRUE | [UID:00004A] | `88/91` | sibling, not part of constructor |
| `0x004de420-0x004de7c2` | [UID:0000U4](../../../by-item/BuildEffectArchiveTable_004DE420.md) | effect archive metadata builder | TRUE | [UID:0000IY] | `86/91` | constructor dependency; formal body still separate/blank |
| `0x004de7d0-0x004dec23` | [UID:0002HB](../../../by-memory/0x004de7d0-0x004dec23.EffectObjImageLibLoadEffectTables.md) | `LoadEffectTables` | TRUE | [UID:00004A] | `88/90` | constructor dependency; child-owned body |
| `0x004e5b70-0x004e5b7b` | [UID:00017W](../../../by-memory/0x004e5b70-0x004e5b7b.EffectObjImageLibSingletonClearHelper.md) | singleton cleanup glue | TRUE | [UID:0000IY] | `85/90` | no-code helper, not source API |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004f6113` | calls `0x004ddf60` | Application startup constructs the singleton. |
| `0x004ddffb` | calls `0x004de7d0` | Constructor invokes `LoadEffectTables()`. |
| `0x004de007` | calls `0x004de420` with `L"EFFECT.EPF"` | Constructor builds effect archive metadata. |
| `0x004de029` | calls `0x00467380` | Fatal resource mismatch cleanup: `DestroyDATFileMgr`. |
| `0x004de02e` | calls `0x004673a0` | Fatal resource mismatch cleanup: `DestroyExceptionHandler`. |
| `0x004de041` | calls `MessageBoxW` | Displays effect-file mismatch message. |
| `0x004de049` | calls `__loaddll(0)` | Terminates after fatal mismatch. |

## Ranked Ownership Analysis

### 1. [UID:00004A] EffectObjImageLib class

- Evidence for: constructor writes the `EffectObjImageLib` vtable, initializes `EffectObjImageLib` object fields, calls class loader `LoadEffectTables`, stores effect archive metadata, and owns the singleton lifecycle. Existing target metadata already uses [UID:00004A] and support docs clear the route through [UID:0000IY].
- Evidence against: constructor is called by Application startup, but that is construction orchestration, not semantic ownership.
- Decision: keep canonical owner and emitter [UID:00004A].

### 2. [UID:0000IY] EffectObjImageLib file

- Evidence for: file owns the source module, resource family, archive helper, singleton/global declarations, and generated output route.
- Evidence against: the constructor is a class method with a narrower semantic owner.
- Decision: keep [UID:0000IY] as source file/emitter root through the class, not direct owner.

### 3. [UID:0002H7] / Application startup

- Evidence for: the only direct caller is startup at `0x004f6113`.
- Evidence against: executed B007 report already treats image libraries as startup dependencies. Application constructs `new EffectObjImageLib` but does not own the constructor body, resources, singleton, or cleanup.
- Decision: reject as owner; retain only caller evidence.

### 4. Shared ImageLib / ImageFrameTable / ProtectedArray

- Evidence for: constructor depends on shared template/container and EPF archive-table structures.
- Evidence against: dependencies are support declarations/helpers; the method body writes EffectObjImageLib object state and resource filenames.
- Decision: reject as owner; cite as dependencies.

## Source Placement

Recommended placement stays `NexusTK/render/EffectObjImageLib.cpp`, through [UID:00004A] -> [UID:0000IY]. This matches current generated output, the class/file support pages, the startup report, and the resource family. Do not move the constructor to Application, generic ImageLib, EPFImageResources, ProtectedArray, or a new source file.

## Range / Split / Padding / Reclassification Analysis

- No split required. UID0002H9 is one exact source-authored constructor body.
- Boundary:
  - Start `0x004ddf60`: MCP function start, constructor prologue.
  - End `0x004de04e`: not a function, fatal tail reaches this boundary, and `get_bytes` shows `0xcc 0xcc` immediately after.
  - Successor `0x004de050`: ordinary destructor.
- Padding/data: no non-code data, jump table, embedded table, or padding belongs inside the constructor range.
- Reclassification: keep `RECONSTRUCTABLE:TRUE`.

## Negative Evidence Summary

- Do not emit UID00017W as a named `ClearEffectObjImageLibSingleton` source helper. B003 and UID00017W prove it is constructor/static cleanup glue.
- Do not move ownership to Application startup. Startup allocates/calls the constructor, but the method is class-owned.
- Do not move the constructor to `ImageLib`, `ImageFrameTable`, `EPFImageResources`, or `ProtectedArray`; those pages provide dependency declarations only.
- Do not keep C++ blank because of final original member spelling. Current support names are stable enough for first-draft constructor C++; spelling uncertainty caps score only.
- Do not inline `LoadEffectTables` or `BuildEffectArchiveTable` bodies into the constructor formal block; each has its own target/support page.
- Do not preserve the decompiler's `_DWORD *` / raw-array field syntax or `sub_` helper names in formal source.

## First-Draft C++ Recommendation

Eligible for draft C++: yes.

Recommended exact formal `RECONSTRUCTION_CPP CODE` insertion text:

```cpp
EffectObjImageLib::EffectObjImageLib()
    : effectInfoArray(10),
      effectPixMapInfoArray(10),
      effectFileInfo(0)
{
    g_pEffectObjImageLib = this;

    LoadEffectTables();

    effectFileInfo = BuildEffectArchiveTable(L"EFFECT.EPF");
    if (effectPixMapInfoArray.count < effectFileInfo->entryCount)
    {
        DestroyDATFileMgr();
        DestroyExceptionHandler();
        MessageBoxW(0, L"Error on Effect File!", L"Data Error", MB_ICONEXCLAMATION);
        __loaddll(0);
    }
}
```

Reason it preserves behavior:

- The initializer list represents the base/member construction that produces `LObject`, `ProtectedArray<EffectInfo>`, and `ProtectedArray<EffectPixMapInfo>` setup. The binary writes initial capacity `10` and zero storage/count fields for both arrays.
- `g_pEffectObjImageLib = this` matches the normal source-visible singleton publish. The decompiler's `this == -4` null-clear branch is unreachable for a valid constructor call and is better attributed to constructor/unwind cleanup shape already documented by UID00017W.
- `LoadEffectTables()` remains the child-owned loader call for `EFFECT.TBL` and `EFFECT.FRM`.
- `BuildEffectArchiveTable(L"EFFECT.EPF")` matches the one helper call and resource literal.
- `effectPixMapInfoArray.count < effectFileInfo->entryCount` matches the `+0x4c` versus first archive-table `uint16` comparison.
- The fatal path preserves both cleanup helper calls, message text, caption text, icon flag class, and `__loaddll(0)`.

Reason it matches plausible original source:

- It uses class fields and helper calls rather than decompiler array indexes.
- It keeps the constructor compact and delegates loader/archive-table work to existing helpers, which matches surrounding image-library source shape.
- It uses existing project-wide descriptive names already present in by-* support docs.

Source-facing names used:

- `effectInfoArray`, `effectPixMapInfoArray`, `effectFileInfo`: from current layout/support docs.
- `BuildEffectArchiveTable`: from UID0000U4 source-quality label.
- `DestroyDATFileMgr`, `DestroyExceptionHandler`: from executed B001 cleanup helper reports.
- `g_pEffectObjImageLib`: from global/storage docs.

Third-party import directive: not applicable.

## Recommended Target Doc Changes

Target path: `by-memory/0x004ddf60-0x004de04e.EffectObjImageLibConstructor.md`

Recommended changes if accepted:

- Change `COMPLETION:88` to `COMPLETION:91`.
- Change `CONFIDENCE:90` to `CONFIDENCE:92`.
- Keep `CANONICAL_OWNER:00004A`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00004A`.
- Insert the exact formal C++ block above.
- Update `Item Summary` to say the target now has first-draft source-ready constructor C++ backed by MCP session `3fa0535f`, exact range/padding, startup caller, singleton publish, protected-array initialization, loader/archive helper calls, frame-count validation, fatal cleanup helpers, and generated-output repair expectation.
- Replace stale `95/95 final-code gate` wording with current combined-score/emitter gate language and explain why remaining field/helper spelling uncertainty caps score but does not block first-draft constructor code.
- Add current MCP session `3fa0535f` evidence for function/range, decompile, xrefs, bytes, strings, and helper analyses.
- Preserve negative evidence: no owner/emitter change, no Application ownership, no inline loader/archive helper body, no standalone singleton-clear helper source, no artificial `this == -4` source branch.

## Recommended Support Doc Changes

Support docs to update if accepted:

- `by-class/EffectObjImageLib.md`:
  - Mark the method row for [UID:0002H9] as source-ready first-draft constructor C++.
  - Add a short source-quality sync note that UID0002H9 now emits the constructor under this class; keep broader class C++ blank because other methods/types remain below final-source quality.
  - Optional score change: `85/87 -> 86/88` if the supervisor wants the class page to reflect the repaired constructor emitter; not required for target correctness.
- `by-file/EffectObjImageLib.md`:
  - Add a short source-root sync note that UID0002H9 now emits `EffectObjImageLib::EffectObjImageLib()` in `NexusTK/render/EffectObjImageLib.cpp`.
  - Preserve the generated-output caveat for other empty emitters and the exact original filename/source-split uncertainty.
  - Optional confidence change: `89/86 -> 89/87` if the supervisor wants the current constructor source-ready status reflected in file-level confidence; not required.
- Already-present support, no edit required unless supervisor wants redundant sync:
  - [UID:00017K] local cluster already lists UID0002H9 and the exact child inventory.
  - [UID:0001U9] layout already supplies field offsets/names.
  - [UID:0001XG] vtable already records constructor vptr store.
  - [UID:0000QT] / [UID:0001PQ] already record singleton publish/clear/read set.
  - [UID:0002HB] already records constructor-only `LoadEffectTables`.
  - [UID:0000U4] already records `BuildEffectArchiveTable` ownership/behavior.
  - [UID:0000UN] already records the archive table `entryCount` header and packed-record layout.

No generated report, manual coverage report, validator/tool state, IDA DB, executed archive, or supervisor ledger edit is recommended for B002 to apply manually.

## Score And Metadata Recommendation

- Current target score: `88/90`.
- Recommended target score after implementation: `91/92`.
- Owner/emitter/reconstructable: unchanged.
- Reason for completion increase: formal C++ repairs the empty emitter; current MCP evidence adds range/padding/decompile/xref/string/helper proof; named blockers are either resolved or already present in support docs.
- Reason not higher: exact original private field spellings, exact `ProtectedArray` constructor/member access spelling, and final archive metadata type name remain inferred/descriptive. Those do not block first-draft code but should cap confidence below final audit.

Score-blocker audit:

| Blocker named by current docs/goal | Research performed | Result |
| --- | --- | --- |
| Protected-array field names | Read `EffectObjImageLibLayout`, `EffectInfo`, `EffectFrameRecord`, `EffectPixMapInfo`, `ProtectedArray`; rechecked constructor writes through MCP. | Resolved for constructor: use existing descriptive field names; exact original spelling caps score only. |
| Effect descriptor/resource layout names | Read `EffectInfo`, `EffectFrameRecord`, `EffectPixMapInfo`, `LoadEffectTables`; rechecked `EFFECT.TBL`/`EFFECT.FRM` strings. | Already present; constructor only calls loader. |
| Archive metadata helper declaration | Read `BuildEffectArchiveTable`, `EPFArchiveMetadataTable`; rechecked constructor call/string and archive count comparison. | Resolved for constructor: call `BuildEffectArchiveTable(L"EFFECT.EPF")`, use `entryCount`. |
| Error/helper naming | Rechecked `0x00467380`/`0x004673a0`; opened executed B001 reports. | Resolved: `DestroyDATFileMgr`, `DestroyExceptionHandler`; no new helper needed. |
| Singleton publish/clear behavior | Read global/storage/helper docs; rechecked xrefs and bytes. | Resolved: source publishes singleton; cleanup helper remains no-code glue. |
| Startup caller | Read executed B007 startup report; rechecked xrefs. | Resolved: one startup caller, not owner. |
| Vtable/protected-array setup | Read layout/vtable docs; rechecked decompile/xrefs. | Resolved; initializer list represents source shape. |
| `EFFECT.TBL`/`EFFECT.FRM` loading | Read UID0002HB; rechecked loader xref. | Already-present; constructor calls loader only. |
| `EFFECT.EPF` metadata and validation | Read UID0000U4/UID0000UN; rechecked string/call/compare. | Resolved; constructor formal code can express validation. |
| Class/file emitter route | Read class/file docs and generated output. | Resolved; route unchanged and valid. |

## Open Questions With Attempted Resolution

- Exact original field names:
  - Evidence checked: layout/type docs, loader/destructor/render support, generated source lead, current MCP.
  - Resolution: use existing descriptive names. Original spelling remains unresolved but nonblocking for constructor source.
- Exact `ProtectedArray` constructor/member API spelling:
  - Evidence checked: ProtectedArray support and constructor field writes.
  - Resolution: initializer-list shape `ProtectedArray<T>(10)` is the cleanest source representation. Direct `.count` in the validation expression matches current support docs; an implementation callback may substitute an established accessor if one exists in accepted declarations, but behavior must remain the `+0x4c` count compare.
- Exact archive-table type name:
  - Evidence checked: UID0000UN and UID0000U4.
  - Resolution: `effectFileInfo->entryCount` is source-ready as descriptive support naming; final type spelling remains a confidence cap.
- Exact source form for constructor fallback singleton clear:
  - Evidence checked: MCP decompile, UID00017W, B003 cleanup policy.
  - Resolution: do not encode `this == -4` into normal source. Preserve the behavior in notes as compiler/unwind cleanup handled by static cleanup glue.

## Validator Results

- Report-only pass: no validators run; no leases taken; no by-* docs edited.
- Implementation callback lease proof:
  - Took short lease as `B002` for `by-memory\0x004ddf60-0x004de04e.EffectObjImageLibConstructor.md`, `by-class\EffectObjImageLib.md`, and `by-file\EffectObjImageLib.md`; leaser returned `Success` for all three.
  - Released the same three leases immediately after the edit/validator/generated-check batch; leaser returned `Success` for all three.
  - Read-back proof: `rg "B002|EffectObjImageLib|0x004ddf60|0002H9" tools\leaser\Agents\current_leases.md` returned no matches after release.
- Implementation validators:
  - `python .\tools\validator.py --mode file --file by-memory\0x004ddf60-0x004de04e.EffectObjImageLibConstructor.md --apply --queue-timeout 240 --wait-generated`
    - `command_id: 000000001137`
    - `command_timestamp: 2026-06-29T20:04:54-04:00`
    - exit code `0`, `ok: 1`
    - `generated_refresh: completed`, `generated_refresh_command_id: 000000001137`
  - `python .\tools\validator.py --mode file --file by-class\EffectObjImageLib.md --apply --queue-timeout 240`
    - `command_id: 000000001138`
    - `command_timestamp: 2026-06-29T20:05:12-04:00`
    - exit code `0`, `ok: 1`
    - `generated_refresh: deferred`
  - `python .\tools\validator.py --mode file --file by-file\EffectObjImageLib.md --apply --queue-timeout 240`
    - `command_id: 000000001139`
    - `command_timestamp: 2026-06-29T20:05:18-04:00`
    - exit code `0`, `ok: 1`
    - `generated_refresh: deferred`
- Generated freshness result:
  - Read-only check of `auto-generated/NexusTK/render/EffectObjImageLib.cpp` found header `validator-command-id: 000000001143`, `validator-refreshed-at: 2026-06-29T20:08:32-04:00`, `validator-refresh-source: deferred-generated-refresh`.
  - Header command `000000001143` is newer than target `--wait-generated` command `000000001137`, class-support command `000000001138`, and file-support command `000000001139`, so it is current enough for the target/support implementation batch.
  - UID0002H9 appears as `// UID:0002H9 ... Completion:91 | Confidence:92` followed by `EffectObjImageLib::EffectObjImageLib()` body; UID0002H9 no longer appears as an `Empty Emitter Marker`. Remaining empty markers in the file are other sibling/support UIDs and were outside this accepted scope.

## Changed Files

- Modified by B002 implementation callback:
  - `by-memory/0x004ddf60-0x004de04e.EffectObjImageLibConstructor.md`
  - `by-class/EffectObjImageLib.md`
  - `by-file/EffectObjImageLib.md`
  - `tools/leaser/Agents/Agent-B002/research/0002H9-EffectObjImageLibConstructor-empty-emitter-source-quality.md`
- Validator-owned/generated side effects observed, not manually edited:
  - `auto-generated/NexusTK/render/EffectObjImageLib.cpp` refreshed to command `000000001143`.
  - Target validator output also reported validator-owned generated/project metadata updates, including generated coverage/tracker/projected stats refreshes.
- Report execution: not performed. Supervisor should run the execute-report lifecycle only after verification.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Proof: supervisor accepted the report and assigned implementation callback mode in `goal.md`.
- [x] Target/support docs to update: UID0002H9 target; support [UID:00004A] EffectObjImageLib class and [UID:0000IY] EffectObjImageLib file. Support [UID:00017K], [UID:0001U9], [UID:0001XG], [UID:0000QT], [UID:0001PQ], [UID:0002HB], [UID:0000U4], and [UID:0000UN] are already-present unless supervisor requests redundant sync. Proof: edited only the three listed by-* docs; other support pages treated already-present.
- [x] Current target state and actual evidence checked recorded: report includes target metadata, generated marker state, MCP session health, function/range/xref/decompile/byte/string/helper evidence, support docs, generated docs, and old report searches. Proof: report evidence sections retained; callback result added above.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim. Proof: rows C01-C14 now show `applied`, `already-present`, or combined applied/already-present proof.
- [x] Metadata/score changes to apply: UID0002H9 `88/90 -> 91/92`; owner/emitter/reconstructable unchanged. Proof: target header is `COMPLETION:91`, `CONFIDENCE:92`, `CANONICAL_OWNER:00004A`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00004A`.
- [x] Score-limiting blockers researched to resolution: protected-array field names, descriptor/resource names, archive helper declaration, error helper naming, singleton publish/clear behavior, startup caller, vtable/protected-array setup, `EFFECT.TBL`/`EFFECT.FRM`, `EFFECT.EPF` metadata build, frame-count validation, and route evidence resolved or marked already-present. Proof: target Status/Reconstruction Notes/Score Rationale and ledger C05-C12 record the applied or already-present outcomes.
- [x] Owner/emitter/reconstructable changes to apply: none; keep `CANONICAL_OWNER:00004A`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00004A`. Proof: target metadata unchanged except scores and C++.
- [x] Split/rename/new-child changes to apply: none. Proof: no split, rename, or new child file created.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable: preserve range `0x004ddf60-0x004de04e`; no IDA DB edits requested; no split/reclassification. Proof: target range unchanged; no IDA/tool-state edits made.
- [x] First-draft C++ to apply: insert exact `EffectObjImageLib::EffectObjImageLib()` formal block from this report into UID0002H9. Proof: target formal block and generated output contain the exact constructor.
- [x] Third-party import directive: not applicable. Proof: no third-party import used.
- [x] Exact target/support doc facts to incorporate at report-level detail: MCP session `3fa0535f`, exact body/range/padding, startup caller, singleton publish/fallback clear interpretation, vtable/protected-array setup, initial capacities, loader/archive helper calls, `EFFECT.EPF` string, archive count validation, fatal cleanup helpers, `MessageBoxW` strings, `__loaddll(0)`, rejected owner alternatives, rejected no-code rationale, and score rationale. Proof: target Item Summary/Boundary Evidence/IDA Evidence/Reconstruction Notes/Score Rationale/Changes and class/file sync notes include these accepted facts.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: old `95/95` code-gate wording is stale; Application/startup ownership rejected; generic ImageLib/ImageFrameTable/ProtectedArray ownership rejected; singleton clear helper remains no-code cleanup glue; no artificial `this == -4` branch in source; no inlining loader/archive helper bodies. Proof: target has no remaining `95/95` or `final-code gate` wording; Reconstruction Notes preserve the rejected alternatives and formal C++ omits `this == -4`.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale: generated `simroot_v2` and older generated-source state treated as leads only; current by-* docs and MCP evidence are authoritative. Proof: support caveats preserve generated-output limitations without using stale disabled-companion state as authority.
- [x] Open questions to close or document as evidence-backed unresolved: exact original private field spellings, `ProtectedArray` accessor/member spelling, archive table type name, and constructor cleanup source mechanism remain score caps but not C++ blockers. Proof: target Status/Reconstruction Notes/Score Rationale document these as caps.
- [x] Validators to run: target validator with `--wait-generated`; class/file validators if support docs are edited. Proof: commands `000000001137`, `000000001138`, `000000001139` recorded above.
- [x] Generated report refresh expected: `EffectObjImageLib.cpp` should refresh and UID0002H9 should no longer be an empty emitter; generated reports/tracker are validator-owned and must not be edited manually. Proof: read-only generated check shows header `000000001143`, constructor body present, no UID0002H9 empty marker.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation. Proof: current `goal.md` assignment mode is implementation callback.
- [x] All accepted target/support doc details incorporated at report-level detail. Proof: changed target/class/file docs listed above.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim. Proof: C01-C14 updated.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason. Proof: target `91/92`, owner/emitter/reconstructable unchanged, no split/rename, formal C++ inserted; optional class/file score increases excluded because current `goal.md` instructed no class/file score changes unless required.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved. Proof: target notes reject Application/generic owner routes, no-code deferral, singleton-clear API emission, `this == -4`, and inlining helper bodies.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale. Proof: target Status/Reconstruction Notes/Score Rationale document remaining field/API/type spelling caps.
- [x] Validators run and results recorded with command IDs/timestamps/results. Proof: validator result block above.
- [x] Generated `EffectObjImageLib.cpp` freshness confirmed against validator command metadata and UID0002H9 body/no-empty-marker inspection. Proof: generated header `000000001143` / `2026-06-29T20:08:32-04:00`, body present, no UID0002H9 empty marker.
- [x] Remaining unapplied accepted items listed with exact blocker. Proof: none. Intentionally excluded optional rows: class `85/87 -> 86/88` and file `89/86 -> 89/87` were not applied because `goal.md` explicitly says not to change class/file scores unless validator requires it or a separate reason is found; validators did not require score changes.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0002H9-EffectObjImageLibConstructor-empty-emitter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0002H9-EffectObjImageLibConstructor-empty-emitter-source-quality.md","timestamp":"2026-06-29T20:10:09","uid":"0002H9"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
