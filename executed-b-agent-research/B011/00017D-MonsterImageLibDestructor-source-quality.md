** TARGET-REPORT-UID:00017D **
** AUTHOR-AGENT-ID:B011 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00017D MonsterImageLibDestructor Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: update [UID:00017D] `by-memory/0x004db010-0x004db0f7.MonsterImageLibDestructor.md` from file-owned blank-C++ routing to class-owned formal method emission through [UID:00008N] `MonsterImageLib`.
- Final disposition: ordinary non-deleting `MonsterImageLib::~MonsterImageLib()` destructor body. It should emit source-level destructor C++ for the handwritten body, while preserving evidence that vptr restore, member destruction, base destruction, singleton-base teardown, EH state, and checked allocator helpers are compiler-lowered output.
- Required action after supervisor validation: change target metadata to `90/91`, `CANONICAL_OWNER:00008N`, `EMITTER_UIDS:00008N`, keep `RECONSTRUCTABLE:TRUE`, insert the exact formal C++ block below, and synchronize the related `MonsterImageLib` support docs.
- Confidence: high. Live IDA MCP after the outage confirms exact function boundaries, cleanup order, vtable/singleton xrefs, scalar-deleting destructor parity, helper identities, and post-body padding. Remaining uncertainty is class-declaration polish, not the destructor body source shape.

## Target

- Target UID: [UID:00017D]
- Target path: `by-memory/0x004db010-0x004db0f7.MonsterImageLibDestructor.md`
- Assignment id: `B011-report-00017D-monster-image-lib-destructor-20260625`
- Source queue: `auto-generated/-ag-research-tracker.md`, by-memory not-covered reconstructable queue.
- Current target metadata: `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000LJ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000LJ`, blank formal C++.
- Current support route: [UID:00008N] `MonsterImageLib` class routes through [UID:0000LJ] `MonsterImageLib` file and `NexusTK/render/MonsterImageLib.cpp`.

## Current Target State

The target already documents the right binary role: ordinary non-deleting `MonsterImageLib` destructor at `0x004db010-0x004db0f7`, cleanup parity with scalar deleting destructor [UID:0003M1] at `0x004e6750-0x004e6860`, `ClearLoadedData`, `MonsterImageEntry` vector cleanup, two embedded `DATIndexVector` destructors, archive-offset vector cleanup, `LObject` base cleanup, singleton clear, no direct xrefs, and `0xcc` post-body padding.

The current blockers are stale under Rule 26:

