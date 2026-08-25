*** UID:0000K9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# InterfaceEfx

## UID0000KA Owner-Header Consumer - 2026-08-15

UID00006N now supplies the guarded `NexusTK/ui/InterfaceEfx.h` declaration required by InventoryPane: exact seven-argument constructor surface, inherited Pane lifetime, `Play()`, and exact 0x15C complete size with unresolved effect-tail names retained as opaque storage. `InventoryPane.cpp` constructs the item effect with `ITEMEFX.EPD`/`INTEFX.PAD`, marks it for deferred deletion, and plays it; this file retains all InterfaceEfx behavior, resource, and method-body ownership. No InterfaceEfx implementation moves into inventory and scores remain unchanged.

## Status

- Confidence: very strong for the shared InterfaceEfx source family, complete manager declaration/global/method order, source/compiler/data split, resources, and generated one-definition route.
- Proposed module folder: `ui/`
- Source file: `ui/InterfaceEfx.cpp`; the former optional `ui/InterfaceEfxMgr.cpp` split is superseded.
- Evidence basis: IDA MCP boundary/caller/callee checks.

## Hypothesis

`InterfaceEfx.cpp` should own the small UI interface-effect animation class and its legacy interface-effect manager. `InterfaceEfx` is an animated pane/effect object backed by `.EPD` and `.PAD` resources, scheduled through the shared update scheduler. `InterfaceEfxMgr` owns the legacy/main-interface effect instances and periodically spawns left/right frame effects.

This should not be folded into [UID:0000IZ][Effects](by-file/Effects.md) by default. The runtime effecter file owns map/screen overlay/filter effecters, while this module owns pane-like UI/interface art such as `CHREFX.EPD`, `MAGEFX.EPD`, `ITEMEFX.EPD`, `FRMLEFX.EPD`, and `FRMREFX.EPD`.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| [UID:00018G][0x004e97b0-0x004ea121.InterfaceEfxAndMgr](by-memory/0x004e97b0-0x004ea121.InterfaceEfxAndMgr.md) | `0x004e97b0-0x004ea121` | Contiguous `InterfaceEfx`/`InterfaceEfxMgr` method island. It is a reconstructable aggregate/child-insertion route, not a blank emitter and not a monolithic source body; exact children should own formal method bodies. |
| [UID:00006N][InterfaceEfx](by-class/InterfaceEfx.md) | `0x004e97b0-0x004e9cfa` | Single scheduled interface effect with resource load, play, render, tick, and teardown. |
| [UID:00006O][InterfaceEfxMgr](by-class/InterfaceEfxMgr.md) | `0x004e9d00-0x004ea121` | Legacy interface-effect manager and old-layout effect spawner; include source-authored manager methods such as [UID:00018H][0x004e9ee0-0x004e9f2d.InterfaceEfxMgrTriggerInterfaceEffect](by-memory/0x004e9ee0-0x004e9f2d.InterfaceEfxMgrTriggerInterfaceEffect.md). [UID:00018I][0x004ea060-0x004ea081.InterfaceEfxMgrSingletonAndThunks](by-memory/0x004ea060-0x004ea081.InterfaceEfxMgrSingletonAndThunks.md) is manager-owned documentation-only compiler/EH glue and should not emit source. |
| [UID:0000R8][g_pInterfaceEfxMgr](by-global/g_pInterfaceEfxMgr.md) | `0x0069b360` | Active manager singleton. |
| [UID:0003BS][0x0061c5b0-0x0061c6c0.InterfaceEfxVtableData](by-memory/0x0061c5b0-0x0061c6c0.InterfaceEfxVtableData.md) | `0x0061c5b0-0x0061c6c0` | Exact `InterfaceEfx`/`InterfaceEfxMgr` RTTI locator and vtable data assigned to this file after Batch216. |
| [UID:0003BT][0x0061c6c0-0x0061c7a4.InterfaceEfxResourceStrings](by-memory/0x0061c6c0-0x0061c7a4.InterfaceEfxResourceStrings.md) | `0x0061c6c0-0x0061c7a4` | Interface-effect resource filename literals assigned to this file after Batch216. |
| effect scheduler wrappers | `0x005975e0`, `0x00597600`, `0x00597610`, `0x00597630` | Tiny wrappers around [UID:0000F0][TimerHandler](by-class/TimerHandler.md) and [UID:0000OT][TimerMgr](by-file/TimerMgr.md); callers include interface effects, but source ownership is generic timer code. |

## Boundary Notes

