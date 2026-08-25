** TARGET-REPORT-UID:0002Q8 **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B007 Source-Quality Report: [UID:0002Q8] UserShapeSelectControlPaneCore

Agent: B007  
Assignment: `B007-rework-0002Q8-user-shape-select-control-pane-core-20260625`  
Report timestamp: 2026-06-25 13:51:00 -04:00  
Target: `by-memory/0x004fce80-0x004fd520.UserShapeSelectControlPaneCore.md`  
Mode: report-only research. No leases taken. No by-* docs, generated files, validator state/cache, IDA DB, or coverage reports were edited.

## Current Target State

- Current by-memory header: `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000FR`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000FR`, blank optional emitter metadata, blank formal C++, `Nested:0`.
- Current route remains correct: exact source child [UID:0002Q8] -> [UID:0000FR] `UserShapeSelectControlPane` -> [UID:0000OX] `UserCreateAppearanceControls`.
- Current prose is stale in three material ways:
  - It still treats the old 95/95 code gate as a blocker. The active code-entry gate is met after this pass: reconstructable, owner/emitter present, and average score above 85.
  - It misses the live IDA function at `0x004fd130-0x004fd137`; the current covered-range table treats `0x004fd126-0x004fd140` as pure padding.
  - It leaves resource-frame names, descriptor field names, and first-draft C++ readiness as open blockers even though current evidence is enough for descriptive source-shaped names.
- Generated state is stale read-only: `auto-generated/NexusTK/login/UserCreateAppearanceControls.cpp` still lists [UID:0000FR] as `84/82` and [UID:0002Q8] as `74/86` empty markers, while the live by-* target is already `86/90`. The generated tracker row also remains `74/86`.

## Evidence Checked

### Current IDA MCP Session

IDA MCP endpoint `http://127.0.0.1:13337/mcp` responded. Active session `80de0a67` is `NexusTK.exe.i64` at `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`. `server_health` returned `ok`, auto-analysis ready, Hex-Rays ready, and strings cache ready. This report is not fallback-only.

Fresh MCP calls used in this report:

- `server_health`: MCP ok, Hex-Rays and auto-analysis ready.
- Rework MCP check on the same active session `80de0a67` at 2026-06-25 13:49-13:51 -04:00: `idb_list` confirmed the live `NexusTK.exe.i64` worker session; `server_health` returned `ok`; `decompile`/`disasm` for `0x004fd230` confirmed the paint lookup calls pass the local object at `[ebp+var_3C]` and then read the embedded rectangle at `[ebp+var_2C..var_20]`; `decompile`/`disasm` for `0x004d02f0` confirmed `ResourceLayoutTable::LookupLayoutEntry` writes the output context at `+0x10..+0x1f` and zeroes the same embedded bounds rectangle on a missing frame; `decompile`/`disasm` for `0x004fcfc0` confirmed the params builder writes descriptor fields but does not read or clear the caller's descriptor-kind byte at offset `+0x28`.
- `entity_query 0x004fce70-0x004fd530`: confirms modeled functions `0x004fce80`, `0x004fcfc0`, `0x004fd030`, `0x004fd050`, `0x004fd070`, `0x004fd0d0`, `0x004fd130`, `0x004fd140`, `0x004fd170`, `0x004fd1e0`, `0x004fd230`, and successor `0x004fd520`.
- `lookup_funcs`: confirms all documented starts/sizes and that padding starts such as `0x004fcfb5`, `0x004fd02a`, `0x004fd043`, `0x004fd066`, `0x004fd0c9`, `0x004fd126`, `0x004fd164`, `0x004fd1de`, and `0x004fd228` are not functions. It also confirms the missing `sub_4FD130`, size `0x7`.
- `get_bytes`: confirms the predecessor padding before `0x004fce80`, constructor epilogue and eleven `0xcc` bytes before `0x004fcfc0`, the `0x004fd130` getter bytes, timer/mouse padding, and paint epilogue ending immediately before `0x004fd520`.
- `decompile`: rechecked constructor, descriptor builder, male/female bank setters, forward/backward shape steppers, no-xref getter, selected-state setter, timer handler, mouse handler, and paint.
- `xrefs_to`: confirms eight constructor callers; descriptor-builder, bank-setter, stepper, and selected-state callers; vtable-only timer/mouse/paint refs; and zero xrefs to the retained getter `0x004fd130`.
- `callees` and `insn_query`: confirms constructor/timer scheduling calls, mouse hit-test call, paint calls, paint globals/resources, and exact callsites inside `0x004fd230`.
- `get_global_value`: confirms vtable entries `0x0061d5a8 -> 0x004fd230`, `0x0061d5d0 -> 0x004fd1e0`, `0x0061d600 -> 0x004fd170`, destructor/thunk entries, `byte_66DA97 == 1`, and zeroed singleton storage for `g_pEPFLib` / `g_pNewHumanImageLib`.
- `int_convert`: verified sizes and constants including `0x135=309`, `0x6a=106`, `0x7=7`, `0x2f0=752`, `0xc8=200`, `0xff=255`, offsets `0x108..0x118`, and packed constructor table values.

