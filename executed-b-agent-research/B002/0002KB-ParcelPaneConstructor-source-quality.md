** TARGET-REPORT-UID:0002KB **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B-Agent Research Report: UID 0002KB ParcelPaneConstructor

Target: [UID:0002KB] `by-memory/0x00546290-0x00546436.ParcelPaneConstructor.md`  
Report path: `tools/leaser/Agents/Agent-B002/research/0002KB-ParcelPaneConstructor-source-quality.md`  
Agent: B002  
Mode: report-only research first  
Date: 2026-06-25

## Assignment Result

`ParcelPane::ParcelPane` is first-draft C++ ready. The old target blocker "final field/API names remain provisional" is now stale after the accepted ParcelPane/FlyingParcelPane support passes and current MCP recheck. The implementation callback should populate the target formal C++ block, raise the target from `86/88` to `91/92`, preserve `CANONICAL_OWNER:0000A6`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000A6`, and keep `EMITTER_POSITION_OPTIONAL:` blank.

No by-* docs, generated files, coverage reports, validator state/cache, or IDA DB files were edited during this report-only pass. No leases were taken. IDA MCP was available and used.

## Sources Checked

- Target page: `by-memory/0x00546290-0x00546436.ParcelPaneConstructor.md`.
- Direct support: `by-class/ParcelPane.md`, `by-file/ParcelPane.md`, `by-type/by-struct/ParcelNotificationPaneLayouts.md`, `by-type/by-vtable/ParcelNotificationVtableFamily.md`, `by-memory/0x00621bb0-0x00621d50.ParcelNotificationVtableData.md`.
- Sibling behavior pages: `ParcelPaneSetParcelSlotData`, `ParcelPaneProcessSlotAnimations`, `ParcelPaneUpdateAnimationCounter`, `ParcelPaneGetButtonFrameIndex`, `ParcelPaneOnPaint`, `FlyingParcelPaneConstructor`, and `FlyingParcelPaneAnimateStep`.
- Dependency pages: `PaneCore`, `PaneLayout`, `TimerHandlerScheduleRemoveWrappers`, `MainUiLayerSlots`, `g_pBackPane`, `g_pParcelPane`, and exact `g_pParcelPane` memory storage.
- Existing reports checked for ParcelPane constructor context: B001 ParcelPane timer/frame helper report, B006 ClearParcelPaneSingleton report, B007 FlyingParcelPaneConstructor report, B001 FlyingParcelPaneAnimateStep report, and B003/B001 accepted sibling implementation material.
- Generated state was read only. `auto-generated/-ag-research-tracker.md` and `auto-generated/-ag-coverage-report-by-memory.md` still list UID 0002KB as stale `76/84` / `emits_code:false`; do not hand-edit them. Refresh by validator only after source docs are edited.

## MCP Availability

IDA MCP was responsive.

- Read-only listener check before MCP work: `Test-NetConnection 127.0.0.1 -Port 13337` returned `TcpTestSucceeded True`.
- MCP endpoint: `http://127.0.0.1:13337/mcp`.
- MCP server: `ida-pro-mcp 1.0.0`.
- Active database: `80de0a67`.
- IDB: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- MCP `server_health` request `201`: `status:"ok"`, module `NexusTK.exe`, input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`.

## Current Target State

The target page currently says:

- `COMPLETION:86`
- `CONFIDENCE:88`
- `CANONICAL_OWNER:0000A6`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000A6`
- blank formal C++
- item summary: constructor installs vtable views, initializes parcel slot/rect/timer state, stores `g_pParcelPane`, and still has provisional field/API names.

The owner/emitter route is still correct, but the score and blank-C++ rationale are outdated. The class page is now `88/90`, the file page is `88/88`, the layout page records accepted ParcelPane fields, and current first-draft sibling pages already use `SetParcelSlotData`, `m_timerHandler.ScheduleTimer`, `Pane::InvalidateRect`, `Pane::RemoveFromLayer`, `g_pParcelPane`, and accepted button/slot fields.