- IDA confirms `InterfaceEfx` starts at `0x004e97b0`; the previous function `0x004e9710` is not part of this class.
- IDA confirms `InterfaceEfxMgr` starts at `0x004e9d00`; the next unrelated class starts at `0x004ea130` and is not part of this module.
- [UID:00018G][0x004e97b0-0x004ea121.InterfaceEfxAndMgr](by-memory/0x004e97b0-0x004ea121.InterfaceEfxAndMgr.md) now uses a formal aggregate marker plus `[[CHILDREN]]` because the range spans both `InterfaceEfx` and `InterfaceEfxMgr` methods, vtable adjustor glue, switch-table bytes, padding, and the non-emitting [UID:00018I][0x004ea060-0x004ea081.InterfaceEfxMgrSingletonAndThunks](by-memory/0x004ea060-0x004ea081.InterfaceEfxMgrSingletonAndThunks.md) compiler/EH child. The marker is the correct route for child insertion; it must not be replaced by a fake monolithic function or downgraded to non-reconstructable while source-authored methods still live in this island.
- `InterfaceEfxMgr` constructor is called by [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md) at `0x004f8ad8`, only in the older layout branch.
- [UID:00018H][0x004e9ee0-0x004e9f2d.InterfaceEfxMgrTriggerInterfaceEffect](by-memory/0x004e9ee0-0x004e9f2d.InterfaceEfxMgrTriggerInterfaceEffect.md) at `0x004e9ee0` is called from [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md) at `0x004b880b`; the exact child now emits first-draft `InterfaceEfxMgr::TriggerInterfaceEffect(int effectId)` through this file route.
- [UID:00018I][0x004ea060-0x004ea081.InterfaceEfxMgrSingletonAndThunks](by-memory/0x004ea060-0x004ea081.InterfaceEfxMgrSingletonAndThunks.md) at `0x004ea060-0x004ea081` belongs semantically to the manager island but is documentation-only/non-emitting after source-quality review: `0x004ea060` is constructor EH singleton rollback glue, and `0x004ea06b`/`0x004ea076` are vtable-referenced compiler adjustor thunks.
- `0x00597600` has broad xrefs from `InterfaceEfx` methods and many other scheduler-backed classes. It is now documented as a generic [UID:0001K8][0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers](by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md), not as `InterfaceEfx.cpp` source ownership.
- 2026-06-11 A002 Batch216 live IDA MCP reconfirmed the read-only data boundary owned by this file: `0x0061c5b0` is the `InterfaceEfx` locator, `0x0061c5b4/0x0061c600/0x0061c630` are the three `InterfaceEfx` vtables, `0x0061c638` is the `InterfaceEfxMgr` locator, `0x0061c63c/0x0061c688/0x0061c6b8` are the manager vtables, and `0x0061c6c0-0x0061c7a4` contains decoded `INTEFX.PAD`, `CHREFX.EPD`, `MAGEFX.EPD`, `ITEMEFX.EPD`, `FRMLEFX.EPD`, and `FRMREFX.EPD` literals before the `InventoryPane` successor locator.

## Parent Gate Rationale

Completion is `91` because the page now routes the complete manager class/global/constructor/ordinary destructor/trigger/OnTimer union, exact compiler/data exclusions, resources, balanced split hierarchy, and one-definition order while preserving all InterfaceEfx content. Confidence is `92` because live bytes, RTTI, vtables, xrefs, contiguous code/literals, current classes/globals, and generated routing agree; the exact stripped historical filename and broader InterfaceEfx private layout prevent a higher file-root score.

## UID0002VQ Accepted Manager Source Closure - 2026-07-21

