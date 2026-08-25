** TARGET-REPORT-UID:0002T2 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002T2 IconsPaneOnMouseEvent Source-Quality Report


## Finalized Report / Current Recommendation

UID `0002T2` implementation callback is complete and ready for supervisor Gate 2 review/execute. The target range, owner, emitter route, and reconstructability flag were kept as accepted:

```text
CANONICAL_OWNER:00006B
EMITTER_UIDS:00006B
RECONSTRUCTABLE:TRUE
Range: 0x004cf3e0-0x004cf74b
```

The old blocker for a blank formal C++ body has been resolved at first-draft level. UID `0002T2` now has a formal `IconsPane::OnMouseEvent` body in the target doc, and support docs now say the OnMouseEvent first draft is present. The adjacent switch-table/raw-helper bytes were not merged into this UID, and UID `0002T2` was not changed to call the no-route raw dispatcher at `0x004cf8e0`; the source block keeps the direct mouse-up switch.

Implemented target score: `COMPLETION:89`, `CONFIDENCE:91`.

## Supporting Research

This report used the project-level B-agent workflow and the report template/score audit references from the `ntk-b-agent-workflow` skill. The target was checked against current docs, generated lead output, prior executed B-agent reports, and the active IDA MCP database session `60724697`.

Important support references checked:

- `by-memory/0x004cf3e0-0x004cf74b.IconsPaneOnMouseEvent.md`
- `by-class/IconsPane.md`
- `by-file/IconsPane.md`
- `by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md`
- `by-memory/0x004cf7d0-0x004cf862.IconsPaneHitTestIcon.md`
- `by-memory/0x004cf870-0x004cf8d5.IconsPaneSetIconHighlight.md`
- `by-memory/0x004cf8e0-0x004cf974.IconsPaneActionDispatchRawBody.md`
- `auto-generated/NexusTK/ui/panels/IconsPane.cpp`, read only as generated lead output
- `auto-generated/-ag-research-tracker.md`, read only as coverage/tracker lead output
- Executed B-agent reports for UID `00016Z`, `00022Q`, `0002T3`, `0002T4`, `0002SW`, and related TabPane raw-rectangle precedent

## Target

Target doc:

```text
source-3/project-documentation/by-memory/0x004cf3e0-0x004cf74b.IconsPaneOnMouseEvent.md
```

Assigned report path:

```text
source-3/project-documentation/tools/leaser/Agents/Agent-B001/research/0002T2-IconsPaneOnMouseEvent-source-quality.md
```

## Current Target State

Current target header state after callback:

```text
UID:0002T2
COMPLETION:89
CONFIDENCE:91
CANONICAL_OWNER:00006B
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00006B
RECONSTRUCTION_CPP: first-draft OnMouseEvent present
```

The target now contains the core behavioral facts and the accepted formal C++ block: exact function range, vtable-slot route, event dispatch, vertical-first coordinate order, hit-test and highlight helper calls, tooltip string IDs, input-lock gate, cleanup behavior, and adjacent compiler-table/raw-helper inventory. The old stale wording that full `OnMouseEvent` C++ should remain blank has been historicalized/superseded.

## Heuristic / Inference Reanalysis And Validation

The source-facing method identity is not heuristic-only. IDA shows `sub_4CF3E0` as a single function at `0x004cf3e0` with one vtable data xref from `0x0061b498`, matching the IconsPane event slot documented by the target and class docs.

The secondary-subobject `this` adjustment in the decompile is compiler/ABI shape, not a reason to move ownership. Calls that need full `IconsPane` state subtract `0xa0` from the incoming event-subobject pointer, and the selected icon index lands at full-object offset `+0xfc`, matching the accepted IconsPane field model used by constructor, hit-test, and highlight docs.

The event coordinate order is validated by current docs and by the current MCP decompile: `Block[2]` is vertical `y`, `Block[3]` is horizontal `x`, and calls to bounds checks and `HitTestIcon` preserve that order.

Action-helper source names are behavior-level names, but the dispatch order and argument constants are not speculative. The direct switch in UID `0002T2` and the retained raw duplicate in UID `00022Q` both use the same eight helper call targets and the same case order.

## Evidence Standards Used

I treated IDA MCP as the ground truth for bytes, ranges, xrefs, function boundaries, and current decompiler structure. Documentation and generated output were treated as leads that must be reconciled against the current IDB.

For C++ eligibility I applied the by-structure gate: target is reconstructable TRUE, has a nonblank emitter route through UID `00006B`, and current average score is above 85. I did not recommend a 95+ score because that requires final-audit evidence and no remaining open caveats.

