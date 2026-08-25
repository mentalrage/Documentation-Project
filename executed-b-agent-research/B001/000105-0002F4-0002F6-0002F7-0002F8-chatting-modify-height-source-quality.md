** TARGET-REPORT-UID:000105 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B001 Chatting Modify Height Source-Quality Report

Assignment: `B001-goal2-chatting-modify-height-source-quality-000105-0002F4-0002F6-0002F7-0002F8-20260617`

Targets:

- [UID:000105] `by-memory/0x004806d0-0x00480739.BackPaneViewportRectHelper.md`
- [UID:0002F4] `by-memory/0x004807b0-0x0048085e.ChattingModifyHeightPaneConstructor.md`
- [UID:0002F6] `by-memory/0x00480890-0x00480a7b.ChattingModifyHeightPaneOnMouseEvent.md`
- [UID:0002F7] `by-memory/0x00480a80-0x00480ac5.ChattingModifyHeightPaneCancelHotkeys.md`
- [UID:0002F8] `by-memory/0x00480ad0-0x00480ba3.ChattingModifyHeightPaneSetLineCount.md`

Report-only status: no by-memory, by-class, by-file, generated, or coverage-report files were edited. This report is the requested handoff artifact for supervisor-owned edits.

## Executive Recommendations

All five assigned target bodies are reconstructable and clear the active combined-score code gate after this reanalysis. The old blank-C++ state is no longer justified for these targets. Four targets should remain owned/emitted by `ChattingModifyHeightPane`; [UID:000105] should be moved to direct `ChattingBackPane` ownership because the function is a `ChattingBackPane` receiver method in the BackPane cluster and only uses the resize pane as a caller.

| UID | Current metadata | Recommended metadata | C++ recommendation |
| --- | --- | --- | --- |
| `000105` | `82/90`, owner `00001W`, emitter `00001W`, reconstructable `TRUE`, C++ blank | `87/91`, owner `00001R`, emitter `00001R`, reconstructable `TRUE` | Populate first-draft C++ as `ChattingBackPane::SetChatViewportLineCount(int visibleLineCount)` or same-role private method. |
| `0002F4` | `82/90`, owner `00001W`, emitter `00001W`, reconstructable `TRUE`, C++ blank | `86/91`, owner `00001W`, emitter `00001W`, reconstructable `TRUE` | Populate constructor C++. |
| `0002F6` | `82/90`, owner `00001W`, emitter `00001W`, reconstructable `TRUE`, C++ blank | `88/92`, owner `00001W`, emitter `00001W`, reconstructable `TRUE` | Populate mouse-event C++. |
| `0002F7` | `82/90`, owner `00001W`, emitter `00001W`, reconstructable `TRUE`, C++ blank | `86/90`, owner `00001W`, emitter `00001W`, reconstructable `TRUE` | Populate key/input cancel C++. |
| `0002F8` | `86/91`, owner `00001W`, emitter `00001W`, reconstructable `TRUE`, C++ blank | `88/92`, owner `00001W`, emitter `00001W`, reconstructable `TRUE` | Populate `SetLineCount` C++. |

Support recommendations:

- [UID:00001W] `by-class/ChattingModifyHeightPane.md`: raise `85/90 -> 87/91` after adding resolved field names and removing [UID:000105] as a direct class method. Keep source route through [UID:0000I5] `Chatting`.
- [UID:00001R] `by-class/ChattingBackPane.md`: raise `86/89 -> 87/90` or leave score unchanged; either way add [UID:000105] as `SetChatViewportLineCount` / viewport-line-count method because the parent already clears the direct-owner gate.
- [UID:0000I5] `by-file/Chatting.md`: no score change required. Update the proposed-contents wording so [UID:000105] appears in the `ChattingBackPane` row, not as a `ChattingModifyHeightPane` helper.
- [UID:0001VR] `by-type/by-struct/RegistryConfigUserProfileBlock.md`: add an adjacent chat display/handle settings block for `+0x28de78..+0x28de81`, immediately before the existing chat-color block at `+0x28de82..+0x28de8d`.

## Evidence Checked

I rechecked the target pages, support docs, generated coverage, current by-memory coverage rows, and local IDA export evidence. Live IDA MCP was not reachable (`127.0.0.1:13337` refused connection), so IDA evidence below is from the checked local export files:

- `C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS\NexusTK.exe.c`
- `C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS\NexusTK.exe.lst`
- `C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS\NexusTK.exe.map`

Checked support docs:

