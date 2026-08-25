** TARGET-REPORT-UID:0003PI **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0003PI RainingLayerPaneConstructor Source-Quality Research


## Finalized Report / Current Recommendation

- Current recommendation: accept the completed ordinary-document implementation that promoted [UID:0003PI] `RainingLayerPaneConstructor` from the historical code-empty `86/88` state to a source-ready `92/94` constructor with direct owner/emitter [UID:0000BJ] `RainingLayerPane` unchanged.
- Final disposition: one exact source-authored no-argument `RainingLayerPane::RainingLayerPane()` body at `[0x005c1410,0x005c145a)`. It calls the implicit `WeatherLayerPane` base constructor, installs compiler-generated Rain vptrs, and performs three source-visible assignments: `m_timerInterval = 120`, `m_frameCount = 3`, and inherited Pane direct-target paint mode `m_drawOnTarget = true`.
- Required action: the exact post-callback artifact SHA256 `8294F430EADFBBEE4BC873B25C9C8C06BBE5B4E9F3C45C7E28E143492EDB9B76` passed supervisor post-callback Gate 1, Gate 2A, and Gate 2B. This report-only reconciliation now requires a fresh final exact-artifact Gate 1/Gate 2 continuity audit, supervisor-only execution/archive, and only then the supervisor-owned manual coverage replacements.
- Confidence: very strong for range, bytes, ABI, caller, base call, object size, fields, constants, vptrs, ownership, emitter, source family, and behavior; strong inferred confidence for the original lexical spelling `m_drawOnTarget`, whose behavior is directly proved even though no source symbol survives.

## Supporting Research

