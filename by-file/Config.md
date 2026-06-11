*** UID:0000IE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/config/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

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
| `Config` | [UID:00030S][0x0048e550-0x0048e77a.ConfigConstructor](by-memory/0x0048e550-0x0048e77a.ConfigConstructor.md), `0x00494020-0x00494126` | `class_Config.cpp` | Base config object and deleting destructor in `config/Config.cpp`. |
| `ConfigEntryBlock` | `0x00494130-0x004941d6` | `class_ConfigEntryBlock.cpp` | Private/shared config-entry cleanup helper near `Config`. |
| `ConfigRawTableHelpers` | `0x0048e310-0x0048e479` | omitted/raw helper gap | Large fixed-table lookup/append and reset helpers near `Config`. |
| `InitializeConfigEntry` | [UID:00032D][0x0048e480-0x0048e4a8.ConfigEntryInitialize](by-memory/0x0048e480-0x0048e4a8.ConfigEntryInitialize.md) | `recovered/InitializeConfigEntry_0048E480.cpp` | Config-entry element constructor/helper. |
| `DestroyConfigEntry` helpers | [UID:00032E][0x0048e4b0-0x0048e54a.ConfigEntryDestroyHelpers](by-memory/0x0048e4b0-0x0048e54a.ConfigEntryDestroyHelpers.md) | `recovered/DestroyConfigEntry_0048E4B0.cpp` plus direct cleanup helper | Config-entry element destructor callback and direct scratch-entry cleanup helper used by server-select parsing. |
| Config-entry vector wrappers | [UID:00032H][0x0048ea70-0x0048ea9f.ConfigEntryVectorCopyWrappersRaw](by-memory/0x0048ea70-0x0048ea9f.ConfigEntryVectorCopyWrappersRaw.md) | omitted/raw helper gap | Raw wrappers forwarding the Config member at `this + 0x2912b4` to a shared copy helper. |
| Config string/preference helpers | [UID:00032I][0x0048eaa0-0x0048ebb3.ConfigStringPreferenceHelpers](by-memory/0x0048eaa0-0x0048ebb3.ConfigStringPreferenceHelpers.md) | omitted/private helpers | Selector lookup/setter and heap-backed string replacement helpers used by MIDI and UI/login/create-user consumers through `g_pConfig`. |
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
- `0x0048e4b0-0x0048e4fa` and `0x0048e500-0x0048e54a` config-entry destroy helpers.
- `0x0048e550-0x0048e77a` `Config::Config`, called from `0x004639d0`.
- `0x0048ea70-0x0048ea9f` raw config-entry vector wrapper pair, no IDA function object but complete code-shaped bodies using `this + 0x2912b4`.
- `0x0048eaa0-0x0048ebb3` Config string/preference helper cluster, called from MIDI and UI/login/create-user paths through `g_pConfig`.
- `0x0048e780-0x0048e85a` `RegistryConfig::~RegistryConfig`, called by the scalar deleting wrapper at `0x00467340`.
- `0x0048e860-0x0048e94f` `RegistryConfig::LoadOrInitialize`, called from `0x004639d0`.
- `0x0048ebc0-0x0048eecf` `RegistryConfig::InitializeUserDataDefaults`, called by `InitializeDefaults` and `LoadUserProfileData`.
- `0x0048eed0-0x0048f3f1` `RegistryConfig::InitializeDefaults`.
- `0x00491b30-0x00492695` `RegistryConfig::SaveToRegistry`.
- `0x004926a0-0x00493e29` `RegistryConfig::LoadFromRegistry`.
- `0x00494020-0x00494126` `Config::DeletingDestructor`.
- `0x00494130-0x004941d6` `ConfigEntryBlock::ReleaseOwnedBuffers`.

The raw helper cluster at [UID:00021Z][0x0048e310-0x0048e479.ConfigRawTableHelpers](by-memory/0x0048e310-0x0048e479.ConfigRawTableHelpers.md) is not currently emitted by `simroot_v2`; direct PE byte review identifies it as config table support immediately before `InitializeConfigEntry`.

The exact constructor child [UID:00030S][0x0048e550-0x0048e77a.ConfigConstructor](by-memory/0x0048e550-0x0048e77a.ConfigConstructor.md) is now assigned to [UID:000031][Config](by-class/Config.md), while the broader defaults aggregate remains mixed and unassigned.

