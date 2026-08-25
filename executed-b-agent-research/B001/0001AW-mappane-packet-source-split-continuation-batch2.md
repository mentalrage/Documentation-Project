** TARGET-REPORT-UID:0001AW **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001AW MapPane Packet Handler Continuation Split Research

## Finalized Report / Current Recommendation

- Current recommendation: executable second split batch for [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](../../../by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md).
- Final disposition: create two new exact `MapPane` child pages and two ignored padding rows:
  - proposed [UID:0003TC] `by-memory/0x0050e690-0x0050e805.MapPaneApplyHitBarObjectPane.md`
  - proposed [UID:0003TD] `by-memory/0x0050e810-0x0050e848.MapPaneActivateLinkedObjectById.md`
  - ignored padding `0x0050e805-0x0050e810`
  - ignored padding `0x0050e848-0x0050e850`
- Required action: supervisor can apply the batch below immediately. [UID:0001AW] should remain `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00007Q` after this batch because the broad `0x0050e850-0x00510400` and `0x005104c7-0x00513800` leaf spans remain source-bearing and unsplit.
- Confidence: high for range, child ownership, and padding. Medium-high for the proposed source-facing helper names. The `0x0050e690` child has no direct callers in the current IDB, so final C++ must stay blank and the name should remain provisional.

## Target

- Target UID: [UID:0001AW]
- Target path: `by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md`
- Assignment: `B001-goal2-memory-tool-mappane-packet-source-split-continuation-0001AW-20260616`
- Current state checked: [UID:0001AW] is `85/88`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`; [UID:0003TB] `MapPaneProcessMapEvent` already exists at `86/89` and is nested under [UID:0001AW].
- Current generated report state: `auto-generated/by-memory-tool-report.md` has Barrier Crossings, General Errors, Filename Errors, and Advanced-Error-Scan sections clean. Largest leaves still include `0x005104c7-0x00513800` and `0x0050e68d-0x00510400` from [UID:0001AW].

## Executable Supervisor Batch

### UID Allocation Assumption

- Current `tools/validator.ini` was checked for this assignment because the supervisor requested UID allocation assumptions. It reports `last_used_uid = 0003TB`.
- This report assumes:
  - next UID: `0003TC`
  - following UID: `0003TD`
- If another supervisor action allocates a UID before this batch is applied, substitute the next two available UIDs consistently in the filenames, headers, links, support docs, and coverage rows.

### Create Child Page 1

- Exact file path: `by-memory/0x0050e690-0x0050e805.MapPaneApplyHitBarObjectPane.md`
- Proposed UID: `0003TC`
- Score: `86/88`
- Owner/emitter: [UID:00007Q][MapPane](../../../by-class/MapPane.md)
- Final C++: blank
- Reason this clears 85/85: IDA MCP confirms a modeled `sub_50E690` function object with exact size `0x175`, no overlap, exact `0xcc` padding after the function, decompilation shows a coherent MapPane-side HitBarObjectPane update/create helper, and support docs independently tie `0x0050e690` to HitBarObjectPane constructor/bounds/active-flag and pool allocation xrefs.
- Caller caveat: current IDA `analyze_function` reports no direct callers and no xrefs to the function start. This does not block exact child creation because it is a real modeled function in the source-bearing parent, but it caps confidence and keeps final C++ blank.

Exact markdown to create:

```markdown
*** UID:0003TC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x0050e690-0x0050e805 MapPane Apply HitBarObjectPane

## Status

- Disposition: reconstructable NexusTK project code.
- Entity kind: exact `MapPane` class method child split from [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md).
- Working source name: `MapPane::ApplyHitBarObjectPane`; provisional descriptive name, not final original-source proof.
- Direct class parent: [UID:00007Q][MapPane](by-class/MapPane.md).
- Source route: [UID:0000L3][MapPane](by-file/MapPane.md).
- Rebuild handling: source-authored MapPane object/marker helper. Keep final C++ blank until the direct caller route, original helper name, target-object field names, and HitBarObjectPane helper names are final-source quality.

## Range And Boundary

| Item | Evidence |
| --- | --- |
| Start | `0x0050e690`; IDA models `sub_50E690` here. |
| End | `0x0050e805` end-exclusive; IDA function size is `0x175`. |
| Successor padding | IDA MCP `make_signature_for_range` over `0x0050e805-0x0050e810` with operand wildcarding disabled returns eleven `0xcc` bytes. |
| Next function | `0x0050e810` begins modeled `sub_50E810`, proposed as [UID:0003TD][0x0050e810-0x0050e848.MapPaneActivateLinkedObjectById](by-memory/0x0050e810-0x0050e848.MapPaneActivateLinkedObjectById.md). |

## Behavior

IDA decompilation shows this helper takes a `MapPane` receiver, a target object pointer, and two current/max value pairs. It converts each value pair into a percentage, then applies the percentages to the target object's attached hit-bar overlay:

1. Compute the primary percentage from the first current/max pair, using a divided form when the current value is large enough to avoid overflow.
2. Compute the secondary percentage from the second current/max pair the same way.
3. Return if the target object pointer is null.
4. Read the target object's attached overlay pointer at object offset `+0x1dc`.
5. If an attached HitBarObjectPane exists and its active flag is set, update that existing hit bar through the HitBar bounds/value helper.
6. If a stale attached hit-bar object exists, unregister and destroy it before creating a replacement.
7. Allocate from the HitBarObjectPane pool, construct the dual-value HitBarObjectPane for the target object, attach/register it through MapPane and attached-object helper calls, invalidate/refresh it, and dispatch its virtual bounds update.

