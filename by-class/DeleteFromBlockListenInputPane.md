*** UID:00003N | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HS | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HS | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// DeleteFromBlockListenInputPane emits through exact children in this source file.
// See [UID:0001N1][0x005b7100-0x005b7140.DeleteFromBlockListenInputPaneConstructor](by-memory/0x005b7100-0x005b7140.DeleteFromBlockListenInputPaneConstructor.md) for the constructor and [UID:0001N2][0x005b7140-0x005b7354.DeleteFromBlockListenInputPaneOnConfirm](by-memory/0x005b7140-0x005b7354.DeleteFromBlockListenInputPaneOnConfirm.md) for OnConfirm().
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# DeleteFromBlockListenInputPane

## Status

- Confidence: strong for behavior and source grouping.
- Likely source file: [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md)
- Autogen parent: [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md). B006 source-quality incorporation raises this child to `86/89`, while the direct file parent remains `85/89`, so both sides clear the strict 85/85 routing gate.
- Exact memory pages: [UID:0001N1][0x005b7100-0x005b7140.DeleteFromBlockListenInputPaneConstructor](by-memory/0x005b7100-0x005b7140.DeleteFromBlockListenInputPaneConstructor.md), [UID:0001N2][0x005b7140-0x005b7354.DeleteFromBlockListenInputPaneOnConfirm](by-memory/0x005b7140-0x005b7354.DeleteFromBlockListenInputPaneOnConfirm.md)
- Module index: [UID:0001MW][0x005b68c0-0x005b7354.BlockListenInputPanes](by-memory/0x005b68c0-0x005b7354.BlockListenInputPanes.md)
- Vtable family: [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md)
- Local find helper: [UID:0001N3][0x005b74e0-0x005b7553.FindBlockListEntry](by-memory/0x005b74e0-0x005b7553.FindBlockListEntry.md)

## Class Purpose

`DeleteFromBlockListenInputPane` is the line-input prompt that removes a case-insensitive matching name from the local block-listen vector, persists config, and sends the server delete-block-list packet.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| [UID:0001N1][0x005b7100-0x005b7140.DeleteFromBlockListenInputPaneConstructor](by-memory/0x005b7100-0x005b7140.DeleteFromBlockListenInputPaneConstructor.md) | `DeleteFromBlockListenInputPane::DeleteFromBlockListenInputPane()` | Source-ready constructor: initializes the `LineInputPane` base with `g_pLanguageMan->GetLocalizedString(0x29)`. Current `STR.RES` id `0x29` text is `Who do you wish to hear? >`, but source keeps the localized lookup. The three DeleteFromBlockListen vptr stores are compiler-emitted constructor effects. |
| [UID:0001N2][0x005b7140-0x005b7354.DeleteFromBlockListenInputPaneOnConfirm](by-memory/0x005b7140-0x005b7354.DeleteFromBlockListenInputPaneOnConfirm.md) | `OnConfirm()` | Reads up to 15 wide chars, finds the matching list entry, erases it from the vector, persists config, and sends opcode `0x0d`, subcommand `0x03`. |

## Bad Method Rows

Old catalog rows attached excluded methods `0x00680067` and `0x00690052` to this class. IDA MCP says neither address is a function. These are bogus pointer values read from the first UTF-16 dwords of `"Right click look :ON"` / `"Right click look :OFF"` string data at `0x006307ec`, `0x006307f0`, `0x00630818`, and `0x0063081c`; the target addresses themselves are undefined `0xff` filler bytes. They should not be migrated with this class.

2026-05-26 recheck: these two false starts are now listed in [UID:0000VN][-ignored](by-memory/-ignored.md) as data-fragment artifacts, not methods.

## Evidence Notes

