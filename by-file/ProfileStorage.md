*** UID:0000MS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/profile/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# ProfileStorage

## UID0000MS Whole-File Source Completion - 2026-08-25

`NexusTK/profile/ProfileStorage.cpp` is a flat C++03-era source module containing exactly three source functions. It is not a `ProfileStorage` namespace or class. The importer is file-local; the loader and writer are public globals declared once by `ProfileStorage.h`. The source-owned ranges are noncontiguous because the writer is separated from the importer/loader pair by unrelated code:

| Source order | UID / range | Size / SHA256 | Source-facing declaration | Linkage and role |
| --- | --- | --- | --- | --- |
| 1 | [UID:00019T][0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport](by-memory/0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport.md) `[0x004f9280,0x004f95a2)` | 802 bytes / `AF24E728DFA8B0C28A9DF1A4D29A60BF9055680C2877421F0759B102088F0808` | `static void ImportLegacyUserProfileData()` | File-local legacy `.cfg` importer; its only inbound call is the loader at `0x004f974a`. |
| 2 | [UID:00019T][0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport](by-memory/0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport.md) `[0x004f95b0,0x004f9d28)` | 1,912 bytes / `C99D8F24811DFD5BCC2BA70D93B266F663ADB162A65750C4A684D18FC202DBD4` | `void LoadUserProfileData()` | Public loader; its only inbound call is [UID:00019K][0x004f7d10-0x004f8b2a.InitializeMainUiGraph](by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md) `InitializeMainUiGraph` at `0x004f8a83`. |
| 3 | [UID:0001AV][0x0050aba0-0x0050b078.SaveUserSettings](by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md) `[0x0050aba0,0x0050b078)` | 1,240 bytes / `0108F81842E9AD6A537622A52E799A65751424BA0237EF70F8AA566D0240BE14` | `void SaveUserSettings()` | Public writer; eight inbound code xrefs occur at `0x00504850`, `0x0053dd8c`, `0x0053dfb8`, `0x0053ed6e`, `0x0053f15c`, `0x0053f8f8`, `0x005420a7`, and `0x0054252a`. |

The file owns 3,954 executable bytes. No fourth ProfileStorage function, thunk, EH helper, global, static object, vtable, RTTI, resource, or data table was found in adjacent ranges, call relationships, current documentation, generated output, or matching executed reports. Imported CRT, Win32, Config, StringBase, vector, path, and player-name facilities remain dependencies.

### Boundaries And Padding

- Three `0xcc` bytes precede the importer at `0x004f927d-0x004f9280`.
- Fourteen `0xcc` bytes separate importer and loader at `0x004f95a2-0x004f95b0`; this alignment gap does not invalidate the two-function [UID:00019T][0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport](by-memory/0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport.md) aggregate.
- Eight post-loader `0xcc` bytes occupy `0x004f9d28-0x004f9d30` and are outside the aggregate.
- Eleven pre-writer `0xcc` bytes occupy `0x0050ab95-0x0050aba0`; eight post-writer bytes occupy `0x0050b078-0x0050b080`. Neither interval is emitted as source.
- No new split is required. Splitting importer from loader would add emitter routing without changing source ownership, while broadening either child would absorb unrelated code.

### Source Shape And Helpers

The CPP source order is includes and CPP-local constants, file-local helper functions, `ImportLegacyUserProfileData`, `LoadUserProfileData`, then `SaveUserSettings`. The shared header contains only `LoadUserProfileData()` and `SaveUserSettings()`. `ReadLegacyQuotedString`, `CreateProfileDirectory`, `ReadProfileString`, and `MigrateLegacyShortcuts` are plausible human source helpers for repeated source operations that the optimizer folded into the modeled bodies; they are not new binary children. CPP-local integral constants explain immediate counts and lengths without inventing by-global allocations.

The final draft deliberately uses ordinary C++03 `NULL`, `static const`, explicit loops, direct global functions, and an anonymous namespace for file-local helpers. It rejects the earlier namespace-shaped/C++11 draft because no symbol, caller, or neighboring source pattern supports a public `ProfileStorage` namespace.

### Modern `.usr` Format

The writer and loader are inverse implementations of eight sequential groups:

