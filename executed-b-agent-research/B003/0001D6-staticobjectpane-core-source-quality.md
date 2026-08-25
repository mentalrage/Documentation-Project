** TARGET-REPORT-UID:0001D6 **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0001D6] StaticObjectPaneCore Source-Quality Review

Assignment: `B003-goal2-staticobjectpane-core-source-quality-0001D6-20260617`  
Agent: `B003`  
Primary target: `by-memory/0x00537900-0x00537abf.StaticObjectPaneCore.md`  
Starting score: `82/88`  
Recommended score: `88/91`  
Recommended owner/emitter: unchanged, [UID:0000O6] `StaticObjectPane`, route `NexusTK/map/StaticObjectPane.cpp`  
Report-only status: no by-* docs, generated files, IDA DB, source files, or coverage report were edited.

## Summary Recommendation

[UID:0001D6] can clear the active 85/85 source-quality and code-entry gate after doc repair. Live IDA evidence resolves the target's open field/helper/packet/caller questions enough to move it from `82/88` to `88/91`, keep it reconstructable, keep owner/emitter as [UID:0000O6] `StaticObjectPane`, and populate a first-draft formal C++ block for this exact range.

The target is not an overbroad aggregate that needs splitting. It is an exact StaticObjectPane method cluster:

- `0x00537900-0x00537947`: constructor
- `0x00537950-0x0053796f`: static-object pixel/solid hit-test bridge
- `0x00537970-0x00537998`: static-object local-bounds copy bridge
- `0x005379a0-0x005379cb`: render bridge
- `0x005379d0-0x00537abe`: checked pointer/event handler

The nearby raw packet helper [UID:00023G] at `0x00537ac0-0x00537b39` remains a separate sibling page. It is source-shaped and StaticObjectPane-owned, but it is outside [UID:0001D6]'s range and still has no modeled function record, no direct xrefs to its raw start, and no PE pointer hits to its start. It should not be merged into [UID:0001D6].

## Evidence Checked

Read documentation:

- Primary [UID:0001D6] `by-memory/0x00537900-0x00537abf.StaticObjectPaneCore.md`
- [UID:0000O6] `by-file/StaticObjectPane.md`
- [UID:0000E1] `by-class/StaticObjectPane.md`
- [UID:00023G] `by-memory/0x00537ac0-0x00537b39.StaticObjectPaneSendInteractionPacket.md`
- [UID:0001D5] `by-memory/0x005372d0-0x005378f9.ObjectPaneCore.md`
- [UID:0003TI] `by-memory/0x0050f030-0x0050f0fc.MapPaneCreateStaticObjectPaneForTile.md`
- [UID:00017J] `by-memory/0x004dd2c0-0x004dd849.StaticObjImageLibRenderStaticObject.md`
- [UID:00034X] StaticObjectPane read-only/vtable data page
- [UID:0000SD] `g_pStaticObjImageLib`
- [UID:0001HU] `QueueAndSendPacket`
- [UID:0001HZ] packet buffer helpers
- [UID:00037Y] MapPane tile/object-grid/render support range
- StaticObjImageLib class/file/layout support docs
- Current generated/source-tree context, including empty `auto-generated/NexusTK/map/StaticObjectPane.cpp`

IDA and raw evidence checked:

- `lookup_funcs`: confirmed functions at `0x00537900`, `0x00537950`, `0x00537970`, `0x005379a0`, `0x005379d0`; no function at `0x00537ac0`, `0x00537b39`, or `0x0050c691`.
- `xrefs_to`: constructor has code xref from `sub_50F030`; vtable slots point to bounds/render/event handlers; `0x00537950` has raw callsite `0x0050c691`; raw packet helper `0x00537ac0` has no direct xrefs.
- Decompiled [UID:0001D6] functions and the StaticObjImageLib helper callees `0x004dd8b0`, `0x004dd850`, `0x004dd2c0`.
- Disassembled raw MapPane helper `0x0050c5e0-0x0050c6da`, which contains callsite `0x0050c691` into [UID:0001D6]'s pixel hit-test bridge.
- Disassembled raw sibling packet helper `0x00537ac0-0x00537b39`.
- Checked padding around method boundaries: `0x005378fa-0x00537900`, `0x00537947-0x00537950`, `0x00537999-0x005379a0`, `0x005379cc-0x005379d0`, `0x00537abf-0x00537ac0`, `0x00537b39-0x00537b40`.
- Ran raw PE pointer/relative-call scan for `0x0050c5e0`, `0x00537950`, and `0x00537ac0`: no absolute/RVA/direct branch hits to `0x0050c5e0` or `0x00537ac0`; one relative branch hit to `0x00537950` at `0x0050c691`.
- Searched executed B reports for [UID:0001D6] and sibling context. No prior direct B report exists. B001's MapPane packet/source split report confirms [UID:0003TI] is MapPane-owned creation/registration context and should not be moved into StaticObjectPane.

