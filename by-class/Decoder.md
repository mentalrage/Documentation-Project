*** UID:00003M | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Decoder
{
public:
    Decoder();
    virtual ~Decoder();

    void SetByteOrder(bool useBigEndian);
    unsigned char ReadByte();
    unsigned short ReadShort();
    unsigned int ReadTriByte();
    unsigned int ReadInt();
    void ReadWideString8(wchar_t *out, int capacityChars, int *outChars);
    void ReadWideString16(wchar_t *out, int capacityChars, int *outChars);
    void ReadAnsiString8(wchar_t *out, int capacityChars, int *outChars);
    void ReadAnsiString16(wchar_t *out, int capacityChars, int *outChars);
    void ReadCString(wchar_t *out, int capacityChars, int *outChars);
    void ReadBytes(void *out, int byteCount);
    void ReadCompressedBytes(
        void *out,
        unsigned int outCapacity,
        unsigned int *outBytes);
    void SkipBytes(int byteCount);
    void Initialize(const unsigned char *buffer, int size);
    bool Finalize();
    virtual void NoopVirtual();

private:
    const unsigned char *m_inputBuffer;
    int m_inputSize;
    int m_readPos;
    bool m_useBigEndian;
    bool m_isValid;
};

typedef char DecoderSizeMustBe20[(sizeof(Decoder) == 20) ? 1 : -1];
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# Decoder

## 2026-08-15 Complete Class And Route

`Decoder` is a standalone 20-byte class directly owned and emitted by [UID:0000HQ][BinaryCodec](by-file/BinaryCodec.md) at source position 2. Its CPP channel is exactly `[[CHILDREN]]`; its H channel completes the common BinaryCodec header after Encoder with all 18 declarations and the size assertion. Every definition remains on its exact by-memory child in address order.

Fields are const input buffer `+0x04`, signed `int` input size `+0x08`, signed `int` read position `+0x0c`, `bool` big-endian selector `+0x10`, and `bool` validity `+0x11`, plus natural tail alignment. All authored methods are retained dead in the current retail route after exhaustive constructor/destructor/method/pointer scans; NoopVirtual has only its vtable reference. This liveness does not remove the complete source API.

Formal source preserves native/wide and CP_ACP paths, MemoryMan copy semantics, zlib's ignored status, signed bounds, the one-byte SkipBytes remainder rule, and Finalize's deliberate lack of full-input-consumption validation. Earlier UID0000IQ root, unsigned-type, MoveMemory, byte-like-not-bool, provisional split, and unresolved-source statements are superseded historical research. No shared base or handwritten ABI glue is emitted.

## Dated Superseded Status

- Confidence: high for class ownership/layout/vtable identity and exact raw-reader boundaries, medium-high for complete live method reachability.
- Likely source file: [UID:0000IQ][Decoder](by-file/Decoder.md), under the [UID:0000HQ][BinaryCodec](by-file/BinaryCodec.md) utility layer
- Current recovered file: `source-3/simroot_v2/class_Decoder.cpp`
- Main address evidence: [UID:00013M][0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue](by-memory/0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue.md)
- Layout docs: [UID:0001TS][BinaryCodecCursorLayout](by-type/by-struct/BinaryCodecCursorLayout.md)
- Primary vtable: [UID:0001X1][BinaryCodecVtables](by-type/by-vtable/BinaryCodecVtables.md)
- Generated size caveat: current metadata reports only 4 bytes, but IDA-confirmed and raw code uses the same cursor layout as [UID:00004F][Encoder](by-class/Encoder.md), with observed fields through offset `+0x11`, giving an observed stream-state footprint of at least `0x12` / 18 bytes (Verified with int_convert.py).

## Class Purpose

`Decoder` is the reader-side companion to [UID:00004F][Encoder](by-class/Encoder.md). It attaches to a caller-owned byte buffer, reads primitive values and string/blob payloads from the current cursor, advances the cursor, and clears its valid flag when a read cannot be satisfied from the remaining buffer.

## Dated Superseded Declaration Direction

The current source-facing declaration direction is:

```cpp
class Decoder {
public:
    Decoder();
    virtual ~Decoder();
    virtual void NoopVirtual(); // descriptive placeholder for 0x004a5df0

    void Initialize(const unsigned char *buffer, unsigned int size);
    bool Finalize();
    void SetByteOrder(unsigned char byteOrderFlag);
    unsigned char ReadByte();
    unsigned short ReadShort();
    unsigned int ReadTriByte();
    unsigned int ReadInt();
    void ReadWideString8(wchar_t *out, int capacityChars, int *outChars);
    void ReadWideString16(wchar_t *out, int capacityChars, int *outChars);
    void ReadAnsiString8(wchar_t *out, int capacityChars, int *outChars);
    void ReadAnsiString16(wchar_t *out, int capacityChars, int *outChars);
    void ReadCString(wchar_t *out, int capacityChars, int *outChars);
    void ReadBytes(void *out, unsigned int byteCount);
    void ReadCompressedBytes(void *out, unsigned int outCapacity, unsigned int *outBytes);
    void SkipBytes(unsigned int byteCount);
};
```

`NoopVirtual` is not a proven original symbol. It is the best descriptive placeholder for the concrete one-byte `ret` body at [UID:00013T][0x004a5df0-0x004a5df1.DecoderNoopVirtual](by-memory/0x004a5df0-0x004a5df1.DecoderNoopVirtual.md), reached only by vtable slot `0x006192dc`. B002's accepted 2026-07-05 source-quality callback records current MCP session `supervisor_recovery_20260705` evidence and makes the exact child emit a source-empty `Decoder::NoopVirtual()` body through this class. Do not use raw `nullsub_28` as a source-quality name and do not model the slot as pure virtual. [UID:00013U][0x004a5e00-0x004a5e24.DecoderScalarDeletingDestructor](by-memory/0x004a5e00-0x004a5e24.DecoderScalarDeletingDestructor.md) is compiler-generated from `virtual ~Decoder()`; do not emit a handwritten scalar deleting destructor body in source.

