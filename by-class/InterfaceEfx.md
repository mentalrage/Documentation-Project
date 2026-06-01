*** UID:00006N | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# InterfaceEfx

## Status

- Confidence: strong
- Likely source file: [UID:0000K9][InterfaceEfx](by-file/InterfaceEfx.md)
- Address range: [UID:00018G][0x004e97b0-0x004ea121.InterfaceEfxAndMgr](by-memory/0x004e97b0-0x004ea121.InterfaceEfxAndMgr.md)
- Current recovered file: `source-3/simroot_v2/class_InterfaceEfx.cpp`

## Class Purpose

`InterfaceEfx` is a scheduled UI/interface animation object. It constructs a pane-like effect from an `.EPD` resource name, update interval, anchor position, draw layer, mirror flag, and `.PAD` palette/config resource. It can start playback, render the current frame through the shared interface render backend, tick through frames on the scheduler, and remove itself from the update scheduler during teardown.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | `0x004e97b0-0x004e98aa` | Initializes pane state, palette handle, render config, short effect filename, and effect id. |
| destructor | `0x004e98b0-0x004e994a` | Removes scheduler registration, invalidates layout, clears clip rect, and runs base pane cleanup. |
| `Play` | `0x004e9950-0x004e9a23` | Resets scheduler/render state, resolves frame size, configures bounds, and schedules immediate update. |
| `Render` | `0x004e9a90-0x004e9b13` | Draws the current effect frame through the shared UI render backend and palette handle. |
| `Tick` | `0x004e9b20-0x004e9c0f` | Advances frame timing, reschedules, or finalizes an owning dialog/effect session when complete. |
| adjustor thunks | `0x004e9c10`, `0x004e9c1b` | Destructor adjustors for secondary vtable layout. |
| scalar deleting destructor | `0x004e9c30-0x004e9cf9` | Runs cleanup and conditionally deletes storage. |
| timer remove wrapper call | `0x00597600-0x0059760d` | Generic [UID:0001K8][0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers](by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md) consumed by InterfaceEfx cleanup; not InterfaceEfx-owned source. |

## Evidence Notes

- IDA `lookup_funcs` confirms all local starts from `0x004e97b0` through `0x004e9c30`.
- IDA callers show `InterfaceEfx` construction from [UID:00006O][InterfaceEfxMgr](by-class/InterfaceEfxMgr.md), `InventoryPane`, and `SpellInventoryPane`-adjacent code.
- IDA callers show `0x00597600` used by `InterfaceEfx` methods and many other classes with embedded scheduler-backed effect state. Its body forwards through `g_pTimerMgr`, so keep it under timer scheduler ownership.
- Current generated `Render` uses a fitting-room helper label; behavior and caller context keep this with interface effects, not fitting-room source.

## Cross-References

- [UID:0000K9][InterfaceEfx](by-file/InterfaceEfx.md)
- [UID:00006O][InterfaceEfxMgr](by-class/InterfaceEfxMgr.md)
- [UID:0001RE][interface-efx-resources](by-resource/interface-efx-resources.md)
- [UID:00018G][0x004e97b0-0x004ea121.InterfaceEfxAndMgr](by-memory/0x004e97b0-0x004ea121.InterfaceEfxAndMgr.md)
- [UID:0001K8][0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers](by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `78/84`. Summary: scheduled UI effect role, constructor/destructor/play/render/tick methods, resource inputs, manager/caller relationships, scheduler wrapper ownership caveat, and generated fitting-room label correction are documented with strong confidence; remaining work is deeper field naming and final C++ reconstruction. Evidence: `InterfaceEfxAndMgr`, `InterfaceEfxMgr`, `interface-efx-resources`, and timer wrapper documentation.
