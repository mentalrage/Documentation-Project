** TARGET-REPORT-UID:0001BV **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# 0001BV ObjectImageButtonPaneCore Source-Quality Report


## Target

- Target UID: [UID:0001BV]
- Target path: `by-memory/0x00520820-0x00520a90.ObjectImageButtonPaneCore.md`
- Assigned report path: `tools/leaser/Agents/Agent-B002/research/0001BV-ObjectImageButtonPaneCore-source-quality.md`
- Queue source: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`, row `85/88`, combined `86.5`, `Reports:0`.
- Current classification: reconstructable source-bearing `ObjectImageButtonPane` method cluster under the object-image controls source family.

## Current Target State

- Current metadata: `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000M3`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000M3`, blank formal C++.
- Current contents: constructor `0x00520820`, key handler `0x00520870`, paint handler `0x00520910`, and highlight setter `0x00520a80`.
- Current stale assumption: the page and ignored ledger treat `0x00520a90-0x00520aa5` as post-core alignment. Live MCP disproves that: `0x00520a90-0x00520a97` is a real two-instruction getter for the same `+0x14c` highlight byte.
- Related current support: [UID:00009N] `by-class/ObjectImageButtonPane.md` is `86/88`; [UID:0000M3] `by-file/ObjectImageControlPane.md` is `88/88`; [UID:0001BU] base methods are `90/91` with `ObjectStatusBlob` source-facing naming and formal C++.

## Evidence Checked

- Required workflow/structure: `goal.md`, `ntk-b-agent-workflow` skill, B-agent workflow reference, score-blocker audit standard, report template, and `by-structure.md` ownership/C++/IDA MCP discipline sections.
- Current by-* docs: target page, `by-class/ObjectImageButtonPane.md`, `by-file/ObjectImageControlPane.md`, `by-class/ObjectImageControlPane.md`, `by-memory/0x00520540-0x00520816.ObjectImageControlPane.md`, `by-class/ObjectStatusBlob.md`, `by-file/HeadSelectDialog.md`, `by-memory/0x00551030-0x005520e5.HeadSelectDialogCore.md`, destructor child pages [UID:0003M9]/[UID:0003MA], `by-memory/0x0061ec10-0x0061fa3c.MerchantMenuDialogReadOnlyData.md`, `by-memory/-ignored.md`, `by-memory/0x00520aa5-0x00520abb.SharedDialogDefaultDestructorThunks.md`, and `by-file/SpecializedButtonPanes.md`.
- Generated/read-only leads: `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-coverage-report-by-memory.md`, `auto-generated/-ag-class-coverage.md`, `project-level/-auto-completion-stats.md`, `project-level/-resolved.md`, and generated `auto-generated/NexusTK/ui/controls/ObjectImageControlPane.cpp`.
- Old report search terms included `0001BV`, `0x00520820`, `00520820`, `ObjectImageButtonPaneCore`, `sub_520820`, `520A90`, `0x00520a90`, and `ObjectImageButtonPane`. Relevant matches: executed B002 [UID:0003MA] scalar-wrapper report and executed B015 [UID:0003M9] thunk report. Both are useful destructor-routing leads but carry `needs-revalidation` footers for target UID registry issues and both predate the live `0x00520a90` getter check.
- IDA MCP session: current `idb_list` session `1f24c222`, `server_health` status `ok`, `auto_analysis_ready:true`, `hexrays_ready:true`, imagebase `0x400000`.
- MCP calls were bounded and schema-current: `lookup_funcs`, `decompile`, `disasm` with `max_instructions <= 80` and paging, `xrefs_to limit=20`, and `get_bytes` over small exact regions.

## Positive Evidence Summary