### Project Documents Read

- Target `by-memory/0x004fce80-0x004fd520.UserShapeSelectControlPaneCore.md`.
- Owner/source docs: `by-class/UserShapeSelectControlPane.md`, `by-file/UserCreateAppearanceControls.md`.
- Neighbor and aggregate docs: `by-memory/0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs.md`, `by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md`, `by-memory/0x004fccf0-0x004fce7e.SelectBoxControlPane.md`, `by-memory/0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore.md`, `by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md`, `by-memory/0x0052a540-0x0052f94c.CreateUserDialogVariants.md`.
- Support docs: `by-class/NewUserShapeSelectControlPane.md`, `by-file/NewUserShapeSelectControlPane.md`, `by-class/NewCreateUserDialogPane.md`, `by-class/UserCreatePreviewControlPane.md`, `by-class/NewHumanImageLib.md`, `by-type/by-struct/RectBoundsLayout.md`, `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md`, `by-memory/0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md`, `by-global/g_useEpfAssets.md`, `by-global/g_pEPFLib.md`, `by-global/g_pNewHumanImageLib.md`, `by-global/SurfaceRenderCallbackTable.md`.
- Prior reports used as format/source-quality precedents: executed B001 report for [UID:0002Q9] and executed B002 report for [UID:00019V].

## Source-Quality Findings

### Range, Function Inventory, And Missing Getter

The exact target range remains `0x004fce80-0x004fd520`. Live IDA confirms the current page's broad split, but adds one function the page currently misses:

| Range | Source-facing role | Current evidence |
| --- | --- | --- |
| `0x004fce80-0x004fcfb5` | constructor | `sub_4FCE80`, size `0x135` / 309 bytes. |
| `0x004fcfb5-0x004fcfc0` | padding | Eleven `0xcc` bytes before descriptor helper. |
| `0x004fcfc0-0x004fd02a` | `BuildPreviewParams` / descriptor builder | `sub_4FCFC0`, size `0x6a` / 106 bytes. |
| `0x004fd030-0x004fd043` | `SetMaleShapeBank` | Stores bank `0` at `+0x10e` and invalidates. |
| `0x004fd050-0x004fd066` | `SetFemaleShapeBank` | Stores bank `1` at `+0x10e` and invalidates. |
| `0x004fd070-0x004fd0c9` | `StepShapeForward` | Advances selected index at `+0x10c`; edge `8 -> 9` returns `-1`. |
| `0x004fd0d0-0x004fd126` | `StepShapeBackward` | Decrements selected index at `+0x10c`; edge `1 -> 0` returns `-1`. |
| `0x004fd130-0x004fd137` | retained `IsSelected` getter | Live IDA function `sub_4FD130`, size `0x7`, returns byte `+0x116`; no inbound xrefs. This replaces stale pure-padding coverage. |
| `0x004fd140-0x004fd164` | `SetSelected` | Stores byte `+0x116` and invalidates only on change. |
| `0x004fd170-0x004fd1de` | timer handler | Vtable-only timer event; updates frame/tick/direction state and reschedules `200` ms timer. |
| `0x004fd1e0-0x004fd228` | mouse event handler | Vtable-only event handler; type-3 hit-test sets selected byte and invalidates. |
| `0x004fd230-0x004fd520` | paint/render | Vtable-only paint; draws frame/background and body preview. |

No split is recommended. The cluster is a coherent `UserShapeSelectControlPane` exact method island. The only no-xref source-shaped helper is the tiny getter at `0x004fd130`, and its role is now clear enough to retain inside the target.

### Constructor, Fields, And Packed Sprite Tables

The constructor calls `ControlPane::ControlPane(8, bounds)`, writes three `UserShapeSelectControlPane` vtable views, stores the caller control flag at `+0xff`, seeds shape state, schedules timer id `0` every `200` ms, and writes two packed ten-entry sprite-id banks.

Recommended source-facing fields:

| Offset | Meaning | Evidence |
| --- | --- | --- |
| `+0xff` | `m_controlFlags` | Constructor stores fifth argument directly. |
| `+0x108` | `m_reservedShapeState` | Constructor clears; no current reader found. |
| `+0x10a` | `m_shapeIndexLimit` / fixed last shape index | Constructor writes `9`; steppers hard-code the same `0..9` range. |
| `+0x10c` | `m_selectedShapeIndex` | Constructor argument; steppers mutate; descriptor builder indexes the table with it. |
| `+0x10e` | `m_shapeBank` | `0` for male/primary bank, `1` for female/secondary bank; descriptor and bank setters consume it. |
| `+0x110` | `m_animationFrame` | Timer increments modulo four; paint passes it into bounds/draw helpers. |
| `+0x112` | `m_direction` | Constructor seeds `2`; timer advances it every sixteen ticks; paint consumes it. |
| `+0x114` | `m_animationTick` | Timer tick counter reset after reaching `16`. |
| `+0x116` | `m_selected` / selected-pane state | Getter/setter/mouse/paint use it; dialog code keeps one of four sibling panes selected. |
| `+0x118..+0x12b` | `m_shapeSpriteIds[0][10]` | Packed bank 0: `{2, 60, 1, 8, 34, 48, 80, 36, 3, 83}`. |
| `+0x12c..+0x13f` | `m_shapeSpriteIds[1][10]` | Packed bank 1: `{33, 74, 78, 50, 91, 10, 31, 4, 7, 45}`. |

MCP `int_convert` verified the packed dword writes: `0x003c0002`, `0x00080001`, `0x00300022`, `0x00240050`, `0x00530003`, `0x004a0021`, `0x0032004e`, `0x000a005b`, `0x0004001f`, and `0x002d0007`.

### Helper Roles And Caller Evidence

`0x004fcfc0` is a descriptor/render-param builder, not a packet writer. It zeroes a `HumanImageRenderParams`-style local, writes the current bank/sex flag, selected table id, and sentinel defaults. Packet serialization belongs to caller code:

- `0x004fc010` chooses the selected shape pane, calls `0x004fcfc0`, then writes opcode `4` packet bytes.
- `0x0052bdd0` computes active pane id `8 + activeIndex`, calls `0x004fcfc0`, then serializes descriptor fields into the create-user packet.
- Paint calls `0x004fcfc0` twice before `g_pNewHumanImageLib` bounds/draw calls.

Live xrefs show the helper cluster is actively routed through old and newer create-user coordinators:

- Constructor `0x004fce80`: eight callers, four in `0x004fb630` and four in `0x0052a540`.
- Descriptor `0x004fcfc0`: `0x004fc010`, three paint calls, and `0x0052bdd0`.
- `SetMaleShapeBank` / `SetFemaleShapeBank`: old-dialog and `NewUserDialogPane2` gender paths call all four sibling panes.
- `StepShapeForward` / `StepShapeBackward`: old-dialog command path, key/help path, and `NewUserDialogPane2` previous/next direction callbacks call all four sibling panes.
- `SetSelected`: old-dialog selection state plus `NewUserDialogPane2` active-pane movement and constructor setup.
- Timer/mouse/paint are vtable-only through `0x0061d600`, `0x0061d5d0`, and `0x0061d5a8`.

The no-xref `IsSelected` getter at `0x004fd130` should be documented as retained source-shaped code. It has a normal body (`mov al, [ecx+0x116]; ret`) and fits the setter/mouse/paint selected-state contract.

### Vtables And Owner Route

Vtable evidence continues to support direct class ownership under [UID:0000FR]:

- Constructor stores primary `0x0061d564`, secondary `0x0061d5cc`, and tertiary/timer `0x0061d5fc` vtable views.
- `get_global_value` confirms:
  - `0x0061d564 -> 0x00502dd0` scalar deleting destructor.
  - `0x0061d568 -> 0x004f4b10` inherited/base slot.
  - `0x0061d5a8 -> 0x004fd230` paint.
  - `0x0061d5cc -> 0x005025ea` adjustor thunk.
  - `0x0061d5d0 -> 0x004fd1e0` mouse/event.
  - `0x0061d5fc -> 0x005025f5` adjustor thunk.
  - `0x0061d600 -> 0x004fd170` timer.

Keep `CANONICAL_OWNER:0000FR` and `EMITTER_UIDS:0000FR`. The source file route through [UID:0000OX] remains stronger than a direct dialog route because the same class is constructed by both `NewUserMiscDialogPane` and `NewUserDialogPane2`.

### Paint Resources And Render Dependencies

