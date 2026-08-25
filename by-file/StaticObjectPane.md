*** UID:0000O6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# StaticObjectPane

## Status

- Confidence: very strong for exact class/source route, complete `0x12c` declaration, source method inventory, inline id accessor/destructor cause, pool ownership, and compiler-generated vtable/scalar/adjustor separation; inferred private spellings cap confidence at `91`.
- Proposed module: `map/StaticObjectPane.cpp`
- Current generated source: `source-3/simroot_v2/class_StaticObjectPane.cpp`
- Primary class doc: [UID:0000E1][StaticObjectPane](by-class/StaticObjectPane.md)
- Main address docs: [UID:0001D6][0x00537900-0x00537abf.StaticObjectPaneCore](by-memory/0x00537900-0x00537abf.StaticObjectPaneCore.md), [UID:00023G][0x00537ac0-0x00537b39.StaticObjectPaneSendInteractionPacket](by-memory/0x00537ac0-0x00537b39.StaticObjectPaneSendInteractionPacket.md), [UID:000388][0x0053d740-0x0053d7bd.StaticObjectPaneScalarDeletingDestructor](by-memory/0x0053d740-0x0053d7bd.StaticObjectPaneScalarDeletingDestructor.md), [UID:00034X][0x00620340-0x006203ec.StaticObjectPaneVtableData](by-memory/0x00620340-0x006203ec.StaticObjectPaneVtableData.md), and mixed inventory [UID:0001DN][0x0053d660-0x0053d7bd.SoundAndStaticObjectPaneDestructors](by-memory/0x0053d660-0x0053d7bd.SoundAndStaticObjectPaneDestructors.md)

## File Role

`StaticObjectPane.cpp` likely owns the `ObjectPane` subclass used for map static objects. It stores the static object id, delegates bounds/render/hit-test work to the static-object image library, and sends a small object-interaction packet when the user clicks inside the static object's active bounds.

The file now has a complete header-and-source route through [UID:0000E1][StaticObjectPane](by-class/StaticObjectPane.md): guarded H owns inherited `ObjectPane` state through `+0x127`, unsigned-short `m_staticObjectId` at `+0x128`, natural tail alignment through total size `0x12c`, constructor, inline virtual destructor, hit-test, bounds, render, event, private packet helper, and inline `GetStaticObjectId()`. CPP includes `StaticObjectPane.h` before the exact method children. This by-file page stays prose-only and does not duplicate either formal channel.

[UID:00023D][0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper](by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md) is an exact consumer of this header: ObjectList scans static pane rows, compares `GetStaticObjectId()`/the same unsigned-short identity, invalidates matching panes, and uses their attachment relationship while removing, updating, or creating a `LightingObjectPane`. The source-facing route is `ObjectList.cpp -> StaticObjectPane.h -> ObjectPane.h`.

Keep this separate from [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md). The image library owns static-object asset tables and drawing primitives; `StaticObjectPane` owns the live map-object wrapper, object identity, map click handling, and `ObjectPane` lifecycle.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `StaticObjectPane` | `0x00537900-0x00537abf`, [UID:00023G][0x00537ac0-0x00537b39.StaticObjectPaneSendInteractionPacket](by-memory/0x00537ac0-0x00537b39.StaticObjectPaneSendInteractionPacket.md), [UID:000388][0x0053d740-0x0053d7bd.StaticObjectPaneScalarDeletingDestructor](by-memory/0x0053d740-0x0053d7bd.StaticObjectPaneScalarDeletingDestructor.md) | Map object wrapper for static map props. |
| static object bounds/render hooks | `0x00537950`, `0x00537970`, `0x005379a0` | `HitTestStaticObjectPixel`, `CopyStaticObjectBounds`, and `RenderStaticObjectForTarget` forwarding through `g_pStaticObjImageLib`. |
| static object interaction sender | `0x005379d0-0x00537abf`, `0x00537ac0-0x00537b39` | Handles click/mouse event data and sends opcode `0x43` subcommand `0x03` tile-coordinate interaction payload; the later helper is retained private `SendInteractionPacket()` code with no current static callers but source-ready first-draft C++. |
| `g_staticObjectPanePool` | [UID:0002WM][0x0069b8bc-0x0069b8e4.StaticObjectPanePoolStaticStorage](by-memory/0x0069b8bc-0x0069b8e4.StaticObjectPanePoolStaticStorage.md), constructor wrapper `0x0041a160`, cleanup wrapper `0x0060c3b0`, allocation/free xrefs `0x0050f086`, `0x00514d05`, `0x0053d776` | File-scope StaticObjectPane object pool declaration: `static PoolAllocator g_staticObjectPanePool(0x12c, 0x10);`. The source-facing spelling/linkage remain inferred; this declaration belongs in `NexusTK/map/StaticObjectPane.cpp`, not `PoolAllocator.cpp`. |
| `StaticObjectPane` RTTI/vtables | [UID:00034X][0x00620340-0x006203ec.StaticObjectPaneVtableData](by-memory/0x00620340-0x006203ec.StaticObjectPaneVtableData.md) | Compiler-emitted primary and adjusted vtable views regenerated from the class declaration. |
| complete class declaration and id accessor | [UID:0000E1][StaticObjectPane](by-class/StaticObjectPane.md), constructor `0x00537900`, `m_staticObjectId` at `+0x128`, total size `0x12c` | Class-before-children declaration with natural inline `GetStaticObjectId()` consumed by [UID:0003TJ][0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion](by-memory/0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion.md). |

