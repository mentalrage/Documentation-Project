*** UID:0000OW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# TransferServerDialogPane

## Status

- Confidence: strong for class/file ownership, executable boundaries, singleton/resource ownership, and overlay behavior; medium-high for final field names and destructor/thunk source representation.
- Proposed module: `ui/dialogs/TransferServerDialogPane.cpp`
- Current recovered source: `class_TransferServerDialogPane.cpp`
- Evidence basis: generated source and older Wave2 entries as leads, plus IDA-backed class/memory/global/read-only-data/launcher pages through 2026-06-07.

## File Role

`TransferServerDialogPane.cpp` owns the animated transfer-server overlay. It loads `TRANSSVR` animation frames, computes the overlay bounds, positions itself relative to the active parcel pane or cursor anchor, fades/advances frames on a timer, optionally auto-closes, and clears the transfer overlay singleton on teardown.

This is best treated as a reusable UI transition/overlay dialog rather than map logic. It is used by login/map/session paths, but the implementation itself is animation-pane infrastructure around the `TRANSSVR` asset family.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 86 | The page now covers the executable method/helper range, singleton lifecycle, launcher/consumer paths, `TRANSSVR` vtable/resource island, timer/paint/reset behavior, destructor/thunk island, source placement, and adjacent-owner exclusions. |
| Confidence | 84 | Existing class, memory, global, item, and read-only-data pages agree on ownership and behavior. Confidence remains below final because field names, timer subobject names, and final treatment of the singleton-clear/adjustor-thunk island are not source-quality yet. |

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `TransferServerDialogPane` | `0x00598ed0-0x0059943f` | Animated transfer overlay construction, opacity reset, timer animation, paint, and destructor behavior. |
| [UID:0000SL][g_pTransferServerDialog](by-global/g_pTransferServerDialog.md) | `0x0069b4b0` | Active transfer overlay singleton. |
| Destructor/helper island | `0x00599220`, `0x005993b0-0x0059943f` | [UID:0000VJ][TransferServerDialogPaneThunks_599220_5993e0](by-item/TransferServerDialogPaneThunks_599220_5993e0.md), including non-deleting helper, singleton clear helper, adjustor thunks, and scalar deleting destructor. |
| `TRANSSVR` resources | string/resource evidence | `TRANSSVR.EPF`/`TRANSSVR.EPD`, `TRANSSVR.PAL`/`TRANSSVR.PAD` animation frames and palettes. |
| read-only data island | [UID:00026R][0x0062e480-0x0062e57c.TransferServerReadOnlyData](by-memory/0x0062e480-0x0062e57c.TransferServerReadOnlyData.md) | TransferServerDialogPane vtables followed by the `TRANSSVR` resource filename family. |
| retained launcher | [UID:0002Q6][0x004f8f10-0x004f8f95.OpenTransferServerDialog](by-memory/0x004f8f10-0x004f8f95.OpenTransferServerDialog.md) | Main-menu/helper path that gates on the singleton, allocates `0x100`, and constructs the overlay when absent; belongs to `MainMenuPane`, not this implementation file. |

## Evidence Notes

- IDA MCP confirms constructor `0x00598ed0-0x00599220`, non-deleting destructor helper `0x00599220-0x00599249`, reset helper `0x00599250-0x00599262`, timer handler `0x00599270-0x005992e9`, paint handler `0x005992f0-0x005993a6`, singleton clear and adjustor helpers `0x005993b0-0x005993d1`, and scalar deleting destructor `0x005993e0-0x0059943f`.
- Older Wave2 report entries already restored `ResetOpacityAndRepaint` at `0x00599250` and kept `OnPaintFrame` at `0x005992f0` as authoritative.
- Constructor callers include login/main UI and map/session paths, which supports a shared overlay placement.
- 2026-05-24 MCP recheck: `xrefs_to 0x0069b4b0` confirms constructor stores, helper/destructor clears, and external login/map/session users. Decompilation of `0x00599220` and `0x005993e0` both call the same base teardown at `0x00544580`, supporting a `Pane` base path over the generated `TextButtonExControlPane::~Pane` label.
- IDA confirms `0x005993bb` and `0x005993c6` as adjustor thunks into `0x005993e0`, with vtable/data refs at `0x0062e4cc` and `0x0062e4fc`.
- [UID:0001KD][0x00598ed0-0x0059943f.TransferServerDialogPane](by-memory/0x00598ed0-0x0059943f.TransferServerDialogPane.md) records exact raw-export sizes, constructor callers, callee/resource use, timer scheduling, paint-time image/palette selection, singleton clear paths, and one-byte padding before/after the range.
- [UID:00026R][0x0062e480-0x0062e57c.TransferServerReadOnlyData](by-memory/0x0062e480-0x0062e57c.TransferServerReadOnlyData.md) ties primary/adjusted vtables and `TRANSSVR.EPF`/`.EPD`/`.PAL`/`.PAD` strings to constructor, timer, paint, thunk, and scalar-destructor refs.
- [UID:0002Q6][0x004f8f10-0x004f8f95.OpenTransferServerDialog](by-memory/0x004f8f10-0x004f8f95.OpenTransferServerDialog.md) confirms a retained launcher that cancels a timer-backed state hook, checks [UID:0000SL][g_pTransferServerDialog](by-global/g_pTransferServerDialog.md), allocates `0x100`, and constructs this dialog if the singleton is absent.
- 2026-06-07 Batch 043 live IDA MCP reconfirmed [UID:0000SL][g_pTransferServerDialog](by-global/g_pTransferServerDialog.md) as an exact `0xffffffff` four-byte slot with 20 direct xrefs, and the split storage page [UID:0002XO][0x0069b4b0-0x0069b4b4.g_pTransferServerDialog](by-memory/0x0069b4b0-0x0069b4b4.g_pTransferServerDialog.md) now separates it from neighboring login-dialog globals.

