*** UID:0001U8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# EffectInfo

## Status

- Confidence: strong for size, pointer/count ownership, and descriptor source; medium for final semantic field names.
- Owner file: [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md).
- Source resource: `EFFECT.TBL`.
- Size: `0x34` bytes.

## Layout

```text
EffectInfo
  +0x00  int effectKeyOrId
  +0x04  EffectFrameRecord* primaryFrames
  +0x08  int primaryUnknown0
  +0x0c  uint8 primaryFlagOrReserved
  +0x0d  uint8[3] primaryPadding
  +0x10  int primaryFrameCount
  +0x14  int primaryRangeStart
  +0x18  int primaryRangeEnd
  +0x1c  EffectFrameRecord* secondaryFrames
  +0x20  int secondaryUnknown0
  +0x24  uint8 secondaryFlagOrReserved
  +0x25  uint8[3] secondaryPadding
  +0x28  int secondaryFrameCount
  +0x2c  int secondaryRangeStart
  +0x30  int secondaryRangeEnd
```

The `primary` and `secondary` labels follow generated `LoadEffectTables`/destructor naming and the destructor's two independent frame-array frees. Final effect-authoring terminology may differ.

## Loader Behavior

- `EffectObjImageLib::LoadEffectTables` reads an `EFFECT.TBL` count, resizes the descriptor array to `count * 0x34`, then loads each descriptor.
- Each descriptor owns two heap arrays of [UID:0001U7][EffectFrameRecord](by-type/by-struct/EffectFrameRecord.md) entries.
- Each frame record is `0x10` bytes; the loader reads two integer fields, one float field, and one integer field per record.
- The ordinary and scalar deleting destructors free both frame arrays per descriptor and reset pointer/count/range fields.

## IDA Evidence

- 2026-05-31 IDA MCP `decompile 0x004de7d0` confirms the descriptor protected array is allocated and copied in `52`-byte strides.
- IDA `decompile 0x004de3e0` copies one descriptor as three 16-byte chunks plus a final four-byte field, proving the `0x34` byte size used by callers.
- IDA destructor decompilation at `0x004de050` and `0x004e62f0` iterates descriptors in `0x34` byte steps, frees both nested frame arrays, clears the two count fields, and resets range fields to `-1`.

## Cross-References

- [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md)
- [UID:00004A][EffectObjImageLib](by-class/EffectObjImageLib.md)
- [UID:0001U9][EffectObjImageLibLayout](by-type/by-struct/EffectObjImageLibLayout.md)
- [UID:0001U7][EffectFrameRecord](by-type/by-struct/EffectFrameRecord.md)
- [UID:00017L][0x004de050-0x004de189.EffectObjImageLibDestructor](by-memory/0x004de050-0x004de189.EffectObjImageLibDestructor.md)

## Changes

- 2026-05-31 IDA evidence and scoring update:
  - Before: metadata was unevaluated (`0/0`) and reconstructability was blank.
  - After: marked `RECONSTRUCTABLE:TRUE`, with completion/confidence set to `76/86`.
  - Summary/evidence: IDA MCP confirms the `0x34` descriptor size, descriptor-copy helper, loader ownership of two nested frame arrays, and destructor cleanup; final user-facing names for several descriptor scalar fields remain provisional.
