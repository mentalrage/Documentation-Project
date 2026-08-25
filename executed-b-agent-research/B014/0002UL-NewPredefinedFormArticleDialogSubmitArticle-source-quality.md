** TARGET-REPORT-UID:0002UL **
** AUTHOR-AGENT-ID:B014 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 0002UL NewPredefinedFormArticleDialogSubmitArticle Source-Quality Research

## Current Recommendation

- Target: [UID:0002UL] `by-memory/0x00478be0-0x00478f8e.NewPredefinedFormArticleDialogSubmitArticle.md`.
- Recommendation: keep the direct class owner/emitter route through [UID:000098] `NewPredefinedFormArticleDialog`, raise the target from `COMPLETION:86`, `CONFIDENCE:87` to `COMPLETION:90`, `CONFIDENCE:91`, and populate the target formal C++ block.
- Source-facing method: `void NewPredefinedFormArticleDialog::SubmitArticle(short boardId)`.
- The previous blank-C++ blockers are now confidence caps, not code blockers. Current support docs already provide source-facing names for `PacketBufferWriteUInt8`, `PacketBufferWriteUInt16BE`, `QueueAndSendPacket`, `g_packetSender`, `g_pUserPane`, `TextEditControlPane`, and the `PredefinedFormArticleEntry` layout enough for a first-draft exact child body.
- Do not edit coverage reports or generated files. The stale `auto-generated` rows still show this target at `78/86` / `emits_code:false`; those are generated-refresh observations only and should be updated by validator/autogen, not by hand.
- No by-* docs, generated files, coverage reports, IDA DB state, validator/tool state, or leases were modified in this report-only pass.

## Evidence Checked

- Assignment and workflow:
  - `tools/leaser/Agents/Agent-B014/goal.md`
  - `tools/leaser/Agents/Supervisor.md`
  - `.codex/skills/ntk-b-agent-workflow/SKILL.md`
  - `.codex/skills/ntk-b-agent-workflow/references/b-agent-research-and-implementation-workflow.md`
  - `.codex/skills/ntk-b-agent-workflow/references/supervisor-rule26-review-and-incorporation-standard.md`
  - `by-structure.md`
- Target and NewPredefined support:
  - `by-memory/0x00478be0-0x00478f8e.NewPredefinedFormArticleDialogSubmitArticle.md`
  - `by-memory/0x00478240-0x004782a2.NewPredefinedFormArticleDialogHandleButtonClick.md`
  - `by-memory/0x004777a0-0x00478f8e.NewPredefinedFormArticleDialog.md`
  - `by-memory/0x004777a0-0x004781e5.NewPredefinedFormArticleDialogConstructor.md`
  - `by-memory/0x00478650-0x00478933.DeserializePredefinedFormArticleEntries.md`
  - `by-item/DeserializePredefinedFormArticleEntries_478650.md`
  - `by-memory/0x00478aa0-0x00478bd9.NewPredefinedFormArticleDialogUnreferencedTransferReplyHelper.md`
  - `by-class/NewPredefinedFormArticleDialog.md`
  - `by-file/NewPredefinedFormArticleDialog.md`
- Packet/text/global support:
  - `by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md`
  - `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md`
  - `by-global/g_packetSender.md`
  - `by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md`
  - `by-global/g_pCollectionData.md`
  - `by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md`
  - `by-class/TextEditControlPane.md`
  - `by-file/TextEditControlPane.md`
  - `by-memory/0x004988d0-0x00498dd0.TextEditControlPaneCore.md`
- Sibling/analogue context:
  - `executed-b-agent-research/B005/00030K-NewArticleDialogCore-source-quality.md`
  - `executed-b-agent-research/B005/0002UO-NewPredefinedFormArticleDialogOnPaint-source-quality.md`
  - `executed-b-agent-research/B005/0002UM-NewPredefinedFormArticleDialogHandleEvent-source-quality.md`
  - `executed-b-agent-research/B001/0002UR-NewPredefinedFormArticleDialogUnreferencedTransferReplyHelper.md`
- Generated/current-state observations, read only:
  - `auto-generated/-ag-memory-coverage.md`
  - `auto-generated/-ag-coverage-report-by-memory.md`
  - `auto-generated/-ag-research-tracker.md`
  - `by-memory/-coverage-report.md`

## Live IDA MCP Evidence

Active MCP session:

- `idb_list` command id `3`, observed at `2026-06-26T06:37:46-04:00`, reports session `80de0a67`, worker PID `26892`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, active, owned/adopted, `is_analyzing:false`.
- `server_health` command id `10`, timestamp `2026-06-26T06:38:25.1150588-04:00`, reports `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`.

