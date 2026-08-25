*** UID:00004F | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "BinaryCodec.h"
#include "MemoryMan.h"
#include "../third_party/zlib/zlib.h"
#include <windows.h>
#include <memory.h>
#include <wchar.h>

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#pragma once

class Encoder
{
public:
    Encoder();
    virtual ~Encoder();

    void SetByteOrder(bool useBigEndian);
    void WriteByte(unsigned char value);
    void WriteShort(unsigned short value);
    void WriteTriByte(unsigned int value);
    void WriteInt(unsigned int value);
    void WriteWideString8(const wchar_t *text, int charCount = -1);
    void WriteWideString16(const wchar_t *text, int charCount = -1);
    void WriteAnsiString8(const wchar_t *text, int charCount = -1);
    void WriteAnsiString16(const wchar_t *text, int charCount = -1);
    void WriteCString(const wchar_t *text, int charCount = -1);
    void WriteBytes(const void *data, int byteCount);
    void WriteCompressedBytes(const void *data, int byteCount);
    void SkipBytes(int byteCount);
    void Initialize(unsigned char *buffer, int capacity);
    bool Finalize(unsigned int *outBytesWritten);
    virtual void NoopVirtual();

private:
    unsigned char *m_outputBuffer;
    int m_capacity;
    int m_writePos;
    bool m_useBigEndian;
    bool m_isWritable;
};

typedef char EncoderSizeMustBe20[(sizeof(Encoder) == 20) ? 1 : -1];
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# Encoder

## 2026-08-15 Complete Class And Route

`Encoder` is a standalone 20-byte class directly owned and emitted by [UID:0000HQ][BinaryCodec](by-file/BinaryCodec.md) at source position 1. The formal CPP preamble supplies all six required includes and `[[CHILDREN]]`; the formal H channel supplies the complete declaration and size assertion. All 18 definitions remain on exact by-memory children in address order, including new raw retained-dead UIDs 000512/000514/000513/000515/000516/000517/00051A/000518/000519.

The final fields are output buffer `+0x04`, signed `int` capacity `+0x08`, signed `int` write position `+0x0c`, `bool` big-endian selector `+0x10`, and `bool` writable state `+0x11`, followed by natural tail alignment. True means big-endian. The sole live caller uses 20 bytes of stack object storage and a single 0x8000-byte staging buffer at capacity `0x7ffe`; other authored API members are retained dead. No base class, separate Encoder source root, handwritten scalar deleting wrapper/vtable, unsigned cursor/count normalization, or leak cleanup is accepted.

Earlier declaration snippets, source-root links through UID0000J1, unsplit-helper caveats, and unresolved final-size/header questions are superseded historical research. Exact retail symbol spellings remain unproved and alone cap confidence below 95.

## Dated Superseded Status

- Confidence: strong; refreshed live IDA evidence now supports direct child routing for exact Encoder-owned data.
- Likely source file: [UID:0000J1][Encoder](by-file/Encoder.md), under the [UID:0000HQ][BinaryCodec](by-file/BinaryCodec.md) utility layer
- Autogen parent: [UID:0000J1][Encoder](by-file/Encoder.md)
- Main address evidence: [UID:00013D][0x004a4e70-0x004a5621.EncoderCore](by-memory/0x004a4e70-0x004a5621.EncoderCore.md) non-emitting split/index, exact vtable data in [UID:0003IA][0x006192c8-0x006192d4.EncoderVtableData](by-memory/0x006192c8-0x006192d4.EncoderVtableData.md), plus vtable glue in [UID:00013M][0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue](by-memory/0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue.md)
- Layout docs: [UID:0001TS][BinaryCodecCursorLayout](by-type/by-struct/BinaryCodecCursorLayout.md)
- Primary vtable: [UID:0001X1][BinaryCodecVtables](by-type/by-vtable/BinaryCodecVtables.md)
- Size/layout: observed fields span through offset `+0x11`; final source `sizeof` padding remains open.

## Class Purpose

`Encoder` is a caller-buffer binary writer. It appends primitive values and raw byte blocks to an attached buffer, tracks write position, and flips its valid/writable flag to false if a write would exceed the advertised capacity. It supports both native little-endian and swapped big-endian integer output through the byte-order flag at offset `+0x10`.

## Dated Superseded Declaration Direction

The current source-facing declaration direction is:

```cpp
class Encoder {
public:
    Encoder();
    virtual ~Encoder();
    virtual void NoopVirtual(); // descriptive placeholder for 0x004a5630

    void Initialize(unsigned char *buffer, unsigned int capacity);
    bool Finalize(unsigned int *outBytesWritten);
    void WriteByte(unsigned char value);
    void WriteShort(unsigned short value);
    void WriteInt(unsigned int value);
    void WriteBytes(const void *data, unsigned int byteCount);
};
```

`NoopVirtual` is not a proven original symbol. It is the best descriptive placeholder for the concrete one-byte `ret` body at [UID:00013L][0x004a5630-0x004a5631.EncoderNoopVirtual](by-memory/0x004a5630-0x004a5631.EncoderNoopVirtual.md), reached only by vtable slot `0x006192d0`; that exact child now emits the empty `Encoder::NoopVirtual()` body. Do not use raw `nullsub_27` as a source-quality name and do not model the slot as pure virtual. [UID:00013V][0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor](by-memory/0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor.md) is `90/93` compiler-generated MSVC scalar deleting destructor glue from `virtual ~Encoder()`; keep its formal C++ blank and do not emit a handwritten scalar deleting destructor body in source.

B010's [UID:00013E][0x004a4ea0-0x004a4ea7.EncoderDestructor](by-memory/0x004a4ea0-0x004a4ea7.EncoderDestructor.md) reanalysis confirms the ordinary source destructor itself is source-bearing and should emit an empty out-of-class body. The body does not free, detach, or reset the caller-owned output buffer; those responsibilities remain with `Finalize`.