| Group | Writer format | Loader behavior, including required edge semantics |
| --- | --- | --- |
| 1 | Ten `uint16` lengths followed by UTF-16 profile-text payloads. | A length over `0x7f` returns immediately without closing the file; accepted rows receive a local NUL. |
| 2 | Ten single UTF-16 legacy-shortcut characters. | Reads exactly ten characters and appends a local NUL to each two-wide slot. |
| 3 | Twenty `uint16` lengths followed by UTF-16 friend-name payloads. | Rebuilds twenty `StringBase<wchar_t>` values through set-length/detach, read, and lock. |
| 4 | One `uint16` length followed by the selected-profile UTF-16 payload. | Trusts the file-provided length, reads directly into the 0x100-wide field, and writes the terminator at that index without a bounds check. |
| 5 | Optional `uint32` count; each row is `uint32` length plus UTF-16 payload. | On a successful count read, clears `m_blockListenNames`, trusts count and length, and appends each reconstructed value. |
| 6 | Literal dword `1`, followed by twenty UTF-16 code/mode pairs. | Any successfully read dword enables exactly twenty rows; its numeric value is not used as a count. Mode is true only for `L'S'`. |
| 7 | Dword `30`; each row contains a type wchar, `uint16` length, and UTF-16 payload. | Trusts the file count. `T/S/I` map to states `1/2/3`; unknown type leaves the existing default. A length `>=0x80` leaves the payload unread and therefore desynchronizes subsequent input. |
| 8 | Dword `2`; each row contains user/monster `L'1'` or `L'0'`. | Trusts the file count and converts each character comparison directly to the two booleans. |

The code must preserve ignored `fread`, `fwrite`, and `fputwc` results and all malformed-input behavior above. Adding clamps, recovery reads, defensive closes, or selected-profile bounds checks would improve safety but change the original executable.

### Legacy `.cfg` Migration

The importer builds `users\\<player>.cfg` under the current directory, opens it with the wide dispatch, and reads quoted UTF-16 fields through a 512-wide scratch buffer: ten profile-text rows, ten legacy-shortcut rows, twenty friend names, then one selected-profile field. Only the selected-profile destination receives the index-255 truncation rule. Failure to open is a no-op; success closes the stream and deletes the migrated file.

Post-load migration first copies nonempty legacy shortcut characters into compact shortcut rows with `isSpellMode = 1`, then converts nonempty compact rows into macro rows. The exact state expression is `(shortcut.isSpellMode != 1) + 2`: only byte value exactly `1` maps to macro state `2`; every other value maps to state `3`.

### Storage And Dependencies

- Profile data is stored directly in `Config`: `m_profileTextSlots`, `m_legacyShortcutText`, `m_friendNames`, `m_selectedProfileName`, `m_blockListenNames`, `m_compactShortcutRecords`, `m_macroHotkeys`, and `m_targetOptionRows`.
- The only `RegistryConfig` cast is the nonvirtual `InitializeUserDataDefaults()` call at loader entry. A broad derived-object cast for ordinary field access is stale and rejected.
- `m_friendNames` supersedes the stale draft spelling `m_profileStringSlots`; the current Config declaration and FriendListDialog behavior establish the role.
- `PlatformApi.h` supplies wide file open/current-directory/CreateDirectory/DeleteFile/SetFileAttributes/read-UTF16 dispatch declarations.
- `StringBase.h` supplies `SetLengthWideAndDetach` and `LockWideBuffer`; the 12-byte `SimpleUStringVector` facade supplies `Clear`, `Size`, indexing, and `PushBack` without changing its begin/end/capacity layout.
- `ProfileStorage.h` is consumed once per translation unit by MainMenu, MapPane, FriendListDialog, MacroDialogs, and TargetOptionDialog; consumer-local forward declarations are rejected.

### Excluded MapPane Sidecar Family

