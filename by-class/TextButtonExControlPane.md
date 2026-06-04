*** UID:0000EK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# TextButtonExControlPane

## Status

- Confidence: strong for class role, function boundaries, vtable identity, text-provider ownership, attach/detach behavior, paint resources, and destructor thunks; medium for final private field names and source split with adjacent text-button controls.
- Likely source file: [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md), adjacent to [UID:0000OK][TextButtonControlPane](by-file/TextButtonControlPane.md)
- Core memory: [UID:000118][0x00494b50-0x00499e30.ButtonChoiceControlCore](by-memory/0x00494b50-0x00499e30.ButtonChoiceControlCore.md)
- Destructor/thunk memory: [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md)
- Evidence basis: live IDA MCP function listing, xrefs, vtable slots, disassembly, and decompilation on 2026-06-04.

## Class Purpose

`TextButtonExControlPane` is an extended text-labeled button. It owns or coordinates a text-provider pane, centers label bounds when state changes, shows/hides the label, attaches/detaches the sub-pane, and paints BUTTONEX-style graphics and optional text/icon overlays.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `TextButtonExControlPane` | `0x00495450-0x004955dc` | Constructs the generic `ButtonControlPane` base, installs `TextButtonExControlPane` vtables, centers the initial label rect, allocates a 372-byte text-provider child, attaches it, and shows it. |
| raw ordinary teardown | `0x004955e0-0x00495615` | No IDA function object, xrefs, or entrypoint pointer hits; restores vtables, releases the `+0x10c` text-provider child if present, and jumps to shared pane cleanup. |
| `SetState` | `0x00495620-0x0049574c` | Re-reads provider text, recomputes centered label bounds, applies the disabled-state offset for state `11`, updates the child rect, stores the state byte, and invalidates. |
| `GetText` | `0x00495750-0x004957b2` | Copies provider text into the caller buffer up to the requested count, writes a UTF-16 null terminator, and returns the copied count. |
| `ShowControl` | `0x004957c0-0x00495836` | Raises provider alpha/visibility to `134`, invalidates provider and owner bounds, and sets the visible flag. |
| `HideControl` | `0x00495840-0x004958b6` | Lowers provider alpha/visibility to `128`, invalidates provider and owner bounds, and clears the visible flag. |
| `OnAttachToParent` | `0x004958c0-0x0049591f` | Chains parent attach, queries child bounds through vtable slot `+0x28`, then attaches the text provider through child slot `+0x30`. |
| `OnDetachFromParent` | `0x00495920-0x00495936` | Detaches/removes the text provider through child slot `+0x38`, then chains base detach. |
| `OnPaint` | `0x00495940-0x00495a95` | Draws BUTTONEX resources, applies disabled-state offset for state `11`, and optionally overlays text/icon variants based on local flags. |
| adjustor thunks | `0x0049b071-0x0049b087` | Secondary and tertiary destructor thunks subtract `0xa0`/`0xa4` and forward to `0x0049b860`. |
| `ScalarDeletingDestructor` | `0x0049b860-0x0049b8c7` | Restores vtables, releases the `+0x10c` text-provider child, calls shared pane cleanup, and conditionally frees storage unless `flags & 4` is set. |

## Evidence Notes

