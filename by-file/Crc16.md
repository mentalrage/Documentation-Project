*** UID:00032J | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Crc16

## Status

- Proposed module: `NexusTK/util/Crc16.cpp`
- Proposed header: `NexusTK/util/Crc16.h`
- Source-owner inference: narrow polynomial-`0x1021` CRC-family utility source file.
- Confidence: strong for the code/table family and source shape; medium-high for exact original filename, identifiers, and linkage declarations.

## File Role

This page models the accepted direct source owner for the dead-retained polynomial-`0x1021` helper island at `0x0049bbf0-0x0049bca9` and its paired lookup tables at `0x0066d47c-0x0066d880`.

The helper island contains four aligned raw callable bodies: a word-step update, an unsigned-count word-buffer update, a byte-step update, and a signed-positive byte-buffer update. The two referenced arrays are byte-identical `0x200`-byte/256-entry writable tables whose complete contents match MSB-first polynomial `0x1021`. The byte pair uses a historical non-augmented update shape; the word pair XORs all 16 input bits and is a project word-symbol extension. Evidence-time IDA/PE checks find no static-image route to the helper starts, so this file is reconstructed as a dead-retained utility module rather than caller-owned feature code.

## Likely Contents

- [UID:00032K][0x0049bbf0-0x0049bc0d.Crc16WordStep](by-memory/0x0049bbf0-0x0049bc0d.Crc16WordStep.md) - one-step update using `word_66D480`.
- [UID:00032L][0x0049bc10-0x0049bc47.Crc16WordBuffer](by-memory/0x0049bc10-0x0049bc47.Crc16WordBuffer.md) - word-buffer update using `word_66D480`.
- [UID:00032M][0x0049bc50-0x0049bc70.Crc16ByteStep](by-memory/0x0049bc50-0x0049bc70.Crc16ByteStep.md) - one-step byte update using `word_66D680`.
- [UID:00032N][0x0049bc70-0x0049bca9.Crc16ByteBuffer](by-memory/0x0049bc70-0x0049bca9.Crc16ByteBuffer.md) - byte-buffer update using `word_66D680`.
- [UID:00027A][0x0066d47c-0x0066d880.ChecksumLookupTablesData](by-memory/0x0066d47c-0x0066d880.ChecksumLookupTablesData.md) - backing lookup table data at `0x0066d47c-0x0066d880`.
- [UID:000225][0x0049bbf0-0x0049bca9.ChecksumTableHelpers](by-memory/0x0049bbf0-0x0049bca9.ChecksumTableHelpers.md) - non-emitting aggregate/index over the four helper bodies and internal alignment padding.

## Draft C++ Emission

The accepted emitted family is intentionally human-shaped but does not claim original-name proof. UID00027A emits two private writable arrays, `s_crc16WordTable` and `s_crc16ByteTable`, at position `10`. Externally linked free functions `Crc16WordStep`, `Crc16WordBuffer`, `Crc16ByteStep`, and `Crc16ByteBuffer` follow at positions `20`, `30`, `40`, and `50`. Function declarations may belong in the proposed `Crc16.h`; the recovered binary does not prove exact header content.

The functions preserve observed argument order and widths, zero-initialized buffer accumulators, unsigned word count, signed-positive byte count, distinct table objects, and low-16-bit return behavior. The two buffer machine bodies inline their recurrences; source-level calls to the paired step functions are preferred because externally retained step bodies and optimized instruction scheduling explain that layout. The duplicate initializer macro is a maintenance convenience, not original macro proof.

Historical/superseded draft: generated output previously used file-static functions and `extern const` `kCrc16*Table` objects. The tables are in writable `.data`, and all four optimized function bodies survive despite no static-image route. The accepted source therefore uses private mutable tables and externally linked but image-dead functions. "External linkage" does not mean PE export; the executable's export directory is empty.

## Evidence

- Evidence-time IDA MCP `lookup_funcs` reports `0x0049bbf0`, `0x0049bc10`, `0x0049bc50`, and `0x0049bc70` are not modeled function starts, while `0x0049bcb0` is the next modeled function after the helper island.
- Evidence-time `xrefs_to` and caller/ref searches report no direct refs/callers to the four helper starts.
- Complete static-image checks found no little-endian VA pointers, usable RVA or raw-offset constants, direct `E8`/`E9` destinations, exports, callbacks, or feature bridge to any helper start. The sole word-step RVA byte hit is a relative-call displacement to unrelated `0x004b9980` and is rejected.
- IDA MCP xrefs to `word_66D480` are exactly `0x0049bbff` and `0x0049bc2c`; xrefs to `word_66D680` are exactly `0x0049bc5f` and `0x0049bc92`.
- IDA MCP byte checks confirm the only internal alignment spans are `0x0049bc0d-0x0049bc10`, `0x0049bc47-0x0049bc50`, and `0x0049bca9-0x0049bcb0`.
- IDA MCP table sampling confirms `0x0066d480`, `0x0066d680`, and the MapPane table body at `0x0066db50` all start with `0x0000, 0x1021, 0x2042, 0x3063`, but only `0x0066d480` and `0x0066d680` are referenced by this helper island.