## IDA MCP Evidence

Current live MCP recheck:

- `lookup_funcs` request `202` reports `sub_546290` at `0x00546290`, size `0x1a6`; no function at `0x00546436`; successor `sub_546440` begins at `0x00546440`.
- `analyze_function` request `203` reports prototype artifact `int __thiscall(int this)`, size `422`, no direct callers, callees `sub_544460`, `sub_4B7C50`, `sub_544C50`, `sub_544D30`, `sub_5975E0`, and security-cookie support.
- `decompile` request `204` shows:
  - base `Pane` construction via `sub_544460(this, 1)`;
  - singleton publish/guard-clear writes to `unk_69BA28` at `0x005462e1` and `0x005462e8`;
  - `ParcelPane` vtable stores at `0x00621c3c`, `0x00621c90`, and `0x00621cc0`;
  - stable state initialization at `+0xf8..+0x121`;
  - left/right button rectangles `(0,0,30,25)` and `(31,0,62,25)`;
  - an inlined zero-argument `SetParcelSlotData`-shape reset/placement sequence using `Pane::RemoveFromLayer`, `Pane::IsAttachedToLayer`, `AddToLayer`, and `Pane::InvalidateRect`;
  - `Pane::SetPaneOrder` / dispatcher ordering helper `sub_544D30(this, 0, g_pBackPane)`;
  - `TimerHandler::ScheduleTimer` on `this + 0xa4` with delay `100`.
- `disasm` request `205` reports 130 instructions including constructor EH fragments at `0x00605c27`, `0x00605c2f`, and `0x00605c3d`. The EH route to `sub_546E80` is compiler cleanup, not source-authored helper code.
- `get_bytes` request `207` confirms `0x00546436-0x00546440` is six `0xcc` bytes before the destructor prologue.
- `xrefs_to` request `208` reports:
  - no direct xrefs to `0x00546290`;
  - vtable-store xrefs for `0x00621c3c`, `0x00621c90`, and `0x00621cc0` from `ParcelIconPane` constructor, this constructor, `ParcelPane` destructor, and scalar deleting destructor;
  - nine xrefs to `0x0069ba28`, including this constructor writes at `0x005462e1` and `0x005462e8`.

Helper checks:

- `decompile`/`disasm` requests `300` and `301`: `0x00544c50` is `Pane::IsAttachedToLayer`, reading cached `Layer*` at `+0xa8`.
- `decompile`/`disasm` requests `302` and `303`: `0x00544d30` passes `this + 0xa0` plus two optional pane/event-handler views into `EventDispatcher`; support docs call this `Pane::SetPaneOrder` / dispatcher order helper.
- `decompile`/`disasm` requests `304` and `305`: `0x00544800` is `Pane::InvalidateRect`, the primary vtable slot `+0x20`.
- `decompile`/`disasm` requests `306` and `307`: `0x00544ce0` is `Pane::RemoveFromLayer`, the primary vtable slot `+0x38`.
- `decompile` request `308`: `0x00544460` is `Pane::Pane(unsigned char mode)` direction; it installs the base `Pane` views and initializes `+0xa0/+0xa4/+0xa8/+0xac/+0xb4/+0xb5`.
- `decompile`/`disasm` request `401`/`402`: `0x005464b0` is `ParcelPane::SetParcelSlotData(total,left,right)` and its body matches the constructor's inlined zero-state reset/placement sequence.
- `decompile` request `403`: `0x00544c70` is `Pane::AddToLayer`.
- `decompile` request `212`: `0x005975e0` is `TimerHandler::ScheduleTimer`, forwarding through `g_pTimerMgr`.

## Field And API Resolution

The target can now use accepted source-facing names instead of provisional offset/API labels.

