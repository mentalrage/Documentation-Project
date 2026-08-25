** TARGET-REPORT-UID:0002FT **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002FT ChattingHandlePane::OnMouseEvent Source-Quality Report

Status: `FINISHED_REPORT`

Report-only scope observed: this report is the only intended write. No by-* pages, leases, generated/project/manual coverage files, tools, or IDA database/process state were edited.

## Target

- Target: [UID:0002FT] `by-memory/0x00481d60-0x0048214f.ChattingHandlePaneOnMouseEvent.md`
- Required report path: `tools/leaser/Agents/Agent-B003/research/0002FT-ChattingHandlePaneOnMouseEvent-source-quality.md`
- Current target metadata: `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:00001V`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00001V`
- Current formal C++: blank.
- Recommendation: keep owner/emitter/reconstructable, raise to `COMPLETION:89`, `CONFIDENCE:91`, and insert first-draft formal C++ below.

The score should stay below final-audit range because exact original member spellings are still inferred and the class declaration is not fully reconstructed. The old blank-C++ blocker is no longer valid: current MCP, support docs, and accepted adjacent first-draft code resolve enough source-facing names and behavior for an implementation-ready first draft.

## MCP State

Current IDA MCP was available and used.

- Active session from `idb_list`: `b010_0001DR_20260628`
- IDB: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Input module: `NexusTK.exe`
- Worker PID: `17656`
- `server_health`: `ok`, auto-analysis ready, Hex-Rays ready, strings cache ready.

MCP evidence used:

- `lookup_funcs` reports `sub_481D60` at `0x00481d60`, size `0x3ef`; `0x0048214f` is not a function; successor `sub_482150` starts at `0x00482150`.
- `analyze_function 0x00481d60` reports prototype `char __userpurge@<al>(int@<ecx>, int@<ebx>, int)`, xref-to data `0x00615010`, no ordinary code callers, and callees `sub_482400`, `sub_4B7E80`, `sub_5A5110`, `sub_55C3A0`, `sub_4B7C50`, `sub_55C3C0`, and security cookie check.
- `decompile 0x00481d60` confirms the complete hover/down/up dispatcher, settings persistence, dependent-pane invalidations, and render-snapshot comparison.
- `analyze_function 0x00482400` confirms `GetChatButtonAtPoint(int mouseX, int mouseY)`, sole callers at `0x00481dca` and `0x00481ec9`, and exact button rectangles.
- `analyze_function 0x00481c10` confirms constructor initialization from config offsets `2678396`, `2678400`, and `2678401`, singleton store, and initial secondary scroll-widget enable/disable.
- `analyze_function 0x00482150` confirms `OnPaint` frame formulas and snapshot writes for the same live state fields.
- `int_convert.py` verified `2678396 == 0x28de7c`, `2678400 == 0x28de80`, `2678401 == 0x28de81`, `1305373 == 0x13eb1d`, and `528 == 0x210`.

## Evidence Checked

Direct and support docs reviewed:

- Target [UID:0002FT] `ChattingHandlePaneOnMouseEvent`
- [UID:00001V] `by-class/ChattingHandlePane.md`
- [UID:0000I5] `by-file/Chatting.md`
- [UID:0002FR] constructor, [UID:0002FU] paint, [UID:0002FW] raw rectangle helper, [UID:000107] `GetChatButtonAtPoint`
- [UID:0002FP]/[UID:0002FQ] retained raw render-state compare/snapshot helpers
- [UID:0000SX] `by-global/GetChatButtonAtPoint.md`
- [UID:00028Q] `g_pConfig`
- [UID:0002XE] `g_pChattingHandlePane`
- [UID:0002B5] UI chat/clan singleton slots
- [UID:0002RX] `OpenInputPaneForCurrentSayMode`
- [UID:0001LE] `SelectObjectWithKeyboardPaneOnMouseEvent`
- [UID:0001LL] `TargetObjectWithKeyboardPaneMouseEvent`
- [UID:000430] `ScrollWidget::Enable`
- [UID:000431] `ScrollWidget::Disable`
- [UID:0067a748-0x0067a74c] `g_pCollectionData` / `g_pUserPane` field support

Prior B-agent research checked:

- B002 raw-helper report: render-state compare/snapshot raw helpers and `GetChatButtonRectRaw` remain no-route support, not callable target code.
- B009 say-input report: `g_pChattingHandlePane + 0x111` is accepted as `ChattingHandlePane::m_chatTargetPending` in `OpenInputPaneForCurrentSayMode`.
- B001 modify-height report: config `+0x28de78..+0x28de81` names are `m_chatVisibleLineCount`, `m_chatHandleModeIndex`, `m_secondaryChatEnabled`, and `m_chatHandleLeftToggle`.
- B003 registry config report: persisted packed `ChatWindow` registry value names match the same config fields.

Generated tracker note: `auto-generated/-ag-research-tracker.md` and `auto-generated/-ag-coverage-report-by-memory.md` still showed stale `80/88` style rows for this target when checked. Implementation should run the normal scoped validation/regeneration after applying by-* edits.

## Binary Behavior

The method is a secondary/event-view virtual for `ChattingHandlePane`, reached through vtable data entry `0x00615010`, with no direct code callers.

Top guard:

- If `g_pUserPane + 0x13eb1d` is set, the method returns false immediately.
- Current support docs name this broad field `m_inputLocked` / `m_localInputLocked`; use `m_inputLocked` as the first-draft source-facing accessor/field name.

Mouse move / hover (`event->type == 0`):

- If `PointInRect(event->mouseY, event->mouseX, &m_bounds)` is false, clear the three paint states to normal and leave the handled flag false.
- Otherwise build the three visible button rectangles inline with `InitRectBounds`:
  - left `(0,4,19,21)`
  - mode/middle-right `(630,4,649,21)`
  - secondary/right `(649,4,668,21)`
- The move path does not call `GetChatButtonAtPoint` and does not use `GetChatButtonRectRaw`.
- Without capture, paint states become hover (`1`) for the hovered visible button and normal (`0`) for the others.
- With capture, paint states become pressed (`2`) only for the currently hovered button whose corresponding down-latch is set; otherwise normal (`0`).
- A move inside bounds returns true even if the visible state is unchanged.

Mouse down (`event->type == 1`):

- Sets `m_mouseCaptured = true`.
- Calls `GetChatButtonAtPoint(event->mouseX, event->mouseY)`.
- Hit `0`: sets the left-button latch and left paint state pressed.
- Hit `1`: if `g_pUserPane + 0x210` is null, calls `OpenInputPaneForCurrentSayMode(g_pUserPane)` and returns true; otherwise returns false for that branch. Support docs treat `+0x210` as pending target-object state.
- Hit `2`: sets the mode-button latch and mode paint state pressed.
- Hit `3`: sets the secondary-button latch and secondary paint state pressed.

Mouse up (`event->type == 3`):

- Clears `m_mouseCaptured`.
- Calls `GetChatButtonAtPoint(event->mouseX, event->mouseY)`.
- Hit `0`: if the left latch is set, toggles `m_chatTargetPending`; returns true for the hit even if the latch was not set.
- Hit `2`: if the mode latch is set, cycles `m_chatHandleModeIndex = (m_chatHandleModeIndex + 1) % 3`, then invalidates `g_pChattingBackPane` and `g_pChattingDisplayPane`; returns true for the hit even if the latch was not set.
- Hit `3`: if the secondary latch is set, toggles `m_secondaryChatEnabled`, calls `ScrollWidget::Enable()` or `ScrollWidget::Disable()` on `g_pChattingDisplayPane + 0xfc`, then invalidates `g_pChattingBackPane`, `g_pChattingDisplayPane`, and `g_pChattingModifyHeightPane`; returns true for the hit even if the latch was not set.
- Hit `1`, no-hit, and default release cases still clear latches and write the current settings to config, but they do not set the handled flag.
- After release handling, clears the three latches and writes:
  - `g_pConfig + 0x28de7c` / `m_chatHandleModeIndex`
  - `g_pConfig + 0x28de80` / `m_secondaryChatEnabled`
  - `g_pConfig + 0x28de81` / `m_chatHandleLeftToggle`

Final repaint invalidation:

- Independently of the handled flag, the method compares live state against the paint snapshot at full-object offsets `+0x0f8..+0x10c`.
- If the snapshot is invalid or any live field differs, it calls inherited virtual slot `+0x20` / `InvalidateRect(&m_bounds)`.
- This matches the retained raw compare/snapshot helpers, but the target does the compare inline. Do not call the raw no-route helpers from the first-draft source body.

## Source-Name Decisions

Recommended class/source names:

| Binary field | Recommended source-facing name | Rationale |
| --- | --- | --- |
| `this+0x110` | `m_mouseCaptured` | Set on down, clear on release, changes hover paint semantics. |
| `this+0x111` | `m_chatTargetPending` | Accepted by B009 and current target-selection/open-input docs as the command/pending chat-target gate. It is also the persisted left handle toggle. |
| config `+0x28de81` | `m_chatHandleLeftToggle` | Keep the registry/config field name from B001/B003; document that it persists `ChattingHandlePane::m_chatTargetPending`. |
| `this+0x114` | `m_chatHandleModeIndex` | Matches config/support docs, cycles modulo three, drives middle-right button paint. |
| config `+0x28de7c` | `m_chatHandleModeIndex` | Same source role as the class field. |
| `this+0x118` | `m_secondaryChatEnabled` | Accepted by modify-height/paint/config support; controls display scroll widget and resize handle behavior. |
| config `+0x28de80` | `m_secondaryChatEnabled` | Same source role as the class field. |
| `this+0x119` | `m_leftButtonPressed` | Down latch consumed on release for hit `0`. |
| `this+0x11a` | `m_modeButtonPressed` | Down latch consumed on release for hit `2`. |
| `this+0x11b` | `m_secondaryButtonPressed` | Down latch consumed on release for hit `3`. |
| `this+0x11c` | `m_leftButtonPaintState` | `OnPaint` uses it as `CHATBUTT.EPF` frame-state multiplier. |
| `this+0x120` | `m_modeButtonPaintState` | `OnPaint` middle-right/mode frame-state multiplier. |
| `this+0x124` | `m_secondaryButtonPaintState` | `OnPaint` right/secondary frame-state multiplier. |
| `this+0x0f8..0x10c` | `m_renderStateSnapshot` | Snapshot written by `OnPaint`, compared by `OnMouseEvent`; use member struct fields in first-draft code. |

Rejected names:

- Do not use generated `m_btn1Hover`, `m_btn2State`, or `m_chatBubbleEnabled` as final source-facing names. They understate persistence and secondary-scroll behavior.
- Do not rename the config byte `m_chatHandleLeftToggle` globally to `m_chatTargetPending`; the registry/config source model uses packed ChatWindow settings and should keep the config-side name while documenting the class-side role.
- Do not model `GetChatButtonRectRaw` as a live helper call in this target; B002 and current docs show no inbound route.
- Do not model this target as a drag handler. The actual drag/height behavior belongs to `ChattingModifyHeightPane`; this method only holds capture/latches for button visual state and opens input from the handle body region.

## Ownership And Placement

Keep:

- `CANONICAL_OWNER:00001V` (`ChattingHandlePane`)
- `EMITTER_UIDS:00001V`
- Source route through [UID:0000I5] `NexusTK/social/Chatting.cpp`
- `RECONSTRUCTABLE:TRUE`

Positive evidence:

- Vtable-only data xref at `0x00615010` is the `ChattingHandlePane` mouse-event slot.
- Constructor and paint methods around the target share the exact field band and source file.
- Singleton slots `g_pChattingDisplayPane`, `g_pChattingBackPane`, `g_pChattingModifyHeightPane`, and `g_pChattingHandlePane` are all part of the documented Chatting UI block.
- Helper `GetChatButtonAtPoint` is a file-local Chatting helper with only target callers.

Negative evidence:

- No ordinary direct code callers exist; this is expected for a virtual method, not evidence of no-route raw code.
- The raw rectangle helper at `0x00482310` remains no-route support and should not receive a call from this first-draft body.
- ScrollWidget enable/disable ownership stays with `ScrollWidget`; this target is a consumer only.
- UserPane target-selection/input fields remain dependencies; they do not move this method out of `ChattingHandlePane`.

## Formal C++ Recommendation

Insert the following exact text into [UID:0002FT]'s `RECONSTRUCTION_CPP CODE` block. This is first-draft formal reconstruction text for supervisor-approved insertion, not a prose example.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
enum ChatHandleButtonHit
{
    kChatHandleButtonNone = -1,
    kChatHandleButtonLeft = 0,
    kChatHandleBody = 1,
    kChatHandleButtonMode = 2,
    kChatHandleButtonSecondary = 3,
};

enum ChatHandleButtonPaintState
{
    kChatHandleButtonNormal = 0,
    kChatHandleButtonHover = 1,
    kChatHandleButtonPressed = 2,
};

bool ChattingHandlePane::OnMouseEvent(const PaneMouseEvent *event)
{
    bool handled = false;

    if (g_pUserPane->m_inputLocked)
        return false;

    switch (event->type) {
    case kPaneMouseMove:
    {
        if (!PointInRect(event->mouseY, event->mouseX, &m_bounds)) {
            m_leftButtonPaintState = kChatHandleButtonNormal;
            m_modeButtonPaintState = kChatHandleButtonNormal;
            m_secondaryButtonPaintState = kChatHandleButtonNormal;
            break;
        }

        RectBounds leftButtonRect;
        RectBounds modeButtonRect;
        RectBounds secondaryButtonRect;

        InitRectBounds(&leftButtonRect, 0, 4, 19, 21);
        InitRectBounds(&modeButtonRect, 630, 4, 649, 21);
        InitRectBounds(&secondaryButtonRect, 649, 4, 668, 21);

        const bool overLeft =
            PointInRect(event->mouseY, event->mouseX, &leftButtonRect);
        const bool overMode =
            PointInRect(event->mouseY, event->mouseX, &modeButtonRect);
        const bool overSecondary =
            PointInRect(event->mouseY, event->mouseX, &secondaryButtonRect);

        if (m_mouseCaptured) {
            m_leftButtonPaintState =
                (overLeft && m_leftButtonPressed)
                    ? kChatHandleButtonPressed
                    : kChatHandleButtonNormal;
            m_modeButtonPaintState =
                (overMode && m_modeButtonPressed)
                    ? kChatHandleButtonPressed
                    : kChatHandleButtonNormal;
            m_secondaryButtonPaintState =
                (overSecondary && m_secondaryButtonPressed)
                    ? kChatHandleButtonPressed
                    : kChatHandleButtonNormal;
        } else {
            m_leftButtonPaintState =
                overLeft ? kChatHandleButtonHover : kChatHandleButtonNormal;
            m_modeButtonPaintState =
                overMode ? kChatHandleButtonHover : kChatHandleButtonNormal;
            m_secondaryButtonPaintState =
                overSecondary ? kChatHandleButtonHover : kChatHandleButtonNormal;
        }

        handled = true;
        break;
    }

    case kPaneMouseLeftButtonDown:
        m_mouseCaptured = true;

        switch (GetChatButtonAtPoint(event->mouseX, event->mouseY)) {
        case kChatHandleButtonLeft:
            m_leftButtonPressed = true;
            m_leftButtonPaintState = kChatHandleButtonPressed;
            handled = true;
            break;

        case kChatHandleBody:
            if (g_pUserPane->m_pendingTargetObject == NULL) {
                OpenInputPaneForCurrentSayMode(g_pUserPane);
                handled = true;
            }
            break;

        case kChatHandleButtonMode:
            m_modeButtonPressed = true;
            m_modeButtonPaintState = kChatHandleButtonPressed;
            handled = true;
            break;

        case kChatHandleButtonSecondary:
            m_secondaryButtonPressed = true;
            m_secondaryButtonPaintState = kChatHandleButtonPressed;
            handled = true;
            break;

        default:
            break;
        }
        break;

    case kPaneMouseLeftButtonUp:
        m_mouseCaptured = false;

        switch (GetChatButtonAtPoint(event->mouseX, event->mouseY)) {
        case kChatHandleButtonLeft:
            if (m_leftButtonPressed)
                m_chatTargetPending = !m_chatTargetPending;
            handled = true;
            break;

        case kChatHandleButtonMode:
            if (m_modeButtonPressed) {
                m_chatHandleModeIndex = (m_chatHandleModeIndex + 1) % 3;
                g_pChattingBackPane->InvalidateRect(&g_pChattingBackPane->m_bounds);
                g_pChattingDisplayPane->InvalidateRect(&g_pChattingDisplayPane->m_bounds);
            }
            handled = true;
            break;

        case kChatHandleButtonSecondary:
            if (m_secondaryButtonPressed) {
                m_secondaryChatEnabled = !m_secondaryChatEnabled;

                if (m_secondaryChatEnabled)
                    g_pChattingDisplayPane->m_scrollWidget->Enable();
                else
                    g_pChattingDisplayPane->m_scrollWidget->Disable();

                g_pChattingBackPane->InvalidateRect(&g_pChattingBackPane->m_bounds);
                g_pChattingDisplayPane->InvalidateRect(&g_pChattingDisplayPane->m_bounds);
                g_pChattingModifyHeightPane->InvalidateRect(&g_pChattingModifyHeightPane->m_bounds);
            }
            handled = true;
            break;

        default:
            break;
        }

        m_leftButtonPressed = false;
        m_modeButtonPressed = false;
        m_secondaryButtonPressed = false;

        g_pConfig->m_chatHandleModeIndex = m_chatHandleModeIndex;
        g_pConfig->m_secondaryChatEnabled = m_secondaryChatEnabled;
        g_pConfig->m_chatHandleLeftToggle = m_chatTargetPending;
        break;

    default:
        break;
    }

    if (!m_renderStateSnapshot.valid ||
        m_renderStateSnapshot.chatTargetPending != m_chatTargetPending ||
        m_renderStateSnapshot.chatHandleModeIndex != m_chatHandleModeIndex ||
        m_renderStateSnapshot.secondaryChatEnabled != m_secondaryChatEnabled ||
        m_renderStateSnapshot.leftButtonPaintState != m_leftButtonPaintState ||
        m_renderStateSnapshot.modeButtonPaintState != m_modeButtonPaintState ||
        m_renderStateSnapshot.secondaryButtonPaintState != m_secondaryButtonPaintState) {
        InvalidateRect(&m_bounds);
    }

    return handled;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Implementation note: the exact declaration spellings for `m_pendingTargetObject`, `m_scrollWidget`, and `m_renderStateSnapshot` are inferred source-facing names. They are strong enough for first-draft C++ but should remain confidence caps in the target/support prose.

## Support-Doc Changes Recommended

Target [UID:0002FT]:

- Replace stale "final names unresolved" blocker with the decisions above.
- Update score to `89/91`.
- Insert the formal C++ block.
- Update behavior to mention `m_inputLocked`, `m_chatTargetPending`, `m_chatHandleModeIndex`, `m_secondaryChatEnabled`, latches, three paint states, and `m_renderStateSnapshot`.
- Mention that hover uses inline rectangles and down/up use `GetChatButtonAtPoint`.
- Mention that release writes all three config fields even for no-op/default release paths.

[UID:00001V] `ChattingHandlePane`:

- Add or update a field map for full-object offsets `+0x110..+0x124` and snapshot `+0x0f8..+0x10c`.
- State that `+0x111` is class-side `m_chatTargetPending`, persisted through config-side `m_chatHandleLeftToggle`.
- Mark `OnMouseEvent` as first-draft C++ ready at `89/91`.

[UID:0000I5] `Chatting`:

- Update the `ChattingHandlePane` row to say OnMouseEvent is source-ready and uses `GetChatButtonAtPoint`, `ScrollWidget::Enable/Disable`, and inherited invalidation.
- Keep route under `NexusTK/social/Chatting.cpp`.

[UID:0002FR] constructor:

- Keep config reads but clarify `m_chatHandleLeftToggle` initializes `ChattingHandlePane::m_chatTargetPending`.
- Replace raw `sub_55C3A0/sub_55C3C0` consumer wording with `ScrollWidget::Enable/Disable` while preserving addresses in evidence.

[UID:0002FU] paint:

- Align field names with this report: `m_chatTargetPending`, `m_chatHandleModeIndex`, `m_secondaryChatEnabled`, and the three paint states.
- Keep exact `CHATBUTT.EPF` formulas.

[UID:0002FP]/[UID:0002FQ]:

- Keep no-route raw-helper classification.
- If names are refreshed, align snapshot field names with `m_renderStateSnapshot` and config/class dual-role wording.

[UID:000107] and [UID:0000SX] `GetChatButtonAtPoint`:

- No ownership or score change needed.
- Preserve coordinate signature `GetChatButtonAtPoint(int mouseX, int mouseY)`.
- Ensure the target docs state only down/up use this helper; hover does not.

[UID:00028Q] `g_pConfig` and registry config docs:

- Keep `m_chatHandleLeftToggle` for config `+0x28de81`.
- Add a note that the class consumer name is `ChattingHandlePane::m_chatTargetPending` and that this persisted setting is the left handle toggle/command-pending state.

[UID:0002XE] `g_pChattingHandlePane`:

- Keep `m_chatTargetPending` / `IsCommandPending()` language.
- Add the persistence relationship to config `m_chatHandleLeftToggle` so it no longer conflicts with the ChattingHandlePane/config docs.

Generated/coverage:

- After manual by-* incorporation, run scoped validators on all changed target/support pages.
- Regenerate or refresh the stale generated tracker/coverage rows that still show old `80/88` data.

## Implementation Checklist

- [x] Update [UID:0002FT] metadata to `89/91`. Proof: `by-memory/0x00481d60-0x0048214f.ChattingHandlePaneOnMouseEvent.md` now has `COMPLETION:89` and `CONFIDENCE:91`; scoped validator command `000000004947` at `2026-06-28T03:35:55-04:00` returned `ok: 1`.
- [x] Insert the formal C++ block exactly into [UID:0002FT]. Proof: the report's `RECONSTRUCTION_CPP CODE` block is now in the target formal block; validator command `000000004947` recorded the C++ registry transition `blank -> block` and returned `ok: 1`.
- [x] Update [UID:0002FT] behavior/source-quality prose with hover/down/up, config persistence, dependency refresh, and snapshot invalidation. Proof: target prose now documents `m_inputLocked`, inline hover rectangles, coordinate `GetChatButtonAtPoint` down/up calls, config writes, `ScrollWidget::Enable/Disable`, back/display/modify invalidations, and `m_renderStateSnapshot`; validator command `000000004947` returned `ok: 1`.
- [x] Update `ChattingHandlePane` class support field map and method row. Proof: `by-class/ChattingHandlePane.md` now has the accepted field map for `+0x0f8..+0x124` and marks `OnMouseEvent` first-draft C++ ready at `89/91`; validator command `000000004950` at `2026-06-28T03:36:30-04:00` returned `ok: 1`.
- [x] Update `Chatting` file support route summary. Proof: `by-file/Chatting.md` now keeps the route under `NexusTK/social/Chatting.cpp` and records the accepted OnMouseEvent source-ready behavior; validator command `000000004954` at `2026-06-28T03:36:37-04:00` returned `ok: 1`.
- [x] Update constructor and paint pages for the resolved field names. Proof: constructor validator `000000004956` at `2026-06-28T03:36:43-04:00` and paint validator `000000004957` at `2026-06-28T03:36:55-04:00` both returned `ok: 1`.
- [x] Update config and `g_pChattingHandlePane` support docs to document the `m_chatTargetPending` / `m_chatHandleLeftToggle` dual-role byte. Proof: updated `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`, `by-global/g_pChattingHandlePane.md`, and `by-memory/0x0067ade0-0x0067ade4.g_pChattingHandlePane.md`; validators `000000004965`, `000000004963`, and `000000004964` all returned `ok: 1`.
- [x] Confirm no call is added to `GetChatButtonRectRaw`. Proof: [UID:0002FT], [UID:000107], and [UID:0000SX] now state hover uses inline visible rectangles and down/up use `GetChatButtonAtPoint`; memory/global hit-test validators `000000004960` and `000000004961` returned `ok: 1`.
- [x] Run scoped validators for touched pages. Proof: scoped file validators from `source-3/project-documentation` returned `ok: 1` for command IDs `000000004947`, `000000004950`, `000000004954`, `000000004956`, `000000004957`, `000000004958`, `000000004959`, `000000004960`, `000000004961`, `000000004963`, `000000004964`, `000000004965`, `000000004966`, `000000004967`, and `000000004968`.
- [x] Refresh generated tracker/coverage rows after validation. Proof: each scoped validator reported `generated_refresh: deferred`; queue status command `000000004975` at `2026-06-28T03:40:47-04:00` showed `queued generated refresh jobs: 0` and `processing generated refresh jobs: 1`. No manual generated, project-level, tool, or coverage-report edit was made by B003; report execution/tracker archival remains supervisor-owned by callback instruction.

## Residual Risk

- Exact original field spellings remain inferred. This report resolves source-facing names for first-draft reconstruction, not final 95+ symbol provenance.
- `m_scrollWidget` is the best current display-pane member name for the object at `g_pChattingDisplayPane + 0xfc`, backed by `ScrollWidget::Enable/Disable`; exact member spelling should stay a confidence cap.
- `m_pendingTargetObject` is inferred for `g_pUserPane + 0x210` from accepted target-selection docs.
- `m_renderStateSnapshot` is inferred source struct spelling for the snapshot at `+0x0f8..+0x10c`; the layout and use are binary-proven.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0002FT-ChattingHandlePaneOnMouseEvent-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0002FT-ChattingHandlePaneOnMouseEvent-source-quality.md","timestamp":"2026-06-28T03:42:59","uid":"0002FT"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
