*** UID:0001UA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000IY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# EffectPixMapInfo

## Status

- Confidence: strong for size, owning array offsets, loader/read pattern, renderer consumption, and `EffectObjImageLib` ownership; medium for final source-facing typedef/member name.
- Owner file: [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md).
- Source resource: `EFFECT.FRM`.
- Size: `0x04` bytes.
- Autogen parent: [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md), because this record is source-declared/generated with the effect image-library resource loader.

## Layout

```text
EffectPixMapInfo
  +0x00  int frameRemapOrPaletteSlot
```

## Notes

- Current generated output calls this protected-array element `EffectPixMapInfo`, but IDA proves each entry is a single four-byte value read from `EFFECT.FRM`; it may become a typedef or a one-field record in final source.
- `EffectObjImageLib` stores the `EFFECT.FRM` count at object offset `+0x4c`, the entry buffer pointer at `+0x50`, and the fallback entry at `+0x58`.
- `RenderEffectFrame` indexes this array by animation frame and passes the selected value as the palette/remap slot for palette category `11`.
- Object offset `+0x58` stores a fallback `EffectPixMapInfo` value initialized to `-1`.

## IDA Evidence

- 2026-05-31 IDA MCP `decompile 0x004de7d0` confirms `EFFECT.FRM` begins with a four-byte count and then reads one four-byte value per remap entry.
- IDA MCP `decompile 0x004de190` indexes object offset `+0x50` by `4 * frameIndex`, falls back to object offset `+0x58`, and passes the selected value to the palette lookup with category `11`.
- 2026-06-04 live IDA MCP `lookup_funcs` confirms `sub_4DE7D0` at `0x004de7d0` is `0x453` bytes and `sub_4DE190` at `0x004de190` is `0x110` bytes.
- 2026-06-04 live IDA MCP xrefs and `py_eval` confirm wide-string globals `aEffectTbl` at `0x0061c230` and `aEffectFrm` at `0x0061c248`; `aEffectFrm` has its loader data xref at `0x004deb48`.
- In the loader, live IDA disassembly shows `0x004deb3c` initializes `this+0x58` to `-1`, `0x004deb5c-0x004deb68` reads the four-byte `EFFECT.FRM` count, `0x004deb80-0x004deb8f` allocates `4 * count`, and `0x004debc4/0x004debca` stores the count and pointer at `this+0x4c/+0x50`.
- In the loader loop, live IDA shows each destination selected as `this+0x50 + index * 4` with fallback to `this+0x58`, then read with `sub_49C310(..., 4)` at `0x004debeb-0x004debf4`.
- In the renderer, live IDA shows `0x004de1d4-0x004de1ec` selecting `this+0x50 + frameIndex * 4` or fallback `this+0x58`, and `0x004de213-0x004de218` passes the selected dword to palette lookup `sub_543E40` with category `0x0b`.

## Cross-References

- [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md)
- [UID:00004A][EffectObjImageLib](by-class/EffectObjImageLib.md)
- [UID:0001U9][EffectObjImageLibLayout](by-type/by-struct/EffectObjImageLibLayout.md)
- [UID:00017M][0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame](by-memory/0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame.md)
- [UID:0002HB][0x004de7d0-0x004dec23.EffectObjImageLibLoadEffectTables](by-memory/0x004de7d0-0x004dec23.EffectObjImageLibLoadEffectTables.md)

## Changes

- 2026-05-31 IDA evidence and scoring update:
  - Before: metadata was unevaluated (`0/0`) and reconstructability was blank.
  - After: marked `RECONSTRUCTABLE:TRUE`, with completion/confidence set to `70/84`.
  - Summary/evidence: IDA MCP loader and render checks confirm this is a four-byte resource-derived remap/palette-slot value; the final source-facing name is still provisional.
- 2026-06-04 live IDA MCP evidence and parent assignment:
  - Before: scores were `70/84` and the page was not attached to its owning file.
  - After: scores set to `82/88` and `AUTOGEN_PARENT_UID:0000IY`.
  - Summary/evidence: live IDA MCP confirmed exact loader/render function sizes, the `aEffectFrm` wide-string global and xref, `this+0x4c/+0x50/+0x58` count/pointer/fallback storage, `4 * count` allocation, per-entry four-byte reads, renderer fallback selection, and palette category `0x0b` consumption. C++ remains blank because the final original typedef/member name is not proven to the 95+ reconstruction bar.
