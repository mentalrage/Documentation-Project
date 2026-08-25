** TARGET-REPORT-UID:00014E **
** AUTHOR-AGENT-ID:B013 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00014E CrashDiagnosticTextSender Source-Quality Report

Agent: B013  
Assignment: `B013-goal2-crash-diagnostic-text-sender-source-quality-00014E-20260619`  
Target: [UID:00014E] `source-3/project-documentation/by-memory/0x004ab740-0x004ab804.CrashDiagnosticTextSender.md`  
Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B013/research/00014E-CrashDiagnosticTextSender-source-quality.md`

## Finalized Report / Current Recommendation

- Current recommendation: update [UID:00014E] from `84/90` to `88/92`, keep direct owner/emitter [UID:00004P] `ExceptionHandler`, and populate first-draft C++ as a nonvirtual `ExceptionHandler::SendCrashDiagnosticText(const char *)` method body on this exact child page after supervisor implementation approval.
- Final disposition: reconstructable source-authored crash/diagnostic packet helper, source-shaped as an `ExceptionHandler` member helper in `platform/ExceptionHandler.cpp`, not a file-static utility, not Application timing ownership, not Socket/PacketBuffer ownership, and not compiler/runtime code.
- Required action after supervisor review: implementation callback should edit the target and support docs only; do not edit `by-memory/-coverage-report.md`. Exact replacement coverage text is included below.
- Confidence: very strong for boundary, padding, caller, `ECX`/`this` setup, packet layout, length gate, helper dependencies, and `ExceptionHandler.cpp` placement; medium-high for exact original source spelling and final helper API spellings.

## Target

- Target UID: `00014E`
- Target path: `by-memory/0x004ab740-0x004ab804.CrashDiagnosticTextSender.md`
- Current metadata: `COMPLETION:84`, `CONFIDENCE:90`, `CANONICAL_OWNER:00004P`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00004P`, formal C++ blank.
- Recommended metadata: `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:00004P`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00004P`.
- Current output route: `00014E -> 00004P -> 0000J8 -> auto-generated/NexusTK/platform/ExceptionHandler.cpp`.
- Recommended output route: keep the current class-through route because the sole caller sets `ECX = g_pCrashTarget` immediately before the call.

## Supervisor Active Recheck

- This was assigned as a report-only B-source-quality pass.
- No by-* docs, generated files, IDA DB, project-level reports, or `by-memory/-coverage-report.md` were edited.
- IDA MCP was checked and unavailable in this session: the direct endpoint request could not connect to the remote server. The removed literal PowerShell command is preserved only in the linked inert archive.
- Because live MCP was unavailable, this report uses current by-* docs with prior live-IDA evidence, local cached function exports, direct PE byte/disassembly checks with Capstone, and a scoped validator dry run.

## Evidence Checked

Primary target and source-family docs:

- `by-memory/0x004ab740-0x004ab804.CrashDiagnosticTextSender.md`
- `by-memory/0x004ab480-0x004ac89a.ExceptionHandler.md`
- `by-class/ExceptionHandler.md`
- `by-file/ExceptionHandler.md`
- `by-meta/client_crash_diagnostics.md`
- `by-memory/0x00466ca0-0x004670ad.CheckTimerSkewAndSendHeartbeat.md`
- `by-item/CheckTimerSkewAndSendHeartbeat_466CA0.md`
- `by-project-structure/proposed-source-tree.md`

Dependency and helper docs:

- `by-memory/0x00516030-0x00516036.GetMemoryMan.md`
- `by-memory/0x00516220-0x00516238.MemmoveWrapper.md`
- `by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md`
- `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md`
- `by-global/g_packetSender.md`
- `by-file/Socket.md`
- `by-file/PacketBuffer.md`

Other evidence:

- Prior lead report `tools/leaser/Agents/Agent-B005/research/00014E-CrashDiagnosticTextSender-source-quality.md` was read and reanalyzed, not treated as authoritative.
- Local cached export `source-3/core/data/cache/prewave/functions/0x004ab740.json`.
- Readonly export `source-3/core/data/readonly/prewave/exported-functions/0x004ab740.json`.
- Direct bytes and disassembly from `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, image base `0x00400000`.
- Number conversions verified with `tools/int_convert.py`: `0xc4` = 196, `0xffe` = 4094, `0xfff` = 4095, `0x1000` = 4096, `0x1004` = 4100, `0x1005` = 4101, `0x1024` = 4132, `0x42` = 66 / ASCII `B`.

