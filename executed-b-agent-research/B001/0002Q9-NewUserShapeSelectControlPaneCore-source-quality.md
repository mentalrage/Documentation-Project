** TARGET-REPORT-UID:0002Q9 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B001 Source-Quality Report: [UID:0002Q9] NewUserShapeSelectControlPaneCore

Agent: B001  
Assignment: `B001-report-0002Q9-new-user-shape-select-control-pane-core-20260625`  
Report timestamp: 2026-06-25 05:24:23 -04:00  
Target: `by-memory/0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore.md`  
Mode: report-only research. No leases taken. No by-* docs, generated files, validator state/cache, IDA DB, or coverage reports were edited.

## Current Target State

- Current source header: `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:00009G`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00009G`, blank optional emitter metadata, blank formal `RECONSTRUCTION_CPP`, `Nested:0`.
- Current item summary is useful but stale because it still frames the page as blocked by "tail-chunk/C++ gates" even though current MCP evidence supports an exact first-draft emitter insertion with documented caveats.
- Current autogen/status prose still says C++ remains blank under a 95+ source gate. That is stale under the current Rule 26 source-quality standard.
- Stale generated tracker state was observed read-only: the tracker row remains at `76/84`, while the target source header is already `86/88`. The generated source marker for `login/NewUserShapeSelectControlPane.cpp` is also stale/empty.
- Owner/emitter route remains direct through [UID:00009G] `by-class/NewUserShapeSelectControlPane.md`; the file route is [UID:0000LY] `by-file/NewUserShapeSelectControlPane.md`. No owner change or split is recommended.

## Evidence Checked

### Current IDA MCP Session

IDA MCP endpoint `http://127.0.0.1:13337/mcp` responded. Evidence was collected from the active IDB session for `NexusTK.exe.i64`; the report is not fallback-only.

Continuation recheck on 2026-06-25 used MCP session `80de0a67` (`NexusTK.exe.i64`, worker pid `26892`). `server_health` returned `ok`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready. Fresh `entity_query`, `lookup_funcs`, `xrefs_to`, `get_bytes`, `callees`, and `decompile` calls reconfirmed the function inventory, tail chunks, no-xref raw helpers, vtable/resource references, boundary bytes, and behavior summarized below. This continuation pass also checked `RectBoundsLayout` / `RectGeometryHelpers` before finalizing the point-conversion C++: `RectBounds` is `{left, top, right, bottom}`, while the shared `PointInRect` helper preserves source-facing argument order `y, x, bounds`.

Current MCP evidence ids used in this report:

- `10 server_health`: MCP ok, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis and Hex-Rays ready.
- `11 entity_query`: modeled functions in and around `0x004fd520-0x004fdd50`: `0x004fd520`, `0x004fd610`, `0x004fd660`, `0x004fd790`, `0x004fd850`, `0x004fd900`, `0x004fd910`, `0x004fd970`, `0x004fda30`, `0x004fdc90`, with successor `0x004fdd40`.
- `12 lookup_funcs`: confirms sizes and that `0x004fd680`/`0x004fd6a0` are tails of `0x0052d060`/`0x0052d0b0`, while `0x004fd6c0`, `0x004fd730`, and `0x004fd8f0` are not IDA function starts.
- `13 xrefs_to`: constructor, descriptor, direction, page, timer/mouse/paint vtable, and point-to-shape references. Constructor caller is `0x0052c7aa`; descriptor caller is `0x0052d85f`; direction callers include `0x0052cedf` and `0x0052d24a`; page callers are `0x0052ce6e` and `0x0052cdce`; point-to-shape caller is `0x004fd9d3`.
- `15 get_bytes`: confirms constructor/padding, direction/tail chunk bytes, raw tiny helper bytes, point-to-shape epilogue, and `0xcc` padding before `0x004fdd40`.
- `17-25 decompile`, rechecked by continuation decompile calls `20-28`: confirms constructor, descriptor builder, direction advance, next/previous page helpers, timer, mouse, paint, and point-to-shape behavior.
- `26-27 decompile`: confirms dialog select-male/select-female helpers tail into `0x004fd680`/`0x004fd6a0` and set body modes `2`/`6`.
- `28` and `31 insn_query`, rechecked by continuation `get_bytes`: disassembles raw no-function helpers `0x004fd6c0-0x004fd72c`, `0x004fd730-0x004fd786`, raw `xor al, al; ret` at `0x004fd8f0`, and `nullsub_39` at `0x004fd900`.
- `29 callees`: verifies constructor calls `ControlPane::ControlPane`, shape count, and timer scheduling; page helpers call the shape count helper; paint calls the expected graphics/render dependencies.
- `30 int_convert`: confirms decimal values for key constants: `0xeb=235`, `0xbd=189`, `0x99=153`, `0x25f=607`, `0xa3=163`, `0xc8=200`, `0x11a=282`, `0x116=278`, `0x118=280`, `0x10c=268`, `0x110=272`, `0xff=255`, `0xa0=160`, `0xa4=164`, `15`, `5`, `3`.
- `32 xrefs_to`: vtable refs at `0x0061d608`, `0x0061d670`, and `0x0061d6a0`; destructor thunk references for `0x00502a70`, `0x0050253a`, and `0x00502545`.
- `34-35 xrefs_to`: resource string refs for `0x0061e3c0` and `0x0061e420`, including target paint refs `0x004fdaf0` and `0x004fdafc`.
- `39-40 insn/decompile`: constructor caller in `NewCreateUserDialogPane` allocates `0x11c` bytes, chooses `rand()%15`, passes the bounds/control args, calls `0x004fd520`, and registers child id `8`.
- `41-42 insn/decompile`: submit/create packet caller reads selector selected slot and page, computes `selectedSlot + 15 * page`, calls `0x004fd610`, and serializes descriptor fields into the create-user packet.
- `44 insn_query`: confirms `0x004fd850` is the previous-page route and `0x004fd790` is the next-page route; also confirms the dialog button logic around page zero/last page.