## Boundary Notes

- IDA confirms a real helper at `0x00537950-0x00537970` that older generated `class_StaticObjectPane.cpp` output omitted. B003 source-quality reanalysis names it `HitTestStaticObjectPixel`; it calls `g_pStaticObjImageLib` with `m_staticObjectId` and caller-supplied local pixel coordinates.
- Historical pre-class-closure generated source listed `HandleStaticObjectEvent` at `0x005379d0` but omitted its body after the local event struct. IDA decompilation and the exact memory child confirm the real packet-sending body through `0x00537abf`; the complete class route now declares it naturally.
- 2026-06-21 B006 Rule 26 incorporation confirms [UID:00023G][0x00537ac0-0x00537b39.StaticObjectPaneSendInteractionPacket](by-memory/0x00537ac0-0x00537b39.StaticObjectPaneSendInteractionPacket.md) as retained private `StaticObjectPane::SendInteractionPacket()` code after a one-byte alignment gap. IDA has no function record or direct static callers, and no VA/RVA pointer route to `0x00537ac0` is known, but the exact packet body is source-ready. `SendInteractionPacket` is the best-supported class-scope spelling; `SendStaticObjectInteractionPacket` is acceptable but redundant, while raw `FUN_00537ac0`/generated helper names remain trace evidence only.
- Keep [UID:0001D6][0x00537900-0x00537abf.StaticObjectPaneCore](by-memory/0x00537900-0x00537abf.StaticObjectPaneCore.md) and [UID:00023G][0x00537ac0-0x00537b39.StaticObjectPaneSendInteractionPacket](by-memory/0x00537ac0-0x00537b39.StaticObjectPaneSendInteractionPacket.md) as separate emitting bodies. The checked handler contains its own compiled inline packet serialization, while the later raw helper emits the exact retained out-of-line sender body.
- Destructor adjustor thunks at `0x0053cf88` and `0x0053cf93` forward to the scalar deleting destructor at `0x0053d740`; `0x0053cf93` is currently listed as missing code in disabled output.
- 2026-06-11 exact destructor split [UID:000388][0x0053d740-0x0053d7bd.StaticObjectPaneScalarDeletingDestructor](by-memory/0x0053d740-0x0053d7bd.StaticObjectPaneScalarDeletingDestructor.md) confirms the file-owned scalar deleting destructor at `0x0053d740-0x0053d7bd`; it calls `ObjectPane` cleanup and optionally frees through the StaticObjectPane static pool at `0x0069b8bc`.
- 2026-06-12 A005 Batch259 exact vtable repair [UID:00034X][0x00620340-0x006203ec.StaticObjectPaneVtableData](by-memory/0x00620340-0x006203ec.StaticObjectPaneVtableData.md) confirms this source root owns the `StaticObjectPane` class declaration that regenerates the primary vtable at `0x00620344`, adjusted views at `0x006203b4` and `0x006203e4`, constructor stores at `0x00537926/0x0053792c/0x00537936`, and the successor boundary before `ItemObjectPane` at `0x006203ec`.
- 2026-06-28 B006 current MCP recheck keeps [UID:00034X][0x00620340-0x006203ec.StaticObjectPaneVtableData](by-memory/0x00620340-0x006203ec.StaticObjectPaneVtableData.md) as generated-binary RTTI/vtable output regenerated from the `StaticObjectPane` class declaration in this file, not a handwritten source table. Session `agent_b009_0002my_20260628` reported server health OK and reconfirmed the `0x00620340` RTTI start, primary/adjusted vtable bases `0x00620344`, `0x006203b4`, `0x006203e4`, constructor stores `0x00537926/0x0053792c/0x00537936`, method slot refs `0x00620394/0x006203a0/0x006203b8`, destructor/adjustor targets `0x0053d740/0x0053cf88/0x0053cf93`, and the excluded `ItemObjectPane` RTTI successor at `0x006203ec`. The UID00034X formal C++ should be only a covered-by marker, so generated `StaticObjectPane.cpp` should no longer show a UID00034X Empty Emitter Marker after scoped validation refresh.
- The global pointer [UID:0000SD][g_pStaticObjImageLib](by-global/g_pStaticObjImageLib.md) is a dependency on [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md), not proof that static-object image library code belongs in this file.
- B003 traced raw caller `0x0050c691` to a MapPane-owned helper inside `0x0050c5e0-0x0050c6da`; that helper scans object-list rows and calls StaticObjectPane pixel hit-testing, but it stays MapPane support context rather than StaticObjectPane source ownership.
- 2026-05-26 IDA static-pool review identifies the [UID:0000E1][StaticObjectPane](by-class/StaticObjectPane.md) [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md) at `0x0069b8bc`, constructed by `0x0041a160` with block size `300` and `16` blocks per chunk.
- 2026-07-09 B002 [UID:0002WM][0x0069b8bc-0x0069b8e4.StaticObjectPanePoolStaticStorage](by-memory/0x0069b8bc-0x0069b8e4.StaticObjectPanePoolStaticStorage.md) implementation callback updates the StaticObjectPane pool from an empty emitter-marker state to the preferred first-draft declaration `static PoolAllocator g_staticObjectPanePool(0x12c, 0x10);`. Evidence-time MCP session `b001-0002wl-readonly` reported healthy NexusTK.exe analysis, writable `.data` storage, 40 zero-filled bytes, raw operand label `unk_69B8BC`, and direct xrefs at `0x0041a167`, `0x0050f086`, `0x00514d05`, `0x0053d776`, and `0x0060c3b0`. At that time a `sizeof(StaticObjectPane)` rewrite was deferred pending final layout proof; the current declaration closes size `0x12c` but deliberately preserves the accepted numeric pool declaration.
- 2026-07-15 B003 source-quality evidence closes that former class-declaration blocker: constructor and image consumers prove `+0x128` is an unsigned 16-bit static-object id; UID0003TJ consumes the natural inline accessor; and the inherited layout plus natural tail alignment close exact size `0x12c`. The numeric pool declaration remains unchanged.
- Source/compiler boundary: source owns the class declaration, inline empty virtual destructor, accessor, constructor and semantic methods. MSVC owns all three vtable/RTTI views, constructor vptr stores, two destructor adjustors, scalar deleting wrapper/flag, explicit base teardown, pool release, constructor cleanup, and cookie/EH code. No raw tables or expanded compiler mechanics belong in human source.