## Source Shape And Boundaries

The target range is a source-shaped StaticObjectPane class-method cluster, not a mixed MapPane/ObjectPane aggregate. The constructor and four methods are separated by compiler `CC` padding and either have a constructor xref or vtable/data xrefs:

| Address | Boundary | Best source-facing role |
|---|---:|---|
| `0x00537900` | `0x47` bytes | `StaticObjectPane::StaticObjectPane(int tileX, int tileY, uint16_t staticObjectId)` |
| `0x00537950` | `0x20` bytes | `StaticObjectPane::HitTestStaticObjectPixel(int localX, int localY) const` |
| `0x00537970` | `0x29` bytes | `StaticObjectPane::CopyStaticObjectBounds(Rect *scratch, Rect *out) const` |
| `0x005379a0` | `0x2c` bytes | `StaticObjectPane::RenderStaticObjectForTarget(int renderMode, StaticObjectDrawRequest *request)` |
| `0x005379d0` | `0xef` bytes | adjusted-view `StaticObjectPane::HandleStaticObjectEvent(const PaneEvent *event)` |

No split is required for [UID:0001D6]. The exact child/sibling issue is already handled by [UID:00023G] for `0x00537ac0-0x00537b39`; that helper should stay separate because it is outside the primary range and has different reachability evidence.

## Constructor And Field Roles

Best defensible constructor signature:

```cpp
StaticObjectPane::StaticObjectPane(int tileX, int tileY, uint16_t staticObjectId);
```

Evidence:

- `0x00537900` calls `sub_5372D0(this, 5, 0, a2, a3)`, so the first two source parameters after `this` are passed directly into the ObjectPane base constructor as tile/map coordinates.
- It stores `a4` into `this[148]`, which is byte offset `+0x128`, and installs the StaticObjectPane vtable at primary and adjusted-view vtable slots.
- [UID:0003TI] `MapPaneCreateStaticObjectPaneForTile` calls `sub_537900(tileX, tileY, staticId)` from MapPane tile-object creation flow.
- `ObjectPaneCore` uses primary `+0x100/+0x104` as object tile/map coordinates. The StaticObjectPane checked-event packet reads those fields.

Best field names:

- `+0x100`: `m_tileX` or existing ObjectPane `m_objectTileX`
- `+0x104`: `m_tileY` or existing ObjectPane `m_objectTileY`
- `+0x128`: `m_staticObjectId`

Rejected alternative: `+0x100/+0x104` as object type/instance id. That interpretation came from generated-owner pollution and the raw packet helper doc, but it conflicts with the ObjectPane constructor call, `ObjectPane::SetPosition`, [UID:0003TI]'s call shape, and the event packet's use of the same two ObjectPane coordinate fields.

## Helper And Packet Semantics

`0x00537950` should be documented as a local-pixel/solid hit-test bridge. It delegates to `StaticObjImageLib` helper `0x004dd8b0` with `(m_staticObjectId, localX, localY)`. That callee rejects invalid static ids and null records, resolves static-object image/layer data, checks the target pixel, and also treats immediate neighboring nonzero pixels as a hit. A final original name is not proven, but the best source-facing name is `HitTestStaticObjectPixel` or `IsStaticObjectPixelSolid`. Prefer `HitTestStaticObjectPixel` because it preserves the local-coordinate role and avoids overclaiming exact solidity semantics.

