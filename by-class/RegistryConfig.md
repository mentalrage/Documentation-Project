*** UID:0000BW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000N4 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# RegistryConfig

## Status

- Confidence: strong for config-module ownership, live method anchors, vtable slots, exact default/load and persistence child docs, and profile-block relationships; medium-high for final helper naming/source split.
- Likely source module: [UID:0000N4][RegistryConfig](by-file/RegistryConfig.md), with base storage in [UID:0000IE][Config](by-file/Config.md).
- Current relevant ranges: scalar deleting wrapper [UID:000329][0x00467340-0x0046737b.RegistryConfigScalarDeletingDestructor](by-memory/0x00467340-0x0046737b.RegistryConfigScalarDeletingDestructor.md), RegistryConfig body methods `0x0048e780-0x00493e29`, and adjacent Config cleanup helpers `0x00494020-0x004941d6`.
- Evidence basis: live IDA MCP function, vtable, global-ref, and caller checks through 2026-06-04 plus exact child memory docs.
- Reconstructable: yes, attached to [UID:0000N4][RegistryConfig](by-file/RegistryConfig.md). Final C++ remains blank because the registry persistence bodies and helper names are still below the `95/95` reconstruction bar.

## Responsibility

`RegistryConfig` is the registry-backed configuration subclass. It resets built-in defaults, reads and writes the Windows registry configuration, owns/defaults the large user-data block, and exposes the default-reset routine used by profile file loading.

It is related to profile persistence, but it should not be owned by `profile/ProfileStorage.cpp`. The better split is:

```text
config/RegistryConfig.cpp
profile/ProfileStorage.cpp
```

The profile/user-data slice inside this object is now tracked as [UID:0001VR][RegistryConfigUserProfileBlock](by-type/by-struct/RegistryConfigUserProfileBlock.md), and the corresponding `.usr` / legacy `.cfg` formats are tracked in [UID:0001QL][client_profile_storage](by-meta/client_profile_storage.md).

## Methods

| Range | Method | Role |
| --- | --- | --- |
| [UID:000329][0x00467340-0x0046737b.RegistryConfigScalarDeletingDestructor](by-memory/0x00467340-0x0046737b.RegistryConfigScalarDeletingDestructor.md) | `ScalarDeletingDestructor(unsigned char flags)` | Wrapper that calls the real destructor and conditionally deletes the object. |
| [UID:00032F][0x0048e780-0x0048e85a.RegistryConfigDestructor](by-memory/0x0048e780-0x0048e85a.RegistryConfigDestructor.md) | `~RegistryConfig()` | Releases registry/key handle state, string/vector members, config-entry storage, clears `g_pConfig`, and destroys the base. |
| [UID:00030U][0x0048e860-0x0048e94f.RegistryConfigLoadOrInitialize](by-memory/0x0048e860-0x0048e94f.RegistryConfigLoadOrInitialize.md) | `LoadOrInitialize()` | Resets defaults, attempts registry load, falls back to defaults, and normalizes command-line startup state. |
| `0x0048f400-0x00491b28` | command-line/session helpers | Helper island for login/session modes, hostname/port parsing, and mode flags used around startup config. |
| [UID:00030W][0x0048ebc0-0x0048eecf.RegistryConfigInitializeUserDataDefaults](by-memory/0x0048ebc0-0x0048eecf.RegistryConfigInitializeUserDataDefaults.md) | `InitializeUserDataDefaults()` | Resets the [UID:0001VR][RegistryConfigUserProfileBlock](by-type/by-struct/RegistryConfigUserProfileBlock.md) before `.usr` or legacy `.cfg` data is applied. |
| [UID:00030Y][0x0048eed0-0x0048f3f1.RegistryConfigInitializeDefaults](by-memory/0x0048eed0-0x0048f3f1.RegistryConfigInitializeDefaults.md) | `InitializeDefaults()` | Applies built-in client defaults, centered pane positions, option masks, and user-data defaults. |
| [UID:0002P7][0x00491b30-0x00492695.RegistryConfigSaveToRegistry](by-memory/0x00491b30-0x00492695.RegistryConfigSaveToRegistry.md) | `SaveToRegistry()` | Saves current client configuration and server lists to Kingdom of the Winds registry keys; assigned directly here after the child reached `85/88`. |
| [UID:0002P8][0x004926a0-0x00493e29.RegistryConfigLoadFromRegistry](by-memory/0x004926a0-0x00493e29.RegistryConfigLoadFromRegistry.md) | `LoadFromRegistry()` | Loads configuration from registry, seeds CLSID if needed, and rebuilds adapter/server metadata; assigned directly here after the child reached `85/87`. |

