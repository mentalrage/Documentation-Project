** TARGET-REPORT-UID:000351 **
** AUTHOR-AGENT-ID:B015 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:000351] EffectObjectPaneVtableData Empty-Emitter / Source-Quality Report

Agent: B015  
Assignment id: `B015-report-000351-EffectObjectPaneVtableData-empty-emitter-source-quality-20260628`  
Revision assignment id: `B015-revise-report-000351-EffectObjectPaneVtableData-empty-emitter-source-quality-20260628`  
Target: `by-memory/0x006205f8-0x006206ac.EffectObjectPaneVtableData.md`  
Mode: report-only research, followed by 2026-06-29 supervisor-accepted implementation callback. The report body records the accepted disposition; the ledger and checklist now carry callback proof. No generated files, coverage reports, validator/tool state, executed reports, or IDA DB were edited manually.

## Recommendation

Implement a source-quality marker, not handwritten table C++.

Recommended target metadata after implementation:

- `COMPLETION:88`
- `CONFIDENCE:92`
- `CANONICAL_OWNER:000049`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:000049`
- `EMITTER_POSITION_OPTIONAL:` blank

Recommended formal `RECONSTRUCTION_CPP CODE` for the target:

```markdown
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted code for this range is covered by [UID:000049].
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Rationale: `0x006205f8-0x006206ac` is compiler-emitted RTTI/vtable data generated from the `EffectObjectPane` class declaration and virtual methods. The rebuilt source should not hand-author an address-shaped table. The current blank block causes an empty emitter marker in generated `Effects.cpp`, so a formal covered-by comment is the correct source-quality disposition under the special non-code-emitter rule.

Recommended target `Item Summary`:

`Exact EffectObjectPane RTTI/vtable range with primary, +0xa0 EventHandler/pane-handler, and +0xa4 TimerHandler/event adjusted views; source-declared/generated-binary data covered by the EffectObjectPane class declaration, not a handwritten table.`

## Current Target State

Current target header before recommended changes:

- `COMPLETION:85`
- `CONFIDENCE:88`
- `CANONICAL_OWNER:000049`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:000049`
- blank formal C++ block
- stale `Item Summary`: "parent blank because class/file confidence is below gate"

The owner/emitter metadata is already repaired. The stale part is the summary/generated coverage text and the blank formal C++ block. Current support docs show the direct gate is no longer blocked: [UID:000049] `EffectObjectPane` is `85/86`, and [UID:0000IZ] `Effects` is `89/85`.

Generated symptom checked read-only:

- `auto-generated/-ag-research-tracker.md` lists UID000351 in `Files With Empty Emitters`, score `85/88`, report count `0`.
- `auto-generated/-ag-memory-coverage.md` lists UID000351 as `emits`, owner/emitter `000049`, output `auto-generated/NexusTK/render/Effects.cpp`, but `emits_code:false`.
- `auto-generated/NexusTK/render/Effects.cpp` has `// UID:000351 ... Empty Emitter Marker`.
- `auto-generated/-ag-coverage-report-by-memory.md` repeats the stale source summary because the target `Item Summary` still says the parent is blank.

## MCP Availability And Provenance

IDA MCP was available and used for the evidence pass.

- `tools/list` succeeded through direct JSON-RPC at `http://127.0.0.1:13337/mcp`.
- `idb_list` returned one active session: `agent_b009_0002my_20260628`, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, active worker PID `2412`.
- `server_health` with `database='agent_b009_0002my_20260628'` returned `status:"ok"`, `idb_path:"E:\NTK\Resources\NexusTK\NexusTK.exe.i64"`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_ready:true`.
- One initial `server_health` probe without `database` returned the current-schema error "database is required"; this was a call-shape correction, not MCP unavailability. All subsequent evidence calls used the active database session.
- MCP tools used read-only: `get_int`, `entity_query`, `lookup_funcs`, `xrefs_to`, and `disasm`.
- 2026-06-29 revision MCP check after supervisor restore: `idb_list` returned active session `07c55da0`, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `9064`; `server_health` returned `status:"ok"`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, and string cache size `2067`.
- 2026-06-29 narrow recheck on session `07c55da0` confirmed the same target-critical facts: dwords `0x006205f8 -> 0x0064d12c`, `0x006205fc -> 0x0053d100`, `0x00620670 -> 0x0064d190`, `0x00620674 -> 0x0053ced0`, `0x006206a0 -> 0x0064d1a4`, `0x006206a4 -> 0x0053cedb`, and `0x006206ac -> 0x0064d1b8`; `xrefs_to` still reports three refs each for `0x006205fc`, `0x00620674`, and `0x006206a4` from constructor `0x005387b0`, ordinary destructor `0x00538880`, and scalar deleting destructor `0x0053d100`, while `0x006206ac` has no direct xrefs as the successor RTTI boundary.

No IDA write tools were called.

## Documents And Reports Checked

Current docs checked:

- `by-memory/0x006205f8-0x006206ac.EffectObjectPaneVtableData.md`
- `by-class/EffectObjectPane.md`
- `by-file/Effects.md`
- `by-memory/0x00620284-0x00620c74.ObjectPaneReadOnlyData.md`
- `by-memory/0x005387b0-0x00538baa.EffectObjectPaneCore.md`
- `by-memory/0x00538880-0x0053889f.EffectObjectPaneNonDeletingDestructor.md`
- `by-memory/0x0053d100-0x0053d197.EffectObjectPaneScalarDeletingDestructor.md`
- `by-memory/0x005388a0-0x005388b4.EffectObjectPaneStartIdleTimer.md`
- Neighboring vtable pages `0x00620544-0x006205f8.AttachedObjectPaneVtableData.md` and `0x006206ac-0x00620734.BowGaugeObjectPaneVtableData.md`

Executed reports checked as context, not accepted blindly:

- `executed-b-agent-research/B001/000260-ObjectPaneReadOnlyData.md`
- `executed-b-agent-research/B001/0002QV-effectobjectpane-non-deleting-destructor-source-quality.md`
- `executed-b-agent-research/B002/0001DA-EffectObjectPaneStartIdleTimer-source-quality.md`

Generated files checked read-only:

- `auto-generated/-ag-research-tracker.md`
- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/-ag-coverage-report-by-memory.md`
- `auto-generated/NexusTK/render/Effects.cpp`

