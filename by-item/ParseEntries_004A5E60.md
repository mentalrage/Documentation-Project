*** UID:0000V5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IN | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IN | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted implementation for this historical ParseEntries item alias is covered by [UID:00013W][0x004a5e60-0x004a609f.ParseEntries](by-memory/0x004a5e60-0x004a609f.ParseEntries.md) DecodeTableValue.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# DecodeTableValue Item Alias (Historical ParseEntries 0x004A5E60)

## Status

- Confidence: very strong for behavior/placement and high for inferred source naming.
- Entity kind: searchable item alias for a file-local helper.
- Canonical global page: [UID:0000TH][ParseEntries_004A5E60](by-global/ParseEntries_004A5E60.md)
- Likely source module: [UID:0000IN][DATFile](by-file/DATFile.md)
- Exact range: [UID:00013W][0x004a5e60-0x004a609f.ParseEntries](by-memory/0x004a5e60-0x004a609f.ParseEntries.md)
- Source-facing name/contract: `DecodeTableValue`, full-register integer `1`/`0`, mutable eight-byte input, unsigned validation key, and writable untyped four-byte output storage.
- Typed direct callers: [UID:0004IY][0x0049c4a0-0x0049c4ef.DATFileReadEncodedTableInt](by-memory/0x0049c4a0-0x0049c4ef.DATFileReadEncodedTableInt.md) and [UID:0004IZ][0x0049c4f0-0x0049c53f.DATFileReadEncodedTableFloat](by-memory/0x0049c4f0-0x0049c53f.DATFileReadEncodedTableFloat.md).

## Behavior

`DecodeTableValue` decodes one eight-byte table scalar in place, validates complementary interleaved key bits, and writes one 32-bit payload bit pattern only on success. Historical `ParseEntries` naming is retained for search/provenance but must not appear as the emitted helper name.

Inputs:

- `encodedBytes`: exactly eight mutable bytes read by a typed DATFile wrapper.
- `validationKey`: unsigned `GetSize() >> 1` from that wrapper.
- `outValue`: four-byte storage supplied as `int *` by UID0004IY or `float *` by UID0004IZ; no numeric float conversion occurs.

Algorithm summary:

- Builds one local 27-dword table in exact initializer order `75,25,31,29,26,9,12,12,83,73,19,17,29,23,6,29,9,6,8,27,28,1,30,29,3,5,9`.
- Cumulatively XOR-mixes odd/even pairs, then XOR-decodes eight bytes while stepping backward modulo 27 from unsigned `(0xFEDCBA98u - validationKey) % 27u`.
- Reads the first and second decoded four-byte halves as big-endian 32-bit values.
- Validates with the `0x55555555` deinterleave mask.
- Validates `second ^ ((first ^ second) & 0x55555555u)` against the key.
- Writes `first ^ ((first ^ second) & 0x55555555u)` and returns full-register `1` on success.
- Returns full-register `0` and leaves output untouched on failure, but all eight input bytes remain mutated because there is no rollback.

No array/vector, allocation, ownership transfer, sentinel, outer archive directory row, persistent buffer, or project callee beyond compiler security-cookie support exists.

## Evidence

- IDA MCP caller check on 2026-05-22 also reported only those two caller sites.
- IDA MCP recheck on 2026-05-25 again reports only those callers, at call sites `0x0049c4d4` and `0x0049c524`; callee checks show `ParseEntries` only calls the compiler security-cookie check.
- IDA MCP decompile on 2026-05-25 shows both `DATFile` wrappers compute `GetSize() >> 1`, read an eight-byte local buffer, and immediately call `ParseEntries`, supporting file-local helper placement.
- IDA MCP recheck on 2026-05-31 confirms `sub_4A5E60` starts at `0x004a5e60`, ends half-open at `0x004a609f`, has only two caller functions at `0x0049c4a0` and `0x0049c4f0`, and only calls the security-cookie check.
- Live IDA MCP recheck on 2026-06-03 reconfirmed `sub_4A5E60` range `0x004a5e60-0x004a609f`, size `0x23f`, with direct call sites only at `0x0049c4d4` and `0x0049c524`.
- Live IDA MCP `decompile` plus full disassembly shows the exact local initializer/order, unsigned key schedule, in-place decode, big-endian assembly, validation/payload expressions, conditional output write, and full-register result.
- Live IDA MCP `decompile 0x0049c4a0` and `0x0049c4f0` shows both wrappers call virtual slot `+20` for size, pass `GetSize() >> 1` as the encoded key, read eight bytes through virtual slot `+32`, then immediately call `sub_4A5E60`.
- Live IDA MCP `py_eval` confirms the adjacent constant window at `0x006192e0` is referenced from inside `sub_4A5E60`, and the byte at `0x004a609f` is `0xcc` padding before the following code bytes.
- 2026-07-12 B001 xref/consumer review resolves `0x0049c4a0` as the 87-call integer wrapper and `0x0049c4f0` as the six-call float wrapper. Both exact children now carry complete formal bodies.
- [UID:0003IC][0x006192e0-0x00619340.ParseEntriesConstantTable](by-memory/0x006192e0-0x00619340.ParseEntriesConstantTable.md) is now correctly classified as compiler pooling for the first 24 local initializer values; final values `3,5,9` are immediate stores.
- A current-package `LIGHT.TBL` check produced 0/385 validations and is preserved only as package/version/path mismatch negative evidence.