- `lookup_funcs` confirms exact source-function starts/sizes: `0x00520820` size `0x4f`, `0x00520870` size `0x9d`, `0x00520910` size `0x169`, `0x00520a80` size `0x10`, and omitted `0x00520a90` size `0x7`.
- Constructor disassembly calls base `0x00520540` at `0x00520830`, installs `ObjectImageButtonPane` vtable heads `0x0061f764`, `0x0061f7cc`, and `0x0061f7fc`, writes inherited state at `+0xff/+0x102`, and clears `+0x14c`.
- `xrefs_to` confirms constructor is called from `HeadSelectDialog::PopulateHeadButtons` at `0x00551479`; highlight setter callers are `0x0055149a`, `0x0055209a`, and `0x005520c3`.
- `OnKeyPress` accepts keyboard message byte `+4 == 8` and narrowed key Space/Enter, flashes action/category state `11` then `10`, sleeps `0x85` ms, repaints, and dispatches action slot `0x48`.
- `OnPaint` uses the `+0x14c` highlight byte to optionally draw `off_61E3F4`/`off_61E40C` overlay art via `g_pEPFLib`, then uses `g_pNewHumanImageLib` / current IDA `dword_67A760` to measure and draw the copied `ObjectStatusBlob` at `+0x108`.
- `SetButtonHighlight` writes `this+0x14c`; `0x00520a90` returns `this+0x14c`. These two functions prove the field should be modeled as one source-facing `m_buttonHighlight` or `m_highlighted` byte with setter/getter accessors.
- `0x004242f0` returns constant `11` and is a vtable slot helper for this class family; it remains outside the target range but belongs in class-level method inventory.

## Negative Evidence Summary

- The current ignored-ledger claim that `0x00520a90-0x00520aa5` is all alignment is false. Exact bytes are getter `8a 81 4c 01 00 00 c3`, then `0xcc` padding through `0x00520aa0`, then unrelated/stale Boost-labeled jump `0x00520aa0-0x00520aa5`, then shared dialog destructor thunks at [UID:0001BW].
- No xrefs were found to `0x00520a90`; that does not make it padding. IDA models it as a function and its body directly reads the target-owned highlight byte.
- The old broad `0x00520820-0x00520c9a` range remains rejected: destructor adjustor thunks [UID:0003M9] and scalar deleting destructor [UID:0003MA] are compiler-generated no-code support, not source-authored target bodies.
- `SpecializedButtonPanes.cpp` remains rejected as owner. Its current page already states `ObjectImageButtonPane` is historical/provisional there and better placed with [UID:0000M3] `ObjectImageControlPane`.
- [UID:00025U] `.rdata` vtable aggregate is physical evidence only; vtables should regenerate from class declarations and should not own this source-bearing method cluster.
- `HeadSelectDialog` is a consumer/caller. It creates and toggles the buttons but does not own the `ObjectImageButtonPane` class implementation.

## Heuristic / Inference Reanalysis And Validation

