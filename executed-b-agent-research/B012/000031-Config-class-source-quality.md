** TARGET-REPORT-UID:000031 **
** AUTHOR-AGENT-ID:B012 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:000031] Config Class Source-Quality Report

Agent: Agent-B012  
Task type: B-agent source-quality / heuristic research  
Target: `E:\NTK\GhidraBridge\source-3\project-documentation\by-class\Config.md`  
Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B012\research\000031-Config-class-source-quality.md`  
Disposition: report-only. No by-* documentation edited. `by-memory/-coverage-report.md` not edited.

## Executive Recommendation

`Config` should stay source-bearing, reconstructable, and emitted through [UID:0000IE] `Config` / `NexusTK/config/Config.cpp`. The class is ready for a first-draft source declaration, but not a final layout-complete declaration: the exact 100-row fixed settings table member names and the raw table helper caller route remain unresolved.

Recommended target metadata after implementation:

```text
COMPLETION:87
CONFIDENCE:89
CANONICAL_OWNER:0000IE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000IE
```

The score should rise from `85/86` to `87/89` because this pass resolves the stale destructor offset map, separates the true `ConfigEntryBlock` from the MIDI track-path `List`, assigns source-facing names to the main helpers, and closes the destructor-versus-scalar-wrapper policy. Completion stays below `90` because the large fixed table is still not field-complete and the raw table helpers have no proven route.

The class-level C++ should be a declaration shell plus known helper declarations and small nested storage types. Do not emit method bodies from the class page. Populate method bodies only in the exact by-memory child pages that are accepted for C++.

## Evidence Checked

Instruction and process docs:

- `source-3/project-documentation/tools/leaser/Agents/Agent-B012/goal.md`
- `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md`
- `source-3/project-documentation/by-structure.md`
- `source-3/project-documentation/inference_research.md`

Target and direct support docs:

- `by-class/Config.md`
- `by-file/Config.md`
- `by-class/ConfigEntryBlock.md`
- `by-memory/0x0048e550-0x0048e77a.ConfigConstructor.md`
- `by-memory/0x00494020-0x00494126.ConfigDeletingDestructor.md`
- `by-memory/0x0048e310-0x0048e479.ConfigRawTableHelpers.md`
- `by-memory/0x0048e480-0x0048e4a8.ConfigEntryInitialize.md`
- `by-memory/0x0048e4b0-0x0048e54a.ConfigEntryDestroyHelpers.md`
- `by-memory/0x0048ea70-0x0048ea9f.ConfigEntryVectorCopyWrappersRaw.md`
- `by-memory/0x0048eaa0-0x0048ebb3.ConfigStringPreferenceHelpers.md`
- `by-memory/0x00494130-0x004941d6.ConfigEntryBlockReleaseOwnedBuffers.md`
- `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`
- `by-memory/0x006168d0-0x006168e8.ConfigVtableData.md`
- `by-memory/0x0048e480-0x0048f3f1.ConfigAndRegistryDefaults.md`
- `by-memory/0x00491b30-0x004941d6.RegistryPersistenceAndConfigEntryCleanup.md`
- `by-memory/0x00491b30-0x00492695.RegistryConfigSaveToRegistry.md`
- `by-memory/0x004926a0-0x00493e29.RegistryConfigLoadFromRegistry.md`
- `by-memory/0x00493ef0-0x00493efb.ConfigGlobalClearUnwindHelper.md`
- `by-class/RegistryConfig.md`
- `by-file/RegistryConfig.md`
- `by-class/List.md`
- `by-file/List.md`
- `by-memory/0x004f3060-0x004f30d5.ListConstructor.md`
- `by-memory/0x004f3140-0x004f31cc.ListAssignFrom.md`
- `by-memory/0x0067ab1c-0x0067ab20.g_pApplication.md`
- `auto-generated/NexusTK/config/Config.cpp`
- class/file/memory/generated coverage reports

Prior B-agent reports used as leads:

- `Agent-B005/research/00032H-ConfigEntryVectorCopyWrappersRaw-source-quality.md`
- `Agent-B003/research/0002P8-RegistryConfigLoadFromRegistry-source-quality.md`
- `Agent-B001/research/executed/older/000110-ConfigAndRegistryDefaults.md`
- `Agent-B001/research/executed/older/000111-RegistryPersistenceAndConfigEntryCleanup.md`
- B-agent Rule 26 incorporation tracker rows for the Config/RegistryConfig split

Local prewave function exports and decompiled bundles checked:

- `0x0048e550` `Config::Config`: Ghidra signature `Config * __thiscall Config(Config * this)`, IDA size `554`.
- `0x00494020` deleting destructor wrapper/body: Ghidra signature `Config * __thiscall ~Config(Config * this, uint param_1)`, IDA size `262`.
- `0x0048e310` raw table lookup/append helper: Ghidra-modeled, IDA not modeled, no callers.
- `0x0048e480` ConfigEntry initializer: 40 bytes.
- `0x0048e4b0` ConfigEntry destructor callback: 74 bytes.
- `0x0048e500` duplicate/scratch ConfigEntry cleanup helper: 74 bytes.
- `0x0048eaa0` MIDI path lookup: 87 bytes, one caller.
- `0x0048eb00` MIDI path setter: 78 bytes, one caller.
- `0x0048eb50` LogData string replacement: 99 bytes, five callers.
- `0x00494130` `ConfigEntryBlock::ReleaseOwnedBuffers`: 166 bytes.
- `0x0048ea70` and `0x0048ea90` raw wrapper starts exist in prewave, but existing IDA/no-route evidence still applies.

## Current Target State

`by-class/Config.md` currently has:

```text
COMPLETION:85
CONFIDENCE:86
CANONICAL_OWNER:0000IE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000IE
RECONSTRUCTION_CPP: blank
```

The page correctly identifies `Config` as the base in-memory client configuration singleton under `Config.cpp`, but it still has three source-quality blockers:

- stale/generic field wording, especially the `this + 0x2912b4` "config-entry vector" wording;
- stale destructor offset descriptions in the by-memory support page;
- no policy decision for source destructor declaration versus MSVC scalar deleting destructor wrapper.

All three can be improved now.

## Resolved Source-Quality Issues

### Source File And Header Split

Keep the source route:

```text
NexusTK/config/Config.h
NexusTK/config/Config.cpp
NexusTK/config/RegistryConfig.h
NexusTK/config/RegistryConfig.cpp
```

`Config` owns the base storage, constructor, base destructor semantics, `g_pConfig`, `ConfigEntry`, `ConfigEntryBlock`, the fixed table helpers, MIDI path list helpers, and `LogData` helper. `RegistryConfig` owns defaults, command-line normalization, registry load/save, and persistence of inherited `Config` fields. `ProfileStorage` remains a consumer of the user/profile slice, not the owner of `Config` or `RegistryConfig`.

Rejected alternatives:

- `profile/ProfileStorage.cpp` ownership: rejected because constructor/destructor, `g_pConfig`, fixed rows, and ConfigEntry storage are lower-level config infrastructure.
- direct `RegistryConfig` ownership for base helper pages: rejected because helpers either construct base `Config` storage or access base `Config` fields.
- new required `ConfigEntry.cpp`: not justified yet. A private `ConfigEntry`/`ConfigEntryBlock` declaration in `Config.h` or `Config.cpp` is enough unless later consumers require public exposure.

### Singleton Lifecycle

`Config::Config`:

- calls `LObject::LObject`;
- writes `g_pConfig` (`0x0067a7c8`) to `this`, guarded only by the inherited base pointer check;
- installs the `Config` vtable `0x006168d0`;
- initializes base storage.

The runtime object is usually `RegistryConfig`, but the base constructor owns initial publication of `g_pConfig`. `RegistryConfig` construction then promotes the vtable and runs defaults/load.

`0x00494020`:

- is the vtable slot for `Config`;
- contains the ordinary base destructor work plus the compiler scalar-deleting wrapper flag logic;
- clears `g_pConfig` after member cleanup and before `LObject` destruction;
- conditionally calls delete only when `(flags & 1) != 0` and `(flags & 4) == 0`.

Source declaration should be:

```cpp
virtual ~Config();
```

Do not write a human `Config::DeletingDestructor(unsigned int flags)` method in final source. The flag parameter is compiler ABI glue. The by-memory page can remain reconstructable and scalar-wrapper-aware, but source C++ should present the ordinary destructor semantics.

### Corrected Field / Offset Map

The current `ConfigDeletingDestructor` support page contains stale offsets. Prewave decompilation and IDA exact offsets support this corrected map:

| Offset | Best source-facing role | Evidence |
| --- | --- | --- |
| `+0x28d9d4` | fixed table active row count | Raw table helper reads/increments this count. |
| fixed table rows, stride `0x6894`, count 100 | large fixed client settings/server table | Constructor and raw reset helper loop 100 rows with stride `0x6894`. |
| `+0x28db10` | `ConfigEntryBlock` / server-entry block | Constructor runs EH vector constructor over 32 entries here; cleanup and destructor pass the same address. |
| `+0x28de10` | `ConfigEntryBlock::count` | 32 entries * `0x18` = `0x300`; cleanup reads/writes block `+0x300`. |
| `+0x28de14` | `ConfigEntryBlock::dirty` / state byte | Cleanup resets block `+0x304`. |
| `+0x28de18` | vector/string-style member destroyed by `sub_582B30` | Constructor calls `sub_582A80`; destructor calls `sub_582B30`. Exact semantic name unresolved. |
| `+0x28de32` and later | user-visible option bytes/blocks | `g_pConfig` support doc maps icons, sound, map/movement, graphics/shadow, target, chat, color, and power settings. |
| `+0x2911dc..+0x2911df` | target option rows | `g_pConfig` support ties ARROW and SHIFT+ARROW user/monster target toggles to these bytes. |
| `+0x2911e0` | 20 4-byte string-handle entries | Constructor/destructor EH vector iterators use element size `4`, count `0x14`. Current `+0x291060` wording is stale. |
| `+0x291230` | `m_mp3Directory` / `m_musicDirectory` 64-wide-char buffer | Constructor clears 64 `wchar_t` via `_wcscpy_s`; registry save/load docs include `MP3Dir`. |
| `+0x2912b4` | `m_midiTrackPaths` (`List*`) | Constructor allocates 20-byte `List` and calls `List::List(0x42, 0x10)`; B005 and string helpers prove MIDI path semantics. |
| `+0x2915b4` | zeroed pointer/state | Constructor clears; exact semantic name unresolved. Preserve as field evidence, not final name. |
| `+0x2916c4` | zeroed pointer/state | Constructor clears; exact semantic name unresolved. |
| `+0x2916cc` | `m_logDataText` / `LogData` wide heap pointer | Registry load report maps `LogData`; helper `0x0048eb50` frees/replaces this heap pointer. |
| `+0x2916d0` | 16-wide-char buffer | Constructor clears with `_wcscpy_s(..., 0x10, L"")`; likely adjacent registry/current-server string, exact original name unresolved. |
| `+0x2918f0` | string-style object | Constructor/destructor call `sub_582B20`/`sub_582B70`. |
| `+0x2918fc` | block-list vector/storage span | `g_pConfig` support doc maps this as block-list vector/storage; destructor calls `sub_493F10`. |
| `+0x29190c` | music-control string-style object | Constructor/destructor call `sub_582B20`/`sub_582B70`. |
| `+0x291915..+0x291917` | music-control byte/word defaults | Constructor stores `0x0101` at `+0x291915` and zero at `+0x291917`. |

Rejected stale offsets:

- `this + 0x28dbd0` for `ConfigEntryBlock`: rejected. Constructor, destructor, and `ConfigEntryBlock::ReleaseOwnedBuffers` line up on `this + 0x28db10`.
- `this + 0x291060` for the 20-entry string-handle array: rejected. Current prewave/IDA decompilation uses `this + 0x2911e0`.
- `this + 0x2913b4` for the owned list/resource: rejected. The destructor's pointer slot is `*((DWORD*)this + 672941)`, which is `+0x2912b4`.
- broad "config-entry vector" for `+0x2912b4`: rejected. This is a heap `List*` of MIDI track-path records, not the 32-entry `ConfigEntryBlock`.

### ConfigEntry And ConfigEntryBlock

The 32-entry base block is source-facing `ConfigEntryBlock`, probably with a private nested/nearby `ConfigEntry` record:

```cpp
struct ConfigEntry
{
    unsigned char selector;      // +0x00
    unsigned char reserved0[3];  // +0x01
    wchar_t *primaryText;        // +0x04
    wchar_t *secondaryText;      // +0x08
    wchar_t *tertiaryText;       // +0x0c
    unsigned short value;        // +0x10
    unsigned short state;        // +0x12
    unsigned short flags;        // +0x14
    unsigned short reserved1;    // +0x16
};

