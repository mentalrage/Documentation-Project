*** UID:0000PL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000KX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# EnsureLoginDialogPane_4F8B30

## Status

- Confidence: strong for behavior and source-family placement.
- Address range: [UID:00019L][0x004f8b30-0x004f8b8d.EnsureLoginDialogPane](by-memory/0x004f8b30-0x004f8b8d.EnsureLoginDialogPane.md)
- Likely owner source: [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md)

## Function Role

`EnsureLoginDialogPane_4F8B30` lazily creates a [UID:00007F][LoginDialogPane](by-class/LoginDialogPane.md) if [UID:0000RE][g_pLoginDialogPane](by-global/g_pLoginDialogPane.md) is null. It allocates `620` bytes and calls the login-dialog constructor at `0x004fa7a0`.

The helper is currently used by [UID:0000JJ][ForcedInformMessageDialog](by-file/ForcedInformMessageDialog.md) teardown after the accepted forced-inform flow needs to return the client to the login dialog.

## Evidence Notes

- IDA MCP `lookup_funcs 0x004f8b30` reports a real function of size `0x5d`.
- IDA MCP callers are the two forced-inform destructor paths at `0x005880db` and `0x0058ac52`.
- IDA MCP callees are allocator `0x004f4aa0` and `LoginDialogPane::LoginDialogPane` at `0x004fa7a0`.
- IDA MCP `xrefs_to 0x0069b484` confirms this helper reads `g_pLoginDialogPane`.
- IDA MCP recheck on 2026-06-05 confirmed `sub_4F8B30`, size `0x5d`, the same two forced-inform callers, allocator `0x004f4aa0`, and login-dialog constructor `0x004fa7a0`.

## Source Layout Decision

Keep this helper with `login/LoginDialogPane.cpp` or a nearby login helper section. It is not a `ForcedInformMessageDialog` method even though the current caller set is forced-inform teardown.

## Cross-References

- [UID:00019L][0x004f8b30-0x004f8b8d.EnsureLoginDialogPane](by-memory/0x004f8b30-0x004f8b8d.EnsureLoginDialogPane.md)
- [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md)
- [UID:0000JJ][ForcedInformMessageDialog](by-file/ForcedInformMessageDialog.md)
- [UID:00019I][0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs](by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `82/88`.
  - Before: page documented lazy login-dialog creation, callers, callees, global read, and source-layout decision but remained unevaluated.
  - After: score reflects documented behavior, allocation/constructor path, forced-inform caller context, and login-owner assignment.
  - Evidence: IDA notes confirm function size, forced-inform destructor callers, allocator and `LoginDialogPane` constructor callees, and `g_pLoginDialogPane` xrefs.
- 2026-06-05: Marked reconstructable and attached to [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md).
  - Reason: live IDA MCP recheck confirms source-authored lazy login-dialog construction; the helper allocates and constructs `LoginDialogPane`, so it belongs with the login dialog source despite forced-inform callers.
