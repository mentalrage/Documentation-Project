** TARGET-REPORT-UID:0003W3 **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003W3 **
# Agent-B004 Report - [UID:0003W3] MenuQuestionDialogSelectionPacketNoRouteRaw

FINISHED report-only source-routing pass for:

- Target: `source-3/project-documentation/by-memory/0x0054fa60-0x0054fb21.MenuQuestionDialogSelectionPacketNoRouteRaw.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B004/research/0003W3-MenuQuestionDialogSelectionPacketNoRouteRaw-source-routing.md`
- Current target metadata checked: `COMPLETION:85`, `CONFIDENCE:86`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank final C++.
- Report-only constraint honored: no by-* documentation and no `by-memory/-coverage-report.md` edits were made.

## Recommendation

Keep [UID:0003W3] as no-owner and non-emitting. Raise the documentation score to `COMPLETION:87`, `CONFIDENCE:89`.

Recommended metadata:

```text
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Do not add `RECONSTRUCTION_CPP CODE`. This remains a source-shaped raw helper candidate, not a routed source method. If a future route is proven, the most likely source-facing shape would be a private `MenuQuestionDialog::SendSelectionPacket(uint8_t selectedRowId)` helper in [UID:0000LA] `MessageDialogs`, but current evidence still rejects assigning an emitter.

The important wording correction is the packet terminator. The helper writes a zero byte at `packet[12]`, but then calls `QueueAndSendPacket(..., packet, 0x0c)`. That zero is local scratch/terminator storage outside the counted 12-byte payload, not a protocol trailing-zero field. Current docs that say the function sends a trailing zero should be corrected.

## Evidence Checked

Instruction/range evidence:

- Fresh PE read from `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, image base `0x00400000`.
- Fresh Capstone disassembly of `0x0054fa5d-0x0054fb30`.
- Fresh Capstone disassembly of positive-control live handler `0x0054f8e0-0x0054fa20`.
- Fresh Capstone disassembly of larger twin raw island `0x00550c7d-0x00550d50`.
- Fresh Capstone disassembly of larger live handler `0x00550b00-0x00550c40`.
- Fresh Capstone disassembly of shared navigation helpers `0x0054cc30-0x0054ce0f`.
- Local static export JSON `exports/0054fa60.json`, `exports/0054f8e0.json`, `exports/00550c80.json`, and `exports/00550b00.json`.

Route/liveness evidence:

- Fresh section-aware PE scan for `0x0054fa60` found zero `E8/E9` rel32 callers/jumps, zero `0F 8x` rel32 conditional branches, zero executable absolute-VA hits, zero executable RVA hits, zero all-section absolute-VA hits, and zero all-section RVA hits.
- Fresh Capstone instruction-boundary scan found zero branch/call immediate operands and zero other immediate operands into `0x0054fa60-0x0054fb21`.
- Fresh positive controls behaved as expected:
  - `0x0054f8e0` live action handler has a `.rdata` absolute pointer at `0x00622644`.
  - `0x00550b00` larger live action handler has a `.rdata` absolute pointer at `0x006226e0`.
  - `0x00574bb0` `QueueAndSendPacket` produced 416 rel32 call hits, matching current docs.
- Existing target/support docs record prior IDA MCP facts: no IDA-modeled function at `0x0054fa60`, no IDA xrefs, no raw rel32 call/jump hits, and no VA/RVA pointer route.
- Live MCP was not available in this session: POST `tools/list` to `http://127.0.0.1:13337/mcp` failed with `Unable to connect to the remote server`.

Document evidence checked:

- Target [UID:0003W3].
- [UID:00007X] `by-class/MenuQuestionDialog.md`.
- [UID:0003W1] `0x0054f8e0-0x0054fa10.MenuQuestionDialogActionHandler.md`.
- [UID:0003W0] `0x0054e920-0x0054f8dd.MenuQuestionDialogConstructor.md`.
- [UID:0003W7] `0x00550c80-0x00550d41.MenuQuestionDialogLargerSelectionPacketNoRouteRaw.md`.
- [UID:0003W5] `0x00550b00-0x00550c30.MenuQuestionDialogLargerActionHandler.md`.
- [UID:0003W4] `0x0054fb30-0x00550afb.MenuQuestionDialogLargerConstructor.md`.
- [UID:00007Y] `by-class/MenuQuestionDialogLarger.md`.
- [UID:0001FG] `0x0054cc30-0x0054ce0f.DialogNavigationPacketHelpers.md`.
- [UID:00023M] `0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md`.
- [UID:0001FH] `0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md`.
- [UID:0000LA] `by-file/MessageDialogs.md`.
- [UID:0003YJ] `0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md`.
- [UID:0001HU] `0x00574bb0-0x00574c13.QueueAndSendPacket.md`.
- Prior executed B001 report `Agent-B001/research/executed/older/0001FH-npc-message-menu-question-source-split.md`.

## Raw Boundary Facts

The exact half-open range should remain `0x0054fa60-0x0054fb21`.

Boundary details:

- `0x0054fa5d-0x0054fa60`: three `0xcc` bytes after [UID:0003W2] `MenuQuestionDialogUpdateConfirmButtonState`.
- `0x0054fa60`: raw body starts with `push ebp; mov ebp, esp; sub esp, 0x104`.
- `0x0054fb1e`: `ret 4`, proving one stack byte/argument slot after `this`.
- `0x0054fb21-0x0054fb30`: fifteen `0xcc` bytes before [UID:0003W4] `MenuQuestionDialogLargerConstructor`.
- The body is 193 bytes, same length as larger raw twin [UID:0003W7].

The old Ghidra export models this as `FUN_0054fa60` with signature `undefined __thiscall FUN_0054fa60(void *this, undefined1 param_1)`, no callers, and no data refs. Current IDA docs say IDA does not model a function at this start. Treat the export as decompilation evidence for byte behavior, not source liveness.

## Packet Shape

The raw body builds a 12-byte payload and passes length `0x0c` to [UID:0001HU] `QueueAndSendPacket` through [UID:0000Q5] `g_packetSender` / historical `dword_67A7EC`.

Recommended packet-field wording:

| Payload offset | Writer | Source | Recommended role |
| --- | --- | --- | --- |
| `0` | `PacketBufferWriteUInt8` / `0x00575380` | constant `0x3a` | dialog/menu response opcode |
| `1` | `PacketBufferWriteUInt8` / `0x00575380` | `this+0x26c` | stored dialog type/menu category byte; best field direction `m_dialogType` or `m_menuCategory` |
| `2..5` | `PacketBufferWriteUInt32BE` / `0x005753f0` | `this+0x270` | stored object/session/context id dword; best field direction `m_objectId` or `m_contextObjectId` |
| `6..7` | `PacketBufferWriteUInt16BE` / `0x005753a0` | `this+0x274` | preserved dialog state word; best field direction `m_dialogState` |
| `8..9` | `PacketBufferWriteUInt16BE` / `0x005753a0` | `this+0x276 + 1` | one-based page/current-index word; best field direction `m_pageIndex` internally, serialized as `m_pageIndex + 1` |
| `10` | `PacketBufferWriteUInt8` / `0x00575380` | constant `1` | selection reply marker/subcommand |
| `11` | `PacketBufferWriteUInt8` / `0x00575380` | stack argument byte | selected menu row id/option id |
| `12` | direct byte store | constant `0` | local terminator/scratch byte outside `sendSize=12`; not sent as a protocol field |

Relevant instructions:

```asm
0054fa7d  push  3Ah
0054fa7f  call  575380h
0054fa8b  movzx eax, byte ptr [esi+26Ch]
0054fa93  call  575380h
0054fa9f  push  dword ptr [esi+270h]
0054faa5  call  5753F0h
0054fab1  movzx eax, word ptr [esi+274h]
0054fab9  call  5753A0h
0054fac5  movzx eax, word ptr [esi+276h]
0054facc  inc   eax
0054face  call  5753A0h
0054fada  push  1
0054fadc  call  575380h
0054fae8  movzx eax, byte ptr [ebp+8]
0054faed  call  575380h
0054fb01  mov   byte ptr [ebp-0F8h], 0
0054fb08  push  0Ch
0054fb0b  call  574BB0h
0054fb1e  ret   4
```