Focused target commands:

- `lookup_funcs` command id `11`:
  - `0x00478be0` is `sub_478BE0`, size `0x3ae` / 942.
  - `0x00478f8e` and `0x00478f90` are `Not a function`.
  - caller [UID:0002UK] `0x00478240` is `sub_478240`, size `0x62` / 98.
  - parser `0x00478650` is `sub_478650`, size `0x2e3`.
  - live transfer-reply handler `0x00478940` is `sub_478940`, size `0x153`.
  - retained helper `0x00478aa0` is `sub_478AA0`, size `0x139`; `0x00478bd9` is not a function.
  - normal article submit `0x00477590` is `sub_477590`, size `0x200`.
- `xrefs_to` command id `17`:
  - `0x00478be0` has exactly one xref: code `0x0047827e` inside `sub_478240`.
  - `0x00478240` has one xref: data slot `0x00614098`.
  - `0x00478940` has one xref: data slot `0x006140ac`.
  - `0x00478aa0` has zero xrefs.
  - normal `NewArticleDialog` submit `0x00477590` has code caller `0x004771ee`.
- `analyze_function` command id `14` on `0x00478be0`:
  - prototype as currently decompiled: `int __thiscall(unsigned int this, __int16)`, size 942, 23 basic blocks, cyclomatic complexity 14.
  - callers: `sub_478240`.
  - callees: `__alloca_probe`, `sub_516030`, `sub_498C10`, `_wcscpy_s`, `sub_516220`, `sub_575380`, `sub_5753A0`, `WideCharToMultiByte`, `sub_574BB0`, `sub_5975E0`, `@__security_check_cookie@4`, and `___report_rangecheckfailure`.
  - no `ValidateChatInputOrThrowPasswordError` or `SanitizeWideTextForChat` calls appear in this predefined-form submitter.
- `analyze_function` command id `15` on `0x00478240`:
  - vtable-routed handler has no ordinary callers and data xref `0x00614098`.
  - OK path reads `this+0x270`, uses `session+0x102` as the selected board id when non-null, calls `sub_478BE0(a1, v7)` at `0x0047827e`, stores `this` at `dword_67A748+0x214`, and calls `sub_4A12B0`.
  - Cancel path checks `a3 == 1`, then calls `sub_4A10E0(session, ..., 0)`.
- `decompile` command id `18` on `0x00478be0`:
  - subject control id `3`, `ReadText` limit `0xff`.
  - body starts as empty wide string `word_60DB20`.
  - if `this+0x274` is zero, no body control is read.
  - if `byte [dword_67A748+0x1340fc]` is nonzero, free-text body control id `4` is read with limit `0xfff`.
  - otherwise the row loop reads controls `2*row+4` and `2*row+5`, appends label/value text, reads row byte at effective entry offset `+0x202` / raw absolute `this + row*0x40c + 0x47a`, and reads row dword at entry offset `+0x408` / raw absolute `this + row*0x40c + 0x680`.
  - packet serialization writes opcode `59` / `0x3b`, subcommand `4`, big-endian board id, one-byte subject length and bytes, two-byte body length and bytes, then sends through `dword_67A7EC` and calls `sub_5975E0(this+0xa4, 0, 15000, 0, 0)`.
- `disasm` command id `19`:
  - 253 instructions total.
  - prologue stack frame uses `0xD214`; local packet storage is `0x8000` bytes with explicit send-length guard `packetLength < 0x7fff`.
  - range-check failure tail is at `0x00478f89`.
  - ordinary return is `retn 4` at `0x00478f86`.
- `get_bytes` command id `20`:
  - `0x00478bd9-0x00478be0` is seven `0xcc` bytes.
  - `0x00478f8e-0x00478f90` is two `0xcc` bytes.
  - `0x00478238-0x00478240` is eight `0xcc` bytes.
  - `0x004782a2-0x004782b0` is fourteen `0xcc` bytes.
- `int_convert` command id `21`:
  - `0x3ae` = `942`, `0x62` = `98`, `0x3b` = `59`, `0x3a98` = `15000`, `0x7fff` = `32767`, `0x40c` = `1036`.
  - `1261820` = `0x1340fc`, `628` = `0x274`, `508` = `0x1fc`, `1146` = `0x47a`, `1664` = `0x680`, `532` = `0x214`, `624` = `0x270`, `258` = `0x102`.

## Boundary, Split, And Reachability

The existing split is correct and should not be adjusted:

- Target half-open range: `0x00478be0-0x00478f8e`.
- Predecessor [UID:0002UR] ends at `0x00478bd9`, followed by seven `0xcc` bytes before this target.
- Target normal return is `retn 4` at `0x00478f86`; `___report_rangecheckfailure` remains in the range at `0x00478f89`.
- The successor bytes `0x00478f8e-0x00478f90` are padding before raw [UID:00021A] `TransferReplyAlertRawConstructor`.
- The sole code caller is [UID:0002UK] at `0x0047827e`. This is a source-authored class helper reached from the OK button path, not a no-route retained helper and not a vtable slot itself.
- Do not merge the body into [UID:0002UK]. The caller reads the selected board id and manages post-submit dialog/session side effects; this target owns the article body assembly and opcode `0x3b` / subcommand `4` serialization.

## Behavior Resolved

`SubmitArticle(short boardId)` builds a predefined-form article post packet.

Subject path:

- Reads control id `3` through the dialog control container at `this+0x1fc`.
- Copies up to `0xff` UTF-16 characters into a `0x100` wide buffer.
- Converts only the returned character count with `WideCharToMultiByte(CP_ACP, 0, ..., cbMultiByte=0x100)`.
- Writes one byte of converted subject length, then exactly that many subject bytes.

Body path:

- Initializes body text to the shared empty wide string.
- If `this+0x274` entry count is zero, the body stays empty.
- If `g_pUserPane` / raw `dword_67A748` flag `+0x1340fc` is set, reads one free-text body control id `4` with limit `0xfff`.
- Otherwise loops over parsed predefined-form rows using the `0x40c` byte stride:
  - row label control id `4 + row*2`;
  - row value control id `5 + row*2`;
  - record-local byte `+0x202` / submit absolute offset `+0x47a` controls insertion of a space after the label when clear;
  - record-local dword `+0x408` / submit absolute offset `+0x680` controls the separator after the value: `0` -> space, `1` -> carriage return, other values -> no separator.
- Converts the assembled body with `WideCharToMultiByte(CP_ACP, 0, ..., cbMultiByte=0x1000)`.
- Writes two-byte big-endian body length and exactly that many body bytes.

Packet and UI side effects:

- Packet layout is `[0x3b, 0x04, boardId:u16be, subjectLen:u8, subjectBytes..., bodyLen:u16be, bodyBytes...]`.
- The local packet buffer has `0x8000` stack bytes and an explicit `packetLength < 0x7fff` guard. The local zero after the sent bytes is not protocol payload.
- The send path is `QueueAndSendPacket(g_packetSender, packet, packetLength)` via raw `sub_574BB0(dword_67A7EC, ...)`.
- After queueing, the method schedules the post-send wait/timeout through raw `sub_5975E0(this+0xa4, 0, 15000, 0, 0)`.

## Source-Facing Names

| Raw/decompiler item | Recommended source-facing spelling | Evidence and caveat |
| --- | --- | --- |
| `sub_478BE0` | `NewPredefinedFormArticleDialog::SubmitArticle(short boardId)` | Existing target/class names, sole caller [UID:0002UK], and normal `NewArticleDialog::SubmitArticle` sibling. |
| decompiler `int` return | `void` | [UID:0002UK] ignores the return, and the normal article sibling is treated as a submit side-effect method. The apparent `int` is the tail expression from `sub_5975E0`, not a consumed source result. |
| `this+0x1fc` virtual `+0x10` | `GetControl(controlId)` | Existing class/control docs use source-facing control access, and [UID:0002EK] already emits `GetControl(7)`. |
| `sub_498C10` | `TextEditControlPane::ReadText` | [UID:0000EM]/[UID:00011H]/[UID:0002OA] document this as the text-edit read/accessor family; exact original method spelling is still inferred. |
| `this+0x274` | `m_predefinedFormEntryCount` | Parser and constructor docs identify this as parsed entry count. |
| `this+0x278 + row*0x40c` | `m_predefinedFormEntries[row]` | Parser docs define `PredefinedFormArticleEntry` records at this stride. |
| record `+0x202` | `usesUserImagePane` | Parser docs name the byte at `+0x202`; target reads the same field through submit absolute offset `+0x47a`. |
| record `+0x408` | `rowAdvanceMode` | Parser docs identify the extra-row-advance flag; target uses values `0` and `1` as space/carriage-return separators. |
| `dword_67A748+0x1340fc` | `g_pUserPane->m_predefinedFormArticleFreeTextMode` | Constructor and target both use it as the predefined-form free-text branch flag. This is a first-draft typed-view field name and remains a confidence cap. |
| `sub_575380` | `PacketBufferWriteUInt8` | [UID:0003YJ] documents the byte writer and spare-zero convention. |
| `sub_5753A0` | `PacketBufferWriteUInt16BE` | [UID:0003YJ] documents high-byte-first word writer and spare-zero convention. |
| `sub_516220` | `memmove` | Existing copy-helper pages and prior packet helpers use source-facing `memmove`. |
| `dword_67A7EC` / `sub_574BB0` | `g_packetSender` / `QueueAndSendPacket` | [UID:0000Q5], [UID:0001P0], and [UID:0001HU] resolve Socket-owned sender and queue/send names. |
| `sub_5975E0(this+0xa4, 0, 15000, 0, 0)` | `StartTransferTimeout(15000)` | Source-facing side-effect name by behavior and normal article sibling; exact helper/member spelling remains a confidence cap. |

