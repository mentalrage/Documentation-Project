*** UID:00020K | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00020J | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00020J | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
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
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# AesBlockCipherStateAndTables

## Status

- Confidence: very strong for AES table identity, local helper usage, and file-static mutable state layout.
- Symbol kind: AES lookup tables plus file-static AES/CBC mutable state.
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

Best current source-facing layout:

```cpp
struct AesBlockCipherState
{
    unsigned char* currentBlock;
    const unsigned char* currentKey;
    unsigned char expandedKey[176];
    const unsigned char* cbcChain;
};
```

This is a file-static utility state model, not a public class/object model and not independent product-global state. The 2026-06-17 B002 pass rejected a class/context owner because there is no `this` pointer, vtable, constructor/destructor, object allocation, or external context argument.

## Xref Summary

- `0x00610fe8` has reads from the encrypt block transform and the key expansion helper.
- `0x006110e8` has reads from the decrypt block transform.
- `0x006111e8` has a read from the key expansion helper.
- `0x0067a878`, `0x0067a87c`, and `0x0067a930` are used only by the AES helper island in current IDA xrefs.
- 2026-06-05 IDA MCP byte reads confirm exact `0x100` `.rdata` tables at `0x00610fe8-0x006110e8`, `0x006110e8-0x006111e8`, and `0x006111e8-0x006112e8`, including head/tail bytes and non-AES neighboring data before/after the table island.
- 2026-06-14 IDA MCP byte reads confirm exact `.data` mutable storage at `0x0067a878-0x0067a934`, currently zero-filled; adjacent bytes are not a unique delimiter, so the documented subrange is bounded by xrefs rather than a byte pattern.
- 2026-06-05 IDA MCP xrefs confirm raw wrappers write `0x0067a878`, `0x0067a87c`, and `0x0067a930`; `AesKeySchedule128` consumes the key pointer and writes the initial key into `0x0067a880-0x0067a88f`; encrypt/decrypt transforms consume expanded-key offsets through `0x0067a920`.
- 2026-05-31 IDA MCP xrefs show the forward S-box read by `sub_4619C0` at `0x00461a26`/`0x00461b76` and by `sub_461FE0` at `0x004620a7`, `0x004620b4`, `0x004620c1`, and `0x004620d5`; the inverse S-box read by `sub_461C10` at `0x00461cc6`/`0x00461d86`; and Rcon read by `sub_461FE0` at `0x004620cf`.
- 2026-06-14 live IDA MCP xref refresh reconfirmed the table/state access sets: `0x0067a878` has 10 AES-helper refs, `0x0067a87c` has three refs, `0x0067a880`/`0x0067a920` are schedule heads/tail refs, `0x0067a930` has six raw-wrapper refs, and the three read-only table heads have 6/2/1 refs.
- Corrected 2026-06-14 raw PE section-offset checking places `0x0067a878-0x0067a934` past the initialized `.data` raw payload. Treat the storage as loader-zeroed BSS/static state that is overwritten by runtime wrapper/key-schedule state, not as a source-authored `0xff` initializer. IDA signature output may render that unbacked virtual tail as `FF`, so the rebuild-relevant fact is the xref-bounded static storage role rather than a hard-coded initializer byte pattern.

## Reconstruction Notes

The source reconstruction should avoid exposing these generated-style names. Prefer local static arrays named `s_aesSBox`, `s_aesInvSBox`, and `s_aesRcon`, plus a private file-static `AesBlockCipherState` for the mutable storage.

This page now emits the shared file-level `AesBlockCipherState`, GF arithmetic helpers, round helpers, and forward declarations at emitter position `2`, after the read-only table declarations and before the file-static mutable state. The block deliberately remains private/static source support for [UID:00020J][AesBlockCipher](by-file/AesBlockCipher.md), not an externally exposed product global API.

## Rule 26 Incorporated B002 Research

