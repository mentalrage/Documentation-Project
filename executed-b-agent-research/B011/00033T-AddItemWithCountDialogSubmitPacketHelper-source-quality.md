** TARGET-REPORT-UID:00033T **
** AUTHOR-AGENT-ID:B011 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00033T AddItemWithCountDialogSubmitPacketHelper Source-Quality Report

## FINISHED Recommendation

- Assignment: B011 source-quality / heuristic research for [UID:00033T] `AddItemWithCountDialogSubmitPacketHelper`.
- Target page: `source-3/project-documentation/by-memory/0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper.md`.
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B011/research/00033T-AddItemWithCountDialogSubmitPacketHelper-source-quality.md`.
- Current target state: `COMPLETION:85`, `CONFIDENCE:86`, `CANONICAL_OWNER:000008`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000008`, blank formal C++.
- Recommendation: keep owner/emitter [UID:000008] `AddItemWithCountDialog`, keep `RECONSTRUCTABLE:TRUE`, raise to `COMPLETION:86`, `CONFIDENCE:90`, and keep formal `RECONSTRUCTION_CPP CODE` blank for now.
- Final disposition: `0x004af4f0-0x004af570` is real source-shaped AddItemWithCountDialog packet helper code, not padding, not compiler glue, and not Socket/CashShop-owned packet infrastructure. It serializes the same count-aware add-item submit packet that the live action handler at `0x004af380` already builds inline.
- Formal-C++ policy: do not populate the target C++ block yet. The concrete blocker is not the old `95/95` rule and not missing behavior. The blocker is source shape: raw PE scans find no exact branch, no absolute VA/RVA pointer, no vtable slot, and no table route to `0x004af4f0`, while [UID:00033S] action handler `0x004af380-0x004af47a` already contains the equivalent packet send inline and then closes the dialog.

## Evidence Checked

- Instructions and local rules:
  - `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`.
  - `source-3/project-documentation/tools/leaser/Agents/Agent-B011/goal.md`.
  - `.codex/AGENTS.md`.
  - `source-3/project-documentation/by-structure.md`.
  - `source-3/project-documentation/inference_research.md`.
  - `source-3/project-documentation/by-project-structure/proposed-source-tree.md`.
- Target and direct supports:
  - [UID:00033T] `by-memory/0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper.md`.
  - [UID:00033S] `by-memory/0x004af040-0x004af4b7.AddItemWithCountDialogCore.md`.
  - [UID:000318] `by-memory/0x004af4c0-0x004af4f0.AddItemWithCountDialogExchangePacketCloseHandler.md`.
  - [UID:000008] `by-class/AddItemWithCountDialog.md`.
  - [UID:0000KE] `by-file/ItemDialogs.md`.
  - [UID:00014T] `by-memory/0x004ae4c0-0x004b0ba5.ItemExchangeMixDialogs.md`.
  - [UID:0003IE] `by-type/by-vtable/AddItemWithCountDialogVtables.md`.
  - [UID:0003NI] `by-memory/0x0061a374-0x0061a37c.AddItemWithCountDialogQuantityFormatString.md`.
- Related packet/helper context:
  - [UID:00014M] `by-memory/0x004ada90-0x004adb02.ExchangeDialogAddItemWithCountHelper.md`.
  - B003 executed report `tools/leaser/Agents/Agent-B003/research/executed/00014M-ExchangeDialogAddItemWithCountHelper-source-quality.md`.
  - [UID:00033R] `by-memory/0x004aeab0-0x004aeb30.AddItemDialogSubmitPacketHelper.md`.
  - [UID:00033V] `by-memory/0x004afb80-0x004afcc0.MixItemDialogSubmitPacketHelper.md`.
  - [UID:0000Q5] `by-global/g_packetSender.md`.
  - [UID:0001HU] `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md`.
  - [UID:0003YJ] `by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md`.
  - [UID:0000M8] `by-file/PacketBuffer.md`.
  - [UID:0000V1] `by-item/PacketBufferHelpers.md`.
- Generated/current-state checks:
  - `auto-generated/-ag-memory-coverage.md` current [UID:00033T] row.
  - `auto-generated/NexusTK/ui/dialogs/ItemDialogs.cpp`, which currently has an empty emitter marker for [UID:00033T].
  - `project-level/-auto-completion-stats.md`, current `00033T` average `85.5`.
  - `by-memory/-coverage-report.md` current [UID:00033T] row. This report does not edit it.