## Stale Source-Recovery / Wave Handling

`by-class/EffectObjectPane.md` currently contains two stale generated-source lead bullets in its status block:

- `Current recovered source: source-3/simroot_v2/class_EffectObjectPane.cpp`
- `Wave3 summary: game object pane for visual effect rendering.`

These were encountered during support-doc review. They are not evidence for UID000351's owner, emitter, score, range, or marker recommendation. The UID000351 recommendation relies on current IDA MCP facts, current by-* docs, current generated reports as generated-state symptoms, and source-shape inference for MSVC RTTI/vtable regeneration. It does not rely on Wave2, Wave3, `simroot_v2`, old recovered source paths, or recovered one-class source output.

Implementation should not leave those two bullets in `by-class/EffectObjectPane.md` as live support evidence. The class page may preserve the information only as a clearly historical generated lead. Recommended support-doc replacement:

```markdown
- Historical generated lead, not current evidence: older Wave3/simroot_v2 output staged this class as `source-3/simroot_v2/class_EffectObjectPane.cpp` and summarized it as a visual effect object pane. Treat that as superseded discovery context only; current ownership/source route is based on IDA MCP vtable/RTTI, constructor/destructor, pool, and current by-* evidence.
```

This is a support-doc hygiene action, not a change to UID000351's binary disposition. If the supervisor wants a less intrusive implementation, the same fact can be moved into a short historical/stale-generated-source note on the class page, but it must not remain framed as active "current recovered source" evidence.

## RTTI / Vtable Boundary Evidence

Current MCP `get_int` over `0x006205f8-0x006206ac` reads a contiguous dword table beginning with the EffectObjectPane RTTI complete object locator pointer and ending before the BowGaugeObjectPane RTTI complete object locator pointer.

Key dwords and names:

| Address | Current value / IDA name | Meaning |
| --- | --- | --- |
| `0x006205f8` | `0x0064d12c` -> `??_R4EffectObjectPane@@6B@` | EffectObjectPane primary RTTI COL pointer; exact target start. |
| `0x006205fc` | `0x0053d100`, name `??_7EffectObjectPane@@6B@` | Primary EffectObjectPane vtable base, slot 0 scalar deleting destructor. |
| `0x0062064c` | `0x00538960` | EffectObjectPane virtual `GetFrameBounds` slot. |
| `0x00620658` | `0x00538af0` | EffectObjectPane virtual render slot. |
| `0x0062066c` | `0x005388c0` | EffectObjectPane virtual bounds slot. |
| `0x00620670` | `0x0064d190` -> `??_R4EffectObjectPane@@6B@_0` | Adjusted `+0xa0` RTTI COL pointer. |
| `0x00620674` | `0x0053ced0`, name `??_7EffectObjectPane@@6B@_0` | Adjusted `+0xa0` vtable base; deleting-destructor adjustor. |
| `0x006206a0` | `0x0064d1a4` -> `??_R4EffectObjectPane@@6B@_1` | Adjusted `+0xa4` RTTI COL pointer. |
| `0x006206a4` | `0x0053cedb`, name `??_7EffectObjectPane@@6B@_1` | Adjusted `+0xa4` TimerHandler/event vtable base; deleting-destructor adjustor. |
| `0x006206a8` | `0x005389d0` | Timer/event adjusted-view callback into EffectObjectPane update logic. |
| `0x006206ac` | `0x0064d1b8` -> `??_R4BowGaugeObjectPane@@6B@` | Next owner RTTI COL pointer; excluded successor boundary. |
| `0x006206b0` | `0x0053cfe0`, name `??_7BowGaugeObjectPane@@6B@` | Next owner vtable base; excluded. |

Current `entity_query kind=names` over `0x006205ec-0x006206b4` returns the vtable names:

- `0x006205f0`: `??_7AttachedObjectPane@@6B@_1`
- `0x006205fc`: `??_7EffectObjectPane@@6B@`
- `0x00620674`: `??_7EffectObjectPane@@6B@_0`
- `0x006206a4`: `??_7EffectObjectPane@@6B@_1`
- `0x006206b0`: `??_7BowGaugeObjectPane@@6B@`

This confirms the exact child starts after the final AttachedObjectPane adjusted view and ends before BowGaugeObjectPane. No split/merge/rename is needed.

## Constructor / Destructor Vptr Store Evidence

