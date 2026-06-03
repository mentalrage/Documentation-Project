*** UID:000010 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:30 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# BoardListPane

## Status

- Disposition: reconstructable NexusTK project list-pane class.
- Confidence: strong for vtable identity, row activation/draw behavior, and board-dialog module placement; medium for final row record layout and raw helper reachability.
- Parent source bucket: [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- Core memory: [UID:0002V9][0x004729e0-0x00472bf5.BoardListPaneCore](by-memory/0x004729e0-0x00472bf5.BoardListPaneCore.md)
- Address range parent: [UID:0000ZK][0x00472070-0x00477790.BoardArticleDialogs](by-memory/0x00472070-0x00477790.BoardArticleDialogs.md)
- Vtable family: [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md)
- Autogen status: attached to the `BoardDialogs` file bucket; reconstruction C++ remains blank because field names, row layout, and raw helper names are not final.

## Class Purpose

`BoardListPane` is the list-pane component used by `BoardListDialog`. It renders available board rows and forwards double-click activation into the owning board dialog/session flow.

## Class Shape

- Base family: board/article list pane in the same multi-view vtable layout used by the dialog family.
- Vtable identity: constructor-shaped code stores primary `0x00613ce8`, secondary `0x00613d70`, and tertiary `0x00613da0` table views.
- Owner relationship: built by [UID:00000Z][BoardListDialog](by-class/BoardListDialog.md) and calls back into the dialog's selected-board opener on activation.
- Source placement: [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md), with the exact pane island split into [UID:0002V9][0x004729e0-0x00472bf5.BoardListPaneCore](by-memory/0x004729e0-0x00472bf5.BoardListPaneCore.md).

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| raw constructor-shaped helper | `0x004729e0-0x00472a27` | Calls the shared list/control setup helper and stores the three `BoardListPane` vtables; IDA does not model this start as a function. |
| raw row text helper | `0x00472a30-0x00472a88` | Stages bounded wide row text and forwards it to shared list text helper `0x004f3c50`; direct reachability remains open. |
| raw selected-board packet helper | `0x00472a90-0x00472b45` | Serializes a board-selection packet from pane selection state; direct reachability remains open. |
| `OnItemDoubleClick` / activation virtual | `0x00472b50-0x00472b63` | Vtable slot `0x00613d64`; climbs owner/container links and tail-jumps to `BoardListDialog::OpenSelectedBoard` at `0x004728a0`. |
| `DrawItem` | `0x00472b70-0x00472bf5` | Vtable slot `0x00613d68`; draws one board-list row with selected/highlight state, marker/icon output, and centered row text. |

## Evidence Notes

- 2026-06-03 restarted IDA MCP confirms the modeled virtual boundaries at `0x00472b50-0x00472b63` and `0x00472b70-0x00472bf5`.
- The same pass confirms raw function-shaped starts at `0x004729e0`, `0x00472a30`, and `0x00472a90` are not IDA function objects and have no direct xrefs to their starts, while the raw constructor-shaped body stores all three `BoardListPane` vtable views.
- Live vtable reads place activation/double-click and draw callbacks at slots `0x00613d64` and `0x00613d68`; the primary table also uses shared list-pane scalar deleting destructor `0x0047ea50`.
- Live xrefs to table bases include inline construction stores at `0x004721d4`, `0x004721da`, and `0x004721e4`, reset/copy stores at `0x00472566`, `0x0047256c`, and `0x00472576`, and the raw helper stores at `0x00472a04`, `0x00472a0c`, and `0x00472a16`.
- Live decompilation of `0x00472b50` shows two virtual owner/container lookups through slot `+0x1c`, followed by a tail jump to [UID:0002EJ][0x00472070-0x004729dd.BoardListDialogCore](by-memory/0x00472070-0x004729dd.BoardListDialogCore.md)'s selected-board opener.
- Live decompilation of `0x00472b70` shows selection/highlight testing, draw helper calls, transient draw-state byte `this + 0x70`, row midpoint calculation, and text drawing from the row payload at `a3 + 2`.

## Open Questions

- The raw starts at `0x00472a30` and `0x00472a90` need stronger caller evidence before final method names are chosen.
- Row record layout and the meaning of draw-state byte `this + 0x70` remain provisional.
- C++ reconstruction remains intentionally blank until the class declaration, raw helper reachability, and row-field names clear the reconstruction gate.

## Cross-References

- [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- [UID:0002V9][0x004729e0-0x00472bf5.BoardListPaneCore](by-memory/0x004729e0-0x00472bf5.BoardListPaneCore.md)
- [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md)
- [UID:0000ZK][0x00472070-0x00477790.BoardArticleDialogs](by-memory/0x00472070-0x00477790.BoardArticleDialogs.md)
- [UID:00000Z][BoardListDialog](by-class/BoardListDialog.md)
- [UID:0002EJ][0x00472070-0x004729dd.BoardListDialogCore](by-memory/0x00472070-0x004729dd.BoardListDialogCore.md)
- [UID:0000ZR][0x0047ea50-0x0047ea8b.SharedListPaneScalarDeletingDestructor](by-memory/0x0047ea50-0x0047ea8b.SharedListPaneScalarDeletingDestructor.md)

## Changes

- What existed before: the page identified the pane role, two compact methods, and board-dialog ownership, but metadata still read `0/0`.
- What it was changed to: scores were set to `70/84`.
- Summary and evidence: the compact method set and BoardDialogs references support high confidence for identity and placement; remaining completion work is mostly final layout/header detail and confirming there is no broader reusable list-pane owner.
- 2026-06-03:
  - Before: class remained `70/84`, reconstructable/autogen-parent metadata was blank, and the page only documented the two modeled virtual callbacks.
  - After: scored as `78/88`, marked reconstructable, and attached under [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md).
  - Summary/evidence: exact child [UID:0002V9][0x004729e0-0x00472bf5.BoardListPaneCore](by-memory/0x004729e0-0x00472bf5.BoardListPaneCore.md) now documents the raw constructor/text/packet helper island, modeled activation/draw virtuals, vtable slots, inline constructor stores, and internal padding. Completion remains below reconstruction level because raw helper reachability, row layout, and source names remain unresolved.