## Ownership Notes

- `LoadUserProfileData` calls `RegistryConfig::InitializeUserDataDefaults` before reading a user profile file.
- `SaveUserSettings_50ABA0` serializes fields from the same user-data block, but it remains a profile-file helper rather than a registry/config class method.
- `LoadFromRegistry` calls [UID:0000L6][MD5](by-file/MD5.md) helper `0x005153e0` at `0x004928ba` to fill a 16-byte digest buffer during registry/CLSID setup. Keep that helper in the shared MD5 utility module.
- [UID:0002VB][0x00493e30-0x00493ef0.UnreferencedAdapterPhysicalAddressFormatterRaw](by-memory/0x00493e30-0x00493ef0.UnreferencedAdapterPhysicalAddressFormatterRaw.md) mirrors part of `LoadFromRegistry`'s adapter physical-address formatting, but it begins after `LoadFromRegistry`'s modeled end, has no direct xrefs/callers, remains not an IDA function, and has no class `this` evidence. B001-016 assigns it to the [UID:0000N4][RegistryConfig](by-file/RegistryConfig.md) file as a private raw helper/dead clone, not as a direct class method.
- `ConfigEntryBlock` is embedded in both `Config` and `RegistryConfig`, so its helpers belong near `Config`/`RegistryConfig`.
- [UID:00032G][0x0048e950-0x0048ea6e.RegistryConfigTypeProbeRaw](by-memory/0x0048e950-0x0048ea6e.RegistryConfigTypeProbeRaw.md) is a private `RegistryConfig.cpp` raw helper, not a class method: IDA shows no function object or direct xrefs, but the body opens the Kingdom of the Winds registry key, reads the `Type` value, and returns a byte result.

## Evidence Notes

