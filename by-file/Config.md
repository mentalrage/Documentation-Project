*** UID:0000IE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/config/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Config

## UID0000KA Input-Mode Consumer - 2026-08-15

`InventoryPane.cpp` includes `config/Config.h` and reads the existing `g_pConfig->m_doubleClickEnabled` byte to select single-click versus double-click item activation. Config retains declaration/storage/registry ownership; inventory owns only the branch and selected-slot use behavior. No proxy, getter, duplicate global, field, or score change is introduced.

## UID0000IF Direct StringUtil Dependency Closure - 2026-08-24

- [UID:000031][Config](by-class/Config.md) embeds `SimpleUStringVector m_blockListenNames` by value at exact offset `+0x2918fc`; C++ therefore requires a complete vector declaration at the member, not merely `class SimpleUStringVector;`.
- The formal Config H route now includes `../util/StringUtil.h` immediately after `../util/StringBase.h` and removes only that vector forward declaration. StringUtil owns the declaration once through ordered H emitters UID0000D9/UID0000DA/UID0000E7/UID0000PW at positions `0/10/20/30`; Config remains a consumer and does not duplicate the typedef, class, methods, or storage.
- `List` remains pointer-only in H and complete only in CPP. Existing complete LObject/Singleton bases, Config/RegistryConfig split, all helper/field/layout/API evidence, scores `93/94`, owner FILE, and `NexusTK/config/` placement remain unchanged.
- Rejected alternatives are a repeated local vector declaration, copied StringUtil source, transitive include dependence, opaque bytes at `+0x2918fc`, raw-offset access, a proxy/getter, or moving block-list ownership out of Config.
- Required generated proof is one direct StringUtil include before Config, zero `SimpleUStringVector` forward declarations, the exact by-value member after the complete included declaration, unchanged `sizeof(Config)==0x291918`, and a later ConnStatusPane regeneration preserving its complete network unit.

## Status

- Confidence: very strong for `config/Config.cpp` and `config/RegistryConfig.cpp` as lower-level configuration modules, the complete Config declaration, and the private server-directory family; raw-helper reachability and unavailable original private spellings remain the principal caps.
- Proposed module folder: `config/`
- Candidate files: `config/Config.cpp` and `config/RegistryConfig.cpp`; a separate `ConfigEntry.cpp` or `ServerSelectDirectory.cpp` remains unproved and is not required.
- Current generated sources: `auto-generated/NexusTK/config/Config.cpp`, `class_Config.cpp`, `class_RegistryConfig.cpp`, `class_ConfigEntryBlock.cpp`, and recovered helpers under `simroot_v2/recovered`.
- Evidence basis: Wave3 class/global inspection, generated source review, and IDA MCP boundary checks on 2026-05-23.

## Hypothesis

The original client separated the low-level configuration object and registry-backed persistence from profile file helpers. `Config` owns the large in-memory settings block, process global `g_pConfig`, and private `ServerSelectEntry`/`ServerSelectDirectory` storage family; `RegistryConfig` extends that inherited storage with registry load/save/default behavior. The constructor/destructor callbacks and directory cleanup remain Config.cpp implementation details shared through inheritance.

Preferred reconstruction:

```text
config/Config.cpp
config/Config.h
config/RegistryConfig.cpp
config/RegistryConfig.h
```

[UID:0000N4][RegistryConfig](by-file/RegistryConfig.md) remains the separate registry/default source candidate. `ServerSelectEntry`, `ServerSelectDirectory`, `ServerSelectEntry::ServerSelectEntry()`, the destructor/direct cleanup bodies, and `ServerSelectDirectory::ReleaseOwnedBuffers()` remain private implementation details in `Config.cpp` / the Config declaration channel. Historical `ConfigEntry`, `ConfigEntryBlock`, `InitializeConfigEntry`, and `DestroyConfigEntry` names are retained as search aliases only. A separate required `ConfigEntry.cpp` remains unproved.

## Proposed Contents