[UID:0001AS][0x005063e0-0x00506962.ProfileSidecarRefresh](by-memory/0x005063e0-0x00506962.ProfileSidecarRefresh.md) `RefreshSelectedProfileData`, [UID:00027P][0x0066dd60-0x0066dd78.ImageExtensionPointerTable](by-memory/0x0066dd60-0x0066dd78.ImageExtensionPointerTable.md) `ImageExtensionPointerTable`, [UID:0003IV][0x0061e964-0x0061e9fc.ProfileSidecarImageStrings](by-memory/0x0061e964-0x0061e9fc.ProfileSidecarImageStrings.md) profile-sidecar image literals, and [UID:0001DU][0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper](by-memory/0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper.md) the ProfileDialog forwarding member are cross-module consumers, not ProfileStorage-owned source. Their receiver, tables, resources, and established owner/emitter routes keep the implementation in MapPane/ProfileDialog. This file records the dependency but does not duplicate their code or data.

### Superseded Historical Assumptions

Older material below that groups the MapPane sidecar into ProfileStorage, uses `namespace ProfileStorage`, casts all profile storage through `RegistryConfig`, or names friend slots `m_profileStringSlots` is retained as historical provenance only. The evidence-backed whole-file model and formal child channels above supersede those assumptions.

## Status

- Confidence: strong for profile persistence helper grouping, the direct `SaveUserSettings` parent relationship, zero-argument load/import signatures, current field-role names, and the corrected MapPane cross-module sidecar route; medium-high for the exact original persistence filename.
- Proposed module: `profile/ProfileStorage.cpp`
- Related config module: [UID:0000IE][Config](by-file/Config.md)
- Related UI callers: `ProfileDialog`, `ProfilePane`, `FriendListDialog`, and other settings dialogs that trigger profile saves; ProfileDialog also invokes the separate MapPane sidecar-refresh route.
- Evidence basis: existing profile-storage documentation, IDA MCP caller/callee/decompile checks through 2026-06-11, and the accepted 2026-07-28 UID0001DU receiver/source-route reanalysis.

## Hypothesis

The user-profile persistence helpers should be grouped as a profile storage module, not left as one-function generated files. They operate on the `RegistryConfig` user-data block through `g_pConfig` or the equivalent global pointer, and their file responsibility is modern `.usr` IO, legacy `.cfg` import, migration, and settings serialization. Selected-profile sidecar packet behavior remains documented here as a cross-module consumer of the same config fields, but its implementation belongs to MapPane.cpp.

Preferred reconstruction:

```text
profile/ProfileStorage.cpp
profile/ProfileStorage.h
```

The lower-level `Config`, `RegistryConfig`, `ConfigEntryBlock`, `InitializeConfigEntry`, and `DestroyConfigEntry` code should migrate to `config/`, not to this profile module.

## Proposed Contents

| Entity | Range | Current file | Role |
| --- | --- | --- | --- |
| `ImportLegacyUserProfileData` | `0x004f9280-0x004f95a2` | `recovered/ImportLegacyUserProfileData_004F9280.cpp` | Imports old current-directory `users\<name>.cfg` profile data and deletes it after successful migration. |
| `LoadUserProfileData` | `0x004f95b0-0x004f9d28` | `recovered/LoadUserProfileData_004F95B0.cpp` | Loads `Documents\NexusTK\users\<name>.usr`, resets defaults first, and falls back to legacy import. |
| `SaveUserSettings` | `0x0050aba0-0x0050b078` | global definition in `profile/ProfileStorage.cpp` | Serializes the current profile/settings block, including [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md) rows, to `Documents\NexusTK\users\<player>.usr`. |

## MapPane Cross-Module Sidecar Route - 2026-07-28

