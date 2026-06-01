*** UID:0000N4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/config/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# RegistryConfig

## Status

- Confidence: strong for module ownership and anchors.
- Proposed module: `config/RegistryConfig.cpp`
- Current generated source: `class_RegistryConfig.cpp`
- Primary class doc: [UID:0000BW][RegistryConfig](by-class/RegistryConfig.md)
- Main address docs: [UID:000110][0x0048e480-0x0048f3f1.ConfigAndRegistryDefaults](by-memory/0x0048e480-0x0048f3f1.ConfigAndRegistryDefaults.md), [UID:000220][0x0048f400-0x00491b28.RegistryCommandLineParsers](by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md), [UID:000111][0x00491b30-0x004941d6.RegistryPersistenceAndConfigEntryCleanup](by-memory/0x00491b30-0x004941d6.RegistryPersistenceAndConfigEntryCleanup.md), [UID:0002P7][0x00491b30-0x00492695.RegistryConfigSaveToRegistry](by-memory/0x00491b30-0x00492695.RegistryConfigSaveToRegistry.md), [UID:0002P8][0x004926a0-0x00493e29.RegistryConfigLoadFromRegistry](by-memory/0x004926a0-0x00493e29.RegistryConfigLoadFromRegistry.md), [UID:0002P9][0x00494020-0x00494126.ConfigDeletingDestructor](by-memory/0x00494020-0x00494126.ConfigDeletingDestructor.md), and [UID:0002PA][0x00494130-0x004941d6.ConfigEntryBlockReleaseOwnedBuffers](by-memory/0x00494130-0x004941d6.ConfigEntryBlockReleaseOwnedBuffers.md)

## File Role

`RegistryConfig.cpp` owns the registry-backed configuration subclass. It resets built-in defaults, initializes the user-data/profile slice, loads and saves Windows registry keys, normalizes startup command-line state, and participates in config-entry cleanup.

Keep this separate from [UID:0000MS][ProfileStorage](by-file/ProfileStorage.md). Profile storage consumes the user-data block and calls `InitializeUserDataDefaults`, but registry/default ownership belongs under `config/`.

`LoadFromRegistry` depends on the shared [UID:0000L6][MD5](by-file/MD5.md) utility for a caller-output digest at `0x004928ba`; that digest helper remains in `util/MD5.cpp`, not in this config module.

The user-profile/settings slice owned by this class is documented as [UID:0001VR][RegistryConfigUserProfileBlock](by-type/by-struct/RegistryConfigUserProfileBlock.md). [UID:0001QL][client_profile_storage](by-meta/client_profile_storage.md) records the `.usr` and legacy `.cfg` file formats that overlay that slice.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `RegistryConfig` | `0x00467340`, `0x0048e780-0x00493e29` | Registry-backed subclass lifecycle, default reset, registry load/save, and user-data defaults. |
| registry/default helper data | emitted globals in `class_RegistryConfig.cpp` | Screen dimensions, empty string handles, language/config globals, and wide-string sentinel aliases. |
| `ConfigEntryBlock` interactions | `0x00494130` callers from registry load/destructor paths | Cleanup support shared with [UID:0000IE][Config](by-file/Config.md). Final owner likely remains `Config.cpp` or a private config-entry helper file. |

## Method Families

| Area | Representative anchors | Notes |
| --- | --- | --- |
| Lifecycle | `0x00467340`, `0x0048e780` | Scalar deleting wrapper and real destructor; releases registry/config resources and clears base state. |
| Load/default flow | `0x0048e860`, `0x0048eed0` | Applies defaults, attempts registry load, and normalizes command-line state. |
| Command-line/session parser helpers | `0x0048f400-0x00491b28` | Login/session command-line modes, DNS/host resolution, and connection parameter setup. |
| User-data defaults | `0x0048ebc0` | Resets the [UID:0001VR][RegistryConfigUserProfileBlock](by-type/by-struct/RegistryConfigUserProfileBlock.md) before `.usr` or legacy `.cfg` overlay. |
| Registry persistence | `0x00491b30`, `0x004926a0` | Saves and loads Kingdom of the Winds/NexusTK registry options, server metadata, adapter state, and CLSID data. |

## Boundary Notes