- The read-only tables are AES-specific, not broad Rijndael placeholders: table heads/tails, 16-byte blocks, 10 rounds, 44 schedule words, and 176 expanded-key bytes match AES-128.
- `s_aesSBox`, `s_aesInvSBox`, and `s_aesRcon` are the preferred source-facing table names. `byte_610FE8`, `dword_67A880`, and similar generated names are evidence handles only.
- The mutable `.data` span is loader-zeroed/file-static AES state. Earlier all-`0xff` wording is historical and superseded by the raw PE and live IDA zero-fill checks.
- The state/table owner remains [UID:00020J][AesBlockCipher](by-file/AesBlockCipher.md) because xrefs are confined to the AES helper island and there is no caller, resource, protocol, class, or storage evidence tying the data to another subsystem.

## Score Rationale

Completion is raised to 90 because this global page now has exact split child pages for both read-only and mutable data, fresh table byte verification, refreshed 10/3/3/2/6 mutable-state xref sets, corrected PE zero-fill versus IDA `FF` placeholder handling for the virtual `.data` tail, file-static `AesBlockCipherState` modeling, source-facing table names, rejected class/context/product-global alternatives, and first-draft shared formal C++ at emitter position `2`. Confidence stays at 93 because the AES table identities, helper confinement, zero-fill correction, and owner/emitter route all agree across IDA and local PE evidence; it remains below final-audit levels because original source names and provenance are still not proven.

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

- 2026-06-05: Raised completion/confidence to `84/92` after refreshing both AES data child pages. Summary/evidence: IDA MCP confirmed exact `0x100` table splits, table head/tail bytes, neighboring `.rdata` boundaries, exact `0xbc` mutable-state span, xref-bounded mutable range rationale, and AES-island-only pointer/table/schedule refs; C++ remains blank below the final-code threshold.
- 2026-06-14 A001 Goal 2 AES mutable-state correction: score remains `84/92`. Summary/evidence: live IDA MCP and raw section-offset sanity checks supersede the earlier all-`0xff` initializer note for [UID:00028Y][0x0067a878-0x0067a934.AesMutableStateAndKeySchedule](by-memory/0x0067a878-0x0067a934.AesMutableStateAndKeySchedule.md); current bytes are zero-filled while the exact `0xbc` xref-bounded AES helper-island storage interpretation remains unchanged.
- 2026-06-14 A002 Goal 2 by-global score pass: raised from `84/92` to `86/93`. Summary/evidence: live IDA MCP reconfirmed the AES table/state xref sets, and corrected local PE section mapping distinguishes the loader-zeroed `.data` tail from IDA `FF` placeholder/signature rendering. Owner and emitter remain [UID:00020J][AesBlockCipher](by-file/AesBlockCipher.md); final C++ remains blank until the source-facing static/context storage shape is resolved.
- 2026-06-17 B002 Rule 26 source-quality incorporation: raised completion to `88` with confidence `93`. Summary/evidence: B002 resolved the preferred file-static `AesBlockCipherState` model, source-facing `s_aesSBox`/`s_aesInvSBox`/`s_aesRcon` names, AES-128-only interpretation, rejected class/context/product-global alternatives, and preserved blank C++ until a coordinated [UID:00020J][AesBlockCipher](by-file/AesBlockCipher.md) file-level AES implementation is accepted.
- 2026-06-29 B012 UID00020J implementation callback: raised completion to `90`, set `EMITTER_POSITION_OPTIONAL:2`, and populated formal C++ with the accepted shared `AesBlockCipherState`, GF helpers, round helpers, and private helper/wrapper prototypes. Summary/evidence: accepted report `00020J-AesBlockCipher-empty-emitter-family-source-quality.md` requires this block to emit after [UID:0002JU][0x00610fe8-0x006112e8.AesReadOnlyTables](by-memory/0x00610fe8-0x006112e8.AesReadOnlyTables.md) table declarations and before [UID:00028Y][0x0067a878-0x0067a934.AesMutableStateAndKeySchedule](by-memory/0x0067a878-0x0067a934.AesMutableStateAndKeySchedule.md) state storage.
