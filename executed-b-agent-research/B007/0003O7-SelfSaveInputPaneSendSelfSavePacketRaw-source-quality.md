** TARGET-REPORT-UID:0003O7 **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003O7 **
# 0003O7 SelfSaveInputPaneSendSelfSavePacketRaw Source-Quality Report

Assignment: B007 source-quality / heuristic reanalysis for [UID:0003O7].

Status: FINISHED, report-only. I did not edit `by-*` documentation, generated source, IDA state, or `by-memory/-coverage-report.md`.

## Current Recommendation

- Keep [UID:0003O7] as source-authored NexusTK packet helper code, not compiler glue and not padding.
- Correct the exact half-open range from `0x005b6870-0x005b68b0` to `0x005b6870-0x005b68b1`. The byte at `0x005b68b0` is the helper's `ret`, not alignment. The following alignment is `0x005b68b1-0x005b68c0`.
- Keep the helper reconstructable and source-bearing, but preserve the no-route caveat. Fresh PE scanning found no rel32 call/jump, absolute VA pointer, RVA pointer, raw-offset pointer, or pointer to any byte in the target range.
- Keep immediate semantic owner/emitter as [UID:0000CW][SelfSaveInputPane](by-class/SelfSaveInputPane.md) for this target because the helper is class-specific SelfSave prompt behavior split from the SelfSave method island. Source placement should be described as a private/file-local helper in the `SelfSaveInputPane` source module, with final consolidation to [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md) only as a coordinated family move.
- Best source-facing helper name: `SendSelfSavePacket`.
- Best source-facing signature: `static void SendSelfSavePacket()` as a file-local helper. A non-static `SelfSaveInputPane::SendSelfSavePacket()` is a weaker alternative because the body has no `this` read, no stack arguments, and no class-field access.
- Opcode `0x25` is the self-save confirmation request packet. The helper writes exactly one transmitted byte and clears a scratch terminator byte that is not sent.
- Raise target metadata from `85/86` to `87/88` after implementation. The behavior, corrected range, packet writer/send helpers, owner context, and first-draft C++ are now clear; confidence remains capped by the lack of any ordinary liveness route and by final `SelfSaveInputPane.cpp` versus `CommandInputPanes.cpp` source grouping.
- First-draft C++ is appropriate and ready, with the no-route caveat retained in prose:

```cpp
namespace {
const unsigned char kSelfSavePacketOpcode = 0x25;

static void SendSelfSavePacket()
{
    char packet[2];

    PacketBufferWriteUInt8(static_cast<char>(kSelfSavePacketOpcode), packet);
    packet[1] = 0;

    QueueAndSendPacket(g_packetSender, packet, 1);
}
}
```

If supervisor policy rejects formal emission for retained no-route helpers, keep the target C++ block blank but include this draft in prose and state the exact defer proof: no ordinary route to `0x005b6870` is known, and the active virtual handler already sends opcode `0x25` inline.

## Target