struct ConfigEntryBlock
{
    ConfigEntry entries[32];     // +0x000
    int count;                   // +0x300
    unsigned char dirty;         // +0x304
};
```

This field spelling is descriptive, not original-proof. The three pointer fields are exact enough for cleanup logic: `0x0048e4b0`, `0x0048e500`, and `0x00494130` all free offsets `+4`, `+8`, and `+0xc`.

Recommended helper names:

- `ConfigEntry::ConfigEntry()` or `InitializeConfigEntry(ConfigEntry*)` for `0x0048e480`.
- `ConfigEntry::~ConfigEntry()` for `0x0048e4b0`, used as the EH vector destructor callback.
- `DestroyConfigEntryScratch(ConfigEntry*)` or `ReleaseConfigEntryOwnedBuffers(ConfigEntry*)` for `0x0048e500`, the duplicate body used by `sub_4F6D80`/server-select scratch cleanup.
- `ConfigEntryBlock::ReleaseOwnedBuffers()` for `0x00494130`.

Rejected alternatives:

- Treating `0x0048e480/0x0048e4b0` as compiler-only vector glue: rejected. These are source-shaped element constructor/destructor bodies over a project-specific 0x18-byte record.
- Treating `0x0048e500` as a separate unrelated class method: rejected. It is byte-equivalent cleanup for the same 0x18-byte record layout.

### MIDI Track Path List And String Helpers

B005's report for [UID:00032H] is the right direction and should be incorporated into the class page.

`Config + 0x2912b4` is:

```cpp
List *m_midiTrackPaths;
```

Constructor evidence:

- allocates `0x14` / 20 bytes for a `List` object;
- calls `List::List(0x42, 0x10)`;
- stores the result at `this + 0x2912b4`.

Record shape:

```cpp
struct ConfigMidiTrackPathEntry
{
    unsigned char selector;
    unsigned char reserved;
    wchar_t path[32];
};
```

The element size is `0x42` / 66 bytes, matching selector byte, one alignment byte, and 32 UTF-16 characters. The string helpers prove `entry + 2` is a fixed 32-wide-character path.

Recommended source-facing helper declarations:

```cpp
void CopyMidiTrackPathsTo(List *destination) const;
void CopyMidiTrackPathsFrom(List *source);
void GetMidiTrackPath(unsigned char selector, wchar_t *destination, size_t destinationCount) const;
void SetMidiTrackPath(unsigned char selector, const wchar_t *source);
```

Function evidence:

- `0x0048ea70`: `destination->AssignFrom(m_midiTrackPaths)`.
- `0x0048ea90`: `m_midiTrackPaths->AssignFrom(source)` via tail jump.
- `0x0048eaa0`: scans `m_midiTrackPaths->count`, uses virtual slot `+0x10`/`List::GetElementAt`, compares selector byte, `_wcscpy_s(destination, destinationCount, entry->path)`, and clears `*destination` when not found.
- `0x0048eb00`: same selector scan, then `_wcscpy_s(entry->path, 0x20, source)`.

Rejected names:

- `m_configEntryVector`: rejected because it conflicts with the separate `ConfigEntryBlock`.
- `m_registryEntries`: rejected because RegistryConfig persists the list but base Config owns and MIDI consumes it.
- `m_stringPreferences`: directionally true but less precise than MIDI path evidence.

### LogData Heap String

`0x0048eb50` should be named as a `LogData` setter/replacer:

```cpp
void SetLogData(const wchar_t *source);
```

Evidence:

- helper frees `this + 0x2916cc`;
- computes the source wide-string length;
- allocates `(length + 1) * sizeof(wchar_t)`;
- writes the new pointer to `this + 0x2916cc`;
- copies with `_wcscpy_s`.

B003's RegistryConfig load report maps registry `LogData` to `+0x2916cc` as a `REG_BINARY` even-length wide string. The five callers from login/create-user/server-message UI paths are consumers that store a short UI/log string into the active config object.

Rejected alternatives:

- generic heap-backed "string preference": too vague now that registry `LogData` evidence exists.
- server-list or MIDI ownership: rejected by `LogData` registry key and distinct `m_midiTrackPaths` field.

### Raw Fixed Table Helpers

[UID:00021Z] remains reconstructable Config source evidence, but not source-body-ready.

Current best source-facing helper names:

```cpp
int FindOrAppendFixedConfigTableRow();
void ResetFixedConfigTableRows();
```

The first name is intentionally descriptive. It likely acts on a current-server/current-environment fixed row, because it compares one row string against a local 40-wide-character buffer and another against `g_pApplication + 0x858`. B013 support identifies `dword_67AB1C + 0x858` as the `g_pApplication` current-server/current-application string area, not an unknown global.

Evidence:

- `0x0048e310` Ghidra models a function; IDA still does not.
- no direct callers/xrefs/pointer hits have been found for `0x0048e310` or `0x0048e410`.
- row count is at `Config + 0x28d9d4`;
- row stride is `0x6894`;
- table row count is 100;
- reset helper clears 100 rows and two 20-entry wide-value subarrays.

Recommended policy:

- Keep owner/emitter [UID:0000IE] `Config`.
- Keep C++ blank in [UID:00021Z] until a live route or original helper-name context is recovered.
- Do not block class-level first-draft declaration on this raw helper island; describe it in prose and keep only private declarations if needed.

Rejected alternatives:

- padding/data: rejected by executable instruction bodies and unique helper shape.
- compiler/runtime helper: rejected by direct `Config` object/table field semantics.
- RegistryConfig ownership: rejected because the helpers act on base fixed storage and sit before ConfigEntry construction.

### Destructor / Scalar Deleting Wrapper Policy

`0x00494020` is not a normal source method named `DeletingDestructor`. It is the MSVC scalar deleting destructor entry that contains:

- ordinary `Config::~Config()` body;
- scalar-delete ABI flag checks;
- conditional `operator delete(this)`;
- no-op behavior for `flags & 4`.

Recommended source presentation:

- In `Config` class C++: declare `virtual ~Config();`.
- In [UID:0002P9] support prose: explicitly call it a scalar deleting destructor wrapper carrying the base destructor body.
- In [UID:0002P9] C++ block: either keep blank or emit only the ordinary destructor body if the supervisor wants memory-page C++; do not emit a source method with `deleteFlags`.

Recommended destructor body semantics to document:

1. Restore Config vtable `0x006168d0`.
2. Delete `m_midiTrackPaths` at `+0x2912b4` through its virtual destructor and clear the slot.
3. Free `m_logDataText` at `+0x2916cc`.
4. Destroy string/vector-style members at `+0x29190c`, `+0x2918fc`, `+0x2918f0`, `+0x2911e0`, and `+0x28de18` using existing string/list support helpers.
5. Call `ConfigEntryBlock::ReleaseOwnedBuffers()` at `+0x28db10`.
6. Run the EH vector destructor over 32 `ConfigEntry` records at `+0x28db10`.
7. Clear `g_pConfig`.
8. Destroy `LObject`.
9. Let compiler-generated scalar-delete wrapper handle conditional delete.

## Recommended Target C++

Populate `by-class/Config.md` with a declaration-only first draft. This is intentionally not a layout-complete class definition; the offset map belongs in prose until the large fixed table is fully named.

```cpp
class List;
class LObject;

