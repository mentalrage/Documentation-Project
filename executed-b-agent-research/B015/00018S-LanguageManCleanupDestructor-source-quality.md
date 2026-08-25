** TARGET-REPORT-UID:00018S **
** AUTHOR-AGENT-ID:B015 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00018S LanguageManCleanupDestructor Source-Quality Report

Assignment id: `B015-report-00018S-language-man-cleanup-destructor-20260625`

Report-only scope: no target/support by-* docs, generated files, project-level files, validator state/cache, coverage reports, IDA DB, or leases were edited. IDA MCP was available and used live.

## Finalized Report / Current Recommendation

Current recommendation: keep [UID:00018S] `by-memory/0x004f0290-0x004f0310.LanguageManCleanupDestructor.md` as the source-authored `LanguageMan::~LanguageMan()` non-deleting destructor body, not as Boost, not as `LanguageManager`, not as `MemoryMan`, and not as the scalar deleting wrapper.

Final disposition:

- Raise target metadata from `COMPLETION:87`, `CONFIDENCE:91` to `COMPLETION:89`, `CONFIDENCE:92`.
- Keep `CANONICAL_OWNER:000071`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:000071`.
- Keep the existing formal C++ body unchanged. The current body is source-shaped and matches the live binary after helper/field-name recheck.
- Add a B015 current-session evidence section to the target page, including the active MCP session `80de0a67`, stale Boost-name status, function/xref/byte facts, helper-name proof, `g_pLanguageMan` proof, scalar-wrapper relationship, and adjacent zero-initializer caveat.
- Correct stale support wording in [UID:0000RC] `by-global/g_pLanguageMan.md`: the active B015 MCP session still reports `0x004f0290` as `??1exception@boost@@MAE@XZ_3`, so the prior C001 "stale Boost label is now repaired in the IDB" sentence must be made session-scoped or superseded.
- Do not manually edit generated reports. The current generated research tracker, auto memory coverage row, and generated `LanguageMan.cpp` UID comments are stale for this target; refresh them through scoped validators after implementation.

Confidence: very strong for behavior/source ownership and strong for the recommended score move.

## Target

- Target UID: `00018S`
- Target path: `by-memory/0x004f0290-0x004f0310.LanguageManCleanupDestructor.md`
- Primary queue source: `auto-generated/-ag-research-tracker.md`, `## by-memory` -> `### Not-Covered Files - Reconstructable`
- Current generated queue row: stale at `76/84`, average `80.0`, path `by-memory/0x004f0290-0x004f0310.LanguageManCleanupDestructor.md`.
- Current auto coverage row: stale at `76%`, `emits_code:false`, even though the source page is `87/91` and generated `auto-generated/NexusTK/localization/LanguageMan.cpp` contains the destructor body.
- Current source metadata: `87/91`, owner/emitter [UID:000071] `LanguageMan`, reconstructable true, nonblank formal C++.
- Parent state: [UID:000071] `LanguageMan` is `89/92`, [UID:0000KK] `LanguageMan` file is `89/89`, and [UID:00018R] localization aggregate is `88/91`.

## Current Target State

The target already contains a plausible formal destructor:

```cpp
LanguageMan::~LanguageMan()
{
    MemoryMan* memoryMan = GetMemoryMan();

    for (int i = 0; i < m_stringCount; ++i)
        memoryMan->FreeBufferMemory(m_strings[i]);

    memoryMan->FreeBufferMemory(m_strings);
    g_pLanguageMan = 0;
}
```

The report task was therefore source-quality verification rather than code discovery. The existing page had the correct broad disposition but still carried score-limiting caveats around the stale Boost name, MemoryMan helper spelling, adjacent zero-initializer fields, scalar deleting destructor relationship, generated-state staleness, and support wording that implied the active IDB name had been repaired.

## Supervisor Active Recheck

The active assignment required live MCP verification and explicitly prohibited fallback-only reporting. MCP responded normally:

- `initialize` succeeded against `http://127.0.0.1:13337/mcp`.
- `idb_list` reported active worker session `80de0a67`, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `pid`/`worker_pid` `26892`, active and not analyzing.
- `server_health` for `80de0a67` reported module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.

No split repair is required. `0x004f0290-0x004f0310` is one complete IDA-modeled function of size `0x80` / 128 bytes (Verified with `int_convert.py`), preceded and followed by existing sibling ranges/padding.

## Inference Research Guidance Check

I treated existing docs and older reports as leads, not proof. The key source-quality issue is not whether the destructor behavior exists; it does. The issue is whether the names and source shape are realistic enough for final emitted C++.

Direct IDA facts in this pass:

- Active IDA still names the function `??1exception@boost@@MAE@XZ_3`.
- The body writes the `LanguageMan` vtable, frees the `+0x04` table using the `+0x08` count, clears `g_pLanguageMan`, and calls the `LObject` base cleanup.
- The scalar deleting wrapper at `0x004f03d0` duplicates the cleanup and adds only compiler delete-flag handling.
- `LanguageMan` and `Singleton<LanguageMan>` RTTI/name records exist; no `LanguageManager` name record was found by the current entity query.

Inference:

- `LanguageMan::~LanguageMan()` is the best source-facing name despite the stale Boost IDA name.
- `GetMemoryMan()` and `MemoryMan::FreeBufferMemory(void*)` remain source-facing inferred names rather than original-proof names, but they are strong enough for this destructor C++ because the helper docs and live bodies establish their role.
- The adjacent zero-initializer is still only a `LanguageMan.cpp` file-level orphan/private helper. It increases layout suspicion for tail fields but does not block the destructor body.

No Wave2/Wave3 material was used as authority. Old Wave3/generated-output caveats were treated only as historical generated-state context.

## Heuristic / Inference Reanalysis And Validation

