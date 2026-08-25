** TARGET-REPORT-UID:0003Z3 **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **

# UID0003Z3 LivingObjectPaneSpriteConfigHelpers Source-Quality Report

## Finalized Report / Current Recommendation

UID0003Z3 remains a source-emitting LivingObjectPane file cluster through UID0000KU. After supervisor Gate 1 acceptance, B008 applied the report-backed recommendation: the target is now `COMPLETION:88`, `CONFIDENCE:90`, keeps `CANONICAL_OWNER:0000KU`, keeps `RECONSTRUCTABLE:TRUE`, keeps `EMITTER_UIDS:0000KU`, preserves blank emitter position, and carries the refreshed formal C++ plus support text reflecting the current MCP evidence.

The highest-value correction was not ownership. Current MCP evidence proves that `0x0053a6b0` is a direction-remap helper with six cross-family callers, including MapPane/UserPane movement paths, so B008 historicalized the stale "file-local/static LivingObjectPane opposite-direction helper" wording. The helper is now documented as a shared/free source helper, consistent with existing MapPane formal C++ that calls `RemapMovementDirectionForMapScroll(direction)`, while the rest of UID0003Z3 remains LivingObjectPane sprite/render state code emitted through `NexusTK/map/LivingObjectPane.cpp`.

The second correction was range-shape evidence. The bytes after `0x0053a6db` are not plain alignment only: MCP shows a switch jump table for `sub_53A6B0`, padding, and an unowned/no-xref code-shaped island at `0x0053a6f0-0x0053a6fb` (`cmp [ecx+0x1cc],9; setnb al; retn`) before the next modeled function at `0x0053a700`. That island has no function, decompile, xref route, vtable route, or owner proof, so B008 documented it as non-emitted proof inside the target range rather than forcing it into callable C++.

## Supporting Research

This artifact was originally produced as a report-only B008 UID0003Z3 assignment. After supervisor Gate 1 acceptance, B008 completed the implementation callback: target/support by-* docs were updated, scoped validators ran for every edited by-* file, and generated LivingObjectPane output refreshed through validator-owned side effects. B008 did not edit generated files manually, did not edit coverage reports or supervisor ledgers, and did not run `execute_report`, lifecycle, archive, registry, probing, or dry-run execute commands.

Project documentation reviewed locally:

- Target: `by-memory/0x0053a6b0-0x0053aae9.LivingObjectPaneSpriteConfigHelpers.md`.
- Direct source route/support: `by-file/LivingObjectPane.md`, `by-class/LivingObjectPane.md`, `by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md`.
- Vtable support: `by-memory/0x00620978-0x00620a38.LivingObjectPaneVtableData.md`.
- Caller/source-placement support: `by-memory/0x005058b0-0x0050593e.MapPaneScrollViewportByDirection.md`, `by-memory/0x00509030-0x00509439.MapPaneMovementTimerHandler.md`, `by-memory/0x00506980-0x00506ad4.MapPaneUpdateObjectPaneScreenBounds.md`, and `by-memory/0x005a5a90-0x005a5b79.LivingObjectPaneWarpToPosition.md`.
- Global support: `by-global/g_activeMapPane.md`, `by-global/g_pNewHumanImageLib.md`, `by-global/g_pMonsterImageLib.md`, and `by-global/g_pTimerMgr.md`.
- Prior research: executed B001 UID0001DE LivingObjectPaneCore source-quality report, executed B001 UID00007B LivingObjectPane class report, executed B007 UID0000KU LivingObjectPane file/family report, executed B001 UID0002R2 LivingObjectPane render-frame methods report, executed B002 MapPane movement object update report, and executed B007 UID0002R1 LivingObjectPane animation timer report.

IDA MCP was reachable and usable. The current active IDB session used by this report was `nexustk_supervisor_20260704` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; `server_health` reported `status: ok`, `auto_analysis_ready:true`, and `hexrays_ready:true`.

## Target

