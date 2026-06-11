*** UID:000069 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000LG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# httpget::Notification

## Status

- Confidence: strong for notification role, layout, state ownership, and destructor behavior; medium for final member names.
- Current generated file: `source-3/simroot_v2/class_httpget__Notification.cpp`
- Likely source module: [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md)
- Current relevant range: `0x005277c0-0x00528519`

## Responsibility

`httpget::Notification` reports progress and failures from [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md) HTTP fetch requests. The notification is posted on channel `0x68747470` (`http`) and carries a state integer plus an optional payload pointer.

## Assignment Gate

- Class score after Batch 097: `85/86`.
- Direct parent: [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md), refreshed to `86/85`.
- Assignment decision: retain parent [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md). The class is allocated and posted by the `MiscWorkThread` HTTP fetch helper, consumed through the same worker notification channel, and destructed by its own vtable path in the MiscWorkThread helper cluster.
- Nested child decision: [UID:0001SN][HttpGetNotificationState](by-type/by-enum/HttpGetNotificationState.md) is assigned here because the state values are the class `+0x04` field and directly control `+0x08` payload lifetime.

## Layout

| Offset | Field | Notes |
| --- | --- | --- |
| `+0x00` | vtable | `httpget::Notification` vtable. |
| `+0x04` | state | See [UID:0001SN][HttpGetNotificationState](by-type/by-enum/HttpGetNotificationState.md). |
| `+0x08` | payload | Chunk `_AUTOBUF<unsigned char>` for state `1`; callback/object payload for state `4`; otherwise usually null. |

Observed allocation size is `0x0c` bytes in the HTTP fetch producer path, matching the vtable, state, and payload-pointer layout.

## Important Methods

| Address | Method | Notes |
| --- | --- | --- |
| `0x005277c0` | producer helper | Allocates/posts `httpget::Notification` objects for HTTP start, data, completion, and failure states. |
| `0x005284c0` | `~Notification` | Releases `payload` when state is `1` or `4`, then destroys the `LObject` base and optionally frees `this`. |

## Evidence

- `FetchHTTPContent` at `0x005277c0` posts start state `0`, data-chunk state `1`, complete state `2`, read/open-url error state `3`, and InternetOpen failure state `4`.
- Data chunks allocate an `_AUTOBUF<unsigned char>` and copy up to `0x400` bytes read from `InternetReadFile`.
- The destructor checks state values that own `payload`, matching the chunk and InternetOpen-failure branches.
- 2026-06-05 live IDA MCP confirms `FetchHTTPContent` at `0x005277c0-0x00527ba6` and the notification scalar deleting destructor at `0x005284c0-0x0052851a`. The destructor decompilation installs the `httpget::Notification` vtable, releases the `+0x08` payload when `(state - 1) == 0` or `(state - 1) == 3`, calls `LObject` cleanup at `0x004f4a90`, and conditionally frees storage through `0x004f4ac0`.
- 2026-06-07 Batch 097 live IDA MCP recheck against `NexusTK.exe` md5 `4247e04e20b65d6414c7238aa8ff5515` confirms `ProcessWorkItem` at `0x00527fe0-0x005281a1` dispatches the `0x47654874` (`GeHt`) work item to `FetchHTTPContent`, tying the notification class to the `MiscWorkThread` HTTP-get path.
- The same recheck confirms `FetchHTTPContent` posts state `4` for `InternetOpenA` failure, state `0` after `InternetOpenUrlA` succeeds, state `1` for copied `_AUTOBUF<unsigned char>` chunks, state `2` for zero-byte completion, and state `3` for open/read failure after the session is active; all posts use channel `0x68747470`.

## Cross-References

- [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md)
- [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md)
- [UID:0001SN][HttpGetNotificationState](by-type/by-enum/HttpGetNotificationState.md)
- [UID:0001CJ][0x005277c0-0x005285dd.MiscWorkThreadAndNotifications](by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md)

## Changes

- 2026-06-07 A004 Batch 097 parent-gate refresh:
  - Before: `COMPLETION:80`, `CONFIDENCE:84`, parent [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md).
  - Changed to: `COMPLETION:85`, `CONFIDENCE:86`, parent retained.
  - Summary/evidence: live IDA rechecked the producer helper, `GeHt` worker dispatch, state-posting paths, notification channel, `0x0c` layout, and destructor-owned payload release. The direct parent gate is satisfied because [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md) is refreshed to `86/85`; C++ remains blank because final member and enum declaration names are still provisional.
- 2026-06-05 autogen metadata classification and confidence update:
  - What existed before: `CONFIDENCE:78`; reconstruction autogen metadata was unclassified.
  - Changed to: `CONFIDENCE:84`, `RECONSTRUCTABLE:TRUE`, and parent [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md).
  - Summary/evidence: live IDA MCP against `NexusTK.exe` md5 `4247e04e20b65d6414c7238aa8ff5515` confirmed `0x005277c0` as `FetchHTTPContent` and `0x005284c0` as the notification destructor; targeted destructor decompilation confirmed vtable installation, state-owned payload release for states `1` and `4`, `LObject` cleanup, and scalar-delete behavior. Completion remains `80` because final source names and payload ownership terminology are still not fully reconstructed. The class and parent now pass the 80/80 parent gate. No reconstruction C++ was emitted because the page is below 95/95.

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:80` and `CONFIDENCE:78`.
  - Summary/evidence: scored from the HTTP notification role, layout/state/payload ownership notes, destructor behavior, `FetchHTTPContent` state-posting evidence, chunk allocation behavior, and medium confidence on final source-file grouping.