For no-route regions, I preserved the workflow distinction between target body ownership and adjacent byte coverage. The uncalled raw helpers and table bytes remain documented support concerns; they do not require expanding UID `0002T2` beyond its exact IDA function end.

## Evidence Checked

IDA MCP session evidence:

- `initialize` succeeded against `ida-pro-mcp` using protocol `2025-06-18`.
- `idb_list` showed active session `60724697`, database `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, input filename `NexusTK.exe.i64`, worker pid `13932`, `is_active:true`, `is_analyzing:false`.
- `server_health` for database `60724697` returned status `ok`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
- `lookup_funcs` found `sub_4CF3E0` at `0x004cf3e0`, size `0x36b`; `0x004cf74b` and `0x004cf7a0` are not functions; `sub_4CF7D0` and `sub_4CF870` remain separate neighbor functions.
- `xrefs_to` found one data xref to `0x004cf3e0` from `0x0061b498`; no direct code callers; local table xrefs to `0x004cf74c`, `0x004cf760`, and `0x004cf780`; no xrefs to `0x004cf7a0` or `0x004cf8e0`.
- `get_bytes` showed the UID `0002T2` function return at `0x004cf748` with `retn 4`, the `0x90` byte at `0x004cf74b`, then local switch-table data, raw helper bytes at `0x004cf7a0`, and padding before `sub_4CF7D0`.
- `decompile` for `0x004cf3e0` showed the full switch over event byte `*((BYTE*)Block + 4)`, coordinates from `Block[2]` and `Block[3]`, hit-test and highlight calls, capture/release calls, input-lock gate, tooltip allocation, language string IDs `202..209`, and the eight direct action helper calls.
- `disasm` paging confirmed event table use at `0x004cf426`, tooltip table use at `0x004cf4b9`, click table use at `0x004cf6d8`, direct action callsites at `0x004cf6df` through `0x004cf712`, cleanup at `0x004cf71b`, selected-index reset at `0x004cf72d`, and final return at `0x004cf748`.
- `callees` for `0x004cf3e0` listed the pane bounds helper, `sub_4CF7D0`, capture helper, `sub_4CF870`, allocation/language/tooltip helpers, capture-state and release helpers, and all eight action helpers.
- `find_bytes` found VA pointer operands for the three local switch tables only at their in-function use sites and found no pointer references to `0x004cf7a0` or `0x004cf8e0`.
- `type_query` and `entity_query` found no recovered `IconsPane` UDT or source symbol names in the local address range, so source-level type/member names remain documentation-derived.

Documentation evidence:

- Target doc already records the method behavior, coordinate order, input-lock byte, helper callsites, and adjacent table/raw-helper layout.
- `by-class/IconsPane.md` already owns this method under UID `00006B` and lists neighbor helpers with accepted first-draft C++.
- `by-file/IconsPane.md` routes UID `00006B` to `NexusTK/ui/panels/IconsPane.cpp`.
- `IconsPaneCore` preserves this method as part of the broader physical cluster while keeping the table/raw-helper gap separate.
- Generated `IconsPane.cpp` now has first-draft bodies for `HitTestIcon`, `SetIconHighlight`, `DispatchIconsPaneAction`, and UID `0002T2` `IconsPane::OnMouseEvent` after latest scoped validator refresh command `000000006275`.
- The generated research tracker row for UID `0002T2` showed no executed B-agent research report before this report.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| B001-0002T2-C01 | UID `0002T2` is exactly `sub_4CF3E0` at `0x004cf3e0-0x004cf74b`. | High | Current MCP `lookup_funcs` reports `sub_4CF3E0` at `0x004cf3e0`, size `0x36b`; `get_bytes` shows function return at `0x004cf748` and post-function `0x90` at `0x004cf74b`; target doc already records this range. | Target `Address Range`, `Evidence`, `Score Rationale`; support `IconsPaneCore` child inventory | already-present | already-present |
| B001-0002T2-C02 | Keep `CANONICAL_OWNER:00006B` and `EMITTER_UIDS:00006B`. | High | Target/class/file docs route the method through IconsPane; current MCP `xrefs_to 0x004cf3e0` shows vtable data xref from `0x0061b498`; generated lead places neighboring IconsPane helpers in `NexusTK/ui/panels/IconsPane.cpp`. | Target metadata; `by-class/IconsPane.md` method table; `by-file/IconsPane.md` source contents | already-present | already-present |
| B001-0002T2-C03 | Keep `RECONSTRUCTABLE:TRUE` and add first-draft formal C++ because the target clears the reconstructable/emitter/score gate. | High | Target is reconstructable TRUE, emitter route is nonblank, current average score is above 85, and neighbor helpers UID `0002T3`, UID `0002T4`, and UID `00022Q` now have first-draft source concepts. | Target metadata and `RECONSTRUCTION_CPP CODE` block | incorporate | applied |
| B001-0002T2-C04 | Update target score to `COMPLETION:89`, `CONFIDENCE:91`; do not raise into 95+ final-audit range. | Medium-high | Current MCP closes the blank-C++ blocker, but no recovered UDT/original symbols exist and adjacent gap child pages remain cluster coverage work. | Target metadata and `Score Rationale`; optional support score notes in class/core docs | incorporate | applied |
| B001-0002T2-C05 | Preserve vertical-first event coordinate order: `Block[2]` is `y`, `Block[3]` is `x`. | High | Current MCP decompile assigns `v3 = Block[2]`, `v4 = Block[3]`; bounds and `HitTestIcon` calls pass `(v3, v4)`; target and B012 reports already corrected older wording. | Target `Behavior`, `Event Flow`, C++ block; support `by-class/IconsPane.md` method notes if expanded | already-present | applied |
| B001-0002T2-C06 | The method handles four relevant event cases: captured move, button down, button up, and hover/help tooltip. | High | Current MCP decompile switch on `*((BYTE*)Block + 4)` and disassembly pages show the same cases and local jump tables. | Target `Event Flow` and formal C++ block | incorporate | applied |
| B001-0002T2-C07 | Button down stores `m_selectedIconIndex`, captures mouse input, and sets pressed/highlight state only for a valid icon. | High | Current MCP decompile case 1 uses bounds check, `sub_4CF7D0`, stores `this[23]`, calls capture helper, then `sub_4CF870(..., 1)`. | Target `Event Flow` and formal C++ block | incorporate | applied |
| B001-0002T2-C08 | Captured move re-hit-tests and calls `SetIconHighlight` true only when the current icon equals `m_selectedIconIndex`. | High | Current MCP decompile case 0 calls capture-state helper, `sub_4CF7D0`, compares against `this[23]`, then calls `sub_4CF870` with 1 or 0. | Target `Event Flow` and formal C++ block | incorporate | applied |
| B001-0002T2-C09 | Button up must use a direct local switch and must not be rewritten as a call to UID `00022Q` `DispatchIconsPaneAction`. | High | Current MCP disassembly shows local click table at `0x004cf780` and direct helper callsites `0x004cf6df` through `0x004cf712`; `xrefs_to 0x004cf8e0` finds zero xrefs. | Target `Action Dispatch`, `Reconstruction Notes`, formal C++ block; support UID `00022Q` note | incorporate | applied |
| B001-0002T2-C10 | Mouse-up action dispatch is gated by `!g_activeMapPane->m_inputLocked` before the eight action cases. | High | Current MCP decompile checks `!*(BYTE *)(dword_67A764 + 1008)` before the switch; target doc records input-lock byte `0x3f0` decimal `1008`. | Target `Action Dispatch`, C++ block; support `by-class/IconsPane.md` external-state notes | incorporate | applied |
| B001-0002T2-C11 | Mouse-up cleanup always clears highlight, resets selected icon to `-1`, releases capture, and returns handled when capture was active. | High | Current MCP disassembly at `0x004cf71b` calls `sub_4CF870(..., 0)`, writes `0xffffffff` to selected index, calls release helper, and sets handled return. | Target `Event Flow` and formal C++ block | incorporate | applied |
| B001-0002T2-C12 | Hover/help tooltip case uses icon IDs `202..209` and timeout `5000`. | High | Current MCP decompile and disassembly show language lookup IDs `0xca..0xd1`, allocation size `0xfc`, and tooltip constructor timeout `0x1388`. | Target `Event Flow`, `Behavior`, and formal C++ block | incorporate | applied |
| B001-0002T2-C13 | `HitTestIcon` and `SetIconHighlight` are separate IconsPane helpers and should remain calls in the C++ block. | High | Current MCP xrefs show four calls to `0x004cf7d0` and four calls to `0x004cf870`; UID `0002T3` and UID `0002T4` have first-draft helper bodies. | Target C++ block and support `by-class/IconsPane.md` method table | incorporate | applied |
| B001-0002T2-C14 | Adjacent `0x004cf74b-0x004cf7d0` bytes stay outside UID `0002T2`; do not merge switch tables or the no-route rectangle helper into this method. | High | Current MCP bytes show function end before table data; `xrefs_to` shows table xrefs only from inside `sub_4CF3E0`; `xrefs_to 0x004cf7a0` finds zero xrefs. | Target `Adjacent Compiler Tables And Raw Helper`, `Range / Split / Padding / Reclassification Analysis`; support `IconsPaneCore` caveat | already-present | applied |
| B001-0002T2-C15 | The current target note that full `OnMouseEvent` C++ should remain blank is stale after this report. | High | Current target reconstruction note predates B012 neighbor helper first drafts and current MCP recheck; C++ eligibility gate is now satisfied. | Target `Reconstruction Notes` and `Score Rationale` | reject-stale | applied |
| B001-0002T2-C16 | Preserve negative evidence that original event type names, capture helper names, UDTs, and final action helper names are not recovered. | Medium-high | Current MCP `type_query` and `entity_query` found no local UDT or source symbol names; generated helper names are behavior-level documentation names. | Target `Evidence`, `Reconstruction Notes`, `Open Questions`; support class/file caveats | incorporate | applied |
| B001-0002T2-C17 | Generated files and validator-owned tracker/coverage outputs must refresh through validator/supervisor flow only, not manual edits. | High | Workflow role boundaries prohibit manual generated/project-level/tracker-state edits; latest scoped validator command `000000006275` refreshed generated `IconsPane.cpp` so UID `0002T2` now emits a body instead of an empty marker. | `Changed Files`, `Validator Results`, checklist; support docs only after callback | not-applicable | excluded-with-reason |

## Positive Evidence Summary

The function boundary is exact and stable. Current MCP confirms `sub_4CF3E0` size `0x36b`, ending before the one-byte `0x90` at `0x004cf74b`.

The behavior is well recovered. The decompile and disassembly agree on four event cases: captured move, button down, button up, and hover/help tooltip. Each helper callsite and each action-helper target is concrete.

The support dependencies are no longer blank. `HitTestIcon`, `SetIconHighlight`, and the retained raw dispatch duplicate have first-draft generated C++ in the current generated lead, so UID `0002T2` can now refer to those accepted source concepts.

The source placement route is already coherent. IconsPane class UID `00006B` emits through `by-file/IconsPane.md` into `NexusTK/ui/panels/IconsPane.cpp`.

## Negative Evidence Summary

No recovered local UDT or original source symbol names were found for `IconsPane`, the event struct, enum values, capture helper names, tooltip class, or action helper names. The first-draft C++ must therefore use documented source-facing names and should keep a note that event type/member names may need synchronization with the broader UI event docs.

No direct xrefs target `0x004cf7a0` or `0x004cf8e0`. These no-route raw helpers should not be presented as direct callees of UID `0002T2`.

The adjacent switch-table/raw-helper gap still lacks exact child pages. This is a physical coverage issue for the IconsPane cluster, not a reason to expand the OnMouseEvent range.

Generated output was refreshed by scoped validator command `000000006275`, not by manual generated-file edits. UID `0002T2` now emits a real `IconsPane::OnMouseEvent` body in `auto-generated/NexusTK/ui/panels/IconsPane.cpp`.

## Ranked Ownership Analysis

1. `00006B` IconsPane class: best owner. The function uses IconsPane fields, IconsPane helper methods, IconsPane vtable data, and IconsPane source placement.
2. `0000JZ` IconsPane file: correct emitter support route through the class/file chain, but not the direct canonical owner of this method.
3. Raw memory owner under `IconsPaneCore`: useful physical grouping only. It should not replace the class owner.
4. Event base/window/control subobject: rejected as canonical owner. The incoming `this` pointer is a secondary event subobject, but the method updates full IconsPane state and routes through IconsPane's vtable slot.

## Source Placement

Keep source placement under:

```text
source-3/project-documentation/by-class/IconsPane.md
source-3/project-documentation/by-file/IconsPane.md
NexusTK/ui/panels/IconsPane.cpp
```

The generated lead places neighbor helper bodies and the refreshed UID `0002T2` body in `auto-generated/NexusTK/ui/panels/IconsPane.cpp`. UID `0002T2` was added through the normal target/support doc route, then regenerated by validator tooling during this implementation callback.

## Range / Split / Padding / Reclassification Analysis

Keep UID `0002T2` as exactly `0x004cf3e0-0x004cf74b`.

Current MCP byte and function evidence:

- `0x004cf3e0-0x004cf74a`: `sub_4CF3E0` body and function return.
- `0x004cf74b`: one-byte `0x90` after the function.
- `0x004cf74c-0x004cf75f`: event switch table.
- `0x004cf760-0x004cf77f`: tooltip string-id switch table.
- `0x004cf780-0x004cf79f`: click-action switch table.
- `0x004cf7a0-0x004cf7c8`: raw rectangle-helper-shaped body with no pointer route found.
- `0x004cf7c9-0x004cf7cf`: `0xcc` padding.
- `0x004cf7d0`: start of UID `0002T3` `HitTestIcon`.

No split is needed inside UID `0002T2`. The adjacent tables and raw helper should remain outside this target. If a later support implementation handles exact physical coverage for the cluster, create separate child docs for the switch-table data and `0x004cf7a0` raw helper rather than expanding this method.

## First-Draft C++ Recommendation

Add formal reconstruction C++ to the target doc. This is intended as first-draft source, not final-audit C++. The event type and event enum/member names below are source-facing names inferred from the recovered event block; if the project has already accepted exact UI event names elsewhere, use those exact names during implementation while preserving the recovered control flow and coordinate order.

Recommended code: the target's formal reconstruction block was populated with exactly this `RECONSTRUCTION_CPP CODE` insertion text. The required header, `BEGIN`, and `END` marker lines are included here intentionally; the C++ is not a body-only example.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool IconsPane::OnMouseEvent(const PaneMouseEvent *event)
{
    bool handled = false;
    const int y = event->y;
    const int x = event->x;

    switch (event->type)
    {
    case MouseEvent_Move:
        if (HasMouseCapture())
        {
            SetIconHighlight(HitTestIcon(y, x) == m_selectedIconIndex);
            handled = true;
        }
        break;

    case MouseEvent_ButtonDown:
        if (PointInRect(y, x, &m_bounds))
        {
            m_selectedIconIndex = HitTestIcon(y, x);
            if (m_selectedIconIndex != -1)
            {
                CaptureMouse();
                SetIconHighlight(true);
                handled = true;
            }
        }
        break;

    case MouseEvent_ButtonUp:
        if (HasMouseCapture())
        {
            const int hitIcon = HitTestIcon(y, x);
            if (hitIcon == m_selectedIconIndex && !g_activeMapPane->m_inputLocked)
            {
                switch (hitIcon)
                {
                case 0:
                    SwitchGeneralPurposePanelMode2WithClickSound();
                    break;

                case 1:
                    SwitchGeneralPurposePanelMode3WithClickSound();
                    break;

                case 2:
                    SendOpcode2DAndStoreExtra(0);
                    break;

                case 3:
                    g_pCollectionData->SyncNationEntriesOrDeferredState();
                    break;

                case 4:
                    EnsureNormalBulletinSession();
                    break;

                case 5:
                    g_pCollectionData->OpenInputPaneForCurrentSayMode();
                    break;

                case 6:
                    SendOpcode43MinusOneRequest();
                    break;

                case 7:
                    OpenQuitPrompt();
                    break;

                default:
                    break;
                }
            }

            SetIconHighlight(false);
            m_selectedIconIndex = -1;
            ReleaseMouseCapture();
            handled = true;
        }
        break;

    case MouseEvent_Hover:
        if (PointInRect(y, x, &m_bounds))
        {
            const int hitIcon = HitTestIcon(y, x);
            if (hitIcon != -1)
            {
                static const unsigned short kTooltipStringIds[8] = {
                    202, 203, 204, 205, 206, 207, 208, 209
                };

                new SimpleHelpPane(
                    g_pLanguageMan->GetString(kTooltipStringIds[hitIcon]),
                    this,
                    x,
                    y,
                    5000);
                handled = true;
            }
        }
        break;

    default:
        break;
    }

    return handled;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Implementation notes for this block:

- The direct switch on mouse-up intentionally mirrors UID `0002T2`'s binary body. Do not replace it with `DispatchIconsPaneAction(hitIcon)` unless a later final-source pass proves the raw duplicate is a real source helper call/inlining artifact.
- `PaneMouseEvent`, `MouseEvent_Move`, `MouseEvent_ButtonDown`, `MouseEvent_ButtonUp`, `MouseEvent_Hover`, `HasMouseCapture`, `CaptureMouse`, `ReleaseMouseCapture`, `PointInRect`, and `SimpleHelpPane` are first-draft source-facing names. Their exact spellings should be synchronized with accepted neighboring event/window docs during implementation.
- The coordinate order must remain `HitTestIcon(y, x)` and `PointInRect(y, x, ...)`.
- Tooltip string IDs must remain `202..209`, with timeout `5000`.
- Third-party import directive: not applicable. This target is custom IconsPane UI code, not a vetted staged static third-party embed.

## Final Recommendation

Implemented UID `0002T2` as first-draft C++. Owner, emitter, reconstructability, and range are unchanged. Target score is now `89/91`, the formal C++ body is present, and stale blank-C++ wording is superseded/historicalized.

Generated files were not edited manually. Scoped validators refreshed `auto-generated/NexusTK/ui/panels/IconsPane.cpp`; its header now shows `validator-command-id: 000000006275`, `validator-refreshed-at: 2026-07-04T12:18:16-04:00`, and UID0002T2 now emits `IconsPane::OnMouseEvent` rather than an empty marker.

Do not run lifecycle/report execution commands as B001. This callback stops at `READY_FOR_SUPERVISOR_EXECUTE`.

## Recommended Target Doc Changes

Applied to `by-memory/0x004cf3e0-0x004cf74b.IconsPaneOnMouseEvent.md`:

- Set `COMPLETION:89` and `CONFIDENCE:91`.
- Kept `CANONICAL_OWNER:00006B`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00006B`.
- Inserted the formal C++ block into `RECONSTRUCTION_CPP CODE`.
- Replaced stale current blank-C++ wording with first-draft-present wording and historicalized older blank-C++ notes.
- Added MCP session `60724697` evidence for active IDB, exact function range, vtable data xref, local switch tables, hit-test/highlight callsites, input-lock gate, tooltip constants, and no-route status for `0x004cf7a0`/`0x004cf8e0`.
- Preserved the adjacent compiler-table/raw-helper section and clarified those bytes remain outside this UID.
- Added the direct-switch note: do not collapse mouse-up into a call to UID `00022Q` unless later source-shape evidence proves that relationship.

