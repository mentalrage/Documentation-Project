*** UID:00020K | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:00020J | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# AesBlockCipherStateAndTables

## Status

- Confidence: strong for AES table identity and local helper usage.
- Symbol kind: AES/Rijndael lookup tables plus file-static scratch state.
- Likely source owner: `AesBlockCipher` support module.
- Evidence basis: IDA MCP xrefs and byte checks through 2026-06-05.

## Data Items

| Address/Range | Role | Evidence |
| --- | --- | --- |
| `0x00610fe8` | AES forward S-box | Starts `63 7c 77 7b f2 6b 6f c5 ...`, the standard AES S-box head; read by block encrypt and key expansion. |
| `0x006110e8` | AES inverse S-box | Starts `52 09 6a d5 30 36 a5 38 ...`, the standard inverse S-box head; read by block decrypt. |
| `0x006111e8` | AES Rcon table | Starts `8d 01 02 04 08 10 20 40 80 1b 36 ...`; read by the key expansion helper. |
| `0x0067a878` | current block/state pointer | Written by raw wrappers before block encrypt/decrypt calls; read by all block helpers. |
| `0x0067a87c` | current key pointer | Written by raw wrappers when a new key pointer is supplied; read by key expansion. |
| `0x0067a880-0x0067a92f` | expanded AES-128 key schedule | Populated by key expansion; read by encrypt and decrypt transforms. |
| `0x0067a930` | CBC chaining pointer | Updated by raw CBC wrappers from supplied IV/previous block state. |

The read-only table bytes are now split into [UID:0002JU][0x00610fe8-0x006112e8.AesReadOnlyTables](by-memory/0x00610fe8-0x006112e8.AesReadOnlyTables.md). The mutable storage bytes are split into [UID:00028Y][0x0067a878-0x0067a934.AesMutableStateAndKeySchedule](by-memory/0x0067a878-0x0067a934.AesMutableStateAndKeySchedule.md).

## Xref Summary

- `0x00610fe8` has reads from the encrypt block transform and the key expansion helper.
- `0x006110e8` has reads from the decrypt block transform.
- `0x006111e8` has a read from the key expansion helper.
- `0x0067a878`, `0x0067a87c`, and `0x0067a930` are used only by the AES helper island in current IDA xrefs.
- 2026-06-05 IDA MCP byte reads confirm exact `0x100` `.rdata` tables at `0x00610fe8-0x006110e8`, `0x006110e8-0x006111e8`, and `0x006111e8-0x006112e8`, including head/tail bytes and non-AES neighboring data before/after the table island.
- 2026-06-05 IDA MCP byte reads confirm exact `.data` mutable storage at `0x0067a878-0x0067a934`, all initialized to `0xff`; adjacent bytes are also `0xff`, so the documented subrange is bounded by xrefs rather than a unique byte delimiter.
- 2026-06-05 IDA MCP xrefs confirm raw wrappers write `0x0067a878`, `0x0067a87c`, and `0x0067a930`; `AesKeySchedule128` consumes the key pointer and writes the initial key into `0x0067a880-0x0067a88f`; encrypt/decrypt transforms consume expanded-key offsets through `0x0067a920`.
- 2026-05-31 IDA MCP xrefs show the forward S-box read by `sub_4619C0` at `0x00461a26`/`0x00461b76` and by `sub_461FE0` at `0x004620a7`, `0x004620b4`, `0x004620c1`, and `0x004620d5`; the inverse S-box read by `sub_461C10` at `0x00461cc6`/`0x00461d86`; and Rcon read by `sub_461FE0` at `0x004620cf`.
- 2026-05-31 IDA MCP byte reads show `0x0067a878-0x0067a934` is initialized as `0xff` bytes in the binary, then overwritten by runtime wrapper/key-schedule state.

## Reconstruction Notes

The source reconstruction should avoid exposing these generated-style names. Prefer local static arrays named along the lines of `s_aesSBox`, `s_aesInverseSBox`, and `s_aesRcon`, with a small AES context or explicit function parameters instead of process-global scratch pointers if behavior permits.

## Score Rationale

Completion is raised because this global page now has exact split child pages for both read-only and mutable data, fresh table byte verification, fresh mutable-state byte verification, current xrefs for each pointer/table/schedule role, and clear rebuild guidance. Confidence remains below final-audit levels because the original source names, provenance, and whether the mutable storage was truly global or an artifact of a static helper API remain unresolved.

## Cross-References

- [UID:00020J][AesBlockCipher](by-file/AesBlockCipher.md)
- [UID:0002JU][0x00610fe8-0x006112e8.AesReadOnlyTables](by-memory/0x00610fe8-0x006112e8.AesReadOnlyTables.md)
- [UID:00020L][0x00461790-0x0046189b.AesCbcEncryptRaw](by-memory/0x00461790-0x0046189b.AesCbcEncryptRaw.md)
- [UID:00020M][0x004618a0-0x004619b8.AesCbcDecryptRaw](by-memory/0x004618a0-0x004619b8.AesCbcDecryptRaw.md)
- [UID:00020N][0x004619c0-0x00461c07.AesEncryptBlock](by-memory/0x004619c0-0x00461c07.AesEncryptBlock.md)
- [UID:00020O][0x00461c10-0x00461dc7.AesDecryptBlock](by-memory/0x00461c10-0x00461dc7.AesDecryptBlock.md)
- [UID:00020P][0x00461dd0-0x00461fd4.AesInvMixColumns](by-memory/0x00461dd0-0x00461fd4.AesInvMixColumns.md)
- [UID:00020Q][0x00461fe0-0x00462114.AesKeySchedule128](by-memory/0x00461fe0-0x00462114.AesKeySchedule128.md)
- [UID:00028Y][0x0067a878-0x0067a934.AesMutableStateAndKeySchedule](by-memory/0x0067a878-0x0067a934.AesMutableStateAndKeySchedule.md)

## Changes

- 2026-05-31: Changed autogen reconstruction status from unassigned to reconstructable under [UID:00020J][AesBlockCipher](by-file/AesBlockCipher.md). Summary: IDA MCP xrefs confirm the S-box, inverse S-box, Rcon, scratch pointers, and expanded schedule are used by the AES helper island; the C++ code section remains empty until table/static-storage spelling is chosen.

- 2026-05-31: Split exact read-only and mutable by-memory data pages. Summary/evidence: IDA MCP xrefs and byte reads identify [UID:0002JU][0x00610fe8-0x006112e8.AesReadOnlyTables](by-memory/0x00610fe8-0x006112e8.AesReadOnlyTables.md) as the AES S-box/inverse S-box/Rcon table block and [UID:00028Y][0x0067a878-0x0067a934.AesMutableStateAndKeySchedule](by-memory/0x0067a878-0x0067a934.AesMutableStateAndKeySchedule.md) as initialized mutable AES/CBC scratch state.

- 2026-06-05: Raised completion/confidence to `84/92` after refreshing both AES data child pages. Summary/evidence: IDA MCP confirms exact `0x100` table splits, table head/tail bytes, neighboring `.rdata` boundaries, exact `0xbc` mutable-state span, all-`0xff` initialization, xref-bounded mutable range rationale, and AES-island-only pointer/table/schedule refs; C++ remains blank below the final-code threshold.