- Owner/emitter is too broad. This is a class method; direct owner/emitter should be [UID:00008N] `MonsterImageLib`, not direct file [UID:0000LJ].
- The blank C++ rationale says archive-offset, cache-table, and entry field names are not final enough. Current support docs now resolve enough source-facing names for a first draft: loader C++ uses `m_monsters`/`m_monsterCount`; layout/type docs provide `m_archiveOffsets`, `m_openArchiveIndex`, `m_boundsBucketIndex`, `MonsterImageEntry`, `ImageAnimationGroup`, and `ImageAnimationFrame` vocabulary.
- Generated reports are stale: `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and `auto-generated/NexusTK/render/MonsterImageLib.cpp` still show `76/86` and an empty marker for [UID:00017D]. These must be refreshed through scoped validators after by-* edits, not by manual generated-file edits.

## Supervisor Active Recheck

The supervisor restored MCP after a prior outage. I redid the MCP-backed evidence pass after restoration and did not use fallback-only outage evidence. Current MCP provenance:

- Endpoint: `http://127.0.0.1:13337/mcp`
- `initialize` JSON-RPC id `201`: HTTP 200, server `ida-pro-mcp` version `1.0.0`, protocol `2025-06-18`.
- `tools/list` JSON-RPC id `202`: HTTP 200; live tools include `server_health`, `idb_list`, `lookup_funcs`, `decompile`, `disasm`, `xrefs_to`, `callees`, `get_bytes`, `get_int`, and `analyze_function`.
- `idb_list` JSON-RPC id `203`: active session `80de0a67`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `26892`, `is_active:true`.
- `server_health` JSON-RPC id `204`: `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, Hex-Rays ready, auto-analysis ready, strings cache ready.

No MCP write/edit tools were used.

## Evidence Checked

IDA MCP checks after restoration:

- `lookup_funcs` id `205`: `0x004db010` -> `sub_4DB010` size `0xe7` / 231 bytes (Verified with `int_convert.py`); `0x004db0f7` is not a function; next function `0x004db100`; scalar deleting destructor `0x004e6750` size `0x110` / 272 bytes (Verified with `int_convert.py`); `ClearLoadedData` `0x004dc2e0`; `DATIndexVector` destructor `0x004573d0`; `LObject` destructor body `0x004f4a90`; constructor `0x004daec0`; archive helpers `0x004dbc60` and `0x004dbe60`.
- `decompile` ids `208-211`: ordinary destructor, scalar deleting destructor, `ClearLoadedData`, and constructor.
- `disasm` ids `214` and `232`: target destructor and constructor setup/order.
- `get_bytes` id `217`: ordinary destructor tail bytes at `0x004db0f0`, scalar tail bytes at `0x004e6858`, vtable dwords at `0x0061b6e0`, singleton storage at `0x0069b440`.
- `get_int` id `216`: vtable slot `0x0061b6e4` value decimal `5138256`, verified as `0x004e6750` with `int_convert.py`; singleton storage currently `0`.
- `callees` id `225`: ordinary destructor calls `0x004dc2e0`, vector destructor iterator, `0x005c7910`, `0x004573d0`, `0x005c7526`, `0x004f4a90`, and invalid-parameter failure; scalar peer adds `0x004f4ac0` and guard helper.
- `xrefs_to` id `226`: zero xrefs to ordinary destructor entry; scalar destructor has one vtable-slot data xref; vtable `0x0061b6e4` has constructor/destructor/scalar vptr refs; singleton `0x0069b440` has 22 lifecycle/consumer refs; `ClearLoadedData` has ordinary destructor, scalar destructor, and external cache-clear callers.
- `decompile` ids `227-230`: `DATIndexVector` destructor, `LObject` destructor body, `MonsterImageEntry` row destructor, and singleton clear helper.
- `xrefs_to` id `231`: `DATIndexVector` destructor callers include this destructor twice and scalar peer twice; `MonsterImageEntry` row destructor has target/scalar/helper refs; singleton clear helper has one constructor cleanup-table xref at `0x005ffd87`.
- `analyze_function` ids `233-234`: ordinary destructor has size 231, 13 basic blocks, cyclomatic complexity 2, no callers; scalar peer has size 272, 17 basic blocks, cyclomatic complexity 4.

Docs checked:

- Target [UID:00017D].
- [UID:00008N] `by-class/MonsterImageLib.md`.
- [UID:0000LJ] `by-file/MonsterImageLib.md`.
- [UID:0003M1] scalar deleting destructor peer.
- [UID:0001VD] `MonsterImageLibLayout`.
- [UID:0001VC] `MonsterImageEntry`.
- [UID:0000RR] `g_pMonsterImageLib`.
- [UID:0001Y7] `MonsterImageLibVtable`.
- [UID:00017C] local method cluster.
- [UID:0000XU] `DATIndexVectorDestructor`.
- [UID:000370] `LObjectDestructorBody`.
- [UID:000181] singleton clear helper.
- [UID:00003K]/[UID:0000IP] `DATIndexVector` class/file.
- Generated read-only reports and `auto-generated/NexusTK/render/MonsterImageLib.cpp`.

No Wave2/Wave3 source was used as authority. Existing generated output was treated as stale lead/state only.

## IDA MCP Facts

Function and boundary facts:

- `sub_4DB010` is exactly `0x004db010-0x004db0f7`, size `0xe7` / 231 bytes (Verified with `int_convert.py`).
- Disassembly id `214` reports 79 function instructions in `.text`.
- Normal epilogue is `pop ebp; retn` at `0x004db0f0-0x004db0f1`; cold invalid-parameter call starts at `0x004db0f2` and its final operand byte is at `0x004db0f6`; `0x004db0f7-0x004db100` is `0xcc` alignment.
- `sub_4E6750` is exactly `0x004e6750-0x004e6860`, size `0x110` / 272 bytes (Verified with `int_convert.py`). Raw bytes at `0x004e6858` show `retn 4`, a cold invalid-parameter call, and `0xcc` padding before the next function.

Cleanup order facts:

1. `0x004db036`: restore `MonsterImageLib` vtable pointer at `this+0`.
2. `0x004db03c`: call `ClearLoadedData` (`0x004dc2e0`).
3. `0x004db041-0x004db070`: if `m_monsters` is non-null, run the MSVC vector destructor iterator with element size `0x0c` / 12 bytes (Verified with `int_convert.py`) and row destructor `0x00528950`, then free the array cookie block.
4. `0x004db078-0x004db083`: destroy `this+0x3c` then `this+0x1c` through `DATIndexVector::~DATIndexVector`.
5. `0x004db088-0x004db0c9`: release `m_archiveOffsets` begin/end/capacity storage and zero the triplet.
6. `0x004db0d2`: call [UID:000370] `LObject` destructor body.
7. `0x004db0d7`: clear `g_pMonsterImageLib`.

Scalar-deleting parity:

- The scalar peer repeats the same cleanup order at `0x004e677d-0x004e681e`, then tests delete flags and optionally calls `0x004f4ac0`.
- Vtable data at `0x0061b6e4` points to `0x004e6750`, and xrefs to `0x0061b6e4` are exactly constructor store `0x004daf16`, ordinary destructor restore `0x004db036`, and scalar destructor vptr restore `0x004e677d`.

Singleton/source-shape fact:

- Constructor disassembly id `232` publishes `g_pMonsterImageLib` through a `this+4` subobject sequence at `0x004daeef-0x004daefe` before the `LObject` base initializer call at `0x004daf11`.
- Destructor disassembly clears `g_pMonsterImageLib` after `LObject` cleanup at `0x004db0d2`.
- This symmetric before-base-construction / after-base-destruction pattern is not the source shape of a normal statement inside `MonsterImageLib::~MonsterImageLib()`. It is best explained as compiler-lowered singleton base/static-lifetime cleanup for the class. Therefore formal destructor C++ must not manually write `g_pMonsterImageLib = 0`.

## Heuristic / Inference Reanalysis And Validation

### Owner and emitter route

Best inference: direct owner/emitter is [UID:00008N] `MonsterImageLib`.

Evidence:

- The target is a full method body of `MonsterImageLib`, not a file-local free helper.
- It restores `MonsterImageLib` vtable `0x0061b6e4`, calls class cleanup `ClearLoadedData`, destroys object members, and has cleanup parity with the scalar vtable slot.
- [UID:00008N] is `86/88` and [UID:0000LJ] is `86/86`, so the class-to-file route clears the 85/85 gate.
- The scalar deleting peer [UID:0003M1] is already class-owned/emitted through [UID:00008N], and the ordinary destructor should not be broader than its vtable wrapper.

Rejected alternatives:

- Direct file owner [UID:0000LJ]: valid source root but too broad for `CANONICAL_OWNER`; it should remain the final generated file root reached through the class.
- No-owner/non-emitting: rejected because the class owner and emitter route are above gate and the source method body is now defensible.
- Scalar deleting destructor ownership: rejected because [UID:0003M1] is compiler ABI wrapper output; this target is the ordinary destructor body the source should model.

### Field and helper names

Best source-facing names for the destructor:

- `m_monsters`: accepted by [UID:0002JN] formal loader C++ and corresponds to target offset `+0x04`.
- `m_monsterCount`: accepted by loader C++ and corresponds to target offset `+0x08`.
- `MonsterImageEntry`: existing [UID:0001VC] row type, size 12.
- `m_archiveOffsets`: source-level `std::vector`-like member represented by offsets `+0x10/+0x14/+0x18`.
- `m_openArchiveIndex`: embedded `DATIndexVector` at `+0x1c`.
- `m_boundsBucketIndex`: embedded `DATIndexVector` at `+0x3c`.
- `ClearLoadedData`: established class method at `0x004dc2e0`.

The older `monsterEntries`, `archiveOffsetsBegin/End/Capacity`, `openArchiveIndex`, and `boundsBucketIndex` names remain useful layout aliases, but support docs should sync them with the `m_` member names now used in formal method C++.

### C++ source shape

The safe formal source body is:

- `ClearLoadedData();`
- `delete[] m_monsters;`

Why this is safe:

- `ClearLoadedData()` is the first meaningful class cleanup call in the destructor.
- The loader formal C++ allocates `m_monsters` with `new MonsterImageEntry[monsterCount]`; `delete[] m_monsters` explains the array-cookie read, 12-byte row stride, row destructor `0x00528950`, and array free in the target.
- No source `m_monsters = 0` statement is needed; the binary does not zero `this+0x04` after the array free.
- `m_boundsBucketIndex`, `m_openArchiveIndex`, and `m_archiveOffsets` cleanup is compiler-emitted member destruction after the destructor body.
- `LObject` cleanup and singleton clear are compiler-emitted base teardown, not handwritten statements inside this method body.

Rejected C++ alternatives:

- `g_pMonsterImageLib = 0;` inside the destructor body: rejected because binary order places the clear after `LObject` base cleanup, which a normal destructor body statement cannot express. Constructor order also indicates singleton base/static-lifetime machinery.
- Manually calling `m_boundsBucketIndex.~DATIndexVector()`, `m_openArchiveIndex.~DATIndexVector()`, or freeing `m_archiveOffsets`: rejected because these are member destructor outputs, not source-authored destructor statements.
- Handwritten scalar deleting destructor wrapper: rejected because [UID:0003M1] should be regenerated from the virtual destructor/class declaration.
- Leaving formal C++ blank: rejected because the target is reconstructable, above the code-entry gate, has a confirmed class emitter route, and source-facing member names are now adequate.

## Inference Claim Ledger

| Claim | Confidence | Evidence | Counter-evidence checked | Remaining uncertainty |
| --- | --- | --- | --- | --- |
| `00017D` is the ordinary `MonsterImageLib::~MonsterImageLib()` body | High | vtable restore, `ClearLoadedData`, member cleanup, scalar peer parity, no direct entry xrefs | scalar peer and singleton helper checked separately | exact original destructor declaration spelling is assumed ordinary C++ |
| Direct owner/emitter should be `00008N` | High | class method body, class parent above gate, scalar peer already class-routed | direct file and no-owner alternatives rejected | none material |
| Formal source body should be `ClearLoadedData(); delete[] m_monsters;` | High | live decompile/disasm order, loader `new[]`, row destructor and array-cookie free | global clear/member/base manual statements rejected | full class declaration still needs later polish |
| Singleton clear is compiler-lowered base/static-lifetime cleanup, not a destructor-body statement | Medium-high | constructor publishes through `this+4` before `LObject`; destructor clears after `LObject` | simple handwritten global assignment rejected by C++ destruction order | exact template/base declaration name not fully formalized |
| Support docs need member-name synchronization | High | loader C++ uses `m_monsters`/`m_monsterCount`; layout docs still use older aliases | keeping raw/decompiler names rejected | exact public/private declaration still future class-level work |

## Positive Evidence Summary

- Current MCP function and raw-byte evidence reconfirms the exact range and padding.
- Current MCP decompilation and disassembly agree on cleanup order.
- Current MCP xrefs tie vtable `0x0061b6e4` to constructor, ordinary destructor, and scalar deleting destructor only.
- Current MCP `xrefs_to 0x0069b440` reports 22 lifecycle/consumer refs, including this destructor and scalar peer.
- Current support docs now contain accepted source-facing names for `m_monsters`, `MonsterImageEntry`, `ImageAnimationGroup`, `ImageAnimationFrame`, `DATIndexVector`, and `LObject`.
- The existing [UID:0002JN] loader C++ allocates `m_monsters` with `new[]`, making `delete[] m_monsters` the natural source counterpart.

## Negative Evidence Summary

- `xrefs_to 0x004db010` returns zero direct xrefs, so no external caller proves a standalone helper/function owner.
- No evidence supports a file-local helper owner; all meaningful object state belongs to `MonsterImageLib`.
- No evidence supports manually emitting scalar-delete flag logic in this target.
- No evidence supports keeping raw names such as `sub_4DB010`, `sub_4573D0`, `unk_69B440`, or `this[1]` in final C++.
- The global clear cannot be safely written as a destructor body statement because its binary position is after base cleanup.

## Ranked Ownership Analysis

### 1. [UID:00008N] MonsterImageLib

- Evidence for: method body operates on `MonsterImageLib` object state, restores class vtable, uses class cleanup/member layout, and has scalar peer in class vtable.
- Evidence against: final class declaration still has some field/header caveats, but these do not block method ownership.
- Decision: accept as direct owner and emitter.

### 2. [UID:0000LJ] MonsterImageLib file

- Evidence for: final generated source root, resource/file ownership, and current target routing.
- Evidence against: too broad for direct semantic owner under current `CANONICAL_OWNER` rules.
- Decision: keep as final file root through class route; do not use as direct owner.

### 3. [UID:0003M1] scalar deleting destructor peer

- Evidence for: same cleanup sequence plus delete flag handling.
- Evidence against: compiler-generated vtable wrapper, not source-authored ordinary destructor body.
- Decision: cross-reference only; keep peer blank/no-code.

### 4. No-owner/non-emitting

- Evidence for: old blank-C++ blocker and class declaration caveats.
- Evidence against: target is reconstructable, above gate, and has defensible formal method source.
- Decision: reject.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. `RECONSTRUCTABLE:TRUE`; confirmed nonblank class emitter route; recommended score average is above 85; exact range is a full method body.
- Recommended code: insert exactly this formal block content into the target after supervisor acceptance:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
MonsterImageLib::~MonsterImageLib()
{
    ClearLoadedData();
    delete[] m_monsters;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Reason it preserves behavior:

- `ClearLoadedData()` accounts for the first cleanup call at `0x004db03c`.
- `delete[] m_monsters` accounts for the row destructor iterator and array free at `0x004db041-0x004db070`.
- Compiler-generated member destructors account for `m_boundsBucketIndex`, `m_openArchiveIndex`, and `m_archiveOffsets` cleanup.
- Compiler-generated base destruction accounts for `LObject` cleanup and singleton clear from the singleton subobject/static-lifetime route.

Style and names:

- Uses existing class-style names from the accepted loader C++: `m_monsters`, `ClearLoadedData`, and `MonsterImageLib::~MonsterImageLib`.
- Avoids raw labels and decompiler temporaries.
- Keeps source concise and plausible for Visual C++ era class code.

## Score And Metadata Recommendation

Current:

- `COMPLETION:86`
- `CONFIDENCE:88`
- `CANONICAL_OWNER:0000LJ`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000LJ`
- blank formal C++