- `by-class/ChattingModifyHeightPane.md`
- `by-class/ChattingBackPane.md`
- `by-class/ChattingPane.md`
- `by-class/ChattingHandlePane.md`
- `by-file/Chatting.md`
- `by-memory/0x0047fbd0-0x0047fc6b.ChattingPaneSetVisibleRowCount.md`
- `by-memory/0x00481c10-0x00481d2a.ChattingHandlePaneConstructor.md`
- `by-memory/0x00481d60-0x0048214f.ChattingHandlePaneOnMouseEvent.md`
- `by-memory/0x00481b60-0x00481bb9.ChattingHandlePaneRenderStateCompareHelperRaw.md`
- `by-memory/0x00481bc0-0x00481c05.ChattingHandlePaneRenderStateSnapshotHelperRaw.md`
- `by-memory/0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers.md`
- `by-memory/0x004f55d0-0x004f561d.LogoPlayerPaneInputSkipHandlers.md`
- `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md`
- `by-type/by-struct/RectBoundsLayout.md`
- `by-memory/0x004b8e00-0x004b8e11.BackPaneGetBounds.md`
- `by-global/g_pChattingBackPane.md`
- `by-global/g_pChattingDisplayPane.md`
- `by-global/g_pChattingModifyHeightPane.md`
- `by-global/g_pChattingHandlePane.md`
- `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`
- `by-type/by-struct/RegistryConfigUserProfileBlock.md`
- `project-level/-resolved-multple-aliases.md`
- `project-level/-resolved.md`
- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/NexusTK/social/Chatting.cpp`

Generated output currently reports all five targets as emitting to `auto-generated/NexusTK/social/Chatting.cpp` with C++ code status `no`. For [UID:000105], generated memory coverage still reports owner/emitter `00001W`; this report recommends changing that to `00001R`.

## Heuristic / Inference Reanalysis And Validation

### Event subtype names

The mouse event byte at `event + 4` should be named with the EventMan mouse type map already documented in current EventMan support:

| Event byte | Recommended source name | Evidence |
| --- | --- | --- |
| `0` | cursor/mouse move, drag preview, or `MouseMove` | `EventManAndEventFactoryHelpers` records `0x004aa3b0` as cursor-state dispatch type `0`; `ChattingHandlePane::OnMouseEvent` uses `event+4 == 0` for hover/move. In [UID:0002F6], this path only acts while `m_dragActive` and updates a preview rectangle. |
| `1` | left-button down / mouse down | `EventManAndEventFactoryHelpers` records left-button down/double-click as types `1`/`2`. `ChattingVarietyPane::OnMouseEvent` and `ChattingHandlePane::OnMouseEvent` both consume `event+4 == 1` as a click/down path. In [UID:0002F6], this path performs the initial handle hit-test and captures drag state. |
| `3` | left-button release/up | `EventManAndEventFactoryHelpers` and `LogoPlayerPaneInputSkipHandlers` identify type `3` as left-button release/up. In [UID:0002F6], this path finalizes and persists the resize. |
| `8` | key down | `EventManAndEventFactoryHelpers` and `LogoPlayerPaneInputSkipHandlers` identify type `8` as key-down with translated key byte. [UID:0002F7] is not a clean `event+8` key-down consumer, but it is still a key/input virtual reached through the same secondary event interface family. |

Rejected alternatives:

- Treating `0` as mouse down and `1` as drag move is rejected by the existing EventMan map and by sibling chat handlers.
- Treating `3` as a generic cancel message is rejected because EventMan left-release evidence and [UID:0002F6] drag-finalization behavior agree.
- Treating [UID:0002F7] as an `OnChar` text-input method is rejected because it reads a key/input payload pointer at `event+0x0c`, does not insert text, restores layout state, and always returns false. It is better modeled as `OnKeyEvent` or `CancelDragOnKeyEvent`.

### `dword_67ADE0 + 0x118`

`dword_67ADE0` is [UID:0002XE] `g_pChattingHandlePane`. The field at full-object `+0x118` is the persisted secondary-chat widget enable flag. Recommended source-facing name: `m_secondaryChatEnabled` or `m_secondaryChatWidgetEnabled`; use the shorter `m_secondaryChatEnabled` in first-draft C++.

Evidence:

- `ChattingHandlePaneConstructor` loads this byte from `g_pConfig + 2678400` / `+0x28de80` and immediately calls the enable/disable pair for `*(g_pChattingDisplayPane + 0xfc)`.
- `ChattingHandlePaneOnMouseEvent` toggles this field for hit-test index `3`, persists it back to `g_pConfig + 2678400`, and refreshes dependent panes.
- `ChattingBackPaneUpdateVisibility`, `ChattingModifyHeightPaneOnMouseEvent`, and `ChattingModifyHeightPaneOnPaint` read this same field as a gate for expanded/secondary chat state.
- The retained ChattingHandlePane render-state compare/snapshot helpers document the same field as `secondaryChatEnabled`.

Rejected alternatives:

- `chatBubbleEnabled`, `chatFilterEnabled`, or generic `rightButtonState`: rejected because the constructor and mouse handler apply the field to the display pane's secondary scroll/widget enable/disable path, not merely to a paint button.
- Leaving the field as `field_118`: no longer necessary for the assigned targets.

### `dword_67A7C8 + 2678392`

`dword_67A7C8` is [UID:00028Q] `g_pConfig`. The offset `2678392` is `0x28de78`, verified by `tools/int_convert.py` and by the IDA listing at `0x004f7fcf` (`push dword ptr [eax+28DE78h]`). Recommended source-facing name: `m_chatVisibleLineCount` or `m_chatVisibleRowCount`; use `m_chatVisibleLineCount` because [UID:0002F6] and [UID:0002F8] compute visible line count before calling `ChattingPane::SetVisibleRowCount`.

Evidence:

- `InitializeMainUiGraph` constructs `ChattingModifyHeightPane`, positions it, then calls `sub_480AD0(v11, *(g_pConfig + 0x28de78))`.
- `ChattingModifyHeightPaneOnMouseEvent` commits the drag result back to `g_pConfig + 2678392`.
- The immediately following config fields are the documented ChattingHandlePane state group:
  - `2678396` / `0x28de7c`: handle mode index / three-state chat display mode.
  - `2678400` / `0x28de80`: secondary chat enabled byte.
  - `2678401` / `0x28de81`: persisted left button/toggle byte.
  - `2678402..2678413` / `0x28de82..0x28de8d`: chat color pairs documented by `RegistryConfigUserProfileBlock.md`.
- This tight neighborhood rules out an unrelated option-field interpretation.

Rejected alternatives:

- The current [UID:0002F6] raw evidence line `+28DDB8h` is rejected as stale/incorrect. The correct hexadecimal offset is `+0x28DE78`.
- Naming it `m_chatPixelHeight` is rejected because the stored value is a line count, not `13 * lineCount`; `ChattingPane::SetVisibleRowCount` stores the pixel height separately at `ChattingPane + 0x134`.
- Naming it a generic option dword is less useful than the high-probability `m_chatVisibleLineCount`, given both initializer-read and drag-write behavior.

### `ChattingModifyHeightPane` fields

The object has a secondary event-interface view at full-object `+0xa0`. In [UID:0002F6] and [UID:0002F7], the decompiler's `this` pointer is the adjusted secondary view, so secondary offsets must be translated back to full-object offsets:

| Secondary-view offset | Full-object offset | Recommended field name | Evidence |
| --- | --- | --- | --- |
| `+0x58` | `+0xf8` | `m_dragActive` | Constructor clears full `+0xf8`; mouse down sets secondary `+0x58`; mouse move/up and cancel test/clear it. |
| `+0x5c` | `+0xfc` | `m_dragAnchorY` | Mouse down stores the first event coordinate used by the drag math; move/up subtract this stored value from the clamped vertical position to compute handle top. |
| `+0x60` | `+0x100` | `m_handleRect` or `m_currentHandleRect` | Constructor initializes full `+0x100`; mouse down hit-tests it; cancel restores it; mouse-up and `SetLineCount` store the committed handle rectangle. |

Use `m_handleRect` in first-draft code. The field is both the current/committed handle rectangle and the cancel-restore rectangle; no second rectangle member is proven.

Rejected alternatives:

- Treating `this+0x58` and `this+0x5c` as full-object offsets is rejected because vtable slots at `0x00614e68` and `0x00614e74` are secondary-interface entries and the decompilation repeatedly uses `this - 0xa0` to call owner-pane virtuals.
- Naming `m_dragAnchorY` as `m_dragAnchorX` is rejected for this target: the value from `event+8` drives vertical top/clamp math, and all rectangle updates are vertical.
- Naming `m_handleRect` as a generic `m_rect2` or `field_100` is no longer necessary.

### Helper/source names

Recommended source-facing helper names:

| Binary/helper | Recommended name | Evidence/reasoning |
| --- | --- | --- |
| [UID:000105] `0x004806d0` | `ChattingBackPane::SetChatViewportLineCount(int visibleLineCount)` | Receiver is `g_pChattingBackPane`; body sits in the `ChattingBackPane` cluster after constructor/destructor and before update virtual; it calls `BackPane::GetBounds`, applies viewport rect `(9, 700 - 13*n, 816, 720)`, and invalidates the back pane. |
| `0x004b8e00` | `BackPane::GetBounds` | Existing [UID:000161] accessor copies `this+0x44` bounds. |
| `0x004b7c50` | `InitRectBounds` | Existing RectBounds docs and resolved aliases identify this free helper. |
| `0x004b7e80` | `PointInRect` / `PointInRect_4B7E80` | Existing RectGeometry and RectBoundsLayout docs identify the half-open point-in-rect helper. The binary argument order is historical/provisional; source code can use a point-style wrapper. |
| [UID:0002EW] `0x0047fbd0` | `ChattingPane::SetVisibleRowCount(int visibleRows)` | Already populated first-draft C++; stores visible pixel height and synchronizes scroll state. |
| Config write route | `g_pConfig->m_chatVisibleLineCount` | `g_pConfig` is canonical; offset and initializer/writeback prove line-count role. |

Rejected alternatives:

- Keeping [UID:000105] owned by `ChattingModifyHeightPane`: rejected. Sole caller is the resize pane, but ownership should follow the receiver and semantic state. The method takes the back pane as `this`, lives in the BackPane cluster, and mutates only BackPane geometry. The caller relationship remains documented.
- Keeping generated name `BackPane::SetScrollViewport`: partially descriptive but less source-specific than `SetChatViewportLineCount`; it also hides the `visibleLineCount` input semantics.
- Moving [UID:000105] to file-level `Chatting` instead of `ChattingBackPane`: possible if final source proves a file-local helper, but lower-probability than a `ChattingBackPane` method because the binary is a receiver-style `thiscall` over the back-pane object.

### Source placement

All targets remain under [UID:0000I5] `Chatting`, proposed path `NexusTK/social/Chatting.cpp`.

Specific placement:

- [UID:000105] should be emitted through [UID:00001R] `ChattingBackPane`, still into `Chatting.cpp`.
- [UID:0002F4], [UID:0002F6], [UID:0002F7], and [UID:0002F8] should be emitted through [UID:00001W] `ChattingModifyHeightPane`, into `Chatting.cpp`.
- The config field declaration belongs to `RegistryConfig`, not `Chatting.cpp`; `Chatting.cpp` should only consume it through `g_pConfig`.

### Historical-assumption reanalysis

Historical docs kept these targets blank mostly because exact field/helper names were unresolved. That is now too conservative for the five assigned targets:

- Event names are now sourced from EventMan support docs and sibling pane handlers.
- `dword_67ADE0 + 0x118` is now tied to ChattingHandlePane secondary-chat enable behavior.
- `dword_67A7C8 + 2678392` is now corrected to `+0x28de78` and tied to visible line-count persistence.
- `this+0x58/+0x5c/+0x100` field names are source-quality role names after normalizing the secondary subobject.
- `sub_4B8E00`, `sub_4B7C50`, `sub_4B7E80`, and `sub_47FBD0` have usable support-doc names.
- [UID:000105] owner caveat has a better answer: direct owner should be `ChattingBackPane`, not `ChattingModifyHeightPane`.

Remaining uncertainty is spelling, not behavior or source shape. Exact original member names such as `m_handleRect` versus `m_currentHandleRect`, or `SetChatViewportLineCount` versus `SetVisibleLineCount`, cannot be proven from current evidence, but role-based first-draft C++ is defensible.

## Target-by-Target Findings

### [UID:000105] BackPaneViewportRectHelper

Current page summary is mostly behavior-correct but owner-cautious. IDA export confirms:

- Modeled function `sub_4806D0`, range `0x004806d0-0x00480739`.
- Map entry immediately after `ChattingBackPane` constructor/destructor cluster and before `ChattingBackPaneUpdateVisibility`.
- Sole code caller at `0x0048093e` inside `ChattingModifyHeightPane::OnMouseEvent`.
- Receiver is the pane pointer passed in `ecx`; caller passes `g_pChattingBackPane`.
- Calls `BackPane::GetBounds`.
- Builds `RectBounds(9, 700 - 13 * visibleLineCount, 816, 720)`.
- Applies through vtable slot `+0x2c` with false/zero.
- Invalidates through vtable slot `+0x20` over inherited rect at `+0x44`.

Recommendation:

- Rename role from generic `BackPaneViewportRectHelper` to source-facing `ChattingBackPane::SetChatViewportLineCount`.
- Change `CANONICAL_OWNER:00001W` to `CANONICAL_OWNER:00001R`.
- Change `EMITTER_UIDS:00001W` to `EMITTER_UIDS:00001R`.
- Raise `82/90 -> 87/91`.
- Populate C++.

### [UID:0002F4] ChattingModifyHeightPaneConstructor

IDA export confirms:

- Calls `Pane::Pane(this, 1)` / `sub_544460((char *)this, 1)`.
- Stores `g_pChattingModifyHeightPane` (`dword_67ADD4`).
- Installs three `ChattingModifyHeightPane` vtable views at `+0x00`, `+0xa0`, `+0xa4`.
- Clears `this+0xf8`.
- Initializes `this+0x100` to `RectBounds(792, 590, 807, 605)`.
- Single construction caller `0x004f7f71` in `InitializeMainUiGraph`.
- Caller then positions the pane with the same startup rect and immediately calls `SetLineCount(g_pConfig->m_chatVisibleLineCount)`.

Inference:

- `this+0xf8` is `m_dragActive`.
- `this+0x100` is `m_handleRect`.
- The startup rectangle is source-authored initialization/fallback geometry. It is not a final persisted layout value because `InitializeMainUiGraph` immediately calls [UID:0002F8] with the persisted line count.

Recommendation:

- Keep owner/emitter `00001W`.
- Raise `82/90 -> 86/91`.
- Populate constructor C++.

### [UID:0002F6] ChattingModifyHeightPaneOnMouseEvent

IDA export confirms:

- Gate: `if (!*(g_pChattingHandlePane + 0x118)) return 0`.
- Event byte `event+4`:
  - `0`: drag preview path while `m_dragActive`.
  - `1`: mouse/left-button down; hit-tests `m_handleRect`; sets drag active and drag anchor.
  - `3`: left-button release/up; finalizes line count.
- Full/secondary offset mapping:
  - secondary `+0x58` = full `+0xf8` = `m_dragActive`.
  - secondary `+0x5c` = full `+0xfc` = `m_dragAnchorY`.
  - secondary `+0x60` = full `+0x100` = `m_handleRect`.
- Preview clamps `currentRectTop + eventCoord` to `50..650` and applies `(792, clampedY - m_dragAnchorY, 807, clampedY - m_dragAnchorY + 15)`.
- Commit clamps the same value, computes `visibleLineCount = (710 - clampedY) / 13`, clamps to minimum `4`, calls [UID:000105], calls `ChattingPane::SetVisibleRowCount`, sets/applies/stores handle rect `(792, 693 - 13*n, 807, 708 - 13*n)`, and writes `g_pConfig + 0x28de78`.

Correction required:

- Current page raw evidence says `[dword_67A7C8+28DDB8h]`; replace with `[g_pConfig+28DE78h]` / `g_pConfig->m_chatVisibleLineCount`.

Recommendation:

- Keep owner/emitter `00001W`.
- Raise `82/90 -> 88/92`.
- Populate C++.

### [UID:0002F7] ChattingModifyHeightPaneCancelHotkeys

IDA export confirms:

- Modeled function `0x00480a80-0x00480ac5`, vtable-only data xref `0x00614e74`.
- Reads first byte from pointer at `event+0x0c`: `**(_BYTE **)(event + 12)`.
- Accepts `0x2f`, `0x30`, or `0x42` (`'/'`, `'0'`, `'B'`).
- Clears secondary `this+0x58` / full `m_dragActive`.
- Restores `m_handleRect` through owner vtable slot `+0x2c`.
- Invalidates owner inherited rect at `+0x44` through vtable slot `+0x20`.
- Always returns `0`.

Inference:

- This is a virtual key/input filter, not text insertion and not a character handler. Best source-facing method name is `OnKeyEvent` if matching class vtable conventions, or role name `CancelDragOnKeyEvent` if the exact virtual name is kept provisional.
- Accepted byte names are best recorded as key bytes/commands `'/'`, `'0'`, and `'B'`. No safe semantic labels for those command keys are proven.

Rejected alternatives:

- `OnChar`: rejected because the body does not consume/insert text and returns false after side effects.
- `CancelHotkeys` as a final source name: acceptable as a doc filename, but too role-specific for a vtable override unless final class declarations prove it.

Recommendation:

- Keep owner/emitter `00001W`.
- Raise `82/90 -> 86/90`.
- Populate first-draft C++ using `OnKeyEvent` or a role-named equivalent.

### [UID:0002F8] ChattingModifyHeightPaneSetLineCount

IDA export confirms:

- Modeled function `0x00480ad0-0x00480ba3`.
- Sole caller `0x004f7fd5` in `InitializeMainUiGraph`.
- Effective count logic:
  - default `40`;
  - if requested `<= 50`, use requested;
  - if result `< 4`, clamp to `4`.
- Updates `g_pChattingBackPane` inline:
  - `BackPane::GetBounds`;
  - `InitRectBounds(9, 700 - 13*n, 816, 720)`;
  - vtable `SetBounds(..., false)`;
  - vtable invalidation over inherited rect.
- Calls `g_pChattingDisplayPane->SetVisibleRowCount(n)`.
- Builds handle rect `(792, 693 - 13*n, 807, 708 - 13*n)`.
- Applies the handle rect through vtable slot `+0x2c`.
- Stores the handle rect to full `this+0x100`.

Inference:

- Source method name `SetLineCount` is acceptable because Wave2 reports it and the initializer caller uses persisted visible line count. `SetVisibleLineCount` would also be readable but is less tied to existing evidence.
- `this+0x100` should be `m_handleRect`.

Recommendation:

- Keep owner/emitter `00001W`.
- Raise `86/91 -> 88/92`.
- Populate first-draft C++.

## First-Draft C++ Blocks

These blocks are intended for the formal `RECONSTRUCTION_CPP` blocks on the exact target pages. Names are role-based source names; exact original spelling remains unproven but no longer blocks first-draft output.

### [UID:000105] recommended C++

```cpp
void ChattingBackPane::SetChatViewportLineCount(int visibleLineCount)
{
    RectBounds currentBounds;
    GetBounds(&currentBounds);

    RectBounds viewport;
    InitRectBounds(&viewport, 9, 700 - 13 * visibleLineCount, 816, 720);
    SetBounds(viewport, false);

    InvalidateRect(m_rect);
}
```

If supervisor prefers to avoid introducing a new public-looking method name, use the same body with `UpdateChatViewportForLineCount` or `SetVisibleLineViewport`. The direct owner should still be [UID:00001R] `ChattingBackPane`.

### [UID:0002F4] recommended C++

```cpp
ChattingModifyHeightPane::ChattingModifyHeightPane()
    : Pane(1),
      m_dragActive(false)
{
    g_pChattingModifyHeightPane = this;
    InitRectBounds(&m_handleRect, 792, 590, 807, 605);
}
```

Do not initialize `m_dragAnchorY` in the formal block unless class-layout work proves the source did so elsewhere; the binary constructor only clears `m_dragActive` and initializes `m_handleRect`.

### [UID:0002F6] recommended C++

```cpp
bool ChattingModifyHeightPane::OnMouseEvent(const PaneMouseEvent *event)
{
    if (!g_pChattingHandlePane->m_secondaryChatEnabled)
        return false;

    switch (event->type) {
    case kPaneMouseMove:
        if (!m_dragActive)
            return false;
        {
            RectBounds currentBounds;
            GetBounds(&currentBounds);

            int clampedY = currentBounds.top + event->mouseY;
            if (clampedY < 50)
                clampedY = 50;
            else if (clampedY > 650)
                clampedY = 650;

            RectBounds previewRect;
            InitRectBounds(&previewRect,
                           792,
                           clampedY - m_dragAnchorY,
                           807,
                           clampedY - m_dragAnchorY + 15);
            SetBounds(previewRect, false);
        }
        return true;

    case kPaneMouseLeftButtonDown:
        if (PointInRect(event->mouseY, event->mouseX, &m_handleRect)) {
            m_dragActive = true;
            m_dragAnchorY = event->mouseY;
            return true;
        }
        return false;

    case kPaneMouseLeftButtonUp:
        if (!m_dragActive)
            return false;
        {
            m_dragActive = false;

            RectBounds currentBounds;
            GetBounds(&currentBounds);

            int clampedY = currentBounds.top + event->mouseY;
            if (clampedY < 50)
                clampedY = 50;
            else if (clampedY > 650)
                clampedY = 650;

            int visibleLineCount = (710 - clampedY) / 13;
            if (visibleLineCount < 4)
                visibleLineCount = 4;

            g_pChattingBackPane->SetChatViewportLineCount(visibleLineCount);
            g_pChattingDisplayPane->SetVisibleRowCount(visibleLineCount);

            RectBounds handleRect;
            InitRectBounds(&handleRect,
                           792,
                           693 - 13 * visibleLineCount,
                           807,
                           708 - 13 * visibleLineCount);
            SetBounds(handleRect, false);
            m_handleRect = handleRect;

            g_pConfig->m_chatVisibleLineCount = visibleLineCount;
        }
        return true;
    }

    return false;
}
```

Coordinate note: existing `RectGeometryHelpers` documentation records the binary `PointInRect_4B7E80` argument order as `y, x, rect`; `event+8` is the coordinate used for vertical drag math. If a later shared `PaneMouseEvent` declaration names fields differently, keep the same binary order but update the source field names.

### [UID:0002F7] recommended C++

```cpp
bool ChattingModifyHeightPane::OnKeyEvent(const PaneKeyEvent *event)
{
    const unsigned char key = event->payload[0];

    if (key == '/' || key == '0' || key == 'B') {
        m_dragActive = false;
        SetBounds(m_handleRect, false);
        InvalidateRect(m_rect);
    }

    return false;
}
```

If the final vtable declaration proves this slot is not named `OnKeyEvent`, use `CancelDragOnKeyEvent` as the private/source-facing role name. The behavior and C++ readiness do not depend on exact spelling.

### [UID:0002F8] recommended C++

```cpp
void ChattingModifyHeightPane::SetLineCount(int requestedLineCount)
{
    int visibleLineCount = 40;
    if (requestedLineCount <= 50)
        visibleLineCount = requestedLineCount;
    if (visibleLineCount < 4)
        visibleLineCount = 4;

    RectBounds backBounds;
    g_pChattingBackPane->GetBounds(&backBounds);

    RectBounds viewport;
    InitRectBounds(&viewport, 9, 700 - 13 * visibleLineCount, 816, 720);
    g_pChattingBackPane->SetBounds(viewport, false);
    g_pChattingBackPane->InvalidateRect(g_pChattingBackPane->m_rect);

    g_pChattingDisplayPane->SetVisibleRowCount(visibleLineCount);

    RectBounds handleRect;
    InitRectBounds(&handleRect,
                   792,
                   693 - 13 * visibleLineCount,
                   807,
                   708 - 13 * visibleLineCount);
    SetBounds(handleRect, false);
    m_handleRect = handleRect;
}
```

This block intentionally inlines the back-pane viewport update, matching the observed `sub_480AD0` body. [UID:0002F6] calls [UID:000105], but [UID:0002F8] does not call that helper in the binary.

## Recommended By-* Doc Changes

Report-only note: these are supervisor-executable recommendations, not edits already made.

### `by-memory/0x004806d0-0x00480739.BackPaneViewportRectHelper.md`

Recommended header values:

```text
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00001R | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00001R | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Recommended status text replacement:

```text
- Disposition: reconstructable NexusTK project code.
- Entity kind: ChattingBackPane viewport-line-count method.
- Source-facing name: `ChattingBackPane::SetChatViewportLineCount(int visibleLineCount)` or equivalent role name.
- Owner: [UID:00001R][ChattingBackPane](by-class/ChattingBackPane.md).
- Source placement: [UID:0000I5][Chatting](by-file/Chatting.md), proposed `NexusTK/social/Chatting.cpp`.
- Confidence: very strong for boundary, receiver, rectangle math, sole resize-pane caller, and first-draft C++; medium only for exact original method spelling.
```

Recommended ownership note:

```text
The earlier `ChattingModifyHeightPane` owner was caller-biased. IDA export evidence shows this body is a receiver-style method over the back pane pointer passed in `ecx`, and the only state it reads/mutates is BackPane geometry. The sole caller remains `ChattingModifyHeightPane::OnMouseEvent`, but caller evidence does not override direct semantic ownership.
```

Add the [UID:000105] C++ block above to the formal reconstruction block.

### `by-memory/0x004807b0-0x0048085e.ChattingModifyHeightPaneConstructor.md`

Recommended header values:

```text
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Recommended open-question replacement:

```text
The constructor field roles are now source-quality for first-draft C++: full-object `+0xf8` is `m_dragActive`, and full-object `+0x100` is `m_handleRect`. The startup rectangle `(792, 590, 807, 605)` is an embedded initialization/fallback rectangle; `InitializeMainUiGraph` immediately calls `SetLineCount(g_pConfig->m_chatVisibleLineCount)`, so this fixed constructor rectangle should not be treated as the persisted final layout.
```

Add the [UID:0002F4] C++ block above to the formal reconstruction block.

### `by-memory/0x00480890-0x00480a7b.ChattingModifyHeightPaneOnMouseEvent.md`

Recommended header values:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Recommended behavior-text replacements:

```text
This method handles dragging the chat-height handle. It first requires `g_pChattingHandlePane->m_secondaryChatEnabled` (`dword_67ADE0 + 0x118`) to be enabled; otherwise it returns `0`.

