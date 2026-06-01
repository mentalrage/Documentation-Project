*** UID:0001U7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# EffectFrameRecord

## Status

- Confidence: strong for size and read pattern, low to medium for field semantics.
- Owner file: [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md).
- Source resource: `EFFECT.TBL`.
- Size: `0x10` bytes.

## Layout

```text
EffectFrameRecord
  +0x00  int value0
  +0x04  int value1
  +0x08  float value2
  +0x0c  int value3
```

## Notes

- `EffectObjImageLib::LoadEffectTables` allocates one array for the primary frame sequence and one array for the secondary frame sequence in each [UID:0001U8][EffectInfo](by-type/by-struct/EffectInfo.md) descriptor.
- The loader reads each `EffectFrameRecord` as four fields: integer, integer, float, integer. IDA names the float read helper separately from the integer read helper.
- Destructors free these arrays through the owning [UID:0001U8][EffectInfo](by-type/by-struct/EffectInfo.md) pointers. The record does not appear to own further heap data.

## IDA Evidence

- 2026-05-31 IDA MCP `decompile 0x004de7d0` confirms both descriptor frame loops allocate `16 * count` bytes.
- The same decompilation shows four reads per frame record: integer at `+0x00`, integer at `+0x04`, float at `+0x08`, and integer at `+0x0c`.
- IDA destructor decompilation at `0x004de050` and `0x004e62f0` frees both frame-array pointers from each [UID:0001U8][EffectInfo](by-type/by-struct/EffectInfo.md) descriptor.

## Cross-References

- [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md)
- [UID:00004A][EffectObjImageLib](by-class/EffectObjImageLib.md)
- [UID:0001U8][EffectInfo](by-type/by-struct/EffectInfo.md)
- [UID:0001U9][EffectObjImageLibLayout](by-type/by-struct/EffectObjImageLibLayout.md)

## Changes

- 2026-05-31 IDA evidence and scoring update:
  - Before: metadata was unevaluated (`0/0`) and reconstructability was blank.
  - After: marked `RECONSTRUCTABLE:TRUE`, with completion/confidence set to `72/84`.
  - Summary/evidence: IDA MCP loader and destructor checks confirm the 16-byte record size, read pattern, owning arrays, and lack of nested heap ownership; final semantic names for the four fields remain provisional.
