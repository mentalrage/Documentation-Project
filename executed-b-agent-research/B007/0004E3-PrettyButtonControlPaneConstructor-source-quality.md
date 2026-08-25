** TARGET-REPORT-UID:0004E3 **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **

# UID0004E3 PrettyButtonControlPane Constructor Source-Quality Report

## Finalized Report / Current Recommendation

Promote [UID:0004E3] `by-memory/0x0054b5e0-0x0054b6a4.PrettyButtonControlPaneConstructor.md` from documented-but-non-emitting constructor evidence to an emitting `PrettyButtonControlPane` constructor child through [UID:0000AR][PrettyButtonControlPane](../../../../../by-class/PrettyButtonControlPane.md).

The old target blocker said formal C++ should remain blank until class layout, resource names, and callback type were accepted. That blocker is now mostly superseded by accepted sibling work:

- UID0004E5 accepts the selected-state byte as `m_selected` at `+0x118`.
- UID0004E6 accepts the owned callback slot as `FunctionObject0 *m_callback` at `+0x124`.
- UID0004E7 accepts the visual-state/timer flag at `+0x119` as `m_visualStateFrameActive`.
- UID0004E8 accepts the constructor-fed paint fields: `m_normalFrameId` `+0x10c`, `m_pressedFrameId` `+0x110`, `m_hoverFrameId` `+0x114`, `m_epfResourceName` `+0x11c`, `m_paletteResourceName` `+0x120`, inherited `m_enabled` at `+0x101`, bounds at `+0x44`, draw mode at `+0x70`, and the EPF/PAL frame-rendering role.

Recommended implementation outcome after supervisor Gate 1: keep owner `0000AR`, keep `RECONSTRUCTABLE:TRUE`, set `EMITTER_UIDS:0000AR`, raise target score from `84/89` to `89/91`, and mark the constructor source-ready using the accepted field names above. The proposed formal C++ body is supplied under `## First-Draft C++ Recommendation` for supervisor validation before any callback edits.

## Supporting Research

The live MCP pass was redone after the supervisor restored MCP. The active IDB session was `9fb70afc` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; `server_health` returned `status:"ok"`, `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_ready:true`.

Live MCP confirms `0x0054b5e0` is `sub_54B5E0`, size `0xc4`, with exact modeled end `0x0054b6a4`. `0x0054b6a4` and `0x0054b6b0` are not functions. Boundary bytes show `0x0054b6a0-0x0054b6a3` as `pop ebp; retn 1Ch`, followed by `0xcc` padding from `0x0054b6a4`; `0x0054b5d5-0x0054b5e0` is also `0xcc` padding.

The constructor behavior is source-authored class construction:

- calls base button-control constructor `sub_494EB0(this, rect)` at `0x54b60c`;
- writes frame ids to `this+0x10c`, `this+0x110`, and `this+0x114`;
- installs three `PrettyButtonControlPane` vtable views at `this+0`, `this+0xa0`, and `this+0xa4`;
- clears the two bytes at `this+0x118` and `this+0x119` together with `mov word ptr [esi+118h], 0`;
- constructs two string/object fields at `this+0x11c` and `this+0x120` with `sub_582560`;
- stores the constructor byte argument at `this+0xff`;
- clears `this+0x124` callback pointer and `this+0x100`.

Callers allocate `0x128` bytes before calling this constructor, pass a rectangle object, resource string pairs such as `DIREC.EPD` / palette data, `NNATION.EPF` / `NNATION.PAL`, and frame-number triples such as `0,1,2`, `3,4,5`, `8,0,12`, `11,3,15`, `0,4,2`, and `1,5,3`. This supports source constructor parameters such as rectangle, EPF resource name, palette resource name, normal/pressed/hover frame ids, and a byte flag, not raw decompiler temporaries.

## Target

