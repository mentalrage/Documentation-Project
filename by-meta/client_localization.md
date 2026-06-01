*** UID:0001QF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Client Localization

## Status

- Scope: localized text loading, numeric string-id lookup, and resource-level localization behavior.
- Confidence: strong for `str.res` loader and singleton layout; medium for final class naming.

## Current Findings

- [UID:0000KK][LanguageMan](by-file/LanguageMan.md) loads `str.res` during `Application::Initialize` and owns [UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md).
- [UID:000072][LanguageManager](by-class/LanguageManager.md) is currently a generated alias/view over the same layout, not a proven second object.
- [UID:0001RP][str-res-localized-strings](by-resource/str-res-localized-strings.md) is a line-oriented DAT-backed resource converted to wide strings with `MultiByteToWideChar(0, 0, ...)`.
- Lookup helper `0x004f0350` returns a `const wchar_t*`; helper `0x004f0380` copies the selected string into a caller-provided string object.
- Current `simroot_v2` still splits `LanguageManager::GetLocalizedString` into a separate generated class and omits several support helpers from active `LanguageMan` output. Use the [UID:00018R][0x004f0010-0x004f0477.LanguageManLocalization](by-memory/0x004f0010-0x004f0477.LanguageManLocalization.md) doc as the ownership anchor.
- 2026-05-26 recheck: the omitted support helpers are now exact documented ranges: [UID:00018S][0x004f0290-0x004f0310.LanguageManCleanupDestructor](by-memory/0x004f0290-0x004f0310.LanguageManCleanupDestructor.md), [UID:00018U][0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers](by-memory/0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers.md), and [UID:00018V][0x004f03d0-0x004f0477.LanguageManScalarDeletingDestructor](by-memory/0x004f03d0-0x004f0477.LanguageManScalarDeletingDestructor.md). The adjacent [UID:00018T][0x004f0310-0x004f0342.LocalizationAdjacentZeroInitializer](by-memory/0x004f0310-0x004f0342.LocalizationAdjacentZeroInitializer.md) remains unresolved.

## Source-Structure Implications

The current source-tree hypothesis adds:

```text
localization/
  LanguageMan.cpp
```

This module should stay separate from `archive/DATFile.cpp`: it consumes the DAT reader, but owns string-id policy and localized UI text.

## Open Questions

- Decide final class naming: keep `LanguageMan`, rename to `LanguageManager`, or preserve both with one as an alias.
- Build a string-id table for frequently referenced ids once enough dialog and packet docs are stable.
- Review whether the adjacent no-xref zero-initializer at `0x004f0310` has any localization ownership.

## Cross-References

- [UID:0000KK][LanguageMan](by-file/LanguageMan.md)
- [UID:000071][LanguageMan](by-class/LanguageMan.md)
- [UID:000072][LanguageManager](by-class/LanguageManager.md)
- [UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md)
- [UID:00018R][0x004f0010-0x004f0477.LanguageManLocalization](by-memory/0x004f0010-0x004f0477.LanguageManLocalization.md)
- [UID:0001OS][0x0067a750-0x0067a754.g_pLanguageMan](by-memory/0x0067a750-0x0067a754.g_pLanguageMan.md)
- [UID:0001RP][str-res-localized-strings](by-resource/str-res-localized-strings.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)
