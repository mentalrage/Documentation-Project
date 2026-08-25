** TARGET-REPORT-UID:0004CA **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# [UID:0004CA] IMEPaneConstructor By-Memory Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: implement [UID:0004CA] as an emitting `IMEPane::IMEPane()` constructor body through [UID:00006H] `IMEPane` into [UID:0000K5] `IMEPanes`.
- Final disposition: source-authored constructor, not no-code and not aggregate-only. The prior blank formal C++ state was a split-callback deferral, not a target-specific no-code proof.
- Required action after supervisor validation: update [UID:0004CA] metadata to `COMPLETION:88`, `CONFIDENCE:91`, preserve `CANONICAL_OWNER:00006H` and `RECONSTRUCTABLE:TRUE`, set `EMITTER_UIDS:00006H`, insert the formal C++ block in this report, and sync class/file/aggregate support prose.
- Confidence: high for range, route, singleton publication, base/list/member initialization, and field offsets; below final audit because exact original enum spelling for `Pane(4)`, final `SetPaneOrder` helper spelling, and the class-shell representation of the embedded `List` count remain inferred/descriptive.

## Target

- Target UID: [UID:0004CA].
- Target path: `by-memory/0x004e7f20-0x004e7ff5.IMEPaneConstructor.md`.
- Assignment: `B008-report-0004CA-IMEPaneConstructor-by-memory-20260701`.
- Queue source: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`.
- Queue row: `82/89`, combined `85.5`, reconstructable `true`, reports `0`.
- Current generated output lead: `auto-generated/NexusTK/input/IMEPanes.cpp`, validator command `000000004115`, refreshed `2026-07-01T17:52:14-04:00`.

## Current Target State

- Current metadata: `COMPLETION:82`, `CONFIDENCE:89`, `CANONICAL_OWNER:00006H`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, blank formal `RECONSTRUCTION_CPP CODE`.
- Current owner/route text: target already names [UID:00006H] `IMEPane` as direct owner and source route [UID:00006H] -> [UID:0000K5] `IMEPanes`.
- Current blocker wording: the page says formal C++ remains blank because no child-specific formal body was accepted when the split child was created on `2026-06-30`.
- Current generated state: `IMEPanes.cpp` contains the [UID:00006H] `IMEPane` class shell and populated [UID:0004CE] `IMEPane::HandleIMEMessage`, but searches for `0004CA`, `IMEPane::IMEPane`, and empty-emitter marker text return no target marker/body. This is expected from blank `EMITTER_UIDS`, not evidence that the constructor is non-source.
- Current related state: [UID:00006H] `IMEPane` is `88/91`, emits through [UID:0000K5], and already declares `IMEPane();`, `statusPane +0xf8`, `activeChildPane +0xfc`, `candidatePane +0x100`, `focusPaneList +0x104`, `focusPaneCount +0x110`, `focusCaretAnchorY +0x118`, and `focusCaretAnchorX +0x11c`.

## Evidence Checked

### Current Docs And Generated Inputs

- `by-memory/0x004e7f20-0x004e7ff5.IMEPaneConstructor.md`.
- `by-class/IMEPane.md`.
- `by-file/IMEPanes.md`.
- `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md`.
- Sibling/current support pages: [UID:0004BX] `IMEStatusPaneConstructor`, [UID:0004C1] `IMECompositionPaneConstructor`, [UID:0004C7] `IMECandidatePaneConstructor`, [UID:0004CB] `IMEPaneOrdinaryDestructor`, [UID:0004CC] `IMEPaneSetFocusPane`, [UID:0004CD] `IMEPaneIsIMESupported`, [UID:0004CE] `IMEPaneHandleIMEMessage`, [UID:00031G] `IMEPaneFocusCaretAnchorHelper`, [UID:00031K] `IMEPaneScalarDeletingDestructor`, [UID:0000R7] `g_pIMEPane`, [UID:0001PS] `0x0069b458-0x0069b45c.g_pIMEPane`, [UID:00025J] `IMEPaneReadOnlyData`, and [UID:0002H7] `ApplicationStartup`.
- Helper/support pages: [UID:0001EA] `PaneCore`, [UID:000191] `ListConstructor`, [UID:00015S] `RectGeometryHelpers`, [UID:0000T6] `MainUiLayerSlots`, [UID:00029O] `MainUiLayerSlotsTail`, and [UID:0001VH] `PaneLayout`.
- Generated output: `auto-generated/NexusTK/input/IMEPanes.cpp` header and searches for `0004CA`, `IMEPane::IMEPane`, `Empty Emitter Marker`, `empty emitter`, and `TODO: empty`.
- Tracker/generated coverage: `auto-generated/-ag-research-tracker.md` and `auto-generated/-ag-coverage-report-by-memory.md`.

### Old / Executed Report Search

Searched existing reports with `0004CA`, `0x004e7f20`, `0x004e7ff5`, `IMEPaneConstructor`, `IMEPane::IMEPane`, `IMEPane`, and `IMEPanes`.

Relevant leads opened or checked:

- B008 executed family report `executed-b-agent-research/B008/0000K5-IMEPanes-empty-emitter-family-source-quality.md`: created [UID:0004CA] as an exact split child and intentionally left its `EMITTER_UIDS` blank until a child-specific body pass.
- B010 executed [UID:0004CE] report `executed-b-agent-research/B010/0004CE-IMEPaneHandleIMEMessage-source-quality.md`: rechecked `IMEPane::IMEPane`, `IMEPane::~IMEPane`, and UID0004CE for the root child-pointer/secondary-vtable model.
- B011/B007/B009 sibling constructor reports and current target pages for [UID:0004BX], [UID:0004C1], and [UID:0004C7]: used as leads for accepted constructor source style, helper names, and vtable/EH exclusion policy.
- SpecialReports benchmark hits for [UID:0004CC] were search hits only; they do not change this constructor recommendation.

Old reports were treated as leads. Current docs and live MCP evidence below were used as proof.

### IDA MCP Facts

MCP state:

- Endpoint: `http://127.0.0.1:13337/mcp`.
- Session/database: `supervisor_resume_20260629`.
- `server_health`: `status:"ok"`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `14860`, `auto_analysis_ready:true`, `hexrays_ready:true`.
- `tools/list` was rechecked before tool calls. Initial singular-`addr` forms for `xrefs_to`, `callees`, and `get_bytes` returned schema errors; they were retried with active schema `addrs` / `regions` and succeeded. This was schema correction, not MCP unavailability.

