*** UID:0000OW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# TransferServerDialogPane

## Status

- Confidence: very strong for class/file ownership, exact source/compiler split, declarations, method bodies, globals, layout/vtables, resources, callers, dependencies, and exclusions.
- Proposed module: `ui/dialogs/TransferServerDialogPane.cpp`
- Historical recovered-source lead: `class_TransferServerDialogPane.cpp`; accepted output is `NexusTK/ui/dialogs/TransferServerDialogPane.cpp`.
- Evidence basis: generated source and older Wave2 entries as leads, plus IDA-backed class/memory/global/read-only-data/launcher pages through 2026-06-07.

## File Role

`TransferServerDialogPane.cpp` owns the animated transfer-server overlay. It loads `TRANSSVR` animation frames, computes the overlay bounds, positions itself relative to the active parcel pane or cursor anchor, fades/advances frames on a timer, optionally auto-closes, and clears the transfer overlay singleton on teardown.

This is best treated as a reusable UI transition/overlay dialog rather than map logic. It is used by login/map/session paths, but the implementation itself is animation-pane infrastructure around the `TRANSSVR` asset family.

## Accepted Source Contents And Order

1. [UID:0000F7][TransferServerDialogPane](by-class/TransferServerDialogPane.md) emits the closed class declaration, extern singleton declaration, and `[[CHILDREN]]` insertion point.
2. Source children emit in exact address order: [UID:0004MV][0x00598ed0-0x0059921f.TransferServerDialogPaneConstructor](by-memory/0x00598ed0-0x0059921f.TransferServerDialogPaneConstructor.md), [UID:0004MW][0x00599220-0x00599248.TransferServerDialogPaneDestructor](by-memory/0x00599220-0x00599248.TransferServerDialogPaneDestructor.md), [UID:0004MX][0x00599250-0x00599261.TransferServerDialogPaneResetOpacityAndRepaint](by-memory/0x00599250-0x00599261.TransferServerDialogPaneResetOpacityAndRepaint.md), [UID:0004MY][0x00599270-0x005992e8.TransferServerDialogPaneOnTimer](by-memory/0x00599270-0x005992e8.TransferServerDialogPaneOnTimer.md), and [UID:0004MZ][0x005992f0-0x005993a5.TransferServerDialogPaneOnPaint](by-memory/0x005992f0-0x005993a5.TransferServerDialogPaneOnPaint.md).
3. [UID:0000SL][g_pTransferServerDialog](by-global/g_pTransferServerDialog.md) emits `TransferServerDialogPane *g_pTransferServerDialog = 0;` after the method children.
4. Compiler-support children [UID:0004N0][0x005993b0-0x005993ba.TransferServerDialogPaneConstructorUnwindClearSingleton](by-memory/0x005993b0-0x005993ba.TransferServerDialogPaneConstructorUnwindClearSingleton.md), [UID:0004N1][0x005993bb-0x005993d0.TransferServerDialogPaneDestructorAdjustorThunks](by-memory/0x005993bb-0x005993d0.TransferServerDialogPaneDestructorAdjustorThunks.md), and [UID:0004N2][0x005993e0-0x0059943e.TransferServerDialogPaneScalarDeletingDestructor](by-memory/0x005993e0-0x0059943e.TransferServerDialogPaneScalarDeletingDestructor.md) remain non-emitting.

The exact executable parent [UID:0001KD][0x00598ed0-0x0059943f.TransferServerDialogPane](by-memory/0x00598ed0-0x0059943f.TransferServerDialogPane.md), read-only parent [UID:00026R][0x0062e47c-0x0062e578.TransferServerReadOnlyData](by-memory/0x0062e47c-0x0062e578.TransferServerReadOnlyData.md), physical children UIDs 0004MS/0004MT/0004MU, [UID:0004N3][TransferServerDialogPaneLayout](by-type/by-struct/TransferServerDialogPaneLayout.md), [UID:0004N4][TransferServerDialogPaneVtables](by-type/by-vtable/TransferServerDialogPaneVtables.md), compatibility item UID0000VJ, and storage UID0002XO are documentation/support only and add no source output.