struct ConfigEntry
{
    unsigned char selector;
    unsigned char reserved0[3];
    wchar_t *primaryText;
    wchar_t *secondaryText;
    wchar_t *tertiaryText;
    unsigned short value;
    unsigned short state;
    unsigned short flags;
    unsigned short reserved1;
};

struct ConfigEntryBlock
{
    ConfigEntry entries[32];
    int count;
    unsigned char dirty;

    void ReleaseOwnedBuffers();
};

struct ConfigMidiTrackPathEntry
{
    unsigned char selector;
    unsigned char reserved;
    wchar_t path[32];
};

class Config : public LObject
{
public:
    Config();
    virtual ~Config();

    int FindOrAppendFixedConfigTableRow();
    void ResetFixedConfigTableRows();

    void CopyMidiTrackPathsTo(List *destination) const;
    void CopyMidiTrackPathsFrom(List *source);
    void GetMidiTrackPath(unsigned char selector, wchar_t *destination, size_t destinationCount) const;
    void SetMidiTrackPath(unsigned char selector, const wchar_t *source);
    void SetLogData(const wchar_t *source);
};

extern Config *g_pConfig;
```

Notes for implementation:

- If the project avoids nested helper declarations in class pages, move `ConfigEntry`, `ConfigEntryBlock`, and `ConfigMidiTrackPathEntry` to the prose/type section and keep only the `Config` declaration in the C++ block.
- Do not include the raw scalar deleting destructor signature.
- Do not force byte-padding fields into the class C++ yet; that would create a misleading pseudo-layout.

## Exact Recommended Doc Changes

### `by-class/Config.md`

1. Change metadata:

```text
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Keep:

```text
*** CANONICAL_OWNER:0000IE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

2. Populate the C++ block with the declaration draft above.

3. Replace the method row:

```text
`Config::DeletingDestructor(unsigned int deleteFlags)`
```

with:

```text
`virtual ~Config()` / scalar deleting destructor wrapper at `0x00494020`
```

and explain that the by-memory function includes MSVC delete-flag glue.

4. Replace the `ConfigEntryVectorCopyWrappersRaw` related-helper wording with:

```text
retained private Config wrappers that copy `m_midiTrackPaths` (`Config +0x2912b4`, heap `List*`, constructed as `List(0x42, 0x10)`) to/from caller-supplied `List` objects through `List::AssignFrom`.
```

5. Add a layout section containing the corrected offset table from this report, including `+0x28db10`, `+0x2911e0`, `+0x291230`, `+0x2912b4`, `+0x2916cc`, and `+0x2918fc`.

6. Add a source-quality change entry:

```text
- 2026-06-19 B012 source-quality pass:
  - Recommended `85/86 -> 87/89`, populated first-draft class declaration guidance, resolved `+0x2912b4` as `m_midiTrackPaths` rather than a ConfigEntry vector, resolved `+0x2916cc` as `LogData` heap wide text, corrected destructor/layout offsets (`ConfigEntryBlock` at `+0x28db10`, 20 string handles at `+0x2911e0`, MIDI list at `+0x2912b4`), and documented that `0x00494020` is a scalar deleting destructor wrapper while source should declare `virtual ~Config()`.