`0x00537970` should be documented as a bounds-copy bridge. It calls `StaticObjImageLib::GetStaticObjectBounds(m_staticObjectId, scratch)` and copies the scratch rectangle to the caller's output rectangle. The local-bounds semantics are strongly supported by `0x004dd850`, which builds a rectangle from static-object frame/layer dimensions.

`0x005379a0` should be documented as the render bridge. It delegates to `StaticObjImageLib::RenderStaticObject` with `m_staticObjectId`, null/zero optional offsets, and the final boolean/render flag set to true. This confirms source placement in `map/StaticObjectPane.cpp`, with image-frame rendering mechanics staying in `render/StaticObjImageLib.cpp`.

`0x005379d0` should be documented as the StaticObjectPane checked event handler. It is called through an adjusted vtable view, but source code should be a normal StaticObjectPane method. It:

- reads event type byte at `event + 0x04` and only handles type `1`;
- reads signed 16-bit event coordinates from `event + 0x08` and `event + 0x0c`;
- constructs a rectangle from primary pane bounds reached through the adjusted `this` view;
- rejects events outside the pane rectangle;
- rejects events with flag bit `0x04` set at `event + 0x10`;
- serializes a 7-byte packet: byte `0x43`, byte `0x03`, word `m_tileX`, word `m_tileY`, byte `0x00`;
- queues/sends the packet through the global packet sender.

Packet helper names remain library-convention names, not source blockers. Use the established packet writer dependency descriptions:

- `sub_575380`: byte writer, source-facing `PacketBuffer_WriteByte` or `WritePacketByte`
- `sub_5753A0`: 16-bit big-endian word writer, source-facing `PacketBuffer_WriteUInt16BE` or `WritePacketWordBE`
- `sub_574BB0`: packet send helper, source-facing `QueueAndSendPacket`

Rejected alternative: opcode `0x43`/subcommand `0x03` as object-id or type/id interaction packet. The same serialization pattern appears in raw helper [UID:00023G], but the data words are ObjectPane coordinate fields at primary `+0x100/+0x104`, not `+0x128` static-object id. The better protocol inference is "static-object interaction at tile coordinate", not "static-object id interaction".

## Caller And Ownership

The constructor caller at `0x0050f0a5` is [UID:0003TI] `MapPaneCreateStaticObjectPaneForTile`. That confirms MapPane owns tile-object allocation/registration and StaticObjectPane owns the constructed object behavior after creation.

The pixel helper's only code xref is raw callsite `0x0050c691`. That address is not inside an IDA-modeled function, but disassembly of `0x0050c5e0-0x0050c6da` shows a coherent raw MapPane helper:

- divides screen/map coordinates by tile height,
- checks visible/tile bounds,
- walks ObjectPane row/list buckets,
- calls each pane's bounds-copy virtual slot,
- rectangle-tests the point,
- computes local coordinates,
- calls StaticObjectPane `0x00537950`,
- returns only the pane with a positive static-object pixel hit.

Best source-facing classification for that raw helper is `MapPaneFindStaticObjectAtPoint` or `MapPaneFindSolidStaticObjectAtPoint`, and it belongs with [UID:00037Y] MapPane tile/object-grid support rather than [UID:0001D6]. There are no direct xrefs or PE pointer hits to its raw start, so this report does not recommend creating a new split page for it under this assignment. It is caller/source context only and does not cap [UID:0001D6]'s completion because the callsite into [UID:0001D6] and helper behavior are proven.

## Raw Sibling [UID:00023G]

[UID:00023G] at `0x00537ac0-0x00537b39` is not part of [UID:0001D6]. It is a source-shaped StaticObjectPane packet-send helper that emits the same opcode/subcommand/tile-coordinate packet body as the checked event handler, but its liveness remains weaker:

- no IDA function record at `0x00537ac0`;
- no direct xrefs to `0x00537ac0`;
- raw PE pointer/relative-branch scan found no hits to the raw start;
- clean boundary: one `CC` at `0x00537abf`, helper body through `0x00537b38`, and seven `CC` bytes before the next modeled function at `0x00537b40`.

