** TARGET-REPORT-UID:000239 **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 000239 TextInputMenuDialog Reply Packet Helper Source-Quality Report

Status: FINISHED_IMPLEMENTATION

Agent: B010
Assignment id: B010-report-000239-text-input-menu-dialog-reply-packet-helper-20260625
Target: [UID:000239] `by-memory/0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper.md`
Required report path: `tools/leaser/Agents/Agent-B010/research/000239-TextInputMenuDialogReplyPacketHelper-source-quality.md`

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:000239] as reconstructable, directly owned and emitted by [UID:0000ER] `TextInputMenuDialog`, but correct the caller-text parameter and final C++ from ANSI to wide input converted through `PacketBufferAppendWideStringAsAnsi8`.
- Final disposition: implementation-ready source-quality correction; no split, owner change, or no-owner fallback.
- Required action: update the target page, [UID:0000ER] class page, [UID:0001BN] aggregate page, and [UID:0000OP] source-file page to supersede the stale `const char *inputTextAnsi` claim for this helper's caller-supplied text.
- Confidence: strong for range, owner, packet field order, optional stored ANSI string, caller wide-string conversion, and C++ correction; capped below final audit by the unchanged no-direct-xref/no-IDA-function state.

## Target

- Target UID: 000239.
- Target path: `by-memory/0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper.md`.
- Source queue/report row: assigned from `auto-generated/-ag-research-tracker.md`, stale row `76/82`, reconstructable true, owner `0000ER`.
- Current supervisor classification: report-only source-quality recheck; no by-* edits, no leases.
- Current source page state: `COMPLETION:88`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000ER`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000ER`, formal C++ present.

## Current Target State

The current target page already documents the exact `0x0051a420-0x0051a51c` raw helper, owner [UID:0000ER], emitter [UID:0000ER], `0x39` opcode, fields at `this+0x270/+0x278/+0x27a/+0x27c/+0x280`, `g_packetSender`, boundary padding, no xrefs to the raw start, and first-draft C++.

The material stale claim is the caller text type:

- Current target C++ declares `void TextInputMenuDialog::SendInputReply(const char *inputTextAnsi)`.
- Current target prose says the caller-supplied argument is appended through `0x005757d0` / `PacketBufferAppendAnsiString8`.
- Fresh MCP disassembly shows the caller argument at `[ebp+8]` is pushed at `0x0051a4e9` and the call at `0x0051a4ea` targets `0x00575850`, which [UID:0003YO] identifies as `PacketBufferAppendWideStringAsAnsi8`.
- MCP decompilation of `0x00575850` confirms the first parameter is `LPCWCH lpWideCharStr`; it converts wide text through `sub_582770`, extracts ANSI bytes through `sub_584540`, writes a one-byte length, copies bytes with `memmove`, advances the cursor, and releases the temporary string.

This is not a naming-only issue. The current formal C++ in the target and generated `auto-generated/NexusTK/ui/dialogs/TextMenuDialogs.cpp` would emit the wrong helper call for the caller text.

## Supervisor Active Recheck

- Direct instruction used: report-only assignment for [UID:000239], use IDA MCP `http://127.0.0.1:13337/mcp`, stop if unavailable, no subagents, no leases, no by-* edits, no generated/project-level/validator/IDA DB edits.
- MCP availability: active and responsive. `idb_list` returned session `80de0a67` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; `server_health` returned status `ok`, module `NexusTK.exe`, imagebase `0x400000`, Hex-Rays ready, auto-analysis ready.
- Split repair: not required. The exact raw helper is bounded by `0xcc` padding before and after, and the neighboring modeled functions are outside the range.
- Source-bearing child repair: this exact child exists and is the right source-bearing page. The correction is source-quality/protocol/C++ text, not a new child-page split.

## Inference Research Guidance Check

IDA MCP and current by-* docs were treated as authoritative. The prior B010 executed class report was used as lead material but rechecked against current MCP because its `const char *` conclusion was based on the stale statement that the raw helper appends its caller argument through `0x005757d0`. Current disassembly contradicts that claim.

Stale Wave2/Wave3 or generated source was not used as proof. Generated `auto-generated/NexusTK/ui/dialogs/TextMenuDialogs.cpp` was checked only as an output-state symptom: it still contains the wrong `const char *` helper body and stale `76/82` annotation for [UID:000239].

Direct IDA facts, documentation evidence, and inference are separated below.

## Evidence Checked

MCP endpoint and session:

- `initialize` and `tools/list` returned successfully from `http://127.0.0.1:13337/mcp`.
- `idb_list`: session `80de0a67`, `NexusTK.exe.i64`, active worker PID `26892`.
- `server_health`: status `ok`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`.

MCP function/range checks:

- `entity_query functions min_addr=0x0051a3d0 max_addr=0x0051a530`: only `sub_51A3E0` at `0x0051a3e0`, size `0x37`, and `sub_51A520` at `0x0051a520`, size `0x76e`; no function object at `0x0051a420`.
- `lookup_funcs`: `0x0051a420` is not a function; `0x0051a417` and `0x0051a51c` are not functions; `0x0051a520` is `sub_51A520`.
- `decompile 0x0051a420`: failed because IDA has no function object at the raw start.
- `disasm 0x0051a420`: rendered the complete raw body from `push ebp` through `retn 4`, then `align 10h` at `0x0051a51c` and next function `sub_51A520` at `0x0051a520`.
- `xrefs_to 0x0051a420`: zero xrefs.
- `get_bytes`: `0x0051a417-0x0051a420` is nine `0xcc` bytes; `0x0051a51c-0x0051a520` is four `0xcc` bytes.

MCP packet/helper checks:

- `decompile 0x005757d0`: `sub_5757D0(const char *Src, int base, int *cursor)` uses `strlen`, writes one length byte, copies ANSI bytes with `memmove`, and advances the cursor. This supports `PacketBufferAppendAnsiString8`.
- `decompile 0x00575850`: `sub_575850(LPCWCH lpWideCharStr, int base, int *cursor)` converts wide text through `sub_582770`, gets ANSI bytes via `sub_584540`, writes one length byte, copies bytes, advances the cursor, and releases the temporary through `sub_582B30`. This supports `PacketBufferAppendWideStringAsAnsi8`.
- `xrefs_to 0x00575850`: six code xrefs, including `0x0051a39d` inside modeled `sub_51A280` and `0x0051a4ea` inside this raw helper.
- `analyze_function 0x0051a280`: submit path reads child control id `6` into `WCHAR v7[256]`, then calls `sub_575850(v7, packet, &cursor)` at `0x0051a39d`.

Documentation/support checked:

- Target [UID:000239] by-memory page.
- [UID:0000ER] `by-class/TextInputMenuDialog.md`.
- [UID:0000OP] `by-file/TextMenuDialogs.md`.
- [UID:0001BN] `by-memory/0x00517ec0-0x0051a417.TextMenuDialogs.md`.
- [UID:0003YM] `by-memory/0x00575650-0x00575703.PacketBufferCursorAppendBigEndianHelpers.md`.
- [UID:0003YO] `by-memory/0x005757d0-0x00575a07.PacketBufferStringWriteHelpers.md`.
- [UID:0000Q5] `by-global/g_packetSender.md` was treated through existing UID links and disassembly xref to `dword_67A7EC`.
- Executed report lead: `executed-b-agent-research/B010/0000ER-TextInputMenuDialog-class-source-quality.md`.
- Generated read-only context: `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, `auto-generated/-ag-memory-coverage.md`, and `auto-generated/NexusTK/ui/dialogs/TextMenuDialogs.cpp`.

Numeric conversion checks:

- `int_convert` verified `0x39` = 57, `0xfc` = 252 with `size=2`, `0x208` = 520, `0x270` = 624, `0x278` = 632, `0x27a` = 634, `0x27c` = 636, `0x280` = 640, `0xff` = 255 with `size=2`, and `0x100` = 256.

## IDA MCP Facts

| Address | Current MCP fact | Source meaning |
| --- | --- | --- |
| `0x0051a420` | Raw prolog, no function object | Retained source-shaped helper body, not IDA-modeled method. |
| `0x0051a423` | `sub esp, 208h` | Local packet buffer frame; `0x208` is 520 (Verified with int_convert.py). |
| `0x0051a435` | `mov edi, [ebp+8]` | Captures the helper argument. |
| `0x0051a438` | `mov esi, ecx` | `ecx` is the `TextInputMenuDialog *this` receiver. |
| `0x0051a457` | `push 39h`; `0x0051a459` calls `0x00575650` | Writes opcode `0x39`. |
| `0x0051a46c` | `movzx eax, byte ptr [esi+278h]` | Writes `m_replyType`. |
| `0x0051a487` | `push dword ptr [esi+270h]`; call `0x005756d0` | Writes `m_dialogId` as uint32 big-endian. |
| `0x0051a4a0` | `movzx eax, word ptr [esi+27Ah]`; call `0x00575670` | Writes `m_selectedOptionId` as uint16 big-endian. |
| `0x0051a4b0` | `cmp byte ptr [esi+27Ch], 0` | Tests `m_hasExtraString`. |
| `0x0051a4c7` | `lea ecx, [esi+280h]`; call `0x00584540`; call `0x005757d0` | Gets stored extra string bytes and appends as ANSI one-byte length-prefixed text. |
| `0x0051a4e9` | `push edi`; `0x0051a4ea` calls `0x00575850` | Appends caller-supplied wide text through wide-to-ANSI one-byte length-prefixed writer. |
| `0x0051a4ef` | `mov ecx, dword_67A7EC` | Loads [UID:0000Q5] `g_packetSender`. |
| `0x0051a505` | call `0x00574bb0` | Queues/sends built packet. |
| `0x0051a511` | call `@__security_check_cookie@4` | Compiler security-cookie epilog. |
| `0x0051a519` | `retn 4` | One stack argument, consistent with one source parameter after `this`. |