The primitive reader names are source-facing descriptive names, not original-symbol proof. B004's accepted 2026-06-25 implementation records the formal method bodies on exact child pages [UID:0003K8][0x004a5680-0x004a568d.DecoderSetByteOrder](by-memory/0x004a5680-0x004a568d.DecoderSetByteOrder.md)-[UID:0003KC][0x004a5770-0x004a57dc.DecoderReadInt](by-memory/0x004a5770-0x004a57dc.DecoderReadInt.md); class-level C++ remains blank until the final header/source declaration shape is settled.

The string/blob/raw-span reader names are also source-facing descriptive names, not original-symbol proof. B004's accepted 2026-06-25 [UID:00013R][0x004a57e0-0x004a5dce.DecoderStringAndBlobReaders](by-memory/0x004a57e0-0x004a5dce.DecoderStringAndBlobReaders.md) implementation records formal method bodies on exact child pages [UID:0003L6][0x004a57e0-0x004a5861.DecoderReadWideString8](by-memory/0x004a57e0-0x004a5861.DecoderReadWideString8.md)-[UID:0003LE][0x004a5db0-0x004a5dce.DecoderInitialize](by-memory/0x004a5db0-0x004a5dce.DecoderInitialize.md). Class-level C++ remains blank until the final combined declaration/header shape is accepted.

B005's accepted 2026-06-28 implementation records formal first-draft constructor C++ on exact child page [UID:00013N][0x004a5640-0x004a5664.DecoderConstructor](by-memory/0x004a5640-0x004a5664.DecoderConstructor.md), using the existing Decoder member names `m_inputBuffer`, `m_inputSize`, `m_readPos`, `m_useBigEndian`, and `m_isValid`. Class-level C++ remains blank until the final combined declaration/header shape is accepted.

B009's accepted 2026-06-28 implementation records formal first-draft finalize C++ on exact child page [UID:00013S][0x004a5dd0-0x004a5ded.DecoderFinalize](by-memory/0x004a5dd0-0x004a5ded.DecoderFinalize.md), using the same member names. Current MCP names the function `sub_4A5DD0`, so the old C001 `Decoder_Finalize` IDA name is stale historical evidence; the source-facing `Finalize` method name is retained because this class declaration, [UID:0000IQ][Decoder](by-file/Decoder.md), [UID:0001X1][BinaryCodecVtables](by-type/by-vtable/BinaryCodecVtables.md), and [UID:00013K][0x004a55e0-0x004a5621.EncoderFinalize](by-memory/0x004a55e0-0x004a5621.EncoderFinalize.md) all support the lifecycle naming. [UID:00013S][0x004a5dd0-0x004a5ded.DecoderFinalize](by-memory/0x004a5dd0-0x004a5ded.DecoderFinalize.md) returns prior `m_isValid`, clears `m_inputBuffer`, `m_inputSize`, and `m_readPos`, restores `m_isValid`, and preserves `m_useBigEndian`. The no-caller/no-pointer-route facts remain a confidence cap, not a reason to keep this exact child blank.

B001's accepted 2026-06-29 implementation records formal first-draft ordinary destructor C++ on exact child page [UID:00013O][0x004a5670-0x004a5677.DecoderDestructor](by-memory/0x004a5670-0x004a5677.DecoderDestructor.md). Current MCP session `279422f0` names the body `sub_4A5670`, size `0x7`, with exact bytes `c7 01 d8 92 61 00 c3`, disassembly/decompile as a `Decoder::vftable` restore and return, one block, no callees, no callers, no strings, no cleanup field writes, unique signature `C7 01 D8 92 61 00 C3`, and no incoming xref or VA/RVA pointer route. The source-facing `Decoder::~Decoder()` name follows the existing `virtual ~Decoder()` declaration direction, vtable ownership, Decoder file route, and sibling `Encoder::~Encoder()` source policy. [UID:00013U][0x004a5e00-0x004a5e24.DecoderScalarDeletingDestructor](by-memory/0x004a5e00-0x004a5e24.DecoderScalarDeletingDestructor.md) remains compiler-generated scalar deleting destructor support and must not be hand-authored as source.

## Observed State

```text
+0x00  vtable pointer (`0x006192d8`)
+0x04  input buffer pointer
+0x08  input buffer size/limit; reader bounds checks use signed-compare shape
+0x0c  current read position; reader bounds checks use signed-compare shape
+0x10  byte-order flag; nonzero reads integer values big-endian; SetByteOrder stores the caller byte exactly
+0x11  valid/readable flag
```

This layout is inferred from IDA decompilation/disassembly of the constructor, initializer, reset/finalizer, and raw reader bodies. It should replace the generated 4-byte-only view before source migration.

## Dated Superseded Method Inventory