Best classification: StaticObjectPane-owned raw private packet helper, likely an unreferenced inlined/stripped helper body or a callback-adjacent compiler island retained in the binary. It should remain [UID:00023G], owner/emitter [UID:0000O6], reconstructable, but formal C++ should remain blank until a direct source route or vtable/callback pointer source is proven. This residual raw-helper liveness issue should not block [UID:0001D6]'s formal C++ because [UID:0001D6]'s range contains its own complete inline packet serialization in `0x005379d0`.

## Support Docs To Update

Recommended [UID:0001D6] target-doc changes:

- Header metadata: `COMPLETION:88`, `CONFIDENCE:91`, `RECONSTRUCTABLE:TRUE`, owner/emitter unchanged.
- Replace the open-question language with resolved notes:
  - `0x00537950` best source name: `HitTestStaticObjectPixel(int localX, int localY) const`.
  - Packet words from `+0x100/+0x104` are ObjectPane tile/map coordinates, not object type/instance ids.
  - `0x0050c691` is a raw MapPane caller inside `0x0050c5e0-0x0050c6da`, best classified as a MapPane solid-static-object point query; it is caller evidence, not an ownership blocker.
  - Final C++ is ready for [UID:0001D6] only; [UID:00023G] remains separate/review-only.
- Add the first-draft C++ below to `RECONSTRUCTION_CPP` after supervisor review.

Recommended [UID:00023G] support-doc changes:

- Replace stale object type/id wording with:

```text
The two 16-bit packet fields read from primary `this + 0x100` and `this + 0x104` are the ObjectPane tile/map coordinate fields, not the StaticObjectPane `+0x128` static-object id and not generated `m_objectTypeId/m_objectInstanceId` fields. The helper serializes opcode `0x43`, subcommand `0x03`, tile X, tile Y, and a zero byte, then sends a 7-byte packet through the global packet sender.
```

- Replace stale final-C++ gate wording with:

```text
Do not populate formal C++ yet. Although the helper is source-shaped and reconstructable, live IDA and PE scans still show no modeled function record, no xrefs to the raw start `0x00537ac0`, and no pointer/relative-branch hits to the helper start. Keep this page as a StaticObjectPane-owned raw private packet helper until a direct source route, callback pointer, or other liveness evidence is found.
```

Recommended [UID:0000O6] and [UID:0000E1] support-doc changes:

- Canonicalize generated `g_pStaticObjectManager` mentions to `g_pStaticObjImageLib` when describing bounds/render/pixel helpers.
- Document source-facing methods:
  - `StaticObjectPane::StaticObjectPane(int tileX, int tileY, uint16_t staticObjectId)`
  - `StaticObjectPane::HitTestStaticObjectPixel(int localX, int localY) const`
  - `StaticObjectPane::CopyStaticObjectBounds(Rect *scratch, Rect *out) const`
  - `StaticObjectPane::RenderStaticObjectForTarget(int renderMode, StaticObjectDrawRequest *request)`
  - `StaticObjectPane::HandleStaticObjectEvent(const PaneEvent *event)`

Recommended [UID:00037Y] support-doc change:

```text
Raw helper `0x0050c5e0-0x0050c6da` is MapPane-owned caller context for StaticObjectPane hit-testing. It has no modeled function record and no direct start xrefs, but disassembly shows it scanning tile/object list rows, invoking pane bounds-copy virtuals, testing the point against bounds, computing local coordinates, and calling [UID:0001D6] `0x00537950` at `0x0050c691`. Keep it in the MapPane tile/object-grid support range unless a future MapPane-focused split proves a safe exact child.
```

## Heuristic / Inference Reanalysis And Validation

Issue: final source name for pixel-test helper.  
Best inference: `StaticObjectPane::HitTestStaticObjectPixel(int localX, int localY) const`.  
Evidence checked: `0x00537950` decompile, only raw callsite `0x0050c691`, StaticObjImageLib callee `0x004dd8b0`, and raw MapPane caller local-coordinate setup. The callee tests static-object frame pixels and neighboring pixels after id/range/null checks.  
Rejected alternatives: `ContainsPoint` is too broad because bounds are tested by caller first; `IsStaticObjectSolid` is less precise because the helper takes local pixel coordinates; image-library ownership is wrong because the method is a StaticObjectPane bridge and uses `m_staticObjectId`.  
Impact: resolves one open target question and supports 85+ completion.

