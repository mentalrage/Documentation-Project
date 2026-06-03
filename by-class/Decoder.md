*** UID:00003M | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000IQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Decoder

## Status

- Confidence: medium-high for class ownership/layout/vtable identity, medium for complete live method reachability.
- Likely source file: [UID:0000IQ][Decoder](by-file/Decoder.md), under the [UID:0000HQ][BinaryCodec](by-file/BinaryCodec.md) utility layer
- Current recovered file: `source-3/simroot_v2/class_Decoder.cpp`
- Main address evidence: [UID:00013M][0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue](by-memory/0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue.md)
- Layout docs: [UID:0001TS][BinaryCodecCursorLayout](by-type/by-struct/BinaryCodecCursorLayout.md)
- Primary vtable: [UID:0001X1][BinaryCodecVtables](by-type/by-vtable/BinaryCodecVtables.md)
- Generated size caveat: current metadata reports only 4 bytes, but IDA-confirmed and raw code uses the same cursor layout as [UID:00004F][Encoder](by-class/Encoder.md), with observed fields through offset `+0x11`.

## Class Purpose

`Decoder` is the reader-side companion to [UID:00004F][Encoder](by-class/Encoder.md). It attaches to a caller-owned byte buffer, reads primitive values and string/blob payloads from the current cursor, advances the cursor, and clears its valid flag when a read cannot be satisfied from the remaining buffer.

## Observed State

```text
+0x00  vtable pointer (`0x006192d8`)
+0x04  input buffer pointer
+0x08  input buffer size/limit
+0x0c  current read position
+0x10  byte-order flag; nonzero reads integer values big-endian
+0x11  valid/readable flag
```

This layout is inferred from IDA decompilation/disassembly of the constructor, initializer, reset/finalizer, and raw reader bodies. It should replace the generated 4-byte-only view before source migration.

## Confirmed And Raw Methods

| Address | Method family | Notes |
| --- | --- | --- |
| `0x004a5640` | constructor | Installs the `Decoder` vtable, clears buffer/limit/cursor, sets flags word to `0x0101`. IDA models this as a function. |
| `0x004a5670` | destructor | Restores the `Decoder` vtable. IDA models this as a function. |
| `0x004a5680` | set byte order | Stores caller byte into offset `+0x10`. Raw code start, not an IDA function; see [UID:00013Q][0x004a5680-0x004a5dce.DecoderRawReaderFamily](by-memory/0x004a5680-0x004a5dce.DecoderRawReaderFamily.md). |
| `0x004a5690` | read byte | Reads one byte and advances by one. Raw code start. |
| `0x004a56c0` | read 16-bit value | Reads a short in selected byte order. Raw code start. |
| `0x004a5710` | read 24-bit value | Reads three bytes and assembles them by selected byte order. Raw code start. |
| `0x004a5770` | read 32-bit value | Reads four bytes in selected byte order. Raw code start. |
| `0x004a57e0` | read 8-bit length UTF-16 payload | Reads one-byte element count, copies `count * 2` bytes, and terminates output. Raw code start. |
| `0x004a5870` | read 16-bit length UTF-16 payload | Reads two-byte element count, copies `count * 2` bytes, and terminates output. Raw code start. |
| `0x004a5930` | read 8-bit length multibyte text | Copies a byte string to a local buffer and converts through `MultiByteToWideChar`. Raw code start. |
| `0x004a5a40` | read 16-bit length multibyte text | Larger-stack variant of the multibyte-to-wide reader. Raw code start. |
| `0x004a5bb0` | read NUL-terminated multibyte text | Scans to NUL, copies, converts to wide text, and reports produced length when requested. Raw code start. |
| `0x004a5c80` | read raw bytes | Copies caller-requested byte count to the destination and advances. Raw code start. |
| `0x004a5cd0` | read bounded/transformed byte payload | Reads a 16-bit length, copies through helper `0x00414390`, and reports produced size. Raw code start. |
| `0x004a5d80` | skip bytes | Advances by caller count if the buffer has enough space plus a trailing sentinel byte. Raw code start. |
| `0x004a5db0` | initialize | Attaches caller buffer/size, resets cursor, and sets valid flag. Raw code start. |
| `0x004a5dd0` | finalize/reset | Returns previous valid state and clears buffer/size/cursor. IDA models this as a function. |
| `0x004a5df0` | no-op virtual | Vtable slot at `0x006192dc`; active output keeps it only in the disabled file. |
| `0x004a5e00` | scalar deleting destructor | Restores vtable and conditionally frees the object. |

## Evidence Notes

