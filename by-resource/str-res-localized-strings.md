*** UID:0001RP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KK | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# str.res Localized Strings

## Status

- Resource kind: DAT-backed text resource.
- Confidence: very strong for loader behavior, lookup behavior, current DAT entry provenance, and basic payload shape; open for full id-to-meaning mapping and exact source text encoding policy beyond Win32 code page `0`.
- Canonical owner module: [UID:0000KK][LanguageMan](by-file/LanguageMan.md)

## Observed Format

[UID:00041V][0x004f0010-0x004f028c.LanguageManConstructor](by-memory/0x004f0010-0x004f028c.LanguageManConstructor.md) / `LanguageMan::LanguageMan` opens `L"str.res"` through [UID:0000IN][DATFile](by-file/DATFile.md) and treats it as a line-oriented byte stream.

Observed parser behavior:

- maximum records: 1024 strings;
- maximum input line length: 1024 bytes before conversion;
- line terminators: LF ends a line; CR ends a line and causes a one-byte seek to skip the following byte;
- byte `0x11` inside a line is rewritten to CR before wide conversion;
- conversion: `MultiByteToWideChar(0, 0, bytes, length, ...)`, so it uses the process ANSI code page;
- each converted line becomes a separately allocated null-terminated `wchar_t*`.

Out-of-range lookups return or copy `L"Invalid String ID"` from `0x0061ca20`.

Exact lookup helpers are documented at [UID:00040P][0x004f0350-0x004f0372.LanguageManGetLocalizedString](by-memory/0x004f0350-0x004f0372.LanguageManGetLocalizedString.md) and [UID:00040Q][0x004f0380-0x004f03bb.LanguageManCopyLocalizedString](by-memory/0x004f0380-0x004f03bb.LanguageManCopyLocalizedString.md), with [UID:00018U][0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers](by-memory/0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers.md) retained only as their non-emitting split index.

B013's read-only-data split records the source-side constants and literals that support this resource contract: [UID:00040V][0x0061c9d4-0x0061c9dc.LanguageManParserLimitConstants](by-memory/0x0061c9d4-0x0061c9dc.LanguageManParserLimitConstants.md) for the inferred 1024 line/count limits, and [UID:00040X][0x0061c9ec-0x0061ca44.LanguageManStringResourceLiterals](by-memory/0x0061c9ec-0x0061ca44.LanguageManStringResourceLiterals.md) for the C++ `str.res`, `Too many strings`, and `Invalid String ID` literals. B012's constructor split ties those constants/literals to exact parser child [UID:00041V][0x004f0010-0x004f028c.LanguageManConstructor](by-memory/0x004f0010-0x004f028c.LanguageManConstructor.md). This resource page still owns the external DAT payload/format, not those `.rdata` bytes.

## Package/Payload Evidence

2026-06-14 read-only package audit of `E:\2026\Resources\Read_Only\NexusTK\Data` parsed the documented DAT entry table format and found the localized string payload as `STR.RES` in `baram.dat`, entry index `9`, offset `11,268,984`, size `7,058` bytes.

