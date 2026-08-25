*** UID:0001TQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// AlphaSurfaceBufferView is declared in AlphaMaskSurface.h.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_RENDER_ALPHASURFACEBUFFERVIEW_DEFINED
#define NEXUSTK_RENDER_ALPHASURFACEBUFFERVIEW_DEFINED

struct AlphaSurfaceBufferView
{
    unsigned char *pixels;
    int width;
    int height;
    int stride;
    bool ownsBuffer;
    unsigned char padding[3];
};

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# AlphaSurfaceBufferView

## Accepted Header Composition

This exact 0x14-byte POD emits at file position 1 in [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md), before [UID:00006K][IntAlphaSurface](by-class/IntAlphaSurface.md). Its dedicated `NEXUSTK_RENDER_ALPHASURFACEBUFFERVIEW_DEFINED` guard is required because it is an independently emitted pre-class fragment; the owning `NEXUSTK_RENDER_ALPHAMASKSURFACE_H` guard separately encloses the enum and class. The non-empty CPP comment records the header-only source disposition without creating an empty emitter marker.

The fields exactly mirror object bytes `+0x14..+0x27`: pointer, width, height, stride, ownership byte, and three explicit padding bytes. [UID:00054Y][0x00462300-0x00462317.IntAlphaSurfaceGetBufferInfo](by-memory/0x00462300-0x00462317.IntAlphaSurfaceGetBufferInfo.md) copies all bytes; [UID:00054Z][0x00462320-0x004623b5.IntAlphaSurfaceGetClippedBufferInfo](by-memory/0x00462320-0x004623b5.IntAlphaSurfaceGetClippedBufferInfo.md) builds non-owning clipped views.

## Status

- Confidence: very strong for exact size, offsets, field widths, byte ownership flag, explicit padding, producer/consumer set, and source role; exact original lexical spelling remains inferred.
- Accepted owner header: `render/AlphaMaskSurface.h`, emitted through [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md) at file position `1`.
- Entity kind: POD buffer-view record.
- Primary memory docs: [UID:0000YL][0x00462170-0x00462e03.AlphaMaskSurface](by-memory/0x00462170-0x00462e03.AlphaMaskSurface.md)
- Parent attachment: canonical owner and emitter [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md), with current score `94/95` and exact source position `1`.
- Reconstructable: true as a source-level POD/view declaration. Formal CPP contains the non-empty header-disposition comment, while formal H carries the exact guarded 0x14-byte record.

## Layout

`AlphaSurfaceBufferView` is the 0x14-byte payload copied from an alpha surface object or built as a clipped non-owning view.

| Offset | Field | Evidence |
| --- | --- | --- |
| `0x00` | `unsigned char *pixels` | `GetBufferInfo` copies source `+0x14`; clipped builder writes adjusted pointer. |
| `0x04` | `int width` | Width copied from source or clipped rectangle. |
| `0x08` | `int height` | Height copied from source or clipped rectangle. |
| `0x0c` | `int stride` | Source stride copied so clipped views keep row pitch. |
| `0x10` | `bool ownsBuffer` | Source ownership byte is copied by `GetBufferInfo`; clipped builders clear byte `+0x10` to mark a non-owning view. |
| `0x11` | `unsigned char padding[3]` | `GetBufferInfo` copies the containing dword while independent builders write/clear only the ownership byte; explicit padding preserves the exact 0x14 size without inventing flag bits. |

## Evidence

