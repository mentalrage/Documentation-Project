*** UID:000010 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// UID000010 BoardListPane class-level source is covered by UID0000HT BoardDialogs and UID0002V9 BoardListPaneCore. This page emits no standalone partial class declaration until BoardListEntry/ListPane/GrafPort declarations are synchronized; UID0002V9 remains an aggregate marker because it mixes retained no-direct-route raw helpers with vtable-dispatched virtual methods.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# BoardListPane

## Status

- Disposition: reconstructable NexusTK project list-pane class.
- Confidence: strong for vtable identity, row activation/draw behavior, board-dialog module placement, and current no-route evidence for the retained raw helpers; medium-high for inferred method/field names and final row/control declarations.
- Parent source bucket: [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- Core memory: [UID:0002V9][0x004729e0-0x00472bf5.BoardListPaneCore](by-memory/0x004729e0-0x00472bf5.BoardListPaneCore.md)
- Address range parent: [UID:0000ZK][0x00472070-0x00477790.BoardArticleDialogs](by-memory/0x00472070-0x00477790.BoardArticleDialogs.md)
- Vtable family: [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md)
- Autogen status: attached to the `BoardDialogs` file bucket; formal output is marker-only because the exact core child should be split into method pages before C++ and the class declaration dependencies are not synchronized.

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
| retained `BoardListPane::BoardListPane` / `InitializeListPane` setup body | `0x004729e0-0x00472a27` | Calls the shared list/control setup helper and stores the three `BoardListPane` vtables; IDA does not model this start as a function, and current xref/pointer/listing checks find no direct route. |
| retained `BoardListPane::AppendBoardItem` | `0x00472a30-0x00472a88` | Builds a `BoardListEntry` with `boardId` at row `+0x00` and UTF-16 display text at row `+0x02`, then forwards it to shared list text/add helper `0x004f3c50`; no direct route is currently found. |
| retained `BoardListPane::SendSelectedBoardRequestNoRoute` | `0x00472a90-0x00472b45` | Serializes opcode `0x3b`, subcommand `0x02`, selected board id, sentinel `0x7fff`, and EPF/legacy mode from inherited selection state at `this + 0x134`; no direct route is currently found, and observed activation uses `BoardListDialog::OpenSelectedBoard`. |
| `BoardListPane::OnItemDoubleClick` | `0x00472b50-0x00472b63` | Vtable slot `0x00613d64`; climbs owner/container links and tail-jumps to `BoardListDialog::OpenSelectedBoard` at `0x004728a0`. |
| `BoardListPane::DrawItem` | `0x00472b70-0x00472bf5` | Vtable slot `0x00613d68`; draws one board-list row with selected/highlight state, marker/icon output, inherited draw/blit-mode byte `this + 0x70`, and centered row text from `entry + 2`. |
| shared scalar deleting destructor | [UID:0000ZR][0x0047ea50-0x0047ea8b.SharedListPaneScalarDeletingDestructor](by-memory/0x0047ea50-0x0047ea8b.SharedListPaneScalarDeletingDestructor.md) | Non-emitting shared list-pane ABI wrapper; keep source ownership on the class methods and let the compiler regenerate the wrapper. |

## Evidence Notes

- 2026-06-03 restarted IDA MCP confirms the modeled virtual boundaries at `0x00472b50-0x00472b63` and `0x00472b70-0x00472bf5`.
- The same pass confirms raw function-shaped starts at `0x004729e0`, `0x00472a30`, and `0x00472a90` are not IDA function objects and have no direct xrefs to their starts, while the raw constructor-shaped body stores all three `BoardListPane` vtable views.
- Live vtable reads place activation/double-click and draw callbacks at slots `0x00613d64` and `0x00613d68`; the primary table also uses shared list-pane scalar deleting destructor `0x0047ea50`.
- Live xrefs to table bases include inline construction stores at `0x004721d4`, `0x004721da`, and `0x004721e4`, reset/copy stores at `0x00472566`, `0x0047256c`, and `0x00472576`, and the raw helper stores at `0x00472a04`, `0x00472a0c`, and `0x00472a16`.
- Live decompilation of `0x00472b50` shows two virtual owner/container lookups through slot `+0x1c`, followed by a tail jump to [UID:0002EJ][0x00472070-0x004729dd.BoardListDialogCore](by-memory/0x00472070-0x004729dd.BoardListDialogCore.md)'s selected-board opener.
- Live decompilation of `0x00472b70` shows selection/highlight testing, draw helper calls, transient draw-state byte `this + 0x70`, row midpoint calculation, and text drawing from the row payload at `a3 + 2`.
- 2026-06-10 B001-025 recheck confirms [UID:0002V9][0x004729e0-0x00472bf5.BoardListPaneCore](by-memory/0x004729e0-0x00472bf5.BoardListPaneCore.md) is now `85/88`, this class is the direct owner, and the shared [UID:0000ZR][0x0047ea50-0x0047ea8b.SharedListPaneScalarDeletingDestructor](by-memory/0x0047ea50-0x0047ea8b.SharedListPaneScalarDeletingDestructor.md) remains non-emitting ABI glue rather than a handwritten source child.
- 2026-07-02 B002 MCP session `supervisor_resume_20260629` changes the raw-helper caveat from open reachability to documented no-direct-route evidence: no IDA function objects, xrefs, pointer-byte hits, or bounded listing routes are found for `0x004729e0`, `0x00472a30`, or `0x00472a90`.
- B002 source-quality naming is descriptive/inferred: `AppendBoardItem`, `SendSelectedBoardRequestNoRoute`, `OnItemDoubleClick`, `DrawItem`, `BoardListEntry::boardId`, `BoardListEntry::text`, inherited selected index at `this + 0x134`, and inherited draw/blit-mode byte at `this + 0x70`. Stale generated aliases and dependency-owner alternatives remain rejected.

## Score Rationale

Completion is raised to `88` because the page records the exact core child, direct file parent, raw helper island, modeled virtuals, vtable stores, activation callback to `BoardListDialog`, row drawing behavior, shared destructor wrapper boundary, current no-route evidence, descriptive method/field names, and the split-first C++ disposition. Confidence is `90` because current MCP supports the class identity, callbacks, raw bytes, negative route evidence, and vtable facts; it remains below final because original method names and synchronized class/row declarations are still inferred.

## Open Questions

- The raw starts at `0x004729e0`, `0x00472a30`, and `0x00472a90` have evidence-backed no-direct-route status in current MCP. Future caller evidence would need a direct branch/call, table pointer, or source/header proof.
- Row record layout names are currently descriptive: `BoardListEntry::boardId` at `+0x00` and `BoardListEntry::text` at `+0x02`; the inherited selected-index and draw/blit-mode fields are likewise inferred from use and support docs.
- C++ reconstruction remains intentionally marker-only until exact method children or synchronized class/row/control declarations are accepted.

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
- 2026-06-10 B001-025:
  - Before: the class remained `78/88`, blocking strict assignment of its repaired child.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:88`; parent remains [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md).
  - Summary/evidence: B001 re-audit confirmed exact pane child coverage, modeled virtuals, raw helper boundaries, vtable stores, activation callback, and non-emitting shared destructor treatment. Remaining uncertainty is final row-layout/source naming, not direct ownership.
- 2026-07-02 B002 UID0002V9 accepted source-quality implementation callback:
  - Before: class score was `85/88`, and raw helper reachability/source names were still described as open.
  - Changed to: `COMPLETION:88`, `CONFIDENCE:90`; owner/emitter remain [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md).
  - Summary/evidence: current MCP session `supervisor_resume_20260629` proves no direct route/pointer hits for retained raw helpers, names the source-facing roles `AppendBoardItem`, `SendSelectedBoardRequestNoRoute`, `OnItemDoubleClick`, and `DrawItem`, records inferred row/selection/draw fields, and keeps class-level output marker-only pending exact method children or synchronized declarations.
