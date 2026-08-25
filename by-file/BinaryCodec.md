*** UID:0000HQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# BinaryCodec

## 2026-08-15 Whole-File Resolution

This page is the sole retained source root for `NexusTK/util/BinaryCodec.cpp` and required sibling `BinaryCodec.h`. The earlier three-root `BinaryCodec.cpp`/`Encoder.cpp`/`Decoder.cpp` hypothesis is preserved only as superseded research: contiguous mirrored code, paired RTTI/vtables, common dependencies, absent embedded path evidence, and the complete source-order inventory support one compilation unit containing standalone `Encoder` followed by standalone `Decoder`.

The final inventory is 36 authored methods, two compiler scalar-deleting wrappers, two exact RTTI/vtable records, and 38 internal/terminal `0xcc` alignment gaps. All 18 Encoder and all 18 Decoder definitions route through their direct class pages into this root. Encoder positions 3/6/8/9/10/11/12/14/15 are the newly documented raw children [UID:000512][0x004a4eb0-0x004a4ebd.EncoderSetByteOrder](by-memory/0x004a4eb0-0x004a4ebd.EncoderSetByteOrder.md), [UID:000514][0x004a4f60-0x004a4fe3.EncoderWriteTriByte](by-memory/0x004a4f60-0x004a4fe3.EncoderWriteTriByte.md), [UID:000513][0x004a5070-0x004a50e3.EncoderWriteWideString8](by-memory/0x004a5070-0x004a50e3.EncoderWriteWideString8.md), [UID:000515][0x004a50f0-0x004a5189.EncoderWriteWideString16](by-memory/0x004a50f0-0x004a5189.EncoderWriteWideString16.md), [UID:000516][0x004a5190-0x004a5293.EncoderWriteAnsiString8](by-memory/0x004a5190-0x004a5293.EncoderWriteAnsiString8.md), [UID:000517][0x004a52a0-0x004a53ca.EncoderWriteAnsiString16](by-memory/0x004a52a0-0x004a53ca.EncoderWriteAnsiString16.md), [UID:00051A][0x004a53d0-0x004a5472.EncoderWriteCString](by-memory/0x004a53d0-0x004a5472.EncoderWriteCString.md), [UID:000518][0x004a54d0-0x004a558d.EncoderWriteCompressedBytes](by-memory/0x004a54d0-0x004a558d.EncoderWriteCompressedBytes.md), and [UID:000519][0x004a5590-0x004a55b6.EncoderSkipBytes](by-memory/0x004a5590-0x004a55b6.EncoderSkipBytes.md). The broad memory pages remain non-emitting indexes; scalar wrappers and vtable/RTTI records are compiler consequences and never handwritten source.

Both classes are standalone 20-byte objects: vptr at `+0x00`, buffer pointer at `+0x04`, signed capacity/size at `+0x08`, signed cursor at `+0x0c`, one-byte `bool` big-endian selector at `+0x10`, one-byte writable/valid state at `+0x11`, and two bytes of natural tail alignment. Scalar payloads and zlib lengths retain unsigned types. No common base class is supported.

Current liveness is deliberately asymmetric. [UID:0000UM][EncodeTextEditState_0058E490](by-item/EncodeTextEditState_0058E490.md) is the sole live authored consumer: it constructs one Encoder in stack storage, attaches one 0x8000-byte buffer with usable capacity `0x7ffe`, writes text, NUL, `0x6b6f6e67`, and three size-prefixed tables, finalizes, then heap-copies exactly the returned byte count. This is state serialization, not network-packet ownership. Nine Encoder methods and the entire Decoder API have no surviving ordinary route but remain coherent retained source, not removable debris.

Dependencies remain `MemoryMan::MemmoveWrapper`, Win32 ACP conversion, zlib `compress`/`uncompress`, CRT allocation/memory/wide-string operations, and compiler support. The family owns no source global/static/string/resource/enum/table beyond compiler RTTI/vtables. `0x006192e0` begins an unrelated ParseEntries table and is excluded. Behavioral reconstruction preserves reserve-byte inequalities, signed cursors/counts, ignored conversion/zlib status, both observed Encoder leak paths, and the Encoder/Decoder Finalize asymmetry.

The `94/93` score reflects complete ordinary source/header reconstruction, exact ranges/hashes/callers/dependencies, and generated-output readiness. Retail lexical spellings and the original object-file name remain unavailable and cap final confidence below 95.

## Dated Superseded Status

