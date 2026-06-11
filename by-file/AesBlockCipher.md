*** UID:00020J | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# AesBlockCipher

## Status

- Confidence: strong that this is AES-128/CBC block cipher support; medium-high for final original filename and live wrapper reachability.
- Proposed module: `NexusTK/util/AesBlockCipher.cpp`, matching the current proposed source tree utility placement.
- Source status: source-authored/static support code, but no live caller or stored function pointer has been found for the wrapper entry points yet.
- Evidence basis: IDA MCP disassembly/decompilation/xref checks through 2026-06-05.

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

The 2026-06-05 IDA MCP recheck confirmed `0x00461790` and `0x004618a0` are not modeled as functions, while the four helpers are modeled exactly as `sub_4619C0` (`0x247` bytes), `sub_461C10` (`0x1b7` bytes), `sub_461DD0` (`0x204` bytes), and `sub_461FE0` (`0x134` bytes). Xrefs from the modeled helpers and tables remain confined to this AES island, supporting a small standalone utility-source placement rather than ownership by network, storage, or startup code.

The 2026-06-05 table/state pass confirms the read-only data in exact [UID:0002JU][0x00610fe8-0x006112e8.AesReadOnlyTables](by-memory/0x00610fe8-0x006112e8.AesReadOnlyTables.md) subranges: forward S-box, inverse S-box, and Rcon are each `0x100` bytes in `.rdata`, with live head/tail byte checks and AES-island-only xrefs. The mutable state page now records that `0x0067a878-0x0067a934` is a `.data` xref-bounded `0xbc` byte block initialized as `0xff` bytes and overwritten at runtime.

## Island Evidence Map

| Area | Evidence | Current handling |
| --- | --- | --- |
| Raw wrappers | 2026-06-05 IDA MCP decodes the encrypt wrapper as 93 instructions at `0x00461790-0x0046189b` and the decrypt wrapper as 97 instructions at `0x004618a0-0x004619b8`; calls resolve to key schedule at `0x004617d0`/`0x004618e0`, encrypt block at `0x0046183a`/`0x0046188f`, and decrypt block at `0x00461934`/`0x004619ac`. | Reconstructable under this file, but C++ remains gated because IDA has no function objects or live external xrefs for the raw wrapper starts. |
| Block transforms | 2026-06-05 IDA MCP confirms the encrypt block `0x004619c0-0x00461c07` has 193 decoded instructions, raw callers at `0x0046183a`/`0x0046188f`, no callees, initial AddRoundKey, nine full rounds, final round, and refs to `0x0067a878`, `0x0067a880`, `0x0067a890`, `0x0067a920`, and `0x00610fe8`; the decrypt block `0x00461c10-0x00461dc7` has 137 decoded instructions, raw xrefs at `0x00461934`/`0x004619ac`, inverse S-box refs at `0x00461cc6`/`0x00461d86`, backward expanded-key refs to `0x0067a920`, `0x0067a910`, and `0x0067a880`, and current-block ref `0x0067a878`. | Private AES-128 block helpers under this file. |
| Inverse MixColumns | 2026-06-05 IDA MCP confirms `0x00461dd0-0x00461fd4` has 195 decoded instructions, sole caller `AesDecryptBlock` at `0x00461d00`, no callees, one state-pointer ref to `0x0067a878`, twelve `0x1b` reduction-constant instructions, no lookup-table refs, and `0xcc` padding before/after. | Private decrypt helper, not an independent feature function. |
| Key schedule | 2026-06-05 IDA MCP confirms `0x00461fe0-0x00462114` has 85 decoded instructions, raw wrapper callers at `0x004617d0`/`0x004618e0`, no callees, 16 initial key-byte writes to `0x0067a880-0x0067a88f`, four forward-S-box refs, one Rcon ref, and loop stop at word index `0x2c`. | Private AES-128 schedule expansion helper under this file. |
| Tables/state | 2026-06-05 IDA MCP confirms three exact `0x100` `.rdata` tables at `0x00610fe8`, `0x006110e8`, and `0x006111e8`; exact `.data` mutable storage at `0x0067a878-0x0067a934`; all-`0xff` mutable initialization; current-block, key-pointer, expanded-key, and CBC chaining refs; and table/state xrefs confined to the AES island. | Source-declared/static support data under this file, represented by exact data child pages. |

## Rebuild Notes