## Binary Facts

Direct PE/Capstone recheck confirms:

- Function start: `0x004ab740`.
- Function end-exclusive: `0x004ab804`.
- Size: `0xc4` / 196 bytes (Verified with `tools/int_convert.py`).
- Predecessor padding: `0x004ab73b-0x004ab740`, five bytes of `0xcc`.
- Successor padding: `0x004ab804-0x004ab810`, twelve bytes of `0xcc`.
- Successor raw setter: `0x004ab810-0x004ab82b`, not part of this function.
- Rel32 call scan found exactly one direct call to `0x004ab740`: call site `0x00466e80`.
- Raw VA pointer scan found no immediate pointer/table route to `0x004ab740`.

Relevant target disassembly:

```asm
004ab740  push ebp
004ab741  mov  ebp, esp
004ab743  mov  eax, 0x1024
004ab748  call 0x005c7740                 ; __alloca_probe
004ab74d  mov  eax, dword ptr [0x00672f24] ; security cookie
...
004ab75a  mov  edi, dword ptr [ebp+8]     ; text
004ab75d  call 0x00516030                 ; GetMemoryMan
...
004ab770  mov  cl, byte ptr [esi]         ; strlen loop
004ab772  inc  esi
004ab773  test cl, cl
004ab775  jne  0x004ab770
004ab777  sub  esi, edx                   ; length
004ab779  lea  eax, [esi-1]
004ab77c  cmp  eax, 0xffe
004ab781  ja   0x004ab7f1                 ; reject length 0 or >=0x1000
...
004ab78c  call 0x00575380                 ; PacketBufferWriteUInt8(0x42)
004ab79a  call 0x00575380                 ; PacketBufferWriteUInt8(1)
004ab7a7  call 0x005753a0                 ; PacketBufferWriteUInt16BE(length)
004ab7ba  call 0x00516220                 ; MemmoveWrapper(packet+4,text,length)
...
004ab7d3  call 0x00575380                 ; terminator byte at packet+length+4
004ab7d8  mov  ecx, dword ptr [0x0067a7ec] ; g_packetSender
004ab7ec  call 0x00574bb0                 ; QueueAndSendPacket(packet,length+5)
...
004ab7f9  call 0x005c772f                 ; __security_check_cookie
004ab801  ret  4
```

Caller-side source-shape evidence at `0x00466e70-0x00466e85`:

```asm
00466e70  mov  ecx, dword ptr [0x0067ab34] ; g_pCrashTarget
00466e76  lea  eax, [ebp-0x1044]           ; formatted diagnostic text
00466e7c  add  esp, 0x34
00466e7f  push eax
00466e80  call 0x004ab740
00466e85  mov  dword ptr [0x0067ab6c], 1   ; report-sent latch
```

The `ECX = g_pCrashTarget` setup immediately before the call is strong caller-side evidence that the original source call was a nonvirtual `ExceptionHandler` member call, likely `g_pCrashTarget->SendCrashDiagnosticText(buffer)`. The target body does not dereference `this`, so IDA/Ghidra infer a `__stdcall`-looking one-argument helper, but caller code still follows the MSVC x86 `thiscall` pattern.

## Boundary Before Raw Wide-String Setter

The target ends exactly at `0x004ab804`.

Direct bytes:

- `0x004ab804-0x004ab810`: `cc cc cc cc cc cc cc cc cc cc cc cc`
- `0x004ab810-0x004ab82b`: raw function-shaped body:

```asm
004ab810  push ebp
004ab811  mov  ebp, esp
004ab813  push dword ptr [ebp+8]
004ab816  lea  eax, [ecx+0x28]
004ab819  push 0x400
004ab81e  push eax
004ab81f  call 0x005cd657
004ab824  add  esp, 0x0c
004ab827  pop  ebp
004ab828  ret  4
```

Best source-facing name for the raw successor: `ExceptionHandler::SetReportText(const wchar_t *text)` or `ExceptionHandler::SetCrashReportText(const wchar_t *text)`. It copies the caller's wide string to `this + 0x28` with a count of `0x400` wide characters. No static rel32 or pointer route to `0x004ab810` was established in the checked docs; keep it as a separate raw helper/split need, not part of [UID:00014E].

