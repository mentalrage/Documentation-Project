** TARGET-REPORT-UID:0001MJ **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 0001MJ GroupInputPane Empty-Emitter Source-Quality Report

## Status

Report-only research pass for [UID:0001MJ] `by-memory/0x005b5440-0x005b5547.GroupInputPane.md`.

No leases were taken. I did not edit by-* docs, generated files, project-level files, manual `-coverage-report.md` files, validator/tool state, or the IDA DB.

## Assignment

- Assignment id: `B009-report-0001MJ-GroupInputPane-empty-emitter-source-quality-20260628`
- Agent: Agent-B009
- Required report path: `tools/leaser/Agents/Agent-B009/research/0001MJ-GroupInputPane-empty-emitter-source-quality.md`
- Target: [UID:0001MJ] `by-memory/0x005b5440-0x005b5547.GroupInputPane.md`
- Queue state: `auto-generated/-ag-research-tracker.md` lists [UID:0001MJ] at `85/88`, reconstructable true, report count `0`; `auto-generated/-ag-coverage-report-by-memory.md` shows `emits_code:false`.
- Current generated output: `auto-generated/NexusTK/ui/dialogs/CommandInputPanes.cpp` still contains `// UID:0001MJ ... Empty Emitter Marker`.

## Executive Recommendation

[UID:0001MJ] is ready for formal first-draft `GroupInputPane::OnConfirmInput()` C++.

Recommended target metadata:

- `COMPLETION:90`
- `CONFIDENCE:92`
- Preserve `CANONICAL_OWNER:00005W`
- Preserve `RECONSTRUCTABLE:TRUE`
- Preserve `EMITTER_UIDS:00005W`
- Preserve blank `EMITTER_POSITION_OPTIONAL`
- Preserve `Nested:0`

The submit method source-quality blockers are resolved:

- `0x00516030` is [UID:0001BC] `GetMemoryMan`, not an input-state reset.
- `0x00516220` is [UID:0001BH] `MemoryMan::MemmoveWrapper`; feature-level C++ can model the payload copy as `memmove(...)`, consistent with accepted string-packet submit handlers.
- `0x00575380` is [UID:0003YJ] `PacketBufferWriteUInt8`, with raw ABI `value, destination`.
- `0x00574bb0` is [UID:0001HU] `Socket::QueueAndSendPacket`, reached through `Socket *g_packetSender` / [UID:0000Q5].
- The packet layout is exact: opcode `0x2e`, one-byte converted-text length, converted text bytes, then a local-only zero terminator outside the sent length.
- The current `GroupInputPane` class/file route is correct: direct owner/emitter remains [UID:00005W] `GroupInputPane`, with source routed through [UID:0000ID] `CommandInputPanes`.

The only meaningful remaining uncertainty is final-audit source spelling/style: exact original callback name, local variable names, and whether the original source used explicit packet helper calls or direct byte assignments. Those are confidence caps, not C++ blockers.

## Current Target State

Current target header:

- `COMPLETION:85`
- `CONFIDENCE:88`
- `CANONICAL_OWNER:00005W`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00005W`
- blank `EMITTER_POSITION_OPTIONAL`
- blank formal `RECONSTRUCTION_CPP CODE`
- `Nested:0`

Current target prose is mostly correct for ownership, vtable route, range, packet shape, and constructor split, but stale for helper source-quality:

- It still describes `0x00516030` as clearing or resetting input state. Current target decompile and accepted [UID:0001BC] prove this is `GetMemoryMan`.
- It still names `sub_575380` and `sub_516220` directly in packet layout tables. Current accepted support docs name them `PacketBufferWriteUInt8` and `MemoryMan::MemmoveWrapper`.
- It still says formal submit C++ is blank pending packet helper names and final source shape. This report resolves those exact blockers.

## Evidence Checked

Local docs and generated state read:

- Target [UID:0001MJ] `by-memory/0x005b5440-0x005b5547.GroupInputPane.md`
- Constructor child [UID:0002SB] `by-memory/0x005b5400-0x005b5440.GroupInputPaneRawConstructor.md`
- Class parent [UID:00005W] `by-class/GroupInputPane.md`
- File route [UID:0000ID] `by-file/CommandInputPanes.md`
- Vtable data [UID:0002N6] `by-memory/0x006300d4-0x006301e8.GroupPostInputPaneVtableData.md`
- [UID:000077] `by-class/LineInputPane.md`
- [UID:00035R] `by-memory/0x004f2300-0x004f230f.LineInputPaneCopyText.md`
- [UID:00035S] `by-memory/0x004f2310-0x004f231b.LineInputPaneTextLength.md`
- [UID:0001BC] `by-memory/0x00516030-0x00516036.GetMemoryMan.md`
- [UID:0001BH] `by-memory/0x00516220-0x00516238.MemmoveWrapper.md`
- [UID:0003YJ] `by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md`
- [UID:0001HU] `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md`
- [UID:0000Q5] `by-global/g_packetSender.md`
- `auto-generated/-ag-research-tracker.md`
- `auto-generated/-ag-coverage-report-by-memory.md`
- `auto-generated/NexusTK/ui/dialogs/CommandInputPanes.cpp`
- `project-level/-resolved.md` and `project-level/-unresolved.md` raw-name rows for this target

Executed report/context checked:

- `executed-b-agent-research/B001/0002SB-GroupInputPaneRawConstructor-source-quality.md`
- `executed-b-agent-research/B006/0001BH-MemmoveWrapper-source-quality.md`
- `executed-b-agent-research/B006/0001LZ-SayToGroupMessageInputPane-source-quality.md`
- Accepted [UID:0001KW] `SpellStringInputPane::OnConfirmInput` by-memory/class docs for string-packet C++ style.

`tools/int_convert_readme.md` was read. Numeric conversions below were verified with `tools/int_convert.py` or MCP `int_convert`, not manually converted.

## IDA MCP Provenance

MCP was available and responsive at `http://127.0.0.1:13337/mcp`.