B001-015 split [UID:000110][0x0048e480-0x0048f3f1.ConfigAndRegistryDefaults](by-memory/0x0048e480-0x0048f3f1.ConfigAndRegistryDefaults.md) into exact children. [UID:00032D][0x0048e480-0x0048e4a8.ConfigEntryInitialize](by-memory/0x0048e480-0x0048e4a8.ConfigEntryInitialize.md), [UID:00032E][0x0048e4b0-0x0048e54a.ConfigEntryDestroyHelpers](by-memory/0x0048e4b0-0x0048e54a.ConfigEntryDestroyHelpers.md), [UID:00032H][0x0048ea70-0x0048ea9f.ConfigEntryVectorCopyWrappersRaw](by-memory/0x0048ea70-0x0048ea9f.ConfigEntryVectorCopyWrappersRaw.md), and [UID:00032I][0x0048eaa0-0x0048ebb3.ConfigStringPreferenceHelpers](by-memory/0x0048eaa0-0x0048ebb3.ConfigStringPreferenceHelpers.md) attach here as private Config storage/preference helpers; the aggregate itself is now a non-emitting mixed inventory.

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
- 2026-06-10 B001-016 source-owner check: [UID:0002VB][0x00493e30-0x00493ef0.UnreferencedAdapterPhysicalAddressFormatterRaw](by-memory/0x00493e30-0x00493ef0.UnreferencedAdapterPhysicalAddressFormatterRaw.md) is not direct evidence for `Config.cpp`. It sits after the registry load method and before the exact Config destructor / entry-cleanup children, has no modeled function, no xrefs, and no callers, and the clone-like adapter physical-address formatting body does not reference the base `Config` constructor/destructor or `ConfigEntryBlock` cleanup path. B001-016 assigns it to [UID:0000N4][RegistryConfig](by-file/RegistryConfig.md) as a file-level raw helper/dead clone because its body duplicates `LoadFromRegistry` adapter physical-address formatting.

## Cross-References