## Dependencies And Exclusions

- Base/type dependencies: Pane, GrafPort, EventHandler, TimerHandler, Singleton, RectBounds, Point, and EPFTileContext.
- Runtime dependencies: EPF/ImageLib entry count/rect/lookup, PaletteLib, Surface sprite callback, active map and screen panes, MainUiLayerSlots, Timer scheduling, SoundManager, and `g_useEpfAssets`.
- MainMenuPane, MapPane, login/session handlers, and transfer packet paths are callers/consumers, not implementation owners. Nine constructor calls and two reset calls do not transfer source ownership.
- TimerPane/TotemFrame and UniAPIInit/UrlAlertPane are physical neighbors only; corrected byte boundaries exclude them.
- No raw RTTI/vtable arrays, explicit vptr/facet/cookie fields, standalone resource arrays, named fade global, handwritten EH cleanup/adjustor/scalar wrapper, defensive frame-count guard, initialized union accumulator, or EPFTileContext release is accepted.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 92 | Exact declaration, five source methods, one global, three compiler-support dispositions, children, source order, layout/vtables, resources, callers, dependencies, boundaries, and rejected alternatives are all resolved. |
| Confidence | 94 | Live IDA-backed class/memory/global/item/data evidence and all exact hashes/routes agree; absent original source spellings cap confidence without blocking the implementation. |

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `TransferServerDialogPane` | `0x00598ed0-0x0059943f` | Animated transfer overlay construction, fade/opacity reset, timer animation, paint, and destructor behavior. |
| [UID:0000SL][g_pTransferServerDialog](by-global/g_pTransferServerDialog.md) | `0x0069b4b0` | Active transfer overlay singleton. |
| Destructor/helper island | `0x00599220`, `0x005993b0-0x0059943f` | [UID:0000VJ][TransferServerDialogPaneThunks_599220_5993e0](by-item/TransferServerDialogPaneThunks_599220_5993e0.md), including non-deleting helper with no direct xrefs, constructor-unwind singleton clear helper, adjustor thunks, and scalar deleting destructor. |
| `TRANSSVR` resources | string/resource evidence | `TRANSSVR.EPF`/`TRANSSVR.EPD`, `TRANSSVR.PAL`/`TRANSSVR.PAD` animation frames and palettes. |
| read-only data island | [UID:00026R][0x0062e47c-0x0062e578.TransferServerReadOnlyData](by-memory/0x0062e47c-0x0062e578.TransferServerReadOnlyData.md) | TransferServerDialogPane vtables followed by the `TRANSSVR` resource filename family. |
| retained launcher | [UID:0002Q6][0x004f8f10-0x004f8f95.OpenTransferServerDialog](by-memory/0x004f8f10-0x004f8f95.OpenTransferServerDialog.md) | Main-menu/helper path that gates on the singleton, allocates `0x100`, and constructs the overlay when absent; belongs to `MainMenuPane`, not this implementation file. |

## Evidence Notes

