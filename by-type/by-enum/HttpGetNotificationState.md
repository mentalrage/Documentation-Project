*** UID:0001SN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# HttpGetNotificationState

## Status

- Confidence: strong for observed state values, medium for final names.
- Owner: [UID:000069][httpget__Notification](by-class/httpget__Notification.md)
- Evidence basis: `FetchHTTPContent` at `0x005277c0` and destructor `0x005284c0` checked through IDA MCP on 2026-05-24 and rechecked on 2026-05-31.
- Reconstructable: yes, as source-level notification state constants. Leave final enum code blank until the original declaration owner/name is proven.

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

## Open Questions

- Final source names are still provisional because no original enum declaration has been found.
- UI consumers of these notification states still need review before the names are considered final.

## Cross-References

- [UID:000069][httpget__Notification](by-class/httpget__Notification.md)
- [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md)
- [UID:0001CJ][0x005277c0-0x005285dd.MiscWorkThreadAndNotifications](by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md)