| Entity | Current range | Current file | Proposed ownership |
| --- | --- | --- | --- |
| `Config` | [UID:00030S][0x0048e550-0x0048e77a.ConfigConstructor](by-memory/0x0048e550-0x0048e77a.ConfigConstructor.md), `0x00494020-0x00494126` | `class_Config.cpp` | Base config object, `g_pConfig` lifecycle, ordinary `virtual ~Config()` semantics, and the MSVC scalar deleting destructor wrapper in `config/Config.cpp`. |
| `ConfigVtableData` | [UID:0003FU][0x006168d0-0x006168e4.ConfigVtableData](by-memory/0x006168d0-0x006168e4.ConfigVtableData.md) | `.rdata` vtable | `Config` vtable emitted from the class declaration. |
| `ConfigRttiLocatorPointer` | [UID:000535][0x006168cc-0x006168d0.ConfigRttiLocatorPointer](by-memory/0x006168cc-0x006168d0.ConfigRttiLocatorPointer.md) | `.rdata` vftable[-1] metadata | Exact Config COL-pointer compiler product routed from the terminal UID000250 dword to the Config class declaration. |
| `ServerSelectDirectory` / historical `ConfigEntryBlock` documentation identity | `0x00494130-0x004941d6` | `class_ConfigEntryBlock.cpp` | Private Config-owned 32-entry server directory and `ServerSelectDirectory::ReleaseOwnedBuffers()` in `config/Config.cpp`. |
| `ConfigRawTableHelpers` | `0x0048e310-0x0048e479` | retained raw helper gap | `FindOrAppendFixedConfigTableRow` and `ResetFixedConfigTableRows`: 40-wide local-player copy, typed character/server row matching, append count, and exact bank-field reset; no direct modeled caller/original symbol remains a lexical score cap. |
| `ServerSelectEntry::ServerSelectEntry()` / historical `InitializeConfigEntry` alias | [UID:00032D][0x0048e480-0x0048e4a8.ConfigEntryInitialize](by-memory/0x0048e480-0x0048e4a8.ConfigEntryInitialize.md) | `config/Config.cpp` private source item | Exact 0x18-byte server-entry constructor callback; initializes only `serverId`, three owned strings, four address bytes, and unsigned-short `port`, leaving natural padding unwritten. |
| `ServerSelectEntry` destructor/direct cleanup helpers | [UID:00032E][0x0048e4b0-0x0048e54a.ConfigEntryDestroyHelpers](by-memory/0x0048e4b0-0x0048e54a.ConfigEntryDestroyHelpers.md) | `recovered/DestroyConfigEntry_0048E4B0.cpp` plus direct cleanup helper | `92/94` element destructor callback and direct scratch-entry cleanup helper used by server-select parsing; both free/null `name`, `description`, and `agreementText`, while exact direct-helper spelling remains inferred. |
| MIDI track-path list copy wrappers | [UID:00032H][0x0048ea70-0x0048ea9f.ConfigEntryVectorCopyWrappersRaw](by-memory/0x0048ea70-0x0048ea9f.ConfigEntryVectorCopyWrappersRaw.md) | `config/Config.cpp` private helper pair | Retained private wrappers copying `m_midiTrackPaths` (`List *`, constructed as `List(0x42, 0x10)` at `Config + 0x2912b4`) to/from caller-supplied `List` objects through [UID:0003JT][0x004f3140-0x004f31cc.ListAssignFrom](by-memory/0x004f3140-0x004f31cc.ListAssignFrom.md); no direct call/pointer/export/vtable route is known in the retail binary. |
| Config string/preference helpers | [UID:00032I][0x0048eaa0-0x0048ebb3.ConfigStringPreferenceHelpers](by-memory/0x0048eaa0-0x0048ebb3.ConfigStringPreferenceHelpers.md) | omitted/private helpers | `GetMidiTrackPath`, `SetMidiTrackPath`, and `SetLogData`: MIDI track-path selector lookup/setter over `m_midiTrackPaths`, plus heap-backed LogData string replacement used by MIDI and UI/login/create-user consumers through `g_pConfig`. |
| `RegistryConfig` | `0x00467340-0x00493e28` | `class_RegistryConfig.cpp` | Registry-backed config subclass in [UID:0000N4][RegistryConfig](by-file/RegistryConfig.md). |

## Responsibilities

- `Config::Config` publishes the singleton, initializes the typed 100-row character/server macro slab/count, protocol launcher union, `ServerSelectDirectory m_serverDirectory` at `+0x28db10`, ANSI login address at `+0x28de18`, semantic options/profile/high storage, `m_midiTrackPaths`, `m_serverEndpointText`, `m_logDataText`, block-list vector, `m_musicFolderPath` at `+0x29190c`, and minimap tail through exact object size `0x291918`.
- The same base Config storage also supplies `m_midiEnabled` at `+0x84c` / decimal `2124`, the low MIDI enable byte used by `MidiPlayer::EnableMidiPlayback`, `DisableMidiPlayback`, and `SelectTrack`. Keep this distinct from the higher MusicControlDialog/SoundManager settings cluster at `+0x291908..+0x291914`.
- Source should present `virtual ~Config()`. The exact by-memory child at `0x00494020` is the MSVC scalar deleting destructor wrapper carrying the ordinary destructor body; it releases `m_midiTrackPaths`, `m_logDataText`, string/vector state, the embedded `ServerSelectDirectory`, each `ServerSelectEntry`, clears `g_pConfig`, destroys `LObject`, and lets compiler ABI flag logic decide conditional delete.
- `RegistryConfig::LoadOrInitialize` resets defaults, attempts registry load, falls back to defaults, and parses startup command-line state.
- `RegistryConfig::InitializeDefaults` sets built-in client defaults, screen-centered pane coordinates, option masks, and user-data defaults.
- `RegistryConfig::InitializeUserDataDefaults` resets the profile/user-data slice later overlaid by `.usr` and legacy `.cfg` profile files.
- `RegistryConfig::SaveToRegistry` and `RegistryConfig::LoadFromRegistry` own registry persistence for client options and server/adapter metadata.

## IDA MCP Evidence

IDA confirms these as real function starts and raw source-shaped helpers:

- `0x0048e480-0x0048e4a8` `ServerSelectEntry::ServerSelectEntry()` / historical raw `InitializeConfigEntry` alias.
- `0x0048e4b0-0x0048e4fa` and `0x0048e500-0x0048e54a` `ServerSelectEntry` cleanup helpers. [UID:00032E][0x0048e4b0-0x0048e54a.ConfigEntryDestroyHelpers](by-memory/0x0048e4b0-0x0048e54a.ConfigEntryDestroyHelpers.md) is `92/94`; the first body is the vector destructor callback and the second is the direct scratch-entry cleanup helper. Both remain Config-owned, and the direct helper's exact original spelling remains inferred.
- `0x0048e550-0x0048e77a` `Config::Config`, called from `0x004639d0`.
- `0x0048ea70-0x0048ea9f` raw MIDI track-path list copy-wrapper pair, no IDA function object but complete code-shaped bodies using `m_midiTrackPaths` (`this + 0x2912b4`) and [UID:0003JT][0x004f3140-0x004f31cc.ListAssignFrom](by-memory/0x004f3140-0x004f31cc.ListAssignFrom.md).
- `0x0048eaa0-0x0048ebb3` Config string/preference helper cluster, called from MIDI and UI/login/create-user paths through `g_pConfig`; the first two helpers are MIDI track-path selector lookup/setter helpers over the same `m_midiTrackPaths` list.
- `0x0048e780-0x0048e85a` `RegistryConfig::~RegistryConfig`, called by the scalar deleting wrapper at `0x00467340`.
- `0x0048e860-0x0048e94f` `RegistryConfig::LoadOrInitialize`, called from `0x004639d0`.
- `0x0048ebc0-0x0048eecf` `RegistryConfig::InitializeUserDataDefaults`, called by `InitializeDefaults` and `LoadUserProfileData`.
- `0x0048eed0-0x0048f3f1` `RegistryConfig::InitializeDefaults`.
- `0x00491b30-0x00492695` `RegistryConfig::SaveToRegistry`.
- `0x004926a0-0x00493e29` `RegistryConfig::LoadFromRegistry`.
- `0x00494020-0x00494126` `Config` scalar deleting destructor wrapper carrying the ordinary `Config::~Config` body.
- `0x00494130-0x004941d6` `ServerSelectDirectory::ReleaseOwnedBuffers` (historical page identity `ConfigEntryBlock`).

The raw helper cluster at [UID:00021Z][0x0048e310-0x0048e479.ConfigRawTableHelpers](by-memory/0x0048e310-0x0048e479.ConfigRawTableHelpers.md) is not currently emitted by `simroot_v2`; direct PE byte review identifies it as config table support immediately before the `ServerSelectEntry::ServerSelectEntry()` / historical raw `InitializeConfigEntry` alias target. B007's accepted source-quality pass keeps the no-function/no-xref/direct-route evidence as a score cap, but the child now carries formal first-draft C++ because the helper bodies, fixed row layout, and `Application + 0x858` field meaning are resolved.

The exact constructor child [UID:00030S][0x0048e550-0x0048e77a.ConfigConstructor](by-memory/0x0048e550-0x0048e77a.ConfigConstructor.md) is now assigned to [UID:000031][Config](by-class/Config.md), while the broader defaults aggregate remains mixed and unassigned.

B001-015 split [UID:000110][0x0048e480-0x0048f3f1.ConfigAndRegistryDefaults](by-memory/0x0048e480-0x0048f3f1.ConfigAndRegistryDefaults.md) into exact children. [UID:00032D][0x0048e480-0x0048e4a8.ConfigEntryInitialize](by-memory/0x0048e480-0x0048e4a8.ConfigEntryInitialize.md), [UID:00032E][0x0048e4b0-0x0048e54a.ConfigEntryDestroyHelpers](by-memory/0x0048e4b0-0x0048e54a.ConfigEntryDestroyHelpers.md), [UID:00032H][0x0048ea70-0x0048ea9f.ConfigEntryVectorCopyWrappersRaw](by-memory/0x0048ea70-0x0048ea9f.ConfigEntryVectorCopyWrappersRaw.md), and [UID:00032I][0x0048eaa0-0x0048ebb3.ConfigStringPreferenceHelpers](by-memory/0x0048eaa0-0x0048ebb3.ConfigStringPreferenceHelpers.md) attach here as private Config storage/preference helpers; the aggregate itself is now a non-emitting mixed inventory.

Batch 256 originally split UID0003FU using a broader endpoint. Current closure routes exact preceding [UID:000535][0x006168cc-0x006168d0.ConfigRttiLocatorPointer](by-memory/0x006168cc-0x006168d0.ConfigRttiLocatorPointer.md) and corrected [UID:0003FU][0x006168d0-0x006168e4.ConfigVtableData](by-memory/0x006168d0-0x006168e4.ConfigVtableData.md) to [UID:000031][Config](by-class/Config.md), while `[0x006168e4,0x006168e8)` remains non-emitting transition padding. The children attach to the class rather than directly to this file root, preserving the direct class-owner chain.

2026-06-16 A001 active-IDB refresh on `b001_mappane_0001AW_20260616` reconfirmed the base Config constructor at `0x0048e550` size `0x22a` with startup caller `0x00464136`, the deleting destructor at `0x00494020` size `0x106`, and `ConfigEntryBlock` cleanup at `0x00494130` size `0xa6`.

