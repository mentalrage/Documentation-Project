*** UID:0000D1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000NO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ServerSelectMenuItemList

## Status

- Confidence: strong for active list behavior, raw constructor-shaped bytes, vtable identity, row layout, owner forwarding, selected-server display update, and parent placement; medium-high for final source-level field names.
- Likely source file: [UID:0000NO][ServerSelectPane](by-file/ServerSelectPane.md)
- Address range: [UID:0001HR][0x00573d20-0x005747df.ServerSelectPane](by-memory/0x00573d20-0x005747df.ServerSelectPane.md)
- Parent attachment: [UID:0000NO][ServerSelectPane](by-file/ServerSelectPane.md) is `84/80` with valid `NexusTK/login/` placement, and [UID:0001HR][0x00573d20-0x005747df.ServerSelectPane](by-memory/0x00573d20-0x005747df.ServerSelectPane.md) is already attached to that parent.

## Class Purpose

`ServerSelectMenuItemList` is the list-pane widget used by `ServerSelectPane`. It forwards row activation to the owner pane and draws each server row as `Name : Description`, updating the selected server name in the application/session buffer when a row is highlighted.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| Raw constructor-shaped bytes | `0x005744a0-0x005744f8` | Builds the list-pane-derived object, stores the owning `ServerSelectPane` pointer at `+0x14c`, and installs the three `ServerSelectMenuItemList` vtables. IDA still does not model this start as a function. |
| `OnItemActivated` | `0x00574660-0x0057466b` | Two-instruction owner-forwarding thunk: loads `[this + 0x14c]` and jumps to shared activation logic at `0x0049de70`. |
| `DrawListItem` | `0x00574670-0x00574748` | Draws selected/unselected rows, formats `Name : Description`, and copies the selected server name to application state. |

## Evidence Notes

- 2026-06-04 live IDA MCP confirms no function object at `0x005744a0`, real modeled virtuals at `0x00574660-0x0057466b` and `0x00574670-0x00574748`, the server-selection helper at `0x00574510-0x0057454e`, and the packet/helper body at `0x005745b0-0x0057465e`.
- Raw constructor disassembly at `0x005744a0` checks [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97`, calls the `ListPane` constructor at `0x005744c7 -> 0x004f3a50`, stores the owner pointer from `[ebp+8]` to `[this + 0x14c]`, and writes vtables `0x00624dc4`, `0x00624e24`, and `0x00624e54`.
- Parent `ServerSelectPane` construction also installs the primary `ServerSelectMenuItemList` vtable at `0x00573f0b` and `0x005741c8`, matching the inline/class-local construction path documented by [UID:0001HR][0x00573d20-0x005747df.ServerSelectPane](by-memory/0x00573d20-0x005747df.ServerSelectPane.md).
- Vtable slots confirm `0x00624e40 -> 0x00574660` and `0x00624e44 -> 0x00574670`; `xrefs_to` for those methods are vtable data refs, not ordinary code calls.
- `0x00574660` is a compact activation thunk (`mov ecx, [ecx+0x14c]; jmp 0x0049de70`), proving that row activation forwards to the owning server-select context.
- 2026-06-04 live decompilation of `0x00574670` confirms the row-entry layout used by the selection helpers: `[entry + 4]` is the server name, `[entry + 8]` is the description, selected rows copy the name into `dword_67AB1C + 2136`, and drawing formats `"%s : %s"` before calling the text draw helper.
- Selection helper `0x00574510` uses the same entry pointer family and forwards the selected id plus entry pointer to `0x005745b0`, which keeps the list class tied to `ServerSelectPane.cpp` rather than a generic list/control module.
- Remaining uncertainty is field naming and source shape around the raw constructor, not class ownership or behavior. Final reconstruction C++ stays blank.

## Cross-References

- [UID:0000NO][ServerSelectPane](by-file/ServerSelectPane.md)
- [UID:0001HR][0x00573d20-0x005747df.ServerSelectPane](by-memory/0x00573d20-0x005747df.ServerSelectPane.md)
- [UID:0000D2][ServerSelectPane](by-class/ServerSelectPane.md)
- [UID:0000VG][ServerSelectHelpers_574510_5745b0](by-item/ServerSelectHelpers_574510_5745b0.md)
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md)

## Changes

- 2026-06-07 A008 alias cleanup: normalized the raw constructor's `byte_66DA97` layout branch to canonical [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md), preserving `byte_66DA97` as the IDA lookup alias.
- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `78`, confidence `76`.
- Evidence: the page documents active list behavior, owner/file grouping, by-memory range, confirmed virtual methods, entry layout, and helper relationship; confidence is limited by the projected constructor boundary.
- 2026-06-04: raised from `78/76` to `82/84`, marked `RECONSTRUCTABLE:TRUE`, and attached to [UID:0000NO][ServerSelectPane](by-file/ServerSelectPane.md).
  - Summary/evidence: live IDA MCP confirms modeled virtual boundaries, the raw constructor-shaped byte range, vtable installs, vtable slot refs, owner-forwarding activation, row-entry name/description layout, selected-name display write, selected-helper relationship, and valid login parent placement.
  - Remaining gaps: final C++ remains blank because the raw constructor is still unmodeled and source-level names for the owner pointer, row-entry type, and selected-server display state are below the 95/95 threshold.
