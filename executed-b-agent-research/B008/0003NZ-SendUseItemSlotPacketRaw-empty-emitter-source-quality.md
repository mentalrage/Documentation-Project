** TARGET-REPORT-UID:0003NZ **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B008 Report - [UID:0003NZ] SendUseItemSlotPacketRaw

Assignment: `B008-report-0003NZ-SendUseItemSlotPacketRaw-empty-emitter-source-quality-20260628`
Mode: report-only research first
Target: [UID:0003NZ] `by-memory/0x005b5e60-0x005b5ebe.SendUseItemSlotPacketRaw.md`
Report date: 2026-06-29

## Finalized Report / Current Recommendation

Recommendation: populate [UID:0003NZ] with formal first-draft C++ as a retained file-scope ItemActionInputPanes helper, keep owner/emitter [UID:0000KC], and raise the target from `85/88` to `88/90`.

Required action:

- Keep `CANONICAL_OWNER:0000KC`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000KC`.
- Change `COMPLETION:85` to `COMPLETION:88`.
- Change `CONFIDENCE:88` to `CONFIDENCE:90`.
- Insert formal source C++ in [UID:0003NZ]'s multiline reconstruction block.
- Do not use a covered-by marker. The target is not covered by [UID:00048W] InventoryPane2's opcode `0x1c` helper; it is a separate retained raw helper in the ItemActionInputPanes source island with a different owner route, ABI details, and adjacency.
- Preserve the no-direct-start-xref/no-pointer caveat as a confidence cap, not as a blank-C++ blocker.

Exact formal C++ to place between the target's existing `RECONSTRUCTION_CPP CODE:BEGIN` and `RECONSTRUCTION_CPP CODE:END` validator lines:

```cpp
static void SendUseItemSlotPacket(char itemSlot)
{
    unsigned char packet[128];

    PacketBufferWriteUInt8(0x1c, packet);
    PacketBufferWriteUInt8(itemSlot, packet + 1);
    packet[2] = 0;

    g_packetSender->QueueAndSendPacket(packet, 2);
}
```

This is intentionally ItemActionInputPanes-style source. The accepted InventoryPane2 sibling uses `WritePacketByte` / `g_pPacketSender->Send`; the current ItemActionInputPanes generated source and support docs use `PacketBufferWriteUInt8` and `g_packetSender->QueueAndSendPacket`. The formal source name deliberately drops the `Raw` suffix: `Raw` remains useful in the by-memory filename/search label because IDA does not model the helper as a function, but current local source-shape evidence does not support emitting it as part of the original C++ helper name.

## Current Target State

Current target header:

- UID: `0003NZ`
- Completion/confidence: `85/88`
- Canonical owner: `0000KC`
- Reconstructable: `TRUE`
- Emitters: `0000KC`
- Formal C++: blank inline and multiline reconstruction blocks
- Current item summary: retained file-level raw use/action-slot packet helper, opcode `0x1c`, slot byte, send length `2`, not EatInputPane opcode `0x1a`

Current generated state:

- `auto-generated/NexusTK/ui/dialogs/ItemActionInputPanes.cpp` has validator command `000000000132`, refreshed `2026-06-28T22:50:23-04:00`.
- That generated file still has `// UID:0003NZ ... Completion:85 | Confidence:88 | Empty Emitter Marker`.
- `auto-generated/-ag-research-tracker.md` still lists [UID:0003NZ] as `85/88`, average `86.5`, reconstructable `true`, report count `0`.
- `auto-generated/-ag-coverage-report-by-memory.md` still reports [UID:0003NZ] as `emits_code:false`.

This report does not edit any generated file. Those generated rows are post-implementation refresh expectations only.

## Current MCP Availability And Provenance

MCP was available for this report. No MCP or IDA process was started, stopped, restarted, or otherwise managed by B008.

Read-only status:

- `Test-NetConnection 127.0.0.1 -Port 13337` returned `TcpTestSucceeded: True`.
- Visible MCP-related processes included `idalib-mcp.exe` PID `9040`, worker Python PID `2412`, and listener Python PID `18824`.
- JSON-RPC `tools/list` succeeded against `http://127.0.0.1:13337/mcp`; tool schema exposed `server_health`, `idb_list`, `lookup_funcs`, `xrefs_to`, `get_bytes`, `find_bytes`, `insn_query`, and `decompile`.
- `idb_list` command `b008-idb-list-0003nz` returned active worker session `agent_b009_0002my_20260628`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `2412`, `is_analyzing:false`.
- `server_health` command `b008-health-0003nz-db` on that session returned `status:"ok"`, module `NexusTK.exe`, input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, strings cache size `2067`.

One earlier broad all-text instruction scan for operand `28` timed out in the same assignment context. It is not used as evidence. Subsequent listener, process, `idb_list`, and `server_health` checks stayed healthy, so the report uses scoped rechecks only.

## Current IDA MCP Evidence

`lookup_funcs` command `b008-lookup-0003nz`:

- `0x005b5de0` resolves to `sub_5B5DE0`, size `0x7c`.
- `0x005b5e60` is `Not a function`.
- `0x005b5ebe` is `Not a function`.
- `0x005b5ec0` resolves to `sub_5B5EC0`, size `0xc7`.
- `0x004ef400` is `Not a function`.

`xrefs_to` command `b008-xrefs-0003nz`:

- `0x005b5e60`: zero xrefs.
- `0x005b5ebe`: zero xrefs.
- `0x004ef400`: zero xrefs.

