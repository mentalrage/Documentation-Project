*** UID:0000U8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# CheckTimerSkewAndSendHeartbeat 0x00466ca0

## Status

- Confidence: strong for boundary, behavior, and Application message-loop caller; medium for final source-facing name and placement.
- Exact memory range: [UID:0000YT][0x00466ca0-0x004670ad.CheckTimerSkewAndSendHeartbeat](by-memory/0x00466ca0-0x004670ad.CheckTimerSkewAndSendHeartbeat.md)
- Likely source family: [UID:0000HG][Application](by-file/Application.md) message-loop timing, with [UID:0000NS][Socket](by-file/Socket.md) packet-sender and diagnostics dependencies.
- Owner/emitter: [UID:0000HG][Application](by-file/Application.md).
- Evidence basis: IDA MCP decompilation on 2026-05-24 plus IDA MCP boundary/xref/callee/data-reference rechecks on 2026-05-26 and 2026-05-30.

## Behavior

`0x00466ca0` checks several time sources for repeated skew and sends a small heartbeat/status packet from the application message-loop maintenance path. When time skew is detected repeatedly, it formats a diagnostic text record and calls the crash/diagnostic text helper at [UID:00014E][0x004ab740-0x004ab804.CrashDiagnosticTextSender](by-memory/0x004ab740-0x004ab804.CrashDiagnosticTextSender.md). B013 rechecked that call and found the source-call shape `ECX = g_pCrashTarget`, explicit argument = formatted ANSI text buffer, then call `0x004ab740`, so this item remains the Application-owned formatter/caller while the sender itself is now modeled as `ExceptionHandler::SendCrashDiagnosticText(const char *)`.

The heartbeat packet branch is guarded by the packet sender, source-facing `g_pUserPane` / stable alias [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) / historical `dword_67A748`, and the connection-closed/reconnect dialog singleton fields in [UID:00029B][0x0067ab54-0x0067ab84.ApplicationDialogTimerAndBackgroundGlobals](by-memory/0x0067ab54-0x0067ab84.ApplicationDialogTimerAndBackgroundGlobals.md). It initializes a packet buffer, writes first byte `0x60`, mixes `GetTickCount()` and `rand()` bytes, appends obfuscated/randomized bytes derived from the heartbeat/session byte at `g_pUserPane + 0x1a0`, then queues 11 bytes through [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md).

## Evidence

- IDA decompilation compares `timeGetTime`, `GetTickCount`, `_time64`, and `GetSystemTimeAsFileTime` elapsed seconds.
- After repeated skew, it formats a text record containing a key/config value, elapsed time values, and OS string data, then calls `0x004ab740`.
- The heartbeat branch calls packet-writing helpers and sends opcode-like first byte `0x60`.
- IDA xrefs to static guard globals around `0x0067ab5c-0x0067ab68` show this function owns local static tick values.
- IDA MCP on 2026-05-26 confirms the exact function boundary `0x00466ca0-0x004670ad`, with exactly one direct caller at `0x00464d26` inside `Application::RunMessageLoop`.
- The heartbeat branch reads [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) and queues the packet through [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md) at call site `0x00467032`.
- IDA MCP recheck on 2026-05-30 reconfirmed the same boundary/caller and showed calls to `timeGetTime`, `GetTickCount`, `_time64`, `GetSystemTimeAsFileTime`, `__aulldiv`, diagnostic formatter `0x00443a00`, diagnostic sender `0x004ab740`, packet setup `0x00574b30`, byte writer `0x00575380`, queue/send `0x00574bb0`, `_rand`, and MSVC local-static guard helpers.
- 2026-06-14 live IDA MCP session `a001_goal2_class_batch` reconfirmed `0x00466ca0` size `0x40d` with exactly one direct xref at `0x00464d26` inside `sub_464CD0` (`0x00464cd0`, size `0x14f`).
- `analyze_function 0x00466ca0` reports one caller, 14 callees, and diagnostic strings including `[Key:%08x]`, `unknown key`, and the formatted skew report string.
- Targeted decompilation reconfirmed sampling from `timeGetTime`, `GetTickCount`, `_time64`, and `GetSystemTimeAsFileTime`; diagnostic sending through `0x004ab740`; the heartbeat gate using `GetTickCount() > lastTick + 30000`, where `30000 == 0x7530` was verified with `int_convert.py`; and final queue/send through `0x00574bb0` with send length `11 == 0x0b` verified with `int_convert.py`.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 86 | The page now ties the item index to the stronger exact memory page, current live boundary/xref evidence, timing-source checks, diagnostic path, heartbeat packet length/gate, packet sender route, and Application owner/emitter route. |
| Confidence | 90 | IDA repeatedly confirms the sole Application message-loop caller, exact function boundary, timing/diagnostic/packet callees, and static/global dependencies. Confidence remains below final-source quality because the source-facing helper name, local static names, and packet-field names remain provisional. |

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

