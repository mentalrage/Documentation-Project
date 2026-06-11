*** UID:000031 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000IE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Config

## Status

- Confidence: strong for base config ownership, singleton lifecycle, modeled
  constructor/destructor boundaries, and placement in the lower-level config
  module.
- Proposed file: [UID:0000IE][Config](by-file/Config.md)
- Current generated target: `auto-generated/NexusTK/config/Config.cpp`
- Current ranges: constructor [UID:00030S][0x0048e550-0x0048e77a.ConfigConstructor](by-memory/0x0048e550-0x0048e77a.ConfigConstructor.md)
  and deleting destructor [UID:0002P9][0x00494020-0x00494126.ConfigDeletingDestructor](by-memory/0x00494020-0x00494126.ConfigDeletingDestructor.md).
- Evidence basis: existing project documentation plus IDA-backed by-memory and
  by-file evidence; older generated-source names are retained only as search
  context.
- Autogen status: reconstructable class attached to the [UID:0000IE][Config](by-file/Config.md)
  file root at position `10`. C++ remains blank because the field names,
  normal-destructor versus scalar-deleting-wrapper presentation, and final
  header/source split are not final-source quality.

## Responsibility

`Config` is the base in-memory client configuration object. It installs `g_pConfig`, initializes fixed settings rows, string/list members, and the embedded config-entry array, then releases those same owned resources during destruction.

## Methods

| Address | Method | Role |
| --- | --- | --- |
| [UID:00030S][0x0048e550-0x0048e77a.ConfigConstructor](by-memory/0x0048e550-0x0048e77a.ConfigConstructor.md) | `Config::Config()` | Constructs the base object, installs `g_pConfig`, initializes the 100-row fixed settings table, constructs 32 config-entry records, initializes list/string storage, and clears display/file-name buffers. |
| [UID:0002P9][0x00494020-0x00494126.ConfigDeletingDestructor](by-memory/0x00494020-0x00494126.ConfigDeletingDestructor.md) | `Config::DeletingDestructor(unsigned int deleteFlags)` | Releases the list, string/vector buffers, config-entry storage, clears `g_pConfig`, destroys `LObject`, and conditionally frees `this`. |

## Related Helpers

- [UID:00021Z][0x0048e310-0x0048e479.ConfigRawTableHelpers](by-memory/0x0048e310-0x0048e479.ConfigRawTableHelpers.md)
  covers the raw config-table lookup/append and reset helpers immediately
  before entry construction.
- [UID:00032D][0x0048e480-0x0048e4a8.ConfigEntryInitialize](by-memory/0x0048e480-0x0048e4a8.ConfigEntryInitialize.md)
  initializes one 0x18-byte config-entry record.
- [UID:00032E][0x0048e4b0-0x0048e54a.ConfigEntryDestroyHelpers](by-memory/0x0048e4b0-0x0048e54a.ConfigEntryDestroyHelpers.md)
  covers the entry destructor callback and direct scratch-entry cleanup helper.
- [UID:00032H][0x0048ea70-0x0048ea9f.ConfigEntryVectorCopyWrappersRaw](by-memory/0x0048ea70-0x0048ea9f.ConfigEntryVectorCopyWrappersRaw.md)
  covers raw wrappers around the `this + 0x2912b4` config-entry vector helper.
- [UID:00032I][0x0048eaa0-0x0048ebb3.ConfigStringPreferenceHelpers](by-memory/0x0048eaa0-0x0048ebb3.ConfigStringPreferenceHelpers.md)
  covers Config-owned selector lookup/setter and heap-backed string preference
  helpers used by MIDI and UI/login/create-user callers through `g_pConfig`.
- [UID:000032][ConfigEntryBlock](by-class/ConfigEntryBlock.md) and
  [UID:0002PA][0x00494130-0x004941d6.ConfigEntryBlockReleaseOwnedBuffers](by-memory/0x00494130-0x004941d6.ConfigEntryBlockReleaseOwnedBuffers.md)
  cover embedded config-entry block cleanup.
- [UID:0000BW][RegistryConfig](by-class/RegistryConfig.md) extends the same
  storage and owns registry-backed defaults/load/save.

## Evidence Notes

- [UID:0000IE][Config](by-file/Config.md) is `86/85`, projected to
  `NexusTK/config/`, and keeps `Config`, `ConfigEntryBlock`, raw config-table
  helpers, and entry construction/destruction in the lower-level configuration
  module.
