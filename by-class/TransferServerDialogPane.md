*** UID:0000F7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# TransferServerDialogPane

## Status

- Confidence: strong for overlay behavior, medium for destructor/base-owner cleanup.
- Likely source file: [UID:0000OW][TransferServerDialogPane](by-file/TransferServerDialogPane.md)
- Address range: [UID:0001KD][0x00598ed0-0x0059943f.TransferServerDialogPane](by-memory/0x00598ed0-0x0059943f.TransferServerDialogPane.md)
- Current recovered file: `source-3/simroot_v2/class_TransferServerDialogPane.cpp`

## Class Purpose

`TransferServerDialogPane` is the animated transfer-server overlay pane. It displays the `TRANSSVR` animation, fades and advances animation frames by timer, optionally auto-closes itself, and clears the singleton on teardown.

## Method Notes

| Method or helper | Address | Role |
| --- | --- | --- |
| `TransferServerDialogPane` | `0x00598ed0` | Constructs the overlay, computes union frame bounds, positions relative to parcel pane or cursor anchor, starts timers, and plays sound. |
| non-deleting destructor helper | `0x00599220` | Resets vtables, clears [UID:0000SL][g_pTransferServerDialog](by-global/g_pTransferServerDialog.md), and tears down the base pane; Wave3 `show method` reports unknown. |
| `ResetOpacityAndRepaint` | `0x00599250` | Sets opacity to zero and repaints; restored by earlier Wave2 work. |
| `OnTimerEvent` | `0x00599270` | Handles animation tick and optional auto-close timer. |
| `OnPaintFrame` | `0x005992f0` | Loads current `TRANSSVR` frame/palette and blits the animation frame. |
| thunk/global-clear island | `0x005993b0-0x005993d0` | Clears singleton and forwards adjustor thunks to the scalar deleting destructor. |
| `ScalarDeletingDestructor` | `0x005993e0` | Clears [UID:0000SL][g_pTransferServerDialog](by-global/g_pTransferServerDialog.md), destroys base pane, and conditionally deletes memory. |

## Evidence Notes

- Wave3 reports class grade `97.5` and current source emits the main behavioral methods.
- IDA MCP confirms several helper/thunk starts that are missing or unknown in Wave3 method lookup.
- Generated destructor source references `TextButtonExControlPane::~Pane`; constructor evidence starts from `Pane::Pane(3)`, so base-owner cleanup remains under review.
- 2026-05-24 IDA MCP decompilation shows `0x00599220` and `0x005993e0` both restore three `TransferServerDialogPane` vtables, clear `0x0069b4b0`, and call base teardown helper `0x00544580`. This makes the current `TextButtonExControlPane::~Pane` generated label likely owner pollution.
- `0x005993bb` and `0x005993c6` are adjustor thunks into `0x005993e0`; their vtable refs support keeping them with this class as compiler glue.

## Cross-References

- [UID:0000OW][TransferServerDialogPane](by-file/TransferServerDialogPane.md)
- [UID:0001KD][0x00598ed0-0x0059943f.TransferServerDialogPane](by-memory/0x00598ed0-0x0059943f.TransferServerDialogPane.md)
- [UID:0000SL][g_pTransferServerDialog](by-global/g_pTransferServerDialog.md)
- [UID:0000VJ][TransferServerDialogPaneThunks_599220_5993e0](by-item/TransferServerDialogPaneThunks_599220_5993e0.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:82`.
  - Summary/evidence: scored from the overlay behavior summary, main method/thunk map, singleton teardown evidence, restored helper note, and remaining destructor/base-owner cleanup caveat.
