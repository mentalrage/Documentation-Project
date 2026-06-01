*** UID:00002U | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# CollectionBarControlPane

## Status

- Likely source file: [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md)
- Address range: [UID:00010X][0x0048c640-0x0048e305.CollectionDialogControls](by-memory/0x0048c640-0x0048e305.CollectionDialogControls.md)
- Current recovered file: `source-3/simroot_v2/class_CollectionBarControlPane.cpp`
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