Current `xrefs_to` for the three vtable bases shows exactly the expected constructor, ordinary destructor, and scalar deleting destructor references:

| Vtable base | Xrefs | Meaning |
| --- | --- | --- |
| `0x006205fc` | `0x005387e9`, `0x00538880`, `0x0053d125` | Primary EffectObjectPane view written by constructor, ordinary destructor, scalar deleting destructor. |
| `0x00620674` | `0x005387ef`, `0x00538886`, `0x0053d12b` | Adjusted `+0xa0` view written by the same three paths. |
| `0x006206a4` | `0x005387f9`, `0x00538890`, `0x0053d135` | Adjusted `+0xa4` TimerHandler/event view written by the same three paths. |

Current `disasm 0x005387b0` confirms the constructor stores:

- `0x005387e9`: `mov dword ptr [edi], offset ??_7EffectObjectPane@@6B@`
- `0x005387ef`: `mov dword ptr [edi+0A0h], offset ??_7EffectObjectPane@@6B@_0`
- `0x005387f9`: `mov dword ptr [edi+0A4h], offset ??_7EffectObjectPane@@6B@_1`

Current `disasm 0x00538880` is the four-instruction ordinary destructor body already described in support docs:

- `mov [ecx], 0x006205fc`
- `mov [ecx+0xa0], 0x00620674`
- `mov [ecx+0xa4], 0x006206a4`
- `jmp 0x00538100`

Current `disasm 0x0053d100` confirms the scalar deleting destructor stores the same three views before base cleanup and optional pool free:

- `0x0053d125`: `mov dword ptr [esi], offset ??_7EffectObjectPane@@6B@`
- `0x0053d12b`: `mov dword ptr [esi+0A0h], offset ??_7EffectObjectPane@@6B@_0`
- `0x0053d135`: `mov dword ptr [esi+0A4h], offset ??_7EffectObjectPane@@6B@_1`
- `0x0053d13f`: `call sub_538100`
- `0x0053d150`: pool receiver `unk_69B90C`
- `0x0053d15c`: pool/free helper `sub_4B14C0`

Current adjustor thunk disassembly:

- `0x0053ced0`: `sub ecx, 0xa0; jmp sub_53D100`
- `0x0053cedb`: `sub ecx, 0xa4; jmp sub_53D100`

The adjusted-view interpretation from prior accepted reports remains correct. `+0xa0` is the inherited EventHandler/pane-handler adjusted view, and `+0xa4` is the inherited TimerHandler/event adjusted view. The adjacent source-ready [UID:0001DA] `EffectObjectPane::StartIdleTimer()` adds `0xa4` to `this` and calls `TimerHandler::ScheduleTimer(1, 0, 0, 0)`, independently supporting the `+0xa4` role.

## Slot Target / Liveness Evidence

Current `xrefs_to` for representative slot targets confirms this range is the table that makes the EffectObjectPane virtual methods reachable:

- `0x0053d100` has data xref from `0x006205fc` plus code xrefs from adjustor thunks `0x0053ced6` and `0x0053cee1`.
- `0x0053ced0` has data xref from `0x00620674`.
- `0x0053cedb` has data xref from `0x006206a4`.
- `0x005388c0` has data xref from `0x0062066c`.
- `0x00538960` has data xref from `0x0062064c`.
- `0x005389d0` has data xref from `0x006206a8`.
- `0x00538af0` has data xref from `0x00620658`.
- `0x00538880` still has zero direct xrefs, consistent with the already-executed ordinary-destructor-body report.
- `0x005388a0` has its direct MapPane creation caller at `0x0050eb14`, but it is not a vtable slot in UID000351.

This proves the table is live and class-owned, but it also proves source emission belongs in class declarations/method pages rather than as hand-authored table initializers.

## Owner / Emitter / Source-Placement Analysis

Accepted owner: [UID:000049] `EffectObjectPane`.

Evidence:

- The table names are `??_7EffectObjectPane@@6B@`, `_0`, and `_1`.
- The constructor, ordinary destructor, and scalar deleting destructor all write the same three table bases into the same complete object.
- The adjusted deleting destructor thunks normalize `this` from `+0xa0` and `+0xa4` back to the complete object before jumping to `EffectObjectPane` scalar deleting destructor.
- The slot targets include EffectObjectPane methods from the core range and the timer/event callback path.
- The direct class parent [UID:000049] now clears the gate at `85/86`, and the file root [UID:0000IZ] clears the file route at `89/85`.

Rejected owners and placements:

- `ObjectPane`: too broad; this is a derived EffectObjectPane table, not a base ObjectPane table. Base ObjectPane has its own exact child [UID:0002SK].
- `AttachedObjectPane`: predecessor boundary only. Its final adjusted view ends before this child, and the target starts at the next dword.
- `BowGaugeObjectPane`: successor boundary only. BowGauge RTTI begins at `0x006206ac` and is excluded.
- `TimerHandler` / `EventHandler`: explain adjusted inherited views, but do not own the complete class vtable range.
- `EffectObjImageLib`: render asset dependency only; it does not own the object-pane vtable.
- A new standalone global/table owner: rejected because MSVC RTTI/vtable output is compiler-generated from the class declaration, not a source-authored global table.

