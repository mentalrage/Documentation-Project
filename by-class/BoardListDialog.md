*** UID:00000Z | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# BoardListDialog

## Status

- Disposition: reconstructable NexusTK project dialog class.
- Confidence: strong for behavior, vtable identity, and board-dialog module placement; medium for final field names and source-quality class declaration.
- Parent source bucket: [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- Core memory: [UID:0002EJ][0x00472070-0x004729dd.BoardListDialogCore](by-memory/0x00472070-0x004729dd.BoardListDialogCore.md)
- Address range parent: [UID:0000ZK][0x00472070-0x00477790.BoardArticleDialogs](by-memory/0x00472070-0x00477790.BoardArticleDialogs.md)
- Vtable family: [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md)
- Autogen status: attached to the `BoardDialogs` file bucket; reconstruction C++ remains blank because field names and class declaration details are not final.

## Class Purpose

`BoardListDialog` presents selectable bulletin-board categories parsed from server packet data. It creates the board-list controls, tracks the selected board, sends the board-selection request, and updates button state when selection changes.

## Class Shape

- Base family: board/article `BulletinDialog` descendant in the `DialogInSession` stack.
- Vtable identity: constructor stores the three `BoardListDialog` table views at object offsets `0x0`, `0xa0`, and `0xa4`.
- Owned controls: builds the board-list pane and command controls; the sibling [UID:000010][BoardListPane](by-class/BoardListPane.md) double-click path calls back into the selected-board opener.
- Network role: serializes the selected board request through the bulletin packet/session globals after reading the selected row state.
- Source placement: [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md), with the exact core method band split into [UID:0002EJ][0x00472070-0x004729dd.BoardListDialogCore](by-memory/0x00472070-0x004729dd.BoardListDialogCore.md).

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `BoardListDialog` | `0x00472070-0x00472869` | Parses board-list packet data, installs three class vtables, creates the board-list pane, and builds command controls. |
| `OnCommand` | `0x00472870-0x00472898` | Vtable slot `0x00613c90`; dispatches command `1` to the selected-board opener and command `2` to the dialog-stack close helper. |
| `OpenSelectedBoard` | `0x004728a0-0x00472999` | Reads the selected row from control `3`, serializes the selected-board packet, updates session/dialog state, and is also reached from the pane double-click callback. |
| `UpdateButtonState` | `0x004729a0-0x004729dd` | Vtable slot `0x00613c94`; enables/disables the open button based on current selection state. |
| title-copy helper | `0x0049db30-0x0049db5d` | Small helper called from the constructor at `0x0047217b` and `0x0047250d`; keep outside the exact core child range until final file layout is settled. |

## Evidence Notes

- 2026-06-03 restarted IDA MCP confirms function boundaries `0x00472070-0x00472869`, `0x00472870-0x00472898`, `0x004728a0-0x00472999`, `0x004729a0-0x004729dd`, and title helper `0x0049db30-0x0049db5d`.
- The same IDA pass confirms `0xcc` alignment gaps at `0x00472869-0x00472870`, `0x00472898-0x004728a0`, `0x00472999-0x004729a0`, and `0x004729dd-0x004729e0`; IDA has no function at `0x004729dd` or `0x004729e0`.
- Vtable evidence is direct: constructor xrefs store `0x00613c48`, `0x00613cac`, and `0x00613cdc` at `0x004720cd`, `0x004720d3`, and `0x004720dd`; vtable dwords `0x00613c90` and `0x00613c94` target `0x00472870` and `0x004729a0`.
- Live xrefs show the constructor reached from bulletin-session code at `0x00471604` and `0x00471921`, and `OpenSelectedBoard` reached both from `OnCommand` at `0x0047288f` and from the board-list pane callback at `0x00472b5e`.
- Callee evidence anchors behavior: the constructor calls `0x004a1400`, `0x0049db30`, list/control helpers, and board-list pane/control constructors; `OpenSelectedBoard` calls selected-row extraction `0x004f3dc0`, packet writers `0x00575380`/`0x005753a0`/`0x00574bb0`, and session/dialog update helper `0x004a12b0`.
- The class should stay in the board/article dialog family rather than generic list-pane or packet code because vtables, constructor callers, owned pane activation, and source bucket all point to `BoardDialogs`.

## Open Questions

- Final field names for the control container, session/dialog pointers, selected-board state, and packet context are not source-quality yet.
- The original source split between a compact `BoardDialogs.cpp`, a separate article-dialog source, and shared alert files is still under review at the file-parent level.
- C++ reconstruction remains intentionally blank until the class declaration and field layout clear the reconstruction gate.

## Cross-References

- [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- [UID:0002EJ][0x00472070-0x004729dd.BoardListDialogCore](by-memory/0x00472070-0x004729dd.BoardListDialogCore.md)
- [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md)
- [UID:0000ZK][0x00472070-0x00477790.BoardArticleDialogs](by-memory/0x00472070-0x00477790.BoardArticleDialogs.md)
- [UID:000010][BoardListPane](by-class/BoardListPane.md)
- [UID:00000K][ArticleListDialog](by-class/ArticleListDialog.md)
- [UID:00001C][BulletinDialog](by-class/BulletinDialog.md)
- [UID:00003S][DialogInSession](by-class/DialogInSession.md)

## Changes

- What existed before: the page documented purpose, methods, placement, and references, but completion/confidence metadata was still `0/0`.
- What it was changed to: scores were set to `70/84`.
- Summary and evidence: the page has strong BoardDialogs placement, method boundaries, and by-memory references, but it is not 100% complete because class layout, final C++ declaration, and exact field names are not fully recovered here.
- 2026-06-03:
  - Before: class remained at `70/84`, had no autogen parent/reconstructable marker, and lacked a fresh IDA evidence map.
  - After: scored as `78/88`, marked reconstructable, and attached to [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md).
  - Summary/evidence: restarted IDA MCP confirms exact function boundaries, padding, three class vtable stores, virtual slots `0x00613c90`/`0x00613c94`, title-helper xrefs, constructor callers, and the board-list pane activation call into `OpenSelectedBoard`; C++ remains blank pending final field names and class-layout recovery.