Stale Boost name:

- Evidence checked: active `lookup_funcs`, `analyze_function`, `entity_query`, vtable bytes, constructor/lookup siblings, and support docs.
- Result: active session `80de0a67` still reports `0x004f0290` as `??1exception@boost@@MAE@XZ_3`; this is contradicted by the body and by LanguageMan RTTI/vtable/global evidence.
- Decision: keep raw Boost name only as an IDA/search alias. Final source name stays `LanguageMan::~LanguageMan()`.
- Support impact: update `by-global/g_pLanguageMan.md` so the C001 saved-name claim is not treated as true for the current active IDB.

MemoryMan wrapper names:

- Evidence checked: [UID:0001BC] `GetMemoryMan`, [UID:0001BF] `FreeBufferMemory`, live `disasm`/`decompile` for `0x00516030` and `0x00516170`, and scalar-wrapper report evidence.
- Live facts: `0x00516030` is two instructions, `mov eax, dword ptr unk_69B4FC; retn`; `0x00516170` calls `j___free_base(Block)`, returns zero, and uses `retn 4`.
- Decision: existing C++ names `GetMemoryMan()` and `memoryMan->FreeBufferMemory(...)` are acceptable first-draft source-facing names. Exact original public API spelling remains below final-audit confidence, but no safer replacement is currently supported.

LanguageMan fields:

- Evidence checked: constructor, direct lookup, copy lookup, cleanup destructor, scalar deleting wrapper, class/file docs.
- Result: constructor stores `this[1]` after final table allocation and increments `this[2]` per string; lookup helpers read `this[1]` and `this[2]`; destructors free `this[1][i]` using `this[2]`.
- Decision: `m_strings` at `+0x04` / 4 bytes and `m_stringCount` at `+0x08` / 8 bytes (Verified with `int_convert.py`) are source-quality field names for this target.

Scalar deleting destructor relationship:

- Evidence checked: live analysis of `0x004f03d0`, xrefs to `0x004f03d0`, vtable bytes, [UID:00018V].
- Result: `0x004f03d0` is size `0xa7` / 167 bytes (Verified with `int_convert.py`), pointed to from `0x0061c9e0`, duplicates the cleanup body, then checks `(flags & 1)` and `(flags & 4)`, optionally calling `OperatorDeleteWrapper` or the compiler guard no-op path with size `0x2c` / 44 bytes (Verified with `int_convert.py`).
- Decision: UID `00018V` stays no-code compiler-wrapper marker. UID `00018S` is the only page that should carry the handwritten destructor body.

`g_pLanguageMan`:

- Evidence checked: constructor decompile, destructor decompile, clear helper decompile, scalar wrapper decompile, xrefs to `0x0067a750`, memory bytes.
- Result: constructor stores the complete `LanguageMan*` to `dword_67A750`; cleanup destructor clears it at `0x004f02ef`; singleton clear helper clears it at `0x004f03c0`; scalar wrapper clears it at `0x004f0431`; storage bytes at `0x0067a750` are zero.
- Decision: existing C++ `g_pLanguageMan = 0;` is source-shaped for this codebase and era. Do not change it to `nullptr`.

Adjacent zero-initializer:

- Evidence checked: live `lookup_funcs`, `analyze_function`, `xrefs_to`, bytes, [UID:00018T], [UID:00018R], [UID:000071], [UID:0000KK].
- Result: `0x004f0310` remains a function of size `0x32` / 50 bytes (Verified with `int_convert.py`) with seven descending zero stores from `+0x24` / 36 bytes through `+0x0c` / 12 bytes (Verified with `int_convert.py`) and no callers/xrefs/callees in the current session. `0x004f0342-0x004f0350` remains fourteen `0xcc` bytes.
- Decision: this remains a support/source-placement caveat, not a destructor C++ blocker. Do not attach it to the `LanguageMan` class or name tail fields from this report.

Generated-output state:

- Evidence checked: `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and `auto-generated/NexusTK/localization/LanguageMan.cpp`.
- Result: generated rows/comments still show older `00018S` scores such as `76/84`, and the auto coverage row says `emits_code:false`; generated `LanguageMan.cpp` nevertheless contains the destructor body.
- Decision: generated/project-level state is validator-owned. Do not edit it manually. Run scoped validators with generated wait after accepted implementation.

## Evidence Standards Used

Evidence sources used:

- IDA MCP session `80de0a67`: `server_health`, `lookup_funcs`, `analyze_function`, `decompile`, `disasm`, `xrefs_to`, `get_bytes`, `entity_query`, and `find_regex`.
- Project converter: `tools/int_convert.py` for numeric conversions.
- Target/support docs: `00018S`, `00018V`, `00018T`, `00018R`, `00040P`, `00040Q`, `00040R`, `00040W`, `g_pLanguageMan`, `LanguageMan`, `LanguageManager`, `MemoryMan`, `FreeBufferMemory`, `GetMemoryMan`, and `LObjectDestructorBody`.
- Accepted B reports: B002 `00018V`, B001 `00018T`, and B007 `00018U`.
- Generated read-only evidence: current generated `LanguageMan.cpp`, research tracker, and auto memory coverage row.

The evidence ladder is strong enough for a score move because the target has live IDA behavior, source-family class/global/type corroboration, helper-body corroboration, vtable relationship, and negative checks for the alternative Boost/LanguageManager/scalar-wrapper interpretations.

## Evidence Checked

IDA MCP/manual checks performed:

- `server_health`: active database/session facts listed above.
- `lookup_funcs`: `0x004f0010` `sub_4F0010` size `0x27c`; `0x004f0290` `??1exception@boost@@MAE@XZ_3` size `0x80`; `0x004f0310` `sub_4F0310` size `0x32`; `0x004f0350` size `0x22`; `0x004f0380` size `0x3b`; `0x004f03c0` size `0xb`; `0x004f03d0` size `0xa7`; `0x004f0480` starts a separate successor function.
- `analyze_function 0x004f0290`: size 128, six basic blocks, complexity 2, no callers, callees `sub_516030`, `sub_516170`, `sub_4F4A90`, decompiled cleanup body.
- `analyze_function 0x004f03d0`: size 167, vtable ref from `0x0061c9e0`, no callers, same cleanup plus delete-flag handling.
- `analyze_function 0x004f0310`: size 50, no callers/callees, seven zero stores.
- `xrefs_to`: no xrefs to `0x004f0290`, `0x004f0310`, `0x004f0342`, or `0x004f0477`; one data xref to `0x004f03d0` from `0x0061c9e0`; three xrefs to vtable slot/base `0x0061c9e0` from constructor/destructor/scalar wrapper stores; `0x0067a750` xref count `192`.
- `get_bytes`: confirmed `0x004f028c-0x004f0290`, `0x004f0342-0x004f0350`, and `0x004f0477-0x004f0480` padding; confirmed full target/scalar/zero-helper bytes; confirmed `0x0061c9dc` vtable dwords and zero bytes at `0x0067a750`.
- `entity_query` names: found multiple stale Boost exception names including this target, and found `LanguageMan` / `Singleton<LanguageMan>` RTTI/name records; no `LanguageManager` name record in that query.
- `find_regex`: found strings `.?AVLanguageMan@@` and `.?AV?$Singleton@VLanguageMan@@@@`.

Negative checks performed:

- No direct callers or xrefs to the cleanup destructor start.
- No direct callers/xrefs to the adjacent zero-initializer start or tail boundary.
- No current-session name evidence for a standalone `LanguageManager`.
- No need for a target split: the function boundary is exact and the target range does not include padding or the zero-initializer.

Failed/unavailable checks:

- None. MCP was available. No fallback-only evidence was used.

## Inference Claim Ledger

| Claim | Confidence | Evidence | Counter-evidence checked | Next verification / remaining uncertainty |
| --- | --- | --- | --- | --- |
| `00018S` is `LanguageMan::~LanguageMan()` | Very strong | vtable store `0x0061c9e0`, `m_strings`/`m_stringCount` cleanup, `g_pLanguageMan` clear, `LObject` base cleanup, class/global docs | Active stale Boost IDA name; no direct callers | Exact original symbol spelling unavailable; final source name is inferred/source-facing |
| Existing formal C++ should remain unchanged | Strong | Live body maps directly to `GetMemoryMan`, looped `FreeBufferMemory`, table free, singleton clear; base cleanup implicit | Possible exact MemoryMan API spelling alternatives | Future MemoryMan final API audit may rename helper globally |
| Raise score to `89/92` | Strong | Current live MCP proof resolves all target-local blockers; source C++ present and source-shaped | Active stale IDA label, unresolved MemoryMan final API spelling, adjacent zero-helper fields, generated stale rows | Do not raise to final-audit level until helper API/field names/generated state fully settle |
| `00018V` must not duplicate the destructor body | Very strong | vtable-only xref, same cleanup sequence plus flags, no direct callers | Old generated `DeletingDestructor` artifacts | None for this target |
| `00018T` does not block this destructor | Strong | No xrefs/callers; zero-helper does not touch `m_strings`, `m_stringCount`, vtable, singleton, or strings | Size envelope `0x2c` makes tail-field relation plausible | Future caller/layout evidence could promote `00018T`, but not from this target |

## Positive Evidence Summary

- The live destructor decompile exactly matches the current formal C++ body except for compiler scaffolding and the implicit `LObject` base destructor.
- The current IDB exposes `LanguageMan` and `Singleton<LanguageMan>` RTTI/name records and no `LanguageManager` name evidence in the current query.
- The constructor, lookup, copy, cleanup, and scalar-wrapper functions all agree on `m_strings` at `+0x04` and `m_stringCount` at `+0x08`.
- The scalar deleting destructor proves the source/no-code split: source destructor body belongs here, compiler wrapper body belongs to `00018V`.
- `g_pLanguageMan` lifecycle evidence agrees across constructor, cleanup destructor, singleton-clear helper, and scalar wrapper.

## IDA MCP Facts

Function/range facts:

- `0x004f0290-0x004f0310`: current IDA function `??1exception@boost@@MAE@XZ_3`, size `0x80` / 128 bytes (Verified with `int_convert.py`), six basic blocks, complexity 2.
- `0x004f0310-0x004f0342`: current IDA function `sub_4F0310`, size `0x32` / 50 bytes (Verified with `int_convert.py`), no callers/callees.
- `0x004f03d0-0x004f0477`: scalar deleting wrapper, size `0xa7` / 167 bytes (Verified with `int_convert.py`).

Data/padding facts:

- `0x004f028c-0x004f0290`, `0x004f0342-0x004f0350`, and `0x004f0477-0x004f0480` are `0xcc` padding.
- `0x0061c9dc-0x0061c9ec` bytes decode to the LanguageMan complete-object locator and vtable slots, including `0x004f03d0` at `0x0061c9e0`.
- `0x0067a750` bytes are `00 00 00 00`.

Xref facts:

- `xrefs_to 0x004f0290`: zero.
- `xrefs_to 0x004f03d0`: one data xref from `0x0061c9e0`.
- `xrefs_to 0x0061c9e0`: three refs from constructor `0x004f007b`, cleanup destructor `0x004f02b7`, and scalar wrapper `0x004f03fe`.
- `xrefs_to 0x0067a750`: count `192`; representative output includes broad UI/application consumers. Destructor writes are directly visible in decompilation/disassembly.

Helper facts:

- `0x00516030`: `mov eax, dword ptr unk_69B4FC; retn`; best source-facing name `GetMemoryMan()`.
- `0x00516170`: `j___free_base(Block); return 0; retn 4`; best source-facing name `MemoryMan::FreeBufferMemory(void*)` / `FreeBufferMemory`.
- `0x004f4a90`: writes `LObject::vftable` to `this` and returns; source-facing base cleanup `LObject::~LObject`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004f0010-0x004f028c` | part of [UID:00018R] | `LanguageMan` constructor / `str.res` loader | true | [UID:000071]/[UID:0000KK] context | aggregate `88/91` | source island predecessor |
| `0x004f0290-0x004f0310` | [UID:00018S] target | source-authored non-deleting destructor body | true | [UID:000071] | recommend `89/92` | emits destructor C++ |
| `0x004f0310-0x004f0342` | [UID:00018T] | file-level zero-initializer orphan/private helper | true | [UID:0000KK] | `85/91` | not a class-method proof |
| `0x004f0350-0x004f0372` | [UID:00040P] | `GetLocalizedString` | true | [UID:000071] | child-scored | field-name corroboration |
| `0x004f0380-0x004f03bb` | [UID:00040Q] | copy-output localized string helper | true | [UID:000071] | child-scored | field-name corroboration |
| `0x004f03c0-0x004f03cb` | [UID:00040R] | file-local singleton clear helper | true | [UID:0000KK] | child-scored | lifecycle corroboration |
| `0x004f03d0-0x004f0477` | [UID:00018V] | compiler scalar deleting destructor wrapper | true | [UID:000071] | `87/92` | no-code marker only |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004f0290` | no direct callers/xrefs; callees `0x00516030`, `0x00516170`, `0x004f4a90` | Non-deleting body is not reached by static call fan-in but is source destructor logic. |
| `0x0061c9e0` | data refs from `0x004f007b`, `0x004f02b7`, `0x004f03fe`; value at slot is `0x004f03d0` | LanguageMan vtable relationship; wrapper owns vtable slot, cleanup body restores vtable during cleanup. |
| `0x0067a750` | `192` xrefs; clears at `0x004f02ef` and `0x004f0431`, clear helper `0x004f03c0`, constructor publish/fallback clear | `g_pLanguageMan` singleton lifecycle. |
| `0x004f0310` | no direct callers/xrefs/callees | Adjacent zero-helper remains a separate unresolved class-layout issue. |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- [UID:000071] `LanguageMan` documents the class layout, canonical `LanguageMan` naming, `LanguageManager` alias rejection, destructor/wrapper split, and zero-initializer caveat.
- [UID:0000KK] `LanguageMan` documents the source file contents and already lists `00018S` as the ordinary destructor body.
- [UID:00018V] documents scalar-wrapper no-code handling and helper-name resolution.
- [UID:00018T] documents the zero-helper as file-level, not class-owned.
- [UID:0001OS] and [UID:0000RC] document `g_pLanguageMan` lifecycle and complete-object pointer semantics.
- [UID:0001BC], [UID:0001BF], and [UID:000370] document the helper names used by the destructor.

Existing docs that are stale or incomplete:

- [UID:0000RC] `g_pLanguageMan` says C001 saved IDA names and that the stale Boost destructor label at `0x004f0290` is repaired in the IDB. That is not true in the active B015 MCP session `80de0a67`; the sentence should be made session-scoped/historical.
- `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and generated `LanguageMan.cpp` UID comments still show stale target scores. These are validator-owned outputs and must not be manually edited.