The paint method at `0x004fd230` is now source-ready at dependency level:

- `0x004fd243`: compares [UID:0000SW] `g_useEpfAssets` / `byte_66DA97` to `1`.
- Current/EPF branch calls `g_pEPFLib->LookupLayoutEntry` at `0x004fd29c` with UTF-16 `USERPART.EPF` at `0x0061e3c0`, then draws via `sub_4B9980` with `NEWBUTT.PAL` at `0x0061e3dc`.
- Legacy branch calls lookup at `0x004fd3c9` with UTF-16 `CAPSULE.EPD` at `0x0061e3f4`, then draws with `NPAL3.PAL` at `0x0061e40c`.
- Rework MCP disassembly/decompilation confirms the frame source rectangle is not an independent local. The stack object initialized at paint `[ebp+var_3C]` is the 0x28-byte `EPFTileContext`; `LookupLayoutEntry` fills its embedded `bounds` at `+0x10`, and paint passes both `&frameContext` and `&frameContext.bounds` into `RenderTileFrame`. The corrected formal C++ therefore reads `frameContext.bounds` after lookup instead of using an uninitialized `sourceRect`.
- Direct byte read of `0x0061e3c0-0x0061e420` decodes the four adjacent wide strings: `USERPART.EPF`, `NEWBUTT.PAL`, `CAPSULE.EPD`, and `NPAL3.PAL`.
- Paint uses [UID:0000TN] `SurfaceRenderCallbackTable` slot `0x0069b3fc` as a fill/region-prep callback after `SetDrawColor(0)`.
- Paint reads [UID:0000RT] `g_pNewHumanImageLib` / `dword_67A760` at `0x004fd33b`, `0x004fd468`, and `0x004fd4fe`.
- Paint calls `0x004e09e0` as `NewHumanImageLib::CalculateBounds` and `0x004e06a0` as `NewHumanImageLib::Draw`, matching current NewHumanImageLib class docs and sibling generated source.

Generated/raw names `byte_66DA97`, `dword_67A744`, `dword_67A760`, `off_61E3C0`, `off_61E3DC`, `off_61E3F4`, and `off_61E40C` should remain evidence aliases only. Source-facing text should use `g_useEpfAssets`, `g_pEPFLib`, `g_pNewHumanImageLib`, `USERPART.EPF`, `NEWBUTT.PAL`, `CAPSULE.EPD`, and `NPAL3.PAL`.

### Rejected Alternatives

- Reject leaving C++ blank because of the stale `95/95` gate. The active gate is met: `RECONSTRUCTABLE:TRUE`, nonblank `EMITTER_UIDS`, and `(88 + 91) / 2 > 85` after this source-quality pass.
- Reject treating `0x004fd130` as padding. Live IDA models it as a 7-byte function and decompiles it as a selected-state getter.
- Reject moving ownership to `NewUserMiscDialogPane`, `NewUserDialogPane2`, or `CreateUserDialogs`. They coordinate and construct the class, but vtables and method bodies belong to `UserShapeSelectControlPane`.
- Reject stale `0x00501620`/`0x00501640` shape-helper ownership. Current support docs correctly place those with `UserHairSelectControlPane`; this target's real bank helpers are `0x004fd030` and `0x004fd050`.
- Reject generated resource pointer globals for `0x0061e3c0..0x0061e40c`; these are UTF-16 literals/fragments, not source global pointers.
- Reject calling `0x004fcfc0` a packet writer. It builds params/descriptor; caller code serializes packets.

## Score And Metadata Recommendation

Recommended [UID:0002Q8] metadata:

- `COMPLETION:88`
- `CONFIDENCE:91`
- `CANONICAL_OWNER:0000FR`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000FR`
- Preserve blank `EMITTER_POSITION_OPTIONAL`
- Preserve `Nested:0`

Rationale:

- Completion rises from `86` to `88` because current MCP evidence resolves the missing getter, exact method inventory, field/table map, descriptor-vs-packet route, current/legacy resource strings, live caller/vtable routes, and formal C++ readiness.
- Confidence rises from `90` to `91` because the active MCP session confirms starts/sizes, bytes, xrefs, decompilation, vtables, globals, resources, callers, and support-doc routes. It stays below final audit because final original member/type spellings remain descriptive and `0x004fd130` is retained/no-xref.

Recommended item summary:

`Source-ready old UserShapeSelectControlPane exact core: constructor, descriptor builder, male/female shape-bank helpers, forward/backward shape steppers, retained selected-state getter, selected-state setter, timer/mouse/paint handlers, two ten-entry sprite-id banks, current/legacy frame resources, g_useEpfAssets/g_pEPFLib/g_pNewHumanImageLib dependencies, direct class owner route, and formal first-draft C++ are documented.`

## Formal C++ Recommendation

If accepted, insert this formal first-draft block into [UID:0002Q8] between `RECONSTRUCTION_CPP CODE:BEGIN` and `RECONSTRUCTION_CPP CODE:END`.

```cpp
// First-draft source-shape implementation for the exact old
// UserShapeSelectControlPane core. Field, descriptor, and helper names are
// descriptive; the method inventory, selected-state getter, sprite-id tables,
// timer, resource branch, caller fanout, and class owner route are backed by
// B007's 2026-06-25 MCP pass.

