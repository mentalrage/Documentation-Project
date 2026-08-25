** TARGET-REPORT-UID:00020L **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00020L-00020Q AES Block Cipher Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: raise all six primary AES executable targets above the active `85/85` quality gate, keep owner/emitter [UID:00020J] `AesBlockCipher`, keep `RECONSTRUCTABLE:TRUE`, and keep the current split boundaries. Do not populate formal per-target C++ yet.
- Final disposition: this is one compact AES-128/CBC utility island under `NexusTK/util/AesBlockCipher.cpp`, with source-declared/generated-binary static tables and a file-static mutable state block. It is not owned by network, auth, archive, startup, or a class object.
- Required action: update target/support docs with the resolved names, wrapper liveness conclusion, file-static state model, nonstandard tail behavior, zero-filled mutable state wording, score changes, and exact `by-memory/-coverage-report.md` rows below.
- Confidence: high for AES-128 identity, exact ranges, table/state ownership, source-file placement, and no-direct-reference liveness; medium-high for source spelling because no original symbols or exact third-party source have been found.

## Target

- Assignment: `B002-goal2-aes-block-cipher-source-quality-00020L-00020M-00020N-00020O-00020P-00020Q-20260617`.
- Primary targets:
  - [UID:00020L] `by-memory/0x00461790-0x0046189b.AesCbcEncryptRaw.md`, current `82/90`.
  - [UID:00020M] `by-memory/0x004618a0-0x004619b8.AesCbcDecryptRaw.md`, current `82/90`.
  - [UID:00020N] `by-memory/0x004619c0-0x00461c07.AesEncryptBlock.md`, current `84/91`.
  - [UID:00020O] `by-memory/0x00461c10-0x00461dc7.AesDecryptBlock.md`, current `84/91`.
  - [UID:00020P] `by-memory/0x00461dd0-0x00461fd4.AesInvMixColumns.md`, current `82/91`.
  - [UID:00020Q] `by-memory/0x00461fe0-0x00462114.AesKeySchedule128.md`, current `82/91`.
- Current owner/emitter for all six: [UID:00020J] `AesBlockCipher`.
- Generated route checked: `auto-generated/NexusTK/util/AesBlockCipher.cpp`; current file exists but is zero bytes.
- Executed B reports searched for these UIDs and AES names under B001/B002/B003 executed research; no prior AES B report was found.

## Executive Recommendation

Keep the current source root [UID:00020J] `AesBlockCipher` and utility path `NexusTK/util/AesBlockCipher.cpp`. The island is self-contained: wrapper code calls only the local AES key schedule and block transforms, the transforms read only local AES tables and mutable state, and there are no subsystem callers or resource/protocol strings that would justify a narrower feature owner.

Resolve the wrapper liveness question as: live source-linked code with no surviving direct entry evidence. Current IDA shows no xrefs to raw starts `0x00461790` or `0x004618a0`, and a literal VA scan for all six function starts found no stored address bytes. That rejects ordinary direct-call, callback-table, vtable, and stored function-pointer reachability. The wrappers are still real source-authored code, not padding or compiler glue, because they are prologued function bodies with internal calls to `AesKeySchedule128`, `AesEncryptBlock`, and `AesDecryptBlock`.

Use AES naming rather than generic Rijndael naming. The implementation is AES-128 only: `0x10` / 16-byte blocks, 10 rounds, `0x2c` / 44 key-schedule words, and `0xb0` / 176 expanded-key bytes, all verified with `tools/int_convert.py`.

## IDA MCP Facts