## Cross-References

- [UID:0000E1][StaticObjectPane](by-class/StaticObjectPane.md)
- [UID:0001D6][0x00537900-0x00537abf.StaticObjectPaneCore](by-memory/0x00537900-0x00537abf.StaticObjectPaneCore.md)
- [UID:00023G][0x00537ac0-0x00537b39.StaticObjectPaneSendInteractionPacket](by-memory/0x00537ac0-0x00537b39.StaticObjectPaneSendInteractionPacket.md)
- [UID:000388][0x0053d740-0x0053d7bd.StaticObjectPaneScalarDeletingDestructor](by-memory/0x0053d740-0x0053d7bd.StaticObjectPaneScalarDeletingDestructor.md)
- [UID:00034X][0x00620340-0x006203ec.StaticObjectPaneVtableData](by-memory/0x00620340-0x006203ec.StaticObjectPaneVtableData.md)
- [UID:0001DN][0x0053d660-0x0053d7bd.SoundAndStaticObjectPaneDestructors](by-memory/0x0053d660-0x0053d7bd.SoundAndStaticObjectPaneDestructors.md)
- [UID:0000M5][ObjectPane](by-file/ObjectPane.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md)
- [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md)

## Changes

- 2026-08-11 B003 UID00023D support synchronization: preserved file metadata `90/91`, owner `FILE`, and `NexusTK/map/`. Synchronized the guarded class-H ownership, CPP include-before-children route, and exact ObjectList lighting-refresh consumer; the by-file page remains non-emitting by schema.
- 2026-07-15 B003 UID0003TJ support callback: raised `86/88` to `90/91`, retained `NexusTK/map/`, preserved all child/static-pool/history facts, and synchronized the complete UID0000E1 `0x12c` declaration, inline id accessor/destructor source cause, exact source method inventory, target consumer, class-before-children route, and compiler exclusions. The by-file formal remains absent by design because the class and exact children own emission.