### Project Documents Read

- Target `by-memory/0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore.md`.
- Support docs: `by-class/NewUserShapeSelectControlPane.md`, `by-file/NewUserShapeSelectControlPane.md`, `by-memory/0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs.md`, `by-memory/0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore.md`, `by-class/NewCreateUserDialogPane.md`, `by-class/UserCreatePreviewControlPane.md`, `by-memory/0x004949e0-0x00494a81.ControlPaneConstructor.md`, `by-memory/0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md`, `by-global/g_pNewHumanImageLib.md`, and `by-global/g_pEPFLib.md`.
- Generated output was checked read-only: `auto-generated/NexusTK/login/NewUserShapeSelectControlPane.cpp` currently contains empty/stale markers for the file/class/child route.

## Source-Quality Findings

### Range, Ownership, And Split

The exact range remains `0x004fd520-0x004fdd33`. MCP evidence id `11` confirms all modeled functions inside the range and the next modeled function at `0x004fdd40`; byte evidence id `15` confirms `sub_4FDC90` ends at `0x004fdd33`, followed by thirteen `0xcc` padding bytes before `ChangePasswordDialogPaneCore`.

No child split is recommended. The range is a selector-core cluster, but the mixed pieces are now classifiable:

- The constructor, descriptor builder, direction advance, page helpers, timer, mouse handler, paint handler, and point-to-shape helper are `NewUserShapeSelectControlPane` class behavior.
- `0x004fd680` and `0x004fd6a0` are physically in the range but are IDA tail chunks of dialog helpers `0x0052d060` and `0x0052d0b0`; they are documented as dialog-owned inline/tail writes to selector body mode, not emitted as independent selector methods.
- `0x004fd6c0` and `0x004fd730` are code-shaped retained helpers with no current inbound xrefs and no IDA function records. They can be represented in the first-draft C++ as retained private helpers, with names that do not claim a live caller.
- `0x004fd8f0` and `0x004fd900` are tiny virtual/null helper bodies; they should be retained in documentation but do not block class C++ emission.

The owner/emitter metadata should remain `CANONICAL_OWNER:00009G` and `EMITTER_UIDS:00009G`.

### Constructor And Field State

MCP decompile id `17` and caller evidence ids `39-40` support the constructor source shape:

- `NewCreateUserDialogPaneCore` allocates `0x11c` bytes, computes an initial selected slot with `rand()%15`, builds bounds `(539,164)-(955,574)`, passes a boolean/body-mode flag and control flag/reserved byte, calls `0x004fd520`, and registers the child with id `8`.
- The constructor calls `ControlPane::ControlPane(8, bounds)`, writes the three `NewUserShapeSelectControlPane` vtable heads, stores the constructor flag byte at `+0xff`, computes `m_maxShapeIndex = GetShapeCount() - 1`, clears page/animation/drag state, chooses body mode `2` for the true/male path and `6` for the false/female path, stores initial direction `2`, stores the initial selected slot at `+0x116`, and schedules a `200` ms timer on the timer subobject at complete-object offset `+0xa4`.

Recommended source-facing fields for implementation docs:

| Offset | Recommended source-facing meaning | Evidence |
| --- | --- | --- |
| `+0xff` | constructor/control flag byte | Constructor argument stored directly; no stronger current member name. |
| `+0x108` | cleared reserved/descriptor state | Constructor clears it; no stronger current reader. |
| `+0x10a` | max shape index | Constructor stores `GetShapeCount() - 1`; selection/paint compare against it. |
| `+0x10c` | body mode | Constructor and dialog tail chunks store `2`/`6`; descriptor/paint consume it. |
| `+0x10e` | animation frame | Timer increments modulo four; paint passes it to the render params. |
| `+0x110` | preview direction | Constructor seeds `2`; direction helper increments modulo four; paint consumes it. |
| `+0x112` | animation tick/counter | Timer increments it; no stronger source name found. |
| `+0x114` | reserved draw state | Constructor clears it; no stronger current reader. |
| `+0x116` | selected shape slot within current page | Constructor caller seeds `rand()%15`; page helpers and point-to-shape update it. |
| `+0x118` | shape page | Constructor clears; page helpers update; submit caller multiplies by `15`. |
| `+0x11a` | mouse tracking/drag flag | Constructor clears; mouse handler toggles it while dragging. |

