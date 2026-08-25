** TARGET-REPORT-UID:0003US **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003US **
# 0003US LivingObjectPaneHandleUserListPacket Source-Quality Research

## Finalized Report / Current Recommendation
- Assignment id: `B001-goal2-livingobjectpane-user-list-packet-source-quality-0003US-20260618`.
- Target: [UID:0003US] `by-memory/0x005abb20-0x005abc6f.LivingObjectPaneHandleUserListPacket.md`.
- Current target state before this report: `85/85`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:00007B`, `EMITTER_UIDS:00007B`, blank formal C++.
- Recommendation: keep `CANONICAL_OWNER:00007B`, keep `RECONSTRUCTABLE:TRUE`, keep `EMITTER_UIDS:00007B`, raise target documentation to `COMPLETION:87`, `CONFIDENCE:86`, and keep formal C++ blank for now under the target-specific no-code proof below.
- Best source-facing name/signature: inferred/descriptive `bool LivingObjectPane::HandleUserListPacket(ServerMessageEvent *event)` or project-local equivalent where `event + 0x0c` is the packet payload pointer and `event + 0x10` is the payload byte count. The binary return is a byte truth value (`1`).
- Best route finding: no direct caller and no hidden table route to the standalone `0x005abb20` entry were proven. The live user-pane server-message switch handles opcode `0x36` with the same logic inline inside [UID:0003VB], while the standalone [UID:0003US] function has zero cached callers/xrefs. Treat [UID:0003US] as a source-authored out-of-line helper/copy retained in the local-player packet tail, not as the live packet-dispatch target.
- Required supervisor action: apply the metadata/support/coverage text below. Do not directly edit `by-memory/-coverage-report.md` from this report; the exact pending row text is provided under `Coverage Report Replacement Text`.

## Evidence Checked
- Required B001/supervisor rules read: `Agent-B001/goal.md`, `Supervisor.md`, `by-structure.md`, `inference_research.md`, and `proposed-source-tree.md`.
- IDA MCP availability: attempted `tools/list` at `http://127.0.0.1:13337/mcp`; the session returned `Unable to connect to the remote server`. Current-session live IDA evidence was unavailable, so this report relies on existing live-IDa-backed by-* docs and read-only prewave/cache decompilation as evidence leads. Confidence is kept below final-source confidence for that reason.
- Target page [UID:0003US] was read. It currently records only the exact range, current IDA name `sub_5ABB20`, no direct start xrefs, and open questions for caller route, packet subtype, and field names.
- Parent/support pages checked: [UID:00007B] `LivingObjectPane`, [UID:0000KU] `LivingObjectPane`, [UID:0001KM] `LivingObjectPaneLocalPlayerExtensions`, [UID:0003VB] `UserPaneHandleServerMessage`, [UID:0003VC] `UserPaneHandleServerMessageSwitchTables`, [UID:0003UK] `LivingObjectPaneSetMovementBuffer`, [UID:0002WD] `g_pUserListDialogPane`, [UID:0000FN] `UserListDialogPane`, [UID:0000OZ] `UserListDialogPane`, [UID:0001KI] `UserListDialogPaneAndUserListPane`, and [UID:00030B] `g_lastFunctionKeyTick`.
- Existing B reports checked: `Agent-B001/research/executed/older/0001KM-livingobject-localplayer-source-split-audit.md`. It correctly identified `0x005abb20-0x005abc6f` as a no-start-xref `LivingObjectPane`-likely function and warned that reachability was unresolved. This report supersedes only the "may be indirectly dispatched" uncertainty: the matching packet-dispatch logic is inline in [UID:0003VB], not a proven route to this standalone entry.
- Read-only cache facts checked for `0x005abb20`: function size `335` bytes / `0x14f`, IDA signature lead `char __thiscall(int this, int)`, Ghidra signature lead `undefined4 __thiscall meth_0x5abb20(LivingObjectPane *this, int param_1)`, `num_callers` `0` in both Ghidra/IDA cache fields, cached `xrefs_to` empty, and seven callees: packet word reader `0x00575480`, free, allocation `0x005c7790`, `memmove`/copy `0x005c95b0`, `0x005a9310`, allocator `0x004f4aa0`, and `UserListDialogPane` constructor `0x0059bc90`.
- Read-only cache decompile for [UID:0003VB] shows `switch (*payload)` and an explicit `case 0x36u` body. That case normalizes the `UserPane` facet to a `LivingObjectPane` receiver with `a1 - 160`, then executes the same user-list staging/dialog-creation logic as standalone `sub_5ABB20`. No call to `0x005abb20` appears in that decompile.
- [UID:0003VC] documents the dispatcher switch-table child as 25 dword entries all pointing back inside [UID:0003VB] `0x005a76c0-0x005a82bd`. That is negative evidence against a switch-table target route to standalone `0x005abb20`.
- User-list constructor cache decompile was sampled for parse offsets. `UserListDialogPane::UserListDialogPane` reads `sub_575480(packet + 1)`, `sub_575480(packet + 3)`, a byte at `packet + 5`, starts record parsing at offset `6`, and loops while the `packet + 3` word is nonzero. This validates the target's `payload + 3` word as the initial user-list entry-count/list-size field, not a generic latency value.
- `int_convert.py` verification was used for field offsets and constants: decimal `1305376` = `0x13eb20`, `1305380` = `0x13eb24`, `1305384` = `0x13eb28`, `1305388` = `0x13eb2c`, `1305392` = `0x13eb30`; `0x64` = decimal `100`, `0x12c` = decimal `300`, `0x1f4` = decimal `500`, `0x320` = decimal `800`; `30000` = `0x7530`, `60000` = `0xea60` with `--size 4`, `90000` = `0x15f90`, `150000` = `0x249f0`; allocation size `652` = `0x28c`.
- `by-memory/-coverage-report.md` was searched read-only. The live report is stale for this split area and did not contain a current [UID:0003US] row, while `auto-generated/-ag-memory-coverage.md` does list [UID:0003US] as emitting through [UID:00007B] to `auto-generated/NexusTK/map/LivingObjectPane.cpp`.

