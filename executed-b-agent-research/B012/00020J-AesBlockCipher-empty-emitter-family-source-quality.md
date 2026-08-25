** TARGET-REPORT-UID:00020J **
** AUTHOR-AGENT-ID:B012 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00020J AesBlockCipher Empty-Emitter Family Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: convert [UID:00020J] `AesBlockCipher` from a documented-but-empty AES island into a coordinated first-draft source emitter family. Do not use a third-party import: no staged AES/Rijndael/crypto source exists under `third_party_embeds`, and the current binary shape is a project-local file-static AES-128/CBC utility rather than a proven vendored library.
- Final disposition: keep all nine current emitters under [UID:00020J] `by-file/AesBlockCipher.md` and `NexusTK/util/AesBlockCipher.cpp`; populate them as one ordered source unit: read-only tables, shared declarations/support, zero-initialized state, private helpers, and the two raw CBC wrappers.
- Required action: implementation callback should edit only the named target/support docs, assign emitter positions, replace stale blank-C++ rationale with source-ready coordinated C++ blocks, fix the stale `all-0xff` UID00028Y summary/coverage wording, validate all scoped docs, and confirm generated `auto-generated/NexusTK/util/AesBlockCipher.cpp` no longer has the nine `Empty Emitter Marker` rows.
- Confidence: high for AES-128 identity, boundaries, local owner/emitter route, data/state layout, and no-import disposition; medium-high for exact original function spellings because no PDB/source symbols were recovered.

## Target

- Target UID: [UID:00020J].
- Target path: `by-file/AesBlockCipher.md`.
- Generated file: `auto-generated/NexusTK/util/AesBlockCipher.cpp`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md` lists [UID:00020J] under `Files With Empty Emitters`, `9` total emitters, `0` filled, `9` empty.
- Current scores and parent state: [UID:00020J] is `89/92`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/"`, `CANONICAL_OWNER:FILE`.

## Current Target State

- Existing metadata: all nine child emitters are reconstructable, owned by [UID:00020J], and route to [UID:00020J].
- Existing C++ state: current generated file header is `validator-command-id: 000000001133`, `validator-refreshed-at: 2026-06-29T19:53:21-04:00`, and every AES emitter has `Empty Emitter Marker`.
- Existing blocker: the B002 accepted policy correctly rejected isolated snippets, but the current empty-emitter assignment now needs a coordinated formal implementation rather than another blank-C++ deferral.
- Stale current text found: [UID:00028Y] `Item Summary` and `by-memory/-coverage-report.md` still say `all-0xff initialization`; current MCP and page body prove loader-zeroed/static storage.
- Related docs checked: target [UID:00020J], support [UID:00020K], [UID:00020L], [UID:00020M], [UID:00020N], [UID:00020O], [UID:00020P], [UID:00020Q], [UID:0002JU], [UID:00028Y], `by-project-structure/proposed-source-tree.md`, `by-file/-coverage-report.md`, `by-global/-coverage-report.md`, `by-memory/-coverage-report.md`, current generated C++ file, B002 executed AES report, tracker/resolved/unresolved generated reports, and `third_party_embeds`.

## Executive Recommendation

Keep `AesBlockCipher.cpp` as a compact utility source file. Populate the formal blocks in dependency order by setting `EMITTER_POSITION_OPTIONAL`:

| UID | Path | Proposed position | Source role |
| --- | --- | ---: | --- |
| [UID:0002JU] | `by-memory/0x00610fe8-0x006112e8.AesReadOnlyTables.md` | `1` | `s_aesSBox`, `s_aesInvSBox`, `s_aesRcon` arrays from exact MCP bytes |
| [UID:00020K] | `by-global/AesBlockCipherStateAndTables.md` | `2` | shared struct, prototypes, and small inline AES byte helpers |
| [UID:00028Y] | `by-memory/0x0067a878-0x0067a934.AesMutableStateAndKeySchedule.md` | `3` | `static AesBlockCipherState s_aesState;` loader-zeroed storage |
| [UID:00020P] | `by-memory/0x00461dd0-0x00461fd4.AesInvMixColumns.md` | `10` | private inverse MixColumns helper |
| [UID:00020Q] | `by-memory/0x00461fe0-0x00462114.AesKeySchedule128.md` | `20` | private AES-128 key expansion |
| [UID:00020N] | `by-memory/0x004619c0-0x00461c07.AesEncryptBlock.md` | `30` | private AES block encrypt transform |
| [UID:00020O] | `by-memory/0x00461c10-0x00461dc7.AesDecryptBlock.md` | `40` | private AES block decrypt transform |
| [UID:00020L] | `by-memory/0x00461790-0x0046189b.AesCbcEncryptRaw.md` | `50` | raw AES-CBC encrypt wrapper |
| [UID:00020M] | `by-memory/0x004618a0-0x004619b8.AesCbcDecryptRaw.md` | `60` | raw AES-CBC decrypt wrapper |

This resolves the empty-emitter blocker without changing ownership, splitting ranges, inventing a class, or importing unavailable third-party source.

## Supervisor Active Recheck

- Active assignment: `B012-report-00020J-AesBlockCipher-empty-emitter-family-20260629`.
- Required scope: all current empty emitters in `auto-generated/NexusTK/util/AesBlockCipher.cpp`, plus third-party source check and coordinated source-shape blocker resolution.
- Split repair: not required. Current ranges are exact and separated by confirmed `0xcc` padding or exact data child pages.

## Inference Research Guidance Check

- IDA/MCP facts are separated from documentation evidence and source-shape inference below.
- Existing B002 documentation was treated as a lead; live MCP session `3fa0535f` rechecked the main binary facts before this report.
- No Wave2/Wave3 stale instruction was used as authority. Generated reports were used only for current empty-emitter/tracker state.

## Heuristic / Inference Reanalysis And Validation