## Historical And Negative Evidence

- The helper does not parse [UID:0000UC][DATEntryRecord](by-item/DATEntryRecord.md). That outer archive row is 17 bytes (`uint32` offset plus 13-byte name); this item consumes one unrelated eight-byte scalar inside a table payload.
- `ReadAllEntries` / `ReadAllEntriesAlt` are historical aliases that overstate collection behavior. Use the typed wrapper names recorded above.
- BinaryCodec/Decoder address adjacency is not ownership proof; padding separates the ranges and only DATFile methods call this helper.
- The target body is emitted only by UID00013W. This item alias must emit only its formal covered-by comment.

## Ownership Decision

Keep this as a file-local helper in [UID:0000IN][DATFile](by-file/DATFile.md). UID0004IY/UID0004IZ are class methods under UID00003G; image/resource libraries are indirect consumers. The exact implementation and 27-value initializer live only on UID00013W.

## Cross-References

- [UID:0000UC][DATEntryRecord](by-item/DATEntryRecord.md)
- [UID:0000TH][ParseEntries_004A5E60](by-global/ParseEntries_004A5E60.md)
- [UID:00013W][0x004a5e60-0x004a609f.ParseEntries](by-memory/0x004a5e60-0x004a609f.ParseEntries.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)
- [UID:00003G][DATFile](by-class/DATFile.md)
- [UID:0004IY][0x0049c4a0-0x0049c4ef.DATFileReadEncodedTableInt](by-memory/0x0049c4a0-0x0049c4ef.DATFileReadEncodedTableInt.md)
- [UID:0004IZ][0x0049c4f0-0x0049c53f.DATFileReadEncodedTableFloat](by-memory/0x0049c4f0-0x0049c53f.DATFileReadEncodedTableFloat.md)
- [UID:0003IC][0x006192e0-0x00619340.ParseEntriesConstantTable](by-memory/0x006192e0-0x00619340.ParseEntriesConstantTable.md)

## Changes

- 2026-05-31: Grading and reconstruction status changed from unevaluated/blank to `70/85` and `RECONSTRUCTABLE:TRUE`.
  - Before: the page body documented the DAT header decoder, but the validator metadata still showed `0/0` and no reconstruction status.
  - After: the metadata now tracks it as rebuild-relevant DAT helper code. Parent UID and C++ remain blank because final file-local placement and source-level naming should be coordinated with the canonical DATFile pages.
  - Evidence: IDA MCP confirms the exact function range, two DATFile wrapper callers, and no project callees beyond the security-cookie check.
- 2026-06-03: Completion/confidence changed from `70/85` to `86/90`, and `AUTOGEN_PARENT_UID` set to [UID:0000IN][DATFile](by-file/DATFile.md).
  - Before: the page had only summary-level behavior and older caller evidence, so it stayed below the canonical global page's score and was not attached for generation.
  - After: live IDA MCP evidence now covers the exact function bounds, only two direct DATFile wrapper callers, no project callees beyond the security-cookie check, wrapper handoff behavior, in-place decode algorithm, constant-table references, validation expression, and neighboring padding.
  - Historical remaining gap: code was then withheld under the obsolete `95/95` rule and unresolved source-name/constant-shape assumptions.
- 2026-07-12 B001 UID00013W callback:
  - Before: `86/90`, blank formal block, historical entry-header/bulk-reader model, and a false relationship implication to the outer DATEntryRecord.
  - After: `89/92`, complete one-scalar/failure/lifetime behavior, exact wrapper UIDs and typed roles, compiler-pool correction, explicit DATEntryRecord distinction, preserved negative evidence, and exact covered-by block.
