** TARGET-REPORT-UID:0003VB **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0003VB / 0003US UserPane User-List Dispatch Source-Shape Research

## Finalized Report / Current Recommendation
- Assignment id: `B001-goal2-userpane-userlist-dispatch-source-shape-0003VB-0003US-20260618`.
- Primary target: [UID:0003VB] `by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md`.
- Support target: [UID:0003US] `by-memory/0x005abb20-0x005abc6f.LivingObjectPaneHandleUserListPacket.md`.
- Final source-shape decision: opcode `0x36` belongs to [UID:0003VB] as an inline `UserPane::HandleServerMessage` dispatcher case. Do not rewrite the dispatcher as an ordinary call to standalone [UID:0003US].
- Final [UID:0003US] disposition: keep it as a documented, `LivingObjectPane`-owned retained duplicate/out-of-line helper body with no proven live route. The helper body is source-shaped and behaviorally useful, but current evidence rejects treating `0x005abb20` as the live opcode `0x36` dispatch target.
- Metadata recommendation for [UID:0003VB]: keep `CANONICAL_OWNER:0000FQ`, keep `RECONSTRUCTABLE:TRUE`, keep `EMITTER_UIDS:0000FQ`, raise to `COMPLETION:87`, `CONFIDENCE:89`, and keep formal C++ blank under the target-specific no-code proof below.
- Metadata recommendation for [UID:0003US]: keep `CANONICAL_OWNER:00007B`, keep `RECONSTRUCTABLE:TRUE`, keep `EMITTER_UIDS:00007B`, raise to `COMPLETION:88`, `CONFIDENCE:88`, and keep formal C++ blank under the target-specific no-code proof below.
- No owner/emitter change is recommended for [UID:0003VC]. It remains non-reconstructable switch-table data owned by the [UID:0003VB] source switch.

