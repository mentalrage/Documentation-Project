** TARGET-REPORT-UID:00021G **
** AUTHOR-AGENT-ID:B012 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00021G SendClanJoinListSelectionPacket Source-Quality Research

## Finalized Report / Current Recommendation
- Current recommendation: update [UID:00021G] to source-facing `ClanStatusPane::SendClanJoinListSelectionPacket(const wchar_t *selectedRowText)`, emitted through the Clan status pane route into `NexusTK/social/Clan.cpp`.
- Final disposition: no split required. Keep the exact range `0x00485590-0x00485682`, keep `RECONSTRUCTABLE:TRUE`, change the direct semantic owner from file-level [UID:0000I8][Clan](../../../../../by-file/Clan.md) to [UID:00002K][ClanStatusPane](../../../../../by-class/ClanStatusPane.md), and route emission through [UID:00002K] so the generated chain still surfaces in `social/Clan.cpp`.
- Required action: replace stale no-code text, populate first-draft C++, update the selected-row support call shape if this method recommendation is accepted, and apply the exact supervisor-owned coverage row below. Do not edit `by-memory/-coverage-report.md` directly from this B report.
- Confidence: high for behavior, packet layout, callers, helper/global names, and code readiness; medium-high for original source declaration spelling because no debug symbol proves the exact name.

## Supporting Research

## Target
- Target UID: `00021G`
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00485590-0x00485682.SendClanJoinListSelectionPacket.md`
- Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B012\research\00021G-SendClanJoinListSelectionPacket-source-quality.md`
- Source queue/report row: reconstructable low-score by-memory row with unresolved helper/signature, packet length, ownership, coverage, and first-draft C++ questions.
- Current supervisor classification: B-preferred source-quality and heuristic/inference pass.
- Current scores and parent state: `COMPLETION:84`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000I8`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000I8`, blank C++.
- Recommended parent gate state: [UID:00002K] `ClanStatusPane` is currently `COMPLETION:85`, `CONFIDENCE:86`, `CANONICAL_OWNER:0000I8`, `EMITTER_UIDS:0000I8`, so it clears the active direct-owner/emitter gate and surfaces to `NexusTK/social/Clan.cpp`.

## Executive Recommendation
- Best direct owner: [UID:00002K] `ClanStatusPane`.
- Source placement: generated output still belongs in `NexusTK/social/Clan.cpp`; this is a class/member ownership correction, not a move out of the Clan source file.
- Best source-facing signature: `int ClanStatusPane::SendClanJoinListSelectionPacket(const wchar_t *selectedRowText)`.
- Best descriptive name: `SendClanJoinListSelectionPacket`. It is inferred/descriptive rather than symbol-proven, but it matches the outbound opcode family and sibling `SendClanJoinListRefreshPacket`.
- Selected-row ownership: the `const wchar_t *` argument is owned by inherited `ListPane` row storage in the caller object (`ClanJoinListPane`). The packet helper does not own, copy beyond the packet conversion, or free that row text.
- Metadata recommendation: raise to `COMPLETION:88`, `CONFIDENCE:91`, set `CANONICAL_OWNER:00002K`, keep `RECONSTRUCTABLE:TRUE`, set `EMITTER_UIDS:00002K`, and populate `RECONSTRUCTION_CPP CODE`.

## Supervisor Active Recheck
- The active supervisor assignment is [UID:00021G] `SendClanJoinListSelectionPacket`, with required focus on helper/signature, selected-row ownership, `WideCharToMultiByte`, one-byte converted-length and packet-length guards, non-sent terminators, packet/global names, opcode/subtype/action direction, Clan file versus dialog/list-pane ownership, support/coverage text, score/metadata, and first-draft C++.
- The target does not require split repair. It is one modeled function with exact half-open bounds `0x00485590-0x00485682`; adjacent padding starts at `0x00485682` and the next helper starts at `0x00485690`.
- The report is intentionally report-only. No by-memory, by-class, by-file, generated, or coverage files were edited.

