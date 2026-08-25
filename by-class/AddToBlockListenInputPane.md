*** UID:00000A | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HS | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HS | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// AddToBlockListenInputPane emits through exact children in this source file.
// See [UID:0001MZ][0x005b6c80-0x005b6cc0.AddToBlockListenInputPaneConstructor](by-memory/0x005b6c80-0x005b6cc0.AddToBlockListenInputPaneConstructor.md) for the constructor and [UID:0001N0][0x005b6cc0-0x005b700e.AddToBlockListenInputPaneSubmitBlockedName](by-memory/0x005b6cc0-0x005b700e.AddToBlockListenInputPaneSubmitBlockedName.md) for SubmitBlockedName().
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# AddToBlockListenInputPane

## Status

- Confidence: strong for behavior and source grouping.
- Likely source file: [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md)
- Autogen parent: [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md); both this class and the direct file parent now clear the strict 85/85 gate.
- Exact memory pages: [UID:0001MZ][0x005b6c80-0x005b6cc0.AddToBlockListenInputPaneConstructor](by-memory/0x005b6c80-0x005b6cc0.AddToBlockListenInputPaneConstructor.md), [UID:0001N0][0x005b6cc0-0x005b700e.AddToBlockListenInputPaneSubmitBlockedName](by-memory/0x005b6cc0-0x005b700e.AddToBlockListenInputPaneSubmitBlockedName.md)
- Module index: [UID:0001MW][0x005b68c0-0x005b7354.BlockListenInputPanes](by-memory/0x005b68c0-0x005b7354.BlockListenInputPanes.md)
- Vtable family: [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md)
- Local find helper: [UID:0001N3][0x005b74e0-0x005b7553.FindBlockListEntry](by-memory/0x005b74e0-0x005b7553.FindBlockListEntry.md)

## Class Purpose

`AddToBlockListenInputPane` is the line-input prompt that validates a name, adds it to the local block-listen vector, persists config, and sends the server add-block-list packet.

The successful submit path sends the add packet inline. The adjacent [UID:0002S0][0x005b7010-0x005b70f7.SendAddBlockListenPacket](by-memory/0x005b7010-0x005b70f7.SendAddBlockListenPacket.md) range is a retained file-local helper with the same opcode `0x0d` / subcommand `0x02` payload shape, not a proven `AddToBlockListenInputPane` method or a direct callee of this class.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| [UID:0001MZ][0x005b6c80-0x005b6cc0.AddToBlockListenInputPaneConstructor](by-memory/0x005b6c80-0x005b6cc0.AddToBlockListenInputPaneConstructor.md) | `AddToBlockListenInputPane::AddToBlockListenInputPane()` | Source-ready constructor: initializes `LineInputPane(g_pLanguageMan->GetLocalizedString(0x28))`; retained raw bytes also install the three compiler-emitted AddToBlockListenInputPane vtable views. Current package text for `STR.RES` id `0x28` is `Who do you wish to ignore? >`, but source keeps the localized lookup. |
| [UID:0001N0][0x005b6cc0-0x005b700e.AddToBlockListenInputPaneSubmitBlockedName](by-memory/0x005b6cc0-0x005b700e.AddToBlockListenInputPaneSubmitBlockedName.md) | `SubmitBlockedName()` | Reads up to 15 wide chars, rejects duplicates/full list/invalid names/self-name/overwide names, appends to config list, persists config, and sends opcode `0x0d`, subcommand `0x02`. |

## Validation Behavior

The submit handler accepts only alphabetic ASCII wide characters, compares against the local character name after uppercasing, and shows the exact [UID:0003EA][0x00630c08-0x00630c24.UserStatusInvalidNameLiteral](by-memory/0x00630c08-0x00630c24.UserStatusInvalidNameLiteral.md) alert for invalid input. It also checks duplicate list membership case-insensitively through [UID:0001N3][0x005b74e0-0x005b7553.FindBlockListEntry](by-memory/0x005b74e0-0x005b7553.FindBlockListEntry.md), which resolves to a `WideStringCompareNoCase` / `_wcsicmp` search over the block-listen name vector at `g_pConfig + 0x2918fc/+0x291900`.

## Evidence Notes

