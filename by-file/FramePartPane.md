*** UID:000578 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/core/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# FramePartPane

## Status

- Disposition: retained inferred NexusTK UI-core source unit, reconstructed as `NexusTK/ui/core/FramePartPane.cpp` and `FramePartPane.h`.
- Source-root role: this page routes the complete class, five-slot storage, builder, raw cleanup helper, compiler products, and resource uses. It does not duplicate child-owned formal C++.
- Reachability status: coherent source is retained, but exhaustive current xref and encoded-pointer searches find no entry route to the builder or cleanup helper. This is a liveness/confidence cap, not a no-code classification.
- Semantic umbrella: [UID:0000JL][FrameChrome](by-file/FrameChrome.md) remains a non-emitting historical index only.

## Complete Source Inventory

| Source item | Exact binary/documentation range | Role and source disposition |
| --- | --- | --- |
| [UID:00005I][FramePartPane](by-class/FramePartPane.md) | allocation size `0xfc` | Complete class declaration in `FramePartPane.h`; `Pane` base plus `int m_partIndex` at `+0xf8`. |
| [UID:00022F][0x004b7120-0x004b731f.BuildFramePartPanes](by-memory/0x004b7120-0x004b731f.BuildFramePartPanes.md) | `0x004b7120-0x004b731f` | File-level builder for five fixed frame pieces. |
| [UID:00015N][0x004b7320-0x004b73a3.FramePartPaneSlotCleanup](by-memory/0x004b7320-0x004b73a3.FramePartPaneSlotCleanup.md) | `0x004b7320-0x004b73a3` | Exact 131-byte source-authored raw cleanup followed by excluded 13-byte `CC` alignment. |
| [UID:00015O][0x004b73b0-0x004b7661.FramePartPane](by-memory/0x004b73b0-0x004b7661.FramePartPane.md) | `0x004b73b0-0x004b7661` | `OnChangeMessage`, `OnPaint`, constructor, ordinary destructor, and compiler-covered scalar deleting wrapper. |
| [UID:00015P][0x004b7590-0x004b75a6.FramePartPaneAdjustorThunks](by-memory/0x004b7590-0x004b75a6.FramePartPaneAdjustorThunks.md) | `0x004b7590-0x004b75a6` | Two compiler-generated destructor adjustors; exact no-code evidence. |
| [UID:0001PF][0x0069b33c-0x0069b350.FramePartPaneSlots](by-memory/0x0069b33c-0x0069b350.FramePartPaneSlots.md) | `0x0069b33c-0x0069b350` | Source-facing `static FramePartPane *g_framePartPanes[5]`. |
| [UID:0002NH][0x0061a7f8-0x0061a880.FramePartPaneVtableData](by-memory/0x0061a7f8-0x0061a880.FramePartPaneVtableData.md) | `0x0061a7f8-0x0061a880` | RTTI plus three vtable views generated from the class declaration; blank raw-table source. |
| [UID:0003I3][FramePartPaneVtables](by-type/by-vtable/FramePartPaneVtables.md) | primary/secondary/tertiary views | Source-local vtable/type index; compiler-generated no-raw-table disposition. |
| [UID:0000U5][BuildFramePartPanes_004B7120](by-item/BuildFramePartPanes_004B7120.md) | promoted index | Non-emitting pointer to canonical UID00022F; no duplicate C++. |
| Resource literals | `FRMPART.EPF` and `FRMPART.EPD` | Use-site literals shared with AboveFrame; no standalone declaration or comment emitter. |

Exact excluded boundaries are `[0x004b73a3,0x004b73b0)` alignment after cleanup, padding after `0x004b7661`, successor RectBounds family at `0x004b7670`, and slot successor `0x0069b350`.

## Behavior And Liveness

- `BuildFramePartPanes` performs five `0xfc` allocations and constructor calls at `0x4b718c`, `0x4b71e2`, `0x4b723b`, `0x4b7294`, and `0x4b72f0`. It creates indexes `4,0,1,2,3` in top/left/right/lower-left/lower-right rectangles and writes the five slot addresses.
- `ReleaseFramePartPanes` contains five exact null-check/delete/clear sequences and returns at `0x004b73a2`. It is source-authored despite not being modeled as an IDA function.
- `OnChangeMessage` handles `goog`, queues this pane for deferred deletion, and clears all five slots.
- `OnPaint` is a `void` virtual override. It selects `FRMPART.EPF` or `FRMPART.EPD`, resolves the indexed frame, and renders it in `m_visibleBounds`; the historical `int OnPaintFrame` spelling is superseded.
- The constructor stores `m_partIndex`, adds the pane to the main layer, and registers the listener. The destructor unregisters the listener, calls `RemoveFromLayer`, and destroys the Pane base.
- Builder and cleanup each have zero incoming refs and zero matching VA/RVA/start-pointer patterns. No evidence supports reclassifying either body as compiler glue.