- Wrapper liveness: current MCP `xrefs_to` has no xrefs to `0x00461790` or `0x004618a0`, and `find_bytes` for little-endian starts `90 17 46 00`, `A0 18 46 00`, `C0 19 46 00`, `10 1C 46 00`, `D0 1D 46 00`, and `E0 1F 46 00` returned zero matches. This rejects direct calls, stored function pointers, vtables, and ordinary callback tables. It does not make the bodies padding: both wrappers have prologues, real control flow, `_memset`, and internal calls.
- Source owner: [UID:00020J] remains correct. All code/data refs are confined to the AES helper island, and no network/auth/archive/startup/resource/class evidence ties the source to another owner.
- Source names: use AES-128 names, not generic Rijndael. Evidence is fixed 16-byte blocks, 10 rounds, 44 schedule words, a 176-byte expanded key, AES S-box/inverse S-box/Rcon, and no 192/256-bit branch.
- State model: file-static `AesBlockCipherState` remains better than class/context/product globals because there is no `this`, vtable, constructor/destructor, allocation, or caller-supplied context.
- C++ readiness: the earlier "blank until coordinated" blocker is now converted into a concrete ordered emitter plan. Isolated per-page code remains rejected; coordinated positioned blocks are safe enough for first-draft source.
- Third-party route: rejected for this pass. `third_party_embeds` contains jsoncpp, libjpeg, lodepng, and zlib files only; `rg` for `aes|rijndael|sbox|rcon|crypto|encrypt|decrypt` in `third_party_embeds` found no AES payload. No import directive is justified.

## Evidence Standards Used

- Direct IDA/MCP evidence: session `3fa0535f`; `server_health`, `lookup_funcs`, `xrefs_to`, `find_bytes`, `get_bytes`, `callees`, `decompile`, `disasm`, and `int_convert`.
- Documentation evidence: current by-* pages, generated C++ header/state, generated research tracker, B002 executed report, project-level resolved/unresolved reports, proposed source tree, and manual coverage rows.
- Negative evidence: no staged third-party AES source, no direct wrapper xrefs, no literal VA byte matches for six AES starts, no class/object evidence, no non-AES consumers of table/state heads.

## Evidence Checked

- MCP availability: `idb_list` returned active worker session `3fa0535f`, path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, pid/worker pid `16844`, `is_analyzing:false`.
- MCP health: `server_health(database=3fa0535f)` status `ok`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- Function lookup: wrappers `0x00461790` and `0x004618a0` are not IDA functions; modeled helpers are `sub_4619C0` size `0x247`, `sub_461C10` size `0x1b7`, `sub_461DD0` size `0x204`, and `sub_461FE0` size `0x134`.
- Xrefs: wrapper starts have zero xrefs; block helpers/key schedule have only raw-wrapper or local helper xrefs; table/state xrefs match the AES island.
- Bytes: MCP confirmed `0xcc` padding around the executable ranges, S-box/inverse-S-box/Rcon heads, and 188 zero bytes at `0x0067a878`.
- Decompile: modeled helpers confirm encrypt rounds, decrypt rounds with inverse MixColumns call, arithmetic inverse MixColumns, and AES-128 key expansion.
- Old reports searched: `rg` terms included `00020J`, `00020K`, `00020L`, `00020M`, `00020N`, `00020O`, `00020P`, `00020Q`, `0002JU`, `00028Y`, `AesBlockCipher`, `AesCbc`, `AesEncryptBlock`, `AesDecryptBlock`, `AesInvMixColumns`, and `AesKeySchedule`. Relevant match opened: `executed-b-agent-research/B002/00020L-00020Q-aes-block-cipher-source-quality.md`.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | [UID:00020J] remains the by-file root under `NexusTK/util/AesBlockCipher.cpp`; no owner/emitter change is needed. | High | Current docs, MCP xref confinement, proposed source tree | `by-file/AesBlockCipher.md` Status/Rebuild Notes/Changes; metadata now `91/93`, `CANONICAL_OWNER:FILE`, `NexusTK/util/` | incorporate | applied |
| C02 | The correct repair is coordinated positioned C++ blocks, not isolated snippets or continued blank formal blocks. | High | Current generated file had 9 empty markers; shared table/state/helper dependencies | all nine emitter docs populated in formal `RECONSTRUCTION_CPP CODE` blocks; generated `auto-generated/NexusTK/util/AesBlockCipher.cpp` has no AES empty markers | incorporate | applied |
| C03 | No third-party import is justified because no AES/Rijndael/crypto source is staged under `third_party_embeds`. | High | `Get-ChildItem` and `rg` searches | [UID:00020J] Rebuild Notes/Changes and [UID:0002JU] Reconstruction Notes retain direct source declarations and no import directive | incorporate | applied |
| C04 | [UID:00020K] should emit shared struct/prototypes/inline helpers and move to position `2`, after the table declarations it references. | Medium-high | by-global role, dependency order | `by-global/AesBlockCipherStateAndTables.md` metadata/C++ now `90/93`, `EMITTER_POSITION_OPTIONAL:2`, shared struct/helpers/prototypes present | incorporate | applied |
| C05 | [UID:0002JU] should emit exact read-only AES table declarations from MCP bytes and move to position `1`. | High | MCP `get_bytes 0x00610fe8 size 768` | `by-memory/0x00610fe8-0x006112e8.AesReadOnlyTables.md` metadata/C++ now `90/94`, `EMITTER_POSITION_OPTIONAL:1`, exact table declarations present | incorporate | applied |
| C06 | [UID:00028Y] should emit zero-initialized `static AesBlockCipherState s_aesState;`, move to position `3`, and fix stale `all-0xff` summary text. | High | MCP zero bytes, A001/B002 docs | `by-memory/0x0067a878-0x0067a934.AesMutableStateAndKeySchedule.md` Item Summary/C++ now `90/93`, `EMITTER_POSITION_OPTIONAL:3`, `static AesBlockCipherState s_aesState;`, loader-zeroed/current-zero summary | incorporate | applied |
| C07 | [UID:00020P], [UID:00020Q], [UID:00020N], [UID:00020O], [UID:00020L], and [UID:00020M] should emit private helper/wrapper functions at positions `10/20/30/40/50/60`. | Medium-high | MCP decompile/disasm/callees/xrefs | six by-memory executable pages now emit `AesInvMixColumns`, `AesExpandKey128`, `AesEncryptBlock`, `AesDecryptBlock`, `AesCbcEncryptBuffer`, and `AesCbcDecryptBuffer` in formal C++ at accepted positions | incorporate | applied |
| C08 | Wrapper entry liveness remains bounded negative evidence: no xrefs and no literal VA byte matches. | High | MCP `xrefs_to`, `find_bytes` | [UID:00020J] Ownership/Rule 26 notes and [UID:00020L]/[UID:00020M] Rule 26/Evidence sections retained no-xref/no-literal-VA caveat | incorporate | applied |
| C09 | CBC tail behavior must preserve the binary's extra post-loop zero-filled block for non-multiple lengths, not PKCS padding. | High | Current wrapper pages and MCP disasm landmarks | [UID:00020L], [UID:00020M], and [UID:00020J] Rebuild/Rule 26 notes retained; wrapper formal C++ includes accepted post-loop tail blocks | incorporate | applied |
| C10 | Manual `by-memory/-coverage-report.md` rows are stale and need supervisor-owned refresh if callback scope allows; B012 must not edit manual coverage in this report-only pass. | High | `rg` rows show old scores/all-0xff | Manual coverage text remains in report only; active goal explicitly excluded manual `-coverage-report.md` edits | incorporate | excluded-with-reason |
| C11 | Generated C++ freshness currently predates this report and should be refreshed by validators during implementation. | High | generated header id `000000001133` before callback; validators with `--wait-generated` | `auto-generated/NexusTK/util/AesBlockCipher.cpp` refreshed to validator-command-id `000000001210`, timestamp `2026-06-29T20:28:39-04:00`, no AES empty markers | incorporate | applied |