Targeted MCP evidence:

- `lookup_funcs`:
  - `0x004e7f20` -> `sub_4E7F20`, size `0xd5`.
  - `0x004e7ff5` -> not a function.
  - `0x004e8000` -> `sub_4E8000`, size `0x98`.
  - `0x004e80a0` -> `sub_4E80A0`, size `0x6b`.
  - `0x004e81a0` -> `sub_4E81A0`, size `0x5`.
  - `0x004e81b0` -> `sub_4E81B0`, size `0x283`.
  - `0x004f639e` sits inside `sub_4F5FB0`, size `0x4e0`.
- `xrefs_to 0x004e7f20`: one code xref at `0x004f639e` from `0x004f5fb0-0x004f6490` startup.
- `xrefs_to 0x0069b458`: 17 data refs, including constructor publish/fallback at `0x004e7f68` and `0x004e7f6f`, destructor clear at `0x004e8079`, root dispatcher read at `0x004e8391`, helper clear at `0x004e85b0`, scalar deleting destructor clear at `0x004e87a0`, startup/shutdown use, and text-entry focus paths.
- `xrefs_to 0x0061c4fc`, `0x0061c548`, `0x0061c578`: each has constructor/destructor/scalar-deleting-destructor stores from `0x004e7f20`, `0x004e8000`, and `0x004e8720`.
- `callees 0x004e7f20`: `0x00544460`, `0x004f3060`, `0x004b7c30`, and `0x00544d30`.
- `decompile 0x004e7f20`: base `Pane` construction with argument `4`; singleton publish/clear through `unk_69B458`; three `IMEPane` vtable stores; `List` construction at `this+0x104` with arguments `4, 4`; zero stores to `this+0xf8`, `this+0xfc`, and `this+0x100`; point-pair/anchor zeroing at `this+0x118`; and `SetPaneOrder` call with two zero arguments.
- `disasm 0x004e7f20`: confirms the above at instruction level, including `push 4; call sub_544460` at `0x004e7f4a/0x004e7f4c`, singleton store at `0x004e7f68`, fallback clear at `0x004e7f6f`, vtable stores at `0x004e7f87/0x004e7f8d/0x004e7f97`, `List` constructor call at `0x004e7fa1`, child pointer zero stores at `0x004e7fb5/0x004e7fbb/0x004e7fc5`, anchor initializer at `0x004e7fcf`, `SetPaneOrder` at `0x004e7fdd`, and return at `0x004e7ff4`.
- `get_bytes`: `0x004e7f1a-0x004e7f20` and `0x004e7ff5-0x004e8000` are `0xcc` padding, supporting exact half-open range `0x004e7f20-0x004e7ff5`.
- `decompile/disasm 0x004e8000`: destructor deletes/marks three root child pointers at complete offsets `+0xf8`, `+0xfc`, and `+0x100`, destroys the embedded List at `+0x104`, clears `g_pIMEPane`, and tears down `Pane`.
- Helper support docs confirm `0x00544460` is `Pane::Pane(mode)`, `0x004f3060` is `List::List(int elementSize, int pageSize)`, `0x004b7c30` is the point-pair initializer (`InitPointPair`) while `0x004b7c50` is `InitRectBounds`, and `0x00544d30` is the accepted `Pane::SetPaneOrder` / dispatcher-order helper.