| Address | Method family | Notes |
| --- | --- | --- |
| `0x004a5640` | constructor | Installs the `Decoder` vtable, clears buffer/limit/cursor, sets flags word to `0x0101`, and now carries first-draft formal C++ on [UID:00013N][0x004a5640-0x004a5664.DecoderConstructor](by-memory/0x004a5640-0x004a5664.DecoderConstructor.md). IDA models this as a function. |
| `0x004a5670` | destructor | Restores the `Decoder` vtable; exact child [UID:00013O][0x004a5670-0x004a5677.DecoderDestructor](by-memory/0x004a5670-0x004a5677.DecoderDestructor.md) now carries first-draft formal `Decoder::~Decoder()` C++. Current MCP models it as `sub_4A5670` with no caller/pointer route, which caps confidence but does not block the exact child body. |
| `0x004a5680` | [UID:0003K8][0x004a5680-0x004a568d.DecoderSetByteOrder](by-memory/0x004a5680-0x004a568d.DecoderSetByteOrder.md) | Exact raw child; stores caller byte into offset `+0x10`. Not an IDA-modeled function. |
| `0x004a5690` | [UID:0003K9][0x004a5690-0x004a56b8.DecoderReadByte](by-memory/0x004a5690-0x004a56b8.DecoderReadByte.md) | Exact raw child; reads one byte and advances by one. Not an IDA-modeled function. |
| `0x004a56c0` | [UID:0003KA][0x004a56c0-0x004a570f.DecoderReadShort](by-memory/0x004a56c0-0x004a570f.DecoderReadShort.md) | Exact raw child; reads a short in selected byte order. Not an IDA-modeled function. |
| `0x004a5710` | [UID:0003KB][0x004a5710-0x004a576f.DecoderReadTriByte](by-memory/0x004a5710-0x004a576f.DecoderReadTriByte.md) | Exact raw child; reads three bytes and assembles them by selected byte order. Not an IDA-modeled function. |
| `0x004a5770` | [UID:0003KC][0x004a5770-0x004a57dc.DecoderReadInt](by-memory/0x004a5770-0x004a57dc.DecoderReadInt.md) | Exact raw child; reads four bytes in selected byte order. Not an IDA-modeled function. |
| `0x004a57e0` | [UID:0003L6][0x004a57e0-0x004a5861.DecoderReadWideString8](by-memory/0x004a57e0-0x004a5861.DecoderReadWideString8.md) | Exact raw child; reads one-byte UTF-16 element count, copies `count * 2` bytes, and terminates output. Not an IDA-modeled function. |
| `0x004a5870` | [UID:0003L7][0x004a5870-0x004a5925.DecoderReadWideString16](by-memory/0x004a5870-0x004a5925.DecoderReadWideString16.md) | Exact raw child; reads byte-order-aware 16-bit UTF-16 element count and copies `count * 2` bytes. Not an IDA-modeled function. |
| `0x004a5930` | [UID:0003L8][0x004a5930-0x004a5a3a.DecoderReadAnsiString8](by-memory/0x004a5930-0x004a5a3a.DecoderReadAnsiString8.md) | Exact raw child; reads one-byte multibyte byte count, copies to stack scratch, and converts through `MultiByteToWideChar`. Not an IDA-modeled function. |
| `0x004a5a40` | [UID:0003L9][0x004a5a40-0x004a5ba7.DecoderReadAnsiString16](by-memory/0x004a5a40-0x004a5ba7.DecoderReadAnsiString16.md) | Exact raw child; reads byte-order-aware 16-bit multibyte byte count, uses large stack scratch, and converts through `MultiByteToWideChar`. Not an IDA-modeled function. |
| `0x004a5bb0` | [UID:0003LA][0x004a5bb0-0x004a5c7e.DecoderReadCString](by-memory/0x004a5bb0-0x004a5c7e.DecoderReadCString.md) | Exact raw child; scans NUL-terminated multibyte input, allocates/copies temporary storage, converts to UTF-16, and frees temporary storage. Not an IDA-modeled function. |
| `0x004a5c80` | [UID:0003LB][0x004a5c80-0x004a5cc4.DecoderReadBytes](by-memory/0x004a5c80-0x004a5cc4.DecoderReadBytes.md) | Exact raw child; copies caller-requested raw byte count to the destination and advances cursor. Not an IDA-modeled function. |
| `0x004a5cd0` | [UID:0003LC][0x004a5cd0-0x004a5d79.DecoderReadCompressedBytes](by-memory/0x004a5cd0-0x004a5d79.DecoderReadCompressedBytes.md) | Exact raw child; reads byte-order-aware compressed length and calls zlib `uncompress` wrapper `0x00414390`. Not an IDA-modeled function. |
| `0x004a5d80` | [UID:0003LD][0x004a5d80-0x004a5da6.DecoderSkipBytes](by-memory/0x004a5d80-0x004a5da6.DecoderSkipBytes.md) | Exact raw child; advances cursor by caller count if `cursor + count + 1` remains within limit. Not an IDA-modeled function. |
| `0x004a5db0` | [UID:0003LE][0x004a5db0-0x004a5dce.DecoderInitialize](by-memory/0x004a5db0-0x004a5dce.DecoderInitialize.md) | Exact raw child; attaches caller buffer/size, resets cursor, and sets valid flag. Not an IDA-modeled function. |
| `0x004a5dd0` | [UID:00013S][0x004a5dd0-0x004a5ded.DecoderFinalize](by-memory/0x004a5dd0-0x004a5ded.DecoderFinalize.md) | Formal finalize child; returns previous valid state, clears buffer/size/cursor, restores valid state, preserves byte order, and now carries first-draft C++ despite no direct caller/pointer route. IDA models this as current placeholder `sub_4A5DD0`. |
| `0x004a5df0` | no-op virtual | Vtable slot at `0x006192dc`; exact child [UID:00013T][0x004a5df0-0x004a5df1.DecoderNoopVirtual](by-memory/0x004a5df0-0x004a5df1.DecoderNoopVirtual.md) now carries formal source-empty `Decoder::NoopVirtual()` C++ using a descriptive/inferred name. |
| `0x004a5e00` | scalar deleting destructor | Restores vtable and conditionally frees the object. |

## Evidence Notes