## Observed State

```text
+0x00  vtable pointer (`0x006192cc`)
+0x04  output buffer pointer (`m_outputBuffer`; historical alias `m_buffer`)
+0x08  output buffer capacity (`m_capacity` / `m_outputCapacity`; historical alias `m_bufferCapacity`)
+0x0c  current write position (`m_writePos`; historical alias `m_cursor`)
+0x10  byte-order flag (`m_useBigEndian`); nonzero writes integer values big-endian
+0x11  valid/writable flag (`m_isWritable` / `m_isValid`)
```

The constructor initializes the flags word to `0x0101`, so new instances default to big-endian integer order and writable state.

## Dated Superseded Partial Method Inventory

| Address | Method | Notes |
| --- | --- | --- |
| [UID:00013C][0x004a4e70-0x004a4e94.EncoderConstructor](by-memory/0x004a4e70-0x004a4e94.EncoderConstructor.md) | `Encoder::Encoder()` | `87/91` exact source-bearing constructor; machine body installs the `Encoder` vtable, clears caller-buffer/capacity/cursor state, sets flags word `0x0101`, and now emits first-draft initializer-list C++ using `m_outputBuffer`, `m_capacity`, `m_writePos`, `m_useBigEndian`, and `m_isWritable`. |
| [UID:00013E][0x004a4ea0-0x004a4ea7.EncoderDestructor](by-memory/0x004a4ea0-0x004a4ea7.EncoderDestructor.md) | destructor | `87/92` exact source-bearing ordinary destructor; machine body restores the `Encoder` vtable, but source C++ is the empty `Encoder::~Encoder()` body and no owned buffer is freed. |
| [UID:00013F][0x004a4ec0-0x004a4ef1.EncoderWriteByte](by-memory/0x004a4ec0-0x004a4ef1.EncoderWriteByte.md) | `WriteByte(unsigned char value)` | `88/91` exact source-bearing byte writer; checks `m_isWritable`, requires `m_capacity >= m_writePos + 2` to preserve final-NUL space, writes one byte to `m_outputBuffer[m_writePos]`, clears writable state on overflow, and now emits first-draft method C++. |
| [UID:00013G][0x004a4f00-0x004a4f59.EncoderWriteShort](by-memory/0x004a4f00-0x004a4f59.EncoderWriteShort.md) | `WriteShort(unsigned short value)` | `88/90` exact source-bearing 16-bit scalar writer; checks `m_isWritable`, requires `m_capacity >= m_writePos + 3` to reserve the final NUL, writes high byte then low byte when `m_useBigEndian` is set, stores a native 16-bit word otherwise, and now emits first-draft method C++. |
| [UID:00013H][0x004a4ff0-0x004a506b.EncoderWriteInt](by-memory/0x004a4ff0-0x004a506b.EncoderWriteInt.md) | `WriteInt(unsigned int value)` | `88/91` exact source-bearing 32-bit scalar writer; checks `m_isWritable`, requires `m_capacity >= m_writePos + 5` to reserve the final NUL, writes MSB-to-LSB when `m_useBigEndian` is set, otherwise stores a native little-endian dword, and now emits first-draft method C++. |
| [UID:00013I][0x004a5480-0x004a54c6.EncoderWriteBytes](by-memory/0x004a5480-0x004a54c6.EncoderWriteBytes.md) | `WriteBytes(const void *data, unsigned int byteCount)` | Copies a caller-supplied byte span through the MemoryMan copy helper, reserves the final NUL byte for `Finalize`, clears valid/writable on overflow, and now carries first-draft C++ at `88/90`. |
| [UID:00013J][0x004a55c0-0x004a55de.EncoderInitialize](by-memory/0x004a55c0-0x004a55de.EncoderInitialize.md) | `Initialize(unsigned char *buffer, unsigned int capacity)` | Attaches caller buffer/capacity, resets write position, sets writable/valid flag, preserves byte-order flag, and now carries first-draft C++ at `88/92`. |
| [UID:00013K][0x004a55e0-0x004a5621.EncoderFinalize](by-memory/0x004a55e0-0x004a5621.EncoderFinalize.md) | `Finalize(unsigned int *outBytesWritten)` | `88/92` exact child; optionally reports the 32-bit write cursor, appends the reserved trailing NUL unconditionally, clears buffer/capacity/cursor, restores writable/valid state, returns the prior writable/valid state, and now carries first-draft method C++. |
| [UID:00013L][0x004a5630-0x004a5631.EncoderNoopVirtual](by-memory/0x004a5630-0x004a5631.EncoderNoopVirtual.md) | source-empty virtual | Vtable slot at `0x006192d0`; exact child emits empty `Encoder::NoopVirtual()` with descriptive/unproved original name. |
| [UID:00013V][0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor](by-memory/0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor.md) | scalar deleting destructor | `90/93` generated MSVC delete-flag wrapper from `virtual ~Encoder()`; formal C++ stays blank, [UID:00013E][0x004a4ea0-0x004a4ea7.EncoderDestructor](by-memory/0x004a4ea0-0x004a4ea7.EncoderDestructor.md) carries the empty ordinary `Encoder::~Encoder()` body, and no handwritten scalar wrapper belongs in source. |

## Evidence Notes