| Raw evidence | Source-facing decision |
| --- | --- |
| `sub_544460(this, 1)` | `Pane(1)` / `Pane(PaneMode)` base construction. The final enum constant name remains support-level, but the constructor argument is stable. |
| `unk_69BA28 = this/0` | `g_pParcelPane = this` with compiler EH cleanup regenerating the fallback clear. Do not hand-author `ClearParcelPaneSingleton` in this constructor body. |
| vtable stores to `0x00621c3c`, `0x00621c90`, `0x00621cc0` | Compiler output from declaring `ParcelPane` with primary, EventHandler, and TimerHandler views; do not emit as source statements. |
| `+0xf8` | `m_totalParcelCount`. |
| `+0xf9` / `+0xfa` | `m_leftParcelCount` / `m_rightParcelCount`. |
| `+0xfb` | `m_rightSlotActionEnabled`, initialized true. |
| `+0xfc` / `+0xfd` | `m_leftButtonState` / `m_rightButtonState`, final stable constructor state idle after the inlined reset path. The transient `0xfb` byte at `+0xfc` is overwritten before attach/invalidate and should not become a separate source state. |
| `+0xfe` / `+0xff` | `m_leftAnimationFrame = -3`, `m_rightAnimationFrame = 0`. |
| `+0x100` / `+0x110` | `m_leftButtonRect` / `m_rightButtonRect`. |
| `+0x120` / `+0x121` | `m_leftSlotAcknowledged` / `m_rightSlotAcknowledged`, initialized false. |
| `sub_4B7C50(rect, ...)` | RECT initialization. First-draft source can use `SetRect` for the two button rectangles. |
| inlined call shape matching `0x005464b0` with all zero arguments | `SetParcelSlotData(0, 0, 0)`. The binary duplicates the helper body, but source-level constructor intent is the same reset/place/invalidate operation already named for UID 0002KC and used by accepted UID 0002KK C++. |
| `sub_544D30(this, 0, dword_67A740)` | `SetPaneOrder(nullptr, g_pBackPane)` / dispatcher order registration. `dword_67A740` is documented `g_pBackPane`; it is a dependency, not ParcelPane-owned storage. |
| `sub_5975E0(this + 0xa4, 0, 100, 0, 0)` | `m_timerHandler.ScheduleTimer(0, 100, 0, 0)`. UID 0002KF's recurring timer callback uses 200 ms; this constructor schedules the initial tick at 100 ms. |
| `unk_69B368` passed to `AddToLayer` inside reset/place code | `MainUiLayerSlots` slot `dword_69B368`. This remains a support dependency hidden behind `SetParcelSlotData` in the recommended formal body. Do not rename it as a ParcelPane field/global. |

## Negative Evidence And Rejected Alternatives

- No direct xrefs to `0x00546290` are present. This is not an ownership blocker; the same no-direct-xref condition exists for other constructors, and ownership is proven by vtable stores, singleton writes, layout, destructor counterparts, and the parcel notification source island.
- The constructor should not be re-owned by `Pane`, `TimerHandler`, `MainUiGraph`, `BackPane`, `MainUiLayerSlots`, or `g_pParcelPane`. Those are dependencies or storage anchors. The direct method owner remains `ParcelPane`.
- The target should not emit vtable stores, security cookie code, `this == -248` guard artifacts, or EH cleanup fragments. The `0x00605c2f -> sub_546E80` route is compiler unwind cleanup; B006 already documents it as non-emitting constructor cleanup.
- Do not split `0x00546290-0x00546436`. `lookup_funcs` and boundary bytes confirm the half-open constructor body, with `0xcc` padding before the destructor at `0x00546440`.
- Do not surface the transient `+0xfc = 0xfb` store as a stable field or enum value. It is overwritten by the constructor's inlined zero-slot reset before any attach/invalidate/timer-visible behavior.
- Do not keep generated `sub_`, `unk_`, or `dword_` labels in target prose or C++.

## Ownership And Score Recommendation