## Evidence Checked
- Required B001/supervisor context was read earlier in the active assignment thread: `Agent-B001/goal.md`, `Agent-B001/notes.md`, `Supervisor.md`, `by-structure.md`, `inference_research.md`, and `proposed-source-tree.md`.
- Current target page [UID:0003VB] was rechecked. It is currently `86/88`, `RECONSTRUCTABLE:TRUE`, owner/emitter [UID:0000FQ], blank formal C++. It documents `UserPane::HandleServerMessage` as a virtual dispatcher at `0x005a76c0-0x005a82bd`, with [UID:0003VC] as the compiler switch-table child.
- Current [UID:0003VB] behavior text already records opcode `0x36` as inline user-list staging/dialog creation and not an ordinary call to [UID:0003US]. This report validates and strengthens that claim with a PE-aware no-route scan.
- Current support page [UID:0003US] was rechecked. It is currently `87/86`, `RECONSTRUCTABLE:TRUE`, owner/emitter [UID:00007B], blank formal C++. It documents a `LivingObjectPane` user-list packet helper at `0x005abb20-0x005abc6f`, zero cached callers/xrefs, and matching inline logic in [UID:0003VB].
- Current switch-table page [UID:0003VC] was rechecked. It documents `0x005a82bd-0x005a83b0` as non-emitting switch-table/alignment data: twenty-five dword target entries at `0x005a82c0-0x005a8324` all point inside [UID:0003VB], followed by selector/table bytes and `0xcc` alignment. It explicitly says opcode `0x36` routes to the dispatcher-internal case body, not standalone `0x005abb20`.
- Prior accepted/executed B001 [UID:0003US] report was rechecked from `Agent-B001/research/executed/0003US-LivingObjectPaneHandleUserListPacket-source-quality.md`. The supervisor already accepted its packet field, user-list state, support-note, and coverage row work; this report supersedes only the previously open duplicate-helper versus inline-dispatch source-shape decision.
- Function cache for `0x005abb20` was checked earlier in this active analysis. It records preferred name `sub_5ABB20`, Ghidra lead `undefined4 __thiscall meth_0x5abb20(LivingObjectPane *this, int param_1)`, IDA lead `char __thiscall(int this, int)`, size `335` bytes, `num_callers` `0` in both Ghidra/IDA cache fields, normalized caller list `[]`, and callees `0x00575480`, `0x005c7799`, `0x005c7790`, `0x005c95b0`, `0x005a9310`, `0x004f4aa0`, and `0x0059bc90`.
- Function cache for `0x005a76c0` was checked earlier in this active analysis. It records preferred name `sub_5A76C0`, size `3069` bytes, one IDA caller through the vtable route, 51/52 callees, and a switch on the first payload byte. Its opcode `0x36` body normalizes the receiver to the `LivingObjectPane` subobject with `a1 - 160` and contains the full user-list staging path inline.
- Direct vtable route was checked in [UID:0003VB], [UID:0000FQ], and [UID:0000P1]. The only raw absolute pointer to `0x005a76c0` is `0x0062efa0`, the `UserPane` vtable slot for the server-message handler.
- Read-only PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` was run against target VA `0x005abb20`. The PE scan found `AbsoluteVAHits=0`, `RVAHits=0`, and `DirectRel32Edges=0`. This rejects a hidden absolute pointer, target-RVA table entry, or direct call/jump/conditional branch route to standalone [UID:0003US] in the raw image.
- User-list constructor support was rechecked through [UID:0001KI], [UID:0000FN], [UID:0000FO], and [UID:0000OZ]. `UserListDialogPane::UserListDialogPane` has callers at `0x005087f4`, `0x00513c6c`, `0x005a7ccb`, and `0x005abc54`; the last two correspond to [UID:0003VB] inline opcode `0x36` and [UID:0003US] standalone duplicate/helper creation paths.
- Constructor packet-shape evidence was rechecked. `UserListDialogPane::UserListDialogPane` reads a big-endian word at `payload + 1`, reads the same big-endian word at `payload + 3` that [UID:0003VB]/[UID:0003US] use for deferral tiers, reads one byte at `payload + 5`, starts row parsing at `payload + 6`, and creates five `UserListPane` instances around fixed `1044`-byte user-row records.
- `g_pUserListDialogPane` support was rechecked. Exact storage child [UID:0002WD] reports current live bytes `00 00 00 00`, not the older stale `ff ff ff ff` wording still present in [UID:0003EI] and the live `by-memory/-coverage-report.md` row.
- Generated output was checked. `auto-generated/NexusTK/ui/panels/UserPane.cpp` and `auto-generated/NexusTK/social/UserListDialogPane.cpp` are zero-byte files. `auto-generated/NexusTK/map/LivingObjectPane.cpp` exists, but no [UID:0003US] formal body or user-list references were found by text search. Generated source therefore does not provide contrary source-shape evidence.
- Current live `by-memory/-coverage-report.md` was searched read-only. It contains a [UID:0003US] row at line 3121, but does not contain a [UID:0003VB] row despite `auto-generated/-ag-memory-coverage.md` listing [UID:0003VB] as an emitting child to `auto-generated/NexusTK/ui/panels/UserPane.cpp`.
- Current-session live IDA MCP was not available earlier in this active assignment thread: attempting `tools/list` at `http://127.0.0.1:13337/mcp` returned `Unable to connect to the remote server`. This report relies on existing IDA-backed by-* pages, read-only cache/decompile evidence, and the local read-only PE route scan.

## Heuristic / Inference Reanalysis And Validation

### Direct Entry / Caller Route To `0x005abb20`
- Finding: [UID:0003US] has no proven live direct entry route.
- Positive evidence for no-route: [UID:0003US] records zero cached callers/xrefs; the cache normalized caller list is empty; [UID:0001KM] carries the same no-direct-xref caveat; and the current PE scan found no absolute VA, no RVA, and no direct rel32 edge to `0x005abb20`.
- Rejected alternative: "the `UserPane::HandleServerMessage` opcode `0x36` case calls `LivingObjectPane::HandleUserListPacket`." [UID:0003VB] decompile contains the body inline and not a call; [UID:0003US] callers remain empty.
- Rejected alternative: "a raw pointer table or switch table targets `0x005abb20`." [UID:0003VC] says all twenty-five dword-like switch entries target inside [UID:0003VB], and the raw PE scan found no VA/RVA table reference to `0x005abb20`.
- Final direction: [UID:0003US] should remain a source-quality retained helper/duplicate documentation page, not the live dispatch target.