- Live IDA on 2026-06-04 confirms `0x00467340-0x0046737b`, `0x0048e780-0x0048e85a`, `0x0048e860-0x0048e94f`, `0x0048ebc0-0x0048eecf`, `0x0048eed0-0x0048f3f1`, `0x00491b30-0x00492695`, `0x004926a0-0x00493e29`, `0x00494020-0x00494126`, and `0x00494130-0x004941d6` as modeled function ranges.
- RegistryConfig RTTI/vtable data starts at `0x00612610`; slot `0x00612614` points to scalar deleting wrapper `0x00467340`, slot `0x00612620` points to `SaveToRegistry`, and slot `0x00612624` points to `LoadFromRegistry`. The vtable is installed/read at `0x0046413b`.
- 2026-06-10 B001-014 split of [UID:0000YU][0x004671a0-0x004673f6.ApplicationFunctionObject0Callbacks](by-memory/0x004671a0-0x004673f6.ApplicationFunctionObject0Callbacks.md) created exact child [UID:000329][0x00467340-0x0046737b.RegistryConfigScalarDeletingDestructor](by-memory/0x00467340-0x0046737b.RegistryConfigScalarDeletingDestructor.md). IDA MCP confirms the body calls `0x0048e780` (`~RegistryConfig`), conditionally deletes through `0x004f4ac0`, and is referenced by the RegistryConfig vtable slot at `0x00612614`.
- 2026-06-10 B001-015 created exact child [UID:00032F][0x0048e780-0x0048e85a.RegistryConfigDestructor](by-memory/0x0048e780-0x0048e85a.RegistryConfigDestructor.md). IDA MCP confirms the non-deleting destructor body, scalar-wrapper caller at `0x00467346`, `ConfigEntryBlock::ReleaseOwnedBuffers` call, config-entry destructor callback use, and `g_pConfig` clear.
- Live IDA reports `g_pConfig` storage at `0x0067a7c8` with 433 data refs across startup, UI, profile, network, audio, and packet code, matching the class's global configuration role.
- Source-output artifacts still omit the full `SaveToRegistry` and `LoadFromRegistry` bodies after their source markers; exact child docs now carry the reliable IDA-backed behavior until final reconstruction.
- `~RegistryConfig` still needs final source-quality review before C++ migration, but the live destructor range and scalar wrapper relationship are now documented.
- 2026-05-25 IDA recheck: `SaveToRegistry` opens `Software\Nexon\Kingdom of the Winds`, writes option/state values, recent strings, `Color%d`, `MultiServerAddr%d`, `MultiServerName%d`, `MultiServerDesc%d`, and `MultiServerAgreement%d` values, then closes keys. `LoadFromRegistry` seeds/reads a CLSID value and loads the same registry family.
- 2026-05-27 gap pass: [UID:000220][0x0048f400-0x00491b28.RegistryCommandLineParsers](by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md) now records the previously UNKNOWN command-line/session parser island between defaults and registry persistence.
- 2026-05-30 split pass: the command-line/session helper island is now split into exact by-memory child pages under [UID:000220][0x0048f400-0x00491b28.RegistryCommandLineParsers](by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md). The helpers still look like config-adjacent launcher/bootstrap routines, not confirmed `RegistryConfig` methods.
- 2026-06-01 split pass: `SaveToRegistry` and `LoadFromRegistry` now have exact child memory pages at [UID:0002P7][0x00491b30-0x00492695.RegistryConfigSaveToRegistry](by-memory/0x00491b30-0x00492695.RegistryConfigSaveToRegistry.md) and [UID:0002P8][0x004926a0-0x00493e29.RegistryConfigLoadFromRegistry](by-memory/0x004926a0-0x00493e29.RegistryConfigLoadFromRegistry.md). The adjacent cleanup functions after the load body are tracked separately as [UID:0002P9][0x00494020-0x00494126.ConfigDeletingDestructor](by-memory/0x00494020-0x00494126.ConfigDeletingDestructor.md) and [UID:0002PA][0x00494130-0x004941d6.ConfigEntryBlockReleaseOwnedBuffers](by-memory/0x00494130-0x004941d6.ConfigEntryBlockReleaseOwnedBuffers.md).
- 2026-05-25 MD5 pass: `LoadFromRegistry` has a direct call to `Md5BytesToBuffer` at `0x005153e0`, confirming a config-to-utility dependency.
- 2026-06-08 A010 Batch112 split pass: the load/default methods now have exact direct-child pages. [UID:00030U][0x0048e860-0x0048e94f.RegistryConfigLoadOrInitialize](by-memory/0x0048e860-0x0048e94f.RegistryConfigLoadOrInitialize.md), [UID:00030W][0x0048ebc0-0x0048eecf.RegistryConfigInitializeUserDataDefaults](by-memory/0x0048ebc0-0x0048eecf.RegistryConfigInitializeUserDataDefaults.md), and [UID:00030Y][0x0048eed0-0x0048f3f1.RegistryConfigInitializeDefaults](by-memory/0x0048eed0-0x0048f3f1.RegistryConfigInitializeDefaults.md) are assigned to this class after each child and this class cleared the corrected `85/85` gate. The broader [UID:000110][0x0048e480-0x0048f3f1.ConfigAndRegistryDefaults](by-memory/0x0048e480-0x0048f3f1.ConfigAndRegistryDefaults.md) aggregate remains unassigned because it also contains base `Config`, config-entry, raw helper, and padding spans.
- 2026-06-10 B001-016 direct-owner check: IDA MCP still reports no function, xrefs, or callers for `0x00493e30`; the raw bytes sit after seven `0xcc` bytes following `LoadFromRegistry` and before [UID:0002VA][0x00493ef0-0x00493efb.ConfigGlobalClearUnwindHelper](by-memory/0x00493ef0-0x00493efb.ConfigGlobalClearUnwindHelper.md). This rejects [UID:0002VB][0x00493e30-0x00493ef0.UnreferencedAdapterPhysicalAddressFormatterRaw](by-memory/0x00493e30-0x00493ef0.UnreferencedAdapterPhysicalAddressFormatterRaw.md) as a direct class-owned method, but B001-016 accepts [UID:0000N4][RegistryConfig](by-file/RegistryConfig.md) as the direct file-level owner because the body duplicates the adapter physical-address formatting block inside `LoadFromRegistry`.
- 2026-06-08 A010 Batch120 strict-gate repair: [UID:0002P7][0x00491b30-0x00492695.RegistryConfigSaveToRegistry](by-memory/0x00491b30-0x00492695.RegistryConfigSaveToRegistry.md) and [UID:0002P8][0x004926a0-0x00493e29.RegistryConfigLoadFromRegistry](by-memory/0x004926a0-0x00493e29.RegistryConfigLoadFromRegistry.md) now assign directly to this class after reaching `85/88` and `85/87`; this class remains `87/87` and [UID:0000N4][RegistryConfig](by-file/RegistryConfig.md) remains `88/85`, so the corrected child-and-parent gate is satisfied.

