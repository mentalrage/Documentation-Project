*** UID:00032J | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# Crc16

## Status

- Proposed module: `NexusTK/util/Crc16.cpp`
- Proposed header: `NexusTK/util/Crc16.h`
- Source-owner inference: narrow CRC-16/CCITT utility source file.
- Confidence: strong for the code/table family; medium-high for the exact original filename.

## File Role

This page models the best current direct source owner for the unreferenced CRC-16/CCITT helper island at `0x0049bbf0-0x0049bca9` and its paired lookup tables at `0x0066d47c-0x0066d880`.

The helper island contains four aligned raw callable bodies: a word-step update, a word-buffer update, a byte-step update, and a byte-buffer update. The two referenced tables are duplicate `0x200`-byte/256-entry 16-bit tables with the canonical `0x1021` CRC-CCITT opening sequence. Live IDA evidence finds no direct callers, raw pointer constants, or direct call/jump encodings to the helper starts, so this file is reconstructed as a retained utility module rather than as caller-owned feature code.

## Likely Contents

- [UID:00032K][0x0049bbf0-0x0049bc0d.Crc16WordStep](by-memory/0x0049bbf0-0x0049bc0d.Crc16WordStep.md) - one-step update using `word_66D480`.
- [UID:00032L][0x0049bc10-0x0049bc47.Crc16WordBuffer](by-memory/0x0049bc10-0x0049bc47.Crc16WordBuffer.md) - word-buffer update using `word_66D480`.
- [UID:00032M][0x0049bc50-0x0049bc70.Crc16ByteStep](by-memory/0x0049bc50-0x0049bc70.Crc16ByteStep.md) - one-step byte update using `word_66D680`.
- [UID:00032N][0x0049bc70-0x0049bca9.Crc16ByteBuffer](by-memory/0x0049bc70-0x0049bca9.Crc16ByteBuffer.md) - byte-buffer update using `word_66D680`.
- [UID:00027A][0x0066d47c-0x0066d880.ChecksumLookupTablesData](by-memory/0x0066d47c-0x0066d880.ChecksumLookupTablesData.md) - backing lookup table data at `0x0066d47c-0x0066d880`.
- [UID:000225][0x0049bbf0-0x0049bca9.ChecksumTableHelpers](by-memory/0x0049bbf0-0x0049bca9.ChecksumTableHelpers.md) - non-emitting aggregate/index over the four helper bodies and internal alignment padding.

## Evidence

- IDA MCP `lookup_funcs` reports `0x0049bbf0`, `0x0049bc10`, `0x0049bc50`, and `0x0049bc70` are not modeled function starts, while `0x0049bcb0` is the next modeled function after the helper island.
- IDA MCP `xrefs_to` and `callers` report no direct refs/callers to the four helper starts.
- IDA MCP raw segment scan found no little-endian pointer constants, direct `E8` calls, or direct `E9` jumps to `0x0049bbf0`, `0x0049bc10`, `0x0049bc50`, or `0x0049bc70` in loaded `.text`, `.idata`, `.rdata`, or `.data`.
- IDA MCP xrefs to `word_66D480` are exactly `0x0049bbff` and `0x0049bc2c`; xrefs to `word_66D680` are exactly `0x0049bc5f` and `0x0049bc92`.
- IDA MCP byte checks confirm the only internal alignment spans are `0x0049bc0d-0x0049bc10`, `0x0049bc47-0x0049bc50`, and `0x0049bca9-0x0049bcb0`.
- IDA MCP table sampling confirms `0x0066d480`, `0x0066d680`, and the MapPane table body at `0x0066db50` all start with `0x0000, 0x1021, 0x2042, 0x3063`, but only `0x0066d480` and `0x0066d680` are referenced by this helper island.

## Ownership Boundaries

- [UID:00027N][0x0066db4c-0x0066dd50.MapPaneChecksumLookupTable](by-memory/0x0066db4c-0x0066dd50.MapPaneChecksumLookupTable.md) is excluded from this file despite identical table bytes because its IDA xrefs are MapPane packet/tile checksum consumers, not this raw helper island.
- [UID:0000L3][MapPane](by-file/MapPane.md) `MapPane` is rejected as direct owner for this helper island because IDA finds no caller bridge from MapPane code to `0x0049bbf0`, `0x0049bc10`, `0x0049bc50`, or `0x0049bc70`.
- [UID:0000PC][Zlib](by-file/Zlib.md) `Zlib` and [UID:0000KW][LodePNG](by-file/LodePNG.md) `LodePNG` are rejected because their documented checksum code is stock zlib/LodePNG CRC-32/Adler/PNG support at unrelated ranges and with different algorithm width/source identity.
- [UID:0000II][Crasher](by-file/Crasher.md) `Crasher` is rejected because the checksum island begins only after `Crasher::ScalarDeletingDestructor` and a `0xcc` alignment byte; there are no shared xrefs, globals, vtables, or behavior.
- [UID:0000LI][Monitor](by-file/Monitor.md) `Monitor` / synchronization code is rejected because it starts after `0x0049bca9-0x0049bcb0` padding and owns Win32 critical-section helpers, not CRC state or lookup data.

## Score Rationale

Completion is `86` because the page now identifies the narrow source owner, exact four helper children, paired table data, rejected neighboring/feature/third-party candidates, IDA negative reachability evidence, and projected util path. Confidence is `88` because the code/table pairing and exclusions are strongly IDA-backed, but the exact original source filename and runtime call path remain unavailable.

## Change Log

- 2026-06-10 B001-019: Created as the best defensible source owner for the CRC-16/CCITT helper code plus table pair after live IDA evidence rejected existing feature, third-party, and neighboring-owner candidates.
