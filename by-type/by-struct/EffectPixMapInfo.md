*** UID:0001UA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# EffectPixMapInfo

## Status

- Confidence: strong for size and owning array, medium for final semantic name.
- Owner file: [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md).
- Source resource: `EFFECT.FRM`.
- Size: `0x04` bytes.

## Layout

```text
EffectPixMapInfo
  +0x00  int frameRemapOrPaletteSlot
```

## Notes

- Current generated output calls this protected-array element `EffectPixMapInfo`, but IDA proves each entry is a single four-byte value read from `EFFECT.FRM`.
- `RenderEffectFrame` indexes this array by animation frame and passes the selected value as the palette/remap slot for palette category `11`.
- Object offset `+0x58` stores a fallback `EffectPixMapInfo` value initialized to `-1`.

## IDA Evidence

- 2026-05-31 IDA MCP `decompile 0x004de7d0` confirms `EFFECT.FRM` begins with a four-byte count and then reads one four-byte value per remap entry.
- IDA MCP `decompile 0x004de190` indexes object offset `+0x50` by `4 * frameIndex`, falls back to object offset `+0x58`, and passes the selected value to the palette lookup with category `11`.

## Cross-References

- [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md)
- [UID:00004A][EffectObjImageLib](by-class/EffectObjImageLib.md)
- [UID:0001U9][EffectObjImageLibLayout](by-type/by-struct/EffectObjImageLibLayout.md)
- [UID:00017M][0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame](by-memory/0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame.md)

## Changes

- 2026-05-31 IDA evidence and scoring update:
  - Before: metadata was unevaluated (`0/0`) and reconstructability was blank.
  - After: marked `RECONSTRUCTABLE:TRUE`, with completion/confidence set to `70/84`.
  - Summary/evidence: IDA MCP loader and render checks confirm this is a four-byte resource-derived remap/palette-slot value; the final source-facing name is still provisional.