- IDA MCP decompiles `0x004a5640`, `0x004a5670`, `0x004a5dd0`, and `0x004a5e00` as Decoder-shaped functions.
- IDA disassembly shows aligned raw reader starts from `0x004a5680` through `0x004a5db0`, but `lookup_funcs` reports "Not a function" for most of them.
- IDA xrefs currently show no direct callers for the raw Decoder starts. For the primitive subset [UID:0003K8][0x004a5680-0x004a568d.DecoderSetByteOrder](by-memory/0x004a5680-0x004a568d.DecoderSetByteOrder.md)-[UID:0003KC][0x004a5770-0x004a57dc.DecoderReadInt](by-memory/0x004a5770-0x004a57dc.DecoderReadInt.md), B004 correction rechecked `xrefs_to`, `xref_query`, raw VA/RVA pointer patterns, vtable slots, adjacent table routes, surrounding modeled Decoder functions, and sibling/parent raw-family pages with no direct-entry route found. This is an exhausted no-direct-entry confidence cap, not proof of dead code and not a blocker for the accepted primitive child C++.
- The `Decoder` vtable at `0x006192d8` has two slots: scalar deleting destructor and no-op virtual.
- B006 [UID:0001X1][BinaryCodecVtables](by-type/by-vtable/BinaryCodecVtables.md) recheck confirms exact vtable dwords `0x006192d4 -> 0x00646b74`, `0x006192d8 -> 0x004a5e00`, and `0x006192dc -> 0x004a5df0`; constructor/destructor/scalar-deleting-destructor vtable-store refs at `0x004a5640`, `0x004a5670`, and `0x004a5e0a`; exported `0x004a5df0` as a one-byte no-op with only the vtable data ref; exported `0x004a5e00` as a 36-byte MSVC scalar deleting destructor wrapper; and successor `0x006192e0` as the DAT parser table boundary rather than a third Decoder slot.
- 2026-05-25 IDA MCP recheck reconfirmed the modeled functions, the raw-reader `Not a function` status, empty raw-reader xrefs, and the 18-byte stream layout fields used by the raw bodies.
- 2026-05-26 IDA MCP recheck produced the same split: constructor/destructor/finalize/no-op/scalar-destructor functions are modeled, every raw reader start still reports `Not a function`, and raw-reader `xrefs_to` remains empty. Keep the raw family as reconstructable `Decoder` project code with missing function-boundary data, not ignored code.
- 2026-05-26 IDA MCP vtable/layout recheck confirms vtable refs at `0x004a5640`, `0x004a5670`, and `0x004a5e0a`, and confirms constructor/raw initialize/finalize use the shared cursor fields now documented in [UID:0001TS][BinaryCodecCursorLayout](by-type/by-struct/BinaryCodecCursorLayout.md).
- 2026-06-12 A002 Goal2 split repair documents the primitive reader subset as non-emitting [UID:00013P][0x004a5680-0x004a57dc.DecoderPrimitiveReaders](by-memory/0x004a5680-0x004a57dc.DecoderPrimitiveReaders.md) plus exact children [UID:0003K8][0x004a5680-0x004a568d.DecoderSetByteOrder](by-memory/0x004a5680-0x004a568d.DecoderSetByteOrder.md), [UID:0003K9][0x004a5690-0x004a56b8.DecoderReadByte](by-memory/0x004a5690-0x004a56b8.DecoderReadByte.md), [UID:0003KA][0x004a56c0-0x004a570f.DecoderReadShort](by-memory/0x004a56c0-0x004a570f.DecoderReadShort.md), [UID:0003KB][0x004a5710-0x004a576f.DecoderReadTriByte](by-memory/0x004a5710-0x004a576f.DecoderReadTriByte.md), and [UID:0003KC][0x004a5770-0x004a57dc.DecoderReadInt](by-memory/0x004a5770-0x004a57dc.DecoderReadInt.md). Live IDA MCP reconfirmed each primitive start is still not an IDA function and has no direct xrefs, while exact bytes/padding and raw instruction behavior are now documented on the child pages.
- 2026-06-25 B004 accepted implementation updates the primitive reader declaration direction: exact child pages [UID:0003K8][0x004a5680-0x004a568d.DecoderSetByteOrder](by-memory/0x004a5680-0x004a568d.DecoderSetByteOrder.md)-[UID:0003KC][0x004a5770-0x004a57dc.DecoderReadInt](by-memory/0x004a5770-0x004a57dc.DecoderReadInt.md) now carry first-draft formal C++ for `SetByteOrder`, `ReadByte`, `ReadShort`, `ReadTriByte`, and `ReadInt`, while [UID:00013P][0x004a5680-0x004a57dc.DecoderPrimitiveReaders](by-memory/0x004a5680-0x004a57dc.DecoderPrimitiveReaders.md) remains a non-emitting split index. Live MCP session `80de0a67` reconfirmed raw no-function/no-xref status, no raw VA pointer route, exact instruction bodies, padding boundaries, and surrounding modeled constructor/finalize Decoder fields. `m_useBigEndian` is byte-like because `SetByteOrder` stores the caller byte exactly; `m_inputSize` and `m_readPos` are signed-compare-shaped in primitive reader bounds checks.
- 2026-06-25 B004 accepted [UID:00013R][0x004a57e0-0x004a5dce.DecoderStringAndBlobReaders](by-memory/0x004a57e0-0x004a5dce.DecoderStringAndBlobReaders.md) implementation updates the string/blob/raw-span declaration direction: exact child pages [UID:0003L6][0x004a57e0-0x004a5861.DecoderReadWideString8](by-memory/0x004a57e0-0x004a5861.DecoderReadWideString8.md)-[UID:0003LE][0x004a5db0-0x004a5dce.DecoderInitialize](by-memory/0x004a5db0-0x004a5dce.DecoderInitialize.md) now carry first-draft formal C++ for wide-string, multibyte-string, C-string, raw-span, compressed-span, skip, and initialize readers, while [UID:00013R][0x004a57e0-0x004a5dce.DecoderStringAndBlobReaders](by-memory/0x004a57e0-0x004a5dce.DecoderStringAndBlobReaders.md) remains a non-emitting split index. Live MCP session `80de0a67` reconfirmed raw no-function/no-xref/no-pointer-route status, exact body instruction counts, helper dependencies, and padding boundaries.
- 2026-06-28 B005 accepted [UID:00013N][0x004a5640-0x004a5664.DecoderConstructor](by-memory/0x004a5640-0x004a5664.DecoderConstructor.md) implementation updates the constructor declaration direction: the exact child page now carries first-draft formal C++ for `Decoder::Decoder()`, mapping the constructor stores to `m_inputBuffer(NULL)`, `m_inputSize(0)`, `m_readPos(0)`, `m_useBigEndian(true)`, and `m_isValid(true)`. Live MCP session `b005_00013N_20260628` reconfirmed the exact range, one-block/no-callee/no-caller shape, vtable-base refs, no VA/RVA pointer route, and `0x0101` as adjacent true byte-order/valid bytes (Verified with int_convert.py).
- 2026-06-28 B009 accepted [UID:00013S][0x004a5dd0-0x004a5ded.DecoderFinalize](by-memory/0x004a5dd0-0x004a5ded.DecoderFinalize.md) implementation updates the finalize declaration direction: the exact child page now carries first-draft formal C++ for `Decoder::Finalize()`, mapping current MCP `sub_4A5DD0` to source-facing finalize/reset behavior. Session `supervisor_20260628_resume` reconfirmed `NexusTK.exe`, imagebase `0x400000`, healthy auto-analysis/Hex-Rays/strings, exact size `0x1d` / 29 bytes (Verified with int_convert.py), raw bytes `8a 41 11 c7 41 04 00 00 00 00 c7 41 08 00 00 00 00 c7 41 0c 00 00 00 00 c6 41 11 01 c3`, one-block/no-callee/no-caller/no-string shape, zero incoming xrefs, no VA/RVA pointer route, and no vtable slot. The body reads prior `+0x11`, clears `+0x04/+0x08/+0x0c`, writes `+0x11 = 1`, and does not touch `+0x10`.
- 2026-06-29 B001 accepted [UID:00013O][0x004a5670-0x004a5677.DecoderDestructor](by-memory/0x004a5670-0x004a5677.DecoderDestructor.md) implementation updates the ordinary destructor declaration direction: the exact child page now carries first-draft formal C++ for `Decoder::~Decoder()`. Current MCP session `279422f0` reconfirmed `NexusTK.exe.i64`, health OK, exact size `0x7` / 7 bytes, bytes `c7 01 d8 92 61 00 c3`, current IDA placeholder `sub_4A5670`, one-block/no-callee/no-caller/no-string shape, unique signature `C7 01 D8 92 61 00 C3`, surrounding `0xcc` padding, no incoming xrefs, no VA/RVA pointer route, and Decoder vtable-base refs from `0x004a5640`, `0x004a5670`, and `0x004a5e0a`. The body has no buffer cleanup and does not call `Finalize()`, so it emits as an empty source destructor while compiler vptr stores are regenerated by the compiler.
- 2026-07-05 B002 accepted [UID:00013T][0x004a5df0-0x004a5df1.DecoderNoopVirtual](by-memory/0x004a5df0-0x004a5df1.DecoderNoopVirtual.md) implementation updates the no-op virtual declaration direction: the exact child now carries formal source-empty `Decoder::NoopVirtual()` C++. Current MCP session `supervisor_recovery_20260705` confirms `NexusTK.exe`, imagebase `0x400000`, health OK, `nullsub_28` size `0x1`, byte `c3`, one basic block, empty decompile, no callers/callees, sole data xref `0x006192dc`, no slot-address xrefs, no RVA pointer-pattern route, and Decoder vtable dwords `0x006192d8 -> 0x004a5e00` / `0x006192dc -> 0x004a5df0`. `NoopVirtual` is descriptive/inferred; unknown original spelling remains a confidence cap, not a no-code reason.
- 2026-06-12 A002 Goal2 split repair documents the string/blob reader subset as non-emitting [UID:00013R][0x004a57e0-0x004a5dce.DecoderStringAndBlobReaders](by-memory/0x004a57e0-0x004a5dce.DecoderStringAndBlobReaders.md) plus exact children [UID:0003L6][0x004a57e0-0x004a5861.DecoderReadWideString8](by-memory/0x004a57e0-0x004a5861.DecoderReadWideString8.md) through [UID:0003LE][0x004a5db0-0x004a5dce.DecoderInitialize](by-memory/0x004a5db0-0x004a5dce.DecoderInitialize.md). Live IDA MCP reconfirmed every string/blob start is still not an IDA function and has no direct xrefs, while exact bytes/padding, copy/conversion/zlib helper calls, cursor/valid behavior, and raw instruction behavior are now documented on the child pages.
- 2026-06-12 A003 Batch 344 live IDA MCP `server_health` confirms session `b001_nexustk` is on `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` with Hex-Rays ready.
- 2026-06-12 A003 Batch 344 live IDA MCP `get_bytes` reconfirms [UID:0003IB][0x006192d4-0x006192e0.DecoderVtableData](by-memory/0x006192d4-0x006192e0.DecoderVtableData.md) as the `0xc` / 12-byte Decoder RTTI/vtable record (Verified with int_convert.py): RTTI pointer `0x00646b74`, scalar deleting destructor slot `0x004a5e00`, and no-op virtual slot `0x004a5df0`.
- 2026-06-12 A003 Batch 344 live IDA MCP `xrefs_to` reconfirms three refs to the Decoder vtable base at `0x006192d8` from `0x004a5640`, `0x004a5670`, and `0x004a5e0a`; `0x006192dc` has no ordinary refs, matching the no-op virtual-slot interpretation.
- 2026-06-12 A003 Batch 344 live IDA MCP `decompile` reconfirms the modeled class surface: the constructor installs the vtable, clears buffer/limit/cursor, and writes flags word `0x0101`; the destructor restores the vtable; `Finalize` returns the prior valid flag and clears stream state; and the scalar deleting destructor restores the vtable before optional delete.
- 2026-06-12 A003 Batch 344 live IDA MCP `lookup_funcs` and `xrefs_to` reconfirm the caveat for all raw starts from `0x004a5680` through `0x004a5db0`: each remains `Not a function` and has no direct code/data xrefs in the active IDB.