- Active IDA session: `b003_00018a_ime_comp_20260617`, input `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready.
- Function lookup:
  - `0x00461790`, `0x0046189b`, `0x004618a0`, and `0x004619b8` are not IDA functions.
  - `0x004619c0` is `sub_4619C0`, size `0x247`.
  - `0x00461c10` is `sub_461C10`, size `0x1b7`.
  - `0x00461dd0` is `sub_461DD0`, size `0x204`.
  - `0x00461fe0` is `sub_461FE0`, size `0x134`.
- Xrefs:
  - No xrefs to wrapper starts `0x00461790` or `0x004618a0`.
  - `AesEncryptBlock` has only raw-wrapper call xrefs at `0x0046183a` and `0x0046188f`.
  - `AesDecryptBlock` has only raw-wrapper call xrefs at `0x00461934` and `0x004619ac`.
  - `AesInvMixColumns` has one caller at `0x00461d00` inside `AesDecryptBlock`.
  - `AesKeySchedule128` has only raw-wrapper call xrefs at `0x004617d0` and `0x004618e0`.
- Literal VA scan:
  - `find_bytes` for little-endian VA bytes `90 17 46 00`, `A0 18 46 00`, `C0 19 46 00`, `10 1C 46 00`, `D0 1D 46 00`, and `E0 1F 46 00` returned zero matches. This is negative evidence against stored entrypoint pointers for all six starts.
- Padding:
  - Current `get_bytes` confirms `0xcc` padding at `0x0046178a-0x00461790`, `0x0046189b-0x004618a0`, `0x004619b8-0x004619c0`, `0x00461c07-0x00461c10`, `0x00461dc7-0x00461dd0`, `0x00461fd4-0x00461fe0`, and `0x00462114-0x00462120`.
- Table/state:
  - Forward S-box head at `0x00610fe8`: `63 7c 77 7b f2 6b 6f c5 ...`.
  - Inverse S-box head at `0x006110e8`: `52 09 6a d5 30 36 a5 38 ...`.
  - Rcon head at `0x006111e8`: `8d 01 02 04 08 10 20 40 80 1b 36 ...`; index zero sentinel `0x8d` / 141 verified with `tools/int_convert.py`.
  - Mutable state `0x0067a878-0x0067a934` is currently zero-filled and xref-bounded to the AES island.

## Source Shape And Names

Recommended source-facing names:

| UID | Source-facing name | Signature direction |
| --- | --- | --- |
| [UID:00020L] | `AesCbcEncryptBuffer` | `void AesCbcEncryptBuffer(unsigned char* dst, unsigned char* src, unsigned int length, const unsigned char* keyOrNull, const unsigned char* ivOrNull)` |
| [UID:00020M] | `AesCbcDecryptBuffer` | `void AesCbcDecryptBuffer(unsigned char* dst, const unsigned char* src, unsigned int length, const unsigned char* keyOrNull, const unsigned char* ivOrNull)` |
| [UID:00020N] | `AesEncryptBlock` | private in-place helper over the file-static current-block pointer and expanded key |
| [UID:00020O] | `AesDecryptBlock` | private in-place helper over the file-static current-block pointer and expanded key |
| [UID:00020P] | `AesInvMixColumns` or `AesInverseMixColumns` | private decrypt helper; `InvMixColumns` matches AES nomenclature and current page name |
| [UID:00020Q] | `AesExpandKey128` / `AesKeySchedule128` | private AES-128 key expansion; `AesExpandKey128` is more source-like, but current page name remains acceptable |

Recommended static state shape:

```cpp
struct AesBlockCipherState
{
    unsigned char* currentBlock;
    const unsigned char* currentKey;
    unsigned char expandedKey[176];
    const unsigned char* cbcChain;
};
```

This maps exactly to [UID:00028Y]:

- `currentBlock`: `0x0067a878`.
- `currentKey`: `0x0067a87c`.
- `expandedKey[176]`: `0x0067a880-0x0067a930`; `0xb0` / 176 verified with `tools/int_convert.py`.
- `cbcChain`: `0x0067a930`.
- Total state size: `0xbc` / 188 verified with `tools/int_convert.py`.

Reject a class/object model for now. There is no `this` pointer, vtable, constructor, destructor, object allocation, or context argument. A file-static `AesBlockCipherState` is the best source-quality grouping for the binary. A public context API can be considered later for cleanup, but it is not the best representation of the original binary shape.

## CBC Tail Behavior

Do not document these wrappers as ordinary one-block zero padding without the caveat. The raw wrappers save `tail = length & 0x0f`, then if `length != 0` compute `((length - 1) >> 4) + 1` blocks and process that many 16-byte blocks. If `tail != 0`, they then copy another 16-byte block at the post-loop source pointer, zero-fill from `tail` through the end of that block, and run the block transform again.

That is exact current binary behavior for both encrypt and decrypt. It may reflect a caller convention where input has an extra block available, an older retained helper with a bug, or a higher-level framing contract not currently reachable. No live caller exists to resolve the intended framing. Score should not be capped below `85/85` because the byte behavior is now exact, but docs should avoid claiming PKCS padding or a normal single final zero-padded block.

## Third-Party / Provenance Recheck

- The AES tables and round logic are standard, but standard AES constants alone do not identify a specific third-party source.
- Local `third_party_embeds` search found no AES/Rijndael/crypto source payload.
- Documentation/source-tree search found only existing AES docs and utility placement, not a license banner, source path, symbol, or library family.
- The implementation uses a project-local file-static scratch shape rather than a recognizable public high-level API. That leans toward a copied/adapted small AES implementation or project utility source, not a vendored static embed that should be moved under `third_party/`.
- Keep [UID:00020J] under `NexusTK/util/AesBlockCipher.cpp`. If a later exact source match is found, move the implementation to a vendored/static-embed owner then.

## Heuristic / Inference Reanalysis And Validation

Best defensible inferences:

- Wrapper liveness: retained source-linked helper bodies with no surviving external entry evidence. Evidence checked: IDA xrefs to both raw starts, literal VA byte scans for all six starts, internal call xrefs, and padding bytes. Rejected direct ordinary caller, vtable/callback table, and stored function-pointer alternatives. A computed indirect call remains theoretically possible but has no evidence; it should not block ownership or score.
- Source owner: [UID:00020J] `AesBlockCipher` remains the best owner/emitter. Evidence checked: table/state xrefs are AES-island-only; helpers have no subsystem strings/resources/imports/callers; proposed source tree already has `util/AesBlockCipher.cpp`; adjacent AboveFrame and AlphaMaskSurface ranges are separated by confirmed padding. Rejected network/auth/archive/startup ownership because there are no caller or state ownership links.
- Naming: use AES-128 names, not broad Rijndael names. Evidence checked: 16-byte blocks, 10-round AES flow, AES S-box/inverse S-box/Rcon, 44 schedule words, no 192/256-bit key expansion. Rejected generic `RijndaelEncrypt` because the implemented key schedule is fixed to AES-128.
- State model: file-static `AesBlockCipherState` is preferred over a class object or external context. Evidence checked: no `this`, no object lifecycle, no caller-provided context, and all state xrefs confined to file-local helpers. Rejected process-wide product global names because the data is purely implementation scratch, not shared application state.
- Tables: source-level names should be `s_aesSBox`, `s_aesInvSBox`, and `s_aesRcon`. Evidence checked: exact table heads/tails and consumer xrefs. Rejected opaque `byte_610FE8`/`dword_67A880` naming and rejected table ownership by the mixed `.rdata` aggregate.
- Tail handling: exact binary behavior is a ceil-block loop plus an extra zero-filled block for non-multiple lengths. Evidence checked: live raw disassembly for both wrappers. Rejected the simpler existing wording that implies a single ordinary final partial block.
- Formal C++ readiness: not ready for per-target formal population. Evidence checked: current generated file is empty, support table/state formal blocks are blank, wrapper external liveness is rejected rather than proven, and a correct source implementation needs coordinated file-level declarations/macros/inline GF helpers across multiple target pages.

Validation/contradiction of current docs:

- Current docs correctly identify AES behavior, ranges, tables, and owner.
- Current docs are stale where they say C++ remains blank below the old `95/95` gate. The active gate is now `(completion + confidence) / 2 > 85`; the reason to keep blank is source-shape coordination, not score.
- Current proposed-source-tree text is stale where it says `0xff`-initialized scratch state. [UID:00028Y] and current IDA evidence support loader-zeroed state.
- Current CBC wrapper docs should refine the tail wording to show the extra zero-filled post-loop block.

Score/source-placement/final-C++ impact:

- All six primaries can rise above the gate because the unresolved items are now bounded with evidence and best-source direction.
- Owner/emitter stays [UID:00020J].
- No split is needed; exact target pages and padding rows already partition the island.
- Formal C++ should remain blank for all six primaries until [UID:00020J], [UID:00020K], [UID:0002JU], and [UID:00028Y] receive a coordinated source-level AES implementation plan.

## First-Draft C++ Recommendation

Do not populate formal `RECONSTRUCTION_CPP CODE` for [UID:00020L]-[UID:00020Q] in this pass, even after scores are raised. This is a deliberate do-not-populate recommendation.

Concrete reason: any safe C++ must be staged as one coordinated file-level AES implementation with shared declarations for the static tables, `AesBlockCipherState`, `xtime`/GF helpers, and private block/key helpers. Populating one target page at a time would either emit decompiler-shaped global names, duplicate helper code across memory pages, or produce uncompilable snippets that reference support data whose formal blocks are still blank. The raw CBC wrappers also have no proven live external entrypoint, so exposing them as public functions before the file-level API is chosen would be source-shape speculation.

Future coordinated file-level source should use this contract, not raw `dword_` names:

```cpp
static const unsigned char s_aesSBox[256];
static const unsigned char s_aesInvSBox[256];
static const unsigned char s_aesRcon[256];
static AesBlockCipherState s_aesState;