- UID: `0004E3`
- Target path: `by-memory/0x0054b5e0-0x0054b6a4.PrettyButtonControlPaneConstructor.md`
- Address range: `0x0054b5e0-0x0054b6a4`
- Current IDA name: `sub_54B5E0`
- Source-facing role: `PrettyButtonControlPane::PrettyButtonControlPane(...)`
- Current direct owner: [UID:0000AR][PrettyButtonControlPane](../../../../../by-class/PrettyButtonControlPane.md)
- Source file route: [UID:0000MP][PrettyButtonControlPane](../../../../../by-file/PrettyButtonControlPane.md), `NexusTK/ui/controls/PrettyButtonControlPane.cpp`
- Parent split/index: [UID:0001F9][0x0054b5e0-0x0054bcbd.PrettyButtonControls](../../../../../by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md)

## Current Target State

Current target metadata:

- `COMPLETION:84`
- `CONFIDENCE:89`
- `CANONICAL_OWNER:0000AR`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:` blank
- formal `RECONSTRUCTION_CPP CODE` blank

The target already records the exact child split, owner, source file, 30 constructor xrefs, base `ButtonControlPane` construction, three-view vtable setup, frame/resource/string/callback fields, and padding at `0x0054b6a4`. Its stale blocker is now the blank emitter/C++ policy: it says emitter route is intentionally blank until class layout, resource names, and callback type are source-grade. Subsequent accepted sibling reports resolved enough of those class-layout and callback names for this constructor to become first-draft C++ ready.

## Heuristic / Inference Reanalysis And Validation

The constructor is not merely a raw setup function. It initializes exactly the fields later consumed by accepted PrettyButtonControlPane methods:

- `+0x10c/+0x110/+0x114`: accepted as `m_normalFrameId`, `m_pressedFrameId`, and `m_hoverFrameId` by UID0004E8. Constructor caller frame triples match paint-time frame selection.
- `+0x118`: accepted as `m_selected` by UID0004E5. The constructor clears it before any caller sets a default selected option through `SetSelected(true)`.
- `+0x119`: accepted as `m_visualStateFrameActive` by UID0004E7 and UID0004E8. The constructor clears it together with `m_selected`.
- `+0x11c/+0x120`: accepted as EPF/PAL string fields by UID0004E8. Callers pass EPF/PAL name pairs or shared string pointers, and OnPaint consumes these resource strings.
- `+0x124`: accepted as owned `FunctionObject0 *m_callback` by UID0004E6. The constructor nulls it; `SetCallback` replaces it; destructor/click paths consume it.
- `+0xff` and `+0x100`: remain less semantically named. The byte at `+0xff` is constructor-provided and should be documented as a constructor mode/flag byte until a better accepted source name exists. The byte at `+0x100` is cleared here and should remain a lower-confidence class state flag until sibling behavior proves a name.

The source-shape inference is strong enough for emitter routing because the direct class owner, file route, field layout, argument roles, and boundaries are all current and mutually consistent. The remaining low-level uncertainty is exact original parameter/member spelling for the two less-understood bytes, not behavior, ownership, range, or source placement.

## Evidence Standards Used

Evidence ranking used in this report:

- Live IDA MCP facts are treated as authority for function boundary, xrefs, instructions, decompilation, callees, vtable references, and padding bytes.
- Current by-* docs are treated as project-accepted documentation state, especially already executed sibling reports incorporated into target/class/file docs.
- Executed B-agent reports are used as validated lead/support evidence after search-gating.
- Caller decompilation is used to infer argument roles, not to claim original source names.
- Generated/decompiler names such as `sub_54B5E0`, `a5`, `Src`, `off_61FF00`, and `arg_18` are not treated as source-quality names.

## Evidence Checked

Read project/workflow evidence:

- `tools/leaser/Agents/Agent-B007/goal.md`
- `ntk-b-agent-workflow` skill and `references/b-agent-research-and-implementation-workflow.md`
- `references/score-blocker-audit-standard.md`
- `by-structure.md` sections on IDA MCP output discipline, canonical homes, owner/emitter separation, and C++ gate rules
- target doc `by-memory/0x0054b5e0-0x0054b6a4.PrettyButtonControlPaneConstructor.md`
- support docs `by-class/PrettyButtonControlPane.md`, `by-file/PrettyButtonControlPane.md`, and `by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md`

Searched active/executed/archived B-agent materials with:

- `0004E3|0x0054b5e0|0054b5e0|PrettyButtonControlPaneConstructor|PrettyButtonControlPane Constructor|sub_54B5E0|PrettyButtonControlPane\(`
- `PrettyButtonControlPane|PrettyButtonControls|FunctionObject0|m_callback|m_normalFrameId|m_epfResourceName|m_paletteResourceName`

Relevant report matches:

- `executed-b-agent-research/B011/0001F9-PrettyButtonControls-source-quality.md`: parent split report; created UID0004E3-UID0004EM and recorded UID0004E3 as class1 constructor owner/emitter candidate under UID0000AR.
- `executed-b-agent-research/B014/0004E5-PrettyButtonControlPaneStateByteVirtualForwarder-source-quality.md`: accepted `SetSelected(bool selected)` and `m_selected` at `+0x118`.
- `executed-b-agent-research/B015/0004E6-PrettyButtonControlPaneSetCallback-source-quality.md`: accepted `FunctionObject0 *m_callback` at `+0x124`.
- `executed-b-agent-research/B001/0004E7-PrettyButtonControlPaneSetVisualState-source-quality.md`: accepted visual-state/timer flag source shape at `+0x119`.
- `executed-b-agent-research/B002/0004E8-PrettyButtonControlPaneOnPaint-source-quality.md`: accepted paint fields fed by this constructor.
- `executed-b-agent-research/B002/0001F6-PowerDialogPane-empty-emitter-source-quality.md`: only treats `0x0054b5e0` as the successor boundary after PowerDialogPane; not a UID0004E3 ownership report.

Live MCP evidence from session `9fb70afc`:

- `idb_list`: active worker session `9fb70afc`, path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, active and not analyzing.
- `server_health`: `status:"ok"`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`.
- `lookup_funcs` for `0x0054b5e0`, `0x0054b6a4`, `0x0054b6b0`: `0x0054b5e0` is `sub_54B5E0` size `0xc4`; the two boundary/next-span addresses are not functions.
- `analyze_function 0x0054b5e0`: prototype-like decompiler shape, size `196`, callees `sub_494EB0` and `sub_582560`, callers `sub_52A540`, `sub_52C360`, `sub_52DD30`, and 30 direct code xrefs.
- `disasm 0x0054b5e0 max_instructions=80 include_total=true`: 59 instructions including SEH/unwind landing pads; constructor body writes the field offsets and vtable refs listed above.
- `xrefs_to` for `0x0054b5e0`, `0x006222d8`, `0x00622340`, and `0x00622370`: 30 constructor calls; each vtable view has constructor, destructor-body, and scalar-deleting-destructor refs.
- `callees 0x0054b5e0`: only `sub_494EB0` and `sub_582560`.
- `get_bytes` for `0x0054b5d5`, `0x0054b6a4`, and `0x0054b6a0`: lower and upper padding are `0xcc`; end sequence is `5d c2 1c 00` followed by padding.
- caller decompilation snippets for `0x0052a540`, `0x0052c360`, and `0x0052dd30`: callers allocate `0x128` bytes and pass rectangles, resource strings, frame triples, and byte flags into `sub_54B5E0`.
- Repair-pass MCP recheck after Gate 1 return: `server_health` on session `9fb70afc` still returned `status:"ok"` with analysis and Hex-Rays ready; fresh `decompile 0x0054b5e0` and bounded `disasm 0x0054b5e0 max_instructions=50 include_total=true` reconfirmed the constructor argument order and field stores used by the proposed first-draft C++ body.

## Claim And Incorporation Ledger

| Claim | Destination | Action | Verification state |
| --- | --- | --- | --- |
| UID0004E3 is an exact `0x0054b5e0-0x0054b6a4` constructor body, not a mixed parent or padding range. | Target Status/Evidence and parent split row | incorporate | applied: target Status/Evidence updated; parent split row synchronized |
| Direct owner remains UID0000AR `PrettyButtonControlPane`; file route remains UID0000MP. | Target metadata and class/file docs | already-present plus refresh | applied: owner/file route preserved and support docs synchronized |
| The old no-emitter blocker is superseded by accepted sibling field/callback reports. | Target C++ Policy, Score Rationale, class/file child inventory | incorporate | applied: target policy replaced; class/file rows now source-ready |
| Constructor initializes accepted fields `m_normalFrameId`, `m_pressedFrameId`, `m_hoverFrameId`, `m_selected`, `m_visualStateFrameActive`, `m_epfResourceName`, `m_paletteResourceName`, and `m_callback`. | Target Evidence / C++ Policy; class Method Notes optional refresh | incorporate | applied: target evidence/C++ and class/file/parent support docs record the accepted field mapping |
| `+0xff` and `+0x100` should be documented conservatively as lower-confidence state/flag bytes, not overnamed. | Target Evidence / Open Questions | incorporate | applied: target and support docs preserve `m_constructorFlag` / `m_reservedState` caveats |
| UID0004E3 should set `EMITTER_UIDS:0000AR` and become first-draft C++ ready during implementation callback. | Target metadata and formal C++ block | incorporate | applied: target emitter set to UID0000AR and formal C++ inserted |
| Formal constructor C++ should use the supplied `PrettyButtonControlPane::PrettyButtonControlPane(...)` body with accepted field names and conservative `m_constructorFlag` / `m_reservedState` names for unresolved bytes. | Target formal `RECONSTRUCTION_CPP CODE` block | incorporate | applied: exact constructor body inserted in target formal block |
| Score should move from `84/89` to `89/91`. | Target metadata / Score Rationale | incorporate | applied: target metadata and score rationale updated |
| Parent UID0001F9 stays non-emitting `RECONSTRUCTABLE:FALSE`; it should not receive aggregate C++. | Parent split/index docs | already-present | applied: parent metadata and aggregate C++ stayed unchanged; only row/evidence text was synchronized |

## Positive Evidence Summary

- Live MCP confirms exact function size `0xc4` and exact padding after `0x0054b6a4`.
- Constructor writes all three PrettyButtonControlPane vtable views; vtable xrefs also include destructor paths, confirming class ownership rather than caller/file-only ownership.
- The constructor initializes the exact fields accepted by sibling emitting reports, so the previous field/resource/callback blocker no longer blocks this target.
- Callers pass resource strings and frame ids rather than the constructor hard-coding one resource, which fits a reusable styled-button constructor.
- The constructor has 30 direct code xrefs from three create-user dialog construction functions, supporting a source-level constructor rather than an unreachable helper.
- Existing owner/file docs already route this class through `NexusTK/ui/controls/PrettyButtonControlPane.cpp`.

## Negative Evidence Summary

- No evidence supports direct ownership by `PrettyButtonControlPane2`; it has its own constructor at UID0004EA.
- No evidence supports making the parent UID0001F9 emit aggregate C++; the parent is already a reviewed split/index.
- No evidence supports direct file-level helper ownership. The target writes class vtables and object fields and is a C++ constructor.
- No exact original source spelling was recovered for the constructor byte at `+0xff` or the cleared byte at `+0x100`; those should not receive overly specific names in the target doc.
- Direct callers are create-user dialogs, but caller locality is consumer evidence only. It does not override generic `ui/controls` source placement because the class/file/vtable/base-constructor evidence points to reusable controls.
- Decompiler names and generic string labels remain tool artifacts; use accepted project names and clearly mark remaining names as inferred.

## Ranked Ownership Analysis

1. [UID:0000AR] `PrettyButtonControlPane` direct class owner: accepted. The constructor writes all three `PrettyButtonControlPane` vtable views, initializes class fields used by accepted sibling methods, and returns `this`.
2. [UID:0000MP] `PrettyButtonControlPane.cpp` file route: accepted as emitter-chain/source-file context, rejected as direct canonical owner because the narrow class owner exists and clears the gate.
3. [UID:0001F9] `PrettyButtonControls` parent split/index: rejected as source owner/emitter for this child. It is a non-emitting physical inventory over two classes and compiler glue.
4. [UID:0000AS] `PrettyButtonControlPane2`: rejected. It has a separate constructor and separate field offsets.
5. Create-user dialog caller owners: rejected as direct owner. They allocate and configure instances, but the constructor belongs to the reusable control class.
6. No-owner/non-emitting: rejected. Current class/vtable/file evidence is strong and source-ready enough for a direct owner/emitter route.

## Source Placement

Keep the target under `PrettyButtonControlPane` and route emitted code through `NexusTK/ui/controls/PrettyButtonControlPane.cpp`. This matches:

- base construction through the generic `ButtonControlPane` path;
- class/file docs already placing both PrettyButton variants under `ui/controls`;
- vtable data pages for PrettyButtonControlPane and PrettyButtonControlPane2;
- sibling accepted method output through UID0000AR;
- caller evidence showing create-user dialogs as consumers rather than owners.

No split, merge, or filename change is needed for this target.

## First-Draft C++ Recommendation

UID0004E3 is eligible for first-draft emitted C++ after callback because:

- `RECONSTRUCTABLE:TRUE`;
- recommended nonblank `EMITTER_UIDS:0000AR`;
- recommended score average is above the strict `>85` gate;
- accepted sibling reports supply the field names needed by this constructor;
- boundaries, callees, owner, file route, and behavior are current MCP-backed.

Do not leave formal C++ blank after callback solely because exact original names for every byte are unavailable. The remaining lower-confidence byte fields are represented below as conservative descriptive members, while accepted names are used for frame ids, resource strings, selected/visual-state flags, and callback.

Proposed formal `RECONSTRUCTION_CPP CODE` insertion:

```cpp
PrettyButtonControlPane::PrettyButtonControlPane(const Rect &bounds,
                                                 const wchar_t *epfResourceName,
                                                 const wchar_t *paletteResourceName,
                                                 int normalFrameId,
                                                 int pressedFrameId,
                                                 int hoverFrameId,
                                                 unsigned char constructorFlag)
    : ButtonControlPane(bounds),
      m_normalFrameId(normalFrameId),
      m_pressedFrameId(pressedFrameId),
      m_hoverFrameId(hoverFrameId),
      m_selected(false),
      m_visualStateFrameActive(false),
      m_epfResourceName(epfResourceName),
      m_paletteResourceName(paletteResourceName),
      m_constructorFlag(constructorFlag),
      m_callback(NULL),
      m_reservedState(false)
{
}
```

Evidence mapping for the proposed body:

- `ButtonControlPane(bounds)` maps to `sub_494EB0(this, a2)` at `0x54b60c`; the caller passes rectangle data as the first constructor argument after `this`.
- `normalFrameId`, `pressedFrameId`, and `hoverFrameId` map to stores at `+0x10c`, `+0x110`, and `+0x114`.
- `m_selected(false)` and `m_visualStateFrameActive(false)` map to the combined word clear at `+0x118/+0x119`.
- `m_epfResourceName` and `m_paletteResourceName` map to the two string constructions at `+0x11c` and `+0x120`.
- `m_constructorFlag(constructorFlag)` maps to the byte store at `+0xff`.
- `m_callback(NULL)` maps to the dword clear at `+0x124`.
- `m_reservedState(false)` maps to the byte clear at `+0x100`.

`Rect`, `m_constructorFlag`, and `m_reservedState` are source-facing descriptive names, not recovered original symbols. `Rect` represents the existing rectangle/bounds object passed by callers and consumed by the base button-control constructor. `m_constructorFlag` is the least-committal name for the final constructor byte at `+0xff`; `m_reservedState` is the least-committal name for the byte at `+0x100` until sibling behavior proves a stronger role. If the project already has a more specific rectangle typedef/class spelling in the PrettyButton/ButtonControlPane headers at callback time, use that established spelling while preserving this argument order and field mapping.

## Recommended Target Doc Changes

For `by-memory/0x0054b5e0-0x0054b6a4.PrettyButtonControlPaneConstructor.md`:

- Change `COMPLETION:84` to `COMPLETION:89`.
- Change `CONFIDENCE:89` to `CONFIDENCE:91`.
- Keep `CANONICAL_OWNER:0000AR`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Set `EMITTER_UIDS:0000AR`.
- Update Item Summary to state the constructor is source-ready/emitting after accepted sibling field/callback reports, while noting `+0xff/+0x100` remain conservatively named.
- Replace the stale C++ Policy blocker with a first-draft C++ readiness note.
- Add live MCP evidence from session `9fb70afc`: function size, exact field writes, xrefs, callees, vtable refs, and padding bytes.
- Add a short score rationale explaining the score raise and the remaining exact-name confidence cap.
- During implementation callback, insert the formal constructor C++ body supplied in `## First-Draft C++ Recommendation` only if supervisor accepts this report.

## Recommended Support Doc Changes

Support docs should be synchronized only enough to avoid stale blocker text:

- `by-class/PrettyButtonControlPane.md`: update the constructor Method Notes / Exact Child Pages wording from C++ blank pending field/resource/callback names to source-ready constructor once the target emits. Preserve the accepted sibling field names and note lower-confidence `+0xff/+0x100` names.
- `by-file/PrettyButtonControlPane.md`: update the UID0004E3 executable split inventory/source-output note so the constructor emits through UID0000AR after callback. Keep broad caveats for still-unresolved sibling methods.
- `by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md`: optional concise row update for UID0004E3 from generic constructor to source-ready/emitting constructor; parent metadata remains `RECONSTRUCTABLE:FALSE`, blank emitter, blank C++.
- `by-memory/0x006222d4-0x00622378.PrettyButtonControlPaneVtableData.md`: no required edit unless current text lacks the constructor vtable-store xrefs; existing class/file docs already record these refs at same-or-greater detail.

No generated report, manual coverage report, registry state, or archive edit is recommended for B007. Generated refresh is supervisor/validator-owned after callback validators.

## Score And Metadata Recommendation

| Field | Current | Recommended | Rationale |
| --- | ---: | ---: | --- |
| `COMPLETION` | `84` | `89` | The target already has exact split, owner, xrefs, base call, vtable stores, field offsets, and padding. Accepted sibling reports now resolve the previously named field/resource/callback blockers enough for emitter/C++ readiness. |
| `CONFIDENCE` | `89` | `91` | Live MCP reconfirms size, instructions, xrefs, callees, vtable refs, caller argument roles, and padding. Confidence remains below final audit because exact original spellings for `+0xff/+0x100` and constructor parameter names are inferred. |
| `CANONICAL_OWNER` | `0000AR` | `0000AR` | Direct class owner is proven by vtable stores and field initialization. |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` | This is source-authored NexusTK constructor code. |
| `EMITTER_UIDS` | blank | `0000AR` | The direct class owner has a valid file route, and the constructor is now source-ready. |
| Formal C++ | blank | supplied in this report for callback insertion | The report now provides the proposed constructor body for Gate 1 validation; callback should add it to the formal block if accepted. |

## Open Questions With Attempted Resolution

- Exact original parameter names: unresolved. MCP/callers prove roles but not original spelling. Recommended source names should be descriptive: rectangle/bounds, EPF resource name, palette resource name, normal/pressed/hover frame ids, and a constructor flag byte.
- `this+0xff`: unresolved exact source name. It is written from the final byte argument and should be documented as an inferred constructor mode/flag byte until sibling behavior names it.
- `this+0x100`: unresolved exact source name. It is cleared by the constructor; no current target-specific evidence supports a stronger name.
- Proposed C++ names for those unresolved bytes: `m_constructorFlag` and `m_reservedState`. These are deliberately conservative and should be documented as inferred confidence caps, not original-symbol proof.
- Resource string constants: resolved enough for source shape. Callers pass EPF/PAL names and shared string pointers; the constructor should store strings rather than hard-code one resource.
- Callback type: resolved for this constructor's blocker by UID0004E6 as `FunctionObject0 *m_callback`; the constructor initializes the pointer to null.
- Owner/source placement: resolved as UID0000AR through UID0000MP.

These open questions cap confidence but do not block emitter routing or first-draft constructor C++.

## Validator Results

Implementation callback validators run:

- `python .\tools\validator.py --mode file --file by-memory/0x0054b5e0-0x0054b6a4.PrettyButtonControlPaneConstructor.md --apply --queue-timeout 240`
  - Result: exit `0`, `ok: 1`, `command_id: 000000005020`, `command_timestamp: 2026-07-03T02:51:57-04:00`.
- `python .\tools\validator.py --mode file --file by-class/PrettyButtonControlPane.md --apply --queue-timeout 240`
  - Result: exit `0`, `ok: 1`, `command_id: 000000005021`, `command_timestamp: 2026-07-03T02:51:59-04:00`.
- `python .\tools\validator.py --mode file --file by-file/PrettyButtonControlPane.md --apply --queue-timeout 240`
  - Result: exit `0`, `ok: 1`, `command_id: 000000005022`, `command_timestamp: 2026-07-03T02:52:01-04:00`.
- `python .\tools\validator.py --mode file --file by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md --apply --queue-timeout 240`
  - Result: exit `0`, `ok: 1`, `command_id: 000000005024`, `command_timestamp: 2026-07-03T02:52:11-04:00`.
- `python .\tools\validator.py --mode file --file by-memory/0x006222d4-0x00622378.PrettyButtonControlPaneVtableData.md --apply --queue-timeout 240`
  - Result: exit `0`, `ok: 1`, `command_id: 000000005025`, `command_timestamp: 2026-07-03T02:52:13-04:00`.

Generated freshness:

- Queue status `000000005034` at `2026-07-03T02:53:32-04:00` reported zero queued/processing jobs and zero queued/processing generated refresh jobs.
- `auto-generated/NexusTK/ui/controls/PrettyButtonControlPane.cpp` header: `validator-command-id: 000000005030`, `validator-refreshed-at: 2026-07-03T02:53:07-04:00`; it contains UID0004E3 and the emitted `PrettyButtonControlPane::PrettyButtonControlPane(...)` body with `m_constructorFlag` and `m_reservedState`.
- `auto-generated/-ag-research-tracker.md` header: `validator-command-id: 000000005030`, refreshed `2026-07-03T02:53:07-04:00`; UID0004E3 row is `89/91`, combined `90.0`, reports `0`.
- `auto-generated/-ag-memory-coverage.md` header: `validator-command-id: 000000005025`, refreshed `2026-07-03T02:52:13-04:00`; UID0004E3 row is `coded`, owner/emitter `0000AR`.
- `auto-generated/-ag-coverage-report-by-memory.md` header: `validator-command-id: 000000005025`, refreshed `2026-07-03T02:52:13-04:00`; UID0004E3 row shows `emits_code:true`, `89%`, `very-strong`.

Results are recorded in the implementation response. No `execute_report`, lifecycle/archive command, registry command, manual report move, generated/manual coverage edit, or IDA/MCP process-management command was run.

## Changed Files

Report/checklist file updated during implementation callback:

- `tools/leaser/Agents/Agent-B007/research/0004E3-PrettyButtonControlPaneConstructor-source-quality.md`

Target/support docs edited:

- `by-memory/0x0054b5e0-0x0054b6a4.PrettyButtonControlPaneConstructor.md`
- `by-class/PrettyButtonControlPane.md`
- `by-file/PrettyButtonControlPane.md`
- `by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md`
- `by-memory/0x006222d4-0x00622378.PrettyButtonControlPaneVtableData.md`

Lease handling:

- B007 leased the five edited by-* docs before the edit/validator batch: target UID0004E3, `by-class/PrettyButtonControlPane.md`, `by-file/PrettyButtonControlPane.md`, parent UID0001F9, and UID0002UW vtable data.
- Cleanup command after validators reported target UID0004E3, class doc, and vtable doc as `Rejected[No active lease]`, and file doc plus parent UID0001F9 as `Rejected[Lease owned by B006]`; B007 therefore had no active releasable lease left at cleanup time.
- The current lease report read after cleanup lists no active B007 leases.

## Implementation Tracking Checklist

- [x] Update `by-memory/0x0054b5e0-0x0054b6a4.PrettyButtonControlPaneConstructor.md` metadata to `COMPLETION:89`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000AR`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000AR`. Proof: target metadata updated.
- [x] Update the target Item Summary, Status, Evidence, C++ Policy, and Score Rationale to reflect live MCP session `9fb70afc`, exact constructor behavior, accepted sibling field/callback names, and remaining `+0xff/+0x100` confidence caps. Proof: target sections updated with MCP evidence and confidence caps.
- [x] During implementation callback only, add the exact proposed formal constructor `RECONSTRUCTION_CPP CODE` from `## First-Draft C++ Recommendation`: `PrettyButtonControlPane::PrettyButtonControlPane(const Rect &bounds, const wchar_t *epfResourceName, const wchar_t *paletteResourceName, int normalFrameId, int pressedFrameId, int hoverFrameId, unsigned char constructorFlag)` initializing `ButtonControlPane(bounds)`, `m_normalFrameId`, `m_pressedFrameId`, `m_hoverFrameId`, `m_selected(false)`, `m_visualStateFrameActive(false)`, `m_epfResourceName`, `m_paletteResourceName`, `m_constructorFlag`, `m_callback(NULL)`, and `m_reservedState(false)`. Proof: exact formal block inserted in target.
- [x] Update `by-class/PrettyButtonControlPane.md` constructor Method Notes / Exact Child Pages wording from blocker wording to source-ready/emitting constructor if the stale blocker remains. Proof: class method and child rows updated, plus evidence/changes notes added.
- [x] Update `by-file/PrettyButtonControlPane.md` UID0004E3 split inventory/source-output note so the constructor emits through UID0000AR; preserve unresolved caveats for other siblings. Proof: file split row/source-output note and evidence/changes updated.
- [x] Optionally update `by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md` UID0004E3 row to source-ready/emitting constructor; keep parent split/index metadata unchanged. Proof: parent row and evidence/changes updated; parent metadata and blank aggregate C++ unchanged.
- [x] Verify `by-memory/0x006222d4-0x00622378.PrettyButtonControlPaneVtableData.md` already records same-or-greater constructor vtable-store evidence, or update only if supervisor callback scope includes it. Proof: vtable doc already had constructor stores; added B007 current constructor store/source-ready note and no metadata change.
- [x] Preserve rejected alternatives and negative evidence: not UID0000AS, not UID0001F9 aggregate emission, not create-user dialog ownership, not no-owner/non-emitting, and no overconfident names for `+0xff/+0x100`. Proof: target rejected alternatives plus support evidence/caveats preserve these.
- [x] Run scoped validators for every edited by-* file and record command id, timestamp, exit code, and `ok` count. Proof: validators `000000005020`, `000000005021`, `000000005022`, `000000005024`, and `000000005025` all exited `0` with `ok: 1`.
- [x] Report generated refresh state after validators if generated `auto-generated/NexusTK/ui/controls/PrettyButtonControlPane.cpp` changes. Proof: queue status `000000005034` shows no pending jobs; generated C++ and research tracker refreshed at `000000005030`, memory coverage reports at `000000005025`, and generated C++ contains UID0004E3 constructor body.
- [x] Supervisor-owned only: after Gate 1 and Gate 2, execute/archive the report through validator lifecycle. B007 must not run `execute_report` or any equivalent lifecycle command. Proof: no lifecycle/archive command run by B007.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000005058","destination_path":"executed-b-agent-research/B007/0004E3-PrettyButtonControlPaneConstructor-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/0004E3-PrettyButtonControlPaneConstructor-source-quality.md","timestamp":"2026-07-03T03:19:24-04:00","uid":"0004E3"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