- Target UID: `0003O7`
- Current target path: `source-3/project-documentation/by-memory/0x005b6870-0x005b68b0.SelfSaveInputPaneSendSelfSavePacketRaw.md`
- Recommended target path after implementation: `source-3/project-documentation/by-memory/0x005b6870-0x005b68b1.SelfSaveInputPaneSendSelfSavePacketRaw.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B007/research/0003O7-SelfSaveInputPaneSendSelfSavePacketRaw-source-quality.md`
- Current metadata: `COMPLETION:85`, `CONFIDENCE:86`, `CANONICAL_OWNER:0000CW`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CW`, blank formal C++.
- Current generated output route: `auto-generated/NexusTK/ui/dialogs/SelfSaveInputPane.cpp`.

## Evidence Checked

Instructions and workflow:

- `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B007/goal.md`

Target and direct support docs:

- [UID:0003O7][0x005b6870-0x005b68b0.SelfSaveInputPaneSendSelfSavePacketRaw](by-memory/0x005b6870-0x005b68b0.SelfSaveInputPaneSendSelfSavePacketRaw.md)
- [UID:0001MU][0x005b67c0-0x005b68b0.SelfSaveInputPane](by-memory/0x005b67c0-0x005b68b0.SelfSaveInputPane.md)
- [UID:0003O5][0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw](by-memory/0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw.md)
- [UID:0003O6][0x005b6800-0x005b686c.SelfSaveInputPaneConfirmInput](by-memory/0x005b6800-0x005b686c.SelfSaveInputPaneConfirmInput.md)
- [UID:0001KQ][0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory](by-memory/0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory.md)
- [UID:0002N8][0x006305c0-0x00630648.SelfSaveInputPaneVtableData](by-memory/0x006305c0-0x00630648.SelfSaveInputPaneVtableData.md)
- [UID:0003HM][SelfSaveInputPaneVtables](by-type/by-vtable/SelfSaveInputPaneVtables.md)
- [UID:0000CW][SelfSaveInputPane](by-class/SelfSaveInputPane.md)
- [UID:0000NM][SelfSaveInputPane](by-file/SelfSaveInputPane.md)
- [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md)
- [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md)
- [UID:0002RY][0x005b6c30-0x005b6c7c.SendBlockListenModePacket](by-memory/0x005b6c30-0x005b6c7c.SendBlockListenModePacket.md)
- [UID:0002S0][0x005b7010-0x005b70f7.SendAddBlockListenPacket](by-memory/0x005b7010-0x005b70f7.SendAddBlockListenPacket.md)
- [UID:0002RZ][0x005b7360-0x005b7447.SendDeleteBlockListenPacket](by-memory/0x005b7360-0x005b7447.SendDeleteBlockListenPacket.md)
- [UID:0002YP][0x005b6760-0x005b67c0.SendWearPacket](by-memory/0x005b6760-0x005b67c0.SendWearPacket.md)
- [UID:0001MK][0x005b5630-0x005b5890.PostInputPane](by-memory/0x005b5630-0x005b5890.PostInputPane.md)
- [UID:0002S6][0x005b3410-0x005b3485.ChangeSpellSlotPacketRawSender](by-memory/0x005b3410-0x005b3485.ChangeSpellSlotPacketRawSender.md)
- [UID:0002S8][0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw](by-memory/0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw.md)
- [UID:0003VS][0x00553350-0x00553495.TextDialogUnreferencedSubmitPacketRaw](by-memory/0x00553350-0x00553495.TextDialogUnreferencedSubmitPacketRaw.md)
- [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md)
- [UID:0003YJ][0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers](by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)
- [UID:0001P0][0x0067a7ec-0x0067a7f0.g_packetSender](by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md)
- `source-3/project-documentation/by-memory/-coverage-report.md`
- `source-3/project-documentation/by-memory/-ignored.md`
- `source-3/project-documentation/project-level/-auto-completion-stats.md`

Prior report used as a lead, with independent recheck for this target:

- `source-3/project-documentation/tools/leaser/Agents/Agent-B012/research/0001KQ-SelfSaveInputPaneFactory-source-quality.md`

Local binary evidence:

- Fresh raw PE parse and scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Capstone disassembly from raw PE bytes for `0x005b6800-0x005b686c`, `0x005b6870-0x005b68b1`, and `0x005b68c0-0x005b6900`.
- Whole-image scans for rel32 calls/jumps, conditional rel32 branches, absolute VA pointers, RVA pointers, raw-offset pointers, and target-range pointers.

No live IDA MCP tool was exposed in this session. Existing target/support pages record prior live IDA MCP results; this report adds fresh PE byte, boundary, disassembly, and route-scan evidence.

## Boundary And Raw Body

Fresh PE parse:

- Image base: `0x00400000`.
- `.text`: RVA `0x1000`, VA `0x00401000`, virtual size `0x20b4ac`, raw size `0x20b600`.
- Target start `0x005b6870` maps to RVA `0x1b6870`, raw file offset `0x1b5c70`.

Corrected byte ranges:

| Range | Bytes / disassembly result | Conclusion |
| --- | --- | --- |
| `0x005b686c-0x005b6870` | `cc cc cc cc` | Four-byte alignment after the active confirm handler. |
| `0x005b6870-0x005b68b1` | Complete helper body ending with `ret` at `0x005b68b0`. | Target range must include `0x005b68b0`; current docs cut off the final byte. |
| `0x005b68b1-0x005b68c0` | Fifteen `0xcc` bytes. | Successor alignment before `BlockListenInputPane` constructor. |
| `0x005b68c0` | `push ebp; mov ebp, esp; ...` | Clean successor constructor start. |

Fresh disassembly for the corrected target:

```asm
005B6870  push    ebp
005B6871  mov     ebp, esp
005B6873  sub     esp, 14h
005B6876  mov     eax, dword ptr [672F24h]
005B687B  xor     eax, ebp
005B687D  mov     dword ptr [ebp-4], eax
005B6880  lea     eax, [ebp-14h]
005B6883  push    eax
005B6884  push    25h
005B6886  call    575380h
005B688B  mov     ecx, dword ptr [67A7ECh]
005B6891  lea     eax, [ebp-14h]
005B6894  add     esp, 8
005B6897  mov     byte ptr [ebp-13h], 0
005B689B  push    1
005B689D  push    eax
005B689E  call    574BB0h
005B68A3  mov     ecx, dword ptr [ebp-4]
005B68A6  xor     ecx, ebp
005B68A8  call    5C772Fh
005B68AD  mov     esp, ebp
005B68AF  pop     ebp
005B68B0  ret
```

This body has no stack arguments and does not read `ECX` as `this`. `ECX` is loaded only with [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) before the queue/send call.

The active vtable-routed handler [UID:0003O6] contains the same packet-send tail after it validates `y` or `Y`:

```asm
005B683A  lea     eax, [ebp-14h]
005B683D  push    eax
005B683E  push    25h
005B6840  call    575380h
005B6845  mov     ecx, dword ptr [67A7ECh]
005B684B  lea     eax, [ebp-14h]
005B684E  add     esp, 8
005B6851  mov     byte ptr [ebp-13h], 0
005B6855  push    1
005B6857  push    eax
005B6858  call    574BB0h
```

## Packet Behavior

Stable behavior:

- Writes packet opcode byte `0x25` through [UID:0003YJ][PacketBufferScalarBigEndianWriteHelpers](by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md) helper `0x00575380`, best source-facing name `PacketBufferWriteUInt8`.
- Clears `packet[1]` / `[ebp-0x13]` to zero after the byte-write helper. This is a scratch terminator/safety byte, not part of the transmitted payload.
- Reads [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) from `0x0067a7ec`.
- Calls [UID:0001HU][QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md) with packet pointer and length `1`.
- Does not read input, class fields, global feature state, localized strings, or pane state.
- Does not call the `SelfSaveInputPane` constructor or factory.

Opcode interpretation:

- `0x25` is best documented as the self-save confirmation request opcode.
- Evidence: [UID:0003O6] sends the same one-byte opcode only after one-character input equals `y` or `Y`; [UID:0003O5]/[UID:0001KQ] build the prompt whose localized id `0x26` is documented by B012 as `Save profile? (Y/N) `; this helper is adjacent to those SelfSave bodies and sends the same packet unconditionally.
- Rejected interpretations: it is not a generic packet sender, not a queue/send wrapper, not a compiler helper, and not a `SelfSaveOKPane` status pane action. The helper only writes one fixed feature opcode and touches only the shared packet sender.

## Route / Liveness Scan

Fresh whole-image PE scan results:

| Target | Result | Interpretation |
| --- | --- | --- |
| `0x005b6870` | `VA=0`, `RVA=0`, `RAW=0` pointer hits | No ordinary pointer/table route to the raw start. |
| `0x005b6870-0x005b68b1` | `0` absolute VA hits to any byte in the corrected range | No mid-function pointer route found. |
| `0x005b6870` and range | `0` rel32 call/jump/conditional branch hits | No direct code route into the helper. |
| First 32 target bytes | `1` whole-image signature hit, at the target raw offset only | No duplicate body found under another route. |
| `0x005b6800` positive control | `1` absolute VA hit at raw `0x22f008`, corresponding to vtable slot `0x00630608` | Scanner finds the known active confirm-handler vtable route. |
| `0x0067a7ec` positive control | `489` absolute VA hits | Scanner finds the known high-fanout packet-sender global references. |
| `0x005b3410` comparison no-route helper | `0` absolute VA hits | Scanner behavior matches other retained no-route raw helpers. |

Conclusion: there is no ordinary static liveness route. This should remain prominent in docs. The negative route scan does not make the target compiler glue; the body is project-specific packet-send code with exact feature adjacency and an exact active-handler duplicate tail.

## Heuristic / Inference Reanalysis And Validation

Issue: exact range and padding.

- Evidence checked: target bytes, successor bytes, Capstone disassembly, current target doc, aggregate doc, `-ignored.md`.
- Result: current `0x005b6870-0x005b68b0` range is one byte short. The final `ret` is at `0x005b68b0`; padding begins at `0x005b68b1`, not `0x005b68b0`.
- Recommendation: rename the target file and heading to `0x005b6870-0x005b68b1`, update [UID:0001MU] to end at `0x005b68b1`, and update `-ignored.md` padding to `0x005b68b1-0x005b68c0`.

Issue: raw-start route.

- Evidence checked: existing IDA no-function/no-xref notes, fresh PE rel32/VA/RVA/raw-offset scans, target-range pointer scan, positive controls.
- Result: no route found.
- Best inference: retained no-route source helper inside the SelfSave prompt family. The helper may be an unused source helper retained in the object file or an old helper whose active handler was later inlined. No evidence supports a hidden vtable, factory, or pointer-table route.
- Impact: keep no-route caveat; do not demote to compiler glue or padding.

Issue: source-facing name and signature.

- Evidence checked: raw body has no args and no `this`; neighboring raw helpers; PostInputPane source-quality precedent; B012 factory report note.
- Accepted name/signature: `static void SendSelfSavePacket()`.
- Reasoning: the body sends a fixed packet and reads no object state. File-local/static source shape is more likely than a non-static class method. The class-qualified name `SelfSaveInputPane::SendSelfSavePacket()` remains a useful audit label if IDA needs a class-specific name, but it is weaker as source C++ because no `this` behavior is present.
- Rejected names: `SelfSaveInputPaneSendSelfSavePacketRaw` is a documentation label; `SubmitSelfSavePacket` suggests input validation that this body lacks; `QueueSelfSavePacket` overstates queue ownership; `SendSaveProfilePacket` is semantically plausible but less directly tied to existing class/file names than `SendSelfSavePacket`.

Issue: owner/emitter and source placement.

- Evidence checked: target/aggregate/class/file docs, vtable docs, command-input file docs, adjacent Wear/Post/ChangeSpell raw helpers, no-route raw Chat/TextDialog pages.
- Recommendation: keep immediate canonical owner/emitter [UID:0000CW][SelfSaveInputPane](by-class/SelfSaveInputPane.md) for this target page because it is a class-specific child split from a SelfSave method island, and the class parent clears the current gate. In prose, state that the actual C++ helper should be file-local in the `SelfSaveInputPane` source module.
- Final source file route: [UID:0000NM][SelfSaveInputPane](by-file/SelfSaveInputPane.md) remains the immediate generated route. [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md) remains the likely final consolidation file, but moving only this helper would fragment the family. A future consolidation should move [UID:0000NM], [UID:0000CW], [UID:0001KQ], [UID:0003O5], [UID:0003O6], [UID:0003O7], [UID:0002N8], and [UID:0003HM] together.
- Rejected owners:
  - [UID:0000NS][Socket](by-file/Socket.md): owns `g_packetSender` lifetime and queue/send infrastructure, not feature packet construction.
  - [UID:0000Q5][g_packetSender](by-global/g_packetSender.md): shared state dependency, not source owner.
  - [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md) as immediate metadata owner: likely final module, but current SelfSave docs still route through [UID:0000NM]/[UID:0000CW].
  - [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md): successor neighborhood only; begins after alignment at `0x005b68c0`.
  - [UID:0000CX][SelfSaveOKPane](by-class/SelfSaveOKPane.md): related feature wording only; different pane family and address island.
  - `NONE`: appropriate for Chat/TextDialog no-route raw islands that lack a strong source route. Here the SelfSave constructor, active handler, vtables, factory, and exact duplicate packet tail provide a stronger feature-owner route.

Issue: relationship to [UID:0003O6] active confirm handler.

- Evidence checked: disassembly of both bodies.
- Result: [UID:0003O6] validates one-character input and sends opcode `0x25` inline. [UID:0003O7] is only the send tail, without input length/read/`y`/`Y` checks.
- Recommendation: do not rewrite [UID:0003O6] as a call to [UID:0003O7] in target docs unless a real call route appears. The first-draft source helper may be documented as plausible source shape, but the binary currently contains an inline copy in the active handler plus a retained helper body.

Issue: first-draft C++ versus no-code proof.

- Evidence checked: reconstructable metadata, nonblank owner/emitter, average score, exact byte behavior, no-route state, sibling helper policy.
- Result: first-draft C++ is appropriate. This is not target-specific no-code/compiler glue. The only blocker is liveness, and adjacent retained raw helper precedents keep similar bodies source-authored/reconstructable with either a draft helper or explicit blank C++ caveat.
- Recommendation: populate formal C++ if the supervisor accepts no-route retained helper emission. Otherwise leave formal C++ blank with an explicit defer proof, not generic "IDA does not model this" wording.

Issue: stale low-gate wording.

- Evidence checked: [UID:0003O6] still says C++ remains blank until "90/90+ code-entry standard"; older pages cite "95/95" or old final gates.
- Recommendation: replace stale numeric-gate wording with current target-specific caveats: exact source shape is known, but no ordinary route and coordinated SelfSave source grouping remain the meaningful blockers.

## First-Draft C++

Recommended target C++ if accepted:

```cpp
namespace {
const unsigned char kSelfSavePacketOpcode = 0x25;

static void SendSelfSavePacket()
{
    char packet[2];

    PacketBufferWriteUInt8(static_cast<char>(kSelfSavePacketOpcode), packet);
    packet[1] = 0;

    QueueAndSendPacket(g_packetSender, packet, 1);
}
}
```

Notes for implementation prose:

- `PacketBufferWriteUInt8` is the current best source-facing name for `0x00575380`.
- `QueueAndSendPacket` is the current best source-facing name for `0x00574bb0`.
- `g_packetSender` is best current source-facing type `Socket *` per [UID:0000Q5]/[UID:0001P0], but the target does not need to restate the full Socket type caveat.
- The helper should not hand-code security-cookie behavior.
- The helper should not manually mention stack offsets.
- The helper should not hard-code vtable or constructor behavior; those belong to [UID:0003O5] and [UID:0001KQ].

## Recommended Target Doc Changes

Apply only after supervisor review:

1. Rename target doc:
   - From: `by-memory/0x005b6870-0x005b68b0.SelfSaveInputPaneSendSelfSavePacketRaw.md`
   - To: `by-memory/0x005b6870-0x005b68b1.SelfSaveInputPaneSendSelfSavePacketRaw.md`
2. Update metadata:
   - `COMPLETION:87`
   - `CONFIDENCE:88`
   - Keep `CANONICAL_OWNER:0000CW`
   - Keep `RECONSTRUCTABLE:TRUE`
   - Keep `EMITTER_UIDS:0000CW`
3. Update heading and Address Range:
   - Heading: `# 0x005b6870-0x005b68b1 SelfSaveInputPane Send Self Save Packet Raw`
   - Range: `0x005b6870-0x005b68b1`, exclusive end.
   - Explicitly state `0x005b68b0` is `ret`; following alignment is `0x005b68b1-0x005b68c0`.