The event subtype byte at `event + 4` is source-facing mouse event kind:

- `0`: cursor/mouse move used for drag preview.
- `1`: left-button down / drag start.
- `3`: left-button release/up / drag commit.

Because this virtual is reached through the secondary event-interface view at full object `+0xa0`, decompiler offsets `this+0x58`, `this+0x5c`, and `this+0x60` correspond to full-object fields `+0xf8`, `+0xfc`, and `+0x100`. Recommended field names are `m_dragActive`, `m_dragAnchorY`, and `m_handleRect`.
```

Correct the raw-code evidence line:

```text
00480997  mov     [g_pConfig+28DE78h], visibleLineCount
```

Recommended config sentence:

```text
The persisted line-count field is `g_pConfig->m_chatVisibleLineCount` at decimal `2678392` / hexadecimal `0x28de78`, immediately before the documented ChattingHandlePane config fields at `+0x28de7c/+0x28de80/+0x28de81` and the chat-color byte pairs at `+0x28de82..+0x28de8d`.
```

Add the [UID:0002F6] C++ block above to the formal reconstruction block.

### `by-memory/0x00480a80-0x00480ac5.ChattingModifyHeightPaneCancelHotkeys.md`

Recommended header values:

```text
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Recommended open-question replacement:

```text
The callback should be treated as a key/input event filter, not as text-character insertion. It reads a key/input payload byte through `event+0x0c`, accepts `'/'`, `'0'`, and `'B'`, clears `m_dragActive`, restores `m_handleRect`, invalidates the inherited pane rect, and always returns false. Exact original virtual spelling remains provisional; use `OnKeyEvent` or role name `CancelDragOnKeyEvent` for first-draft C++.
```

