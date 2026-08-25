** TARGET-REPORT-UID:0002ET **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B001-goal2 Chatting Pane Remaining Handlers Source-Quality Report

Assignment: `B001-goal2-chatting-pane-remaining-handlers-source-quality-0002ET-0002EV-0002EZ-20260617`

Targets:

- [UID:0002ET] `by-memory/0x0047f6f0-0x0047f890.ChattingPaneKeyboardScrollHandler.md`
- [UID:0002EV] `by-memory/0x0047f8d0-0x0047fbc5.ChattingPaneOnPaint.md`
- [UID:0002EZ] `by-memory/0x0047fd70-0x0047ff80.ChatPacketType13Handler.md`

Requested output was report-only. I did not edit by-memory, by-class, by-file, generated source, coverage rows, IDA state, or generated reports.

## Evidence Sources And IDA Availability

Fresh IDA MCP was not available in this run. `list_mcp_resources` returned no configured resources, and a probe to `http://127.0.0.1:13337/mcp` failed with `Unable to connect to the remote server`. This report therefore relies on existing live-IDA-backed documentation, existing Agent reports, generated hook/function-data JSON, recovered snippets under `re-agent/reports/code`, and the generated `auto-generated/NexusTK/social/Chatting.cpp` routing output.

Important inspected evidence:

- Target docs for `0002ET`, `0002EV`, and `0002EZ`.
- Support docs: `ChattingPane`, `Chatting`, `ChattingUI`, `0002ES`, `0002EQ`, `0002EU`, `0002EW`, `0002EX`, `ColorStringChattingMessage`, `g_useEpfAssets`, `ScrollablePaneCore`, GrafPort clip/draw-state helpers, `RegionAndMotionRect`, `SurfaceRenderCallbackTable`, `PacketBufferScalarBigEndianReadHelpers`, `g_activeMapPane`, and `g_pCollectionData`.
- Existing accepted reports: B003 `0002EP-0002EU-0002EW-chatting-pane-core-source-quality.md`, B001 `0002EX-0002F0-chatting-source-quality-20260615.md`, and B001 `0002EO-0002ES-chatting-message-ingress-source-quality.md`.
- Recovered/decompiled snippets:
  - `re-agent/reports/code/0x0047f6f0_ChattingPane_virt_meth_0x47f6f0.cpp`
  - `re-agent/reports/code/0x0047f8d0_ChattingPane_virt_meth_0x47f8d0.cpp`
  - `hooks-generation/tests/function_data/ida/0x0047fd70.json`
  - `hooks-generation/tests/function_data/ida/0x0047f8d0.json`
  - `hooks-generation/tests/function_data/ida/0x0055eae0.json`

## Executive Recommendations

Recommended target metadata:

| UID | Current | Recommended | Owner/emitter | C++ |
| --- | ---: | ---: | --- | --- |
| `0002ET` | `84/88` | `86/90` | keep `00001X` / `00001X` | populate first-draft C++ |
| `0002EV` | `84/88` | `86/90` | keep `00001X` / `00001X` | populate first-draft C++ |
| `0002EZ` | `84/88` | `86/90` | keep `0000I5` / `0000I5` | populate first-draft C++ |

The current C++ gate is satisfied for all three: each target is `RECONSTRUCTABLE:TRUE`, each has a nonblank emitter route to `Chatting.cpp`, and `(completion + confidence) / 2` is already `86` before this reanalysis. The remaining uncertainties are original source spellings, not behavior or route blockers. Use role-based names as the existing B003 first drafts do.

Primary behavior correction:

- `0002EZ` currently says current-layout subtype `1` is suppressed when the local state byte is not `2`. The recovered decompile shows the opposite. In both current and old layouts, subtype `1` is suppressed when the local state byte equals `2`; otherwise it appends the highlighted message (`14/128` current, `12/143` old).

## Heuristic / Inference Reanalysis And Validation

### 0002ET Keyboard Input And Scroll Helpers

Validated facts:

- The handler body is `0x0047f6f0-0x0047f868`; compiler switch/table bytes are `0x0047f868-0x0047f888`; `0x0047f888-0x0047f890` is alignment.
- Dispatch is vtable-only through `0x00614d5c`.
- The binary narrows `event[8]` through `std::ctype<char>::do_narrow`, using `event[266]` / `event+0x10a` as the default/fallback, before checking the guards.
- Required guards are `event[4] == 8` and `event[266] == 4`.
- Active signed key values are `-127`, `-109`, `-125`, and `-108`, equivalent to unsigned bytes `0x81`, `0x93`, `0x83`, and `0x94`.
- `-127` / `0x81` scrolls one line up.
- `-109` / `0x93` scrolls one page up, where page size is inherited virtual slot `+0x50`.
- `-125` / `0x83` scrolls one line down.
- `-108` / `0x94` scrolls one page down, using the same page-size virtual.
- Unmatched key values return `false`.
- `0x0055e950` is the selected-child current/offset getter from `ScrollablePaneCore`.
- `0x0055e910` is the selected-child target/range getter from `ScrollablePaneCore`.
- `0x0055eae0` is more precisely `ApplyScrollPosition(axis, oldPosition, targetPosition)`: its signature is `(__int128 *this, char axis, unsigned short old, unsigned short target)`, it no-ops when `old == target`, updates child offset `+0xfe`, calls virtual slot `+0x5c` to convert the scroll delta, then refreshes/clips content/render regions.

Rejected alternatives:

- Do not map `0x81`, `0x83`, `0x93`, or `0x94` to raw Win32 virtual-key constants. Win32 `VK_PRIOR`, `VK_NEXT`, `VK_UP`, and `VK_DOWN` are `0x21`, `0x22`, `0x26`, and `0x28`, not these bytes. The values are this client/input-layer's narrowed extended key symbols.
- Do not emit pointer arithmetic for `this - 0xa0`. The recovered snippets and `0002EU` show this is secondary-subobject compiler shape. Source should call inherited `ScrollablePane` methods normally from `ChattingPane`.

Best source-facing names:

- Event callback: `ChattingPane::OnKeyEvent` or `ChattingPane::HandleKeyboardScroll`. Prefer `OnKeyEvent` if matching the local pane callback naming used in generated `Chatting.cpp`.
- Event type guard: `kPaneEventKey` or `kInputEventKeyboard` for byte `8`.
- Key state guard: `kKeyStatePressed` for byte `4`.
- Key constants:
  - `kChatScrollLineUpKey = static_cast<signed char>(0x81)`
  - `kChatScrollLineDownKey = static_cast<signed char>(0x83)`
  - `kChatScrollPageUpKey = static_cast<signed char>(0x93)`
  - `kChatScrollPageDownKey = static_cast<signed char>(0x94)`
- Scroll helpers:
  - `GetScrollPosition(axis)` for `0x0055e950`
  - `GetScrollMax(axis)` or `GetScrollRange(axis)` for `0x0055e910`; keep `GetScrollMax` for consistency with accepted `0002EW`
  - `ApplyScrollPosition(axis, oldPosition, targetPosition)` for `0x0055eae0`; if keeping existing generated naming, document that `SetScrollRange` is a role alias, not an exact signature name.

### 0002EV Paint, Clip, Draw-State, And Message Layout

Validated facts:

- Body is exactly `0x0047f8d0-0x0047fbc5`; the previous and next gaps are `0xcc` padding.
- Dispatch is vtable-only through `0x00614d4c`.
- Current layout (`g_useEpfAssets == 1`) creates two local region objects, saves byte `this+0xb5`, tests `byte [dword_67ade0 + 280]`, sets GrafPort color/state to `0`, calls the surface/render callback at `0x0069b3fc` with `this+0x44`, obtains clip rect through `0x004b96c0`, and iterates messages only when the global byte is nonzero.
- When the current-layout global byte is zero, the method still sets color/state `0`, calls `0x0069b3fc(this, this+0x44)`, destroys the local regions, and returns without the message loop.
- Old layout (`g_useEpfAssets != 1`) creates two local region objects, sets GrafPort color/state `143`, calls `0x0069b3fc(this, this+0x110)`, obtains clip rect through `0x004b96c0`, and always enters the message-loop path when the list count is positive.
- The message list is at `this+0x130`; count is list `+0x0c`; fetch uses list vtable slot `+0x10`.
- Message entries are `ColorStringChattingMessage`-compatible objects. Measure uses entry vslot `+0x10`; draw uses entry vslot `+0x14`.
- Current layout measures and draws with width `783`; old layout uses width `408`.
- The loop initializes a three-int row/draw span as `{0, runningTop, width}`. `runningTop` starts from `this+0x124` and advances by `13 * measuredRows`.
- Before current-layout visibility testing on each row, `0x005446b0(this, savedByte)` restores the saved receiver byte from `this+0xb5`.
- `0x004b7cc0` gates row drawing against the current clip/query context.
- Clip behavior is:
  - save/copy current clip state through `0x004b9590`
  - if the copied region is empty via `0x005546f0`, apply row clip through `0x004b95b0`, draw, and restore via `0x004b9580`
  - else if `0x005547e0` can normalize/build a region from the row span, apply that region through `0x004b9580`, draw, and restore the saved region through `0x004b9580`

