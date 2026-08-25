** TARGET-REPORT-UID:0001M4 **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001M4 SendEmotionPacket Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: accept [UID:0001M4] `by-memory/0x005b2f70-0x005b2fcb.SendEmotionPacket.md` as a reconstructable, code-emitting, file-local/static Emotion packet helper under [UID:0000ID] `CommandInputPanes`.
- Final disposition: keep owner/emitter [UID:0000ID], keep `RECONSTRUCTABLE:TRUE`, and keep the source-facing helper name `SendEmotionPacket`.
- Required action: update the formal helper C++ to preserve the observed 128-byte local scratch packet buffer instead of the current behavior-equivalent but source-shape-weaker `packet[3]`; update the target evidence/score rationale for the current MCP recheck and the stale generated tracker row.
- Confidence: very strong for range, callers, opcode, helper dependencies, static/file-local source shape, and padding; original helper spelling remains inferred.

## Target

- Target UID: [UID:0001M4]
- Target path: `by-memory/0x005b2f70-0x005b2fcb.SendEmotionPacket.md`
- Assigned report path: `tools/leaser/Agents/Agent-B009/research/0001M4-SendEmotionPacket-source-quality.md`
- Source queue/report row: `auto-generated/-ag-research-tracker.md` currently lists this target under not-covered-style research state at stale `76/86`, while the source target page is already `87/90` and `auto-generated/-ag-memory-coverage.md` marks it `coded`.
- Current supervisor classification: source-quality recheck of an already-documented helper selected from a stale generated tracker row.
- Pre-implementation scores and parent state at report time: target page was `COMPLETION:87`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000ID`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000ID`. The accepted implementation callback updated the target to `88/91` with the same owner/emitter/reconstructable route; see the implementation checklist proof below.

## Current Target State

- Pre-implementation metadata: `87/90`, owner/emitter [UID:0000ID] `CommandInputPanes`, reconstructable true.
- Existing C++ state: formal `RECONSTRUCTION_CPP CODE` is nonblank and uses a file-local `static void SendEmotionPacket(int selector)`, opcode `0x1d`, `PacketBufferWriteUInt8(selector - 0x0b, packet + 1)`, local `packet[2] = 0`, and `QueueAndSendPacket(g_packetSender, packet, 2)`.
- Existing issue found in this pass: the formal C++ uses `unsigned char packet[3]`, but live IDA MCP disassembly/decompilation shows the helper reserves a 0x80-byte contiguous packet scratch region before the security cookie. Nearby accepted packet-helper reports use `packet[128]` when the stack frame proves that source-shaped fixed buffer. `packet[3]` is behavior-equivalent for sent bytes, but it is less faithful to the likely precompiled C++ source and should be corrected.
- Related support docs checked: [UID:0001M3] `by-memory/0x005b29c0-0x005b2f68.EmotionInputPane.md`, [UID:00004B] `by-class/EmotionInputPane.md`, [UID:0000ID] `by-file/CommandInputPanes.md`, [UID:0000Q5] `by-global/g_packetSender.md`, [UID:0001HU] `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md`, and [UID:0003YJ] `by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md`.
- Old report checked: central executed `executed-b-agent-research/B009/00004B-EmotionInputPane-class-source-quality.md`. It is valid lead material and already drove most current documentation, but it supplied a non-formal `packet[3]` reference shape before this target-specific buffer-size audit.

## Executive Recommendation

Keep [UID:0001M4] directly routed to [UID:0000ID] `CommandInputPanes` as a file-local/static helper used only by `EmotionInputPane::OnCharInput`. Do not move it to PacketBuffer, Socket, Chatting, SystemMessagePanes, or ordinary `EmotionInputPane` instance-method ownership.

Recommended source-quality repair is narrow:

- Preserve existing metadata except consider raising confidence by one point after implementation because the current MCP pass closes the formal C++ buffer-shape issue.
- Replace the formal C++ block with the exact header/block text below using `unsigned char packet[128]`.
- Keep the target `Item Summary` concise but update prose to state the local scratch buffer is 128 bytes while only two bytes are sent.
- Do not manually edit generated tracker or coverage files. The stale `auto-generated/-ag-research-tracker.md` row should refresh only through the supervisor's executed-report/validator lifecycle.

## Inference Research Guidance Check