static void AesExpandKey128(const unsigned char* key);
static void AesEncryptBlock();
static void AesDecryptBlock();
static void AesInvMixColumns();
static void AesCbcEncryptBuffer(unsigned char* dst, unsigned char* src, unsigned int length,
                                const unsigned char* keyOrNull, const unsigned char* ivOrNull);
static void AesCbcDecryptBuffer(unsigned char* dst, const unsigned char* src, unsigned int length,
                                const unsigned char* keyOrNull, const unsigned char* ivOrNull);
```

The snippets above are source-shape guidance only and should not be pasted into individual target formal blocks as the accepted C++ for this assignment.

## Exact Score And Metadata Recommendations

Primary targets:

```text
[UID:00020L] 82/90 -> 86/91, CANONICAL_OWNER:00020J, RECONSTRUCTABLE:TRUE, EMITTER_UIDS:00020J, formal C++ blank.
[UID:00020M] 82/90 -> 86/91, CANONICAL_OWNER:00020J, RECONSTRUCTABLE:TRUE, EMITTER_UIDS:00020J, formal C++ blank.
[UID:00020N] 84/91 -> 87/92, CANONICAL_OWNER:00020J, RECONSTRUCTABLE:TRUE, EMITTER_UIDS:00020J, formal C++ blank.
[UID:00020O] 84/91 -> 87/92, CANONICAL_OWNER:00020J, RECONSTRUCTABLE:TRUE, EMITTER_UIDS:00020J, formal C++ blank.
[UID:00020P] 82/91 -> 86/92, CANONICAL_OWNER:00020J, RECONSTRUCTABLE:TRUE, EMITTER_UIDS:00020J, formal C++ blank.
[UID:00020Q] 82/91 -> 87/92, CANONICAL_OWNER:00020J, RECONSTRUCTABLE:TRUE, EMITTER_UIDS:00020J, formal C++ blank.
```

Support recommendations:

```text
[UID:00020J] AesBlockCipher: 88/91 -> 89/92. Keep PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" and CANONICAL_OWNER:FILE.
[UID:00020K] AesBlockCipherStateAndTables: 86/93 -> 88/93. Keep owner/emitter [UID:00020J], formal C++ blank.
[UID:0002JU] AesReadOnlyTables: keep 86/93 unless table declarations are coordinated with file-level AES C++; update coverage confidence wording to very strong.
[UID:00028Y] AesMutableStateAndKeySchedule: 85/91 -> 87/92 after replacing remaining global/context uncertainty with the file-static state model.
```

## Support Docs To Update

- [UID:00020J] `by-file/AesBlockCipher.md`: add the no-xref plus literal-VA-scan liveness result; replace old 95/95 C++ gate wording; record file-static state model; record exact nonstandard tail behavior; state that formal C++ remains blank for coordinated source-shape reasons.
- [UID:00020K] `by-global/AesBlockCipherStateAndTables.md`: replace "prefer context if behavior permits" wording with "file-static `AesBlockCipherState` is the best binary/source model"; keep exact table/static names.
- [UID:0002JU] `by-memory/0x00610fe8-0x006112e8.AesReadOnlyTables.md`: keep owner but update source naming guidance to `s_aesSBox`, `s_aesInvSBox`, `s_aesRcon`; no formal table C++ yet.
- [UID:00028Y] `by-memory/0x0067a878-0x0067a934.AesMutableStateAndKeySchedule.md`: update score and source-shape text to the `AesBlockCipherState` layout above.
- `by-project-structure/proposed-source-tree.md`: in the `util/AesBlockCipher.cpp` section, replace "`0xff`-initialized scratch state" with loader-zeroed/file-static AES mutable state, and update the liveness line to say no xrefs or literal VA references were found.
- `by-memory/-ignored.md`: no content change required; AES padding spans are already correct.

## Supervisor-Owned `by-memory/-coverage-report.md` Row Text

Placement: replace the six executable AES rows under the existing `0x00461790-0x00462114` AES island while leaving the padding rows unchanged.

```markdown
    - [UID:00020L][0x00461790-0x0046189b.AesCbcEncryptRaw](by-memory/0x00461790-0x0046189b.AesCbcEncryptRaw.md) 0x00461790-0x0046189b | function | AesCbcEncryptRaw : reconstructable : 86% : very strong : B002 2026-06-17 source-quality reanalysis resolves this as a retained source-authored AES-CBC encrypt buffer wrapper with no inbound xrefs or literal VA references, internal calls to key expansion/encrypt block, file-static AES state, exact ceil-loop plus extra zero-filled tail behavior, and owner/emitter [UID:00020J][AesBlockCipher](by-file/AesBlockCipher.md); formal C++ remains blank pending coordinated file-level AES source declarations.
    - [UID:00020M][0x004618a0-0x004619b8.AesCbcDecryptRaw](by-memory/0x004618a0-0x004619b8.AesCbcDecryptRaw.md) 0x004618a0-0x004619b8 | function | AesCbcDecryptRaw : reconstructable : 86% : very strong : B002 2026-06-17 source-quality reanalysis resolves this as a retained source-authored AES-CBC decrypt buffer wrapper with no inbound xrefs or literal VA references, internal calls to key expansion/decrypt block, file-static AES state, exact ceil-loop plus extra zero-filled tail behavior, and owner/emitter [UID:00020J][AesBlockCipher](by-file/AesBlockCipher.md); formal C++ remains blank pending coordinated file-level AES source declarations.
    - [UID:00020N][0x004619c0-0x00461c07.AesEncryptBlock](by-memory/0x004619c0-0x00461c07.AesEncryptBlock.md) 0x004619c0-0x00461c07 | function | AesEncryptBlock : reconstructable : 87% : very strong : AES-128 in-place block encrypt transform with raw-wrapper-only callers, initial/final AddRoundKey, nine full rounds, forward S-box refs, file-static expanded-key/current-block state, exact padding boundaries, and [UID:00020J][AesBlockCipher](by-file/AesBlockCipher.md) owner/emitter; formal C++ remains blank until shared AES tables/state helpers are emitted coherently.
    - [UID:00020O][0x00461c10-0x00461dc7.AesDecryptBlock](by-memory/0x00461c10-0x00461dc7.AesDecryptBlock.md) 0x00461c10-0x00461dc7 | function | AesDecryptBlock : reconstructable : 87% : very strong : AES-128 in-place block decrypt transform with raw-wrapper-only callers, backward expanded-key refs, inverse S-box refs, sole inverse-MixColumns callee, file-static current-block state, exact padding boundaries, and [UID:00020J][AesBlockCipher](by-file/AesBlockCipher.md) owner/emitter; formal C++ remains blank until shared AES tables/state helpers are emitted coherently.
    - [UID:00020P][0x00461dd0-0x00461fd4.AesInvMixColumns](by-memory/0x00461dd0-0x00461fd4.AesInvMixColumns.md) 0x00461dd0-0x00461fd4 | helper | AesInvMixColumns : reconstructable : 86% : very strong : Private AES inverse MixColumns helper called only by `AesDecryptBlock`, with arithmetic GF reduction using `0x1b`, no callees, one current-state pointer ref, no table refs, exact padding boundaries, and [UID:00020J][AesBlockCipher](by-file/AesBlockCipher.md) owner/emitter; formal C++ remains blank pending coordinated AES helper declarations.
    - [UID:00020Q][0x00461fe0-0x00462114.AesKeySchedule128](by-memory/0x00461fe0-0x00462114.AesKeySchedule128.md) 0x00461fe0-0x00462114 | helper | AesKeySchedule128 : reconstructable : 87% : very strong : AES-128 key expansion helper with raw-wrapper-only callers, 16-byte key copy, `0x2c` / 44-word schedule stop, forward S-box and Rcon refs, `0xb0` / 176-byte expanded-key output, exact padding boundaries, and [UID:00020J][AesBlockCipher](by-file/AesBlockCipher.md) owner/emitter; formal C++ remains blank pending coordinated AES table/state declarations.