- [UID:00006O][InterfaceEfxMgr](by-class/InterfaceEfxMgr.md) emits the complete class at position 10.
- [UID:0000R8][g_pInterfaceEfxMgr](by-global/g_pInterfaceEfxMgr.md) emits the sole typed zero definition at position 20.
- [UID:0004V0][0x004e9d00-0x004e9e78.InterfaceEfxMgrConstructor](by-memory/0x004e9d00-0x004e9e78.InterfaceEfxMgrConstructor.md), [UID:0004V1][0x004e9e80-0x004e9edf.InterfaceEfxMgrDestructor](by-memory/0x004e9e80-0x004e9edf.InterfaceEfxMgrDestructor.md), [UID:00018H][0x004e9ee0-0x004e9f2d.InterfaceEfxMgrTriggerInterfaceEffect](by-memory/0x004e9ee0-0x004e9f2d.InterfaceEfxMgrTriggerInterfaceEffect.md), and [UID:0004V2][0x004e9f40-0x004ea05e.InterfaceEfxMgrOnTimer](by-memory/0x004e9f40-0x004ea05e.InterfaceEfxMgrOnTimer.md) emit at positions 30/40/50/60.
- UID00018G is a false/non-emitting split index; UID00018I and UID0004V3 are non-emitting compiler glue; UID0003BS/UID0003BT are non-emitting compiler/literal physical data.
- Physical singleton storage UID0002VQ is non-emitting and therefore cannot duplicate UID0000R8.
- Direct manager bases are Pane and empty Singleton; complete size is `0x104` with persistent effect pointers at `+0xf8/+0xfc/+0x100`.
- `OnTimer` is the current virtual source identity; historical `SpawnRandomFrameEffects` remains only a behavior label.
- The current source route is this file. No separate manager translation unit is required or supported by exact evidence.

## Manager Compiler And Data Exclusions

- Constructor publication, Singleton clear, vptr stores, EH rollback, base teardown, destructor adjustors, scalar wrapper flags/free, RTTI, and vtables are regenerated from declarations/source bodies.
- `INTEFX.PAD` and five EPD names remain exact source literals; their physical data page does not emit separately.
- The switch table remains attached to trigger behavior and is not padding.
- Four CC-only gaps and the existing successor alignment are ignored, not emitted.

## 2026-06-16 A001 Target-Support Refresh

Live IDA MCP on database `b001_mappane_0001AW_20260616` reconfirmed the manager half of this file while refreshing [UID:00006O][InterfaceEfxMgr](by-class/InterfaceEfxMgr.md). The manager constructor at `0x004e9d00`, trigger helper at `0x004e9ee0`, frame spawner at `0x004e9f40`, singleton clear/adjustor thunks at `0x004ea060-0x004ea081`, scalar deleting destructor at `0x004ea090-0x004ea121`, and unrelated `InventoryPane` successor at `0x004ea130` all match the existing file boundary.

The same pass reconfirmed one constructor caller from [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md), one trigger caller from [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md), seven direct refs to [UID:0000R8][g_pInterfaceEfxMgr](by-global/g_pInterfaceEfxMgr.md), manager vtable refs at `0x0061c63c`, `0x0061c688`, and `0x0061c6b8`, and resource refs for `INTEFX.PAD`, `CHREFX.EPD`, `MAGEFX.EPD`, `ITEMEFX.EPD`, `FRMLEFX.EPD`, and `FRMREFX.EPD`. Decompilation confirms persistent manager effect pointers at `+0xf8/+0xfc/+0x100`, timer subobject scheduling at `+0xa4`, option-gated frame-effect playback via `g_pConfig +0x28de5e`, and randomized reschedule `rand() % 180000 + 120000`.

`search_structs InterfaceEfx` and `search_structs InterfaceEfxMgr` returned no local UDT records, so this file still keeps the one-file versus separate `InterfaceEfxMgr.cpp` split and inherited pane/timer field names as final-source blockers. That split question does not block exact child emission for [UID:00018H][0x004e9ee0-0x004e9f2d.InterfaceEfxMgrTriggerInterfaceEffect](by-memory/0x004e9ee0-0x004e9f2d.InterfaceEfxMgrTriggerInterfaceEffect.md), whose current accepted route remains `NexusTK/ui/InterfaceEfx.cpp`.

## 2026-06-20 B006 Singleton/Thunk Source-Quality Sync

The accepted route for source-authored `InterfaceEfx` and `InterfaceEfxMgr` behavior remains `NexusTK/ui/InterfaceEfx.cpp`, with the optional later `InterfaceEfxMgr.cpp` split still only a final-source organization caveat. [UID:00018I][0x004ea060-0x004ea081.InterfaceEfxMgrSingletonAndThunks](by-memory/0x004ea060-0x004ea081.InterfaceEfxMgrSingletonAndThunks.md) now stops emitting because the exact island is compiler/EH glue:

- `0x004ea060` clears `g_pInterfaceEfxMgr` only from the constructor EH cleanup funclet and should be modeled as constructor failure/unwind semantics.
- `0x004ea06b` and `0x004ea076` are secondary/tertiary destructor adjustor thunks into `0x004ea090`, regenerated by the compiler from `InterfaceEfxMgr` inheritance and destructor declarations.
- Do not add `ClearInterfaceEfxMgrSingleton`, `InterfaceEfxMgr::ClearSingleton`, or a raw `sub_4EA060` helper to generated source. The old empty emitter marker for [UID:00018I][0x004ea060-0x004ea081.InterfaceEfxMgrSingletonAndThunks](by-memory/0x004ea060-0x004ea081.InterfaceEfxMgrSingletonAndThunks.md) was metadata pollution, not a missing function body.