- IDA MCP `lookup_funcs` reports `0x005b7100` as not defined, but limited disassembly confirms constructor-shaped bytes covering `0x005b7100-0x005b7140`.
- IDA MCP confirms `0x005b7140` as `sub_5B7140`, size `0x214`.
- IDA MCP confirms three `DeleteFromBlockListenInputPane` vtable views at `0x00630764`, `0x006307b4`, and `0x006307e4`, with stores from `BlockListenInputPane` dispatch and raw constructor-shaped bytes.
- IDA MCP callees include shared input helpers, [UID:0000PM][FindBlockListEntry_5B74E0](by-global/FindBlockListEntry_5B74E0.md), vector move/destroy helpers, config persistence, packet-buffer helpers, `WideCharToMultiByte`, and the broad send funnel at `0x00574bb0`.
- IDA MCP `xrefs_to 0x005b7140` reports a vtable/data reference at `0x006307ac`.
- IDA MCP `lookup_funcs` reports `0x00680067` and `0x00690052` as `Not a function`; `xrefs_to` reports data refs only.
- 2026-06-02 IDA MCP refresh confirms the same `0x005b7140` modeled function and vtable reference, plus the adjacent raw packet helper at [UID:0002RZ][0x005b7360-0x005b7447.SendDeleteBlockListenPacket](by-memory/0x005b7360-0x005b7447.SendDeleteBlockListenPacket.md).
- 2026-06-05 IDA MCP refresh confirms [UID:0001N3][0x005b74e0-0x005b7553.FindBlockListEntry](by-memory/0x005b74e0-0x005b7553.FindBlockListEntry.md) as the only local find helper called from this handler and the add-submit handler.
- 2026-06-12 Batch 300 IDA MCP refresh confirms `0x005b7100` and `0x005b711f` are not modeled function starts, while the raw constructor bytes are unique over `0x005b7100-0x005b7140`. The signature starts `55 8B EC 51 56 8B F1 ...` and is unique in IDA.
- 2026-06-12 Batch 300 IDA MCP `trace_data_flow` confirms the three `DeleteFromBlockListenInputPane` vtable views are installed both by `BlockListenInputPane::HandleCommandSelection` at `0x005b6bd5`, `0x005b6bdb`, and `0x005b6be5` and by the raw constructor-shaped bytes at `0x005b711f`, `0x005b7127`, and `0x005b7131`.
- 2026-06-12 Batch 300 IDA MCP confirms vtable slot `0x006307ac` is `dd offset sub_5B7140`; `lookup_funcs` still reports `sub_5B7140` at `0x005b7140`, size `0x214`/532, with no ordinary callers.
- 2026-06-26 B006 accepted source-quality implementation for [UID:0001N1][0x005b7100-0x005b7140.DeleteFromBlockListenInputPaneConstructor](by-memory/0x005b7100-0x005b7140.DeleteFromBlockListenInputPaneConstructor.md) uses live MCP session `80de0a67` and resolves the constructor as source-ready: `DeleteFromBlockListenInputPane::DeleteFromBlockListenInputPane() : LineInputPane(g_pLanguageMan->GetLocalizedString(0x29)) {}`. MCP still reports `0x005b7100`, `0x005b711f`, `0x005b7127`, `0x005b7131`, and `0x005b713f` as `Not a function`; exact bytes cover `0x005b7100-0x005b7140`, size `0x40` / 64 bytes (Verified with int_convert.py), after nine `0xcc` bytes at `0x005b70f7-0x005b70ff` and before successor `0x005b7140`.
- The B006 pass ties prompt id `0x29` / zero-based resource id 41 (Verified with int_convert.py) to current package text `Who do you wish to hear? >`; this is resource evidence only, and constructor source keeps `g_pLanguageMan->GetLocalizedString(0x29)` instead of embedding English text.
- The same pass confirms the constructor's raw vptr stores at `0x005b711f`, `0x005b7127`, and `0x005b7131`, the dispatcher mirror stores at `0x005b6bd5`, `0x005b6bdb`, and `0x005b6be5`, and successor slot `0x006307ac -> 0x005b7140`. `xrefs_to 0x005b7100`, raw-start VA pointer bytes `00 71 5b 00`, and raw-start RVA pointer bytes `00 71 1b 00` all return zero matches, so the no-function/no-direct-route state remains a confidence cap rather than a C++ blocker.
- 2026-06-12 Batch 300 decompilation reconfirms the handler reads up to 15 wide characters, compares against the block-list vector range at `dword_67A7C8 + 0x2918fc` through `+0x291900`, calls `sub_5B74E0`, erases by moving later four-byte string entries, destroys the former tail, calls config persistence `0x00516030`, writes packet bytes `0x0d`/13 and `0x03`/3, converts through `WideCharToMultiByte`, range-checks against `0x100`/256 and `0x400`/1024 buffers, and sends through `0x00574bb0`.
- 2026-06-12 Batch 300 IDA MCP `lookup_funcs` reconfirms adjacent packet helper `0x005b7360` and stale generated rows `0x00680067`/`0x00690052` are not functions.
- 2026-06-22 B013 sync resolves the local find helper as source-style `FindBlockListEntry`: it searches `SimpleUStringVector` 4-byte pointer-backed string slots case-insensitively through `0x00582950` (`WideStringCompareNoCase` / `_wcsicmp`), uses `0x00584540` as the `StringBase::c_str` accessor, and releases the by-value search key through `0x00582b70`. The compared vector is the block-listen name vector at `g_pConfig + 0x2918fc/+0x291900`, pending a final config-field name.