## Heuristic / Inference Reanalysis And Validation

### Direct Entry / Caller Route
- Finding: the standalone `0x005abb20` function has no proven direct caller.
- Evidence: target page reports no direct start xrefs; prewave function cache records `num_callers` `0`; cached `xrefs_to` is empty; existing B001 `0001KM` audit recorded no start xrefs.
- Rejected alternative: "ordinary direct call from `UserPane::HandleServerMessage`." The dispatcher cache decompile shows the opcode `0x36` body inline rather than a `sub_5ABB20` call.
- Rejected alternative: "hidden switch-table route to the standalone function." [UID:0003VC] says all 25 switch-table target dwords point inside [UID:0003VB], not to `0x005abb20`.
- Final direction: document [UID:0003US] as a retained modeled source-authored helper/copy with no proven caller, while documenting the live protocol route as [UID:0003VB] opcode `0x36` inline logic. This should cap confidence and block immediate formal C++ insertion, but it does not disprove `LivingObjectPane` ownership.

### Packet Subtype And Payload Shape
- Finding: the user-list server-message subtype is opcode `0x36`.
- Evidence: [UID:0003VB] decompile cache has `case 0x36u` and the full user-list staging/body. The first payload byte is the dispatch selector.
- Payload shape inference:
  - `payload[0]`: opcode/subtype `0x36`.
  - `payload + 1`: big-endian word read by `UserListDialogPane` constructor; exact semantic name remains unresolved, likely a category/list selector or current-filter field because the dialog constructor reads it before category/list setup.
  - `payload + 3`: big-endian word read by both [UID:0003US] and the constructor; high-confidence descriptive name `entryCount` / `userListEntryCount`. The constructor loops over this count when parsing user rows, while [UID:0003US] uses it for refresh/defer tiers.
  - `payload + 5`: one byte read by the constructor and applied to a dialog control; exact semantic name remains below source-quality proof.
  - `payload + 6`: start of repeated encoded user-list row data. [UID:0000FN] documents internal staged user rows as fixed `1044`-byte records, and the constructor allocates/populates list panes around those records.
- Rejected alternative: "the `payload + 3` word is latency/ping." The values `100/300/500/800` could superficially look like latency thresholds, but the constructor uses the same word as a loop count for initial row parsing. `entryCount`/`listSize` is the stronger inference.