## Positive Evidence Summary

- The target is a modeled function with exact `0xd5` size and exact padding before/after. It is not a raw no-entry helper or data island.
- The only direct caller is application startup, which already emits `new IMEPane;` and identifies this call as root IME pane construction.
- The constructor writes [UID:0000R7] `g_pIMEPane` at the same global page that current docs and MCP identify as the pane-side IME singleton.
- The constructor installs the three `IMEPane` vtable views already documented in [UID:00025J] `IMEPaneReadOnlyData`.
- The constructor initializes the exact fields already used by current emitted sibling code: `statusPane +0xf8`, `activeChildPane +0xfc`, `candidatePane +0x100`, `focusPaneList +0x104`, and caret anchors at `+0x118/+0x11c`.
- The class [UID:00006H] and file [UID:0000K5] both clear the code-emitter route gate. [UID:00006H] emits through [UID:0000K5] with `[[CHILDREN]]`; [UID:0000K5] has a valid `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/input/"`.
- Sibling constructor callbacks in the same source family have already accepted first-draft C++ using `Pane(0)`, normal source-facing helper names, and omission of vtable/EH/security-cookie lowering. UID0004CA is now at the same evidence tier.

## Negative Evidence Summary

- No evidence supports leaving the target non-emitting. The current blank state is explained by the split callback note, not by no-code proof.
- No evidence supports direct ownership by [UID:0000K5] `IMEPanes` bypassing [UID:00006H]. The method is a class constructor and the class is the narrow semantic owner.
- No evidence supports `InputMan`, `Application`, `Pane`, `List`, `RectBounds`, `MainUiLayerSlots`, `g_pIMEPane`, or `IMEPaneReadOnlyData` as direct owner. They are caller/dependency/global/data support.
- No `AddToLayer` call occurs in this constructor. Unlike the status/composition/candidate pane constructors, UID0004CA only orders/registers the root event-handler view with `SetPaneOrder(NULL, NULL)`.
- The decompiler's `if (this == -248)` branch is an artifact of using `edi = this + 0xf8` and subtracting `0xf8`; source should be `g_pIMEPane = this`, not a nullable adjusted-pointer branch.
- The vtable stores, security-cookie/SEH prologue, construction unwind funclets at `0x00600575`/`0x0060057d`/`0x0060058b`, and `return this` are compiler/ABI effects and should not be handwritten C++.
- The helper at `0x004b7c30` is a point-pair initializer for the two caret-anchor ints, not `InitRectBounds`. Formal source should directly set `focusCaretAnchorY` and `focusCaretAnchorX` to zero rather than inventing a public point-pair helper dependency.

## Heuristic / Inference Reanalysis And Validation

The score blocker named in the current page is stale: "formal constructor C++ remains for a child-specific pass" is exactly what this assignment now supplies. The reasonable current evidence routes were checked:

- Range and boundary: resolved by `lookup_funcs`, `disasm`, and padding bytes.
- Caller/reachability: resolved by the single startup caller and current [UID:0002H7] `ApplicationStartup` source body.
- Owner/emitter route: resolved by [UID:00006H] class ownership and [UID:0000K5] source root generation.
- Helper names: resolved to accepted source-facing names or direct field writes. Use `Pane(4)`, `focusPaneList(4, 4)`, `SetPaneOrder(NULL, NULL)`, and direct caret-anchor zero assignments. Do not emit raw `sub_544460`, `sub_4F3060`, `sub_4B7C30`, or `sub_544D30`.
- Layout/member names: `statusPane`, `activeChildPane`, `candidatePane`, `focusPaneList`, `focusPaneCount`, `focusCaretAnchorY`, and `focusCaretAnchorX` are already the accepted current class names. Constructor evidence further proves `focusPaneList` is constructed with element size `4` and page size `4`; the documented `focusPaneCount +0x110` is the embedded `List` count slot / source-facing alias, not an independently initialized constructor field.
- Source-shape: a normal C++ constructor is better than decompiler-shaped placement-new or raw helper code. The binary publishes `g_pIMEPane` before the embedded list constructor and has unwind cleanup for that early publication; current project constructor style documents that as compiler/EH lowering and uses normal source-facing constructor semantics. This caps final-audit confidence but does not block first-draft code.

Rejected alternatives:

- `no-code`: rejected because this is a modeled source-authored constructor with owner route, field initialization, singleton publish, and first-draft source shape.
- `aggregate-only`: rejected because [UID:000189] is only the family insertion point; exact source bodies belong to child pages.
- `direct by-file emitter`: rejected because class-owned method bodies should route through [UID:00006H].
- `InputMan/Application ownership`: rejected because they call or feed the IME UI but do not own the pane-side constructor.
- `raw helper/function C++`: rejected because source should use the accepted class, global, List, and Pane abstractions.

