*** UID:0000M0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# NexonclubRegistrationDialog

## Status

- Confidence: strong for class behavior and IDA boundaries, medium for current Wave3 materialization completeness.
- Proposed module: `ui/dialogs/NexonclubRegistrationDialog.cpp`
- Current recovered source: `source-3/simroot_v2/class_NexonclubRegistrationDialog.cpp`
- Main memory range: [UID:0001CT][0x0052f950-0x00530636.NexonclubRegistrationDialog](by-memory/0x0052f950-0x00530636.NexonclubRegistrationDialog.md)
- Support-helper detail: [UID:0001CU][0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers](by-memory/0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers.md)

## File Role

`NexonclubRegistrationDialog` owns the Nexonclub account-registration form. It builds the username/password dialog, submits the registration request through [UID:0000RQ][g_pMiscWorkThread](by-global/g_pMiscWorkThread.md), manages a pending alert and timeout, handles server response/status messages, opens the web registration URL when requested, and calls back to the caller with the result.

This is related to [UID:0000LZ][NexonclubProxyDialog](by-file/NexonclubProxyDialog.md), but not identical: the proxy parses an NPC/message packet and launches this registration dialog; the registration dialog owns the account form and result flow.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `NexonclubRegistrationDialog` | `0x0052f950-0x00530636` | Registration form, command handling, pending/status alerts, response callback, destructor/thunk support. |
| omitted support helpers | [UID:0001CU][0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers](by-memory/0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers.md) | Real IDA-confirmed functions in the class island that current active simroot output does not emit as normal active methods. |

## Function Map

| Range | Function | Notes |
| --- | --- | --- |
| `0x0052f950-0x0052ff9a` | constructor | Builds the `DLGNC` account/password form, sets result handler, and enters modal input. |
| `0x0052ffa0-0x00530014` | destructor | Cancels callback/status state and destroys pending alert state. |
| `0x00530020-0x00530052` | [UID:0001CU][0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers](by-memory/0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers.md) | IDA-confirmed real helper omitted from active generated source. |
| `0x00530060-0x0053022a` | `OnCommand` | Handles submit, cancel, and open-web-registration commands. |
| `0x00530230-0x005303ef` | [UID:0001CU][0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers](by-memory/0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers.md) | IDA-confirmed real helper omitted from active generated source; routes server result codes to callback or status alerts. |
| `0x00530410-0x005304b3` | `ShowRegistrationStatusAlert` | Clears pending state and shows a status alert. |
| `0x005304c0-0x005304e1` | [UID:0001CU][0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers](by-memory/0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers.md) | IDA-confirmed real helper omitted from active generated source. |
| `0x005304f0-0x00530565` | [UID:0001CU][0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers](by-memory/0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers.md) | IDA-confirmed real helper omitted or polluted in current generated metadata. |
| `0x00530565-0x0053057b` | [UID:0001CU][0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers](by-memory/0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers.md) | Destructor/adjustor thunk support; one disabled body is currently missing in generated output. |
| `0x00530580-0x00530636` | scalar deleting destructor | Deleting-destructor wrapper. |

## Ownership Notes

- The helper group at `0x00530020`, `0x00530230`, `0x005304c0`, and `0x005304f0` should stay with this class despite current generated-source omissions/pollution.
- `0x005304c0` and `0x005304f0` are response/status helpers for the registration dialog, not chat-color or generic alert ownership by themselves.
- IDA xrefs show the submit path reads [UID:0000RQ][g_pMiscWorkThread](by-global/g_pMiscWorkThread.md) and calls the `MiscWorkThread` NCA-update submission wrapper at `0x00528310`.
- The constructor is called from multiple account/registration launch sites, including [UID:0000LZ][NexonclubProxyDialog](by-file/NexonclubProxyDialog.md).
- Use [UID:0000HE][AlertPanes](by-file/AlertPanes.md) only as the shared alert-control dependency; do not move registration response policy into alert infrastructure.

## Current Data Caveats

- Active `simroot_v2` emits only constructor, destructor, command, status-alert, and scalar deleting destructor methods.
- 2026-05-25 recheck: current active output still omits the four helper functions at `0x00530020`, `0x00530230`, `0x005304c0`, and `0x005304f0`; IDA confirms them as real functions in the same class island.
- Disabled output reports one missing thunk body at `0x00530565`, but IDA confirms an 11-byte adjustor thunk that subtracts `0xa0` from `this` and jumps to `0x00530580`.
- Current `simroot_v2` `.meta_wave3` and `.meta_old` files still contain stored method-name control-character grade reasons. Treat those as stale exported metadata unless a fresh live Wave3 grade reintroduces them.

## Cross-References

- [UID:00009I][NexonclubRegistrationDialog](by-class/NexonclubRegistrationDialog.md)
- [UID:0001CT][0x0052f950-0x00530636.NexonclubRegistrationDialog](by-memory/0x0052f950-0x00530636.NexonclubRegistrationDialog.md)
- [UID:0001CU][0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers](by-memory/0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers.md)
- [UID:0000LZ][NexonclubProxyDialog](by-file/NexonclubProxyDialog.md)
- [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md)
- [UID:0000HE][AlertPanes](by-file/AlertPanes.md)
- [UID:0000OM][TextEditControlPane](by-file/TextEditControlPane.md)

## Changes

### 2026-05-28 - Registration Range Endpoint Corrected

- What existed before: the registration-dialog range and scalar deleting destructor were recorded as ending at `0x00530635`.
- What changed: both endpoints are now `0x00530636`.
- Why: IDA MCP reports `sub_530580` ending at `0x00530636`; the byte at `0x00530635` is part of the destructor return instruction.

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `86`, confidence `80`.
- Summary/evidence: the page documents role, function map, support helpers, ownership notes, generated-data caveats, range correction, and cross-references; confidence remains capped by current Wave3 materialization omissions/pollution.
