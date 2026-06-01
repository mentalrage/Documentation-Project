*** UID:000032 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ConfigEntryBlock

## Status

- Confidence: strong
- Proposed file: [UID:0000IE][Config](by-file/Config.md)
- Current generated file: `class_ConfigEntryBlock.cpp`
- Current range: `0x00494130-0x004941d6`
- Evidence basis: Wave3 class inspection, generated source, and IDA MCP xrefs.

## Responsibility

`ConfigEntryBlock` owns a fixed block of `ConfigEntry` records embedded inside `Config` and `RegistryConfig`. Its method releases per-entry heap buffers and resets the entry count/dirty state.

## Method

| Address | Method | Role |
| --- | --- | --- |
| `0x00494130` | `ConfigEntryBlock::ReleaseOwnedBuffers()` | Iterates active entries, frees primary/secondary/tertiary buffers, nulls them, then clears count and dirty state. |

## Ownership Notes

- IDA shows callers from `RegistryConfig::~RegistryConfig`, `RegistryConfig::LoadFromRegistry`, a cleanup wrapper around `0x00493f90`, and `Config::DeletingDestructor`.
- The free helpers `InitializeConfigEntry` and `DestroyConfigEntry` operate on one `ConfigEntry`; `ConfigEntryBlock` handles the whole active block.
- This class should migrate with `config/Config.cpp` or a tiny private `config/ConfigEntry.cpp`, not with profile UI.

## Cross-References

- [UID:0000IE][Config](by-file/Config.md)
- [UID:0000BW][RegistryConfig](by-class/RegistryConfig.md)
- [UID:000111][0x00491b30-0x004941d6.RegistryPersistenceAndConfigEntryCleanup](by-memory/0x00491b30-0x004941d6.RegistryPersistenceAndConfigEntryCleanup.md)

## Changes

- 2026-05-27: Current range changed from `0x00494130-0x004941d5` to `0x00494130-0x004941d6`. Evidence: IDA MCP `lookup_funcs` reports `sub_494130` size `0xa6`, and direct PE byte review shows the final `ret` byte at `0x004941d5`.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `72/86`.
  - Summary/evidence: the single owned-buffer cleanup method, endpoint correction, caller set, and config ownership are documented; remaining work is mainly exact original struct/member naming and final emitted-source placement.
