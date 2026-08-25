*** UID:0001SN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000069 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000069 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
enum NotificationState {
    Started = 0,
    DataChunk = 1,
    Completed = 2,
    ReadOrOpenUrlFailed = 3,
    InternetOpenFailed = 4
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# HttpGetNotificationState

## Status

- Confidence: strong for observed state values, medium for final names.
- Assigned owner: [UID:000069][httpget__Notification](by-class/httpget__Notification.md)
- Evidence basis: `FetchHTTPContent` at `0x005277c0` and destructor `0x005284c0` checked through IDA MCP on 2026-05-24 and rechecked on 2026-05-31.
- Reconstructable: yes, as source-level notification state constants. Formal first-draft enum C++ now emits from this page; final original names remain inferred, but the values and state-owned payload behavior are proven.

## Assignment Gate

- Child score after Batch 097: `86/89`.
- Direct parent: [UID:000069][httpget__Notification](by-class/httpget__Notification.md), refreshed to `85/86`.
- Parent chain: [UID:000069][httpget__Notification](by-class/httpget__Notification.md) remains under [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md), refreshed to `86/85`.
- Assignment decision: assign to [UID:000069][httpget__Notification](by-class/httpget__Notification.md). The state values are the class's `+0x04` field, are produced by the HTTP fetch helper, and drive the class destructor's payload-release decision.

## Values

| Value | Proposed name | Payload | Notes |
| --- | --- | --- | --- |
| `0` | `Started` | None | Posted after `InternetOpenUrlA` succeeds and before reading begins. |
| `1` | `DataChunk` | `_AUTOBUF<unsigned char>*` | Posted for each non-empty `InternetReadFile` chunk. Destructor releases this payload. |
| `2` | `Completed` | None | Posted after the read loop reaches zero bytes. |
| `3` | `ReadOrOpenUrlFailed` | None | Posted when `InternetOpenUrlA` or a read call fails after `InternetOpenA` succeeded. |
| `4` | `InternetOpenFailed` | Helper object pointer | Posted when `InternetOpenA(\"Baram\", ...)` fails. Destructor releases this payload. |

## IDA MCP Evidence

- 2026-05-31 IDA MCP decompilation of `0x005277c0` shows `InternetOpenA("Baram", ...)`, `InternetOpenUrlA`, and a repeated `InternetReadFile(..., 0x400, ...)` loop.
- The same decompilation assigns notification state `0` before the read loop begins and posts it on channel `0x68747470`.
- Non-empty read chunks allocate/copy an `_AUTOBUF<unsigned char>`-style payload, assign state `1`, and post it on the same channel.
- The zero-byte completion path assigns state `2`; read/open-url failure paths assign state `3`; the `InternetOpenA` failure path assigns state `4`.
- IDA MCP decompilation of `0x005284c0` confirms the `httpget::Notification` destructor releases payload storage when `(state - 1) == 0` or `(state - 1) == 3`, matching states `1` and `4`.

## Batch 097 IDA Recheck

- 2026-06-07 IDA MCP checked `NexusTK.exe` md5 `4247e04e20b65d6414c7238aa8ff5515`.
- Function lookup confirms `FetchHTTPContent` at `0x005277c0-0x00527ba6`, `ProcessWorkItem` at `0x00527fe0-0x005281a1`, and the notification destructor at `0x005284c0-0x0052851a`.
- `ProcessWorkItem` switches on task FourCCs and dispatches `0x47654874` (`GeHt`) to `FetchHTTPContent`, tying this state family to the `MiscWorkThread` HTTP-get request path.
- `FetchHTTPContent` posts every `httpget::Notification` on channel `0x68747470` (`http`): state `4` for `InternetOpenA` failure, state `0` after `InternetOpenUrlA` succeeds, state `1` for copied `_AUTOBUF<unsigned char>` read chunks, state `2` for zero-byte completion, and state `3` for open/read failure after the session exists.
- The destructor installs the `httpget::Notification` vtable, releases the payload for states `1` and `4`, calls `LObject` cleanup, and optionally frees `this`, proving the enum directly controls the class-owned payload lifetime.

## Open Questions

- Final source names are still provisional because no original enum declaration has been found.
- UI consumers of these notification states still need review before the names are considered final.

## Formal Source Enum

2026-07-01 B008 empty-emitter family implementation makes this page the formal source enum emitted under [UID:000069][httpget__Notification](by-class/httpget__Notification.md). The names are descriptive first-draft source names, but live IDA evidence proves all five values, producer states, channel `0x68747470`, and payload ownership. The aggregate [UID:0001CJ][0x005277c0-0x005285dd.MiscWorkThreadAndNotifications](by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md) should use this enum rather than duplicate it.

## Cross-References

- [UID:000069][httpget__Notification](by-class/httpget__Notification.md)
- [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md)
- [UID:0001CJ][0x005277c0-0x005285dd.MiscWorkThreadAndNotifications](by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md)

## Changes

- 2026-06-07 A004 Batch 097:
  - Before: `COMPLETION:76`, `CONFIDENCE:89`, parent blank.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:89`, `AUTOGEN_PARENT_UID:000069`.
  - Summary/evidence: live IDA rechecked the producer helper, worker dispatch, notification channel, state-specific payload ownership, and destructor release states. The strict assignment gate is satisfied after refreshing [UID:000069][httpget__Notification](by-class/httpget__Notification.md) to `85/86` and [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md) to `86/85`; C++ remains blank because final enum/member names are still provisional.
- 2026-07-01 B008 empty-emitter family implementation:
  - Changed from `COMPLETION:86`, `CONFIDENCE:89`, blank formal C++.
  - Changed to `COMPLETION:88`, `CONFIDENCE:90`, with formal five-value `NotificationState` enum C++.
  - Summary/evidence: B008 live IDA MCP reconfirmed `FetchHTTPContent` state postings and destructor-owned payload states. Original symbol spelling remains inferred but no longer blocks source-ready first-draft enum emission.
