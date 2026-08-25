** TARGET-REPORT-UID:0002DT **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B003-goal2-fittingroom-listpane-slot-geometry-source-quality-0002DT-0002DP-0002DU-20260618

Agent: Agent-B003

Targets:

- [UID:0002DT] `by-memory/0x00420950-0x00420b60.FittingRoomListPaneSlotRectRawHelpers.md`
- [UID:0002DP] `by-memory/0x00420b60-0x00420cf9.FittingRoomListPaneHitTestSlot.md`
- [UID:0002DU] `by-memory/0x00420d50-0x00420dd5.FittingRoomListPaneSlotLayoutRawHelpers.md`

Report-only output. No by-* docs, generated reports, generated source, IDA DB, or `by-memory/-coverage-report.md` were edited.

## Finalized Report / Current Recommendation

Keep the three target pages source-bearing under [UID:000053][FittingRoomListPane](../../../../by-class/FittingRoomListPane.md), emitted through [UID:0000JE][FittingRoom](../../../../by-file/FittingRoom.md) / `NexusTK/cashshop/FittingRoom.cpp`. The class/file route is still the best source placement: the geometry uses `FittingRoomListPane` display mode, list scroll/list-slot behavior, and the fitting-room input/paint cluster, while the broader file is the correct implementation unit.

Do not reclassify the target cluster as generic UI geometry, `FittingRoomScrollPane`, `ItemCatalog`, `FittingRoomDialogItemState`, or `FittingEquipmentState`. Those are dependencies or neighboring consumers, not owners for these helper bodies.

Recommended scores:

| UID | Current | Recommended | Metadata |
| --- | ---: | ---: | --- |
| `0002DT` | `84/88` | `86/89` | Keep `CANONICAL_OWNER:000053`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000053`; populate first-draft C++ if supervisor accepts the raw no-route caveat. |
| `0002DP` | `84/88` | `87/90` | Keep `CANONICAL_OWNER:000053`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000053`; populate first-draft C++ for `FittingRoomListPane::HitTestSlot`. |
| `0002DU` | `84/88` | `86/88` | Keep `CANONICAL_OWNER:000053`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000053`; populate first-draft C++ if supervisor accepts provisional timer-field names. |

The targets clear the active `85/85` combined-score/emitter gate after this reanalysis. The old "95/95" and "blank parent/below threshold" explanations are stale. Remaining raw no-route and field-name gaps should cap these below near-final audit levels, not block first-draft C++.

## Evidence Checked

- Read supervisor workflow files:
  - `tools/leaser/Agents/Supervisor.md`
  - `tools/leaser/Agents/Agent-B003/goal.md`
  - `tools/leaser/Agents/Agent-B003/notes.md`
- Read source-placement guidance:
  - `by-structure.md`
  - `inference_research.md`
  - `proposed-source-tree.md`
- Read target docs:
  - `by-memory/0x00420950-0x00420b60.FittingRoomListPaneSlotRectRawHelpers.md`
  - `by-memory/0x00420b60-0x00420cf9.FittingRoomListPaneHitTestSlot.md`
  - `by-memory/0x00420d50-0x00420dd5.FittingRoomListPaneSlotLayoutRawHelpers.md`
- Read immediate fitting-room support:
  - `by-class/FittingRoomListPane.md`
  - `by-file/FittingRoom.md`
  - `by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md`
  - `by-memory/0x0041eb90-0x0041ecbd.FittingRoomListPaneConstructor.md`
  - `by-memory/0x0041f2b0-0x0041fb9b.FittingRoomListPaneOnPaint.md`
  - `by-memory/0x0041fcd0-0x004207ce.FittingRoomListPaneOnInputEvent.md`
  - `by-memory/0x00420840-0x00420949.FittingRoomListPaneOnScrollStep.md`
  - `by-memory/0x00420de0-0x00421301.FittingRoomSelectionVectorHelpers.md`
  - `by-class/FittingRoomDialog.md`
  - `by-class/FittingRoomDialogItemState.md`
  - `by-class/FittingEquipmentState.md`
  - `by-class/ItemCatalog.md`
- Read timer support for the `0x00420db0` cleanup helper:
  - `by-class/TimerHandler.md`
  - `by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md`
  - `by-memory/0x00597610-0x00597645.TimerHandlerWrappers.md`
- Read coverage/support rows:
  - `by-memory/-coverage-report.md` rows around `0002DT` / `0002DP` / `0002DQ` / `0002DU` / `0002DR`
  - `auto-generated/-ag-memory-coverage.md` rows for the three targets
  - `project-level/-auto-completion-stats.md`
  - `project-level/-unresolved.md` entries mentioning `sub_420B60`

Live IDA MCP was unavailable during this pass (`http://127.0.0.1:13337/mcp` connection failed). I therefore used the existing live-IDA-backed docs plus a fresh local executable byte and pointer-route scan against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.

## Fresh PE Route Recheck

Executable checked:

- Path: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Size: `2679296`
- MD5: `4247e04e20b65d6414c7238aa8ff5515`
- SHA1: `c285b73dc7b54c9a0e28ff7591a9bdde2ac55f9a`
- Image base: `0x00400000`
- `.text`: VA `0x00401000-0x0060c4ac`, raw `0x400`, raw size `0x20b600`
- `.rdata`: VA `0x0060d000-0x0066c0be`, raw `0x20ba00`, raw size `0x5f200`
- `.data`: VA `0x0066d000-0x0069ce24`, raw `0x26ac00`, raw size `0xd800`

Boundary and body confirmation:

- `0x00420949-0x00420950` is seven `0xcc` bytes, then `0x00420950` starts `55 8b ec`.
- `0x00420a10` starts `55 8b ec 83 b9 0c 01 00 00`.
- `0x00420a90` starts `55 8b ec 83 ec 14`.
- `0x00420b5c-0x00420b60` is `da 0a 42 00`, the final jump-table dword for the `0x00420a90` helper, then `0x00420b60` starts `55 8b ec 83 ec 18`.
- `0x00420cf9-0x00420d00` is seven `0xcc` bytes, then `0x00420d00` starts the modeled selection-index validator.
- `0x00420d50` starts `55 8b ec 83 b9 0c 01 00 00`.
- `0x00420dd5-0x00420de0` is eleven `0xcc` bytes before the next modeled helper island.