## Inference Research Guidance Check
- `by-structure.md` separates direct semantic ownership from generated output routing. That rule is decisive here: the code is emitted through Clan, but both live callers set `ECX = g_pClanStatusPane` before the call, so the narrowest true owner is `ClanStatusPane`, not the broader `Clan` file and not the `ClanJoinListPane` caller.
- The active reconstruction gate is `RECONSTRUCTABLE:TRUE`, confirmed nonblank emitter route, and `(COMPLETION + CONFIDENCE) / 2 > 85`. The current `84/90` average is already `87`; the recommended `88/91` average is `89.5`. The stale target note saying C++ is blank because of an old `95/95` gate should be removed or replaced.
- `inference_research.md` cautions that original source file names and declarations usually cannot be proven without debug metadata. I therefore separate IDA facts from descriptive source names. The member-method recommendation is an inference, but it is supported by two independent call sites and by sibling Clan selected-row helper patterns.

## Heuristic / Inference Reanalysis And Validation
- Helper name/signature:
  - Evidence checked: target decompilation, exact `retn 4`, two callers at `0x004888ea` and `0x00488951`, caller assembly notes showing `MOV ECX, g_pClanStatusPane` before `CALL 0x00485590`, and sibling selected-row senders in the subtype-6 helper strip.
  - Best inference: `int ClanStatusPane::SendClanJoinListSelectionPacket(const wchar_t *selectedRowText)`.
  - Rejected alternatives: plain `int __stdcall SendClanJoinListSelectionPacket(const wchar_t *)` because it explains the callee body but discards the deliberate `ECX` receiver setup at both callers; `int SendClanJoinListSelectionPacket(ClanStatusPane *, const wchar_t *)` because it preserves the route but does not match the observed `thiscall`-style call shape; `ClanJoinListPane::Send...` because the caller list pane supplies row text but does not act as receiver.
  - Impact: this resolves the previous final-source signature blocker and justifies class owner/routing through `ClanStatusPane`.
- Selected-row argument ownership:
  - Evidence checked: [UID:0002NR] `0x004888d0` reads selected index at inherited `ListPane +0x134`, calls `ListPane::GetSelectedEntry` at `0x004f3dc0`, then calls this helper; [UID:00021U] `0x00488900` repeats the same selected-entry path on Enter.
  - Best inference: `selectedRowText` is a borrowed pointer to the selected list row text. It should be typed `const wchar_t *`; the helper converts it immediately and never stores or frees it.
  - Rejected alternatives: heap-owned string transfer, mutable output buffer, or `ClanStatusPane` field read. The callee reads only the pointer argument and local buffers.
- `WideCharToMultiByte` length/count policy:
  - Evidence checked: target page records the manual length loop and `movsx eax, bl`; exported decompilation shows `WideCharToMultiByte(0, 0, lpWideCharStr, count, MultiByteStr, 256, 0, 0)`.
  - Best inference: source draft should preserve the observed signed low-byte character count with `static_cast<signed char>(wcslen(selectedRowText))`, and use `CP_ACP` for Windows code page `0`.
  - Rejected alternatives: passing `-1` to include the terminator, sending a Unicode string, or silently simplifying to full `wcslen` in the first-draft source. Sibling clan submitters often decompile as full `wcslen`, but this target's recorded instruction width is narrower and should be preserved until a coordinated clan packet helper audit proves otherwise.
  - Impact: no blocker. The chosen code mirrors the binary while making the width caveat visible.
- Converted-length and packet-length guards:
  - Evidence checked: target decompilation and current page behavior. The converted byte count is checked against `0x100`, written as one byte at packet offset `3`, and `convertedLength + 4` is checked against the `0x80` local packet buffer.
  - Best inference: keep both guards. The first protects the one-byte length field and `convertedName[256]`; the second protects the `packet[128]` stack buffer.
  - Rejected alternatives: treating the `0x100` guard as packet capacity, or treating the `0x80` guard as protocol maximum unrelated to the local buffer. Both are local safety checks visible in the stack layout.
