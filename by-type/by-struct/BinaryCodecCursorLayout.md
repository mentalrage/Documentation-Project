*** UID:0001TS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# Binary Codec Cursor Layout

## 2026-08-15 Final Layout Disposition

This page is exact non-emitting ABI evidence owned by [UID:0000HQ][BinaryCodec](by-file/BinaryCodec.md). It must not duplicate either class declaration: the complete Encoder and Decoder H fragments now live on [UID:00004F][Encoder](by-class/Encoder.md) and [UID:00003M][Decoder](by-class/Decoder.md).

Both standalone classes are exactly `0x14` bytes. Their common physical pattern is vptr `+0x00`, buffer pointer `+0x04`, signed `int` capacity/size `+0x08`, signed `int` cursor `+0x0c`, one-byte `bool` big-endian selector `+0x10`, one-byte `bool` writable/valid state `+0x11`, and two bytes of tail alignment. The source uses no shared base. Earlier open questions about final size/header split, unsigned cursor fields, or a byte-like non-bool selector are superseded; only exact retail field spellings remain unavailable.

## Dated Superseded Status

- Entity kind: shared object layout for [UID:00004F][Encoder](by-class/Encoder.md) and [UID:00003M][Decoder](by-class/Decoder.md).
- Confidence: strong for observed offsets, constructor initialization, initialize/finalize field use, and raw reader/writer field use.
- Remaining caveat: final source-facing field names and tail padding/`sizeof` are not proven.
- Likely owner header: `NexusTK/util/Encoder.h`, `NexusTK/util/Decoder.h`, or a compact `NexusTK/util/BinaryCodec.h`.
- Parent attachment: attached to [UID:0000HQ][BinaryCodec](by-file/BinaryCodec.md), now `86/88`, because this is a shared layout across both codec classes.
- C++ reconstruction: intentionally blank for this shared layout page until final header ownership, class split, final field spellings, and tail padding are settled. Exact method child pages may still emit first-draft C++ when their own reconstructable/emitter/combined-score gate is met.
- Vtable relationship: [UID:0001X1][BinaryCodecVtables](by-type/by-vtable/BinaryCodecVtables.md) proves both concrete classes have a vptr at `+0x00` and the same two-slot virtual shape: a generated scalar deleting destructor slot followed by a concrete one-byte no-op virtual slot. That supports the shared cursor-state layout but does not by itself settle final field spellings, header ownership, or `sizeof` padding.

## Layout

`Encoder` and `Decoder` use the same cursor-state footprint through offset `+0x11`.

| Offset | Field hypothesis | Encoder interpretation | Decoder interpretation | Evidence |
| --- | --- | --- | --- | --- |
| `0x00` | vtable pointer | `0x006192cc` | `0x006192d8` | Constructors and destructors install the class vtable. |
| `0x04` | buffer pointer | `m_outputBuffer` output byte buffer | `m_inputBuffer` input byte buffer | Constructors clear it; initialize methods store caller buffer. |
| `0x08` | buffer size / limit | `m_capacity` / `m_outputCapacity` output capacity | `m_inputSize` / input limit; primitive readers use signed-compare-shaped bounds checks | Initialize methods store caller size. |
| `0x0c` | cursor | `m_writePos` | `m_readPos`; primitive readers use signed-compare-shaped cursor growth | Initialize/finalize reset it; read/write bodies advance it. |
| `0x10` | `m_useBigEndian` byte-order flag | nonzero writes integer values big-endian | nonzero reads integer values big-endian; `Decoder::SetByteOrder` stores the caller byte exactly | Constructors write flags word `0x0101`; raw `Decoder::SetByteOrder` writes this byte; `Encoder::Initialize` preserves it. |
| `0x11` | `m_isWritable` / `m_isValid` valid flag | writable/valid state | readable/valid state | Constructors and initialize/finalize set it to `1`; overrun paths clear it. |

Observed field use spans `0x12` bytes. Final C++ `sizeof` and tail padding should remain open until allocation/caller evidence proves whether the original declaration packed the two flag bytes or rounded to 4-byte alignment.