## Ranked Ownership Analysis

### 1. [UID:000071] LanguageMan class

- Evidence for: vtable store, source destructor role, class layout fields, constructor/destructor/lookup family, `LanguageMan` RTTI/name records, scalar-wrapper vtable slot, and current parent score `89/92`.
- Evidence against: no direct callers to the non-deleting body; active IDA name still polluted as Boost.
- Decision: keep as canonical owner/emitter. The no-caller and stale-name facts are already overcome by body/vtable/layout evidence.

### 2. [UID:0000KK] LanguageMan.cpp file

- Evidence for: final source placement is `NexusTK/localization/LanguageMan.cpp`; file owns the module and `g_pLanguageMan`.
- Evidence against: class method/destructor pages should route through the class parent when the class is known and clears the gate.
- Decision: keep as source file route through class, not direct target owner.

### 3. Boost exception / CRT / library code

- Evidence for: active IDA name `??1exception@boost@@MAE@XZ_3` and related Boost-name aliases elsewhere.
- Evidence against: body writes LanguageMan vtable, uses LanguageMan fields, clears `g_pLanguageMan`, has no Boost exception semantics, and class/global/name evidence points to LanguageMan.
- Decision: rejected. Preserve only as stale IDA alias/search evidence.

### 4. [UID:000072] LanguageManager

- Evidence for: old generated output and historical alias view around the lookup helper.
- Evidence against: no current `LanguageManager` RTTI/name evidence; lookup/destructor use the `LanguageMan` object built by `LanguageMan::LanguageMan`; [UID:000072] is ignored as alias.
- Decision: rejected as source owner/name.

### 5. MemoryMan or LObject

- Evidence for: destructor calls MemoryMan helpers and LObject base cleanup.
- Evidence against: these are callees/dependencies, not object-owner evidence.
- Decision: rejected.

## Source Placement

Recommended source placement remains:

```text
NexusTK/localization/LanguageMan.cpp
```

The source-facing destructor should be `LanguageMan::~LanguageMan()` in the `LanguageMan` class implementation. `LObject::~LObject` is implicit base-destructor behavior and should not be hand-called in the C++ body. The scalar deleting wrapper should not be handwritten.

