*** UID:0001SP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00008I | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00008I | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
enum MiscWorkThreadMessageId {
    kMiscWorkBrowseDirectory = 0x42446972, // BDir
    kMiscWorkGetHttp = 0x47654874,         // GeHt
    kMiscWorkNcaUpdate = 0x4e434175        // NCAu request
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MiscWorkThreadMessageId

## Status

- Confidence: strong for observed values, dispatch behavior, payload ownership, request producers, and parent ownership; medium-high for final symbolic names.
- Owner: [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md)
- Evidence basis: `MiscWorkThread::ProcessWorkItem` decompilation and request-submission helpers checked through IDA MCP on 2026-05-24 and rechecked on 2026-05-31.
- Reconstructable: yes, as source-level async worker message constants. Do not emit final enum code until the owner header and original names are proven.
- Autogen status: attached to [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md) after the enum page and direct class parent both cleared the strict `85/85` gate in the 2026-06-11 A005 Batch 174 recheck.

## Values

| Value | Decimal | FourCC display | Proposed name | Payload | Worker behavior |
| --- | --- | --- | --- | --- | --- |
| `0x42446972` | `1111779698` | `BDir` | `BrowseDirectory` / `kMiscWorkBrowseDirectory` | Heap ANSI title string | Shows shell folder picker and posts [UID:000012][brdir__Notification](by-class/brdir__Notification.md) on the same numeric channel, best named `kBrowseDirectoryNotification` when split from worker-request ids. |
| `0x47654874` | `1197820020` | `GeHt` | `GetHttp` | One heap `SimpleUString` URL | Calls `FetchHTTPContent`, then destroys the string wrapper. |
| `0x4e434175` | `1313030517` | `NCAu` | `NcaUpdate` | Two adjacent heap `SimpleUString` values | Calls `ProcessNCAUpdate`, then destroys both string wrappers. |

The decimal/hex pairs above were verified with `int_convert.py` on 2026-06-11. The tool reports little-endian ASCII byte order (`riDB`, `tHeG`, `uACN`), while the `FourCC display` column keeps the source-facing big-endian spelling used by the existing switch constants and comments.

## Notes

- The message ids are passed through [UID:0000EV][Thread](by-class/Thread.md) async queue helper `0x00596960`.
- Unknown message ids fall back to `Thread::OnMessage`.
- Posted notification channels are not identical for every request: HTTP posts `0x68747470` (`http`), NCA posts `0x4e634175`, and browse-directory reposts `0x42446972`.
- Producer coverage is now complete for the three currently observed ids: `0x00528290` submits `GetHttp`, `0x00528310` submits `NcaUpdate`, and raw/no-function bytes at `0x005283b0` submit `BrowseDirectory`.
- For browse-directory, B011 reanalysis confirms the same `0x42446972` value appears in retained request wrapper queueing, the live `ProcessWorkItem` dispatch compare/post path, the retained browse helper post, and [UID:0003MG][0x00529c60-0x00529cf8.MusicControlDialogDirectoryPacketHandler](by-memory/0x00529c60-0x00529cf8.MusicControlDialogDirectoryPacketHandler.md) consumption. If reconstruction splits worker-request ids from posted application-notification ids, keep the same numeric value with separate names `kMiscWorkBrowseDirectory` and `kBrowseDirectoryNotification`.

## IDA MCP Evidence

- 2026-05-31 IDA MCP decompilation of `0x00527fe0` shows a `switch (a2)` with cases `1111779698`, `1197820020`, and `1313030517`.
- Case `1111779698` initializes COM, shows the shell folder picker, creates a `brdir::Notification`, posts it with the same `1111779698` channel, hides the cursor, uninitializes COM, and frees the heap title string.
- Case `1197820020` converts the heap string payload and calls `0x005277c0` (`FetchHTTPContent`), then destroys the string wrapper and payload block.
- Case `1313030517` calls `0x00527bb0` (`ProcessNCAUpdate`) with two adjacent string wrappers, then destroys both wrappers and the payload block.
- The default branch forwards to `0x00596920`, matching the inherited thread-message fallback.
- 2026-06-11 A005 Batch 174 live IDA MCP recheck:
  - `0x00527fe0-0x005281a1` still decompiles as a switch over `a2` with cases `1111779698`, `1197820020`, and `1313030517`, plus default `0x00596920`.
  - `0x00528290-0x00528304` allocates one `SimpleUString` wrapper and calls `0x00596960(this, 1197820020, payload, 0)`.
  - `0x00528310-0x005283a6` allocates two adjacent `SimpleUString` wrappers and calls `0x00596960(this, 1313030517, payload, 0)`.
  - Raw/no-function bytes at `0x005283b0-0x005283d5` call `__strdup`, push `0x42446972`, and call `0x00596960`.
  - `int_convert.py` verified `0x42446972 == 1111779698`, `0x47654874 == 1197820020`, `0x4e434175 == 1313030517`, `0x68747470 == 1752462448`, and `0x4e634175 == 1315127669`.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 86 | The page now records all observed worker message values, decimal/hex verification, payload ownership, worker behavior, notification channel differences, default fallback, and all three producer paths including the raw browse-directory submitter. |
| Confidence | 90 | Live IDA decompilation and disassembly strongly support the enum membership and direct [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md) ownership. Confidence stays below final-audit quality because original symbol spellings may have been macros/constants rather than a literal enum and final source names remain provisional. |

## Open Questions

- The FourCC-like values are strong, but final source spelling may have used macros or constants rather than an enum.
- Submission call sites still need a full pass before the message names are considered final.
- The browse-directory producer remains raw/no-function in IDA, so its body is documented from disassembly rather than a modeled function object.

## Formal Source Enum

2026-07-01 B008 empty-emitter family implementation promotes this page from a blank marker to the source-facing request-id enum emitted under [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md). The names remain descriptive/inferred rather than recovered original symbols, but the values, payload ownership, producer paths, and worker switch are strong enough for first-draft formal C++. [UID:0001CJ][0x005277c0-0x005285dd.MiscWorkThreadAndNotifications](by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md) no longer needs to duplicate this enum.

## Cross-References

- [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md)
- [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md)
- [UID:0001CJ][0x005277c0-0x005285dd.MiscWorkThreadAndNotifications](by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md)

## Changes

- 2026-06-11 A005 Batch 174:
  - Changed from: `COMPLETION:74`, `CONFIDENCE:88`, `AUTOGEN_PARENT_UID:` blank.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:90`, `AUTOGEN_PARENT_UID:00008I`.
  - Evidence: live IDA MCP rechecked `ProcessWorkItem` switch cases, modeled HTTP/NCA request producers, raw browse-directory request bytes, `Thread` queue fallback, and value conversions through `int_convert.py`. The direct [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md) parent was refreshed to `85/85`, satisfying the strict child+parent gate.
- 2026-06-21 Rule 26 incorporation of B011 brdir notification source-quality report:
  - Score unchanged at `86/90`.
  - Evidence: added the browse-directory request/notification naming distinction and the complete `0x42446972` evidence chain across raw wrapper queueing, `ProcessWorkItem` dispatch/posting, retained helper posting, and MusicControlDialog consumption.
- 2026-07-01 B008 empty-emitter family implementation:
  - Changed from `COMPLETION:86`, `CONFIDENCE:90`, blank formal C++.
  - Changed to `COMPLETION:88`, `CONFIDENCE:91`, with formal `MiscWorkThreadMessageId` enum C++.
  - Summary/evidence: B008 live IDA MCP reconfirmed `ProcessWorkItem` cases `1111779698`, `1197820020`, and `1313030517`; HTTP/NCA request wrappers dispatch through `Thread` helper `0x00596960`; raw `0x005283b0` remains a no-xref retained `BDir` wrapper. Exact original spelling remains inferred but no longer blocks first-draft source emission.