## Ranked Ownership Analysis

### 1. [UID:00006H] IMEPane

- Evidence for: constructor writes `IMEPane` vtables, initializes IMEPane-specific child/focus fields, publishes `g_pIMEPane`, is paired with [UID:0004CB] destructor and [UID:00031K] scalar deleting destructor, and is listed as `IMEPane()` in the class shell.
- Evidence against: none material. Exact original field/helper spellings are inferred but already accepted across sibling source.
- Decision: direct semantic owner remains [UID:00006H].

### 2. [UID:0000K5] IMEPanes

- Evidence for: final source file owns the pane-side IME family and receives [UID:00006H] output.
- Evidence against: by-structure says class methods should not bypass the class owner just to reach a file root.
- Decision: source file route only: [UID:00006H] -> [UID:0000K5].

### 3. Rejected caller/dependency owners

- [UID:0002H7] `ApplicationStartup`: constructs the singleton but does not own IMEPane internals.
- [UID:0000K6] `InputMan`: produces/bridges IME events but does not own pane UI construction.
- [UID:0000A2] `Pane`, [UID:000079] `List`, [UID:0000N2] `RectBounds`, [UID:0000R7] `g_pIMEPane`, and [UID:00025J] `IMEPaneReadOnlyData`: dependencies or data support, not the method owner.
- Decision: rejected.

## Source Placement

- Recommended source placement: `NexusTK/input/IMEPanes.cpp`, as an `IMEPane::IMEPane()` method emitted through [UID:00006H] and [UID:0000K5].
- This matches the existing generated class shell and sibling method bodies in `auto-generated/NexusTK/input/IMEPanes.cpp`.
- No new file, split, rename, or by-project-structure edit is recommended.

## Range / Split / Padding / Reclassification Analysis

- Exact body range: `0x004e7f20-0x004e7ff5`.
- Predecessor padding: `0x004e7f1a-0x004e7f20` is `0xcc` after [UID:0004C9] `IMECandidatePaneOnPaint`.
- Successor padding: `0x004e7ff5-0x004e8000` is `0xcc` before [UID:0004CB] `IMEPaneOrdinaryDestructor`.
- No split is required. The SEH/unwind funclets outside the body are compiler support for construction cleanup and should remain evidence, not separate source children.
- [UID:000189] `IMEPaneFamily` should remain an aggregate `[[CHILDREN]]` insertion point; it should not receive a broad constructor body.

## First-Draft C++ Recommendation

Eligible for draft C++: yes.

Recommended formal `RECONSTRUCTION_CPP CODE` insertion for [UID:0004CA]:

```cpp
IMEPane::IMEPane()
    : Pane(4),
      focusPaneList(4, 4)
{
    g_pIMEPane = this;

    statusPane = NULL;
    activeChildPane = NULL;
    candidatePane = NULL;

    focusCaretAnchorY = 0;
    focusCaretAnchorX = 0;

    SetPaneOrder(NULL, NULL);
}
```

Reason this preserves observed behavior:

- `Pane(4)` maps the `sub_544460(this, 4)` base construction call and uses the current Pane source style without inventing an unaccepted enum constant.
- `focusPaneList(4, 4)` maps the `List::List` call at `this+0x104` with element size/page size `4, 4`.
- `g_pIMEPane = this` maps the singleton store at `0x004e7f68`; the null-adjusted fallback branch is a compiler/decompiler artifact and construction-unwind detail, not ordinary source.
- The three pointer zeroes map `statusPane`, `activeChildPane`, and `candidatePane`.
- The two caret-anchor zeroes map the `0x004b7c30` point-pair initializer at `this+0x118`.
- `SetPaneOrder(NULL, NULL)` maps `sub_544D30(this, 0, 0)`.

Reason it matches plausible original source:

- It follows the accepted sibling constructor style in [UID:0004BX], [UID:0004C1], and [UID:0004C7]: normal base/member initializer list, field assignments, accepted helper names, and omission of vtable/EH/scalar-wrapper lowering.
- It uses existing project symbols already emitted or declared in `IMEPanes.cpp`: `IMEPane`, `Pane`, `List`, `g_pIMEPane`, and `SetPaneOrder`.
- It avoids raw labels, fake wrapper APIs, vtable arrays, security-cookie code, and decompiler temporaries.

## Recommended Target Doc Changes

Target path: `by-memory/0x004e7f20-0x004e7ff5.IMEPaneConstructor.md`.

Implementation callback should:

- Change metadata from `COMPLETION:82`, `CONFIDENCE:89`, blank `EMITTER_UIDS` to `COMPLETION:88`, `CONFIDENCE:91`, `EMITTER_UIDS:00006H`.
- Preserve `CANONICAL_OWNER:00006H`, `RECONSTRUCTABLE:TRUE`, and blank `EMITTER_POSITION_OPTIONAL`.
- Insert the exact formal C++ block above.
- Replace split-callback blank-C++ wording with current evidence: exact range, padding, startup caller, `Pane(4)`, singleton publish/fallback artifact, `IMEPane` vtable evidence, `focusPaneList(4,4)`, `statusPane`/`activeChildPane`/`candidatePane` zeroing, caret anchor zeroing, `SetPaneOrder`, destructor pairing, and rejected alternatives.
- Update Item Summary to state that the constructor now emits through [UID:00006H] into `NexusTK/input/IMEPanes.cpp`.
- Preserve negative evidence: no `AddToLayer`, no raw vtable/EH/helper C++ statements, no direct `InputMan`/`Application` ownership, no aggregate-only body, and no separate `focusPaneCount = 0` source write.

## Recommended Support Doc Changes

Support path: `by-class/IMEPane.md`.

- No metadata change recommended.
- Add or amend the method/evidence notes for [UID:0004CA]: it is now an emitting constructor body, uses `Pane(4)`, constructs `focusPaneList(4,4)`, publishes `g_pIMEPane`, zeroes `statusPane`/`activeChildPane`/`candidatePane`, zeroes `focusCaretAnchorY/X`, and calls `SetPaneOrder(NULL, NULL)`.
- Clarify that `focusPaneCount +0x110` is the `focusPaneList` count slot / source-facing alias initialized by the List constructor, not a separate source write in UID0004CA.
- Preserve [UID:0004CE] corrected `statusPane +0xf8` / `activeChildPane +0xfc` / `candidatePane +0x100` model.

Support path: `by-file/IMEPanes.md`.

- No metadata change recommended.
- Update Proposed Contents / Evidence Notes / Changes for [UID:0004CA] from "root singleton constructor publishes `g_pIMEPane`" to "emitting `IMEPane::IMEPane()` constructor through [UID:00006H]".
- Preserve source route [UID:00006H] -> [UID:0000K5] and generated expectation that `NexusTK/input/IMEPanes.cpp` should contain the UID0004CA marker/body after validation.

Support path: `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md`.

- No metadata change recommended.
- Update Covered Ranges / split-source table row for [UID:0004CA] to record `88/91`, formal constructor C++ populated, exact `0xd5` function, padding, startup caller, field initialization, singleton publication, and rejected no-code/direct-file/aggregate alternatives.
- Keep aggregate formal C++ as comment plus `[[CHILDREN]]`; do not duplicate the constructor body on the aggregate page.

Already-present support, no callback edit required unless supervisor wants extra cross-links:

- [UID:0000R7] `g_pIMEPane` and [UID:0001PS] memory slot already record constructor publish/fallback, current null storage, and source declaration.
- [UID:0002H7] `ApplicationStartup` already records `new IMEPane;` and the sole constructor caller.
- [UID:0001EA] `PaneCore`, [UID:000191] `ListConstructor`, [UID:00015S] `RectGeometryHelpers`, and [UID:00025J] `IMEPaneReadOnlyData` already provide helper/vtable support at sufficient detail.

## Score And Metadata Recommendation

Current target:

- `COMPLETION:82`
- `CONFIDENCE:89`
- `CANONICAL_OWNER:00006H`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:` blank

Recommended target after callback:

- `COMPLETION:88`
- `CONFIDENCE:91`
- `CANONICAL_OWNER:00006H`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00006H`
- `EMITTER_POSITION_OPTIONAL:` blank

Rationale:

- Completion rises because the report resolves the current blank-emitter blocker with exact formal C++, documents range/padding, caller, callees, field writes, singleton behavior, helper names, route, rejected alternatives, and generated-output expectation.
- Confidence rises because live MCP and current docs agree on the function identity, ownership, route, helper roles, and field offsets. It remains below final-audit levels because exact original `Pane(4)` enum spelling, exact inherited helper spelling, construction-unwind/source-order nuance, and final class-shell List/count declaration polish remain support-level caps.
- No 95+ score is recommended.

## Open Questions With Attempted Resolution

- Exact enum name for `Pane(4)`: unresolved but nonblocking. Pane docs prove mode byte semantics and sibling reports use raw numeric `Pane(0)` when enum labels are not proven. Use `Pane(4)` rather than inventing a mode constant.
- Exact original spelling for `SetPaneOrder`: unresolved but nonblocking. PaneCore documents `Pane::SetPaneOrder` / dispatcher-order helper as the accepted current source name.
- Class-shell representation of `focusPaneCount`: current docs expose `focusPaneCount +0x110` for sibling code, while List layout evidence shows this offset is the embedded `List` count. The implementation callback should clarify this as a source-facing alias/count slot and should not add a separate constructor write.
- Exact status-pane creation path: not resolved by this target and not required for constructor C++. UID0004CA only zeroes `statusPane`; [UID:0004CB]/[UID:0004CE] already preserve that UID0004CE does not create/delete status pane.
- Exact EH/unwind order around early singleton publication: MCP proves cleanup funclets, but formal source should not emit compiler EH scaffolding. This remains an audit caveat, not a C++ blocker under current project style.