```

### `by-file/Config.md`

1. Recommended metadata:

```text
COMPLETION:88
CONFIDENCE:88
```

2. Replace "Config-entry vector wrappers" with "MIDI track-path list copy wrappers".

3. Add the corrected helper/field note:

```text
`Config +0x2912b4` is `m_midiTrackPaths`, a heap `List*` constructed as `List(0x42, 0x10)`. It is persisted by RegistryConfig under the `Midi` subkey and consumed by Config MIDI path helpers; it is not the embedded 32-entry ConfigEntryBlock.
```

4. Add the destructor policy note:

```text
The source declaration is `virtual ~Config()`. The exact by-memory child at `0x00494020` is the MSVC scalar deleting destructor entry and should not be treated as a hand-written `DeletingDestructor` API.
```

5. Preserve `RegistryConfig.cpp` separation and ProfileStorage rejection.

### `by-memory/0x0048e550-0x0048e77a.ConfigConstructor.md`

Add the constructor field map:

- `g_pConfig` install at `0x0067a7c8`.
- fixed table initialization: 100 rows, stride `0x6894`, count `+0x28d9d4`.
- 32 `ConfigEntry` construction at `+0x28db10`.
- `ConfigEntryBlock` count/dirty zero at `+0x28de10/+0x28de14`.
- string/vector member construction at `+0x28de18`.
- 20 string-handle construction at `+0x2911e0`.
- `m_mp3Directory` 64-wide-char buffer clear at `+0x291230`.
- `m_midiTrackPaths = new List(0x42, 0x10)` at `+0x2912b4`.
- `m_logDataText` zero at `+0x2916cc`.
- music/block-list members at `+0x2918f0`, `+0x2918fc`, `+0x29190c`, and default flags at `+0x291915..+0x291917`.

Recommended score: `87/90`.

### `by-memory/0x00494020-0x00494126.ConfigDeletingDestructor.md`

Fix the stale offset descriptions:

- `this + 0x2913b4` -> `this + 0x2912b4` (`m_midiTrackPaths`).
- `this + 0x291060` -> `this + 0x2911e0` (20 string-handle entries).
- `this + 0x28dbd0` -> `this + 0x28db10` (`ConfigEntryBlock`).
- vague `this + 0x291540/+0x291574/+0x291584/+0x28de28` -> corrected members `+0x29190c`, `+0x2918fc`, `+0x2918f0`, and `+0x28de18`.
- `this + 0x2917c4` raw allocation -> recheck before retaining; current decompile-proven heap free is `+0x2916cc` (`m_logDataText`).

Rename/reframe the method in prose as:

```text
Config scalar deleting destructor wrapper carrying the ordinary `Config::~Config` body
```

Recommended score: `87/90`.

### `by-memory/0x0048e480-0x0048e4a8.ConfigEntryInitialize.md`

Add the `ConfigEntry` layout:

- `+0x00` selector byte;
- `+0x04/+0x08/+0x0c` owned heap pointer fields;
- `+0x10`, `+0x12`, `+0x14` state/value/flag words cleared through one word write and one dword write.

Recommended source-facing name: `ConfigEntry::ConfigEntry()` or `InitializeConfigEntry`.

Recommended score: `86/89`.

### `by-memory/0x0048e4b0-0x0048e54a.ConfigEntryDestroyHelpers.md`

Add that both helper bodies free the same three pointer fields at `+4/+8/+0xc` and clear those slots. Distinguish:

- `0x0048e4b0`: EH vector destructor callback / `ConfigEntry::~ConfigEntry`.
- `0x0048e500`: direct scratch-entry cleanup helper / duplicate source helper.

Recommended score: `86/89`.

### `by-memory/0x0048ea70-0x0048ea9f.ConfigEntryVectorCopyWrappersRaw.md`

Apply B005's exact direction:

- Rename role from config-entry vector to MIDI track-path list wrappers.
- Use `m_midiTrackPaths` and `List::AssignFrom`.
- Populate first-draft C++ in that child if supervisor accepts B005.
- Recommended score: `88/90`.

### `by-memory/0x0048eaa0-0x0048ebb3.ConfigStringPreferenceHelpers.md`

Replace generic names with:

- `Config::GetMidiTrackPath(unsigned char selector, wchar_t *destination, size_t destinationCount)` for `0x0048eaa0`.
- `Config::SetMidiTrackPath(unsigned char selector, const wchar_t *source)` for `0x0048eb00`.
- `Config::SetLogData(const wchar_t *source)` for `0x0048eb50`.

Add `m_midiTrackPaths` and `m_logDataText` field evidence. Recommended score: `88/90`.

### `by-memory/0x0048e310-0x0048e479.ConfigRawTableHelpers.md`

Keep C++ blank, but update names/prose:

- `FindOrAppendFixedConfigTableRow` for `0x0048e310`.
- `ResetFixedConfigTableRows` for `0x0048e410`.
- replace `dword_67AB1C` wording with `g_pApplication`, with the compared field currently described as `g_pApplication +0x858` current-server/application text.
- preserve no-function/no-xref/no-pointer-route caveat.

Recommended score: keep `85/88`.

### `by-memory/0x00494130-0x004941d6.ConfigEntryBlockReleaseOwnedBuffers.md`

Add explicit parent-offset evidence:

- when called from Config/RegistryConfig, block base is `this +0x28db10`;
- `count` is block `+0x300` -> object `+0x28de10`;
- `dirty`/state byte is block `+0x304` -> object `+0x28de14`.

Recommended score: `86/91`.

### `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`

Add or cross-link:

- `+0x291230` as MP3/music directory buffer.
- `+0x2912b4` as `m_midiTrackPaths`.
- `+0x2916cc` as `m_logDataText` / `LogData`.
- confirm existing `+0x2918fc` block-list vector/storage.

No score change required unless the supervisor wants the global row refreshed.

### `by-class/ConfigEntryBlock.md`

Add corrected embedding note:

```text
In `Config`, the block begins at `+0x28db10`; its `count` and dirty/state byte land at `+0x28de10` and `+0x28de14`.
```

No need to move ownership away from Config.

## Support Updates To Avoid

- Do not move `RegistryConfig::LoadFromRegistry`, `SaveToRegistry`, defaults, or command-line parsers into `Config`.
- Do not move `ConfigEntryBlock` cleanup into `RegistryConfig` just because registry load/destructor call it.
- Do not attach `0x00493e30` adapter formatter clone to Config; current support rightly keeps it with the RegistryConfig file-level raw/dead helper route.
- Do not make the class C++ layout-complete with large byte arrays solely to force binary offsets; this would be less source-like than a declaration shell plus documented offset map.

## Open Questions And Attempted Resolution

| Question | Attempted resolution | Current recommendation |
| --- | --- | --- |
| Exact original name for the 100-row fixed table | Checked constructor, raw helpers, Config/Registry save/load docs, g_pApplication docs. No caller route or string literal proves a final name. | Use descriptive `fixedConfigTable` / `FindOrAppendFixedConfigTableRow`; do not emit raw helper C++ yet. |
| Exact original name for `+0x28de18` string/vector member | Constructor/destructor helper calls prove lifetime, but support docs do not yet map consumer semantics. | Document offset and helper family; leave exact field name open. |
| Exact original `ConfigEntry` field names | Init/destroy/cleanup prove layout and owned pointer fields; registry/server load docs tie it to server/multiserver entries. | Use `primaryText`, `secondaryText`, `tertiaryText`, `value/state/flags` as descriptive placeholders. |
| Whether `0x0048ea70/ea90` are live | B005 direct PE scan found no calls/jumps, VA/RVA pointer hits, export, or vtable route. | Treat as retained private source wrappers; emit child C++ only with no-route caveat. |
| Whether `0x00494020` should be no-code | It is compiler scalar deleting destructor ABI, but contains the ordinary destructor body and is the only vtable entry. | Class C++ should declare `virtual ~Config`; by-memory page should avoid a fake `DeletingDestructor` API. |
| Header/source split for helper declarations | Config and RegistryConfig split is stable; only ConfigEntry exposure is uncertain. | Put `ConfigEntry`/`ConfigEntryBlock` near Config for now; header exposure can remain open. |

## IDA Rename / Type / Comment Recommendations

No IDA edits were made.

Recommended future IDA changes:

- `0x0048e550`: `Config::Config`; confidence high.
- `0x00494020`: `Config::scalar_deleting_destructor` or IDA-style `Config::'scalar deleting destructor'`; add comment "contains ordinary Config::~Config body plus MSVC delete-flag wrapper"; confidence high.
- `0x0048e480`: `ConfigEntry::ConfigEntry` / `InitializeConfigEntry`; confidence high for behavior, medium for exact spelling.
- `0x0048e4b0`: `ConfigEntry::~ConfigEntry`; confidence high.
- `0x0048e500`: `DestroyConfigEntryScratch` / `ReleaseConfigEntryOwnedBuffers`; confidence medium-high.
- `0x00494130`: `ConfigEntryBlock::ReleaseOwnedBuffers`; confidence high.
- `0x0048ea70`: `Config::CopyMidiTrackPathsTo`; confidence high for behavior, medium for exact original name.
- `0x0048ea90`: `Config::CopyMidiTrackPathsFrom`; confidence high for behavior, medium for exact original name.
- `0x0048eaa0`: `Config::GetMidiTrackPath`; confidence high.
- `0x0048eb00`: `Config::SetMidiTrackPath`; confidence high.
- `0x0048eb50`: `Config::SetLogData`; confidence high.
- `0x0048e310`: `Config::FindOrAppendFixedConfigTableRow`; confidence medium.
- `0x0048e410`: `Config::ResetFixedConfigTableRows`; confidence medium.

Recommended field comments:

- `Config +0x28db10`: `m_serverEntries` / `m_configEntryBlock`; type `ConfigEntryBlock`.
- `Config +0x28de10`: `m_serverEntries.count`.
- `Config +0x28de14`: `m_serverEntries.dirty`.
- `Config +0x291230`: `m_mp3Directory` / `m_musicDirectory`.
- `Config +0x2912b4`: `m_midiTrackPaths`; type `List*`.
- `Config +0x2916cc`: `m_logDataText`; type `wchar_t*`.
- `Config +0x2918fc`: block-list vector/storage.
- `0x0067a7c8`: `Config *g_pConfig`; runtime object commonly `RegistryConfig*`.

## Exact Pending Coverage Text

Do not edit `by-memory/-coverage-report.md` during this report-only pass. If implementation is accepted, the supervisor can use the following rows as exact replacement text.

### `by-class/-coverage-report.md`

Replace the current `000031` row with:

```text
- [UID:000031][Config](by-class/Config.md) : reconstructable : 87% : very strong : B012 source-quality pass keeps owner/emitter [UID:0000IE][Config](by-file/Config.md) and resolves first-draft class declaration readiness: `g_pConfig` lifecycle, constructor/destructor route, fixed table row count at `+0x28d9d4`, `ConfigEntryBlock` at `+0x28db10` with count/dirty at `+0x28de10/+0x28de14`, option/chat/target fields from global support, 20 string handles at `+0x2911e0`, MP3/music directory at `+0x291230`, MIDI track-path `List*` at `+0x2912b4` (`List(0x42,0x10)`), `LogData` heap wide string at `+0x2916cc`, block-list/music members at `+0x2918f0..+0x291917`, ConfigEntry helper layout, and scalar-deleting-destructor policy documented. Stale `ConfigEntryVector`, `+0x28dbd0`, `+0x291060`, and `+0x2913b4` wording is rejected; source should declare `virtual ~Config()` while the by-memory destructor page remains MSVC wrapper-aware.
```

### `by-file/-coverage-report.md`

Replace the current `0000IE` row with:

```text
- [UID:0000IE][Config](by-file/Config.md) : reconstructable : 88% : very strong : Config module source-quality refresh keeps the `NexusTK/config/Config.cpp` / `RegistryConfig.cpp` split, routes base `Config`, `g_pConfig`, `ConfigEntry`, `ConfigEntryBlock`, raw fixed-table helpers, MIDI track-path list helpers, and `LogData` helper to Config while preserving RegistryConfig registry/default ownership and ProfileStorage as a consumer. B012 resolves `+0x2912b4` as `m_midiTrackPaths` (`List(0x42,0x10)`) instead of a ConfigEntry vector, `+0x2916cc` as `LogData`, `ConfigEntryBlock` at `+0x28db10`, destructor source policy as `virtual ~Config()` plus MSVC scalar wrapper at `0x00494020`, and keeps raw table helpers source-shaped but C++-blank pending caller/name proof.
```

### `by-memory/-coverage-report.md` rows

Replace the stale `00021Z` row with:

```text
    - [UID:00021Z][0x0048e310-0x0048e479.ConfigRawTableHelpers](by-memory/0x0048e310-0x0048e479.ConfigRawTableHelpers.md) 0x0048e310-0x0048e479 | raw helper cluster | ConfigRawTableHelpers : reconstructable : 85% : strong : Current source-quality state keeps owner/emitter [UID:0000IE][Config](by-file/Config.md): Ghidra models `0x0048e310` as a fixed Config table lookup/append helper over row count `+0x28d9d4`, 100 rows, and stride `0x6894`, comparing row strings against a local 40-wide-character buffer and `g_pApplication +0x858`; raw `0x0048e410` resets the same fixed table and two 20-entry wide-value subarrays. IDA still has no function objects/xrefs and direct call/jump/VA/RVA route scans found no route to either raw start, so first-draft source names `FindOrAppendFixedConfigTableRow` and `ResetFixedConfigTableRows` are documented but C++ remains blank pending caller/name proof.
