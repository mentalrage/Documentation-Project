*** UID:0000RU | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000OE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pNewSystemMessagePane

## Status

- Confidence: strong for singleton address, owner, lifecycle writes, and resize-handler consumer.
- Address: `0x0069bc10`
- Proposed owner: [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)
- Primary class: [UID:00009C][NewSystemMessagePane](by-class/NewSystemMessagePane.md)

## Role

`g_pNewSystemMessagePane` stores the active newer system-message panel singleton. The resize handle uses it to refresh the panel after committing a new height, and the `NewSystemMessagePane` constructor/destructor maintain the pointer.

## Evidence

- IDA `xrefs_to 0x0069bc10` reports writes from `NewSystemMessagePane` construction at `0x00588560`, the singleton-clear helper at `0x0058aab0`, and the scalar deleting destructor at `0x0058ad20`.
- IDA decompilation of `0x005882f0` shows the height-modify drag handler calling a virtual refresh method through `g_pNewSystemMessagePane` after writing the saved height.
- 2026-06-06 IDA MCP reports concrete xrefs at `0x005883c0`, `0x005885b8`, `0x005885bf`, `0x005887e9`, `0x0058aab0`, and `0x0058ad6c`, and confirms the slot is initialized to `0xffffffff`.

## 2026-05-30 Review Notes

- IDA MCP on 2026-06-06 confirms `0x0069bc10` is a four-byte `.data` slot initialized to `0xffffffff`, with 6 data xrefs.
- Live IDA xrefs confirm the height-modify consumer at `0x005883c0`, constructor publish/fallback refs at `0x005885b8` and `0x005885bf`, an additional constructor-body reference at `0x005887e9`, singleton-clear helper at `0x0058aab0`, and destructor clear at `0x0058ad6c`.
- Existing docs also tie adjacent `0x0069bc0c` to `NewSystemMessageModifyHeightPane`; this supports keeping both slots together in [UID:0002AO][0x0069bc0c-0x0069bc18.SystemMessagePaneSingletonSlots](by-memory/0x0069bc0c-0x0069bc18.SystemMessagePaneSingletonSlots.md).
- Live IDA decompilation confirms `0x00588560` publishes the current object into the singleton slot and installs the `NewSystemMessagePane` vtable, while `0x0058aab0` and `0x0058ad20` clear the singleton during cleanup/destruction.
- Completion remains below full because `0x005887e9` is an interior constructor-body reference without a containing function in this xref query and the exact source split from the broader system-message pane family remains provisional.

## Cross-References

- [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)
- [UID:00009C][NewSystemMessagePane](by-class/NewSystemMessagePane.md)
- [UID:00009B][NewSystemMessageModifyHeightPane](by-class/NewSystemMessageModifyHeightPane.md)
- [UID:0001J6][0x00584ea0-0x0058af3b.SystemMessagePanes](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md)
- [UID:0002AO][0x0069bc0c-0x0069bc18.SystemMessagePaneSingletonSlots](by-memory/0x0069bc0c-0x0069bc18.SystemMessagePaneSingletonSlots.md)

## Changes

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `84`, confidence `88`.
- Summary/evidence: live IDA MCP on 2026-06-06 verified exact storage, size, segment, 6 xrefs for `g_pNewSystemMessagePane`, adjacent height-pane singleton context, constructor/clear/destructor writes, and resize-handler consumer use. Completion remains below full because source split and one singleton reference inside the constructor body still need deeper classification.

- 2026-06-05 autogen classification:
  - What existed before: autogen metadata was blank, so the singleton was reported as unclassified.
  - Changed to: `RECONSTRUCTABLE:TRUE` with `AUTOGEN_PARENT_UID:0000OE`; `RECONSTRUCTION_CPP CODE` remains empty.
  - Summary/evidence: live IDA MCP `xrefs_to 0x0069bc10` and decompilation of `0x00588560`, `0x0058aab0`, and `0x0058ad20` prove NexusTK-owned `NewSystemMessagePane` singleton storage owned by [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md). No final C++ body was added because the page is below the 95/95 reconstruction gate.
- 2026-06-06 source-facing cleanup:
  - What existed before: score `78/86`, raw IDA storage/function labels in evidence, and a stale global coverage-row summary.
  - Changed to: score `84/88`, refreshed live xref/byte evidence, source-facing singleton wording, and synced the editable by-global coverage row.
  - Summary/evidence: current IDA MCP confirms initialized storage, resize-handler consumer, constructor publish/fallback refs, singleton-clear helper, destructor clear, adjacent height-pane singleton context, and SystemMessagePanes file-parent ownership. Validator/generated sync is pending because those shared files were leased by another agent.
