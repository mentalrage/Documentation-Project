** TARGET-REPORT-UID:00033R **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00033R AddItemDialogSubmitPacketHelper Source-Quality Report

Status: FINISHED

Agent: B003

Target UID: [UID:00033R] `AddItemDialogSubmitPacketHelper`

Target path: `source-3/project-documentation/by-memory/0x004aeab0-0x004aeb30.AddItemDialogSubmitPacketHelper.md`

Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B003/research/00033R-AddItemDialogSubmitPacketHelper-source-quality.md`

Do not edit directly in this report stage:

- `source-3/project-documentation/by-memory/0x004aeab0-0x004aeb30.AddItemDialogSubmitPacketHelper.md`
- support by-* docs
- `source-3/project-documentation/by-memory/-coverage-report.md`

## Executive Recommendation

Keep [UID:00033R] as a reconstructable `AddItemDialog` child emitted through [UID:000007] `AddItemDialog` / [UID:0000KE] `ItemDialogs`.

Recommended metadata for the target:

```text
COMPLETION:88
CONFIDENCE:89
CANONICAL_OWNER:000007
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:000007
```

This clears the current code-entry rule. The target should receive first-draft C++ for both the singleton accessor at `0x004aeab0` and the retained packet helper at `0x004aeac0`. The helper has no direct caller/pointer route in the current binary, but it is source-shaped, exactly within the `AddItemDialog` island, matches the live `AddItemDialog::OnButtonAction` packet-send block, and has a valid narrow owner/emitter. Treat it as a retained private helper/out-of-line copy, not padding and not ExchangeDialog-owned code.

Best current source-facing names:

| Address / item | Recommended name | Confidence |
| --- | --- | --- |
| `0x004aeab0` | `GetActiveAddItemDialog` or `AddItemDialog_GetActive` | Medium-high role, medium original spelling |
| `dword_69B328` | `g_pAddItemDialog` / `g_activeAddItemDialog` | High role, medium original spelling |
| `0x004aeac0` | `AddItemDialog::SendSelectedItemPacket(char selectedInventorySlot)` | High role, medium original spelling |
| `this+0x26c` | `m_exchangeSessionId` for the AddItemDialog exchange-send path; fallback generic name `m_contextId` if final source keeps the base class generic | High for exchange path, medium final class-wide spelling |
| stack argument byte | `selectedInventorySlot` / `inventorySlot` | High |
| `0x00575380` | `PacketBufferWriteUInt8` | High descriptive |
| `0x005753f0` | `PacketBufferWriteUInt32BE` | High descriptive |
| `dword_67A7EC` | `Socket *g_packetSender` | High |
| `0x00574bb0` | `Socket::QueueAndSendPacket(const void *packet, short packetSize)` | High descriptive |

## Evidence Checked

Instruction sources read:

- `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B003/goal.md`
- `source-3/project-documentation/by-structure.md`
- `source-3/project-documentation/inference_research.md`

Target and owner docs read:

- `by-memory/0x004aeab0-0x004aeb30.AddItemDialogSubmitPacketHelper.md`
- `by-memory/0x004ae4c0-0x004aea7d.AddItemDialogCore.md`
- `by-memory/0x004aea80-0x004aeab0.AddItemDialogExchangePacketCloseHandler.md`
- `by-class/AddItemDialog.md`
- `by-file/ItemDialogs.md`
- `by-memory/0x004ae4c0-0x004b0ba5.ItemExchangeMixDialogs.md`
- `by-type/by-vtable/AddItemDialogVtables.md`
- `by-memory/0x0069b328-0x0069b330.ItemDialogSingletonGlobals.md`

Sibling/helper docs read:

- `by-class/AddItemWithCountDialog.md`
- `by-memory/0x004af040-0x004af4b7.AddItemWithCountDialogCore.md`
- `by-memory/0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper.md`
- `by-memory/0x004afb80-0x004afcc0.MixItemDialogSubmitPacketHelper.md`
- `by-memory/0x004aec80-0x004aec8e.MyItemListPaneGetSelectedSlotIndex.md`
- `by-class/MyItemListPane.md`
- `by-file/MyItemListPane.md`
- `by-item/PacketBufferHelpers.md`
- `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md`
- `by-global/g_packetSender.md`
- `by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md`
- `by-memory/0x004ada90-0x004adb02.ExchangeDialogAddItemWithCountHelper.md`
- `by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md`
- `by-class/ExchangeDialog.md`

Local binary evidence checked against:

```text
E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
MD5: 4247E04E20B65D6414C7238AA8FF5515
SHA256: 9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632
Image base: 0x00400000
```

Commands used included targeted PowerShell `rg`/`Get-Content`, Python PE scans, and Capstone disassembly. No by-* docs or coverage docs were edited.

## Exact Target Bytes And Range

`0x004aeab0-0x004aeb30` splits cleanly:

| Range | Role |
| --- | --- |
| `0x004aeab0-0x004aeab6` | accessor body: `mov eax, [0x0069b328]; ret` |
| `0x004aeab6-0x004aeac0` | ten `0xcc` bytes |
| `0x004aeac0-0x004aeb2f` | retained helper body with normal prologue, stack cookie, `ret 4` |
| `0x004aeb2f-0x004aeb30` | one `0xcc` byte before `MyItemListPane` constructor |

Disassembly facts for the retained helper:

```asm
004aeac0  push   ebp
004aeac1  mov    ebp, esp
004aeac3  sub    esp, 0x44
004aeac6  mov    eax, dword ptr [0x672f24]
004aeacb  xor    eax, ebp
004aeacd  mov    dword ptr [ebp - 4], eax
004aead0  push   esi
004aead1  lea    eax, [ebp - 0x44]
004aead4  mov    esi, ecx
004aead6  push   eax
004aead7  push   0x4a
004aead9  call   0x575380
004aeade  lea    eax, [ebp - 0x43]
004aeae1  push   eax
004aeae2  push   1
004aeae4  call   0x575380
004aeae9  lea    eax, [ebp - 0x42]
004aeaec  push   eax
004aeaed  push   dword ptr [esi + 0x26c]
004aeaf3  call   0x5753f0
004aeaf8  lea    eax, [ebp - 0x3e]
004aeafb  push   eax
004aeafc  movsx  eax, byte ptr [ebp + 8]
004aeb00  push   eax
004aeb01  call   0x575380
004aeb06  mov    ecx, dword ptr [0x67a7ec]
004aeb0c  lea    eax, [ebp - 0x44]
004aeb0f  add    esp, 0x20
004aeb12  mov    byte ptr [ebp - 0x3d], 0
004aeb16  push   7
004aeb18  push   eax
004aeb19  call   0x574bb0
004aeb1e  mov    ecx, dword ptr [ebp - 4]
004aeb21  xor    ecx, ebp
004aeb23  pop    esi
004aeb24  call   0x5c772f
004aeb29  mov    esp, ebp
004aeb2b  pop    ebp
004aeb2c  ret    4
004aeb2f  int3
```

Packet layout:

| Offset | Value | Evidence |
| --- | --- | --- |
| `packet[0]` | `0x4A` | `PacketBufferWriteUInt8(0x4a, packet)` |
| `packet[1]` | `1` | `PacketBufferWriteUInt8(1, packet + 1)` |
| `packet[2..5]` | `this+0x26c`, big-endian | `PacketBufferWriteUInt32BE([esi+0x26c], packet + 2)` |
| `packet[6]` | stack argument byte | `movsx eax, byte ptr [ebp+8]`, then byte writer at `packet+6` |
| `packet[7]` | explicit zero scratch terminator | `mov byte ptr [ebp-0x3d], 0` |
| send length | `7` | `push 7`, `QueueAndSendPacket` |

Important correction: the explicit zero at `packet[7]` is a scratch/terminator byte and is not part of the transmitted packet because the helper sends length `7`.

## Route And Liveness Evidence

PE-wide direct route scan results:

```text
VA 004aeab0 file_off=0xadeb0
  abs dword hits 0
  rva dword hits 0
  raw-offset dword hits 0
  rel32 call/jmp/jcc hits 0

