*** UID:000069 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# httpget::Notification

## Status

- Confidence: strong for notification role, medium for final source-file grouping.
- Current generated file: `source-3/simroot_v2/class_httpget__Notification.cpp`
- Likely source module: [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md)
- Current relevant range: `0x005277c0-0x00528519`

## Responsibility

`httpget::Notification` reports progress and failures from [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md) HTTP fetch requests. The notification is posted on channel `0x68747470` (`http`) and carries a state integer plus an optional payload pointer.

## Layout

| Offset | Field | Notes |
| --- | --- | --- |
| `+0x00` | vtable | `httpget::Notification` vtable. |
| `+0x04` | state | See [UID:0001SN][HttpGetNotificationState](by-type/by-enum/HttpGetNotificationState.md). |
| `+0x08` | payload | Chunk `_AUTOBUF<unsigned char>` for state `1`; callback/object payload for state `4`; otherwise usually null. |

## Important Methods

| Address | Method | Notes |
| --- | --- | --- |
| `0x005284c0` | `~Notification` | Releases `payload` when state is `1` or `4`, then destroys the `LObject` base and optionally frees `this`. |

## Evidence

- `FetchHTTPContent` at `0x005277c0` posts start state `0`, data-chunk state `1`, complete state `2`, read/open-url error state `3`, and InternetOpen failure state `4`.
- Data chunks allocate an `_AUTOBUF<unsigned char>` and copy up to `0x400` bytes read from `InternetReadFile`.
- The destructor checks state values that own `payload`, matching the chunk and InternetOpen-failure branches.

## Cross-References

- [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md)
- [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md)
- [UID:0001SN][HttpGetNotificationState](by-type/by-enum/HttpGetNotificationState.md)
- [UID:0001CJ][0x005277c0-0x005285dd.MiscWorkThreadAndNotifications](by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:80` and `CONFIDENCE:78`.
  - Summary/evidence: scored from the HTTP notification role, layout/state/payload ownership notes, destructor behavior, `FetchHTTPContent` state-posting evidence, chunk allocation behavior, and medium confidence on final source-file grouping.