### Opcode `0x36` Switch Shape
- Finding: opcode `0x36` is an inline dispatcher case in [UID:0003VB].
- Evidence: [UID:0003VB] switches on `*payload`; the opcode `0x36` body begins by computing the `LivingObjectPane` subobject from the `UserPane` facet (`a1 - 160` in the decompile) and then performs the same writes/calls as standalone [UID:0003US].
- Evidence: the switch-table child [UID:0003VC] is compiler-generated support data for [UID:0003VB]. Its target run stays inside the dispatcher body; it is not a pointer bridge into the local-player packet tail at `0x005abb20`.
- Rejected alternative: "opcode `0x36` should be represented as a `LivingObjectPane` public method call from [UID:0003VB]." That would introduce a call edge contradicted by the binary body and route evidence.
- Rejected alternative: "opcode `0x36` should be moved wholly to `UserListDialogPane`." The dialog parses and renders user-list rows, but the packet deferral fields are `LivingObjectPane` local-player state at `+0x13eb20..+0x13eb30`; the dispatcher owns the live incoming-message route.

### Inline Versus Duplicate Helper Source Explanation
- Best source-shape explanation: the compiled binary contains two equivalent bodies: a live inline dispatcher body in [UID:0003VB] and an unreferenced standalone `LivingObjectPane`-receiver body in [UID:0003US].
- High-probability source explanations that remain possible: the original source had a helper defined in a header or same compilation unit and the compiler emitted both an inline copy and an out-of-line copy; or the source had duplicate handwritten logic in a live dispatcher and a retained helper that is currently dead/unused.
- Strongly rejected explanation: ordinary cross-translation-unit inlining from `LivingObjectPane.cpp` into `UserPane.cpp` plus a retained external function, without link-time code generation evidence. The project source placement currently routes [UID:0003VB] through `NexusTK/ui/panels/UserPane.cpp` and [UID:0003US] through `NexusTK/map/LivingObjectPane.cpp`; a mid-2000s non-LTO build would not normally inline a non-header out-of-line method across that boundary.
- Practical reconstruction rule: the future [UID:0003VB] formal C++ should express opcode `0x36` inline in `UserPane::HandleServerMessage`. It may use a local descriptive helper inside the future whole-method draft only if that helper does not imply a binary call to `0x005abb20`. It should not call [UID:0003US] unless future direct evidence proves the original source intended that route.

### Packet Field Names And Payload Shape
- `payload[0]`: high-confidence source-facing name `opcode` or `messageOpcode`; value `0x36` selects the user-list path in [UID:0003VB].
- `payload + 1`: best defensible source-facing name `userListHeaderWord` or `userListRequestWord`. Evidence: `UserListDialogPane::UserListDialogPane` reads this big-endian word before row parsing and before control setup. Current evidence does not prove whether it is page, category, total-user count, or request id. Do not call it `entryCount`.
- `payload + 3`: high-confidence source-facing name `userListEntryCount` or `entryCount`. Evidence: [UID:0003VB]/[UID:0003US] read it with `0x00575480` and compare it against `100`, `300`, `500`, and `800` for refresh/defer tiers; `UserListDialogPane::UserListDialogPane` reads the same word and loops over it while parsing rows.
- `payload + 5`: best defensible source-facing name `userListSortOrViewMode` or `userListModeByte`. Evidence: the constructor reads this byte and passes/applies it during dialog/list control initialization; current docs do not prove whether it is sort mode, category mode, status filter, or selected tab. Do not over-name it as `sortMode` without another constructor-field audit.
- `payload + 6`: high-confidence source-facing name `encodedUserListRows` or `userListRows`. Evidence: the constructor starts record parsing at this offset after the one-byte opcode, two words, and one mode byte, then populates fixed `1044`-byte `UserListPane` row records.
- Packet context fields: `event + 0x0c` is the payload pointer and `event + 0x10` is the payload byte count. Both [UID:0003VB] and [UID:0003US] use those fields.
- Rejected alternative: "`payload + 3` is a latency/ping value." The tier thresholds could superficially resemble latency bands, but constructor row parsing uses the same word as a count. `entryCount`/`listSize` is stronger.