Current read-only MCP state:

- Server: `ida-pro-mcp` version `1.0.0`
- Active session/database: `agent_b009_0002my_20260628`
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Module: `NexusTK.exe`
- Input path: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- Imagebase: `0x400000`
- `server_health`: `status:ok`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, string cache size `2067`

Current schema note: this MCP build requires `database:<session_id>` on IDB-backed tool calls. An initial no-database health probe returned the expected "database is required" tool error; all evidence calls below used `database:'agent_b009_0002my_20260628'`.

All MCP interactions were read-only. I did not use rename, comment, type, patch, save, or other IDA DB mutation tools.

## Current MCP Evidence

Function and boundary checks:

- `lookup_funcs 0x005b5440` reports `sub_5B5440`, size `0x107` / 263 bytes (Verified with int_convert.py).
- `lookup_funcs 0x005b5546` is still inside `sub_5B5440`.
- `lookup_funcs 0x005b5547` reports not a function, confirming the end-exclusive target boundary.
- `lookup_funcs 0x005b5400` and `0x005b53f9` report not functions, preserving the raw-constructor/padding caveat on the predecessor side.
- `lookup_funcs` resolves support callees:
  - `0x004f2310` -> `sub_4F2310`, size `0xb`.
  - `0x004f2300` -> `sub_4F2300`, size `0xf`.
  - `0x00516030` -> `sub_516030`, size `0x6`.
  - `0x00575380` -> `sub_575380`, size `0x11`.
  - `0x00516220` -> `sub_516220`, size `0x18`.
  - `0x00574bb0` -> `sub_574BB0`, size `0x63`.

Target decompilation:

- The body calls `sub_4F2310(this)` and returns immediately when the current text length is not positive.
- It calls `sub_4F2300(this, WideCharStr, 255)`, so the source reads at most `0xff` / 255 wide characters (Verified with int_convert.py) into a 256-wide local buffer.
- It calls `sub_516030()` before packet assembly. Accepted support doc [UID:0001BC] and live decompile prove this is `GetMemoryMan()`, returning `g_pMemoryMan`, not a LineInputPane input reset.
- It calls `sub_575380(46, &Src)`, writing opcode `0x2e` / 46 (Verified with int_convert.py).
- It calls `WideCharToMultiByte(0,0,WideCharStr,wcslen(WideCharStr),MultiByteStr,256,0,0)`, so the source conversion is default ANSI/codepage (`CP_ACP` / `0`) into a 256-byte local buffer.
- It stores `MultiByteStr[encodedLength] = 0`, then writes the encoded byte count through `sub_575380(encodedLength, &v10)`.
- It copies exactly `encodedLength` bytes through `sub_516220(v11, MultiByteStr, encodedLength)`.
- It computes `packetLength = encodedLength + 2`, checks the 300-byte packet scratch boundary `0x12c` / 300 (Verified with int_convert.py), writes a local-only zero byte at `packet[packetLength]`, and calls `sub_574BB0(dword_67A7EC, &Src, packetLength)`.
- The decompiler shows `___report_rangecheckfailure` on the local array index guard paths. This is compiler range-check scaffolding for local indexed writes, not a protocol branch or a feature error path.

Target disassembly key points:

| Address | Instruction | Meaning |
| --- | --- | --- |
| `0x005b5456` | `call sub_4F2310` | LineInputPane text length gate. |
| `0x005b5460` | `jge loc_5B5533` | Return when length is zero or negative. |
| `0x005b5467` | `push 0FFh` | Copy cap is `0xff` / 255 wide chars (Verified with int_convert.py). |
| `0x005b5475` | `call sub_4F2300` | Copy current wide input text. |
| `0x005b547a` | `call sub_516030` | `GetMemoryMan()`, stored for later copy helper use. |
| `0x005b5488` | `push 2Eh` | Opcode `0x2e` / 46 (Verified with int_convert.py). |
| `0x005b548a` | `call sub_575380` | `PacketBufferWriteUInt8(opcode, packet)`. |
| `0x005b54ce` | `call ds:WideCharToMultiByte` | Convert wide text to multibyte bytes. |
| `0x005b54e4` | `mov [ebp+esi+MultiByteStr], 0` | Local encoded-text terminator. |
| `0x005b54ee` | `call sub_575380` | Write encoded byte length at packet `+1`. |
| `0x005b5507` | `call sub_516220` | Copy encoded bytes to packet `+2`. |
| `0x005b550c` | `add esi, 2` | Sent packet length is `encodedLength + 2`. |
| `0x005b5516` | `jnb short loc_5B5542` | Packet scratch range check against `0x12c` / 300 (Verified with int_convert.py). |
| `0x005b5518` | `mov ecx, dword_67A7EC` | Load [UID:0000Q5] `g_packetSender`. |
| `0x005b5526` | `mov [ebp+esi+Src], 0` | Local-only packet terminator outside sent length. |
| `0x005b552e` | `call sub_574BB0` | Queue/send packet through the Socket sender. |
| `0x005b5542` | `call ___report_rangecheckfailure` | Compiler range-check failure path. |