- [UID:0001AS][0x005063e0-0x00506962.ProfileSidecarRefresh](by-memory/0x005063e0-0x00506962.ProfileSidecarRefresh.md) is `void MapPane::RefreshSelectedProfileData()` in [UID:0000L3][MapPane](by-file/MapPane.md), not a ProfileStorage free function. Every live caller prepares a MapPane receiver, including the ProfileDialog action path and retained [UID:0001DU][0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper](by-memory/0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper.md) through [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md). Incoming `this` is optimized unused after the call boundary, which explains the old cdecl-shaped decompile without proving cdecl source.
- [UID:00027P][0x0066dd60-0x0066dd78.ImageExtensionPointerTable](by-memory/0x0066dd60-0x0066dd78.ImageExtensionPointerTable.md) follows its sole UID0001AS table-base consumer to MapPane.cpp and emits the one `kProfileSidecarExtensions` declaration there. [UID:0003IV][0x0061e964-0x0061e9fc.ProfileSidecarImageStrings](by-memory/0x0061e964-0x0061e9fc.ProfileSidecarImageStrings.md) is MapPane-owned, source-generated, non-emitting literal evidence.
- ProfileStorage still supplies the config-field and persistence semantics needed to understand the method: the selected-profile field at `g_pConfig + 0x2912b8`, local-user profile paths, and compatibility behavior. It does not emit the MapPane member, extension table, or raw literal child. ProfileDialog.cpp owns only its separate forwarding trigger helper.
- The former B003 ownership inference relied on filesystem behavior and the erased `this` use. Receiver ABI, physical MapPane code/data placement, the sole table consumer, and one-definition output now supersede it. All accepted FaceRipper/JPF/image-validation/opcode-79 facts remain below; only current source ownership changes.

## File Format And Paths

- Modern profile files live under `Documents\NexusTK\users` and use a `.usr` extension.
- `LoadUserProfileData` also checks the current-directory `users/<name>.usr` fallback.
- Legacy migration reads current-directory `users\<name>.cfg` as quoted wide strings, copies the data into the same config user-data offsets, and deletes the legacy file after success.
- `SaveUserSettings` writes all eight exact groups documented below. `int_convert.py` verified `0x1e == 30`, `0x108 == 264`, `0x28f2f0 == 2683632`, and `0x28f2f4 == 2683636` during the 2026-06-11 Batch 164 refresh.
- [UID:0001QL][client_profile_storage](by-meta/client_profile_storage.md) now records the `.usr` binary layout, legacy `.cfg` import format, shortcut migration, selected-profile sidecar behavior, and caller evidence.
- [UID:0001VR][RegistryConfigUserProfileBlock](by-type/by-struct/RegistryConfigUserProfileBlock.md) records the current offset map for the user-profile/settings slice inside `RegistryConfig`.
- [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md) records the integrated macro/hotkey row layout at `g_pConfig + 0x28f2ec + i * 0x108`.
- `LoadUserProfileData` and `ImportLegacyUserProfileData` are source-facing zero-argument helpers. Both call the local-player-name copy helper at `0x005a2da0`; the apparent IDA loader argument and importer return value are not semantic source API.
- The current-directory `.usr` fallback and legacy `.cfg` import are reached only after `SHGetFolderPathW(CSIDL_PERSONAL)` succeeds and both `Documents\NexusTK` and `Documents\NexusTK\users` are created or already exist. A Documents-path failure leaves `RegistryConfig::InitializeUserDataDefaults` output in place.
- Cross-module `MapPane::RefreshSelectedProfileData` probes sidecar image extensions (`bmp`, `pcx`, `jpg`, `jpeg`, `pnm`), runs `FaceRipper.exe` for a found sidecar, then reads `<local-player-name>.jpf` from the documents folder or `./users`. The sidecar filename stem comes from [UID:0002AA][0x0069bee0-0x0069bf20.LocalPlayerNameWideBuffer](by-memory/0x0069bee0-0x0069bf20.LocalPlayerNameWideBuffer.md) through helper `0x005a2dc0`; the ProfileStorage-related selected-profile field at `g_pConfig + 0x2912b8` is appended to outbound opcode `79`.
- [UID:0003IV][0x0061e964-0x0061e9fc.ProfileSidecarImageStrings](by-memory/0x0061e964-0x0061e9fc.ProfileSidecarImageStrings.md) is the exact MapPane-owned read-only string child for those sidecar extensions/path formats. C001 split it away from later `/users/` `.epf`/`.face` strings; current non-emitting classification reflects that ordinary MapPane source literals regenerate its bytes.
- The `.jpf` validation path calls the shared [UID:000175][0x004d05f0-0x004d0f4a.ImageDecodeWrappers](by-memory/0x004d05f0-0x004d0f4a.ImageDecodeWrappers.md) at `0x004d07b0`, then only includes the profile name when the decoded tile-context span matches the expected portrait dimensions.