- IDA MCP confirms all active generated `Encoder` method starts and the scalar deleting destructor.
- IDA vtable inspection confirms the omitted no-op virtual at `0x004a5630`.
- B006 [UID:0001X1][BinaryCodecVtables](by-type/by-vtable/BinaryCodecVtables.md) recheck confirms exact vtable dwords `0x006192c8 -> 0x00646b2c`, `0x006192cc -> 0x004a5e30`, and `0x006192d0 -> 0x004a5630`; constructor/destructor/scalar-deleting-destructor vtable-store refs at `0x004a4e70`, `0x004a4ea0`, and `0x004a5e3a`; exported `0x004a5630` as a one-byte no-op with only the vtable data ref; and exported `0x004a5e30` as a 36-byte MSVC scalar deleting destructor wrapper.
- IDA xrefs show the direct behavioral methods are called by [UID:0000UM][EncodeTextEditState_0058E490](by-item/EncodeTextEditState_0058E490.md), a text-edit serialization helper.
- `Encoder` does not own the output buffer. The caller allocates or provides it, and `Finalize` detaches rather than frees it.
- 2026-05-25 IDA MCP recheck reconfirmed the two-slot vtable at `0x006192cc` and that the active writer-family xrefs all come from [UID:0000UM][EncodeTextEditState_0058E490](by-item/EncodeTextEditState_0058E490.md).
- 2026-05-26 IDA MCP recheck again found the direct writer/finalize callers only in [UID:0000UM][EncodeTextEditState_0058E490](by-item/EncodeTextEditState_0058E490.md); the helper itself has one raw thunk xref at `0x00498c4a` and no formal modeled callers.
- 2026-05-26 IDA MCP vtable/layout recheck confirms vtable refs at `0x004a4e70`, `0x004a4ea0`, and `0x004a5e3a`, and confirms constructor/initialize/finalize use the shared cursor fields now documented in [UID:0001TS][BinaryCodecCursorLayout](by-type/by-struct/BinaryCodecCursorLayout.md).
- 2026-06-12 A002 Batch 343 live IDA MCP refresh confirmed stable Encoder method starts/sizes: constructor `0x004a4e70` size `0x24`, destructor `0x004a4ea0` size `0x7`, byte/short/int/raw-span writers `0x004a4ec0`/`0x004a4f00`/`0x004a4ff0`/`0x004a5480`, initialize/finalize `0x004a55c0`/`0x004a55e0`, no-op virtual `0x004a5630`, and scalar deleting destructor `0x004a5e30`.
- The same refresh read exact vtable bytes at `0x006192c8-0x006192d4`, reconfirmed vtable-base stores from the constructor/destructor/scalar-deleting destructor, and found no ordinary code caller for the no-op slot beyond its vtable data reference.
- IDA decompilation during Batch 343 reconfirmed the constructor installs `off_6192CC`, clears buffer/capacity/cursor, and writes flags word `0x0101`; `Finalize` appends the trailing zero byte, optionally returns the cursor, clears buffer/capacity/cursor, restores valid state, and returns the saved valid flag.
- 2026-06-17 B002 source-quality recheck reclassifies [UID:00013D][0x004a4e70-0x004a5621.EncoderCore](by-memory/0x004a4e70-0x004a5621.EncoderCore.md) as a non-emitting split/index. Exact method pages remain the source-bearing units; the broad index still records unsplit helper-shaped islands and must not emit aggregate C++.
- 2026-06-20 B003/B004 source-quality reanalysis confirms [UID:00013J][0x004a55c0-0x004a55de.EncoderInitialize](by-memory/0x004a55c0-0x004a55de.EncoderInitialize.md) as exact `void Encoder::Initialize(unsigned char *buffer, unsigned int capacity)` draft source. It writes `m_outputBuffer`, stores the capacity field, resets `m_writePos`, sets the writable/valid flag, and deliberately leaves `m_useBigEndian` unchanged, so default big-endian scalar output remains active for [UID:0001JN][0x0058e490-0x0058e691.TextEditPaneSerialization](by-memory/0x0058e490-0x0058e691.TextEditPaneSerialization.md). B004 aligns the formal draft with `m_capacity` and `m_isWritable` while retaining `m_outputCapacity` and `m_isValid` as equivalent layout aliases. The by-memory child should emit the method definition; this class page carries the class/API inventory and eventual declaration-level context.
- 2026-06-21 B008 source-quality reanalysis confirms [UID:00013K][0x004a55e0-0x004a5621.EncoderFinalize](by-memory/0x004a55e0-0x004a5621.EncoderFinalize.md) as exact `bool Encoder::Finalize(unsigned int *outBytesWritten)` draft source. It returns the previous `m_isWritable` byte, optionally stores `m_writePos` as a 32-bit byte count, writes the trailing NUL through `m_outputBuffer[m_writePos]` without a null/valid guard, clears `m_outputBuffer`, `m_capacity`, and `m_writePos`, restores `m_isWritable`, and leaves `m_useBigEndian` unchanged. The sole confirmed caller at `0x0058e624` passes a dword stack local, uses the full dword count for allocation/copy, and only later truncates to a 16-bit caller-facing size, so the class declaration should not use a 16-bit output pointer.
- 2026-06-21 B011 source-quality recheck independently confirms the same [UID:00013K][0x004a55e0-0x004a5621.EncoderFinalize](by-memory/0x004a55e0-0x004a5621.EncoderFinalize.md) class placement from exported IDA/Ghidra artifacts: the exact body is non-thunk, non-library, one-caller/no-callee source-bearing `Encoder` code, not compiler glue, BinaryCodec coordinator code, or TextEditPane-owned serialization logic.
- 2026-06-21 B010 source-quality reanalysis confirms [UID:00013E][0x004a4ea0-0x004a4ea7.EncoderDestructor](by-memory/0x004a4ea0-0x004a4ea7.EncoderDestructor.md) as exact `Encoder::~Encoder()` draft source. Local PE/Capstone bytes `c7 01 cc 92 61 00 c3` prove the body only restores vtable base `0x006192cc` and returns; vtable restoration is compiler mechanics, so the method's C++ body is empty. The ordinary cleanup call at `0x0058e66c` and compiler cleanup jump at `0x0060970c` are TextEditPane stack-Encoder cleanup routes, not ownership. [UID:00013V][0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor](by-memory/0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor.md) remains generated delete-flag glue, and raw `0x004a4eb0-0x004a4ebd` is a likely future `Encoder::SetByteOrder(unsigned char byteOrderFlag)` split matching [UID:0003K8][0x004a5680-0x004a568d.DecoderSetByteOrder](by-memory/0x004a5680-0x004a568d.DecoderSetByteOrder.md).
- 2026-06-22 B013 source-quality verification for [UID:00013E][0x004a4ea0-0x004a4ea7.EncoderDestructor](by-memory/0x004a4ea0-0x004a4ea7.EncoderDestructor.md) confirms no class declaration or score downgrade is needed. B013's conservative `86/91` recommendation is superseded by the current `87/92` child state, but the report independently validates the same empty ordinary destructor body, no-owned-buffer cleanup proof, direct `Encoder` owner/emitter route, active code gate, source-quality alias cleanup for `sub_4A4EA0` and `off_6192CC`, and rejection of TextEditPane, BinaryCodec-direct, packet/network, DAT, and no-owner alternatives. Live MCP was unavailable in that B013 session, so it is corroborating provenance rather than a source of newer direct IDA facts.
- 2026-06-21 B011 source-quality reanalysis confirms [UID:00013C][0x004a4e70-0x004a4e94.EncoderConstructor](by-memory/0x004a4e70-0x004a4e94.EncoderConstructor.md) as exact `Encoder::Encoder()` draft source. Exported IDA/Ghidra data and direct PE bytes agree on the `0x24` body: compiler vptr store `0x006192cc`, zero stores for `m_outputBuffer`/`m_capacity`/`m_writePos`, flags word `0x0101` for `m_useBigEndian` plus `m_isWritable`, one TextEditPane serialization caller at `0x0058e4e4`, no callees, and padding before the destructor. The constructor now carries first-draft C++ on the by-memory child; this class page keeps declaration/API context and treats raw `sub_4A4E70`, `off_6192CC`, and `mbr_0x...` names only as evidence aliases.
- 2026-06-21 supervisor closeout of B012 duplicate [UID:00013C][0x004a4e70-0x004a4e94.EncoderConstructor](by-memory/0x004a4e70-0x004a4e94.EncoderConstructor.md) report confirms no class-level change was needed. B012 independently checked the same PE/exported evidence, accepted the current `Encoder::Encoder()` initializer-list C++ and field names, recorded that live IDA MCP was unavailable for that session, and rejected the same TextEditPane, PacketBuffer/network, BinaryCodec-direct, no-owner, vtable-only, and generated-name source routes.
- 2026-06-21 B011 source-quality reanalysis confirms [UID:00013F][0x004a4ec0-0x004a4ef1.EncoderWriteByte](by-memory/0x004a4ec0-0x004a4ef1.EncoderWriteByte.md) as exact `void Encoder::WriteByte(unsigned char value)` draft source. Exported IDA/Ghidra data, prior live IDA-backed docs, and direct PE bytes agree on the `0x31` body: valid/writable byte `+0x11` gate, signed capacity check requiring `m_capacity >= m_writePos + 2`, byte write to `m_outputBuffer[m_writePos]`, cursor increment, valid clear without partial write on overflow, one TextEditPane serialization caller at `0x0058e57b`, no callees, and the adjacent `0x004a4eb0-0x004a4ebd` byte-order setter as a separate future split. The exact child now carries first-draft C++; this class page keeps declaration/API context.
- 2026-06-22 B014 source-quality verification for [UID:00013F][0x004a4ec0-0x004a4ef1.EncoderWriteByte](by-memory/0x004a4ec0-0x004a4ef1.EncoderWriteByte.md) corroborates the same class route without changing the stronger current `88/91` child state. B014's lower `87/90` recommendation reflected stale pre-incorporation metadata, but its valid analysis confirms `Encoder::WriteByte(unsigned char)`, final-NUL reserve capacity policy, overflow invalidation through `m_isWritable`, TextEditPaneSerialization as caller only, rejected TextEditPane/BinaryCodec-direct/packet/no-owner routes, descriptive member-name direction, and the separate `0x004a4eb0-0x004a4ebd` byte-order setter candidate.
- 2026-06-21 B009 source-quality reanalysis confirms [UID:00013H][0x004a4ff0-0x004a506b.EncoderWriteInt](by-memory/0x004a4ff0-0x004a506b.EncoderWriteInt.md) as exact `void Encoder::WriteInt(unsigned int value)` draft source. The target and sibling docs agree on the `0x7b` body: valid/writable byte `+0x11` gate, capacity check requiring `m_capacity >= m_writePos + 5`, big-endian byte sequence when `m_useBigEndian` is set, direct native x86 dword store when it is clear, one TextEditPane serialization caller at `0x0058e58b` for marker value `0x6b6f6e67`, no callees, and raw helper islands after `0x004a506b` as separate future exact children. The exact child now carries first-draft C++; this class page keeps declaration/API context.
- 2026-06-22 B013 source-quality reanalysis raises [UID:00013H][0x004a4ff0-0x004a506b.EncoderWriteInt](by-memory/0x004a4ff0-0x004a506b.EncoderWriteInt.md) confidence to `91` from direct PE/Capstone evidence. It confirms the signed capacity/cursor compare for `m_capacity >= m_writePos + 5`, logical shifts supporting `unsigned int value`, default-big-endian emission of the TextEditPane marker bytes `6b 6f 6e 67` (`"kong"`), `ret 4` thiscall shape, no callees, one positive rel32 caller at `0x0058e58b`, and no route to the adjacent helper-island starts. The field names remain source-facing reconstruction names, not proven original symbols.
- 2026-06-21 B012 source-quality reanalysis confirms [UID:00013G][0x004a4f00-0x004a4f59.EncoderWriteShort](by-memory/0x004a4f00-0x004a4f59.EncoderWriteShort.md) as exact `void Encoder::WriteShort(unsigned short value)` draft source. Target/support evidence agrees on the `0x59` body: valid/writable byte `+0x11` gate, capacity check requiring `m_capacity >= m_writePos + 3` for two payload bytes plus the final-NUL reserve, high-byte-first output when `m_useBigEndian` is set, direct native 16-bit store when it is clear, three TextEditPane serialization length-prefix callers at `0x0058e59a`/`0x0058e5c9`/`0x0058e5f8`, no callees, and adjacent raw `0x004a4f60-0x004a4fe3` as a separate probable 24-bit writer candidate. The exact child now carries first-draft C++; this class page keeps declaration/API context.
- 2026-06-27 B005 source-quality implementation confirms [UID:00013L][0x004a5630-0x004a5631.EncoderNoopVirtual](by-memory/0x004a5630-0x004a5631.EncoderNoopVirtual.md) as exact source-empty `void Encoder::NoopVirtual()` draft source. Current MCP session `b001_000241_20260627` proves byte `c3`, one basic block `0x004a5630-0x004a5631`, no callers/callees, sole data xref `0x006192d0`, and vtable dwords placing the body after the scalar deleting destructor slot. The original virtual method spelling remains unproved, so `NoopVirtual` is descriptive; [UID:00013V][0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor](by-memory/0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor.md) remains generated glue with no handwritten source body.
- 2026-06-27 B009 source-quality implementation raises [UID:00013V][0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor](by-memory/0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor.md) to `90/93` while preserving the no-code disposition. Current MCP session `b001_000241_20260627` confirms health OK, exact `0x004a5e30-0x004a5e54` size `0x24`, hidden delete-flag test, Encoder vtable restore to `0x006192cc`, conditional `0x14`-byte free-helper call to `sub_5C7526`, `ret 4`, full wrapper bytes, twelve-byte `0xcc` padding before and after, sole data pointer at `0x006192cc`, no ordinary code callers, and vtable dwords `0x006192c8 -> 0x00646b2c`, `0x006192cc -> 0x004a5e30`, `0x006192d0 -> 0x004a5630`. The source-facing class declaration remains `virtual ~Encoder()` plus the ordinary empty [UID:00013E][0x004a4ea0-0x004a4ea7.EncoderDestructor](by-memory/0x004a4ea0-0x004a4ea7.EncoderDestructor.md) body; the hidden delete flag and free-helper branch are ABI glue, not class source statements.

