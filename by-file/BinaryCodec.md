*** UID:0000HQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# BinaryCodec

## Status

- Confidence: strong for the modeled `Encoder` method family, shared cursor layout, compact vtables, and neighboring padding/DAT boundary.
- Confidence: medium-high for the full `Decoder` reader family because the raw reader bodies are clear project code but still have no IDA function objects or direct caller xrefs.
- Proposed modules: `NexusTK/util/Encoder.cpp` and `NexusTK/util/Decoder.cpp`, with this page kept as the `NexusTK/util/` binary-codec source-family coordinator.
- C++ reconstruction: intentionally blank for this coordinator. The concrete code-bearing roots remain [UID:0000J1][Encoder](by-file/Encoder.md) and [UID:0000IQ][Decoder](by-file/Decoder.md), and final method names/signatures remain below the 95/95 final-code bar.
- Main classes: [UID:00004F][Encoder](by-class/Encoder.md) and [UID:00003M][Decoder](by-class/Decoder.md)
- Main memory docs: [UID:00013D][0x004a4e70-0x004a5621.EncoderCore](by-memory/0x004a4e70-0x004a5621.EncoderCore.md), [UID:00013M][0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue](by-memory/0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue.md), and [UID:00013Q][0x004a5680-0x004a5dce.DecoderRawReaderFamily](by-memory/0x004a5680-0x004a5dce.DecoderRawReaderFamily.md)
- Type docs: [UID:0001TS][BinaryCodecCursorLayout](by-type/by-struct/BinaryCodecCursorLayout.md) and [UID:0001X1][BinaryCodecVtables](by-type/by-vtable/BinaryCodecVtables.md)
- Evidence basis: live IDA MCP function, xref, vtable, padding, and raw-disassembly checks through 2026-06-04.

## File Role

This utility layer provides small in-memory binary stream helpers. `Encoder` writes primitive values and raw byte blocks into a caller-owned buffer, tracks overflow with a validity flag, and can swap 16-bit and 32-bit integer byte order. `Decoder` is the mirror reader: it consumes a caller-owned byte buffer, advances a read cursor, and invalidates itself when a read overruns the available data.

Current live xref evidence is asymmetric. IDA finds direct `Encoder` consumer calls from [UID:0000UM][EncodeTextEditState_0058E490](by-item/EncodeTextEditState_0058E490.md), but the raw `Decoder` reader starts in `0x004a5680-0x004a5db0` still have no inbound code/data refs. Treat `Decoder` as real retained project code, but keep the exact live/dead status open until caller recovery improves.

## Proposed Contents

| Entity | Address evidence | Proposed placement | Notes |
| --- | --- | --- | --- |
| `Encoder` | [UID:00013D][0x004a4e70-0x004a5621.EncoderCore](by-memory/0x004a4e70-0x004a5621.EncoderCore.md), no-op `0x004a5630`, scalar deleting destructor `0x004a5e30`, vtable `0x006192cc` | `NexusTK/util/Encoder.cpp` | Writes byte, short, int, and raw byte spans; finalizes with a trailing NUL byte. |
| `Decoder` | [UID:00013M][0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue](by-memory/0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue.md), raw readers [UID:00013Q][0x004a5680-0x004a5dce.DecoderRawReaderFamily](by-memory/0x004a5680-0x004a5dce.DecoderRawReaderFamily.md), vtable `0x006192d8` | `NexusTK/util/Decoder.cpp` | Reads byte, 16-bit, 24-bit, 32-bit, length-prefixed strings, NUL-terminated strings, raw spans, and transformed spans. |
| `EncodeTextEditState` | `0x0058e490-0x0058e691` | [UID:0000ON][TextEditPane](by-file/TextEditPane.md) | Sole confirmed direct behavioral `Encoder` consumer; serializes text-edit run tables into a heap buffer. |

## Live IDA Evidence

2026-06-04 IDA MCP checks confirmed:

- Modeled `Encoder` boundaries:
  - `0x004a4e70-0x004a4e94` constructor, vtable store `0x006192cc`, clears `+0x04/+0x08/+0x0c`, writes flags word `0x0101` at `+0x10`.
  - `0x004a4ea0-0x004a4ea7` destructor, restores vtable `0x006192cc`.
  - `0x004a4ec0-0x004a4ef1`, `0x004a4f00-0x004a4f59`, `0x004a4ff0-0x004a506b`, and `0x004a5480-0x004a54c6` write byte/short/int/raw-span data while checking `+0x08`, advancing `+0x0c`, honoring `+0x10`, and clearing `+0x11` on overflow.
  - `0x004a55c0-0x004a55de` initializes buffer/size/cursor/valid fields.
  - `0x004a55e0-0x004a5621` returns prior valid state, reports cursor, writes the final NUL, clears buffer/size/cursor, and resets valid.