The extracted current payload is a CR/LF-delimited byte stream with 248 lines under the loader's 1024-record cap. The first lines decode through the host Korean/ANSI-compatible code page as `Nexus`, `Kru Inc.`, `Can't initialize Nexus.`, `Do you really want to leave? (Y/N) `, `Private message to? [%s] > `, and inventory/drop prompts. The final observed lines include `Your ignore list is empty.`, `This change will take effect next time you run Nexus.`, `Withdraw how much?`, `Buy how many?`, and `Add how many?`.

This confirms that the bundled resource is a plain line table matching the IDA-observed parser contract. The audit does not by itself assign every numeric id to a caller-facing UI meaning, and it does not prove whether other distributions ship language-specific variants.

## IDA MCP Evidence

- ASCII `str.res` was verified at `0x0061c9ec`, with an xref at `0x004f0099` inside `0x004f0010-0x004f028c`.
- IDA decompilation of `0x004f0010-0x004f028c` opens `L"str.res"`, allocates a 1024-entry temporary pointer array, reads one byte at a time, treats LF and CR as line terminators, seeks one byte after CR, rewrites byte `0x11` to CR, and calls `MultiByteToWideChar(0, 0, ...)` into a 1024-wide-character buffer.
- The same decompile shows converted strings are copied into separately allocated null-terminated `wchar_t*` entries and throws `"Too many strings"` after the 1024-record limit.
- 2026-06-14 IDA MCP refresh confirmed `0x004f0010` (`sub_4F0010`, size `0x27c`), lookup helper `0x004f0350` (`sub_4F0350`, size `0x22`), copy-out helper `0x004f0380` (`sub_4F0380`, size `0x3b`), and scalar deleting destructor `0x004f03d0` (`sub_4F03D0`, size `0xa7`).
- Current xrefs remain one `str.res` constructor hit at `0x004f0099` and two `Invalid String ID` lookup hits at `0x004f0369` and `0x004f03a9`.
- Refreshed decompilation of `0x004f0350` returns `this[1][id]` only when `0 <= id < this[2]`; otherwise it returns `L"Invalid String ID"`. Refreshed decompilation of `0x004f0380` applies the same bounds check and copies either the selected localized string or the fallback literal through the string-copy helper.
- 2026-06-14 continuation xref check pinned the fallback literal at `0x0061ca20` with exactly two data xrefs: `0x004f0369` in the direct-return helper and `0x004f03a9` in the copy-out helper. A targeted parser decompile recheck reconfirmed `CR` handling with a one-byte seek, `LF` termination, byte `0x11` to `CR` remapping, `MultiByteToWideChar(0, 0, ...)`, and the 1024-record cap.

## Source/Resource Contract

| Area | Source-owned behavior | Resource-owned data |
| --- | --- | --- |
| Loader/parser | [UID:00041V][0x004f0010-0x004f028c.LanguageManConstructor](by-memory/0x004f0010-0x004f028c.LanguageManConstructor.md) owns opening `str.res`, byte-by-byte line parsing, CR/LF handling, `0x11` line-break remapping, `MultiByteToWideChar(0, 0, ...)`, allocation, lookup limits, [UID:00040V][0x0061c9d4-0x0061c9dc.LanguageManParserLimitConstants](by-memory/0x0061c9d4-0x0061c9dc.LanguageManParserLimitConstants.md), and source-side loader/diagnostic literals in [UID:00040X][0x0061c9ec-0x0061ca44.LanguageManStringResourceLiterals](by-memory/0x0061c9ec-0x0061ca44.LanguageManStringResourceLiterals.md). The child emits through [UID:000071][LanguageMan](by-class/LanguageMan.md) into [UID:0000KK][LanguageMan](by-file/LanguageMan.md). | `str.res` owns the line-oriented localized text payload. |
| Lookup helpers | Source owns the `m_strings` / `+0x04` string-table pointer, `m_stringCount` / `+0x08` count, in-range direct lookup [UID:00040P][0x004f0350-0x004f0372.LanguageManGetLocalizedString](by-memory/0x004f0350-0x004f0372.LanguageManGetLocalizedString.md), copy-output helper [UID:00040Q][0x004f0380-0x004f03bb.LanguageManCopyLocalizedString](by-memory/0x004f0380-0x004f03bb.LanguageManCopyLocalizedString.md), and `Invalid String ID` fallback literal in [UID:00040X][0x0061c9ec-0x0061ca44.LanguageManStringResourceLiterals](by-memory/0x0061c9ec-0x0061ca44.LanguageManStringResourceLiterals.md). | Numeric ids and text meanings are content authored in the resource and callers; this page does not hard-code the full table. |
| Packaging | Source should preserve the `str.res` DAT name and loader contract. | The current `baram.dat` payload is proven as a 248-line `STR.RES` entry; distribution-specific text, language variants, full id mapping, and final encoding policy remain resource/package concerns. |

## Consumers

`g_pLanguageMan` is read across many UI and gameplay modules before calls to the localized string helpers:

- dialog constructors and alert text;
- item/menu/input prompts;
- bulletin/mail/article flows;
- `NumberInputDialog` out-of-range text through `0x004f0380`;
- [UID:0000P5][VirusChecker](by-file/VirusChecker.md) scanner DLL and detection messages.

## Confirmed High-Value String IDs

| Zero-based id | Hex | Current decoded text | Proven consumer |
| ---: | ---: | --- | --- |
| 3 | `0x03` | `Do you really want to leave? (Y/N) ` | [UID:0003ZQ][0x005adcc0-0x005add18.QuitInputPaneConstructor](by-memory/0x005adcc0-0x005add18.QuitInputPaneConstructor.md) calls `g_pLanguageMan->GetLocalizedString(3)` and passes the returned `const wchar_t *` to `CharInputPane::CharInputPane(const wchar_t *)`. The live [UID:0001KP][0x005a94b0-0x005a95d2.QuitPromptLauncher](by-memory/0x005a94b0-0x005a95d2.QuitPromptLauncher.md) branch contains the same lookup as part of its inlined `QuitInputPane` construction. Source must preserve the id lookup, not hard-code the current English prompt. |
| 38 | `0x26` | `Save profile? (Y/N) ` | [UID:0003O5][0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw](by-memory/0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw.md) loads [UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md), calls `LanguageMan::GetLocalizedString(0x26)`, and passes the returned prompt to `CharInputPane::CharInputPane(const wchar_t *)`; [UID:0001KQ][0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory](by-memory/0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory.md) duplicates the same lookup during retained `CreateSelfSaveInputPane()` construction. |
| 39 | `0x27` | `Ignore list - (A)dd,(D)elete,(?)List ` | [UID:0001MV][0x005b68c0-0x005b6900.BlockListenInputPaneConstructor](by-memory/0x005b68c0-0x005b6900.BlockListenInputPaneConstructor.md) loads [UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md), calls `LanguageMan::GetLocalizedString(0x27)`, and passes the returned prompt to `CharInputPane::CharInputPane(const wchar_t *)`; source should use `kBlockListenPromptStringId` or an equivalent id constant, not a hard-coded English prompt string. |
| 40 | `0x28` | `Who do you wish to ignore? >` | [UID:0001MZ][0x005b6c80-0x005b6cc0.AddToBlockListenInputPaneConstructor](by-memory/0x005b6c80-0x005b6cc0.AddToBlockListenInputPaneConstructor.md) loads [UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md), calls `LanguageMan::GetLocalizedString(0x28)`, and passes the returned prompt to `LineInputPane::LineInputPane(const wchar_t *)`; source should keep `g_pLanguageMan->GetLocalizedString(0x28)` or a future equivalent id constant rather than hard-coding this English prompt text. |
| 41 | `0x29` | `Who do you wish to hear? >` | [UID:0001N1][0x005b7100-0x005b7140.DeleteFromBlockListenInputPaneConstructor](by-memory/0x005b7100-0x005b7140.DeleteFromBlockListenInputPaneConstructor.md) loads [UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md), calls `LanguageMan::GetLocalizedString(0x29)`, and passes the returned prompt to `LineInputPane::LineInputPane(const wchar_t *)`; source should keep `g_pLanguageMan->GetLocalizedString(0x29)` or a future equivalent id constant rather than hard-coding this English prompt text. |
| 64 | `0x40` | `Are you sure you want to delete this?` | [UID:0002US][0x0047e100-0x0047e158.ConfirmDeleteAlertRawConstructor](by-memory/0x0047e100-0x0047e158.ConfirmDeleteAlertRawConstructor.md) loads [UID:0001OS][0x0067a750-0x0067a754.g_pLanguageMan](by-memory/0x0067a750-0x0067a754.g_pLanguageMan.md), calls `LanguageMan::GetLocalizedString(0x40)`, and passes the returned message into `AlertPane::AlertPane` before adding `L"Delete"` / `L"Cancel"` buttons. |
| 158 | `0x9e` | `How many %ss will you add?` | [UID:0004BQ][0x004af040-0x004af371.AddItemWithCountDialogConstructor](by-memory/0x004af040-0x004af371.AddItemWithCountDialogConstructor.md) calls `g_pLanguageMan->GetLocalizedString(158)` and formats the result with the signed inventory-slot record's `displayName` into a 256-WCHAR prompt. The doubled `s` is current resource payload text plus the `%s` conversion; constructor source must preserve runtime lookup/formatting rather than hard-code this English string. |
| 212 | `0xd4` | `Ju Jak - The magical bird of fire, and totem of magic. This magical beast uses it's great magical powers to control and master it's surroundings, and then deliver great damage from afar.` | [UID:00043P][0x0052b3a0-0x0052b462.NewUserDialogPane2SelectTotem](by-memory/0x0052b3a0-0x0052b462.NewUserDialogPane2SelectTotem.md) passes `totem + 212` to `g_pLanguageMan->GetLocalizedString`, then sends the returned pointer to TextEdit child `19`. Constructor/command callers map totem `0` to this row. Source must preserve runtime lookup rather than hard-code this current English payload. |
| 213 | `0xd5` | `Baekho - The great white tiger, the totem of stealth, cunning, and speed. The great Baekho uses it's power and light magic to quickly subdue it's foe, he is unmatched one on one.` | UID00043P maps caller-provided totem `1` to id `213` through the same TextEdit child-`19` runtime lookup path. |
| 214 | `0xd6` | `Hyun Moo - The mystical black turtle, and totem of protection and healing. The strong Hyun Moo uses it's magical abilities to heal and protect, making itself nearly immortal.` | UID00043P maps caller-provided totem `2` to id `214` through the same TextEdit child-`19` runtime lookup path. |
| 215 | `0xd7` | `Chung Ryong - The powerful blue dragon, and totem of power, strength, and battles. This incredible beast is unmatched in its ability to deliver great damage to large groups of opponents.` | UID00043P maps caller-provided totem `3` to id `215` through the same TextEdit child-`19` runtime lookup path. |
| 227 | `0xe3` | `Please input nexon.com ID and password.` | [UID:00043T][0x0052b650-0x0052b724.NewUserDialogPane2OpenNexonclubRegistrationOrSendCharacterRequest](by-memory/0x0052b650-0x0052b724.NewUserDialogPane2OpenNexonclubRegistrationOrSendCharacterRequest.md) calls `g_pLanguageMan->GetLocalizedString(227)` on its true branch and passes the returned `const wchar_t *` into the 632-byte `NexonclubRegistrationDialog` constructor together with a bound `OnNexonclubRegistrationResult` callback. The symmetric retained create-user variant helpers at `0x0052d100` and `0x0052e970` use the same id. Source must preserve the runtime LanguageMan lookup rather than hard-code the current English prompt. |
| 236 | `0xec` | `Please wait for a while...` | [UID:00032T][0x0046f220-0x0046f30f.BrowserControlPaneOldDrawStatusOverlay](by-memory/0x0046f220-0x0046f30f.BrowserControlPaneOldDrawStatusOverlay.md) loads [UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md), calls `LanguageMan::GetLocalizedString(236)`, and draws the returned waiting/status overlay text through the old browser control pane. B006 re-extracted the documented `baram.dat` `STR.RES` payload span at offset `11,268,984`, size `7,058`, and tied zero-based id `236` / `0xec` to this current text. Source should keep `GetLocalizedString(236)` or a named browser status string id, not a hard-coded English literal. |