- 2026-06-05: Assigned projected reconstruction folder.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank, so the by-file row remained a generated-root coverage error.
  - After: set the folder to `NexusTK/map/`.
  - Evidence: live IDA MCP lookup confirms the documented `StaticObjectPane` constructor anchor at `0x00537900`; proposed-source-tree keeps the live static-map-object wrapper in `map/`, separate from the render asset library `StaticObjImageLib.cpp`.
- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `82` and confidence to `86`.
  - Evidence: document captures map-object wrapper role, proposed contents, static-image-library dependency boundary, packet helper split, omitted helper, destructor thunks, pool allocator evidence, and cross-references; confidence is high because role and core range are strongly anchored.
- 2026-06-11 A008 Batch 171: Raised completion/confidence from `82/86` to `85/87` after exact scalar destructor child [UID:000388][0x0053d740-0x0053d7bd.StaticObjectPaneScalarDeletingDestructor](by-memory/0x0053d740-0x0053d7bd.StaticObjectPaneScalarDeletingDestructor.md) split and live IDA confirmation of static destructor boundary, adjustor/vtable refs, base cleanup, and pool-free behavior.
- 2026-06-12 A005 Batch259: Raised completion/confidence from `85/87` to `86/88` after adding exact vtable/RTTI child [UID:00034X][0x00620340-0x006203ec.StaticObjectPaneVtableData](by-memory/0x00620340-0x006203ec.StaticObjectPaneVtableData.md), live IDA constructor-store evidence, and the `ObjectPane`/`ItemObjectPane` read-only-data boundary relationship needed for strict-gate routing.
- 2026-06-17 B003 support refresh: updated StaticObjectPane source-facing method names, packet field semantics, and static image-library dependency wording after [UID:0001D6][0x00537900-0x00537abf.StaticObjectPaneCore](by-memory/0x00537900-0x00537abf.StaticObjectPaneCore.md) source-quality execution and first-draft C++ entry.
- 2026-06-21 B006 Rule 26 support sync: changed [UID:00023G][0x00537ac0-0x00537b39.StaticObjectPaneSendInteractionPacket](by-memory/0x00537ac0-0x00537b39.StaticObjectPaneSendInteractionPacket.md) from provisional/no-code wording to retained private `SendInteractionPacket()` source ownership with first-draft C++; retained no-caller/no-function evidence remains a reachability caveat and score cap.
- 2026-06-28 B006 vtable marker support sync: preserved the current source-route decision for [UID:00034X][0x00620340-0x006203ec.StaticObjectPaneVtableData](by-memory/0x00620340-0x006203ec.StaticObjectPaneVtableData.md). This file owns the class declaration that regenerates the primary and adjusted `StaticObjectPane` RTTI/vtables, while UID00034X emits only a covered-by marker and no handwritten vtable table.
- 2026-07-09 B002 static-pool support sync: added the [UID:0002WM][0x0069b8bc-0x0069b8e4.StaticObjectPanePoolStaticStorage](by-memory/0x0069b8bc-0x0069b8e4.StaticObjectPanePoolStaticStorage.md) file-scope pool declaration as `static PoolAllocator g_staticObjectPanePool(0x12c, 0x10);`; no file metadata change.

## 2026-08-22 UID0000MM Accepted PoolAllocator Dependency Callback

- Formal CPP dependency: `#include "../util/PoolAllocator.h"`, emitted by [UID:0000E1][StaticObjectPane](by-class/StaticObjectPane.md) into this file's existing source route.
- Retained consumer declarations: `static PoolAllocator g_staticObjectPanePool(0x12c, 0x10);`.
- Inventory linkage: P02; exact ranges, bytes, xrefs, wrapper topology, and supervisor-owned materialization actions remain on their UID-bound storage pages and the accepted UID0000MM report.
- Routing: The declaration remains on UID0002WM and is emitted through UID0000E1/UID0000O6.
- Formal H disposition: no PoolAllocator declaration is duplicated here; the CPP include supplies the complete standalone utility type.
- Generated acceptance: the earlier command-26311/26323/26351/26355 observations are dated prestates only. The scoped callback validator must regenerate this CPP with the include and unchanged consumer declaration(s), and the dated physical file receipt is recorded in the accepted report.