## Live IDA Evidence

2026-06-04 IDA MCP checks confirmed:

- `Encoder::Encoder` at `0x004a4e70-0x004a4e94` stores vtable `0x006192cc`, clears dwords `+0x04`, `+0x08`, and `+0x0c`, then writes word `0x0101` at `+0x10`.
- `Decoder::Decoder` at `0x004a5640-0x004a5664` stores vtable `0x006192d8`, clears dwords `+0x04`, `+0x08`, and `+0x0c`, then writes word `0x0101` at `+0x10`.
- `Encoder::Initialize` at `0x004a55c0-0x004a55de` writes buffer/size at `+0x04/+0x08`, clears cursor `+0x0c`, and writes valid byte `+0x11`.
- B003/B004 Rule 26 reanalysis confirms `Encoder::Initialize` writes only `+0x04`, `+0x08`, `+0x0c`, and `+0x11`; it does not write `+0x10`, so byte-order state is intentionally preserved across buffer attach/reset. B004 independently verified the same `0x1e` body from hash-matched local PE bytes while IDA MCP was unavailable.
- `Encoder::Finalize` at `0x004a55e0-0x004a5621` reads valid byte `+0x11`, optionally reports cursor `+0x0c` as a 32-bit byte count, writes the trailing NUL through buffer `+0x04` at that cursor, clears buffer/size/cursor, restores valid byte `+0x11`, leaves byte-order flag `+0x10` unchanged, and returns the saved previous valid/writable state.
- `Decoder::Finalize` at `0x004a5dd0-0x004a5ded` reads valid byte `+0x11`, clears buffer/size/cursor at `+0x04/+0x08/+0x0c`, restores valid byte `+0x11`, and preserves byte-order flag `+0x10`.
- Writer bodies at `0x004a4ec0`, `0x004a4f00`, `0x004a4ff0`, and `0x004a5480` check valid byte `+0x11`, compare limit `+0x08` with cursor growth from `+0x0c`, use buffer `+0x04`, and honor byte-order flag `+0x10` for scalar values.
- B011's [UID:00013F][0x004a4ec0-0x004a4ef1.EncoderWriteByte](by-memory/0x004a4ec0-0x004a4ef1.EncoderWriteByte.md) source-quality pass confirms the byte-writer side of that rule: `WriteByte` uses `m_outputBuffer`, `m_capacity`, `m_writePos`, and `m_isWritable`, requires `m_capacity >= m_writePos + 2` to preserve [UID:00013K][0x004a55e0-0x004a5621.EncoderFinalize](by-memory/0x004a55e0-0x004a5621.EncoderFinalize.md)'s trailing NUL, and does not read byte-order flag `+0x10`.
- B012's [UID:00013G][0x004a4f00-0x004a4f59.EncoderWriteShort](by-memory/0x004a4f00-0x004a4f59.EncoderWriteShort.md) source-quality pass confirms the 16-bit scalar-writer side of that rule: `WriteShort` uses `m_outputBuffer`, `m_capacity`, `m_writePos`, `m_useBigEndian`, and `m_isWritable`, requires `m_capacity >= m_writePos + 3` to preserve [UID:00013K][0x004a55e0-0x004a5621.EncoderFinalize](by-memory/0x004a55e0-0x004a5621.EncoderFinalize.md)'s trailing NUL, writes high-byte-first when `+0x10` is set, and uses a direct native 16-bit store when `+0x10` is clear.
- B009's [UID:00013H][0x004a4ff0-0x004a506b.EncoderWriteInt](by-memory/0x004a4ff0-0x004a506b.EncoderWriteInt.md) source-quality pass confirms the 32-bit scalar-writer side of that rule: `WriteInt` uses `m_outputBuffer`, `m_capacity`, `m_writePos`, `m_useBigEndian`, and `m_isWritable`, requires `m_capacity >= m_writePos + 5` to preserve [UID:00013K][0x004a55e0-0x004a5621.EncoderFinalize](by-memory/0x004a55e0-0x004a5621.EncoderFinalize.md)'s trailing NUL, writes MSB-to-LSB when `+0x10` is set, and uses a direct native little-endian dword store when `+0x10` is clear.
- Raw [UID:00013P][0x004a5680-0x004a57dc.DecoderPrimitiveReaders](by-memory/0x004a5680-0x004a57dc.DecoderPrimitiveReaders.md) and [UID:00013R][0x004a57e0-0x004a5dce.DecoderStringAndBlobReaders](by-memory/0x004a57e0-0x004a5dce.DecoderStringAndBlobReaders.md) use the same field offsets for input buffer, limit, cursor, byte-order flag, and validity.
- B004's accepted 2026-06-25 [UID:00013P][0x004a5680-0x004a57dc.DecoderPrimitiveReaders](by-memory/0x004a5680-0x004a57dc.DecoderPrimitiveReaders.md) implementation confirms the Decoder primitive-reader side of the layout: `SetByteOrder` writes the raw caller byte into `+0x10` without boolean normalization; `ReadByte`, `ReadShort`, `ReadTriByte`, and `ReadInt` compare `+0x08` against `+0x0c + width` with signed-compare shape; underflow clears `+0x11`; successful reads advance `+0x0c`; and multi-byte readers choose byte assembly/native paths from `+0x10`.
- B004's accepted 2026-06-25 [UID:00013R][0x004a57e0-0x004a5dce.DecoderStringAndBlobReaders](by-memory/0x004a57e0-0x004a5dce.DecoderStringAndBlobReaders.md) implementation confirms the Decoder string/blob/raw-span side of the layout: draft child C++ uses `m_inputBuffer`, `m_inputSize`, `m_readPos`, `m_useBigEndian`, and `m_isValid`; wide/byte readers use `+0x04/+0x08/+0x0c/+0x11`; 16-bit length and compressed readers additionally use `+0x10`; multibyte readers use 0x100/0x10000 stack scratch plus KERNEL32 `MultiByteToWideChar`; the compressed reader calls zlib `uncompress` while cursor/valid ownership remains Decoder; `SkipBytes` preserves the `cursor + count + 1` sentinel check; and `Initialize` attaches buffer/size, clears cursor, and sets valid.
- B009's accepted 2026-06-28 [UID:00013S][0x004a5dd0-0x004a5ded.DecoderFinalize](by-memory/0x004a5dd0-0x004a5ded.DecoderFinalize.md) implementation confirms the Decoder finalize side of the layout with current MCP session `supervisor_20260628_resume`: active IDA placeholder `sub_4A5DD0`, exact range `0x004a5dd0-0x004a5ded`, size `0x1d` / 29 bytes (Verified with int_convert.py), raw bytes `8a 41 11 c7 41 04 00 00 00 00 c7 41 08 00 00 00 00 c7 41 0c 00 00 00 00 c6 41 11 01 c3`, one-block/no-callee/no-caller/no-string shape, no incoming xrefs, no VA/RVA pointer route, and no Decoder vtable slot. The accepted source model reads prior `m_isValid`, clears `m_inputBuffer`, `m_inputSize`, and `m_readPos`, restores `m_isValid`, and leaves `m_useBigEndian` unchanged.

