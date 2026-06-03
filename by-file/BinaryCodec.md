*** UID:0000HQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# BinaryCodec

## Status

- Confidence: strong for `Encoder`, medium for the full `Decoder` method set.
- Proposed modules: `util/Encoder.cpp` and `util/Decoder.cpp`, with `NexusTK/util/BinaryCodec.cpp` kept as a source-family coordination root until final source evidence proves whether the helpers were split or paired.
- Current recovered files: `source-3/simroot_v2/class_Encoder.cpp` and `source-3/simroot_v2/class_Decoder.cpp`
- Generated root: `auto-generated/NexusTK/util/BinaryCodec.cpp`; keep this C++ file blank while the concrete code-bearing roots remain [UID:00004F][Encoder](by-class/Encoder.md) and [UID:00003M][Decoder](by-class/Decoder.md).
- Main classes: [UID:00004F][Encoder](by-class/Encoder.md) and [UID:00003M][Decoder](by-class/Decoder.md)
- Main memory docs: [UID:00013D][0x004a4e70-0x004a5621.EncoderCore](by-memory/0x004a4e70-0x004a5621.EncoderCore.md) and [UID:00013M][0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue](by-memory/0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue.md)
- Type docs: [UID:0001TS][BinaryCodecCursorLayout](by-type/by-struct/BinaryCodecCursorLayout.md) and [UID:0001X1][BinaryCodecVtables](by-type/by-vtable/BinaryCodecVtables.md)
- Evidence basis: `simroot_v2` generated source/metadata as leads, with IDA MCP lookup, vtable, decompilation, disassembly, and xref checks on 2026-05-24, 2026-05-25, 2026-05-26, 2026-05-31, and 2026-06-03.

## File Role

This utility layer provides small in-memory binary stream helpers. `Encoder` writes primitive values and raw byte blocks into a caller-owned buffer, tracks overflow with a validity flag, and can swap 16-bit and 32-bit integer byte order. `Decoder` is the mirror reader: it consumes a caller-owned byte buffer, advances a read cursor, and invalidates itself when a read overruns the available data.

Current live xref evidence is asymmetric. IDA finds a direct `Encoder` consumer at [UID:0000UM][EncodeTextEditState_0058E490](by-item/EncodeTextEditState_0058E490.md), but most `Decoder` routines in `0x004a5680-0x004a5db0` are raw code heads rather than IDA-modeled functions and have no direct xrefs in the current database. Treat `Decoder` as real retained project code, but keep the exact live/dead status open until caller recovery improves.

## Proposed Contents

| Entity | Address evidence | Proposed placement | Notes |
| --- | --- | --- | --- |
| `Encoder` | [UID:00013D][0x004a4e70-0x004a5621.EncoderCore](by-memory/0x004a4e70-0x004a5621.EncoderCore.md), plus [UID:00013L][0x004a5630-0x004a5631.EncoderNoopVirtual](by-memory/0x004a5630-0x004a5631.EncoderNoopVirtual.md), [UID:00013V][0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor](by-memory/0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor.md), and vtable `0x006192cc` | `util/Encoder.cpp` | Writes byte, short, int, and raw byte spans; finalizes with a trailing NUL byte. |
| `Decoder` | `0x004a5640-0x004a5e23`, including [UID:00013Q][0x004a5680-0x004a5dcf.DecoderRawReaderFamily](by-memory/0x004a5680-0x004a5dcf.DecoderRawReaderFamily.md) in `0x004a5680-0x004a5db0`, and vtable `0x006192d8` | `util/Decoder.cpp` | Reads byte, 16-bit, 24-bit, 32-bit, length-prefixed strings, NUL-terminated strings, and raw spans. |
| `EncodeTextEditState` | `0x0058e490-0x0058e690` | [UID:0000ON][TextEditPane](by-file/TextEditPane.md) | Sole confirmed `Encoder` caller; serializes text-edit run tables into a heap buffer. |

## Evidence Notes