Add the [UID:0002F7] C++ block above to the formal reconstruction block.

### `by-memory/0x00480ad0-0x00480ba3.ChattingModifyHeightPaneSetLineCount.md`

Recommended header values:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Recommended open-question replacement:

```text
`SetLineCount` is source-ready as a role-based method name. The method applies a visible chat line count, not total content lines. The stored rectangle at full object `+0x100` is the committed resize-handle rectangle; recommended field name is `m_handleRect`. Exact original spelling such as `SetVisibleLineCount` or `m_currentHandleRect` remains unproven but is not a first-draft C++ blocker.
```

Add the [UID:0002F8] C++ block above to the formal reconstruction block.

### `by-class/ChattingModifyHeightPane.md`

Recommended metadata:

```text
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Recommended field-layout addition after Method Notes:

```text
## Field Notes

The resize/input virtuals use a secondary event-interface `this` pointer at full object `+0xa0`. Normalize secondary offsets before naming fields:

| Full-object offset | Secondary-view offset | Recommended name | Role |
| --- | --- | --- | --- |
| `+0xf8` | `+0x58` | `m_dragActive` | Set on left-button down, tested during move/up, cleared on commit/cancel. |
| `+0xfc` | `+0x5c` | `m_dragAnchorY` | Initial vertical drag coordinate used for preview/commit top math. |
| `+0x100` | `+0x60` | `m_handleRect` | Current/committed handle rectangle, hit-tested and restored on cancel. |
```

Recommended Method Notes change:

- Remove [UID:000105] from the `ChattingModifyHeightPane` method table, or mark it as an external `ChattingBackPane` method called by `OnMouseEvent`.
- Keep [UID:0002F4], [UID:0002F6], [UID:0002F7], [UID:0002F8], [UID:0002F9], destructor, and scalar destructor rows.

### `by-class/ChattingBackPane.md`

Recommended metadata:

```text
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Recommended Method Notes row insertion after destructor:

```text
| `SetChatViewportLineCount` | [UID:000105][0x004806d0-0x00480739.BackPaneViewportRectHelper](by-memory/0x004806d0-0x00480739.BackPaneViewportRectHelper.md) | Applies the chat viewport rectangle `(9, 700 - 13*n, 816, 720)` for the selected visible-line count and invalidates the back pane. |
```

Recommended Evidence Map row:

```text
| [UID:000105][0x004806d0-0x00480739.BackPaneViewportRectHelper](by-memory/0x004806d0-0x00480739.BackPaneViewportRectHelper.md) | Receiver-style BackPane method called by the resize handle; confirms `GetBounds`, chat viewport rectangle math, `SetBounds`, and inherited-rect invalidation. |
```

### `by-file/Chatting.md`

Recommended proposed-contents changes:

- In `ChattingBackPane` row, change role text to include:

```text
Transparent chat background pane tied to chat handle visibility/mode state, including visible-line viewport method [UID:000105][0x004806d0-0x00480739.BackPaneViewportRectHelper](by-memory/0x004806d0-0x00480739.BackPaneViewportRectHelper.md).
```

- In `ChattingModifyHeightPane` row, remove `helper at [UID:000105]` and use:

```text
Drag handle for changing visible chat line count, updating `ChattingBackPane` and `ChattingPane`, and persisting the count to config.
```