- Confidence: strong for the modeled `Encoder` method family, shared cursor layout, compact vtables, exact Decoder raw-reader children, and neighboring padding/DAT boundary.
- Confidence: medium-high for full live `Decoder` reachability because the raw reader bodies are clear project code but still have no IDA function objects or direct caller xrefs.
- Proposed module: `NexusTK/util/BinaryCodec.cpp` with required `BinaryCodec.h`; this page is the final source root rather than a coordinator-only placeholder.
- C++ reconstruction: complete through [UID:00004F][Encoder](by-class/Encoder.md) and [UID:00003M][Decoder](by-class/Decoder.md), whose CPP/H channels and exact authored children assemble the source and header without duplicate class-level method bodies.
- Main classes: [UID:00004F][Encoder](by-class/Encoder.md) and [UID:00003M][Decoder](by-class/Decoder.md)
- Main memory docs: [UID:00013D][0x004a4e70-0x004a5621.EncoderCore](by-memory/0x004a4e70-0x004a5621.EncoderCore.md), [UID:00013M][0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue](by-memory/0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue.md), and [UID:00013Q][0x004a5680-0x004a5dce.DecoderRawReaderFamily](by-memory/0x004a5680-0x004a5dce.DecoderRawReaderFamily.md)
- Type docs: [UID:0001TS][BinaryCodecCursorLayout](by-type/by-struct/BinaryCodecCursorLayout.md) and [UID:0001X1][BinaryCodecVtables](by-type/by-vtable/BinaryCodecVtables.md)
- Evidence basis: live IDA MCP function, xref, vtable, padding, raw-disassembly, and exact-child split checks through the 2026-06-27 B009 [UID:00013M][0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue](by-memory/0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue.md) refresh.
- 2026-06-27 B009 [UID:00013M][0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue](by-memory/0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue.md) refresh: current MCP session `b001_000241_20260627` reconfirms the glue page as a non-emitting BinaryCodec family/index page; exact Encoder and Decoder child pages remain the source-owned emitters where applicable.
- 2026-06-21 B006 vtable-family recheck: [UID:0001X1][BinaryCodecVtables](by-type/by-vtable/BinaryCodecVtables.md) is now recommended `88/92` while still emitting only an empty marker through this coordinator. Exact vtable-data children stay class-owned by [UID:00004F][Encoder](by-class/Encoder.md) and [UID:00003M][Decoder](by-class/Decoder.md); this file owns the paired family explanation, shared cursor/vtable relationship, and source-placement boundary.

## Dated Superseded File Role

This utility layer provides small in-memory binary stream helpers. `Encoder` writes primitive values and raw byte blocks into a caller-owned buffer, tracks overflow with a validity flag, and can swap 16-bit and 32-bit integer byte order. `Decoder` is the mirror reader: it consumes a caller-owned byte buffer, advances a read cursor, and invalidates itself when a read overruns the available data.

Current live xref evidence is asymmetric. IDA finds direct `Encoder` consumer calls from [UID:0000UM][EncodeTextEditState_0058E490](by-item/EncodeTextEditState_0058E490.md), but the raw `Decoder` reader starts in `0x004a5680-0x004a5db0` still have no inbound code/data refs. Treat `Decoder` as real retained project code, but keep the exact live/dead status open until caller recovery improves.

## Dated Superseded Proposed Contents

