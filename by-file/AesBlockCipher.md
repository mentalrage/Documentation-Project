*** UID:00020J | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# AesBlockCipher

## Status

- Confidence: very strong that this is AES-128/CBC block cipher support; medium-high for final original filename and source-facing public API spelling.
- Proposed module: `NexusTK/util/AesBlockCipher.cpp`, matching the current proposed source tree utility placement.
- Source status: source-authored/static support code. No direct caller, vtable/callback-table entry, stored function pointer, or literal VA reference has been found for the wrapper entry points, so the wrappers are retained source-linked helpers with no surviving direct entry evidence.
- Evidence basis: IDA MCP disassembly/decompilation/xref checks through 2026-06-17.

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

Current IDA evidence does not show direct xrefs, stored dword references, or literal little-endian VA references to the raw wrappers at `0x00461790` or `0x004618a0`. Treat this as a real source-linked support island that may be dead or indirectly reached by a mechanism not currently modeled, not as compiler-generated padding.

The 2026-06-05 IDA MCP recheck confirmed `0x00461790` and `0x004618a0` are not modeled as functions, while the four helpers are modeled exactly as `sub_4619C0` (`0x247` bytes), `sub_461C10` (`0x1b7` bytes), `sub_461DD0` (`0x204` bytes), and `sub_461FE0` (`0x134` bytes). Xrefs from the modeled helpers and tables remain confined to this AES island, supporting a small standalone utility-source placement rather than ownership by network, storage, or startup code.

The 2026-06-05 table/state pass confirms the read-only data in exact [UID:0002JU][0x00610fe8-0x006112e8.AesReadOnlyTables](by-memory/0x00610fe8-0x006112e8.AesReadOnlyTables.md) subranges: forward S-box, inverse S-box, and Rcon are each `0x100` bytes in `.rdata`, with live head/tail byte checks and AES-island-only xrefs. The mutable state page now records that `0x0067a878-0x0067a934` is a `.data` xref-bounded `0xbc` byte block that the current IDA database reads as zero-filled and that wrappers/key-schedule code overwrites at runtime.

The 2026-06-17 B002 source-quality pass resolves the best source model as a file-static AES state block rather than a class, product global, or caller-provided context object. No `this` pointer, vtable, constructor/destructor, allocation, or external context argument is present. The source-facing state should be documented as a private `AesBlockCipherState` in this utility source, with fields for the current block pointer, current key pointer, `0xb0` / 176-byte expanded AES-128 key schedule, and CBC chaining pointer.

## Island Evidence Map

| Area | Evidence | Current handling |
| --- | --- | --- |
| Raw wrappers | 2026-06-05 IDA MCP decodes the encrypt wrapper as 93 instructions at `0x00461790-0x0046189b` and the decrypt wrapper as 97 instructions at `0x004618a0-0x004619b8`; calls resolve to key schedule at `0x004617d0`/`0x004618e0`, encrypt block at `0x0046183a`/`0x0046188f`, and decrypt block at `0x00461934`/`0x004619ac`. | Reconstructable under this file, but C++ remains gated because IDA has no function objects or live external xrefs for the raw wrapper starts. |
| Block transforms | 2026-06-05 IDA MCP confirms the encrypt block `0x004619c0-0x00461c07` has 193 decoded instructions, raw callers at `0x0046183a`/`0x0046188f`, no callees, initial AddRoundKey, nine full rounds, final round, and refs to `0x0067a878`, `0x0067a880`, `0x0067a890`, `0x0067a920`, and `0x00610fe8`; the decrypt block `0x00461c10-0x00461dc7` has 137 decoded instructions, raw xrefs at `0x00461934`/`0x004619ac`, inverse S-box refs at `0x00461cc6`/`0x00461d86`, backward expanded-key refs to `0x0067a920`, `0x0067a910`, and `0x0067a880`, and current-block ref `0x0067a878`. | Private AES-128 block helpers under this file. |
| Inverse MixColumns | 2026-06-05 IDA MCP confirms `0x00461dd0-0x00461fd4` has 195 decoded instructions, sole caller `AesDecryptBlock` at `0x00461d00`, no callees, one state-pointer ref to `0x0067a878`, twelve `0x1b` reduction-constant instructions, no lookup-table refs, and `0xcc` padding before/after. | Private decrypt helper, not an independent feature function. |
| Key schedule | 2026-06-05 IDA MCP confirms `0x00461fe0-0x00462114` has 85 decoded instructions, raw wrapper callers at `0x004617d0`/`0x004618e0`, no callees, 16 initial key-byte writes to `0x0067a880-0x0067a88f`, four forward-S-box refs, one Rcon ref, and loop stop at word index `0x2c`. | Private AES-128 schedule expansion helper under this file. |
| Tables/state | 2026-06-14 IDA MCP confirms three exact `0x100` `.rdata` tables at `0x00610fe8`, `0x006110e8`, and `0x006111e8`; exact `.data` mutable storage at `0x0067a878-0x0067a934`; current zero-filled mutable bytes; current-block, key-pointer, expanded-key, and CBC chaining refs; and table/state xrefs confined to the AES island. | Source-declared/static support data under this file, represented by exact data child pages. |

## Rebuild Notes

Prefer reconstructing this as a compact AES-128 helper with file-static support declarations rather than exposing the decompiler-style globals. The binary uses file-local storage for the current block pointer, key pointer, expanded key schedule, and CBC chaining pointer; current evidence does not support a class object or caller-provided context.