This table records current package text for known callers. It does not mean the English text is hard-coded in source; callers should keep `g_pLanguageMan->GetLocalizedString(<id>)` or a project-wide string-id enum/constant such as `0x03`, `0x26`, `0x27`, `0x28`, `0x29`, `0x40`, `0x9e`, `0xd4` through `0xd7`, `0xe3`, or `0xec` rather than embedding the current English strings. The four totem descriptions were reread from `baram.dat` entry `STR.RES`, index `9`, offset `11,268,984`, size `7,058`, and decoded under code page 949; they remain resource data, not C++ literals.

## Open Questions

- Determine whether `str.res` is language-specific per distribution or a single bundled resource.
- Map high-value string ids to UI meanings as dialog and packet handlers are documented.
- Confirm whether `0x11` represents an authoring-time line-break escape in the resource file.

## Cross-References

- [UID:0000KK][LanguageMan](by-file/LanguageMan.md)
- [UID:00018R][0x004f0010-0x004f0477.LanguageManLocalization](by-memory/0x004f0010-0x004f0477.LanguageManLocalization.md)
- [UID:00041V][0x004f0010-0x004f028c.LanguageManConstructor](by-memory/0x004f0010-0x004f028c.LanguageManConstructor.md)
- [UID:00040P][0x004f0350-0x004f0372.LanguageManGetLocalizedString](by-memory/0x004f0350-0x004f0372.LanguageManGetLocalizedString.md)
- [UID:00040Q][0x004f0380-0x004f03bb.LanguageManCopyLocalizedString](by-memory/0x004f0380-0x004f03bb.LanguageManCopyLocalizedString.md)
- [UID:00018U][0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers](by-memory/0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers.md)
- [UID:00040V][0x0061c9d4-0x0061c9dc.LanguageManParserLimitConstants](by-memory/0x0061c9d4-0x0061c9dc.LanguageManParserLimitConstants.md)
- [UID:00040X][0x0061c9ec-0x0061ca44.LanguageManStringResourceLiterals](by-memory/0x0061c9ec-0x0061ca44.LanguageManStringResourceLiterals.md)
- [UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md)
- [UID:0001OS][0x0067a750-0x0067a754.g_pLanguageMan](by-memory/0x0067a750-0x0067a754.g_pLanguageMan.md)
- [UID:0001QF][client_localization](by-meta/client_localization.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)
- [UID:0004BQ][0x004af040-0x004af371.AddItemWithCountDialogConstructor](by-memory/0x004af040-0x004af371.AddItemWithCountDialogConstructor.md)

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 90 | The page documents the `str.res` parser format, table limits, terminator handling, `0x11` remap, ANSI-code-page conversion, allocation model, lookup and copy-out fallback behavior with exact fallback literal address, source/resource split, consumers, canonical owner module, current IDA evidence, current `baram.dat` package/payload details, and confirmed high-value ids `0x03`, `0x26`, `0x27`, `0x28`, `0x29`, `0x40`, `0x9e`, `0xd4` through `0xd7`, `0xe3`, and `0xec`. IDs `212..215` close the NewUserDialogPane2 totem-description mapping and id `227` closes its Nexonclub-registration prompt contract while preserving runtime lookup. Completion remains capped because the full id-to-meaning map, language/package variants, and final encoding policy are not fully audited. |
| Confidence | 94 | Current IDA string/xref checks, decompilation, DAT payload parsing, and direct consumer/resource checks confirm the loader, lookup helpers, fallback literal, LanguageMan ownership, archive entry, payload size, line-table shape, and high-value caller ids including QuitInputPane `3`, AddItemWithCount `158`, NewUserDialogPane2 totem descriptions `212..215`, and Nexonclub registration `227`. Confidence is capped by unresolved language/distribution policy and incomplete caller-id mapping. |

