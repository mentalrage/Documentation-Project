*** UID:0000UH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000YO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# DrawEncodedAlphaFrame 0x00462F20

## Status

- Confidence: promoted support index; source-bearing evidence and the `88/91` score live on [UID:0000YO][0x00462f20-0x00463252.DrawEncodedAlphaFrame](by-memory/0x00462f20-0x00463252.DrawEncodedAlphaFrame.md).
- Entity kind: non-emitting support/alias for the exact by-memory `AlphaMaskSurface` member method.
- Likely source module: [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md), routed through the source-bearing by-memory page.
- Owner/emitter route: owned by [UID:0000YO][0x00462f20-0x00463252.DrawEncodedAlphaFrame](by-memory/0x00462f20-0x00463252.DrawEncodedAlphaFrame.md); no direct emitter on this support index.
- Exact range: [UID:0000YO][0x00462f20-0x00463252.DrawEncodedAlphaFrame](by-memory/0x00462f20-0x00463252.DrawEncodedAlphaFrame.md)

## Behavior

This AlphaMaskSurface member draws encoded frame rows into the receiver's byte-mask buffer. It clips a requested destination/source rectangle pair, skips encoded rows until the source start row, then walks signed run tokens for each row. Runs with the high bit set are drawn; the low seven bits carry run length. The written alpha value is interpolated vertically between two caller-provided alpha endpoints.

The transfer mode mirrors the other mask helpers:

| Mode | Operation |
| --- | --- |
| `0` | Fill/replace the covered run with the interpolated alpha. |
| `1` | Add the interpolated alpha to destination bytes. |
| `2` | Subtract the interpolated alpha from destination bytes. |

## Evidence

- IDA MCP decompilation on 2026-05-22 shows the signed-run row walker, vertical alpha ramp, and replace/add/subtract branches.
- IDA MCP live recheck on 2026-05-26 confirms function start `0x00462f20`, end-exclusive `0x00463252`, IDA name `sub_462F20`, and nine direct code xrefs.
- IDA MCP recheck on 2026-05-25 reports nine code xrefs in render/image-library neighborhoods. Six currently resolve to caller functions through IDA's caller query: `0x4db5a4`, `0x4dd7f6`, `0x4de289`, `0x4defa2`, `0x4df1bd`, and `0x4e31c4`.
- 2026-05-26 IDA MCP caller/xref recheck maps those six modeled callers to established image-library owners:

| Call site | Containing function | Current owner evidence |
| --- | --- | --- |
| `0x004db5a4` | `0x004db3b0` | [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md) `RenderMonsterImage` overlay pass. |
| `0x004dd7f6` | `0x004dd2c0` | [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md) `RenderStaticObject` overlay pass. |
| `0x004de289` | `0x004de190` | [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md) `RenderEffectFrame` overlay pass. |
| `0x004defa2` | `0x004dee50` | [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md) `DrawItemImage` overlay pass. |
| `0x004df1bd` | `0x004defc0` | [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md) `DrawItemImageIn43x43Slot` overlay pass. |
| `0x004e31c4` | `0x004e2fe0` | [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md) prepared-composition overlay pass. |

- The remaining xrefs at `0x004d5ea6`, `0x004d6b16`, and `0x004dcca5` are still code refs but IDA currently reports no containing function. Local disassembly shows the same scaled overlay-strength setup before calling `0x00462f20`, so keep them as raw image-library neighborhood evidence rather than separate source owners.
- The helper uses the same alpha-surface layout and rect intersection helper family as `AlphaMaskSurface` and `DrawFrameWithBlendMode`.
- 2026-05-30 IDA MCP recheck confirms `sub_462F20` size `0x332`, the same six modeled callers, and the same three raw xrefs outside modeled functions.
- 2026-05-30 decompilation confirms the encoded source rows are read from `a3[9]`, target pixels/stride are read from alpha-surface offsets `+0x14/+0x20`, and the vertical alpha ramp is rounded from the caller-provided row/alpha endpoints.
- B004 2026-06-20 EPFTileContext support sync identifies source field `a3[9]` as the same signed-run row stream carried by `EPFTileContext::encodedMaskBytes` at `+0x24` when the source descriptor is an EPFTileContext/frame-compatible record. This confirms the encoded-mask stream is also consumed by alpha-mask overlay helpers, not only by Surface sprite/tile blitters.
- 2026-06-16 A002 live IDA MCP refresh on session `b001_maildialogs_0000ZO_20260616` again reports `sub_462F20` at `0x00462f20` with size `0x332`, nine total code xrefs, and six modeled callers: `0x004db3b0`, `0x004dd2c0`, `0x004de190`, `0x004dee50`, `0x004defc0`, and `0x004e2fe0`.
- The same pass confirms the three raw xrefs `0x004d5ea6`, `0x004d6b16`, and `0x004dcca5` still have no containing function in the current IDB. They remain image-library caller-boundary recovery work, not blockers for UID0000YO ownership, source placement, or signature.
- Current compact analysis lists only `sub_4B7CC0`, `_memset`, and the security-cookie check as callees, and the decompilation still shows encoded rows loaded from `a3[9]`, clipped target writes through the alpha-surface pixel/stride fields, signed run tokens using `token & 0x7f` for length, and mode-specific replace/add/subtract loops.
- 2026-06-16 A001 live IDA/PE refresh on session `b001_selflookpane_0001H7_20260616` reconfirmed `sub_462F20` at `0x00462f20` size `0x332`, prototype-shaped `__thiscall(int *this, int *, _DWORD *, _DWORD *, int, unsigned __int8, int, unsigned __int8, int)`, six modeled callers, three raw no-containing-function callsites, and callees `sub_4B7CC0`, `_memset`, and the security-cookie check.
- The same pass ran a section-mapped PE scan of `NexusTK.exe`: no absolute VA/RVA pointer hits target `0x00462f20`, and the only rel32 calls/jumps are the nine documented calls at `0x004d5ea6`, `0x004d6b16`, `0x004db5a4`, `0x004dcca5`, `0x004dd7f6`, `0x004de289`, `0x004defa2`, `0x004df1bd`, and `0x004e31c4`.
- Byte reads around `0x00462f00` and `0x00463240` reconfirm the `0xcc`-bounded start after `DrawFrameWithBlendMode` and `retn 20h` followed by alignment bytes. Reads around the raw callsites `0x004d5ea6`, `0x004d6b16`, and `0x004dcca5` show the same inline overlay-strength setup immediately before the rel32 call; IDA still reports those addresses as not functions.