- [UID:00030S][0x0048e550-0x0048e77a.ConfigConstructor](by-memory/0x0048e550-0x0048e77a.ConfigConstructor.md)
  is an exact `85/88` constructor child assigned to this class after the mixed
  aggregate was split.
- [UID:000110][0x0048e480-0x0048f3f1.ConfigAndRegistryDefaults](by-memory/0x0048e480-0x0048f3f1.ConfigAndRegistryDefaults.md)
  is now a non-emitting mixed inventory over exact Config and RegistryConfig
  children. B001-015 split [UID:00032D][0x0048e480-0x0048e4a8.ConfigEntryInitialize](by-memory/0x0048e480-0x0048e4a8.ConfigEntryInitialize.md), [UID:00032E][0x0048e4b0-0x0048e54a.ConfigEntryDestroyHelpers](by-memory/0x0048e4b0-0x0048e54a.ConfigEntryDestroyHelpers.md), [UID:00032H][0x0048ea70-0x0048ea9f.ConfigEntryVectorCopyWrappersRaw](by-memory/0x0048ea70-0x0048ea9f.ConfigEntryVectorCopyWrappersRaw.md), and
  [UID:00032I][0x0048eaa0-0x0048ebb3.ConfigStringPreferenceHelpers](by-memory/0x0048eaa0-0x0048ebb3.ConfigStringPreferenceHelpers.md) out as Config-owned helper pages.
- [UID:0002P9][0x00494020-0x00494126.ConfigDeletingDestructor](by-memory/0x00494020-0x00494126.ConfigDeletingDestructor.md)
  records the exact vtable-dispatched deleting destructor, cleanup order,
  20-entry and 32-entry destructor passes, `g_pConfig` clear, scalar-delete
  flag handling, and now assigns directly here after the child reached `85/88`.
- [UID:00028Q][0x0067a7c8-0x0067a7cc.g_pConfig](by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md)
  documents the process config singleton touched by the constructor and
  destructor.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `85` | The file parent, singleton lifecycle, exact constructor child, deleting-destructor cleanup sequence, raw table helpers, config-entry initialization/destruction, and `ConfigEntryBlock` relationship are now cross-linked to current project docs. Completion remains below final-source quality because field names, entry-array declarations, and final header/source presentation are not final. |
| Confidence `86` | IDA-backed memory pages agree on modeled function starts, vtable dispatch, global install/clear, helper ranges, and config-module ownership. Confidence is capped by unresolved field names and the final presentation of source destructor versus compiler scalar-deleting wrapper. |

## Cross-References

- [UID:0000IE][Config](by-file/Config.md)
- [UID:00021Z][0x0048e310-0x0048e479.ConfigRawTableHelpers](by-memory/0x0048e310-0x0048e479.ConfigRawTableHelpers.md)
- [UID:00032D][0x0048e480-0x0048e4a8.ConfigEntryInitialize](by-memory/0x0048e480-0x0048e4a8.ConfigEntryInitialize.md)
- [UID:00032E][0x0048e4b0-0x0048e54a.ConfigEntryDestroyHelpers](by-memory/0x0048e4b0-0x0048e54a.ConfigEntryDestroyHelpers.md)
- [UID:00030S][0x0048e550-0x0048e77a.ConfigConstructor](by-memory/0x0048e550-0x0048e77a.ConfigConstructor.md)
- [UID:000110][0x0048e480-0x0048f3f1.ConfigAndRegistryDefaults](by-memory/0x0048e480-0x0048f3f1.ConfigAndRegistryDefaults.md)
- [UID:00032H][0x0048ea70-0x0048ea9f.ConfigEntryVectorCopyWrappersRaw](by-memory/0x0048ea70-0x0048ea9f.ConfigEntryVectorCopyWrappersRaw.md)
- [UID:00032I][0x0048eaa0-0x0048ebb3.ConfigStringPreferenceHelpers](by-memory/0x0048eaa0-0x0048ebb3.ConfigStringPreferenceHelpers.md)
- [UID:000111][0x00491b30-0x004941d6.RegistryPersistenceAndConfigEntryCleanup](by-memory/0x00491b30-0x004941d6.RegistryPersistenceAndConfigEntryCleanup.md)
- [UID:0002P9][0x00494020-0x00494126.ConfigDeletingDestructor](by-memory/0x00494020-0x00494126.ConfigDeletingDestructor.md)
- [UID:0002PA][0x00494130-0x004941d6.ConfigEntryBlockReleaseOwnedBuffers](by-memory/0x00494130-0x004941d6.ConfigEntryBlockReleaseOwnedBuffers.md)
- [UID:00028Q][0x0067a7c8-0x0067a7cc.g_pConfig](by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md)

