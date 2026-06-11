*** UID:00002W | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000IB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# CollectionEntryControlPane

## Status

- Likely source file: [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md)
- Address range: [UID:00010X][0x0048c640-0x0048e305.CollectionDialogControls](by-memory/0x0048c640-0x0048e305.CollectionDialogControls.md), plus shared GrafPort helper calls at `0x004b95e0`, `0x004b9620`, and `0x004bab20`
- Recovered class file name: `class_CollectionEntryControlPane.cpp`
- Confidence: strong for dialog-control ownership, medium for helper placement.

## Class Purpose

`CollectionEntryControlPane` draws one item slot in the collection detail dialog. It renders locked, empty, and collected states, formats per-volume sprite filenames (`CLTVOL%d.EPF` / `CLTVOL%d.PAL`), and draws entry name, short name, index, and description from the collection player-data block.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `CollectionEntryControlPane` | `0x0048d3a0-0x0048d47a` | Constructs a control of type `8`, stores category/entry indices, enables image behavior, and formats volume asset names. |
| `~CollectionEntryControlPane` body | `0x0048d480-0x0048d49f` | [UID:00010Y][0x0048d480-0x0048d49f.CollectionEntryControlPaneDestructor](by-memory/0x0048d480-0x0048d49f.CollectionEntryControlPaneDestructor.md); restores vtables and chains to `TextButtonExControlPane`. |
| `OnDraw` | `0x0048d4a0-0x0048d991` | Draws background, lock icon, collected item sprite, and text fields. |
| `DrawWrappedText` | `0x0048d9e0-0x0048dc21` | Wraps and draws wide text inside a clip rect, honoring literal `\\n` sequences. |
| destructor adjustors | `0x0048e177-0x0048e18c` | Compiler-generated vtable adjustors. |
| `ScalarDeletingDestructor` | `0x0048e2b0-0x0048e304` | Destructor wrapper. |
| `GetDrawPosition` | `0x004b95e0-0x004b95f4` | Shared [UID:000162][0x004b95e0-0x004b969f.GrafPortDrawStateAccessors](by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md); current collection ownership is caller-biased. |
| `OffsetDrawPosition` | `0x004b9620-0x004b9632` | Shared [UID:000162][0x004b95e0-0x004b969f.GrafPortDrawStateAccessors](by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md); current collection ownership is caller-biased. |
| `DrawCharWithColors` | `0x004bab20-0x004bab6b` | Builds a small color pack and calls the shared [UID:00016I][0x004bb5e0-0x004bb7df.GrafPortDrawGlyph](by-memory/0x004bb5e0-0x004bb7df.GrafPortDrawGlyph.md). Treat current collection ownership as caller-biased. |

## Data Layout

Reads [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) at category record offsets:

- `+0x3ec9`: volume number/type for `CLTVOL` filename formatting;
- `+0x3eca`: max entry count;
- `+0x3efc`, `+0x3ee4`, `+0x3f14`, `+0x3f2c`: per-entry `std::wstring`/state fields through `0x4c`-byte records.

## Cross-References

- [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md)
- [UID:00002V][CollectionDialogPane](by-class/CollectionDialogPane.md)
- [UID:00002U][CollectionBarControlPane](by-class/CollectionBarControlPane.md)
- [UID:0001TZ][CollectionPlayerDataLayout](by-type/by-struct/CollectionPlayerDataLayout.md)
- [UID:00010Y][0x0048d480-0x0048d49f.CollectionEntryControlPaneDestructor](by-memory/0x0048d480-0x0048d49f.CollectionEntryControlPaneDestructor.md)
- [UID:000162][0x004b95e0-0x004b969f.GrafPortDrawStateAccessors](by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md)
- [UID:00016C][0x004ba9a0-0x004bad66.GrafPortTextRunHelpers](by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md)

## Changes

- What existed before: the page documented entry-slot draw states, methods, data offsets, and shared GrafPort helper caveats, but metadata still read `0/0`.
- What it was changed to: scores were set to `76/82`.
- Summary and evidence: constructor, destructor, draw/wrapped-text behavior, category record offsets, and shared helper dependencies are documented; confidence is capped by caller-biased helper ownership and unfinished field naming.
- 2026-06-05: Marked reconstructable for autogen.
  - Before: `RECONSTRUCTABLE` was blank, leaving the class coverage row unclassified.
  - After: `RECONSTRUCTABLE:TRUE`; `AUTOGEN_PARENT_UID` remains blank because the class completion score is below the 80% attachment gate.
  - Evidence: live IDA MCP confirms modeled method starts at `0x0048d3a0`, `0x0048d480`, `0x0048d4a0`, `0x0048d9e0`, and `0x0048e2b0`, with construction from `CollectionDialogPane` at `0x0048ca46` and `0x0048ce45`.
- 2026-06-05: Raised from `76/82` to `80/84` and attached to [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md).
  - Evidence: live IDA MCP confirmed constructor/destructor/draw/wrapped-text/scalar-destructor starts, constructor xrefs from the dialog at `0x0048ca46` and `0x0048ce45`, the virtual draw table reference at `0x006165d4`, scalar-destructor thunk/table references, and nine draw-call sites into the wrapped-text helper.
  - Remaining limits: shared GrafPort helper ownership and final member-field names are still not exhaustive, so this page only reaches the attachment gate rather than final-source readiness.