- Direct semantic owner should be [UID:00009N] `ObjectImageButtonPane`, not file [UID:0000M3]. `by-structure.md` says method groups should use the narrowest true owner when supported; [UID:00009N] is `86/88` and clears the gate, and its emitter route reaches [UID:0000M3].
- Source file placement remains [UID:0000M3] `NexusTK/ui/controls/ObjectImageControlPane.cpp`. The constructor's immediate base call, shared descriptor layout, sibling destructor-size comparison, and current `SpecializedButtonPanes` exclusion all favor the object-image control family.
- Range should be repaired to include the getter: recommended half-open range `0x00520820-0x00520a97`, with filename/title rename to `0x00520820-0x00520a97.ObjectImageButtonPaneCore.md`. Do not create a separate child page solely for the 7-byte getter; it is contiguous source-bearing class behavior and uses the same field as the setter.
- Correct ignored subrange after repair: only `0x00520a97-0x00520aa0` is padding. `0x00520aa0-0x00520aa5` is a separate stale-Boost-named jump/glue function, and `0x00520aa5-0x00520abb` remains [UID:0001BW].
- Best source-facing field names: `m_buttonHighlight` or `m_highlighted` for `+0x14c`; `m_objectStatus` remains inherited at `+0x108..+0x14b` from `ObjectImageControlPane`; source-facing global `g_pNewHumanImageLib` should replace raw `dword_67A760` in prose/C++.
- Constructor writes at `+0xff/+0x102` are likely inherited focus/input/control visual flags. They should be documented as inherited control-state initialization rather than promoted to new `ObjectImageButtonPane` fields.
- The class type-code helper `0x004242f0` returning `11` is source-facing class behavior but outside this by-memory page. Keep it in `by-class/ObjectImageButtonPane.md` and do not paste its code into this target's formal C++.
- Wave2/Wave3/simroot generated names were treated only as leads. No generated source was used as proof; the current generated `ObjectImageControlPane.cpp` is a state check showing [UID:0001BV] is still an empty emitter marker.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00520820-0x0052086f` | part of [UID:0001BV] | Constructor, forwards `ObjectStatusBlob`/bounds to base and initializes button state | TRUE | recommend [UID:00009N] | current target `85/88` | Source-authored. |
| `0x00520870-0x0052090d` | part of [UID:0001BV] | `OnKeyPress` Space/Enter action flash/dispatch | TRUE | recommend [UID:00009N] | current target `85/88` | Source-authored. |
| `0x00520910-0x00520a79` | part of [UID:0001BV] | `OnPaint`, optional highlight overlay and centered human-image draw | TRUE | recommend [UID:00009N] | current target `85/88` | Source-authored. |
| `0x00520a80-0x00520a90` | part of [UID:0001BV] | `SetButtonHighlight(bool)` writes `+0x14c` | TRUE | recommend [UID:00009N] | current target `85/88` | Source-authored. |
| `0x00520a90-0x00520a97` | currently omitted from [UID:0001BV] | `IsButtonHighlighted()` / getter for `+0x14c` | TRUE | recommend [UID:00009N] | unrepresented | Add to target by range rename/extension. |
| `0x00520a97-0x00520aa0` | currently in ignored ledger | padding | FALSE | none | n/a | Correct ignored ledger if callback scope permits. |
| `0x00520aa0-0x00520aa5` | currently in ignored ledger | stale-Boost-named jump/glue, not target source | FALSE/other support | none | n/a | Do not absorb into target. |
| `0x00520ae7-0x00520afd` | [UID:0003M9] | destructor adjustor thunks | FALSE | none | `86/92` | Already split compiler glue. |
| `0x00520c60-0x00520c9b` | [UID:0003MA] | scalar deleting destructor wrapper | FALSE | none | `86/92` | Already split compiler glue. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00520820` | code xref `0x00551479` from `HeadSelectDialog::PopulateHeadButtons` | HeadSelect creates selectable head-grid buttons. |
| `0x00520a80` | code xrefs `0x0055149a`, `0x0055209a`, `0x005520c3` | HeadSelect highlights selected button and clears old highlight in action handler. |
| `0x00520a90` | no xrefs | Retained/unreferenced getter; still source-bearing because it reads the same class field and is IDA-modeled code. |
| `0x00520910` | data xref `0x0061f7a8` | `ObjectImageButtonPane` paint vtable slot. |
| `0x00520870` | data xref `0x0061f7d4` | `ObjectImageButtonPane` key handler vtable slot. |
| `0x004242f0` | data xref `0x0061f7c4` plus sibling button-control vtable refs | shared constant type-code helper; class method inventory, not this target body. |
| `0x0061f764/0x0061f7cc/0x0061f7fc` | constructor refs at `0x00520835`, `0x0052083d`, `0x00520847` | constructor installs complete/secondary/tertiary vtable views. |

## Ranked Ownership Analysis

### 1. [UID:00009N] ObjectImageButtonPane

- Evidence for: every target function is a member method or accessor of this class; vtable refs and constructor stores name `ObjectImageButtonPane`; class page clears the gate at `86/88`; by-structure requires the narrowest true owner.
- Evidence against: class-level declaration C++ is still blank, and exact inherited field names are not final. These are C++/detail caveats, not ownership blockers.
- Decision: recommend `CANONICAL_OWNER:00009N` and `EMITTER_UIDS:00009N` for [UID:0001BV] after range repair.

### 2. [UID:0000M3] ObjectImageControlPane