4. Replace the current reconstruction note:
   - Old meaning: blank because IDA does not model raw start and no direct caller/xref is known.
   - New meaning: source shape is known as retained file-local `SendSelfSavePacket()`; no-route state remains a liveness caveat, not a generic C++ blocker.
5. Add Behavior detail:
   - Writes opcode `0x25` with `PacketBufferWriteUInt8`.
   - Clears `packet[1]` as a non-transmitted terminator/scratch byte.
   - Calls `QueueAndSendPacket(g_packetSender, packet, 1)`.
   - Reads no input and no object fields.
6. Add Route/Liveness section:
   - No rel32 call/jump/conditional branch route.
   - No absolute VA/RVA/raw-offset pointer route.
   - No pointer to any byte in corrected target range.
   - Positive controls found the [UID:0003O6] vtable pointer and `g_packetSender` xrefs.
7. Add source-quality section:
   - Best name/signature: file-local `static void SendSelfSavePacket()`.
   - Weaker alternative: `SelfSaveInputPane::SendSelfSavePacket()` only if later evidence proves a class static/non-static declaration.
   - Keep owner/emitter [UID:0000CW] for current child attachment; source file context is [UID:0000NM], future consolidation [UID:0000ID].
8. Add first-draft C++ block above, or if the supervisor chooses no formal C++ insertion, add exact defer proof:
   - "Formal C++ is deferred only because no ordinary route to `0x005b6870` is known and [UID:0003O6] already sends the packet inline; the retained helper source shape is otherwise known."