namespace
{
constexpr unsigned char kUserShapeControlType = 8;
constexpr unsigned char kInitialShapeDirection = 2;
constexpr unsigned short kOldUserShapeLastIndex = 9;
constexpr unsigned short kOldUserShapeForwardEdge = 8;
constexpr unsigned short kOldUserShapeTimerMs = 200;
constexpr unsigned short kOldUserShapeDirectionTickLimit = 16;
constexpr unsigned char kControlPaneVisualStateNormal = 10;
constexpr unsigned char kShapePreviewDescriptorKind = 0x50;

constexpr unsigned short kUserShapeSpriteIds[2][10] = {
    {2, 60, 1, 8, 34, 48, 80, 36, 3, 83},
    {33, 74, 78, 50, 91, 10, 31, 4, 7, 45},
};

int CenterLow(int outerLow, int outerHigh, int innerLow, int innerHigh)
{
    return (outerLow + outerHigh) / 2 - (innerHigh - innerLow) / 2;
}

void CenterRectInBounds(RectBounds *outRect,
                        const RectBounds &outerRect,
                        const RectBounds &sourceRect)
{
    const int sourceLeft = sourceRect.left;
    const int sourceTop = sourceRect.top;
    const int sourceRight = sourceRect.right;
    const int sourceBottom = sourceRect.bottom;
    const int width = sourceRight - sourceLeft;
    const int height = sourceBottom - sourceTop;

    outRect->left = CenterLow(outerRect.left, outerRect.right,
                              sourceLeft, sourceRight);
    outRect->top = CenterLow(outerRect.top, outerRect.bottom,
                             sourceTop, sourceBottom);
    outRect->right = outRect->left + width;
    outRect->bottom = outRect->top + height;
}
}

UserShapeSelectControlPane::UserShapeSelectControlPane(short initialShapeIndex,
                                                       bool useMaleShapeBank,
                                                       const RectBounds *bounds,
                                                       unsigned char controlFlags)
    : ControlPane(kUserShapeControlType, bounds),
      m_controlFlags(controlFlags),
      m_reservedShapeState(0),
      m_shapeIndexLimit(kOldUserShapeLastIndex),
      m_selectedShapeIndex(initialShapeIndex),
      m_shapeBank(useMaleShapeBank ? 0 : 1),
      m_animationFrame(0),
      m_direction(kInitialShapeDirection),
      m_animationTick(0),
      m_selected(false)
{
    for (int bank = 0; bank < 2; ++bank) {
        for (int index = 0; index < 10; ++index) {
            m_shapeSpriteIds[bank][index] = kUserShapeSpriteIds[bank][index];
        }
    }

    ScheduleTimer(0, kOldUserShapeTimerMs, 0, 0);
}

HumanImageRenderParams *UserShapeSelectControlPane::BuildPreviewParams(
    HumanImageRenderParams *outParams) const
{
    outParams->Reset();
    outParams->isFemale = (m_shapeBank != 0);
    outParams->shapeIndex = static_cast<unsigned char>(
        m_shapeSpriteIds[m_shapeBank][m_selectedShapeIndex]);
    outParams->bodyMode = static_cast<unsigned char>(m_shapeBank);
    outParams->paletteOrFrame = -1;
    return outParams;
}

void UserShapeSelectControlPane::SetMaleShapeBank()
{
    m_shapeBank = 0;
    InvalidateBounds();
}

void UserShapeSelectControlPane::SetFemaleShapeBank()
{
    m_shapeBank = 1;
    InvalidateBounds();
}

int UserShapeSelectControlPane::StepShapeForward()
{
    if (m_selectedShapeIndex < kOldUserShapeForwardEdge) {
        ++m_selectedShapeIndex;
        InvalidateBounds();
        return m_selectedShapeIndex;
    }

    if (m_selectedShapeIndex == kOldUserShapeForwardEdge) {
        m_selectedShapeIndex = kOldUserShapeLastIndex;
        InvalidateBounds();
        return -1;
    }

    return m_selectedShapeIndex;
}

