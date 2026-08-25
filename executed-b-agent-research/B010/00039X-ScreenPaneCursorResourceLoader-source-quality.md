** TARGET-REPORT-UID:00039X **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00039X ScreenPaneCursorResourceLoader Source-Quality Research


## Finalized Report / Current Recommendation

- Current recommendation: keep UID00039X reconstructable, keep the implemented direct semantic owner/emitter reroute from [UID:0000NB] `ScreenPane` file to [UID:0000CB] `ScreenPane` class, keep generated output routed through the ScreenPane class to `NexusTK/ui/core/ScreenPane.cpp`, and keep the populated first-draft formal C++ for the cursor resource loader.
- Final disposition: source-authored ScreenPane cursor resource initialization, not a standalone `CursorManager` source root and not a Surface-owned presentation helper.
- Current accepted/applied support scope: target page, `by-class/ScreenPane.md`, `by-file/ScreenPane.md`, and related `by-memory/0x00557380-0x00557467.ScreenCursorHelpers.md` cross-reference sync. The broader original report-only suggestions for `SurfacePresentation`, CursorManager class/file pages, and `ScreenPaneResourceStringData` were not accepted for the updated callback scope and remain excluded/out-of-scope in this repaired artifact.
- Confidence: high for behavior, range, startup caller, literals, ScreenPane ownership, and source route; capped below final-audit because the retained raw slot-loader helper at `0x00559080` has no external xrefs and cursor slots `0-6` remain outside this target.

## Supporting Research

This report began as a report-only Gate 1 pass for Agent-B010. After the supervisor Gate 1 callback, B010 applied the accepted implementation scope to the target and allowed ScreenPane support docs, then updated this report's ledger/checklist and ran only the scoped file validators named by the updated `goal.md`.

B010 did not edit generated files, coverage reports, validator-owned state, supervisor ledgers, lifecycle headers/footers, or archive files by hand. B010 did not run `execute_report`, any dry-run/probing equivalent, report lifecycle command, manual report move, broad validator, registry lifecycle command, or archive move.

Current MCP evidence was collected from `ida-pro-mcp` `1.0.0` at `http://127.0.0.1:13337/mcp`. The server initially required a proper MCP session header and `idb_open`; after opening the already configured IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, database session `18aed30a` reported `server_health` status `ok`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_ready:true`.

The callback implementation now records the direct class owner, exact slot mapping, raw helper semantics, generated-output route, and formal C++ readiness in the target/support docs at report-level detail.

## Target

- Target UID: `00039X`.
- Target path: `by-memory/0x00558f70-0x005590da.ScreenPaneCursorResourceLoader.md`.
- Required report path: `tools/leaser/Agents/Agent-B010/research/00039X-ScreenPaneCursorResourceLoader-source-quality.md`.
- Source queue/report row before callback: `auto-generated/-ag-research-tracker.md` -> by-memory not-covered reconstructable row, `86/89`, combined `87.5`, reconstructable `true`, direct reports `0`.
- Current generated route after callback validation: `auto-generated/NexusTK/ui/core/ScreenPane.cpp` refreshed with `validator-command-id: 000000007605`, `validator-refreshed-at: 2026-07-06T17:59:27-04:00`, and contains the UID00039X `ScreenPane::LoadCursorResources()` / `ScreenPane::LoadCursorResourceSlot(...)` code block.
- Current supervisor classification: same-report post-callback Gate 1 repair complete after this edit; ready for fresh supervisor Gate 1 review of the repaired artifact before any Gate 2 or supervisor-owned execution decision.

## Current Target State

- Pre-callback metadata: `COMPLETION:86`, `CONFIDENCE:89`, `CANONICAL_OWNER:0000NB`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000NB`, blank formal C++.
- Current implemented metadata: `COMPLETION:90`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000CB`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CB`, blank optional position, formal C++ populated.
- Current owner/emitter/reconstructable state: ScreenPane class-owned and emitted through the ScreenPane class/file route to `NexusTK/ui/core/ScreenPane.cpp`.
- Current C++/emitter state: generated `ScreenPane.cpp` no longer contains the UID00039X empty marker; it contains the formal cursor loader and retained raw helper code after scoped validation.
- Remaining open score caps: raw helper no-xref liveness, exact original helper spelling, and cursor slots `0-6` outside this target.
- Related target/support docs checked: target page; `by-file/ScreenPane.md`; `by-class/ScreenPane.md`; `by-file/CursorManager.md`; `by-class/CursorManager.md`; `by-global/g_pScreenPane.md`; `by-global/g_pCursorManager.md`; `by-memory/0x00557380-0x00557467.ScreenCursorHelpers.md`; `by-memory/0x00557140-0x00559aef.SurfacePresentation.md`; `by-memory/0x00556910-0x00557132.ScreenPane.md`; `by-memory/0x004f5fb0-0x004f6490.ApplicationStartup.md`; `by-memory/0x0062317c-0x00623480.ScreenPaneResourceStringData.md`; `by-memory/0x006230e8-0x0062317c.ScreenPaneVtableData.md`; generated `auto-generated/NexusTK/ui/core/ScreenPane.cpp`; generated tracker/coverage rows.
- Related docs edited during callback under the updated goal scope: target page, `by-class/ScreenPane.md`, `by-file/ScreenPane.md`, and `by-memory/0x00557380-0x00557467.ScreenCursorHelpers.md`.
- Current artifact/lifecycle status: active B010 report after implementation callback and same-report Gate 1 repair, awaiting fresh supervisor post-callback Gate 1 review.

## Heuristic / Inference Reanalysis And Validation

The old blocker said cursor table names and final resource-loader split were not source quality. Current evidence supports these source-facing names:

- `0x00558f70`: `ScreenPane::LoadCursorResources()`. This is a modeled `__thiscall` function with one direct startup caller at `0x004f61c9`, called immediately after `new PaletteLib` in `Application::Startup()`.
- `0x00559080`: retained raw helper, best named `ScreenPane::LoadCursorResourceSlot(unsigned int cursorIndex, const wchar_t *animatedCursorPath, const wchar_t *staticCursorPath)`. It is not an IDA-modeled function and has no xrefs to the start, but the byte-bounded body clearly takes `ecx` as the same ScreenPane object, validates an unsigned cursor index against `0x0b`, and writes the same handle table at `this+0x550`.
- Cursor table: field at byte offset `+0x550`; current target loads entries `+0x56c`, `+0x570`, `+0x574`, `+0x578`, and `+0x57c`, corresponding to table slots 7 through 11. `int_convert.py` verified `0x550` / 1360, `0x56c` / 1388, `0x570` / 1392, `0x574` / 1396, `0x578` / 1400, `0x57c` / 1404, `0x580` / 1408, `0x0b` / 11, `0x105` / 261, `0x5a` / 90, and `0x7f00` / 32512.
- Slot names: slots 7-11 are best source-facing `normal`, `select`, `view`, `put`, and `attack` cursor indices because each slot is loaded from matching `Cursor\*.ani` then `Cursor\*.cur` resource-path pairs.
- Fallback: every loaded cursor falls back to `LoadCursorW(NULL, IDC_ARROW)` when both file paths fail. The binary pushes `0x7f00`, which is the Win32 `IDC_ARROW` resource value.
- CursorManager alternative: rejected as a direct owner because current docs and MCP evidence show no separate constructor, destructor, allocation, or singleton lifetime. `g_pCursorManager` remains an alias/typed view over `g_pScreenPane`.
- Surface alternative: rejected for this target because the body performs no DirectDraw presentation or Surface global initialization. It only writes ScreenPane cursor state and uses cursor resource strings.
- Split alternative: no required split. The modeled loader and raw slot helper share the same object, table, dependencies, and source route. A future one-helper-per-page split would be optional style work, not a current source-quality blocker.