- Live IDA reports core function boundaries at `0x00495450-0x004955dc`, `0x00495620-0x0049574c`, `0x00495750-0x004957b2`, `0x004957c0-0x00495836`, `0x00495840-0x004958b6`, `0x004958c0-0x0049591f`, `0x00495920-0x00495936`, and `0x00495940-0x00495a95`, plus destructor thunks `0x0049b071-0x0049b087` and scalar deleting destructor `0x0049b860-0x0049b8c7`.
- The constructor has a single direct caller at `0x00518d9c` inside `0x00517f30`; no fitting-room constructor caller was observed in this pass.
- Constructor setup calls [UID:00001E][ButtonControlPane](by-class/ButtonControlPane.md) construction at `0x0049548c`, writes temporary `ButtonControlPane` vtables at `0x0049549c/0x004954a2/0x004954ac`, then writes `TextButtonExControlPane` vtables at `0x004954dc/0x004954e2/0x004954ec`.
- The child text provider pointer lives at `this+0x10c`; constructor allocates `372` bytes via `0x004f4aa0`, constructs the provider through `0x00595390`, sets its rect through vtable slot `+0x2c`, calls `0x0058ea80`, and shows it through `0x005446b0`.
- Live IDA names the vtable views as `??_7TextButtonExControlPane@@6B@` at `0x00617d24`, `??_7TextButtonExControlPane@@6B@_0` at `0x00617d90`, and `??_7TextButtonExControlPane@@6B@_1` at `0x00617dc0`.
- Key slots are `0x00617d24 -> 0x0049b860`, `0x00617d54 -> 0x004958c0`, `0x00617d5c -> 0x00495920`, `0x00617d68 -> 0x00495940`, `0x00617d6c -> 0x00495620`, `0x00617d70 -> 0x004957c0`, `0x00617d74 -> 0x00495840`, `0x00617d88 -> 0x00495750`, `0x00617d90 -> 0x0049b071`, and `0x00617dc0 -> 0x0049b07c`.
- The raw ordinary teardown at `0x004955e0` has no IDA function object, no direct xrefs, and no entrypoint pointer hits. Its vtable writes match the constructor and scalar destructor, so it belongs with this class even though it remains an unmodeled body.
- `SetState` uses provider text helpers `0x0058e380`, text measurement `0x004baa70`, bounds helpers `0x004b8e00`, `0x004b7cc0`, and `0x004b7e10`, then updates the provider via child slot `+0x2c` and invalidates the owner through vtable slot `+0x20`.
- `ShowControl` and `HideControl` toggle the provider through `0x0058eb30` with values `134` and `128`, then invalidate the provider and owner bounds when the visible flag changes.
- `OnPaint` branches on `byte_66DA97`, loads resources through `dword_67A744`, `0x00457a60`, and `0x004d02f0`, uses resource names at `0x006186bc`, `0x006186d8`, `0x006186ec`, and `"NP"` at `0x0061484c`, and applies the state `11` one-pixel disabled offset before drawing.
- The scalar deleting destructor releases the `+0x10c` child through its virtual destructor, calls shared pane cleanup `0x00544580`, and only calls `0x004f4ac0` when scalar delete is requested and the no-delete flag bit is clear.

## Score Rationale

Completion and confidence are raised because live IDA now records exact function boundaries, the constructor caller, vtable identities/slots/writes, the `+0x10c` child lifecycle, raw ordinary teardown, state/text/show/hide/attach/detach/paint behavior, destructor thunks, and scalar destructor flag behavior. The score remains below final-source range because private field names, child-provider type naming, resource label names, and the final split between `ButtonControlPane.cpp` and adjacent text-button files still need source-quality review.

## Cross-References

- [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md)
- [UID:0000EJ][TextButtonControlPane](by-class/TextButtonControlPane.md)
- [UID:000118][0x00494b50-0x00499e30.ButtonChoiceControlCore](by-memory/0x00494b50-0x00499e30.ButtonChoiceControlCore.md)
- [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `82`, confidence `76`.
- Evidence: the page documents extended button role, constructor/state/text/show/hide/attach/paint/destructor ranges, text-provider child behavior, caller evidence, and unreliable owner-name pollution; confidence remains capped by destructor/helper owner names.
- 2026-06-04 live IDA pass:
  - Before: completion `82`, confidence `76`, reconstructable metadata blank.
  - Changed to: completion `86`, confidence `86`, `RECONSTRUCTABLE:TRUE`, and parent [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md).
  - Evidence: live IDA verified exact function boundaries, constructor caller, vtable slots/writes, text-provider child lifecycle, raw ordinary teardown at `0x004955e0`, state/text/show/hide/attach/detach/paint behavior, destructor thunks, and scalar destructor flag handling; remaining uncertainty is limited to private field names, resource labels, and final text-button source split.