`insn_query` command `b008-insn-0003nz`, scoped to `0x005b5e50-0x005b5ec8`, confirms the exact target body and boundaries:

- `0x005b5e51`: `UseInputPane::OnSubmitInput` calls `sub_5A3E30`.
- `0x005b5e5b`: predecessor `sub_5B5DE0` returns.
- `0x005b5e5c`: `align 10h`, matching four `0xcc` bytes before the target.
- `0x005b5e60`: raw helper prologue starts, with no IDA function metadata.
- `0x005b5e7a`: `push 1Ch`.
- `0x005b5e7c`: calls `sub_575380`.
- `0x005b5e88`: `movsx eax, byte ptr [ebp+8]`.
- `0x005b5e8d`: calls `sub_575380` for the slot byte.
- `0x005b5e92`: loads `dword_67A7EC`.
- `0x005b5ea1`: writes local terminator byte at `[ebp-82h]`.
- `0x005b5ea8`: `push 2`.
- `0x005b5eab`: calls `sub_574BB0`.
- `0x005b5ebd`: plain `retn`.
- `0x005b5ebe`: `align 10h`, matching two `0xcc` bytes before `EatInputPane::EatInputPane`.
- `0x005b5ec0`: successor `sub_5B5EC0` begins.

`get_bytes` command `b008-bytes-0003nz`:

- `0x005b5e5c` begins with four `0xcc` bytes, then the helper bytes.
- The helper bytes include `6a 1c` for opcode `0x1c`, `0f be 45 08` for sign-extending the stack byte, `6a 02` for send length `2`, plain `c3` at the target return, and two `0xcc` bytes after the return.
- The accepted sibling [UID:00048W] at `0x004ef400` has the same stack-cookie packet helper shape, but uses `0f b6 45 08` (`movzx`) and `c2 04 00` (`retn 4`).

`decompile` command `b008-decompile-use-submit` for `0x005b5de0`:

- The live Use submit method reads one input character, maps `a-z` to `1-26` and `A-Z` to `27-52`, validates against `unk_69AE0C + 644`, and calls `sub_5A3E30` at `0x005b5e51`.
- This proves the ordinary live `UseInputPane::OnSubmitInput` path still dispatches through [UID:0001KN] `UseInventorySlotDispatch`, not through this raw helper.

`decompile` command `b008-decompile-eat-submit` for `0x005b6000`:

- The live Eat submit method performs the same slot-letter mapping and then calls `sub_575380(26, &Src)` at `0x005b6081`, where decimal `26` is opcode `0x1a`.
- It sends exactly two bytes through `sub_574BB0((_BYTE *)dword_67A7EC, &Src, 2)` at `0x005b60ac`.
- This confirms again that [UID:0003NZ] is not the EatInputPane packet path.

`find_bytes` command `b008-findbytes-0003nz`:

- Pattern `6A 1C E8` has 13 whole-image matches, including `0x004ef41a` and `0x005b5e7a`.
- VA pointer pattern `60 5E 5B 00` has zero matches.
- RVA pointer pattern `60 5E 1B 00` has zero matches.
- The packet-helper stack-cookie prefix `55 8B EC 81 EC 84 00 00 00 A1 24 2F 67 00 33 C5` has 67 matches, including `0x004ef400`, `0x005b5c20`, `0x005b5e60`, `0x005b6500`, and nearby ItemAction raw packet helpers. This supports the retained raw packet-helper family classification.

`insn_query` command `b008-insn-push1c-0003nz`, scoped pattern check:

- In `0x004ef000-0x004ef520`, the only scoped `push 1Ch` is `0x004ef41a`, the accepted InventoryPane2 use-item raw helper.
- In `0x005b4400-0x005b6800`, the only scoped `push 1Ch` is `0x005b5e7a`, this target.

`xrefs_to` command `b008-xrefs-context-0003nz`:

- `0x005b5e7a` has only the internal fall-through/code xref from `0x005b5e79`.
- `0x004ef41a` likewise has only the internal fall-through/code xref from `0x004ef419`.
- `0x005a3e30` has eight code xrefs, including `0x005b5e51` from `UseInputPane::OnSubmitInput`.
- `0x005af580` has five code xrefs, including two from `UseInventorySlotDispatch`.

## Positive Evidence

- Exact bytes and instructions prove a complete source-authored helper body at `0x005b5e60-0x005b5ebe`.
- The helper sends `[0x1c, itemSlot]` with send length `2`.
- The local terminator byte at `packet[2]` is outside the counted send length, matching the ItemAction packet-helper style already emitted for `SendWieldPacket`.
- The target is surrounded by clean `0xcc` alignment: `0x005b5e5c-0x005b5e60` before it and `0x005b5ebe-0x005b5ec0` after it.
- It is not an aggregate and not padding. A single formal helper body can represent the exact executable range without duplicating child pages.
- The target already meets the current code-entry gate: reconstructable true, nonblank emitter UID `0000KC`, emitter surfaces to `auto-generated/NexusTK/ui/dialogs/ItemActionInputPanes.cpp`, and `(85 + 88) / 2 = 86.5`, above the `> 85` first-draft threshold.
- Current ItemActionInputPanes source style supports the source-facing call shape: `PacketBufferWriteUInt8(...); g_packetSender->QueueAndSendPacket(packet, length);`.
- [UID:00048W] InventoryPane2 provides accepted precedent that an unmodeled no-start-xref opcode `0x1c` use-item raw helper can emit first-draft C++ when behavior, owner route, and source file placement are otherwise clear.

## Negative Evidence And Caps