Recommended:

- `COMPLETION:90`
- `CONFIDENCE:91`
- `CANONICAL_OWNER:00008N`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00008N`
- `EMITTER_POSITION_OPTIONAL:` unchanged blank
- `Nested:-4` unchanged unless validator reports a scoped issue
- formal C++ block above

Score rationale:

- Completion rises because owner/emitter routing is corrected, field/helper name blockers are resolved enough for formal source, scalar peer relationship is rechecked, and generated-output staleness is identified for validator refresh.
- Confidence rises because current MCP after the outage reconfirmed every high-impact binary fact and support docs now agree on source-facing names.
- Not higher than 91 because the full `MonsterImageLib` class declaration, exact singleton-base spelling, and exact member declaration visibility/order still need a class-level final declaration pass.

## Recommended Target Doc Changes

Target: `by-memory/0x004db010-0x004db0f7.MonsterImageLibDestructor.md`

Apply:

- Header metadata exactly as recommended above.
- Formal C++ block exactly as supplied above.
- Item Summary update to: `Ordinary MonsterImageLib destructor body; live MCP confirms exact range, cleanup order, scalar-deleting parity, vtable/singleton refs, helper callees, and formal source body ClearLoadedData plus delete[] m_monsters with member/base/singleton teardown compiler-lowered.`
- Status update: direct owner/emitter [UID:00008N], generated route through [UID:0000LJ].
- Behavior update: distinguish source-authored destructor body (`ClearLoadedData(); delete[] m_monsters;`) from compiler-generated vptr restore, member destructors, base destructor, singleton subobject cleanup, EH, and allocator guard output.
- Layout notes update: `+0x04` is source member `m_monsters`; `+0x08` is `m_monsterCount`; `+0x10/+0x14/+0x18` are `m_archiveOffsets` vector internals; `+0x1c` is `m_openArchiveIndex`; `+0x3c` is `m_boundsBucketIndex`.
- Evidence update: add current MCP command ids and facts from this report.
- Reconstruction Notes update: remove old "leave C++ blank until field names are final" blocker and replace with the formal C++ source-shape proof.
- Changes entry: record B011 2026-06-25 source-quality report, owner/emitter correction, score raise, formal C++ insertion, and post-restoration MCP evidence.

## Recommended Support Doc Changes

`by-class/MonsterImageLib.md`:

- Update status/owner-emitter note to say method-level formal C++ now exists for [UID:0002JN] `LoadMonsterTables` and should be added for [UID:00017D] `MonsterImageLib::~MonsterImageLib`; whole-class declaration C++ remains a separate declaration-polish task.
- Update destructor method row to mention source body `ClearLoadedData(); delete[] m_monsters;`, with member/base/singleton teardown compiler-lowered.
- Add a 2026-06-25 B011 destructor source sync note with the current MCP facts and owner/emitter correction.
- Keep class metadata unchanged at `86/88`, `CANONICAL_OWNER:0000LJ`, `EMITTER_UIDS:0000LJ` unless supervisor chooses a broader class-declaration pass.

`by-file/MonsterImageLib.md`:

- Add a 2026-06-25 destructor source sync note: [UID:00017D] now routes through [UID:00008N] and contributes formal `MonsterImageLib::~MonsterImageLib()` C++ to `NexusTK/render/MonsterImageLib.cpp`.
- State that scalar deleting destructor [UID:0003M1] remains blank generated wrapper output.
- State that generated `76/86` rows are stale and should refresh from source metadata through scoped validator.

`by-type/by-struct/MonsterImageLibLayout.md`:

- Synchronize source-facing member names with formal method C++:
  - `+0x04` `m_monsters` (older alias `monsterEntries`)
  - `+0x08` `m_monsterCount` (older alias `monsterEntryCount`)
  - `+0x10/+0x14/+0x18` `m_archiveOffsets` vector internals (`begin/end/capacity`)
  - `+0x1c` `m_openArchiveIndex`
  - `+0x3c` `m_boundsBucketIndex`
- Add destructor source-shape note: target C++ explicitly deletes `m_monsters`; `m_archiveOffsets` and the two `DATIndexVector` members are compiler-emitted member destruction.

`by-memory/0x004dac40-0x004dc420.MonsterImageLibLocalMethodCluster.md`:

- Update the active function row for `0x004db010-0x004db0f7` to say the exact destructor child now has formal C++ and class owner/emitter.
- Update reconstructability notes that currently imply [UID:00017D] stays blank until final gate.

`by-memory/0x004e6750-0x004e6860.MonsterImageLibScalarDeletingDestructor.md`:

- Add support note that ordinary destructor [UID:00017D] now supplies the source body; scalar peer remains blank because the virtual destructor/class declaration regenerates the deleting wrapper and delete-flag logic.
- No metadata or C++ change required.

`by-global/g_pMonsterImageLib.md`:

- Add lifecycle clarification: the writes/clears remain observed at constructor/destructor/scalar/helper addresses, but [UID:00017D] formal C++ should not contain `g_pMonsterImageLib = 0`; current constructor/destructor ordering indicates singleton base/static-lifetime cleanup.
- Preserve the source-global owner route unless a separate singleton-template/global ownership pass changes it.

`by-type/by-vtable/MonsterImageLibVtable.md`:

- Add a short note that [UID:00017D] now carries ordinary destructor source, while slot `+0x00` [UID:0003M1] remains source-declared/generated-binary scalar deleting wrapper output.
- No metadata or C++ change required.

No support edit is required for [UID:0001VC] `MonsterImageEntry`, [UID:0000XU] `DATIndexVectorDestructor`, or [UID:000370] `LObjectDestructorBody` beyond confirming their current facts are already sufficient.

## Validator / Generated Refresh Plan

After accepted implementation, run scoped validators from `source-3/project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [00017D-MonsterImageLibDestructor-source-quality-removed.md](00017D-MonsterImageLibDestructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Generated refresh expectation:

- `auto-generated/NexusTK/render/MonsterImageLib.cpp` should stop showing the stale `Completion:76 | Confidence:86 | Empty Emitter Marker` for [UID:00017D] and should include the formal destructor block routed through [UID:00008N].
- `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-research-tracker.md`, and `auto-generated/-ag-coverage-report-by-memory.md` should refresh from source metadata; do not hand-edit them.
- If generated output remains stale after the target validator, use validator queue status or scoped autogen refresh per supervisor/tooling direction instead of editing generated files or validator state.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

None. No manual `-coverage-report.md` edits are requested. Generated tracker and coverage rows should refresh from source metadata through validators.

## Open Questions With Attempted Resolution

- Exact original singleton base/template spelling: not fully proven. Current constructor/destructor order strongly proves the singleton clear should not be a handwritten destructor-body statement. This does not block the method C++ because the formal body does not mention the singleton.
- Exact full class declaration: still not final. This affects whole-class C++ and header polish, not the target method source body.
- `m_archiveOffsets` exact container type: source-shaped as vector-like from the begin/end/capacity triplet. It is not referenced in the target formal body, so it does not block the destructor source block.
- Exact original names for `m_openArchiveIndex` and `m_boundsBucketIndex`: current names are inferred but well supported by cache roles. They are support-doc names and not present in the destructor formal body.

## Changed Files

Created:

- `tools/leaser/Agents/Agent-B011/research/00017D-MonsterImageLibDestructor-source-quality.md`

Modified:

- None outside the Agent-B011 research folder.

Leases:

- None. Report-only pass; no by-* docs edited.

Validators:

- None run. Report-only pass; validators are listed for the implementation callback.

## Implementation Tracking Checklist

Implementation callback pass:

- [x] Supervisor validation required before implementation.
  - Proof: supervisor callback accepted this report for implementation and updated `Agent-B011/goal.md` with assignment `B011-implementation-00017D-monster-image-lib-destructor-20260625`.
- [x] Update target `by-memory/0x004db010-0x004db0f7.MonsterImageLibDestructor.md` metadata to `COMPLETION:90`, `CONFIDENCE:91`, `CANONICAL_OWNER:00008N`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00008N`, blank emitter position, unchanged `Nested:-4` unless validator reports otherwise.
  - Proof: target header now has `90/91`, owner/emitter `00008N`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_POSITION_OPTIONAL`, and `Nested:-4`. Validator command `000000001848` at `2026-06-25T17:27:33-04:00` recorded completion/confidence/owner/autogen registry updates; final target rerun `000000001865` at `2026-06-25T17:30:38-04:00` returned `ok: 1`.
- [x] Insert the exact formal `RECONSTRUCTION_CPP CODE` block from this report into the target.
  - Proof: target formal block now contains exactly:
    ```cpp
    MonsterImageLib::~MonsterImageLib()
    {
        ClearLoadedData();
        delete[] m_monsters;
    }
    ```
    Generated `auto-generated/NexusTK/render/MonsterImageLib.cpp` contains the same body at the [UID:00017D] insertion point.
- [x] Update target Item Summary, Status, Behavior, Layout Notes, Evidence, Reconstruction Notes, Cross-References if needed, Score Rationale, and Changes with the current MCP evidence and source-shape distinction between handwritten body and compiler-lowered teardown.
  - Proof: target now records B011 MCP session `80de0a67`, command ids `205`, `208-211`, `214`, `216-217`, `225-234`, cleanup/order facts, source-authored body, compiler-lowered member/base/singleton teardown, rejected alternatives, and a 2026-06-25 B011 change entry.
- [x] Update `by-class/MonsterImageLib.md` method inventory/status and add B011 destructor source sync: [UID:00017D] now emits `MonsterImageLib::~MonsterImageLib()` through the class; whole-class declaration remains separate.
  - Proof: status and destructor method row now mention [UID:00017D] formal method C++ through [UID:00008N], and a new `2026-06-25 Destructor Source Sync` section records owner/emitter, source body, MCP facts, compiler-lowered teardown, scalar-wrapper policy, and whole-class declaration caveat. Final validator rerun `000000001866` at `2026-06-25T17:30:53-04:00` returned `ok: 1`.
- [x] Update `by-file/MonsterImageLib.md` with file-route source sync, generated-stale note, and scalar wrapper distinction.
  - Proof: new `2026-06-25 Destructor Source Sync` section records the class-routed source root, formal destructor contribution to `MonsterImageLib.cpp`, generated-stale note, scalar-wrapper generated-binary policy, and rejected direct file semantic owner. Final validator rerun `000000001867` at `2026-06-25T17:30:58-04:00` returned `ok: 1`.
- [x] Update `by-type/by-struct/MonsterImageLibLayout.md` to synchronize member names `m_monsters`, `m_monsterCount`, `m_archiveOffsets`, `m_openArchiveIndex`, and `m_boundsBucketIndex`, preserving older aliases where useful.
  - Proof: layout block and field table now use the `m_` member names with older aliases preserved; notes connect `delete[] m_monsters` to the formal destructor and member/base/static-lifetime teardown to compiler output. Final validator rerun `000000001868` at `2026-06-25T17:31:05-04:00` returned `ok: 1`.
- [x] Update `by-memory/0x004dac40-0x004dc420.MonsterImageLibLocalMethodCluster.md` to remove stale "destructor remains blank" wording for [UID:00017D].
  - Proof: Item Summary, active-function row, and reconstructability notes now say [UID:00017D] has formal class-routed C++ while the aggregate remains non-emitting. Validator command `000000001855` at `2026-06-25T17:28:38-04:00` returned `ok: 1` and updated stale UID path `00017C` from the old broad `0x004dac40-0x004e685f` path to the live local-method-cluster path.
- [x] Update `by-memory/0x004e6750-0x004e6860.MonsterImageLibScalarDeletingDestructor.md` to say the ordinary destructor now supplies the source body and the scalar wrapper remains generated/blank.
  - Proof: Item Summary, Status, Behavior, Evidence Notes, and Changes now state [UID:00017D] supplies ordinary destructor source C++ and this scalar deleting destructor remains source-declared/generated-binary blank wrapper output. Validator command `000000001856` at `2026-06-25T17:29:27-04:00` returned `ok: 1` and registered UID `0003M1`.
- [x] Update `by-global/g_pMonsterImageLib.md` with lifecycle clarification: observed clears remain, but formal destructor C++ should not manually write the singleton.
  - Proof: write-evidence row for `0x004db0d7` and new `Destructor Source-Shape Clarification` section record the observed clear as compiler-lowered singleton subobject/static-lifetime cleanup and preserve the no-manual-`g_pMonsterImageLib = 0` policy. Final validator rerun `000000001869` at `2026-06-25T17:31:11-04:00` returned `ok: 1`.
- [x] Update `by-type/by-vtable/MonsterImageLibVtable.md` with ordinary-destructor source versus scalar-wrapper generated-binary policy.
  - Proof: Rebuild Notes and Changes now distinguish [UID:00017D] ordinary destructor source C++ from [UID:0003M1] scalar deleting wrapper output. Validator command `000000001859` at `2026-06-25T17:29:44-04:00` returned `ok: 1`; it retained one unrelated pre-existing missing target warning for [UID:00025I].
- [x] Confirm [UID:0001VC] `MonsterImageEntry`, [UID:0000XU] `DATIndexVectorDestructor`, and [UID:000370] `LObjectDestructorBody` already contain sufficient support facts; do not edit unless implementation finds a direct stale statement.
  - Proof: [UID:0001VC] already documents `MonsterImageEntry`, `m_monsters`-compatible row layout, accepted group/frame field names, and row destructor cleanup. [UID:0000XU] already documents `DATIndexVector::~DATIndexVector` shared container teardown and MonsterImageLib destructor callsites. [UID:000370] already documents the `LObject` base destructor body. No content edits were required for these support facts. Validator command `000000001861` at `2026-06-25T17:30:05-04:00` was run on [UID:000370] only to register its existing UID/path after earlier scoped scans reported `missing_ref_uid 000370`; it returned `ok: 1`.
- [x] Preserve rejected alternatives: direct file owner as semantic owner, no-owner/non-emitting, handwritten scalar wrapper, manual member/base destructor calls, and manual `g_pMonsterImageLib = 0` in target C++.
  - Proof: target Reconstruction Notes and Change entry explicitly reject all five alternatives; class/file/global/vtable/scalar support pages preserve the same distinctions.
- [x] Run the scoped validator commands listed above and report command ids, timestamps, exit codes, ok counts, generated-refresh state, and any warnings.
  - Proof: all validator processes exited `0` and reported `ok: 1`.
  - Initial listed validators: target `000000001848` `2026-06-25T17:27:33-04:00` `--wait-generated` completed generated refresh; class `000000001852` `17:28:20`; file `000000001853` `17:28:25`; layout `000000001854` `17:28:32`; aggregate `000000001855` `17:28:38`; scalar `000000001856` `17:29:27`; global `000000001857` `17:29:32`; vtable `000000001859` `17:29:44`.
  - Support UID registration validator: `by-memory/0x004f4a90-0x004f4a97.LObjectDestructorBody.md` command `000000001861` `2026-06-25T17:30:05-04:00`.
  - Final reference-refresh validators after UID registration: target `000000001865` `17:30:38` `--wait-generated`; class `000000001866` `17:30:53`; file `000000001867` `17:30:58`; layout `000000001868` `17:31:05`; global `000000001869` `17:31:11`.
  - Warnings/side effects: target/aggregate validators reported broad pre-existing `autogen_registry_stale` and `memory_coverage_metadata_missing_file` warnings. Aggregate command `000000001855` also updated stale validator path state for [UID:00017C] and reported a validator-driven UID-link update in `by-memory/-coverage-report.md`; this was not a manual coverage edit. Vtable command `000000001859` still reports unrelated missing target [UID:00025I] for old `ImageLibraryReadOnlyData` path.
- [x] Confirm generated refresh for `auto-generated/NexusTK/render/MonsterImageLib.cpp` and generated `-ag-*` reports is equal/newer than the target validator command before implementation is returned; if stale, report the exact validator/generated-refresh blocker.
  - Proof: queue status command `000000001870` at `2026-06-25T17:31:18-04:00` showed `queued generated refresh jobs: 0` and `processing generated refresh jobs: 0`.
  - `auto-generated/NexusTK/render/MonsterImageLib.cpp` header is `validator-command-id: 000000001869`, `validator-refreshed-at: 2026-06-25T17:31:11-04:00`, and contains [UID:00017D] `MonsterImageLib::~MonsterImageLib()` with `ClearLoadedData(); delete[] m_monsters;`.
  - `auto-generated/-ag-memory-coverage.md` header is `000000001865` and row [UID:00017D] is `coded` with owner/emitter `00008N`.
  - `auto-generated/-ag-research-tracker.md` header is `000000001869` and row [UID:00017D] is `90/91`.
  - `auto-generated/-ag-coverage-report-by-memory.md` header is `000000001865` and row [UID:00017D] has `emits_code:true`, `90%`, `very-strong`, and the updated item summary.
- [x] Do not edit generated files, project-level files, manual coverage reports, validator state/cache, lease files, or IDA DB by hand.
  - Proof: no manual edits were made to generated files, project-level files, coverage reports, validator state/cache, lease files, or the IDA DB. Required validators produced validator-owned generated/project-level/registry side effects and one reported manual coverage UID-link side effect during `00017C` path repair; no hand edits were made to those files.
- [x] Short scoped leases acquired only for immediate by-* edit/validator batches and released immediately after edit/validator batch.
  - Proof: B011 leased only the listed target/support docs for immediate edits and validators, plus [UID:000370] for support UID registration. Release command succeeded for active leases on target, class, file, layout, global, and LObject support; aggregate/scalar/vtable release attempts returned `Rejected[No active lease]` because those earlier leases had already expired or were not active. The final lease report showed no active B011 leases.
- [x] All accepted target/support doc details incorporated at report-level detail or explicitly marked already present/stale/not applicable.
  - Proof: target/support docs listed above incorporate the accepted facts. [UID:0001VC], [UID:0000XU], and [UID:000370] were already sufficient; only [UID:000370] needed validator registration, not content changes.
- [x] Report checklist updated with checked items and proof after implementation.
  - Proof: this checklist update records files, validator commands, generated refresh, lease state, and side effects.
- [x] Remaining unapplied accepted items listed with exact blocker, if any.
  - Proof: no accepted target/support documentation item remains unapplied. Residual warnings are validator/project-state side effects outside the accepted 00017D documentation content: broad stale autogen registry rows/missing metadata warnings, the pre-existing vtable [UID:00025I] missing target path, and the validator-driven `by-memory/-coverage-report.md` UID-link side effect from repairing [UID:00017C] path state.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B011","command_id":"000000004165","destination_path":"executed-b-agent-research/B011/00017D-MonsterImageLibDestructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B011/research/00017D-MonsterImageLibDestructor-source-quality.md","timestamp":"2026-06-25T17:37:52","uid":"00017D"} -->
<!-- {"agent":"B011","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00017D-MonsterImageLibDestructor-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B011/00017D-MonsterImageLibDestructor-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00017D"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