int UserShapeSelectControlPane::StepShapeBackward()
{
    if (m_selectedShapeIndex > 1) {
        --m_selectedShapeIndex;
        InvalidateBounds();
        return m_selectedShapeIndex;
    }

    if (m_selectedShapeIndex == 1) {
        m_selectedShapeIndex = 0;
        InvalidateBounds();
        return -1;
    }

    return m_selectedShapeIndex;
}

bool UserShapeSelectControlPane::IsSelected() const
{
    return m_selected;
}

void UserShapeSelectControlPane::SetSelected(bool selected)
{
    if (m_selected == selected) {
        return;
    }

    m_selected = selected;
    InvalidateBounds();
}

bool UserShapeSelectControlPane::OnTimerEvent(int timerId, int, int)
{
    if (timerId == 0) {
        m_animationFrame = static_cast<unsigned short>((m_animationFrame + 1) % 4);
        ++m_animationTick;

        if (m_animationTick >= kOldUserShapeDirectionTickLimit) {
            m_animationTick = 0;
            m_direction = static_cast<unsigned char>((m_direction + 1) % 4);
        }

        InvalidateBounds();
        ScheduleTimer(0, kOldUserShapeTimerMs, 0, 0);
    }

    return true;
}

bool UserShapeSelectControlPane::OnMouseEvent(const MouseEvent *event)
{
    if (event != NULL &&
        event->type == MouseEvent::ButtonDown &&
        PointInRect(event->mouseY, event->mouseX, &m_bounds) &&
        !m_selected)
    {
        m_selected = true;
        InvalidateBounds();
    }

    return true;
}