## Positive Evidence Summary

- The AES code/data island is internally cohesive: raw wrappers call only local AES helpers; modeled helpers use only AES tables/state and local helper calls.
- AES identity is hard evidence: standard S-box/inverse S-box heads, Rcon head, 16-byte blocks, 10 rounds, `0x2c` / 44 schedule words, `0xb0` / 176 expanded-key bytes, and inverse MixColumns `0x1b` reduction arithmetic.
- Current source placement is already valid and generated; the problem is only that all child formal blocks are empty.

## IDA MCP Facts

- Session: `3fa0535f`, `server_health` ok on 2026-06-29.
- `lookup_funcs`: `0x00461790` and `0x004618a0` are raw non-functions; `0x004619c0`, `0x00461c10`, `0x00461dd0`, and `0x00461fe0` are modeled at sizes `0x247`, `0x1b7`, `0x204`, and `0x134`.
- `xrefs_to`: `0x00461790` and `0x004618a0` have zero xrefs; `0x004619c0` has two raw encrypt-wrapper xrefs; `0x00461c10` has two raw decrypt-wrapper xrefs; `0x00461dd0` has one decrypt-block xref; `0x00461fe0` has two raw-wrapper xrefs.
- Table xrefs: `0x00610fe8` has six refs from encrypt/key schedule; `0x006110e8` has two decrypt refs; `0x006111e8` has one key-schedule ref.
- State xrefs: `0x0067a878` has ten AES refs; `0x0067a87c` has three; `0x0067a880` has three; `0x0067a930` has six raw-wrapper refs.
- `find_bytes`: no stored little-endian VA matches for the six executable starts.
- `get_bytes`: table heads match AES constants, padding is `0xcc`, and the mutable state range reads as zero.
- `int_convert`: `0x10` = 16, `0x2c` = 44, `0xb0` = 176, `0xbc` = 188, `0x100` = 256, and `0x8d` = 141; conversions verified with MCP `int_convert`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Current Score | Recommended status |
| --- | --- | --- | --- | --- | --- | --- |
| file root | [UID:00020J] `by-file/AesBlockCipher.md` | source root | file root | `FILE` | `89/92` | `91/93`, generated output source-ready |
| state/tables aggregate | [UID:00020K] `by-global/AesBlockCipherStateAndTables.md` | shared declarations | TRUE | [UID:00020J] | `88/93` | `90/93`, position 2, non-empty C++ |
| `0x00461790-0x0046189b` | [UID:00020L] | CBC encrypt wrapper | TRUE | [UID:00020J] | `86/91` | `90/92`, position 50, non-empty C++ |
| `0x004618a0-0x004619b8` | [UID:00020M] | CBC decrypt wrapper | TRUE | [UID:00020J] | `86/91` | `90/92`, position 60, non-empty C++ |
| `0x004619c0-0x00461c07` | [UID:00020N] | block encrypt | TRUE | [UID:00020J] | `87/92` | `91/93`, position 30, non-empty C++ |
| `0x00461c10-0x00461dc7` | [UID:00020O] | block decrypt | TRUE | [UID:00020J] | `87/92` | `91/93`, position 40, non-empty C++ |
| `0x00461dd0-0x00461fd4` | [UID:00020P] | inverse MixColumns | TRUE | [UID:00020J] | `86/92` | `90/93`, position 10, non-empty C++ |
| `0x00461fe0-0x00462114` | [UID:00020Q] | key expansion | TRUE | [UID:00020J] | `87/92` | `91/93`, position 20, non-empty C++ |
| `0x00610fe8-0x006112e8` | [UID:0002JU] | read-only tables | TRUE | [UID:00020J] | `86/93` | `90/94`, position 1, non-empty C++ |
| `0x0067a878-0x0067a934` | [UID:00028Y] | mutable state | TRUE | [UID:00020J] | `87/92` | `90/93`, position 3, non-empty C++ |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00461790` | zero xrefs | raw encrypt entry retained without surviving direct call |
| `0x004618a0` | zero xrefs | raw decrypt entry retained without surviving direct call |
| `0x004619c0` | xrefs `0x0046183a`, `0x0046188f` | encrypt wrapper block calls |
| `0x00461c10` | xrefs `0x00461934`, `0x004619ac` | decrypt wrapper block calls |
| `0x00461dd0` | xref `0x00461d00` | decrypt block calls inverse MixColumns |
| `0x00461fe0` | xrefs `0x004617d0`, `0x004618e0` | wrappers call key expansion |

## Documentation Evidence And IDA Status

- Current docs already preserve most B002 evidence but stop short of source emission.
- Current generated output proves all nine child emitters are still empty.
- Manual coverage rows are stale: by-memory rows still show older scores and UID00028Y still says `all-0xff`.
- `by-project-structure/proposed-source-tree.md` already records loader-zeroed state and utility placement; no source-tree move is needed.

## Ranked Ownership Analysis

### 1. Existing [UID:00020J] `AesBlockCipher`

- Evidence for: exact proposed output path, all helper/table/state xrefs confined to the AES island, current owner/emitter route is valid, and no external owner signal exists.
- Evidence against: original source filename is not proven.
- Decision: keep owner/emitter.

### 2. Third-party static embed

- Evidence for: AES constants and round algorithms are standard.
- Evidence against: no staged AES source exists under `third_party_embeds`; no license/banner/source path/API signature matches; binary uses file-static scratch and raw retained wrappers.
- Decision: reject import for this pass.

### 3. Network/auth/archive/startup or class/context owner

- Evidence for: none beyond AES being commonly used by protocols/storage.
- Evidence against: no callers, strings, resources, object lifecycle, `this`, vtable, constructor, destructor, or context argument.
- Decision: reject.

## Source Placement

- Recommended source file: `NexusTK/util/AesBlockCipher.cpp`.
- Header exposure: none proven. Keep functions `static` unless later caller evidence proves a public API.
- Rejected placements: third-party embed, network/auth/archive/startup module, class source, and process-global owner.

## Range / Split / Padding / Reclassification Analysis

- Exact executable island: `0x00461790-0x00462114`.
- Padding: MCP reconfirmed `0xcc` padding at `0x0046178a-0x00461790`, `0x0046189b-0x004618a0`, `0x004619b8-0x004619c0`, `0x00461c07-0x00461c10`, `0x00461dc7-0x00461dd0`, `0x00461fd4-0x00461fe0`, and `0x00462114-0x00462120`.
- Data children: exact `.rdata` table island `0x00610fe8-0x006112e8` and exact `.data` static state `0x0067a878-0x0067a934`.
- No split/merge/rename is recommended.

## Negative Evidence Summary

- Consumer xrefs do not prove a subsystem owner; all consumers are inside AES.
- Standard AES constants do not prove a vendored source import.
- No live wrapper caller should be invented.
- Do not keep old blank-C++ text that says source must wait for another coordinated pass; this report provides the coordinated plan.

## IDA Rename / Type / Comment Recommendations

- Source-facing names to preserve: `AesBlockCipherState`, `s_aesSBox`, `s_aesInvSBox`, `s_aesRcon`, `s_aesState`, `AesInvMixColumns`, `AesExpandKey128`, `AesEncryptBlock`, `AesDecryptBlock`, `AesCbcEncryptBuffer`, and `AesCbcDecryptBuffer`.
- Do not expose IDA names `unk_67A878`, `unk_67A880`, `byte_610FE8`, `byte_6110E8`, or `byte_6111E8` in final source.
- IDA DB edits are not requested.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. Every child is `RECONSTRUCTABLE:TRUE`, has a non-dead-ended emitter route to [UID:00020J], and clears the active combined score gate.
- Third-party import directive: not applicable.
- Exact insertion policy: populate each formal `RECONSTRUCTION_CPP CODE` block with final-output-style source for that page only. The table block must contain the full 768 bytes read from MCP at `0x00610fe8`; the current full byte extraction was performed with MCP `get_bytes` JSON-RPC id `21`.
- Shared declaration block for [UID:00020K], emitted after the table block so the inline helpers can reference `s_aesSBox` and `s_aesInvSBox`:

```cpp
struct AesBlockCipherState
{
    unsigned char* currentBlock;
    const unsigned char* currentKey;
    unsigned char expandedKey[176];
    const unsigned char* cbcChain;
};