| Entity | Address evidence | Proposed placement | Notes |
| --- | --- | --- | --- |
| `Encoder` | [UID:00013D][0x004a4e70-0x004a5621.EncoderCore](by-memory/0x004a4e70-0x004a5621.EncoderCore.md), no-op `0x004a5630`, scalar deleting destructor `0x004a5e30`, vtable `0x006192cc` | `NexusTK/util/Encoder.cpp` | Writes byte, short, int, and raw byte spans; [UID:00013E][0x004a4ea0-0x004a4ea7.EncoderDestructor](by-memory/0x004a4ea0-0x004a4ea7.EncoderDestructor.md) emits the empty ordinary source destructor and leaves scalar-delete glue to the compiler; [UID:00013G][0x004a4f00-0x004a4f59.EncoderWriteShort](by-memory/0x004a4f00-0x004a4f59.EncoderWriteShort.md) emits exact `void Encoder::WriteShort(unsigned short value)` with the same final-NUL reserve and byte-order model as the sibling scalar writers; [UID:00013J][0x004a55c0-0x004a55de.EncoderInitialize](by-memory/0x004a55c0-0x004a55de.EncoderInitialize.md) attaches caller-owned output storage and preserves byte-order state; [UID:00013K][0x004a55e0-0x004a5621.EncoderFinalize](by-memory/0x004a55e0-0x004a5621.EncoderFinalize.md) is exact `bool Encoder::Finalize(unsigned int *outBytesWritten)`, reports a 32-bit byte count, appends the trailing NUL byte, detaches caller-owned storage, and emits from its exact child page. |
| `Decoder` | [UID:00013M][0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue](by-memory/0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue.md), ordinary destructor [UID:00013O][0x004a5670-0x004a5677.DecoderDestructor](by-memory/0x004a5670-0x004a5677.DecoderDestructor.md), raw readers [UID:00013Q][0x004a5680-0x004a5dce.DecoderRawReaderFamily](by-memory/0x004a5680-0x004a5dce.DecoderRawReaderFamily.md), exact primitive children [UID:0003K8][0x004a5680-0x004a568d.DecoderSetByteOrder](by-memory/0x004a5680-0x004a568d.DecoderSetByteOrder.md)-[UID:0003KC][0x004a5770-0x004a57dc.DecoderReadInt](by-memory/0x004a5770-0x004a57dc.DecoderReadInt.md), exact string/blob children [UID:0003L6][0x004a57e0-0x004a5861.DecoderReadWideString8](by-memory/0x004a57e0-0x004a5861.DecoderReadWideString8.md)-[UID:0003LE][0x004a5db0-0x004a5dce.DecoderInitialize](by-memory/0x004a5db0-0x004a5dce.DecoderInitialize.md), vtable `0x006192d8` | `NexusTK/util/Decoder.cpp` | Reads byte, 16-bit, 24-bit, 32-bit, length-prefixed strings, NUL-terminated strings, raw spans, compressed spans, skip, and initialize data. [UID:00013O][0x004a5670-0x004a5677.DecoderDestructor](by-memory/0x004a5670-0x004a5677.DecoderDestructor.md) now mirrors the Encoder destructor policy by emitting the ordinary empty `Decoder::~Decoder()` body through the Decoder route, while [UID:00013U][0x004a5e00-0x004a5e24.DecoderScalarDeletingDestructor](by-memory/0x004a5e00-0x004a5e24.DecoderScalarDeletingDestructor.md) remains compiler-generated wrapper support. |
| `BinaryCodecVtables` | [UID:0001X1][BinaryCodecVtables](by-type/by-vtable/BinaryCodecVtables.md), exact data children [UID:0003IA][0x006192c8-0x006192d4.EncoderVtableData](by-memory/0x006192c8-0x006192d4.EncoderVtableData.md) and [UID:0003IB][0x006192d4-0x006192e0.DecoderVtableData](by-memory/0x006192d4-0x006192e0.DecoderVtableData.md), boundary [UID:0003IC][0x006192e0-0x00619340.ParseEntriesConstantTable](by-memory/0x006192e0-0x00619340.ParseEntriesConstantTable.md) | Coordinator only; exact data belongs with `Encoder.cpp` / `Decoder.cpp` class ownership | Paired family record for RTTI/vtable adjacency, scalar deleting destructor slots, one-byte no-op virtual slots, and the `0x006192e0` DAT parser constant-table boundary. Formal C++ stays blank; source should declare virtual destructors and descriptive no-op virtual placeholders in the class docs, not emit handwritten vtable dwords. |
| `EncodeTextEditState` | `0x0058e490-0x0058e691` | [UID:0000ON][TextEditPane](by-file/TextEditPane.md) | Sole confirmed direct behavioral `Encoder` consumer; serializes text-edit run tables into a heap buffer. |

## Live IDA Evidence

2026-06-04 IDA MCP checks confirmed:

- Modeled `Encoder` boundaries:
  - `0x004a4e70-0x004a4e94` constructor, vtable store `0x006192cc`, clears `+0x04/+0x08/+0x0c`, writes flags word `0x0101` at `+0x10`.
  - `0x004a4ea0-0x004a4ea7` destructor, restores vtable `0x006192cc`.
  - `0x004a4ec0-0x004a4ef1`, `0x004a4f00-0x004a4f59`, `0x004a4ff0-0x004a506b`, and `0x004a5480-0x004a54c6` write byte/short/int/raw-span data while checking `+0x08`, advancing `+0x0c`, honoring `+0x10`, and clearing `+0x11` on overflow.
  - `0x004a55c0-0x004a55de` initializes buffer/size/cursor/valid fields.
  - `0x004a55e0-0x004a5621` returns prior valid state, reports cursor, writes the final NUL, clears buffer/size/cursor, and resets valid.