The same pass reconfirmed the source split around private helpers: raw table helpers `0x0048e310` and `0x0048e410` are still not functions with zero `xrefs_to` results; raw MIDI track-path copy wrappers `0x0048ea70` and `0x0048ea90` are still not functions with zero `xrefs_to`; modeled string/preference helpers `0x0048eaa0`, `0x0048eb00`, and `0x0048eb50` have the same one, one, and five code-call refs documented by the exact child pages.

A001 absolute pointer-byte scans for raw starts `0x0048e310`, `0x0048e410`, `0x0048ea70`, and `0x0048ea90` returned zero matches. B005's 2026-06-19 direct PE route scan reconfirmed no rel32, VA/RVA pointer, export, or vtable route to the two MIDI track-path copy-wrapper starts; their C++ is still emitted as retained private Config helpers because the bodies and field/callee semantics are source-shaped, while exact original names remain descriptive/inferred.

B012 2026-06-21 source-quality review resolves several stale Config layout labels without moving ownership:

- The fixed table uses `ConfigCharacterServerMacroRow[100]` at `+0x4`, stride `0x6894`, and `m_fixedConfigRowCount` at `+0x28d9d4`. UID00021Z copies `wchar_t[40]` local-player identity, compares player/server text, appends, and resets typed primary/alternate macro fields. Historical 20-wide empty-key and lookupKey/stateBlock/wideValueSet wording is superseded.
- `ServerSelectDirectory m_serverDirectory` begins at `+0x28db10`; its `ServerSelectEntry entries[32]` occupy 0x300 bytes, `entryCount` is at object `+0x28de10`, `version` at `+0x28de14`, and the next member begins at `+0x28de18`. Historical `ConfigEntryBlock`, count/dirty, and `+0x28dbd0` wording is stale.
- The destructor's 20-entry string-handle destruction pass is at `+0x2911e0`; older `+0x291060` text is stale for this pass.
- `+0x2912b4` is `m_midiTrackPaths`, not a ConfigEntry vector or registry-entry vector. It is a heap `List *` constructed as `List(0x42, 0x10)`, persisted by RegistryConfig under the `Midi` subkey, and consumed by MIDI selector helpers.
- `+0x2916cc` is `m_logDataText` / registry `LogData`, an owned heap wide string replaced by the private Config helper at `0x0048eb50`.
- `+0x291230` is `m_serverEndpointText[64]`; `m_musicFolderPath` is separate at `+0x29190c`. Historical MP3Dir-at-endpoint conflict is superseded by ServerSelect formatting, constructor, persistence, and music-consumer evidence. `+0x2918f0` remains the documented structured-launcher id overlay.

`ServerSelectDirectory` cleanup remains shared by RegistryConfig destruction/load paths and the base Config destructor: active `xrefs_to 0x00494130` reports refs from `0x0048e824`, `0x004938d6`, `0x00493e01`, `0x00493fb5`, and `0x004940c8`. This supports keeping the base storage helper in Config.cpp while [UID:0000N4][RegistryConfig](by-file/RegistryConfig.md) owns registry/default/load/save behavior.

## Source-Layout Decision

Do not keep `RegistryConfig` or `ServerSelectDirectory` in `profile/ProfileStorage.cpp` as the earlier draft suggested. Profile file helpers consume inherited Config user-data storage and call RegistryConfig-owned default/persistence methods, but the storage, registry/default behavior, and server-directory code remain lower-level configuration infrastructure.

Recommended split:

```text
config/Config.cpp
config/RegistryConfig.cpp
profile/ProfileStorage.cpp
```

`profile/ProfileStorage.cpp` references RegistryConfig behavior for defaults and inherited base Config storage for field data; it owns neither class. The complete typed Config declaration now makes this split compile-legal without raw-offset accessors or a derived cast.

Exact Config RTTI fixes the base header shape: `Config.h` includes `../util/LObject.h` and `../util/Singleton.h`, then declares `Config` with direct nonvirtual bases `LObject` and `Singleton<Config>`. The embedded source objects additionally require `../util/StringBase.h` and the complete vector declaration from `../util/StringUtil.h`; neither a base nor a by-value member can remain incomplete. `Config.cpp` includes `Config.h` and receives exact method/private-helper children. The locator and five-slot vtable are compiler products represented by their child markers, not raw definitions; the four-byte successor padding emits nothing.

## UID0003UB Macro-Table Consumer And Declaration Boundary

[UID:0003UB][0x005a3ae0-0x005a3d39.UserPaneExecuteHotkeyAction](by-memory/0x005a3ae0-0x005a3d39.UserPaneExecuteHotkeyAction.md) belongs to `NexusTK/ui/panels/UserPane.cpp`, not this module, but it is a direct consumer of Config-owned runtime storage. The merged key-handler caller supplies page bases `0`, `10`, or `20`; the method rotates the relative digit and reads one of 30 `0x108`-byte [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md) rows at `g_pConfig + 0x28f2ec`. State is row `+0x04` and `wchar_t[0x80]` text/key payload is row `+0x08`. Text state constructs opcode `0x0e`, subtype `0`, one-byte ACP length, and an exact `length + 3` send; Spell and Item states map alphabetic payloads to one-based command and inventory slots.