## Inference Claim Ledger

| Claim | Confidence | Evidence | Counter-evidence checked | Next verification / remaining uncertainty |
| --- | --- | --- | --- | --- |
| [UID:000239] belongs directly to `TextInputMenuDialog`. | Strong | Raw body reads `this+0x270/+0x278/+0x27a/+0x27c/+0x280`, serializes opcode `0x39`, sits immediately after `TextInputMenuDialog` methods, class and file pages already document the route. | PacketBuffer, socket, TextEditControlPane, source-file-only, and no-owner alternatives checked; these are callees or broad containers. | No direct xref to raw start remains a score cap, not an ownership blocker. |
| Caller parameter is wide text, not ANSI. | Strong | `0x0051a4e9` pushes `[ebp+8]` copy in `edi`; `0x0051a4ea` calls `0x00575850`; MCP decompilation of `0x00575850` takes `LPCWCH` and converts wide text to ANSI before appending. | Prior B010 report and current target page claimed `0x005757d0`; fresh disassembly rejects that for the caller argument. | Exact original parameter name is not symbol-proven; `inputTextWide` is descriptive and source-facing. |
| Optional stored extra string remains ANSI append. | Strong | `0x0051a4c7` loads `this+0x280`, calls `0x00584540`, then `0x0051a4d3` calls `0x005757d0`; `0x005757d0` decomp takes `const char *`. | Treating both strings as wide rejected because only the caller argument uses `0x00575850`. | Exact StringBase/SimpleUString concrete type remains class-header work, not target blocker. |
| Formal C++ should remain present after correction. | Strong | Target is reconstructable, owner/emitter route is nonblank and surfaces through [UID:0000OP], current average score is above 85, and the exact body is fully disassembled. | Leaving code blank rejected because the code-entry gate is met; keeping current ANSI body rejected by fresh MCP. | Keep below final-audit scores because no direct xref/function object exists. |
| No split is needed. | Strong | `0x0051a417-0x0051a420` and `0x0051a51c-0x0051a520` are `0xcc`; function inventory has only neighboring `0x0051a3e0` and `0x0051a520` modeled functions. | Overbroad/mixed-range alternative rejected; target range is exact helper body plus no unrelated data. | None for split. |

## Heuristic / Inference Reanalysis And Validation

### Generated/source-facing names

`SendInputReply` remains the best source-facing method name. The function emits a dialog reply packet, not a generic packet-buffer operation. The parameter should be renamed from `inputTextAnsi` to `inputTextWide` or `inputText`. `inputTextWide` is more explicit because the binary passes it to the wide-to-ANSI helper. Raw names `sub_51A420`, `sub_575850`, `dword_67A7EC`, and decompiler temporaries should stay in evidence/history only.

### Protocol fields

The packet order remains stable:

1. opcode byte `0x39`;
2. `m_replyType` at `this+0x278`;
3. `m_dialogId` at `this+0x270`;
4. `m_selectedOptionId` at `this+0x27a`;
5. optional stored extra string from `this+0x280`, guarded by `this+0x27c`, appended through `PacketBufferAppendAnsiString8`;
6. caller-supplied wide text appended through `PacketBufferAppendWideStringAsAnsi8`;
7. send through `g_packetSender` / `QueueAndSendPacket`.

### Caller/reachability

The raw helper still has no direct xref to `0x0051a420`. Current MCP confirms the modeled submit handler `0x0051a280` inlines the same packet shape and calls `0x00575850` at `0x0051a39d`. This supports a likely source-family relationship, but not a direct call from `OnButtonPress` to [UID:000239]. The docs should continue to say "retained raw helper" and should not rewrite `OnButtonPress` as a direct caller unless future route evidence proves it.

### Source placement

Keep source placement in `ui/dialogs/TextMenuDialogs.cpp` through [UID:0000OP]. The helper is method-shaped and class-owned by [UID:0000ER], while [UID:0000OP] is the output source root. PacketBuffer owns `0x005757d0` and `0x00575850`; it does not own this dialog-specific opcode payload.

