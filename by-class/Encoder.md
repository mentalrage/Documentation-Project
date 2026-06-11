*** UID:00004F | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000J1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Encoder

## Status

- Confidence: strong.
- Likely source file: [UID:0000J1][Encoder](by-file/Encoder.md), under the [UID:0000HQ][BinaryCodec](by-file/BinaryCodec.md) utility layer
- Autogen parent: [UID:0000J1][Encoder](by-file/Encoder.md)
- Main address evidence: [UID:00013D][0x004a4e70-0x004a5621.EncoderCore](by-memory/0x004a4e70-0x004a5621.EncoderCore.md), plus vtable glue in [UID:00013M][0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue](by-memory/0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue.md)
- Layout docs: [UID:0001TS][BinaryCodecCursorLayout](by-type/by-struct/BinaryCodecCursorLayout.md)
- Primary vtable: [UID:0001X1][BinaryCodecVtables](by-type/by-vtable/BinaryCodecVtables.md)
- Size/layout: observed fields span through offset `+0x11`; final source `sizeof` padding remains open.

## Class Purpose

`Encoder` is a caller-buffer binary writer. It appends primitive values and raw byte blocks to an attached buffer, tracks write position, and flips its valid/writable flag to false if a write would exceed the advertised capacity. It supports both native little-endian and swapped big-endian integer output through the byte-order flag at offset `+0x10`.

## Observed State

```text
+0x00  vtable pointer (`0x006192cc`)
+0x04  output buffer pointer
+0x08  output buffer capacity
+0x0c  current write position
+0x10  byte-order flag; nonzero writes integer values big-endian
+0x11  valid/writable flag
```

The constructor initializes the flags word to `0x0101`, so new instances default to big-endian integer order and writable state.

## Confirmed Methods

| Address | Method | Notes |
| --- | --- | --- |
| [UID:00013C][0x004a4e70-0x004a4e94.EncoderConstructor](by-memory/0x004a4e70-0x004a4e94.EncoderConstructor.md) | constructor | Installs the `Encoder` vtable, clears buffer/capacity/cursor, sets flags word to `0x0101`. |
| [UID:00013E][0x004a4ea0-0x004a4ea7.EncoderDestructor](by-memory/0x004a4ea0-0x004a4ea7.EncoderDestructor.md) | destructor | Restores the `Encoder` vtable; no owned buffer is freed. |
| [UID:00013F][0x004a4ec0-0x004a4ef1.EncoderWriteByte](by-memory/0x004a4ec0-0x004a4ef1.EncoderWriteByte.md) | `WriteByte` | Writes one byte when `capacity >= writePos + 2`; otherwise clears valid flag. |
| [UID:00013G][0x004a4f00-0x004a4f59.EncoderWriteShort](by-memory/0x004a4f00-0x004a4f59.EncoderWriteShort.md) | `WriteShort` | Writes two bytes in selected byte order, leaving one byte for final NUL. |
| [UID:00013H][0x004a4ff0-0x004a506b.EncoderWriteInt](by-memory/0x004a4ff0-0x004a506b.EncoderWriteInt.md) | `WriteInt` | Writes four bytes in selected byte order, leaving one byte for final NUL. |
| [UID:00013I][0x004a5480-0x004a54c6.EncoderWriteBytes](by-memory/0x004a5480-0x004a54c6.EncoderWriteBytes.md) | `WriteBytes` | Copies a caller-supplied byte span through the shared memory copy helper. |
| [UID:00013J][0x004a55c0-0x004a55de.EncoderInitialize](by-memory/0x004a55c0-0x004a55de.EncoderInitialize.md) | `Initialize` | Attaches caller buffer/capacity and resets write position and valid flag. |
| [UID:00013K][0x004a55e0-0x004a5621.EncoderFinalize](by-memory/0x004a55e0-0x004a5621.EncoderFinalize.md) | `Finalize` | Optionally reports bytes written, appends NUL, clears buffer/capacity/cursor, and returns prior valid state. |
| [UID:00013L][0x004a5630-0x004a5631.EncoderNoopVirtual](by-memory/0x004a5630-0x004a5631.EncoderNoopVirtual.md) | no-op virtual | Vtable slot at `0x006192d0`; omitted from active generated output. |
| [UID:00013V][0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor](by-memory/0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor.md) | scalar deleting destructor | Calls the destructor path and conditionally frees the object. |

