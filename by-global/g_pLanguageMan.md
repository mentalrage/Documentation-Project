*** UID:0000RC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000KK | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pLanguageMan

## Status

- Address: `0x0067a750`
- Exact memory range: [UID:0001OS][0x0067a750-0x0067a754.g_pLanguageMan](by-memory/0x0067a750-0x0067a754.g_pLanguageMan.md)
- Kind: singleton pointer / global data.
- Confidence: strong.
- Proposed owner: [UID:0000KK][LanguageMan](by-file/LanguageMan.md)

## Role

`g_pLanguageMan` points to the process-wide localized string table loaded from `str.res`. Dialog, prompt, scanner, startup, and gameplay UI code pass this pointer into localized string lookup helpers with numeric string ids.

## Lifetime

- Set by `LanguageMan::LanguageMan` at `0x004f0010`.
- Cleared by the destructor paths at `0x004f0290` and `0x004f03d0`.
- Cleared by helper `0x004f03c0`, referenced from constructor cleanup metadata.
- Read by broad callers before invoking `0x004f0350` or `0x004f0380`.

## Evidence

- IDA MCP xrefs to `0x0067a750` show writes in `0x004f0010`, `0x004f0290`, `0x004f03c0`, and `0x004f03d0`.
- IDA MCP xrefs show many data references immediately paired with calls to `0x004f0350` or `0x004f0380`.
- 2026-05-24 IDA recheck found 192 xrefs to `0x0067a750`, reinforcing that `LanguageManager` should be treated as an alias/view over this singleton unless separate allocation evidence is found.
- 2026-05-26 IDA recheck again returned a large xref set, truncated by MCP after representative callers, with constructor/destructor/clear writes still present.
- 2026-05-27 IDA MCP item-action rechecks show prompt constructors reading `dword_67A750` before localized string lookup: `ThrowInputPane` uses string id `0x23`, `UseInputPane` uses `0x09`, `EatInputPane` uses `0x0c`, `WieldInputPane` uses `0x0d`, and `WearInputPane` uses `0x21`. Aliases such as `g_pStringTable` should normalize back to this singleton unless the address differs.
- 2026-06-05 live IDA MCP again reports 192 xrefs to `0x0067a750`; decompilation confirms constructor `0x004f0010`, clear helper `0x004f03c0`, and deleting destructor `0x004f03d0` write/clear `dword_67A750`.

## Cross-References

- [UID:0000KK][LanguageMan](by-file/LanguageMan.md)
- [UID:000071][LanguageMan](by-class/LanguageMan.md)
- [UID:000072][LanguageManager](by-class/LanguageManager.md)
- [UID:00018R][0x004f0010-0x004f0477.LanguageManLocalization](by-memory/0x004f0010-0x004f0477.LanguageManLocalization.md)
- [UID:0001OS][0x0067a750-0x0067a754.g_pLanguageMan](by-memory/0x0067a750-0x0067a754.g_pLanguageMan.md)
- [UID:0001RP][str-res-localized-strings](by-resource/str-res-localized-strings.md)
- [UID:0000EY][ThrowInputPane](by-class/ThrowInputPane.md)
- [UID:0000FG][UseInputPane](by-class/UseInputPane.md)
- [UID:000047][EatInputPane](by-class/EatInputPane.md)
- [UID:0000G4][WieldInputPane](by-class/WieldInputPane.md)
- [UID:0000G0][WearInputPane](by-class/WearInputPane.md)

## Changes

### 2026-05-30 completion/confidence evidence pass

- What existed before: the page had `0` completion/confidence values and broad owner notes.
- What changed: completion/confidence were raised to `84/88`, and the evidence now distinguishes exact IDA-backed singleton storage from alias/source naming.
- Summary and evidence: existing IDA-backed docs establish `0x0067a750-0x0067a754`, lifecycle writes/clears, and broad lookup callers. Completion remains capped because the final original spelling and split between `LanguageMan` and `LanguageManager` naming are still unresolved.
- 2026-06-05: Marked reconstructable under [UID:0000KK][LanguageMan](by-file/LanguageMan.md). Evidence: live IDA MCP reports 192 xrefs to `0x0067a750`; decompilation confirms `0x004f0010`, `0x004f03c0`, and `0x004f03d0` write/clear `dword_67A750`.