```

Replace the stale `00030S` row with:

```text
        - [UID:00030S][0x0048e550-0x0048e77a.ConfigConstructor](by-memory/0x0048e550-0x0048e77a.ConfigConstructor.md) 0x0048e550-0x0048e77a | constructor | ConfigConstructor : reconstructable : 87% : very strong : B012 source-quality recheck keeps direct class owner [UID:000031][Config](by-class/Config.md) and resolves constructor field shape: publishes `g_pConfig`, installs Config vtable `0x006168d0`, initializes the 100-row fixed table and count at `+0x28d9d4`, constructs 32 `ConfigEntry` records at `+0x28db10`, seeds `ConfigEntryBlock` count/dirty at `+0x28de10/+0x28de14`, constructs string/vector members including 20 string handles at `+0x2911e0`, clears MP3/music directory at `+0x291230`, allocates `m_midiTrackPaths` as `List(0x42,0x10)` at `+0x2912b4`, zeros `LogData` at `+0x2916cc`, and initializes block-list/music-control fields through `+0x291917`.
```

Replace the stale `00032H` row with B005's accepted text:

```text
        - [UID:00032H][0x0048ea70-0x0048ea9f.ConfigEntryVectorCopyWrappersRaw](by-memory/0x0048ea70-0x0048ea9f.ConfigEntryVectorCopyWrappersRaw.md) 0x0048ea70-0x0048ea9f | raw wrapper pair | ConfigEntryVectorCopyWrappersRaw : reconstructable : 88% : very strong : Source-quality recheck keeps owner/emitter [UID:0000IE][Config](by-file/Config.md) and resolves the raw wrappers as retained private Config MIDI track-path list copy helpers: `0x0048ea70` copies `m_midiTrackPaths` (`Config +0x2912b4`, heap `List*`, `List(0x42,0x10)`) into a caller list through `List::AssignFrom`, while `0x0048ea90` copies a caller list back into `m_midiTrackPaths` via a tail jump to `List::AssignFrom`. Direct PE route search found no calls/jumps, VA/RVA pointer hits, export, or vtable route to either raw start; exact bytes, constructor/destructor field use, adjacent MIDI path helpers, and registry persistence support reconstructing first-draft private Config C++.