Direct route and hidden-table checks:

- Exact VA/RVA dword hits for `0x00420950`, `0x00420a10`, `0x00420a90`, `0x00420b60`, `0x00420d50`, and `0x00420db0`: no hits outside instruction/jump-table contexts.
- Aligned non-text dword scan in `.rdata`, `.data`, and `.rsrc` for pointers into the target ranges and exact raw starts: no hits.
- Direct relative call/jmp hits:
  - `0x00420950`: none.
  - `0x00420a10`: none.
  - `0x00420a90`: none.
  - `0x00420b60`: one call at `0x0041fdaf`, the documented `FittingRoomListPane::OnInputEvent` call.
  - `0x00420d50`: none.
  - `0x00420db0`: none.
- Full byte-pattern uniqueness:
  - `0002DT` `0x00420950-0x00420b60`: one occurrence at `0x00420950`.
  - `0002DP` `0x00420b60-0x00420cf9`: one occurrence at `0x00420b60`.
  - `0002DU` `0x00420d50-0x00420dd5`: one occurrence at `0x00420d50`.
  - Whole slot cluster `0x00420950-0x00420dd5`: one occurrence.

Helper-call confirmation in local target ranges:

- `0x004b7c50` rectangle setup is called from `0002DT` at `0x00420980`, `0x004209a6`, `0x004209cc`, `0x004209e9`, `0x00420a7c`, and `0x00420afb`, and from `0002DP` at `0x00420bef` and `0x00420c9f`.
- `0x004b7e80` point-in-rectangle is called from `0002DT` at `0x00420b08` and from `0002DP` at `0x00420bfe` and `0x00420cae`.
- `0x004b7c30` point setup is called from `0002DU` at `0x00420d6a` and `0x00420d87`.
- `0x00597610` is called from `0002DU` at `0x00420dc4`.

Field-route scan for `this+0x124` inside `0x0041ba40-0x004245f5`:

- Exact displacement `0x124` appears at `0x0041ec19`, `0x00420db5`, and `0x00420dcb`.
- `0x0041ec19` is constructor initialization.
- `0x00420db5` is `mov eax, [esi+0x124]` inside the cleanup helper.
- `0x00420dcb` is `mov dword ptr [esi+0x124], 0` inside the cleanup helper.
- No producer write to a nonzero `+0x124` value was found in the local fitting-room range by the byte-pattern scan.
- `lea ecx, [esi+0xa4]` occurs at `0x00420dbe` immediately before the `0x00597610` call, proving the cleanup helper cancels an event on the embedded `TimerHandler`-like facet at `this+0xa4`, using `this+0x124` as the event id/handle argument.

## Heuristic / Inference Reanalysis And Validation

### Source Placement

Current owner/emitter state is correct for the aggregate pages:

- `0002DT`, `0002DP`, and `0002DU` should keep `CANONICAL_OWNER:000053` and `EMITTER_UIDS:000053`.
- [UID:000053][FittingRoomListPane](../../../../by-class/FittingRoomListPane.md) is the direct behavioral owner because these helpers depend on list-pane display mode, visible item slots, input hit-testing, and list drawing/origin behavior.
- [UID:0000JE][FittingRoom](../../../../by-file/FittingRoom.md) remains the broader source module and generated output route.

Rejected placements:

- `FittingRoomScrollPane`: rejected because these helpers operate on item/list slots and `FittingRoomListPane::m_displayMode`, not scrollbar parts or scroll-thumb geometry.
- `FittingRoomDialog`: rejected as direct owner because the dialog owns the feature shell and preview state, but the direct receiver/caller evidence for the live hit-test method is list-pane input.
- `FittingRoomDialogItemState` / `FittingEquipmentState`: rejected because those pages own catalog/equipment-entry state and reset/parser behavior, not list-pane slot rectangles.
- `ItemCatalog`: rejected because catalog count/lookup appears in selection validation and scroll update, while these targets contain only geometry and timer cleanup.
- Generic UI geometry helpers: rejected because `0x004b7c30`, `0x004b7c50`, and `0x004b7e80` are dependencies; the target bodies are fitting-room-specific formulas.

Source split guidance:

- `0x00420950-0x00420a10` does not read `this`; it is best represented as a file-local static helper in `FittingRoom.cpp`, semantically tied to the list-pane feature: `GetFittingRoomEquipmentSlotRect` or `GetFittingRoomPreviewSlotRect`.
- `0x00420a10-0x00420a8a` reads `this+0x10c`; it is a `FittingRoomListPane` member helper: `GetItemSlotRect` / `GetVisibleItemSlotRect`.
- `0x00420a90-0x00420b60` does not read `this`; it is best represented as a file-local static special/equipment-slot hit-test helper: `HitTestFittingRoomEquipmentSlot`.
- `0x00420b60-0x00420cf9` reads `this+0x10c` and has the sole direct caller in `OnInputEvent`; it is `FittingRoomListPane::HitTestSlot`, preferably clarified as `HitTestItemSlot` if the class later has both item-slot and preview-slot hit-test names.
- `0x00420d50-0x00420db0` reads `this+0x10c`; it is a `FittingRoomListPane` member helper: `GetItemSlotOrigin` / `GetVisibleItemSlotOrigin`.
- `0x00420db0-0x00420dd5` reads `this+0x124` and uses `this+0xa4`; it is a `FittingRoomListPane` member cleanup helper for a pending timer/event id, not a generic resource free.

The aggregate target pages can remain as-is for now because all code still emits into `FittingRoom.cpp`; a future exact-source split would be cleaner but is not required to fix the current source-quality blockers.

### Slot / Category / Sub-Slot / Animation / Direction Meaning

The first `0002DT` helper is not a category helper, animation helper, direction helper, or display-mode helper.

Evidence:

- It accepts a signed 16-bit value, adds one, switches over six entries, and only gives valid rectangles for input values `2`, `3`, and `4`.
- It writes only fixed rectangles through `0x004b7c50`:
  - slot id `2`: `(168, 37, 185, 54)`
  - slot id `3`: `(168, 55, 185, 72)`
  - slot id `4`: `(168, 99, 185, 116)`
  - default / `-1`, `0`, `1`, and out-of-range: `(-1, -1, -1, -1)`
