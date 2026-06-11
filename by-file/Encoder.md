*** UID:0000J1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:83 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# Encoder

## Status

- Confidence: strong for writer behavior; medium for exact split from [UID:0000IQ][Decoder](by-file/Decoder.md).
- Proposed module: `NexusTK/util/Encoder.cpp`, or folded into [UID:0000HQ][BinaryCodec](by-file/BinaryCodec.md) if later evidence proves a single paired codec file.
- Autogen/source-root status: validated source root at `NexusTK/util/`; [UID:00004F][Encoder](by-class/Encoder.md) is attached to this file, and concrete method pages under that class currently resolve to `auto-generated/NexusTK/util/Encoder.cpp`.
- Primary vtable: [UID:0001X1][BinaryCodecVtables](by-type/by-vtable/BinaryCodecVtables.md) at `0x006192cc`
- Shared layout: [UID:0001TS][BinaryCodecCursorLayout](by-type/by-struct/BinaryCodecCursorLayout.md)

## File Role

`Encoder.cpp` should own the small in-memory binary writer. It writes primitive values and raw spans into caller-supplied storage, tracks cursor/capacity state, supports byte-swapping, and finalizes with a trailing NUL byte.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| [UID:00004F][Encoder](by-class/Encoder.md) | [UID:00013C][0x004a4e70-0x004a4e94.EncoderConstructor](by-memory/0x004a4e70-0x004a4e94.EncoderConstructor.md), [UID:00013E][0x004a4ea0-0x004a4ea7.EncoderDestructor](by-memory/0x004a4ea0-0x004a4ea7.EncoderDestructor.md), [UID:00013F][0x004a4ec0-0x004a4ef1.EncoderWriteByte](by-memory/0x004a4ec0-0x004a4ef1.EncoderWriteByte.md), [UID:00013G][0x004a4f00-0x004a4f59.EncoderWriteShort](by-memory/0x004a4f00-0x004a4f59.EncoderWriteShort.md), [UID:00013H][0x004a4ff0-0x004a506b.EncoderWriteInt](by-memory/0x004a4ff0-0x004a506b.EncoderWriteInt.md), [UID:00013I][0x004a5480-0x004a54c6.EncoderWriteBytes](by-memory/0x004a5480-0x004a54c6.EncoderWriteBytes.md), [UID:00013J][0x004a55c0-0x004a55de.EncoderInitialize](by-memory/0x004a55c0-0x004a55de.EncoderInitialize.md), [UID:00013K][0x004a55e0-0x004a5621.EncoderFinalize](by-memory/0x004a55e0-0x004a5621.EncoderFinalize.md), [UID:00013L][0x004a5630-0x004a5631.EncoderNoopVirtual](by-memory/0x004a5630-0x004a5631.EncoderNoopVirtual.md), [UID:00013V][0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor](by-memory/0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor.md) | Concrete writer class, primitive/raw-span writes, buffer attach/finalize, no-op vtable slot, and scalar deleting destructor wrapper. |
| [UID:00013D][0x004a4e70-0x004a5621.EncoderCore](by-memory/0x004a4e70-0x004a5621.EncoderCore.md) | aggregate over the constructor, destructor, writer, initialize, and finalize child pages | Coverage/index range only; source emission should come from the exact child method pages once they reach the final-code gate. |

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
- [UID:00013C][0x004a4e70-0x004a4e94.EncoderConstructor](by-memory/0x004a4e70-0x004a4e94.EncoderConstructor.md)
- [UID:00013D][0x004a4e70-0x004a5621.EncoderCore](by-memory/0x004a4e70-0x004a5621.EncoderCore.md)
- [UID:00013F][0x004a4ec0-0x004a4ef1.EncoderWriteByte](by-memory/0x004a4ec0-0x004a4ef1.EncoderWriteByte.md)
- [UID:00013G][0x004a4f00-0x004a4f59.EncoderWriteShort](by-memory/0x004a4f00-0x004a4f59.EncoderWriteShort.md)
- [UID:00013H][0x004a4ff0-0x004a506b.EncoderWriteInt](by-memory/0x004a4ff0-0x004a506b.EncoderWriteInt.md)
- [UID:00013I][0x004a5480-0x004a54c6.EncoderWriteBytes](by-memory/0x004a5480-0x004a54c6.EncoderWriteBytes.md)
- [UID:00013K][0x004a55e0-0x004a5621.EncoderFinalize](by-memory/0x004a55e0-0x004a5621.EncoderFinalize.md)
- [UID:00013M][0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue](by-memory/0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue.md)
- [UID:00013V][0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor](by-memory/0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor.md)
- [UID:0001TS][BinaryCodecCursorLayout](by-type/by-struct/BinaryCodecCursorLayout.md)
- [UID:0001X1][BinaryCodecVtables](by-type/by-vtable/BinaryCodecVtables.md)
- [UID:0000IQ][Decoder](by-file/Decoder.md)

## Changes

- 2026-06-07 A007 source-root cleanup:
  - What existed before: scores were `81/80`; the contents table only named the class aggregate/core/no-op/destructor subset, and status still referenced recovered source instead of the current by-* evidence chain.
  - Changed to: scores `83/84`, explicit validated `NexusTK/util/` source-root status, a current child-page inventory for constructor/destructor/writer/finalize/vtable support pages, and aggregate/source-emission guidance for [UID:00013D][0x004a4e70-0x004a5621.EncoderCore](by-memory/0x004a4e70-0x004a5621.EncoderCore.md).
  - Summary/evidence: [UID:00004F][Encoder](by-class/Encoder.md) is attached to this file root, the listed memory pages resolve to `auto-generated/NexusTK/util/Encoder.cpp`, and the broader [UID:0000HQ][BinaryCodec](by-file/BinaryCodec.md) page remains a coordinator rather than the concrete `Encoder.cpp` owner.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:80` and `CONFIDENCE:78`.
  - Summary/evidence: writer role, proposed contents, text-edit consumer boundary, vtable/layout evidence, and Encoder/Decoder split caveat are documented; completion is lower than larger pages because detailed per-method behavior and caller coverage are compact rather than exhaustive.
- 2026-05-31 reconstruction path and IDA recheck:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, scores were `80/78`, and the module path used `util/Encoder.cpp` without an explicit generated root.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/"`, scores `81/80`, and proposed module `NexusTK/util/Encoder.cpp`.
  - Summary/evidence: IDA MCP reconfirmed modeled writer lifecycle/vtable glue and the text-edit consumer boundary. No C++ reconstruction code is emitted because per-method final-source rewrites and surrounding/dependency confidence are below the `95+` final-code gate.
