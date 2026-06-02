*** UID:0000TB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000L0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# OpenCreateUserDialog_4F8FA0

## Status

- Confidence: medium.
- Address range: [UID:00019P][0x004f8fa0-0x004f9055.OpenCreateUserDialog](by-memory/0x004f8fa0-0x004f9055.OpenCreateUserDialog.md)
- Symbol kind: retained main-menu helper.
- Likely owner file: [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md), with constructor targets in [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- Current generated owner: not emitted as a standalone active `simroot_v2` body during this pass.

## Behavior

`OpenCreateUserDialog_4F8FA0` is a retained pre-login create-user launcher.

Observed behavior:

- checks the main-menu layout/rendering flag at `0x0066da97`;
- in the high-resolution branch, closes the active login dialog singleton if present;
- allocates `0x280` bytes and constructs [UID:00003B][CreateUserDialogPane](by-class/CreateUserDialogPane.md) at `0x0052dd30`;
- plays a sound/music action through the global sound manager;
- in the alternate branch, allocates `0x280` bytes and constructs [UID:00009E][NewUserDialogPane2](by-class/NewUserDialogPane2.md) at `0x0052a540`.

IDA reports no direct caller/xref to the helper start in the current database. This makes it likely retained legacy code, an indirect callback target not recovered by IDA xrefs, or an older wrapper now duplicated by `MainMenuPane::ActivateMenuItem`.

## Evidence

- IDA MCP `lookup_funcs 0x004f8fa0` reports `sub_4F8FA0`, size `0xb5`.
- IDA MCP `callers` and `xrefs_to` for `0x004f8fa0` return no direct references.
- IDA MCP callees include `operator_new`, `CreateUserDialogPane::CreateUserDialogPane`, `NewUserDialogPane2::NewUserDialogPane2`, the login-dialog close helper, and sound-manager playback.
- Prewave/Wave2 cache also ties this function to the create-user constructors, but those owner labels are evidence of callee relationships, not proof that the helper belongs inside either dialog class.

## Source Placement

Keep this as a retained private helper in `login/MainMenuPane.cpp` until a live callback path is found. The dialog implementations should stay in [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md).

## Autogen Status

- Reconstructable: true as a retained source-owned launcher/helper.
- Parent: [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md). The parent is scored `88/82`, has the valid proposed path `NexusTK/login/`, and explicitly keeps this helper in `MainMenuPane.cpp`.
- Code: intentionally blank. The exact by-memory page documents the body, but final source names and live callback reachability are not strong enough for 95+/95+ C++ reconstruction.

## Score Rationale

- Completion is raised to 72 to match the exact memory page because boundary, branch behavior, callees, owner, padding, and retained-helper caveat are documented.
- Confidence is raised to 82 because [UID:00019P][0x004f8fa0-0x004f9055.OpenCreateUserDialog](by-memory/0x004f8fa0-0x004f9055.OpenCreateUserDialog.md) records IDA-backed lookup/callers/xrefs/callees/decompile/disasm/raw-byte evidence, and [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md) records the same source placement.
- Remaining uncertainty is live reachability: current IDA caller/xref checks still find no direct reference to the helper start.

## Cross-References

- [UID:00019P][0x004f8fa0-0x004f9055.OpenCreateUserDialog](by-memory/0x004f8fa0-0x004f9055.OpenCreateUserDialog.md)
- [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)
- [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- [UID:00003B][CreateUserDialogPane](by-class/CreateUserDialogPane.md)
- [UID:00009E][NewUserDialogPane2](by-class/NewUserDialogPane2.md)
- [UID:0001QN][client_s2-main_menu](by-meta/client_s2-main_menu.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `64/74`.
  - Before: page documented the retained create-user launcher behavior, constructor targets, no-caller result, and source placement but remained unevaluated.
  - After: score reflects documented behavior and owner hypothesis, with lower confidence because the current database has no direct caller/xref to the helper start.
  - Evidence: IDA notes confirm function size, no direct callers, branch-specific create-user constructors, login-dialog close helper, and sound-manager playback callees.
- 2026-06-02: Raised to `72/82`, marked reconstructable, attached to [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md), and added autogen/scoring rationale based on the exact memory page [UID:00019P][0x004f8fa0-0x004f9055.OpenCreateUserDialog](by-memory/0x004f8fa0-0x004f9055.OpenCreateUserDialog.md). C++ remains blank.