Recommended target metadata:

- `COMPLETION:91`
- `CONFIDENCE:92`
- `CANONICAL_OWNER:0000A6`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000A6`
- `EMITTER_POSITION_OPTIONAL:` unchanged blank

Rationale:

- Completion rises because the target now has current MCP evidence, exact boundary proof, accepted field names, accepted dependency/API names, source-shaped lifecycle handling, singleton publication, inlined reset/placement explanation, timer schedule semantics, and first-draft formal C++.
- Confidence rises because current MCP directly confirms the body and dependencies, support pages now agree on `ParcelButtonState`, left/right count/state/frame/ack fields, `SetParcelSlotData`, `TimerHandler::ScheduleTimer`, `Pane` layer helpers, `g_pBackPane`, `MainUiLayerSlots`, and `g_pParcelPane`. The remaining caveats are original spelling of `SetPaneOrder` and broader support declaration polish, not target source readiness.

Recommended target Item Summary:

`Constructs ParcelPane, publishes g_pParcelPane, initializes parcel slot/button state and button rects, performs the initial zero-slot placement/reset, registers pane order, and starts the 100 ms timer.`

## Recommended Formal C++

Exact formal block content for `by-memory/0x00546290-0x00546436.ParcelPaneConstructor.md`:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
ParcelPane::ParcelPane()
    : Pane(1),
      m_totalParcelCount(0),
      m_leftParcelCount(0),
      m_rightParcelCount(0),
      m_rightSlotActionEnabled(true),
      m_leftButtonState(kParcelButtonIdle),
      m_rightButtonState(kParcelButtonIdle),
      m_leftAnimationFrame(-3),
      m_rightAnimationFrame(0),
      m_leftSlotAcknowledged(false),
      m_rightSlotAcknowledged(false)
{
    g_pParcelPane = this;

    SetRect(&m_leftButtonRect, 0, 0, 30, 25);
    SetRect(&m_rightButtonRect, 31, 0, 62, 25);

    SetParcelSlotData(0, 0, 0);
    SetPaneOrder(nullptr, g_pBackPane);
    m_timerHandler.ScheduleTimer(0, 100, 0, 0);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

The body intentionally uses source-level calls rather than inlining `SetParcelSlotData`'s repeated placement/reset sequence. UID 0002KC remains blank pending its own parameter-name polish, but accepted UID 0002KK already calls `g_pParcelPane->SetParcelSlotData(...)`; using the same source-facing method here is consistent and prevents duplicating helper internals in the constructor. `SetPaneOrder` remains the best current source-facing name from Pane support docs; if a later Pane/EventDispatcher audit renames it, update both the support declarations and this constructor consistently.

## Support Sync Needed If Accepted

Target page:

- Update metadata and Item Summary as recommended.
- Populate the formal C++ block above.
- Replace the stale "Do not emit final C++ yet" rationale with the resolved field/API/source-shape analysis.
- Add current MCP evidence with request ids `201` through `212`, `300` through `309`, and `401` through `404` as relevant.
- Preserve owner/emitter and range.

`by-class/ParcelPane.md`:

- Update the constructor method row to say UID 0002KB now emits first-draft `ParcelPane::ParcelPane()` C++.
- Add an evidence note for current MCP session `80de0a67`: exact range, no direct callers, vtable store xrefs, `g_pParcelPane`, accepted fields, inlined `SetParcelSlotData(0,0,0)`, `SetPaneOrder(nullptr, g_pBackPane)`, and initial 100 ms timer.
- Update assignment gate/score rationale/open questions so the constructor is no longer blocked by field/helper/API names. Keep broader timer/helper declaration caveats for sibling pages.

`by-file/ParcelPane.md`:

- Record that UID 0002KB now has first-draft formal C++ through the `ParcelPane.cpp` source route.
- Keep `ParcelPane.cpp` as the source-family owner for `ParcelIconPane`, `ParcelPane`, `FlyingParcelPane`, `g_pParcelPane`, and parcel resources.
- Preserve remaining file-level caveats for private helper declarations, timer/input helper spellings, raw FlyingParcelPane cleanup/start, and generated-output omissions.

`by-type/by-struct/ParcelNotificationPaneLayouts.md`:

- Update the ParcelPane constructor evidence to note first-draft C++ readiness and stable field initialization, especially `m_rightSlotActionEnabled`, `m_leftAnimationFrame = -3`, and the transient overwritten `+0xfc = 0xfb` store not being a stable source field.
- No score change is required unless supervisor wants support synchronization to mention the accepted constructor explicitly.

Optional support note:

- `by-global/g_pParcelPane.md` and `by-memory/0x0069ba28-0x0069ba2c.g_pParcelPane.md` already contain the constructor publish/fallback-clear evidence. The exact memory child has stale Item Summary wording saying `ff ff ff ff` / `0xffffffff` even though the body records `00 00 00 00`; this task does not need to edit that page unless the supervisor includes it in the implementation callback.

## Validation Plan If Accepted

Run scoped validators from `source-3/project-documentation` after edits. Do not manually edit generated outputs or coverage reports.

Recommended commands:

> Executable block R001 was removed from this report and preserved verbatim in [0002KB-ParcelPaneConstructor-source-quality-removed.md](0002KB-ParcelPaneConstructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the generated coverage row remains stale after target validation, supervisor should refresh generated/project-level state through the standard validator/autogen path only. Do not hand-edit `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, `auto-generated/NexusTK/ui/panels/ParcelPane.cpp`, or any `-coverage-report.md`.

