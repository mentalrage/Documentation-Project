*** UID:00000A | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# AddToBlockListenInputPane

## Status

- Confidence: strong for behavior and source grouping.
- Likely source file: [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md)
- Autogen parent: blank under the strict 85/85 gate. The direct file parent now clears at `85/89`, but this child remains `76/86`, so assignment waits on more completion.
- Exact memory pages: [UID:0001MZ][0x005b6c80-0x005b6cc0.AddToBlockListenInputPaneConstructor](by-memory/0x005b6c80-0x005b6cc0.AddToBlockListenInputPaneConstructor.md), [UID:0001N0][0x005b6cc0-0x005b700e.AddToBlockListenInputPaneSubmitBlockedName](by-memory/0x005b6cc0-0x005b700e.AddToBlockListenInputPaneSubmitBlockedName.md)
- Module index: [UID:0001MW][0x005b68c0-0x005b7354.BlockListenInputPanes](by-memory/0x005b68c0-0x005b7354.BlockListenInputPanes.md)
- Vtable family: [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md)
- Local find helper: [UID:0001N3][0x005b74e0-0x005b7553.FindBlockListEntry](by-memory/0x005b74e0-0x005b7553.FindBlockListEntry.md)

## Class Purpose

`AddToBlockListenInputPane` is the line-input prompt that validates a name, adds it to the local block-listen vector, persists config, and sends the server add-block-list packet.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| [UID:0001MZ][0x005b6c80-0x005b6cc0.AddToBlockListenInputPaneConstructor](by-memory/0x005b6c80-0x005b6cc0.AddToBlockListenInputPaneConstructor.md) | `AddToBlockListenInputPane::AddToBlockListenInputPane()` | Constructor-shaped bytes: localizes prompt id `0x28`, calls `LineInputPane`, and installs three vtable views. |
| [UID:0001N0][0x005b6cc0-0x005b700e.AddToBlockListenInputPaneSubmitBlockedName](by-memory/0x005b6cc0-0x005b700e.AddToBlockListenInputPaneSubmitBlockedName.md) | `SubmitBlockedName()` | Reads up to 15 wide chars, rejects duplicates/full list/invalid names/self-name/overwide names, appends to config list, persists config, and sends opcode `0x0d`, subcommand `0x02`. |

## Validation Behavior

The submit handler accepts only alphabetic ASCII wide characters, compares against the local character name after uppercasing, and shows a literal `Invalid name` alert for invalid input. It also checks list membership through [UID:0000PM][FindBlockListEntry_5B74E0](by-global/FindBlockListEntry_5B74E0.md).

## Evidence Notes

- IDA MCP `lookup_funcs` reports `0x005b6c80` as not defined, but limited disassembly confirms constructor-shaped bytes covering `0x005b6c80-0x005b6cc0`.
- IDA MCP confirms `0x005b6cc0` as `sub_5B6CC0`, size `0x34e`.
- IDA MCP confirms three `AddToBlockListenInputPane` vtable views at `0x006306d8`, `0x00630728`, and `0x00630758`, with stores from `BlockListenInputPane` dispatch and raw constructor-shaped bytes.
- IDA MCP callees include shared input helpers, `FindBlockListEntry_5B74E0`, packet-buffer byte/write helpers, `WideCharToMultiByte`, config persistence, and the broad send funnel at `0x00574bb0`.
- IDA MCP `xrefs_to 0x005b6cc0` reports a vtable/data reference at `0x00630720`.
- 2026-06-02 IDA MCP refresh confirms the same `0x005b6cc0` modeled function and vtable reference, plus the adjacent raw packet helper at [UID:0002S0][0x005b7010-0x005b70f7.SendAddBlockListenPacket](by-memory/0x005b7010-0x005b70f7.SendAddBlockListenPacket.md).
- 2026-06-05 IDA MCP refresh confirms [UID:0001N3][0x005b74e0-0x005b7553.FindBlockListEntry](by-memory/0x005b74e0-0x005b7553.FindBlockListEntry.md) as the only duplicate-check helper called from this handler and the delete-confirm handler.

## Cross-References

- [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md)
- [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md)
- [UID:00000X][BlockListenInputPane](by-class/BlockListenInputPane.md)
- [UID:00003N][DeleteFromBlockListenInputPane](by-class/DeleteFromBlockListenInputPane.md)
- [UID:0000PM][FindBlockListEntry_5B74E0](by-global/FindBlockListEntry_5B74E0.md)
- [UID:0001N3][0x005b74e0-0x005b7553.FindBlockListEntry](by-memory/0x005b74e0-0x005b7553.FindBlockListEntry.md)
- [UID:0001QH][client_network](by-meta/client_network.md)

## Changes

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