IDA facts, documentation evidence, and inference were kept separate. IDA proves the range, call sites, callees, stack frame, padding, and global/helper reads. Documentation confirms current source routes and support names. Inference is limited to original source spelling and whether the helper was file-local `static` versus a private static class method.

No current Wave2/Wave3 evidence was used. Any historical Wave2/Wave3 mentions in older notes are stale under the active skill rules and were ignored.

## Heuristic / Inference Reanalysis And Validation

| Issue | Resolution |
| --- | --- |
| Helper name | `SendEmotionPacket` remains the best source-facing name. It is feature-specific, called only by the Emotion input handler, and sends the Emotion opcode. Original spelling is not proven, but this is stronger than any raw `sub_5B2F70` label. |
| Source placement | [UID:0000ID] `CommandInputPanes` remains best. `EmotionInputPane` already belongs to this file route, and the helper is adjacent and called only from the Emotion handler. A future `EmotionInputPane.cpp` split remains plausible but unproven. |
| Static/file-local vs instance method | File-local `static` is best. Callers load `ecx = this`, but the helper never reads `ecx` and returns `ret 4`; ordinary instance-method ownership is not supported. A private static class method would be source-compatible but slightly more invented. |
| Packet writer name and ABI | `PacketBufferWriteUInt8` remains the best descriptive name for `0x00575380`. Current support docs prove value-first raw ABI. |
| Sender global and send route | `g_packetSender` and `QueueAndSendPacket` remain correct source-facing support names for `0x0067a7ec` and `0x00574bb0`. |
| Opcode and selector transform | Opcode is `0x1d` / decimal `29` (Verified with int_convert.py). Helper subtracts `0x0b` / decimal `11` (Verified with int_convert.py) from its caller-provided selector argument. |
| Caller-side selector split | Stays on [UID:0001M3], not this helper: `a-l` passes `ch - 0x56` / decimal `86`, `m-n` passes `ch - 0x64` / decimal `100`, and `o-p` passes `ch - 0x58` / decimal `88` (Verified with int_convert.py). |
| Local buffer size | Current target formal C++ should change from `packet[3]` to `packet[128]`. IDA disassembly reserves `sub esp, 84h`, with packet byte 0 at `[ebp-0x84]`, packet byte 1 at `[ebp-0x83]`, packet byte 2 at `[ebp-0x82]`, and the security cookie at `[ebp-0x4]`. This leaves a contiguous 128-byte scratch packet buffer before the cookie. |
| Padding | `0x005b2f68-0x005b2f70` is eight `0xcc` bytes and `0x005b2fcb-0x005b2fd0` is five `0xcc` bytes. Both remain alignment, not source code. |

Rejected alternatives:

- PacketBuffer ownership: rejected because PacketBuffer owns the scalar writer, not the Emotion opcode helper.
- Socket ownership: rejected because Socket owns `g_packetSender` and queue/send behavior, not the feature-level packet construction.
- Chatting/ChatInputPane ownership: rejected because this helper sends opcode `0x1d`, while ChatInputPane sends opcode `0x0e`.
- SystemMessagePane ownership: rejected because SystemMessagePane/OldSystemMessagePane are `?` help-menu display dependencies of `EmotionInputPane`, not packet-send owners.
- Ordinary `EmotionInputPane` instance method: rejected because the helper does not read `ecx` or object fields.
- Keeping `packet[3]` in final formal C++: rejected as less source-faithful than the proven 128-byte local scratch buffer, even though it sends identical two-byte payload at this abstraction level.

## Evidence Standards Used

- IDA MCP session: `80de0a67`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready.
- MCP tools used in this pass: `server_health`, `tools/list`, `lookup_funcs`, `xrefs_to`, `xref_query`, `callees`, `decompile`, `disasm`, `get_bytes`, and `find_bytes`.
- Numeric conversion tool used: `python .\tools\int_convert.py` from `source-3/project-documentation`.
- Documentation evidence: current by-* target/support pages plus central executed B009 EmotionInputPane class report.
- Generated evidence: current `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-memory-coverage.md`, and `auto-generated/-ag-coverage-report-by-memory.md` were read only.

## Evidence Checked

IDA MCP/manual-disassembly/raw-byte checks performed:

- `server_health` reported status `ok`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`.
- `lookup_funcs` reports `0x005b2f70` as `sub_5B2F70`, size `0x5b` / decimal `91` (Verified with int_convert.py). `0x005b2fcb`, `0x005b2fd0`, and `0x005b2f68` are not function starts.
- `lookup_funcs` also reconfirmed caller functions `0x005b29c0` size `0xb0` and `0x005b2a70` size `0x4f8`, support writer `0x00575380` size `0x11`, and send funnel `0x00574bb0` size `0x63`.
- `xrefs_to 0x005b2f70` reports exactly three code callers: `0x005b2aef`, `0x005b2b15`, and `0x005b2f52`, all in `sub_5B2A70`.
- `callees 0x005b2f70` reports `0x00575380` (`sub_575380`), `0x00574bb0` (`sub_574BB0`), and `@__security_check_cookie@4`.
- `decompile 0x005b2f70` shows `Src = 29`, `sub_575380(a1 - 11, v3)`, `v3[1] = 0`, and `sub_574BB0((_BYTE *)dword_67A7EC, &Src, 2)`.
- `disasm 0x005b2f70` shows `sub esp, 84h`, `lea eax, [ebp+var_83]`, `mov [ebp+Src], 1Dh`, `add eax, 0FFFFFFF5h`, `call sub_575380`, `mov ecx, dword_67A7EC`, `mov [ebp+var_82], 0`, `push 2`, `call sub_574BB0`, stack-cookie check, and `retn 4`.
- Caller decompile/disassembly confirms the split selector call sites: `0x005b2aef` pushes `ch - 0x56`, `0x005b2b15` pushes `ch - 0x64`, and `0x005b2f52` pushes `ch - 0x58`.
- `get_bytes` reports `0x005b2f68` as eight `0xcc` bytes and `0x005b2fcb` as five `0xcc` bytes.
- `find_bytes` for little-endian absolute VA `70 2f 5b 00`, RVA-style `70 2f 1b 00`, and PE raw-offset `70 23 1b 00` found zero matches. This supplements IDA xrefs by showing no simple pointer-table route to the helper start.

Documentation/generator checks performed:

- Target [UID:0001M4] already contains most accepted B009 facts, current `87/90`, formal helper C++, and the same owner/emitter route.
- [UID:0001M3] documents the caller-side split and keeps formal C++ blank for the multi-method constructor/handler cluster.
- [UID:00004B] documents the class-level route and intentionally keeps class-page C++ blank.
- [UID:0000ID] documents Emotion as part of the current command-input file route and rejects PacketBuffer/Socket/SystemMessagePanes ownership.
- [UID:0000Q5], [UID:0001HU], and [UID:0003YJ] support `g_packetSender`, `QueueAndSendPacket`, and `PacketBufferWriteUInt8`.
- Current `auto-generated/-ag-research-tracker.md` still lists [UID:0001M4] as `76/86`, which is stale compared with the target page. No generated/project-level file was edited.

Failed/unavailable checks: none. MCP was responsive after the resume slot became available.

## Inference Claim Ledger

| Claim | Confidence | Evidence | Counter-evidence checked | Next verification / remaining uncertainty |
| --- | --- | --- | --- | --- |
| Helper range is exactly `0x005b2f70-0x005b2fcb`. | Very strong | MCP `lookup_funcs`, decompile, disasm, and padding bytes. | `0x005b2fcb` and `0x005b2fd0` are not function starts; following bytes are `0xcc`. | None for current range. |
| Direct source route is `CommandInputPanes.cpp`. | Strong | Emotion class/file docs, caller-only relationship to `EmotionInputPane::OnCharInput`, feature-local opcode helper, dependency rejection. | PacketBuffer, Socket, Chatting, SystemMessagePanes, ordinary instance method considered and rejected. | Exact original file split (`CommandInputPanes.cpp` vs `EmotionInputPane.cpp`) remains inferred. |
| Helper should be file-local/static. | Strong | No `ecx` read, `ret 4`, no object field access, no pointer-table route, only Emotion handler callers. | Callers set `ecx = this`, but callee ignores it. | A recovered header could prove private static class-member spelling; behavior and file route would not change. |
| Formal C++ should use `packet[128]`. | Strong | Stack frame reserves 0x84 bytes with 128-byte contiguous scratch packet before security cookie; accepted sibling packet-helper precedent uses 128-byte packet buffers when proven. | `packet[3]` is behavior-equivalent for sent bytes, but less source-faithful. | Final project-wide packet-helper style could choose `char` vs `unsigned char`. |
| Sent protocol payload is exactly two bytes. | Very strong | Decompile/disasm sends length `2`; local `packet[2]`/`var_82` is not transmitted. | No evidence of send length `3`; packet terminator is outside counted length. | None. |

## Positive Evidence Summary

- IDA MCP proves the function is modeled, small, exact, and only directly called by `EmotionInputPane::OnCharInput`.
- The helper body is pure packet construction/send logic: opcode `0x1d`, transformed selector byte, scratch zero, and two-byte send.
- Support docs already resolve raw names away from IDA placeholders: `PacketBufferWriteUInt8`, `g_packetSender`, and `QueueAndSendPacket`.
- The helper does not consume `ecx`, supporting file-local/static helper shape.
- Padding before and after is confirmed `0xcc` alignment, so the target boundary is clean and does not overlap [UID:0001M3] or the following ChangeItemSlot neighborhood.

## IDA MCP Facts

- Function/range facts: `0x005b2f70` is `sub_5B2F70`, size `0x5b`; `0x005b2fcb` and `0x005b2fd0` are not functions.
- Data/table/padding facts: `0x005b2f68-0x005b2f70` is eight `0xcc` bytes; `0x005b2fcb-0x005b2fd0` is five `0xcc` bytes.
- Xref facts: exactly three code callers to the helper start: `0x005b2aef`, `0x005b2b15`, and `0x005b2f52`, all inside `0x005b2a70`.
- Callee facts: calls `sub_575380`, `sub_574BB0`, and `@__security_check_cookie@4`; reads `dword_67A7EC`.
- Negative IDA/raw facts: no IDA xrefs outside the three call sites; no simple absolute VA/RVA/raw-offset byte-pattern hits for the helper start.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x005b29c0-0x005b2f68` | [UID:0001M3] `by-memory/0x005b29c0-0x005b2f68.EmotionInputPane.md` | constructor plus virtual input handler cluster | true | [UID:00004B] | `87/89` | support/caller page |
| `0x005b2f70-0x005b2fcb` | [UID:0001M4] `by-memory/0x005b2f70-0x005b2fcb.SendEmotionPacket.md` | file-local/static Emotion packet helper | true | [UID:0000ID] | current `87/90` | assigned target |
| `0x00575380-0x00575470` | [UID:0003YJ] `PacketBufferScalarBigEndianWriteHelpers` | scalar packet byte writer family | true | [UID:0000M8] | `87/91` | support dependency |
| `0x00574bb0-0x00574c13` | [UID:0001HU] `QueueAndSendPacket` | Socket-owned queue/send funnel | true | Socket support route | support page | support dependency |
| `0x0067a7ec` | [UID:0000Q5] `g_packetSender` | Socket-owned sender global | true | Socket | `86/88` | support dependency |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x005b2aef` | call to `0x005b2f70` | `a-l` caller branch, passes `ch - 0x56` before helper subtracts `0x0b`. |
| `0x005b2b15` | call to `0x005b2f70` | `m-n` caller branch, passes `ch - 0x64` before helper subtracts `0x0b`. |
| `0x005b2f52` | call to `0x005b2f70` | `o-p` caller branch, passes `ch - 0x58` before helper subtracts `0x0b`. |
| `0x005b2f98` | call to `0x00575380` | Writes transformed selector byte to `packet + 1`. |
| `0x005b2fb6` | call to `0x00574bb0` | Sends exactly two bytes through the Socket queue/send funnel. |
| `0x005b2f9d` | data read `0x0067a7ec` | Loads `g_packetSender`. |

## Documentation Evidence And IDA Status

- Existing docs support the owner/emitter route and all packet behavior. The target page already contains strong evidence, formal C++, rejected owner alternatives, and current `87/90` metadata.
- Existing generated tracker state is stale: `auto-generated/-ag-research-tracker.md` still lists [UID:0001M4] at `76/86` under a not-covered-style row, while target source is `87/90` and generated memory coverage says `coded`.
- Current generated by-memory auto coverage has stale `emits_code:false`/`76%` style content for [UID:0001M4] even though source metadata is nonblank C++. This should be refreshed by validator/executed-report lifecycle, not hand edited by B009.
- Existing [UID:0001M4] formal C++ is mostly correct but should preserve the 128-byte scratch buffer shape.

## Ranked Ownership Analysis

### 1. [UID:0000ID] CommandInputPanes

- Evidence for: owns/routs the EmotionInputPane class family; helper is only called by EmotionInputPane input handler; helper is feature-level command-input packet code; current file docs already include Emotion, Group, Post, and related command input panes.
- Evidence against: a narrower `EmotionInputPane.cpp` original file split remains possible.
- Decision: keep as current owner/emitter because it is the least invented source route under current evidence.

### 2. Static helper under EmotionInputPane

- Evidence for: helper is private to `EmotionInputPane::OnCharInput`.
- Evidence against: helper never reads `ecx` and has no object field access; current by-structure route uses by-file owner [UID:0000ID].
- Decision: plausible source spelling only if a future header proves it, but not required now.

### 3. PacketBuffer / Socket / Chatting / SystemMessagePanes

- Evidence for: helper calls PacketBuffer and Socket support; EmotionInputPane's `?` branch uses SystemMessagePanes.
- Evidence against: these are dependencies or neighboring subsystems, not feature opcode ownership; ChatInputPane opcode is `0x0e`, not `0x1d`.
- Decision: rejected.

## Source Placement

- Recommended placement: `NexusTK/ui/dialogs/CommandInputPanes.cpp`, as a file-local/static helper near `EmotionInputPane::OnCharInput`.
- Why this fits: it is a tiny private packet helper used by a command input pane, not a reusable protocol API.
- Remaining uncertainty: exact original file split and helper declaration spelling. This does not block current first-draft helper C++ because behavior, route, and scope are strong.

## Range / Split / Padding / Reclassification Analysis

- No split is required. [UID:0001M4] already owns exactly the helper function.
- Padding before and after stays ignored/alignment:
  - `0x005b2f68-0x005b2f70`: eight `0xcc` bytes.
  - `0x005b2fcb-0x005b2fd0`: five `0xcc` bytes.
- No merge with [UID:0001M3] is recommended. The helper is adjacent and caller-private, but it is a distinct modeled function with its own code-emitting child page.
- No move into the following ChangeItemSlot neighborhood is supported.

## IDA Rename / Type / Comment Recommendations

- IDA DB edits are not requested in this report-only pass.
- Source-facing names for docs/C++:
  - `SendEmotionPacket` for `0x005b2f70`.
  - `PacketBufferWriteUInt8` for `0x00575380`.
  - `g_packetSender` for `0x0067a7ec`.
  - `QueueAndSendPacket` or `g_packetSender->QueueAndSendPacket` depending on final Socket API style; target currently uses the free helper style and may keep it for consistency with existing support docs.
- Type direction:
  - Helper parameter: `int selector` is acceptable source-facing C++ because callers push widened integer values.
  - Packet local: `unsigned char packet[128]` is the best current source-shape type. `char packet[128]` is also plausible, but existing target/support usage leans `unsigned char` for packet bytes.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. Target is reconstructable, exact, owner/emitter route is strong, and no split is needed.
- Recommended code: replace the current formal target C++ with this exact formal header/block insertion text:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static void SendEmotionPacket(int selector)
{
    unsigned char packet[128];

    packet[0] = 0x1d;
    PacketBufferWriteUInt8(static_cast<unsigned char>(selector - 0x0b), packet + 1);
    packet[2] = 0;
    QueueAndSendPacket(g_packetSender, packet, 2);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Reason it preserves exact original behavior: opcode `0x1d`, selector transform `selector - 0x0b`, local scratch zero, and explicit two-byte send length exactly match decompile/disassembly. The larger local buffer does not add transmitted bytes.
- Reason it better matches plausible original precompiled source: packet-building helpers in this codebase commonly use fixed 128-byte local packet buffers even when only a short packet is sent. The disassembly proves a 0x80-byte local scratch region before the security cookie, and accepted sibling reports document that `packet[3]` is behaviorally enough but less source-faithful when `packet[128]` is proven.
- Inferred names used instead of IDA labels: `SendEmotionPacket`, `PacketBufferWriteUInt8`, `g_packetSender`, `QueueAndSendPacket`, and `selector`.
- Naming/coding style convention: file-local `static` helper with simple C-style packet buffer, matching current target and sibling packet-helper draft style.
- Reason code should not remain as `packet[3]`: it under-represents the stack scratch buffer shape and would be less likely to compile to the observed frame.

## Final Recommendation

- Target [UID:0001M4]: keep owner/emitter/reconstructable route; replace formal C++ as above; add current MCP evidence and buffer-size source-shape rationale; consider score `88/91` after implementation.
- Support [UID:0001M3]: no required metadata change; if touched, preserve the current caller-side split and add no new helper body there.
- Support [UID:00004B] and [UID:0000ID]: no required score change; optional support sync can mention that [UID:0001M4] now uses a 128-byte source-shaped local packet buffer while sending two bytes.
- Generated/tracker files: do not edit manually; supervisor/executed-report validator should refresh the stale tracker/coverage state.

## Recommended Target Doc Changes

- Target path: `by-memory/0x005b2f70-0x005b2fcb.SendEmotionPacket.md`
- Exact report facts to incorporate:
  - Current MCP session `80de0a67` reconfirmed helper boundary, three caller xrefs, callees, disassembly, decompile, and padding.
  - The formal C++ local packet buffer should be `unsigned char packet[128]`, not `packet[3]`, because the stack reserve and accepted sibling packet-helper precedent prove the source-shaped fixed buffer.
  - The transmitted payload remains two bytes; `packet[2]` is local-only scratch/terminator.
  - The generated tracker row is stale and should refresh through validator lifecycle.
- Metadata/score/owner/emitter/reconstructable/C++ changes:
  - `COMPLETION:87 -> 88`
  - `CONFIDENCE:90 -> 91`
  - Keep `CANONICAL_OWNER:0000ID`
  - Keep `RECONSTRUCTABLE:TRUE`
  - Keep `EMITTER_UIDS:0000ID`
  - Replace formal C++ with the exact `packet[128]` block above.
- Historical/stale assumptions to preserve:
  - Ordinary instance-method ownership rejected because no `ecx` read.
  - Chat opcode `0x0e` rejected; this helper sends `0x1d`.
  - `packet[3]` was behavior-equivalent first draft but superseded by target-specific source-shape audit.

## Recommended Support Doc Changes

- `by-memory/0x005b29c0-0x005b2f68.EmotionInputPane.md`: no required change unless supervisor wants support sync. Existing caller-side split is correct.
- `by-class/EmotionInputPane.md`: no required score change. Optional support sync: mention [UID:0001M4] now carries formal helper C++ with a source-shaped `packet[128]` local scratch buffer.
- `by-file/CommandInputPanes.md`: no required score change. Optional support sync: mention the same `packet[128]` shape in the Emotion row/boundary notes if the supervisor wants the file page fully synchronized.
- `by-global/g_packetSender.md`, `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md`, and `by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md`: no required change. They already cover the relevant support names.

## Score And Metadata Recommendation

- Current score/metadata: `COMPLETION:87`, `CONFIDENCE:90`, owner/emitter [UID:0000ID], reconstructable true, formal C++ nonblank.
- Recommended score/metadata after implementation: `COMPLETION:88`, `CONFIDENCE:91`, same owner/emitter/reconstructable fields.
- Reason higher: this pass resolves the remaining formal C++ source-shape issue by replacing `packet[3]` with the proven 128-byte local scratch buffer and records a current MCP-backed recheck.
- Reason not higher: original helper spelling and exact original file split (`CommandInputPanes.cpp` vs a narrower `EmotionInputPane.cpp`) remain inferred; PacketBuffer/Socket function names are accepted descriptive source-facing names, not original symbol proof.
- Reason not lower: function range, callers, callees, opcode, selector transform, sent length, padding, support names, and static/file-local owner route are all independently supported by current MCP and by-* docs.
- Score-improvement attempt:
  - Original helper name: researched through current target/support docs and old B009 report; `SendEmotionPacket` remains best inferred source-facing name.
  - Packet writer/helper names: researched via [UID:0003YJ], [UID:0000Q5], and [UID:0001HU]; raw labels should not remain in source-facing target docs.
  - Caller-side selector split: rechecked with MCP caller decompile/disassembly and kept on [UID:0001M3].
  - Source placement: rechecked against [UID:00004B] and [UID:0000ID], rejected PacketBuffer/Socket/Chatting/SystemMessagePanes/ordinary instance method.
  - Exact padding: rechecked with `get_bytes`; both neighboring spans are `0xcc`.
  - Formal C++: current `packet[3]` found and repair-planned to `packet[128]`.

## Open Questions With Attempted Resolution

- Open question: exact original helper declaration spelling.
  - Evidence checked: current target/support docs, executed B009 class report, MCP call graph, helper ABI, caller set, no `ecx` read.
  - Resolution: use inferred file-local `static void SendEmotionPacket(int selector)`. This is implementation-ready; no `sub_`/raw name should remain in source-facing C++.
- Open question: exact source file split.
  - Evidence checked: by-file `CommandInputPanes`, by-class `EmotionInputPane`, caller locality, rejected owner routes.
  - Resolution: keep [UID:0000ID] now. A future `EmotionInputPane.cpp` split is plausible but unproven and not required for this exact child.
- Open question: free helper call versus `Socket` method call for send.
  - Evidence checked: [UID:0001HU] and [UID:0000Q5] support docs and existing target style.
  - Resolution: keep current `QueueAndSendPacket(g_packetSender, packet, 2)` formal style unless a later Socket header policy standardizes method-call syntax project-wide.
- Open question: `packet[3]` versus `packet[128]`.
  - Evidence checked: MCP disassembly stack layout, decompilation locals, sibling [UID:0001MS] SendWieldPacket report/doc precedent.
  - Resolution: use `packet[128]`; `packet[3]` is superseded as a source-shape issue.

No final report blocker remains for this target.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

No manual `-coverage-report.md` text is recommended. B009 must not edit coverage reports or generated tracker files.

Supervisor-owned/generated expectations:

- Execute/validate this report through the normal validator lifecycle after implementation so `auto-generated/-ag-research-tracker.md` and generated coverage refresh from source metadata.
- If manual by-memory coverage is still maintained separately, supervisor should derive any row from source metadata after target validation; B009 provides no manual row replacement.

## Follow-Up Actions

- Supervisor: validate this report; if accepted, send B009 an implementation callback for the target doc and optional support sync.
- B009 implementation callback: update only the accepted by-* docs, not generated or coverage files; run scoped validators from `source-3/project-documentation`.
- Future B-agent work outside this target: [UID:0001M3] can receive a separate method-split/`OnCharInput` C++ pass if the project wants full method-body emission for the caller cluster.

## Confidence

- Recommendation confidence: high/very strong for target doc and formal helper C++ repair.
- Score confidence: `88/91` after implementation is justified; above that should wait for exact original helper/file spelling or project-wide PacketBuffer/Socket header finalization.
- Remaining uncertainty: original symbol spelling and exact source file split only.

## Validator Results

Implementation callback validators were run from `E:\NTK\GhidraBridge\source-3\project-documentation` while the by-* leases were active:

| File | Command | command_id | command_timestamp | Exit | ok | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| `by-memory/0x005b2f70-0x005b2fcb.SendEmotionPacket.md` | `python .\tools\validator.py --mode file --file by-memory\0x005b2f70-0x005b2fcb.SendEmotionPacket.md --apply --queue-timeout 240` | `000000002322` | `2026-06-26T04:19:56-04:00` | `0` | `1` | Applied `completion_update 88`, `confidence_update 91`, owner/emitter registry updates, C++ block registry update, projected stats update; generated refresh deferred. Existing warning: missing ref UID `0003YJ`. |
| `by-class/EmotionInputPane.md` | `python .\tools\validator.py --mode file --file by-class\EmotionInputPane.md --apply --queue-timeout 240` | `000000002325` | `2026-06-26T04:20:10-04:00` | `0` | `1` | Scores unchanged at `87/89`; validator inserted the missing [UID:0001M4] link target on the new support note, updated reference index/projected stats; generated refresh deferred. Existing warnings include missing ref UIDs `0003HI` and `0003ED`. |
| `by-file/CommandInputPanes.md` | `python .\tools\validator.py --mode file --file by-file\CommandInputPanes.md --apply --queue-timeout 240` | `000000002327` | `2026-06-26T04:20:19-04:00` | `0` | `1` | Scores unchanged at `86/86`; projected stats update; generated refresh deferred. Existing warnings include stale/missing references for older Post/SelfSave paths and missing ref UIDs already present on the page. |

Generated/project-level side effects were validator-owned only: the scoped runs updated validator registry/reference metadata and projected stats, and each reported `generated_refresh: deferred` with the matching command id/timestamp. B009 did not manually edit generated files, project-level generated files, manual `-coverage-report.md` files, validator/tool state, or the IDA DB.

## Changed Files

- Updated target `by-memory/0x005b2f70-0x005b2fcb.SendEmotionPacket.md`.
- Updated support `by-class/EmotionInputPane.md`.
- Updated support `by-file/CommandInputPanes.md`.
- Updated this report checklist/proof: `tools/leaser/Agents/Agent-B009/research/0001M4-SendEmotionPacket-source-quality.md`.
- No generated files, manual coverage reports, validator/tool source, or IDA DB files were manually edited.

## Implementation Tracking Checklist

Report-only pass:

- [x] Read B009 `goal.md`.
- [x] Used project-level `ntk-b-agent-workflow` skill.
- [x] Checked target [UID:0001M4] and required support docs.
- [x] Checked central executed B009 EmotionInputPane class report as lead material.
- [x] Used live IDA MCP session `80de0a67`; MCP was responsive after resume.
- [x] Verified key numeric constants with `tools/int_convert.py`.
- [x] Did not edit by-* docs, generated files, coverage reports, validator/tool state, or IDA DB during the report-only pass.

Implementation callback pass:

- [x] Target `by-memory/0x005b2f70-0x005b2fcb.SendEmotionPacket.md`: changed `COMPLETION:87 -> 88` and `CONFIDENCE:90 -> 91`; preserved `CANONICAL_OWNER:0000ID`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000ID`.
- [x] Target `by-memory/0x005b2f70-0x005b2fcb.SendEmotionPacket.md`: replaced the formal `RECONSTRUCTION_CPP CODE` block with the accepted `unsigned char packet[128]` implementation, preserving opcode `0x1d`, `PacketBufferWriteUInt8(static_cast<unsigned char>(selector - 0x0b), packet + 1)`, local `packet[2] = 0`, and `QueueAndSendPacket(g_packetSender, packet, 2)`.
- [x] Target `by-memory/0x005b2f70-0x005b2fcb.SendEmotionPacket.md`: added MCP session `80de0a67` evidence for server health, exact `0x005b2f70-0x005b2fcb` boundary, non-function endpoints, three caller xrefs, caller selector transforms, callees, decompile facts, disassembly stack-frame layout, padding bytes, and negative VA/RVA/raw-offset pointer-pattern checks.
- [x] Target `by-memory/0x005b2f70-0x005b2fcb.SendEmotionPacket.md`: documented that `packet[3]` was behavior-equivalent for the sent bytes but superseded by the 128-byte source-shape repair.
- [x] Target `by-memory/0x005b2f70-0x005b2fcb.SendEmotionPacket.md`: preserved rejected alternatives for ordinary instance-method ownership, PacketBuffer/Socket/Chatting/SystemMessagePanes ownership, chat opcode `0x0e`, and retaining `packet[3]` as final C++.
- [x] Target `by-memory/0x005b2f70-0x005b2fcb.SendEmotionPacket.md`: did not move owner/emitter and did not split or merge the target.
- [x] Support sync `by-class/EmotionInputPane.md`: added the accepted support fact that [UID:0001M4] now carries formal helper C++ with source-shaped `packet[128]` local scratch storage while sending only two bytes; scores unchanged at `87/89`.
- [x] Support sync `by-file/CommandInputPanes.md`: added the accepted support fact in the Emotion row/boundary notes that [UID:0001M4] now models `packet[128]` local scratch storage while sending length `2`; scores unchanged at `86/86`.
- [x] No support edit was made for `by-memory/0x005b29c0-0x005b2f68.EmotionInputPane.md`, `g_packetSender`, `QueueAndSendPacket`, or packet scalar write helpers because no stale text directly contradicted the accepted report.
- [x] Did not manually edit any `-coverage-report.md`, `auto-generated/-ag-*` tracker/coverage file, generated C++ file, project-level generated file, validator/tool source/state, or IDA DB.
- [x] Ran scoped validator for every changed by-* file and recorded command, command id/timestamp, exit code, `ok`, and generated-refresh state above.
- [x] Generated tracker/coverage refresh expectation: source metadata and validator registry are updated; generated refresh was reported as deferred for the three scoped commands, so the supervisor should rely on validator-owned refresh/executed-report lifecycle rather than manual generated edits.
- [x] Leases used and released: B009 leased `by-memory/0x005b2f70-0x005b2fcb.SendEmotionPacket.md`, `by-class/EmotionInputPane.md`, and `by-file/CommandInputPanes.md` at `2026-06-26T08:18:03Z`, validated while the leases were active, and released all three immediately after the edit/validator batch.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000004165","destination_path":"executed-b-agent-research/B009/0001M4-SendEmotionPacket-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/0001M4-SendEmotionPacket-source-quality.md","timestamp":"2026-06-26T06:06:46","uid":"0001M4"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