- This report began as a report-only artifact. After supervisor Gate 1 acceptance of SHA256 `5FE6F7FBC2562EB797D2D44FBEF476880DE444843D206A80FD5A31ECDDBEB064`, B003 implemented the accepted ordinary-document claims in ten by-* destinations and ran serial scoped validators. B003 did not edit manual coverage, generated/tracker, audit, supervisor, goal, lifecycle, or IDA state directly.
- Live read-only IDA MCP was mandatory and available throughout the evidence pass at `http://127.0.0.1:13337/mcp`.
- Fresh MCP `idb_list` returned one active non-analyzing worker session, `supervisor_gate2b_0002OT_20260723`, for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `3368`.
- Fresh `server_health` returned `status:ok`, module `NexusTK.exe`, input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, image base `0x400000`, `hexrays_ready:true`, `strings_cache_ready:true`, and 2,067 cached strings. `auto_analysis_ready:false` was recorded exactly; narrow lookup, bytes, xref, type, disassembly, and decompilation calls all completed successfully, so MCP was responsive rather than unavailable or busy.
- Current executable identity is 2,679,296 bytes, SHA256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`.
- Historical target ordinary-doc checkpoint before the callback: SHA256 `F03EA97BB6E44AE982CDC921A8DEC488DFF091A017BB75637040621F6F7E3B14`, 5,113 bytes, 60 physical lines. Current post-callback target checkpoint is SHA256 `38D83C1072B965403FE70AEB9D36D8C91FB74B33ABC96FB92271D0D2A1C57708`, 11,792 bytes, 99 physical lines.
- Historical initial evidence-pass generated checkpoint: `auto-generated/NexusTK/map/WeatherLayerPane.cpp` at validator command `000000017005`, refreshed `2026-07-24T00:34:37-04:00`, SHA256 `4FE50C6D197FE9EF8428198410AA252CDE334C97A825710FD5B72DC68EE6538F`, 14,542 bytes, 336 lines, with UID0003PI at historical line 330.
- Historical second generated checkpoint: `auto-generated/NexusTK/map/WeatherLayerPane.cpp` at validator command `000000017016`, refreshed `2026-07-24T00:51:53-04:00`, SHA256 `EDFA6113377EAB9CA92F0A2134286B2B931A65D1258DC1D94482DD1F93FBB7D7`, 15,104 bytes, 355 lines, with UID0003PI at historical line 351.
- Historical third generated checkpoint captured immediately before the first repair edit: `auto-generated/NexusTK/map/WeatherLayerPane.cpp` at validator command `000000017029`, refreshed `2026-07-24T01:17:14-04:00`, SHA256 `0762A0F4A68ED0D47697705DF157D0BF07214D6EB7D706430301B96054A0BAAD`, 17,600 bytes, 425 lines, with UID0003PI at line 423.
- Fresh generated readback captured after the post-edit drift check: `auto-generated/NexusTK/map/WeatherLayerPane.cpp` at validator command `000000017030`, refreshed `2026-07-24T01:17:42-04:00`, SHA256 `9E45C70A4B6B2AA32906365293AF2B92DB22085C7812B367268B40508B0D1C78`, 17,600 bytes, 425 lines, with one UID0003PI empty-emitter marker at line 423. This is an exact timestamped checkpoint; later unrelated validator refreshes may advance the generated header without changing the target state.
- Historical initial evidence-pass research-tracker checkpoint: validator command `000000017009`, refreshed `2026-07-24T00:36:01-04:00`, SHA256 `2181C9BF32F3FE42801A3BD47CFBB8D2061025BDB7E337672D2E389F3232D38B`, 1,640,183 bytes, 6,518 lines, with UID0003PI at historical line 1672.
- Historical second research-tracker checkpoint: validator command `000000017017`, refreshed `2026-07-24T00:56:56-04:00`, SHA256 `565E044A5CC4E9218BD2FE92016E3905ED5348F0C377C8784FB03872CE1DF9B2`, 1,640,326 bytes, 6,518 lines, with UID0003PI at historical line 1671.
- Historical third research-tracker checkpoint captured immediately before the first repair edit: validator command `000000017029`, refreshed `2026-07-24T01:17:14-04:00`, SHA256 `F888F3E21848BF5A4FCBD648B4AE30EF9478EFAF22F60795881D6F2315FD206F`, 1,640,561 bytes, 6,519 lines, with UID0003PI at line 1670.
- Fresh research-tracker readback captured after the post-edit drift check: validator command `000000017030`, refreshed `2026-07-24T01:17:42-04:00`, SHA256 `BB07550671A294095EABC6FC33F388A8DB1FE2013D02E50E8F134D11B874282A`, 1,640,561 bytes, 6,519 lines; UID0003PI is at line 1670 with `86/88`, average `87.0`, reconstructable true, and direct/additional/total report coverage `0/0/0` before this report is executed. This is an exact timestamped checkpoint; later unrelated validator refreshes may advance the generated header without changing the target row.
- Post-callback validator-owned generated readback after command `000000017059`: `auto-generated/NexusTK/map/WeatherLayerPane.cpp`, validator refresh timestamp `2026-07-24T01:35:14-04:00`, final saved-file checkpoint SHA256 `48F38B2A848F2B2C874231114569E28B7B562C9D33E7DA782F9C6419CEBD7009`, 17,829 bytes, 433 lines. UID0003PI appears exactly once as the qualified constructor at lines 148-154 and has zero empty-emitter markers. Later unrelated validator refreshes may advance this shared generated file without changing the verified UID0003PI content.
- Post-callback validator-owned tracker readback after command `000000017059`: `auto-generated/-ag-research-tracker.md`, validator refresh timestamp `2026-07-24T01:35:14-04:00`, final saved-file checkpoint SHA256 `45654E18615CA8176704E9E0B7870F8F47369B048B0CA822703D746F4C1E1366`, 1,640,946 bytes, 6,520 lines. UID0003PI is at line 3356 with `92/94`, average `93.0`, reconstructable true, and direct/additional/total report coverage `0/0/0` before supervisor execution. Later unrelated validator refreshes may advance this shared tracker without changing the verified row.
- Supervisor post-callback Gate 1 passed the exact report SHA256 `8294F430EADFBBEE4BC873B25C9C8C06BBE5B4E9F3C45C7E28E143492EDB9B76`, 71,556 bytes, 585 lines, with all 33 required H2 headings, 32 unique claims, one complete managed formal, 30 checked/four supervisor-owned unchecked rows, one readiness marker, and ASCII-only content.
- Supervisor Gate 2A at `2026-07-24T02:03:00-04:00` independently verified C3PI-01 through C3PI-28 and C3PI-31 against all ten current destinations. Supervisor commands `000000017065` through `000000017074` each exited `0` with `ok:1`; the exact command-to-destination map and audit readback are recorded under `Validator Results`.
- Gate 2A audit generated checkpoint: `auto-generated/NexusTK/map/WeatherLayerPane.cpp` SHA256 `D94DF635BCC6BE71ECB24C5235B5AB4F187CA785F50ED975485290F58B2A6F81`, 17,829 bytes, with one UID0003PI occurrence, one qualified constructor, and zero UID0003PI empty-emitter markers. This is the exact Gate 2A checkpoint; later unrelated generated refreshes may advance the shared file without changing the verified constructor.
- Supervisor Gate 2B at `2026-07-24T02:04:56-04:00` applied and verified C3PI-29/C3PI-30. B003 did not mutate IDA; the full supervisor-owned backup, pre-state, actions, readback, preservation, and save checkpoint are recorded in the exact IDA section below.

## Target

- Target UID: `0003PI`.
- Additional target UIDs: none.
- Declared-target inventory: [UID:0003PI] `by-memory/0x005c1410-0x005c145a.RainingLayerPaneConstructor.md`, exact Rain constructor body and sole primary report target.
- Target path: `source-3/project-documentation/by-memory/0x005c1410-0x005c145a.RainingLayerPaneConstructor.md`.
- Gate 2A source-queue checkpoint after supervisor command `000000017074`: `auto-generated/-ag-research-tracker.md` line 3356, `92/94`, average `93.0`, reconstructable true, report coverage `0/0/0` before supervisor execution.
- Historical source-queue checkpoints: command `000000017009` placed the same unchanged row at line 1672, command `000000017017` placed it at line 1671, and command `000000017029` placed it at line 1670; these remain timestamped observations rather than durable latest-state labels.
- Current supervisor classification: completed reconstructable by-memory source-quality implementation with documentation and IDA gates passed, awaiting final exact-artifact audit and supervisor lifecycle execution.
- Current scores and parent state: target `92/94`, `CANONICAL_OWNER:0000BJ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000BJ`; direct class parent [UID:0000BJ] is `91/93` and routes through [UID:0000P8] `WeatherLayerPane.cpp` at `92/93`.

## Current Target State

- Current metadata: `COMPLETION:92`, `CONFIDENCE:94`, `CANONICAL_OWNER:0000BJ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000BJ`, blank optional position.
- Existing owner/emitter/reconstructable state: correct and unchanged. The direct semantic owner is [UID:0000BJ] `RainingLayerPane`; its class emitter reaches canonical source family [UID:0000P8] `WeatherLayerPane`.
- Current C++/emitter state: the target formal contains the accepted exact three-assignment constructor, and current generated `WeatherLayerPane.cpp` contains one qualified UID0003PI body and zero UID0003PI empty-emitter markers.
- Historical open questions and stale assumptions preserved after implementation:
  - The target says final field/helper names and one-file versus per-layer placement block C++. Current evidence resolves the four Weather tail fields and selects `WeatherLayerPane.cpp`; that blocker is stale.
  - Historical text calls `Pane+0xf6` merely enabled, visibility, or reserved state. Live cross-function evidence proves its concrete behavior: true suppresses generic `OnPaint` dispatch during recursive dirty-region handling for the three concrete weather panes, consistent with their virtual direct-target drawing path.
  - Historical 120-frame, maximum-frame, and frame-step interpretations are already superseded by current docs. This report preserves that history while using exact `m_frameCount = 3` and `m_timerInterval = 120` milliseconds.
  - The constructor ABI returns `this` in EAX, but source C++ remains a normal constructor with no source return type.
- Related target/support docs checked: UID0003PI target; UID0000BJ class; UID0000MY historical file; UID0000P8 canonical file; UID0000G1 Weather class; UID0003PG Weather constructor; UID0003PH Weather timer; UID0003PJ Rain OnPaint; UID0003PK Rain DrawOnTarget; UID0001NZ aggregate; UID0002Z8 Rain vtable data; UID0001WJ Weather layouts; UID0001VH Pane layout; UID0003O0 Snow constructor; UID0001O2 Swallow core; current generated output, research tracker, memory coverage, and manual coverage rows; executed reports B001 UID0001NZ, B008 UID0000P8, B003 UID0002Z8, B002 UID0001O2, and B005 UID0003PJ.
- Current artifact/lifecycle status: pre-callback Gate 1, ordinary implementation, post-callback Gate 1, Gate 2A documentation verification, and Gate 2B IDA application/readback are complete. This reconciled exact report still requires a fresh final Gate 1/Gate 2 continuity audit, supervisor-only execution/archive, and post-execution C3PI-32 manual coverage application.

## Executive Recommendation

- Keep direct owner/emitter [UID:0000BJ] `RainingLayerPane`; do not route the exact method directly to the aggregate or file page.
- Keep [UID:0001NZ] as a non-emitting migration/index container. UID0003PI is already the exact source-bearing child and needs no split, merge, rename of the documentation file, or additional UID.
- UID0003PI formal C++ is populated with the exact constructor body and the direct target is `92/94`.
- Treat `Pane+0xf6` as inherited bool-like direct-target paint mode. The preferred source spelling is `m_drawOnTarget`; retain `m_usesDirectTargetDrawing` as a descriptive alias in evidence, not as a second field.
- Support prose now records `+0xf6` as direct-target paint mode while preserving the separate proven Pane visibility byte at `+0xb4`; the two fields are not conflated.
- Keep vptr assignments, adjusted subobject vptrs, constructor return-in-EAX behavior, caller EH cleanup, and deleting-destructor/vtable material out of handwritten source.

## Supervisor Active Recheck

- The original `goal.md` assigned UID0003PI exhaustive report-only research; supervisor Gate 1 then explicitly authorized the ordinary-document callback. Healthy live MCP evidence remains the research basis. B003 made no IDA or lifecycle mutation; the supervisor separately completed Gate 2B.
- No split repair is required. The exact function child already exists with correct half-open bounds and direct class route.
- Every source-bearing function involved in the constructor chain is documented: UID0003PI is the Rain constructor, UID0003PG is the base Weather constructor, UID0003PJ/UID0003PK are the Rain virtual render methods, and UID0003PH is the shared Weather timer callback. This report does not duplicate bodies owned by those siblings.
- UID0003PG had an independent B001 target-specific assignment during the evidence pass. B003 reread every overlapping destination before editing and preserved the current UID0003PG/UID0003PH/UID0003PJ/UID0003PK details rather than overwriting them from the older report snapshot.

## Inference Research Guidance Check

- The project inference discipline requires a best human source reconstruction when symbols are gone; it forbids retaining `sub_5C1410`, offset-only writes, `_WORD *this`, manual vptr stores, or reverse-engineered casts in final C++ merely because original lexical spellings are unavailable.
- `by-structure.md` exact-child rules support keeping UID0003PI as the sole method emitter while UID0001NZ remains an index and UID0000BJ remains a class-level child router.
- IDA facts, documentation evidence, and inference are separated below:
  - IDA facts: exact bytes, bounds, stores, xrefs, vptrs, caller allocation, base call, and the only modeled read/write family for `+0xf6`.
  - Documentation evidence: accepted Weather/Rain hierarchy, exact tail types, source family, header contract, and sibling render roles.
  - Inference: the source lexical name `m_drawOnTarget` and ordinary compact constructor-body formatting.
- Existing assumptions treated as uncertain and rechecked: dedicated `RainingLayerPane.cpp`, generic enabled/visibility meaning for `+0xf6`, final C++ blank due field names, and decompiler return type.
- Wave2/Wave3 mentions found in old project material were ignored as stale under current instructions. None is used as evidence or workflow authority in this report.

## Heuristic / Inference Reanalysis And Validation

| Issue | Reanalysis | Best resolution | Classification |
| --- | --- | --- | --- |
| `sub_5C1410` | RTTI/vptr stores name `RainingLayerPane`; sole caller allocates `0x10c` for weather selector 1 and calls the target; exact class child already owns it. | `RainingLayerPane::RainingLayerPane()` / IDA-safe `RainingLayerPane__RainingLayerPane`. | Source identity very strong; original mangled constructor symbol absent. |
| Decompiler `_WORD *__thiscall(_WORD *this)` | ECX carries the allocated object; no explicit stack arguments; EAX is set to `this` for constructor ABI. | Source constructor has no return type and no explicit parameters. IDA prototype may model `RainingLayerPane *` return for decompilation. | ABI exact; source shape exact. |
| Base call `sub_5C12A0` | Live caller/callee graph and three derived callers identify the shared Weather constructor. It calls Pane construction, installs Weather vptrs, initializes the Weather tail/bounds, and schedules timer state. | Implicit `WeatherLayerPane()` base construction; no raw helper call in source body. | Very strong. |
| `+0xfa = 120` | A 16-bit store from AX follows `mov eax,0x78`; UID0003PH consumes signed interval for timer rescheduling. | inherited `short m_timerInterval = 120` milliseconds. | Exact field/constant and role. |
| `+0xf9 = 3` | One byte store; UID0003PH compares the incremented signed frame against this byte; UID0003PJ indexes three rain table frames. | inherited `signed char m_frameCount = 3`. | Exact field/constant and role. |
| `+0xf6 = 1` | Pane construction clears word `+0xf5/+0xf6`; only Rain/Snow/Swallow constructors set `+0xf6`; `Layer_UpdateDirtyRegionsRecursive` tests it once and calls vtable slot `+0x44` (`OnPaint`) only when zero. Rain/Snow/Swallow also expose specialized direct-target rendering. | inherited bool-like direct-target paint mode, preferred source name `m_drawOnTarget`; source assignment `true`. | Behavior exact; lexical spelling inferred/high probability. |
| Visibility hypothesis | Pane `+0xb4` is separately proved as the Show/Hide visibility byte. Therefore calling `+0xf6` `m_isVisible` creates two visibility fields and contradicts the unique consumer. | Reject `m_isVisible`, `m_weatherVisible`, and generic `enabled`. | Rejected by direct field separation and consumer semantics. |
| Reserved/padding hypothesis | `+0xf6` has one live read and three concrete writes; it is not inert padding. | Reject reserved/adjacent-motion-only treatment. | Rejected by live code. |
| Rain-added storage | Caller allocates exactly `0x10c`; current `RainingLayerPane` and Weather layout are both `0x10c`; all source assignments touch inherited state. | Rain adds no fields. | Exact. |
| Source file | Current class/file routes, contiguous Weather/Rain/Snow/Swallow code and RTTI, accepted rain table ownership, and generated output select `NexusTK/map/WeatherLayerPane.cpp`. | Emit qualified constructor through UID0000BJ into UID0000P8. | Current project source route very strong. |
| Header placement | Accepted class/layout docs require complete `WeatherLayerPane : Pane` and storage-free `RainingLayerPane : WeatherLayerPane`. | Declaration belongs in canonical `WeatherLayerPane.h`; this target emits only the out-of-line constructor definition. | Very strong project source contract. |
| Vptr stores | Three compiler-generated writes select primary and adjusted Rain views. | Omit from handwritten C++; compiler emits them from inheritance. | Exact compiler/source distinction. |
| EH/cleanup | Target itself has no SEH record or local cleanup. Caller has allocation-state cleanup; base constructor has Pane unwind cleanup. | No try/catch/delete/unwind source in Rain constructor. | Exact. |
| Score blocker | Previous blank-body reason cites unresolved names/source split. Current evidence resolves behavior, best source name, ownership, source route, and exact body. | Raise to `92/94`; do not leave marker empty. | Resolved. |

Rejected alternatives:

- Dedicated `RainingLayerPane.cpp`: retained only as historical secondary placement; current canonical route is UID0000P8 `WeatherLayerPane.cpp`.
- `m_isVisible` / `m_weatherVisible`: rejected because `Pane+0xb4` is the proven visibility byte and `+0xf6` controls generic OnPaint bypass.
- `m_initialized` / `m_ready`: constructor-end placement alone could suggest readiness, but the only consumer tests the byte specifically around virtual OnPaint dispatch; direct-target paint semantics are stronger.
- `m_skipOnPaint`: behaviorally literal but negatively phrased and tied to one caller implementation; `m_drawOnTarget` better matches the positive class virtual/source concept.
- Manual `this->vftable = ...`, adjusted-vptr stores, or constructor return: compiler ABI, not developer source.
- Initializer-list entries for `m_frameCount` and `m_timerInterval`: these are inherited Weather members and cannot be named in a derived-class initializer list. Body assignments are the valid source form.

## Evidence Standards Used

- Direct binary evidence: exact MCP bytes/disassembly/decompilation, current executable PE section mapping, body SHA256, unique signature, caller/callee/xrefs, vtable dwords, function/type catalog, and field-access pattern searches.
- Cross-function evidence: Pane constructor default, Layer consumer, all three concrete weather constructor writes, Weather timer consumption, Rain paint frame selection, and MapPane construction/allocation/EH context.
- Documentation evidence: current target/class/file/type/vtable/aggregate pages and current generated/manual tracker states.
- Historical evidence: executed reports were used only as leads and provenance; every material target claim was rechecked against current docs or live MCP.
- Negative evidence: no target-end xref, no VA/RVA/raw-offset target pointer, no duplicate body prefix, no explicit target arguments, no target-local EH, no additional `+0xf6` reader, and no Rain-added field.
- Evidence ladder result: direct binary and current cross-document evidence support exact behavior and source routing. Only original lexical spelling remains inferential; project rules require the strongest human name rather than a raw offset label.

## Evidence Checked

- IDA MCP/manual-disassembly/raw-byte checks performed:
  - `initialize`/`tools/list` schema refresh and current `idb_list`/`server_health` health verification;
  - `lookup_funcs`, `analyze_function`, `disasm`, `decompile`, `callees`, `xrefs_to`, `xref_query`, `get_bytes`, `get_int`, `find_bytes`, `insn_query`, `type_query`, and `type_inspect` read-only;
  - target `[0x005c1410,0x005c145a)`, caller `0x0050db50`, base `0x005c12a0`, Pane constructor `0x00544460`, Layer consumer `0x004f15a0`, sibling constructors `0x005c1bd0` and `0x005c2230`, and Rain vtable cells;
  - current target type, exact executable section/raw mapping, executable hash, target body hash, padding hashes, unique signature, and VA/RVA/raw-offset pointer patterns.
- by-* docs, support docs, old reports, generated reports, and trackers checked: all items listed under `Current Target State`, current manual by-memory/by-type coverage rows, generated WeatherLayerPane.cpp, generated memory coverage, and generated research tracker.
- Negative checks performed: no xref to end `0x005c145a`; no embedded target VA `10 14 5c 00`, RVA `10 14 1c 00`, or raw offset `10 08 1c 00`; one body-prefix hit at `0x005c1410`; no signed/unsigned byte loads or alternate byte stores at `+0xf6` beyond the documented access family; no dword field store at `+0xf6`.
- Failed, unavailable, or intentionally skipped checks:
  - MCP broad `insn_query(op_any=246)` returned no useful output, so exact byte-pattern searches plus direct function disassembly were used instead.
  - No validator was run during the initial report-only pass. After Gate 1 acceptance, the implementation callback ran the ten serial scoped validators recorded under `Validator Results`.
  - No IDA mutation tool was invoked because B agents are read-only.
  - No compile/codegen comparison was attempted because the current project header graph is not generated as standalone headers; this remains a bounded final-audit limitation rather than a constructor blocker.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C3PI-01 | 0003PI | Exact function is `[0x005c1410,0x005c145a)`, 74 bytes. | exact | MCP lookup/disasm/bytes | target Status/Evidence | incorporate | implemented and validator-verified; command 17041; destination hash below |
| C3PI-02 | 0003PI | Exact body SHA256 is `B302EDA90BEA72A3FA45D2C16C9C6059B3ECE41F29FAFA5024A85986D56BB29E`. | exact | MCP bytes plus PE readback | target Evidence | incorporate | implemented and validator-verified; command 17041 |
| C3PI-03 | 0003PI | Eight predecessor and six successor bytes are `0xcc`; postpad SHA256 is `33CC4A00A0F04735602819132DA3E3FAC4CDEB8EC7AEE92551DC79BA8488E722`. | exact | MCP bytes/hash | target Boundaries; UID0001NZ | incorporate | implemented and validator-verified; commands 17041/17048 |
| C3PI-04 | 0003PI | Body prefix is unique and no VA/RVA/raw-offset pointer to target exists. | exact negative | MCP find_bytes | target Liveness/Negative Evidence | incorporate | implemented and validator-verified; command 17041 |
| C3PI-05 | 0003PI | Sole target xref is code call `0x0050dc3b` in MapPane weather setup. | exact | xref_query | target Caller Inventory; class/file | incorporate | implemented and validator-verified; commands 17041/17047/17059 |
| C3PI-06 | 0003PI | Caller allocates `0x10c` bytes for weather selector 1 before calling target. | exact | caller disassembly | target ABI/Layout | incorporate | implemented and validator-verified; commands 17041/17059 |
| C3PI-07 | 0003PI | Caller stores the result in MapPane `+0x414` and has allocation cleanup outside the target. | exact | caller disassembly/SEH tails | target Caller/EH | incorporate | implemented and validator-verified; commands 17041/17048/17059 |
| C3PI-08 | 0003PI | Target is no-argument thiscall constructor; EAX `this` return is ABI, not source return. | exact ABI | target disassembly/prototype | target Signature/C++ rationale | incorporate | implemented and validator-verified; command 17041 |
| C3PI-09 | 0003PI | Sole callee is Weather constructor `0x005c12a0`. | exact | callees/disassembly | target Base Construction | incorporate | implemented and validator-verified; commands 17041/17048/17059 |
| C3PI-10 | 0003PI | Target has no local SEH/cleanup/heap/resource calls. | exact negative | complete target disassembly | target EH/Negative Evidence | incorporate | implemented and validator-verified; command 17041 |
| C3PI-11 | 0003PI | Rain primary/adjusted vptr stores are `0x00631220`, `0x00631274`, `0x006312a4`. | exact | disassembly/xrefs | target Vtable; UID0002Z8 | incorporate | implemented and validator-verified; commands 17041/17049 |
| C3PI-12 | 0003PI | Vptr writes are compiler-generated and must not appear in source C++. | very strong | C++ ABI and class hierarchy | target Reconstruction Notes | incorporate | implemented and validator-verified; commands 17041/17047/17049/17059 |
| C3PI-13 | 0003PI | `+0xfa` is inherited signed-short `m_timerInterval`, assigned 120 ms. | exact | target store and UID0003PH consumer | target Fields/C++; layout/class/file | incorporate | implemented and validator-verified; commands 17041/17043/17047/17059 |
| C3PI-14 | 0003PI | `+0xf9` is inherited signed-char `m_frameCount`, assigned 3. | exact | target store, timer and paint consumers | target Fields/C++; layout/class/file | incorporate | implemented and validator-verified; commands 17041/17043/17047/17059 |
| C3PI-15 | 0003PI | Base constructor zeroes dword `+0xf8`, including current frame/count/interval defaults before derived assignments. | exact | base disassembly | target Initialization Order | incorporate | implemented and validator-verified; commands 17041/17043/17048 |
| C3PI-16 | 0003PI | Pane constructor clears word `+0xf5/+0xf6`. | exact | `0x0054454f` disassembly | PaneLayout; target field provenance | incorporate | implemented and validator-verified; commands 17041/17042 |
| C3PI-17 | 0003PI | Rain/Snow/Swallow constructors are the only byte-store matches setting `+0xf6` to 1. | exact bounded search | find_bytes at `0x5c144e/0x5c1c63/0x5c2327` | PaneLayout; weather support docs | incorporate | implemented and validator-verified; commands 17041-17045 |
| C3PI-18 | 0003PI | Layer dirty-region traversal is the only byte-read/compare match and invokes virtual `OnPaint` only when `+0xf6` is zero. | exact bounded search | `0x004f16b2-0x004f16bf`; Rain vtable +0x44 | PaneLayout; target behavior | incorporate | implemented and validator-verified; commands 17041-17045 |
| C3PI-19 | 0003PI | Preferred source name is inherited bool `m_drawOnTarget`; visibility/reserved/readiness aliases are rejected. | strong inference | C3PI-16 through C3PI-18; separate +0xb4 visibility | target C++; Pane/Swallow/Snow support | incorporate | implemented and validator-verified in all ten destinations |
| C3PI-20 | 0003PI | RainingLayerPane adds no storage and remains exactly `0x10c`. | exact | caller allocation, type catalog, class docs | target Layout; class/type | incorporate | implemented and validator-verified; commands 17041/17043/17047/17049/17059 |
| C3PI-21 | 0003PI | Current RainingLayerPane IDA UDT is size 268 with Pane prefix and exact four Weather tail fields. | exact current IDA state | type_query/type_inspect | target IDA Facts | incorporate | Gate 2A and Gate 2B verified exact UDT preservation; WeatherLayerPane opaque declaration preserved without broad type mutation |
| C3PI-22 | 0003PI | Source body is three inherited assignments after implicit base construction. | very strong | instruction/source mapping | target formal C++ | incorporate | implemented and validator-verified; generated once at lines 148-154 |
| C3PI-23 | 0003PI | Canonical source placement is `NexusTK/map/WeatherLayerPane.cpp`. | very strong | current class/file routes and generated output | target Source Placement; UID0000P8 | incorporate | implemented and validator-verified; command 17059/current generated hash below |
| C3PI-24 | 0003PI | Complete class declaration belongs in `WeatherLayerPane.h`; target emits only qualified definition. | very strong | accepted class/layout/header contract | target Source Placement; class/file | incorporate | implemented and validator-verified; commands 17041/17047/17059 |
| C3PI-25 | 0003PI | Direct owner/emitter stays UID0000BJ; UID0001NZ remains non-emitting index. | exact route | current metadata and split rules | target metadata; aggregate | preserve | preserved and validator-verified; commands 17041/17048 |
| C3PI-26 | 0003PI | No range split, merge, new child, or padding ownership change is needed. | exact | bounds/adjacent pages | target Range Analysis | preserve | preserved and validator-verified; commands 17041/17048 |
| C3PI-27 | 0003PI | Raise target `86/88 -> 92/94`; support scores remain unchanged. | strong | resolved blockers and exact body | target metadata; manual target row | incorporate | implemented; target 92/94 and support metadata preserved at their current values |
| C3PI-28 | 0003PI | Generated UID0003PI empty marker should be replaced by one constructor after validation. | exact expected route | historical command `000000017030` generated line 423 checkpoint | generated readback only | Gate 2A verified after command 17074: one constructor, one UID occurrence, zero empty markers; generated SHA D94DF635...A6F81 |
| C3PI-29 | 0003PI | Rename/type/comment target in IDA at Gate 2B; preserve exact boundaries and decorated vtables. | strong | raw pre-state, collision-negative lookup, applied action/readback/save | supervisor Gate 2B handoff | apply-by-supervisor | APPLIED_VERIFIED at 2026-07-24T02:04:56-04:00; exact range/caller/vtable xrefs/UDT preserved |
| C3PI-30 | 0003PI | Add semantic comments for `+0xf6` compare and three weather writes; do not rebuild broad Pane UDT in this target gate. | strong/safe | six-address live comment readback and type-preservation audit | supervisor Gate 2B handoff | apply-by-supervisor | APPLIED_VERIFIED at 2026-07-24T02:04:56-04:00; all six comments readable; no broad Pane/Weather type mutation |
| C3PI-31 | 0003PI | Historical field-name/source-split blank-body blockers are superseded but must be preserved as history. | exact documentation state | current target/support docs | target/support Changes/History | historicalize | implemented and validator-verified across target/support destinations |
| C3PI-32 | 0003PI | Manual by-memory target row and PaneLayout by-type row need exact supervisor-owned replacements. | exact current manual rows | manual coverage readback | manual coverage handoff | supervisor-only | pending supervisor |

## Positive Evidence Summary

- Direct facts supporting the recommendation:
  - one exact modeled 74-byte function and unique body prefix;
  - one direct MapPane call after an exact `0x10c` allocation;
  - one base Weather constructor call;
  - three exact Rain vptr stores;
  - three source-visible scalar assignments and no other target side effects;
  - exact caller cleanup and no target-local cleanup;
  - exact Weather/Rain extent and direct owner route.
- Corroborating documentation/generated evidence:
  - accepted UID0003PJ closes Weather tail types and canonical file/header route;
  - UID0002Z8 closes Rain RTTI/vtable identity and no-added-storage extent;
  - UID0000BJ/UID0000P8 already route exact child definitions into WeatherLayerPane.cpp;
  - historical pre-callback generated output placed an empty UID0003PI marker at that route, proving formal population was the missing step; Gate 2A now verifies one qualified constructor and zero target empty markers.
- Strongest inference chain: Pane clears `+0xf6`; exactly the three concrete weather constructors set it; generic Layer traversal tests it around the virtual OnPaint call; all three concrete weather classes have specialized rendering. `m_drawOnTarget` is therefore a positive human source name for exact observed behavior, not an arbitrary offset alias.

## IDA MCP Facts

- Function/range facts:
  - Recommendation-time `lookup_funcs 0x005c1410 -> sub_5C1410`, size `0x4a`; no function begins at `0x005c145a`; successor `RainingLayerPane__OnPaint` begins at `0x005c1460`. Gate 2B current readback is `RainingLayerPane__RainingLayerPane` at the same exact range.
  - Recommendation-time inferred prototype was `_WORD *__thiscall(_WORD *this)`; complete disassembly is one basic block with no branch, no explicit argument, and `retn`. Gate 2B current prototype is exact returned-this `RainingLayerPane *__thiscall(RainingLayerPane *this)`.
  - Exact target bytes:
    `55 8b ec 51 56 8b f1 89 75 fc e8 81 fe ff ff b8 78 00 00 00 c7 06 20 12 63 00 66 89 86 fa 00 00 00 8b c6 c7 86 a0 00 00 00 74 12 63 00 c7 86 a4 00 00 00 a4 12 63 00 c6 86 f9 00 00 00 03 c6 86 f6 00 00 00 01 5e 8b e5 5d c3`.
  - Target lies in PE `.text`, RVA `0x001c1410`, raw file offset `0x001c0810`; file bytes hash to the same target SHA256.
- Data/table/padding facts:
  - `[0x005c1408,0x005c1410)` is eight `0xcc` bytes, SHA256 `3D2F424783DF5853C8D7121B1371650C04241F318E1B0CD46BEDBC805B9164C3`.
  - `[0x005c145a,0x005c1460)` is six `0xcc` bytes, SHA256 `33CC4A00A0F04735602819132DA3E3FAC4CDEB8EC7AEE92551DC79BA8488E722`.
  - The 20-byte body prefix occurs once, at `0x005c1410`.
- Xref facts:
  - target start has exactly one xref, call `0x0050dc3b` in `sub_50DB50`/MapPane weather setup;
  - target end has zero xrefs;
  - vtable destinations have exactly one constructor-store xref each: `0x005c1424 -> 0x00631220`, `0x005c1433 -> 0x00631274`, `0x005c143d -> 0x006312a4`;
  - target pointer byte searches for VA, RVA, and raw offset returned zero.
- Vtable/global/type facts:
  - primary Rain vtable entry at `0x00631264` is `0x005c1460`, proving primary slot `+0x44` is Rain `OnPaint`;
  - current `RainingLayerPane` UDT exists at size `0x10c` with `Pane` prefix plus `m_currentFrame`, `m_frameCount`, `m_timerInterval`, and `m_weatherBounds`;
  - `WeatherLayerPane` did not exist during B003's evidence pass. By Gate 2B it exists only as an opaque declaration from independently accepted UID0003PH work; the supervisor preserved it and still rejected a target-local speculative broad hierarchy rewrite.
- Negative IDA facts:
  - no alternate caller/callee, no strings, no target global, no local table, no local EH handler, no explicit constructor argument, no duplicate body, and no target data pointer;
  - no modeled `+0xf6` byte loads besides `0x004f16b2`, and no byte writes besides the three concrete weather constructors; Pane's default clear is the one word store at `0x0054454f`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x005c12a0-0x005c13a1` | UID0003PG Weather constructor | Initializes Pane/Weather base, bounds, timer state | true | UID0000G1 | `86/88` | independent active B001 source-quality assignment; support only here |
