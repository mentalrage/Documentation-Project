** TARGET-REPORT-UID:00019T **
** AUTHOR-AGENT-ID:B013 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B013 B-Report: 00019T ProfileLoadAndLegacyImport Source Quality

## Assignment

- UID: `00019T`
- Target: `source-3/project-documentation/by-memory/0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B013/research/00019T-ProfileLoadAndLegacyImport-source-quality.md`
- Scope: B-agent report only. I did not edit target docs, support docs, or `by-memory/-coverage-report.md`.
- Prior reports preserved: `00013E`, `00015H`, and `00018U` were not moved or modified.

## Executive Recommendation

`00019T` should stay reconstructable, attached to [UID:0000MS] `ProfileStorage`, and emitted through `auto-generated/NexusTK/profile/ProfileStorage.cpp`. The stale "blank until 95/95 final-source gate" rationale should be replaced with the current 85/85 gate analysis: the child is already average-gate eligible (`84/90`, average `87`), and the source-quality pass closes enough field/helper/signature blockers to raise the target to `88/90`.

Recommended target metadata:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MS | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MS | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Recommended source-facing function signatures:

```cpp
namespace ProfileStorage {
namespace {
void ImportLegacyUserProfileData();
}

void LoadUserProfileData();
}
```

Rationale:

- `ImportLegacyUserProfileData` is called only from `LoadUserProfileData`; it should be file-local/static in `ProfileStorage.cpp`.
- Both functions obtain the current local user id internally through `0x005a2da0` / `GetLocalPlayerName`, so neither needs a source-level `const wchar_t *userId` parameter.
- IDA's `int()` return guess for `0x004f9280` is a tail-return artifact from `_wfopen` / `DeleteFileW`; the only caller ignores it, and Ghidra decompiles the body as `void`.
- IDA's `void __fastcall(unsigned int)` guess for `0x004f95b0` is a caller/SEH artifact. The decompile stores the apparent argument into a local that is later reused as loop state, while the path stem still comes from `GetLocalPlayerName_5A2DA0`. Ghidra decompiles the loader as no-argument `void`.
- A direct aggregate C++ emission is appropriate. This page contains exactly two same-owner functions plus `0xcc` padding between them. Child splitting into `0x004f9280-0x004f95a2` and `0x004f95b0-0x004f9d28` is optional if the supervisor wants per-function doc pages later, but it is not required for source routing or code emission.

## Evidence Checked

Required process docs:

- `tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md`
- `tools/leaser/Agents/Agent-B013/goal.md`
- `by-structure.md`
- `by-project-structure/proposed-source-tree.md`
- `inference_research.md`

Target and profile support docs:

- `by-memory/0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport.md`
- `by-file/ProfileStorage.md`
- `by-meta/client_profile_storage.md`
- `by-type/by-struct/RegistryConfigUserProfileBlock.md`
- `by-type/by-struct/MacroHotkeyRecord.md`
- `by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md`
- `by-memory/0x005063e0-0x00506962.ProfileSidecarRefresh.md`
- `by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md`
- `by-memory/0x0048ebc0-0x0048eecf.RegistryConfigInitializeUserDataDefaults.md`
- `by-memory/0x0048e480-0x0048f3f1.ConfigAndRegistryDefaults.md`
- `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`
- `by-memory/0x0069bee0-0x0069bf20.LocalPlayerNameWideBuffer.md`
- `by-global/WideApiDispatchTable.md`
- `by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md`
- `by-memory/0x004236e0-0x00423710.WideFormatWrapper.md`
- `by-memory/0x005829f0-0x00582d80.StringBaseShareAssignAndAccess.md`
- `by-memory/0x005832f0-0x00583714.StringBaseReleaseAndCapacity.md`
- `by-memory/0x00584160-0x005845af.StringBaseAppendAndFind.md`
- `by-memory/0x005845f0-0x0058490f.StringBaseWideSearchHelpers.md`
- `by-memory/0x0049cc40-0x0049ce48.SimpleUStringVectorGrowAndInsert.md`
- `by-type/by-struct/SimpleUStringVectorLayout.md`
- `by-memory/0x00584910-0x0058498b.SimpleUStringVectorPushBack.md`
- `by-memory/0x005b68c0-0x005b7354.BlockListenInputPanes.md`

Raw export facts checked:

- `resources/exported_data/functions/0x004f9280.json`
  - IDA name `sub_4F9280`, size `802` / `0x322`.
  - IDA signature guess `int()`, Ghidra signature `undefined __stdcall FUN_004f9280(void)`.
  - One IDA caller: `0x004f974a` in `sub_4F95B0`.
  - Callees: `0x005a2da0`, `_wcscat_s`, `_wcscpy_s`, `0x00582d20`, `_fclose`, stack cookie, range-check failure.
- `resources/exported_data/functions/0x004f95b0.json`
  - IDA name `sub_4F95B0`, size `1912` / `0x778`.
  - IDA signature guess `void __fastcall(unsigned int)`, Ghidra signature `undefined __stdcall FUN_004f95b0(void)`.
  - One IDA caller: `0x004f8a83` in `sub_4F7D10` / `InitializeMainUiGraph`.
  - Callees include `RegistryConfig::InitializeUserDataDefaults` at `0x0048ebc0`, `SHGetFolderPathW`, `GetLastError`, `GetLocalPlayerName_5A2DA0`, StringBase/SimpleUString helpers, `ImportLegacyUserProfileData`, `_fread`, `_fgetwc`, `SimpleUStringVector::GrowAndInsert`, and `_fclose`.
- `resources/exported_data/functions/0x0041a280.json`
  - Confirms platform dispatch slots used here:
    - `dword_69BE14 = _wfopen`
    - `dword_69BE1C = ReadUtf16CodeUnitFromFile` via `sub_599570`
    - `dword_69BE5C = CreateDirectoryW`
    - `dword_69BE60 = DeleteFileW`
    - `dword_69BE70 = GetCurrentDirectoryW`

Prior B-agent report cross-check:

- `Agent-B002/research/executed/00012G-simple-ustring-vector-grow-insert-source-quality.md` confirms `0x004f997d` in `LoadUserProfileData` is a consumer of `SimpleUStringVector::GrowAndInsert`, not ProfileStorage-owned vector infrastructure.

Operational checks:

- IDA MCP endpoint `http://127.0.0.1:13337/mcp`: unavailable, `Unable to connect to the remote server`.
- Validator baseline:

_Executable command block removed from the research report; preserved in [00019T-ProfileLoadAndLegacyImport-source-quality-removed.md](00019T-ProfileLoadAndLegacyImport-source-quality-removed.md)._

Result:

```text
ok           00019T by-memory/0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport.md UID header exists
stats_incremental_skip 00019T project-level/-auto-completion-stats.md dry run; pass --apply to update generated stats rows
```

## Function Findings

### `ImportLegacyUserProfileData`

Best source-facing identity:

```cpp
static void ImportLegacyUserProfileData();
```

Behavior:

- Builds the legacy path from the process current directory:

```text
<current-directory>\users\<local-player-name>.cfg
```

- The local player/user id is copied by `0x005a2da0` from [UID:0002AA] `LocalPlayerNameWideBuffer`.
- The open path uses `dword_69BE14` / `_wfopen` with `L"rb"`.
- The quoted-string reader uses `dword_69BE1C`, now documented as `ReadUtf16CodeUnitFromFile`.
- It imports only the legacy prefix:
  - ten quoted strings into `g_pConfig + 0x28de9c + i * 0x100`;
  - ten quoted strings into `g_pConfig + 0x28e89c + i * 0x100`;
  - twenty quoted strings into `SimpleUString` handles at `g_pConfig + 0x2911e0 + i * 4` through `0x00582d20` raw wide assignment;
  - one quoted string into `g_pConfig + 0x2912b8`, with a defensive terminator at character index `0xff` when the legacy text reaches `0x100` chars.
- It closes the file and deletes the legacy `.cfg` through `dword_69BE60` / `DeleteFileW`.
- If the file does not open, it returns without changing state. Since `LoadUserProfileData` has already reset defaults, this leaves default profile data.

Source-quality caveat:

- The decompiler shows a returned delete/open result, but no caller consumes it. Treat the function as `void` unless a future live disassembly/prototype pass proves a real source API used the return.

### `LoadUserProfileData`

Best source-facing identity:

```cpp
void LoadUserProfileData();
```

Behavior:

- Calls `RegistryConfig::InitializeUserDataDefaults(g_pConfig)` first.
- Calls `SHGetFolderPathW(NULL, CSIDL_PERSONAL, NULL, 0, documentsPath)`.
- If `SHGetFolderPathW` fails, the function returns with defaults. It does not attempt the current-directory `.usr` fallback or legacy `.cfg` import in that path.
- It formats and creates/checks:

```text
%s\NexusTK
%s\NexusTK\users
```

where `%s` is the Documents path. `CreateDirectoryW` failure is accepted only when `GetLastError() == ERROR_ALREADY_EXISTS` / `183`.

- It gets the local player/user id through `0x005a2da0`, not from a caller parameter.
- It first opens:

```text
Documents\NexusTK\users/<local-player-name>.usr
```

- If that open fails, it calls `GetCurrentDirectoryW` and tries:

```text
<current-directory>/users/<local-player-name>.usr
```

- If both modern `.usr` opens fail, it calls `ImportLegacyUserProfileData()` and returns after cleaning up the temporary `SimpleUString`.

Modern `.usr` loader sections:

| Order | Read shape | Field recommendation | Notes |
| --- | --- | --- | --- |
| 1 | `uint16 length` + UTF-16 text, 10 times | `m_profileTextSlots[10][0x80]` at `+0x28de9c` | Length must be `<= 0x7f`; writes terminator. |
| 2 | one UTF-16 char, 10 times | `m_legacyShortcutText[10][0x80]` at `+0x28e89c` | Writes char then terminator per slot. |
| 3 | `uint16 length` + UTF-16 string-object text, 20 times | `m_profileStringSlots[20]` at `+0x2911e0` | Uses StringBase length/capacity helpers and locks writable buffer. |
| 4 | `uint16 length` + UTF-16 text | `m_selectedProfileName[0x100]` at `+0x2912b8` | Packet text for profile opcode `79`; not the sidecar filename stem. |
| 5 | optional `uint32 count`, then `uint32 length` + text entries | `m_blockListenNames` vector at `+0x2918fc/+0x291900/+0x291904` | Clears existing vector, appends each entry through `SimpleUStringVector::GrowAndInsert` as needed. |
| 6 | optional `uint32 present`, then 20 pairs of UTF-16 chars | `m_compactShortcutRecords[20]` at `+0x28f29c` | First char is code point; second char `S` sets mode byte true, otherwise inventory mode. |
| 7 | optional `uint32 count`, then macro rows | `m_macroHotkeys[30]` at `+0x28f2ec` | Type `T` -> state `1`; `S` -> state `2`; `I` -> state `3`; unknown leaves default state from `InitializeUserDataDefaults`. |
| 8 | optional `uint32 count`, then two UTF-16 boolean chars per row | `m_targetOptionRows[2]` at `+0x2911dc` | Stores byte booleans from `L'1'`; current config docs tie these rows to ARROW and SHIFT+ARROW target options. |

Post-load migration:

- Legacy shortcut slots `m_legacyShortcutText[0..9][0]` move into the first ten compact shortcut records, set mode byte `1`, and clear the old slot.
- Every nonzero compact shortcut record among the 20 entries is promoted to the corresponding `MacroHotkeyRecord`.
- Promotion writes the code point into the macro row payload at row offset `+8`, writes a terminator, sets state `2` when compact mode byte is `1`, otherwise state `3`, and clears the compact code point.
- This proves the compact shortcut section is a compatibility layer; final runtime dispatch uses the 30-row `MacroHotkeyRecord` table.

## Ownership And Dependency Boundaries

Keep source ownership in `profile/ProfileStorage.cpp`.

`ProfileStorage` owns:

- path construction for profile data;
- modern `.usr` open/read behavior;
- legacy `.cfg` import/delete behavior;
- file-format compatibility migration;
- routing to shared string/vector/platform helpers.

`RegistryConfig` owns:

- declaration and defaulting of the profile/settings slice;
- `RegistryConfig::InitializeUserDataDefaults` at `0x0048ebc0`;
- the `MacroHotkeyRecord` storage defaults and adjacent config fields.

`Config` owns:

- `g_pConfig` lifetime/global pointer publication through the base/derived config object model.

`PlatformApi` / `WideApiDispatchTable` owns:

- `_wfopen`, `ReadUtf16CodeUnitFromFile`, `CreateDirectoryW`, `DeleteFileW`, and `GetCurrentDirectoryW` dispatch slots. These must not be emitted as ProfileStorage globals.

`StringBase`, `SimpleUString`, and `SimpleUStringVector` own:

- pointer-backed UTF-16 string handle initialization, assignment, data access, formatting, length/capacity updates, vector growth, and vector append. ProfileStorage is only a caller/consumer.

## Field And Helper Name Recommendations

Recommended `RegistryConfig` profile slice names for first-draft source:

| Offset | Recommended source-facing role name |
| --- | --- |
| `+0x28de9c` | `m_profileTextSlots[10][0x80]` |
| `+0x28e89c` | `m_legacyShortcutText[10][0x80]` |
| `+0x28f29c` | `m_compactShortcutRecords[20]` |
| `+0x28f2ec` | `m_macroHotkeys[30]` |
| `+0x2911dc` | `m_targetOptionRows[2]` |
| `+0x2911e0` | `m_profileStringSlots[20]` |
| `+0x2912b8` | `m_selectedProfileName[0x100]` |
| `+0x2918fc/+0x291900/+0x291904` | `m_blockListenNames` |

Recommended helper names:

| Address / slot | Recommended name | Owner |
| --- | --- | --- |
| `0x005a2da0` | `GetLocalPlayerName(wchar_t *dst, size_t cch)` | UserPane/local-player support |
| `0x004236e0` | `FormatWidePath260` / existing `WideFormatWrapper` | StringUtil |
| `0x00582b20` | `StringBase::InitEmptyWide` | StringBase |
| `0x00582d20` | `StringBase::AssignWideCString` | StringBase |
| `0x005835c0` | `StringBase::SetLengthWideAndDetach` | StringBase |
| `0x00584040` | `StringBase::LockWideBuffer` | StringBase |
| `0x00583700` | `SimpleUString::Format` / wide varargs forwarder | StringBase/SimpleUString |
| `0x00584540` | `SimpleUString::c_str` / `GetStringDataPointer` | StringBase |
| `0x0049cc40` | `SimpleUStringVector::GrowAndInsert` | SimpleUStringVector |
| `dword_69BE14` | `g_pfnWideOpenFile` / `_wfopen` | PlatformApi |
| `dword_69BE1C` | `g_pfnReadUtf16CodeUnitFromFile` | PlatformApi |
| `dword_69BE5C` | `g_pfnCreateDirectoryW` | PlatformApi |
| `dword_69BE60` | `g_pfnDeleteFileW` | PlatformApi |
| `dword_69BE70` | `g_pfnGetCurrentDirectoryW` | PlatformApi |

## First-Draft Source-Style C++

This is ready for target implementation as first-draft source, subject to a fresh validator/live-IDA callback. It intentionally uses named config fields and shared helper abstractions rather than raw offsets.