## Dated Superseded Caveats

- The no-op vtable slot at `0x004a5630` is modeled by exact child [UID:00013L][0x004a5630-0x004a5631.EncoderNoopVirtual](by-memory/0x004a5630-0x004a5631.EncoderNoopVirtual.md), which emits an empty `Encoder::NoopVirtual()` body even though it has no ordinary code callers.
- The only confirmed direct caller is a text-edit serializer. Do not assume network packet ownership from the generic "encoder" name without caller evidence.
- The broad [UID:00013D][0x004a4e70-0x004a5621.EncoderCore](by-memory/0x004a4e70-0x004a5621.EncoderCore.md) range is not a code-emitting unit. Interior helper-shaped islands still need exact child research or classification before final full-class source output.
- Exact children that clear the active gate, including [UID:00013C][0x004a4e70-0x004a4e94.EncoderConstructor](by-memory/0x004a4e70-0x004a4e94.EncoderConstructor.md), [UID:00013E][0x004a4ea0-0x004a4ea7.EncoderDestructor](by-memory/0x004a4ea0-0x004a4ea7.EncoderDestructor.md), [UID:00013F][0x004a4ec0-0x004a4ef1.EncoderWriteByte](by-memory/0x004a4ec0-0x004a4ef1.EncoderWriteByte.md), [UID:00013G][0x004a4f00-0x004a4f59.EncoderWriteShort](by-memory/0x004a4f00-0x004a4f59.EncoderWriteShort.md), [UID:00013H][0x004a4ff0-0x004a506b.EncoderWriteInt](by-memory/0x004a4ff0-0x004a506b.EncoderWriteInt.md), [UID:00013I][0x004a5480-0x004a54c6.EncoderWriteBytes](by-memory/0x004a5480-0x004a54c6.EncoderWriteBytes.md), and [UID:00013J][0x004a55c0-0x004a55de.EncoderInitialize](by-memory/0x004a55c0-0x004a55de.EncoderInitialize.md), may carry first-draft method C++ even while the full class declaration remains capped by original-name and helper-island uncertainty.
- Adjacent raw `0x004a4f60-0x004a4fe3` is a probable Encoder 24-bit scalar writer (`WriteUInt24` / `WriteTriByte`) with the same fields and a `m_writePos + 4` reserve check, but current evidence shows no IDA caller/xref route. Keep it separate from [UID:00013G][0x004a4f00-0x004a4f59.EncoderWriteShort](by-memory/0x004a4f00-0x004a4f59.EncoderWriteShort.md) and track it as future exact-child/support work rather than merging it into the short writer.
- [UID:00013K][0x004a55e0-0x004a5621.EncoderFinalize](by-memory/0x004a55e0-0x004a5621.EncoderFinalize.md) also clears the active gate and should emit from the exact child. [UID:00013L][0x004a5630-0x004a5631.EncoderNoopVirtual](by-memory/0x004a5630-0x004a5631.EncoderNoopVirtual.md) now emits the source-empty virtual body through the exact child; [UID:00013V][0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor](by-memory/0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor.md) is resolved as `90/93` compiler-generated scalar deleting destructor glue and should not be represented as a handwritten method body.
- The raw `0x004a4eb0-0x004a4ebd` island is not destructor tail or `WriteByte`; it is a setter-shaped body that writes an argument byte to `+0x10`. The best current name is `Encoder::SetByteOrder(unsigned char byteOrderFlag)`, but it should stay unsplit until assigned exact-child work confirms route and UID.