## Range / Split / Padding / Reclassification Analysis

No split or reclassification is recommended for `00018S`.

Exact boundary facts:

- Target starts at `0x004f0290`, immediately after four `0xcc` bytes at `0x004f028c-0x004f0290`.
- Target size is `0x80` / 128 bytes (Verified with `int_convert.py`), ending exactly at `0x004f0310`.
- `0x004f0310` starts the separate zero-helper [UID:00018T], not padding and not part of the destructor.

The target is source-authored executable destructor logic and should not be merged with `00018V` or `00018T`.

## Negative Evidence Summary

- Stale Boost IDA name was checked and rejected by vtable/layout/global facts.
- `LanguageManager` was checked and rejected by current name/RTTI evidence and alias docs.
- MemoryMan/LObject direct ownership was rejected because they are callees only.
- Zero-initializer adjacency was checked and rejected as a reason to block this destructor's field names or formal C++.
- Generated tracker/coverage rows were checked and found stale, but generated staleness is not target source evidence.

## IDA Rename / Type / Comment Recommendations

No IDA DB edits are requested. The report-only assignment forbids IDA DB changes.

Source-facing names/types/comments to incorporate into docs:

- `LanguageMan::~LanguageMan()` for `0x004f0290-0x004f0310`.
- `GetMemoryMan()` for `0x00516030`.
- `MemoryMan::FreeBufferMemory(void* block)` / `FreeBufferMemory` for `0x00516170`.
- `LObject::~LObject` as the implicit base cleanup at `0x004f4a90`.
- `m_strings` at `+0x04` and `m_stringCount` at `+0x08`.
- `g_pLanguageMan` for `0x0067a750`.

Items intentionally left unresolved:

- Exact original MemoryMan public API spelling remains inferred.
- Zero-initializer tail fields `+0x0c..+0x24` remain unnamed.
- Active IDB rename state remains supervisor/IDA-maintenance-owned.

## First-Draft C++ Recommendation

Eligible for draft C++: yes. The target is reconstructable, has confirmed owner/emitter [UID:000071], and already clears the active code-entry gate.

Recommended code: keep the formal `RECONSTRUCTION_CPP CODE` block exactly as it is:

```cpp
LanguageMan::~LanguageMan()
{
    MemoryMan* memoryMan = GetMemoryMan();

    for (int i = 0; i < m_stringCount; ++i)
        memoryMan->FreeBufferMemory(m_strings[i]);

    memoryMan->FreeBufferMemory(m_strings);
    g_pLanguageMan = 0;
}
```

Reason it preserves exact original behavior:

- The binary calls `GetMemoryMan` once and reuses the returned object for all frees.
- It frees every entry in `m_strings` for `0 <= i < m_stringCount`.
- It frees the `m_strings` table itself after the loop.
- It clears `g_pLanguageMan`.
- It lets compiler-generated destructor sequencing call the `LObject` base cleanup instead of writing an explicit base call.

Reason it matches plausible original source shape:

- It is an ordinary class destructor, not a reverse-engineered `DeletingDestructor` or `sub_` wrapper.
- It uses the accepted `LanguageMan` class and field names.
- It avoids IDA raw names and decompiler temporaries.
- It uses `0`, not `nullptr`, which fits the surrounding reconstructed late-1990s/early-2000s C++ style.

Reason not to change the code:

- No live evidence supports a better source-facing MemoryMan helper name for this exact target.
- Writing `delete[]`, `free`, or an explicit `LObject::~LObject()` would be less faithful to the documented project helper and compiler behavior.

## Final Recommendation

Exact recommended changes:

- Update [UID:00018S] metadata to `89/92`; keep owner/emitter/reconstructable fields unchanged.
- Keep the formal C++ body unchanged.
- Add B015 2026-06-25 current-session evidence and score rationale to [UID:00018S].
- Update [UID:00018S] `Item Summary` so generated coverage has a concise current source summary once refreshed.
- Update [UID:0000RC] `g_pLanguageMan` to clarify the stale Boost-name repair sentence as historical/session-scoped and to record current session `80de0a67` still reports the Boost name.
- Do not change [UID:00018V], [UID:00018T], [UID:000071], [UID:0000KK], or [UID:0001OS] unless the supervisor wants optional current-session cross-notes; they already contain the relevant accepted facts at same-or-greater detail.

No new child files, split, rename, owner change, or C++ replacement is recommended.

## Recommended Target Doc Changes

Target path: `by-memory/0x004f0290-0x004f0310.LanguageManCleanupDestructor.md`

Metadata/score/owner/emitter/reconstructable/C++ changes:

- `COMPLETION:87 -> 89`
- `CONFIDENCE:91 -> 92`
- `CANONICAL_OWNER:000071` unchanged
- `RECONSTRUCTABLE:TRUE` unchanged
- `EMITTER_UIDS:000071` unchanged
- Formal C++ unchanged

Exact facts to incorporate:

- B015 MCP session `80de0a67`, server health values, and active database path.
- Current IDA still names the function `??1exception@boost@@MAE@XZ_3`; this is stale/polluted and rejected.
- `lookup_funcs` boundary map around constructor, destructor, zero-helper, lookup/copy/clear helpers, scalar wrapper, and successor.
- `analyze_function 0x004f0290` facts: size `0x80` / 128 bytes (Verified with `int_convert.py`), six basic blocks, complexity 2, no callers, callees `sub_516030`, `sub_516170`, `sub_4F4A90`, concrete cleanup operations.
- `xrefs_to` facts: no direct xrefs to `0x004f0290`; `0x0061c9e0` refs from constructor/cleanup/scalar wrapper; `0x004f03d0` only vtable data xref; `0x0067a750` broad xref count `192`.
- Helper body facts for `GetMemoryMan`, `FreeBufferMemory`, and `LObject::~LObject`.
- Current name inventory: `LanguageMan`/`Singleton<LanguageMan>` records present, no `LanguageManager` name in current query.
- Generated-state caveat: tracker/auto coverage/generated C++ comments are stale and validator-owned.
- Score rationale: raise to `89/92`; not higher because active IDB name remains stale, final MemoryMan API spelling is inferred, zero-helper tail fields remain unresolved, and generated state must refresh through validators.

