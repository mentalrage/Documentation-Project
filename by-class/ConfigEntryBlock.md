*** UID:000032 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
ServerSelectDirectory::~ServerSelectDirectory()
{
    ReleaseOwnedBuffers();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ConfigEntryBlock

## Status

- Confidence: very strong for the exact layout, cleanup behavior, Config ownership, and source-family identity; strong for inferred original private spellings.
- Proposed file: [UID:0000IE][Config](by-file/Config.md)
- Current generated target: `auto-generated/NexusTK/config/Config.cpp`
- Current range: `0x00494130-0x004941d6`
- Evidence basis: existing project documentation plus IDA-backed by-memory and
  by-file evidence; older generated-source names are retained only as search
  context.
- Autogen status: reconstructable helper class attached to the
  [UID:0000IE][Config](by-file/Config.md) file root at position `20`. Its exact
  cleanup child [UID:0002PA][0x00494130-0x004941d6.ConfigEntryBlockReleaseOwnedBuffers](by-memory/0x00494130-0x004941d6.ConfigEntryBlockReleaseOwnedBuffers.md)
  attaches directly to this historical class identity. Source-facing code uses
  `ServerSelectDirectory`; [UID:000031][Config](by-class/Config.md) owns the
  exact private declarations, while this historical class page emits only the
  non-duplicating `ServerSelectDirectory::~ServerSelectDirectory()` body that
  calls `ReleaseOwnedBuffers()` before automatic entry destruction.

## Responsibility

`ConfigEntryBlock` is the retained documentation identity for the source-facing private `ServerSelectDirectory` embedded in `Config` and inherited by `RegistryConfig`. It contains 32 natural-aligned `ServerSelectEntry` records. `ReleaseOwnedBuffers` releases each active entry's `name`, `description`, and `agreementText`, then resets `entryCount` and `version`.

In `Config` and `RegistryConfig`, `ServerSelectDirectory` begins at object `+0x28db10`. Its `entries[32]` occupy 0x300 bytes, `int entryCount` at directory `+0x300` lands at object `+0x28de10`, and `unsigned char version` at directory `+0x304` lands at object `+0x28de14`; the next Config field begins at `+0x28de18`. Each 0x18-byte `ServerSelectEntry` contains `unsigned char serverId` at `+0x00`, `wchar_t *name` at `+0x04`, `wchar_t *description` at `+0x08`, `wchar_t *agreementText` at `+0x0c`, `unsigned char address[4]` at `+0x10`, and `unsigned short port` at `+0x14`. Natural x86 alignment explains sizes 0x18 and 0x308 without explicit padding members. The exact source declaration lives on [UID:000031][Config](by-class/Config.md).

## Method

| Address | Method | Role |
| --- | --- | --- |
| [UID:0002PA][0x00494130-0x004941d6.ConfigEntryBlockReleaseOwnedBuffers](by-memory/0x00494130-0x004941d6.ConfigEntryBlockReleaseOwnedBuffers.md) | `ServerSelectDirectory::ReleaseOwnedBuffers()` | Iterates active entries, conditionally frees `name`, `description`, and `agreementText`, clears them in reverse field order, then unconditionally clears `entryCount` and `version`; a null receiver still faults on the final stores. |

## Ownership Notes

- IDA shows callers from `RegistryConfig::~RegistryConfig`, `RegistryConfig::LoadFromRegistry`, a cleanup wrapper around `0x00493f90`, and the `Config` scalar deleting destructor wrapper carrying `Config::~Config` semantics.
- The constructor/destructor helpers operate on one `ServerSelectEntry`; this directory method handles the whole active block.
- This private source type and method belong in `config/Config.cpp`, not profile UI, RegistryConfig persistence ownership, or an unproved separate `ConfigEntry.cpp`.
- [UID:0000IE][Config](by-file/Config.md) is `93/94`, projected to
  `NexusTK/config/`, and explicitly lists `ServerSelectDirectory`, the
  `ServerSelectEntry` constructor/destructor pair, the direct per-entry cleanup
  helper, and raw config-table helpers as lower-level configuration storage
  support. The generic names remain dated research aliases only.
- [UID:0002PA][0x00494130-0x004941d6.ConfigEntryBlockReleaseOwnedBuffers](by-memory/0x00494130-0x004941d6.ConfigEntryBlockReleaseOwnedBuffers.md)
  is `94/96` and records the exact range/body and padding hashes, five callers,
  sole free-family callee, complete 0x18/0x308 layouts, real null fault, and exact
  formal `ServerSelectDirectory::ReleaseOwnedBuffers` implementation.
- [UID:000111][0x00491b30-0x004941d6.RegistryPersistenceAndConfigEntryCleanup](by-memory/0x00491b30-0x004941d6.RegistryPersistenceAndConfigEntryCleanup.md)
  keeps the mixed aggregate unassigned while routing this exact child helper to
  the `Config` source root.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `92` | The page now maps the historical class identity to the exact `ServerSelectDirectory` source type, complete entry/directory layouts, cleanup method, Config route, and non-duplicating formal-channel disposition. |
| Confidence `94` | Exact binary boundaries, caller/callee behavior, registry and packet field use, constructor/destructor helpers, and ServerSelect consumers converge. Only unavailable original private spellings/header partition remain uncertain. |

## Cross-References

- [UID:0000IE][Config](by-file/Config.md)
- [UID:0000BW][RegistryConfig](by-class/RegistryConfig.md)
- [UID:000111][0x00491b30-0x004941d6.RegistryPersistenceAndConfigEntryCleanup](by-memory/0x00491b30-0x004941d6.RegistryPersistenceAndConfigEntryCleanup.md)
- [UID:0002PA][0x00494130-0x004941d6.ConfigEntryBlockReleaseOwnedBuffers](by-memory/0x00494130-0x004941d6.ConfigEntryBlockReleaseOwnedBuffers.md)
- [UID:0002P9][0x00494020-0x00494126.ConfigDeletingDestructor](by-memory/0x00494020-0x00494126.ConfigDeletingDestructor.md)

## Changes

- 2026-08-10 B010 UID0002PA accepted implementation callback:
  - Raised `85/88` to `92/94`; the CPP channel was blank at that time and is now superseded by the UID000480 generated-source closure below.
  - Recast this historical `ConfigEntryBlock` documentation page as the source-facing `ServerSelectDirectory` identity, added the complete `ServerSelectEntry` and directory layouts, and synchronized the exact `ReleaseOwnedBuffers` behavior and Config.cpp route.
  - Historical `ConfigEntry`, `ConfigEntryBlock`, primary/secondary/tertiary, count/dirty, separate-ConfigEntry.cpp, and unresolved-declaration assumptions remain in dated entries below, superseded as current source authority.

- 2026-06-08 A010 Batch120 strict-gate repair:
  - Changed from `80/88` to `85/88`.
  - Summary/evidence: the exact cleanup child [UID:0002PA][0x00494130-0x004941d6.ConfigEntryBlockReleaseOwnedBuffers](by-memory/0x00494130-0x004941d6.ConfigEntryBlockReleaseOwnedBuffers.md) is now `85/90` and attaches directly here; [UID:0000IE][Config](by-file/Config.md) is `86/85` and remains the `NexusTK/config/` source root. The class still does not emit C++ because original field names and declaration style remain open.
- 2026-06-21 B012 Rule 26 Config source-quality pass:
  - Score unchanged.
  - Historical summary/evidence: added corrected embedding evidence at `+0x28db10` with count/version at `+0x28de10/+0x28de14`. Its then-blank class C++ conclusion is superseded by the non-duplicating destructor body now emitted here; declarations remain unique on [UID:000031][Config](by-class/Config.md).
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

## 2026-07-15 UID0003UP Complete-Layout Type Synchronization

- Current declaration authority is the complete base-`Config` x86/MSVC layout of size `0x291918`. It declares the typed 100-row character/server macro table and count, launcher protocol union, ANSI `m_loginServerAddress`, semantic option bytes, profile/high storage, `m_serverEndpointText`, MIDI list, startup state, log text, block-list vector, `m_musicFolderPath`, and minimap tail.
- Exact current offsets include `m_mapMovementStatusOption=+0x28de75`, `m_profileTextSlots=+0x28de9c`, `m_macroHotkeys=+0x28f2ec`, `m_serverEndpointText=+0x291230`, `m_midiTrackPaths=+0x2912b4`, `m_logDataText=+0x2916cc`, and `m_musicFolderPath=+0x29190c`.
- Any earlier present-tense claim on this page that the final Config layout remained unresolved, required a RegistryConfig cast, used opaque/reserved/numeric/schematic storage, or placed the MP3/music directory at `+0x291230` is now explicitly historical and superseded.
- The later complete-layout work remains valid, while the accepted source-facing names are now `ServerSelectEntry` and `ServerSelectDirectory`: they retain the constructor/destructor behavior, 32-entry ownership, buffer-release semantics, and natural alignment previously described with generic names. Exact declarations live in UID000031's formal H channel. This historical class page emits only the directory destructor body, so it does not duplicate either declaration or the exact ReleaseOwnedBuffers method child.

## UID000480 Generated-Source Closure - 2026-08-15

- The scalar Config deleting-destructor sequence calls `ReleaseOwnedBuffers()` immediately before compiler destruction of the 32 `ServerSelectEntry` elements. That ordering is the lowering of `ServerSelectDirectory::~ServerSelectDirectory()` rather than a manual Config-body call.
- The formal body therefore contains only `ReleaseOwnedBuffers();`. Entry destructor iteration, Config member ordering, EH cleanup, and the scalar-delete wrapper remain compiler-generated.
- Metadata remains `92/94`, owner/emitter UID0000IE; no duplicate structure, method, or helper declaration is introduced.
- This synchronization adds no duplicate C++ and does not move entry ownership to RegistryConfig or ProfileStorage. Exact original helper spellings remain descriptive confidence limits.
