*** UID:0000UR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# GetSpriteBounds 0x004de2a0

## Status

- Confidence: strong for effect-bounds behavior, medium for final owner.
- Likely owner file: [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md)
- Memory range: `0x004de2a0-0x004de3d2`

## Function Role

`GetSpriteBounds` resolves one effect atlas frame and writes centered bounds. In modern mode it formats `EFFECT%d.EPF` using `spriteGroup / 200` and frame `spriteGroup % 200`; in legacy mode it uses `EFFECT.EPD` and the raw `spriteGroup`. It then offsets the resolved bounds by half the global [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md).

The function calls the central EPF layout library through `g_pEPFLib` / `dword_67A744`, so it is an effect-specific consumer of the shared image library rather than a raw DAT parser.

This helper is source-owned with [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md), but it does not require the `EffectObjImageLib` instance pointer. Runtime callers reach it from `EffectObjectPane` bounds/setup paths after reading [UID:0000QT][g_pEffectObjImageLib](by-global/g_pEffectObjImageLib.md).

## Ownership Decision

Keep near `EffectObjImageLib` because the resource family is effect-specific and the callers are effect render paths. If a later pass finds a broader sprite-bounds helper module, this can be moved there with a cross-reference.

## Evidence

- IDA MCP on 2026-05-30 reports `sub_4DE2A0` as `0x004de2a0-0x004de3d2`, size `306`.
- IDA xrefs show exactly two code callers, `0x00538903` in `sub_5388C0` and `0x00538994` in `sub_538960`, matching effect-object bounds/setup paths.
- Hex-Rays shows modern-mode `EFFECT%d.EPF` formatting with `spriteGroup / 200`, frame `spriteGroup % 200`, legacy-mode `EFFECT.EPD` lookup with raw `spriteGroup`, and negative `spriteGroup` returning an empty rectangle through `0x004b7c50`.
- The helper calls [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md) entry lookup at `0x004de305` and `0x004de377`, then applies the same tile-midpoint centering policy as [UID:0000UQ][GetItemGlyphBounds_004DF460](by-item/GetItemGlyphBounds_004DF460.md) through `0x004b7e10`.
- IDA data refs in this function hit `word_66DAA0` at `0x004de30a` / `0x004de37c` and `word_66DA9C` at `0x004de317` / `0x004de389`.

## Cross-References

- [UID:00004A][EffectObjImageLib](by-class/EffectObjImageLib.md)
- [UID:0001U9][EffectObjImageLibLayout](by-type/by-struct/EffectObjImageLibLayout.md)
- [UID:0000QT][g_pEffectObjImageLib](by-global/g_pEffectObjImageLib.md)
- [UID:00006E][ImageLib](by-class/ImageLib.md)
- [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md)
- [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md)

## Changes

- Before: the page had `COMPLETION:0` and `CONFIDENCE:0`, cited a recovered generated file path, and used the old inclusive range spelling.
- Changed to: `COMPLETION:78` and `CONFIDENCE:86`, IDA-backed bounds, caller list, exact modern/legacy atlas behavior, and negative-sprite empty-rectangle behavior.
- Summary/evidence: IDA MCP on 2026-05-30 confirms `0x004de2a0-0x004de3d2`, two effect-object callers, calls to `0x004d0530`, `0x004b7e10`, and `0x004b7c50`, and the `EFFECT%d.EPF`/`EFFECT.EPD` mode branch.