Issue: packet word semantics and field names.  
Best inference: `+0x100/+0x104` are ObjectPane tile/map coordinate fields, and `+0x128` is `m_staticObjectId`. The packet is opcode `0x43`, subcommand `0x03`, tile X, tile Y, zero flag byte.  
Evidence checked: constructor call into ObjectPane with tile args, [UID:0003TI] creation caller, `ObjectPane::SetPosition` behavior in [UID:0001D5], `0x005379d0` packet writes, raw sibling [UID:00023G] packet writes, and lack of any use of `+0x128` in packet serialization.  
Rejected alternatives: generated `m_objectTypeId`/`m_objectInstanceId` naming and raw-helper object-id wording. Those conflict with constructor and ObjectPane movement evidence.  
Impact: closes the packet/field blocker and prevents incorrect generated-owner names from entering formal C++.

Issue: `0x0050c691` raw xref owner.  
Best inference: raw MapPane helper `0x0050c5e0-0x0050c6da`, likely `MapPaneFindSolidStaticObjectAtPoint`, caller/support only.  
Evidence checked: IDA reports no function at `0x0050c691`; manual disassembly from `0x0050c5e0`; padding before/after; PE scan found no pointer/direct branch to `0x0050c5e0`; B001 MapPane split report says MapPane tile helpers remain MapPane-owned.  
Rejected alternatives: merge with StaticObjectPane because it calls `0x00537950`; split now under B003 because no safe direct start liveness exists and the helper belongs to MapPane, not the assigned StaticObjectPane target.  
Impact: removes [UID:0001D6] caller uncertainty. It suggests a future MapPane-support note but does not cap [UID:0001D6].

Issue: raw sibling [UID:00023G] liveness and split treatment.  
Best inference: StaticObjectPane-owned private packet helper, separate exact sibling, formal C++ blank.  
Evidence checked: raw disassembly `0x00537ac0-0x00537b39`, padding `0x00537abf` and `0x00537b39-0x00537b40`, no IDA function record, no xrefs, PE scan no pointer/direct branch hits, packet body comparison to `0x005379d0`.  
Rejected alternatives: merge into [UID:0001D6] because the address range starts after [UID:0001D6] and has its own existing page; delete or mark dead because the body is coherent source-shaped code and matches live event-handler serialization; populate C++ now because raw-start reachability is still unproven.  
Impact: [UID:00023G] remains a support/sibling caveat, not a primary-target blocker.

Issue: source placement.  
Best inference: [UID:0001D6] emits to `NexusTK/map/StaticObjectPane.cpp`; StaticObjImageLib internals remain in `render/StaticObjImageLib.cpp`; MapPane raw caller remains MapPane support context.  
Evidence checked: proposed source tree, file/class docs, vtable ownership, constructor caller, image-lib global docs, and generated empty `auto-generated/NexusTK/map/StaticObjectPane.cpp`.  
Rejected alternatives: place methods in StaticObjImageLib because all image work is delegated through `g_pStaticObjImageLib`; place in ObjectPane because constructor delegates to ObjectPane; place in MapPane because MapPane constructs/calls it. Those are dependency/caller contexts, not method owners.  
Impact: owner/emitter unchanged and final C++ route is valid.

Issue: final C++ readiness.  
Best inference: populate [UID:0001D6]'s formal C++ with the draft below after supervisor applies doc/metadata repairs.  
Evidence checked: exact function boundaries, vtable slots, constructor xref, generated-output omission, field roles, packet semantics, caller context, and range exclusion of [UID:00023G].  
Rejected alternatives: leave blank because original names are not proven. Under B-source-quality rules, best defensible source-facing names with evidence are sufficient; no unresolved blocker remains that would materially change the method bodies or owner/source file.  
Impact: recommended score `88/91`, active code gate cleared, formal C++ should be populated for [UID:0001D6].

