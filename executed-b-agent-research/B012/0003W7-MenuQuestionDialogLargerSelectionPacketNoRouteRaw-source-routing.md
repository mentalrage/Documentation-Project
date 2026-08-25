** TARGET-REPORT-UID:0003W7 **
** AUTHOR-AGENT-ID:B012 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003W7 **
# 0003W7 MenuQuestionDialogLargerSelectionPacketNoRouteRaw Source-Routing Report

Assignment: B012 source-routing / no-route raw helper recheck for [UID:0003W7]

Status: FINISHED, report-only. I did not edit `by-*` documentation and did not edit `by-memory/-coverage-report.md`.

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003W7] no-owner, non-reconstructable, and non-emitting.
- Final disposition: exact raw source-shaped code island retained as evidence only.
- Required action: update the target/support docs with the fuller no-code proof, packet layout, best-if-routed helper name, rejected alternatives, fresh route scan, and coverage row text below.
- Recommended target metadata after implementation:
  - `COMPLETION:86`
  - `CONFIDENCE:88`
  - `CANONICAL_OWNER:NONE`
  - `RECONSTRUCTABLE:FALSE`
  - `EMITTER_UIDS:` blank
  - `RECONSTRUCTION_CPP CODE:` blank
- Confidence: high for behavior and non-route proof; low for runtime liveness because no caller/pointer/fallthrough route is proven.

The body is not compiler padding and not generic runtime code. It is a custom source-shaped packet helper candidate. However, fresh PE route scanning found no rel32 call/jump, no absolute VA pointer, and no RVA pointer to `0x00550c80`. Positive controls in the same scan found the expected vtable pointer for the live larger action handler at `0x006226e0 -> 0x00550b00`, vtable pointer for the update method at `0x006226e4 -> 0x00550c40`, and direct constructor call refs to `0x00550d50`. That strongly supports "unreachable retained helper clone" over "missed normal route."

Best source-facing name if a route is ever found:

```cpp
void MenuQuestionDialogLarger::SendSelectionReply(unsigned char selectedValue);
```

Use this only as a descriptive candidate. Do not assign the page to [UID:00007Y] or emit C++ unless a caller, pointer, vtable, EH table, or other runtime route appears.

## Target

- Target UID: `0003W7`
- Target path: `source-3/project-documentation/by-memory/0x00550c80-0x00550d41.MenuQuestionDialogLargerSelectionPacketNoRouteRaw.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B012/research/0003W7-MenuQuestionDialogLargerSelectionPacketNoRouteRaw-source-routing.md`
- Current target metadata: `85/86`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters, blank formal C++.
- Containing split index: [UID:0001FH] `by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md`.
- Closest live owner candidate: [UID:00007Y] `by-class/MenuQuestionDialogLarger.md`, source file [UID:0000LA] `by-file/MessageDialogs.md`.
- Live active submit path: [UID:0003W5] `by-memory/0x00550b00-0x00550c30.MenuQuestionDialogLargerActionHandler.md`.

## Evidence Checked

Existing documentation:

- Target page [UID:0003W7].
- Sibling normal raw helper [UID:0003W3] `0x0054fa60-0x0054fb21.MenuQuestionDialogSelectionPacketNoRouteRaw`.
- Live larger action handler [UID:0003W5] `0x00550b00-0x00550c30.MenuQuestionDialogLargerActionHandler`.
- Live normal action handler [UID:0003W1] `0x0054f8e0-0x0054fa10.MenuQuestionDialogActionHandler`.
- Larger constructor [UID:0003W4] `0x0054fb30-0x00550afb.MenuQuestionDialogLargerConstructor`.
- Larger confirm-button updater [UID:0003W6] `0x00550c40-0x00550c7d.MenuQuestionDialogLargerUpdateConfirmButtonState`.
- Split index [UID:0001FH] `NpcMessageAndMenuQuestionDialogs`.
- Class page [UID:00007Y] `MenuQuestionDialogLarger`.
- File page [UID:0000LA] `MessageDialogs`.
- Shared navigation helpers [UID:0001FG] `0x0054cc30-0x0054ce0f.DialogNavigationPacketHelpers`.
- Packet sender global [UID:0000Q5] `g_packetSender`.
- Queue/send helper [UID:0001HU] `0x00574bb0-0x00574c13.QueueAndSendPacket`.
- PacketBuffer helper index [UID:0001HZ] `0x00575380-0x00575abb.PacketBufferHelpers`.
- Current `by-memory/-coverage-report.md`, `auto-generated/-ag-memory-coverage.md`, and `project-level/-auto-completion-stats.md` rows.
- Prior B001 split report `source-3/project-documentation/tools/leaser/Agents/Agent-B001/research/executed/older/0001FH-npc-message-menu-question-source-split.md`.

Local exported/direct evidence:

- `source-3/core/data/cache/prewave/functions/0x00550c80.json`
- `source-3/core/data/cache/prewave/functions/0x00550b00.json`
- `source-3/core/data/cache/prewave/functions/0x0054fa60.json`
- Relevant decompiled/xref bundles referenced from those exports.
- Fresh read-only PE scan over `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.

No live IDA MCP tool was exposed in this session. Where I rely on B001's live IDA MCP report, I label it as prior documentation evidence. The fresh PE route scan and local prewave exports are new evidence from this pass.

## Raw Bytes, Boundaries, And Padding

Fresh PE scan details:

- PE image base: `0x00400000`.
- `.text` section: `VA=0x00401000`, `RVA=0x00001000`, virtual size `0x20b4ac`, raw size `0x20b600`.
- Target range: `0x00550c80-0x00550d41`, size `0xc1` / 193 bytes.
- Preceding boundary `0x00550c7d-0x00550c80`: `CC CC CC`.
- Target start `0x00550c80-0x00550ca0`:
  - `55 8B EC 81 EC 04 01 00 00 A1 24 2F 67 00 33 C5 89 45 FC 56 8D 85 FC FE FF FF 8B F1 50 6A 3A E8`
  - This is a normal frame/prologue, stack-cookie load, local packet buffer setup, receiver save, and first packet write of opcode `0x3a`.
- Target end `0x00550d30-0x00550d41`:
  - `8B 4D FC 33 CD 5E E8 F4 69 07 00 8B E5 5D C2 04 00`
  - This is stack-cookie verification, restore, and `retn 4`.
- Following boundary `0x00550d41-0x00550d50`: fifteen `CC` bytes.

Boundary conclusion:

- No fallthrough route exists from [UID:0003W6]. It ends at `0x00550c7d`, then three `CC` bytes precede this raw helper.
- No fallthrough route exists to [UID:0003W8]. This helper ends at `0x00550d41`, then fifteen `CC` bytes precede the next modeled constructor at `0x00550d50`.
- The body is real source-shaped code, not padding or a switch table.

## Function Shape And Packet Layout

Local prewave export gives this Ghidra-only function shape:

```cpp
void __thiscall FUN_00550c80(void *this, undefined1 param_1)
```

IDA fields in that export are null: no IDA name, no IDA signature, and no IDA function metadata. Ghidra size is `193` bytes, matching the exact range `0x00550c80-0x00550d41`.

The decompiled body:

```cpp
PacketBuffer_WriteByte(0x3a, packet + 0);
PacketBuffer_WriteByte(*(byte *)(this + 0x26c), packet + 1);
PacketBuffer_WriteDWORD_BE(*(uint32_t *)(this + 0x270), packet + 2);
PacketBuffer_WriteUInt16BE(*(uint16_t *)(this + 0x274), packet + 6);
PacketBuffer_WriteUInt16BE(*(uint16_t *)(this + 0x276) + 1, packet + 8);
PacketBuffer_WriteByte(1, packet + 10);
PacketBuffer_WriteByte(selectedValue, packet + 11);
packet[12] = 0;
QueueAndSendPacket(g_packetSender, packet, 12);
```

Packet fields and best source-facing names:

| Packet offset | Source | Recommended descriptive field | Evidence |
| --- | --- | --- | --- |
| `+0` | constant `0x3a` | `kDialogReplyOpcode` / message-dialog response opcode | Shared navigation helpers and action handlers use opcode `0x3a` for NPC/message/menu-question replies. |
| `+1` | `this +0x26c` | `m_dialogType` / dialog subtype byte | Same offset used by shared navigation helpers and live action handlers. |
| `+2..+5` | `this +0x270` | `m_dialogId` / `m_objectId` / context id | Written big-endian through `0x005753f0`, same as navigation helpers. |
| `+6..+7` | `this +0x274` | `m_stateWord` / dialog state word | Written as 16-bit big-endian through `0x005753a0`. |
| `+8..+9` | `this +0x276 + 1` | `m_currentPage + 1` / one-based page/index | Live menu-question action handler uses the same `+1` before selection send; navigation helpers use this field for previous/next/current page state. |
| `+10` | constant `1` | selection-reply marker / action selector | Present only in selection replies; navigation packets are 10 bytes and omit it. |
| `+11` | `param_1` | selected menu value / selected row id byte | Active handler gets this from the selected row's first byte before writing it. |
| scratch `+12` | zero | local terminator/safety byte | Body writes zero after the 12-byte payload; `QueueAndSendPacket` length is exactly `12`, so the scratch terminator is not sent by this helper. |

The target accepts the selected byte argument and sends only the packet. It does not look up the selected row and does not close the dialog.

## Relationship To The Live Larger Action Handler

[UID:0003W5] `0x00550b00-0x00550c30.MenuQuestionDialogLargerActionHandler` is the active vtable-routed submit path.

Case `1` in the live action handler:

- Fetches child control id `5` from the dialog control collection.
- Dereferences the child control's embedded list pointer at `+0x108`.
- Reads selected index at inherited `ListPane +0x134`.
- Calls `ListPane::GetSelectedEntry` at `0x004f3dc0`.
- Reads the selected row's first byte into `BL`.
- Builds the same opcode `0x3a` packet with `this+0x26c`, `+0x270`, `+0x274`, `+0x276 + 1`, marker `1`, selected row byte, and trailing zero.
- Calls `QueueAndSendPacket(g_packetSender, packet, 12)`.
- Calls the dialog close helper at `0x0049dad0`.
- Returns through `RET 8` as the virtual action method.

Cases `2`, `3`, and `4` call shared previous/next/current navigation helpers [UID:0001FG], then close.

Comparison:

- The raw helper is a strict send-only sub-body candidate for case `1`.
- The live action handler already inlines the selected-row lookup, packet send, and close.
- The raw helper does not close the dialog and cannot replace the full action handler.
- If source-routed, it would be a private helper called by action case `1` after selected-row extraction; however, no call to it exists.

## Fresh Route Scan

I ran a fresh read-only PE scan over `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`. The scan checked:

- `E8` and `E9` rel32 call/jump targets.
- `0F 80` through `0F 8F` rel32 conditional-jump targets.
- Absolute 32-bit VA pointers.
- 32-bit RVA pointers.

Results:

| Target | Meaning | rel32 hits | absolute VA hits | RVA hits |
| --- | --- | ---: | ---: | ---: |
| `0x00550c80` | assigned raw helper | `0` | `0` | `0` |
| `0x0054fa60` | normal raw helper positive sibling | `0` | `0` | `0` |
| `0x00550b00` | live larger action handler | `0` | `1` at `0x006226e0` in `.rdata` | `0` |
| `0x00550c40` | live larger update method | `0` | `1` at `0x006226e4` in `.rdata` | `0` |
| `0x00550d50` | live normal item-list constructor | `2` at `0x0054eb04` and `0x0054f276` | `0` | `0` |

Interpretation:

- The raw helper has no direct branch or table route in the PE.
- The same scan finds expected route evidence for real vtable methods and real constructor calls in the neighborhood, so the scanner is not blind to ordinary xref forms.
- The absence of an absolute VA/RVA hit rejects a missed vtable slot, jump table, static function pointer table, EH scope table, or RTTI-like pointer route for this raw start in the PE image.
- A completely computed call with no stored target address cannot be disproven by static scanning, but no surrounding code or documentation evidence suggests such a mechanism here.

## Heuristic / Inference Reanalysis And Validation

### Helper Name And Signature

Best descriptive candidate if routed:

```cpp
void MenuQuestionDialogLarger::SendSelectionReply(unsigned char selectedValue);
```

Why:

- Receiver fields are `MenuQuestionDialogLarger` fields.
- The only stack argument is the selected row value byte.
- The body sends a reply packet but performs no UI lookup or close.
- `SendSelectionReply` is more precise than `ActionHandler` and less low-level than `PacketNoRouteRaw`.

Rejected names:

- `OnButtonAction`: rejected. The active action handler is [UID:0003W5] and includes selection lookup, navigation cases, and close.
- `SendNavigationPacket`: rejected. Navigation helpers [UID:0001FG] send 10-byte previous/next/current packets and do not include marker `1` or a selected value.
- `PacketBufferWriteSelection`: rejected. PacketBuffer helpers are callees, not owners.
- `MenuQuestionDialogLargerSelectionPacketNoRouteRaw` remains correct as a documentation filename/disposition name because no route is proven.

### Source Placement Alternatives

1. [UID:00007Y] `MenuQuestionDialogLarger` under [UID:0000LA] `MessageDialogs`.
   - Evidence for: receiver fields and packet semantics match the larger menu-question class; the body is physically between larger updater and list constructor; it duplicates the live larger action case-1 send body.
   - Evidence against: no caller, no vtable data ref, no absolute pointer, no RVA pointer, no rel32 route, and no fallthrough. The active handler already inlines behavior.
   - Decision: best hypothetical source owner if route appears, but do not assign now.

2. Shared static helper in `MessageDialogs.cpp`.
   - Evidence for: normal [UID:0003W3] and larger [UID:0003W7] raw helper clones have the same packet body and same field offsets.
   - Evidence against: two duplicate bodies exist rather than one shared function; the calling convention is `__thiscall`; no callers exist to either clone.
   - Decision: plausible original-source pattern only as dead retained per-class out-of-line helpers; not a current owner/emitter route.

3. [UID:0001FG] shared dialog navigation helpers.
   - Evidence for: same opcode and same dialog field family.
   - Evidence against: navigation helpers have direct callers from multiple action handlers and build 10-byte previous/next/current packets; this body is a 12-byte selection reply clone with no route.
   - Decision: rejected as direct owner.

4. [UID:0001HZ] PacketBuffer / [UID:0001HU] QueueAndSendPacket / [UID:0000Q5] g_packetSender.
   - Evidence for: this body calls those helpers/globals.
   - Evidence against: they are generic dependencies with broad fan-in, not feature ownership. The body's receiver and packet fields are dialog-specific.
   - Decision: rejected as source owner.

5. Compiler/linker-generated glue.
   - Evidence for: no route; retained code can happen when function-level linking or dead-stripping is not removing every unreferenced out-of-line source function.
   - Evidence against: packet construction is custom feature logic, not destructor/thunk/EH/runtime pattern.
   - Decision: classify as dead retained source-shaped code, not compiler-generated glue.

### Dead Retained Code Versus Missed Route

Best inference: dead retained out-of-line helper clone.

Reasons:

- The code is source-shaped and semantically useful.
- It mirrors the active larger selection-submit path but omits selected-row lookup and close, exactly the shape of a private helper one might call from action case `1`.
- It has a normal stack-cookie frame and `retn 4`, so it was compiled as a callable body.
- There are two such clones: one for normal menu-question and one for larger menu-question.
- Fresh scan proves there is no ordinary static route to the larger clone, and B001's prior live IDA/PE scan found the same for both clones.

Why not a missed vtable/table route:

- Vtable positive controls are present in `.rdata` for `0x00550b00` and `0x00550c40`.
- No `.rdata`, `.data`, `.text`, or `.rsrc` absolute pointer/RVA to `0x00550c80` exists.
- `0x00550c80` is not part of the preceding switch table; the switch table is the earlier ignored `0x00550c30-0x00550c40` range and points inside the action handler.
- The raw helper is bracketed by `CC` padding, eliminating fallthrough.

### Field / Protocol Names

Recommended target/support doc wording:

- `0x3a`: NPC dialog/menu-question response opcode.
- `this+0x26c`: dialog type/subtype byte.
- `this+0x270`: dialog/object/context id dword.
- `this+0x274`: dialog state word.
- `this+0x276`: page/index word, encoded as `+1` for selection replies.
- marker byte `1`: selection-reply action marker.
- selected byte argument: selected menu row value, matching the first byte of the live list row.
- final local zero: scratch terminator written after the 12-byte payload; not the reason for a 13-byte send.

Avoid raw names such as `dword_67A7EC` and `FUN_005753a0` in source-quality prose when the docs already have better names:

- `g_packetSender` / `Socket *` global for `0x0067a7ec`.
- `QueueAndSendPacket` for `0x00574bb0`.
- `PacketBuffer_WriteByte`, `PacketBuffer_WriteDWORD_BE`, and `PacketBuffer_WriteUInt16BE` for `0x00575380`, `0x005753f0`, and `0x005753a0`.

### Final C++ Decision

Do not populate formal C++ for [UID:0003W7].

Exact no-code proof:

- `RECONSTRUCTABLE:FALSE`.
- `EMITTER_UIDS:` blank.
- No caller/pointer/fallthrough route.
- Live active behavior is already in [UID:0003W5], which is reconstructable and class-owned.
- Emitting this target would create an unreachable duplicate send helper in generated source and would imply a source route the binary does not prove.

If a route is found later, the first-draft body should be a small private method under `MenuQuestionDialogLarger`, not a standalone global:

```cpp
void MenuQuestionDialogLarger::SendSelectionReply(unsigned char selectedValue)
{
    unsigned char packet[13];

    PacketBuffer_WriteByte(0x3a, packet + 0);
    PacketBuffer_WriteByte(m_dialogType, packet + 1);
    PacketBuffer_WriteUInt32BE(m_dialogId, packet + 2);
    PacketBuffer_WriteUInt16BE(m_stateWord, packet + 6);
    PacketBuffer_WriteUInt16BE(m_pageIndex + 1, packet + 8);
    PacketBuffer_WriteByte(1, packet + 10);
    PacketBuffer_WriteByte(selectedValue, packet + 11);
    packet[12] = 0;
    g_packetSender->QueueAndSendPacket(packet, 12);
}
```

This draft is included only to document source shape if a route appears. It must not be entered into [UID:0003W7] while the no-route state remains.

## Ranked Ownership Analysis

### 1. Keep `CANONICAL_OWNER:NONE`, non-emitting raw child - accepted

Evidence for:

- No IDA function metadata in local export; target page and B001 report agree IDA does not model a function.
- Ghidra-only body has zero callers.
- Fresh PE route scan has zero rel32, VA, or RVA hits to `0x00550c80`.
- Boundary bytes eliminate fallthrough.
- Active vtable-routed handler [UID:0003W5] already implements submit behavior.

Evidence against:

- The body is semantically source-shaped and class-specific, so it is not meaningless bytes.

Decision:

- Accepted. This is a retained no-route helper candidate, not emitted reconstructable code.

### 2. Assign to [UID:00007Y] `MenuQuestionDialogLarger` - rejected for now

Evidence for:

- Receiver fields and packet shape match [UID:00007Y].
- Physical neighborhood is the larger menu-question class band.
- If a route is found, this is the correct direct class owner.

Evidence against:

- No route of any checked kind.
- Class already has live [UID:0003W5] action handler for selection submission.
- Assigning it would pollute emitted class source with an uncalled duplicate.

Decision:

- Rejected unless a future route appears.

### 3. Assign to [UID:0000LA] `MessageDialogs` as standalone helper - rejected

Evidence for:

- Source family is definitely `MessageDialogs`.
- Normal/larger duplicate helpers could have been written near the dialog classes.

Evidence against:

- The body is `__thiscall` and reads class offsets, so a class method candidate is stronger than a standalone helper.
- No caller from `MessageDialogs` code exists.

Decision:

- Reject as current owner. Mention `MessageDialogs.cpp` only as the source file that would contain the class method if routed.

### 4. Assign to packet/network infrastructure - rejected

Evidence for:

- Calls PacketBuffer and Socket send helpers.

Evidence against:

- All source-specific state is dialog state.
- PacketBuffer/Socket are dependencies and have many feature callers.

Decision:

- Rejected.

## Negative Evidence Summary

Checked and rejected:

- Direct call/jump route: no `E8`/`E9` or conditional rel32 target to `0x00550c80`.
- Vtable/static pointer route: no absolute VA hit to `0x00550c80`.
- RVA pointer route: no `0x00150c80` hit.
- Switch-table route: the adjacent switch table is `0x00550c30-0x00550c40` and routes inside [UID:0003W5], not to this helper.
- Fallthrough route: three `CC` bytes before target and fifteen `CC` bytes after target.
- Generic helper ownership: rejected because the body reads `MenuQuestionDialogLarger` state fields.
- Compiler padding/table classification: rejected because the body has a full prologue, stack cookie, packet writes, send call, and `retn 4`.
- Source emission: rejected because no route exists and active submit behavior is already emitted through [UID:0003W5].

## Recommended Target Doc Changes

Update `by-memory/0x00550c80-0x00550d41.MenuQuestionDialogLargerSelectionPacketNoRouteRaw.md`:

1. Header metadata:
   - Change `COMPLETION:85` to `COMPLETION:86`.
   - Change `CONFIDENCE:86` to `CONFIDENCE:88`.
   - Keep `CANONICAL_OWNER:NONE`.
   - Keep `RECONSTRUCTABLE:FALSE`.
   - Keep `EMITTER_UIDS:` blank.
   - Keep formal C++ blank.
2. Status:
   - Keep "raw source-shaped no-route code island".
   - Add that it is a Ghidra-only function-shaped body with IDA metadata null.
   - Add no-code proof: no route, no fallthrough, active handler inlines behavior, non-emitting.
3. Behavior:
   - Replace the generic behavior candidate with full packet layout:
     - opcode `0x3a`;
     - `this+0x26c`;
     - `this+0x270`;
     - `this+0x274`;
     - `this+0x276 + 1`;
     - marker byte `1`;
     - selected byte argument;
     - scratch zero after the 12-byte payload;
     - `QueueAndSendPacket(g_packetSender, packet, 12)`;
     - `retn 4`.
4. Route/liveness:
   - Add the fresh B012 PE scan table and positive controls.
   - Add boundary bytes and padding.
   - State that `MenuQuestionDialogLarger::SendSelectionReply(unsigned char selectedValue)` is the best source-facing name only if a route is later proven.
5. Relationship:
   - Add explicit comparison with [UID:0003W5] case `1`.
   - State [UID:0003W5] performs selected-row lookup and close, while [UID:0003W7] sends only the packet from a caller-supplied selected byte.
6. Rejected alternatives:
   - Add rejected owner/source routes: [UID:00007Y] for now, standalone [UID:0000LA] helper, [UID:0001FG], PacketBuffer/Socket ownership, compiler padding, switch table, and emitted final C++.
7. Changes:
   - Add a dated B012 source-routing entry documenting the fresh route scan, score change to `86/88`, and no-code proof.

## Recommended Support Doc Changes

Update [UID:00007Y] `by-class/MenuQuestionDialogLarger.md`:

- In the method/raw helper note, replace "raw packet sender stays non-emitting until ownership is resolved" with a stronger statement:
  - [UID:0003W7] is best understood as a dead retained private helper candidate `SendSelectionReply(unsigned char selectedValue)`.
  - It has no route and must not be emitted.
  - Live [UID:0003W5] action case `1` already inlines selection lookup, packet send, and close.
- Preserve the class score unless the supervisor wants to raise it in a separate class source-quality callback; this task does not require changing [UID:00007Y].

Update [UID:0000LA] `by-file/MessageDialogs.md`:

- Under the `MenuQuestionDialogLarger` / raw no-route helper notes, add:
  - fresh B012 scan found no rel32/VA/RVA route to `0x00550c80`;
  - positive controls found routes for live larger action/update methods;
  - [UID:0003W7] remains no-owner/non-emitting.
- No file score change is required.

Update [UID:0001FH] `by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md`:

- In the split-child row/notes for [UID:0003W7], add a short reference to the fresh B012 route scan and best-if-routed name.
- Keep [UID:0001FH] `RECONSTRUCTABLE:FALSE`, split-index role, and `88/90` score unchanged.

No changes are required to [UID:0003W5] unless the supervisor chooses to do a separate source-quality callback for final action-handler C++; this report only needs [UID:0003W5] as the positive active submit path.

## Exact Callback Implementation Instructions

If the supervisor accepts this report, send B012 an implementation callback with these exact tasks:

1. Lease and update:
   - `by-memory/0x00550c80-0x00550d41.MenuQuestionDialogLargerSelectionPacketNoRouteRaw.md`
   - `by-class/MenuQuestionDialogLarger.md`
   - `by-file/MessageDialogs.md`
   - `by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md`
2. Do not edit `by-memory/-coverage-report.md`; carry the exact replacement row below for supervisor-owned application.
3. Apply target metadata `86/88`, owner/emitter/reconstructable unchanged as no-owner/non-emitting.
4. Incorporate report facts claim-by-claim at report-level detail:
   - raw bytes and boundary padding;
   - Ghidra-only/IDA-null function state;
   - packet layout and field names;
   - active [UID:0003W5] comparison;
   - fresh PE route scan table and positive controls;
   - dead-retained helper inference;
   - best-if-routed helper name;
   - rejected owners/source routes;
   - exact no-code/final-C++ blank proof;
   - score rationale.
5. Do not populate formal C++ for [UID:0003W7]. The only C++ in the target/support docs should be clearly labeled "if a route is ever found" source-shape evidence, not formal reconstruction code.
6. Run the scoped validator commands listed below and report exact results.

## Exact Coverage Text

Replace the current [UID:0003W7] row in `by-memory/-coverage-report.md` with:

```md
        - [UID:0003W7][0x00550c80-0x00550d41.MenuQuestionDialogLargerSelectionPacketNoRouteRaw](by-memory/0x00550c80-0x00550d41.MenuQuestionDialogLargerSelectionPacketNoRouteRaw.md) 0x00550c80-0x00550d41 | no-route raw code island | MenuQuestionDialogLargerSelectionPacketNoRouteRaw : ignored/non-emitting : 86% : strong : Raw source-shaped larger-layout opcode `0x3a` selection-reply helper candidate (`MenuQuestionDialogLarger::SendSelectionReply(unsigned char selectedValue)` if a route is ever found), bracketed by `0xcc` padding and ending `retn 4`; fresh B012 PE scan found no rel32 call/jump, absolute VA, or RVA pointer hits while positive controls found vtable refs for [UID:0003W5][0x00550b00-0x00550c30.MenuQuestionDialogLargerActionHandler](by-memory/0x00550b00-0x00550c30.MenuQuestionDialogLargerActionHandler.md)/[UID:0003W6][0x00550c40-0x00550c7d.MenuQuestionDialogLargerUpdateConfirmButtonState](by-memory/0x00550c40-0x00550c7d.MenuQuestionDialogLargerUpdateConfirmButtonState.md). Live action handler [UID:0003W5] already inlines the active submit-and-close behavior, so keep `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitter/final C++ unless a route appears.
```