### Descriptor Helper And Packet Route

`0x004fd610` should be documented as `BuildPreviewParams` or `BuildShapeDescriptor`, not as a packet writer. MCP evidence ids `18` and `41-42` show:

- The helper receives a descriptor/render-params output pointer and a resolved global shape index.
- It initializes descriptor fields from current body mode, selected shape index, direction/frame defaults, and a sentinel `-1`.
- The create-user submit path computes `selectedSlot + 15 * page`, calls this helper, then separately serializes the descriptor fields into the create-user packet.

The existing high-level support wording in `NewCreateUserDialogPaneCore` that resembles `m_shapeSelector->AppendCreateUserAppearance(packet)` should be synchronized to reflect this two-step route: selector builds params/descriptor, submit code serializes the resulting fields.

`HumanImageRenderParams` remains the best project-facing descriptive typedef because `by-class/UserCreatePreviewControlPane.md` already uses the same style for the sibling create-user preview builder. No evidence supports replacing it with a generated `unk_` struct or with a final original source typedef.

### Heuristic / Inference Reanalysis And Validation

The current pass treats unresolved source-quality blockers as active research rather than final excuses. The prior page wording left C++ blocked on tail chunks, raw helper liveness, source placement, field names, helper names, and a stale 95+ gate. Current MCP and support-doc evidence resolves those blockers to implementation-ready documentation changes:

- Tail chunks are not unresolved selector methods: `lookup_funcs` maps `0x004fd680` and `0x004fd6a0` to dialog helpers `0x0052d060`/`0x0052d0b0`, and decompilation proves they store body modes `2`/`6` on child id `8` then invalidate.
- Raw helpers are source-shaped retained selector helpers, not padding or live routed methods: `lookup_funcs` reports `0x004fd6c0`, `0x004fd730`, and `0x004fd8f0` as not functions, `xrefs_to` finds no inbound refs to `0x004fd6c0`/`0x004fd730`, and byte reads show normal prologue/epilogue helper bodies plus alignment padding.
- Generated globals/resources have better source-facing names: `dword_67A760` routes through `g_pNewHumanImageLib`, `dword_67A744` through `g_pEPFLib`, and `off_61E3C0`/`off_61E420` are `USERPART.EPF`/`USERPART.PAL` resource string references.
- `0x004fd610` is a descriptor/render-params builder, not a packet writer: the submit helper computes `selectedSlot + 15 * page`, calls `0x004fd610`, then separately serializes the descriptor bytes into the outgoing create-user packet.
- The point-conversion source form must preserve the project rectangle convention: `InitRectBounds` writes `{left, top, right, bottom}`, `PointInRect` is `PointInRect(y, x, bounds)`, and `0x004fdc90` receives `(localY, localX)` even though decompiler names can make that look inverted. The formal C++ below uses that order explicitly.
- Exact original member/type spellings remain unrecovered, but they no longer block C++ entry because the field roles, offsets, dependencies, and emitter route are documented. The report therefore uses descriptive, source-facing names and keeps confidence below final-audit `95+`.

### Page, Direction, Mouse, Timer, Paint

The current helper names can be made source-facing:

- `0x004fd660`: `AdvanceDirection()`, advances `m_direction` modulo four.
- `0x004fd790`: `SelectNextPage()` or `AdvanceShapePage()`. MCP id `44` proves this is the next-page route because dialog logic reaches it from the right/next button path and then adjusts next/previous button enabled state.
- `0x004fd850`: `SelectPreviousPage()`. MCP id `44` proves this is the previous-page route.
- `0x004fd910`: timer handler; event id `0` advances animation frame modulo four, increments the tick, invalidates, and reschedules `200` ms.
- `0x004fd970`: mouse handler; hit-tests the selector rectangle, tracks drag/capture state, and calls `SelectShapeAtPoint` with local arguments in the binary/project helper order `(localY, localX)`.
- `0x004fda30`: paint handler; renders a 5-column by 3-row selector grid, highlights the selected slot, and uses `USERPART.EPF`/`USERPART.PAL` plus `g_pNewHumanImageLib` to draw the preview body.
- `0x004fdc90`: `SelectShapeAtPoint(int localY, int localX)`, clamps local cell coordinates and updates selected slot on valid shape indices.

The grid constants are now source-ready: 5 columns, 3 rows, 15 shapes per page, 80-pixel cell width, 132-pixel cell height, `200` ms timer interval.

### Raw Helper Disposition