## Dated Superseded Score Rationale

The class now clears the `85/85` parent gate with margin because the page has a complete observed field layout, modeled lifecycle/vtable-support method inventory, exact vtable child, exact raw primitive and string/blob reader child coverage, and fresh live IDA evidence proving the constructor/destructor/deleting-destructor ownership of the vtable. Completion and confidence remain below final-audit quality because the raw reader methods still lack IDA function objects, the primitive direct-entry route is exhausted negative in the current IDB, original source names/signatures remain final-audit caveats, and class-level declaration emission is not final.

## Dated Superseded Caveats

- Generated `Decoder.cpp` now emits accepted exact method children through this class after validator refresh. B002's UID00013T callback resolves the previous no-op virtual empty-marker state with a source-empty `Decoder::NoopVirtual()` body; validator-owned refresh now shows UID00013T as `Decoder::NoopVirtual()` instead of an empty marker.
- Generated metadata reports `Decoder` as a 4-byte minimal base; the raw code proves the real layout is larger and stream-like.
- [UID:00013N][0x004a5640-0x004a5664.DecoderConstructor](by-memory/0x004a5640-0x004a5664.DecoderConstructor.md) now carries accepted first-draft constructor C++; class-level declaration C++ still remains blank.
- [UID:00013S][0x004a5dd0-0x004a5ded.DecoderFinalize](by-memory/0x004a5dd0-0x004a5ded.DecoderFinalize.md) now carries accepted first-draft finalize C++; class-level declaration C++ still remains blank because the combined header/source declaration remains a class-level final-audit question.
- [UID:00013O][0x004a5670-0x004a5677.DecoderDestructor](by-memory/0x004a5670-0x004a5677.DecoderDestructor.md) now carries accepted first-draft ordinary destructor C++; class-level declaration C++ still remains blank because method bodies belong on exact by-memory children and the combined header/source declaration remains a class-level final-audit question.
- Primitive exact children [UID:0003K8][0x004a5680-0x004a568d.DecoderSetByteOrder](by-memory/0x004a5680-0x004a568d.DecoderSetByteOrder.md)-[UID:0003KC][0x004a5770-0x004a57dc.DecoderReadInt](by-memory/0x004a5770-0x004a57dc.DecoderReadInt.md) and string/blob exact children [UID:0003L6][0x004a57e0-0x004a5861.DecoderReadWideString8](by-memory/0x004a57e0-0x004a5861.DecoderReadWideString8.md)-[UID:0003LE][0x004a5db0-0x004a5dce.DecoderInitialize](by-memory/0x004a5db0-0x004a5dce.DecoderInitialize.md) now carry accepted first-draft method C++ despite raw no-function/no-xref status, with those facts preserved as confidence caps rather than exclusion proof.