No other coverage rows need replacement for this report unless the supervisor separately changes support-doc scores.

## Validation Commands Needed After Implementation

Run from `E:\NTK\GhidraBridge`:

> Executable block R001 was removed from this report and preserved verbatim in [0003W7-MenuQuestionDialogLargerSelectionPacketNoRouteRaw-source-routing-removed.md](0003W7-MenuQuestionDialogLargerSelectionPacketNoRouteRaw-source-routing-removed.md). The archived block is non-authoritative and must not be executed.

After the supervisor applies the banned shared coverage row:

> Executable block R002 was removed from this report and preserved verbatim in [0003W7-MenuQuestionDialogLargerSelectionPacketNoRouteRaw-source-routing-removed.md](0003W7-MenuQuestionDialogLargerSelectionPacketNoRouteRaw-source-routing-removed.md). The archived block is non-authoritative and must not be executed.

No validators were run during this report-only pass because no by-* docs were edited.

## IDA Rename / Type / Comment Recommendations

Do not assign a final IDA function name as live source. If keeping a local label for audit clarity, use:

- `MenuQuestionDialogLargerSelectionPacketNoRouteRaw` at `0x00550c80` as an audit label, not a source method.

If a route is later proven, rename/type to:

```cpp
void __thiscall MenuQuestionDialogLarger::SendSelectionReply(unsigned char selectedValue);
```