### Generated-output drift

Generated C++ is currently stale and incorrect for this target:

- `auto-generated/NexusTK/ui/dialogs/TextMenuDialogs.cpp` header says [UID:000239] `Completion:76 | Confidence:82` even though the source page is `88/88`.
- It declares `void SendInputReply(const char *inputTextAnsi)` in the class and method body.
- It emits `PacketBufferAppendAnsiString8(packet, &cursor, inputTextAnsi)`.

Do not edit generated files. The implementation callback should update source docs, then run scoped validators with `--wait-generated` so the generated output and `-ag-*` reports refresh from source metadata.

## Ranked Ownership Analysis

### 1. [UID:0000ER] TextInputMenuDialog - accepted direct owner

- Evidence for: `this` field reads are all documented `TextInputMenuDialog` fields; opcode `0x39` belongs to the text/menu dialog reply family; helper sits directly after text-input methods; class page now documents the method and child relation; direct class parent clears the active gate.
- Evidence against: no direct xref and no IDA function object at `0x0051a420`.
- Decision: keep as direct canonical owner and emitter. The negative reachability evidence caps confidence but does not defeat ownership.

### 2. [UID:0000OP] TextMenuDialogs - accepted source-file route only

- Evidence for: source root already owns the text-menu dialog class family and generated path `NexusTK/ui/dialogs/`.
- Evidence against: by-structure requires the narrow direct semantic owner for class methods; assigning directly to the file would bypass [UID:0000ER].
- Decision: keep as source-file route through [UID:0000ER], not direct canonical owner of [UID:000239].

### 3. [UID:0000M8] PacketBuffer - rejected owner

- Evidence for: target calls PacketBuffer append helpers.
- Evidence against: PacketBuffer only owns `0x00575650`, `0x00575670`, `0x005756d0`, `0x005757d0`, and `0x00575850`; the target chooses dialog opcode and dialog fields.
- Decision: support/callee only.

### 4. TextEditControlPane - rejected owner

- Evidence for: `OnButtonPress` obtains typed wide text from child edit control id `6`.
- Evidence against: [UID:000239] itself does not read the edit control; it accepts one argument and serializes dialog fields. TextEditControlPane is an input provider, not owner.
- Decision: support/callee context only.

### 5. No-owner/non-emitting - rejected

- Evidence for: no direct xrefs to raw start.
- Evidence against: exact source-shaped body, class field reads, owner page, source root, and formal C++ gate all support reconstruction.
- Decision: not appropriate.

## Range / Split / Padding / Reclassification Analysis

- Exact range: `0x0051a420-0x0051a51c` half-open.
- Size: `0xfc` / 252 bytes (Verified with int_convert.py).
- Leading boundary: `0x0051a417-0x0051a420` is nine `0xcc` bytes.
- Trailing boundary: `0x0051a51c-0x0051a520` is four `0xcc` bytes.
- Function inventory in `0x0051a3d0-0x0051a530`: only `sub_51A3E0` and `sub_51A520`.
- Reclassification: keep reconstructable project code, raw helper / method body.
- Split: no child split or merge is needed.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. `RECONSTRUCTABLE:TRUE`, owner/emitter route is nonblank, and current/recommended scores clear the active combined-score gate.
- Recommended code: replace the formal target block with the exact corrected block below. This is implementation text for the by-memory page, not a report-only sample.

```cpp
void TextInputMenuDialog::SendInputReply(const wchar_t *inputTextWide)
{
    unsigned char packet[0x208];
    int cursor = 0;

    PacketBufferAppendUInt8(packet, &cursor, 0x39);
    PacketBufferAppendUInt8(packet, &cursor, m_replyType);
    PacketBufferAppendUInt32BE(packet, &cursor, m_dialogId);
    PacketBufferAppendUInt16BE(packet, &cursor, m_selectedOptionId);

    if (m_hasExtraString) {
        PacketBufferAppendAnsiString8(packet, &cursor, m_extraString.c_str());
    }

    PacketBufferAppendWideStringAsAnsi8(packet, &cursor, inputTextWide);
    QueueAndSendPacket(g_packetSender, packet, static_cast<short>(cursor));
}
```

Reason it preserves exact behavior: it keeps the same local packet buffer, cursor, opcode, field order, optional stored ANSI string append, and final send. The only change from current docs is the corrected caller-text helper and source parameter type matching `0x0051a4ea -> 0x00575850`.