Resolved helper families:

- `0x00554680` constructs a `Region`/Motion rectangle helper object; `0x004f4a90` is the destructor/base cleanup for that object family.
- `0x005546f0` is `Region::IsEmpty` / Motion emptiness test.
- `0x005547e0` obtains a normalized rectangle/region for later clip application.
- `0x004b9580`, `0x004b9590`, and `0x004b95b0` are GrafPort clip-region copy/apply helpers over receiver state at `this+0x54`.
- `0x004b9660` is GrafPort draw/color-state setter at `this+0x74`.
- `0x004b96c0` is the shared `GrafPort::GetClipRect` candidate.
- `0x004b7cc0` is the shared intersection helper.
- `0x0069b3fc` is slot 7 in the `SurfaceRenderCallbackTable`, a broad pane refresh/presentation callback. It should not be named as a Chatting-specific callback. Existing generated alias `g_pfnLockSurface` is suspect for this use.

Field/name recommendations:

- `this+0x44`: inherited/current pane rectangle, already safely referenced as `m_rect` in generated drafts.
- `this+0x110`: inherited old-layout content/viewport rectangle from `ScrollablePane`.
- `this+0x124`: cached row paint origin/top used by the message loop. The broader `ScrollablePane` recompute helper treats this area as cached draw/content coordinates; do not give it a final original field name yet. Role name `m_chatMessagePaintTop` or `m_messagePaintOriginY` is acceptable in first-draft code.
- `this+0xb5`: saved current-layout draw/input state byte restored before each row's visibility/draw path. Role name `m_savedDrawStateByte` is acceptable; original field name is not proven.
- `this+0x130`: message list. Use the existing source-facing `m_pChatMessageList` / `m_chatMessageList` naming consistently with `0002EP`, `0002EQ`, and `0002EX`.

### 0002EZ Packet Type 13

Validated facts:

- Body is `0x0047fd70-0x0047ff60`; switch/table bytes are `0x0047ff60-0x0047ff74`; alignment continues to `0x0047ff80`.
- The router tail-jumps from `0x0047f8b5` when packet byte `0` equals `13`.
- The handler always returns `0`, both after side-effect insertion and after rejected/ignored packets. Return value is not an accept/reject indicator.
- Subtype is packet byte `1`.
- Text length is packet byte `6`.
- Text bytes begin at packet byte `7` and are converted with `MultiByteToWideChar(0, 0, packet + 7, length, WideCharStr, 256)`, then terminated.
- Current layout calls `PacketBufferReadUInt32BE` (`0x005754c0`) twice for subtype `4`; the two dwords are located after the text payload at `packet + 7 + textLength` and `packet + 7 + textLength + 4`.
- `0x005754c0` is resolved by `PacketBufferScalarBigEndianReadHelpers` as `PacketBufferReadUInt32BE`, a general big-endian 32-bit scalar decoder, not an RGB-specific helper. In this handler the decoded values are custom foreground/background color values because they are forwarded with color ids `253/254`, matching the type-10 subtype-18 convention.
- Current accepted subtype set is `0`, `1`, `3`, and `4`.
- Old accepted subtype set is `0`, `1`, and `3`.
- Current subtype `0` appends only when local state byte is `0`; otherwise no insertion.
- Current subtype `1` appends when local state byte is not `2`, using first color `14`; it is suppressed when the state byte equals `2`.
- Current subtype `3` appends without a local-state gate using colors `143/128`.
- Current subtype `4` appends without a local-state gate using ids `253/254` and the two decoded dwords.
- Old subtype `0` appends only when local state byte is `0`.
- Old subtype `1` appends when local state byte is not `2`, using first color `12`; it is suppressed when the state byte equals `2`.
- Old subtype `3` appends without a local-state gate using colors `128/143`.