The storage is inherited from Config. Startup allocates exactly `0x291918` bytes, calls `Config::Config`, and only then patches the RegistryConfig vtable. Constructor/default/load/save/UI consumers agree on the table offset and surrounding storage; `g_pConfig` remains a base `Config *`, while the live object is RegistryConfig. RegistryConfig owns defaults and persistence behavior, not a separate copy of the table.

Historical UID0003UB-era declaration research checked Config/RegistryConfig formals, constructor/destructor/default/load/save/copy methods, fixed-table/string helpers, profile/macro UI consumers, launcher parsers, generated sources, adjacent types, and old reports. Its rejection of nested-profile, RegistryConfig-only, derived-cast, raw/accessor, field-only, and placeholder-heavy routes remains valid, while its unchanged-score/no-complete-layout conclusion is superseded by this `90/91` callback.

The formerly exact blockers are now closed: typed character/server macro rows resolve all fixed-row groups; a protocol-view launcher union resolves `+0x28d9e0..+0x28db10`; `m_loginServerAddress` resolves `+0x28de18`; semantic option/profile/high fields resolve the tail; and `m_serverEndpointText`/`m_musicFolderPath` resolve the prior role conflict. The complete declaration reaches `0x291918`; UID0003UB's separate target formal remains outside this support edit.

## Data Caveats