Recommended comments:

- At `0x00550c80`: "Ghidra-only source-shaped selection reply helper clone. Sends opcode 0x3a using MenuQuestionDialogLarger fields and caller-selected byte; no IDA xrefs/rel32/VA/RVA route found as of B012 2026-06-19."
- At [UID:0003W5] case `1`: "Active submit path inlines selected-row lookup plus same 0x3a packet send and close; do not route to 0x00550c80 unless a real call/table route appears."

## Open Questions Closed Or Remaining

Closed:

- Source-bearing vs no-code: no-code/non-emitting remains correct.
- Best-if-routed helper name/signature: `MenuQuestionDialogLarger::SendSelectionReply(unsigned char selectedValue)`.
- Packet shape and field meanings: resolved descriptively above.
- Live relationship: [UID:0003W5] is active and already inlines submit-and-close behavior.
- Owner/emitter route: no current owner/emitter; [UID:00007Y] is only hypothetical if route appears.
- Compiler/linker retention: best inference is dead retained source-shaped out-of-line helper clone, not compiler glue.
- Raw boundary: target is bracketed by `CC` padding and ends with `retn 4`.

Remaining:

- Absolute runtime liveness cannot be disproven for hypothetical computed calls with no stored target, but there is no evidence for such a route. This remaining uncertainty is why the page should stay capped below final/near-final scores and remain no-owner/non-emitting.
- Exact original source member names for `this+0x26c/+0x270/+0x274/+0x276` remain descriptive. This does not affect no-code disposition because no emission is recommended.

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B012/research/0003W7-MenuQuestionDialogLargerSelectionPacketNoRouteRaw-source-routing.md`
- Modified: none outside the B012 research folder.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003W7","source_path":"executed-b-agent-research/B012/0003W7-MenuQuestionDialogLargerSelectionPacketNoRouteRaw-source-routing.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
