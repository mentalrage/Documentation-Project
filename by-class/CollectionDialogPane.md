*** UID:00002V | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000IB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# CollectionDialogPane

## Status

- Likely source file: [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md)
- Address range: [UID:00010X][0x0048c640-0x0048e305.CollectionDialogControls](by-memory/0x0048c640-0x0048e305.CollectionDialogControls.md)
- Recovered class file name: `class_CollectionDialogPane.cpp`
- Confidence: strong.

## Class Purpose

`CollectionDialogPane` displays one collection group's detail view. It builds a fixed 668x468 dialog, adds next/previous/OK buttons, shows a collection name image, creates a progress bar control, creates six entry controls, pages through entries, and clears [UID:0000QL][g_pCollectionDialogPane](by-global/g_pCollectionDialogPane.md) on destruction.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `CollectionDialogPane` | `0x0048c640-0x0048cf74` | Constructs local or network-backed dialog, populates bit flags, and builds child controls. |
| `OnButtonClick` | `0x0048cfb0-0x0048d17d` | Handles previous, close, and next actions. |
| no-op virtual | `0x0048d180-0x0048d182` | Disabled no-op. |
| `FindCategoryIndex` | `0x0048d190-0x0048d1cd` | Finds the selected category in the collection player-data block. |
| page-advance block | `0x0048d1d0-0x0048d2c6` | Advances six-entry page and updates button state; live IDA currently disassembles this as a code block with a prologue but reports no direct xrefs. |
| page-back block | `0x0048d2d0-0x0048d39e` | Moves back one page and updates button state; live IDA currently disassembles this as a code block with a prologue but reports no direct xrefs. |
| clear singleton helper | `0x0048e140-0x0048e14b` | [UID:00010Z][0x0048e140-0x0048e14b.ClearCollectionDialogPaneSingleton](by-memory/0x0048e140-0x0048e14b.ClearCollectionDialogPaneSingleton.md) that clears `g_pCollectionDialogPane`. |
| destructor adjustors | `0x0048e161-0x0048e176` | Compiler-generated vtable adjustors. |
| `ScalarDeletingDestructor` | `0x0048e250-0x0048e2ae` | Resets vtables, tears down the base, clears singleton, and optionally deletes. |

## Data And Globals

- Owns [UID:0000QL][g_pCollectionDialogPane](by-global/g_pCollectionDialogPane.md) as the active singleton.
- Reads [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) and collection-record fields used by the constructor, selected-category search, and page navigation.
- Uses `g_screenWidth`, `g_screenHeight`, `g_pTopMostPane`, and `g_dialogLayoutSentinel` for modeless dialog placement/showing.

## Cross-References

- [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md)
- [UID:00002W][CollectionEntryControlPane](by-class/CollectionEntryControlPane.md)
- [UID:00002U][CollectionBarControlPane](by-class/CollectionBarControlPane.md)
- [UID:00002X][CollectionPane](by-class/CollectionPane.md)
- [UID:00010Z][0x0048e140-0x0048e14b.ClearCollectionDialogPaneSingleton](by-memory/0x0048e140-0x0048e14b.ClearCollectionDialogPaneSingleton.md)

## Changes

- What existed before: the page documented collection detail dialog construction, navigation, singleton handling, globals, and child controls, but metadata was still `0/0`.
- What it was changed to: scores were set to `82/88`.
- Summary and evidence: constructor, button handling, page navigation, singleton clear/destructor, child controls, and placement globals are covered; detailed field names and final source declaration remain below exhaustive.
- 2026-06-05: Marked reconstructable and attached to [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md).
  - Before: `RECONSTRUCTABLE` and `AUTOGEN_PARENT_UID` were blank, leaving the class coverage row unclassified.
  - After: `RECONSTRUCTABLE:TRUE` and `AUTOGEN_PARENT_UID:0000IB`.
  - Evidence: live IDA MCP confirms modeled method starts at `0x0048c640`, `0x0048cfb0`, `0x0048d190`, and `0x0048e250`, with callers from `0x00508cf6`, `0x00514529`, and `0x0056fd40`; this class and the parent file both meet the 80% completion/confidence attachment gate.
- 2026-06-05: Removed stale recovered-path and alias provenance wording; refined the page-advance/page-back entries to reflect the live IDA state where those address ranges disassemble as standalone prologue-bearing code blocks but are not current function-table entries and have no direct xrefs.