static unsigned char AesXtime(unsigned char value)
{
    return (unsigned char)((value << 1) ^ ((value & 0x80) ? 0x1b : 0x00));
}

static unsigned char AesMultiply(unsigned char value, unsigned char factor)
{
    unsigned char result = 0;

    while (factor != 0)
    {
        if ((factor & 1) != 0)
            result ^= value;

        value = AesXtime(value);
        factor >>= 1;
    }

    return result;
}

static void AesAddRoundKey(unsigned char* state, const unsigned char* roundKey)
{
    for (int i = 0; i < 16; ++i)
        state[i] ^= roundKey[i];
}

static void AesSubBytes(unsigned char* state)
{
    for (int i = 0; i < 16; ++i)
        state[i] = s_aesSBox[state[i]];
}

static void AesInvSubBytes(unsigned char* state)
{
    for (int i = 0; i < 16; ++i)
        state[i] = s_aesInvSBox[state[i]];
}

static void AesShiftRows(unsigned char* state)
{
    unsigned char temp;

    temp = state[1];
    state[1] = state[5];
    state[5] = state[9];
    state[9] = state[13];
    state[13] = temp;

    temp = state[2];
    state[2] = state[10];
    state[10] = temp;
    temp = state[6];
    state[6] = state[14];
    state[14] = temp;

    temp = state[15];
    state[15] = state[11];
    state[11] = state[7];
    state[7] = state[3];
    state[3] = temp;
}

static void AesInvShiftRows(unsigned char* state)
{
    unsigned char temp;

    temp = state[13];
    state[13] = state[9];
    state[9] = state[5];
    state[5] = state[1];
    state[1] = temp;

    temp = state[2];
    state[2] = state[10];
    state[10] = temp;
    temp = state[6];
    state[6] = state[14];
    state[14] = temp;

    temp = state[3];
    state[3] = state[7];
    state[7] = state[11];
    state[11] = state[15];
    state[15] = temp;
}

static void AesMixColumns(unsigned char* state)
{
    for (int column = 0; column < 4; ++column)
    {
        unsigned char* s = state + (column * 4);
        unsigned char a0 = s[0];
        unsigned char a1 = s[1];
        unsigned char a2 = s[2];
        unsigned char a3 = s[3];
        unsigned char mix = (unsigned char)(a0 ^ a1 ^ a2 ^ a3);

        s[0] ^= mix ^ AesXtime((unsigned char)(a0 ^ a1));
        s[1] ^= mix ^ AesXtime((unsigned char)(a1 ^ a2));
        s[2] ^= mix ^ AesXtime((unsigned char)(a2 ^ a3));
        s[3] ^= mix ^ AesXtime((unsigned char)(a3 ^ a0));
    }
}

static void AesInvMixColumns();
static void AesExpandKey128();
static void AesEncryptBlock();
static void AesDecryptBlock();
static void AesCbcEncryptBuffer(unsigned char* dst, unsigned char* src, unsigned int length,
                                const unsigned char* keyOrNull, const unsigned char* ivOrNull);
static void AesCbcDecryptBuffer(unsigned char* dst, const unsigned char* src, unsigned int length,
                                const unsigned char* keyOrNull, const unsigned char* ivOrNull);
```

- Table block for [UID:0002JU]: emit the exact byte declarations below. Preserve the leading Rcon sentinel `0x8d`.

```cpp
static const unsigned char s_aesSBox[256] =
{
    0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
    0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
    0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
    0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
    0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
    0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
    0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
    0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
    0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
    0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
    0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
    0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
    0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
    0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
    0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
    0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16
};