Recommended source-facing names for a coordinated future implementation are `AesCbcEncryptBuffer`, `AesCbcDecryptBuffer`, `AesEncryptBlock`, `AesDecryptBlock`, `AesInvMixColumns`, and `AesExpandKey128` / `AesKeySchedule128`. The read-only tables should use names such as `s_aesSBox`, `s_aesInvSBox`, and `s_aesRcon`, and the mutable storage should be a file-static `AesBlockCipherState`.

The CBC wrappers do not implement ordinary PKCS padding or a simple single final zero-padded partial block. They process `((length - 1) >> 4) + 1` blocks when `length != 0`; if `length & 0x0f` is nonzero, they then copy one additional 16-byte block at the post-loop source pointer, zero-fill from the tail offset through the end of that extra block, and transform it. This exact behavior is documented because no live caller has been found to explain whether it reflects caller framing, retained helper drift, or a real higher-level contract.

Formal per-target C++ now uses a coordinated file-level emitter order: [UID:0002JU][0x00610fe8-0x006112e8.AesReadOnlyTables](by-memory/0x00610fe8-0x006112e8.AesReadOnlyTables.md) emits the read-only tables first, [UID:00020K][AesBlockCipherStateAndTables](by-global/AesBlockCipherStateAndTables.md) emits the shared state type and helpers second, [UID:00028Y][0x0067a878-0x0067a934.AesMutableStateAndKeySchedule](by-memory/0x0067a878-0x0067a934.AesMutableStateAndKeySchedule.md) emits the file-static state third, and the executable helpers/wrappers follow at ordered positions. This preserves the single `AesBlockCipher.cpp` source shape without isolated decompiler-style snippets.

If later evidence identifies the exact third-party implementation, this page should be revised and the code should move under a vendored/static-embed third-party folder. Until then, keep it as a project support utility with a clear caveat.

## Rule 26 Incorporated B002 Research

- Wrapper liveness is now bounded: direct xrefs, stored function-pointer bytes, vtable/callback-table evidence, and literal VA references were checked and were absent for the six AES starts. The helpers are still source-authored because the bodies are aligned, padded, internally called, and semantically cohesive.
- Source ownership stays with [UID:00020J] `AesBlockCipher`: all executable helpers, read-only tables, and mutable state xrefs are confined to this island, and no auth/network/archive/startup caller or string/resource evidence supports a feature owner.
- Naming should be AES-128-specific, not generic Rijndael: the implementation uses 16-byte blocks, 10 rounds, 44 key-schedule words, a 176-byte expanded key, AES S-box/inverse S-box, and AES Rcon.
- The file-static state model supersedes both the older all-`0xff` mutable-state assumption and the weaker "prefer context if behavior permits" guidance. The best current source model is private static AES state owned by this file.
- Rejected alternatives: class/object owner, process-wide product global owner, network/auth/archive/startup ownership, generic Rijndael naming, table ownership by the surrounding mixed `.rdata` aggregate, and ordinary public CBC API exposure before a coordinated source plan exists.

## Evidence-Bounded Remaining Questions

- The original file name may have been AES, Rijndael, crypt, or a broader utility/security source file; current source-tree evidence still makes `NexusTK/util/AesBlockCipher.cpp` the safest emitted path.
- The wrappers may have been intentionally dead, computed-indirectly reached, or retained from an older protocol/storage path. Current xref and literal-VA evidence rejects ordinary direct reachability but cannot prove why the linker retained them.
- The final public API should not be chosen until a coordinated AES source implementation is drafted. Current source-facing names are descriptive best guesses, not proven original symbols.

## Score Rationale

Completion and confidence are raised because the file root now has exact executable ranges, exact table/state child pages, parented helper pages, fresh raw encrypt/decrypt wrapper instruction maps, refreshed key-schedule, encrypt/decrypt block, inverse-MixColumns, table, mutable-state maps, island-level xref and literal-VA negative evidence, exact tail-behavior wording, file-static state modeling, rejected alternatives, and a bounded C++ staging policy. Confidence stays below final-source levels because original file name, exact source API spelling, and third-party provenance remain unresolved.

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
- 2026-06-05: Raised completion/confidence to `88/91` after refreshing the AES table/state pages. Summary/evidence: IDA MCP confirmed exact `0x100` forward S-box, inverse S-box, and Rcon tables with head/tail bytes and neighboring boundaries, exact `0xbc` mutable-state span, then-believed all-`0xff` initialization later superseded by loader-zeroed/current-zero evidence, xref-bounded mutable storage, and AES-island-only table/state refs.
- 2026-06-14 A001 Goal 2 AES mutable-state correction: score remains `88/91`. Summary/evidence: live IDA MCP and raw section-offset sanity checks supersede the earlier all-`0xff` mutable-state note; [UID:00028Y][0x0067a878-0x0067a934.AesMutableStateAndKeySchedule](by-memory/0x0067a878-0x0067a934.AesMutableStateAndKeySchedule.md) now records zero-filled current bytes while preserving the exact xref-bounded AES helper-island storage interpretation.
- 2026-06-17 B002 Rule 26 source-quality incorporation: raised completion/confidence to `89/92`. Summary/evidence: B002 rechecked xrefs, literal VA references, table/state ownership, AES-128 naming, file-static state layout, nonstandard CBC tail behavior, rejected subsystem/class/context owners, and formal-C++ readiness. At that stage C++ was left blank pending a coordinated file-level implementation rather than isolated by-memory snippets.
- 2026-06-29 B012 UID00020J implementation callback: raised completion/confidence to `91/93` and applied the coordinated AES formal C++ plan. Summary/evidence: accepted report `00020J-AesBlockCipher-empty-emitter-family-source-quality.md` populated ordered table/state/helper/wrapper emitters through this file root, preserved the no-third-party-import decision, and kept unresolved original filename/API/wrapper-retention questions as final-audit caveats rather than first-draft blockers.