## Cross-References

- [UID:0000J1][Encoder](by-file/Encoder.md)
- [UID:0000HQ][BinaryCodec](by-file/BinaryCodec.md)
- [UID:00003M][Decoder](by-class/Decoder.md)
- [UID:00013D][0x004a4e70-0x004a5621.EncoderCore](by-memory/0x004a4e70-0x004a5621.EncoderCore.md)
- [UID:00013M][0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue](by-memory/0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue.md)
- [UID:0003IA][0x006192c8-0x006192d4.EncoderVtableData](by-memory/0x006192c8-0x006192d4.EncoderVtableData.md)
- [UID:0001TS][BinaryCodecCursorLayout](by-type/by-struct/BinaryCodecCursorLayout.md)
- [UID:0001X1][BinaryCodecVtables](by-type/by-vtable/BinaryCodecVtables.md)
- [UID:0000UM][EncodeTextEditState_0058E490](by-item/EncodeTextEditState_0058E490.md)

## Changes

- 2026-06-27 B009 implementation of accepted [UID:00013V][0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor](by-memory/0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor.md) report:
  - Before/after class score unchanged: `88/91`.
  - Summary/evidence: updated the class declaration/support inventory so [UID:00013V][0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor](by-memory/0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor.md) is a `90/93` generated MSVC scalar deleting destructor wrapper with blank formal C++, generated from `virtual ~Encoder()` and paired with the empty ordinary [UID:00013E][0x004a4ea0-0x004a4ea7.EncoderDestructor](by-memory/0x004a4ea0-0x004a4ea7.EncoderDestructor.md) source body. Current MCP evidence records the exact `0x24` wrapper, hidden delete-flag test, conditional `0x14`-byte free-helper branch, `ret 4`, vtable slot/xrefs, no ordinary callers, padding envelopes, and no-code source disposition while preserving broader class blockers for original no-op virtual spelling, helper islands, final member names, header split, and final `sizeof`.