Xrefs and vtable evidence:

- `xrefs_to 0x005b5440` returns one data xref: `0x0063011c`.
- `get_int 0x0063011c u32le` confirms the slot value is `0x005b5440`, the `GroupInputPane` submit method.
- `xrefs_to 0x005b5400` returns zero xrefs; this is predecessor constructor-route evidence only and does not block this target's submit C++.
- `xrefs_to 0x006300d4`, `0x00630124`, and `0x00630154` each returns the same three GroupInputPane vtable-store sites: dispatcher `sub_5A5BD0`, open helper `sub_5A9A10`, and raw constructor bytes `0x005b541f` / `0x005b5427` / `0x005b5431`.

Callee set:

- `0x004f2310` / `LineInputPaneTextLength`
- `0x004f2300` / `LineInputPaneCopyText`
- `0x00516030` / `GetMemoryMan`
- `0x00575380` / `PacketBufferWriteUInt8`
- `WideCharToMultiByte`
- `0x00516220` / `MemoryMan::MemmoveWrapper`
- `0x00574bb0` / `Socket::QueueAndSendPacket`
- MSVC security/range helpers `@__security_check_cookie@4` and `___report_rangecheckfailure`

Helper decompilation/current names:

- `0x00516030`: decompiles to a direct return of `unk_69B4FC`; [UID:0001BC] names source as `MemoryMan* GetMemoryMan() { return g_pMemoryMan; }`.
- `0x00516220`: decompiles to `return memmove(destination, source, size);`; [UID:0001BH] names source as `MemoryMan::MemmoveWrapper`.
- `0x00575380`: decompiles to `*destination = value; destination[1] = 0; return value;`.
- `0x00575380` disassembly reads the byte value from `[ebp+8]` and destination pointer from `[ebp+0xc]`, proving raw ABI `PacketBufferWriteUInt8(value, destination)`.
- `0x00574bb0`: decompiles as the Socket queue/send wrapper: it checks the send-disabled byte, allocates `packetSize + 1`, copies `packetSize` bytes, appends a zero to the queued copy, and posts Socket command `8`.
- `0x004f2300` forwards the text-copy request to the editable child at `this[63]`.
- `0x004f2310` returns the editable child text length through the same child.

Range signature:

- `make_signature_for_range 0x005b5440-0x005b5547` returned `unique:true`.
- The signature starts with `55 8B EC 81 EC 30 04 00 00 A1 ? ? ? ? ...` and covers the full target range through the `___report_rangecheckfailure` tail call at the exclusive end. The full wildcard signature is long and does not need to be pasted into by-* docs unless the supervisor requests byte-signature detail.

## Numeric Conversions

Verified with `tools/int_convert.py` and/or MCP `int_convert`:

- `0x107` = 263, target function size.
- `0x2e` = 46, ASCII `.`, group command opcode.
- `0xff` = 255, wide-character copy cap.
- `0x100` = 256, multibyte conversion buffer cap.
- `0x12c` = 300, packet scratch-buffer cap.
- `0x108` = 264, GroupInputPane object allocation size from constructor/open-helper support docs.
- `0x2f` = 47, ASCII `/`, constructor prompt id from [UID:0002SB] support.

## Behavior And Packet Layout

`GroupInputPane::OnConfirmInput()` is a virtual line-input submit handler for group commands. It is not the same class or packet as the say-to-group message input family:

- [UID:0001MJ] sends opcode `0x2e`, with one converted input string and no stored destination group-name field.
- [UID:0001LZ] `SayToGroupMessageInputPane` sends opcode `0x19`, with a stored `m_groupName[128]`, group-name length/bytes, and message length/bytes.

Current target packet layout:

| Offset | Sent bytes | Source-quality interpretation |
| --- | --- | --- |
| `+0` | `0x2e` | Group command opcode, written through `PacketBufferWriteUInt8`. |
| `+1` | encoded byte count | One-byte result from `WideCharToMultiByte`. |
| `+2..packetLength-1` | encoded command text | Exactly `encodedLength` bytes copied from the local encoded-text buffer. |
| local `packet[packetLength]` | zero | Scratch terminator outside explicit send length; not part of the protocol payload. |

Important local buffer details:

- `wchar_t inputText[256]` source local matches the `WideCharStr[256]` stack local.
- `CopyText(inputText, 255)` matches the binary `push 0xff`.
- `char encodedText[256]` source local matches `MultiByteStr[256]`.
- `unsigned char packet[300]` source local matches `Src`, `v10`, and `v11[298]` as a contiguous 300-byte packet scratch area.
- `WideCharToMultiByte(CP_ACP, 0, ...)` is the source-level spelling for CodePage `0`, flags `0`; the source count excludes the wide NUL by using `wcslen`.
- `encodedText[encodedLength] = 0` and `packet[packetLength] = 0` are local terminators. `QueueAndSendPacket` receives only `packetLength`, which is `encodedLength + 2`.

