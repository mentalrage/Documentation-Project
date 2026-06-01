*** UID:0000RC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
- Current simroot references `g_pLanguageMan` in `class_LanguageMan.cpp`, while `class_LanguageManager.cpp` methods are called with the same singleton pointer.
- 2026-05-24 IDA recheck found 192 xrefs to `0x0067a750`, reinforcing that `LanguageManager` should be treated as an alias/view over this singleton unless separate allocation evidence is found.
- 2026-05-26 IDA recheck again returned a large xref set, truncated by MCP after representative callers, with constructor/destructor/clear writes still present.
- 2026-05-27 IDA MCP item-action rechecks show prompt constructors reading `dword_67A750` before localized string lookup: `ThrowInputPane` uses string id `0x23`, `UseInputPane` uses `0x09`, `EatInputPane` uses `0x0c`, `WieldInputPane` uses `0x0d`, and `WearInputPane` uses `0x21`. Generated aliases such as `g_pStringTable` should normalize back to this singleton unless the address differs.
- Current `simroot_v2/class_LanguageMan.cpp` sets `g_pLanguageMan = this` in `LanguageMan::LanguageMan`, clears it in the generated deleting destructor, and loads `str.res`. `class_LanguageManager.cpp` emits `GetLocalizedString` over the same `+0x4` string-table and `+0x8` count layout.
- Source-map caveat: `class_LanguageMan.cpp.source_map.json` has zero missing memory-range lines and maps the constructor/deleting-destructor uses of `g_pLanguageMan` to code ranges, but `class_LanguageMan.meta_wave3` currently has an empty active `global_data` partition and does not emit a standalone `g_pLanguageMan` declaration. Treat the exact `0x0067a750-0x0067a754` storage as IDA-backed documentation evidence, not as an active Wave3 global-data declaration.
- Current IDA MCP is unavailable in this session, so the added current-source notes are based on local simroot/source-map inspection and the existing IDA-backed documentation listed above.

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

- What existed before: the page had `0` completion/confidence values and said current simroot declares `g_pLanguageMan` in `class_LanguageMan.cpp`.
- What changed: completion/confidence were raised to `84/88`, and the evidence now distinguishes current generated uses from the exact IDA-backed singleton storage. The simroot declaration claim was narrowed because current `class_LanguageMan.meta_wave3` has no active `global_data` entry for this singleton.
- Summary and evidence: existing IDA-backed docs establish `0x0067a750-0x0067a754`, lifecycle writes/clears, and broad lookup callers. Current simroot/source-map evidence confirms constructor/destructor references and the `LanguageManager` lookup split, but the active generated global-data partition is still incomplete; that caveat prevents a higher completion score.
