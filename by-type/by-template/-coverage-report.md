*** UID:0001WK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# by-type/by-template Coverage Report

## Summary

- Last generated: 2026-05-26
- Folder: `by-type/by-template`
- Coverage summary: 5 covered reconstructable rows, 1 covered ignored row, 1 uncovered inventory placeholder row.
- Confidence summary: baseline report generated from existing documentation pages and `-ignored.md`; ignored rows are driven by the local ignored ledger, while reconstructable row confidence is heuristic until IDA/MCP or manual verification raises it.
- Ordering: alphabetic by item name, except `by-memory`, which is sorted by the first address in the row.

## Covered Items To Replicate

- [UID:0001WN][AUTOBUF_unsigned_char](by-type/by-template/AUTOBUF_unsigned_char.md) : reconstructable : 76% : strong : IDA-verified concrete `_AUTOBUF<unsigned char>` constructor, resize helper, vtable data, and MapPane/UserLookPane caller evidence; exact original template spelling/header placement remains open.
- [UID:0001WP][FolderTreePaneTreeTemplates](by-type/by-template/FolderTreePaneTreeTemplates.md) : reconstructable : 80% : strong : IDA-confirmed project-local `Tree`/`TreeStorage`/`TreeItor` template support for `FolderTreePane::TreeElem`, with exact storage/reset/iterator child ranges split; final template header spelling and sort-helper splits remain open.
- [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md) : reconstructable : 78% : strong : - IDA rechecked representative callback wrappers/destructors and split MusicControlDialog callback invoke/destructor into exact by-memory pages; final template declaration/source shape remains below final-source gate.
- [UID:0001WR][ProtectedArrayTemplates](by-type/by-template/ProtectedArrayTemplates.md) : reconstructable : 78% : strong : ProtectedArray template behavior verified by IDA ordinary destructors, accessors, scalar deleting destructors, GameServerConfig constructor bytes, and nation-entry resize helper; final declaration spelling remains open.
- [UID:0001WS][StringBaseTemplate](by-type/by-template/StringBaseTemplate.md) : reconstructable : 82% : strong : - IDA-rechecked pointer-backed `mystr::StringBase` allocation, formatting, comparison, and refcount/length/capacity header evidence; final API/source split remains open.

## Covered Items To Ignore

- [UID:0001WO][CandidateStringDequeTemplate](by-type/by-template/CandidateStringDequeTemplate.md) : ignored : 78% : strong : Standard-library `std::deque<std::wstring>` helper materialization used by IME/InputMan; source semantics should be ordinary container use, not a NexusTK-owned template body.

## Uncovered Items

- by-type/by-template inventory baseline : uncovered : 0% : open : Full authoritative inventory for by-type/by-template is not yet proven complete; compare this report against Wave3 when OPERATIONAL, simroot_v2, and IDA/MCP evidence.