## Validator Results

Report-only pass: no validators were run.

Implementation callback validators from `E:\NTK\GhidraBridge\source-3\project-documentation`:

| File | Command | command_id | command_timestamp | Exit | ok | Generated refresh |
| --- | --- | --- | --- | --- | --- | --- |
| `by-memory/0x004e7f20-0x004e7ff5.IMEPaneConstructor.md` | `python .\tools\validator.py --mode file --file by-memory/0x004e7f20-0x004e7ff5.IMEPaneConstructor.md --apply --queue-timeout 240 --wait-generated` | `000000004195` | `2026-07-02T04:32:09-04:00` | `0` | `1` | completed; generated refresh command `000000004195` |
| `by-class/IMEPane.md` | `python .\tools\validator.py --mode file --file by-class/IMEPane.md --apply --queue-timeout 240 --wait-generated` | `000000004201` | `2026-07-02T04:39:08-04:00` | `0` | `1` | completed; generated refresh command `000000004201` |
| `by-file/IMEPanes.md` | `python .\tools\validator.py --mode file --file by-file/IMEPanes.md --apply --queue-timeout 240 --wait-generated` | `000000004203` | `2026-07-02T04:39:25-04:00` | `0` | `1` | completed; generated refresh command `000000004203` |
| `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md` | `python .\tools\validator.py --mode file --file by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md --apply --queue-timeout 240 --wait-generated` | `000000004204` | `2026-07-02T04:39:47-04:00` | `0` | `1` | completed; generated refresh command `000000004204` |

Validator side effects were validator-owned generated refreshes only: generated coverage/research tracker/projected stats metadata and `auto-generated/NexusTK/input/IMEPanes.cpp` were refreshed by validator commands. No generated files, coverage reports, validator/tool state, queues, ledgers, archives, locks, or IDA DB were edited manually.

Generated freshness:

- `auto-generated/NexusTK/input/IMEPanes.cpp` header after callback: `validator-command-id: 000000004205`, `validator-refreshed-at: 2026-07-02T04:40:07-04:00`.
- The generated header is newer than the final edited by-* validator command `000000004204` / `2026-07-02T04:39:47-04:00`.
- The generated file contains `// UID:0004CA | by-memory/0x004e7f20-0x004e7ff5.IMEPaneConstructor.md | Completion:88 | Confidence:91` followed by `IMEPane::IMEPane()`.
- The aggregate page still emits only the aggregate comment plus `[[CHILDREN]]`; the constructor body is not duplicated there.

## Changed Files

