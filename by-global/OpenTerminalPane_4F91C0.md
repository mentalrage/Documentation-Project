*** UID:0000TF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000L0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# OpenTerminalPane_4F91C0

## Status

- Confidence: strong for helper body, cleanup path, constructor target, and source split; medium for live callback reachability.
- Address range: [UID:00019S][0x004f91c0-0x004f927d.OpenTerminalPane](by-memory/0x004f91c0-0x004f927d.OpenTerminalPane.md)
- Symbol kind: retained main-menu helper.
- Likely owner file: [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md), with constructor target in [UID:0000OI][TerminalPane](by-file/TerminalPane.md)
- Current emitted source owner: none; retain the helper under the documented main-menu owner until a live callback path is found.

## Behavior

`OpenTerminalPane_4F91C0` is a retained pre-login terminal launcher.

Observed behavior:

- sends the shared cleanup packet through the packet/session object at `dword_67A7EC`;
- performs an additional packet/session reset helper call at `0x00596620`;
- closes the active login dialog singleton if present;
- detaches/unregisters and queues the caller-provided pane through [UID:0000HR][BlackHole](by-file/BlackHole.md) at `dword_67A74C`;
- checks a client-state flag at `g_pClientState + 2692810`;
- if the flag is set, requests application exit;
- otherwise allocates `0x270` bytes and constructs [UID:0000EG][TerminalPane](by-class/TerminalPane.md) at `0x0058af50`;
- plays sound/sample id `0x192` through the global sound manager.

IDA reports no direct caller/xref to the helper start in the current database. The `TerminalPane` constructor call site at `0x004f924f` is inside this helper.

## Evidence

- Live IDA MCP on 2026-06-04 confirms `sub_4F91C0` at `0x004f91c0` with size `0xbd`; `0x004f927d` is not a function start.
- IDA MCP `callers` and `xrefs_to` for `0x004f91c0` return no direct references.
- IDA MCP callers/xrefs for `TerminalPane::TerminalPane` at `0x0058af50` include `0x004f924f` inside this helper, plus related construction paths at `0x004f5f9b`, `0x004f647a`, and `0x004f7cbb`.
- IDA MCP callees for `0x004f91c0` are `sub_574B20` packet/session cleanup, `sub_596620` packet/session reset, `sub_49DAD0` login-dialog close helper, `sub_469180` [UID:0000HR][BlackHole](by-file/BlackHole.md) pane queueing with `dword_67A74C`, `sub_464E40` application exit request, `sub_4F4AA0` allocation, `sub_58AF50` `TerminalPane` construction, and `sub_57A5C0` sound playback.
- IDA decompilation confirms the exact flow: cleanup/reset through `dword_67A7EC`, close `dword_69B484` if present, queue the caller-provided pane through `dword_67A74C`, check `*(byte *)(dword_67A7C8 + 2692810)`, request exit through `dword_67AB1C` if set, otherwise allocate `0x270` bytes and construct `TerminalPane`, then play sound id `0x192` through `dword_67A7D0`.
- Existing [UID:0001JB][0x0058af50-0x0058c350.TerminalPaneAndSetup](by-memory/0x0058af50-0x0058c350.TerminalPaneAndSetup.md) notes include the constructor caller at `0x004f924f`, matching this helper.

## Source Placement

Keep this as a retained private helper in `login/MainMenuPane.cpp` or an adjacent pre-login launch-helper section. The `TerminalPane` implementation should remain in [UID:0000OI][TerminalPane](by-file/TerminalPane.md).

## Autogen Status

- Reconstructable: true as a retained source-owned launcher/helper.
- Parent: [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md). The parent is scored `88/82`, has the valid proposed path `NexusTK/login/`, and explicitly keeps this helper in `MainMenuPane.cpp`.
- Code: intentionally blank. The exact by-memory page documents the body, but final source names and live callback reachability are not strong enough for 95+/95+ C++ reconstruction.

## Score Rationale

- Completion is now 82 because the exact boundary, cleanup/reset path, constructor target, exit branch, sound call, owner, padding, retained-helper caveat, and live constructor-call split are documented.
- Confidence is now 84 because [UID:00019S][0x004f91c0-0x004f927d.OpenTerminalPane](by-memory/0x004f91c0-0x004f927d.OpenTerminalPane.md) records the exact body and the 2026-06-04 live recheck reconfirmed lookup/callers/xrefs/callees/decompile evidence; [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md) records the same source placement.
- Remaining uncertainty is live reachability: current IDA caller/xref checks still find no direct reference to the helper start.

## Cross-References

- [UID:00019S][0x004f91c0-0x004f927d.OpenTerminalPane](by-memory/0x004f91c0-0x004f927d.OpenTerminalPane.md)
- [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)
- [UID:0000OI][TerminalPane](by-file/TerminalPane.md)
- [UID:0000EG][TerminalPane](by-class/TerminalPane.md)
- [UID:0000HR][BlackHole](by-file/BlackHole.md)
- [UID:0001QN][client_s2-main_menu](by-meta/client_s2-main_menu.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `64/74`.
  - Before: page documented retained terminal launcher behavior, constructor target, no-caller result, and source placement but remained unevaluated.
  - After: score reflects documented behavior and owner hypothesis, with lower confidence because current IDA data has no direct caller/xref to the helper start.
  - Evidence: IDA notes confirm function size, no direct callers, cleanup/reset/login-close/BlackHole/exit/TerminalPane/sound callees, and constructor caller inside this helper.
- 2026-06-02: Raised to `72/82`, marked reconstructable, attached to [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md), and added autogen/scoring rationale based on the exact memory page [UID:00019S][0x004f91c0-0x004f927d.OpenTerminalPane](by-memory/0x004f91c0-0x004f927d.OpenTerminalPane.md). C++ remains blank.
- 2026-06-04 live IDA refresh:
  - Before: the page had the retained-helper model but did not record the current decompiled control flow, constructor-target caller split, or exact global/callee roles.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:84`.
  - Summary/evidence: live IDA MCP reconfirmed `sub_4F91C0` size `0xbd`, no direct callers/xrefs to the helper start, exact `TerminalPane` construction at `0x004f924f`, related constructor calls at `0x004f5f9b`, `0x004f647a`, and `0x004f7cbb`, cleanup/reset via `dword_67A7EC`, BlackHole queueing via `dword_67A74C`, exit branch through `dword_67AB1C`, allocation size `0x270`, and sound id `0x192`. Confidence remains capped by unresolved live callback reachability, so reconstruction C++ stays blank.
