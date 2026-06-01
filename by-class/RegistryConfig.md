*** UID:0000BW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# RegistryConfig

## Status

- Confidence: strong for config-module ownership, medium for exact original file split.
- Likely source module: [UID:0000N4][RegistryConfig](by-file/RegistryConfig.md), with base storage in [UID:0000IE][Config](by-file/Config.md).
- Current file: `class_RegistryConfig.cpp`
- Current range: `0x00467340-0x00493e28`
- Evidence basis: Wave3 class inspection, generated source, profile-storage globals, and IDA MCP boundary checks on 2026-05-23.

## Responsibility

`RegistryConfig` is the registry-backed configuration subclass. It resets built-in defaults, reads and writes the Windows registry configuration, owns/defaults the large user-data block, and exposes the default-reset routine used by profile file loading.

It is related to profile persistence, but it should not be owned by `profile/ProfileStorage.cpp`. The better split is:

```text
config/RegistryConfig.cpp
profile/ProfileStorage.cpp
```

The profile/user-data slice inside this object is now tracked as [UID:0001VR][RegistryConfigUserProfileBlock](by-type/by-struct/RegistryConfigUserProfileBlock.md), and the corresponding `.usr` / legacy `.cfg` formats are tracked in [UID:0001QL][client_profile_storage](by-meta/client_profile_storage.md).

## Methods

| Address | Method | Role |
| --- | --- | --- |
| `0x00467340` | `ScalarDeletingDestructor(unsigned char flags)` | Wrapper that calls the real destructor and conditionally deletes the object. |
| `0x0048e780` | `~RegistryConfig()` | Releases registry/key handle state, string/vector members, config-entry storage, clears `g_pConfig`, and destroys the base. |
| `0x0048e860` | `LoadOrInitialize()` | Resets defaults, attempts registry load, falls back to defaults, and normalizes command-line startup state. |
| `0x0048f400-0x00491b28` | command-line/session helpers | Helper island for login/session modes, hostname/port parsing, and mode flags used around startup config. |
| `0x0048ebc0` | `InitializeUserDataDefaults()` | Resets the [UID:0001VR][RegistryConfigUserProfileBlock](by-type/by-struct/RegistryConfigUserProfileBlock.md) before `.usr` or legacy `.cfg` data is applied. |
| `0x0048eed0` | `InitializeDefaults()` | Applies built-in client defaults, centered pane positions, option masks, and user-data defaults. |
| `0x00491b30` | `SaveToRegistry()` | Saves current client configuration and server lists to Kingdom of the Winds registry keys. |
| `0x004926a0` | `LoadFromRegistry()` | Loads configuration from registry, seeds CLSID if needed, and rebuilds adapter/server metadata. |

## Ownership Notes

- `LoadUserProfileData` calls `RegistryConfig::InitializeUserDataDefaults` before reading a user profile file.
- `SaveUserSettings_50ABA0` serializes fields from the same user-data block, but it remains a profile-file helper rather than a registry/config class method.
- `LoadFromRegistry` calls [UID:0000L6][MD5](by-file/MD5.md) helper `0x005153e0` at `0x004928ba` to fill a 16-byte digest buffer during registry/CLSID setup. Keep that helper in the shared MD5 utility module.
- `ConfigEntryBlock` is embedded in both `Config` and `RegistryConfig`, so its helpers belong near `Config`/`RegistryConfig`.

## Data Caveats