### Deferred User-List State Field Names
- `LivingObjectPane + 0x13eb20`: best name `m_deferredUserListPacket`; heap buffer pointer freed/reallocated for large direct-copy tier and copied into by `0x005a9310` for medium tiers.
- `LivingObjectPane + 0x13eb24`: best name `m_deferredUserListPacketSize`; copied payload byte count.
- `LivingObjectPane + 0x13eb28`: best name `m_userListPacketTick`; current tick copied from `g_pTimerMgr + 0x18` when a non-skipped packet is accepted.
- `LivingObjectPane + 0x13eb2c`: best name `m_userListDeferUntilTick` or `m_nextUserListRefreshTick`; set to current tick, current + `30000`, current + `60000`, current + `90000`, or current + `150000` by entry-count tier.
- `LivingObjectPane + 0x13eb30`: best name `m_skipNextUserListPacket`; one-shot flag cleared by the handler. When set, the handler skips the timing/buffer update path but still performs the lazy dialog-open guard.
- The `0x005a9310` helper should remain documented as broader than movement: this user-list path proves it also copies deferred packet payloads. Preferred descriptive name remains `CopyDeferredPacketBuffer` or equivalent until all callers are audited.

### Source Placement
- [UID:0003VB] remains a `UserPane` virtual method owned by [UID:0000FQ] and emitted through [UID:0000FQ]/[UID:0000P1] `NexusTK/ui/panels/UserPane.cpp`. Evidence is the `0x0062efa0` `UserPane` vtable slot, [UID:0000FQ] method table, and switch-table child [UID:0003VC].
- [UID:0003US] remains `LivingObjectPane`-owned documentation under [UID:00007B]/[UID:0000KU] because the receiver and mutated fields are `LivingObjectPane` local-player state. However, source emission must treat it as a retained duplicate/no-live-route body unless future evidence proves a real call route.
- `UserListDialogPane.cpp` remains a dependency owner for dialog construction, row parsing, and singleton storage, not the packet deferral owner.

### Current Docs Validated Or Contradicted
- Validated: [UID:0003VB] current claim that opcode `0x36` appears inline and not as an ordinary call to [UID:0003US].
- Validated and strengthened: [UID:0003US] current no-direct-caller claim. The new PE scan adds raw VA/RVA/rel32 negative evidence.
- Validated: [UID:0003VC] current statement that switch-table targets remain inside [UID:0003VB].
- Validated: [UID:0003US] packet field and state-field names from the accepted previous B001 report, except that `payload + 1` and `payload + 5` remain descriptive rather than final semantic names.
- Contradicted/stale support wording: [UID:0003EI] still says [UID:0002WD] is initialized as `ff ff ff ff`; [UID:0002WD] current page says live bytes are `00 00 00 00` and supersedes that wording. The live `by-memory/-coverage-report.md` [UID:0002WD] row has the same stale state/assignment issue.
- Contradicted/stale coverage structure: live `by-memory/-coverage-report.md` lacks a [UID:0003VB] row even though [UID:0003VB] is an emitting exact child in `auto-generated/-ag-memory-coverage.md`.

## Open Questions Resolved Or Remaining
- Resolved: direct caller route to [UID:0003US]. No route is proven; raw PE scan found no VA/RVA/rel32 edge.
- Resolved: hidden packet-dispatch/switch-table route to [UID:0003US]. [UID:0003VC] targets stay inside [UID:0003VB], and PE route scan found no hidden pointer/table evidence.
- Resolved: opcode `0x36` source shape. Live source representation should be inline inside [UID:0003VB], not a dispatcher call to [UID:0003US].
- Resolved: whether first-draft formal C++ belongs in [UID:0003VB], [UID:0003US], both, or neither. It belongs in neither formal block now; future whole-method C++ for [UID:0003VB] should include the opcode `0x36` case inline, while [UID:0003US] should remain blank until a real route or explicit retained-dead-helper source policy is approved.
- Resolved: `payload + 3` is `userListEntryCount`/`entryCount`, not latency.
- Partially resolved with best descriptive names: `payload + 1` is a constructor-consumed `userListHeaderWord`/`userListRequestWord`; `payload + 5` is a constructor-consumed `userListSortOrViewMode`/`userListModeByte`. Exact semantic names remain below proof because the current constructor docs do not trace the final member/control assignment deeply enough. This does not block the opcode `0x36` source-shape decision, but it continues to block full formal C++ for [UID:0003VB].
- Remaining blocker for [UID:0003VB] formal C++: the page spans the entire `UserPane::HandleServerMessage` dispatcher with approximately 25 cases and 51/52 callees. Only opcode `0x36` has been settled here; other packet case names and field names remain provisional on the target page.
- Remaining blocker for [UID:0003US] formal C++: the standalone function has no proven live route and duplicates inline dispatcher logic. Emitting it would create an uncalled LivingObjectPane method or force a call shape contradicted by the binary.