## Recommended Support Doc Changes

Applied to `by-class/IconsPane.md`:

- Updated the UID `0002T2` method row to say first-draft C++ is present.
- Left class score unchanged at `87/89`; the supervisor did not accept an optional class score bump.
- Preserved caveats for action helper names and exact child allocation of `0x004cf74b-0x004cf7d0`.

Applied to `by-file/IconsPane.md`:

- Updated the source contents list and behavior/data caveats to reflect that `IconsPane::OnMouseEvent` has first-draft C++.
- Repaired stale generated-output wording; scoped validator refresh has made `auto-generated/NexusTK/ui/panels/IconsPane.cpp` current at command `000000006275`.

Applied to `by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md`:

- Updated the UID `0002T2` row and aggregate behavior/data/score notes from behavior-only status to first-draft-present status.
- Kept the physical cluster caveat for exact child allocation of the switch-table/raw-helper gap.

For `by-memory/0x004cf8e0-0x004cf974.IconsPaneActionDispatchRawBody.md`:

- No edit needed. The page already records that it mirrors live `IconsPane::OnMouseEvent`, has no route/xrefs, and may not be needed as a separate callable helper if a later source-shape pass proves it is an unreferenced duplicate.

No manual edits were made to generated files, coverage reports, tool state, validator state, lifecycle/archive files, or supervisor ledgers.

