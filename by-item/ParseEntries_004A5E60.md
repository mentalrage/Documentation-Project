*** UID:0000V5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ParseEntries 0x004A5E60

## Status

- Confidence: strong
- Entity kind: global helper
- Current Wave3 owner file: `ParseEntries_004A5E60.cpp`
- Canonical global page: [UID:0000TH][ParseEntries_004A5E60](by-global/ParseEntries_004A5E60.md)
- Likely source module: [UID:0000IN][DATFile](by-file/DATFile.md)
- Exact range: [UID:00013W][0x004a5e60-0x004a609f.ParseEntries](by-memory/0x004a5e60-0x004a609f.ParseEntries.md)

## Behavior

`ParseEntries` decodes an eight-byte DAT header buffer in place, validates it against an encoded key, and returns a decoded 32-bit value through `outValue`.

Inputs:

- `headerBytes`: eight encoded bytes read from a DAT-backed file.
- `encodedKey`: caller passes `fileSize >> 1`.
- `outValue`: receives the decoded value when validation succeeds.

Algorithm summary:

- Builds a 27-entry mixed table from fixed byte constants.
- XOR-decodes eight header bytes, stepping backward modulo 27 from `(0xFEDCBA98 - encodedKey) % 27`.
- Reads the first and second decoded four-byte halves as big-endian 32-bit values.
- Validates with the `0x55555555` deinterleave mask.
- Writes `upper ^ ((upper ^ lower) & 0x55555555)` to `outValue` on success.

## Evidence

- Wave3 restored signature: `bool ParseEntries(unsigned char* headerBytes, unsigned int encodedKey, unsigned int* outValue)`.
- Wave3 notes say IDA showed only two callers: `DATFile::ReadAllEntries` at `0x0049c4a0` and `DATFile::ReadAllEntriesAlt` at `0x0049c4f0`.
- IDA MCP caller check on 2026-05-22 also reported only those two caller sites.
- IDA MCP recheck on 2026-05-25 again reports only those callers, at call sites `0x0049c4d4` and `0x0049c524`; callee checks show `ParseEntries` only calls the compiler security-cookie check.
- IDA MCP decompile on 2026-05-25 shows both `DATFile` wrappers compute `GetSize() >> 1`, read an eight-byte local buffer, and immediately call `ParseEntries`, supporting file-local helper placement.
- IDA MCP recheck on 2026-05-31 confirms `sub_4A5E60` starts at `0x004a5e60`, ends half-open at `0x004a609f`, has only two caller functions at `0x0049c4a0` and `0x0049c4f0`, and only calls the security-cookie check.

## Ownership Decision

Keep this as a private/free helper in the [UID:0000IN][DATFile](by-file/DATFile.md) module. It is not an image/EPF helper even though higher-level resource loaders may indirectly rely on it.

## Cross-References

- [UID:0000UC][DATEntryRecord](by-item/DATEntryRecord.md)
- [UID:0000TH][ParseEntries_004A5E60](by-global/ParseEntries_004A5E60.md)
- [UID:00013W][0x004a5e60-0x004a609f.ParseEntries](by-memory/0x004a5e60-0x004a609f.ParseEntries.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)
- [UID:00003G][DATFile](by-class/DATFile.md)

## Changes

- 2026-05-31: Grading and reconstruction status changed from unevaluated/blank to `70/85` and `RECONSTRUCTABLE:TRUE`.
  - Before: the page body documented the DAT header decoder, but the validator metadata still showed `0/0` and no reconstruction status.
  - After: the metadata now tracks it as rebuild-relevant DAT helper code. Parent UID and C++ remain blank because final file-local placement and source-level naming should be coordinated with the canonical DATFile pages.
  - Evidence: IDA MCP confirms the exact function range, two DATFile wrapper callers, and no project callees beyond the security-cookie check.
