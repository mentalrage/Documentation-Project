*** UID:0001X1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Binary Codec Vtables

## Status

- Entity kind: vtable layout
- Confidence: strong for slot values, owning class association, vtable-store refs, and the non-vtable boundary at `0x006192e0`.
- Parent attachment: attached to [UID:0000HQ][BinaryCodec](by-file/BinaryCodec.md), now `80/86`, because this is shared read-only type data for both codec classes.
- Evidence basis: live IDA MCP dword, xref, function-boundary, and padding checks through 2026-06-04.
- Metadata caveat: any non-IDA metadata that omits these vtables is incomplete; IDA dwords and xrefs are the authority here.

## Encoder Vtable

- Primary vtable: `0x006192cc`
- Owner class: [UID:00004F][Encoder](by-class/Encoder.md)
- Likely source file: [UID:0000J1][Encoder](by-file/Encoder.md)

| Slot | Target | Interpretation |
| --- | --- | --- |
| `+0x00` | [UID:00013V][0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor](by-memory/0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor.md) | `Encoder::ScalarDeletingDestructor` |
| `+0x04` | [UID:00013L][0x004a5630-0x004a5631.EncoderNoopVirtual](by-memory/0x004a5630-0x004a5631.EncoderNoopVirtual.md) | no-op virtual / `nullsub_27` |

IDA xrefs to `0x006192cc` land at:

- `0x004a4e70` in `Encoder::Encoder`
- `0x004a4ea0` in `Encoder::~Encoder`
- `0x004a5e3a` in `Encoder::ScalarDeletingDestructor`

The no-op virtual target has only the vtable data reference at `0x006192d0` in the current IDA database.

## Decoder Vtable

- Primary vtable: `0x006192d8`
- Owner class: [UID:00003M][Decoder](by-class/Decoder.md)
- Likely source file: [UID:0000IQ][Decoder](by-file/Decoder.md)

| Slot | Target | Interpretation |
| --- | --- | --- |
| `+0x00` | [UID:00013U][0x004a5e00-0x004a5e24.DecoderScalarDeletingDestructor](by-memory/0x004a5e00-0x004a5e24.DecoderScalarDeletingDestructor.md) | `Decoder::ScalarDeletingDestructor` |
| `+0x04` | [UID:00013T][0x004a5df0-0x004a5df1.DecoderNoopVirtual](by-memory/0x004a5df0-0x004a5df1.DecoderNoopVirtual.md) | no-op virtual / `nullsub_28` |

IDA xrefs to `0x006192d8` land at:

- `0x004a5640` in `Decoder::Decoder`
- `0x004a5670` in `Decoder::~Decoder`
- `0x004a5e0a` in `Decoder::ScalarDeletingDestructor`

The no-op virtual target has only the vtable data reference at `0x006192dc` in the current IDA database.

## Live IDA Evidence

2026-06-04 IDA MCP checks confirmed:

- `0x004a5630-0x004a5631` and `0x004a5df0-0x004a5df1` are one-byte `retn` functions.
- `0x004a5e00-0x004a5e24` and `0x004a5e30-0x004a5e54` are scalar deleting destructor wrappers that restore the class vtable and conditionally call the delete helper.
- `0x006192c8 -> ??_R4Encoder@@6B@`
- `0x006192cc -> 0x004a5e30`
- `0x006192d0 -> 0x004a5630`
- `0x006192d4 -> ??_R4Decoder@@6B@`
- `0x006192d8 -> 0x004a5e00`
- `0x006192dc -> 0x004a5df0`
- `0x006192e0 -> 0x0000001a`, with the only data ref from `0x004a5e9e` inside the adjacent [UID:0000IN][DATFile](by-file/DATFile.md) parser helper. This proves `0x006192e0` is not another codec vtable slot.
- `0x004a5e54-0x004a5e60` is `0xcc` padding before the adjacent DAT helper at `0x004a5e60`.

## Source-Layout Implication

Both classes have compact two-slot vtables and share the same [UID:0001TS][BinaryCodecCursorLayout](by-type/by-struct/BinaryCodecCursorLayout.md) field pattern. The vtable adjacency supports a paired utility source family, either separate `NexusTK/util/Encoder.cpp` / `NexusTK/util/Decoder.cpp` files or one compact binary-codec source/header family. It does not support assigning the codec methods to packet, DAT, or text-edit feature modules.

## Cross-References

- [UID:0000HQ][BinaryCodec](by-file/BinaryCodec.md)
- [UID:0000J1][Encoder](by-file/Encoder.md)
- [UID:0000IQ][Decoder](by-file/Decoder.md)
- [UID:00004F][Encoder](by-class/Encoder.md)
- [UID:00003M][Decoder](by-class/Decoder.md)
- [UID:0001TS][BinaryCodecCursorLayout](by-type/by-struct/BinaryCodecCursorLayout.md)
- [UID:00013M][0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue](by-memory/0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue.md)
- [UID:00013V][0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor](by-memory/0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor.md)
- [UID:00013U][0x004a5e00-0x004a5e24.DecoderScalarDeletingDestructor](by-memory/0x004a5e00-0x004a5e24.DecoderScalarDeletingDestructor.md)

## Changes

- 2026-06-04: Attached `AUTOGEN_PARENT_UID:0000HQ`; scores remain `84/90`.
  - Before: the page had strong vtable content but no parent attachment and stale non-IDA metadata caveat wording.
  - After: live IDA MCP reconfirms slot dwords, vtable-store refs, no-op bodies, deleting-destructor boundaries, padding, and the `0x006192e0` non-vtable boundary, and the page is attached to the strengthened BinaryCodec coordinator.
  - Score rationale: no score increase was made because the new pass reconfirms rather than materially expands the vtable evidence.