- 2026-06-27 B005 implementation of accepted [UID:00013L][0x004a5630-0x004a5631.EncoderNoopVirtual](by-memory/0x004a5630-0x004a5631.EncoderNoopVirtual.md) report:
  - Before/after class score unchanged: `88/91`.
  - Summary/evidence: updated the class declaration/support inventory so `NoopVirtual` remains a descriptive declaration placeholder and the exact [UID:00013L][0x004a5630-0x004a5631.EncoderNoopVirtual](by-memory/0x004a5630-0x004a5631.EncoderNoopVirtual.md) child emits empty `Encoder::NoopVirtual()` C++. Current MCP proof records the `c3` body, no callers/callees, sole `0x006192d0` vtable data xref, and `Encoder` vtable dwords; the scalar deleting destructor [UID:00013V][0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor](by-memory/0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor.md) remains compiler-generated/no-handwritten-source.

- 2026-06-22 Rule 26 incorporation of B013 [UID:00013H][0x004a4ff0-0x004a506b.EncoderWriteInt](by-memory/0x004a4ff0-0x004a506b.EncoderWriteInt.md) report:
  - Before/after class score unchanged: `88/91`.
  - Summary/evidence: updated the class inventory to `88/91` for the exact `Encoder::WriteInt(unsigned int value)` child and incorporated B013's raw PE/Capstone confirmation of the body, source-facing field directions, unsigned value parameter, default-big-endian `"kong"` marker behavior, one-caller/no-callee route, and separate future status of raw helper islands after `0x004a5070`.

- 2026-06-21 Rule 26 incorporation of B012 [UID:00013G][0x004a4f00-0x004a4f59.EncoderWriteShort](by-memory/0x004a4f00-0x004a4f59.EncoderWriteShort.md) report:
  - Before/after class score unchanged: `88/91`.
  - Summary/evidence: the class inventory now records `Encoder::WriteShort(unsigned short value)` as an exact source-bearing child with first-draft C++. B012 verified the active C++ gate, direct Encoder owner/emitter route, final-NUL reserve capacity policy, byte-order polarity, native-store branch, three TextEditPane length-prefix callers, no-callee behavior, rejected BinaryCodec-direct/TextEditPane/packet/no-owner routes, and kept adjacent `0x004a4f60-0x004a4fe3` as a separate probable 24-bit writer candidate. Exact original member spellings, header split, final `sizeof`, and unsplit helper islands still cap the class below final audit.

- 2026-06-21 Rule 26 incorporation of B009 [UID:00013H][0x004a4ff0-0x004a506b.EncoderWriteInt](by-memory/0x004a4ff0-0x004a506b.EncoderWriteInt.md) report:
  - Before/after class score unchanged: `88/91`.
  - Summary/evidence: the class inventory now records `Encoder::WriteInt(unsigned int value)` as an exact source-bearing child with first-draft C++. B009 verified the active C++ gate, direct Encoder owner/emitter route, final-NUL reserve capacity policy, big-endian default marker bytes for the TextEditPane serializer, direct native-store little-endian branch, one caller/no callee behavior, rejected BinaryCodec-direct/TextEditPane/packet/no-owner routes, and rejected raw/generated names as source spellings. Exact original member spellings, historical typedef/header split, final `sizeof`, and unsplit raw helper islands still cap the class below final audit.