VA 004aeac0 file_off=0xadec0
  abs dword hits 0
  rva dword hits 0
  raw-offset dword hits 0
  rel32 call/jmp/jcc hits 0

VA 004aeb2f file_off=0xadf2f
  abs dword hits 0
  rva dword hits 0
  raw-offset dword hits 0
  rel32 call/jmp/jcc hits 0
```

Positive controls from the same scan:

```text
VA 004aeb30 file_off=0xadf30
  rel32 call/jmp/jcc hits 4:
    0x0048a50d, 0x004ae63e, 0x004ae7f0, 0x004af7a7

VA 004ae4c0 file_off=0xad8c0
  rel32 call/jmp/jcc hits 5:
    0x004a339f, 0x004a4aee, 0x004ad124, 0x004af924, 0x004b0031

VA 004ae930 file_off=0xadd30
  abs dword hits 1: 0x00619ed4
  rel32 call/jmp/jcc hits 1: 0x004a4b60

VA 004aec80 file_off=0xae080
  rel32 call/jmp/jcc hits 2: 0x0048a733, 0x0048b6ae

VA 0069b328 file_off=0x298f28
  abs dword hits 7:
    0x004ad672, 0x004ade34, 0x004ae8d4, 0x004ae91c,
    0x004aeab1, 0x004b0932, 0x004b0992