No Wave2/Wave3 stale source instruction was used as authority. Generated output was used only as lead/state evidence and was rechecked against target docs and IDA MCP facts.

## Evidence Standards Used

- Direct IDA MCP facts: current `lookup_funcs`, `func_profile`, `xrefs_to`, `callees`, `decompile`, `disasm`, `get_bytes`, `search_text`, `get_string`, `entity_query`, and `type_query` calls on database `18aed30a`.
- Byte/range evidence: exact modeled function size, raw helper bytes, `0xcc` padding before/after the raw helper, and successor function boundary at `0x005590e0`.
- Xref evidence: one direct startup code xref to `0x00558f70`, zero xrefs to `0x00559080`, and one data xref from the modeled loader to each cursor literal.
- Documentation evidence: current target/support docs, generated ScreenPane output, generated tracker/coverage rows, and exact-match old B reports used as leads.
- Negative evidence: no separate CursorManager lifetime, no raw helper start xrefs, no data/pointer xrefs to `0x00559080`, no Surface-specific behavior in this target, and no IDA local `ScreenPane` type definition beyond RTTI/vtable names.

The evidence is strong enough for first-draft C++ and a class-owner reroute. It is not strong enough for a final-audit score because original helper spellings and cursor slots `0-6` are not fully recovered in this target.

## Evidence Checked

- IDA MCP/manual-disassembly/raw-byte checks performed:
  - `server_health` on database `18aed30a`: ok, `NexusTK.exe`, imagebase `0x400000`, auto-analysis/Hex-Rays/strings ready.
  - `lookup_funcs`: `0x00558f70` -> `sub_558F70`, size `0x105`; `0x00559080` and `0x005590da` are not functions; successor `0x005590e0` -> `sub_5590E0`.
  - `func_profile 0x00558f70`: 80 instructions, 16 basic blocks, one caller, prototype guessed as `HCURSOR __thiscall(_DWORD *this)`, constants for ten cursor literals and `0x7f00`.
  - `xrefs_to`: one code xref to `0x00558f70` at `0x004f61c9`; zero xrefs to `0x00559080`; zero xrefs to `0x005590da`.
  - `decompile/disasm 0x00558f70`: exact cursor load sequence for `normal`, `select`, `view`, `put`, `attack`; writes `[esi+56Ch]` through `[esi+57Ch]`; falls back to `LoadCursorW(0, 0x7f00)`.
  - `get_bytes`: `0x00559075-0x00559080` is eleven `0xcc` bytes; raw helper `0x00559080-0x005590da` is executable bytes ending `pop esi; pop ebx; pop ebp; retn 0Ch`; `0x005590da-0x005590e0` is six `0xcc` bytes; `0x005590e0` starts with a new function prologue.
  - Bounded `search_text 0x00559080-0x005590da`: raw helper calls `LoadCursorFromFileW` at `0x00559097` and `0x005590b0`, calls `LoadCursorW` at `0x005590c7`, writes `[ebx+esi*4+550h]` at `0x0055909d`, `0x005590b6`, and `0x005590cd`, and returns with `retn 0Ch` at `0x005590d7`.
  - `get_string` and `get_bytes` for cursor literal addresses confirmed the UTF-16 paths: `Cursor\normal.ani`, `Cursor\normal.cur`, `Cursor\select.ani`, `Cursor\select.cur`, `Cursor\view.ani`, `Cursor\view.cur`, `Cursor\put.ani`, `Cursor\put.cur`, `Cursor\attack.ani`, `Cursor\attack.cur`.
  - `xrefs_to` for those ten literal addresses: each has exactly one data xref from `sub_558F70`.
  - `entity_query`: ScreenPane RTTI/vtable names exist, and the only matching function in the target neighborhood is `sub_558F70`.
  - `type_query`: no local `ScreenPane` UDT; `HCURSOR` typedef exists.
- by-* docs, support docs, old reports, generated reports, and trackers checked:
  - Target/support docs listed in `Current Target State`.
  - Generated tracker row: `auto-generated/-ag-research-tracker.md` line for UID00039X is `86/89`, combined `87.5`, reconstructable `true`, direct reports `0`.
  - Generated memory coverage: UID00039X emits through `0000NB` to generated `ScreenPane.cpp`, no code.
  - Generated by-memory coverage report: UID00039X remains `emits_code:false`, `86%`, strong, last updated 2026-06-26, with startup caller and `LoadCursorResources()` support.
  - Generated `auto-generated/NexusTK/ui/core/ScreenPane.cpp`: current empty marker for UID00039X.
  - Old-report search terms used: `TARGET-REPORT-UID:00039X`, `00039X`, `0x00558f70`, `0x005590da`, `ScreenPaneCursorResourceLoader`, `ScreenPane`, `cursor`, `resource loader`, `sub_558F70`, `LoadCursorResources`, `LoadCursorFromFileW`, `LoadCursorW`, `Cursor\normal`, `Cursor\select`, `Cursor\view`, `Cursor\put`, `Cursor\attack`.
  - Exact-match report leads opened: `executed-b-agent-research/B001/0001G6-SurfacePresentation.md`, `executed-b-agent-research/B006/00039W-SurfaceMinimapRenderInitializer-source-quality.md`, `executed-b-agent-research/B005/00039Y-ScreenPaneCallbackAndFlagHelpers-source-quality.md`, and `executed-b-agent-research/B007/0002H7-ApplicationStartup-source-quality.md`. `B005/00039Y` carries `REPORT-VALIDATION-STATUS: needs-revalidation`, so it is used only as adjacent-context lead and not as accepted coverage.
- Negative checks performed:
  - No separate `CursorManager` constructor/destructor/allocation/lifetime evidence in current support docs.
  - No xrefs to raw helper start `0x00559080`.
  - No modeled function at `0x00559080`, `0x005590da`, or padding boundary `0x00559075`.
  - No evidence that Surface owns this target; UID00039W's mixed Surface/ScreenPane blocker does not apply to UID00039X.
