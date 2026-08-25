*** UID:00006K | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "AlphaMaskSurface.h"
#include "EPFTileContext.h"
#include "SoftwareBlend16.h"

#include <math.h>
#include <new>
#include <stdlib.h>
#include <string.h>

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_RENDER_ALPHAMASKSURFACE_H
#define NEXUSTK_RENDER_ALPHAMASKSURFACE_H

#include "../ui/core/RectBounds.h"

struct EPFTileContext;

enum AlphaMaskBlendMode
{
    kAlphaMaskBlendCopy = 0,
    kAlphaMaskBlendAdd = 1,
    kAlphaMaskBlendSubtract = 2
};

class IntAlphaSurface
{
public:
    virtual ~IntAlphaSurface();
    virtual void ReleaseOwnedPixels();

    [[CHILDREN]]

private:
    RectBounds m_bounds;
    unsigned char *m_pixels;
    int m_width;
    int m_height;
    int m_stride;
    bool m_ownsBuffer;
    unsigned char m_padding[3];
};

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# IntAlphaSurface

## Accepted Current Class Resolution

`IntAlphaSurface` is the sole concrete 0x28-byte dynamic alpha-surface class. Unique RTTI `.?AVIntAlphaSurface@@`, a one-class hierarchy, vtable `0x006112ec`, all five vptr writes, the exact common layout, and the thirteen-method family close the former AlphaMaskSurface-versus-IntAlphaSurface split. The class is declared and implemented in [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md); [UID:0000K8][IntAlphaSurface](by-file/IntAlphaSurface.md) is a historical rejected file split.

The formal CPP block is the owning `AlphaMaskSurface.cpp` preamble. The formal H block supplies the guarded blend enum and class shell. [UID:0001TQ][AlphaSurfaceBufferView](by-type/by-struct/AlphaSurfaceBufferView.md) emits its separately guarded POD before this class fragment. Exact by-memory children occupy both `[[CHILDREN]]` markers in source order. Destructor then `ReleaseOwnedPixels` remain the first two virtual declarations so the compiler recreates slots `0x006112ec` and `0x006112f0`; the trailing null slots and RTTI/COL remain compiler-generated rather than handwritten arrays.

The object layout is vptr `+0x00`, `RectBounds m_bounds` `+0x04`, `m_pixels` `+0x14`, width `+0x18`, height `+0x1c`, stride `+0x20`, ownership byte `+0x24`, and three bytes tail padding. Owning constructors set `m_ownsBuffer`; clipped/full views clear it; release and destruction free only owned non-null pixels. Exact child pages document all source methods and compiler exclusions.

Scores `94/95` reflect complete source, ownership, layout, routing, compiler exclusions, and formal CPP/H. Remaining limits are inferred private spellings, zero-route liveness for the retained default constructor/no-op stub, no direct caller for `InitSurfaceView`, and no rebuilt-binary comparison.

## Historical Pre-Callback Status

The following sections preserve dated evidence. Statements that call this class related/provisional, route it through `IntAlphaSurface.cpp`, or place `InitSurfaceView` on a separate AlphaMaskSurface class are superseded by the accepted current class resolution above.

- Confidence: strong for destructor, buffer-release slot, vtable evidence, and live IDA boundaries; medium-high for render-surface placement; medium for final constructor/source split.
- Direct source file: [UID:0000K8][IntAlphaSurface](by-file/IntAlphaSurface.md), with possible merge into [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md) or a neighboring `render/Surface.cpp` after constructor/caller recovery.
- Address ranges: [UID:0000YP][0x00463270-0x004632b1.IntAlphaSurface](by-memory/0x00463270-0x004632b1.IntAlphaSurface.md), [UID:0004FR][0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels](by-memory/0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels.md)
- Type docs: [UID:0001TP][AlphaMaskSurfaceLayout](by-type/by-struct/AlphaMaskSurfaceLayout.md), [UID:0001XT][IntAlphaSurfaceVtable](by-type/by-vtable/IntAlphaSurfaceVtable.md)

## Class Purpose

