*** UID:0000PH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000L0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# CloseMainMenuDialogSingletons_4F69A0

## Status

- Confidence: strong for behavior and source-family placement.
- Address range: [UID:00019J][0x004f69a0-0x004f6a31.CloseMainMenuDialogSingletons](by-memory/0x004f69a0-0x004f6a31.CloseMainMenuDialogSingletons.md)
- Likely owner source: [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)
- Singleton storage ranges: [UID:00029H][0x0069b480-0x0069b490.MainMenuAccountDialogSingletons](by-memory/0x0069b480-0x0069b490.MainMenuAccountDialogSingletons.md), [UID:00029W][0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots](by-memory/0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots.md), and individual history/backstory/forced-inform singleton pages.

## Function Role

`CloseMainMenuDialogSingletons_4F69A0` is a pre-login cleanup helper. It marks the active bulletin session and [UID:000066][HistoryViewingPane](by-class/HistoryViewingPane.md) for deletion, closes live login/password/backstory/forced-inform/server-select dialogs, and then closes the active create-user dialog variant selected by [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md).

## Evidence Notes

- IDA MCP `lookup_funcs 0x004f69a0` reports a real function of size `0x91`.
- IDA MCP callers are `MainMenuPane` destructor paths at `0x004f695c`, `0x004f6aa8`, and `0x005028a3`.
- IDA MCP callees include the shared dialog close helper at `0x0049dad0` and the pane/session mark-for-delete helper at `0x00544690`.
- IDA data-flow review shows the helper reads `g_pBulletinSession`, `g_pLoginDialogPane`, `g_pChangePasswordDialogPane`, `g_pBackStoryDialogPane`, `g_pHistoryViewingPane`, `g_pForcedInformMessageDialog`, `g_pServerSelectPane`, `g_pNewCreateUserDialogPane`, `g_pNewUserDialogPane2`, and [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md).
- IDA MCP `xrefs_to 0x0069b498` on 2026-05-25 confirms the backstory singleton storage behind [UID:0000Q9][g_pBackStoryDialogPane](by-global/g_pBackStoryDialogPane.md), with this helper reading it at `0x004f69ce`.
- IDA MCP recheck on 2026-06-05 confirmed `sub_4F69A0`, size `0x91`, the same three teardown callers, and callees `0x00544690` and `0x0049dad0`.
- [UID:00019J][0x004f69a0-0x004f6a31.CloseMainMenuDialogSingletons](by-memory/0x004f69a0-0x004f6a31.CloseMainMenuDialogSingletons.md) now records the exact `0x004f69a0-0x004f6a31` boundary, confirms `0x004f6a31`/`0x004f6a40` are not function starts, lists the same three direct callers, and documents that the screen-dimmer action is a virtual-slot call while the direct callees remain `0x0049dad0` and `0x00544690`.
- [UID:00029W][0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots](by-memory/0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots.md) distinguishes the old/new create-user singleton slots. This helper reads `g_pNewCreateUserDialogPane` at `0x004f6a13` and `g_pNewUserDialogPane2` at `0x004f6a22`, selected by [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md).

## Cleanup Sequence

The cleanup pass first handles already-open pre-login singleton panes, then resolves the create-user variant:

- account/login dialog slots from [UID:00029H][0x0069b480-0x0069b490.MainMenuAccountDialogSingletons](by-memory/0x0069b480-0x0069b490.MainMenuAccountDialogSingletons.md);
- history/backstory/forced-inform/server-select singletons in the adjacent `0x0069b494-0x0069b4a4` range;
- one of the two create-user singleton slots in [UID:00029W][0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots](by-memory/0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots.md), gated by [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md).

This supports keeping the helper as a `MainMenuPane.cpp` file-local/free teardown helper rather than migrating it to any individual dialog class.

## Source Layout Decision

Keep this helper with `login/MainMenuPane.cpp`. It is a free function in generated output, but its only confirmed callers are main-menu destructor/teardown paths and the handled singleton set is the main-menu/login dialog cluster.

## Cross-References

- [UID:00019J][0x004f69a0-0x004f6a31.CloseMainMenuDialogSingletons](by-memory/0x004f69a0-0x004f6a31.CloseMainMenuDialogSingletons.md)
- [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)
- [UID:00029H][0x0069b480-0x0069b490.MainMenuAccountDialogSingletons](by-memory/0x0069b480-0x0069b490.MainMenuAccountDialogSingletons.md)
- [UID:00029W][0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots](by-memory/0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots.md)
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md)
- [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md)
- [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md)
- [UID:0000Q9][g_pBackStoryDialogPane](by-global/g_pBackStoryDialogPane.md)
- [UID:0000JJ][ForcedInformMessageDialog](by-file/ForcedInformMessageDialog.md)

## Changes

- 2026-06-07 A007 singleton-slot sync:
  - What existed before: the page documented the cleanup role and singleton set, but did not directly link the exact account/create-user singleton storage ranges or the current/old create-user branch slots.
  - Changed to: scores `82/88`, added singleton storage range links, recorded the exact `g_pNewCreateUserDialogPane`/`g_pNewUserDialogPane2` read offsets, and added a cleanup-sequence section.
  - Summary/evidence: [UID:00019J][0x004f69a0-0x004f6a31.CloseMainMenuDialogSingletons](by-memory/0x004f69a0-0x004f6a31.CloseMainMenuDialogSingletons.md) confirms the function boundary, callers, and callees; [UID:00029W][0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots](by-memory/0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots.md) confirms the create-user slots and branch addresses.
- 2026-05-30: Grading changed from `0/0` to `80/86`.
  - Before: page documented the cleanup helper role, callers, callees, singleton set, and source-layout decision but remained unevaluated.
  - After: score reflects documented pre-login dialog cleanup behavior, exact memory link, main-menu ownership, and singleton/global dependencies.
  - Evidence: IDA notes confirm the function size, main-menu destructor callers, close/mark-for-delete callees, and backstory singleton storage xrefs.
- 2026-06-05: Marked reconstructable and attached to [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md).
  - Reason: live IDA MCP recheck confirmed this is source-authored main-menu teardown helper code with only main-menu teardown callers and no evidence for an independent source file.
- 2026-06-07 A008 alias cleanup:
  - Normalized the create-user variant selector to canonical [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md).
