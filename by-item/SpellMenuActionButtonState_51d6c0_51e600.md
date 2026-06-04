*** UID:0000VH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000O2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SpellMenuActionButtonState_51d6c0_51e600

## Status

- Confidence: strong for exact helper boundaries, child-slot behavior, spell-list ownership, vtable refs, and chat-list exclusion.
- Current IDA caveat: the client helper's stale `ChattingColorListPane*` local type label should not override the list constructor, vtable, and renderer evidence.
- Proposed owner file: [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md)
- Exact memory range: [UID:0001BR][0x0051ca40-0x0051e998.SpellMenuDialogs](by-memory/0x0051ca40-0x0051e998.SpellMenuDialogs.md)
- Rebuild handling: source-authored spell-menu UI state helpers. Parent-attached to the spell-menu dialog file, but C++ remains blank until child-slot names, list declarations, and button virtual names reach the 95/95 bar.

## Helper Summary

| Address range | Owner | Behavior |
| --- | --- | --- |
| `0x0051d6c0-0x0051d6fd` | `ServerSpellMenuDialog::UpdateActionButtonState` | Fetches control child `1` as the action button, fetches child `6` as the server spell list, counts enabled rows, and jumps to the action button enable/disable virtual. |
| `0x0051e600-0x0051e63d` | `ClientSpellMenuDialog::UpdateActionButtonState` | Same control pattern for the client spell list; live list-constructor and renderer evidence identifies the child as `ClientSpellMenuItemList`, not chat UI. |

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

Rechecked on 2026-06-04:

- Live IDA reports `0x0051d6c0-0x0051d6fd` and `0x0051e600-0x0051e63d` as two exact 0x3d-byte function ranges with vtable data refs at `0x0061f1b4` and `0x0061f314`.
- Both helpers fetch child slot `1` from `this[127]` for the action button and child slot `6` for the spell list, call `sub_4F3E20` on the list object's `+0x108` list storage, then tail-dispatch through the action-button virtuals at `+0x4c` or `+0x50`.
- Live IDA reports `0x0051e640-0x0051e6ac` as the `ClientSpellMenuItemList` constructor; it is called from `ClientSpellMenuDialog` construction at `0x0051dce7` and `0x0051e189`, installs vtables `0x0061f364`, `0x0061f3ec`, and `0x0061f41c`, and stores packet/list context fields.
- Live IDA reports `0x0051e890-0x0051e998` as the client list renderer; its decompilation copies display text from `entry + 4`, matching client spell-list row data rather than chat-color rows.
- Live IDA reports the real `ChattingColorListPane` constructor at `0x00482fb0`; its only code xrefs remain `0x00482837` and `0x0048295d` inside the chat-color pane construction path, with no spell-menu constructor callers.

## Ownership Decision

The `ChattingColorListPane*` spelling in the client helper is only a local type/name pollution artifact. The source-layout owner remains `ui/dialogs/SpellMenuDialogs.cpp`, and the local type should be renamed to a neutral `SpellMenuItemList` or concrete `ClientSpellMenuItemList` wrapper before source migration.

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
- 2026-06-04: Raised item coverage and parent-attached it to [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md).
  - What existed before: `COMPLETION:70`, `CONFIDENCE:85`, and blank autogen parent metadata. The page had correct behavior notes but stale source-state framing and no parent attachment.
  - Changed to: `COMPLETION:84`, `CONFIDENCE:90`, and `AUTOGEN_PARENT_UID:0000O2`; reconstruction C++ remains blank because child-slot names and final virtual names are still below 95/95.
  - Summary/evidence: live IDA MCP on 2026-06-04 confirmed exact helper ranges, vtable refs, child-slot `1`/`6` use, `sub_4F3E20` enabled-entry counting, action-button virtual dispatch, `ClientSpellMenuItemList` constructor/vtables, client renderer text at `entry + 4`, and no spell-menu xrefs to `ChattingColorListPane` construction.