- Failed, unavailable, or intentionally skipped checks and why:
  - Initial report-only pass ran no validator. During the later implementation callback, B010 ran only the scoped file validators recorded in `Validator Results`; no broad validator or lifecycle command was run.
  - No IDA mutation tools, rename/type/comment tools, or function-definition tools were used.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-00039X-01 | UID00039X is a ScreenPane instance cursor-resource loader, not Surface or standalone CursorManager source. | High | MCP caller/decompile/disasm, ScreenPane/CursorManager docs. | Target Status/Ownership Analysis; ScreenPane class/file support docs. | incorporate | applied |
| C-00039X-02 | `0x00558f70` is `sub_558F70`, size `0x105`, one direct startup caller at `0x004f61c9`. | High | MCP `lookup_funcs`, `xrefs_to`, `func_profile`. | Target IDA MCP Evidence. | incorporate | applied |
| C-00039X-03 | Source-facing method name `ScreenPane::LoadCursorResources()` is accepted and implementation-ready. | High | B007 ApplicationStartup report/doc, current startup page, current MCP caller route. | Target Behavior/formal C++; ScreenPane class/file method inventory. | incorporate | applied |
| C-00039X-04 | The modeled loader writes cursor handles at `+0x56c/+0x570/+0x574/+0x578/+0x57c`, slots 7-11 in the `+0x550` table. | High | MCP disasm/decompile and `int_convert.py`. | Target Behavior/IDA Evidence; ScreenPane class layout; ScreenCursorHelpers table note. | incorporate | applied |
| C-00039X-05 | Slots 7-11 are best named normal/select/view/put/attack cursor slots. | High | Direct cursor resource literal pairs and table writes. | Target Behavior/formal C++; ScreenPane class layout; ScreenCursorHelpers cross-reference. | incorporate | applied |
| C-00039X-06 | Each modeled slot tries `.ani`, then `.cur`, then `LoadCursorW(NULL, IDC_ARROW)`. | High | MCP decompile/disasm and direct literal reads. | Target Behavior/formal C++; ScreenPane file/class support notes. | incorporate | applied |
| C-00039X-07 | `0x00559080-0x005590da` is a raw retained cursor slot-loader helper, not padding. | High | MCP bytes, bounded search_text, `retn 0Ch`. | Target Address Range/Behavior/formal C++; ScreenPane class/file method notes. | incorporate | applied |
| C-00039X-08 | Raw helper has no external xrefs and should cap score/liveness confidence, not block source documentation. | High | MCP `xrefs_to 0x00559080` zero; raw helper semantics. | Target IDA Evidence/Assignment Gate/Changes; ScreenPane class/file support notes. | incorporate | applied |
| C-00039X-09 | `0x00559075-0x00559080` and `0x005590da-0x005590e0` are `0xcc` padding. | High | MCP `get_bytes`; successor function `0x005590e0`. | Target Address Range/IDA MCP Evidence/Changes. | incorporate | applied |
| C-00039X-10 | Direct owner should become [UID:0000CB] `ScreenPane`; generated emitter should become `0000CB` to route through ScreenPane class/file. | High | by-structure direct-owner rule, ScreenPane class docs, method receiver/state evidence. | Target metadata; ScreenPane class/file support docs; validator command `000000007602`. | incorporate | applied |
| C-00039X-11 | Formal C++ is now eligible and should replace the generated empty marker. | Medium-high | Combined score/emitter gate, full behavior evidence, remaining raw-helper liveness cap. | Target formal `RECONSTRUCTION_CPP CODE`; generated `ScreenPane.cpp` refreshed by command `000000007605`. | incorporate | applied |
| C-00039X-12 | CursorManager open-loader wording is resolved as "ScreenPane class loader; CursorManager remains typed view." | High | CursorManager docs plus current MCP. | Applied in authorized target, ScreenPane class, ScreenPane file, and ScreenCursorHelpers docs; direct CursorManager page edits excluded by updated `goal.md` callback scope. | incorporate | applied |
| C-00039X-13 | Original report-only suggestion to update `SurfacePresentation` child-row state is not part of the current accepted/applied callback scope. | High | Updated `goal.md` accepted support scope names only ScreenPane class/file and related ScreenPane cursor-helper docs. | `Recommended Support Doc Changes`, `Final Recommendation`, and checklist exclusion rows. | not-applicable | excluded-with-reason |
| C-00039X-14 | Original report-only suggestion to update direct CursorManager class/file pages is not part of the current accepted/applied callback scope. | High | Updated `goal.md` accepted support scope excludes CursorManager docs; accepted typed-view conclusion was applied through authorized ScreenPane docs. | `Recommended Support Doc Changes`, `Final Recommendation`, and checklist exclusion rows. | not-applicable | excluded-with-reason |
| C-00039X-15 | Original report-only suggestion to update `ScreenPaneResourceStringData` is not part of the current accepted/applied callback scope. | High | Updated `goal.md` accepted support scope excludes resource-string data page; literal facts were applied in the target and authorized ScreenPane docs. | `Recommended Support Doc Changes`, `Final Recommendation`, and checklist exclusion rows. | not-applicable | excluded-with-reason |

## Positive Evidence Summary

- Direct facts supporting the chosen recommendation:
  - `0x00558f70` is modeled and startup-called exactly once from `Application::Startup()` at `0x004f61c9`.
  - The body uses `ecx` as the ScreenPane object pointer and writes object-local cursor handles.
  - The direct literal set is cursor-resource-specific and has one xref per literal from this function.
  - Raw helper `0x00559080` writes the same `this+0x550` table and shares the same `LoadCursorFromFileW` / `LoadCursorW` dependencies.
- Corroborating documentation/generated-report evidence:
  - Current ApplicationStartup formal C++ already calls `g_pScreenPane->LoadCursorResources()`.
  - ScreenPane class/file docs own the root object, cursor table field, active cursor index, and CursorManager alias caveat.
  - Generated `ScreenPane.cpp` currently routes UID00039X to the correct source file but only as an empty marker, exactly matching the source-quality issue.
- Strongest inference chain and why it is sufficient:
  - ScreenPane singleton receiver at startup -> direct call to `0x00558f70` -> writes ScreenPane cursor table -> cursor selector uses that table -> no separate CursorManager lifetime -> ScreenPane class is the narrowest owner and ScreenPane.cpp is the correct source route.

## IDA MCP Facts

- Function/range facts:
  - `0x00558f70`: modeled `sub_558F70`, size `0x105`, 80 instructions.
  - `0x00559075-0x00559080`: eleven `0xcc` padding bytes.
  - `0x00559080-0x005590da`: raw executable helper bytes, not modeled as a function, with `retn 0Ch` at `0x005590d7`.
  - `0x005590da-0x005590e0`: six `0xcc` padding bytes.
  - `0x005590e0`: successor `sub_5590E0`.
- Data/table/padding facts:
  - `0x00558f70` writes ScreenPane cursor table entries at `+0x56c`, `+0x570`, `+0x574`, `+0x578`, and `+0x57c`.
  - Raw helper writes `[ebx+esi*4+550h]` at `0x0055909d`, `0x005590b6`, and `0x005590cd`.