Recommended concise Item Summary:

```text
Source-authored `LanguageMan::~LanguageMan` body; current MCP session 80de0a67 still shows a stale Boost IDA name, but live vtable/layout/global evidence confirms it frees `m_strings[i]`, frees the `m_strings` table through `GetMemoryMan`/`FreeBufferMemory`, clears `g_pLanguageMan`, and leaves `LObject` base cleanup implicit while the scalar deleting wrapper stays no-code.
```

## Recommended Support Doc Changes

Support path: `by-global/g_pLanguageMan.md`

Exact support correction:

- Replace or supersede the current absolute sentence:

```text
C001 applied and saved the IDA names `g_pLanguageMan`, `LanguageMan_Constructor`, `LanguageMan_CleanupDestructor`, `LanguageMan_ClearSingletonHelper`, and `LanguageMan_ScalarDeletingDestructor` after a successful dry run. The stale Boost destructor label at `0x004f0290` is now repaired in the IDB.
```

- With session-scoped wording:

```text
C001 reported applying saved IDA names for `g_pLanguageMan` and the four LanguageMan lifecycle helpers in its 2026-06-16 session. B015's 2026-06-25 live MCP session `80de0a67` still reports `0x004f0290` as `??1exception@boost@@MAE@XZ_3`, so the Boost-name repair should be treated as session/IDA-state-specific rather than guaranteed in the active IDB. The source-facing documentation remains `LanguageMan_CleanupDestructor` / `LanguageMan::~LanguageMan` because the body writes the LanguageMan vtable, uses `m_strings`/`m_stringCount`, and clears `g_pLanguageMan`.
```

Support docs already present at same-or-greater detail:

- [UID:000071] `LanguageMan.md`: already records fields, object size caveat, scalar-wrapper relationship, zero-helper caveat, and canonical `LanguageMan` naming.
- [UID:0000KK] `LanguageMan.md`: already records source placement, `00018S` destructor, `00018V` no-code wrapper, zero-helper file-level placement, and generated alias rejection.
- [UID:00018V] scalar deleting destructor: already records no-code wrapper proof and helper names.
- [UID:00018T] zero-initializer: already records the no-caller/no-xref evidence and `0x2c` size-envelope caveat.
- [UID:0001OS] `g_pLanguageMan` memory: already records the complete-object pointer clarification and destructor clear behavior.

## Score And Metadata Recommendation

Current score/metadata:

```text
COMPLETION:87
CONFIDENCE:91
CANONICAL_OWNER:000071
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:000071
```

Recommended score/metadata:

```text
COMPLETION:89
CONFIDENCE:92
CANONICAL_OWNER:000071
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:000071
```

Score rationale:

- Completion improves because this pass resolves the assignment's listed blockers with current live MCP evidence: stale Boost name rechecked, helper names revalidated, fields revalidated, scalar wrapper relationship revalidated, singleton behavior revalidated, zero-helper caveat revalidated, C++ shape revalidated, and generated-state staleness identified.
- Confidence improves because live MCP now directly corroborates the accepted B002/B007/B001 facts for this exact target rather than relying on older report evidence.
- Reason not higher: exact original MemoryMan API spelling remains inferred, active IDA still carries the stale Boost label, `00018T` tail fields remain unresolved, and generated tracker/coverage output is stale until validator refresh.

## Open Questions With Attempted Resolution

Open question: is the active Boost name repaired?

- Evidence checked: current `lookup_funcs`, `entity_query`, target/support docs.
- Resolution: no, not in session `80de0a67`; support wording must be corrected.

Open question: should MemoryMan helper spelling change?

- Evidence checked: helper docs and live helper bodies.
- Resolution: no current safer replacement. Keep `GetMemoryMan` and `FreeBufferMemory` as source-facing inferred names.

Open question: should `00018T` zero-helper change the destructor fields or score?

- Evidence checked: live zero-helper facts, B001 report, class/file docs, scalar wrapper size.
- Resolution: no. It stays a file-level orphan/private helper; it does not block `00018S` destructor source.

Open question: should generated tracker/coverage be manually repaired?

- Evidence checked: generated rows and generated C++ comments.
- Resolution: no manual edit. Use validators after accepted implementation.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

No manual coverage-report or tracker text is recommended. The stale rows are validator-owned generated outputs:

- `auto-generated/-ag-research-tracker.md`
- `auto-generated/-ag-coverage-report-by-memory.md`
- `auto-generated/NexusTK/localization/LanguageMan.cpp`

If the report is accepted and implemented, run scoped validators with generated refresh and inspect that generated output no longer shows `00018S` as `76/84` or `emits_code:false`. If it remains stale, report validator-owned stale state rather than manually editing generated files.

## Follow-Up Actions

Supervisor actions:

- Validate this report and checklist.
- If accepted, send B015 an implementation callback for only the target page and `by-global/g_pLanguageMan.md` support correction.
- After B015 implementation and validators, execute this report with the normal validator executed-report lifecycle command.

B015 implementation actions if accepted:

- Lease only `by-memory/0x004f0290-0x004f0310.LanguageManCleanupDestructor.md` and `by-global/g_pLanguageMan.md` immediately before editing.
- Apply the target score/evidence/item-summary updates and support stale-name correction.
- Run scoped validators from `source-3/project-documentation` with `--wait-generated` for both edited files.
- Update this report checklist with proof.

