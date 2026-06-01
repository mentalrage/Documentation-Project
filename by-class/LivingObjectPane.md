*** UID:00007B | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# LivingObjectPane

## Status

- Confidence: strong for purpose and primary method families; medium for exact method boundaries in the local-player packet tail.
- Likely source file: [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md)
- Current recovered file: `source-3/simroot_v2/class_LivingObjectPane.cpp`
- Current Wave3 grade: `94.8`
- Current Wave3 coverage: 78 modeled methods, zero missing target refs.

## Class Purpose

`LivingObjectPane` represents a living map actor. It owns actor position, facing, render bounds, sprite configuration, animation state, linked ground/shadow/EPF/nameplate objects, active effects, movement prediction history, spell/command slot dispatch, and network packets that mutate or report living-object state.

It is a gameplay map object class, not a generic UI panel. It derives through the pane/object-pane stack and is rendered by [UID:00007Q][MapPane](by-class/MapPane.md), but most of its behavior is entity state and server protocol handling.

## Method Families

| Family | Address evidence | Role |
| --- | --- | --- |
| Scattered accessors | [UID:000233][0x00514ea0-0x00514edd.LivingObjectPaneGmNameSuffixCheck](by-memory/0x00514ea0-0x00514edd.LivingObjectPaneGmNameSuffixCheck.md), `0x005374d0`, `0x005376c0`, `0x005376d0`, `0x00537bc0`, [UID:00023H][0x00538bb0-0x00538bb7.LivingObjectPaneGetEntityId](by-memory/0x00538bb0-0x00538bb7.LivingObjectPaneGetEntityId.md) | GM suffix check, position/type/id accessors, animation-state setter, and linked nameplate ownership. |
| Core construction/destruction | [UID:0002R0][0x0053a110-0x0053a6a6.LivingObjectPaneConstructionAndCleanup](by-memory/0x0053a110-0x0053a6a6.LivingObjectPaneConstructionAndCleanup.md), [UID:0002R3][0x0053d430-0x0053d589.LivingObjectPaneScalarDeletingDestructor](by-memory/0x0053d430-0x0053d589.LivingObjectPaneScalarDeletingDestructor.md) | Constructor variants, full cleanup, and scalar deleting destructor. |
| Render/sprite state | `0x0053a700-0x0053a9ed`, `0x0053b3d0-0x0053b830`, [UID:0002R1][0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer](by-memory/0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer.md), [UID:0002R2][0x0053bb20-0x0053beb6.LivingObjectPaneRenderFrameMethods](by-memory/0x0053bb20-0x0053beb6.LivingObjectPaneRenderFrameMethods.md) | Render bounds, sprite config, facing, animation playback, death animation, timer callbacks, nameplate spawn, draw, sprite draw, and bounds methods. |
| Linked object/effect ownership | `0x0053ab40`, `0x0053ada0`, `0x0053ae70`, `0x0053ae80`, `0x0053b130`, `0x0053bad0` | Destroys and replaces linked objects and clears/removes active effects. |
| Movement state machine | `0x0053b280`, `0x0053bf40`, `0x0053bf80`, `0x0053c070`, `0x0053c1d0`, `0x0053c390` | Begins movement, schedules/cancels timer callbacks through [UID:0000F1][TimerMgr](by-class/TimerMgr.md), syncs linked objects, refreshes linked objects, and steps forward. |
| Local movement and commands | `0x005a2de0-0x005a8e66` | Viewport position, movement send path, walk animation setup, spell/command slot use, action gate, warp, screen update, and movement packet send. |
| Local player settings and server packets | `0x005a9310-0x005ad440` | Movement buffer/history, settings packet, spell slot updates, server entry/login state, movement acks, chat/user-list/panel packets, linked-object packets, and action/attack packets. |

## Key Relationships