- Xref facts:
  - One code xref to modeled loader: `0x004f61c9`.
  - Zero xrefs to raw helper start `0x00559080`.
  - Each cursor literal has one data xref from `sub_558F70`.
- Vtable/global/type facts:
  - MCP `entity_query` finds ScreenPane RTTI/vtable names but no IDA local `ScreenPane` UDT. `type_query` finds `HCURSOR`.
- Negative IDA facts:
  - No modeled function at the raw helper start.
  - No pointer/data route to the raw helper start.
  - No separate CursorManager type/lifetime evidence in current MCP or docs.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00558f70-0x00559075` | UID00039X target | Modeled `ScreenPane::LoadCursorResources()` | TRUE | Recommend [UID:0000CB] | Recommend `90/91` | First-draft C++ ready |
| `0x00559075-0x00559080` | padding within UID00039X | `0xcc` alignment | FALSE | ignored/padding | n/a | Already represented in target range notes |
| `0x00559080-0x005590da` | UID00039X target | Raw retained `ScreenPane::LoadCursorResourceSlot(...)` helper | TRUE | Recommend [UID:0000CB] | Included in `90/91` | First-draft C++ ready with no-xref caveat |
| `0x005590da-0x005590e0` | padding before UID00039Y | `0xcc` alignment | FALSE | ignored/padding | n/a | Boundary proof |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004f61c9 -> 0x00558f70` | Sole direct code caller from `Application::Startup()` | Startup loads cursor resources on `g_pScreenPane` after PaletteLib construction. |
| `0x00558f70 -> LoadCursorFromFileW` | Repeated import call | Attempts `.ani` then `.cur` resource files. |
| `0x00558f70 -> LoadCursorW` | Repeated import call with `0x7f00` | Fallback to `IDC_ARROW`. |
| `0x00559080 -> LoadCursorFromFileW` | Raw helper calls at `0x00559097` and `0x005590b0` | Generalized slot loader tries two caller-supplied paths. |
| `0x00559080 -> LoadCursorW` | Raw helper call at `0x005590c7` | Fallback to `IDC_ARROW`. |
| `0x00559080` start | Zero direct/pointer xrefs found | Retained helper liveness remains a score cap. |

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion:
  - Target page already states ScreenPane ownership, startup caller, cursor helper dependencies, and `g_pScreenPane->LoadCursorResources()`.
  - `by-class/ScreenPane.md` records cursor table `+0x550`, active cursor index `+0x580`, and current CursorManager alias caveat.
  - `by-file/CursorManager.md` and `by-class/CursorManager.md` already reject a standalone CursorManager source root and name UID00039X as ScreenPane-owned cursor resource loading evidence.
  - `by-memory/0x004f5fb0-0x004f6490.ApplicationStartup.md` emits `g_pScreenPane->LoadCursorResources()` in the formal block.
  - `by-memory/0x0062317c-0x00623480.ScreenPaneResourceStringData.md` owns the cursor literals as ScreenPane resource string data.
- Pre-callback stale/incomplete docs that this report addressed:
  - Target metadata used file UID `0000NB` as direct owner. Under current by-structure rules, the class UID `0000CB` is the narrower direct owner for this ScreenPane method/helper pair, and the callback updated the target metadata.
  - Target C++ was blank even though the evidence supported a first-draft implementation; the callback populated the formal C++ block.
  - CursorManager support docs were an original report-only follow-up candidate. Direct CursorManager page edits were not accepted in the updated callback scope, so this repaired artifact treats them as excluded/out-of-scope while applying the typed-view conclusion through the target and authorized ScreenPane support docs.
- Generated/coverage report state:
  - Pre-callback generated ScreenPane output had a UID00039X empty marker. After callback validation, `auto-generated/NexusTK/ui/core/ScreenPane.cpp` refreshed under command `000000007605` and contains the formal UID00039X code.

## Ranked Ownership Analysis

### 1. [UID:0000CB] ScreenPane class

- Evidence for: `Application::Startup()` calls the loader on `g_pScreenPane`; modeled and raw bodies use `this` as the root ScreenPane object; writes target ScreenPane cursor table; ScreenPane class docs own cursor table and active cursor index; no separate CursorManager lifetime exists.
- Evidence against: current target metadata uses the ScreenPane file UID; exact original method/helper names are inferred, not recovered.
- Decision: recommend as direct semantic owner and emitter. The class already routes through [UID:0000NB] `ScreenPane` file to generated `NexusTK/ui/core/ScreenPane.cpp`.

### 2. [UID:0000NB] ScreenPane file

- Evidence for: correct source file and current generated output route; ScreenPane file owns the source root and currently documents cursor helpers as ScreenPane.cpp support.
- Evidence against: by-structure says method bodies that belong directly to a class should use the class UID as canonical owner rather than the file root.
- Decision: keep as source placement/file route, not direct owner.

### 3. [UID:0000IL] / [UID:00003E] CursorManager typed view

- Evidence for: cursor semantics, active cursor helper, width/height aliases, generated one-class output names.
- Evidence against: no constructor/destructor/allocation/singleton lifetime; `g_pCursorManager` aliases `g_pScreenPane`; cursor resource loader is startup-called on ScreenPane storage; current docs mark CursorManager non-standalone.
- Decision: reject as direct owner or source root. Preserve as typed-view/search alias only.

### 4. [UID:0000OC] Surface

- Evidence for: address neighborhood inside mixed SurfacePresentation aggregate and adjacent UID00039W presentation initializer.
- Evidence against: UID00039X has no DirectDraw presentation/global initialization, no Surface receiver, and no Surface-specific state writes. It only loads cursor resources into the ScreenPane cursor table.
- Decision: reject as owner. SurfacePresentation remains aggregate neighborhood context only.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: no new file. Use `ScreenPane` class emitted through existing `NexusTK/ui/core/ScreenPane.cpp`.
- Likely full contents: two ScreenPane cursor resource methods represented by this by-memory target, plus existing ScreenPane class methods already routed through the same file.
- Candidate related items that belong: UID0001G7 cursor selector/dimension helper support, UID0003CJ cursor resource strings, UID0002H7 startup callsite.
- Candidate related items rejected: standalone `CursorManager.cpp`, Surface presentation source root, DirectDraw/Surface helper families.
- Standalone, narrow, or broad source-file inference: narrow ScreenPane class method/helper pair inside existing broad `ScreenPane.cpp`.

## Source Placement

- Recommended source file/class/global/module placement: `ScreenPane` class in `NexusTK/ui/core/ScreenPane.cpp`.
- Why this placement fits source-tree and subsystem context: startup calls on `g_pScreenPane`, cursor selector reads the same ScreenPane table, and ScreenPane class/file docs already own the root screen object, cursor state, and generated output root.
- Rejected placements and why:
  - `CursorManager.cpp`: no independent object lifetime or global.
  - `Surface.cpp`: address-neighbor only; behavior is cursor resource loading.
  - `Application.cpp`: caller only; Application does not own cursor table.
  - Resource-only page: literals are support data, but executable behavior is ScreenPane code.