## Behavior And Protocol

`CrashDiagnosticTextSender` does not format the human-readable diagnostic text. The sole caller, [UID:0000YT] `CheckTimerSkewAndSendHeartbeat`, builds the stack ANSI text with calls to `0x00443a00`, using timer-skew, key/timing, and OS label data. This target only serializes and queues that text.

Observed behavior:

- Calls `GetMemoryMan()` before building the local packet. The return is preserved briefly but no source-visible state from it is used by this helper.
- Measures the input with an inline byte loop equivalent to `strlen(text)`.
- Applies the unsigned gate `length - 1 <= 0xffe`, accepting exactly lengths `1..0xfff` / `1..4095` bytes (Verified with `tools/int_convert.py`).
- Rejects empty strings and strings with byte length `0x1000` / 4096 bytes or greater (Verified with `tools/int_convert.py`).
- Writes opcode `0x42` / 66 / ASCII `B` (Verified with `tools/int_convert.py`).
- Writes subtype byte `1`.
- Writes a two-byte big-endian payload length.
- Copies exactly `length` raw ANSI bytes.
- Writes a zero byte at `packet + length + 4`.
- Sends exactly `length + 5` bytes through [UID:0000Q5] `g_packetSender` and [UID:0001HU] `QueueAndSendPacket`.
- The final `PacketBufferWriteUInt8(0, packet + length + 4)` writes the sent trailing zero at offset `length + 4` and, because the helper writes a scratch zero after every scalar value, also clears `packet[length + 5]`; that scratch byte is not included in the sent length.

Packet layout:

| Offset | Writer | Meaning |
| --- | --- | --- |
| `0` | `PacketBufferWriteUInt8(0x42, packet)` | crash/diagnostic text opcode |
| `1` | `PacketBufferWriteUInt8(1, packet + 1)` | subtype `1` |
| `2..3` | `PacketBufferWriteUInt16BE(length, packet + 2)` | ANSI payload byte length, excluding terminator |
| `4..length+3` | `MemmoveWrapper(packet + 4, text, length)` | raw ANSI diagnostic text |
| `length+4` | `PacketBufferWriteUInt8(0, packet + length + 4)` | included trailing zero |
| `length+5` | scalar-writer scratch byte | not included in queued length |

Maximum accepted payload:

- Payload bytes: `0xfff` / 4095 (Verified with `tools/int_convert.py`).
- Counted send length: `0x1004` / 4100 (Verified with `tools/int_convert.py`).
- Minimum semantic local packet capacity including scratch byte: `0x1005` / 4101 (Verified with `tools/int_convert.py`).
- Observed compiler stack reservation: `0x1024` / 4132 (Verified with `tools/int_convert.py`), with IDA decompilation showing a packet/local span of `0x1020` bytes before the security cookie. Draft source may use `unsigned char packet[0x1020]` to match the observed frame shape while still documenting that the protocol only needs `0x1005`.

## Helper / Global / Type Name Resolution

Use these source-facing names in target and support docs:

| Raw/generated name | Recommended name | Ownership |
| --- | --- | --- |
| `sub_4AB740`, `FUN_004ab740` | `ExceptionHandler::SendCrashDiagnosticText` | [UID:00004P] `ExceptionHandler` |
| `0x00516030`, `sub_516030` | `GetMemoryMan` | [UID:0000L7] `MemoryMan` |
| `0x00575380`, `sub_575380` | `PacketBufferWriteUInt8` | [UID:0000M8] `PacketBuffer` |
| `0x005753a0`, `sub_5753A0` | `PacketBufferWriteUInt16BE` | [UID:0000M8] `PacketBuffer` |
| `0x00516220`, `sub_516220` | `MemmoveWrapper` | [UID:0000L7] `MemoryMan` / copy-wrapper island |
| `0x0067a7ec`, `dword_67A7EC` | `g_packetSender` | [UID:0000NS] `Socket` global |
| `0x00574bb0`, `sub_574BB0`, stale `CashShopRequest::meth_0x574bb0` | `Socket::QueueAndSendPacket` / `QueueAndSendPacket` | [UID:0000DD] `Socket` |

Rejected generated names:

- `sub_4AB740`, `FUN_004ab740`, `Src`, `param_1`: raw decompiler labels only.
- `CashShopRequest::meth_0x574bb0`: stale generated ownership for `0x00574bb0`; current Socket docs resolve the queue/send funnel.
- `PacketBuffer_WriteByte` is a useful generated lead, but `PacketBufferWriteUInt8` is the current support-doc name.

## Heuristic / Inference Reanalysis And Validation

### 1. Source-facing function name/signature

Best current source-facing signature:

```cpp
void ExceptionHandler::SendCrashDiagnosticText(const char *text)
```

Evidence:

- Caller `0x00466e80` sets `ECX = g_pCrashTarget` immediately before pushing the formatted text and calling `0x004ab740`.
- Target `ret 4` matches MSVC x86 `thiscall` for a member with one stack argument just as well as a `__stdcall` free function.
- Target body reads the text argument and never mutates it, so `const char *` is better source-facing type than IDA's `char *Src` and Ghidra's incorrect `uint *param_1`.
- Only known caller ignores EAX, so `void` is better source-facing return type than IDA's `int`. The observed EAX values are residual compare/send helper results, not a documented source status contract.

Rejected alternatives:

- `static void __stdcall SendCrashDiagnosticText(const char *)`: rejected as final recommendation because caller-side `ECX = g_pCrashTarget` is too strong to ignore. This was the main weakness in the prior B005 report's file-static conclusion.
- `int __stdcall sub_4AB740(char *)`: ABI/decompiler shape, not source-quality C++.
- `Application::SendCrashDiagnosticText`: rejected because Application owns the timer-skew formatter/caller, not this crash-diagnostics member helper.
- `Socket::SendCrashDiagnosticText` or PacketBuffer ownership: rejected because they are transport/serialization dependencies.

Remaining uncertainty:

- Exact original method spelling is not proven. `SendCrashDiagnosticText` is a descriptive high-probability name. Alternatives such as `SendDiagnosticText`, `SendCrashText`, or `SendErrorText` remain possible but less precise.

Score impact:

- This resolves the major source-shape blocker and supports raising completion/confidence. Original spelling uncertainty keeps the score below final-audit levels.

### 2. ExceptionHandler class owner versus file-static diagnostics helper

Best recommendation: keep direct owner/emitter [UID:00004P] `ExceptionHandler`.

Evidence:

- The sole caller passes `g_pCrashTarget` in `ECX`, a member-call pattern.
- The helper is physically inside the `0x004ab480-0x004ac89a` ExceptionHandler crash-diagnostics cluster.
- The proposed source tree lists `ExceptionHandler.cpp` as owner for the diagnostic text helper.
- The class page already describes this as part of the exception-handler helper family.
- The function has no independent initializer, no separate diagnostics global, and no caller cluster justifying a new diagnostics source file.

Rejected alternatives:

- Direct [UID:0000J8] file-static owner/emitter: plausible if the caller had not set `ECX`, but now weaker than class ownership. The file still owns the final source module, but the direct semantic owner should be the class.
- New `CrashDiagnostics.cpp`: rejected because no source-path, initializer, global owner, or broader non-ExceptionHandler helper set proves a standalone translation unit.
- [UID:0000HG] `Application`: rejected because it only formats the timer-skew text and calls the helper.

Score impact:

- Owner/emitter can remain stable. The report should explicitly preserve [UID:00004P] to avoid a wrong direct reroute.

### 3. Sole caller and reachability

Best conclusion: one direct static code caller at `0x00466e80`; no pointer/table route found.

Evidence:

- Direct PE rel32 scan found exactly one `call 0x004ab740` at `0x00466e80`.
- Cached IDA export reports one caller and IDA xref-to only `CALL_NEAR` from `0x00466e80`.
- Direct raw VA pointer scan found zero pointer hits to `0x004ab740`.
- The call sits inside [UID:0000YT] `CheckTimerSkewAndSendHeartbeat`, after text formatting and before writing the one-shot report-sent latch at `0x0067ab6c`.

Rejected alternatives:

- Hidden vtable/callback route: no VA pointer evidence found.
- Dead retained helper: rejected because the direct call is live and source-shaped.

Score impact:

- Reachability is resolved and should no longer block C++.

### 4. Packet protocol layout

Best conclusion: packet is `{0x42, 0x01, UInt16BE(length), payload bytes, 0}` and the terminator is included in the queued length.