## First-Draft C++ Recommendation

Populate [UID:0001D6]'s formal `RECONSTRUCTION_CPP` block after applying the target-doc repairs above. Do not populate [UID:00023G]'s formal C++ block in this assignment.

Draft for [UID:0001D6] only:

```cpp
StaticObjectPane::StaticObjectPane(int tileX, int tileY, uint16_t staticObjectId)
    : ObjectPane(5, 0, tileX, tileY)
{
    m_staticObjectId = staticObjectId;
}

bool StaticObjectPane::HitTestStaticObjectPixel(int localX, int localY) const
{
    return g_pStaticObjImageLib->HitTestStaticObjectPixel(m_staticObjectId, localX, localY);
}

Rect *StaticObjectPane::CopyStaticObjectBounds(Rect *scratch, Rect *out) const
{
    g_pStaticObjImageLib->GetStaticObjectBounds(m_staticObjectId, scratch);
    *out = *scratch;
    return out;
}

bool StaticObjectPane::RenderStaticObjectForTarget(int renderMode, StaticObjectDrawRequest *request)
{
    return g_pStaticObjImageLib->RenderStaticObject(renderMode, request, m_staticObjectId, 0, 0.0f, true) != 0;
}

bool StaticObjectPane::HandleStaticObjectEvent(const PaneEvent *event)
{
    Rect bounds;

    Rect_Set(&bounds, m_bounds.left, m_bounds.top, m_bounds.right, m_bounds.bottom);

    if (event->type != 1) {
        return false;
    }

    if (!Rect_ContainsPoint(&bounds, event->x, event->y) || (event->flags & 0x04) != 0) {
        return false;
    }

    uint8_t packet[8];
    PacketBuffer_WriteByte(0x43, &packet[0]);
    PacketBuffer_WriteByte(0x03, &packet[1]);
    PacketBuffer_WriteUInt16BE(static_cast<uint16_t>(m_tileX), &packet[2]);
    PacketBuffer_WriteUInt16BE(static_cast<uint16_t>(m_tileY), &packet[4]);
    PacketBuffer_WriteByte(0x00, &packet[6]);
    packet[7] = 0;

    QueueAndSendPacket(g_pPacketSender, packet, 7);
    return true;
}
```

Notes for supervisor application:

- `m_tileX/m_tileY`, `m_bounds`, `PaneEvent`, `Rect`, and helper names should be adjusted to the final project-wide naming conventions if those differ, but the data flow and field roles are evidence-backed.
- Keep the packet helper inline in this target's event method. Do not fold [UID:00023G] into this C++ block because [UID:00023G] is outside the target range.
- If the project convention uses value-first packet writers matching the binary prototypes, rename calls to `PacketBuffer_WriteByte(value, dest)` and `PacketBuffer_WriteUInt16BE(value, dest)` as shown. If the final wrappers are destination-first, only the wrapper call syntax changes, not the packet layout.

## Exact Coverage Row Text

Replace the existing [UID:0001D6] row in `by-memory/-coverage-report.md` with:

```text
    - [UID:0001D6][0x00537900-0x00537abf.StaticObjectPaneCore](by-memory/0x00537900-0x00537abf.StaticObjectPaneCore.md) 0x00537900-0x00537abf | class-method-cluster | StaticObjectPaneCore : reconstructable : 88% : strong : Live IDA 2026-06-17 reconfirms the exact constructor/hit-test/bounds/render/event-handler method boundaries, StaticObjectPane owner/emitter route to `map/StaticObjectPane.cpp`, constructor caller `sub_50F030`, `m_staticObjectId` at `+0x128`, canonical `g_pStaticObjImageLib` bounds/render/pixel hit-test delegation, vtable refs at `0x00620394/0x006203a0/0x006203b8`, adjusted event-handler field mapping, tile-coordinate packet words from primary `+0x100/+0x104`, opcode `0x43`/subcommand `0x03` length-7 serialization, raw MapPane caller `0x0050c5e0-0x0050c6da` at callsite `0x0050c691`, sibling raw packet helper separation, and first-draft C++ readiness.
```