- [UID:00009R][ObjectPane](by-class/ObjectPane.md) is the base game-object pane below `LivingObjectPane`; keep generic object data/bounds/attachment logic there.
- [UID:00007Q][MapPane](by-class/MapPane.md) owns spatial lookup, map bounds, visible tile conversion, and object insertion/removal. `LivingObjectPane` calls those APIs while keeping actor-side position and prediction state.
- [UID:0000FQ][UserPane](by-class/UserPane.md) owns the local user UI surface. Its constructor/destructor wraps a `LivingObjectPane` subobject, but world movement and command packet functions stay with `LivingObjectPane`.
- [UID:0000CU][SelfLookPane](by-class/SelfLookPane.md), inventory panes, and spell input panes call into `LivingObjectPane` for current slot data or command execution.
- [UID:0000I5][Chatting](by-file/Chatting.md) and [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md) consume some packet outcomes, but chat pane/source ownership should not be inferred from `LivingObjectPane::HandleChatMessagePacket` alone.
- [UID:0000F0][TimerHandler](by-class/TimerHandler.md) / [UID:0000F1][TimerMgr](by-class/TimerMgr.md) provide the generic callback scheduler used by `LivingObjectPane` sprite, facing, movement, and animation state. Active generated `SoundManager::CancelTimer` names inside `class_LivingObjectPane.cpp` are stale labels for the generic timer-wrapper functions at `0x00597610` and `0x00597630`, not an audio-module dependency.

## Boundary Caveats

- IDA confirms the main function starts for the core and movement clusters, but several Wave3-projected helpers in the local-player tail are not IDA function starts yet: `0x005a3a20`, `0x005a9250`, `0x005aaff0`, `0x005ac1b0`, `0x005ac7e0`, and `0x005ac9a0`.
- `0x0053d030` is modeled by Wave3 as a separate `LivingObjectPane__BoxRotator` class. The vtable name and constructor state support treating it as `LivingObjectPane::BoxRotator`, likely nested or source-local.
- The emitted `class_LivingObjectPane.cpp` contains repeated local struct/class redeclarations. Those are generated-source artifacts and should not be used as original header-layout evidence.
- The emitted `class_LivingObjectPane.cpp` also contains timer calls under `SoundManager::*` names. IDA rechecks on 2026-05-24 show the underlying bodies forward through `g_pTimerMgr`, so source migration should name the dependency through `TimerHandler`/`TimerMgr` instead.
- The paired hotkey dispatch helper names are still source-name candidates. Current docs resolve [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md) state `2` / `.usr` `S` from the spell-inventory tab and state `3` / `.usr` `I` from the inventory tab; those records currently route through `0x005a4530` and [UID:0001KN][0x005a3e30-0x005a3ff3.UseInventorySlotDispatch](by-memory/0x005a3e30-0x005a3ff3.UseInventorySlotDispatch.md) respectively. The latter is now documented as `UseInventorySlotDispatch` because `UseInputPane` calls it for item-slot use and it can open `ItemWhoInputPane`.

## Cross-References

- [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md)
- [UID:00007C][LivingObjectPane__BoxRotator](by-class/LivingObjectPane__BoxRotator.md)
- [UID:000233][0x00514ea0-0x00514edd.LivingObjectPaneGmNameSuffixCheck](by-memory/0x00514ea0-0x00514edd.LivingObjectPaneGmNameSuffixCheck.md)
- [UID:00023H][0x00538bb0-0x00538bb7.LivingObjectPaneGetEntityId](by-memory/0x00538bb0-0x00538bb7.LivingObjectPaneGetEntityId.md)
- [UID:0001DE][0x0053a110-0x0053d818.LivingObjectPaneCore](by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md)
- [UID:0001KM][0x005a2de0-0x005ad440.LivingObjectPaneLocalPlayerExtensions](by-memory/0x005a2de0-0x005ad440.LivingObjectPaneLocalPlayerExtensions.md)
- [UID:0001KN][0x005a3e30-0x005a3ff3.UseInventorySlotDispatch](by-memory/0x005a3e30-0x005a3ff3.UseInventorySlotDispatch.md)
- [UID:00009R][ObjectPane](by-class/ObjectPane.md)
- [UID:00007Q][MapPane](by-class/MapPane.md)
- [UID:0000FQ][UserPane](by-class/UserPane.md)
- [UID:0001K9][0x00597610-0x00597645.TimerHandlerWrappers](by-memory/0x00597610-0x00597645.TimerHandlerWrappers.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `82/78`. Summary: the gameplay actor page has broad, detailed coverage of purpose, method families, dependencies, nested helper, timer misnames, and packet/movement caveats, but confidence is capped by unresolved local-player tail boundaries and source-level naming. Evidence: documented core/local-player memory ranges, accessor pages, `BoxRotator` nesting, `MapPane`/`UserPane`/`TimerMgr` relationships, and explicit Wave3 artifact exclusions.