The behavior is MapPane-owned because the method manages MapPane object/marker state and target-object attachment policy. [UID:000067][HitBarObjectPane](by-class/HitBarObjectPane.md) remains the constructed overlay class owner.

## IDA MCP Evidence

- Live IDA session `b001_mappane_0001AW_20260616` on 2026-06-16 reports `lookup_funcs(0x0050e690)` as `sub_50E690`, size `0x175`.
- The same lookup reports `0x0050e805` as not a function and `0x0050e810` as the next modeled function start.
- `analyze_function(0x0050e690)` reports prototype `unsigned int __thiscall(void *this, int, unsigned int, unsigned int, unsigned int, unsigned int)`, size `373`, 19 basic blocks, and complexity `5`.
- Callees reported by IDA: `sub_5374D0`, `PoolAllocator_Allocate`, `sub_531C10`, `sub_5314A0`, `sub_4B8E00`, `sub_538EB0`, `sub_538DC0`, `sub_53AE70`, `@__security_check_cookie@4`, and `sub_538E60`.
- Decompilation shows update-or-create HitBarObjectPane logic: percentage computation, target attached-object pointer load at `a2 + 476`, active-flag call `sub_538EB0`, existing hit-bar update `sub_538E60`, stale object removal, pool allocation, dual HitBar constructor `sub_538DC0`, attached-object registration helpers, and virtual refresh calls.
- Negative evidence: `analyze_function(0x0050e690)` reports no current direct callers and no xrefs to the function start. The only `xrefs.from` item is the function's own internal instruction at `0x0050e691`.
- Padding evidence: `make_signature_for_range(0x0050e805, 0x0050e810, wildcard_operands=false)` returns `CC CC CC CC CC CC CC CC CC CC CC`.

## Documentation Evidence

- [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md) already inventories `0x0050e690` as a modeled HitBar/object event helper in the MapPane packet cluster.
- [UID:000067][HitBarObjectPane](by-class/HitBarObjectPane.md) states that the dual constructor is called from `0x0050e690`, the bounds/state helper is reached from `0x0050e690`, and the active-flag accessor is used from `0x0050e690`.
- [UID:0002WP][0x0069b934-0x0069b95c.HitBarObjectPanePoolStaticStorage](by-memory/0x0069b934-0x0069b95c.HitBarObjectPanePoolStaticStorage.md) records direct HitBarObjectPane pool xref `0x0050e778` inside this function and resolves it to the `0x0050e690` allocation path.
- [UID:0000L3][MapPane](by-file/MapPane.md) and [UID:00007Q][MapPane](by-class/MapPane.md) already carry the parent [UID:0001AW] and first child [UID:0003TB] as MapPane packet/object/event source.

## Source Placement Decision

Assign this child to [UID:00007Q][MapPane](by-class/MapPane.md), emitting through MapPane. The function is not a HitBarObjectPane method even though it allocates and calls HitBarObjectPane helpers: the receiver is MapPane, the policy is when to create/update/remove the attached hit-bar overlay for a map object, and the parent packet/object-event cluster is MapPane-owned.

Rejected owners:

- [UID:000067][HitBarObjectPane](by-class/HitBarObjectPane.md): constructed and updated callee class, not the method receiver or source owner.
- [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md): provides attached-object base behavior reached through callees, but does not own MapPane's packet/object marker route.
- [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md): source-family parent only; this exact child carries the method-level evidence.

## Reconstruction Notes

Final C++ remains blank. The exact behavior is clear enough for an 85/85+ split child, but the final source needs:

- a confirmed original helper name;
- a resolved direct caller route or a final decision that this is retained but uncalled MapPane helper code;
- final names for the target object pointer, object offset `+0x1dc`, and MapPane object/attachment helper calls;
- final HitBarObjectPane create/update/bounds helper names.

## Score Rationale

Completion is `86` because the page records the exact function boundary, successor padding, decompiled behavior, callee set, HitBarObjectPane constructor/pool links, owner analysis, and final-C++ blockers.

Confidence is `88` because function boundary and MapPane/HitBar callee ownership are strong, but no direct caller is currently modeled and the source-facing helper name is descriptive rather than proven.

## Cross-References

- [UID:00007Q][MapPane](by-class/MapPane.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md)
- [UID:0003TB][0x0050e4c0-0x0050e68d.MapPaneProcessMapEvent](by-memory/0x0050e4c0-0x0050e68d.MapPaneProcessMapEvent.md)
- [UID:0003TD][0x0050e810-0x0050e848.MapPaneActivateLinkedObjectById](by-memory/0x0050e810-0x0050e848.MapPaneActivateLinkedObjectById.md)
- [UID:000067][HitBarObjectPane](by-class/HitBarObjectPane.md)
- [UID:0002WP][0x0069b934-0x0069b95c.HitBarObjectPanePoolStaticStorage](by-memory/0x0069b934-0x0069b95c.HitBarObjectPanePoolStaticStorage.md)
- [UID:0000VN][-ignored](by-memory/-ignored.md)

## Changes

- 2026-06-16 B001 continuation split batch: recommended as the exact second child of [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md), scored `86/88`, routed to [UID:00007Q][MapPane](by-class/MapPane.md), and left final C++ blank pending caller/source-name/field/helper-name confirmation. Evidence: IDA MCP reports `sub_50E690` size `0x175`, decompilation shows MapPane-side HitBarObjectPane update/create behavior, HitBarObjectPane support docs tie the address to constructor/bounds/active-flag and pool storage xrefs, and IDA confirms `0x0050e805-0x0050e810` as eleven `0xcc` alignment bytes before `sub_50E810`.
```

### Create Child Page 2

- Exact file path: `by-memory/0x0050e810-0x0050e848.MapPaneActivateLinkedObjectById.md`
- Proposed UID: `0003TD`
- Score: `86/90`
- Owner/emitter: [UID:00007Q][MapPane](../../../by-class/MapPane.md)
- Final C++: blank
- Reason this clears 85/85: IDA MCP confirms modeled function boundary, direct callers from NewGroupPane, LivingObjectPane, and group marker clear paths, decompilation shows MapPane object-list lookup and attached-overlay activation/clear behavior, and support docs already describe this as `MapPane::ActivateLinkedObjectById`.

Exact markdown to create:

```markdown
*** UID:0003TD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x0050e810-0x0050e848 MapPane Activate Linked Object By Id

