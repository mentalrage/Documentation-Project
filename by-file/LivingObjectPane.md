*** UID:0000KU | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# LivingObjectPane

## Status

- Confidence: strong for class responsibility and main anchors; medium for exact original file split around packet helpers and nested helper classes.
- Proposed module: `map/LivingObjectPane.cpp`
- Current generated sources: `class_LivingObjectPane.cpp`, `class_LivingObjectPane__BoxRotator.cpp`
- Primary class doc: [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md)
- Core memory docs: [UID:0001DE][0x0053a110-0x0053d818.LivingObjectPaneCore](by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md), child pages [UID:0002R0][0x0053a110-0x0053a6a6.LivingObjectPaneConstructionAndCleanup](by-memory/0x0053a110-0x0053a6a6.LivingObjectPaneConstructionAndCleanup.md), [UID:0002R1][0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer](by-memory/0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer.md), [UID:0002R2][0x0053bb20-0x0053beb6.LivingObjectPaneRenderFrameMethods](by-memory/0x0053bb20-0x0053beb6.LivingObjectPaneRenderFrameMethods.md), [UID:0002R3][0x0053d430-0x0053d589.LivingObjectPaneScalarDeletingDestructor](by-memory/0x0053d430-0x0053d589.LivingObjectPaneScalarDeletingDestructor.md), and [UID:0001KM][0x005a2de0-0x005ad440.LivingObjectPaneLocalPlayerExtensions](by-memory/0x005a2de0-0x005ad440.LivingObjectPaneLocalPlayerExtensions.md)

## File Role

`LivingObjectPane.cpp` is the live map entity source for players, NPCs, monsters, pets, and other living map actors. It sits on top of [UID:0000M5][ObjectPane](by-file/ObjectPane.md), between [UID:0000L3][MapPane](by-file/MapPane.md), render asset libraries, input/command panels, and the network packet layer.

The original source likely contained the main `LivingObjectPane` class and its small nested `BoxRotator` timer/frame helper. Wave3 currently emits `LivingObjectPane__BoxRotator` as a standalone file, but the vtable name and constructor state make it look like a nested helper inside or beside `LivingObjectPane.cpp`, not an independent feature module.

## Proposed Contents

| Entity | Evidence | Proposed ownership |
| --- | --- | --- |
| `LivingObjectPane` | Wave3 grade `94.8`, 78 modeled methods, zero missing target refs | Main `map/LivingObjectPane.cpp` class. |
| `LivingObjectPane::BoxRotator` / `LivingObjectPane__BoxRotator` | Scalar deleting destructor at `0x0053d030`, vtable `??_7BoxRotator@LivingObjectPane@@6B@` | Nested/private helper in `LivingObjectPane.cpp` unless later source evidence proves a separate file. |
| Movement history helpers | `0x005a87e0`, `0x005a8810`, `0x005a9310` | Keep with living-object movement/prediction state. |
| Command/spell slot dispatch | [UID:0001KN][0x005a3e30-0x005a3ff3.UseInventorySlotDispatch](by-memory/0x005a3e30-0x005a3ff3.UseInventorySlotDispatch.md), `0x005a4530` | Keep with `LivingObjectPane`; these consume local player spell/item/command tables and create input panes. |
| Local movement send/ack handlers | `0x005a2e00`, `0x005a5a90`, `0x005ab090`, `0x005ab410`, `0x005ad360` | Keep with `LivingObjectPane`, not [UID:0000P1][UserPane](by-file/UserPane.md), because they mutate map entity position, facing, prediction state, and attack packets. |
| Login/player settings packet handlers | `0x005aa480`, `0x005aa710`, `0x005aac80` | Keep with `LivingObjectPane` for now; they update local living-object state and side-panel/map state during server entry. |

## Major Method Families

