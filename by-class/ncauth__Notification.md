*** UID:00008X | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000LG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ncauth::Notification

## Status

- Confidence: strong for notification layout, construction/posting paths, consumer handling, and owner family; medium-high for final original declaration names.
- Likely source module: [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md)
- Current relevant ranges: NCA worker `0x00527bb0-0x00527ea4`, destructor `0x00528520-0x00528558`, post helper `0x00528560-0x005285dd`, registration consumer `0x00530230-0x005303ef`, and vtable `0x0061fbd0`.
- Reconstructable: yes, as a local notification payload attached to [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md). Final C++ remains blank because the original declaration spelling and helper names are still below the `95/95` reconstruction bar.

## Responsibility

`ncauth::Notification` reports status from [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md) NCA auth/update probes. The worker posts it on channel `0x4e634175` (`NCAu`), and the [UID:00009I][NexonclubRegistrationDialog](by-class/NexonclubRegistrationDialog.md) response handler consumes the state value to finish or reject a pending registration request.

## Layout

| Offset | Field | Notes |
| --- | --- | --- |
| `+0x00` | vtable | `ncauth::Notification` vtable at `0x0061fbd0`; first slot points to `0x00528520`. |
| `+0x04` | state | See [UID:0001SQ][NcauthNotificationState](by-type/by-enum/NcauthNotificationState.md). |

## Important Methods

| Range | Method | Notes |
| --- | --- | --- |
| `0x00528520-0x00528558` | `ScalarDeletingDestructor` | Destroys the `LObject` base and optionally frees `this`. |
| `0x00528560-0x005285dd` | `PostNCAStatus` candidate | Allocates the notification, stores state at `+4`, posts channel `0x4e634175`. |

## Evidence

- 2026-06-04 live IDA MCP evidence from `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe` (image base `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`) confirms `ProcessNCAUpdate` at `0x00527bb0-0x00527ea4`, the scalar deleting destructor at `0x00528520-0x00528558`, and the post helper at `0x00528560-0x005285dd`.
- Vtable `0x0061fbd0` is named `??_7Notification@ncauth@@6B@`, points first to `0x00528520`, and has construction/data refs at `0x00527c2b` and `0x005285a5`.
- `ProcessNCAUpdate` has a direct inline `InternetOpenA` failure path at `0x00527c0b-0x00527c4f`: allocate 8 bytes, construct the [UID:00007D][LObject](by-class/LObject.md) shell, install the `ncauth::Notification` vtable, write state `4` at offset `+4`, and post channel `0x4e634175` through `0x004aa1d0`.
- `0x00528560` is called only from `ProcessNCAUpdate` at `0x00527e0d` and `0x00527e86`; it allocates 8 bytes, installs the same vtable, writes the caller-provided state at `+4`, and posts channel `0x4e634175`.
- The worker posts state `4` for `InternetOpenA` and `InternetOpenUrlA` failures, state `5` for `InternetReadFile` failure, state `0` when the response starts with ASCII `'1'`, state `1` for the parsed `ID` rejection pattern, state `2` for the parsed `PW` rejection pattern, and state `3` for other parsed rejection responses.
- Live immediate search finds exactly three `0x4e634175` code operands: the inline worker post at `0x00527c43`, the helper post at `0x005285bc`, and the registration consumer compare at `0x0053025a`.
- Consumer `0x00530230-0x005303ef` rejects non-`NCAu` packets, checks the pending-registration flag at object offset `+0x1d0`, reads the notification state from payload offset `+4`, maps state `0` through the success callback, and maps states `1` through `5` to localized message ids `228` through `232`.

## Cross-References

- [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md)
- [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md)
- [UID:00009I][NexonclubRegistrationDialog](by-class/NexonclubRegistrationDialog.md)
- [UID:0001SQ][NcauthNotificationState](by-type/by-enum/NcauthNotificationState.md)
- [UID:0001CJ][0x005277c0-0x005285dd.MiscWorkThreadAndNotifications](by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md)
- [UID:0001CU][0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers](by-memory/0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers.md)

## Changes

- Before: the current relevant range ended at `0x005285dc`.
- Changed to: the range ends at `0x005285dd`.
- Summary/evidence: 2026-05-28 IDA MCP shows `0x005285dc` is the `PostNCAStatus` `retn` byte, followed by padding from `0x005285dd`.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:78` and `CONFIDENCE:76`.
  - Summary/evidence: scored from the NCA auth/update notification role, layout/state enum, scalar destructor, `PostNCAStatus` helper evidence, posted states, and medium confidence on final source-file grouping.
- 2026-06-04 live IDA evidence update:
  - What existed before: `COMPLETION:78` and `CONFIDENCE:76`, with a short role/layout summary, source-output caveat, and no documented consumer handling.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:88`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000LG`.
  - Summary/evidence: live IDA confirms exact function ranges, vtable `0x0061fbd0`, inline and helper construction paths, `0x4e634175` posting, state writes at `+4`, destructor behavior, the only consumer compare at `0x0053025a`, and registration-handler state mapping. C++ remains blank because original declaration spelling/helper names are not yet at the `95/95` bar.