## Heuristic / Inference Reanalysis

### Helper names and stale raw labels

The target should stop using raw `sub_` names as unresolved blockers:

- `sub_4F2310` -> `LineInputPane::TextLength()` or `TextLength()` in class-local source prose.
- `sub_4F2300` -> `LineInputPane::CopyText(...)` or `CopyText(...)`.
- `sub_516030` -> [UID:0001BC] `GetMemoryMan`.
- `sub_575380` -> [UID:0003YJ] `PacketBufferWriteUInt8`.
- `sub_516220` -> [UID:0001BH] `MemoryMan::MemmoveWrapper`, source-level payload copy can be rendered as `memmove(...)`.
- `dword_67A7EC` -> [UID:0000Q5] `Socket *g_packetSender`.
- `sub_574BB0` -> [UID:0001HU] `Socket::QueueAndSendPacket`.

The older "clears/reset state" interpretation for `0x00516030` is rejected. The call exists because the compiler/source path obtains the MemoryMan singleton used by the later copy wrapper. It has no LineInputPane or input-state side effect.

### Formal C++ source shape

Recommended formal C++ should be source-like, not decompiler-shaped:

- Keep `GroupInputPane::OnConfirmInput()` as the method body, matching the class page declaration and vtable route.
- Use class-local `TextLength()` and `CopyText(...)` names consistent with [UID:00005W] and nearby CommandInputPanes first-draft code.
- Use `PacketBufferWriteUInt8` for the two one-byte packet fields because the helper is explicit, accepted, and source-facing enough.
- Use `memmove(packet + 2, encodedText, encodedLength)` for the payload copy. The binary routes this through `GetMemoryMan()` and `MemoryMan::MemmoveWrapper`, but accepted string-packet source drafts already model feature-level byte copies with ordinary C/C++ copy calls while target prose preserves the exact helper dependency.
- Use `g_packetSender->QueueAndSendPacket(...)` because [UID:0000Q5] now documents `g_packetSender` as best current `Socket *`, and [UID:0001HU] documents `QueueAndSendPacket` as a Socket method. A wrapper-style `QueueAndSendPacket(g_packetSender, ...)` would be behavior-equivalent and appears in some existing generated snippets, but the member-call spelling is more plausible human C++ for this exact sender.
- Do not emit vtable stores, security-cookie checks, raw stack locals `Src/v10/v11`, `result` temporaries, or `__report_rangecheckfailure` calls as handwritten source statements.

### Range-check interpretation

The binary branches to `___report_rangecheckfailure` when array-index bounds are violated. This should be documented as compiler range-check scaffolding around local array writes:

- `encodedText[encodedLength] = 0` has a `0x100` / 256-byte local bound.
- `packet[packetLength] = 0` has a `0x12c` / 300-byte local bound.

Unlike some accepted sibling drafts that use early returns for readability, this target does not need explicit source `if (encodedLength >= 0x100) return;` or `if (packetLength >= 0x12c) return;`. Direct indexed writes are the better source-level representation because they explain the compiler-generated range-check tail without inventing game-visible error handling.

### Owner/source placement

Accepted direct owner remains [UID:00005W] `GroupInputPane`.

Accepted source-file route remains [UID:0000ID] `CommandInputPanes` / `NexusTK/ui/dialogs/CommandInputPanes.cpp`.

Evidence:

- The vtable slot `0x0063011c -> 0x005b5440` is a direct data xref to this method.
- The constructor child [UID:0002SB] now emits `GroupInputPane::GroupInputPane()` and installs the same class vtables.
- The open-helper and dispatcher mirrors allocate `0x108` / 264 bytes, use prompt id `0x2f`, and install the same three `GroupInputPane` vtables.
- The class page already emits a declaration shell with `GroupInputPane()`, `OnConfirmInput()`, and `kGroupPromptStringId = 0x2f`.
- [UID:0000ID] already owns the command input pane source route, including Emotion and Post input context.

Rejected owners:

- [UID:0000JS] `Group`: feature cross-reference only. It does not own this command-input source module.
- [UID:000077] `LineInputPane`: base class/dependency only.
- [UID:0000Q5] `g_packetSender`, [UID:0001HU] `QueueAndSendPacket`, [UID:0003YJ] `PacketBuffer`, and [UID:0001BH] `MemoryMan::MemmoveWrapper`: dependencies only.
- [UID:0001LZ] `SayToGroupMessageInputPane`: separate say-message target input, opcode `0x19`, different class/source family.
- [UID:0002N6] vtable data: source-declared/generated-binary evidence only, not method owner.

## Exact Formal RECONSTRUCTION_CPP CODE

