** TARGET-REPORT-UID:0001MF **
** AUTHOR-AGENT-ID:B014 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001MF ShoutInputPane Source-Quality Report

Agent: Agent-B014  
Assignment: report-only first pass for [UID:0001MF] `by-memory/0x005b4260-0x005b43bc.ShoutInputPane.md`  
Required target: `tools/leaser/Agents/Agent-B014/research/0001MF-ShoutInputPane-source-quality.md`  
Status: implementation callback complete; accepted by-* edits applied and validated.

## Recommendation

Improvement is available. This is not a no-improvement case.

The stale "C++ blank under the 95+ gate" blocker should be removed from the target. Under the current project rule, formal C++ eligibility is not a `95+` score threshold: this page is `RECONSTRUCTABLE:TRUE`, has a valid nonblank emitter route through [UID:0000D5][ShoutInputPane](by-class/ShoutInputPane.md), and has `(86 + 89) / 2 = 87.5`, which clears the corrected source-code entry gate. The remaining source-quality blockers named on the target page have now been resolved well enough for a first-draft formal method body by the live IDA facts plus accepted sibling/helper pages.

Recommended target page outcome:

| Field | Current | Recommended |
| --- | ---: | ---: |
| `COMPLETION` | `86` | `90` |
| `CONFIDENCE` | `89` | `91` |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` |
| `CANONICAL_OWNER` | `0000D5` | `0000D5` |
| `EMITTER_UIDS` | `0000D5` | `0000D5` |

Recommended `Item Summary` replacement:

`Exact ShoutInputPane virtual submit method; live IDA confirms range 0x005b4260-0x005b43bc, vtable slot 0x0062fd48, LineInputPane text read/length gates, g_pCollectionData+0x134102 shout-send gate value 2, password guard, chat sanitizer, opcode 0x0e subtype 1 packet bytes, WideCharToMultiByte payload conversion, range checks, g_packetSender send path, constructor split, and first-draft method C++ readiness.`

The target range should stay `0x005b4260-0x005b43bc`. Do not absorb the raw constructor [UID:0002SA][0x005b4220-0x005b4255.ShoutInputPaneRawConstructor](by-memory/0x005b4220-0x005b4255.ShoutInputPaneRawConstructor.md), the `0x005b4255-0x005b4260` alignment bytes, or the `0x005b43bc-0x005b43c0` successor padding. I found no existing retained by-memory page for the adjacent prologue at `0x005b43c0`; this report does not recommend creating one inside this callback without a separate assignment.

## MCP Evidence

IDA MCP was available and used. No fallback-only report was produced.

Current endpoint/session:

- MCP endpoint: `http://127.0.0.1:13337/mcp`.
- JSON-RPC initialize id `1` succeeded on 2026-06-26 at about `04:40 -04:00`; `tools/list` id `2` succeeded and exposed the current named-parameter schemas.
- `idb_list` id `3`: active session `80de0a67`, input path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `26892`, `is_analyzing=false`.
- `server_health(database=80de0a67)` id `4`: `status=ok`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready=true`, `hexrays_ready=true`, `strings_cache_ready=true`, `strings_cache_size=2067`.
- Continuation sanity check on 2026-06-26 at `04:49 -04:00`: MCP listener `127.0.0.1:13337` was open, the expected `idalib-mcp.exe`/worker process tree was present, and corrected streamable-HTTP `initialize` id `9011` returned HTTP 200 with server `ida-pro-mcp` version `1.0.0`. An earlier direct `server_health` probe timed out and an `Invoke-WebRequest` retry without `-UseBasicParsing` failed locally; neither failed probe is used as target evidence.

Scoped target checks:

- `lookup_funcs` id `5` reports `0x005b4260 -> sub_5B4260`, size `0x15c` / 348 bytes (Verified with `tools/int_convert.py`), and reports `0x005b43bc` and raw constructor start `0x005b4220` are not function starts.
- The same lookup confirms the routed creator/helper at `0x005a5710 -> sub_5A5710`, size `0x81`, and the target callees: `0x004f2310`, `0x004f2300`, `0x00465890`, `0x005957c0`, `0x00516030`, `0x00575380`, `0x00516220`, and `0x00574bb0`.
- `xrefs_to` id `6` reports exactly one xref to the target start: data xref `0x0062fd48 -> 0x005b4260`. No xrefs target the vtable cell address itself. This is the expected virtual-dispatch shape.
- `decompile` id `8` confirms the full body: text length call, positive-length gate, `dword_67A748+0x134102` compare against `2`, copy limit `255`, password guard `sub_465890`, sanitizer `sub_5957C0`, packet scratch setup `sub_516030`, byte writes `sub_575380(14, &Src)` and `sub_575380(1, &v10)`, `WideCharToMultiByte`, converted-length guard `<0x100`, payload-length byte, payload copy through `sub_516220`, final length guard `<0x12c`, local terminator outside the sent length, and `sub_574BB0(dword_67A7EC, &Src, convertedLength + 3)`.
- `disasm` id `9` confirms the same instruction landmarks: stack frame `0x430` / 1072 bytes (Verified with `tools/int_convert.py`), `cmp byte ptr [eax+134102h], 2` at `0x005b428b`, opcode byte write at `0x005b42f4-0x005b42f6`, subtype byte write at `0x005b4302-0x005b4304`, `WideCharToMultiByte` at `0x005b4343`, range checks at `0x005b434b` and `0x005b4385`, `g_packetSender` load at `0x005b438d`, and send call at `0x005b43a3`.

Tooling note: an earlier `decompile` attempt with id `7` used the obsolete `addrs` shape and returned a schema error. It was corrected with id `8`; no evidence claim depends on the failed call.

Relevant numeric conversions were checked with `tools/int_convert.py`: `0x15c = 348`, `0x134102 = 1261826`, `0x0e = 14`, `0x100 = 256`, `0x12c = 300`, `0xff = 255`, `0x430 = 1072`, `0x35 = 53`, `0x81 = 129`, `0x3 = 3`, `0x2 = 2`, and `0x1 = 1`.

## Source-Quality Closure

The target is the ShoutInputPane virtual submit/send method, not a generic packet helper and not part of the raw constructor. The vtable-only reference at `0x0062fd48` and the absence of direct callers are normal for this input-pane override family. Source placement remains [UID:0000D5][ShoutInputPane](by-class/ShoutInputPane.md) under [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md).

The named blockers on the target page now have source-facing support:

| Binary fact | Source-facing use in target C++ | Support |
| --- | --- | --- |
| `0x004f2310` | `LineInputPane::TextLength()` | [UID:00035S][LineInputPaneTextLength](by-memory/0x004f2310-0x004f231b.LineInputPaneTextLength.md), plus the accepted `SayInputPane::OnSubmitChat` child |
| `0x004f2300(..., 255)` | `LineInputPane::CopyText(wideText, 255)` | [UID:00035R][LineInputPaneCopyText](by-memory/0x004f2300-0x004f230f.LineInputPaneCopyText.md) |
| `dword_67A748+0x134102 == 2` blocks send | `g_pCollectionData->chatInputSendBlocked == 2` | Accepted Say/Chat submit pages use this stable typed-view name; [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) now documents it as a view over canonical `g_pUserPane` |
| `0x00465890` | `ValidateChatInputOrThrowPasswordError(wideText)` | [UID:0002VH][ValidateChatInputOrThrowPasswordError](by-memory/0x00465890-0x00465ae2.ValidateChatInputOrThrowPasswordError.md), including this target as a caller |
| `0x005957c0` | `SanitizeWideTextForChat(wideText, wcslen(wideText))` | [UID:00041J][SanitizeWideTextForChat](by-memory/0x005957c0-0x005958ca.SanitizeWideTextForChat.md), which already emits first-draft helper C++ |
| `0x00516030` result held for the payload copy | `void *packetCopyContext = GetMemoryMan()` | Same source-facing pattern as accepted [UID:000416][SayInputPaneSubmitSayChat](by-memory/0x005b3670-0x005b37ea.SayInputPaneSubmitSayChat.md) |
| `0x00575380` | `PacketBufferWriteUInt8` | [UID:0003YJ][PacketBufferScalarBigEndianWriteHelpers](by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md); source drafts use the documented destination-first wrapper style even though raw ABI is value-first |
| `0x00516220` | `CopyPacketBytes(packetCopyContext, packet + 3, multibyteText, convertedLength)` | [UID:0001BH][MemmoveWrapper](by-memory/0x00516220-0x00516238.MemmoveWrapper.md) plus accepted submit-child precedent |
| `0x0067a7ec` and `0x00574bb0` | `QueueAndSendPacket(g_packetSender, packet, packetLength)` | [UID:0000Q5][g_packetSender](by-global/g_packetSender.md), [UID:0001P0][g_packetSender memory](by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md), and [UID:0001HU][QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md) |

The closest source precedent is [UID:000416][0x005b3670-0x005b37ea.SayInputPaneSubmitSayChat](by-memory/0x005b3670-0x005b37ea.SayInputPaneSubmitSayChat.md). That accepted child emits `void SayInputPane::OnSubmitChat()` despite the raw decompiler's 16-bit return model. The Shout target has the same virtual submit shape, no direct callers, no history-save tail, opcode `0x0e`, and subtype `1`. Therefore the formal Shout block should be a source-facing `void ShoutInputPane::OnSubmitInput()` body, not a decompiler artifact that preserves the low word of `g_pCollectionData` on the blocked branch.

One behavioral difference from the default Say submit child is intentional: Shout does not test `wideText[0] == L'\0'` after copying. The live decompile/disassembly shows no post-copy empty-string branch before the password guard, sanitizer, and packet construction.

## Formal C++ Block

Formal first-draft C++ is ready for the target page. The following is the exact formal `RECONSTRUCTION_CPP CODE` header/block content to place on [UID:0001MF][0x005b4260-0x005b43bc.ShoutInputPane](by-memory/0x005b4260-0x005b43bc.ShoutInputPane.md), including the repository marker lines:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ShoutInputPane::OnSubmitInput()
{
    const short textLength = LineInputPane::TextLength();
    if (textLength <= 0) {
        return;
    }

    if (g_pCollectionData->chatInputSendBlocked == 2) {
        return;
    }

    wchar_t wideText[256] = {};
    LineInputPane::CopyText(wideText, 255);

    ValidateChatInputOrThrowPasswordError(wideText);
    SanitizeWideTextForChat(wideText, static_cast<int>(wcslen(wideText)));

    const unsigned char kChatMessageOpcode = 0x0e;
    const unsigned char kShoutChatSubtype = 1;

    unsigned char packet[300] = {};
    char multibyteText[256] = {};
    void *packetCopyContext = GetMemoryMan();

    PacketBufferWriteUInt8(packet + 0, kChatMessageOpcode);
    PacketBufferWriteUInt8(packet + 1, kShoutChatSubtype);

    const int convertedLength = WideCharToMultiByte(
        0, 0, wideText, static_cast<int>(wcslen(wideText)),
        multibyteText, sizeof(multibyteText), 0, 0);
    if (convertedLength >= 0x100) {
        ReportRangeCheckFailure();
    }

    multibyteText[convertedLength] = '\0';
    PacketBufferWriteUInt8(packet + 2, convertedLength);
    CopyPacketBytes(packetCopyContext, packet + 3, multibyteText, convertedLength);

    const int packetLength = convertedLength + 3;
    if (packetLength >= 0x12c) {
        ReportRangeCheckFailure();
    }

    packet[packetLength] = 0;
    QueueAndSendPacket(g_packetSender, packet, packetLength);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

This block is first-draft source reconstruction, not final original-source proof. Confidence remains below final audit because the exact original method name, field spelling for `chatInputSendBlocked`, and final PacketBuffer/header declarations are inferred from project style and accepted sibling pages rather than recovered symbols.

## Support-Doc Impact

Implementation should update the target and the directly related support docs, but should not edit generated files, coverage reports, validator state, or IDA DB.

Required target update:

- [UID:0001MF][0x005b4260-0x005b43bc.ShoutInputPane](by-memory/0x005b4260-0x005b43bc.ShoutInputPane.md): replace the formal `RECONSTRUCTION_CPP CODE` header/block with the exact marker/block content above; raise to `90/91`; replace the stale item summary; replace the reconstruction note that says helper/global names are not source-quality; add current MCP provenance, vtable-only xref proof, packet layout, no-empty-copy-branch note, and the `void` submit-return rationale.

Required support updates:

- [UID:0000D5][ShoutInputPane](by-class/ShoutInputPane.md): update the `OnSubmitInput` row and reconstruction notes so class-level prose no longer says the submit method/helper/global naming remains a C++ blocker. Class-level C++ can remain blank because exact bodies live on by-memory children.
- [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md): update the `ShoutInputPane` row and change log to state that both the raw constructor child and submit child now have first-draft C++; preserve the `class_ShoutInputPane.cpp` route.
- [UID:0003JS][0x00630a6c-0x00630a78.ShoutPromptString](by-memory/0x00630a6c-0x00630a78.ShoutPromptString.md): no score or C++ change is required, but implementation should add one sentence if needed that the submit child is now first-draft populated while this literal page remains blank because it is data.

Intentionally excluded from this callback unless the supervisor explicitly authorizes sibling cleanup:

- [UID:0001MC][0x005b3940-0x005b3bba.ChatInputPane](by-memory/0x005b3940-0x005b3bba.ChatInputPane.md): its item summary still says "C++ blank under the 95+ gate" even though formal C++ is already present, but that is a sibling stale-summary cleanup rather than required ShoutInputPane incorporation. Do not lease, edit, or validate this file in the default 0001MF implementation callback. If the supervisor later authorizes sibling cleanup, the narrow fix should replace only the stale item-summary ending with wording that says first-draft C++ is populated.

No helper-page edits are required for [UID:00035S], [UID:00035R], [UID:0002VH], [UID:00041J], [UID:0003YJ], [UID:0001BH], [UID:0001HU], [UID:0000Q5], [UID:0001P0], or [UID:0000QK]. Those pages already provide enough source-facing naming and caveats for this first-draft target C++. They should be cited, not churned, unless an implementation edit needs to add a narrow back-reference.

Manual `by-memory/-coverage-report.md` and all `-coverage-report.md` files should remain unedited. Any stale generated/manual coverage wording about `95+` is supervisor-owned or validator-generated follow-up, not a report-only edit target.

## Validator Plan For Implementation

After the implementation callback edits only the leased files, run scoped validators from `source-3/project-documentation` for every changed by-* file. Minimum expected commands if only the required target/support pages are touched:

> Executable block R001 was removed from this report and preserved verbatim in [0001MF-ShoutInputPane-source-quality-removed.md](0001MF-ShoutInputPane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Add these only if those pages are edited:

> Executable block R002 was removed from this report and preserved verbatim in [0001MF-ShoutInputPane-source-quality-removed.md](0001MF-ShoutInputPane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Do not run the ChatInputPane validator for this callback unless the supervisor explicitly adds [UID:0001MC] sibling cleanup to the accepted implementation scope.

Implementation callback validator proof:

| File | Command | Timestamp | Exit | Result / warnings | Generated-refresh observation |
| --- | --- | --- | ---: | --- | --- |
| `by-memory/0x005b4260-0x005b43bc.ShoutInputPane.md` | `000000002414` | `2026-06-26T05:05:56-04:00` | `0` | `ok: 1`; validator recorded completion `90`, confidence `91`, canonical owner `0000D5`, registry/hash updates, and one header-blank insertion. | `generated_refresh: deferred`; queue later had no queued/processing refresh jobs. |
| `by-class/ShoutInputPane.md` | `000000002415` | `2026-06-26T05:06:05-04:00` | `0` | `ok: 1`; reference index added [UID:0003JS]. | `generated_refresh: deferred`; queue later had no queued/processing refresh jobs. |
| `by-file/SayInputPanes.md` | `000000002416` | `2026-06-26T05:06:14-04:00` | `0` | `ok: 1`; pre-existing missing-reference diagnostics remain for older unregistered/stale links (`0003JM`, `000401`-`000406`, `0003JQ`, `0003JR`, old `0001ME` path, old `0002S8` path). | `generated_refresh: deferred`; queue later had no queued/processing refresh jobs. |
| `by-memory/0x00630a6c-0x00630a78.ShoutPromptString.md` | `000000002417` | `2026-06-26T05:06:26-04:00` | `0` | `ok: 1`; pre-existing missing-reference diagnostic remains for unregistered [UID:0003J3]. | `generated_refresh: deferred`; queue later had no queued/processing refresh jobs. |

Validator queue status `000000002419` at `2026-06-26T05:07:06-04:00` reported worker running, queued jobs `0`, processing jobs `0`, queued generated refresh jobs `0`, and processing generated refresh jobs `0`.

## Implementation Checklist

- [x] Lease [UID:0001MF] `by-memory/0x005b4260-0x005b43bc.ShoutInputPane.md` immediately before editing; if another active lease blocks it, stop and report `PAUSED_LEASE_CONFLICT`. Proof: `current_leases.md` showed no active leases before editing; `python .\tools\leaser\leaser.py Agent-B014 lease ...` returned `Success` for the target and three accepted support files.
- [x] Edit [UID:0001MF]: set `COMPLETION:90`, `CONFIDENCE:91`, leave owner/emitter as `0000D5`, replace the target formal `RECONSTRUCTION_CPP CODE` marker/block with the exact three-marker block content from this report, replace the item summary, and update status/reconstruction notes with current MCP proof. Proof: target header now shows `90/91`, owner/emitter `0000D5`, exact `void ShoutInputPane::OnSubmitInput()` formal block, and the recommended item summary; validator `000000002414` exited `0` with `ok: 1`.
- [x] Edit [UID:0001MF] body: document vtable-only xref `0x0062fd48 -> 0x005b4260`, no direct callers, `0x005b43bc-0x005b43c0` padding, no merge with raw constructor [UID:0002SA], opcode `0x0e` subtype `1`, send gate value `2`, no post-copy empty-string branch, and `void` submit rationale from the accepted Say submit child. Proof: target `IDA MCP Evidence`, `Behavior Evidence`, `Reconstruction Notes`, `Score Rationale`, and `Changes` sections now carry those facts, including current session `80de0a67`, no direct callers, no post-copy empty branch, and the `void` rationale.
- [x] Lease and update [UID:0000D5] `by-class/ShoutInputPane.md`: remove the submit-method/helper/global naming blocker, mark `OnSubmitInput` as first-draft populated on the exact child, and keep class-level C++ blank because executable bodies live on by-memory children. Proof: method row now links [UID:0001MF] and says first-draft populated; reconstruction notes say exact constructor and submit children emit while class-level C++ remains blank; validator `000000002415` exited `0` with `ok: 1`.
- [x] Lease and update [UID:0000N9] `by-file/SayInputPanes.md`: refresh the ShoutInputPane row/change log so it states that the raw constructor and submit child now emit first-draft C++ through the `ShoutInputPane` route. Proof: `ShoutInputPane` proposed-content row and 2026-06-26 boundary/change notes now state both children emit first-draft C++; validator `000000002416` exited `0` with `ok: 1` and retained only pre-existing missing-reference diagnostics.
- [x] Check [UID:0003JS] `by-memory/0x00630a6c-0x00630a78.ShoutPromptString.md`; edit only if a narrow one-sentence submit-status sync is needed, leaving its C++ blank because it is a literal-data page. Proof: added one submit-status sync sentence and a 2026-06-26 change note; formal C++ remains blank; validator `000000002417` exited `0` with `ok: 1` and retained only pre-existing [UID:0003J3] missing-reference diagnostics.
- [x] Exclude [UID:0001MC] `by-memory/0x005b3940-0x005b3bba.ChatInputPane.md` from the default callback; do not lease/edit/validate this sibling stale-summary cleanup unless the supervisor explicitly adds it to the accepted implementation scope. Proof: no B014 lease was taken for [UID:0001MC], no ChatInputPane validator was run, and this callback made no ChatInputPane edit.
- [x] Do not edit generated files, project-level generated files, validator/tool state, IDA DB, `by-memory/-coverage-report.md`, or any `-coverage-report.md`. Proof: no manual edits were made to those files and no IDA mutation tools were used. Scoped validator commands reported validator-owned `projected_stats_update`, `autogen_registry_update`, and deferred generated refresh side effects; these are recorded above. Manual coverage-report diffs caused by the validator batch were reverted, and final git status for `by-memory/-coverage-report.md`, `by-class/-coverage-report.md`, and `by-file/-coverage-report.md` is clean.
- [x] Run the scoped validator command for each changed by-* file from `source-3/project-documentation`; record command ids, timestamps, exit status, ok counts, and generated-refresh observations in this report. Proof: commands `000000002414`, `000000002415`, `000000002416`, and `000000002417` all exited `0` with `ok: 1`; queue status `000000002419` showed no queued or processing refresh jobs.
- [x] Release every B014 lease immediately after the edit/validator batch; record lease-release proof and confirm no active B014 leases remain. Proof: `python .\tools\leaser\leaser.py Agent-B014 unlease ...` returned `Success` for all four leased by-* files; `tools/leaser/Agents/current_leases.md` immediately after release reported `No active leases`, and the final recheck shows only unrelated Agent-B006 leases with no active B014 leases.
- [x] Update this implementation checklist with checked items and short file/section proof only after the accepted implementation callback is complete. Proof: this checklist is now checked with target/support section proof, validator command proof, generated-refresh observations, explicit [UID:0001MC] exclusion, and lease release proof.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B014","command_id":"000000004165","destination_path":"executed-b-agent-research/B014/0001MF-ShoutInputPane-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B014/research/0001MF-ShoutInputPane-source-quality.md","timestamp":"2026-06-26T05:19:51","uid":"0001MF"} -->
<!-- {"agent":"B014","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001MF-ShoutInputPane-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B014/0001MF-ShoutInputPane-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001MF"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
