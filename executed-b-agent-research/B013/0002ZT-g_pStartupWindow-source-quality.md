** TARGET-REPORT-UID:0002ZT **
** AUTHOR-AGENT-ID:B013 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# Agent-B013 B-source-quality report: [UID:0002ZT] g_pStartupWindow storage

Report path: `tools/leaser/Agents/Agent-B013/research/0002ZT-g_pStartupWindow-source-quality.md`  
Target path: `by-memory/0x0069bac8-0x0069bacc.g_pStartupWindow.md`  
Assignment mode: implementation callback complete after supervisor Gate 1. The target by-memory doc plus two support docs were edited and validated; generated `StartupWindow.cpp` refreshed through scoped validators only. No manual generated edits, coverage edits, validator-state edits, supervisor-ledger edits, lifecycle/archive moves, or `execute_report` commands were run.

## Finalized Report / Current Recommendation

[UID:0002ZT] is the exact four-byte writable storage for the `StartupWindow *` singleton at `0x0069bac8-0x0069bacc`. Current MCP session `ddf5b602` confirms the storage is data, not a function; the eight-byte startup global cluster is zero-initialized; `0x0069bac8` has exactly four current xrefs; and all four xrefs match the documented singleton lifecycle: constructor publish at `0x005807e5`, ordinary destructor raw clear at `0x00580864`, WndProc read at `0x00581114`, and scalar deleting destructor wrapper clear at `0x00581d94`.

Implemented disposition: this target remains a reconstructable exact storage child owned/emitted by [UID:0002ZS][g_pStartupWindow](by-global/g_pStartupWindow.md), not a duplicate global declaration. The target is now `88/91`, still `CANONICAL_OWNER:0002ZS`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0002ZS`, with a cleaned formal no-duplicate storage marker in the target `RECONSTRUCTION_CPP CODE` block. The source declaration remains on the by-global parent as `static StartupWindow *g_pStartupWindow;`; this by-memory child documents exact storage, bytes, xrefs, lifecycle writes/reads, and the no-duplicate emission rule.

The reason UID0002ZT had no direct B report in the tracker before this artifact was lifecycle scope, not missing implementation. The executed B008 report was a broad [UID:0000O5] StartupWindow empty-emitter family report. It implemented the parent global declaration and this storage marker, but the research tracker recorded reports `0` for the exact UID0002ZT row because no UID0002ZT-specific B report had been executed.

## Supporting Research

Required reads and evidence sources:

- `tools/leaser/Agents/Agent-B013/goal.md`: assigned UID0002ZT, Medium provenance, report-only boundary, target/report paths, and required questions around singleton ownership/source quality.
- `.codex/skills/ntk-b-agent-workflow/SKILL.md` and `references/b-agent-research-and-implementation-workflow.md`: B-agent report template, source-quality requirements, no by-* edit boundary, formal C++ block rule, and MCP requirement.
- `by-structure.md` `IDA MCP Output Discipline` and rebuild-handling guidance: non-`.text` data can be source-declared/generated-binary, and MCP calls must be narrow, exact-address, paged/bounded, and schema-current.
- Target: `by-memory/0x0069bac8-0x0069bacc.g_pStartupWindow.md`.
- Direct parent/support docs: `by-global/g_pStartupWindow.md`, `by-memory/0x0069bac4-0x0069bacc.StartupWindowUpdateStateGlobals.md`, `by-file/StartupWindow.md`, `by-class/StartupWindow.md`, `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md`, `by-memory/0x005807d0-0x0058080c.StartupWindowConstructor.md`, `by-memory/0x00580810-0x00580870.StartupWindowOrdinaryDestructor.md`, `by-memory/0x00581100-0x005815aa.StartupWindowUpdateCheckWindowProc.md`, and `by-memory/0x00581d30-0x00581db2.StartupWindowScalarDeletingDestructor.md`.
- Generated read-only evidence: `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-coverage-report-by-memory.md`, `auto-generated/-ag-global-coverage.md`, and `auto-generated/NexusTK/app/StartupWindow.cpp`.
- Prior report lead opened after search: `executed-b-agent-research/B008/0000O5-StartupWindow-empty-emitter-family-source-quality.md`.

Search terms used before finalizing: `0002ZT`, `0x0069bac8`, `0x0069bacc`, `g_pStartupWindow`, `StartupWindow singleton`, `dword_69BAC8`, `StartupWindowUpdateStateGlobals`, `StartupWindow`, `0002ZS`, and `0000O5`.

## Target

- Target UID: `0002ZT`
- Target path: `by-memory/0x0069bac8-0x0069bacc.g_pStartupWindow.md`
- Current metadata after callback: `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:0002ZS`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0002ZS`, blank optional position. Pre-callback metadata was `86/88`.
- Current formal C++ block:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Exact storage for g_pStartupWindow at 0x0069bac8.
// The source declaration is emitted by [UID:0002ZS][g_pStartupWindow](by-global/g_pStartupWindow.md).
// Do not duplicate the pointer definition from this storage child.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Current generated output: `auto-generated/NexusTK/app/StartupWindow.cpp` header reports `validator-command-id: 000000006453`, `validator-refreshed-at: 2026-07-04T19:03:00-04:00`, and emits the parent declaration `static StartupWindow *g_pStartupWindow;` under UID0002ZS followed by the UID0002ZT no-duplicate storage marker at `Completion:88 | Confidence:91`. No `Empty Emitter Marker` match was found for UID0002ZT in the generated output check.
- Historical tracker state before supervisor execution: `auto-generated/-ag-research-tracker.md` listed UID0002ZT under not-covered reconstructable by-memory rows with `86/88`, `true`, reports `0`. The matching by-global parent UID0002ZS also reported `0`, because B008 executed as target UID0000O5 rather than either exact global/storage UID.