- Evidence for: final source file family, base constructor call, source path `NexusTK/ui/controls/ObjectImageControlPane.cpp`, current owner/emitter route works.
- Evidence against: it is the file/source-family owner, not the direct semantic owner of the method cluster.
- Decision: keep as source-file route through [UID:00009N], not direct target owner.

### 3. [UID:0000JT]/[UID:000062] HeadSelectDialog

- Evidence for: constructor and highlight setter callers are in HeadSelectDialog.
- Evidence against: consumer-only; it allocates and toggles `ObjectImageButtonPane` instances but does not own class implementation.
- Decision: reject as owner; keep as caller/use evidence.

### 4. [UID:0000NY] SpecializedButtonPanes

- Evidence for: old generated/historical references and current cross-reference row list this class as historical/provisional.
- Evidence against: current page explicitly moves `ObjectImageButtonPane` out of the bucket; base class/source-family and object-image descriptor dependencies are stronger.
- Decision: reject as owner; no support edit needed unless supervisor wants the row range updated to include the getter.

## Source Placement

- Recommended source file/class route: [UID:0001BV] -> [UID:00009N] `ObjectImageButtonPane` -> [UID:0000M3] `NexusTK/ui/controls/ObjectImageControlPane.cpp`.
- This keeps the button next to its base `ObjectImageControlPane`, reuses `ObjectStatusBlob` and `g_pNewHumanImageLib` support, and avoids creating a one-off `ObjectImageButtonPane.cpp` solely for a small subclass.
- Rejected placement: `HeadSelectDialog.cpp` because it is a caller; `SpecializedButtonPanes.cpp` because current support docs treat that as historical/provisional; read-only/vtable aggregate because it is generated-binary support only.

## Range / Split / Padding / Reclassification Analysis

- Current target end `0x00520a90` is not source-complete. `lookup_funcs 0x00520a90` returns `sub_520A90`, size `0x7`; decompile returns `return this[332];`; disassembly is `mov al,[ecx+14Ch]; retn`.
- Recommended target rename/extension: `by-memory/0x00520820-0x00520a97.ObjectImageButtonPaneCore.md`.
- No new child page is recommended for `0x00520a90-0x00520a97`; the getter is tiny, contiguous, source-bearing, and completes the setter/field story.
- Correct the stale ignored row `0x00520a90-0x00520aa5`: replace with a smaller padding row `0x00520a97-0x00520aa0` and, if supervisor scope allows, add a note that `0x00520aa0-0x00520aa5` is separate stale-Boost-labeled glue before [UID:0001BW].
- Existing compiler-glue splits [UID:0003M9] and [UID:0003MA] remain correct and should not be merged back into [UID:0001BV].

## First-Draft C++ Recommendation

- Eligible for draft C++: yes, after range repair. The target is reconstructable, will have an emitter route through [UID:00009N] to [UID:0000M3], and the current average score already exceeds `85`.
- Recommended formal insertion text for the repaired target's `RECONSTRUCTION_CPP CODE` block:

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
ObjectImageButtonPane::ObjectImageButtonPane(const ObjectStatusBlob *objectStatus,
                                             const RectBounds *bounds)
    : ObjectImageControlPane(objectStatus, bounds),
      m_buttonHighlight(false)
{
    m_acceptsKeyboardActivation = true;
    m_pressedVisualState = 0;
}

bool ObjectImageButtonPane::OnKeyPress(const KeyEvent &event)
{
    const char key = std::use_facet<std::ctype<char> >(std::locale()).narrow(
        event.virtualKey,
        event.fallbackKey);

    if (event.message != KeyEvent::KeyDown || (key != ' ' && key != '\r')) {
        return false;
    }

    ControlManager *manager = GetControlManager();
    const int slot = manager->FindControlSlot(this);

    manager->SetControlState(slot, 11);
    g_pDisplayContext->Present();
    Sleep(0x85);

    manager->SetControlState(-1, 10);
    g_pDisplayContext->Present();
    manager->DispatchAction(slot, 11);
    return true;
}