Evidence:

- Direct instruction order and support-doc disassembly confirm two `PacketBufferWriteUInt8` calls, one `PacketBufferWriteUInt16BE`, one `MemmoveWrapper`, final terminator write, then queue/send.
- Length gate and queue argument prove accepted length `1..0xfff`, send length `length + 5`, and maximum counted packet `0x1004` bytes.
- PacketBuffer scalar writer docs prove the trailing scratch zero semantics after each scalar write.

Rejected alternatives:

- UTF-16 payload: rejected; the caller passes an ANSI stack buffer and this helper copies raw bytes.
- Length includes the trailing zero: rejected for the length field; accepted for the queued send size. The field at offsets `2..3` is payload length only, while queued length includes the trailing zero byte.
- Truncation: rejected; overlong input is dropped.

Score impact:

- Protocol blocker resolved.

### 5. Compiler/security scaffolding

Best conclusion: exclude `__alloca_probe`, security-cookie reads/checks, and padding from final source.

Evidence:

- Prologue uses `__alloca_probe` for local frame `0x1024`.
- Reads security cookie at `0x00672f24` and calls `__security_check_cookie` at epilogue.
- Padding before/after target is `0xcc` alignment.

Rejected alternatives:

- Hand-authoring cookie or probe logic in C++: rejected as compiler-generated.
- Treating the stack frame size as protocol length: rejected; protocol length is controlled by the explicit length gate and send argument.

Score impact:

- C++ can be source-style and should not include compiler artifacts.

### 6. Raw wide-string setter boundary

Best conclusion: the raw setter is adjacent ExceptionHandler code but outside [UID:00014E].

Evidence:

- Twelve `0xcc` bytes separate `0x004ab804` from raw body `0x004ab810`.
- Raw body uses `ECX + 0x28`, count `0x400`, and `_wcscpy_s`-style callee `0x005cd657`.
- Aggregate/class docs name `this + 0x28` as `m_reportText[0x400]`.

Rejected alternatives:

- Merging the setter into this target: rejected by padding and separate function-shaped prologue/ret.
- Treating setter as compiler glue: rejected because it is source-shaped class helper code, just not routed by static calls yet.

Score impact:

- Confirms [UID:00014E] exact boundary and leaves setter as a separate child/split issue for [UID:00014D]/[UID:00004P].

## Ownership Analysis

### Accepted: [UID:00004P] `ExceptionHandler` class

Evidence for:

- Caller passes `g_pCrashTarget` in `ECX`.
- Target has `ret 4`, compatible with a `thiscall` member taking one explicit argument.
- Physical address cluster and source-tree placement are ExceptionHandler diagnostics.
- The method belongs semantically to crash diagnostics, and `g_pCrashTarget` is the active handler object.

Evidence against:

- The body does not read fields from `this`.

Decision:

- Keep [UID:00004P] as direct owner/emitter. A member function that does not use `this` is common when policy is grouped on an object API but the current helper only needs global transport dependencies.

### Rejected As Direct Owner: [UID:0000J8] `ExceptionHandler.cpp`

Evidence for:

- It is the correct final source file.
- The helper is file-local to the ExceptionHandler translation unit if viewed at `.cpp` scope.

Evidence against:

- Caller-side `ECX` setup is positive member-call evidence.
- Bypassing the class would lose a real ABI/source-shape clue.

Decision:

- Keep [UID:0000J8] as the source file reached through [UID:00004P], not as direct canonical owner for this exact by-memory function.

### Rejected: [UID:0000HG] `Application`

Evidence for:

- Sole ordinary caller is the Application message-loop timer-skew helper.

Evidence against:

- Application formats the diagnostic string but calls the crash target object to send it.
- Caller dependency is not source ownership.

Decision:

- Application remains caller/consumer only.

### Rejected: Socket, PacketBuffer, MemoryMan, CashShopRequest

Evidence for:

- The helper calls those subsystems or stale generated aliases mention them.

Evidence against:

- Transport/serialization/copy helpers are broad dependencies with their own owners.
- The target owns the crash-diagnostic packet policy, not the generic send queue or scalar writers.

Decision:

- Keep dependency links only; do not reroute ownership.

## First-Draft C++ Recommendation

This target meets the active C++ entry gate after the recommended score update:

- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00004P`, which routes to [UID:0000J8] `ExceptionHandler.cpp`
- `(88 + 92) / 2 = 90`, above the active `>85` gate
- Exact boundary, caller, helper names, packet layout, and source shape are now documented

Recommended first-draft C++ for the target's `RECONSTRUCTION_CPP CODE` block:

```cpp
void ExceptionHandler::SendCrashDiagnosticText(const char *text)
{
    GetMemoryMan();

    const unsigned int length = static_cast<unsigned int>(strlen(text));
    if (length == 0 || length > 0x0fff) {
        return;
    }

    unsigned char packet[0x1020];
    PacketBufferWriteUInt8(0x42, packet);
    PacketBufferWriteUInt8(1, packet + 1);
    PacketBufferWriteUInt16BE(static_cast<unsigned short>(length), packet + 2);
    MemmoveWrapper(packet + 4, text, length);
    PacketBufferWriteUInt8(0, packet + length + 4);

    g_packetSender->QueueAndSendPacket(packet, static_cast<short>(length + 5));
}
```

Implementation notes:

- Do not add a null check for `text`; the binary has none.
- Do not add a null check for `g_packetSender`; the binary has none.
- Do not truncate overlong strings; the binary drops length `0` and length `>= 0x1000`.
- Keep the trailing zero inside the sent length.
- Keep `GetMemoryMan();` even though the returned pointer is not source-visible in this helper; the binary calls it before packet construction.
- The draft uses `packet[0x1020]` to reflect the observed local packet span. If the supervisor prefers minimum semantic source, `packet[0x1005]` is sufficient for max payload plus scalar-writer scratch byte; document the choice either way.
- If support docs later standardize `QueueAndSendPacket` as a free wrapper instead of a `Socket` method call, change the last line mechanically to `QueueAndSendPacket(g_packetSender, packet, static_cast<short>(length + 5));`.
- Do not emit `__alloca_probe`, security-cookie logic, raw addresses, `sub_` names, or `this+offset` arithmetic.

## Recommended Target Doc Changes

Apply these to `by-memory/0x004ab740-0x004ab804.CrashDiagnosticTextSender.md` during a supervisor-approved implementation callback:

1. Change metadata:
   - `COMPLETION:84 -> 88`
   - `CONFIDENCE:90 -> 92`
   - keep `CANONICAL_OWNER:00004P`
   - keep `RECONSTRUCTABLE:TRUE`
   - keep `EMITTER_UIDS:00004P`
2. Replace "medium for final source-facing helper name" wording with:
   - "very strong for exact boundary, sole caller, `ECX = g_pCrashTarget` member-call evidence, packet layout, accepted length gate, helper dependencies, and ExceptionHandler source route; medium-high for exact original method spelling."
3. Add a source-quality note:
   - "Caller `0x00466e80` loads `g_pCrashTarget` into `ECX` before pushing the formatted text and calling this helper, so the best source shape is a nonvirtual `ExceptionHandler::SendCrashDiagnosticText(const char *)` member. The body does not dereference `this`, which explains why decompilers infer a `__stdcall`-like helper."
4. Add or update packet layout with opcode `0x42`, subtype `1`, big-endian length, raw ANSI payload, included trailing zero, and scalar-writer scratch zero outside the send length.
5. Add exact accepted length:
   - `1..0xfff` / `1..4095` bytes (Verified with `tools/int_convert.py`).
6. Add exact maximum send length:
   - `0x1004` / `4100` bytes (Verified with `tools/int_convert.py`).
7. Add boundary/padding proof:
   - `0x004ab73b-0x004ab740` five `0xcc` bytes before the target.
   - `0x004ab804-0x004ab810` twelve `0xcc` bytes before raw setter.
   - raw setter `0x004ab810-0x004ab82b` is a separate `ExceptionHandler::SetReportText`-style helper.
8. Replace raw helper names:
   - `0x00575380` -> `PacketBufferWriteUInt8`
   - `0x005753a0` -> `PacketBufferWriteUInt16BE`
   - `0x00516220` -> `MemmoveWrapper`
   - `0x00574bb0` -> `QueueAndSendPacket`
   - `dword_67A7EC` -> `g_packetSender`
9. Add first-draft C++ above.
10. Preserve a "rejected prior/static interpretation" note:
    - A file-static `SendCrashDiagnosticText` was a plausible reading from the callee body alone, but caller-side `ECX = g_pCrashTarget` makes the member helper interpretation stronger.

## Recommended Support Doc Updates

`by-class/ExceptionHandler.md`:

- List `0x004ab740-0x004ab804` as `ExceptionHandler::SendCrashDiagnosticText(const char *text)`.
- Explain that the method does not use fields directly, but the caller passes `g_pCrashTarget` in `ECX`.
- Keep `m_reportText[0x400]` / raw setter as separate helper context.
- Note that class C++ can declare this method; body belongs to exact [UID:00014E].

`by-file/ExceptionHandler.md`:

- Keep `platform/ExceptionHandler.cpp` placement.
- Refine the [UID:00014E] bullet from "packet helper" to "nonvirtual `ExceptionHandler::SendCrashDiagnosticText(const char *)` helper called from Application timer-skew diagnostics."
- Do not create a new `CrashDiagnostics.cpp` based on this helper.

`by-memory/0x004ab480-0x004ac89a.ExceptionHandler.md`:

- Update the child inventory row for [UID:00014E] with the member-call evidence and first-draft C++ readiness.
- Keep aggregate C++ blank or `[[CHILDREN]]`; the exact child should emit the method body.
- Keep `0x004ab810-0x004ab82b` raw setter as separate source-shaped code after 12-byte padding.

`by-meta/client_crash_diagnostics.md`:

- Close the open ownership question for [UID:00014E]:
  - "Best current source shape is `ExceptionHandler::SendCrashDiagnosticText(const char *)`, called from Application timer-skew diagnostics through `g_pCrashTarget`; no separate diagnostics utility file is justified."

`by-memory/0x00466ca0-0x004670ad.CheckTimerSkewAndSendHeartbeat.md`:

- Update the diagnostic text-sender mention to include the caller detail:
  - `0x00466e80` passes `g_pCrashTarget` in `ECX` and the formatted ANSI stack buffer as the sole explicit argument.
- Replace stale "95/95 final-code bar" wording with the active combined-score/emitter gate if the page is touched.

`by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md`:

- No required edit for this target; existing scalar-writer names and scratch-zero behavior support the target.

`by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md` and `by-global/g_packetSender.md`:

- No required edit for this target; existing Socket ownership and `Socket *` type support the target.

## Exact Coverage Replacement Text

Do not edit `by-memory/-coverage-report.md` during this B-agent report pass. If the implementation callback accepts the recommended target metadata/source route/C++ change, replace the current [UID:00014E] row with:

```markdown
    - [UID:00014E][0x004ab740-0x004ab804.CrashDiagnosticTextSender](by-memory/0x004ab740-0x004ab804.CrashDiagnosticTextSender.md) : reconstructable : 88% : very strong : B013 source-quality pass resolves this as nonvirtual `ExceptionHandler::SendCrashDiagnosticText(const char *)` under [UID:00004P][ExceptionHandler](by-class/ExceptionHandler.md), not a file-static diagnostics utility: exact `0xc4` / 196-byte body (Verified with `tools/int_convert.py`), five-byte predecessor padding, twelve-byte successor padding before raw wide-string setter `0x004ab810`, sole rel32 caller `0x00466e80` from Application timer-skew diagnostics with `ECX = g_pCrashTarget`, packet `{0x42,0x01,length16be,payload,0}`, accepted ANSI length `1..0xfff` / `1..4095` bytes (Verified with `tools/int_convert.py`), maximum queued length `0x1004` / 4100 bytes (Verified with `tools/int_convert.py`), included trailing terminator plus out-of-send scalar-writer scratch zero, `GetMemoryMan`/`MemmoveWrapper`/PacketBuffer writer dependencies, `g_packetSender` Socket queue route, security-cookie/compiler scaffolding exclusion, and first-draft C++ readiness on the exact child page.