```cpp
namespace ProfileStorage {
namespace {

constexpr unsigned int kLocalPlayerNameCch = 0x28;
constexpr unsigned int kLegacyPathCch = 0x80;
constexpr unsigned int kProfilePathCch = 0x104;
constexpr unsigned int kFixedProfileSlotCount = 10;
constexpr unsigned int kFixedProfileSlotCch = 0x80;
constexpr unsigned int kProfileStringSlotCount = 20;
constexpr unsigned int kSelectedProfileCch = 0x100;
constexpr unsigned int kCompactShortcutCount = 20;
constexpr unsigned int kMacroHotkeyCount = 30;
constexpr unsigned int kMacroPayloadCch = 0x80;
constexpr unsigned int kTargetOptionRowCount = 2;

void ReadLegacyQuotedWideString(FILE* file, wchar_t* out, size_t outCch)
{
    wchar_t scratch[512];
    unsigned short count = 0;
    unsigned int index = 0;

    int ch;
    do {
        ch = g_pfnReadUtf16CodeUnitFromFile(file);
    } while (ch != L'"' && ch != WEOF);

    for (;;) {
        ch = g_pfnReadUtf16CodeUnitFromFile(file);
        index = count;
        scratch[index] = static_cast<wchar_t>(ch);
        if (ch == L'"' || ch == WEOF) {
            break;
        }
        ++count;
    }

    if (index >= 512) {
        __report_rangecheckfailure(index * sizeof(wchar_t));
    }

    scratch[count] = L'\0';
    if (outCch == kSelectedProfileCch && count >= kSelectedProfileCch) {
        scratch[kSelectedProfileCch - 1] = L'\0';
    }
    wcscpy_s(out, outCch, scratch);
}

void ImportLegacyUserProfileData()
{
    wchar_t path[kLegacyPathCch];
    wchar_t userId[kLocalPlayerNameCch];

    g_pfnGetCurrentDirectoryW(kLegacyPathCch, path);
    GetLocalPlayerName(userId, kLocalPlayerNameCch);
    wcscat_s(path, kLegacyPathCch, L"\\users\\");
    wcscat_s(path, kLegacyPathCch, userId);
    wcscat_s(path, kLegacyPathCch, L".cfg");

    FILE* file = g_pfnWideOpenFile(path, L"rb");
    if (file == nullptr) {
        return;
    }

    RegistryConfig& cfg = *g_pConfig;
    for (unsigned int i = 0; i < kFixedProfileSlotCount; ++i) {
        ReadLegacyQuotedWideString(file, cfg.m_profileTextSlots[i], kFixedProfileSlotCch);
    }
    for (unsigned int i = 0; i < kFixedProfileSlotCount; ++i) {
        ReadLegacyQuotedWideString(file, cfg.m_legacyShortcutText[i], kFixedProfileSlotCch);
    }
    for (unsigned int i = 0; i < kProfileStringSlotCount; ++i) {
        wchar_t scratch[512];
        ReadLegacyQuotedWideString(file, scratch, _countof(scratch));
        cfg.m_profileStringSlots[i].AssignWideCString(scratch);
    }

    ReadLegacyQuotedWideString(file, cfg.m_selectedProfileName, kSelectedProfileCch);

    fclose(file);
    g_pfnDeleteFileW(path);
}

bool EnsureDirectoryExists(const wchar_t* path)
{
    if (g_pfnCreateDirectoryW(path, nullptr)) {
        return true;
    }
    return GetLastError() == ERROR_ALREADY_EXISTS;
}

bool ReadLengthPrefixedWide(FILE* file, wchar_t* out, size_t outCch, unsigned int maxChars)
{
    unsigned short length = 0;
    fread(&length, sizeof(length), 1, file);
    if (length > maxChars) {
        return false;
    }
    fread(out, sizeof(wchar_t), length, file);
    out[length] = L'\0';
    return true;
}

void ReadProfileStringSlot(FILE* file, SimpleUString& out)
{
    unsigned short length = 0;
    fread(&length, sizeof(length), 1, file);
    out.Remove(0, npos);
    wchar_t* buffer = out.SetLengthWideAndDetach(length);
    fread(buffer, sizeof(wchar_t), length, file);
    out.LockWideBuffer();
}

void MigrateLegacyShortcuts(RegistryConfig& cfg)
{
    for (unsigned int i = 0; i < kFixedProfileSlotCount; ++i) {
        const wchar_t code = cfg.m_legacyShortcutText[i][0];
        if (code == L'\0') {
            continue;
        }

        cfg.m_compactShortcutRecords[i].code = code;
        cfg.m_compactShortcutRecords[i].isSpellMode = true;
        cfg.m_legacyShortcutText[i][0] = L'\0';
    }

    for (unsigned int i = 0; i < kCompactShortcutCount; ++i) {
        CompactShortcutRecord& shortcut = cfg.m_compactShortcutRecords[i];
        if (shortcut.code == L'\0') {
            continue;
        }

        MacroHotkeyRecord& macro = cfg.m_macroHotkeys[i];
        macro.state = shortcut.isSpellMode ? 2 : 3;
        macro.payload[0] = shortcut.code;
        macro.payload[1] = L'\0';
        shortcut.code = L'\0';
    }
}

} // namespace

void LoadUserProfileData()
{
    RegistryConfig& cfg = *g_pConfig;
    cfg.InitializeUserDataDefaults();

    wchar_t documents[MAX_PATH];
    if (SHGetFolderPathW(nullptr, CSIDL_PERSONAL, nullptr, 0, documents) != S_OK) {
        return;
    }

    wchar_t path[kProfilePathCch];
    WideFormatWrapper(path, L"%s\\NexusTK", documents);
    if (!EnsureDirectoryExists(path)) {
        return;
    }

    WideFormatWrapper(path, L"%s\\NexusTK\\users", documents);
    if (!EnsureDirectoryExists(path)) {
        return;
    }

    wchar_t userId[kLocalPlayerNameCch];
    GetLocalPlayerName(userId, kLocalPlayerNameCch);

    SimpleUString profilePath;
    profilePath.Format(L"%s/%s.usr", path, userId);

    FILE* file = g_pfnWideOpenFile(profilePath.c_str(), L"rb");
    if (file == nullptr) {
        g_pfnGetCurrentDirectoryW(kLegacyPathCch, path);
        profilePath.Format(L"%s/users/%s.usr", path, userId);
        file = g_pfnWideOpenFile(profilePath.c_str(), L"rb");
        if (file == nullptr) {
            ImportLegacyUserProfileData();
            return;
        }
    }

    for (unsigned int i = 0; i < kFixedProfileSlotCount; ++i) {
        if (!ReadLengthPrefixedWide(file, cfg.m_profileTextSlots[i], kFixedProfileSlotCch, 0x7f)) {
            return;
        }
    }

    for (unsigned int i = 0; i < kFixedProfileSlotCount; ++i) {
        cfg.m_legacyShortcutText[i][0] = static_cast<wchar_t>(fgetwc(file));
        cfg.m_legacyShortcutText[i][1] = L'\0';
    }

    for (unsigned int i = 0; i < kProfileStringSlotCount; ++i) {
        ReadProfileStringSlot(file, cfg.m_profileStringSlots[i]);
    }

    ReadLengthPrefixedWide(file, cfg.m_selectedProfileName, kSelectedProfileCch, 0xffff);

    uint32_t count = 0;
    if (fread(&count, sizeof(count), 1, file) == 1) {
        cfg.m_blockListenNames.clear();
        for (uint32_t i = 0; i < count; ++i) {
            uint32_t length = 0;
            fread(&length, sizeof(length), 1, file);
            SimpleUString value;
            wchar_t* data = value.SetLengthWideAndDetach(length);
            fread(data, sizeof(wchar_t), length, file);
            value.LockWideBuffer();
            cfg.m_blockListenNames.push_back(value);
        }
    }

    uint32_t present = 0;
    if (fread(&present, sizeof(present), 1, file) == 1) {
        for (unsigned int i = 0; i < kCompactShortcutCount; ++i) {
            cfg.m_compactShortcutRecords[i].code = static_cast<wchar_t>(fgetwc(file));
            cfg.m_compactShortcutRecords[i].isSpellMode = (fgetwc(file) == L'S');
        }
    }

    count = 0;
    if (fread(&count, sizeof(count), 1, file) == 1 && count != 0) {
        for (uint32_t i = 0; i < count; ++i) {
            const wint_t type = fgetwc(file);
            if (type == L'I') {
                cfg.m_macroHotkeys[i].state = 3;
            } else if (type == L'S') {
                cfg.m_macroHotkeys[i].state = 2;
            } else if (type == L'T') {
                cfg.m_macroHotkeys[i].state = 1;
            }

            unsigned short length = 0;
            fread(&length, sizeof(length), 1, file);
            if (length < kMacroPayloadCch) {
                fread(cfg.m_macroHotkeys[i].payload, sizeof(wchar_t), length, file);
                cfg.m_macroHotkeys[i].payload[length] = L'\0';
            }
        }
    }

    count = 0;
    if (fread(&count, sizeof(count), 1, file) == 1 && count != 0) {
        for (uint32_t i = 0; i < count; ++i) {
            cfg.m_targetOptionRows[i].userEnabled = (fgetwc(file) == L'1');
            cfg.m_targetOptionRows[i].monsterEnabled = (fgetwc(file) == L'1');
        }
    }

    MigrateLegacyShortcuts(cfg);
    fclose(file);
}

} // namespace ProfileStorage
```