## First-Draft C++ Recommendation / Target-Specific No-Code Proof

Do not populate formal C++ for [UID:0003VB] in this pass. The target covers the full `UserPane::HandleServerMessage` function, not a small exact opcode child. Entering only the opcode `0x36` case into the formal reconstruction block would be a partial body for a whole-method by-memory page. The correct future formal C++ belongs in [UID:0003VB] only after the remaining dispatcher cases and event/field names are source-quality enough to reconstruct the complete method.

Do not populate formal C++ for [UID:0003US] in this pass. The standalone `0x005abb20` body has no proven caller, no switch-table target, no raw VA/RVA pointer route, and no direct rel32 route. Emitting it as a normal `LivingObjectPane::HandleUserListPacket` method would add source API that the live binary does not route through, while changing [UID:0003VB] to call it would contradict the inline dispatcher body.

When [UID:0003VB] eventually receives a complete whole-method draft, opcode `0x36` should be represented inline with source-facing structure like the following. This is documentation-only draft text for future incorporation, not a formal C++ block to insert now:

```cpp
case 0x36:
{
    LivingObjectPane *living = GetLivingObjectPaneFromUserPane(this);
    const unsigned char *payload = event->m_payload;
    unsigned int payloadSize = event->m_payloadSize;

    if (living->m_skipNextUserListPacket) {
        living->m_skipNextUserListPacket = false;
    } else {
        unsigned short entryCount = ReadPacketWord(payload + 3);
        unsigned int now = g_pTimerMgr->m_currentTick;

        living->m_userListPacketTick = now;
        if (entryCount < 100) {
            living->m_userListDeferUntilTick = now;
        } else if (entryCount < 300) {
            living->m_userListDeferUntilTick = now + 30000;
            living->CopyDeferredPacketBuffer(payload, payloadSize);
        } else if (entryCount < 500) {
            living->m_userListDeferUntilTick = now + 60000;
            living->CopyDeferredPacketBuffer(payload, payloadSize);
        } else if (entryCount < 800) {
            living->m_userListDeferUntilTick = now + 90000;
            living->CopyDeferredPacketBuffer(payload, payloadSize);
        } else {
            living->m_userListDeferUntilTick = now + 150000;
            free(living->m_deferredUserListPacket);
            living->m_deferredUserListPacket = static_cast<unsigned char *>(malloc(payloadSize));
            living->m_deferredUserListPacketSize = payloadSize;
            memmove(living->m_deferredUserListPacket, payload, payloadSize);
        }
    }

    if (g_pUserListDialogPane == 0) {
        new UserListDialogPane(payload);
    }
    return true;
}
```

Notes for future C++:
- `GetLivingObjectPaneFromUserPane(this)` is a descriptive placeholder for the binary's `UserPane` facet to `LivingObjectPane` subobject adjustment (`a1 - 160`). Replace with the actual class/facet accessor only when the class layout docs support it.
- `ReadPacketWord` is the source-facing role of `0x00575480`.
- `CopyDeferredPacketBuffer` is the source-facing role of `0x005a9310` in this path; do not retain a movement-only helper name.
- `event->m_payload` and `event->m_payloadSize` are descriptive names for packet context fields `+0x0c` and `+0x10`.
- `payload + 1` and `payload + 5` are intentionally not named in this case body because [UID:0003VB]/[UID:0003US] do not consume them directly; the dialog constructor does.

## Exact Supervisor Changes Required

### [UID:0003VB] Metadata
Replace the metadata values with:

```text
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000FQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000FQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Keep [UID:0003VB] formal C++ blank.

### [UID:0003VB] Behavior Replacement
Placement: replace the current opcode `0x36` paragraph in `## Behavior`.