`IntAlphaSurface` appears to be a related alpha/blending surface that owns a pixel buffer when an `ownsBuffer` flag is set. Live IDA evidence proves the source-ready ordinary destructor [UID:0000YP][0x00463270-0x004632b1.IntAlphaSurface](by-memory/0x00463270-0x004632b1.IntAlphaSurface.md), the source-ready buffer-release slot [UID:0004FR][0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels](by-memory/0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels.md), the active owning constructor/helper at `0x00462170`, and construction/use-site stores from the neighboring alpha-surface helper region. B009's 2026-06-28 implementation resolves the nearby view initializer [UID:0002NM][0x004623c0-0x00462514.InitAlphaSurfaceView](by-memory/0x004623c0-0x00462514.InitAlphaSurfaceView.md) as AlphaMaskSurface-owned source that initializes a caller-supplied `IntAlphaSurface *` destination; it is not a direct `IntAlphaSurface` method.

## Observed State

```text
0x00  vtable
0x04  RectBounds bounds
0x14  uint8_t* pixels
0x18  int width
0x1c  int height
0x20  int stride
0x24  uint8_t ownsBuffer
```

The destructor frees `m_pixels` when `m_ownsBuffer` is true, clears the pointer, and optionally deletes object storage through the compiler scalar-delete wrapper. Slot 1 at [UID:0004FR][0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels](by-memory/0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels.md) performs the same owned-buffer release without deleting object storage; [UID:0000TX][AlphaSurfaceReleaseOwnedPixels_00462260](by-item/AlphaSurfaceReleaseOwnedPixels_00462260.md) is now an alias/support page.

## Vtable Evidence

IDA identifies `off_6112EC` as the `IntAlphaSurface` vtable. Slot 0 points to `0x00463270`, and slot 1 points to `0x00462260`. The vtable has data references from raw constructor-shaped bytes at `0x0046212c`, from the active constructor at `0x0046217b`, from the EH-only [UID:0000YM][0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup](by-memory/0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup.md) at `0x00462237`, from the [UID:0002NM][0x004623c0-0x00462514.InitAlphaSurfaceView](by-memory/0x004623c0-0x00462514.InitAlphaSurfaceView.md) construction/use-site store at `0x00462415`, and from the destructor reset at `0x0046327a`. IDA MCP recheck on 2026-05-25 and 2026-05-26 reports no direct code callers for either virtual target, which is expected for vtable-dispatched teardown.

2026-06-08 B001 ownership follow-up confirms the RTTI chain directly before the vtable: `0x006112e8 -> 0x00641e9c -> 0x006744ec`, with complete object locator `??_R4IntAlphaSurface@@6B@`, type descriptor `??_R0?AVIntAlphaSurface@@@8`, and class hierarchy descriptor `??_R3IntAlphaSurface@@8`. This makes [UID:0001XT][IntAlphaSurfaceVtable](by-type/by-vtable/IntAlphaSurfaceVtable.md) a direct class/type child of this page even though the physical source file may still be colocated with `AlphaMaskSurface`.

2026-05-26 IDA MCP `py_eval` confirms the first four vtable dwords at `0x006112ec` are `0x00463270`, `0x00462260`, `0x00000000`, and `0x00000000`.

2026-05-30 IDA MCP recheck confirms the destructor and release slot both test ownership byte `+0x24`, free pixel pointer `+0x14`, and clear the pointer. `xrefs_to 0x00463270` and `xrefs_to 0x00462260` remain vtable-only, and `callers` reports no direct code callers for either function.

2026-06-04 live IDA MCP recheck confirms:

- `0x00462120` still has no function object and no xrefs, but raw disassembly writes `off_6112EC`, clears `+0x14/+0x18/+0x1c/+0x20`, sets ownership byte `+0x24`, and calls `sub_4B7C50`.
- `sub_462170` is a real `0x00462170-0x00462227` function with four callers at `0x004df9a9`, `0x0050442c`, `0x005a288d`, and `0x005a2b8e`; decompilation writes `off_6112EC`, initializes bounds, calls the release vtable slot before reallocating, and stores width/height/stride plus a `width * height` allocation.
- `sub_4623C0` is `0x004623c0-0x00462514` and owns tail chunks `0x00462230-0x00462258` and `0x005fa580-0x005fa5be`; the only observed xref to the `0x00462230` cleanup chunk is the EH funclet xref at `0x005fa593`.
- The first four vtable dwords at `0x006112ec` remain `0x00463270`, `0x00462260`, `0x00000000`, and `0x00000000`, with stores at `0x0046212c`, `0x0046217b`, `0x00462237`, `0x00462415`, and `0x0046327a`.

