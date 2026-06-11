*** UID:00006O | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000K9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# InterfaceEfxMgr

## Status

- Confidence: strong for manager role, old-layout construction, singleton lifecycle, persistent effect ownership, and destructor behavior; medium for final source split from `InterfaceEfx`.
- Likely source file: [UID:0000K9][InterfaceEfx](by-file/InterfaceEfx.md)
- Address range: [UID:00018G][0x004e97b0-0x004ea121.InterfaceEfxAndMgr](by-memory/0x004e97b0-0x004ea121.InterfaceEfxAndMgr.md)
- Current recovered file: `source-3/simroot_v2/class_InterfaceEfxMgr.cpp`

## Class Purpose

`InterfaceEfxMgr` manages old-layout interface visual effects. Its constructor creates persistent character, magic, and item interface effects, registers the manager hook with the shared effect scheduler, and stores [UID:0000R8][g_pInterfaceEfxMgr](by-global/g_pInterfaceEfxMgr.md). It can trigger one of the persistent effects and periodically spawn randomized left/right frame effects.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | `0x004e9d00-0x004e9e77` | Creates `CHREFX.EPD`, `MAGEFX.EPD`, and `ITEMEFX.EPD` effects and schedules manager hook. |
| `TriggerInterfaceEffect` | [UID:00018H][0x004e9ee0-0x004e9f2d.InterfaceEfxMgrTriggerInterfaceEffect](by-memory/0x004e9ee0-0x004e9f2d.InterfaceEfxMgrTriggerInterfaceEffect.md) | If the client option flag is enabled, plays character/item/magic effects based on input id. Active generated output omits this body. |
| `SpawnRandomFrameEffects` | `0x004e9f40-0x004ea05d` | Creates `FRMLEFX.EPD` and `FRMREFX.EPD`, optionally plays them, and reschedules itself after 120000-299999 ms. |
| singleton clear helper | [UID:00018I][0x004ea060-0x004ea081.InterfaceEfxMgrSingletonAndThunks](by-memory/0x004ea060-0x004ea081.InterfaceEfxMgrSingletonAndThunks.md) | Clears `g_pInterfaceEfxMgr`. Active generated output omits this body. |
| adjustor thunks | [UID:00018I][0x004ea060-0x004ea081.InterfaceEfxMgrSingletonAndThunks](by-memory/0x004ea060-0x004ea081.InterfaceEfxMgrSingletonAndThunks.md) | Destructor adjustors for secondary vtables. |
| scalar deleting destructor | `0x004ea090-0x004ea121` | Destroys owned persistent effects, clears singleton, tears down base pane state, and conditionally deletes storage. |

## Owned State And Resources

| State/resource | Role |
| --- | --- |
| `g_pInterfaceEfxMgr` / `0x0069b360` | Constructor publishes the manager pointer, constructor EH cleanup and scalar deleting destructor clear it, and the legacy tab-switch UI reads it before calling `TriggerInterfaceEffect`. |
| `InterfaceEfxMgr +0xf8` | Persistent `CHREFX.EPD` character interface effect. Trigger ids `0` and `1` play this effect. |
| `InterfaceEfxMgr +0xfc` | Persistent `MAGEFX.EPD` magic interface effect. Trigger id `3` plays this effect. |
| `InterfaceEfxMgr +0x100` | Persistent `ITEMEFX.EPD` item interface effect. Trigger id `2` plays this effect. |
| `FRMLEFX.EPD` / `FRMREFX.EPD` | Transient left/right frame effects allocated by `0x004e9f40`; they are played only when the interface-effect option byte is enabled. |
| `g_pConfig +0x28de5e` | Option byte checked by both the direct trigger helper and the periodic frame-effect spawner. |
| `dword_69B364` / `dword_69B368` | Main UI layer/context arguments passed into persistent and transient InterfaceEfx constructors. |

## Evidence Notes