## Status

- Disposition: reconstructable NexusTK project code.
- Entity kind: exact `MapPane` class method child split from [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md).
- Working source name: `MapPane::ActivateLinkedObjectById`; this name is supported by Group documentation and direct caller behavior, but still provisional for final C++.
- Direct class parent: [UID:00007Q][MapPane](by-class/MapPane.md).
- Source route: [UID:0000L3][MapPane](by-file/MapPane.md).
- Rebuild handling: source-authored MapPane linked-object/marker helper. Keep final C++ blank until the object-list field, attached-object field, and virtual callback names are final-source quality.

## Range And Boundary

| Item | Evidence |
| --- | --- |
| Start | `0x0050e810`; IDA models `sub_50E810` here. |
| End | `0x0050e848` end-exclusive; IDA function size is `0x38`. |
| Predecessor padding | `0x0050e805-0x0050e810` is eleven `0xcc` alignment bytes after proposed [UID:0003TC][0x0050e690-0x0050e805.MapPaneApplyHitBarObjectPane](by-memory/0x0050e690-0x0050e805.MapPaneApplyHitBarObjectPane.md). |
| Successor padding | IDA MCP `make_signature_for_range` over `0x0050e848-0x0050e850` with operand wildcarding disabled returns eight `0xcc` bytes. |
| Next function | `0x0050e850` begins modeled `sub_50E850`, not part of this child. |

## Behavior

IDA decompilation shows a small MapPane helper that activates or clears a linked attached object by object id:

1. Look up a map object by id through the MapPane object-list state (`this[265]` in current decompiler output).
2. Return if no object is found.
3. Read the object's attached overlay pointer at object offset `+0x1dc`.
4. Return if no attached overlay exists.
5. Check the attached overlay active flag through [UID:000067][HitBarObjectPane](by-class/HitBarObjectPane.md)'s active-flag helper.
6. If active, call the attached object's first virtual callback with argument `1`; this is the clear/activation side used by group and linked-object marker flows.

The behavior is MapPane-owned because the receiver and object-list lookup are MapPane state. Group, LivingObjectPane, and option UI callers supply object ids or update policy, but MapPane owns the map-object side effect.

## IDA MCP Evidence

- Live IDA session `b001_mappane_0001AW_20260616` on 2026-06-16 reports `lookup_funcs(0x0050e810)` as `sub_50E810`, size `0x38`.
- The same lookup reports `0x0050e848` as not a function and `0x0050e850` as the next modeled function start.
- `analyze_function(0x0050e810)` reports size `56`, 6 basic blocks, complexity `4`, callees `sub_532370` and `sub_538EB0`.
- IDA xrefs/callers to `0x0050e810`: `0x0056e197` inside `sub_56E130`, `0x005ac2e8` inside `sub_5AC280`, and `0x005adc98` inside `sub_5ADC70`.
- `analyze_component(0x0056e130, 0x005ac280, 0x005adc70)` confirms:
  - `0x0056e130` calls `sub_50E4C0` and `sub_50E810`;
  - `0x005ac280` calls `sub_50E4C0` and `sub_50E810`;
  - `0x005adc70` calls `sub_50E810`.
- Decompilation shows object lookup through `sub_532370(this[265], objectId)`, attached-overlay pointer load at `result + 476`, active check through `sub_538EB0`, and a virtual call on the attached overlay when active.
- Padding evidence: `make_signature_for_range(0x0050e848, 0x0050e850, wildcard_operands=false)` returns `CC CC CC CC CC CC CC CC`.

## Documentation Evidence

- [UID:000090][NewGroupPane](by-class/NewGroupPane.md) says `ParseGroupListPacket` at `0x0056e130` calls MapPane marker helpers at `0x0050e810` and `0x0050e4c0`.
- [UID:0001HC][0x0056c4c0-0x0056e939.GroupPanes](by-memory/0x0056c4c0-0x0056e939.GroupPanes.md) records the same `ParseGroupListPacket` relationship and says it refreshes map markers through `0x0050e810` and `0x0050e4c0`.
- [UID:0001KR][0x005adc20-0x005adcb3.GroupMemberMarkers](by-memory/0x005adc20-0x005adcb3.GroupMemberMarkers.md) describes `0x005adc70` as `ClearGroupMemberMarkers_5ADC70`, walking cached group ids and calling the complementary map linked-object activation/clear path.
- [UID:0000JS][Group](by-file/Group.md) documents `ClearGroupMemberMarkers_5ADC70` as clearing cached group members through `MapPane::ActivateLinkedObjectById`.
- [UID:0000P1][LivingObjectPane](by-file/LivingObjectPane.md) and [UID:0001KK-linked support range][0x005a2de0-0x005ad440.LivingObjectPaneLocalPlayerExtensions](by-memory/0x005a2de0-0x005ad440.LivingObjectPaneLocalPlayerExtensions.md) place `0x005ac280` in a linked-object/player companion packet parser, which matches the MapPane linked-object side effect.
- [UID:000067][HitBarObjectPane](by-class/HitBarObjectPane.md) records active-flag accessor use from `0x0050e810`.