| `0x005c13b0-0x005c1408` | UID0003PH Weather timer | Advances frame, invalidates/draws, reschedules | true | UID0000G1 | current doc | sibling support |
| `0x005c1408-0x005c1410` | UID0000VN ignored | eight-byte alignment | false | none | `100` | unchanged |
| `0x005c1410-0x005c145a` | UID0003PI target | Rain constructor | true | UID0000BJ | `86/88 -> 92/94` | source-ready recommendation |
| `0x005c145a-0x005c1460` | UID0000VN ignored | six-byte alignment | false | none | `100` | unchanged |
| `0x005c1460-0x005c180c` | UID0003PJ Rain OnPaint | Main-view rain paint | true | UID0000BJ | `92/94` | accepted emitting sibling |
| `0x005c1810-0x005c1bc7` | UID0003PK Rain DrawOnTarget | Supplied-target rain render | true | UID0000BJ | `86/88` | independent sibling; no body duplication |
| `0x0063121c-0x006312ac` | UID0002Z8 Rain vtable data | RTTI/three vtable views | true generated-binary | UID0000BJ | `88/92` | compiler-only formal marker |
| `0x005c12a0-0x005c1bc7` | UID0001NZ aggregate | Weather/Rain address index | false | UID0000P8 | `88/94` | non-emitting, unchanged |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0050dc1e` | `push 0x10c` | exact Rain allocation size |
| `0x0050dc23` | allocator `sub_4F4AA0` | source `new RainingLayerPane` allocation path |
| `0x0050dc3b` | call `0x005c1410` | sole target constructor call |
| `0x00602803` | caller EH cleanup | frees allocated Rain block if construction throws |
| `0x005c141a` | call `0x005c12a0` | implicit Weather base construction |
| `0x005c1424` | data ref `0x00631220` | compiler primary Rain vptr install |
| `0x005c1433` | data ref `0x00631274` | compiler adjusted Rain vptr install |
| `0x005c143d` | data ref `0x006312a4` | compiler adjusted Rain vptr install |
| `0x005c142a` | store word `+0xfa = 120` | inherited timer interval |
| `0x005c1447` | store byte `+0xf9 = 3` | inherited frame count |
| `0x005c144e` | store byte `+0xf6 = 1` | inherited direct-target paint mode |
| `0x004f16b2` | compare byte `Pane+0xf6` | zero invokes primary virtual slot `+0x44` / OnPaint; nonzero bypasses generic paint |
| `0x0054454f` | clear word `Pane+0xf5` | Pane default clears `+0xf5` and `+0xf6` together |
| `0x005c1c63`, `0x005c2327` | sibling stores `+0xf6 = 1` | Snow and Swallow share the concrete-weather mode |

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion:
  - UID0000BJ and UID0001WJ prove storage-free Rain inheritance and exact Weather tail types.
  - UID0003PH proves timer/count consumption.
  - UID0003PJ proves three-frame Rain use and current canonical source/header route.
  - UID0003PK and Rain vtable data prove the direct-target virtual contract.
  - UID0001NZ proves exact child boundaries and non-emitting aggregate policy.
- Existing docs that are stale, incomplete, or contradicted:
  - UID0003PI blank formal and old blanket blocker text;
  - PaneLayout claim that `+0xf6` has no consumer;
  - Swallow core visibility-state wording and Snow constructor generic enabled wording;
  - aggregate/vtable/target phrases that say merely enabled state without the now-proved OnPaint-bypass/direct-target behavior.
- Generated/coverage report state:
  - current validator-owned generated output routes UID0003PI through UID0000BJ into WeatherLayerPane.cpp and contains its exact constructor once at lines 148-154;
  - current generated source has zero UID0003PI empty markers;
  - current research tracker shows target `92/94`, average `93.0`, reconstructable true, and report coverage `0/0/0` before supervisor execution;
  - supervisor-owned manual by-memory row remains `86% : strong` and says enabled state;
  - supervisor-owned PaneLayout manual row remains `85% : very-strong` but omits the now-proved `+0xf6` role.

## Ranked Ownership Analysis

### 1. RainingLayerPane via WeatherLayerPane.cpp

- Evidence for: exact Rain vptr stores, Rain RTTI/vtable, sole Rain allocation/call branch, target-specific constants, existing UID0000BJ owner, accepted contiguous source family, class child route, generated destination, and storage-free inheritance.
- Evidence against: no surviving source-path string or original constructor symbol. This affects lexical proof, not semantic ownership.
- Decision: retain UID0000BJ as direct owner/emitter and UID0000P8 as canonical file route.

### 2. Historical dedicated RainingLayerPane.cpp

- Evidence for: dedicated by-file hypothesis UID0000MY and a coherent possible original per-layer organization.
- Evidence against: current accepted project route, contiguous Weather/Rain code/data/RTTI family, existing emitted siblings, and generated source all select WeatherLayerPane.cpp; no source-path evidence overrides that route.
- Decision: preserve as historical alternative only; do not move target.

### 3. Weather aggregate, Pane, MapPane, or compiler owner

- Evidence for: Weather supplies inherited fields, Pane supplies `+0xf6`, MapPane constructs the object, and compiler emits vptr stores.
- Evidence against: those are base/dependency/caller/ABI roles. The exact function constructs the Rain dynamic type and is already owned by the Rain class child.
- Decision: reject direct ownership by UID0001NZ, UID0000G1, Pane, MapPane, vtable data, or compiler-support pages.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: not applicable; use existing UID0000BJ -> UID0000P8 route.
- Likely full contents: existing `WeatherLayerPane.cpp` source family already carries Weather/Rain/Snow/Swallow definitions and weather-private data.
- Candidate related items that belong: UID0003PI remains between UID0003PH and UID0003PJ in current source/memory order.
- Candidate related items rejected: no new Rain-only file, no constructor aggregate, no synthetic Pane helper, no hand-authored vtable data.
- Standalone, narrow, or broad source-file inference: narrow exact method child emitted within established broad weather source file.

## Source Placement

- Recommended source file/class/global/module placement: `NexusTK/map/WeatherLayerPane.cpp`, qualified definition `RainingLayerPane::RainingLayerPane()`, emitted through UID0000BJ into UID0000P8.
- Header contract: canonical `WeatherLayerPane.h` declares `WeatherLayerPane : public Pane` with four tail fields and `RainingLayerPane : public WeatherLayerPane` with no new storage.
- Why this placement fits: current class/file ownership, contiguous binary neighborhood, RTTI/vtables, static rain arrays, sibling render methods, and generated destination agree.
- Rejected placements: dedicated Rain file as current route, MapPane.cpp caller ownership, Pane.cpp inherited-field ownership, aggregate emission, and vtable-data emission.
- Remaining placement uncertainty: exact historical physical file cannot be proven from the binary, but the project has already selected the canonical route. That historical uncertainty does not block target source or score.

## Range / Split / Padding / Reclassification Analysis

- Exact range/boundary facts: target begins after eight `0xcc` bytes, occupies exactly 74 bytes, ends before six `0xcc` bytes, and next function begins at `0x005c1460`.
- Children/subranges: none. All 74 bytes belong to one function; all surrounding alignment already belongs to ignored coverage.
- Padding/table/data/code distinctions: three vtable destination addresses are referenced data outside the function; no vtable bytes are inside this code child. Pre/post `0xcc` spans are compiler alignment, not source statements.
- Parent/container impact: UID0001NZ remains a non-emitting index. No parent score or reconstructable state needs change.
- Reclassification: promote only source readiness and score within existing reconstructable constructor classification; do not reclassify the target as raw, compiler-generated, covered-by, or non-emitting.

## Negative Evidence Summary

- No second code/data xref, target pointer, duplicate body, interior entry, end xref, jump table, exported symbol, string, global declaration, or alternate class vptr exists.
- No target-local allocation, timer call, cleanup, EH frame, condition, loop, error branch, null guard, bounds check, or resource operation exists.
- The target does not initialize `m_currentFrame` or `m_weatherBounds`; the base constructor does.
- Rain does not add storage; `0x10c` is both allocated and typed extent.
- The direct MapPane caller proves use but not ownership; Weather construction proves inheritance but not direct ownership; vtable stores prove dynamic class but remain compiler output.
- `+0xf6` is not generic visibility because separate `+0xb4` handles Show/Hide. It is not padding because live code reads and writes it. It is not merely initialized/ready because its only consumer specifically gates virtual OnPaint.
- No current evidence justifies inventing a setter method; the binary performs a direct protected/base-field store.

## IDA Rename / Type / Comment Recommendations

The table below preserves the exact recommendation-time pre-state and supervisor handoff. Agent-B003 did not mutate IDA. Supervisor Gate 2B subsequently applied and verified the accepted actions; the authoritative applied checkpoint follows the original table and constraints.

| Address/entity | Recommendation-time readback | Proposed supervisor action | Evidence/confidence | Expected readback |
| --- | --- | --- | --- | --- |
| function `0x005c1410-0x005c145a` | `sub_5C1410`, `_WORD *__thiscall(_WORD *this)`, size `0x4a`; live `lookup_funcs` finds no existing `RainingLayerPane__RainingLayerPane` collision | Rename to `RainingLayerPane__RainingLayerPane`; apply `RainingLayerPane *__thiscall RainingLayerPane__RainingLayerPane(RainingLayerPane *this)` | exact class identity/ABI and collision-negative lookup; very strong | named typed function at same exact range, source decompile with typed receiver, and no second function carrying the proposed name |
| function comment `0x005c1410` | no target semantic function comment returned | Set exact repeatable comment: `RainingLayerPane constructor: calls WeatherLayerPane base construction, installs compiler Rain vptr views, sets inherited m_timerInterval=120 ms, m_frameCount=3, and Pane direct-target paint mode (Pane+0xf6)=true; source adds no Rain fields.` | exact except lexical field spelling; very strong | comment visible on function start |
| instruction `0x005c142a` | raw `+0xfa` word store | Comment: `inherited WeatherLayerPane::m_timerInterval = 120 ms` | exact | semantic operand comment |
| instruction `0x005c1447` | raw `+0xf9` byte store | Comment: `inherited WeatherLayerPane::m_frameCount = 3` | exact | semantic operand comment |
| instruction `0x005c144e` | raw `+0xf6` byte store | Comment: `inherited Pane direct-target paint mode (preferred source name m_drawOnTarget) = true` | behavior exact, spelling inferred | semantic operand comment |
| instruction `0x004f16b2` | `cmp byte ptr [esi+0F6h],0` | Comment: `Pane+0xf6: zero dispatches virtual OnPaint here; concrete weather panes set it to bypass generic paint and use direct-target rendering` | exact control flow and weather write family | shared consumer documents role |
| instruction `0x005c1c63` | Snow sibling raw `+0xf6` store | Set exact comment: `inherited Pane direct-target paint mode (preferred source name m_drawOnTarget) = true; SnowingLayerPane uses direct-target rendering` | exact write family | exact comment readable at `0x005c1c63` |
| instruction `0x005c2327` | Swallow sibling raw `+0xf6` store | Set exact comment: `inherited Pane direct-target paint mode (preferred source name m_drawOnTarget) = true; SwallowLayerPane uses direct-target rendering` | exact write family | exact comment readable at `0x005c2327` |
| type `RainingLayerPane` | exists, size 268, `Pane _base` plus exact four Weather tail fields | Already present for this target; no destructive replacement in this gate | exact size/offsets; active UID0003PG may separately improve hierarchy | size and members unchanged |
| type `WeatherLayerPane` | absent during the original B003 evidence pass | No target-local creation in this gate; independent weather-family work owns hierarchy-wide IDA decisions | avoids conflicting broad type mutation while target type is sufficient | preserve whatever independently accepted state exists at Gate 2B without broad replacement |
| decorated Rain RTTI/vtables `0x00631220`, `0x00631274`, `0x006312a4` | correct decorated names | `NO_CHANGE_VERIFIED` | compiler names and xrefs exact | names/data preserved |

Required type/size invariants:

- `sizeof(RainingLayerPane) == 0x10c` / 268.
- inherited Weather tail remains `m_currentFrame +0xf8` signed byte, `m_frameCount +0xf9` signed byte, `m_timerInterval +0xfa` signed short, `m_weatherBounds +0xfc` 16-byte `RectBounds`.
- `Pane+0xf6` remains inside the 248-byte Pane prefix; do not create an overlapping Rain field.

Negative constraints:

- Do not create a second function, absorb padding, change target end, add explicit arguments, type source constructor as `void` in IDA's ABI model if that loses the useful returned-this decompile, or create a Rain-added field.
- Do not rename decorated RTTI/vtables, rewrite `sub_5C12A0` under this target's Gate 2B, or mutate the broad Pane UDT solely to expose one field.
- Do not use raw `sub_5C1410`, `_WORD`, `field_F6`, `unk_F6`, `enabled`, or visibility wording as final source identity.
- Do not apply any IDA action before the B003 ordinary-document callback and supervisor Gate 2A verification; supervisor owns Gate 2B. This ordering constraint was satisfied.

**Supervisor Gate 2B applied and verified checkpoint**

- Gate entry: `2026-07-24T02:04:56-04:00`, MCP session `1a506870-31a1-4191-836d-54ef871b2064`, database `supervisor_gate2b_0002OT_20260723`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, based on exact report SHA256 `8294F430EADFBBEE4BC873B25C9C8C06BBE5B4E9F3C45C7E28E143492EDB9B76`.
- Pre-mutation backup: `E:\NTK\Resources\NexusTK\NexusTK.pre-gate2b-0003PI-20260724-0204.i64`, 143,184,868 bytes, SHA256 `C4250949C7705E08A6753673C2B1AF1BA285BAE6BF8AEE27DAAC78BD884EB76E`.
- Raw target pre-state: `0x005c1410` was `sub_5C1410`, `_WORD *__thiscall(_WORD *this)`, size `0x4a`, with no semantic target comment and sole call xref `0x0050dc3b`. `RainingLayerPane__RainingLayerPane` had no collision. All six recommended instruction addresses had their expected raw store/compare operations and none had the proposed semantic comment.
- Applied identity: `0x005c1410` was renamed to `RainingLayerPane__RainingLayerPane` and assigned exact returned-this prototype `RainingLayerPane *__thiscall RainingLayerPane__RainingLayerPane(RainingLayerPane *this);` without changing the exact 74-byte range.
- Applied exact function comment: `RainingLayerPane constructor: calls WeatherLayerPane base construction, installs compiler Rain vptr views, sets inherited m_timerInterval=120 ms, m_frameCount=3, and Pane direct-target paint mode (Pane+0xf6)=true; source adds no Rain fields.`

| Address | Exact applied instruction comment |
| --- | --- |
| `0x005c142a` | `inherited WeatherLayerPane::m_timerInterval = 120 ms` |
| `0x005c1447` | `inherited WeatherLayerPane::m_frameCount = 3` |
| `0x005c144e` | `inherited Pane direct-target paint mode (preferred source name m_drawOnTarget) = true` |
| `0x004f16b2` | `Pane+0xf6: zero dispatches virtual OnPaint here; concrete weather panes set it to bypass generic paint and use direct-target rendering` |
| `0x005c1c63` | `inherited Pane direct-target paint mode (preferred source name m_drawOnTarget) = true; SnowingLayerPane uses direct-target rendering` |
| `0x005c2327` | `inherited Pane direct-target paint mode (preferred source name m_drawOnTarget) = true; SwallowLayerPane uses direct-target rendering` |

- Live target readback: `analyze_function(0x005c1410)` returns name `RainingLayerPane__RainingLayerPane`, prototype `RainingLayerPane *__thiscall(RainingLayerPane *this)`, size 74, the exact function comment, the exact three target-local instruction comments, and unchanged sole caller xref `0x0050dc3b`. One-instruction readback at all six addresses displays each exact applied comment; no requested address was interior or non-head.
- Vtable preservation readback: `0x00631220`, `0x00631274`, and `0x006312a4` retain exactly one constructor-store xref at `0x005c1424`, `0x005c1433`, and `0x005c143d`; decorated names and table data remain unchanged.
- Type preservation readback: exact `RainingLayerPane` remains size 268 with Pane prefix plus signed-byte `m_currentFrame +0xf8`, signed-byte `m_frameCount +0xf9`, signed-short `m_timerInterval +0xfa`, and `RectBounds m_weatherBounds +0xfc`. `WeatherLayerPane` is now only an opaque declaration from independently accepted UID0003PH work; Gate 2B preserved it and performed no broad Pane/Weather hierarchy or layout mutation.
- Negative preservation readback: no bytes, padding, target end, caller, explicit arguments, Rain-added field, UDT layout, decorated vtable identity, broad Pane/Weather layout, or unrelated identity changed.
- Save evidence: `idb_save` returned `ok:true`. The exact UID0003PI Gate 2B saved-IDB checkpoint is 143,184,868 bytes, last write `2026-07-24T02:04:56.9435186-04:00`, SHA256 `4F1F76E332E002C8D0CE48742CF3782EBC52E7D40F60FE3081DA203069ABB025`. Later unrelated supervisor saves may advance the shared current IDB while preserving these `APPLIED_VERIFIED` items.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. Exact behavior, ownership, fields, constants, and source route are sufficient.
- Exact proposed managed target metadata/header replacement block:

```text
*** UID:0003PI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000BJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000BJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
RainingLayerPane::RainingLayerPane()
{
    m_timerInterval = 120;
    m_frameCount = 3;
    m_drawOnTarget = true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Exact source-ready no-argument Rain constructor with unique 74-byte body/hash, sole MapPane allocation/call route, implicit WeatherLayerPane base construction, compiler-only primary/adjusted Rain vptr installation, inherited 120 ms timer interval, three-frame count, inherited direct-target paint mode, exact no-added-storage 0x10c extent, caller-owned unwind cleanup, canonical WeatherLayerPane.cpp/.h route, and bounded alignment. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

- Reason it preserves exact original behavior:
  - C++ automatically invokes the default Weather base constructor before the body;
  - MSVC emits the dynamic-type vptr stores;
  - body assignments preserve the exact values, widths, and positive direct-target mode;
  - no extra branch, guard, call, resource, cleanup, timer scheduling, or added field is introduced.
- Reason it matches plausible original mid-2000s developer source:
  - a short out-of-line constructor assigns inherited configuration members directly;
  - it avoids decompiler casts, raw offsets, manual vtables, artificial wrappers, and unnecessary comments;
  - it follows the accepted project `m_` lower-camel member style and bool literal style.
- Inferred source-facing names/types/fields: `RainingLayerPane`, `m_timerInterval`, `m_frameCount`, and `m_drawOnTarget`. The first three are established by current docs/type evidence; `m_drawOnTarget` is the best high-probability lexical inference from the exact access family.
- Naming/coding style convention: class-qualified PascalCase constructor, `m_` lower-camel members, braces on following lines, four-space indentation, no redundant `this->`, and no modern-only syntax beyond `true`, all compatible with C++03-era game source.
- Third-party import directive: not applicable; this is NexusTK project code.
- Reason code should remain blank: not applicable. The old blank-body rationale is superseded and should be historicalized.

## Final Recommendation

- C3PI-01 through C3PI-31 are implemented and independently verified; no declared additional UID exists. C3PI-29/C3PI-30 are supervisor `APPLIED_VERIFIED`, while C3PI-32 remains the supervisor post-execution manual coverage handoff.
- UID0003PI target now records `86/88 -> 92/94`, preserves owner/emitter/reconstructable/position, contains the exact managed constructor, and preserves prior assumptions as explained history rather than current blockers.
- Rain class/file/source-family, aggregate/vtable/layout, Pane `+0xf6`, and Snow/Swallow field-role support are synchronized at report-level detail without changing unrelated metadata or bodies.
- Parent assignments: unchanged. UID0000BJ remains direct method owner; UID0000P8 remains canonical source file; UID0001NZ remains non-emitting index.
- Items left no-owner/non-emitting: only existing compiler alignment and aggregate/vtable compiler-output policies; no new no-owner item is created.
- Independent UID0003PG/UID0003PH/UID0003PJ/UID0003PK work was preserved from current destination reads. It does not block UID0003PI and was not overwritten from the older report snapshot.

## Recommended Target Doc Changes

- Target path: `by-memory/0x005c1410-0x005c145a.RainingLayerPaneConstructor.md`.
- Exact report facts to incorporate:
  - exact bytes/body SHA/PE raw mapping and padding hashes;
  - no-argument thiscall constructor ABI and returned-this compiler artifact;
  - exact sole caller/allocation/store/EH context;
  - base construction and no target-local cleanup;
  - vptr stores as compiler output;
  - exact three assignments and field provenance;
  - complete `+0xf6` writer/reader semantics and rejected visibility/reserved/readiness aliases;
  - unique/no-pointer/no-end-xref negatives;
  - canonical source/header placement and no split/no-added-storage proof.
- Metadata/score/owner/emitter/reconstructable/C++ result: the exact managed block above is installed; only target score, formal, summary, and evidence/history prose changed, while owner/emitter/reconstructable/position remain unchanged.
- Historical/stale assumptions to preserve: old split uncertainty, 120-frame/max-frame/frame-step interpretations, old generic enabled/visibility/reserved terminology, and previous blank formal must remain explicitly marked historical/superseded with reasons.

## Recommended Support Doc Changes

| Support path | Exact facts to incorporate | Metadata/link/score impact |
| --- | --- | --- |
| `by-class/RainingLayerPane.md` | Constructor is now source-ready; three inherited assignments; no added storage; direct-target paint mode semantics; UID0003PI actual child formal route. | Preserved current `91/93`, owner/emitter UID0000P8. |
| `by-file/WeatherLayerPane.md` | Exact UID0003PI constructor source state, one-body/zero-empty-marker expectation, one-file route, and header obligation are recorded. | Preserved current `92/93`. |
| `by-file/RainingLayerPane.md` | Preserve as historical file candidate while recording the accepted constructor source body through WeatherLayerPane.cpp. | Keep current metadata. |
| `by-memory/0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes.md` | UID0003PI child row now records source-ready direct-target mode and populated exact-child C++; aggregate remains marker-only. | Preserved current `89/92`, non-reconstructable/non-emitting. |
| `by-memory/0x0063121c-0x006312ac.RainingLayerPaneVtableData.md` | Record typed constructor identity, exact body SHA, populated child C++, and compiler-vptr/source separation. | Keep current vtable metadata/formal policy. |
| `by-type/by-struct/WeatherLayerDataLayouts.md` | Add inherited Pane direct-target paint-mode relationship beside exact Weather tail; do not place `+0xf6` in Rain-added storage. | Keep `91/93`. |
| `by-type/by-struct/PaneLayout.md` | Replace no-consumer/reserved wording for `+0xf6` with exact default/write/read behavior and preferred `m_drawOnTarget` direction; preserve `+0xb4` visibility. | Keep `85/88`; no broad formal C++ change. |
| `by-memory/0x005c1bd0-0x005c1c7e.SnowingLayerPaneConstructor.md` | Replace generic enables-the-pane phrase with shared inherited direct-target paint-mode assignment; no Snow source-body decision. | Keep current metadata. |
| `by-memory/0x005c2230-0x005c299f.SwallowLayerPaneCore.md` | Replace `+0xf6` visibility-state wording with direct-target paint-mode semantics and link the unique consumer evidence. | Keep current metadata and unrelated raw-helper caveats. |

No support C++ block is proposed. UID0003PI alone owns this constructor body.

## Score And Metadata Recommendation

- Historical pre-callback score/metadata: `86/88`, owner/emitter UID0000BJ, reconstructable true, blank position, blank C++.
- Current implemented score/metadata: `92/94`, owner/emitter UID0000BJ unchanged, reconstructable true unchanged, blank position unchanged, exact constructor formal populated.
- Reason not lower: range, bytes, hash, caller, allocation, ABI, base call, vptrs, all source-visible assignments, field types, constants, no-added-storage layout, cleanup boundary, source/header placement, direct owner/emitter, and human source body are resolved.
- Reason not higher: original private lexical spelling for `m_drawOnTarget` and exact historical physical file are not symbol-proven; no full project header materialization or compiler codegen-match test is claimed. These are confidence caps, not implementation blockers.
- Score-improvement attempt:
  - field-name blocker: traced all `+0xf6` defaults/writes/read and chose `m_drawOnTarget` with rejected alternatives;
  - source-split blocker: rechecked current canonical class/file/generated route and retained dedicated file only as history;
  - C++ blocker: mapped every instruction to implicit base/vptr ABI or one of three source assignments;
  - caller/reachability blocker: proved sole call, allocation size, storage, and EH cleanup;
  - type/layout blocker: verified current UDT size/tail and no Rain-added fields;
  - range blocker: verified exact bytes, unique prefix, pointer negatives, and alignment.
- Implemented metadata fields: `COMPLETION`, `CONFIDENCE`, formal C++, and Item Summary. Preserved metadata fields: UID, owner, reconstructable, emitter, optional position, Nested.

## Open Questions With Attempted Resolution

- Original spelling of `Pane+0xf6`:
  - evidence checked: Pane constructor default, all byte-store patterns, all common signed/unsigned byte-load/compare patterns, unique Layer consumer, Rain vtable slot, separate Pane visibility byte, sibling weather classes, and current docs/history;
  - resolution: use `bool m_drawOnTarget` as the highest-probability human name; record `m_usesDirectTargetDrawing` only as a descriptive alias. No actionable naming question remains for first-draft source.
- Exact original `.cpp` split:
  - evidence checked: class/file routes, contiguous binary code/RTTI/data, current generated destination, historical by-file hypotheses, and old source-path searches;
  - resolution: canonical project reconstruction uses `WeatherLayerPane.cpp`; historical per-layer placement remains provenance only and does not block target.
- Constructor source order:
  - evidence checked: exact scalar store order and C++ inheritance rules;
  - resolution: body assignments follow observed scalar order `m_timerInterval`, `m_frameCount`, `m_drawOnTarget`; base construction/vptr stores remain implicit.
- IDA hierarchy type:
  - evidence checked: exact `RainingLayerPane` UDT, recommendation-time absence of `WeatherLayerPane`, and Gate 2B current opaque `WeatherLayerPane` declaration created by independently accepted UID0003PH work;
  - resolution: the exact-size Rain type safely carries the target prototype. Gate 2B preserved both the exact Rain layout and the current opaque Weather declaration without a broad Weather/Pane type rewrite.
- Questions remaining unresolved: none that block target metadata, ownership, source placement, managed C++, support synchronization, or completed Gate 2B target actions. Irrecoverable original lexical/file-history uncertainty is explicitly bounded in score rationale.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Current post-callback manual coverage checkpoints were read without editing: `by-memory/-coverage-report.md` SHA256 `FC99E0E28BD5A8EB148BCB25D2E205184B84EBCD28DAE36B381E38B10277A6A1`, 2,011,910 bytes, 4,591 lines, UID0003PI at line 3940; and `by-type/-coverage-report.md` SHA256 `822CAA013F10C34623D24803EB88D04FF87DEEE3D8B8FBC9C8ADA9A546AF6CB2`, 5,204 bytes, 34 lines, UID0001VH at line 20. Both rows still require the exact replacements below after supervisor execution.

- File/placement: `by-memory/-coverage-report.md`, replace the existing UID0003PI row at the same indentation under UID0001NZ with exactly:

```text
        - [UID:0003PI][0x005c1410-0x005c145a.RainingLayerPaneConstructor](by-memory/0x005c1410-0x005c145a.RainingLayerPaneConstructor.md) 0x005c1410-0x005c145a | constructor | RainingLayerPaneConstructor : reconstructable : 92% : very-strong : Exact source-ready no-argument Rain constructor with unique 74-byte body/hash, sole MapPane 0x10c allocation/call route, implicit WeatherLayerPane base construction, compiler-only primary/adjusted Rain vptr installation, inherited 120 ms timer interval, three-frame count, inherited m_drawOnTarget direct-target paint mode, no added storage or target-local cleanup, exact alignment/pointer negatives, and canonical WeatherLayerPane.cpp/.h placement.
```

- File/placement: `by-type/-coverage-report.md`, replace the existing UID0001VH PaneLayout row with exactly:

```text
- [UID:0001VH][PaneLayout](by-type/by-struct/PaneLayout.md) : reconstructable : 85% : very-strong : Pane/GrafPort inherited layout through the +0xf8 derived boundary; +0x44 is GrafPort m_visibleBounds, +0xac/+0xb0 are Point m_origin.y/m_origin.x, +0xb4 remains the Show/Hide visibility byte, and +0xf6 is the inherited m_drawOnTarget direct-target paint mode cleared by Pane, set by Rain/Snow/Swallow constructors, and tested to bypass generic virtual OnPaint during Layer dirty-region traversal; all handler/layer/region/motion/deletion evidence remains intact.
```

- Inspected support rows that remain valid without replacement: UID0001NZ aggregate, UID0002Z8 vtable child, UID0000BJ class, UID0000P8 file, and UID0001WJ layout. Their scores and broad descriptions remain truthful after this target body is added.
- Reason B agent must not apply these directly: all `-coverage-report.md` files are supervisor-owned collision points. Generated trackers are validator-owned and must not be edited manually.

## Follow-Up Actions

- Supervisor actions:
  - run a fresh final exact-artifact Gate 1/Gate 2 continuity audit over this report-only reconciliation;
  - execute/archive only through the supervisor validator lifecycle command;
  - after execution, apply and validate the two exact manual coverage row replacements.
- A-agent actions: none.
- B003 future research actions: none. The accepted callback, immediate short leases, serial scoped validators, generated readback, and same-report reconciliation are complete.

## Confidence

- Recommendation confidence: very strong.
- Score confidence: very strong for `92/94` under current source-quality scoring precedent.
- Remaining uncertainty: only original lexical spelling and historical physical file. The report selects human source directions and does not carry raw IDA names into C++.
- Runtime fidelity: exact. The formal introduces no behavior absent from the binary and omits only compiler-generated ABI operations.
- Human-source fidelity: high probability and consistent with accepted mid-2000s C++ project style.

## Validator Results

All commands ran serially from `source-3/project-documentation` as `python .\tools\validator.py --mode file --file <relative-by-star-path> --apply --queue-timeout 240`. Every command exited `0` with `ok: 1`:

| Command | Timestamp | Destination | Result |
| --- | --- | --- | --- |
| `000000017041` | `2026-07-24T01:27:51-04:00` | `by-memory/0x005c1410-0x005c145a.RainingLayerPaneConstructor.md` | target registered at `92/94`; generated refresh deferred |
| `000000017042` | `2026-07-24T01:28:37-04:00` | `by-type/by-struct/PaneLayout.md` | `ok: 1`; generated refresh deferred |
| `000000017043` | `2026-07-24T01:29:13-04:00` | `by-type/by-struct/WeatherLayerDataLayouts.md` | `ok: 1`; generated refresh deferred |
| `000000017044` | `2026-07-24T01:29:44-04:00` | `by-memory/0x005c1bd0-0x005c1c7e.SnowingLayerPaneConstructor.md` | `ok: 1`; generated refresh deferred |
| `000000017045` | `2026-07-24T01:30:18-04:00` | `by-memory/0x005c2230-0x005c299f.SwallowLayerPaneCore.md` | `ok: 1`; nine pre-existing `missing_ref_uid 0003YQ` diagnostics retained |
| `000000017046` | `2026-07-24T01:30:52-04:00` | `by-file/RainingLayerPane.md` | `ok: 1`; generated refresh deferred |
| `000000017047` | `2026-07-24T01:31:29-04:00` | `by-class/RainingLayerPane.md` | `ok: 1`; generated refresh deferred |
| `000000017048` | `2026-07-24T01:33:18-04:00` | `by-memory/0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes.md` | `ok: 1`; existing marker on non-reconstructable aggregate reported as `emitter_inactive_has_data` |
| `000000017049` | `2026-07-24T01:33:56-04:00` | `by-memory/0x0063121c-0x006312ac.RainingLayerPaneVtableData.md` | `ok: 1`; generated refresh deferred |
| `000000017059` | `2026-07-24T01:35:14-04:00` | `by-file/WeatherLayerPane.md` | `ok: 1`; six pre-existing `missing_ref_uid 0003YQ` diagnostics retained |

- Command-17059 generated checkpoint: `WeatherLayerPane.cpp` SHA256 `48F38B2A848F2B2C874231114569E28B7B562C9D33E7DA782F9C6419CEBD7009`, 17,829 bytes, 433 lines; UID0003PI appears once at lines 148-154 and has no empty marker.
- Command-17059 tracker checkpoint: SHA256 `45654E18615CA8176704E9E0B7870F8F47369B048B0CA822703D746F4C1E1366`, 1,640,946 bytes, 6,520 lines; UID0003PI line 3356 is `92/94`, average `93.0`, reconstructable true, and `0/0/0` report coverage before execution.
- No callback validator failed. The UID0003YQ reference-index diagnostics and UID0001NZ marker-policy diagnostic pre-existed this callback and do not contradict UID0003PI implementation.
- Supervisor Gate 2A independently reran the exact ten destination validators. Commands `000000017065` through `000000017074` each exited `0` with `ok:1`:

| Supervisor command | Timestamp | Independently validated destination | Gate 2A result |
| --- | --- | --- | --- |
| `000000017065` | `2026-07-24T02:01:10-04:00` | `by-memory/0x005c1410-0x005c145a.RainingLayerPaneConstructor.md` | `ok:1`; C3PI target range/metadata/formal verified |
| `000000017066` | `2026-07-24T02:01:12-04:00` | `by-class/RainingLayerPane.md` | `ok:1`; class route and no-added-storage state verified |
| `000000017067` | `2026-07-24T02:01:13-04:00` | `by-file/WeatherLayerPane.md` | `ok:1`; canonical source-family route verified |
| `000000017068` | `2026-07-24T02:01:24-04:00` | `by-file/RainingLayerPane.md` | `ok:1`; historical dedicated-file state verified |
| `000000017069` | `2026-07-24T02:01:32-04:00` | `by-memory/0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes.md` | `ok:1`; intentional inactive-emitter marker diagnostic does not contradict C3PI |
| `000000017070` | `2026-07-24T02:01:40-04:00` | `by-memory/0x0063121c-0x006312ac.RainingLayerPaneVtableData.md` | `ok:1`; exact vptr/compiler-source separation verified |
| `000000017071` | `2026-07-24T02:01:42-04:00` | `by-type/by-struct/WeatherLayerDataLayouts.md` | `ok:1`; exact inherited tail/no-Rain-storage layout verified |
| `000000017072` | `2026-07-24T02:01:51-04:00` | `by-type/by-struct/PaneLayout.md` | `ok:1`; direct-target field/default/writer/reader semantics verified |
| `000000017073` | `2026-07-24T02:02:02-04:00` | `by-memory/0x005c1bd0-0x005c1c7e.SnowingLayerPaneConstructor.md` | `ok:1`; Snow direct-target support verified |
| `000000017074` | `2026-07-24T02:02:13-04:00` | `by-memory/0x005c2230-0x005c299f.SwallowLayerPaneCore.md` | `ok:1`; existing UID0003YQ diagnostics do not contradict C3PI |

- Gate 2A current-destination hashes are the exact full SHA256 values recorded under `Changed Files`: target `38D83C10...7708`, Raining class `652DEF1C...32CB`, Weather file `EA4D0C2D...2F247`, historical Rain file `9B7C42F6...5AF`, aggregate `318A4B03...F2E`, Rain vtable `EBB73F32...3F3B`, Weather layouts `BEE4EC9C...2802`, Pane layout `4A4D0E3F...B96B`, Snow support `DF04F216...8DFB`, and Swallow support `38E547DC...9351`.
- Gate 2A generated readback after command `000000017074`: `auto-generated/NexusTK/map/WeatherLayerPane.cpp` SHA256 `D94DF635BCC6BE71ECB24C5235B5AB4F187CA785F50ED975485290F58B2A6F81`, 17,829 bytes; UID0003PI count one, qualified constructor count one, target empty-marker count zero. The research tracker remains at line 3356 with `92/94`, average `93.0`, reconstructable true, and `0/0/0` report coverage before execution.
- Lifecycle commands: none run, probed, dry-run, or invoked by B003.

## Changed Files

- `by-memory/0x005c1410-0x005c145a.RainingLayerPaneConstructor.md`: SHA256 `38D83C1072B965403FE70AEB9D36D8C91FB74B33ABC96FB92271D0D2A1C57708`, 11,792 bytes, 99 lines.
- `by-class/RainingLayerPane.md`: SHA256 `652DEF1C07BF44415CF97D69F48CFFA572E58B18F102D327946D63842FE532CB`, 20,177 bytes, 144 lines.
- `by-file/WeatherLayerPane.md`: SHA256 `EA4D0C2D3B3809F53DF9F2332DAA3C7EC5162D9F62D5C691724C5DBCCB52F247`, 51,209 bytes, 297 lines.
- `by-file/RainingLayerPane.md`: SHA256 `9B7C42F675A87C9F1ECDE58323624451A2FFD593300AABEB03FD5732AE6775AF`, 20,329 bytes, 138 lines.
- `by-memory/0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes.md`: SHA256 `318A4B03A8DBB57ED990C5E4583341004C6E6CDB0814DE956B45E8545D202F2E`, 26,260 bytes, 178 lines.
- `by-memory/0x0063121c-0x006312ac.RainingLayerPaneVtableData.md`: SHA256 `EBB73F32CA8A64B5817D5099009AD1782800B43C86269A31888EC16176383F3B`, 26,694 bytes, 202 lines.
- `by-type/by-struct/WeatherLayerDataLayouts.md`: SHA256 `BEE4EC9CA873844647AA6EFAE03C7A3F0B7FC4443FD32E85A86EFB698C2F2802`, 28,133 bytes, 194 lines.
- `by-type/by-struct/PaneLayout.md`: SHA256 `4A4D0E3F7C9A965A0A4306AAB911EC35EB75FD84E2236DFE1FF88EDDA6B96B0B`, 20,397 bytes, 127 lines.
- `by-memory/0x005c1bd0-0x005c1c7e.SnowingLayerPaneConstructor.md`: SHA256 `DF04F2162491D943EA1A157B0E316710905403B50CDA1B5457461038508C8DFB`, 5,212 bytes, 59 lines.
- `by-memory/0x005c2230-0x005c299f.SwallowLayerPaneCore.md`: SHA256 `38E547DC0E8D551A3FF4CE9BA17276D168355F5BD13C45775E297E74513C9351`, 20,101 bytes, 126 lines.
- This same report was modified in place; its final exact identity is returned to the supervisor after the final audit.
- This final reconciliation changes only this report. It records supervisor audit/IDA evidence without modifying any ordinary destination, coverage/tracker/generated file, IDA database, audit, goal/notes, or validator/lifecycle state.
- Created/renamed ordinary files: none. Every ordinary-file lease was acquired only for immediate edit/validation and released immediately afterward.
- Report execution: not run. Agent-B003 did not invoke any `execute_report`, registry lifecycle, archive, or manual report move command.
- Coverage/generated direct edits: none. Generated changes came only from validators; manual coverage remains supervisor-owned.
- B003 IDA mutation: none. Supervisor Gate 2B independently applied and verified C3PI-29/C3PI-30 at `2026-07-24T02:04:56-04:00`; the exact checkpoint is recorded above.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor Gate 1 validation completed for exact pre-callback SHA256 `5FE6F7FBC2562EB797D2D44FBEF476880DE444843D206A80FD5A31ECDDBEB064` before implementation.
- [x] Target/support docs updated: UID0003PI, UID0000BJ, UID0000MY, UID0000P8, UID0001NZ, UID0002Z8, UID0001WJ, UID0001VH, UID0003O0, and UID0001O2 as listed above.
- [x] Every declared additional UID has target-specific evidence, recommendation, ledger rows, destination docs, and planned validation: not applicable; no additional target UID is declared.
- [x] Current target state and actual evidence checked recorded.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score change applied: UID0003PI `86/88 -> 92/94` only.
- [x] Score-limiting blockers researched to resolution: `+0xf6` role/name, source placement, ABI/source mapping, caller route, layout, range, and formal body are closed.
- [x] Owner/emitter/reconstructable changes: none; UID0000BJ/UID0000BJ/true preserved.
- [x] Split/rename/new-child changes: none; exact documentation range and existing child structure preserved.
- [x] Source-placement, range/split/padding/reclassification, and IDA rename/type/comment work are resolved or handed off at exact-action detail.
- [x] Supervisor Gate 2B IDA handoff lists every exact address/entity, pre-state, proposed action, supporting type, safety constraint, and expected readback; B003 did not mutate IDA.
- [x] First-draft C++ applied: exact UID0003PI managed constructor block.
- [x] Third-party import directive: not applicable; NexusTK project code.
- [x] Exact target/support doc facts incorporated at report-level detail.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale.
- [x] Open questions closed with best supported inference and score cap.
- [x] Serial scoped file validators run for every changed ordinary by-* doc after callback.
- [x] Validator-owned generated output refreshed: one UID0003PI constructor and zero UID0003PI empty markers; tracker refreshed to `92/94`.
- [x] Exact supervisor-owned manual coverage replacement text remains recorded and was not applied by B003.

Implementation callback pass:

- [x] Report accepted by supervisor for ordinary-document implementation.
- [x] All accepted target/support doc details incorporated at report-level detail.
- [x] Every declared primary/additional UID verified independently against its ledger and destination docs.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly preserved with reason.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions resolved with evidence-backed inference and bounded final-audit caps.
- [x] Validators run and exact results recorded.
- [x] Generated output/tracker refresh completed by validators and exact current readback recorded.
- [x] Remaining unapplied accepted documentation item is limited to C3PI-32 supervisor manual coverage work after execution.
- [x] Supervisor post-callback exact-artifact Gate 1 and Gate 2A claim-by-claim verification passed for SHA256 `8294F430EADFBBEE4BC873B25C9C8C06BBE5B4E9F3C45C7E28E143492EDB9B76`; commands 17065-17074 all returned `ok:1`.
- [x] Supervisor Gate 2B applied and read back C3PI-29/C3PI-30 at `2026-07-24T02:04:56-04:00`; B003 did not mutate IDA.
- [ ] Supervisor fresh final exact-artifact Gate 1/Gate 2 continuity audit after this report-only reconciliation.
- [ ] Supervisor-only `execute_report` validation/archive after the fresh final audit.
- [ ] Supervisor applies and validates C3PI-32 exact manual coverage rows only after execution.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000017079","destination_path":"executed-b-agent-research/B003/0003PI-RainingLayerPaneConstructor-empty-emitter-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0003PI-RainingLayerPaneConstructor-empty-emitter-source-quality.md","timestamp":"2026-07-24T02:22:56-04:00","uid":"0003PI"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