### State Fields / Type Names
- Best descriptive field names for [UID:0003US] writes:
  - `this + 0x13eb20` / decimal `1305376` (Verified with `int_convert.py`): `m_deferredUserListPacket` or `m_userListPacketCopy`, a heap buffer pointer freed/reallocated for large or deferred list packets.
  - `this + 0x13eb24` / decimal `1305380` (Verified with `int_convert.py`): `m_deferredUserListPacketSize`, the copied payload size.
  - `this + 0x13eb28` / decimal `1305384` (Verified with `int_convert.py`): `m_userListPacketTick`, set to `g_pTimerMgr + 0x18` current tick when a packet is accepted.
  - `this + 0x13eb2c` / decimal `1305388` (Verified with `int_convert.py`): `m_nextUserListRefreshTick` or `m_userListDeferUntilTick`, set to current tick plus a tiered delay.
  - `this + 0x13eb30` / decimal `1305392` (Verified with `int_convert.py`): `m_skipNextUserListPacket`, a one-shot flag; when set, the handler clears it and skips the packet-buffer/timer update path but still executes the lazy-dialog open guard.
- Delay/defer tier behavior:
  - `entryCount < 100`: process/update immediately by setting `m_nextUserListRefreshTick` to the current tick and not copying the packet.
  - `100 <= entryCount < 300`: set current tick + `30000` and copy payload through `0x005a9310`.
  - `300 <= entryCount < 500`: set current tick + `60000` and copy payload through `0x005a9310`.
  - `500 <= entryCount < 800`: set current tick + `90000` and copy payload through `0x005a9310`.
  - `entryCount >= 800`: set current tick + `150000`, free the previous `m_deferredUserListPacket`, allocate a new buffer of the payload size, store pointer/size, and copy the full payload with `memmove`.
- `dword_67AB80` is resolved elsewhere as [UID:0000SI] `g_pTimerMgr`; the field read at `+0x18` is the current tick used broadly by timer/timing docs.
- Rejected alternative: "all `+0x13eb20` state is movement history only." [UID:0003UK] is currently named `SetMovementBuffer`, but [UID:00030B] already records normal callers from `sub_5A76C0` and `sub_5ABB20`; this target shows that `0x005a9310` copies deferred user-list packet data as well. The support name is too narrow.

### Source-Facing Method Name / Signature
- Best name: `LivingObjectPane::HandleUserListPacket`.
- Best signature: `bool LivingObjectPane::HandleUserListPacket(ServerMessageEvent *event)` with `event->payload` at offset `+0x0c` and `event->payloadSize` at offset `+0x10`; return `true`/`1`.
- Evidence: OOAnalyzer/cache classifies the standalone body as a `LivingObjectPane` method; the dispatcher inline case uses `a1 - 160` as the `LivingObjectPane` subobject receiver; [UID:00007B]/[UID:0000KU]/[UID:0001KM] all place this packet-tail family with `LivingObjectPane`.
- Rejected alternative: `UserPane::HandleUserListPacket`. The standalone signature is a `LivingObjectPane *this`, and the live `UserPane` dispatcher normalizes to the `LivingObjectPane` subobject before executing the logic.
- Rejected alternative: `UserListDialogPane::HandleUserListPacket`. `UserListDialogPane` has its own method at `0x0059d620`; this body only stages the initial packet and lazy-creates the dialog.

### Owner / Source Placement
- Keep direct owner [UID:00007B] `LivingObjectPane`; keep file route through [UID:0000KU] `NexusTK/map/LivingObjectPane.cpp`.
- Evidence for owner: source-family position in [UID:0001KM], `LivingObjectPane` receiver, shared `LivingObjectPane` packet state offsets, use of `0x005a9310`, and adjacency to other `LivingObjectPane` server-packet helpers.
- Evidence against moving to social/user-list file: the only social ownership signal is construction of `UserListDialogPane` when the singleton is null. That is a dependency and UI effect, not the receiver/source owner. The user-list feature source [UID:0000OZ] owns the dialog parsing/rendering methods, not this local-player packet staging state.
- Evidence against moving to [UID:0000P1] `UserPane`: the live dispatcher owns the opcode switch, but the staged fields and receiver are `LivingObjectPane` state. The dispatcher should reference this behavior as a dependency or inline duplicate, not own the standalone helper.