`0x004fd6c0-0x004fd72c` and `0x004fd730-0x004fd786` should not be left as unexplained `sub_`/raw blocks. MCP ids `12`, `13`, `28`, and `31` establish that they are code-shaped selector helpers but have no IDA function record and no current inbound xrefs.

Recommended disposition:

- Keep them inside [UID:0002Q9] as retained source-shaped helpers.
- Use conservative names `StepShapeForwardRetained()` and `StepShapeBackwardRetained()`, or equivalent, so implementation does not invent a live caller.
- Document the backward helper's zero-slot fall-through as source-normalized to return the current slot; the raw decompiler shape otherwise exposes an uninitialized stack-word return on the zero path, which is not a defensible source-level behavior claim.
- These retained helpers lower confidence slightly but do not block first-draft class C++ because their isolation is proven and the behavior is simple.

### Tail Chunks

`0x004fd680` and `0x004fd6a0` should not be emitted as separate `NewUserShapeSelectControlPane` method definitions in [UID:0002Q9]. MCP ids `12`, `26`, and `27` prove they are tails of dialog helpers:

- `0x004fd680`: dialog select-male path sets selector body mode `2` and invalidates.
- `0x004fd6a0`: dialog select-female path sets selector body mode `6` and invalidates.

The implementation should preserve these in coverage notes and support docs as dialog-owned tail chunks or inlined selector state writes. A private source helper such as `SetBodyMode()` may be mentioned as a source-shape explanation in the parent/dialog docs, but [UID:0002Q9] should not pretend a standalone function starts at either tail address.

### Globals, Resources, And Generated Names

Generated placeholder names can be replaced where evidence is strong:

- `dword_67A760` should be documented as `g_pNewHumanImageLib`, based on `by-global/g_pNewHumanImageLib.md` and direct target uses.
- `dword_67A744` should be documented as `g_pEPFLib`, based on `by-global/g_pEPFLib.md` and paint evidence.
- `off_61E3C0` and `off_61E420` are not pointer globals for source C++; `by-memory/0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md` identifies them as UTF-16 resource strings `USERPART.EPF` and `USERPART.PAL`.
- `sub_4E0DD0(g_pNewHumanImageLib)` is proven to be the shape-count dependency for this selector. `GetNewUserShapeCount()` or `g_pNewHumanImageLib->GetShapeCount()` is the best source-facing expression. The older/sibling `GetHeadCount` naming precedent from head-preview support docs is not a better name for this body-shape selector.
- `sub_5975E0` is the timer scheduling route. Use a descriptive `ScheduleTimer(0, 200, 0, 0)` in first-draft C++ and document the raw call in support evidence.

## Rejected Alternatives And Negative Evidence

- Reject leaving C++ blank because of a 95+ gate. Current Rule 26 allows first-draft C++ when reconstructable exact emitters have current evidence and blockers are resolved; [UID:0002Q9] satisfies that standard.
- Reject a new split before C++. The only mixed-owner bytes are already explainable tail chunks, and the raw retained helpers have no inbound refs but are local selector behavior.
- Reject moving ownership to `NewCreateUserDialogPane`. The constructor and helper callers route through that dialog, but vtable refs and method bodies belong to `NewUserShapeSelectControlPane`.
- Reject treating `0x004fd610` as a packet writer. The submit path proves the helper builds descriptor/render params; packet serialization happens afterward in `0x0052d7c0`.
- Reject generated names `dword_67A760`, `dword_67A744`, `off_61E3C0`, and `off_61E420` in source-facing prose/C++ where current project docs provide stronger names.
- Reject emitting `0x004fd680`/`0x004fd6a0` as standalone methods. They are IDA tails of dialog helpers.
- Reject using `GetHeadCount` as the source-facing count helper for this target. The target is a body-shape selector; current evidence proves count semantics but not the final original method spelling, so `GetNewUserShapeCount()`/`GetShapeCount()` is the safer descriptive name.
- Reject `PointInRect(x, y, rect)` and `SelectShapeAtPoint(localX, localY)` as final source-facing signatures for this target. Rect support docs and live decompilation show the shared point helper uses `y, x, bounds`, while `0x004fd970` subtracts top/left into `(localY, localX)` before calling `0x004fdc90`.
- No IDA MCP unavailability blocker exists for this report.

## Score And Metadata Recommendation

Recommended [UID:0002Q9] metadata:

- `COMPLETION:88`
- `CONFIDENCE:91`
- `CANONICAL_OWNER:00009G`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00009G`
- Preserve blank `EMITTER_POSITION_OPTIONAL`
- Preserve `Nested:0`

Rationale:

- Completion rises from `86` to `88` because current MCP evidence resolves first-draft C++ readiness, constructor argument shape, descriptor-vs-packet route, page-helper directionality, body-mode tail chunk disposition, raw helper disposition, current globals/resources, and support-doc synchronization needs.
- Confidence rises from `88` to `91` because live MCP confirms function starts, sizes, xrefs, vtables, tail chunks, bytes, padding, decompiled behavior, and caller data flow. It stays below `95` because final original member names and exact HumanImageLib descriptor typedef names remain descriptive rather than proven source spellings, and two no-xref raw helpers must be retained conservatively.

Recommended item summary:

`Source-ready NewUserShapeSelectControlPane exact core: constructor arguments, ControlPane base construction, vtable ownership, initial random slot caller, 200 ms timer, BuildPreviewParams descriptor route, AdvanceDirection, previous/next page helpers, mouse/paint/SelectShapeAtPoint behavior, retained no-xref shape-step helpers, dialog tail-chunk disposition, USERPART resource strings, g_pNewHumanImageLib/g_pEPFLib dependencies, and exact padding before ChangePasswordDialogPane are documented with formal first-draft C++ present.`

## Formal C++ Recommendation

If accepted, insert the following exact formal block into [UID:0002Q9] between `RECONSTRUCTION_CPP CODE:BEGIN` and `RECONSTRUCTION_CPP CODE:END`.

```cpp
// First-draft source-shape implementation for the exact
// NewUserShapeSelectControlPane core. Field and descriptor typedef names are
// descriptive; the constructor/caller route, timer, selection math, paint
// dependencies, no-xref retained helpers, and tail-chunk exclusions are backed
// by B001's 2026-06-25 MCP pass.

namespace
{
constexpr unsigned short kNewUserShapeMaleMode = 2;
constexpr unsigned short kNewUserShapeFemaleMode = 6;
constexpr unsigned char kInitialPreviewDirection = 2;
constexpr int kShapeGridColumns = 5;
constexpr int kShapeGridRows = 3;
constexpr int kShapesPerPage = kShapeGridColumns * kShapeGridRows;
constexpr int kShapeCellWidth = 80;
constexpr int kShapeCellHeight = 132;
constexpr int kShapeTimerMs = 200;

int GetNewUserShapeCount()
{
    return g_pNewHumanImageLib->GetShapeCount();
}

int ClampInt(int value, int low, int high)
{
    if (value < low) {
        return low;
    }
    if (value > high) {
        return high;
    }
    return value;
}
}

NewUserShapeSelectControlPane::NewUserShapeSelectControlPane(short initialSelectedSlot,
                                                             bool initialMaleMode,
                                                             const RectBounds *bounds,
                                                             unsigned char controlFlags)
    : ControlPane(8, bounds),
      m_controlFlags(controlFlags),
      m_reservedShapeState(0),
      m_maxShapeIndex(static_cast<unsigned short>(GetNewUserShapeCount() - 1)),
      m_bodyMode(initialMaleMode ? kNewUserShapeMaleMode : kNewUserShapeFemaleMode),
      m_animationFrame(0),
      m_direction(kInitialPreviewDirection),
      m_animationTick(0),
      m_reservedDrawState(0),
      m_selectedShapeSlot(initialSelectedSlot),
      m_shapePage(0),
      m_mouseTracking(false)
{
    ScheduleTimer(0, kShapeTimerMs, 0, 0);
}

HumanImageRenderParams *NewUserShapeSelectControlPane::BuildPreviewParams(
    HumanImageRenderParams *outParams,
    unsigned char shapeIndex) const
{
    outParams->Reset();
    outParams->isFemale = (m_bodyMode != kNewUserShapeMaleMode);
    outParams->shapeIndex = shapeIndex;
    outParams->bodyMode = static_cast<unsigned char>(m_bodyMode);
    outParams->paletteOrFrame = -1;
    return outParams;
}

void NewUserShapeSelectControlPane::AdvanceDirection()
{
    m_direction = static_cast<unsigned char>((m_direction + 1) % 4);
}

int NewUserShapeSelectControlPane::StepShapeForwardRetained()
{
    const int lastForwardSlot = GetNewUserShapeCount() - 2;
    if (m_selectedShapeSlot < lastForwardSlot) {
        ++m_selectedShapeSlot;
        InvalidateBounds();
        return m_selectedShapeSlot;
    }

    if (m_selectedShapeSlot == lastForwardSlot) {
        ++m_selectedShapeSlot;
        InvalidateBounds();
        return -1;
    }

    return m_selectedShapeSlot;
}

int NewUserShapeSelectControlPane::StepShapeBackwardRetained()
{
    if (m_selectedShapeSlot > 1) {
        --m_selectedShapeSlot;
        InvalidateBounds();
        return m_selectedShapeSlot;
    }

    if (m_selectedShapeSlot == 1) {
        m_selectedShapeSlot = 0;
        InvalidateBounds();
        return -1;
    }

    return m_selectedShapeSlot;
}