void UserShapeSelectControlPane::OnPaint()
{
    EPFTileContext frameContext;
    RectBounds frameRect;
    RectBounds drawRect;
    HumanImageRenderParams params;

    frameContext.Initialize();
    SetDrawColor(0);
    FillRect(&m_bounds);

    if (m_selected || m_visualState != kControlPaneVisualStateNormal) {
        const wchar_t *frameResource = g_useEpfAssets == 1
            ? L"USERPART.EPF"
            : L"CAPSULE.EPD";
        const wchar_t *paletteResource = g_useEpfAssets == 1
            ? L"NEWBUTT.PAL"
            : L"NPAL3.PAL";

        g_pEPFLib->LookupLayoutEntry(frameResource, 0, &frameContext);

        const RectBounds &sourceRect = frameContext.bounds;
        CenterRectInBounds(&frameRect, m_bounds, sourceRect);

        RenderTileFrame(&frameContext, &sourceRect, &frameRect, 0, paletteResource, 0);
    }

    BuildPreviewParams(&params);
    params.kind = kShapePreviewDescriptorKind;
    g_pNewHumanImageLib->CalculateBounds(&params, m_direction, &drawRect);

    CenterRectInBounds(&drawRect, m_bounds, drawRect);

    BuildPreviewParams(&params);
    params.kind = kShapePreviewDescriptorKind;
    g_pNewHumanImageLib->Draw(this, &drawRect, &params, m_direction);
}
```

Implementation notes for the supervisor/editor:

- `HumanImageRenderParams`, `EPFTileContext`, `RenderTileFrame`, `FillRect`, `ScheduleTimer`, and `InvalidateBounds` are descriptive source-facing names matching nearby accepted pages. If an existing canonical helper name is stronger during implementation, use the canonical name while preserving the documented raw evidence.
- The paint draft intentionally uses `frameContext.bounds` as the lookup-populated source rectangle. This matches the rework MCP evidence and accepted EPFTileContext layout docs: `LookupLayoutEntry` fills the 0x28-byte context, and `RenderTileFrame` receives `&frameContext` plus `&frameContext.bounds`.
- The preview descriptor kind is assigned after `BuildPreviewParams()` in this source draft because `0x004fcfc0` does not read or clear the offset `+0x28` kind byte; this keeps the body internally coherent even if the eventual descriptor helper name is implemented as a broader reset/default routine.
- If the class declaration is also updated, add `m_shapeSpriteIds[2][10]`, selected-shape fields, timer fields, selected byte, and method declarations consistent with the method-body block.

## Support-Doc Synchronization Required If Accepted

During an implementation callback, lease only the edited docs and apply scoped updates:

- `by-memory/0x004fce80-0x004fd520.UserShapeSelectControlPaneCore.md`: score to `88/91`, summary, covered ranges including `0x004fd130`, live MCP evidence, field/table map, resource literals, first-draft C++ block, and removal of stale 95/95 wording.
- `by-class/UserShapeSelectControlPane.md`: update method map with `BuildPreviewParams`, `SetMaleShapeBank`, `SetFemaleShapeBank`, `StepShapeForward`, `StepShapeBackward`, retained `IsSelected`, `SetSelected`, timer/mouse/paint, field map, vtable refs, and source-ready exact child route. Consider a declaration shell only if the supervisor wants class-level emission.
- `by-file/UserCreateAppearanceControls.md`: replace stale empty/old-gate wording for [UID:0002Q8], keep this file as the owner route, and do not move old-dialog packet/coordinator logic into this file.
- `by-memory/0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs.md`: update [UID:0002Q8] child row to include the retained getter, first-draft C++ readiness, resource literals, and current source-ready disposition.
- `by-memory/0x0052a540-0x0052f94c.CreateUserDialogVariants.md` and/or exact `NewUserDialogPane2` child docs if touched: synchronize the four old-shape-pane constructor calls, `rand()%6`, active-pane state, and calls to this target's bank/step/selected helpers.
- `by-memory/0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md`: add this target's read-only resource facts for `NEWBUTT.PAL`, `CAPSULE.EPD`, and `NPAL3.PAL` adjacent to the already documented `USERPART.EPF` strings.
- `by-global/g_useEpfAssets.md`, `by-global/g_pEPFLib.md`, `by-global/g_pNewHumanImageLib.md`, and `by-global/SurfaceRenderCallbackTable.md`: no required ownership changes. Add this target as a consumer only if those pages are already being touched.

Do not edit generated files, project-level generated files, manual coverage files, validator/tool state, IDA DB, `by-memory/-coverage-report.md`, or any other `-coverage-report.md`.

## Implementation Tracking Checklist

Implementation callback completed on 2026-06-25.

- [x] Lease only the target/support by-* docs immediately before editing. Proof: leased exactly `by-memory/0x004fce80-0x004fd520.UserShapeSelectControlPaneCore.md`, `by-class/UserShapeSelectControlPane.md`, `by-file/UserCreateAppearanceControls.md`, `by-memory/0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs.md`, and `by-memory/0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md` as `Agent-B007` at `2026-06-25T18:01:08Z`.
- [x] Update [UID:0002Q8] metadata to `88/91`, preserving owner/emitter/reconstructable metadata and blank optional metadata. Proof: post-validation readback shows `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000FR`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000FR`, blank `EMITTER_POSITION_OPTIONAL`, and `Nested:0`.
- [x] Replace the item summary with the recommended source-ready summary. Proof: target summary now names constructor, descriptor builder, bank helpers, steppers, retained selected-state getter, selected-state setter, timer/mouse/paint handlers, sprite-id banks, resources, globals, owner route, and formal first-draft C++.
- [x] Replace stale old-gate and unresolved-source-quality wording in [UID:0002Q8]. Proof: status/reconstruction notes now describe the active source-ready gate and preserve the old `95/95` gate only as an explicitly rejected alternative.
- [x] Add the `0x004fd130-0x004fd137` getter row and correct the surrounding padding rows. Proof: target covered ranges now split `0x004fd126-0x004fd130` padding, `0x004fd130-0x004fd137` retained getter, and `0x004fd137-0x004fd140` padding.
- [x] Insert the corrected formal first-draft C++ block above or an equivalent source-shaped block that preserves the same evidence-backed behavior and names, including `EPFTileContext::bounds` as the lookup-populated frame source rectangle and descriptor-kind assignment after `BuildPreviewParams()`. Proof: target formal `RECONSTRUCTION_CPP` block contains `const RectBounds &sourceRect = frameContext.bounds;` after `g_pEPFLib->LookupLayoutEntry(...)`, and assigns `params.kind = kShapePreviewDescriptorKind;` after each `BuildPreviewParams(&params)`.
- [x] Document the constructor field/table map, including the two ten-entry sprite-id banks. Proof: target and class pages record offsets `+0xff`, `+0x108..+0x116`, and sprite banks at `+0x118..+0x12b` / `+0x12c..+0x13f` with the decoded values.
- [x] Document descriptor helper as a render/packet params builder and note that callers serialize packets. Proof: target, class, and file-owner docs now distinguish `BuildPreviewParams` from dialog packet serialization.
- [x] Document current/legacy paint resources: `USERPART.EPF` / `NEWBUTT.PAL` and `CAPSULE.EPD` / `NPAL3.PAL`. Proof: target, class, file-owner, mixed aggregate, and read-only data aggregate all record the current/legacy resource route.
- [x] Synchronize class/file/aggregate support docs listed above without manual generated or coverage edits. Proof: manually edited only the five leased by-* docs plus this report; validator-owned generated/project refreshes were produced only by scoped `--apply --wait-generated` validators.
- [x] Run scoped validators for each edited by-* doc after applying edits, record command ids/timestamps/exit codes/ok counts, and inspect generated output only if validators refresh it. Proof:
  - `python .\tools\validator.py --mode file --file by-memory/0x004fce80-0x004fd520.UserShapeSelectControlPaneCore.md --apply --queue-timeout 240 --wait-generated`; command_id `000000001570`, timestamp `2026-06-25T14:08:54-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed`, generated_refresh_command_id `000000001570`, generated_refresh_timestamp `2026-06-25T14:08:54-04:00`.
  - `python .\tools\validator.py --mode file --file by-class/UserShapeSelectControlPane.md --apply --queue-timeout 240 --wait-generated`; command_id `000000001571`, timestamp `2026-06-25T14:09:13-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed`, generated_refresh_command_id `000000001571`, generated_refresh_timestamp `2026-06-25T14:09:13-04:00`.
  - `python .\tools\validator.py --mode file --file by-file/UserCreateAppearanceControls.md --apply --queue-timeout 240 --wait-generated`; command_id `000000001572`, timestamp `2026-06-25T14:09:27-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed`, generated_refresh_command_id `000000001572`, generated_refresh_timestamp `2026-06-25T14:09:27-04:00`.
  - `python .\tools\validator.py --mode file --file by-memory/0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs.md --apply --queue-timeout 240 --wait-generated`; command_id `000000001573`, timestamp `2026-06-25T14:09:43-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed`, generated_refresh_command_id `000000001573`, generated_refresh_timestamp `2026-06-25T14:09:43-04:00`.
  - `python .\tools\validator.py --mode file --file by-memory/0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md --apply --queue-timeout 240 --wait-generated`; command_id `000000001574`, timestamp `2026-06-25T14:09:59-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed`, generated_refresh_command_id `000000001574`, generated_refresh_timestamp `2026-06-25T14:09:59-04:00`.