- Created during report-only pass: `tools/leaser/Agents/Agent-B008/research/0004CA-IMEPaneConstructor-by-memory-source-quality.md`.
- Modified during callback: `by-memory/0x004e7f20-0x004e7ff5.IMEPaneConstructor.md`.
- Modified during callback: `by-class/IMEPane.md`.
- Modified during callback: `by-file/IMEPanes.md`.
- Modified during callback: `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md`.
- Modified during callback: this report checklist/ledger.
- Leases: B008 leased the target at `2026-07-02T08:29:18Z` until `08:34:18Z` and released it after target validation. B008 later leased `by-class/IMEPane.md`, `by-file/IMEPanes.md`, and `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md`, validated them, and released them. Final lease report shows no active B008 leases.
- Excluded from manual edits: support docs outside approved scope, generated files, generated reports, coverage reports, project-level generated reports, validator/tool state, supervisor ledgers, queues, archives, lock files, and IDA DB.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | Prior target state was `82/89`, reconstructable true, owner [UID:00006H], blank emitter/formal C++, and tracker row `82/89` combined `85.5`. | High | Target metadata; generated tracker/coverage leads. | [UID:0004CA] Status, Score Rationale, Changes. | incorporate | applied |
| C02 | Prior generated `IMEPanes.cpp` lacked UID0004CA marker/body because `EMITTER_UIDS` was blank. | High | Generated search before callback; validator output after callback. | [UID:0004CA] Reconstruction Notes; [UID:0000K5] Evidence/Changes. | incorporate | applied |
| C03 | Live MCP evidence from the report remains provenance for the accepted callback. | High | Report MCP evidence. | [UID:0004CA] Evidence; callback report body retained. | incorporate | applied |
| C04 | Function boundary is exact `0x004e7f20-0x004e7ff5`, size `0xd5`, with `0xcc` padding before and after. | High | MCP `lookup_funcs`, `disasm`, `get_bytes`. | [UID:0004CA] Evidence; [UID:000189] covered/split rows. | incorporate | applied |
| C05 | Sole direct constructor caller is startup at `0x004f639e` in [UID:0002H7] `ApplicationStartup`. | High | MCP xrefs; current startup doc. | [UID:0004CA] Evidence; [UID:0000K5] Evidence. | incorporate | applied |
| C06 | Constructor source shape begins with `Pane(4)`; exact enum name is unproven, so use numeric `4`. | High | MCP decompile/disasm; Pane docs. | [UID:0004CA] formal C++ and evidence; support docs. | incorporate | applied |
| C07 | Decompiler adjusted-pointer branch is compiler/decompiler artifact; source should be `g_pIMEPane = this`. | High | MCP decompile/disasm; g_pIMEPane docs. | [UID:0004CA] formal C++ and notes. | incorporate | applied |
| C08 | Vtable stores are compiler output from IMEPane class declarations, not handwritten source. | High | MCP disasm/xrefs; read-only data docs. | [UID:0004CA] Evidence/Reconstruction Notes; support notes. | incorporate | applied |
| C09 | `focusPaneList` is constructed as `List(4,4)`; `focusPaneCount +0x110` is the embedded List count slot/source-facing alias, not a separate constructor write. | High | MCP decompile/disasm; List layout; class shell. | [UID:0004CA] C++; [UID:00006H] shell/method/evidence; support rows. | incorporate | applied |
| C10 | Constructor zeroes `statusPane +0xf8`, `activeChildPane +0xfc`, and `candidatePane +0x100`. | High | MCP decompile/disasm; destructor pairing. | [UID:0004CA] Behavior/Evidence; [UID:00006H]; [UID:000189]. | incorporate | applied |
| C11 | Constructor zeroes caret-anchor fields at `+0x118/+0x11c`; formal source uses direct field writes, not raw `InitPointPair`. | High | MCP decompile/disasm; RectGeometry docs. | [UID:0004CA] formal C++/evidence; [UID:00006H] note. | incorporate | applied |
| C12 | Constructor calls `SetPaneOrder(NULL, NULL)` and does not call `AddToLayer`. | High | MCP callees/disasm; PaneCore docs. | [UID:0004CA] formal C++/negative evidence; support rows. | incorporate | applied |
| C13 | Direct owner remains [UID:00006H] `IMEPane`; emitter is [UID:00006H] because class routes to [UID:0000K5]. | High | Target/class/file metadata; by-structure rules. | [UID:0004CA] metadata; [UID:00006H]/[UID:0000K5] support notes. | incorporate | applied |
| C14 | Reject no-code, direct-file, InputMan, Application, Pane/List/Rect/global/data ownership alternatives. | High | Ownership ranking; caller/dependency roles. | [UID:0004CA] Reconstruction Notes; [UID:0000K5]/[UID:000189] support. | incorporate | applied |
| C15 | Target metadata should be `88/91`, preserve owner/reconstructable, set `EMITTER_UIDS:00006H`, keep blank position. | High | Code gate; owner route; sibling constructor precedent. | [UID:0004CA] header metadata and Score Rationale. | incorporate | applied |
| C16 | Exact formal C++ body is `IMEPane::IMEPane() : Pane(4), focusPaneList(4,4) { ... SetPaneOrder(NULL,NULL); }`. | High | MCP body; helper docs; sibling style. | [UID:0004CA] formal `RECONSTRUCTION_CPP CODE`. | incorporate | applied |
| C17 | [UID:00006H] class support should add constructor evidence and clarify List/count alias, with no metadata change. | Medium-high | Current class shell; MCP List constructor. | `by-class/IMEPane.md` Method Notes/Observed State/Evidence/Changes. | incorporate | applied |
| C18 | [UID:0000K5] file support should mark UID0004CA as emitting through IMEPane, with no score change. | High | File route; target-specific improvement. | `by-file/IMEPanes.md` Proposed Contents/Evidence/Changes. | incorporate | applied |
| C19 | [UID:000189] aggregate should update UID0004CA rows and keep aggregate code as comment plus `[[CHILDREN]]`, with no duplicate body. | High | Aggregate split policy; by-structure child-body rule. | `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md` Covered Ranges/split table/Changes. | incorporate | applied |
| C20 | Existing g_pIMEPane, ApplicationStartup, PaneCore, ListConstructor, RectGeometry, MainUiLayerSlots, and IMEPaneReadOnlyData docs are support evidence already present; no direct edits required. | Medium-high | Current docs checked. | Mentioned in target/support; no separate edits. | already-present | already-present |
| C21 | Generated/manual coverage files, generated reports, generated C++, validator/tool state, ledgers, queues, archives, lock files, and IDA DB are excluded from B008 manual edits. | High | Assignment write boundaries and workflow rules. | Callback changed-file/no-edit statement. | not-applicable | not-applicable |