- IDA `callers 0x004e9d00` reports the sole constructor call from [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md) at `0x004f8ad8`, in the older-layout branch.
- IDA `xrefs_to 0x004e9ee0` reports a call from [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md) at `0x004b880b`.
- IDA `decompile 0x004e9ee0` confirms the client option gate and dispatch to the manager-owned `CHREFX.EPD`, `ITEMEFX.EPD`, and `MAGEFX.EPD` effects.
- IDA `xrefs_to 0x0069b360` confirms singleton writes/clears from the constructor, clear helper, and destructor.
- IDA `xrefs_to 0x004ea060` confirms the omitted singleton-clear helper is reached through the constructor EH cleanup funclet; `xrefs_to 0x004ea06b` and `xrefs_to 0x004ea076` confirm the omitted destructor adjustors are vtable-referenced secondary destructor thunks.
- Live IDA decompilation of `0x004e9d00` shows three 348-byte allocations followed by `InterfaceEfx` constructor calls for `CHREFX.EPD`, `MAGEFX.EPD`, and `ITEMEFX.EPD`, then a scheduler add call for the manager timer subobject at `this +0xa4`.
- Live IDA decompilation of `0x004e9f40` shows allocation of `FRMLEFX.EPD` and `FRMREFX.EPD`, two `InterfaceEfx::Play` calls gated by the same client option byte, and rescheduling for `120000..299999` ms via `rand()`.
- Live IDA decompilation of `0x004ea090` shows virtual deletion of the three persistent effect pointers at `+0xf8/+0xfc/+0x100`, `g_pInterfaceEfxMgr` clear, base cleanup, and conditional storage free.
- Vtable xrefs at `0x0061c63c`, `0x0061c688`, and `0x0061c6b8` are written in the constructor and scalar deleting destructor, confirming the three-manager-vptr inherited layout.
- The following function `0x004ea130` is an `InventoryPane`-side constructor and should not be absorbed into this range.

## Cross-References

- [UID:0000K9][InterfaceEfx](by-file/InterfaceEfx.md)
- [UID:00006N][InterfaceEfx](by-class/InterfaceEfx.md)
- [UID:0000R8][g_pInterfaceEfxMgr](by-global/g_pInterfaceEfxMgr.md)
- [UID:0001RE][interface-efx-resources](by-resource/interface-efx-resources.md)
- [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md)
- [UID:00018H][0x004e9ee0-0x004e9f2d.InterfaceEfxMgrTriggerInterfaceEffect](by-memory/0x004e9ee0-0x004e9f2d.InterfaceEfxMgrTriggerInterfaceEffect.md)
- [UID:00018I][0x004ea060-0x004ea081.InterfaceEfxMgrSingletonAndThunks](by-memory/0x004ea060-0x004ea081.InterfaceEfxMgrSingletonAndThunks.md)

## Changes

- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` and attached to [UID:0000K9][InterfaceEfx](by-file/InterfaceEfx.md) because this class is 80/82 and the parent file is 86/80. Live IDA MCP on `NexusTK.exe` confirmed manager methods at `0x004e9d00`, `0x004e9ee0`, `0x004e9f40`, singleton/thunk functions `0x004ea060`, `0x004ea06b`, `0x004ea076`, scalar deleting destructor `0x004ea090`, and sole constructor caller `0x004f8ad8`.
- Completion/confidence score update: existed before as `0/0`; changed to `80/82`. Summary: old-layout effect manager role, persistent effect construction, trigger helper, random frame effect spawning, singleton/thunk/destructor handling, constructor caller, and source-split caveat are documented; confidence remains medium-strong because exact source split from `InterfaceEfx` is still open. Evidence: `InterfaceEfxAndMgr`, `InterfaceEfxMgrTriggerInterfaceEffect`, `InterfaceEfxMgrSingletonAndThunks`, `g_pInterfaceEfxMgr`, `interface-efx-resources`, and `InitializeMainUiGraph` caller evidence.
- 2026-06-06: Corrected [UID:00018I][0x004ea060-0x004ea081.InterfaceEfxMgrSingletonAndThunks](by-memory/0x004ea060-0x004ea081.InterfaceEfxMgrSingletonAndThunks.md) from the stale `0x004ea080` endpoint to `0x004ea081` and corrected the scalar deleting destructor end to `0x004ea121`; live IDA MCP confirmed the third adjustor is size `0xb` and the destructor includes the final `retn 4` byte at `0x004ea120`.
- 2026-06-06 A005 evidence refresh: raised completion/confidence from `80/82` to `84/86` after live IDA MCP reconfirmed manager constructor allocations, persistent effect resources and offsets, option-gated trigger/spawner behavior, random reschedule interval, scalar deleting destructor cleanup, singleton xrefs, and manager vtable xrefs; final source split from `InterfaceEfx` remains open.