- `class_RegistryConfig.cpp` currently omits the actual source bodies for `SaveToRegistry` and `LoadFromRegistry`; only struct/stub material is emitted after their markers. Wave3 metadata and IDA ranges still confirm the methods exist. Track the emission defect under [UID:0000VD][ScopedMarkerMissingMethodBodies](by-item/ScopedMarkerMissingMethodBodies.md).
- `~RegistryConfig` is marked `needs_attention` by Wave3 inspection and should be reviewed before final code migration.
- 2026-05-25 IDA recheck: `SaveToRegistry` opens `Software\Nexon\Kingdom of the Winds`, writes option/state values, recent strings, `Color%d`, `MultiServerAddr%d`, `MultiServerName%d`, `MultiServerDesc%d`, and `MultiServerAgreement%d` values, then closes keys. `LoadFromRegistry` seeds/reads a CLSID value and loads the same registry family.
- 2026-05-27 gap pass: [UID:000220][0x0048f400-0x00491b28.RegistryCommandLineParsers](by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md) now records the previously UNKNOWN command-line/session parser island between defaults and registry persistence.
- 2026-05-30 split pass: the command-line/session helper island is now split into exact by-memory child pages under [UID:000220][0x0048f400-0x00491b28.RegistryCommandLineParsers](by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md). The helpers still look like config-adjacent launcher/bootstrap routines, not confirmed `RegistryConfig` methods.
- 2026-06-01 split pass: `SaveToRegistry` and `LoadFromRegistry` now have exact child memory pages at [UID:0002P7][0x00491b30-0x00492695.RegistryConfigSaveToRegistry](by-memory/0x00491b30-0x00492695.RegistryConfigSaveToRegistry.md) and [UID:0002P8][0x004926a0-0x00493e29.RegistryConfigLoadFromRegistry](by-memory/0x004926a0-0x00493e29.RegistryConfigLoadFromRegistry.md). The adjacent cleanup functions after the load body are tracked separately as [UID:0002P9][0x00494020-0x00494126.ConfigDeletingDestructor](by-memory/0x00494020-0x00494126.ConfigDeletingDestructor.md) and [UID:0002PA][0x00494130-0x004941d6.ConfigEntryBlockReleaseOwnedBuffers](by-memory/0x00494130-0x004941d6.ConfigEntryBlockReleaseOwnedBuffers.md).
- 2026-05-25 MD5 pass: `LoadFromRegistry` has a direct call to `Md5BytesToBuffer` at `0x005153e0`, confirming a config-to-utility dependency.
- Current `simroot_v2/class_RegistryConfig.cpp` still has omitted-body markers at `0x00491b30` and `0x004926a0`.

## Cross-References

- [UID:0000N4][RegistryConfig](by-file/RegistryConfig.md)
- [UID:0000IE][Config](by-file/Config.md)
- [UID:0000L6][MD5](by-file/MD5.md)
- [UID:0000MS][ProfileStorage](by-file/ProfileStorage.md)
- [UID:0001QL][client_profile_storage](by-meta/client_profile_storage.md)
- [UID:0001VR][RegistryConfigUserProfileBlock](by-type/by-struct/RegistryConfigUserProfileBlock.md)
- [UID:0000VD][ScopedMarkerMissingMethodBodies](by-item/ScopedMarkerMissingMethodBodies.md)
- [UID:000110][0x0048e480-0x0048f3f1.ConfigAndRegistryDefaults](by-memory/0x0048e480-0x0048f3f1.ConfigAndRegistryDefaults.md)
- [UID:000220][0x0048f400-0x00491b28.RegistryCommandLineParsers](by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md)
- [UID:000111][0x00491b30-0x004941d6.RegistryPersistenceAndConfigEntryCleanup](by-memory/0x00491b30-0x004941d6.RegistryPersistenceAndConfigEntryCleanup.md)
- [UID:0002P7][0x00491b30-0x00492695.RegistryConfigSaveToRegistry](by-memory/0x00491b30-0x00492695.RegistryConfigSaveToRegistry.md)
- [UID:0002P8][0x004926a0-0x00493e29.RegistryConfigLoadFromRegistry](by-memory/0x004926a0-0x00493e29.RegistryConfigLoadFromRegistry.md)
- [UID:0002P9][0x00494020-0x00494126.ConfigDeletingDestructor](by-memory/0x00494020-0x00494126.ConfigDeletingDestructor.md)
- [UID:0002PA][0x00494130-0x004941d6.ConfigEntryBlockReleaseOwnedBuffers](by-memory/0x00494130-0x004941d6.ConfigEntryBlockReleaseOwnedBuffers.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-05-30: Changed completion/confidence from `0/0` to `80/76`.
  - Before: The page was unevaluated despite documenting responsibility, methods, ownership, profile/config split, data caveats, helper islands, and persistence dependencies.
  - After: Scored as high completion with medium-high confidence because `SaveToRegistry`/`LoadFromRegistry` still have generated omitted-body defects and the exact original file split remains partly inferred.
  - Evidence: Existing method table, ownership notes, data caveats, IDA recheck notes, command-line parser split, MD5 dependency, profile-block references, and memory/type/meta cross-references support the score.
