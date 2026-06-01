*** UID:0000TH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ParseEntries_004A5E60

## Status

- Address range: [UID:00013W][0x004a5e60-0x004a609f.ParseEntries](by-memory/0x004a5e60-0x004a609f.ParseEntries.md)
- Symbol kind: global helper function
- Signature hypothesis: `bool ParseEntries(unsigned char* headerBytes, unsigned int encodedKey, unsigned int* outValue)`
- Likely owner file: [UID:0000IN][DATFile](by-file/DATFile.md)
- Current generated file: `source-3/simroot_v2/recovered/ParseEntries_004A5E60.cpp`
- Confidence: strong

## Function Role

`ParseEntries` is a DAT table/header decoder used by `DATFile` bulk-entry readers. It mutates the caller's eight-byte header buffer, validates the decoded halves against the caller-supplied encoded key, and returns one deinterleaved 32-bit value through `outValue`.

## Evidence Notes

- Current `simroot_v2` emits this as a standalone recovered global helper from Wave2/Wave3 recovery data.
- IDA MCP `lookup_funcs` on 2026-05-25 confirms `0x004a5e60` as a real function of size `0x23f`, ending half-open at `0x004a609f`.
- IDA MCP `callers` confirms only `DATFile::ReadAllEntries` and `DATFile::ReadAllEntriesAlt` call it, at call sites `0x0049c4d4` and `0x0049c524`.
- IDA MCP `decompile` on 2026-05-25 shows both `DATFile` wrappers only compute the encoded key from `GetSize() >> 1`, read eight bytes, and dispatch to this helper.
- IDA MCP decompilation matches the generated helper: 27-entry constant table, XOR mixing, eight-byte decode, big-endian reads, and `0x55555555` mask validation.

## Source Layout Decision

Declare this as a private/static-style helper beside `DATFile` in `archive/DATFile.cpp`. It is not a render/image helper; its only confirmed direct callers are `DATFile` methods.

## Cross-References

- [UID:00013W][0x004a5e60-0x004a609f.ParseEntries](by-memory/0x004a5e60-0x004a609f.ParseEntries.md)
- [UID:0000V5][ParseEntries_004A5E60](by-item/ParseEntries_004A5E60.md)
- [UID:0000IN][DATFile](by-file/DATFile.md)
- [UID:00003G][DATFile](by-class/DATFile.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `86/90`.
  - Before: page documented the DAT table/header decoder behavior, exact callers, decompiled algorithm, and DATFile placement but remained unevaluated.
  - After: score reflects near-complete behavior and owner documentation for this helper.
  - Evidence: IDA notes confirm the function range, only `DATFile::ReadAllEntries` / `ReadAllEntriesAlt` callers, generated decompile match, 27-entry constant table, XOR mixing, big-endian reads, and validation mask.