## Recommended Support Doc Changes

[UID:0001MU][SelfSaveInputPane method island]:

- Rename to `0x005b67c0-0x005b68b1.SelfSaveInputPane.md`.
- Update aggregate range to `0x005b67c0-0x005b68b1`.
- Update child table:
  - `0x005b6870-0x005b68b1` for [UID:0003O7].
  - `0x005b68b1-0x005b68c0` for successor alignment.
- Update IDA/byte evidence to state `0x005b68b0` is `ret`, not padding.

[UID:0000CW][SelfSaveInputPane]:

- Add the retained raw send helper decision:
  - file-local/private source helper `SendSelfSavePacket()`;
  - no `this` usage;
  - no ordinary route;
  - same opcode `0x25` as active handler.
- Add or update method notes to distinguish:
  - constructor [UID:0003O5] raw no-route;
  - active virtual confirm handler [UID:0003O6] vtable-routed;
  - retained raw send helper [UID:0003O7] no-route;
  - factory [UID:0001KQ] file-level no-route.
- Keep class page C++ blank unless a coordinated SelfSave implementation callback adds all method/helper bodies in the class/source file.

[UID:0000NM][SelfSaveInputPane]:

- Update raw helper range from `0x005b6870-0x005b68b0` to `0x005b6870-0x005b68b1`.
- Add exact `ret`/padding correction: raw byte reads previously described `0x005b6870-0x005b68af` and sixteen `0xcc` bytes after; correct it to helper through `ret` at `0x005b68b0` and fifteen `0xcc` bytes from `0x005b68b1`.
- State best source-facing helper is file-local `SendSelfSavePacket()`, not a proven class method.
- Keep immediate route on this file while noting that [UID:0000ID] remains the likely final source consolidation target.