void ObjectImageButtonPane::OnPaint()
{
    EPFTileContext tileContext;
    RectBounds sourceBounds;
    RectBounds destBounds;

    tileContext.InitTileContext();

    if (m_buttonHighlight) {
        g_pEPFLib->GetFrameBounds(L"NEWBUTT.EPF", 0, &sourceBounds);

        const int width = sourceBounds.right - sourceBounds.left;
        const int height = sourceBounds.bottom - sourceBounds.top;
        const int x = ((m_bounds.left + m_bounds.right) / 2) - (width / 2);
        const int y = ((m_bounds.top + m_bounds.bottom) / 2) - (height / 2);

        destBounds.left = x;
        destBounds.top = y;
        destBounds.right = x + width;
        destBounds.bottom = y + height;

        DrawTileFrame(&tileContext, &sourceBounds, &destBounds, L"NEWBUTT.PAL", 0);
    }

    g_pNewHumanImageLib->CalculateBounds(&m_objectStatus,
                                         NewHumanImageLib::HeadButtonRender,
                                         &sourceBounds);

    const int width = sourceBounds.right - sourceBounds.left;
    const int height = sourceBounds.bottom - sourceBounds.top;
    const int x = ((m_bounds.left + m_bounds.right) / 2) - (width / 2);
    const int y = ((m_bounds.top + m_bounds.bottom) / 2) - (height / 2);

    destBounds.left = x;
    destBounds.top = y;
    destBounds.right = x + width;
    destBounds.bottom = y + height;

    g_pNewHumanImageLib->Draw(this,
                              &destBounds,
                              &m_objectStatus,
                              NewHumanImageLib::HeadButtonRender);
}

void ObjectImageButtonPane::SetButtonHighlight(bool highlighted)
{
    m_buttonHighlight = highlighted;
}

