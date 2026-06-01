*** UID:0000RU | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pNewSystemMessagePane

## Status

- Confidence: strong for singleton address and owner.
- Address: `0x0069bc10`
- Proposed owner: [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)
- Primary class: [UID:00009C][NewSystemMessagePane](by-class/NewSystemMessagePane.md)

## Role

`g_pNewSystemMessagePane` stores the active newer system-message panel singleton. The resize handle uses it to refresh the panel after committing a new height, and the `NewSystemMessagePane` constructor/destructor maintain the pointer.

## Evidence

- IDA `xrefs_to 0x0069bc10` reports writes from `NewSystemMessagePane` construction at `0x00588560`, clear helper `0x0058aab0`, and scalar deleting destructor `0x0058ad20`.
- IDA decompilation of `0x005882f0` shows the height-modify drag handler calling a virtual refresh method through `g_pNewSystemMessagePane` after writing the saved height.
- 2026-05-25 IDA recheck reports concrete xrefs at `0x005883c0`, `0x005885b8`, `0x005885bf`, `0x005887e9`, `0x0058aab0`, and `0x0058ad6c`.

## 2026-05-30 Review Notes

- IDA MCP `py_eval` on 2026-05-30 confirms `0x0069bc10` is `dword_69BC10`, size `4`, in `.data`, with 6 data xrefs.
- Live IDA xrefs confirm the height-modify consumer at `0x005883c0` in `sub_5882F0`, constructor writes at `0x005885b8` and `0x005885bf` in `sub_588560`, an additional constructor-body reference at `0x005887e9`, clear helper at `0x0058aab0` in `sub_58AAB0`, and destructor clear at `0x0058ad6c` in `sub_58AD20`.
- Live IDA MCP also confirms adjacent `0x0069bc0c` as `dword_69BC0C`, `.data` size `4`, with 7 xrefs tied to `NewSystemMessageModifyHeightPane`; this supports keeping both slots together in [UID:0002AO][0x0069bc0c-0x0069bc18.SystemMessagePaneSingletonSlots](by-memory/0x0069bc0c-0x0069bc18.SystemMessagePaneSingletonSlots.md).
- Completion remains below full because `0x005887e9` was not mapped to a containing IDA function in this query and the exact source split from the broader system-message pane family remains provisional.

## Cross-References

- [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)
- [UID:00009C][NewSystemMessagePane](by-class/NewSystemMessagePane.md)
- [UID:00009B][NewSystemMessageModifyHeightPane](by-class/NewSystemMessageModifyHeightPane.md)
- [UID:0001J6][0x00584ea0-0x0058af3b.SystemMessagePanes](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md)
- [UID:0002AO][0x0069bc0c-0x0069bc18.SystemMessagePaneSingletonSlots](by-memory/0x0069bc0c-0x0069bc18.SystemMessagePaneSingletonSlots.md)

## Changes

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `78`, confidence `86`.
- Summary/evidence: live IDA MCP on 2026-05-30 verified exact storage, size, segment, 6 xrefs for `g_pNewSystemMessagePane`, adjacent height-pane singleton context, constructor/clear/destructor writes, and resize-handler consumer use. Completion remains below full because source split and one singleton reference inside the constructor body still need deeper classification.
