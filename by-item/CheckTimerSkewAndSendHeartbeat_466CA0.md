*** UID:0000U8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# CheckTimerSkewAndSendHeartbeat 0x00466ca0

## Status

- Confidence: strong for boundary, behavior, and Application message-loop caller; medium for final source-facing name and placement.
- Exact memory range: [UID:0000YT][0x00466ca0-0x004670ad.CheckTimerSkewAndSendHeartbeat](by-memory/0x00466ca0-0x004670ad.CheckTimerSkewAndSendHeartbeat.md)
- Likely source family: [UID:0000HG][Application](by-file/Application.md) message-loop timing, with [UID:0000NS][Socket](by-file/Socket.md) packet-sender and diagnostics dependencies.
- Autogen parent: [UID:0000HG][Application](by-file/Application.md).
- Evidence basis: IDA MCP decompilation on 2026-05-24 plus IDA MCP boundary/xref/callee/data-reference rechecks on 2026-05-26 and 2026-05-30.

## Behavior

`0x00466ca0` checks several time sources for repeated skew and sends a small heartbeat/status packet from the application message-loop maintenance path. When time skew is detected repeatedly, it formats a diagnostic text record and calls the crash/diagnostic text helper at [UID:00014E][0x004ab740-0x004ab804.CrashDiagnosticTextSender](by-memory/0x004ab740-0x004ab804.CrashDiagnosticTextSender.md).

The heartbeat packet branch is guarded by the packet sender, a session/object pointer at [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) / historical `dword_67A748`, and the connection-closed/reconnect dialog singleton fields in [UID:00029B][0x0067ab54-0x0067ab84.ApplicationDialogTimerAndBackgroundGlobals](by-memory/0x0067ab54-0x0067ab84.ApplicationDialogTimerAndBackgroundGlobals.md). It initializes a packet buffer, writes first byte `0x60`, mixes `GetTickCount()` and `rand()` bytes, appends obfuscated/randomized bytes derived from `g_pCollectionData + 0x1a0`, then queues 11 bytes through [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md).

## Evidence

- IDA decompilation compares `timeGetTime`, `GetTickCount`, `_time64`, and `GetSystemTimeAsFileTime` elapsed seconds.
- After repeated skew, it formats a text record containing a key/config value, elapsed time values, and OS string data, then calls `0x004ab740`.
- The heartbeat branch calls packet-writing helpers and sends opcode-like first byte `0x60`.
- IDA xrefs to static guard globals around `0x0067ab5c-0x0067ab68` show this function owns local static tick values.
- IDA MCP on 2026-05-26 confirms the exact function boundary `0x00466ca0-0x004670ad`, with exactly one direct caller at `0x00464d26` inside `Application::RunMessageLoop`.
- The heartbeat branch reads [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) and queues the packet through [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md) at call site `0x00467032`.
- IDA MCP recheck on 2026-05-30 reconfirmed the same boundary/caller and showed calls to `timeGetTime`, `GetTickCount`, `_time64`, `GetSystemTimeAsFileTime`, `__aulldiv`, diagnostic formatter `0x00443a00`, diagnostic sender `0x004ab740`, packet setup `0x00574b30`, byte writer `0x00575380`, queue/send `0x00574bb0`, `_rand`, and MSVC local-static guard helpers.
## Ownership Notes

Do not attach this directly to [UID:00004P][ExceptionHandler](by-class/ExceptionHandler.md), [UID:0000I6][CheatDetector](by-file/CheatDetector.md), [UID:0000NS][Socket](by-file/Socket.md), or [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md). It consumes crash diagnostics and packet-send infrastructure, but the verified caller evidence points to [UID:0000HG][Application](by-file/Application.md) message-loop timing ownership.

## Cross-References

- [UID:0001QB][client_crash_diagnostics](by-meta/client_crash_diagnostics.md)
- [UID:0000YT][0x00466ca0-0x004670ad.CheckTimerSkewAndSendHeartbeat](by-memory/0x00466ca0-0x004670ad.CheckTimerSkewAndSendHeartbeat.md)
- [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md)
- [UID:0000NS][Socket](by-file/Socket.md)
- [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md)
- [UID:0001HT][0x00574b90-0x00575377.CashShopRequestSendQueue](by-memory/0x00574b90-0x00575377.CashShopRequestSendQueue.md)
- [UID:0001QU][client_timing](by-meta/client_timing.md)

## Changes

- 2026-06-07: Replaced the raw `dword_67A748` heartbeat-session reference with canonical [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) wording.
  - Before: the heartbeat branch described its session/object guard and `+0x1a0` byte source only through the historical generated name.
  - After: the page links the resolved collection-data global while retaining the historical label for traceability.
  - Evidence: the generated resolved-name report maps `dword_67A748` to `g_pCollectionData`, and this page's existing packet evidence ties the dereference to the heartbeat branch's session/object data.

- 2026-06-05: Reconstructable metadata changed from blank to `TRUE`, attached to [UID:0000HG][Application](by-file/Application.md), and stale generated-file caveat wording was removed.
  - Before: the heartbeat/timer-skew helper was documented but unclassified in autogen coverage.
  - After: it is marked as NexusTK-owned application message-loop source under the validated Application file root; C++ remains blank because final helper naming, packet-field names, and local static names are not at the 95/95 final-code bar.
  - Evidence: live IDA MCP confirms `sub_466CA0` at `0x00466ca0`, size `0x40d`, with one direct caller at `0x00464d26` inside the application message-loop function and callees matching the documented clock, diagnostic, packet-write, and queue/send behavior.

- 2026-05-30: Grading changed from unevaluated `0/0` to `82/88`.
  - Before: page summarized the helper but did not carry completion/confidence scoring and used broader non-IDA provenance wording.
  - After: page records the current IDA-backed function boundary, caller, packet construction, and gating globals.
  - Evidence: IDA MCP recheck confirmed the exact range, sole `Application::RunMessageLoop` caller, clock-source calls, diagnostic helper calls, packet writer/queue calls, and timing/global data references.