```markdown
Opcode `0x36` is the live user-list packet path and should be source-shaped as an inline `UserPane::HandleServerMessage` dispatcher case. The decompile contains the user-list staging/dialog-open body inline rather than an ordinary call to [UID:0003US][0x005abb20-0x005abc6f.LivingObjectPaneHandleUserListPacket](by-memory/0x005abb20-0x005abc6f.LivingObjectPaneHandleUserListPacket.md). That body normalizes the `UserPane` facet to the `LivingObjectPane` subobject, reads the packet context payload pointer/size at `event+0x0c/+0x10`, tiers the `payload+3` `userListEntryCount` word, updates deferred user-list packet state at `LivingObjectPane+0x13eb20..+0x13eb30`, and lazy-creates `UserListDialogPane` when `g_pUserListDialogPane` is null. Treat [UID:0003US] as a retained duplicate/out-of-line helper body with no proven live route; do not make this dispatcher case call `0x005abb20` unless future evidence proves a real source policy that requires it.
```

### [UID:0003VB] Evidence Addition
Placement: add to `## Evidence`.

```markdown
- 2026-06-18 B001 source-shape route audit for opcode `0x36`: [UID:0003US] cached callers/xrefs are empty, [UID:0003VC] switch-table entries target only inside this dispatcher, and a PE-aware scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` found no absolute VA bytes, no target-RVA bytes, and no direct rel32 call/jump/conditional-branch edge to standalone `0x005abb20`. This validates the inline dispatcher-case representation and rejects an ordinary call to [UID:0003US].
```

### [UID:0003VB] Source-Quality Note Addition
Placement: add to `## Source Quality Notes`.

```markdown
- Formal C++ remains blank despite the resolved opcode `0x36` shape because this page covers the whole `UserPane::HandleServerMessage` dispatcher. A partial C++ body for only one case would misrepresent the target. Future whole-method C++ should include opcode `0x36` inline and may use descriptive local helper names only if they do not imply a binary call to standalone `0x005abb20`.
```

### [UID:0003US] Metadata
Replace the metadata values with:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007B | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007B | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Keep [UID:0003US] formal C++ blank.

### [UID:0003US] Summary Replacement
Placement: replace the second paragraph in `## Summary`.

```markdown
The standalone `0x005abb20` entry has no proven direct caller, switch-table route, pointer-table route, or raw PE route. The live [UID:0003VB][0x005a76c0-0x005a82bd.UserPaneHandleServerMessage](by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md) dispatcher contains the matching `case 0x36` body inline. Treat this function as a `LivingObjectPane`-owned retained duplicate/out-of-line helper body in the local-player packet tail, not as the live packet-dispatch target and not as a method that [UID:0003VB] should be rewritten to call.
```

### [UID:0003US] Evidence Additions
Placement: add to `## Evidence`.

```markdown
- 2026-06-18 B001 PE-aware route scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` for target VA `0x005abb20` found `AbsoluteVAHits=0`, `RVAHits=0`, and `DirectRel32Edges=0`. This adds raw-image negative evidence to the existing cached no-caller/no-xref evidence.
- Source-shape decision: final live source should keep opcode `0x36` inline in [UID:0003VB] `UserPane::HandleServerMessage`. This [UID:0003US] body remains useful as source-quality evidence for `LivingObjectPane` state names and packet staging behavior, but formal C++ should not be populated unless a retained-dead-helper emission policy is explicitly approved.
```

### [UID:0003US] Source-Quality Notes Replacement
Placement: replace the current formal-C++ bullet in `## Source-Quality Notes`.

```markdown
- Formal C++ remains blank under a target-specific no-code proof: standalone `0x005abb20` has zero cached callers/xrefs, [UID:0003VC] does not route to it, a PE-aware VA/RVA/rel32 scan found no raw route, and the live [UID:0003VB] dispatcher contains the same opcode `0x36` body inline. Emitting this as a normal called `LivingObjectPane` method would either create uncalled source API or force a call shape contradicted by the binary.
```

### [UID:0003VC] Evidence Addition
Placement: add to `## Evidence`.

```markdown
- 2026-06-18 B001 route audit also scanned the raw PE for standalone [UID:0003US] target `0x005abb20` and found no absolute VA, no target-RVA, and no direct rel32 edge. This supports the existing switch-table conclusion that opcode `0x36` targets the dispatcher-internal case body rather than a hidden standalone helper.
```

### [UID:0000FQ] UserPane Class Support Addition
Placement: add to `## Evidence Notes` after the vtable-slot evidence.