- UID: `0003Z3`
- Target doc: `by-memory/0x0053a6b0-0x0053aae9.LivingObjectPaneSpriteConfigHelpers.md`
- Current target metadata after callback: `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000KU`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KU`, blank emitter position.
- Current emitted file route: `by-file/LivingObjectPane.md` / `auto-generated/NexusTK/map/LivingObjectPane.cpp`.
- Current formal block after callback: exact report C++ exists for `RemapMovementDirectionForMapScroll`, `LivingObjectPane::GetRenderBounds`, `GetSpriteConfig`, `SetSpriteConfig`, and `InitializeSpriteConfig`, with the no-function island documented as non-callable C++ proof.

## Current Target State

The current target is above the code-emission threshold and is not an empty-emitter blocker. It emits refreshed formal C++ through UID0000KU. Historical pre-callback issues and their current dispositions are:

- The target item summary is now populated with the source-ready helper cluster summary.
- `0x0053a6b0` is now described as shared/free `RemapMovementDirectionForMapScroll`, not a file-local/static LivingObjectPane member.
- The range table now splits `0x0053a6dc` switch-table proof, `0x0053a6f0-0x0053a6fb` no-function/no-xref island proof, and padding.
- The formal C++ now uses current global routes such as `g_activeMapPane`, `g_pNewHumanImageLib`, `g_pMonsterImageLib`, and `g_pTimerMgr`.
- `SetSpriteConfig` now returns the final active-MapPane invalidation/update result in the formal C++.
- IDA still has no recovered `LivingSpriteConfig` or `NxRect` UDTs, so the formal C++ remains first-draft source reconstruction rather than final type recovery.

## Heuristic / Inference Reanalysis And Validation

The original owner/emitter heuristic was mostly correct: UID0003Z3 belongs under the LivingObjectPane source family because four of the five modeled routines operate on `this` fields in the LivingObjectPane sprite/render state region and one routine is a LivingObjectPane vtable target. The current evidence does not support moving the target to MapPane, UserPane, NewHumanImageLib, MonsterImageLib, TimerMgr, or a no-owner bucket.

The heuristic weakness is the first raw function. `0x0053a6b0` has no `this` receiver and has six callers from movement paths. Existing MapPane documentation already consumes it as `RemapMovementDirectionForMapScroll`. Therefore it should be documented as a shared/free helper emitted through the LivingObjectPane file route because it is physically clustered with and already emitted in the LivingObjectPane helper page, not as a private LivingObjectPane member or pure file-local helper.

The range heuristic also needed correction. The target range does contain modeled helper bodies, but it also contains compiler switch-table data and one code-shaped no-function island. The right source-quality response is to document the raw island and keep it out of formal C++ until reachability/ownership proof appears, while still improving the modeled source bodies.

## Evidence Standards Used

This report used the B-agent source-quality standard from `ntk-b-agent-workflow`: ownership and source placement require positive evidence from calls, receivers, fields, vtables, globals, source-route docs, and negative evidence against plausible alternatives. C++ recommendations are treated as formal target block insertion text, not examples. After callback implementation, every ledger action below records an applied, already-present, or excluded-with-reason state.

MCP evidence was kept narrow and address-scoped: `idb_list`, `server_health`, `lookup_funcs`, `func_profile`, `xrefs_to`, `get_bytes`, `disasm`, `decompile`, `type_query`, and `entity_query` were used only for the target functions, immediate range boundaries, vtable slot bytes, and directly referenced globals/types.

## Evidence Checked

- MCP live session: `nexustk_supervisor_20260704`, NexusTK IDB, Hex-Rays ready.
- Function starts checked: `0x0053a6b0`, `0x0053a700`, `0x0053a8c0`, `0x0053a900`, `0x0053a9f0`, successor `0x0053aaf0`.
- Non-function/range checks: `0x0053a6dc`, `0x0053a6f0`, `0x0053a6fb`, target end `0x0053aae9`.
- Xrefs checked for all five modeled function starts and for `0x006209cc`.
- Bytes checked at pre-target padding, each inter-function gap, the switch-table region, the no-function island, target end padding, and vtable slot bytes.
- Decompiled bodies checked for all five modeled functions.
- Type evidence checked for `LivingSpriteConfig`, `NxRect`, and generic `Rect` names.
- Local docs and executed reports checked for source-route, field, global, vtable, and caller support.
- Generated/project-level reports were read only for freshness and coverage state; they were not edited.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
|---|---|---:|---|---|---|---|
| C-0003Z3-01 | Keep UID0003Z3 owned/emitted through UID0000KU `LivingObjectPane.cpp`; do not move to MapPane/UserPane/global/no-owner. | 93 | Current target metadata, file/class/core support, four member-like functions using LivingObjectPane state, vtable data ref to `0x0053a700`. | Target metadata/status plus `by-file/LivingObjectPane.md` file-route note and `by-class/LivingObjectPane.md` support note. | applied | applied: target kept `0000KU`; support docs updated/validated by commands `000000006352`, `000000006366`, `000000006367`. |
| C-0003Z3-02 | Raise target score to `COMPLETION:88`, `CONFIDENCE:90`. | 90 | MCP verifies modeled functions, xrefs, bytes, decompile, globals, vtable slot; remaining UDT/name/island uncertainty caps score. | Target metadata and score rationale. | applied | applied: target validator `000000006352` recorded completion/confidence updates to `88/90`, exit 0, `ok:1`. |
| C-0003Z3-03 | Replace blank item summary with target-specific source-ready summary. | 91 | Current item summary was blank; evidence supports source-ready helper cluster and documented raw island. | Target `Item Summary`. | applied | applied: target summary now names helper cluster, shared/free remap, vtable method, no-xref island, global routes, and C++; validator `000000006352` passed. |
| C-0003Z3-04 | Historicalize `0x0053a6b0` as not merely file-local/static LivingObjectPane helper; recommend shared/free `RemapMovementDirectionForMapScroll`. | 92 | MCP xrefs to six callsites in `sub_5058B0`, `sub_50BCE0`, `sub_5A83B0`; MapPane support already uses that source-facing name. | Target formal C++ and narrative; support `by-file/LivingObjectPane.md`, `by-class/LivingObjectPane.md`, core page. | applied | applied: target/support docs now use shared/free `RemapMovementDirectionForMapScroll`; validators `000000006352`, `000000006366`, `000000006367`, `000000006368` passed. |
| C-0003Z3-05 | Preserve modeled LivingObjectPane methods for render bounds, sprite-config copy, set, and initialize. | 92 | Decompiles for `0x0053a700`, `0x0053a8c0`, `0x0053a900`, `0x0053a9f0`; fields `+0x178` through sprite/render state; callers/vtable evidence. | Target formal C++ block. | applied | applied: formal block replaced with accepted methods; generated output now shows UID0003Z3 at `88/90` under command `000000006367`. |
| C-0003Z3-06 | Correct `SetSpriteConfig` return shape to return final active-MapPane invalidation/update result rather than unconditional false. | 89 | MCP decompile returns `sub_506980(dword_67A764,this)`; UID0004DS and WarpToPosition support document same final invalidation pattern. | Target formal C++ block and target evidence notes. | applied | applied: target C++ now returns `g_activeMapPane->InvalidateObject(this)` and target behavior/evidence notes state the return semantics; validator `000000006352` passed. |
| C-0003Z3-07 | Update global aliases to current global docs: `g_activeMapPane`, `g_pNewHumanImageLib`, `g_pMonsterImageLib`, `g_pTimerMgr`. | 90 | Global by-* pages tie raw `dword_67A764`, `dword_67A760`, `dword_69B440`, `dword_67AB80` to those source routes. | Target formal C++ and documentation evidence; global pages checked as already-present support. | applied / already-present | applied in target formal C++ and touched-field/global notes; global pages were already sufficient and not edited; validator `000000006352` passed. |
| C-0003Z3-08 | Document `0x0053a6db-0x0053a6ef` as switch jump-table/lowered switch data plus padding, not plain alignment. | 96 | MCP bytes show NOP and jump-table entries; `xrefs_to 0x0053a6dc` reports jump-table data xref from `0x53a6bc`. | Target range table and split analysis; core page padding/split support. | applied | applied: target/core split notes now identify switch-table support at `0x0053a6dc-0x0053a6ef`; validators `000000006352` and `000000006368` passed. |
| C-0003Z3-09 | Document `0x0053a6f0-0x0053a6fb` as no-function/no-xref code-shaped island and do not emit a callable C++ helper for it. | 91 | `lookup_funcs`, `func_profile`, `xrefs_to`, `decompile`, and disasm checked; no function/xrefs/decompile route. | Target range table, formal C++ comment, split analysis, negative evidence. | applied | applied: target formal block contains no-callable-helper comment and target/core support mark the island no-code; validators `000000006352` and `000000006368` passed. |
| C-0003Z3-10 | Keep first-draft UDT names provisional because IDA has no `LivingSpriteConfig` or `NxRect` type. | 87 | `type_query *LivingSprite*` returned zero; `type_query *NxRect*` returned zero; generic Rect hits were not project UDT proof. | Target rationale, score blockers, open questions. | applied | applied: target status/evidence and score rationale keep UDT spelling unresolved while retaining first-draft C++; validator `000000006352` passed. |
| C-0003Z3-11 | Support `0x006209cc -> 0x0053a700` vtable slot evidence in LivingObjectPane vtable docs if missing. | 90 | MCP xrefs_to `0x0053a700` includes data ref at `0x006209cc`; vtable bytes at `0x006209c8` show `... 00 a7 53 00 ...`. | `by-memory/0x00620978-0x00620a38.LivingObjectPaneVtableData.md`. | applied | applied: vtable support row and change note added; validator `000000006354` passed with existing missing-ref warnings. |
| C-0003Z3-12 | Preserve rejected alternatives: not MapPane owner, not global owner, not padding-only, not no-owner, not broad parent body, not immediate separate child creation. | 91 | Caller/field/vtable/global/range checks distinguish dependencies and raw islands from owner/source route. | Target negative evidence, support notes, final recommendation. | applied / excluded-with-reason | applied in target rejected alternatives and support docs; child creation excluded because callback did not authorize a split and report evidence recommends documentation/no-code island proof only. |

## Positive Evidence Summary

- MCP `lookup_funcs` identifies five modeled functions inside the target: `sub_53A6B0` size `0x2b`, `sub_53A700` size `0x1b7`, `sub_53A8C0` size `0x3e`, `sub_53A900` size `0xee`, and `sub_53A9F0` size `0xf9`; successor `sub_53AAF0` begins at `0x0053aaf0`.
- MCP decompile for `0x0053a6b0` proves the direction remap table: `1 -> 3`, `2 -> 0`, `3 -> 1`, default/other including `0 -> 2`.
- MCP xrefs to `0x0053a6b0` show six code references: `0x5058c6`, `0x50be3b`, `0x5a843a`, `0x5a8515`, `0x5a857a`, and `0x5a862a`, proving the helper is not isolated to one local LivingObjectPane method.
- Existing MapPane support already uses the source-facing name `RemapMovementDirectionForMapScroll(direction)` for the `0x0053a6b0` dependency.
- MCP xrefs to `0x0053a700` show one code ref at `0x005a885c` and a vtable/data ref at `0x006209cc`; vtable bytes confirm the slot contains `0x0053a700`.
- `0x0053a700` decompile reads the active MapPane global, tests the sprite config kind, dispatches to NewHuman/Monster image-library frame-bound calls, adjusts bounds through MapPane/object-screen helpers, and writes image/screen rect outputs.
- `0x0053a8c0` decompile copies exactly four 16-byte chunks plus one dword from `this+0x178` into the output, matching a 68-byte sprite config copy.
- `0x0053a900` decompile copies config state, conditionally preserves/updates movement, cancels timers, calls the animation helper for kind `1`, stores facing, invokes virtual slot `+0x78`, and returns the active MapPane object-bounds/invalidation helper result.
- `0x0053a9f0` decompile initializes config/facing/movement/frame state, invokes virtual slot `+0x78`, schedules a timer through `g_pTimerMgr` when kind `1`, and resets BoxRotator-related fields.
- Current generated `auto-generated/NexusTK/map/LivingObjectPane.cpp` is refreshed by validator command `000000006307` and contains UID0003Z3 as emitted C++ rather than an empty-marker target.

## Negative Evidence Summary

- `0x0053a6b0` is not a LivingObjectPane member method: MCP prototype is `char __stdcall(char)`, no receiver is used, and callers include MapPane/UserPane movement paths.
- UID0003Z3 should not be reassigned to MapPane: MapPane consumes the direction-remap helper and invalidation helpers, but the main modeled cluster operates on LivingObjectPane sprite state and includes a LivingObjectPane vtable method.
- UID0003Z3 should not be assigned to NewHumanImageLib, MonsterImageLib, TimerMgr, or global pages: those are dependencies used by the methods, not owners of the source body.
- The range is not padding-only and not a no-owner raw-data span; five real functions are decompiled and currently source-emitting.
- `0x0053a6db-0x0053a700` is not pure alignment; it contains switch-table data and a no-function code-shaped island that require explicit documentation.
- `0x0053a6f0-0x0053a6fb` should not be emitted as a callable source helper in this pass because it has no function record, no direct xrefs, no decompile route, and no established source name.
- The target should not paste broad LivingObjectPane parent/class bodies; it owns only the exact helper cluster in `0x0053a6b0-0x0053aae9`.
- Exact final UDT names for `LivingSpriteConfig` and `NxRect` are not proven by IDA types; current names remain documentation-level reconstruction.

## Ranked Ownership Analysis

1. `0000KU` / `by-file/LivingObjectPane.md` - best owner/emitter. The target is already routed through LivingObjectPane.cpp, four modeled functions use LivingObjectPane sprite/render state, and one function is a LivingObjectPane vtable target. The mixed free-helper plus member-method shape is a file/source-family cluster rather than a pure class-only method group.
2. `00007B` / `by-class/LivingObjectPane.md` - strong semantic support but not the best canonical owner for this by-memory page. The render/sprite methods belong to the class, but the `0x0053a6b0` free remap helper and raw range-island evidence make the file owner a better aggregate route.
3. MapPane/UserPane movement owners - rejected. They call the direction-remap helper and MapPane invalidation/update helpers, but they do not own the sprite-config methods or vtable method.
4. Image-library/global owners - rejected. `g_pNewHumanImageLib`, `g_pMonsterImageLib`, `g_activeMapPane`, and `g_pTimerMgr` are external collaborators only.
5. No-owner/non-emitting - rejected. The target already has a valid owner/emitter and source C++ for most of the range.

## Source Placement

Recommended source placement remains `NexusTK/map/LivingObjectPane.cpp` through UID0000KU. The page should keep a mixed helper-cluster source shape:

- Emit `RemapMovementDirectionForMapScroll` as a free helper in the LivingObjectPane source route, not as `LivingObjectPane::OppositeDirection`.
- Emit `LivingObjectPane::GetRenderBounds`, `LivingObjectPane::GetSpriteConfig`, `LivingObjectPane::SetSpriteConfig`, and `LivingObjectPane::InitializeSpriteConfig` as LivingObjectPane methods.
- Keep `0x0053a6f0-0x0053a6fb` as documented no-code proof inside the range until a future route is proven.

This placement matches current generated output while fixing stale helper naming and range-shape notes. It also preserves broader file/class caveats from UID0000KU/UID00007B reports: final class layout, exact UDT names, and project-wide global alias harmonization are outside this single target.

## Range / Split / Padding / Reclassification Analysis

Recommended range ownership remains `0x0053a6b0-0x0053aae9`, but the internal table needs correction:

- `0x0053a6b0-0x0053a6db`: function `sub_53A6B0`, source-facing `RemapMovementDirectionForMapScroll`, `__stdcall`-style byte direction remap.
- `0x0053a6db`: one NOP following the helper body.
- `0x0053a6dc-0x0053a6ef`: switch jump-table entries for `sub_53A6B0` plus padding; MCP xref shows the table reference from `0x0053a6bc`.
- `0x0053a6f0-0x0053a6fb`: no-function/no-xref code-shaped island: `cmp dword ptr [ecx+0x1cc], 9; setnb al; retn`. It is not safe to emit as a named source helper in this pass.
- `0x0053a6fb-0x0053a700`: padding/alignment to the next function.
- `0x0053a700-0x0053a8b7`: `LivingObjectPane::GetRenderBounds`.
- `0x0053a8b7-0x0053a8c0`: padding.
- `0x0053a8c0-0x0053a8fe`: `LivingObjectPane::GetSpriteConfig`.
- `0x0053a8fe-0x0053a900`: padding.
- `0x0053a900-0x0053a9ee`: `LivingObjectPane::SetSpriteConfig`.
- `0x0053a9ee-0x0053a9f0`: padding.
- `0x0053a9f0-0x0053aae9`: `LivingObjectPane::InitializeSpriteConfig`.
- `0x0053aae9-0x0053aaf0`: seven bytes of `0xcc` padding to successor `sub_53AAF0`.

No target range extension is recommended. The successor at `0x0053aaf0` is a distinct function and should stay out of UID0003Z3.

## Function / Child Inventory

| Address | Current IDA name | MCP profile | Recommended source role |
|---|---|---|---|
| `0x0053a6b0` | `sub_53A6B0` | 18 instructions, 6 blocks, caller_count 3 functions / 6 callsites, prototype `char __stdcall(char)` | Free/shared direction remap helper: `RemapMovementDirectionForMapScroll(unsigned char)` |
| `0x0053a700` | `sub_53A700` | 148 instructions, 17 blocks, caller_count 1, vtable data ref at `0x006209cc` | `LivingObjectPane::GetRenderBounds(NxRect *, NxRect *) const` |
| `0x0053a8c0` | `sub_53A8C0` | 15 instructions, 1 block, caller_count 9 functions / 18 callsites | `LivingObjectPane::GetSpriteConfig(LivingSpriteConfig *) const` |
| `0x0053a900` | `sub_53A900` | 62 instructions, 7 blocks, caller_count 2, prototype `char __thiscall(char *, int, char)` | `LivingObjectPane::SetSpriteConfig(const LivingSpriteConfig *, unsigned char)` |
| `0x0053a9f0` | `sub_53A9F0` | 61 instructions, 3 blocks, caller_count 1, prototype `int __thiscall(char *, int, char)` | `LivingObjectPane::InitializeSpriteConfig(const LivingSpriteConfig *, unsigned char)` |
| `0x0053a6f0` | none | not a function; no xrefs; decompile fails | Documented no-code raw island only |

No child page creation was done in this callback. A future supervisor-directed split could isolate the no-function island or create narrower child pages, but current docs were improved within the existing UID0003Z3 by-memory page.

## Direct Xref / Caller Inventory

- `xrefs_to 0x0053a6b0`: code references at `0x5058c6`, `0x50be3b`, `0x5a843a`, `0x5a8515`, `0x5a857a`, and `0x5a862a`.
- `xrefs_to 0x0053a700`: code reference at `0x5a885c`; data/vtable reference at `0x6209cc`.
- `xrefs_to 0x0053a8c0`: code references at `0x507292`, `0x5074a1`, `0x507610`, `0x507a96`, `0x50810d`, `0x5089b2`, `0x50923d`, `0x50b1d7`, `0x50fa31`, `0x50faa1`, `0x511a8a`, `0x513470`, `0x5134d5`, `0x513d66`, `0x566a2c`, `0x570506`, `0x5c2cf4`, and `0x5c2fc0`.
- `xrefs_to 0x0053a900`: code references at `0x505f75` and `0x51362c`.
- `xrefs_to 0x0053a9f0`: code reference at `0x506052`.
- `xrefs_to 0x0053a6dc`: data reference from `0x53a6bc` inside `sub_53A6B0` to the switch table.
- `xrefs_to 0x0053a6f0`: zero refs.

The caller inventory supports two source facts at once: the first helper is shared/free, while the rest of the cluster remains tightly bound to LivingObjectPane sprite/render state and vtable behavior.

## Documentation Evidence And IDA Status

Current documentation already places UID0003Z3 under LivingObjectPane through UID0000KU and identifies the five modeled helper/method roles. Prior B001/B007 reports created and supported this route. The documentation is stale mainly in detail:

- `by-file/LivingObjectPane.md` and `by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md` still describe the first helper as file-local.
- `by-class/LivingObjectPane.md` describes the render/sprite child row but does not carry the current cross-family/free-helper and no-function-island details.
- `by-memory/0x00620978-0x00620a38.LivingObjectPaneVtableData.md` has LivingObjectPane vtable support but should be checked for an explicit `0x006209cc -> 0x0053a700` slot note.
- `by-memory/0x005058b0-0x0050593e.MapPaneScrollViewportByDirection.md` already contains same-or-greater support for `RemapMovementDirectionForMapScroll(direction)` as the source-facing helper name.
- Global docs already identify `g_activeMapPane`, `g_pNewHumanImageLib`, `g_pMonsterImageLib`, and `g_pTimerMgr`.

IDA status remains raw: functions are still named `sub_*`; no source/decorated names are recovered for the target; `entity_query` in the target range found only switch labels `def_53A6BC` and `jpt_53A6BC`.

## IDA MCP Facts

- Session: `nexustk_supervisor_20260704`; `server_health` `status: ok`, `auto_analysis_ready:true`, `hexrays_ready:true`.
- `lookup_funcs`:
  - `0x0053a6b0`: `sub_53A6B0`, size `0x2b`.
  - `0x0053a700`: `sub_53A700`, size `0x1b7`.
  - `0x0053a8c0`: `sub_53A8C0`, size `0x3e`.
  - `0x0053a900`: `sub_53A900`, size `0xee`.
  - `0x0053a9f0`: `sub_53A9F0`, size `0xf9`.
  - `0x0053aae9`: no function; `0x0053aaf0`: successor `sub_53AAF0`.
- `func_profile 0x0053a6b0`: prototype `char __stdcall(char)`, 18 instructions, 6 blocks, caller_count 3 functions.
- `func_profile 0x0053a700`: prototype `void __thiscall(int this, int *, _OWORD *)`, 148 instructions, 17 blocks, caller_count 1, callee_count 7.
- `func_profile 0x0053a8c0`: prototype `int __thiscall(int this, int)`, 15 instructions, caller_count 9 functions.
- `func_profile 0x0053a900`: prototype `char __thiscall(char *this, int, char)`, 62 instructions, caller_count 2.
- `func_profile 0x0053a9f0`: prototype `int __thiscall(char *this, int, char)`, 61 instructions, caller_count 1.
- `get_bytes 0x0053a6b0`: `55 8b ec 0f be 45 08 83 f8 03 77 19 ff 24 85 dc a6 53 00 b0 03 5d c2 04 00 32 c0 5d c2 04 00 b0 01 5d c2 04 00 b0 02 5d c2 04 00`.
- `get_bytes 0x0053a6db`: `90 d5 a6 53 00 c3 a6 53 00 c9 a6 53 00 cf a6 53 00 cc cc cc cc 83 b9 cc 01 00 00 09 0f 93 c0 c3 cc cc cc cc cc`.
- `disasm 0x0053a6f0`: `cmp dword ptr [ecx+1CCh], 9`; `setnb al`; `retn`; then alignment to `0x0053a700`.
- `type_query *LivingSprite*`: zero results.
- `type_query *NxRect*`: zero results.
- Vtable bytes at `0x006209c8`: `f0 75 53 00 00 a7 53 00 00 78 53 00 80 78 53 00`, including `0x006209cc -> 0x0053a700`.

## IDA Rename / Type / Comment Recommendations

No IDA edits were applied in this B-agent callback. Recommended future IDA-facing names/comments if a supervisor separately authorizes them:

- Rename/comment `sub_53A6B0` as `RemapMovementDirectionForMapScroll`, with a comment that current source route emits through `LivingObjectPane.cpp` but callers are cross-family movement paths.
- Rename/comment `sub_53A700` as `LivingObjectPane::GetRenderBounds`.
- Rename/comment `sub_53A8C0` as `LivingObjectPane::GetSpriteConfig`.
- Rename/comment `sub_53A900` as `LivingObjectPane::SetSpriteConfig`.
- Rename/comment `sub_53A9F0` as `LivingObjectPane::InitializeSpriteConfig`.
- Add a comment at `0x0053a6f0` only after a supervisor-approved IDA annotation pass: "No-function/no-xref code-shaped island inside UID0003Z3; not currently emitted as source."
- Do not create final IDA UDTs for `LivingSpriteConfig` or `NxRect` from this evidence alone.

## First-Draft C++ Recommendation

The target should keep a formal C++ block, but replace the stale helper/global/return details with the following exact formal block insertion text:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
unsigned char RemapMovementDirectionForMapScroll(unsigned char direction)
{
    switch (direction)
    {
    case 1:
        return 3;
    case 2:
        return 0;
    case 3:
        return 1;
    default:
        return 2;
    }
}

// 0x0053a6f0-0x0053a6fb is a no-function/no-xref code-shaped island
// inside the switch-table/padding gap; it is documented but not emitted as
// a callable source helper until a caller or source route is proven.

void LivingObjectPane::GetRenderBounds(NxRect *imageRect, NxRect *screenRect) const
{
    if (g_activeMapPane == 0)
        return;

    if (m_spriteConfig.kind != 0)
    {
        if (g_activeMapPane->IsHighResolutionMode())
        {
            if (m_spriteConfig.frameGroup < 9 && m_isMoving)
                g_pMonsterImageLib->GetFrameBounds(m_spriteConfig, m_facing + 5, m_moveFrame, imageRect, &m_boxRotatorRect);
            else
                g_pMonsterImageLib->GetFrameBounds(m_spriteConfig, m_spriteConfig.frameGroup, m_animationFrame, imageRect, &m_boxRotatorRect);

            OffsetBoundsByObjectAnchor(imageRect, m_boxRotatorRect);
        }
        else
        {
            g_pMonsterImageLib->GetFrameBounds(m_spriteConfig, m_spriteConfig.frameGroup, m_animationFrame, imageRect, 0);
        }
    }
    else
    {
        g_pNewHumanImageLib->GetFrameBounds(m_spriteConfig,
                                            m_facing,
                                            m_spriteConfig.bodyFrame,
                                            m_moveFrame,
                                            imageRect,
                                            g_activeMapPane->IsHighResolutionMode() ? &m_boxRotatorRect : 0,
                                            0,
                                            m_isMoving,
                                            m_spriteConfig.palette);

        if (g_activeMapPane->IsHighResolutionMode())
            OffsetBoundsByObjectAnchor(imageRect, m_boxRotatorRect);
    }

    g_activeMapPane->BuildObjectScreenRect(this, imageRect, screenRect);
}

void LivingObjectPane::GetSpriteConfig(LivingSpriteConfig *out) const
{
    *out = m_spriteConfig;
}

bool LivingObjectPane::SetSpriteConfig(const LivingSpriteConfig *config, unsigned char facing)
{
    if (m_spriteConfig.kind != config->kind)
    {
        m_spriteConfig = *config;

        if (m_isMoving && TryStepForward())
            return true;
    }

    m_timerHandler.CancelPendingTimersExceptEvent(kLivingTimerRefresh);
    m_moveFrame = 0;

    if (config->kind == 1)
        PlayAnimation(facing + 1);

    m_spriteConfig = *config;
    m_facing = facing;
    m_timerHandler.CancelTimer(kLivingTimerIdleCheck);

    OnSpriteConfigChanged();
    return g_activeMapPane->InvalidateObject(this);
}

void LivingObjectPane::InitializeSpriteConfig(const LivingSpriteConfig *config, unsigned char facing)
{
    m_spriteConfig = *config;
    m_facing = facing;
    m_spriteConfig.bodyFrame = 0;
    m_isMoving = false;
    m_moveFrame = 0;
    m_animationFrame = 0;
    m_nameVisible = false;

    OnSpriteConfigChanged();

    m_spriteConfig.frameGroup = facing + 1;

    if (config->kind == 1)
    {
        const int delay = g_pMonsterImageLib->GetFrameDelay(m_spriteConfig.appearanceId - 0x8000,
                                                           m_spriteConfig.frameGroup,
                                                           m_animationFrame);
        g_pTimerMgr->ScheduleTimer(&m_timerHandler, kLivingTimerFrameAdvance, delay, 0, 0);
    }

    m_linkedOwnerBackPointer = 0;
    m_boxRotationPhase = 0;
    m_boxRotatorOwner = this;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

The names `LivingSpriteConfig`, `NxRect`, `kLivingTimerRefresh`, and `kLivingTimerFrameAdvance` remain documentation-level source reconstruction. The evidence supports their roles, not exact original spelling.

## Final Recommendation

UID0003Z3 has been applied as a source-ready, but still first-draft, LivingObjectPane file helper cluster:

- Target metadata is now `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000KU`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KU`, with blank emitter position preserved.
- The target formal C++ block was replaced with the exact block in `First-Draft C++ Recommendation`.
- Target prose now states that `0x0053a6b0` is a shared/free direction remap helper emitted through the LivingObjectPane source route, not a private LivingObjectPane member and not proven static/file-local.
- Target range evidence now covers the switch jump table and the `0x0053a6f0-0x0053a6fb` no-function/no-xref island.
- The target remains in the LivingObjectPane source family and was not reassigned to MapPane, UserPane, image libraries, TimerMgr, globals, no-owner, or broad parent aggregate.
- Future work outside this target: original source spelling/header recovery for helper/UDT names, optional child split if supervisor wants per-function pages, and project-wide alias harmonization for active MapPane/global names.