## Changes

- 2026-08-24 B005 UID0000KK callback: raised the resource contract to `92/95`; retained DAT ownership and line-oriented byte payload, CR/LF termination, `0x11` to carriage-return remap, code-page-0 `MultiByteToWideChar`, 1024 line/count caps, per-string allocation/termination, and source-side constants/literals while leaving the external id/text payload outside C++ emission.

- 2026-08-13 B004 UID00043P callback incorporation: preserved `90/94` and owner UID0000KK; added exact zero-based ids `212..215` / `0xd4..0xd7`, their complete code-page-949-decoded `baram.dat` STR.RES text, the `NewUserDialogPane2::SelectTotem(short)` consumer and TextEdit child-`19` route, and the no-hard-coded-resource-text source rule.

- 2026-07-22 B002 UID00043T callback incorporation: raised completion from `89` to `90`; added zero-based id `227` / `0xe3`, current `STR.RES` text `Please input nexon.com ID and password.`, the exact NewUserDialogPane2 registration-gate caller and symmetric create-user variant use, and the no-hard-coded-English source rule. Package provenance remains `baram.dat` entry index `9`, offset `11,268,984`, size `7,058` bytes, with 248 extracted lines.

- 2026-07-14 B003 UID0003ZQ resource sync: scores/owner unchanged; added zero-based id `3` / `0x03`, current `STR.RES` text `Do you really want to leave? (Y/N) `, exact retained constructor and live inlined-launcher consumers, the `const wchar_t *` lookup/base-constructor contract, and the no-hard-coded-English source rule.