- Direct `Encoder` calls are from `0x0058e490-0x0058e691`: constructor at `0x0058e4e4`, initialize at `0x0058e54b`, `WriteBytes` at `0x0058e56e`/`0x0058e5ba`/`0x0058e5e3`/`0x0058e612`, `WriteByte` at `0x0058e57b`, `WriteInt` at `0x0058e58b`, `WriteShort` at `0x0058e59a`/`0x0058e5c9`/`0x0058e5f8`, finalize at `0x0058e624`, and destructor at `0x0058e66c`.
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
- 2026-06-20 B003/B004 Rule 26 reanalysis promotes exact Encoder child [UID:00013J][0x004a55c0-0x004a55de.EncoderInitialize](by-memory/0x004a55c0-0x004a55de.EncoderInitialize.md) to first-draft `void Encoder::Initialize(unsigned char *buffer, unsigned int capacity)` readiness. The coordinator remains non-emitting, but the child now has exact bytes, one direct TextEditPaneSerialization caller at `0x0058e54b`, no callees, no VA/RVA start-pointer route, and source-facing field directions for `m_outputBuffer`, `m_capacity` / `m_outputCapacity`, `m_writePos`, `m_useBigEndian`, and `m_isWritable` / `m_isValid`. B004 independently verified the method from the hash-matched local PE while IDA MCP was unavailable.
- 2026-06-21 B008 Rule 26 reanalysis promotes exact Encoder child [UID:00013K][0x004a55e0-0x004a5621.EncoderFinalize](by-memory/0x004a55e0-0x004a5621.EncoderFinalize.md) to first-draft `bool Encoder::Finalize(unsigned int *outBytesWritten)` readiness. The coordinator remains non-emitting, but the child now has exact local PE bytes, one direct TextEditPaneSerialization caller at `0x0058e624`, no callees, a proven 32-bit output-count pointer, previous-valid return, unconditional trailing-NUL write, buffer/capacity/cursor reset, unchanged byte-order flag, and rejected no-code/BinaryCodec-direct/TextEditPane ownership alternatives.
- 2026-06-21 B011 Rule 26 recheck for exact Encoder child [UID:00013K][0x004a55e0-0x004a5621.EncoderFinalize](by-memory/0x004a55e0-0x004a5621.EncoderFinalize.md) confirms the same coordinator boundary from exported IDA/Ghidra artifacts. `BinaryCodec` remains family context only; `Encoder::Finalize` stays owned by [UID:00004F][Encoder](by-class/Encoder.md) and emitted through [UID:0000J1][Encoder](by-file/Encoder.md), with no split or ownership reclassification needed.
- 2026-06-21 B009 Rule 26 reanalysis promotes exact Encoder child [UID:00013H][0x004a4ff0-0x004a506b.EncoderWriteInt](by-memory/0x004a4ff0-0x004a506b.EncoderWriteInt.md) to first-draft `void Encoder::WriteInt(unsigned int value)` readiness. The coordinator remains non-emitting, but the child now records exact one-caller/no-callee source-bearing behavior, final-NUL reserve, big-endian default `"kong"` marker output, direct native little-endian dword store branch, raw helper-island exclusions, and rejected no-code/BinaryCodec-direct/TextEditPane ownership alternatives.
- 2026-06-21 B012 Rule 26 reanalysis promotes exact Encoder child [UID:00013G][0x004a4f00-0x004a4f59.EncoderWriteShort](by-memory/0x004a4f00-0x004a4f59.EncoderWriteShort.md) to first-draft `void Encoder::WriteShort(unsigned short value)` readiness. The coordinator remains non-emitting, but the child now records exact three-caller/no-callee source-bearing behavior, final-NUL reserve, default big-endian TextEditPane length-prefix output, direct native 16-bit store branch, adjacent raw `0x004a4f60-0x004a4fe3` 24-bit writer exclusion, and rejected no-code/BinaryCodec-direct/TextEditPane ownership alternatives.

2026-06-14 A001 live IDA MCP refresh in database `b001_0003gy` reconfirmed the coordinator state after the 2026-06-12 exact child split:

- `lookup_funcs` still models all `Encoder` starts from `0x004a4e70` through `0x004a55e0`, the `Encoder` no-op virtual at `0x004a5630`, the `Decoder` constructor/destructor/finalize/no-op/scalar-deleting destructor starts at `0x004a5640`, `0x004a5670`, `0x004a5dd0`, `0x004a5df0`, and `0x004a5e00`, and the `Encoder` scalar deleting destructor at `0x004a5e30`.
- `lookup_funcs` still reports every exact raw Decoder child start from `0x004a5680` through `0x004a5db0` as `Not a function`; `xrefs_to` still finds zero direct code/data refs to those raw starts.
- `xrefs_to` reconfirms Encoder vtable-base refs at `0x004a4e70`, `0x004a4ea0`, and `0x004a5e3a`, and Decoder vtable-base refs at `0x004a5640`, `0x004a5670`, and `0x004a5e0a`.
- `get_int` reconfirms the read-only sequence `0x006192c8 -> 0x00646b2c`, `0x006192cc -> 0x004a5e30`, `0x006192d0 -> 0x004a5630`, `0x006192d4 -> 0x00646b74`, `0x006192d8 -> 0x004a5e00`, `0x006192dc -> 0x004a5df0`, and `0x006192e0 -> 0x1a`.
- `xrefs_to(0x006192e0)` still has only the DAT helper reference at `0x004a5e9e`, and `lookup_funcs(0x004a5e60)` returns the adjacent DAT parser helper, preserving the codec/DAT boundary.
- Padding bytes remain stable at `0x004a5621-0x004a5630`, `0x004a5dce-0x004a5dd0`, and `0x004a5e54-0x004a5e60`.

2026-06-27 B009 live IDA MCP refresh for [UID:00013M][0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue](by-memory/0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue.md) reconfirmed the coordinator evidence basis:

- Active MCP session `b001_000241_20260627` reported health OK for `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
- `lookup_funcs` and function inventory still model the same glue/lifecycle starts at `0x004a5630`, `0x004a5640`, `0x004a5670`, `0x004a5dd0`, `0x004a5df0`, `0x004a5e00`, and `0x004a5e30`, with adjacent `0x004a5e60` remaining the DAT helper outside the codec page.
- The raw Decoder starts from `0x004a5680` through `0x004a5db0` still have no IDA function objects, zero incoming refs, and no VA/RVA pointer routes. This remains a confidence cap for raw-reader reachability, not a reason to emit from the BinaryCodec coordinator.
- Vtable data remains the same compact Encoder/Decoder sequence at `0x006192c8-0x006192dc`, and `0x006192e0 -> 0x1a` remains adjacent DAT constant data referenced from `0x004a5e9e`.
- The page-level outcome is unchanged: BinaryCodec remains the shared family coordinator; [UID:00013M][0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue](by-memory/0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue.md) stays a non-emitting index; exact Encoder and Decoder children remain the source-owned emitters where applicable.

2026-06-29 B001 implementation of [UID:00013O][0x004a5670-0x004a5677.DecoderDestructor](by-memory/0x004a5670-0x004a5677.DecoderDestructor.md) syncs the Decoder ordinary destructor with the existing Encoder destructor policy:

- Current MCP session `279422f0` confirms UID00013O as exact `sub_4A5670`, size `0x7`, bytes `c7 01 d8 92 61 00 c3`, a vtable-restore-only body with no callees, callers, strings, cleanup writes, or VA/RVA pointer route.
- The exact child emits first-draft `Decoder::~Decoder()` through [UID:00003M][Decoder](by-class/Decoder.md) and [UID:0000IQ][Decoder](by-file/Decoder.md); this coordinator remains non-emitting shared family context.
- [UID:00013U][0x004a5e00-0x004a5e24.DecoderScalarDeletingDestructor](by-memory/0x004a5e00-0x004a5e24.DecoderScalarDeletingDestructor.md) remains MSVC scalar deleting destructor wrapper support generated from `virtual ~Decoder()`, not handwritten BinaryCodec or Decoder source.

## Ownership Boundaries

Keep [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md) in `network/PacketBuffer.cpp`: it owns packet/network buffer behavior and should not absorb these generic in-memory codec helpers unless later caller evidence proves the original project did so. Keep [UID:0000ON][TextEditPane](by-file/TextEditPane.md) ownership for [UID:0000UM][EncodeTextEditState_0058E490](by-item/EncodeTextEditState_0058E490.md): it is a text-edit serializer that consumes `Encoder`, not a codec method.

Do not merge this with [UID:0000IN][DATFile](by-file/DATFile.md). `DATFile` is an archive-backed file implementation, and `0x004a5e60` is a physically adjacent DAT parser helper after the codec padding boundary.

[UID:0001X1][BinaryCodecVtables](by-type/by-vtable/BinaryCodecVtables.md) strengthens the coordinator role but does not make this file the direct owner of exact class vtable dwords. The exact children are class-owned, while this page preserves why a paired BinaryCodec family remains the least misleading way to discuss shared cursor layout, adjacent RTTI/vtable placement, and the common virtual surface.

## Cross-References

- [UID:00004F][Encoder](by-class/Encoder.md)
- [UID:00003M][Decoder](by-class/Decoder.md)
- [UID:0000J1][Encoder](by-file/Encoder.md)
- [UID:0000IQ][Decoder](by-file/Decoder.md)
- [UID:00013D][0x004a4e70-0x004a5621.EncoderCore](by-memory/0x004a4e70-0x004a5621.EncoderCore.md)
- [UID:00013M][0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue](by-memory/0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue.md)
- [UID:00013Q][0x004a5680-0x004a5dce.DecoderRawReaderFamily](by-memory/0x004a5680-0x004a5dce.DecoderRawReaderFamily.md)
- [UID:0003K8][0x004a5680-0x004a568d.DecoderSetByteOrder](by-memory/0x004a5680-0x004a568d.DecoderSetByteOrder.md)
- [UID:0003KC][0x004a5770-0x004a57dc.DecoderReadInt](by-memory/0x004a5770-0x004a57dc.DecoderReadInt.md)
- [UID:0003L6][0x004a57e0-0x004a5861.DecoderReadWideString8](by-memory/0x004a57e0-0x004a5861.DecoderReadWideString8.md)
- [UID:0003LE][0x004a5db0-0x004a5dce.DecoderInitialize](by-memory/0x004a5db0-0x004a5dce.DecoderInitialize.md)
- [UID:0001TS][BinaryCodecCursorLayout](by-type/by-struct/BinaryCodecCursorLayout.md)
- [UID:0001X1][BinaryCodecVtables](by-type/by-vtable/BinaryCodecVtables.md)
- [UID:0000UM][EncodeTextEditState_0058E490](by-item/EncodeTextEditState_0058E490.md)
- [UID:0000ON][TextEditPane](by-file/TextEditPane.md)

## Changes

- 2026-06-29 B001 [UID:00013O][0x004a5670-0x004a5677.DecoderDestructor](by-memory/0x004a5670-0x004a5677.DecoderDestructor.md) implementation:
  - Before/after coordinator score unchanged: `86/88`.
  - Summary/evidence: synced the coordinator with the exact Decoder child decision: UID00013O now emits first-draft empty `Decoder::~Decoder()` through [UID:0000IQ][Decoder](by-file/Decoder.md), while this BinaryCodec page stays a non-emitting family coordinator and [UID:00013U][0x004a5e00-0x004a5e24.DecoderScalarDeletingDestructor](by-memory/0x004a5e00-0x004a5e24.DecoderScalarDeletingDestructor.md) remains compiler-generated wrapper support. Current MCP session `279422f0` confirms the destructor's exact seven-byte vtable-restore-only body, no cleanup, no callees/callers/strings, unique signature, no pointer route, and vtable-base refs shared with constructor/scalar deleting destructor.
- 2026-06-27 B009 [UID:00013M][0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue](by-memory/0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue.md) implementation callback:
  - Before/after coordinator score unchanged: `86/88`.
  - Summary/evidence: updated the coordinator evidence basis so it no longer stops at 2026-06-14. Current MCP session `b001_000241_20260627` reconfirms the target glue page as a non-emitting BinaryCodec family/index page, with stable modeled glue/lifecycle functions, raw Decoder no-function/no-incoming-ref/no-pointer-route evidence, compact Encoder/Decoder vtable dwords, the `0x006192e0` DAT boundary, and padding envelopes. Exact child pages remain the source-owned emitters where applicable; no BinaryCodec score, source-root, ownership, or C++ change is needed.
- 2026-06-25 B004 [UID:00013R][0x004a57e0-0x004a5dce.DecoderStringAndBlobReaders](by-memory/0x004a57e0-0x004a5dce.DecoderStringAndBlobReaders.md) implementation wording cleanup:
  - Before/after coordinator score unchanged: `86/88`.
  - Summary/evidence: updated the Decoder proposed-contents wording from the stale "transformed spans" phrasing to compressed spans plus skip/initialize data, matching the accepted [UID:0003LC][0x004a5cd0-0x004a5d79.DecoderReadCompressedBytes](by-memory/0x004a5cd0-0x004a5d79.DecoderReadCompressedBytes.md) child disposition while keeping this page as the non-emitting BinaryCodec family coordinator.
- 2026-06-21 Rule 26 incorporation of B012 [UID:00013G][0x004a4f00-0x004a4f59.EncoderWriteShort](by-memory/0x004a4f00-0x004a4f59.EncoderWriteShort.md) report:
  - Before/after coordinator score unchanged: `86/88`.
  - Summary/evidence: synced the coordinator with the exact Encoder child decision: [UID:00013G][0x004a4f00-0x004a4f59.EncoderWriteShort](by-memory/0x004a4f00-0x004a4f59.EncoderWriteShort.md) now emits first-draft `Encoder::WriteShort(unsigned short value)` through [UID:0000J1][Encoder](by-file/Encoder.md), while this coordinator stays non-emitting. B012 confirms the `m_outputBuffer`/`m_capacity`/`m_writePos`/`m_useBigEndian`/`m_isWritable` field roles, final-NUL reserve, high-byte-first TextEditPane prefix output, native-store branch, and adjacent raw 24-bit writer boundary.

- 2026-06-21 B006 [UID:0001X1][BinaryCodecVtables](by-type/by-vtable/BinaryCodecVtables.md) source-quality incorporation:
  - Before/after coordinator score unchanged: `86/88`.
  - Summary/evidence: [UID:0001X1][BinaryCodecVtables](by-type/by-vtable/BinaryCodecVtables.md) now records `88/92` vtable-family evidence: exact Encoder/Decoder RTTI and vtable dwords, class-owned exact vtable data children, one-byte no-op virtual slots, generated scalar deleting destructor slots, and `0x006192e0` as the DAT parser constant-table boundary. This file remains the family coordinator and intentionally does not emit handwritten vtable tables.
- 2026-06-21 Rule 26 incorporation of B009 [UID:00013H][0x004a4ff0-0x004a506b.EncoderWriteInt](by-memory/0x004a4ff0-0x004a506b.EncoderWriteInt.md) report:
  - Before/after coordinator score unchanged: `86/88`.
  - Summary/evidence: synced the coordinator with the exact Encoder child decision: [UID:00013H][0x004a4ff0-0x004a506b.EncoderWriteInt](by-memory/0x004a4ff0-0x004a506b.EncoderWriteInt.md) now emits first-draft `Encoder::WriteInt(unsigned int value)` through [UID:0000J1][Encoder](by-file/Encoder.md), while this coordinator stays non-emitting. B009 confirms the `m_outputBuffer`/`m_capacity`/`m_writePos`/`m_useBigEndian`/`m_isWritable` field roles, final-NUL reserve, big-endian TextEditPane marker output, native-store branch, and raw helper-island boundaries.
- 2026-06-21 Rule 26 incorporation of B010 [UID:00013E][0x004a4ea0-0x004a4ea7.EncoderDestructor](by-memory/0x004a4ea0-0x004a4ea7.EncoderDestructor.md) report:
  - Before/after coordinator score unchanged: `86/88`.
  - Summary/evidence: synced the coordinator with the exact Encoder child decision: [UID:00013E][0x004a4ea0-0x004a4ea7.EncoderDestructor](by-memory/0x004a4ea0-0x004a4ea7.EncoderDestructor.md) now emits the empty ordinary source destructor through [UID:0000J1][Encoder](by-file/Encoder.md), while this coordinator stays non-emitting and [UID:00013V][0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor](by-memory/0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor.md) remains generated wrapper support.
- 2026-06-22 Rule 26 incorporation of B013 [UID:00013E][0x004a4ea0-0x004a4ea7.EncoderDestructor](by-memory/0x004a4ea0-0x004a4ea7.EncoderDestructor.md) report:
  - Before/after coordinator score unchanged: `86/88`.
  - Summary/evidence: B013 confirms the same coordinator boundary after the exact destructor child was already implemented: BinaryCodec remains shared family context only, not the direct owner/emitter for the ordinary `Encoder::~Encoder` body. The exact child stays owned by [UID:00004F][Encoder](by-class/Encoder.md) and emitted through [UID:0000J1][Encoder](by-file/Encoder.md), with TextEditPane as caller/consumer evidence and scalar deleting destructor glue kept compiler-generated. The old code-gate issue is already resolved here by the active exact-child combined-score/emitter wording.
- 2026-06-14 A001 coordinator sync:
  - Before: scored `80/86`; the page predated the 2026-06-12 exact raw-reader child split in its inventory and still used old `95/95` code-gate wording.
  - After: scored `86/88`; the coordinator now links the exact primitive and string/blob Decoder children, records a 2026-06-14 live IDA refresh, and uses the active exact-child combined-score/emitter code-entry gate.
  - Evidence: live IDA MCP `lookup_funcs`, `xrefs_to`, `get_int`, and `get_bytes` reconfirm modeled Encoder/Decoder lifecycle starts, raw Decoder no-function/no-xref status, compact vtable dwords and store refs, padding envelopes, and the adjacent DAT helper boundary. Final C++ remains blank because this is a family coordinator and final method names/signatures are still gated at the exact children.
- 2026-06-04: Raised grading from `72/82` to `80/86`.
  - Before: the page still carried stale non-live provenance wording and older evidence blocks, and its score understated the now-documented layout/vtable/memory evidence.
  - After: the page uses live IDA MCP evidence for modeled `Encoder`/`Decoder` boundaries, raw `Decoder` non-function/no-xref status, direct `Encoder` consumer calls, shared cursor offsets, compact vtables, read-only data boundary, and padding envelopes.
  - Score rationale: completion increased because the coordinator now cleanly records the full source-family shape and ownership boundaries. It remains below final-code level because raw `Decoder` readers still lack IDA function objects/callers and the final separate-vs-paired original file split remains unresolved.
- 2026-06-20 Rule 26 incorporation of B003 [UID:00013J][0x004a55c0-0x004a55de.EncoderInitialize](by-memory/0x004a55c0-0x004a55de.EncoderInitialize.md) report:
  - Before/after coordinator score unchanged: `86/88`.
  - Summary/evidence: the coordinator wording now distinguishes family-page non-emission from exact-child code readiness. [UID:00013J][0x004a55c0-0x004a55de.EncoderInitialize](by-memory/0x004a55c0-0x004a55de.EncoderInitialize.md) is an `Encoder.cpp` child with exact attach/reset semantics and draft C++, while [UID:0000HQ] remains the shared BinaryCodec family coordinator for Encoder/Decoder layout, vtables, and source-root boundaries.
- 2026-06-20 Rule 26 incorporation of B004 [UID:00013J][0x004a55c0-0x004a55de.EncoderInitialize](by-memory/0x004a55c0-0x004a55de.EncoderInitialize.md) report:
  - Before/after coordinator score unchanged: `86/88`.
  - Summary/evidence: B004 revalidated the exact child, rejected BinaryCodec as the direct owner for this method, and kept this page as a coordinator while [UID:00004F][Encoder](by-class/Encoder.md) and [UID:0000J1][Encoder](by-file/Encoder.md) carry the emitting route. Field aliases and the unsplit adjacent raw helper islands remain documented as final-audit blockers rather than reasons to suppress the exact child draft C++.
- 2026-06-21 Rule 26 incorporation of B008 [UID:00013K][0x004a55e0-0x004a5621.EncoderFinalize](by-memory/0x004a55e0-0x004a5621.EncoderFinalize.md) report:
  - Before/after coordinator score unchanged: `86/88`.
  - Summary/evidence: B008 revalidated the exact child, rejected BinaryCodec as the direct owner for this method, and kept this page as a coordinator while [UID:00004F][Encoder](by-class/Encoder.md) and [UID:0000J1][Encoder](by-file/Encoder.md) carry the emitting route. The exact child now records first-draft C++ with `unsigned int *outBytesWritten`; the caller's later 16-bit size store remains TextEditPane-side behavior and does not change the Encoder signature.
- 2026-06-21 Rule 26 incorporation check of B011 [UID:00013K][0x004a55e0-0x004a5621.EncoderFinalize](by-memory/0x004a55e0-0x004a5621.EncoderFinalize.md) report:
  - Before/after coordinator score unchanged: `86/88`.
  - Summary/evidence: B011 independently confirmed the B008 coordinator decision with exported IDA/Ghidra facts. This page still does not emit coordinator C++; the exact child carries the method body, while this coordinator records family context and the rejected BinaryCodec-direct ownership alternative.