## IDA MCP Evidence

IDA confirms the three current ProfileStorage source functions and the cross-module MapPane member as real function starts:

- `0x004f9280-0x004f95a2` `ImportLegacyUserProfileData`, called only from `LoadUserProfileData`.
- `0x004f95b0-0x004f9d28` `LoadUserProfileData`, called from `0x004f7d10` during main UI graph initialization.
- `0x005063e0-0x00506962` `MapPane::RefreshSelectedProfileData`, called from `0x00507c90`, `0x0053fdc0`, and `0x0053fe90`; all three call routes prepare a MapPane receiver, so this is cross-module evidence rather than a Proposed Contents row.
- `0x0050aba0-0x0050b078` `SaveUserSettings`, with eight exact xrefs: `0x00504850`, raw/no-function `0x0053dd8c`, `0x0053dfb8`, `0x0053ed6e`, `0x0053f15c`, `0x0053f8f8`, `0x005420a7`, and `0x0054252a`.

Historically, the 2026-06-11 Batch 164 recheck grouped four functions here: `ImportLegacyUserProfileData`, `LoadUserProfileData`, `RefreshSelectedProfileData`, and `SaveUserSettings`. Its direct range/caller and writer facts remain valid, but the storage-group conclusion for UID0001AS is superseded by the 2026-07-28 receiver/source-route proof. Current ProfileStorage source contains the first, second, and fourth functions; MapPane.cpp contains UID0001AS. The writer decompilation still proves `SHGetFolderPathW`, `%s\\NexusTK`, `%s\\NexusTK\\users`, `%s/%s.usr`, repeated `_fwrite`/`_fputwc`, `_fclose`, and macro type characters `T`, `S`, and `I`.

## SaveUserSettings Exact Writer Contract

The source definition is a global, unqualified `void SaveUserSettings()` in this module. It accesses the derived user-profile slice through `*static_cast<RegistryConfig *>(g_pConfig)`; RegistryConfig owns the storage, while this file owns path construction and serialization. MapPane and the calling dialogs are triggers only.

| Order | Source field | Exact output |
| --- | --- | --- |
| 1 | ten `m_profileTextSlots[0x80]` rows | uint16 length, then one `fwrite` of `2 * length` bytes |
| 2 | ten `m_legacyShortcutText` rows | first wchar only, no count/terminator |
| 3 | twenty pointer-backed `m_profileStringSlots` | narrowed uint16 length, then byte-size wide payload |
| 4 | `m_selectedProfileName[0x100]` | uint16 length, then byte-size wide payload |
| 5 | `m_blockListenNames` pointer-triplet vector | uint32 count; each row uint32 length then `fwrite` size 2/count length |
| 6 | twenty `m_compactShortcutRecords` | literal dword `1`, then code wchar and `S` for nonzero mode / `I` for zero; byte `+3` omitted |
| 7 | thirty `m_macroHotkeys` | dword `30`, `T/S/I` for states 1/2/3, uint16 text length, byte-size text |
| 8 | two `m_targetOptionRows` | dword `2`, then four wchar booleans; only byte exactly 1 maps to `1` |

The group-6 dword is an optional-tail presence/version marker, not a row count. An invalid macro state emits no type wchar but still emits its length/text, preserving the binary's malformed-stream hazard. All fixed/string lengths narrow exactly as documented; no NUL terminator is serialized for length-prefixed text.

Path/failure order is also source-significant. `SHGetFolderPathW(CSIDL_PERSONAL)` must return `S_OK`; both directory creations accept failure only when immediate `GetLastError()` is `ERROR_ALREADY_EXISTS`. `GetLocalPlayerName` receives capacity `0x28` and its result is ignored. The writer sets normal attributes and deletes the old file without checking either result, then opens `wb`; open failure may therefore leave no file. Every `fwrite`, `fputwc`, and `fclose` result is ignored, so partial/truncated output is possible. There is no temporary file, rename, retry, rollback, exception, error report, or status return.