## Cross-References

- [UID:0000N4][RegistryConfig](by-file/RegistryConfig.md)
- [UID:0000IE][Config](by-file/Config.md)
- [UID:0000L6][MD5](by-file/MD5.md)
- [UID:0000MS][ProfileStorage](by-file/ProfileStorage.md)
- [UID:0001QL][client_profile_storage](by-meta/client_profile_storage.md)
- [UID:0001VR][RegistryConfigUserProfileBlock](by-type/by-struct/RegistryConfigUserProfileBlock.md)
- [UID:0000VD][ScopedMarkerMissingMethodBodies](by-item/ScopedMarkerMissingMethodBodies.md)
- [UID:000110][0x0048e480-0x0048f3f1.ConfigAndRegistryDefaults](by-memory/0x0048e480-0x0048f3f1.ConfigAndRegistryDefaults.md)
- [UID:00030U][0x0048e860-0x0048e94f.RegistryConfigLoadOrInitialize](by-memory/0x0048e860-0x0048e94f.RegistryConfigLoadOrInitialize.md)
- [UID:00032F][0x0048e780-0x0048e85a.RegistryConfigDestructor](by-memory/0x0048e780-0x0048e85a.RegistryConfigDestructor.md)
- [UID:00032G][0x0048e950-0x0048ea6e.RegistryConfigTypeProbeRaw](by-memory/0x0048e950-0x0048ea6e.RegistryConfigTypeProbeRaw.md)
- [UID:00030W][0x0048ebc0-0x0048eecf.RegistryConfigInitializeUserDataDefaults](by-memory/0x0048ebc0-0x0048eecf.RegistryConfigInitializeUserDataDefaults.md)
- [UID:00030Y][0x0048eed0-0x0048f3f1.RegistryConfigInitializeDefaults](by-memory/0x0048eed0-0x0048f3f1.RegistryConfigInitializeDefaults.md)
- [UID:000329][0x00467340-0x0046737b.RegistryConfigScalarDeletingDestructor](by-memory/0x00467340-0x0046737b.RegistryConfigScalarDeletingDestructor.md)
- [UID:000220][0x0048f400-0x00491b28.RegistryCommandLineParsers](by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md)
- [UID:000111][0x00491b30-0x004941d6.RegistryPersistenceAndConfigEntryCleanup](by-memory/0x00491b30-0x004941d6.RegistryPersistenceAndConfigEntryCleanup.md)
- [UID:0002P7][0x00491b30-0x00492695.RegistryConfigSaveToRegistry](by-memory/0x00491b30-0x00492695.RegistryConfigSaveToRegistry.md)
- [UID:0002P8][0x004926a0-0x00493e29.RegistryConfigLoadFromRegistry](by-memory/0x004926a0-0x00493e29.RegistryConfigLoadFromRegistry.md)
- [UID:0002VB][0x00493e30-0x00493ef0.UnreferencedAdapterPhysicalAddressFormatterRaw](by-memory/0x00493e30-0x00493ef0.UnreferencedAdapterPhysicalAddressFormatterRaw.md)
- [UID:0002P9][0x00494020-0x00494126.ConfigDeletingDestructor](by-memory/0x00494020-0x00494126.ConfigDeletingDestructor.md)
- [UID:0002PA][0x00494130-0x004941d6.ConfigEntryBlockReleaseOwnedBuffers](by-memory/0x00494130-0x004941d6.ConfigEntryBlockReleaseOwnedBuffers.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-06-10 B001-014 scalar deleting destructor split:
  - Score unchanged at `87/87`.
  - Replaced raw `0x00467340-0x0046737b` references with exact child [UID:000329][0x00467340-0x0046737b.RegistryConfigScalarDeletingDestructor](by-memory/0x00467340-0x0046737b.RegistryConfigScalarDeletingDestructor.md).
  - Evidence: IDA MCP confirms the wrapper calls `~RegistryConfig`, conditionally frees the object, and is the vtable slot at `0x00612614`.
- 2026-06-10 B001-015 destructor/type-probe split:
  - Score unchanged at `87/87`.
  - Replaced raw `0x0048e780-0x0048e85a` destructor references with exact child [UID:00032F][0x0048e780-0x0048e85a.RegistryConfigDestructor](by-memory/0x0048e780-0x0048e85a.RegistryConfigDestructor.md), and added file-helper cross-reference [UID:00032G][0x0048e950-0x0048ea6e.RegistryConfigTypeProbeRaw](by-memory/0x0048e950-0x0048ea6e.RegistryConfigTypeProbeRaw.md).
  - Evidence: B001-015 IDA MCP confirms the destructor boundary/caller/cleanup path and the raw registry `Type` probe body. [UID:00032G][0x0048e950-0x0048ea6e.RegistryConfigTypeProbeRaw](by-memory/0x0048e950-0x0048ea6e.RegistryConfigTypeProbeRaw.md) is attached to the RegistryConfig file parent rather than this class because it has no `this` parameter and no function object.

- 2026-05-30: Changed completion/confidence from `0/0` to `80/76`.
  - Before: The page was unevaluated despite documenting responsibility, methods, ownership, profile/config split, data caveats, helper islands, and persistence dependencies.
  - After: Scored as high completion with medium-high confidence because `SaveToRegistry`/`LoadFromRegistry` still have source-output omitted-body defects and the exact original file split remains partly inferred.
  - Evidence: Existing method table, ownership notes, data caveats, IDA recheck notes, command-line parser split, MD5 dependency, profile-block references, and memory/type/meta cross-references support the score.
- 2026-06-04 live IDA evidence update:
  - What existed before: `COMPLETION:80`, `CONFIDENCE:76`, no reconstructable parent assignment, stale source-output/tooling caveats, and several method rows without half-open ranges.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:86`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000N4`.
  - Summary/evidence: live IDA confirms exact method ranges, RegistryConfig vtable slots at `0x00612614/0x00612620/0x00612624`, 433 data refs to `g_pConfig`, the direct `Md5BytesToBuffer` call at `0x004928ba`, exact registry persistence child docs, and the profile-block defaulting relationship. C++ remains blank because registry persistence/helper names are not yet at the `95/95` bar.
- 2026-06-08 Batch 113 direct-owner check:
  - Changed to: no score or metadata change.
  - Summary/evidence: added [UID:0002VB][0x00493e30-0x00493ef0.UnreferencedAdapterPhysicalAddressFormatterRaw](by-memory/0x00493e30-0x00493ef0.UnreferencedAdapterPhysicalAddressFormatterRaw.md) as a rejected direct class child. Fresh IDA MCP checks reconfirmed no function, xrefs, or callers at `0x00493e30`, so similarity to `LoadFromRegistry` is insufficient to assign it to `RegistryConfig`.
- 2026-06-10 B001-016 split audit:
  - Changed to: no score or metadata change.
  - Summary/evidence: clarified that [UID:0002VB][0x00493e30-0x00493ef0.UnreferencedAdapterPhysicalAddressFormatterRaw](by-memory/0x00493e30-0x00493ef0.UnreferencedAdapterPhysicalAddressFormatterRaw.md) is still rejected as a direct class method, but now routes to [UID:0000N4][RegistryConfig](by-file/RegistryConfig.md) as a file-level raw helper/dead clone.
- 2026-06-08 A010 Batch112 parent-gate follow-up:
  - Changed from `86/86` to `87/87`.
  - Summary/evidence: linked exact default/load child pages for `LoadOrInitialize`, `InitializeUserDataDefaults`, and `InitializeDefaults`, documented why those children assign directly here, and recorded why the broader mixed Config/RegistryConfig aggregate remains unassigned despite reaching `85/89`.
- 2026-06-08 A010 Batch120 child-routing repair:
  - Changed to: no score change.
  - Summary/evidence: linked the exact `SaveToRegistry` and `LoadFromRegistry` pages as direct class children after each child cleared the corrected `85/85` gate. The adjacent unreferenced adapter-formatting clone remains rejected as a direct child because it has no function, xrefs, callers, or source-boundary proof.