Local state byte inference:

- The handler obtains `v8/v13 = *(_DWORD *)(dword_67A764 + 1048)`, where `dword_67A764` is [UID:0000PR] `g_activeMapPane`.
- MapPane support docs identify `MapPane +0x418` as the active/local object pointer consumed by local-object coordinate/update paths.
- The checked byte is active local object offset `0x134101` / decimal `1261825`.
- Nearby chat send paths check `dword_67A748 + 1261826` / `0x134102` as a player/session chat gate; `ShoutInputPane` documents value `2` as blocking shout sending.
- Best defensible inference: packet type 13 gates on an active-local-object chat/session/display state byte adjacent to the known local-player chat-send gate. Use a helper/role name such as `GetActiveLocalChatState()` or `activeLocalObject->m_chatDisplayState` in first-draft code, but do not claim the original field spelling.

Subtype name recommendations:

Original protocol enum spellings are not recoverable from the inspected docs. Type-10 names do not transfer cleanly: type 13 uses active-local-object state gates and fixed/default colors rather than `g_pConfig` chat-color categories. Use role names that encode observed behavior:

| Subtype | Recommended role constant | Evidence |
| ---: | --- | --- |
| `0` | `ChatType13_State0Only` | Accepted in both layouts only when active local chat state is `0`; uses default layout color pair. |
| `1` | `ChatType13_HighlightUnlessState2` | Accepted in both layouts when state is not `2`; suppressed at state `2`; uses highlighted first color `14` current, `12` old. |
| `3` | `ChatType13_UngatedDefault` | Accepted in both layouts with no state gate; uses default layout color pair. |
| `4` | `ChatType13_CustomColor` | Current-layout-only; reads two big-endian dwords after the text payload and forwards ids `253/254`. |

FolderTreePane owner pollution:

- Keep `0002EZ` under [UID:0000I5] `Chatting`, not `FolderTreePane`.
- Evidence is the router-only entry from `ChattingPane::OnChatPacketMessage`, the append target `ChattingPaneAddChattingMessage`, and the known owner-pollution page for the `0x0047f280-0x0058a8e0` chat-message subset.
- `FolderTreePane` is a generated-owner artifact here; it is not the filesystem tree-control route and should not receive emitter ownership.

## Per-Target Recommendations

### [UID:0002ET] ChattingPaneKeyboardScrollHandler

Recommended metadata:

```text
COMPLETION:86
CONFIDENCE:90
CANONICAL_OWNER:00001X
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00001X
```

Recommended doc changes:

- Replace the open question about Win32 virtual-key constants with the role-constant conclusion above.
- Add `ScrollablePaneCore` cross-reference and state that `0x0055eae0` is an apply-scroll-position helper with `(axis, old, target)` semantics.
- State that `this - 0xa0` is secondary-subobject compiler shape, not source pointer arithmetic.
- Populate first-draft C++ using role names.

Score rationale:

Completion rises because the key bytes, signed values, inherited helper semantics, page-step virtual, and secondary-subobject issue are now resolved to a source-ready role model. Confidence rises because the recovered decompile and `ScrollablePaneCore` doc agree on the helper signatures and call behavior. Exact original enum spellings remain below final-source quality but no longer block first-draft C++.

### [UID:0002EV] ChattingPaneOnPaint

Recommended metadata:

```text
COMPLETION:86
CONFIDENCE:90
CANONICAL_OWNER:00001X
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00001X
```

Recommended doc changes:

- Replace generic helper caveats with the resolved GrafPort/Region roles listed above.
- Document the exact recovered row-span shape `{0, runningTop, width}`, the starting field `this+0x124`, current width `783`, old width `408`, and current saved byte at `this+0xb5`.
- Identify `0x0069b3fc` as `SurfaceRenderCallbackTable` slot 7 / broad pane refresh-presentation callback, not a Chatting-specific function pointer.
- Populate first-draft C++ using role names and small helper abstractions for clip save/apply/restore.

Score rationale:

Completion rises because all previous helper/type/callback blockers now have defensible source roles and support docs. Confidence rises because the recovered decompile gives exact loop, row, and branch shape. Original names for the region object, clip helpers, and the `this+0x124` cached coordinate remain provisional, so this should not exceed `86/90`.

### [UID:0002EZ] ChatPacketType13Handler

Recommended metadata:

```text
COMPLETION:86
CONFIDENCE:90
CANONICAL_OWNER:0000I5
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000I5
```

Required behavior correction:

Replace the current-layout subtype `1` bullet. Current doc says subtype `1` is suppressed when the local state byte is not `2`; recovered decompile shows it is suppressed when the local state byte equals `2`, same as old layout.

Recommended doc changes:

- Resolve `0x005754c0` to `PacketBufferReadUInt32BE`.
- State subtype `4` custom dwords are read after the text payload, at `packet + 7 + textLength` and `packet + 7 + textLength + 4`.
- Add role subtype constants from the table above.
- Add local-state inference through `g_activeMapPane->activeLocalObject` / `MapPane +0x418`, byte `+0x134101`.
- Keep owner/emitter `0000I5` and note `FolderTreePane` as owner pollution only.
- Populate first-draft C++.

Score rationale:

Completion rises because packet decoder semantics, local-state route, subtype roles, current/old differences, and source route are now reanalyzed. Confidence rises because the recovered decompile directly corrects the subtype `1` condition and confirms custom-value offsets. Exact original protocol enum names and field spelling remain provisional.

## First-Draft C++ Recommendation

### 0002ET First Draft

```cpp
bool ChattingPane::OnKeyEvent(const PaneKeyEvent *event)
{
    const signed char key = NarrowPaneKey(event->payload[0], event->keyState);

    if (event->type != kPaneEventKey)
        return false;
    if (event->keyState != kKeyStatePressed)
        return false;

    constexpr unsigned char kVerticalAxis = 0;

    switch (key) {
    case kChatScrollLineUpKey: {
        const unsigned short current = GetScrollPosition(kVerticalAxis);
        const unsigned short target =
            current > 0 ? static_cast<unsigned short>(current - 1) : 0;
        ApplyScrollPosition(kVerticalAxis, current, target);
        return true;
    }

    case kChatScrollPageUpKey: {
        const unsigned short current = GetScrollPosition(kVerticalAxis);
        const int pageRows = GetScrollPageStep(kVerticalAxis);
        const unsigned short target =
            current > pageRows ? static_cast<unsigned short>(current - pageRows) : 0;
        ApplyScrollPosition(kVerticalAxis, current, target);
        return true;
    }

    case kChatScrollLineDownKey: {
        const unsigned short current = GetScrollPosition(kVerticalAxis);
        const unsigned short maximum = GetScrollMax(kVerticalAxis);
        const unsigned short target =
            current < maximum ? static_cast<unsigned short>(current + 1) : maximum;
        ApplyScrollPosition(kVerticalAxis, current, target);
        return true;
    }

    case kChatScrollPageDownKey: {
        const unsigned short current = GetScrollPosition(kVerticalAxis);
        const unsigned short maximum = GetScrollMax(kVerticalAxis);
        const int pageRows = GetScrollPageStep(kVerticalAxis);
        unsigned int target = current + pageRows;
        if (target > maximum)
            target = maximum;
        ApplyScrollPosition(kVerticalAxis, current, static_cast<unsigned short>(target));
        return true;
    }
    }

    return false;
}
```

Notes for insertion:

- `NarrowPaneKey` is the source-role wrapper for `std::ctype<char>::do_narrow(event[8], event[266])`.
- Constants should be role-defined as `signed char`: line up `0x81`, line down `0x83`, page up `0x93`, page down `0x94`.
- If the local codebase keeps B003's accepted `SetScrollRange` spelling, it should be documented as an alias for `ApplyScrollPosition(axis, oldPosition, targetPosition)`.