Caller semantics are not interchangeable. MapPane exit and FriendList call unconditionally; FriendList performs optional opcode `0x77` synchronization first. OptionPane apply/raw, SpellMacro, NewMacro, IntegrateMacro, and TargetOption gate the writer on non-null `g_activeMapPane`. Raw `[0x0053dd70,0x0053dda6)` has no start route and remains support-only rather than a new emitter; `[0x0053dda6,0x0053ddb0)` is ten-byte `0xcc` padding.

Rejected current-source alternatives for `SaveUserSettings` are MapPane ownership, RegistryConfig member placement, dialog-local ownership, `WideFormatWrapper`, `g_userSettingsDirty`, FriendList `SaveConfig()`, and the address-suffixed `SaveUserSettings_50ABA0` spelling. The address suffix remains historical search provenance only. Exact original persistence filename/member spelling is still unknown and keeps confidence below final-source certainty without blocking the accepted source route.

## Placement Decision

Recommended split:

```text
config/Config.cpp
config/RegistryConfig.cpp
profile/ProfileStorage.cpp
profile/ProfileDialog.cpp
```

`ProfileDialog` and `ProfilePane` remain UI/profile modules that call persistence helpers in ProfileStorage; they do not own file serialization. The selected-profile sidecar path is separate: ProfileDialog.cpp owns the retained `RefreshProfileData` forwarding helper, while MapPane.cpp owns `MapPane::RefreshSelectedProfileData`, its one extension table, and source-generated literals. The earlier behavior-based preference for ProfileStorage ownership is historical and superseded. See [UID:0000MR][ProfileDialog](by-file/ProfileDialog.md) and [UID:0000L3][MapPane](by-file/MapPane.md) for the two source routes.

[UID:0001AV][0x0050aba0-0x0050b078.SaveUserSettings](by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md) now clears the strict child gate and is attached here. The surrounding broad [UID:0001AT][0x00506970-0x0050e320.MapPaneInputPacketRenderCore](by-memory/0x00506970-0x0050e320.MapPaneInputPacketRenderCore.md) page physically spans this address island but explicitly excludes it from MapPane ownership.

## Score Rationale

Completion is `94` because the page now closes the complete three-function persistence inventory, exact noncontiguous ranges, byte hashes and caller/xref routes, modern `.usr` and legacy `.cfg` behavior, malformed-input semantics, dependencies, MapPane/ProfileDialog sidecar exclusions, and complete formal C++03 CPP/H source. Confidence is `94` because current IDA, inverse load/save behavior, Config/profile-schema declarations, cross-module callers, generated output, and owner/emitter evidence converge on the same file boundary and implementation. Exact original filename, helper/member/local spelling, and final build-level equivalence remain inferred rather than symbol- or build-proven, so the current source-quality score remains below 95 without blocking reconstruction.

## Open Questions

- Whether the original filename was `ProfileStorage.cpp`, `UserProfile.cpp`, or a Korean/legacy naming equivalent.
- Resolved 2026-07-28: `RefreshSelectedProfileData` does not remain in ProfileStorage.cpp. All three callers establish a MapPane receiver, the body sits in a MapPane code cluster, and its sole table sits between MapPane data tables. The current source is `MapPane::RefreshSelectedProfileData`; the former cdecl/storage-side inference is retained as corrected B003 history.
- Source-facing profile field role names are now strong enough for first-draft C++: `m_profileTextSlots`, `m_legacyShortcutText`, `m_profileStringSlots`, `m_selectedProfileName`, `m_blockListenNames`, `m_compactShortcutRecords`, `m_macroHotkeys`, and `m_targetOptionRows`. Exact original member spelling remains open, but these names are no longer blockers for reconstructable source emission.

## Cross-References