## Source Placement Decision

Assign this child to [UID:00007Q][MapPane](by-class/MapPane.md), emitting through MapPane. The strongest evidence is the receiver-side object list lookup and the fact that all direct callers hand off object ids into MapPane-owned side effects.

Rejected owners:

- [UID:0000JS][Group](by-file/Group.md): calls the helper from group marker clear/update logic but does not own the map object implementation.
- [UID:0000P1][LivingObjectPane](by-file/LivingObjectPane.md): calls the helper while parsing linked-object packet data but does not own MapPane's object-list lookup or attached-object virtual dispatch.
- [UID:000067][HitBarObjectPane](by-class/HitBarObjectPane.md): provides the active-flag helper reached through the attached overlay pointer, not the MapPane method receiver.
- [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md): source-family parent only; this exact child carries the method-level evidence.

## Reconstruction Notes

Final C++ remains blank. The helper is source-quality enough for a split child, but final reconstruction needs:

- final object-list field name for the `this[265]` lookup root;
- final map object type and attached-object slot name for object offset `+0x1dc`;
- final attached-object active check and virtual callback names;
- a final naming pass for whether `ActivateLinkedObjectById` is original-source quality or only the current generated/doc name.

## Score Rationale

Completion is `86` because the page records exact function boundary, padding, direct xrefs/callers, callee set, behavior, owner decision, rejected owners, and final-C++ blockers.

Confidence is `90` because current IDA xrefs and multiple support docs agree on liveness and MapPane source ownership. Confidence stays below final audit because field names, callback semantics, and original method spelling are still provisional.

## Cross-References

- [UID:00007Q][MapPane](by-class/MapPane.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md)
- [UID:0003TC][0x0050e690-0x0050e805.MapPaneApplyHitBarObjectPane](by-memory/0x0050e690-0x0050e805.MapPaneApplyHitBarObjectPane.md)
- [UID:000090][NewGroupPane](by-class/NewGroupPane.md)
- [UID:0001HC][0x0056c4c0-0x0056e939.GroupPanes](by-memory/0x0056c4c0-0x0056e939.GroupPanes.md)
- [UID:0001KR][0x005adc20-0x005adcb3.GroupMemberMarkers](by-memory/0x005adc20-0x005adcb3.GroupMemberMarkers.md)
- [UID:0000JS][Group](by-file/Group.md)
- [UID:0000P1][LivingObjectPane](by-file/LivingObjectPane.md)
- [UID:000067][HitBarObjectPane](by-class/HitBarObjectPane.md)
- [UID:0000VN][-ignored](by-memory/-ignored.md)

## Changes

- 2026-06-16 B001 continuation split batch: recommended as an exact child of [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md), scored `86/90`, routed to [UID:00007Q][MapPane](by-class/MapPane.md), and left final C++ blank pending field/callback/source-name confirmation. Evidence: IDA MCP reports `sub_50E810` size `0x38`, direct callers from `0x0056e130`, `0x005ac280`, and `0x005adc70`, decompilation shows MapPane object-list lookup and attached-overlay activation/clear behavior, and IDA confirms `0x0050e848-0x0050e850` as eight `0xcc` alignment bytes before `sub_50E850`.
```

### Parent Target Edits

File: `by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md`

Metadata stays unchanged:

```text
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

In `## Exact Child Pages And Nesting`, insert these two rows after the existing [UID:0003TB] row and before [UID:0001AX]:

```markdown
| [UID:0003TC][0x0050e690-0x0050e805.MapPaneApplyHitBarObjectPane](by-memory/0x0050e690-0x0050e805.MapPaneApplyHitBarObjectPane.md) | Exact modeled MapPane helper that computes primary/secondary hit-bar percentages, updates an active attached HitBarObjectPane, or allocates/constructs/registers a replacement for the target object. |
| [UID:0003TD][0x0050e810-0x0050e848.MapPaneActivateLinkedObjectById](by-memory/0x0050e810-0x0050e848.MapPaneActivateLinkedObjectById.md) | Exact modeled MapPane helper that looks up a map object by id and invokes the active attached-overlay virtual clear/activation callback for group and linked-object marker routes. |
```

In `## Current Exact Boundary Inventory`, replace the existing `0x0050e690` row with these two rows:

```markdown
| `0x0050e690` | `sub_50E690` | `0x175` | Exact child [UID:0003TC][0x0050e690-0x0050e805.MapPaneApplyHitBarObjectPane](by-memory/0x0050e690-0x0050e805.MapPaneApplyHitBarObjectPane.md); MapPane HitBarObjectPane update/create helper with no current direct callers but strong HitBar constructor/bounds/pool evidence. |
| `0x0050e810` | `sub_50E810` | `0x38` | Exact child [UID:0003TD][0x0050e810-0x0050e848.MapPaneActivateLinkedObjectById](by-memory/0x0050e810-0x0050e848.MapPaneActivateLinkedObjectById.md); MapPane object-id lookup and attached-overlay activation/clear helper with direct callers from `0x0056e130`, `0x005ac280`, and `0x005adc70`. |
```

Add this evidence bullet near the existing B001/IDA evidence bullets:

```markdown
- 2026-06-16 B001 continuation live IDA MCP session `b001_mappane_0001AW_20260616`: `lookup_funcs` reports `sub_50E690` size `0x175`, `sub_50E810` size `0x38`, and `sub_50E850` size `0x1e0`; `0x0050e805` and `0x0050e848` are not function starts. `analyze_function(0x0050e690)` reports no direct callers but decompiles to a MapPane-side HitBarObjectPane update/create helper with HitBar pool allocation and dual-constructor calls. `analyze_function(0x0050e810)` reports direct callers at `0x0056e197`, `0x005ac2e8`, and `0x005adc98`, and decompiles to a MapPane object-list lookup plus active attached-overlay virtual callback. `make_signature_for_range` confirms `0x0050e805-0x0050e810` as eleven `0xcc` bytes and `0x0050e848-0x0050e850` as eight `0xcc` bytes.
```