## 2026-07-03 B011 Aggregate Marker Sync

[UID:00018G][0x004e97b0-0x004ea121.InterfaceEfxAndMgr](by-memory/0x004e97b0-0x004ea121.InterfaceEfxAndMgr.md) is the file-level aggregate for this module's contiguous executable island. Current MCP session `3a33af0b` confirms multiple ordinary source methods and compiler/data artifacts inside the range: `InterfaceEfx` constructor/cleanup/`Play`/`Render`/`Tick`/destructor wrappers, `InterfaceEfxMgr` constructor/frame spawner/scalar deleting destructor, [UID:00018H][0x004e9ee0-0x004e9f2d.InterfaceEfxMgrTriggerInterfaceEffect](by-memory/0x004e9ee0-0x004e9f2d.InterfaceEfxMgrTriggerInterfaceEffect.md) exact trigger helper emission, [UID:00018I][0x004ea060-0x004ea081.InterfaceEfxMgrSingletonAndThunks](by-memory/0x004ea060-0x004ea081.InterfaceEfxMgrSingletonAndThunks.md) non-emitting constructor-EH rollback plus adjustor thunks, switch-table bytes at `0x004e9f30-0x004e9f40`, padding before `0x004ea060`, `0x004ea081`, and `0x004ea121`, and successor `InventoryPane` code at `0x004ea130`.

The correct source route remains `NexusTK/ui/InterfaceEfx.cpp`. The aggregate now emits only an aggregate marker plus `[[CHILDREN]]`; it is not a blank emitter and must not be expanded into one monolithic source function. Remaining `InterfaceEfx` constructor/cleanup/play/render/tick and manager constructor/spawner/destructor bodies should become exact child pages before formal method C++ is emitted. The possible later `InterfaceEfxMgr.cpp` split remains a final-source organization caveat, not a current blocker for [UID:00018G][0x004e97b0-0x004ea121.InterfaceEfxAndMgr](by-memory/0x004e97b0-0x004ea121.InterfaceEfxAndMgr.md) or [UID:00018H][0x004e9ee0-0x004e9f2d.InterfaceEfxMgrTriggerInterfaceEffect](by-memory/0x004e9ee0-0x004e9f2d.InterfaceEfxMgrTriggerInterfaceEffect.md).

## Migration Caveats

- Older source views may omit `0x004e9ee0` and `0x004ea060`; [UID:00018H][0x004e9ee0-0x004e9f2d.InterfaceEfxMgrTriggerInterfaceEffect](by-memory/0x004e9ee0-0x004e9f2d.InterfaceEfxMgrTriggerInterfaceEffect.md) now supplies first-draft C++ for the trigger helper through this file route, while the `0x004ea060` singleton clear is constructor EH rollback glue and remains non-emitting.
- The destructor adjustor thunks `0x004ea06b` and `0x004ea076` are compiler thunks, not handwritten source methods.
- Helper labels such as `FittingRoomListPane::OnRender` and `TextButtonExControlPane::~Pane` should be treated as provisional shared-helper/base labels, not source ownership evidence.
- Source notes that assign `0x00597600` to `InterfaceEfx::RemoveFromUpdateScheduler` are caller-biased. Use [UID:0000OT][TimerMgr](by-file/TimerMgr.md) ownership for that wrapper during migration.

## Cross-References

- [UID:00006N][InterfaceEfx](by-class/InterfaceEfx.md)
- [UID:00006O][InterfaceEfxMgr](by-class/InterfaceEfxMgr.md)
- [UID:00018G][0x004e97b0-0x004ea121.InterfaceEfxAndMgr](by-memory/0x004e97b0-0x004ea121.InterfaceEfxAndMgr.md)
- [UID:0001K8][0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers](by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md)
- [UID:0000R8][g_pInterfaceEfxMgr](by-global/g_pInterfaceEfxMgr.md)
- [UID:0001RE][interface-efx-resources](by-resource/interface-efx-resources.md)
- [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md)
- [UID:00018H][0x004e9ee0-0x004e9f2d.InterfaceEfxMgrTriggerInterfaceEffect](by-memory/0x004e9ee0-0x004e9f2d.InterfaceEfxMgrTriggerInterfaceEffect.md)
- [UID:00018I][0x004ea060-0x004ea081.InterfaceEfxMgrSingletonAndThunks](by-memory/0x004ea060-0x004ea081.InterfaceEfxMgrSingletonAndThunks.md)
- [UID:0003BS][0x0061c5b0-0x0061c6c0.InterfaceEfxVtableData](by-memory/0x0061c5b0-0x0061c6c0.InterfaceEfxVtableData.md)
- [UID:0003BT][0x0061c6c0-0x0061c7a4.InterfaceEfxResourceStrings](by-memory/0x0061c6c0-0x0061c7a4.InterfaceEfxResourceStrings.md)

