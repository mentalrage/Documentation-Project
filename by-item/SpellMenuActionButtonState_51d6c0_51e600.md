*** UID:0000VH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SpellMenuActionButtonState_51d6c0_51e600

## Status

- Confidence: strong for behavior and spell-menu ownership.
- Current Wave3 caveat: `ClientSpellMenuDialog::UpdateActionButtonState` uses a generated local `ChattingColorListPane*` type for the spell-list pointer.
- Proposed owner file: [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md)
- Exact memory range: [UID:0001BR][0x0051ca40-0x0051e998.SpellMenuDialogs](by-memory/0x0051ca40-0x0051e998.SpellMenuDialogs.md)
- Rebuild handling: `source-authored` spell-menu UI state helpers. Marked reconstructable, but parent attachment and C++ are blank until the child-slot ownership, list types, and button virtual names are near-final.

## Helper Summary

| Address range | Owner | Behavior |
| --- | --- | --- |
| `0x0051d6c0-0x0051d6fc` | `ServerSpellMenuDialog::UpdateActionButtonState` | Fetches control child `1` as the action button, fetches child `6` as the server spell list, counts enabled rows, and jumps to the action button enable/disable virtual. |
| `0x0051e600-0x0051e63c` | `ClientSpellMenuDialog::UpdateActionButtonState` | Same control pattern for the client spell list; generated source currently gives the list pointer a polluted `ChattingColorListPane*` local type. |

## IDA MCP Evidence

Checked on 2026-05-24:

- `lookup_funcs` confirms `0x0051d6c0` and `0x0051e600` as real functions of size `0x3d` each.
- Decompilation of both functions obtains child `1` from `this[127]` as the action button and child `6` as the list container.
- Both functions call `sub_4F3E20` on the list pointer stored at child-slot owner offset `+0x108`, then dispatch through action-button vtable offsets `+0x4c` or `+0x50`.
- The client spell-list constructor `0x0051e640` installs `ClientSpellMenuItemList` vtables and stores packet/list context at offsets `+0x14c`, `+0x150`, `+0x154`, and `+0x158`.
- The client list renderer `0x0051e890` draws row text from `entry + 4`, matching `ClientSpellMenuItemList`, not chat color-list row data.
- `xrefs_to 0x00482fb0` for the real `ChattingColorListPane` constructor reports only chat-color pane callers at `0x00482837` and `0x0048295d`, with no spell-menu constructor use.
- 2026-05-31 IDA MCP recheck reports `0x0051d6c0` and `0x0051e600` as separate 61-byte functions ending exclusively at `0x0051d6fd` and `0x0051e63d`; both call only `0x004f3e20` and then tail-dispatch through action-button virtual slots.
- 2026-05-31 IDA MCP recheck also confirms `0x0051e640` installs `ClientSpellMenuItemList` vtables and stores context fields, while `0x0051e890` draws text from `entry + 4`. `ChattingColorListPane` constructor `0x00482fb0` still has only chat-color callers at `0x00482837` and `0x0048295d`.

## Ownership Decision

The `ChattingColorListPane*` spelling in generated `ClientSpellMenuDialog.cpp` is only a local type/name pollution artifact. The source-layout owner remains `ui/dialogs/SpellMenuDialogs.cpp`, and the local type should be renamed to a neutral `SpellMenuItemList` or concrete `ClientSpellMenuItemList` wrapper before source migration.

## Cross-References

- [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md)
- [UID:00002R][ClientSpellMenuDialog](by-class/ClientSpellMenuDialog.md)
- [UID:0000D3][ServerSpellMenuDialog](by-class/ServerSpellMenuDialog.md)
- [UID:00002S][ClientSpellMenuItemList](by-class/ClientSpellMenuItemList.md)
- [UID:0000D4][ServerSpellMenuItemList](by-class/ServerSpellMenuItemList.md)
- [UID:00001S][ChattingColorListPane](by-class/ChattingColorListPane.md)

## Changes

- What existed before: the page was unevaluated (`COMPLETION:0`, `CONFIDENCE:0`) and had no reconstructable classification.
- What it was changed to: the page is now marked reconstructable with moderate completion and strong confidence, while parent attachment and C++ remain blank.
- Summary and evidence: IDA MCP verification on 2026-05-31 reconfirmed both update-helper boundaries, shared child/list-count behavior, client spell-list constructor and renderer evidence, and lack of spell-menu xrefs to the chat-color-list constructor. The score remains below 95 because final child-slot names, list type declarations, and virtual method names are not fully audited.