## Dated Superseded Open Questions

- Final `sizeof` remains open: the observed fields span `0x12` bytes, but the original C++ layout may have rounded or packed tail padding.
- Final class split remains a broader layout final-audit caveat between separate `Encoder.h` / `Decoder.h` declarations and a compact shared `BinaryCodec.h` helper header. The IDA vtables and identical cursor offsets support a shared layout contract, but the raw Decoder reader family still lacks function objects and direct-entry routes, so a shared base type or exact original header name is not safe to force from this layout page alone.
- The no-op virtual declarations should be treated as descriptive placeholders (`NoopVirtual`) until better evidence appears. B006's [UID:0001X1][BinaryCodecVtables](by-type/by-vtable/BinaryCodecVtables.md) recheck rejects raw `nullsub_27` / `nullsub_28` as source-quality names, rejects pure-virtual interpretation because both bodies are concrete `ret` functions, and confirms scalar deleting destructor wrappers are compiler-generated from `virtual ~Encoder()` / `virtual ~Decoder()`.
- Source-facing helper names were investigated on 2026-06-16. The modeled Encoder lifecycle/writer and Decoder lifecycle/deleting-destructor functions were still generic `sub_...` names in IDA, while the raw Decoder reader starts remained non-functions with zero direct xrefs. Existing exact child docs support the modeled method names strongly enough for IDA function renames, but not for promoting raw reader starts into functions or emitting final C++.
- B003/B004 [UID:00013J][0x004a55c0-0x004a55de.EncoderInitialize](by-memory/0x004a55c0-0x004a55de.EncoderInitialize.md) source-quality passes narrow the Encoder-side names to `m_outputBuffer`, `m_capacity` / `m_outputCapacity`, `m_writePos`, `m_useBigEndian`, and `m_isWritable` / `m_isValid` for draft C++ and support prose. B004's formal method body uses `m_capacity` and `m_isWritable` to match the sibling `WriteBytes` draft. Original symbol spellings, final `sizeof`, and shared-header naming remain open, but those questions do not block [UID:00013J][0x004a55c0-0x004a55de.EncoderInitialize](by-memory/0x004a55c0-0x004a55de.EncoderInitialize.md)'s method body.
- B008 [UID:00013K][0x004a55e0-0x004a5621.EncoderFinalize](by-memory/0x004a55e0-0x004a5621.EncoderFinalize.md) source-quality pass keeps the same Encoder-side field-name direction and proves the output-count pointer is 32-bit: the TextEditPane caller passes a dword stack local, uses that dword for allocation/copy, and only later truncates to a 16-bit external output size. Original symbol spellings, final `sizeof`, and shared-header naming remain open, but those questions do not block [UID:00013K][0x004a55e0-0x004a5621.EncoderFinalize](by-memory/0x004a55e0-0x004a5621.EncoderFinalize.md)'s method body.
- B011 [UID:00013K][0x004a55e0-0x004a5621.EncoderFinalize](by-memory/0x004a55e0-0x004a5621.EncoderFinalize.md) source-quality recheck independently confirms the same layout interpretation from exported IDA/Ghidra artifacts: `+0x0c` is the 32-bit cursor/output count, `+0x04` is caller-owned output storage, `+0x08` is capacity cleared on detach, `+0x10` is byte-order state left untouched, and `+0x11` is the previous-valid return/restored writable byte. This recheck did not change the layout score or final open questions.
- B011 [UID:00013C][0x004a4e70-0x004a4e94.EncoderConstructor](by-memory/0x004a4e70-0x004a4e94.EncoderConstructor.md) source-quality pass confirms the same Encoder-side field-name direction for construction. The observed `0x0101` word store at `+0x10` is source-modeled as two adjacent true flags, `m_useBigEndian` and `m_isWritable`, because later methods access the two bytes independently. The constructor now emits first-draft child C++ using `m_outputBuffer`, `m_capacity`, `m_writePos`, `m_useBigEndian`, and `m_isWritable`; exact original spellings, final `sizeof`, and shared-header naming remain open layout-level questions.
- B011 [UID:00013F][0x004a4ec0-0x004a4ef1.EncoderWriteByte](by-memory/0x004a4ec0-0x004a4ef1.EncoderWriteByte.md) source-quality pass confirms the same Encoder-side field-name direction for one-byte writes. The method now emits first-draft child C++ using `m_outputBuffer`, `m_capacity`, `m_writePos`, and `m_isWritable`; exact original spellings, final `sizeof`, and shared-header naming remain open layout-level questions.
- B009 [UID:00013H][0x004a4ff0-0x004a506b.EncoderWriteInt](by-memory/0x004a4ff0-0x004a506b.EncoderWriteInt.md) source-quality pass confirms the same Encoder-side field-name direction for 32-bit scalar writes. The method now emits first-draft child C++ using `m_outputBuffer`, `m_capacity`, `m_writePos`, `m_useBigEndian`, and `m_isWritable`; exact original spellings, final `sizeof`, and shared-header naming remain open layout-level questions.
- B012 [UID:00013G][0x004a4f00-0x004a4f59.EncoderWriteShort](by-memory/0x004a4f00-0x004a4f59.EncoderWriteShort.md) source-quality pass confirms the same Encoder-side field-name direction for 16-bit scalar writes. The method now emits first-draft child C++ using `m_outputBuffer`, `m_capacity`, `m_writePos`, `m_useBigEndian`, and `m_isWritable`; exact original spellings, final `sizeof`, and shared-header naming remain open layout-level questions.
- B004 [UID:00013P][0x004a5680-0x004a57dc.DecoderPrimitiveReaders](by-memory/0x004a5680-0x004a57dc.DecoderPrimitiveReaders.md) source-quality implementation confirms the Decoder-side primitive reader direction. Draft child C++ now uses `m_inputBuffer`, `m_inputSize`, `m_readPos`, `m_useBigEndian`, and `m_isValid`; `m_inputSize`/`m_readPos` should remain documented as signed-compare-shaped for reader bounds checks; and `m_useBigEndian` should stay byte-like rather than being normalized through a boolean setter. Exact original spellings, final `sizeof`, shared-header ownership, and raw string/blob original names/direct-entry remain layout-level confidence caps, but string/blob child completion/C++ direction is now recorded on the child pages.
- B009 [UID:00013S][0x004a5dd0-0x004a5ded.DecoderFinalize](by-memory/0x004a5dd0-0x004a5ded.DecoderFinalize.md) source-quality implementation closes the previous exact-child finalize C++ blocker. The accepted child body uses `m_inputBuffer`, `m_inputSize`, `m_readPos`, and `m_isValid`; it deliberately does not touch `m_useBigEndian`. Current MCP names the function `sub_4A5DD0`, not the stale C001 `Decoder_Finalize` label, and the no-caller/no-pointer-route facts are preserved as confidence caps rather than source-emission blockers.