VA 0067a7ec file_off=0x2783ec
  abs dword hits 489
```

Conclusion:

- No direct rel32 caller, jump, conditional branch, absolute pointer, RVA pointer, raw-file-offset pointer, or end-pointer route was found to `0x004aeab0`, `0x004aeac0`, or `0x004aeb2f`.
- No fallthrough route exists: the accessor ends at `ret`, is followed by `0xcc`, the retained helper ends at `ret 4`, and the successor `0x004aeb30` has normal callers as `MyItemListPane`.
- The target is still source-shaped and valuable. It is adjacent to AddItemDialog code, uses AddItemDialog state, matches a live AddItemDialog action-send block, and follows the same retained raw-helper pattern as [UID:00033T] and [UID:00033V].
- The correct source-shape statement is "retained/no-direct-xref private helper or out-of-line clone", not "dead padding", "compiler glue", or "ExchangeDialog method".

## Caller/Inline Relationship

The live `AddItemDialog::OnButtonAction` at `0x004ae930` contains an inline equivalent block for action id `1`. It fetches selected rows from the embedded item list, resolves each row payload through `0x004f3dc0`, reads payload byte `+0`, then builds and sends the same `0x4A/1` packet.

Relevant disassembly:

```asm
004ae970  push    3
004ae972  mov     eax, dword ptr [ecx]
004ae974  call    dword ptr [eax + 0x10]
004ae977  push    0x100
004ae97c  mov     eax, dword ptr [eax]
004ae97e  mov     ebx, dword ptr [eax + 0x108]
004ae984  lea     eax, [ebp - 0x444]
004ae98a  push    eax
004ae98b  mov     ecx, ebx
004ae993  call    0x4f3e80
004ae998  xor     edi, edi
004ae9a0  test    eax, eax
004ae9a2  jle     0x4aea19
004ae9b0  push    dword ptr [ebp + edi*4 - 0x444]
004ae9b7  mov     ecx, ebx
004ae9b9  call    0x4f3dc0
004ae9be  mov     bl, byte ptr [eax]
004ae9c0  lea     eax, [ebp - 0x44]
004ae9c3  push    eax
004ae9c4  push    0x4a
004ae9c6  call    0x575380
004ae9cb  lea     eax, [ebp - 0x43]
004ae9ce  push    eax
004ae9cf  push    1
004ae9d1  call    0x575380
004ae9d6  lea     eax, [ebp - 0x42]
004ae9d9  push    eax
004ae9da  push    dword ptr [esi + 0x26c]
004ae9e0  call    0x5753f0
004ae9e5  lea     eax, [ebp - 0x3e]
004ae9e8  push    eax
004ae9e9  movsx   eax, bl
004ae9ec  push    eax
004ae9ed  call    0x575380
004ae9f2  mov     ecx, dword ptr [0x67a7ec]
004ae9f8  lea     eax, [ebp - 0x44]
004ae9fb  add     esp, 0x20
004ae9fe  mov     byte ptr [ebp - 0x3d], 0
004aea02  push    7
004aea04  push    eax
004aea05  call    0x574bb0
004aea0a  mov     ebx, dword ptr [ebp - 0x44c]
004aea10  inc     edi
004aea17  jl      0x4ae9b0
004aea1d  call    0x49eb90
004aea24  call    0x49dad0
```

This resolves the argument role: the helper's stack byte is the selected inventory slot byte from the `MyItemListPane` row payload, the same byte documented by [UID:0002JP] `MyItemListPaneGetSelectedSlotIndex`.

## Packet Semantics

`0x4A` is the client-to-server exchange action opcode in this dialog family:

- `0x4A/1`: add selected item by inventory slot, this target.
- `0x4A/2`: add selected item with count, [UID:00033T] `AddItemWithCountDialogSubmitPacketHelper`.
- `0x4A/3`: submit money amount in `ExchangeDialog`.
- `0x4A/4`: cancel/close exchange in `ExchangeDialog`.

The `this+0x26c` field is strongest as `m_exchangeSessionId` for the exchange packet path. Evidence:

- `ExchangeDialog::OnButtonAction` allocates `AddItemDialog` and calls `0x004ae4c0` with `push 1; push [esi+0x26c]` at `0x004ad11a-0x004ad124`.
- `ExchangeDialog` docs identify its own `+0x26c` as the exchange session id.
- `MixItemDialog` and `AddMixingItemDialog` pass `0` when reusing the `AddItemDialog` base constructor and then install derived vtables, so the field can be zero/unused outside the exchange-send path.

Recommended final wording: "`this+0x26c` is the AddItemDialog exchange/context id, best current name `m_exchangeSessionId` for the `0x4A` packet path; use generic `m_contextId` only if final source keeps the base picker deliberately exchange-neutral."

## Ownership And Source Placement

Ownership ranking:

1. [UID:000007] `AddItemDialog`: direct owner. The helper uses `AddItemDialog` state at `this+0x26c`, sits immediately after AddItemDialog's close handler, and duplicates AddItemDialog action-handler packet construction.
2. [UID:0000KE] `ItemDialogs`: source-file route. Existing proposed source tree and `by-file/ItemDialogs.md` place `AddItemDialog`, `AddItemWithCountDialog`, `MixItemDialog`, and singleton globals in the item-dialog module.
3. [UID:0000J9] `ExchangeDialog`: caller/consumer only. Exchange creates `AddItemDialog` with its exchange id and consumes server updates, but it does not own the reusable item-picker implementation.
4. [UID:0000M8] `PacketBuffer` / [UID:0000NS] `Socket`: helper dependencies only.
5. No owner / padding / compiler glue: rejected. The raw body is a normal project helper with packet semantics, security cookie, AddItemDialog field access, and a real send path.

Source file route:

- Keep generated output under `auto-generated/NexusTK/ui/dialogs/ItemDialogs.cpp`.
- Do not split this helper into `ExchangeDialog.cpp`.
- Do not move `MyItemListPane` ownership into the target; the target only consumes row payload bytes.

## First-Draft C++ Recommendation

Populate the target's formal C++ block with a source-level draft. This code intentionally uses descriptive names, not proven original spellings.

```cpp
AddItemDialog *GetActiveAddItemDialog()
{
    return g_pAddItemDialog;
}