Implementation callback caveats for the C++ block:

- The corrupt-file early-return path after a fixed-slot length `> 0x7f` should be revalidated with live disassembly before final code, because the decompiled shape appears to leave through the local `SimpleUString` cleanup path rather than a clean `fclose`.
- The macro-row count reader uses the file-provided count; the writer emits `30`. The exact binary does not show a clamp before writing rows, so final code should not silently add `min(count, 30)` unless the supervisor requests a safer cleaned-source variant.
- The flag-pair count reader uses the file-provided count; the writer emits `2`. Same no-clamp caveat.

## Recommended Target Doc Changes

Update the status section to say:

```text
- Confidence: strong for function boundaries, source owner, caller chain, zero-argument source signatures, modern/legacy profile path behavior, serialized layout, field-role names, helper ownership, and first-draft C++ shape.
- Proposed file: [UID:0000MS][ProfileStorage](by-file/ProfileStorage.md)
- Code gate: clears the current 85/85 source-quality gate after this pass. C++ should no longer remain blank solely because of the stale 95/95 no-code policy.
```

Add/replace signature note:

```text
Source-facing signatures are `static void ImportLegacyUserProfileData()` and `void LoadUserProfileData()`. Both helpers get the local user/profile file stem internally from `0x005a2da0`; neither takes a semantic user-name parameter. IDA's `int()` return guess for the importer and `void __fastcall(unsigned int)` guess for the loader are decompiler artifacts and should not drive the source API.
```