- 2026-06-21 Rule 26 incorporation of B011 [UID:00013F][0x004a4ec0-0x004a4ef1.EncoderWriteByte](by-memory/0x004a4ec0-0x004a4ef1.EncoderWriteByte.md) report:
  - Before/after class score unchanged: `88/91`.
  - Summary/evidence: the class inventory now records `Encoder::WriteByte(unsigned char value)` as an exact source-bearing child with first-draft C++. B011 verified the byte-exact writer body, final-NUL reserve capacity policy, overflow invalidation without partial write, one TextEditPane serialization delimiter caller, no callee behavior, direct Encoder owner/emitter route, rejected TextEditPane/BinaryCodec-direct/packet/no-owner routes, and rejected raw/generated names as source spellings. Exact original member spellings, header split, final `sizeof`, and unsplit helper islands still cap the class below final audit.
- 2026-06-22 Rule 26 incorporation check of B014 [UID:00013F][0x004a4ec0-0x004a4ef1.EncoderWriteByte](by-memory/0x004a4ec0-0x004a4ef1.EncoderWriteByte.md) report:
  - Before/after class score unchanged: `88/91`.
  - Summary/evidence: B014 revalidated the exact `Encoder::WriteByte(unsigned char)` child after it had already been incorporated above B014's `87/90` recommendation. The class page keeps the existing declaration and child inventory, records B014's source-route/name/field/caller checks as corroboration, and preserves remaining class-level caveats for exact original member spelling, header split, final `sizeof`, and unsplit raw helper islands.
- 2026-06-21 Rule 26 incorporation of B011 [UID:00013C][0x004a4e70-0x004a4e94.EncoderConstructor](by-memory/0x004a4e70-0x004a4e94.EncoderConstructor.md) report:
  - Before/after class score unchanged: `88/91`.
  - Summary/evidence: the class inventory now records `Encoder::Encoder()` as an exact source-bearing child with first-draft initializer-list C++. B011 verified the byte-exact constructor body, compiler-only vptr store, caller-owned buffer/capacity/cursor default state, `0x0101` split into `m_useBigEndian` and `m_isWritable`, sole TextEditPane serialization caller, no callee behavior, direct Encoder owner/emitter route, and rejected TextEditPane, BinaryCodec-direct, PacketBuffer/network, no-owner, vtable-only, and no-code/compiler-glue alternatives. Exact original member spellings, header split, final `sizeof`, and unsplit helper islands still cap the class below final audit.
- 2026-06-21 Rule 26 incorporation of B010 [UID:00013E][0x004a4ea0-0x004a4ea7.EncoderDestructor](by-memory/0x004a4ea0-0x004a4ea7.EncoderDestructor.md) report:
  - Before/after class score unchanged: `88/91`.
  - Summary/evidence: the class inventory now records `Encoder::~Encoder()` as an exact source-bearing child with empty first-draft C++. B010 verified the seven-byte vtable-restore body, no owned-buffer cleanup, ordinary TextEditPane stack cleanup call versus compiler cleanup jump, generated scalar deleting destructor relationship, direct Encoder owner route, rejected BinaryCodec/TextEditPane/packet ownership, and likely future `Encoder::SetByteOrder` raw neighbor split. The class page remains declaration/context only; exact by-memory child pages carry method bodies.
- 2026-06-22 Rule 26 incorporation of B013 [UID:00013E][0x004a4ea0-0x004a4ea7.EncoderDestructor](by-memory/0x004a4ea0-0x004a4ea7.EncoderDestructor.md) report:
  - Before/after class score unchanged: `88/91`.
  - Summary/evidence: B013 rechecked the already-incorporated destructor decision and confirmed the class should keep `virtual ~Encoder()` declaration context while the exact child emits the empty out-of-class body. The pass preserves B010's stronger `87/92` child state over B013's conservative `86/91` recommendation, records raw-name/source-name cleanup, confirms scalar deleting destructor glue remains generated, and leaves broader original header/member/no-op virtual naming questions as class-level caveats rather than blockers for the exact destructor child.
- 2026-06-21 B006 [UID:0001X1][BinaryCodecVtables](by-type/by-vtable/BinaryCodecVtables.md) source-quality incorporation:
  - Before/after class score unchanged: `88/91`.
  - Summary/evidence: added declaration-level vtable guidance: `virtual ~Encoder()` plus descriptive `virtual void NoopVirtual()` for the concrete no-op vtable slot, with scalar deleting destructor kept compiler-generated. The exact vtable data child remains class-owned while [UID:0001X1][BinaryCodecVtables](by-type/by-vtable/BinaryCodecVtables.md) stays the BinaryCodec family aggregate.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `82/86`.
  - Summary/evidence: binary writer role, cursor layout, constructor/destructor/writer/finalize/no-op/scalar-destructor methods, vtable evidence, caller evidence, and caveats are documented; remaining work is final `sizeof` padding and broader caller provenance if new xrefs are recovered.
- 2026-05-31:
  - Before: the class was documented as reconstructable in prose but validator `RECONSTRUCTABLE` metadata was blank.
  - After: `RECONSTRUCTABLE` is set to `TRUE`.
  - Summary/evidence: IDA MCP reconfirmed the Encoder constructor/destructor/no-op/scalar-deleting vtable surface and direct consumer boundary; at that time declaration-level C++ remained blank pending later child/source-quality passes.
- 2026-06-05:
  - Before: `AUTOGEN_PARENT_UID` was blank, leaving reconstructable Encoder children unable to resolve to an autogen root.
  - After: `AUTOGEN_PARENT_UID` is set to [UID:0000J1][Encoder](by-file/Encoder.md), and stale generated-source wording was removed from the status/caveat text.
  - Summary/evidence: [UID:0000J1][Encoder](by-file/Encoder.md) is a validated `NexusTK/util/` file root with documented Encoder ownership; live autogen coverage showed [UID:00013D][0x004a4e70-0x004a5621.EncoderCore](by-memory/0x004a4e70-0x004a5621.EncoderCore.md) already using this class as parent, so the class needed a file-root parent chain.