| Area | Representative anchors | Notes |
| --- | --- | --- |
| Entity construction and destruction | `0x0053a110`, `0x0053a360`, `0x0053a5a0`, `0x0053d030`, `0x0053d430` | Constructs human/monster actor state, object links, timer target state, nested `BoxRotator`, and cleanup paths. |
| Render and sprite state | `0x0053a700`, `0x0053a8c0`, `0x0053a900`, `0x0053b3d0`, `0x0053b700`, `0x0053bb20-0x0053bec0` | Bounds, sprite config, facing, animation playback, image-frame selection, and linked visual refresh. |
| Linked objects and effects | `0x005376d0`, `0x0053ab40`, `0x0053ada0`, `0x0053ae70`, `0x0053ae80`, `0x0053b130`, `0x0053c070`, `0x0053c1d0` | Owns ground/shadow/EPF/nameplate objects, effect lists, and syncing linked objects to actor position. |
| Scattered accessors | [UID:000233][0x00514ea0-0x00514edd.LivingObjectPaneGmNameSuffixCheck](by-memory/0x00514ea0-0x00514edd.LivingObjectPaneGmNameSuffixCheck.md), `0x005374d0`, `0x005376c0`, `0x005376d0`, `0x00537bc0`, [UID:00023H][0x00538bb0-0x00538bb7.LivingObjectPaneGetEntityId](by-memory/0x00538bb0-0x00538bb7.LivingObjectPaneGetEntityId.md) | Name suffix, position/type/id, animation-state, and linked-nameplate helpers outside the contiguous core block. |
| Movement timers | `0x0053b280`, `0x0053bf40`, `0x0053bf80`, `0x0053c390`, `0x005a36f0`, `0x005a3770` | Schedules/cancels FourCC timer messages through the generic timer scheduler and advances tile movement. |
| Player movement and prediction | `0x005a2e00`, `0x005a5a90`, `0x005a87e0`, `0x005a8810`, `0x005a8cf0`, `0x005a9310`, `0x005ab090`, `0x005ab410` | Sends movement/facing packets, records prediction history, handles server correction, and warps local position. |
| Spell/action commands | `0x005a3e30`, `0x005a4530`, `0x005a58c0`, `0x005acc30`, `0x005ad360` | Uses spell/command slots, creates target input panes, sends action/attack packets, and auto-faces targets. |
| Server packet handlers | `0x005aa480`, `0x005aa710`, `0x005aac80`, `0x005ab860`, `0x005abb20`, `0x005abda0`, `0x005ac280` | Handles settings, spell-slot updates, entry/login state, chat/user-list/UI-panel packets, and linked object packet data. |

## Boundary Notes

- Keep [UID:0000P1][UserPane](by-file/UserPane.md) separate. `UserPane` owns the local user UI surface and event methods; `LivingObjectPane` owns world-object movement, animation, map placement, and command packet behavior.
- Keep [UID:0000L3][MapPane](by-file/MapPane.md) separate. `LivingObjectPane` calls map spatial/indexing and coordinate APIs, but it owns the entity-side state transitions.
- Keep [UID:0000M5][ObjectPane](by-file/ObjectPane.md) as the base map-object pane; do not pull actor-specific movement/packet code down into the base class.
- Keep [UID:0000I5][Chatting](by-file/Chatting.md) and [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md) separate. `HandleChatMessagePacket` touches chat speaker history and display, but that does not make `LivingObjectPane.cpp` the owner of chat pane classes.
- Do not treat active generated calls named `SoundManager::CancelTimer` or `SoundManager::CancelPendingTimersExceptEvent` as audio ownership evidence. The call targets at `0x00597610` and `0x00597630` are generic [UID:0001K9][0x00597610-0x00597645.TimerHandlerWrappers](by-memory/0x00597610-0x00597645.TimerHandlerWrappers.md), and `LivingObjectPane` uses them as a timer owner for sprite, facing, and animation state.
- Do not migrate every address inside `0x005a2de0-0x005ad440` blindly. IDA currently does not define functions at several Wave3-projected starts, and unrelated helper thunks exist in the same neighborhood.
- Treat the current generated names for the paired hotkey dispatch helpers as provisional. [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md) resolves state `2` / `.usr` `S` from the spell-inventory tab and state `3` / `.usr` `I` from the inventory tab, even though those states dispatch through the currently named `UseCommandSlot` (`0x005a4530`) and `UseSpellSlot` (`0x005a3e30`) helpers. The `0x005a3e30` helper is now documented as [UID:0001KN][0x005a3e30-0x005a3ff3.UseInventorySlotDispatch](by-memory/0x005a3e30-0x005a3ff3.UseInventorySlotDispatch.md) based on its `UseInputPane` caller and `ItemWhoInputPane` target-selection path.

## IDA MCP Evidence

Targeted IDA checks on 2026-05-23 confirmed:

- `0x0053a110-0x0053a35d` and `0x0053a360-0x0053a59d` are constructor bodies.
- `0x0053a5a0-0x0053a6a6` is the non-deleting destructor body; `0x0053d430-0x0053d589` is the scalar deleting destructor.
- `0x0053d030-0x0053d053` is referenced by the `BoxRotator@LivingObjectPane` vtable.
- `0x005a2e00-0x005a36de`, `0x005a5a90-0x005a5b79`, `0x005a88d0-0x005a89c9`, and `0x005a8cf0-0x005a8e67` are real local-player movement/action functions interleaved near `UserPane`.
- `0x005ab090-0x005ab410`, `0x005ab410-0x005ab75d`, `0x005ab860-0x005aba7b`, `0x005abda0-0x005abee8`, `0x005ac280-0x005ac69b`, `0x005acc30-0x005acd85`, and `0x005ad360-0x005ad441` are real IDA functions in the packet/action tail.

IDA did not define functions at Wave3-projected starts `0x005a3a20`, `0x005a9250`, `0x005aaff0`, `0x005ac1b0`, `0x005ac7e0`, or `0x005ac9a0` during this pass. Treat those as boundary-review items until IDA function creation or lower-level disassembly confirms them.

Targeted IDA checks on 2026-05-24 confirmed:

- `0x0053a900` (`SetSpriteConfig`) calls timer-wrapper targets `0x00597630` and `0x00597610`, calls `0x0053b700` (`PlayAnimation`) when sprite config switches to animated actor mode, and invalidates through the map/object refresh path.
- `0x0053b700` (`PlayAnimation`) cancels the frame-animation timer through `0x00597610`, resolves animation frames through sprite resource helpers, and schedules follow-up frame callbacks through `TimerMgr::ScheduleTimer` at `0x00597910`.
- `0x0053b830` handles timer messages for direction changes, forward movement, rotation/frame stepping, refresh callbacks, and frame-animation callbacks; it reschedules through `TimerMgr::ScheduleTimer` rather than owning a separate scheduler.
- `0x005a36f0`, `0x005a3770`, `0x005a5a90`, `0x005ab090`, and `0x005ab410` confirm the same timer ownership in the local-player movement extension: walking and directional movement schedule through `0x00597910`, while warp/correction paths cancel pending actor timers through `0x00597610` or the timer-manager removal helper at `0x00597a10`.
- 2026-05-26 IDA static-pool review identifies the [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md) [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md) at `0x0069b894`, constructed by `0x0041a100` with block size `524` and `32` blocks per chunk.

## Cross-References

- [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md)
- [UID:00007C][LivingObjectPane__BoxRotator](by-class/LivingObjectPane__BoxRotator.md)
- [UID:000233][0x00514ea0-0x00514edd.LivingObjectPaneGmNameSuffixCheck](by-memory/0x00514ea0-0x00514edd.LivingObjectPaneGmNameSuffixCheck.md)
- [UID:00023H][0x00538bb0-0x00538bb7.LivingObjectPaneGetEntityId](by-memory/0x00538bb0-0x00538bb7.LivingObjectPaneGetEntityId.md)
- [UID:0001DE][0x0053a110-0x0053d818.LivingObjectPaneCore](by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md)
- [UID:0001KM][0x005a2de0-0x005ad440.LivingObjectPaneLocalPlayerExtensions](by-memory/0x005a2de0-0x005ad440.LivingObjectPaneLocalPlayerExtensions.md)
- [UID:0001KN][0x005a3e30-0x005a3ff3.UseInventorySlotDispatch](by-memory/0x005a3e30-0x005a3ff3.UseInventorySlotDispatch.md)
- [UID:0000M5][ObjectPane](by-file/ObjectPane.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000P1][UserPane](by-file/UserPane.md)
- [UID:0000I5][Chatting](by-file/Chatting.md)
- [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md)
- [UID:0000OT][TimerMgr](by-file/TimerMgr.md)
- [UID:0001K9][0x00597610-0x00597645.TimerHandlerWrappers](by-memory/0x00597610-0x00597645.TimerHandlerWrappers.md)
- [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:88` and `CONFIDENCE:80`.
  - Summary/evidence: live map-entity source role, nested `BoxRotator`, major method families, command/movement/server-packet helpers, timer ownership, boundary notes, IDA checks, static pool evidence, and cross-references are documented; confidence is capped by unresolved projected starts and exact split around packet helpers and nested classes.