Add/replace fallback note:

```text
`LoadUserProfileData` only tries the current-directory `users/<name>.usr` fallback after `SHGetFolderPathW(CSIDL_PERSONAL)` succeeds and the `Documents\NexusTK` / `Documents\NexusTK\users` directory setup succeeds. If `SHGetFolderPathW` fails, or either directory cannot be created and is not already present, the function returns after defaults and does not call the legacy importer.
```

Add field-name table from this report under the layout section.

Populate the C++ block with a refined version of the first-draft source above, subject to implementation callback and fresh validation.

## Recommended Support Doc Updates

### `by-file/ProfileStorage.md`

Recommended metadata:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Exact content to add under `File Format And Paths`:

```text
- `LoadUserProfileData` and `ImportLegacyUserProfileData` are source-facing zero-argument helpers. Both call the local-player-name copy helper at `0x005a2da0`; the apparent IDA loader argument and importer return value are not semantic source API.
- The current-directory `.usr` fallback and legacy `.cfg` import are reached only after `SHGetFolderPathW(CSIDL_PERSONAL)` succeeds and both `Documents\NexusTK` and `Documents\NexusTK\users` are created or already exist. A Documents-path failure leaves `RegistryConfig::InitializeUserDataDefaults` output in place.
```

Exact content to replace the final open-question bullet about remaining `.usr` field names:

```text
- Source-facing profile field role names are now strong enough for first-draft C++: `m_profileTextSlots`, `m_legacyShortcutText`, `m_profileStringSlots`, `m_selectedProfileName`, `m_blockListenNames`, `m_compactShortcutRecords`, `m_macroHotkeys`, and `m_targetOptionRows`. Exact original member spelling remains open, but these names are no longer blockers for reconstructable source emission.
```

### `by-meta/client_profile_storage.md`

Exact content to replace the section-5 row note:

```text
| 5 | `uint32 count`, then `uint32 length` + text per entry | vector at `+0x2918fc/+0x291900/+0x291904` | variable | Dynamic wide-string vector. Current block-listen input-pane evidence resolves the role as block-listen names; use source-facing `m_blockListenNames` unless later original-symbol recovery proves different spelling. |
```

Exact content to add under `.usr Paths`:

```text
- If `SHGetFolderPathW(CSIDL_PERSONAL)` fails, or if `Documents\NexusTK` / `Documents\NexusTK\users` cannot be created and the error is not `ERROR_ALREADY_EXISTS`, the loader returns with default user-data state. The current-directory `.usr` fallback and legacy `.cfg` importer are not reached in those failure paths.
```

### `by-type/by-struct/RegistryConfigUserProfileBlock.md`

Recommended metadata:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Exact content to add after the current layout slice table:

```text
For first-draft source, use these descriptive member names: `m_profileTextSlots[10][0x80]` at `+0x28de9c`, `m_legacyShortcutText[10][0x80]` at `+0x28e89c`, `m_compactShortcutRecords[20]` at `+0x28f29c`, `m_macroHotkeys[30]` at `+0x28f2ec`, `m_targetOptionRows[2]` at `+0x2911dc`, `m_profileStringSlots[20]` at `+0x2911e0`, `m_selectedProfileName[0x100]` at `+0x2912b8`, and `m_blockListenNames` at `+0x2918fc/+0x291900/+0x291904`. These are role-accurate source names, not proven original spelling.
```

Exact content to replace the dynamic-vector open question:

```text
- The dynamic vector role is resolved as block-listen name storage by BlockListenInputPanes show/add/delete evidence. Exact original member spelling remains open, but `m_blockListenNames` is the recommended source-facing name for current reconstruction.
```

