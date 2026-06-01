*** UID:0000IQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:79 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# Decoder

## Status

- Confidence: medium for full live method set; strong that the reader island is paired with [UID:0000J1][Encoder](by-file/Encoder.md).
- Proposed module: `NexusTK/util/Decoder.cpp`, or folded into [UID:0000HQ][BinaryCodec](by-file/BinaryCodec.md) if later evidence proves a single paired codec file.
- Current recovered source: `source-3/simroot_v2/class_Decoder.cpp`
- Primary vtable: [UID:0001X1][BinaryCodecVtables](by-type/by-vtable/BinaryCodecVtables.md) at `0x006192d8`
- Shared layout: [UID:0001TS][BinaryCodecCursorLayout](by-type/by-struct/BinaryCodecCursorLayout.md)

## File Role

`Decoder.cpp` should own the in-memory binary reader that mirrors `Encoder`. Current generated output is incomplete: IDA shows constructor/destructor/reset/finalize behavior and many raw reader starts in `0x004a5680-0x004a5db0`, while active generated `class_Decoder.cpp` emits only a small subset.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| [UID:00003M][Decoder](by-class/Decoder.md) | `0x004a5640-0x004a5e23` | In-memory stream reader, reset/finalize, no-op virtual, and scalar deleting destructor. |
| raw reader family | [UID:00013Q][0x004a5680-0x004a5dcf.DecoderRawReaderFamily](by-memory/0x004a5680-0x004a5dcf.DecoderRawReaderFamily.md) | Byte/short/int/string/raw-span readers; the starts are raw code heads rather than current IDA functions. |
| primitive reader subset | [UID:00013P][0x004a5680-0x004a57dc.DecoderPrimitiveReaders](by-memory/0x004a5680-0x004a57dc.DecoderPrimitiveReaders.md) | Exact raw disassembly for byte-order setter and byte/16-bit/24-bit/32-bit readers. |
| string/blob reader subset | [UID:00013R][0x004a57e0-0x004a5dcc.DecoderStringAndBlobReaders](by-memory/0x004a57e0-0x004a5dcc.DecoderStringAndBlobReaders.md) | Exact raw disassembly for UTF-16, multibyte, raw-span, transformed-span, skip, and initialize readers. |

## Evidence Notes

2026-05-25 IDA MCP recheck:

- `lookup_funcs` reports modeled Decoder functions at `0x004a5640`, `0x004a5670`, `0x004a5dd0`, `0x004a5df0`, and `0x004a5e00`.
- `lookup_funcs` reports every raw reader start from `0x004a5680` through `0x004a5db0` as `Not a function`, despite aligned method-shaped disassembly.
- `xrefs_to` finds no direct references to the raw reader starts in the current database; this keeps live/dead caller status open.
- Vtable `0x006192d8` still contains scalar deleting destructor `0x004a5e00` and no-op virtual `0x004a5df0`.
- 2026-05-26 raw disassembly pass split the primitive-reader subset into [UID:00013P][0x004a5680-0x004a57dc.DecoderPrimitiveReaders](by-memory/0x004a5680-0x004a57dc.DecoderPrimitiveReaders.md). The bodies use the same buffer/cursor/byte-order/valid fields as the broader raw family.

2026-05-26 IDA MCP recheck:

- Vtable refs remain constructor/destructor-owned at `0x004a5640`, `0x004a5670`, and `0x004a5e0a`.
- Constructor and raw initialize/finalize disassembly reconfirm the same cursor fields used by `Encoder`, despite current metadata reporting a 4-byte class layout.
- Raw disassembly split the string/blob-reader subset into [UID:00013R][0x004a57e0-0x004a5dcc.DecoderStringAndBlobReaders](by-memory/0x004a57e0-0x004a5dcc.DecoderStringAndBlobReaders.md). The bodies use the same cursor fields, call copy helpers `0x00516030`/`0x00516220`, use `MultiByteToWideChar` for multibyte text, and leave all starts as `Not a function` in IDA.

2026-05-31 IDA MCP recheck:

- Modeled lifecycle/glue starts remain stable at `0x004a5640`, `0x004a5670`, `0x004a5dd0`, `0x004a5df0`, and `0x004a5e00`.
- Vtable `0x006192d8` has two slots, `0x004a5e00` and `0x004a5df0`, with constructor/destructor-owned refs.
- Raw reader starts from `0x004a5680` through `0x004a5db0` still are not IDA-modeled functions and still have no direct xrefs in the current database. This supports utility placement but keeps confidence below high until caller recovery and exact boundary modeling improve.

## Boundary Notes

Do not trust active generated `class_Decoder.cpp` as migration-ready source until the missing reader starts and 18-byte stream layout are modeled. See [wave3_data_issues](../wave3_data_issues.md) for the current generator/data caveat.

## Cross-References

- [UID:0000HQ][BinaryCodec](by-file/BinaryCodec.md)
- [UID:00003M][Decoder](by-class/Decoder.md)
- [UID:00013M][0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue](by-memory/0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue.md)
- [UID:00013Q][0x004a5680-0x004a5dcf.DecoderRawReaderFamily](by-memory/0x004a5680-0x004a5dcf.DecoderRawReaderFamily.md)
- [UID:00013P][0x004a5680-0x004a57dc.DecoderPrimitiveReaders](by-memory/0x004a5680-0x004a57dc.DecoderPrimitiveReaders.md)
- [UID:00013R][0x004a57e0-0x004a5dcc.DecoderStringAndBlobReaders](by-memory/0x004a57e0-0x004a5dcc.DecoderStringAndBlobReaders.md)
- [UID:0001TS][BinaryCodecCursorLayout](by-type/by-struct/BinaryCodecCursorLayout.md)
- [UID:0001X1][BinaryCodecVtables](by-type/by-vtable/BinaryCodecVtables.md)
- [UID:0000J1][Encoder](by-file/Encoder.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:78` and `CONFIDENCE:70`.
  - Summary/evidence: codec ownership, raw reader families, primitive/string/blob subsets, IDA raw-start caveats, vtable refs, and generated-output warnings are documented; confidence remains moderate because many reader starts are not IDA-modeled functions and active generated source is incomplete.
- 2026-05-31 reconstruction path and IDA recheck:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, scores were `78/70`, and the module path used `util/Decoder.cpp` without an explicit generated root.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/"`, scores `79/72`, and proposed module `NexusTK/util/Decoder.cpp`.
  - Summary/evidence: IDA MCP reconfirmed modeled lifecycle/vtable glue and the raw reader caveat. No C++ reconstruction code is emitted because raw-reader boundaries, caller evidence, active generated source completeness, and surrounding/dependency confidence are below the `95+` final-code gate.