- Remaining placement uncertainty: exact original helper names and whether the raw slot loader appeared in a private header or as an unreferenced member remain unknown; this caps score but does not block ScreenPane class placement.

## Range / Split / Padding / Reclassification Analysis

- Exact range/boundary facts:
  - Modeled `0x00558f70-0x00559075` function, then eleven `0xcc` bytes to `0x00559080`.
  - Raw `0x00559080-0x005590da` helper body, then six `0xcc` bytes to successor `0x005590e0`.
  - Successor `0x005590e0` is UID00039Y callback/flag helper territory and must remain outside UID00039X.
- Children/subranges to create, repair, merge, leave ignored, or leave no-owner:
  - No child-page split required. The raw helper belongs to the same cursor resource loader source cluster.
  - Padding spans should remain documented as padding, not emitted code.
- Padding/table/data/code distinctions:
  - Cursor resource strings live in UID0003CJ `.rdata` support page and are source-declared literals, not code.
  - UID00039X contains code plus internal/boundary padding only.
- Parent/container impact:
  - SurfacePresentation aggregate child-row refresh was an original report-only suggestion but was not accepted for direct edit in the updated callback scope; the target and authorized ScreenPane support docs carry the implemented owner/score/C++ readiness facts.

## Negative Evidence Summary

- No xrefs to raw helper start `0x00559080`; this prevents a final proof of active use but does not make the byte-bounded helper padding or compiler glue.
- No separate CursorManager constructor, destructor, allocation, or singleton. Existing CursorManager pages are alias/typed-view docs and remain non-reconstructable.
- Consumer/caller evidence alone does not make Application the owner; Application only calls ScreenPane startup setup.
- Address adjacency to SurfacePresentation does not make Surface the owner; this target has no Surface-specific state or DirectDraw calls.
- IDA type catalog has ScreenPane RTTI/vtables but no complete ScreenPane UDT; field names remain inferred from docs and offsets.

## IDA Rename / Type / Comment Recommendations

- Proposed source-facing names:
  - `ScreenPane::LoadCursorResources()` for `0x00558f70`.
  - `ScreenPane::LoadCursorResourceSlot(unsigned int cursorIndex, const wchar_t *animatedCursorPath, const wchar_t *staticCursorPath)` for raw `0x00559080`.
  - `m_cursorHandles` or `m_cursorHandleTable` for table at `+0x550`.
  - `kScreenCursorNormal`, `kScreenCursorSelect`, `kScreenCursorView`, `kScreenCursorPut`, `kScreenCursorAttack`, and `kScreenCursorMax`.
- Evidence for each proposed name/type/comment: direct resource paths, ScreenPane receiver, cursor selector table use, raw helper index guard.
- Items intentionally left unchanged and why:
  - Slots `0-6`: not loaded by this target; do not invent names here.
  - Exact original helper spelling: inferred only.
  - IDA DB names: no rename requested in a report-only B-agent pass.
- Whether IDA DB edits are safe, unsafe, or not requested: not requested.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. The target is reconstructable, has an emitter route, clears the combined-score gate, and current evidence resolves behavior/source placement.
- Recommended code: exact formal `RECONSTRUCTION_CPP CODE` insertion text for supervisor-approved implementation:

```cpp
static const unsigned int kScreenCursorNormal = 7;
static const unsigned int kScreenCursorSelect = 8;
static const unsigned int kScreenCursorView = 9;
static const unsigned int kScreenCursorPut = 10;
static const unsigned int kScreenCursorAttack = 11;
static const unsigned int kScreenCursorMax = 11;

void ScreenPane::LoadCursorResources()
{
    HCURSOR cursor;

    cursor = LoadCursorFromFileW(L"Cursor\\normal.ani");
    m_cursorHandles[kScreenCursorNormal] = cursor;
    if (cursor == NULL) {
        cursor = LoadCursorFromFileW(L"Cursor\\normal.cur");
        m_cursorHandles[kScreenCursorNormal] = cursor;
        if (cursor == NULL)
            m_cursorHandles[kScreenCursorNormal] = LoadCursorW(NULL, IDC_ARROW);
    }

    cursor = LoadCursorFromFileW(L"Cursor\\select.ani");
    m_cursorHandles[kScreenCursorSelect] = cursor;
    if (cursor == NULL) {
        cursor = LoadCursorFromFileW(L"Cursor\\select.cur");
        m_cursorHandles[kScreenCursorSelect] = cursor;
        if (cursor == NULL)
            m_cursorHandles[kScreenCursorSelect] = LoadCursorW(NULL, IDC_ARROW);
    }

    cursor = LoadCursorFromFileW(L"Cursor\\view.ani");
    m_cursorHandles[kScreenCursorView] = cursor;
    if (cursor == NULL) {
        cursor = LoadCursorFromFileW(L"Cursor\\view.cur");
        m_cursorHandles[kScreenCursorView] = cursor;
        if (cursor == NULL)
            m_cursorHandles[kScreenCursorView] = LoadCursorW(NULL, IDC_ARROW);
    }

    cursor = LoadCursorFromFileW(L"Cursor\\put.ani");
    m_cursorHandles[kScreenCursorPut] = cursor;
    if (cursor == NULL) {
        cursor = LoadCursorFromFileW(L"Cursor\\put.cur");
        m_cursorHandles[kScreenCursorPut] = cursor;
        if (cursor == NULL)
            m_cursorHandles[kScreenCursorPut] = LoadCursorW(NULL, IDC_ARROW);
    }

    cursor = LoadCursorFromFileW(L"Cursor\\attack.ani");
    m_cursorHandles[kScreenCursorAttack] = cursor;
    if (cursor == NULL) {
        cursor = LoadCursorFromFileW(L"Cursor\\attack.cur");
        m_cursorHandles[kScreenCursorAttack] = cursor;
        if (cursor == NULL)
            m_cursorHandles[kScreenCursorAttack] = LoadCursorW(NULL, IDC_ARROW);
    }
}

void ScreenPane::LoadCursorResourceSlot(unsigned int cursorIndex,
                                        const wchar_t *animatedCursorPath,
                                        const wchar_t *staticCursorPath)
{
    if (cursorIndex > kScreenCursorMax)
        return;

    if (animatedCursorPath == NULL)
        return;

    HCURSOR cursor = LoadCursorFromFileW(animatedCursorPath);
    m_cursorHandles[cursorIndex] = cursor;
    if (cursor != NULL)
        return;

    if (staticCursorPath == NULL)
        return;

    cursor = LoadCursorFromFileW(staticCursorPath);
    m_cursorHandles[cursorIndex] = cursor;
    if (cursor != NULL)
        return;

    m_cursorHandles[cursorIndex] = LoadCursorW(NULL, IDC_ARROW);
}
```