void AddItemDialog::SendSelectedItemPacket(char selectedInventorySlot)
{
    unsigned char packet[8];

    PacketBufferWriteUInt8(0x4A, packet);
    PacketBufferWriteUInt8(1, packet + 1);
    PacketBufferWriteUInt32BE(m_exchangeSessionId, packet + 2);
    PacketBufferWriteUInt8(selectedInventorySlot, packet + 6);

    packet[7] = 0;
    g_packetSender->QueueAndSendPacket(packet, 7);
}
```

Alternative if the final source header keeps the picker base exchange-neutral:

```cpp
void AddItemDialog::SendSelectedItemPacket(char selectedInventorySlot)
{
    unsigned char packet[8];

    PacketBufferWriteUInt8(0x4A, packet);
    PacketBufferWriteUInt8(1, packet + 1);
    PacketBufferWriteUInt32BE(m_contextId, packet + 2);
    PacketBufferWriteUInt8(selectedInventorySlot, packet + 6);

    packet[7] = 0;
    g_packetSender->QueueAndSendPacket(packet, 7);
}
```

No-code proof is not recommended here. The only no-code argument is lack of a direct route, but the target is already a reconstructable source helper island with an owner/emitter and an inline equivalent live path. Record the no-xref route caveat in prose while still providing first-draft source for the helper body.

## Recommended Target Doc Changes

In `by-memory/0x004aeab0-0x004aeb30.AddItemDialogSubmitPacketHelper.md`:

1. Update metadata to `COMPLETION:88`, `CONFIDENCE:89`; keep owner/emitter/reconstructable as `000007`/`TRUE`/`000007`.
2. Replace "no final C++ emitted because helper not modeled/source-facing packet name inferred" with a current note: "First-draft C++ is now appropriate; names are descriptive and no-direct-route is documented."
3. Add a "Route and liveness" section:
   - no IDA ordinary caller known for `0x004aeab0` or `0x004aeac0`;
   - local PE scan found no rel32 call/jump/jcc, VA dword, RVA dword, raw-offset pointer, or end-pointer route;
   - no fallthrough from accessor/padding or into successor `MyItemListPane`;
   - live `AddItemDialog::OnButtonAction` contains an inline equivalent send block.
4. Replace packet prose with exact layout:
   - opcode `0x4A`;
   - subtype `1`;
   - big-endian `m_exchangeSessionId`/context dword from `this+0x26c`;
   - selected inventory slot byte from stack argument;
   - zero scratch terminator at byte 7 not included in the 7-byte send.
5. Add source-facing names:
   - `GetActiveAddItemDialog`;
   - `AddItemDialog::SendSelectedItemPacket(char selectedInventorySlot)`;
   - `g_pAddItemDialog`/`g_activeAddItemDialog`;
   - `Socket *g_packetSender`;
   - `PacketBufferWriteUInt8`, `PacketBufferWriteUInt32BE`, `Socket::QueueAndSendPacket`.
6. Add relationship to siblings:
   - [UID:00033Q] action handler contains inline equivalent for action id `1`;
   - [UID:000317] is the server close handler for `0x42/0x04`;
   - [UID:00033T] sends the sibling count-aware `0x4A/2` packet;
   - [UID:00014T] remains the mixed container, not the target owner.
7. Populate the C++ block with the draft above.

## Recommended Support Doc Changes

`by-class/AddItemDialog.md`:

- In `Class Shape`, change the provisional `+0x26c` wording to: "`+0x26c`: exchange/context id used by the `0x4A` add-item packet path; ExchangeDialog passes its `m_exchangeSessionId`, while mix-derived paths pass zero and install derived vtables."
- In `Method Notes`, update [UID:00033R] row to: "Active singleton accessor plus retained/no-direct-xref private send helper; best source name `SendSelectedItemPacket(char selectedInventorySlot)`, builds client exchange packet `0x4A/1` from `m_exchangeSessionId` and selected inventory slot, queues 7 bytes through `g_packetSender`."
- In evidence notes, add that PE scans found no static route to `0x004aeac0`, and `0x004ae930` contains the inline equivalent selected-row send loop.
- Score can remain `85/89`; a small raise to `86/90` is defensible only if the class page also receives the field/method-name cleanup.

`by-memory/0x004ae4c0-0x004aea7d.AddItemDialogCore.md`:

- Expand the `0x004ae930` action handler row:
  "Action id `1` iterates selected item rows, resolves each row payload through the list helper, reads payload byte `+0x00` as selected inventory slot, builds the same `0x4A/1` packet as [UID:00033R], queues 7 bytes, then closes the dialog."
- Add `this+0x26c` as the exchange/context id used by the action send path.
- Add [UID:00033R] cross-reference in the action evidence.

`by-file/ItemDialogs.md`:

- Update the `AddItemDialog` proposed contents entry to name the retained helper:
  "`AddItemDialog::SendSelectedItemPacket(char selectedInventorySlot)` / `GetActiveAddItemDialog`, retained helper/accessor island at `0x004aeab0-0x004aeb30`; sends client exchange opcode `0x4A/1` with exchange session/context id and selected inventory slot. No direct route to the retained helper start has been found; live action handler inlines the equivalent send loop."
- Keep `AddItemDialog` in `ItemDialogs.cpp`; do not migrate to `ExchangeDialog.cpp`.

`by-memory/0x004ae4c0-0x004b0ba5.ItemExchangeMixDialogs.md`:

- Update the [UID:00033R] row to mention no-direct-route and inline-equivalent evidence:
  "`dword_69B328` accessor plus retained `0x4A/1` AddItemDialog selected-inventory-slot send helper; PE scans find no direct caller/pointer route, while `AddItemDialog::OnButtonAction` contains an inline equivalent."
- No aggregate owner/emitter change.

`by-memory/0x0069b328-0x0069b330.ItemDialogSingletonGlobals.md`:

- For `0x0069b328`, add recommended source names `g_pAddItemDialog` / `g_activeAddItemDialog`.
- Add that `0x004aeab0` is a no-direct-route accessor for the slot, not evidence for a broader global structure.

`by-memory/0x004aec80-0x004aec8e.MyItemListPaneGetSelectedSlotIndex.md`:

- Add cross-reference that [UID:00033R] and the live `AddItemDialog::OnButtonAction` send path consume the same row payload byte as the selected inventory slot for exchange add-item packet `0x4A/1`.

`by-item/PacketBufferHelpers.md`, `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md`, and `by-global/g_packetSender.md`:

- No required edits. They already support the source-facing names and zero-terminator caveat. Optional cross-reference from those broad docs to [UID:00033R] is not necessary.

## Exact Pending Coverage Row

Do not edit `by-memory/-coverage-report.md` in this report-only phase. If the report is accepted and the target metadata changes, replace the existing [UID:00033R] row with:

```text
        - [UID:00033R][0x004aeab0-0x004aeb30.AddItemDialogSubmitPacketHelper](by-memory/0x004aeab0-0x004aeb30.AddItemDialogSubmitPacketHelper.md) 0x004aeab0-0x004aeb30 | singleton/raw packet helper | AddItemDialogSubmitPacketHelper : reconstructable : 88% : strong : Assigned to [UID:000007][AddItemDialog](by-class/AddItemDialog.md); covers the no-direct-route `g_pAddItemDialog`/`dword_69B328` accessor at `0x004aeab0`, `0x004aeab6-0x004aeac0` padding, and retained raw helper `0x004aeac0-0x004aeb2f` that builds client exchange packet `0x4A/1` with exchange/session context and selected inventory slot byte, writes an unsent scratch terminator, and queues 7 bytes through `g_packetSender`; direct PE scans found no caller/pointer route, while `AddItemDialog::OnButtonAction` contains an inline equivalent send loop.
