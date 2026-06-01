*** UID:0000IE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# Config

## Status

- Confidence: strong for `config/Config.cpp` and `config/RegistryConfig.cpp` as lower-level configuration modules.
- Proposed module folder: `config/`
- Candidate files: `config/Config.cpp`, `config/RegistryConfig.cpp`, possibly `config/ConfigEntry.cpp`.
- Current generated sources: `class_Config.cpp`, `class_RegistryConfig.cpp`, `class_ConfigEntryBlock.cpp`, and recovered helpers under `simroot_v2/recovered`.
- Evidence basis: Wave3 class/global inspection, generated source review, and IDA MCP boundary checks on 2026-05-23.

## Hypothesis

The original client likely separated the low-level configuration object and registry-backed persistence from the profile file helpers. `Config` owns the large in-memory settings block and the process global `g_pConfig`; `RegistryConfig` extends that storage with registry load/save/default behavior; `ConfigEntryBlock` and the two free entry helpers are embedded storage-management details shared by both.

Preferred reconstruction:

```text
config/Config.cpp
config/Config.h
config/RegistryConfig.cpp
config/RegistryConfig.h
```

[UID:0000N4][RegistryConfig](by-file/RegistryConfig.md) is now tracked as the separate registry/default source candidate. `ConfigEntryBlock`, `ConfigEntry`, `InitializeConfigEntry`, and `DestroyConfigEntry` could be private implementation details in `Config.cpp`, unless header exposure is required by other modules.

## Proposed Contents

| Entity | Current range | Current file | Proposed ownership |
| --- | --- | --- | --- |
| `Config` | `0x0048e550-0x0048e779`, `0x00494020-0x00494125` | `class_Config.cpp` | Base config object and deleting destructor in `config/Config.cpp`. |
| `ConfigEntryBlock` | `0x00494130-0x004941d6` | `class_ConfigEntryBlock.cpp` | Private/shared config-entry cleanup helper near `Config`. |
| `ConfigRawTableHelpers` | `0x0048e310-0x0048e479` | omitted/raw helper gap | Large fixed-table lookup/append and reset helpers near `Config`. |
| `InitializeConfigEntry` | `0x0048e480-0x0048e4a8` | `recovered/InitializeConfigEntry_0048E480.cpp` | Config-entry element constructor. |
| `DestroyConfigEntry` | `0x0048e4b0-0x0048e4fa` | `recovered/DestroyConfigEntry_0048E4B0.cpp` | Config-entry element destructor. |
| `RegistryConfig` | `0x00467340-0x00493e28` | `class_RegistryConfig.cpp` | Registry-backed config subclass in [UID:0000N4][RegistryConfig](by-file/RegistryConfig.md). |

## Responsibilities

- `Config::Config` initializes the global config singleton, zeroes the 100-row fixed settings tables, constructs 32 config-entry records, initializes string/list storage, and clears display/file-name buffers.
- `Config::DeletingDestructor` releases the tracked list, heap-backed string/vector state, the embedded `ConfigEntryBlock`, each `ConfigEntry`, and then clears `g_pConfig`.
- `RegistryConfig::LoadOrInitialize` resets defaults, attempts registry load, falls back to defaults, and parses startup command-line state.
- `RegistryConfig::InitializeDefaults` sets built-in client defaults, screen-centered pane coordinates, option masks, and user-data defaults.
- `RegistryConfig::InitializeUserDataDefaults` resets the profile/user-data slice later overlaid by `.usr` and legacy `.cfg` profile files.
- `RegistryConfig::SaveToRegistry` and `RegistryConfig::LoadFromRegistry` own registry persistence for client options and server/adapter metadata.

## IDA MCP Evidence

IDA confirms these as real function starts:

- `0x0048e480-0x0048e4a8` `InitializeConfigEntry`.
- `0x0048e4b0-0x0048e4fa` `DestroyConfigEntry`.
- `0x0048e550-0x0048e77a` `Config::Config`, called from `0x004639d0`.
- `0x0048e780-0x0048e85a` `RegistryConfig::~RegistryConfig`, called by the scalar deleting wrapper at `0x00467340`.
- `0x0048e860-0x0048e94f` `RegistryConfig::LoadOrInitialize`, called from `0x004639d0`.
- `0x0048ebc0-0x0048eecf` `RegistryConfig::InitializeUserDataDefaults`, called by `InitializeDefaults` and `LoadUserProfileData`.
- `0x0048eed0-0x0048f3f1` `RegistryConfig::InitializeDefaults`.
- `0x00491b30-0x00492695` `RegistryConfig::SaveToRegistry`.
- `0x004926a0-0x00493e29` `RegistryConfig::LoadFromRegistry`.
- `0x00494020-0x00494126` `Config::DeletingDestructor`.
- `0x00494130-0x004941d6` `ConfigEntryBlock::ReleaseOwnedBuffers`.

The raw helper cluster at [UID:00021Z][0x0048e310-0x0048e479.ConfigRawTableHelpers](by-memory/0x0048e310-0x0048e479.ConfigRawTableHelpers.md) is not currently emitted by `simroot_v2`; direct PE byte review identifies it as config table support immediately before `InitializeConfigEntry`.

## Source-Layout Decision

Do not keep `RegistryConfig` and `ConfigEntryBlock` in `profile/ProfileStorage.cpp` as the earlier draft suggested. Profile file helpers depend on the user-data block owned by `RegistryConfig`, but the registry/default/config-entry code is lower-level configuration infrastructure.

Recommended split:

```text
config/Config.cpp
config/RegistryConfig.cpp
profile/ProfileStorage.cpp
```

`profile/ProfileStorage.cpp` should include or reference `RegistryConfig` for default reset and field offsets, but it should not own the class implementation.

## Data Caveats

- `class_RegistryConfig.cpp` currently emits only stubs/structs for `SaveToRegistry` and `LoadFromRegistry` even though Wave3 method metadata grades them and IDA confirms their ranges. This is tracked in `../wave3_data_issues.md`.
- `RegistryConfig::~RegistryConfig` has lower Wave3 grade than the rest of the cluster, so destructor details should be reviewed before final source cleanup.

## Cross-References

- [UID:000031][Config](by-class/Config.md)
- [UID:000032][ConfigEntryBlock](by-class/ConfigEntryBlock.md)
- [UID:0000N4][RegistryConfig](by-file/RegistryConfig.md)
- [UID:0000BW][RegistryConfig](by-class/RegistryConfig.md)
- [UID:0000MS][ProfileStorage](by-file/ProfileStorage.md)
- [UID:00021Z][0x0048e310-0x0048e479.ConfigRawTableHelpers](by-memory/0x0048e310-0x0048e479.ConfigRawTableHelpers.md)
- [UID:000110][0x0048e480-0x0048f3f1.ConfigAndRegistryDefaults](by-memory/0x0048e480-0x0048f3f1.ConfigAndRegistryDefaults.md)
- [UID:000111][0x00491b30-0x004941d6.RegistryPersistenceAndConfigEntryCleanup](by-memory/0x00491b30-0x004941d6.RegistryPersistenceAndConfigEntryCleanup.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-05-27: `ConfigEntryBlock` range changed from `0x00494130-0x004941d5` to `0x00494130-0x004941d6`. Evidence: IDA MCP `lookup_funcs` reports `sub_494130` size `0xa6`, and direct PE byte review places the final `ret` byte at `0x004941d5`.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:84`.
  - Summary/evidence: config/registry split, proposed source files, function inventory, raw table helpers, responsibilities, source-layout decision, and generated-output caveats are documented; confidence is strong but not complete because registry destructor/generated stub details still need final cleanup.
