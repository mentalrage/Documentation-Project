*** UID:00003T | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DialogPane

## Status

- Confidence: strong for class role.
- Likely source file: [UID:0000IT][DialogPane](by-file/DialogPane.md)
- Main address range: [UID:00012R][0x0049d8a0-0x0049feae.DialogPane](by-memory/0x0049d8a0-0x0049feae.DialogPane.md)
- Type docs: [UID:0001U4][DialogPaneLayout](by-type/by-struct/DialogPaneLayout.md), [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md)
- Current recovered file: `source-3/simroot_v2/class_DialogPane.cpp`

## Class Purpose

`DialogPane` is the base dialog class. It owns dialog title/config state, modal registration, control tracking, creation/destruction hooks, and saved-position behavior. Feature dialogs should derive from it or embed it rather than owning these common routines.

## Observed State

IDA-confirmed offsets and generated-name hints are consolidated in [UID:0001U4][DialogPaneLayout](by-type/by-struct/DialogPaneLayout.md). Current known inherited state includes:

```text
0x000  Pane base
0x0f8  wchar_t m_title[128]
0x1f8  uint16 m_dialogConfigId
0x1fc  control manager pointer
0x200  focused control id
0x204  previous focused id
0x208  title-drag/capture active byte candidate
0x209  constructor mode / saved pane mode byte candidate
0x20c  drag origin X candidate
0x210  drag origin Y candidate
0x214  hover control id
0x218  pressed-control active byte candidate
0x21c  pressed control id candidate
0x220  pressed hit type byte candidate
0x224  selected/prior hover control id candidate
0x228  hit-type/selection visual byte candidate
0x23c  EPFTileContext
0x260  custom/background state
```

Final source-facing names after `0x208` remain provisional; use IDA layout evidence over generated field names when assigning derived-dialog tails.

## Method Families

| Family | Addresses | Role |
| --- | --- | --- |
| Constructor/destructor | `0x0049d8a0`, `0x0048c350` | Initializes dialog state, tile context, mode/cursor state; scalar deleting destructor. |
| vtable adjustor thunks | `0x0048c27b-0x0048c290` | Two IDA-confirmed 0xb-byte secondary/tertiary destructor thunks. |
| Lifecycle | `0x0049dfd0-0x0049e231` | Create, show, destroy, hide, modal registration. |
| Slide animation | `0x0049eac0-0x0049f07e` | Shared slide-open, slide-close, horizontal slide, shrink, and expand helpers; current generated owner labels are polluted by feature dialogs. |
| Position/config/control handling | `0x0049e6e0-0x0049fead` | Dialog config layout, child-control dispatch, focus/hover/selection behavior. |
| Input overrides | `0x0046ad80`, `0x0046e930`; [UID:00020Y][0x0046d330-0x0046d475.WebBoardDialogVirtualCompanions](by-memory/0x0046d330-0x0046d475.WebBoardDialogVirtualCompanions.md) covers derived `0x0046d3b0`, and [UID:00020Z][0x0046d4b0-0x0046d57b.WebBoardDialogInputAndRequestHelpers](by-memory/0x0046d4b0-0x0046d57b.WebBoardDialogInputAndRequestHelpers.md) covers derived `0x0046d4b0` | Embedded window reposition and keyboard input handlers; final derived-owner split remains open for the remaining raw variants. |

IDA `list_globals` confirms `DialogPane` vtable bases at `0x00618a64`, `0x00618ac4`, and `0x00618af4`. The tertiary table is short and ends before neighboring `AlertPane` RTTI.

## Cross-References

- [UID:0000IT][DialogPane](by-file/DialogPane.md)
- [UID:00012R][0x0049d8a0-0x0049feae.DialogPane](by-memory/0x0049d8a0-0x0049feae.DialogPane.md)
- [UID:0001U4][DialogPaneLayout](by-type/by-struct/DialogPaneLayout.md)
- [UID:00012U][0x0049eac0-0x0049f07e.DialogPaneSlideAnimation](by-memory/0x0049eac0-0x0049f07e.DialogPaneSlideAnimation.md)
- [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md)
- [UID:00010U][0x0048c27b-0x0048c290.DialogPaneAdjustorThunks](by-memory/0x0048c27b-0x0048c290.DialogPaneAdjustorThunks.md)
- [UID:0000A2][Pane](by-class/Pane.md)
- [UID:000038][ControlPane](by-class/ControlPane.md)
- [Wave3 noticed problems](../wave3_noticed_problems.md)

## Changes

- 2026-05-27: The input-override row previously listed `0x0046d3b0` as an unresolved DialogPane/derived split. Changed it to point to the `WebBoardDialog` virtual-companion memory page because IDA vtable slot `0x00613654` points to `0x0046d3b0` inside the `WebBoardDialog` vtable family, and the body manipulates embedded browser-control state.
- 2026-05-27: The input-override row also previously kept `0x0046d4b0` in the unresolved DialogPane/derived split. Changed it to point to the `WebBoardDialog` input/request helper page because IDA vtable slot `0x00613658` points to `0x0046d4b0` in the same `WebBoardDialog` vtable family.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `82/84`.
  - Summary/evidence: base dialog role, major layout offsets, constructor/destructor/lifecycle/animation/control/input families, vtable bases, and corrected derived input-owner split are documented; remaining uncertainty is mostly provisional field naming after `0x208` and final source-facing helper names.
- 2026-05-31 reconstructability:
  - Before: `RECONSTRUCTABLE` was blank.
  - After: `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: IDA MCP reconfirms the constructor/lifecycle/control method anchors and vtable stores for the common base dialog class. Parent/code autogen remains blank because the final C++ shape is not at the required near-final threshold.