- IDA MCP status:
  - Tried local MCP `tools/list` at `http://127.0.0.1:13337/mcp`.
  - Result: unavailable in this session, `Unable to connect to the remote server`.
  - Impact: this report uses existing MCP-backed docs as prior evidence and adds direct raw PE/Capstone verification. No IDA database edits were attempted.
- Raw executable checked:
  - `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
  - Size: `2679296`.
  - MD5: `4247E04E20B65D6414C7238AA8FF5515`.
  - SHA256: `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`.
  - PE image base: `0x00400000`.
  - `.text`: `0x00401000-0x0060c600`, raw offset `0x400`, raw size `0x20b600`.
  - Capstone version: `5.0.7`.
- Integer conversions checked with `tools/int_convert.py` where decimal values are used:
  - `0x80` is decimal `128` (Verified with int_convert.py).
  - `0x274` is decimal `628` (Verified with int_convert.py).
  - `0x26c` is decimal `620` (Verified with int_convert.py).
  - `0x270` is decimal `624` (Verified with int_convert.py).
  - `0x4a` is decimal `74` (Verified with int_convert.py).
  - `0xff` is decimal `255` (Verified with int_convert.py).
  - `0x08` is decimal `8` (Verified with int_convert.py).

## Raw PE / Capstone Findings

### Target Body

Capstone disassembly of `0x004af4f0-0x004af570` confirms one contiguous, function-shaped helper:

```text
0x004af4f0  push ebp
0x004af4f1  mov ebp, esp
0x004af4f3  sub esp, 0x24
0x004af506  push packet
0x004af507  push 0x4a
0x004af509  call 0x00575380
0x004af512  push 2
0x004af514  call 0x00575380
0x004af51d  push dword ptr [esi+0x26c]
0x004af523  call 0x005753f0
0x004af52c  movsx eax, byte ptr [esi+0x270]
0x004af534  call 0x00575380
0x004af53d  movzx eax, byte ptr [ebp+8]
0x004af542  call 0x00575380
0x004af547  mov ecx, dword ptr [0x0067a7ec]
0x004af553  mov byte ptr [packet+8], 0
0x004af557  push 8
0x004af559  push packet
0x004af55a  call 0x00574bb0
0x004af565  call 0x005c772f
0x004af56d  ret 4
```

- Exact range: `0x004af4f0-0x004af570`, size `0x80` / 128 bytes (Verified with int_convert.py).
- It starts immediately after [UID:000318] returns at `0x004af4ed-0x004af4f0`; there is no padding between the packet-close handler and this helper.
- It ends at `ret 4` ending at `0x004af570`; [UID:00033U]/`MixItemDialog` constructor starts immediately at `0x004af570`.
- It has a normal security-cookie frame and `__thiscall` receiver in `ecx`.
- Stack argument `[ebp+8]` is consumed as one unsigned byte and sent as the count field.

### Packet Semantics

The actual sent payload is exactly eight bytes:

```text
packet[0]   = 0x4a
packet[1]   = 0x02
packet[2:6] = PacketBufferWriteUInt32BE(this->m_exchangeSessionId)
packet[6]   = this->m_selectedItemType
packet[7]   = count
```

The explicit zero at `packet[8]` is an out-of-band scratch terminator/safety byte, not a protocol field and not included in the `QueueAndSendPacket(..., 8)` length. This uses the PacketBuffer convention documented by [UID:0003YJ]/[UID:0000V1]: scalar write helpers leave a trailing zero after the counted payload. Therefore the current target wording that lists a "zero terminator" inside an eight-byte packet is misleading and should be corrected.

Resolved raw helper names:

- `0x00575380` / `sub_575380`: `PacketBufferWriteUInt8(value, dst)`.
- `0x005753f0` / `sub_5753F0`: `PacketBufferWriteUInt32BE(value, dst)`.
- `0x0067a7ec` / `dword_67A7EC`: [UID:0000Q5] `g_packetSender`, best current source-facing type `Socket *`.
- `0x00574bb0` / `sub_574BB0`: [UID:0001HU] `Socket::QueueAndSendPacket`.

### Active Action Handler Duplicate

Capstone disassembly of [UID:00033S] action handler `0x004af380-0x004af47a` shows the live confirm path already builds and sends the same packet inline:

- Button/action dispatch goes to `0x004af3c1` for confirm.
- It obtains child selector `4`, converts/parses text with the wide `"%hu"` format string at [UID:0003NI] `0x0061a374`.
- It clamps parsed values at `0xff` / 255 (Verified with int_convert.py).
- It writes `0x4a`, subtype `2`, `this+0x26c`, `this+0x270`, and the clamped count byte through the same PacketBuffer helpers.
- It queues exactly `0x08` / 8 bytes (Verified with int_convert.py) through `g_packetSender` / `Socket::QueueAndSendPacket`.
- It then calls the normal dialog close/remove helpers at `0x0049eb90` and `0x0049dad0`.

This action-handler body is not a call to `0x004af4f0`; it is an inline duplicate of the raw helper's serialization with the additional parse/clamp and close behavior.

### Constructor And Field Evidence

Capstone disassembly of `0x004af040-0x004af371` confirms the constructor stores:

- First constructor argument `[ebp+8]` to `this+0x26c`.
- Second constructor argument `[ebp+0xc]` low byte to `this+0x270`.

Constructor callers remain the two exchange paths already documented:

- `0x004ad3bf`: live [UID:00014L] dispatcher subcommand `1`.
- `0x004adaeb`: retained [UID:00014M] `ExchangeDialog::OpenAddItemWithCountDialog` helper.

Both caller paths pass the ExchangeDialog exchange/session id plus the selected item/type byte from exchange packet `packet+2`. The count is not a constructor argument and is not stored at `this+0x270`; it is entered later by the user, parsed in `0x004af380`, clamped, and passed as the raw helper's stack argument when that out-of-line helper shape is considered.

Best field names:

- `this+0x26c`: `m_exchangeSessionId` or `m_exchangeId`; high confidence for role, medium-high for exact original spelling.
- `this+0x270`: `m_selectedItemType`, `m_selectedItemToken`, or `m_itemType`; high confidence for role as the selected item/type byte from exchange packet `packet+2`, medium for exact original spelling.

### Route / Liveness Scans

Raw PE scans found:

- Exact rel32 branch/call target to `0x004af4f0`: `0` hits.
- Exact absolute VA literal `0x004af4f0`: `0` hits.
- Exact RVA literal `0x000af4f0`: `0` hits.
- Exact vtable/data pointer to `0x004af4f0`: `0` hits.
- Capstone/raw branch scan positive controls found two real rel32 constructor calls to `0x004af040`: `0x004ad3bf` and `0x004adaeb`.
- Vtable data positive controls found `0x004af380` at `0x0061a034` and `0x004af4c0` at `0x0061a05c`; no vtable slot points to `0x004af4f0`.
- A sliding raw rel32 scan found no exact-start displacement to `0x004af4f0`. Non-start interior matches were coincidental byte-window false positives or inside the target/neighboring instruction streams, not decoded inbound transfers.

Conclusion: `0x004af4f0` is a retained raw helper body with no defensible active static route in the current binary. Lack of IDA function promotion is not a blocker by itself; the positive policy is to document it as source-shaped, AddItemWithCountDialog-owned, reconstructable retained helper code with formal C++ blank until the retained-helper versus inline-action source integration is decided.

## Heuristic / Source-Quality Decisions

### Source Placement And Ownership

Keep [UID:00033T] under [UID:000008] `AddItemWithCountDialog`, emitted through [UID:0000KE] `ItemDialogs`.

Evidence for:

- It reads the AddItemWithCountDialog receiver fields `this+0x26c` and `this+0x270`.
- It serializes the count-aware add-item packet for the dialog's confirm path.
- It is physically between AddItemWithCountDialog packet-close handler and MixItemDialog constructor, inside the ItemDialogs address island.
- [UID:00033S] action handler contains the same packet send and is vtable-routed as AddItemWithCountDialog action behavior.
- [UID:00014M] and [UID:00014L] are only construction/opening paths; they do not own this dialog's submit behavior.

Rejected alternatives:

- `CANONICAL_OWNER:NONE` / no-code: rejected because the body is ordinary source-like packet construction, not compiler-only glue.
- Socket/CashShop owner: rejected because `g_packetSender` and `QueueAndSendPacket` are infrastructure callees; they do not own feature packet construction.
- ExchangeDialog owner: rejected because ExchangeDialog constructs the dialog and supplies context/item token, but the submit helper reads AddItemWithCountDialog fields and serializes the user's later count.
- Padding/alignment: rejected by complete prologue/body/cookie/send/ret and sibling raw helper pattern.

### Packet Opcode / Subtype Semantics

Best semantics:

- `0x4a` is the exchange client opcode used by exchange dialog item/money/cancel submit paths.
- Subtype `1` is the no-count `AddItemDialog` selected-item submit path in [UID:00033R].
- Subtype `2` is the count-aware `AddItemWithCountDialog` selected-item submit path in [UID:00033T] and inline in [UID:00033S].
- The dword at `this+0x26c` is the exchange/session context.
- The byte at `this+0x270` is the selected item/type token supplied by the exchange server packet.
- The stack argument is the user-entered count after parse and clamp, not the packet length, not the selected item/type byte, and not the exchange id.

### Relationship To Aggregate And Support Docs

- [UID:00014T] already mostly repaired the stale aggregate padding claim: its current split table says `0x004af4f0-0x004af570` is a real opcode `0x4a/2` helper. It should be enriched, not reversed.
- [UID:0000KE] `ItemDialogs.md` still has a support-table gap: its `AddItemWithCountDialog` row lists `0x004af040-0x004af4f0` with the packet-close child and omits [UID:00033T]. It should include the raw helper through `0x004af570`, or explicitly list [UID:00033T] as the retained no-route submit helper.
- [UID:000008] `AddItemWithCountDialog.md` already mentions [UID:00033T], but should distinguish the live inline action handler from the no-route retained helper and should remove any implication that the scratch zero is a sent packet field.
- [UID:00033S] should document that `0x004af380` duplicates [UID:00033T]'s packet serialization inline. This is important for the formal C++ decision.
- [UID:0003IE] `AddItemWithCountDialogVtables.md` does not need a required change. It already records action and packet-close slots; the correct evidence is that no vtable slot routes to [UID:00033T].

## Recommended Metadata

Recommended [UID:00033T] metadata:

```text
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000008 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000008 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Score rationale:

- Raise completion from `85` to `86` because this pass resolves the current 85/85 gate wording, exact packet layout, scratch-zero semantics, helper naming, field roles, count argument, no-route evidence, action-handler duplication, and support-doc gaps.
- Raise confidence from `86` to `90` because raw PE/Capstone independently confirms the body, boundaries, packet bytes, field uses, positive constructor-call controls, vtable non-route, and no exact inbound route.
- Do not raise higher because original helper name/signature and retained-helper emission policy remain inferred, and no active static route reaches the helper start.
- Keep owner/emitter unchanged. The direct source owner remains [UID:000008] `AddItemWithCountDialog`; file route remains [UID:0000KE] `ItemDialogs`.
- Keep formal C++ blank for now. The target may still be represented as a retained out-of-line clone if the broader source-rebuild policy wants binary-byte coverage for unreferenced helpers, but that is an integration decision, not a behavior blocker.

No required score change is recommended for [UID:000008], [UID:00033S], [UID:0000KE], [UID:00014T], or [UID:0003IE]. Optional support text should remove stale gate/padding wording.

## First-Draft C++ Readiness

Do not paste C++ into [UID:00033T]'s formal block yet.

Concrete blocker:

- No static route reaches `0x004af4f0`.
- The live action handler at `0x004af380-0x004af47a` already serializes this exact packet inline, including parse/clamp and close behavior.
- Emitting [UID:00033T] as a standalone method now would likely add an unreferenced duplicate helper unless the broader ItemDialogs reconstruction chooses to rewrite the action handler to call this helper, or explicitly keeps retained no-route helper bodies for binary parity.