- IDA still has no function at `0x005b5e60`.
- `xrefs_to 0x005b5e60` remains empty.
- No whole-image VA or RVA pointer hit to `0x005b5e60` was found by current `find_bytes`.
- The ordinary live `UseInputPane::OnSubmitInput` method calls [UID:0001KN] `UseInventorySlotDispatch` at `0x005b5e51`. It does not call this raw helper.
- The target's final original source helper name is inferred from packet behavior, adjacency, and project naming precedent. `SendUseItemSlotPacketRaw` remains the documentation/search label for the retained raw body, but `SendUseItemSlotPacket` is the stronger formal source-facing helper name.
- The stack argument is sign-extended (`movsx`) and the function returns with plain `retn`, unlike [UID:00048W] InventoryPane2 (`movzx`, `retn 4`). This supports `char itemSlot` and a file-scope helper, but confidence should stay below InventoryPane2's `91`.

These caps justify `88/90`, not a final-audit score.

## Heuristic And Source-Quality Reanalysis

The old blank-C++ state should not persist merely because the raw helper has no start xrefs. Rule 26 requires attacking that blocker with current evidence. Current evidence shows no caller route, but also shows a complete, bounded, source-authored packet helper with stable owner/emitter routing and exact behavior. For an eligible emitter above the code-entry gate, the correct result is first-draft C++ unless a target-specific no-code proof exists.

No such no-code proof exists for [UID:0003NZ]. It is not:

- an aggregate container like [UID:0001ML];
- compiler-only glue;
- a data-only table;
- a duplicate of an existing target;
- a covered range fully represented by `UseInputPane::OnSubmitInput`;
- a covered range fully represented by [UID:00048W] InventoryPane2.

The helper should remain separate from the live Use submit path. The direct Use path validates the slot and dispatches to [UID:0001KN] `UseInventorySlotDispatch`, which may send object-action packets or open `ItemWhoInputPane`. [UID:0003NZ] is a retained adjacent use/action-slot packet builder for opcode `0x1c`. Its raw/no-route status should be recorded as a liveness and name cap, not as a reason to leave the formal C++ block blank.

## Source-Facing Naming Analysis

Best formal C++ name/signature:

```cpp
static void SendUseItemSlotPacket(char itemSlot)
```

This keeps the page title `SendUseItemSlotPacketRaw` as the by-memory/documentation label but emits `SendUseItemSlotPacket` as the plausible human source helper name.

Rejected and accepted name forms:

- `SendUseItemSlotPacketRaw`: reject as formal C++ for this target. It is useful in the documentation filename because the body is retained raw code with no IDA function object or start xrefs, but the current ItemAction source pattern does not show `Raw` as a human-written suffix for local packet senders. [UID:0003NY] is the closest same-source-family precedent: its page label remains `SendThrowConfirmedItemPacketRaw`, but its formal source emits `ThrowReallyInputPane::SendThrowConfirmedItemPacket()` and explicitly rejects `Raw` as the source method suffix. No current evidence proves a high-level `SendUseItemSlotPacket` wrapper plus a lower-level `SendUseItemSlotPacketRaw` pair in ItemActionInputPanes; without that contrast, `Raw` reads as a documentation/search qualifier, not original C++.
- `SendUseItemSlotPacket`: accept. It preserves the packet role and the one-byte slot payload, which matters because the ordinary `UseInputPane::OnSubmitInput` path dispatches to [UID:0001KN] `UseInventorySlotDispatch` and may send object-action packets or open target selection. The `Slot` word prevents the name from implying a broader targeted/object use packet. It also follows the ItemAction helper style of descriptive `Send...Packet` names such as `SendWieldPacket`, `SendTakeOffPacket`, and proposed file-local `SendDropGoldPacket` / `SendGiveGoldPacket`.
- `SendUseItemPacket`: reject as too broad. It is plausible English, but less source-informative for this exact body because the packet contains only opcode `0x1c` and the selected slot byte. It could be confused with [UID:0001KN] use dispatch or [UID:0001LA] object-action packet sends, both of which are broader than this two-byte slot packet.
- `UseInputPane::SendUseItemSlotPacket` or another `UseInputPane::...` member: reject. The helper does not read `ecx`, does not use class state, reads the selected slot from `[ebp+8]`, and returns with a plain `retn`; current `UseInputPane::OnSubmitInput` does not call this raw helper. Unlike [UID:0003NY], which is thiscall-shaped and reads `this+0x108`, this target is argument-driven and file-helper-shaped.
- File-local/static helper form: accept. A `static` file-scope helper best matches the raw ABI shape: one stack byte argument, no `this`, ItemActionInputPanes ownership, no current external pointer/caller route, and adjacency to other compact item-action packet helpers. [UID:0001MS] `SendWieldPacket` is already emitted as a private/static file helper in this module. [UID:0001M2] `SendTakeOffPacket` is non-static because it has many cross-file callers, including SelfLookPane; [UID:0003NZ] has no such route, so static file-local linkage is the conservative source shape.
- Covered-by or no-code alternative: still reject. The naming correction does not change the earlier evidence: this is a complete exact helper range with stable owner/emitter routing and first-draft C++ eligibility. A covered-by marker would hide a distinct retained ItemAction helper, and blank C++ would leave an eligible emitter unresolved.

[UID:00048W] InventoryPane2 is useful precedent for emitting a no-xref opcode `0x1c` use-slot helper, but it should not be blindly copied for naming. It is a class-owned inventory source item, currently emits `InventoryPane2::SendUseItemSlotPacketRaw(unsigned char inventorySlot)`, uses `movzx`, and returns with `retn 4`. This target is ItemAction-owned, file-helper-shaped, uses `movsx`, and returns with plain `retn`. The stronger same-module naming precedent is [UID:0003NY]'s separation of retained-raw page label from human source name, plus the local file-level packet helper names without `Raw`.

