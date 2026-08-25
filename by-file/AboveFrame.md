*** UID:000577 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/core/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# AboveFrame

## Status

- Disposition: active inferred NexusTK UI-core source unit, reconstructed as `NexusTK/ui/core/AboveFrame.cpp` and `AboveFrame.h`.
- Source-root role: this page routes one concrete class, its file-static slots, three source-authored file helpers, exact compiler-product evidence, and resource-use dependencies. It does not duplicate child-owned formal C++.
- Evidence confidence: very strong for the complete inventory, object layout, active startup/dynamic reachability, source order, and separate source unit; high for the historical basename and private spelling because no PDB, map, or original path survives.
- Semantic umbrella: [UID:0000JL][FrameChrome](by-file/FrameChrome.md) remains a non-emitting historical index only.

## Complete Source Inventory

| Source item | Exact binary/documentation range | Role and source disposition |
| --- | --- | --- |
| [UID:000005][AboveFrame](by-class/AboveFrame.md) | allocation size `0x134` | Complete class declaration in `AboveFrame.h`; `Pane` base, `EPFTileContext`, one `RectBounds`, palette-mode byte, and natural tail alignment. |
| [UID:0000YH][0x004610f0-0x0046178a.AboveFrame](by-memory/0x004610f0-0x0046178a.AboveFrame.md) | `0x004610f0-0x0046178a` | Constructor, ordinary destructor, `OnPaint`, `OnChangeMessage`, and compiler-covered scalar deleting destructor. Source methods emit here; wrapper does not. |
| [UID:0000U2][BuildAboveFrameBorder_00461310](by-item/BuildAboveFrameBorder_00461310.md) | `0x00461310-0x004615aa` | Active file-level builder with EPF and legacy branches. |
| [UID:0000YI][0x004615b0-0x00461658.AboveFrameRefreshHelpers](by-memory/0x004615b0-0x00461658.AboveFrameRefreshHelpers.md) | `0x004615b0-0x00461658` | `ReleaseDynamicAboveFrame` and `RecreateDynamicAboveFrame`. |
| [UID:0000YJ][0x004616c8-0x004616de.AboveFrameAdjustorThunks](by-memory/0x004616c8-0x004616de.AboveFrameAdjustorThunks.md) | `0x004616c8-0x004616de` | Two compiler-generated destructor adjustors; exact no-code evidence. |
| [UID:0001P1][0x0067a834-0x0067a874.AboveFrameSlots](by-memory/0x0067a834-0x0067a874.AboveFrameSlots.md) | `0x0067a834-0x0067a874` | Five scalar pointer roles, two five-entry pointer arrays, and one four-byte no-source alignment gap. |
| [UID:0002NG][0x00610ed8-0x00610f60.AboveFrameVtableData](by-memory/0x00610ed8-0x00610f60.AboveFrameVtableData.md) | `0x00610ed8-0x00610f60` | RTTI plus three vtable views generated from the class declaration; blank raw-table source. |
| [UID:0003I2][AboveFrameVtables](by-type/by-vtable/AboveFrameVtables.md) | primary/secondary/tertiary views | Source-local vtable/type index; compiler-generated no-raw-table disposition. |
| Resource literals | `0x00610f60-0x00610fe8` children | `FRMPART.EPF`, `TABS.EPF`, `FRMPART.EPD`, `FRMPART.PAL`, `TABS.PAL`, and `NPAL5.PAL` are emitted as use-site literals only, never standalone data objects. |

Excluded neighbors are exact: the method island ends at `0x0046178a`; the slot family excludes `0x0067a874` `g_pGeneralPurposePanel`; and the vtable family ends at the `FRMPART.EPF` literal boundary `0x00610f60`.

## Behavior And Reachability

- The constructor has ten direct calls at `0x461368`, `0x4613a0`, `0x4613db`, `0x461423`, `0x461476`, `0x4614ae`, `0x4614e9`, `0x461535`, `0x461570`, and `0x461626`.
- `BuildAboveFrameBorder` is active from Main UI startup calls at `0x4f802c` and `0x4f8670`.
- `ReleaseDynamicAboveFrame` is called at `0x4b872e` and `0x4b8a62`; `RecreateDynamicAboveFrame` follows at `0x4b8733` and `0x4b8a67`.
- Construction resolves EPF/EPD layouts, offsets bounds, adds the pane to the main layer, and registers the `goog` listener. The ordinary destructor unregisters the listener but does not call `RemoveFromLayer`; source must not invent that call.
- `OnPaint` selects `NPAL5.PAL`, `TABS.PAL`, or `FRMPART.PAL` according to asset mode and frame mode, then draws the retained tile context. `OnChangeMessage` marks the pane for deletion on the `goog` message.
- Dynamic release intentionally deletes without clearing `g_pDynamicAboveFrame`, matching the observed body.

