*** UID:0000KK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/localization/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# LanguageMan

## Proposed Original Placement

- Proposed source path: `localization/LanguageMan.cpp`
- Proposed header path: `localization/LanguageMan.h`
- Confidence: strong for module responsibility, medium for final folder name.

## Current Wave3 Containers

- `class_LanguageMan.cpp`
- `class_LanguageManager.cpp`
- global-data `g_pLanguageMan`

## Responsibilities

`LanguageMan` is the process-wide localized string table. It opens the DAT-backed `str.res` resource, reads up to 1024 text records, converts each line to wide characters, stores an owned `wchar_t*` table, and serves localized strings to dialog, prompt, scanner, and startup code by numeric id.

Treat `LanguageManager` as a generated alias/view over the same concrete object for now. Its only recovered method, `GetLocalizedString` at `0x004f0350`, reads the exact layout initialized by `LanguageMan::LanguageMan`: pointer table at `+0x4` and string count at `+0x8`.

## Likely File Contents

- [UID:000071][LanguageMan](by-class/LanguageMan.md) lifecycle and string table ownership.
- [UID:000072][LanguageManager](by-class/LanguageManager.md) lookup alias or folded method name until canonical naming is settled.
- [UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md) at `0x0067a750`.
- `GetLocalizedString` returning `const wchar_t*`.
- `GetLocalizedString` overload/helper that copies into a `SimpleUString` output parameter.
- `str.res` parser details documented in [UID:0001RP][str-res-localized-strings](by-resource/str-res-localized-strings.md).

## Evidence

- IDA MCP confirms `LanguageMan::LanguageMan` at `0x004f0010-0x004f028c`; current Wave3 metadata incorrectly records only `0x004f0010-0x004f004b`.
- Constructor xref comes from `Application::Initialize` at `0x00464108`.
- The constructor calls `DATFile` construction/open/read helpers, opens `L"str.res"`, reads one byte at a time until CR/LF or 1024 bytes, converts byte `0x11` to carriage return, and calls `MultiByteToWideChar`.
- `0x004f0350-0x004f0372` returns a table entry when the id is in range or `L"Invalid String ID"` otherwise.
- `0x004f0380-0x004f03bb` copies the same lookup result into a string object through `0x00582560`; confirmed callers include `NumberInputDialog` behavior and [UID:0000P5][VirusChecker](by-file/VirusChecker.md).
- `0x004f03d0-0x004f0477` is the scalar deleting destructor and vtable slot. It frees each string, frees the pointer table, clears `g_pLanguageMan`, tears down `LObject`, and optionally deletes the object.
- 2026-05-24 recheck: current `simroot_v2/class_LanguageMan.cpp` emits the full constructor body and deleting destructor, but active output still omits `0x004f0290`, `0x004f0380`, and `0x004f03c0`; `class_LanguageManager.cpp` still emits `0x004f0350` as a separate class view.
- 2026-05-26 recheck: current `simroot_v2` still has the same split. IDA MCP reconfirms `0x004f0290` as LanguageMan cleanup despite a polluted Boost destructor name, `0x004f0310` as an unreferenced zero-initializer, `0x004f0380` with callers at `0x00530b40` and `0x005c07b0`, and `0x004f03c0` referenced from constructor cleanup metadata.
- 2026-05-26 IDA `py_eval` recheck found 351 xrefs to the localized-string lookup at `0x004f0350` and 192 xrefs to `g_pLanguageMan` at `0x0067a750`. IDA exposes `LanguageMan` / `Singleton<LanguageMan>` RTTI and no `LanguageManager` RTTI, so `class_LanguageManager.cpp` should be treated as a generated alias container.

## Migration Notes

- Fold `class_LanguageManager.cpp` into this file or keep it as a documented alias until final class naming is decided.
- Attach or explicitly model omitted functions `0x004f0290`, `0x004f0380`, and `0x004f03c0` before source migration.
- Do not attach adjacent `0x004f0310` to this file without more evidence. It is a real zero-initializer function in the physical neighborhood, but current xrefs do not prove localization ownership.
- Do not classify `0x004f0290` as Boost/CRT based on the current IDA symbol. The body uses the LanguageMan string-table layout and clears `g_pLanguageMan`.
- Current exported `class_LanguageMan.meta_wave3` still carries an old method-name control-character grade reason for `0x004f0010`; treat that as stale exported metadata unless fresh live grade output reintroduces it.
- Candidate final simpath: `localization/LanguageMan.cpp`.

## Cross-References

- Classes: [UID:000071][LanguageMan](by-class/LanguageMan.md), [UID:000072][LanguageManager](by-class/LanguageManager.md)
- Global: [UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md)
- Memory: [UID:00018R][0x004f0010-0x004f0477.LanguageManLocalization](by-memory/0x004f0010-0x004f0477.LanguageManLocalization.md)
- Exact helpers: [UID:00018S][0x004f0290-0x004f0310.LanguageManCleanupDestructor](by-memory/0x004f0290-0x004f0310.LanguageManCleanupDestructor.md), [UID:00018T][0x004f0310-0x004f0342.LocalizationAdjacentZeroInitializer](by-memory/0x004f0310-0x004f0342.LocalizationAdjacentZeroInitializer.md), [UID:00018U][0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers](by-memory/0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers.md), [UID:00018V][0x004f03d0-0x004f0477.LanguageManScalarDeletingDestructor](by-memory/0x004f03d0-0x004f0477.LanguageManScalarDeletingDestructor.md), [UID:0001OS][0x0067a750-0x0067a754.g_pLanguageMan](by-memory/0x0067a750-0x0067a754.g_pLanguageMan.md)
- Resource: [UID:0001RP][str-res-localized-strings](by-resource/str-res-localized-strings.md)
- Neighboring files: [UID:0000HG][Application](by-file/Application.md), [UID:0000IN][DATFile](by-file/DATFile.md), [UID:0000P5][VirusChecker](by-file/VirusChecker.md)
- Meta: [UID:0001QF][client_localization](by-meta/client_localization.md), [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)

## Changes

- 2026-06-01 projected reconstruction path update:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank even though the page and proposed source tree already identified `localization/LanguageMan.cpp`.
  - Changed to: `NexusTK/localization/`.
  - Summary/evidence: [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) and this page already place the module under localization; IDA evidence ties the range to the `LanguageMan` singleton and `str.res` loader.

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:88` and `CONFIDENCE:84`.
  - Summary/evidence: localized string table responsibility, `LanguageManager` alias, constructor/parser behavior, lookup helpers, cleanup/destructor, global xrefs, resource ownership, and migration caveats are documented; confidence is capped by the remaining alias/final naming question and adjacent zero-initializer ownership.