### Generated/Compiler Names And Support-Doc Pollution
- `sub_5ABB20` should be replaced in docs by inferred/descriptive `LivingObjectPane::HandleUserListPacket`.
- `sub_5A9310` should not stay documented as movement-only. Recommended descriptive support name is `CopyDeferredPacketBuffer`, `SetDeferredPacketBuffer`, or at minimum "movement/deferred-packet buffer copy helper" until all callers are audited.
- `dword_69B4E0` is [UID:0002WD]/[UID:0003EI] `g_pUserListDialogPane`; docs already support this and need no ownership change.
- `dword_67AB80` is [UID:0000SI] `g_pTimerMgr`; use that name for `+0x18` current tick reads.

### Score / C++ Impact
- Completion should rise because the packet subtype, payload count field, state offsets, threshold schedule, singleton/dialog path, and duplicate inline route are now documented.
- Confidence should remain below final-source confidence because current live IDA MCP was unavailable in this session, the standalone function has no proven caller/table route, and the final source representation must decide between "out-of-line helper kept for binary parity" and "inline dispatcher case body."
- Formal C++ should remain blank despite the suggested `87/86` metadata because the no-code proof below is target-specific and source-shape-specific.

## Open Questions Resolved Or Remaining
- Resolved: packet subtype is `0x36`.
- Resolved: the live packet-dispatch route is [UID:0003VB] `UserPane::HandleServerMessage` `case 0x36`, but that route does not call standalone `0x005abb20`.
- Resolved: no current evidence proves a direct caller, switch-table route, data-pointer route, or direct table target to standalone `0x005abb20`.
- Resolved with high-probability inference: `payload + 3` is the user-list entry count/list-size word because the `UserListDialogPane` constructor loops over the same word while parsing initial rows.
- Resolved with descriptive names: fields at `+0x13eb20` through `+0x13eb30` are deferred user-list packet pointer/size, user-list packet tick, next/defer tick, and skip-next flag.
- Remaining, score/C++-impacting: exact original source design for the duplicate/no-xref standalone body. It may have been an out-of-line `LivingObjectPane` method kept while the dispatcher inlined or duplicated the body, or a dead helper retained by object-file/linker settings. No defensible conclusion beyond "source-authored, no proven live entry route" is available without live IDA pointer scans/runtime evidence/source-map proof.
- Remaining, non-blocking for ownership: exact semantic names for `payload + 1` and `payload + 5`; current constructor evidence shows they are header fields consumed by `UserListDialogPane`, but [UID:0003US] itself only reads `payload + 3`.

## First-Draft C++ Recommendation / Target-Specific No-Code Proof
Do not populate [UID:0003US] formal `RECONSTRUCTION_CPP CODE` yet.

Target-specific proof:
- The standalone target body at `0x005abb20` has zero cached callers and empty cached `xrefs_to`.
- The real server-message subtype route is [UID:0003VB] `case 0x36`, whose decompile contains the same logic inline. [UID:0003VC] documents that switch-table targets stay inside [UID:0003VB], so the switch table is not a hidden route to [UID:0003US].
- Adding formal C++ for [UID:0003US] now would force a source-shape decision that is not proven by the target: either emit an uncalled `LivingObjectPane::HandleUserListPacket` method for binary-parity/source-retention reasons, or rewrite [UID:0003VB] to call that method even though the observed dispatcher body is inline. That decision must be coordinated with [UID:0003VB] C++ and the local-player packet-tail duplicate-helper strategy.
- The safe supervisor action is to keep the body documented, named, owned, and emitted-routed, but leave formal C++ blank until the dispatcher source-shape page explicitly decides whether opcode `0x36` should be represented as an inline case body or a call to an inline-able/out-of-line `LivingObjectPane` helper.

If the supervisor later accepts the helper-call source shape, use this signature as the target signature, but do not enter a body from this report alone:

```cpp
bool LivingObjectPane::HandleUserListPacket(ServerMessageEvent *event);
```

## Exact Supervisor Changes Required

### [UID:0003US] Target Metadata
Replace target metadata values with:

```text
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007B | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007B | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Keep `RECONSTRUCTION_CPP CODE` blank.

### [UID:0003US] Target Body Replacement
Placement: replace the current `## Summary`, `## Evidence`, and `## Open Questions` sections with:

```markdown
## Summary

This modeled `LivingObjectPane` method stages an opcode `0x36` user-list packet, records user-list refresh/defer timing from `g_pTimerMgr + 0x18`, copies large/deferred user-list packet payloads into `LivingObjectPane` state, honors a one-shot skip flag, and lazy-creates `UserListDialogPane` when `g_pUserListDialogPane` is null.

The standalone `0x005abb20` entry has no proven direct caller or switch-table route. The live `UserPane::HandleServerMessage` dispatcher contains a matching inline `case 0x36` body. Treat this function as a source-authored retained/out-of-line helper or duplicate body in the local-player packet tail, not as the proven dispatch target.

## Evidence

- Cached function metadata records `sub_5ABB20` at `0x005abb20`, size `0x14f` / 335 bytes, with IDA signature lead `char __thiscall(int this, int)` and Ghidra class lead `LivingObjectPane *this`.
- Cached caller/xref evidence reports zero callers and empty `xrefs_to` for the standalone entry.
- [UID:0003VB] `UserPane::HandleServerMessage` decompile shows opcode `case 0x36u` executing the same user-list staging logic inline after converting the `UserPane` facet to the `LivingObjectPane` subobject with `a1 - 160`.
- [UID:0003VC] switch-table evidence records 25 dword entries that all point back inside [UID:0003VB], rejecting a hidden switch-table route to standalone `0x005abb20`.
- The packet context argument uses `+0x0c` as payload pointer and `+0x10` as payload size. `payload[0]` is opcode `0x36`; `payload + 3` is a big-endian user-list entry count/list-size word read through `0x00575480`.
- `UserListDialogPane::UserListDialogPane` reads the same `payload + 3` word and loops over it while parsing initial user-list rows, supporting the `entryCount` inference. It also reads a header word at `payload + 1`, a byte at `payload + 5`, and begins row parsing at `payload + 6`.
- Field offsets verified with `int_convert.py`: `this + 0x13eb20` is the deferred packet buffer pointer, `+0x13eb24` is the copied payload size, `+0x13eb28` stores the current user-list packet tick, `+0x13eb2c` stores the next/defer tick, and `+0x13eb30` is the one-shot skip flag.
- Entry-count tiers are `100`, `300`, `500`, and `800` entries (constants verified with `int_convert.py`). The method sets next/defer tick to current, current + `30000`, current + `60000`, current + `90000`, or current + `150000`; middle tiers copy through `0x005a9310`, while the largest tier frees/reallocates/copies the full payload directly.
- `dword_69B4E0` is [UID:0002WD]/[UID:0003EI] `g_pUserListDialogPane`; when null, the method allocates `652` bytes (`0x28c`, verified with `int_convert.py`) and calls `UserListDialogPane` constructor `0x0059bc90` with the packet payload pointer.

## Source-Quality Notes

- Source-facing name: inferred/descriptive `LivingObjectPane::HandleUserListPacket`.
- Source-facing signature: `bool LivingObjectPane::HandleUserListPacket(ServerMessageEvent *event)` or project-local equivalent; return is byte truth `1`.
- Best field names: `m_deferredUserListPacket`, `m_deferredUserListPacketSize`, `m_userListPacketTick`, `m_nextUserListRefreshTick` or `m_userListDeferUntilTick`, and `m_skipNextUserListPacket`.
- Support helper `0x005a9310` is not movement-only. This target proves it also copies deferred user-list packet payloads; document or rename it as a movement/deferred-packet buffer copy helper.
- Formal C++ remains blank because the standalone function has no proven live route and duplicates/aligns with inline `UserPane::HandleServerMessage` `case 0x36`; the dispatcher/source-shape decision must be made before code entry.
```

### [UID:0003VB] UserPaneHandleServerMessage Support Update
Placement: in `Behavior`, after the delegated handler list, add:

```markdown
- Opcode `0x36` is the user-list packet path. The decompile contains the user-list staging/dialog-open body inline rather than an ordinary call to [UID:0003US]. That body normalizes the receiver to the `LivingObjectPane` subobject, reads the packet context payload pointer/size, tiers the `payload + 3` entry-count word, updates deferred user-list packet state, and lazy-creates `UserListDialogPane` when `g_pUserListDialogPane` is null. [UID:0003US] remains a modeled standalone duplicate/helper with no proven direct caller.
```

### [UID:0003VC] Switch Table Support Update
Placement: in `Evidence`, add:

```markdown
- Reanalysis for [UID:0003US] confirms the opcode `0x36` switch route stays inside [UID:0003VB]. The switch table does not target standalone `0x005abb20`; it targets the dispatcher-internal case body.
```

