** TARGET-REPORT-UID:00023G **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00023G StaticObjectPaneSendInteractionPacket Source-Quality Report

## Final Recommendation

- Target UID: `00023G`
- Target path: `source-3/project-documentation/by-memory/0x00537ac0-0x00537b39.StaticObjectPaneSendInteractionPacket.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B006/research/00023G-StaticObjectPaneSendInteractionPacket-source-quality.md`
- Current target metadata observed: `COMPLETION:85`, `CONFIDENCE:86`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:0000O6`, `EMITTER_UIDS:0000O6`, blank formal C++.
- Report-only rule followed: no by-* docs, generated docs/source, IDA DB, or `by-memory/-coverage-report.md` were edited.

Recommendation after implementation:

- Keep `CANONICAL_OWNER:0000O6` and `EMITTER_UIDS:0000O6`; the direct source route remains [UID:0000O6] `StaticObjectPane`, proposed path `NexusTK/map/StaticObjectPane.cpp`.
- Raise target to `COMPLETION:88`, `CONFIDENCE:89`.
- Treat `0x00537ac0-0x00537b39` as an exact retained source-authored private `StaticObjectPane` method, best named `StaticObjectPane::SendInteractionPacket()`.
- Populate first-draft C++ for this exact target. The lack of an IDA-modeled function record and lack of direct caller xrefs should remain documented as reachability evidence, but they should no longer block code entry because the body is source-shaped, unique, fully understood, class-owned, and already above the active B-agent code-entry threshold.
- Do not merge this range into [UID:0001D6] `StaticObjectPaneCore`; keep both the checked virtual event handler and the raw private helper documented. The checked handler contains its own inline serialization in the compiled binary, while this target is the retained out-of-line helper body.

## Evidence Checked

Workflow and rule docs:

- `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B006/goal.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B006/notes.md`
- `source-3/project-documentation/by-structure.md`
- `source-3/project-documentation/tools/leaser/Agents/inference_research.md`
- `source-3/project-documentation/by-project-structure/proposed-source-tree.md`

Primary and support documentation:

- `by-memory/0x00537ac0-0x00537b39.StaticObjectPaneSendInteractionPacket.md`
- `by-memory/0x00537900-0x00537abf.StaticObjectPaneCore.md`
- `by-class/StaticObjectPane.md`
- `by-file/StaticObjectPane.md`
- `by-memory/0x00620340-0x006203ec.StaticObjectPaneVtableData.md`
- `by-memory/0x00537b40-0x005380af.ItemAndFlyingObjectPanes.md`
- `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md`
- `by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md`
- `by-file/PacketBuffer.md`
- `by-global/g_packetSender.md`
- `by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md`
- `by-memory/-coverage-report.md`, row context only; no edits made.
- `auto-generated/NexusTK/map/StaticObjectPane.cpp`, for current generated-output state only.

Checked-in export/local evidence:

- `source-3/core/data/cache/prewave/functions/0x00537ac0.json`
- `source-3/core/data/cache/prewave/functions/0x005379d0.json`
- `source-3/core/data/cache/prewave/functions/0x00575380.json`
- `source-3/core/data/cache/prewave/functions/0x005753a0.json`
- `source-3/core/data/cache/prewave/functions/0x00574bb0.json`
- Local PE: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- `tool_search` for live IDA/MCP/decompile tools returned no callable tools in this Codex session. This report therefore relies on current checked-in IDA-derived docs/exports plus local PE byte and reference scans.

Local PE checks performed:

- Parsed PE image base `0x00400000`; target VA `0x00537ac0` maps to file offset `0x136ec0`.
- Confirmed boundary bytes:
  - `0x00537abf` is `cc` padding after the checked handler range.
  - `0x00537ac0` begins `55 8b ec 83 ec 24 ...`, a normal frame/security-cookie prologue.
  - `0x00537b38` returns, followed by `0x00537b39-0x00537b40` `cc` padding before `ItemObjectPane`.
- Scanned the exact `0x79`-byte target body sequence and found exactly one hit, at VA `0x00537ac0`.
- Scanned little-endian target VA `0x00537ac0` and target RVA `0x00137ac0`; found zero hits.
- Positive-control pointer scan found one little-endian checked-handler VA `0x005379d0` hit at file `0x21edb8`, VA `0x006203b8`, matching the documented `StaticObjectPane` vtable/data reference.
- Direct call/control-flow positive controls matched docs: `QueueAndSendPacket` at `0x00574bb0` has 416 direct rel call hits, `PacketBufferWriteUInt8` at `0x00575380` has 1114, and `PacketBufferWriteUInt16BE` at `0x005753a0` has 222.
- A byte-oriented branch scan produced one apparent short-branch hit to `0x00537ac0` at `0x00537a5e`, but aligned byte context shows this is the `0x76` ModR/M byte inside `ff 76 60` (`push dword ptr [esi+0x60]`) in the checked handler packet write, not an instruction opcode. Reject it as a false positive; it is not caller evidence.

## Heuristic / Inference Reanalysis And Validation

### Boundary And Function Shape

The range is exactly `0x00537ac0-0x00537b39`, length `0x79` / 121 bytes. Ghidra prewave exports also model `0x00537ac0` as `FUN_00537ac0`, size `121`, no callers, four callees, and a `__fastcall`-looking one-parameter signature because the method receives `this` in `ECX`. IDA does not model it as a function, but the checked-in docs and local byte inspection agree on the source-shaped prologue/body/epilogue:

- frame setup with security cookie;
- `ESI = ECX`, therefore a `this` receiver;
- no stack arguments consumed by the final `ret`;
- stack buffer at `EBP-0x24`/nearby locals;
- calls to packet scalar writers;
- reads from `this+0x100` and `this+0x104`;
- calls `QueueAndSendPacket` with length `7`;
- security-cookie check and plain `ret`.

The function is not padding. It is not an adjustor thunk or compiler-generated destructor glue. It has ordinary local stack storage, data serialization calls, and a feature-specific packet payload. The correct entity kind should remain `raw-private-helper` or `private class helper`, but the source-facing interpretation should be tightened from "IDA-missed method body candidate" to "retained private class method".

### Owner, Emitter, And Source Placement

The best owner is `StaticObjectPane`, emitted through [UID:0000O6] `StaticObjectPane` at `NexusTK/map/StaticObjectPane.cpp`.

Evidence:

- The method uses `ECX` as a pane object and reads `this+0x100/+0x104`, the inherited `ObjectPane` tile/map coordinate fields used elsewhere in `StaticObjectPaneCore`.
- The preceding contiguous source island is [UID:0001D6] `StaticObjectPaneCore`, ending at `0x00537abf`.
- The successor at `0x00537b40` is the `ItemObjectPane` constructor; `0x00537b39-0x00537b40` is padding and not part of the helper.
- The packet payload is identical to the checked `StaticObjectPane::HandleStaticObjectEvent` send path in [UID:0001D6], minus the event type, bounds, and disabled-flag gates.
- [UID:0000E1] `StaticObjectPane` and [UID:0000O6] `StaticObjectPane` already list this range as part of the StaticObjectPane source cluster.

Rejected alternatives:

- File-static helper: rejected because the helper receives a class object in `ECX` and directly reads inherited pane fields. A file-static helper would require an explicit `StaticObjectPane *` parameter; the binary has a `thiscall`-style receiver.
- `ObjectPane` ownership: rejected because the opcode/subcommand and checked-handler relationship are StaticObjectPane-specific, and the immediate source neighborhood is the StaticObjectPane method island.
- `MapPane` ownership: rejected because no MapPane field is touched and no MapPane route reaches this body. MapPane is caller context for `HitTestStaticObjectPixel`, not this packet helper.
- `Socket`/`PacketBuffer` ownership: rejected because those are only callee dependencies.
- Compiler glue/no-code target: rejected because the body performs feature-level packet construction and is not ABI glue.

### Method Name And Signature

Best source-facing signature:

```cpp
void StaticObjectPane::SendInteractionPacket()
```

Confidence: high for class, receiver, no arguments, and `void`; medium-high for exact original spelling.

Reasoning:

- The body has no evidence of a meaningful return value. Any value in `EAX` after `QueueAndSendPacket` is not used by a caller, and the plain `ret`/no stack cleanup is consistent with a `void __thiscall` helper.
- The method performs one action: it sends the static-object interaction packet for the pane's current tile coordinates.
- `SendInteractionPacket` is the best name inside `StaticObjectPane` because the class name already supplies "StaticObject"; `SendStaticObjectInteractionPacket` is acceptable but redundant in class scope.
- `HandleStaticObjectEvent` is rejected for this helper because that name belongs to the checked virtual handler at `0x005379d0`, which validates event type, bounds, and flags before sending.
- `BuildInteractionPacket` is too narrow because this helper also queues the packet through `g_packetSender`.
- `SendClickPacket` is less precise because the raw helper has no event/click argument and does not check the click itself.

The method should be documented as a private, non-virtual helper. There is no vtable slot or data ref to `0x00537ac0`; the vtable/data ref at `0x006203b8` points to the checked handler `0x005379d0`.

### Field Semantics

The two serialized words are inherited `ObjectPane` tile/map coordinates:

- `this+0x100`: best field name `m_tileX` or `m_mapTileX`.
- `this+0x104`: best field name `m_tileY` or `m_mapTileY`.

Use `m_tileX`/`m_tileY` in first-draft C++ because [UID:0001D6] already uses those names in its populated C++ block.

Rejected alternatives:

- `m_objectTypeOrId` / `m_objectInstanceId`: rejected by B003's `StaticObjectPaneCore` field reanalysis and by `ObjectPaneSetMapPosition`, which treats `+0x100/+0x104` as coordinates.
- `m_staticObjectId`: rejected because the constructor stores the static-object id at `+0x128`, and image-library delegates use `+0x128`; this helper never reads `+0x128`.
- Screen/pixel coordinates: rejected because the checked handler has already converted event coordinates to a pane/bounds test; the packet words match the object pane's map tile coordinates.

### Packet Layout And Helper Names

The packet layout is resolved:

| Offset | Value | Meaning |
| --- | --- | --- |
| `0` | `0x43` | static-object/object-interaction opcode |
| `1` | `0x03` | static-object interaction subcommand |
| `2..3` | `m_tileX` via big-endian 16-bit writer | object tile X |
| `4..5` | `m_tileY` via big-endian 16-bit writer | object tile Y |
| `6` | `0x00` | trailing flag/zero payload byte |
| `7` | helper-written scratch terminator | outside counted payload |

The send length is exactly `7`. The eighth stack byte is scratch/terminator state written by the PacketBuffer scalar helpers, not part of the protocol payload. `QueueAndSendPacket` then copies `7` bytes and appends its own queue-buffer terminator.

Best helper names:

- `sub_575380` -> `PacketBufferWriteUInt8` (current local draft may spell it `PacketBuffer_WriteByte` for consistency with [UID:0001D6]).
- `sub_5753A0` -> `PacketBufferWriteUInt16BE` (current local draft may spell it `PacketBuffer_WriteUInt16BE` for consistency with [UID:0001D6]).
- `sub_574BB0` -> `QueueAndSendPacket` / `Socket::QueueAndSendPacket`, owned by [UID:0000DD] `Socket`.
- `dword_67A7EC` -> `g_packetSender`, best current type `Socket *`.

Rejected helper/global names:

- `FUN_00537ac0`, `sub_575380`, `sub_5753A0`, `sub_574BB0`, and `dword_67A7EC` are raw/generated names and should remain only as trace evidence.
- `g_pCashShopRequest` is rejected for `0x0067a7ec`; the real `g_pCashShopRequest` storage is `0x0067a738`, while `0x0067a7ec` has Socket-lifetime writes.
- `g_pPacketSender` appears in current [UID:0001D6] generated C++, but support docs now prefer `g_packetSender` with `Socket *` type. If the implementer keeps `g_pPacketSender` for local consistency, note it as a transitional spelling; the source-quality documentation should point to `g_packetSender`.

### Relationship To The Checked Handler

[UID:0001D6] `StaticObjectPaneCore` contains the checked virtual event handler at `0x005379d0-0x00537abf`. That handler:

- checks event kind `1`;
- builds/tests the pane rectangle;
- rejects disabled events where `event->flags & 0x04`;
- serializes the same `0x43, 0x03, tileX, tileY, 0` packet;
- sends length `7` through `g_packetSender`.

This target contains only the send body. The strongest source-shape interpretation is a retained private helper that the original source either called from the checked handler and the compiler inlined there, or kept as an out-of-line helper for another route that is no longer statically referenced. Because the compiled checked handler contains inline serialization and there is no direct branch/call to `0x00537ac0`, do not rewrite [UID:0001D6]'s C++ to call this helper in this implementation pass. Keep the two source bodies separate in documentation:

- [UID:0001D6] remains the checked virtual handler and already has first-draft C++.
- [UID:00023G] becomes the private direct sender helper and gets its own first-draft C++.

### Route And Reachability Closure

Current state:

- IDA has no function record for `0x00537ac0`.
- IDA/xref docs report no xrefs to `0x00537ac0`.
- Local PE scans found no absolute VA or RVA pointer hits to `0x00537ac0`.
- Ghidra prewave exports model the body as a function with zero callers.
- The target body bytes are unique.

Conclusion:

The lack of static callers is a real reachability fact but not a source-authorship blocker. The best explanation is retained out-of-line private method code from the same `StaticObjectPane` source family. It may be retained because the original source defined the helper out-of-line while the checked handler's call was inlined, or because an older/direct interaction route was removed without the function being eliminated. No evidence supports a vtable slot, callback table, or data-driven dispatch route to this helper. The report should not claim live runtime reachability beyond "retained code present in the binary."

This closure replaces the previous passive blocker wording. The target should still document the no-caller evidence, but C++ emission is justified because the method body is exact and source-owned.

### Split Needs

No additional child split is needed for `00023G`. The target is already an exact single function-shaped body plus trailing padding excluded by the range. The existing neighboring split model is correct:

- `0x00537abf-0x00537ac0`: one-byte `cc` alignment after [UID:0001D6].
- `0x00537ac0-0x00537b39`: this retained helper.
- `0x00537b39-0x00537b40`: `cc` alignment before [UID:0001D7].

Do not merge this into [UID:0001D6] or [UID:0001D7].

### First-Draft C++ Readiness

First-draft C++ is appropriate now.

Gate check:

- `RECONSTRUCTABLE:TRUE`
- nonblank emitter route `0000O6`
- `(85 + 86) / 2 = 85.5`, already above the active threshold
- body behavior resolved
- field semantics resolved
- PacketBuffer/Socket helper roles resolved enough for source-facing names
- remaining issue is caller reachability, which affects confidence and notes but not the correctness of this method body

Recommended C++ block for the target:

```cpp
void StaticObjectPane::SendInteractionPacket()
{
    unsigned char packet[8];

    PacketBufferWriteUInt8(0x43, &packet[0]);
    PacketBufferWriteUInt8(0x03, &packet[1]);
    PacketBufferWriteUInt16BE(static_cast<unsigned short>(m_tileX), &packet[2]);
    PacketBufferWriteUInt16BE(static_cast<unsigned short>(m_tileY), &packet[4]);
    PacketBufferWriteUInt8(0x00, &packet[6]);
    packet[7] = 0;

    QueueAndSendPacket(g_packetSender, packet, 7);
}
```

Implementation note: [UID:0001D6] currently uses transitional spellings `PacketBuffer_WriteByte`, `PacketBuffer_WriteUInt16BE`, and `g_pPacketSender`. If the supervisor wants this target to match the current generated `StaticObjectPane.cpp` style before a coordinated PacketBuffer/global normalization, the semantically equivalent local-style block is:

```cpp
void StaticObjectPane::SendInteractionPacket()
{
    uint8_t packet[8];

    PacketBuffer_WriteByte(0x43, &packet[0]);
    PacketBuffer_WriteByte(0x03, &packet[1]);
    PacketBuffer_WriteUInt16BE(static_cast<uint16_t>(m_tileX), &packet[2]);
    PacketBuffer_WriteUInt16BE(static_cast<uint16_t>(m_tileY), &packet[4]);
    PacketBuffer_WriteByte(0x00, &packet[6]);
    packet[7] = 0;

    QueueAndSendPacket(g_pPacketSender, packet, 7);
}
```

My source-quality preference is the first block (`PacketBufferWriteUInt8`, `PacketBufferWriteUInt16BE`, `g_packetSender`) because current support docs normalize those names, but either block preserves the verified behavior. The target/support text should explain the spelling transition instead of leaving raw names unresolved.

## Recommended Target Doc Changes

Target file: `source-3/project-documentation/by-memory/0x00537ac0-0x00537b39.StaticObjectPaneSendInteractionPacket.md`

1. Change metadata:
   - `COMPLETION:88`
   - `CONFIDENCE:89`
   - keep `CANONICAL_OWNER:0000O6`
   - keep `RECONSTRUCTABLE:TRUE`
   - keep `EMITTER_UIDS:0000O6`
2. Replace the status/source-shape wording:
   - Before: "raw class helper / IDA-missed method body candidate" and "Formal C++ remains blank because raw-start caller/reachability question is unresolved."
   - After: "retained source-authored private `StaticObjectPane` helper, best named `SendInteractionPacket`; IDA still misses the function start and no callers are known, but the no-caller fact is documented reachability evidence rather than a C++ blocker."
3. Add first-draft C++ in the target C++ block using one of the two blocks above. Prefer normalized PacketBuffer/global names if the current implementation callback includes name cleanup; otherwise use the local-style block to match [UID:0001D6].
4. Update `Behavior`:
   - state this is `StaticObjectPane::SendInteractionPacket()`;
   - state no event/bounds/disabled checks are performed;
   - state it serializes opcode `0x43`, subcommand `0x03`, `m_tileX`, `m_tileY`, zero flag, length `7`;
   - state byte `7` is scratch/terminator outside counted payload.
5. Update `Callers And Callees`:
   - keep no IDA xrefs/no modeled function record;
   - add Ghidra prewave export evidence that `0x00537ac0` is modeled as a 121-byte function with zero callers and four callees;
   - add local PE negative pointer scan and exact-body uniqueness evidence;
   - add the rejected false-positive `0x00537a5e` scan note only if useful, to prevent future mistaken caller claims.
6. Update `Relationship To Checked Handler`:
   - document the retained helper/inlined duplicate interpretation;
   - explicitly say not to rewrite [UID:0001D6]'s checked handler in this pass.
7. Replace `Non-Final Source Shape Notes` with `First-Draft Source Shape` and remove language saying the C++ is intentionally not emitted.
8. Add a `Rejected Alternatives` or `Source-Quality Decisions` subsection:
   - reject file-static, ObjectPane-owned, MapPane-owned, Socket-owned, compiler glue, and padding interpretations;
   - reject stale field names and raw helper/global names.
9. Update score rationale to explain why confidence remains below 90 despite code entry: IDA no-function/no-direct-caller evidence remains real.

## Recommended Support Doc Changes

`source-3/project-documentation/by-class/StaticObjectPane.md`

- Change the method table entry for [UID:00023G] from "leave formal C++ blank until raw-start liveness is proven" to "retained private no-argument `SendInteractionPacket()` helper; no direct static callers are known, but first-draft C++ is justified because the source-authored packet-send body is exact."
- Add that `SendInteractionPacket()` sends opcode `0x43`, subcommand `0x03`, inherited `m_tileX/m_tileY`, zero flag, length `7`.
- Add that it is non-virtual/private and has no vtable slot; the checked event handler remains the virtual route at `0x005379d0`.
- Optional score bump for class page is not required. If supervisor wants a support score update, `86/88` can stay because this is a narrow method clarification, not a class-wide audit.

`source-3/project-documentation/by-file/StaticObjectPane.md`

- Update the "static object interaction sender" row to say the later helper is a private retained direct packet sender, best named `SendInteractionPacket`, with no current static callers but source-ready first-draft C++.
- Replace "final method name stays provisional" with "method spelling `SendInteractionPacket` is best-supported; `SendStaticObjectInteractionPacket` remains a rejected/acceptable redundant alternative."
- Add the no-merge policy: keep [UID:0001D6] checked handler and [UID:00023G] direct sender as separate emitting bodies.

`source-3/project-documentation/by-memory/0x00537900-0x00537abf.StaticObjectPaneCore.md`

- Update the `0x00537ac0` row/source-quality note:
  - Before: raw packet helper with no xrefs, do not merge, raw-start reachability unproven.
  - After: exact retained private `SendInteractionPacket()` helper with no direct xrefs; no merge with core range, but first-draft C++ is now recommended in [UID:00023G].
- Do not change the already-populated [UID:0001D6] checked-handler C++ during this implementation. It correctly mirrors the compiled checked handler's inline packet serialization.

`source-3/project-documentation/by-memory/0x00537b40-0x005380af.ItemAndFlyingObjectPanes.md`

- No required behavioral change. If touched, only keep the boundary note: [UID:00023G] ends at `0x00537b39`, followed by `cc` padding before `0x00537b40`.

`source-3/project-documentation/by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md`

- No direct edit required. It already documents `sub_575380` as `PacketBufferWriteUInt8` and `sub_5753A0` as `PacketBufferWriteUInt16BE`.

`source-3/project-documentation/by-global/g_packetSender.md` and `by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md`

- No direct edit required. They already normalize `dword_67A7EC` to `Socket *g_packetSender` and reject generated `CashShopRequest*` aliases.

`source-3/project-documentation/by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md`

- No direct edit required. It already documents the Socket-owned queue/send funnel, 416-call fan-in, payload copy, appended terminator, and request code `8`.

`source-3/project-documentation/auto-generated/NexusTK/map/StaticObjectPane.cpp`

- Do not edit by hand. After target implementation and validator/autogen refresh, this generated file should no longer show `UID:00023G ... Empty Emitter Marker`; it should include the `SendInteractionPacket()` body after the existing [UID:0001D6] methods.

## Exact Coverage Row Text

Supervisor-owned file: `source-3/project-documentation/by-memory/-coverage-report.md`

Replace the current row at the same placement between the padding rows for `0x00537abf-0x00537ac0` and `0x00537b39-0x00537b40` with:

```md
    - [UID:00023G][0x00537ac0-0x00537b39.StaticObjectPaneSendInteractionPacket](by-memory/0x00537ac0-0x00537b39.StaticObjectPaneSendInteractionPacket.md) 0x00537ac0-0x00537b39 | raw-private-helper | StaticObjectPaneSendInteractionPacket : reconstructable : 88% : strong : StaticObjectPane retained private `SendInteractionPacket()` helper attached to `map/StaticObjectPane.cpp`; exact raw boundary and unique 0x79-byte body, IDA no-function/no-direct-xref evidence retained as reachability note, no VA/RVA pointer hits to raw start, Ghidra prewave 121-byte zero-caller function export, opcode `0x43`/subcommand `0x03` length-7 packet layout, inherited tile-coordinate words from `+0x100/+0x104`, zero flag byte plus scratch terminator outside counted payload, PacketBuffer UInt8/UInt16BE writers, `g_packetSender`/`QueueAndSendPacket` dependency, checked-handler duplicate/inlined-body relationship, stale object-id/generated-name alternatives rejected, and first-draft C++ now recommended for this exact helper.
