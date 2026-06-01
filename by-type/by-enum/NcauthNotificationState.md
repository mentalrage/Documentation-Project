*** UID:0001SQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
- Evidence basis: `ProcessNCAUpdate` at `0x00527bb0` and notification helper `0x00528560` checked through IDA MCP on 2026-05-24 and rechecked on 2026-05-31.
- Reconstructable: yes, as source-level NCA update notification constants. Leave final enum code blank until consumer UI semantics and declaration owner are proven.

## Values

| Value | Proposed name | Evidence |
| --- | --- | --- |
| `0` | `Accepted` | Posted when the first response byte is ASCII `1`. |
| `1` | `IdRejected` | Posted when the response pattern includes space plus `ID`. |
| `2` | `PasswordRejected` | Posted when the response pattern includes `PW`. |
| `3` | `RejectedOther` | Default parsed failure state. |
| `4` | `OpenFailed` | Posted when `InternetOpenA` or `InternetOpenUrlA` fails. |
| `5` | `ReadFailed` | Posted when `InternetReadFile` fails. |

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

## Open Questions

- Final names require review of the notification consumer UI text and any server-facing protocol notes.
- The parser behavior is verified, but the original source may have used inline constants, macros, or an enum with user-facing names different from this documentation vocabulary.

## Cross-References

- [UID:00008X][ncauth__Notification](by-class/ncauth__Notification.md)
- [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md)
- [UID:0001CJ][0x005277c0-0x005285dd.MiscWorkThreadAndNotifications](by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md)
