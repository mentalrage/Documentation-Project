*** UID:000032 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000IE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ConfigEntryBlock

## Status

- Confidence: strong
- Proposed file: [UID:0000IE][Config](by-file/Config.md)
- Current generated target: `auto-generated/NexusTK/config/Config.cpp`
- Current range: `0x00494130-0x004941d6`
- Evidence basis: existing project documentation plus IDA-backed by-memory and
  by-file evidence; older generated-source names are retained only as search
  context.
- Autogen status: reconstructable helper class attached to the
  [UID:0000IE][Config](by-file/Config.md) file root at position `20`. Its exact
  cleanup child [UID:0002PA][0x00494130-0x004941d6.ConfigEntryBlockReleaseOwnedBuffers](by-memory/0x00494130-0x004941d6.ConfigEntryBlockReleaseOwnedBuffers.md)
  now attaches directly to this class after both sides clear the corrected
  `85/85` gate. C++ remains blank because the exact `ConfigEntryBlock`
  structure names and source-level declaration style are not final-source
  quality.

## Responsibility

`ConfigEntryBlock` owns a fixed block of `ConfigEntry` records embedded inside `Config` and `RegistryConfig`. Its method releases per-entry heap buffers and resets the entry count/dirty state.

## Method

| Address | Method | Role |
| --- | --- | --- |
| [UID:0002PA][0x00494130-0x004941d6.ConfigEntryBlockReleaseOwnedBuffers](by-memory/0x00494130-0x004941d6.ConfigEntryBlockReleaseOwnedBuffers.md) | `ConfigEntryBlock::ReleaseOwnedBuffers()` | Iterates active entries, frees primary/secondary/tertiary buffers, nulls them, then clears count and dirty state. |

## Ownership Notes

- IDA shows callers from `RegistryConfig::~RegistryConfig`, `RegistryConfig::LoadFromRegistry`, a cleanup wrapper around `0x00493f90`, and `Config::DeletingDestructor`.
- The free helpers `InitializeConfigEntry` and `DestroyConfigEntry` operate on one `ConfigEntry`; `ConfigEntryBlock` handles the whole active block.
- This class should migrate with `config/Config.cpp` or a tiny private `config/ConfigEntry.cpp`, not with profile UI.
- [UID:0000IE][Config](by-file/Config.md) is `86/84`, projected to
  `NexusTK/config/`, and explicitly lists `ConfigEntryBlock`,
  `InitializeConfigEntry`, `DestroyConfigEntry`, and raw config-table helpers as
  lower-level configuration storage support.
- [UID:0002PA][0x00494130-0x004941d6.ConfigEntryBlockReleaseOwnedBuffers](by-memory/0x00494130-0x004941d6.ConfigEntryBlockReleaseOwnedBuffers.md)
  records the exact range, neighboring padding, caller set, 0x18-byte entry
  stride, active-count field at block `+0x300`, state byte at `+0x304`, and the
  free/reset behavior.
- [UID:000111][0x00491b30-0x004941d6.RegistryPersistenceAndConfigEntryCleanup](by-memory/0x00491b30-0x004941d6.RegistryPersistenceAndConfigEntryCleanup.md)
  keeps the mixed aggregate unassigned while routing this exact child helper to
  the `Config` source root.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `85` | The single source-facing cleanup method, range, caller set, entry/block layout evidence, direct child routing, config-module ownership, and relationship to `Config` / `RegistryConfig` are documented. Completion remains capped by unresolved original field names and whether final source presents this as a small class, private helper, or inline cleanup abstraction. |
| Confidence `88` | IDA-backed child evidence confirms the exact boundary, neighboring padding, callers, `free`-only callee behavior, 0x18-byte record stride, and `Config.cpp` placement. Confidence remains below final-source quality because the source-level declaration style is still open. |

## Cross-References

- [UID:0000IE][Config](by-file/Config.md)
- [UID:0000BW][RegistryConfig](by-class/RegistryConfig.md)
- [UID:000111][0x00491b30-0x004941d6.RegistryPersistenceAndConfigEntryCleanup](by-memory/0x00491b30-0x004941d6.RegistryPersistenceAndConfigEntryCleanup.md)
- [UID:0002PA][0x00494130-0x004941d6.ConfigEntryBlockReleaseOwnedBuffers](by-memory/0x00494130-0x004941d6.ConfigEntryBlockReleaseOwnedBuffers.md)
- [UID:0002P9][0x00494020-0x00494126.ConfigDeletingDestructor](by-memory/0x00494020-0x00494126.ConfigDeletingDestructor.md)

## Changes

- 2026-06-08 A010 Batch120 strict-gate repair:
  - Changed from `80/88` to `85/88`.
  - Summary/evidence: the exact cleanup child [UID:0002PA][0x00494130-0x004941d6.ConfigEntryBlockReleaseOwnedBuffers](by-memory/0x00494130-0x004941d6.ConfigEntryBlockReleaseOwnedBuffers.md) is now `85/90` and attaches directly here; [UID:0000IE][Config](by-file/Config.md) is `86/85` and remains the `NexusTK/config/` source root. The class still does not emit C++ because original field names and declaration style remain open.
- 2026-06-06 parent attachment update:
  - Before: the page was `72/86`, reconstructable, but unassigned because it
    still failed the child-side parent gate and retained stale generated-source
    provenance.
  - After: raised to `80/88`, attached to [UID:0000IE][Config](by-file/Config.md)
    at position `20`, replaced stale provenance with current project-doc and
    IDA-backed evidence, added score rationale, and kept C++ blank under the
    final-source gate.
  - Evidence: [UID:0000IE][Config](by-file/Config.md) is the valid `Config.cpp`
    root; [UID:0002PA][0x00494130-0x004941d6.ConfigEntryBlockReleaseOwnedBuffers](by-memory/0x00494130-0x004941d6.ConfigEntryBlockReleaseOwnedBuffers.md)
    documents the exact helper boundary, caller set, and entry layout; and
    [UID:000111][0x00491b30-0x004941d6.RegistryPersistenceAndConfigEntryCleanup](by-memory/0x00491b30-0x004941d6.RegistryPersistenceAndConfigEntryCleanup.md)
    records the mixed aggregate routing decision.
- 2026-05-27: Current range changed from `0x00494130-0x004941d5` to `0x00494130-0x004941d6`. Evidence: IDA MCP `lookup_funcs` reports `sub_494130` size `0xa6`, and direct PE byte review shows the final `ret` byte at `0x004941d5`.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `72/86`.
  - Summary/evidence: the single owned-buffer cleanup method, endpoint correction, caller set, and config ownership are documented; remaining work is mainly exact original struct/member naming and final emitted-source placement.
- 2026-06-05: Marked reconstructable for autogen.
  - Before: `RECONSTRUCTABLE` was blank, leaving the class coverage row unclassified.
  - After: `RECONSTRUCTABLE:TRUE`; `AUTOGEN_PARENT_UID` remains blank because the class completion score is below the 80% attachment gate.
  - Evidence: live IDA MCP confirms `0x00494130-0x004941d6` as a modeled cleanup function with callers from registry-config teardown/load paths and `Config::DeletingDestructor`; existing project docs place the helper with [UID:0000IE][Config](by-file/Config.md).