## 2026-07-12 B002 C01-C20 Source-Unit Contract

- Range/inventory: exact source-bearing children are UIDs 00032K, 00032L, 00032M, 00032N, and data UID00027A. UID000225 is a non-emitting aggregate over those children and three `cc` alignment spans. No split, merge, or new child applies.
- Signatures: word step `(unsigned short value, unsigned short crc)`; word buffer `(const unsigned short* words, unsigned int count)`; byte step `(unsigned char value, unsigned short crc)`; byte buffer `(const unsigned char* bytes, int count)`; each returns `unsigned short` under default 32-bit `__cdecl`-compatible free-function shape.
- Control semantics: both buffers seed zero. Word count uses unsigned `jb`; byte count exits for `count <= 0` and loops with signed `jl`. Zero/no-work paths do not dereference their pointers.
- Recurrence: table indexed by `crc >> 8`, XOR shifted `crc`, then XOR the input symbol. All 256 table entries exactly match polynomial `0x1021`; both arrays have SHA256 `ea5f177f22d32b7e80c132b498ee4b92882484f891f43f1897075f28bb3da4d9`.
- Type/storage: both arrays are separately initialized in writable `.data` and have exclusive step/buffer readers. Private `static unsigned short` arrays preserve storage and source locality; const-signaling names/types are rejected.
- Liveness/linkage: no xref, immediate, pointer, raw offset, relative branch, export, callback, or feature route reaches any helper start. The functions are externally linked in the reconstruction because that best explains retained optimized bodies; they are dead-retained in this image and not exported.
- Source calls: buffer machine bodies contain inline recurrence, but source calls to paired step functions are highest probability. Macro-only and duplicated-source alternatives remain machine-equivalent but are weaker source-shape explanations.
- Naming: function and `s_crc16*Table` names are descriptive inferred names. Historical Satchell/Forsberg `updcrc` lineage corroborates the recurrence/update role but does not prove NexusTK spelling or third-party import identity.
- Ownership/rejections: this narrow util owner remains stronger than parent-blank, MapPane, zlib, LodePNG, Crasher, or synchronization ownership. MapPane's similar table has separate consumers; neighbors are padding-separated; third-party checksum families differ.
- Emission: table at `10`, functions K/L/M/N at `20/30/40/50`. Exact child formal blocks are authoritative; the aggregate remains blank. No manual generated/coverage/tracker/project-structure edit is permitted.

## Ownership Boundaries

- [UID:00027N][0x0066db4c-0x0066dd50.MapPaneChecksumLookupTable](by-memory/0x0066db4c-0x0066dd50.MapPaneChecksumLookupTable.md) is excluded from this file despite identical table bytes because its IDA xrefs are MapPane packet/tile checksum consumers, not this raw helper island.
- [UID:0000L3][MapPane](by-file/MapPane.md) `MapPane` is rejected as direct owner for this helper island because IDA finds no caller bridge from MapPane code to `0x0049bbf0`, `0x0049bc10`, `0x0049bc50`, or `0x0049bc70`.
- [UID:0000PC][Zlib](by-file/Zlib.md) `Zlib` and [UID:0000KW][LodePNG](by-file/LodePNG.md) `LodePNG` are rejected because their documented checksum code is stock zlib/LodePNG CRC-32/Adler/PNG support at unrelated ranges and with different algorithm width/source identity.
- [UID:0000II][Crasher](by-file/Crasher.md) `Crasher` is rejected because the checksum island begins only after `Crasher::ScalarDeletingDestructor` and a `0xcc` alignment byte; there are no shared xrefs, globals, vtables, or behavior.
- [UID:0000LI][Monitor](by-file/Monitor.md) `Monitor` / synchronization code is rejected because it starts after `0x0049bca9-0x0049bcb0` padding and owns Win32 critical-section helpers, not CRC state or lookup data.

## Score Rationale

Completion is `91` because the source owner now records complete child/range inventory, exact signatures and loop semantics, full table identity/polynomial/mutability, exhaustive liveness and false-positive disposition, source linkage/inlining, accepted names/types/order, generated contract, and rejected alternatives. Confidence is `92` because code/table grouping and exclusions are strongly binary-backed, while exact original filename, identifiers, header declarations, source linkage, and historical runtime use remain inferred.

## Change Log

- 2026-07-12 B002 UID00032L accepted callback: changed `86/88 -> 91/92`; incorporated C01-C20 at source-unit detail; superseded static-function, external-const-table, and unqualified CRC-variant wording; and established the table-first `10/20/30/40/50` generated contract without changing the proposed `NexusTK/util/` path.
- 2026-06-10 B001-019: Created as the best defensible source owner for the CRC-16/CCITT helper code plus table pair after live IDA evidence rejected existing feature, third-party, and neighboring-owner candidates.
- 2026-06-22 Rule26 supervisor closeout: Verified the B001-019 report was already incorporated at report-level detail, then added first-draft C++ emission notes/code for the exact helper children and backing table data so the `Crc16` generated source is no longer an empty-emitter shell.