Replace the existing [UID:00023G] row with:

```text
    - [UID:00023G][0x00537ac0-0x00537b39.StaticObjectPaneSendInteractionPacket](by-memory/0x00537ac0-0x00537b39.StaticObjectPaneSendInteractionPacket.md) 0x00537ac0-0x00537b39 | raw-private-helper | StaticObjectPaneSendInteractionPacket : reconstructable : 85% : strong : StaticObjectPane raw packet-send helper attached to `map/StaticObjectPane.cpp` with exact raw boundary, no modeled function record/xrefs/PE pointer hits to raw start, opcode `0x43`/subcommand `0x03` length-7 packet layout, tile-coordinate words from primary `+0x100/+0x104`, zero flag byte, PacketBuffer byte/UInt16BE writers, queue/send dependency, checked-handler comparison, and explicit do-not-populate formal C++ policy until raw-start reachability/source helper shape is proven.
```

Optional support insert if supervisor wants [UID:00037Y] exposed in the coverage report; insert under the [UID:0001AT] MapPane cluster near the existing MapPane tile/object-grid child rows:

```text
        - [UID:00037Y][0x0050bce0-0x0050e320.MapPaneTileObjectGridRenderCore](by-memory/0x0050bce0-0x0050e320.MapPaneTileObjectGridRenderCore.md) 0x0050bce0-0x0050e320 | class-method-cluster | MapPaneTileObjectGridRenderCore : reconstructable : 86% : strong : MapPane-owned tile/object-grid/render helper family; current support recheck also identifies raw helper `0x0050c5e0-0x0050c6da` inside the range that scans object-list row buckets, bounds-checks panes, calls [UID:0001D6] hit-test at `0x0050c691`, and returns only a solid-pixel StaticObjectPane hit; no direct refs to raw start, so keep helper inside this aggregate pending a dedicated MapPane split.
```

## Validation Commands

Recommended after supervisor applies doc edits:

> Executable block R001 was removed from this report and preserved verbatim in [0001D6-staticobjectpane-core-source-quality-removed.md](0001D6-staticobjectpane-core-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the local validator script has a different project name, use the repository's standard by-doc validation command; no generated source rebuild is required until the supervisor populates the formal C++ block.

## IDA Rename And Comment Recommendations

High confidence:

- Rename `sub_537900` to `StaticObjectPane_ctor`.
- Rename `sub_537950` to `StaticObjectPane_HitTestStaticObjectPixel`.
- Rename `sub_537970` to `StaticObjectPane_CopyStaticObjectBounds`.
- Rename `sub_5379A0` to `StaticObjectPane_RenderStaticObjectForTarget`.
- Rename `sub_5379D0` to `StaticObjectPane_HandleStaticObjectEvent`.
- Rename field `StaticObjectPane +0x128` to `m_staticObjectId`.
- Comment primary ObjectPane fields `+0x100/+0x104` as tile/map coordinate fields consumed by StaticObjectPane interaction packets.

Medium confidence:

- Comment raw `0x0050c5e0-0x0050c6da` as MapPane raw solid-static-object point query, no modeled function/xrefs yet.
- Comment raw `0x00537ac0-0x00537b39` as StaticObjectPane raw packet-send helper, no modeled function/xrefs yet.

## Blockers And Follow-Up

No remaining blocker prevents [UID:0001D6] from reaching `88/91` or receiving first-draft formal C++.

Residual follow-up outside the primary target:

- A future MapPane-focused pass should decide whether raw `0x0050c5e0-0x0050c6da` deserves a safe exact child page under [UID:00037Y]. Current evidence does not prove direct start liveness.
- A future StaticObjectPane support pass can continue looking for callback/pointer evidence to raw helper [UID:00023G]. Until then, keep its formal C++ blank.

Files changed by B003:

- `tools/leaser/Agents/Agent-B003/research/0001D6-staticobjectpane-core-source-quality.md`

Leases used: none. This was report-only work.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0001D6-staticobjectpane-core-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:27","uid":"0001D6"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001D6-staticobjectpane-core-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/0001D6-staticobjectpane-core-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001D6"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
