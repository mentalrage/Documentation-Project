*** UID:0001SP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MiscWorkThreadMessageId

## Status

- Confidence: strong for observed values, medium for final symbolic names.
- Owner: [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md)
- Evidence basis: `MiscWorkThread::ProcessWorkItem` decompilation and request-submission helpers checked through IDA MCP on 2026-05-24 and rechecked on 2026-05-31.
- Reconstructable: yes, as source-level async worker message constants. Do not emit final enum code until the owner header and original names are proven.

## Values

| Value | FourCC | Proposed name | Payload | Worker behavior |
| --- | --- | --- | --- | --- |
| `0x42446972` | `BDir` | `BrowseDirectory` | Heap ANSI title string | Shows shell folder picker and posts [UID:000012][brdir__Notification](by-class/brdir__Notification.md). |
| `0x47654874` | `GeHt` | `GetHttp` | One heap `SimpleUString` URL | Calls `FetchHTTPContent`, then destroys the string wrapper. |
| `0x4e434175` | `NCAu` | `NcaUpdate` | Two adjacent heap `SimpleUString` values | Calls `ProcessNCAUpdate`, then destroys both string wrappers. |

## Notes

- The message ids are passed through [UID:0000EV][Thread](by-class/Thread.md) async queue helper `0x00596960`.
- Unknown message ids fall back to `Thread::OnMessage`.
- Posted notification channels are not identical for every request: HTTP posts `0x68747470` (`http`), NCA posts `0x4e634175`, and browse-directory reposts `0x42446972`.

## IDA MCP Evidence

- 2026-05-31 IDA MCP decompilation of `0x00527fe0` shows a `switch (a2)` with cases `1111779698`, `1197820020`, and `1313030517`.
- Case `1111779698` initializes COM, shows the shell folder picker, creates a `brdir::Notification`, posts it with the same `1111779698` channel, hides the cursor, uninitializes COM, and frees the heap title string.
- Case `1197820020` converts the heap string payload and calls `0x005277c0` (`FetchHTTPContent`), then destroys the string wrapper and payload block.
- Case `1313030517` calls `0x00527bb0` (`ProcessNCAUpdate`) with two adjacent string wrappers, then destroys both wrappers and the payload block.
- The default branch forwards to `0x00596920`, matching the inherited thread-message fallback.

## Open Questions

- The FourCC-like values are strong, but final source spelling may have used macros or constants rather than an enum.
- Submission call sites still need a full pass before the message names are considered final.

## Cross-References

- [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md)
- [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md)
- [UID:0001CJ][0x005277c0-0x005285dd.MiscWorkThreadAndNotifications](by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md)