## Implementation Tracking Checklist

- [x] Lease only immediate edit files before implementation: target `by-memory/0x00546290-0x00546436.ParcelPaneConstructor.md`, `by-class/ParcelPane.md`, `by-file/ParcelPane.md`, and `by-type/by-struct/ParcelNotificationPaneLayouts.md` if support sync is accepted. Proof: `python .\tools\leaser\leaser.py B002 lease ...` returned `Success` for those four by-* files; no report/generator/state files were leased.
- [x] Update UID 0002KB target metadata to `COMPLETION:91`, `CONFIDENCE:92`, preserve `CANONICAL_OWNER:0000A6`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000A6`, and blank `EMITTER_POSITION_OPTIONAL`. Proof: target header now has those exact values; validator command `000000001610` recorded `completion_update 0002KB 91`, `confidence_update 0002KB 92`, and `canonical_owner_update 0002KB 0000A6`.
- [x] Update UID 0002KB Item Summary to the recommended constructor behavior summary. Proof: target Item Summary now reads "Constructs ParcelPane, publishes g_pParcelPane, initializes parcel slot/button state and button rects, performs the initial zero-slot placement/reset, registers pane order, and starts the 100 ms timer."
- [x] Insert the exact formal C++ block from this report into UID 0002KB. Proof: target formal block now contains `ParcelPane::ParcelPane()` with `Pane(1)`, accepted member initializers, `g_pParcelPane = this`, both `SetRect` calls, `SetParcelSlotData(0, 0, 0)`, `SetPaneOrder(nullptr, g_pBackPane)`, and `m_timerHandler.ScheduleTimer(0, 100, 0, 0)`.
- [x] Replace stale target no-code/provisional-name prose with resolved analysis for `g_pParcelPane`, accepted ParcelPane fields, button rectangles, `SetParcelSlotData(0,0,0)`, `SetPaneOrder(nullptr, g_pBackPane)`, `MainUiLayerSlots` dependency, and `m_timerHandler.ScheduleTimer(0,100,0,0)`. Proof: target `Behavior`, `IDA MCP Evidence`, `Reconstruction Notes`, `Score Rationale`, `Cross-References`, and `Changes` sections now carry those accepted facts and source-shape decisions.
- [x] Preserve negative evidence: no direct callers, no split, no manual vtable/security/EH cleanup code, `ClearParcelPaneSingleton` remains non-emitting compiler cleanup, dependency owners rejected. Proof: target evidence/notes document no direct callers, single half-open range `0x00546290-0x00546436`, compiler-only vtable/security/EH handling, non-emitting `ClearParcelPaneSingleton`, and rejected dependency owners.
- [x] Sync `by-class/ParcelPane.md` constructor row/evidence/gate/changes to show UID 0002KB is first-draft populated. Proof: class method row, B002 evidence note, assignment gate, score rationale/open questions, and `Changes` section now reference UID 0002KB first-draft `ParcelPane::ParcelPane()` with exact range, no callers, vtable/singleton evidence, accepted fields, reset/order/timer behavior, and compiler-output exclusions.
- [x] Sync `by-file/ParcelPane.md` file-role/migration/changes to show UID 0002KB now emits through `ParcelPane.cpp`. Proof: file role paragraph, evidence note, migration note, and `Changes` section now record UID 0002KB first-draft constructor emission through `ParcelPane.cpp` while preserving source-family ownership and remaining file-level caveats.
- [x] Sync `by-type/by-struct/ParcelNotificationPaneLayouts.md` with constructor initialization detail and transient `+0xfc` overwrite rationale if accepted. Proof: layout introduction, `ParcelPane` field table, 2026-06-25 MCP note, and `Changes` section now record the stable constructor initializers and the transient `+0xfc` overwrite rationale.
- [x] Do not edit `by-global/g_pParcelPane.md` or `by-memory/0x0069ba28-0x0069ba2c.g_pParcelPane.md` unless supervisor explicitly includes the stale memory-child summary cleanup. Proof: no edits were made to either `g_pParcelPane` page; the stale memory-child summary cleanup remains excluded as instructed.
- [x] Run scoped validators with `--apply --wait-generated` for every edited by-* file; report command ids, timestamps, exit codes, `ok:1`, and generated refresh status. Proof: from `source-3/project-documentation`, all exited `0` with `ok:1` and `generated_refresh: completed`: target command `000000001610` at `2026-06-25T14:31:23-04:00`; class command `000000001612` at `2026-06-25T14:31:53-04:00`; file command `000000001614` at `2026-06-25T14:32:08-04:00`; layout command `000000001615` at `2026-06-25T14:32:30-04:00`. Validator-owned side effects included generated metadata/C++ refreshes, projected stats updates, research tracker/autogen registry updates, backups under `tools/validator_autogen_backup/`, and repeated pre-existing stale registry/missing-target diagnostics for old UID paths such as `0001EH` and `0001EN`; no validator state or generated files were edited manually.
- [x] Confirm generated `auto-generated/NexusTK/ui/panels/ParcelPane.cpp` contains UID 0002KB first-draft constructor only after validator refresh; do not edit generated C++ manually. Proof: generated file header currently shows `validator-command-id: 000000001617` and `validator-refreshed-at: 2026-06-25T14:33:09-04:00`, which is newer than B002's last scoped validator command `000000001615`; the file contains `// UID:0002KB ... Completion:91 | Confidence:92`, `ParcelPane::ParcelPane()`, `SetParcelSlotData(0, 0, 0)`, and `m_timerHandler.ScheduleTimer(0, 100, 0, 0)`.
- [x] Release all leases immediately after validators finish. Proof: `python .\tools\leaser\leaser.py B002 unlease ...` after validators reported `Rejected[No active lease]` for each of the four paths because the short leases had already expired; the current lease report was then checked and contains no B002 entries.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0002KB-ParcelPaneConstructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0002KB-ParcelPaneConstructor-source-quality.md","timestamp":"2026-06-25T14:41:29","uid":"0002KB"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002KB-ParcelPaneConstructor-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/0002KB-ParcelPaneConstructor-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002KB"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