Prefer reconstructing this as a compact AES-128 helper with explicit state passed through parameters. The binary uses globals for the current state pointer, key pointer, expanded key schedule, and CBC chaining pointer; those globals may be implementation artifacts or original file-static scratch variables.

If later evidence identifies the exact third-party implementation, this page should be revised and the code should move under a vendored/static-embed third-party folder. Until then, keep it as a project support utility with a clear caveat.

## Open Questions

- Whether the original file name was AES, Rijndael, crypt, or a broader utility/security source file.
- Whether the wrappers were intentionally dead code, called indirectly from unloaded data, or retained from an older protocol/storage path.
- Whether the public source-facing wrappers should expose CBC mode or whether only the block/key-schedule routines were intended to be private.

## Score Rationale

Completion is now raised because the file root has exact executable ranges, exact table/state child pages, parented helper pages, fresh raw encrypt/decrypt wrapper instruction maps, refreshed key-schedule, encrypt/decrypt block, inverse-MixColumns, table, and mutable-state maps, and an island-level xref map. Confidence stays below final-source levels because wrapper liveness, original file name, source API shape, and third-party provenance are still unresolved.

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

- 2026-06-03: Raised completion/confidence from `68/88` to `76/89` and added an island evidence map. Summary/evidence: fresh IDA MCP xrefs confirm raw-wrapper calls to key schedule and block helpers, decrypt-to-inverse-MixColumns ownership, and AES table/global state refs confined to this source island; C++ remains blank because wrapper reachability and source API are not final.
- 2026-06-05: Raised completion/confidence to `80/90` after refreshing the raw encrypt-wrapper page. Summary/evidence: IDA MCP confirms the encrypt wrapper has 93 decoded instructions ending at `0x0046189a`, no xrefs to the raw entry or neighboring boundary, refreshed key-schedule/encrypt-block call offsets, scratch-global refs, and `0xcc` padding on both sides; the file remains below the final-C++ gate because source API, liveness, original filename, and provenance are still unresolved.
- 2026-06-05: Raised completion to `82` after refreshing the raw decrypt-wrapper page. Summary/evidence: IDA MCP confirms the decrypt wrapper has 97 decoded instructions ending at `0x004619b7`, no xrefs to the raw entry or neighboring boundary, refreshed key-schedule/decrypt-block call offsets, scratch-global refs, and `0xcc` padding on both sides; source API, liveness, original filename, and provenance still keep final C++ blank.
- 2026-06-05: Raised completion to `83` after refreshing the key-schedule helper. Summary/evidence: IDA MCP confirms `0x00461fe0-0x00462114` bounds, 85 decoded instructions, raw wrapper callers, no callees, initial key copy into `0x0067a880`, S-box/Rcon refs, loop stop at word index `0x2c`, and `0xcc` padding before/after; final source API/provenance questions still keep the file below the final-C++ gate.
- 2026-06-05: Raised completion to `84` after refreshing the encrypt-block helper. Summary/evidence: IDA MCP confirms `0x004619c0-0x00461c07` bounds, 193 decoded instructions, raw encrypt-wrapper callers, no callees, current-block/key/S-box refs, nine full rounds plus final round, and `0xcc` padding before/after; final source API/provenance questions still keep the file below the final-C++ gate.
- 2026-06-05: Raised completion to `85` after refreshing the decrypt-block helper. Summary/evidence: IDA MCP confirms `0x00461c10-0x00461dc7` bounds, 137 decoded instructions, raw decrypt-wrapper xrefs, sole inverse-MixColumns callee, inverse S-box refs, backward expanded-key refs, current-block ref, and `0xcc` padding before/after; final source API/provenance questions still keep the file below the final-C++ gate.
- 2026-06-05: Raised completion to `86` after refreshing the inverse-MixColumns helper. Summary/evidence: IDA MCP confirms `0x00461dd0-0x00461fd4` bounds, 195 decoded instructions, sole decrypt-block caller, no callees, one current-state ref, no table refs, repeated `0x1b` reduction constants, and `0xcc` padding before/after; final source API/provenance questions still keep the file below the final-C++ gate.
- 2026-06-05: Raised completion/confidence to `88/91` after refreshing the AES table/state pages. Summary/evidence: IDA MCP confirms exact `0x100` forward S-box, inverse S-box, and Rcon tables with head/tail bytes and neighboring boundaries, exact `0xbc` mutable-state span, all-`0xff` initialization, xref-bounded mutable storage, and AES-island-only table/state refs; final source API/provenance questions still keep the file below the final-C++ gate.