short NewUserShapeSelectControlPane::SelectNextPage()
{
    const int shapeCount = GetNewUserShapeCount();
    ++m_shapePage;
    if (m_shapePage < 0) {
        m_shapePage = 0;
    }

    const short lastPage = static_cast<short>(shapeCount / kShapesPerPage);
    if (m_shapePage > lastPage) {
        m_shapePage = lastPage;
    }

    if (m_shapePage == lastPage && m_selectedShapeSlot >= shapeCount % kShapesPerPage) {
        m_selectedShapeSlot = static_cast<short>(shapeCount - kShapesPerPage * lastPage - 1);
        if (m_selectedShapeSlot < 0) {
            m_selectedShapeSlot = 0;
        }
    }

    InvalidateBounds();
    return m_shapePage;
}

short NewUserShapeSelectControlPane::SelectPreviousPage()
{
    const int shapeCount = GetNewUserShapeCount();
    --m_shapePage;
    if (m_shapePage < 0) {
        m_shapePage = 0;
    }

    const short lastPage = static_cast<short>(shapeCount / kShapesPerPage);
    if (m_shapePage > lastPage) {
        m_shapePage = lastPage;
    }

    if (m_shapePage == lastPage && m_selectedShapeSlot > shapeCount % kShapesPerPage) {
        m_selectedShapeSlot = 1;
    }

    InvalidateBounds();
    return m_shapePage;
}

bool NewUserShapeSelectControlPane::OnTimerEvent(int timerId, int, int)
{
    if (timerId == 0) {
        m_animationFrame = static_cast<unsigned short>((m_animationFrame + 1) % 4);
        ++m_animationTick;
        InvalidateBounds();
        ScheduleTimer(0, kShapeTimerMs, 0, 0);
    }

    return true;
}

bool NewUserShapeSelectControlPane::OnMouseEvent(const MouseEvent *event)
{
    RectBounds selectorRect;
    SetRect(&selectorRect, 17, 6, 417, 534);

    if (PointInRect(event->mouseY, event->mouseX, &selectorRect)) {
        const int localY = event->mouseY - 6;
        const int localX = event->mouseX - 17;

        if (event->type == MouseEvent::ButtonDown) {
            m_mouseTracking = true;
            SelectShapeAtPoint(localY, localX);
            return true;
        }

        if (event->type == MouseEvent::MouseMove && m_mouseTracking) {
            SelectShapeAtPoint(localY, localX);
            return true;
        }
    }

    if (event->type != MouseEvent::ButtonDown) {
        return ControlPane::OnMouseEvent(event);
    }

    m_mouseTracking = false;
    return true;
}

void NewUserShapeSelectControlPane::OnPaint()
{
    RectBounds selectedFrameRect;
    RectBounds shapeRect;
    HumanImageRenderParams params;

    InitializeTileContext(&selectedFrameRect);
    SetDrawColor(0);
    FillBounds();

    int rowTop = 6;
    for (int row = 0; row < kShapeGridRows; ++row) {
        for (int column = 0; column < kShapeGridColumns; ++column) {
            const unsigned char shapeIndex = static_cast<unsigned char>(
                column + kShapeGridColumns * (row + kShapeGridRows * m_shapePage));
            if (shapeIndex > m_maxShapeIndex) {
                continue;
            }

            const int left = 17 + kShapeCellWidth * column;
            if (m_selectedShapeSlot == column + kShapeGridColumns * row) {
                SetRect(&selectedFrameRect, left, rowTop, left + kShapeCellWidth, rowTop + kShapeCellHeight);
                g_pEPFLib->LookupLayoutEntry(L"USERPART.EPF", 0, &selectedFrameRect);
                DrawPaletteFrame(selectedFrameRect, L"USERPART.PAL");
            }

            SetRect(&shapeRect, left + 8, rowTop + 72, left + 88, rowTop + 204);
            BuildPreviewParams(&params, shapeIndex);
            params.animationFrame = m_animationFrame;
            params.direction = m_direction;
            g_pNewHumanImageLib->CalculateBounds(&params, m_direction, &shapeRect);
            g_pNewHumanImageLib->Draw(this, &shapeRect, &params, m_direction);
        }

        rowTop += kShapeCellHeight;
    }
}

