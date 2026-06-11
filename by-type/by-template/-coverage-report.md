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

- [UID:0001WN][AUTOBUF_unsigned_char](by-type/by-template/AUTOBUF_unsigned_char.md) : reconstructable : 78% : strong : IDA-verified concrete `_AUTOBUF<unsigned char>` constructor, resize helper, tight vtable data, MapPane/UserLookPane caller evidence, class/file ownership linkage, and 21-reference cross-feature fan-out; exact original template spelling/header placement remains open.
- [UID:0001WP][FolderTreePaneTreeTemplates](by-type/by-template/FolderTreePaneTreeTemplates.md) : reconstructable : 85% : strong : A005 Batch 110 assigned this concrete `Tree`/`TreeStorage`/`TreeItor` support to [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) after child `85/89` and direct parent `89/85` cleared the corrected gate; live IDA reconfirmed helper starts, `Tree`/`TreeItor` vtable refs, three `FolderTreePane` vtable views, and the remaining open template-header/sort-helper caveats.
- [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md) : reconstructable : 82% : strong : IDA rechecked representative callback wrappers/destructors, exact MusicControlDialog callback invoke/destructor pages, and exact UserPane callback constructor/invoke pages; final template declaration/source shape remains below final-source gate.
- [UID:0001WR][ProtectedArrayTemplates](by-type/by-template/ProtectedArrayTemplates.md) : reconstructable : 82% : strong : ProtectedArray template behavior verified by IDA ordinary destructors, three accessors including the 0x004e5f70 0x0c-stride image-info accessor, scalar deleting destructors, GameServerConfig constructor bytes, and nation-entry resize helper; final declaration spelling remains open.
- [UID:0001WS][StringBaseTemplate](by-type/by-template/StringBaseTemplate.md) : reconstructable : 86% : strong : Attached to [UID:0000OA][StringBase](by-file/StringBase.md) after Batch135 raised the direct parent to `88/86`; IDA-rechecked pointer-backed `mystr::StringBase` allocation, formatting, comparison, preserved vtable/RTTI name evidence, and refcount/length/capacity header behavior documented while final API/header spelling remains open.

## Covered Items To Ignore

- [UID:0001WO][CandidateStringDequeTemplate](by-type/by-template/CandidateStringDequeTemplate.md) : ignored : 78% : strong : Standard-library `std::deque<std::wstring>` helper materialization used by IME/InputMan; source semantics should be ordinary container use, not a NexusTK-owned template body.

## Uncovered Items

- by-type/by-template inventory baseline : uncovered : 0% : open : Full authoritative inventory for by-type/by-template is not yet proven complete; compare this report against Wave3 when OPERATIONAL, simroot_v2, and IDA/MCP evidence.