## Confidence

- Recommendation confidence: strong.
- Score confidence: strong for `89/92`, not final-audit.
- Remaining uncertainty: exact original MemoryMan helper public spelling, active IDA rename propagation, generated validator state staleness, and `00018T` tail-field names.

## Validator Results

Report-only pass commands: none. No target/support by-* docs were edited during the initial report.

Implementation callback validators, run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [00018S-LanguageManCleanupDestructor-source-quality-removed.md](00018S-LanguageManCleanupDestructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- Exit code: `0`
- `command_id`: `000000001667`
- `command_timestamp`: `2026-06-25T15:00:12-04:00`
- `ok`: `1`
- Generated refresh: `completed`; `generated_refresh_command_id: 000000001667`, `generated_refresh_timestamp: 2026-06-25T15:00:12-04:00`
- Target effects reported: `completion_update 00018S 89`, `confidence_update 00018S 92`, `canonical_owner_update 00018S 000071`, autogen registry updates, by-memory auto coverage update, research tracker update, generated C++ update, projected stats update.
- Remaining validator noise: missing UID refs for `00040P`/`00040Q` in this page and broader pre-existing `autogen_registry_stale` / `memory_coverage_metadata_missing_file` entries for unrelated missing files. No target validator failure.

> Executable block R002 was removed from this report and preserved verbatim in [00018S-LanguageManCleanupDestructor-source-quality-removed.md](00018S-LanguageManCleanupDestructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- Exit code: `0`
- `command_id`: `000000001672`
- `command_timestamp`: `2026-06-25T15:00:30-04:00`
- `ok`: `1`
- Generated refresh: `completed`; `generated_refresh_command_id: 000000001672`, `generated_refresh_timestamp: 2026-06-25T15:00:30-04:00`
- Support effects reported: `completion_update 0000RC 87`, `confidence_update 0000RC 92`, `canonical_owner_update 0000RC 0000KK`, autogen registry updates, research tracker update, generated metadata refresh, generated C++ update, projected stats update.
- Remaining validator noise: missing UID refs for `00040R`/`00040P`/`00040Q`/`0003O5` in the support page and broader pre-existing `autogen_registry_stale` / `memory_coverage_metadata_missing_file` entries for unrelated missing files. No support validator failure.

Generated refresh verification:

- `auto-generated/NexusTK/localization/LanguageMan.cpp` header now shows `validator-command-id: 000000001672`, `validator-refreshed-at: 2026-06-25T15:00:30-04:00`, and `UID:00018S ... Completion:89 | Confidence:92`; the destructor body is present.
- `auto-generated/-ag-coverage-report-by-memory.md` header shows `validator-command-id: 000000001672`, `validator-refreshed-at: 2026-06-25T15:00:30-04:00`; exact UID row now shows `emits_code:true`, `89%`, `very-strong`, updated `2026-06-25 15:00:13`, and the accepted Item Summary.
- `auto-generated/-ag-research-tracker.md` exact UID row now shows `00018S` at `89/92`, average `90.5`, reconstructable true. Its header shows a later deferred refresh, `validator-command-id: 000000001674`, `validator-refreshed-at: 2026-06-25T15:01:07-04:00`.
- No generated, project-level, coverage, validator state/cache, IDA DB, or tool-state files were manually edited by B015. Generated/project-level/tool-state side effects were validator-owned.

## Changed Files

Created:

- `tools/leaser/Agents/Agent-B015/research/00018S-LanguageManCleanupDestructor-source-quality.md`

Modified by B015:

- `by-memory/0x004f0290-0x004f0310.LanguageManCleanupDestructor.md`
- `by-global/g_pLanguageMan.md`
- `tools/leaser/Agents/Agent-B015/research/00018S-LanguageManCleanupDestructor-source-quality.md`

Validator-owned generated/project-state side effects observed and not manually edited:

- `auto-generated/NexusTK/localization/LanguageMan.cpp`
- `auto-generated/-ag-coverage-report-by-memory.md`
- `auto-generated/-ag-research-tracker.md`
- `project-level/-auto-completion-stats.md`
- `tools/validator.ini`
- `tools/validator_autogen_backup/20260625-150023`
- `tools/validator_autogen_backup/20260625-150048`

Leases:

- Read `tools/leaser/Agents/Agent-B015/current_leases.md` before editing; no active target/support conflict was present.
- Leased only `by-memory/0x004f0290-0x004f0310.LanguageManCleanupDestructor.md` and `by-global/g_pLanguageMan.md` as `B015` immediately before editing.
- Release command after validators returned `Success` for both files.
- Post-release `current_leases.md` / `rg` check found no active `B015`, target, or support lease entries.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Proof: supervisor accepted this report and sent implementation callback `B015-implement-00018S-language-man-cleanup-destructor-20260625`.
- [x] Target doc to update: `by-memory/0x004f0290-0x004f0310.LanguageManCleanupDestructor.md`. Proof: edited target metadata, Item Summary, B015 evidence section, and 2026-06-25 change note.
- [x] Support doc to update: `by-global/g_pLanguageMan.md`. Proof: edited C001 IDA-name repair wording and added 2026-06-25 support correction note.
- [x] Current target state and actual evidence checked to preserve: current `87/91`, owner/emitter [UID:000071], formal destructor C++, active MCP session `80de0a67`, stale Boost active IDA name, helper/body/xref/byte evidence, generated-state staleness. Proof: target now records the B015 current-session evidence section and `Changed to 89/92` note while preserving the C++ block.
- [x] Metadata/score changes to apply: `00018S` `COMPLETION:87 -> 89`, `CONFIDENCE:91 -> 92`; owner/emitter/reconstructable unchanged. Proof: target header and validator `000000001667` report `completion_update 00018S 89`, `confidence_update 00018S 92`, `canonical_owner_update 00018S 000071`.
- [x] Score-limiting blockers researched: stale Boost name rejected with current IDA facts; MemoryMan helper names revalidated; fields revalidated through constructor/lookup/destructor; scalar wrapper relationship revalidated; `g_pLanguageMan` lifecycle revalidated; zero-helper adjacency rechecked and kept as support caveat; generated rows identified as validator-owned stale state. Proof: target section `2026-06-25 B015 Current-Session Evidence`.
- [x] Owner/emitter/reconstructable changes to apply: none; keep `CANONICAL_OWNER:000071`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000071`. Proof: target header unchanged for those fields; validator confirmed canonical owner `000071`.
- [x] Split/rename/new-child changes to apply: none. Proof: no new files, no rename, no split; target documents current function inventory and separate zero-helper/scalar-wrapper pages.
- [x] Source-placement/range/padding/reclassification changes to apply: none; add current-session boundary/padding proof to target prose only. Proof: target records predecessor padding, exact target range, zero-helper boundary, scalar-wrapper boundary, and successor boundary.
- [x] IDA rename/type/comment changes to apply: none; no IDA DB edits requested. Proof: no IDA mutation or save tools were used; only read-only MCP `initialize`, `tools/list`, `idb_list`, and `server_health` were used during callback.
- [x] First-draft C++ to apply: keep existing formal `LanguageMan::~LanguageMan()` body unchanged; do not add explicit `LObject::~LObject`; do not change `g_pLanguageMan = 0`. Proof: target formal C++ block remains the accepted body; generated `LanguageMan.cpp` now emits `00018S` as `89/92`.
- [x] Exact target facts to incorporate at report-level detail: B015 MCP session, live `lookup_funcs`, `analyze_function`, `xrefs_to`, `get_bytes`, helper disasm/decompile, name inventory, score rationale, generated stale row note. Proof: target section `2026-06-25 B015 Current-Session Evidence` incorporates these facts.
- [x] Exact support facts to incorporate at report-level detail: make C001 IDA-name repair wording session-scoped and record that active B015 session still reports stale Boost name. Proof: `by-global/g_pLanguageMan.md` Evidence and Changes sections now contain that wording.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: stale Boost alias rejected, `LanguageManager` rejected, scalar wrapper no-code split preserved, zero-helper class ownership rejected, generated rows not manually edited. Proof: target and support prose preserve each decision.
- [x] Wave2/Wave3/generated-output artifacts encountered and ignored/rejected as authority: old generated `LanguageManager`/tracker/coverage score rows and stale generated UID comments. Proof: target records generated state as validator-owned and validators refreshed it; no generated manual edit.
- [x] Open questions to close/document: MemoryMan final API spelling remains inferred; `00018T` tail fields remain unresolved; generated stale state must refresh through validators. Proof: target score rationale documents the remaining MemoryMan/zero-helper limits; generated state refreshed and exact rows were inspected.
- [x] Validators to run after implementation: target by-memory validator and `by-global/g_pLanguageMan.md` validator from `source-3/project-documentation`, both with `--apply --queue-timeout 240 --wait-generated`. Proof: commands `000000001667` and `000000001672`, both exit `0`, `ok:1`, generated refresh completed.
- [x] Generated report refresh expected: yes, validator-owned; no manual coverage/tracker text supplied. Proof: generated exact UID rows now show target `89/92`, coverage `emits_code:true`; no manual coverage/tracker edits by B015.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation. Proof: current `goal.md` assignment id `B015-implement-00018S-language-man-cleanup-destructor-20260625` names this accepted report and target.
- [x] Immediate leases taken only for `00018S` target and `by-global/g_pLanguageMan.md`, then released/confirmed expired after validators. Proof: lease command returned `Success` for both files; release command returned `Success` for both files; post-release `current_leases.md` check found no active B015/target/support entries.
- [x] All accepted target/support doc details incorporated at report-level detail. Proof: target current-session evidence section and support C001 wording correction match the accepted report.
- [x] `00018S` metadata score applied and C++ preserved unchanged. Proof: target header `89/92`, owner/emitter unchanged, formal destructor body unchanged; generated C++ row now `Completion:89 | Confidence:92`.
- [x] `g_pLanguageMan.md` stale IDA-name repair wording corrected. Proof: support Evidence bullet now makes C001 wording historical/session-scoped and records active B015 stale Boost state.
- [x] Historical/stale assumptions and negative evidence preserved. Proof: target/support docs preserve stale Boost, `LanguageManager` rejection, no-code scalar-wrapper split, zero-helper caveat, and validator-owned generated state.
- [x] Scoped validators run and results recorded with `command_id`, `command_timestamp`, exit code, `ok`, generated refresh state, and side effects. Proof: Validator Results section records commands `000000001667` and `000000001672`.
- [x] Generated output inspected or generated refresh state reported for stale `76/84` / `emits_code:false` rows. Proof: generated tracker exact row now `89/92`; coverage exact row now `emits_code:true`; generated `LanguageMan.cpp` row now `89/92`.
- [x] Remaining unapplied accepted items listed with exact blocker, if any. Proof: none; all accepted items applied or already preserved at same-or-greater detail.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B015","command_id":"000000004165","destination_path":"executed-b-agent-research/B015/00018S-LanguageManCleanupDestructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B015/research/00018S-LanguageManCleanupDestructor-source-quality.md","timestamp":"2026-06-25T15:07:15","uid":"00018S"} -->
<!-- {"agent":"B015","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00018S-LanguageManCleanupDestructor-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B015/00018S-LanguageManCleanupDestructor-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00018S"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