- 2026-06-12 A002 Batch 343:
  - Before: scored `82/86`, which blocked direct routing for [UID:0003IA][0x006192c8-0x006192d4.EncoderVtableData](by-memory/0x006192c8-0x006192d4.EncoderVtableData.md).
  - After: scored `86/90`; parent remains [UID:0000J1][Encoder](by-file/Encoder.md).
  - Summary/evidence: live IDA reconfirmed the complete method family, exact vtable child bytes, constructor/finalize behavior, vtable store refs, text-edit serializer caller boundary, and no-op virtual slot, so the class now clears the strict 85/85 gate for exact Encoder-owned children.
- 2026-06-17 B002 source-quality recheck:
  - Before/after class score unchanged: `86/90`.
  - Summary/evidence: [UID:00013D][0x004a4e70-0x004a5621.EncoderCore](by-memory/0x004a4e70-0x004a5621.EncoderCore.md) is now a non-emitting split/index while exact child method/vtable-support pages carry source ownership. B002 validated Encoder rather than BinaryCodec/TextEditPane as the direct owner, recorded descriptive field-name directions, and kept final C++ blocked until exact source names/signatures and helper-island splits are resolved.
- 2026-06-20 supervisor Rule 26 incorporation of B001/B014 [UID:00013I][0x004a5480-0x004a54c6.EncoderWriteBytes](by-memory/0x004a5480-0x004a54c6.EncoderWriteBytes.md) reports:
  - Before/after class score unchanged: `86/90`.
  - Summary/evidence: [UID:00013I][0x004a5480-0x004a54c6.EncoderWriteBytes](by-memory/0x004a5480-0x004a54c6.EncoderWriteBytes.md) now records first-draft `Encoder::WriteBytes(const void *data, unsigned int byteCount)` C++ and `88/90` target scoring. The class inventory reflects the exact source-facing signature, final-NUL reserve, overflow invalidation, MemoryMan copy-helper route, and corrected adjacent helper spans `0x004a54d0-0x004a558d` and `0x004a5590-0x004a55b6`; remaining helper-island splits continue to cap full Encoder final audit.
- 2026-06-20 Rule 26 incorporation of B003 [UID:00013J][0x004a55c0-0x004a55de.EncoderInitialize](by-memory/0x004a55c0-0x004a55de.EncoderInitialize.md) report:
  - Before: class score `86/90`, with [UID:00013J][0x004a55c0-0x004a55de.EncoderInitialize](by-memory/0x004a55c0-0x004a55de.EncoderInitialize.md) still listed as generic `Initialize` and field names split between older aliases.
  - Changed to: class score `88/91`; the API inventory now records `Encoder::Initialize(unsigned char *outputBuffer, int capacity)`, preferred source-facing names `m_outputBuffer`, `m_outputCapacity`, `m_writePos`, `m_useBigEndian`, and `m_isValid`, and the child/page division where exact by-memory methods emit bodies while the class page preserves declaration/source-context evidence.
  - Evidence: B003 byte/disassembly and route analysis proves [UID:00013J][0x004a55c0-0x004a55de.EncoderInitialize](by-memory/0x004a55c0-0x004a55de.EncoderInitialize.md) is live, non-virtual, one-caller attach/reset code with no callees or pointer route. It is not a constructor, TextEditPane-owned helper, dead helper, or `int`-returning API; exact original symbol spelling remains the main class-level caveat.
- 2026-06-20 Rule 26 incorporation of B004 [UID:00013J][0x004a55c0-0x004a55de.EncoderInitialize](by-memory/0x004a55c0-0x004a55de.EncoderInitialize.md) report:
  - Before/after class score unchanged: `88/91`.
  - Summary/evidence: B004 independently rechecked the exact child from local PE bytes, confirmed no owner/emitter/source-root change, and aligned the class inventory with `Encoder::Initialize(unsigned char *buffer, unsigned int capacity)`, `m_capacity`, and `m_isWritable` while retaining the B003 aliases as layout synonyms. Exact original symbol spelling, class header split, and adjacent helper names remain descriptive rather than symbol-proven.
- 2026-06-21 Rule 26 incorporation of B008 [UID:00013K][0x004a55e0-0x004a5621.EncoderFinalize](by-memory/0x004a55e0-0x004a5621.EncoderFinalize.md) report:
  - Before/after class score unchanged: `88/91`.
  - Summary/evidence: the class inventory now records `Encoder::Finalize(unsigned int *outBytesWritten)` with the 32-bit output count, previous-valid return, unconditional trailing-NUL write, caller-owned buffer detach/reset, unchanged byte-order flag, and exact-child first-draft C++ ownership. B008 rejects no-code/compiler glue, aggregate-only emission, TextEditPane ownership, BinaryCodec direct ownership, and a 16-bit output pointer; remaining uncertainty is original member spelling and header organization, not the method body.
- 2026-06-21 Rule 26 incorporation check of B011 [UID:00013K][0x004a55e0-0x004a5621.EncoderFinalize](by-memory/0x004a55e0-0x004a5621.EncoderFinalize.md) report:
  - Before/after class score unchanged: `88/91`.
  - Summary/evidence: B011's requested class/source route was already present, so no declaration or emitter change was made. The report's exported IDA/Ghidra checks reinforce the existing class inventory: `Finalize` is exact source-bearing `Encoder` method code with one TextEditPane consumer, zero callees, direct `Encoder.cpp` routing, and rejected compiler-glue/BinaryCodec-direct/TextEditPane-owner alternatives.