In `## Cross-References`, insert after [UID:0003TB]:

```markdown
- [UID:0003TC][0x0050e690-0x0050e805.MapPaneApplyHitBarObjectPane](by-memory/0x0050e690-0x0050e805.MapPaneApplyHitBarObjectPane.md)
- [UID:0003TD][0x0050e810-0x0050e848.MapPaneActivateLinkedObjectById](by-memory/0x0050e810-0x0050e848.MapPaneActivateLinkedObjectById.md)
```

Add this change note above the previous 2026-06-16 B001 addendum:

```markdown
- 2026-06-16 B001 continuation split batch: recommended exact children [UID:0003TC][0x0050e690-0x0050e805.MapPaneApplyHitBarObjectPane](by-memory/0x0050e690-0x0050e805.MapPaneApplyHitBarObjectPane.md) and [UID:0003TD][0x0050e810-0x0050e848.MapPaneActivateLinkedObjectById](by-memory/0x0050e810-0x0050e848.MapPaneActivateLinkedObjectById.md), plus ignored alignment ranges `0x0050e805-0x0050e810` and `0x0050e848-0x0050e850`. Parent [UID:0001AW] remains `RECONSTRUCTABLE:TRUE`, `85/88`, and owner/emitter [UID:00007Q][MapPane](by-class/MapPane.md) because the remaining broad leaves still need exact children.
```

### Support Doc Edits

File: `by-class/MapPane.md`

Do not change score. Insert these cross-reference bullets immediately after the existing [UID:0003TB] bullet:

```markdown
- [UID:0003TC][0x0050e690-0x0050e805.MapPaneApplyHitBarObjectPane](by-memory/0x0050e690-0x0050e805.MapPaneApplyHitBarObjectPane.md)
- [UID:0003TD][0x0050e810-0x0050e848.MapPaneActivateLinkedObjectById](by-memory/0x0050e810-0x0050e848.MapPaneActivateLinkedObjectById.md)
```

Add this change note above the existing `2026-06-16 B001 executable child-split addendum` note:

```markdown
- 2026-06-16 B001 continuation split batch:
  - Score unchanged at `85/85`.
  - Added exact MapPane packet/object-event children [UID:0003TC][0x0050e690-0x0050e805.MapPaneApplyHitBarObjectPane](by-memory/0x0050e690-0x0050e805.MapPaneApplyHitBarObjectPane.md) and [UID:0003TD][0x0050e810-0x0050e848.MapPaneActivateLinkedObjectById](by-memory/0x0050e810-0x0050e848.MapPaneActivateLinkedObjectById.md). The first child documents MapPane-owned HitBarObjectPane update/create policy, and the second documents MapPane object-id lookup and attached-overlay activation/clear side effects used by group and linked-object marker callers.
```

File: `by-file/MapPane.md`

Do not change score. Insert these cross-reference bullets immediately after the existing [UID:0003TB] bullet:

```markdown
- [UID:0003TC][0x0050e690-0x0050e805.MapPaneApplyHitBarObjectPane](by-memory/0x0050e690-0x0050e805.MapPaneApplyHitBarObjectPane.md)
- [UID:0003TD][0x0050e810-0x0050e848.MapPaneActivateLinkedObjectById](by-memory/0x0050e810-0x0050e848.MapPaneActivateLinkedObjectById.md)
```

Add this change note above the existing `2026-06-16 B001 executable child-split addendum` note:

```markdown
- 2026-06-16 B001 continuation split batch:
  - Score unchanged at `89/85`.
  - Added exact children [UID:0003TC][0x0050e690-0x0050e805.MapPaneApplyHitBarObjectPane](by-memory/0x0050e690-0x0050e805.MapPaneApplyHitBarObjectPane.md) and [UID:0003TD][0x0050e810-0x0050e848.MapPaneActivateLinkedObjectById](by-memory/0x0050e810-0x0050e848.MapPaneActivateLinkedObjectById.md) under the MapPane packet/object-event family. HitBarObjectPane, Group, and LivingObjectPane remain callee/caller source owners rather than owners of these MapPane methods.
```

No score or metadata changes are recommended for [UID:000067][HitBarObjectPane](../../../by-class/HitBarObjectPane.md), [UID:0000JS][Group](../../../by-file/Group.md), [UID:000090][NewGroupPane](../../../by-class/NewGroupPane.md), [UID:0000P1][LivingObjectPane](../../../by-file/LivingObjectPane.md), or [UID:0001KR][GroupMemberMarkers](../../../by-memory/0x005adc20-0x005adcb3.GroupMemberMarkers.md). They already provide sufficient caller/callee context for this batch or remain below the scope of this split.

### Ignored Ledger Edits

File: `by-memory/-ignored.md`

Insert after the existing `0x0050e68d-0x0050e690` entry:

```markdown
- `0x0050e805-0x0050e810` - alignment padding after `MapPaneApplyHitBarObjectPane`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes, not executable product logic.
  - Evidence: 2026-06-16 B001 IDA MCP `make_signature_for_range` with operand wildcarding disabled shows eleven `0xcc` bytes at `0x0050e805-0x0050e810`; `lookup_funcs` reports `sub_50E690` at `0x0050e690` size `0x175`, and the next modeled function starts at `0x0050e810`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0003TC][0x0050e690-0x0050e805.MapPaneApplyHitBarObjectPane](by-memory/0x0050e690-0x0050e805.MapPaneApplyHitBarObjectPane.md) and [UID:0003TD][0x0050e810-0x0050e848.MapPaneActivateLinkedObjectById](by-memory/0x0050e810-0x0050e848.MapPaneActivateLinkedObjectById.md).

- `0x0050e848-0x0050e850` - alignment padding after `MapPaneActivateLinkedObjectById`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes, not executable product logic.
  - Evidence: 2026-06-16 B001 IDA MCP `make_signature_for_range` with operand wildcarding disabled shows eight `0xcc` bytes at `0x0050e848-0x0050e850`; `lookup_funcs` reports `sub_50E810` at `0x0050e810` size `0x38`, and the next modeled function starts at `0x0050e850`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0003TD][0x0050e810-0x0050e848.MapPaneActivateLinkedObjectById](by-memory/0x0050e810-0x0050e848.MapPaneActivateLinkedObjectById.md) and [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md).
```

### Coverage Report Rows

Do not edit `by-memory/-coverage-report.md` directly as B001. Supervisor should replace the nested block under [UID:0001AW] by inserting these rows after the current `0x0050e68d-0x0050e690` padding row and before the existing [UID:0001AX] row:

```markdown
        - [UID:0003TC][0x0050e690-0x0050e805.MapPaneApplyHitBarObjectPane](by-memory/0x0050e690-0x0050e805.MapPaneApplyHitBarObjectPane.md) 0x0050e690-0x0050e805 | class method | MapPaneApplyHitBarObjectPane : reconstructable : 86% : strong : Exact modeled `sub_50E690` child split from MapPanePacketHandlers; computes primary/secondary hit-bar percentages, updates an active attached HitBarObjectPane when present, or removes stale marker state, allocates/constructs/registers/refreshes a dual HitBarObjectPane for the target object. Owner/emitter [UID:00007Q][MapPane](by-class/MapPane.md); HitBarObjectPane remains the constructed overlay owner. No direct callers currently modeled, so final C++ stays blank pending source-name/reachability/field confirmation.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0050e805-0x0050e810 | padding | MapPaneApplyHitBarObjectPane to MapPaneActivateLinkedObjectById alignment : ignored : 100% : strong : B001 IDA MCP `make_signature_for_range` with operand wildcarding disabled shows eleven `0xcc` bytes after `sub_50E690` end-exclusive `0x0050e805` and before next modeled function `sub_50E810` starts at `0x0050e810`.
        - [UID:0003TD][0x0050e810-0x0050e848.MapPaneActivateLinkedObjectById](by-memory/0x0050e810-0x0050e848.MapPaneActivateLinkedObjectById.md) 0x0050e810-0x0050e848 | class method | MapPaneActivateLinkedObjectById : reconstructable : 86% : strong : Exact modeled `sub_50E810` child split; looks up a map object by id through MapPane object-list state, reads the object attached-overlay pointer at `+0x1dc`, checks the HitBarObjectPane active flag helper, and invokes the attached object virtual activation/removal callback. Owner/emitter [UID:00007Q][MapPane](by-class/MapPane.md); direct xrefs from `NewGroupPane::ParseGroupListPacket` `0x0056e130`, `LivingObjectPane::ParseLinkedObjectsPacket` `0x005ac280`, and `ClearGroupMemberMarkers_5ADC70` `0x005adc70` prove liveness. Final C++ blank pending final object-list/attached-object field names.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0050e848-0x0050e850 | padding | MapPaneActivateLinkedObjectById to next MapPane helper alignment : ignored : 100% : strong : B001 IDA MCP `make_signature_for_range` with operand wildcarding disabled shows eight `0xcc` bytes after `sub_50E810` end-exclusive `0x0050e848` and before next modeled function `sub_50E850` starts at `0x0050e850`.
```

Parent [UID:0001AW] row stays unchanged. Existing [UID:0001AX], [UID:0001AY], [UID:0001AZ], and [UID:0001B0] rows stay unchanged.

No `by-class/-coverage-report.md` or `by-file/-coverage-report.md` row changes are required because MapPane class/file scores stay unchanged and the support edits are inventory links only.

### Validation Order

1. Create [UID:0003TC] and [UID:0003TD] child pages.
2. Apply [UID:0001AW], `by-class/MapPane.md`, `by-file/MapPane.md`, and `by-memory/-ignored.md` edits.
3. Run validator on the two new child pages with `--apply`.
4. Run validator on [UID:0001AW], `by-class/MapPane.md`, `by-file/MapPane.md`, and `by-memory/-ignored.md` with `--apply`.
5. Apply the `by-memory/-coverage-report.md` rows above, then run validator on `by-memory/-coverage-report.md` with `--apply`.
6. Run `python .\tools\memory_ranges.py report`.
7. Confirm Barrier Crossings, General Errors, Filename Errors, and Advanced-Error-Scan remain `None`; confirm largest-range leaves shrink by removing the newly split `0x0050e690-0x0050e805` and `0x0050e810-0x0050e848` spans from the parent leaf.