## Parent-Chain Decision

The actual direct parent is [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md), not the broad memory island. The file page already clears `85/89` and names `DeleteFromBlockListenInputPane` as one of its three command-prompt classes. B006 source-quality incorporation adds constructor C++ readiness, localized prompt/resource evidence, raw vtable-store evidence, dispatcher mirror evidence, and negative raw-start route checks, raising this child to `86/89`; the class now routes to the file parent. The exact memory children route to this class rather than directly to the file because their ownership is class-specific and the class clears the gate.

## Score Rationale

Completion is raised to `89` because the class now has a source-ready constructor page with exact formal C++, exact constructor range/boundary evidence, prompt/resource evidence, vtable views, dispatcher mirror, confirm-handler page, formal first-draft confirm-handler C++ on [UID:0001N2][0x005b7140-0x005b7354.DeleteFromBlockListenInputPaneOnConfirm](by-memory/0x005b7140-0x005b7354.DeleteFromBlockListenInputPaneOnConfirm.md), source parent, helper boundaries, false-start exclusions, and a formal `[[CHILDREN]]` route marker on this class page. Confidence is raised to `90` because live IDA evidence ties the raw constructor-shaped bytes, dispatcher mirror, and virtual confirm slot to the same class, resource id `0x29` matches the delete prompt text, and the exact child source/no-code split is now explicit. Broad class declarations remain a later class-layout pass rather than content to duplicate here.

## Cross-References

