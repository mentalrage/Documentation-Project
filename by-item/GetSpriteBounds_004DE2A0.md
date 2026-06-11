*** UID:0000UR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000IY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# GetSpriteBounds 0x004de2a0

## Status

- Confidence: strong for effect-bounds behavior, medium for final owner.
- Likely owner file: [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md)
- Autogen parent: [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md)
- Memory range: `0x004de2a0-0x004de3d2`
- Entity kind: source-owned free helper near the effect image library; no `EffectObjImageLib *this` use is visible in the current decompile.

## Function Role

`GetSpriteBounds` resolves one effect atlas frame and writes centered bounds. In modern mode it formats `EFFECT%d.EPF` using `spriteGroup / 200` and frame `spriteGroup % 200`; in legacy mode it uses `EFFECT.EPD` and the raw `spriteGroup`. It then offsets the resolved bounds by half the global [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md).

The function calls the central EPF layout library through `g_pEPFLib` / `dword_67A744`, so it is an effect-specific consumer of the shared image library rather than a raw DAT parser.

This helper is source-owned with [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md), but it does not require the `EffectObjImageLib` instance pointer. Runtime callers reach it from `EffectObjectPane` bounds/setup paths after reading [UID:0000QT][g_pEffectObjImageLib](by-global/g_pEffectObjImageLib.md).

The decompiled signature currently has five stdcall parameters, but only the first sprite-group argument and the output rectangle pointer are used. Treat the middle arguments as unresolved caller-convention or callback-shape residue until the `EffectObjectPane` callers are fully rewritten.

## Ownership Decision

Keep near `EffectObjImageLib` because the resource family is effect-specific and the callers are effect render paths. If a later pass finds a broader sprite-bounds helper module, this can be moved there with a cross-reference.

## Score Rationale

- Completion is `82` because the page now records exact half-open range evidence, caller set, mode split, resource-layout call shape, negative empty-rectangle behavior, tile-centering globals, callee inventory, and unresolved signature caveat.
- Confidence is `88` because the live decompile, caller/callee inventory, sibling function boundary, and global/type cross-references agree with the effect image-library placement. Confidence remains below final audit because the two effect-object callers and final helper signature still need source-level rewrite review.

## Evidence

- IDA MCP on 2026-06-06 reports `sub_4DE2A0` as `0x004de2a0-0x004de3d2`, size `0x132`; `0x004de3d2` is not a function, and the next function is [UID:0002HA][0x004de3e0-0x004de420.EffectObjImageLibGetEffectInfo](by-memory/0x004de3e0-0x004de420.EffectObjImageLibGetEffectInfo.md).
- IDA xrefs show exactly two code callers, `0x00538903` in `sub_5388C0` and `0x00538994` in `sub_538960`, matching effect-object bounds/setup paths.
- Hex-Rays shows the modern-mode branch testing [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / `byte_66DA97 == 1`, formatting `EFFECT%d.EPF` with `spriteGroup / 200`, and passing frame `spriteGroup % 200` to [UID:0002KS][0x004d0530-0x004d059b.ResourceLayoutTableGetEntryRect](by-memory/0x004d0530-0x004d059b.ResourceLayoutTableGetEntryRect.md).
- The legacy branch calls the same resource-layout rectangle lookup with literal `EFFECT.EPD` and the raw signed 16-bit `spriteGroup`.
- Both mode branches treat negative `spriteGroup` as an empty rectangle through `InitRectBounds` (`0x004b7c50`) and otherwise center the resolved rectangle with the same `0x004b7e10` rectangle-offset helper used by [UID:0000UQ][GetItemGlyphBounds_004DF460](by-item/GetItemGlyphBounds_004DF460.md).
- IDA data refs in this function hit [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) / `dword_67A744`, [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md) as `word_66DAA0 / 2` and `word_66DA9C / 2`, and [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) for the modern/legacy asset branch.

## Callee Inventory

IDA MCP `callees(0x004de2a0)` reports:

| Callee | Current interpretation |
| --- | --- |
| `sub_41B9B0` | Builds the numbered `EFFECT%d.EPF` wide string in modern EPF mode. |
| [UID:0002KS][0x004d0530-0x004d059b.ResourceLayoutTableGetEntryRect](by-memory/0x004d0530-0x004d059b.ResourceLayoutTableGetEntryRect.md) / `0x004d0530` | Resolves the selected EPF/EPD frame rectangle through [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md). |
| `sub_4B7C50` | Initializes an empty rectangle when `spriteGroup` is negative. |
| `sub_4B7E10` | Offsets the returned rectangle by half a map tile. |
| `@__security_check_cookie@4` | Compiler security-cookie epilogue from the local formatted-path buffer. |

## Cross-References

- [UID:00004A][EffectObjImageLib](by-class/EffectObjImageLib.md)
- [UID:0001U9][EffectObjImageLibLayout](by-type/by-struct/EffectObjImageLibLayout.md)
- [UID:0000QT][g_pEffectObjImageLib](by-global/g_pEffectObjImageLib.md)
- [UID:00006E][ImageLib](by-class/ImageLib.md)
- [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md)
- [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md)
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md)
- [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md)
- [UID:0002KS][0x004d0530-0x004d059b.ResourceLayoutTableGetEntryRect](by-memory/0x004d0530-0x004d059b.ResourceLayoutTableGetEntryRect.md)

## Changes

- 2026-06-06 A002 live IDA evidence pass:
  - Before: the page was `78/86` and had only summary-level Hex-Rays evidence for the mode split and centering behavior.
  - After: raised to `82/88`, added entity-kind/signature caveats, refreshed live caller/callee evidence, and linked the exact resource-layout rectangle lookup and EPF-mode globals.
  - Evidence: IDA MCP `lookup_funcs`, `callers`, `callees`, and decompilation on 2026-06-06 confirm the `0x132`-byte helper, two effect-object callers, `g_useEpfAssets` branch, `EFFECT%d.EPF`/`EFFECT.EPD` lookup, negative empty-rectangle path, `g_pEPFLib` access, and tile-midpoint offset through `word_66DA9C`/`word_66DAA0`. Final C++ remains blank below the final-source gate.

- 2026-06-05: Reconstructable metadata changed from blank to `TRUE` and attached to [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md).
  - Before: the effect bounds helper was documented but unclassified in autogen coverage.
  - After: it is marked as NexusTK-owned effect-image helper source under the validated EffectObjImageLib file root; C++ remains blank because final helper/file split and resource table field names are not at the 95/95 final-code bar.
  - Evidence: live IDA MCP confirms `sub_4DE2A0` at `0x004de2a0`, size `0x132`, with two direct effect-object callers and callees to resource-layout, rectangle initialization, and rectangle offset helpers.

- Before: the page had `COMPLETION:0` and `CONFIDENCE:0`, cited non-authoritative path evidence, and used the old inclusive range spelling.
- Changed to: `COMPLETION:78` and `CONFIDENCE:86`, IDA-backed bounds, caller list, exact modern/legacy atlas behavior, and negative-sprite empty-rectangle behavior.
- Summary/evidence: IDA MCP on 2026-05-30 confirms `0x004de2a0-0x004de3d2`, two effect-object callers, calls to `0x004d0530`, `0x004b7e10`, and `0x004b7c50`, and the `EFFECT%d.EPF`/`EFFECT.EPD` mode branch.