## Evidence Notes

- IDA MCP confirms all active generated `Encoder` method starts and the scalar deleting destructor.
- IDA vtable inspection confirms the omitted no-op virtual at `0x004a5630`.
- IDA xrefs show the direct behavioral methods are called by [UID:0000UM][EncodeTextEditState_0058E490](by-item/EncodeTextEditState_0058E490.md), a text-edit serialization helper.
- `Encoder` does not own the output buffer. The caller allocates or provides it, and `Finalize` detaches rather than frees it.
- 2026-05-25 IDA MCP recheck reconfirmed the two-slot vtable at `0x006192cc` and that the active writer-family xrefs all come from [UID:0000UM][EncodeTextEditState_0058E490](by-item/EncodeTextEditState_0058E490.md).
- 2026-05-26 IDA MCP recheck again found the direct writer/finalize callers only in [UID:0000UM][EncodeTextEditState_0058E490](by-item/EncodeTextEditState_0058E490.md); the helper itself has one raw thunk xref at `0x00498c4a` and no formal modeled callers.
- 2026-05-26 IDA MCP vtable/layout recheck confirms vtable refs at `0x004a4e70`, `0x004a4ea0`, and `0x004a5e3a`, and confirms constructor/initialize/finalize use the shared cursor fields now documented in [UID:0001TS][BinaryCodecCursorLayout](by-type/by-struct/BinaryCodecCursorLayout.md).

## Current Caveats

- The no-op vtable slot at `0x004a5630` still needs to be modeled in final source even though it has no ordinary code callers.
- The only confirmed direct caller is a text-edit serializer. Do not assume network packet ownership from the generic "encoder" name without caller evidence.

## Cross-References

- [UID:0000J1][Encoder](by-file/Encoder.md)
- [UID:0000HQ][BinaryCodec](by-file/BinaryCodec.md)
- [UID:00003M][Decoder](by-class/Decoder.md)
- [UID:00013D][0x004a4e70-0x004a5621.EncoderCore](by-memory/0x004a4e70-0x004a5621.EncoderCore.md)
- [UID:00013M][0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue](by-memory/0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue.md)
- [UID:0001TS][BinaryCodecCursorLayout](by-type/by-struct/BinaryCodecCursorLayout.md)
- [UID:0001X1][BinaryCodecVtables](by-type/by-vtable/BinaryCodecVtables.md)
- [UID:0000UM][EncodeTextEditState_0058E490](by-item/EncodeTextEditState_0058E490.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `82/86`.
  - Summary/evidence: binary writer role, cursor layout, constructor/destructor/writer/finalize/no-op/scalar-destructor methods, vtable evidence, caller evidence, and caveats are documented; remaining work is final `sizeof` padding and broader caller provenance if new xrefs are recovered.
- 2026-05-31:
  - Before: the class was documented as reconstructable in prose but validator `RECONSTRUCTABLE` metadata was blank.
  - After: `RECONSTRUCTABLE` is set to `TRUE`.
  - Summary/evidence: IDA MCP reconfirmed the Encoder constructor/destructor/no-op/scalar-deleting vtable surface and direct consumer boundary; C++ code remains blank because final-source confidence is below the `95+` gate.
- 2026-06-05:
  - Before: `AUTOGEN_PARENT_UID` was blank, leaving reconstructable Encoder children unable to resolve to an autogen root.
  - After: `AUTOGEN_PARENT_UID` is set to [UID:0000J1][Encoder](by-file/Encoder.md), and stale generated-source wording was removed from the status/caveat text.
  - Summary/evidence: [UID:0000J1][Encoder](by-file/Encoder.md) is a validated `NexusTK/util/` file root with documented Encoder ownership; live autogen coverage showed [UID:00013D][0x004a4e70-0x004a5621.EncoderCore](by-memory/0x004a4e70-0x004a5621.EncoderCore.md) already using this class as parent, so the class needed a file-root parent chain.