## Score And Metadata Recommendation

Recommended target metadata:

```text
COMPLETION:89
CONFIDENCE:91
CANONICAL_OWNER:00006B
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00006B
```

Rationale for `89/91`:

- First-draft C++ is now justified by current MCP evidence and resolved neighbor helper documentation.
- Exact behavior is strong for the target range.
- Remaining unknowns are source-name quality, exact event type/field names, exact capture/helper class names, and adjacent cluster child coverage.
- This is not final-audit quality and should not be raised into the 95+ range.

## Open Questions With Attempted Resolution

Open question: what are the exact original event struct and enum names?

Attempted resolution: current MCP has no recovered UDT or symbol names. The first-draft block uses `PaneMouseEvent` and `MouseEvent_*` placeholders that preserve the recovered semantics. This is not a blocker to first-draft C++ if the target doc notes the naming caveat.

Open question: should OnMouseEvent call `DispatchIconsPaneAction`?

Attempted resolution: no. Current disassembly shows UID `0002T2` contains its own direct switch and direct helper calls. UID `00022Q` has no code or data xrefs. A source-level call would be less faithful than a direct switch at first-draft stage.

Open question: does the `0x004cf74b-0x004cf7d0` gap block target implementation?

Attempted resolution: no. The gap is outside `sub_4CF3E0` and has separate evidence/caveats. It remains a support coverage task, not a target range blocker.