- Non-sent terminator behavior:
  - Evidence checked: target decompilation writes `convertedName[convertedLength] = 0` and later `packet[packetLength] = 0`, but `QueueAndSendPacket` receives exactly `packetLength`.
  - Best inference: both terminators are local scratch NUL writes. The protocol field is length-prefixed bytes only; no trailing NUL is sent.
  - Rejected alternatives: adding `+1` to the sent length, documenting a NUL-terminated packet string, or omitting the scratch writes from the source draft. The packet draft should retain the local terminator for binary-like stack behavior.
- Packet helper/global names:
  - Evidence checked: [UID:0003YJ] names `0x00575380` as `PacketBufferWriteUInt8`; [UID:0001BH] names `0x00516220` as `memmove` wrapper; [UID:0001HU] names `0x00574bb0` as `QueueAndSendPacket`; [UID:0001P0] names `0x0067a7ec` as `Socket *g_packetSender`.
  - Best inference: source draft should use `PacketBufferWriteUInt8(packet + offset, value)`, `memmove`, and `g_packetSender->QueueAndSendPacket(packet, static_cast<short>(packetLength))`.
  - Rejected alternatives: raw `sub_575380`, `sub_516220`, `sub_574BB0`, or `dword_67A7EC` names. They are generated/decompiler names and are resolved by existing support docs.
- Opcode/subtype/action direction:
  - Evidence checked: target sends `{0x4b, 2, 1}`; [UID:00021F] sends `{0x4b, 2, 0}` as join-list refresh/request; [UID:00010H] row `3` sends subtype `2` action `0`; [UID:00021S] inbound opcode `0x43` subtype `2` populates the join-list child.
  - Best inference: outbound opcode `0x4b` is a clan request/action packet; subtype `2` is the join-list family; action `0` requests or refreshes the join list; action `1` submits the selected join-list row. Inbound opcode `0x43` subtype `2` is the server response/update path and should not be confused with this outbound sender.
  - Rejected alternatives: naming subtype `2` as status attributes, enlist list, or inbound list update. Those collide with sibling action/request docs and the inbound dispatcher evidence.
- Clan file versus dialog/list-pane ownership:
  - Evidence checked: [UID:0000I8] `Clan` lists the helper strip under `social/Clan.cpp`; [UID:00002K] `ClanStatusPane` is the main clan UI and owns child panes and packet handling; both callers explicitly load `g_pClanStatusPane`; [UID:00002H] `ClanJoinListPane` owns the row selection action but only supplies the selected text.
  - Best inference: direct semantic owner should be `ClanStatusPane`; generated output still routes to `Clan.cpp`. The target is not dialog-owned and not list-pane-owned.
  - Rejected alternatives: keep `CANONICAL_OWNER:0000I8` as the final direct owner because it is broader than the live receiver; attach to `ClanJoinListPane` because it is only a caller/data source; attach to an input dialog because no dialog participates in this call path; attach to PacketBuffer/Socket because those are callee utilities, not feature owners.
  - Impact: recommend metadata owner/emitter change and support-doc call-shape update.
- First-draft C++ readiness:
  - Evidence checked: target current score, active code gate, exact range, dependency names, sibling accepted clan submitter source style, and non-sent terminator/guard behavior.
  - Best inference: populate final `RECONSTRUCTION_CPP CODE` now. No no-code proof remains.
  - Rejected alternatives: leaving blank under the old `95/95` wording, or waiting for perfect original enum names. The draft uses descriptive constants and preserves exact behavior; unresolved original enum spelling does not block the active gate.
- Generated-output pollution/support changes:
  - Evidence checked: [UID:0002NR] currently drafts `return SendClanJoinListSelectionPacket(g_pClanStatusPane, selectedName);`; [UID:0000I8] line item still describes the target as a file helper; current coverage row says `packet helper | SendClanJoinListSelectionPacket`.
  - Best inference: update support text to describe a `ClanStatusPane` receiver method emitted through `Clan.cpp`. If the supervisor elects to keep a file-level helper strip for consistency, it should explicitly document that as a source-generation convenience and not as the exact ABI/source-owner inference.
  - Remaining blocker: none for this target. A broader pass may choose to normalize sibling helper strips, but [UID:00021G] has enough caller evidence to resolve its own source shape.