```markdown
- 2026-06-18 B001 opcode `0x36` source-shape audit: [UID:0003VB] owns the live inline user-list packet dispatcher case. [UID:0003US] is retained as a `LivingObjectPane` duplicate/helper body with no proven live route; do not model `UserPane::OnServerMessage` as calling standalone `0x005abb20`.
```

No [UID:0000FQ] score change is required.

### [UID:0000P1] UserPane File Support Addition
Placement: add to `## Evidence Notes` near the [UID:0003VB] event-band split note.

```markdown
- 2026-06-18 B001 opcode `0x36` source-shape audit resolves the user-list packet path as inline source in `UserPane::HandleServerMessage`: [UID:0003VB] contains the live body, [UID:0003VC] switch data stays inside that method, and raw PE route scans found no direct or table route to standalone [UID:0003US] `0x005abb20`.
```

No [UID:0000P1] score change is required.

### [UID:00007B] LivingObjectPane Class Support Replacement
Placement: replace the current [UID:0003US] evidence-note bullet.

```markdown
- [UID:0003US][0x005abb20-0x005abc6f.LivingObjectPaneHandleUserListPacket](by-memory/0x005abb20-0x005abc6f.LivingObjectPaneHandleUserListPacket.md) is a modeled `LivingObjectPane` user-list packet helper/duplicate body with no proven caller/xref, switch-table, pointer-table, or raw PE route. The live [UID:0003VB][0x005a76c0-0x005a82bd.UserPaneHandleServerMessage](by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md) opcode `0x36` body contains matching logic inline, so final class C++ should not emit [UID:0003US] as a normally called method unless a future retained-dead-helper source policy is explicitly approved.
```

No [UID:00007B] score change is required.

### [UID:0000KU] LivingObjectPane File Support Replacement
Placement: replace the current [UID:0003US] boundary note.

```markdown
- The user-list packet body at [UID:0003US][0x005abb20-0x005abc6f.LivingObjectPaneHandleUserListPacket](by-memory/0x005abb20-0x005abc6f.LivingObjectPaneHandleUserListPacket.md) remains part of the `LivingObjectPane.cpp` source family for state/field documentation because it mutates `LivingObjectPane` local-player user-list packet fields and lazy-creates the social user-list dialog as a dependency. However, the live dispatch route is [UID:0003VB] opcode `0x36` inline in `UserPane::HandleServerMessage`: cached callers/xrefs for `0x005abb20` are empty, [UID:0003VC] switch-table entries stay inside the dispatcher, and raw PE VA/RVA/rel32 scans found no route to the standalone helper. Do not emit final formal C++ for [UID:0003US] as a called method unless future evidence changes that source-shape decision.
```

No [UID:0000KU] score change is required.

### [UID:0003EI] g_pUserListDialogPane Support Correction
Placement: in `## Evidence Notes`, replace the stale first bullet.

```markdown
- [UID:0002WD][0x0069b4e0-0x0069b4e4.g_pUserListDialogPane](by-memory/0x0069b4e0-0x0069b4e4.g_pUserListDialogPane.md) records the exact `0x4` / 4-byte `.data` slot (Verified with int_convert.py). The exact memory child reports current live IDA bytes `00 00 00 00` and twelve direct data xrefs, superseding older stale `ff ff ff ff` wording from the 2026-06-07 split pass.
```

No [UID:0003EI] score change is required for this assignment.

## Coverage Report Replacement Text

Do not edit `by-memory/-coverage-report.md` directly from this report. The supervisor should apply the following coverage changes if accepting the metadata/support recommendations.

### [UID:0003VB] Coverage Row Insert
Current live `by-memory/-coverage-report.md` does not contain a [UID:0003VB] row, while `auto-generated/-ag-memory-coverage.md` lists it as an emitting child. Insert this row in address order in the UserPane/local-player split area, after [UID:0003V9] `0x005a5bd0-0x005a7422.UserPaneHandleKeyEvent` and before [UID:0003VC] / [UID:0003VD] if those rows are present in the live report. If the live report still lacks the surrounding exact UserPane rows, insert it at the supervisor's regenerated [UID:0001KM]/UserPane child location in address order.