- `Encoder` and `Decoder` share the same stream cursor layout through offset `+0x11`: vtable, buffer pointer, capacity/limit, cursor, byte-order flag, and valid flag. See [UID:0001TS][BinaryCodecCursorLayout](by-type/by-struct/BinaryCodecCursorLayout.md).
- `Encoder` initializes the flags word to `0x0101`: byte order enabled at offset `+0x10` and valid/writable state enabled at `+0x11`.
- `Encoder::Finalize` writes a NUL byte at the current cursor before clearing the attached buffer and returning the previous valid state.
- IDA vtable data shows `Encoder` has a two-slot vtable at `0x006192cc`: scalar deleting destructor `0x004a5e30` and one no-op virtual slot `0x004a5630`.
- IDA vtable data shows `Decoder` has a two-slot vtable at `0x006192d8`: scalar deleting destructor `0x004a5e00` and one no-op virtual slot `0x004a5df0`.
- IDA disassembly shows additional `Decoder` reader starts at `0x004a5680`, `0x004a5690`, `0x004a56c0`, `0x004a5710`, `0x004a5770`, `0x004a57e0`, `0x004a5870`, `0x004a5930`, `0x004a5a40`, `0x004a5bb0`, `0x004a5c80`, `0x004a5cd0`, `0x004a5d80`, and `0x004a5db0`; most are not formal IDA functions today.

2026-05-25 IDA MCP recheck:

- `lookup_funcs` still models `0x004a5630`, `0x004a5640`, `0x004a5670`, `0x004a5dd0`, `0x004a5df0`, `0x004a5e00`, `0x004a5e30`, and `0x0058e490`, while every raw reader start from `0x004a5680` through `0x004a5db0` remains `Not a function`.
- `xrefs_to` still shows the active Encoder write family is only called from [UID:0000UM][EncodeTextEditState_0058E490](by-item/EncodeTextEditState_0058E490.md); the raw Decoder reader starts have no xrefs in the current IDA database.
- Vtable memory still resolves to `Encoder` slots `0x004a5e30` and `0x004a5630`, and `Decoder` slots `0x004a5e00` and `0x004a5df0`.

2026-05-26 IDA MCP recheck:

- Modeled functions remain unchanged: `0x004a5630`, `0x004a5640`, `0x004a5670`, `0x004a5dd0`, `0x004a5df0`, `0x004a5e00`, `0x004a5e30`, and `0x0058e490`.
- All raw Decoder starts from `0x004a5680` through `0x004a5db0` still return `Not a function` from `lookup_funcs`, and `xrefs_to` still finds no direct references to those raw starts.
- Encoder writer/finalize methods are still only directly called by [UID:0000UM][EncodeTextEditState_0058E490](by-item/EncodeTextEditState_0058E490.md). The text-edit helper has one raw thunk xref at `0x00498c4a`, while formal `callers` remains empty.
- No ignored-ledger change is needed for the raw Decoder family: these are reconstructable raw/projected `Decoder` methods, not CRT, third-party, compiler glue, or impossible ranges.
- Vtable xrefs remain constructor/destructor-owned: `Encoder` vtable refs at `0x004a4e70`, `0x004a4ea0`, and `0x004a5e3a`; `Decoder` vtable refs at `0x004a5640`, `0x004a5670`, and `0x004a5e0a`.

2026-05-31 IDA MCP vtable/read-only-data recheck:

- `lookup_funcs` reconfirmed exact modeled ranges for the Decoder constructor/destructor/finalize/no-op/deleting-destructor functions and the Encoder no-op/deleting-destructor vtable glue.
- `py_eval` dword reads show the read-only block at `0x006192c8-0x006192dc` contains `Encoder` RTTI/vtable data followed by `Decoder` RTTI/vtable data.
- `xrefs_to 0x006192e0` reports the adjacent DAT parser/entry helper at `0x004a5e9e`, confirming that `0x006192e0` is not another BinaryCodec vtable slot.

2026-06-03 IDA MCP recheck:

- `lookup_funcs` still models the compact `Encoder` function family at `0x004a4e70`, `0x004a4ea0`, `0x004a4ec0`, `0x004a4f00`, `0x004a4ff0`, `0x004a5480`, `0x004a55c0`, and `0x004a55e0`, plus the no-op/scalar-deleting-destructor glue at `0x004a5630`, `0x004a5df0`, `0x004a5e00`, and `0x004a5e30`.
- Raw `Decoder` reader starts at `0x004a5680`, `0x004a5690`, `0x004a56c0`, `0x004a5710`, `0x004a5770`, `0x004a57e0`, and `0x004a5db0` still return `Not a function`, and `xrefs_to` remains empty for the raw reader starts through `0x004a5db0`.
- `callers` confirms the modeled `Encoder` write/finalize helpers are still only directly reached from [UID:0000UM][EncodeTextEditState_0058E490](by-item/EncodeTextEditState_0058E490.md); `0x004a5640` and `0x004a5dd0` have no callers in the current database.
- `py_eval` confirms `0x006192cc` points to `0x004a5e30` and `0x004a5630` for `Encoder`, while `0x006192d8` points to `0x004a5e00` and `0x004a5df0` for `Decoder`; padding from `0x004a5621-0x004a5630` and `0x004a5e54-0x004a5e60` remains `0xcc`.
- `xrefs_to 0x006192e0` and callers of `0x004a5e60` continue to tie the following constants to the adjacent DAT parser helper, not to another BinaryCodec vtable or source-owned method.

## Ownership Boundaries

Keep [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md) in `network/PacketBuffer.cpp`: it owns packet/network buffer behavior and should not absorb these generic in-memory codec helpers unless later caller evidence proves the original project did so. Keep [UID:0000ON][TextEditPane](by-file/TextEditPane.md) ownership for [UID:0000UM][EncodeTextEditState_0058E490](by-item/EncodeTextEditState_0058E490.md): it is a text-edit serializer that consumes `Encoder`, not a codec method.

Do not merge this with [UID:0000IN][DATFile](by-file/DATFile.md). `DATFile` is an archive-backed file implementation; `Encoder`/`Decoder` operate on caller-supplied memory buffers.

## Cross-References

- [UID:00004F][Encoder](by-class/Encoder.md)
- [UID:00003M][Decoder](by-class/Decoder.md)
- [UID:00013D][0x004a4e70-0x004a5621.EncoderCore](by-memory/0x004a4e70-0x004a5621.EncoderCore.md)
- [UID:00013M][0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue](by-memory/0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue.md)
- [UID:00013Q][0x004a5680-0x004a5dcf.DecoderRawReaderFamily](by-memory/0x004a5680-0x004a5dcf.DecoderRawReaderFamily.md)
- [UID:0001TS][BinaryCodecCursorLayout](by-type/by-struct/BinaryCodecCursorLayout.md)
- [UID:0001X1][BinaryCodecVtables](by-type/by-vtable/BinaryCodecVtables.md)
- [UID:0000UM][EncodeTextEditState_0058E490](by-item/EncodeTextEditState_0058E490.md)
- [UID:0000ON][TextEditPane](by-file/TextEditPane.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- What existed before: the page documented `Encoder`, raw `Decoder` readers, vtables, layout, and ownership boundaries but remained scored as unevaluated.
- What it was changed to: scores were set to `68/78`.
- Summary and evidence: `Encoder` is strongly supported by modeled functions and a confirmed consumer; `Decoder` remains reconstructable but lower-confidence because many reader starts are raw/unmodeled and currently lack direct xrefs.
- What existed before: the evidence notes stopped at the 2026-05-26 IDA pass and did not capture the current `0x006192e0` non-vtable boundary check.
- What it was changed to: the evidence basis now includes the 2026-05-31 IDA MCP vtable/read-only-data recheck and confidence was raised from `78` to `80`.
- Summary and evidence: IDA MCP dword/xref checks verified the compact `Encoder`/`Decoder` RTTI/vtable layout and the adjacent non-vtable constant boundary, while raw Decoder reader reachability remains unresolved.
- What existed before: the page remained at `68/80` with no proposed reconstruction path, even though the concrete `Encoder` and `Decoder` file roots were already staged under `NexusTK/util/`.
- What it was changed to: scores were raised to `72/82` and `PROPOSED_RECONSTRUCTION_PATH` was set to `NexusTK/util/` for a coordinating `BinaryCodec.cpp` root; no C++ body or child attachment is claimed for this coordinator.
- Summary and evidence: the 2026-06-03 IDA MCP pass reconfirmed modeled Encoder functions, raw/unxrefed Decoder reader starts, compact vtable dwords, padding boundaries, and the adjacent DAT parser boundary. Completion remains capped because Decoder reachability and the final original file split are still unresolved.
