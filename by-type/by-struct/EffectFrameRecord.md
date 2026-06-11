*** UID:0001U7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# EffectFrameRecord

## Status

- Confidence: strong for size, read pattern, and ownership lifecycle; low to medium for field semantics.
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

## Ownership And Consumers

- [UID:0002HB][0x004de7d0-0x004dec23.EffectObjImageLibLoadEffectTables](by-memory/0x004de7d0-0x004dec23.EffectObjImageLibLoadEffectTables.md) is the producer for both descriptor-owned frame arrays. Its frame-read table shows the same four-read `0x10` entry shape for both arrays and latches the image-library load/error byte when any integer/float read fails.
- [UID:0001U8][EffectInfo](by-type/by-struct/EffectInfo.md) stores the two array pointers and their counts/ranges. The current `primary` and `secondary` labels are documentation names that follow the two independent loader/destructor families, not final authoring-tool terms.
- [UID:00017L][0x004de050-0x004de189.EffectObjImageLibDestructor](by-memory/0x004de050-0x004de189.EffectObjImageLibDestructor.md) frees the secondary pointer at descriptor `+0x1c`, clears its count/ranges at `+0x28/+0x2c/+0x30`, then frees the primary pointer at `+0x04` and clears `+0x10/+0x14/+0x18`.
- [UID:0002HA][0x004de3e0-0x004de420.EffectObjImageLibGetEffectInfo](by-memory/0x004de3e0-0x004de420.EffectObjImageLibGetEffectInfo.md) copies the containing descriptor by value. That accessor preserves these frame-array pointers in the copied descriptor; it does not copy or reinterpret individual `EffectFrameRecord` entries.

## Boundary And Naming Caveats

- Keep this record distinct from [UID:0001UA][EffectPixMapInfo](by-type/by-struct/EffectPixMapInfo.md). `EffectFrameRecord` comes from variable-length arrays embedded in `EFFECT.TBL` descriptors, while `EffectPixMapInfo` is the separate four-byte `EFFECT.FRM` remap consumed by [UID:00017M][0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame](by-memory/0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame.md).
- The third field is strongly typed as a float by the loader helper, but its source-facing meaning is still open. Avoid naming it as duration, alpha, scale, or speed until runtime descriptor consumers are audited against these array entries.
- No nested ownership has been observed inside the record. Cleanup is array-level through [UID:0001U8][EffectInfo](by-type/by-struct/EffectInfo.md), so each entry should remain a plain four-scalar POD layout for now.

## IDA Evidence

- 2026-05-31 IDA MCP `decompile 0x004de7d0` confirms both descriptor frame loops allocate `16 * count` bytes.
- The same decompilation shows four reads per frame record: integer at `+0x00`, integer at `+0x04`, float at `+0x08`, and integer at `+0x0c`.
- IDA destructor decompilation at `0x004de050` and `0x004e62f0` frees both frame-array pointers from each [UID:0001U8][EffectInfo](by-type/by-struct/EffectInfo.md) descriptor.

## Score Rationale

- Completion is `78` because the page now records the producer, descriptor ownership, accessor behavior, destructor lifecycle, and the explicit boundary against `EFFECT.FRM` remap records. It remains below `80` until runtime consumers of the copied frame arrays are audited enough to name the four fields.
- Confidence is `86` because the record size, read helpers, array stride, and cleanup ownership are cross-confirmed by the loader, descriptor, accessor, and destructor pages. Confidence remains capped by unresolved field semantics.

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
- 2026-06-07 A006 documentation pass:
  - Before: the page was `72/84` and focused on size/read/destructor evidence.
  - After: raised to `78/86`.
  - Summary/evidence: added the loader producer relationship, `EffectInfo` pointer/count ownership, `GetEffectInfo` descriptor-copy behavior, destructor cleanup offsets for both frame-array families, explicit `EFFECT.FRM` remap boundary, and naming caveats for the unresolved scalar fields.
