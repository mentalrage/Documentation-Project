*** UID:0000TH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IN | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IN | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted implementation for this historical ParseEntries alias is covered by [UID:00013W][0x004a5e60-0x004a609f.ParseEntries](by-memory/0x004a5e60-0x004a609f.ParseEntries.md) DecodeTableValue.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# DecodeTableValue (Historical ParseEntries_004A5E60 Alias)

## Status

- Address range: [UID:00013W][0x004a5e60-0x004a609f.ParseEntries](by-memory/0x004a5e60-0x004a609f.ParseEntries.md)
- Symbol kind: searchable global/helper alias; exact implementation is owned by UID00013W.
- Source-facing signature: full-register integer result with mutable eight-byte input, unsigned validation key, and writable untyped four-byte output storage.
- Source-facing name: `DecodeTableValue`; `ParseEntries_004A5E60` is retained only as historical/search provenance.
- Likely owner file: [UID:0000IN][DATFile](by-file/DATFile.md)
- Compiler initializer-pool evidence: [UID:0003IC][0x006192e0-0x00619340.ParseEntriesConstantTable](by-memory/0x006192e0-0x00619340.ParseEntriesConstantTable.md), non-emitting and owned by UID00013W.
- Typed direct callers: [UID:0004IY][0x0049c4a0-0x0049c4ef.DATFileReadEncodedTableInt](by-memory/0x0049c4a0-0x0049c4ef.DATFileReadEncodedTableInt.md) and [UID:0004IZ][0x0049c4f0-0x0049c53f.DATFileReadEncodedTableFloat](by-memory/0x0049c4f0-0x0049c53f.DATFileReadEncodedTableFloat.md).
- Confidence: very strong for behavior/ownership and high for inferred source name.

## Function Role

`DecodeTableValue` decodes exactly one eight-byte encoded scalar unit. It initializes and cumulatively XOR-mixes a local 27-dword table, starts at unsigned `(0xFEDCBA98u - validationKey) % 27u`, XOR-mutates all eight bytes while stepping backward modulo 27, reads two big-endian words, validates complementary interleaved bits with `0x55555555u`, and writes one four-byte payload only on success.

The integer/float distinction belongs to the wrappers, not this helper. UID0004IY supplies integer storage at 87 higher-level call sites; UID0004IZ supplies float storage at six sites in four functions. The decoder performs no numeric float conversion.

Failure returns full-register `0`, leaves output untouched, and does not roll back the already-mutated input bytes. Success writes the payload and returns full-register `1`. No allocation, ownership transfer, persistent buffer, entry array, outer 17-byte archive record, or sentinel is involved.

## Evidence Notes

- IDA MCP `lookup_funcs` on 2026-05-25 confirms `0x004a5e60` as a real function of size `0x23f`, ending half-open at `0x004a609f`.
- IDA MCP caller/xref checks confirm only UID0004IY and UID0004IZ call it, at `0x0049c4d4` and `0x0049c524`.
- IDA MCP `decompile` on 2026-05-25 shows both `DATFile` wrappers only compute the encoded key from `GetSize() >> 1`, read eight bytes, and dispatch to this helper.
- Live IDA MCP recheck on 2026-06-03 reconfirms the same two direct call sites and shows `ParseEntries` has no project callees beyond the compiler security-cookie check.
- Live IDA MCP decompilation/full disassembly shows the exact 27-value local initializer, pairwise cumulative XOR mixing, unsigned key arithmetic, eight-byte in-place decode, big-endian reads, `0x55555555` validation/payload expressions, conditional output write, and full-register integer return.
- Live IDA MCP `py_eval` ties the adjacent read-only constants at `0x006192e0` and `0x006192f0` to this helper and confirms the `0xcc` padding split at `0x004a609f`.
- 2026-06-12/2026-07-12 xref and disassembly checks tie all six 16-byte blocks to this helper. Current source reanalysis shows they are compiler pooling for the first 24 local initializer values; final values `3,5,9` are immediate stack stores. UID0003IC is therefore non-reconstructable standalone data owned by UID00013W.
- Current-package `LIGHT.TBL` did not validate under this executable's exact schedule (0/385 units); that is preserved as package/version/path mismatch negative evidence, not used to infer payload values.

