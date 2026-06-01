*** UID:0000K9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# InterfaceEfx

## Status

- Confidence: strong for `InterfaceEfx` and `InterfaceEfxMgr` relationship; medium for final original source filename.
- Proposed module folder: `ui/`
- Proposed source file: `ui/InterfaceEfx.cpp`, with possible split `ui/InterfaceEfxMgr.cpp`
- Current generated sources: `class_InterfaceEfx.cpp`, `class_InterfaceEfxMgr.cpp`
- Evidence basis: `simroot_v2`, IDA MCP boundary/caller/callee checks, and existing Wave2 notes in `by-memory/-report.md`.

## Hypothesis

`InterfaceEfx.cpp` should own the small UI interface-effect animation class and its legacy interface-effect manager. `InterfaceEfx` is an animated pane/effect object backed by `.EPD` and `.PAD` resources, scheduled through the shared update scheduler. `InterfaceEfxMgr` owns the legacy/main-interface effect instances and periodically spawns left/right frame effects.

This should not be folded into [UID:0000IZ][Effects](by-file/Effects.md) by default. The runtime effecter file owns map/screen overlay/filter effecters, while this module owns pane-like UI/interface art such as `CHREFX.EPD`, `MAGEFX.EPD`, `ITEMEFX.EPD`, `FRMLEFX.EPD`, and `FRMREFX.EPD`.

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| [UID:00006N][InterfaceEfx](by-class/InterfaceEfx.md) | `0x004e97b0-0x004e9cfa` | `class_InterfaceEfx.cpp` | Single scheduled interface effect with resource load, play, render, tick, and teardown. |
| [UID:00006O][InterfaceEfxMgr](by-class/InterfaceEfxMgr.md) | `0x004e9d00-0x004ea120` | `class_InterfaceEfxMgr.cpp` | Legacy interface-effect manager and old-layout effect spawner; active output currently omits [UID:00018H][0x004e9ee0-0x004e9f2c.InterfaceEfxMgrTriggerInterfaceEffect](by-memory/0x004e9ee0-0x004e9f2c.InterfaceEfxMgrTriggerInterfaceEffect.md) and [UID:00018I][0x004ea060-0x004ea080.InterfaceEfxMgrSingletonAndThunks](by-memory/0x004ea060-0x004ea080.InterfaceEfxMgrSingletonAndThunks.md). |
| [UID:0000R8][g_pInterfaceEfxMgr](by-global/g_pInterfaceEfxMgr.md) | `0x0069b360` | generated global-data | Active manager singleton. |
| effect scheduler wrappers | `0x005975e0`, `0x00597600`, `0x00597610`, `0x00597630` | mixed generated ownership | Tiny wrappers around [UID:0000F0][TimerHandler](by-class/TimerHandler.md) and [UID:0000OT][TimerMgr](by-file/TimerMgr.md); callers include interface effects, but source ownership is generic timer code. |

## Boundary Notes

- IDA confirms `InterfaceEfx` starts at `0x004e97b0`; the previous function `0x004e9710` is not part of this class.
- IDA confirms `InterfaceEfxMgr` starts at `0x004e9d00`; the next unrelated class starts at `0x004ea130` and is not part of this module.
- `InterfaceEfxMgr` constructor is called by [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md) at `0x004f8ad8`, only in the older layout branch.
- [UID:00018H][0x004e9ee0-0x004e9f2c.InterfaceEfxMgrTriggerInterfaceEffect](by-memory/0x004e9ee0-0x004e9f2c.InterfaceEfxMgrTriggerInterfaceEffect.md) at `0x004e9ee0` is called from [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md) at `0x004b880b`.
- [UID:00018I][0x004ea060-0x004ea080.InterfaceEfxMgrSingletonAndThunks](by-memory/0x004ea060-0x004ea080.InterfaceEfxMgrSingletonAndThunks.md) at `0x004ea060-0x004ea080` belong to the manager island; the adjustors are vtable-referenced compiler thunks.
- `0x00597600` has broad xrefs from `InterfaceEfx` methods and many other scheduler-backed classes. It is now documented as a generic [UID:0001K8][0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers](by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md), not as `InterfaceEfx.cpp` source ownership.

## Generated Data Caveats

- Active `class_InterfaceEfxMgr.cpp` omits `0x004e9ee0` and `0x004ea060`, both IDA-confirmed manager methods now documented in exact memory pages.
- Active `class_InterfaceEfxMgr.cpp` also omits the destructor adjustor thunks `0x004ea06b` and `0x004ea076`, though metadata knows they are excluded compiler thunks.
- Active `class_InterfaceEfx.cpp` includes helper labels such as `FittingRoomListPane::OnRender` and `TextButtonExControlPane::~Pane`; treat those as provisional shared-helper/base labels, not source ownership evidence.
- Generated/source notes that assign `0x00597600` to `InterfaceEfx::RemoveFromUpdateScheduler` are caller-biased. Use [UID:0000OT][TimerMgr](by-file/TimerMgr.md) ownership for that wrapper during migration.

## Cross-References

- [UID:00006N][InterfaceEfx](by-class/InterfaceEfx.md)
- [UID:00006O][InterfaceEfxMgr](by-class/InterfaceEfxMgr.md)
- [UID:00018G][0x004e97b0-0x004ea121.InterfaceEfxAndMgr](by-memory/0x004e97b0-0x004ea121.InterfaceEfxAndMgr.md)
- [UID:0001K8][0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers](by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md)
- [UID:0000R8][g_pInterfaceEfxMgr](by-global/g_pInterfaceEfxMgr.md)
- [UID:0001RE][interface-efx-resources](by-resource/interface-efx-resources.md)
- [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md)
- [UID:00018H][0x004e9ee0-0x004e9f2c.InterfaceEfxMgrTriggerInterfaceEffect](by-memory/0x004e9ee0-0x004e9f2c.InterfaceEfxMgrTriggerInterfaceEffect.md)
- [UID:00018I][0x004ea060-0x004ea080.InterfaceEfxMgrSingletonAndThunks](by-memory/0x004ea060-0x004ea080.InterfaceEfxMgrSingletonAndThunks.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:80`.
  - Summary/evidence: `InterfaceEfx`/manager relationship, exact class ranges, singleton, old-layout trigger helper, timer-wrapper boundary, generated omissions, and resource refs are documented; confidence is capped by final source filename and shared scheduler ownership.