Recommended commands from `source-3/project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0001AW-mappane-packet-source-split-continuation-batch2-removed.md](0001AW-mappane-packet-source-split-continuation-batch2-removed.md). The archived block is non-authoritative and must not be executed.

### IDA DB Recommendation

Do not edit IDA for this batch.

- Function boundaries are already correct.
- Padding is already data/alignment and does not require function creation/deletion.
- `MapPaneApplyHitBarObjectPane` and `MapPaneActivateLinkedObjectById` are documentation-level working names; the first has no direct callers and both still have unresolved field/callback names. That is not strong enough for a safe IDA rename.

## Supporting Research

## Evidence Standards Used

- Live IDA MCP evidence from session `b001_mappane_0001AW_20260616`.
- Current `by-memory`, `by-class`, and `by-file` documentation after the supervisor executed the first [UID:0003TB] split.
- Current `by-memory/-coverage-report.md` nesting and `auto-generated/by-memory-tool-report.md` largest leaves.
- Padding byte checks through IDA MCP `make_signature_for_range` because no local `NexusTK.exe` was present under the workspace paths searched during this run.
- Negative evidence: current IDA caller/xref absence for `0x0050e690`; no final source name proof for either candidate; no safe IDA DB rename.

## IDA MCP Facts

| Address / range | IDA fact | Meaning |
| --- | --- | --- |
| `0x0050e690` | `lookup_funcs` returns `sub_50E690`, size `0x175`. | Real modeled function, exact range `0x0050e690-0x0050e805`. |
| `0x0050e805` | `lookup_funcs` reports not a function. | End-exclusive boundary is not a function start. |
| `0x0050e805-0x0050e810` | `make_signature_for_range` returns eleven `CC` bytes. | Alignment padding after `sub_50E690`. |
| `0x0050e810` | `lookup_funcs` returns `sub_50E810`, size `0x38`. | Real modeled function, exact range `0x0050e810-0x0050e848`. |
| `0x0050e848` | `lookup_funcs` reports not a function. | End-exclusive boundary is not a function start. |
| `0x0050e848-0x0050e850` | `make_signature_for_range` returns eight `CC` bytes. | Alignment padding after `sub_50E810`. |
| `0x0050e850` | `lookup_funcs` returns `sub_50E850`, size `0x1e0`. | Next unsplit MapPane helper; outside this bounded batch. |

## Function / Child Inventory

| Range / item | UID / path | Role | Reconstructable | Direct parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0050e4c0-0x0050e68d` | [UID:0003TB][MapPaneProcessMapEvent](../../../by-memory/0x0050e4c0-0x0050e68d.MapPaneProcessMapEvent.md) | Existing first child. | true | [UID:00007Q] | `86/89` | Existing, executed. |
| `0x0050e68d-0x0050e690` | [UID:0000VN][-ignored](../../../by-memory/-ignored.md) | Existing padding. | false | none | `100` | Existing, executed. |
| `0x0050e690-0x0050e805` | proposed [UID:0003TC] | HitBarObjectPane update/create helper. | true | [UID:00007Q] | `86/88` | Create now. |
| `0x0050e805-0x0050e810` | [UID:0000VN][-ignored](../../../by-memory/-ignored.md) | Alignment padding. | false | none | `100` | Add now. |
| `0x0050e810-0x0050e848` | proposed [UID:0003TD] | Activate/clear attached object by map object id. | true | [UID:00007Q] | `86/90` | Create now. |
| `0x0050e848-0x0050e850` | [UID:0000VN][-ignored](../../../by-memory/-ignored.md) | Alignment padding. | false | none | `100` | Add now. |
| `0x0050e850-0x00510400` | no child yet | Remaining MapPane helper span through raw day/night child boundary. | true | [UID:00007Q] | not scored | Roadmap only. |

## Direct Xref / Caller Inventory

| Address / item | Xref / caller / callee | Meaning |
| --- | --- | --- |
| `0x0050e690` | no current direct callers or xrefs to start. | Real function but liveness/source name remains less certain; create child, keep final C++ blank. |
| `0x0050e690` callees | `PoolAllocator_Allocate`, `sub_538DC0`, `sub_538E60`, `sub_538E60`, `sub_538EB0`, attached-object helpers. | HitBarObjectPane update/create behavior. |
| `0x0050e810` caller `0x0056e197` | inside `sub_56E130`. | `NewGroupPane::ParseGroupListPacket` uses MapPane linked-object activation/clear path. |
| `0x0050e810` caller `0x005ac2e8` | inside `sub_5AC280`. | LivingObjectPane linked-object/player companion parser uses the same MapPane path. |
| `0x0050e810` caller `0x005adc98` | inside `sub_5ADC70`. | Group marker clear helper calls the MapPane linked-object path. |
| `0x0050e810` callees | `sub_532370`, `sub_538EB0`. | Map object lookup plus attached-overlay active check. |

## Documentation Evidence And IDA Status

- [UID:0001AW] already lists `0x0050e690` as a modeled HitBar/object event helper and records [UID:0003TB] as the first exact split. IDA confirms the next two functions and padding.
- [UID:000067][HitBarObjectPane](../../../by-class/HitBarObjectPane.md) records MapPane caller evidence for `0x0050e690` and active-flag accessor use from `0x0050e810`. IDA decompilation confirms those callee relationships.
- [UID:0002WP][HitBarObjectPanePoolStaticStorage](../../../by-memory/0x0069b934-0x0069b95c.HitBarObjectPanePoolStaticStorage.md) records pool xref `0x0050e778` inside `0x0050e690`. IDA decompilation confirms pool allocation in the method.
- [UID:000090][NewGroupPane](../../../by-class/NewGroupPane.md), [UID:0001HC][GroupPanes](../../../by-memory/0x0056c4c0-0x0056e939.GroupPanes.md), [UID:0001KR][GroupMemberMarkers](../../../by-memory/0x005adc20-0x005adcb3.GroupMemberMarkers.md), and [UID:0000JS][Group](../../../by-file/Group.md) already describe `0x0050e810` as the complementary MapPane activation/clear path. IDA confirms direct caller addresses.
- [UID:0000P1][LivingObjectPane](../../../by-file/LivingObjectPane.md) and [UID:0001KK-linked support range](../../../by-memory/0x005a2de0-0x005ad440.LivingObjectPaneLocalPlayerExtensions.md) place `0x005ac280` in linked-object packet parsing. IDA confirms `0x005ac280` calls `0x0050e810`.

