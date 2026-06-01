*** UID:000031 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Config

## Status

- Confidence: strong
- Proposed file: [UID:0000IE][Config](by-file/Config.md)
- Current generated file: `class_Config.cpp`
- Current ranges: `0x0048e550-0x0048e779`, `0x00494020-0x00494125`
- Evidence basis: Wave3 class inspection and IDA MCP function-boundary verification.

## Responsibility

`Config` is the base in-memory client configuration object. It installs `g_pConfig`, initializes fixed settings rows, string/list members, and the embedded config-entry array, then releases those same owned resources during destruction.

## Methods

| Address | Method | Role |
| --- | --- | --- |
| `0x0048e550` | `Config::Config()` | Constructs the base object, sets `g_pConfig`, initializes 100 fixed rows, 32 config-entry records, string state, list storage, and display/file-name buffers. |
| `0x00494020` | `Config::DeletingDestructor(unsigned int deleteFlags)` | Releases the list, string/vector buffers, config-entry storage, clears `g_pConfig`, destroys `LObject`, and conditionally frees `this`. |

## Related Helpers

- `ConfigRawTableHelpers` at `0x0048e310-0x0048e479`.
- `InitializeConfigEntry` at `0x0048e480`.
- `DestroyConfigEntry` at `0x0048e4b0`.
- `ConfigEntryBlock::ReleaseOwnedBuffers` at `0x00494130`.
- `RegistryConfig` extends the same storage and owns registry-backed defaults/load/save.

## Cross-References

- [UID:0000IE][Config](by-file/Config.md)
- [UID:00021Z][0x0048e310-0x0048e479.ConfigRawTableHelpers](by-memory/0x0048e310-0x0048e479.ConfigRawTableHelpers.md)
- [UID:000110][0x0048e480-0x0048f3f1.ConfigAndRegistryDefaults](by-memory/0x0048e480-0x0048f3f1.ConfigAndRegistryDefaults.md)
- [UID:000111][0x00491b30-0x004941d6.RegistryPersistenceAndConfigEntryCleanup](by-memory/0x00491b30-0x004941d6.RegistryPersistenceAndConfigEntryCleanup.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `72/84`.
  - Summary/evidence: constructor/destructor responsibility, global ownership, member initialization/release behavior, and related helper ranges are documented; remaining work is detailed member layout, exact original type names, and fuller generated-C++ reconstruction.