- [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md)
- [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md)
- [UID:00000X][BlockListenInputPane](by-class/BlockListenInputPane.md)
- [UID:00000A][AddToBlockListenInputPane](by-class/AddToBlockListenInputPane.md)
- [UID:0000PM][FindBlockListEntry_5B74E0](by-global/FindBlockListEntry_5B74E0.md)
- [UID:0001N3][0x005b74e0-0x005b7553.FindBlockListEntry](by-memory/0x005b74e0-0x005b7553.FindBlockListEntry.md)
- [UID:0001QH][client_network](by-meta/client_network.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `76/82`.
  - Summary/evidence: prompt constructor, confirm behavior, packet shape, bad method rows, vtable views, callees, and network/config side effects are documented; remaining uncertainty is mainly final source grouping.

- 2026-06-02:
  - Before: the class was not marked reconstructable or attached to a source parent.
  - After: marked `RECONSTRUCTABLE:TRUE`, attached to [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md), and raised to `80/86`.
  - Summary/evidence: source folder is now validated as `NexusTK/social/`; fresh IDA MCP confirms confirm-handler, vtable, callee, bad-row, and raw-helper adjacency evidence.

- 2026-06-05:
  - Before: the status and bad-row sections still carried stale output/tooling provenance.
  - After: removed that provenance and tied the local find helper to current IDA MCP evidence.
  - Summary/evidence: current IDA MCP confirms [UID:0001N3][0x005b74e0-0x005b7553.FindBlockListEntry](by-memory/0x005b74e0-0x005b7553.FindBlockListEntry.md) is called from `sub_5B7140` at `0x005b720d`, while `0x00680067` and `0x00690052` remain data-only false starts.

- 2026-06-10 A002 strict-gate repair:
  - Before: `AUTOGEN_PARENT_UID:0000HS` attached this class to [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md).
  - After: `AUTOGEN_PARENT_UID:` is blank; score remains `80/86`.
  - Summary/evidence: the direct file parent is now `85/89`, but the child page is below the required child completion threshold. Keep the source-owner cross-reference and evidence, but do not emit this class through validator autogen until the child page reaches `85/85`.

- 2026-06-12 Agent-A001 Batch 300:
  - Before: class was `80/86` with blank autogen parent under the strict child gate.
  - After: class is `85/88` with `AUTOGEN_PARENT_UID:0000HS`.
  - Summary/evidence: live IDA MCP confirms unique raw constructor bytes, all three vtable install sites from both dispatcher and constructor-shaped ranges, confirm-handler vtable slot `0x006307ac`, modeled handler size `0x214`/532, block-list vector erase, config persistence, packet opcode/subcommand, buffer bounds, and stale non-function exclusions.
- 2026-06-22 B013 [UID:0001N3][0x005b74e0-0x005b7553.FindBlockListEntry](by-memory/0x005b74e0-0x005b7553.FindBlockListEntry.md) support sync: no score change. Recorded that delete lookup is case-insensitive through the shared file-local find helper and the `_wcsicmp` wrapper, with the block-listen config vector still awaiting final field naming.
- 2026-06-26 B006 [UID:0001N1][0x005b7100-0x005b7140.DeleteFromBlockListenInputPaneConstructor](by-memory/0x005b7100-0x005b7140.DeleteFromBlockListenInputPaneConstructor.md) source-quality implementation:
  - Before: class was `85/88`; constructor row recognized raw bytes but did not record final constructor C++ readiness or resource-owned prompt text for id `0x29`.
  - After: class is `86/89`; constructor row and evidence notes record source-ready `DeleteFromBlockListenInputPane::DeleteFromBlockListenInputPane()`, source shape `LineInputPane(g_pLanguageMan->GetLocalizedString(0x29))`, current `STR.RES` text `Who do you wish to hear? >`, raw vptr stores, dispatcher mirror stores, successor slot `0x006307ac -> 0x005b7140`, and zero raw-start xref/VA/RVA pointer evidence.
  - Summary/evidence: the constructor blocker is resolved, but class-level C++ remains blank because [UID:0001N2][0x005b7140-0x005b7354.DeleteFromBlockListenInputPaneOnConfirm](by-memory/0x005b7140-0x005b7354.DeleteFromBlockListenInputPaneOnConfirm.md) still owns the separate submit/delete source-quality work.
- 2026-07-01 B007 empty-emitter implementation callback: raised `86/89` to `89/90` and inserted the formal `[[CHILDREN]]` class-route marker. The exact source bodies now live on [UID:0001N1][0x005b7100-0x005b7140.DeleteFromBlockListenInputPaneConstructor](by-memory/0x005b7100-0x005b7140.DeleteFromBlockListenInputPaneConstructor.md) and [UID:0001N2][0x005b7140-0x005b7354.DeleteFromBlockListenInputPaneOnConfirm](by-memory/0x005b7140-0x005b7354.DeleteFromBlockListenInputPaneOnConfirm.md); this class page stays a route/ownership page instead of duplicating broad class declaration C++.