- [UID:0000IE][Config](by-file/Config.md)
- [UID:0000BW][RegistryConfig](by-class/RegistryConfig.md)
- [UID:00019T][0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport](by-memory/0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport.md)
- [UID:0001AS][0x005063e0-0x00506962.ProfileSidecarRefresh](by-memory/0x005063e0-0x00506962.ProfileSidecarRefresh.md)
- [UID:0003IV][0x0061e964-0x0061e9fc.ProfileSidecarImageStrings](by-memory/0x0061e964-0x0061e9fc.ProfileSidecarImageStrings.md)
- [UID:000175][0x004d05f0-0x004d0f4a.ImageDecodeWrappers](by-memory/0x004d05f0-0x004d0f4a.ImageDecodeWrappers.md)
- [UID:0001AV][0x0050aba0-0x0050b078.SaveUserSettings](by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md)
- [UID:0001QL][client_profile_storage](by-meta/client_profile_storage.md)
- [UID:0001VR][RegistryConfigUserProfileBlock](by-type/by-struct/RegistryConfigUserProfileBlock.md)
- [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-07-28 B005 UID0001DU callback: raised `88/87` to `89/90`; removed UID0001AS and UID0003IV from current Proposed Contents; retained all selected-profile sidecar behavior as a cross-module contract; routed UID0001AS, UID00027P, and UID0003IV to MapPane.cpp; added the separate ProfileDialog.cpp forwarding-helper route; and historicalized the B003 four-member/cdecl/ProfileStorage assumption without deleting its valid filesystem/JPF/opcode evidence.

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `86`, confidence `80`.
- Summary/evidence: the page documents profile-storage grouping, file formats/paths, IDA caller evidence, placement decision, open questions, related type/meta docs, and cross-references; confidence remains capped by exact original filename and unresolved field names.
- 2026-06-11 A005 Batch 164 parent-gate refresh:
  - Before: `86/80`.
  - After: `87/85`.
  - Summary/evidence: live IDA MCP reconfirmed the four profile-storage helper boundaries and caller spread, including eight xrefs to `SaveUserSettings_50ABA0`; decompilation of the writer shows the `Documents\\NexusTK\\users` path construction, `%s/%s.usr`, macro-row serialization, `T`/`S`/`I` writes, and `_fwrite`/`_fputwc`/`_fclose`. `int_convert.py` verified the macro count/stride and state/text offsets used by the profile writer. Confidence remains at `85` rather than higher because the original source filename and several field names remain open.
- 2026-06-12 C001 Batch C001-018:
  - Score unchanged at `87/85`.
  - Added exact sidecar string child [UID:0003IV][0x0061e964-0x0061e9fc.ProfileSidecarImageStrings](by-memory/0x0061e964-0x0061e9fc.ProfileSidecarImageStrings.md), split from the former mixed [UID:0002ST][0x0061e908-0x0061eadc.MapPaneResourceStrings](by-memory/0x0061e908-0x0061eadc.MapPaneResourceStrings.md) aggregate.
- 2026-06-17 B003 ProfileSidecarRefresh source-quality execution:
  - Score unchanged at `87/85`.
  - Resolved the sidecar filename stem as the local-player-name helper at `0x005a2dc0` / [UID:0002AA][0x0069bee0-0x0069bf20.LocalPlayerNameWideBuffer](by-memory/0x0069bee0-0x0069bf20.LocalPlayerNameWideBuffer.md), kept `g_pConfig + 0x2912b8` as the selected-profile packet field, and kept [UID:0001AS][0x005063e0-0x00506962.ProfileSidecarRefresh](by-memory/0x005063e0-0x00506962.ProfileSidecarRefresh.md) in `ProfileStorage.cpp` after rejecting ProfileDialog, MapPane, Socket, and ImageLoaders ownership alternatives.
- 2026-06-22 B013 ProfileLoadAndLegacyImport source-quality incorporation:
  - Before: `87/85`.
  - After: `88/87`.
  - Summary/evidence: B013 resolved `LoadUserProfileData` and `ImportLegacyUserProfileData` as zero-argument ProfileStorage helpers, rejected the apparent importer return and loader argument artifacts, confirmed fallback/import ordering, upgraded field-role names enough for first-draft source, and kept unresolved exact member spelling/original filename as non-blocking final-source caveats.
- 2026-07-14 B005 SaveUserSettings source-quality synchronization:
  - Score/path/owner and absence of a by-file formal block remain unchanged at `88/87`.
  - Replaced current address-suffixed naming with global `SaveUserSettings`, added all eight exact stream sections, failure/partial-write behavior, eight caller routes, raw OptionPane no-route/padding disposition, ownership negatives, and lexical confidence cap. Historical `SaveUserSettings_50ABA0` remains only as superseded search provenance.