Emitter route should remain [UID:000049] -> [UID:0000IZ] -> `auto-generated/NexusTK/render/Effects.cpp`. The open question about final original source granularity (`Effects.cpp` versus an `EffectObjectPane.cpp` companion) does not block the current route; current project docs consistently place EffectObjectPane under the runtime effects module until a broader class/source split pass proves otherwise.

## Empty-Emitter Disposition And C++ Decision

The target is `RECONSTRUCTABLE:TRUE` because source declarations are required to reproduce the table in the rebuilt binary. It is also source-declared/generated-binary data, not hand-authored source data.

Therefore:

- Do not emit a manually written vtable array or RTTI object.
- Do not set `RECONSTRUCTABLE:FALSE`; that would hide a real source-declaration dependency.
- Do not blank `EMITTER_UIDS`; the owner/emitter route is valid and should remain visible to generated reports.
- Do add a formal covered-by marker comment so the generated output no longer treats UID000351 as an empty emitter.

The marker should be minimal because the actual source belongs in the future `EffectObjectPane` class declaration and exact method pages. A longer hand-authored explanation inside C++ output would make the generated source look reverse-engineering-shaped.

## Score Recommendation

Raise UID000351 from `85/88` to `88/92`.

Completion should rise because the current pass resolves the empty-emitter disposition, current owner gate, stale item summary, exact boundaries, three adjusted views, constructor/destructor/scalar-destructor vptr store parity, slot-target liveness, and formal marker text.

Confidence should rise because current MCP independently reconfirmed the target range and table ownership through dword reads, IDA names, xrefs, and disassembly. Confidence should remain below final-audit level because the complete `EffectObjectPane` class declaration and final original source split are still not fully reconstructed, and the marker only covers source-declared generated-binary data rather than final class source.

## Support Repair Recommendations

Required target doc changes:

- Update target scores to `88/92`.
- Replace the stale Item Summary with the recommended summary above.
- Keep owner/emitter route unchanged: `000049`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Insert the exact formal covered-by marker comment in `RECONSTRUCTION_CPP CODE:BEGIN/END`.
- Clarify that the dwords at `0x006205f8`, `0x00620670`, and `0x006206a0` point to RTTI complete object locators `0x0064d12c`, `0x0064d190`, and `0x0064d1a4`; the visible vtable names are at `0x006205fc`, `0x00620674`, and `0x006206a4`.
- Add current MCP evidence for session `agent_b009_0002my_20260628`, boundary dwords, vptr xrefs, adjustor thunks, and slot-target xrefs.
- Add a change entry preserving the rejected alternatives and explaining that the old "parent blank because class/file confidence is below gate" wording is stale.

Required support doc changes:

- `by-class/EffectObjectPane.md`: add a B015 note that UID000351 now has a formal covered-by marker because the vtable/RTTI bytes are source-declared/generated-binary output of the class declaration; keep class-level C++ blank and preserve the existing class-wide source blockers. Also replace or historicalize the stale live status bullets for `Current recovered source: source-3/simroot_v2/class_EffectObjectPane.cpp` and `Wave3 summary` using the stale-source/Wave handling text above, because those generated-source leads are not evidence for UID000351.
- `by-file/Effects.md`: add a B015 support note that the EffectObjectPane vtable data is not a handwritten table in `Effects.cpp`; it is covered by the class declaration/method route through [UID:000049], with the exact source split still open.
- `by-memory/0x00620284-0x00620c74.ObjectPaneReadOnlyData.md`: update the UID000351 child row/change notes to say current B015 MCP reconfirmed the exact `0x006205f8-0x006206ac` boundary and source-declared/generated-binary marker disposition. Preserve the aggregate as `RECONSTRUCTABLE:FALSE`.
- Optional/no-score support sync only if the supervisor wants all local support docs to carry the detail: `by-memory/0x005387b0-0x00538baa.EffectObjectPaneCore.md` can add one sentence that UID000351's table route is now marker-covered, while aggregate C++ remains blank.

Read/check-only support pages unless contradictions are found during implementation:

- `by-memory/0x00538880-0x0053889f.EffectObjectPaneNonDeletingDestructor.md`
- `by-memory/0x0053d100-0x0053d197.EffectObjectPaneScalarDeletingDestructor.md`
- `by-memory/0x005388a0-0x005388b4.EffectObjectPaneStartIdleTimer.md`
- Neighboring `AttachedObjectPaneVtableData` and `BowGaugeObjectPaneVtableData`

No manual coverage-report edit is recommended for B015. The validator-owned auto coverage row should refresh from the target `Item Summary`. The legacy manual `by-memory/-coverage-report.md` contains the same stale summary, but it is outside B-agent edit scope unless the supervisor explicitly authorizes a manual coverage-report update.

## Claim And Incorporation Ledger

