*** UID:00004G | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000J2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000J2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "EPFImageControlPane.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_UI_CONTROLS_EPFIMAGECONTROLPANE_H
#define NEXUSTK_UI_CONTROLS_EPFIMAGECONTROLPANE_H

#include "../core/ControlPane.h"

struct RectBounds;

class EPFImageControlPane : public ControlPane
{
public:
    EPFImageControlPane(const wchar_t *resourceName,
                        short frameIndex,
                        unsigned char mode,
                        const RectBounds *bounds,
                        const wchar_t *paletteName);
    virtual ~EPFImageControlPane();
    virtual void OnPaint();

private:
    wchar_t m_resourceName[16];
    short m_frameIndex;
    wchar_t m_paletteName[16];
};

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# EPFImageControlPane

## 2026-08-14 B003 Header Creation Route

- The complete class declaration moved from CPP to the new guarded `EPFImageControlPane.h`; CPP now includes that header and emits children. The H preserves the exact five-argument constructor, destructor, `OnPaint`, and three storage fields.
- This resolves the formerly absent header required by ChangePasswordDialogPane while retaining UID00004G/UID0000J2 ownership and `92/93` metadata.

## Status

- Confidence: strong for exact source methods, object layout, vtable identity, caller fanout, render behavior, compiler-glue disposition, and neighboring-range exclusion. Original private/method typedef spellings remain confidence-capped below 95.
- Likely source file: [UID:0000J2][EPFImageControlPane](by-file/EPFImageControlPane.md)
- Core address range: [UID:00011J][0x004991f0-0x004993a5.EPFImageControlPaneCore](by-memory/0x004991f0-0x004993a5.EPFImageControlPaneCore.md)
- Exact source children: [UID:0004JN][0x004991f0-0x004992a8.EPFImageControlPaneConstructor](by-memory/0x004991f0-0x004992a8.EPFImageControlPaneConstructor.md), [UID:0004JS][0x004992b0-0x0049930e.EPFImageControlPaneDestructor](by-memory/0x004992b0-0x0049930e.EPFImageControlPaneDestructor.md), and [UID:0004JW][0x00499310-0x004993a5.EPFImageControlPaneOnPaint](by-memory/0x00499310-0x004993a5.EPFImageControlPaneOnPaint.md).
- Non-contiguous compiler support: [UID:0003LN][0x0049af53-0x0049af69.EPFImageControlPaneAdjustorThunks](by-memory/0x0049af53-0x0049af69.EPFImageControlPaneAdjustorThunks.md) and [UID:0003LO][0x0049b1b0-0x0049b24f.EPFImageControlPaneScalarDeletingDestructor](by-memory/0x0049b1b0-0x0049b24f.EPFImageControlPaneScalarDeletingDestructor.md).
- Parent attachment: [UID:0000J2][EPFImageControlPane](by-file/EPFImageControlPane.md) now has a valid `NexusTK/ui/controls/` path and live IDA-backed module evidence.

## Score Rationale

- Completion `92`: the declaration, exact three-method split, tail layout, source order, vtable routes, caller/object-size evidence, callback behavior, and ABI-wrapper policy are now complete.
- Confidence `93`: class identity and binary behavior are exact. Descriptive source-facing names remain below 95 because stripped symbols do not prove original spellings.

## Class Purpose

`EPFImageControlPane` is a `ControlPane`-derived widget that paints one frame from a named EPF/EPD resource. It stores two fixed 16-wchar names and a signed frame index. Mode/control state remains inherited; no local flip member exists.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| Constructor | [UID:0004JN][0x004991f0-0x004992a8.EPFImageControlPaneConstructor](by-memory/0x004991f0-0x004992a8.EPFImageControlPaneConstructor.md) | Calls `ControlPane(8,bounds)`, copies resource/palette arrays, stores signed frame, clears inherited control flags, calls `SetMode`, and applies `BARAM.PAL` fallback. |
| Destructor | [UID:0004JS][0x004992b0-0x0049930e.EPFImageControlPaneDestructor](by-memory/0x004992b0-0x0049930e.EPFImageControlPaneDestructor.md) | Explicitly releases inherited surface buffers; compiler performs base teardown. |
| `OnPaint` | [UID:0004JW][0x00499310-0x004993a5.EPFImageControlPaneOnPaint](by-memory/0x00499310-0x004993a5.EPFImageControlPaneOnPaint.md) | Clears bounds with `FillRect`, looks up a borrowed frame, conditionally palette/blits valid pixels, and always builds the encoded mask. |
| Adjustor thunks | [UID:0003LN][0x0049af53-0x0049af69.EPFImageControlPaneAdjustorThunks](by-memory/0x0049af53-0x0049af69.EPFImageControlPaneAdjustorThunks.md) | Non-emitting `-0xa0/-0xa4` destructor adjustors. |
| Scalar deleting destructor | [UID:0003LO][0x0049b1b0-0x0049b24f.EPFImageControlPaneScalarDeletingDestructor](by-memory/0x0049b1b0-0x0049b24f.EPFImageControlPaneScalarDeletingDestructor.md) | Source-declared/generated-binary wrapper with covered-by marker at position 40. |

## Object Layout

