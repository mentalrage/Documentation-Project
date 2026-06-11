*** UID:00003N | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DeleteFromBlockListenInputPane

## Status

- Confidence: strong for behavior and source grouping.
- Likely source file: [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md)
- Autogen parent: blank under the strict 85/85 gate. The direct file parent now clears at `85/89`, but this child remains `80/86`, so assignment waits on more completion.
- Exact memory pages: [UID:0001N1][0x005b7100-0x005b7140.DeleteFromBlockListenInputPaneConstructor](by-memory/0x005b7100-0x005b7140.DeleteFromBlockListenInputPaneConstructor.md), [UID:0001N2][0x005b7140-0x005b7354.DeleteFromBlockListenInputPaneOnConfirm](by-memory/0x005b7140-0x005b7354.DeleteFromBlockListenInputPaneOnConfirm.md)
- Module index: [UID:0001MW][0x005b68c0-0x005b7354.BlockListenInputPanes](by-memory/0x005b68c0-0x005b7354.BlockListenInputPanes.md)
- Vtable family: [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md)
- Local find helper: [UID:0001N3][0x005b74e0-0x005b7553.FindBlockListEntry](by-memory/0x005b74e0-0x005b7553.FindBlockListEntry.md)

## Class Purpose

`DeleteFromBlockListenInputPane` is the line-input prompt that removes a matching name from the local block-listen vector, persists config, and sends the server delete-block-list packet.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| [UID:0001N1][0x005b7100-0x005b7140.DeleteFromBlockListenInputPaneConstructor](by-memory/0x005b7100-0x005b7140.DeleteFromBlockListenInputPaneConstructor.md) | `DeleteFromBlockListenInputPane::DeleteFromBlockListenInputPane()` | Constructor-shaped bytes: localizes prompt id `0x29`, calls `LineInputPane`, and installs three vtable views. |
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