`0x004632c0` is explicitly excluded from this class. It uses vtable `0x00612574`, is reached from application global initializer/atexit cleanup paths, and should be tracked as application error-state cleanup rather than `IntAlphaSurface`.

2026-06-07 Agent-A002 IDA MCP recheck confirms the same source-family shape:

- `0x00462120` still has no IDA function object and no xrefs; it remains bounded by previous function `0x00461fe0-0x00462114` and next function `0x00462170-0x00462227`.
- `0x00462170-0x00462227` is still the active constructor/helper, with four direct code xrefs from three unique caller functions (`0x004df7e0`, `0x00504110`, and `0x005a2530`) and calls to `0x004b7c50` plus the allocation helper at `0x005c7790`.
- `0x00462260-0x00462282` is still vtable slot 1 with only the `0x006112f0` vtable-data xref; `0x00463270-0x004632b1` is still the scalar deleting destructor with only the `0x006112ec` vtable-data xref.
- `off_6112EC` at `0x006112ec` still contains `0x00463270`, `0x00462260`, `0x00000000`, and `0x00000000`; xrefs to the vtable base remain `0x0046212c`, `0x0046217b`, `0x00462237`, `0x00462415`, and `0x0046327a`.
- `0x004632c0-0x0046330b` remains a separate application error-state cleanup function and is not part of this class.
- 2026-07-03 B006 current MCP session `b010_00032w_20260703` reconfirmed the destructor and release slot at report-level detail: `0x00463270` is size `0x41` / 65 and `0x00462260` is size `0x22` / 34 (both Verified with `int_convert.py`); pointer patterns occur only at vtable slots `0x006112ec` and `0x006112f0`; vtable base `0x006112ec` still has the raw constructor, active constructor, EH cleanup, view construction/use-site, and destructor-reset refs; field names are standardized to `m_pixels` and `m_ownsBuffer`; and `0x004632c0` remains separate on vtable `0x00612574`.

## Assignment Gate

`CANONICAL_OWNER` and `EMITTER_UIDS` are set to [UID:0000K8][IntAlphaSurface](by-file/IntAlphaSurface.md). The class now clears `88/91`, the direct file parent is refreshed, and the relationship is direct render-surface ownership rather than a consumer attachment. The exact destructor child [UID:0000YP][0x00463270-0x004632b1.IntAlphaSurface](by-memory/0x00463270-0x004632b1.IntAlphaSurface.md) and release helper child [UID:0004FR][0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels](by-memory/0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels.md) attach to this class.

B001/supervisor vtable-owner application: [UID:0001XT][IntAlphaSurfaceVtable](by-type/by-vtable/IntAlphaSurfaceVtable.md) now attaches to this class. The decisive direct-owner signal is the vtable RTTI naming `IntAlphaSurface`; the `AlphaMaskSurface` constructor/helper and view-initializer stores remain physical source-colocation evidence, not a stronger class/type ownership signal than the RTTI and virtual slot targets.

## Cross-References

- [UID:0000K8][IntAlphaSurface](by-file/IntAlphaSurface.md)
- [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md)
- [UID:0000YM][0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup](by-memory/0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup.md)
- [UID:0004FR][0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels](by-memory/0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels.md)
- [UID:0000TX][AlphaSurfaceReleaseOwnedPixels_00462260](by-item/AlphaSurfaceReleaseOwnedPixels_00462260.md)
- [UID:0000UU][InitAlphaSurfaceView_004623C0](by-item/InitAlphaSurfaceView_004623C0.md)
- [UID:0000YP][0x00463270-0x004632b1.IntAlphaSurface](by-memory/0x00463270-0x004632b1.IntAlphaSurface.md)
- [UID:0001TP][AlphaMaskSurfaceLayout](by-type/by-struct/AlphaMaskSurfaceLayout.md)
- [UID:0001XT][IntAlphaSurfaceVtable](by-type/by-vtable/IntAlphaSurfaceVtable.md)
- [UID:0000YQ][0x004632c0-0x0046330b.ApplicationErrorStateCleanup](by-memory/0x004632c0-0x0046330b.ApplicationErrorStateCleanup.md)

## Changes