- 2026-07-13 UID0004BQ resource sync: scores/owner unchanged; added zero-based id `158` / `0x9e`, current `STR.RES` text `How many %ss will you add?`, exact AddItemWithCount constructor consumer, display-name formatting, and the no-hard-coded-English source rule. Provenance remains `baram.dat` entry 9 at offset `11,268,984`, size `7,058`, 248 lines.

- 2026-07-02 B006 Browser status overlay resource sync:
  - Scores unchanged.
  - Evidence: B006 re-extracted current `STR.RES` text from the documented `baram.dat` payload span and tied zero-based id `236` / `0xec` to [UID:00032T][0x0046f220-0x0046f30f.BrowserControlPaneOldDrawStatusOverlay](by-memory/0x0046f220-0x0046f30f.BrowserControlPaneOldDrawStatusOverlay.md). The current decoded text is `Please wait for a while...`. The emitted old-pane overlay source should call `g_pLanguageMan->GetLocalizedString(236)` or an equivalent named browser status string id; the English text remains resource-owned data.

- 2026-06-26 B006 AddToBlockListen constructor resource sync:
  - Scores unchanged.
  - Evidence: B006 extracted current `STR.RES` text from the documented `baram.dat` payload and tied zero-based id `40` / `0x28` to [UID:0001MZ][0x005b6c80-0x005b6cc0.AddToBlockListenInputPaneConstructor](by-memory/0x005b6c80-0x005b6cc0.AddToBlockListenInputPaneConstructor.md). The constructor source should call `g_pLanguageMan->GetLocalizedString(0x28)` and pass the returned text to `LineInputPane::LineInputPane(const wchar_t *)`; the English prompt remains resource-owned data.