## Behavior And State

| Function | Source-facing role |
| --- | --- |
| Constructor `0x00598ed0` | Builds the base pane with style/id `3`, publishes [UID:0000SL][g_pTransferServerDialog](by-global/g_pTransferServerDialog.md), installs three vtables, scans the transfer-server frame family to compute overlay bounds, positions the pane relative to active UI/screen state, starts event `0` at `100ms`, optionally starts event `1` at `5000ms`, and plays transfer sound `0x19c`. |
| `ResetOpacityAndRepaint` `0x00599250` | Clears the opacity/state field and dispatches repaint/update; called from transfer-server entry paths. |
| Timer handler `0x00599270` | Handles the animation tick by fading opacity, advancing frame index modulo frame count, repainting, and rescheduling; event `1` closes/removes the pane. |
| Paint handler `0x005992f0` | Loads the current `TRANSSVR` frame and palette family, recenters the frame rectangle, and calls the render callback with blend/alpha arguments. |
| Destructor helpers `0x00599220`, `0x005993b0`, `0x005993e0` | Restore class vtables, clear the singleton, call base pane teardown `0x00544580`, and conditionally free memory for scalar deletion. |

## Ownership Notes

Keep this separate from `TotemFrame` and generic pane/base classes. Nearby `0x00598e70` is currently a `TotemFrame` destructor, while `0x00598ed0` begins the transfer overlay constructor. The generated destructor's `TextButtonExControlPane::~Pane` call should be treated as base-owner pollution; IDA now shows both destructor helper paths calling the same base teardown helper at `0x00544580`.

## Cross-References

- [UID:0000F7][TransferServerDialogPane](by-class/TransferServerDialogPane.md)
- [UID:0001KD][0x00598ed0-0x0059943f.TransferServerDialogPane](by-memory/0x00598ed0-0x0059943f.TransferServerDialogPane.md)
- [UID:0000SL][g_pTransferServerDialog](by-global/g_pTransferServerDialog.md)
- [UID:0000VJ][TransferServerDialogPaneThunks_599220_5993e0](by-item/TransferServerDialogPaneThunks_599220_5993e0.md)
- [UID:00026R][0x0062e480-0x0062e57c.TransferServerReadOnlyData](by-memory/0x0062e480-0x0062e57c.TransferServerReadOnlyData.md)
- [UID:0002Q6][0x004f8f10-0x004f8f95.OpenTransferServerDialog](by-memory/0x004f8f10-0x004f8f95.OpenTransferServerDialog.md)
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
- 2026-06-07 A001 file-page reconciliation:
  - What existed before: the file page had the correct overlay role and path but lagged newer memory/global/read-only-data pages for exact ranges, resource/vtable ownership, launcher handling, and score rationale.
  - Changed to: completion `86`, confidence `84`; added score rationale, exact half-open helper ranges, read-only data and launcher rows, behavior/state table, and cross-links to the `TRANSSVR` `.rdata` island and retained launcher.
  - Summary/evidence: [UID:0001KD][0x00598ed0-0x0059943f.TransferServerDialogPane](by-memory/0x00598ed0-0x0059943f.TransferServerDialogPane.md), [UID:00026R][0x0062e480-0x0062e57c.TransferServerReadOnlyData](by-memory/0x0062e480-0x0062e57c.TransferServerReadOnlyData.md), [UID:0000SL][g_pTransferServerDialog](by-global/g_pTransferServerDialog.md), and [UID:0002Q6][0x004f8f10-0x004f8f95.OpenTransferServerDialog](by-memory/0x004f8f10-0x004f8f95.OpenTransferServerDialog.md) now support the file-level owner, while final field names, timer subobject names, and destructor/thunk source representation remain below the final-C++ gate.
- 2026-06-07 Batch 043 parent-gate refresh:
  - Before: `86/84`.
  - After: `87/86`.
  - Evidence: live IDA MCP reconfirmed exact singleton storage bounds, initial value, and 20 xrefs across construction, teardown, retained launcher, map/session, and living-object code. The remaining field/timer naming caveats still block final source C++, but no longer block the direct global parent chain.