- It does not read `g_pFittingRoomDialog`, active category `+0x784`, catalog state, item-entry data, image frame state, direction state, or `this+0x10c`.
- The fitting-room category set is the larger `main`, `weapons`, `mounts`, `face`, `head`, `mantle`, `necklaces`, `coats`, `shoes`, `usable_items`, and `specialty_sets` set documented in the item-state/category parser, not `2..4`.
- Direction and animation state is handled in the preview/user-image and timer paths, not by these fixed pane coordinates.

Best inference:

- The ids are special fitting-room equipment/preview slot ids used by the list/preview UI, with `2`, `3`, and `4` being the only visible/hittable special slots in this helper.
- Use `FittingRoomEquipmentSlotId` or `FittingRoomPreviewSlotId` for the enum family if the supervisor adds support types. Do not name these as category ids.

### List/Grid Display Mode and Slot Index

`this+0x10c` is a display mode field.

- `0` means row/list mode.
- Nonzero means icon/grid mode; constructor initializes this field to `1`, so `1` is the observed default grid mode.
- Recommended enum names:
  - `FittingRoomListDisplayMode_Rows = 0`
  - `FittingRoomListDisplayMode_Grid = 1`

Slot indexes are 16-bit in the emitted code:

- Candidate loop variables are short/word sized.
- `0002DP` returns the matched candidate as a 16-bit value and returns `0xffff` for miss.
- Recommended typedef:

```cpp
typedef short FittingRoomSlotIndex;
static const FittingRoomSlotIndex kInvalidFittingRoomSlot = -1;
```

Use signed `short` at source boundaries because the miss sentinel is `-1`, but preserve unsigned range checks when testing valid slots, because the binary treats negative values as out of range through zero-extension in the rectangle helpers.

### List/Grid Rectangle Formulas

`0x00420a10` and `0x00420b60` use the same formulas.

Row/list mode (`this+0x10c == 0`):

- Valid slots: `0..0x1a` inclusive (`27` visible row candidates).
- Rectangle:
  - left `2`
  - top `slot * 20 + 16`
  - right `160`
  - bottom `slot * 20 + 36`
- Out of range: `(-1, -1, -1, -1)`.

Grid mode (`this+0x10c != 0`):

- Valid slots: `0..0x12` inclusive (`19` visible grid candidates).
- Six columns.
- `row = slot / 6`, `column = slot % 6`.
- Rectangle:
  - left `column * 96 + 16`
  - top `row * 112 + 31`
  - right `left + 54`
  - bottom `top + 54`
- Out of range: `(-1, -1, -1, -1)`.

This validates current docs for the formulas and resolves the display-mode naming/type issue enough for first-draft C++.

### Point / Origin Formulas

`0x00420d50` computes a draw/origin point companion to the rectangle formulas.

Row/list mode:

- Calls point helper `0x004b7c30` with base values `(30, 20)`.
- Applies `slot * 20` to the raw first stored coordinate.

Grid mode:

- Calls point helper `0x004b7c30` with base values `(21, 17)`.
- Computes `row = slot / 6` and `column = slot % 6`.
- Applies `column * 96` to the raw second stored coordinate.
- Applies `row * 112` to the raw first stored coordinate.

Recommended helper name: `FittingRoomListPane::GetItemSlotOrigin` or `GetVisibleItemSlotOrigin`.

Open caution: the raw storage order appears to put the row/vertical coordinate in the first stored dword and the column/horizontal coordinate in the second stored dword for this helper. The visual formulas match `y += rowStride` and `x += columnStride`; the final `Point` field names should be validated against the generic point helper before converting all docs from raw first/second coordinate language to `x/y`.

### Point / Rect / Hit-Test Helper Names

Recommended support names:

- `0x004b7c50`: `SetRectLTRB(RectBounds* out, int left, int top, int right, int bottom)` or simply `SetRect`.
- `0x004b7c30`: `SetPointXY(Point* out, int x, int y)` or simply `SetPoint`. Preserve raw first/second coordinate notes for `0002DU` until the project-wide point layout is final.
- `0x004b7e80`: `PointInRect(const RectBounds* rect, int x, int y)` / `PtInRect`.

These are generic UI helpers and should not become fitting-room-owned source functions.

### `this+0xa4..0x124` Layout and Cleanup Helper Role

Current `0002DU` wording says "release/reset scratch resource" and the constructor page calls `this+0x124` an "item/render state pointer". That is no longer the best interpretation.

Evidence:

- `0x00420db0` loads `[this+0x124]`, tests it, pushes it as the second argument, loads `ecx = this+0xa4`, calls `0x00597610`, and then clears `[this+0x124]`.
- `0x00597610` is documented as the generic `TimerHandler` targeted cancel wrapper, forwarding through `g_pTimerMgr` to the `0x00597b80` removal helper. It is not audio-owned and not a resource destructor.
- `0x00420840` `FittingRoomListPane::OnScrollStep` is an adjusted callback that derives the list pane from `ecx - 0xa4` and schedules repeat timers through `0x005975e0`.
- The local fitting-room range scan found only constructor initialization and cleanup clear for `+0x124`; no nonzero producer write was found in `0x0041ba40-0x004245f5`.

Best inference:

- `this+0xa4` is an embedded/secondary `TimerHandler` facet used by list-pane timer callbacks.
- `this+0x124` is a pending timer/event id or handle associated with that timer facet, not an image/text resource pointer.
- The helper at `0x00420db0` is best named `CancelPendingSlotTimer`, `CancelSlotLayoutTimer`, or `ClearPendingSlotTimerEvent`.
- It is not a destructor helper by itself: it has no base teardown, no vtable restore, no child deletion, no heap free, and no `TimerHandler::RemovePendingTimers` call. It only cancels one stored event id and clears the field.

Recommended field names:

- `this+0xa4`: `m_timerHandler` / embedded `TimerHandler` facet.
- `this+0x108`: current list scroll position, already validated by reset/update/input/paint docs.
- `this+0x10c`: `m_displayMode` / `FittingRoomListDisplayMode`.
- `this+0x11c`: embedded `FittingRoomScrollPane*`.
- `this+0x124`: `m_pendingSlotTimerEventId` or `m_pendingLayoutTimerEventId`; keep provisional because no producer write was found.

