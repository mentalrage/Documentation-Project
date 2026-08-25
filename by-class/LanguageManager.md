*** UID:000072 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# LanguageManager

## Status

- Disposition: ignored as a standalone class record; keep as an alias note for [UID:000071][LanguageMan](by-class/LanguageMan.md).
- Confidence: very strong that this is only a historical/generated alias and not a separate original class.
- Likely source file: [UID:0000KK][LanguageMan](by-file/LanguageMan.md)
- Main address range: [UID:00018R][0x004f0010-0x004f0477.LanguageManLocalization](by-memory/0x004f0010-0x004f0477.LanguageManLocalization.md)
- Current recovered file: `source-3/simroot_v2/class_LanguageManager.cpp`

## Class Purpose

`LanguageManager` is retained only as historical search context for [UID:000071][LanguageMan](by-class/LanguageMan.md), not as a source alias, compatibility type, or second object. Exhaustive live searches found no `LanguageManager` RTTI, UDT, vtable, allocation, constructor, destructor, or distinct storage. Its former generated method is UID00040P under LanguageMan and reads the exact `m_strings +0x4` / `m_stringCount +0x8` layout.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `GetLocalizedString` | [UID:00040P][0x004f0350-0x004f0372.LanguageManGetLocalizedString](by-memory/0x004f0350-0x004f0372.LanguageManGetLocalizedString.md) | Bounds-checks a numeric string id and returns either the localized `wchar_t*` or `L"Invalid String ID"`. This is a `LanguageMan` child now; this page keeps only the generated-alias search route. |

## Ownership Notes

- Fold this class into `LanguageMan` during source migration unless later evidence proves separate headers or inheritance. The 2026-06-21 split makes [UID:00040P][0x004f0350-0x004f0372.LanguageManGetLocalizedString](by-memory/0x004f0350-0x004f0372.LanguageManGetLocalizedString.md) the source-bearing child under [UID:000071][LanguageMan](by-class/LanguageMan.md), not under this alias page.
- Many generated files call `LanguageManager::GetLocalizedString(g_pLanguageMan, id)`. That is caller evidence for the global string table, not proof of a separate manager allocation.
- 2026-05-26 IDA recheck: `0x004f0350` still has broad code refs and still reads only `this + 0x4` and `this + 0x8`, matching the [UID:000071][LanguageMan](by-class/LanguageMan.md) table layout. Current `simroot_v2` still emits it in `class_LanguageManager.cpp`.
- 2026-05-26 IDA `py_eval` recheck found 351 xrefs to `0x004f0350` and 192 xrefs to `g_pLanguageMan` at `0x0067a750`. IDA name inventory exposes `LanguageMan` and `Singleton<LanguageMan>` RTTI, but no `LanguageManager` RTTI/name evidence.
- 2026-06-22 B013 source-quality report review again found no source-quality evidence for a real separate `LanguageManager` class. Its references to old `class_LanguageManager.cpp` output and generated `LanguageManagerLayout` are historical recovery artifacts; current docs fold that output into [UID:00040P][0x004f0350-0x004f0372.LanguageManGetLocalizedString](by-memory/0x004f0350-0x004f0372.LanguageManGetLocalizedString.md) under [UID:000071][LanguageMan](by-class/LanguageMan.md).

## Cross-References

- [UID:000071][LanguageMan](by-class/LanguageMan.md)
- [UID:0000KK][LanguageMan](by-file/LanguageMan.md)
- [UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md)
- [UID:00018U][0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers](by-memory/0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers.md)
- [UID:00040P][0x004f0350-0x004f0372.LanguageManGetLocalizedString](by-memory/0x004f0350-0x004f0372.LanguageManGetLocalizedString.md)
- [UID:0001RP][str-res-localized-strings](by-resource/str-res-localized-strings.md)

## Changes

- 2026-08-24 B005 UID0000KK callback: set ignored-alias evidence scores to `90/96`; rejected a compatibility declaration or source emitter after exhaustive negative RTTI/type/vtable/allocation/lifecycle searches; preserved the page solely as a pointer to canonical UID000071/UID0000KK and UID00040P.

- Completion/confidence score update: existed before as `0/0`; changed to `-1/-1`. Summary: this page is an ignored generated alias/view over `LanguageMan`, not a separately scored reconstructable class. Evidence: the page's disposition already marks it ignored, and documented IDA evidence points to `LanguageMan`/`Singleton<LanguageMan>` RTTI and the shared `g_pLanguageMan` table layout rather than a separate `LanguageManager` class.
- 2026-06-05: Marked not reconstructable for autogen.
  - Before: `RECONSTRUCTABLE` was blank, leaving this ignored alias page unclassified in generated class coverage.
  - After: set `RECONSTRUCTABLE:FALSE`; kept parent/C++ blank because [UID:000071][LanguageMan](by-class/LanguageMan.md) is the reconstructable owner.
  - Summary/evidence: live IDA MCP reconfirms `0x004f0350` as the shared localized-string lookup with broad caller fanout and finds `LanguageMan`/`Singleton<LanguageMan>` RTTI/name records but no `LanguageManager` name records; [UID:000003][-ignored](by-class/-ignored.md) already records this generated-alias disposition.
- 2026-06-21 Rule 26 B007 split update: [UID:00018U][0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers](by-memory/0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers.md) is now a non-emitting split index and [UID:00040P][0x004f0350-0x004f0372.LanguageManGetLocalizedString](by-memory/0x004f0350-0x004f0372.LanguageManGetLocalizedString.md) carries the method under [UID:000071][LanguageMan](by-class/LanguageMan.md). This page remains ignored and should not produce a separate `LanguageManager.cpp` source body for the lookup.
- 2026-06-22 Rule 26 B013 verification: no score/status change. Preserved B013's alias rejection here so future generated-output cleanup does not revive `LanguageManager.cpp` as an original source owner.