Open question: are the action helper source names final?

Attempted resolution: no. They are behavior-level names already used by generated lead output for UID `00022Q`. Keep them for consistency, but do not treat them as final-audit recovered names.

## Validator Results

Scoped validators run from `source-3/project-documentation`:

| File | Command ID | Command timestamp | Exit | ok | Generated refresh |
| --- | --- | --- | --- | ---: | --- |
| `by-memory/0x004cf3e0-0x004cf74b.IconsPaneOnMouseEvent.md` | `000000006264` | `2026-07-04T12:07:22-04:00` | `0` | `1` | completed |
| `by-class/IconsPane.md` | `000000006265` | `2026-07-04T12:07:43-04:00` | `0` | `1` | completed |
| `by-file/IconsPane.md` | `000000006267` | `2026-07-04T12:07:59-04:00` | `0` | `1` | completed |
| `by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md` | `000000006268` | `2026-07-04T12:08:18-04:00` | `0` | `1` | completed |
| `by-file/IconsPane.md` final recheck | `000000006275` | `2026-07-04T12:18:16-04:00` | `0` | `1` | completed |

Commands used:

> Executable block R001 was removed from this report and preserved verbatim in [0002T2-IconsPaneOnMouseEvent-source-quality-removed.md](0002T2-IconsPaneOnMouseEvent-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

The by-file validator was rerun after a narrow generated-freshness wording repair; command `000000006275` is the final by-file validation and latest generated refresh.

Generated freshness checked:

- `auto-generated/NexusTK/ui/panels/IconsPane.cpp` now has `validator-command-id: 000000006275`, `validator-refreshed-at: 2026-07-04T12:18:16-04:00`, and `validator-refresh-source: foreground-generated-refresh`.
- UID0002T2 appears in generated `IconsPane.cpp` as `Completion:89 | Confidence:91` with a real `bool IconsPane::OnMouseEvent(const PaneMouseEvent *event)` body, not an empty emitter marker.

Validator-owned side effects reported by the scoped commands included generated C++/coverage refreshes, generated metadata refreshes, research tracker update after UID0002T2 left the not-covered row, projected stats updates, `validator.ini` registry rebuilds, and `tools/validator_autogen_backup/20260704-120727`, `20260704-120730`, `20260704-120733`, `20260704-120747`, `20260704-120751`, `20260704-120753`, `20260704-120803`, `20260704-120807`, `20260704-120809`, `20260704-120823`, `20260704-120826`, `20260704-120829`, `20260704-121821`, `20260704-121825`, and `20260704-121827` backup folders. These were validator-owned side effects, not manual edits.

Known unrelated validator warnings remained: `autogen_children_marker_missing`, `autogen_children_fallback_insert`, and `autogen_emitter_has_no_code` rows for unrelated docs. No target-specific validator failure occurred.

I did not run `execute_report`, dry-run/probing variants, registry lifecycle commands, report moves, archive commands, or manual validator-state repairs. MCP was available during research; no `PAUSED_MCP_UNAVAILABLE` condition occurred.

Lease release proof: `python leaser.py B001 unlease` returned `Success` for `by-class/IconsPane.md`, `by-file/IconsPane.md`, `by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md`, and `by-memory/0x004cf3e0-0x004cf74b.IconsPaneOnMouseEvent.md`; `tools/leaser/Agents/current_leases.md` and `tools/leaser/Agents/Agent-B001/current_leases.md` have no active B001 entries.

## Changed Files

Manual by-* edits:

```text
source-3/project-documentation/by-memory/0x004cf3e0-0x004cf74b.IconsPaneOnMouseEvent.md
source-3/project-documentation/by-class/IconsPane.md
source-3/project-documentation/by-file/IconsPane.md
source-3/project-documentation/by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md
```

Manual report update:

```text
source-3/project-documentation/tools/leaser/Agents/Agent-B001/research/0002T2-IconsPaneOnMouseEvent-source-quality.md
```

No manual edit was made to `by-memory/0x004cf8e0-0x004cf974.IconsPaneActionDispatchRawBody.md`; it was already sufficient.

Validator-owned refresh side effects included generated `auto-generated/NexusTK/ui/panels/IconsPane.cpp`, generated `auto-generated/-ag-*` reports/metadata, generated research tracker/coverage, projected stats, `validator.ini`, and `tools/validator_autogen_backup/*` backup folders as reported above. I did not manually edit generated files, coverage reports, validator state, lifecycle/archive files, or supervisor ledgers.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validated this exact report artifact before implementation callback.
- [x] Target doc updated: `by-memory/0x004cf3e0-0x004cf74b.IconsPaneOnMouseEvent.md`.
- [x] Support docs updated or excluded with reason: `by-class/IconsPane.md`, `by-file/IconsPane.md`, and `by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md` updated; raw dispatch support page excluded because it already carried the no-route/direct-switch caveat at sufficient detail.
- [x] Current target state and evidence recorded: target now `89/91`, owner/emitter `00006B`, reconstructable TRUE, first-draft C++ present, MCP session `60724697` evidence incorporated, generated UID0002T2 body refreshed.
- [x] Claim And Incorporation Ledger rows `B001-0002T2-C01` through `B001-0002T2-C17` updated from `proposed` to `applied`, `already-present`, or `excluded-with-reason`.
- [x] Metadata/score applied: target `COMPLETION:89`, `CONFIDENCE:91`; owner/emitter/reconstructable unchanged.
- [x] Owner/emitter/source placement preserved: `CANONICAL_OWNER:00006B`, `EMITTER_UIDS:00006B`, source route through `by-class/IconsPane.md` -> `by-file/IconsPane.md` -> `NexusTK/ui/panels/IconsPane.cpp`.
- [x] Range/split recommendation applied: UID `0002T2` remains `0x004cf3e0-0x004cf74b`; adjacent `0x004cf74b-0x004cf7d0` switch-table/raw-helper bytes remain excluded from this UID.
- [x] Formal C++ inserted into the target `RECONSTRUCTION_CPP CODE` block; no body-only snippet was used.
- [x] Third-party import directive confirmed not applicable; target is custom IconsPane UI code.
- [x] Target facts incorporated: four event cases, vertical-first `(y, x)` coordinate order, capture-state behavior, selected-icon state, input-lock gate, direct action switch, tooltip IDs `202..209`, timeout `5000`, and cleanup on mouse-up.
- [x] Helper/source-quality facts preserved: `HitTestIcon` and `SetIconHighlight` remain calls; action helper names are behavior-level; event/capture/tooltip names are inferred first-draft names.
- [x] Stale/historical target notes repaired: old blank-C++ blocker wording is superseded/historicalized.
- [x] Negative evidence preserved: no recovered local `IconsPane` UDT, no original event enum/type names, no direct xrefs to `0x004cf7a0` or `0x004cf8e0`, no pointer refs to the no-route raw helpers, and no proof that UID `0002T2` calls UID `00022Q`.
- [x] Wave2/Wave3 material not used or incorporated.
- [x] Open questions preserved with attempted resolution: exact event struct/enum names, capture helper names, final action helper names, and adjacent gap child allocation remain non-final but do not block first-draft C++ or the `89/91` target score.
- [x] Scoped validators run for every changed by-* file; command metadata recorded above.
- [x] Generated refresh checked: `auto-generated/NexusTK/ui/panels/IconsPane.cpp` command id `000000006275`, refreshed `2026-07-04T12:18:16-04:00`, UID0002T2 body present.
- [x] Manual supervisor-owned coverage/tracker text not needed; generated tracker/coverage refreshed through validator.
- [x] Forbidden lifecycle boundary maintained: B001 did not run `execute_report`, dry-run/probing variants, registry lifecycle commands, report moves, archive commands, or manual generated/coverage/tool-state edits.

Implementation callback pass (accepted and applied):

- [x] Supervisor sent explicit implementation callback naming this report and accepted scope.
- [x] B001 checked current leases, leased/renewed the four edited by-* docs as B001, and released them after validation/report update; the shared and B001 lease reports have no active B001 entries.
- [x] Target metadata updated to `COMPLETION:89`, `CONFIDENCE:91`; `CANONICAL_OWNER:00006B`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00006B` preserved.
- [x] Exact formal C++ inserted into target doc.
- [x] Target sections updated at report-level detail: `Status`, `Address Range`, `Behavior`, `Action Dispatch`, `Adjacent Compiler Tables And Raw Helper`, `Evidence`, `Reconstruction Notes`, `Score Rationale`, and `Changes`.
- [x] Target negative evidence and caveats preserved.
- [x] Target range and adjacent-byte exclusion preserved.
- [x] `by-class/IconsPane.md` updated; class score left unchanged because optional bump was not accepted.
- [x] `by-file/IconsPane.md` updated.
- [x] `by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md` updated.
- [x] `by-memory/0x004cf8e0-0x004cf974.IconsPaneActionDispatchRawBody.md` excluded with reason: already sufficiently records no-route retained duplicate evidence and mirrors live `OnMouseEvent`.
- [x] No manual generated, project-level generated, coverage-report, validator-state, tool-state, lifecycle/archive, or supervisor-ledger edits.
- [x] Report ledger updated with callback verification states.
- [x] Report checklist updated with proof.
- [x] Scoped validators run for all changed by-* docs; command IDs `000000006264`, `000000006265`, `000000006267`, `000000006268`, and final by-file recheck `000000006275`, each exit `0`, `ok:1`.
- [x] Generated refresh checked; generated `IconsPane.cpp` is current at command `000000006275` and contains UID0002T2 body.
- [x] No target-specific validator blockers remain. Unrelated marker/emitter warnings are recorded in `Validator Results`.
- [x] No accepted item remains unapplied.
- [x] Ready to return `READY_FOR_SUPERVISOR_EXECUTE`; B001 did not run or probe `execute_report`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000006278","destination_path":"executed-b-agent-research/B001/0002T2-IconsPaneOnMouseEvent-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/0002T2-IconsPaneOnMouseEvent-source-quality.md","timestamp":"2026-07-04T12:23:28-04:00","uid":"0002T2"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002T2-IconsPaneOnMouseEvent-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0002T2-IconsPaneOnMouseEvent-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002T2"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