### `by-type/by-struct/RegistryConfigUserProfileBlock.md`

Recommended insertion immediately before `## Adjacent Chat Color Block`:

```text
## Adjacent Chat Display/Handle Settings Block

The chat display/handle settings immediately precede the chat-color pairs. These offsets are owned by `RegistryConfig` storage and consumed by `Chatting.cpp`.

| Offset | Size | Recommended role name | Evidence |
| --- | ---: | --- | --- |
| `+0x28de78` | 4 | `m_chatVisibleLineCount` / visible chat line count | Read by `InitializeMainUiGraph` before calling `ChattingModifyHeightPane::SetLineCount`; written by `ChattingModifyHeightPane::OnMouseEvent` after drag commit. |
| `+0x28de7c` | 4 | `m_chatHandleModeIndex` / chat display mode index | Loaded and persisted by `ChattingHandlePane`; cycled modulo 3 by handle hit-test index 2. |
| `+0x28de80` | 1 | `m_secondaryChatEnabled` | Loaded and persisted by `ChattingHandlePane`; controls the secondary chat widget and gates ChattingBackPane/resize-handle behavior. |
| `+0x28de81` | 1 | `m_chatHandleLeftToggle` | Loaded and persisted by `ChattingHandlePane`; toggled by handle hit-test index 0. |

Exact original field spellings remain unproven, but the roles and offsets are source-quality for first-draft Chatting.cpp consumers.
```