- IDA MCP `lookup_funcs` reports `0x005b6c80` as not defined, but limited disassembly confirms constructor-shaped bytes covering `0x005b6c80-0x005b6cc0`.
- IDA MCP confirms `0x005b6cc0` as `sub_5B6CC0`, size `0x34e`.
- IDA MCP confirms three `AddToBlockListenInputPane` vtable views at `0x006306d8`, `0x00630728`, and `0x00630758`, with stores from `BlockListenInputPane` dispatch and raw constructor-shaped bytes.
- IDA MCP callees include shared input helpers, `FindBlockListEntry_5B74E0`, packet-buffer byte/write helpers, `WideCharToMultiByte`, config persistence, and the broad send funnel at `0x00574bb0`.
- IDA MCP `xrefs_to 0x005b6cc0` reports a vtable/data reference at `0x00630720`.
- 2026-06-02 IDA MCP refresh confirms the same `0x005b6cc0` modeled function and vtable reference, plus the adjacent raw packet helper at [UID:0002S0][0x005b7010-0x005b70f7.SendAddBlockListenPacket](by-memory/0x005b7010-0x005b70f7.SendAddBlockListenPacket.md).
- 2026-06-05 IDA MCP refresh confirms [UID:0001N3][0x005b74e0-0x005b7553.FindBlockListEntry](by-memory/0x005b74e0-0x005b7553.FindBlockListEntry.md) as the only duplicate-check helper called from this handler and the delete-confirm handler.
- 2026-06-12 live IDA MCP session `a001-b276` reconfirmed the raw constructor at `0x005b6c80` as a `<no function>` body with prompt id `0x28`, `LineInputPane` base construction, and three vtable stores to `0x006306d8`, `0x00630728`, and `0x00630758`.
- 2026-06-12 live IDA MCP `trace_data_flow` shows those same three vtable bases are written both by the raw constructor (`0x005b6c9f/0x005b6ca7/0x005b6cb1`) and by `BlockListenInputPane::HandleCommandSelection` (`0x005b6b0a/0x005b6b10/0x005b6b1a`), proving this class is the direct owner of that subprompt.
- 2026-06-26 B006 current MCP session `80de0a67` resolves the constructor child [UID:0001MZ][0x005b6c80-0x005b6cc0.AddToBlockListenInputPaneConstructor](by-memory/0x005b6c80-0x005b6cc0.AddToBlockListenInputPaneConstructor.md) as source-ready. `lookup_funcs` still reports the raw constructor start and interior vptr-store addresses as `Not a function`, while successor `0x005b6cc0` is modeled as `sub_5B6CC0` size `0x34e` / 846 bytes (Verified with int_convert.py). Byte reads prove the exact `0x005b6c80-0x005b6cc0` range, `0x40` / 64-byte size (Verified with int_convert.py), predecessor padding at `0x005b6c7c-0x005b6c7f`, and immediate submit successor at `0x005b6cc0`.
- The same B006 pass decodes the source constructor shape as `AddToBlockListenInputPane::AddToBlockListenInputPane() : LineInputPane(g_pLanguageMan->GetLocalizedString(0x28)) {}`. The raw body loads [UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md), pushes id `0x28` / 40 (Verified with int_convert.py), calls [UID:00040P][0x004f0350-0x004f0372.LanguageManGetLocalizedString](by-memory/0x004f0350-0x004f0372.LanguageManGetLocalizedString.md), passes the returned prompt into `LineInputPane::LineInputPane(const wchar_t *)`, and then emits compiler vptr stores to `0x006306d8`, `0x00630728`, and `0x00630758`.
- Current `STR.RES` package extraction maps zero-based id `40` / `0x28` to `Who do you wish to ignore? >`. That text is resource-owned evidence for the UI prompt; source should call `g_pLanguageMan->GetLocalizedString(0x28)` or a future equivalent string-id constant rather than hard-code the English string.
- B006 `xrefs_to`/`trace_data_flow` in session `80de0a67` confirms the same vtable bases are written by the dispatcher mirror at `0x005b6b0a/0x005b6b10/0x005b6b1a` and by the raw constructor at `0x005b6c9f/0x005b6ca7/0x005b6cb1`; `find_bytes` finds exactly one AddToBlockListen vtable-store sequence in the dispatcher and one in the raw constructor. The dispatcher `A/a` branch allocates `0x108` / 264 bytes (Verified with int_convert.py), requests prompt id `0x28`, calls `LineInputPane`, and installs the same class vtables.
- B006 preserves the direct-route caveat: `xrefs_to 0x005b6c80` reports zero xrefs, and byte searches for raw-start VA pointer `80 6C 5B 00` and RVA pointer `80 6C 1B 00` return zero matches. This is a confidence cap, not a no-code proof, because the exact raw constructor and dispatcher mirror are source-equivalent.
- B006 confirms the submit relation: the AddToBlockListen primary vtable slot at `0x00630720` points to [UID:0001N0][0x005b6cc0-0x005b700e.AddToBlockListenInputPaneSubmitBlockedName](by-memory/0x005b6cc0-0x005b700e.AddToBlockListenInputPaneSubmitBlockedName.md). Submit validation, config insertion, persistence, and inline packet sending remain owned by [UID:0001N0][0x005b6cc0-0x005b700e.AddToBlockListenInputPaneSubmitBlockedName](by-memory/0x005b6cc0-0x005b700e.AddToBlockListenInputPaneSubmitBlockedName.md) and still need their own source-quality C++ pass.
- 2026-06-12 live IDA MCP decompilation of `0x005b6cc0` confirms the submit handler reads a bounded candidate name, duplicate-checks through [UID:0000PM][FindBlockListEntry_5B74E0](by-global/FindBlockListEntry_5B74E0.md), caps insertion at `0x14` entries, displays [UID:0003EA][0x00630c08-0x00630c24.UserStatusInvalidNameLiteral](by-memory/0x00630c08-0x00630c24.UserStatusInvalidNameLiteral.md) for invalid/self/overwide candidates, persists config through `0x00516030`, and sends opcode `0x0d` / subcommand `0x02`.
- 2026-06-19 B011 sync confirms the add send path in [UID:0001N0][0x005b6cc0-0x005b700e.AddToBlockListenInputPaneSubmitBlockedName](by-memory/0x005b6cc0-0x005b700e.AddToBlockListenInputPaneSubmitBlockedName.md) is an inline duplicate of [UID:0002S0][0x005b7010-0x005b70f7.SendAddBlockListenPacket](by-memory/0x005b7010-0x005b70f7.SendAddBlockListenPacket.md): both write `0x0d`, `0x02`, convert the wide name through `WideCharToMultiByte`, write a one-byte ANSI payload length, copy the payload, and call `QueueAndSendPacket(g_packetSender, packet, convertedLength + 3)`. Current static route scans found no rel32 or absolute-pointer route to `0x005b7010`, so the helper remains file-local under [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md).
- 2026-06-22 B013 sync resolves the duplicate-check helper's raw callees: `0x00584540` is `StringBase::c_str` / `GetStringDataPointer`, `0x00582950` is the `_wcsicmp` / case-insensitive wide compare wrapper, and `0x00582b70` releases the by-value `SimpleUString` search key. The add handler therefore rejects duplicates case-insensitively, not by an unresolved generic wide compare.