### Raw-Start Liveness and Caller Evidence

`0002DP` is live and directly reached:

- `0x00420b60` has a modeled IDA function record in current docs.
- PE direct-call scan confirms one direct call at `0x0041fdaf`.
- The caller is `FittingRoomListPane::OnInputEvent`, matching current docs.

`0002DT` and `0002DU` raw starts remain no-route helpers:

- No function records at `0x00420950`, `0x00420a10`, `0x00420a90`, `0x00420d50`, or `0x00420db0` in existing IDA evidence.
- Current docs record failed decompilation and no xrefs at those raw starts.
- Fresh PE scan found no direct call/jmp hits to those starts.
- Fresh PE scan found no exact VA/RVA data pointers to the starts and no aligned non-text pointers into the raw helper ranges.
- The bodies are still function-shaped, uniquely present, and tightly adjacent to live fitting-room list-pane code.

Conclusion:

- Treat raw helpers as retained source-authored helper bodies with no proven runtime route, likely preserved because the object file was linked for neighboring live `FittingRoomListPane` methods.
- Do not create IDA functions or assert hidden callers based on this report alone.
- Source names are still defensible from behavior and placement, but raw no-route status caps confidence and should remain documented.

### Validation / Contradiction of Current Docs

Validated:

- `0002DT` raw helper boundaries, switch tables, no-function/no-xref state, rectangle formulas, and final jump-table dword at `0x00420b5c`.
- `0002DP` method boundary, sole direct caller, formulas, `0xffff` miss return, and source placement.
- `0002DU` raw helper boundaries, point formulas, and `0x00420dd5-0x00420de0` padding.
- `CANONICAL_OWNER:000053` and `EMITTER_UIDS:000053` for all three aggregate pages.

Contradicted or stale:

- "Blank parent due attachment threshold" is stale. `FittingRoomListPane` is now `85/87`, and the target metadata already has owner/emitter `000053`.
- "95/95 source-quality gate" is stale. The active gate is the corrected combined `85/85` plus reconstructable/emitter path.
- `0002DU` "scratch-resource reset" is too broad and probably wrong. The observed body is a targeted `TimerHandler` event cancellation.
- Constructor support text saying `this+0x124` is an "item/render state pointer" should be revised to pending timer/event id with provisional naming.
- `project-level/-unresolved.md` still treating `sub_420B60` as unresolved is stale; the source-facing name `FittingRoomListPane::HitTestSlot` is validated.
- The adjacent `0002DR` coverage row still says `00030X` remains unassigned at `82/86`, while current `0002DR` and `FittingRoomListPane` docs say `00030X` now routes to `StringUtil`.

## Recommended Metadata And Score Changes

### `0002DT`

Recommended metadata:

```text
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000053 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000053 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Rationale: completion rises because the first helper's special/equipment-slot role, list/grid item-slot rectangle helper, static/member source split, and first-draft C++ path are now documented. Confidence rises because fresh PE route checks reject hidden pointer/table routes while validating uniqueness and boundaries. Do not raise above `89` confidence because raw starts still have no IDA function records or proven callers.

### `0002DP`

Recommended metadata:

```text
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000053 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000053 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Rationale: this is the strongest target. It has a modeled body, exact direct caller, exact formulas, exact sentinel behavior, and now source-quality display-mode and slot-index recommendations. Confidence should not go much higher until the class-wide event record and point/rect support names are final.

### `0002DU`

Recommended metadata:

```text
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000053 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000053 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Rationale: completion rises because the point/origin helper names and cleanup-helper role are resolved enough for first-draft C++. Confidence stays `88` because raw starts remain no-route and `+0x124` has no observed producer write beyond constructor init/cleanup clear.

Support pages:

- `by-class/FittingRoomListPane.md`: score can remain `85/87`, but method-table and boundary text should be updated.
- `by-file/FittingRoom.md`: score can remain `85/87`; add a source-quality note that the slot geometry cluster is now first-draft ready and that `0002DU` is timer cleanup rather than resource free.
- `by-memory/0x0041eb90-0x0041ecbd.FittingRoomListPaneConstructor.md`: score can remain `86/90`; field text should update `+0xa4` and `+0x124`.
- `by-memory/-coverage-report.md`: replace target rows and the adjacent stale `0002DR` row as listed below.

## First-Draft C++ Recommendation

Populate formal C++ for all three targets if the supervisor applies the recommended score changes. The snippets below are source-facing first drafts, not guaranteed binary-identical decompilation. Where the binary duplicates formulas instead of making direct calls, using helper calls is acceptable source shape unless the supervisor wants one-to-one codegen style.

Suggested support declarations for `FittingRoom.h` or the local `FittingRoom.cpp` support area:

```cpp
typedef short FittingRoomSlotIndex;

enum FittingRoomListDisplayMode
{
    FittingRoomListDisplayMode_Rows = 0,
    FittingRoomListDisplayMode_Grid = 1
};

static const FittingRoomSlotIndex kInvalidFittingRoomSlot = -1;
```

### `0002DT` Draft

Recommended formal body:

```cpp
static void GetFittingRoomEquipmentSlotRect(FittingRoomSlotIndex slotId, RectBounds* rect)
{
    switch (slotId)
    {
    case 2:
        SetRectLTRB(rect, 168, 37, 185, 54);
        break;
    case 3:
        SetRectLTRB(rect, 168, 55, 185, 72);
        break;
    case 4:
        SetRectLTRB(rect, 168, 99, 185, 116);
        break;
    default:
        SetRectLTRB(rect, -1, -1, -1, -1);
        break;
    }
}

void FittingRoomListPane::GetItemSlotRect(FittingRoomSlotIndex slotIndex, RectBounds* rect)
{
    if (m_displayMode == FittingRoomListDisplayMode_Rows)
    {
        if (static_cast<unsigned short>(slotIndex) <= 0x1a)
        {
            const int top = slotIndex * 20 + 16;
            SetRectLTRB(rect, 2, top, 160, top + 20);
            return;
        }
    }
    else
    {
        if (static_cast<unsigned short>(slotIndex) <= 0x12)
        {
            const int row = slotIndex / 6;
            const int column = slotIndex % 6;
            const int left = column * 96 + 16;
            const int top = row * 112 + 31;
            SetRectLTRB(rect, left, top, left + 54, top + 54);
            return;
        }
    }

    SetRectLTRB(rect, -1, -1, -1, -1);
}