## Current Target State

The target is now callback-applied. Exact range, owner/emitter route, reconstructable storage-child state, no-duplicate marker, parent declaration route, current MCP evidence, generated freshness, UID-specific report-history rationale, and rejected alternatives are recorded in the target page.

- Current state: exact range, canonical owner [UID:0002ZS], emission route [UID:0002ZS] -> [UID:0000O5], reconstructable storage-child state, cleaned no-duplicate marker, parent cluster split, and source declaration placement on `by-global/g_pStartupWindow.md`.
- Pre-callback blocker, now resolved: the target relied mostly on older accepted B008/B011 support notes and did not carry current MCP session `ddf5b602` evidence for the exact bytes, current xrefs, WndProc read, constructor publish, scalar wrapper clear, ordinary destructor raw clear, and next-range boundary at `0x0069bacc`.
- Current source-shape conclusion: this by-memory target does not emit `static StartupWindow *g_pStartupWindow;` because that declaration already belongs to [UID:0002ZS]. The storage child is reconstructable as source-declared/generated-binary support and emits only a formal no-duplicate marker/comment.
- Score cap: exact original global spelling is inferred from project convention and docs, not symbol-proven. The address is also storage for a source declaration emitted elsewhere, so completion should remain below final/high-90s until the parent/global and all related StartupWindow globals have UID-specific report coverage.

## Heuristic / Inference Reanalysis And Validation

The main source-quality question is whether the exact storage child should emit a duplicate declaration, be reclassified no-code, move to file/class ownership, or stay as a reconstructable by-memory storage child under the by-global parent.

The current evidence supports the storage-child disposition:

- The address is live writable data, not padding or a compiler-only table. Current MCP `get_bytes 0x0069bac4 size 8` returns eight zero bytes, and `get_int` returns `0` at the atom, reserved word, and singleton pointer fields. This matches source-level zero initialization for static storage.
- The parent cluster is cleanly split. Current MCP `xrefs_to` returns four refs to `0x0069bac4`, zero refs to the interior reserved word `0x0069bac6`, four refs to `0x0069bac8`, and separate next-range refs at `0x0069bacc`. That confirms `0x0069bac8-0x0069bacc` is the final dword of the StartupWindow update-state cluster, not part of the following string-buffer pool.
- Constructor evidence proves publication. MCP decompile of `0x005807d0` writes `unk_69BAC8 = v2` after the `this == -4` guard; disassembly at `0x005807e5` is `mov dword ptr unk_69BAC8, eax`. `analyze_function` confirms the constructor is `StartupWindow__Constructor`, size `60`, with `_WinMain@16` as caller.
- WndProc evidence proves read/use. MCP `xrefs_to 0x0069bac8` includes `0x00581114` inside `sub_581100`; decompile starts with `v4 = unk_69BAC8` and falls back to `DefWindowProcA` if the singleton is null. That is the expected file-local WndProc pattern for a global receiver pointer.
- Destructor evidence proves lifecycle cleanup. The raw ordinary destructor body at `0x00580810` is still not an IDA function, but bounded disassembly shows source-shaped cleanup ending in `mov dword ptr unk_69BAC8, 0` at `0x00580864`. The scalar deleting destructor wrapper at `0x00581d30` also decompiles to `unk_69BAC8 = 0` at `0x00581d94`, followed by conditional object free.
- The source declaration is already correctly located on [UID:0002ZS]. The by-global parent owns the source-level declaration and emits it through [UID:0000O5]. Re-emitting it in this storage child would duplicate source semantics and generated output.

