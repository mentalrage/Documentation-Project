*** UID:0000J1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:81 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# Encoder

## Status

- Confidence: strong for writer behavior; medium for exact split from [UID:0000IQ][Decoder](by-file/Decoder.md).
- Proposed module: `NexusTK/util/Encoder.cpp`, or folded into [UID:0000HQ][BinaryCodec](by-file/BinaryCodec.md) if later evidence proves a single paired codec file.
- Current recovered source: `source-3/simroot_v2/class_Encoder.cpp`
- Primary vtable: [UID:0001X1][BinaryCodecVtables](by-type/by-vtable/BinaryCodecVtables.md) at `0x006192cc`
- Shared layout: [UID:0001TS][BinaryCodecCursorLayout](by-type/by-struct/BinaryCodecCursorLayout.md)

## File Role

`Encoder.cpp` should own the small in-memory binary writer. It writes primitive values and raw spans into caller-supplied storage, tracks cursor/capacity state, supports byte-swapping, and finalizes with a trailing NUL byte.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| [UID:00004F][Encoder](by-class/Encoder.md) | [UID:00013D][0x004a4e70-0x004a5621.EncoderCore](by-memory/0x004a4e70-0x004a5621.EncoderCore.md), [UID:00013L][0x004a5630-0x004a5631.EncoderNoopVirtual](by-memory/0x004a5630-0x004a5631.EncoderNoopVirtual.md), [UID:00013V][0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor](by-memory/0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor.md) | In-memory stream writer and vtable glue. |

## Boundary Notes

[UID:0000UM][EncodeTextEditState_0058E490](by-item/EncodeTextEditState_0058E490.md) is the only confirmed direct writer-family consumer today, but it belongs with [UID:0000ON][TextEditPane](by-file/TextEditPane.md). Do not migrate text-edit serialization into this utility file.

## Evidence Notes

2026-05-25 IDA MCP recheck:

- Vtable `0x006192cc` still contains scalar deleting destructor `0x004a5e30` and no-op virtual `0x004a5630`.
- `xrefs_to` confirms the behavioral writer methods are called only from [UID:0000UM][EncodeTextEditState_0058E490](by-item/EncodeTextEditState_0058E490.md) in the current database.
- `callers` finds no normal code caller for the no-op virtual slot; it is present through the vtable data reference at `0x006192d0`.

2026-05-26 IDA MCP recheck:

- Vtable refs remain constructor/destructor-owned at `0x004a4e70`, `0x004a4ea0`, and `0x004a5e3a`.
- Constructor and initialize/finalize disassembly reconfirm the shared cursor fields at `+0x04`, `+0x08`, `+0x0c`, `+0x10`, and `+0x11`.

2026-05-31 IDA MCP recheck:

- Modeled starts remain stable for constructor/initializer/no-op/destructor glue at `0x004a4e70`, `0x004a4ea0`, `0x004a5630`, and `0x004a5e30`.
- Vtable `0x006192cc` has two slots, `0x004a5e30` and `0x004a5630`, with xrefs from constructor/initializer/destructor code.
- `EncodeTextEditState` at `0x0058e490` remains the direct behavioral consumer, so codec utility ownership is supported while text-edit serialization stays outside this file.

## Cross-References

- [UID:0000HQ][BinaryCodec](by-file/BinaryCodec.md)
- [UID:00004F][Encoder](by-class/Encoder.md)
- [UID:00013D][0x004a4e70-0x004a5621.EncoderCore](by-memory/0x004a4e70-0x004a5621.EncoderCore.md)
- [UID:00013M][0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue](by-memory/0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue.md)
- [UID:0001TS][BinaryCodecCursorLayout](by-type/by-struct/BinaryCodecCursorLayout.md)
- [UID:0001X1][BinaryCodecVtables](by-type/by-vtable/BinaryCodecVtables.md)
- [UID:0000IQ][Decoder](by-file/Decoder.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:80` and `CONFIDENCE:78`.
  - Summary/evidence: writer role, proposed contents, text-edit consumer boundary, vtable/layout evidence, and Encoder/Decoder split caveat are documented; completion is lower than larger pages because detailed per-method behavior and caller coverage are compact rather than exhaustive.
- 2026-05-31 reconstruction path and IDA recheck:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, scores were `80/78`, and the module path used `util/Encoder.cpp` without an explicit generated root.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/"`, scores `81/80`, and proposed module `NexusTK/util/Encoder.cpp`.
  - Summary/evidence: IDA MCP reconfirmed modeled writer lifecycle/vtable glue and the text-edit consumer boundary. No C++ reconstruction code is emitted because per-method final-source rewrites and surrounding/dependency confidence are below the `95+` final-code gate.