## Cross-References

- [UID:0000IQ][Decoder](by-file/Decoder.md)
- [UID:0000HQ][BinaryCodec](by-file/BinaryCodec.md)
- [UID:00004F][Encoder](by-class/Encoder.md)
- [UID:00013M][0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue](by-memory/0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue.md)
- [UID:00013Q][0x004a5680-0x004a5dce.DecoderRawReaderFamily](by-memory/0x004a5680-0x004a5dce.DecoderRawReaderFamily.md)
- [UID:00013P][0x004a5680-0x004a57dc.DecoderPrimitiveReaders](by-memory/0x004a5680-0x004a57dc.DecoderPrimitiveReaders.md)
- [UID:0003K8][0x004a5680-0x004a568d.DecoderSetByteOrder](by-memory/0x004a5680-0x004a568d.DecoderSetByteOrder.md)
- [UID:0003K9][0x004a5690-0x004a56b8.DecoderReadByte](by-memory/0x004a5690-0x004a56b8.DecoderReadByte.md)
- [UID:0003KA][0x004a56c0-0x004a570f.DecoderReadShort](by-memory/0x004a56c0-0x004a570f.DecoderReadShort.md)
- [UID:0003KB][0x004a5710-0x004a576f.DecoderReadTriByte](by-memory/0x004a5710-0x004a576f.DecoderReadTriByte.md)
- [UID:0003KC][0x004a5770-0x004a57dc.DecoderReadInt](by-memory/0x004a5770-0x004a57dc.DecoderReadInt.md)
- [UID:00013R][0x004a57e0-0x004a5dce.DecoderStringAndBlobReaders](by-memory/0x004a57e0-0x004a5dce.DecoderStringAndBlobReaders.md)
- [UID:0003L6][0x004a57e0-0x004a5861.DecoderReadWideString8](by-memory/0x004a57e0-0x004a5861.DecoderReadWideString8.md)
- [UID:0003L7][0x004a5870-0x004a5925.DecoderReadWideString16](by-memory/0x004a5870-0x004a5925.DecoderReadWideString16.md)
- [UID:0003L8][0x004a5930-0x004a5a3a.DecoderReadAnsiString8](by-memory/0x004a5930-0x004a5a3a.DecoderReadAnsiString8.md)
- [UID:0003L9][0x004a5a40-0x004a5ba7.DecoderReadAnsiString16](by-memory/0x004a5a40-0x004a5ba7.DecoderReadAnsiString16.md)
- [UID:0003LA][0x004a5bb0-0x004a5c7e.DecoderReadCString](by-memory/0x004a5bb0-0x004a5c7e.DecoderReadCString.md)
- [UID:0003LB][0x004a5c80-0x004a5cc4.DecoderReadBytes](by-memory/0x004a5c80-0x004a5cc4.DecoderReadBytes.md)
- [UID:0003LC][0x004a5cd0-0x004a5d79.DecoderReadCompressedBytes](by-memory/0x004a5cd0-0x004a5d79.DecoderReadCompressedBytes.md)
- [UID:0003LD][0x004a5d80-0x004a5da6.DecoderSkipBytes](by-memory/0x004a5d80-0x004a5da6.DecoderSkipBytes.md)
- [UID:0003LE][0x004a5db0-0x004a5dce.DecoderInitialize](by-memory/0x004a5db0-0x004a5dce.DecoderInitialize.md)
- [UID:0001TS][BinaryCodecCursorLayout](by-type/by-struct/BinaryCodecCursorLayout.md)
- [UID:0001X1][BinaryCodecVtables](by-type/by-vtable/BinaryCodecVtables.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- 2026-07-05 B002 [UID:00013T][0x004a5df0-0x004a5df1.DecoderNoopVirtual](by-memory/0x004a5df0-0x004a5df1.DecoderNoopVirtual.md) implementation:
  - Before/after class score unchanged: `87/88`.
  - Summary/evidence: recorded that the exact no-op virtual child now emits formal source-empty `Decoder::NoopVirtual()` C++ through this class, while [UID:00013U][0x004a5e00-0x004a5e24.DecoderScalarDeletingDestructor](by-memory/0x004a5e00-0x004a5e24.DecoderScalarDeletingDestructor.md) remains separate compiler-generated scalar deleting destructor support. Current MCP session `supervisor_recovery_20260705` confirms the target's one-byte `c3` / `retn` body, one basic block, empty decompile, no callers/callees, sole vtable data xref `0x006192dc`, no slot-address refs, VA/RVA pointer-pattern results, and the compact Decoder vtable dwords. The `NoopVirtual` spelling remains descriptive/inferred, with `nullsub_28` preserved only as a raw alias.
- 2026-06-29 B001 [UID:00013O][0x004a5670-0x004a5677.DecoderDestructor](by-memory/0x004a5670-0x004a5677.DecoderDestructor.md) implementation:
  - Before/after class score unchanged: `87/88`.
  - Summary/evidence: recorded that the exact ordinary destructor child now carries formal first-draft `Decoder::~Decoder()` C++ while scalar deleting destructor [UID:00013U][0x004a5e00-0x004a5e24.DecoderScalarDeletingDestructor](by-memory/0x004a5e00-0x004a5e24.DecoderScalarDeletingDestructor.md) remains compiler-generated support. Current MCP session `279422f0` confirms `sub_4A5670` size `0x7`, bytes `c7 01 d8 92 61 00 c3`, vtable-restore-only behavior, no callees/callers/strings, no cleanup field writes, unique signature, padding, no incoming xrefs, no VA/RVA pointer route, and Decoder vtable-base refs from constructor/destructor/scalar-deleting destructor. The no-route facts remain confidence caps, not a reason to keep the exact ordinary destructor blank.
- 2026-06-28 B009 [UID:00013S][0x004a5dd0-0x004a5ded.DecoderFinalize](by-memory/0x004a5dd0-0x004a5ded.DecoderFinalize.md) implementation:
  - Before/after class score unchanged: `87/88`.
  - Summary/evidence: recorded that the exact finalize child now carries formal first-draft `Decoder::Finalize()` C++ using `m_inputBuffer`, `m_inputSize`, `m_readPos`, and `m_isValid`, while preserving `m_useBigEndian`. Current MCP session `supervisor_20260628_resume` names the function `sub_4A5DD0`, so older `Decoder_Finalize` IDA-name wording is stale historical evidence and not source-name proof. The class keeps `Finalize` as the accepted source-facing name from class/file/type guidance and Encoder sibling symmetry. No direct caller, incoming xref, VA/RVA pointer route, or vtable slot was found; those facts cap confidence but no longer block the exact child C++. Class-level C++ remains blank because this page is declaration/header guidance, and method bodies belong on exact by-memory children.
- 2026-06-28 B005 [UID:00013N][0x004a5640-0x004a5664.DecoderConstructor](by-memory/0x004a5640-0x004a5664.DecoderConstructor.md) implementation:
  - Before/after class score unchanged: `87/88`.
  - Summary/evidence: recorded that the exact constructor child now carries formal first-draft `Decoder::Decoder()` C++ using the existing Decoder member names. Preserved the class-level declaration/header C++ block as blank, because the constructor body belongs to the exact by-memory child while the final combined class declaration remains open.
- 2026-06-25 B004 [UID:00013R][0x004a57e0-0x004a5dce.DecoderStringAndBlobReaders](by-memory/0x004a57e0-0x004a5dce.DecoderStringAndBlobReaders.md) implementation:
  - Before/after class score unchanged: `87/88`.
  - Summary/evidence: added string/blob/raw-span declaration direction for `ReadWideString8`, `ReadWideString16`, `ReadAnsiString8`, `ReadAnsiString16`, `ReadCString`, `ReadBytes`, `ReadCompressedBytes`, and `SkipBytes`; recorded that exact child pages [UID:0003L6][0x004a57e0-0x004a5861.DecoderReadWideString8](by-memory/0x004a57e0-0x004a5861.DecoderReadWideString8.md)-[UID:0003LE][0x004a5db0-0x004a5dce.DecoderInitialize](by-memory/0x004a5db0-0x004a5dce.DecoderInitialize.md) now carry first-draft formal C++; and removed the prior string/blob C++ blocker from the class caveats while preserving raw no-function/no-xref/no-pointer status as a confidence cap.
- 2026-06-25 B004 [UID:00013P][0x004a5680-0x004a57dc.DecoderPrimitiveReaders](by-memory/0x004a5680-0x004a57dc.DecoderPrimitiveReaders.md) implementation:
  - Before/after class score unchanged: `87/88`.
  - Summary/evidence: added primitive reader declaration direction for `SetByteOrder`, `ReadByte`, `ReadShort`, `ReadTriByte`, and `ReadInt`; recorded that the method names are descriptive/source-facing, not original-symbol proof; recorded byte-like `m_useBigEndian` because `SetByteOrder` stores the caller byte exactly; and recorded signed-compare-shaped `m_inputSize`/`m_readPos` semantics for reader bounds checks. Exact child pages now carry first-draft formal C++ while the broad primitive split index remains non-emitting.
- 2026-06-21 B006 [UID:0001X1][BinaryCodecVtables](by-type/by-vtable/BinaryCodecVtables.md) source-quality incorporation:
  - Before/after class score unchanged: `87/88`.
  - Summary/evidence: added declaration-level vtable guidance: `virtual ~Decoder()` plus descriptive `virtual void NoopVirtual()` for the concrete no-op vtable slot, with scalar deleting destructor kept compiler-generated. The exact vtable data child remains class-owned while [UID:0001X1][BinaryCodecVtables](by-type/by-vtable/BinaryCodecVtables.md) stays the BinaryCodec family aggregate and `0x006192e0` remains outside the Decoder vtable.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `78/78`.
  - Summary/evidence: cursor layout, modeled constructor/destructor/finalize/destructor glue, raw primitive/string/blob reader families, vtable identity, and Wave3 caveats are documented; confidence remains limited by unmodeled raw-reader function boundaries and empty xrefs.
- 2026-05-31:
  - Before: the class was documented as reconstructable in prose but validator `RECONSTRUCTABLE` metadata was blank.
  - After: `RECONSTRUCTABLE` is set to `TRUE`.
  - Summary/evidence: IDA MCP reconfirmed the Decoder constructor/destructor/no-op/scalar-deleting vtable surface and raw-reader caveats. This old class-level no-code rationale is superseded for exact primitive children: [UID:0003K8][0x004a5680-0x004a568d.DecoderSetByteOrder](by-memory/0x004a5680-0x004a568d.DecoderSetByteOrder.md)-[UID:0003KC][0x004a5770-0x004a57dc.DecoderReadInt](by-memory/0x004a5770-0x004a57dc.DecoderReadInt.md) now clear the active combined-score/emitter gate and carry first-draft formal method C++; class-level declaration/header shape remains open.
- 2026-06-03:
  - Before: scores were `78/78` and the legacy parent/source-root route was blank while the file parent still had low confidence.
  - After: scores are `80/82`, `CANONICAL_OWNER` is [UID:0000IQ][Decoder](by-file/Decoder.md), and the emitter route reaches the same file root.
  - Summary/evidence: the class page already records the full observed state, modeled lifecycle functions, raw reader starts, vtable slots, generated-size caveat, and links to the strengthened layout/vtable/source-root docs. Class-level C++ remains blank because final header/source declaration shape is still open; exact primitive children now carry accepted first-draft method C++ where supported.
- 2026-06-12 A003 Batch 344:
  - Before: scores were `80/82`; [UID:0003IB][0x006192d4-0x006192e0.DecoderVtableData](by-memory/0x006192d4-0x006192e0.DecoderVtableData.md) was blocked from routing by the class parent score.
  - After: scores are `85/86`; the existing file parent remains [UID:0000IQ][Decoder](by-file/Decoder.md), and the Decoder vtable child can now attach directly to this class.
  - Summary/evidence: fresh live IDA MCP reconfirmed the exact Decoder vtable bytes and refs, modeled constructor/destructor/finalize/scalar-deleting-destructor behavior, observed `0x12` / 18-byte stream-state footprint (Verified with int_convert.py), and the raw-reader non-function/no-xref confidence cap.
- 2026-06-12 A002 Goal2 primitive-reader split:
  - What existed before: the primitive reader table pointed at the broad [UID:00013P][0x004a5680-0x004a57dc.DecoderPrimitiveReaders](by-memory/0x004a5680-0x004a57dc.DecoderPrimitiveReaders.md) block.
  - Changed to: exact primitive children [UID:0003K8][0x004a5680-0x004a568d.DecoderSetByteOrder](by-memory/0x004a5680-0x004a568d.DecoderSetByteOrder.md), [UID:0003K9][0x004a5690-0x004a56b8.DecoderReadByte](by-memory/0x004a5690-0x004a56b8.DecoderReadByte.md), [UID:0003KA][0x004a56c0-0x004a570f.DecoderReadShort](by-memory/0x004a56c0-0x004a570f.DecoderReadShort.md), [UID:0003KB][0x004a5710-0x004a576f.DecoderReadTriByte](by-memory/0x004a5710-0x004a576f.DecoderReadTriByte.md), and [UID:0003KC][0x004a5770-0x004a57dc.DecoderReadInt](by-memory/0x004a5770-0x004a57dc.DecoderReadInt.md) now carry the reconstructable primitive methods and route directly to this class at positions `30` through `70`.
  - Summary/evidence: live IDA MCP verified each exact raw body, zero direct xrefs, no function-object status, and padding boundaries; the class cleared the strict parent gate and later moved to `87/88` after the string/blob split.
- 2026-06-12 A002 Goal2 string/blob-reader split:
  - What existed before: the method inventory listed the string/blob reader subset as raw unlinked starts under broad [UID:00013R][0x004a57e0-0x004a5dce.DecoderStringAndBlobReaders](by-memory/0x004a57e0-0x004a5dce.DecoderStringAndBlobReaders.md).
  - Changed to: exact string/blob/raw-span/compressed/skip/initialize children [UID:0003L6][0x004a57e0-0x004a5861.DecoderReadWideString8](by-memory/0x004a57e0-0x004a5861.DecoderReadWideString8.md) through [UID:0003LE][0x004a5db0-0x004a5dce.DecoderInitialize](by-memory/0x004a5db0-0x004a5dce.DecoderInitialize.md) now carry the reconstructable raw methods and route directly to this class at positions `71` through `79`; class score `85/86 -> 87/88`.
  - Summary/evidence: live IDA MCP verified each exact raw body, zero direct xrefs, no function-object status, helper calls, cursor/valid behavior, and all padding boundaries. The class is stronger as a parent, while final C++ remains gated by raw function recovery.