```text
        - [UID:0003VB][0x005a76c0-0x005a82bd.UserPaneHandleServerMessage](by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md) 0x005a76c0-0x005a82bd | UserPane virtual server-message dispatcher | UserPaneHandleServerMessage : reconstructable : 87% : very-strong : UserPane vtable-owned server-message dispatcher at 0x0062efa0 with compiler switch-table child [UID:0003VC][0x005a82bd-0x005a83b0.UserPaneHandleServerMessageSwitchTables](by-memory/0x005a82bd-0x005a83b0.UserPaneHandleServerMessageSwitchTables.md). Opcode 0x36 source shape is resolved as an inline dispatcher case that stages user-list packets on the LivingObjectPane subobject, reads packet payload at event+0x0c/+0x10, treats payload+3 as userListEntryCount, updates LivingObjectPane+0x13eb20..0x13eb30 deferred user-list fields, and lazy-creates UserListDialogPane when g_pUserListDialogPane is null. Do not rewrite this case as a call to [UID:0003US]: cached [UID:0003US] callers/xrefs are empty, [UID:0003VC] switch-table entries remain inside this method, and PE-aware VA/RVA/rel32 scans found no route to 0x005abb20. Formal C++ remains blank because the whole dispatcher still has unresolved packet-case/source-name coverage; future C++ should include opcode 0x36 inline.
```

### [UID:0003US] Coverage Row Replacement
Placement: replace the existing [UID:0003US] row currently present near line 3121.

```text
        - [UID:0003US][0x005abb20-0x005abc6f.LivingObjectPaneHandleUserListPacket](by-memory/0x005abb20-0x005abc6f.LivingObjectPaneHandleUserListPacket.md) 0x005abb20-0x005abc6f | retained duplicate/no-live-route packet helper | LivingObjectPaneHandleUserListPacket : reconstructable : 88% : strong : LivingObjectPane-owned retained duplicate/out-of-line helper body for opcode 0x36 user-list packet staging. It reads packet context payload at +0x0c/+0x10, treats payload+3 as the big-endian user-list entry count, records g_pTimerMgr+0x18 into LivingObjectPane+0x13eb28, sets next/defer tick at +0x13eb2c by <100/<300/<500/<800 count tiers, copies deferred packet data at +0x13eb20/+0x13eb24 through 0x005a9310 or direct allocation/memmove, honors the +0x13eb30 skip flag, and lazy-creates UserListDialogPane through g_pUserListDialogPane when absent. Source-shape is now resolved: live dispatch belongs inline in [UID:0003VB][0x005a76c0-0x005a82bd.UserPaneHandleServerMessage](by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md), while this standalone 0x005abb20 body has zero cached callers/xrefs, no [UID:0003VC] switch-table route, and no raw PE VA/RVA/rel32 route. Formal C++ remains blank under the retained-duplicate/no-live-route proof.
```

### [UID:0002WD] Support Coverage Row Replacement
Placement: replace the stale [UID:0002WD] row currently present near line 3810 if the supervisor is updating support coverage during this pass.

```text
        - [UID:0002WD][0x0069b4e0-0x0069b4e4.g_pUserListDialogPane](by-memory/0x0069b4e0-0x0069b4e4.g_pUserListDialogPane.md) 0x0069b4e0-0x0069b4e4 | global pointer | g_pUserListDialogPane : reconstructable : 87% : very-strong : Exact UserListDialogPane singleton slot assigned to [UID:0003EI][g_pUserListDialogPane](by-global/g_pUserListDialogPane.md); current live IDA bytes are zero-filled, slot size is 0x4/4, constructor publish/fallback refs occur at 0x0059bce4/0x0059bceb, consumers and cleanup include 0x005087c2, 0x00513c43, 0x0059e4cf, 0x0059ed8f, 0x0059eea1, 0x0059efe0, 0x0059f14a, 0x005a7c97, and 0x005abc28, and the direct global/file route clears the corrected gate. Older ff ff ff ff wording is stale.
```

## Validator Results
- No validator command was run. This was a report-only assignment and no by-* docs, generated reports/source, IDA DB, or `by-memory/-coverage-report.md` were edited.

## Changed Files
- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B001/research/0003VB-0003US-UserPaneUserListDispatchSourceShape-source-quality.md`

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0003VB-0003US-UserPaneUserListDispatchSourceShape-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:23","uid":"0003VB"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