If the supervisor accepts this report, replace [UID:0001MJ]'s formal reconstruction block with the exact marker/block below. Do not treat this as an illustrative snippet, and do not paste the Markdown fence into the target document.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void GroupInputPane::OnConfirmInput()
{
    if (TextLength() <= 0) {
        return;
    }

    wchar_t inputText[256];
    CopyText(inputText, 255);

    unsigned char packet[300];
    PacketBufferWriteUInt8(0x2e, packet);

    char encodedText[256];
    const int encodedLength = WideCharToMultiByte(
        CP_ACP,
        0,
        inputText,
        static_cast<int>(wcslen(inputText)),
        encodedText,
        static_cast<int>(sizeof(encodedText)),
        NULL,
        NULL);
    encodedText[encodedLength] = 0;

    PacketBufferWriteUInt8(static_cast<unsigned char>(encodedLength), packet + 1);
    memmove(packet + 2, encodedText, encodedLength);

    const int packetLength = encodedLength + 2;
    packet[packetLength] = 0;

    g_packetSender->QueueAndSendPacket(packet, static_cast<short>(packetLength));
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Behavioral match notes:

- The first return matches the `TextLength() <= 0` branch.
- `CopyText(inputText, 255)` matches the `0xff` copy cap.
- `CP_ACP` is source-level CodePage `0`.
- The payload copy can compile through the accepted MemoryMan wrapper path; target prose should still document `GetMemoryMan`/`MemoryMan::MemmoveWrapper` as binary facts.
- Local terminators are retained but not sent.
- Sent length is exactly `encodedLength + 2`.

## Score And Metadata Rationale

Target [UID:0001MJ] should move from `85/88` to `90/92`.

Completion rises because the page can now document:

- exact modeled function range and boundary;
- current MCP session/tool provenance;
- vtable route and no direct code callers;
- exact callee set with source-facing helper names;
- corrected `GetMemoryMan` interpretation;
- packet layout, buffer sizes, length calculation, and local-only terminators;
- accepted owner/source route;
- rejected owners and stale assumptions;
- formal first-draft C++.

Confidence rises because current MCP, accepted support docs, and adjacent class/constructor docs all agree. It should remain below `95` because:

- exact original helper/local/callback spellings are inferred rather than symbol-recovered;
- the source-level representation of MemoryMan copy helper versus `memmove` remains a source-shape inference;
- class/file source grouping is strong but still not backed by original source-file metadata;
- the range-check failure path is recognized as compiler scaffolding, but exact compiler settings are not recovered.

Support score recommendations:

- [UID:00005W] `by-class/GroupInputPane.md`: raise from `87/90` to `88/91` after implementation, because both constructor and submit children will carry source-ready first-draft C++ and the class open question about submit C++ is closed. Keep class-level C++ declaration as-is unless the supervisor wants only text updates.
- [UID:0000ID] `by-file/CommandInputPanes.md`: no score change required. Add a support note/row update for the now source-ready GroupInputPane submit method, but broader command/spell/social split caveats still justify `86/86`.
- [UID:0000Q5] `by-global/g_packetSender.md`: no score change required. Add a focused consumer note for the opcode `0x2e` GroupInputPane path if the supervisor accepts a support-doc sync.
- [UID:0003YJ] `PacketBufferScalarBigEndianWriteHelpers`, [UID:0001BH] `MemmoveWrapper`, [UID:0001BC] `GetMemoryMan`, [UID:0001HU] `QueueAndSendPacket`, [UID:00035R] `LineInputPaneCopyText`, and [UID:00035S] `LineInputPaneTextLength`: no edits required unless supervisor wants additional consumer notes. They already contain same-or-greater support detail for their own behavior.

## Recommended Target Doc Changes

Target path: `by-memory/0x005b5440-0x005b5547.GroupInputPane.md`.

Apply these changes during an implementation callback:

- Set `COMPLETION:90`.
- Set `CONFIDENCE:92`.
- Preserve owner/emitter/reconstructable metadata:
  - `CANONICAL_OWNER:00005W`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:00005W`
  - blank `EMITTER_POSITION_OPTIONAL`
  - `Nested:0`
- Replace the blank formal C++ block with the exact block from this report.
- Replace the item summary with an equivalent of:

```text
Source-ready GroupInputPane submit method: current B009 MCP session `agent_b009_0002my_20260628` confirms exact `0x005b5440-0x005b5547` / `0x107`-byte virtual handler, vtable slot `0x0063011c -> 0x005b5440`, LineInputPane text length/copy calls, `GetMemoryMan` plus `MemoryMan::MemmoveWrapper` payload copy, `PacketBufferWriteUInt8` opcode/length writes, `WideCharToMultiByte` CP_ACP conversion, packet layout `[0x2e, encodedLength, encodedText...]`, local-only terminators, `g_packetSender->QueueAndSendPacket(packet, encodedLength + 2)`, and formal first-draft `GroupInputPane::OnConfirmInput()` C++.
```

- Update `Status`, `IDA MCP Evidence`, `Submit Packet Layout`, `Touched State And Dependencies`, `Reconstruction Notes`, and `Changes` to preserve:
  - current MCP session/database and health state;
  - target size `0x107` / 263 bytes (Verified with int_convert.py);
  - `0x005b5547` not-a-function end boundary;
  - vtable data xref `0x0063011c`;
  - no xrefs to `0x005b5400` retained as constructor caveat only;
  - exact callee list and source-facing helper names;
  - `0x00516030` corrected from input reset to `GetMemoryMan`;
  - packet layout and local-only terminator;
  - range-check path as compiler scaffolding;
  - rejected owners/source alternatives.
- Replace raw `sub_575380`, `sub_516220`, `sub_574BB0`, `dword_67A7EC`, `sub_4F2300`, and `sub_4F2310` text with source-facing names while preserving raw labels as historical/search aliases where useful.
- Keep the constructor child [UID:0002SB] split and first-draft constructor note; do not merge constructor C++ into this target.

## Recommended Support Doc Changes

### [UID:00005W] `by-class/GroupInputPane.md`

Recommended:

- Raise `COMPLETION:87 -> 88`.
- Raise `CONFIDENCE:90 -> 91`.
- Preserve `CANONICAL_OWNER:0000ID`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000ID`, and class declaration C++.
- Update `Status`, `Method Notes`, `Assignment Gate`, `Source Placement And C++ Notes`, and `Changes` to say [UID:0001MJ] now carries first-draft `GroupInputPane::OnConfirmInput()` C++.
- Replace "submit method C++ remains separate work" with "submit method C++ is source-ready on [UID:0001MJ] after B009 current MCP source-quality pass."
- Preserve that method bodies remain on exact by-memory children and class-level C++ stays declaration-only with `[[CHILDREN]]`.

No class declaration change is required unless the supervisor wants a naming tweak. The existing declaration already has:

- `GroupInputPane();`
- `void OnConfirmInput() override;`
- `static const int kGroupPromptStringId = 0x2f;`
- `[[CHILDREN]]`

### [UID:0000ID] `by-file/CommandInputPanes.md`

Recommended:

- No score change.
- Update the `GroupInputPane` row in `Proposed Contents` to state that both [UID:0002SB] constructor and [UID:0001MJ] submit method now carry first-draft C++.
- Add a support note in `Boundary And Data Notes` / `Source Placement Notes`:
  - [UID:0001MJ] is the source-ready opcode `0x2e` group-command submit method.
  - Current B009 MCP session confirms `TextLength`, `CopyText`, `WideCharToMultiByte`, `PacketBufferWriteUInt8`, `GetMemoryMan`/`MemoryMan::MemmoveWrapper`, and `g_packetSender->QueueAndSendPacket`.
  - This does not move the class to [UID:0000JS] `Group` and does not conflate it with [UID:0001LZ] `SayToGroupMessageInputPane`.
- Update the change log with the accepted B009 report and target score movement if implemented.

### [UID:0000Q5] `by-global/g_packetSender.md`

Recommended:

- No score, owner, emitter, or C++ change.
- Add [UID:0001MJ] as a consumer note:
  - `GroupInputPane::OnConfirmInput()` builds opcode `0x2e`, one-byte encoded-length field, converted text bytes, writes a local-only terminator outside the sent length, and queues exactly `encodedLength + 2` bytes through `g_packetSender->QueueAndSendPacket`.
  - This is consumer/type evidence only; [UID:0000NS] `Socket` remains the global owner/emitter and `GroupInputPane` remains feature/source owner for the packet builder.

### No-Edit Support Decisions

No implementation edits are required for these support docs unless the supervisor broadens the callback:

- [UID:0003YJ] `PacketBufferScalarBigEndianWriteHelpers`: already documents `PacketBufferWriteUInt8`, value-first raw ABI, and scratch zero semantics.
- [UID:0001BH] `MemmoveWrapper`: already source-ready as `MemoryMan::MemmoveWrapper` and documents feature callers may use source-level `memmove`.
- [UID:0001BC] `GetMemoryMan`: already source-ready and proves `0x00516030` returns the MemoryMan singleton.
- [UID:0001HU] `QueueAndSendPacket`: already source-quality enough for the Socket queue/send method and local terminator semantics.
- [UID:00035R] and [UID:00035S] LineInputPane accessors: already document the copy and text-length helpers.
- [UID:0002N6] Group/Post vtable data: already documents `0x0063011c -> 0x005b5440` and the GroupInputPane vtable stores.
- [UID:0002SB] constructor child: already source-ready and should only be referenced, not changed.
- [UID:0000JS] `Group`: no required change. It remains a feature cross-reference, not direct source owner.

## Generated And Coverage State

Do not manually edit generated reports or generated C++.

Expected after accepted implementation and scoped validation:

- `auto-generated/NexusTK/ui/dialogs/CommandInputPanes.cpp` should no longer contain the [UID:0001MJ] Empty Emitter Marker.
- The generated C++ should contain the `GroupInputPane::OnConfirmInput()` body from this report under [UID:0001MJ].
- `auto-generated/-ag-coverage-report-by-memory.md` should eventually show [UID:0001MJ] `emits_code:true`.
- `auto-generated/-ag-research-tracker.md` should refresh after the supervisor later executes the accepted report.

No explicit manual `by-memory/-coverage-report.md` replacement text is required for this assignment. If a supervisor still chooses to sync the legacy manual coverage file, use the target item summary facts above; B009 must not edit that file directly.

## Suggested Validators For Implementation Callback

Run scoped validators only after accepted by-* edits, from `E:\NTK\GhidraBridge\source-3\project-documentation`.

Suggested commands:

> Executable block R001 was removed from this report and preserved verbatim in [0001MJ-GroupInputPane-empty-emitter-source-quality-removed.md](0001MJ-GroupInputPane-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the supervisor accepts no `g_packetSender` edit, skip that validator. If generated output matters for final callback proof, inspect `auto-generated/NexusTK/ui/dialogs/CommandInputPanes.cpp` after the target/class/file validators and compare `validator-command-id` / `validator-refreshed-at` against the returned command metadata.

Supervisor-owned execution command after implementation verification:

> Executable block R002 was removed from this report and preserved verbatim in [0001MJ-GroupInputPane-empty-emitter-source-quality-removed.md](0001MJ-GroupInputPane-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

B009 must not run `execute_report`.

## Remaining Risks And Follow-Up

No blocker remains for [UID:0001MJ] first-draft C++.

Residual risks that cap the score below final-audit level:

- exact original source names for locals and helper wrappers are not recovered;
- original source-file metadata for `CommandInputPanes.cpp` versus a more granular social command file is not recovered;
- project-wide final style still varies between `QueueAndSendPacket(g_packetSender, ...)` and `g_packetSender->QueueAndSendPacket(...)`;
- `memmove(...)` is chosen as the feature-level source copy while the binary routes through `GetMemoryMan` and `MemoryMan::MemmoveWrapper`.

These are documented source-shape caveats, not reasons to leave the emitter blank.

## Implementation Tracking Checklist

Implementation callback completed by B009 on 2026-06-28/2026-06-29. Supervisor still owns final `execute_report`.

- [x] Supervisor validates and accepts this report before any by-* implementation edits. Proof: supervisor callback in updated `goal.md` accepted `tools/leaser/Agents/Agent-B009/research/0001MJ-GroupInputPane-empty-emitter-source-quality.md` and instructed implementation for [UID:0001MJ].
- [x] Lease only the immediate by-* edit batch after acceptance; no reservation leases. Proof: B009 first leased exactly `by-memory/0x005b5440-0x005b5547.GroupInputPane.md`, `by-class/GroupInputPane.md`, `by-file/CommandInputPanes.md`, and `by-global/g_packetSender.md`; first window was `2026-06-29T03:00:51Z` to `2026-06-29T03:05:51Z`. A mid-batch refresh attempt was rejected as "Already has lease"; after expiry, B009 re-leased the same four files at `2026-06-29T03:05:58Z` only to complete the validator batch.
- [x] Target [UID:0001MJ] `by-memory/0x005b5440-0x005b5547.GroupInputPane.md`: set `COMPLETION:90`, `CONFIDENCE:92`; preserve owner `00005W`, reconstructable true, emitter `00005W`, blank optional emitter position, and `Nested:0`. Proof: target header now has `90/92`, `CANONICAL_OWNER:00005W`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00005W`, blank `EMITTER_POSITION_OPTIONAL`, and `Nested:0`; validator `000000000178` recorded `completion_update 0001MJ ... 90` and `confidence_update 0001MJ ... 92`.
- [x] Target [UID:0001MJ]: replace the blank formal reconstruction block with the exact `GroupInputPane::OnConfirmInput()` formal block from this report. Proof: target managed multiline block now contains only the C++ function body between existing `RECONSTRUCTION_CPP CODE:BEGIN` and `END`; the report's markdown header/footer lines were not pasted.
- [x] Target [UID:0001MJ]: update item summary and body sections with current MCP session `agent_b009_0002my_20260628`, exact function size/boundary, vtable slot, helper names, packet layout, local terminator semantics, range-check interpretation, and rejected alternatives. Proof: target `Item Summary`, `IDA MCP Evidence`, `Submit Packet Layout`, `Touched State And Dependencies`, `Ownership Decision`, `Reconstruction Notes`, and `Changes` now record those facts at report-level detail.
- [x] Target [UID:0001MJ]: correct stale `0x00516030` "clears/reset state" wording to [UID:0001BC] `GetMemoryMan`. Proof: target now marks the old reset/clear assumption as superseded/rejected and identifies raw `0x00516030` as [UID:0001BC] `GetMemoryMan`; class support page repeats the correction.
- [x] Target [UID:0001MJ]: replace unresolved raw helper labels with source-facing names while preserving raw aliases only as historical/search labels. Proof: target uses `LineInputPaneTextLength`, `LineInputPaneCopyText`, `GetMemoryMan`, `PacketBufferWriteUInt8`, `MemoryMan::MemmoveWrapper`, `g_packetSender`, and `Socket::QueueAndSendPacket`, while keeping raw `sub_`/address aliases only as trace labels in evidence tables.
- [x] Support [UID:00005W] `by-class/GroupInputPane.md`: raise to `88/91`, preserve owner/emitter, and update method/source/C++ notes so [UID:0001MJ] is no longer a blank submit-C++ blocker. Proof: class header is `88/91`, owner/emitter remain `0000ID`, and `Method Notes`, `Evidence Notes`, `Assignment Gate`, `Source Placement And C++ Notes`, and `Changes` now identify [UID:0001MJ] as source-ready first-draft submit C++. Validator `000000000179` recorded `completion_update 00005W ... 88` and `confidence_update 00005W ... 91`.
- [x] Support [UID:0000ID] `by-file/CommandInputPanes.md`: update the GroupInputPane row/notes/change log with [UID:0001MJ] source-ready opcode `0x2e` submit C++ and preserve CommandInputPanes ownership. Proof: `Proposed Contents`, `Boundary And Data Notes`, `Source Placement Notes`, and `Changes` now state that [UID:0001MJ] emits first-draft `GroupInputPane::OnConfirmInput()` for opcode `0x2e` while preserving [UID:0000ID] as the command-input file route; scores remain `86/86`.
- [x] Support [UID:0000Q5] `by-global/g_packetSender.md`: if accepted by supervisor, add a no-score-change consumer note for [UID:0001MJ]'s opcode `0x2e` path and preserve Socket ownership. Proof: global page now has a 2026-06-28 [UID:0001MJ] consumer note and change-log entry; header remains `86/88`, owner/emitter remain [UID:0000NS] Socket, and formal C++ remains blank.
- [x] Confirm no edits are needed to PacketBuffer, MemmoveWrapper, GetMemoryMan, QueueAndSendPacket, LineInputPane accessor, vtable, constructor, or Group docs unless supervisor callback explicitly broadens scope. Proof: no edits were made to those check-only support docs; their accepted facts were incorporated by UID reference into the target/support pages instead.
- [x] Run scoped validators for every edited by-* file and record command, `command_id`, `command_timestamp`, exit code, `ok` count, warnings, and generated-refresh state. Proof:
  - `python .\tools\validator.py --mode file --file by-memory\0x005b5440-0x005b5547.GroupInputPane.md --apply --queue-timeout 240 --wait-generated` -> command `000000000178`, timestamp `2026-06-28T23:05:10-04:00`, exit `0`, `ok: 1`, generated refresh `completed` for command `000000000178`. Diagnostics included pre-existing/mapped missing references `0003MW` and stale old [UID:0001MK] target path plus broad existing autogen registry/memory-coverage missing-file diagnostics.
  - `python .\tools\validator.py --mode file --file by-class\GroupInputPane.md --apply --queue-timeout 240 --wait-generated` -> command `000000000179`, timestamp `2026-06-28T23:05:41-04:00`, exit `0`, `ok: 1`, generated refresh `completed` for command `000000000179`. Diagnostics included missing `0003MW` plus the same broad existing generated registry/missing-file diagnostics.
  - `python .\tools\validator.py --mode file --file by-file\CommandInputPanes.md --apply --queue-timeout 240 --wait-generated` -> command `000000000180`, timestamp `2026-06-28T23:06:07-04:00`, exit `0`, `ok: 1`, generated refresh `completed` for command `000000000180`. Diagnostics included pre-existing missing refs/targets on `0003HI`, `0003HK`, `0003O7`, `0003O6`, `0003O5`, `0003HM`, old [UID:0001MK] and [UID:0001MU] target paths, plus broad existing generated registry/missing-file diagnostics.
  - `python .\tools\validator.py --mode file --file by-global\g_packetSender.md --apply --queue-timeout 240` -> command `000000000181`, timestamp `2026-06-28T23:06:24-04:00`, exit `0`, `ok: 1`, generated refresh `deferred` for command `000000000181`; queue-status command `000000000182` at `2026-06-28T23:06:44-04:00` showed `queued generated refresh jobs: 0` and `processing generated refresh jobs: 0`. Diagnostics were pre-existing missing ref UID `0003UT`.
- [x] Verify generated `auto-generated/NexusTK/ui/dialogs/CommandInputPanes.cpp` is current for the target/class/file validator batch and no longer shows [UID:0001MJ] as an Empty Emitter Marker. Proof: generated header shows `validator-command-id: 000000000180` and `validator-refreshed-at: 2026-06-28T23:06:07-04:00`; `rg` finds `// UID:0001MJ ... Completion:90 | Confidence:92` at line 144 and `void GroupInputPane::OnConfirmInput()` at line 145. `rg` finds other empty markers in the generated file, but none for UID0001MJ. Validator-owned generated coverage also caught up: `auto-generated/-ag-memory-coverage.md` shows UID0001MJ as `coded`, `auto-generated/-ag-research-tracker.md` shows `90/92`, and `auto-generated/-ag-coverage-report-by-memory.md` shows `emits_code:true`.
- [x] Do not manually edit generated reports, generated C++ files, project-level generated files, manual `-coverage-report.md` files, validator/tool state, or IDA DB. Proof: only target/support by-* docs and this B009 report checklist were manually edited; generated files changed only through validator commands.
- [x] Release all leases immediately after the edit/validator batch and record release or expiry proof. Proof: `python .\tools\leaser\leaser.py B009 unlease ...` returned `Success` for all four by-* paths after validation/generation inspection; current `tools/leaser/Agents/current_leases.md` then showed no B009 lease entries.
- [x] Update this checklist during implementation with proof for every checked item. Proof: this checklist now records per-item implementation proof and validator/generated/lease evidence.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000004165","destination_path":"executed-b-agent-research/B009/0001MJ-GroupInputPane-empty-emitter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/0001MJ-GroupInputPane-empty-emitter-source-quality.md","timestamp":"2026-06-28T23:20:31","uid":"0001MJ"} -->
<!-- {"agent":"B009","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001MJ-GroupInputPane-empty-emitter-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B009/0001MJ-GroupInputPane-empty-emitter-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001MJ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