bool ObjectImageButtonPane::IsButtonHighlighted() const
{
    return m_buttonHighlight;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

- Source-facing names that are inferred, not symbol-proven: `m_buttonHighlight`, `m_acceptsKeyboardActivation`, `m_pressedVisualState`, `KeyEvent`, `ControlManager`, `g_pDisplayContext`, `HeadButtonRender`, `DrawTileFrame`, `NEWBUTT.EPF`, and `NEWBUTT.PAL`. These names should be accepted as first-draft source names only if the implementation callback records them as inferred aliases tied to exact IDA labels (`dword_67A754`, `dword_67A7CC`, `dword_67A744`, `off_61E3F4`, `off_61E40C`).
- Reason not higher/final: exact local class declaration and inherited control-state field names remain inferred. The code is first-draft reconstruction-quality, not final 95+ source audit.

## Recommended Target Doc Changes

- Rename/extend target path to `by-memory/0x00520820-0x00520a97.ObjectImageButtonPaneCore.md`.
- Change metadata to `COMPLETION:89`, `CONFIDENCE:91`, `CANONICAL_OWNER:00009N`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00009N`.
- Update summary/function table to include the getter `0x00520a90-0x00520a97`.
- Replace the stale "alignment gap after `0x00520a90`" claim with exact boundary evidence: getter through `0x00520a97`, padding `0x00520a97-0x00520aa0`, stale-Boost jump/glue `0x00520aa0-0x00520aa5`, and [UID:0001BW] starting `0x00520aa5`.
- Add live MCP session `1f24c222` evidence for function sizes, xrefs, decompilation, disassembly, and bytes.
- Add formal first-draft C++ above if supervisor accepts the inferred names.

## Recommended Support Doc Changes

- `by-class/ObjectImageButtonPane.md`: update method inventory with getter `0x00520a90-0x00520a97`, add direct owner route for [UID:0001BV], add `m_buttonHighlight` field at `+0x14c`, and update the core range to `0x00520820-0x00520a97`. Recommended score `87/90` if this detail is incorporated.
- `by-file/ObjectImageControlPane.md`: update proposed contents row from core `0x00520820-0x00520a90` to `0x00520820-0x00520a97`; note [UID:0001BV] now routes through [UID:00009N] while still landing in this file.
- `by-memory/-ignored.md`: correct stale `0x00520a90-0x00520aa5` padding row to exclude the getter. Recommended replacement is padding `0x00520a97-0x00520aa0`; do not claim `0x00520a90-0x00520a97` is ignored.
- `by-file/SpecializedButtonPanes.md`: optional cross-reference-only update to the historical row range `0x00520820-0x00520a97`; no owner/score change needed.
- `by-memory/0x0061ec10-0x0061fa3c.MerchantMenuDialogReadOnlyData.md`: no required edit; current vtable facts already cover the relevant slots at same-or-greater detail.
- No manual `-coverage-report.md` edit by B002. Any manual coverage correction remains supervisor-owned; generated `-ag-*` reports should refresh from source doc validation after callback.

## Score And Metadata Recommendation

- Current: `85/88`, owner/emitter [UID:0000M3], reconstructable true, no code.
- Recommended after accepted implementation: `89/91`, `CANONICAL_OWNER:00009N`, `EMITTER_UIDS:00009N`, `RECONSTRUCTABLE:TRUE`, formal C++ populated.
- Why score rises: live MCP resolves exact function boundaries, current xrefs, decompiled behavior, the previously omitted getter, field offset `+0x14c`, source owner route, source file placement, and first-draft C++ readiness.
- Why not 95+: several source names remain inferred rather than symbol-proven, especially inherited key-event/control-manager fields and render helper enum names.
- No new child pages are recommended. The only range repair is widening/renaming the target to include a contiguous 7-byte source getter.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C1 | Target should extend/rename from `0x00520820-0x00520a90` to `0x00520820-0x00520a97`. | High | MCP `lookup_funcs/decompile/disasm/get_bytes` for `0x00520a90`. | `by-memory/0x00520820-0x00520a97.ObjectImageButtonPaneCore.md` metadata/title/status/range notes | applied | Applied by direct rename. Scoped validator `000000004776` (`2026-07-02T18:10:48-04:00`) exited 0/ok 1 and reported `path_update` old -> new. |
| C2 | `0x00520a90-0x00520a97` is a getter for `+0x14c`, not padding. | High | Decompile `return this[332]`; disasm `mov al,[ecx+14Ch]; retn`; no xrefs. | target, `by-class/ObjectImageButtonPane.md`, `by-memory/-ignored.md` | applied | Target inventory, class method list, and ignored rows updated. Validators `000000004776`, `000000004777`, and `000000004779` exited 0/ok 1. |
| C3 | Direct owner should be [UID:00009N], emitter [UID:00009N], source file route [UID:0000M3]. | High | vtable/class evidence; by-structure direct-owner rule; class/file scores. | target metadata, class/file prose | applied | Target metadata now `CANONICAL_OWNER:00009N` and `EMITTER_UIDS:00009N`; file/class route prose synchronized. Validator `000000004776` reported canonical-owner update to `00009N` and completion/confidence `89/91`. |
| C4 | Destructor thunks/wrapper stay split and non-emitting. | High | Existing [UID:0003M9]/[UID:0003MA] docs plus MCP bytes/xrefs. | target split notes and link-only support references | already-present plus link sync applied | Target split notes preserve the non-emitting destructor/glue split. Link-only support pages were updated to the renamed target and validators `000000004782` through `000000004785` exited 0/ok 1. |
| C5 | `m_buttonHighlight` at `+0x14c` is the best source-facing field alias. | Medium-high | Constructor clear, setter write, getter read, paint branch, HeadSelect callers. | target/class layout notes and C++ | applied | Target C++ and evidence notes use `m_buttonHighlight`; class layout notes document `+0x14c m_buttonHighlight / m_highlighted`. Validators `000000004776` and `000000004777` exited 0/ok 1. |
| C6 | First-draft formal C++ is now eligible and is supplied as exact `RECONSTRUCTION_CPP CODE` marker/block insertion text, using documented inferred aliases. | Medium-high | Combined score gate, emitter route, MCP behavior, support docs. | target formal C++ block | applied | Formal `RECONSTRUCTION_CPP CODE` block populated in the renamed target. Validator `000000004776` exited 0/ok 1 and generated `auto-generated/NexusTK/ui/controls/ObjectImageControlPane.cpp` refreshed with [UID:0001BV] code under validator header `000000004781`. |
| C7 | Current ignored `0x00520a90-0x00520aa5` padding claim is stale. | High | Live bytes/function lookup. | `by-memory/-ignored.md` | applied | Ignored ledger now preserves only `0x00520a97-0x00520aa0` padding and `0x00520aa0-0x00520aa5` stale-Boost jump/glue. Validator `000000004779` exited 0/ok 1. |
| C8 | `SpecializedButtonPanes` remains historical/provisional only. | High | Current support page already rejects object-image ownership. | `by-file/SpecializedButtonPanes.md` optional support note | already-present plus optional range sync applied | Ownership rejection was already present; optional historical row range/link sync to `0x00520820-0x00520a97` was applied without owner change. Validator `000000004780` exited 0/ok 1. |

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Gate 1 passed for SHA256 `82BD35C39CB744CF5F17400BE2C0EC12762A7C5721BE2953A030BE58308D1B62`.
- [x] Target doc updated: renamed/extended `by-memory/0x00520820-0x00520a90.ObjectImageButtonPaneCore.md` to `by-memory/0x00520820-0x00520a97.ObjectImageButtonPaneCore.md`; title, status, function inventory, evidence, split notes, metadata, and formal C++ updated.
- [x] Support doc updated: `by-class/ObjectImageButtonPane.md` now includes the getter row, `+0x14c m_buttonHighlight`, direct owner/emitter route, corrected range, and `87/90`.
- [x] Support doc updated: `by-file/ObjectImageControlPane.md` now has corrected core range and source route through [UID:00009N]/[UID:0000M3].
- [x] Support doc updated: `by-memory/-ignored.md` no longer claims `0x00520a90-0x00520aa5` is all padding; it retains true padding/support rows only.
- [x] Optional support doc updated: `by-file/SpecializedButtonPanes.md` range/link sync only; no owner change.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score changes applied: target `85/88 -> 89/91`, owner/emitter `0000M3 -> 00009N`, reconstructable remains true.
- [x] First-draft C++ applied as exact formal `RECONSTRUCTION_CPP CODE` marker/block insertion text for `ObjectImageButtonPane` constructor, `OnKeyPress`, `OnPaint`, `SetButtonHighlight`, and `IsButtonHighlighted`.
- [x] Split/rename/new-child rule satisfied: no new child pages; target range rename/extension only.
- [x] Historical/stale assumptions preserved: old broad `0x00520820-0x00520c9a` remains rejected; [UID:0003M9]/[UID:0003MA] remain compiler glue; `0x00520a90-0x00520aa5` all-padding row is stale and replaced.
- [x] Validators run after callback from `source-3/project-documentation`: scoped file validators covered every changed by-* doc.
- [x] Generated refresh completed: queue status reached `queued:0, processing:0`; generated C++ and auto-generated coverage reflect [UID:0001BV] emitting through [UID:00009N]/[UID:0000M3].
- [x] B002 did not run `execute_report` / lifecycle commands or hand-edit manual coverage reports, generated reports, validator state, queues, archives, or supervisor ledgers. Validator-managed side effects are recorded below.

## Validator Results

- IDA MCP availability: available and used via session `1f24c222`.
- Scoped validators run from `source-3/project-documentation` with `--apply --queue-timeout 240`; each exited `0` with `ok:1`.
- `000000004776` at `2026-07-02T18:10:48-04:00`: `python .\tools\validator.py --mode file --file by-memory\0x00520820-0x00520a97.ObjectImageButtonPaneCore.md --apply --queue-timeout 240`; path update old -> new, owner/emitter/score update, formal C++ accepted. Warnings: missing ref UIDs `0003M9`/`0003MA` from existing split references; generated refresh deferred.
- `000000004777` at `2026-07-02T18:10:52-04:00`: `by-class\ObjectImageButtonPane.md`; score update accepted. Warnings: existing missing ref UIDs `0003M9`/`0003MA`; generated refresh deferred.
- `000000004778` at `2026-07-02T18:10:54-04:00`: `by-file\ObjectImageControlPane.md`; route/range sync accepted. Warnings: existing missing ref UIDs `0003M9`/`0003MA`; generated refresh deferred.
- `000000004779` at `2026-07-02T18:10:56-04:00`: `by-memory\-ignored.md`; stale ignored range corrected. Warnings: pre-existing missing-ref rows; generated refresh deferred.
- `000000004780` at `2026-07-02T18:11:09-04:00`: `by-file\SpecializedButtonPanes.md`; optional historical range/link sync accepted. Warnings: pre-existing missing-ref rows; generated refresh deferred.
- `000000004781` at `2026-07-02T18:11:16-04:00`: `by-memory\0x00520540-0x00520816.ObjectImageControlPane.md`; link-only support sync accepted; generated refresh deferred.
- `000000004782` at `2026-07-02T18:11:24-04:00`: `by-memory\0x00520abb-0x00520e2b.MenuDialogDestructorThunks.md`; link-only support sync accepted. Warnings: existing missing-ref rows; generated refresh deferred.
- `000000004783` at `2026-07-02T18:11:34-04:00`: `by-memory\0x00520ae7-0x00520afd.ObjectImageButtonPaneDestructorThunks.md`; link sync accepted and validator inserted blank header/UID mapping for [UID:0003M9]. Warnings: existing missing ref UID `0003MA`; generated refresh deferred.
- `000000004784` at `2026-07-02T18:11:41-04:00`: `by-memory\0x00520c60-0x00520c9b.ObjectImageButtonPaneScalarDeletingDestructor.md`; link sync accepted and validator inserted blank header/UID mapping for [UID:0003MA]; generated refresh deferred.
- `000000004785` at `2026-07-02T18:11:43-04:00`: `by-memory\0x0061ec10-0x0061fa3c.MerchantMenuDialogReadOnlyData.md`; link-only support sync accepted; generated refresh deferred.
- Queue status commands `000000004786`, `000000004787`, and `000000004788` showed generated refresh drain from queued/processing to `queued:0, processing:0`.
- Generated-refresh state: `auto-generated/NexusTK/ui/controls/ObjectImageControlPane.cpp` refreshed with validator header `000000004781` at `2026-07-02T18:11:16-04:00` and includes [UID:0001BV] formal code from `by-memory/0x00520820-0x00520a97.ObjectImageButtonPaneCore.md`; `auto-generated/-ag-memory-coverage.md` shows [UID:0001BV] range `0x00520820-0x00520a97`, owner/emitter `00009N`, reconstructable `yes`, generated output path populated.
- Validator side effects noted but not hand-edited: `by-memory/-coverage-report.md` received a validator `uid_link_update` from old target link to new target link during command `000000004776`, and project-level projected stats were refreshed by validators.

## Changed Files

- `by-memory/0x00520820-0x00520a97.ObjectImageButtonPaneCore.md` (renamed from `by-memory/0x00520820-0x00520a90.ObjectImageButtonPaneCore.md`)
- `by-class/ObjectImageButtonPane.md`
- `by-file/ObjectImageControlPane.md`
- `by-memory/-ignored.md`
- `by-file/SpecializedButtonPanes.md`
- `by-memory/0x00520540-0x00520816.ObjectImageControlPane.md`
- `by-memory/0x00520abb-0x00520e2b.MenuDialogDestructorThunks.md`
- `by-memory/0x00520ae7-0x00520afd.ObjectImageButtonPaneDestructorThunks.md`
- `by-memory/0x00520c60-0x00520c9b.ObjectImageButtonPaneScalarDeletingDestructor.md`
- `by-memory/0x0061ec10-0x0061fa3c.MerchantMenuDialogReadOnlyData.md`
- `tools/leaser/Agents/Agent-B002/research/0001BV-ObjectImageButtonPaneCore-source-quality.md`

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004795","destination_path":"executed-b-agent-research/B002/0001BV-ObjectImageButtonPaneCore-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0001BV-ObjectImageButtonPaneCore-source-quality.md","timestamp":"2026-07-02T18:19:15-04:00","uid":"0001BV"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
