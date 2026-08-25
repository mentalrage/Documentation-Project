** TARGET-REPORT-UID:0004C1 **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B007 Research Report: [UID:0004C1] IMECompositionPaneConstructor

Assignment ID: `B007-report-0004C1-IMECompositionPaneConstructor-20260630`

Original mode: report-only research. Callback implementation update on 2026-07-01 applied the accepted details to target/support `by-*` documentation under short `B007` leases. No subagents were spawned.

Report path: `tools/leaser/Agents/Agent-B007/research/0004C1-IMECompositionPaneConstructor-source-quality.md`

## Target

- Primary target: [UID:0004C1] `by-memory/0x004e7380-0x004e744d.IMECompositionPaneConstructor.md`
- Current owner: [UID:00006G] `by-class/IMECompositionPane.md`
- Current source route: [UID:00006G] -> [UID:0000K5] `by-file/IMEPanes.md`
- Aggregate family page: [UID:000189] `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md`
- Related ordinary destructor: [UID:0004C2] `by-memory/0x004e7450-0x004e746f.IMECompositionPaneOrdinaryDestructor.md`
- Related scalar deleting destructor: [UID:00031J] `by-memory/0x004e86c0-0x004e8715.IMECompositionPaneScalarDeletingDestructor.md`

## Current Target State

Current target metadata:

- `COMPLETION:82`
- `CONFIDENCE:88`
- `CANONICAL_OWNER:00006G`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:` blank
- `EMITTER_POSITION_OPTIONAL:` blank
- Formal `RECONSTRUCTION_CPP CODE` block is blank

The target already has the correct narrow semantic owner and source route, but it still contains stale split-callback wording: `EMITTER_UIDS` stays blank until child-specific C++ is accepted, and formal constructor C++ remains for a later pass. Under the current score-blocker standard, that future-work wording is the blocker to resolve in this report.

## MCP Availability And Provenance

IDA MCP was available and used. This is not fallback-only research.

- Endpoint: `http://127.0.0.1:13337/mcp`
- Active session from MCP request `215` `idb_list`: `supervisor_resume_20260629`
- Active IDB: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Worker process: pid/worker pid `24256`
- MCP request `217` `server_health`: `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, strings cache ready.

MCP calls used or preserved for this pass:

- `idb_list`, `server_health`, `lookup_funcs`, `decompile`, `get_bytes`, `xrefs_to`
- Constructor-focused requests preserved from the current session: `lookup_funcs` request `102`, `decompile 0x004e7380` request `103`, `get_bytes` request `106`, constructor `xrefs_to` request `107`, vtable `xrefs_to` request `108`.
- Helper/root rechecks from this continuation: `lookup_funcs` request `225`; `decompile 0x00544c70` request `226`; `decompile 0x00544d30` request `227`; `decompile 0x004b7c50` request `228`; `decompile 0x004e81b0` request `229`.

## Evidence Checked

Current documentation read:

- [UID:0004C1] target page.
- [UID:00006G] `IMECompositionPane`.
- [UID:0000K5] `IMEPanes`.
- [UID:000189] `IMEPaneFamily`.
- [UID:00018A] `IMECompositionSetCompositionString`.
- [UID:0004C3] `IMECompositionPaneOnMouseEvent`.
- [UID:0004C5] `IMECompositionPaneOnPaint`.
- [UID:0004C4] `IMECompositionPaneOnKeyEvent`.
- [UID:0004C6] `IMECompositionPaneGetCompositionWidth`.
- [UID:0004C2] `IMECompositionPaneOrdinaryDestructor`.
- [UID:00031J] `IMECompositionPaneScalarDeletingDestructor`.
- [UID:0001EA] `PaneCore`, [UID:0002V7] `PaneSetMode`, [UID:0001VH] `PaneLayout`.
- [UID:0000T6] `MainUiLayerSlots`, [UID:00029O] `0x0069b378-0x0069b380.MainUiLayerSlotsTail`, and [UID:0002H7] `ApplicationStartup`.
- `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and generated `auto-generated/NexusTK/input/IMEPanes.cpp`.
- Relevant `by-structure.md` metadata and C++ gate sections: direct semantic owner, emitter route, by-memory formal C++ limited to the page's own range, and `[[CHILDREN]]` insertion.

Existing report searches were run by UID, address range, target name, constructor name, owner candidates, and IME pane family terms across active B-agent reports, central executed reports, legacy executed report folders, and archives. Relevant leads:

- `executed-b-agent-research/B008/0000K5-IMEPanes-empty-emitter-family-source-quality.md`: created/incorporated the split route for [UID:0004C1] but did not accept this constructor's formal body.
- `executed-b-agent-research/B003/00018A-ime-composition-set-composition-string-source-quality.md`: resolved `compositionCursorX` and `compositionText[256]`.
- `executed-b-agent-research/B009/0004C3-IMECompositionPaneOnMouseEvent-source-quality.md`: used the constructor as drag-active initialization evidence.
- `executed-b-agent-research/B008/0004C5-IMECompositionPaneOnPaint-source-quality.md`: used constructor/sibling field context.
- Active B010 report and current implemented page for [UID:0004C2]: parallel ordinary destructor/source route evidence.