## Evidence Standards Used
- IDA facts used: function range, return convention, decompilation observations, callee list, two caller addresses, caller register setup from existing docs, and adjacent padding/next-function boundary.
- Documentation evidence used: target page, [UID:0002NR] selected-row action, [UID:00021U] list-pane input handlers, [UID:000194] `ListPane`, [UID:00002K] `ClanStatusPane`, [UID:00002H] `ClanJoinListPane`, [UID:0000I8] `Clan`, [UID:00021F] join-list refresh, [UID:00010H] row-action sender, [UID:00021S] inbound dispatcher/dialog handlers, PacketBuffer/memmove/QueueAndSendPacket/global docs, and prior B-agent clan submitter source-quality reports.
- Negative evidence used: no callee read of `ECX`, no heap/string ownership transfer, no dialog path in the caller chain, no inbound opcode use in this outbound sender, and no reason to include local NUL bytes in the sent length.
- Live IDA MCP note: the MCP endpoint was unavailable in this session after retry attempts to `127.0.0.1:13337/mcp`, so this report uses the target's recorded live IDA evidence, readonly exported function facts already captured in the workspace, and current project documentation. This limits final confidence below `95`, but it does not block the source-quality recommendation because the critical caller/callee facts are already documented and internally consistent.

## IDA MCP Facts
- Function/range facts: IDA models `sub_485590` at `0x00485590`, size `0xf2`, ending at `0x00485682`; the function returns with `retn 4`.
- Decompilation facts: the body writes bytes `0x4b`, `2`, and `1`; computes a wide-character count; calls `WideCharToMultiByte(0, 0, selectedRowText, count, convertedName, 256, NULL, NULL)`; checks `convertedLength < 0x100`; writes one-byte length; copies `convertedLength` bytes to packet offset `4`; checks `convertedLength + 4 < 0x80`; writes a local packet terminator; and sends exactly `convertedLength + 4` bytes.
- Xref facts: only two code refs are documented: `0x004888ea` in `ClanJoinListPane` selected-row action and `0x00488951` in `ClanJoinListPane` key/event handler.
- Callee facts: dependencies include `sub_516030`, `sub_575380`, `WideCharToMultiByte`, `sub_516220`, `sub_574BB0`, security-cookie support, and range-check failure.
- Receiver facts: both caller paths load `g_pClanStatusPane` from `0x0067ade4` into `ECX` before the call. The callee body does not dereference `ECX`, which is why decompilers can model the function as `__stdcall(LPCWSTR)`, but the call-site ABI evidence favors a `ClanStatusPane` receiver method.
- Boundary facts: `0x00485682-0x00485690` is alignment padding before the next clan helper at `0x00485690`.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00485590-0x00485682` | [UID:00021G](../../../../../by-memory/0x00485590-0x00485682.SendClanJoinListSelectionPacket.md) | Sends outbound clan join-list selected-row packet `{0x4b, 2, 1, len, payload}` | `TRUE` | Recommend [UID:00002K] `ClanStatusPane` | Recommend `88/91` | Populate first-draft C++ |
| `0x00485520-0x00485588` | [UID:00021F](../../../../../by-memory/0x00485520-0x00485588.SendClanJoinListRefreshPacket.md) | Sibling subtype-2 action-0 join-list refresh/request sender | `TRUE` | Existing Clan route | Already documented | Protocol sibling only |
| `0x004888d0-0x004888f1` | [UID:0002NR](../../../../../by-memory/0x004888d0-0x004888f1.ClanJoinListPaneSelectedRowAction.md) | Selected-row action caller that supplies row text | `TRUE` | `ClanJoinListPane` | `87/91` current doc | Support call shape should be updated if method owner accepted |
| `0x00488900-0x00488b3d` | [UID:00021U](../../../../../by-memory/0x00488900-0x00488b3d.ClanListPaneInputHandlers.md) | Enter-key caller for join/enlist list panes | `TRUE` | Clan list pane handlers | Current doc supports call path | Evidence/support only |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004888ea` | caller in `ClanJoinListPaneSelectedRowAction` | Nonnegative selected row is fetched through `ListPane::GetSelectedEntry`, `ECX` is set to `g_pClanStatusPane`, and selected text is passed to target. |
| `0x00488951` | caller in `ClanListPaneInputHandlers` | Enter-key path repeats the selected-row lookup and calls the target with `g_pClanStatusPane` as receiver. |
| `0x00575380` | callee `PacketBufferWriteUInt8` | Writes opcode, subtype, action, and converted-length bytes into local packet buffer. |
| `0x00516220` | callee memmove wrapper | Copies converted payload bytes into packet offset `4`. |
| `0x00574bb0` | callee `QueueAndSendPacket` | Queues/sends the counted packet bytes through `Socket *g_packetSender`. |
| `0x0067a7ec` | global `g_packetSender` | Socket sender used by final send. |
| `0x0067ade4` | global `g_pClanStatusPane` | Receiver loaded by both callers before the target call. |