- IDA MCP confirms constructor `0x00598ed0-0x00599220`, non-deleting destructor helper `0x00599220-0x00599249`, reset helper `0x00599250-0x00599262`, timer handler `0x00599270-0x005992e9`, paint handler `0x005992f0-0x005993a6`, singleton clear and adjustor helpers `0x005993b0-0x005993d1`, and scalar deleting destructor `0x005993e0-0x0059943f`.
- Older Wave2 report entries already restored `ResetOpacityAndRepaint` at `0x00599250` and kept `OnPaintFrame` at `0x005992f0` as authoritative.
- Constructor callers include login/main UI and map/session paths, which supports a shared overlay placement.
- 2026-05-24 MCP recheck: `xrefs_to 0x0069b4b0` confirms constructor stores, helper/destructor clears, and external login/map/session users. Decompilation of `0x00599220` and `0x005993e0` both call the same base teardown at `0x00544580`, supporting a `Pane` base path over the generated `TextButtonExControlPane::~Pane` label.
- IDA confirms `0x005993bb` and `0x005993c6` as adjustor thunks into `0x005993e0`, with vtable/data refs at `0x0062e4cc` and `0x0062e4fc`.
- [UID:0001KD][0x00598ed0-0x0059943f.TransferServerDialogPane](by-memory/0x00598ed0-0x0059943f.TransferServerDialogPane.md) records exact raw-export sizes, constructor callers, callee/resource use, timer scheduling, paint-time image/palette selection, singleton clear paths, and one-byte padding before/after the range.
- [UID:00026R][0x0062e47c-0x0062e578.TransferServerReadOnlyData](by-memory/0x0062e47c-0x0062e578.TransferServerReadOnlyData.md) ties primary/adjusted vtables and `TRANSSVR.EPF`/`.EPD`/`.PAL`/`.PAD` strings to constructor, timer, paint, thunk, and scalar-destructor refs.
- [UID:0002Q6][0x004f8f10-0x004f8f95.OpenTransferServerDialog](by-memory/0x004f8f10-0x004f8f95.OpenTransferServerDialog.md) confirms a retained launcher that cancels a timer-backed state hook, checks [UID:0000SL][g_pTransferServerDialog](by-global/g_pTransferServerDialog.md), allocates `0x100`, and constructs this dialog if the singleton is absent.
- 2026-06-07 Batch 043 and the later 2026-06-12 C001 correction reconfirmed [UID:0000SL][g_pTransferServerDialog](by-global/g_pTransferServerDialog.md) as an exact four-byte singleton slot with initial bytes `00 00 00 00` and 20 direct xrefs. The split storage page [UID:0002XO][0x0069b4b0-0x0069b4b4.g_pTransferServerDialog](by-memory/0x0069b4b0-0x0069b4b4.g_pTransferServerDialog.md) separates it from neighboring login-dialog globals.
- 2026-06-16 A002 live IDA MCP session `c001_midiplayer_rdata_20260615` refreshed the file-level evidence. `lookup_funcs` reconfirmed the exact constructor/reset/timer/paint/destructor-helper ranges, and `get_bytes` reconfirmed all gaps inside `0x00598ed0-0x0059943f` are `0xcc` alignment. `xref_query` reconfirmed nine constructor calls, two reset-helper calls from `0x005aac80`, data-only reachability for the timer/paint/adjustor/scalar-destructor slots, one constructor-unwind code ref to the singleton clear helper, zero direct xrefs to the non-deleting helper, and 20 direct refs to `g_pTransferServerDialog`.
- The 2026-06-16 constructor/timer disassembly resolves the timer-subobject offset to `this+0x0a4`: constructor tail sets `ecx = this + 0x0a4` before scheduling event `0` every `0x64` ms and optional event `1` at `0x1388` ms; timer event `1` subtracts `0x0a4` back to the primary pane before calling close/remove helper `0x00544690`. Field roles are now offset-confirmed as fade/opacity at primary `+0x90`, current frame at `+0x0f8`, and frame count at `+0x0fc`; final source names remain unresolved.
- A002 also checked hidden pointer-byte reachability with `find_bytes`: only the expected vtable entries were found for timer, paint, adjustor thunks, and scalar deleting destructor. No VA/RVA pointer-byte hits were found for the constructor, non-deleting helper, reset helper, or singleton clear helper, so the remaining destructor/thunk source-shape caveat is real rather than uninvestigated.

## Behavior And State