### 0002EV First Draft

```cpp
void ChattingPane::OnPaint()
{
    struct ClipRegionGuard {
        explicit ClipRegionGuard(ChattingPane *pane) : pane(pane) {}
        ~ClipRegionGuard() = default;

        ChattingPane *pane;
        Region savedClip;
        Region workClip;
    };

    auto paintMessages = [this](const ClipBounds &clipBounds,
                                int messageWidth,
                                bool restoreCurrentLayoutByte,
                                unsigned char savedByte) {
        int y = m_chatMessagePaintTop;
        const int count = m_pChatMessageList->GetCount();

        for (int index = 0; index < count; ++index) {
            ColorStringChattingMessage *message =
                static_cast<ColorStringChattingMessage *>(m_pChatMessageList->GetAt(index));

            ChatMessageDrawSpan rowSpan;
            rowSpan.left = 0;
            rowSpan.top = y;
            rowSpan.width = messageWidth;

            const short rows = message->MeasureLines(this, messageWidth);
            y += 13 * rows;

            if (restoreCurrentLayoutByte)
                RestoreCurrentChatDrawByte(savedByte);

            if (!IntersectsDrawSpan(rowSpan, clipBounds, nullptr))
                continue;

            Region savedClip;
            CopyClipRegion(&savedClip);

            if (savedClip.IsEmpty()) {
                ApplyDrawSpanClip(rowSpan);
                message->Draw(this, &rowSpan);
                RestoreClipRegion(savedClip);
            } else {
                Region clippedRow;
                if (clippedRow.SetFromDrawSpan(rowSpan)) {
                    RestoreClipRegion(clippedRow);
                    message->Draw(this, &rowSpan);
                    RestoreClipRegion(savedClip);
                }
            }
        }
    };

    if (g_useEpfAssets != 1) {
        ClipRegionGuard clip(this);
        SetGrafPortColorState(143);
        g_surfaceRenderCallbacks->RefreshPaneRegion(this, &m_scrollContentRect);

        ClipBounds clipBounds;
        GetClipRect(&clipBounds);
        paintMessages(clipBounds, 408, false, 0);
        return;
    }

    ClipRegionGuard clip(this);
    const unsigned char savedByte = m_currentLayoutDrawStateByte;

    if (g_chatUiState->m_shouldPaintChatMessages) {
        SetGrafPortColorState(0);
        g_surfaceRenderCallbacks->RefreshPaneRegion(this, &m_rect);

        ClipBounds clipBounds;
        GetClipRect(&clipBounds);
        paintMessages(clipBounds, 783, true, savedByte);
        return;
    }

    SetGrafPortColorState(0);
    g_surfaceRenderCallbacks->RefreshPaneRegion(this, &m_rect);
}
```

Notes for insertion:

- This is deliberately first-draft source, not final-source code. The binary uses local `Region` objects created by `0x00554680` and destroyed by `0x004f4a90`; the RAII wrapper expresses that source shape.
- `ChatMessageDrawSpan` should be a three-int role type matching `{left, top, width}` from the decompile, not forced into a four-int `RectBounds` without checking the draw helper declaration.
- `m_chatMessagePaintTop` is the role for `this+0x124`.
- `m_scrollContentRect` is the role for the old-layout `this+0x110` rectangle.
- `g_surfaceRenderCallbacks->RefreshPaneRegion` is a role wrapper for callback slot `0x0069b3fc`; final method name remains unresolved.

### 0002EZ First Draft