## Documentation Evidence And IDA Status
- Existing target doc already captures exact range, packet layout, non-sent local terminator, conversion/length guards, two callers, and current file-level Clan attachment.
- [UID:0002NR] selected-row action proves the row text source and currently uses a two-argument helper draft. That draft should be revised to `return g_pClanStatusPane->SendClanJoinListSelectionPacket(selectedName);` if the method-source recommendation is accepted.
- [UID:00021U] proves the Enter-key caller and shows the same clan singleton receiver setup pattern for join and enlist list senders.
- [UID:0000I8] `Clan` correctly places the code in `social/Clan.cpp`, but its current row leaves open whether packet helpers should be file-local or member-attached. For this target, live caller receiver evidence resolves the direct owner as `ClanStatusPane`.
- [UID:00002K] `ClanStatusPane` is the main status UI, owns the child panes, and is the singleton receiver for packet handling. It is above the active ownership/code gate.
- Current target C++ blocker text is stale because it cites the previous `95/95` final-source gate. Under the active gate and current evidence, C++ should be populated.

## Ranked Ownership Analysis

### 1. ClanStatusPane method
- Evidence for: both callers load `g_pClanStatusPane` into `ECX` before the call; target returns with one stack argument (`retn 4`); the helper belongs to the Clan status/join-list UI flow; `ClanStatusPane` owns the child list panes and packet dispatcher; generated output still surfaces through `Clan.cpp`.
- Evidence against: the callee body does not dereference `this`, so decompilers label it `__stdcall(LPCWSTR)`; existing docs currently list the helper under file-level Clan.
- Decision: accepted as the best direct semantic owner/source shape. Unused `this` is common enough for short member send helpers and is better than discarding the deliberate call-site receiver.

### 2. Clan.cpp file-local helper
- Evidence for: [UID:0000I8] lists the contiguous opcode `0x4b` helper strip in `social/Clan.cpp`; several adjacent raw helpers have no obvious class state reads; a file-local helper would keep sibling helper organization simple.
- Evidence against: a plain file helper does not explain the two caller-site `ECX = g_pClanStatusPane` setup unless modeled as a nonstandard helper with an unused first receiver parameter. `by-structure.md` says direct owner should be the narrowest true owner, not merely the final source-file root.
- Decision: rejected as direct owner for [UID:00021G], but retained as the generated source file context through `ClanStatusPane`.

### 3. ClanJoinListPane method
- Evidence for: both live callers are in `ClanJoinListPane` behavior and the selected text originates from its inherited row storage.
- Evidence against: callers explicitly replace `ECX` with `g_pClanStatusPane` before calling the packet helper; the callee is not called as a method on the list pane; row storage is only input data, not owner context.
- Decision: rejected as target owner. Keep [UID:0002NR] and [UID:00021U] as caller/support owners only.