### `by-global/WideApiDispatchTable.md`

Exact content to add to the file I/O/platform slot table:

```text
| `0x0069be5c` | `g_pfnCreateDirectoryW` / `dword_69BE5C` | `CreateDirectoryW` | ProfileStorage, screenshot capture, and other path setup helpers |
| `0x0069be60` | `g_pfnDeleteFileW` / `dword_69BE60` | `DeleteFileW` | Legacy profile `.cfg` deletion, stale profile writer cleanup, minimap/download partial-file cleanup |
| `0x0069be70` | `g_pfnGetCurrentDirectoryW` / `dword_69BE70` | `GetCurrentDirectoryW` | Legacy profile import, current-directory `.usr` fallback, registry location persistence |
```

### `by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md`

Exact change to `Evidence`:

```text
- Current raw export/decompilation of `0x0041a280` also resolves the ProfileStorage path slots: `0x0069be5c` is `CreateDirectoryW`, `0x0069be60` is `DeleteFileW`, and `0x0069be70` is `GetCurrentDirectoryW`.
```

## Validator And Implementation Needs

Before implementation callback:

1. Reconnect live IDA MCP if available and run:

```text
lookup_funcs 0x004f9280
lookup_funcs 0x004f95b0
callees 0x004f9280
callees 0x004f95b0
callers 0x004f9280
callers 0x004f95b0
disasm 0x004f8a70 0x40
get_bytes 0x004f95a2 0x0e
get_bytes 0x004f9d28 0x08
```

2. Validate the source-facing no-argument signatures by checking the caller-side instruction sequence around `0x004f8a83` and the loader's non-use of the apparent argument.

3. If target/support docs are edited, run:

_Executable command block removed from the research report; preserved in [00019T-ProfileLoadAndLegacyImport-source-quality-removed.md](00019T-ProfileLoadAndLegacyImport-source-quality-removed.md)._

4. If C++ is populated, also run the normal reconstruction generation/check path requested by the supervisor. I did not run generation in this B-report-only pass.

## Exact Pending Coverage Row

Do not edit `by-memory/-coverage-report.md` in this pass. Replace the existing row with:

```text
    - [UID:00019T][0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport](by-memory/0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport.md) 0x004f9280-0x004f9d28 | function-pair aggregate | ProfileLoadAndLegacyImport : reconstructable : 88% : strong : B013 source-quality pass resolves the stale no-code gate for the ProfileStorage loader/importer aggregate: raw exports confirm `0x004f9280` size `0x322` and `0x004f95b0` size `0x778`, importer caller only from loader, loader caller from `InitializeMainUiGraph` at `0x004f8a83`, source-facing zero-argument `ImportLegacyUserProfileData` and `LoadUserProfileData`, internal current-user lookup through `0x005a2da0`, Documents `.usr` path setup through `SHGetFolderPathW(CSIDL_PERSONAL)`, current-directory `.usr` fallback only after Documents setup succeeds, legacy `.cfg` quoted-string import/delete, named RegistryConfig profile fields, block-list vector, shortcut/macro migration, PlatformApi/StringBase/SimpleUStringVector dependency boundaries, and first-draft aggregate C++ ready under [UID:0000MS] ProfileStorage.
```

## Implementation Readiness

Status: ready for implementation callback.

Recommended implementation action:

- Edit the target doc metadata to `88/90`.
- Replace stale no-code prose with the current source-quality findings.
- Populate the target C++ block with a refined version of the first-draft code.
- Update support docs as listed above.
- Update `by-memory/-coverage-report.md` only if the supervisor authorizes shared coverage edits.

Remaining open questions are not blockers:

- Exact original filename may have been `ProfileStorage.cpp`, `UserProfile.cpp`, or legacy/Korean equivalent. Current proposed tree and sibling helpers still make `profile/ProfileStorage.cpp` the best route.
- Exact original member spelling is not recovered, but role-accurate field names are strong enough for first-draft source.
- Exact corrupt-file cleanup behavior should be validated during implementation, but normal load/import behavior and ownership are resolved.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B013","command_id":"000000004165","destination_path":"executed-b-agent-research/B013/00019T-ProfileLoadAndLegacyImport-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:36","uid":"00019T"} -->
<!-- {"agent":"B013","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00019T-ProfileLoadAndLegacyImport-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B013/00019T-ProfileLoadAndLegacyImport-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00019T"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
