*** UID:0001X1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Binary Codec Vtables

## Status

- Entity kind: vtable layout
- Confidence: strong for slot values and owning class association.
- Evidence basis: IDA MCP `py_eval` vtable reads and xref checks on 2026-05-26 and 2026-05-31.
- Current data caveat: `class_Encoder.meta_wave3` and `class_Decoder.meta_wave3` both report `vtable_count: 0`; do not use that generated count as authority.

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

## 2026-05-31 IDA Recheck

- `lookup_funcs` confirms the vtable slots are code: `0x004a5630` is `nullsub_27` size `0x1`, `0x004a5df0` is `nullsub_28` size `0x1`, `0x004a5e00` is size `0x24`, and `0x004a5e30` is size `0x24`.
- `lookup_funcs` confirms `0x006192cc`, `0x006192d8`, and `0x006192e0` are not functions.
- `py_eval` confirms `0x006192c8 -> ??_R4Encoder@@6B@`, `0x006192cc -> 0x004a5e30`, `0x006192d0 -> 0x004a5630`, `0x006192d4 -> ??_R4Decoder@@6B@`, `0x006192d8 -> 0x004a5e00`, and `0x006192dc -> 0x004a5df0`.
- `xrefs_to 0x006192cc` reports only Encoder constructor/destructor/deleting-destructor vptr stores at `0x004a4e70`, `0x004a4ea0`, and `0x004a5e3a`.
- `xrefs_to 0x006192d8` reports only Decoder constructor/destructor/deleting-destructor vptr stores at `0x004a5640`, `0x004a5670`, and `0x004a5e0a`.
- `xrefs_to 0x006192e0` reports DAT parser code at `0x004a5e9e`, so the table after the Decoder no-op slot is adjacent non-vtable constant data, not a third Decoder vtable slot.
- Disassembly confirms both no-op virtual targets are single-byte `retn` functions and both scalar deleting destructors restore the class vtable, check the scalar-delete flag, and conditionally call the delete helper with size `0x14`.

## Source-Layout Implication

Both classes have compact two-slot vtables and share the same [UID:0001TS][BinaryCodecCursorLayout](by-type/by-struct/BinaryCodecCursorLayout.md) field pattern. The vtable adjacency supports a paired utility source family, either separate `util/Encoder.cpp` / `util/Decoder.cpp` files or one compact `util/BinaryCodec.cpp`. It does not support assigning the codec methods to packet, DAT, or text-edit feature modules.

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

- What existed before: the page had strong vtable content but remained scored as unevaluated and reconstructability was not marked.
- What it was changed to: the page is now marked reconstructable, scored `84/90`, and slot targets now link to the exact memory pages.
- Summary/evidence: 2026-05-31 IDA MCP reconfirmed the Encoder and Decoder vtable slots, constructor/destructor vptr-store xrefs, no-op bodies, deleting-destructor bodies, RTTI adjacency, and the `0x006192e0` non-vtable boundary.
