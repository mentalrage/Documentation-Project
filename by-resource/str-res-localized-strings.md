*** UID:0001RP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# str.res Localized Strings

## Status

- Resource kind: DAT-backed text resource.
- Confidence: strong for loader behavior, open for exact source text encoding policy beyond Win32 code page `0`.
- Owner module: [UID:0000KK][LanguageMan](by-file/LanguageMan.md)

## Observed Format

`LanguageMan::LanguageMan` opens `L"str.res"` through [UID:0000IN][DATFile](by-file/DATFile.md) and treats it as a line-oriented byte stream.

Observed parser behavior:

- maximum records: 1024 strings;
- maximum input line length: 1024 bytes before conversion;
- line terminators: LF ends a line; CR ends a line and causes a one-byte seek to skip the following byte;
- byte `0x11` inside a line is rewritten to CR before wide conversion;
- conversion: `MultiByteToWideChar(0, 0, bytes, length, ...)`, so it uses the process ANSI code page;
- each converted line becomes a separately allocated null-terminated `wchar_t*`.

Out-of-range lookups return or copy `L"Invalid String ID"`.

Exact lookup helpers are documented at [UID:00018U][0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers](by-memory/0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers.md).

## IDA MCP Evidence

- ASCII `str.res` was verified at `0x0061c9ec`, with an xref at `0x004f0099` inside `0x004f0010-0x004f028c`.
- IDA decompilation of `0x004f0010-0x004f028c` opens `L"str.res"`, allocates a 1024-entry temporary pointer array, reads one byte at a time, treats LF and CR as line terminators, seeks one byte after CR, rewrites byte `0x11` to CR, and calls `MultiByteToWideChar(0, 0, ...)` into a 1024-wide-character buffer.
- The same decompile shows converted strings are copied into separately allocated null-terminated `wchar_t*` entries and throws `"Too many strings"` after the 1024-record limit.

## Consumers

`g_pLanguageMan` is read across many UI and gameplay modules before calls to the localized string helpers:

- dialog constructors and alert text;
- item/menu/input prompts;
- bulletin/mail/article flows;
- `NumberInputDialog` out-of-range text through `0x004f0380`;
- [UID:0000P5][VirusChecker](by-file/VirusChecker.md) scanner DLL and detection messages.

## Open Questions

- Determine whether `str.res` is language-specific per distribution or a single bundled resource.
- Map high-value string ids to UI meanings as dialog and packet handlers are documented.
- Confirm whether `0x11` represents an authoring-time line-break escape in the resource file.

## Cross-References

- [UID:0000KK][LanguageMan](by-file/LanguageMan.md)
- [UID:00018R][0x004f0010-0x004f0477.LanguageManLocalization](by-memory/0x004f0010-0x004f0477.LanguageManLocalization.md)
- [UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md)
- [UID:0001OS][0x0067a750-0x0067a754.g_pLanguageMan](by-memory/0x0067a750-0x0067a754.g_pLanguageMan.md)
- [UID:0001QF][client_localization](by-meta/client_localization.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)

## Changes

- What existed before: the page had detailed parser notes but remained scored unevaluated.
- Changed to: scored `COMPLETION:82` / `CONFIDENCE:90` and added direct IDA MCP string/xref/decompilation evidence.
- Summary and evidence: the loader behavior is strongly verified from `0x004f0010`; score remains below final because concrete string-id mappings and distribution/encoding policy are still incomplete.