- `class_RegistryConfig.cpp` currently emits only stubs/structs for `SaveToRegistry` and `LoadFromRegistry` even though Wave3 method metadata grades them and IDA confirms their ranges. This is tracked in `../wave3_data_issues.md`.
- `RegistryConfig::~RegistryConfig` has lower Wave3 grade than the rest of the cluster, so destructor details should be reviewed before final source cleanup.
- `m_midiTrackPaths` is the preferred descriptive name for the base Config heap list at `+0x2912b4`. Older labels such as `config-entry vector`, `ConfigEntryVector`, `m_registryEntries`, and `m_midiRegistryList` should be read as historical or persistence-context names unless a later symbol-quality pass proves different original spelling.
- `m_logDataText` is the preferred descriptive name for the heap wide-string pointer at `+0x2916cc`, because RegistryConfig load maps registry `LogData` there and `0x0048eb50` frees/replaces that pointer. Avoid generic "string preference" names where `LogData` evidence is the active context.
- The source declaration should be `virtual ~Config()`. Do not introduce a human `Config::DeletingDestructor(unsigned int deleteFlags)` method; `0x00494020` is the compiler scalar deleting destructor wrapper plus ordinary destructor body.
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
- [UID:0003FU][0x006168d0-0x006168e4.ConfigVtableData](by-memory/0x006168d0-0x006168e4.ConfigVtableData.md)
- [UID:000111][0x00491b30-0x004941d6.RegistryPersistenceAndConfigEntryCleanup](by-memory/0x00491b30-0x004941d6.RegistryPersistenceAndConfigEntryCleanup.md)
- [UID:0002VB][0x00493e30-0x00493ef0.UnreferencedAdapterPhysicalAddressFormatterRaw](by-memory/0x00493e30-0x00493ef0.UnreferencedAdapterPhysicalAddressFormatterRaw.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-08-24 B003 UID0000IF C138 ordinary implementation callback:
  - Routed Config's by-value `SimpleUStringVector` dependency through the complete guarded `StringUtil.h`, removed the insufficient forward declaration, and preserved Config as a consumer rather than a type owner.
  - Kept score `93/94`, FILE ownership, `NexusTK/config/` path, complete `0x291918` layout, Config/RegistryConfig/ProfileStorage boundaries, formal source ownership, and every unrelated helper/history fact. Generated files remain validator-owned and require the exact include/forward/member/size and downstream ConnStatusPane proof above.

- 2026-08-15 B007 UID000480 accepted support callback:
  - Kept `93/94`, owner `FILE`, projected path `NexusTK/config/`, and every existing Config source/layout/helper fact.
  - Added exact UID000535 locator routing, corrected UID0003FU endpoint/padding, and the complete `LObject` plus `Singleton<Config>` header/source requirement. Generated `Config.cpp`/`.h` remains validator-owned and must be physically checked after the final waited owner validation.

- 2026-07-06 B011 UID00032D implementation callback support sync:
  - Score unchanged. Updated the proposed contents/source-placement wording for [UID:00032D][0x0048e480-0x0048e4a8.ConfigEntryInitialize](by-memory/0x0048e480-0x0048e4a8.ConfigEntryInitialize.md) so the formal item is `ConfigEntry::ConfigEntry()` and `InitializeConfigEntry(ConfigEntry *)` is only a historical/raw helper alias.
  - Summary/evidence: accepted B011 UID00032D report and target implementation keep the helper in `NexusTK/config/Config.cpp`, preserve the no-required-`ConfigEntry.cpp` caveat, and correct the constructor C++ to initialize only selector, three owned text pointers, value, state, and flags.
- 2026-07-06 B001 UID00032E implementation callback support sync:
  - Score unchanged at `88/88`.
  - Summary/evidence: synchronized [UID:00032E][0x0048e4b0-0x0048e54a.ConfigEntryDestroyHelpers](by-memory/0x0048e4b0-0x0048e54a.ConfigEntryDestroyHelpers.md) to `88/90`, keeping the helper pair in `NexusTK/config/Config.cpp`. The target now models two explicit emitted cleanup bodies: the vector destructor callback at `0x0048e4b0` and the direct scratch-entry cleanup helper at `0x0048e500`. Exact duplicate-helper spelling remains inferred/descriptive.
- 2026-06-27 B011 [UID:0002BR][0x004918e0-0x00491b28.StructuredHostPortIdLauncherParser](by-memory/0x004918e0-0x00491b28.StructuredHostPortIdLauncherParser.md) implementation callback support sync:
  - Score unchanged. Revised `+0x2918f0` from block-list/music-control-only wording to include this target's StringBase-style structured launcher id storage, inferred as `m_startupLauncherId` in the child C++.
  - Evidence: B011 MCP session `398b87c1` confirms [UID:0002BR][0x004918e0-0x00491b28.StructuredHostPortIdLauncherParser](by-memory/0x004918e0-0x00491b28.StructuredHostPortIdLauncherParser.md) extracts `/id:`, trims it, and assigns it to `this + 0x2918f0`; broader block-list/music-control caveats remain preserved.
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
- 2026-06-16 A001 Goal 2 file-confidence refresh:
  - Changed to: completion `87`, confidence `86`.
  - Summary/evidence: active IDB checks reconfirmed the Config constructor/destructor and ConfigEntryBlock cleanup boundaries, raw table/vector helper no-function/no-xref state, modeled string helper caller sets, and RegistryConfig cleanup/load refs into `ConfigEntryBlock`. Scores remain below final-source quality because raw helper reachability, large table field names, and final header/source declarations are still unresolved.
- 2026-06-19 B005 Rule 26 source-quality incorporation:
  - Changed to: completion `88`, confidence `88`.
  - Summary/evidence: [UID:00032H][0x0048ea70-0x0048ea9f.ConfigEntryVectorCopyWrappersRaw](by-memory/0x0048ea70-0x0048ea9f.ConfigEntryVectorCopyWrappersRaw.md) now emits first-draft private Config wrappers for copying `m_midiTrackPaths` to/from caller `List` objects, and [UID:00032I][0x0048eaa0-0x0048ebb3.ConfigStringPreferenceHelpers](by-memory/0x0048eaa0-0x0048ebb3.ConfigStringPreferenceHelpers.md) now names the same list as MIDI track-path selector storage. Direct PE route search still finds no live route to the raw wrapper starts, so the names are descriptive/inferred rather than original-proof.
- 2026-06-21 B006 MidiPlayer support sync:
  - Score unchanged.
  - Summary/evidence: recorded `m_midiEnabled` at `+0x84c` / decimal `2124` as the base Config MIDI enable byte consumed by `MidiPlayer` select/toggle helpers.
- 2026-06-21 B012 Rule 26 Config source-quality pass:
  - Score unchanged at `88/88`.
  - Summary/evidence: incorporated the class-level Config source-quality review: retained the `NexusTK/config/Config.cpp` / `RegistryConfig.cpp` split, kept ProfileStorage as a consumer, documented the fixed table helper names/no-route proof, corrected `ConfigEntryBlock` to `+0x28db10`, corrected string handles to `+0x2911e0`, resolved `+0x2912b4` as `m_midiTrackPaths`, resolved `+0x2916cc` as `m_logDataText` / `LogData`, and recorded that source should expose `virtual ~Config()` rather than a hand-authored deleting-destructor API.
- 2026-06-26 B007 ConfigRawTableHelpers support sync:
  - Score unchanged at `88/88`.
  - Summary/evidence: synchronized [UID:00021Z][0x0048e310-0x0048e479.ConfigRawTableHelpers](by-memory/0x0048e310-0x0048e479.ConfigRawTableHelpers.md) with the accepted B007 implementation: fixed table rows start at `Config + 0x4`, use stride `0x6894`, have active row count at `+0x28d9d4`, use `lookupKey`/`serverName`/`stateBlock`/two 20-entry wide-value sets/trailing dword fields, compare against `g_pApplication->currentServerName`, and now emit formal first-draft C++ from the target page. The raw helper no-route proof remains evidence and score cap rather than a blank-C++ blocker.
- 2026-07-15 B005 UID0003UB callback synchronization:
  - Score, path, source route, helper inventory, and absence of a by-file formal remain unchanged at `88/88`.
  - Added the external UserPane macro-table consumer, exact inherited Config storage/construction proof, declaration-blocking interval inventory, and rejected source routes. RegistryConfig retains default/load/save behavior; ProfileStorage remains an IO consumer; no raw, partial, cast-based, or placeholder-heavy Config declaration is introduced.

## 2026-07-15 UID0003UP Complete Config Source-Route Callback

### Applied declaration and source boundary

- The accepted callback replaces the former data-member-free/placeholder-heavy partial shell with the complete source-era x86/MSVC `Config` declaration used by every emitted `Config::` definition. `Config` remains an `LObject`-derived base object owned/emitted by UID0000IE; existing methods, children, ownership, and unrelated history remain intact.
- The declaration spans exact `sizeof(Config)==0x291918`. It uses typed active members, an anonymous launcher-protocol union, descriptive semantic option/profile fields, and compiler-natural alignment. It emits no raw offset, explicit padding/reserved array, `m_unresolved*`, opaque byte wrapper, numeric slot/type label, schematic A/B field, RegistryConfig downcast, or decompiler scaffolding.
- External `StringBase`, `SimpleUStringVector`, and `LObject` declarations remain canonical dependencies; `StringBase.h` and `StringUtil.h` provide the complete embedded types, while `List` remains pointer-only. No repeated vector declaration or duplicate implementation remains in the Config header.

### Exact support types and cumulative layout

- `ConfigFixedTableText` is `0x202`; `CompactShortcutRecord` is `0x4`; `MacroHotkeyRecord` is `0x108` with natural alignment at state; each `ConfigCharacterServerMacroRow` is `0x6894`; the 100-row slab begins at `+0x4`; and `m_fixedConfigRowCount` is `+0x28d9d4`.
- Exact cumulative offsets are: launcher union/`m_thrunetAuthenticationToken=+0x28d9e0`; `m_serverDirectory=+0x28db10`; `m_loginServerAddress=+0x28de18`; `m_startupConnectionMode=+0x28de28`; `m_fontIndex=+0x28de30`; `m_adapterPhysicalAddressDigest=+0x28de38`; `m_soundEffectsEnabled=+0x28de48`; `m_mapEffectEnabled=+0x28de58`; `m_staticObjectTransparencyEnabled=+0x28de5d`; `m_showUserName=+0x28de5f`; `m_selfLookTopButtonSelected=+0x28de60`; `m_selfLookBottomButtonSelected=+0x28de61`; `m_graphicsSetting=+0x28de68`; `m_hearSnoreMode=+0x28de71`; and `m_mapMovementStatusOption=+0x28de75`.
- High storage continues with `m_profileTextSlots=+0x28de9c`, `m_macroHotkeys=+0x28f2ec`, `m_profileStringSlots=+0x2911e0`, `m_serverEndpointText=+0x291230`, `m_midiTrackPaths=+0x2912b4`, `m_startupAddress=+0x2915b4`, startup port/token union `+0x2916c4`, `m_logDataText=+0x2916cc`, `m_blockListenNames=+0x2918fc`, `m_musicFolderPath=+0x29190c`, and exact end `0x291918`.
- Natural x86/MSVC padding alone accounts for `+0x28d9de..df`, `+0x28de33`, `+0x28de49..4b`, `+0x28de51..53`, `+0x28de67`, and `+0x2918fa..fb`.

### Field and container evidence

- Constructor/destructor, defaults, registry load/save, launcher parsers, OptionPane controls, Ctrl+T, renderer, SelfLook, profile serialization, startup/server selection, music, and movement consumers jointly prove the active layout.

## UID000480 Generated Config Source Closure - 2026-08-15

The Config source route now has no intentionally blank emitting child. Exact by-memory children emit `Config::Config()`, ordinary `Config::~Config()` semantics from the scalar-wrapper range, and the single `Config *g_pConfig = 0` definition. The historical ConfigEntryBlock class identity emits only `ServerSelectDirectory::~ServerSelectDirectory()`, while its declarations remain unique in Config.h and its `ReleaseOwnedBuffers()` method remains on its exact child. Config.cpp includes Config.h and the complete List definition. Raw Config RTTI/vtable objects, scalar-delete flags, vptr stores, vector iterator helpers, member/base teardown, EH scaffolding, and direct generated ABI arrays remain compiler products rather than source.

This closure preserves the existing `93/94` file score and every ownership/range decision. It resolves source-emission completeness only; unavailable original private spellings and final historical header partition remain the existing confidence caps.
- The `+0x28d9e0..+0x28db10` storage is an aligned anonymous union of Thrunet token `[64]`, LG session id/key `[64]`, Generic/Bixel payload `[2][64]`, `ILauncherAuthentication *`, and Kornet World `[3][16]` plus `[256]`; its size is `0x130` and the following server directory remains exact.
- `m_loginServerAddress` is the ANSI login endpoint at `+0x28de18`, distinct from later `m_serverEndpointText[64]`. `m_musicFolderPath` is the final music directory at `+0x29190c`; the old MP3-at-`+0x291230` claim is superseded.
- The movement family directly reads and writes one arbitrary unsigned byte, `m_mapMovementStatusOption`, at `+0x28de75`. Defaults, UI/server writers, and movement consumers rank direct base storage above an accessor, nested aggregate, alias union, separate global, or derived cast.
- Typed character/server macro rows preserve player/server identity, primary/alternate macro fields, 20-row bank semantics, and fixed-row helper behavior. Profile/high storage preserves ten fixed wchar rows, legacy first-wchar values, twenty pointer-backed strings, selected profile text, block-list vector, compact shortcuts, thirty macro hotkeys, startup state, MIDI paths, and minimap flags.

### Historical and negative evidence

- UID0003UB's earlier exhaustive objection to an undeclared derived-only macro field remains valid history; this callback resolves it by declaring the complete base storage rather than reviving a RegistryConfig cast.
- B012/B007 partial layouts, explicit `reserved` spans, empty-key/schematic fixed-row models, numeric options, opaque launcher wrappers, and incomplete endpoint/music interpretations are historicalized and rejected as current source shape.
- Exact original private spellings for some protocol payloads and option gameplay labels remain lexical confidence caps only. Every retained descriptive name maps to bounded behavior; no source dependency or layout interval remains unresolved.

### File ownership and emission policy

- `config/Config.cpp` remains the base-object source route for constructor/destructor, fixed-row helpers, entry cleanup, MIDI/list/string helpers, `g_pConfig`, and the complete declaration. Registry-backed defaults/load/save remain in `config/RegistryConfig.cpp`; ProfileStorage remains the free profile writer owner.
- Existing B001-B016 helper ownership, generated/source inventories, and blank by-file formal remain unchanged. The callback raises only this file's score and replaces the prior incomplete-layout cap with the accepted complete declaration policy.

## 2026-07-15 UID0003UA Compact Shortcut Source Synchronization

- This additive file-root rebase follows the terminal B005 UID0003UP declaration callback and preserves its complete Config module inventory, helper ownership, launcher/profile/option/startup/music evidence, `90/91` score, `config/` route, and blank by-file formal. The terminal B002 UserPane H5/HUZ/H4 work and all unrelated Config/RegistryConfig/ProfileStorage source boundaries are unchanged.
- `CompactShortcutRecord` is exactly 0x4 bytes, not 0x84: `wchar_t code` at row `+0`, `unsigned char isSpellMode` at row `+2`, and one byte of compiler-natural tail alignment at `+3`. The 20-row table begins at base `Config+0x28f29c`; it is direct inherited Config storage rather than a nested user-profile object or derived RegistryConfig-only member.
- Source consumers now share one contract. RegistryConfig defaults/load/save and ProfileStorage initialize or persist `code/isSpellMode`; NewMacroDialog constructor/save/load present and update the same fields; [UID:0003UA][0x005a3a20-0x005a3ad4.UserPaneDispatchConfiguredShortcutHotkey](by-memory/0x005a3a20-0x005a3ad4.UserPaneDispatchConfiguredShortcutHotkey.md) reads them directly and dispatches `isSpellMode != 0` to UserPane command slots or zero to inventory slots.
- The record's `isSpellMode` remains an arbitrary unsigned byte because all writers/readers preserve byte width and runtime consumers test zero/nonzero. No evidence justifies a source `bool`, packed bitfield, explicit tail member, alias union, raw accessor, `m_userProfile` wrapper, or duplicate standalone profile aggregate.
- `config/Config.cpp` owns the complete base declaration and `g_pConfig`; `config/RegistryConfig.cpp` owns registry-backed default/load/save bodies; ProfileStorage owns profile IO; MacroDialogs owns dialog editing; UserPane owns runtime dispatch. This placement resolves cross-translation-unit field spelling without moving any helper or method between source files.
- Historical `key/mode`, `wchar_t/bool`, 0x84 record-size typo, partial declaration, nested profile, RegistryConfig cast, raw offset, opaque storage, explicit reserved byte, and unresolved emitted-member claims are superseded. Exact private spellings remain lexical confidence caps only and do not block the complete direct layout or any generated definition.

## B001 UID0003FV Accepted Callback Synchronization - 2026-07-20

- Final file state is 92/92. UID0000IE remains the sole Config source route and emits the complete UID000031 class declaration; this by-file page intentionally does not duplicate that formal C++.
- The complete public Config layout is exactly 0x291918 bytes and supports direct inherited RegistryConfig parser access. The launcher overlay at +0x28d9e0 is ILauncherAuthenticationPtr *: a pointer to the heap smart-pointer holder allocated by UID0002BN, not a direct interface pointer.
- The holder is initialized lazily only by the selected Excite parser. Config construction does not establish a universal active protocol-union object, and current Config/RegistryConfig destruction performs no holder read, Release, delete, or free; the retained process-lifetime object is preserved rather than hardened.
- All B005/B003 methods, fields, support types, source order, and unrelated current union content remain authoritative. Older incomplete-layout and direct-interface-pointer statements are explicitly superseded by the accepted complete declaration and fresh holder evidence.

## 2026-08-10 B010 UID0002PA Accepted Callback Synchronization

- Final file state is `93/94`; FILE ownership, `NexusTK/config/` path, Config/RegistryConfig split, later complete-layout work, and the intentionally absent by-file formal channels remain unchanged.
- The module inventory now uses private `ServerSelectEntry` and `ServerSelectDirectory` source identities. Their sole exact declarations remain in UID000031's owning formal CPP channel, while the constructor, two cleanup bodies, and directory cleanup remain Config.cpp source items.
- Generic `ConfigEntry`/`ConfigEntryBlock`, selector/text/value/state/flags, count/dirty, `InitializeConfigEntry`/`DestroyConfigEntry`, separate-ConfigEntry.cpp, and null-artifact assumptions remain preserved as dated historical aliases or rejected alternatives, not active source shape.