- 2026-05-26 IDA MCP decompilation of `0x00462300` copies an OWORD from alpha-surface object offset `+0x14` to output offset `+0x00`, then copies the dword at object offset `+0x24` to output offset `+0x10`.
- 2026-05-26 IDA MCP decompilation of [UID:0000U3][BuildClippedAlphaSurfaceView_00462320](by-item/BuildClippedAlphaSurfaceView_00462320.md) writes adjusted pixel pointer, clipped width/height, preserved stride, and clears byte `+0x10`.
- `0x00462320` has a live IDA code xref from `StaticObjImageLib` at `0x004dd66a`, so this record is reconstructable render infrastructure rather than dead local scratch.
- 2026-05-30 IDA MCP recheck of [UID:0000U3][BuildClippedAlphaSurfaceView_00462320](by-item/BuildClippedAlphaSurfaceView_00462320.md) confirms the output writes: pixel pointer at `+0x00`, clipped width at `+0x04`, clipped height at `+0x08`, stride at `+0x0c`, and non-owning byte clear at `+0x10`.

## Cross-References

- [UID:0002TH][0x004c3cf0-0x004c3e93.SoftwareRenderRgb565AlphaLookupBlitCallback](by-memory/0x004c3cf0-0x004c3e93.SoftwareRenderRgb565AlphaLookupBlitCallback.md)
- [UID:0002TD][0x004bdf40-0x004be0db.SoftwareRenderCompatAlphaLookupBlitCallback](by-memory/0x004bdf40-0x004be0db.SoftwareRenderCompatAlphaLookupBlitCallback.md)

- [UID:0001TP][AlphaMaskSurfaceLayout](by-type/by-struct/AlphaMaskSurfaceLayout.md)
- [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md)
- [UID:00000C][AlphaMaskSurface](by-class/AlphaMaskSurface.md)
- [UID:0000YL][0x00462170-0x00462e03.AlphaMaskSurface](by-memory/0x00462170-0x00462e03.AlphaMaskSurface.md)
- [UID:0000U3][BuildClippedAlphaSurfaceView_00462320](by-item/BuildClippedAlphaSurfaceView_00462320.md)
- [UID:0000UU][InitAlphaSurfaceView_004623C0](by-item/InitAlphaSurfaceView_004623C0.md)

## Changes

- 2026-08-17 B005 UID0000HF Gate 2A reconciliation:
  - Replaced the active pre-callback `90/93`, uncertain-header, and blank-CPP statements with the accepted `94/95`, exact `AlphaMaskSurface.h`, owner/emitter [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md), position `1`, non-empty CPP comment, and exact H disposition.
  - Preserved all field-layout, producer/consumer, and dated score-history evidence below.

- 2026-08-04 B010 UID0002TH alpha-view closure:
  - Raised `86/90` to `90/93` and populated exact formal H for the 0x14-byte POD.
  - Resolved the old dword-sized `ownsBufferOrFlags` placeholder to one-byte `bool ownsBuffer` plus three explicit padding bytes, preserving all observed copy and non-owning-builder writes.
  - Added both Surface slot-5 providers as consumers. `AlphaMaskSurface::GetBufferInfo` at `0x00462300` copies object `+0x14..+0x27` into this record; compat `0x004bdf40` and RGB565 `0x004c3cf0` are its exact two callers.
  - Original lexical spelling remains inferred, but raw stack-fragment arrays and an invented multi-bit flag field are rejected because independent producer/consumer evidence proves the five source fields.

- 2026-05-30: Raised completion/confidence from `0/0` to `86/90`. Previously this page documented the layout but had no score; it now records the current IDA MCP clipped-view recheck and concrete output offsets.
- 2026-06-04: Marked `RECONSTRUCTABLE:TRUE` without changing scores.
  - Reasoning: IDA-backed `GetBufferInfo` and clipped-view writes prove a real 0x14-byte POD buffer-view record; final original type name and owner header remain below the parent-attachment threshold.
- 2026-06-06: Set `AUTOGEN_PARENT_UID` to [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md) without changing scores.
  - Before: the POD view page had strong IDA-backed field evidence but no parent.
  - After: the view record is attached to the file-level alpha surface module because it is a helper declaration for the surface/blitter cluster rather than a standalone class.
  - Evidence: the file page is scored `82/89`, links this view layout, and owns the `GetBufferInfo`/clipped-view helper family that constructs the 0x14-byte record.
