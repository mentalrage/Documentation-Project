*** UID:00006N | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000K9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# InterfaceEfx

## Status

- Confidence: strong for method boundaries, vtable ownership, resource fields, scheduler use, and source-file placement; final field names remain open.
- Likely source file: [UID:0000K9][InterfaceEfx](by-file/InterfaceEfx.md)
- Address range: [UID:00018G][0x004e97b0-0x004ea121.InterfaceEfxAndMgr](by-memory/0x004e97b0-0x004ea121.InterfaceEfxAndMgr.md)
- Current recovered file: `source-3/simroot_v2/class_InterfaceEfx.cpp`
- Parent attachment: attached to [UID:0000K9][InterfaceEfx](by-file/InterfaceEfx.md) after the class page reached the 80% gate; final C++ is intentionally blank.

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

## Observed State Layout

| Offset | Current interpretation | Evidence |
| --- | --- | --- |
| `+0x00`, `+0xa0`, `+0xa4` | Primary and secondary vptr slots for the pane/timer-style inherited layout. | Constructor, ordinary destructor, and scalar deleting destructor write InterfaceEfx vtable addresses referenced from `0x0061c5b4`, `0x0061c600`, and `0x0061c630`. |
| `+0xf8` | Resolved effect id. | Constructor initializes zero, copies the `.EPD` name, then stores the result from the effect-library lookup. |
| `+0xfc` | Scheduler interval/tick delay. | Constructor stores the third argument; `Tick` uses the stored interval when rescheduling through the timer manager. |
| `+0x100` | Palette/config handle loaded from the `.PAD` resource argument. | Constructor calls the palette/config loader and `Render` passes the handle to the draw callback. |
| `+0x104` | Current frame index. | Constructor clears it, `Play` resets it to `-1`, and `Tick` increments it before either rendering the next frame or finalizing. |
| `+0x108-0x120` | Short fixed wide-character effect filename buffer. | Constructor calls `wcsncpy_s` with count `0x0c` and writes a terminator at `+0x120`. |
| `+0x124` and following | Effect draw-state block. | Constructor initializes the block; `Render` passes it with the active frame rectangle and resolved effect id. |
| `+0x14c/+0x150/+0x154/+0x158` | Anchor position, draw layer/context, and mirror/side flag inputs. | Constructor stores the remaining arguments; `Play`, `Render`, and manager construction/spawn calls consume these values. |

## Evidence Notes

- IDA `lookup_funcs` confirms all local starts from `0x004e97b0` through `0x004e9c30`.
- IDA callers show `InterfaceEfx` construction from [UID:00006O][InterfaceEfxMgr](by-class/InterfaceEfxMgr.md), `InventoryPane`, and `SpellInventoryPane`-adjacent code.
- Live IDA callers for `0x004e97b0` are the manager constructor, manager frame spawner, `InventoryPane` setup, and another UI caller at `0x0057c366`; this confirms the class is a reusable effect object rather than manager-only state.
- Live IDA callers for `0x004e9950` are only the manager trigger helper and manager frame spawner, matching the play/trigger model.
- Live IDA callees confirm constructor dependencies on pane initialization, effect-library lookup, draw-state setup, and safe filename copy; `Play` and `Tick` call the timer scheduler wrappers documented under [UID:0001K8][0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers](by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md).
- `Render` calls the shared render setup helper, the main UI layer callback, rectangle offset helper, and the frame draw callback while passing the resolved effect id at `+0xf8`.
- `Tick` increments the current frame, removes or re-adds the scheduler registration, fetches frame offsets from the effect library for continuing frames, and invokes an owning-session finalizer only on the completion path.
- IDA xrefs tie destructor adjustors `0x004e9c10` and `0x004e9c1b` to vtable slots `0x0061c600` and `0x0061c630`, and both tail-jump into the scalar deleting destructor at `0x004e9c30`.
- IDA callers show `0x00597600` used by `InterfaceEfx` methods and many other classes with embedded scheduler-backed effect state. Its body forwards through `g_pTimerMgr`, so keep it under timer scheduler ownership.
- Current generated `Render` uses a fitting-room helper label; behavior and caller context keep this with interface effects, not fitting-room source.

## Open Questions

- Final member names are still provisional; the offset table records behavior, not final source declarations.
- The exact base-class spelling for the three vptr slots and timer callback subobject still needs a deeper pane/timer hierarchy audit.
- Final reconstruction C++ stays blank until the class layout, base types, render callbacks, and effect-library interfaces reach the 95/95 gate.

## Cross-References

- [UID:0000K9][InterfaceEfx](by-file/InterfaceEfx.md)
- [UID:00006O][InterfaceEfxMgr](by-class/InterfaceEfxMgr.md)
- [UID:0001RE][interface-efx-resources](by-resource/interface-efx-resources.md)
- [UID:00018G][0x004e97b0-0x004ea121.InterfaceEfxAndMgr](by-memory/0x004e97b0-0x004ea121.InterfaceEfxAndMgr.md)
- [UID:0001K8][0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers](by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md)

## Changes

- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` after live IDA MCP on `NexusTK.exe` confirmed effect methods at `0x004e97b0`, `0x004e98b0`, `0x004e9950`, `0x004e9a90`, `0x004e9b20`, adjustor thunks `0x004e9c10`/`0x004e9c1b`, and scalar deleting destructor `0x004e9c30`. Left `AUTOGEN_PARENT_UID` blank because this class is still below the 80 completion attachment gate.
- Completion/confidence score update: existed before as `0/0`; changed to `78/84`. Summary: scheduled UI effect role, constructor/destructor/play/render/tick methods, resource inputs, manager/caller relationships, scheduler wrapper ownership caveat, and generated fitting-room label correction are documented with strong confidence; remaining work is deeper field naming and final C++ reconstruction. Evidence: `InterfaceEfxAndMgr`, `InterfaceEfxMgr`, `interface-efx-resources`, and timer wrapper documentation.
- 2026-06-06 A005 evidence refresh: changed completion/confidence from `78/84` to `82/86` and attached the class to [UID:0000K9][InterfaceEfx](by-file/InterfaceEfx.md). Live IDA MCP reconfirmed method sizes, constructor/play callers, callee sets, vtable slot xrefs, constructor field writes, render callbacks, tick scheduler behavior, and the timer-wrapper ownership caveat; field names and final C++ remain below the source gate.