Rejected alternatives:

- Duplicate declaration on UID0002ZT: rejected because UID0002ZS already emits `static StartupWindow *g_pStartupWindow;`, and generated output confirms the storage child should only contribute a marker/comment.
- No-code/non-reconstructable reclassification: rejected because a source-level global declaration is required to recreate this data, even though the exact by-memory storage child must not duplicate the declaration.
- Class-only ownership: rejected because `StartupWindow` class owns the object semantics, but the source declaration is a file-static/global declaration owned by the `StartupWindow.cpp` file route through the by-global page.
- File-only ownership: rejected as too broad for the exact storage child; [UID:0000O5] is the source emitter, while [UID:0002ZS] is the direct global owner.
- Neighbor merge into [UID:0002AM] or [UID:0002AN]: rejected because current xrefs and range boundaries prove this is the singleton dword split between the atom/reserved word and string-buffer pool storage.

## Evidence Standards Used

- Direct MCP facts take precedence over generated output and older reports.
- Generated C++ is lead/freshness evidence only; it is not proof of source ownership without matching IDA/MCP and by-* documentation.
- Prior executed B reports are treated as strong leads after search-gating, but UID-specific recommendations are rechecked against current docs and MCP.
- Non-`.text` data can be reconstructable when a source declaration is needed; exact binary bytes need not be hand-authored if a C++ declaration/initializer will reproduce the storage.
- Numeric conversions are marked `(Verified with int_convert.py)` when decimal/base conversion is documented.
- Confidence remains capped when exact original source spelling is inferred rather than symbol-proven.

## Evidence Checked

MCP session and health:

- `initialize`: MCP server responded as `ida-pro-mcp`.
- `tools/list`: schema-current tool list checked; old argument names rejected for `get_bytes`, `get_int`, and `xrefs_to`, then current schemas were used (`regions`, `queries`, `addrs`).
- `idb_list`: session `ddf5b602`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, active, not analyzing, worker PID `20820`.
- `server_health ddf5b602`: `status:ok`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.

MCP storage and range checks:

- `lookup_funcs`: `0x0069bac8` is not a function; `0x005807d0` is `StartupWindow__Constructor` size `0x3c`; `0x00580810` is not a function; `0x00581100` is `sub_581100` size `0x4aa`; `0x00581d30` is `sub_581D30` size `0x82`.
- `get_bytes 0x0069bac4 size 8`: eight zero bytes.
- `get_int`: `0x0069bac4 u16le = 0`, `0x0069bac6 u16le = 0`, `0x0069bac8 u32le = 0`.
- `get_global_value`: values at `0x0069bac4`, `0x0069bac6`, and `0x0069bac8` are all `0x0`.
- `int_convert 0x4`: decimal `4` (Verified with int_convert.py). The target range `0x0069bac8-0x0069bacc` is four bytes.
- `xrefs_to` with limit `20`: four refs to `0x0069bac4`, zero refs to `0x0069bac6`, four refs to `0x0069bac8`, and four separate refs to successor address `0x0069bacc`.

MCP lifecycle refs for `0x0069bac8`:

- Constructor publish: `xrefs_to 0x0069bac8` includes `0x005807e5` in `StartupWindow__Constructor`. Decompile writes `unk_69BAC8 = v2`, installs the StartupWindow vtable, writes `byte_66DA97 = 1`, stores `this[2] = a2`, and clears state flags. Disassembly shows `mov dword ptr unk_69BAC8, eax`.
- Ordinary destructor raw clear: `xrefs_to 0x0069bac8` includes `0x00580864` with no function owner. `lookup_funcs 0x00580810` reports not a function. Bounded disassembly from `0x00580810` shows cleanup and `mov dword ptr unk_69BAC8, 0` at `0x00580864`. `get_bytes 0x0058080c size 4` returns four `0xcc` predecessor bytes.
- WndProc read: `xrefs_to 0x0069bac8` includes `0x00581114` in `sub_581100`. Decompile starts with `v4 = unk_69BAC8` and `if (!unk_69BAC8) return DefWindowProcA(...)`.
- Scalar deleting destructor wrapper clear: `xrefs_to 0x0069bac8` includes `0x00581d94` in `sub_581D30`. Decompile clears `unk_69BAC8 = 0` before conditional `sub_5C7526(Block)` object free.

Local/generated/report checks:

- Target page currently has `86/88`, owner/emitter `0002ZS`, and a no-duplicate marker.
- `by-global/g_pStartupWindow.md` currently emits `static StartupWindow *g_pStartupWindow;` plus `[[CHILDREN]]`.
- `by-memory/0x0069bac4-0x0069bacc.StartupWindowUpdateStateGlobals.md` records the three-child split for atom, reserved word, and singleton pointer.
- `by-file/StartupWindow.md` and `by-class/StartupWindow.md` already route the global to `StartupWindow.cpp` and preserve class/global lifecycle evidence.
- `auto-generated/NexusTK/app/StartupWindow.cpp` currently has header command `000000006440`, refreshed `2026-07-04T18:28:15-04:00`, emits `static StartupWindow *g_pStartupWindow;` under UID0002ZS, and contains only UID0002ZT marker comments for the storage child.
- `auto-generated/-ag-research-tracker.md` lists UID0002ZT and UID0002ZS with reports `0`.
- Executed B008 StartupWindow family report implemented this storage marker and parent global declaration as part of target UID0000O5, not as UID0002ZT-specific coverage.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-0002ZT-01 | UID0002ZT is exact four-byte storage at `0x0069bac8-0x0069bacc`, not a function. | High | MCP `lookup_funcs 0x0069bac8` not a function; `int_convert 0x4` = 4 decimal; target path/range. | Target `Status` / `Evidence` | incorporate | applied: target `Status` and `Evidence` now record exact range, not-a-function status, and four-byte size; validator `000000006447` exit `0`, ok `1`. |
| C-0002ZT-02 | The storage is zero-initialized writable global data. | High | MCP `get_bytes 0x0069bac4 size 8` all zero; `get_int 0x0069bac8 u32le = 0`; `get_global_value` returns `0x0`. | Target `Evidence`; parent cluster support | incorporate | applied: target and parent cluster now record zeroed bytes/value; validators `000000006447` and `000000006453` exit `0`, ok `1`. |
| C-0002ZT-03 | The cluster boundary is clean: refs to `0x0069bac8` are separate from atom `0x0069bac4`, reserved `0x0069bac6`, and successor `0x0069bacc`. | High | MCP `xrefs_to` returns four refs to `0x0069bac4`, zero to `0x0069bac6`, four to `0x0069bac8`, and separate next-range refs to `0x0069bacc`. | Target `Evidence`; parent cluster layout | incorporate | applied: target and parent cluster now record atom/reserved/singleton/successor xref split; validators `000000006447` and `000000006453` exit `0`, ok `1`. |
| C-0002ZT-04 | Constructor `0x005807d0` publishes the singleton pointer. | High | MCP decompile and disasm show `unk_69BAC8 = v2` / `mov dword ptr unk_69BAC8, eax` at `0x005807e5`. | Target lifecycle evidence; global parent evidence | incorporate | applied: target and global parent now record constructor publish at `0x005807e5`; validators `000000006447` and `000000006451` exit `0`, ok `1`. |
| C-0002ZT-05 | WndProc `0x00581100` reads the singleton and falls back if null. | High | MCP decompile starts with `v4 = unk_69BAC8` and null `DefWindowProcA` branch; xref at `0x00581114`. | Target lifecycle evidence; WndProc support note if stale | incorporate | applied: target and global parent now record WndProc read/null guard at `0x00581114`; WndProc doc was already sufficient and not edited. |
| C-0002ZT-06 | Ordinary destructor raw body clears the singleton at `0x00580864`. | High | MCP `lookup_funcs 0x00580810` not a function; bounded disasm shows `mov dword ptr unk_69BAC8, 0`; xref at `0x00580864`. | Target lifecycle evidence; destructor support note if stale | incorporate | applied: target and global parent now record raw ordinary destructor clear at `0x00580864`; ordinary destructor doc was already sufficient and not edited. |
| C-0002ZT-07 | Scalar deleting destructor wrapper also clears the singleton at `0x00581d94`. | High | MCP decompile of `0x00581d30` includes `unk_69BAC8 = 0`; xref at `0x00581d94`. | Target lifecycle evidence; scalar wrapper support if stale | incorporate | applied: target and global parent now record scalar wrapper clear at `0x00581d94`; scalar wrapper doc was already sufficient and not edited. |
| C-0002ZT-08 | Source declaration belongs on [UID:0002ZS], while UID0002ZT must remain a no-duplicate storage marker. | High | by-global formal block emits declaration; generated `StartupWindow.cpp` shows UID0002ZS declaration followed by UID0002ZT marker only. | Target formal C++ block; by-global support | incorporate | applied: target marker was cleaned; by-global declaration preserved unchanged; generated `StartupWindow.cpp` command `000000006453` shows declaration under UID0002ZS and marker under UID0002ZT. |
| C-0002ZT-09 | Owner/emitter should remain `CANONICAL_OWNER:0002ZS`, `EMITTER_UIDS:0002ZS`. | High | Direct storage-to-global relationship; source declaration parent; by-file/class route; generated output. | Target metadata | already-present | already-present: target metadata still has `CANONICAL_OWNER:0002ZS`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0002ZS`, blank optional position after validator `000000006447`. |
| C-0002ZT-10 | Target score should rise to `88/91` but not higher. | Medium-high | Fresh UID-specific MCP closes current-evidence gap; exact original global name and indirect source declaration keep caps. | Target metadata and score rationale | incorporate | applied: target metadata is now `COMPLETION:88`, `CONFIDENCE:91`; validator `000000006447` reported completion/confidence updates and exit `0`, ok `1`. |
| C-0002ZT-11 | UID0002ZT lacks direct tracker coverage because B008 executed as UID0000O5 family/split report. | High | `auto-generated/-ag-research-tracker.md` reports `0`; B008 report target is UID0000O5 and includes UID0002ZT as support. | Target/report history note; report final recommendation | incorporate | applied: target now records B008 family/split report history and UID-specific coverage reason; validator `000000006447` exit `0`, ok `1`. |
| C-0002ZT-12 | Reject no-code, duplicate declaration, class-only, file-only, and neighbor-merge alternatives. | High | Live xrefs/bytes, by-global declaration route, cluster split, generated output, and support docs. | Target `Evidence` / source-quality notes | incorporate | applied: target evidence now rejects duplicate declaration, no-code/non-reconstructable, class-only, file-only, aggregate-only, and neighbor-merge alternatives; validator `000000006447` exit `0`, ok `1`. |

## Positive Evidence Summary

- Current MCP session `ddf5b602` is healthy, IDB-backed, active, and Hex-Rays ready.
- Exact target range is a four-byte dword storage slot at `0x0069bac8-0x0069bacc` (Verified with int_convert.py).
- The eight-byte parent cluster is zero-initialized and split into atom/reserved/singleton roles.
- Current xrefs prove exactly four singleton lifecycle refs: constructor publish, raw ordinary destructor clear, WndProc read, and scalar deleting destructor wrapper clear.
- The WndProc null guard proves the global is the active receiver pointer used by message handling.
- Generated `StartupWindow.cpp` currently emits the declaration only once under UID0002ZS, then emits the UID0002ZT storage marker; this validates the no-duplicate source shape.
- Existing class/file/global docs already route `g_pStartupWindow` through `StartupWindow.cpp` and identify the direct by-global owner.

## Negative Evidence Summary

- No symbol/PDB/source proof recovers the exact original spelling `g_pStartupWindow`; the name is a strong source-facing inference.
- UID0002ZT is data storage, not an independent C++ declaration site; duplicating `static StartupWindow *g_pStartupWindow;` in the storage child would misrepresent source shape.
- `0x00580810` remains a raw no-function ordinary destructor body. It is valid lifecycle evidence for this storage, but its no-direct-route caveat should not be hidden.
- No direct xrefs target the reserved word `0x0069bac6`; that supports the split but does not prove a named source field between atom and singleton pointer.
- The next address `0x0069bacc` has separate refs into string-buffer/static-storage code; merging UID0002ZT into the next range would be wrong.
- Generated output is not primary evidence; it agrees with MCP and by-* docs here but should remain a freshness/route check.

## Ranked Ownership Analysis

1. [UID:0002ZS] `g_pStartupWindow` by-global parent: best direct owner. It owns the source declaration and links exact storage to the StartupWindow file route.
2. [UID:0000O5] `StartupWindow.cpp` by-file root: correct emitter route, but too broad as direct owner for the storage child because the direct source entity is the global declaration page.
3. [UID:0000DZ] `StartupWindow` class: semantically related and constructor/destructor/WndProc users are class-local, but C++ global storage is not a class member.
4. [UID:0002AM] StartupWindow update-state globals parent: useful cluster/container, but exact child and global pages now own the source declarations.
5. [UID:0001IO] StartupWindowUpdateCheck executable aggregate: rejected as owner; it uses and mutates the global through child bodies, but it is a non-emitting split/index over executable ranges.
6. String buffer/static storage at `0x0069bacc`: rejected by boundary and xref evidence.
7. No-code/compiler-generated/padding: rejected because the source declaration is required and the storage is live data with lifecycle xrefs.

## Source Placement

Source placement should remain `NexusTK/app/StartupWindow.cpp` through [UID:0000O5], with the declaration owned by [UID:0002ZS]:

```cpp
static StartupWindow *g_pStartupWindow;
```

The exact by-memory storage child [UID:0002ZT] should not emit that declaration a second time. It should retain a formal marker that says the declaration is emitted by [UID:0002ZS] and this child preserves exact storage evidence only. No new file, class member, header-only construct, or standalone raw-data definition is justified.

## First-Draft C++ Recommendation

Keep this target as a formal no-duplicate storage marker. Recommended exact target `RECONSTRUCTION_CPP CODE` insertion text:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Exact storage for g_pStartupWindow at 0x0069bac8.
// The source declaration is emitted by [UID:0002ZS][g_pStartupWindow](by-global/g_pStartupWindow.md).
// Do not duplicate the pointer definition from this storage child.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

The parent [UID:0002ZS] by-global page already carries the declaration block:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static StartupWindow *g_pStartupWindow;
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Do not paste the parent declaration into UID0002ZT, and do not blank the target block while it remains `RECONSTRUCTABLE:TRUE` with a storage-child route.

## Final Recommendation

UID0002ZT implementation callback is complete and ready for supervisor execution:

- Target metadata is now `COMPLETION:88`, `CONFIDENCE:91`.
- `CANONICAL_OWNER:0002ZS`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0002ZS`, and blank optional position were preserved.
- Target formal block was cleaned to the no-duplicate marker wording; no `static StartupWindow *g_pStartupWindow;` declaration was added to UID0002ZT.
- Target and support prose now incorporate MCP session `ddf5b602` evidence: health/session, not-a-function at storage, exact four-byte size, zeroed bytes/value, xrefs to atom/reserved/singleton/successor addresses, constructor publish, WndProc read/null guard, raw ordinary destructor clear, scalar deleting destructor clear, and generated-output freshness.
- Target prose now records the tracker-history note: B008 implemented this as part of the UID0000O5 family report, but UID0002ZT needed direct UID-specific report coverage.
- Confidence caps for inferred original spelling and source declaration emitted through the parent global were preserved.