- 2026-06-26 B006 DeleteFromBlockListen constructor resource sync:
  - Scores unchanged.
  - Evidence: B006 extracted current `STR.RES` text from the documented `baram.dat` payload and tied zero-based id `41` / `0x29` to [UID:0001N1][0x005b7100-0x005b7140.DeleteFromBlockListenInputPaneConstructor](by-memory/0x005b7100-0x005b7140.DeleteFromBlockListenInputPaneConstructor.md). The constructor source should call `g_pLanguageMan->GetLocalizedString(0x29)` and pass the returned text to `LineInputPane::LineInputPane(const wchar_t *)`; the English prompt remains resource-owned data and must not be hard-coded in constructor C++.

- 2026-06-26 B002 BlockListen constructor resource sync:
  - Scores unchanged.
  - Evidence: B002 confirmed zero-based id `39` / `0x27` in the current `STR.RES` payload as `Ignore list - (A)dd,(D)elete,(?)List ` and tied it to [UID:0001MV][0x005b68c0-0x005b6900.BlockListenInputPaneConstructor](by-memory/0x005b68c0-0x005b6900.BlockListenInputPaneConstructor.md). The constructor source should call `g_pLanguageMan->GetLocalizedString(kBlockListenPromptStringId)` or an equivalent id constant lookup; the English text remains resource-owned data.

- 2026-06-25 B012 constructor child implementation:
  - Scores unchanged.
  - Evidence: exact constructor child [UID:00041V][0x004f0010-0x004f028c.LanguageManConstructor](by-memory/0x004f0010-0x004f028c.LanguageManConstructor.md) now owns the source loader/parser site for `str.res`; [UID:00018R][0x004f0010-0x004f0477.LanguageManLocalization](by-memory/0x004f0010-0x004f0477.LanguageManLocalization.md) is retained only as the non-emitting island map.

- 2026-06-25 B002 ConfirmDeleteAlert resource sync:
  - Scores unchanged.
  - Evidence: B002 extracted current `STR.RES` text from `baram.dat` and tied zero-based id `64` / `0x40` to [UID:0002US][0x0047e100-0x0047e158.ConfirmDeleteAlertRawConstructor](by-memory/0x0047e100-0x0047e158.ConfirmDeleteAlertRawConstructor.md). The constructor source should call `g_pLanguageMan->GetLocalizedString(0x40)`; the English text remains resource-owned data.