Old reports were used as leads only. Important constructor claims below were rechecked against current docs and current MCP evidence.

## Current MCP Function Evidence

### Constructor Body

MCP `lookup_funcs` request `102` and preserved session evidence identify:

- `0x004e7380 -> sub_4E7380`, size `0xcd`.
- `0x004e744d` is not a function.
- `0x004e7450 -> sub_4E7450`, the ordinary destructor successor.

MCP `get_bytes` request `106` confirms:

- Five `0xcc` bytes precede the constructor from `0x004e737b-0x004e7380`, after [UID:0004C0].
- The constructor body occupies `0x004e7380-0x004e744d`.
- Three `0xcc` bytes follow from `0x004e744d-0x004e7450`, before [UID:0004C2].

MCP `decompile 0x004e7380` request `103`:

```cpp
int __thiscall sub_4E7380(int this)
{
  __m128i v3; // [esp+10h] [ebp-20h] BYREF
  int v4; // [esp+2Ch] [ebp-4h]

  sub_544460((char *)this, 0); /*0x4e73b3*/
  v4 = 0; /*0x4e73c3*/
  *(_DWORD *)this = &IMECompositionPane::`vftable'; /*0x4e73cd*/
  *(_DWORD *)(this + 160) = &IMECompositionPane::`vftable'; /*0x4e73d3*/
  *(_DWORD *)(this + 164) = &IMECompositionPane::`vftable'; /*0x4e73dd*/
  *(_DWORD *)(this + 248) = 0; /*0x4e73e7*/
  memset((void *)(this + 252), 0, 0x200u); /*0x4e73f1*/
  *(_BYTE *)(this + 764) = 0; /*0x4e73ff*/
  sub_4B7C50(&v3, 0, 0, 0, 0); /*0x4e7409*/
  sub_544C70(this, &v3, 0, 0, (_DWORD *)unk_69B37C); /*0x4e7421*/
  sub_544D30((void *)this, 0, 0); /*0x4e742c*/
  return this; /*0x4e7433*/
}
```

Constructor facts:

- `sub_544460(this, 0)` is the base `Pane(0)` construction path.
- Local `v4 = 0` is compiler exception/unwind state and not source logic.
- Vtable stores at `0x004e73cd`, `0x004e73d3`, and `0x004e73dd` install primary, secondary, and tertiary `IMECompositionPane` views. These are compiler output from the class declaration, not source statements.
- `this+0xf8` is set to zero: `compositionCursorX = 0`.
- `memset(this+0xfc, 0, 0x200)` clears `compositionText[256]`.
- `this+0x2fc` is set to zero: `compositionDragActive = false`.
- The constructor does not initialize `compositionDragStartY +0x300`, `compositionDragStartX +0x304`, or `compositionDragSavedMode +0x308`; [UID:0004C3] initializes those on mouse-down before reading them.
- `sub_4B7C50(&v3, 0, 0, 0, 0)` creates a zero rectangle.
- `sub_544C70(this, &v3, 0, 0, unk_69B37C)` attaches the pane to a layer/context with no parent pane.
- `sub_544D30(this, 0, 0)` registers/sets event handler ordering with no before/after pane.

### Helper And Global Name Rechecks

MCP request `225`:

- `0x00544c70 -> sub_544C70`, size `0x34`.
- `0x00544d30 -> sub_544D30`, size `0x3f`.
- `0x004b7c50 -> sub_4B7C50`, size `0x1f`.
- `0x004e81b0 -> sub_4E81B0`, size `0x283`.

MCP request `226` decompiles `sub_544C70`:

- If a parent pane argument is non-null, it uses the parent's cached layer at `parent +0xa8`.
- Otherwise it uses the explicit layer argument.
- It calls `sub_4F0630` and writes the chosen layer to `this+0xa8`.
- Current [UID:0001EA] and [UID:0001VH] docs identify this as `Pane::AddToLayer(const RectBounds *bounds, int zOrder, Pane *parentPane, Layer *layer)`.

MCP request `227` decompiles `sub_544D30`:

- It passes `this+0xa0` and optional neighbor handler views to dispatcher state at `unk_67AB30`.
- Current Pane/EventDispatcher docs identify this as the `Pane::SetPaneOrder` / dispatcher-order helper.

MCP request `228` decompiles `sub_4B7C50`:

- It writes the four dwords in `left, top, right, bottom` order.
- Current RectBounds support identifies this as `InitRectBounds(RectBounds *bounds, int left, int top, int right, int bottom)`.

[UID:00029O] and [UID:0000T6] document `0x0069b37c` / `dword_69B37C` as the Main UI layer slot currently named `g_mainUiLayerSlots.fpsOverlayLayerContext` in accepted [UID:0002H7] source. The constructor's layer argument should therefore use that accepted support name, not raw `unk_69B37C`.

### Root IME Attach Path

MCP request `229` decompiles `IMEPane::HandleIMEMessage` at `0x004e81b0`. For event case `0x0c`, the root handler allocates `780` bytes, inlines the same `IMECompositionPane` construction sequence, calls:

- `sub_544460(v6, 0)`,
- the same three vtable stores,
- `memset(v6 + 252, 0, 0x200)`,
- `v6[764] = 0`,
- `sub_4B7C50(&v14, 0, 0, 0, 0)`,
- `sub_544C70(v6, &v14, 0, 0, unk_69B37C)`,
- `sub_544D30(v6, 0, 0)`,
- then stores the new pane pointer in root `IMEPane` slot `this[23]`.

This matters for source placement:

- The constructor body itself is source-authored `IMECompositionPane::IMECompositionPane()`.
- The root pointer assignment `IMEPane::compositionPane = new IMECompositionPane` belongs to [UID:0004CE] / `IMEPane::HandleIMEMessage`, not to the constructor formal C++ block.
- The no direct xref to `0x004e7380` is not no-code proof; the source constructor body is also emitted/inlined inside the root event handler's allocation path.

### Reachability And Vtable Evidence

MCP request `107` reports no direct xrefs to `0x004e7380`. This is negative evidence and should be documented as a reachability caveat only. It does not support padding/no-code because:

- `lookup_funcs` models a real `0xcd` constructor body at `0x004e7380`.
- The body contains nontrivial source field initialization and layer/order registration.
- MCP request `229` shows active inline duplication of the same constructor sequence in `IMEPane::HandleIMEMessage` event `0x0c`.
- Vtable xrefs tie the same `IMECompositionPane` vtables to constructor, destructor, root inline construction, and scalar wrapper paths.

MCP request `108` vtable refs:

- `0x0061c3ec` refs include constructor store `0x004e73cd`, ordinary destructor `0x004e7450`, root handler inline construction `0x004e8238`, and scalar wrapper `0x004e86c6`.
- `0x0061c438` refs include constructor store `0x004e73d3`, ordinary destructor `0x004e7456`, root handler inline construction `0x004e823e`, and scalar wrapper `0x004e86cc`.
- `0x0061c468` refs include constructor store `0x004e73dd`, ordinary destructor `0x004e7460`, root handler inline construction `0x004e8248`, and scalar wrapper `0x004e86d6`.

## Empty Emitter Family Inventory

In-scope target:

| UID | Current state | Disposition |
| --- | --- | --- |
| [UID:0004C1] `IMECompositionPaneConstructor` | `82/88`, `RECONSTRUCTABLE:TRUE`, owner [UID:00006G], blank `EMITTER_UIDS`, blank formal C++ | Resolve now: set `88/91`, set `EMITTER_UIDS:00006G`, insert constructor formal C++. |

Adjacent current composition-pane children:

| UID | Current state | Scope decision |
| --- | --- | --- |
| [UID:00018A] `SetCompositionString` | `88/91`, emits through [UID:00006G], formal C++ populated | Already present support for `compositionCursorX` and `compositionText[256]`; no edit required except optional cross-reference synchronization. |
| [UID:0004C3] `OnMouseEvent` | `88/91`, emits through [UID:00006G], formal C++ populated | Already present support for drag fields; no edit required except optional constructor support note already covered by this report. |
| [UID:0004C5] `OnPaint` | `88/91`, emits through [UID:00006G], formal C++ populated | Already present support for text/cursor paint consumption; no edit required. |
| [UID:0004C2] `OrdinaryDestructor` | Current page now `88/91`, emits formal empty destructor through [UID:00006G] | Already resolved by B010; use as lifecycle sibling evidence only. |
| [UID:00031J] `ScalarDeletingDestructor` | `86/90`, emits wrapper proof comment through [UID:00006G] | Already present scalar-wrapper proof; no edit required for this constructor. |
| [UID:0004C4] `OnKeyEvent` | `82/89`, blank emitter/formal C++ | Adjacent future child; outside this assignment. Its sole forwarding route to [UID:00018A] does not block the constructor disposition. |
| [UID:0004C6] `GetCompositionWidth` | `82/89`, blank emitter/formal C++ | Adjacent future child; outside this assignment. It confirms `compositionCursorX` only. |

Support pages:

- [UID:00006G] already emits through [UID:0000K5] and contains `[[CHILDREN]]`.
- [UID:0000K5] already owns the IME pane source route.
- [UID:000189] already lists [UID:0004C1] in the split/source-placement table.
- [UID:0001EA], [UID:0001VH], [UID:0000T6], and [UID:00029O] already carry the accepted helper/global names needed by this target. No support metadata change is required there.

## Heuristic And Inference Reanalysis

The target is eligible to emit. It is a source-authored class constructor, not padding, not a raw helper, not a compiler-only thunk, and not an aggregate body.

Resolved source-shape decisions:

- Base construction is represented as `: Pane(0)`.
- Vtable writes are omitted as compiler output.
- EH/unwind local `v4 = 0` is omitted as compiler output.
- `compositionCursorX = 0`, `memset(compositionText, 0, sizeof(compositionText))`, and `compositionDragActive = false` are source statements because they map directly to field initialization.
- `compositionDragStartY`, `compositionDragStartX`, and `compositionDragSavedMode` must not be initialized in this constructor draft. Current binary does not write them here, and [UID:0004C3] initializes them on mouse-down before use.
- `InitRectBounds` plus `AddToLayer` is the source-facing form for the zero-bounds attach path.
- The fourth argument is `g_mainUiLayerSlots.fpsOverlayLayerContext`, because current MainUiLayerSlots docs map `0x0069b37c` to that accepted support name.
- `SetPaneOrder(NULL, NULL)` is the source-facing form for `sub_544D30(this, 0, 0)`.
- The root `IMEPane` storage write after allocation is outside this range and belongs to `IMEPane::HandleIMEMessage`; do not include it in this constructor.

Rejected source-shape alternatives:

- Marker-only/no-code: rejected because the body is modeled, source-authored, and now has a valid owner/emitter route.
- Direct by-file emission: rejected because [UID:00006G] is the direct class owner; [UID:0000K5] is the source root route.
- Aggregate-only emission under [UID:000189]: rejected because [UID:000189] is a source-order container with `[[CHILDREN]]`.
- `SetBounds(&rect, 0)` for `sub_544C70`: rejected for this constructor. Current MCP and Pane docs identify `0x00544c70` as `Pane::AddToLayer`, while inherited `SetBounds` is a different helper at `0x00544bd0` and is used by sibling runtime positioning methods.
- Using raw `unk_69B37C`: rejected because current MainUiLayerSlots docs provide an accepted source-facing support name.
- Adding root `g_pIMEPane` pointer writes: rejected because the constructor does not write [UID:0000R7] `g_pIMEPane` or the root child slot; root allocation/lifetime is in `IMEPane::HandleIMEMessage`.

## Ranked Ownership And Source Placement

1. [UID:00006G] `IMECompositionPane` -> [UID:0000K5] `IMEPanes`: selected.
   - The body constructs `IMECompositionPane`, installs its vtable views, initializes its fields, and is duplicated inline when root `IMEPane` creates the composition child.
   - [UID:00006G] already has the formal class shell and `[[CHILDREN]]`.
   - [UID:0000K5] is the established source file route into `NexusTK/input/IMEPanes.cpp`.

2. [UID:0000K5] `IMEPanes` as direct owner: rejected as too broad.
   - It is the file route, not the narrow semantic owner.

3. [UID:000189] `IMEPaneFamily`: rejected as direct owner.
   - It is a non-body source-order aggregate and should keep only `[[CHILDREN]]` plus route/split evidence.

4. [UID:00006H] `IMEPane`: rejected as direct owner.
   - `IMEPane::HandleIMEMessage` allocates and stores the child, but the constructor body initializes `IMECompositionPane` state.

5. [UID:0000A2] `Pane`, [UID:0000T6] `MainUiLayerSlots`, `Layer`, `EventDispatcher`, or RectBounds owners: rejected.
   - These are dependencies/helper owners only.

6. No-owner/non-emitting: rejected.
   - Current evidence supports exact owner, exact route, and formal C++ readiness.

## Score And Metadata Recommendation

Recommended [UID:0004C1] metadata:

- `COMPLETION:88`
- `CONFIDENCE:91`
- `CANONICAL_OWNER:00006G` unchanged
- `RECONSTRUCTABLE:TRUE` unchanged
- `EMITTER_UIDS:00006G`
- `EMITTER_POSITION_OPTIONAL:` unchanged/blank

Before rationale:

- `82/88` reflected the exact range, owner, fields, and route, but left the formal constructor body and emitter blank under stale child-pass wording.

After rationale:

- Completion should rise to `88` because the exact range, padding, modeled size, constructor body, field writes, helper names, root inline duplication, owner/emitter route, rejected alternatives, and formal C++ are resolved.
- Confidence should rise to `91` because current MCP directly supports the function boundary, body, vtable parity, helper roles, root inline duplication, and source route. It should not rise above low-final range because direct xrefs to the out-of-line constructor entry are absent and exact original spellings for helper/global declarations remain inferred support names.
- Combined score `(88 + 91) / 2 = 89.5` clears the current by-structure source/C++ gate once `EMITTER_UIDS:00006G` is set.

Support score recommendations:

- [UID:00006G] `IMECompositionPane`: keep `88/91`; add constructor row/evidence if accepted.
- [UID:0000K5] `IMEPanes`: keep `90/88`; add constructor child/generation note if accepted.
- [UID:000189] `IMEPaneFamily`: keep `87/90`; update [UID:0004C1] row text to `88/91` formal constructor-ready if accepted.
- [UID:0000T6], [UID:00029O], [UID:0001EA], [UID:0001VH], [UID:00018A], [UID:0004C3], [UID:0004C5], [UID:0004C2], [UID:00031J]: no score or metadata change required for this constructor callback.

## Formal C++ Recommendation

Recommended exact formal `RECONSTRUCTION_CPP CODE` content for [UID:0004C1]:

```cpp
IMECompositionPane::IMECompositionPane()
    : Pane(0)
{
    compositionCursorX = 0;
    memset(compositionText, 0, sizeof(compositionText));
    compositionDragActive = false;

    RectBounds initialBounds;
    InitRectBounds(&initialBounds, 0, 0, 0, 0);
    AddToLayer(&initialBounds, 0, NULL, g_mainUiLayerSlots.fpsOverlayLayerContext);
    SetPaneOrder(NULL, NULL);
}
```

Formal block notes:

- Do not include vtable stores, EH state, `return this`, or raw helper labels.
- Do not initialize `compositionDragStartY`, `compositionDragStartX`, or `compositionDragSavedMode`.
- Do not include root `IMEPane` pointer assignment or allocation logic.
- Use `NULL` to match current generated IME/Panes style where pointer nulls are already present; `nullptr` is not required for this source-family style.

## Generated Output Expectation

Current generated state:

- `auto-generated/NexusTK/input/IMEPanes.cpp` currently emits [UID:00006G] class shell and populated children such as [UID:00018A], [UID:0004C3], [UID:0004C5], [UID:0004C2], and [UID:00031J].
- Searches for `UID:0004C1`, `IMECompositionPane::IMECompositionPane`, and `0x004e7380` found no constructor body in current generated output because [UID:0004C1] still has blank `EMITTER_UIDS` and blank formal C++.

After accepted implementation and scoped validation with `--wait-generated`, generated `auto-generated/NexusTK/input/IMEPanes.cpp` should contain a [UID:0004C1] marker and the constructor body above, routed through [UID:00006G] into [UID:0000K5]. There should be no [UID:0004C1] empty-emitter marker.

## Target And Support Doc Recommendations

### [UID:0004C1] `by-memory/0x004e7380-0x004e744d.IMECompositionPaneConstructor.md`

Required if accepted:

- Set `COMPLETION:88`.
- Set `CONFIDENCE:91`.
- Set `EMITTER_UIDS:00006G`.
- Insert the formal constructor C++ block exactly as recommended.
- Replace stale "formal C++ remains for a child-specific pass" wording with MCP evidence:
  - function `sub_4E7380`, size `0xcd`;
  - half-open range `0x004e7380-0x004e744d`;
  - five-byte predecessor and three-byte successor `0xcc` padding;
  - base `Pane(0)`;
  - vtable stores as compiler output;
  - `compositionCursorX`, `compositionText[256]`, and `compositionDragActive` writes;
  - no constructor writes to drag-start/saved-mode fields;
  - `InitRectBounds`, `AddToLayer`, `SetPaneOrder`, and `g_mainUiLayerSlots.fpsOverlayLayerContext`;
  - zero direct xrefs caveat;
  - active inline duplication in `IMEPane::HandleIMEMessage` case `0x0c`;
  - rejected alternatives.

### [UID:00006G] `by-class/IMECompositionPane.md`

Required if accepted:

- Keep `[[CHILDREN]]`.
- Keep metadata unchanged.
- Update constructor method row/evidence to say [UID:0004C1] is `88/91`, formal C++ populated, constructs `Pane(0)`, clears `compositionCursorX`, `compositionText[256]`, and `compositionDragActive`, attaches zero bounds to `g_mainUiLayerSlots.fpsOverlayLayerContext`, and calls `SetPaneOrder(NULL, NULL)`.
- Add that drag-start Y/X/saved-mode fields are initialized by [UID:0004C3] mouse-down, not by the constructor.

### [UID:0000K5] `by-file/IMEPanes.md`

Required if accepted:

- Keep metadata unchanged.
- Update the `IMECompositionPane` proposed contents/evidence to include [UID:0004C1] as an emitting constructor child routed through [UID:00006G], with formal constructor C++ expected in generated `NexusTK/input/IMEPanes.cpp`.

### [UID:000189] `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md`

Required if accepted:

- Keep aggregate metadata unchanged.
- Update the [UID:0004C1] row in covered ranges/split plan to `88/91`, formal constructor C++ populated, exact zero-bounds `AddToLayer` and `SetPaneOrder` route, and root handler inline duplication evidence.

### Already-present / no-edit support

- [UID:0000T6] `MainUiLayerSlots` and [UID:00029O] `MainUiLayerSlotsTail`: already provide `g_mainUiLayerSlots.fpsOverlayLayerContext`.
- [UID:0001EA] `PaneCore`, [UID:0001VH] `PaneLayout`: already provide `Pane::AddToLayer`, `Pane::SetPaneOrder`, `Pane(0)`, and layer pointer layout.
- [UID:00018A], [UID:0004C3], [UID:0004C5], [UID:0004C2], [UID:00031J]: already provide field/paint/mouse/destructor sibling support. No implementation edit required unless the supervisor wants extra cross-link wording.
- [UID:0004C4] and [UID:0004C6]: adjacent blank-emitter children remain future targets; do not edit them in this callback unless explicitly assigned.

## Claim And Incorporation Ledger

| Claim | Evidence | Destination | Action | Verification state |
| --- | --- | --- | --- | --- |
| [UID:0004C1] is an exact modeled constructor body at `0x004e7380-0x004e744d`, size `0xcd`, not padding or an aggregate. | MCP `lookup_funcs` request `102`; `get_bytes` request `106`; successor destructor at `0x004e7450`; padding before/after. | [UID:0004C1] metadata/evidence/range notes; [UID:000189] split row. | incorporate | applied: [UID:0004C1] Evidence records range/size/padding; [UID:000189] covered/split rows updated. |
| The constructor source shape is `IMECompositionPane::IMECompositionPane() : Pane(0)`. | MCP `decompile 0x004e7380` request `103` calls `sub_544460(this, 0)` before derived initialization; Pane docs identify `0x00544460` constructor. | [UID:0004C1] formal C++; [UID:00006G] method row/evidence. | incorporate | applied: formal C++ inserted on [UID:0004C1]; [UID:00006G] method row/evidence updated. |
| Vtable stores at `0x004e73cd`, `0x004e73d3`, `0x004e73dd` are compiler output and should not be handwritten. | MCP decompile request `103`; vtable xrefs request `108`; class declaration already owns virtual layout. | [UID:0004C1] Reconstruction Notes and formal C++ omission. | incorporate | applied: [UID:0004C1] Reconstruction Notes identify vtable/EH/return-this as compiler output omitted from C++. |
| Field initialization is `compositionCursorX = 0`, clear `compositionText[256]`, and `compositionDragActive = false`. | MCP decompile request `103`; [UID:00006G] observed-state table; [UID:00018A], [UID:0004C3], [UID:0004C5] sibling docs. | [UID:0004C1] Behavior/Evidence/Formal C++; [UID:00006G] constructor row. | incorporate | applied: [UID:0004C1] Behavior/Evidence/formal C++ and [UID:00006G] row/evidence include all three writes. |
| Constructor does not initialize `compositionDragStartY`, `compositionDragStartX`, or `compositionDragSavedMode`. | MCP decompile request `103` only writes `+0x2fc`; [UID:0004C3] initializes `+0x300/+0x304/+0x308` on mouse-down. | [UID:0004C1] Reconstruction Notes; [UID:00006G] evidence note. | incorporate | applied: [UID:0004C1] Behavior notes non-initialization; [UID:00006G] evidence note says mouse-down owns those fields. |
| `sub_4B7C50`, `sub_544C70`, and `sub_544D30` should be expressed as `InitRectBounds`, `AddToLayer`, and `SetPaneOrder`. | MCP requests `225-228`; current [UID:0001EA], [UID:0001VH], and RectBounds support docs. | [UID:0004C1] formal C++; support notes in [UID:00006G]/[UID:0000K5]/[UID:000189]. | incorporate | applied: formal C++ uses accepted helper names; all three support docs record helper route. |
| The layer argument `0x0069b37c` should be `g_mainUiLayerSlots.fpsOverlayLayerContext`. | [UID:00029O], [UID:0000T6], [UID:0002H7]; MCP decompile uses `unk_69B37C`. | [UID:0004C1] formal C++; no MainUiLayerSlots edit required. | incorporate | applied: [UID:0004C1] formal C++ and support notes use `g_mainUiLayerSlots.fpsOverlayLayerContext`; MainUiLayerSlots docs left untouched as already sufficient. |
| No direct xrefs to `0x004e7380` are a reachability caveat, not no-code proof. | MCP `xrefs_to` request `107`; positive function/body/vtable evidence; root inline duplication in request `229`. | [UID:0004C1] Evidence/Reconstruction Notes/Rejected Alternatives/Score Rationale. | incorporate | applied: [UID:0004C1] Evidence and Score Rationale preserve zero-xref caveat and reject no-code. |
| Root `IMEPane::HandleIMEMessage` inlines the constructor sequence and owns root child pointer assignment outside this constructor range. | MCP `decompile 0x004e81b0` request `229`; [UID:000189] root handler row. | [UID:0004C1] root attach/source-placement notes; [UID:0000K5] optional generation note. | incorporate | applied: [UID:0004C1] Evidence/Reconstruction Notes, [UID:0000K5] evidence note, and [UID:000189] rows mention root inline duplication and keep root pointer assignment out of constructor. |
| Correct owner/emitter is [UID:00006G] -> [UID:0000K5]. | Current target/class/file/aggregate docs; class `[[CHILDREN]]`; vtable and field evidence. | [UID:0004C1] metadata; [UID:00006G], [UID:0000K5], [UID:000189] support updates. | incorporate | applied: [UID:0004C1] `EMITTER_UIDS:00006G`; support docs updated with same route. |
| Metadata should improve from `82/88`, blank emitter to `88/91`, `EMITTER_UIDS:00006G`. | Resolved body/source/helper/owner/C++ blockers; current by-structure code gate. | [UID:0004C1] metadata and score rationale. | incorporate | applied: [UID:0004C1] metadata and Score Rationale updated. |
| Generated `IMEPanes.cpp` should contain UID0004C1 constructor after callback validation. | Current generated file lacks UID0004C1 due blank emitter; route exists through class/file. | Validator/generated freshness checklist. | incorporate | applied: generated `auto-generated/NexusTK/input/IMEPanes.cpp` header is `validator-command-id: 000000003224`, `validator-refreshed-at: 2026-07-01T03:54:15-04:00`, newer than final validator command `000000003222`; file contains UID0004C1 `IMECompositionPane::IMECompositionPane()` and no UID0004C1 empty marker. |
| [UID:00006G], [UID:0000K5], [UID:000189] need support text updates but no score changes. | Support route already clears gate; current target improvement is child-specific. | Support docs and implementation checklist. | incorporate | applied: support docs changed; their metadata scores were left unchanged. |
| [UID:0000T6], [UID:00029O], [UID:0001EA], [UID:0001VH], [UID:00018A], [UID:0004C3], [UID:0004C5], [UID:0004C2], [UID:00031J] are already-present support evidence for this target. | Current docs read; no contradictory gap found. | Report ledger/checklist; no edit unless supervisor requests extra cross-links. | already-present | already-present: no contradiction found during callback; no extra edits made to these support pages. |
| [UID:0004C4] and [UID:0004C6] remain adjacent future blank-emitter children and are outside this constructor assignment. | Current pages read; goal assignment is [UID:0004C1]. | Report inventory only. | not-applicable | not-applicable: callback scope stayed on [UID:0004C1] and required support docs only. |

## Implementation Tracking Checklist

Callback implementation update: supervisor accepted this report and assigned implementation on 2026-07-01. Items below are checked with destination/proof for supervisor verification.

- [x] Lease [UID:0004C1] target and the accepted support docs only when ready to edit immediately. Proof: leased `by-memory/0x004e7380-0x004e744d.IMECompositionPaneConstructor.md`, `by-class/IMECompositionPane.md`, `by-file/IMEPanes.md`, and `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md` as `B007` immediately before editing.
- [x] Update [UID:0004C1] metadata to `COMPLETION:88`, `CONFIDENCE:91`, and `EMITTER_UIDS:00006G`; preserve owner/reconstructable/position. Proof: [UID:0004C1] metadata changed; `CANONICAL_OWNER:00006G`, `RECONSTRUCTABLE:TRUE`, and blank `EMITTER_POSITION_OPTIONAL` preserved.
- [x] Insert exact [UID:0004C1] formal constructor C++. Proof: inserted this exact formal block in [UID:0004C1]:

```cpp
IMECompositionPane::IMECompositionPane()
    : Pane(0)
{
    compositionCursorX = 0;
    memset(compositionText, 0, sizeof(compositionText));
    compositionDragActive = false;

    RectBounds initialBounds;
    InitRectBounds(&initialBounds, 0, 0, 0, 0);
    AddToLayer(&initialBounds, 0, NULL, g_mainUiLayerSlots.fpsOverlayLayerContext);
    SetPaneOrder(NULL, NULL);
}
```

- [x] Update [UID:0004C1] prose with MCP-backed range/body/padding/helper/root-inline/negative-xref/rejected-alternative evidence. Proof: [UID:0004C1] Behavior, Evidence, Reconstruction Notes, Score Rationale, and Changes updated.
- [x] Update [UID:00006G] `IMECompositionPane.md` constructor method row/evidence, preserve `[[CHILDREN]]`, and do not disturb existing [UID:00018A], [UID:0004C3], [UID:0004C5], [UID:0004C2], or [UID:00031J] incorporated details. Proof: constructor row/evidence/Changes updated; formal class shell and existing sibling rows retained.
- [x] Update [UID:0000K5] `IMEPanes.md` proposed contents/evidence for [UID:0004C1] constructor emission. Proof: `IMECompositionPane` proposed-contents row, Evidence Notes, and Changes updated without score changes.
- [x] Update [UID:000189] `IMEPaneFamily.md` [UID:0004C1] split row with `88/91`, formal constructor C++ populated, helper route, and root inline duplication. Proof: Covered Ranges row, Evidence Notes, Split / Source Placement Plan row, and Changes updated.
- [x] Do not edit [UID:0004C4] or [UID:0004C6] during this callback unless the supervisor expands scope. Proof: no edits made to those adjacent child pages.
- [x] Treat [UID:0000T6], [UID:00029O], [UID:0001EA], [UID:0001VH], [UID:00018A], [UID:0004C3], [UID:0004C5], [UID:0004C2], and [UID:00031J] as already-present support unless the supervisor explicitly requests cross-link-only wording. Proof: no direct contradiction found; no edits made to these already-present support pages.
- [x] Run scoped validators from `source-3/project-documentation` for each changed `by-*` file using `python .\tools\validator.py --mode file --file <relative path> --apply --wait-generated --queue-timeout 240`. Proof: all four exited `0` with `ok: 1`: `000000003219` at `2026-07-01T03:53:00-04:00` for [UID:0004C1], `000000003220` at `2026-07-01T03:53:20-04:00` for [UID:00006G], `000000003221` at `2026-07-01T03:53:34-04:00` for [UID:0000K5], and `000000003222` at `2026-07-01T03:53:48-04:00` for [UID:000189].
- [x] Confirm generated `auto-generated/NexusTK/input/IMEPanes.cpp` header is equal/newer than the final validator command metadata and contains [UID:0004C1] `IMECompositionPane::IMECompositionPane()` with no [UID:0004C1] empty marker. Proof: generated header is `validator-command-id: 000000003224`, `validator-refreshed-at: 2026-07-01T03:54:15-04:00`, newer than final scoped validator command `000000003222`; `rg` found UID0004C1 marker and constructor at lines 172-173 and no UID0004C1 empty marker.
- [x] Release all leases immediately after the edit/validator batch. Proof: `python .\tools\leaser\leaser.py B007 unlease ...` reported `Rejected[No active lease]` for all four by-* paths because the short leases had already expired; shared `tools/leaser/Agents/current_leases.md` then showed `No active leases.`
- [x] During callback, update this report ledger/checklist with applied/already-present/excluded proof for every accepted claim. Proof: ledger verification states and this checklist updated during callback; validator, generated-output, and lease-release rows are checked with proof.
- [x] Return validator command, command_id, command_timestamp, exit code, ok count, warnings, generated freshness, changed files, leases, score/metadata before/after, and blockers. Proof: included in final B007 checkpoint after lease release.

## Blockers

No blocker remains for supervisor validation.

- MCP is available and current.
- The target range/body is exact.
- The direct owner and emitter route are established.
- The formal constructor C++ is implementation-ready.
- Adjacent blank-emitter children [UID:0004C4] and [UID:0004C6] are outside this constructor assignment and do not block [UID:0004C1].

Implementation-callback validators were run after the accepted by-* edits, all from `source-3/project-documentation` with `--apply --wait-generated --queue-timeout 240`, and all exited `0` with `ok: 1`:

- `python .\tools\validator.py --mode file --file by-memory/0x004e7380-0x004e744d.IMECompositionPaneConstructor.md --apply --wait-generated --queue-timeout 240`: `command_id: 000000003219`, `command_timestamp: 2026-07-01T03:53:00-04:00`.
- `python .\tools\validator.py --mode file --file by-class/IMECompositionPane.md --apply --wait-generated --queue-timeout 240`: `command_id: 000000003220`, `command_timestamp: 2026-07-01T03:53:20-04:00`.
- `python .\tools\validator.py --mode file --file by-file/IMEPanes.md --apply --wait-generated --queue-timeout 240`: `command_id: 000000003221`, `command_timestamp: 2026-07-01T03:53:34-04:00`.
- `python .\tools\validator.py --mode file --file by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md --apply --wait-generated --queue-timeout 240`: `command_id: 000000003222`, `command_timestamp: 2026-07-01T03:53:48-04:00`.

Generated `auto-generated/NexusTK/input/IMEPanes.cpp` was refreshed to `validator-command-id: 000000003224`, `validator-refreshed-at: 2026-07-01T03:54:15-04:00`, which is newer than the final scoped validator command. It contains the [UID:0004C1] `IMECompositionPane::IMECompositionPane()` marker/body and no [UID:0004C1] empty marker.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/0004C1-IMECompositionPaneConstructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/0004C1-IMECompositionPaneConstructor-source-quality.md","timestamp":"2026-07-01T03:59:17","uid":"0004C1"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