- IDA confirms exact starts/ranges for `0x00467340`, `0x0048e780`, `0x0048e860`, `0x0048ebc0`, `0x0048eed0`, `0x00491b30`, `0x004926a0`, `0x00494020`, and `0x00494130`; exact child pages now document registry save/load and the adjacent config cleanup helpers.
- `list missing-ref --class RegistryConfig` returns zero entries.
- Current emitted source omits bodies for `SaveToRegistry` and `LoadFromRegistry` after their source markers; this is tracked in [wave3_data_issues](../wave3_data_issues.md) and the shared [UID:0000VD][ScopedMarkerMissingMethodBodies](by-item/ScopedMarkerMissingMethodBodies.md) note.
- `show grade class RegistryConfig` now reports a low effective grade because child rollup uses low auto grades despite high manual/effective child grades. This is tracked in [wave3_noticed_problems](../wave3_noticed_problems.md) as a grading/tool issue.
- 2026-05-25 IDA MCP recheck confirms `0x00491b30` opens `Software\Nexon\Kingdom of the Winds`, writes client options plus `Color%d` and `MultiServer*` values, and closes registry handles. `0x004926a0` creates/reads a CLSID value under `HKEY_CLASSES_ROOT`, loads the same Nexon key family, and rebuilds adapter/server metadata.
- 2026-05-27 gap pass: direct PE byte review and local exported function starts identify [UID:000220][0x0048f400-0x00491b28.RegistryCommandLineParsers](by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md) as a command-line/login/session helper island between defaults and registry persistence.
- 2026-05-30 split pass: [UID:000220][0x0048f400-0x00491b28.RegistryCommandLineParsers](by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md) is now an aggregate parent with exact child pages for the individual launcher/auth parser helpers. Keep the family config-adjacent until a verified caller path proves a different original source module.
- 2026-05-27 gap pass: [UID:000221][0x004941e0-0x00494519.MsvcComAndFormattingHelpers](by-memory/0x004941e0-0x00494519.MsvcComAndFormattingHelpers.md) is an ignored MSVC COM/CRT helper island used by the command-line/parser helpers and broad formatting/scanning callers; do not place it in `RegistryConfig.cpp` as NexusTK-authored source.
- 2026-05-25 MD5 pass: IDA confirms `0x004926a0` calls [UID:0000L6][MD5](by-file/MD5.md) helper `0x005153e0` at `0x004928ba`, passing a registry-derived string buffer, its length, and an output pointer near the config object. This is a dependency on `util/MD5.cpp`, not evidence that MD5 belongs in `RegistryConfig.cpp`.
- Current `simroot_v2/class_RegistryConfig.cpp` still contains only `WAVE3 OMITTED METHOD BODY` markers for `SaveToRegistry` and `LoadFromRegistry`, so this source is not migration-ready for registry persistence.

## Cross-References

- [UID:0000IE][Config](by-file/Config.md)
- [UID:0000BW][RegistryConfig](by-class/RegistryConfig.md)
- [UID:000032][ConfigEntryBlock](by-class/ConfigEntryBlock.md)
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
- [UID:000221][0x004941e0-0x00494519.MsvcComAndFormattingHelpers](by-memory/0x004941e0-0x00494519.MsvcComAndFormattingHelpers.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-06-01: `PROPOSED_RECONSTRUCTION_PATH` changed from blank to `NexusTK/config/`, and exact memory child pages were added for registry save/load.
  - Before: this by-file page named `config/RegistryConfig.cpp` in prose but did not populate the validator-managed projected path, and `SaveToRegistry` / `LoadFromRegistry` were referenced through the broad aggregate only.
  - After: the validator path points at `NexusTK/config/`, and [UID:0002P7][0x00491b30-0x00492695.RegistryConfigSaveToRegistry](by-memory/0x00491b30-0x00492695.RegistryConfigSaveToRegistry.md) plus [UID:0002P8][0x004926a0-0x00493e29.RegistryConfigLoadFromRegistry](by-memory/0x004926a0-0x00493e29.RegistryConfigLoadFromRegistry.md) provide exact method-level docs.
  - Evidence: `by-project-structure/proposed-source-tree.md` lists `config/RegistryConfig.cpp`; IDA MCP on 2026-06-01 confirms the exact function boundaries and registry-related callees.

- 2026-06-01: The bottom of the file had a second `## Changes` heading and two cross-reference bullets after the first change entry.
  - Before: [UID:000221][0x004941e0-0x00494519.MsvcComAndFormattingHelpers](by-memory/0x004941e0-0x00494519.MsvcComAndFormattingHelpers.md) and [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) were outside the cross-reference section, and the older scoring change was under a duplicate heading.
  - After: cross-references are grouped in one section, including the exact cleanup children, and the scoring change is retained under the single `## Changes` section.
  - Evidence: local page structure review while adding exact registry/config cleanup child pages.

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `88`, confidence `82`.
- Summary/evidence: the page documents registry-backed config role, method families, profile/config split, MD5 dependency, IDA boundary evidence, command-line parser split, generated caveats, and cross-references; confidence remains capped by omitted Wave3 method bodies and parser-family ownership caveats.