## Changes

- 2026-06-06 parent attachment update:
  - Before: the page was `72/84`, reconstructable, but unassigned because it
    still failed the child-side parent gate and retained stale generated-source
    provenance.
  - After: raised to `82/86`, attached to [UID:0000IE][Config](by-file/Config.md)
    at position `10`, replaced stale provenance with project-doc/IDA-backed
    evidence, added evidence notes and score rationale, and kept C++ blank under
    the final-source gate.
  - Evidence: [UID:0000IE][Config](by-file/Config.md) is an `86/84` file root
    under `NexusTK/config/`; [UID:000110][0x0048e480-0x0048f3f1.ConfigAndRegistryDefaults](by-memory/0x0048e480-0x0048f3f1.ConfigAndRegistryDefaults.md)
    documents the constructor/defaults side; [UID:0002P9][0x00494020-0x00494126.ConfigDeletingDestructor](by-memory/0x00494020-0x00494126.ConfigDeletingDestructor.md)
    documents the exact destructor cleanup; and [UID:00028Q][0x0067a7c8-0x0067a7cc.g_pConfig](by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md)
    anchors singleton ownership.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `72/84`.
  - Summary/evidence: constructor/destructor responsibility, global ownership, member initialization/release behavior, and related helper ranges are documented; remaining work is detailed member layout, exact original type names, and fuller generated-C++ reconstruction.
- 2026-06-05: Marked reconstructable for autogen.
  - Before: `RECONSTRUCTABLE` was blank, leaving the class coverage row unclassified.
  - After: `RECONSTRUCTABLE:TRUE`; `AUTOGEN_PARENT_UID` remains blank because the class completion score is below the 80% attachment gate.
  - Evidence: live IDA MCP confirms modeled function starts at `0x0048e550` and `0x00494020`, with config construction called from startup/config initialization at `0x00464136`; existing project docs place the class in [UID:0000IE][Config](by-file/Config.md).
- 2026-06-08 A010 Batch112: Raised completion from `82` to `85` and kept confidence at `86`.
  - Before: the constructor was only linked through the mixed Config/RegistryConfig aggregate, so this class did not fully support the strict direct-child gate for a constructor page.
  - After: linked exact child [UID:00030S][0x0048e550-0x0048e77a.ConfigConstructor](by-memory/0x0048e550-0x0048e77a.ConfigConstructor.md) and updated the file parent evidence to [UID:0000IE][Config](by-file/Config.md) `86/85`.
  - Evidence: the constructor child isolates `Config::Config`, singleton installation, fixed settings initialization, config-entry construction, and destructor partner evidence while leaving final C++ blank below the 95/95 gate.
- 2026-06-08 A010 Batch120 child-routing repair:
  - Changed to: no score change.
  - Summary/evidence: [UID:0002P9][0x00494020-0x00494126.ConfigDeletingDestructor](by-memory/0x00494020-0x00494126.ConfigDeletingDestructor.md) now attaches directly to this class after reaching `85/88`. This class remains `85/86` and the file parent [UID:0000IE][Config](by-file/Config.md) remains `86/85`, satisfying the corrected gate without changing final-source readiness.
- 2026-06-10 B001-015 split repair:
  - Changed to: no score change.
  - Summary/evidence: exact Config-owned helper children [UID:00032D][0x0048e480-0x0048e4a8.ConfigEntryInitialize](by-memory/0x0048e480-0x0048e4a8.ConfigEntryInitialize.md), [UID:00032E][0x0048e4b0-0x0048e54a.ConfigEntryDestroyHelpers](by-memory/0x0048e4b0-0x0048e54a.ConfigEntryDestroyHelpers.md), [UID:00032H][0x0048ea70-0x0048ea9f.ConfigEntryVectorCopyWrappersRaw](by-memory/0x0048ea70-0x0048ea9f.ConfigEntryVectorCopyWrappersRaw.md), and [UID:00032I][0x0048eaa0-0x0048ebb3.ConfigStringPreferenceHelpers](by-memory/0x0048eaa0-0x0048ebb3.ConfigStringPreferenceHelpers.md) now carry the base Config storage/preference helper evidence that used to be trapped in the mixed aggregate.
