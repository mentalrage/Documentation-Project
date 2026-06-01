*** UID:00006Y | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:62 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ItemWhoInputPaneState

## Status

- Confidence: strong for helper behavior; medium for final owner source file.
- Likely source file: [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md) or [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md).
- Address range: [UID:0001IJ][0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag](by-memory/0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag.md)
- Current recovered file: `source-3/simroot_v2/class_ItemWhoInputPaneState.cpp`

## Class Purpose

`ItemWhoInputPaneState` is currently represented by one small helper that writes an input-mode byte at offset `+0xfa`. It is used by item target-input flows and by nearby shared spell/item target state paths.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SetInputModeFlag` | `0x0057d0a0-0x0057d0af` | Stores the passed byte to `this + 0xfa`. |

## Evidence Notes

- IDA confirms `0x0057d0a0` as a real 0x10-byte function.
- `simroot_v2` emits only this helper in `class_ItemWhoInputPaneState.cpp`.
- IDA xrefs include item target-input methods, spell input methods, and destructor/helper paths, so this should not be treated as a one-class source file in final layout.

## Cross-References

- [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md)
- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- [UID:0001IJ][0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag](by-memory/0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag.md)
- [UID:0000DX][SpellWhoInputPane](by-class/SpellWhoInputPane.md)
- [UID:0000DM][SpellInputPaneState](by-class/SpellInputPaneState.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `62/76`. Summary: the one known helper, input-mode flag offset, cross-flow xrefs, and likely owner modules are documented, but the page is intentionally incomplete as a standalone class because final ownership belongs with broader spell/item target-state paths. Evidence: `ItemWhoInputPaneStateSetFlag`, TargetSelectionInputPanes, ItemActionInputPanes, SpellWhoInputPane, and SpellInputPaneState.