### [UID:0003UK] SetMovementBuffer Support Update
Placement: replace the current `## Summary` with:

```markdown
## Summary

This helper replaces/copies a `LivingObjectPane` deferred packet/history buffer. The current filename `SetMovementBuffer` is too narrow: in addition to movement/prediction use, [UID:0003US] and the inline [UID:0003VB] opcode `0x36` path call `0x005a9310` to copy deferred user-list packet payloads for medium-sized user-list responses. Prefer a future source-facing name such as `CopyDeferredPacketBuffer` or document the dual movement/user-list packet-buffer role until all callers are audited.
```

### [UID:0001KM] Local-Player Split Index Update
Placement: in the function map row for `0x005abb20`, replace the role cell with:

```text
User-list packet staging helper; no direct xrefs to the standalone function, while [UID:0003VB] opcode `0x36` contains the same logic inline. Reads the packet context payload at `+0x0c/+0x10`, tiers the `payload+3` entry count, updates deferred user-list packet state at `LivingObjectPane+0x13eb20..0x13eb30`, and lazy-creates `UserListDialogPane`.
```

### [UID:00007B] LivingObjectPane Class Update
Placement: in `Boundary Caveats`, add:

```markdown
- [UID:0003US] `0x005abb20-0x005abc6f` is a modeled `LivingObjectPane` user-list packet helper with no proven caller/xref route. The live `UserPane::HandleServerMessage` opcode `0x36` body contains matching logic inline, so final class C++ must coordinate the duplicate helper versus inline-dispatch source shape before emitting this method body.
```

### [UID:0000KU] LivingObjectPane File Update
Placement: in `Boundary Notes`, add:

```markdown
- The user-list packet path at [UID:0003US] remains part of the `LivingObjectPane.cpp` source family because it mutates `LivingObjectPane` local-player packet state and lazy-creates the social user-list dialog as a dependency. However, no direct caller/table route to the standalone `0x005abb20` function is currently proven; [UID:0003VB] opcode `0x36` contains the same body inline. Do not emit final source for this helper until the dispatcher/source-shape decision is coordinated.
```

## Coverage Report Replacement Text
The live `by-memory/-coverage-report.md` search did not find a current [UID:0003US] row, while `auto-generated/-ag-memory-coverage.md` does list [UID:0003US] as emitted through [UID:00007B]. The supervisor should insert or replace the stale missing child row in address order under the [UID:0001KM] local-player split subtree, immediately after [UID:0003UR] `0x005ab860-0x005aba7b.LivingObjectPaneHandleChatMessagePacket` and before [UID:0003UT] `0x005abda0-0x005abee8.LivingObjectPaneHandleUIPanelSwitchPacket`.

Exact row text:

```text
        - [UID:0003US][0x005abb20-0x005abc6f.LivingObjectPaneHandleUserListPacket](by-memory/0x005abb20-0x005abc6f.LivingObjectPaneHandleUserListPacket.md) 0x005abb20-0x005abc6f | modeled no-direct-xref packet helper | LivingObjectPaneHandleUserListPacket : reconstructable : 87% : strong : Source-authored user-list packet staging helper for opcode 0x36; cached caller/xref evidence reports no direct route to standalone 0x005abb20, while [UID:0003VB] contains the same opcode 0x36 logic inline and [UID:0003VC] switch-table entries stay inside the dispatcher. Reads packet context payload at +0x0c/+0x10, treats payload+3 as the big-endian user-list entry count, records g_pTimerMgr+0x18 into LivingObjectPane+0x13eb28, sets next/defer tick at +0x13eb2c by <100/<300/<500/<800 count tiers, copies deferred packet data at +0x13eb20/+0x13eb24 through 0x005a9310 or direct allocation/memmove, honors the +0x13eb30 skip flag, and lazy-creates UserListDialogPane through g_pUserListDialogPane when absent; formal C++ remains blank pending duplicate-helper versus inline-dispatch source-shape decision.
```

Do not edit `by-memory/-coverage-report.md` directly from this report.

## Validator Results
- No validator command was run. This was a report-only assignment and no by-* docs or coverage files were edited.

## Changed Files
- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B001/research/0003US-LivingObjectPaneHandleUserListPacket-source-quality.md`
- Modified: none outside this B001 research report.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003US","source_path":"executed-b-agent-research/B001/0003US-LivingObjectPaneHandleUserListPacket-source-quality.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