## Changes

- 2026-06-20 B006 Rule 26 sync: updated [UID:00018I][0x004ea060-0x004ea081.InterfaceEfxMgrSingletonAndThunks](by-memory/0x004ea060-0x004ea081.InterfaceEfxMgrSingletonAndThunks.md) from "included helper" wording to documentation-only compiler/EH glue. Source-authored manager behavior still routes through this file, but the singleton rollback funclet and adjustor thunks should be regenerated from constructor/destructor/class layout rather than emitted as a clear helper.
- 2026-07-03 B011 aggregate-marker sync: [UID:00018G][0x004e97b0-0x004ea121.InterfaceEfxAndMgr](by-memory/0x004e97b0-0x004ea121.InterfaceEfxAndMgr.md) now uses a formal aggregate marker plus `[[CHILDREN]]` at `87/90`. The route remains `InterfaceEfx.cpp`; the marker replaces the stale blank-emitter state without creating a monolithic parent body or downgrading the file-owned source island to non-reconstructable.
- 2026-06-17 B003 trigger-helper route sync: clarified that [UID:00018H][0x004e9ee0-0x004e9f2d.InterfaceEfxMgrTriggerInterfaceEffect](by-memory/0x004e9ee0-0x004e9f2d.InterfaceEfxMgrTriggerInterfaceEffect.md) now emits first-draft `InterfaceEfxMgr::TriggerInterfaceEffect(int effectId)` through the existing `NexusTK/ui/InterfaceEfx.cpp` route. The optional later `InterfaceEfxMgr.cpp` split remains a final-source organization caveat, not a blocker for the exact child.
- 2026-06-11 A002 Batch216 parent-gate repair:
  - Before: score `86/80`; this file was below the strict confidence gate for assigning the exact interface-effect vtable/string children.
  - Changed to: score `87/85`, with exact read-only child rows and parent-gate rationale.
  - Evidence: live IDA MCP reconfirmed the `InterfaceEfx` and `InterfaceEfxMgr` locator/vtable cells, representative store xrefs, decoded interface-effect resource strings, and the `InventoryPane` successor boundary. Remaining final-source field/name uncertainty caps confidence at `85`.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:80`.
  - Summary/evidence: `InterfaceEfx`/manager relationship, exact class ranges, singleton, old-layout trigger helper, timer-wrapper boundary, migration caveats, and resource refs are documented; confidence is capped by final source filename and shared scheduler ownership.
- 2026-06-05 reconstruction path classification:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, leaving the file row in error.
  - Changed to: `NexusTK/ui/`.
  - Summary/evidence: `by-project-structure/proposed-source-tree.md` places `InterfaceEfx.cpp` under `NexusTK/ui/`, and live IDA MCP xrefs/decompilation confirm `0x004e9d00`, `0x004ea060`, and `0x004ea090` write/clear `dword_69B360` from the `InterfaceEfxMgr` lifecycle island.
- 2026-06-06 boundary sync:
  - Corrected [UID:00018I][0x004ea060-0x004ea081.InterfaceEfxMgrSingletonAndThunks](by-memory/0x004ea060-0x004ea081.InterfaceEfxMgrSingletonAndThunks.md) from stale end `0x004ea080` to `0x004ea081` and updated the manager island end to `0x004ea121`.
- 2026-06-16 A001 target-support refresh:
  - Before: `COMPLETION:87`, `CONFIDENCE:85`.
  - After: `COMPLETION:88`, `CONFIDENCE:87`.
  - Evidence: live IDA MCP reconfirmed the manager method sizes/boundary, constructor/trigger/singleton/vtable/resource xrefs, persistent and transient effect behavior, `InventoryPane` successor boundary, and absence of local UDT records for final source names. The source split and inherited field names still block final C++.