- Reason it preserves exact original behavior: it preserves the order of `.ani`/`.cur` attempts, per-slot stores after each file attempt, `IDC_ARROW` fallback only after both paths fail, and raw helper early returns for out-of-range/null path inputs.
- Reason it matches the most plausible original precompiled mid-2000s developer source shape: it uses ordinary Win32 `HCURSOR`, `LoadCursorFromFileW`, `LoadCursorW`, `NULL`, and named constants instead of decompiler labels.
- Inferred source-facing names/types/fields used instead of IDA/decompiler labels: `ScreenPane`, `m_cursorHandles`, cursor constants, `LoadCursorResources`, and `LoadCursorResourceSlot`.
- Naming/coding style convention used and evidence for consistency: follows existing generated ScreenPane method naming style and current support docs' `g_pScreenPane->LoadCursorResources()` caller name.
- Reason code should remain blank, if applicable: not applicable; code should no longer remain blank after Gate 1/implementation callback.
- Exact no-code proof, if not eligible: not applicable.

## Final Recommendation

- Current implemented target state:
  - Target owner/emitter was updated from file UID `0000NB` to class UID `0000CB`.
  - Target score was raised to `90/91`.
  - Current MCP facts, raw helper evidence, range/padding evidence, slot mapping, fallback behavior, and score caps were incorporated into the target.
  - The blank formal C++ block was replaced with the code in `First-Draft C++ Recommendation`.
  - Raw helper no-xref caveat, unresolved cursor slot `0-6` caveat, and inferred exact original helper spelling caveat were preserved.
- Current accepted/applied support scope:
  - Applied: `by-class/ScreenPane.md` method/layout/cross-reference support for UID00039X.
  - Applied: `by-file/ScreenPane.md` proposed-contents/source-route support for UID00039X and CursorManager typed-view wording within the ScreenPane file context.
  - Applied: `by-memory/0x00557380-0x00557467.ScreenCursorHelpers.md` cross-reference sync from the `+0x550` cursor handle table to UID00039X slot initialization.
- Original broader support recommendations excluded from the updated callback scope:
  - `by-memory/0x00557140-0x00559aef.SurfacePresentation.md`: not edited because the updated `goal.md` only allowed the target, ScreenPane class/file pages, and related ScreenPane cursor-helper docs needed for cross-reference sync. No accepted callback item required direct aggregate-page mutation.
  - `by-file/CursorManager.md` and `by-class/CursorManager.md`: not edited because direct CursorManager-page edits were outside the updated callback scope. The accepted fact that CursorManager remains a typed view/search alias was applied in the target and authorized ScreenPane support docs instead.
  - `by-memory/0x0062317c-0x00623480.ScreenPaneResourceStringData.md`: not edited because direct resource-string data-page edits were outside the updated callback scope. The ten cursor literal facts were incorporated into the target and ScreenPane support docs.
- Exact parent assignments:
  - Direct semantic owner/emitter: [UID:0000CB] `ScreenPane`.
  - Source file route remains [UID:0000NB] `ScreenPane` / `NexusTK/ui/core/ScreenPane.cpp`.
- Exact items left no-owner/non-emitting and why:
  - None inside UID00039X. Padding spans remain non-emitting alignment, not child source.
- Exact future work outside this assignment scope:
  - Later cursor/UI pass may name slots `0-6` if other loaders/callers prove them.
  - Later final-audit pass may decide whether `LoadCursorResourceSlot` should stay emitted as a retained no-xref helper or be split under a project-wide retained-helper policy. Current recommendation keeps it emitted with the target.

## Recommended Target Doc Changes

- Target path: `by-memory/0x00558f70-0x005590da.ScreenPaneCursorResourceLoader.md`.
- Exact report facts to incorporate:
  - Add current MCP session `18aed30a` evidence for modeled function, raw helper, xrefs, bytes, literals, and generated empty marker.
  - Add source-facing names and slot mapping described in this report.
  - Add raw helper body semantics and zero-xref caveat.
  - Add first-draft formal C++ block.
  - Update status from "C++ remains blank until cursor table names and final resource-loader split are source quality" to "first-draft C++ ready; exact original names and raw-helper liveness cap final score."