This also resolves the apparent byte-count conflict in the current docs: the local buffer has 13 initialized bytes, but only 12 are sent. [UID:0003YJ] already documents the PacketBuffer writers' spare zero byte behavior, and [UID:0001HU] documents that `QueueAndSendPacket` copies the requested length and appends its own queue terminator.

## Relationship To Live Action Handler

[UID:0003W1] `MenuQuestionDialogActionHandler` is the active routed implementation for the same user-visible submit behavior.

Live handler facts from the fresh disassembly:

- Range `0x0054f8e0-0x0054fa10`; following `0x0054fa10-0x0054fa20` is the action switch table.
- Vtable route is already documented and positive-controlled by the `.rdata` pointer `0x00622644 -> 0x0054f8e0`.
- Case `1` starts at `0x0054f91e` and gets the selected row id through child control id `5`.
- The selected row path calls `0x004f3dc0` and uses `byte ptr [eax]` as the selected row id.
- It writes the same 12-byte payload layout as raw [UID:0003W3].
- It calls `QueueAndSendPacket(g_packetSender, packet, 0x0c)`.
- It then closes/dismisses the dialog with `0x0049dad0`.
- It returns `ret 8`, consistent with the virtual action handler taking two stack arguments.

The raw [UID:0003W3] body differs in the way a helper would differ:

- It takes the selected row id as the sole explicit stack argument and ends `ret 4`.
- It does not look up child control id `5`.
- It does not call `0x0049dad0` to close the dialog.
- It is adjacent to the normal menu-question method group but has no route into the active graph.

Therefore the best semantic description is "unrouted private selection-packet helper clone," not "the active selection submit handler."

## Larger Twin Comparison

[UID:0003W7] `0x00550c80-0x00550d41.MenuQuestionDialogLargerSelectionPacketNoRouteRaw` is the larger-layout twin.

Fresh disassembly comparison:

- Same half-open length: 193 bytes.
- Same instruction count: 55 instructions.
- Same mnemonic/op-str sequence under Capstone after relocations are resolved.
- Same packet layout, `ret 4`, helper calls, and local terminator pattern.
- Same negative route result for start `0x00550c80`: no rel32 caller/jump, no conditional rel32 branch, no executable absolute VA/RVA hit, no all-section absolute VA/RVA hit.

This twin supports a retained-helper-clone interpretation, because both normal and larger dialogs have active virtual action handlers that inline the submit path and both have adjacent, source-shaped helper bodies with no route.

## Ownership And Source Placement

Do not assign a canonical owner or emitter today.

Ranked alternatives:

1. **Dead retained private helper from `MenuQuestionDialog` in `MessageDialogs.cpp`** - strongest semantic match. The byte behavior, adjacency, field offsets, and normal/larger twin pattern point here. This is still not enough for ownership because no caller, vtable, table pointer, or absolute pointer route exists.
2. **Missed pointer/table route** - actively investigated and currently rejected. PE scans found no VA/RVA pointer to the entry and no direct branch/call route. Positive controls found routed vtable entries for the live action handlers, so the scan was capable of finding the common table form used nearby.
3. **Shared dialog navigation helper family** - rejected as canonical ownership. The packet uses the shared `0x3a` header fields, but selection marker/selected-row semantics are menu-question-specific and the body is physically adjacent to `MenuQuestionDialog`, not the shared helper cluster at `0x0054cc30`.
4. **`MenuQuestionItemList` owner** - rejected. The row id comes from the list in the active handler, but the raw helper consumes dialog state at `this+0x26c..0x276`; `this` is the dialog object, not the list widget.
5. **Compiler-generated helper/thunk** - rejected. The body has a full stack-cookie frame and hand-source packet serialization; it is not a thunk, scalar deleting destructor, adjustor, switch table, or padding.
6. **Padding/data/switch table** - rejected. The raw body is valid code bounded by `0xcc` padding and ending in `ret 4`; the real switch table is the preceding `0x0054fa10-0x0054fa20` span.

The target can say: "If a future route is found, attach it to [UID:00007X] `MenuQuestionDialog` with source file [UID:0000LA] `MessageDialogs`; until then keep `NONE` and non-emitting."

## No-Code Proof

Final C++ should remain blank for [UID:0003W3].

Target-specific proof:

- The active class behavior is already emitted/routed through [UID:0003W1] `MenuQuestionDialogActionHandler`.
- [UID:0003W3] has no current route: no IDA xrefs in current docs, no current-session PE branch/call target, no table/pointer target, and no vtable entry.
- The body would duplicate active submit serialization if emitted under [UID:00007X].
- Assigning it to [UID:0000LA] directly would create a source helper that no live code calls.
- Its only clear source-level role is hypothetical/private, and the reconstruction policy requires an owner/emitter route before final C++ emission.

Do not insert this C++ in the by-memory target. It is included only to lock down the inferred shape if a future route appears:

```cpp
// Non-emitting source-shape inference only. Do not place in RECONSTRUCTION_CPP
// until a caller, pointer, vtable, or runtime route to 0x0054fa60 is proven.
void MenuQuestionDialog::SendSelectionPacket(unsigned char selectedRowId)
{
    unsigned char packet[13];

    PacketBufferWriteUInt8(0x3a, &packet[0]);
    PacketBufferWriteUInt8(m_dialogType, &packet[1]);
    PacketBufferWriteUInt32BE(m_objectId, &packet[2]);
    PacketBufferWriteUInt16BE(m_dialogState, &packet[6]);
    PacketBufferWriteUInt16BE(m_pageIndex + 1, &packet[8]);
    PacketBufferWriteUInt8(1, &packet[10]);
    PacketBufferWriteUInt8(selectedRowId, &packet[11]);
    packet[12] = 0;

    g_packetSender->QueueAndSendPacket(packet, 12);
}
```

Field names above are recommended directions, not final declarations.

## Open Questions Closed Or Narrowed

- **Is there any route to `0x0054fa60`?** No route found. Current docs record negative IDA xrefs; fresh PE scans found no branch/call or address-table route. Keep no-owner.
- **Could it be a missed vtable method?** Very unlikely. Positive controls found vtable pointers for `0x0054f8e0` and `0x00550b00`; there is no pointer to `0x0054fa60`.
- **Does it send a trailing zero protocol byte?** No. It initializes `packet[12]` to zero but sends length `12`. The zero is a local terminator/spare byte.
- **What is the selected byte?** Best direction: selected row id / option id. The live handler obtains it from the selected list-row record via child id `5` and `0x004f3dc0`.
- **What are `this+0x26c..0x276`?** Best direction: `m_dialogType`/`m_menuCategory`, `m_objectId`/`m_contextObjectId`, `m_dialogState`, and internal `m_pageIndex`. The first three are preserved from the constructor packet; `m_pageIndex` is adjusted by navigation helpers and serialized as one-based for selection.
- **Should `MessageDialogs` own it despite no route?** No. Source placement is high-probability, but ownership/emission requires liveness. Keep the placement as a note only.

## Exact Recommended Target Edits

For `by-memory/0x0054fa60-0x0054fb21.MenuQuestionDialogSelectionPacketNoRouteRaw.md`:

1. Change score metadata to `COMPLETION:87`, `CONFIDENCE:89`.
2. Keep `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and blank final C++.
3. Keep title/behavior label `MenuQuestionDialogSelectionPacketNoRouteRaw`.
4. Replace the behavior paragraph with packet-layout text that says:
   - source-facing candidate if routed: private `MenuQuestionDialog::SendSelectionPacket(uint8_t selectedRowId)`;
   - writes opcode `0x3a`;
   - writes stored dialog fields at `this+0x26c`, `this+0x270`, `this+0x274`, and `this+0x276 + 1`;
   - writes selection marker `1` and the selected row id argument;
   - writes `packet[12] = 0` as a local terminator outside the sent length;
   - sends exactly 12 bytes via `g_packetSender`/`QueueAndSendPacket`.
5. Add a packet layout table matching this report.
6. Add boundary evidence:
   - three `0xcc` bytes at `0x0054fa5d-0x0054fa60`;
   - raw body `0x0054fa60-0x0054fb21`;
   - `ret 4` at `0x0054fb1e`;
   - fifteen `0xcc` bytes at `0x0054fb21-0x0054fb30`.
7. Add route evidence:
   - no current PE rel32 branch/call route to start;
   - no current PE instruction-immediate route into range;
   - no all-section absolute VA/RVA pointer to start;
   - prior IDA: no function/xrefs;
   - positive controls: `0x00622644 -> 0x0054f8e0`, `0x006226e0 -> 0x00550b00`, 416 rel32 call hits to `0x00574bb0`.
8. Add relationship to [UID:0003W1]:
   - live handler inlines the same 12-byte packet, derives selected id from child list id `5`, sends, then closes the dialog with `0x0049dad0`;
   - raw helper takes selected byte as an argument and does not close the dialog.
9. Add larger-twin comparison to [UID:0003W7]:
   - identical source-shaped instruction sequence, same no-route disposition.
10. Add no-code proof:
   - no route, active behavior already inlined in [UID:0003W1], emitting would duplicate behavior.

Suggested target replacement wording for the behavior section:

```text
This raw body is a source-shaped private selection-packet helper candidate for normal `MenuQuestionDialog`. If it were routed, the likely source-facing name would be `MenuQuestionDialog::SendSelectionPacket(uint8_t selectedRowId)`. It writes a 12-byte opcode `0x3a` menu-question reply: stored dialog type byte, stored object/context id, stored dialog state word, one-based page/index word, selection marker `1`, and the caller-supplied selected row id. It also writes a zero at local `packet[12]`, but the send length is `0x0c`, so that byte is a local terminator/spare byte rather than a sent protocol field.
```

Suggested target no-code wording:

```text
Final C++ remains ineligible. The active [UID:0003W1] action handler is vtable-routed and already inlines the selection submit behavior, while this raw helper has no IDA function, no xrefs, no current PE branch/call route, and no VA/RVA pointer route. Keep no-owner/non-emitting unless a caller, table pointer, or runtime route is proven.
```

## Exact Recommended Support-Doc Edits

For `by-class/MenuQuestionDialog.md`:

- Update the action-handler evidence to say the submit payload is 12 bytes and that the explicit zero is a local terminator outside the sent payload.
- Add a short caveat for [UID:0003W3]: source-shaped `SendSelectionPacket(uint8_t selectedRowId)` candidate, but no route; active submit remains [UID:0003W1].
- Update field table direction:
  - `this+0x26c`: stored dialog type/menu category byte, likely `m_dialogType` or `m_menuCategory`.
  - `this+0x270`: stored object/context/session id, likely `m_objectId` or `m_contextObjectId`.
  - `this+0x274`: stored dialog state word, likely `m_dialogState`.
  - `this+0x276`: page/current-index word, likely `m_pageIndex`; selection serializes `m_pageIndex + 1`.

For `by-memory/0x0054f8e0-0x0054fa10.MenuQuestionDialogActionHandler.md`:

- Replace "and a trailing zero, then sends 12 bytes" with "sets the local terminator byte at `packet[12]`, sends length `0x0c`, and therefore does not send the terminator as a protocol field."
- Add that case `1` is the active routed implementation and [UID:0003W3] is an unrouted duplicate/helper candidate.

For `by-memory/0x0054cc30-0x0054ce0f.DialogNavigationPacketHelpers.md`:

- Refine the zero wording for the navigation helpers too: each helper writes a local zero at `packet[10]` and sends length `10`; the zero is a terminator/spare byte, not a protocol field.
- Keep existing field-role table, but prefer `m_pageIndex` for `this+0x276` in future source-quality wording.

For `by-file/MessageDialogs.md`:

- Add one sentence in the raw-helper caveat: [UID:0003W3] has been rechecked and remains non-emitting; if ever routed, conceptual placement would be a private normal `MenuQuestionDialog` helper in `MessageDialogs.cpp`.

For `by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md`:

- If touched, update only the [UID:0003W3] row/caveat to include the refined no-route proof and the local-terminator clarification. No split/range change is needed.

No support-doc edit is required to [UID:0003W7] from this report alone, because B012 has the larger twin assignment. If a supervisor wants parity edits, apply the same terminator/source-shape wording there after B012 review.

## Coverage Row Text

Do not edit `by-memory/-coverage-report.md` in this B-agent pass. If the supervisor accepts this report and applies the score change, replace the existing [UID:0003W3] row with:

```text
        - [UID:0003W3][0x0054fa60-0x0054fb21.MenuQuestionDialogSelectionPacketNoRouteRaw](by-memory/0x0054fa60-0x0054fb21.MenuQuestionDialogSelectionPacketNoRouteRaw.md) 0x0054fa60-0x0054fb21 | no-route raw code island | MenuQuestionDialogSelectionPacketNoRouteRaw : ignored/non-emitting : 87% : strong : Raw source-shaped `MenuQuestionDialog::SendSelectionPacket(uint8_t selectedRowId)` candidate writes a 12-byte opcode `0x3a` selection reply through `g_packetSender`/`QueueAndSendPacket`; `packet[12]=0` is a local terminator outside the sent length. Fresh PE route scan and prior IDA evidence find no IDA function, no xrefs, no rel32 branch/call route, no instruction-immediate route, and no VA/RVA pointer route; active [UID:0003W1] action handler already inlines the routed submit behavior. Keep `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitter/final C++ unless a route is found.
```