| ID | Claim / fact to preserve | Action | Intended destination or exclusion | Verification state |
| --- | --- | --- | --- | --- |
| C01 | UID000351 covers exact range `0x006205f8-0x006206ac`. | incorporate | Target range/evidence section in `by-memory/0x006205f8-0x006206ac.EffectObjectPaneVtableData.md`; support row in `ObjectPaneReadOnlyData`. | applied - target Summary/Range and `ObjectPaneReadOnlyData` child row now state exact `0x006205f8-0x006206ac`; validators `000000000257` and `000000000260` exit 0 ok 1. |
| C02 | Range starts at EffectObjectPane RTTI COL pointer dword `0x006205f8 -> 0x0064d12c` and excludes preceding AttachedObjectPane data. | incorporate | Target boundary evidence; `ObjectPaneReadOnlyData` child row/change note. | applied - target IDA Evidence and Boundary notes record `0x006205f8 -> 0x0064d12c` and predecessor AttachedObjectPane exclusion; aggregate support note repeats predecessor boundary. |
| C03 | Range ends before successor `0x006206ac -> 0x0064d1b8` BowGaugeObjectPane RTTI COL pointer; `0x006206b0` is BowGauge vtable and excluded. | incorporate | Target boundary evidence; `ObjectPaneReadOnlyData` child row/change note. | applied - target IDA Evidence and Boundary notes record `0x006206ac -> 0x0064d1b8` and `0x006206b0` BowGauge vtable exclusion; aggregate support note records successor BowGauge boundary. |
| C04 | Primary vtable base `0x006205fc` is `??_7EffectObjectPane@@6B@` and points to scalar deleting destructor `0x0053d100`. | incorporate | Target IDA evidence table and vtable notes. | applied - target IDA Evidence table records `0x006205fc` as `??_7EffectObjectPane@@6B@ -> 0x0053d100` with constructor, ordinary destructor, and scalar deleting destructor refs. |
| C05 | Adjusted view `0x00620674` is the `+0xa0` EventHandler/pane-handler adjusted view and reaches adjustor thunk `0x0053ced0`. | incorporate | Target adjusted-view evidence; `EffectObjectPane` class support note if room. | applied - target IDA Evidence and Boundary notes record the `+0xa0` view and `0x0053ced0`; `by-class/EffectObjectPane.md` B015 evidence note records the same inherited adjusted view. |
| C06 | Adjusted view `0x006206a4` is the `+0xa4` TimerHandler/event adjusted view and reaches adjustor thunk `0x0053cedb`. | incorporate | Target adjusted-view evidence; `EffectObjectPane` class support note if room. | applied - target IDA Evidence and Boundary notes record the `+0xa4` view and `0x0053cedb`; `by-class/EffectObjectPane.md` B015 evidence note records the same inherited adjusted view. |
| C07 | Constructor `0x005387b0`, ordinary destructor `0x00538880`, and scalar deleting destructor `0x0053d100` each write the same three vtable bases. | incorporate | Target vptr-store evidence; class support note. | applied - target Boundary notes, target change entry, class B015 evidence note, and ObjectPane aggregate B015 note all record constructor/destructor/scalar-destructor store parity. |
| C08 | Adjustor thunks subtract `0xa0` and `0xa4` before jumping to scalar deleting destructor, proving adjusted views rather than independent classes. | incorporate | Target destructor/adjustor evidence. | applied - target Boundary notes record adjusted thunk behavior and adjusted-view conclusion; no support contradiction found in checked destructor/timer pages. |
| C09 | Slot-target xrefs make the table live, including slots to EffectObjectPane bounds/render/update methods; this is not dead data. | incorporate | Target slot-target/liveness section. | applied - target Boundary notes list live slots `0x0062064c`, `0x00620658`, `0x0062066c`, and `0x006206a8`; aggregate support note records slot-target liveness. |
| C10 | UID000351 is source-declared/generated-binary data: rebuild should regenerate RTTI/vtables from class declarations and virtual methods, not hand-author a table. | incorporate | Target rebuild handling and C++ disposition; support notes in class/file pages. | applied - target Summary/Reconstruction Notes, class Reconstruction State, Effects evidence/change note, ObjectPane aggregate row, and core support sync all record source-declared/generated-binary marker disposition. |
| C11 | Formal C++ should be the exact marker `// Emitted code for this range is covered by [UID:000049].` | incorporate | Target `RECONSTRUCTION_CPP CODE:BEGIN/END`. | applied - target formal `RECONSTRUCTION_CPP CODE` block contains the marker; generated `Effects.cpp` line for UID000351 contains the expanded covered-by marker and no UID000351 Empty Emitter Marker. |
| C12 | Metadata should move from `85/88` to `88/92`, owner/emitter unchanged at `000049`, reconstructable unchanged `TRUE`. | incorporate | Target metadata header and change entry. | applied - target header is `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:000049`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000049`, blank emitter position; validator `000000000257` confirmed metadata updates. |
| C13 | Current stale target `Item Summary` saying parent is blank because class/file confidence is below gate is superseded. | reject-stale | Replace target `Item Summary`; mention old parent-gate wording as stale in target change/evidence note. | applied - target `Item Summary` replaced with marker-covered adjusted-view summary; target change entry explicitly records stale parent-blank wording as before state. |
| C14 | `by-class/EffectObjectPane.md` stale live `Current recovered source: source-3/simroot_v2/class_EffectObjectPane.cpp` / `Wave3 summary` wording is not evidence for UID000351. | historicalize | Replace or move to historical generated lead note on `by-class/EffectObjectPane.md`; do not leave as live current evidence. | applied - class Status replaced the live recovered-source and Wave3 summary bullets with a historical generated-lead note; post-verification correction also historicalized the same live recovered-source line in edited support page `by-memory/0x005387b0-0x00538baa.EffectObjectPaneCore.md`; no active `Current recovered source` line remains in that core page. |
| C15 | UID000351 recommendation does not rely on Wave2/Wave3/simroot/recovered-source output. | incorporate | Report implementation notes; class support historicalization; no by-* source claim should cite Wave/recovered-source as proof for UID000351. | applied - class B015 evidence note states UID000351 support does not use Wave2/Wave3/simroot/recovered-source output; file support describes `class_EffectObjectPane.cpp` as staging only and uses current MCP evidence for UID000351; corrected core page now labels the `simroot_v2` path as a historical generated lead, not current evidence. |
| C16 | Rejected owners: ObjectPane, AttachedObjectPane, BowGaugeObjectPane, TimerHandler/EventHandler, EffectObjImageLib, standalone global/table owner. | incorporate | Target rejected alternatives/source-placement section. | applied - target Assignment Gate records each rejected route and the reason; predecessor/successor and adjusted-view support pages were read-only checked with no contradiction. |
| C17 | Emitter route should stay [UID:000049] -> [UID:0000IZ] -> `auto-generated/NexusTK/render/Effects.cpp`. | incorporate | Target owner/emitter section and class/file support notes. | applied - target metadata and Assignment Gate keep owner/emitter [UID:000049]; class and Effects support notes preserve route through [UID:0000IZ]; generated `Effects.cpp` header is source by-file UID `0000IZ`. |
| C18 | `ObjectPaneReadOnlyData` remains `RECONSTRUCTABLE:FALSE`; only exact child UID000351 carries the vtable-data route. | incorporate | `by-memory/0x00620284-0x00620c74.ObjectPaneReadOnlyData.md`. | applied - ObjectPane aggregate header remains `RECONSTRUCTABLE:FALSE`; UID000351 child row and B015 change note record exact child marker-covered route only. |
| C19 | Manual `by-memory/-coverage-report.md` should not be edited by B015; stale manual row is outside callback scope unless supervisor explicitly authorizes it. | not-applicable | Report/checklist only; no by-* manual coverage edit. | excluded-with-reason - assignment forbids manual coverage-report edits and no override named `by-memory/-coverage-report.md`; no manual coverage report was edited. Validator-owned generated coverage refreshed from source by-* docs. |
| C20 | Generated reports/C++ should refresh through validator; implementation should check generated `Effects.cpp` read-only for UID000351 no longer being an empty emitter. | incorporate | Validator plan and implementation closeout expectations. | applied - scoped validators ran with `--wait-generated`; post-correction generated `auto-generated/NexusTK/render/Effects.cpp` header is command `000000000267` at `2026-06-29T01:28:52-04:00`, newer than target validator `000000000257`, and UID000351 has the covered-by marker with no UID000351 Empty Emitter Marker. |

## Validator Plan For Implementation Callback

Run scoped validators from `E:\NTK\GhidraBridge\source-3\project-documentation` after accepted edits:

> Executable block R001 was removed from this report and preserved verbatim in [000351-EffectObjectPaneVtableData-empty-emitter-source-quality-removed.md](000351-EffectObjectPaneVtableData-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If `by-memory/0x005387b0-0x00538baa.EffectObjectPaneCore.md` is edited for optional support sync, also run:

> Executable block R002 was removed from this report and preserved verbatim in [000351-EffectObjectPaneVtableData-empty-emitter-source-quality-removed.md](000351-EffectObjectPaneVtableData-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Generated output should be checked read-only after the target validator. Expected result: `auto-generated/NexusTK/render/Effects.cpp` should contain UID000351 with the covered-by comment and should no longer show `Empty Emitter Marker` for UID000351.

## Open Question Closure And Scope Disposition

Every named uncertainty in this report is either resolved for UID000351, converted into implementation-ready support text, or explicitly outside this UID000351 vtable-data assignment:

- UID000351's target-specific C++ disposition is resolved: use the covered-by marker, not hand-authored vtable data.
- UID000351's range/split issue is resolved: exact `0x006205f8-0x006206ac`, no split/merge/rename needed.
- UID000351's owner/emitter issue is resolved: keep owner/emitter [UID:000049] with output route through [UID:0000IZ].
- The stale class-page Wave/recovered-source wording is converted into an implementation-ready support edit: historicalize or replace those live status bullets as described above.
- The full `EffectObjectPane` class declaration is outside this UID000351 callback except for preserving that class-level C++ remains blank; the vtable marker is the implementation-ready no-table proof for this exact data range.
- Final original source split remains open between `render/Effects.cpp`, a small `EffectObjectPane.cpp` companion, or a nearby object-pane source unit. That broader source-tree decision is outside this vtable-data assignment; current route through [UID:0000IZ] remains the best supported route and is sufficient for UID000351.
- Constructor/frame/render field names, scalar deleting destructor source spelling, and pool allocator declaration style are class-wide/source-pass topics outside this exact vtable-data report. They do not affect the table boundary, owner, emitter route, or marker recommendation.

None of those justify leaving UID000351 as an empty emitter. The exact vtable data has a valid current owner/emitter route and a precise source-declared/generated-binary no-table proof.

## 2026-06-29 Post-Verification Correction

Supervisor verification found one narrow stale-source issue in the optional support page edited during implementation: `by-memory/0x005387b0-0x00538baa.EffectObjectPaneCore.md` still had an active `Current recovered source: source-3/simroot_v2/class_EffectObjectPane.cpp` line.

Correction applied: that line now reads as a historical generated lead, not current evidence: older Wave3/simroot_v2 output staged the class as `source-3/simroot_v2/class_EffectObjectPane.cpp`, while current ownership/source route is based on IDA MCP and by-* evidence. No UID000351 target metadata, C++ marker, owner/emitter, or score was changed.

Scoped validator run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R003 was removed from this report and preserved verbatim in [000351-EffectObjectPaneVtableData-empty-emitter-source-quality-removed.md](000351-EffectObjectPaneVtableData-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Validator result: command `000000000267`, timestamp `2026-06-29T01:28:52-04:00`, exit code 0, `ok: 1`, `generated_refresh: completed`. Known existing diagnostic remained: old UID00023H target path `by-memory/0x00538bb0-0x00538bb7.LivingObjectPaneGetEntityId.md` is missing. Validator-owned generated refreshes/backups/projected stats/autogen registry rebuild occurred; no manual generated/project-level/tool-state edit was made.

Lease proof: B015 leased only `by-memory/0x005387b0-0x00538baa.EffectObjectPaneCore.md` for the correction and released it after validation; `tools/leaser/Agents/current_leases.md` then reported `No active leases.`

## Implementation Tracking Checklist

- [x] Target metadata update: `by-memory/0x006205f8-0x006206ac.EffectObjectPaneVtableData.md` to `COMPLETION:88`, `CONFIDENCE:92`, owner/emitter unchanged at `000049`, reconstructable unchanged `TRUE`, blank emitter position. Proof: target header now has `88/92`, owner/emitter `000049`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_POSITION_OPTIONAL`; validator `000000000257` at `2026-06-29T01:20:22-04:00` exited 0 with `ok: 1`.
- [x] Target formal C++ marker: insert exactly `// Emitted code for this range is covered by [UID:000049].` in the target `RECONSTRUCTION_CPP CODE:BEGIN/END` block; do not add a handwritten vtable array. Proof: target formal block contains only that marker; generated `Effects.cpp` expands it on UID000351 and no handwritten table was added.
- [x] Target summary/evidence update: replace stale "parent blank" Item Summary, clarify RTTI COL pointer dwords versus vtable-base names, add MCP session `agent_b009_0002my_20260628` evidence for `get_int`, `entity_query`, `xrefs_to`, `lookup_funcs`, and `disasm`. Proof: target `Item Summary`, `IDA Evidence`, `Boundary, View, And Liveness Notes`, and B015 change entry now carry those details.
- [x] Target revision evidence update: preserve the original MCP evidence and add the 2026-06-29 restored-session check from active session `07c55da0`, including health status and the narrow dword/xref spot-check confirming no recommendation change. Proof: target `IDA Evidence` records active session `07c55da0`, `server_health` OK, imagebase `0x400000`, readiness fields, `get_bytes` dwords, and `xrefs_to` triple/no-xref successor results.
- [x] Target rejected-alternatives preservation: document rejected ObjectPane, AttachedObjectPane, BowGaugeObjectPane, TimerHandler/EventHandler, EffectObjImageLib, and standalone global/table ownership alternatives. Proof: target `Assignment Gate` lists each rejected owner route and reason.
- [x] Support update: `by-class/EffectObjectPane.md` records UID000351 as marker-covered source-declared/generated-binary vtable/RTTI data while class-level C++ remains blank. Proof: class Batch233 evidence, Reconstruction State, and 2026-06-29 B015 change section record UID000351 marker coverage and preserve class-level blank C++ blockers; validator `000000000258` at `2026-06-29T01:20:40-04:00` exited 0 with `ok: 1`.
- [x] Support stale-source/Wave handling: in `by-class/EffectObjectPane.md`, replace or move the live status bullets `Current recovered source: source-3/simroot_v2/class_EffectObjectPane.cpp` and `Wave3 summary: game object pane for visual effect rendering.` into a clearly historical generated-lead note, using the recommended wording from this report or equivalent report-level detail. Confirm that UID000351 support text does not cite Wave2/Wave3/simroot/recovered source as evidence. Proof: class Status now has a single historical generated-lead note; the old live bullets were removed; B015 class note states UID000351 support does not use Wave2/Wave3/simroot/recovered-source output.
- [x] Support update: `by-file/Effects.md` records that UID000351 is not handwritten Effects.cpp table source and is covered through the EffectObjectPane class route. Proof: Effects Proposed Contents row, Evidence paragraph, and B015 change entry record marker-covered class route and source split still open; validator `000000000259` at `2026-06-29T01:20:55-04:00` exited 0 with `ok: 1`.
- [x] Support update: `by-memory/0x00620284-0x00620c74.ObjectPaneReadOnlyData.md` records the B015 boundary/marker disposition for UID000351 while preserving the aggregate as non-emitting `RECONSTRUCTABLE:FALSE`. Proof: aggregate header remains `RECONSTRUCTABLE:FALSE`; UID000351 child row and B015 evidence/change notes record exact marker-covered route; validator `000000000260` at `2026-06-29T01:21:09-04:00` exited 0 with `ok: 1`.
- [x] Optional support sync only if edited: `by-memory/0x005387b0-0x00538baa.EffectObjectPaneCore.md` may mention UID000351's marker-covered table route without changing aggregate blank-C++ policy. Proof: edited; core 2026 verification and B015 change section mention UID000351 marker-covered route and explicitly keep aggregate blank-C++ policy unchanged; validator `000000000261` at `2026-06-29T01:21:24-04:00` exited 0 with `ok: 1`. Post-verification correction historicalized the page's remaining active `Current recovered source` line as stale Wave3/simroot_v2 generated lead material; correction validator `000000000267` at `2026-06-29T01:28:52-04:00` exited 0 with `ok: 1`.
- [x] Claim And Incorporation Ledger callback update: during implementation, update every ledger row's verification state to `applied`, `already-present`, `excluded-with-reason`, or `blocked` with proof. Proof: C01-C18 and C20 are `applied`; C19 is `excluded-with-reason`; no rows remain `proposed` or `blocked`.
- [x] Read/check-only pages checked during implementation for contradictions: non-deleting destructor, scalar deleting destructor, StartIdleTimer, AttachedObjectPane vtable neighbor, BowGaugeObjectPane vtable neighbor. Edit only if a direct contradiction is found. Proof: checked `by-memory/0x00538880-0x0053889f.EffectObjectPaneNonDeletingDestructor.md`, `by-memory/0x0053d100-0x0053d197.EffectObjectPaneScalarDeletingDestructor.md`, `by-memory/0x005388a0-0x005388b4.EffectObjectPaneStartIdleTimer.md`, `by-memory/0x00620544-0x006205f8.AttachedObjectPaneVtableData.md`, and `by-memory/0x006206ac-0x00620734.BowGaugeObjectPaneVtableData.md`; no contradiction found, so no edits or validators were needed for those read-only pages.
- [x] Scoped validators run from `source-3/project-documentation` for every edited by-* doc with `--apply --queue-timeout 240 --wait-generated`; record command, `command_id`, `command_timestamp`, exit code, `ok` count, and generated-refresh state. Proof: commands run from `E:\NTK\GhidraBridge\source-3\project-documentation`: `python .\tools\validator.py --mode file --file by-memory\0x006205f8-0x006206ac.EffectObjectPaneVtableData.md --apply --queue-timeout 240 --wait-generated` command `000000000257`, `2026-06-29T01:20:22-04:00`, exit 0, `ok: 1`, `generated_refresh: completed`; `by-class\EffectObjectPane.md` command `000000000258`, `2026-06-29T01:20:40-04:00`, exit 0, `ok: 1`, completed; `by-file\Effects.md` command `000000000259`, `2026-06-29T01:20:55-04:00`, exit 0, `ok: 1`, completed; `by-memory\0x00620284-0x00620c74.ObjectPaneReadOnlyData.md` command `000000000260`, `2026-06-29T01:21:09-04:00`, exit 0, `ok: 1`, completed; `by-memory\0x005387b0-0x00538baa.EffectObjectPaneCore.md` command `000000000261`, `2026-06-29T01:21:24-04:00`, exit 0, `ok: 1`, completed; post-verification correction validator for `by-memory\0x005387b0-0x00538baa.EffectObjectPaneCore.md` command `000000000267`, `2026-06-29T01:28:52-04:00`, exit 0, `ok: 1`, completed. Known diagnostics were existing unrelated stale registry/missing-file or missing-reference rows: target command missing UID000382; class command missing UID000382 and old UID00023H target; Effects command missing UID0003HA/0003HC/0003HB/0003HD and old UID0001GG target; core commands old UID00023H target. Validators also performed validator-owned generated refreshes/backups/projected stats/autogen registry rebuilds; no manual tool-state edits were made.
- [x] Generated proof checked read-only: UID000351 no longer appears as `Empty Emitter Marker` in `auto-generated/NexusTK/render/Effects.cpp`; generated file header is equal/newer than the target validator command metadata. Proof: post-correction generated header is `validator-command-id: 000000000267`, `validator-refreshed-at: 2026-06-29T01:28:52-04:00`, newer than target validator `000000000257`; UID000351 lines show `Completion:88 | Confidence:92` and the covered-by marker, with no UID000351 Empty Emitter Marker. Other empty emitters in `Effects.cpp` are out of scope.
- [x] Lease proof recorded during callback: leases acquired only immediately before editing accepted by-* files and released immediately after the edit/validator batch. No reservation leases. Proof: B015 leased exactly the five edited by-* files before patching and released them after validators; for the post-verification correction, B015 leased only `by-memory/0x005387b0-0x00538baa.EffectObjectPaneCore.md` and released it after validator `000000000267`; current lease report then showed `No active leases.`
- [x] No manual edits to generated reports, generated C++ files, project-level generated files, manual `-coverage-report.md` files, validator/tool state, executed reports, or IDA DB. Proof: manual edits were limited to target/support by-* docs and this B015 report; generated files and validator state were changed only by scoped validator commands; no `execute_report`, IDA write, generated-file manual edit, coverage-report edit, lock-file edit, or executed-report edit was performed.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B015","command_id":"000000004165","destination_path":"executed-b-agent-research/B015/000351-EffectObjectPaneVtableData-empty-emitter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B015/research/000351-EffectObjectPaneVtableData-empty-emitter-source-quality.md","timestamp":"2026-06-29T01:36:01","uid":"000351"} -->
<!-- {"agent":"B015","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000351-EffectObjectPaneVtableData-empty-emitter-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B015/000351-EffectObjectPaneVtableData-empty-emitter-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000351"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