[UID:0000ID][CommandInputPanes]:

- Update the command-input neighborhood note from `0x005b29c0-0x005b68b0` to `0x005b29c0-0x005b68b1` if it is intended to include the full SelfSave raw helper.
- Add that B007 corrected the helper end byte and source shape, but does not recommend moving only [UID:0003O7] to `CommandInputPanes.cpp` without the rest of the SelfSave family.

[UID:0003O6][SelfSaveInputPaneConfirmInput]:

- Replace stale "90/90+ code-entry standard" wording with current source-quality wording.
- Add that the active handler already sends opcode `0x25` inline after `y`/`Y`; do not force a call to [UID:0003O7] without real route evidence.

[UID:0003O5][SelfSaveInputPaneConstructorRaw]:

- Add cross-reference to the corrected [UID:0003O7] path after rename.
- No behavior change needed for this pass.

[UID:0001KQ][SelfSaveInputPaneFactory]:

- Add/update cross-reference to corrected [UID:0003O7] path.
- Preserve B012 conclusion: factory does not call the raw send helper.

[UID:0002N8] and [UID:0003HM] vtable docs:

- No vtable slot changes. Optional cross-reference-only update to corrected [UID:0001MU]/[UID:0003O7] paths after rename.

[UID:0000Q5] and [UID:0001P0] `g_packetSender`:

- Optional cross-reference update only. Existing docs already record SelfSave local refs at `0x005b6845` and `0x005b688b`.

`by-memory/-ignored.md`:

- Replace ignored padding entry `0x005b68b0-0x005b68c0` with `0x005b68b1-0x005b68c0`.
- Replace evidence text that says the helper returns at `0x005b68af` followed by sixteen `0xcc` bytes. Correct evidence: `0x005b68af` is `pop ebp`, `0x005b68b0` is `ret`, and `0x005b68b1-0x005b68c0` are fifteen `0xcc` bytes.

`by-project-structure/proposed-source-tree.md`:

- Optional support update: where the command-input neighborhood says `0x005b29c0-0x005b68b0`, use `0x005b29c0-0x005b68b1` if the range is meant to include the full SelfSave helper.

## Score And Metadata Recommendation

Recommended target metadata:

```text
COMPLETION:87
CONFIDENCE:88
CANONICAL_OWNER:0000CW
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000CW
```

Rationale:

- Completion increases because the exact range is corrected, the missing `ret` byte is identified, no-route evidence now includes raw PE scans with positive controls, packet helper names are resolved, source-facing helper name/signature is selected, and first-draft C++ is ready.
- Confidence increases because behavior is byte-exact and agrees with the active confirm handler tail. Confidence remains capped because no ordinary route exists and final source-file consolidation is unsettled.
- Do not raise to `95+` or treat as final-source quality. The original helper spelling and runtime liveness remain inferred.

## Exact Coverage Text

Do not edit `by-memory/-coverage-report.md` during this report pass. If supervisor accepts the boundary correction and target child row insertion, replace the current [UID:0001MU] row near the `0x005b65xx-0x005b68xx` section with this block:

```md
    - [UID:0001MU][0x005b67c0-0x005b68b1.SelfSaveInputPane](by-memory/0x005b67c0-0x005b68b1.SelfSaveInputPane.md) 0x005b67c0-0x005b68b1 | class method island | SelfSaveInputPane : ignored : 88% : strong : Non-emitting SelfSave prompt island; exact children carry reconstruction. Contains raw constructor `0x005b67c0-0x005b6800`, vtable-routed confirmation handler `0x005b6800-0x005b686c`, four-byte alignment `0x005b686c-0x005b6870`, and retained raw send helper `0x005b6870-0x005b68b1`; B007 2026-06-19 PE recheck corrects the prior end byte by proving `0x005b68b0` is the helper `ret` and padding begins at `0x005b68b1`.
        - [UID:0003O5][0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw](by-memory/0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw.md) 0x005b67c0-0x005b6800 | raw constructor | SelfSaveInputPaneConstructorRaw : reconstructable : 85% : strong : Raw constructor-shaped `SelfSaveInputPane` body; calls localized string id `0x26`, constructs `CharInputPane`, and installs the three SelfSave vtable views.
        - [UID:0003O6][0x005b6800-0x005b686c.SelfSaveInputPaneConfirmInput](by-memory/0x005b6800-0x005b686c.SelfSaveInputPaneConfirmInput.md) 0x005b6800-0x005b686c | virtual method | SelfSaveInputPaneConfirmInput : reconstructable : 86% : strong : Active vtable-routed one-character confirmation handler; accepts only `y`/`Y`, writes opcode `0x25`, clears a non-transmitted terminator byte, and queues a one-byte packet through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md).
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005b686c-0x005b6870 | padding | SelfSave confirm handler to raw send helper alignment : ignored : 100% : strong : Four `0xcc` bytes between [UID:0003O6] and [UID:0003O7].
        - [UID:0003O7][0x005b6870-0x005b68b1.SelfSaveInputPaneSendSelfSavePacketRaw](by-memory/0x005b6870-0x005b68b1.SelfSaveInputPaneSendSelfSavePacketRaw.md) 0x005b6870-0x005b68b1 | retained raw packet helper | SelfSaveInputPaneSendSelfSavePacketRaw : reconstructable : 87% : strong : Source-authored retained no-route helper that sends self-save opcode `0x25` without reading input; B007 2026-06-19 PE scan proves the corrected half-open range includes `ret` at `0x005b68b0`, finds no rel32 call/jump, VA, RVA, raw-offset, or target-range pointer route to `0x005b6870`, and resolves the best source shape as file-local `SendSelfSavePacket()` using [UID:0003YJ][PacketBufferWriteUInt8](by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md), [UID:0000Q5][g_packetSender](by-global/g_packetSender.md), and [UID:0001HU][QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md).
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005b68b1-0x005b68c0 | padding | SelfSave raw send helper to BlockListenInputPane alignment : ignored : 100% : strong : Fifteen `0xcc` bytes after [UID:0003O7]'s `ret` at `0x005b68b0` and before [UID:0001MV][0x005b68c0-0x005b6900.BlockListenInputPaneConstructor](by-memory/0x005b68c0-0x005b6900.BlockListenInputPaneConstructor.md).
```

If the supervisor chooses not to introduce child rows in the coverage report, at minimum replace the existing [UID:0001MU] row with a single aggregate row that uses the corrected range `0x005b67c0-0x005b68b1` and mentions the corrected [UID:0003O7] subrange `0x005b6870-0x005b68b1`.

## Exact Callback Implementation Instructions

If the supervisor accepts this report, send B007 an implementation callback with these concrete steps:

1. Rename [UID:0003O7] target file to `by-memory/0x005b6870-0x005b68b1.SelfSaveInputPaneSendSelfSavePacketRaw.md`.
2. Update [UID:0003O7] metadata to `87/88`, keeping owner/emitter `0000CW`.
3. Update [UID:0003O7] range, behavior, route scan, source-facing name/signature, first-draft C++ or exact defer proof, score rationale, and IDA recommendations using the details above.
4. Rename/update [UID:0001MU] aggregate to `0x005b67c0-0x005b68b1`, and update its child table and padding rows.
5. Update [UID:0000CW], [UID:0000NM], [UID:0000ID], [UID:0003O6], [UID:0003O5], [UID:0001KQ], [UID:0002N8], [UID:0003HM], and `by-memory/-ignored.md` as listed in "Recommended Support Doc Changes".
6. Do not edit `by-memory/-coverage-report.md`; carry the exact coverage block above for supervisor-owned application.
7. Run validators from `source-3/project-documentation` with scoped file mode and `--queue-timeout 240`.

