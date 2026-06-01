*** UID:00006O | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# InterfaceEfxMgr

## Status

- Confidence: strong for manager role and old-layout construction; medium for final source split from `InterfaceEfx`.
- Likely source file: [UID:0000K9][InterfaceEfx](by-file/InterfaceEfx.md)
- Address range: [UID:00018G][0x004e97b0-0x004ea121.InterfaceEfxAndMgr](by-memory/0x004e97b0-0x004ea121.InterfaceEfxAndMgr.md)
- Current recovered file: `source-3/simroot_v2/class_InterfaceEfxMgr.cpp`

## Class Purpose

`InterfaceEfxMgr` manages old-layout interface visual effects. Its constructor creates persistent character, magic, and item interface effects, registers the manager hook with the shared effect scheduler, and stores [UID:0000R8][g_pInterfaceEfxMgr](by-global/g_pInterfaceEfxMgr.md). It can trigger one of the persistent effects and periodically spawn randomized left/right frame effects.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | `0x004e9d00-0x004e9e77` | Creates `CHREFX.EPD`, `MAGEFX.EPD`, and `ITEMEFX.EPD` effects and schedules manager hook. |
| `TriggerInterfaceEffect` | [UID:00018H][0x004e9ee0-0x004e9f2c.InterfaceEfxMgrTriggerInterfaceEffect](by-memory/0x004e9ee0-0x004e9f2c.InterfaceEfxMgrTriggerInterfaceEffect.md) | If the client option flag is enabled, plays character/item/magic effects based on input id. Active generated output omits this body. |
| `SpawnRandomFrameEffects` | `0x004e9f40-0x004ea05d` | Creates `FRMLEFX.EPD` and `FRMREFX.EPD`, optionally plays them, and reschedules itself after 120000-299999 ms. |
| singleton clear helper | [UID:00018I][0x004ea060-0x004ea080.InterfaceEfxMgrSingletonAndThunks](by-memory/0x004ea060-0x004ea080.InterfaceEfxMgrSingletonAndThunks.md) | Clears `g_pInterfaceEfxMgr`. Active generated output omits this body. |
| adjustor thunks | [UID:00018I][0x004ea060-0x004ea080.InterfaceEfxMgrSingletonAndThunks](by-memory/0x004ea060-0x004ea080.InterfaceEfxMgrSingletonAndThunks.md) | Destructor adjustors for secondary vtables. |
| scalar deleting destructor | `0x004ea090-0x004ea120` | Destroys owned persistent effects, clears singleton, tears down base pane state, and conditionally deletes storage. |

## Evidence Notes

- IDA `callers 0x004e9d00` reports the sole constructor call from [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md) at `0x004f8ad8`, in the older-layout branch.
- IDA `xrefs_to 0x004e9ee0` reports a call from [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md) at `0x004b880b`.
- IDA `decompile 0x004e9ee0` confirms the client option gate and dispatch to the manager-owned `CHREFX.EPD`, `ITEMEFX.EPD`, and `MAGEFX.EPD` effects.
- IDA `xrefs_to 0x0069b360` confirms singleton writes/clears from the constructor, clear helper, and destructor.
- IDA `xrefs_to 0x004ea06b` and `xrefs_to 0x004ea076` confirm the omitted destructor adjustors are vtable-referenced secondary destructor thunks.
- The following function `0x004ea130` is an `InventoryPane`-side constructor and should not be absorbed into this range.

## Cross-References

- [UID:0000K9][InterfaceEfx](by-file/InterfaceEfx.md)
- [UID:00006N][InterfaceEfx](by-class/InterfaceEfx.md)
- [UID:0000R8][g_pInterfaceEfxMgr](by-global/g_pInterfaceEfxMgr.md)
- [UID:0001RE][interface-efx-resources](by-resource/interface-efx-resources.md)
- [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md)
- [UID:00018H][0x004e9ee0-0x004e9f2c.InterfaceEfxMgrTriggerInterfaceEffect](by-memory/0x004e9ee0-0x004e9f2c.InterfaceEfxMgrTriggerInterfaceEffect.md)
- [UID:00018I][0x004ea060-0x004ea080.InterfaceEfxMgrSingletonAndThunks](by-memory/0x004ea060-0x004ea080.InterfaceEfxMgrSingletonAndThunks.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `80/82`. Summary: old-layout effect manager role, persistent effect construction, trigger helper, random frame effect spawning, singleton/thunk/destructor handling, constructor caller, and source-split caveat are documented; confidence remains medium-strong because exact source split from `InterfaceEfx` is still open. Evidence: `InterfaceEfxAndMgr`, `InterfaceEfxMgrTriggerInterfaceEffect`, `InterfaceEfxMgrSingletonAndThunks`, `g_pInterfaceEfxMgr`, `interface-efx-resources`, and `InitializeMainUiGraph` caller evidence.