| Function | Source-facing role |
| --- | --- |
| Constructor `0x00598ed0` | Builds the base pane with style/id `3`, publishes [UID:0000SL][g_pTransferServerDialog](by-global/g_pTransferServerDialog.md), installs three vtables, scans the transfer-server frame family to compute overlay bounds, positions the pane relative to active UI/screen state, initializes fade/frame fields, starts event `0` at `100ms` through the `this+0x0a4` timer subobject, optionally starts event `1` at `5000ms`, and plays transfer sound `0x19c`. |
| `ResetOpacityAndRepaint` `0x00599250` | Clears the fade/opacity field at primary offset `+0x90` and dispatches repaint/update; called from transfer-server entry paths. |
| Timer handler `0x00599270` | Handles the animation tick by fading opacity, advancing frame index modulo frame count, repainting, and rescheduling through the timer subobject; event `1` closes/removes the primary pane. |
| Paint handler `0x005992f0` | Loads the current `TRANSSVR` frame and palette family, recenters the frame rectangle, and calls the render callback with blend/alpha arguments. |
| Destructor helpers `0x00599220`, `0x005993b0`, `0x005993e0` | Restore class vtables, clear the singleton, call base pane teardown `0x00544580`, and conditionally free memory for scalar deletion. |

## Ownership Notes

Keep this separate from `TotemFrame` and generic pane/base classes. Nearby `0x00598e70` is currently a `TotemFrame` destructor, while `0x00598ed0` begins the transfer overlay constructor. The generated destructor's `TextButtonExControlPane::~Pane` call should be treated as base-owner pollution; IDA now shows both destructor helper paths calling the same base teardown helper at `0x00544580`.

Final C++ remains intentionally blank in child pages until the transfer-overlay field names, timer-subobject member name, and destructor/thunk representation can be written as source-quality C++ rather than offset-based reverse-engineering names.

## Cross-References

- [UID:0000F7][TransferServerDialogPane](by-class/TransferServerDialogPane.md)
- [UID:0001KD][0x00598ed0-0x0059943f.TransferServerDialogPane](by-memory/0x00598ed0-0x0059943f.TransferServerDialogPane.md)
- [UID:0000SL][g_pTransferServerDialog](by-global/g_pTransferServerDialog.md)
- [UID:0000VJ][TransferServerDialogPaneThunks_599220_5993e0](by-item/TransferServerDialogPaneThunks_599220_5993e0.md)
- [UID:00026R][0x0062e47c-0x0062e578.TransferServerReadOnlyData](by-memory/0x0062e47c-0x0062e578.TransferServerReadOnlyData.md)
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
  - Summary/evidence: [UID:0001KD][0x00598ed0-0x0059943f.TransferServerDialogPane](by-memory/0x00598ed0-0x0059943f.TransferServerDialogPane.md), [UID:00026R][0x0062e47c-0x0062e578.TransferServerReadOnlyData](by-memory/0x0062e47c-0x0062e578.TransferServerReadOnlyData.md), [UID:0000SL][g_pTransferServerDialog](by-global/g_pTransferServerDialog.md), and [UID:0002Q6][0x004f8f10-0x004f8f95.OpenTransferServerDialog](by-memory/0x004f8f10-0x004f8f95.OpenTransferServerDialog.md) now support the file-level owner, while final field names, timer subobject names, and destructor/thunk source representation remain below the final-C++ gate.
- 2026-06-07 Batch 043 parent-gate refresh:
  - Before: `86/84`.
  - After: `87/86`.
  - Evidence: live IDA MCP reconfirmed exact singleton storage bounds, initial value, and 20 xrefs across construction, teardown, retained launcher, map/session, and living-object code. The remaining field/timer naming caveats still block final source C++, but no longer block the direct global parent chain.
- 2026-06-16 A002 low-confidence target support refresh:
  - Before: `87/86`.
  - After: `88/88`.
  - Evidence: live IDA MCP reconfirmed the exact executable range, padding gaps, constructor/reset/timer/paint/destructor reachability, singleton xrefs, vtable/resource bytes, and timer-subobject offset. The file remains the direct source root under `NexusTK/ui/dialogs/`; final C++ is still blocked by source-quality field names and destructor/thunk representation, not by ownership or source placement.