- 2026-07-03 B006 Gate 1 implementation:
  - Raised completion/confidence from `85/89` to `88/91`.
  - Summary/evidence: [UID:0000YP][0x00463270-0x004632b1.IntAlphaSurface](by-memory/0x00463270-0x004632b1.IntAlphaSurface.md) now carries formal destructor C++; [UID:0004FR][0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels](by-memory/0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels.md) now carries formal release-helper C++; [UID:0000TX][AlphaSurfaceReleaseOwnedPixels_00462260](by-item/AlphaSurfaceReleaseOwnedPixels_00462260.md) is alias/support. Current MCP session `b010_00032w_20260703` reconfirmed exact ranges, bytes, vtable-only reachability, owned-buffer offsets, scalar-delete wrapper distinction, raw constructor/EH cleanup caveats, and `0x004632c0` exclusion.
- 2026-06-28 B009 [UID:0002NM][0x004623c0-0x00462514.InitAlphaSurfaceView](by-memory/0x004623c0-0x00462514.InitAlphaSurfaceView.md) support refresh:
  - Score and metadata unchanged.
  - Summary/evidence: [UID:0002NM][0x004623c0-0x00462514.InitAlphaSurfaceView](by-memory/0x004623c0-0x00462514.InitAlphaSurfaceView.md) is recorded as external AlphaMaskSurface-owned construction/use-site evidence for this class layout/vtable, not a direct method. MCP session `b001_000241_20260627` proves `ECX` is the source `AlphaMaskSurface` object and `arg_0` is the destination `IntAlphaSurface *`.
- 2026-05-30: Raised completion/confidence from `0/0` to `76/84`. Previously the class page had recovered layout/vtable notes but no score; it now records the current IDA MCP vtable-only caller/xref recheck while keeping constructor and source-family recovery open.
- 2026-05-31: Marked `RECONSTRUCTABLE:TRUE`.
  - Before: validator metadata left the reconstructable field blank.
  - After: the page is explicitly reconstructable, but parent attachment and C++ autogen code remain blank.
  - Summary/evidence: IDA MCP confirms the `off_6112EC` vtable, destructor/release methods, owned-pixel offsets, and alpha-surface constructor/helper stores. The final source-file split with `AlphaMaskSurface` is still open, so only the reconstructable classification was changed.
- 2026-06-04: Raised completion/confidence from `76/84` to `84/88`.
  - Before: the page still treated the class as mostly destructor-only and did not record the current IDA tail-chunk ownership for the cleanup block.
  - After: the class page records the active owning constructor/helper, current vtable dwords and xrefs, the raw/no-xref default-constructor caveat, and the EH-only cleanup chunk under `sub_4623C0`.
  - Summary/evidence: live IDA MCP proves the destructor/release slot behavior, vtable-only virtual targets, active constructor callers, `0x00462120` raw status, and `0x00462230` EH tail-chunk ownership. The class remains below final C++ reconstruction confidence because the original source split with `AlphaMaskSurface` is still unresolved.
- 2026-06-07 Agent-A002 Batch 091 parent-gate pass:
  - Before: `84/88`, reconstructable but unassigned because this class and the direct file parent were just below the corrected gate.
  - Changed to: `85/89` and `AUTOGEN_PARENT_UID:0000K8`.
  - Summary/evidence: live IDA MCP reconfirmed the raw `0x00462120` no-function caveat, active constructor/helper callers, release/destructor vtable-only dispatch, exact `off_6112EC` slot values and xrefs, and the `0x004632c0` exclusion. The source split is still provisional, so this remains below final-source reconstruction quality.
- 2026-06-08 A005 Batch124:
  - Score and parent metadata unchanged.
  - Added the explicit vtable-owner audit for [UID:0001XT][IntAlphaSurfaceVtable](by-type/by-vtable/IntAlphaSurfaceVtable.md). Live IDA reconfirmed the vtable slots and stores; at that checkpoint the declaration owner was left unresolved pending the later B001 RTTI pass.
- 2026-06-08 B001/supervisor RTTI ownership application:
  - Score and parent metadata unchanged.
  - Changed the [UID:0001XT][IntAlphaSurfaceVtable](by-type/by-vtable/IntAlphaSurfaceVtable.md) audit from ownership-unknown to direct class ownership. B001 confirmed the RTTI chain `0x006112e8 -> 0x00641e9c -> 0x006744ec`, naming `IntAlphaSurface` through the complete object locator and type descriptor. The remaining uncertainty is physical source-file colocation with `AlphaMaskSurface`, not class ownership of the vtable artifact.