Review-only draft shape if supervisor later chooses retained-helper emission:

```cpp
// Descriptive source shape only. Do not paste into RECONSTRUCTION_CPP
// until the retained-helper versus inline-action policy is decided.
void AddItemWithCountDialog::SendSelectedItemWithCountPacket(unsigned char count)
{
    unsigned char packet[9];

    PacketBufferWriteUInt8(0x4a, packet);
    PacketBufferWriteUInt8(2, packet + 1);
    PacketBufferWriteUInt32BE(m_exchangeSessionId, packet + 2);
    PacketBufferWriteUInt8(m_selectedItemType, packet + 6);
    PacketBufferWriteUInt8(count, packet + 7);
    packet[8] = 0;

    g_packetSender->QueueAndSendPacket(packet, 8);
}
```

Draft caveats:

- `SendSelectedItemWithCountPacket`, `m_exchangeSessionId`, and `m_selectedItemType` are descriptive names, not proven original spellings.
- `packet[8] = 0` models the scratch terminator outside the sent length, not a protocol byte.
- If final source emits only the action handler, [UID:00033S] should contain the active C++ and [UID:00033T] should remain a retained helper note with blank formal C++.

## Exact Recommended Implementation Checklist

### Target [UID:00033T]

Apply the metadata change to `86/90`, preserve owner/emitter/reconstructable, and keep formal C++ blank.