```cpp
static bool HandleChatPacketType13(ChattingPane *pane, const unsigned char *packet)
{
    InitializePacketDecodeScratch();

    const unsigned char subtype = packet[1];
    const unsigned char textLength = packet[6];

    wchar_t text[258];
    const int written = MultiByteToWideChar(
        0, 0,
        reinterpret_cast<const char *>(packet + 7),
        textLength,
        text,
        256);
    text[static_cast<unsigned char>(written)] = L'\0';

    const unsigned char localChatState = GetActiveLocalObjectChatState();

    if (g_useEpfAssets == 1) {
        switch (subtype) {
        case ChatType13_State0Only:
            if (localChatState != 0)
                return false;
            pane->AddChattingMessage(text, 143, 128, false, 0, 0);
            return false;

        case ChatType13_HighlightUnlessState2:
            if (localChatState == 2)
                return false;
            pane->AddChattingMessage(text, 14, 128, false, 0, 0);
            return false;

        case ChatType13_UngatedDefault:
            pane->AddChattingMessage(text, 143, 128, false, 0, 0);
            return false;

        case ChatType13_CustomColor: {
            const unsigned int payloadEnd = 7 + textLength;
            const unsigned int foreground =
                PacketBufferReadUInt32BE(packet + static_cast<unsigned short>(payloadEnd));
            const unsigned int background =
                PacketBufferReadUInt32BE(packet + static_cast<unsigned short>(payloadEnd + 4));
            pane->AddChattingMessage(text, 253, 254, false, foreground, background);
            return false;
        }
        }

        return false;
    }

    switch (subtype) {
    case ChatType13_State0Only:
        if (localChatState != 0)
            return false;
        pane->AddChattingMessage(text, 128, 143, false, 0, 0);
        return false;

    case ChatType13_HighlightUnlessState2:
        if (localChatState == 2)
            return false;
        pane->AddChattingMessage(text, 12, 143, false, 0, 0);
        return false;

    case ChatType13_UngatedDefault:
        pane->AddChattingMessage(text, 128, 143, false, 0, 0);
        return false;
    }

    return false;
}
```

Notes for insertion:

- The function returns `false` after appending because the binary returns zero after handled and rejected paths.
- `GetActiveLocalObjectChatState()` should read `*(g_activeMapPane->m_activeLocalObject + 0x134101)` through a typed role helper until the active object layout is named.
- `ChatType13_*` constants are role names, not original protocol spellings.

## Support-Doc Update Recommendations

Recommended support-doc changes are informational and do not require score changes unless the supervisor wants parent pages to record the new child C++ readiness.

### `by-class/ChattingPane.md`

Score/metadata: keep current score unless applying a broader class-declaration refresh. Add a short source-quality note near the child-method or field notes:

```text
- 2026-06-17 B001 source-quality reanalysis resolved the remaining keyboard/paint child blockers enough for first-draft C++: `0x0047f6f0` uses project-specific narrowed key bytes `0x81/0x83/0x93/0x94` for line/page scrolling through inherited `ScrollablePane` helpers, and the `this - 0xa0` adjustment is secondary-subobject compiler shape; `0x0047f8d0` paints the `this+0x130` `ColorStringChattingMessage` list through measure/draw vslots using current width `783` or old width `408`, cached row origin `this+0x124`, GrafPort clip helpers, and `SurfaceRenderCallbackTable` slot `0x0069b3fc`. Exact original names for key enum values, the cached paint-origin field, and clip helper wrappers remain provisional.
```

### `by-file/Chatting.md`

Score/metadata: keep current score. Add a packet-helper note under the chat packet handler section:

```text
- 2026-06-17 B001 source-quality reanalysis keeps `ChatPacketType13Handler` in `Chatting.cpp` despite generated `FolderTreePane` owner pollution. Packet byte `13` subtype roles are `State0Only` (`0`), `HighlightUnlessState2` (`1`), `UngatedDefault` (`3`), and current-layout `CustomColor` (`4`). The local gate reads the active local object from `g_activeMapPane + 0x418` and byte `+0x134101`; subtype `1` is suppressed when that byte equals `2` in both layouts. `0x005754c0` is `PacketBufferReadUInt32BE`, used here for custom foreground/background values after the text payload.
```

### `0002ES` / `ScrollablePaneCore`

No score change required. If updating wording, prefer:

```text
For ChattingPane keyboard scroll source drafts, treat `0x0055e950` as `GetScrollPosition(axis)`, `0x0055e910` as `GetScrollMax(axis)`, and `0x0055eae0` as `ApplyScrollPosition(axis, oldPosition, targetPosition)`. Existing `SetScrollRange` draft names are role aliases for the same apply-scroll helper.
```

### `0002EU`

No score change required. If updating C++/notes, state that `HandleChatPacketType13` returns `false` after side-effect append because the binary helper always returns zero.