```

Replace the stale `00032I` row with:

```text
        - [UID:00032I][0x0048eaa0-0x0048ebb3.ConfigStringPreferenceHelpers](by-memory/0x0048eaa0-0x0048ebb3.ConfigStringPreferenceHelpers.md) 0x0048eaa0-0x0048ebb3 | private helper cluster | ConfigStringPreferenceHelpers : reconstructable : 88% : very strong : B012 source-quality recheck resolves the first two helpers as MIDI track-path accessors over `m_midiTrackPaths` (`Config +0x2912b4`, heap `List*`, `List(0x42,0x10)`): `0x0048eaa0` scans selector-tagged 66-byte entries, copies the fixed 32-wide-character path to the caller buffer or clears the destination, and `0x0048eb00` updates a selector-matched path with `_wcscpy_s(...,0x20,source)`. The third helper `0x0048eb50` replaces `m_logDataText` (`Config +0x2916cc`) with an owned heap wide string; caller counts remain 1/1/5 from MIDI track selection and login/create-user/server-message UI consumers through `g_pConfig`.
```

Replace the stale `0002P9` row with:

```text
        - [UID:0002P9][0x00494020-0x00494126.ConfigDeletingDestructor](by-memory/0x00494020-0x00494126.ConfigDeletingDestructor.md) 0x00494020-0x00494126 | scalar deleting destructor wrapper | Config scalar deleting destructor : reconstructable : 87% : very strong : B012 source-quality recheck keeps direct class owner [UID:000031][Config](by-class/Config.md) but reframes the function as the MSVC scalar deleting destructor entry carrying the ordinary `Config::~Config` body: vtable restore, delete/null `m_midiTrackPaths` at `+0x2912b4`, free `m_logDataText` at `+0x2916cc`, destroy string/list members at `+0x29190c/+0x2918fc/+0x2918f0`, destroy 20 string handles at `+0x2911e0`, release `ConfigEntryBlock` at `+0x28db10`, destroy 32 `ConfigEntry` records, clear `g_pConfig`, destroy `LObject`, and conditionally delete only for `(flags & 1) && !(flags & 4)`. Source C++ should declare/implement `virtual ~Config()` semantics, not a hand-written `DeletingDestructor` API.