### 4. Dialog, PacketBuffer, Socket, or protocol-only owner
- Evidence for: the helper uses packet buffer and socket utilities; it participates in a protocol packet family.
- Evidence against: no dialog object is on the path; PacketBuffer and Socket are utilities, not the clan feature owner; protocol-only ownership would lose UI receiver and Clan source placement.
- Decision: rejected.

## Negative Evidence Summary
- No callee state read from `ClanJoinListPane`, no member-field dependency on the selected-row caller, and no dialog allocation/control access are present.
- No evidence supports sending the local string or packet terminator bytes. The counted send length excludes them.
- No evidence supports an inbound opcode interpretation. Opcode `0x43` subtype `2` is handled by the server-to-client dispatcher/list updater; this target is an outbound `0x4b` sender.
- No split is justified. The function is a single compact packet sender and has exact padding after its end.
- No original enum names are proven. Descriptive names `ClanPacketOpcode::Request = 0x4b`, join-list subtype `2`, and action `1` are useful in prose, but first-draft code should keep the literal bytes unless the enum family is coordinated across Clan.

## First-Draft C++ Recommendation
Populate `RECONSTRUCTION_CPP CODE` for [UID:00021G] with this source-style draft:

```cpp
int ClanStatusPane::SendClanJoinListSelectionPacket(const wchar_t *selectedRowText)
{
    char convertedName[256];
    unsigned char packet[128];

    PacketBufferWriteUInt8(packet + 0, 0x4b);
    PacketBufferWriteUInt8(packet + 1, 0x02);
    PacketBufferWriteUInt8(packet + 2, 0x01);

    const int sourceCharCount =
        static_cast<signed char>(wcslen(selectedRowText));

    unsigned int convertedLength = WideCharToMultiByte(
        CP_ACP,
        0,
        selectedRowText,
        sourceCharCount,
        convertedName,
        sizeof(convertedName),
        NULL,
        NULL);
    if (convertedLength >= sizeof(convertedName)) {
        __report_rangecheckfailure();
    }

    convertedName[convertedLength] = 0;
    PacketBufferWriteUInt8(packet + 3, convertedLength);
    memmove(packet + 4, convertedName, convertedLength);

    unsigned int packetLength = convertedLength + 4;
    if (packetLength >= sizeof(packet)) {
        __report_rangecheckfailure();
    }

    packet[packetLength] = 0;
    return g_packetSender->QueueAndSendPacket(
        packet,
        static_cast<short>(packetLength));
}
```

Source-shape notes:
- The `static_cast<signed char>(wcslen(...))` preserves the recorded `movsx eax, bl` source count width. Do not replace it with plain `wcslen` in this target unless a later binary/source audit proves the current instruction-level observation was wrong.
- The local packet terminator remains outside the counted send length.
- If the supervisor declines the `ClanStatusPane` method ownership and keeps a file-local helper strip, the least-wrong fallback draft would need to document an explicit route-only `ClanStatusPane *` receiver parameter. That fallback is not the best ABI/source-owner explanation for this target.

## Exact Metadata / Support / Coverage Replacement Text
Recommended target metadata values:

```text
COMPLETION:88
CONFIDENCE:91
CANONICAL_OWNER:00002K
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00002K
RECONSTRUCTION_CPP CODE: populate with the first-draft C++ above
```

Recommended target status text replacement:

```text
- Entity kind: ClanStatusPane packet-sending member/helper
- Likely source module: [UID:0000I8][Clan](by-file/Clan.md), generated through [UID:00002K][ClanStatusPane](by-class/ClanStatusPane.md) into `NexusTK/social/Clan.cpp`
- Caller owner: [UID:00002H][ClanJoinListPane](by-class/ClanJoinListPane.md) supplies the selected row text; it is not the packet helper owner.
- Parent attachment: attach to [UID:00002K][ClanStatusPane](by-class/ClanStatusPane.md). Both live callers load `g_pClanStatusPane` into `ECX` before calling the helper, and the source-level sender is best reconstructed as a `ClanStatusPane` member with a borrowed selected-row text argument.
```