## Validation Commands Needed After Implementation

No validators were run in this report-only pass because no by-* docs were edited.

Run from `E:\NTK\GhidraBridge\source-3\project-documentation` after accepted implementation:

> Executable block R001 was removed from this report and preserved verbatim in [0003O7-SelfSaveInputPaneSendSelfSavePacketRaw-source-quality-removed.md](0003O7-SelfSaveInputPaneSendSelfSavePacketRaw-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If vtable cross-reference paths are updated:

> Executable block R002 was removed from this report and preserved verbatim in [0003O7-SelfSaveInputPaneSendSelfSavePacketRaw-source-quality-removed.md](0003O7-SelfSaveInputPaneSendSelfSavePacketRaw-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

After the supervisor applies the banned coverage row:

> Executable block R003 was removed from this report and preserved verbatim in [0003O7-SelfSaveInputPaneSendSelfSavePacketRaw-source-quality-removed.md](0003O7-SelfSaveInputPaneSendSelfSavePacketRaw-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## IDA Rename / Type / Comment Recommendations

If IDA edits are later allowed:

- At `0x005b6870`:
  - Name: `SendSelfSavePacket` or audit-safe `SelfSaveInputPane_SendSelfSavePacket_raw`.
  - Type: `void __cdecl SendSelfSavePacket(void)`.
  - Comment: `Retained no-route SelfSave packet helper. Sends one-byte opcode 0x25 via g_packetSender/QueueAndSendPacket; no this/args; B007 PE scan found no rel32/VA/RVA/raw-offset route; corrected range ends after ret at 0x005b68b0.`
- At `0x005b68b1-0x005b68c0`:
  - Mark as alignment padding, not part of the helper.
- At `0x005b6800`:
  - Keep/confirm `SelfSaveInputPane::OnConfirmInput`.
  - Comment: `Active vtable-routed y/Y confirmation path; sends opcode 0x25 inline. Do not force-call raw helper without route evidence.`
- At `0x00575380`:
  - Keep source-facing helper name family `PacketBufferWriteUInt8`.
- At `0x00574bb0`:
  - Keep source-facing helper name `QueueAndSendPacket`.
- At `0x0067a7ec`:
  - Keep `g_packetSender`.

Confidence:

- High for corrected target bytes, packet behavior, and dependency roles.
- Medium-high for `SendSelfSavePacket` name because original spelling is inferred.
- Medium for formal source declaration style because no route proves file-local static versus class static/non-static declaration.
- Low for runtime liveness because no ordinary route exists.

## Open Questions Closed Or Remaining

Closed:

- Exact range: `0x005b6870-0x005b68b1`, not `0x005b6870-0x005b68b0`.
- Padding after target: `0x005b68b1-0x005b68c0`.
- Source-bearing versus compiler glue: source-bearing retained packet helper.
- Opcode semantics: self-save confirmation request opcode `0x25`.
- Packet length: exactly one transmitted byte.
- Packet writer helper: `PacketBufferWriteUInt8` / `0x00575380`.
- Send helper: `QueueAndSendPacket` / `0x00574bb0`.
- Sender global: `g_packetSender` / `0x0067a7ec`.
- Best source-facing helper name/signature: `static void SendSelfSavePacket()`.
- Relationship to active handler: active handler sends same packet inline after input validation; raw helper is no-route retained send-only body.
- BlockListen ownership: rejected; it starts after corrected padding at `0x005b68c0`.
- Socket/g_packetSender ownership: rejected for feature packet construction.
- Compiler-generated/no-code classification: rejected.

Remaining:

- No ordinary route to `0x005b6870` is known. This caps confidence and must remain visible.
- Original helper spelling is inferred.
- Original declaration style is not proven. File-local static is the best source shape; class method/static remains a secondary alternative only if later route/header evidence appears.
- Final source-file consolidation remains open. [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md) is likely final context, but moving only [UID:0003O7] would split the SelfSave prompt family.

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B007/research/0003O7-SelfSaveInputPaneSendSelfSavePacketRaw-source-quality.md`
- Modified: none outside the B007 research folder.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003O7","source_path":"executed-b-agent-research/B007/0003O7-SelfSaveInputPaneSendSelfSavePacketRaw-source-quality.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