- What existed before: the page had detailed parser notes but remained scored unevaluated.
- Changed to: scored `COMPLETION:82` / `CONFIDENCE:90` and added direct IDA MCP string/xref/decompilation evidence.
- Summary and evidence: the loader behavior is strongly verified from `0x004f0010`; score remains below final because concrete string-id mappings and distribution/encoding policy are still incomplete.
- 2026-06-14 A002 Goal2 by-resource score pass:
  - What existed before: `COMPLETION:82` / `CONFIDENCE:90` documented the loader but lacked an explicit source/resource contract and current lookup-helper refresh on this page.
  - Changed to: `COMPLETION:85` / `CONFIDENCE:91` after refreshed IDA MCP confirmed loader and lookup helper bounds, `str.res` and fallback literal xrefs, parser decompilation, in-range lookup behavior, copy-out fallback behavior, and the source-versus-resource packaging split.
  - Remaining below higher score: full string-id mapping, actual payload audit, language-package variants, and final encoding policy remain open.
- 2026-06-14 A002 Goal2 continuation:
  - What existed before: `CANONICAL_OWNER:NONE` despite the page, loader evidence, and parent file all identifying [UID:0000KK][LanguageMan](by-file/LanguageMan.md) as the direct owner.
  - Changed to: `COMPLETION:86` / `CONFIDENCE:92` and `CANONICAL_OWNER:0000KK` after direct fallback-literal xref refresh fixed the exact `Invalid String ID` address and reconfirmed parser edge behavior.
  - No emitter or proposed path fields apply to by-resource pages.
- 2026-06-14 A002 resource-payload provenance:
  - What existed before: `COMPLETION:86` / `CONFIDENCE:92` with actual payload/package provenance still open.
  - Changed to: `COMPLETION:88` / `CONFIDENCE:94`.
  - Evidence: current DAT table parsing found `STR.RES` in `baram.dat` at entry index `9`, offset `11,268,984`, size `7,058`; extracting the payload confirmed a 248-line CR/LF text table whose first and final records match the IDA-observed line-oriented `LanguageMan` parser contract.
- 2026-06-21 Rule 26 B005 incorporation:
  - Changed to: `COMPLETION:89` / `CONFIDENCE:94`.
  - Evidence: B005's SelfSave constructor pass tied zero-based id `38` / `0x26` to current text `Save profile? (Y/N) ` and to [UID:0003O5][0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw](by-memory/0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw.md). The text remains resource-owned data, not a hard-coded source literal.
- 2026-06-21 Rule 26 B012 factory sync:
  - Scores unchanged.
  - Evidence: B012 tied [UID:0001KQ][0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory](by-memory/0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory.md) to the same id `38` / `0x26` lookup during retained `CreateSelfSaveInputPane()` construction. The helper source should remain `new SelfSaveInputPane`; the prompt text remains resource-owned data.
- 2026-06-21 Rule 26 B007 lookup split:
  - Scores unchanged.
  - Evidence: exact lookup/copy children [UID:00040P][0x004f0350-0x004f0372.LanguageManGetLocalizedString](by-memory/0x004f0350-0x004f0372.LanguageManGetLocalizedString.md) and [UID:00040Q][0x004f0380-0x004f03bb.LanguageManCopyLocalizedString](by-memory/0x004f0380-0x004f03bb.LanguageManCopyLocalizedString.md) replace the prior aggregate-only reference. The direct lookup child returns `m_strings[stringId]` or `L"Invalid String ID"`; the copy child assigns the selected/fallback text through `0x00582560`. The fallback literal at `0x0061ca20` is static LanguageMan diagnostic text, not a regular resource id.
- 2026-06-22 B013 read-only-data source-routing incorporation:
  - Scores unchanged.
  - Evidence: linked [UID:00040V][0x0061c9d4-0x0061c9dc.LanguageManParserLimitConstants](by-memory/0x0061c9d4-0x0061c9dc.LanguageManParserLimitConstants.md) and [UID:00040X][0x0061c9ec-0x0061ca44.LanguageManStringResourceLiterals](by-memory/0x0061c9ec-0x0061ca44.LanguageManStringResourceLiterals.md) as source-side support for this resource contract. The resource page still owns the DAT payload and id/text mapping; LanguageMan.cpp owns the loader constants and static literals.