Recommended support-doc C++ call-shape replacement for [UID:0002NR] if [UID:00021G] becomes a method:

```cpp
return g_pClanStatusPane->SendClanJoinListSelectionPacket(selectedName);
```

Exact replacement row for `by-memory/-coverage-report.md` line currently containing [UID:00021G] (supervisor-owned; B012 did not edit it):

```text
    - [UID:00021G][0x00485590-0x00485682.SendClanJoinListSelectionPacket](by-memory/0x00485590-0x00485682.SendClanJoinListSelectionPacket.md) 0x00485590-0x00485682 | packet helper/method | ClanStatusPane::SendClanJoinListSelectionPacket : reconstructable : 88% : very strong : B012 2026-06-19 source-quality reanalysis resolves the live subtype-2 action-1 join-list selection sender as a ClanStatusPane receiver helper emitted through social/Clan.cpp, with selected text owned by ClanJoinListPane row storage, caller `ECX = g_pClanStatusPane` receiver setup at both call sites, opcode `0x4b` subtype `2` action `1`, CP_ACP WideCharToMultiByte conversion using the observed signed-byte source character count, one-byte converted-length and `<0x80` packet-length guards, local-only non-sent terminators, PacketBufferWriteUInt8/memmove/QueueAndSendPacket through `Socket *g_packetSender`, and first-draft C++ readiness.
```

## Final Recommendation
- Apply the metadata change from `84/90` file-owned helper to `88/91` `ClanStatusPane` member/helper.
- Populate first-draft C++ using the method source above.
- Update support docs that currently model this as `SendClanJoinListSelectionPacket(g_pClanStatusPane, selectedName)` if the method owner recommendation is accepted.
- Keep `social/Clan.cpp` as the source file route. Do not move this to a dialog file, list-pane file, PacketBuffer, Socket, or protocol-only module.
- Do not split or rename the memory file; the current range and filename are serviceable. The title can remain `SendClanJoinListSelectionPacket` even if the source method is `ClanStatusPane::SendClanJoinListSelectionPacket`.

## Follow-Up Actions
- Supervisor action: incorporate this report into the target by-memory page, update [UID:0002NR] call-shape support if adopting the method recommendation, and apply the exact coverage row during supervisor-owned coverage maintenance.
- A-agent action: when editing support docs, preserve the distinction between selected-row ownership (`ClanJoinListPane`/`ListPane`) and packet sender ownership (`ClanStatusPane`).
- B012 future research action: none required for [UID:00021G]. A later family pass may normalize sibling Clan packet-helper strips, but this target is code-ready now.

## Confidence
- Recommendation confidence: high. The main inference is source declaration shape, and the two live caller receiver setups are strong enough to choose a method owner.
- Score confidence: `88/91` is justified by exact range, behavior, packet layout, dependencies, ownership inference, and C++ readiness. It stays below `95` because exact original enum names and original source declaration spelling remain descriptive rather than symbol-proven, and live MCP was not reachable during this report write.
- Remaining uncertainty: only original spelling/enum naming. That uncertainty does not block owner/emitter assignment or first-draft C++.

## Validator Results
- Commands run: none. This was a report-only B-agent assignment; no by-* documentation, coverage, generated, or project-level files were modified.
- Read checks run: `Test-Path` for the report path, current target page read, current coverage row grep, and support-doc greps for source/owner/caller evidence.
- MCP status: direct live MCP endpoint was unavailable in this session; current docs already preserve prior live IDA MCP facts needed for this pass.
- Unresolved validator warnings/errors: none introduced.

## Changed Files
- Created: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B012\research\00021G-SendClanJoinListSelectionPacket-source-quality.md`
- Modified: none outside Agent-B012 research.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B012","command_id":"000000004165","destination_path":"executed-b-agent-research/B012/00021G-SendClanJoinListSelectionPacket-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:35","uid":"00021G"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
