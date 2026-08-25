** TARGET-REPORT-UID:00049Q **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B003 Report - UID00049Q ExchangeDialogOnButtonAction Source Quality

TARGET-REPORT-UID:00049Q

Assignment: `B003-report-00049Q-ExchangeDialogOnButtonAction-source-quality-20260629`

Target: [UID:00049Q] `by-memory/0x004ad0b0-0x004ad1ca.ExchangeDialogOnButtonAction.md`

Report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B003\research\00049Q-ExchangeDialogOnButtonAction-source-quality.md`

Mode: report-only research. No leases were taken during the research phase. No by-* target/support docs, generated docs, project docs, or IDB state were edited during that phase.

Implementation callback update, 2026-06-29:

- Supervisor accepted this report for implementation callback and B003 applied the accepted target/support edits.
- B003 leased and edited the required by-* files: `by-memory/0x004ad0b0-0x004ad1ca.ExchangeDialogOnButtonAction.md`, `by-memory/0x004ad900-0x004ad95f.ExchangeDialogSendCancelPacket.md`, `by-class/ExchangeDialog.md`, `by-file/ExchangeDialog.md`, and `by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md`.
- Current MCP session `46666bf7` was rechecked during callback by `idb_list`, `server_health`, `lookup_funcs`, `xrefs_to`, and `analyze_function` for UID00049Q/UID00049U before implementation.
- Validators ran with `--wait-generated`; generated refresh completed through validator tooling, not by hand.
- Final generated freshness proof: `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp` has current observed `validator-command-id: 000000000931`, refreshed at `2026-06-29T16:30:49-04:00`, contains UID00049Q `ExchangeDialog::OnButtonAction` at lines `7`/`8`, contains UID00049U `ExchangeDialog::SendCancelPacket` at lines `207`/`208`, and has no UID00049Q/UID00049U empty-emitter marker.

## Executive Recommendation

Promote UID00049Q from a blank-emitter source-bearing child to first-draft C++ emission through [UID:00004R] `ExchangeDialog`.

Recommended target metadata:

| Field | Current | Recommended |
| --- | --- | --- |
| `COMPLETION` | `83` | `87` |
| `CONFIDENCE` | `86` | `89` |
| `CANONICAL_OWNER` | `00004R` | unchanged |
| `RECONSTRUCTABLE` | `TRUE` | unchanged |
| `EMITTER_UIDS` | blank | `00004R` |
| `EMITTER_POSITION_OPTIONAL` | blank | unchanged |

Reason: current IDA MCP session `46666bf7` resolves all named blockers in the current target page. The vtable route, exact range, action ids, packet helper names, `AddItemDialog` constructor shape, `g_pUserPane +0x3ec0` gate, and the support cancel helper are now sufficiently documented for implementation-ready first-draft source. Original constant/member spellings remain descriptive rather than final, but that is no longer a code-entry blocker under the current by-* reconstruction standard.

Support edit required: promote [UID:00049U] `by-memory/0x004ad900-0x004ad95f.ExchangeDialogSendCancelPacket.md` to emit `ExchangeDialog::SendCancelPacket()` through the same `00004R` route. UID00049Q action id `3` calls this helper, so UID00049Q should not be implemented while UID00049U remains a blank C++ dependency.

## Current Target State

Current target page state before implementation:

- UID: `00049Q`
- Range: `0x004ad0b0-0x004ad1ca`
- Completion/confidence: `83/86`
- Canonical owner: [UID:00004R] `ExchangeDialog`
- Emitter route: blank
- Reconstructable: `TRUE`
- Formal C++: blank
- Current blocker text: exact control-id names, button callback contract, packet helper declarations, and `AddItemDialog` interaction source shape remain descriptive.

Related current pages:

- [UID:00004R] `by-class/ExchangeDialog.md` already owns `OnButtonAction`, `SendCancelPacket`, packed exchange state, and the `m_exchangeSessionId` field at `+0x26c`.
- [UID:0000J9] `by-file/ExchangeDialog.md` already routes `ExchangeDialog.cpp` under `NexusTK/ui/dialogs/`.
- [UID:00049U] `by-memory/0x004ad900-0x004ad95f.ExchangeDialogSendCancelPacket.md` currently remains blank-emitter `83/87`.
- [UID:000007] `by-class/AddItemDialog.md` and [UID:00033Q] `AddItemDialogCore` already document that `ExchangeDialog::OnButtonAction` calls the `AddItemDialog` constructor with `m_exchangeSessionId` and mode/action `1`.

## Current IDA MCP Evidence

Fresh session requirement was satisfied. I used only fresh IDA MCP session `46666bf7`; stale session `978e78c8` was not used.

Listener/process/call details:

- JSON-RPC endpoint: `http://127.0.0.1:13337/mcp`
- `idb_list`: one active session, `session_id=46666bf7`, path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `filename=NexusTK.exe.i64`, `is_active=true`, `is_analyzing=false`, `backend=worker`, `owned=true`, `adopted=true`, `pid=20688`, `worker_pid=20688`.
- `server_health(database=46666bf7)`: `status=ok`, module `NexusTK.exe`, `idb_path=E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready with size `2067`.

Bounded MCP calls used:

- `lookup_funcs(database=46666bf7, queries=[0x004ad0b0, 0x004ad1c9, 0x004ad1ca, 0x004ad1d0, 0x004ad900, 0x004ad960, 0x004ae4c0, 0x004af040, 0x004ada90, 0x004ad320, 0x00619d74])`
- `xrefs_to(database=46666bf7, addrs=[0x004ad0b0, 0x004ad1d0, 0x004ad900, 0x004ad960, 0x004ae4c0, 0x004af040, 0x00619d74])`
- `callees(database=46666bf7, addrs=[0x004ad0b0])`
- `analyze_function(database=46666bf7, addr=0x004ad0b0, include_asm=false)`
- `decompile(database=46666bf7, addr=0x004ad0b0, include_addresses=true)`
- `disasm(database=46666bf7, addr=0x004ad0b0, max_instructions=180, include_total=true)`
- `decompile(database=46666bf7, addr=0x004ad900, include_addresses=true)`
- `analyze_function(database=46666bf7, addr=0x004ad900, include_asm=false)`
- `int_convert(database=46666bf7, inputs=[0x11a, 0x4A, 0x274, 0x26c, 0x270])`

Key function/range facts:

- `lookup_funcs 0x004ad0b0`: `sub_4AD0B0`, size `0x11a`; `int_convert` confirms `0x11a` is 282 decimal.
- `lookup_funcs 0x004ad1c9`: still inside `sub_4AD0B0`.
- `lookup_funcs 0x004ad1ca`: not a function, supporting the half-open target end.
- `lookup_funcs 0x004ad1d0`: next modeled function `sub_4AD1D0`, size `0x24`.
- `xrefs_to 0x004ad0b0`: exactly one data xref at `0x00619d74`, no ordinary code callers. This is the ExchangeDialog vtable action slot.
- `analyze_function 0x004ad0b0`: prototype rendered as `__int16 *__thiscall(int this, int, int)`, size 282, no strings, no constants, callees `sub_4AD900`, `sub_4F4AA0`, `sub_4AE4C0`, `sub_575380`, `sub_5753F0`, `sub_574BB0`, and `@__security_check_cookie@4`, 14 basic blocks, cyclomatic complexity 4.

Key behavior facts from decompile/disasm:

- The first stack argument is the action id. The second stack argument is unused. The function returns with `retn 8`.
- Action id `1` builds a six-byte client exchange packet:
  - opcode byte `0x4A` (`int_convert` decimal `74`);
  - subcommand `4` when `byte ptr [dword_67A748 + 0x3ec0] != 0`;
  - subcommand `5` when that byte is zero;
  - big-endian dword from `this+0x26c`;
  - local-only zero at packet offset `6`;
  - send length `6` through `dword_67A7EC` / `QueueAndSendPacket`;
  - then writes `byte ptr [this+0x270] = 1`.
- Action id `2` allocates `0x270` bytes at `0x004ad0fb-0x004ad100`, pushes `1`, pushes `[esi+0x26c]`, and calls `sub_4AE4C0` at `0x004ad124`, which is the documented `AddItemDialog` constructor.
- Action id `3` calls `sub_4AD900` at `0x004ad0f1`.
- `sub_4AD900` decompiles as a one-block `ExchangeDialog::SendCancelPacket` helper: writes opcode `0x4A`, subcommand `4`, big-endian `this[155]` (`this+0x26c`), local zero at packet offset `6`, and sends six bytes through `dword_67A7EC` / `QueueAndSendPacket`.
- `xrefs_to 0x004ad900`: exactly one code xref from `0x004ad0f1` inside UID00049Q.
- `xrefs_to 0x004ae4c0`: includes `0x004ad124` from UID00049Q, plus other documented item-dialog construction sites.
- `xrefs_to 0x004af040`: only dispatcher/helper contexts `0x004ad3bf` and `0x004adaeb`; UID00049Q does not directly construct `AddItemWithCountDialog`.

Key numeric conversions:

- `0x11a` = 282, target byte size.
- `0x4A` = 74, client exchange opcode.
- `0x274` = 628, `AddItemWithCountDialog` allocation size from related support, not used directly by UID00049Q.
- `0x26c` = 620, exchange/session id field.
- `0x270` = 624, first packed state byte, documented as local offer/ready-request state.

## Existing Report And Documentation Search

No direct executed B-agent report exists for `TARGET-REPORT-UID:00049Q`.

Relevant prior reports used as leads:

- `executed-b-agent-research/B001/00014K-ExchangeDialog-empty-emitter-source-quality.md`
  - Created UID00049Q as a vtable-routed exact child at `83/86`, blank emitter/C++.
  - Recorded vtable xref `0x00619d74 -> 0x004ad0b0`.
  - Listed the original blockers: control-id names, packet helper names, and `AddItemDialog` interaction source shape.
- `executed-b-agent-research/B015/00014L-ExchangeDialogPacketDispatcher-source-quality.md`
  - Resolved `ExchangeDialog` server opcode `0x42` dispatcher first-draft C++.
  - Established descriptive field names `m_exchangeSessionId`, `m_localOfferPending`, `m_localReadyConfirmed`, and `m_peerReadyConfirmed`.
  - Confirmed `AddItemWithCountDialog` construction belongs to dispatcher case `1`, not UID00049Q.
- `executed-b-agent-research/B003/00033R-AddItemDialogSubmitPacketHelper-source-quality.md`
  - Confirms UID00049Q's `0x004ad124` constructor call to `AddItemDialog` with `push 1; push [esi+0x26c]`.
  - Confirms `AddItemDialog` owns selected-item packet `0x4A/1`; UID00049Q only opens the picker.
- `executed-b-agent-research/B011/00033T-AddItemWithCountDialogSubmitPacketHelper-source-quality.md`
  - Confirms count-aware add-item flow is an `AddItemWithCountDialog` concern opened by dispatcher/helper contexts, not by UID00049Q.

Current support docs also already resolve the raw helper names:

- [UID:0003YJ] `PacketBufferScalarBigEndianWriteHelpers`: `sub_575380` is `PacketBufferWriteUInt8`; `sub_5753F0` is `PacketBufferWriteUInt32BE`; both write a local spare zero byte.
- [UID:0001HU] `QueueAndSendPacket`: `sub_574BB0` is the Socket-owned queue/send funnel.
- [UID:0000Q5] `g_packetSender`: `dword_67A7EC` is source-facing `Socket *g_packetSender`; generated `g_pCashShopRequest` aliases are rejected.
- [UID:0000QK] `g_pCollectionData` alias page and [UID:0001OR] memory page: `dword_67A748` is canonical source-facing `UserPane *g_pUserPane`; `+0x3ec0` is the item/gold command busy gate, best field name `m_itemCommandBusy`.

## Positive Evidence

Ownership:

- UID00049Q uses `this+0x26c`, `this+0x270`, ExchangeDialog action semantics, and the ExchangeDialog vtable slot at `0x00619d74`.
- [UID:00004R] already clears the owner gate and documents this function as `ExchangeDialog::OnButtonAction`.
- [UID:0000J9] already routes `ExchangeDialog.cpp` as the source file.

Code shape:

- The range is a complete source-shaped virtual method: normal MSVC prologue, stack cookie, exception cleanup for the possible allocation path, three explicit action cases, and clean `retn 8`.
- Action ids are exact: `1`, `2`, `3`. They match the existing target summary of OK/confirm, add-item, and cancel buttons.
- Packet helper names are no longer blockers. `PacketBufferWriteUInt8`, `PacketBufferWriteUInt32BE`, `g_packetSender->QueueAndSendPacket`, and `g_pUserPane->m_itemCommandBusy` are all documented in current support pages.
- `AddItemDialog` interaction is source-ready: UID00049Q allocates the base `AddItemDialog` with exchange id and mode `1`; the selected-item packet is owned by `AddItemDialog`, not by UID00049Q.

Support helper:

- UID00049Q action id `3` has a single direct call to `0x004ad900`.
- `0x004ad900` has one caller, one basic block, exact packet behavior, and a clear method role: `ExchangeDialog::SendCancelPacket()`.
- Promoting UID00049Q without UID00049U would introduce a missing source dependency. Promoting both as a target/support pair is the implementation-ready repair.

## Negative Evidence

- There are no ordinary code callers to UID00049Q. This is expected for a vtable-routed virtual and supports, rather than weakens, the `OnButtonAction` classification.
- `lookup_funcs 0x004ad1ca` returns not a function, and `0x004ad1d0` starts the next method. Do not expand or split the target range.
- UID00049Q does not call `AddItemWithCountDialog`; current xrefs to `0x004af040` are from the server dispatcher and retained helper, not from the button handler.
- The `AddItemDialog` constructor body and selected-item packet helper belong to [UID:000007] / [UID:0000KE] `ItemDialogs`. Do not move item picker implementation into `ExchangeDialog.cpp`.
- `dword_67A748` should not be documented as a collection-only object or emitted under a `g_pCollectionData` final name in this target. The current source-facing view is `g_pUserPane`.
- The second action-handler stack argument is unused. Do not invent behavior for it; keep it as `int /*unused*/`.
- Do not hand-edit generated tracker/coverage files after the implementation. Let validators/generation refresh them.

## Ownership And Source Placement

Ranked owner/source placement:

1. [UID:00004R] `ExchangeDialog` / [UID:0000J9] `ExchangeDialog.cpp` in `NexusTK/ui/dialogs/`:
   - Direct vtable slot, ExchangeDialog fields, ExchangeDialog session id, ExchangeDialog ready state, and existing class/file routing all agree.
2. [UID:0000J9] file page as direct owner:
   - Correct source file route but not the direct semantic owner. Keep as file route, not `CANONICAL_OWNER`.
3. [UID:000007] `AddItemDialog`:
   - Dependency only. UID00049Q constructs it; `AddItemDialog` owns picker internals and selected-item submit behavior.
4. [UID:0000NS] `Socket` / packet support:
   - Owns `g_packetSender` and queue/send helper, not ExchangeDialog button behavior.
5. No-owner / non-reconstructable:
   - Rejected. The target is custom UI/protocol source with a valid class and file route.

Recommended source placement:

- UID00049Q: emit `void ExchangeDialog::OnButtonAction(int actionId, int /*unused*/)` through [UID:00004R] into [UID:0000J9] `ExchangeDialog.cpp`.
- UID00049U support: emit `void ExchangeDialog::SendCancelPacket()` through [UID:00004R] into the same source route.

## Split, Range, And Liveness Analysis

No target split is needed.

- Target start `0x004ad0b0` is a modeled function start.
- Target end `0x004ad1ca` is half-open and exact: `0x004ad1c9` is still in the function, `0x004ad1ca` is not a function, and the next method starts at `0x004ad1d0`.
- The post-target span `0x004ad1ca-0x004ad1d0` remains padding/alignment.
- The vtable data xref at `0x00619d74` is the live route.

No new child page is required.

- Action id `3` reaches existing exact child [UID:00049U] `0x004ad900-0x004ad95f.ExchangeDialogSendCancelPacket`.
- Action id `2` reaches existing [UID:00033Q] `AddItemDialogCore`.
- Action id `1` is inline packet construction inside UID00049Q.

## Source-Quality Blocker Audit

| Blocker from current UID00049Q page | Resolution |
| --- | --- |
| Exact control-id names | IDs are exact and behaviorally mapped: `1` confirm/ready request, `2` open add-item picker, `3` cancel. Original symbolic spellings remain unproven, but numeric IDs plus descriptive names are enough for first-draft C++ and match accepted dialog-action precedent. |
| Button callback contract | Current MCP and comparable action-handler docs support `void ExchangeDialog::OnButtonAction(int actionId, int /*unused*/)`. The decompiler return is expression pollution from constructor/helper calls; `retn 8` and the unused second arg match other dialog action handlers. |
| Packet helper declarations | Resolved by [UID:0003YJ], [UID:0001HU], and [UID:0000Q5]. Use `PacketBufferWriteUInt8`, `PacketBufferWriteUInt32BE`, and `g_packetSender->QueueAndSendPacket`. |
| AddItemDialog source shape | Resolved. UID00049Q constructs `AddItemDialog(m_exchangeSessionId, 1)` and does not own the picker body or selected-item packet. |
| `dword_67A748 + 0x3ec0` identity | Resolved as `g_pUserPane->m_itemCommandBusy`, a UserPane/local-player item-command busy gate. |
| Support cancel helper | Resolved by promoting UID00049U with first-draft `ExchangeDialog::SendCancelPacket()`. |

No in-scope source-quality blocker remains unresolved.

## First-Draft C++ Recommendation

Target UID00049Q formal block recommendation:

```cpp
void ExchangeDialog::OnButtonAction(int actionId, int /*unused*/)
{
    if (actionId == 1) {
        unsigned char packet[7];

        PacketBufferWriteUInt8(0x4A, packet);

        if (g_pUserPane->m_itemCommandBusy != 0) {
            PacketBufferWriteUInt8(4, packet + 1);
        } else {
            PacketBufferWriteUInt8(5, packet + 1);
        }

        PacketBufferWriteUInt32BE(m_exchangeSessionId, packet + 2);
        packet[6] = 0;

        g_packetSender->QueueAndSendPacket(packet, 6);
        m_localOfferPending = 1;
        return;
    }

    if (actionId == 2) {
        new AddItemDialog(m_exchangeSessionId, 1);
        return;
    }

    if (actionId == 3) {
        SendCancelPacket();
    }
}
```

Support UID00049U formal block recommendation:

```cpp
void ExchangeDialog::SendCancelPacket()
{
    unsigned char packet[7];

    PacketBufferWriteUInt8(0x4A, packet);
    PacketBufferWriteUInt8(4, packet + 1);
    PacketBufferWriteUInt32BE(m_exchangeSessionId, packet + 2);
    packet[6] = 0;

    g_packetSender->QueueAndSendPacket(packet, 6);
}
```

Notes for implementation:

- If the local support headers expose the byte writer as `PacketBufferWriteByte`, use the locally accepted alias consistently, but keep the by-* documentation mapping to [UID:0003YJ] `PacketBufferWriteUInt8`.
- `packet[6] = 0` is a local-only spare byte outside the explicit send length, matching the helper side effect and the target disassembly.
- The C++ block intentionally uses literal action ids and packet subcommands. A later style cleanup may introduce `kExchangeDialogConfirmButtonId`, `kExchangeDialogAddItemButtonId`, `kExchangeDialogCancelButtonId`, `kExchangeClientOpcode`, `kExchangeClientCancelOrConfirmSubcommand`, and `kExchangeClientReadyRequestSubcommand`, but constants are not required to implement this target safely.

## Implementation-Ready Edits

Apply these in a future implementation callback, not during this report-only assignment.

### Target: UID00049Q

File: `by-memory/0x004ad0b0-0x004ad1ca.ExchangeDialogOnButtonAction.md`

Required metadata edits:

- `COMPLETION:87`
- `CONFIDENCE:89`
- `CANONICAL_OWNER:00004R` unchanged
- `RECONSTRUCTABLE:TRUE` unchanged
- `EMITTER_UIDS:00004R`
- `EMITTER_POSITION_OPTIONAL:` unchanged
- Replace the blank formal block with the `ExchangeDialog::OnButtonAction` C++ above.

Required prose edits:

- Replace the old no-code disposition with a current source-quality closure.
- Document current session `46666bf7` evidence: exact range, vtable xref `0x00619d74`, action ids `1/2/3`, packet `0x4A` subcommands `4/5`, `g_pUserPane->m_itemCommandBusy`, `m_exchangeSessionId`, `m_localOfferPending`, `AddItemDialog(m_exchangeSessionId, 1)`, and UID00049U call.
- State that `AddItemDialog` implementation remains in [UID:000007]/[UID:0000KE].
- State that the second callback parameter is unused.

### Support: UID00049U

File: `by-memory/0x004ad900-0x004ad95f.ExchangeDialogSendCancelPacket.md`

Required metadata edits:

- `COMPLETION:86`
- `CONFIDENCE:89`
- `CANONICAL_OWNER:00004R` unchanged
- `RECONSTRUCTABLE:TRUE` unchanged
- `EMITTER_UIDS:00004R`
- `EMITTER_POSITION_OPTIONAL:` unchanged
- Replace the blank formal block with the `ExchangeDialog::SendCancelPacket` C++ above.

Required prose edits:

- Replace the old packet-helper-name blocker with current helper names and session `46666bf7` evidence.
- Document `xrefs_to 0x004ad900` as one code xref from UID00049Q at `0x004ad0f1`.
- Keep source route [UID:00004R] -> [UID:0000J9].

### Support: ExchangeDialog Class/File/Aggregate

Files:

- `by-class/ExchangeDialog.md`
- `by-file/ExchangeDialog.md`
- `by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md`

Required edits:

- Update the UID00049Q row from "non-emitting until blockers are final" to "first-draft C++ ready/emitting through UID00004R".
- Update UID00049U row similarly if the support implementation is applied.
- Preserve `+0x270` wording as descriptive `m_localOfferPending` / local ready-request state, not original-name proof.
- Keep `AddItemDialog` and `AddItemWithCountDialog` as ItemDialogs dependencies, not ExchangeDialog-owned implementations.
- Do not change [UID:0000J9] file ownership score unless validators suggest it; the file route already clears the gate.

### Generated/Tracker Refresh

Do not hand-edit these. Run validators/generation after by-* edits so `auto-generated/-ag-research-tracker.md`, coverage summaries, and generated source update naturally.

Expected generated outcome:

- UID00049Q should no longer appear as an empty/non-emitting reconstructable target.
- Generated `ExchangeDialog.cpp` should contain `ExchangeDialog::OnButtonAction`.
- If UID00049U support is implemented in the same callback, generated `ExchangeDialog.cpp` should contain `ExchangeDialog::SendCancelPacket` or an equivalent class-private method body.

## Validation Plan For Implementation Callback

From `source-3/project-documentation` after applying edits:

> Executable block R001 was removed from this report and preserved verbatim in [00049Q-ExchangeDialogOnButtonAction-source-quality-removed.md](00049Q-ExchangeDialogOnButtonAction-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Post-validation checks:

> Executable block R002 was removed from this report and preserved verbatim in [00049Q-ExchangeDialogOnButtonAction-source-quality-removed.md](00049Q-ExchangeDialogOnButtonAction-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

The initial report-only pass did not run validators because it made no by-* edits. The accepted implementation callback ran the validators recorded below.

## Claim And Incorporation Ledger

| Claim | Evidence | Incorporation instruction | Callback verification |
| --- | --- | --- | --- |
| UID00049Q range is exact `0x004ad0b0-0x004ad1ca`. | `lookup_funcs 0x004ad0b0` size `0x11a`; `0x004ad1c9` inside same function; `0x004ad1ca` not a function; next function `0x004ad1d0`. | Keep target range and filename unchanged. | Applied in `by-memory/0x004ad0b0-0x004ad1ca.ExchangeDialogOnButtonAction.md`; validator `000000000920` ok. |
| UID00049Q is a vtable-routed `ExchangeDialog` method. | `xrefs_to 0x004ad0b0` has one data xref `0x00619d74`; class/file pages route this slot to ExchangeDialog. | Keep `CANONICAL_OWNER:00004R`; set `EMITTER_UIDS:00004R`. | Applied in UID00049Q metadata and support rows; validators `000000000920`, `000000000922`, `000000000924`, and `000000000927` ok. |
| Callback shape is `OnButtonAction(int actionId, int unused)`. | MCP decompile has two stack args, second unused; disasm returns `retn 8`; comparable dialog pages use action-handler `void` methods despite decompiler return pollution. | Emit `void ExchangeDialog::OnButtonAction(int actionId, int /*unused*/)`; reject decompiler pointer return type. | Applied in UID00049Q formal C++ and generated `ExchangeDialog.cpp`; validator `000000000920` ok, generated freshness command `000000000927`. |
| Action id `1` sends client opcode `0x4A` subcommand `4` or `5`, then sets byte `this+0x270=1`. | Decompile/disasm at `0x004ad12e-0x004ad1a7`; `int_convert 0x4A=74`, `0x270=624`. | Add inline packet path and `m_localOfferPending = 1`. | Applied in UID00049Q formal C++ and prose; validator `000000000920` ok. |
| The subcommand branch depends on `dword_67A748+0x3ec0`. | Disasm `0x004ad12e mov eax, dword_67A748`; `0x004ad133 cmp byte ptr [eax+3EC0h],0`; support page maps storage to `g_pUserPane`, field to `m_itemCommandBusy`. | Use `g_pUserPane->m_itemCommandBusy != 0`; reject `g_pCollectionData` final name in target C++. | Applied in UID00049Q formal C++ and docs; validator `000000000920` ok. |
| Packet helper names are resolved. | [UID:0003YJ] maps `sub_575380` to `PacketBufferWriteUInt8`, `sub_5753F0` to `PacketBufferWriteUInt32BE`; [UID:0001HU]/[UID:0000Q5] map `sub_574BB0`/`dword_67A7EC`. | Use packet helper names in prose and C++; remove packet-helper-name blocker. | Applied in UID00049Q/UID00049U formal C++; validators `000000000920` and `000000000921` ok. |
| Action id `2` opens `AddItemDialog` with exchange id and mode `1`. | Disasm `0x004ad11a push 1`, `0x004ad11c push [esi+26Ch]`, `0x004ad124 call sub_4AE4C0`; `xrefs_to 0x004ae4c0` includes this call. | Emit `new AddItemDialog(m_exchangeSessionId, 1)`; keep AddItemDialog implementation in ItemDialogs. | Applied in UID00049Q formal C++ and support-file boundary prose; validators `000000000920` and `000000000924` ok. |
| UID00049Q does not open `AddItemWithCountDialog`. | `xrefs_to 0x004af040` only from `0x004ad3bf` dispatcher and `0x004adaeb` helper. | Reject AddItemWithCount ownership/source-shape dependency for UID00049Q. | Applied as source placement boundary in `by-file/ExchangeDialog.md`; validator `000000000924` ok. |
| Action id `3` calls cancel helper UID00049U. | Disasm call at `0x004ad0f1`; `xrefs_to 0x004ad900` exactly one code xref from UID00049Q. | Promote UID00049U support or do not emit UID00049Q. | Applied by promoting UID00049U and documenting the code xref; validators `000000000920` and `000000000921` ok. |
| UID00049U source body is ready. | `decompile 0x004ad900`: writes `0x4A`, `4`, `this+0x26c`, local zero, sends length `6`; one caller. | Add support formal C++ `ExchangeDialog::SendCancelPacket()`, `86/89`, `EMITTER_UIDS:00004R`. | Applied in `by-memory/0x004ad900-0x004ad95f.ExchangeDialogSendCancelPacket.md`; validator `000000000921` ok. |
| Score increase is justified but not final-source perfect. | Current MCP resolves code-entry blockers, but original constant/member spellings remain descriptive. | Target `87/89`; support `86/89`; do not claim final original naming. | Applied in UID00049Q and UID00049U metadata; validators `000000000920` and `000000000921` ok. |

## Implementation Tracking Checklist

- [x] Edit UID00049Q metadata to `87/89`, `EMITTER_UIDS:00004R`, keeping owner and reconstructable status unchanged. Validator `000000000920`, `2026-06-29T16:26:39-04:00`, exit `0`, `ok:1`.
- [x] Insert the recommended `ExchangeDialog::OnButtonAction(int actionId, int /*unused*/)` formal C++ block into UID00049Q. Validator `000000000920`, exit `0`, `ok:1`.
- [x] Replace UID00049Q's stale no-code blocker with current `46666bf7` MCP evidence and source-quality closure. Validator `000000000920`, exit `0`, `ok:1`.
- [x] Edit UID00049U metadata to `86/89`, `EMITTER_UIDS:00004R`, keeping owner and reconstructable status unchanged. Validator `000000000921`, `2026-06-29T16:27:01-04:00`, exit `0`, `ok:1`.
- [x] Insert the recommended `ExchangeDialog::SendCancelPacket()` formal C++ block into UID00049U. Validator `000000000921`, exit `0`, `ok:1`.
- [x] Update `by-class/ExchangeDialog.md` rows for `OnButtonAction` and `SendCancelPacket`. Validator `000000000922`, `2026-06-29T16:27:17-04:00`, exit `0`, `ok:1`.
- [x] Update `by-file/ExchangeDialog.md` packet/action notes while preserving ItemDialogs dependency boundaries. Validator `000000000924`, `2026-06-29T16:27:33-04:00`, exit `0`, `ok:1`.
- [x] Update aggregate `by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md` rows for UID00049Q and UID00049U. Validator `000000000927`, `2026-06-29T16:27:53-04:00`, exit `0`, `ok:1`.
- [x] Run the five validator commands listed above from `source-3/project-documentation`. All were run with `--wait-generated`; command IDs `000000000920`, `000000000921`, `000000000922`, `000000000924`, and `000000000927` returned exit `0`, `ok:1`, `generated_refresh:completed`.
- [x] Confirm generated output has no UID00049Q empty-emitter marker and includes `ExchangeDialog::OnButtonAction`. `rg` found UID00049Q at generated lines `7`/`8` in `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp`.
- [x] Confirm generated output includes `ExchangeDialog::SendCancelPacket` or an equivalent emitted support method before accepting the UID00049Q implementation. `rg` found UID00049U at generated lines `207`/`208` in `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp`.
- [x] Let generated tracker/coverage files refresh through tooling; do not hand-edit them. Validator generated refresh completed, and the final observed generated source header is `validator-command-id: 000000000931`.

## Out-Of-Scope Exclusions

- Do not resolve sibling blank-emitter targets UID00049P constructor, UID00049S button-state updater, UID00049T key handler, UID00049W amount setter, or UID00049Y focus-change handler in this UID00049Q report.
- Do not rename stable global page paths such as `g_pCollectionData`; only use the current canonical source-facing name `g_pUserPane` in target/support prose and C++.
- Do not move `AddItemDialog` or `AddItemWithCountDialog` into `ExchangeDialog.cpp`.
- Do not manually edit `auto-generated` tracker/coverage outputs.
- Do not claim final original symbolic names for action ids, packet subcommands, or packed state fields. The recommended names are descriptive and implementation-ready.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/00049Q-ExchangeDialogOnButtonAction-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/00049Q-ExchangeDialogOnButtonAction-source-quality.md","timestamp":"2026-06-29T16:53:17","uid":"00049Q"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00049Q-ExchangeDialogOnButtonAction-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/00049Q-ExchangeDialogOnButtonAction-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00049Q"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
