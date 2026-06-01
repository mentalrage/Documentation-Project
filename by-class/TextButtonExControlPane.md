*** UID:0000EK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# TextButtonExControlPane

## Status

- Confidence: strong for class role, medium for destructor/helper owner names.
- Likely source file: [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md), adjacent to [UID:0000OK][TextButtonControlPane](by-file/TextButtonControlPane.md)
- Current recovered file: `source-3/simroot_v2/class_TextButtonExControlPane.cpp`

## Class Purpose

`TextButtonExControlPane` is an extended text-labeled button. It owns or coordinates a text-provider pane, centers label bounds when state changes, shows/hides the label, attaches/detaches the sub-pane, and paints BUTTONEX-style graphics and optional text/icon overlays.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `TextButtonExControlPane` | `0x00495450-0x004955db` | Constructs the generic text-button base and attached text-provider child; current fitting-room user-image owner label is polluted. |
| `SetState` | `0x00495620-0x0049574b` | Recomputes centered label bounds and invalidates on state change. |
| `GetText` | `0x00495750-0x004957b1` | Copies text from the text provider into caller buffer. |
| `ShowControl` / `HideControl` | `0x004957c0-0x004958b5` | Toggles text-provider alpha/visibility and invalidates bounds. |
| `OnAttachToParent` / `OnDetachFromParent` | `0x004958c0-0x00495935` | Chains parent attach/detach and attaches/removes text provider. |
| `OnPaint` | `0x00495940-0x00495a94` | Draws BUTTONEX resources, disabled offset, optional icon/text overlays. |
| `ScalarDeletingDestructor` | `0x0049b860-0x0049b8c6` | Releases text provider and base pane; generated owner names are polluted. |

## Evidence Notes

- Wave3 reports 11 methods and a 97.6 effective class grade.
- Generated source includes `BowGaugeObjectPane` and an emitted `Pane::~Pane` body at `0x00544580`; treat those as base-teardown artifacts until ownership is corrected.
- 2026-05-25 IDA MCP rechecked `0x00495450`: it is a real function called only from `0x00517f30` in current callers, sets `ButtonControlPane` then `TextButtonExControlPane` vtables, measures the label, allocates a `372` byte text-provider child through `0x00595390`, and shows that child through `0x005446b0`. This should not stay under `FittingRoomUserImageControlPane`.

## Cross-References

- [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md)
- [UID:0000EJ][TextButtonControlPane](by-class/TextButtonControlPane.md)
- [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `82`, confidence `76`.
- Evidence: the page documents extended button role, constructor/state/text/show/hide/attach/paint/destructor ranges, text-provider child behavior, caller evidence, and generated owner-name pollution; confidence remains capped by destructor/helper owner names.
