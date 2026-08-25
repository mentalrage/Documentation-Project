*** UID:0000UR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
RectBounds *GetSpriteBounds(
    int frameResourceId,
    int timerDelayAndRenderArg,
    float renderScalar,
    int lightingAndRenderArg,
    RectBounds *outBounds)
{
    (void)timerDelayAndRenderArg;
    (void)renderScalar;
    (void)lightingAndRenderArg;

    if (frameResourceId < 0)
    {
        InitRectBounds(outBounds, 0, 0, 0, 0);
        return outBounds;
    }

    if (g_useEpfAssets == 1)
    {
        wchar_t archiveName[20];
        swprintf(archiveName, 20, L"EFFECT%d.EPF", frameResourceId / 200);
        ResourceLayoutTableGetEntryRect(
            g_pEPFLib,
            archiveName,
            static_cast<short>(frameResourceId % 200),
            outBounds);
    }
    else
    {
        ResourceLayoutTableGetEntryRect(
            g_pEPFLib,
            L"EFFECT.EPD",
            static_cast<short>(frameResourceId),
            outBounds);
    }

    OffsetRectBounds(outBounds, g_mapTilePixelWidth / 2, g_mapTilePixelHeight / 2);
    return outBounds;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# GetSpriteBounds 0x004de2a0

## Status

- Confidence: strong for effect-bounds behavior and EffectObjImageLib routing; medium for final source signature and helper/file split.
- Likely owner file: [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md)
- Owner/emitter route: [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md)
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

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 88 | The page records exact half-open range evidence, endpoint/padding checks, two effect-object callers, modern/legacy mode split, resource-layout call shape, negative empty-rectangle behavior, tile-centering globals, callee inventory, EffectObjImageLib owner/emitter routing, unresolved signature caveat, and formal first-draft C++. |
| Confidence | 91 | Live IDA MCP decompile, xrefs, callee inventory, sibling function boundary, and global/type cross-references agree with effect image-library placement. Confidence remains below final-source level because the helper signature and exact source-file split still need rewrite-quality names. |

## Evidence

- IDA MCP on 2026-06-06 reports `sub_4DE2A0` as `0x004de2a0-0x004de3d2`, size `0x132`; `0x004de3d2` is not a function, and the next function is [UID:0002HA][0x004de3e0-0x004de420.EffectObjImageLibGetEffectInfo](by-memory/0x004de3e0-0x004de420.EffectObjImageLibGetEffectInfo.md).
- IDA xrefs show exactly two code callers, `0x00538903` in `sub_5388C0` and `0x00538994` in `sub_538960`, matching effect-object bounds/setup paths.
- Hex-Rays shows the modern-mode branch testing [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / `byte_66DA97 == 1`, formatting `EFFECT%d.EPF` with `spriteGroup / 200`, and passing frame `spriteGroup % 200` to [UID:0002KS][0x004d0530-0x004d059b.ResourceLayoutTableGetEntryRect](by-memory/0x004d0530-0x004d059b.ResourceLayoutTableGetEntryRect.md).
- The legacy branch calls the same resource-layout rectangle lookup with literal `EFFECT.EPD` and the raw signed 16-bit `spriteGroup`.
- Both mode branches treat negative `spriteGroup` as an empty rectangle through `InitRectBounds` (`0x004b7c50`) and otherwise center the resolved rectangle with the same `0x004b7e10` rectangle-offset helper used by [UID:0000UQ][0x004df460-0x004df4f9.GetItemGlyphBounds](by-memory/0x004df460-0x004df4f9.GetItemGlyphBounds.md).
- IDA data refs in this function hit [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) / `dword_67A744`, [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md) as `word_66DAA0 / 2` and `word_66DA9C / 2`, and [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) for the modern/legacy asset branch.

2026-06-14 live IDA MCP session `a001_goal2_class_batch` reconfirmed:

- `lookup_funcs` resolves `0x004de2a0` to `sub_4DE2A0`, size `0x132`, while `0x004de3d2` is not a function and the next modeled sibling remains `0x004de3e0`. Decimal size `306 == 0x132` was verified with `int_convert.py`.
- `analyze_function 0x004de2a0` reports two callers, five callees, and a one-block/low-complexity helper; `xrefs_to 0x004de2a0` reports the two direct code refs at `0x00538903` and `0x00538994`.
- Targeted decompilation reconfirmed the `byte_66DA97 == 1` modern branch, negative-id empty rectangle through `0x004b7c50`, `EFFECT%d.EPF` formatting, `spriteGroup / 200` archive selection and `spriteGroup % 200` frame selection (`200 == 0xc8`, verified with `int_convert.py`), legacy `EFFECT.EPD` lookup, and final rectangle offset through `0x004b7e10`.
- `get_bytes 0x004de3d2 size 14` returned fourteen `0xcc` bytes before the next function; `14 == 0x0e` was verified with `int_convert.py`.
- B008's 2026-06-30 callback attaches formal first-draft C++. The exact source signature, unused-parameter/calling-convention explanation, resource selector names, and helper/file split remain confidence caps rather than marker-only blockers.

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

- 2026-06-30 B008 empty-emitter implementation callback:
  - Before: `85/90`, formal C++ blank with unresolved-signature caveats.
  - After: `88/91`, formal first-draft C++ attached under [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md).
  - Summary/evidence: accepted report used current MCP session `supervisor_resume_20260629`, server-health call id `3`, and score-blocker rework evidence to preserve the exact helper range, two `EffectObjectPane` callers, negative-frame empty rectangle path, `g_useEpfAssets` modern branch, `EFFECT%d.EPF` shard/frame calculation with divisor `200`, legacy `EFFECT.EPD` path, `g_pEPFLib` rectangle lookup, tile-centering offset, and rejected relocation to raw EPF/DAT or effect-pane owners.

- 2026-06-06 A002 live IDA evidence pass:
  - Before: the page was `78/86` and had only summary-level Hex-Rays evidence for the mode split and centering behavior.
  - After: raised to `82/88`, added entity-kind/signature caveats, refreshed live caller/callee evidence, and linked the exact resource-layout rectangle lookup and EPF-mode globals.
  - Evidence: IDA MCP `lookup_funcs`, `callers`, `callees`, and decompilation on 2026-06-06 confirm the `0x132`-byte helper, two effect-object callers, `g_useEpfAssets` branch, `EFFECT%d.EPF`/`EFFECT.EPD` lookup, negative empty-rectangle path, `g_pEPFLib` access, and tile-midpoint offset through `word_66DA9C`/`word_66DAA0`. B008's 2026-06-30 callback later attached formal first-draft C++.

- 2026-06-05: Reconstructable metadata changed from blank to `TRUE` and attached to [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md).
  - Before: the effect bounds helper was documented but unclassified in generated coverage.
  - After: it is marked as NexusTK-owned effect-image helper source under the validated EffectObjImageLib file root. B008's 2026-06-30 callback later attached formal first-draft C++ while preserving final helper/file-split and resource-table naming caveats.
  - Evidence: live IDA MCP confirms `sub_4DE2A0` at `0x004de2a0`, size `0x132`, with two direct effect-object callers and callees to resource-layout, rectangle initialization, and rectangle offset helpers.

- Before: the page had `COMPLETION:0` and `CONFIDENCE:0`, cited non-authoritative path evidence, and used the old inclusive range spelling.
- Changed to: `COMPLETION:78` and `CONFIDENCE:86`, IDA-backed bounds, caller list, exact modern/legacy atlas behavior, and negative-sprite empty-rectangle behavior.
- Summary/evidence: IDA MCP on 2026-05-30 confirms `0x004de2a0-0x004de3d2`, two effect-object callers, calls to `0x004d0530`, `0x004b7e10`, and `0x004b7c50`, and the `EFFECT%d.EPF`/`EFFECT.EPD` mode branch.

- 2026-06-14 A001: Raised from `82/88` to `85/90`.
  - Before: the page had correct behavior/ownership but still used legacy routing wording and lacked current endpoint/padding and constant-verification evidence.
  - After: added current owner/emitter terminology, a score rationale table, live IDA MCP lookup/analyze/xref/decompile refresh, `get_bytes` endpoint padding evidence, and `int_convert.py`-verified constants.