## Implementation Checklist For Callback

If accepted for implementation, make these edits only under normal lease/validator rules:

1. Edit target `by-memory/0x0054fa60-0x0054fb21.MenuQuestionDialogSelectionPacketNoRouteRaw.md`.
2. Change metadata to `87/89`; preserve no-owner/non-reconstructable/blank emitter/blank C++.
3. Replace stale behavior/evidence with the packet layout, local-terminator correction, route scan, live-handler comparison, larger-twin comparison, rejected alternatives, and no-code proof above.
4. Edit `by-class/MenuQuestionDialog.md` if it still says the selection path sends a trailing zero or leaves [UID:0003W3] as a passive unresolved caveat.
5. Edit `by-memory/0x0054f8e0-0x0054fa10.MenuQuestionDialogActionHandler.md` if it still says the active handler sends a trailing zero protocol byte.
6. Edit `by-memory/0x0054cc30-0x0054ce0f.DialogNavigationPacketHelpers.md` if it still says the navigation helpers send a trailing zero protocol byte.
7. Edit `by-file/MessageDialogs.md` and/or [UID:0001FH] only if their raw-helper caveats contradict the accepted no-route/local-terminator wording.
8. Do not edit `by-memory/-coverage-report.md`; leave the exact row above for supervisor-owned application.
9. Do not add final C++ to [UID:0003W3].

## Validation Commands Needed

From `source-3/project-documentation`, run the scoped validator for every touched doc, for example:

> Executable block R001 was removed from this report and preserved verbatim in [0003W3-MenuQuestionDialogSelectionPacketNoRouteRaw-source-routing-removed.md](0003W3-MenuQuestionDialogSelectionPacketNoRouteRaw-source-routing-removed.md). The archived block is non-authoritative and must not be executed.

Run only the commands for files actually edited. No generated C++ workflow should run, because final C++ remains blank and this page stays non-emitting.

## IDA Rename/Type/Comment Recommendations

Because current IDA does not model a function at `0x0054fa60` and no route exists, do not create a final source-facing IDA function/rename yet.

Safe comment-only recommendations:

- At `0x0054fa60`: `unrouted MenuQuestionDialog selection-packet helper candidate; sends 12-byte opcode 0x3a payload; no owner/emitter until route is proven`.
- At `0x0054fb01`: `packet[12] local terminator; QueueAndSendPacket length is 0x0c, so this byte is not sent`.
- At `0x0054fb08`: `send length 12`.

If a future analysis namespace requires a temporary label, use a clearly non-source label such as `raw_MenuQuestionDialog_SendSelectionPacket_noRoute_54FA60`, not `MenuQuestionDialog::SendSelectionPacket`.

Confidence levels:

| Recommendation | Confidence |
| --- | --- |
| Keep no-owner/non-emitting | High |
| Conceptual source placement under `MenuQuestionDialog` / `MessageDialogs.cpp` if routed | High |
| Candidate helper name `SendSelectionPacket` | Medium-high |
| Field direction `m_dialogType`, `m_objectId`, `m_dialogState`, `m_pageIndex` | Medium |
| Do not treat `packet[12]` as sent protocol field | High |

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003W3","source_path":"executed-b-agent-research/B004/0003W3-MenuQuestionDialogSelectionPacketNoRouteRaw-source-routing.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
