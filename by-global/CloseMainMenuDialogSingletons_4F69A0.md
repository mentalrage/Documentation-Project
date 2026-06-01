*** UID:0000PH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# CloseMainMenuDialogSingletons_4F69A0

## Status

- Confidence: strong for behavior and source-family placement.
- Address range: [UID:00019J][0x004f69a0-0x004f6a31.CloseMainMenuDialogSingletons](by-memory/0x004f69a0-0x004f6a31.CloseMainMenuDialogSingletons.md)
- Current generated file: `source-3/simroot_v2/recovered/CloseMainMenuDialogSingletons_004F69A0.cpp`
- Likely owner source: [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)

## Function Role

`CloseMainMenuDialogSingletons_4F69A0` is a pre-login cleanup helper. It marks the active bulletin session and [UID:000066][HistoryViewingPane](by-class/HistoryViewingPane.md) for deletion, closes live login/password/backstory/forced-inform/server-select dialogs, and then closes the active create-user dialog variant selected by `g_useEpfAssets`.

## Evidence Notes

- IDA MCP `lookup_funcs 0x004f69a0` reports a real function of size `0x91`.
- IDA MCP callers are `MainMenuPane` destructor paths at `0x004f695c`, `0x004f6aa8`, and `0x005028a3`.
- IDA MCP callees include the shared dialog close helper at `0x0049dad0` and the pane/session mark-for-delete helper at `0x00544690`.
- Generated `simroot_v2` source shows the helper reads `g_pBulletinSession`, `g_pLoginDialogPane`, `g_pChangePasswordDialogPane`, `g_pBackStoryDialogPane`, `g_pHistoryViewingPane`, `g_pForcedInformMessageDialog`, `g_pServerSelectPane`, `g_pNewCreateUserDialogPane`, `g_pNewUserDialogPane2`, and `g_useEpfAssets`.
- IDA MCP `xrefs_to 0x0069b498` on 2026-05-25 confirms the backstory singleton storage behind [UID:0000Q9][g_pBackStoryDialogPane](by-global/g_pBackStoryDialogPane.md), with this helper reading it at `0x004f69ce`.

## Source Layout Decision

Keep this helper with `login/MainMenuPane.cpp`. It is a free function in generated output, but its only confirmed callers are main-menu destructor/teardown paths and the handled singleton set is the main-menu/login dialog cluster.

## Cross-References

- [UID:00019J][0x004f69a0-0x004f6a31.CloseMainMenuDialogSingletons](by-memory/0x004f69a0-0x004f6a31.CloseMainMenuDialogSingletons.md)
- [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)
- [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md)
- [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md)
- [UID:0000Q9][g_pBackStoryDialogPane](by-global/g_pBackStoryDialogPane.md)
- [UID:0000JJ][ForcedInformMessageDialog](by-file/ForcedInformMessageDialog.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `80/86`.
  - Before: page documented the cleanup helper role, callers, callees, singleton set, and source-layout decision but remained unevaluated.
  - After: score reflects documented pre-login dialog cleanup behavior, exact memory link, main-menu ownership, and singleton/global dependencies.
  - Evidence: IDA notes confirm the function size, main-menu destructor callers, close/mark-for-delete callees, and backstory singleton storage xrefs.
