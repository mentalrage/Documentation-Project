*** UID:0000TB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000L0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// OpenCreateUserDialog is emitted by exact helper [UID:00019P][0x004f8fa0-0x004f9055.OpenCreateUserDialog](by-memory/0x004f8fa0-0x004f9055.OpenCreateUserDialog.md); this address-suffixed global page remains a search/support alias and does not duplicate the retained launcher body.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# OpenCreateUserDialog_4F8FA0

## Status

- Confidence: strong for helper body, constructor targets, source-module placement, and duplicate active menu path; medium for live callback reachability.
- Address range: [UID:00019P][0x004f8fa0-0x004f9055.OpenCreateUserDialog](by-memory/0x004f8fa0-0x004f9055.OpenCreateUserDialog.md)
- Symbol kind: retained main-menu helper.
- Likely owner file: [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md), with constructor targets in [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- Parent status: assigned to [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md). This helper is `86/90`, and the direct parent is now `89/86`, so both clear the strict 85/85 child/direct-parent gate.
- Current emitted source owner: exact child [UID:00019P][0x004f8fa0-0x004f9055.OpenCreateUserDialog](by-memory/0x004f8fa0-0x004f9055.OpenCreateUserDialog.md) emits the retained `MainMenuPane.cpp` helper. This address-suffixed page is a support/search alias and carries only the formal no-duplicate marker comment above.

## Behavior

`OpenCreateUserDialog_4F8FA0` is a retained pre-login create-user launcher.

Observed behavior:

- checks [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97` at `0x0066da97`;
- in the high-resolution branch, closes the active login dialog singleton if present;
- allocates `0x280` bytes, 640 decimal bytes (Verified with int_convert.py), and constructs [UID:00003B][CreateUserDialogPane](by-class/CreateUserDialogPane.md) at `0x0052dd30`;
- plays a sound/music action through the global sound manager;
- in the alternate branch, allocates `0x280` bytes, 640 decimal bytes (Verified with int_convert.py), and constructs [UID:00009E][NewUserDialogPane2](by-class/NewUserDialogPane2.md) at `0x0052a540`.

IDA reports no direct caller/xref to the helper start in the current database. This makes it likely retained legacy code, an indirect callback target not recovered by IDA xrefs, or an older wrapper now duplicated by `MainMenuPane::ActivateMenuItem`.

## Evidence

- Live IDA MCP on 2026-06-04 confirms `sub_4F8FA0` at `0x004f8fa0` with size `0xb5`; `0x004f9055` is not a function start.
- Live IDA MCP on 2026-06-10 reconfirms `sub_4F8FA0` at `0x004f8fa0` with size `0xb5`, 181 decimal bytes by `int_convert.py`; `0x004f9055` is not a function start and the next helper starts at `0x004f9060`.
- IDA MCP `callers` and `xrefs_to` for `0x004f8fa0` return no direct references.
- IDA MCP `callers` and `xrefs_to` on 2026-06-10 still return no direct references to `0x004f8fa0`.
- IDA MCP callers/xrefs for constructor targets show `CreateUserDialogPane` called from `0x004f8ff8` inside this helper and `0x004f7a82` in the related main-menu path; `NewUserDialogPane2` is called from `0x004f9041` inside this helper and `0x004f7ad0` in the related main-menu path.
- IDA MCP callees for `0x004f8fa0` are `sub_4F4AA0` allocation, `sub_49DAD0` login-dialog close helper, `sub_52DD30` `CreateUserDialogPane` construction, `sub_52A540` `NewUserDialogPane2` construction, and `sub_579E30` sound playback.
- IDA decompilation confirms the exact branch shape: [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97` equal to `1` closes `dword_69B484` if present, allocates `0x280`, constructs `CreateUserDialogPane`, and plays sound; the alternate branch allocates `0x280` and constructs `NewUserDialogPane2` without the close/sound path.
- IDA MCP `decompile 0x004f7a10` on 2026-06-10 shows the active main-menu case duplicates the same create-user behavior instead of calling this retained helper.
- IDA disassembly on 2026-06-10 shows a normal SEH/security-cookie prologue around the source-authored branch behavior; the compiler frame does not change the documented helper semantics.
- 2026-06-12 A002 live IDA MCP session `b001_nexustk` reconfirmed `lookup_funcs 0x004f8fa0` as `sub_4F8FA0` with size `0xb5`, 181 decimal bytes (Verified with int_convert.py); `0x004f9055` is not a function and `0x004f9060` starts the next retained launcher.
- 2026-06-12 `analyze_function 0x004f8fa0` shows the same branch body: compare `byte_66DA97`, close `dword_69B484`, allocate `0x280`, call `sub_52DD30`, call `sub_579E30`, or allocate `0x280` and call `sub_52A540`.
- 2026-06-12 `xrefs_to` still reports no direct xrefs to `0x004f8fa0`, but it reports constructor-target xrefs from both this helper and [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)::`ActivateMenuItem`: `0x0052dd30` from `0x004f8ff8` and `0x004f7a82`, `0x0052a540` from `0x004f9041` and `0x004f7ad0`, and sound helper `0x00579e30` from `0x004f9010` and `0x004f7a9a`.
- 2026-06-12 `analyze_function 0x004f7a10` confirms active menu case `0` duplicates this helper's create-user branch, while other switch cases open login, password, story/history, terminal, or exit flows. This keeps source-module ownership with `MainMenuPane.cpp`, not the dialog implementation file.

## Source Placement

Keep this as a retained private helper in `login/MainMenuPane.cpp` until a live callback path is found. The dialog implementations should stay in [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md).

## Autogen Status

- Reconstructable: true as a retained source-owned launcher/helper.
- Parent: [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md). The direct parent now scores `89/86`, has valid proposed path `NexusTK/login/`, and explicitly keeps retained open helpers in `MainMenuPane.cpp`; the helper and parent both clear the strict 85/85 gate.
- Code: marker-only alias. The exact by-memory page now emits accepted retained-helper C++; live callback reachability remains a confidence cap, not a reason for duplicate alias emission.

## 2026-06-21 B010 Create-User Family Sync

- This helper remains a [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md) retained launcher. [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md) is now non-emitting family/index context and should not own this helper.
- Constructor targets align with the child-only create-user split: `0x004f8ff8` constructs old [UID:00003B][CreateUserDialogPane](by-class/CreateUserDialogPane.md), and `0x004f9041` constructs [UID:00009E][NewUserDialogPane2](by-class/NewUserDialogPane2.md). The helper provides no direct constructor evidence for retained [UID:00008Z][NewCreateUserDialogPane](by-class/NewCreateUserDialogPane.md).
- Blank body duplication is retained only because this page is the address-suffixed alias; exact child [UID:00019P][0x004f8fa0-0x004f9055.OpenCreateUserDialog](by-memory/0x004f8fa0-0x004f9055.OpenCreateUserDialog.md) owns the formal emitted body.

## Score Rationale

- Completion is now 86 because the exact boundary, branch behavior, constructor call sites, callees, source-module owner, compiler-frame caveat, duplicate active main-menu path, strict parent-gate decision, and retained-helper caveat are documented with current live IDA evidence.
- Confidence is now 90 because [UID:00019P][0x004f8fa0-0x004f9055.OpenCreateUserDialog](by-memory/0x004f8fa0-0x004f9055.OpenCreateUserDialog.md) records the exact body and the 2026-06-12 live recheck reconfirmed lookup/xrefs/callees/decompile/disassembly evidence; [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md) now clears the direct-parent gate and records the same active-menu duplicate path and source placement.
- Remaining uncertainty is live reachability: current IDA caller/xref checks still find no direct reference to the helper start.

## Cross-References

- [UID:00019P][0x004f8fa0-0x004f9055.OpenCreateUserDialog](by-memory/0x004f8fa0-0x004f9055.OpenCreateUserDialog.md)
- [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)
- [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- [UID:00003B][CreateUserDialogPane](by-class/CreateUserDialogPane.md)
- [UID:00009E][NewUserDialogPane2](by-class/NewUserDialogPane2.md)
- [UID:0001QN][client_s2-main_menu](by-meta/client_s2-main_menu.md)

## Changes

- 2026-06-12 Agent-A002 Batch 293:
  - Before: `84/88`, `AUTOGEN_PARENT_UID` blank because likely direct parent [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md) was `88/82`.
  - After: `86/90`, assigned to [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md).
  - Summary/evidence: live IDA MCP `b001_nexustk` reconfirmed the `0x004f8fa0-0x004f9055` boundary, no direct helper-start xrefs, `byte_66DA97` branch, `dword_69B484` close path, `0x280` / 640-byte allocations verified with int_convert.py, constructor xrefs shared with `MainMenuPane::ActivateMenuItem`, duplicate active case-0 behavior at `0x004f7a10`, and the `0x004f9060` successor function.
  - Gate rationale: this page is `86/90` and direct parent [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md) is `89/86`, so both clear the strict `85/85` route gate. Final C++ remains blank because live callback reachability is still unresolved.
- 2026-06-10 A001 live refresh and parent-gate repair:
  - Changed to: `COMPLETION:84`, `CONFIDENCE:88`, and blank `AUTOGEN_PARENT_UID`.
  - Summary/evidence: live IDA MCP reconfirmed `sub_4F8FA0` size `0xb5` / 181 decimal bytes, no direct callers or xrefs to the helper start, exact callees, constructor target caller split, active `MainMenuPane` duplicate path at `0x004f7a10`, and branch disassembly with only SEH/security-cookie compiler framing around the source behavior.
  - Gate rationale: likely owner [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md) remains `88/82`, so this page cannot attach under the strict 85/85 child/direct-parent gate.
- 2026-05-30: Grading changed from `0/0` to `64/74`.
  - Before: page documented the retained create-user launcher behavior, constructor targets, no-caller result, and source placement but remained unevaluated.
  - After: score reflects documented behavior and owner hypothesis, with lower confidence because the current database has no direct caller/xref to the helper start.
  - Evidence: IDA notes confirm function size, no direct callers, branch-specific create-user constructors, login-dialog close helper, and sound-manager playback callees.
- 2026-06-02: Raised to `72/82`, marked reconstructable, attached to [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md), and added autogen/scoring rationale based on the exact memory page [UID:00019P][0x004f8fa0-0x004f9055.OpenCreateUserDialog](by-memory/0x004f8fa0-0x004f9055.OpenCreateUserDialog.md). C++ remains blank.
- 2026-06-04 live IDA refresh:
  - Before: the page still mentioned older non-IDA evidence and did not record the live constructor-target caller split.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:84`.
  - Summary/evidence: live IDA MCP reconfirmed `sub_4F8FA0` size `0xb5`, no direct callers/xrefs to the helper start, exact calls to `CreateUserDialogPane` at `0x004f8ff8` and `NewUserDialogPane2` at `0x004f9041`, sibling main-menu constructor calls at `0x004f7a82`/`0x004f7ad0`, and the decompiled [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / `byte_66DA97` branch behavior. Confidence remains capped by unresolved live callback reachability, so reconstruction C++ stays blank.
- 2026-06-07 A008 alias cleanup:
  - Normalized the create-user layout/rendering branch to canonical [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md), retaining `byte_66DA97` as the historical IDA lookup alias.
- 2026-06-21 B010 create-user family sync:
  - Score unchanged.
  - Summary/evidence: replaced obsolete high-score gate wording with retained-helper reachability reasoning and documented this helper's relationship to the non-emitting create-user family/index page.
