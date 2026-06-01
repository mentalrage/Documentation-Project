*** UID:0000OW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# TransferServerDialogPane

## Status

- Confidence: strong for class/file ownership, medium for destructor helper cleanup.
- Proposed module: `ui/dialogs/TransferServerDialogPane.cpp`
- Current recovered source: `class_TransferServerDialogPane.cpp`
- Evidence basis: Wave3 class/method summaries, generated source, older Wave2 report entries, and IDA MCP boundary checks on 2026-05-23.

## File Role

`TransferServerDialogPane.cpp` owns the animated transfer-server overlay. It loads `TRANSSVR` animation frames, computes the overlay bounds, positions itself relative to the active parcel pane or cursor anchor, fades/advances frames on a timer, optionally auto-closes, and clears the transfer overlay singleton on teardown.

This is best treated as a reusable UI transition/overlay dialog rather than map logic. It is used by login/map/session paths, but the implementation itself is animation-pane infrastructure around the `TRANSSVR` asset family.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `TransferServerDialogPane` | `0x00598ed0-0x0059943f` | Animated transfer overlay construction, opacity reset, timer animation, paint, and destructor behavior. |
| [UID:0000SL][g_pTransferServerDialog](by-global/g_pTransferServerDialog.md) | `0x0069b4b0` | Active transfer overlay singleton. |
| Destructor/helper island | `0x00599220`, `0x005993b0-0x0059943f` | [UID:0000VJ][TransferServerDialogPaneThunks_599220_5993e0](by-item/TransferServerDialogPaneThunks_599220_5993e0.md), including non-deleting helper, singleton clear helper, adjustor thunks, and scalar deleting destructor. |
| `TRANSSVR` resources | string/resource evidence | `TRANSSVR.EPF`/`TRANSSVR.EPD`, `TRANSSVR.PAL`/`TRANSSVR.PAD` animation frames and palettes. |

## Evidence Notes

- IDA MCP confirms constructor `0x00598ed0-0x0059921f`, non-deleting destructor helper `0x00599220-0x00599248`, reset helper `0x00599250-0x00599261`, timer handler `0x00599270-0x005992e8`, paint handler `0x005992f0-0x005993a5`, thunk/global-clear helpers around `0x005993b0-0x005993d0`, and scalar deleting destructor `0x005993e0-0x0059943f`.
- Older Wave2 report entries already restored `ResetOpacityAndRepaint` at `0x00599250` and kept `OnPaintFrame` at `0x005992f0` as authoritative.
- Constructor callers include login/main UI and map/session paths, which supports a shared overlay placement.
- 2026-05-24 MCP recheck: `xrefs_to 0x0069b4b0` confirms constructor stores, helper/destructor clears, and external login/map/session users. Decompilation of `0x00599220` and `0x005993e0` both call the same base teardown at `0x00544580`, supporting a `Pane` base path over the generated `TextButtonExControlPane::~Pane` label.
- IDA confirms `0x005993bb` and `0x005993c6` as adjustor thunks into `0x005993e0`, with vtable/data refs at `0x0062e4cc` and `0x0062e4fc`.

## Ownership Notes

Keep this separate from `TotemFrame` and generic pane/base classes. Nearby `0x00598e70` is currently a `TotemFrame` destructor, while `0x00598ed0` begins the transfer overlay constructor. The generated destructor's `TextButtonExControlPane::~Pane` call should be treated as base-owner pollution; IDA now shows both destructor helper paths calling the same base teardown helper at `0x00544580`.

## Cross-References

- [UID:0000F7][TransferServerDialogPane](by-class/TransferServerDialogPane.md)
- [UID:0001KD][0x00598ed0-0x0059943f.TransferServerDialogPane](by-memory/0x00598ed0-0x0059943f.TransferServerDialogPane.md)
- [UID:0000SL][g_pTransferServerDialog](by-global/g_pTransferServerDialog.md)
- [UID:0000VJ][TransferServerDialogPaneThunks_599220_5993e0](by-item/TransferServerDialogPaneThunks_599220_5993e0.md)
- [UID:0000MC][Pane](by-file/Pane.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)

## Changes

- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `82` and confidence to `80`.
  - Evidence: document covers animated transfer overlay role, proposed contents, singleton/global, IDA boundary evidence, resource family, destructor/thunk island, ownership notes, and cross-references; confidence remains capped by destructor helper cleanup and generated base-owner pollution.
- 2026-05-31: Assigned validator reconstruction path.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank.
  - After: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"`.
  - Evidence: [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) places `TransferServerDialogPane.cpp` under `ui/dialogs`; IDA MCP confirms the compact `0x00598ed0-0x0059943f` transfer overlay range and `g_pTransferServerDialog` lifecycle.
