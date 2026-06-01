*** UID:0000R2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pHeightModifyPane

## Status

- Confidence: strong for singleton address and owner.
- Address: `0x0069bc0c`
- Proposed owner: [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)
- Primary class: [UID:00009B][NewSystemMessageModifyHeightPane](by-class/NewSystemMessageModifyHeightPane.md)

## Role

`g_pHeightModifyPane` stores the active new-system-message resize handle singleton. The constructor writes it, cleanup/destructor helpers clear it, and `NewSystemMessagePane` construction creates the owned handle.

## Evidence

- IDA `xrefs_to 0x0069bc0c` reports writes from `0x005881f0` and inlined construction inside `0x00588560`.
- IDA confirms clear paths at `0x005882c0`, `0x0058aaa0`, and `0x0058acc0`.
- Active generated source names the symbol `g_pHeightModifyPane` in `class_NewSystemMessageModifyHeightPane.cpp`.
- 2026-05-25 IDA recheck reports concrete xrefs at `0x00588239`, `0x00588240`, `0x005882da`, `0x00588620`, `0x00588627`, `0x0058aaa0`, and `0x0058ace0`.

## Cross-References

- [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)
- [UID:00009B][NewSystemMessageModifyHeightPane](by-class/NewSystemMessageModifyHeightPane.md)
- [UID:0001J6][0x00584ea0-0x0058af3b.SystemMessagePanes](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `84/84`. Summary/evidence: the page documents address, owner, resize-handle singleton role, constructor/clear xrefs, generated source name, IDA recheck sites, and class/file/memory refs.