- Direct `Encoder` calls are from `0x0058e490-0x0058e691`: constructor at `0x0058e4e4`, initialize at `0x0058e54b`, raw writes at `0x0058e56e`/`0x0058e57b`/`0x0058e58b`/`0x0058e59a`, finalize at `0x0058e624`, and destructor at `0x0058e66c`.
- Modeled `Decoder`/glue boundaries:
  - `0x004a5630-0x004a5631` one-byte `Encoder` no-op virtual.
  - `0x004a5640-0x004a5664` `Decoder` constructor, vtable store `0x006192d8`, clears `+0x04/+0x08/+0x0c`, writes flags word `0x0101` at `+0x10`.
  - `0x004a5670-0x004a5677` `Decoder` destructor, restores vtable `0x006192d8`.
  - `0x004a5dd0-0x004a5ded` `Decoder` finalize/reset, returns `+0x11`, clears buffer/size/cursor, and resets valid.
  - `0x004a5df0-0x004a5df1` one-byte `Decoder` no-op virtual.
  - `0x004a5e00-0x004a5e24` and `0x004a5e30-0x004a5e54` scalar deleting destructors.
- Raw `Decoder` starts at `0x004a5680`, `0x004a5690`, `0x004a56c0`, `0x004a5710`, `0x004a5770`, `0x004a57e0`, `0x004a5870`, `0x004a5930`, `0x004a5a40`, `0x004a5bb0`, `0x004a5c80`, `0x004a5cd0`, `0x004a5d80`, and `0x004a5db0` still have no IDA function object and no inbound code/data refs.
- Vtable/read-only data:
  - `0x006192c8 -> ??_R4Encoder@@6B@`
  - `0x006192cc -> 0x004a5e30`, with vtable-store refs at `0x004a4e70`, `0x004a4ea0`, and `0x004a5e3a`
  - `0x006192d0 -> 0x004a5630`
  - `0x006192d4 -> ??_R4Decoder@@6B@`
  - `0x006192d8 -> 0x004a5e00`, with vtable-store refs at `0x004a5640`, `0x004a5670`, and `0x004a5e0a`
  - `0x006192dc -> 0x004a5df0`
  - `0x006192e0 -> 0x0000001a`, referenced from `0x004a5e9e` inside the adjacent DAT parser helper, not a codec vtable slot.
- Padding boundaries are stable: `0x004a4e6b-0x004a4e70`, `0x004a5621-0x004a5630`, and `0x004a5e54-0x004a5e60` are `0xcc` bytes outside the codec functions.

## Ownership Boundaries

Keep [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md) in `network/PacketBuffer.cpp`: it owns packet/network buffer behavior and should not absorb these generic in-memory codec helpers unless later caller evidence proves the original project did so. Keep [UID:0000ON][TextEditPane](by-file/TextEditPane.md) ownership for [UID:0000UM][EncodeTextEditState_0058E490](by-item/EncodeTextEditState_0058E490.md): it is a text-edit serializer that consumes `Encoder`, not a codec method.

Do not merge this with [UID:0000IN][DATFile](by-file/DATFile.md). `DATFile` is an archive-backed file implementation, and `0x004a5e60` is a physically adjacent DAT parser helper after the codec padding boundary.

## Cross-References

- [UID:00004F][Encoder](by-class/Encoder.md)
- [UID:00003M][Decoder](by-class/Decoder.md)
- [UID:0000J1][Encoder](by-file/Encoder.md)
- [UID:0000IQ][Decoder](by-file/Decoder.md)
- [UID:00013D][0x004a4e70-0x004a5621.EncoderCore](by-memory/0x004a4e70-0x004a5621.EncoderCore.md)
- [UID:00013M][0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue](by-memory/0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue.md)
- [UID:00013Q][0x004a5680-0x004a5dce.DecoderRawReaderFamily](by-memory/0x004a5680-0x004a5dce.DecoderRawReaderFamily.md)
- [UID:0001TS][BinaryCodecCursorLayout](by-type/by-struct/BinaryCodecCursorLayout.md)
- [UID:0001X1][BinaryCodecVtables](by-type/by-vtable/BinaryCodecVtables.md)
- [UID:0000UM][EncodeTextEditState_0058E490](by-item/EncodeTextEditState_0058E490.md)
- [UID:0000ON][TextEditPane](by-file/TextEditPane.md)

## Changes

- 2026-06-04: Raised grading from `72/82` to `80/86`.
  - Before: the page still carried stale non-live provenance wording and older evidence blocks, and its score understated the now-documented layout/vtable/memory evidence.
  - After: the page uses live IDA MCP evidence for modeled `Encoder`/`Decoder` boundaries, raw `Decoder` non-function/no-xref status, direct `Encoder` consumer calls, shared cursor offsets, compact vtables, read-only data boundary, and padding envelopes.
  - Score rationale: completion increased because the coordinator now cleanly records the full source-family shape and ownership boundaries. It remains below final-code level because raw `Decoder` readers still lack IDA function objects/callers and the final separate-vs-paired original file split remains unresolved.
