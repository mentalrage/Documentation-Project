*** UID:0000R6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pIconsPane

## Status

- Confidence: strong for address and lifecycle, medium for final declaration owner.
- Address: `0x0069b41c`
- Current aliases: `dword_69B41C`, `DAT_0069b41c`
- Kind: process-wide singleton pointer to [UID:00006B][IconsPane](by-class/IconsPane.md)
- Proposed owner module: [UID:0000JZ][IconsPane](by-file/IconsPane.md)
- Evidence basis: `simroot_v2` generated source plus IDA MCP xrefs/decompilation on 2026-05-24.

## Lifecycle

- Set in `IconsPane::IconsPane` at `0x004cf215`.
- Cleared by the non-deleting cleanup helper at `0x004cf260`.
- Cleared by the scalar deleting destructor at `0x004cfda0`.
- Read during main UI shutdown at `0x00504a07`.
- Read by option UI paths around `0x0053da72` and `0x0053dec2`, which call `IsShowingAllIcons`, `ShowAllIcons`, and `ShowReducedIcons`.

## Ownership Notes

This global is the singleton for the old-layout icon strip. It should be owned by `IconsPane.cpp`, not by [UID:0000OF][TabPane](by-file/TabPane.md), even though the two classes are adjacent and their destructor thunks are interleaved.

## Data Caveats

Current active `class_IconsPane.cpp` exposes this global and now emits the constructor, cleanup helper, and scalar deleting destructor paths that write or clear it. The main UI shutdown and option UI consumers remain outside the generated class file, so use the IDA-confirmed lifecycle above and the memory pages when migrating global ownership.

## Cross-References

- [UID:00006B][IconsPane](by-class/IconsPane.md)
- [UID:0000JZ][IconsPane](by-file/IconsPane.md)
- [UID:00016Z][0x004cf1f0-0x004cf8d5.IconsPaneCore](by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md)
- [UID:000170][0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail](by-memory/0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail.md)

## Changes

- 2026-05-30: Changed completion/confidence from `0/0` to `82/78`.
  - Before: The page had strong lifecycle/address notes but was unscored and still described active output as omitting helper functions that clear the singleton.
  - After: The page records that current active `class_IconsPane.cpp` emits the constructor, cleanup helper, and scalar deleting destructor singleton writes/clears, while consumer paths remain outside this generated file.
  - Evidence: Current `class_IconsPane.cpp` has `NTK_ScopedInstall(IconsPane, 0x004cf1f0)`, `NTK_ScopedInstall(Cleanup, 0x004cf260)`, and `NTK_ScopedVirtualInstall(ScalarDeletingDestructor, 0x004cfda0)`; existing IDA notes record reads from main UI shutdown and option UI paths.
