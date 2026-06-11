*** UID:000072 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# LanguageManager

## Status

- Disposition: ignored as a standalone class record; keep as an alias note for [UID:000071][LanguageMan](by-class/LanguageMan.md).
- Confidence: strong that `0x004f0350` is a localized string lookup; not proved as a separate original class.
- Likely source file: [UID:0000KK][LanguageMan](by-file/LanguageMan.md)
- Main address range: [UID:00018R][0x004f0010-0x004f0477.LanguageManLocalization](by-memory/0x004f0010-0x004f0477.LanguageManLocalization.md)
- Current recovered file: `source-3/simroot_v2/class_LanguageManager.cpp`

## Class Purpose

`LanguageManager` is currently best treated as an alias or recovered view over [UID:000071][LanguageMan](by-class/LanguageMan.md), not a proven second object. Its only emitted method reads `this + 0x4` as a string table pointer and `this + 0x8` as the string count, matching the layout built by `LanguageMan::LanguageMan`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `GetLocalizedString` | `0x004f0350-0x004f0372` | Bounds-checks a numeric string id and returns either the localized `wchar_t*` or `L"Invalid String ID"`; see [UID:00018U][0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers](by-memory/0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers.md). |

## Ownership Notes

- Fold this class into `LanguageMan` during source migration unless later evidence proves separate headers or inheritance.
- Many generated files call `LanguageManager::GetLocalizedString(g_pLanguageMan, id)`. That is caller evidence for the global string table, not proof of a separate manager allocation.
- 2026-05-26 IDA recheck: `0x004f0350` still has broad code refs and still reads only `this + 0x4` and `this + 0x8`, matching the [UID:000071][LanguageMan](by-class/LanguageMan.md) table layout. Current `simroot_v2` still emits it in `class_LanguageManager.cpp`.
- 2026-05-26 IDA `py_eval` recheck found 351 xrefs to `0x004f0350` and 192 xrefs to `g_pLanguageMan` at `0x0067a750`. IDA name inventory exposes `LanguageMan` and `Singleton<LanguageMan>` RTTI, but no `LanguageManager` RTTI/name evidence.

## Cross-References

- [UID:000071][LanguageMan](by-class/LanguageMan.md)
- [UID:0000KK][LanguageMan](by-file/LanguageMan.md)
- [UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md)
- [UID:00018U][0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers](by-memory/0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers.md)
- [UID:0001RP][str-res-localized-strings](by-resource/str-res-localized-strings.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `-1/-1`. Summary: this page is an ignored generated alias/view over `LanguageMan`, not a separately scored reconstructable class. Evidence: the page's disposition already marks it ignored, and documented IDA evidence points to `LanguageMan`/`Singleton<LanguageMan>` RTTI and the shared `g_pLanguageMan` table layout rather than a separate `LanguageManager` class.
- 2026-06-05: Marked not reconstructable for autogen.
  - Before: `RECONSTRUCTABLE` was blank, leaving this ignored alias page unclassified in generated class coverage.
  - After: set `RECONSTRUCTABLE:FALSE`; kept parent/C++ blank because [UID:000071][LanguageMan](by-class/LanguageMan.md) is the reconstructable owner.
  - Summary/evidence: live IDA MCP reconfirms `0x004f0350` as the shared localized-string lookup with broad caller fanout and finds `LanguageMan`/`Singleton<LanguageMan>` RTTI/name records but no `LanguageManager` name records; [UID:000003][-ignored](by-class/-ignored.md) already records this generated-alias disposition.
