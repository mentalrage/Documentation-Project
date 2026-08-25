*** UID:0001SQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00008X | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00008X | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
enum NotificationState
{
    Accepted = 0,
    IdRejected = 1,
    PasswordRejected = 2,
    RejectedOther = 3,
    OpenFailed = 4,
    ReadFailed = 5
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# NcauthNotificationState

## Status

- Confidence: medium-high for semantic names, very strong for values and producer/consumer mapping.
- Owner: [UID:00008X][ncauth__Notification](by-class/ncauth__Notification.md)
- Evidence basis: `ProcessNCAUpdate` at `0x00527bb0`, notification helper `0x00528560`, and registration consumer `0x00530230` checked through live IDA MCP on 2026-06-04 and refreshed on 2026-06-11.
- Reconstructable: yes, as source-level NCA update notification constants. Formal first-draft enum C++ now emits from this page; final original names remain behavioral/inferred, but the values, producer paths, and consumer mapping are proven.
- Parent attachment: [UID:00008X][ncauth__Notification](by-class/ncauth__Notification.md), which is `88/90`; this enum is now `88/93`, so the strict child/direct-parent `85/85` gate is satisfied.

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
- 2026-06-11 live IDA MCP `py_eval` reconfirmed `NexusTK.exe` as the IDB root and the three `0x4e634175` immediate use sites: inline worker post at `0x00527c43`, helper post at `0x005285bc`, and registration consumer compare at `0x0053025a`.
- The same 2026-06-11 function-boundary pass reconfirmed `ProcessNCAUpdate` as `0x00527bb0-0x00527ea4`, the notification post helper as `0x00528560-0x005285dd`, and the registration consumer as `0x00530230-0x005303ef`; no additional producer or consumer function boundary appeared in that check.

## Open Questions

- Final names require review of the notification consumer UI text and any server-facing protocol notes.
- The parser behavior is verified, but the original source may have used inline constants, macros, or an enum with user-facing names different from this documentation vocabulary.

## Formal Source Enum

2026-07-01 B008 empty-emitter family implementation makes this page the formal source enum emitted under [UID:00008X][ncauth__Notification](by-class/ncauth__Notification.md). The names are descriptive first-draft source names, but live IDA evidence proves all six values, producer paths, helper `0x00528560`, channel `0x4e634175`, and registration consumer mapping. The aggregate [UID:0001CJ][0x005277c0-0x005285dd.MiscWorkThreadAndNotifications](by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md) should use this enum rather than duplicate it.

## Cross-References

- [UID:00008X][ncauth__Notification](by-class/ncauth__Notification.md)
- [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md)
- [UID:0001CJ][0x005277c0-0x005285dd.MiscWorkThreadAndNotifications](by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md)
- [UID:0001CU][0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers](by-memory/0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers.md)

## 2026-08-11 UID0001CU Formal-Route Incorporation

- Metadata remains `88/93`; owner/emitter remain [UID:00008X][ncauth__Notification](by-class/ncauth__Notification.md), reconstructable remains true, position remains blank, and `Nested:0` remains exact.
- The exact six-value state enum now resides in the formal H channel and expands at UID00008X's `[[CHILDREN]]` position inside namespace `ncauth`. Formal CPP is exactly blank.
- Values remain Accepted `0`, IdRejected `1`, PasswordRejected `2`, RejectedOther `3`, OpenFailed `4`, and ReadFailed `5`. UID0001CU's response switch consumes precisely that mapping.

## Changes

- 2026-06-11 A002 Batch 178:
  - What existed before: `80/90`, reconstructable but unassigned, with producer/consumer values already documented from Batch 104-era research.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:92`, and `AUTOGEN_PARENT_UID:00008X`.
  - Summary/evidence: live IDA MCP reconfirmed the exact worker/post-helper/consumer function boundaries, the only three `NCAu` immediate use sites, state storage at notification payload offset `+4`, and the `0..5` consumer handling already linked through [UID:00008X][ncauth__Notification](by-class/ncauth__Notification.md). Completion remains below final-source quality because original enum value names are still behavioral names rather than recovered declarations.
- 2026-06-04 live IDA consumer evidence update:
  - What existed before: `COMPLETION:72` and `CONFIDENCE:86`, with strong producer-side values but only provisional semantic names.
  - Changed to: `COMPLETION:80` and `CONFIDENCE:90`.
  - Summary/evidence: live IDA confirms the only consumer-side `NCAu` compare at `0x0053025a`, the state dword read at notification payload offset `+4`, success handling for state `0`, and localized message-id mapping for states `1` through `5`. Final enum code remains blank because original constant names are still inferred from behavior rather than recovered declarations.
- 2026-07-01 B008 empty-emitter family implementation:
  - Changed from `COMPLETION:86`, `CONFIDENCE:92`, blank formal C++.
  - Changed to `COMPLETION:88`, `CONFIDENCE:93`, with formal six-value `NotificationState` enum C++.
  - Summary/evidence: B008 live IDA MCP reconfirmed `ProcessNCAUpdate` post states `0..5`, inline/open-failure state `4`, `PostNCAStatus` helper use, and the existing consumer mapping. Original symbol spelling remains inferred but no longer blocks first-draft enum emission.
