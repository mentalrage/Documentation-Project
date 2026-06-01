*** UID:00020J | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:68 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# AesBlockCipher

## Status

- Confidence: strong that this is AES-128 block cipher support; medium-high for final original filename.
- Proposed module: `NexusTK/util/AesBlockCipher.cpp`, matching the current proposed source tree utility placement.
- Source status: source-authored/static support code, but no live caller or stored function pointer has been found for the wrapper entry points yet.
- Evidence basis: IDA MCP disassembly/decompilation/xref checks on 2026-05-27 and 2026-05-31.

## Contents

This file should own the contiguous AES helper island at `0x00461790-0x00462114` and the associated AES state/tables:

- `0x00461790-0x0046189b`: raw AES-CBC encrypt wrapper.
- `0x004618a0-0x004619b8`: raw AES-CBC decrypt wrapper.
- `0x004619c0-0x00461c07`: AES block encrypt transform.
- `0x00461c10-0x00461dc7`: AES block decrypt transform.
- `0x00461dd0-0x00461fd4`: inverse MixColumns helper used by the decrypt path.
- `0x00461fe0-0x00462114`: AES-128 key expansion.
- [UID:0002JU][0x00610fe8-0x006112e8.AesReadOnlyTables](by-memory/0x00610fe8-0x006112e8.AesReadOnlyTables.md): AES forward S-box, inverse S-box, and Rcon/key-schedule table.
- [UID:00028Y][0x0067a878-0x0067a934.AesMutableStateAndKeySchedule](by-memory/0x0067a878-0x0067a934.AesMutableStateAndKeySchedule.md): scratch pointers, expanded key schedule, and CBC chaining pointer.

## Ownership Notes

The implementation is standard AES/Rijndael style code: 16-byte blocks, 10 rounds, S-box and inverse S-box tables, Rcon key-schedule constants, AddRoundKey/SubBytes/ShiftRows/MixColumns sequencing, and inverse MixColumns in the decrypt path.

Current IDA evidence does not show direct xrefs or stored dword references to the raw wrappers at `0x00461790` or `0x004618a0`. Treat this as a real source-linked support island that may be dead or indirectly reached by a mechanism not currently modeled, not as compiler-generated padding.

The 2026-05-31 IDA MCP recheck confirmed `0x00461790` and `0x004618a0` are not modeled as functions, while the four helpers are modeled exactly as `sub_4619C0` (`0x247` bytes), `sub_461C10` (`0x1b7` bytes), `sub_461DD0` (`0x204` bytes), and `sub_461FE0` (`0x134` bytes). Xrefs from the modeled helpers and tables remain confined to this AES island, supporting a small standalone utility-source placement rather than ownership by network, storage, or startup code.

The 2026-05-31 table pass split the read-only data into an exact [UID:0002JU][0x00610fe8-0x006112e8.AesReadOnlyTables](by-memory/0x00610fe8-0x006112e8.AesReadOnlyTables.md) page. IDA xrefs show the forward S-box consumed by encrypt/key schedule, inverse S-box consumed by decrypt, and Rcon consumed by key expansion. The mutable state page now records that `0x0067a878-0x0067a934` is initialized as `0xff` bytes and overwritten at runtime.

## Rebuild Notes

Prefer reconstructing this as a compact AES-128 helper with explicit state passed through parameters. The binary uses globals for the current state pointer, key pointer, expanded key schedule, and CBC chaining pointer; those globals may be implementation artifacts or original file-static scratch variables.

If later evidence identifies the exact third-party implementation, this page should be revised and the code should move under a vendored/static-embed third-party folder. Until then, keep it as a project support utility with a clear caveat.

## Open Questions

- Whether the original file name was AES, Rijndael, crypt, or a broader utility/security source file.
- Whether the wrappers were intentionally dead code, called indirectly from unloaded data, or retained from an older protocol/storage path.
- Whether the public source-facing wrappers should expose CBC mode or whether only the block/key-schedule routines were intended to be private.

## Cross-References

- [UID:00020K][AesBlockCipherStateAndTables](by-global/AesBlockCipherStateAndTables.md)
- [UID:0002JU][0x00610fe8-0x006112e8.AesReadOnlyTables](by-memory/0x00610fe8-0x006112e8.AesReadOnlyTables.md)
- [UID:00020L][0x00461790-0x0046189b.AesCbcEncryptRaw](by-memory/0x00461790-0x0046189b.AesCbcEncryptRaw.md)
- [UID:00020M][0x004618a0-0x004619b8.AesCbcDecryptRaw](by-memory/0x004618a0-0x004619b8.AesCbcDecryptRaw.md)
- [UID:00020N][0x004619c0-0x00461c07.AesEncryptBlock](by-memory/0x004619c0-0x00461c07.AesEncryptBlock.md)
- [UID:00020O][0x00461c10-0x00461dc7.AesDecryptBlock](by-memory/0x00461c10-0x00461dc7.AesDecryptBlock.md)
- [UID:00020P][0x00461dd0-0x00461fd4.AesInvMixColumns](by-memory/0x00461dd0-0x00461fd4.AesInvMixColumns.md)
- [UID:00020Q][0x00461fe0-0x00462114.AesKeySchedule128](by-memory/0x00461fe0-0x00462114.AesKeySchedule128.md)
- [UID:00028Y][0x0067a878-0x0067a934.AesMutableStateAndKeySchedule](by-memory/0x0067a878-0x0067a934.AesMutableStateAndKeySchedule.md)

## Changes

- 2026-05-31: Changed projected reconstruction placement from ambiguous `util/AesBlockCipher.cpp` / `crypto/AesBlockCipher.cpp` to `NexusTK/util/AesBlockCipher.cpp`. Summary: the existing proposed source tree already places this module under `util`, and the fresh IDA MCP xref check still shows an isolated AES support island with no subsystem caller evidence that would justify a narrower owner.

- 2026-05-31: Split AES read-only table data into exact by-memory documentation. Summary/evidence: IDA MCP xrefs and byte reads identify `0x00610fe8-0x006112e8` as the AES forward S-box, inverse S-box, and Rcon table block, all consumed only by the local AES helper island.