- IDA MCP decompiles `0x004a5640`, `0x004a5670`, `0x004a5dd0`, and `0x004a5e00` as Decoder-shaped functions.
- IDA disassembly shows aligned raw reader starts from `0x004a5680` through `0x004a5db0`, but `lookup_funcs` reports "Not a function" for most of them.
- IDA xrefs currently show no direct callers for the raw Decoder starts. This may be dead retained utility code, missing call analysis, or a generated-data/function-boundary gap.
- The `Decoder` vtable at `0x006192d8` has two slots: scalar deleting destructor and no-op virtual.
- 2026-05-25 IDA MCP recheck reconfirmed the modeled functions, the raw-reader `Not a function` status, empty raw-reader xrefs, and the 18-byte stream layout fields used by the raw bodies.
- 2026-05-26 IDA MCP recheck produced the same split: constructor/destructor/finalize/no-op/scalar-destructor functions are modeled, every raw reader start still reports `Not a function`, and raw-reader `xrefs_to` remains empty. Keep the raw family as reconstructable `Decoder` project code with missing function-boundary data, not ignored code.
- 2026-05-26 IDA MCP vtable/layout recheck confirms vtable refs at `0x004a5640`, `0x004a5670`, and `0x004a5e0a`, and confirms constructor/raw initialize/finalize use the shared cursor fields now documented in [UID:0001TS][BinaryCodecCursorLayout](by-type/by-struct/BinaryCodecCursorLayout.md).
- 2026-05-26 raw IDA disassembly documents the primitive reader subset at [UID:00013P][0x004a5680-0x004a57dc.DecoderPrimitiveReaders](by-memory/0x004a5680-0x004a57dc.DecoderPrimitiveReaders.md): byte-order setter, byte reader, 16-bit reader, 24-bit reader, and 32-bit reader.
- 2026-05-26 raw IDA disassembly documents the string/blob reader subset at [UID:00013R][0x004a57e0-0x004a5dce.DecoderStringAndBlobReaders](by-memory/0x004a57e0-0x004a5dce.DecoderStringAndBlobReaders.md): UTF-16 length-prefixed readers, multibyte-to-wide readers, C-string reader, raw-byte reader, transformed-byte reader, skip helper, and raw initialize body.

## Current Caveats

- Active `class_Decoder.cpp` emits only the scalar deleting destructor at `0x004a5e00`.
- Disabled `class_Decoder.cpp` emits the no-op virtual at `0x004a5df0`, but omits the constructor, ordinary destructor, reset/finalize helper, and the raw reader family.
- Generated metadata reports `Decoder` as a 4-byte minimal base; the raw code proves the real layout is larger and stream-like.
- The raw reader family needs function-definition recovery before migration, but it should not be excluded from source reconstruction.

## Cross-References

- [UID:0000IQ][Decoder](by-file/Decoder.md)
- [UID:0000HQ][BinaryCodec](by-file/BinaryCodec.md)
- [UID:00004F][Encoder](by-class/Encoder.md)
- [UID:00013M][0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue](by-memory/0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue.md)
- [UID:00013Q][0x004a5680-0x004a5dce.DecoderRawReaderFamily](by-memory/0x004a5680-0x004a5dce.DecoderRawReaderFamily.md)
- [UID:00013P][0x004a5680-0x004a57dc.DecoderPrimitiveReaders](by-memory/0x004a5680-0x004a57dc.DecoderPrimitiveReaders.md)
- [UID:00013R][0x004a57e0-0x004a5dce.DecoderStringAndBlobReaders](by-memory/0x004a57e0-0x004a5dce.DecoderStringAndBlobReaders.md)
- [UID:0001TS][BinaryCodecCursorLayout](by-type/by-struct/BinaryCodecCursorLayout.md)
- [UID:0001X1][BinaryCodecVtables](by-type/by-vtable/BinaryCodecVtables.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `78/78`.
  - Summary/evidence: cursor layout, modeled constructor/destructor/finalize/destructor glue, raw primitive/string/blob reader families, vtable identity, and Wave3 caveats are documented; confidence remains limited by unmodeled raw-reader function boundaries and empty xrefs.
- 2026-05-31:
  - Before: the class was documented as reconstructable in prose but validator `RECONSTRUCTABLE` metadata was blank.
  - After: `RECONSTRUCTABLE` is set to `TRUE`.
  - Summary/evidence: IDA MCP reconfirmed the Decoder constructor/destructor/no-op/scalar-deleting vtable surface and raw-reader caveats; C++ code remains blank because raw reader boundary/caller evidence is below the `95+` final-code gate.
- 2026-06-03:
  - Before: scores were `78/78` and `AUTOGEN_PARENT_UID` was blank while the file parent still had low confidence.
  - After: scores are `80/82`, and `AUTOGEN_PARENT_UID` is [UID:0000IQ][Decoder](by-file/Decoder.md).
  - Summary/evidence: the class page already records the full observed state, modeled lifecycle functions, raw reader starts, vtable slots, generated-size caveat, and links to the strengthened layout/vtable/source-root docs. C++ remains blank because the raw reader family still lacks modeled function objects and direct caller recovery.