## Historical And Negative Evidence

- `ParseEntries`, `ReadAllEntries`, and `ReadAllEntriesAlt` were historical documentation names that overstate collection behavior. They remain search aliases only.
- The scalar unit is not [UID:0000UC][DATEntryRecord](by-item/DATEntryRecord.md); no 17-byte stride, name, next-record offset, or archive directory layout is read here.
- Address adjacency to Encoder/Decoder code does not establish BinaryCodec ownership; padding separates the ranges and only DATFile methods call the helper.
- Do not emit a duplicate body from this alias or a duplicate constant declaration from UID0003IC.

## Source Layout Decision

Emit the complete helper only from UID00013W as a private/static-style function in `archive/DATFile.cpp`. This alias emits the formal covered-by comment above. It is not a render/image/BinaryCodec helper; those modules are indirect consumers or address neighbors.

## Cross-References

- [UID:00013W][0x004a5e60-0x004a609f.ParseEntries](by-memory/0x004a5e60-0x004a609f.ParseEntries.md)
- [UID:0000V5][ParseEntries_004A5E60](by-item/ParseEntries_004A5E60.md)
- [UID:0004IY][0x0049c4a0-0x0049c4ef.DATFileReadEncodedTableInt](by-memory/0x0049c4a0-0x0049c4ef.DATFileReadEncodedTableInt.md)
- [UID:0004IZ][0x0049c4f0-0x0049c53f.DATFileReadEncodedTableFloat](by-memory/0x0049c4f0-0x0049c53f.DATFileReadEncodedTableFloat.md)
- [UID:0000IN][DATFile](by-file/DATFile.md)
- [UID:00003G][DATFile](by-class/DATFile.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)
- [UID:0003IC][0x006192e0-0x00619340.ParseEntriesConstantTable](by-memory/0x006192e0-0x00619340.ParseEntriesConstantTable.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `86/90`.
  - Before: page documented the DAT table/header decoder behavior, exact callers, decompiled algorithm, and DATFile placement but remained unevaluated.
  - After: score reflects near-complete behavior and owner documentation for this helper.
  - Evidence: IDA notes confirm the function range, only `DATFile::ReadAllEntries` / `ReadAllEntriesAlt` callers, generated decompile match, 27-entry constant table, XOR mixing, big-endian reads, and validation mask.
- 2026-06-03: Set `RECONSTRUCTABLE:TRUE` and `AUTOGEN_PARENT_UID:0000IN`; score remains `86/90`.
  - Before: the page was scored as strong but remained unclassified for generation and still cited generated recovery provenance.
  - After: live IDA MCP evidence independently supports the same helper behavior and source placement: exact range, caller restriction to the two DATFile bulk readers, wrapper handoff logic, no project callees, constant references, validation/output behavior, and the padding boundary.
  - Historical remaining gap: final code was then withheld under the obsolete `95/95` policy and unresolved naming/constant-source assumptions.
- 2026-06-12 A002 Batch 321: Raised `86/90 -> 87/91`.
  - Summary/evidence: split exact constant data child [UID:0003IC][0x006192e0-0x00619340.ParseEntriesConstantTable](by-memory/0x006192e0-0x00619340.ParseEntriesConstantTable.md) from the legacy mixed codec/DAT range and attached it here. Live IDA MCP confirms every 16-byte block in that table is referenced only from this helper.
- 2026-07-12 B001 UID00013W callback:
  - Before: `87/91`, blank formal block, historical helper/bulk-wrapper names, and standalone constant-table wording.
  - After: `90/93`, source-facing `DecodeTableValue` alias documentation, complete scalar/failure/lifetime contract, real wrapper UIDs, compiler-pool correction, preserved negative evidence, and exact covered-by block.
  - Owner/emitter UID0000IN and reconstructable true remain unchanged because this searchable alias intentionally surfaces a no-duplicate marker through the same source root.