- [UID:000031][Config](by-class/Config.md)
- [UID:000032][ConfigEntryBlock](by-class/ConfigEntryBlock.md)
- [UID:0000N4][RegistryConfig](by-file/RegistryConfig.md)
- [UID:0000BW][RegistryConfig](by-class/RegistryConfig.md)
- [UID:0000MS][ProfileStorage](by-file/ProfileStorage.md)
- [UID:00021Z][0x0048e310-0x0048e479.ConfigRawTableHelpers](by-memory/0x0048e310-0x0048e479.ConfigRawTableHelpers.md)
- [UID:00032D][0x0048e480-0x0048e4a8.ConfigEntryInitialize](by-memory/0x0048e480-0x0048e4a8.ConfigEntryInitialize.md)
- [UID:00032E][0x0048e4b0-0x0048e54a.ConfigEntryDestroyHelpers](by-memory/0x0048e4b0-0x0048e54a.ConfigEntryDestroyHelpers.md)
- [UID:00030S][0x0048e550-0x0048e77a.ConfigConstructor](by-memory/0x0048e550-0x0048e77a.ConfigConstructor.md)
- [UID:000110][0x0048e480-0x0048f3f1.ConfigAndRegistryDefaults](by-memory/0x0048e480-0x0048f3f1.ConfigAndRegistryDefaults.md)
- [UID:00032H][0x0048ea70-0x0048ea9f.ConfigEntryVectorCopyWrappersRaw](by-memory/0x0048ea70-0x0048ea9f.ConfigEntryVectorCopyWrappersRaw.md)
- [UID:00032I][0x0048eaa0-0x0048ebb3.ConfigStringPreferenceHelpers](by-memory/0x0048eaa0-0x0048ebb3.ConfigStringPreferenceHelpers.md)
- [UID:000111][0x00491b30-0x004941d6.RegistryPersistenceAndConfigEntryCleanup](by-memory/0x00491b30-0x004941d6.RegistryPersistenceAndConfigEntryCleanup.md)
- [UID:0002VB][0x00493e30-0x00493ef0.UnreferencedAdapterPhysicalAddressFormatterRaw](by-memory/0x00493e30-0x00493ef0.UnreferencedAdapterPhysicalAddressFormatterRaw.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-05-27: `ConfigEntryBlock` range changed from `0x00494130-0x004941d5` to `0x00494130-0x004941d6`. Evidence: IDA MCP `lookup_funcs` reports `sub_494130` size `0xa6`, and direct PE byte review places the final `ret` byte at `0x004941d5`.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:84`.
  - Summary/evidence: config/registry split, proposed source files, function inventory, raw table helpers, responsibilities, source-layout decision, and generated-output caveats are documented; confidence is strong but not complete because registry destructor/generated stub details still need final cleanup.
- 2026-06-02: Filled the validator projected path from the existing source-layout decision.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank even though the status, hypothesis, and source-layout sections place `Config.cpp` under `config/`.
  - After: projected path is `NexusTK/config/`, matching [UID:0000N4][RegistryConfig](by-file/RegistryConfig.md) and the proposed `config/Config.cpp` / `config/RegistryConfig.cpp` split.
  - Evidence: the page's proposed contents keep `Config`, `ConfigEntryBlock`, raw config-table helpers, and config-entry construction/destruction in the lower-level configuration module.
- 2026-06-02: Corrected the proposed contents display range for `Config::DeletingDestructor` from `0x00494020-0x00494125` to `0x00494020-0x00494126`.
  - Evidence: IDA MCP `lookup_funcs` reports `sub_494020` size `0x106`, and [UID:0002P9][0x00494020-0x00494126.ConfigDeletingDestructor](by-memory/0x00494020-0x00494126.ConfigDeletingDestructor.md) records the following `0x00494126-0x00494130` alignment gap.
- 2026-06-08 A010 Batch112: Raised confidence from `84` to `85`.
  - Before: the Config constructor was only documented through the mixed Config/RegistryConfig defaults aggregate, which blocked direct parent routing for the constructor child.
  - After: linked exact constructor child [UID:00030S][0x0048e550-0x0048e77a.ConfigConstructor](by-memory/0x0048e550-0x0048e77a.ConfigConstructor.md) and retained `NexusTK/config/` ownership.
  - Evidence: the exact child page isolates `Config::Config`, links `g_pConfig` lifecycle evidence and the matching deleting destructor, and assigns to [UID:000031][Config](by-class/Config.md), making the Config file/class parent chain meet the corrected `85/85` gate.
- 2026-06-08 A003 Batch113: Added a source-owner rejection note for [UID:0002VB][0x00493e30-0x00493ef0.UnreferencedAdapterPhysicalAddressFormatterRaw](by-memory/0x00493e30-0x00493ef0.UnreferencedAdapterPhysicalAddressFormatterRaw.md).
  - Before: the page documented the Config/RegistryConfig split but did not explicitly reject the adjacent raw adapter-formatting clone as base Config ownership.
  - After: the data caveats and cross-references state that `0002VB` is unreferenced and outside the direct base Config constructor/destructor/entry-cleanup ownership path.
  - Evidence: Batch113 IDA checks on `0x00493e30` and the mixed aggregate [UID:000111][0x00491b30-0x004941d6.RegistryPersistenceAndConfigEntryCleanup](by-memory/0x00491b30-0x004941d6.RegistryPersistenceAndConfigEntryCleanup.md).
- 2026-06-10 B001-015 split repair:
  - Changed to: no score change.
  - Summary/evidence: added exact Config helper children [UID:00032D][0x0048e480-0x0048e4a8.ConfigEntryInitialize](by-memory/0x0048e480-0x0048e4a8.ConfigEntryInitialize.md), [UID:00032E][0x0048e4b0-0x0048e54a.ConfigEntryDestroyHelpers](by-memory/0x0048e4b0-0x0048e54a.ConfigEntryDestroyHelpers.md), [UID:00032H][0x0048ea70-0x0048ea9f.ConfigEntryVectorCopyWrappersRaw](by-memory/0x0048ea70-0x0048ea9f.ConfigEntryVectorCopyWrappersRaw.md), and [UID:00032I][0x0048eaa0-0x0048ebb3.ConfigStringPreferenceHelpers](by-memory/0x0048eaa0-0x0048ebb3.ConfigStringPreferenceHelpers.md) after IDA MCP confirmed exact boundaries, xrefs/callers, raw wrapper bodies, and `g_pConfig` storage use. [UID:000110][0x0048e480-0x0048f3f1.ConfigAndRegistryDefaults](by-memory/0x0048e480-0x0048f3f1.ConfigAndRegistryDefaults.md) is now a non-emitting mixed inventory rather than a source parent.
- 2026-06-10 B001-016 split audit:
  - Changed to: no score change.
  - Summary/evidence: refreshed the [UID:0002VB][0x00493e30-0x00493ef0.UnreferencedAdapterPhysicalAddressFormatterRaw](by-memory/0x00493e30-0x00493ef0.UnreferencedAdapterPhysicalAddressFormatterRaw.md) rejection note. B001-016 keeps it out of Config ownership and assigns it to [UID:0000N4][RegistryConfig](by-file/RegistryConfig.md).
