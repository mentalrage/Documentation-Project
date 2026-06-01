*** UID:000071 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# LanguageMan

## Status

- Confidence: strong for layout and lifecycle.
- Likely source file: [UID:0000KK][LanguageMan](by-file/LanguageMan.md)
- Main address range: [UID:00018R][0x004f0010-0x004f0477.LanguageManLocalization](by-memory/0x004f0010-0x004f0477.LanguageManLocalization.md)
- Current recovered file: `source-3/simroot_v2/class_LanguageMan.cpp`

## Class Purpose

`LanguageMan` owns the client localized string table loaded from `str.res`. It is constructed during application initialization, stores a process-wide singleton pointer, and supplies wide strings by integer id to UI, dialog, scanner, startup, and gameplay prompt code.

## Layout Notes

| Offset | Meaning | Evidence |
| --- | --- | --- |
| `+0x0` | `LObject` base / vtable | Constructor calls `0x004f4a80` and installs vtable `0x0061c9e0`. |
| `+0x4` | `wchar_t**` string table | Constructor writes allocated table; lookup methods index it. |
| `+0x8` | string count | Constructor increments per parsed line; lookup methods bounds-check against it. |

## Method Notes

| Method/helper | Address | Role |
| --- | --- | --- |
| constructor | `0x004f0010-0x004f028c` | Loads `str.res`, converts lines to wide strings, stores table, and sets `g_pLanguageMan`. |
| non-deleting destructor body | `0x004f0290-0x004f0310` | Frees every string and the table, clears singleton, destroys `LObject`; IDA currently mislabels it as `boost::exception`. See [UID:00018S][0x004f0290-0x004f0310.LanguageManCleanupDestructor](by-memory/0x004f0290-0x004f0310.LanguageManCleanupDestructor.md). |
| adjacent zero-initializer | `0x004f0310-0x004f0342` | Zeroes fields `+0x0c..+0x24`; no xrefs found, so ownership is unresolved. |
| `GetLocalizedString` | `0x004f0350-0x004f0372` | Returns `strings[id]` or `L"Invalid String ID"`. |
| string-copy lookup helper | `0x004f0380-0x004f03bb` | Copies the selected localized string into a caller-provided string object. |
| singleton clear helper | `0x004f03c0-0x004f03cb` | Clears `g_pLanguageMan`; referenced from constructor cleanup metadata. |
| scalar deleting destructor | `0x004f03d0-0x004f0477` | Vtable destructor slot; frees strings/table, clears singleton, destroys base, optionally deletes storage. |

## Naming Notes

- [UID:000072][LanguageManager](by-class/LanguageManager.md) is currently a separate generated class for `0x004f0350`, but it uses this exact layout and the same `g_pLanguageMan` singleton.
- Final source should probably use one class name. `LanguageMan` has stronger evidence from the singleton/global name and imported source file, while `LanguageManager` is useful as an alias for missing-ref callers.
- 2026-05-26 recheck: active `class_LanguageMan.cpp` still contains only the constructor and deleting destructor; active `class_LanguageManager.cpp` still contains the lookup method as a separate generated class. Keep the final class naming unresolved, but do not treat the split as proof of two allocated objects.
- 2026-05-26 IDA `py_eval` recheck found `LanguageMan` and `Singleton<LanguageMan>` RTTI/name records, 351 xrefs to the lookup helper at `0x004f0350`, and 192 xrefs to `g_pLanguageMan`; no `LanguageManager` RTTI/name evidence was found.

## Data Caveats

- Current active output still omits the non-deleting cleanup body at `0x004f0290`, string-copy lookup helper at `0x004f0380`, and singleton clear helper at `0x004f03c0`.
- IDA still reports no direct callers for `0x004f0310`; keep it unresolved rather than folding it into localization by physical adjacency alone.
- Current exported `simroot_v2/class_LanguageMan.meta_wave3` still reports a stored method-name control-character reason for `0x004f0010`, even though the active emitted method name is normal.

## Cross-References

- [UID:0000KK][LanguageMan](by-file/LanguageMan.md)
- [UID:000072][LanguageManager](by-class/LanguageManager.md)
- [UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md)
- [UID:00018R][0x004f0010-0x004f0477.LanguageManLocalization](by-memory/0x004f0010-0x004f0477.LanguageManLocalization.md)
- [UID:00018S][0x004f0290-0x004f0310.LanguageManCleanupDestructor](by-memory/0x004f0290-0x004f0310.LanguageManCleanupDestructor.md)
- [UID:00018U][0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers](by-memory/0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers.md)
- [UID:0001OS][0x0067a750-0x0067a754.g_pLanguageMan](by-memory/0x0067a750-0x0067a754.g_pLanguageMan.md)
- [UID:0001RP][str-res-localized-strings](by-resource/str-res-localized-strings.md)
- [UID:0000HG][Application](by-file/Application.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `86/88`. Summary: the localization singleton is well documented across purpose, layout, lifecycle, lookup helpers, naming evidence, and caveats, with only the adjacent zero-initializer and final generated split preventing a higher score. Evidence: documented `str.res` ownership, `g_pLanguageMan`, lookup/helper ranges, destructor body, RTTI/name evidence, and LanguageManager alias analysis.
