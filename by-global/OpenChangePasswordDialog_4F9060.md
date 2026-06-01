*** UID:0000TA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:65 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:65 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# OpenChangePasswordDialog_4F9060

## Status

- Confidence: medium overall; strong for behavior and current unreferenced status, weak for why the wrapper was retained.
- Address range: [UID:00019Q][0x004f9060-0x004f90b4.OpenChangePasswordDialog](by-memory/0x004f9060-0x004f90b4.OpenChangePasswordDialog.md)
- Symbol kind: retained duplicate main-menu/account launcher helper.
- Current IDA name: `___std_parallel_algorithms_hw_threads@0_0` (misleading).
- Likely owner file: [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md), with target behavior in [UID:0000I3][ChangePasswordDialogPane](by-file/ChangePasswordDialogPane.md)

## Behavior

`OpenChangePasswordDialog_4F9060` allocates `620` bytes and constructs [UID:00001L][ChangePasswordDialogPane](by-class/ChangePasswordDialogPane.md). It returns null if allocation fails.

Observed behavior:

- calls the local allocator at `0x004f4aa0` with size `620`;
- on success calls `ChangePasswordDialogPane::ChangePasswordDialogPane` at `0x004fdd40`;
- returns the constructed dialog pointer.

IDA reports no direct caller/xref to the helper start in the current database. The active [UID:00019I][0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs](by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md) action handler case `2` directly allocates `620` bytes and calls `ChangePasswordDialogPane::ChangePasswordDialogPane`, so this wrapper is best treated as retained duplicate launcher code unless a hidden callback path is later proven.

## Evidence

- IDA MCP `lookup_funcs 0x004f9060` reports a real function of size `0x54`.
- IDA MCP `decompile 0x004f9060` shows allocation followed by `sub_4FDD40(result)`.
- IDA MCP `callers` and `xrefs_to` for `0x004f9060` return no direct references.
- IDA MCP `callers 0x004fdd40` reports constructor call sites at `0x004f7b49` and `0x004f90a0`.
- 2026-05-26 IDA recheck still reports no code or data refs to `0x004f9060`; keep reachability weak until an indirect callback table or dead-code decision is proven.
- 2026-05-27 IDA raw-pointer scan across loaded segments found no dword equal to `0x004f9060`.
- 2026-05-28 IDA MCP recheck still reports no code/data refs, no little-endian pointer byte match for `60 90 4F 00`, and no immediate-value search hits for `0x004f9060`.
- 2026-05-28 IDA MCP decompile of `0x004f7a10` shows main-menu case `2` directly allocating `620` bytes and calling `0x004fdd40`, matching this wrapper's behavior without calling the wrapper.

## Source Placement

Keep this as a retained private helper in the login/main-menu family for address-matching reconstruction. It may sit in `login/MainMenuPane.cpp` beside the other retained launch helpers or in `login/ChangePasswordDialogPane.cpp` if account-dialog helpers are grouped by target. A behavior-only source rebuild can rely on the direct action-handler construction path unless later evidence proves this wrapper is reachable.

## Cross-References

- [UID:00019Q][0x004f9060-0x004f90b4.OpenChangePasswordDialog](by-memory/0x004f9060-0x004f90b4.OpenChangePasswordDialog.md)
- [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)
- [UID:0000I3][ChangePasswordDialogPane](by-file/ChangePasswordDialogPane.md)
- [UID:00001L][ChangePasswordDialogPane](by-class/ChangePasswordDialogPane.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- Before: documented as a retained opener with weak unresolved reachability.
- After: documented as a retained duplicate launcher whose lack of current refs has been rechecked; the active main-menu action path is now recorded as directly duplicating the allocation/constructor sequence.
- Why: IDA MCP found no direct or raw-pointer references to `0x004f9060`, while `0x004f7a10` case `2` performs the same `620`-byte allocation and `0x004fdd40` constructor call.
- Evidence: 2026-05-28 IDA MCP `xrefs_to`, `callers`, `find_bytes`, immediate `search`, and `decompile 0x004f7a10`.