static const unsigned char s_aesInvSBox[256] =
{
    0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb,
    0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb,
    0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d, 0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e,
    0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2, 0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25,
    0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92,
    0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda, 0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84,
    0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a, 0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06,
    0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02, 0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b,
    0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea, 0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73,
    0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85, 0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e,
    0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89, 0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b,
    0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20, 0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4,
    0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31, 0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f,
    0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d, 0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef,
    0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0, 0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61,
    0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26, 0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d
};

static const unsigned char s_aesRcon[256] =
{
    0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a,
    0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39,
    0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a,
    0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8,
    0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef,
    0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc,
    0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b,
    0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3,
    0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94,
    0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20,
    0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35,
    0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f,
    0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04,
    0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63,
    0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd,
    0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb, 0x00
};
```
- State block for [UID:00028Y]:

```cpp
static AesBlockCipherState s_aesState;
```

- Helper/wrapper bodies: use these exact formal body shapes in the corresponding by-memory pages. They intentionally depend on the shared declarations/table/state blocks above and must remain `static` because no external caller is proven.

[UID:00020P] `AesInvMixColumns`:

```cpp
static void AesInvMixColumns()
{
    unsigned char* state = s_aesState.currentBlock;

    for (int column = 0; column < 4; ++column)
    {
        unsigned char* s = state + (column * 4);
        unsigned char a0 = s[0];
        unsigned char a1 = s[1];
        unsigned char a2 = s[2];
        unsigned char a3 = s[3];

        s[0] = (unsigned char)(AesMultiply(a0, 0x0e) ^ AesMultiply(a1, 0x0b) ^
                               AesMultiply(a2, 0x0d) ^ AesMultiply(a3, 0x09));
        s[1] = (unsigned char)(AesMultiply(a0, 0x09) ^ AesMultiply(a1, 0x0e) ^
                               AesMultiply(a2, 0x0b) ^ AesMultiply(a3, 0x0d));
        s[2] = (unsigned char)(AesMultiply(a0, 0x0d) ^ AesMultiply(a1, 0x09) ^
                               AesMultiply(a2, 0x0e) ^ AesMultiply(a3, 0x0b));
        s[3] = (unsigned char)(AesMultiply(a0, 0x0b) ^ AesMultiply(a1, 0x0d) ^
                               AesMultiply(a2, 0x09) ^ AesMultiply(a3, 0x0e));
    }
}
```

[UID:00020Q] `AesExpandKey128`:

```cpp
static void AesExpandKey128()
{
    for (int i = 0; i < 16; ++i)
        s_aesState.expandedKey[i] = s_aesState.currentKey[i];

    for (unsigned int word = 4; word < 44; ++word)
    {
        unsigned char temp[4];
        unsigned int previous = (word - 1) * 4;
        unsigned int source = (word - 4) * 4;
        unsigned int target = word * 4;

        temp[0] = s_aesState.expandedKey[previous + 0];
        temp[1] = s_aesState.expandedKey[previous + 1];
        temp[2] = s_aesState.expandedKey[previous + 2];
        temp[3] = s_aesState.expandedKey[previous + 3];

        if ((word & 3) == 0)
        {
            unsigned char rotated = temp[0];
            temp[0] = (unsigned char)(s_aesSBox[temp[1]] ^ s_aesRcon[word >> 2]);
            temp[1] = s_aesSBox[temp[2]];
            temp[2] = s_aesSBox[temp[3]];
            temp[3] = s_aesSBox[rotated];
        }

        s_aesState.expandedKey[target + 0] = (unsigned char)(s_aesState.expandedKey[source + 0] ^ temp[0]);
        s_aesState.expandedKey[target + 1] = (unsigned char)(s_aesState.expandedKey[source + 1] ^ temp[1]);
        s_aesState.expandedKey[target + 2] = (unsigned char)(s_aesState.expandedKey[source + 2] ^ temp[2]);
        s_aesState.expandedKey[target + 3] = (unsigned char)(s_aesState.expandedKey[source + 3] ^ temp[3]);
    }
}
```

[UID:00020N] `AesEncryptBlock`:

```cpp
static void AesEncryptBlock()
{
    unsigned char* state = s_aesState.currentBlock;

    AesAddRoundKey(state, s_aesState.expandedKey);

    for (int round = 1; round <= 9; ++round)
    {
        AesSubBytes(state);
        AesShiftRows(state);
        AesMixColumns(state);
        AesAddRoundKey(state, s_aesState.expandedKey + (round * 16));
    }

    AesSubBytes(state);
    AesShiftRows(state);
    AesAddRoundKey(state, s_aesState.expandedKey + 160);
}
```

[UID:00020O] `AesDecryptBlock`:

```cpp
static void AesDecryptBlock()
{
    unsigned char* state = s_aesState.currentBlock;

    AesAddRoundKey(state, s_aesState.expandedKey + 160);

    for (int round = 9; round >= 1; --round)
    {
        AesInvShiftRows(state);
        AesInvSubBytes(state);
        AesAddRoundKey(state, s_aesState.expandedKey + (round * 16));
        AesInvMixColumns();
    }

    AesInvShiftRows(state);
    AesInvSubBytes(state);
    AesAddRoundKey(state, s_aesState.expandedKey);
}
```

[UID:00020L] `AesCbcEncryptBuffer`:

```cpp
static void AesCbcEncryptBuffer(unsigned char* dst, unsigned char* src, unsigned int length,
                                const unsigned char* keyOrNull, const unsigned char* ivOrNull)
{
    unsigned char tail = (unsigned char)(length & 0x0f);

    for (int i = 0; i < 16; ++i)
        dst[i] = src[i];

    s_aesState.currentBlock = dst;

    if (keyOrNull != 0)
    {
        s_aesState.currentKey = keyOrNull;
        AesExpandKey128();
    }

    const unsigned char* chain = ivOrNull != 0 ? ivOrNull : s_aesState.cbcChain;
    s_aesState.cbcChain = chain;

    if (length != 0)
    {
        unsigned int blockCount = ((length - 1) >> 4) + 1;

        while (blockCount-- != 0)
        {
            for (int i = 0; i < 16; ++i)
                src[i] ^= chain[i];

            for (int i = 0; i < 16; ++i)
                dst[i] = src[i];

            s_aesState.currentBlock = dst;
            AesEncryptBlock();

            chain = dst;
            src += 16;
            dst += 16;
        }

        s_aesState.cbcChain = chain;
    }

    if (tail != 0)
    {
        for (int i = 0; i < 16; ++i)
            dst[i] = src[i];

        for (int i = tail; i < 16; ++i)
            dst[i] = 0;

        s_aesState.currentBlock = dst;
        AesEncryptBlock();
    }
}
```

[UID:00020M] `AesCbcDecryptBuffer`:

```cpp
static void AesCbcDecryptBuffer(unsigned char* dst, const unsigned char* src, unsigned int length,
                                const unsigned char* keyOrNull, const unsigned char* ivOrNull)
{
    unsigned char tail = (unsigned char)(length & 0x0f);

    for (int i = 0; i < 16; ++i)
        dst[i] = src[i];

    s_aesState.currentBlock = dst;

    if (keyOrNull != 0)
    {
        s_aesState.currentKey = keyOrNull;
        AesExpandKey128();
    }

    const unsigned char* chain = ivOrNull != 0 ? ivOrNull : s_aesState.cbcChain;
    s_aesState.cbcChain = chain;

    if (length != 0)
    {
        unsigned int blockCount = ((length - 1) >> 4) + 1;
        const unsigned char* previousCipher = src;

        while (blockCount-- != 0)
        {
            for (int i = 0; i < 16; ++i)
                dst[i] = src[i];

            s_aesState.currentBlock = dst;
            AesDecryptBlock();

            for (int i = 0; i < 16; ++i)
                dst[i] ^= chain[i];

            previousCipher = src;
            src += 16;
            dst += 16;
        }

        s_aesState.cbcChain = previousCipher;
    }

    if (tail != 0)
    {
        for (int i = 0; i < 16; ++i)
            dst[i] = src[i];

        for (int i = tail; i < 16; ++i)
            dst[i] = 0;

        s_aesState.currentBlock = dst;
        AesDecryptBlock();
    }
}
```

## Final Recommendation

- Apply coordinated formal C++ to all nine child emitters.
- Keep [UID:00020J] as root and keep `NexusTK/util/`.
- Keep all items reconstructable.
- Update scores as listed in the inventory.
- Fix stale UID00028Y all-`0xff` summary and manual coverage wording.
- Do not execute or archive this report until supervisor validation and implementation callback verification.

## Recommended Target Doc Changes

- `by-file/AesBlockCipher.md`: update status/source status from blank coordinated policy to source-ready coordinated implementation; raise to `91/93`; record MCP session `3fa0535f`; record no third-party import; record generated file currently stale with nine empty markers; preserve wrapper no-xref/literal-VA negative evidence.

## Recommended Support Doc Changes

- `by-memory/0x00610fe8-0x006112e8.AesReadOnlyTables.md`: raise to `90/94`, position `1`, add full table declarations from MCP bytes.
- `by-global/AesBlockCipherStateAndTables.md`: raise to `90/93`, position `2`, add formal shared declarations/prototypes/helper C++.
- `by-memory/0x0067a878-0x0067a934.AesMutableStateAndKeySchedule.md`: raise to `90/93`, position `3`, add `s_aesState`, fix stale `Item Summary`.
- `by-memory/0x00461dd0-0x00461fd4.AesInvMixColumns.md`: raise to `90/93`, position `10`, add function body.
- `by-memory/0x00461fe0-0x00462114.AesKeySchedule128.md`: raise to `91/93`, position `20`, add function body.
- `by-memory/0x004619c0-0x00461c07.AesEncryptBlock.md`: raise to `91/93`, position `30`, add function body.
- `by-memory/0x00461c10-0x00461dc7.AesDecryptBlock.md`: raise to `91/93`, position `40`, add function body.
- `by-memory/0x00461790-0x0046189b.AesCbcEncryptRaw.md`: raise to `90/92`, position `50`, add function body and exact tail caveat.
- `by-memory/0x004618a0-0x004619b8.AesCbcDecryptRaw.md`: raise to `90/92`, position `60`, add function body and exact tail caveat.

## Score And Metadata Recommendation

- Score movement is justified because the named C++ blocker is resolved into concrete source-ready placement/order/code responsibility.
- Scores stay below `95` because final compiler equivalence, exact original source spellings, and external API/liveness remain unproven.
- Owner/emitter metadata remains [UID:00020J] for children and `FILE` for root.

## Open Questions With Attempted Resolution

- Original source filename/API: unresolved, but current `AesBlockCipher.cpp` utility path remains best supported. This does not block first-draft static source because generated output already uses that root and no better owner exists.
- Wrapper liveness: unresolved why retained, but negative reachability is bounded and does not block reconstructing source-authored bodies.
- Third-party provenance: no staged source or exact source match found; no import is safe.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Manual `by-memory/-coverage-report.md` is out of report-only write scope. If supervisor includes manual coverage in a callback, replace the AES rows with the following text while preserving existing padding rows and nesting:

```markdown
    - [UID:00020L][0x00461790-0x0046189b.AesCbcEncryptRaw](by-memory/0x00461790-0x0046189b.AesCbcEncryptRaw.md) 0x00461790-0x0046189b | function | AesCbcEncryptRaw : reconstructable : 90% : very strong : Raw AES-CBC encrypt wrapper with no direct xrefs or literal VA references, retained source-authored body, file-static AES state, optional AES-128 key expansion, exact full-block CBC encrypt loop, extra post-loop zero-filled tail block for non-multiple lengths, owner/emitter [UID:00020J][AesBlockCipher](by-file/AesBlockCipher.md), and formal source emitted through the coordinated AesBlockCipher implementation.
    - [UID:00020M][0x004618a0-0x004619b8.AesCbcDecryptRaw](by-memory/0x004618a0-0x004619b8.AesCbcDecryptRaw.md) 0x004618a0-0x004619b8 | function | AesCbcDecryptRaw : reconstructable : 90% : very strong : Raw AES-CBC decrypt wrapper with no direct xrefs or literal VA references, retained source-authored body, file-static AES state, optional AES-128 key expansion, exact full-block CBC decrypt/XOR loop, extra post-loop zero-filled tail decrypt behavior, owner/emitter [UID:00020J][AesBlockCipher](by-file/AesBlockCipher.md), and formal source emitted through the coordinated AesBlockCipher implementation.
    - [UID:00020N][0x004619c0-0x00461c07.AesEncryptBlock](by-memory/0x004619c0-0x00461c07.AesEncryptBlock.md) 0x004619c0-0x00461c07 | function | AesEncryptBlock : reconstructable : 91% : very strong : AES-128 in-place block encrypt transform with raw-wrapper-only callers, initial/final AddRoundKey, nine full rounds, forward S-box refs, file-static expanded-key/current-block state, exact padding boundaries, owner/emitter [UID:00020J][AesBlockCipher](by-file/AesBlockCipher.md), and coordinated formal source present.
    - [UID:00020O][0x00461c10-0x00461dc7.AesDecryptBlock](by-memory/0x00461c10-0x00461dc7.AesDecryptBlock.md) 0x00461c10-0x00461dc7 | function | AesDecryptBlock : reconstructable : 91% : very strong : AES-128 in-place block decrypt transform with raw-wrapper-only callers, backward expanded-key refs, inverse S-box refs, sole inverse-MixColumns callee, file-static current-block state, exact padding boundaries, owner/emitter [UID:00020J][AesBlockCipher](by-file/AesBlockCipher.md), and coordinated formal source present.
    - [UID:00020P][0x00461dd0-0x00461fd4.AesInvMixColumns](by-memory/0x00461dd0-0x00461fd4.AesInvMixColumns.md) 0x00461dd0-0x00461fd4 | helper | AesInvMixColumns : reconstructable : 90% : very strong : Private AES inverse MixColumns helper called only by AesDecryptBlock, with arithmetic GF reduction using the AES polynomial, no callees, one current-state pointer ref, no table refs, exact padding boundaries, owner/emitter [UID:00020J][AesBlockCipher](by-file/AesBlockCipher.md), and coordinated formal source present.
    - [UID:00020Q][0x00461fe0-0x00462114.AesKeySchedule128](by-memory/0x00461fe0-0x00462114.AesKeySchedule128.md) 0x00461fe0-0x00462114 | helper | AesKeySchedule128 : reconstructable : 91% : very strong : AES-128 key expansion helper with raw-wrapper-only callers, 16-byte key copy, `0x2c` / 44-word schedule stop, forward S-box and Rcon refs, `0xb0` / 176-byte expanded-key output, exact padding boundaries, owner/emitter [UID:00020J][AesBlockCipher](by-file/AesBlockCipher.md), and coordinated formal source present.
        - [UID:0002JU][0x00610fe8-0x006112e8.AesReadOnlyTables](by-memory/0x00610fe8-0x006112e8.AesReadOnlyTables.md) 0x00610fe8-0x006112e8 | source-declared data | AesReadOnlyTables : reconstructable : 90% : very strong : AES forward S-box, inverse S-box, and Rcon table island with exact three `0x100`-byte `.rdata` subranges, head/tail byte checks, neighboring boundary evidence, AES-island-only consumers, source names `s_aesSBox`/`s_aesInvSBox`/`s_aesRcon`, owner/emitter [UID:00020J][AesBlockCipher](by-file/AesBlockCipher.md), and formal table declarations emitted.
    - [UID:00028Y][0x0067a878-0x0067a934.AesMutableStateAndKeySchedule](by-memory/0x0067a878-0x0067a934.AesMutableStateAndKeySchedule.md) 0x0067a878-0x0067a934 | AES mutable state | AesMutableStateAndKeySchedule : reconstructable : 90% : very strong : AES/CBC file-static mutable state modeled as `AesBlockCipherState` with current-block pointer, key pointer, `0xb0` / 176-byte expanded AES-128 key schedule, and chaining pointer; exact `0xbc` / 188-byte loader-zeroed `.data` range, xref-bounded AES-island confinement, owner/emitter [UID:00020J][AesBlockCipher](by-file/AesBlockCipher.md), and stale all-`0xff` initializer wording rejected.