| Offset | Member | Evidence |
| --- | --- | --- |
| inherited `+0x1c` | `m_surfaceContext` | Destructor release and OnPaint final mask build. |
| inherited `+0x44` | `m_bounds` | Slot-7 fill and slot-2 destination rectangle. |
| inherited `+0xff` | `m_controlFlags` | Constructor clears it before `SetMode`; no flip operation exists. |
| `+0x108` | `wchar_t m_resourceName[16]` | Extent-16 secure copy and frame lookup key. |
| `+0x128` | `short m_frameIndex` | Word store and signed promotion in lookup. |
| `+0x12a` | `wchar_t m_paletteName[16]` | Extent-16 secure copy and palette key. |

The declared tail ends at `0x14a`; normal alignment yields observed `sizeof(EPFImageControlPane)==0x14c`. Callers allocate 332 bytes. No explicit source pad is required.

## Evidence Notes

- Live IDA `py_eval` on 2026-06-04 used `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.
- IDA confirms exact local function bounds for the constructor, non-deleting destructor, render helper, adjustors, and scalar deleting destructor.
- The constructor has 120 call sites in 66 unique caller functions across dialog/control construction paths, matching reusable control ownership.
- Constructor, destructor, and scalar deleting destructor write EPF vtables `0x00618248`, `0x006182b0`, and `0x006182e0`.
- Vtable slots place scalar deleting destructor at `0x00618248 -> 0x0049b1b0`, `OnPaint` at primary `+0x44`, `0x0061828c -> 0x00499310`, and adjustors at `0x006182b0 -> 0x0049af53` / `0x006182e0 -> 0x0049af5e`.
- Constructor stores the EPF/EPD resource name at `this+0x108`, signed frame index at `this+0x128`, clears inherited control flags at `this+0xff`, and defaults palette to exact `BARAM.PAL` at `this+0x12a` when no palette is supplied.
- `OnPaint` initializes a local frame, sets draw color zero, calls slot 7 as `(this,this+0x44)` / `FillRect(&m_bounds)`, looks up the frame, conditionally resolves palette and calls `g_pfnBlitSprite`, then unconditionally calls `m_surfaceContext.BuildEncodedMask()`.
- Invalid frames skip only palette/blit work. The local frame borrows resource pointers and is not released.
- The ordinary destructor explicitly calls inherited `ReleaseBuffers`; scalar deletion and `-0xa0/-0xa4` adjustors are compiler lowering caused by the virtual declaration and ordinary body.
- The following in-band code at `0x004993b0+` installs `TargetOptionEditControlPane` vtables, so it remains excluded from this class.

## Dependencies

- `g_pEPFLib`: process-wide `ImageLib` singleton whose layout lookup methods are currently recovered as `ResourceLayoutTable`.
- `g_pPaletteLib`: palette lookup service.
- `dword_69B3FC`: shared slot-7 fill/presentation callback storage at `0x0069b3fc`; `OnPaint` passes `(this,this+0x44)`, source-facing `FillRect(&m_bounds)` rather than lock behavior.
- `g_pfnBlitSprite`: blits the selected EPF frame with the selected palette.

## Cross-References

- [UID:00006E][ImageLib](by-class/ImageLib.md)
- [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md)
- [UID:00004I][EPFTileContext](by-class/EPFTileContext.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)
- [UID:0000QW][g_pfnLockSurface](by-global/g_pfnLockSurface.md)
- [UID:00011J][0x004991f0-0x004993a5.EPFImageControlPaneCore](by-memory/0x004991f0-0x004993a5.EPFImageControlPaneCore.md)
- [0x0049b1b0-0x0049b24f.EPFImageControlPaneScalarDeletingDestructor](by-memory/0x0049b1b0-0x0049b24f.EPFImageControlPaneScalarDeletingDestructor.md)

## Changes

- 2026-07-13 B001 UID00011J accepted callback:
  - Raised `85/87 -> 92/93`, retained owner/emitter UID0000J2, and inserted the accepted complete class declaration.
  - Replaced the aggregate method list with exact UID0004JN/0004JS/0004JW links; documented 0x14c layout, inherited fields, OnPaint slot/behavior, scalar covered-by and adjustor non-emitting dispositions.
  - Historicalized local flip, `LoadAndRenderImage`, lock-surface, cached-image, and blank-until-95 assumptions while retaining their provenance in the method/evidence history below.
- 2026-06-12 C001 barrier repair:
  - Changed score from `84/86` to `85/87` and replaced the broad class range with compact core plus exact non-contiguous destructor children.
  - Evidence: IDA MCP reconfirmed the core successor boundary at `0x004993b0`, exact scalar destructor `0x0049b1b0-0x0049b24f`, and distinct FunctionObject successor at `0x0049b250`.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `72/80`.
  - Summary/evidence: control role, constructor/destructor/render/destructor-wrapper methods, EPF/palette/render callback dependencies, and thunk caveat are documented; remaining uncertainty is final member names and callback signature cleanup.
- 2026-06-04: Raised from `72/80` to `84/86`, marked reconstructable, and attached to [UID:0000J2][EPFImageControlPane](by-file/EPFImageControlPane.md).
  - Before: class metadata was unassigned, function ranges were start-only, parent path was blank, and vtable/caller evidence was sparse.
  - After: live IDA evidence records executable identity, exact bounds, 66-constructor-caller fanout, vtable stores/slots, render callback dependencies, default palette behavior, and TargetOption exclusion.
  - Reasoning: parent [UID:0000J2][EPFImageControlPane](by-file/EPFImageControlPane.md) now has a valid `NexusTK/ui/controls/` path and strong module evidence. Final C++ remains blank because source-facing field names and callback typedefs remain below the 95/95 threshold.
