*** UID:00002U | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000IB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# CollectionBarControlPane

## Status

- Likely source file: [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md)
- Address range: [UID:00010X][0x0048c640-0x0048e305.CollectionDialogControls](by-memory/0x0048c640-0x0048e305.CollectionDialogControls.md)
- Recovered class file name: `class_CollectionBarControlPane.cpp`
- Confidence: strong.

## Class Purpose

`CollectionBarControlPane` draws the selected collection group's progress bar. It reads total/current counts from the collection data block, renders `CLTBAR` left/fill/right sprites, and draws the `current/total(percent)` label with a small bitmap font table.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `CollectionBarControlPane` | `0x0048dc30-0x0048dcdf` | Constructs control type `8`, loads `9X11FONT.BIN`, and copies total/current counts. |
| `~CollectionBarControlPane` | `0x0048dce0-0x0048dd52` | Frees the glyph table and chains to the text-button base. |
| `OnPaint` | `0x0048dd60-0x0048dfeb` | Draws bar fill and centered label. |
| `DrawProgressLabel` | `0x0048dff0-0x0048e132` | Draws digits/symbols using the loaded glyph table and `FONTSYMB` sprites. |
| destructor adjustors | `0x0048e14b-0x0048e160` | Compiler-generated vtable adjustors. |
| `ScalarDeletingDestructor` | `0x0048e190-0x0048e243` | Destructor wrapper. |

## Data And Globals

- Reads [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md), emitted here as `g_collectionProgressTable`.
- Uses `g_uiSpriteManager`/EPF frame helpers for `CLTBAR` and `FONTSYMB` resources.

## Cross-References

- [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md)
- [UID:00002V][CollectionDialogPane](by-class/CollectionDialogPane.md)
- [UID:00002W][CollectionEntryControlPane](by-class/CollectionEntryControlPane.md)
- [UID:0001R8][collection-ui-resources](by-resource/collection-ui-resources.md)

## Changes

- What existed before: the page documented collection progress-bar behavior, methods, resource usage, and globals, but metadata was still `0/0`.
- What it was changed to: scores were set to `78/86`.
- Summary and evidence: constructor, destructor, paint, label drawing, collection data reads, and sprite/font dependencies are documented; exact member names and final class declaration remain incomplete.
- 2026-06-05: Marked reconstructable for autogen.
  - Before: `RECONSTRUCTABLE` was blank, leaving the class coverage row unclassified.
  - After: `RECONSTRUCTABLE:TRUE`; `AUTOGEN_PARENT_UID` remains blank because the class completion score is below the 80% attachment gate.
  - Evidence: live IDA MCP confirms modeled method starts at `0x0048dc30`, `0x0048dce0`, `0x0048dd60`, `0x0048dff0`, and `0x0048e190`, with construction from `CollectionDialogPane` at `0x0048c98a` and `0x0048cd8a`.
- 2026-06-05: Raised from `78/86` to `82/86` and attached to [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md).
  - Evidence: live IDA MCP confirmed constructor/destructor/paint/label/scalar-destructor starts, constructor xrefs from the dialog at `0x0048c98a` and `0x0048cd8a`, the virtual paint table reference at `0x00616678`, scalar-destructor thunk/table references, and the paint path's progress-fill and label-draw dependencies.
  - Remaining limits: exact class declaration and member names are still pending, so final C++ remains blank.