## Object Layout

`AboveFrame` is exactly `0x134` bytes: `Pane` occupies `0x000-0x0f8`, `EPFTileContext m_tileContext` occupies `0x0f8-0x120`, `RectBounds m_bounds` occupies `0x120-0x130`, `unsigned char m_framePaletteMode` is at `0x130`, and three bytes of natural tail alignment complete the allocation. Earlier documentation that described a second bounds object is superseded by the constructor offsets and allocation size.

## Source Order And Formal Channels

The generated source order is fixed:

1. [UID:000005][AboveFrame](by-class/AboveFrame.md) emits `#include "AboveFrame.h"` and the complete H declaration.
2. [UID:0001P1][0x0067a834-0x0067a874.AboveFrameSlots](by-memory/0x0067a834-0x0067a874.AboveFrameSlots.md) emits the file-static pointer declarations.
3. [UID:0000YH][0x004610f0-0x0046178a.AboveFrame](by-memory/0x004610f0-0x0046178a.AboveFrame.md) emits the four source-authored class methods.
4. [UID:0000U2][BuildAboveFrameBorder_00461310](by-item/BuildAboveFrameBorder_00461310.md) emits `BuildAboveFrameBorder`.
5. [UID:0000YI][0x004615b0-0x00461658.AboveFrameRefreshHelpers](by-memory/0x004615b0-0x00461658.AboveFrameRefreshHelpers.md) emits release/recreate helpers.

The by-file page is a routing root and owns no duplicate formal body. Compiler adjustors, scalar deleting wrapper, RTTI/vtable bytes, linker alignment, and pooled literals remain generated/no-code.

## Generated Output Contract

- Required outputs: `auto-generated/NexusTK/ui/core/AboveFrame.cpp` and `AboveFrame.h`.
- The CPP must contain every source item above in the declared order, with no empty-emitter marker, no FramePartPane body, and no raw compiler-product definition.
- The H must contain one complete `AboveFrame : public Pane` declaration with constructor, virtual destructor, `OnPaint`, `OnChangeMessage`, `m_tileContext`, `m_bounds`, and `m_framePaletteMode`.
- `FrameChrome.cpp/.h` is obsolete after this split and must not retain duplicate output.

## Ownership And Rejected Alternatives

- Selected owner: class-centered `AboveFrame.cpp/.h`, based on one contiguous active code island, one slot family, one three-view vtable family, and complete startup/dynamic routes.
- Rejected `FrameChrome.cpp`: useful historical semantic label but it conflates two distant independent object families and produced malformed mixed generated output.
- Rejected `GeneralPurposePanel`: it supplies one active-child index but does not own the frame class, helpers, slots, or vtables.
- Rejected EPF/ImageLib and resource-table files: they are dependencies used by the frame code, not owners of pane lifetime.
- Rejected the polluted standard-library label at `0x004615d0`: body, callers, globals, and allocation prove `RecreateDynamicAboveFrame`.

## Negative Evidence And Remaining Uncertainty

- No original source path, PDB, linker map, or private field symbols prove the literal basename or spellings.
- Shared palette strings have external consumers and do not establish exclusive ownership.
- These uncertainties cap final-audit confidence but do not justify retaining raw `sub_`, `unk_`, or `dword_` names in source.

## Cross-References

- [UID:0000JL][FrameChrome](by-file/FrameChrome.md)
- [UID:0000PN][FrameChromeSlots](by-global/FrameChromeSlots.md)
- [UID:0002SG][0x00610f60-0x00610fe8.FrameChromeResourceStrings](by-memory/0x00610f60-0x00610fe8.FrameChromeResourceStrings.md)
- [UID:00005I][FramePartPane](by-class/FramePartPane.md)

## Score Rationale

Completion `93` reflects a complete function/data/type/resource inventory, exact boundaries, source order, routing, formal CPP/H ownership, compiler-product exclusions, and generated-output contract. Confidence `95` reflects direct caller/xref/layout/vtable agreement while retaining a narrow reserve for the unproved historical basename and private lexical spellings.