Add or replace target evidence with this content:

```text
## 2026-06-19 B011 Source-Quality Recheck

B011 rechecked `0x004af4f0-0x004af570` against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` (MD5 `4247E04E20B65D6414C7238AA8FF5515`, SHA256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`) after IDA MCP was unavailable in-session. Raw PE/Capstone disassembly confirms an exact `0x80` / 128-byte source-shaped helper body (Verified with int_convert.py), starting immediately after [UID:000318] ends at `0x004af4f0` and ending with `ret 4` at `0x004af56d-0x004af570` before `MixItemDialog` starts.

The helper serializes eight sent bytes: opcode `0x4a`, subtype `2`, big-endian dword `this+0x26c`, byte `this+0x270`, and byte stack argument count. The explicit zero at packet offset `8` is a scratch terminator outside the `QueueAndSendPacket(..., 8)` length, not an additional protocol field. `this+0x26c` is the exchange/session id supplied by the ExchangeDialog constructor paths, `this+0x270` is the selected item/type token from exchange packet `packet+2`, and the stack argument is the user-entered count after [UID:00033S] parses `"%hu"` and clamps to `0xff` / 255 (Verified with int_convert.py).

Raw route scans found no exact rel32 branch/call to `0x004af4f0`, no full-file absolute VA literal `0x004af4f0`, no RVA literal `0x000af4f0`, and no vtable/data pointer to this helper. Positive controls found the two real constructor calls to `0x004af040` at `0x004ad3bf` and `0x004adaeb`, plus vtable pointers to the action handler `0x004af380` and packet-close handler `0x004af4c0`. The live action handler at `0x004af380-0x004af47a` already emits the same packet inline and closes the dialog, so formal C++ stays blank pending retained-helper versus inline-action integration. This is a target-specific source-shape blocker under the current combined-score/emitter policy, not the old `95/95` no-code rule.
```

Replace the behavior summary so the packet is described as:

```text
Builds and sends the eight-byte payload `{ 0x4a, 2, be32(exchange/session id), selected item/type byte, count byte }`; the zero written at the next byte is an out-of-band scratch terminator and is not sent.
```

Recommended stale wording replacement:

```text
Formal C++ remains blank even though the target clears the current combined-score/emitter minimum after this recheck. The blocker is source integration: no static branch/table/vtable route reaches `0x004af4f0`, and [UID:00033S] action handler `0x004af380-0x004af47a` already contains the equivalent packet serialization inline.
```

### [UID:00033S] AddItemWithCountDialogCore

Add a short support note under IDA evidence or ownership:

```text
- 2026-06-19 B011 rechecked [UID:00033T] and confirmed `0x004af380-0x004af47a` contains the active inline submit path: it reads count text from child selector `4`, parses `"%hu"`, clamps to `0xff` / 255 (Verified with int_convert.py), writes opcode `0x4a`, subtype `2`, `this+0x26c`, `this+0x270`, and the clamped count byte, sends exactly eight bytes through `g_packetSender` / `Socket::QueueAndSendPacket`, and then closes the dialog. [UID:00033T] is a retained no-route helper with the same packet serialization but no close path.
```

### [UID:000008] AddItemWithCountDialog

Update the `SubmitPacketHelper` method row:

```text
| `SubmitPacketHelper` | [UID:00033T][0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper](by-memory/0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper.md) | Retained no-route raw helper that serializes the count-aware selected-item packet `{ 0x4a, 2, exchange/session id, selected item/type, count }`; [UID:00033S] action handler contains the equivalent active send inline, so formal helper C++ remains blank pending retained-helper policy. |
```

Add/update evidence:

```text
- 2026-06-19 B011 raw PE/Capstone recheck confirms [UID:00033T] is real helper code, not padding, but has no exact branch/VA/RVA/vtable route to `0x004af4f0`. The helper reads `this+0x26c` as exchange/session id and `this+0x270` as selected item/type byte, accepts a one-byte count argument, sends eight bytes through `g_packetSender` / `Socket::QueueAndSendPacket`, and writes a scratch zero outside the sent payload. The live action handler [UID:00033S] already builds the same packet inline after parsing and clamping the count.
```

If the class coverage row is refreshed, replace its stale `95/95` wording with current source-shape wording. Exact optional by-class coverage row:

```text
- [UID:000008][AddItemWithCountDialog](by-class/AddItemWithCountDialog.md) : reconstructable : 85% : strong : Quantity-aware item add dialog attached to [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md); live constructor/action/update ranges, exchange constructor call sites, vtable/action-slot refs, stored exchange/session id at `this+0x26c`, selected item/type byte at `this+0x270`, count parse/clamp, and opcode `0x4a/2` packet serialization are documented. B011 recheck confirms [UID:00033T] is real no-route helper code while [UID:00033S] contains the active inline send; class-level C++ remains blank because final control/member names and retained-helper versus inline-action integration remain unresolved under the current combined-score/emitter policy.
```

### [UID:0000KE] ItemDialogs

Update the `AddItemWithCountDialog` contents row so the raw helper is not omitted:

```text
| `AddItemWithCountDialog` | `0x004af040-0x004af570`; exact packet-close child [UID:000318][0x004af4c0-0x004af4f0.AddItemWithCountDialogExchangePacketCloseHandler](by-memory/0x004af4c0-0x004af4f0.AddItemWithCountDialogExchangePacketCloseHandler.md) and retained submit helper [UID:00033T][0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper](by-memory/0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper.md) | `class_AddItemWithCountDialog.cpp` | Quantity-aware item add dialog with packet-close handling and count-aware opcode `0x4a/2` submit serialization. |
```

Add a boundary note:

```text
- [UID:00033T] `0x004af4f0-0x004af570` is retained AddItemWithCountDialog submit helper code, not aggregate padding. It has no static route to the helper start in raw PE scans, while [UID:00033S] action handler duplicates the packet send inline; keep it documented under ItemDialogs but leave formal helper C++ blank until retained-helper policy is decided.
```

### [UID:00014T] ItemExchangeMixDialogs

The current aggregate already rejects the stale padding claim. Optional enrichment:

```text
| [UID:00033T][0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper](by-memory/0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper.md) | `AddItemWithCountDialog` retained raw submit helper | Real opcode `0x4a/2` packet helper; B011 confirms no static route to helper start and confirms [UID:00033S] action handler duplicates the same eight-byte submit payload inline. |
```

### [UID:0003IE] Vtable Support

No required change. If touched, add only this negative-route note:

```text
- No AddItemWithCountDialog vtable slot points to [UID:00033T] `0x004af4f0`; action slot `0x0061a034` points to [UID:00033S] `0x004af380`, and packet-close slot `0x0061a05c` points to [UID:000318] `0x004af4c0`.
```

## Coverage Report Replacement Text

Do not edit `source-3/project-documentation/by-memory/-coverage-report.md` directly in this report-only task.

Replace the current [UID:00033T] row with:

```text
        - [UID:00033T][0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper](by-memory/0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper.md) 0x004af4f0-0x004af570 | raw packet helper | AddItemWithCountDialogSubmitPacketHelper : reconstructable : 86% : strong : B011 PE/Capstone recheck confirms exact `0x80` / 128-byte source-shaped raw helper body (Verified with int_convert.py), no exact branch/VA/RVA/vtable route to `0x004af4f0`, opcode `0x4a` subtype `2` eight-byte payload `{opcode, subtype, exchange/session id, selected item/type, count}`, PacketBufferWriteUInt8/PacketBufferWriteUInt32BE and `g_packetSender` / `Socket::QueueAndSendPacket` dependencies, scratch zero outside the sent length, fields `this+0x26c` exchange/session id and `this+0x270` selected item/type byte, one-byte count argument supplied by the parsed/clamped action path, and active [UID:00033S] action handler duplication of the same send inline. Keep owner/emitter [UID:000008], keep reconstructable, and keep formal C++ blank until retained-helper versus inline-action integration is decided; stale padding and stale `95/95` no-code explanations are rejected.
```

## Validation Commands After Implementation

Run from `source-3/project-documentation` after applying accepted changes:

> Executable block R001 was removed from this report and preserved verbatim in [00033T-AddItemWithCountDialogSubmitPacketHelper-source-quality-removed.md](00033T-AddItemWithCountDialogSubmitPacketHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the optional by-class coverage row is updated, also run:

> Executable block R002 was removed from this report and preserved verbatim in [00033T-AddItemWithCountDialogSubmitPacketHelper-source-quality-removed.md](00033T-AddItemWithCountDialogSubmitPacketHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Autogen refresh is recommended because the [UID:00033T] score changes and the empty emitter marker should reflect updated metadata, even though owner/emitter/reconstructable state does not structurally change.

## IDA Rename / Type / Comment Recommendations

No IDA edits were performed. Recommended if an IDA update pass is later allowed:

- Promote/create a function at `0x004af4f0` only if the project accepts raw no-route retained helpers as functions. Suggested name: `AddItemWithCountDialog_SendSelectedItemWithCountPacket` or `AddItemWithCountDialog::SendSelectedItemWithCountPacket`. Confidence: medium-high for role, medium for original name.
- Add a comment at `0x004af4f0`: "Retained no-route helper; action handler `0x004af380` builds the same `0x4a/2` packet inline. No exact branch/VA/RVA/vtable route found in B011 PE scan."
- Rename/type `sub_575380` as `PacketBufferWriteUInt8(unsigned value, unsigned char *dst)`. Confidence: high; PacketBuffer support docs already accept this direction.
- Rename/type `sub_5753F0` as `PacketBufferWriteUInt32BE(unsigned value, unsigned char *dst)`. Confidence: high.
- Normalize `dword_67A7EC` references to `g_packetSender` / `Socket *`. Confidence: high for storage and broad type, medium-high for exact header spelling.
- Normalize `sub_574BB0` references to `Socket::QueueAndSendPacket(const void *packet, int length)` or equivalent. Confidence: high for role, medium-high for exact signature.
- Add structure/member comments on AddItemWithCountDialog:
  - `+0x26c`: `m_exchangeSessionId` / exchange-session context dword. Confidence: high for role.
  - `+0x270`: `m_selectedItemType` / selected item-type token byte. Confidence: high for role, medium for name.
- Add a comment to `0x004af380` confirm path: "Active source route for count-aware submit; parse `%hu`, clamp to 255, send `0x4a/2` with exchange id, item/type, count, then close."

## Remaining Open Questions

- Original helper spelling is not proven. Best descriptive name is `SendSelectedItemWithCountPacket` or `SendSubmitPacket`; do not claim original-name proof.
- Final ItemDialogs C++ integration must decide whether to:
  - keep [UID:00033S] action handler inline and leave [UID:00033T] as retained no-route helper documentation with blank formal C++;
  - rewrite the action handler source to call a private helper and emit [UID:00033T] as that helper; or
  - preserve unreferenced retained helper bodies for binary parity.
- Exact final member names for `this+0x26c`, `this+0x270`, inherited child selector `4`, and the packet helper API remain below final-source confidence. Their roles are no longer behavior blockers.
- IDA MCP was unavailable. The report's recommendation does not depend on an unverified MCP-only claim; raw PE/Capstone evidence plus existing MCP-backed docs were sufficient. A later IDA pass can rerun `lookup_funcs`, `xrefs_to`, `xref_query`, and `decompile` for `0x004af4f0`, `0x004af380`, and `0x004af040`.

## Changed Files

- Created:
  - `source-3/project-documentation/tools/leaser/Agents/Agent-B011/research/00033T-AddItemWithCountDialogSubmitPacketHelper-source-quality.md`
- Modified:
  - None outside the Agent-B011 research folder.
- Not edited:
  - by-* target/support docs.
  - generated files.
  - `source-3/project-documentation/by-memory/-coverage-report.md`.
  - IDA database.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B011","command_id":"000000004165","destination_path":"executed-b-agent-research/B011/00033T-AddItemWithCountDialogSubmitPacketHelper-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:34","uid":"00033T"} -->
<!-- {"agent":"B011","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00033T-AddItemWithCountDialogSubmitPacketHelper-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B011/00033T-AddItemWithCountDialogSubmitPacketHelper-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00033T"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