## Implementation Tracking Checklist

Callback implementation:

- [x] Supervisor validation required before any by-* implementation. Callback received in `goal.md`; implementation performed after acceptance.
- [x] Edit `by-memory/0x004e7f20-0x004e7ff5.IMEPaneConstructor.md`: changed `COMPLETION:82` to `COMPLETION:88`; changed `CONFIDENCE:89` to `CONFIDENCE:91`; preserved `CANONICAL_OWNER:00006H`, `RECONSTRUCTABLE:TRUE`, and blank `EMITTER_POSITION_OPTIONAL`; set `EMITTER_UIDS:00006H`.
- [x] Edit `by-memory/0x004e7f20-0x004e7ff5.IMEPaneConstructor.md`: inserted exact formal `IMEPane::IMEPane()` C++ body from this report into the formal block.
- [x] Edit `by-memory/0x004e7f20-0x004e7ff5.IMEPaneConstructor.md`: replaced stale blank-C++ wording with behavior/evidence for `Pane(4)`, `g_pIMEPane = this`, compiler vtable stores, `focusPaneList(4,4)`, child/caret zeroing, `SetPaneOrder(NULL,NULL)`, startup caller, padding, and destructor pairing.
- [x] Edit `by-memory/0x004e7f20-0x004e7ff5.IMEPaneConstructor.md`: preserved rejected alternatives and negative evidence: no no-code disposition, no direct by-file/InputMan/Application/helper/global/data owner, no `AddToLayer`, no handwritten vtable/security-cookie/EH/source-unwind code, no raw helper APIs, and no separate `focusPaneCount = 0` source statement.
- [x] Edit `by-class/IMEPane.md`: added constructor method/evidence notes for emitting `IMEPane::IMEPane()`, `Pane(4)`, `focusPaneList(4,4)`, `g_pIMEPane`, child pointer zeroing, caret zeroing, and `SetPaneOrder(NULL,NULL)`.
- [x] Edit `by-class/IMEPane.md`: clarified `focusPaneCount +0x110` as embedded `focusPaneList` count slot/source-facing alias initialized by `List(4,4)`, not a separate constructor store; no class metadata change was made by this callback.
- [x] Edit `by-file/IMEPanes.md`: updated Proposed Contents / Evidence Notes / Changes for [UID:0004CA] as emitting `IMEPane::IMEPane()` routed through [UID:00006H] into `NexusTK/input/IMEPanes.cpp`; preserved route [UID:00006H] -> [UID:0000K5] and no file metadata change.
- [x] Edit `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md`: updated UID0004CA Covered Ranges / split-source rows with `88/91`, formal constructor C++ populated, exact `0xd5` boundary, padding, startup caller, field initialization, singleton publication, and rejected no-code/direct-file/aggregate alternatives. Aggregate formal C++ remains comment plus `[[CHILDREN]]`; no duplicate constructor body.
- [x] Confirmed no direct edits were made to out-of-scope support docs, generated files, coverage reports, validator/tool state, queues, ledgers, archives, lock files, or IDA DB.
- [x] Ran target validator: command `000000004195`, timestamp `2026-07-02T04:32:09-04:00`, exit `0`, `ok:1`, generated refresh completed.
- [x] Ran class validator: command `000000004201`, timestamp `2026-07-02T04:39:08-04:00`, exit `0`, `ok:1`, generated refresh completed.
- [x] Ran file validator: command `000000004203`, timestamp `2026-07-02T04:39:25-04:00`, exit `0`, `ok:1`, generated refresh completed.
- [x] Ran aggregate validator: command `000000004204`, timestamp `2026-07-02T04:39:47-04:00`, exit `0`, `ok:1`, generated refresh completed.
- [x] Inspected `auto-generated/NexusTK/input/IMEPanes.cpp`: header `validator-command-id: 000000004205`, `validator-refreshed-at: 2026-07-02T04:40:07-04:00`; generated file contains UID0004CA marker and `IMEPane::IMEPane()` body; aggregate UID000189 did not duplicate the constructor body.
- [x] Updated this report's Claim And Incorporation Ledger from `proposed` to callback states with proof destinations.
- [x] Checked off this checklist with target/support path proof, validator command IDs/timestamps/exit/ok counts, generated freshness, and exclusions.

Unchecked callback items: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004213","destination_path":"executed-b-agent-research/B008/0004CA-IMEPaneConstructor-by-memory-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B008/research/0004CA-IMEPaneConstructor-by-memory-source-quality.md","timestamp":"2026-07-02T04:53:47-04:00","uid":"0004CA"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