Reason it matches plausible original source: a dialog method that accepts wide edit text and converts it through a packet-buffer string writer is consistent with the modeled submit path, where `OnButtonPress` reads `WCHAR[256]` from child edit control id `6` and calls the same wide-to-ANSI helper at `0x0051a39d`.

Naming/style: keep existing project/local method style `TextInputMenuDialog::SendInputReply`, member names `m_dialogId`, `m_replyType`, `m_selectedOptionId`, `m_hasExtraString`, `m_extraString`, and PacketBuffer helper facade names. Use `inputTextWide` instead of IDA/decompiler labels.

## Score And Metadata Recommendation

- Current target metadata: `COMPLETION:88`, `CONFIDENCE:88`, owner/emitter `0000ER`, reconstructable true, formal C++ present.
- Recommended target metadata after implementation: `COMPLETION:90`, `CONFIDENCE:89`, owner/emitter `0000ER`, reconstructable true, formal C++ corrected.
- Score rationale: completion can rise because this pass resolves a material wrong C++/protocol-type claim, adds fresh MCP schema/session provenance, exact disassembly anchors, and generated-output drift handling. Confidence should rise only slightly because the no-direct-xref/no-IDA-function state remains real negative evidence.
- Reason not higher: IDA still does not model the raw helper as a function, decompilation of `0x0051a420` fails, `xrefs_to 0x0051a420` remains empty, exact original method/parameter spelling is not symbol-proven, and the final PacketBuffer helper declaration order/type policy is still broader support work.

Score-limiting blockers researched:

- Raw/no-function start: checked `entity_query`, `lookup_funcs`, `disasm`, `decompile`, and neighboring bytes. Result: exact raw method body, but no function object. No split needed.
- Missing xref route: checked `xrefs_to 0x0051a420` and `xrefs_to 0x00575850`; raw start has no refs, but `0x0051a4ea` is a code xref to the wide-string helper and `0x0051a39d` in `OnButtonPress` is the modeled inline sibling path. Result: reachability cap remains, but source relation is stronger.
- Packet writer type: resolved. Caller text uses `0x00575850`, not `0x005757d0`.
- Generated C++ mismatch: confirmed. Requires source-doc edit plus validator refresh, not generated manual edit.

## Recommended Target Doc Changes

Target path: `by-memory/0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper.md`.

Apply these changes at report-level detail:

- Change metadata to `COMPLETION:90`, `CONFIDENCE:89`; keep `CANONICAL_OWNER:0000ER`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000ER`.
- Replace formal C++ with the corrected `const wchar_t *inputTextWide` block in this report.
- In `Item Summary`, say the caller wide text is converted/appended through `PacketBufferAppendWideStringAsAnsi8`; keep optional `this+0x280` stored text as ANSI.
- In Status/Role/Source Draft sections, replace `SendInputReply(const char *inputTextAnsi)` with `SendInputReply(const wchar_t *inputTextWide)`.
- In packet serialization semantics, update order item 6 to: caller-supplied wide input text; evidence `0x0051a4e9 push edi`, `0x0051a4ea call 0x00575850`, [UID:0003YO] `PacketBufferAppendWideStringAsAnsi8`.
- Preserve the distinction from `OnButtonPress`: the modeled submit path also uses `0x00575850`, but the raw helper still has no direct caller proof.
- Update IDA evidence: call scan should list `0x0051a4ea -> 0x00575850`, not `0x005757d0`; keep optional stored string `0x0051a4d3 -> 0x005757d0`.
- Add a historical/superseded note that the earlier B010 class report and target page treated the raw helper argument as ANSI based on an incorrect `0x005757d0` call attribution; current MCP disassembly supersedes it.
- Keep the no-direct-xref/no-function caveat and do not request IDA DB edits during implementation.

## Recommended Support Doc Changes

### `by-class/TextInputMenuDialog.md`

- Update the class C++ declaration from `void SendInputReply(const char *inputTextAnsi);` to `void SendInputReply(const wchar_t *inputTextWide);`.
- Update method map/prose so [UID:000239] is the retained raw `SendInputReply(const wchar_t *)` serializer.
- Replace text saying the raw helper appends its argument through `PacketBufferAppendAnsiString8`; it appends caller text through `PacketBufferAppendWideStringAsAnsi8`.
- Keep the existing statement that `OnButtonPress` should not be claimed as a direct caller without future route proof.
- Preserve the optional `m_extraString` ANSI append and the `OnButtonPress` inline wide-to-ANSI submit path.
- Metadata recommendation: keep `88/88`; this is a support-doc correction, not a full class rescore.

### `by-memory/0x00517ec0-0x0051a417.TextMenuDialogs.md`

- In the adjacent continuation row and `TextInputMenuDialog B010 Source-Quality Notes`, update [UID:000239] from `SendInputReply(const char *)` to `SendInputReply(const wchar_t *)`.
- Say [UID:000239] appends optional stored text through `0x005757d0` / `PacketBufferAppendAnsiString8`, then appends caller wide text through `0x00575850` / `PacketBufferAppendWideStringAsAnsi8`.
- Keep aggregate metadata `86/88`; no range/split change.

### `by-file/TextMenuDialogs.md`

- In Proposed Contents and source-placement notes, update [UID:000239] to retained raw `SendInputReply(const wchar_t *)`.
- Replace "caller ANSI string" wording with "caller wide input converted through PacketBufferAppendWideStringAsAnsi8".
- Keep rejected owner routes: not PacketBuffer, TextEditControlPane, sockets, or generic network code.
- Keep metadata `90/86`; no source-file reroute.

### Generated files and reports

- Do not edit generated files by hand.
- After source-doc implementation, validator refresh should update `auto-generated/NexusTK/ui/dialogs/TextMenuDialogs.cpp`, `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and `auto-generated/-ag-research-tracker.md` from source metadata.
- Current generated C++ read-only evidence: `auto-generated/NexusTK/ui/dialogs/TextMenuDialogs.cpp` still has [UID:000239] as `Completion:76 | Confidence:82`, declares `const char *inputTextAnsi`, and calls `PacketBufferAppendAnsiString8` for the caller argument.