- [x] Re-read [UID:0002Q8] header/summary/C++ after validation. Proof: post-validation readback confirmed `88/91`, source-ready summary, `frameContext.bounds`, and `params.kind` assignments after `BuildPreviewParams()`.
- [x] Release leases immediately after validation. Proof: explicit unlease command after validation returned `Rejected[No active lease]` for all five files because leases had expired during validation; immediate `tools/leaser/Agents/current_leases.md` check then reported `No active leases.` A later final check showed only unrelated Agent-B001 leases, with no Agent-B007 entries.
- [x] Update this report's checklist/proof section or the implementation callback response with exact validation and lease proof before returning `FINISHED_IMPLEMENTATION`. Proof: this section records the completed callback.

## Implementation Callback Proof

- Edited by-* files: `by-memory/0x004fce80-0x004fd520.UserShapeSelectControlPaneCore.md`, `by-class/UserShapeSelectControlPane.md`, `by-file/UserCreateAppearanceControls.md`, `by-memory/0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs.md`, and `by-memory/0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md`.
- Generated freshness: `auto-generated/NexusTK/login/UserCreateAppearanceControls.cpp` now carries `validator-command-id: 000000001574`; it includes [UID:0002Q8] at `Completion:88 | Confidence:91`, the `IsSelected` body, `frameContext.bounds`, and two `params.kind` assignments after `BuildPreviewParams()`.
- Validator notes: command `000000001574` reported pre-existing unresolved reference warnings on this read-only data aggregate (`missing_ref_uid` / `missing_ref_target`) but exited `0` with `ok: 1`. No additional target-specific validator failure remains.
- Exclusions honored: no subagents were spawned; no IDA DB, manual coverage report, `by-memory/-coverage-report.md`, or `-coverage-report.md` file was manually edited; generated/project-level changes were validator-owned side effects of the required scoped `--apply --wait-generated` runs.
- MCP availability: available and used during report rework; implementation did not require new MCP access.
- Blockers remaining: none for the accepted implementation callback.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/0002Q8-UserShapeSelectControlPaneCore-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/0002Q8-UserShapeSelectControlPaneCore-source-quality.md","timestamp":"2026-06-25T14:18:52","uid":"0002Q8"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