- Metadata/score/owner/emitter/reconstructable/C++ changes:
  - `COMPLETION:90`
  - `CONFIDENCE:91`
  - `CANONICAL_OWNER:0000CB`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:0000CB`
  - `EMITTER_POSITION_OPTIONAL:` blank
  - `RECONSTRUCTION_CPP CODE`: insert exact code from this report.
- Historical/stale assumptions, rejected alternatives, and negative evidence to preserve:
  - Preserve CursorManager typed-view rejection.
  - Preserve Surface address-neighborhood rejection.
  - Preserve raw helper `0x00559080` no-xref caveat.
  - Preserve that exact original method/helper spelling remains inferred.

## Recommended Support Doc Changes

Current accepted/applied support docs:

- Support path: `by-class/ScreenPane.md`.
  - Applied: added `LoadCursorResources` and retained `LoadCursorResourceSlot` to the ScreenPane method/helper inventory.
  - Applied: expanded layout notes for `m_cursorHandles` at `+0x550`: slots 7-11 are normal/select/view/put/attack; active cursor index remains `+0x580`; slots `0-6` remain unnamed here.
  - Applied: cross-linked UID00039X and noted first-draft C++ readiness.
- Support path: `by-file/ScreenPane.md`.
  - Applied: added UID00039X to Proposed Contents as class-owned cursor resource loader emitted through `ScreenPane.cpp`.
  - Applied: stated within the ScreenPane file context that CursorManager remains a typed view and not a standalone source root for this loader.
- Support path: `by-memory/0x00557380-0x00557467.ScreenCursorHelpers.md`.
  - Applied: synced the `this+0x550` cursor handle table note to UID00039X, which initializes slots 7-11 as normal/select/view/put/attack.
  - Applied: preserved that slots `0-6` remain outside UID00039X evidence and preserved the helper page's existing owner/score.

Original report-only support suggestions intentionally excluded from the updated callback:

- Support path excluded: `by-memory/0x00557140-0x00559aef.SurfacePresentation.md`.
  - Exclusion reason: the updated callback scope did not authorize direct SurfacePresentation aggregate edits. The accepted target/source-route facts were applied to the target and authorized ScreenPane support docs; any aggregate child-row refresh is left to a later explicitly authorized pass or generated/supervisor-owned workflow.
- Support paths excluded: `by-file/CursorManager.md` and `by-class/CursorManager.md`.
  - Exclusion reason: the updated callback scope did not authorize direct CursorManager page edits. The accepted conclusion that CursorManager is not the owner and remains a typed view/search alias was applied in the target, `by-class/ScreenPane.md`, `by-file/ScreenPane.md`, and the cursor-helper cross-reference page.
- Support path excluded: `by-memory/0x0062317c-0x00623480.ScreenPaneResourceStringData.md`.
  - Exclusion reason: the updated callback scope did not authorize direct resource-string data-page edits. The ten cursor resource literal facts and one-xref evidence were applied in the target and authorized ScreenPane support docs.

Generated output state after applied scoped validation:

- `auto-generated/NexusTK/ui/core/ScreenPane.cpp` no longer contains the UID00039X empty marker and contains the formal loader code after validator command `000000007605`. This generated file was not edited by hand.

## Score And Metadata Recommendation

- Current score/metadata: `86/89`, `CANONICAL_OWNER:0000NB`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000NB`, blank formal C++.
- Recommended score/metadata: `90/91`, `CANONICAL_OWNER:0000CB`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CB`, blank optional position, formal C++ populated.
- Score rationale and reason not higher/lower:
  - Higher than current because current MCP resolves exact behavior, strings, slots, padding, raw helper semantics, startup caller, direct class owner, and formal C++ readiness.
  - Not higher than `90/91` because exact original helper spellings are inferred, raw helper start has zero xrefs, and this target does not recover cursor slots `0-6`.
  - Not lower because the remaining uncertainty no longer blocks first-draft source output for the exact behavior in UID00039X.
- Score-improvement attempt:
  - Ownership/emitter blocker: resolved to `ScreenPane` class with ScreenPane file route.
  - Source placement blocker: resolved by startup receiver and table writes; rejected CursorManager/Surface alternatives.
  - Naming blocker: resolved slots 7-11 from literal names; helper names remain inferred but source-facing enough.
  - Raw helper liveness blocker: exhausted with `lookup_funcs`, `xrefs_to`, bytes, bounded rendered listing search, and support docs. It remains a score cap, not a no-code blocker.
  - First-draft C++ blocker: resolved with exact formal code.
- Metadata fields to change or leave unchanged:
  - Change owner/emitter and score as above.
  - Keep reconstructable `TRUE`.
  - Keep optional position blank unless supervisor wants ordering under ScreenPane class.

## Open Questions With Attempted Resolution

- Open question: are slots `0-6` named cursor states?
  - Evidence checked: UID00039X modeled loader, raw helper guard, ScreenCursorHelpers docs, CursorManager docs.
  - Best supported resolution: UID00039X only proves slots 7-11. Do not name slots `0-6` in this pass.
  - Remaining impact: score cap only; does not block this target's formal C++ for loaded slots.
- Open question: should raw `0x00559080` be emitted despite no start xrefs?
  - Evidence checked: `xrefs_to` start zero, bounded raw helper search, byte body, shared ScreenPane table writes, B005 UID00039Y retained-helper precedent as a needs-revalidation adjacent lead only.
  - Best supported resolution: keep raw helper in this target and include source body with no-xref caveat. The body is source-authored and semantically tied to the loader.
  - Remaining impact: confidence cap; supervisor can choose to omit the raw helper body only under an explicit retained-helper non-emission policy.
- Open question: exact original names?
  - Evidence checked: IDA names/types, generated output, docs, B007 caller mapping.
  - Best supported resolution: use inferred source-facing `LoadCursorResources`, `LoadCursorResourceSlot`, and cursor constants. Original-proof is unavailable, but raw `sub_*` names are worse for reconstruction quality.
- Open question: standalone CursorManager source?
  - Evidence checked: CursorManager file/class/global docs, ScreenPane singleton docs, current MCP type/name checks.
  - Best supported resolution: no standalone source root; keep typed-view docs only.

## Follow-Up Actions

- Supervisor actions: perform a fresh post-callback Gate 1 audit of this repaired report artifact. If Gate 1 passes, proceed with supervisor-owned Gate 2 implementation verification against the changed by-* docs and scoped validator outputs.
- B010 actions remaining: none for this repair. B010 stops at `READY_FOR_SUPERVISOR_GATE1_REVIEW`.
- A-agent actions: none required for this callback.

## Confidence

- Recommendation confidence: high.
- Score confidence: high for implemented `90/91`, deliberately below final-audit.
- Remaining uncertainty: raw helper no-xref liveness, exact original helper spelling, and cursor slot `0-6` names. These are documented score caps, not unapplied implementation blockers.

## Validator Results

- `python .\tools\validator.py --mode file --file by-memory/0x00558f70-0x005590da.ScreenPaneCursorResourceLoader.md --apply --queue-timeout 240`
  - `command_id: 000000007602`
  - `command_timestamp: 2026-07-06T17:58:58-04:00`
  - Exit code: `0`
  - `ok: 1`
  - Relevant updates: completion `90`, confidence `91`, canonical owner `0000NB -> 0000CB`, autogen owner/emitter route `0000NB -> 0000CB`, formal C++ hash stored, code state `blank -> block`.
  - Warnings: none target-specific. Generated refresh was deferred by this command.
- `python .\tools\validator.py --mode file --file by-class/ScreenPane.md --apply --queue-timeout 240`
  - `command_id: 000000007603`
  - `command_timestamp: 2026-07-06T17:59:04-04:00`
  - Exit code: `0`
  - `ok: 1`
  - Relevant updates: UID00039X added to the reference index for `by-class/ScreenPane.md`.
  - Warnings: `missing_ref_uid: 34` for older existing ScreenPane references such as `00039R`, `00039P`, `00039Y`, `00039Z`, and `0003A2`; UID00039X was accepted and these warnings are not target-specific implementation failures.
- `python .\tools\validator.py --mode file --file by-file/ScreenPane.md --apply --queue-timeout 240`
  - `command_id: 000000007604`
  - `command_timestamp: 2026-07-06T17:59:16-04:00`
  - Exit code: `0`
  - `ok: 1`
  - Relevant updates: UID00039X added to the reference index for `by-file/ScreenPane.md`.
  - Warnings: `missing_ref_uid: 34` for older existing ScreenPane references such as `00039R`, `00039Y`, `00039Z`, `00039P`, and `0003A4`; UID00039X was accepted and these warnings are not target-specific implementation failures.
- `python .\tools\validator.py --mode file --file by-memory/0x00557380-0x00557467.ScreenCursorHelpers.md --apply --queue-timeout 240`
  - `command_id: 000000007605`
  - `command_timestamp: 2026-07-06T17:59:27-04:00`
  - Exit code: `0`
  - `ok: 1`
  - Relevant updates: UID00039X and UID0003A3 reference-index entries accepted for the cursor-helper page.
  - Warnings: none.
- Generated ScreenPane freshness: `auto-generated/NexusTK/ui/core/ScreenPane.cpp` now has `validator-command-id: 000000007605`, `validator-refreshed-at: 2026-07-06T17:59:27-04:00`, `validator-refresh-source: deferred-generated-refresh`, and contains UID00039X `ScreenPane::LoadCursorResources()` plus `ScreenPane::LoadCursorResourceSlot(...)`.
- Validator-managed side effects reported: generated refresh, `project-level/-auto-completion-stats.md` projected path completion updates, and validator registry/autogen metadata updates. These were produced by scoped validators, not manual edits.
- Same-report Gate 1 repair note: this repair edited only the B010 report text, made no by-* edits, and ran no new validators.

## Changed Files

- Created/updated report: `tools/leaser/Agents/Agent-B010/research/00039X-ScreenPaneCursorResourceLoader-source-quality.md`.
- Same-report Gate 1 repair change: updated this report only to align `Final Recommendation`, `Recommended Support Doc Changes`, Claim/Incorporation Ledger, and Implementation Tracking Checklist on the accepted/applied support scope.
- Modified manually under B010 lease:
  - `by-memory/0x00558f70-0x005590da.ScreenPaneCursorResourceLoader.md`
  - `by-class/ScreenPane.md`
  - `by-file/ScreenPane.md`
  - `by-memory/0x00557380-0x00557467.ScreenCursorHelpers.md`
- Validator-managed/generated side effects observed:
  - `auto-generated/NexusTK/ui/core/ScreenPane.cpp` refreshed with UID00039X code.
  - `project-level/-auto-completion-stats.md` projected path completion section updated.
  - Validator registry/autogen metadata updated through scoped validator commands.
- Renamed: none.
- Report execution: not run. B010 did not run `tools/validator.py execute_report`, dry-run/probing variants, registry lifecycle commands, manual report moves, archive moves, or any equivalent report execution/archive command.
- Leases: B010 lease command returned `Success` for the four manually edited by-* docs; B010 unlease command returned `Success` for the same four paths after validation.
- Same-report Gate 1 repair leases/validators: no leases were needed for editing this report in B010's own research folder, and no validators were run because no by-* docs were edited during this repair.

## Implementation Tracking Checklist

Gate 1 / callback scope:

- [x] Supervisor validation required before implementation: satisfied by supervisor Gate 1 audit entry `2026-07-06T17:50:30-04:00 - B010 UID00039X Gate 1 Audit`.
- [x] Apply updated `goal.md` callback scope: target, `by-class/ScreenPane.md`, `by-file/ScreenPane.md`, and related ScreenPane cursor-helper cross-reference page were edited. Broader original-report support recommendations for SurfacePresentation, CursorManager pages, and resource-string data were not directly edited because the updated callback scope did not authorize those pages.
- [x] Excluded support path `by-memory/0x00557140-0x00559aef.SurfacePresentation.md`: not accepted for direct edit in the updated callback scope; aggregate child-row refresh remains outside this callback.
- [x] Excluded support paths `by-file/CursorManager.md` and `by-class/CursorManager.md`: not accepted for direct edit in the updated callback scope; the CursorManager typed-view conclusion was applied through the target and authorized ScreenPane support docs.
- [x] Excluded support path `by-memory/0x0062317c-0x00623480.ScreenPaneResourceStringData.md`: not accepted for direct edit in the updated callback scope; literal facts were applied in the target and authorized ScreenPane support docs.
- [x] Lease only immediate edit/validator batch: leased four by-* docs as B010 immediately before edits; release command succeeded for all four after validators.

Applied target/support edits:

- [x] Target metadata applied in `by-memory/0x00558f70-0x005590da.ScreenPaneCursorResourceLoader.md`: `COMPLETION:90`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000CB`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CB`, blank `EMITTER_POSITION_OPTIONAL`.
- [x] Formal C++ inserted into the target `RECONSTRUCTION_CPP CODE` block exactly from the report's `First-Draft C++ Recommendation`.
- [x] Target evidence incorporated: MCP session `18aed30a`, health ok for `NexusTK.exe.i64`, modeled loader `0x00558f70-0x00559075`, raw helper `0x00559080-0x005590da`, padding at `0x00559075-0x00559080` and `0x005590da-0x005590e0`, successor `0x005590e0`, startup caller `0x004f61c9`, cursor table slots 7-11, ten cursor literals, `.ani`/`.cur`/`IDC_ARROW` fallback behavior, and raw-helper no-xref caveat.
- [x] Target ownership/source-placement analysis applied: direct owner/emitter rerouted from file UID `0000NB` to class UID `0000CB`, generated route preserved through ScreenPane file, and CursorManager/Surface/no-owner/non-emitting alternatives rejected with evidence.
- [x] Target score rationale applied: `90/91`, not higher because raw helper liveness, exact original names, and slots `0-6` remain unresolved; not lower because behavior, source route, slot mapping, and first-draft C++ are resolved.
- [x] `by-class/ScreenPane.md` support sync applied: method row for UID00039X, layout note for `m_cursorHandles` / `+0x550`, slots 7-11 normal/select/view/put/attack, cross-reference, and change-log entry.
- [x] `by-file/ScreenPane.md` support sync applied: proposed contents row for UID00039X, CursorManager typed-view wording, evidence note closing old cursor-loader follow-up language, cross-reference, and change-log entry.
- [x] `by-memory/0x00557380-0x00557467.ScreenCursorHelpers.md` cross-reference sync applied: `this+0x550` active cursor table now points to UID00039X initialization of slots 7-11 while preserving the helper page's owner/score and slots `0-6` caveat.
- [x] Historical/stale assumptions and negative evidence preserved: standalone CursorManager rejected, Surface owner rejected, raw helper zero-xref caveat retained, exact original helper names and slot `0-6` limitations retained.
- [x] Wave2/Wave3 stale artifacts: none used as authority; generated output used only as lead/state evidence and validator-generated refresh state.
- [x] Third-party import directive: not applicable; this is NexusTK-owned ScreenPane code and the formal multiline C++ block is populated.
- [x] Split/rename/new-child changes: none; no split or rename recommended or performed.
- [x] IDA DB changes: none requested or performed.

Ledger / validation / generated state:

- [x] Claim And Incorporation Ledger updated: accepted target/ScreenPane-scope claims are `applied`; original broader support-page suggestions for SurfacePresentation, direct CursorManager pages, and resource-string data are explicitly `excluded-with-reason` because the updated callback scope did not authorize those direct edits.
- [x] Scoped validators run and recorded: commands `000000007602`, `000000007603`, `000000007604`, and `000000007605`, all exit code `0`, all `ok: 1`.
- [x] Generated ScreenPane refresh checked: `auto-generated/NexusTK/ui/core/ScreenPane.cpp` header is `validator-command-id: 000000007605`, `validator-refreshed-at: 2026-07-06T17:59:27-04:00`, and UID00039X code is present.
- [x] Generated report refresh / manual tracker text: no manual coverage/tracker text supplied or applied; validator-managed generated/state outputs refreshed through scoped validators only.
- [x] Remaining unapplied accepted items: none within updated `goal.md` callback scope.
- [x] Same-report Gate 1 repair: `Final Recommendation`, `Recommended Support Doc Changes`, Claim/Incorporation Ledger, and this checklist now agree that only the target, ScreenPane class/file support, and ScreenCursorHelpers cross-reference were accepted/applied; SurfacePresentation, direct CursorManager pages, and resource-string data page are excluded/out-of-scope with concrete reasons.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000007627","destination_path":"executed-b-agent-research/B010/00039X-ScreenPaneCursorResourceLoader-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B010/research/00039X-ScreenPaneCursorResourceLoader-source-quality.md","timestamp":"2026-07-06T18:32:14-04:00","uid":"00039X"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