int NewUserShapeSelectControlPane::SelectShapeAtPoint(int localY, int localX)
{
    const int column = ClampInt(localX / kShapeCellWidth, 0, kShapeGridColumns - 1);
    const int row = ClampInt(localY / kShapeCellHeight, 0, kShapeGridRows - 1);
    const int globalShape = kShapesPerPage * m_shapePage + kShapeGridColumns * row + column;

    if (globalShape >= 0 && globalShape <= m_maxShapeIndex) {
        m_selectedShapeSlot = static_cast<unsigned short>(globalShape % kShapesPerPage);
    }

    return InvalidateBounds();
}
```

## Support-Doc Synchronization Required If Accepted

The following support pages should be synchronized during the implementation callback:

- `by-memory/0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore.md`: score, summary, stale 95+ wording, current MCP evidence ids, formal C++ block, descriptor/page/raw-helper/tail-chunk/resource/global details.
- `by-class/NewUserShapeSelectControlPane.md`: update class summary and method map with constructor readiness, `BuildPreviewParams`, `AdvanceDirection`, `SelectNextPage`, `SelectPreviousPage`, `SelectShapeAtPoint`, retained raw helpers, timer/mouse/paint slots, and the tail-chunk exclusion. It may receive a declaration-level shell only if the supervisor accepts that extra class emission; otherwise keep [UID:0002Q9] as the formal method-body emitter.
- `by-file/NewUserShapeSelectControlPane.md`: replace stale blank-C++/folded-source caveat with the accepted file/class route and exact module expectations.
- `by-memory/0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs.md`: update the child row for [UID:0002Q9] so it no longer cites tail-chunk/C++ gates as an unresolved blocker.
- `by-memory/0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore.md`: synchronize constructor caller details, initial random slot, child id `8`, shape selector allocation size `0x11c`, select-male/select-female tail chunks, and submit route through `BuildPreviewParams`.
- `by-class/NewCreateUserDialogPane.md`: synchronize the member/control relationship and packet submit description to say the selector builds descriptor params and the dialog serializes them.
- `by-class/UserCreatePreviewControlPane.md`: no broad rewrite needed, but its `HumanImageRenderParams` naming precedent should remain consistent with this new selector wording if cross-links are touched.
- `by-memory/0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md`: no required edit unless support docs still call `0x0061e3c0`/`0x0061e420` generated pointer globals; if touched, preserve that they are UTF-16 `USERPART.EPF` and `USERPART.PAL`.
- `by-global/g_pNewHumanImageLib.md` and `by-global/g_pEPFLib.md`: no required edit unless xref summaries are stale; if touched, add this selector as a current use without altering global ownership.

Do not edit generated reports, project-level generated files, manual coverage files, validator/tool state, IDA DB, `by-memory/-coverage-report.md`, or any other `-coverage-report.md`.

## Implementation Tracking Checklist

Completed after supervisor acceptance on 2026-06-25:

- [x] Lease only the required target/support by-* docs immediately before editing. Proof: `python .\tools\leaser\leaser.py B001 lease ...` returned `Success` for all six edited by-* docs; leases were refreshed once before validation.
- [x] Update [UID:0002Q9] score to `88/91`, preserving owner/emitter/reconstructable metadata and blank optional metadata. Proof: post-validator readback shows `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:00009G`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00009G`, blank `EMITTER_POSITION_OPTIONAL`, and `Nested:0`.
- [x] Replace [UID:0002Q9] item summary with the exact recommended summary in this report. Proof: post-validator readback shows the `Source-ready NewUserShapeSelectControlPane exact core...` item summary.
- [x] Replace stale "blank under 95+" / unresolved C++ gate wording in [UID:0002Q9]. Proof: target now says formal first-draft C++ is populated and stale blockers are resolved; scoped `rg` found no active stale blank-gate wording in the edited primary docs.
- [x] Insert the exact formal `RECONSTRUCTION_CPP CODE` block above into [UID:0002Q9]. Proof: post-validator readback shows the first-draft block beginning immediately after `RECONSTRUCTION_CPP CODE:BEGIN`, including `BuildPreviewParams`, `PointInRect(event->mouseY, event->mouseX, &selectorRect)`, and `SelectShapeAtPoint(localY, localX)`.
- [x] Add current MCP evidence ids `10-13`, `15`, `17-32`, `34-35`, `39-42`, and `44` to [UID:0002Q9] evidence notes as appropriate. Proof: target evidence notes cite MCP session `80de0a67` and the accepted id ranges.
- [x] Document constructor caller details, allocation size `0x11c`, child id `8`, `rand()%15` initial selected slot, `ControlPane(8, bounds)`, vtable refs, `200` ms timer, field map, and padding before `0x004fdd40`. Proof: target `Constructor And Field Map`, `Evidence Notes`, `Callers And Dependencies`, and `Score Rationale` contain these facts.
- [x] Document descriptor helper as `BuildPreviewParams`/shape descriptor builder and correct any support wording that implies it writes packets directly. Proof: target, `NewCreateUserDialogPaneCore`, and `NewCreateUserDialogPane` now state that the selector builds descriptor params and the dialog serializes them.
- [x] Document next/previous page directionality using MCP id `44`. Proof: target covered-range rows and helper disposition name `0x004fd790` as `SelectNextPage` and `0x004fd850` as `SelectPreviousPage`, with id `44` proof.
- [x] Document the RectBounds/PointInRect coordinate-order caveat: `RectBounds` is `left, top, right, bottom`, but the point helper uses `PointInRect(y, x, bounds)` and [UID:0002Q9] calls `SelectShapeAtPoint(localY, localX)`. Proof: target evidence notes and formal C++ carry this exact order.
- [x] Document retained raw helpers `0x004fd6c0` and `0x004fd730` with no-xref proof and conservative retained names. Proof: target and class page document `StepShapeForwardRetained` / `StepShapeBackwardRetained`, no function-start status, and no inbound xrefs.
- [x] Document tail chunks `0x004fd680` and `0x004fd6a0` as dialog-owned select-male/select-female tails, not standalone selector methods. Proof: target, class, aggregate, and dialog child pages document the tail disposition.
- [x] Replace generated global/resource names with `g_pNewHumanImageLib`, `g_pEPFLib`, `USERPART.EPF`, and `USERPART.PAL` where relevant. Proof: target/class/file prose and formal C++ use the source-facing names; generated labels only remain where explicitly called historical aliases.
- [x] Synchronize `by-class/NewUserShapeSelectControlPane.md`. Proof: page now has the updated method map, retained helpers, tail exclusion, source-placement note, and changed 2026-06-25 entry.
- [x] Synchronize `by-file/NewUserShapeSelectControlPane.md`. Proof: page now points to the accepted class/file route and exact child first-draft C++ rather than treating file folding as a C++ blocker.
- [x] Synchronize `by-memory/0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs.md` child row. Proof: [UID:0002Q9] row now says source-ready and lists first-draft C++, descriptor/page/raw-helper/tail disposition.
- [x] Synchronize `by-memory/0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore.md`. Proof: page now records allocation `0x11c`, child id `8`, `rand()%15`, select-male/select-female tails, and descriptor route; C++ no longer calls `AppendCreateUserAppearance(packet)`.
- [x] Synchronize `by-class/NewCreateUserDialogPane.md`. Proof: page now describes child id `8`, `m_shapeSelector`, select-male/select-female body-mode tails, and `BuildPreviewParams` followed by dialog-side serialization.
- [x] Review whether `by-class/UserCreatePreviewControlPane.md`, `by-memory/0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md`, `by-global/g_pNewHumanImageLib.md`, or `by-global/g_pEPFLib.md` need narrow cross-link/xref updates after primary edits. Proof: all four were reviewed. No edits were needed: `UserCreatePreviewControlPane` already uses `HumanImageRenderParams`; the read-only data page already resolves `USERPART.EPF`/`USERPART.PAL`; both globals already carry canonical names and historical alias context.
- [x] Run scoped validators for every changed by-* doc, recording command id, timestamp, exit code, ok count, and whether generated refresh was used. Proof table below.
- [x] Re-read [UID:0002Q9] header/summary/C++ after validation to confirm score, metadata, non-stale summary, and formal C++ survived. Proof: post-validator readback confirmed header `88/91`, owner/emitter metadata, the exact source-ready item summary, and formal C++ with corrected coordinate order.
- [x] If generated output is refreshed by validators, inspect `auto-generated/NexusTK/login/NewUserShapeSelectControlPane.cpp` for a non-empty current emission and no stale empty marker for [UID:0002Q9]. Proof: not applicable; every scoped validator reported `generated_refresh: deferred`, and generated output was not used as proof.
- [x] Release leases immediately after the edit/validator batch. Proof: `python .\tools\leaser\leaser.py B001 unlease ...` returned `Success` for all six paths; current lease report shows no active leases.
- [x] Update this checklist/proof section with implementation commands, validator outputs, final readbacks, and any generated-refresh result before returning `FINISHED_IMPLEMENTATION`.

