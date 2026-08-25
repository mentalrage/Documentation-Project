*** UID:0000VH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000O2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# SpellMenuActionButtonState_51d6c0_51e600

## Status

- Disposition: reviewed non-emitting support index for the two spell-menu action-button update helpers.
- Source owner: [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md).
- Exact emitted method owners: [UID:0004Y4][0x0051ca40-0x0051d6fd.ServerSpellMenuDialogMethods](by-memory/0x0051ca40-0x0051d6fd.ServerSpellMenuDialogMethods.md) and [UID:0004Y6][0x0051db40-0x0051e63d.ClientSpellMenuDialogMethods](by-memory/0x0051db40-0x0051e63d.ClientSpellMenuDialogMethods.md).
- Broad split index: [UID:0001BR][0x0051ca40-0x0051e998.SpellMenuDialogs](by-memory/0x0051ca40-0x0051e998.SpellMenuDialogs.md).
- Rebuild handling: this item is `RECONSTRUCTABLE:FALSE` because it is now an evidence/index page; exact dialog method children own emitted source and formal C++.

## Helper Summary

| Address range | Exact owner | Behavior |
| --- | --- | --- |
| `0x0051d6c0-0x0051d6fd` | [UID:0004Y4][0x0051ca40-0x0051d6fd.ServerSpellMenuDialogMethods](by-memory/0x0051ca40-0x0051d6fd.ServerSpellMenuDialogMethods.md) | Fetches child slot `1` as the action button, fetches child slot `6` as the server spell list, counts selected/enabled list entries, and dispatches the action-button enable/disable virtual. |
| `0x0051e600-0x0051e63d` | [UID:0004Y6][0x0051db40-0x0051e63d.ClientSpellMenuDialogMethods](by-memory/0x0051db40-0x0051e63d.ClientSpellMenuDialogMethods.md) | Same control pattern for the client spell list; live list constructor, vtable, and renderer evidence identifies child slot `6` as `ClientSpellMenuItemList`, not chat UI. |

## Current MCP Evidence

B001 report `0001BR-SpellMenuDialogs-source-quality.md` refreshed this item with MCP session `80de0a67`:

- `lookup_funcs` reports both helpers as exact `0x3d`-byte functions.
- `xrefs_to` reports the server helper as a vtable/data-only slot at `0x0061f1b4` and the client helper as a vtable/data-only slot at `0x0061f314`.
- Both helpers fetch child slot `1` for the action button and child slot `6` for the spell list from the inherited control manager.
- Both helpers read list storage at `+0x108` and call [UID:0003U0][0x004f3bb0-0x004f3f20.ListPaneItemSelectionStorageHelpers](by-memory/0x004f3bb0-0x004f3f20.ListPaneItemSelectionStorageHelpers.md) helper `0x004f3e20`.
- `xrefs_to 0x004f3e20` reports 14 callers across list-based UI update helpers, including spell-menu calls at `0x0051d6e8` and `0x0051e628`; this is shared `ListPane` behavior, not spell-owned helper logic.
- Positive selection count dispatches action-button virtual slot `+0x4c`; zero dispatches virtual slot `+0x50`.
- The client spell list constructor `0x0051e640` has constructor refs from `ClientSpellMenuDialog` and installs `ClientSpellMenuItemList` vtables; the client renderer `0x0051e890` reads text from row `+4`.

## ChattingColorListPane Rejection

The generated `ChattingColorListPane*` local type in the client helper is type/name pollution:

- The real `ChattingColorListPane` constructor at `0x00482fb0` has only chat-color callers `0x00482837` and `0x0048295d`.
- There are no spell-menu constructor or updater refs to `0x00482fb0`.
- `ClientSpellMenuItemList` construction and drawing remain inside [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md) and are linked from [UID:0004Y6][0x0051db40-0x0051e63d.ClientSpellMenuDialogMethods](by-memory/0x0051db40-0x0051e63d.ClientSpellMenuDialogMethods.md) / [UID:0004Y7][0x0051e640-0x0051e998.ClientSpellMenuItemList](by-memory/0x0051e640-0x0051e998.ClientSpellMenuItemList.md).

## Ownership Decision

The action-button update code belongs to the server/client dialog classes, not to this support item. This page remains useful to show the shared pattern and the rejected chat-local-type evidence, but it must not emit duplicate C++ now that [UID:0004Y4][0x0051ca40-0x0051d6fd.ServerSpellMenuDialogMethods](by-memory/0x0051ca40-0x0051d6fd.ServerSpellMenuDialogMethods.md) and [UID:0004Y6][0x0051db40-0x0051e63d.ClientSpellMenuDialogMethods](by-memory/0x0051db40-0x0051e63d.ClientSpellMenuDialogMethods.md) carry the formal method source.

## Cross-References

- [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md)
- [UID:0004Y4][0x0051ca40-0x0051d6fd.ServerSpellMenuDialogMethods](by-memory/0x0051ca40-0x0051d6fd.ServerSpellMenuDialogMethods.md)
- [UID:0004Y6][0x0051db40-0x0051e63d.ClientSpellMenuDialogMethods](by-memory/0x0051db40-0x0051e63d.ClientSpellMenuDialogMethods.md)
- [UID:0000D3][ServerSpellMenuDialog](by-class/ServerSpellMenuDialog.md)
- [UID:00002R][ClientSpellMenuDialog](by-class/ClientSpellMenuDialog.md)
- [UID:0000D4][ServerSpellMenuItemList](by-class/ServerSpellMenuItemList.md)
- [UID:00002S][ClientSpellMenuItemList](by-class/ClientSpellMenuItemList.md)
- [UID:00001S][ChattingColorListPane](by-class/ChattingColorListPane.md)
- [UID:0003U0][0x004f3bb0-0x004f3f20.ListPaneItemSelectionStorageHelpers](by-memory/0x004f3bb0-0x004f3f20.ListPaneItemSelectionStorageHelpers.md)

## Changes

- 2026-06-23 B001 accepted implementation:
  - Changed metadata from `86/91`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O2` to `88/92`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`.
  - Reclassified this item as a non-emitting support index because [UID:0004Y4][0x0051ca40-0x0051d6fd.ServerSpellMenuDialogMethods](by-memory/0x0051ca40-0x0051d6fd.ServerSpellMenuDialogMethods.md) and [UID:0004Y6][0x0051db40-0x0051e63d.ClientSpellMenuDialogMethods](by-memory/0x0051db40-0x0051e63d.ClientSpellMenuDialogMethods.md) own the emitted source.
  - Preserved child-slot, `+0x108`, shared `0x004f3e20`, vtable-only ref, action-button virtual, and ChattingColorListPane pollution evidence at support-page detail.