## Exact Replacement Rows For `by-memory/-coverage-report.md`

Replace only the five target rows; do not edit padding rows. These rows use current coverage formatting and are intended for supervisor application.

```text
        - [UID:000105][0x004806d0-0x00480739.BackPaneViewportRectHelper](by-memory/0x004806d0-0x00480739.BackPaneViewportRectHelper.md) 0x004806d0-0x00480739 | helper method | ChattingBackPaneSetChatViewportLineCount : reconstructable : 87% : very-strong : B001 2026-06-17 source-quality reanalysis moves direct owner/emitter to ChattingBackPane, not ChattingModifyHeightPane; IDA export confirms receiver-style BackPane method, exact `BackPane::GetBounds` call, `InitRectBounds(9, 700 - 13*n, 816, 720)`, vtable `SetBounds(..., false)`, inherited-rect invalidation, sole drag-commit caller at `0x0048093e`, source placement under Chatting.cpp, and first-draft C++ readiness with role-based method name `SetChatViewportLineCount`.
        - [UID:0002F4][0x004807b0-0x0048085e.ChattingModifyHeightPaneConstructor](by-memory/0x004807b0-0x0048085e.ChattingModifyHeightPaneConstructor.md) 0x004807b0-0x0048085e | constructor | ChattingModifyHeightPaneConstructor : reconstructable : 86% : strong : B001 2026-06-17 source-quality reanalysis resolves constructor fields as `m_dragActive` at full `+0xf8` and `m_handleRect` at `+0x100`, confirms the single InitializeMainUiGraph caller `0x004f7f71`, base `Pane(1)` construction, `g_pChattingModifyHeightPane` store, three vtable writes, embedded startup handle rect `(792,590,807,605)`, immediate persisted-line-count follow-up caller context, and first-draft constructor C++ readiness.
        - [UID:0002F6][0x00480890-0x00480a7b.ChattingModifyHeightPaneOnMouseEvent](by-memory/0x00480890-0x00480a7b.ChattingModifyHeightPaneOnMouseEvent.md) 0x00480890-0x00480a7b | virtual method | ChattingModifyHeightPaneOnMouseEvent : reconstructable : 88% : very-strong : B001 2026-06-17 source-quality reanalysis resolves event kinds `0` cursor/mouse move, `1` left-button down, and `3` left-button release/up; identifies `g_pChattingHandlePane->m_secondaryChatEnabled` at `+0x118`, secondary/full offset mapping for `m_dragActive`, `m_dragAnchorY`, and `m_handleRect`, `g_pConfig->m_chatVisibleLineCount` at decimal `2678392` / `0x28de78`, back-pane/display-pane update calls, handle rect commit, rejected stale `+0x28ddb8` offset, and first-draft C++ readiness.
        - [UID:0002F7][0x00480a80-0x00480ac5.ChattingModifyHeightPaneCancelHotkeys](by-memory/0x00480a80-0x00480ac5.ChattingModifyHeightPaneCancelHotkeys.md) 0x00480a80-0x00480ac5 | virtual input helper | ChattingModifyHeightPaneCancelHotkeys : reconstructable : 86% : strong : B001 2026-06-17 source-quality reanalysis resolves this as a key/input drag-cancel filter, not text insertion; IDA export confirms payload-byte keys `'/'`, `'0'`, and `'B'`, secondary/full mapping to `m_dragActive` and `m_handleRect`, owner `SetBounds(m_handleRect,false)` restore, inherited-rect invalidation, vtable-only reachability, always-false return, and first-draft C++ readiness with provisional `OnKeyEvent` / `CancelDragOnKeyEvent` source role.
        - [UID:0002F8][0x00480ad0-0x00480ba3.ChattingModifyHeightPaneSetLineCount](by-memory/0x00480ad0-0x00480ba3.ChattingModifyHeightPaneSetLineCount.md) 0x00480ad0-0x00480ba3 | layout helper | ChattingModifyHeightPaneSetLineCount : reconstructable : 88% : very-strong : B001 2026-06-17 source-quality reanalysis validates `SetLineCount` as first-draft C++ ready; IDA export confirms sole InitializeMainUiGraph caller `0x004f7fd5`, exact fallback/pass-through clamp (`>50` falls back to 40, `<4` clamps to 4), `g_pChattingBackPane` viewport update through `BackPane::GetBounds` and `InitRectBounds`, `g_pChattingDisplayPane->SetVisibleRowCount`, handle rect `(792, 693 - 13*n, 807, 708 - 13*n)`, `m_handleRect` store at full `+0x100`, and source placement under Chatting.cpp.
```

## Validation Notes

- This report was created under `tools/leaser/Agents/Agent-B001/research/` only.
- No supervisor-owned `by-memory/-coverage-report.md` edit was made.
- No by-memory, by-class, by-file, generated, or project-level docs were edited.
- The exact report path is `tools/leaser/Agents/Agent-B001/research/000105-0002F4-0002F6-0002F7-0002F8-chatting-modify-height-source-quality.md`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/000105-0002F4-0002F6-0002F7-0002F8-chatting-modify-height-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:18","uid":"000105"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