## Ownership And Source Placement

Ranked disposition:

1. [UID:0000KC] `ItemActionInputPanes` - keep as canonical owner and emitter. The target sits inside the Throw/Use/Eat item-action island, adjacent to `UseInputPane` and `EatInputPane`, uses the item-action slot-byte packet pattern, and already emits through the ItemActionInputPanes generated file route.
2. [UID:0000FG] `UseInputPane` - support class context only. The target is adjacent to `UseInputPane`, sends the use/action opcode, and shares slot semantics, but there is no direct caller proof from the class method and the body does not read `this`.
3. [UID:0001ML] `ThrowUseEatInputPanes` - non-emitting split/container only. It inventories the range and child raw helpers; it must stay `RECONSTRUCTABLE:FALSE`.
4. [UID:0000Q5]/[UID:0001P0] `g_packetSender` - dependency only. The sender owns transport lifetime, not the feature packet builder.
5. [UID:00048W] InventoryPane2 helper - analogy/precedent only. It does not own, cover, or replace this range.

Rejected owners:

- `EatInputPane`: opcode mismatch; Eat uses decimal `26` / `0x1a` at `0x005b6000`, while this target uses `0x1c`.
- `UseInventorySlotDispatch` / `LivingObjectPane`: ordinary Use flow dependency, not this retained helper's source owner.
- `Socket`, `PacketBuffer`, `ProtocolSend`: infrastructure dependencies, not feature ownership.

## Covered-By Marker Decision

Do not convert [UID:0003NZ] to a covered-by marker.

[UID:00048W] proves a sibling source shape, but it is owned by [UID:00006S] `InventoryPane2`, emitted through `NexusTK/ui/inventory/InventoryPane.cpp`, uses `movzx` for the argument byte, and returns with `retn 4`. [UID:0003NZ] is owned by [UID:0000KC] `ItemActionInputPanes`, emitted through `NexusTK/ui/dialogs/ItemActionInputPanes.cpp`, uses `movsx` for the stack argument byte, and returns with plain `retn`.

The two functions send the same opcode/payload shape, but they are distinct source locations and distinct by-memory ranges. A covered-by marker would erase a real retained helper that is currently an empty emitter in the correct source file.

## Recommended Target Doc Changes

For `by-memory/0x005b5e60-0x005b5ebe.SendUseItemSlotPacketRaw.md`:

- Set `COMPLETION:88`.
- Set `CONFIDENCE:90`.
- Keep `CANONICAL_OWNER:0000KC`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `EMITTER_UIDS:0000KC`.
- Populate the formal multiline C++ block with the exact C++ from this report.
- Add the source-facing naming decision: the page/file label remains `SendUseItemSlotPacketRaw`, but formal emitted C++ should be `static void SendUseItemSlotPacket(char itemSlot)` because `Raw` is a retained-body documentation/search qualifier here, not a proven original source suffix.
- Update the item summary to state that current MCP session `agent_b009_0002my_20260628` confirms no IDA function/start xrefs/pointer hits, opcode `0x1c`, signed stack-slot byte write, send length `2`, clean boundaries, first-draft helper C++ through [UID:0000KC], and separation from `UseInputPane::OnSubmitInput` and `EatInputPane`.
- Add a 2026-06-29 B008 evidence section or change entry with the current MCP command IDs:
  - `b008-idb-list-0003nz`
  - `b008-health-0003nz-db`
  - `b008-lookup-0003nz`
  - `b008-xrefs-0003nz`
  - `b008-insn-0003nz`
  - `b008-bytes-0003nz`
  - `b008-findbytes-0003nz`
  - `b008-insn-push1c-0003nz`
  - `b008-xrefs-context-0003nz`
  - `b008-decompile-use-submit`
  - `b008-decompile-eat-submit`
- Preserve the no-start-xref/no-pointer caveat as a confidence cap.
- Explicitly reject covered-by treatment and InventoryPane2 ownership.

## Recommended Support Doc Changes

For `by-file/ItemActionInputPanes.md`:

- Update the `UseInputPane` proposed-contents row to say [UID:0003NZ] is now source-ready/formal first-draft as a retained file-scope helper:
  `static void SendUseItemSlotPacket(char itemSlot)`.
- Preserve that `UseInputPane::OnSubmitInput` itself still calls [UID:0001KN] `UseInventorySlotDispatch`; this helper does not replace the live submit method's dispatch.
- Preserve the by-memory/page label `SendUseItemSlotPacketRaw` as the retained raw documentation/search label, but document that the formal source-facing helper name drops `Raw`.
- Add a boundary/change note recording current B008 evidence: no function at `0x005b5e60`, no start xrefs or VA/RVA pointer hits, `push 1Ch` at `0x005b5e7a`, `movsx` from `[ebp+8]`, send length `2`, `retn` at `0x005b5ebd`, and ItemAction-local source style `PacketBufferWriteUInt8` / `g_packetSender->QueueAndSendPacket`.
- Score change not required for the file page; it already remains capped by other raw helper/method work.

For `by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md`:

- Keep the parent as non-emitting `RECONSTRUCTABLE:FALSE`.
- Update the child map/reconstruction notes to state that [UID:0003NZ] now carries its own formal first-draft C++ through [UID:0000KC] while [UID:0001ML] remains only the range inventory.
- Preserve the corrected opcode `0x1c` and separation from Eat opcode `0x1a`.