## Score Rationale

Completion is raised to `89` because the class now has current constructor, submit-handler, vtable-store, alert literal, duplicate-check, packet-send, parent-file, source-ready constructor evidence, formal first-draft submit-handler C++ on [UID:0001N0][0x005b6cc0-0x005b700e.AddToBlockListenInputPaneSubmitBlockedName](by-memory/0x005b6cc0-0x005b700e.AddToBlockListenInputPaneSubmitBlockedName.md), and a formal `[[CHILDREN]]` route marker on this class page. Confidence is raised to `90` because the main behavior, direct source parent, raw constructor bytes, dispatcher mirror, localized-prompt source shape, and exact child source/no-code split are live-IDA/current-doc backed. The class-level formal C++ intentionally routes to children because the exact constructor and submit-handler pages carry the source bodies and broad class declarations remain a later class-layout pass.

## Cross-References

- [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md)
- [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md)
- [UID:00000X][BlockListenInputPane](by-class/BlockListenInputPane.md)
- [UID:00003N][DeleteFromBlockListenInputPane](by-class/DeleteFromBlockListenInputPane.md)
- [UID:0000PM][FindBlockListEntry_5B74E0](by-global/FindBlockListEntry_5B74E0.md)
- [UID:0001N3][0x005b74e0-0x005b7553.FindBlockListEntry](by-memory/0x005b74e0-0x005b7553.FindBlockListEntry.md)
- [UID:0003EA][0x00630c08-0x00630c24.UserStatusInvalidNameLiteral](by-memory/0x00630c08-0x00630c24.UserStatusInvalidNameLiteral.md)
- [UID:0001QH][client_network](by-meta/client_network.md)

## Changes