## Recommended Target Doc Changes

For `by-memory/0x0053a6b0-0x0053aae9.LivingObjectPaneSpriteConfigHelpers.md`, the callback applied:

- `COMPLETION:86` to `COMPLETION:88`.
- `CONFIDENCE:88` to `CONFIDENCE:90`.
- Preserved `CANONICAL_OWNER:0000KU`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KU`, and blank `EMITTER_POSITION_OPTIONAL`.
- Filled the blank item summary with the source-ready helper cluster summary.
- Replaced the formal C++ block with the exact block from `First-Draft C++ Recommendation`.
- Replaced stale "file-local/static opposite-direction helper" wording with cross-family `RemapMovementDirectionForMapScroll` evidence.
- Replaced stale "alignment raw cc/gap" wording for `0x0053a6db-0x0053a700` with the detailed jump-table/no-function-island/padding split.
- Added MCP session `nexustk_supervisor_20260704` facts: function sizes, xrefs, vtable slot ref, bytes, no-function island checks, decompiles, UDT absence, and global source-route support.
- Updated score rationale to explain the 88/90 cap.

## Recommended Support Doc Changes

Support dispositions after callback:

- `by-file/LivingObjectPane.md`: applied UID0003Z3 child/source-route wording at `88/90`, `RemapMovementDirectionForMapScroll`, no-function island proof, and stale file-local historicalization; validator `000000006366`.
- `by-class/LivingObjectPane.md`: applied narrow class support note for UID0003Z3 methods plus shared/free direction-remap caveat; validator `000000006367`.
- `by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md`: applied exact child row/core anchor/raw-helper/padding split updates; validator `000000006368`.
- `by-memory/0x00620978-0x00620a38.LivingObjectPaneVtableData.md`: applied vtable slot/data ref `0x006209cc -> 0x0053a700`; validator `000000006354`.
- `by-memory/0x005058b0-0x0050593e.MapPaneScrollViewportByDirection.md`: already contained same-or-greater source-facing support for `RemapMovementDirectionForMapScroll(direction)` and was not edited.
- `by-global/g_activeMapPane.md`, `by-global/g_pNewHumanImageLib.md`, `by-global/g_pMonsterImageLib.md`, and `by-global/g_pTimerMgr.md`: already contained same-or-greater global source-route support and were not edited.

Generated files were not edited manually. Generated `auto-generated/NexusTK/map/LivingObjectPane.cpp` refreshed through validator-owned side effects after implementation.

## Score And Metadata Recommendation

Applied target score: `COMPLETION:88`, `CONFIDENCE:90`.

Rationale:

- Completion improves because MCP validates all five modeled functions, the formal C++ can be updated, the source route is valid, and the primary stale blocker is quality/detail rather than emission eligibility.
- Confidence improves because current evidence ties callers, xrefs, globals, bytes, decompiles, vtable data, and support docs together.
- Completion should not exceed the high 80s because one no-function/no-xref code-shaped island remains documented but not source-emitted, exact source helper spelling/linkage is inferred, and IDA lacks recovered `LivingSpriteConfig`/`NxRect` UDTs.
- Confidence should not exceed 90 because raw function names remain `sub_*`, current UDT/source symbol evidence is documentation-level, and project-wide global alias wording is not fully harmonized across siblings.

Ownership metadata should not change. UID0000KU remains the best canonical owner/emitter route for this mixed file helper cluster.

## Open Questions With Attempted Resolution

- Exact original name/linkage for `0x0053a6b0`: attempted resolution used MCP prototype/xrefs/decompile and existing MapPane documentation. The evidence disproves a private LivingObjectPane member and supports source-facing `RemapMovementDirectionForMapScroll`, but exact original spelling and linkage remain unproven. Score/C++ impact: use the established documentation name, do not claim final symbol recovery. Needed evidence: original headers/source symbols or stronger source import.
- `0x0053a6f0-0x0053a6fb` source role: attempted resolution used `lookup_funcs`, `func_profile`, `xrefs_to`, `disasm`, `decompile`, and byte checks. It is code-shaped but has no function/xref/decompile route. Score/C++ impact: document it and keep it out of callable C++. Needed evidence: a proven caller, a recovered function boundary, or source-level equivalent.
- `LivingSpriteConfig` and `NxRect` exact UDTs: attempted resolution used `type_query` for `LivingSprite` and `NxRect`, both returning zero, plus local docs and decompiles. Score/C++ impact: keep existing first-draft names but cap score. Needed evidence: recovered type info or validated source declarations.
- Active MapPane global spelling: attempted resolution checked `by-global/g_activeMapPane.md` and sibling formal C++. Score/C++ impact: recommend current global formal `g_activeMapPane`, while noting sibling generated code may still use `g_pActiveMapPane`. Needed evidence: project-wide naming pass outside UID0003Z3.
- `SetSpriteConfig` return semantics: attempted resolution used MCP decompile and sibling `WarpToPosition`/MapPane invalidation docs. Score/C++ impact: update formal C++ to return the final active MapPane invalidation result, not `false`. Needed evidence for exact source method spelling: original MapPane method declaration.

## Validator Results

Scoped validators were run from `E:\NTK\GhidraBridge\source-3\project-documentation` for every edited by-* file.

| File | Command | command_id | command_timestamp | Exit | ok | Warnings / side effects |
|---|---|---|---|---:|---:|---|
| `by-memory/0x0053a6b0-0x0053aae9.LivingObjectPaneSpriteConfigHelpers.md` | `python .\tools\validator.py --mode file --file by-memory/0x0053a6b0-0x0053aae9.LivingObjectPaneSpriteConfigHelpers.md --apply --queue-timeout 240` | `000000006352` | `2026-07-04T13:40:25-04:00` | 0 | 1 | `completion_update` 88, `confidence_update` 90, `autogen_registry_update`, reference index adds for global UIDs, stats row removal/rescore recommendation, projected stats update, `generated_refresh: deferred`. |
| `by-memory/0x00620978-0x00620a38.LivingObjectPaneVtableData.md` | `python .\tools\validator.py --mode file --file by-memory/0x00620978-0x00620a38.LivingObjectPaneVtableData.md --apply --queue-timeout 240` | `000000006354` | `2026-07-04T13:40:33-04:00` | 0 | 1 | Existing `missing_ref_uid` warnings for `0003UD`/`0003Z5`; reference index add for `0003Z3`; projected stats update; `generated_refresh: deferred`. |
| `by-file/LivingObjectPane.md` | `python .\tools\validator.py --mode file --file by-file/LivingObjectPane.md --apply --queue-timeout 240` | `000000006366` | `2026-07-04T13:45:52-04:00` | 0 | 1 | Existing broad `missing_ref_uid` warnings suppressed after first 10; projected stats update; `generated_refresh: deferred`. |
| `by-class/LivingObjectPane.md` | `python .\tools\validator.py --mode file --file by-class/LivingObjectPane.md --apply --queue-timeout 240` | `000000006367` | `2026-07-04T13:45:58-04:00` | 0 | 1 | Existing broad `missing_ref_uid` warnings suppressed after first 10; projected stats update; `generated_refresh: deferred`. Subsequent validator-owned generated refresh now shows UID0003Z3 as `88/90` with `RemapMovementDirectionForMapScroll`. |
| `by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md` | `python .\tools\validator.py --mode file --file by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md --apply --queue-timeout 240` | `000000006368` | `2026-07-04T13:46:07-04:00` | 0 | 1 | Existing broad `missing_ref_uid` warnings; `uid_link_insert` for `0003Z3`; projected stats update; `generated_refresh: deferred`. |

Generated freshness observation: `auto-generated/NexusTK/map/LivingObjectPane.cpp` header now has `validator-command-id: 000000006373`, `validator-refreshed-at: 2026-07-04T13:52:43-04:00`, and its UID0003Z3 section shows `Completion:88`, `Confidence:90`, `RemapMovementDirectionForMapScroll`, and current `g_activeMapPane` references. This was validator-owned generated refresh; B008 did not edit generated files manually.

## Changed Files

- `by-memory/0x0053a6b0-0x0053aae9.LivingObjectPaneSpriteConfigHelpers.md` - target metadata, item summary, formal C++, evidence/range/support/rationale.
- `by-file/LivingObjectPane.md` - narrow UID0003Z3 file-route/source-ready support sync.
- `by-class/LivingObjectPane.md` - narrow UID0003Z3 class support note.
- `by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md` - parent child-row/raw-helper/range-split support sync.
- `by-memory/0x00620978-0x00620a38.LivingObjectPaneVtableData.md` - `0x006209cc -> 0x0053a700` vtable support sync.
- `tools/leaser/Agents/Agent-B008/research/0003Z3-LivingObjectPaneSpriteConfigHelpers-source-quality.md` - implementation ledger/checklist/validator results update.

Validator-owned side effects observed:

- `auto-generated/NexusTK/map/LivingObjectPane.cpp` refreshed to command `000000006373`.
- `project-level/-auto-completion-stats.md` projected path completion section updated by scoped validators.
- Validator registry/reference-index side effects were reported by validator commands; B008 did not edit validator state by hand.

No coverage reports, lifecycle/archive files, report moves, or supervisor ledgers were edited. No `execute_report` or lifecycle command was run.

## Implementation Tracking Checklist

- [x] Target metadata set to `COMPLETION:88`, `CONFIDENCE:90`; owner/emitter/reconstructable/blank position preserved. Proof: target validator `000000006352`, exit 0, `ok:1`.
- [x] Target item summary populated with source-ready helper cluster summary. Proof: target summary updated and validator `000000006352` passed.
- [x] Target formal C++ block replaced with the exact formal block from this report. Proof: generated output command `000000006367` shows UID0003Z3 with `RemapMovementDirectionForMapScroll`.
- [x] `0x0053a6b0` wording updated from stale file-local/static helper to shared/free `RemapMovementDirectionForMapScroll` source role. Proof: target, by-file, by-class, and core validators passed.
- [x] Range table updated for `0x0053a6dc` jump table, `0x0053a6f0-0x0053a6fb` no-function island, and successor padding. Proof: target validator `000000006352`, core validator `000000006368`.
- [x] MCP session `nexustk_supervisor_20260704` evidence incorporated into target proof/rationale. Proof: target evidence section updated and validator `000000006352` passed.
- [x] Negative evidence preserved: not MapPane owner, not global owner, not padding-only, not no-owner, not broad parent body, not immediate child split. Proof: target rejected alternatives updated; child split explicitly excluded by reason.
- [x] Support docs checked/updated only where stale: `by-file/LivingObjectPane.md`, `by-class/LivingObjectPane.md`, `by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md`, and `by-memory/0x00620978-0x00620a38.LivingObjectPaneVtableData.md`. Proof: validators `000000006366`, `000000006367`, `000000006368`, `000000006354`.
- [x] Already-present support recorded for `MapPaneScrollViewportByDirection` and global pages. Proof: no direct stale contradictions found; report ledger row C-0003Z3-07 marks global pages already-present.
- [x] Scoped validators run for every edited by-* file during implementation callback. Proof: five validator rows above, all exit 0, `ok:1`.
- [x] Generated `auto-generated/NexusTK/map/LivingObjectPane.cpp` freshness observed after validator-owned refresh. Proof: header `validator-command-id: 000000006373`, `validator-refreshed-at: 2026-07-04T13:52:43-04:00`.
- [x] Report ledger updated from `proposed` to `applied`, `already-present`, `excluded-with-reason`, or `blocked` during implementation callback. Proof: ledger rows C-0003Z3-01 through C-0003Z3-12 updated above.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000006381","destination_path":"executed-b-agent-research/B008/0003Z3-LivingObjectPaneSpriteConfigHelpers-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B008/research/0003Z3-LivingObjectPaneSpriteConfigHelpers-source-quality.md","timestamp":"2026-07-04T17:48:41-04:00","uid":"0003Z3"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