### Packet and global support pages

No metadata changes required.

- `PacketBufferScalarBigEndianReadHelpers`: optionally cross-link `0002EZ` as another `PacketBufferReadUInt32BE` custom-color consumer.
- `g_activeMapPane` / `MapPane` support pages: optionally cross-link `0002EZ` as a consumer of `MapPane +0x418` active/local object pointer.
- `g_pCollectionData`: no direct route for `0002EZ`, but the adjacent `+0x134102` chat-send gate can remain supporting context for the `+0x134101` local-state inference.

## Supervisor-Owned Coverage Row Text

Replace the existing rows in `by-memory/-coverage-report.md` only if the supervisor accepts the score changes. Agents are banned from editing that file.

Replacement for `0002ET`:

```text
        - [UID:0002ET][0x0047f6f0-0x0047f890.ChattingPaneKeyboardScrollHandler](by-memory/0x0047f6f0-0x0047f890.ChattingPaneKeyboardScrollHandler.md) 0x0047f6f0-0x0047f890 | method + switch data | ChattingPaneKeyboardScrollHandler : reconstructable : 86% : strong : B001 2026-06-17 reanalysis resolves source-facing keyboard scroll constants as project-specific narrowed key bytes `0x81/0x83/0x93/0x94` rather than Win32 VK values, confirms event type `8` and key-state `4` guards, inherited `ScrollablePane` helper roles (`GetScrollPosition`, `GetScrollMax`, `ApplyScrollPosition(axis, old, target)`), vslot `+0x50` page-step use, secondary-subobject `this-0xa0` compiler adjustment, exact body/table/alignment boundaries, vtable-only reachability, and first-draft C++ readiness with role-based names.
```

Replacement for `0002EV`:

```text
        - [UID:0002EV][0x0047f8d0-0x0047fbc5.ChattingPaneOnPaint](by-memory/0x0047f8d0-0x0047fbc5.ChattingPaneOnPaint.md) 0x0047f8d0-0x0047fbc5 | method | ChattingPaneOnPaint : reconstructable : 86% : strong : B001 2026-06-17 reanalysis resolves GrafPort/Region clip helper roles, `SurfaceRenderCallbackTable` slot `0x0069b3fc`, current/old layout setup (`this+0x44` width `783`, `this+0x110` width `408`), message-list count/fetch at `this+0x130`, row span `{0, this+0x124, width}` with `13 * measuredRows` advance, current-layout byte restore from `this+0xb5`, measure/draw virtual slots, exact body/padding/vtable-only evidence, and first-draft C++ readiness with provisional helper/field names.
```

Replacement for `0002EZ`:

```text
        - [UID:0002EZ][0x0047fd70-0x0047ff80.ChatPacketType13Handler](by-memory/0x0047fd70-0x0047ff80.ChatPacketType13Handler.md) 0x0047fd70-0x0047ff80 | packet handler + switch data | ChatPacketType13Handler : reconstructable : 86% : strong : B001 2026-06-17 reanalysis confirms packet byte-13 router route, exact body/table/alignment, UTF-16 conversion from `packet+7` length byte `packet[6]`, role subtype map `State0Only`/`HighlightUnlessState2`/`UngatedDefault`/current `CustomColor`, corrected subtype `1` suppression when active-local chat state equals `2` in both layouts, active local object state read through `g_activeMapPane+0x418` byte `+0x134101`, `PacketBufferReadUInt32BE` custom-color dwords after the text payload, FolderTreePane owner-pollution rejection, Chatting.cpp emitter route, and first-draft C++ readiness with role-based protocol names.
```

## Remaining Limitations

- No fresh IDA MCP was available in this run, so this report did not create new live decompilation evidence. It reuses existing live-IDA-backed docs and generated hook/recovered snippets.
- Exact original source spellings remain unproven for the `0002ET` key enum, `0002EV` clip helper wrappers and cached paint-origin field, and `0002EZ` packet subtype enum/local chat-state field.
- These are not current C++ gate blockers because all three drafts can use role-based names consistent with existing accepted Chatting first drafts.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0002ET-0002EV-0002EZ-chatting-pane-remaining-handlers-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:21","uid":"0002ET"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