## 2026-06-16 Source-Quality Refresh

Live IDA MCP session `b001_selflookpane_0001H7_20260616` reported `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready. The pass reconfirmed:

- Modeled Encoder functions at `0x004a4e70`, `0x004a4ea0`, `0x004a4ec0`, `0x004a4f00`, `0x004a4ff0`, `0x004a5480`, `0x004a55c0`, `0x004a55e0`, `0x004a5630`, and `0x004a5e30`.
- Modeled Decoder lifecycle/glue functions at `0x004a5640`, `0x004a5670`, `0x004a5dd0`, `0x004a5df0`, and `0x004a5e00`.
- Raw Decoder reader starts `0x004a5680`, `0x004a5690`, `0x004a56c0`, `0x004a5710`, `0x004a5770`, `0x004a57e0`, `0x004a5870`, `0x004a5930`, `0x004a5a40`, `0x004a5bb0`, `0x004a5c80`, `0x004a5cd0`, `0x004a5d80`, and `0x004a5db0` still return `Not a function` and have no direct xrefs.
- Vtable-base refs remain limited to Encoder constructor/destructor/scalar-deleting destructor writes/reads at `0x004a4e70`, `0x004a4ea0`, and `0x004a5e3a`, and Decoder constructor/destructor/scalar-deleting destructor writes/reads at `0x004a5640`, `0x004a5670`, and `0x004a5e0a`.
- Direct modeled `Encoder::Initialize` and `Encoder::Finalize` xrefs remain from [UID:0000UM][EncodeTextEditState_0058E490](by-item/EncodeTextEditState_0058E490.md), preserving the current caller/reachability model.

IDA database source-quality edits made from this evidence: `sub_4A4E70` -> `Encoder_Constructor`, `sub_4A4EA0` -> `Encoder_Destructor`, `sub_4A4EC0` -> `Encoder_WriteByte`, `sub_4A4F00` -> `Encoder_WriteShort`, `sub_4A4FF0` -> `Encoder_WriteInt`, `sub_4A5480` -> `Encoder_WriteBytes`, `0x004a55c0` is treated as `Encoder_Initialize` / `Encoder::Initialize`, `0x004a55e0` is treated as `Encoder_Finalize` / `Encoder::Finalize`, `sub_4A5640` -> `Decoder_Constructor`, `sub_4A5670` -> `Decoder_Destructor`, `sub_4A5DD0` -> `Decoder_Finalize`, `sub_4A5E00` -> `Decoder_ScalarDeletingDestructor`, and `sub_4A5E30` -> `Encoder_ScalarDeletingDestructor`. B009's 2026-06-28 current MCP pass supersedes the Decoder finalize IDA-name portion of this historical note: the active IDB again reports `0x004a5dd0` as `sub_4A5DD0`, while the source-facing `Decoder::Finalize` name remains the accepted documentation/source name. No raw Decoder reader functions were created because the current IDB still has no function objects or caller/xref proof at those starts.

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

- 2026-06-28 B009 [UID:00013S][0x004a5dd0-0x004a5ded.DecoderFinalize](by-memory/0x004a5dd0-0x004a5ded.DecoderFinalize.md) implementation:
  - Before/after layout score unchanged: `87/91`.
  - Summary/evidence: synchronized the shared layout with the accepted Decoder finalize source model. Current MCP `sub_4A5DD0` at `0x004a5dd0-0x004a5ded` reads prior `+0x11`, clears `+0x04/+0x08/+0x0c`, writes `+0x11 = 1`, and leaves `+0x10` untouched. The formal child C++ now uses `m_inputBuffer`, `m_inputSize`, `m_readPos`, and `m_isValid`, while preserving `m_useBigEndian`. No direct caller, incoming xref, VA/RVA pointer route, callee, or vtable slot was found; those facts remain confidence caps and do not reopen the layout or child C++ decision. This page remains non-emitting with blank formal C++ because shared header ownership, exact original field spellings, final `sizeof`, and tail padding remain broader layout final-audit caveats.
- 2026-06-25 Rule 26 incorporation of B004 [UID:00013R][0x004a57e0-0x004a5dce.DecoderStringAndBlobReaders](by-memory/0x004a57e0-0x004a5dce.DecoderStringAndBlobReaders.md) implementation:
  - Before/after layout score unchanged: `87/91`.
  - Summary/evidence: synchronized the shared layout with the Decoder string/blob/raw-span first-draft source model. Wide-string, multibyte, C-string, byte-span, compressed-span, skip, and initialize children now use `m_inputBuffer`, `m_inputSize`, `m_readPos`, `m_useBigEndian`, and `m_isValid` consistently with the primitive reader direction; 16-bit length readers and compressed reads consume `+0x10`; multibyte readers use stack scratch plus `MultiByteToWideChar`; compressed reads call zlib while keeping cursor/valid ownership in Decoder; and `SkipBytes` preserves the trailing sentinel-space check.
- 2026-06-25 Rule 26 incorporation of B004 [UID:00013P][0x004a5680-0x004a57dc.DecoderPrimitiveReaders](by-memory/0x004a5680-0x004a57dc.DecoderPrimitiveReaders.md) implementation:
  - Before/after layout score unchanged: `87/91`.
  - Summary/evidence: synchronized the shared layout with the Decoder primitive reader first-draft source model. `SetByteOrder` stores the caller byte exactly into `+0x10`; primitive readers check `+0x11`, compare signed-shaped `m_inputSize`/`m_readPos` growth at `+0x08/+0x0c`, use `+0x04` as `m_inputBuffer`, advance `+0x0c`, and use `+0x10` to choose high-byte-first assembly versus native little-endian reads. This reinforces Decoder-side field-name direction while leaving exact original spellings, final `sizeof`, shared-header ownership, and raw string/blob helper completion open.
- 2026-06-21 Rule 26 incorporation of B012 [UID:00013G][0x004a4f00-0x004a4f59.EncoderWriteShort](by-memory/0x004a4f00-0x004a4f59.EncoderWriteShort.md) report:
  - Before/after layout score unchanged: `87/91`.
  - Summary/evidence: synchronized the shared layout with the 16-bit scalar writer's first-draft source model. `WriteShort` checks `+0x11`, reads/advances `+0x0c`, compares `+0x08` against `m_writePos + 3`, uses `+0x10` to choose high-byte-first byte stores versus native 16-bit storage through `+0x04`, and keeps overflow reporting on the sticky valid/writable byte. This reinforces the current field-name direction while leaving exact original spellings, final `sizeof`, shared-header ownership, and raw helper splits open.

- 2026-06-21 Rule 26 incorporation of B011 [UID:00013F][0x004a4ec0-0x004a4ef1.EncoderWriteByte](by-memory/0x004a4ec0-0x004a4ef1.EncoderWriteByte.md) report:
  - Before/after layout score unchanged: `87/91`.
  - Summary/evidence: synchronized the shared layout with the byte writer's first-draft source model. `WriteByte` checks `+0x11`, reads `+0x0c`, compares `+0x08` against `m_writePos + 2`, writes through `+0x04`, and deliberately ignores `+0x10`; that reinforces the current `m_outputBuffer`/`m_capacity`/`m_writePos`/`m_useBigEndian`/`m_isWritable` naming direction while leaving exact original spellings, final `sizeof`, shared-header ownership, and raw helper splits open.
- 2026-06-21 Rule 26 incorporation of B009 [UID:00013H][0x004a4ff0-0x004a506b.EncoderWriteInt](by-memory/0x004a4ff0-0x004a506b.EncoderWriteInt.md) report:
  - Before/after layout score unchanged: `87/91`.
  - Summary/evidence: synchronized the shared layout with the 32-bit scalar writer's first-draft source model. `WriteInt` checks `+0x11`, reads/advances `+0x0c`, compares `+0x08` against `m_writePos + 5`, uses `+0x10` to choose big-endian byte stores versus native little-endian dword storage through `+0x04`, and keeps overflow reporting on the sticky valid/writable byte. This reinforces the current field-name direction while leaving exact original spellings, final `sizeof`, shared-header ownership, and raw helper splits open.
- 2026-06-21 Rule 26 incorporation of B011 [UID:00013C][0x004a4e70-0x004a4e94.EncoderConstructor](by-memory/0x004a4e70-0x004a4e94.EncoderConstructor.md) report:
  - Before/after layout score unchanged: `87/91`.
  - Summary/evidence: aligned the shared layout with the constructor's first-draft source model. The constructor clears `+0x04/+0x08/+0x0c`, writes `0x0101` across `+0x10/+0x11`, and should be read as defaulting `m_outputBuffer`, `m_capacity`, `m_writePos`, `m_useBigEndian`, and `m_isWritable`, while the vptr store is compiler-generated class-construction evidence. The shared layout page remains non-code-emitting because header ownership, final field spellings, and final `sizeof` are broader layout final-audit caveats; primitive Decoder child methods now carry their accepted method C++ elsewhere, while string/blob reader completion remains separately capped by function-boundary/direct-entry evidence.
- 2026-06-21 B006 [UID:0001X1][BinaryCodecVtables](by-type/by-vtable/BinaryCodecVtables.md) source-quality incorporation:
  - Before/after layout score unchanged: `87/91`.
  - Summary/evidence: added the vtable/layout relationship from the B006 report. The vtable page confirms both classes share a vptr at `+0x00`, generated deleting-destructor first slots, concrete no-op virtual second slots, class-owned exact vtable data children, and the `0x006192e0` DAT table boundary. Final field names, final `sizeof`, and header ownership remain open and are not forced by the vtable aggregate alone.
- 2026-06-04: Raised grading from `78/88` to `82/90` and attached the layout to [UID:0000HQ][BinaryCodec](by-file/BinaryCodec.md) as canonical owner/emitter.
  - Before: the page had strong layout evidence but still lacked a parent attachment and carried stale non-live metadata caveat wording.
  - After: live IDA MCP evidence records constructor, initialize, finalize, writer, and reader use of every cursor field, with the shared layout attached to the strengthened BinaryCodec coordinator.
  - Score rationale: completion and confidence increased because the field offsets are now verified across both classes and across both modeled and raw bodies. The score remains below final-code level because final field names, tail padding, and header ownership are still open.
- 2026-06-16 C001 source-quality refresh:
  - Before: `82/90`.
  - After: `85/90`.
  - Summary/evidence: live IDA MCP reconfirmed the modeled Encoder/Decoder lifecycle and writer/finalize functions, unchanged raw Decoder no-function/no-xref blockers, compact vtable refs, and direct `EncodeTextEditState` caller evidence. IDA function names were updated for the modeled methods listed above. Completion now clears the gate because the page records current parent strength, live reachability limits, safe IDA names, and exact reasons the remaining `sizeof`, raw-reader, and original-header blockers cannot be resolved yet.
- 2026-06-20 Rule 26 incorporation of B003 [UID:00013J][0x004a55c0-0x004a55de.EncoderInitialize](by-memory/0x004a55c0-0x004a55de.EncoderInitialize.md) report:
  - Before: `85/90`, with generic layout names and no explicit byte-order-preservation proof from `Initialize`.
  - Changed to: `87/91`; Encoder-side layout names now prefer `m_outputBuffer`, `m_outputCapacity`, `m_writePos`, `m_useBigEndian`, and `m_isValid`, while Decoder-side names use matching `m_inputBuffer`, `m_inputSize`, and `m_readPos` directions where documented.
  - Evidence: B003 checked exact `Initialize` bytes/disassembly and sibling writer/finalize behavior, proving the method resets output buffer/capacity/cursor/valid state but does not touch the byte-order flag at `+0x10`.
- 2026-06-20 Rule 26 incorporation of B004 [UID:00013J][0x004a55c0-0x004a55de.EncoderInitialize](by-memory/0x004a55c0-0x004a55de.EncoderInitialize.md) report:
  - Before/after layout score unchanged: `87/91`.
  - Summary/evidence: B004 reconciled the Encoder-side field aliases with the current emitted method drafts, so `+0x08` records both `m_capacity` and `m_outputCapacity` and `+0x11` records both `m_isWritable` and `m_isValid`. The raw-name cleanup treats `0x004a55c0` as `Encoder_Initialize` / `Encoder::Initialize` instead of preserving a compiler-generated source-facing token.
- 2026-06-21 Rule 26 incorporation of B008 [UID:00013K][0x004a55e0-0x004a5621.EncoderFinalize](by-memory/0x004a55e0-0x004a5621.EncoderFinalize.md) report:
  - Before/after layout score unchanged: `87/91`.
  - Summary/evidence: B008 reconciled `Finalize` with the current emitted method drafts, confirming `+0x0c` as the 32-bit byte count/write cursor, `+0x04` as caller-owned output storage, `+0x08` as capacity cleared on detach, `+0x10` as byte-order state left untouched, and `+0x11` as the previous-valid return/restored writable byte. The raw-name cleanup treats `0x004a55e0` as `Encoder_Finalize` / `Encoder::Finalize` instead of preserving a compiler-generated source-facing token.
- 2026-06-21 Rule 26 incorporation check of B011 [UID:00013K][0x004a55e0-0x004a5621.EncoderFinalize](by-memory/0x004a55e0-0x004a5621.EncoderFinalize.md) report:
  - Before/after layout score unchanged: `87/91`.
  - Summary/evidence: B011 revalidated the already-incorporated `Finalize` field mapping with exported IDA/Ghidra function artifacts and did not change the shared cursor layout. The prior B008 entry already carried the active raw-name cleanup and first-draft method-body implications; B011 adds confirmation that the exact method remains non-thunk, non-library, one-caller/no-callee source-bearing Encoder code rather than a layout or ownership correction.