```

## Validator Needs

Dry-run validation already run during this report:

> Executable block R001 was removed from this report and preserved verbatim in [00014E-CrashDiagnosticTextSender-source-quality-removed.md](00014E-CrashDiagnosticTextSender-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result: `ok: 1`; dry-run only, no files changed.

Expected validation after implementation callback:

> Executable block R002 was removed from this report and preserved verbatim in [00014E-CrashDiagnosticTextSender-source-quality-removed.md](00014E-CrashDiagnosticTextSender-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected generated output impact after C++ insertion:

- `auto-generated/NexusTK/platform/ExceptionHandler.cpp` should receive `ExceptionHandler::SendCrashDiagnosticText(const char *text)` through the existing `00014E -> 00004P -> 0000J8` route.
- The generated output should not contain a duplicate file-static `SendCrashDiagnosticText`.
- The aggregate [UID:00014D] should not emit a monolithic body duplicating this exact child.

## IDA Rename / Type / Comment Recommendations

Recommended IDA/Ghidra naming, if a future tool-side rename pass is allowed:

- `sub_4AB740` -> `ExceptionHandler::SendCrashDiagnosticText`
- Caller comment at `0x00466e80`: "Timer-skew diagnostics call active ExceptionHandler member helper; ECX = g_pCrashTarget, stack arg = formatted ANSI text."
- `sub_575380` -> `PacketBufferWriteUInt8`
- `sub_5753A0` -> `PacketBufferWriteUInt16BE`
- `sub_516220` -> `MemmoveWrapper`
- `sub_574BB0` -> `Socket::QueueAndSendPacket`
- Raw `0x004ab810` body -> `ExceptionHandler::SetReportText` or `ExceptionHandler::SetCrashReportText` after separate validation.

Recommended type/comment updates:

- Treat the explicit source signature as `void ExceptionHandler::SendCrashDiagnosticText(const char *text)`.
- Comment `0x0067a7ec` use as `g_packetSender`, best current type `Socket *`.
- Comment target stack packet as `unsigned char packet[0x1020]` / protocol payload max `0x1004` counted send bytes.
- Comment security-cookie read `0x00672f24` and `__alloca_probe` as compiler-generated scaffolding.

## Open Questions And Score Impact

- Exact original method spelling is not proven. `SendCrashDiagnosticText` is the best descriptive name; this caps final-audit confidence but does not block first-draft C++.
- Exact final helper API spellings for PacketBuffer/MemoryMan wrappers are inferred from support docs. Current names are strong enough for draft source, but future header recovery may rename them.
- The reason for the explicit `GetMemoryMan()` call is not semantically proven. Preserve it in C++ because the binary calls it.
- Live IDA MCP was unavailable during this session. Direct PE/Capstone checks and current docs with prior live-IDA evidence agree on all material target facts; this prevents only final-audit scoring, not implementation readiness.

## Exact Implementation Checklist

For a later same-agent implementation callback:

1. Edit only the accepted target/support docs listed by the supervisor.
2. On [UID:00014E], update metadata to `88/92`, preserving owner/emitter [UID:00004P].
3. Replace the pending-C++/no-code wording with first-draft C++ readiness under the active combined-score/emitter gate.
4. Insert the `ExceptionHandler::SendCrashDiagnosticText(const char *text)` C++ block if accepted.
5. Add the caller-side `ECX = g_pCrashTarget` source-shape evidence and explicitly reject the file-static interpretation as weaker.
6. Add the boundary/padding and raw setter separation proof.
7. Add packet layout, length gate, max send size, scalar-writer scratch-zero behavior, and helper/global names.
8. Update `by-class/ExceptionHandler.md`, `by-file/ExceptionHandler.md`, `by-memory/0x004ab480-0x004ac89a.ExceptionHandler.md`, `by-meta/client_crash_diagnostics.md`, and optionally the caller page with report-level details.
9. Do not edit `by-memory/-coverage-report.md`; provide the exact row above to the supervisor.
10. Run the scoped validators above and report exact results.

## Changed Files

Created:

- `source-3/project-documentation/tools/leaser/Agents/Agent-B013/research/00014E-CrashDiagnosticTextSender-source-quality.md`

Modified:

- none outside this B013 research report

FINISHED

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B013","command_id":"000000004165","destination_path":"executed-b-agent-research/B013/00014E-CrashDiagnosticTextSender-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:35","uid":"00014E"} -->
<!-- {"agent":"B013","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00014E-CrashDiagnosticTextSender-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B013/00014E-CrashDiagnosticTextSender-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00014E"} -->
<!-- {"agent":"B013","command_id":"000000023047","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00014E-CrashDiagnosticTextSender-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B013/00014E-CrashDiagnosticTextSender-source-quality.md","timestamp":"2026-08-13T02:36:38-04:00","uid":"00014E"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
