** TARGET-REPORT-UID:00014E **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00014E CrashDiagnosticTextSender Source-Quality Report

Agent: B005
Target: `source-3/project-documentation/by-memory/0x004ab740-0x004ab804.CrashDiagnosticTextSender.md`
Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B005/research/00014E-CrashDiagnosticTextSender-source-quality.md`

## Finalized Report / Current Recommendation

- Current recommendation: update [UID:00014E] from `84/90` to `86/91`, replace the pending-code wording with first-draft source C++, and reroute the direct owner/emitter from the `ExceptionHandler` class [UID:00004P] to the source file [UID:0000J8] `ExceptionHandler.cpp`.
- Final disposition: source-authored file-static crash/diagnostic packet helper, not a class member, not an Application timing helper, not Socket/PacketBuffer ownership, and not compiler/runtime code.
- Required action after supervisor review: implementation callback should edit only the accepted target/support docs, then run scoped validator apply. Do not edit `by-memory/-coverage-report.md`; exact replacement text is included below.
- Confidence: high for exact behavior, protocol layout, reachability, source file, and helper dependencies; medium-high for exact original helper/API spelling.

## Target

- Target UID: `00014E`
- Target path: `by-memory/0x004ab740-0x004ab804.CrashDiagnosticTextSender.md`
- Current metadata: `COMPLETION:84`, `CONFIDENCE:90`, `CANONICAL_OWNER:00004P`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00004P`, formal C++ blank.
- Current generated route: `00014E -> 00004P -> 0000J8 -> auto-generated/NexusTK/platform/ExceptionHandler.cpp`.
- Recommended generated route: `00014E -> 0000J8 -> auto-generated/NexusTK/platform/ExceptionHandler.cpp`.
- Current coverage row: `84% : strong`, exact row replacement below.

## Evidence Checked

Primary target/support docs:

- `by-memory/0x004ab740-0x004ab804.CrashDiagnosticTextSender.md`
- `by-memory/0x004ab480-0x004ac89a.ExceptionHandler.md`
- `by-class/ExceptionHandler.md`
- `by-file/ExceptionHandler.md`
- `by-meta/client_crash_diagnostics.md`
- `by-memory/0x00466ca0-0x004670ad.CheckTimerSkewAndSendHeartbeat.md`
- `by-item/CheckTimerSkewAndSendHeartbeat_466CA0.md`

Protocol/network/helper docs:

- `by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md`
- `by-memory/0x00575380-0x00575abb.PacketBufferHelpers.md`
- `by-file/PacketBuffer.md`
- `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md`
- `by-global/g_packetSender.md`
- `by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md`
- `by-file/Socket.md`
- `by-memory/0x00516030-0x00516036.GetMemoryMan.md`
- `by-memory/0x00516220-0x00516238.MemmoveWrapper.md`

Prior B-report and generated/project evidence:

- `tools/leaser/Agents/Agent-B005/research/executed/00014D-ExceptionHandler-source-quality.md`
- `tools/leaser/Agents/Agent-B005/research/executed/000259-ExceptionHandlerDiagnosticsReadOnlyData-source-quality.md`
- `project-level/-auto-completion-stats.md`
- `project-level/-unresolved.md`
- `project-level/-resolved.md`
- `project-level/-resolved-multple-aliases.md`
- `auto-generated/-ag-memory-coverage.md`
- `by-memory/-coverage-report.md`
- local cached function export `source-3/core/data/cache/prewave/functions/0x004ab740.json`
- readonly exported function `source-3/core/data/readonly/prewave/exported-functions/0x004ab740.json`

Live IDA MCP was checked and unavailable in this session:

> Executable block R001 was removed from this report and preserved verbatim in [00014E-CrashDiagnosticTextSender-source-quality-removed.md](00014E-CrashDiagnosticTextSender-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

This report therefore relies on current by-* pages containing prior live-IDA evidence, local cached IDA/Ghidra function export, generated coverage reports, and source-quality support docs. No Wave2/Wave3 source output or simroot source was used as authority.

Number conversions used in this report were checked with `tools/int_convert.py`:

- `0xfff` = 4095
- `0xffe` = 4094
- `0xc4` = 196
- `0x42` = 66 / ASCII `B`
- `0x1000` = 4096
- `0x1004` = 4100

## Cached Function Facts

The cached function export for `0x004ab740` agrees with the target page:

- IDA preferred name: `sub_4AB740`
- IDA signature: `int __stdcall(char *Src)`
- Ghidra signature: `undefined __stdcall FUN_004ab740(uint *param_1)`
- Size: `0xc4` / 196 bytes
- Caller count: one
- Caller: `0x00466e80` inside `0x00466ca0-0x004670ad.CheckTimerSkewAndSendHeartbeat`
- Callees: `__alloca_probe`, `0x00516030`, `0x00575380`, `0x005753a0`, `0x00516220`, `0x00574bb0`, and `__security_check_cookie`
- IDA xref-to: only `CALL_NEAR` from `0x00466e80`

IDA decompilation shape from the local export:

```c
int __stdcall sub_4AB740(char *Src)
{
  unsigned int length = strlen(Src);
  int result = length - 1;
  if (length - 1 <= 0xFFE) {
    sub_575380(66, &packet[0]);
    sub_575380(1, &packet[1]);
    sub_5753A0(length, &packet[2]);
    sub_516220(&packet[4], Src, length);
    sub_575380(0, &packet[length + 4]);
    return sub_574BB0(dword_67A7EC, packet, length + 5);
  }
  return result;
}
```

Ghidra recovers the same operation but types the argument as `uint *` because the byte-scan loop is decompiled through dword locals. The IDA `char *Src` type and caller-side `sprintf_s` ANSI buffer are the better source-facing input type.

## Behavior And Protocol

The helper does not construct the human-readable timer-skew diagnostic string itself. Its only known caller, [UID:0000YT] `CheckTimerSkewAndSendHeartbeat`, formats the message first with key/timing/OS data, then calls this helper. This target's job is to packetize and send the already-built ANSI text.

Source behavior:

- Touches the MemoryMan singleton/context through `0x00516030`.
- Computes `strlen(text)`.
- Accepts only byte lengths `1..0xFFF` / `1..4095` (Verified with `int_convert.py`).
- Rejects the empty string and any string of length `0x1000` / 4096 bytes or greater. It does not truncate long strings.
- Writes packet opcode `0x42` / 66 / ASCII `B` (Verified with `int_convert.py`).
- Writes subtype byte `1`.
- Writes the original text length as a two-byte big-endian integer.
- Copies the raw ANSI bytes exactly, without UTF-16 conversion or escaping.
- Appends a zero terminator byte after the payload.
- Sends exactly `length + 5` bytes through `g_packetSender`.
- At maximum payload, sends `0x1004` / 4100 bytes (Verified with `int_convert.py`).

Packet layout:

| Offset | Source-facing writer | Meaning |
| --- | --- | --- |
| `0` | `PacketBufferWriteUInt8(0x42, packet)` | Crash/diagnostic packet opcode |
| `1` | `PacketBufferWriteUInt8(1, packet + 1)` | Diagnostic text subtype |
| `2..3` | `PacketBufferWriteUInt16BE(length, packet + 2)` | ANSI payload byte length, excluding trailing zero |
| `4..length+3` | `MemmoveWrapper(packet + 4, text, length)` | Raw ANSI diagnostic bytes |
| `length+4` | `PacketBufferWriteUInt8(0, packet + length + 4)` | Sent zero terminator |
| `length+5` | side effect of `PacketBufferWriteUInt8` | Extra scratch/safety zero, not included in send length |

The target page currently says the trailing zero is included in the send length. That is correct for the byte at `length + 4`. The PacketBuffer byte writer also clears one spare byte after the written byte; for the final terminator this creates an extra scratch zero at `length + 5`, which is outside the counted send length. A source buffer of `0x1005` bytes is therefore the best first-draft size: it holds the maximum counted packet (`0x1004` bytes) plus the PacketBuffer writer's spare zero.

## Source-Quality Names And Signatures

Recommended target/source name:

```text
SendCrashDiagnosticText
```

Recommended first-draft source signature:

```cpp
static void __stdcall SendCrashDiagnosticText(const char *text)
```

Rationale:

- `SendCrashDiagnosticText` matches the established B005 [UID:00014D] ExceptionHandler report and this helper's exact role.
- `CrashDiagnosticTextSender` is acceptable as the documentation filename/title, but source C++ should use a verb phrase.
- `const char *text` is better than generated `char *Src` or Ghidra's `uint *param_1`; the function reads an ANSI buffer and never mutates it.
- `__stdcall` is supported by the recovered signature and the one-stack-argument helper pattern used by nearby packet helpers.
- `void` is the best source-facing return type. IDA's `int` is a decompiler artifact from EAX carrying the comparison value on reject or the queue-send result on accept. The only known caller ignores the return value, and the source behavior is send-or-drop.

Acceptable fallback if the implementation pass prioritizes ABI literalism over source-facing clarity:

```cpp
static int __stdcall SendCrashDiagnosticText(const char *text)
```

That fallback should be documented as ABI-preserving but source-semantically weaker. I do not recommend it for final source unless another caller is found that consumes the return.

Rejected names and shapes:

- `FUN_004ab740`, `sub_4AB740`, `Src`, `param_1`: raw/generated names only.
- `CrashDiagnosticTextSender` as a function name: descriptive page label, but not likely original source style.
- `ExceptionHandler::SendCrashDiagnosticText`: rejected because the body has no `this`, no object field access, and one stack argument.
- `Application::SendCrashDiagnosticText`: rejected because Application is only the observed timing-diagnostic caller.
- `Socket::SendCrashDiagnosticText` or PacketBuffer ownership: rejected because Socket/PacketBuffer provide dependencies, not this diagnostic policy helper.
- `CashShopRequest::meth_0x574bb0` / generated CashShop route: rejected. The current source-quality docs resolve `0x00574bb0` as Socket-owned `QueueAndSendPacket`, and `dword_67A7EC` as `g_packetSender`.

## Helper / Global / Type Name Resolution

Use these names in target/support documentation:

| Raw/generated name | Recommended source-facing name | Evidence |
| --- | --- | --- |
| `0x00516030`, `sub_516030`, `FUN_00516030` | `GetMemoryMan()` | [UID:0001BC] singleton accessor for `g_pMemoryMan`. |
| `0x00575380`, `sub_575380`, `FUN_00575380`, `WriteByteZ_575380` | `PacketBufferWriteUInt8` | [UID:0003YJ] scalar PacketBuffer byte writer. |
| `0x005753a0`, `sub_5753A0`, `FUN_005753a0`, `WriteUInt16BEZ_5753A0` | `PacketBufferWriteUInt16BE` | [UID:0003YJ] two-byte big-endian writer. |
| `0x00516220`, `sub_516220` | `MemmoveWrapper` or final MemoryMan copy helper | [UID:0001BH] direct wrapper around `memmove`. |
| `0x0067a7ec`, `dword_67A7EC` | `g_packetSender` | [UID:0000Q5]/[UID:0001P0], best current type `Socket *`. |
| `0x00574bb0`, `sub_574BB0`, generated `CashShopRequest::meth_0x574bb0` | `Socket::QueueAndSendPacket` / `QueueAndSendPacket` | [UID:0001HU], Socket-owned queue-send wrapper consumed by Socket command `8`. |

Use descriptive helper names, not raw address names, in the C++ draft. The exact original PacketBuffer and MemoryMan helper spellings remain inferred, but the current support docs are strong enough for first-draft source.

## Ownership And Source Placement

### Accepted: [UID:0000J8] `ExceptionHandler.cpp`

Decision: recommended direct canonical owner and emitter for [UID:00014E].

Evidence for:

- The accepted [UID:00014D] B005 report classifies this as a file-static diagnostics helper in `platform/ExceptionHandler.cpp`.
- The function is physically inside the ExceptionHandler crash-diagnostics cluster between the stored `BCrash.nfo` sender and raw report-text setter.
- It sends the same opcode/subtype family as the stored crash-report upload helper at `0x004ab510`.
- The source-tree page explicitly lists `ExceptionHandler.cpp` as owning the diagnostic text packet helper at `0x004ab740`.
- The by-file route is above gate: [UID:0000J8] is `87/88` and stages to `auto-generated/NexusTK/platform/ExceptionHandler.cpp`.
- Direct file ownership avoids implying a member function when the body has no `this`.

Evidence against:

- The only ordinary caller is Application timing, not ExceptionHandler code.
- The body uses PacketBuffer/Socket dependencies.

Decision: those are caller/dependency signals, not ownership. Keep it in `platform/ExceptionHandler.cpp`.

### Tolerable But Weaker: [UID:00004P] `ExceptionHandler` Class

Current metadata uses [UID:00004P]. This is output-valid because the class routes to [UID:0000J8], but it is source-semantically weaker for this exact target.

Evidence for:

- This helper belongs to the same crash-diagnostics family as the class.
- Existing child pages in the ExceptionHandler cluster often route through [UID:00004P] or [UID:00014D].

Evidence against:

- This function has no receiver and no class field access.
- The best source signature is file-static, not a member.

Decision: change the direct target metadata to [UID:0000J8] in the implementation pass unless the supervisor intentionally keeps the older class-through route for consistency. If the supervisor keeps [UID:00004P], still enter the same file-static C++ and document why the helper is not a member.

### Rejected Owners

- [UID:0000HG] `Application`: owns the timer-skew caller, not the diagnostic sender.
- [UID:0000NS]/[UID:0000DD] `Socket`: owns `g_packetSender` and queue-send transport, not diagnostic packet policy.
- [UID:0000M8] `PacketBuffer`: owns scalar writers, not this packet-specific helper.
- [UID:0000I0]/[UID:00001H] `CashShopRequest`: stale generated-name pollution for `0x00574bb0`; not a source owner here.
- New `CrashDiagnostics.cpp`: rejected by the accepted [UID:00014D] report and current source-tree notes. There is no independent initializer, source-path evidence, or non-ExceptionHandler helper cluster strong enough to create a new file.

## Recommended Metadata

Exact recommended metadata:

```text
COMPLETION:86
CONFIDENCE:91
CANONICAL_OWNER:0000J8
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000J8
```

Before/after:

- Before: `84/90`, owner/emitter [UID:00004P].
- After: `86/91`, owner/emitter [UID:0000J8].
- Average after update: `88.5`.

Rationale:

- Completion rises because the source-facing signature, file-static placement, helper/global names, packet-buffer size behavior, protocol layout, and first-draft C++ are now resolved.
- Confidence rises because target docs, PacketBuffer/Socket support docs, the accepted [UID:00014D] B report, proposed source tree, and cached IDA export all agree on behavior and route.
- Confidence stays below final-audit level because exact original helper spelling and final PacketBuffer/MemoryMan helper API names remain inferred.

## Recommended First-Draft C++

Recommended target C++ block:

```cpp
static void __stdcall SendCrashDiagnosticText(const char *text)
{
    GetMemoryMan();

    const unsigned int length = static_cast<unsigned int>(strlen(text));
    if (length == 0 || length >= 0x1000) {
        return;
    }

    unsigned char packet[0x1005];

    PacketBufferWriteUInt8(0x42, packet);
    PacketBufferWriteUInt8(1, packet + 1);
    PacketBufferWriteUInt16BE(static_cast<unsigned short>(length), packet + 2);
    MemmoveWrapper(packet + 4, text, length);
    PacketBufferWriteUInt8(0, packet + length + 4);

    g_packetSender->QueueAndSendPacket(packet, static_cast<short>(length + 5));
}
```

Implementation notes:

- Do not add null checks for `text` or `g_packetSender`; the binary has none.
- Do not truncate overlong strings; the binary drops them after `strlen`.
- Keep the trailing zero in the sent length.
- Keep the `0x1005` local size unless the PacketBuffer write helper is inlined differently; it accounts for the maximum counted packet plus the writer's extra scratch zero.
- If final helper declaration policy does not yet expose `MemmoveWrapper`, the implementation callback may use the documented MemoryMan copy-helper spelling accepted by the supervisor. Do not use raw `sub_516220`.
- If the project later standardizes PacketBuffer helpers as `WriteByteZ_575380`/`WriteUInt16BEZ_5753A0`, update the code then. For source-quality output, `PacketBufferWriteUInt8` and `PacketBufferWriteUInt16BE` are clearer.

## Recommended Exact Target Doc Changes

Replace the current status/code sentence:

```text
- Final C++ is pending exact child-body source entry under the active combined-score/emitter gate. The old `95/95` threshold is obsolete. This child should receive C++ only on its own exact page or through a valid child insertion route, not through a monolithic [UID:00014D][0x004ab480-0x004ac89a.ExceptionHandler](by-memory/0x004ab480-0x004ac89a.ExceptionHandler.md) aggregate body.
```

with:

```text
- Final C++ is ready for this exact child page under the active combined-score/emitter gate. The source-facing shape is a file-static `SendCrashDiagnosticText(const char *)` helper in [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md), not an `ExceptionHandler` member and not a monolithic [UID:00014D][0x004ab480-0x004ac89a.ExceptionHandler](by-memory/0x004ab480-0x004ac89a.ExceptionHandler.md) aggregate body.
```

Add this source-quality note:

```text
Source-quality note: use `static void __stdcall SendCrashDiagnosticText(const char *text)`. IDA's `int` return is not a source contract; the only known caller ignores EAX, and the observed return values are the byproduct of the length compare or the queue-send call. The helper is file-static because it has no `this` pointer and does not access `ExceptionHandler` fields.
```

Add this helper-name note:

```text
Resolved helper/global names: `0x00575380` is `PacketBufferWriteUInt8`, `0x005753a0` is `PacketBufferWriteUInt16BE`, `0x00516220` is the MemoryMan `MemmoveWrapper`, `0x0067a7ec` is `g_packetSender` with best current type `Socket *`, and `0x00574bb0` is Socket-owned `QueueAndSendPacket`. Reject generated `CashShopRequest::meth_0x574bb0` and raw `dword_67A7EC` names for final source.
```

Add or update protocol detail:

```text
The final `PacketBufferWriteUInt8(0, packet + length + 4)` writes the sent zero terminator at `length + 4` and also clears the writer's scratch byte at `length + 5`; only `length + 5` bytes are sent. A source buffer of `0x1005` bytes covers the maximum accepted payload (`0xFFF` / 4095 bytes, Verified with `tools/int_convert.py`), maximum send length (`0x1004` / 4100 bytes, Verified with `tools/int_convert.py`), and the extra scratch zero.
```

Update ownership wording:

```text
Ownership recommendation: use [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md) as direct `CANONICAL_OWNER` and `EMITTER_UIDS`. [UID:00004P][ExceptionHandler](by-class/ExceptionHandler.md) remains the crash-handler class context, but this helper is file-static source in `platform/ExceptionHandler.cpp`.
```

Optional support-doc sync for later implementation callback:

- `by-meta/client_crash_diagnostics.md`: close the open question about [UID:00014E] ownership by stating it is best treated as a file-static `ExceptionHandler.cpp` helper called by Application timer-skew diagnostics.
- `by-file/ExceptionHandler.md`: update the likely-contents bullet for [UID:00014E] from "packet helper" to "file-static `SendCrashDiagnosticText(const char *)` packet helper".
- `by-class/ExceptionHandler.md`: keep [UID:00014E] as related helper context, but avoid listing it as an `ExceptionHandler` member method.
- `by-memory/0x00466ca0-0x004670ad.CheckTimerSkewAndSendHeartbeat.md`: its old final-C++ wording still mentions a `95/95` final-code bar. If touched in a later pass, replace that stale code-gate wording with the active combined-score/emitter gate policy; do not let that support-page wording block [UID:00014E] C++.

## Validator Needs

Already run during this B-report pass:

_Executable command block removed from the research report; preserved in [00014E-CrashDiagnosticTextSender-source-quality-removed.md](00014E-CrashDiagnosticTextSender-source-quality-removed.md)._

Result: dry-run only, `ok: 1`, no target errors, no file changes.

After implementation callback edits target:

_Executable command block removed from the research report; preserved in [00014E-CrashDiagnosticTextSender-source-quality-removed.md](00014E-CrashDiagnosticTextSender-source-quality-removed.md)._

If support docs are edited, run scoped validator apply on those files too.

Expected project stats row after target metadata update:

```text
| `00014E` | 86 | 91 | 88.5 | `by-memory/0x004ab740-0x004ab804.CrashDiagnosticTextSender.md` |
```

Expected generated output impact after C++ insertion and direct file route: `auto-generated/NexusTK/platform/ExceptionHandler.cpp` should receive the `SendCrashDiagnosticText` helper once the validator/autogen pass assembles [UID:0000J8].

## Exact Pending Coverage Text

Do not edit `by-memory/-coverage-report.md` during this B-agent pass. If the implementation callback accepts the recommended metadata/source route/C++ change, replace the current [UID:00014E] row with:

```text
    - [UID:00014E][0x004ab740-0x004ab804.CrashDiagnosticTextSender](by-memory/0x004ab740-0x004ab804.CrashDiagnosticTextSender.md) : reconstructable : 86% : very strong : Exact file-static `SendCrashDiagnosticText(const char *)` helper in `platform/ExceptionHandler.cpp`; B005 source-quality pass recommends direct owner/emitter [UID:0000J8], first-draft C++ under the active gate, exact `0xc4` / 196-byte body (Verified with int_convert.py), sole caller `0x00466e80` from Application timer-skew diagnostics, ANSI payload gate `1..0xFFF` / `1..4095` bytes (Verified with int_convert.py), packet `{0x42,0x01,length16be,payload,0}` with send length `length+5` and max `0x1004` / 4100 bytes (Verified with int_convert.py), `g_packetSender`/Socket queue route, PacketBuffer writer and MemoryMan/memmove helper dependencies, generated-name rejection, and twelve-byte padding before the raw report-text setter.
```

If the supervisor keeps the current [UID:00004P] class-through route instead of direct [UID:0000J8], use this alternate sentence fragment inside the same row:

```text
keeps current class-through owner/emitter [UID:00004P] only as an output route while documenting the source helper as file-static in [UID:0000J8]
```

## Open Questions And Score Impact

- Exact original source spelling remains inferred. `SendCrashDiagnosticText` is the best current name from behavior and the accepted [UID:00014D] report.
- Exact final PacketBuffer/MemoryMan helper API names remain inferred. Current support docs are strong enough for first-draft source, but not final-audit confidence.
- The reason for the explicit unused `GetMemoryMan()` call is not semantically proven. The binary calls it before packet construction, so the first-draft source keeps it.
- No live IDA MCP recheck was possible in this session. Existing prior live-IDA docs and cached IDA export agree, so this limits only final-audit confidence, not first-draft C++ readiness.

## Changed Files

Created:

- `source-3/project-documentation/tools/leaser/Agents/Agent-B005/research/00014E-CrashDiagnosticTextSender-source-quality.md`

Modified:

- none outside this B005 research report

Not edited:

- target by-memory page
- support by-* docs
- `by-memory/-coverage-report.md`
- generated/project-level files

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/00014E-CrashDiagnosticTextSender-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:30","uid":"00014E"} -->
<!-- {"agent":"B005","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00014E-CrashDiagnosticTextSender-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B005/00014E-CrashDiagnosticTextSender-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00014E"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
