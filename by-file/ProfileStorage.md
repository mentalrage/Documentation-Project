*** UID:0000MS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/profile/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ProfileStorage

## Status

- Confidence: strong for profile file helper grouping, medium for exact original filename.
- Proposed module: `profile/ProfileStorage.cpp`
- Related config module: [UID:0000IE][Config](by-file/Config.md)
- Related UI callers: `ProfileDialog`, `ProfilePane`, `FriendListDialog`, and other settings dialogs that trigger profile save/refresh.
- Evidence basis: existing profile-storage documentation and IDA MCP caller/callee/decompile checks through 2026-06-01.

## Hypothesis

The user-profile persistence helpers should be grouped as a profile storage module, not left as one-function generated files. They operate on the `RegistryConfig` user-data block through `g_pConfig` or the equivalent global pointer, but their file responsibility is profile file IO and profile-side refresh packets.

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
| `RefreshSelectedProfileData` | `0x005063e0-0x00506962` | `recovered/RefreshSelectedProfileData_005063E0.cpp` | Finds/normalizes selected profile sidecar assets, reads a `.jpf` blob when present, validates it through [UID:000175][0x004d05f0-0x004d0c57.ImageDecodeWrappers](by-memory/0x004d05f0-0x004d0c57.ImageDecodeWrappers.md), and queues profile refresh packet `79`. |
| `SaveUserSettings_50ABA0` | `0x0050aba0-0x0050b078` | `recovered/SaveUserSettings_0050ABA0.cpp` | Serializes the current profile/settings block, including [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md) rows, to `Documents\NexusTK\users\<player>.usr`. |

## File Format And Paths

- Modern profile files live under `Documents\NexusTK\users` and use a `.usr` extension.
- `LoadUserProfileData` also checks the current-directory `users/<name>.usr` fallback.
- Legacy migration reads current-directory `users\<name>.cfg` as quoted wide strings, copies the data into the same config user-data offsets, and deletes the legacy file after success.
- `SaveUserSettings_50ABA0` writes length-prefixed wide-string groups, dynamic string vector entries, compact shortcut records, 30 [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md) rows, and two trailing flag pairs.
- [UID:0001QL][client_profile_storage](by-meta/client_profile_storage.md) now records the `.usr` binary layout, legacy `.cfg` import format, shortcut migration, selected-profile sidecar behavior, and caller evidence.
- [UID:0001VR][RegistryConfigUserProfileBlock](by-type/by-struct/RegistryConfigUserProfileBlock.md) records the current offset map for the user-profile/settings slice inside `RegistryConfig`.
- [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md) records the integrated macro/hotkey row layout at `g_pConfig + 0x28f2ec + i * 0x108`.
- `RefreshSelectedProfileData` probes sidecar image extensions (`bmp`, `pcx`, `jpg`, `jpeg`, `pnm`), runs `FaceRipper.exe` for a found sidecar, then reads `<profile>.jpf` from the documents folder or `./users`.
- The `.jpf` validation path calls the shared [UID:000175][0x004d05f0-0x004d0c57.ImageDecodeWrappers](by-memory/0x004d05f0-0x004d0c57.ImageDecodeWrappers.md) at `0x004d07b0`, then only includes the profile name when the decoded tile-context span matches the expected portrait dimensions.

## IDA MCP Evidence

IDA confirms these as real function starts:

- `0x004f9280-0x004f95a2` `ImportLegacyUserProfileData`, called only from `LoadUserProfileData`.
- `0x004f95b0-0x004f9d28` `LoadUserProfileData`, called from `0x004f7d10` during main UI graph initialization.
- `0x005063e0-0x00506962` `RefreshSelectedProfileData`, called from `0x00507c90`, `0x0053fdc0`, and `0x0053fe90`.
- `0x0050aba0-0x0050b078` `SaveUserSettings_50ABA0`, called from seven currently visible UI/settings paths including `0x0053f830`.

## Placement Decision

Recommended split:

```text
config/Config.cpp
config/RegistryConfig.cpp
profile/ProfileStorage.cpp
profile/ProfileDialog.cpp
```

`ProfileDialog` and `ProfilePane` should remain UI/profile modules that call into `ProfileStorage`; they should not own the file serialization logic. `RefreshSelectedProfileData` is shared by profile UI and a packet-driven `MapPane` path, but its file path and selected-profile behavior make `profile/ProfileStorage.cpp` a better initial owner than map UI. See [UID:0000MR][ProfileDialog](by-file/ProfileDialog.md) for the dialog-side split.

## Open Questions

- Whether the original filename was `ProfileStorage.cpp`, `UserProfile.cpp`, or a Korean/legacy naming equivalent.
- Whether `RefreshSelectedProfileData` should be split into `ProfileImage.cpp` or a small profile-network helper after packet send ownership is cleaned up.
- Final names for the remaining `.usr` profile fields are still open; the format and current offsets are tracked in [UID:0001QL][client_profile_storage](by-meta/client_profile_storage.md), [UID:0001VR][RegistryConfigUserProfileBlock](by-type/by-struct/RegistryConfigUserProfileBlock.md), and [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md).

## Cross-References

- [UID:0000IE][Config](by-file/Config.md)
- [UID:0000BW][RegistryConfig](by-class/RegistryConfig.md)
- [UID:00019T][0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport](by-memory/0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport.md)
- [UID:0001AS][0x005063e0-0x00506962.ProfileSidecarRefresh](by-memory/0x005063e0-0x00506962.ProfileSidecarRefresh.md)
- [UID:000175][0x004d05f0-0x004d0c57.ImageDecodeWrappers](by-memory/0x004d05f0-0x004d0c57.ImageDecodeWrappers.md)
- [UID:0001AV][0x0050aba0-0x0050b078.SaveUserSettings](by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md)
- [UID:0001QL][client_profile_storage](by-meta/client_profile_storage.md)
- [UID:0001VR][RegistryConfigUserProfileBlock](by-type/by-struct/RegistryConfigUserProfileBlock.md)
- [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `86`, confidence `80`.
- Summary/evidence: the page documents profile-storage grouping, file formats/paths, IDA caller evidence, placement decision, open questions, related type/meta docs, and cross-references; confidence remains capped by exact original filename and unresolved field names.