```

Validator-owned generated reports should refresh through validators only.

## Follow-Up Actions

- Supervisor: validate this report; if accepted, send B012 implementation callback for the exact target/support pages only.
- B012 callback: lease only the named by-* docs immediately before editing, apply every accepted row, run scoped validators, verify generated C++ freshness and absence of the nine empty markers, update this report ledger/checklist, release leases.
- No A-agent follow-up is required before callback unless supervisor wants compiler testing outside B-agent scope.

## Confidence

- Recommendation confidence: high.
- Score confidence: medium-high.
- Remaining uncertainty: exact original names/API and binary-equivalent compiler output, not ownership or source-emission route.

## Validator Results

Implementation callback validators from `E:\NTK\GhidraBridge\source-3\project-documentation`; all used `--apply --queue-timeout 240 --wait-generated` and exited `0` with `ok: 1`.

| File | command_id | command_timestamp | exit | ok | generated_refresh |
| --- | --- | --- | --- | --- | --- |
| `by-file\AesBlockCipher.md` | `000000001201` | `2026-06-29T20:27:09-04:00` | `0` | `1` | completed, command `000000001201` |
| `by-memory\0x00610fe8-0x006112e8.AesReadOnlyTables.md` | `000000001202` | `2026-06-29T20:27:19-04:00` | `0` | `1` | completed, command `000000001202` |
| `by-global\AesBlockCipherStateAndTables.md` | `000000001203` | `2026-06-29T20:27:29-04:00` | `0` | `1` | completed, command `000000001203` |
| `by-memory\0x0067a878-0x0067a934.AesMutableStateAndKeySchedule.md` | `000000001204` | `2026-06-29T20:27:39-04:00` | `0` | `1` | completed, command `000000001204` |
| `by-memory\0x00461dd0-0x00461fd4.AesInvMixColumns.md` | `000000001205` | `2026-06-29T20:27:49-04:00` | `0` | `1` | completed, command `000000001205` |
| `by-memory\0x00461fe0-0x00462114.AesKeySchedule128.md` | `000000001206` | `2026-06-29T20:27:59-04:00` | `0` | `1` | completed, command `000000001206` |
| `by-memory\0x004619c0-0x00461c07.AesEncryptBlock.md` | `000000001207` | `2026-06-29T20:28:09-04:00` | `0` | `1` | completed, command `000000001207` |
| `by-memory\0x00461c10-0x00461dc7.AesDecryptBlock.md` | `000000001208` | `2026-06-29T20:28:18-04:00` | `0` | `1` | completed, command `000000001208` |
| `by-memory\0x00461790-0x0046189b.AesCbcEncryptRaw.md` | `000000001209` | `2026-06-29T20:28:28-04:00` | `0` | `1` | completed, command `000000001209` |
| `by-memory\0x004618a0-0x004619b8.AesCbcDecryptRaw.md` | `000000001210` | `2026-06-29T20:28:39-04:00` | `0` | `1` | completed, command `000000001210` |

Generated state checked read-only after validators: `auto-generated/NexusTK/util/AesBlockCipher.cpp` header `validator-command-id: 000000001210`, `validator-refreshed-at: 2026-06-29T20:28:39-04:00`. `rg` found no `Empty Emitter Marker` or `UID00020K`/`UID00020L`/`UID00020M`/`UID00020N`/`UID00020O`/`UID00020P`/`UID00020Q`/`UID0002JU`/`UID00028Y` empty-marker rows.

## Changed Files

- Modified: `by-file/AesBlockCipher.md`.
- Modified: `by-global/AesBlockCipherStateAndTables.md`.
- Modified: `by-memory/0x00610fe8-0x006112e8.AesReadOnlyTables.md`.
- Modified: `by-memory/0x0067a878-0x0067a934.AesMutableStateAndKeySchedule.md`.
- Modified: `by-memory/0x00461dd0-0x00461fd4.AesInvMixColumns.md`.
- Modified: `by-memory/0x00461fe0-0x00462114.AesKeySchedule128.md`.
- Modified: `by-memory/0x004619c0-0x00461c07.AesEncryptBlock.md`.
- Modified: `by-memory/0x00461c10-0x00461dc7.AesDecryptBlock.md`.
- Modified: `by-memory/0x00461790-0x0046189b.AesCbcEncryptRaw.md`.
- Modified: `by-memory/0x004618a0-0x004619b8.AesCbcDecryptRaw.md`.
- Modified: `tools/leaser/Agents/Agent-B012/research/00020J-AesBlockCipher-empty-emitter-family-source-quality.md`.
- Validator-owned/generated side effects: `auto-generated/NexusTK/util/AesBlockCipher.cpp`, generated metadata/coverage/tracker refreshes, and validator-owned state refreshes were produced by scoped validators, not manual edits.
- Leases: B012 successfully leased the ten by-* docs before editing; the validator batch exceeded the active lease window, and cleanup `unlease` returned `Rejected[No active lease]` for each AES path. `tools/leaser/Agents/current_leases.md` then showed no active leases.
- Report execution: not performed; supervisor owns execution after verification.

## Implementation Tracking Checklist

Implementation callback:
- [x] Supervisor validation required before implementation. Proof: current `goal.md` converted this accepted report to implementation callback mode.
- [x] Target/support docs to update: [UID:00020J], [UID:00020K], [UID:00020L], [UID:00020M], [UID:00020N], [UID:00020O], [UID:00020P], [UID:00020Q], [UID:0002JU], and [UID:00028Y]. Proof: all ten listed by-* docs modified and validated.
- [x] Current target state and actual evidence checked recorded: MCP session `3fa0535f`, generated header `000000001133`, B002 executed report, current by-* docs, manual/generated coverage, and third-party searches. Proof: retained in Evidence Checked; no fresh MCP was required during callback.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim. Proof: C01-C09 and C11 marked `applied`; C10 marked `excluded-with-reason` because manual coverage edits are supervisor-owned and explicitly out of scope.
- [x] Metadata/score changes to apply: scores and emitter positions in the Function / Child Inventory. Proof: docs now show [UID:00020J] `91/93`; [UID:0002JU] `90/94` pos `1`; [UID:00020K] `90/93` pos `2`; [UID:00028Y] `90/93` pos `3`; [UID:00020P] `90/93` pos `10`; [UID:00020Q] `91/93` pos `20`; [UID:00020N] `91/93` pos `30`; [UID:00020O] `91/93` pos `40`; [UID:00020L] `90/92` pos `50`; [UID:00020M] `90/92` pos `60`.
- [x] Score-limiting blocker resolved: coordinated blank-C++ blocker converted into ordered source-ready emitter plan. Proof: generated C++ now contains table/state/helper/wrapper code and no AES empty markers.
- [x] Owner/emitter/reconstructable changes to apply: keep owners/emitters/reconstructable; add only `EMITTER_POSITION_OPTIONAL` values. Proof: owners/emitters retained; positions added as accepted.
- [x] Split/rename/new-child changes to apply: none. Proof: no new by-* files created and no target rename/split applied.
- [x] Source-placement/range/padding/reclassification changes to apply: preserve `NexusTK/util/`, exact ranges, and padding; no reclassification. Proof: [UID:00020J] retains `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/"`; range docs preserved.
- [x] First-draft C++ to apply: shared [UID:00020K] declarations, [UID:0002JU] tables, [UID:00028Y] state, and six helper/wrapper bodies. Proof: all formal `RECONSTRUCTION_CPP CODE` blocks populated and generated into `auto-generated/NexusTK/util/AesBlockCipher.cpp`.
- [x] Third-party import directive to apply or confirm not applicable: not applicable; no staged AES source under `third_party_embeds`. Proof: no import directive inserted; direct source declarations retained.
- [x] Exact target/support doc facts to incorporate: all ledger claims C01-C11. Proof: ledger rows updated with destinations/proof; only C10 excluded because callback forbade manual coverage edits.
- [x] Historical/stale assumptions to preserve/reject: reject stale UID00028Y `all-0xff` summary/coverage wording; preserve no-xref/no-literal-VA wrapper liveness caveat. Proof: UID00028Y Item Summary now says loader-zeroed/current-zero; historical all-`0xff` notes are explicitly superseded; wrapper liveness caveats retained.
- [x] Wave2/Wave3 artifacts encountered and ignored/rejected as stale: generated reports used only as current state, not source authority. Proof: no Wave2/Wave3 content incorporated as authority.
- [x] Open questions to close or document: original source spelling/API and wrapper retention reason remain evidence-backed unresolved, not blockers. Proof: [UID:00020J] Evidence-Bounded Remaining Questions retained these as final-audit caveats.
- [x] Validators to run after callback edits: one scoped file validator per changed by-* doc with `--apply --queue-timeout 240 --wait-generated`. Proof: validator commands `000000001201` through `000000001210`, all exit `0`, `ok:1`.
- [x] Generated report refresh expected: generated C++ should refresh to a newer command id than `000000001133` and should contain no `Empty Emitter Marker` for the nine AES UIDs. Proof: generated header `000000001210` at `2026-06-29T20:28:39-04:00`; empty-marker search found no AES UID rows.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B012","command_id":"000000004165","destination_path":"executed-b-agent-research/B012/00020J-AesBlockCipher-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B012/research/00020J-AesBlockCipher-empty-emitter-family-source-quality.md","timestamp":"2026-06-29T21:00:23","uid":"00020J"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
