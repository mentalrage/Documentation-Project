*** UID:00009I | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000M0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# NexonclubRegistrationDialog

## Status

- Confidence: strong for class responsibility, IDA function boundaries, parent file ownership, and support-helper relationships; current generated output is incomplete and final helper/field names remain provisional.
- Current parent: [UID:0000M0][NexonclubRegistrationDialog](by-file/NexonclubRegistrationDialog.md)
- Main address range: [UID:0001CT][0x0052f950-0x00530636.NexonclubRegistrationDialog](by-memory/0x0052f950-0x00530636.NexonclubRegistrationDialog.md)
- Support-helper detail: [UID:0001CU][0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers](by-memory/0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers.md)
- Current recovered file: `source-3/simroot_v2/class_NexonclubRegistrationDialog.cpp`

## Class Purpose

`NexonclubRegistrationDialog` is a registration form dialog for Nexonclub accounts. It owns the account/password fields, submit/cancel/web actions, pending request alert, timeout cleanup, server response handling, and result callback. The submit path queues NCA work through [UID:0000RQ][g_pMiscWorkThread](by-global/g_pMiscWorkThread.md).

## Method Families

| Range | Method | Role |
| --- | --- | --- |
| `0x0052f950-0x0052ff9a` | constructor | Builds the account/password form from `DLGNC` resources. |
| `0x0052ffa0-0x00530014` | destructor | Cancels outstanding callback/status state and releases alert objects. |
| `0x00530020-0x00530052` | [UID:0001CU][0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers](by-memory/0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers.md) | Clears request-pending state, cancels timeout, and destroys status alert state. |
| `0x00530060-0x0053022a` | `OnCommand` | Handles submit, cancel, and web-registration commands. |
| `0x00530230-0x005303ef` | [UID:0001CU][0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers](by-memory/0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers.md) | Processes registration response/status data and routes result codes. |
| `0x00530410-0x005304b3` | `ShowRegistrationStatusAlert` | Shows localized registration status/pending alerts. |
| `0x005304c0-0x005304e1` | [UID:0001CU][0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers](by-memory/0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers.md) | Reads the account text control for successful callback payload. |
| `0x005304f0-0x00530565` | [UID:0001CU][0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers](by-memory/0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers.md) | Creates registration status alerts for failure/result cases. |
| `0x00530565-0x0053057b` | [UID:0001CU][0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers](by-memory/0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers.md) | Compiler thunk support. |
| `0x00530580-0x00530636` | scalar deleting destructor | Deleting-destructor wrapper. |

## Key Relationships

- Constructed by [UID:00009H][NexonclubProxyDialog](by-class/NexonclubProxyDialog.md) and other registration launch sites.
- Submit reads [UID:0000RQ][g_pMiscWorkThread](by-global/g_pMiscWorkThread.md) and calls the [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md) NCA-update request wrapper at `0x00528310`.
- Uses [UID:0000OM][TextEditControlPane](by-file/TextEditControlPane.md) for account/password fields.
- Uses [UID:0000HE][AlertPanes](by-file/AlertPanes.md) for pending and result alerts.
- Parent-chain gate: [UID:0000M0][NexonclubRegistrationDialog](by-file/NexonclubRegistrationDialog.md) is `86/80`; aggregate memory page [UID:0001CT][0x0052f950-0x00530636.NexonclubRegistrationDialog](by-memory/0x0052f950-0x00530636.NexonclubRegistrationDialog.md) is `82/88`; support-helper page [UID:0001CU][0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers](by-memory/0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers.md) is `82/90`.

## Data Caveats

Active generated source omits several IDA-confirmed helper functions in this class island. Current exported `simroot_v2` metadata still carries old stored method-name control-character grade reasons, but the main actionable issue is the omitted helper/body coverage. Use the memory doc rather than active simroot alone for source migration decisions.

## Cross-References

- [UID:0000M0][NexonclubRegistrationDialog](by-file/NexonclubRegistrationDialog.md)
- [UID:0001CT][0x0052f950-0x00530636.NexonclubRegistrationDialog](by-memory/0x0052f950-0x00530636.NexonclubRegistrationDialog.md)
- [UID:0001CU][0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers](by-memory/0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers.md)
- [UID:00009H][NexonclubProxyDialog](by-class/NexonclubProxyDialog.md)

## Changes

- 2026-06-07: Raised confidence from `78` to `80` and attached parent `0000M0`.
  - Before: The class stayed just below the parent-attach gate even though the file page and by-memory evidence had already been refreshed.
  - After: The class is attached to [UID:0000M0][NexonclubRegistrationDialog](by-file/NexonclubRegistrationDialog.md) while final C++ remains gated by provisional field/helper names and active generated-output omissions.
  - Evidence: The file parent is `86/80`; the aggregate memory page is `82/88`; the support-helper page is `82/90`; together they document constructor/destructor/command/response/status/helper/thunk/deleting-destructor boundaries, constructor callers, NCA submission, response-state switch table, vtable refs, helper omissions, and padding.

- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` after live IDA MCP on `NexusTK.exe` confirmed registration constructor/destructor/command/response/alert/helper/thunk/deleting-destructor starts at `0x0052f950`, `0x0052ffa0`, `0x00530020`, `0x00530060`, `0x00530230`, `0x00530410`, `0x005304c0`, `0x005304f0`, `0x00530565`, and `0x00530580`. Left `AUTOGEN_PARENT_UID` blank because this class confidence is below the 80 attachment gate even though [UID:0000M0][NexonclubRegistrationDialog](by-file/NexonclubRegistrationDialog.md) is the likely source-module parent.

### 2026-05-28 - Scalar Deleting Destructor Endpoint Corrected

- What existed before: the scalar deleting destructor was recorded as `0x00530580-0x00530635`.
- What changed: the range is now `0x00530580-0x00530636`.
- Why: IDA MCP reports `sub_530580` ending at `0x00530636`; the byte at `0x00530635` is part of the function.
- Before: completion/confidence metadata were `0/0` even though the page already contained detailed constructor/destructor, command, helper, status-alert, work-thread, and generated-output caveat notes.
- Changed to: `COMPLETION:82` and `CONFIDENCE:78`.
- Evidence: IDA-backed method ranges, support-helper pages, construction relationships, text-edit/alert/work-thread dependencies, and data caveats are documented; confidence remains medium-high because active generated output still omits several helper bodies and should not be used alone for migration.