## Object Layout

`FramePartPane` is exactly `0xfc` bytes: inherited `Pane` occupies `0x000-0x0f8`, and `int m_partIndex` occupies `0x0f8-0x0fc`. The constructor takes `int partIndex` and `const RectBounds &bounds`. Primary, secondary, and tertiary vtable views plus destructor adjustors are compiler products of the class hierarchy.

## Source Order And Formal Channels

The generated source order is fixed:

1. [UID:00005I][FramePartPane](by-class/FramePartPane.md) emits `#include "FramePartPane.h"`, required `BlackHole.h`, and the complete H declaration.
2. [UID:0001PF][0x0069b33c-0x0069b350.FramePartPaneSlots](by-memory/0x0069b33c-0x0069b350.FramePartPaneSlots.md) emits the five-entry file-static array.
3. [UID:00022F][0x004b7120-0x004b731f.BuildFramePartPanes](by-memory/0x004b7120-0x004b731f.BuildFramePartPanes.md) emits `BuildFramePartPanes`.
4. [UID:00015N][0x004b7320-0x004b73a3.FramePartPaneSlotCleanup](by-memory/0x004b7320-0x004b73a3.FramePartPaneSlotCleanup.md) emits `ReleaseFramePartPanes`.
5. [UID:00015O][0x004b73b0-0x004b7661.FramePartPane](by-memory/0x004b73b0-0x004b7661.FramePartPane.md) emits callback, paint, constructor, and ordinary destructor methods.

The by-file page is a routing root and owns no duplicate formal body. Compiler adjustors, scalar deleting wrapper, RTTI/vtable bytes, and alignment remain generated/no-code.

## Generated Output Contract

- Required outputs: `auto-generated/NexusTK/ui/core/FramePartPane.cpp` and `FramePartPane.h`.
- The CPP must contain the array, builder, cleanup, and four class methods in the declared order, with no empty-emitter marker and no AboveFrame body.
- The H must contain one complete `FramePartPane : public Pane` declaration with constructor, virtual destructor, `OnPaint`, `OnChangeMessage`, and `m_partIndex`.
- `FrameChrome.cpp/.h` is obsolete after this split and must not retain duplicate output.

## Ownership And Rejected Alternatives

- Selected owner: class-centered `FramePartPane.cpp/.h`, based on one complete code island, adjacent builder/cleanup source order, one contiguous slot family, and one separate three-view vtable family.
- Rejected `FrameChrome.cpp`: a historical semantic grouping that incorrectly joins this retained island to the distant active AboveFrame unit.
- Rejected `FrameMgr`, generic Pane manager, and resource/image files: none owns the five-slot lifetime or this class hierarchy.
- Rejected class-method placement for builder/cleanup: they operate on file-static family state and have no receiver.

## Negative Evidence And Remaining Uncertainty

- No direct caller, xref, rel32 route, stored VA, or stored RVA reaches builder or cleanup starts.
- No PDB, source path, or original private symbols prove the historical basename or array spelling.
- Contiguous uniform lifecycle strongly favors `g_framePartPanes[5]`; five separate statics remain layout-equivalent but less likely.
- These uncertainties cap score/confidence but do not justify raw compiler names or blank source for the retained bodies.

## Cross-References

- [UID:0000JL][FrameChrome](by-file/FrameChrome.md)
- [UID:0000PN][FrameChromeSlots](by-global/FrameChromeSlots.md)
- [UID:0002SG][0x00610f60-0x00610fe8.FrameChromeResourceStrings](by-memory/0x00610f60-0x00610fe8.FrameChromeResourceStrings.md)
- [UID:000005][AboveFrame](by-class/AboveFrame.md)

## Score Rationale

Completion `91` reflects a complete function/data/type/resource inventory, exact boundaries, source order, routing, formal CPP/H ownership, compiler-product exclusions, and generated-output contract. Confidence `93` preserves a larger reserve than AboveFrame because builder/cleanup have no discoverable current entry route and original private spellings remain inferred.