For `by-class/UseInputPane.md`:

- Add a support note that [UID:0003NZ] is now source-ready/formal first-draft as an adjacent retained ItemAction helper, but the live `UseInputPane::OnSubmitInput` body still calls [UID:0001KN] `UseInventorySlotDispatch`.
- Preserve class-level C++ blank state unless a separate UseInputPane class/method report is accepted. This report only resolves the adjacent raw helper.

No required edit to [UID:0000Q5]/[UID:0001P0] `g_packetSender` is needed. Current packet-sender docs already establish `Socket *g_packetSender`, `QueueAndSendPacket`, and ItemAction consumers. If the supervisor wants a consumer note, it should be non-semantic and score-neutral: [UID:0003NZ] is one more feature packet consumer through the same sender, not a Socket ownership/type change.

## Score And Metadata Disposition

Target score after implementation:

- Completion `88`: exact range, exact bytes/instructions, current MCP health/session, no-function/no-xref/no-pointer evidence, source owner/emitter route, support-page route, formal C++ body, sibling comparison, and rejected covered-by/owner alternatives are documented.
- Confidence `90`: behavior and owner are strong, but no direct caller/start xref/pointer hit remains, the final original helper spelling is inferred, and the target is retained raw code not reached by the ordinary current `UseInputPane::OnSubmitInput` path.

Do not raise beyond `90` confidence until either a real caller/pointer/liveness route is found or surrounding source recovery explains why this retained helper exists without xrefs.

## Validation And Generated Refresh Expectations