- 2026-06-26 B006 [UID:0001MZ][0x005b6c80-0x005b6cc0.AddToBlockListenInputPaneConstructor](by-memory/0x005b6c80-0x005b6cc0.AddToBlockListenInputPaneConstructor.md) source-quality implementation:
  - Before: `85/88`; constructor evidence existed, but the class page still treated the raw constructor as blank-C++ and did not record the source-ready base initializer, current resource text, zero-route caveat, or detailed current dispatcher mirror.
  - Changed to: `86/89`; owner/emitter route through [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md) is unchanged, and the class formal C++ block remains blank because [UID:0001N0][0x005b6cc0-0x005b700e.AddToBlockListenInputPaneSubmitBlockedName](by-memory/0x005b6cc0-0x005b700e.AddToBlockListenInputPaneSubmitBlockedName.md) still needs its own source-quality C++ pass.
  - Summary/evidence: B006 MCP session `80de0a67` confirms exact `0x005b6c80-0x005b6cc0` constructor bytes, `0x40` / 64-byte size, prompt id `0x28` / current resource text `Who do you wish to ignore? >`, [UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md), [UID:00040P][0x004f0350-0x004f0372.LanguageManGetLocalizedString](by-memory/0x004f0350-0x004f0372.LanguageManGetLocalizedString.md), `LineInputPane` base construction, raw vptr stores at `0x005b6c9f/0x005b6ca7/0x005b6cb1`, dispatcher mirror stores at `0x005b6b0a/0x005b6b10/0x005b6b1a`, submit slot `0x00630720 -> 0x005b6cc0`, and zero raw-start xrefs/VA/RVA pointer hits. The constructor child now emits source-ready C++; the no-function/no-route caveat remains a confidence cap.
- What existed before: the page had exact method, vtable, validation, and packet evidence but was still scored `0/0`.
- What it was changed to: scores were set to `70/82` based on the existing IDA-backed constructor/submit-handler split and source-file placement.
- Summary and evidence: completion remains below high because final source grouping and the raw constructor-shaped range still need deeper validation.

- 2026-06-02:
  - Before: the class was not marked reconstructable or attached to a source parent.
  - After: marked `RECONSTRUCTABLE:TRUE`, attached to [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md), and raised to `76/86`.
  - Summary/evidence: source folder is now validated as `NexusTK/social/`; fresh IDA MCP confirms submit-handler, vtable, callee, and raw-helper adjacency evidence.

- 2026-06-05:
  - Before: the status still pointed at stale output provenance.
  - After: removed that provenance and tied the duplicate-check helper to current IDA MCP evidence.
  - Summary/evidence: current IDA MCP confirms [UID:0001N3][0x005b74e0-0x005b7553.FindBlockListEntry](by-memory/0x005b74e0-0x005b7553.FindBlockListEntry.md) is called from `sub_5B6CC0` at `0x005b6d89`.

- 2026-06-10 A002 strict-gate repair:
  - Before: `AUTOGEN_PARENT_UID:0000HS` attached this class to [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md).
  - After: `AUTOGEN_PARENT_UID:` is blank; score remains `76/86`.
  - Summary/evidence: the direct file parent is now `85/89`, but the child page is below the required child completion threshold. Keep the source-owner cross-reference and evidence, but do not emit this class through validator autogen until the child page reaches `85/85`.

- 2026-06-12 A005 Batch 278 strict-gate repair:
  - Before: `76/86`, `AUTOGEN_PARENT_UID:` blank, with the direct file parent already at `85/89`.
  - After: `85/88`, `AUTOGEN_PARENT_UID:0000HS`.
  - Summary/evidence: live IDA MCP reconfirmed the raw constructor, three AddToBlockListenInputPane vtable views and write sites, submit-handler validation/send behavior, and the sole [UID:0003EA][0x00630c08-0x00630c24.UserStatusInvalidNameLiteral](by-memory/0x00630c08-0x00630c24.UserStatusInvalidNameLiteral.md) consumer; the class and direct file parent now both clear `85/85`.
- 2026-06-19 B011 [UID:0002S0][0x005b7010-0x005b70f7.SendAddBlockListenPacket](by-memory/0x005b7010-0x005b70f7.SendAddBlockListenPacket.md) support sync: no score change. Clarified that this class sends subcommand `0x02` inline and that the retained raw helper is file-local rather than a proven class method.
- 2026-06-22 B013 [UID:0001N3][0x005b74e0-0x005b7553.FindBlockListEntry](by-memory/0x005b74e0-0x005b7553.FindBlockListEntry.md) support sync: no score change. Recorded that duplicate detection is case-insensitive through the shared file-local find helper and the `_wcsicmp` wrapper, with the config block-listen vector still pending final field naming.
- 2026-07-01 B007 empty-emitter implementation callback: raised `86/89` to `89/90` and inserted the formal `[[CHILDREN]]` class-route marker. The exact source bodies now live on [UID:0001MZ][0x005b6c80-0x005b6cc0.AddToBlockListenInputPaneConstructor](by-memory/0x005b6c80-0x005b6cc0.AddToBlockListenInputPaneConstructor.md) and [UID:0001N0][0x005b6cc0-0x005b700e.AddToBlockListenInputPaneSubmitBlockedName](by-memory/0x005b6cc0-0x005b700e.AddToBlockListenInputPaneSubmitBlockedName.md); this class page stays a route/ownership page instead of duplicating broad class declaration C++.