static FittingRoomSlotIndex HitTestFittingRoomEquipmentSlot(int x, int y)
{
    RectBounds rect;

    for (FittingRoomSlotIndex slotId = 0; slotId < 5; ++slotId)
    {
        GetFittingRoomEquipmentSlotRect(slotId, &rect);
        if (PointInRect(&rect, x, y))
            return slotId;
    }

    return kInvalidFittingRoomSlot;
}
```

Binary-shape note: the emitted `0x00420a90` body duplicates the special-slot rectangle switch rather than calling `0x00420950`. If the supervisor wants stricter binary-shape reconstruction, keep the same helper name but inline the switch in `HitTestFittingRoomEquipmentSlot`.

### `0002DP` Draft

Recommended formal body:

```cpp
FittingRoomSlotIndex FittingRoomListPane::HitTestSlot(int x, int y)
{
    RectBounds rect;

    if (m_displayMode == FittingRoomListDisplayMode_Rows)
    {
        for (FittingRoomSlotIndex slotIndex = 0; slotIndex <= 0x1a; ++slotIndex)
        {
            GetItemSlotRect(slotIndex, &rect);
            if (PointInRect(&rect, x, y))
                return slotIndex;
        }
    }
    else
    {
        for (FittingRoomSlotIndex slotIndex = 0; slotIndex <= 0x12; ++slotIndex)
        {
            GetItemSlotRect(slotIndex, &rect);
            if (PointInRect(&rect, x, y))
                return slotIndex;
        }
    }

    return kInvalidFittingRoomSlot;
}
```

Binary-shape note: the emitted body repeats the rectangle formula instead of calling the raw helper at `0x00420a10`. The helper-call form is cleaner source and consistent with the neighboring helper body; if strict local codegen is preferred, duplicate the formulas directly in the loop.

### `0002DU` Draft

Recommended formal body:

```cpp
void FittingRoomListPane::GetItemSlotOrigin(Point* point, FittingRoomSlotIndex slotIndex)
{
    if (m_displayMode == FittingRoomListDisplayMode_Rows)
    {
        SetPoint(point, 30, 20);
        point->y += slotIndex * 20;
    }
    else
    {
        const int row = slotIndex / 6;
        const int column = slotIndex % 6;

        SetPoint(point, 21, 17);
        point->x += column * 96;
        point->y += row * 112;
    }
}

void FittingRoomListPane::CancelPendingSlotTimer()
{
    if (m_pendingSlotTimerEventId != 0)
    {
        m_timerHandler.CancelTimer(m_pendingSlotTimerEventId);
        m_pendingSlotTimerEventId = 0;
    }
}
```

Point-layout caution: this snippet uses conventional `x/y` names because the visual geometry is column/horizontal and row/vertical. The raw body adds row stride to the first stored coordinate and column stride to the second stored coordinate. If the project-wide `Point` type proves the first dword is named differently, preserve the raw field order in formal C++.

Timer-field caution: `m_pendingSlotTimerEventId` is a high-probability name. Do not harden it beyond provisional until the producer of `this+0x124` is found.

## Exact Supervisor Changes Required

### Target Header Changes

Apply the metadata changes listed in `Recommended Metadata And Score Changes`.

### `0002DT` Target Text

In `by-memory/0x00420950-0x00420b60.FittingRoomListPaneSlotRectRawHelpers.md`, replace the `Autogen status` bullet in `## Summary` with:

```md
- Autogen status: reconstructable helper island attached to [UID:000053][FittingRoomListPane](by-class/FittingRoomListPane.md), which now clears the corrected source-emission gate. First-draft C++ is recommended for the source-facing helper bodies, while the raw no-route starts remain documented as a confidence cap.
```

In the behavior table, replace the three rows with:

```md
| `0x00420950-0x00420a10` | file-local special equipment/preview slot rectangle helper | No `this` read. Switches on a signed 16-bit slot id and writes fixed rectangles for ids `2`, `3`, and `4`; default and ids `-1/0/1` write `(-1,-1,-1,-1)`. Best source name: `GetFittingRoomEquipmentSlotRect` or `GetFittingRoomPreviewSlotRect`. |
| `0x00420a10-0x00420a8a` | `FittingRoomListPane::GetItemSlotRect` / `GetVisibleItemSlotRect` | Reads display mode at `this+0x10c`. Row mode accepts slots `0..0x1a` and uses `(2, slot*20+16, 160, slot*20+36)`. Grid mode accepts slots `0..0x12` and uses six columns, stride `96x112`, base `(16,31)`, and size `54x54`. |
| `0x00420a90-0x00420b60` | file-local special equipment/preview slot hit-test helper | No `this` read. Loops candidate short values `0..4`, builds the same fixed special-slot rectangles, calls point-in-rect helper `0x004b7e80`, and returns the matching slot id or `-1`. The final dword at `0x00420b5c` is the last switch-table entry, not padding. |
```

Replace `## Open Questions` with:

```md
## Source-Quality Resolution

- The first helper is best treated as special fitting-room equipment/preview slot geometry, not category, sub-slot, animation, direction, or display-mode logic. It has no catalog/category/global/timer reads and only recognizes fixed ids `2`, `3`, and `4`.
- Source split: the first and third helpers are file-local static helpers in `FittingRoom.cpp` because they do not read `this`; the middle helper is a `FittingRoomListPane` member because it reads `this+0x10c`.
- Current PE route recheck found no direct call/jmp hits, exact VA/RVA start pointers, or aligned non-text pointers to the raw starts. Keep the no-route state documented and do not create IDA functions solely from this report.
- First-draft C++ is now recommended, with confidence capped by the raw no-route status and the unproven original helper names.
```

Replace the `Score Rationale` table with:

```md
| Score | Rationale |
| --- | --- |
| Completion `86` | Existing live IDA evidence plus the 2026-06-18 PE route scan confirm raw-start non-function status, no direct routes, exact switch-table/data boundaries, helper call targets, fixed special-slot rectangles, list/grid item-slot formulas, display-mode use, return conventions, and source split between file-local static special-slot helpers and a `FittingRoomListPane` item-rect member. Completion remains below near-final because the raw starts still have no modeled function records or proven callers. |
| Confidence `89` | Ownership is strong because the island is unique, adjacent to live list-pane input/scroll/hit-test code, and uses fitting-room-specific slot geometry. Confidence stays capped because no hidden caller/table route was found and original helper names are inferred rather than symbol-proven. |
```

### `0002DP` Target Text

In `by-memory/0x00420b60-0x00420cf9.FittingRoomListPaneHitTestSlot.md`, replace the `Autogen handling` bullet with:

```md
- Autogen handling: reconstructable `FittingRoomListPane` method attached to [UID:000053][FittingRoomListPane](by-class/FittingRoomListPane.md), which now clears the corrected source-emission gate. First-draft C++ is recommended for `FittingRoomListPane::HitTestSlot`; the old 95+ and below-threshold explanations are stale.
```

Replace `## Reconstruction Status` with:

```md
## Reconstruction Status

Emit first-draft C++ for this page after applying the recommended score update. The source shape is now clear: loop visible slot candidates for the active row/grid display mode, build or call the item-slot rectangle helper, call the generic point-in-rectangle helper with incoming mouse coordinates, return the matched short slot index, and return `-1` / `0xffff` on miss.

Recommended support names are `FittingRoomListDisplayMode_Rows`, `FittingRoomListDisplayMode_Grid`, `FittingRoomSlotIndex`, `SetRectLTRB`, and `PointInRect`. These names are source-quality enough for first-draft output, while exact original typedef names remain a confidence cap.
```

Replace the `Score Rationale` table with:

```md
| Score | Rationale |
| --- | --- |
| Completion `87` | Live IDA evidence confirms exact bounds, direct `OnInputEvent` caller, direct callee set, display-mode field, list/grid iteration ranges, rectangle formulas, hit-test call, matched-slot return, and miss return. The 2026-06-18 reanalysis resolves the display-mode enum direction, slot-index typedef, helper-name recommendations, and C++ readiness. |
| Confidence `90` | Confidence is strong because modeled IDA function data, the direct caller at `0x0041fdaf`, executable-byte boundaries, sibling raw-helper formulas, and class/file ownership all agree. Confidence stays below near-final because support type names and project-wide point/rect helper names are not symbol-proven. |
```

### `0002DU` Target Text

In `by-memory/0x00420d50-0x00420dd5.FittingRoomListPaneSlotLayoutRawHelpers.md`, replace the behavior table rows with:

```md
| `0x00420d50-0x00420db0` | `FittingRoomListPane::GetItemSlotOrigin` / `GetVisibleItemSlotOrigin` | Reads display mode at `this+0x10c`, writes a base point through `0x004b7c30`, and offsets it by slot index. Row mode uses base `(30,20)` plus slot row step `20`; grid mode uses base `(21,17)`, six columns, horizontal stride `0x60`, and vertical stride `0x70`. |
| `0x00420db0-0x00420dd5` | pending slot/layout timer cancellation helper | If `this+0x124` is nonzero, calls generic `TimerHandler` targeted cancel wrapper `0x00597610` with `ecx=this+0xa4` and the stored event id, then clears `this+0x124`. This is timer cleanup, not image/text resource release. |
```

Replace the paragraph after the table with:

```md
The geometry helper is the slot-origin companion to [UID:0002DT][0x00420950-0x00420b60.FittingRoomListPaneSlotRectRawHelpers](by-memory/0x00420950-0x00420b60.FittingRoomListPaneSlotRectRawHelpers.md). The cleanup helper is tied to the embedded `TimerHandler` facet at `this+0xa4`; `this+0x124` is best treated as a pending timer/event id or handle. No nonzero producer write for `+0x124` has been found in the local fitting-room range, so the final member name remains provisional.
```

Replace `## Open Questions` with:

```md
## Source-Quality Resolution

- `this+0xa4` is the embedded/adjusted `TimerHandler` facet used by list-pane timer callbacks and cancellation helpers.
- `this+0x124` is best named `m_pendingSlotTimerEventId` or `m_pendingLayoutTimerEventId`, not an image/text resource pointer. The constructor initializes it to zero and this helper clears it after targeted timer cancellation.
- The cleanup helper is not proven to be a destructor helper: it performs no vtable restore, base teardown, child deletion, or heap free. Its direct role is targeted timer/event cancellation.
- Current PE route recheck found no direct call/jmp hits, exact start VA/RVA pointers, or aligned non-text pointers to `0x00420d50` or `0x00420db0`. Keep the no-route state documented.
- First-draft C++ is recommended, with field names marked provisional because the producer of `+0x124` remains unknown.
```

Replace the score table with:

```md
| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 86 | Existing live IDA evidence plus the 2026-06-18 PE route scan confirm exact neighboring functions, two raw helper bodies, raw-start no-route status, point-helper calls, mode-dependent slot-origin formulas, `TimerHandler` targeted cancel use through `this+0xa4`, `+0x124` clear, and tail padding. Completion remains capped because the `+0x124` producer and exact original field name are unresolved. |
| Confidence | 88 | Ownership is strong because the helper island is unique, adjacent to list-pane selection/vector helpers, and depends on list-pane display mode/timer facet state. Confidence stays capped because the starts have no IDA function records or direct caller xrefs and the timer-event field name remains inferred. |
```

### Support Doc Text

In `by-class/FittingRoomListPane.md`, replace the method-table rows for the three targets with:

```md
| [UID:0002DT][0x00420950-0x00420b60.FittingRoomListPaneSlotRectRawHelpers](by-memory/0x00420950-0x00420b60.FittingRoomListPaneSlotRectRawHelpers.md) | slot rectangle raw/helper cluster | Contains file-local special equipment/preview slot rect and hit-test helpers plus `FittingRoomListPane::GetItemSlotRect`; no raw-start route is proven, but fixed slot ids `2..4`, row/grid item-rect formulas, switch tables, and source placement are now source-quality enough for first-draft C++. |
| [UID:0002DP][0x00420b60-0x00420cf9.FittingRoomListPaneHitTestSlot](by-memory/0x00420b60-0x00420cf9.FittingRoomListPaneHitTestSlot.md) | `HitTestSlot` | Direct `OnInputEvent` callee that maps mouse coordinates to a visible row/grid item slot and returns a 16-bit slot index or `-1`. |
| [UID:0002DU][0x00420d50-0x00420dd5.FittingRoomListPaneSlotLayoutRawHelpers](by-memory/0x00420d50-0x00420dd5.FittingRoomListPaneSlotLayoutRawHelpers.md) | slot origin and pending timer cleanup raw helpers | Computes row/grid item-slot origins and cancels a pending slot/layout timer event through the embedded `TimerHandler` facet at `this+0xa4`; `this+0x124` is a provisional timer/event id field, not a resource pointer. |
```

In `by-class/FittingRoomListPane.md`, after the existing boundary caution that begins "2026-05-30 IDA MCP byte review shows `0x004207ce-0x00420840`", insert:

```md
- 2026-06-18 B003 source-quality reanalysis of [UID:0002DT][0x00420950-0x00420b60.FittingRoomListPaneSlotRectRawHelpers](by-memory/0x00420950-0x00420b60.FittingRoomListPaneSlotRectRawHelpers.md), [UID:0002DP][0x00420b60-0x00420cf9.FittingRoomListPaneHitTestSlot](by-memory/0x00420b60-0x00420cf9.FittingRoomListPaneHitTestSlot.md), and [UID:0002DU][0x00420d50-0x00420dd5.FittingRoomListPaneSlotLayoutRawHelpers](by-memory/0x00420d50-0x00420dd5.FittingRoomListPaneSlotLayoutRawHelpers.md) confirms `0002DP` has a direct `OnInputEvent` caller while the raw helper starts still have no direct call/jmp or non-text pointer routes in the PE. Source-facing names are now recommended as special equipment/preview slot rect and hit-test static helpers, `GetItemSlotRect`, `HitTestSlot`, `GetItemSlotOrigin`, and `CancelPendingSlotTimer`. The cleanup helper uses `TimerHandler::CancelTimer` candidate `0x00597610` with `ecx=this+0xa4`, so `this+0x124` should be treated as a pending timer/event id, not a scratch resource pointer.
```

In `by-memory/0x0041eb90-0x0041ecbd.FittingRoomListPaneConstructor.md`, under `Observed list-pane fields`, add this bullet before `this + 0x108`:

```md
- `this + 0xa4`: embedded/adjusted `TimerHandler` facet used by scroll-repeat callbacks and by [UID:0002DU][0x00420d50-0x00420dd5.FittingRoomListPaneSlotLayoutRawHelpers](by-memory/0x00420d50-0x00420dd5.FittingRoomListPaneSlotLayoutRawHelpers.md) for targeted timer cancellation;
```

In the same field list, replace:

```md
- `this + 0x124`: item/render state pointer initialized to `0`;
```

with:

```md
- `this + 0x124`: pending slot/layout timer event id or handle initialized to `0`; [UID:0002DU][0x00420d50-0x00420dd5.FittingRoomListPaneSlotLayoutRawHelpers](by-memory/0x00420d50-0x00420dd5.FittingRoomListPaneSlotLayoutRawHelpers.md) passes this value to generic `TimerHandler` cancel wrapper `0x00597610` with `ecx=this+0xa4` and then clears it, but no nonzero producer has been found in the local fitting-room range;
```

In `by-file/FittingRoom.md`, after the large `FittingRoomListPane` bullet in `Likely Contents`, insert:

```md
- 2026-06-18 B003 source-quality reanalysis resolves the list-pane slot geometry cluster [UID:0002DT][0x00420950-0x00420b60.FittingRoomListPaneSlotRectRawHelpers](by-memory/0x00420950-0x00420b60.FittingRoomListPaneSlotRectRawHelpers.md), [UID:0002DP][0x00420b60-0x00420cf9.FittingRoomListPaneHitTestSlot](by-memory/0x00420b60-0x00420cf9.FittingRoomListPaneHitTestSlot.md), and [UID:0002DU][0x00420d50-0x00420dd5.FittingRoomListPaneSlotLayoutRawHelpers](by-memory/0x00420d50-0x00420dd5.FittingRoomListPaneSlotLayoutRawHelpers.md) as first-draft C++ ready under `FittingRoom.cpp`: special equipment/preview slot ids `2..4`, row/grid item-slot rectangle formulas, direct `HitTestSlot` caller evidence, row/grid origin formulas, and targeted timer cancellation through the list-pane `TimerHandler` facet at `this+0xa4` are now documented. Raw helper starts remain no-route helpers and should not be promoted to IDA functions without additional route evidence.
```

In `project-level/-unresolved.md`, remove or mark superseded any unresolved `sub_420B60` entry. Replacement note if the supervisor keeps a resolved ledger:

```md
- `sub_420B60` superseded: resolved as [UID:0002DP][0x00420b60-0x00420cf9.FittingRoomListPaneHitTestSlot](by-memory/0x00420b60-0x00420cf9.FittingRoomListPaneHitTestSlot.md) / `FittingRoomListPane::HitTestSlot`, with sole direct caller at `0x0041fdaf` inside `FittingRoomListPane::OnInputEvent`.
```

## Coverage Report Replacement Text

Placement: replace the existing rows in `by-memory/-coverage-report.md` around the `FittingRoomListPaneAlignmentPadding` / `0002DT` / `0002DP` / `0002DQ` / `0002DU` block. Leave the padding rows and `0002DQ` row unchanged unless the supervisor is already refreshing the whole neighborhood.

Replace the `0002DT` row with:

```md
        - [UID:0002DT][0x00420950-0x00420b60.FittingRoomListPaneSlotRectRawHelpers](by-memory/0x00420950-0x00420b60.FittingRoomListPaneSlotRectRawHelpers.md) 0x00420950-0x00420b60 | raw helpers | FittingRoomListPaneSlotRectRawHelpers : reconstructable : 86% : strong : Existing live IDA evidence plus B003 2026-06-18 PE recheck confirm raw-start non-function/no-route status for `0x00420950`/`0x00420a10`/`0x00420a90`, no direct call/jmp or non-text pointer routes, unique bytes, exact switch tables at `0x004209f8` and `0x00420b48` through final dword `0x00420b5c`, fixed special equipment/preview slot rectangles for ids `2..4`, row/grid item-slot rectangle formulas through `this+0x10c`, rectangle helper `0x004b7c50`, point-in-rect helper `0x004b7e80`, source split between file-local static special-slot helpers and a `FittingRoomListPane` item-rect member, and first-draft C++ readiness under owner/emitter `000053` with raw no-route confidence cap.
```

Replace the `0002DP` row with:

```md
        - [UID:0002DP][0x00420b60-0x00420cf9.FittingRoomListPaneHitTestSlot](by-memory/0x00420b60-0x00420cf9.FittingRoomListPaneHitTestSlot.md) 0x00420b60-0x00420cf9 | method | FittingRoomListPaneHitTestSlot : reconstructable : 87% : strong : Existing live IDA evidence plus B003 2026-06-18 PE recheck confirm exact bounds, sole direct `OnInputEvent` caller at `0x0041fdaf`, display-mode field `this+0x10c`, row/list visible slots `0..0x1a`, grid visible slots `0..0x12`, row rectangle `(2, slot*20+16, 160, slot*20+36)`, six-column grid rectangle with stride `96x112`, base `(16,31)`, size `54x54`, point-in-rect testing, 16-bit slot return, `0xffff` miss return, source-facing `FittingRoomSlotIndex` / row-grid display-mode recommendations, and first-draft C++ readiness under owner/emitter `000053`.
```

Replace the `0002DU` row with:

```md
        - [UID:0002DU][0x00420d50-0x00420dd5.FittingRoomListPaneSlotLayoutRawHelpers](by-memory/0x00420d50-0x00420dd5.FittingRoomListPaneSlotLayoutRawHelpers.md) 0x00420d50-0x00420dd5 | raw helpers | FittingRoomListPaneSlotLayoutRawHelpers : reconstructable : 86% : strong : Existing live IDA evidence plus B003 2026-06-18 PE recheck confirm raw-start non-function/no-route status for `0x00420d50`/`0x00420db0`, no direct call/jmp or non-text pointer routes, unique bytes, exact neighboring functions and `0x00420dd5-0x00420de0` padding, row/grid slot-origin formulas through point helper `0x004b7c30`, display-mode field `this+0x10c`, targeted pending timer/event cancellation through `TimerHandler` wrapper `0x00597610` with `ecx=this+0xa4`, provisional `this+0x124` timer-event-id field cleared after cancel, and first-draft C++ readiness with raw no-route and missing producer confidence caps.
```

Adjacent stale row replacement recommended for `0002DR` if the supervisor touches the neighborhood:

```md
        - [UID:0002DR][0x00420de0-0x00421301.FittingRoomSelectionVectorHelpers](by-memory/0x00420de0-0x00421301.FittingRoomSelectionVectorHelpers.md) 0x00420de0-0x00421301 | helper-island | FittingRoomSelectionVectorHelpers : ignored : 88% : strong : Reviewed mixed aggregate/audit container over exact child functions. A002 Batch101 and later supervisor follow-up split the six exact child pages: FittingRoomListPane is `85/87` and owns `00030R`/`00030T`; VectorHelpers is `86/86` and owns `00030Q`/`00030Z`; StringUtil owns `00030V` and `00030X`. The aggregate itself stays non-emitting/unassigned because no single direct source owner covers all children.
```

## Remaining Blockers

- Live IDA MCP was unavailable for this pass, so no new IDA comments, names, function creation, or xref queries were applied. Existing live-IDA-backed docs and the fresh PE scan were sufficient for report recommendations but not for IDA DB edits.
- `0002DT` and `0002DU` raw starts still have no direct caller/xref/pointer route. This does not block first-draft C++ but should block any claim of proven runtime liveness or IDA function promotion.
- Exact original names for `GetFittingRoomEquipmentSlotRect`, `HitTestFittingRoomEquipmentSlot`, `GetItemSlotRect`, `GetItemSlotOrigin`, and `CancelPendingSlotTimer` remain inferred from behavior.
- The project-wide `Point` storage/field order should be verified before hardening `point->x` / `point->y` in formal generated C++ for `0002DU`.
- The producer of `this+0x124` was not found in the local fitting-room range. The field should remain provisional as pending slot/layout timer event id or handle. This caps `0002DU` confidence and support field-name confidence.

## Validation Commands For Supervisor

After applying the target/support/coverage changes, run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0002DT-0002DP-0002DU-FittingRoomListPaneSlotGeometry-source-quality-removed.md](0002DT-0002DP-0002DU-FittingRoomListPaneSlotGeometry-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If C++ snippets are inserted and accepted, then run the apply variants under normal supervisor control:

> Executable block R002 was removed from this report and preserved verbatim in [0002DT-0002DP-0002DU-FittingRoomListPaneSlotGeometry-source-quality-removed.md](0002DT-0002DP-0002DU-FittingRoomListPaneSlotGeometry-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Optional IDA follow-up when MCP is available:

```text
lookup_funcs 0x00420950 0x00420dd5
xrefs_to 0x00420950
xrefs_to 0x00420a10
xrefs_to 0x00420a90
xrefs_to 0x00420b60
xrefs_to 0x00420d50
xrefs_to 0x00420db0
xrefs_to 0x00420dc4
decompile 0x00420b60
```

Do not create functions at the raw starts unless a separate supervisor-approved IDA boundary repair pass decides raw helper promotion is desirable.

## Changed Files

- Created this report only: `tools/leaser/Agents/Agent-B003/research/0002DT-0002DP-0002DU-FittingRoomListPaneSlotGeometry-source-quality.md`

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0002DT-0002DP-0002DU-FittingRoomListPaneSlotGeometry-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:28","uid":"0002DT"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002DT-0002DP-0002DU-FittingRoomListPaneSlotGeometry-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/0002DT-0002DP-0002DU-FittingRoomListPaneSlotGeometry-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002DT"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
