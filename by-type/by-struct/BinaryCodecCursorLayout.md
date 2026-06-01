*** UID:0001TS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Binary Codec Cursor Layout

## Status

- Entity kind: shared object layout for [UID:00004F][Encoder](by-class/Encoder.md) and [UID:00003M][Decoder](by-class/Decoder.md).
- Confidence: strong for observed offsets, medium for final source-facing field names and `sizeof` tail padding.
- Likely owner header: `util/Encoder.h`, `util/Decoder.h`, or a compact `util/BinaryCodec.h`.
- Evidence basis: IDA MCP disassembly of constructor/initialize/finalize bodies on 2026-05-26, plus existing exact memory pages.
- Reconstructable: yes, as source-level codec cursor layout information. Do not emit declaration C++ until the final owner header and class split are proven.

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

## IDA Evidence

- `Encoder::Encoder` at `0x004a4e70` installs vtable `0x006192cc`, clears `+0x04`, `+0x08`, and `+0x0c`, then writes word `0x0101` at `+0x10`.
- `Decoder::Decoder` at `0x004a5640` installs vtable `0x006192d8`, clears `+0x04`, `+0x08`, and `+0x0c`, then writes word `0x0101` at `+0x10`.
- `Encoder::Initialize` at `0x004a55c0` stores buffer/size at `+0x04/+0x08`, clears cursor `+0x0c`, and sets byte `+0x11`.
- Raw [UID:00013P][0x004a5680-0x004a57dc.DecoderPrimitiveReaders](by-memory/0x004a5680-0x004a57dc.DecoderPrimitiveReaders.md) use `+0x04` as buffer base, `+0x08` as limit, `+0x0c` as cursor, `+0x10` as byte-order flag, and `+0x11` as valid flag.
- Raw [UID:00013R][0x004a57e0-0x004a5dcc.DecoderStringAndBlobReaders](by-memory/0x004a57e0-0x004a5dcc.DecoderStringAndBlobReaders.md) use the same fields for UTF-16, multibyte, raw-byte, transformed-byte, skip, and initialize bodies; the raw initialize stores buffer/limit, clears cursor, and sets valid flag.
- Raw `Decoder::Initialize` at `0x004a5db0` performs the same buffer/size/cursor/valid setup, but IDA does not currently model it as a function start.
- `Encoder::Finalize` at `0x004a55e0` returns previous valid state, optionally reports cursor `+0x0c`, writes a trailing NUL at `buffer[cursor]`, clears buffer/size/cursor, and resets byte `+0x11`.
- `Decoder::Finalize` at `0x004a5dd0` returns previous valid state, clears buffer/size/cursor, and resets byte `+0x11`.
- 2026-05-31 IDA MCP recheck confirms `Encoder::Encoder` at `0x004a4e70` and `Decoder::Decoder` at `0x004a5640` both clear dwords `+0x04`, `+0x08`, and `+0x0c`, then write word `0x0101` at `+0x10`.
- 2026-05-31 IDA MCP recheck confirms `Encoder::Initialize` at `0x004a55c0` writes buffer/size/cursor/valid at `+0x04/+0x08/+0x0c/+0x11`, and `Encoder::Finalize` at `0x004a55e0` returns byte `+0x11`, reports cursor `+0x0c`, clears the cursor state, and resets valid to `1`.
- 2026-05-31 IDA MCP recheck confirms `Decoder::Finalize` at `0x004a5dd0` returns byte `+0x11`, clears buffer/size/cursor, and resets valid to `1`.

## Generated-Data Caveat

Current `class_Encoder.meta_wave3` already records an 18-byte stream-like layout, but current `class_Decoder.meta_wave3` reports a 4-byte minimal class. IDA confirms `Decoder` uses the same cursor fields as `Encoder`; do not migrate active `class_Decoder.cpp` until this layout is corrected.

## Open Questions

- Final `sizeof` remains open: the observed fields span `0x12` bytes, but the original C++ layout may have rounded or packed tail padding.
- Final class split and shared base/helper naming remain open until all encoder/decoder read/write families are audited.

## Cross-References

- [UID:0000HQ][BinaryCodec](by-file/BinaryCodec.md)
- [UID:00004F][Encoder](by-class/Encoder.md)
- [UID:00003M][Decoder](by-class/Decoder.md)
- [UID:0001X1][BinaryCodecVtables](by-type/by-vtable/BinaryCodecVtables.md)
- [UID:00013D][0x004a4e70-0x004a5621.EncoderCore](by-memory/0x004a4e70-0x004a5621.EncoderCore.md)
- [UID:00013Q][0x004a5680-0x004a5dcf.DecoderRawReaderFamily](by-memory/0x004a5680-0x004a5dcf.DecoderRawReaderFamily.md)
- [UID:00013P][0x004a5680-0x004a57dc.DecoderPrimitiveReaders](by-memory/0x004a5680-0x004a57dc.DecoderPrimitiveReaders.md)
- [UID:00013R][0x004a57e0-0x004a5dcc.DecoderStringAndBlobReaders](by-memory/0x004a57e0-0x004a5dcc.DecoderStringAndBlobReaders.md)
- [UID:00013M][0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue](by-memory/0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue.md)