## Recommended Target Doc Changes

For `by-memory/0x0069bac8-0x0069bacc.g_pStartupWindow.md`, these changes were applied:

1. Metadata changed from `COMPLETION:86`, `CONFIDENCE:88` to `COMPLETION:88`, `CONFIDENCE:91`.
2. Metadata unchanged: `CANONICAL_OWNER:0002ZS`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0002ZS`, blank optional position.
3. Current formal no-duplicate marker replaced with the exact block in `First-Draft C++ Recommendation`, removing the accidental trailing `g_pStartupWindow;` text from the second comment line.
4. `Evidence` expanded with current MCP facts:
   - MCP session `ddf5b602`, health OK, active `NexusTK.exe.i64` IDB;
   - target data/not-a-function status and four-byte range size (Verified with int_convert.py);
   - zeroed bytes/value at `0x0069bac8`;
   - current xrefs: `0x005807e5`, `0x00580864`, `0x00581114`, `0x00581d94`;
   - zero xrefs to reserved interior word `0x0069bac6` and separate next-range refs to `0x0069bacc`;
   - constructor decompile/disasm, WndProc decompile, raw ordinary destructor disasm, scalar wrapper decompile.
5. Source-quality note added: this storage child is source-declared/generated-binary support for the parent global declaration, not an independent declaration site and not no-code padding.
6. Report-history note added: B008 family implementation created/validated the marker under target UID0000O5, but UID0002ZT still had no direct tracker report before this artifact.
7. Rejected alternatives preserved: duplicate declaration, no-code/non-reconstructable, class-only ownership, file-only ownership, broad aggregate/cluster-only ownership, and neighbor merge.

## Recommended Support Doc Changes

Support sync was narrow:

- `by-global/g_pStartupWindow.md`: applied current MCP session `ddf5b602` evidence for four singleton xrefs, constructor publish, WndProc read/null guard, ordinary destructor raw clear at `0x00580864`, scalar wrapper clear at `0x00581d94`, and no-duplicate declaration routing. Score left unchanged because the exact original global spelling remains inferred.
- `by-memory/0x0069bac4-0x0069bacc.StartupWindowUpdateStateGlobals.md`: applied current-session xref/zero-byte refresh and no-duplicate declaration routing note. Score left unchanged because the parent cluster was already split correctly.
- `by-file/StartupWindow.md` and `by-class/StartupWindow.md`: inspected through current report evidence and prior reads; no direct stale contradiction found, so no edits.
- `by-memory/0x005807d0-0x0058080c.StartupWindowConstructor.md`, `by-memory/0x00580810-0x00580870.StartupWindowOrdinaryDestructor.md`, `by-memory/0x00581100-0x005815aa.StartupWindowUpdateCheckWindowProc.md`, and `by-memory/0x00581d30-0x00581db2.StartupWindowScalarDeletingDestructor.md`: already carried same-or-greater detail for lifecycle use sites; no edits.

No consumer docs outside the StartupWindow family are required for this callback.

## Score And Metadata Recommendation

| Path | Current | Recommended | Reason |
| --- | --- | --- | --- |
| `by-memory/0x0069bac8-0x0069bacc.g_pStartupWindow.md` | Pre-callback `86/88`, owner/emitter `0002ZS`, reconstructable true, marker C++ | Applied `88/91`, owner/emitter/reconstructable unchanged, cleaned no-duplicate marker | Fresh UID-specific MCP confirms exact storage, bytes/value, xrefs, lifecycle writes/reads, boundary split, generated route, and report-history cause. |
| `by-global/g_pStartupWindow.md` | `86/88`, owner/emitter `0000O5`, emits declaration | Unchanged score; evidence sync applied | Parent already emits correct declaration; current evidence added, but exact original name remains inferred. |
| `by-memory/0x0069bac4-0x0069bacc.StartupWindowUpdateStateGlobals.md` | `87/89`, owner/emitter `0000O5` | Unchanged score; support evidence sync applied | Parent cluster already split correctly; no need for broad reclassification. |
| `by-file/StartupWindow.md` | `89/88` | unchanged | File route already owns StartupWindow startup globals and exact child source routes. |
| `by-class/StartupWindow.md` | `88/89` | unchanged | Class route already records singleton state and lifecycle methods; global declaration is not class-owned. |

The recommended `88/91` for the target is conservative. Completion rises because current UID-specific evidence closes the stale/no-direct-report gap. Confidence rises because all current xrefs and bytes match the existing source shape. It remains below high-final confidence because original spelling is inferred and the actual declaration is deliberately emitted by the parent global page rather than this storage child.

## Open Questions With Attempted Resolution

- Why is UID0002ZT still uncovered in the research tracker? Resolved: B008 executed as UID0000O5 and implemented UID0002ZT as part of a family/split callback. The tracker still records reports `0` for UID0002ZT because it has not had its own UID-specific B report.
- Should UID0002ZT emit the pointer declaration? Resolved no: [UID:0002ZS] already emits `static StartupWindow *g_pStartupWindow;`, and generated output confirms UID0002ZT appears only as storage-marker comments.
- Should UID0002ZT become `RECONSTRUCTABLE:FALSE`? Resolved no: source-level static storage must be represented by a declaration, even though this exact child should not duplicate that declaration.
- Is `g_pStartupWindow` the original source name? Unresolved but acceptable. The name is source-facing and consistent with project style, singleton role, and existing docs. Lack of symbol proof caps confidence but does not block implementation.
- Does raw ordinary destructor `0x00580810` weaken this storage proof? No. It strengthens lifecycle proof by clearing the global at `0x00580864`; the no-function/no-direct-route caveat belongs to UID0004CR source reconstruction, not to UID0002ZT ownership.

## Validator Results

Callback validators were run from `source-3/project-documentation` for every changed by-* doc:

> Executable block R001 was removed from this report and preserved verbatim in [0002ZT-g_pStartupWindow-source-quality-removed.md](0002ZT-g_pStartupWindow-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- Target validator: command `000000006447`, timestamp `2026-07-04T19:02:27-04:00`, exit `0`, ok `1`. Reported completion update to `88`, confidence update to `91`, registry/research tracker/projected stats/generated refresh effects, and generated refresh completed.
- Global parent validator: command `000000006451`, timestamp `2026-07-04T19:02:43-04:00`, exit `0`, ok `1`. Reported reference-index additions, stats row/projected stats/generated refresh effects, and generated refresh completed.
- Cluster parent validator: command `000000006453`, timestamp `2026-07-04T19:03:00-04:00`, exit `0`, ok `1`. Reported projected stats/generated refresh effects, and generated refresh completed.
- Validator warnings/known side effects: repeated project-wide generated metadata refreshes, `autogen_children_marker_missing`, `autogen_children_fallback_insert`, and `autogen_emitter_has_no_code` diagnostics on unrelated docs; no UID0002ZT-specific validation error.

Generated freshness after validators: `auto-generated/NexusTK/app/StartupWindow.cpp` reports `validator-command-id: 000000006453`, `validator-refreshed-at: 2026-07-04T19:03:00-04:00`, `validator-refresh-source: foreground-generated-refresh`. It shows UID0002ZS declaration `static StartupWindow *g_pStartupWindow;`, UID0002ZT at `Completion:88 | Confidence:91`, the cleaned no-duplicate marker comments, no UID0002ZT empty marker, constructor assignment `g_pStartupWindow = this`, destructor clear `g_pStartupWindow = NULL`, and WndProc read `StartupWindow *startupWindow = g_pStartupWindow`.

## Changed Files

Implementation callback changed:

- `tools/leaser/Agents/Agent-B013/research/0002ZT-g_pStartupWindow-source-quality.md`
- `by-memory/0x0069bac8-0x0069bacc.g_pStartupWindow.md`
- `by-global/g_pStartupWindow.md`
- `by-memory/0x0069bac4-0x0069bacc.StartupWindowUpdateStateGlobals.md`
- `auto-generated/NexusTK/app/StartupWindow.cpp` refreshed by validator infrastructure only; not manually edited.

Generated reports and validator metadata refreshed through scoped validators; no generated file was manually edited. No coverage reports, supervisor ledgers, lifecycle/archive files, or executed-report registries were edited.

Leases used and released: `by-memory/0x0069bac8-0x0069bacc.g_pStartupWindow.md`, `by-global/g_pStartupWindow.md`, and `by-memory/0x0069bac4-0x0069bacc.StartupWindowUpdateStateGlobals.md` were leased by B013 for the edit/validator batch and unleased immediately afterward. A post-release lease check found no B013/UID0002ZT entries.

## Implementation Tracking Checklist

- [x] Target metadata updated in `by-memory/0x0069bac8-0x0069bacc.g_pStartupWindow.md`: `COMPLETION:88`, `CONFIDENCE:91`, owner `0002ZS`, reconstructable true, emitter `0002ZS`.
- [x] Target formal C++ marker replaced with the exact no-duplicate storage block from `First-Draft C++ Recommendation`; no duplicate `static StartupWindow *g_pStartupWindow;` declaration added to UID0002ZT.
- [x] Target evidence updated with MCP session `ddf5b602`, health/session facts, target not-a-function status, zeroed bytes/value, and four-byte size (Verified with int_convert.py).
- [x] Target evidence records current `xrefs_to` results for `0x0069bac4`, `0x0069bac6`, `0x0069bac8`, and `0x0069bacc`.
- [x] Target lifecycle evidence records constructor publish at `0x005807e5`, WndProc read/null guard at `0x00581114`, raw ordinary destructor clear at `0x00580864`, and scalar wrapper clear at `0x00581d94`.
- [x] Target prose preserves confidence caps for inferred original global spelling and parent-emitted source declaration.
- [x] Target prose rejects duplicate declaration, no-code/non-reconstructable, class-only, file-only, broad aggregate/cluster-only ownership, and neighbor merge alternatives.
- [x] Target prose explains why UID0002ZT lacked a UID-specific executed B report despite B008 family/split implementation.
- [x] `by-global/g_pStartupWindow.md` updated with current-session lifecycle evidence and no-duplicate declaration routing; score intentionally left unchanged.
- [x] Parent/support StartupWindow docs inspected/updated only if stale: `by-memory/0x0069bac4-0x0069bacc.StartupWindowUpdateStateGlobals.md` received current-session split evidence; `by-file/StartupWindow.md`, `by-class/StartupWindow.md`, constructor, ordinary destructor, WndProc, and scalar wrapper docs were already sufficient and not edited.
- [x] Scoped validators run for every changed by-* doc from `source-3/project-documentation`: commands `000000006447`, `000000006451`, and `000000006453`, each exit `0`, ok `1`.
- [x] Generated `auto-generated/NexusTK/app/StartupWindow.cpp` freshness checked after validation: header `000000006453`, refreshed `2026-07-04T19:03:00-04:00`, UID0002ZS declaration plus UID0002ZT marker comments and no UID0002ZT empty marker.
- [x] Claim And Incorporation Ledger verification states updated from `proposed` to `applied` or `already-present`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B013","command_id":"000000006478","destination_path":"executed-b-agent-research/B013/0002ZT-g_pStartupWindow-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B013/research/0002ZT-g_pStartupWindow-source-quality.md","timestamp":"2026-07-04T19:12:10-04:00","uid":"0002ZT"} -->
<!-- {"agent":"B013","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002ZT-g_pStartupWindow-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B013/0002ZT-g_pStartupWindow-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002ZT"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