## First-Draft C++ Eligibility

Formal C++ is ready for this exact child because:

- `RECONSTRUCTABLE:TRUE`.
- `EMITTER_UIDS:000098`.
- Direct class/file route clears the gate: target child `86/87`, class parent `85/86`, file parent `88/85`, with recommended target `90/91`.
- The target has one live caller and exact boundaries.
- Packet helper/global names are now better supported than the target page currently says.
- Parser/constructor docs provide enough row-layout names for a first-draft method body.
- Remaining uncertainties are private field/helper spellings, not behavior, range, route, or packet layout.

The following block is the exact formal insertion content recommended for the target page. It is not an illustrative snippet.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void NewPredefinedFormArticleDialog::SubmitArticle(short boardId)
{
    char packet[0x8000] = {};
    char convertedText[0x1000] = {};
    wchar_t subject[0x100] = {};
    wchar_t body[0x1000] = {};
    wchar_t fieldText[0x1000] = {};

    const int subjectLength =
        static_cast<unsigned short>(
            static_cast<TextEditControlPane *>(GetControl(3))->ReadText(subject, 0xff));

    int bodyLength = 0;
    body[0] = L'\0';

    if (m_predefinedFormEntryCount != 0)
    {
        if (g_pUserPane->m_predefinedFormArticleFreeTextMode)
        {
            bodyLength =
                static_cast<unsigned short>(
                    static_cast<TextEditControlPane *>(GetControl(4))->ReadText(body, 0xfff));
            if (static_cast<unsigned int>(bodyLength * sizeof(wchar_t)) >= 0x2000)
            {
                __report_rangecheckfailure();
            }
            body[bodyLength] = L'\0';
        }
        else
        {
            for (unsigned char rowIndex = 0;
                 rowIndex < m_predefinedFormEntryCount;
                 ++rowIndex)
            {
                const PredefinedFormArticleEntry& entry =
                    m_predefinedFormEntries[rowIndex];

                const int labelLength =
                    static_cast<unsigned short>(
                        static_cast<TextEditControlPane *>(
                            GetControl(4 + rowIndex * 2))->ReadText(fieldText, 0xfff));
                if (static_cast<unsigned int>(labelLength * sizeof(wchar_t)) >= 0x2000)
                {
                    __report_rangecheckfailure();
                }
                fieldText[labelLength] = L'\0';
                memmove(body + bodyLength, fieldText, labelLength * sizeof(wchar_t));
                bodyLength += labelLength;

                if (!entry.usesUserImagePane)
                {
                    body[bodyLength++] = L' ';
                }

                const int valueLength =
                    static_cast<unsigned short>(
                        static_cast<TextEditControlPane *>(
                            GetControl(5 + rowIndex * 2))->ReadText(fieldText, 0xfff));
                if (static_cast<unsigned int>(valueLength * sizeof(wchar_t)) >= 0x2000)
                {
                    __report_rangecheckfailure();
                }
                fieldText[valueLength] = L'\0';
                memmove(body + bodyLength, fieldText, valueLength * sizeof(wchar_t));
                bodyLength += valueLength;

                if (entry.rowAdvanceMode == 0)
                {
                    body[bodyLength++] = L' ';
                }
                else if (entry.rowAdvanceMode == 1)
                {
                    body[bodyLength++] = L'\r';
                }
            }
        }
    }

    if (static_cast<unsigned int>(bodyLength * sizeof(wchar_t)) >= 0x2000)
    {
        __report_rangecheckfailure();
    }
    body[bodyLength] = L'\0';

    PacketBufferWriteUInt8(packet, 0x3b);
    PacketBufferWriteUInt8(packet + 1, 0x04);
    PacketBufferWriteUInt16BE(packet + 2, static_cast<unsigned short>(boardId));

    const int subjectByteLength = WideCharToMultiByte(
        CP_ACP,
        0,
        subject,
        subjectLength,
        convertedText,
        0x100,
        NULL,
        NULL);
    if (static_cast<unsigned int>(subjectByteLength) >= sizeof(convertedText))
    {
        __report_rangecheckfailure();
    }
    convertedText[subjectByteLength] = '\0';
    PacketBufferWriteUInt8(packet + 4, subjectByteLength);
    memmove(packet + 5, convertedText, subjectByteLength);

    const int bodyByteLength = WideCharToMultiByte(
        CP_ACP,
        0,
        body,
        bodyLength,
        convertedText,
        sizeof(convertedText),
        NULL,
        NULL);
    if (static_cast<unsigned int>(bodyByteLength) >= sizeof(convertedText))
    {
        __report_rangecheckfailure();
    }
    convertedText[bodyByteLength] = '\0';

    char *bodyLengthField = packet + 5 + subjectByteLength;
    PacketBufferWriteUInt16BE(bodyLengthField, bodyByteLength);
    memmove(bodyLengthField + 2, convertedText, bodyByteLength);

    const int packetLength = subjectByteLength + bodyByteLength + 7;
    if (static_cast<unsigned int>(packetLength) >= 0x7fff)
    {
        __report_rangecheckfailure();
    }
    packet[packetLength] = '\0';

    QueueAndSendPacket(g_packetSender, packet, packetLength);
    StartTransferTimeout(15000);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Implementation notes for the formal block:

- `PacketBufferWriteUInt8` and `PacketBufferWriteUInt16BE` are written in the project's established destination-first source-wrapper style, even though the raw ABI pushes destination before value for a value-first callee.
- `packet[0x8000]` matches the contiguous stack packet storage; the send length remains capped at `< 0x7fff`.
- No validation/sanitization calls are included because current MCP callees and decompilation do not show them in this predefined submitter. The normal `NewArticleDialog::SubmitArticle` sibling has that extra text-filter path; this target does not.
- The formal C++ keeps the source-body side effect as `void`. The caller ignores a result, and the decompiler's `int` is only the tail expression from the timeout helper.

## Rejected Alternatives

- Keep final C++ blank pending `95+` or original private names: rejected. Current workflow no longer requires a stale `95+` gate, and existing support docs close the helper/global names enough for target-level first-draft C++.
- Keep final C++ blank because row fields and free-text flag names are inferred: rejected as too conservative. Those names cap confidence below final audit; they do not block a behavior-preserving child body because the row offsets, branch values, control ids, and packet bytes are exact.
- Route ownership to `Socket`, `PacketBuffer`, `TextEditControlPane`, or `UserPane`: rejected. Those are dependencies consumed by this class method. The sole code caller and class cluster prove direct ownership by [UID:000098].
- Merge this method into [UID:0002UK] `HandleButtonClick`: rejected. The button handler performs selection/session side effects and calls this helper; this helper performs body assembly and packet serialization.
- Merge this method into the aggregate [UID:0000ZL]: rejected. The project already emits method bodies on exact child pages for this class, including [UID:0002EK], [UID:0002UM], and [UID:0002UO].
- Model this as `int SubmitArticle(...)`: rejected for source-facing C++. No caller consumes a return value; the apparent integer is only produced by tail-returning `sub_5975E0`.
- Add normal article validation/sanitization calls by analogy to [UID:00030K]: rejected. Live current MCP callee inventory for this exact target lacks those calls, so adding them would alter behavior.
- Treat `0x00478f8e-0x00478f90` as part of the body or merge with [UID:00021A]: rejected by `lookup_funcs`, disassembly, and byte evidence.

## Score And Metadata Recommendation

Recommended target metadata:

```text
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000098 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000098 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Rationale:

- Raise completion to `90` because the target can now carry formal first-draft C++, exact current MCP session evidence, source-facing packet/helper names, row field mappings, route proof, split proof, and rejected alternatives.
- Raise confidence to `91` because behavior, caller, range, packet layout, row offsets, and helper/global routes are all current-MCP and support-doc backed.
- Do not raise higher: `m_predefinedFormArticleFreeTextMode`, `m_predefinedFormEntries`, `PredefinedFormArticleEntry`, `ReadText`, and `StartTransferTimeout` are source-facing first-draft names, not recovered original declarations; the constructor/parser pages still lack final full class layout C++.

Recommended target item summary:

```text
Source-ready `NewPredefinedFormArticleDialog::SubmitArticle(short boardId)` first-draft C++ for opcode `0x3b`/subcommand `4`: reads subject control `3`, free-text control `4` or parsed-row label/value control pairs, serializes board id plus subject/body ANSI payloads, queues through `g_packetSender`, and starts the 15000 ms post-send wait.
```

## Support Update Plan

Accepted implementation edits if the supervisor approves this report:

- `by-memory/0x00478be0-0x00478f8e.NewPredefinedFormArticleDialogSubmitArticle.md`
  - Update scores to `90/91`.
  - Keep `CANONICAL_OWNER:000098`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000098`, and blank emitter position.
  - Insert the exact formal `RECONSTRUCTION_CPP CODE` block from this report.
  - Replace the stale item summary with the recommended source-ready summary.
  - Replace "Final C++ remains blank" / "packet helper names not source-final" wording with current source-ready first-draft rationale.
  - Add current MCP evidence command ids `10`, `11`, `14`, `15`, `17`, `18`, `19`, `20`, and `21`.
  - Add explicit no-validation/sanitization contrast with normal `NewArticleDialog::SubmitArticle`.
  - Add rejected alternatives and void-return rationale.
- `by-memory/0x00478240-0x004782a2.NewPredefinedFormArticleDialogHandleButtonClick.md`
  - Narrow support sync only: the OK path now calls a source-ready `SubmitArticle(short boardId)` child with formal C++ on [UID:0002UL].
  - Keep this handler's own C++ blank unless a separate callback resolves session/helper names.
  - No score change required.
- `by-class/NewPredefinedFormArticleDialog.md`
  - Update the `SubmitArticle` method row and evidence notes so submit/packet helper naming is no longer listed as a class-level child C++ blocker.
  - State that first-draft C++ lives on exact child [UID:0002UL].
  - Keep class-level C++ blank because executable bodies live on exact children and broader constructor/parser/alert/retained-helper policy still block a whole-class body.
  - No score change required.
- `by-file/NewPredefinedFormArticleDialog.md`
  - Update the proposed contents, packet/layout model, and boundary notes to record [UID:0002UL] as source-ready first-draft C++ through the `NewPredefinedFormArticleDialog` route.
  - Remove submit/packet wrapper names from file-level blank-C++ blockers; keep constructor/parser/alert/retained-helper caveats.
  - No score change required.
- `by-memory/0x004777a0-0x00478f8e.NewPredefinedFormArticleDialog.md`
  - Update the child table, autogen/reconstruction notes, data issues, and score rationale so [UID:0002UL] is no longer an aggregate blank-C++ blocker.
  - Keep aggregate C++ blank because constructor, parser, alert packet naming, class layout, and retained `0x00478aa0` source-emission policy remain separate blockers.
  - No score change required.

Check-only / no-edit proof unless a future callback finds a contradiction:

- `by-memory/0x00478650-0x00478933.DeserializePredefinedFormArticleEntries.md` and `by-item/DeserializePredefinedFormArticleEntries_478650.md`: already document the `0x40c` stride and `+0x202` / `+0x408` fields at equal-or-greater detail. No edit required for this target.
- `by-memory/0x004777a0-0x004781e5.NewPredefinedFormArticleDialogConstructor.md`: already documents `this+0x274`, `this+0x276`, entries at `this+0x278`, free-text flag `dword_67A748+0x1340fc`, and dynamic control creation. No edit required unless the callback wants a one-sentence "submit child now source-ready" sync.
- `by-memory/0x00478aa0-0x00478bd9.NewPredefinedFormArticleDialogUnreferencedTransferReplyHelper.md`: unrelated retained alert helper; no edit.
- `by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md`, `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md`, `by-global/g_packetSender.md`, and `by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md`: already provide source-facing helper/global names at equal-or-greater detail. No edit.
- `by-global/g_pCollectionData.md` and `by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md`: already establish canonical `g_pUserPane`; this callback can keep the `+0x1340fc` free-text typed-view local to the target page rather than widening UserPane layout docs.
- `by-class/TextEditControlPane.md`, `by-file/TextEditControlPane.md`, and `by-memory/0x004988d0-0x00498dd0.TextEditControlPaneCore.md`: already support `TextEditControlPane` and read-text/accessor helper family. No edit.
- `by-memory/-coverage-report.md`, any other `-coverage-report.md`, generated files, project-level generated files, validator state, IDA DB: excluded.

## Validator Plan For Implementation Callback

Run from `E:\NTK\GhidraBridge\source-3\project-documentation` for every changed by-* file:

> Executable block R001 was removed from this report and preserved verbatim in [0002UL-NewPredefinedFormArticleDialogSubmitArticle-source-quality-removed.md](0002UL-NewPredefinedFormArticleDialogSubmitArticle-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Implementation callback validator results are recorded in the checked checklist below.

## Implementation Tracking Checklist

- [x] Lease only the immediate accepted edit batch, then release immediately after the edit/validator batch. Proof: initial lease report showed B002 active support leases for `by-memory/0x00478240-0x004782a2...`, `by-class/NewPredefinedFormArticleDialog.md`, `by-file/NewPredefinedFormArticleDialog.md`, and `by-memory/0x004777a0-0x00478f8e...` created `2026-06-26T18:19:36Z`, expiring `2026-06-26T18:24:36Z`; target-only B014 lease succeeded and was released after the first target validator. After B002 expiry, B014 support lease succeeded; because that lease expired during the support edit, B014 reacquired a fresh all-five changed-file lease before final cleanup/validators. Final `python .\tools\leaser\leaser.py B014 unlease ...` returned `Success` for all five files, and `tools/leaser/Agents/current_leases.md` after release showed no active B014 rows.
- [x] Update [UID:0002UL] target metadata to `COMPLETION:90`, `CONFIDENCE:91`, keep owner/emitter `000098`, keep reconstructable true, and preserve blank emitter position. Proof: `by-memory/0x00478be0-0x00478f8e.NewPredefinedFormArticleDialogSubmitArticle.md` header now has `COMPLETION:90`, `CONFIDENCE:91`, `CANONICAL_OWNER:000098`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000098`, and blank `EMITTER_POSITION_OPTIONAL`.
- [x] Insert the exact formal `RECONSTRUCTION_CPP CODE` marker/block content from this report into [UID:0002UL]. Proof: target formal block now contains the three required marker lines and `void NewPredefinedFormArticleDialog::SubmitArticle(short boardId)` with destination-first `PacketBufferWriteUInt8` / `PacketBufferWriteUInt16BE`, `g_packetSender`, and `StartTransferTimeout(15000)`.
- [x] Replace [UID:0002UL] item summary with the recommended source-ready summary. Proof: target `Item Summary` now begins `Source-ready NewPredefinedFormArticleDialog::SubmitArticle(short boardId) first-draft C++ for opcode 0x3b/subcommand 4...`.
- [x] Incorporate [UID:0002UL] current MCP evidence at report-level detail: session `80de0a67`, command ids `10`, `11`, `14`, `15`, `17`, `18`, `19`, `20`, `21`, exact boundary, sole caller, vtable route via [UID:0002UK], free-text and row branches, packet layout, no validation/sanitizer calls, send path, 15000 ms timeout, and rejected alternatives. Proof: target `Address Range`, `Behavior`, `Evidence`, `Touched State And Data Flow`, `Source-Facing Name Caveats`, `Rejected Alternatives`, `Score Rationale`, and `Changes` sections were updated with those facts.
- [x] Update [UID:0002UK] caller page with narrow support sync that the OK path now reaches source-ready [UID:0002UL] first-draft C++; keep handler C++ disposition consistent with its own accepted B002 report. Proof: `by-memory/0x00478240-0x004782a2.NewPredefinedFormArticleDialogHandleButtonClick.md` `Behavior`, `Evidence`, and `Changes` now state the OK path calls source-ready [UID:0002UL]; this page's own B002 formal `OnCommand` C++ was preserved and not broadened.
- [x] Update [UID:000098] class page method row and evidence/score rationale so submit/packet naming is no longer a child C++ blocker; keep class-level C++ blank. Proof: `by-class/NewPredefinedFormArticleDialog.md` `Status`, `Method Notes`, `Evidence Notes`, `Score Rationale`, and `Changes` now include B014 [UID:0002UL] source-ready `SubmitArticle(short boardId)` evidence; stale `submit/packet` blocker wording was replaced with constructor/parser/layout/alert/retained-helper blockers.
- [x] Update [UID:0000LT] file page proposed contents/packet model/boundary notes so [UID:0002UL] emits first-draft C++ through this source route; keep file page metadata-only. Proof: `by-file/NewPredefinedFormArticleDialog.md` `Proposed Contents`, `Packet And Layout Model`, `Boundary Notes`, `Score Rationale`, and `Changes` now list [UID:0002UL] as source-ready child emission through [UID:000098] while this by-file page remains metadata-only.
- [x] Update [UID:0000ZL] aggregate page child table/reconstruction notes/data issues so [UID:0002UL] is source-ready on the exact child and no longer an aggregate blank-C++ blocker; keep aggregate C++ blank. Proof: `by-memory/0x004777a0-0x00478f8e.NewPredefinedFormArticleDialog.md` `Autogen status`, `Score Rationale`, `Covered Ranges`, `IDA MCP Evidence`, `Reconstruction Notes`, `Data Issues`, and `Changes` now include B014 source-ready [UID:0002UL] and retain aggregate blank C++ only for constructor/parser/alert/retained-helper issues.
- [x] Record no-edit proof for check-only pages: parser memory/item docs, constructor page, retained helper page, PacketBuffer/QueueAndSend/g_packetSender/g_pUserPane/TextEdit support pages. Proof: no edits were made to those pages. Current checked proof: parser memory/item docs already document `0x40c`, `+0x202`, `+0x408`; constructor page already documents `this+0x274`, `this+0x276`, `this+0x278`, `dword_67A748+0x1340fc`, dynamic controls, and free-text branch; retained helper page already documents no xrefs/raw VA/RVA/vtable slot for `0x00478aa0`; PacketBuffer page documents `PacketBufferWriteUInt8`, `PacketBufferWriteUInt16BE`, and destination-first wrapper caveat; QueueAndSend/g_packetSender pages document `QueueAndSendPacket` and `g_packetSender`; g_pCollectionData pages document canonical `g_pUserPane`; TextEditControlPane pages document the read-text/accessor family.
- [x] Run scoped validators for every changed by-* file from `source-3/project-documentation`. Proof:
  - `python .\tools\validator.py --mode file --file by-memory\0x00478be0-0x00478f8e.NewPredefinedFormArticleDialogSubmitArticle.md --apply --queue-timeout 240`: command id `000000002682`, timestamp `2026-06-26T14:35:11-04:00`, exit code `0`, `ok: 1`, warnings none; `generated_refresh: deferred`, generated refresh command id `000000002682`.
  - `python .\tools\validator.py --mode file --file by-memory\0x00478240-0x004782a2.NewPredefinedFormArticleDialogHandleButtonClick.md --apply --queue-timeout 240`: command id `000000002683`, timestamp `2026-06-26T14:35:13-04:00`, exit code `0`, `ok: 1`, warnings none; `uid_link_insert: 1`; `generated_refresh: deferred`, generated refresh command id `000000002683`.
  - `python .\tools\validator.py --mode file --file by-class\NewPredefinedFormArticleDialog.md --apply --queue-timeout 240`: command id `000000002685`, timestamp `2026-06-26T14:35:15-04:00`, exit code `0`, `ok: 1`, warnings none; `uid_link_insert: 2`; `generated_refresh: deferred`, generated refresh command id `000000002685`.
  - `python .\tools\validator.py --mode file --file by-file\NewPredefinedFormArticleDialog.md --apply --queue-timeout 240`: command id `000000002686`, timestamp `2026-06-26T14:35:25-04:00`, exit code `0`, `ok: 1`, warnings none; `uid_link_insert: 1`; `generated_refresh: deferred`, generated refresh command id `000000002686`.
  - `python .\tools\validator.py --mode file --file by-memory\0x004777a0-0x00478f8e.NewPredefinedFormArticleDialog.md --apply --queue-timeout 240`: command id `000000002687`, timestamp `2026-06-26T14:35:35-04:00`, exit code `0`, `ok: 1`, warnings none; `uid_link_insert: 1`; `generated_refresh: deferred`, generated refresh command id `000000002687`.
- [x] Do not edit `by-memory/-coverage-report.md`, any `-coverage-report.md`, generated/project-level files, validator/tool state, IDA DB, or stale/orphan reports. Proof: direct manual edits were limited to the five accepted by-* docs and this B014 report. Validator-owned side effects were reported from scoped validators: projected stats updates, incremental stats noops, and deferred generated refresh; no manual coverage/generated/IDA DB/tool-state edits were made.

## Implementation State

- Changed by-* files: `by-memory/0x00478be0-0x00478f8e.NewPredefinedFormArticleDialogSubmitArticle.md`; `by-memory/0x00478240-0x004782a2.NewPredefinedFormArticleDialogHandleButtonClick.md`; `by-class/NewPredefinedFormArticleDialog.md`; `by-file/NewPredefinedFormArticleDialog.md`; `by-memory/0x004777a0-0x00478f8e.NewPredefinedFormArticleDialog.md`.
- Changed report file: `tools/leaser/Agents/Agent-B014/research/0002UL-NewPredefinedFormArticleDialogSubmitArticle-source-quality.md`.
- No active B014 leases remain after final release.
- No unchecked implementation items remain.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B014","command_id":"000000004165","destination_path":"executed-b-agent-research/B014/0002UL-NewPredefinedFormArticleDialogSubmitArticle-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B014/research/0002UL-NewPredefinedFormArticleDialogSubmitArticle-source-quality.md","timestamp":"2026-06-26T14:45:54","uid":"0002UL"} -->
<!-- {"agent":"B014","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002UL-NewPredefinedFormArticleDialogSubmitArticle-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B014/0002UL-NewPredefinedFormArticleDialogSubmitArticle-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002UL"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