## Reconstruction Notes

This page is a non-emitting index. Keep the source-bearing implementation and evidence on UID0000YO as a shared AlphaMaskSurface member; do not duplicate it into `MonsterImageLib`, `StaticObjImageLib`, `EffectObjImageLib`, `ItemObjImageLib`, or `NewHumanImageLib`.

The source form should keep the three blend modes visible: replace/fill, add, and subtract. Runs with the high bit set are drawn; non-negative run tokens only advance the x cursor.

Current source-facing signature:

```cpp
int AlphaMaskSurface::DrawEncodedAlphaFrame(
    RectBounds *dstRect,
    EPFTileContext *sourceContext,
    RectBounds *sourceOrigin,
    int alphaEndY,
    unsigned char alphaEnd,
    int alphaStartY,
    unsigned char alphaStart,
    int blendMode);
```

`EPFTileContext::encodedMaskBytes` at `+0x24` supplies the encoded stream; no new payload type is needed. UID0000YO intentionally keeps formal C++ blank because the observed return register is variant and source-unclean: null stream returns a stale source-context pointer value, mode `0` returns clipped-bottom-shaped state, modes `1` and `2` return row-offset/clipped-top-shaped state, and invalid modes return `blendMode - 2`. Normalizing that result would be an unsupported behavior change.

## Cross-References

- [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md)
- [UID:0000YO][0x00462f20-0x00463252.DrawEncodedAlphaFrame](by-memory/0x00462f20-0x00463252.DrawEncodedAlphaFrame.md)
- [UID:0000UI][DrawFrameWithBlendMode_00462E10](by-item/DrawFrameWithBlendMode_00462E10.md)
- [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md)
- [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md)
- [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md)
- [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md)
- [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md)

## Changes

- 2026-07-09 B001 UID0000YO support-index synchronization:
  - Historicalized the old `free render helper` classification. Current MCP proves an AlphaMaskSurface `thiscall` member with the signature above.
  - Converted this duplicate by-item page to a `-1/-1`, `RECONSTRUCTABLE:FALSE`, non-emitting support index owned by UID0000YO; the exact by-memory page remains the sole source-bearing documentation target.
  - Added the accepted return-contract no-code proof and reclassified the three raw xrefs as caller-boundary evidence rather than signature or placement blockers.

- 2026-06-16 A001 file/item completion refresh:
  - Before: `85/89`.
  - Changed to: `86/90`; owner/emitter remain [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md); final C++ remains blank.
  - Evidence: live IDA reconfirmed the exact size, prototype-shaped arguments, six modeled image-library callers, three raw callsites, compact callee set, signed-run row decoding, alpha-surface field use, vertical alpha ramp, and replace/add/subtract modes. A PE scan found no VA/RVA pointer refs and exactly the nine documented rel32 callsites, while bytes reconfirm the `0xcc`-bounded range and raw callsite neighborhoods. The remaining blockers are exact encoded-frame type names and three raw caller boundaries.

- 2026-06-16 A002 file/item completion refresh:
  - Before: `84/88`.
  - Changed to: `85/89`; owner/emitter remain [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md); final C++ remains blank.
  - Evidence: live IDA reconfirmed the exact size, nine xrefs, six modeled image-library callers, three still-raw image-library callsites, compact callee set, signed-run row decoding, alpha-ramp math, and mode-specific replace/add/subtract behavior. Completion still stops at `85` because the encoded-frame source type and three raw caller boundaries are not safely resolved.

- 2026-06-05: Reconstructable metadata changed from blank to `TRUE`, attached to [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md), and stale generated-emission wording was removed.
  - Before: the encoded alpha-frame blitter was documented but unclassified in autogen coverage.
  - After: it is marked as NexusTK-owned alpha-mask blitter source under the validated AlphaMaskSurface file root; C++ remains blank because final frame-source type names and mode naming are not at the 95/95 final-code bar.
  - Evidence: live IDA MCP confirms `sub_462F20` at `0x00462f20`, size `0x332`, with alpha-surface/rectangle callees and the already documented image-library caller spread.

- 2026-05-30: Raised completion/confidence from `0/0` to `84/88` and replaced the stale raw range text with the canonical by-memory UID link. Added current IDA MCP boundary/caller/xref/decompilation evidence and preserved the open frame-source type/raw-xref caveats.