```

The auto-generated memory coverage table row should remain structurally the same but will reflect the target's updated scores after validator/autogen.

## Implementation Checklist For Supervisor Callback

1. Edit `by-memory/0x004aeab0-0x004aeb30.AddItemDialogSubmitPacketHelper.md`.
   - Apply metadata `88/89`.
   - Add route/liveness, packet layout, source-name, ownership, and inline-equivalence sections.
   - Add first-draft C++.
2. Edit support docs if accepted:
   - `by-class/AddItemDialog.md`
   - `by-memory/0x004ae4c0-0x004aea7d.AddItemDialogCore.md`
   - `by-file/ItemDialogs.md`
   - `by-memory/0x004ae4c0-0x004b0ba5.ItemExchangeMixDialogs.md`
   - `by-memory/0x0069b328-0x0069b330.ItemDialogSingletonGlobals.md`
   - optional: `by-memory/0x004aec80-0x004aec8e.MyItemListPaneGetSelectedSlotIndex.md`
3. Do not edit `by-memory/-coverage-report.md`; include row above for supervisor/shared coverage handling.
4. Run validators.

## Validation Commands

Run from `source-3/project-documentation` after implementation:

> Executable block R001 was removed from this report and preserved verbatim in [00033R-AddItemDialogSubmitPacketHelper-source-quality-removed.md](00033R-AddItemDialogSubmitPacketHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the optional `MyItemListPaneGetSelectedSlotIndex` support note is edited:

> Executable block R002 was removed from this report and preserved verbatim in [00033R-AddItemDialogSubmitPacketHelper-source-quality-removed.md](00033R-AddItemDialogSubmitPacketHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If generated memory coverage is rebuilt by the supervisor/validator workflow, verify that the target row reflects `88/89` and that no manual change was made to `by-memory/-coverage-report.md`.

## IDA Rename, Type, And Comment Recommendations

Function and data names:

| Address | Recommendation | Confidence |
| --- | --- | --- |
| `0x004aeab0` | Rename to `GetActiveAddItemDialog` or `AddItemDialog_GetActive` | Medium-high |
| `0x004aeac0` | Create/rename function as `AddItemDialog::SendSelectedItemPacket` | High for role, medium original spelling |
| `0x0069b328` | Rename data to `g_pAddItemDialog` or `g_activeAddItemDialog` | High role, medium original spelling |
| `0x0067a7ec` | Keep `g_packetSender`, type `Socket *` | High |
| `0x00575380` | `PacketBufferWriteUInt8` | High descriptive |
| `0x005753f0` | `PacketBufferWriteUInt32BE` | High descriptive |
| `0x00574bb0` | `Socket::QueueAndSendPacket` | High descriptive |

Suggested IDA function type:

```cpp
void __thiscall AddItemDialog::SendSelectedItemPacket(char selectedInventorySlot);
AddItemDialog *__cdecl GetActiveAddItemDialog(void);
```

Suggested field/type notes:

```cpp
// AddItemDialog +0x26c:
// exchange/session context id for client exchange opcode 0x4A packet paths.
// ExchangeDialog passes its m_exchangeSessionId; mix-derived paths pass zero
// and replace the virtual action behavior.
```

Suggested comments:

- At `0x004aeac0`: "Retained/no-direct-xref AddItemDialog selected-item send helper. Builds client exchange packet `0x4A/1`: exchange id/context dword + selected inventory slot. Inline equivalent exists in `AddItemDialog::OnButtonAction` at `0x004ae9c0-0x004aea05`."
- At `0x004aeb12`: "Writes scratch terminator at packet[7]; send length is 7, so this byte is not transmitted."
- At `0x004aeab0`: "Accessor for active AddItemDialog singleton slot `0x0069b328`; no direct route found in PE scan."

## Open Questions And Best Current Answers

| Question | Current answer |
| --- | --- |
| Is `0x004aeac0` live? | No direct route found. Treat as retained/no-direct-xref private helper or out-of-line clone. Do not call it proven-live, but do not treat it as padding. |
| Should formal C++ remain blank? | No. The target clears the current reconstructable/emitter/score gate, has exact behavior, and source-shape caveat can be documented. First-draft C++ is appropriate. |
| Is `this+0x26c` exchange-specific or generic context? | Strongest evidence is exchange session id in the `0x4A` path. Use `m_exchangeSessionId` for this helper; keep `m_contextId` as fallback if final source keeps `AddItemDialog` generic. |
| Is the signed byte a count, subtype, row id, or item id? | It is the selected inventory slot byte from `MyItemListPane` row payload offset `+0x00`. It is sign-extended because the original source type was likely `char`; transmitted value is the low byte. |
| Is `0x4A/1` AddItemDialog-owned or ExchangeDialog-owned? | AddItemDialog-owned implementation under `ItemDialogs`; ExchangeDialog supplies the exchange id and consumes the protocol but does not own this picker helper. |
| Should the range split further? | No new by-memory split is required. The target can document accessor, padding, retained helper, and final padding as one small AddItemDialog helper island. |
| Does `0x004aeab0` prove singleton getter liveness? | No direct route found. It is still a normal accessor-shaped body and should be named/documented with the same no-direct-route caveat as the raw helper. |

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/00033R-AddItemDialogSubmitPacketHelper-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:28","uid":"00033R"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00033R-AddItemDialogSubmitPacketHelper-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/00033R-AddItemDialogSubmitPacketHelper-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00033R"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
