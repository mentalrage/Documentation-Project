*** UID:0001TS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Binary Codec Cursor Layout

## Status

- Entity kind: shared object layout for [UID:00004F][Encoder](by-class/Encoder.md) and [UID:00003M][Decoder](by-class/Decoder.md).
- Confidence: strong for observed offsets, constructor initialization, initialize/finalize field use, and raw reader/writer field use.
- Remaining caveat: final source-facing field names and tail padding/`sizeof` are not proven.
- Likely owner header: `NexusTK/util/Encoder.h`, `NexusTK/util/Decoder.h`, or a compact `NexusTK/util/BinaryCodec.h`.
- Parent attachment: attached to [UID:0000HQ][BinaryCodec](by-file/BinaryCodec.md), now `80/86`, because this is a shared layout across both codec classes.
- C++ reconstruction: intentionally blank until final header ownership and class split reach the 95/95 final-code bar.

## Layout

`Encoder` and `Decoder` use the same cursor-state footprint through offset `+0x11`.

| Offset | Field hypothesis | Encoder interpretation | Decoder interpretation | Evidence |
| --- | --- | --- | --- | --- |
| `0x00` | vtable pointer | `0x006192cc` | `0x006192d8` | Constructors and destructors install the class vtable. |
| `0x04` | buffer pointer | output byte buffer | input byte buffer | Constructors clear it; initialize methods store caller buffer. |
| `0x08` | buffer size / limit | output capacity | input size/limit | Initialize methods store caller size. |
| `0x0c` | cursor | write position | read position | Initialize/finalize reset it; read/write bodies advance it. |
| `0x10` | byte-order flag | nonzero writes integer values big-endian | nonzero reads integer values big-endian | Constructors write flags word `0x0101`; raw `Decoder::SetByteOrder` writes this byte. |
| `0x11` | valid flag | writable/valid state | readable/valid state | Constructors and initialize/finalize set it to `1`; overrun paths clear it. |

Observed field use spans `0x12` bytes. Final C++ `sizeof` and tail padding should remain open until allocation/caller evidence proves whether the original declaration packed the two flag bytes or rounded to 4-byte alignment.

## Live IDA Evidence

2026-06-04 IDA MCP checks confirmed:

- `Encoder::Encoder` at `0x004a4e70-0x004a4e94` stores vtable `0x006192cc`, clears dwords `+0x04`, `+0x08`, and `+0x0c`, then writes word `0x0101` at `+0x10`.
- `Decoder::Decoder` at `0x004a5640-0x004a5664` stores vtable `0x006192d8`, clears dwords `+0x04`, `+0x08`, and `+0x0c`, then writes word `0x0101` at `+0x10`.
- `Encoder::Initialize` at `0x004a55c0-0x004a55de` writes buffer/size at `+0x04/+0x08`, clears cursor `+0x0c`, and writes valid byte `+0x11`.
- `Encoder::Finalize` at `0x004a55e0-0x004a5621` reads valid byte `+0x11`, optionally reports cursor `+0x0c`, writes the trailing NUL through buffer `+0x04`, clears buffer/size/cursor, and restores valid byte `+0x11`.
- `Decoder::Finalize` at `0x004a5dd0-0x004a5ded` reads valid byte `+0x11`, clears buffer/size/cursor at `+0x04/+0x08/+0x0c`, and restores valid byte `+0x11`.
- Writer bodies at `0x004a4ec0`, `0x004a4f00`, `0x004a4ff0`, and `0x004a5480` check valid byte `+0x11`, compare limit `+0x08` with cursor growth from `+0x0c`, use buffer `+0x04`, and honor byte-order flag `+0x10` for scalar values.
- Raw [UID:00013P][0x004a5680-0x004a57dc.DecoderPrimitiveReaders](by-memory/0x004a5680-0x004a57dc.DecoderPrimitiveReaders.md) and [UID:00013R][0x004a57e0-0x004a5dce.DecoderStringAndBlobReaders](by-memory/0x004a57e0-0x004a5dce.DecoderStringAndBlobReaders.md) use the same field offsets for input buffer, limit, cursor, byte-order flag, and validity.

## Open Questions

- Final `sizeof` remains open: the observed fields span `0x12` bytes, but the original C++ layout may have rounded or packed tail padding.
- Final class split and shared base/helper naming remain open until all encoder/decoder read/write families are audited.

## Cross-References

- [UID:0000HQ][BinaryCodec](by-file/BinaryCodec.md)
- [UID:00004F][Encoder](by-class/Encoder.md)
- [UID:00003M][Decoder](by-class/Decoder.md)
- [UID:0001X1][BinaryCodecVtables](by-type/by-vtable/BinaryCodecVtables.md)
- [UID:00013D][0x004a4e70-0x004a5621.EncoderCore](by-memory/0x004a4e70-0x004a5621.EncoderCore.md)
- [UID:00013Q][0x004a5680-0x004a5dce.DecoderRawReaderFamily](by-memory/0x004a5680-0x004a5dce.DecoderRawReaderFamily.md)
- [UID:00013P][0x004a5680-0x004a57dc.DecoderPrimitiveReaders](by-memory/0x004a5680-0x004a57dc.DecoderPrimitiveReaders.md)
- [UID:00013R][0x004a57e0-0x004a5dce.DecoderStringAndBlobReaders](by-memory/0x004a57e0-0x004a5dce.DecoderStringAndBlobReaders.md)
- [UID:00013M][0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue](by-memory/0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue.md)

## Changes

- 2026-06-04: Raised grading from `78/88` to `82/90` and attached `AUTOGEN_PARENT_UID:0000HQ`.
  - Before: the page had strong layout evidence but still lacked a parent attachment and carried stale non-live metadata caveat wording.
  - After: live IDA MCP evidence records constructor, initialize, finalize, writer, and reader use of every cursor field, with the shared layout attached to the strengthened BinaryCodec coordinator.
  - Score rationale: completion and confidence increased because the field offsets are now verified across both classes and across both modeled and raw bodies. The score remains below final-code level because final field names, tail padding, and header ownership are still open.
