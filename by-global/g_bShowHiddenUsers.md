*** UID:0002ZX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000OZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_bShowHiddenUsers

## Status

- Canonical symbol: `g_bShowHiddenUsers`
- Storage: [UID:0002A7][0x0069bed0-0x0069bed4.UserListDialogShowHiddenFlag](by-memory/0x0069bed0-0x0069bed4.UserListDialogShowHiddenFlag.md), byte at `0x0069bed0`
- Symbol kind: module-scope boolean flag
- Owner file: [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md)
- Rebuild handling: `source-authored`
- Confidence: strong for role, storage, and owner; medium-high for exact original variable name capitalization.

## Role

`g_bShowHiddenUsers` controls whether the User List dialog keeps hidden users visible while constructing and refreshing category lists. The flag is read while the dialog is built and while category contents are refreshed, and it is toggled by the user-list control command path.

## Evidence

- [UID:0002A7][0x0069bed0-0x0069bed4.UserListDialogShowHiddenFlag](by-memory/0x0069bed0-0x0069bed4.UserListDialogShowHiddenFlag.md) documents the exact `.data` storage, six direct byte xrefs, and the three trailing unreferenced bytes in the four-byte slot.
- [UID:0001KI][0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane](by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md) owns the executable UserListDialogPane family, including constructor, refresh, and control-command methods that use this flag.
- [UID:0000FN][UserListDialogPane](by-class/UserListDialogPane.md) names this state as `g_bShowHiddenUsers` and records it as runtime state for the dialog class.
- The neighboring dispatch table ends at `0x0069bed0`: [UID:0002A6][0x0069bec8-0x0069bed0.WideApiDispatchTailPointers](by-memory/0x0069bec8-0x0069bed0.WideApiDispatchTailPointers.md) covers the preceding `GetLocaleInfoW` and `SetFileAttributesW` pointers, so this flag is not part of the PlatformApi dispatch table.

## Ownership Decision

Keep this global with [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md). It is dialog feature state, not generic list-control state and not part of the adjacent platform dispatch table. The direct memory child [UID:0002A7][0x0069bed0-0x0069bed4.UserListDialogShowHiddenFlag](by-memory/0x0069bed0-0x0069bed4.UserListDialogShowHiddenFlag.md) attaches here because both this global page and the child page clear the corrected `85/85` gate.

## Reconstruction Notes

Recreate this as a file-scope boolean near the user-list dialog implementation. The exact four-byte initialized storage is compiler/linker layout; the source requirement is the boolean state and its initialization semantics, not a hand-authored four-byte integer table.

## Cross-References

- [UID:0002A7][0x0069bed0-0x0069bed4.UserListDialogShowHiddenFlag](by-memory/0x0069bed0-0x0069bed4.UserListDialogShowHiddenFlag.md)
- [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md)
- [UID:0000FN][UserListDialogPane](by-class/UserListDialogPane.md)
- [UID:0001KI][0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane](by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md)
- [UID:0002A6][0x0069bec8-0x0069bed0.WideApiDispatchTailPointers](by-memory/0x0069bec8-0x0069bed0.WideApiDispatchTailPointers.md)