## 2026-06-29 B013 Duplicate Index Repair

- B013 implements the accepted duplicate/index route repair: this by-item page is now non-emitting while UID0000YT remains the exact by-memory source/no-code decision page.
- Metadata is `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:0000HG`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank formal C++.
- This page remains a search/index alias for `0x00466ca0`; it must not duplicate UID0000YT's timer/heartbeat proof marker or any future exact body.

Implementation validator: run `python .\tools\validator.py --mode file --file by-item/CheckTimerSkewAndSendHeartbeat_466CA0.md --apply --queue-timeout 240` from `source-3/project-documentation`.

## Changes

- 2026-06-07: Replaced the raw `dword_67A748` heartbeat-session reference with canonical [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) wording.
  - Before: the heartbeat branch described its session/object guard and `+0x1a0` byte source only through the historical generated name.
  - After: the page links the resolved collection-data global while retaining the historical label for traceability.
  - Evidence: the generated resolved-name report maps `dword_67A748` to `g_pCollectionData`, and this page's existing packet evidence ties the dereference to the heartbeat branch's session/object data.

- 2026-06-05: Reconstructable metadata changed from blank to `TRUE`, attached to [UID:0000HG][Application](by-file/Application.md), and stale generated-file caveat wording was removed.
  - Before: the heartbeat/timer-skew helper was documented but unclassified in autogen coverage.
  - After: at that time it was marked as NexusTK-owned application message-loop source under the validated Application file root. This is superseded by the 2026-06-29 B013 duplicate/index repair above: the exact source/no-code decision now lives on UID0000YT, and this by-item page is non-emitting index metadata.
  - Evidence: live IDA MCP confirms `sub_466CA0` at `0x00466ca0`, size `0x40d`, with one direct caller at `0x00464d26` inside the application message-loop function and callees matching the documented clock, diagnostic, packet-write, and queue/send behavior.

- 2026-05-30: Grading changed from unevaluated `0/0` to `82/88`.
  - Before: page summarized the helper but did not carry completion/confidence scoring and used broader non-IDA provenance wording.
  - After: page records the current IDA-backed function boundary, caller, packet construction, and gating globals.
  - Evidence: IDA MCP recheck confirmed the exact range, sole `Application::RunMessageLoop` caller, clock-source calls, diagnostic helper calls, packet writer/queue calls, and timing/global data references.
- 2026-06-14 A001: Raised from `82/88` to `86/90`.
  - Before: the item page lagged behind the stronger exact memory page and still used legacy parent/final-code wording.
  - After: added current live IDA evidence, explicit score rationale, current owner/emitter terminology, and verified heartbeat interval/packet length constants.
  - Evidence: `lookup_funcs`, `analyze_function`, `xrefs_to`, and targeted decompile checks reconfirmed the exact `0x40d` boundary, sole message-loop xref, diagnostic strings/callees, timing-source sampling, `0x7530` heartbeat gate, and `0x0b` queue/send length.
- 2026-06-22 Rule 26 support sync from B001 [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md):
  - Updated the heartbeat packet dependency to source-facing `g_pUserPane` while retaining [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) and raw `dword_67A748` as aliases.
  - Preserved Application ownership for the timer/heartbeat helper; `g_pUserPane + 0x1a0` is only a consumed UserPane/local-player heartbeat-session byte.