```

Replace the stale `0002PA` row with:

```text
        - [UID:0002PA][0x00494130-0x004941d6.ConfigEntryBlockReleaseOwnedBuffers](by-memory/0x00494130-0x004941d6.ConfigEntryBlockReleaseOwnedBuffers.md) 0x00494130-0x004941d6 | method | ConfigEntryBlock::ReleaseOwnedBuffers : reconstructable : 86% : very strong : B012 source-quality recheck confirms the helper as `ConfigEntryBlock::ReleaseOwnedBuffers`: for each active 0x18-byte `ConfigEntry`, it frees owned pointers at entry `+4/+8/+0xc`, clears them, then resets block `count` at `+0x300` and dirty/state byte at `+0x304`. When embedded in Config/RegistryConfig the block base is `this +0x28db10`, so count/dirty land at `+0x28de10/+0x28de14`; callers from Config/RegistryConfig destructor and RegistryConfig load cleanup remain support evidence, not ownership transfer away from Config/ConfigEntryBlock.
```

No coverage row for `g_pConfig` strictly needs replacement, but if the supervisor updates that row, add `m_midiTrackPaths`, `m_logDataText`, and the corrected ConfigEntryBlock offsets to the existing description.

## Validator Needs

No validators were run because this was report-only.

If the implementation callback is accepted, run from `source-3/project-documentation` for files actually edited:

> Executable block R001 was removed from this report and preserved verbatim in [000031-Config-class-source-quality-removed.md](000031-Config-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected outcome after only target/class edit: validator `ok: 1`, generated `auto-generated/NexusTK/config/Config.cpp` now contains the Config declaration block or at least no longer has an empty `000031` marker. If child C++ updates are also accepted, generated output should include the accepted helper bodies for `00032H`/`00032I` and still avoid a fake hand-written `DeletingDestructor` API.

## Implementation Readiness

Ready for supervisor implementation callback.

Minimum safe implementation scope:

1. Update `by-class/Config.md` metadata, C++ declaration, method/destructor policy, layout notes, and change log.
2. Update `by-file/Config.md` with `m_midiTrackPaths`, `m_logDataText`, corrected destructor policy, and Config/RegistryConfig split refinements.
3. Update stale support pages, especially `ConfigDeletingDestructor`, `ConfigConstructor`, `ConfigStringPreferenceHelpers`, `ConfigEntryVectorCopyWrappersRaw`, and `ConfigEntryBlockReleaseOwnedBuffers`.
4. Leave `by-memory/-coverage-report.md` for supervisor-owned coverage application using the exact rows above.
5. Run validators for touched files and review `auto-generated/NexusTK/config/Config.cpp`.

The target is not hard-blocked. Remaining uncertainty is field-completion and exact original spelling, not class source-readiness.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B012","command_id":"000000004165","destination_path":"executed-b-agent-research/B012/000031-Config-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:35","uid":"000031"} -->
<!-- {"agent":"B012","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000031-Config-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B012/000031-Config-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000031"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