## IDA Rename / Type / Comment Recommendations

No IDA DB edits are requested or allowed during this report-only assignment.

If a future supervisor-approved IDA cleanup pass allows raw function creation or comments:

| Address | Recommendation | Confidence |
| --- | --- | --- |
| `0x0051a420` | Create/name raw function as `TextInputMenuDialog::SendInputReply` only if project IDA policy allows raw function creation. | High for body/role, medium for IDA DB promotion. |
| `0x0051a420` type | `void __thiscall(TextInputMenuDialog *this, const wchar_t *inputTextWide)` | Strong for wide parameter from `0x0051a4ea -> 0x00575850`. |
| `0x0051a4d3` comment | Optional stored text append uses `PacketBufferAppendAnsiString8`. | Strong. |
| `0x0051a4ea` comment | Caller wide text append uses `PacketBufferAppendWideStringAsAnsi8`. | Strong. |

## Open Questions With Attempted Resolution

- No-direct-xref/no-function raw helper: still unresolved after current MCP checks. This is an evidence-backed confidence cap. It does not block owner, emitter, or corrected C++ because the exact body is fully disassembled and source-shaped.
- Exact original parameter spelling: not recoverable from current evidence. `inputTextWide` is the best source-facing descriptive name because the callee accepts `LPCWCH`.
- Exact final PacketBuffer helper declaration order: broader PacketBuffer API policy remains outside this target. The target should follow the existing generated/source-facing facade style used by current C++ blocks while correcting the helper name and argument type.
- Whether original source had a direct helper call from `OnButtonPress`: current modeled `OnButtonPress` inlines the same packet shape and calls `0x00575850`; no evidence proves a direct call to raw `0x0051a420`. Do not claim direct caller.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

No explicit manual `-coverage-report.md` permission was granted, and generated `auto-generated/-ag-*` reports must not be edited manually. No manual coverage row text is supplied.

Expected generated-report path: update source docs and run scoped validators with generated refresh. If the supervisor later chooses to update legacy manual `by-memory/-coverage-report.md`, use the corrected facts above, but that is supervisor-owned and outside this report-only B-agent edit scope.

## Validator Results

No validators were run during this report-only pass because no by-* docs were edited and the direct assignment forbids validator state/cache edits. MCP-backed evidence was collected successfully.

Expected implementation validators from `source-3/project-documentation` after accepted by-* edits:

> Executable block R001 was removed from this report and preserved verbatim in [000239-TextInputMenuDialogReplyPacketHelper-source-quality-removed.md](000239-TextInputMenuDialogReplyPacketHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

The implementation result should report each command's `command_id`, `command_timestamp`, exit code, `ok` count, `generated_refresh` state, and whether `auto-generated/NexusTK/ui/dialogs/TextMenuDialogs.cpp` no longer contains the stale `const char *inputTextAnsi` body for [UID:000239].

## Changed Files

- Created: `tools/leaser/Agents/Agent-B010/research/000239-TextInputMenuDialogReplyPacketHelper-source-quality.md`.
- Modified: none outside this report.
- Renamed: none.
- Leases used: none.
- Report execution: blank for supervisor. The supervisor runs `tools/validator.py execute_report ... --apply` only after accepted implementation is verified.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Proof: supervisor accepted this report for implementation in callback `B010-implement-000239-text-input-menu-dialog-reply-packet-helper-20260625`.
- [x] Target doc `by-memory/0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper.md`: change `COMPLETION:88` to `90`, `CONFIDENCE:88` to `89`; keep owner/emitter/reconstructable fields unchanged. Proof: target header after supervisor fix shows `COMPLETION:90`, `CONFIDENCE:89`, `CANONICAL_OWNER:0000ER`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000ER`; target validator `000000001012`, timestamp `2026-06-25T03:37:54-04:00`, exit 0, `ok:1`, generated refresh skipped by supervisor design.
- [x] Target doc: replace formal C++ with `SendInputReply(const wchar_t *inputTextWide)` and `PacketBufferAppendWideStringAsAnsi8(packet, &cursor, inputTextWide)`. Proof: target formal block and generated `auto-generated/NexusTK/ui/dialogs/TextMenuDialogs.cpp` both contain the corrected signature/helper; generated C++ header from command `000000001004` is current for the corrected code.
- [x] Target doc: update Role, Packet Serialization Semantics, Source Draft, IDA Evidence, Score Rationale, and Changes to preserve the fresh MCP facts: caller argument call site `0x0051a4ea -> 0x00575850`, optional string `0x0051a4d3 -> 0x005757d0`, no xrefs to `0x0051a420`, exact padding boundaries. Proof: target body now records the two string paths, `0x0051a4e9`/`0x0051a4ea -> 0x00575850`, optional `0x0051a4d3 -> 0x005757d0`, no raw-start xrefs, and padding boundaries.
- [x] Target doc: add historical/superseded note for the stale prior `const char *` / caller `PacketBufferAppendAnsiString8` claim. Proof: target Changes section marks the 2026-06-21 `const char *` caller-argument wording as superseded by the 2026-06-25 MCP pass.
- [x] Support doc `by-class/TextInputMenuDialog.md`: change the class declaration and prose from `SendInputReply(const char *)` to `SendInputReply(const wchar_t *)`; preserve the no-direct-caller caveat. Proof: class declaration is `void SendInputReply(const wchar_t *inputTextWide);`, prose distinguishes optional ANSI append from caller wide-to-ANSI append, and the no-direct-`OnButtonPress` caveat remains.
- [x] Support doc `by-memory/0x00517ec0-0x0051a417.TextMenuDialogs.md`: update adjacent helper and B010 source-quality notes to distinguish optional stored ANSI append from caller wide-to-ANSI append. Proof: adjacent continuation row and TextInputMenuDialog notes now state optional stored text uses `0x005757d0` / `PacketBufferAppendAnsiString8` and caller wide input uses `0x00575850` / `PacketBufferAppendWideStringAsAnsi8`.
- [x] Support doc `by-file/TextMenuDialogs.md`: update Proposed Contents/source-placement notes to `SendInputReply(const wchar_t *)` and corrected caller-text helper; keep owner route unchanged. Proof: Proposed Contents row and source-placement paragraph now use retained raw `SendInputReply(const wchar_t *)`, preserve the `TextInputMenuDialog`/`TextMenuDialogs.cpp` source route, and reject PacketBuffer/TextEditControlPane/socket/network ownership.
- [x] Metadata fields to leave unchanged: [UID:000239] `CANONICAL_OWNER:0000ER`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000ER`; [UID:0000ER] `88/88`; [UID:0001BN] `86/88`; [UID:0000OP] `90/86`. Proof: post-validator headers and generated C++ show these support scores/owners unchanged, with only [UID:000239] raised to `90/89`.
- [x] Score-limiting blockers researched: no-function raw start, no direct xrefs, PacketBuffer caller-text callee, generated-output drift, and split/padding boundaries. Proof: incorporated in target/support docs from the accepted report; no-function/no-xref remains a confidence cap, while PacketBuffer caller-text callee and generated C++ drift were corrected.
- [x] Owner/emitter changes to apply: none. Proof: [UID:000239] owner/emitter remained `0000ER`; support docs retained existing owner routes.
- [x] Split/rename/new-child changes to apply: none. Proof: no file splits, renames, or new child pages were created.
- [x] IDA DB changes to apply: none. Proof: no IDA DB edits were made or requested during implementation.
- [x] First-draft C++ to apply: corrected formal code block in this report. Proof: target formal block and generated `TextMenuDialogs.cpp` contain `SendInputReply(const wchar_t *inputTextWide)` and `PacketBufferAppendWideStringAsAnsi8(packet, &cursor, inputTextWide)`.
- [x] Historical/stale assumptions and negative evidence to preserve: stale prior ANSI-argument claim, no direct xrefs, no IDA function object, decompile failure at raw start, generated-output stale state. Proof: target/support Changes sections preserve the superseded `const char *` wording as historical, and target Status/Evidence keep no-xref/no-function/decompile-failure limitations.
- [x] Wave2/Wave3 artifacts encountered: generated/autogen output checked only as read-only drift evidence; no stale Wave2/Wave3 claim was used as proof. Proof: implementation did not edit generated/project-level/manual coverage files; generated output was checked only after validators.
- [x] Open questions to close/document: keep no-direct-xref/no-function as evidence-backed confidence cap; keep exact original parameter spelling open but use `inputTextWide` as best source-facing name. Proof: target Role/Score Rationale/Open caveat keep no raw-start xref/function-object cap and use descriptive `inputTextWide`.
- [x] Validators to run after accepted implementation: the four scoped file validators listed above with `--wait-generated --queue-timeout 240`. Proof: ran from `source-3/project-documentation`: target `000000000998` at `2026-06-25T03:33:23-04:00`, class `000000000999` at `2026-06-25T03:33:41-04:00`, aggregate `000000001000` at `2026-06-25T03:33:58-04:00`, file page `000000001001` at `2026-06-25T03:34:12-04:00`; all exit 0, `ok:1`, generated refresh completed. Target retry `000000001004` at `2026-06-25T03:36:02-04:00` also exit 0, `ok:1`, generated refresh completed but reproduced stale Item Summary rewrite; supervisor resolved with target validator `000000001012` using `--no-generated-refresh`, exit 0, `ok:1`.
- [x] Generated refresh expectation: generated `TextMenuDialogs.cpp` and `-ag-*` reports should update from source metadata; do not manually edit generated reports or generated C++. Proof: generated `auto-generated/NexusTK/ui/dialogs/TextMenuDialogs.cpp` header shows `validator-command-id: 000000001004`, `validator-refreshed-at: 2026-06-25T03:36:02-04:00`, and contains corrected [UID:000239] `Completion:90 | Confidence:89`, `SendInputReply(const wchar_t *inputTextWide)`, and `PacketBufferAppendWideStringAsAnsi8(packet, &cursor, inputTextWide)`. Supervisor intentionally validated the final Item Summary with `000000001012` and `--no-generated-refresh` to avoid reintroducing stale generated metadata.
- [x] Manual coverage/tracker text: none supplied because no explicit manual coverage-report permission was granted. Proof: B010 did not edit manual coverage/tracker files; supervisor separately fixed/validated the manual row and later fixed the target Item Summary conflict with command `000000001012`.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation. Proof: callback assigned `B010-implement-000239-text-input-menu-dialog-reply-packet-helper-20260625`.
- [x] All accepted target/support doc details incorporated at report-level detail. Proof: target, class, aggregate, and file pages were edited; supervisor fixed the final stale target Item Summary conflict directly and validated it with `000000001012`.
- [x] Metadata/score/C++ changes applied or explicitly not applied with reason. Proof: [UID:000239] is `90/89`, owner/emitter/reconstructable preserved, formal C++ corrected; support metadata remained [UID:0000ER] `88/88`, [UID:0001BN] `86/88`, [UID:0000OP] `90/86`.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved. Proof: docs preserve the superseded ANSI-argument claim, rejected PacketBuffer/TextEditControlPane/socket/network owners, and no-function/no-xref confidence cap.
- [x] Validators run and command metadata recorded. Proof: B010 validators `000000000998`, `000000000999`, `000000001000`, `000000001001`, retry `000000001004`, plus supervisor fix validator `000000001012`; all recorded above with result summaries.
- [x] Generated output checked for corrected [UID:000239] signature/helper call or exact refresh blocker reported. Proof: generated `TextMenuDialogs.cpp` from `000000001004` contains corrected wide signature and helper call. The stale Item Summary generated-refresh conflict was reported as `PAUSED_VALIDATOR_METADATA_CONFLICT`; supervisor fixed target source with `000000001012` using generated refresh disabled.
- [x] Remaining unapplied accepted items listed with exact blocker. Proof: no accepted items remain unapplied after supervisor fix `000000001012`; B010 leases are released and current lease report has no B010 entries.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000004165","destination_path":"executed-b-agent-research/B010/000239-TextInputMenuDialogReplyPacketHelper-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B010/research/000239-TextInputMenuDialogReplyPacketHelper-source-quality.md","timestamp":"2026-06-25T03:42:19","uid":"000239"} -->
<!-- {"agent":"B010","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000239-TextInputMenuDialogReplyPacketHelper-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B010/000239-TextInputMenuDialogReplyPacketHelper-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000239"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