Accepted callback used current queue syntax from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0003NZ-SendUseItemSlotPacketRaw-empty-emitter-source-quality-removed.md](0003NZ-SendUseItemSlotPacketRaw-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Validator results during callback:

| File | command_id | command_timestamp | exit | ok | Generated state / warnings |
| --- | --- | --- | --- | --- | --- |
| `by-memory/0x005b5e60-0x005b5ebe.SendUseItemSlotPacketRaw.md` | `000000000236` | `2026-06-29T00:59:15-04:00` | `0` | `1` | `generated_refresh: completed`; validator-owned side effects included `autogen_cpp_update: 1`, `memory_auto_coverage_update: 1`, `projected_stats_update: 1`, and existing stale-registry/missing-file diagnostics outside UID0003NZ. |
| `by-file/ItemActionInputPanes.md` | `000000000237` | `2026-06-29T00:59:34-04:00` | `0` | `1` | `generated_refresh: deferred`; existing `missing_ref_uid` warnings for older ItemAction child UIDs remained, and validator inserted one [UID:0001KN] link. |
| `by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md` | `000000000238` | `2026-06-29T00:59:41-04:00` | `0` | `1` | `generated_refresh: deferred`; existing `missing_ref_uid` warnings for [UID:0003NX] remained, and validator inserted [UID:0003NZ] links. |
| `by-class/UseInputPane.md` | `000000000239` | `2026-06-29T00:59:47-04:00` | `0` | `1` | `generated_refresh: deferred`; validator inserted [UID:0003NZ]/[UID:0001KN] links and added a [UID:0003NZ] reference-index entry. |

Narrow supervisor correction validators for stale Wave3/recovered-source support-doc handling:

| File | command_id | command_timestamp | exit | ok | Generated state / warnings |
| --- | --- | --- | --- | --- | --- |
| `by-class/UseInputPane.md` | `000000000250` | `2026-06-29T01:09:49-04:00` | `0` | `1` | `generated_refresh: deferred`; projected stats update only. |
| `by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md` | `000000000251` | `2026-06-29T01:09:56-04:00` | `0` | `1` | `generated_refresh: deferred`; existing [UID:0003NX] `missing_ref_uid` warnings remained. |
| `by-file/ItemActionInputPanes.md` | `000000000252` | `2026-06-29T01:10:03-04:00` | `0` | `1` | `generated_refresh: deferred`; existing `missing_ref_uid` warnings for older ItemAction child UIDs remained. |

Generated output was read-only checked after validation:

- Final observed callback check of `auto-generated/NexusTK/ui/dialogs/ItemActionInputPanes.cpp` showed header `validator-command-id: 000000000244` and `validator-refreshed-at: 2026-06-29T01:03:17-04:00`, which is newer than the target validator command `000000000236`.
- UID0003NZ now appears as `// UID:0003NZ | by-memory/0x005b5e60-0x005b5ebe.SendUseItemSlotPacketRaw.md | Completion:88 | Confidence:90`.
- UID0003NZ generated body contains `static void SendUseItemSlotPacket(char itemSlot)`, `PacketBufferWriteUInt8(0x1c, packet)`, `PacketBufferWriteUInt8(itemSlot, packet + 1)`, `packet[2] = 0`, and `g_packetSender->QueueAndSendPacket(packet, 2)`.
- UID0003NZ is no longer an `Empty Emitter Marker`. Other unrelated empty markers remain in the generated file.

`auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, generated C++, project-level generated files, validator/tool state, lock files, manual coverage reports, executed-report archives, IDA DB, and `g_packetSender` docs were not manually edited by B008. Validator-owned generated/tool-state side effects are reported above. `execute_report` was not run; supervisor owns report execution after verification.

## Stale Wave3 / Recovered-Source Handling

Supervisor correction pass historicalized the stale Wave3/recovered-source artifacts encountered in the edited support docs. `source-3/simroot_v2/class_UseInputPane.cpp`, the Wave3 `LivingObjectPane::UseSpellSlot` generated name, the `Current Wave3 owners`/projected-start wording in [UID:0001ML], the `wave3.py` migration command block, and recovered `class_DropGoldInputPane.cpp` / `class_GiveGoldInputPane.cpp` artifact labels are preserved only as historical/generated leads or migration artifacts. They are not current authority for UID0003NZ ownership, source placement, source-facing naming, or emitted C++; current authority remains current IDA/MCP evidence, by-* docs, and the accepted exact-child [UID:0003NZ] implementation.

## Claim And Incorporation Ledger

| Claim / accepted fact | Action | Destination | Verification state | Proof / exclusion |
| --- | --- | --- | --- | --- |
| Target metadata must be raised from `85/88` to `88/90` while keeping `CANONICAL_OWNER:0000KC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KC`, and blank emitter position. | incorporate | `by-memory/0x005b5e60-0x005b5ebe.SendUseItemSlotPacketRaw.md` header | applied | Header now has `COMPLETION:88`, `CONFIDENCE:90`, unchanged owner/emitter/reconstructable metadata, and blank `EMITTER_POSITION_OPTIONAL`. Validator `000000000236` recorded `completion_update 0003NZ 88` and `confidence_update 0003NZ 90`. |
| Formal C++ must be inserted only inside the target's validator `RECONSTRUCTION_CPP CODE:BEGIN/END` block, with no report illustrative header/footer lines. | incorporate | Target formal C++ block | applied | Target block contains only the accepted function body for `static void SendUseItemSlotPacket(char itemSlot)` with packet buffer writes and `g_packetSender->QueueAndSendPacket(packet, 2)`. Generated `ItemActionInputPanes.cpp` shows the same body for UID0003NZ. |
| Page/file label remains `SendUseItemSlotPacketRaw`, but emitted source name is `SendUseItemSlotPacket` without `Raw`. | incorporate | Target `Status`, `Source-Facing Naming And Ownership Notes`, `Changes`; `by-file/ItemActionInputPanes.md` row/note | applied | Target status/naming notes explicitly preserve `Raw` as a documentation/search qualifier and reject raw-suffixed formal C++; ItemAction row says `Raw` remains the by-memory/search label only. |
| Current MCP session `agent_b009_0002my_20260628` and command IDs must be preserved. | incorporate | Target `Item Summary`, `IDA MCP Evidence`, `Changes`; support notes where relevant | applied | Target evidence lists `b008-idb-list-0003nz`, `b008-health-0003nz-db`, `b008-lookup-0003nz`, `b008-xrefs-0003nz`, `b008-insn-0003nz`, `b008-bytes-0003nz`, `b008-findbytes-0003nz`, `b008-insn-push1c-0003nz`, `b008-xrefs-context-0003nz`, `b008-decompile-use-submit`, and `b008-decompile-eat-submit`. |
| No IDA function/start xrefs/pointer hits are a confidence cap, not a blank-C++ blocker. | incorporate | Target summary/status/evidence/naming/change; support by-file/parent/class notes | applied | Target states no function/xref/pointer remains a confidence cap; support docs preserve no-route caveat while saying exact child now emits first-draft C++. |
| Exact behavior is opcode `0x1c`, signed stack-slot byte from `[ebp+8]`, local terminator, send length `2`, clean padding/end at `0x005b5ebe`. | incorporate | Target packet/evidence; support by-file row/note; parent row/evidence/raw map; class evidence | applied | Target and support docs record `push 1Ch`, `movsx`, `packet[2] = 0`, send length `2`, `retn` at `0x005b5ebd`, and `0xcc` padding before/after. |
| `UseInputPane::OnSubmitInput` remains separate and still calls [UID:0001KN] `UseInventorySlotDispatch`. | incorporate | Target evidence/naming; `by-file/ItemActionInputPanes.md`; `by-class/UseInputPane.md`; parent evidence | applied | All affected docs state live submit calls [UID:0001KN] and does not call/replace UID0003NZ. |
| `EatInputPane` remains the opcode `0x1a` path and does not own/cover UID0003NZ. | incorporate | Target summary/evidence/boundary; parent evidence/raw map; support by-file/class notes | applied | Target and parent preserve `EatInputPane::OnConfirmInput` as decimal `26` / `0x1a`; by-file keeps adjacent helper "not the eat helper" context. |
| Covered-by treatment is rejected. | incorporate | Target `Source-Facing Naming And Ownership Notes` and `Changes`; support by-file change note | applied | Target says do not convert UID0003NZ to a covered-by marker because Use submit and InventoryPane2 do not cover the retained range; by-file change note says covered-by remains rejected. |
| InventoryPane2/[UID:00048W] is analogy only, not owner or source-name precedent to copy blindly. | incorporate | Target packet/naming/change; support by-file change note | applied | Target compares [UID:00048W] ABI and ownership differences and rejects InventoryPane2 ownership; by-file change note preserves rejection. |
| `SendUseItemPacket` and `UseInputPane::...` member alternatives are rejected; file-local/static helper is accepted. | incorporate | Target `Source-Facing Naming And Ownership Notes` and `Changes` | applied | Target naming notes reject broad `SendUseItemPacket`, reject member form due no `ecx`/stack arg/plain `retn`, and accept file-local/static helper under [UID:0000KC]. |
| `by-file/ItemActionInputPanes.md` must update the UseInputPane row plus boundary/change notes at report-level specificity. | incorporate | `by-file/ItemActionInputPanes.md` | applied | Row now names `SendUseItemSlotPacket(char itemSlot)`, packet details, `Raw` label caveat, no-route proof, and live [UID:0001KN] route; boundary/change notes add B008 MCP/session evidence and score unchanged `90/85`. Validator `000000000237` passed. |
| Parent [UID:0001ML] must stay non-emitting and route source-bearing C++ to exact child [UID:0003NZ]. | incorporate | `by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md` | applied | Parent summary, covered range row, MCP evidence, raw-helper map, reconstruction notes, and change log now say UID0003NZ emits exact-child source while parent remains `RECONSTRUCTABLE:FALSE`, blank emitter/code. Validator `000000000238` passed. |
| `by-class/UseInputPane.md` must add adjacent helper readiness while preserving class C++ blank and live [UID:0001KN] route. | incorporate | `by-class/UseInputPane.md` | applied | Status, evidence notes, and change log now say UID0003NZ is source-ready on exact child; class-level formal C++ remains blank and live `OnSubmitInput` still calls [UID:0001KN]. Validator `000000000239` passed. |
| No required `g_packetSender` doc edit. | not-applicable | [UID:0000Q5]/[UID:0001P0] packet-sender docs | excluded-with-reason | Report found no contradiction; target/support docs use existing source-facing `g_packetSender->QueueAndSendPacket`, so packet-sender ownership/type docs were left untouched. |
| Stale/historical assumptions must be preserved or corrected: old eat/opcode `0x1a` wording, blank-C++ state, raw formal suffix, and InventoryPane2 covered-by/ownership ideas. | historicalize | Target/support change logs and naming/evidence sections | applied | Target Changes preserve B010 correction history and add B008 correction; support docs preserve parent non-emitting history, old no-route caveat, and rejected alternatives instead of deleting them. |
| Scoped validators must run with `--queue-timeout 240`, and generated output must be checked. | incorporate | This report validation section/checklist | applied | Validators `000000000236` through `000000000239` all exited `0` with `ok: 1`; final observed generated `ItemActionInputPanes.cpp` header is `000000000244` and UID0003NZ is no longer an empty marker. |
| Leases must be short and released immediately after edit/validator batch. | incorporate | This report checklist/final callback result | applied | B008 leased the four by-* docs before editing. Cleanup `unlease` reported `Rejected[No active lease]` for all four because the short leases had already expired; current lease report has no B008 rows. |
| `execute_report`, generated reports/C++ manual edits, manual coverage reports, validator/tool state edits, executed archives, lock files, and IDA DB edits are excluded. | not-applicable | Supervisor-owned/tool-owned areas | excluded-with-reason | B008 did not run `execute_report` and did not manually edit excluded files or IDA DB. Validator-owned generated/tool-state side effects are listed in the validation table. |
| UseInputPane support doc stale recovered/Wave3 output must be historicalized, not treated as authority. | historicalize | `by-class/UseInputPane.md` | applied | Rewrote `source-3/simroot_v2/class_UseInputPane.cpp` as a historical recovered-source lead and rewrote the Wave3 `LivingObjectPane::UseSpellSlot` line as an old generated lead. The doc now states current authority is IDA MCP/by-* evidence: live `OnSubmitInput` calls [UID:0001KN], while [UID:0003NZ] emits only on its exact child page. Validator `000000000250` passed. |
| ThrowUseEatInputPanes support doc stale Wave3 owner/projection wording must be historicalized. | historicalize | `by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md` | applied | Rewrote `Current Wave3 owners` as current by-* source contexts with older Wave3 owner labels historicalized, and rewrote the Wave3 projected constructor-start line to state it is an old generated lead. Current authority is IDA function map/raw-byte evidence plus exact class/raw child pages. Validator `000000000251` passed. |
| ItemActionInputPanes support doc Wave3 migration commands and recovered artifact wording must be historical/generated context only. | historicalize | `by-file/ItemActionInputPanes.md` | applied | Added a proposed-contents note that file/route names are older generated/recovered leads when applicable, renamed the migration section to `Historical Migration Notes`, marked Wave3 dry-run commands as non-authoritative, and labeled recovered `class_DropGoldInputPane.cpp` / `class_GiveGoldInputPane.cpp` artifacts as historical migration artifacts. Validator `000000000252` passed. |
| Narrow correction validators and leases must be reported. | incorporate | This report validation/checklist/final result | applied | Correction validators `000000000250`, `000000000251`, and `000000000252` exited `0` with `ok: 1`; leases for the three support docs were released successfully. |

No ledger row is blocked or left unapplied.

## Implementation Tracking Checklist

- [x] Claim ledger update: added `## Claim And Incorporation Ledger` with accepted claims/facts, destinations, allowed actions, callback verification states, and proof/exclusion reason for every row. No row remains `blocked`.
- [x] Target metadata update: in `by-memory/0x005b5e60-0x005b5ebe.SendUseItemSlotPacketRaw.md`, set completion/confidence to `88/90`, kept owner/emitter [UID:0000KC], kept reconstructable true, and left emitter position blank. Proof: target header now has `COMPLETION:88`, `CONFIDENCE:90`; validator `000000000236` recorded the metadata updates.
- [x] Target formal C++ update: inserted only the C++ body between the existing validator `RECONSTRUCTION_CPP CODE:BEGIN` and `RECONSTRUCTION_CPP CODE:END` lines. Proof: target block and generated UID0003NZ body show `static void SendUseItemSlotPacket(char itemSlot)`, `PacketBufferWriteUInt8(0x1c, packet)`, `PacketBufferWriteUInt8(itemSlot, packet + 1)`, `packet[2] = 0`, and `g_packetSender->QueueAndSendPacket(packet, 2)`; no `source=agent-b008-report-20260629` header/footer lines were inserted.
- [x] Target evidence update: incorporated current MCP evidence from session `agent_b009_0002my_20260628`, including health, lookup, no-xref, exact instruction/body bytes, scoped `push 1Ch`, Use/Eat decompile contrast, InventoryPane2 sibling contrast, and no VA/RVA pointer hits. Proof: target `IDA MCP Evidence` and `Changes` list all B008 command IDs and facts.
- [x] Target source-quality disposition update: documented that no covered-by marker is appropriate, no-code is rejected, no-direct-xref remains only a confidence cap, the formal source name is `SendUseItemSlotPacket` rather than raw-suffixed, and the helper remains separate from `UseInputPane::OnSubmitInput` and `EatInputPane`. Proof: target `Source-Facing Naming And Ownership Notes` and `Changes` contain these rejections and caps.
- [x] Support update in `by-file/ItemActionInputPanes.md`: updated the `UseInputPane` row and boundary/change notes with formal helper readiness, source placement, packet details, source-facing name `SendUseItemSlotPacket` without `Raw`, and the live dispatch caveat. Proof: row now names the static helper and live [UID:0001KN] route; B008 boundary/change notes added; validator `000000000237` passed.
- [x] Support update in `by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md`: kept the parent non-emitting, but updated the [UID:0003NZ] child/reconstruction notes to say source-bearing C++ is now on the exact child page. Proof: summary, child map, MCP evidence, raw-helper map, reconstruction notes, and B008 change log updated; validator `000000000238` passed.
- [x] Support update in `by-class/UseInputPane.md`: added the source-ready adjacent-helper note while preserving that the live submit method calls [UID:0001KN] and the class C++ remains blank outside this report. Proof: status/evidence/change notes updated; validator `000000000239` passed.
- [x] Stale/historicalized/rejected claims handled: older eat/opcode `0x1a` wording remains historicalized as corrected by B010/B008, blank-C++ state is superseded by formal helper code, raw formal suffix is rejected but kept as label, and InventoryPane2/covered-by/member/broad-name alternatives are explicitly rejected. Proof: target/source-family/parent/class docs preserve these decisions.
- [x] No edit required to `g_packetSender` docs. Proof: no contradiction was found; packet-sender docs were not edited, and target/support docs use existing `g_packetSender->QueueAndSendPacket` naming.
- [x] No manual edit to generated reports, generated C++ files, project-level files, manual coverage reports, validator/tool state, executed reports, lock files, or IDA DB. Proof: direct edits were limited to the four target/support by-* docs and this B008 report; validator-owned generated/tool-state side effects are reported above.
- [x] Scoped validators run for all edited by-* docs with `--apply` and current queue syntax. Proof: commands `000000000236`, `000000000237`, `000000000238`, and `000000000239` all exited `0` with `ok: 1`; command timestamps and warnings are recorded in the validation table.
- [x] Generated refresh result verified by reading `auto-generated/NexusTK/ui/dialogs/ItemActionInputPanes.cpp`. Proof: final observed header `validator-command-id: 000000000244`, `validator-refreshed-at: 2026-06-29T01:03:17-04:00`; UID0003NZ line shows `Completion:88 | Confidence:90` and generated helper body, not `Empty Emitter Marker`.
- [x] Implementation leases released/cleared after edit/validator batch. Proof: cleanup `python .\leaser.py Agent-B008 unlease ...` returned `Rejected[No active lease]` for all four paths because the short leases had already expired; `tools/leaser/Agents/Agent-B008/current_leases.md` has no B008 active rows.
- [x] `execute_report` was not run. Proof: no execute-report command was issued; supervisor owns execution after verification.
- [x] Stale Wave3/recovered-source handling note added. Proof: report now has `## Stale Wave3 / Recovered-Source Handling`, stating Wave3/recovered artifacts are historical/generated leads or migration artifacts only, not current authority for UID0003NZ.
- [x] `by-class/UseInputPane.md` stale recovered/Wave3 lines corrected. Proof: `source-3/simroot_v2/class_UseInputPane.cpp` is a historical recovered-source lead only; Wave3 `LivingObjectPane::UseSpellSlot` is an old generated lead; validator `000000000250` passed.
- [x] `by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md` Wave3 owner/projection wording corrected. Proof: older Wave3 owner labels and projected constructor starts are historical/generated leads only; validator `000000000251` passed.
- [x] `by-file/ItemActionInputPanes.md` Wave3 migration/recovered-artifact wording corrected. Proof: proposed-contents note, `Historical Migration Notes`, and recovered artifact labels now mark Wave3/recovered output as historical/generated migration context only; validator `000000000252` passed.
- [x] Correction leases released. Proof: `python .\leaser.py Agent-B008 unlease ...` returned `Success` for `by-class/UseInputPane.md`, `by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md`, and `by-file/ItemActionInputPanes.md`.

No implementation checklist item remains unchecked or blocked.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004165","destination_path":"executed-b-agent-research/B008/0003NZ-SendUseItemSlotPacketRaw-empty-emitter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B008/research/0003NZ-SendUseItemSlotPacketRaw-empty-emitter-source-quality.md","timestamp":"2026-06-29T01:16:42","uid":"0003NZ"} -->
<!-- {"agent":"B008","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0003NZ-SendUseItemSlotPacketRaw-empty-emitter-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B008/0003NZ-SendUseItemSlotPacketRaw-empty-emitter-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0003NZ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