## Ranked Ownership Analysis

### 1. [UID:00007Q] MapPane

- Evidence for: both functions are inside the MapPane packet/object-event aggregate; receiver-side state is MapPane; `0x0050e810` performs MapPane object-list lookup; parent class and file already clear the 85/85 gate; neighboring [UID:0003TB] follows the same source route.
- Evidence against: `0x0050e690` has no direct callers and both names remain provisional.
- Decision: accepted. Create both children as MapPane-owned exact children.

### 2. [UID:000067] HitBarObjectPane

- Evidence for: `0x0050e690` constructs/updates HitBarObjectPane and `0x0050e810` checks the HitBar active flag helper through the attached overlay pointer.
- Evidence against: the receiver and policy are MapPane-side object/marker management; HitBarObjectPane is the constructed/called class, not the source owner of these helpers.
- Decision: rejected as canonical owner; keep as callee/support owner.

### 3. [UID:0000JS] Group / [UID:000090] NewGroupPane

- Evidence for: direct caller `0x0056e130` and marker-clear caller `0x005adc70` use `0x0050e810`; Group docs name the helper as `MapPane::ActivateLinkedObjectById`.
- Evidence against: Group supplies group member ids and marker policy, but the function itself looks up and mutates MapPane object state.
- Decision: rejected as owner; keep as direct caller evidence.

### 4. [UID:0000P1] LivingObjectPane

- Evidence for: direct caller `0x005ac280` uses `0x0050e810` while parsing linked-object/player companion packets.
- Evidence against: the callee receiver is MapPane and the side effect is MapPane attached-overlay activation/clear behavior.
- Decision: rejected as owner; keep as caller evidence.

## Blockers Investigated

- UID allocation: resolved for this report by checking current `tools/validator.ini`; next assumed UIDs are `0003TC` and `0003TD`.
- `0x0050e690` caller/liveness: IDA MCP `analyze_function` reports no direct callers or xrefs to the function start. This cannot be safely resolved further without broader pointer/relative-branch scans outside the current bounded batch. The evidence is still enough to split a real modeled function from a reconstructable parent, but not enough for final C++ or an IDA rename.
- `0x0050e810` liveness: resolved. IDA MCP reports direct callers from `0x0056e130`, `0x005ac280`, and `0x005adc70`; supporting docs identify those as group and linked-object marker paths.
- Padding: resolved. IDA MCP byte/signature checks prove `0x0050e805-0x0050e810` and `0x0050e848-0x0050e850` are all `0xcc`.
- Source owner: resolved. MapPane is the best direct owner for both children; HitBarObjectPane, Group, and LivingObjectPane are callee/caller/support contexts.
- Final C++ eligibility: not met for either child despite combined-score eligibility because source-quality names, fields, payload/attached-object types, and `0x0050e690` direct caller status remain unresolved.
- Parent reclassification: not justified. [UID:0001AW] still contains large unsplit source-bearing leaves; it must stay reconstructable and emitting after this batch.
- IDA DB edit: not safe or useful. Boundaries are already present, and names are not final enough to rename in IDA.

## Roadmap-Only Items Not In This Executable Batch

- `0x0050e850-0x00510400` remains a large source-bearing leaf. The next likely split starts at `0x0050e850`, followed by `0x0050ea30`, `0x0050edd0`, `0x0050f030`, `0x0050fb00`, and raw `0x00510400`; these need their own IDA/caller/source-name audit before creation.
- `0x005104c7-0x00513800` remains the larger later leaf. Existing [UID:0001AX] is below the 85/85 creation/routing confidence for parent reclassification, and later exact modeled handlers need bounded child work.
- [UID:0001AW] can become a non-emitting source-family split index only after exact children cover all source-bearing functions/data in the aggregate and every emitted child has a defensible direct owner/emitter route. This batch is a step toward that outcome, not enough to reclassify the parent.

## Final Recommendation

Apply the executable batch exactly as above:

- Create [UID:0003TC] `MapPaneApplyHitBarObjectPane` at `0x0050e690-0x0050e805`, `86/88`, owner/emitter [UID:00007Q].
- Create [UID:0003TD] `MapPaneActivateLinkedObjectById` at `0x0050e810-0x0050e848`, `86/90`, owner/emitter [UID:00007Q].
- Add ignored padding for `0x0050e805-0x0050e810` and `0x0050e848-0x0050e850`.
- Update [UID:0001AW], `by-class/MapPane.md`, and `by-file/MapPane.md` inventories and change notes.
- Insert the exact nested coverage rows.
- Do not change [UID:0001AW] metadata, support scores, or IDA DB.
- Keep final C++ blank for both children.

## Validator Results

Commands run by B001:

- Read-only support and coverage inspection through PowerShell.
- IDA MCP `idb_list`, `lookup_funcs`, `analyze_component`, `analyze_function`, `decompile`, and `make_signature_for_range` via JSON-RPC.

No validator command was run because this is report-only and no by-* files were directly edited by B001.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B001/research/0001AW-mappane-packet-source-split-continuation-batch2.md`
- Modified: none outside this research report.
- Direct by-* edits: none.
- IDA DB edits: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001AW-mappane-packet-source-split-continuation-batch2.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:19","uid":"0001AW"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001AW-mappane-packet-source-split-continuation-batch2-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0001AW-mappane-packet-source-split-continuation-batch2.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001AW"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