Validator proof:

| File | Command id | Timestamp | Exit | ok | generated refresh |
| --- | --- | --- | ---: | ---: | --- |
| `by-memory/0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore.md` | `000000001289` | `2026-06-25T05:38:59-04:00` | `0` | `1` | `deferred` |
| `by-class/NewUserShapeSelectControlPane.md` | `000000001290` | `2026-06-25T05:39:07-04:00` | `0` | `1` | `deferred` |
| `by-file/NewUserShapeSelectControlPane.md` | `000000001291` | `2026-06-25T05:39:13-04:00` | `0` | `1` | `deferred` |
| `by-memory/0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs.md` | `000000001292` | `2026-06-25T05:39:20-04:00` | `0` | `1` | `deferred` |
| `by-memory/0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore.md` | `000000001293` | `2026-06-25T05:39:26-04:00` | `0` | `1` | `deferred` |
| `by-class/NewCreateUserDialogPane.md` | `000000001294` | `2026-06-25T05:39:37-04:00` | `0` | `1` | `deferred` |

## Report-Only Proof

- Leases: none taken, per report-only instruction.
- Validators: none run, per report-only instruction.
- Edited files: only this report file under Agent-B001 research.
- MCP availability: available and used; no MCP pause condition.
- Blockers remaining for supervisor acceptance: none. The only residual uncertainty is final original member/type spelling, which is explicitly handled by descriptive first-draft names and reflected in the recommended `91` confidence rather than left as an implementation blocker.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0002Q9-NewUserShapeSelectControlPaneCore-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/0002Q9-NewUserShapeSelectControlPaneCore-source-quality.md","timestamp":"2026-06-25T05:43:07","uid":"0002Q9"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