```

Placement: update the existing AES data rows in their current address locations if support recommendations are applied.

```markdown
        - [UID:0002JU][0x00610fe8-0x006112e8.AesReadOnlyTables](by-memory/0x00610fe8-0x006112e8.AesReadOnlyTables.md) 0x00610fe8-0x006112e8 | source-declared data | AesReadOnlyTables : reconstructable : 86% : very strong : AES forward S-box, inverse S-box, and Rcon table island with exact three `0x100`-byte `.rdata` subranges, head/tail byte checks, neighboring boundary evidence, AES-island-only consumers, source names `s_aesSBox`/`s_aesInvSBox`/`s_aesRcon`, and [UID:00020J][AesBlockCipher](by-file/AesBlockCipher.md) owner/emitter; formal table C++ remains blank pending coordinated file-level AES source.
    - [UID:00028Y][0x0067a878-0x0067a934.AesMutableStateAndKeySchedule](by-memory/0x0067a878-0x0067a934.AesMutableStateAndKeySchedule.md) 0x0067a878-0x0067a934 | AES mutable state | AesMutableStateAndKeySchedule : reconstructable : 87% : very strong : AES/CBC file-static mutable state modeled as `AesBlockCipherState` with current-block pointer, key pointer, `0xb0` / 176-byte expanded AES-128 key schedule, and chaining pointer; exact `0xbc` / 188-byte loader-zeroed `.data` range, xref-bounded AES-island confinement, and [UID:00020J][AesBlockCipher](by-file/AesBlockCipher.md) owner/emitter documented.
```

## Validation Commands

Run after supervisor applies doc/support/coverage updates:

> Executable block R001 was removed from this report and preserved verbatim in [00020L-00020Q-aes-block-cipher-source-quality-removed.md](00020L-00020Q-aes-block-cipher-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Because this report recommends blank formal C++ for the six primaries, `auto-generated/NexusTK/util/AesBlockCipher.cpp` may remain empty until a coordinated AES source implementation is later accepted.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B002/research/00020L-00020Q-aes-block-cipher-source-quality.md`.
- Not edited: by-* docs, generated reports/source, IDA DB, source files, and `by-memory/-coverage-report.md`.

## Blockers And Follow-Up

- No ownership, range, liveness, or score blocker remains for the six primary pages.
- Formal C++ is intentionally blocked by source-shape coordination, not by lack of AES behavior evidence.
- Useful follow-up: a later coordinated AES implementation pass should populate [UID:00020J], [UID:00020K], [UID:0002JU], [UID:00028Y], and the six helper pages together, or identify an exact third-party source match and move the implementation under the appropriate static-embed path.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/00020L-00020Q-aes-block-cipher-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:24","uid":"00020L"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00020L-00020Q-aes-block-cipher-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/00020L-00020Q-aes-block-cipher-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00020L"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
