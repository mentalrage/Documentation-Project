*** UID:00008X | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ncauth::Notification

## Status

- Confidence: strong for notification role, medium for final source-file grouping.
- Current generated file: `source-3/simroot_v2/class_ncauth__Notification.cpp`
- Likely source module: [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md)
- Current relevant range: `0x00527bb0-0x005285dd`

## Responsibility

`ncauth::Notification` reports status from [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md) NCA auth/update probes. The helper at `0x00528560` allocates an 8-byte notification, stores the status at offset `+4`, and posts it on channel `0x4e634175`.

## Layout

| Offset | Field | Notes |
| --- | --- | --- |
| `+0x00` | vtable | `ncauth::Notification` vtable. |
| `+0x04` | state | See [UID:0001SQ][NcauthNotificationState](by-type/by-enum/NcauthNotificationState.md). |

## Important Methods

| Address | Method | Notes |
| --- | --- | --- |
| `0x00528520` | `ScalarDeletingDestructor` | Destroys the `LObject` base and optionally frees `this`. |
| `0x00528560` | `PostNCAStatus` candidate | Allocates the notification, stores state, posts channel `0x4e634175`. |

## Evidence

- `ProcessNCAUpdate` at `0x00527bb0` calls `0x00528560` for each observed status outcome.
- Internet initialization/open-url failures post state `4`; read failure posts state `5`; response parsing posts states `0`, `1`, `2`, or `3`.
- The generated `class_ncauth__Notification.cpp` currently has duplicated `<cstdint>` include text. That is a data/output issue, not source-layout evidence.

## Cross-References

- [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md)
- [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md)
- [UID:0001SQ][NcauthNotificationState](by-type/by-enum/NcauthNotificationState.md)
- [UID:0001CJ][0x005277c0-0x005285dd.MiscWorkThreadAndNotifications](by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md)

## Changes

- Before: the current relevant range ended at `0x005285dc`.
- Changed to: the range ends at `0x005285dd`.
- Summary/evidence: 2026-05-28 IDA MCP shows `0x005285dc` is the `PostNCAStatus` `retn` byte, followed by padding from `0x005285dd`.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:78` and `CONFIDENCE:76`.
  - Summary/evidence: scored from the NCA auth/update notification role, layout/state enum, scalar destructor, `PostNCAStatus` helper evidence, posted states, and medium confidence on final source-file grouping plus generated output issue.