```

Do not edit the coverage report during the report-only pass.

## IDA Rename, Type, And Comment Recommendations

If supervisor/IDA implementation is later authorized:

- Define function at `0x00537ac0` if IDA still does not model it.
- Function end should be exclusive `0x00537b39`.
- Rename to `StaticObjectPane_SendInteractionPacket` or, if class method naming is configured, `StaticObjectPane::SendInteractionPacket`.
- Apply type: `void __thiscall StaticObjectPane::SendInteractionPacket(void)`.
- Comment at function start: `Retained private StaticObjectPane packet sender; no known direct callers; same payload as checked event handler without event/bounds/disabled checks.`
- Comment reads:
  - `this+0x100` -> inherited `ObjectPane::m_tileX`
  - `this+0x104` -> inherited `ObjectPane::m_tileY`
- Rename or annotate callees:
  - `0x00575380` -> `PacketBufferWriteUInt8`
  - `0x005753a0` -> `PacketBufferWriteUInt16BE`
  - `0x00574bb0` -> `Socket::QueueAndSendPacket` / `QueueAndSendPacket`
  - `0x0067a7ec` -> `g_packetSender`
- Add a note that `0x006203b8` points to `0x005379d0`, not this helper; no vtable slot for `0x00537ac0` is known.

## Implementation Callback Checklist

When supervisor sends an implementation callback, apply only the accepted subset:

1. Edit `by-memory/0x00537ac0-0x00537b39.StaticObjectPaneSendInteractionPacket.md`.
2. Set target metadata to `COMPLETION:88`, `CONFIDENCE:89`; keep owner/emitter/reconstructable values.
3. Insert first-draft C++ for `StaticObjectPane::SendInteractionPacket()` using supervisor-selected helper/global spellings.
4. Replace non-final/no-code language with first-draft source-shape language.
5. Add source-quality decisions: retained private method, no caller evidence, field names, PacketBuffer helper names, `g_packetSender`, checked-handler relationship, rejected alternatives.
6. Update `by-class/StaticObjectPane.md`.
7. Update `by-file/StaticObjectPane.md`.
8. Update [UID:0001D6] `by-memory/0x00537900-0x00537abf.StaticObjectPaneCore.md` only for the sibling-helper note; do not rewrite its checked-handler C++.
9. Do not edit `by-memory/-coverage-report.md` unless supervisor explicitly includes that in the callback; use the exact row above.
10. Run scoped validators and post-update searches.

## Validation Commands

Recommended after implementation, from `source-3/project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [00023G-StaticObjectPaneSendInteractionPacket-source-quality-removed.md](00023G-StaticObjectPaneSendInteractionPacket-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Recommended post-update searches:

> Executable block R002 was removed from this report and preserved verbatim in [00023G-StaticObjectPaneSendInteractionPacket-source-quality-removed.md](00023G-StaticObjectPaneSendInteractionPacket-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected results:

- Target validates with nonblank C++.
- `auto-generated/NexusTK/map/StaticObjectPane.cpp` includes a `UID:00023G` `SendInteractionPacket()` body instead of an empty emitter marker after autogen refresh.
- Support docs no longer describe raw-start reachability as a passive C++ blocker.
- Raw names remain only in trace/evidence sections, not as unresolved source names.

## Residual Risk

Residual risk is limited to exact original spelling and reachability, not behavior:

- The original method name might have been `SendStaticObjectInteractionPacket`, `SendPacket`, or a Korean/project-specific equivalent. `SendInteractionPacket` is the best current source-facing English name in class scope.
- The original checked handler source may have called this helper and been inlined by the compiler. The compiled checked handler still contains inline packet serialization, so documentation should not force a source call in [UID:0001D6] unless a later source-wide refactor chooses readability over exact per-range emission.
- Final PacketBuffer helper spelling remains coordinated at the PacketBuffer module level. This target should use the accepted project spelling and document the raw callee names as evidence only.

These risks justify `88/89` rather than a 90+ score, but they do not justify leaving the formal C++ blank.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000004165","destination_path":"executed-b-agent-research/B006/00023G-StaticObjectPaneSendInteractionPacket-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:31","uid":"00023G"} -->
<!-- {"agent":"B006","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00023G-StaticObjectPaneSendInteractionPacket-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B006/00023G-StaticObjectPaneSendInteractionPacket-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00023G"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
