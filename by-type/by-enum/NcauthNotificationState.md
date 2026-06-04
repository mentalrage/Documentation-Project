*** UID:0001SQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# NcauthNotificationState

## Status

- Confidence: medium for semantic names, strong for values.
- Owner: [UID:00008X][ncauth__Notification](by-class/ncauth__Notification.md)
- Evidence basis: `ProcessNCAUpdate` at `0x00527bb0`, notification helper `0x00528560`, and registration consumer `0x00530230` checked through live IDA MCP on 2026-06-04.
- Reconstructable: yes, as source-level NCA update notification constants. Leave final enum code blank until consumer UI semantics and declaration owner are proven.

## Values

| Value | Proposed name | Producer evidence | Consumer handling |
| --- | --- | --- | --- |
| `0` | `Accepted` | Posted when the first response byte is ASCII `1`. | `0x00530230` routes through `sub_5304C0` and the registration success callback. |
| `1` | `IdRejected` | Posted when the response pattern includes space plus `ID`. | `0x00530230` calls `sub_5304F0` with localized message id `228`. |
| `2` | `PasswordRejected` | Posted when the response pattern includes `PW`. | `0x00530230` calls `sub_5304F0` with localized message id `229`. |
| `3` | `RejectedOther` | Default parsed failure state. | `0x00530230` calls `sub_5304F0` with localized message id `230`. |
| `4` | `OpenFailed` | Posted when `InternetOpenA` or `InternetOpenUrlA` fails. | `0x00530230` calls `sub_5304F0` with localized message id `231`. |
| `5` | `ReadFailed` | Posted when `InternetReadFile` fails. | `0x00530230` calls `sub_5304F0` with localized message id `232`. |

## Notes

- Final user-facing names should wait for UI handler review. The table names describe current parser behavior, not confirmed original enum names.
- Notifications are posted on channel `0x4e634175`.

## IDA MCP Evidence

- 2026-05-31 IDA MCP decompilation of `0x00527bb0` shows `InternetOpenA`, URL construction, `InternetOpenUrlA`, and `InternetReadFile` into a small response buffer.
- `InternetOpenUrlA` failure posts state `4` through `0x00528560`; `InternetReadFile` failure posts state `5`.
- If `Buffer[0] == 49` (`'1'`), the code posts state `0`.
- If the parsed response contains space followed by `ID`, the code posts state `1`.
- If the parsed response contains `PW`, the code posts state `2`; otherwise the failure parser posts state `3`.
- IDA MCP decompilation of `0x00528560` confirms it allocates an `ncauth::Notification`, writes the state to `v2[1]`, and posts on channel `0x4e634175`.
- 2026-06-04 live IDA MCP immediate scan finds the only consumer-side `0x4e634175` compare at `0x0053025a` in `0x00530230-0x005303ef`.
- `0x00530230` reads the posted notification payload's state dword at offset `+4`, switches over values `0` through `5`, sends state `0` through the registration success callback, and maps states `1` through `5` to localized message ids `228` through `232`.

## Open Questions

- Final names require review of the notification consumer UI text and any server-facing protocol notes.
- The parser behavior is verified, but the original source may have used inline constants, macros, or an enum with user-facing names different from this documentation vocabulary.

## Cross-References

- [UID:00008X][ncauth__Notification](by-class/ncauth__Notification.md)
- [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md)
- [UID:0001CJ][0x005277c0-0x005285dd.MiscWorkThreadAndNotifications](by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md)
- [UID:0001CU][0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers](by-memory/0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers.md)

## Changes

- 2026-06-04 live IDA consumer evidence update:
  - What existed before: `COMPLETION:72` and `CONFIDENCE:86`, with strong producer-side values but only provisional semantic names.
  - Changed to: `COMPLETION:80` and `CONFIDENCE:90`.
  - Summary/evidence: live IDA confirms the only consumer-side `NCAu` compare at `0x0053025a`, the state dword read at notification payload offset `+4`, success handling for state `0`, and localized message-id mapping for states `1` through `5`. Final enum code remains blank because original constant names are still inferred from behavior rather than recovered declarations.
